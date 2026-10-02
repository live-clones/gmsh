if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -setnumber Mesh.OptimizeQuadsTargetSize 4
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
# V2 visits TT pairs for guarded CAD-driven swaps, but this patch must not
# accept a dihedral-only flip. The final quality pass must independently split
# its inadmissible quad, and a second invocation must leave the result unchanged.
if(NOT first_swap MATCHES "accepted=0$" OR
   NOT second_swap MATCHES "accepted=0$")
  message(FATAL_ERROR "V2 unexpectedly ran the legacy dihedral-only TT pass:\n${log}")
endif()
string(REGEX MATCHALL
  "OptimizeQuadsFast quality: [^\n\r]*triangles=4 quads=0 [^\n\r]*validity=PASS"
  quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "The repaired TT/Q patch did not contain four valid triangles:\n${log}")
endif()
string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES ", 1 topology changes," OR
   NOT first_summary MATCHES "bad elements 1 -> 0" OR
   NOT second_summary MATCHES ", 0 topology changes," OR
   NOT second_summary MATCHES "bad elements 0 -> 0" OR
   NOT log MATCHES "final cleanup: split\\[invalid/quality/CAD\\]=0/1/0 TTmerges=0 TTcadSwaps=0 QTswaps=0 rejectedSplits=0")
  message(FATAL_ERROR "The TT/Q patch must change only through its final quality split:\n${log}")
endif()

# Raising the lower length limit must not admit a replacement either.
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -setnumber Mesh.OptimizeQuadsTargetSize 4
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
