set(QUAD_OPTIMIZER_SRC
  halfEdge.cpp
  quadQuality.cpp
  smallCavityOptimizer.cpp
  smallCavityOptimizerV2.cpp
  smallCavityWinslow.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadOptimizer "${QUAD_OPTIMIZER_SRC};${HDR}")

if(ENABLE_TESTS AND NOT DISABLE_GMSH_TESTS)
  add_executable(testSmartLaplacian testSmartLaplacian.cpp)
  target_include_directories(testSmartLaplacian PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})
  add_executable(testHalfEdgeRewriteCatalog
    testHalfEdgeRewriteCatalog.cpp)
  target_include_directories(testHalfEdgeRewriteCatalog PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})
  add_executable(testQuadQualityLedger testQuadQualityLedger.cpp)
  target_include_directories(testQuadQualityLedger PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_BINARY_DIR}/src/common)
  add_executable(testSmallCavityWinslowNormalization
    testSmallCavityWinslowNormalization.cpp smallCavityWinslow.cpp
    testWinslowRuntime.cpp
    ${CMAKE_SOURCE_DIR}/contrib/BoundaryLayers/gmshLBFGS.cpp)
  # Exercise the scalar production solver without loading the Gmsh UI or
  # optional BLAS runtime. Full optimizer contracts cover the configured build.
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/winslow-test)
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/winslow-test/GmshConfig.h
    "// Scalar configuration for numerical Winslow contracts.\n")
  target_include_directories(testSmallCavityWinslowNormalization BEFORE PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/winslow-test
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/contrib/BoundaryLayers ${CMAKE_BINARY_DIR}/src/common)
  add_executable(testSurfaceWinslow3D testSurfaceWinslow3D.cpp
    testWinslowRuntime.cpp
    ${CMAKE_SOURCE_DIR}/contrib/BoundaryLayers/gmshLBFGS.cpp)
  target_include_directories(testSurfaceWinslow3D BEFORE PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/winslow-test
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/contrib/BoundaryLayers ${CMAKE_BINARY_DIR}/src/common)
endif()
