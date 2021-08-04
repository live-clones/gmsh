// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
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

bool buildVerticesAndTriangles(GFace *gf, vector<MVertex *> &vertices,
                               vector<std::array<uint32_t, 3> > &triangles)
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
    if(n == 3) { triangles.push_back({fvert[0], fvert[1], fvert[2]}); }
    else if(n == 4) {
      /* one triangle per corner */
      triangles.push_back({fvert[0], fvert[1], fvert[2]});
      triangles.push_back({fvert[0], fvert[2], fvert[3]});
      triangles.push_back({fvert[1], fvert[2], fvert[3]});
      triangles.push_back({fvert[1], fvert[3], fvert[0]});
    }
  }

  return true;
}

bool buildPlanarTriProblem(GFace *gf, vector<MVertex *> &vertices,
                           vector<vec2> &points, vector<bool> &locked,
                           vector<std::array<uint32_t, 3> > &triangles,
                           TransfoPlanar &transfo)
{
  buildVerticesAndTriangles(gf, vertices, triangles);

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

  return true;
}

double triangle_area_2d(vec2 a, vec2 b, vec2 c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

void invertTrianglesIfNecessary(
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
  TransfoPlanar transfo;
  bool okb =
    buildPlanarTriProblem(gf, vertices, points, locked, triangles, transfo);
  if(!okb) {
    Msg::Error(
      "- Face %i: untangleGFaceMeshConstrained, failed to build planar problem",
      gf->tag());
    return false;
  }
  invertTrianglesIfNecessary(points, triangles);

  /* Call Winslow untangler */
  std::vector<std::array<std::array<double, 2>, 3> > triIdealShapes;
  double theta = 1. / 128.;
  int iterMaxInner = 500;
  int iterFailMax = 10;
  double lambda = 1./127.; 

  bool converged = untangle_triangles_2D(points, locked, triangles,
      triIdealShapes, lambda, iterMaxInner, iterMax, iterFailMax, timeMax);

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
