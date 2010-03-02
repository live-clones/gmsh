#ifndef _DG_RUNGE_KUTTA_H_
#define _DG_RUNGE_KUTTA_H_
#include <vector>
#include <map>
class dgConservationLaw;
class dgDofContainer;
class dgLimiter;
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
  public:
  void setLimiter(dgLimiter *limiter) { _limiter = limiter; }
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

class dgRungeKuttaMultirate: public dgRungeKutta{
  private:
  int _maxExponent;
  int _minExponent;
  double _dt;
  dgConservationLaw *_law;
  dgDofContainer *_solution;
  dgDofContainer **_K;
  dgDofContainer *_currentInput;
  dgDofContainer *_residual;
  dgResidualVolume *_residualVolume;
  dgResidualInterface *_residualInterface;
  dgResidualBoundary *_residualBoundary;
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_bulkGroupsOfElements;// int is the multirateExponent
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_innerBufferGroupsOfElements;// int is the multirateExponent
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_outerBufferGroupsOfElements;// int is the multirateExponent
  void computeInputForK(int iK,int exponent,bool isBuffer);
  void computeK(int iK,int exponent,bool isBuffer);
  void updateSolution(int exponent,bool isBuffer);
  void computeResidual(int exponent,bool isBuffer,dgDofContainer *solution, dgDofContainer *residual);
  public:
  dgRungeKuttaMultirate(dgGroupCollection *gc,dgConservationLaw* law);
  ~dgRungeKuttaMultirate();


  double iterate(double dt, dgDofContainer *solution);
  static void registerBindings(binding *b);
};
#endif
