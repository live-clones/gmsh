//
// Created by Amaury Johnen on 13/02/18.
//

#include "InteriorNodePlacement.h"
#include "pointsGenerators.h"

typedef std::pair<std::pair<int, int>, int> mytuple;
#define MAKE_TUPLE(a,b,c) std::make_pair(std::make_pair(a,b),c)

namespace {
  void double2int(const fullMatrix<double> &doubleMat,
                  fullMatrix<int> &intMat) {
    intMat.resize(doubleMat.size1(), doubleMat.size2(), false);
    for (int i = 0; i < intMat.size1(); ++i) {
      for (int j = 0; j < intMat.size2(); ++j) {
        intMat(i, j) = static_cast<int>(doubleMat(i, j) + .5);
      }
    }
  }
}

fullMatrix<double> gmshGenerateInteriorNodePlacementTriangle(int order)
{
  fullMatrix<double> M;

  if (order < 3) {
    M.resize(0, 0);
    return M;
  }

  int szInc = 3 * order;
  int szComp = (order + 1) * (order + 2) / 2;
  M.resize(szComp-szInc, szInc, true);

  fullMatrix<double> monomials = gmshGenerateMonomialsTriangle(order, false);
  monomials.print("monomials");
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<std::pair<int, int>, int> coord2idx;
  for (int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    coord2idx[std::make_pair(u, v)] = i;
  }

  int &n = order;
  for (int i = 0; i < szComp-szInc; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int q = n-u-v;
    double xi = (double)u / n;
    double eta = (double)v / n;
    double rho = (double)q / n;

    M(i, coord2idx[std::make_pair(u+v,   0)]) += xi;
    M(i, coord2idx[std::make_pair(u+q,   v)]) += xi;
    M(i, coord2idx[std::make_pair(  0, v+u)]) += eta;
    M(i, coord2idx[std::make_pair(  u, v+q)]) += eta;
    M(i, coord2idx[std::make_pair(  0,   v)]) += rho;
    M(i, coord2idx[std::make_pair(  u,   0)]) += rho;
    M(i, coord2idx[std::make_pair(  n,   0)]) -= xi;
    M(i, coord2idx[std::make_pair(  0,   n)]) -= eta;
    M(i, coord2idx[std::make_pair(  0,   0)]) -= rho;
  }

  M.print("Mtri");
  for (int i = 0; i < M.size1(); ++i) {
    double sum = 0;
    for (int j = 0; j < M.size2(); ++j) {
      sum += M(i, j);
    }
    if (abs(sum-1) > 1e-12)
      printf("AAARARARARARARRG");
  }
  return M;
}

fullMatrix<double> gmshGenerateInteriorNodePlacementQuadrangle(int order)
{
  fullMatrix<double> M;

  if (order < 2) {
    M.resize(0, 0);
    return M;
  }

  int szInc = 4 * order;
  int szComp = (order + 1) * (order + 1);
  M.resize(szComp-szInc, szInc, true);

  fullMatrix<double> monomials = gmshGenerateMonomialsQuadrangle(order, false);
  monomials.print("monomials");
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<std::pair<int, int>, int> coord2idx;
  for (int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    coord2idx[std::make_pair(u, v)] = i;
  }

  int &n = order;
  for (int i = 0; i < szComp-szInc; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    double xi = (double)u / n;
    double eta = (double)v / n;

    M(i, coord2idx[std::make_pair(0, v)]) += 1-xi;
    M(i, coord2idx[std::make_pair(n, v)]) += xi;
    M(i, coord2idx[std::make_pair(u, 0)]) += 1-eta;
    M(i, coord2idx[std::make_pair(u, n)]) += eta;
    M(i, coord2idx[std::make_pair(0, 0)]) -= (1-xi)*(1-eta);
    M(i, coord2idx[std::make_pair(n, 0)]) -= xi*(1-eta);
    M(i, coord2idx[std::make_pair(n, n)]) -= xi*eta;
    M(i, coord2idx[std::make_pair(0, n)]) -= (1-xi)*eta;
  }

  M.print("Mquad");
  for (int i = 0; i < M.size1(); ++i) {
    double sum = 0;
    for (int j = 0; j < M.size2(); ++j) {
      sum += M(i, j);
    }
    if (abs(sum-1) > 1e-12)
      printf("AAARARARARARARRG");
  }
  return M;
}

fullMatrix<double> gmshGenerateInteriorNodePlacementTetrahedron(int order)
{
  fullMatrix<double> M;

  if (order < 4) {
    M.resize(0, 0);
    return M;
  }

  int szInc = 4 + 6 * (order - 1) + 4 * (order - 2) * (order - 1) / 2;
  int szComp = (order + 1) * (order + 2) * (order + 3) / 6;
  M.resize(szComp-szInc, szInc, true);

  fullMatrix<double> monomials = gmshGenerateMonomialsTetrahedron(order, false);
  monomials.print("monomials");
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for (int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[MAKE_TUPLE(u, v, w)] = i;
  }

  int &n = order;
  for (int i = 0; i < szComp-szInc; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    int q = n-u-v-w;
    double xi = (double)u / n;
    double eta = (double)v / n;
    double zeta = (double)w / n;
    double rho = (double)q / n;

    M(i, coord2idx[MAKE_TUPLE(u+v, 0, w)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(u+w, v, 0)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(u+q, v, w)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(0, v+u, w)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(u, v+w, 0)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(u, v+q, w)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(0, v, w+u)]) += zeta;
    M(i, coord2idx[MAKE_TUPLE(u, 0, w+v)]) += zeta;
    M(i, coord2idx[MAKE_TUPLE(u, v, w+q)]) += zeta;
    M(i, coord2idx[MAKE_TUPLE(0, v, w)]) += rho;
    M(i, coord2idx[MAKE_TUPLE(u, 0, w)]) += rho;
    M(i, coord2idx[MAKE_TUPLE(u, v, 0)]) += rho;

    M(i, coord2idx[MAKE_TUPLE(n-q, 0, 0)]) -= xi;
    M(i, coord2idx[MAKE_TUPLE(n-w, 0, w)]) -= xi;
    M(i, coord2idx[MAKE_TUPLE(n-v, v, 0)]) -= xi;
    M(i, coord2idx[MAKE_TUPLE(0, n-q, 0)]) -= eta;
    M(i, coord2idx[MAKE_TUPLE(0, n-w, w)]) -= eta;
    M(i, coord2idx[MAKE_TUPLE(u, n-u, 0)]) -= eta;
    M(i, coord2idx[MAKE_TUPLE(0, 0, n-q)]) -= zeta;
    M(i, coord2idx[MAKE_TUPLE(0, v, n-v)]) -= zeta;
    M(i, coord2idx[MAKE_TUPLE(u, 0, n-u)]) -= zeta;
    M(i, coord2idx[MAKE_TUPLE(0, 0, w)]) -= rho;
    M(i, coord2idx[MAKE_TUPLE(0, v, 0)]) -= rho;
    M(i, coord2idx[MAKE_TUPLE(u, 0, 0)]) -= rho;

    M(i, coord2idx[MAKE_TUPLE(n, 0, 0)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(0, n, 0)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(0, 0, n)]) += zeta;
    M(i, coord2idx[MAKE_TUPLE(0, 0, 0)]) += rho;
  }

  M.print("Mtet");
  for (int i = 0; i < M.size1(); ++i) {
    double sum = 0;
    for (int j = 0; j < M.size2(); ++j) {
      sum += M(i, j);
    }
    if (abs(sum-1) > 1e-12)
      printf("AAARARARARARARRG");
  }
  return M;
}

fullMatrix<double> gmshGenerateInteriorNodePlacementHexahedron(int order)
{
  fullMatrix<double> M;

  if (order < 2) {
    M.resize(0, 0);
    return M;
  }

  int szInc = 8 + 12 * (order - 1) + 6 * (order - 1) * (order - 1);
  int szComp = (order + 1) * (order + 1) * (order + 1);
  M.resize(szComp-szInc, szInc, true);

  fullMatrix<double> monomials = gmshGenerateMonomialsHexahedron(order, false);
  monomials.print("monomials");
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for (int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[MAKE_TUPLE(u, v, w)] = i;
  }

  int &n = order;
  for (int i = 0; i < szComp-szInc; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    double xi = (double)u / n;
    double eta = (double)v / n;
    double zeta = (double)w / n;

    M(i, coord2idx[MAKE_TUPLE(0, v, w)]) += 1-xi;
    M(i, coord2idx[MAKE_TUPLE(n, v, w)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(u, 0, w)]) += 1-eta;
    M(i, coord2idx[MAKE_TUPLE(u, n, w)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(u, v, 0)]) += 1-zeta;
    M(i, coord2idx[MAKE_TUPLE(u, v, n)]) += zeta;

    M(i, coord2idx[MAKE_TUPLE(0, 0, w)]) -= (1-xi) * (1-eta);
    M(i, coord2idx[MAKE_TUPLE(0, n, w)]) -= (1-xi) * eta;
    M(i, coord2idx[MAKE_TUPLE(n, 0, w)]) -= xi * (1-eta);
    M(i, coord2idx[MAKE_TUPLE(n, n, w)]) -= xi * eta;
    M(i, coord2idx[MAKE_TUPLE(u, 0, 0)]) -= (1-eta) * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(u, 0, n)]) -= (1-eta) * zeta;
    M(i, coord2idx[MAKE_TUPLE(u, n, 0)]) -= eta * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(u, n, n)]) -= eta * zeta;
    M(i, coord2idx[MAKE_TUPLE(0, v, 0)]) -= (1-zeta) * (1-xi);
    M(i, coord2idx[MAKE_TUPLE(n, v, 0)]) -= (1-zeta) * xi;
    M(i, coord2idx[MAKE_TUPLE(0, v, n)]) -= zeta * (1-xi);
    M(i, coord2idx[MAKE_TUPLE(n, v, n)]) -= zeta * xi;

    M(i, coord2idx[MAKE_TUPLE(0, 0, 0)]) += (1-xi) * (1-eta) * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(0, 0, n)]) += (1-xi) * (1-eta) * zeta;
    M(i, coord2idx[MAKE_TUPLE(0, n, 0)]) += (1-xi) * eta * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(0, n, n)]) += (1-xi) * eta * zeta;
    M(i, coord2idx[MAKE_TUPLE(n, 0, 0)]) += xi * (1-eta) * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(n, 0, n)]) += xi * (1-eta) * zeta;
    M(i, coord2idx[MAKE_TUPLE(n, n, 0)]) += xi * eta * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(n, n, n)]) += xi * eta * zeta;
  }

  M.print("Mhex");
  for (int i = 0; i < M.size1(); ++i) {
    double sum = 0;
    for (int j = 0; j < M.size2(); ++j) {
      sum += M(i, j);
    }
    if (abs(sum-1) > 1e-12)
      printf("AAARARARARARARRG");
  }
  return M;
}

fullMatrix<double> gmshGenerateInteriorNodePlacementPrism(int order)
{
  fullMatrix<double> M;

  if (order < 3) {
    M.resize(0, 0);
    return M;
  }

  int szInc = 6 + 9 * (order - 1) + 3 * (order - 1) * (order - 1)
              + 2 * (order - 2) * (order - 1) / 2;
  int szComp = (order + 1) * (order + 1) * (order + 2) / 2;
  M.resize(szComp-szInc, szInc, true);

  fullMatrix<double> monomials = gmshGenerateMonomialsPrism(order, false);
  monomials.print("monomials");
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for (int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[MAKE_TUPLE(u, v, w)] = i;
  }

  int &n = order;
  for (int i = 0; i < szComp-szInc; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    int q = n-u-v;
    double xi = (double)u / n;
    double eta = (double)v / n;
    double zeta = (double)w / n;
    double rho = (double)q / n;

    M(i, coord2idx[MAKE_TUPLE(u+v, 0, w)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(u+q, v, w)]) += xi;
    M(i, coord2idx[MAKE_TUPLE(0, v+u, w)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(u, v+q, w)]) += eta;
    M(i, coord2idx[MAKE_TUPLE(0, v, w)]) += rho;
    M(i, coord2idx[MAKE_TUPLE(u, 0, w)]) += rho;
    M(i, coord2idx[MAKE_TUPLE(u, v, 0)]) += 1-zeta;
    M(i, coord2idx[MAKE_TUPLE(u, v, n)]) += zeta;

    M(i, coord2idx[MAKE_TUPLE(n, 0, w)]) -= xi;
    M(i, coord2idx[MAKE_TUPLE(0, n, w)]) -= eta;
    M(i, coord2idx[MAKE_TUPLE(0, 0, w)]) -= rho;
    M(i, coord2idx[MAKE_TUPLE(u+v, 0, 0)]) -= xi * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(u+q, v, 0)]) -= xi * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(0, v+u, 0)]) -= eta * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(u, v+q, 0)]) -= eta * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(0, v, 0)]) -= rho * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(u, 0, 0)]) -= rho * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(u+v, 0, n)]) -= xi * zeta;
    M(i, coord2idx[MAKE_TUPLE(u+q, v, n)]) -= xi * zeta;
    M(i, coord2idx[MAKE_TUPLE(0, v+u, n)]) -= eta * zeta;
    M(i, coord2idx[MAKE_TUPLE(u, v+q, n)]) -= eta * zeta;
    M(i, coord2idx[MAKE_TUPLE(0, v, n)]) -= rho * zeta;
    M(i, coord2idx[MAKE_TUPLE(u, 0, n)]) -= rho * zeta;

    M(i, coord2idx[MAKE_TUPLE(n, 0, 0)]) += xi * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(0, n, 0)]) += eta * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(0, 0, 0)]) += rho * (1-zeta);
    M(i, coord2idx[MAKE_TUPLE(n, 0, n)]) += xi * zeta;
    M(i, coord2idx[MAKE_TUPLE(0, n, n)]) += eta * zeta;
    M(i, coord2idx[MAKE_TUPLE(0, 0, n)]) += rho * zeta;
  }

  M.print("Mprism");
  for (int i = 0; i < M.size1(); ++i) {
    double sum = 0;
    for (int j = 0; j < M.size2(); ++j) {
      sum += M(i, j);
    }
    if (abs(sum-1) > 1e-12)
      printf("AAARARARARARARRG");
  }
  return M;
}

fullMatrix<double> gmshGenerateInteriorNodePlacementPyramid(int order)
{
  fullMatrix<double> M;

  if (order < 3) {
    M.resize(0, 0);
    return M;
  }

  int szInc = 5 + 8 * (order - 1) + 1 * (order - 1) * (order - 1)
              + 4 * (order - 2) * (order - 1) / 2;
  int szComp = (order+1) * ((order+1)+1) * (2*(order+1)+1) / 6;
  M.resize(szComp-szInc, szInc, true);

  fullMatrix<double> monomials = gmshGenerateMonomialsPyramid(order, false);
  monomials.print("monomials");
  fullMatrix<int> coordinates;
  double2int(monomials, coordinates);

  std::map<mytuple, int> coord2idx;
  for (int i = 0; i < szInc; ++i) {
    int u = coordinates(i, 0);
    int v = coordinates(i, 1);
    int w = coordinates(i, 2);
    coord2idx[MAKE_TUPLE(u, v, w)] = i;
  }

  int &n = order;
  for (int i = 0; i < szComp-szInc; ++i) {
    int u = coordinates(szInc + i, 0);
    int v = coordinates(szInc + i, 1);
    int w = coordinates(szInc + i, 2);
    int q = n-u-w;
    int r = n-v-w;
    double xi = (double)u / n;
    double eta = (double)v / n;
    double zeta = (double)w / n;
    double rho = (double)q / n;
    double tau = (double)r / n;
    double xip = (double)u / (n-w);
    double etap = (double)v / (n-w);

    // lateral faces
    M(i, coord2idx[MAKE_TUPLE(0, v, w)]) += 1-xip;
    M(i, coord2idx[MAKE_TUPLE(u, 0, w)]) += 1-etap;
    M(i, coord2idx[MAKE_TUPLE(n-w, v, w)]) += xip;
    M(i, coord2idx[MAKE_TUPLE(u, n-w, w)]) += etap;
    // basis face
    M(i, coord2idx[MAKE_TUPLE(u, v, 0)]) += rho * tau;
    M(i, coord2idx[MAKE_TUPLE(u+w, v, 0)]) += xi * tau;
    M(i, coord2idx[MAKE_TUPLE(u+w, v+w, 0)]) += xi * eta;
    M(i, coord2idx[MAKE_TUPLE(u, v+w, 0)]) += rho * eta;
    // vertical edges
    M(i, coord2idx[MAKE_TUPLE(0, 0, w)]) -= (1-xip) * (1-etap);
    M(i, coord2idx[MAKE_TUPLE(n-w, 0, w)]) -= xip * (1-etap);
    M(i, coord2idx[MAKE_TUPLE(n-w, n-w, w)]) -= xip * etap;
    M(i, coord2idx[MAKE_TUPLE(0, n-w, w)]) -= (1-xip) * etap;
    // basis edges
    M(i, coord2idx[MAKE_TUPLE(0, v, 0)]) -= rho * tau;
    M(i, coord2idx[MAKE_TUPLE(u, 0, 0)]) -= rho * tau;
    M(i, coord2idx[MAKE_TUPLE(u+w, 0, 0)]) -= xi * tau;
    M(i, coord2idx[MAKE_TUPLE(n, v, 0)]) -= xi * tau;
    M(i, coord2idx[MAKE_TUPLE(n, v+w, 0)]) -= xi * eta;
    M(i, coord2idx[MAKE_TUPLE(u+w, n, 0)]) -= xi * eta;
    M(i, coord2idx[MAKE_TUPLE(u, n, 0)]) -= rho * eta;
    M(i, coord2idx[MAKE_TUPLE(0, v+w, 0)]) -= rho * eta;
    // basis corners
    M(i, coord2idx[MAKE_TUPLE(0, 0, 0)]) += rho * tau;
    M(i, coord2idx[MAKE_TUPLE(n, 0, 0)]) += xi * tau;
    M(i, coord2idx[MAKE_TUPLE(n, n, 0)]) += xi * eta;
    M(i, coord2idx[MAKE_TUPLE(0, n, 0)]) += rho * eta;
  }

  M.print("Mpyr");
  for (int i = 0; i < M.size1(); ++i) {
    double sum = 0;
    for (int j = 0; j < M.size2(); ++j) {
      sum += M(i, j);
    }
    if (abs(sum-1) > 1e-12)
      printf("AAARARARARARARRG");
  }
  return M;
}

#undef MAKE_TUPLE