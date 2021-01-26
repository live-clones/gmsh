# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  GKlib/b64.c
  GKlib/blas.c
  GKlib/csr.c
  GKlib/error.c
  GKlib/evaluate.c
  GKlib/fkvkselect.c
  GKlib/fs.c
  GKlib/getopt.c
  GKlib/gkregex.c
  GKlib/graph.c
  GKlib/htable.c
  GKlib/io.c
  GKlib/itemsets.c
  GKlib/mcore.c
  GKlib/memory.c
  GKlib/omp.c
  GKlib/pdb.c
  GKlib/pqueue.c
  GKlib/random.c
  GKlib/rw.c
  GKlib/seq.c
  GKlib/sort.c
  GKlib/string.c
  GKlib/timers.c
  GKlib/tokenizer.c
  GKlib/util.c
  libmetis/auxapi.c
  libmetis/balance.c 
  libmetis/bucketsort.c
  libmetis/checkgraph.c
  libmetis/coarsen.c
  libmetis/compress.c
  libmetis/contig.c
  libmetis/debug.c
  libmetis/fm.c
  libmetis/fortran.c
  libmetis/frename.c
  libmetis/gklib.c
  libmetis/graph.c
  libmetis/initpart.c
  libmetis/kmetis.c
  libmetis/kwayfm.c
  libmetis/kwayrefine.c
  libmetis/mcutil.c
  libmetis/mesh.c
  libmetis/meshpart.c
  libmetis/minconn.c
  libmetis/mincover.c
  libmetis/mmd.c
  libmetis/ometis.c
  libmetis/options.c
 # libmetis/parmetis.c
  libmetis/pmetis.c
  libmetis/refine.c
  libmetis/separator.c
  libmetis/sfm.c
  libmetis/srefine.c
  libmetis/stat.c
  libmetis/timing.c
  libmetis/util.c
  libmetis/wspace.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/metis "${SRC};${HDR}")
