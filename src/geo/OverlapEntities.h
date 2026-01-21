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

#include "EntityTraits.h"

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
 * Minor helpers
 */
// For all partitions (vector entry), collections of all entities-subset to save
// pairs.
template <int dim>
using OverlapCollection =
  std::vector<std::unordered_map<typename EntityTraits<dim>::PartitionEntity *,
                                 std::unordered_set<MElement *>>>;

// For each partition, we keep a map from volume entity to face/edges with their
// parent element. Parent allows a reconstruction of a high-order boundary
// element.
template <int dim>
using OveralBoundariesMesh = std::vector<std::unordered_map<
  typename EntityTraits<dim>::Entity *,
  std::unordered_map<typename EntityTraits<dim>::BoundaryMeshObject, MElement *,
                     typename EntityTraits<dim>::BoundaryMeshObjectHash,
                     typename EntityTraits<dim>::BoundaryMeshObjectEqual>>>;

template <int dim>
using BoundaryToPartitionEntity =
  std::unordered_map<typename EntityTraits<dim>::BoundaryMeshObject,
                     typename EntityTraits<dim>::BoundaryEntity *,
                     typename EntityTraits<dim>::BoundaryMeshObjectHash,
                     typename EntityTraits<dim>::BoundaryMeshObjectEqual>;

inline std::vector<int> getEntityPartition(GEntity *entity,
                                           bool failOnNull = true)
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
  if(failOnNull)
    Msg::Error("getEntityPartition: entity is not a partitioned entity.");
  return {};
}

#endif // OVERLAP_ENTITIES_H