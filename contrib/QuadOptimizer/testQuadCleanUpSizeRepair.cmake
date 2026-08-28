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

string(REGEX MATCHALL "QuadOptimizer size: [^\n\r]*" size_audits "${log}")
list(LENGTH size_audits size_audit_count)
if(NOT size_audit_count EQUAL 2)
  message(FATAL_ERROR "Expected two size audits:\n${log}")
endif()
list(GET size_audits 0 first_size)
list(GET size_audits 1 second_size)
if(NOT first_size MATCHES "initialBelow=1" OR
   NOT first_size MATCHES "finalBelow=0" OR
   NOT first_size MATCHES "finalAbove=0" OR
   NOT first_size MATCHES "finalInvalid=0")
  message(FATAL_ERROR "The short edge was not repaired:\n${log}")
endif()
if(NOT second_size MATCHES "initialBelow=0" OR
   NOT second_size MATCHES "finalBelow=0" OR
   NOT second_size MATCHES "finalAbove=0" OR
   NOT second_size MATCHES "finalInvalid=0")
  message(FATAL_ERROR "The repaired sizes were not stable:\n${log}")
endif()
