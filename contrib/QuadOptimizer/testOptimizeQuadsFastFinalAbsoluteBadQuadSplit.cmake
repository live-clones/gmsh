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
    "OptimizeQuadsFast valid-quad preservation driver failed:\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The valid-quad preservation check failed:\n${log}")
endif()

string(REGEX MATCHALL
  "OptimizeQuadsFast quality: [^\n\r]*triangles=0 quads=1 absolutePass=0/1 validity=PASS"
  quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR
    "The valid quad was not preserved with its quality violation reported:\n${log}")
endif()

if(log MATCHES
   "QuadOptimizerV2 final split face=1 quad=[0-9]+ reason=invalid diagonal=[01]")
  message(FATAL_ERROR
    "The final repair split a physically valid quad solely for its angle:\n${log}")
endif()
if(log MATCHES
   "terminal triangle recombination: [^\n\r]*accepted=[1-9]")
  message(FATAL_ERROR
    "The preserved quad unexpectedly underwent triangle recombination:\n${log}")
endif()

string(REGEX MATCHALL
  "Q\\+T\\+T triangle reduction: accepted=0"
  strip_summaries "${log}")
list(LENGTH strip_summaries strip_summary_count)
if(NOT strip_summary_count EQUAL 2 OR log MATCHES
   "half-edge rule triangle_quad_strip_reduce accepted=[1-9]")
  message(FATAL_ERROR
    "The fixed quad unexpectedly underwent triangle-strip reduction:\n${log}")
endif()
