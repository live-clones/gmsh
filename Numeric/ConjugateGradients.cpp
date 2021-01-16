// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <math.h>
#include "GmshMessage.h"
#include "ConjugateGradients.h"
/*
  min_a f(x+a*d);
  f(x+a*d) = f(x) + f'(x) (
*/

static double _norm(std::vector<double> &x)
{
  double n = 0.0;
  for(std::size_t i = 0; i < x.size(); i++) n += x[i] * x[i];
  return sqrt(n);
}
static void scale(std::vector<double> &x, double s)
{
  for(std::size_t i = 0; i < x.size(); i++) x[i] *= s;
}

static void gmshLineSearch(void (*func)(std::vector<double> &x, double &Obj,
                                        bool needGrad,
                                        std::vector<double> &gradObj,
                                        void *), // the function
                           void *data, // eventual data
                           std::vector<double> &x, // variables
                           std::vector<double> &p, // search direction
                           std::vector<double> &g, // gradient
                           double &f, double stpmax, int &check)
{
  int i;
  double alam, alam2 = 1., alamin, f2 = 0., fold2 = 0., rhs1, rhs2, temp,
               tmplam = 0.;

  const double ALF = 1.e-4;
  const double TOLX = 1.0e-9;

  std::vector<double> xold(x), grad(x);
  double fold;
  (*func)(xold, fold, false, grad, data);

  check = 0;
  int n = x.size();
  double norm = _norm(p);
  if(norm > stpmax) scale(p, stpmax / norm);
  double slope = 0.0;
  for(i = 0; i < n; i++) slope += g[i] * p[i];
  double test = 0.0;
  for(i = 0; i < n; i++) {
    temp = fabs(p[i]) / std::max(fabs(xold[i]), 1.0);
    if(temp > test) test = temp;
  }

  alamin = TOLX / test;
  alam = 1.;

  while(1) {
    for(i = 0; i < n; i++) x[i] = xold[i] + alam * p[i];
    (*func)(x, f, false, grad, data);
    if(f > 1.e280)
      alam *= .5;
    else
      break;
  }

  while(1) {
    for(i = 0; i < n; i++) x[i] = xold[i] + alam * p[i];
    (*func)(x, f, false, grad, data);

    //    printf("alam = %12.5E alamin = %12.5E f = %12.5E fold = %12.5E slope
    //    %12.5E stuff %12.5E\n",alam,alamin,f,fold, slope,  ALF * alam *
    //    slope);

    //    f = (*func)(x, data);
    if(alam < alamin) {
      for(i = 0; i < n; i++) x[i] = xold[i];
      check = 1;
      return;
    }
    else if(f <= fold + ALF * alam * slope)
      return;
    else {
      if(alam == 1.0)
        tmplam = -slope / (2.0 * (f - fold - slope));
      else {
        rhs1 = f - fold - alam * slope;
        rhs2 = f2 - fold2 - alam2 * slope;
        const double a =
          (rhs1 / (alam * alam) - rhs2 / (alam2 * alam2)) / (alam - alam2);
        const double b =
          (-alam2 * rhs1 / (alam * alam) + alam * rhs2 / (alam2 * alam2)) /
          (alam - alam2);
        if(a == 0.0)
          tmplam = -slope / (2.0 * b);
        else {
          const double disc = b * b - 3.0 * a * slope;
          if(disc < 0.0)
            Msg::Error("Roundoff problem in gmshLineSearch.");
          else
            tmplam = (-b + sqrt(disc)) / (3.0 * a);
        }
        if(tmplam > 0.5 * alam) tmplam = 0.5 * alam;
      }
    }
    alam2 = alam;
    f2 = f;
    fold2 = fold;
    alam = std::max(tmplam, 0.1 * alam);
  }
}

// Simple Gradient Descent Minimization (use finite differences to compute the
// gradient)

double GradientDescent(void (*func)(std::vector<double> &x, double &Obj,
                                    bool needGrad, std::vector<double> &gradObj,
                                    void *), // its gradient
                       std::vector<double> &x, // The variables
                       void *data) // User data
{
  const int MAXIT = 3;
  const int N = x.size();

  std::vector<double> grad(N);
  std::vector<double> dir(N);
  double f;

  //  printf("entering gradient descent (%d unknowns)...\n",N);

  for(int iter = 0; iter < MAXIT; iter++) {
    // compute gradient of func
    double stpmax = 100000;
    func(x, f, true, grad, data);
    //    printf("computing f ... %22.15E\n",f);
    for(int i = 0; i < N; i++) dir[i] = -grad[i];
    int check;
    gmshLineSearch(func, data, x, dir, grad, f, stpmax, check);
    //    printf("line search is done, f reduces to %22.15E\n",f);
    // printf("Line search done x = (%g %g) f = %g\n",x(0),x(1),f);
    if(check == 1) break;
  }
  return f;
}
