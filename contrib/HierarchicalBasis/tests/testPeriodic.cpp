// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Periodic keys on curves: on a square whose opposite sides are periodic, each
// basis function on a slave curve, multiplied by the sign returned by
// getPeriodicKeys(), equals the basis function of the master key at the
// corresponding point of the master curve (value for H1, tangential component
// for H(curl)).

#include <cmath>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  typedef std::array<double, 3> Vec;

  // the element of the curve containing the point x, and the local coordinate
  // of x in it
  static std::size_t locate(int curve, const Vec &x, double &u)
  {
    std::vector<std::size_t> tags, nodes;
    gmsh::model::mesh::getElementsByType(1, tags, nodes, curve);
    for(auto tag : tags) {
      double v, w;
      gmsh::model::mesh::getLocalCoordinatesInElement(tag, x[0], x[1], x[2], u,
                                                      v, w);
      if(u >= -1 - 1e-10 && u <= 1 + 1e-10) {
        std::vector<double> jac, det, xyz;
        gmsh::model::mesh::getJacobian(tag, {u, 0., 0.}, jac, det, xyz);
        double d = std::hypot(xyz[0] - x[0], xyz[1] - x[1]);
        if(d < 1e-10) return tag;
      }
    }
    return 0;
  }

  // the value (H1) or the tangential component along the direction dir
  // (H(curl)) of basis function f of element tag at local coordinate u
  static double trace(std::size_t tag, const std::string &fs, int f, double u,
                      const Vec &dir)
  {
    int o;
    gmsh::model::mesh::getBasisFunctionsOrientationForElement(tag, fs, o);
    Table b = evaluate(1, {u, 0., 0.}, fs, {o});
    if(b.numComponents == 1) return b(0, 0, f, 0);
    std::vector<double> jac, det, xyz;
    gmsh::model::mesh::getJacobian(tag, {u, 0., 0.}, jac, det, xyz);
    Eigen::Map<const Eigen::Matrix<double, 3, 3, Eigen::RowMajor>> J(&jac[0]);
    Eigen::Vector3d v =
      J.inverse() *
      Eigen::Vector3d(b(0, 0, f, 0), b(0, 0, f, 1), b(0, 0, f, 2));
    return v.dot(Eigen::Vector3d(dir.data()));
  }

  void testPeriodic()
  {
    gmsh::clear();
    namespace geo = gmsh::model::geo;
    std::vector<std::pair<double, double>> xy = {
      {0, 0}, {1, 0}, {1, 1}, {0, 1}};
    for(int i = 0; i < 4; i++)
      geo::addPoint(xy[i].first, xy[i].second, 0, 0.13, i + 1);
    for(int i = 0; i < 4; i++) geo::addLine(i + 1, (i + 1) % 4 + 1, i + 1);
    geo::addCurveLoop({1, 2, 3, 4}, 1);
    geo::addPlaneSurface({1}, 1);
    geo::synchronize();
    // curve 2 (x = 1) is a copy of curve 4 (x = 0), curve 3 (y = 1) of curve 1
    gmsh::model::mesh::setPeriodic(
      1, {2}, {4}, {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    gmsh::model::mesh::setPeriodic(
      1, {3}, {1}, {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1});
    gmsh::model::mesh::generate(2);

    struct Case {
      int slave;
      Vec shift, dir;
    };
    std::vector<Case> cases = {{2, {1, 0, 0}, {0, 1, 0}},
                               {3, {0, 1, 0}, {1, 0, 0}}};
    std::vector<std::string> fss = {"Lagrange"};
    for(int p = 1; p <= 4; p++) fss.push_back("H1Legendre" + std::to_string(p));
    for(int p = 0; p <= 4; p++)
      fss.push_back("HcurlLegendre" + std::to_string(p));
    for(auto &c : cases) {
      std::vector<std::size_t> tags, nodes;
      gmsh::model::mesh::getElementsByType(1, tags, nodes, c.slave);
      for(auto &fs : fss) {
        int master;
        std::vector<int> tk, tkm, sign;
        std::vector<std::size_t> ek, ekm;
        std::vector<double> x, xm;
        gmsh::model::mesh::getPeriodicKeys(1, fs, c.slave, master, tk, tkm, ek,
                                           ekm, x, xm, sign);
        int nk = gmsh::model::mesh::getNumberOfKeys(1, fs);
        bool sizes = (tk.size() == nk * tags.size() &&
                      tkm.size() == tk.size() && sign.size() == tk.size() &&
                      x.size() == 3 * tk.size() && xm.size() == x.size());
        check(sizes, "periodic curve %d %s: wrong sizes", c.slave, fs.c_str());
        if(!sizes) continue;
        double coordError = 0., valueError = 0., scale = 1.;
        int unmatched = 0;
        for(std::size_t j = 0; j < tk.size(); j++) {
          for(int k = 0; k < 3; k++)
            coordError = std::max(
              coordError, std::abs(xm[3 * j + k] + c.shift[k] - x[3 * j + k]));
          if(fs == "Lagrange") continue;
          // a point of the slave element and the corresponding master point
          std::size_t e = tags[j / nk];
          std::vector<double> jac, det, xyz;
          const double u = 0.37;
          gmsh::model::mesh::getJacobian(e, {u, 0., 0.}, jac, det, xyz);
          Vec q = {xyz[0] - c.shift[0], xyz[1] - c.shift[1], 0.};
          double um;
          std::size_t em = locate(master, q, um);
          std::vector<int> mtk;
          std::vector<std::size_t> mek;
          std::vector<double> mc;
          if(em)
            gmsh::model::mesh::getKeysForElement(em, fs, mtk, mek, mc, false);
          int fm = -1;
          for(std::size_t i = 0; i < mtk.size(); i++)
            if(mtk[i] == tkm[j] && mek[i] == ekm[j]) fm = i;
          if(fm < 0) {
            unmatched++;
            continue;
          }
          double vs = trace(e, fs, j % nk, u, c.dir);
          double vm = trace(em, fs, fm, um, c.dir);
          valueError = std::max(valueError, std::abs(sign[j] * vs - vm));
          scale = std::max(scale, std::abs(vm));
        }
        check(coordError < 1e-10 && !unmatched && valueError < 1e-10 * scale,
              "periodic curve %d %s: coordinates differ by %g, %d unmatched "
              "keys, values differ by %g (relative to %g)",
              c.slave, fs.c_str(), coordError, unmatched, valueError, scale);
      }
    }
  }

} // namespace bt
