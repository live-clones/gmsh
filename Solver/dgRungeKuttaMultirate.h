#include "dgRungeKutta.h"

class dgRungeKuttaMultirate: public dgRungeKutta{
  protected:
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
  dgGroupCollection *_gc;
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_bulkGroupsOfElements;// int is the multirateExponent
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_innerBufferGroupsOfElements;// int is the multirateExponent
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_outerBufferGroupsOfElements;// int is the multirateExponent
  virtual void computeInputForK(int iK,int exponent,bool isBuffer)=0;
  void computeK(int iK,int exponent,bool isBuffer);
  virtual void updateSolution(int exponent,bool isBuffer)=0;
  void computeResidual(int exponent,bool isBuffer,dgDofContainer *solution, dgDofContainer *residual);
  public:
  dgRungeKuttaMultirate(dgGroupCollection *gc,dgConservationLaw* law, int nStages);
  virtual ~dgRungeKuttaMultirate();


  virtual double iterate(double dt, dgDofContainer *solution)=0;
  static void registerBindings(binding *b);
};

class dgRungeKuttaMultirate43: public dgRungeKuttaMultirate{
  void computeInputForK(int iK,int exponent,bool isBuffer);
  void updateSolution(int exponent,bool isBuffer);
  public:
  double iterate(double dt, dgDofContainer *solution);
  dgRungeKuttaMultirate43(dgGroupCollection *gc,dgConservationLaw *law);
  static void registerBindings(binding *b);
};

class dgRungeKuttaMultirate22: public dgRungeKuttaMultirate{
  void computeInputForK(int iK,int exponent,bool isBuffer);
  void updateSolution(int exponent,bool isBuffer);
  public:
  double iterate(double dt, dgDofContainer *solution);
  dgRungeKuttaMultirate22(dgGroupCollection *gc,dgConservationLaw *law);
  static void registerBindings(binding *b);
};
