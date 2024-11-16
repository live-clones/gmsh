// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "overlapFaceManager.h"
#include "gmsh.h"
#include "MLine.h"
#include "partitionEdge.h"
#include <unordered_set>

overlapFaceManager::overlapFaceManager(GModel *model, int tagParent,
                                       int overlapSize, bool createPhysicals)
  : model(model), tagParent(tagParent)
{
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
    int elementaryNumberBnd =
    model->getMaxElementaryNumber(1); // Tags of new 1D entites
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
    std::set<MTriangle *> allTrianglesInOverlap;

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
      auto triangles = neighborFace->getNearbyTriangles(*thisFace, overlapSize);
      if(triangles.empty()) { continue; }
      overlapFace *overlapij =
        new overlapFace(model, ++elementaryNumber, thisFace, neighborFace);
      for(auto triangle : triangles) { overlapij->addElement(triangle); }
      // Fill the "overlap of i" set
      for (auto t: triangles) {allTrianglesInOverlap.insert(t);}

      overlapij->setManager(this);
      this->addOverlap(overlapij);
      model->add(overlapij);
      ++nOverlapsCreated;

      // Handle boundary
      auto boundary = _createBoundary(triangles);
      partitionEdge* bnd = new partitionEdge(model, ++elementaryNumberBnd, {i});
      bnd->lines = boundary; // Take ownership
      model->add(bnd);
      this->boundaries[i][j] = bnd;
    }
    std::set<MVertex*> verticesI;
    for (auto t: thisFace->triangles) {
      for (int i = 0; i < 3; ++i) {
        verticesI.insert(t->getVertex(i));
      }
    }

    /* Begin full boundary computation */
    std::unordered_map<MEdge, int, MEdgeHash, MEdgeEqual> edgeCount;
    for(auto triangle : allTrianglesInOverlap) {
      for(int k = 0; k < 3; ++k) edgeCount[triangle->getEdge(k)]++;
    }
    std::unordered_set<MEdge, MEdgeHash, MEdgeEqual> boundaryEdges;
    for(auto [edge, count] : edgeCount) {
      // Exterior boundary if edge appears once and one of its vertices is not in the covered surface (boundary)
      if(count != 1) continue;
      if(verticesI.count(edge.getVertex(0)) && verticesI.count(edge.getVertex(1))) continue;

      // One of the vertices must be inside the global surface (not on the boundary of domain i)
      for (int i = 0; i < 2; ++i) {
        if (verticesI.count(edge.getVertex(i))) continue;
        // Is it on the surface ?
        GEntity* onWhat = edge.getVertex(i)->onWhat();
        GEntity* parent = onWhat->getParentEntity();
        if (parent == nullptr)
          Msg::Error("Boundary of face overlap: Vertex %d has not parent", edge.getVertex(i)->getNum());
        if(parent->dim() == 2 && parent->tag() == tagParent) {
          boundaryEdges.insert(edge);
        }
      }
    }

    std::vector<MLine*> linesBnd;
    for (MEdge edge: boundaryEdges) {
      linesBnd.push_back(new MLine(edge.getVertex(0), edge.getVertex(1)));
    }
    /* End full boundary computation */
    partitionEdge* fullBnd = new partitionEdge(model, ++elementaryNumberBnd, {i});
    fullBnd->lines = std::move(linesBnd); // Take ownership
    model->add(fullBnd);
    this->fullBoundaries[i] = fullBnd;
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
      gmsh::model::addPhysicalGroup(2, overlapTags, -1,
                                    basis_name + std::to_string(i));
      gmsh::model::addPhysicalGroup(1, {fullBoundaries.at(i)->tag()}, -1,
                                    basis_name + std::to_string(i) + "_bnd");
                                    Msg::Info("Created physical group %s", (basis_name + std::to_string(i) + "_bnd").c_str()) ;
      ++nPhysicalsCreated;
    }
    Msg::Debug("Created %d physicals for entity 2 %d", nPhysicalsCreated,
              tagParent);
  }
}

std::vector<MLine *> overlapFaceManager::_createBoundary(
  const std::set<MTriangle *> &trianglesInOverlap) const
{
  std::vector<MLine*> result;
  std::unordered_map<MEdge, int, MEdgeHash, MEdgeEqual> edgeCount;
  for (auto triangle: trianglesInOverlap) {
    for (int k = 0; k < 3; ++k)
      edgeCount[triangle->getEdge(k)]++;
  }

  std::unordered_set<MEdge, MEdgeHash, MEdgeEqual> boundaryEdges;
  for (auto [edge, count]: edgeCount) {
    if (count != 1) continue;
    // This edge is on the boundary if one of its point is in the covered surface. TODO: add physical boundaries
    if (edge.getVertex(0)->onWhat()->dim() == 2 || edge.getVertex(1)->onWhat()->dim() == 2) {
      boundaryEdges.insert(edge);
    }
  }

  for (auto edge: boundaryEdges) {
    result.push_back(new MLine(edge.getVertex(0), edge.getVertex(1)));
  }

  return result;
}
