if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -setnumber Mesh.PackTargetSize 4
          -setnumber Mesh.OptimizeQuadsMinimumEdgeLength 2
          -setnumber Mesh.OptimizeQuadsMaximumEdgeLength 8
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
# V2 exposes QQ/QT swaps and acceptable TT merges. It deliberately has no
# standalone dihedral-only TT flip. These fixed cells must remain valid and
# unchanged under both size settings, including a second invocation.
if(NOT first_swap MATCHES "visited=0 accepted=0" OR
   NOT second_swap MATCHES "visited=0 accepted=0")
  message(FATAL_ERROR "V2 unexpectedly ran the legacy dihedral-only TT pass:\n${log}")
endif()
string(REGEX MATCHALL
  "OptimizeQuadsFast quality: [^\n\r]*triangles=2 quads=1 [^\n\r]*validity=PASS"
  quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2 OR log MATCHES
   "OptimizeQuadsFast: [^\n\r]*[1-9][0-9]* topology changes")
  message(FATAL_ERROR "V2 changed the protected fixed TT/Q patch:\n${log}")
endif()

# Raising the lower length limit must not admit a replacement either.
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -setnumber Mesh.PackTargetSize 4
          -setnumber Mesh.OptimizeQuadsMinimumEdgeLength 4
          -setnumber Mesh.OptimizeQuadsMaximumEdgeLength 8
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
