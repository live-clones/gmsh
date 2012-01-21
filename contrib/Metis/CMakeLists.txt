# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  balance.c 
  fm.c        
  kwayfm.c    
  mcoarsen.c  
  minitpart2.c 
  mpmetis.c   
  pmetis.c     
  subdomains.c
  bucketsort.c  
  fortran.c  
  kwayrefine.c
  memory.c  
  minitpart.c  
  mrefine2.c
  pqueue.c
  timing.c
  ccgraph.c 
  frename.c 
  kwayvolfm.c
  mesh.c
  mkmetis.c
  mrefine.c 
  refine.c  
  util.c
  coarsen.c 
  graph.c
  kwayvolrefine.c  
  meshpart.c  
  mkwayfmh.c 
  mutil.c 
  separator.c
  compress.c
  initpart.c
  match.c
  mfm2.c 
  mkwayrefine.c
  myqsort.c
  sfm.c
  debug.c 
  kmetis.c  
  mbalance2.c
  mfm.c  
  mmatch.c 
  ometis.c 
  srefine.c
  estmem.c 
  kvmetis.c
  mbalance.c 
  mincover.c  
  mmd.c  
#  parmetis.c 
  stat.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/Metis "${SRC};${HDR}")
