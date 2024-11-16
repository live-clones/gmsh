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

        unsigned nOverlapsInI = 0;
        unsigned nDomInI = 0;
for(auto e : entities) {
  std::set<MTriangle *> allElementsInOverlap; // Total set of elements in the
                                              // overlaps of this entity
  partitionFace *surface = dynamic_cast<partitionFace *>(e);
  if(!surface) continue; // Skip the "full" entities

  if(!surface || surface->geomType() == GEntity::OverlapSurface)
    continue; // Avoid overlaps of overlaps ?
  if(surface->getPartitions().size() != 1 || surface->getPartitions()[0] != i)
    continue;

  if (surface->getParentEntity() != parentFace) {
    continue;
  }

  ++nDomInI;

  //auto boundaryVertices = region->getBoundaryVertices();

  std::vector<int> tagsForPhysicals;

  for(auto e2 : entities) {
    partitionFace *otherSurface = dynamic_cast<partitionFace *>(e2);
    if(!otherSurface || otherSurface->geomType() == GEntity::OverlapSurface)
      continue;
    
    if(otherSurface->getPartitions().size() != 1 ||
       otherSurface->getPartitions()[0] == i)
      continue;

    if (surface->getParentEntity() != otherSurface->getParentEntity()) {
      continue;
    }

    /*int j = otherRegion->getPartitions()[0];
    if(touchingPartitions.find(j) == touchingPartitions.end())
      continue; // Skip non-touching partitions*/

    // Fill the overlap
    auto triangles = otherSurface->getNearbyTriangles(*surface, overlapSize);
    if(triangles.empty()) continue;
    overlapFace *overlap =
      new overlapFace(model, ++elementaryNumber, surface, otherSurface);
    overlap->setManager(this);
    this->overlapsByPartition[i].insert(overlap);
    model->add(overlap);
    ++nOverlapsCreated;
    tagsForPhysicals.push_back(overlap->tag());

    for(auto triangle : triangles) { overlap->addElement(triangle); }
    for(auto triangle : triangles) { allElementsInOverlap.insert(triangle); }
  }

  // Create Physical
  gmsh::model::addPhysicalGroup(2, tagsForPhysicals, -1,
                                "OverlapOfFace_" + std::to_string(tagParent) +
                                  "_part_" + std::to_string(i) + "_num_" +
                                  std::to_string(++nOverlapsInI));

  // TO UPDATE BELOW
  std::set<MVertex*> verticesI;
    for (auto t: surface->triangles) {
      for (int i = 0; i < 3; ++i) {
        verticesI.insert(t->getVertex(i));
      }
    }

  std::unordered_map<MEdge, int, MEdgeHash, MEdgeEqual> edgeCount;
    for(auto triangle : allElementsInOverlap) {
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

      // Create a full boundary for each overlap
      partitionEdge *fullBnd =
        new partitionEdge(model, ++elementaryNumberBnd, {i});

      std::vector<MLine *> bndElems;
      for(auto face : boundaryEdges) {
        bndElems.push_back(new MLine(face.getVertex(0), face.getVertex(1)));
      }
      fullBnd->lines = std::move(bndElems); // Take ownership
      model->add(fullBnd);
      Msg::Info("Created full boundary %d for i = %d", fullBnd->tag(), i);
      this->boundariesByPartition[i].insert(fullBnd);
      gmsh::model::addPhysicalGroup(
        1, {fullBnd->tag()}, -1,
        "OverlapBndOfFace_" + std::to_string(tagParent) + "_part_" +
          std::to_string(i) + "_num_" + std::to_string(nOverlapsInI));
    }

  Msg::Info("Created %d overlaps on %d entites for face %d", nOverlapsCreated, nDomInI, tagParent);



  }
}
