if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH OR NOT DEFINED TEST_OUTPUT)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO, TEST_MSH and TEST_OUTPUT are required")
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
# The fixture runs twice: the final quality split in the first invocation can
# expose three QT quality swaps followed by a TT merge in the second. V2
# intentionally does not restart its full topology schedule after final splitting.
# A third invocation must be a true fixed point, including every saved coordinate
# and element connectivity.
set(driver "${TEST_OUTPUT}.geo")
set(second_mesh "${TEST_OUTPUT}.second.msh")
set(third_mesh "${TEST_OUTPUT}.third.msh")
file(WRITE "${driver}"
  "Include \"${TEST_GEO}\";\n"
  "Mesh.MshFileVersion = 2.2;\nMesh.Binary = 0;\nMesh.SaveAll = 1;\n"
  "Save \"${second_mesh}\";\n"
  "OptimizeMesh \"OptimizeQuadsFast\";\n"
  "Save \"${third_mesh}\";\n")
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${driver}"
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
string(REGEX MATCHALL "half-edge rule valence6_split accepted=1"
       valence_splits "${log}")
list(LENGTH valence_splits valence_split_count)
if(NOT valence_split_count EQUAL 1)
  message(FATAL_ERROR "Expected exactly one dedicated valence-six rewrite:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 3)
  message(FATAL_ERROR "Expected three Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
list(GET summaries 2 third_summary)
if(NOT first_summary MATCHES ", [1-9][0-9]* topology changes,")
  message(FATAL_ERROR "The valence-six star was not split:\n${log}")
endif()
if(NOT second_summary MATCHES ", [1-9][0-9]* topology changes," OR
   NOT third_summary MATCHES ", 0 topology changes,")
  message(FATAL_ERROR "The split star did not reach a fixed point after its final quality repair:\n${log}")
endif()
file(SHA256 "${second_mesh}" second_hash)
file(SHA256 "${third_mesh}" third_hash)
if(NOT second_hash STREQUAL third_hash)
  message(FATAL_ERROR "The third pass changed the saved nodes or connectivity")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 3)
  message(FATAL_ERROR "Expected three Fast quality summaries:\n${log}")
endif()
list(GET quality_summaries 0 first_quality)
list(GET quality_summaries 1 second_quality)
list(GET quality_summaries 2 third_quality)
if(NOT first_quality MATCHES "triangles=2 quads=6 absolutePass=8/8" OR
   NOT second_quality MATCHES "triangles=0 quads=7 absolutePass=7/7" OR
   NOT third_quality MATCHES "triangles=0 quads=7 absolutePass=7/7")
  message(FATAL_ERROR "The quality split and subsequent TT merge did not recover seven admissible quads:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES
     "validity=PASS invalid\\[T/Q\\]=0/0 nonManifoldFaces=0")
    message(FATAL_ERROR "The valence-six rewrite produced invalid or non-manifold cells:\n${log}")
  endif()
endforeach()
string(REGEX MATCHALL
  "OptimizeQuadsFast Q\\+T\\+T triangle reduction: accepted=[0-9]+"
  reductions "${log}")
list(LENGTH reductions reduction_count)
if(NOT reduction_count EQUAL 3)
  message(FATAL_ERROR "Expected one triangle-reduction report per invocation:\n${log}")
endif()
list(GET reductions 0 first_reduction)
list(GET reductions 1 second_reduction)
list(GET reductions 2 third_reduction)
if(NOT first_reduction MATCHES "accepted=0$" OR
   NOT second_reduction MATCHES "accepted=1$" OR
   NOT third_reduction MATCHES "accepted=0$")
  message(FATAL_ERROR "Only the second invocation should recover the split quad:\n${log}")
endif()
