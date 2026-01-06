// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MFaceHash.h"
#include "MEdgeHash.h"

template <int dim> struct EntityTraits {};

class GVertex;
class GEdge;
class GFace;
class GRegion;
class partitionVertex;
class partitionEdge;
class partitionFace;
class partitionRegion;
class overlapFace;
class overlapRegion;

template <> struct EntityTraits<0> {
  using PartitionEntity = partitionVertex;
  using Entity = GVertex;
};

template <> struct EntityTraits<1> {
  using PartitionEntity = partitionEdge;
  using Entity = GEdge;
};

template <> struct EntityTraits<2> {
  using PartitionEntity = partitionFace;
  using Entity = GFace;
  using BoundaryEntity = partitionEdge;
  using BoundaryMeshObject = MEdge;
  using BoundaryMeshObjectHash = MEdgeHash;
  using BoundaryMeshObjectEqual = MEdgeEqual;
  using OverlapEntity = overlapFace;
};

template <> struct EntityTraits<3> {
  using PartitionEntity = partitionRegion;
  using Entity = GRegion;
  using BoundaryEntity = partitionFace;
  using BoundaryMeshObject = MFace;
  using BoundaryMeshObjectHash = MFaceHash;
  using BoundaryMeshObjectEqual = MFaceEqual;
  using OverlapEntity = overlapRegion;
};
