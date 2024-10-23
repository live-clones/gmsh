// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "overlapFaceManager.h"
#include "gmsh.h"

overlapFaceManager::overlapFaceManager(GModel *model, int tagParent,
                                       int overlapSize, bool createPhysicals)
  : model(model), tagParent(tagParent)
{
  create(overlapSize, createPhysicals);
}

void overlapFaceManager::create(int overlapSize, bool createPhysicals)
{
  int numPartitions = model->getNumPartitions();
  std::vector<GEntity *> entities;
  model->getEntities(entities, 2);
  GEntity *ge = model->getEntityByTag(2, tagParent);
  GFace *parentFace = dynamic_cast<GFace *>(ge);
  if(!parentFace) {
    Msg::Error("overlapFaceManager: Parent face %d not found", tagParent);
    return;
  }

  int elementaryNumber =
    model->getMaxElementaryNumber(2); // Tags of new 2D entites
  unsigned nOverlapsCreated = 0;

  for(unsigned i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i
    auto it = std::find_if(
      entities.begin(), entities.end(), [i, parentFace](GEntity *e) {
        if(e->getParentEntity() != parentFace) return false;
        partitionFace *gf = dynamic_cast<partitionFace *>(e);
        if(!gf) return false;
        return gf->getPartitions().size() == 1 && gf->getPartitions()[0] == i;
      });

    if(it == entities.end()) {
      // It is not necassary for all partitions to have an entity, just skip
      continue;
    }
    partitionFace *thisFace = dynamic_cast<partitionFace *>(*it);

    for(unsigned j = 1; j <= numPartitions; ++j) {
      if(i == j) continue;
      auto it = std::find_if(
        entities.begin(), entities.end(), [j, parentFace](GEntity *e) {
          if(e->getParentEntity() != parentFace) return false;
          partitionFace *gf = dynamic_cast<partitionFace *>(e);
          if(!gf) return false;
          return gf->getPartitions().size() == 1 && gf->getPartitions()[0] == j;
        });

      if(it == entities.end()) {
        continue;
      }
      partitionFace *neighborFace = dynamic_cast<partitionFace *>(*it);
      if(!neighborFace) {
        Msg::Error("Neighbor face is not a partitionFace");
        continue;
      }
      auto triangles = neighborFace->getNearbyTriangles(*thisFace, 1);
      if(triangles.empty()) { continue; }
      overlapFace *overlapij =
        new overlapFace(model, ++elementaryNumber, thisFace, neighborFace);
      for(auto triangle : triangles) { overlapij->addElement(triangle); }

      overlapij->setManager(this);
      this->addOverlap(overlapij);
      model->add(overlapij);
      ++nOverlapsCreated;
    }
  }
  Msg::Info("Created %d overlaps for entity 2 %d", nOverlapsCreated, tagParent);
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
      gmsh::model::addPhysicalGroup(2, overlapTags, -1,
                                    basis_name + std::to_string(i));
      ++nPhysicalsCreated;
    }
    Msg::Debug("Created %d physicals for entity 2 %d", nPhysicalsCreated,
              tagParent);
  }
}
