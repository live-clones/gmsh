# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

# contributor : Jonathan Lambrechts

set(SRC_MULTI
  src/taucs_sn_llt.c
  src/taucs_ccs_base.c
  src/taucs_vec_base.c
  src/taucs_ccs_ops.c
  src/taucs_ccs_io.c
  src/taucs_ccs_factor_llt.c
  src/taucs_ccs_solve_llt.c
  src/taucs_complex.c
  src/taucs_ccs_ooc_llt.c
  src/taucs_ccs_ooc_lu.c
)

set(SRC_DOUBLE
  src/taucs_iter.c
  src/taucs_vaidya.c
  src/taucs_recvaidya.c
  src/taucs_gremban.c
  src/taucs_ccs_xxt.c
  src/taucs_ccs_generators.c
)

set(SRC_GENERAL
  src/taucs_linsolve.c
  src/taucs_ccs_order.c
  src/taucs_memory.c
  src/taucs_logging.c
  src/taucs_timer.c
  src/taucs_ooc_io.c
  src/taucs_malloc.c
)

set(SRC
  # external/src/readhb.c
  external/src/amdatr.c
  external/src/amdbar.c
  external/src/amdexa.c
  external/src/amdhaf.c
  external/src/amdhat.c
  external/src/amdpre.c
  external/src/amdtru.c
  external/src/genmmd.c
  external/src/colamd.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/taucs "${SRC};${HDR}")

foreach(FILE ${SRC_MULTI})
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/D)
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/S)
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Z)
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/C)
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/G)
endforeach(FILE)

foreach(FILE ${SRC_DOUBLE})
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/D)
endforeach(FILE)

foreach(FILE ${SRC_GENERAL})
  file(COPY ${FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/G)
endforeach(FILE)
