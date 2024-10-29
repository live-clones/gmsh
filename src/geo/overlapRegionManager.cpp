// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "overlapRegionManager.h"
#include "gmsh.h"
#include "MTriangle.h"
#include "partitionFace.h"
#include <unordered_set>

overlapRegionManager::overlapRegionManager(GModel *model, int tagParent,
                                       int overlapSize, bool createPhysicals)
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
    model->getMaxElementaryNumber(3); // Tags of new 2D entites
    int elementaryNumberBnd =
    model->getMaxElementaryNumber(2); // Tags of new 1D entites
  unsigned nOverlapsCreated = 0;

  for(unsigned i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i
    auto it = std::find_if(
      entities.begin(), entities.end(), [i, parentRegion](GEntity *e) {
        if(e->getParentEntity() != parentRegion) return false;
        partitionRegion *gf = dynamic_cast<partitionRegion *>(e);
        if(!gf) return false;
        return gf->getPartitions().size() == 1 && gf->getPartitions()[0] == i;
      });

    if(it == entities.end()) {
      // It is not necassary for all partitions to have an entity, just skip
      continue;
    }
    partitionRegion *thisRegion = dynamic_cast<partitionRegion *>(*it);

    for(unsigned j = 1; j <= numPartitions; ++j) {
      if(i == j) continue;
      auto it = std::find_if(
        entities.begin(), entities.end(), [j, parentRegion](GEntity *e) {
          if(e->getParentEntity() != parentRegion) return false;
          partitionRegion *gf = dynamic_cast<partitionRegion *>(e);
          if(!gf) return false;
          return gf->getPartitions().size() == 1 && gf->getPartitions()[0] == j;
        });

      if(it == entities.end()) {
        continue;
      }
      partitionRegion *neighborRegion = dynamic_cast<partitionRegion *>(*it);
      if(!neighborRegion) {
        Msg::Error("Neighbor region is not a partitionRegion");
        continue;
      }
      auto tetras = neighborRegion->getNearbyTetra(*thisRegion, 1);
      if(tetras.empty()) { continue; }
      overlapRegion *overlapij =
        new overlapRegion(model, ++elementaryNumber, thisRegion, neighborRegion);
      for(auto tetra : tetras) { overlapij->addElement(tetra); }

      overlapij->setManager(this);
      this->addOverlap(overlapij);
      model->add(overlapij);
      ++nOverlapsCreated;

      // Handle boundary
      auto boundary = _createBoundary(tetras);
      partitionFace* bnd = new partitionFace(model, ++elementaryNumberBnd, {i});
      bnd->triangles = boundary; // Take ownership
      model->add(bnd);
      this->boundaries[i][j] = bnd;
    }
  }
  unsigned nPhysicalsCreated = 0;
  if(createPhysicals) {
    std::string basis_name = "overlapOfFace" + std::to_string(tagParent) + "_";
    for(unsigned i = 1; i <= numPartitions; ++i) {
      const auto overlaps = this->getOverlapsOf(i);
      if(!overlaps) {
        continue;
      }
      std::vector<int> overlapTags;
      for(auto [j, overlap] : *overlaps) {
        overlapTags.push_back(overlap->tag());
      }
      std::vector<int> bndTags;
      if (boundaries.find(i) != boundaries.end()) {
        for(auto [j, bnd] : boundaries[i]) {
          bndTags.push_back(bnd->tag());
        }
      }
      gmsh::model::addPhysicalGroup(3, overlapTags, -1,
                                    basis_name + std::to_string(i));
      gmsh::model::addPhysicalGroup(2, bndTags, -1,
                                    basis_name + std::to_string(i) + "_bnd");
                                    Msg::Info("Created physical group %s", (basis_name + std::to_string(i) + "_bnd").c_str()) ;
      ++nPhysicalsCreated;
    }
    Msg::Debug("Created %d physicals for entity 3 %d", nPhysicalsCreated,
              tagParent);
  }
}

std::vector<MTriangle *> overlapRegionManager::_createBoundary(
  const std::set<MTetrahedron *> &tetrasInOverlap) const
{
  std::vector<MTriangle*> result;
  std::unordered_map<MFace, int, MFaceHash, MFaceEqual> faceCount;
  for (auto tetra: tetrasInOverlap) {
    for (int k = 0; k < tetra->getNumFaces(); ++k)
      faceCount[tetra->getFace(k)]++;
  }

  std::unordered_set<MFace, MFaceHash, MFaceEqual> boundaryFaces;
  for (auto [face, count]: faceCount) {
    if (count != 1) continue;
    bool isBoundary = false;
    // If any of the vertices lies on the inner region, it is a boundary face
    for (int k = 0; k < face.getNumVertices(); ++k) {
      if (face.getVertex(k)->onWhat()->dim() == 3) {
        isBoundary = true;
        break;
      }
    }
    if (isBoundary) {
      boundaryFaces.insert(face);
    }
  }

  for (auto face: boundaryFaces) {
    if (face.getNumVertices() != 3) {
      Msg::Error("Boundary face is not a triangle");
      continue;
    }
    result.push_back(new MTriangle(face.getVertex(0), face.getVertex(1), face.getVertex(2)));
  }

  return result;
}
