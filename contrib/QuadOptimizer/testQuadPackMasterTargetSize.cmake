if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_OUTPUT)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_OUTPUT are required")
endif()

execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}" -2 -algo pack
          -setnumber Mesh.QuadqsTargetSize 0.03
          -nopopup -v 5 -o "${TEST_OUTPUT}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "PACK master-target driver failed:\n${log}")
endif()
if(NOT log MATCHES
   "PACK master target size: h=0.03, admissible edges=\\[0.015,0.06\\], 3D packing forced")
  message(FATAL_ERROR "The target did not derive the edge bounds:\n${log}")
endif()
if(NOT log MATCHES "Size map statistics: min=0.030, max=0.030")
  message(FATAL_ERROR "The target did not drive mesh generation:\n${log}")
endif()
if(NOT log MATCHES "Blossom recombination completed")
  message(FATAL_ERROR "PACK did not implicitly recombine the surface:\n${log}")
endif()
if(NOT log MATCHES "Optimizing mesh \\(OptimizeQuadsFast\\)")
  message(FATAL_ERROR "PACK did not run the Fast cleanup:\n${log}")
endif()
if(NOT log MATCHES
   "QuadOptimizer size: target=0.03 minimum=0.015 maximum=0.06")
  message(FATAL_ERROR "Fast cleanup did not receive the derived sizes:\n${log}")
endif()
