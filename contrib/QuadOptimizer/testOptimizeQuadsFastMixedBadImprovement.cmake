if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 5
          -setnumber Mesh.OptimizeQuadsTargetSize 2
          -setnumber Mesh.OptimizeQuadsMinimumEdgeLength 1
          -setnumber Mesh.OptimizeQuadsMaximumEdgeLength 4
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast bad-to-less-bad mixed-swap driver failed:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two OptimizeQuadsFast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
# The QT phase must accept its strict improvement even though the replacement
# quad still violates absolute shape limits. The unconditional final quality
# split subsequently repairs that quad; it is a separate topology change.
if(NOT log MATCHES "loop round=1 phase=swap end accepted=1" OR
   NOT log MATCHES "final cleanup: split\\[invalid/quality/CAD\\]=0/1/0 TTmerges=0 TTcadSwaps=0 QTswaps=1 rejectedSplits=0" OR
   NOT first_summary MATCHES ", 2 topology changes," OR
   NOT first_summary MATCHES "bad elements 1 -> 0" OR
   NOT first_summary MATCHES "absolute violations 3 -> 0")
  message(FATAL_ERROR
    "The mixed T+Q improvement and its final quality repair did not compose:\n${log}")
endif()
if(NOT second_summary MATCHES ", 0 topology changes," OR
   NOT second_summary MATCHES "bad elements 0 -> 0" OR
   NOT second_summary MATCHES "absolute violations 0 -> 0")
  message(FATAL_ERROR
    "The repaired mixed T+Q result is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two quality summaries:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES "triangles=3 quads=0 absolutePass=3/3" OR
     NOT quality_summary MATCHES "validity=PASS" OR
     NOT quality_summary MATCHES "shapeSpecs=FAIL" OR
     NOT quality_summary MATCHES "sizeSpecs=PASS")
    message(FATAL_ERROR
      "The repaired mesh must satisfy absolute shape limits, validity and size while retaining its preferred-shape violations:\n${log}")
  endif()
endforeach()

if(log MATCHES "QuadOptimizer face [0-9]+ timing\\(s\\):")
  message(FATAL_ERROR "Per-face optimizer timings leaked:\n${log}")
endif()
