// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Maxence Reberol

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include "meshUntangling.h"
#include "WinslowUntangler.h"
#include "Context.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GRegion.h"
#include "MEdge.h"
#include "MElement.h"
#include "MVertex.h"
#include "Numeric.h"
#include "OS.h"
#include "SPoint3.h"
#include "SVector3.h"

using std::array;
using std::vector;
using vec3 = std::array<double, 3>;
using vec2 = std::array<double, 2>;

static const int quad_dcp[4][3] = {{0, 1, 2}, {2, 3, 0}, {1, 2, 3}, {3, 0, 1}};

static double triangleArea(const vec2 &a, const vec2 &b, const vec2 &c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

static vec2 scaled(const vec2 &a, double s) { return {a[0] * s, a[1] * s}; }

bool buildTrianglesAndTargetsFromElements(
  const std::vector<std::array<uint32_t, 4>> &elements,
  std::vector<std::array<uint32_t, 3>> &triangles,
  std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes)
{
  const uint32_t NO_U32 = (uint32_t)-1;

  // Equilateral triangle centered in origin with unit area
  std::array<vec2, 3> equi = {vec2{1., 0.},
                              vec2{cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
                              vec2{cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
  const double s = 1. / std::pow(triangleArea(equi[0], equi[1], equi[2]), .5);
  for(auto &p : equi) p = scaled(p, s);

  const std::array<vec2, 4> qtarget = {vec2{0., 0.}, vec2{1., 0.}, vec2{1., 1.},
                                       vec2{0., 1.}};

  triIdealShapes.clear();
  triangles.clear();
  for(const auto &e : elements) {
    if(e[0] == NO_U32) { continue; }
    else if(e[3] == NO_U32) {
      triangles.push_back({e[0], e[1], e[2]});
      triIdealShapes.push_back(equi);
    }
    else {
      for(size_t k = 0; k < 4; ++k) {
        triangles.push_back(
          {e[quad_dcp[k][0]], e[quad_dcp[k][1]], e[quad_dcp[k][2]]});
        triIdealShapes.push_back({qtarget[quad_dcp[k][0]],
                                  qtarget[quad_dcp[k][1]],
                                  qtarget[quad_dcp[k][2]]});
      }
    }
  }
  return true;
}

static void getVertices(std::vector<MElement *> &es,
                        std::vector<MVertex *> &vall,
                        std::vector<MVertex *> &vbound)
{
  vall.clear();
  vbound.clear();
  std::set<MEdge, MEdgeLessThan> edges;
  for(auto e : es) {
    for(size_t i = 0; i < e->getNumVertices(); i++) {
      MVertex *v = e->getVertex(i);
      if(std::find(vall.begin(), vall.end(), v) == vall.end())
        vall.push_back(v);
    }
    for(size_t i = 0; i < e->getNumEdges(); i++) {
      MEdge ed = e->getEdge(i);
      if(edges.find(ed) == edges.end())
        edges.insert(ed);
      else
        edges.erase(ed);
    }
  }
  for(auto ed : edges) {
    for(size_t i = 0; i < 2; i++) {
      MVertex *v = ed.getVertex(i);
      if(std::find(vbound.begin(), vbound.end(), v) == vbound.end())
        vbound.push_back(v);
    }
  }
}

static bool untangleGFaceMeanPlane(GFace *gf, std::vector<MElement *> &els,
                                   mean_plane &mp, int iter)
{
  std::vector<MVertex *> vall, vbound;
  getVertices(els, vall, vbound);

  std::vector<vec2> points;
  std::vector<bool> locked;
  std::vector<std::array<uint32_t, 3>> triangles;
  std::vector<std::array<std::array<double, 2>, 3>> triIdealShapes;

  int i = 0;
  SVector3 t1(mp.plan[0][0], mp.plan[0][1], mp.plan[0][2]);
  SVector3 t2(mp.plan[1][0], mp.plan[1][1], mp.plan[1][2]);
  t1.normalize();
  t2.normalize();
  SPoint3 X0(mp.x, mp.y, mp.z);
  for(auto v : vall) {
    SPoint3 ptProj;
    projectPointToPlane(v->point(), ptProj, mp);
    SVector3 D = ptProj - X0;
    double X = dot(t1, D);
    double Y = dot(t2, D);
    points.push_back({X, Y});
    if(std::find(vbound.begin(), vbound.end(), v) == vbound.end() &&
       v->onWhat()->dim() == 2)
      locked.push_back(false);
    else
      locked.push_back(true);
    v->setIndex(i++);
  }

  int nbPos = 0, nbNeg = 0;
  const double NRM = 0.5;
  const std::array<vec2, 4> qt = {vec2{NRM, NRM}, vec2{-NRM, NRM},
                                  vec2{-NRM, -NRM}, vec2{NRM, -NRM}};
  for(auto e : els) {
    MVertex *v[4]{e->getVertex(0), e->getVertex(1), e->getVertex(2),
                  e->getNumVertices() == 4 ? e->getVertex(3) : nullptr};
    int numSubdiv = e->getNumVertices() == 4 ? 4 : 1;
    for(int j = 0; j < numSubdiv; j++) {
      int i0 = v[quad_dcp[j][0]]->getIndex();
      int i1 = v[quad_dcp[j][1]]->getIndex();
      int i2 = v[quad_dcp[j][2]]->getIndex();
      if(iter < 0) std::swap(i0, i1);
      double area = triangleArea(points[i0], points[i1], points[i2]);
      if(area > 0)
        nbPos++;
      else
        nbNeg++;
      if(!(locked[i0] && locked[i1] && locked[i2])) {
        triangles.push_back({(uint32_t)i0, (uint32_t)i1, (uint32_t)i2});
        const double s = sqrt(fabs(area));
        triIdealShapes.push_back({scaled(qt[quad_dcp[j][0]], s),
                                  scaled(qt[quad_dcp[j][1]], s),
                                  scaled(qt[quad_dcp[j][2]], s)});
      }
    }
  }

  // most elements are reversed in this plane: retry with the other orientation
  if(nbPos < nbNeg && iter > 0)
    return untangleGFaceMeanPlane(gf, els, mp, -iter);

  WinslowUntangler::Options options;
  options.lambda = 1.e-2;
  options.maxInnerIterations = 200;
  options.maxOuterIterations = 3;
  options.maxFailures = 300;
  options.timeMax = 1.e3;
  options.numThreads = CTX::instance()->numThreadsFor(triangles.size(), 5000);
  WinslowUntangler::untangle2D(points, locked, triangles, triIdealShapes,
                               options);

  for(auto v : vall) {
    int i = v->getIndex();
    if(!locked[i]) {
      SVector3 P = X0 + t1 * points[i][0] + t2 * points[i][1];
      double initialGuess[2] = {0, 0};
      GPoint gp = gf->closestPoint(SPoint3(P.x(), P.y(), P.z()), initialGuess);
      v->setXYZ(gp.x(), gp.y(), gp.z());
      v->setParameter(gp.u(), gp.v());
    }
  }
  return true;
}

static mean_plane computeMeanPlaneSimple(std::vector<MVertex *> &vs)
{
  std::vector<SPoint3> pp;
  for(auto v : vs) pp.push_back(v->point());
  mean_plane mp;
  computeMeanPlaneSimple(pp, mp);
  return mp;
}

static bool tooFarFromPlane(std::vector<MVertex *> &vs, mean_plane &mp,
                            double threshold)
{
  double fact = sqrt(mp.a * mp.a + mp.b * mp.b + mp.c * mp.c);
  for(auto v : vs) {
    double d =
      fabs(mp.a * v->x() + mp.b * v->y() + mp.c * v->z() - mp.d) / fact;
    if(d > threshold) return true;
  }
  return false;
}

bool untangleGFaceMeshConstrained(GFace *gf)
{
  const double threshold = 1.e-2;
  if(gf->mesh_vertices.empty()) return true;
  double L = gf->bounds().diag();
  Msg::Info("Winslow Untangler applied to %s face %d size %g",
            gf->getTypeString().c_str(), gf->tag(), L);

  std::map<MVertex *, std::vector<MElement *>> v2e;
  for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    for(size_t j = 0; j < e->getNumVertices(); j++)
      v2e[e->getVertex(j)].push_back(e);
  }

  // Grow a patch around each vertex not yet treated, as long as it stays close
  // to its mean plane, and untangle it in that plane
  int iter = 0;
  std::vector<MVertex *> vall, vbound;
  std::set<MVertex *> touched;
  for(size_t k = 0; k < v2e.size(); k++) {
    MVertex *v = gf->mesh_vertices[iter % gf->mesh_vertices.size()];
    iter++;
    if(touched.find(v) != touched.end()) continue;
    if(touched.size() >= v2e.size()) break;

    std::vector<MElement *> es = v2e[v];
    getVertices(es, vall, vbound);
    mean_plane mp = computeMeanPlaneSimple(vall);
    if(tooFarFromPlane(vall, mp, threshold * L)) continue;
    while(1) {
      std::vector<MElement *> esNew = es;
      for(auto b : vbound) {
        std::vector<MElement *> eb = v2e[b];
        for(auto el : eb)
          if(std::find(esNew.begin(), esNew.end(), el) == esNew.end())
            esNew.push_back(el);
      }
      if(esNew.size() <= es.size()) break;
      getVertices(esNew, vall, vbound);
      mp = computeMeanPlaneSimple(vall);
      if(tooFarFromPlane(vall, mp, threshold * L)) break;
      es = esNew;
    }
    for(auto vv : vall)
      if(std::find(vbound.begin(), vbound.end(), vv) == vbound.end())
        touched.insert(vv);
    untangleGFaceMeanPlane(gf, es, mp, iter);
  }
  return true;
}

namespace {
  const uint32_t pyr2tet_corners[4][4] = {
    {0, 1, 2, 4}, {1, 2, 3, 4}, {2, 3, 0, 4}, {3, 0, 1, 4}};

  const uint32_t hex2tet_corners[8][4] = {
    {0, 1, 2, 5}, {1, 2, 3, 6}, {2, 3, 0, 7}, {3, 0, 1, 4},
    {6, 5, 4, 1}, {5, 4, 7, 0}, {4, 7, 6, 3}, {7, 6, 5, 2},
  };

  const uint32_t hex2tet_24[24][4] = {
    {0, 1, 2, 4}, {0, 1, 3, 5}, {0, 3, 7, 1}, {0, 3, 4, 2}, {0, 4, 1, 7},
    {0, 4, 5, 3}, {1, 2, 0, 6}, {1, 2, 3, 5}, {1, 5, 2, 4}, {1, 5, 6, 0},
    {3, 2, 6, 0}, {3, 2, 7, 1}, {3, 7, 0, 6}, {3, 7, 4, 2}, {2, 6, 7, 1},
    {2, 6, 3, 5}, {4, 5, 0, 6}, {4, 5, 1, 7}, {4, 7, 5, 3}, {4, 7, 6, 0},
    {5, 6, 1, 7}, {5, 6, 2, 4}, {7, 6, 5, 3}, {7, 6, 4, 2}};

  enum HexDcp { TO_8TETS, TO_24TETS, TO_32TETS };

  std::vector<std::array<uint32_t, 4>>
  tetsFromHex(const array<uint32_t, 8> &hex, HexDcp dcp = TO_24TETS)
  {
    vector<array<uint32_t, 4>> tets;
    if(dcp == TO_8TETS || dcp == TO_32TETS) {
      for(size_t i = 0; i < 8; ++i) {
        tets.push_back({hex[hex2tet_corners[i][0]], hex[hex2tet_corners[i][1]],
                        hex[hex2tet_corners[i][2]],
                        hex[hex2tet_corners[i][3]]});
      }
    }
    if(dcp == TO_24TETS || dcp == TO_32TETS) {
      for(size_t i = 0; i < 24; ++i) {
        tets.push_back({hex[hex2tet_24[i][0]], hex[hex2tet_24[i][1]],
                        hex[hex2tet_24[i][2]], hex[hex2tet_24[i][3]]});
      }
    }
    return tets;
  }

  const std::array<std::array<double, 3>, 4> tet_ideal_shape = {
    array<double, 3>{.5, 0, -1. / (2. * std::sqrt(2.))},
    array<double, 3>{-.5, 0, -1. / (2. * std::sqrt(2.))},
    array<double, 3>{0, .5, 1. / (2. * std::sqrt(2.))},
    array<double, 3>{0, -.5, 1. / (2. * std::sqrt(2.))},
  };

  const std::vector<std::array<double, 3>> unit_cube = {
    {0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
    {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};

  const std::vector<std::array<double, 3>> unit_pyr = {
    {0., 0., 0.},
    {1., 0., 0.},
    {1., 1., 0.},
    {0., 1., 0.},
    {0.5, 0.5, 1. / std::sqrt(2.)}};

  std::vector<std::array<std::array<double, 3>, 4>> tetsFromHexTargetShape(
    HexDcp dcp = TO_32TETS,
    const std::vector<std::array<double, 3>> &target = unit_cube)
  {
    if(target.size() != 8) {
      Msg::Error("target shape, wrong size, expects 8 and not %li",
                 target.size());
      return {};
    }
    std::vector<std::array<std::array<double, 3>, 4>> shapes;
    if(dcp == TO_8TETS || dcp == TO_32TETS) {
      for(size_t i = 0; i < 8; ++i) {
        shapes.push_back(
          {target[hex2tet_corners[i][0]], target[hex2tet_corners[i][1]],
           target[hex2tet_corners[i][2]], target[hex2tet_corners[i][3]]});
      }
    }
    if(dcp == TO_24TETS || dcp == TO_32TETS) {
      for(size_t i = 0; i < 24; ++i) {
        shapes.push_back({target[hex2tet_24[i][0]], target[hex2tet_24[i][1]],
                          target[hex2tet_24[i][2]], target[hex2tet_24[i][3]]});
      }
    }
    return shapes;
  }

  std::array<uint32_t, 4> invert_tet(const std::array<uint32_t, 4> &tet)
  { return {tet[0], tet[1], tet[3], tet[2]}; }

  std::array<array<double, 3>, 4>
  invert_shape(const std::array<array<double, 3>, 4> &shape)
  { return {shape[0], shape[1], shape[3], shape[2]}; }

} // namespace

static bool buildTetrahedraFromElements(
  const std::vector<std::vector<uint32_t>> &elements,
  const std::vector<std::vector<std::array<double, 3>>> &elementTargetShapes,
  std::vector<std::array<uint32_t, 4>> &tets,
  std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes, int dcpHex)
{
  tetIdealShapes.clear();
  tets.clear();

  HexDcp dcp = HexDcp::TO_32TETS;
  if(dcpHex == 32) { dcp = HexDcp::TO_32TETS; }
  else if(dcpHex == 8) {
    dcp = HexDcp::TO_8TETS;
  }
  else if(dcpHex == 24) {
    dcp = HexDcp::TO_24TETS;
  }
  else {
    Msg::Error("decomposition not supported");
    return false;
  }

  for(size_t e = 0; e < elements.size(); ++e) {
    const vector<uint32_t> &vert = elements[e];
    if(vert.size() == 4) {
      array<uint32_t, 4> tet = {vert[0], vert[1], vert[2], vert[3]};

      // warning: tet orientation in untangler is inverted compared to gmsh
      // orientation
      tet = invert_tet(tet);

      tets.push_back(tet);
      if(e < elementTargetShapes.size()) {
        std::array<std::array<double, 3>, 4> ishape = {
          elementTargetShapes[e][0], elementTargetShapes[e][1],
          elementTargetShapes[e][2], elementTargetShapes[e][3]};
        // warning: tet orientation in untangler is inverted compared to gmsh
        // orientation
        ishape = invert_shape(ishape);
        tetIdealShapes.push_back(ishape);
      }
      else {
        tetIdealShapes.push_back(tet_ideal_shape);
      }
    }
    else if(vert.size() == 8) {
      const array<uint32_t, 8> hex = {vert[0], vert[1], vert[2], vert[3],
                                      vert[4], vert[5], vert[6], vert[7]};
      vector<array<uint32_t, 4>> htets = tetsFromHex(hex, dcp);
      vector<array<array<double, 3>, 4>> shapes;
      if(e < elementTargetShapes.size()) {
        shapes = tetsFromHexTargetShape(dcp, elementTargetShapes[e]);
      }
      else {
        shapes = tetsFromHexTargetShape(dcp, unit_cube);
      }

      for(size_t j = 0; j < htets.size(); ++j) {
        array<uint32_t, 4> tet = htets[j];
        array<array<double, 3>, 4> shape = shapes[j];

        // warning: tet orientation in untangler is inverted compared to gmsh
        // orientation
        tet = invert_tet(tet);
        shape = invert_shape(shape);

        tets.push_back(tet);
        tetIdealShapes.push_back(shape);
      }
    }
    else if(vert.size() == 5) {
      for(size_t j = 0; j < 4; ++j) {
        array<uint32_t, 4> tet = {
          vert[pyr2tet_corners[j][0]], vert[pyr2tet_corners[j][1]],
          vert[pyr2tet_corners[j][2]], vert[pyr2tet_corners[j][3]]};
        array<array<double, 3>, 4> shape = {
          unit_pyr[pyr2tet_corners[j][0]], unit_pyr[pyr2tet_corners[j][1]],
          unit_pyr[pyr2tet_corners[j][2]], unit_pyr[pyr2tet_corners[j][3]]};

        tet = invert_tet(tet);
        shape = invert_shape(shape);

        tets.push_back(tet);
        tetIdealShapes.push_back(shape);
      }
    }
    else if(vert.size() == 6) {
      Msg::Error("prism not supported yet, abort");
      return false;
    }
    else {
      Msg::Error("case not supported, abort");
      return false;
    }
  }

  return true;
}

static bool buildVerticesAndTetrahedra(
  GRegion *gr, vector<MVertex *> &vertices, vector<vec3> &points,
  vector<bool> &locked, vector<std::array<uint32_t, 4>> &tets,
  std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes)
{
  vertices.clear();
  points.clear();
  locked.clear();
  tetIdealShapes.clear();
  tets.clear();

  std::unordered_map<MVertex *, uint32_t> old2new;
  vector<vector<uint32_t>> elements(gr->getNumMeshElements());
  for(size_t e = 0; e < gr->getNumMeshElements(); ++e) {
    MElement *elt = gr->getMeshElement(e);
    size_t n = elt->getNumVertices();
    vector<uint32_t> &vert = elements[e];
    vert.resize(n);
    for(size_t lv = 0; lv < n; ++lv) {
      MVertex *v = elt->getVertex(lv);
      auto it = old2new.find(v);
      if(it == old2new.end()) {
        old2new[v] = vertices.size();
        vert[lv] = vertices.size();
        vertices.push_back(v);
      }
      else {
        vert[lv] = it->second;
      }
    }
  }

  points.resize(vertices.size());
  locked.clear();
  locked.resize(vertices.size(), false);
  for(size_t v = 0; v < points.size(); ++v) {
    points[v] = {vertices[v]->x(), vertices[v]->y(), vertices[v]->z()};
    if(vertices[v]->onWhat()->dim() <= 2) { locked[v] = true; }
  }

  const int dcpHex = 32;
  std::vector<std::vector<std::array<double, 3>>> elementTargetShapes;
  bool okb = buildTetrahedraFromElements(elements, elementTargetShapes, tets,
                                         tetIdealShapes, dcpHex);
  if(!okb) {
    Msg::Error("Failed to build tets from elements");
    return false;
  }

  return true;
}

static void computeSICNquality(GRegion *gr, double &sicnMin, double &sicnAvg)
{
  sicnMin = DBL_MAX;
  sicnAvg = 0.;
  std::size_t n = 0;
  for(std::size_t i = 0; i < gr->getNumMeshElements(); ++i) {
    MElement *e = gr->getMeshElement(i);
    if(e->getType() != TYPE_TET && e->getType() != TYPE_HEX &&
       e->getType() != TYPE_PRI && e->getType() != TYPE_PYR)
      continue;
    double q = e->minSICNShapeMeasure();
    if(std::isnan(q)) q = -1.;
    sicnMin = std::min(sicnMin, q);
    sicnAvg += q;
    n++;
  }
  if(n) sicnAvg /= double(n);
}

bool untangleGRegionMeshConstrained(GRegion *gr, int iterMax, double timeMax)
{
  if(gr->getNumMeshElements() == 0) {
    Msg::Debug("- Region %i: no elements", gr->tag());
    return false;
  }

  double t0 = Cpu();

  double sicnMinB, sicnAvgB;
  computeSICNquality(gr, sicnMinB, sicnAvgB);

  vector<MVertex *> vertices;
  vector<vec3> points;
  vector<bool> locked;
  vector<std::array<uint32_t, 4>> tets;
  std::vector<std::array<std::array<double, 3>, 4>> tetIdealShapes;
  if(!buildVerticesAndTetrahedra(gr, vertices, points, locked, tets,
                                 tetIdealShapes))
    return false;

  WinslowUntangler::Options options;
  options.lambda = 1.025;
  options.maxInnerIterations = 300;
  options.maxOuterIterations = iterMax;
  options.maxFailures = 10;
  options.timeMax = timeMax;
  options.numThreads = CTX::instance()->numThreadsFor(tets.size(), 5000);
  WinslowUntangler::untangle3D(points, locked, tets, tetIdealShapes, options);

  for(size_t v = 0; v < points.size(); ++v)
    if(!locked[v]) {
      vertices[v]->setXYZ(points[v][0], points[v][1], points[v][2]);
    }

  double sicnMinA, sicnAvgA;
  computeSICNquality(gr, sicnMinA, sicnAvgA);

  Msg::Info("- Region %i: Winslow untangling, SICN min: %.3f -> %.3f, avg: "
            "%.3f -> %.3f (%li vertices, %.3f seconds)",
            gr->tag(), sicnMinB, sicnMinA, sicnAvgB, sicnAvgA, vertices.size(),
            Cpu() - t0);

  return true;
}
