# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  alphaShapes.cpp
  Generator.cpp
  meshGEdge.cpp
    meshGEdgeExtruded.cpp
  meshGFace.cpp
  meshGFacePack.cpp
    meshGFaceTransfinite.cpp meshGFaceExtruded.cpp
    meshGFaceBamg.cpp meshGFaceBDS.cpp meshGFaceDelaunayInsertion.cpp
    meshGFaceOptimize.cpp
    meshGFaceBipartiteLabelling.cpp
  meshGRegion.cpp
    meshGRegionBoundaryRecovery.cpp
    meshGRegionHxt.cpp meshGRegionNetgen.cpp
    meshGRegionDelaunayInsertion.cpp meshGRegionTransfinite.cpp
    meshGRegionExtruded.cpp meshGRegionCarveHole.cpp
    meshGRegionLocalMeshMod.cpp meshGRegionMMG.cpp
  meshGRegionBoundaryLayer.cpp
  meshRelocateVertex.cpp
  meshRenumber.cpp
  meshTriangulation.cpp
  meshMetric.cpp
  meshUntangle.cpp
  meshMesquite.cpp
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
  meshQuadQuasiStructured.cpp
  meshOctreeLibOL.cpp
  meshCombine3D.cpp
 )

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/mesh "${SRC};${HDR}")
