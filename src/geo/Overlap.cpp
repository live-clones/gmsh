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

// Small util. Convert to partitionFace or partionRegion semi-statically
template <int dim>
static typename EntityTraits<dim>::PartitionEntity *
castToPartitionEntity(GEntity *e)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");
  return dynamic_cast<typename EntityTraits<dim>::PartitionEntity *>(e);
}

template <int dim> OverlapCollection<dim> quickOverlap(GModel *const model)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");
  size_t numParts =
    model->getNumPartitions(); // Ensure the model is partitioned
  if(numParts == 0) {
    Msg::Error("Model is not partitioned. Cannot compute quick overlap.");
  }

  double time0 = Cpu();

  std::map<MVertex *, std::set<int>> vertexToPartitions;

  // Function that takes a partitioned entity and adds fills the dictionary for
  // all used (not owned!) vertices
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

  // For each partition and each partitioned entity, we keep a dict mapping a
  // partitioned entity to the elements of its overlaps. These elements are not
  // separed by origin
  OverlapCollection<dim> overlap(numParts);

  auto handleEntity = [&overlap, &vertexToPartitions](GEntity *entity) {
    auto partitionEntity = castToPartitionEntity<dim>(entity);
    static_assert(std::is_same_v<decltype(partitionEntity),
                                 typename EntityTraits<dim>::PartitionEntity *>,
                  "The cast to PartitionEntity failed. Check the entity type.");
    if(!partitionEntity || partitionEntity->getPartitions().size() != 1) return;

    int partition = partitionEntity->getPartitions()[0];

    for(size_t e = 0; e < partitionEntity->getNumMeshElements(); ++e) {
      MElement *element = partitionEntity->getMeshElement(e);
      for(size_t v = 0; v < element->getNumVertices(); ++v) {
        if(element->getVertex(v)->onWhat()->dim() == dim)
          continue; // Non-Boundary vertex, skip it
        // It is critical in some cases to check we uses partitions of the
        // vertex and not the partitions of its entities (Particular case when a
        // vertex is on partitions that do not use the interface on which it
        // lies, if the BREP isn't perfect)
        auto parts = vertexToPartitions[element->getVertex(v)];
        // If this element has a vertex used by other partitions, it is part of
        // their overlap
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
    for(auto &&region : model->getRegions()) {
      updateVertexToPartition(region);
    }
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
    Msg::Error(
      "Number of partitions in overlaps does not match model partitions.");
  }

  std::unordered_multimap<MVertex *, int> vertexToOverlaps; // 0-based index

  // Build vertex to partitions map:
  // We must know in which overlaps a vertex lie
  for(size_t i = 0; i < overlaps.size(); ++i) {
    for(const auto &[_, elements] : overlaps[i]) {
      for(MElement *element : elements) {
        for(size_t v = 0; v < element->getNumVertices(); ++v) {
          MVertex *vertex = element->getVertex(v);
          // Store the vertex and the partition index, 0-based
          vertexToOverlaps.insert({vertex, static_cast<int>(i)});
        }
      }
    }
  }

  // We will loop over all elements of the dimension. If it shares a vertex with
  // one already in the overlap, we add it.
  auto addElements = [&](typename EntityTraits<dim>::PartitionEntity *pe) {
    for(size_t ie = 0; ie < pe->getNumMeshElements(); ++ie) {
      MElement *element = pe->getMeshElement(ie);
      for(size_t v = 0; v < element->getNumVertices(); ++v) {
        MVertex *vertex = element->getVertex(v);
        auto range = vertexToOverlaps.equal_range(vertex);
        for(auto it = range.first; it != range.second; ++it) {
          int partitionIndex = it->second;
          // Do not overlap yourself!
          auto partitions = pe->getPartitions();
          if(std::find(partitions.begin(), partitions.end(),
                       partitionIndex + 1) != partitions.end()) {
            continue;
          }
          overlaps[partitionIndex][pe].insert(element);
        }
      }
    }
  };

  if constexpr(dim == 2) {
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      auto face = *it;
      auto partitionEntity =
        dynamic_cast<typename EntityTraits<dim>::PartitionEntity *>(face);
      if(partitionEntity) { addElements(partitionEntity); }
    }
  }
  else if constexpr(dim == 3) {
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      auto region = *it;
      auto partitionEntity =
        dynamic_cast<typename EntityTraits<dim>::PartitionEntity *>(region);
      if(partitionEntity) { addElements(partitionEntity); }
    }
  }
}

template void extendOverlapCollection<2>(GModel *const model,
                                         OverlapCollection<2> &overlaps);
template void extendOverlapCollection<3>(GModel *const model,
                                         OverlapCollection<3> &overlaps);

// Read an overlap collection and modify the GModel to add overlap entities.
// No new elements are created but these entities will point to underlying
// elements of their covered partitionEntity.
template <int dim>
void buildOverlapEntities(GModel *const model,
                          const OverlapCollection<dim> &overlaps)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");

  using OverlapEntity = typename EntityTraits<dim>::OverlapEntity;
  using ParentEntityType = typename EntityTraits<dim>::Entity;

  if(overlaps.size() != model->getNumPartitions())
    Msg::Error(
      "Number of partitions in overlaps does not match model partitions.");

  for(size_t i = 0; i < overlaps.size(); ++i) {
    const int partition = i + 1; // Partitions are 1-indexed
    for(const auto &[covered, elements] : overlaps[i]) {
      if(!covered) continue; // Skip null entities
      OverlapEntity *overlapEntity = nullptr;
      try {
        overlapEntity = new OverlapEntity(model, covered, partition);
      } catch(const std::bad_alloc &e) {
        Msg::Error("Failed to allocate memory for overlap entity for partition "
                   "%d and covered entity with tag %d: %s",
                   partition, covered->tag(), e.what());
      }
      bool add = model->add(overlapEntity);
      if(!add)
        Msg::Error("Failed to add overlap entity for partition %d and covered "
                   "entity with tag %d. (Tag already existing)",
                   partition, covered->tag());
      model->addOverlap(overlapEntity);

      if constexpr(dim == 2) {
        if(std::get<0>(model->getAllOverlaps()).back() != overlapEntity) {
          Msg::Error("Overlap entity was not added to the model's overlaps.");
        }
      }
      if constexpr(dim == 3) {
        if(std::get<1>(model->getAllOverlaps()).back() != overlapEntity) {
          Msg::Error("Overlap entity was not added to the model's overlaps.");
        }
      }

      auto parent =
        dynamic_cast<ParentEntityType *>(covered->getParentEntity());
      if(!parent) {
        Msg::Error("Parent entity of dim %d and tag %d is not of the expected "
                   "type or was not found.",
                   covered->dim(), covered->tag());
      }

      // Add elements to the overlap entity - no new creation
      for(const auto &element : elements) {
        overlapEntity->addElement(element);
      }
    }
  }
}

template void buildOverlapEntities<2>(GModel *const model,
                                      const OverlapCollection<2> &overlaps);
template void buildOverlapEntities<3>(GModel *const model,
                                      const OverlapCollection<3> &overlaps);

template <int dim>
OveralBoundariesMesh<dim>
findBoundaryOfOverlapEntities(const OverlapCollection<dim> &overlaps)
{
  using Entity = typename EntityTraits<dim>::Entity;
  using MBnd = typename EntityTraits<dim>::BoundaryMeshObject;
  using Hash = typename EntityTraits<dim>::BoundaryMeshObjectHash;
  using Equal = typename EntityTraits<dim>::BoundaryMeshObjectEqual;
  // Track count and one parent element for each boundary
  // We only need one element since boundaries with count==1 are kept
  using BndInfoMap =
    std::unordered_map<MBnd, std::pair<unsigned, MElement *>, Hash, Equal>;
  OveralBoundariesMesh<dim> result(overlaps.size());

// Embarassingly parallel
#pragma omp parallel for schedule(dynamic)
  for(size_t i = 0; i < overlaps.size(); ++i) {
    std::unordered_map<Entity *, BndInfoMap> counts;

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
            auto &info = dict[edge];
            info.first++;
            info.second = element; // Store the parent element
          }
        }
        else if constexpr(dim == 3) {
          for(int j = 0; j < element->getNumFaces(); ++j) {
            MBnd face = element->getFace(j);
            auto &info = dict[face];
            info.first++;
            info.second = element; // Store the parent element
          }
        }
      }
    }

    for(const auto &[parent, boundaryInfo] : counts) {
      auto &boundaryMap = result[i][parent];
      for(const auto &[boundary, info] : boundaryInfo) {
        if(info.first == 1) { // Only keep unique boundaries
          boundaryMap[boundary] = info.second; // Map boundary to parent element
        }
      }
    }
  }

  return result;
}

template OveralBoundariesMesh<2>
findBoundaryOfOverlapEntities<2>(const OverlapCollection<2> &overlaps);
template OveralBoundariesMesh<3>
findBoundaryOfOverlapEntities<3>(const OverlapCollection<3> &overlaps);

template <int dim>
static BoundaryToPartitionEntity<dim>
buildBoundaryElementToEntityDict(GModel *const model)
{
  BoundaryToPartitionEntity<dim> boundaryToEntity;
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");

  using BEntity = typename EntityTraits<dim>::BoundaryEntity;

  // In 2D, build a MEdge -> PartitionEdge dict
  // In 3D, build a MFace -> PartitionFace dict
  // We iterate over all partition entities and their elements and build the
  // dict. Keys should be unique.
  auto processEntity = [&](auto *entity) {
    auto partitionEntity = dynamic_cast<BEntity *>(entity);
    if(!partitionEntity) return;

    for(size_t i = 0; i < partitionEntity->getNumMeshElements(); ++i) {
      MElement *element = partitionEntity->getMeshElement(i);

      auto addBoundary = [&](const auto &boundary) {
        // try_emplace returns {iterator, bool inserted}
        if(!boundaryToEntity.try_emplace(boundary, partitionEntity).second) {
          Msg::Error("Boundary object already has an associated entity.");
        }
      };

      if constexpr(dim == 2) {
        for(int j = 0; j < element->getNumEdges(); ++j)
          addBoundary(element->getEdge(j));
      }
      else {
        for(int j = 0; j < element->getNumFaces(); ++j)
          addBoundary(element->getFace(j));
      }
    }
  };

  if constexpr(dim == 2) {
    for(auto *edge : model->getEdges()) processEntity(edge);
  }
  else {
    for(auto *face : model->getFaces()) processEntity(face);
  }

  return boundaryToEntity;
}

template BoundaryToPartitionEntity<2>
buildBoundaryElementToEntityDict<2>(GModel *const model);
template BoundaryToPartitionEntity<3>
buildBoundaryElementToEntityDict<3>(GModel *const model);

// Helper to create a high-order line element from an edge and its parent
// element
static MLine *createHighOrderLine(const MEdge &edge, MElement *parentElement)
{
  MEdgeN hoEdge = parentElement->getHighOrderEdge(edge);
  std::size_t numVertices = hoEdge.getNumVertices();

  if(numVertices == 2) {
    return new MLine(hoEdge.getVertex(0), hoEdge.getVertex(1));
  }
  else if(numVertices == 3) {
    return new MLine3(hoEdge.getVertex(0), hoEdge.getVertex(1),
                      hoEdge.getVertex(2));
  }
  else {
    std::vector<MVertex *> vertices(numVertices);
    for(std::size_t i = 0; i < numVertices; ++i)
      vertices[i] = hoEdge.getVertex(i);
    return new MLineN(vertices);
  }
}

// Helper to create a high-order triangle/quad element from a face and its
// parent element
static MElement *createHighOrderFace(const MFace &face, MElement *parentElement)
{
  MFaceN hoFace = parentElement->getHighOrderFace(face);
  std::size_t numVertices = hoFace.getNumVertices();
  int order = hoFace.getPolynomialOrder();

  std::vector<MVertex *> vertices(numVertices);
  for(std::size_t i = 0; i < numVertices; ++i)
    vertices[i] = hoFace.getVertex(i);

  if(hoFace.isTriangular()) {
    if(order == 1 || numVertices == 3) {
      return new MTriangle(vertices[0], vertices[1], vertices[2]);
    }
    else {
      return new MTriangleN(vertices, static_cast<char>(order));
    }
  }
  else {
    if(order == 1 || numVertices == 4) {
      return new MQuadrangle(vertices[0], vertices[1], vertices[2],
                             vertices[3]);
    }
    else {
      return new MQuadrangleN(vertices, static_cast<char>(order));
    }
  }
}

template <int dim>
void overlapBuildBoundaries(GModel *const model,
                            const OverlapCollection<dim> &overlaps)
{
  // Is this MEdge/MFace on an existing partitionEdge/Face ?
  auto boundaryToEntity = buildBoundaryElementToEntityDict<dim>(model);
  // What is the map of MEdge/MFace -> parent element of the overlap for each
  // **parent** entity ? It's a vector per partition, then the entry is a dict
  // Entity -> (boundary -> parentElement)
  auto boundaryElements = findBoundaryOfOverlapEntities<dim>(overlaps);

  using BoundaryMeshObject = typename EntityTraits<dim>::BoundaryMeshObject;
  using BoundaryMeshObjectHash =
    typename EntityTraits<dim>::BoundaryMeshObjectHash;
  using BoundaryMeshObjectEqual =
    typename EntityTraits<dim>::BoundaryMeshObjectEqual;

  // Map from boundary to its parent element (for high-order extraction)
  using BoundaryToElementMap =
    std::unordered_map<BoundaryMeshObject, MElement *, BoundaryMeshObjectHash,
                       BoundaryMeshObjectEqual>;

  if(boundaryElements.size() != model->getNumPartitions()) {
    Msg::Error(
      "Number of boundary elements does not match number of partitions.");
  }

  // Loop over all partitions
  for(size_t i = 0; i < boundaryElements.size(); ++i) {
    int partition = i + 1; // Partitions are 1-indexed
    for(const auto &[parent, boundaryMap] : boundaryElements[i]) {
      // Maps boundary -> parent element for inner boundaries
      BoundaryToElementMap innerboundaryMap;
      // Maps GEntity -> (boundary -> parent element) for existing boundaries
      std::unordered_map<GEntity *, BoundaryToElementMap> boundariesOfExisting;

      if(!parent) continue; // Skip null entities
      if(boundaryMap.empty()) continue; // Skip empty maps

      // Overlap bnd on partition for this parent entity
      for(const auto &[melement, parentElement] : boundaryMap) {
        auto it = boundaryToEntity.find(melement);
        if(it != boundaryToEntity.end()) {
          auto partitionEntity = it->second;
          auto parentEntity = (partitionEntity->getParentEntity());
          if(!parentEntity) { Msg::Error("No parent entity"); }

          // If it is part of the outer boundary, add it to the overlap of
          // boundary
          if(parentEntity->dim() == dim - 1) {
            boundariesOfExisting[parentEntity][melement] = parentElement;
          }
          else {
            // Element is on an interface between two subdomains. If none of the
            // subdomains are the current partition, add to inner boundary
            // (which will lead to a duplicate element) On small partitions it's
            // an edge case but this is actually critical.
            auto parts = getEntityPartition(partitionEntity);
            if(std::find(parts.begin(), parts.end(), partition) ==
               parts.end()) {
              // Msg::Warning("Interface between two other subdomains added as
              // artificial boundary.");
              innerboundaryMap[melement] = parentElement;
            }
          }
        }
        else {
          // element not on an existing entity, add to inner boundary
          innerboundaryMap[melement] = parentElement;
        }
      }

      // Create new entity for inner boundary. Has one partition and zero
      // parents
      if(!innerboundaryMap.empty()) {
        auto bnd = new typename EntityTraits<dim>::BoundaryEntity(
          model, model->getMaxElementaryNumber(dim - 1) + 1, {partition});

        // Add elements with high-order support
        if constexpr(dim == 2) {
          for(const auto &[edge, parentElement] : innerboundaryMap) {
            auto elem = createHighOrderLine(edge, parentElement);
            bnd->addLine(elem);
          }
        }
        else if constexpr(dim == 3) {
          for(const auto &[face, parentElement] : innerboundaryMap) {
            auto elem = createHighOrderFace(face, parentElement);
            if(auto tri = dynamic_cast<MTriangle *>(elem)) {
              bnd->addTriangle(tri);
            }
            else if(auto quad = dynamic_cast<MQuadrangle *>(elem)) {
              bnd->addQuadrangle(quad);
            }
            else {
              Msg::Error("Unexpected element type in 3D overlap boundary.");
              delete elem;
            }
          }
        }
        model->add(bnd);
        model->addInnerBoundary(parent, bnd);
      }

      for(const auto &[entity, bndMap] : boundariesOfExisting) {
        if(!entity) continue; // Skip null entities
        if(bndMap.empty()) continue; // Skip empty maps

        auto bnd = new typename EntityTraits<dim>::BoundaryEntity(
          model, model->getMaxElementaryNumber(dim - 1) + 1, {partition});

        // Add elements with high-order support
        if constexpr(dim == 2) {
          for(const auto &[edge, parentElement] : bndMap) {
            auto elem = createHighOrderLine(edge, parentElement);
            bnd->addLine(elem);
          }
          Msg::Info("Created overlap of boundary entity with %lu elements for "
                    "partition %d.",
                    bnd->getNumMeshElements(), partition);
        }
        else if constexpr(dim == 3) {
          for(const auto &[face, parentElement] : bndMap) {
            auto elem = createHighOrderFace(face, parentElement);
            if(auto tri = dynamic_cast<MTriangle *>(elem)) {
              bnd->addTriangle(tri);
            }
            else if(auto quad = dynamic_cast<MQuadrangle *>(elem)) {
              bnd->addQuadrangle(quad);
            }
            else {
              Msg::Error("Unexpected element type in 3D overlap boundary.");
              delete elem;
            }
          }
          Msg::Info("Created overlap of boundary entity with %lu elements for "
                    "partition %d in dimension %d.",
                    bnd->getNumMeshElements(), partition, dim);
        }
        Msg::Info("Entity %d %d is creating an overlap of %d %d", parent->dim(),
                  parent->tag(), entity->dim(), entity->tag());
        model->add(bnd);
        if constexpr(dim == 2)
          model->addOverlapOfBoundary(dynamic_cast<GEdge *>(entity), bnd,
                                      parent);
        else if constexpr(dim == 3)
          model->addOverlapOfBoundary(dynamic_cast<GFace *>(entity), bnd,
                                      parent);
      }
    }
  }
}

template void overlapBuildBoundaries<2>(GModel *const model,
                                        const OverlapCollection<2> &overlaps);
template void overlapBuildBoundaries<3>(GModel *const model,
                                        const OverlapCollection<3> &overlaps);

template <int dim>
std::unordered_map<typename EntityTraits<dim>::PartitionEntity *,
                   std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave(GModel *const model, int partition)
{
  std::unordered_map<typename EntityTraits<dim>::PartitionEntity *,
                     std::unordered_set<MElement *>>
    result;

  using overlapEntityType = typename EntityTraits<dim>::OverlapEntity;

  const auto &overlaps =
    std::get<std::vector<overlapEntityType *>>(model->getAllOverlaps());
  for(auto overlapPtr : overlaps) {
    if(overlapPtr->owningPartition() != partition) continue;
    size_t numElements = overlapPtr->getNumMeshElements();
    for(size_t i = 0; i < numElements; ++i) {
      MElement *element = overlapPtr->getMeshElement(i);
      result[overlapPtr->getCovered()].insert(element);
    }
  }

  return result;
}

template std::unordered_map<typename EntityTraits<2>::PartitionEntity *,
                            std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave<2>(GModel *const model, int partition);

template std::unordered_map<typename EntityTraits<3>::PartitionEntity *,
                            std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave<3>(GModel *const model, int partition);

template <int dim>
std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave(
  GModel *const model, int partition,
  const std::unordered_map<typename EntityTraits<dim>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities)
{
  std::unordered_map<GEntity *, std::unordered_set<MVertex *>> result;
  for(const auto &[coveredEntity, elements] : coveredEntities) {
    for(MElement *elem : elements) {
      for(size_t v = 0; v < elem->getNumVertices(); ++v) {
        MVertex *vertex = elem->getVertex(v);
        auto onWhat = vertex->onWhat();
        result[onWhat].insert(vertex);
      }
    }
  }

  // Add empty entities that are the BREP of the covered entities
  if(partition == 0) return result;

  for(const auto &[coveredEntity, _] : coveredEntities) {
    result[coveredEntity]; // This will create an empty set if not present
    auto brep = coveredEntity->boundaryEntities();
    for(auto entity : brep) {
      result[entity]; // This will create an empty set if not present
      for(auto entity2 : entity->boundaryEntities()) {
        result[entity2]; // This will create an empty set if not present
        for(auto entity3 : entity2->boundaryEntities()) {
          result[entity3]; // This will create an empty set if not present
        }
      }
    }
  }

  // FIX for embedded vertices: the BREP trick doesn't save them, so we add any
  // partitionVertex with at least one partition in what we export Otherwise the
  // node is exported on a non-existent partitionVertex and the mesh is invalid
  std::set<int> partitionsToExport;
  for(const auto &[coveredEntity, _] : coveredEntities) {
    auto parts = getEntityPartition(coveredEntity);
    for(int part : parts) partitionsToExport.insert(part);
  }
  partitionsToExport.erase(partition); // Remove own partition (full export)

  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    auto pv = dynamic_cast<partitionVertex *>(*it);
    if(!pv) continue;
    auto parts = pv->getPartitions();
    if(std::any_of(parts.begin(), parts.end(),
                   [&](int p) { return partitionsToExport.count(p) > 0; })) {
      result[pv]; // Insert empty vertex
    }
  }
  // Same for partitionEdge
  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    auto pe = dynamic_cast<partitionEdge *>(*it);
    if(!pe) continue;
    auto parts = pe->getPartitions();
    if(std::any_of(parts.begin(), parts.end(),
                   [&](int p) { return partitionsToExport.count(p) > 0; })) {
      result[pe]; // Insert empty edge
    }
  }

  return result;
}

template std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave<2>(
  GModel *const model, int partition,
  const std::unordered_map<typename EntityTraits<2>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities);
template std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave<3>(
  GModel *const model, int partition,
  const std::unordered_map<typename EntityTraits<3>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities);