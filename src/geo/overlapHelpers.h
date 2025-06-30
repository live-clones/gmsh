// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Martin

#ifndef OVERLAP_HELPERS_H
#define OVERLAP_HELPERS_H

#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"

#include <unordered_map>
#include <unordered_set>

template <int dim>
struct OverlapHelpers {
};

template <> struct OverlapHelpers<2> {
  using PartitionEntity = partitionFace;
  using Entity = GFace;
  using BoundaryEntity = partitionEdge;
  using BoundaryMeshObject = MEdge;
  using BoundaryMeshObjectHash = MEdgeHash;
  using BoundaryMeshObjectEqual = MEdgeEqual;
};

template <> struct OverlapHelpers<3> {
  using PartitionEntity = partitionRegion;
  using Entity = GRegion;
  using BoundaryEntity = partitionFace;
  using BoundaryMeshObject = MFace;
  using BoundaryMeshObjectHash = MFaceHash;
  using BoundaryMeshObjectEqual = MFaceEqual;
};

template <int dim>
std::unordered_set<typename OverlapHelpers<dim>::BoundaryMeshObject,
                   typename OverlapHelpers<dim>::BoundaryMeshObjectHash,
                   typename OverlapHelpers<dim>::BoundaryMeshObjectEqual>
findBoundaryOfEntitiesPack(
  const std::vector<typename OverlapHelpers<dim>::PartitionEntity *> &entities)
{
    static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported. For 1d, use vertices ?");

  std::unordered_map<typename OverlapHelpers<dim>::BoundaryMeshObject, size_t,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectHash,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectEqual>
    count;

  for(const auto &entity : entities) {
    for(size_t e = 0; e < entity->getNumMeshElements(); ++e) {
      auto element = entity->getMeshElement(e);
      if constexpr(dim == 2) {
        for(int i = 0; i < element->getNumEdges(); ++i) {
          MEdge edge = element->getEdge(i);
          count[edge]++;
        }
      }
      else if constexpr(dim == 3) {
        for(int i = 0; i < element->getNumFaces(); ++i) {
          MFace face = element->getFace(i);
          count[face]++;
        }
      }
    }
  }
  std::unordered_set<typename OverlapHelpers<dim>::BoundaryMeshObject,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectHash,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectEqual>
    uniques;
  for(const auto &pair : count) {
    if(pair.second == 1) { uniques.insert(pair.first); }
  }
  return uniques;
}

template <int dim>
//std::vector<typename OverlapHelpers<dim>::PartitionEntity *>
auto
findEntitiesOnPartition(GModel *const model, int partition)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");

  std::vector<typename OverlapHelpers<dim>::PartitionEntity *> entities;
  auto containsMyPartition = [partition](const std::vector<int> &partitions) {
    return std::find(partitions.begin(), partitions.end(), partition) !=
           partitions.end();
  };

  if constexpr(dim == 2) {
    for(auto&& face : model->getFaces()) {
      auto partitionFace =
        dynamic_cast<typename OverlapHelpers<dim>::PartitionEntity *>(face);
      if(partitionFace &&
         containsMyPartition(partitionFace->getPartitions())) {
        entities.push_back(partitionFace);
      }
    }
  }
  else if constexpr(dim == 3) {
    for(auto&& region : model->getRegions()) {
      auto partitionRegion =
        dynamic_cast<typename OverlapHelpers<dim>::PartitionEntity *>(region);
      if(partitionRegion &&
         containsMyPartition(partitionRegion->getPartitions())) {
        entities.push_back(partitionRegion);
      }
    }
  }

  return entities;
}

template <int dim>
std::unordered_set<MVertex*> findVerticesInBoundarySet(
  const std::unordered_set<typename OverlapHelpers<dim>::BoundaryMeshObject> &boundarySet)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");

  std::unordered_set<MVertex*> vertices;
  for(const auto &boundary : boundarySet) {
    if constexpr(dim == 2) {
      vertices.insert(boundary.getVertex(0));
      vertices.insert(boundary.getVertex(1));
    }
    else if constexpr(dim == 3) {
      for(size_t i = 0; i < boundary.getNumVertices(); ++i) {
        vertices.insert(boundary.getVertex(i));
      }
    }
  }
  return vertices;
}

template <int dim>
auto findBoundaryForPartition(
  GModel *const model, int partition)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");

  auto entities = findEntitiesOnPartition<dim>(model, partition);
  return findBoundaryOfEntitiesPack<dim>(entities);
}

#endif