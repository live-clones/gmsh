set(QUAD_OPTIMIZER_SRC
  quadQuality.cpp
  smallCavityOptimizer.cpp
  smallCavityWinslow.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadOptimizer "${QUAD_OPTIMIZER_SRC};${HDR}")

add_executable(gmshQuadOptimizer quadOptimizerMain.cpp)
target_include_directories(gmshQuadOptimizer PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/api
  ${CMAKE_SOURCE_DIR}/src/common
  ${CMAKE_SOURCE_DIR}/src/geo
  ${CMAKE_SOURCE_DIR}/src/mesh
  ${CMAKE_SOURCE_DIR}/src/numeric
  ${CMAKE_BINARY_DIR}/src/common
)
target_link_libraries(gmshQuadOptimizer PRIVATE shared)
install(TARGETS gmshQuadOptimizer DESTINATION ${CMAKE_INSTALL_BINDIR})

if(ENABLE_TESTS)
  add_executable(testQuadQuality testQuadQuality.cpp)
  target_include_directories(testQuadQuality PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_BINARY_DIR}/src/common
  )
  target_link_libraries(testQuadQuality PRIVATE shared)

  add_executable(testSmallCavityWinslow testSmallCavityWinslow.cpp)
  target_include_directories(testSmallCavityWinslow PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_BINARY_DIR}/src/common
  )
  target_link_libraries(testSmallCavityWinslow PRIVATE shared)
endif()
