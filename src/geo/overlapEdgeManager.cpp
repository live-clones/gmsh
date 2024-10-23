// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "overlapEdgeManager.h"
#include "gmsh.h"

overlapEdgeManager::overlapEdgeManager(GModel *model, int tagParent,
                                       int overlapSize, bool createPhysicals)
  : model(model), tagParent(tagParent)
{
  create(overlapSize, createPhysicals);
}

void overlapEdgeManager::create(int overlapSize, bool createPhysicals)
{
  int numPartitions = model->getNumPartitions();
  std::vector<GEntity *> entities;
  model->getEntities(entities, 1);
  GEntity *ge = model->getEntityByTag(1, tagParent);
  GEdge *parentEdge = dynamic_cast<GEdge *>(ge);
  if(!parentEdge) {
    Msg::Error("overlapEdgeManager: Parent edge %d not found", tagParent);
    return;
  }

  int elementaryNumber =
    model->getMaxElementaryNumber(1); // Tags of new 1D entites
  unsigned nOverlapsCreated = 0;

  for(unsigned i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i
    auto it = std::find_if(
      entities.begin(), entities.end(), [i, parentEdge](GEntity *e) {
        if(e->getParentEntity() != parentEdge) return false;
        partitionEdge *gf = dynamic_cast<partitionEdge *>(e);
        if(!gf) return false;
        return gf->getPartitions().size() == 1 && gf->getPartitions()[0] == i;
      });

    if(it == entities.end()) {
      // It is not necassary for all partitions to have an entity, just skip
      continue;
    }
    partitionEdge *thisEdge = dynamic_cast<partitionEdge *>(*it);

    for(unsigned j = 1; j <= numPartitions; ++j) {
      if(i == j) continue;
      auto it = std::find_if(
        entities.begin(), entities.end(), [j, parentEdge](GEntity *e) {
          if(e->getParentEntity() != parentEdge) return false;
          partitionEdge *gf = dynamic_cast<partitionEdge *>(e);
          if(!gf) return false;
          return gf->getPartitions().size() == 1 && gf->getPartitions()[0] == j;
        });

      if(it == entities.end()) {
        continue;
      }
      partitionEdge *neighborEdge = dynamic_cast<partitionEdge *>(*it);
      if(!neighborEdge) {
        Msg::Error("Neighbor edge is not a partitionEdge");
        continue;
      }
      auto lines = neighborEdge->getNearbyEdges(*thisEdge, 1);
      if(lines.empty()) { continue; }
      overlapEdge *overlapij =
        new overlapEdge(model, ++elementaryNumber, thisEdge, neighborEdge);
      for(auto line : lines) { overlapij->addElement(line); }

      overlapij->setManager(this);
      this->addOverlap(overlapij);
      model->add(overlapij);
      ++nOverlapsCreated;
    }
  }
  Msg::Info("Created %d overlaps for entity 1 %d", nOverlapsCreated, tagParent);
  unsigned nPhysicalsCreated = 0;
  if(createPhysicals) {
    std::string basis_name = "overlapOfEdge" + std::to_string(tagParent) + "_";
    for(unsigned i = 1; i <= numPartitions; ++i) {
      const auto *overlaps = this->getOverlapsOf(i);
      if(!overlaps) {
        continue;
      }
      std::vector<int> overlapTags;
      for(auto [j, overlap] : *overlaps) {
        overlapTags.push_back(overlap->tag());
      }
      gmsh::model::addPhysicalGroup(1, overlapTags, -1,
                                    basis_name + std::to_string(i));
      ++nPhysicalsCreated;
    }
    Msg::Debug("Created %d physicals for entity 1 %d", nPhysicalsCreated,
              tagParent);
  }
}
