# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC
   meshGRegionBoundaryRecovery.cpp
   delaunay3d.cpp
   delaunay_refinement.cpp
   Generator.cpp
    meshGEdge.cpp 
      meshGEdgeExtruded.cpp
    meshGFace.cpp 
    meshGFaceElliptic.cpp
      meshGFaceTransfinite.cpp meshGFaceExtruded.cpp 
      meshGFaceBamg.cpp meshGFaceBDS.cpp meshGFaceDelaunayInsertion.cpp 
      meshGFaceLloyd.cpp meshGFaceOptimize.cpp 
     meshGFaceQuadrilateralize.cpp 
    meshGRegion.cpp 
    meshDiscreteRegion.cpp 
      meshGRegionDelaunayInsertion.cpp meshGRegionTransfinite.cpp 
      meshGRegionExtruded.cpp  meshGRegionCarveHole.cpp 
      meshGRegionLocalMeshMod.cpp meshGRegionMMG3D.cpp
meshGRegionRelocateVertex.cpp
    meshMetric.cpp
    BackgroundMeshTools.cpp 
    BackgroundMesh.cpp 
    BGMBase.cpp 
    BackgroundMesh2D.cpp 
    BackgroundMesh3D.cpp 
    BackgroundMeshManager.cpp 
    pointInsertionRTreeTools.cpp 
    pointInsertion.cpp 
    qualityMeasures.cpp qualityMeasuresJacobian.cpp
    BoundaryLayers.cpp 
    BDS.cpp 
    HighOrder.cpp 
    meshPartition.cpp
    meshRefine.cpp
    multiscalePartition.cpp
    QuadTriUtils.cpp
      QuadTriExtruded2D.cpp QuadTriExtruded3D.cpp QuadTriTransfinite3D.cpp
    simple3D.cpp ThinLayer.cpp
  DivideAndConquer.cpp
    Voronoi3D.cpp
    Levy3D.cpp
    periodical.cpp
    directions3D.cpp
    filterElements.cpp
    yamakawa.cpp
    Field.cpp
    CenterlineField.cpp
    surfaceFiller.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Mesh "${SRC};${HDR}")
