if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

# Keep the fixture specific: boundary vertex 1 has exactly the connected
# T(1,2,3)-Q(1,3,4,5)-Q(1,5,6,7)-T(1,7,8) fan. The direct I=0 strip must
# now win; the I=1 boundary fan remains a fallback for harder geometries.
file(READ "${TEST_MSH}" fixture)
foreach(element IN ITEMS
    "17 2 2 0 1 1 2 3"
    "18 3 2 0 1 1 3 4 5"
    "19 3 2 0 1 1 5 6 7"
    "20 2 2 0 1 1 7 8")
  if(NOT fixture MATCHES "[\n\r]${element}[\n\r]")
    message(FATAL_ERROR
      "The boundary fan fixture no longer contains its T-Q-Q-T chain")
  endif()
endforeach()

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
    "OptimizeQuadsFast boundary fan driver failed (status ${status}):\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The boundary fan rewrite failed:\n${log}")
endif()

string(REGEX MATCHALL
  "OptimizeQuadsFast Q\\+T\\+T triangle reduction: accepted=[0-9]+"
  strip_summaries "${log}")
list(LENGTH strip_summaries strip_summary_count)
if(NOT strip_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two direct strip summaries:\n${log}")
endif()
list(GET strip_summaries 0 first_strip_summary)
list(GET strip_summaries 1 second_strip_summary)
if(NOT first_strip_summary MATCHES "accepted=1$")
  message(FATAL_ERROR
    "The direct T-Q-Q-T -> 3Q reduction was not accepted once:\n${log}")
endif()
if(NOT second_strip_summary MATCHES "accepted=0$")
  message(FATAL_ERROR "The direct strip rule is not at a fixed point:\n${log}")
endif()

string(REGEX MATCHALL
  "OptimizeQuadsFast half-edge rule boundary_t_qn_t: accepted=[0-9]+"
  fan_summaries "${log}")
list(LENGTH fan_summaries fan_summary_count)
if(NOT fan_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two boundary fan summaries:\n${log}")
endif()
foreach(fan_summary IN LISTS fan_summaries)
  if(NOT fan_summary MATCHES "accepted=0$")
    message(FATAL_ERROR
      "The point-creating boundary fan intercepted the direct strip:\n${log}")
  endif()
endforeach()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "1 topology changes")
  message(FATAL_ERROR
    "The direct boundary strip rewrite was not applied exactly once:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes")
  message(FATAL_ERROR "The closed boundary fan is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast quality summaries:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES
     "triangles=0 quads=3 [^\n\r]*validity=PASS [^\n\r]*invalid\\[T/Q\\]=0/0 [^\n\r]*nonManifoldFaces=0")
    message(FATAL_ERROR
      "The closed boundary fan is not three valid manifold quads:\n${log}")
  endif()
endforeach()
