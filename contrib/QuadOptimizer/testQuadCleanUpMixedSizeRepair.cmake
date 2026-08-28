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
  message(FATAL_ERROR "QuadCleanUp mixed-size driver failed:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two QuadCleanUp summaries:\n${log}")
endif()
foreach(summary IN LISTS summaries)
  if(NOT summary MATCHES "0 topology changes")
    message(FATAL_ERROR "Mixed size repair changed topology:\n${log}")
  endif()
endforeach()

string(REGEX MATCHALL "QuadCleanUp fixed point: [^\n\r]*" fixed_points
       "${log}")
list(LENGTH fixed_points fixed_point_count)
if(NOT fixed_point_count EQUAL 2)
  message(FATAL_ERROR "Expected two fixed-point summaries:\n${log}")
endif()
list(GET fixed_points 0 first_fixed_point)
list(GET fixed_points 1 second_fixed_point)
if(NOT first_fixed_point MATCHES "smoothed=[1-9][0-9]*")
  message(FATAL_ERROR "The mixed one-ring was not smoothed:\n${log}")
endif()
if(NOT second_fixed_point MATCHES "smoothed=0")
  message(FATAL_ERROR "The mixed one-ring was not a fixed point:\n${log}")
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
  message(FATAL_ERROR "The mixed short edge was not repaired:\n${log}")
endif()
if(NOT second_size MATCHES "initialBelow=0" OR
   NOT second_size MATCHES "finalBelow=0" OR
   NOT second_size MATCHES "finalAbove=0" OR
   NOT second_size MATCHES "finalInvalid=0")
  message(FATAL_ERROR "The mixed repaired sizes were not stable:\n${log}")
endif()
