# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC 
  b64.c
  blas.c
  csr.c
  error.c
  evaluate.c
  fkvkselect.c
  fs.c
  getopt.c
  gkregex.c
  graph.c
  htable.c
  io.c
  itemsets.c
  mcore.c
  memory.c
  omp.c
  pdb.c
  pqueue.c
  random.c
  rw.c
  seq.c
  sort.c
  string.c
  timers.c
  tokenizer.c
  util.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/Metis5/GKlib "${SRC};${HDR}")
