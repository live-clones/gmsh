// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PDEL3D_H
#define PDEL3D_H

// pdel3d: parallel Delaunay tetrahedralization on flat arrays, the successor
// of del3d. The data layout and the parallel scheme follow HXT (C. Marot,
// J. Pellerin, J.-F. Remacle, "One machine, one minute, three billion
// tetrahedra", IJNME 2019): vertices are ordered along a Moore curve, each
// thread inserts the vertices of a contiguous piece of the curve and may only
// touch tetrahedra whose vertices all lie in that piece, and the convex hull is
// closed by ghost tetrahedra sharing a vertex at infinity.

#include <cstdint>
#include <cstddef>
#include <vector>

namespace pdel3d {

  typedef std::uint32_t vIdx; // vertex index
  typedef std::uint32_t tIdx; // tetrahedron index
  typedef std::uint32_t tRef; // 4 * tetrahedron + facet
  constexpr vIdx GHOST = 0xffffffffu; // the vertex at infinity
  constexpr tRef NO_ADJ = 0xffffffffu;
  constexpr tIdx NO_TET = 0xffffffffu;

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

  // Nodes of facet f, in an order such that {node0, node1, node2, f} is an even
  // permutation of {0, 1, 2, 3}; a valid tetrahedron has orient3d(n0, n1, n2,
  // n3) < 0, i.e. orient3d(a, b, c, nf) < 0 for the nodes a, b, c of every
  // facet f
  inline unsigned facetNode0(unsigned f) { return (f + 1) & 3; }
  inline unsigned facetNode1(unsigned f) { return (f & 2) ^ 3; }
  inline unsigned facetNode2(unsigned f) { return (f + 3) & 2; }

  struct Mesh {
    // vertices: x, y, z and the mesh size (<= 0: unknown), 4 doubles per vertex
    std::vector<double> xyz;
    // position of each vertex along the current Moore curve
    std::vector<std::uint64_t> dist;
    // tetrahedra: the arrays are sized to the capacity, the first ntet slots
    // are in use (some of them flagged deleted until removeDeleted())
    std::size_t ntet = 0;
    std::vector<vIdx> node; // 4 per tet; a ghost vertex is always node 3
    std::vector<tRef> neigh; // 4 per tet
    std::vector<std::uint16_t> flag;
    // volume of the tet (COLOR_OUT: outside); left empty when not needed
    std::vector<std::uint32_t> color;

    static constexpr std::uint32_t COLOR_OUT = 0xffffffffu;

    std::size_t numVertices() const { return xyz.size() / 4; }
    std::size_t tetCapacity() const { return flag.size(); }
    void reserveTets(std::size_t n);
    // drop the deleted tets, keeping the order of the others
    void removeDeleted();
    // number of tets not deleted and not ghosts
    std::size_t numRealTets() const;
    bool isGhost(tIdx t) const { return node[4 * t + 3] == GHOST; }
    bool isDeleted(tIdx t) const { return flag[t] & F_DELETED; }
    // bounding box of the vertices
    void bbox(double min[3], double max[3]) const;
    // sanity checks: node validity, orientation, adjacency symmetry, and
    // optionally the local Delaunay property across every facet; prints the
    // problems found and returns their number
    std::size_t verify(bool delaunay, bool verbose = true) const;
  };

  // Moore curve coordinate of every vertex (or of the first n), on a cube
  // enclosing the bounding box; shift[3] in [0, 1] moves the center of the
  // curve, which changes the partitions between rounds
  void mooreCurve(Mesh &m, const double min[3], const double max[3],
                  const double *shift = nullptr, std::size_t n = 0);

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
    // 0: nothing is in the mesh yet; 1 - 0.5^n after n refinement rounds
    double partitionability = 0.;
    // when the mesh is empty and all the vertices are inserted, store them
    // in insertion order (toInsert[i] then receives the original index of
    // vertex i), which keeps the coordinates read together close in memory
    bool reorderVertices = false;
    int verbosity = 0;
  };

  struct DelaunayStats {
    std::size_t inserted = 0, filtered = 0, duplicates = 0, conflicts = 0;
    std::size_t rounds = 0;
    double timeSort = 0., timeInsert = 0.;
  };

  // Insert the vertices listed in toInsert into the mesh, creating the
  // triangulation (the first tet and its 4 ghosts) when the mesh has no tets.
  // The vertices must already be stored in m.xyz; m.dist is (re)computed
  // internally. The order of toInsert is changed. status[i] receives the
  // status of toInsert[i] (or of vertex i with opt.reorderVertices). Deleted
  // tets are removed at the end.
  void insertVertices(Mesh &m, DelaunayOptions &opt,
                      std::vector<vIdx> &toInsert,
                      std::vector<std::uint8_t> &status,
                      DelaunayStats *stats = nullptr);

} // namespace pdel3d

#endif
