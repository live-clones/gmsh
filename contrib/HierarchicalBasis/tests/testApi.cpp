// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Consistency of the API functions with each other, and errors on unsupported
// requests:
// - the values for a subset of the orientations are the corresponding slices
//   of the values for all of them;
// - getKeysForElement() and getBasisFunctionsOrientationForElement() agree
//   with getKeys() and getBasisFunctionsOrientation();
// - unknown function spaces, unsupported elements and invalid orientations
//   raise an error (and do not crash).

#include <cmath>
#include <functional>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  static bool fails(const std::function<void()> &f)
  {
    try {
      f();
    } catch(...) {
      return true;
    }
    return false;
  }

  static void testOrientationSubsets()
  {
    Random r(6);
    for(auto &e : elements()) {
      std::vector<double> uvw = interiorPoints(e, 3, r);
      for(auto &s : spaces()) {
        if(!supported(s, e)) continue;
        for(int p = s.minOrder; p <= 3; p++) {
          for(int derivative = 0; derivative < 2; derivative++) {
            std::string fs = spaceType(s, p, derivative);
            Table first = evaluate(e.type, uvw, fs, {0});
            std::vector<int> o = orientations(first.totalOrientations, 16);
            std::vector<int> reversed(o.rbegin(), o.rend());
            Table sub = evaluate(e.type, uvw, fs, reversed);
            // all the orientations at once, unless there are too many
            Table all;
            if(first.totalOrientations <= 720) all = evaluate(e.type, uvw, fs);
            double diff = 0.;
            for(std::size_t i = 0; i < reversed.size(); i++) {
              Table one = evaluate(e.type, uvw, fs, {reversed[i]});
              for(int q = 0; q < one.numPoints; q++)
                for(int f = 0; f < one.numFunctions; f++)
                  for(int c = 0; c < one.numComponents; c++) {
                    diff = std::max(
                      diff, std::abs(one(0, q, f, c) - sub(i, q, f, c)));
                    if(all.numOrientations)
                      diff =
                        std::max(diff, std::abs(one(0, q, f, c) -
                                                all(reversed[i], q, f, c)));
                  }
            }
            check(diff == 0.,
                  "%s %s: values for a subset of orientations "
                  "differ by %g",
                  e.name.c_str(), fs.c_str(), diff);
          }
        }
      }
    }
  }

  static void testKeysAndOrientations()
  {
    for(int dim = 1; dim <= 3; dim++) {
      mixedMesh(dim);
      std::vector<int> types;
      gmsh::model::mesh::getElementTypes(types, dim);
      for(int type : types) {
        const Element *el = nullptr;
        for(auto &e : elements())
          if(e.type == type) el = &e;
        std::vector<std::size_t> tags, nodes;
        gmsh::model::mesh::getElementsByType(type, tags, nodes);
        for(auto &s : spaces()) {
          if(!supported(s, *el)) continue;
          for(int p = s.minOrder; p <= 3; p++) {
            std::string fs = spaceType(s, p);
            std::vector<int> typeKeys, ori;
            std::vector<std::size_t> entityKeys;
            std::vector<double> coord;
            gmsh::model::mesh::getKeys(type, fs, typeKeys, entityKeys, coord);
            gmsh::model::mesh::getBasisFunctionsOrientation(type, fs, ori);
            int nk = gmsh::model::mesh::getNumberOfKeys(type, fs);
            bool keysOk = typeKeys.size() == nk * tags.size() &&
                          coord.size() == 3 * typeKeys.size(),
                 oriOk = ori.size() == tags.size();
            for(std::size_t i = 0; i < tags.size() && keysOk && oriOk; i++) {
              std::vector<int> tk;
              std::vector<std::size_t> ek;
              std::vector<double> c;
              gmsh::model::mesh::getKeysForElement(tags[i], fs, tk, ek, c);
              for(int k = 0; k < nk; k++)
                if(tk[k] != typeKeys[i * nk + k] ||
                   ek[k] != entityKeys[i * nk + k] ||
                   c[3 * k] != coord[3 * (i * nk + k)])
                  keysOk = false;
              int o;
              gmsh::model::mesh::getBasisFunctionsOrientationForElement(tags[i],
                                                                        fs, o);
              if(o != ori[i]) oriOk = false;
            }
            check(keysOk, "%s %s: getKeysForElement differs from getKeys",
                  el->name.c_str(), fs.c_str());
            check(oriOk,
                  "%s %s: getBasisFunctionsOrientationForElement "
                  "differs from getBasisFunctionsOrientation",
                  el->name.c_str(), fs.c_str());
          }
        }
      }
    }
  }

  static void testErrors()
  {
    const std::vector<double> uvw = {0.1, 0.1, 0.1};
    auto bf = [&](int type, const std::string &fs, const std::vector<int> &o) {
      return fails([&]() { evaluate(type, uvw, fs, o); });
    };
    const int pyramid = 7;
    for(auto fs : {"H1Legendre1", "HcurlLegendre1", "HdivLegendre1"})
      check(bf(pyramid, fs, {}), "%s on pyramids: no error", fs);
    for(auto &e : elements())
      for(auto &s : spaces())
        if(s.kind == HDIV && !supported(s, e))
          check(bf(e.type, "HdivLegendre1", {}),
                "HdivLegendre1 on %s: no error", e.name.c_str());
    check(bf(4, "FooLegendre1", {}), "unknown function space: no error");
    for(auto fs : {"HcurlLegendre3:2", "HcurlLegendre:2", "Lagrange1:2",
                   "H1Legendre-1:2"})
      check(bf(4, fs, {}), "%s: no error", fs);
    for(auto fs : {"H1Legendre0", "HcurlLegendre-1", "HdivLegendre-1"})
      check(bf(2, fs, {}), "%s: no error", fs);
    // no maximum order
    for(auto fs : {"H1Legendre20", "HcurlLegendre16", "HdivLegendre16"})
      check(!bf(2, fs, {0}), "%s: error", fs);
    check(fails([]() { gmsh::model::mesh::getNumberOfKeys(7, "H1Legendre2"); }),
          "getNumberOfKeys on pyramids: no error");
    check(bf(2, "HcurlLegendre1", {-1}), "orientation -1: no error");
    check(bf(2, "HcurlLegendre1", {6}), "orientation 6 on triangles: no error");
    check(bf(2, "HcurlLegendre1", {1, 1}), "repeated orientation: no error");
    check(bf(2, "HcurlLegendre1", {0, 1, 2, 3, 4, 5, 0}),
          "too many orientations: no error");
    check(bf(2, "Lagrange", {1}), "orientation 1 for Lagrange: no error");
    // and the API still works afterwards
    check(!bf(2, "HcurlLegendre1", {5}), "valid call fails after errors");
  }

  void testApi()
  {
    testOrientationSubsets();
    testKeysAndOrientations();
    testErrors();
  }

} // namespace bt
