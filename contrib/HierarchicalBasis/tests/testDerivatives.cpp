// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The gradients of the H1 functions, the curls of the H(curl) functions and the
// divergences of the H(div) functions agree with finite differences, in all the
// orientations tested.

#include <algorithm>
#include <cmath>
#include "basisTest.h"

namespace bt {

  void testDerivatives()
  {
    const double h = 1e-6;
    Random r(2);
    for(auto &e : elements()) {
      if(e.dim == 0) continue;
      std::vector<double> uvw = interiorPoints(e, 8, r);
      for(auto &s : spaces()) {
        if(!supported(s, e)) continue;
        for(int p = s.minOrder; p <= maxOrder(e); p++) {
          std::string fs = spaceType(s, p);
          Table t = evaluate(e.type, uvw, fs, {0});
          std::vector<int> o = orientations(t.totalOrientations, 16);
          Table d = evaluate(e.type, uvw, spaceType(s, p, true), o);
          // dv[k](o, q, f, c): derivative of component c with respect to the
          // k-th reference coordinate
          std::vector<Table> dv(3);
          for(int k = 0; k < e.dim; k++) {
            std::vector<double> plus = uvw, minus = uvw;
            for(std::size_t q = 0; q < uvw.size() / 3; q++) {
              plus[3 * q + k] += h;
              minus[3 * q + k] -= h;
            }
            dv[k] = evaluate(e.type, plus, fs, o);
            Table m = evaluate(e.type, minus, fs, o);
            for(std::size_t i = 0; i < m.data.size(); i++)
              dv[k].data[i] = (dv[k].data[i] - m.data[i]) / (2 * h);
          }
          auto D = [&](int k, int o, int q, int f, int c) {
            return k < e.dim ? dv[k](o, q, f, c) : 0.;
          };
          double scale = 1., error = 0.;
          for(double v : d.data) scale = std::max(scale, std::abs(v));
          for(std::size_t i = 0; i < o.size(); i++)
            for(int q = 0; q < d.numPoints; q++)
              for(int f = 0; f < d.numFunctions; f++) {
                double fd[3] = {0., 0., 0.};
                if(s.kind == H1) {
                  for(int k = 0; k < 3; k++) fd[k] = D(k, i, q, f, 0);
                }
                else if(s.kind == HCURL && e.dim > 1) {
                  fd[0] = D(1, i, q, f, 2) - D(2, i, q, f, 1);
                  fd[1] = D(2, i, q, f, 0) - D(0, i, q, f, 2);
                  fd[2] = D(0, i, q, f, 1) - D(1, i, q, f, 0);
                }
                else if(s.kind == HDIV) {
                  for(int k = 0; k < 3; k++) fd[0] += D(k, i, q, f, k);
                }
                for(int c = 0; c < d.numComponents; c++)
                  error = std::max(error, std::abs(fd[c] - d(i, q, f, c)));
              }
          check(error < 1e-7 * scale,
                "%s %s: finite differences differ by %g (scale %g)",
                e.name.c_str(), spaceType(s, p, true).c_str(), error, scale);
        }
      }
    }
  }

} // namespace bt
