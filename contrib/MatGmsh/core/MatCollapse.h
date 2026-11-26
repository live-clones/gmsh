// Filter of the unmerged dual complex by elementary collapses: a polygon with
// a free edge is removed, together with that edge, when its erosion thickness
// is below a fraction of the part thickness or when it belongs to an anchored
// convex wing (the sheet running from a convex CAD edge into the material).
// Elementary collapses keep the homotopy type of the complex.
#pragma once
#include "MatErosion.h"

namespace matgmsh {
namespace tet {

// A mesh segment of a CAD curve, between two sites of the skin.
struct Segment {
  int a = -1, b = -1;           // sites, a < b
  int patchA = -1, patchB = -1; // patches of its two skin triangles, -1 if unknown
  int sign = 2;                 // +1 convex, -1 concave, 0 flat, 2 unknown
};

struct SkinSegments {
  std::vector<Segment> segments; // by (a, b), then in the given order
  // The sign of a dihedral needs the material side of the skin; true when it
  // is known on every shell.
  bool materialSide = false;
};

// curves: the two sites of each mesh segment of the CAD curves;
// trianglePatch: the patch of each skin triangle, -1 if unknown;
// side: orientation of each skin triangle with respect to the material (see
// skinSides), which gives the material side of each shell. If empty, the sign
// of the volume is used, for a single closed shell only.
GMSH_API SkinSegments skinSegments(const std::vector<double> &sites, const std::vector<int> &skin,
                                   const std::vector<int> &trianglePatch,
                                   const std::vector<std::array<int, 2> > &curves,
                                   const std::vector<signed char> &side =
                                     std::vector<signed char>());

struct Wings {
  // convex: the nearest CAD segment common to the patches of the two sites of
  // the polygon is convex. wing: convex, and connected through convex polygons
  // of the same patch pair to a free edge that touches such a segment.
  std::vector<unsigned char> convex, wing;
  std::size_t components = 0, anchored = 0;
};

// patchOffsets/patchValues: sorted distinct patches of the CAD faces around
// each site. tetrahedra: zero-based, one per vertex of the dual.
GMSH_API Wings wings(const Dual &dual, const Adjacency &graph, const Geometry &geometry,
                     const std::vector<double> &sites,
                     const std::vector<std::size_t> &patchOffsets,
                     const std::vector<int> &patchValues, const std::vector<Segment> &segments,
                     const std::vector<int> &tetrahedra);

// The wings of the complex beyond those of the convex CAD curves, from the
// angle under which each polygon sees its two sites from its centroid: 90
// degrees on the sheet that runs from a right-angled convex edge of the solid
// into the material, 180 between two facing walls. A polygon under `angle`
// degrees is a wing when one of the two holds:
//
//   - it burns like the wing of a wedge. On the bisector sheet of a wedge, at
//     the place seen under the angle a, the erosion thickness (burn time
//     minus radius) is R (1 - cos(a/2)) / cos(a/2); the polygon qualifies up
//     to one and a half times that, plus its own size. The strip of a
//     mid-sheet along a junction is also seen under a small angle, but it
//     burns late, from far away: it stays. Near the ends of the junction it
//     does burn early: the margins of the walls are left out, that is the
//     sets of polygons under the angle (connected through the edges of two
//     polygons) that touch polygons over the angle across such an edge and
//     have less than a quarter of the length of their boundary free. A wing
//     that goes on from a wall touches it too, with about half of its
//     boundary free.
//   - it belongs to a wing branch. A branch is a set of polygons connected
//     through edges shared by exactly two polygons; a wing branch touches the
//     free boundary of the complex (it has an edge of a single polygon) and
//     at least nine tenths of its area is under the angle. All its polygons
//     are wings, whatever they burn like and their own angle.
//
// (A branch can hold a wall and the wings that go on from it without a
// junction: with half of the area for a wing branch, the wall was removed with
// them, or the wings kept with it, depending on the mesh.)
struct BranchWings {
  std::vector<unsigned char> wing; // one flag per polygon
  // For each polygon: whether it can be removed as a wing for some angle (it
  // burns like one, or its branch is a wing branch), and the angle under
  // which it sees its sites, in degrees (NaN without area).
  std::vector<unsigned char> candidate;
  std::vector<double> angle;
  std::size_t branches = 0, wingBranches = 0, wedgePolygons = 0;
};

// vertices: of the dual, three coordinates per tetrahedron; burnTimes: one
// per polygon (see burnTimes).
GMSH_API BranchWings branchWings(const Dual &dual, const Adjacency &graph,
                                 const Geometry &geometry, const std::vector<double> &sites,
                                 const std::vector<double> &vertices,
                                 const std::vector<double> &burnTimes, double angle = 135.);

struct Collapse {
  std::vector<unsigned char> keep; // one flag per polygon
  std::size_t eligible = 0, removed = 0, blocked = 0, wingsBlocked = 0;
  // Edges left without polygon once the dangling trees are pruned: the kept
  // polygons alone do not have the homotopy type of the complex.
  std::size_t wireEdges = 0;
};

// Removes, by increasing erosion thickness, the polygons with a free edge that
// are wings or below the threshold. The set removed does not depend on the
// order. A NaN erosion thickness is never eligible.
GMSH_API Collapse collapse(const Dual &dual, const Adjacency &graph,
                           const std::vector<double> &erosionOverThickness,
                           const std::vector<unsigned char> &wing, double threshold);

struct FilterInput {
  const std::vector<double> *sites = nullptr, *vertices = nullptr;
  const std::vector<int> *skin = nullptr, *tetrahedra = nullptr;
  std::vector<int> trianglePatch;
  std::vector<signed char> skinSide; // see skinSegments
  std::vector<std::array<int, 2> > curves;
  std::vector<std::size_t> patchOffsets;
  std::vector<int> patchValues;
  double thickness = 1., threshold = .21;
  // The wings found from the angle of the polygons (see branchWings) are
  // removed like the convex wings, whatever their erosion thickness.
  bool wingBranches = false;
  double branchAngle = 135.;
};

struct CollapseReport {
  bool computed = false, materialSide = false;
  double thickness = 0., threshold = 0.;
  std::size_t curveSegments = 0, convexSegments = 0;
  std::size_t zeroAreaPolygons = 0, unreachedPolygons = 0;
  std::size_t convexPolygons = 0, wingComponents = 0, anchoredWingComponents = 0;
  std::size_t wingPolygons = 0, eligible = 0, removed = 0, blocked = 0, wingsBlocked = 0;
  // with FilterInput::wingBranches: the branches of the raw MAT, those that
  // are wings, the polygons that burn like a wing under the angle, and the
  // polygons of both kinds that the convex wings did not hold already
  std::size_t branches = 0, wingBranches = 0, wedgePolygons = 0, branchWingPolygons = 0;
  std::size_t wireEdges = 0;
  ComplexTopology surface; // the kept polygons
};

struct Filtered {
  std::vector<unsigned char> keep, wing;
  // of each polygon, see BranchWings
  std::vector<unsigned char> wingCandidate;
  std::vector<double> contactAngle;
  std::vector<double> erosionOverThickness;
  Geometry geometry;
  CollapseReport report;
};

GMSH_API Filtered filter(const Dual &dual, const FilterInput &input);

} // namespace tet
} // namespace matgmsh
