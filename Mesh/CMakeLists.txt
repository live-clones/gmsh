# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  Generator.cpp
  meshGEdge.cpp
    meshGEdgeExtruded.cpp
  meshGFace.cpp
    meshGFaceTransfinite.cpp meshGFaceExtruded.cpp
    meshGFaceBamg.cpp meshGFaceBDS.cpp meshGFaceDelaunayInsertion.cpp
    meshGFaceOptimize.cpp
  meshGRegion.cpp
    meshGRegionBoundaryRecovery.cpp
    meshGRegionHxt.cpp meshGRegionNetgen.cpp
    meshGRegionDelaunayInsertion.cpp meshGRegionTransfinite.cpp
    meshGRegionExtruded.cpp meshGRegionCarveHole.cpp
    meshGRegionLocalMeshMod.cpp meshGRegionMMG.cpp
  meshGRegionBoundaryLayer.cpp
  meshRelocateVertex.cpp
  meshTriangulation.cpp
  meshMetric.cpp
  BackgroundMesh.cpp BackgroundMeshTools.cpp
  qualityMeasures.cpp qualityMeasuresJacobian.cpp
  BoundaryLayers.cpp
  BDS.cpp
  HighOrder.cpp
  meshPartition.cpp
  meshRefine.cpp
  delaunay3d.cpp
  DivideAndConquer.cpp
  Field.cpp
  filterElements.cpp
  gmshCrossFields.cpp
  automaticMeshSizeField.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(Mesh "${SRC};${HDR}")
