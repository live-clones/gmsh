if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

# Keep the regression focused on the precise Blossom failure: two quads share
# the two-edge chain 1-2-3, with opposite incidences and disjoint interiors.
file(READ "${TEST_MSH}" fixture)
if(NOT fixture MATCHES "[\n\r]10 3 2 0 1 1 2 3 4[\n\r]" OR
   NOT fixture MATCHES "[\n\r]11 3 2 0 1 5 1 2 3[\n\r]")
  message(FATAL_ERROR
    "The preflight-split fixture no longer contains the two-edge quad pair")
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
  message(FATAL_ERROR "Preflight concave-split driver failed:\n${log}")
endif()
if(log MATCHES "not a regular oriented surface cell complex" OR
   log MATCHES "could not be oriented consistently")
  message(FATAL_ERROR
    "Fast rejected the repairable Blossom cell complex:\n${log}")
endif()

if(NOT log MATCHES
   "prepared fixed CAD valence-two stars: splitQuads=1 addedPoints=0")
  message(FATAL_ERROR "V2 did not prepare the shared CAD pole:\n${log}")
endif()

string(REGEX MATCHALL
  "QuadOptimizerV2 final split face=1 [^\n\r]*" split_summaries "${log}")
list(LENGTH split_summaries split_summary_count)
if(NOT split_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast split summaries:\n${log}")
endif()
list(GET split_summaries 0 first_split)
list(GET split_summaries 1 second_split)
# A bounded invalid-cavity rewrite can now repair the remaining quad before
# the terminal split. Assert the final mesh below, independently of which
# validity repair produced it.
if(NOT first_split MATCHES "invalid=[01] cad=0 rejected=0")
  message(FATAL_ERROR
    "The first terminal split audit contains an unexpected result:\n${log}")
endif()
if(NOT second_split MATCHES "invalid=0 cad=0 rejected=0")
  message(FATAL_ERROR "The preflight repair is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "reoriented=[1-9][0-9]*" OR
   NOT second_summary MATCHES "reoriented=0")
  message(FATAL_ERROR
    "Concavity split and local orientation repair did not compose:\n${log}")
endif()
if(NOT second_summary MATCHES " faces, 0 topology changes,")
  message(FATAL_ERROR "The repaired mesh is not a topology fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two final quality summaries:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES
     "faces=1 triangles=4 quads=0 absolutePass=4/4")
    message(FATAL_ERROR "Preflight repair did not produce four valid triangles:\n${log}")
  endif()
  if(NOT quality_summary MATCHES
     "validity=PASS invalid\\[T/Q\\]=0/0 nonManifoldFaces=0")
    message(FATAL_ERROR "Preflight split failed validity:\n${log}")
  endif()
endforeach()
