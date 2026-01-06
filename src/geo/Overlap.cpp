// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Martin


#include "Overlap.h"
#include <unordered_map>
#include <unordered_set>
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MFace.h"
#include "GModel.h"

#include <OS.h> // Timing

//#include "overlapHelpers.h"

template <int dim>
 OverlapCollection<dim> quickOverlap(GModel *const model)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");
  size_t numParts =
    model->getNumPartitions(); // Ensure the model is partitioned
  if(numParts == 0) {
    Msg::Error("Model is not partitioned. Cannot compute quick overlap.");
  }

  double time0 = Cpu();

  std::map<MVertex *, std::set<int>> vertexToPartitions;
  auto updateVertexToPartition = [&vertexToPartitions](GEntity *ge) {
    auto partsToAdd = getEntityPartition(ge, false);
    if(partsToAdd.empty()) return;
    for(size_t ie = 0; ie < ge->getNumMeshElements(); ++ie) {
      MElement *element = ge->getMeshElement(ie);
      for(size_t iv = 0; iv < element->getNumVertices(); ++iv) {
        MVertex *v = element->getVertex(iv);
        auto &parts = vertexToPartitions[v];
        parts.insert(partsToAdd.begin(), partsToAdd.end());
      }
    }
  };

  OverlapCollection<dim> overlap(numParts);
  auto handleEntity = [&overlap, &vertexToPartitions](GEntity *entity) {
    auto partitionEntity = cast<dim>(entity);
    static_assert(
      std::is_same_v<decltype(partitionEntity),
                     typename OverlapHelpers<dim>::PartitionEntity *>,
      "The cast to PartitionEntity failed. Check the entity type.");
    if(!partitionEntity || partitionEntity->getPartitions().size() != 1) return;

    int partition = partitionEntity->getPartitions()[0];

    for(size_t e = 0; e < partitionEntity->getNumMeshElements(); ++e) {
      MElement *element = partitionEntity->getMeshElement(e);
      for(size_t v = 0; v < element->getNumVertices(); ++v) {
        /*auto onWhat = element->getVertex(v)->onWhat();
        if(onWhat->dim() < dim) // Boundary vertex
        {
          auto partitions = getEntityPartition(onWhat);
          for(int part : partitions) {
            if(part != partition) {
              overlap[part - 1][partitionEntity].insert(element);
            }
          }
        }*/
        if (element->getVertex(v)->onWhat()->dim() == dim) continue; // Non-Boundary vertex, skip it

        auto parts = vertexToPartitions[element->getVertex(v)];
        for(int part : parts) {
          if(part != partition) {
            overlap[part - 1][partitionEntity].insert(element);
          }
        }
      }
    }
  };

  if constexpr(dim == 2) {
    for(auto &&face : model->getFaces()) { updateVertexToPartition(face); }
    for(auto &&face : model->getFaces()) { handleEntity(face); }
  }
  else if constexpr(dim == 3) {
    for(auto &&region : model->getRegions()) { updateVertexToPartition(region); }
    for(auto &&region : model->getRegions()) { handleEntity(region); }
  }

  double time1 = Cpu();
  Msg::Info("Quick overlap computed in %g s. (CPU time)", time1 - time0);

  return overlap;
}

template OverlapCollection<2> quickOverlap<2>(GModel *const model);
template OverlapCollection<3> quickOverlap<3>(GModel *const model);

template <int dim>
void extendOverlapCollection(GModel *const model,
                             OverlapCollection<dim> &overlaps)
{

  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");
  if(overlaps.size() != model->getNumPartitions()) {
    Msg::Error("Number of partitions in overlaps does not match model partitions.");
  }

  //std::vector<std::unordered_set<MVertex*>> verticesInOverlap(model->getNumPartitions());
  std::unordered_multimap<MVertex*, int> vertexToOverlaps; // 0-based index

  // Build vertex to partitions map
  for(size_t i = 0; i < overlaps.size(); ++i) {
    for (const auto& [_, elements]: overlaps[i]) {
      for (MElement* element : elements) {
        for (size_t v = 0; v < element->getNumVertices(); ++v) {
          MVertex *vertex = element->getVertex(v);
          // Store the vertex and the partition index, 0-based
          vertexToOverlaps.insert({vertex, static_cast<int>(i)});
        }
      }
    }
  }

  auto addElements = [&](typename OverlapHelpers<dim>::PartitionEntity* pe) {
    for (size_t ie = 0; ie < pe->getNumMeshElements(); ++ie) {
      MElement* element = pe->getMeshElement(ie);
      for (size_t v = 0; v < element->getNumVertices(); ++v) {
        MVertex *vertex = element->getVertex(v);
        auto range = vertexToOverlaps.equal_range(vertex);
        for (auto it = range.first; it != range.second; ++it) {
          int partitionIndex = it->second;
          // Do not overlap yourself!
          auto partitions = pe->getPartitions();
          if (std::find(partitions.begin(), partitions.end(), partitionIndex + 1) != partitions.end()) {
            continue;
          }
          overlaps[partitionIndex][pe].insert(element);
        }
      }
    }
  };

  if constexpr (dim == 2) {
    for (auto it = model->firstFace(); it != model->lastFace(); ++it) {
      auto face = *it;
      auto partitionEntity = dynamic_cast<typename OverlapHelpers<dim>::PartitionEntity *>(face);
      if (partitionEntity) {
        addElements(partitionEntity);
      }
    }
  }
  else if constexpr (dim == 3) {
    for (auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      auto region = *it;
      auto partitionEntity = dynamic_cast<typename OverlapHelpers<dim>::PartitionEntity *>(region);
      if (partitionEntity) {
        addElements(partitionEntity);
      }
    }
  }

}

template void extendOverlapCollection<2>(GModel *const model,
                                          OverlapCollection<2> &overlaps);
template void extendOverlapCollection<3>(GModel *const model,
                                          OverlapCollection<3> &overlaps);

// Read an overlap collection and modify the GModel to add overlap entities.
// No new elements are created but these entities will point to underlying elements of their covered partitionEntity.
template <int dim>
void buildOverlapEntities(GModel* const model, const OverlapCollection<dim>& overlaps)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");

  using OverlapEntity = typename OverlapHelpers<dim>::OverlapEntity;
  using ParentEntityType = typename OverlapHelpers<dim>::Entity;

  if (overlaps.size() != model->getNumPartitions())
    Msg::Error("Number of partitions in overlaps does not match model partitions.");
  
  for (size_t i = 0; i < overlaps.size(); ++i) {
    int partition = i + 1; // Partitions are 1-indexed
    for (const auto& [covered, elements] : overlaps[i]) {
      if (!covered) continue; // Skip null entities
      auto overlapEntity = new OverlapEntity(model, covered, partition);
      bool add = model->add(overlapEntity);
      if (!add)
        Msg::Error("Failed to add overlap entity for partition %d and covered entity with tag %d.",
                   partition, covered->tag());
      model->addOverlap(overlapEntity);

      if constexpr (dim == 2)
      if (std::get<0>(model->getAllOverlaps()).back() != overlapEntity) {
        Msg::Error("Overlap entity was not added to the model's overlaps.");
      }

      auto parent = dynamic_cast<ParentEntityType *>(covered->getParentEntity());
      if (!parent) {
        Msg::Error("Parent entity of dim %d and tag %d is not of the expected type.",
                   covered->dim(), covered->tag());
      }
      
      // Add elements to the overlap entity - no new creation
      for (const auto& element : elements) {
        overlapEntity->addElement(element);
      }
    }
  }

}

template void buildOverlapEntities<2>(GModel* const model, const OverlapCollection<2>& overlaps);
template void buildOverlapEntities<3>(GModel* const model, const OverlapCollection<3>& overlaps);

template <int dim>
OveralBoundariesMesh<dim> findBoundaryOfOverlapEntities(
  GModel *const model,
  const OverlapCollection<dim> overlaps)
{
  using Entity = typename OverlapHelpers<dim>::Entity;
  using MBnd = typename OverlapHelpers<dim>::BoundaryMeshObject;
  using Hash = typename OverlapHelpers<dim>::BoundaryMeshObjectHash;
  using Equal =  typename OverlapHelpers<dim>::BoundaryMeshObjectEqual;
  OveralBoundariesMesh<dim> result(overlaps.size());

  for(size_t i = 0; i < overlaps.size(); ++i) {
    std::unordered_map<Entity *, std::unordered_map<MBnd, unsigned, Hash, Equal>> counts;
    for(const auto &[covered, elements] : overlaps[i]) {
      if(!covered) continue; // Skip null entities
      auto parent = dynamic_cast<Entity *>(covered->getParentEntity());
      if(!parent) {
        Msg::Error(
          "Parent entity of dim %d and tag %d is not of the expected type.",
          covered->dim(), covered->tag());
      }

      auto &dict = counts[parent];
      for(const auto &element : elements) {
        if constexpr(dim == 2) {
          for(int j = 0; j < element->getNumEdges(); ++j) {
            MBnd edge = element->getEdge(j);
            dict[edge]++;
          }
        }
        else if constexpr(dim == 3) {
          for(int j = 0; j < element->getNumFaces(); ++j) {
            MBnd face = element->getFace(j);
            dict[face]++;
          }
        }
      }
    }

    for(const auto &[parent, boundaryCounts] : counts) {
      auto &boundarySet = result[i][parent];
      for(const auto &[boundary, count] : boundaryCounts) {
        if(count == 1) { // Only keep unique boundaries
          boundarySet.insert(boundary);
        }
      }
    }
  }

  return result;
}

template OveralBoundariesMesh<2>
findBoundaryOfOverlapEntities<2>(GModel *const model,
                                 const OverlapCollection<2> overlaps);
template OveralBoundariesMesh<3>
findBoundaryOfOverlapEntities<3>(GModel *const model,
                                 const OverlapCollection<3> overlaps);


template <int dim>
static BoundaryToPartitionEntity<dim>
buildBoundaryElementToEntityDict(GModel *const model)
{
  BoundaryToPartitionEntity<dim> boundaryToEntity;
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");
  if constexpr(dim == 2) {
    for(auto &&face : model->getEdges()) {
      auto partitionEdge =
        dynamic_cast<typename OverlapHelpers<dim>::BoundaryEntity *>(face);
      if(partitionEdge) {
        for(size_t i = 0; i < partitionEdge->getNumMeshElements(); ++i) {
          MElement *element = partitionEdge->getMeshElement(i);
          for(int j = 0; j < element->getNumEdges(); ++j) {
            MEdge edge = element->getEdge(j);
            if(boundaryToEntity.find(edge) == boundaryToEntity.end()) {
              boundaryToEntity[edge] = partitionEdge;
            }
            else {
              Msg::Error("Boundary edge already has an associated entity.");
            }
          }
        }
      }
    }
  }
  else if constexpr(dim == 3) {
    for(auto &&face : model->getFaces()) {
      auto partitionFace =
        dynamic_cast<typename OverlapHelpers<dim>::BoundaryEntity *>(face);
      if(partitionFace) {
        for(size_t i = 0; i < partitionFace->getNumMeshElements(); ++i) {
          MElement *element = partitionFace->getMeshElement(i);
          for(int j = 0; j < element->getNumFaces(); ++j) {
            MFace face = element->getFace(j);
            if(boundaryToEntity.find(face) == boundaryToEntity.end()) {
              boundaryToEntity[face] = partitionFace;
            }
            else {
              Msg::Error(
                "Boundary face already has an associated entity."); // Should
                                                                    // not
                                                                    // happen
            }
          }
        }
      }
    }
  }

  return boundaryToEntity;
}

template BoundaryToPartitionEntity<2>
buildBoundaryElementToEntityDict<2>(GModel *const model);
template BoundaryToPartitionEntity<3>
buildBoundaryElementToEntityDict<3>(GModel *const model);

template <int dim>
void overlapBuildBoundaries(GModel *const model,
                            const OverlapCollection<dim> &overlaps)
{
  // Is this MEdge/MFace on an existing partitionEdge/Face ?
  auto boundaryToEntity = buildBoundaryElementToEntityDict<dim>(model);
  // What is the set of MEdge/MFace of the overlap for each **parent** entity ?
  // It's a vector per partition, then the entry is a dict Entity-> set of bnds
  auto boundaryElements = findBoundaryOfOverlapEntities<dim>(model, overlaps);

  using BoundaryMeshObject = typename OverlapHelpers<dim>::BoundaryMeshObject;
  using BoundaryMeshObjectHash =
    typename OverlapHelpers<dim>::BoundaryMeshObjectHash;
  using BoundaryMeshObjectEqual =
    typename OverlapHelpers<dim>::BoundaryMeshObjectEqual;

  if(boundaryElements.size() != model->getNumPartitions()) {
    Msg::Error(
      "Number of boundary elements does not match number of partitions.");
  }

  // Loop over all partitions
  for(size_t i = 0; i < boundaryElements.size(); ++i) {
    int partition = i + 1; // Partitions are 1-indexed
    for(const auto &[parent, boundarySet] : boundaryElements[i]) {
      std::unordered_set<BoundaryMeshObject, BoundaryMeshObjectHash,
                         BoundaryMeshObjectEqual>
        innerboundarySet;
      std::unordered_map<GEntity *, std::unordered_set<BoundaryMeshObject,
                                                       BoundaryMeshObjectHash,
                                                       BoundaryMeshObjectEqual>>
        boundariesOfExisting;
      if(!parent) continue; // Skip null entities
      if(boundarySet.empty()) continue; // Skip empty sets

      // Overlap bnd on partition for this parent entity
      for(auto melement : boundarySet) {
        auto it = boundaryToEntity.find(melement);
        if(it != boundaryToEntity.end()) {
          auto partitionEntity = it->second;
          auto parentEntity = (partitionEntity->getParentEntity());
          if(!parentEntity) { Msg::Error("No parent entity"); }
          
          // If it is part of the outer boundary, add it to the overlap of boundary
          if(parentEntity->dim() == dim - 1) {
            boundariesOfExisting[parentEntity].insert(melement);
          }
          else {
            // Element is on an interface between two subdomains. If none of the subdomains are
            // the current partition, add to inner boundary (which will lead to a duplicate element)
            // On small partitions it's an edge case but this is actually critical.
            auto parts = getEntityPartition(partitionEntity);
            if(std::find(parts.begin(), parts.end(), partition) ==
               parts.end()) {
              //Msg::Warning("Interface between two other subdomains added as artificial boundary.");
              innerboundarySet.insert(melement);
            }
          }
        }
        else {
          // element not on an existing entity, add to inner boundary
          innerboundarySet.insert(melement);
        }
      }

      // Create new entity for inner boundary. Has one partition and zero
      // parents
      if(!innerboundarySet.empty()) {
        auto bnd = new typename OverlapHelpers<dim>::BoundaryEntity(
          model, model->getMaxElementaryNumber(dim - 1) + 1, {partition});

        // Add elements
        if constexpr(dim == 2) {
          for(const MEdge &edge : innerboundarySet) {
            auto elem = new MLine(edge.getVertex(0), edge.getVertex(1));
            bnd->addLine(elem);
          }
        }
        else if constexpr(dim == 3) {
          for (const MFace& face : innerboundarySet) {
            if (face.getNumVertices() == 3) {
              auto elem = new MTriangle(
                face.getVertex(0), face.getVertex(1), face.getVertex(2));
              bnd->addTriangle(elem);
            }
            else if (face.getNumVertices() == 4) {
              auto elem = new MQuadrangle(
                face.getVertex(0), face.getVertex(1), face.getVertex(2),
                face.getVertex(3));
              bnd->addQuadrangle(elem);
            }
            else {
              Msg::Error("Face with %d vertices not supported in 3D overlap.",
                         face.getNumVertices());
            }
          }
        }
        model->add(bnd);
        model->addInnerBoundary(parent, bnd);
      }

      for(const auto &[entity, boundarySet] : boundariesOfExisting) {
        if(!entity) continue; // Skip null entities
        if(boundarySet.empty()) continue; // Skip empty sets

        auto bnd = new typename OverlapHelpers<dim>::BoundaryEntity(
          model, model->getMaxElementaryNumber(dim - 1) + 1, {partition});

        // Add elements
        if constexpr(dim == 2) {
          for(const MEdge &edge : boundarySet) {
            auto elem = new MLine(edge.getVertex(0), edge.getVertex(1));
            bnd->addLine(elem);
          }
          Msg::Info("Created overlap of boundary entity with %lu elements for partition %d.",
                    bnd->getNumMeshElements(), partition);
        }
        else if constexpr(dim == 3) {
          for (const MFace& face : boundarySet) {
            if (face.getNumVertices() == 3) {
              auto elem = new MTriangle(
                face.getVertex(0), face.getVertex(1), face.getVertex(2));
              bnd->addTriangle(elem);
            }
            else if (face.getNumVertices() == 4) {
              auto elem = new MQuadrangle(
                face.getVertex(0), face.getVertex(1), face.getVertex(2),
                face.getVertex(3));
              bnd->addQuadrangle(elem);
            }
            else {
              Msg::Error("Face with %d vertices not supported in 3D overlap.",
                         face.getNumVertices());
            }
          }
          Msg::Info("Created overlap of boundary entity with %lu elements for partition %d in dimension %d.",
                    bnd->getNumMeshElements(), partition, dim);
        }
        Msg::Info("Entity %d %d is creating an overlap of %d %d", parent->dim(),
                  parent->tag(), entity->dim(), entity->tag());
        model->add(bnd);
        if constexpr(dim == 2)
          model->addOverlapOfBoundary(dynamic_cast<GEdge *>(entity), bnd, parent);
        else if constexpr(dim == 3)
          model->addOverlapOfBoundary(dynamic_cast<GFace *>(entity), bnd, parent);
      }
    }
  }
}

template void overlapBuildBoundaries<2>(GModel *const model,
                                         const OverlapCollection<2> &overlaps);
template void overlapBuildBoundaries<3>(GModel *const model,
                                            const OverlapCollection<3> &overlaps);

template <int dim>
std::unordered_map<typename OverlapHelpers<dim>::PartitionEntity *,
                   std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave(GModel *const model, int partition)
{
  std::unordered_map<typename OverlapHelpers<dim>::PartitionEntity *,
                     std::unordered_set<MElement *>>
    result;
  
  using overlapEntityType = typename OverlapHelpers<dim>::OverlapEntity;

  const auto& overlaps = std::get<std::vector<overlapEntityType*>>(model->getAllOverlaps());
  for (auto overlapPtr: overlaps) {
    if (overlapPtr->owningPartition() != partition) continue;
    size_t numElements = overlapPtr->getNumMeshElements();
    for (size_t i = 0; i < numElements; ++i) {
      MElement *element = overlapPtr->getMeshElement(i);
      result[overlapPtr->getCovered()].insert(element);
    }
  }
  
  return result;
}

template std::unordered_map<typename OverlapHelpers<2>::PartitionEntity *,
                            std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave<2>(GModel *const model, int partition);

template std::unordered_map<typename OverlapHelpers<3>::PartitionEntity *,
                            std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave<3>(GModel *const model, int partition);

template <int dim>
std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave(
  GModel *const model, int partition,
  const std::unordered_map<typename OverlapHelpers<dim>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities)
{
  std::unordered_map<GEntity *, std::unordered_set<MVertex *>> result;
  for(const auto &[coveredEntity, elements] : coveredEntities) {
    for (MElement* elem: elements) {
      for (size_t v = 0; v < elem->getNumVertices(); ++v) {
        MVertex *vertex = elem->getVertex(v);
        auto onWhat = vertex->onWhat();
        result[onWhat].insert(vertex);
      }
    }
  }

  // Add empty entities that are the BREP of the covered entities
  if (partition == 0)
    return result;

  for (const auto& [coveredEntity, _] : coveredEntities) {
    result[coveredEntity]; // This will create an empty set if not present
    auto brep = coveredEntity->boundaryEntities();
    for (auto entity : brep) {
      result[entity]; // This will create an empty set if not present
      for (auto entity2: entity->boundaryEntities()) {
        result[entity2]; // This will create an empty set if not present
        for (auto entity3: entity2->boundaryEntities()) {
          result[entity3]; // This will create an empty set if not present
        }
      }
    }
  }

  // FIX for embedded vertices: the BREP trick doesn't save them, so we add any partitionVertex with at least one partition in what we export
  // Otherwise the node is exported on a non-existent partitionVertex and the mesh is invalid
  std::set<int> partitionsToExport;
  for(const auto &[coveredEntity, _] : coveredEntities) {
    auto parts = getEntityPartition(coveredEntity);
    for(int part : parts) partitionsToExport.insert(part);
  }
  partitionsToExport.erase(partition); // Remove own partition (full export)

  for (auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    auto pv = dynamic_cast<partitionVertex *>(*it);
    if (!pv) continue;
    auto parts = pv->getPartitions();
    if (std::any_of(parts.begin(), parts.end(), [&](int p) { return partitionsToExport.count(p) > 0; })) {
      result[pv]; // Insert empty vertex
    }
  }
  // Same for partitionEdge
  for (auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    auto pe = dynamic_cast<partitionEdge *>(*it);
    if (!pe) continue;
    auto parts = pe->getPartitions();
    if (std::any_of(parts.begin(), parts.end(), [&](int p) { return partitionsToExport.count(p) > 0; })) {
      result[pe]; // Insert empty edge
    }
  }


  return result;
}

template std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave<2>(
  GModel *const model, int partition,
  const std::unordered_map<typename OverlapHelpers<2>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities);
template std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave<3>(
  GModel *const model, int partition,
  const std::unordered_map<typename OverlapHelpers<3>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities);