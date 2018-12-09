# Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues

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
    meshGRegionExtruded.cpp  meshGRegionCarveHole.cpp
    meshGRegionLocalMeshMod.cpp meshGRegionMMG3D.cpp
    meshGRegionRelocateVertex.cpp
  meshDiscreteRegion.cpp
  meshMetric.cpp
  BackgroundMeshTools.cpp
    BackgroundMesh.cpp BGMBase.cpp
    BackgroundMesh2D.cpp
    BackgroundMesh3D.cpp
    BackgroundMeshManager.cpp
  pointInsertionRTreeTools.cpp pointInsertion.cpp
  qualityMeasures.cpp qualityMeasuresJacobian.cpp
  BoundaryLayers.cpp
    BDS.cpp
    HighOrder.cpp
    meshPartition.cpp
    meshRefine.cpp
    QuadTriUtils.cpp
      QuadTriExtruded2D.cpp QuadTriExtruded3D.cpp QuadTriTransfinite3D.cpp
  delaunay3d.cpp
  simple3D.cpp ThinLayer.cpp
  DivideAndConquer.cpp
  directions3D.cpp
  filterElements.cpp
  yamakawa.cpp
  Field.cpp
  surfaceFiller.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(Mesh "${SRC};${HDR}")
