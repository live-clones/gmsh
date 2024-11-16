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
#include <unordered_set>

overlapRegionManager::overlapRegionManager(GModel *model, int tagParent,
                                           int overlapSize,
                                           bool createPhysicals)
  : model(model), tagParent(tagParent)
{
}

void overlapRegionManager::create(int overlapSize, bool createPhysicals)
{
  int numPartitions = model->getNumPartitions();
  std::vector<GEntity *> entities;
  model->getEntities(entities, 3);
  GEntity *ge = model->getEntityByTag(3, tagParent);
  GRegion *parentRegion = dynamic_cast<GRegion *>(ge);
  if(!parentRegion) {
    Msg::Error("overlapRegionManager: Parent region %d not found", tagParent);
    return;
  }

  int elementaryNumber =
    model->getMaxElementaryNumber(3); // Tags of new 3D entites
  int elementaryNumberBnd =
    model->getMaxElementaryNumber(2); // Tags of new 2D entites
  unsigned nOverlapsCreated = 0;

  for(unsigned i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i

    unsigned nOverlapsInI = 0;

    // Loop over all partitioned regions with only one partition that is i
    for(auto e : entities) {
      std::set<MTetrahedron *>
        allElementsInOverlap; // Total set of elements in the overlaps of this
                              // entity
      partitionRegion *region = dynamic_cast<partitionRegion *>(e);
      if(!region) continue; // Skip the "full" entities

      if(!region || region->geomType() == GEntity::OverlapVolume)
        continue; // Avoid overlaps of overlaps ?
      if(region->getPartitions().size() != 1 || region->getPartitions()[0] != i)
        continue;

      // Get all the valid "j"
      std::set<int> touchingPartitions;
      {
        auto neighborFaces = region->faces();
        for(GFace *f : neighborFaces) {
          partitionFace *pf = dynamic_cast<partitionFace *>(f);
          if(!pf) continue;
          for(int p : pf->getPartitions()) {
            if(p != i) touchingPartitions.insert(p);
          }
        }
      }
      Msg::Info("Region %d has %d touching partitions", region->tag(), touchingPartitions.size());
      
      
      auto boundaryVertices = region->getBoundaryVertices();

      std::vector<int> tagsForPhysicals;

      for(auto e2 : entities) {
        partitionRegion *otherRegion = dynamic_cast<partitionRegion *>(e2);
        if(!otherRegion || otherRegion->geomType() == GEntity::OverlapVolume)
          continue;
        if(e != e2 && otherRegion->getPartitions()[0] == i)
          Msg::Warning("Region %d has more than one partitions", i);
        if(otherRegion->getPartitions().size() != 1 ||
           otherRegion->getPartitions()[0] == i)
          continue;

        int j = otherRegion->getPartitions()[0];
        if (touchingPartitions.find(j) == touchingPartitions.end()) continue; // Skip non-touching partitions

        // Fill the overlap
        auto tetras =
          otherRegion->getNearbyTetra(*region, boundaryVertices, overlapSize);
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
      std::unordered_set<MFace, MFaceHash, MFaceEqual> boundaryFaces;
      for(auto [face, count] : faceCount) {
        if(count != 1) continue;
        // Add if at least one point is not shared with the domain and has the
        // volume as parent

        for(int k = 0; k < face.getNumVertices(); ++k) {
          MVertex *v = face.getVertex(k);
          GEntity *parent = v->onWhat();
          if(parent->getParentEntity() != parentRegion) { continue; }
          if(std::find(boundaryVertices.begin(), boundaryVertices.end(), v) !=
             boundaryVertices.end()) {
            continue;
          }
          boundaryFaces.insert(face);
          break;
        }
      }

      // Create a full boundary for each overlap
      partitionFace *fullBnd =
        new partitionFace(model, ++elementaryNumberBnd, {i});

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
    }
  }
}
