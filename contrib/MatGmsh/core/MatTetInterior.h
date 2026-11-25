// Interior tetrahedra of the Delaunay triangulation of the skin nodes, the
// unmerged dual complex they carry, and the certificate of their boundary.
//
// All indices are zero-based. Nothing here uses a tolerance: a tetrahedron is
// interior if and only if its exact volume is nonzero and the integer winding
// number of the closed skin at its barycentre is resolved and odd. A
// barycentre in contact with the skin (exactly, or within the roundoff of its
// own evaluation) is exterior by convention and counted apart.
//
// Odd rather than nonzero: each connected component of the skin is oriented
// consistently, but not the components relative to each other (the shell of a
// closed cavity may be oriented like the outer shell, which gives a winding
// number of two in the void). The parity does not depend on these choices: a
// point is in the material iff an odd number of shells enclose it. With a
// winding number in {-1, 0, 1} both rules are the same.
#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "gmsh.h" // GMSH_API

namespace matgmsh {
namespace tet {

// Certificate of an indexed triangle surface.
struct Surface {
  std::size_t vertices = 0, edges = 0, faces = 0, components = 0;
  // Edges not shared by exactly two triangles, vertices whose link is not one
  // circle, edges traversed twice in the same direction, unused sites.
  std::size_t badEdges = 0, badVertices = 0, badOrientations = 0, missingSites = 0;
  long long euler = 0;
  bool closedManifold = false, oriented = false;
};

enum Status : std::uint8_t {
  Resolved = 0,         // winding number known
  ExactContact = 1,     // barycentre exactly on a skin triangle
  NumericalContact = 2, // contact not excluded by the roundoff bound
  Unresolved = 3,       // every deterministic ray was degenerate
  ZeroVolume = 4        // no query: exactly flat tetrahedron
};

struct Classification {
  std::vector<unsigned char> interior; // one flag per tetrahedron
  std::vector<signed char> volumeSign; // exact sign of orient3d
  std::vector<int> winding;            // signed crossings, 0 unless Resolved
  std::vector<std::uint8_t> status;
};

// Unmerged dual complex: one vertex per tetrahedron, one polygon per Delaunay
// edge whose incident tetrahedra are all interior. Polygons are sorted by site
// pair; each cycle starts at its smallest tetrahedron.
struct Dual {
  std::vector<std::array<int, 2> > sitePair;
  std::vector<std::size_t> offsets; // polygons + 1 entries
  std::vector<int> cycles;          // tetrahedron ids
  // All-interior edges without a polygon: on the convex hull, or with a link
  // that is not one simple cycle (counted, never repaired).
  std::size_t hullEdges = 0, invalidLinks = 0;
  std::size_t size() const { return sitePair.size(); }
};

struct ComplexTopology {
  std::size_t vertices = 0, edges = 0, faces = 0, components = 0;
  std::size_t freeEdges = 0, junctionEdges = 0;
  long long euler = 0;
};

struct Report {
  bool computed = false, certified = false;
  std::size_t sites = 0, tetrahedra = 0, interior = 0;
  std::size_t zeroVolume = 0, exactContact = 0, numericalContact = 0, unresolved = 0;
  std::size_t polygons = 0, hullEdges = 0, invalidLinks = 0;
  std::size_t boundaryFacesOverValenceTwo = 0;
  Surface skin, boundary; // boundary of the union of the interior tetrahedra
  ComplexTopology dual;
};

GMSH_API Surface certifySurface(const std::vector<int> &triangles, std::size_t sites);

// Throws if the skin is not a closed oriented manifold. Needs the robust
// predicates initialized (Gmsh does it at startup). The result does not
// depend on the number of threads.
GMSH_API Classification classify(const std::vector<double> &xyz, const std::vector<int> &skin,
                        const std::vector<int> &tetrahedra, unsigned threads = 1);

GMSH_API Dual buildDual(const std::vector<int> &tetrahedra, const std::vector<unsigned char> &interior,
               std::size_t sites);

// For each skin triangle: +1 if it is oriented away from the material, -1 if
// towards it, 0 if it is not a boundary face of the interior tetrahedra (the
// Delaunay triangulation may use the other diagonal of a flat quadrilateral).
GMSH_API std::vector<signed char> skinSides(const std::vector<int> &skin,
                                            const std::vector<int> &tetrahedra,
                                            const Classification &classification);

// Topology of the polygons selected by keep (all of them if null).
GMSH_API ComplexTopology topology(const Dual &dual, const std::vector<unsigned char> *keep = nullptr);

// certified: the boundary of the interior tetrahedra is a closed oriented
// manifold through every site with the Euler characteristic of the skin, every
// selected link is a cycle, and the dual has half that Euler characteristic.
GMSH_API Report certify(const std::vector<int> &skin, const std::vector<int> &tetrahedra,
               const Classification &classification, const Dual &dual, std::size_t sites);

} // namespace tet
} // namespace matgmsh
