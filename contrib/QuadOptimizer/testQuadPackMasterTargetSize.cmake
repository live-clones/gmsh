if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO OR
   NOT DEFINED TEST_OUTPUT)
  message(FATAL_ERROR "GMSH_EXECUTABLE, TEST_GEO and TEST_OUTPUT are required")
endif()

function(assert_pack_log_contract log_variable run_label)
  set(run_log "${${log_variable}}")

  # Debug printf() calls are especially brittle here: one historical call
  # even passed a double through an integer format. Reject any unlabelled
  # numeric-only line without depending on the accidental values printed.
  set(number_re "[-+]?[0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?")
  set(raw_numeric_line_re
      "(^|[\n\r])[ \t]*${number_re}([ \t]+${number_re})*[ \t]*($|[\n\r])")
  if(run_log MATCHES "${raw_numeric_line_re}")
    message(FATAL_ERROR
      "${run_label} leaked unlabelled numeric debug output:\n${run_log}")
  endif()
  if(run_log MATCHES
     "(QuadOptimizer|QuadCleanUp) face [0-9]+(:| timing\\(s\\):)")
    message(FATAL_ERROR
      "${run_label} leaked per-face optimizer timing:\n${run_log}")
  endif()

  # Preserve the useful diagnostic and its field names, but not values that
  # legitimately depend on timings or future meshing improvements.
  string(REGEX MATCHALL
    "- Face 1: remeshed with a global pattern, [^\n\r]*"
    global_pattern_messages "${run_log}")
  list(LENGTH global_pattern_messages global_pattern_count)
  if(NOT global_pattern_count EQUAL 1)
    message(FATAL_ERROR
      "${run_label} expected exactly one global-pattern success message:\n"
      "${run_log}")
  endif()
  list(GET global_pattern_messages 0 global_pattern_message)
  if(NOT global_pattern_message MATCHES
     "^- Face 1: remeshed with a global pattern, [0-9]+ -> [0-9]+ quads, [0-9]+ -> [0-9]+ int\\. vertices, SICN min: [-+]?[0-9]+\\.[0-9][0-9][0-9] -> [-+]?[0-9]+\\.[0-9][0-9][0-9], SICN avg: [-+]?[0-9]+\\.[0-9][0-9][0-9] -> [-+]?[0-9]+\\.[0-9][0-9][0-9], time: [0-9]+\\.[0-9][0-9][0-9]s$")
    message(FATAL_ERROR
      "${run_label} global-pattern diagnostic changed:\n"
      "${global_pattern_message}")
  endif()

  string(REGEX MATCHALL "PACK final quad audit: [^\n\r]*"
         final_audits "${run_log}")
  list(LENGTH final_audits final_audit_count)
  if(NOT final_audit_count EQUAL 1)
    message(FATAL_ERROR
      "${run_label} expected exactly one final quad audit:\n${run_log}")
  endif()
  list(GET final_audits 0 final_audit)
  if(NOT final_audit MATCHES
     "^PACK final quad audit: concaveOrInvalid=[0-9]+ excessiveWarping=[0-9]+ split=[0-9]+ rejected=0 skippedFaces=0$")
    message(FATAL_ERROR
      "${run_label} failed its terminal validity audit:\n${final_audit}")
  endif()

  string(REGEX MATCHALL "PACK final quality: [^\n\r]*"
         final_quality_lines "${run_log}")
  list(LENGTH final_quality_lines final_quality_count)
  if(NOT final_quality_count EQUAL 1)
    message(FATAL_ERROR
      "${run_label} expected exactly one final quality line:\n${run_log}")
  endif()
  list(GET final_quality_lines 0 final_quality_line)
  if(final_quality_line MATCHES
     "^PACK final quality: faces=([1-9][0-9]*) triangles=([0-9]+) quads=([0-9]+) absolutePass=([0-9]+)/([0-9]+) validity=PASS invalid\\[T/Q\\]=0/0 nonManifoldFaces=0 shapeSpecs=(PASS|FAIL) sizeSpecs=(PASS|FAIL|off)$")
    set(triangles "${CMAKE_MATCH_2}")
    set(quadrangles "${CMAKE_MATCH_3}")
    set(absolute_pass "${CMAKE_MATCH_4}")
    set(quality_elements "${CMAKE_MATCH_5}")
  else()
    message(FATAL_ERROR
      "${run_label} malformed or invalid final quality line:\n"
      "${final_quality_line}")
  endif()
  math(EXPR expected_elements "${triangles} + ${quadrangles}")
  if(NOT quality_elements EQUAL expected_elements OR
     absolute_pass GREATER quality_elements)
    message(FATAL_ERROR
      "${run_label} has incoherent element counts:\n${final_quality_line}")
  endif()

  set(pass_counts_re "[0-9]+/[0-9]+\\|[0-9]+/[0-9]+")
  string(REGEX MATCHALL
    "PACK final specifications pass\\(preferred/total\\|absolute/total\\): [^\n\r]*"
    final_specification_lines "${run_log}")
  list(LENGTH final_specification_lines final_specification_count)
  if(NOT final_specification_count EQUAL 1)
    message(FATAL_ERROR
      "${run_label} expected exactly one final specifications line:\n"
      "${run_log}")
  endif()
  list(GET final_specification_lines 0 final_specification_line)
  if(NOT final_specification_line MATCHES
     "^PACK final specifications pass\\(preferred/total\\|absolute/total\\): warp=${pass_counts_re} edgeRatio=${pass_counts_re} quadAngleMin=${pass_counts_re} quadAngleMax=${pass_counts_re} triAngleMin=${pass_counts_re} triAngleMax=${pass_counts_re} skew=${pass_counts_re}$")
    message(FATAL_ERROR
      "${run_label} malformed final specifications line:\n"
      "${final_specification_line}")
  endif()

  string(REGEX MATCHALL "PACK final quad metrics: [^\n\r]*"
         final_metric_lines "${run_log}")
  list(LENGTH final_metric_lines final_metric_count)
  if(NOT final_metric_count EQUAL 1)
    message(FATAL_ERROR
      "${run_label} expected exactly one final quad-metrics line:\n${run_log}")
  endif()
  list(GET final_metric_lines 0 final_metric_line)
  if(NOT final_metric_line MATCHES
     "^PACK final quad metrics: SICN\\[min/avg\\]=${number_re}/${number_re} angle\\[min/max\\]=${number_re}/${number_re}deg edgeRatio\\[max/avg\\]=${number_re}/${number_re} skew\\[max/avg\\]=${number_re}/${number_re}deg warp\\[max/avg\\]=${number_re}/${number_re}deg bad=[0-9]+ invalid=[0-9]+ valence\\[severe/irregular\\]=[0-9]+/[0-9]+$")
    message(FATAL_ERROR
      "${run_label} malformed final quad-metrics line:\n${final_metric_line}")
  endif()

  string(REGEX MATCHALL "PACK final fit: [^\n\r]*"
         final_fit_lines "${run_log}")
  list(LENGTH final_fit_lines final_fit_count)
  if(NOT final_fit_count EQUAL 1)
    message(FATAL_ERROR
      "${run_label} expected exactly one final fit line:\n${run_log}")
  endif()
  list(GET final_fit_lines 0 final_fit_line)
  if(NOT final_fit_line MATCHES
     "^PACK final fit: sizeEdges=[0-9]+ length\\[min/max\\]=${number_re}/${number_re} targetRatio\\[min/max/rmsLog\\]=${number_re}/${number_re}/${number_re} sizeBad\\[below/above/invalid\\]=[0-9]+/[0-9]+/[0-9]+ CAD\\[max/rms\\]=${number_re}/${number_re} CADcoverage=[0-9]+/[0-9]+ invalidElements=[0-9]+ invalidSamples=[0-9]+$")
    message(FATAL_ERROR
      "${run_label} malformed final fit line:\n${final_fit_line}")
  endif()
  if(final_fit_line MATCHES
     "CADcoverage=([0-9]+)/([0-9]+) invalidElements=0 invalidSamples=0$")
    set(cad_elements "${CMAKE_MATCH_1}")
    set(cad_elements_requested "${CMAKE_MATCH_2}")
  else()
    message(FATAL_ERROR
      "${run_label} has incomplete CAD coverage:\n${final_fit_line}")
  endif()
  if(NOT cad_elements EQUAL cad_elements_requested OR
     NOT cad_elements_requested EQUAL expected_elements)
    message(FATAL_ERROR
      "${run_label} has incoherent CAD coverage:\n${final_fit_line}")
  endif()

  # The model-wide report is meaningful only after the unconditional terminal
  # validity audit. Also preserve the four-line report order.
  string(FIND "${run_log}" "PACK final quad audit:" final_audit_position)
  string(FIND "${run_log}" "PACK final quality:" final_quality_position)
  string(FIND "${run_log}"
         "PACK final specifications pass(preferred/total|absolute/total):"
         final_specification_position)
  string(FIND "${run_log}" "PACK final quad metrics:" final_metric_position)
  string(FIND "${run_log}" "PACK final fit:" final_fit_position)
  if(NOT final_quality_position GREATER final_audit_position OR
     NOT final_specification_position GREATER final_quality_position OR
     NOT final_metric_position GREATER final_specification_position OR
     NOT final_fit_position GREATER final_metric_position)
    message(FATAL_ERROR
      "${run_label} final quality report is missing, reordered or precedes "
      "the final quad audit:\n${run_log}")
  endif()
endfunction()

execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}" -2 -algo pack
          -setnumber Mesh.QuadqsTargetSize 0.03
          -nopopup -v 5 -o "${TEST_OUTPUT}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "PACK master-target driver failed:\n${log}")
endif()
if(NOT log MATCHES
   "PACK master target size: h=0.03, admissible edges=\\[0.015,0.06\\], 3D packing forced")
  message(FATAL_ERROR "The target did not derive the edge bounds:\n${log}")
endif()
if(NOT log MATCHES "Size map statistics: min=0.030, max=0.030")
  message(FATAL_ERROR "The target did not drive mesh generation:\n${log}")
endif()
if(NOT log MATCHES "Blossom recombination completed")
  message(FATAL_ERROR "PACK did not implicitly recombine the surface:\n${log}")
endif()
if(NOT log MATCHES "Optimizing mesh \\(OptimizeQuadsFast\\)")
  message(FATAL_ERROR "PACK did not run the Fast cleanup:\n${log}")
endif()
if(NOT log MATCHES "3D oriented-cube packing created [0-9]+ points on face 1")
  message(FATAL_ERROR "PACK did not use 3D packing on the CAD face:\n${log}")
endif()
if(log MATCHES "intrinsic Delaunay triangulation")
  message(FATAL_ERROR "PACK applied discrete intrinsic refinement to CAD:\n${log}")
endif()
assert_pack_log_contract(log "PACK master-target driver")

# Preserve the historical uniform-size command-line spelling. It must enter
# the exact same bounded CAD pipeline without requiring QuadqsTargetSize.
set(legacy_output "${TEST_OUTPUT}.legacy.msh")
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}" -2 -algo pack
          -clmin 0.03 -clmax 0.03
          -nopopup -v 5 -o "${legacy_output}"
  RESULT_VARIABLE legacy_status
  OUTPUT_VARIABLE legacy_output_log
  ERROR_VARIABLE legacy_error)
set(legacy_log "${legacy_output_log}${legacy_error}")
if(NOT legacy_status EQUAL 0)
  message(FATAL_ERROR "PACK legacy uniform-size driver failed:\n${legacy_log}")
endif()
if(NOT legacy_log MATCHES
   "PACK master target size: h=0.03, admissible edges=\\[0.015,0.06\\], 3D packing forced")
  message(FATAL_ERROR "-clmin/-clmax did not derive the PACK target:\n${legacy_log}")
endif()
if(NOT legacy_log MATCHES
   "3D oriented-cube packing created [0-9]+ points on face 1")
  message(FATAL_ERROR "Legacy uniform sizing did not use CAD 3D packing:\n${legacy_log}")
endif()
if(legacy_log MATCHES "intrinsic Delaunay triangulation")
  message(FATAL_ERROR "Legacy PACK applied intrinsic refinement to CAD:\n${legacy_log}")
endif()
assert_pack_log_contract(legacy_log "PACK legacy uniform-size driver")
