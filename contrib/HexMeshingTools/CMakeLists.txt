set(HMT_SRC
    hblMain.cpp
    hblDiskTriangulation.cpp
    hblBrepMesh.cpp
    hblUtils.cpp
    hblGmshIO.cpp
    hblBuildAllHexLayer.cpp
    hblSolveAllHexLayer.cpp
    hblOptimizeGeometry.cpp
    hblBuildInteriorMesh.cpp
    hblGecode.cpp
    TetGenPredicates.cpp
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HexMeshingTools "${HMT_SRC};${HDR}")
