if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -setnumber Mesh.QuadqsTargetSize 4
          -setnumber Mesh.QuadqsMinimumEdgeLength 2
          -setnumber Mesh.QuadqsMaximumEdgeLength 8
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "OptimizeQuadsFast T+T swap driver failed:\n${log}")
endif()

string(REGEX MATCHALL
       "triangle_triangle_swap: visited=[0-9]+ accepted=[0-9]+"
       swaps "${log}")
list(LENGTH swaps swap_count)
if(NOT swap_count EQUAL 2)
  message(FATAL_ERROR "Expected two T+T swap summaries:\n${log}")
endif()
list(GET swaps 0 first_swap)
list(GET swaps 1 second_swap)
if(NOT first_swap MATCHES "accepted=1")
  message(FATAL_ERROR "The improving T+T diagonal was not selected:\n${log}")
endif()
if(NOT second_swap MATCHES "accepted=0")
  message(FATAL_ERROR "The T+T diagonal swap is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL
       "dihedral=[0-9.eE+-]+->[0-9.eE+-]+"
       accepted "${log}")
list(LENGTH accepted accepted_count)
if(NOT accepted_count EQUAL 1)
  message(FATAL_ERROR "Expected one strict dihedral improvement:\n${log}")
endif()

# The acceptance trace must expose the additive affected-edge state potential,
# not only the new/old shared diagonal angle. External T/T neighbors are absent
# from this minimal fixture, but this still exercises the common support scorer
# and protects its integration in the transaction ordering.
string(REGEX MATCHALL
       "affectedPenalty=[0-9.eE+-]+->[0-9.eE+-]+"
       affected_penalties "${log}")
list(LENGTH affected_penalties affected_penalty_count)
if(NOT affected_penalty_count EQUAL 1)
  message(FATAL_ERROR
    "Expected one affected-edge T/T penalty improvement:\n${log}")
endif()

# The replacement diagonal is about 3.33 long. Raising h/2 to 4 must reject
# exactly the same geometrically improving flip: this explicitly exercises the
# hard lower-size gate instead of relying only on production Doghouse meshes.
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -setnumber Mesh.QuadqsTargetSize 4
          -setnumber Mesh.QuadqsMinimumEdgeLength 4
          -setnumber Mesh.QuadqsMaximumEdgeLength 8
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE rejected_status
  OUTPUT_VARIABLE rejected_output
  ERROR_VARIABLE rejected_error)
set(rejected_log "${rejected_output}${rejected_error}")
if(NOT rejected_status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast size-rejected T+T driver failed:\n${rejected_log}")
endif()
string(REGEX MATCHALL
       "triangle_triangle_swap: visited=[0-9]+ accepted=0"
       rejected_swaps "${rejected_log}")
list(LENGTH rejected_swaps rejected_swap_count)
if(NOT rejected_swap_count EQUAL 2)
  message(FATAL_ERROR
    "The T+T flip with a diagonal shorter than h/2 was not rejected:\n${rejected_log}")
endif()
