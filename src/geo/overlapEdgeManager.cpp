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
  int elementaryNumberBnd =
    model->getMaxElementaryNumber(0); // Tags of new 0D entites
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
    std::set<MLine *> allLinesInOverlap;

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
      for(auto line : lines) {
        allLinesInOverlap.insert(line);
      }

      overlapij->setManager(this);
      this->addOverlap(overlapij);
      model->add(overlapij);
      ++nOverlapsCreated;

    }
    std::set<MVertex*> verticesI;
    for (auto l: thisEdge->lines) {
      verticesI.insert(l->getVertex(0));
      verticesI.insert(l->getVertex(1));
    }

    /* Begin full boundary computation */
    std::map<MVertex*, int> vertexCount;
    for(auto line : allLinesInOverlap) {
      vertexCount[line->getVertex(0)]++;
      vertexCount[line->getVertex(1)]++;
    }
    std::set<MVertex*> boundaryVertices;
    for(auto [vertex, count] : vertexCount) {
      if(count == 1) {
        boundaryVertices.insert(vertex);
        // Further checks ?
      }
    }

    std::vector<MPoint*> bndElems;
    for(auto vertex : boundaryVertices) {
      bndElems.push_back(new MPoint(vertex));
    }
    /* End full boundary computation */
    partitionVertex*  fullBnd = new partitionVertex(model, ++elementaryNumberBnd, {static_cast<int>(i)});
    fullBnd->points = std::move(bndElems); // Take ownership
    model->add(fullBnd);
    this->fullBoundaries[i] = fullBnd;
    std::string physName = "fullBoundaryOfEdge" + std::to_string(tagParent) +
                           "_" + std::to_string(i);
  }
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

      gmsh::model::addPhysicalGroup(0, {fullBoundaries.at(i)->tag()}, -1,
                                    basis_name + std::to_string(i) + "_bnd");
      ++nPhysicalsCreated;
    }
    Msg::Debug("Created %d physicals for entity 1 %d", nPhysicalsCreated,
              tagParent);
  }
}

std::vector<MPoint *> overlapEdgeManager::_createBoundary(
  const std::set<MLine *> &overlapElements) const
{
  std::vector<MPoint *> result;
  std::unordered_map<MVertex *, int> pointCount;
  for(auto line : overlapElements) {
    pointCount[line->getVertex(0)]++;
    pointCount[line->getVertex(1)]++;
  }

  for(auto [vertex, count] : pointCount) {
    if(count == 1) {
      result.push_back(new MPoint(vertex));
    }
  }

  return result;
}
