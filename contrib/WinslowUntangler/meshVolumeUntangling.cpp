// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshVolumeUntangling.h"

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
#include "MTetrahedron.h"
#include "MHexahedron.h"
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

  const std::vector<std::array<double, 3> > unit_cube = {
    {0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
    {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};

  const std::array<std::array<double, 3>, 4> tet_ideal_shape = {
    array<double, 3>{.5, 0, -1. / (2. * std::sqrt(2.))},
    array<double, 3>{-.5, 0, -1. / (2. * std::sqrt(2.))},
    array<double, 3>{0, .5, 1. / (2. * std::sqrt(2.))},
    array<double, 3>{0, -.5, 1. / (2. * std::sqrt(2.))},
  };

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
  int dcpHex)
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

  std::unordered_map<MVertex *, uint32_t> old2new;
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
        tetIdealShapes.push_back(shape);
      }
    }
    else if(vert.size() == 5) {
      Msg::Error("pyramid not supported yet, abort");
      return false;
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

bool buildVerticesAndTetrahedra(
  GRegion *gr, vector<MVertex *> &vertices, vector<vec3> &points,
  vector<bool> &locked, vector<std::array<uint32_t, 4> > &tets,
  std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes)
{
  vertices.clear();
  points.clear();
  locked.clear();
  tetIdealShapes.clear();
  tets.clear();

  std::unordered_map<MVertex *, uint32_t> old2new;
  vector<vector<uint32_t> > elements(gr->getNumMeshElements());
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
    points[v] = vertices[v]->point();
    if(vertices[v]->onWhat()->dim() <= 2) { locked[v] = true; }
  }

  const int dcpHex = 32;
  std::vector<std::vector<std::array<double, 3> > > elementTargetShapes;
  bool okb = buildTetrahedraFromElements(elements, elementTargetShapes, tets,
                                         tetIdealShapes, dcpHex);
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

  vector<MVertex *> vertices;
  vector<vec3> points;
  vector<bool> locked;
  vector<std::array<uint32_t, 4> > tets;
  std::vector<std::array<std::array<double, 3>, 4> > tetIdealShapes;
  buildVerticesAndTetrahedra(gr, vertices, points, locked, tets,
                             tetIdealShapes);
  invertTetsIfNecessary(points, tets, tetIdealShapes);

  /* Call Winslow untangler */
  int iterMaxInner = 300;
  int iterFailMax = 10;
  double lambda = 0.25;

  bool converged =
    untangle_tetrahedra(points, locked, tets, tetIdealShapes, lambda,
                        iterMaxInner, iterMax, iterFailMax, timeMax);

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

#else
bool untangleGRegionMeshConstrained(GFace *gf, int iterMax, double timeMax)
{
  Msg::Error(
    "Module QuadMeshingTools required for untangleGRegionMeshConstrained");
  return false;
}
#endif
