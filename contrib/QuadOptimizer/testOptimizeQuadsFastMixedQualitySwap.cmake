if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 5
          -setnumber Mesh.QuadqsTargetSize 2
          -setnumber Mesh.QuadqsMinimumEdgeLength 1
          -setnumber Mesh.QuadqsMaximumEdgeLength 4
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast quality-only mixed-swap driver failed:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR
    "Expected two OptimizeQuadsFast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "1 topology changes" OR
   NOT first_summary MATCHES "bad elements 0 -> 0" OR
   NOT first_summary MATCHES "absolute violations 0 -> 0" OR
   NOT first_summary MATCHES "preferred violations 4 -> 0")
  message(FATAL_ERROR
    "The quality-only mixed T+Q swap was not accepted:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes" OR
   NOT second_summary MATCHES "bad elements 0 -> 0" OR
   NOT second_summary MATCHES "absolute violations 0 -> 0" OR
   NOT second_summary MATCHES "preferred violations 0 -> 0")
  message(FATAL_ERROR
    "The quality-only mixed T+Q result is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast fit: [^\n\r]*" fit_summaries
       "${log}")
list(LENGTH fit_summaries fit_summary_count)
if(NOT fit_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two OptimizeQuadsFast fit summaries:\n${log}")
endif()
list(GET fit_summaries 0 first_fit_summary)
list(GET fit_summaries 1 second_fit_summary)
foreach(fit_summary IN LISTS fit_summaries)
  if(NOT fit_summary MATCHES
     "sizeBad\\[below/above/invalid\\]=0/0/0")
    message(FATAL_ERROR "The mixed T+Q swap violated size bounds:\n${log}")
  endif()
endforeach()
if(NOT first_fit_summary STREQUAL second_fit_summary)
  message(FATAL_ERROR
    "The mixed T+Q size result is not a fixed point:\n${log}")
endif()

foreach(report_label IN ITEMS
    "quality"
    "specifications pass\\(preferred/total\\|absolute/total\\)"
    "quad metrics")
  string(REGEX MATCHALL "OptimizeQuadsFast ${report_label}: [^\n\r]*"
         report_lines "${log}")
  list(LENGTH report_lines report_count)
  if(NOT report_count EQUAL 2)
    message(FATAL_ERROR
      "Expected two OptimizeQuadsFast ${report_label} summaries:\n${log}")
  endif()
endforeach()
if(log MATCHES "QuadOptimizer face [0-9]+ timing\\(s\\):")
  message(FATAL_ERROR "Per-face optimizer timings leaked:\n${log}")
endif()
