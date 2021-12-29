#ifndef _ORTHOGONALPOLY_H_
#define _ORTHOGONALPOLY_H_

#include <math.h>
#include <string>
namespace OrthogonalPoly {

  // Lobatto Orthogonal Shape Functions in Horner's form
  double EvalLobatto(int order, double x);
  // derivative of lobatto orthogonal shape funcions in Horner's form
  double EvalDLobatto(int order, double x);
  // Kernel functions in Horner's form
  double EvalKernelFunction(int order, double x);
  // derivative of Kernel functions in Horner's form
  double EvalDKernelFunction(int order, double x);
  // Legendre Functions in Horner's form
  double EvalLegendre(int order, double x);
  // derivative of Legendre  Functions in Horner's form
  double EvalDLegendre(int order, double x);

}; // namespace OrthogonalPoly

#endif
