if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_MSH)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_MSH are required")
endif()

# Keep the regression specific: two opposite triangles split four quads in
# one complete six-face interior star around vertex 11.
file(READ "${TEST_MSH}" fixture)
foreach(element IN ITEMS
    "21 2 2 0 1 11 1 2"
    "22 3 2 0 1 11 2 3 4"
    "23 3 2 0 1 11 4 5 6"
    "24 2 2 0 1 11 6 7"
    "25 3 2 0 1 11 7 8 9"
    "26 3 2 0 1 11 9 10 1")
  if(NOT fixture MATCHES "[\n\r]${element}[\n\r]")
    message(FATAL_ERROR
      "The fixture no longer contains its exact T-Q-Q-T-Q-Q star")
  endif()
endforeach()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
set(output_mesh
    "${CMAKE_CURRENT_BINARY_DIR}/optimizeQuadsFastInteriorQQTQQT-output.msh")
file(REMOVE "${output_mesh}")
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -save -format msh2 -o "${output_mesh}" -nopopup -v 6
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR
    "OptimizeQuadsFast QQTQQT driver failed (status ${status}):\n${log}")
endif()
if(log MATCHES "Error *:" OR log MATCHES "OptimizeQuadsFast failed")
  message(FATAL_ERROR "The QQTQQT rewrite failed:\n${log}")
endif()
if(NOT EXISTS "${output_mesh}")
  message(FATAL_ERROR "The optimized QQTQQT mesh was not saved:\n${log}")
endif()
if(NOT log MATCHES
   "half-edge rule interior_qqtqqt_to_6q accepted=1")
  message(FATAL_ERROR "The dedicated QQTQQT rule was not accepted:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES "[1-9][0-9]* topology changes")
  message(FATAL_ERROR "The QQTQQT star was not rewritten:\n${log}")
endif()
if(NOT second_summary MATCHES "0 topology changes")
  message(FATAL_ERROR "The six-quad replacement is not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "OptimizeQuadsFast quality: [^\n\r]*"
       quality_summaries "${log}")
list(LENGTH quality_summaries quality_summary_count)
if(NOT quality_summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two Fast quality summaries:\n${log}")
endif()
foreach(quality_summary IN LISTS quality_summaries)
  if(NOT quality_summary MATCHES
     "triangles=0 quads=6 [^\n\r]*validity=PASS [^\n\r]*invalid\\[T/Q\\]=0/0 [^\n\r]*nonManifoldFaces=0")
    message(FATAL_ERROR
      "QQTQQT did not produce six valid manifold quads:\n${log}")
  endif()
endforeach()

# B=10/I=1 has eleven primary nodes; B=10/I=2 must have twelve. Moreover,
# harmonic initialization followed by Winslow must separate both interior
# positions from each other and move the retained center away from (0,0,0).
file(READ "${output_mesh}" optimized_mesh)
string(REGEX MATCH
  "\\$Nodes[\n\r]+([0-9]+)[\n\r]+([^$]*)\\$EndNodes"
  nodes_section "${optimized_mesh}")
if(NOT nodes_section OR NOT CMAKE_MATCH_1 EQUAL 12)
  message(FATAL_ERROR
    "QQTQQT did not add exactly one primary vertex:\n${optimized_mesh}")
endif()
set(node_lines "${CMAKE_MATCH_2}")
foreach(node_id IN ITEMS 11 12)
  string(REGEX MATCH
    "(^|[\n\r])${node_id}[ \t]+([^ \t\n\r]+)[ \t]+([^ \t\n\r]+)[ \t]+([^ \t\n\r]+)"
    node_line "${node_lines}")
  if(NOT node_line)
    message(FATAL_ERROR
      "Missing interior node ${node_id} after QQTQQT:\n${optimized_mesh}")
  endif()
  set(interior_${node_id}_x "${CMAKE_MATCH_2}")
  set(interior_${node_id}_y "${CMAKE_MATCH_3}")
  set(interior_${node_id}_z "${CMAKE_MATCH_4}")
endforeach()
set(zero "[-+]?0+(\\.0*)?([eE][-+]?0+)?")
if(interior_11_x MATCHES "^${zero}$" AND
   interior_11_y MATCHES "^${zero}$" AND
   interior_11_z MATCHES "^${zero}$")
  message(FATAL_ERROR
    "Winslow did not move the retained interior center:\n${optimized_mesh}")
endif()
if(interior_11_x STREQUAL interior_12_x AND
   interior_11_y STREQUAL interior_12_y AND
   interior_11_z STREQUAL interior_12_z)
  message(FATAL_ERROR
    "The two QQTQQT interior positions still coincide:\n${optimized_mesh}")
endif()
