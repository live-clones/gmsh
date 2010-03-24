# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  gmp_normal_form.cpp
  gmp_matrix_io.cpp
  gmp_matrix.cpp
  gmp_blas.cpp
  mpz.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/kbipack "${SRC};${HDR}")
