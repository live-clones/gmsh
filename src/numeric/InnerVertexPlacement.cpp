// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Amaury Johnen

#include "InnerVertexPlacement.h"
#include "GmshDefines.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "ElementType.h"
#include "nodalBasis.h"
#include "MTriangle.h"
#include "MTetrahedron.h"

namespace {
  typedef std::pair<std::pair<int, int>, int> mytuple;

  mytuple make_mytuple(int a, int b, int c)
  {
    return std::make_pair(std::make_pair(a, b), c);
  }

  void double2int(const fullMatrix<double> &doubleMat, fullMatrix<int> &intMat)
  {
    intMat.resize(doubleMat.size1(), doubleMat.size2(), false);
    for(int i = 0; i < intMat.size1(); ++i) {
      for(int j = 0; j < intMat.size2(); ++j) {
        intMat(i, j) = static_cast<int>(doubleMat(i, j) + .5);
      }
    }
  }

  std::map<int, fullMatrix<double> *> storedMatrices[6];
} // namespace

fullMatrix<double> *getInnerVertexPlacement(int type, int order)
{
  if(type < 3 || type > 8) return nullptr;
  std::map<int, fullMatrix<double> *>::iterator it;
  it = storedMatrices[type - 3].find(order);
  if(it != storedMatrices[type - 3].end()) { return it->second; }
  else {
    fullMatrix<double> *matrix = new fullMatrix<double>();
    switch(type) {
    case TYPE_TRI:
      *matrix = gmshGenerateInnerVertexPlacementTriangle(order);
      break;
    case TYPE_QUA:
      *matrix = gmshGenerateInnerVertexPlacementQuadrangle(order);
      break;
    case TYPE_TET:
      *matrix = gmshGenerateInnerVertexPlacementTetrahedron(order);
      break;
    case TYPE_PRI:
      *matrix = gmshGenerateInnerVertexPlacementPrism(order);
      break;
    case TYPE_HEX:
      *matrix = gmshGenerateInnerVertexPlacementHexahedron(order);
      break;
    case TYPE_PYR:
      *matrix = gmshGenerateInnerVertexPlacementPyramid(order);
      break;
    }
    storedMatrices[type - 3][order] = matrix;
    return matrix;
  }
}

fullMatrix<double> gmshGenerateInnerVertexPlacementTriangle(int order)
{
  if(order < 3) return fullMatrix<double>();

  const int szInc = 3 * order;
  const int szInt = (order + 1) * (order + 2) / 2 - szInc;

  fullMatrix<double> monomials = gmshGenerateMonomialsTriangle(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<std::pair<int, int>, int> coord2idx;
  for(int i = 0; i < szInc; ++i)
    coord2idx[std::make_pair(coordinates(i, 0), coordinates(i, 1))] = i;
  auto col = [&](const int b[3]) {
    return coord2idx[std::make_pair(b[1], b[2])];
  };

  // Lagrange basis of an edge (on [-1, 1]), whose nodes are numbered as the
  // monomials
  const nodalBasis *lineBasis =
    BasisFactory::getNodalBasis(ElementType::getType(TYPE_LIN, order));
  const fullMatrix<double> lineMonomials = gmshGenerateMonomialsLine(order);

  std::vector<double> sfLine(lineBasis->getNumShapeFunctions());
  fullMatrix<double> M(szInt, szInc, true);
  for(int r = 0; r < szInt; ++r) {
    const int u = coordinates(szInc + r, 0), v = coordinates(szInc + r, 1);
    const int a[3] = {order - u - v, u, v};
    double l[3];
    for(int i = 0; i < 3; ++i) l[i] = (double)a[i] / order;

    // affine part: + lambda_i P_i
    for(int i = 0; i < 3; ++i) M(r, i) += l[i];

    // edge terms: + we (phi(tau) - (1 - tau) P_i - tau P_j)
    for(int e = 0; e < 3; ++e) {
      const int i = MTriangle::edges_tri(e, 0);
      const int j = MTriangle::edges_tri(e, 1);
      const double tau = 0.5 * (1. - l[i] + l[j]);
      const double we = l[i] * l[j] / (tau * (1. - tau));
      lineBasis->f(2. * tau - 1., 0., 0., &sfLine[0]);
      for(int q = 0; q <= order; ++q) {
        const int s = (int)lineMonomials(q, 0);
        int b[3] = {0, 0, 0};
        b[i] = order - s;
        b[j] = s;
        M(r, col(b)) += we * sfLine[q];
      }
      M(r, i) -= we * (1. - tau);
      M(r, j) -= we * tau;
    }
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementQuadrangle(int order)
{
  if(order < 2) return fullMatrix<double>();

  const int szInc = 4 * order;
  const int szComp = (order + 1) * (order + 1);
  const int szInt = szComp - szInc;

  fullMatrix<double> monomials = gmshGenerateMonomialsQuadrangle(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<std::pair<int, int>, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    coord2idx[std::make_pair(u, v)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    double xi = (double)u / n;
    double eta = (double)v / n;

    M(i, coord2idx[std::make_pair(0, v)]) += 1 - xi;
    M(i, coord2idx[std::make_pair(n, v)]) += xi;
    M(i, coord2idx[std::make_pair(u, 0)]) += 1 - eta;
    M(i, coord2idx[std::make_pair(u, n)]) += eta;
    M(i, coord2idx[std::make_pair(0, 0)]) -= (1 - xi) * (1 - eta);
    M(i, coord2idx[std::make_pair(n, 0)]) -= xi * (1 - eta);
    M(i, coord2idx[std::make_pair(n, n)]) -= xi * eta;
    M(i, coord2idx[std::make_pair(0, n)]) -= (1 - xi) * eta;
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementTetrahedron(int order)
{
  if(order < 4) return fullMatrix<double>();

  const int szInt = (order - 3) * (order - 2) * (order - 1) / 6;
  const int szInc = (order + 1) * (order + 2) * (order + 3) / 6 - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsTetrahedron(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i)
    coord2idx[make_mytuple(coordinates(i, 0), coordinates(i, 1),
                           coordinates(i, 2))] = i;
  auto col = [&](const int b[4]) {
    return coord2idx[make_mytuple(b[1], b[2], b[3])];
  };

  // Lagrange basis of an edge (on [-1, 1]) and of a face (on (0, 0), (1, 0),
  // (0, 1)), whose nodes are numbered as the monomials
  const nodalBasis *lineBasis =
    BasisFactory::getNodalBasis(ElementType::getType(TYPE_LIN, order));
  const nodalBasis *triBasis =
    BasisFactory::getNodalBasis(ElementType::getType(TYPE_TRI, order));
  const fullMatrix<double> lineMonomials = gmshGenerateMonomialsLine(order);
  fullMatrix<double> triMonomials = gmshGenerateMonomialsTriangle(order, false);
  fullMatrix<int> triCoord;
  double2int(triMonomials, triCoord);
  const fullMatrix<double> triRule =
    gmshGenerateInnerVertexPlacementTriangle(order);
  const int szIncTri = 3 * order;

  std::vector<double> sfLine(lineBasis->getNumShapeFunctions());
  std::vector<double> sfTri(triBasis->getNumShapeFunctions());
  fullMatrix<double> M(szInt, szInc, true);
  for(int r = 0; r < szInt; ++r) {
    const int u = coordinates(szInc + r, 0), v = coordinates(szInc + r, 1),
              w = coordinates(szInc + r, 2);
    const int a[4] = {order - u - v - w, u, v, w};
    double l[4];
    for(int i = 0; i < 4; ++i) l[i] = (double)a[i] / order;

    // affine part: + lambda_i P_i
    for(int i = 0; i < 4; ++i) M(r, i) += l[i];

    // edge terms: + we (phi(tau) - (1 - tau) P_i - tau P_j)
    for(int e = 0; e < 6; ++e) {
      const int i = MTetrahedron::edges_tetra(e, 0);
      const int j = MTetrahedron::edges_tetra(e, 1);
      const double tau = 0.5 * (1. - l[i] + l[j]);
      const double we = l[i] * l[j] / (tau * (1. - tau));
      lineBasis->f(2. * tau - 1., 0., 0., &sfLine[0]);
      for(int q = 0; q <= order; ++q) {
        const int s = (int)lineMonomials(q, 0);
        int b[4] = {0, 0, 0, 0};
        b[i] = order - s;
        b[j] = s;
        M(r, col(b)) += we * sfLine[q];
      }
      M(r, i) -= we * (1. - tau);
      M(r, j) -= we * tau;
    }

    // face terms: + wf (phi(s_j, s_k) - triRule(s_j, s_k))
    for(int f = 0; f < 4; ++f) {
      int fv[3];
      for(int c = 0; c < 3; ++c) fv[c] = MTetrahedron::faces_tetra(f, c);
      const int m = 6 - fv[0] - fv[1] - fv[2];
      std::vector<int> fCol(triCoord.size1()); // column of each face node
      for(int c = 0; c < triCoord.size1(); ++c) {
        int b[4] = {0, 0, 0, 0};
        b[fv[0]] = order - triCoord(c, 0) - triCoord(c, 1);
        b[fv[1]] = triCoord(c, 0);
        b[fv[2]] = triCoord(c, 1);
        fCol[c] = col(b);
      }
      double s[3];
      for(int c = 0; c < 3; ++c) s[c] = l[fv[c]] + l[m] / 3.;
      const double wf = l[fv[0]] * l[fv[1]] * l[fv[2]] / (s[0] * s[1] * s[2]);
      triBasis->f(s[1], s[2], 0., &sfTri[0]);
      for(int p = 0; p < triRule.size1(); ++p) {
        const double c = wf * sfTri[szIncTri + p];
        M(r, fCol[szIncTri + p]) += c;
        for(int cc = 0; cc < szIncTri; ++cc)
          M(r, fCol[cc]) -= c * triRule(p, cc);
      }
    }
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementHexahedron(int order)
{
  if(order < 2) return fullMatrix<double>();

  const int szInt = (order - 1) * (order - 1) * (order - 1);
  const int szComp = (order + 1) * (order + 1) * (order + 1);
  const int szInc = szComp - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsHexahedron(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[make_mytuple(u, v, w)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    double xi = (double)u / n;
    double eta = (double)v / n;
    double zeta = (double)w / n;

    M(i, coord2idx[make_mytuple(0, v, w)]) += 1 - xi;
    M(i, coord2idx[make_mytuple(n, v, w)]) += xi;
    M(i, coord2idx[make_mytuple(u, 0, w)]) += 1 - eta;
    M(i, coord2idx[make_mytuple(u, n, w)]) += eta;
    M(i, coord2idx[make_mytuple(u, v, 0)]) += 1 - zeta;
    M(i, coord2idx[make_mytuple(u, v, n)]) += zeta;

    M(i, coord2idx[make_mytuple(0, 0, w)]) -= (1 - xi) * (1 - eta);
    M(i, coord2idx[make_mytuple(0, n, w)]) -= (1 - xi) * eta;
    M(i, coord2idx[make_mytuple(n, 0, w)]) -= xi * (1 - eta);
    M(i, coord2idx[make_mytuple(n, n, w)]) -= xi * eta;
    M(i, coord2idx[make_mytuple(u, 0, 0)]) -= (1 - eta) * (1 - zeta);
    M(i, coord2idx[make_mytuple(u, 0, n)]) -= (1 - eta) * zeta;
    M(i, coord2idx[make_mytuple(u, n, 0)]) -= eta * (1 - zeta);
    M(i, coord2idx[make_mytuple(u, n, n)]) -= eta * zeta;
    M(i, coord2idx[make_mytuple(0, v, 0)]) -= (1 - zeta) * (1 - xi);
    M(i, coord2idx[make_mytuple(n, v, 0)]) -= (1 - zeta) * xi;
    M(i, coord2idx[make_mytuple(0, v, n)]) -= zeta * (1 - xi);
    M(i, coord2idx[make_mytuple(n, v, n)]) -= zeta * xi;

    M(i, coord2idx[make_mytuple(0, 0, 0)]) += (1 - xi) * (1 - eta) * (1 - zeta);
    M(i, coord2idx[make_mytuple(0, 0, n)]) += (1 - xi) * (1 - eta) * zeta;
    M(i, coord2idx[make_mytuple(0, n, 0)]) += (1 - xi) * eta * (1 - zeta);
    M(i, coord2idx[make_mytuple(0, n, n)]) += (1 - xi) * eta * zeta;
    M(i, coord2idx[make_mytuple(n, 0, 0)]) += xi * (1 - eta) * (1 - zeta);
    M(i, coord2idx[make_mytuple(n, 0, n)]) += xi * (1 - eta) * zeta;
    M(i, coord2idx[make_mytuple(n, n, 0)]) += xi * eta * (1 - zeta);
    M(i, coord2idx[make_mytuple(n, n, n)]) += xi * eta * zeta;
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementPrism(int order)
{
  if(order < 3) return fullMatrix<double>();

  const int szInt = (order - 1) * (order - 2) * (order - 1) / 2;
  const int szComp = (order + 1) * (order + 1) * (order + 2) / 2;
  const int szInc = szComp - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsPrism(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[make_mytuple(u, v, w)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    int q = n - u - v;
    double xi = (double)u / n;
    double eta = (double)v / n;
    double zeta = (double)w / n;
    double rho = (double)q / n;

    M(i, coord2idx[make_mytuple(u + v, 0, w)]) += xi;
    M(i, coord2idx[make_mytuple(u + q, v, w)]) += xi;
    M(i, coord2idx[make_mytuple(0, v + u, w)]) += eta;
    M(i, coord2idx[make_mytuple(u, v + q, w)]) += eta;
    M(i, coord2idx[make_mytuple(0, v, w)]) += rho;
    M(i, coord2idx[make_mytuple(u, 0, w)]) += rho;
    M(i, coord2idx[make_mytuple(u, v, 0)]) += 1 - zeta;
    M(i, coord2idx[make_mytuple(u, v, n)]) += zeta;

    M(i, coord2idx[make_mytuple(n, 0, w)]) -= xi;
    M(i, coord2idx[make_mytuple(0, n, w)]) -= eta;
    M(i, coord2idx[make_mytuple(0, 0, w)]) -= rho;
    M(i, coord2idx[make_mytuple(u + v, 0, 0)]) -= xi * (1 - zeta);
    M(i, coord2idx[make_mytuple(u + q, v, 0)]) -= xi * (1 - zeta);
    M(i, coord2idx[make_mytuple(0, v + u, 0)]) -= eta * (1 - zeta);
    M(i, coord2idx[make_mytuple(u, v + q, 0)]) -= eta * (1 - zeta);
    M(i, coord2idx[make_mytuple(0, v, 0)]) -= rho * (1 - zeta);
    M(i, coord2idx[make_mytuple(u, 0, 0)]) -= rho * (1 - zeta);
    M(i, coord2idx[make_mytuple(u + v, 0, n)]) -= xi * zeta;
    M(i, coord2idx[make_mytuple(u + q, v, n)]) -= xi * zeta;
    M(i, coord2idx[make_mytuple(0, v + u, n)]) -= eta * zeta;
    M(i, coord2idx[make_mytuple(u, v + q, n)]) -= eta * zeta;
    M(i, coord2idx[make_mytuple(0, v, n)]) -= rho * zeta;
    M(i, coord2idx[make_mytuple(u, 0, n)]) -= rho * zeta;

    M(i, coord2idx[make_mytuple(n, 0, 0)]) += xi * (1 - zeta);
    M(i, coord2idx[make_mytuple(0, n, 0)]) += eta * (1 - zeta);
    M(i, coord2idx[make_mytuple(0, 0, 0)]) += rho * (1 - zeta);
    M(i, coord2idx[make_mytuple(n, 0, n)]) += xi * zeta;
    M(i, coord2idx[make_mytuple(0, n, n)]) += eta * zeta;
    M(i, coord2idx[make_mytuple(0, 0, n)]) += rho * zeta;
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementPyramid(int order)
{
  if(order < 3) return fullMatrix<double>();

  const int szInt = (order - 2) * ((order - 2) + 1) * (2 * (order - 2) + 1) / 6;
  const int szComp =
    (order + 1) * ((order + 1) + 1) * (2 * (order + 1) + 1) / 6;
  const int szInc = szComp - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsPyramid(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = order - coordinates(i, 2);
    coord2idx[make_mytuple(u, v, w)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = order - coordinates(szInc + i, 2);
    int q = n - u - w;
    int r = n - v - w;
    double xi = (double)u / n;
    double eta = (double)v / n;
    double rho = (double)q / n;
    double tau = (double)r / n;
    double xip = (double)u / (n - w);
    double etap = (double)v / (n - w);

    // lateral faces
    M(i, coord2idx[make_mytuple(0, v, w)]) += 1 - xip;
    M(i, coord2idx[make_mytuple(u, 0, w)]) += 1 - etap;
    M(i, coord2idx[make_mytuple(n - w, v, w)]) += xip;
    M(i, coord2idx[make_mytuple(u, n - w, w)]) += etap;
    // basis face
    M(i, coord2idx[make_mytuple(u, v, 0)]) += rho * tau;
    M(i, coord2idx[make_mytuple(u + w, v, 0)]) += xi * tau;
    M(i, coord2idx[make_mytuple(u + w, v + w, 0)]) += xi * eta;
    M(i, coord2idx[make_mytuple(u, v + w, 0)]) += rho * eta;
    // vertical edges
    M(i, coord2idx[make_mytuple(0, 0, w)]) -= (1 - xip) * (1 - etap);
    M(i, coord2idx[make_mytuple(n - w, 0, w)]) -= xip * (1 - etap);
    M(i, coord2idx[make_mytuple(n - w, n - w, w)]) -= xip * etap;
    M(i, coord2idx[make_mytuple(0, n - w, w)]) -= (1 - xip) * etap;
    // basis edges
    M(i, coord2idx[make_mytuple(0, v, 0)]) -= rho * tau;
    M(i, coord2idx[make_mytuple(u, 0, 0)]) -= rho * tau;
    M(i, coord2idx[make_mytuple(u + w, 0, 0)]) -= xi * tau;
    M(i, coord2idx[make_mytuple(n, v, 0)]) -= xi * tau;
    M(i, coord2idx[make_mytuple(n, v + w, 0)]) -= xi * eta;
    M(i, coord2idx[make_mytuple(u + w, n, 0)]) -= xi * eta;
    M(i, coord2idx[make_mytuple(u, n, 0)]) -= rho * eta;
    M(i, coord2idx[make_mytuple(0, v + w, 0)]) -= rho * eta;
    // basis corners
    M(i, coord2idx[make_mytuple(0, 0, 0)]) += rho * tau;
    M(i, coord2idx[make_mytuple(n, 0, 0)]) += xi * tau;
    M(i, coord2idx[make_mytuple(n, n, 0)]) += xi * eta;
    M(i, coord2idx[make_mytuple(0, n, 0)]) += rho * eta;
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementTriangleLinear(int order,
                                                                  int dir)
{
  if(order < 3) return fullMatrix<double>();

  const int szInc = 3 * order;
  const int szComp = (order + 1) * (order + 2) / 2;
  const int szInt = szComp - szInc;

  fullMatrix<double> monomials = gmshGenerateMonomialsTriangle(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<std::pair<int, int>, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    coord2idx[std::make_pair(u, v)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    double mu;

    switch(dir) {
    case 0:
      mu = (double)u / (n - v);
      M(i, coord2idx[std::make_pair(0, v)]) += 1 - mu;
      M(i, coord2idx[std::make_pair(n - v, v)]) += mu;
      break;
    case 1:
      mu = (double)v / (u + v);
      M(i, coord2idx[std::make_pair(u + v, 0)]) += 1 - mu;
      M(i, coord2idx[std::make_pair(0, u + v)]) += mu;
      break;
    default:
    case 2:
      mu = (double)v / (n - u);
      M(i, coord2idx[std::make_pair(u, 0)]) += 1 - mu;
      M(i, coord2idx[std::make_pair(u, n - u)]) += mu;
      break;
    }
  }

  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementQuadrangleLinear(int order)
{
  if(order < 2) return fullMatrix<double>();

  const int szInc = 4 * order;
  const int szComp = (order + 1) * (order + 1);
  const int szInt = szComp - szInc;

  fullMatrix<double> monomials = gmshGenerateMonomialsQuadrangle(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<std::pair<int, int>, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    coord2idx[std::make_pair(u, v)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    double eta = (double)v / n;

    M(i, coord2idx[std::make_pair(u, 0)]) += 1 - eta;
    M(i, coord2idx[std::make_pair(u, n)]) += eta;
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementTetrahedronLinear(int order,
                                                                     int dir)
{
  // 'dir' corresponds to the number of edge
  if(order < 4) return fullMatrix<double>();

  const int szInt = (order - 3) * (order - 2) * (order - 1) / 6;
  const int szComp = (order + 1) * (order + 2) * (order + 3) / 6;
  const int szInc = szComp - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsTetrahedron(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[make_mytuple(u, v, w)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    double mu;

    switch(dir) {
    case 0:
      mu = (double)u / (n - v - w);
      M(i, coord2idx[make_mytuple(0, v, w)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(n - v - w, v, w)]) += mu;
      break;
    case 2:
      mu = (double)v / (n - u - w);
      M(i, coord2idx[make_mytuple(u, 0, w)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(u, n - u - w, w)]) += mu;
      break;
    default:
    case 3:
      mu = (double)w / (n - u - v);
      M(i, coord2idx[make_mytuple(u, v, 0)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(u, v, n - u - v)]) += mu;
      break;
    case 1:
      mu = (double)v / (u + v);
      M(i, coord2idx[make_mytuple(u + v, 0, w)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(0, u + v, w)]) += mu;
      break;
    case 4:
      mu = (double)w / (v + w);
      M(i, coord2idx[make_mytuple(u, v + w, 0)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(u, 0, v + w)]) += mu;
      break;
    case 5:
      mu = (double)w / (u + w);
      M(i, coord2idx[make_mytuple(u + w, v, 0)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(0, v, u + w)]) += mu;
      break;
    }
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementHexahedronLinear(int order,
                                                                    int dir)
{
  if(order < 2) return fullMatrix<double>();

  const int szInt = (order - 1) * (order - 1) * (order - 1);
  const int szComp = (order + 1) * (order + 1) * (order + 1);
  const int szInc = szComp - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsHexahedron(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[make_mytuple(u, v, w)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    double eta;

    switch(dir) {
    case 0:
      eta = (double)u / n;
      M(i, coord2idx[make_mytuple(0, v, w)]) += 1 - eta;
      M(i, coord2idx[make_mytuple(n, v, w)]) += eta;
      break;
    case 1:
      eta = (double)v / n;
      M(i, coord2idx[make_mytuple(u, 0, w)]) += 1 - eta;
      M(i, coord2idx[make_mytuple(u, n, w)]) += eta;
      break;
    default:
    case 2:
      eta = (double)w / n;
      M(i, coord2idx[make_mytuple(u, v, 0)]) += 1 - eta;
      M(i, coord2idx[make_mytuple(u, v, n)]) += eta;
      break;
    }
  }
  return M;
}

fullMatrix<double> gmshGenerateInnerVertexPlacementPrismLinear(int order,
                                                               int dir)
{
  if(order < 3) return fullMatrix<double>();

  const int szInt = (order - 1) * (order - 2) * (order - 1) / 2;
  const int szComp = (order + 1) * (order + 1) * (order + 2) / 2;
  const int szInc = szComp - szInt;

  fullMatrix<double> monomials = gmshGenerateMonomialsPrism(order, false);
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[make_mytuple(u, v, w)] = i;
  }

  int &n = order;
  fullMatrix<double> M(szInt, szInc, true);
  for(int i = 0; i < szInt; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    double eta, mu;

    switch(dir) {
    case 0:
      mu = (double)u / (n - v);
      M(i, coord2idx[make_mytuple(0, v, w)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(n - v, v, w)]) += mu;
      break;
    case 1:
      mu = (double)v / (u + v);
      M(i, coord2idx[make_mytuple(u + v, 0, w)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(0, u + v, w)]) += mu;
      break;
    case 2:
      mu = (double)v / (n - u);
      M(i, coord2idx[make_mytuple(u, 0, w)]) += 1 - mu;
      M(i, coord2idx[make_mytuple(u, n - u, w)]) += mu;
      break;
    default:
    case 3:
      eta = (double)w / n;
      M(i, coord2idx[make_mytuple(u, v, 0)]) += 1 - eta;
      M(i, coord2idx[make_mytuple(u, v, n)]) += eta;
      break;
    }
  }
  return M;
}

#undef make_mytuple
