if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_OUTPUT)
  message(FATAL_ERROR
    "GMSH_EXECUTABLE, TEST_GEO and TEST_OUTPUT are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 6
          -save -format msh4 -setnumber Mesh.Binary 0
          -o "${TEST_OUTPUT}"
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast discrete-fold guard driver failed:\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The discrete-fold guard emitted an error:\n${log}")
endif()

# V2 validates physical Jacobians and sampled CAD normals at final splitting.
# Preserve the output connectivity and CAD-coverage assertions below.
if(NOT log MATCHES
   "QuadOptimizerV2 final split face=1 invalid=1 cad=0 rejected=0")
  message(FATAL_ERROR
    "The physical terminal split was not accepted:\n${log}")
endif()
if(NOT log MATCHES
   "quality: faces=1 triangles=2 quads=0 [^\n\r]*validity=PASS" OR
   NOT log MATCHES "invalid.T/Q.=0/0")
  message(FATAL_ERROR
    "The split triangles failed the final multipoint orientation audit:\n${log}")
endif()
if(NOT log MATCHES
   "fit: [^\n\r]*CADcoverage=2/2 invalidElements=0 invalidSamples=0")
  message(FATAL_ERROR
    "The split triangles were not both evaluated against the GFace:\n${log}")
endif()

file(READ "${TEST_OUTPUT}" mesh)
if(NOT mesh MATCHES "\n2 1 2 2[ \t]*\n" OR
   mesh MATCHES "\n2 1 3 [0-9]+[ \t]*\n")
  message(FATAL_ERROR
    "Expected exactly one triangle block and no quadrangle block in "
    "${TEST_OUTPUT}")
endif()
