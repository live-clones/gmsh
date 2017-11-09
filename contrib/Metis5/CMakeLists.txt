# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC
  auxapi.c
  balance.c 
  bucketsort.c
  checkgraph.c
  coarsen.c
  compress.c
  contig.c
  debug.c
  fm.c
  fortran.c
  frename.c
  gklib.c
  graph.c
  initpart.c
  kmetis.c
  kwayfm.c
  kwayrefine.c
  mcutil.c
  mesh.c
  meshpart.c
  minconn.c
  mincover.c
  mmd.c
  ometis.c
  options.c
 # parmetis.c
  pmetis.c
  refine.c
  separator.c
  sfm.c
  srefine.c
  stat.c
  timing.c
  util.c
  wspace.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/Metis5 "${SRC};${HDR}")
