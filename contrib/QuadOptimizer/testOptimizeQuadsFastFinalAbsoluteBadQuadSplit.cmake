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
    "OptimizeQuadsFast absolute-quality split driver failed:\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The absolute-quality split check failed:\n${log}")
endif()

string(REGEX MATCHALL
  "OptimizeQuadsFast quality: [^\n\r]*triangles=2 quads=0 absolutePass=2/2 validity=PASS"
  quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR
    "The unacceptable quad was not replaced by two admissible triangles:\n${log}")
endif()

string(REGEX MATCHALL
  "QuadOptimizerV2 final split face=1 quad=[0-9]+ reason=absolute-quality diagonal=1"
  splits "${log}")
list(LENGTH splits split_count)
if(NOT split_count EQUAL 1)
  message(FATAL_ERROR
    "The final repair did not select the admissible diagonal exactly once:\n${log}")
endif()

if(log MATCHES
   "terminal triangle recombination: [^\n\r]*accepted=[1-9]")
  message(FATAL_ERROR
    "The unacceptable quad was recreated by triangle recombination:\n${log}")
endif()

string(REGEX MATCHALL
  "Q\\+T\\+T triangle reduction: accepted=0"
  strip_summaries "${log}")
list(LENGTH strip_summaries strip_summary_count)
if(NOT strip_summary_count EQUAL 2 OR log MATCHES
   "half-edge rule triangle_quad_strip_reduce accepted=[1-9]")
  message(FATAL_ERROR
    "The rejected quad unexpectedly underwent triangle-strip reduction:\n${log}")
endif()
