#ifndef _DG_RUNGE_KUTTA_H_
#define _DG_RUNGE_KUTTA_H_
#include <vector>
#include <map>
class dgConservationLaw;
class dgDofContainer;
class dgLimiter;
class dgTransformNodalValue;
class dgGroupCollection;
class dgGroupOfElements;
class dgGroupOfFaces;
class dgResidualVolume;
class dgResidualInterface;
class dgResidualBoundary;
class binding;
#include "fullMatrix.h"
class dgRungeKutta {
  double diagonalRK(const dgConservationLaw *claw, double dt, dgDofContainer *solution, int nStages, double *A, double *b); // c == A
  double nonDiagonalRK(const dgConservationLaw *claw, double dt, dgDofContainer *solution, int nStages, fullMatrix<double>&A, double *b, double *c);
  dgLimiter *_limiter;
  dgTransformNodalValue *_TransformNodalValue;
  public:
  void setLimiter(dgLimiter *limiter) { _limiter = limiter; }
  void setTransformNodalValue(dgTransformNodalValue *TransformNodalValue) { _TransformNodalValue = TransformNodalValue; }

  double iterateEuler(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate22(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate33(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate44(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate44ThreeEight(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate43SchlegelJCAM2009(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterateRKFehlberg45(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  static void registerBindings (binding *b);
  dgRungeKutta();
};

#endif
