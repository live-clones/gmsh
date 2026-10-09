# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Tests of the hierarchical basis functions, through the public C++ API. Run
# them with "ctest -R hierarchicalBasis" in the build directory.

add_executable(hierarchicalBasisTests
  main.cpp basisTest.cpp testCounts.cpp testDerivatives.cpp testSpaces.cpp
  testTraces.cpp testConformity.cpp testApi.cpp testPeriodic.cpp
  testReference.cpp testHierarchy.cpp)
target_include_directories(hierarchicalBasisTests PRIVATE
  ${CMAKE_SOURCE_DIR}/api)
target_link_libraries(hierarchicalBasisTests shared)
# next to the shared library, for Windows
set_target_properties(hierarchicalBasisTests PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

foreach(TEST counts derivatives spaces traces conformity api periodic
             hierarchy)
  add_test(NAME hierarchicalBasis_${TEST}
           COMMAND hierarchicalBasisTests ${TEST})
endforeach()
add_test(NAME hierarchicalBasis_reference
         COMMAND hierarchicalBasisTests reference
                 ${CMAKE_CURRENT_SOURCE_DIR}/reference.txt)
