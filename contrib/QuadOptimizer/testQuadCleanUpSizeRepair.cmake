if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
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
  message(FATAL_ERROR "QuadCleanUp size-repair driver failed:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two QuadCleanUp summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "0 topology changes" OR
   NOT first_summary MATCHES "preferred violations 2 -> 0")
  message(FATAL_ERROR "The guarded size smoothing was not applied:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes" OR
   NOT second_summary MATCHES "preferred violations 0 -> 0")
  message(FATAL_ERROR "The second size repair was not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp fit: [^\n\r]*" fit_summaries "${log}")
list(LENGTH fit_summaries fit_summary_count)
if(NOT fit_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two QuadCleanUp fit summaries:\n${log}")
endif()
list(GET fit_summaries 0 first_fit_summary)
list(GET fit_summaries 1 second_fit_summary)
foreach(fit_summary IN LISTS fit_summaries)
  if(NOT fit_summary MATCHES
     "sizeBad\\[below/above/invalid\\]=0/0/0")
    message(FATAL_ERROR "The short edge was not repaired:\n${log}")
  endif()
endforeach()
if(NOT first_fit_summary STREQUAL second_fit_summary)
  message(FATAL_ERROR "The repaired sizes were not stable:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp fixed point: [^\n\r]*"
       fixed_points "${log}")
list(LENGTH fixed_points fixed_point_count)
if(NOT fixed_point_count EQUAL 2)
  message(FATAL_ERROR "Expected two QuadCleanUp fixed-point reports:\n${log}")
endif()
list(GET fixed_points 0 first_fixed_point)
list(GET fixed_points 1 second_fixed_point)
if(NOT first_fixed_point MATCHES "smoothed=1" OR
   NOT second_fixed_point MATCHES "smoothed=0")
  message(FATAL_ERROR
    "The guarded size smoothing did not reach a fixed point:\n${log}")
endif()
