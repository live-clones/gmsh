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

#ifndef DISCRETE_CAD_RECOGNITION_H
#define DISCRETE_CAD_RECOGNITION_H

#include <array>
#include <vector>

// An analytic surface: a plane through o of normal axis, a sphere of center o
// and radius r1, a cylinder of axis (o, axis) and radius r1, a cone of apex o,
// axis axis (towards its points) and half angle r1, or a torus of center o,
// axis axis and radii r1 (of its center circle) and r2 (of its section)
struct DiscreteCADAnalyticSurface {
  enum Type { NONE, PLANE, SPHERE, CYLINDER, CONE, TORUS };
  Type type;
  double o[3], axis[3], r1, r2;
  DiscreteCADAnalyticSurface() : type(NONE), r1(0.), r2(0.)
  {
    for(int k = 0; k < 3; k++) o[k] = axis[k] = 0.;
  }
  // the signed distance of point x to the surface, and its unit normal at the
  // point of the surface nearest to x
  double distance(const double x[3]) const;
  void normal(const double x[3], double n[3]) const;
  // the second derivatives m of the signed distance at x (the derivatives of
  // the normal)
  void hessian(const double x[3], double m[3][3]) const;
};

// the point x where the analytic surfaces s (two or three) meet near p, on the
// plane through p normal to the unit vector t if t is not null (with two
// surfaces): Newton steps of least norm from p; false if they do not converge
bool intersectSurfaces(const std::vector<const DiscreteCADAnalyticSurface *> &s,
                       const double p[3], const double *t, double x[3]);

// whether x, where the analytic surfaces s (two or three) meet, is their
// intersection near p: they meet at x at more than a degree (the intersection
// of surfaces fitted to a triangulation of tangent surfaces is not defined),
// and x is closer to p than a tenth of the distance at which their curvatures
// can make them meet again
bool isIntersectionNear(
  const std::vector<const DiscreteCADAnalyticSurface *> &s, const double p[3],
  const double x[3]);

// the unit tangent (along t) and the curvature vector at x of the
// intersection of the analytic surfaces a and b
void intersectionCurve(const DiscreteCADAnalyticSurface &a,
                       const DiscreteCADAnalyticSurface &b, const double x[3],
                       const double t[3], double tangent[3],
                       double curvature[3]);

// the map from the parameters of an analytic surface (see
// analyticParameters) to its points, and back: the coordinates in a plane of
// axes e0, e1; the developed cylinder or cone (around the axis of the
// surface, e0 and e1 at the angle 0 and pi / 2), the angle of a point taken
// around reference (in the developed plane for a cone); the disk of a cone
// with its apex, of radius scale; the stereographic projection of a sphere
// from -scale d (scale = 1 or -1), e0 and e1 orthogonal to d; the conformal
// map of a torus onto an annulus, the angle around its section taken from
// cut, the radius exp(scale (s - lowest)) for the conformal coordinate s
struct DiscreteCADAnalyticMap {
  enum Kind { NONE, PLANE, DEVELOPED, DISK, STEREOGRAPHIC, ANNULUS };
  Kind kind;
  DiscreteCADAnalyticSurface surface;
  double e0[3], e1[3], d[3], scale, lowest, cut, reference;
  DiscreteCADAnalyticMap()
    : kind(NONE), scale(1.), lowest(0.), cut(0.), reference(0.)
  {
    for(int k = 0; k < 3; k++) e0[k] = e1[k] = d[k] = 0.;
  }
  // the point at the parameters (u, v), and the parameters of the point of
  // the surface nearest to x (near guess, if not null)
  void point(double u, double v, double x[3]) const;
  void parameters(const double x[3], const double *guess, double uv[2]) const;
  // the derivatives of the point at the parameters (u, v): der[0] = dx/du,
  // der[1] = dx/dv, der[2] = d2x/du2, der[3] = d2x/dv2, der[4] = d2x/dudv
  void derivatives(double u, double v, double der[5][3]) const;
  // the reference of the angles from the parameters of the corners of the
  // triangles of a surface
  void setReference(const std::vector<std::array<std::array<double, 2>, 3> > &uv);
};

// the simplest analytic surface (a plane, a sphere, a cylinder, a cone or a
// torus) whose distance to the nodes x of a triangulation is at most
// tolerance, the normals of its triangles making an angle smaller than angle
// with its normals at their centroids (type NONE if there is none)
DiscreteCADAnalyticSurface
recognizeSurface(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 double tolerance, double angle);

// the angle between the sheets of a triangulation along its edges shared by
// two triangles (edges: their nodes and their two triangles, consistently
// oriented): the angle between the normals at the middle of the edge of the
// quadrics fitted to the nodes within two edges of its nodes on each side of
// it (around its axis), which does not depend on the size of the triangles on
// a smooth surface (on a coarse triangulation the angle between the
// triangles, in raw, can be large), the nodes reached from the triangle on
// each side across edges not sharper than it; the angle between the triangles
// if it is smaller (or than lower, or if the nodes are too few)
void sheetAngles(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 const std::vector<std::array<int, 4> > &edges, double lower,
                 std::vector<double> &angles, std::vector<double> &raw);

// the largest distance by which the nodes x were moved when their coordinates
// were rounded: written as text with few decimals or significant digits, or
// as single or double precision floats
double coordinatePrecision(const std::vector<std::array<double, 3> > &x);

// the triangulation of a smooth surface (neighbors: the triangles across its
// edges) split into pieces on analytic surfaces, for a part whose faces meet
// tangentially: from seed triangles (by decreasing area, with the rings around
// them, fewer for a small face, if an analytic surface is within twice the
// precision of the coordinates of their nodes, and within tolerance), the
// regions grown on the surface, refitted as they grow (a freeform surface has
// no seeds); then the pieces optimized together (variational shape
// approximation: the triangles given to the nearest surface by flooding, the
// surfaces fitted to their pieces, until they do not change, pieces on the
// same surface merged), the bands of free triangles one triangle wide along
// them added to them. The piece of each triangle (-1 for none) and the
// surface of each piece.
void segmentSurface(const std::vector<std::array<double, 3> > &x,
                    const std::vector<std::array<int, 3> > &triangles,
                    const std::vector<std::vector<int> > &neighbors,
                    double tolerance, double precision, double angle,
                    std::vector<int> &piece,
                    std::vector<DiscreteCADAnalyticSurface> &surfaces);

// the parameters of the corners of the triangles on an analytic surface, as
// those of the primitives of the discrete CAD modeler: the coordinates in the
// plane; the developed cylinder (r theta, z) and cone s (cos(theta sin(a)),
// sin(theta sin(a))), the angles continuous across the edges except, for a
// surface going around its axis, along the shortest path of edges between
// two of its boundaries going around it (the jump is its seam); for a cone
// holding its apex (a node
// at most tolerance away from it, given in apex, else -1), the disk (s / smax)
// (cos(theta), sin(theta)); the stereographic projection of a sphere from the
// point opposite to it, or of its two halves (half of each triangle, 0 or 1)
// if it goes beyond 120 degrees from its center; the conformal map of a torus
// onto an annulus, or of its two halves on each side of its equatorial plane
// if it goes around its section
// (the maps of the halves in maps)
void analyticParameters(const DiscreteCADAnalyticSurface &s,
                        const std::vector<std::array<double, 3> > &x,
                        const std::vector<std::array<int, 3> > &triangles,
                        double tolerance,
                        std::vector<std::array<std::array<double, 2>, 3> > &uv,
                        std::vector<int> &half, int &apex,
                        std::vector<DiscreteCADAnalyticMap> &maps);

#endif
