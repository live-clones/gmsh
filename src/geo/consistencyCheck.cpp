// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "consistencyCheck.h"
#include <GModel.h>
#include <GmshMessage.h>
#include <partitionRegion.h>
#include <partitionFace.h>
#include <partitionEdge.h>
#include <partitionVertex.h>
#include <overlapFaceManager.h>
#include <overlapRegionManager.h>
#include <Context.h>


// TODO: use indices instead ?
std::unordered_map<MVertex *, int> countVertexOccurences(
  GModel *model,
  const std::optional<std::set<GEntity *, GEntityPtrLessThan>> &entities,
  int dim)
{
  std::unordered_map<MVertex *, int> result;
  if(dim != 3) {
    Msg::Error("countVertexOccurences(): Only dim = 3 is supported");
  }

  if(dim == 3) {
    std::set<GRegion *> regions;
    if(entities.has_value()) {
      for(auto entity : entities.value()) {
        if(entity->dim() == 3) {
          GRegion *region = dynamic_cast<GRegion *>(entity);
          if(region) { regions.insert(region); }
          else {
            Msg::Error("countVertexOccurences(): Entity %d is not a region",
                       entity->tag());
          }
        }
      }
    }
    else {
      for(auto entity : model->getRegions()) {
        GRegion *region = dynamic_cast<GRegion *>(entity);
        if(region && region->geomType() != GEntity::GeomType::OverlapVolume) { regions.insert(region); }
        else {
          Msg::Error("countVertexOccurences(): Entity %d is not a region",
                     entity->tag());
        }
      }
    }

    for (auto region : regions) {
        for (size_t elemId = 0; elemId < region->getNumMeshElements(); ++elemId) {
            auto elem = region->getMeshElement(elemId);
            for (int k = 0; k < elem->getNumVertices(); ++k) {
                auto vertex = elem->getVertex(k);
                result[vertex]++; // It is 0-initialized
        }
      }
    }
  }

  return result;
}

std::set<std::tuple<MVertex *, int, int>>
findMismatch(const std::unordered_map<MVertex *, int> &saved,
             const std::unordered_map<MVertex *, int> &expected)
{
  std::set<std::tuple<MVertex *, int, int>> errors;

  for (const auto& [vertex, savedCount]: saved) {
    if (savedCount == 0)
        Msg::Error("findMismatch: entry with 0.");
    auto it = expected.find(vertex);
    if (it == expected.end()) {
      errors.insert({vertex, savedCount, 0});
    } else if (it->second != savedCount) {
      errors.insert({vertex, savedCount, it->second});
    }
  }

  return errors;
}

// Same thing for set of all entities
template <typename T>
static void incrementAdjacency(std::vector<std::set<MVertex*>>& result, T begin, T end) {
  for (auto it = begin; it != end; ++it) {
    GEntity *entity = dynamic_cast<GEntity*>(*it);
    if (!entity) {
      Msg::Error("computeVertexAdjacency(): invalid entity");
    }
    Msg::Warning("Entity %d has %d mesh elements and is of type %s", entity->tag(), entity->getNumMeshElements(), entity->getTypeString().c_str());
    for (size_t elemId = 0; elemId < entity->getNumMeshElements(); ++elemId) {
      auto elem = entity->getMeshElement(elemId);
      for (int k = 0; k < elem->getNumVertices(); ++k) {
        auto vertex = elem->getVertex(k);
        for (int l = 0; l < elem->getNumVertices(); ++l) {
          if (l != k) {
            result.at(vertex->getNum()-1).insert(elem->getVertex(l));
          }
        }
      }
    }
  }
}

std::vector<std::set<MVertex *>> computeVertexAdjacency(GModel *model)
{
  size_t arraySize = model->getMaxVertexNumber();
  size_t countedVertices = 0;
  std::vector<std::set<MVertex *>> result(arraySize);

  incrementAdjacency(result, model->firstRegion(), model->lastRegion());
  incrementAdjacency(result, model->firstFace(), model->lastFace());
  incrementAdjacency(result, model->firstEdge(), model->lastEdge());
  incrementAdjacency(result, model->firstVertex(), model->lastVertex());

  for (size_t k = 0; k < arraySize; ++k) {
    if(!result[k].empty()) {
      countedVertices++;
      //Msg::Info("Vertex %d has %d adjacent vertices", k, result[k].size());
    }
    else {
      Msg::Warning("Vertex %d has no adjacent vertices", k);
    }
  }

  return result;
}

std::vector<std::set<MVertex *>>
computeVertexAdjacency(GModel *model,
                       const std::set<GRegion *, GEntityPtrLessThan> &regions,
                       const std::set<GFace *, GEntityPtrLessThan> &faces,
                       const std::set<GEdge *, GEntityPtrLessThan> &edges,
                       const std::set<GVertex *, GEntityPtrLessThan> &vertices)
{
  size_t arraySize = model->getMaxVertexNumber();
  size_t countedVertices = 0;
  std::vector<std::set<MVertex *>> result(arraySize);

  incrementAdjacency(result, regions.begin(), regions.end());
  incrementAdjacency(result, faces.begin(), faces.end());
  incrementAdjacency(result, edges.begin(), edges.end());
  incrementAdjacency(result, vertices.begin(), vertices.end());


  return result;
}

bool vertexInPartition(const MVertex *vert, int partition) {
  auto on = vert->onWhat();
  int dim = on->dim();
  IndicesReoriented parts;

  if (dim == 0) {
    auto pv = dynamic_cast<partitionVertex *>(on);
    parts = pv->getPartitions();
  }
  else if (dim == 1) {
    auto pe = dynamic_cast<partitionEdge *>(on);
    parts = pe->getPartitions();
  }
  else if (dim == 2) {
    auto pf = dynamic_cast<partitionFace *>(on);
    parts = pf->getPartitions();
  }
  else if (dim == 3) {
    auto pr = dynamic_cast<partitionRegion *>(on);
    parts = pr->getPartitions();
  }
  else {
    Msg::Error("vertexInPartition(): invalid dimension");
  }

  return std::find(parts.begin(), parts.end(), partition) != parts.end();
}



EntityPackage::EntityPackage(const GModel *model, int partitionToSave) {

  

  const bool saveAllEntities = CTX::instance()->mesh.saveFullBrep != 0;
  auto isPartitionInParts = [partitionToSave, saveAllEntities](const IndicesReoriented& part) {
    if (partitionToSave == 0 || saveAllEntities)
      return true;
    else
      return std::find(part.begin(), part.end(), partitionToSave) != part.end();
  };
  // TODO: eliminate overlap BND ?

  for (auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    auto *region = dynamic_cast<partitionRegion*>(*it);
    if (region && region->geomType() == GEntity::GeomType::PartitionVolume && isPartitionInParts(region->getPartitions())) {
        regions.insert(region);
    }
  }
  for (auto it = model->firstFace(); it != model->lastFace(); ++it) {
    auto *face = dynamic_cast<partitionFace*>(*it);
    if (face && face->geomType() == GEntity::GeomType::PartitionSurface && isPartitionInParts(face->getPartitions())) {
        faces.insert(face);
    }
  }
  for (auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    auto *edge = dynamic_cast<partitionEdge*>(*it);
    if (edge && edge->geomType() == GEntity::GeomType::PartitionCurve && isPartitionInParts(edge->getPartitions())) {
        edges.insert(edge);
    }
  }
  for (auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    auto *vertex = dynamic_cast<partitionVertex*>(*it);
    if (vertex && vertex->geomType() == GEntity::GeomType::PartitionPoint && isPartitionInParts(vertex->getPartitions())) {
        vertices.insert(vertex);
    }
  }

  addEmbeddedVertices(model);
  addOverlappedEntities(model, partitionToSave);
  fillFromNodes(model);
}

void EntityPackage::fillFromNodes(const GModel *model)
{
  for (GRegion* region: regions) {
    this->addEntitiesFromNodes(region);
  }
  for (GFace* face: faces) {
    this->addEntitiesFromNodes(face);
  }
  for (GEdge* edge: edges) {
    this->addEntitiesFromNodes(edge);
  }
  for (GVertex* vertex: vertices) {
    this->addEntitiesFromNodes(vertex);
  }
}

void EntityPackage::addEntitiesFromNodes(const GEntity* entity)
{
    for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
        auto elem = entity->getMeshElement(i);
        for (int j = 0; j < elem->getNumVertices(); ++j) {
            auto vertex = elem->getVertex(j);
            auto on = vertex->onWhat();
            if (on->dim() == 3) {
                GRegion* region = dynamic_cast<GRegion*>(on);
                if (!region) Msg::Error("Entity %d is not a region", on->tag());
                regions.insert(region);
            }
            else if (on->dim() == 2) {
                GFace* face = dynamic_cast<GFace*>(on);
                if (!face) Msg::Error("Entity %d is not a face", on->tag());
                faces.insert(face);
            }
            else if (on->dim() == 1) {
                GEdge* edge = dynamic_cast<GEdge*>(on);
                if (!edge) Msg::Error("Entity %d is not an edge", on->tag());
                edges.insert(edge);
            }
            else if (on->dim() == 0) {
                GVertex* vertex = dynamic_cast<GVertex*>(on);
                if (!vertex) Msg::Error("Entity %d is not a vertex", on->tag());
                vertices.insert(vertex);
            }
        }
    }
}

void EntityPackage::addEmbeddedVertices(const GModel *model) {
  // Ensure all embedded vertices are there
  std::set<GVertex *, GEntityPtrLessThan> embeddedVerticesEntities;
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    GRegion *gr = static_cast<GRegion *>(*it);
    auto embVertices = gr->embeddedVertices();
    for(GVertex *vertex : embVertices) {
      embeddedVerticesEntities.insert(vertex);
    }
  }

  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    partitionVertex *pv = dynamic_cast<partitionVertex *>(*it);
    if(pv) {
      GVertex *parentVert = dynamic_cast<GVertex *>(pv->getParentEntity());
      if(parentVert && embeddedVerticesEntities.count(parentVert) > 0) {
        this->vertices.insert(*it);
      }
    }
  }
}

void EntityPackage::addOverlappedEntities(const GModel *model, int partitionToSave) {
  if(model->hasOverlaps()) {
    // Now add the overlapped entities and the boundaries
    for(const auto &[tag, manager] : model->getOverlapFaceManagers()) {
      auto map = manager->getOverlapsByPartition();
      for(overlapFace *ov : map[partitionToSave]) {
        this->faces.insert(ov->getOverlapOn());
        for(GEdge *edge : ov->getOverlapOn()->edges()) {
          this->edges.insert(edge);
        }
        for(GVertex *vertex : ov->getOverlapOn()->vertices()) {
          this->vertices.insert(vertex);
        }
      }
      auto mapbnd = manager->getBoundariesByPartition();
      for(partitionEdge *bnd : mapbnd[partitionToSave]) {
        this->edges.insert(bnd);
      }
    }

    for(const auto &[tag, manager] : model->getOverlapRegionManagers()) {
      auto map = manager->getOverlapsByPartition();
      for(overlapRegion *ov : map[partitionToSave]) {
        auto overlappedRegion = ov->getOverlapOn();
        this->regions.insert(overlappedRegion);
        for(GFace *face : overlappedRegion->faces()) {
          this->faces.insert(face);
        }
        for(GEdge *edge : overlappedRegion->edges()) {
          this->edges.insert(edge);
        }
        for(GVertex *vertex : overlappedRegion->vertices()) {
          this->vertices.insert(vertex);
        }
      }
      auto mapbnd = manager->getBoundariesByPartition();
      for(partitionFace *bnd : mapbnd[partitionToSave]) {
        this->faces.insert(bnd);
      }
    }
  }
}
