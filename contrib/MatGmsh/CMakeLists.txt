set(SRC MatPipeline.cpp MatMesh.cpp MatCadPatches.cpp MatExtension.cpp MatBranchPlane.cpp
    MatMidSurfaceModel.cpp MatPermas.cpp)
file(GLOB CORE_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} core/*.cpp)
file(GLOB CORE_HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} core/*.h)
list(APPEND SRC ${CORE_SRC} ${CORE_HDR} MatPipeline.h MatPermas.h cadSurfacePatchAnalyzer.h)
if(HAVE_PLUGINS AND HAVE_POST)
  list(APPEND SRC MatGmshPlugin.cpp MatGmshPlugin.h)
endif()
append_gmsh_src(contrib/MatGmsh "${SRC}")
