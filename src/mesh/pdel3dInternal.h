// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PDEL3D_INTERNAL_H
#define PDEL3D_INTERNAL_H

// Shared by the parallel kernels of pdel3d: the partitions of the Moore
// curve, and the thread count throttled on the conflicts (after HXT)

#include <algorithm>
#include <cstdint>
#include <vector>
#include "pdel3d.h"
#include "robustPredicates.h"

namespace pdel3d {

  // a contiguous piece of the (circular) curve, and the range of the sorted
  // work items it holds
  struct Partition {
    std::uint64_t startDist = 0, lengthDist = ~0ull;
    std::size_t firstElem = 0, numElem = 0;
  };

  inline bool outOfPartition(const Mesh &m, vIdx v, const Partition &p)
  { return (m.dist[v] - p.startDist) >= p.lengthDist; }

  // a tet lies in the partition if all its real nodes do
  inline bool tetInPartition(const Mesh &m, tIdx t, const Partition &p)
  {
    const vIdx *n = &m.node[4 * t];
    if(outOfPartition(m, n[0], p) || outOfPartition(m, n[1], p) ||
       outOfPartition(m, n[2], p))
      return false;
    return n[3] == GHOST || !outOfPartition(m, n[3], p);
  }

  // Cut the sorted items (dist[i] ascending, todo[i] nonzero for the ones to
  // process) in nthreads pieces of about the same number of items to do,
  // starting at a fraction startShift of the first piece and only where the
  // curve coordinate changes; returns the number of pieces made (1 means no
  // partitioning: the single partition covers everything)
  inline int makePartitions(const std::uint64_t *dist, const std::uint8_t *todo,
                            std::size_t n, std::size_t numTodo, int nthreads,
                            double startShift, std::vector<Partition> &parts)
  {
    if(nthreads > 1 && n > 1) {
      const std::size_t perThread = numTodo / nthreads + 1;
      std::size_t counter = perThread;
      int tid = 0;
      const std::size_t offset = (std::size_t)(startShift * n / nthreads);
      for(std::size_t i = 0; i < n && tid < nthreads; i++) {
        const std::size_t index = (offset + i) % n;
        const std::uint64_t d = dist[index];
        if(counter >= perThread) {
          const std::uint64_t prev = dist[(index + n - 1) % n];
          if(d != prev) {
            parts[tid].firstElem = index;
            parts[tid].startDist = prev + (d - prev + 1) / 2;
            counter = 0;
            tid++;
          }
        }
        if(todo[index]) counter++;
      }
      if(tid > 1) {
        for(int t = 0; t < tid; t++) {
          Partition &P = parts[t];
          const Partition &N = parts[(t + 1) % tid];
          P.numElem = (N.firstElem + n - P.firstElem) % n;
          P.lengthDist = N.startDist - P.startDist;
        }
        return tid;
      }
    }
    parts[0] = Partition();
    parts[0].numElem = n;
    return 1;
  }

  // halve the threads when the conflicts are too many, and keep at least
  // smallestPass items per thread
  inline int computeNumberOfThreads(double conflictRatio, int numThreads,
                                    std::size_t numElem,
                                    std::size_t smallestPass)
  {
    const double maxBorders = 8.;
    if(conflictRatio >
       (numThreads - 1) * maxBorders / (numThreads * (maxBorders + 1) - 2.))
      numThreads = (numThreads + 1) / 2;
    int maxThreadsInRound = 1;
    std::size_t tmp = numElem / smallestPass;
    while(tmp > 1 && maxThreadsInRound < numThreads) {
      tmp /= 2;
      maxThreadsInRound *= 2;
    }
    return std::min(maxThreadsInRound, numThreads);
  }

  inline std::uint32_t lcg(std::uint32_t &seed)
  {
    seed = seed * 1664525u + 1013904223u;
    return seed;
  }
  inline double lcg01(std::uint32_t &seed)
  { return lcg(seed) * (1. / 4294967296.); }

  // the plain floating-point determinants, decided by the static filters of
  // robustPredicates (set by exactinit), with the adaptive exact evaluation
  // as fallback: inlined, the common case is a few dozen flops
  inline double orient3dFast(const double *pa, const double *pb,
                             const double *pc, const double *pd)
  {
    const double adx = pa[0] - pd[0], bdx = pb[0] - pd[0], cdx = pc[0] - pd[0];
    const double ady = pa[1] - pd[1], bdy = pb[1] - pd[1], cdy = pc[1] - pd[1];
    const double adz = pa[2] - pd[2], bdz = pb[2] - pd[2], cdz = pc[2] - pd[2];
    const double det = adx * (bdy * cdz - bdz * cdy) +
                       bdx * (cdy * adz - cdz * ady) +
                       cdx * (ady * bdz - adz * bdy);
    if(det > robustPredicates::o3dstaticfilter ||
       -det > robustPredicates::o3dstaticfilter)
      return det;
    return robustPredicates::orient3d(pa, pb, pc, pd);
  }

} // namespace pdel3d

#endif
