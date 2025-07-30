// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Martin

#ifndef OVERLAP_ENTITIES_H
#define OVERLAP_ENTITIES_H

#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"
#include "SBoundingBox3d.h"

#include <unordered_map>
#include <unordered_set>

/*
  Overlap entities
 */

class overlapFace : public discreteFace {
private:
  partitionFace *_covered = nullptr;
  int _partition;

public:
  overlapFace(GModel *model, partitionFace *covered, int partition)
    : discreteFace(model, model->getMaxElementaryNumber(2) + 1),
      _covered(covered), _partition(partition)
  {
    Msg::Info("Creating overlapFace for partition %d covering face with tag %d",
              _partition, this->tag());
  }

  virtual GeomType geomType() const override { return OverlapSurface; }
  int owningPartition() const { return _partition; }
  partitionFace *getCovered() const
  {
    if(!_covered) Msg::Error("No covered entity");
    return _covered;
  }

  virtual ~overlapFace() { deleteMesh(); }
  virtual void deleteMesh() override
  {
    // Do not free elements, they are owned by the partitioned entities
    this->triangles.clear();
    this->quadrangles.clear();
    this->polygons.clear();
  }
};

class overlapRegion : public discreteRegion {
private:
  partitionRegion *_covered;
  int _partition;

public:
  overlapRegion(GModel *model, partitionRegion *covered, int partition)
    : discreteRegion(model, model->getMaxElementaryNumber(3) + 1),
      _covered(covered), _partition(partition)
  {
  }

  virtual GeomType geomType() const override { return OverlapVolume; }
  int owningPartition() const { return _partition; }
  partitionRegion *getCovered() const { return _covered; }

  virtual ~overlapRegion() { deleteMesh(); }
  virtual void deleteMesh() override
  {
    // Do not free elements, they are owned by the partitioned entities
    this->tetrahedra.clear();
    this->hexahedra.clear();
    this->prisms.clear();
    this->pyramids.clear();
    this->trihedra.clear();
    this->polyhedra.clear();
  }
};

/**
 * Traits
 */

template <int dim> struct OverlapHelpers {};

template <> struct OverlapHelpers<0> {
  using PartitionEntity = partitionVertex;
  using Entity = GVertex;
};

template <> struct OverlapHelpers<1> {
  using PartitionEntity = partitionEdge;
  using Entity = GEdge;
};

template <> struct OverlapHelpers<2> {
  using PartitionEntity = partitionFace;
  using Entity = GFace;
  using BoundaryEntity = partitionEdge;
  using BoundaryMeshObject = MEdge;
  using BoundaryMeshObjectHash = MEdgeHash;
  using BoundaryMeshObjectEqual = MEdgeEqual;
  using OverlapEntity = overlapFace;
};

template <> struct OverlapHelpers<3> {
  using PartitionEntity = partitionRegion;
  using Entity = GRegion;
  using BoundaryEntity = partitionFace;
  using BoundaryMeshObject = MFace;
  using BoundaryMeshObjectHash = MFaceHash;
  using BoundaryMeshObjectEqual = MFaceEqual;
  using OverlapEntity = overlapRegion;
};

/**
 * Minor helpers
 */
// For all partitions (vector entry), collections of all entities-subset to save
// pairs.
template <int dim>
using OverlapCollection = std::vector<
  std::unordered_map<typename OverlapHelpers<dim>::PartitionEntity *,
                     std::unordered_set<MElement *>>>;

template <int dim>
using OveralBoundariesMesh = std::vector<std::unordered_map<
  typename OverlapHelpers<dim>::Entity *,
  std::unordered_set<typename OverlapHelpers<dim>::BoundaryMeshObject,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectHash,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectEqual>>>;

template <int dim>
using BoundaryToPartitionEntity =
  std::unordered_map<typename OverlapHelpers<dim>::BoundaryMeshObject,
                     typename OverlapHelpers<dim>::BoundaryEntity *,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectHash,
                     typename OverlapHelpers<dim>::BoundaryMeshObjectEqual>;

// Small util. Convert to partitionFace or partionRegion semi-statically
template <int dim>
typename OverlapHelpers<dim>::PartitionEntity *cast(GEntity *e)
{
  static_assert(dim == 2 || dim == 3, "Only dim=2 and dim=3 are supported.");
  return dynamic_cast<typename OverlapHelpers<dim>::PartitionEntity *>(e);
}

inline std::vector<int> getEntityPartition(GEntity *entity)
{
  if(!entity) Msg::Error("getEntityPartition: entity is null.");
  auto pv = dynamic_cast<partitionVertex *>(entity);
  if(pv) { return pv->getPartitions(); }
  auto pe = dynamic_cast<partitionEdge *>(entity);
  if(pe) { return pe->getPartitions(); }
  auto pf = dynamic_cast<partitionFace *>(entity);
  if(pf) { return pf->getPartitions(); }
  auto pr = dynamic_cast<partitionRegion *>(entity);
  if(pr) { return pr->getPartitions(); }
  Msg::Error("getEntityPartition: entity is not a partitioned entity.");
  return {};
}

#endif // OVERLAP_ENTITIES_H