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
  message(FATAL_ERROR "QuadCleanUp fixed-point driver failed:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two QuadCleanUp summaries, got ${summary_count}:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "1 topology changes" OR
   NOT first_summary MATCHES "bad elements 2 -> 0")
  message(FATAL_ERROR "The first CleanUp did not perform the expected fill_2:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes" OR
   NOT second_summary MATCHES "bad elements 0 -> 0")
  message(FATAL_ERROR "The second CleanUp was not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "QuadOptimizer size: [^\n\r]*" size_audits "${log}")
list(LENGTH size_audits size_audit_count)
if(NOT size_audit_count EQUAL 2)
  message(FATAL_ERROR "Expected two size audits, got ${size_audit_count}:\n${log}")
endif()
foreach(size_audit IN LISTS size_audits)
  foreach(field IN ITEMS initialBelow initialAbove initialInvalid
                         finalBelow finalAbove finalInvalid)
    if(NOT size_audit MATCHES "${field}=0")
      message(FATAL_ERROR "Size requirement ${field}=0 is missing:\n${log}")
    endif()
  endforeach()
endforeach()
