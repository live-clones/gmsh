// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshVolumeUntangling.h"

#include "winslowUntangler.h"
#include "winslowUntanglerGMSH.h"

#include <math.h>
#include <iostream> // debugging
#include <sstream>

#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "MVertex.h"
#include "MElement.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "GRegion.h"
#include "Numeric.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "arrayGeometry.h"

using namespace ArrayGeometry;
using std::array;
using std::vector;

namespace WinslowUntanglerVolume {
  const uint32_t pyr2tet_corners[4][4] = {
    {0, 1, 2, 4}, {1, 2, 3, 4}, {2, 3, 0, 4}, {3, 0, 1, 4}
  };

  // Triangular prism (0,1,2 bottom, 3,4,5 top, vertical edges 0-3,1-4,2-5)
  // split into 3 tets by a consistent "staircase" diagonal choice on the
  // 3 quad side faces.
  const uint32_t prism2tet_corners[3][4] = {
    {0, 1, 2, 3}, {1, 2, 3, 4}, {2, 3, 4, 5}
  };

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

  std::vector<std::array<uint32_t, 4> >
  tetsFromHex(const array<uint32_t, 8> &hex, HexDcp dcp = TO_24TETS)
  {
    vector<array<uint32_t, 4> > tets;
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

  const std::vector<std::array<double, 3> > unit_cube = {
    {0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
    {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};

  const std::vector<std::array<double, 3> > unit_pyr = {
    {0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
    {0.5, 0.5, 1./std::sqrt(2.)}};

  const std::vector<std::array<double, 3> > unit_prism = {
    {0., 0., 0.}, {1., 0., 0.}, {0.5, std::sqrt(3.) / 2., 0.},
    {0., 0., 1.}, {1., 0., 1.}, {0.5, std::sqrt(3.) / 2., 1.}};
    
  std::vector<std::array<std::array<double, 3>, 4> > tetsFromHexTargetShape(
    HexDcp dcp = TO_32TETS,
    const std::vector<std::array<double, 3> > &target = unit_cube)
  {
    if(target.size() != 8) {
      Msg::Error("target shape, wrong size, expects 8 and not %li",
                 target.size());
      return {};
    }
    std::vector<std::array<std::array<double, 3>, 4> > shapes;
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
  {
    return {tet[0], tet[1], tet[3], tet[2]};
  }

  std::array<array<double, 3>, 4>
  invert_shape(const std::array<array<double, 3>, 4> &shape)
  {
    return {shape[0], shape[1], shape[3], shape[2]};
  }

  inline double volume(vec3 a, vec3 b, vec3 c, vec3 d)
  {
    return dot((a - d), cross(b - d, c - d)) / 6.;
  }

  double volume(const std::vector<std::array<double, 3> > &points,
                const std::vector<std::array<uint32_t, 4> > &tets)
  {
    double sum = 0.;
    for(size_t i = 0; i < tets.size(); ++i) {
      sum += volume(points[tets[i][0]], points[tets[i][1]], points[tets[i][2]],
                    points[tets[i][3]]);
    }
    return sum;
  }

  void invertTetsIfNecessary(
    const std::vector<std::array<double, 3> > &points,
    std::vector<std::array<uint32_t, 4> > &tets,
    std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes)
  {
    if(tetIdealShapes.size() > 0) {
      double volIdealShapes = 0.;
      for(size_t i = 0; i < tetIdealShapes.size(); ++i) {
        volIdealShapes += volume(tetIdealShapes[i][0], tetIdealShapes[i][1],
                                 tetIdealShapes[i][2], tetIdealShapes[i][3]);
      }
      volIdealShapes /= double(tetIdealShapes.size());
      Msg::Debug("average volume ideal tets: %f", volIdealShapes);
    }

    double vol = volume(points, tets);
    Msg::Debug("region volume: %f", vol);
  }
} // namespace WinslowUntanglerVolume

using namespace WinslowUntanglerVolume;

bool buildTetrahedraFromElements(
  const std::vector<std::vector<uint32_t> > &elements,
  const std::vector<std::vector<std::array<double, 3> > > &elementTargetShapes,
  std::vector<std::array<uint32_t, 4> > &tets,
  std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
  int dcpHex, std::vector<size_t> *tetElementIndex)
{
  tetIdealShapes.clear();
  tets.clear();
  if(tetElementIndex) tetElementIndex->clear();

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

  std::unordered_map<MVertex *, uint32_t> old2new;
  for(size_t e = 0; e < elements.size(); ++e) {
    const vector<uint32_t> &vert = elements[e];
    if(vert.size() == 4) {
      array<uint32_t, 4> tet = {vert[0], vert[1], vert[2], vert[3]};

      // warning: tet orientation in untangler is inverted compared to gmsh
      // orientation
      tet = invert_tet(tet);

      tets.push_back(tet);
      if(tetElementIndex) tetElementIndex->push_back(e);
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
      vector<array<uint32_t, 4> > htets = tetsFromHex(hex, dcp);
      vector<array<array<double, 3>, 4> > shapes;
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
        if(tetElementIndex) tetElementIndex->push_back(e);
        tetIdealShapes.push_back(shape);
      }
    }
    else if(vert.size() == 5) {
      const array<uint32_t, 5> pyr = {vert[0], vert[1], vert[2], vert[3], vert[4]};

      for(size_t j = 0; j < 4; ++j) {
        array<uint32_t, 4> tet = {vert[pyr2tet_corners[j][0]],
				  vert[pyr2tet_corners[j][1]],
				  vert[pyr2tet_corners[j][2]],
				  vert[pyr2tet_corners[j][3]]};
        array<array<double, 3>, 4> shape = {unit_pyr[pyr2tet_corners[j][0]],
					    unit_pyr[pyr2tet_corners[j][1]],
					    unit_pyr[pyr2tet_corners[j][2]],
					    unit_pyr[pyr2tet_corners[j][3]]};

        tet = invert_tet(tet);
        shape = invert_shape(shape);

        tets.push_back(tet);
        if(tetElementIndex) tetElementIndex->push_back(e);
        tetIdealShapes.push_back(shape);
      }
    }
    else if(vert.size() == 6) {
      for(size_t j = 0; j < 3; ++j) {
        array<uint32_t, 4> tet = {vert[prism2tet_corners[j][0]],
                                  vert[prism2tet_corners[j][1]],
                                  vert[prism2tet_corners[j][2]],
                                  vert[prism2tet_corners[j][3]]};
        array<array<double, 3>, 4> shape = {
          unit_prism[prism2tet_corners[j][0]],
          unit_prism[prism2tet_corners[j][1]],
          unit_prism[prism2tet_corners[j][2]],
          unit_prism[prism2tet_corners[j][3]]};

        tet = invert_tet(tet);
        shape = invert_shape(shape);

        tets.push_back(tet);
        if(tetElementIndex) tetElementIndex->push_back(e);
        tetIdealShapes.push_back(shape);
      }
    }
    else {
      Msg::Error("case not supported, abort");
      return false;
    }
  }

  return true;
}

bool buildVerticesAndTetrahedra(
  GRegion *gr, vector<MVertex *> &vertices, vector<vec3> &points,
  vector<bool> &locked, vector<std::array<uint32_t, 4> > &tets,
  std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
  std::vector<MElement *> *sourceElements = nullptr,
  std::vector<size_t> *tetElementIndex = nullptr)
{
  vertices.clear();
  points.clear();
  locked.clear();
  tetIdealShapes.clear();
  tets.clear();

  std::unordered_map<MVertex *, uint32_t> old2new;
  // Trihedra (the hex/tet transition element of the hybrid hex-dominant
  // mesher) are not a shape this untangler's ideal-shape machinery knows
  // about: skip them rather than silently mistreating them as tets, since
  // their 4 vertices don't describe a regular tetrahedron.
  vector<vector<uint32_t> > elements;
  elements.reserve(gr->getNumMeshElements());
  if(sourceElements) sourceElements->clear();
  for(size_t e = 0; e < gr->getNumMeshElements(); ++e) {
    MElement *elt = gr->getMeshElement(e);
    if(elt->getType() == TYPE_TRIH) continue;
    size_t n = elt->getNumVertices();
    elements.push_back(vector<uint32_t>(n));
    if(sourceElements) sourceElements->push_back(elt);
    vector<uint32_t> &vert = elements.back();
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
    points[v] = vertices[v]->point();
    if(vertices[v]->onWhat()->dim() <= 2) { locked[v] = true; }
  }

  // TO_32TETS (8 corners + 24 face-diagonal tets) is not robust to hex
  // skew: the 24 face-diagonal tets can flip sign on a genuinely valid
  // but distorted hex (a real SICN=0.43 hex was observed with 23/24
  // consistently signed and 1 flipped), which falsely reports the
  // element as tangled and makes the energy landscape needlessly stiff.
  // TO_8TETS (corners only) is not a complete validity characterization
  // in theory, but is far more robust in practice.
  int dcpHex = 8;
  if(const char *env = getenv("GMSH_WINSLOW_DCPHEX")) dcpHex = atoi(env);
  std::vector<std::vector<std::array<double, 3> > > elementTargetShapes;
  bool okb = buildTetrahedraFromElements(elements, elementTargetShapes, tets,
                                         tetIdealShapes, dcpHex,
                                         tetElementIndex);
  if(!okb) {
    Msg::Error("Failed to build tets from elements");
    return false;
  }

  return true;
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

  if(getenv("GMSH_DEBUG_WORST_ELEMENT")) {
    struct Entry {
      double q;
      MElement *e;
      const char *tname;
    };
    std::vector<Entry> worst;
    auto scan = [&](const std::vector<MElement *> &elts, const char *name) {
      for(auto e : elts) {
        double q = e->minSICNShapeMeasure();
        if(std::isnan(q)) q = -1.;
        worst.push_back({q, e, name});
      }
    };
    std::vector<MElement *> tetElts, hexElts, priElts, pyrElts;
    for(auto e : gr->tetrahedra) tetElts.push_back(e);
    for(auto e : gr->hexahedra) hexElts.push_back(e);
    for(auto e : gr->prisms) priElts.push_back(e);
    for(auto e : gr->pyramids) pyrElts.push_back(e);
    scan(tetElts, "tet");
    scan(hexElts, "hex");
    scan(priElts, "prism");
    scan(pyrElts, "pyramid");
    std::sort(worst.begin(), worst.end(),
              [](const Entry &a, const Entry &b) { return a.q < b.q; });
    for(int i = 0; i < 10 && i < (int)worst.size(); i++) {
      MElement *e = worst[i].e;
      std::ostringstream verts;
      for(std::size_t k = 0; k < e->getNumVertices(); k++)
        verts << e->getVertex((int)k)->getNum() << " ";
      Msg::Info("- debug: worst element #%d: type=%s num=%d SICN=%.4f "
                "verts: %s",
                i, worst[i].tname, e->getNum(), worst[i].q,
                verts.str().c_str());
    }
  }

  vector<MVertex *> vertices;
  vector<vec3> points;
  vector<bool> locked;
  vector<std::array<uint32_t, 4> > tets;
  std::vector<std::array<std::array<double, 3>, 4> > tetIdealShapes;
  std::vector<MElement *> sourceElements;
  std::vector<size_t> tetElementIndex;
  buildVerticesAndTetrahedra(gr, vertices, points, locked, tets,
                             tetIdealShapes, &sourceElements,
                             &tetElementIndex);
  invertTetsIfNecessary(points, tets, tetIdealShapes);

  if(getenv("GMSH_WINSLOW_DEBUG_ITER1")) {
    int shown = 0;
    for(size_t t = 0; t < tets.size() && shown < 5; t++) {
      double v = volume(std::vector<vec3>(points.begin(), points.end()),
                        std::vector<std::array<uint32_t, 4> >(1, tets[t]));
      double vi = volume(tetIdealShapes[t][0], tetIdealShapes[t][1],
                         tetIdealShapes[t][2], tetIdealShapes[t][3]);
      if(v > 0) continue; // this sub-tet is fine
      shown++;
      MElement *src = sourceElements[tetElementIndex[t]];
      std::ostringstream verts, coords;
      for(std::size_t k = 0; k < src->getNumVertices(); k++) {
        MVertex *sv = src->getVertex((int)k);
        verts << sv->getNum() << " ";
        coords << "(" << sv->x() << "," << sv->y() << "," << sv->z() << ") ";
      }
      Msg::Info("- debug: invalid sub-tet %zu (vol=%.6g, ideal-vol=%.6g) "
                "comes from element num=%d type=%d SICN=%.6f, its %zu "
                "verts: %s coords: %s",
                t, v, vi, src->getNum(), src->getType(),
                src->minSICNShapeMeasure(), src->getNumVertices(),
                verts.str().c_str(), coords.str().c_str());
    }
  }

  /* Call Winslow untangler */
  int iterMaxInner = 300;
  int iterFailMax = 10;
  double lambda = 1.025;

  bool converged =
    untangle_tetrahedra_GMSH(points, locked, tets, tetIdealShapes, lambda,
                             iterMaxInner, iterMax, iterFailMax, timeMax);

  for(size_t v = 0; v < points.size(); ++v)
    if(!locked[v]) {
      vertices[v]->setXYZ(points[v][0], points[v][1], points[v][2]);
    }

  double sicnMinA, sicnAvgA;
  computeSICNquality(gr, sicnMinA, sicnAvgA);

  Msg::Info("- Region %i: Winslow untangling%s, SICN min: %.3f -> %.3f, avg: "
            "%.3f -> %.3f (%li vertices, %.3f seconds)",
            gr->tag(), converged ? "" : " (did not converge)", sicnMinB,
            sicnMinA, sicnAvgB, sicnAvgA, vertices.size(), Cpu() - t0);

  return true;
}

#else
bool untangleGRegionMeshConstrained(GRegion *gr, int iterMax, double timeMax)
{
  Msg::Error(
    "Module QuadMeshingTools required for untangleGRegionMeshConstrained");
  return false;
}
#endif
