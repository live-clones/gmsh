if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_OUTPUT)
  message(FATAL_ERROR
    "GMSH_EXECUTABLE, TEST_GEO and TEST_OUTPUT are required")
endif()

execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}" -2 -nopopup -v 5
          -setnumber Mesh.QuadqsCleanupMethod 2
          -o "${TEST_OUTPUT}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "PACK terminal-concave driver failed:\n${log}")
endif()

# Keep the regression honest: recombination must first construct the bad
# quad; otherwise two triangles in the output would not exercise the terminal
# validity fallback.
if(NOT log MATCHES
   "Blossom recombination completed [^\n\r]*: 1 quads, 0 triangles, 1 invalid quads")
  message(FATAL_ERROR
    "The fixture no longer creates exactly one invalid PACK quad:\n${log}")
endif()
if(NOT log MATCHES
   "PACK terminal quad validity: concaveOrInvalid=1 [^\n\r]*split=1 rejected=0 skippedFaces=0")
  message(FATAL_ERROR
    "PACK did not report the unconditional terminal split:\n${log}")
endif()
if(NOT log MATCHES
   "PACK terminal triangle recombination: [^\n\r]*accepted=0 [^\n\r]*rejectedInvalid=1")
  message(FATAL_ERROR
    "PACK recreated the concave quad from its split siblings:\n${log}")
endif()
if(NOT log MATCHES
   "PACK final quad audit: concaveOrInvalid=0 [^\n\r]*split=0 rejected=0 skippedFaces=0")
  message(FATAL_ERROR "PACK final quad audit failed:\n${log}")
endif()

file(READ "${TEST_OUTPUT}" mesh)
string(REGEX MATCH "\\$Elements[\n\r]+[0-9]+[\n\r]+([^$]+)\\$EndElements"
       element_section "${mesh}")
if(element_section STREQUAL "")
  message(FATAL_ERROR "Could not parse the MSH2 element section")
endif()
string(REGEX MATCHALL
  "[\n\r][0-9]+ 2 [0-9]+ [^\n\r]*" triangles "${element_section}")
string(REGEX MATCHALL
  "[\n\r][0-9]+ 3 [0-9]+ [^\n\r]*" quadrangles "${element_section}")
list(LENGTH triangles triangle_count)
list(LENGTH quadrangles quadrangle_count)
if(NOT triangle_count EQUAL 2 OR NOT quadrangle_count EQUAL 0)
  message(FATAL_ERROR
    "PACK returned a prohibited terminal quad: expected 2 triangles and 0 "
    "quads, got ${triangle_count} triangles and ${quadrangle_count} quads.\n"
    "${log}")
endif()

# Exercise the direct Fast terminal path as well. Here Fast must consume the
# invalid quad before the model-wide PACK fallback sees the face.
set(fast_output "${TEST_OUTPUT}.fast.msh")
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}" -2 -nopopup -v 5
          -setnumber Mesh.QuadqsCleanupMethod 1
          -o "${fast_output}"
  RESULT_VARIABLE fast_status
  OUTPUT_VARIABLE fast_output_log
  ERROR_VARIABLE fast_error)
set(fast_log "${fast_output_log}${fast_error}")
if(NOT fast_status EQUAL 0)
  message(FATAL_ERROR "Fast terminal-concave driver failed:\n${fast_log}")
endif()
if(NOT fast_log MATCHES
   "OptimizeQuadsFast terminal split: [^\n\r]*nonConvexOrInvalid=1 split=1 rejected=0")
  message(FATAL_ERROR
    "OptimizeQuadsFast did not split its prohibited final quad:\n${fast_log}")
endif()
if(NOT fast_log MATCHES
   "OptimizeQuadsFast terminal triangle recombination: [^\n\r]*accepted=0 [^\n\r]*rejectedInvalid=1")
  message(FATAL_ERROR
    "OptimizeQuadsFast recreated its concave split quad:\n${fast_log}")
endif()
if(NOT fast_log MATCHES
   "PACK terminal quad validity: concaveOrInvalid=0 [^\n\r]*split=0 rejected=0 skippedFaces=0")
  message(FATAL_ERROR
    "PACK found a prohibited quad after the Fast terminal pass:\n${fast_log}")
endif()
