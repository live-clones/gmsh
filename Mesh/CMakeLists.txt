# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Generator.cpp
    meshGEdge.cpp 
      meshGEdgeExtruded.cpp
    meshGFace.cpp 
    meshGFaceElliptic.cpp
      meshGFaceTransfinite.cpp meshGFaceExtruded.cpp 
      meshGFaceBamg.cpp meshGFaceBDS.cpp meshGFaceDelaunayInsertion.cpp 
      meshGFaceLloyd.cpp meshGFaceOptimize.cpp 
      meshGFaceQuadrilateralize.cpp meshGFaceBoundaryLayers.cpp
    meshGRegion.cpp 
      meshGRegionDelaunayInsertion.cpp meshGRegionTransfinite.cpp 
      meshGRegionExtruded.cpp  meshGRegionCarveHole.cpp 
      meshGRegionLocalMeshMod.cpp meshGRegionMMG3D.cpp
    meshMetric.cpp
    BackgroundMesh.cpp 
    qualityMeasures.cpp 
    BoundaryLayers.cpp 
    BDS.cpp 
    HighOrder.cpp 
      highOrderTools.cpp 
    meshPartition.cpp
    meshRefine.cpp
    multiscalePartition.cpp
    QuadTriUtils.cpp
      QuadTriExtruded2D.cpp QuadTriExtruded3D.cpp QuadTriTransfinite3D.cpp
    simple3D.cpp
  DivideAndConquer.cpp
    Voronoi3D.cpp
    Levy3D.cpp
    periodical.cpp
    directions3D.cpp
    yamakawa.cpp
    Field.cpp
    CenterlineField.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Mesh "${SRC};${HDR}")
