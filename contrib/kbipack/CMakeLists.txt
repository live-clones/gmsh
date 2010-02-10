# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  gmp_normal_form.c
  gmp_matrix_io.c
  gmp_matrix.c
  gmp_blas.c
  mpz.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_SOURCE_DIR}/contrib/kbipack *.h)
append_gmsh_src(contrib/kbipack "${SRC};${HDR}")
