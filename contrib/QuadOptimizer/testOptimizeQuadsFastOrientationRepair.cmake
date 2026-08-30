if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

# Keep the fixture honest: both quads traverse the common edge 2 -> 3, but
# they otherwise form two disjoint square interiors.
file(READ "${TEST_MSH}" fixture)
if(NOT fixture MATCHES "[\n\r]13 3 2 0 1 1 2 3 4[\n\r]" OR
   NOT fixture MATCHES "[\n\r]14 3 2 0 1 2 3 6 5[\n\r]")
  message(FATAL_ERROR
    "The orientation-repair fixture no longer contains the reversed quad")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 5
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "Orientation-repair driver failed:\n${log}")
endif()
if(log MATCHES "not a regular oriented surface cell complex" OR
   log MATCHES "could not be oriented consistently")
  message(FATAL_ERROR "A repairable orientation was rejected:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "reoriented=1" OR
   NOT first_summary MATCHES "0 topology changes")
  message(FATAL_ERROR "The reversed quad was not repaired locally:\n${log}")
endif()
if(NOT second_summary MATCHES "reoriented=0" OR
   NOT second_summary MATCHES "0 topology changes")
  message(FATAL_ERROR "The repaired orientation is not stable:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two final quality summaries:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES
     "validity=PASS invalid\\[T/Q\\]=0/0 nonManifoldFaces=0")
    message(FATAL_ERROR "Orientation repair failed validity:\n${log}")
  endif()
endforeach()
