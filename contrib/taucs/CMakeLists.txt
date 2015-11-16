# Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

# contributor : Jonathan Lambrechts

set(SRC_MULTI
  taucs_sn_llt
  taucs_ccs_base
  taucs_vec_base
  taucs_ccs_ops
  taucs_ccs_io
  taucs_ccs_factor_llt
  taucs_ccs_solve_llt
  taucs_complex
  taucs_ccs_ooc_llt
  taucs_ccs_ooc_lu
)

set(SRC_DOUBLE
  taucs_iter
  taucs_vaidya
  taucs_recvaidya
  taucs_gremban
  taucs_ccs_xxt
  taucs_ccs_generators
)

set(SRC_GENERAL
  taucs_linsolve
  taucs_ccs_order
  taucs_memory
  taucs_logging
  taucs_timer
  taucs_ooc_io
  taucs_malloc
)

set(SRC
  external/src/readhb.c
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

function (build_variant SFILE FLAG DNAME)
  file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/${SFILE}.c" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${DNAME}")
  set(DEST "${CMAKE_CURRENT_BINARY_DIR}/${DNAME}/${SFILE}.c")
  set_property(SOURCE ${DEST} PROPERTY COMPILE_FLAGS " ${FLAG}")
  list(APPEND SRC ${DEST})
  set(SRC ${SRC} PARENT_SCOPE)
endfunction(build_variant)

foreach(SFILE ${SRC_MULTI})
  build_variant(${SFILE} "-DTAUCS_CORE_DOUBLE" "D")
  build_variant(${SFILE} "-DTAUCS_CORE_SINGLE" "S")
  build_variant(${SFILE} "-DTAUCS_CORE_DCOMPLEX" "Z")
  build_variant(${SFILE} "-DTAUCS_CORE_SCOMPLEX" "C")
  build_variant(${SFILE} "-DTAUCS_CORE_GENERAL" "G")
endforeach(SFILE)

foreach(SFILE ${SRC_DOUBLE})
  build_variant(${SFILE} "-DTAUCS_CORE_DOUBLE" "D")
endforeach(SFILE)

foreach(SFILE ${SRC_GENERAL})
  build_variant(${SFILE} "-DTAUCS_CORE_GENERAL" "G")
endforeach(SFILE)

include_directories(src config)

set (FLAGS "-std=c99 -fPIC")

if(UNIX)
  if(APPLE)
    set(FLAGS "${FLAGS} -DOSTYPE_darwin")
  else(APPLE)
    set(FLAGS "${FLAGS} -DOSTYPE_linux")
  endif(APPLE)
endif(UNIX)

if(WIN32)
  set(FLAGS "${FLAGS} -DOSTYPE_win32")
endif(WIN32)

add_library(taucs STATIC ${SRC})
set_property(TARGET taucs PROPERTY COMPILE_FLAGS ${FLAGS})
