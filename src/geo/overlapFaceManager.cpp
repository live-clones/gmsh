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

static std::unordered_set<MEdge, MEdgeHash, MEdgeEqual>
boundaryOfFace(GFace *surface)
{
  auto facesOfThisEntity = surface->edges();
  std::unordered_set<MEdge, MEdgeHash, MEdgeEqual> entityEdges;
  for(auto f : facesOfThisEntity) {
    for(auto l : f->lines) { entityEdges.insert(l->getEdge(0)); }
  }
  return entityEdges;
}

static void fillEdgeToEntities(
  std::unordered_map<MEdge, partitionEdge *, MEdgeHash, MEdgeEqual>
    &edgeToEntities,
  const std::vector<GEdge *> &outerEdges, GModel *model)
{
  std::vector<GEntity *> entities;
  model->getEntities(entities, 1);
  for(GEntity *e : entities) {
    partitionEdge *pe = dynamic_cast<partitionEdge *>(e);
    // For all PE that have the face boundary as parent, fill.
    if(!pe) continue;
    if(std::find(outerEdges.begin(), outerEdges.end(), pe->getParentEntity()) ==
       outerEdges.end())
      continue;

    for(size_t k = 0; k < pe->getNumMeshElements(); ++k) {
      auto elem = pe->getMeshElement(k);
      for(int i = 0; i < elem->getNumEdges(); ++i) {
        edgeToEntities[elem->getEdge(i)] = pe;
      }
    }
  }
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

  // For building "boundaries of overlap", we keep track for all partitionEdge
  // whose parent is a boundary of this region, of their faces
  std::unordered_map<MEdge, partitionEdge *, MEdgeHash, MEdgeEqual>
    edgeToEntities;
  Msg::Info("Face has %d edges as boundary. These will get an overlap too.",
            parentFace->faces().size());
  fillEdgeToEntities(edgeToEntities, parentFace->edges(), model);
  Msg::Info("Face to PF map has %lu entries", edgeToEntities.size());

  for(unsigned i = 1; i <= numPartitions; ++i) {
    // Generate overlaps of partition i

    unsigned nOverlapsInI = 0;
    unsigned nDomInI = 0;
    for(auto e : entities) {
      std::set<MTriangle *> allElementsInOverlap; // Total set of elements in
                                                  // the overlaps of this entity

      std::map<partitionEdge*, std::unordered_set<MEdge, MEdgeHash, MEdgeEqual>>
        edgeToOverlaps;

      partitionFace *surface = dynamic_cast<partitionFace *>(e);
      if(!surface) continue; // Skip the "full" entities

      if(!surface || surface->geomType() == GEntity::OverlapSurface)
        continue; // Avoid overlaps of overlaps ?
      if(surface->getPartitions().size() != 1 ||
         surface->getPartitions()[0] != i)
        continue;

      if(surface->getParentEntity() != parentFace) { continue; }

      // TODO: get valid "j"

      ++nDomInI;

      auto entityEdges = boundaryOfFace(surface);
      std::vector<int> tagsForPhysicals;

      for(auto e2 : entities) {
        partitionFace *otherSurface = dynamic_cast<partitionFace *>(e2);
        if(!otherSurface || otherSurface->geomType() == GEntity::OverlapSurface)
          continue;

        if(otherSurface->getPartitions().size() != 1 ||
           otherSurface->getPartitions()[0] == i)
          continue;

        if(surface->getParentEntity() != otherSurface->getParentEntity()) {
          continue;
        }

        /*int j = otherRegion->getPartitions()[0];
        if(touchingPartitions.find(j) == touchingPartitions.end())
          continue; // Skip non-touching partitions*/

        // Fill the overlap
        auto triangles =
          otherSurface->getNearbyTriangles(*surface, overlapSize);
        if(triangles.empty()) continue;
        overlapFace *overlap =
          new overlapFace(model, ++elementaryNumber, surface, otherSurface);
        overlap->setManager(this);
        this->overlapsByPartition[i].insert(overlap);
        model->add(overlap);
        ++nOverlapsCreated;
        tagsForPhysicals.push_back(overlap->tag());

        for(auto triangle : triangles) { overlap->addElement(triangle); }
        for(auto triangle : triangles) {
          allElementsInOverlap.insert(triangle);
        }
      }

      // Create Physical
      gmsh::model::addPhysicalGroup(
        2, tagsForPhysicals, -1,
        "OverlapOfFace_" + std::to_string(tagParent) + "_part_" +
          std::to_string(i) + "_num_" + std::to_string(++nOverlapsInI));

      // Find all the edges that are on the boundary of the overlap
      std::unordered_map<MEdge, int, MEdgeHash, MEdgeEqual> edgeCount;
      for(auto triangle : allElementsInOverlap) {
        for(int k = 0; k < 3; ++k) edgeCount[triangle->getEdge(k)]++;
      }

      auto surfaceEdges = surface->edges();
      std::unordered_set<MEdge, MEdgeHash, MEdgeEqual> boundaryEdges;
      for (auto [edge, count]: edgeCount) {
        if (count != 1) continue;

        auto itEntity = edgeToEntities.find(edge);
        if (itEntity == edgeToEntities.end()) {
          // Either an internal or artificial edge, but not the physical boundary
          if (entityEdges.find(edge) == entityEdges.end()) {
            boundaryEdges.insert(edge);
          }

          continue;
        }

        // This edge belongs to the physical boundary of the face (and is on a
        // partitionEdge neighbor of the face)
        GEntity* parentEdge = (itEntity->second)->getParentEntity();
        int numEdgesWithThisParent = std::count_if(
          surfaceEdges.begin(), surfaceEdges.end(), [parentEdge](GEntity *f) {
            if(!f) return false;
            return f->getParentEntity() == parentEdge;
          });
        if(numEdgesWithThisParent > 1) {
          Msg::Warning("Boundary face has more than one parent face: %d on "
                       "partition %d. Overlap of boundary can be messy",
                       numEdgesWithThisParent, i);
        }

        auto pe = std::find_if(surfaceEdges.begin(), surfaceEdges.end(),
                               [parentEdge](GEntity *f) {
                                if(!f) return false;
                                 return f->getParentEntity() == parentEdge;
                               });
        // For now, we look for any PE on this entity and add the overlap there
        if (pe != surfaceEdges.end()) {
          partitionEdge *edgeWithOverlap = dynamic_cast<partitionEdge *>(*pe);
          if (!edgeWithOverlap) {
            Msg::Error("Boundary edge is not a partitionEdge");
          }
          edgeToOverlaps[edgeWithOverlap].insert(edge);
        }
        else {
          // What does this represent ? FIXME
          // Msg::Error("Parent edge not found");
        }

      }

      // Create an artificial boundary of all the overlaps of this entity, with
      // new elements.
      partitionEdge *fullBnd =
        new partitionEdge(model, ++elementaryNumberBnd, {static_cast<int>(i)});
      fullBnd->setParentEntity(parentFace);

      std::vector<MLine *> bndElems;
      for(auto edge : boundaryEdges) {
        bndElems.push_back(new MLine(edge.getVertex(0), edge.getVertex(1)));
      }
      fullBnd->lines = std::move(bndElems); // Take ownership
      model->add(fullBnd);
      Msg::Info("Created full boundary %d for i = %d", fullBnd->tag(), i);
      this->boundariesByPartition[i].insert(fullBnd);
      gmsh::model::addPhysicalGroup(
        1, {fullBnd->tag()}, -1,
        "OverlapBndOfFace_" + std::to_string(tagParent) + "_part_" +
          std::to_string(i) + "_num_" + std::to_string(0));

      // Create overlaps of the physical boundaries
      for (auto [pe, edges]: edgeToOverlaps) {
        partitionEdge *bnd =
          new partitionEdge(model, ++elementaryNumberBnd, {static_cast<int>(i)});
        bnd->setParentEntity(pe);
        std::vector<MLine *> elems;
        for(auto edge : edges) {
          elems.push_back(new MLine(edge.getVertex(0), edge.getVertex(1)));
        }
        bnd->lines = std::move(elems); // Take ownership
        model->add(bnd);
        this->boundariesByPartition[i].insert(bnd);

        gmsh::model::addPhysicalGroup(
          1, {bnd->tag()}, -1,
          "OverlapOfBnd_" + std::to_string(tagParent) + "_part_" +
            std::to_string(i) + "_pe_" + std::to_string(pe->tag()));
      }
    }


  }
}
