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
  message(FATAL_ERROR "OptimizeQuadsFast Q+T+T driver failed:\n${log}")
endif()

string(REGEX MATCHALL
       "Q\\+T\\+T triangle reduction: accepted=[0-9]+"
       reductions "${log}")
list(LENGTH reductions reduction_count)
if(NOT reduction_count EQUAL 2)
  message(FATAL_ERROR "Expected two Q+T+T summaries:\n${log}")
endif()
list(GET reductions 0 first_reduction)
list(GET reductions 1 second_reduction)
if(NOT first_reduction MATCHES "accepted=1")
  message(FATAL_ERROR "The Q+T+T -> Q+Q action was not accepted:\n${log}")
endif()
if(NOT second_reduction MATCHES "accepted=0")
  message(FATAL_ERROR "The Q+T+T -> Q+Q result is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two OptimizeQuadsFast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "1 topology changes")
  message(FATAL_ERROR "Expected one first-pass topology change:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes")
  message(FATAL_ERROR "Expected an idle second pass:\n${log}")
endif()
