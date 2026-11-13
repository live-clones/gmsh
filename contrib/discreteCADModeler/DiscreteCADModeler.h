// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef DISCRETE_CAD_MODELER_H
#define DISCRETE_CAD_MODELER_H

#include <array>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "DiscreteCADRecognition.h"

class GModel;

// The internal data of the discrete CAD modeler: points, polylines and
// triangulations, copied into the model as discrete vertices, curves,
// surfaces and volumes by synchronize(). The nodes are shared: the
// triangulations of two surfaces with a common curve use the nodes of its
// polyline. The modeler gives the parameters of the nodes of its surfaces:
// coordinates in their plane, stereographic projections of the two halves of
// a sphere, conformal maps of lateral surfaces and of the two halves of a
// torus onto annuli.
class DiscreteCAD_Internals {
public:
  struct Vertex {
    int node;
  };
  // an open polyline from the node of vertex v0 to the node of vertex v1,
  // smooth if it only cuts a smooth surface (a seam, a cut into pieces that
  // a map can parametrize, the boundary between its pieces on analytic
  // surfaces), not along a sharp edge or a boundary of a triangulation
  struct Curve {
    int v0, v1;
    std::vector<int> nodes;
    bool smooth = false;
  };
  // a triangulation (oriented outwards for the surfaces of a volume) bounded
  // by loops of curves, a negative tag for a curve used backwards, the
  // vertices inside it, the parameters of the corners of its triangles
  // (computed from the triangulation by synchronize if empty), its seams: the
  // curves used twice in its loops, with the parameters of their nodes on
  // their two sides (the side of the curve used forwards first), the curves
  // inside it (its creases), and, for an analytic surface, the map from its
  // parameters to its points (its exact geometry), or only the surface for a
  // primitive (its geometry stays its triangulation); a raw surface is the
  // triangulation of a piece of a file, as read, without curves (see
  // importTriangulations)
  struct Surface {
    std::vector<int> curves;
    std::vector<std::array<int, 3> > triangles;
    std::vector<int> embeddedVertices;
    std::vector<std::array<std::array<double, 2>, 3> > uv;
    std::map<int, std::array<std::vector<std::array<double, 2> >, 2> > seams;
    std::vector<int> embeddedCurves;
    DiscreteCADAnalyticMap analytic;
    bool raw = false;
  };
  // a closed shell of surfaces, a negative tag for a surface used reversed
  struct Volume {
    std::vector<int> surfaces;
  };
  // an orthonormal frame: origin o and axes e[0], e[1], e[2]
  struct Frame {
    double o[3], e[3][3];
  };

private:
  std::vector<std::array<double, 3> > _nodes;
  std::map<int, Vertex> _vertices;
  std::map<int, Curve> _curves;
  std::map<int, Surface> _surfaces;
  std::map<int, Volume> _volumes;
  int _maxTag[4];
  // entities added since the last synchronize
  bool _changed;
  // the entities copied into the model by the last synchronize
  std::vector<std::pair<int, int> > _synchronized;
  bool _exists(int dim, int tag) const;
  // a free tag of dimension dim if tag <= 0, else tag if it is free
  bool _assignTag(int dim, int &tag);
  int _addNode(double x, double y, double z);
  int _addVertex(int node);
  int _addCurve(int v0, int v1, const std::vector<int> &nodes);
  int _addSurface(const std::vector<int> &curves,
                  const std::vector<std::array<int, 3> > &triangles);
  // the n nodes (n even, or 1 for the center) of the ellipse of radii rx, ry
  // in the plane w of frame f, at the angles 2 pi i / n
  std::vector<int> _addRing(const Frame &f, double rx, double ry, double w,
                            int n);
  // the vertices at the angles 0 and pi of a ring, and its two arcs: a from 0
  // to pi, b from pi to 2 pi
  void _addArcs(const std::vector<int> &ring, int &a, int &b);
  // the rings filling the ellipse of radii rx, ry, from its boundary ring
  // inwards, and their triangles, oriented along e[2]
  // the parameters of the corners of the triangles of a surface without seam,
  // from those of their nodes
  void _setUV(int surface,
              const std::function<std::array<double, 2>(int)> &uvOfNode);
  // the parameters of the nodes of a planar surface: their coordinates along
  // the axes eu, ev from o
  void _planarUV(int surface, const double o[3], const double eu[3],
                 const double ev[3]);
  // remove a volume, and its surfaces, curves and vertices that no other
  // entity uses
  void _removeVolume(int tag);
  // remove the curves and vertices that no surface uses
  void _removeUnused();
  std::vector<std::array<int, 3> > _fillEllipse(const Frame &f, double rx,
                                                double ry, double w,
                                                const std::vector<int> &ring);
  // the surfaces, curves and vertices of a triangulation of nodes: a surface
  // for each set of triangles of the same label connected across edges of
  // two triangles, curves along the other edges (between two surfaces, of one
  // triangle or of more than two) and along the seams of the surfaces (where
  // the parameters of the corners of their triangles jump, for those with
  // hasUV) and along the creases inside the surfaces (embedded curves), split
  // where more or less than two of them meet, where their kind changes and
  // where they turn by more than curveAngle and at the nodes of corners, the
  // closed ones in two arcs; the parameters made continuous across the seams
  // of the surfaces that do not go around them. The surface of each triangle
  // in surfaceOf.
  void _addTopology(const std::vector<std::array<int, 3> > &triangles,
                    const std::vector<int> &label,
                    std::vector<std::array<std::array<double, 2>, 3> > &uv,
                    const std::vector<char> &hasUV,
                    const std::set<std::pair<int, int> > &creases,
                    double curveAngle, std::vector<int> &surfaceOf,
                    const std::set<int> *corners = nullptr);
  // the volumes bounded by the surfaces of a triangulation (the surface of
  // each triangle in surfaceOf): the cells of space between them, found by
  // turning around their edges; those of a connected piece of the
  // triangulation inside no cell of another one are volumes, those of a piece
  // inside a cell are volumes if its triangles point out of it, holes if they
  // point into it, and the shell around the piece bounds the cell. For each
  // volume its shells of signed surfaces (negative for a surface oriented
  // inwards), the outer one first.
  std::vector<std::vector<std::vector<int> > >
  _cells(const std::vector<std::array<int, 3> > &triangles,
         const std::vector<int> &surfaceOf) const;
  // the triangles of a triangulation (3 coordinates per node, 3 node indices
  // from 0 per triangle) on the nodes of the modeler, those at the same
  // coordinates merged, and the piece of each one (0 if pieces is empty)
  bool _mergeNodes(const std::vector<double> &coord,
                   const std::vector<std::size_t> &triangles,
                   const std::vector<int> &pieces,
                   std::vector<std::array<int, 3> > &tri,
                   std::vector<int> &piece);
  // the degenerate triangles and the copies removed, the others oriented as
  // their neighbors across the edges of two triangles
  bool _cleanTriangles(std::vector<std::array<int, 3> > &tri,
                       std::vector<int> &piece);
  // the patches of a triangulation (the label of each triangle): the
  // triangles of the same piece connected across edges of two triangles that
  // are not sharp (see addTriangulation), and the edges between them in
  // barrier (the sharp ones, and those between two pieces)
  void _patches(const std::vector<std::array<int, 3> > &tri,
                const std::vector<int> &piece, double angle,
                std::vector<int> &label,
                std::set<std::pair<int, int> > &barrier);
  // the surfaces, curves, vertices and volumes of a triangulation split into
  // patches (the label of each triangle) along the edges of barrier: its
  // patches on analytic surfaces if recognize (see addTriangulation), the
  // others split into pieces that a map can parametrize, their topology (see
  // _addTopology, curves split at the nodes of corners), its volumes (see
  // _cells; that of the triangles pointing out of them in volumeOf, by their
  // nodes from the smallest one, keeps its tag). The volumes and the surfaces
  // bounding none in outDimTags.
  bool _build(std::vector<std::array<int, 3> > &tri, std::vector<int> &label,
              const std::set<std::pair<int, int> > &barrier, double angle,
              double curveAngle, double tolerance, bool recognize,
              const std::set<int> *corners,
              const std::map<std::array<int, 3>, int> *volumeOf,
              std::vector<std::pair<int, int> > &outDimTags);
  // the triangles of the surfaces of a mesh file, each surface a piece (see
  // importShapes)
  bool _readTriangulations(const std::string &fileName,
                           std::vector<double> &coord,
                           std::vector<std::size_t> &triangles,
                           std::vector<int> &pieces);
  // the fillets of a volume along the curves of radiusOf (see fillet)
  bool _filletVolume(int volume, const std::map<int, double> &radiusOf,
                     bool removeVolume,
                     std::vector<std::pair<int, int> > &outDimTags);

public:
  DiscreteCAD_Internals();
  void reset();
  bool getChanged() const { return _changed; }
  // a box with a corner at (x, y, z) and extents dx, dy, dz; tag is the tag
  // of the volume (a new one if tag <= 0)
  bool addBox(int &tag, double x, double y, double z, double dx, double dy,
              double dz);
  // a sphere whose triangulation is at most tolerance away from the exact
  // surface (Geometry.DiscreteTolerance times the radius if tolerance <= 0)
  bool addSphere(int &tag, double xc, double yc, double zc, double radius,
                 double tolerance);
  // a rectangle in the plane z with a corner at (x, y, z) and extents dx, dy;
  // tag is the tag of the surface
  bool addRectangle(int &tag, double x, double y, double z, double dx,
                    double dy);
  // a disk (an ellipse of radii rx along xAxis, ry, normal to zAxis; the x
  // and z axes if empty), its boundary at most tolerance away from the exact
  // ellipse; tag is the tag of the surface
  bool addDisk(int &tag, double xc, double yc, double zc, double rx, double ry,
               const std::vector<double> &zAxis,
               const std::vector<double> &xAxis, double tolerance);
  // a cylinder of axis (dx, dy, dz) from (x, y, z) and radius r
  bool addCylinder(int &tag, double x, double y, double z, double dx,
                   double dy, double dz, double r, double tolerance);
  // a cone of axis (dx, dy, dz) from (x, y, z), radius r1 at (x, y, z) and r2
  // at the other end (one of them can be zero)
  bool addCone(int &tag, double x, double y, double z, double dx, double dy,
               double dz, double r1, double r2, double tolerance);
  // a torus of center (x, y, z) and axis zAxis (z if empty), radius r1 of its
  // center circle and r2 of its section
  bool addTorus(int &tag, double x, double y, double z, double r1, double r2,
                const std::vector<double> &zAxis, double tolerance);
  // the boolean operation op (0: union, 1: intersection, 2: difference) of
  // the volumes objectDimTags and toolDimTags, exact on their
  // triangulations: the resulting volumes in outDimTags (the first one with
  // the tag tag if positive), and
  // those coming from each input entity in outDimTagsMap; the surfaces of the
  // result keep the parameters of those they come from. The nodes of the
  // result closer than merge times its size are merged; the triangles coming
  // from a surface of alias (its keys) are part of the surfaces of those of
  // the surface it gives.
  bool booleanOperation(
    int op, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap, int tag,
    bool removeObject, bool removeTool, double merge = 1.e-12,
    const std::map<int, int> *alias = nullptr);
  // the volumes volumeTags filleted along the curves curveTags (and the
  // curves continuing them tangentially) with the radii (one, or one for each
  // curve): the ball of radius r rolling on the two surfaces of each curve
  // removes the solid between it and the curve if it is convex, fills the
  // space between them if it is concave; three fillets of the same radius
  // and kind meeting at a vertex are joined by the part of the ball touching
  // their three surfaces. The resulting volumes in outDimTags.
  bool fillet(const std::vector<int> &volumeTags,
              const std::vector<int> &curveTags,
              const std::vector<double> &radii,
              std::vector<std::pair<int, int> > &outDimTags, bool removeVolume);
  // a triangulation (3 coordinates per node, 3 node indices from 0 per
  // triangle, and for each triangle the piece of the input it belongs to, if
  // not empty) and its topology: its surfaces, the triangles connected across
  // edges of two triangles whose normals make an angle smaller than angle (in
  // the same piece), the curves between them, along its boundaries, its
  // non-manifold edges and its sharp edges inside a surface (embedded in it),
  // split where they turn by more than curveAngle, and
  // its volumes, the cells of space they bound (see _cells), every surface
  // oriented outwards of the first volume whose outer shell it is on, or else
  // of the first volume it bounds. The surfaces whose nodes are at most
  // tolerance away from a plane, a sphere, a cylinder, a cone or a torus
  // (Geometry.DiscreteTolerance times the size of the triangulation if
  // tolerance <= 0) get the parameters of the primitives (see
  // analyticParameters), the others are split into their pieces on such
  // surfaces up to the precision of the coordinates (see segmentSurface), the
  // rest into pieces that a single map can parametrize (as classifySurfaces
  // does). The volumes and the surfaces bounding none in outDimTags.
  bool addTriangulation(const std::vector<double> &coord,
                        const std::vector<std::size_t> &triangles,
                        const std::vector<int> &pieces, double angle,
                        double curveAngle, double tolerance,
                        std::vector<std::pair<int, int> > &outDimTags);
  // the triangulations of the surfaces of a mesh file (STL, MSH, OBJ, PLY,
  // OFF, VTK, MESH), each surface of the file a piece, and their topology
  // (see addTriangulation)
  bool importShapes(const std::string &fileName, double angle,
                    double curveAngle, double tolerance,
                    std::vector<std::pair<int, int> > &outDimTags);
  // the steps of importShapes, one at a time: the triangulations of the
  // surfaces of a mesh file as read, a raw surface for each one, without
  // curves (their nodes at the same coordinates merged), in outDimTags
  bool importTriangulations(const std::string &fileName,
                            std::vector<std::pair<int, int> > &outDimTags);
  // the raw surfaces surfaceTags (all of them if empty) healed together:
  // their degenerate triangles and their copies removed, their triangles
  // oriented (see DiscreteCADHeal.h)
  bool heal(const std::vector<int> &surfaceTags);
  // the raw surfaces surfaceTags (all of them if empty) replaced by their
  // topology (see addTriangulation, each raw surface a piece), without
  // analytic surfaces: the volumes and the surfaces bounding none in
  // outDimTags
  bool classify(const std::vector<int> &surfaceTags, double angle,
                double curveAngle,
                std::vector<std::pair<int, int> > &outDimTags);
  // the analytic surfaces of the volumes and surfaces dimTags (all of them if
  // empty), and of those connected to them by their curves (see
  // addTriangulation): their surfaces
  // across smooth curves joined, then split into their pieces on analytic
  // surfaces, the rest into pieces that a map can parametrize; their curves
  // kept where sharp, split where they were; the volumes keep their tags. The
  // volumes and the surfaces bounding none in outDimTags.
  bool recognize(const std::vector<std::pair<int, int> > &dimTags,
                 double angle, double tolerance,
                 std::vector<std::pair<int, int> > &outDimTags);
  // the entities copied into the model, replacing those of the previous call
  void synchronize(GModel *model);
};

#endif
