// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "overlapRegionManager.h"
#include "gmsh.h"
#include "MTriangle.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"

overlapRegionManager::overlapRegionManager(GModel *model, int tagParent,
                                           int overlapSize,
                                           bool createPhysicals)
  : model(model), tagParent(tagParent)
{
}

static std::vector<MTriangle *> fromFacePatchToElements(
  partitionFace *pf,
  const std::unordered_set<MFace, MFaceHash, MFaceEqual> &faceSet)
{
  std::vector<MTriangle *> elems;
  for(MTriangle *t : pf->triangles) {
    if(faceSet.find(t->getFace(0)) != faceSet.end()) { elems.push_back(t); }
  }
  return elems;
}

static std::unordered_set<MFace, MFaceHash, MFaceEqual>
boundaryOfRegion(GRegion *reg)
{
  auto facesOfThisEntity = reg->faces();
  std::unordered_set<MFace, MFaceHash, MFaceEqual> entityFaces;
  for(auto f : facesOfThisEntity) {
    for(auto t : f->triangles) { entityFaces.insert(t->getFace(0)); }
  }
  return entityFaces;
}

static std::set<int> computeTouchingPartitions(GRegion *reg)
{
  std::set<int> touchingPartitions;
  auto neighborFaces = reg->faces();
  for(GFace *f : neighborFaces) {
    partitionFace *pf = dynamic_cast<partitionFace *>(f);
    if(!pf) continue;
    for(int p : pf->getPartitions()) { touchingPartitions.insert(p); }
  }

  // Add partitions with a common partition vertex
  for(GVertex *v : reg->vertices()) {
    partitionVertex *pv = dynamic_cast<partitionVertex *>(v);
    if(!pv) continue;
    for(int p : pv->getPartitions()) { touchingPartitions.insert(p); }
  }
  return touchingPartitions;
}

static void fillFaceToEntities(
  std::unordered_map<MFace, partitionFace *, MFaceHash, MFaceEqual>
    &faceToEntities,
  const std::vector<GFace *> &outerFaces, GModel *model)
{
  std::vector<GEntity *> entities;
  model->getEntities(entities, 2);
  for(GEntity *e : entities) {
    partitionFace *pf = dynamic_cast<partitionFace *>(e);
    // For all PF that have the region boundary as parent, fill.
    if(!pf) continue;
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
  int numPartitions = model->getNumPartitions();
  std::vector<GEntity *> entities;
  model->getEntities(entities, 3);
  GRegion *parentRegion =
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
  std::unordered_map<MFace, partitionFace *, MFaceHash, MFaceEqual>
    faceToEntities;
  Msg::Info(
    "Volume has %d surfaces as boundary. These will get an overlap too.",
    parentRegion->faces().size());
  fillFaceToEntities(faceToEntities, parentRegion->faces(), model);
  Msg::Info("Face to PF map has %lu entries", faceToEntities.size());

  
  // JAN 25: optimized overlaps
  std::unordered_map<partitionRegion*, std::unordered_set<MFace, MFaceHash, MFaceEqual>> regionFaces;
  for (auto e: entities) {
    partitionRegion* region = dynamic_cast<partitionRegion*>(e);
    if (!region) continue;
    auto faces = boundaryOfRegion(region);
    regionFaces.insert({region, faces});
  }
  for (const auto& [pr, faces]: regionFaces) {
    Msg::Info("Region %d has %lu faces", pr->tag(), faces.size());
  }
  std::unordered_map<MVertex*, std::set<partitionRegion *>> skeletonVerticesOwner;
  for (const auto& [pr, faces]: regionFaces) {
    for (const auto& f: faces) {
      for (int i = 0; i < f.getNumVertices(); ++i) {
        skeletonVerticesOwner[f.getVertex(i)].insert(pr);
      }
    }
  }
  
  std::unordered_map<partitionRegion*, std::set<partitionRegion*>> regionToTouchingRegions;
for (const auto& [v, regions]: skeletonVerticesOwner) {
    if (regions.size() > 1) {
      //Msg::Info("Vertex %d is shared by %lu regions", v->getNum(), regions.size());
      for (auto r1: regions) {
        for (auto r2: regions) {
          if (r1 == r2) continue;
          regionToTouchingRegions[r1].insert(r2);
        }
      }
    }
  }

  for (const auto& [r, touching]: regionToTouchingRegions) {
    //Msg::Info("Region %d has %lu touching regions", r->tag(), touching.size());
  }

  std::unordered_map<int, std::set<overlapRegion *>> overlapsByPartition;

  for(unsigned i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i

    unsigned nOverlapsInI = 0;

    // Loop over all partitioned regions with only one partition that is i
    for(auto e : entities) {
      std::set<MTetrahedron *>
        allElementsInOverlap; // Total set of elements in the overlaps of this
                              // entity
      std::map<partitionFace *,
               std::unordered_set<MFace, MFaceHash, MFaceEqual>>
        faceToOverlaps;

      partitionRegion *region = dynamic_cast<partitionRegion *>(e);
      // Skip the "full" entities as well as overlap entities
      if(!region || region->geomType() == GEntity::OverlapVolume)
        continue; // Avoid overlaps of overlaps ?
      if(region->getPartitions().size() != 1 || region->getPartitions()[0] != i)
        continue;

      // Get all the valid "j"
      std::set<int> touchingPartitions = computeTouchingPartitions(region);
      Msg::Info("Region %d has %d touching partitions", region->tag(),
                touchingPartitions.size());

      // ALL MFACE ON MY BOUNDARY
      auto& entityFaces = regionFaces.at(region);
      std::vector<int> tagsForPhysicals;

      for(auto e2 : entities) {
        partitionRegion *otherRegion = dynamic_cast<partitionRegion *>(e2);
        // Check validity of the region
        if(!otherRegion || otherRegion->geomType() == GEntity::OverlapVolume)
          continue;
        if(e != e2 && otherRegion->getPartitions()[0] == i)
          Msg::Warning("Region %d has more than one partitions", i);
        if(otherRegion->getPartitions().size() != 1 ||
           otherRegion->getPartitions()[0] == i)
          continue;
        if(region->getParentEntity() != otherRegion->getParentEntity()) {
          continue;
        }

        int j = otherRegion->getPartitions()[0];
        if(touchingPartitions.find(j) == touchingPartitions.end())
          continue; // Skip non-touching partitions
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

      auto regionFaces = region->faces();
      std::unordered_set<MFace, MFaceHash, MFaceEqual> boundaryFaces;
      for(auto [face, count] : faceCount) {
        if(count != 1) continue;

        auto itEntity = faceToEntities.find(face);
        if(itEntity == faceToEntities.end()) {
          // Either an internal or artifical face, but not the physical boundary
          if(entityFaces.find(face) == entityFaces.end()) {
            boundaryFaces.insert(face);
          }
          // Else, neglect: internal face
          continue;
        }

        // This face belongs to the physical boundary of the region (and is on a
        // partitionFace neighbor of the region)
        GEntity *parentFace = (itEntity->second)->getParentEntity();
        int numFacesWithThisParent = std::count_if(
          regionFaces.begin(), regionFaces.end(), [parentFace](GEntity *f) {
            if(!f) return false;
            return f->getParentEntity() == parentFace;
          });
        if(numFacesWithThisParent > 1) {
          Msg::Warning("Boundary face has more than one parent face: %d on "
                       "partition %d. Overlap of boundary can be messy",
                       numFacesWithThisParent, i);
        }
        auto pf = std::find_if(regionFaces.begin(), regionFaces.end(),
                               [parentFace](GEntity *f) {
                                 return f->getParentEntity() == parentFace;
                               });
        // For now, we look for any PF on this entity and add the overlap there
        if(pf != regionFaces.end()) {
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

  // Create all the boundaries
  /*for (const auto& [pf, set]: faceToOverlaps) {
    std::vector<MTriangle*> bndElems;
    for (auto face: set) {
      if (face.getNumVertices() != 3) {
        Msg::Error("Boundary face is not a triangle");
        continue;
      }
      bndElems.push_back(new MTriangle(face.getVertex(0), face.getVertex(1),
                                       face.getVertex(2)));
    }
    partitionFace *fullBnd =
      new partitionFace(model, ++elementaryNumberBnd, {pf->getPartitions()[0]});
    fullBnd->triangles = std::move(bndElems); // Take ownership
    model->add(fullBnd);
    Msg::Info("Created full boundary %d for i = %d", fullBnd->tag(),
  pf->getPartitions()[0]);
    this->boundariesByPartition[pf->getPartitions()[0]].insert(fullBnd);
    gmsh::model::addPhysicalGroup(
      2, {fullBnd->tag()}, -1,
      "OverlapBndOfRegion_" + std::to_string(tagParent) + "_part_" +
        std::to_string(pf->getPartitions()[0]) + "_num_" + std::to_string(0));
  }*/
}

/*
void overlapRegionManager::findElementsForBoundaryOverlap(
  partitionFace *pf,
  const std::map<partitionFace *, std::unordered_set<MFace, MFaceHash>>
    &faceToOverlaps,
  std::map<partitionFace *, std::set<MTriangle *>> &faceToOverlapElements,
  GModel* model)
{
  std::vector<GEntity *> entities;
  model->getEntities(entities, 2);
  for(const auto &[pf, faceSet] : faceToOverlaps) {
    std::set<MTriangle *> elems;

    std::set<partitionFace *> others;
    auto& myEdges  = pf->edges();
    for(GEntity *e : entities) {
      partitionFace *other = dynamic_cast<partitionFace *>(e);
      if(!other) continue;
      if(other->getParentEntity() != pf->getParentEntity()) continue;
      if(other == pf) continue;
      const auto& otherEdges = other->edges();
      for (GEdge* edge: myEdges) {
        if (std::find(otherEdges.begin(), otherEdges.end(), edge) !=
otherEdges.end()) { others.insert(other); break;
        }
      }
    }

    for(partitionFace *other : others) {
      for(MTriangle *t : other->triangles) {
        if(faceSet.find(t->getFace(0)) != faceSet.end()) { elems.insert(t); }
      }
    }

    faceToOverlapElements[pf] = std::move(elems);
    Msg::Info("Found %lu elements for boundary overlap",
              faceToOverlapElements[pf].size());
  }
}
*/
