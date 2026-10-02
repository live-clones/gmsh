if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

file(READ "${TEST_MSH}" fixture)
if(NOT fixture MATCHES "[\n\r]8 3 2 0 1 1 2 3 4[\n\r]" OR
   NOT fixture MATCHES "[\n\r]9 3 2 0 1 1 5 6 7[\n\r]")
  message(FATAL_ERROR
    "The bow-tie fixture no longer contains the two one-vertex fans")
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
  message(FATAL_ERROR
    "The bow-tie warning stopped OptimizeQuadsFast (status ${status}):\n${log}")
endif()
if(NOT log MATCHES
   "Warning *: QuadOptimizer: face 1 is not a regular oriented surface cell complex")
  message(FATAL_ERROR
    "OptimizeQuadsFast did not reject the disconnected vertex link:\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR
    "The bow-tie input warning was converted into an error:\n${log}")
endif()
if(NOT log MATCHES
   "OptimizeQuadsFast: [^\n\r]*skipped\\(inputCellComplex=1\\)")
  message(FATAL_ERROR
    "The skipped bow-tie face is missing from the summary:\n${log}")
endif()
if(log MATCHES "OptimizeQuadsFast: [^\n\r]*[1-9][0-9]* topology changes")
  message(FATAL_ERROR
    "OptimizeQuadsFast mutated the bow-tie input before rejecting it:\n${log}")
endif()
if(NOT log MATCHES
   "OptimizeQuadsFast quality: [^\n\r]*validity=FAIL [^\n\r]*invalid\\[T/Q\\]=0/0 [^\n\r]*nonManifoldFaces=1")
  message(FATAL_ERROR
    "The audit did not isolate the half-edge vertex-link failure:\n${log}")
endif()
