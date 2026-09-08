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

# The invalid pairing can be rejected directly by Blossom, or by the
# terminal validity split on builds retaining the historical recombination
# path. Validate either complete route explicitly; never accept an
# unrecognized intermediate state merely because its final cell count fits.
if(log MATCHES
   "Blossom: kept 1 inverted matched triangle pair unrecombined")
  if(NOT log MATCHES
     "Blossom recombination completed [^\n\r]*: 0 quads, 2 triangles, 0 invalid quads")
    message(FATAL_ERROR
      "Blossom rejected the concave pair but did not retain its triangles:\n${log}")
  endif()
  if(NOT log MATCHES
     "PACK terminal quad validity: concaveOrInvalid=0 [^\n\r]*split=0 rejected=0 skippedFaces=0")
    message(FATAL_ERROR
      "PACK altered the mesh after Blossom's upstream guard:\n${log}")
  endif()
elseif(log MATCHES
       "Blossom recombination completed [^\n\r]*: 1 quads, 0 triangles, 1 invalid quads")
  if(NOT log MATCHES
     "PACK terminal quad validity: concaveOrInvalid=1 [^\n\r]*split=1 rejected=0 skippedFaces=0")
    message(FATAL_ERROR
      "PACK did not split its concave intermediate quad:\n${log}")
  endif()
else()
  message(FATAL_ERROR
    "PACK followed no recognized concave-pair protection route:\n${log}")
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
string(FIND "${log}"
  "PACK final quality: faces=1 triangles=2 quads=0"
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
if(NOT triangle_count EQUAL 2 OR NOT quadrangle_count EQUAL 0)
  message(FATAL_ERROR
    "PACK returned a prohibited terminal quad: expected 2 triangles and 0 "
    "quads, got ${triangle_count} triangles and ${quadrangle_count} quads.\n"
    "${log}")
endif()

# The protected diagonal is {1,3}; counts alone would also accept the other,
# concave pairing that this regression is intended to prohibit.
if(NOT mesh MATCHES
   "[\n\r][0-9]+ 2 2 0 1 (1 2 3|2 3 1|3 1 2|1 3 2|3 2 1|2 1 3)[\n\r]" OR
   NOT mesh MATCHES
   "[\n\r][0-9]+ 2 2 0 1 (1 3 4|3 4 1|4 1 3|1 4 3|4 3 1|3 1 4)[\n\r]")
  message(FATAL_ERROR
    "PACK did not retain the deterministic {1,2,3}/{1,3,4} split")
endif()

# Exercise the Fast configuration as well. The same upstream guard may leave
# no invalid quad for Fast; otherwise Fast must split it before PACK's final
# audit.
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
if(fast_log MATCHES
   "Blossom: kept 1 inverted matched triangle pair unrecombined")
  if(NOT fast_log MATCHES
     "OptimizeQuadsFast terminal split: [^\n\r]*nonConvexOrInvalid=0 split=0 rejected=0")
    message(FATAL_ERROR
      "Fast altered the triangles protected upstream by Blossom:\n${fast_log}")
  endif()
elseif(NOT fast_log MATCHES
       "OptimizeQuadsFast terminal split: [^\n\r]*nonConvexOrInvalid=1 split=1 rejected=0")
  message(FATAL_ERROR
    "Fast followed no recognized concave-pair protection route:\n${fast_log}")
endif()
if(NOT fast_log MATCHES
   "OptimizeQuadsFast Q\\+T\\+T triangle reduction: accepted=0" OR
   NOT fast_log MATCHES
   "PACK terminal triangle recombination: [^\n\r]*accepted=0 [^\n\r]*rejectedInvalid=1")
  message(FATAL_ERROR
    "OptimizeQuadsFast recreated its concave split quad:\n${fast_log}")
endif()
if(NOT fast_log MATCHES
   "PACK terminal quad validity: concaveOrInvalid=0 [^\n\r]*split=0 rejected=0 skippedFaces=0")
  message(FATAL_ERROR
    "PACK found a prohibited quad after the Fast terminal pass:\n${fast_log}")
endif()

file(READ "${fast_output}" fast_mesh)
string(REGEX MATCHALL
  "[\n\r][0-9]+ 2 2 0 1 [^\n\r]*" fast_triangles "${fast_mesh}")
string(REGEX MATCHALL
  "[\n\r][0-9]+ 3 2 0 1 [^\n\r]*" fast_quadrangles "${fast_mesh}")
list(LENGTH fast_triangles fast_triangle_count)
list(LENGTH fast_quadrangles fast_quadrangle_count)
if(NOT fast_triangle_count EQUAL 2 OR NOT fast_quadrangle_count EQUAL 0 OR
   NOT fast_mesh MATCHES
   "[\n\r][0-9]+ 2 2 0 1 (1 2 3|2 3 1|3 1 2|1 3 2|3 2 1|2 1 3)[\n\r]" OR
   NOT fast_mesh MATCHES
   "[\n\r][0-9]+ 2 2 0 1 (1 3 4|3 4 1|4 1 3|1 4 3|4 3 1|3 1 4)[\n\r]")
  message(FATAL_ERROR
    "Fast did not retain the deterministic valid triangle split")
endif()
