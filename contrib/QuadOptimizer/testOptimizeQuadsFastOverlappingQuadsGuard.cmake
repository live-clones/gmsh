if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

file(READ "${TEST_MSH}" fixture)
if(NOT fixture MATCHES "[\n\r]10 3 2 0 1 1 2 3 4[\n\r]" OR
   NOT fixture MATCHES "[\n\r]11 3 2 0 1 1 2 3 5[\n\r]")
  message(FATAL_ERROR
    "The overlap fixture no longer contains the two-edge quad pair")
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
if(status EQUAL 0)
  message(FATAL_ERROR "Fast accepted overlapping quads:\n${log}")
endif()
if(NOT log MATCHES
   "QuadOptimizer: face 1 is not a regular oriented surface cell complex")
  message(FATAL_ERROR
    "Fast did not diagnose the overlapping Q/Q complex (status ${status}):\n"
    "${log}")
endif()
if(log MATCHES "terminal split: [^\n\r]*split=[1-9]")
  message(FATAL_ERROR
    "Fast mutated the overlap before rejecting it:\n${log}")
endif()
