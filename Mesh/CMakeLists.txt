# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Generator.cpp
  Field.cpp
    meshGEdge.cpp 
      meshGEdgeExtruded.cpp
    meshGFace.cpp 
      meshGFaceTransfinite.cpp meshGFaceExtruded.cpp 
      meshGFaceBamg.cpp meshGFaceBDS.cpp meshGFaceDelaunayInsertion.cpp 
      meshGFaceLloyd.cpp meshGFaceOptimize.cpp 
      meshGFaceQuadrilateralize.cpp meshGFaceBoundaryLayer.cpp 
    meshGRegion.cpp 
      meshGRegionDelaunayInsertion.cpp meshGRegionTransfinite.cpp 
      meshGRegionExtruded.cpp  meshGRegionCarveHole.cpp 
      meshGRegionLocalMeshMod.cpp
    BackgroundMesh.cpp 
    qualityMeasures.cpp 
    BoundaryLayers.cpp 
    BDS.cpp 
    HighOrder.cpp 
      highOrderSmoother.cpp 
    meshPartition.cpp 
    meshRefine.cpp
    multiscalePartition.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Mesh "${SRC};${HDR}")
