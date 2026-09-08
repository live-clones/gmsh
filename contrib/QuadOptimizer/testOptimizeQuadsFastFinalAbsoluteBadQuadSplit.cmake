if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast final absolute split driver failed:\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The final absolute split failed:\n${log}")
endif()

string(REGEX MATCHALL
  "OptimizeQuadsFast quality: [^\n\r]*triangles=2 quads=0 [^\n\r]*validity=PASS"
  quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR
    "The final fallback did not leave a stable two-triangle mesh:\n${log}")
endif()

if(NOT log MATCHES
   "QuadOptimizerV2 final split face=1 quad=[0-9]+ reason=invalid diagonal=[01]")
  message(FATAL_ERROR
    "The V2 final invalid-quad split was not accepted:\n${log}")
endif()
if(log MATCHES
   "terminal triangle recombination: [^\n\r]*accepted=[1-9]")
  message(FATAL_ERROR
    "A later operation recreated the unacceptable quadrangle:\n${log}")
endif()

string(REGEX MATCHALL
  "Q\\+T\\+T triangle reduction: accepted=0"
  strip_summaries "${log}")
list(LENGTH strip_summaries strip_summary_count)
if(NOT strip_summary_count EQUAL 2 OR log MATCHES
   "half-edge rule triangle_quad_strip_reduce accepted=[1-9]")
  message(FATAL_ERROR
    "The second invocation recombined the terminal triangle pair:\n${log}")
endif()
