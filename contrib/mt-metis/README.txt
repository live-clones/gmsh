This directory contains a subset of Dominique LaSalle's mt-metis, a
multithreaded (OpenMP) version of the METIS graph partitioner, version 0.6.0
(mt-metis-0.6.0.tar.gz, sha256
cb8fb836b630a899edbeca4e1da19ec9eb47e89903bda83e7ec62cb0ffdcc284, from the
Spack source mirror: the upstream sites are no longer available), with only
the library: src/ (without mtmetis_bin.c), include/ and domlib/. The bundled
METIS (a 2014 development version of METIS 5.1 with renamed symbols), the
wildriver graph I/O library, the command line tool and the tests are left
out: mt-metis calls the METIS of contrib/metis (or the system METIS) for the
initial partitioning of the coarsest graph.

The files are unmodified copies of the upstream files, except:

* include/mtmetis.h: MTMETIS_64BIT_EDGES is defined (64-bit edge indices, as
  the dual graphs of meshes of a billion elements have more than 2^32 edges)
* src/imetis.c: includes <metis.h> and calls the METIS_ functions instead of
  the renamed __METIS_ functions of the bundled METIS
* src/vseprefine.c: METIS_NodeRefine() gets copies of the weights, parts and
  locks as idx_t arrays instead of casts of the pointers (idx_t is 64-bit in
  Gmsh)
* domlib/dlmacros.h: _mm_pause() only uses the x86 "pause" instruction on x86
  ("yield" on ARM)
* domlib/dllcb_funcs.h: the lock-free communication lists use __atomic
  release stores and acquire loads (and sequentially consistent termination
  flags) instead of plain stores and volatile flags, which crash on weakly
  ordered processors (ARM) with 4 threads or more
* domlib/dlthread.c: the flags of the custom tree barrier use __atomic release
  stores and acquire loads, for the same reason

METIS_ComputeVertexSeparator() and METIS_NodeRefine(), used by mt-metis for
vertex separators and nested dissection, are in contrib/metis/libmetis/parmetis.c.
