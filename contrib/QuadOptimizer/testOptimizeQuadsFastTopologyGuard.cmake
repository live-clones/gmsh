if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

# Keep the fixture honest: its triangle and quadrangle deliberately share the
# two directed edges 1->2 and 2->3. This is both a same-orientation incidence
# and a pair of distinct cells sharing more than one edge.
file(READ "${TEST_MSH}" fixture)
if(NOT fixture MATCHES "[\n\r]9 2 2 0 1 1 2 3[\n\r]" OR
   NOT fixture MATCHES "[\n\r]10 3 2 0 1 1 2 3 4[\n\r]")
  message(FATAL_ERROR
    "The topology-guard fixture no longer contains the invalid T/Q pair")
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
    "The invalid input warning stopped OptimizeQuadsFast (status ${status}):\n"
    "${log}")
endif()
if(NOT log MATCHES
   "Warning *: QuadOptimizer: face 1 is not a regular oriented surface cell complex")
  message(FATAL_ERROR
    "OptimizeQuadsFast did not warn about the invalid input cell complex:\n"
    "${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR
    "The invalid input warning was converted back into an error:\n${log}")
endif()
if(NOT log MATCHES
   "OptimizeQuadsFast: [^\n\r]*skipped\\(inputCellComplex=1\\)")
  message(FATAL_ERROR
    "The skipped input face is missing from the Fast summary:\n${log}")
endif()
if(NOT log MATCHES
   "OptimizeQuadsFast quality: [^\n\r]*validity=FAIL [^\n\r]*invalid\\[T/Q\\]=1/1 [^\n\r]*nonManifoldFaces=1")
  message(FATAL_ERROR
    "The skipped input face is missing from the final validity audit:\n${log}")
endif()
if(log MATCHES "OptimizeQuadsFast: [^\n\r]*[1-9][0-9]* topology changes")
  message(FATAL_ERROR
    "OptimizeQuadsFast mutated the invalid input before rejecting it:\n${log}")
endif()
