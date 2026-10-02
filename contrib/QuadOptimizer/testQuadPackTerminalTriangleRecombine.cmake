if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_OUTPUT)
  message(FATAL_ERROR
    "GMSH_EXECUTABLE, TEST_GEO and TEST_OUTPUT are required")
endif()

execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}" -2 -nopopup -v 5
          -setnumber Mesh.PackCleanupMethod 1
          -o "${TEST_OUTPUT}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "PACK terminal triangle recombination failed:\n${log}")
endif()

# The odd five-segment boundary receives one midpoint during even quantization.
# Blossom must reject its two inverted candidate pairs, then V2 must recover
# exactly one admissible quad from the four triangles. Preserve the exact
# final connectivity checks below, including the new boundary midpoint.
if(NOT log MATCHES
   "Blossom recombination completed [^\n\r]*: 0 quads, 4 triangles, 0 invalid quads" OR
   NOT log MATCHES "PACK final cleanup: V2 with final nodal Winslow" OR
   NOT log MATCHES
   "QuadOptimizerV2 final split face=1 invalid=0 quality=0 cad=0 rejected=0")
  message(FATAL_ERROR "PACK/V2 did not reject the inverted pairings before its final recovery:\n${log}")
endif()
if(NOT log MATCHES
   "PACK final quad audit: concaveOrInvalid=0 [^\n\r]*split=0 rejected=0")
  message(FATAL_ERROR "The final quad validity audit failed:\n${log}")
endif()
string(FIND "${log}"
  "PACK final quality: faces=1 triangles=2 quads=1"
  final_count_position)
string(FIND "${log}"
  "validity=PASS invalid[T/Q]=0/0 nonManifoldFaces=0"
  final_validity_position)
if(final_count_position EQUAL -1 OR final_validity_position EQUAL -1)
  message(FATAL_ERROR "PACK final validity summary failed:\n${log}")
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
if(NOT triangle_count EQUAL 2 OR NOT quadrangle_count EQUAL 1)
  message(FATAL_ERROR
    "Expected two residual triangles and one recovered quad, got "
    "${triangle_count} triangles and ${quadrangle_count} quads")
endif()

# Even quantization splits boundary edge {1,2} at node 6. The recovery must
# retain both boundary segments and return Q={1,6,3,5}, T={2,3,6}, T={3,4,5};
# accept either cyclic orientation of each surface element.
if(NOT mesh MATCHES
   "[\n\r][0-9]+ 3 2 0 1 (1 6 3 5|6 3 5 1|3 5 1 6|5 1 6 3|1 5 3 6|5 3 6 1|3 6 1 5|6 1 5 3)[\n\r]")
  message(FATAL_ERROR "The recovered quad is not {1,6,3,5}")
endif()
if(NOT mesh MATCHES
   "[\n\r][0-9]+ 2 2 0 1 (3 4 5|4 5 3|5 3 4|3 5 4|5 4 3|4 3 5)[\n\r]")
  message(FATAL_ERROR "The residual triangle is not {3,4,5}")
endif()

if(NOT mesh MATCHES
   "[\n\r][0-9]+ 2 2 0 1 (2 3 6|3 6 2|6 2 3|2 6 3|6 3 2|3 2 6)[\n\r]" OR
   NOT mesh MATCHES "[\n\r][0-9]+ 1 2 0 1 (1 6|6 1)[\n\r]" OR
   NOT mesh MATCHES "[\n\r][0-9]+ 1 2 0 1 (6 2|2 6)[\n\r]")
  message(FATAL_ERROR "The boundary midpoint or its adjacent triangle was lost")
endif()
