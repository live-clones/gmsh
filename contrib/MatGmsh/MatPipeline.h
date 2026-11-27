// Native filtered MAT pipeline. Source geometry and all mesh indices are kept
// separate from GModel entity tags; junction vertices have one global identity.
#ifndef GMSH_MAT_PIPELINE_H
#define GMSH_MAT_PIPELINE_H

#include <cstddef>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "gmsh.h"
#include "core/MatCollapse.h"

class GModel;

namespace matgmsh_native {

struct Mesh {
  std::vector<double> xyz;
  std::vector<int> triangles;
  std::vector<int> branch; // one branch per triangle
  std::vector<int> parent; // original polygon/triangle, -1 for new material
  // of the MAT meshes (raw, filtered), one per node: the radius of the ball
  // of the MAT centred there (the distance to the two sites of the Voronoi
  // polygon it is on); empty for the other meshes
  std::vector<double> radius;
};

enum class Stage { Filtered, Projected, Extended };

// Raw MAT. Tet (default): dual faces of the Delaunay edges surrounded by
// interior tetrahedra only (integer winding at the barycentre), with a
// certificate of the boundary of their union. Legacy: dual faces whose
// circumcentres have a winding number above the threshold, coincident
// circumcentres merged.
enum class RawMode { Legacy, Tet };
// Collapse (default): erosion thickness and homotopy-preserving collapse
// (needs RawMode::Tet). Legacy: branch classification by CAD patches (needs
// RawMode::Legacy). None: the raw MAT.
enum class FilterMode { Legacy, Collapse, None };

struct Options {
  double thickness = 1.;
  double windingThreshold = .5;
  RawMode raw = RawMode::Tet;
  FilterMode filter = FilterMode::Collapse;
  // FilterMode::Collapse: polygons with an erosion thickness below this
  // fraction of the thickness are removed.
  double collapseThreshold = .21;
  // FilterMode::Collapse: the wings of the raw MAT found from the angle under
  // which its polygons see their two contacts (see
  // matgmsh::tet::branchWings: the polygons that burn like a wing, and the
  // branches made of them) are removed, whatever their erosion thickness.
  bool wingBranches = false;
  // the angle (degrees) under which a wing sees its contacts, at most: 90
  // for the wing of a right-angled edge, 180 between two walls
  double branchAngle = 135.;
  // RawMode::Tet: if nonempty, the dual complex and its attributes are written
  // to this directory as NumPy arrays (see README.txt).
  std::string complexDirectory;
  bool project = false;
  bool legacyCleanup = true;
  Stage stopAfter = Stage::Filtered;
  double extensionLength = 0.; // zero means 3 * thickness
  int extensionLayers = 12;
};

struct Topology {
  std::size_t vertices = 0, triangles = 0, components = 0;
  std::size_t freeEdges = 0, junctionEdges = 0;
  long long euler = 0;
};

struct FrontStatus {
  int a = -1, b = -1, branch = -1;
  std::string status; // already_on_skin, reached_skin, reached_sheet, unresolved
  std::string reason;
};

struct ExtensionReport {
  std::vector<FrontStatus> fronts;
  std::size_t addedTriangles = 0;
  bool complete = false;
  std::string message;
};

struct Result {
  Mesh skin, raw, filtered, projected, extended;
  Topology filteredTopology;
  matgmsh::tet::Report tet;              // RawMode::Tet only
  matgmsh::tet::CollapseReport collapse; // FilterMode::Collapse only
  // FilterMode::Collapse, for each polygon of the raw MAT (Mesh::parent of
  // raw): whether it can be removed as a wing for some angle, and the angle
  // under which it sees its two contacts with the skin, in degrees (see
  // matgmsh::tet::BranchWings)
  std::vector<unsigned char> wingCandidate;
  std::vector<double> contactAngle;
  std::string projectionStatus = "disabled";
  std::string projectionMessage;
  ExtensionReport extension;
  double rawSeconds = 0., filterSeconds = 0., projectionSeconds = 0.;
  double extensionSeconds = 0.;
  std::vector<std::string> warnings;
};

// Consume the current model's existing first-order surface mesh. The caller
// retains ownership of the CAD and chooses its mesh sizing separately.
GMSH_API bool compute(GModel *source, const Options &options, Result &result,
             std::string &error);
GMSH_API bool computeCurrent(const Options &options, Result &result,
                            std::string &error);
// The current model, for the callers that only see the API.
GMSH_API GModel *currentModel();

// The pipeline one stage at a time, for interactive use. The raw MAT is kept
// between the calls: the filter can be run again with another threshold, and
// the projection and the extension run or run again, without a new Delaunay
// tetrahedrization. compute() is these stages in a row.
//
// Each stage needs the ones before it, and running a stage again discards
// the results of the later ones. filter() and project() refuse a model whose
// surface mesh is not the one given to raw().
class GMSH_API Session {
public:
  Session();
  ~Session();
  Session(const Session &) = delete;
  Session &operator=(const Session &) = delete;
  // Raw MAT of the first-order triangular surface mesh of the model
  // (options: thickness, raw, windingThreshold).
  bool raw(GModel *source, const Options &options, std::string &error);
  // Filtered MAT (options: thickness, filter, collapseThreshold,
  // legacyCleanup, complexDirectory). The legacy filter changes the raw MAT
  // in place: running it again computes the raw MAT again.
  bool filter(GModel *source, const Options &options, std::string &error);
  // Projection of the filtered MAT if options.project is set; a projection
  // that is refused keeps the filtered MAT, and says why in the result.
  bool project(GModel *source, const Options &options, std::string &error);
  // Extension of the projected MAT (of the filtered one if project() was not
  // called) to the skin (options: thickness, extensionLength,
  // extensionLayers). A failed extension keeps its input and is reported in
  // the result.
  bool extend(GModel *source, const Options &options, std::string &error);
  bool hasRaw() const;
  bool hasFiltered() const;
  bool hasProjected() const;
  bool hasExtended() const;
  // The meshes and reports of the stages available.
  const Result &result() const;
  // The same, moved out of the session, which is left empty.
  Result take();

private:
  struct Data;
  std::unique_ptr<Data> data_;
};

GMSH_API Topology topology(const Mesh &mesh);
GMSH_API bool validateMesh(const Mesh &mesh, std::string &error);
// Exact final-configuration intersection check, including coplanar overlaps;
// shared indexed vertices/edges at sheet junctions are valid. No swept check.
GMSH_API bool validateNoSelfIntersections(const Mesh &mesh, std::string &error);
// Co-refine against the closed skin and verify every original triangle remains
// inside, with its area preserved. The input mesh is never changed.
GMSH_API bool validateContainedInSkin(const Mesh &mesh, const Mesh &skin,
                                    std::string &error);
// With nodeData (one value per node), its finite values as $NodeData
// `dataName'.
GMSH_API bool writeMesh(const Mesh &mesh, const std::string &filename,
               std::string &error, const std::vector<double> *nodeData = nullptr,
               const std::string &dataName = "");
GMSH_API bool writeReport(const Result &result, const Options &options,
                 const std::string &filename, std::string &error);

// A branch of a MAT mesh (the triangles with one value of Mesh::branch) and
// its least-squares plane: area, the distance to the plane below which 95% of
// its area lies, and the largest one.
struct BranchPlane {
  int branch = -1;
  std::size_t triangles = 0;
  double area = 0.;
  double origin[3] = {0., 0., 0.}, normal[3] = {0., 0., 1.};
  double deviation = 0., maxDeviation = 0.;
};

// The branches of the mesh, largest first.
GMSH_API std::vector<BranchPlane> branchPlanes(const Mesh &mesh);

struct PlaneExtension {
  // The rectangle of the plane around the skin, cut by the skin and by the
  // other branches: Mesh::branch is 0 on the fragments kept, then 1, 2... by
  // decreasing area on the others.
  Mesh plane;
  // The MAT with the branch replaced by the kept fragments, under the same
  // branch number, and without the branches in `merged`.
  Mesh result;
  // The other branches that lay in the plane inside a kept fragment.
  std::vector<int> merged;
  std::size_t cutters = 0, fragments = 0, keptFragments = 0, addedTriangles = 0;
  // the reentrant corners of the section of the skin by the plane, and the
  // faces prolonged there into the material to bound the fragments
  std::size_t corners = 0, fences = 0;
  // the sheets of other branches that ended in the plane just short of a
  // sheet or of the skin, prolonged to it: the fragments do not go around
  // their end
  std::size_t closures = 0;
  // by a ribbon: the rows that did not end on the skin and were stopped by
  // the face of the skin that stops their neighbours, prolonged
  std::size_t stoppedRows = 0;
  // the spacing of the grid the kept fragments are meshed with, 0 if they are
  // made of the triangles of the cut of two large triangles
  double keptArea = 0., gridSize = 0., seconds = 0.;
  // the area of the triangles that replace the branch (less than keptArea if
  // the fragments go beyond the reach)
  double addedArea = 0.;
  // A kept fragment reaches the rectangle: the skin does not close it.
  bool reachesFrame = false;
};

// Extends a branch in its plane: a rectangle of the plane around the whole
// skin is cut by the skin and by the triangles of the other branches that
// reach the plane (those lying in it, within the tolerance, excepted), and the
// fragments that hold a triangle of the branch replace it. Nothing else is
// changed and the result is not made conforming with the other branches. If
// size is positive the kept fragments are meshed with a grid of that spacing
// (larger for a fragment more than 400 times as long), cut the same way. If
// reach is positive, the faces of the part are prolonged into the material
// at the reentrant corners of its section by the plane (the end face of a rib
// where it meets the wall it stands on) up to the first sheet of another
// branch within that length, except where they would run on the branch
// itself or along a sheet that faces them, so that a fragment stops where the
// faces of the branch stop; and only the part of the kept fragments about
// that close to the branch (and to the branches merged with it) replaces it.
// The sheet of another branch that ends in the plane just short of another
// sheet or of the skin (within twice the tolerance) is prolonged to it as
// well: what is across another surface is not kept.
GMSH_API bool extendBranchInPlane(const Mesh &mesh, const Mesh &skin, const BranchPlane &plane,
                                  double tolerance, double size, double reach,
                                  PlaneExtension &out, std::string &error);

// A ribbon along the free boundary of a branch (its edges that no other
// triangle of the mesh shares): u is the length along the boundary and v the
// distance from it, in the direction tangent to the branch and normal to the
// boundary (tangent of the boundary x smoothed normal of the branch), turned
// where needed so that neighbouring directions do not cross within the length
// (see Ribbon::smoothedVertices). The ribbon is not cut by anything: it is
// what would be added if nothing stood in its way.
struct Ribbon {
  Mesh mesh;                // Mesh::branch is the number of the boundary chain
  std::vector<double> u, v; // one per vertex of mesh
  std::vector<int> source;  // the vertex of the MAT a vertex with v = 0 is, else -1
  std::size_t boundaryEdges = 0, freeEdges = 0, loops = 0;
  double boundaryLength = 0.;
  // Where the ribbon would fold over itself its directions are smoothed, and
  // where that is not enough it is made shorter: the vertices whose direction
  // was changed, those where the ribbon is shorter than asked, the passes it
  // took, and the spans of boundary that still fold.
  std::size_t smoothedVertices = 0, shortenedVertices = 0, foldedEdges = 0;
  int smoothingPasses = 0;
  // The chains of the free boundary, one row of vertices per node (the first
  // row of each chain, rows + 1 entries are not kept: the last chain ends
  // with the rows), whether each chain is a loop, the sign of its direction
  // (direction = sign x tangent x normal) and the normal of the branch at
  // each row; of extendFront, the vertices at the full length.
  std::vector<int> chainStart;
  std::vector<unsigned char> chainClosed;
  std::vector<double> chainSign, normal;
  std::vector<unsigned char> far;
};

// With original (the MAT before any of its branches was extended, whose
// vertices keep their numbers in mesh), an edge that was shared there is not
// free, even if the branch on its other side has been replaced since.
GMSH_API bool branchRibbon(const Mesh &mesh, int branch, double length, int layers, Ribbon &out,
                           std::string &error, const Mesh *original = nullptr);

// The band that extends a branch from its free boundary without folding: the
// chains of `rows' (a ribbon of branchRibbon, of which only the boundary, its
// normals and the side of the extension are used) advanced as fronts, layer
// by layer, up to `length'.
//  - A layer is the strip between a front and its offset: the front smoothed,
//    moved along tangent x normal by the step (beyond its own bumps), and
//    sampled again at a spacing that grows with the step. The steps double
//    from twice the edge length of the boundary up to length / layers, so
//    that the triangles keep their shape and the zigzag of the boundary of a
//    MAT is absorbed by the first, thin, layers.
//  - The strip is triangulated by walking along both lines at once; a
//    triangle is only made if it is turned like the surface (its normal
//    along that of the branch), which is tested for each one: a strip of
//    triangles all turned alike between two lines that do not cross does not
//    fold or overlap.
//  - The notches of the boundary narrower than the first step (a left turn
//    of more than 30 degrees) are filled first, by ears.
//  - Where the offset turns back (the front curves towards the outside
//    faster than the step: a hole closing, an inner corner) its points are
//    left out and the strip fans onto its neighbours; a loop that closes is
//    filled from its centre.
//  - A point of the offset closer to another part of the free boundary of
//    the branch than nine tenths of its own distance is beyond the middle of
//    a gap: the front ends there (no part of the band runs over another one,
//    or over the branch).
// The cost is linear in the number of nodes of the boundary. `limit', if
// given, is how far each row may go (one per row of `rows'). In `out': the
// mesh (Mesh::branch the chain), source (the vertex of the MAT of a boundary
// vertex, else -1), v the distance, far the vertices at the full length, and
// foldedEdges the triangles that could not be made (0 unless the boundary
// itself overlaps).
GMSH_API bool extendFront(const Ribbon &rows, double length, int layers,
                          const std::vector<double> *limit, Ribbon &out);

// Cuts the ribbon by the skin, by the other branches and where it crosses
// itself, and adds to the branch the fragments that have an edge on its
// boundary. In `out`, plane holds the pieces of the ribbon (0 kept, 1 not),
// result the MAT with the kept pieces added; reachesFrame says that a kept
// fragment holds the far end of the ribbon: it met nothing on its way. A row
// of the ribbon (the points away from one vertex of the boundary) that does
// not end on the skin is first stopped where it crosses the plane of the
// face of the skin that stops the nearest row that does (within its own
// length along the boundary), unless it ends shortly after on a sheet of
// another branch that faces it: next to the foot of a wall the ribbon would
// go on inside the wall it stands on.
GMSH_API bool extendBranchByRibbon(const Mesh &mesh, const Mesh &skin, int branch,
                                   const Ribbon &ribbon, PlaneExtension &out, std::string &error);

// All the branches at once. Each branch first gets the surface that extends
// it, not cut by anything: for the flat branches lying in one plane (within
// the tolerance), the part of that plane within the reach of them, as a grid
// of the size given (a branch is also flat when half of its area is within
// an eighth of the tolerance of a plane, the rest no further than half the
// reach from it and, beyond the tolerance, within the reach of a junction of
// the MAT: the wall with the cusps its sheet has along its junctions, which
// are replaced with it); for another branch, the ribbon along its free boundary
// (branchRibbon with the reach as length, its rows stopped as in
// extendBranchByRibbon). These surfaces, the skin, the sheets of the branches
// that are not replaced and the faces of the part prolonged at its reentrant
// corners (one set per plane, which cuts that plane only) are then cut where
// they meet, all together and once. Of each surface are kept the pieces
// attached to its branches (those that hold one of their triangles for a
// plane, those along the boundary for a ribbon) without crossing the skin, a
// sheet, or a kept piece of another surface: first with every piece of the
// others taken as kept, then again with what was kept, until nothing changes
// (or until the kept pieces alternate between two sets: the smaller one is
// taken, settled is false).
// The result does not depend on an order, a branch stops exactly on the
// surfaces of the others, and the kept pieces share their vertices along the
// lines where they meet.
//
// Left as they are: the branches of area under minArea (specks of the filter,
// which do not cut either), those of `fixed`, and the branches that are not
// flat and have no free boundary. In `out`: surfaces is what extends the
// branches before the cut and pieces what the cut makes of it (Mesh::branch is
// the number of the branch, -1 in pieces for what is not kept), result the MAT
// with every branch extended. `planes`, when given, is branchPlanes(mesh)
// already computed (the list of the branches of the window).
struct ExtensionSurface {
  int branch = 0;            // the largest of the branches it extends
  std::vector<int> branches; // all of them
  bool planar = true;
  std::size_t corners = 0, fences = 0, closures = 0; // of a plane, see PlaneExtension
  std::size_t stoppedRows = 0;         // of a ribbon
  std::size_t fragments = 0, keptFragments = 0, addedTriangles = 0;
  // of the branches before; of what replaces them (plane) or is added (ribbon)
  double area = 0., addedArea = 0.;
  // of a plane: the area of its branches off it, the cusps they have along
  // their junctions, replaced with them
  double cusps = 0.;
  // a kept piece reaches the border of the part of the plane, or the far end
  // of the ribbon: nothing stopped it
  bool reachesEnd = false;
};

struct GlobalExtension {
  Mesh surfaces, pieces, result;
  std::vector<ExtensionSurface> report;
  std::vector<int> extended; // the branches extended
  std::size_t specks = 0, unextended = 0, cutters = 0;
  // the edges of the sheets that stay prolonged to the planes that replace
  // the branches they ended on
  std::size_t prolonged = 0;
  // the slits of the result closed (see closeSlits), the triangles found
  // twice left once
  std::size_t slits = 0, duplicates = 0;
  // the triangles the bands could not make without folding (see extendFront)
  std::size_t unfolded = 0;
  double bandSeconds = 0.; // in extendFront
  // the times the kept pieces were found, and whether they stopped changing
  int rounds = 0;
  bool settled = false;
  double seconds = 0., cutSeconds = 0.;
};

GMSH_API bool extendAllBranches(const Mesh &mesh, const Mesh &skin, double tolerance,
                                double size, double reach, int layers, double minArea,
                                const std::set<int> &fixed, GlobalExtension &out,
                                std::string &error, const Mesh *original = nullptr,
                                const std::vector<BranchPlane> *planes = nullptr);

// The slits of a mesh closed: an edge of one triangle with nodes on it that
// are joined, from one end to the other, by edges of one triangle (a hole of
// zero area: a node of a cut on the edge of the triangle next to the one cut,
// not on its own), the triangle split as a fan from its third node at these
// nodes. Returns how many.
GMSH_API std::size_t closeSlits(Mesh &mesh);

// The mid-surface as an MSH 2.2 file: one surface and one physical group
// "branch <n>" per branch, and its edges classified in four physical groups
// of lines: "junction" (edge of three triangles or more, or of two triangles
// of different branches), and for the edges of one triangle, "boundary along
// another branch" (a triangle of another branch within half the usual edge
// length of the skin from its middle: where an extended branch stops on a
// sheet without sharing its vertices), "boundary on the skin" (a node of the
// skin within one and a half usual edge lengths) and "boundary inside the
// part" (the others). One curve per kind and branch. Only the nodes in use
// are written.
struct ClassifiedEdges {
  std::size_t branches = 0, onSkin = 0, inside = 0, junction = 0, along = 0;
};
// With nodeData (one value per node of the mesh), its finite values as
// $NodeData `dataName'.
GMSH_API bool writeClassifiedMesh(const Mesh &mesh, const Mesh &skin, const std::string &filename,
                                  ClassifiedEdges &counts, std::string &error,
                                  const std::vector<double> *nodeData = nullptr,
                                  const std::string &dataName = "");

// The mid-surface as a discrete model of Gmsh, to be meshed by Gmsh: a new
// model (GModel), named `name', made by the discrete CAD modeler from the
// triangles of the mesh, each branch a piece (see
// DiscreteCAD_Internals::addTriangulation): its surfaces are the triangles of
// a branch connected across edges of two triangles that are not sharp (angle
// between their normals below `angle'), its curves along the junctions, the
// boundaries and the sharp edges, split where they turn by more than
// `curveAngle' (a triple line that does not reach the boundary of a surface
// embedded in it), the nodes at the same coordinates merged; no
// parametrization and no analytic surface: the surfaces are their
// triangulations; one physical group of surfaces "branch <n>" per
// branch, and two of curves, "junction" (between surfaces of different
// branches, or of more than two surfaces) and "boundary" (of one surface).
// Its surfaces are meshed by the Frontal-Delaunay algorithm on their
// triangulation (Mesh.Algorithm 12, set on each surface), with the size map
// of Gmsh, the sizes of the 1D mesh not extended into them. Before: the
// nodes joined by an edge shorter than a tenth of the square root of minArea
// made one (the node on more junction and boundary edges kept in place, no
// triangle that is not flat turned over, the triangles left without area and
// those found twice left out: the cut of the extension leaves nodes
// micrometres apart where it crosses the MAT near a junction, which would be
// points of the model as close), the slits of the mesh closed (a hole of three edges, of
// zero area: the triangle along it split at its node off its edge, as the
// cut of the extension leaves some), the holes of area under minArea filled
// (a few micrometres wide, also left by the cut); after: the surfaces of area
// under minArea (folds and needles of the cut) removed. The current model and the
// visibility of the others are left as they were, the new model hidden.
struct MidSurfaceModel {
  GModel *model = nullptr; // in GModel::list, deleted by its owner
  std::size_t branches = 0, surfaces = 0, curves = 0, points = 0, volumes = 0;
  std::size_t junctions = 0, boundaries = 0; // curves of each group
  // the nodes merged into a neighbor closer than mergeLength and the
  // triangles then left out, the slits closed, the surfaces under minArea
  // left out and their area
  std::size_t merged = 0, removed = 0, slits = 0, holes = 0, specks = 0;
  double mergeLength = 0., speckArea = 0.;
  std::map<int, int> branchOfSurface; // surface tag -> branch
  // the triangulation given to the discrete CAD modeler, repaired (branch:
  // the piece of each triangle)
  Mesh triangulation;
  // of the last mesh: its triangles and nodes, the surfaces left without
  // triangles
  std::size_t triangles = 0, nodes = 0, failed = 0;
  double buildSeconds = 0., meshSeconds = 0.;
};
GMSH_API bool buildMidSurfaceModel(const Mesh &mesh, const std::string &name, double angle,
                                   double curveAngle, double minArea, MidSurfaceModel &out,
                                   std::string &error);
// The 2D mesh of the model, its triangles at most `size' (Mesh.MeshSizeMax,
// for this mesh only; Gmsh's size options alone if 0): the smaller sizes the
// other options ask for (Mesh.MeshSizeMin, Mesh.MeshSizeFromCurvature, the
// fields of the model) apply. The current model is left as it was.
GMSH_API bool meshMidSurfaceModel(MidSurfaceModel &m, double size, std::string &error);
// MSH 4.1, the elements of the physical groups, and the values at nodes, if
// given, as $NodeData `name'
GMSH_API bool writeMidSurfaceMesh(const MidSurfaceModel &m, const std::string &filename,
                                  std::string &error,
                                  const std::vector<std::size_t> *nodes = nullptr,
                                  const std::vector<double> *values = nullptr,
                                  const std::string &name = "");

// The local thickness of the MAT: at a point of a branch, twice the radius of
// the ball of the MAT at the nearest node of that branch in `original' (a MAT
// mesh with its radii: the filtered MAT), or of any branch if it has none
// (NaN without radii). For the extended parts, the thickness at the nearest
// point of the branch they extend. Of the points xyz of the branches given:
GMSH_API void localThickness(const Mesh &original, const std::vector<double> &xyz,
                             const std::vector<int> &branch, std::vector<double> &thickness);
// of the nodes of a mesh (NaN for those of no triangle; a node of several
// branches takes that of its first triangle)
GMSH_API std::vector<double> localThickness(const Mesh &mesh, const Mesh &original);
// of the nodes of the mesh of the mid-surface model (by their numbers)
GMSH_API void midSurfaceThickness(const MidSurfaceModel &m, const Mesh &original,
                                  std::vector<std::size_t> &nodes,
                                  std::vector<double> &thickness);

// Optional stages propose changes to a copy. On failure their input remains
// usable. A partial extension is reported explicitly for every original front.
GMSH_API bool extend(const Mesh &input, const Mesh &skin, const Options &options,
            Mesh &output, ExtensionReport &report, std::string &error);

} // namespace matgmsh_native
#endif
