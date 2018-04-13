//
// Created by Amaury Johnen on 12/04/18.
//

#ifndef GMSH_ORTHOGONALBASIS_H
#define GMSH_ORTHOGONALBASIS_H

// Orthogonal bases:
// - Line: Legendre
// - Quadrangle: Legendre x Legendre
// - Triangle: Legendre x Jacobi

class orthogonalBasis {

};

namespace LegendrePolynomials {
  void f(int n, double u, double *val);
  void fc(int n, double u, double *val);
  void df(int n, double u, double *val);
}

namespace JacobiPolynomials {
  void f(int n, double alpha, double beta, double u, double *val);
  void df(int n, double alpha, double beta, double u, double *val);

  inline double Pochhammer(double x,int n)
  {
    double result = 1;
    for (int i = 0; i < n; i++) result *= x + i;
    return result;
  }
}


#endif //GMSH_ORTHOGONALBASIS_H
