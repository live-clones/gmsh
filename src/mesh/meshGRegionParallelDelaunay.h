// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_PARALLEL_DELAUNAY_H
#define MESH_GREGION_PARALLEL_DELAUNAY_H

// pdel3d: the parallel Delaunay mesher on flat arrays, the successor of
// del3d (meshGRegionDelaunay.cpp). The optimizer of its meshes is in
// meshGRegionParallelOptimize.h. The data layout and the parallel scheme
// follow HXT (C. Marot, J. Pellerin, J.-F. Remacle, "One machine, one minute,
// three billion tetrahedra", IJNME 2019): vertices are ordered along a Moore
// curve, each thread inserts the vertices of a contiguous piece of the curve
// and may only touch tetrahedra whose vertices all lie in that piece, and the
// convex hull is closed by ghost tetrahedra sharing a vertex at infinity.

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <map>
#include <memory>
#include <new>
#include <set>
#include <vector>
#include "robustPredicates.h"

namespace pdel3d {

  // 32-bit vertex indices; 64-bit tet indices and references, so that a
  // mesh can hold more than 2^30 tets (4 * tet + facet must fit)
  typedef std::uint32_t vIdx; // vertex index
  typedef std::uint64_t tIdx; // tetrahedron index
  typedef std::uint64_t tRef; // 4 * tetrahedron + facet
  constexpr vIdx GHOST = 0xffffffffu; // the vertex at infinity
  constexpr tRef NO_ADJ = ~0ull;
  constexpr tIdx NO_TET = ~0ull;
  constexpr std::uint64_t NO_LINE = ~0ull; // a line not in the mesh

  // flag bits of a tetrahedron, as in HXT
  constexpr std::uint16_t F_EDGE0 =
    0x1; // edge between facets 0 and 1 (nodes 2-3)
  constexpr std::uint16_t F_EDGE1 = 0x2; // facets 0-2 (nodes 1-3)
  constexpr std::uint16_t F_EDGE2 = 0x4; // facets 0-3 (nodes 1-2)
  constexpr std::uint16_t F_EDGE3 = 0x8; // facets 1-2 (nodes 0-3)
  constexpr std::uint16_t F_EDGE4 = 0x10; // facets 1-3 (nodes 0-2)
  constexpr std::uint16_t F_EDGE5 = 0x20; // facets 2-3 (nodes 0-1)
  constexpr std::uint16_t F_ALL_EDGES = 0x3f;
  constexpr std::uint16_t F_DELETED = 0x40;
  constexpr std::uint16_t F_PROCESSED = 0x80;
  constexpr std::uint16_t F_FACET0 = 0x100;
  constexpr std::uint16_t F_FACET1 = 0x200;
  constexpr std::uint16_t F_FACET2 = 0x400;
  constexpr std::uint16_t F_FACET3 = 0x800;
  constexpr std::uint16_t F_ALL_FACETS = 0xf00;
  constexpr std::uint16_t F_ALL_CONSTRAINTS = 0xf3f;
  constexpr std::uint16_t F_UNDELETE =
    0x1000; // scratch of the cavity reshaping
  constexpr std::uint16_t F_SPR_TRIED =
    0x2000; // the optimizer's reconnection could not improve the tet

  // the two facets sharing edge e, the two nodes of edge e, the edge between
  // two facets and the edge between two nodes (e is also the flag bit)
  inline void edgeFacets(int e, unsigned &f0, unsigned &f1)
  {
    static const unsigned fmin[6] = {0, 0, 0, 1, 1, 2},
                          fmax[6] = {1, 2, 3, 2, 3, 3};
    f0 = fmin[e];
    f1 = fmax[e];
  }
  inline void edgeNodes(int e, unsigned &n0, unsigned &n1)
  { edgeFacets(5 - e, n0, n1); }
  inline int edgeFromFacets(unsigned f0, unsigned f1)
  {
    static const int t[4][4] = {
      {-1, 0, 1, 2}, {0, -1, 3, 4}, {1, 3, -1, 5}, {2, 4, 5, -1}};
    return t[f0][f1];
  }
  inline int edgeFromNodes(unsigned n0, unsigned n1)
  { return 5 - edgeFromFacets(n0, n1); }

  // Nodes of facet f, in an order such that {node0, node1, node2, f} is an even
  // permutation of {0, 1, 2, 3}; a valid tetrahedron has orient3d(n0, n1, n2,
  // n3) < 0, i.e. orient3d(a, b, c, nf) < 0 for the nodes a, b, c of every
  // facet f
  inline unsigned facetNode0(unsigned f) { return (f + 1) & 3; }
  inline unsigned facetNode1(unsigned f) { return (f & 2) ^ 3; }
  inline unsigned facetNode2(unsigned f) { return (f + 3) & 2; }

  // a resizable array of a trivially copyable type, grown with realloc: a
  // large block is then remapped rather than copied, so that the old and the
  // new tet arrays are never both in memory
  template <class T> class PodVector {
  private:
    T *_data = nullptr;
    std::size_t _size = 0;

  public:
    PodVector() = default;
    PodVector(const PodVector &) = delete;
    PodVector &operator=(const PodVector &) = delete;
    ~PodVector() { std::free(_data); }
    std::size_t size() const { return _size; }
    bool empty() const { return !_size; }
    T &operator[](std::size_t i) { return _data[i]; }
    const T &operator[](std::size_t i) const { return _data[i]; }
    T *data() { return _data; }
    T *begin() { return _data; }
    T *end() { return _data + _size; }
    const T *begin() const { return _data; }
    const T *end() const { return _data + _size; }
    // the new entries are left uninitialized: the threads writing them first
    // also place their pages
    void resizeNoInit(std::size_t n)
    {
      if(!n) {
        clear();
        return;
      }
      if(n != _size) {
        T *p = (T *)std::realloc(_data, n * sizeof(T));
        if(!p) throw std::bad_alloc();
        _data = p;
      }
      _size = n;
    }
    void resize(std::size_t n, const T &value = T())
    {
      const std::size_t old = _size;
      resizeNoInit(n);
      for(std::size_t i = old; i < n; i++) _data[i] = value;
    }
    void assign(std::size_t n, const T &value)
    {
      resizeNoInit(n);
      std::fill(_data, _data + n, value);
    }
    // frees the memory
    void clear()
    {
      std::free(_data);
      _data = nullptr;
      _size = 0;
    }
  };

  struct Mesh {
    // vertices: x, y, z and the mesh size (<= 0: unknown), 4 doubles per vertex
    std::vector<double> xyz;
    // position of each vertex along the current Moore curve; the first
    // numDefaultDist entries are valid for the default (unshifted) curve on
    // the bounding box defaultBox, which saves recomputing them
    std::vector<std::uint64_t> dist;
    std::size_t numDefaultDist = 0;
    double defaultBox[6] = {0., 0., 0., 0., 0., 0.};
    // tetrahedra: the arrays are sized to the capacity, the first ntet slots
    // are in use (some of them flagged deleted until removeDeleted())
    std::size_t ntet = 0;
    PodVector<vIdx> node; // 4 per tet; a ghost vertex is always node 3
    PodVector<tRef> neigh; // 4 per tet
    PodVector<std::uint16_t> flag;
    // volume of the tet (COLOR_OUT: outside); left empty when not needed
    PodVector<std::uint32_t> color;

    static constexpr std::uint32_t COLOR_OUT = 0xffffffffu;

    std::size_t numVertices() const { return xyz.size() / 4; }
    std::size_t tetCapacity() const { return flag.size(); }
    void reserveTets(std::size_t n);
    // drop the deleted tets, keeping the order of the others
    void removeDeleted(int nthreads = 1);
    // number of tets not deleted and not ghosts
    std::size_t numRealTets() const;
    bool isGhost(tIdx t) const { return node[4 * t + 3] == GHOST; }
    bool isDeleted(tIdx t) const { return flag[t] & F_DELETED; }
    // bounding box of the vertices
    void bbox(double min[3], double max[3], int nthreads = 1) const;
    // drop the vertices not referenced by any tet, keeping the order of the
    // others; newIndex[v] receives the new index of vertex v or GHOST
    void removeUnusedVertices(std::vector<vIdx> &newIndex, int nthreads = 1);
    // sanity checks: node validity, orientation, adjacency symmetry, and
    // optionally the local Delaunay property across every facet; prints the
    // problems found and returns their number
    std::size_t verify(bool delaunay) const;
  };

  // constraints

  // facet of a tet (4 * tet + facet) carrying each triangle, NO_ADJ when the
  // triangle is not in the mesh; returns the number missing
  std::size_t triangleToTetMap(const Mesh &m, const std::vector<vIdx> &triNode,
                               std::vector<tRef> &tri2tet, int nthreads = 1);
  // edge of a tet (6 * tet + edge) carrying each line, NO_LINE when missing;
  // lines flagged in skip are not searched
  std::size_t lineToTetMap(const Mesh &m, const std::vector<vIdx> &lineNode,
                           const std::vector<std::uint8_t> &skip,
                           std::vector<std::uint64_t> &line2tet);
  // flag the lines that are edges of the triangles
  void linesInTriangles(const std::vector<vIdx> &triNode,
                        const std::vector<vIdx> &lineNode,
                        std::vector<std::uint8_t> &inTriangle);
  // set the facet constraint bits on both sides of each triangle, and the edge
  // constraint bits around each line
  void constrainFacets(Mesh &m, const std::vector<tRef> &tri2tet);
  void constrainEdges(Mesh &m, const std::vector<std::uint64_t> &line2tet);
  // recover the missing triangles and lines (tri2tet[i] == NO_ADJ,
  // line2tet[i] == NO_LINE with lineInTriangle[i] == 0) by local edge
  // removals: a missing edge is created by removing an edge around which its
  // two nodes are ring vertices, a missing facet by removing an edge around
  // which its three nodes are. The maps are updated for what was recovered,
  // the deleted tets removed; returns the number of items still missing
  std::size_t recoverLocally(Mesh &m, const std::vector<vIdx> &triNode,
                             const std::vector<vIdx> &lineNode,
                             const std::vector<std::uint8_t> &lineInTriangle,
                             std::vector<tRef> &tri2tet,
                             std::vector<std::uint64_t> &line2tet, int nthreads,
                             int verbosity);
  // color the tets: a flood fill bounded by the constrained facets gives the
  // connected volumes, which are matched to the given volumes through the set
  // of surface colors (triColor) bounding them: volume i gets color i, the
  // others get colors from volumes.size() up, the outside gets COLOR_OUT.
  // The sets are completed with the siblings of their surfaces (siblings[c]
  // lists the colors of the surfaces forming a compound with surface c)
  // before comparison. The two sides of a surface whose color is in embedded
  // are in the same volume. Returns false if some volume was not found
  bool colorVolumes(
    Mesh &m, const std::vector<tRef> &tri2tet,
    const std::vector<std::uint32_t> &triColor,
    const std::vector<std::vector<std::uint32_t>> &volumes,
    const std::map<std::uint32_t, std::vector<std::uint32_t>> &siblings,
    const std::set<std::uint32_t> &embedded, int nthreads = 1);

  // refinement

  struct RefineOptions {
    int numThreads = 1;
    // tets with a color at or above numVolumes are not refined
    std::uint32_t numVolumes = 0;
    double sizeMin = 0., sizeMax = 1.e300, sizeFactor = 1.;
    // optional size field: called on the candidate points (x, y, z, size
    // interpolated from the tet, 4 doubles each) and the color of their tets;
    // it overwrites the size
    void (*sizeCallback)(double *xyzs, const std::uint32_t *color,
                         std::size_t n, void *data) = nullptr;
    void *sizeData = nullptr;
    int curveFilterWindow = 16;
    int verbosity = 0;
  };

  // insert vertices in the volumes until the mesh matches the sizes stored in
  // xyz[4 * v + 3]; the tets must be colored and constrained
  void refine(Mesh &m, RefineOptions &opt);

  // Moore curve coordinate of a point, on a cube enclosing the bounding box
  // min-max; shift[3] in [0, 1] moves the center of the curve (default: the
  // center of the box), which changes the partitions between rounds
  struct MooreCurve {
    static constexpr double nmax = 2097152.; // 1 << 21 levels per axis
    double lo[3], middle[3], f0[3], f1[3], sub1[3];
    MooreCurve(const double min[3], const double max[3],
               const double *shift = nullptr);
    std::uint64_t key(const double *p) const;
  };

  // the Moore curve coordinate of the vertices from `first` on, in m.dist
  void mooreCurve(Mesh &m, const double min[3], const double max[3],
                  int nthreads, const double *shift = nullptr,
                  std::size_t first = 0);

  // Insertion status per vertex
  enum : std::uint8_t {
    ST_TODO = 0, // not inserted yet (or to be tried again)
    ST_INSERTED = 1,
    ST_FILTERED = 2, // skipped because too close to another vertex
    ST_DUPLICATE = 3 // skipped because it coincides with a vertex
  };

  struct DelaunayOptions {
    int numThreads = 1;
    // no facet/edge constraints exist in the mesh and none must be enforced
    bool perfectDelaunay = true;
    // allow inserting vertices in tets colored COLOR_OUT
    bool allowOuterInsertion = true;
    // filter the vertices on the mesh size stored in xyz[4 * v + 3]: a vertex
    // is not inserted when it is closer to an existing one than
    // factor * clamp(0.5 * (s0 + s1), sizeMin, sizeMax); a vertex with
    // unknown size gets the mean size of the vertices of its cavity
    bool filterOnSize = false;
    double sizeMin = 0., sizeMax = 1.e300, sizeFactor = 1.;
    // number of vertices kept along the curve a vertex is checked against
    int curveFilterWindow = 16;
    // 0: nothing is in the mesh yet; 1 - 0.5^n after n refinement rounds
    double partitionability = 0.;
    // number of vertices already in the mesh, when known (saves a scan)
    std::size_t numVerticesInMesh = (std::size_t)-1;
    // remove the deleted tets at the end (otherwise they stay as flagged
    // slots until the caller compacts the mesh)
    bool compact = true;
    // when the mesh is empty and all the vertices are inserted, store them
    // in insertion order (toInsert[i] then receives the original index of
    // vertex i), which keeps the coordinates read together close in memory
    bool reorderVertices = false;
    int verbosity = 0;
  };

  struct DelaunayStats {
    // filtered: by the size filter in their cavity; curveFiltered: by the size
    // filter against their predecessor along the curve
    std::size_t inserted = 0, filtered = 0, curveFiltered = 0;
    std::size_t rounds = 0;
    double timeSort = 0., timeInsert = 0.;
  };

  // Insert the vertices listed in toInsert into the mesh, creating the
  // triangulation (the first tet and its 4 ghosts) when the mesh has no tets.
  // The vertices must already be stored in m.xyz; m.dist is (re)computed
  // internally. The order of toInsert is changed. status[i] receives the
  // status of toInsert[i] (or of vertex i with opt.reorderVertices). Deleted
  // tets are removed at the end.
  // hints[i], if given, is a tet close to toInsert[i] (e.g. the one that
  // generated it) where its walk starts when it is still alive
  void insertVertices(Mesh &m, DelaunayOptions &opt,
                      std::vector<vIdx> &toInsert,
                      std::vector<std::uint8_t> &status,
                      DelaunayStats *stats = nullptr,
                      const std::vector<tIdx> *hints = nullptr);

  // shared by the parallel kernels: the partitions of the Moore curve, the
  // thread count throttled on the conflicts (after HXT), a parallel sort and
  // the fast orientation predicate

  // a contiguous piece of the (circular) curve, and the range of the sorted
  // work items it holds
  struct Partition {
    std::uint64_t startDist = 0, lengthDist = ~0ull;
    std::size_t firstElem = 0, numElem = 0;
  };

  // The sign of orient3d(a, b, r0, r1) for the valid tet t holding the four
  // nodes, from the parity of their positions: the ring of an edge (a, b) is
  // walked in a fixed direction, so that this sign is the same for all its
  // tets and fixes the orientation of the tets of a retriangulation of the
  // ring: for a triangle (r_i, r_j, r_l), i < j < l, orient3d(r_i, r_j, r_l,
  // a) has the opposite sign (and the b-side one the same sign).
  // Accepting whichever of the two is positive lets a triangle outside a
  // non-convex ring polygon through: positive tets covering existing ones
  // twice, while a gap elsewhere keeps the volumes adding up
  inline int ringOrientation(const Mesh &m, tIdx t, vIdx a, vIdx b, vIdx r0,
                             vIdx r1)
  {
    const vIdx *n = &m.node[4 * t];
    unsigned p[4] = {0, 0, 0, 0};
    for(unsigned q = 0; q < 4; q++) {
      if(n[q] == a) p[0] = q;
      if(n[q] == b) p[1] = q;
      if(n[q] == r0) p[2] = q;
      if(n[q] == r1) p[3] = q;
    }
    int inv = 0;
    for(int x = 0; x < 4; x++)
      for(int y = x + 1; y < 4; y++) inv += p[x] > p[y];
    return (inv & 1) ? 1 : -1; // the tet itself has orient3d < 0
  }

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

  // Sort the items on their dist member (ascending), in parallel: a sample
  // sort with 4 buckets per thread, each bucket sorted by one thread
  template <class T> void sortByDist(T *items, std::size_t n, int nthreads)
  {
    auto cmp = [](const T &a, const T &b) { return a.dist < b.dist; };
    if(nthreads < 2 || n < 65536) {
      std::sort(items, items + n, cmp);
      return;
    }
    const int nb = 4 * nthreads;
    const std::size_t ns = 64 * (std::size_t)nb;
    std::vector<std::uint64_t> sample(ns);
    for(std::size_t i = 0; i < ns; i++)
      sample[i] = items[(std::size_t)((i + 0.5) * n / ns)].dist;
    std::sort(sample.begin(), sample.end());
    std::vector<std::uint64_t> split(nb - 1);
    for(int b = 0; b + 1 < nb; b++) split[b] = sample[(b + 1) * ns / nb];
    // count[c * nb + b]: items of chunk c in bucket b, then where they go
    std::vector<std::size_t> count((std::size_t)nthreads * nb, 0);
    std::vector<std::size_t> bucketStart(nb + 1, 0);
    std::unique_ptr<T[]> tmp(new T[n]); // no serial initialization
    auto bucket = [&](std::uint64_t d) {
      return (int)(std::upper_bound(split.begin(), split.end(), d) -
                   split.begin());
    };
#pragma omp parallel num_threads(nthreads)
    {
#pragma omp for schedule(static)
      for(int c = 0; c < nthreads; c++) {
        std::size_t *cnt = &count[(std::size_t)c * nb];
        for(std::size_t i = c * n / nthreads; i < (c + 1) * n / nthreads; i++)
          cnt[bucket(items[i].dist)]++;
      }
#pragma omp single
      {
        std::size_t pos = 0;
        for(int b = 0; b < nb; b++) {
          bucketStart[b] = pos;
          for(int c = 0; c < nthreads; c++) {
            const std::size_t k = count[(std::size_t)c * nb + b];
            count[(std::size_t)c * nb + b] = pos;
            pos += k;
          }
        }
        bucketStart[nb] = pos;
      }
#pragma omp for schedule(static)
      for(int c = 0; c < nthreads; c++) {
        std::size_t *pos = &count[(std::size_t)c * nb];
        for(std::size_t i = c * n / nthreads; i < (c + 1) * n / nthreads; i++)
          tmp[pos[bucket(items[i].dist)]++] = items[i];
      }
#pragma omp for schedule(dynamic)
      for(int b = 0; b < nb; b++)
        std::sort(&tmp[bucketStart[b]], &tmp[0] + bucketStart[b + 1], cmp);
#pragma omp for schedule(static)
      for(std::size_t i = 0; i < n; i++) items[i] = tmp[i];
    }
  }

  inline std::uint32_t lcg(std::uint32_t &seed)
  {
    seed = seed * 1664525u + 1013904223u;
    return seed;
  }
  inline double lcg01(std::uint32_t &seed)
  { return lcg(seed) * (1. / 4294967296.); }

  // gmsh's gamma quality (3 inradius / circumradius) of the tet (p0, p1,
  // p2, p3) whose orientation determinant is det (negative when valid);
  // a facet by its sorted nodes, to match the facets of tets
  struct FacetKey {
    vIdx v0, v1, v2;
    tRef ref;
    FacetKey() = default;
    FacetKey(vIdx a, vIdx b, vIdx c, tRef r) : v0(a), v1(b), v2(c), ref(r)
    {
      if(v0 > v1) std::swap(v0, v1);
      if(v1 > v2) std::swap(v1, v2);
      if(v0 > v1) std::swap(v0, v1);
    }
    bool operator<(const FacetKey &o) const
    {
      if(v0 != o.v0) return v0 < o.v0;
      if(v1 != o.v1) return v1 < o.v1;
      return v2 < o.v2;
    }
    bool sameFacet(const FacetKey &o) const
    { return v0 == o.v0 && v1 == o.v1 && v2 == o.v2; }
  };

  // link the facets of new tets that match each other, among the nf keys
  // (those already linked have ref NO_ADJ)
  inline void linkFacets(PodVector<tRef> &neigh, FacetKey *facets, int nf)
  {
    for(int i = 0; i < nf; i++) {
      if(facets[i].ref == NO_ADJ) continue;
      for(int j = i + 1; j < nf; j++) {
        if(facets[j].ref != NO_ADJ && facets[j].sameFacet(facets[i])) {
          neigh[facets[i].ref] = facets[j].ref;
          neigh[facets[j].ref] = facets[i].ref;
          facets[j].ref = NO_ADJ;
          break;
        }
      }
    }
  }

  inline double sqDist(const double *a, const double *b)
  {
    const double dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
    return dx * dx + dy * dy + dz * dz;
  }

  // the mesh size filter: two points at squared distance d2 with sizes s0 and
  // s1 (0: unknown) are too close (opt: sizeMin, sizeMax, sizeFactor)
  template <class Options>
  inline bool tooClose(double s0, double s1, double d2, const Options &opt)
  {
    if(s0 > 0. && s1 > 0.) {
      const double s =
        std::min(opt.sizeMax, std::max(opt.sizeMin, 0.5 * (s0 + s1))) *
        opt.sizeFactor;
      return d2 < s * s;
    }
    return false;
  }

  // -1 for an inverted or flat tet
  inline double gammaQuality(const double *p0, const double *p1,
                             const double *p2, const double *p3, double det)
  {
    if(det >= 0.) return -1.;
    const double volume = -det / 6.;
    const double la = sqDist(p1, p0), lb = sqDist(p2, p0), lc = sqDist(p3, p0);
    const double lA = sqDist(p3, p2), lB = sqDist(p3, p1), lC = sqDist(p2, p1);
    const double lalA = std::sqrt(la * lA), lblB = std::sqrt(lb * lB),
                 lclC = std::sqrt(lc * lC);
    const double insideSqrt = (lalA + lblB + lclC) * (lalA + lblB - lclC) *
                              (lalA - lblB + lclC) * (-lalA + lblB + lclC);
    if(insideSqrt <= 0.) return 0.;
    const double partR = std::sqrt(insideSqrt) / 24.;
    auto area = [](const double *a, const double *b, const double *c) {
      const double u[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
      const double v[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
      const double n[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
                           u[0] * v[1] - u[1] * v[0]};
      return 0.5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    };
    const double s =
      area(p0, p1, p2) + area(p0, p2, p3) + area(p0, p1, p3) + area(p1, p2, p3);
    const double rho = 9. * volume / s;
    return rho * volume / partR;
  }

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

class MVertex;
class GRegion;
class MTetrahedron;

// Delaunay tetrahedralization of a point set with the parallel kernel; the
// vertices are not reordered, the tets reference them directly
void delaunayMeshIn3DParallel(std::vector<MVertex *> &v,
                              std::vector<MTetrahedron *> &tets);

// mesh the volumes of a group of connected regions with the parallel mesher;
// returns 0 on success, 2 if the input is not supported (the caller may fall
// back to another algorithm), 1 on error
int meshGRegionParallelDelaunay(std::vector<GRegion *> &regions);

#endif
