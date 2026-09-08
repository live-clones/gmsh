if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

# Keep the fixture honest: the six quadrangles form one complete star around
# interior vertex 13 and expose the twelve-vertex cavity boundary 1..12.
file(READ "${TEST_MSH}" fixture)
foreach(element IN ITEMS
    "25 3 2 0 1 13 1 2 3"
    "26 3 2 0 1 13 3 4 5"
    "27 3 2 0 1 13 5 6 7"
    "28 3 2 0 1 13 7 8 9"
    "29 3 2 0 1 13 9 10 11"
    "30 3 2 0 1 13 11 12 1")
  if(NOT fixture MATCHES "[\n\r]${element}[\n\r]")
    message(FATAL_ERROR
      "The valence-six fixture no longer contains its complete B=12 star")
  endif()
endforeach()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast valence-six driver failed (status ${status}):\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The valence-six rewrite failed:\n${log}")
endif()
if(NOT log MATCHES
   "half-edge rule valence6_split accepted=1")
  message(FATAL_ERROR "The dedicated valence-six rule was not accepted:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "[1-9][0-9]* topology changes")
  message(FATAL_ERROR "The valence-six star was not split:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes")
  message(FATAL_ERROR "The split valence-six star is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast quality summaries:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES
     "triangles=0 quads=7 [^\n\r]*validity=PASS [^\n\r]*invalid\\[T/Q\\]=0/0 [^\n\r]*nonManifoldFaces=0")
    message(FATAL_ERROR
      "The split valence-six star is not seven valid manifold quads:\n${log}")
  endif()
endforeach()
if(log MATCHES
   "OptimizeQuadsFast Q\\+T\\+T triangle reduction: accepted=[1-9]")
  message(FATAL_ERROR "An unrelated mixed rewrite was accepted:\n${log}")
endif()
