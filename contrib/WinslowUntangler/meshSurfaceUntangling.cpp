// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshSurfaceUntangling.h"
#include "winslowUntangler.h"

#include <math.h>
#include <iostream> // debugging

#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "MVertex.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "GFace.h"
#include "Numeric.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "arrayGeometry.h"

using std::vector;
using namespace ArrayGeometry;

struct TransfoPlanar {
  SVector3 pop;
  SVector3 normal;
  SVector3 tangent;
  SVector3 binormal;
  mean_plane mp;
};

inline std::array<vec2, 4>
quadAnisotropicTargetShape(const std::vector<vec2> &points,
                           const std::array<uint32_t, 4> &quad)
{
  const double L01 = length(points[quad[0]] - points[quad[1]]);
  const double L12 = length(points[quad[1]] - points[quad[2]]);
  const double L23 = length(points[quad[2]] - points[quad[3]]);
  const double L30 = length(points[quad[3]] - points[quad[0]]);
  const vec2 deltamax = {std::max(L01, L23), std::max(L12, L30)};
  const vec2 deltaavg = {0.5 * (L01 + L23), 0.5 * (L12 + L30)};
  const double lmax = std::max(deltamax[0], deltamax[1]);
  const vec2 w = {deltaavg[0] / lmax, deltaavg[1] / lmax};

  std::array<vec2, 4> target = {vec2{0., 0.}, vec2{w[0], 0.}, vec2{w[0], w[1]},
                                vec2{0., w[1]}};
  double area = w[0] * w[1];
  for(size_t lv = 0; lv < 4; ++lv) {
    target[lv] = (1. / std::pow(area, 1. / 2.)) * target[lv];
  }
  return target;
}

bool normalizeTargetArea(std::array<vec2, 3> &target)
{
  double area = triangleArea(target[0], target[1], target[2]);
  if(area <= 0.) { Msg::Warning("target triangle area: %f", area); }
  for(size_t lv = 0; lv < 3; ++lv) {
    target[lv] = (1. / std::pow(area, 1. / 2.)) * target[lv];
  }
  return true;
}

bool buildTrianglesAndTargetsFromElements(
  const std::vector<std::array<double, 2> > &points,
  const std::vector<std::array<uint32_t, 4> > &elements,
  std::vector<std::array<uint32_t, 3> > &triangles,
  std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes,
  bool preserveQuadAnisotropy)
{
  const uint32_t NO_U32 = (uint32_t)-1;

  // Equilateral triangle centered in origin with unit area
  std::array<vec2, 3> equi = {vec2{1., 0.},
                              vec2{cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
                              vec2{cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
  normalizeTargetArea(equi);

  const int quad_dcp[4][3] = {{0, 1, 2}, {0, 2, 3}, {1, 2, 3}, {1, 3, 0}};

  triIdealShapes.clear();
  triangles.clear();
  double areaAvg = 0.;
  double areaN = 0.;
  for(size_t i = 0; i < elements.size(); ++i) {
    if(elements[i][0] == NO_U32) { continue; }
    else if(elements[i][3] == NO_U32) { /* already triangle */
      triangles.push_back({elements[i][0], elements[i][1], elements[i][2]});
      /* equilateral triangle target shape */
      triIdealShapes.push_back(equi);
      areaAvg += 1.;
      areaN += 1.;
    }
    else {
      std::array<vec2, 4> qtarget = {vec2{0., 0.}, vec2{1., 0.}, vec2{1., 1.},
                                     vec2{0., 1.}};
      if(preserveQuadAnisotropy) { /* does not work well, need better approach
                                    */
        qtarget = quadAnisotropicTargetShape(points, elements[i]);
      }
      for(size_t k = 0; k < 4; ++k) {
        triangles.push_back({elements[i][quad_dcp[k][0]],
                             elements[i][quad_dcp[k][1]],
                             elements[i][quad_dcp[k][2]]});
        std::array<vec2, 3> target = {qtarget[quad_dcp[k][0]],
                                      qtarget[quad_dcp[k][1]],
                                      qtarget[quad_dcp[k][2]]};
        normalizeTargetArea(target);

        // Warning: better behavior with equilateral tris instead of tri adapted
        // to unit quad. Quite weird... maybe a bug ?
        // triIdealShapes.push_back(target);
        triIdealShapes.push_back(equi);

        areaAvg += 1.;
        areaN += 1.;
      }
    }
  }
  if(areaN > 0) areaAvg /= areaN;
  for(size_t i = 0; i < triIdealShapes.size(); ++i)
    for(size_t lv = 0; lv < 3; ++lv) {
      triIdealShapes[i][lv] =
        triIdealShapes[i][lv] * (1. / std::pow(areaAvg, 1. / 2.));
    }

  return true;
}

bool buildVerticesAndElements(GFace *gf, vector<MVertex *> &vertices,
                              vector<std::array<uint32_t, 4> > &elements)
{
  std::unordered_map<MVertex *, uint32_t> old2new;
  vector<uint32_t> fvert;
  for(size_t e = 0; e < gf->getNumMeshElements(); ++e) {
    MElement *elt = gf->getMeshElement(e);
    size_t n = elt->getNumVertices();
    fvert.resize(n);
    for(size_t lv = 0; lv < n; ++lv) {
      MVertex *v = elt->getVertex(lv);
      auto it = old2new.find(v);
      if(it == old2new.end()) {
        old2new[v] = vertices.size();
        fvert[lv] = vertices.size();
        vertices.push_back(v);
      }
      else {
        fvert[lv] = it->second;
      }
    }
    if(n == 3) {
      elements.push_back({fvert[0], fvert[1], fvert[2], uint32_t(-1)});
    }
    else {
      elements.push_back({fvert[0], fvert[1], fvert[2], fvert[3]});
    }
  }

  return true;
}

bool buildPlanarTriProblem(
  GFace *gf, vector<MVertex *> &vertices, vector<vec2> &points,
  vector<bool> &locked, std::vector<std::array<uint32_t, 3> > &triangles,
  std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes,
  TransfoPlanar &transfo)
{
  std::vector<std::array<uint32_t, 4> > elements;
  buildVerticesAndElements(gf, vertices, elements);

  // Compute mean plane
  std::vector<SPoint3> positions;
  positions.reserve(vertices.size());
  for(MVertex *v : vertices) { positions.push_back(v->point()); }
  computeMeanPlaneSimple(positions, transfo.mp);
  double denom = std::pow(transfo.mp.a, 2) + std::pow(transfo.mp.b, 2) +
                 std::pow(transfo.mp.c, 2);
  if(denom < 1.e-16) {
    Msg::Warning("geometry optimize: invalid mean plane");
    return false;
  }
  transfo.normal = SVector3(transfo.mp.a, transfo.mp.b, transfo.mp.c);
  buildOrthoBasis(transfo.normal, transfo.tangent, transfo.binormal);
  transfo.pop = SPoint3(transfo.mp.x, transfo.mp.y, transfo.mp.z);

  // Project on plane
  points.resize(vertices.size());
  locked.clear();
  locked.resize(vertices.size(), false);
  SPoint3 proj;
  for(size_t v = 0; v < points.size(); ++v) {
    SPoint3 p = vertices[v]->point();
    points[v] = {dot(p - transfo.pop, transfo.tangent),
                 dot(p - transfo.pop, transfo.binormal)};
    if(vertices[v]->onWhat()->dim() < 2) { locked[v] = true; }
  }

  bool preserveQuadAnisotropy = true;
  return buildTrianglesAndTargetsFromElements(
    points, elements, triangles, triIdealShapes, preserveQuadAnisotropy);
}

double triangle_area_2d(vec2 a, vec2 b, vec2 c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

void _invertTrianglesIfNecessary(
  const std::vector<std::array<double, 2> > &points,
  std::vector<std::array<uint32_t, 3> > &tris)
{
  double area = 0.;
  for(size_t i = 0; i < tris.size(); ++i) {
    area += triangle_area_2d(points[tris[i][0]], points[tris[i][1]],
                             points[tris[i][2]]);
  }
  if(area < 0.) {
    Msg::Debug(
      "invert 2D triangle orientations (total area was %f for %li tris)", area,
      tris.size());
    for(size_t i = 0; i < tris.size(); ++i) {
      uint32_t v1 = tris[i][1];
      tris[i][1] = tris[i][2];
      tris[i][2] = v1;
    }
  }
}

bool untangleGFaceMeshConstrained(GFace *gf, int iterMax, double timeMax)
{
  if(gf->geomType() != GFace::Plane) {
    Msg::Error("- Face %i: untangleGFaceMeshConstrained only implemented for "
               "planar faces",
               gf->tag());
    return false;
  }

  if(gf->getNumMeshElements() == 0) {
    Msg::Debug("- Face %i: no elements", gf->tag());
    return false;
  }

  double t0 = Cpu();

  double sicnMinB, sicnAvgB;
  computeSICNquality(gf, sicnMinB, sicnAvgB);

  /* Build planar problem by projection on mean plane */
  vector<MVertex *> vertices;
  vector<vec2> points;
  vector<bool> locked;
  vector<std::array<uint32_t, 3> > triangles;
  std::vector<std::array<std::array<double, 2>, 3> > triIdealShapes;
  TransfoPlanar transfo;
  bool okb = buildPlanarTriProblem(gf, vertices, points, locked, triangles,
                                   triIdealShapes, transfo);
  if(!okb) {
    Msg::Error(
      "- Face %i: untangleGFaceMeshConstrained, failed to build planar problem",
      gf->tag());
    return false;
  }
  _invertTrianglesIfNecessary(points, triangles);

  /* Call Winslow untangler */
  int iterMaxInner = 1000;
  int iterFailMax = 10;
  double lambda = 1. / 127.;

  bool converged =
    untangle_triangles_2D(points, locked, triangles, triIdealShapes, lambda,
                          iterMaxInner, iterMax, iterFailMax, timeMax);

  /* Project back on 3D plane, then CAD */
  for(size_t v = 0; v < points.size(); ++v)
    if(!locked[v]) {
      SPoint3 onPlane = SPoint3(transfo.pop + points[v][0] * transfo.tangent +
                                points[v][1] * transfo.binormal);

      double initGuess[2] = {0., 0.};
      GPoint proj = gf->closestPoint(onPlane, initGuess);
      if(proj.succeeded()) {
        vertices[v]->setXYZ(proj.x(), proj.y(), proj.z());
        vertices[v]->setParameter(0, proj.u());
        vertices[v]->setParameter(1, proj.v());
      }
      else {
        vertices[v]->setXYZ(onPlane.x(), onPlane.y(), onPlane.z());
      }
    }

  double sicnMinA, sicnAvgA;
  computeSICNquality(gf, sicnMinA, sicnAvgA);

  Msg::Info("- Face %i: Winslow untangling, SICN min: %.3f -> %.3f, avg: %.3f "
            "-> %.3f (%li vertices, %.3f seconds)",
            gf->tag(), sicnMinB, sicnMinA, sicnAvgB, sicnAvgA, vertices.size(),
            Cpu() - t0);

  return true;
}

#else
bool untangleGFaceMeshConstrained(GFace *gf, int iterMax, double timeMax)
{
  Msg::Error(
    "Module QuadMeshingTools required for untangleGFaceMeshConstrained");
  return false;
}
#endif
