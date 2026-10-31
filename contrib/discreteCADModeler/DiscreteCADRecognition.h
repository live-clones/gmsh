// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
};

// the simplest analytic surface (a plane, a sphere, a cylinder, a cone or a
// torus) whose distance to the nodes x of a triangulation is at most
// tolerance, the normals of its triangles making an angle smaller than angle
// with its normals at their centroids (type NONE if there is none)
DiscreteCADAnalyticSurface
recognizeSurface(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 double tolerance, double angle);

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
// no seeds); then the triangles between the pieces moved to the piece whose
// surface is the nearest to their centroid, the bands of free triangles one
// triangle wide along them added to them. The piece of each triangle (-1 for
// none) and the surface of each piece.
void segmentSurface(const std::vector<std::array<double, 3> > &x,
                    const std::vector<std::array<int, 3> > &triangles,
                    const std::vector<std::vector<int> > &neighbors,
                    double tolerance, double precision, double angle,
                    std::vector<int> &piece,
                    std::vector<DiscreteCADAnalyticSurface> &surfaces);

// the parameters of the corners of the triangles on an analytic surface, as
// those of the primitives of the discrete CAD modeler: the coordinates in the
// plane; the developed cylinder (r theta, z) and cone s (cos(theta sin(a)),
// sin(theta sin(a))), the angles of the corners of each triangle within pi of
// each other (their jumps are the seams); for a cone holding its apex (a node
// at most tolerance away from it, given in apex, else -1), the disk (s / smax)
// (cos(theta), sin(theta)); the stereographic projection of a sphere from the
// point opposite to it, or of its two halves (half of each triangle, 0 or 1)
// if it goes beyond 120 degrees from its center; the conformal map of a torus
// onto an annulus, or of its two halves on each side of its equatorial plane
// if it goes around its section
void analyticParameters(const DiscreteCADAnalyticSurface &s,
                        const std::vector<std::array<double, 3> > &x,
                        const std::vector<std::array<int, 3> > &triangles,
                        double tolerance,
                        std::vector<std::array<std::array<double, 2>, 3> > &uv,
                        std::vector<int> &half, int &apex);

#endif
