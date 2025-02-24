// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "overlapRegionManager.h"
#include "gmsh.h"
#include "OS.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"

overlapRegionManager::overlapRegionManager(GModel *model, int tagParent,
                                           int overlapSize,
                                           bool createPhysicals)
  : model(model), tagParent(tagParent)
{
}


static std::unordered_set<MFace, MFaceHash, MFaceEqual>
boundaryOfRegion(GRegion *reg)
{
  auto facesOfThisEntity = reg->faces();
  std::unordered_set<MFace, MFaceHash, MFaceEqual> entityFaces;
  for(auto f : facesOfThisEntity) {
    for(auto t : f->triangles) { entityFaces.insert(t->getFace(0)); }
    for(auto q: f->quadrangles) { entityFaces.insert(q->getFace(0)); }
  }
  return entityFaces;
}


static std::unordered_map<MFace, partitionFace *, MFaceHash, MFaceEqual> fillBndFaceToEntities(const std::vector<GFace *> &outerFaces, const GModel *model)
{
  std::unordered_map<MFace, partitionFace *, MFaceHash, MFaceEqual> faceToEntities;
  std::vector<GEntity *> entities;
  model->getEntities(entities, 2);
  for(GEntity *e : entities) {
    partitionFace *pf = dynamic_cast<partitionFace *>(e);
    if(!pf) continue;
    // N.B. This would be equivalent to "pf->getParentEntity()->dim() == 2" when all faces are boundary of a unique volume.
    if(std::find(outerFaces.begin(), outerFaces.end(), pf->getParentEntity()) ==
       outerFaces.end())
      continue;

    for(size_t k = 0; k < pf->getNumMeshElements(); ++k) {
      auto elem = pf->getMeshElement(k);
      for(int i = 0; i < elem->getNumFaces(); ++i) {
        faceToEntities[elem->getFace(i)] = pf;
      }
    }
  }
  return faceToEntities;
}

/*
Thoughts about boundary overlaps

The boundary overlaps will be made of the outer part of overlap boundaries. When
building the volume overlap, each partitionFace will know which of its elements
are covered. Then we must decide whom they are overlap of. This can come from
BREP information of the volume whose overlap is computed. If each
partitionRegion has only one face with the correct tag, it is trivial.
Pathological cases are weird. But does it matter ?

Suggestion:
1) Build a MFace->partitionFace* dict
2) For all surfaces bounding the volume, When building overlap of
partitionRegion "r", check how many of its faces match the boundaries ? ASSUMING
A PARTITION REGION HAS PARTITIONFACE AS BOUNDARY ? 3) Attribute these faces
accordingly (as future part j of overlap i of ...) 4) Build a FaceOverlapManager
?

*/

void overlapRegionManager::create(int overlapSize, bool createPhysicals)
{
  const int numPartitions = model->getNumPartitions();
  double wt1, wt2;
  std::vector<GEntity *> entities;
  model->getEntities(entities, 3);
  const GRegion *parentRegion =
    dynamic_cast<GRegion *>(model->getEntityByTag(3, tagParent));
  if(!parentRegion) {
    Msg::Error("overlapRegionManager: Parent region %d not found", tagParent);
    return;
  }

  // For entities numbering
  int elementaryNumber =
    model->getMaxElementaryNumber(3); // Tags of new 3D entites
  int elementaryNumberBnd =
    model->getMaxElementaryNumber(2); // Tags of new 2D entites
  unsigned nOverlapsCreated = 0;

  // For building "boundaries of overlap", we keep track for all partitionFace
  // whose parent is a boundary of this region, of their faces
  Msg::Info(
    "Volume has %d surfaces as boundary. These will get an overlap too.",
    parentRegion->faces().size());
  wt1 = TimeOfDay();
  auto faceToEntities = fillBndFaceToEntities(parentRegion->faces(), model);
  wt2 = TimeOfDay();
  Msg::Info("Wall time to compute boundary mesh face to partition face entity dict: %fs.", wt2 - wt1);

  std::unordered_map<partitionRegion*, std::unordered_set<MFace, MFaceHash, MFaceEqual>> regionFaces;
  for (auto e: entities) {
    partitionRegion* region = dynamic_cast<partitionRegion*>(e);
    if (!region || region->getParentEntity() != parentRegion) continue;
    auto faces = boundaryOfRegion(region);
    regionFaces.insert({region, std::move(faces)});
  }

  std::unordered_map<MVertex *, std::set<partitionRegion *>>
    skeletonVerticesOwner;
  for(const auto &[pr, faces] : regionFaces) {
    for(const auto &f : faces) {
      for(size_t i = 0; i < f.getNumVertices(); ++i) {
        skeletonVerticesOwner[f.getVertex(i)].insert(pr);
      }
    }
  }

  std::unordered_map<partitionRegion *, std::set<partitionRegion *>>
    regionToTouchingRegions;
  wt1 = TimeOfDay();
  for(const auto &[v, regions] : skeletonVerticesOwner) {
    if(regions.size() > 1) {
      for(auto r1 : regions) {
        for(auto r2 : regions) {
          if(r1 == r2) continue;
          regionToTouchingRegions[r1].insert(r2);
        }
      }
    }
  }
  wt2 = TimeOfDay();
  Msg::Info("Wall time to compute touching regions: %fs.", wt2 - wt1);

  

  std::unordered_map<int, std::set<overlapRegion *>> overlapsByPartition;

  for(int i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i
    unsigned nOverlapsInI = 0;

    // Loop over all partitioned regions with only one partition that is i
    for(auto e : entities) {
      // Todo: extend to other elements
      std::set<MTetrahedron *>
        allElementsInOverlap;
      std::map<partitionFace *,
               std::unordered_set<MFace, MFaceHash, MFaceEqual>>
        faceToOverlaps;

      partitionRegion *region = dynamic_cast<partitionRegion *>(e);
      // Skip the "full" entities as well as overlap entities
      if(!region || region->geomType() == GEntity::OverlapVolume)
        continue; // Avoid overlaps of overlaps ?
      if(region->getPartitions().size() != 1 || region->getPartitions()[0] != i)
        continue;

      std::vector<int> tagsForPhysicals;
      auto isRegionValid = [&](partitionRegion *r) {
        if(!r) return false;
        if(r->geomType() == GEntity::OverlapVolume) return false;
        if(r->getPartitions().size() != 1 || r->getPartitions()[0] != i)
          return false;
        if(r->getParentEntity() != region->getParentEntity()) return false;
        if(regionToTouchingRegions[region].find(r) ==
           regionToTouchingRegions[region].end())
          return false;
        return true;
      };

      for(auto e2 : entities) {
        partitionRegion *otherRegion = dynamic_cast<partitionRegion *>(e2);
        // Check validity of the region
        if(e != e2 && otherRegion->getPartitions()[0] == i)
          Msg::Warning("Partition %d has more than one region. (This shouldn't be a problem.)", i);
        
        if(!isRegionValid(otherRegion)) continue;

        if(regionToTouchingRegions[region].find(otherRegion) ==
           regionToTouchingRegions[region].end())
          continue; // Skip non-touching regions

        // Fill the overlap
        auto tetras = otherRegion->getNearbyTetra(
          *region, region->getBoundaryVertices(), overlapSize);
        if(tetras.empty()) continue;
        overlapRegion *overlap =
          new overlapRegion(model, ++elementaryNumber, region, otherRegion);
        overlap->setManager(this);
        this->overlapsByPartition[i].insert(overlap);
        model->add(overlap);
        ++nOverlapsCreated;
        tagsForPhysicals.push_back(overlap->tag());

        for(auto tetra : tetras) { overlap->addElement(tetra); }
        for(auto tetra : tetras) { allElementsInOverlap.insert(tetra); }
      }

      // Create Physical
      gmsh::model::addPhysicalGroup(
        3, tagsForPhysicals, -1,
        "OverlapOfRegion_" + std::to_string(tagParent) + "_part_" +
          std::to_string(i) + "_num_" + std::to_string(++nOverlapsInI));

      // Find all faces at the boundary of the overlap of e.
      std::unordered_map<MFace, int, MFaceHash, MFaceEqual> faceCount;
      for(auto tetra : allElementsInOverlap) {
        for(int k = 0; k < tetra->getNumFaces(); ++k)
          faceCount[tetra->getFace(k)]++;
      }

      auto facesOfThisRegion = region->faces();
      std::unordered_set<MFace, MFaceHash, MFaceEqual> boundaryFaces;
      auto& entityMFaces = regionFaces.at(region);

      for(auto [face, count] : faceCount) {
        if(count != 1) continue;

        auto itEntity = faceToEntities.find(face);
        if(itEntity == faceToEntities.end()) {
          // Either an internal or artifical face, but not the physical boundary
          if(entityMFaces.find(face) == entityMFaces.end()) {
            boundaryFaces.insert(face);
          }
          // Else, neglect: internal face
          continue;
        }

        // This face belongs to the physical boundary of the region (and is on a
        // partitionFace neighbor of the region)
        GEntity *parentFace = (itEntity->second)->getParentEntity();
        int numFacesWithThisParent = std::count_if(
          facesOfThisRegion.begin(), facesOfThisRegion.end(), [parentFace](GEntity *f) {
            if(!f) return false;
            return f->getParentEntity() == parentFace;
          });
        if(numFacesWithThisParent > 1) {
          Msg::Warning("Boundary face has more than one parent face: %d on "
                       "partition %d. Overlap of boundary can be messy",
                       numFacesWithThisParent, i);
        }
        auto pf = std::find_if(facesOfThisRegion.begin(), facesOfThisRegion.end(),
                               [parentFace](GEntity *f) {
                                 return f->getParentEntity() == parentFace;
                               });
        // For now, we look for any PF on this entity and add the overlap there
        if(pf != facesOfThisRegion.end()) {
          partitionFace *faceWithOverlap = dynamic_cast<partitionFace *>(*pf);
          if(!faceWithOverlap) {
            Msg::Error("Boundary face is not a partitionFace");
          }
          faceToOverlaps[faceWithOverlap].insert(face);
        }
        else {
          // What does this represetn ? FIXME
          // Msg::Error("Parent face not found");
        }
      }

      // Create an artificial boundary of all the overlaps of this entity, with
      // new elements.
      partitionFace *fullBnd =
        new partitionFace(model, ++elementaryNumberBnd, {static_cast<int>(i)});
      fullBnd->setParentEntity(region->getParentEntity());

      std::vector<MTriangle *> bndElems;
      for(auto face : boundaryFaces) {
        if(face.getNumVertices() != 3) {
          Msg::Error("Boundary face is not a triangle");
          continue;
        }
        bndElems.push_back(new MTriangle(face.getVertex(0), face.getVertex(1),
                                         face.getVertex(2)));
      }
      fullBnd->triangles = std::move(bndElems); // Take ownership
      model->add(fullBnd);
      Msg::Info("Created full boundary %d for i = %d", fullBnd->tag(), i);
      this->boundariesByPartition[i].insert(fullBnd);
      gmsh::model::addPhysicalGroup(
        2, {fullBnd->tag()}, -1,
        "OverlapBndOfRegion_" + std::to_string(tagParent) + "_part_" +
          std::to_string(i) + "_num_" + std::to_string(nOverlapsInI));

      /*std::map<partitionFace *, std::set<MTriangle *>> faceToOverlapElements;
      findElementsForBoundaryOverlap(fullBnd, faceToOverlaps,
                                     faceToOverlapElements,
                                     model);*/

      // Now create overlap of physical boundaries

      for(const auto &[pf, set] : faceToOverlaps) {
        Msg::Info("PF %d has %lu faces", pf->tag(), set.size());
        std::vector<MTriangle *> elems;
        for(auto face : set) {
          if(face.getNumVertices() != 3) {
            Msg::Error("Boundary face is not a triangle");
            continue;
          }
          elems.push_back(new MTriangle(face.getVertex(0), face.getVertex(1),
                                        face.getVertex(2)));
        }
        partitionFace *bnd =
          new partitionFace(model, ++elementaryNumberBnd, {static_cast<int>(i)});
        Msg::Info("Created overlap of boundary %d with %d elements", bnd->tag(),
                  elems.size());
        auto parentFace = pf->getParentEntity();
        if(!parentFace) {
          Msg::Error("Parent face not found");
          continue;
        }
        bnd->setParentEntity(parentFace);
        bnd->triangles = std::move(elems); // Take ownership
        model->add(bnd);
        this->boundariesByPartition[i].insert(bnd);

        gmsh::model::addPhysicalGroup(
          2, {bnd->tag()}, -1,
          "OverlapOfBnd_" + std::to_string(tagParent) + "_part_" +
            std::to_string(i) + "_pf_" + std::to_string(pf->tag()));
      }
    }
  }

}
