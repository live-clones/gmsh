// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// References: Solin, P., Segeth, K., & Dolezel, I. (2003). Higher-Order Finite
// Element Methods. Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041
// Zaglmayr, S. (2006). High Order Finite Element Methods for Electromagnetic
// Field Computation. PhD thesis, Johannes Kepler University Linz.

#ifndef HDIV_PRISM_H
#define HDIV_PRISM_H

#include "HierarchicalBasis.h"
#include "HcurlPrism.h"
#include "HdivTriangle.h"

// H(div) basis on the prism of base (0, 0), (1, 0), (0, 1) and height w in
// [-1, 1], with the affine coordinates L0 = 1 - u - v, L1 = u, L2 = v of the
// triangle, B = (1 - w) / 2 and T = (1 + w) / 2: the space D_p x P_p(w) + P_p x
// P_p+1(w) e_w, D_p being the H(div) space of the triangle (HdivTriangle), so
// that its normal traces are those of HdivTetrahedron on the triangular faces
// and of HdivHexahedron on the quadrilateral faces, and its divergences span
// P_p x P_p (L2Legendre):
// - on the quadrilateral faces, as on the faces of the hexahedron, the lowest
//   order function, then the curls of the rotational H(curl) functions of the
//   face (see HcurlPrism) by increasing order;
// - on the triangular faces s3 (bottom) and s4 (top), B or T times the vertical
//   fields whose normal traces are those of the faces of HdivTetrahedron: the
//   Whitney 2-form of the face, then the curls of its rotational H(curl)
//   functions of order l + 1 (see hcurlTriangleRotational), for the orders l;
// - in the interior, the face functions d of HdivTriangle times L_k(w), and the
//   products q of Legendre polynomials of degree at most p of 2 u - 1 and 2 v -
//   1 times l_k(w) e_w, by increasing order;
// where L_k are the Legendre polynomials and l_k the Lobatto polynomials. The
// divergence-free functions of this space are not all curls of H(curl)
// functions of the same order, nor local to one face, so the space is not
// split into parts.
class HdivPrism : public HierarchicalBasis {
public:
  HdivPrism(int order);
  void functionInfo(std::vector<FunctionInfo> &info) override;
  void functions(const Dual *x, std::vector<Vec> &vertex,
                 std::vector<Vec> &edge, std::vector<Vec> &face,
                 std::vector<Vec> &bubble) override;
  void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                     int faceNumber, std::vector<Vec> &face) override;

private:
  int _order;
  HcurlPrism _hcurl;
  HdivTriangle _triangle;
  // the functions of quadrilateral face f, from its H(curl) functions c, in
  // the orientation given by the flags
  void _quadrangle(const Dual *x, int f, int flag1, int flag2, int flag3,
                   const Vec *c, Vec *out);
  // the functions of triangular face f (0 for the bottom, 1 for the top), the
  // roles of its vertices given by r
  void _triangleFace(const Dual *x, int f, const int *r, Vec *out);
};

#endif
