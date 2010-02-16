#ifndef _DG_RUNGE_KUTTA_H_
#define _DG_RUNGE_KUTTA_H_
class dgConservationLaw;
class dgDofContainer;
class dgLimiter;
class binding;
class dgRungeKutta {
  double diagonalRK(const dgConservationLaw *claw, double dt, dgDofContainer *solution, int nStages, double *A, double *b); // c == A
  //static double nonDiagonalRK();
  dgLimiter *_limiter;
  public:
  void setLimiter(dgLimiter *limiter) { _limiter = limiter; }
  double iterateEuler(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate22(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  double iterate44(const dgConservationLaw *claw, double dt, dgDofContainer *solution);
  static void registerBindings (binding *b);
  dgRungeKutta();
};
#endif
