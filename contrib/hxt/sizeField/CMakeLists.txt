# this project is a little bit special, as it needs to be part of GMSH build tree

if(NOT HAVE_P4EST)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

	find_library(P4EST_LIB p4est)
	find_path(P4EST_INC "p4est.h" PATH_SUFFIXES src)
	if((NOT P4EST_LIB) OR (NOT P4EST_INC))
		message(FATAL_ERROR "P4EST library not found")
	else()
		message("found P4est library (${P4EST_LIB})")
	endif()
endif()

append_gmsh_src(contrib/hxt/sizeField "hxt_octree.cpp;hxt_octree.h")
