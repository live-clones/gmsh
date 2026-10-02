if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
foreach(strip_length IN ITEMS 0 2 3 4)
  execute_process(
    COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
            -setnumber StripLength "${strip_length}"
            -parse_and_exit -nopopup -v 5
    WORKING_DIRECTORY "${TEST_DIRECTORY}"
    RESULT_VARIABLE status
    OUTPUT_VARIABLE output
    ERROR_VARIABLE error)
  set(log "${output}${error}")
  if(NOT status EQUAL 0)
    message(FATAL_ERROR
      "OptimizeQuadsFast T-Q^${strip_length}-T driver failed:\n${log}")
  endif()

  string(REGEX MATCHALL
         "Q\\+T\\+T triangle reduction: accepted=[0-9]+"
         reductions "${log}")
  list(LENGTH reductions reduction_count)
  if(NOT reduction_count EQUAL 2)
    message(FATAL_ERROR
      "Expected two strip-reduction summaries for k=${strip_length}:\n${log}")
  endif()
  list(GET reductions 0 first_reduction)
  list(GET reductions 1 second_reduction)
  if(NOT first_reduction MATCHES "accepted=1")
    message(FATAL_ERROR
      "T-Q^${strip_length}-T was not reduced by the strip rule:\n${log}")
  endif()
  if(NOT second_reduction MATCHES "accepted=0")
    message(FATAL_ERROR
      "T-Q^${strip_length}-T is not a fixed point:\n${log}")
  endif()

  string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
  list(LENGTH summaries summary_count)
  if(NOT summary_count EQUAL 2)
    message(FATAL_ERROR
      "Expected two optimizer summaries for k=${strip_length}:\n${log}")
  endif()
  list(GET summaries 0 first_summary)
  list(GET summaries 1 second_summary)
  if(NOT first_summary MATCHES "[1-9][0-9]* topology changes")
    message(FATAL_ERROR
      "Expected a non-empty first pass for k=${strip_length}:\n${log}")
  endif()
  if(NOT second_summary MATCHES "0 topology changes")
    message(FATAL_ERROR
      "Expected an idle second pass for k=${strip_length}:\n${log}")
  endif()

  string(REGEX MATCHALL
         "OptimizeQuadsFast quality: [^\n\r]*triangles=0 quads=[1-9][0-9]* [^\n\r]*validity=PASS"
         quality_summaries "${log}")
  list(LENGTH quality_summaries quality_summary_count)
  if(NOT quality_summary_count EQUAL 2)
    message(FATAL_ERROR
      "Unexpected final cell counts for k=${strip_length}:\n${log}")
  endif()

  string(REGEX MATCHALL
         "terminal triangle recombination: [^\n\r]*accepted=0"
         terminal_recombinations "${log}")
  list(LENGTH terminal_recombinations terminal_recombination_count)
  if(NOT terminal_recombination_count EQUAL 2)
    message(FATAL_ERROR
      "A terminal fallback handled k=${strip_length} instead of the catalog rule:\n${log}")
  endif()
endforeach()
