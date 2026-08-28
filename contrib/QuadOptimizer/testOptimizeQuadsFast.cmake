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
  message(FATAL_ERROR "OptimizeQuadsFast driver failed:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR
    "Expected two OptimizeQuadsFast summaries, got ${summary_count}:\n${log}")
endif()

list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES
     "^OptimizeQuadsFast: 1 faces, 1 topology changes, 0 pillows \\(0 quads\\)," OR
   NOT first_summary MATCHES "bad elements 2 -> 0" OR
   NOT first_summary MATCHES "absolute violations 4 -> 0")
  message(FATAL_ERROR "The first Fast cleanup did not repair the mesh:\n${log}")
endif()
if(NOT second_summary MATCHES
     "^OptimizeQuadsFast: 1 faces, 0 topology changes, 0 pillows \\(0 quads\\)," OR
   NOT second_summary MATCHES "bad elements 0 -> 0" OR
   NOT second_summary MATCHES "absolute violations 0 -> 0")
  message(FATAL_ERROR "The second Fast cleanup was not a fixed point:\n${log}")
endif()
