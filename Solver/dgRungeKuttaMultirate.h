#include "dgRungeKutta.h"

class dgRungeKuttaMultirate: public dgRungeKutta{
  protected:
  bool _init;   
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
  dgGroupCollection *_gc;
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_bulkGroupsOfElements;// int is the multirateExponent
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_innerBufferGroupsOfElements;// int is the multirateExponent
  std::vector<std::pair<std::vector<dgGroupOfElements*>,std::vector<dgGroupOfFaces*> > >_outerBufferGroupsOfElements;// int is the multirateExponent
  void initialize(int nStages);
  void computeK(int iK,int exponent,bool isBuffer);
  virtual void updateSolution(int exponent,bool isBuffer)=0;
  void computeResidual(int exponent,bool isBuffer,dgDofContainer *solution, dgDofContainer *residual);
  public:
  dgRungeKuttaMultirate(dgGroupCollection *gc,dgConservationLaw* law);
  virtual ~dgRungeKuttaMultirate();
  virtual double iterate(double dt, dgDofContainer *solution)=0;
  virtual double splitForMultirate(int maxLevels, dgDofContainer *solution)=0;
  static void registerBindings(binding *b);
};

class dgRungeKuttaMultirate43: public dgRungeKuttaMultirate{
  void computeInputForK(int iK,int exponent,bool isBuffer);
  void updateSolution(int exponent,bool isBuffer);
  public:
  double splitForMultirate(int maxLevels, dgDofContainer *solution);
  double iterate(double dt, dgDofContainer *solution);
  dgRungeKuttaMultirate43(dgGroupCollection *gc,dgConservationLaw *law);
  static void registerBindings(binding *b);
};

class dgRungeKuttaMultirate22: public dgRungeKuttaMultirate{
  void computeInputForK(int iK,int exponent,bool isBuffer,int upperLeveliK);
  void updateSolution(int exponent,bool isBuffer);
  public:
  double splitForMultirate(int maxLevels, dgDofContainer *solution);
  double iterate(double dt, dgDofContainer *solution);
  dgRungeKuttaMultirate22(dgGroupCollection *gc,dgConservationLaw *law);
  static void registerBindings(binding *b);
};
class dgRungeKuttaMultirateConservative: public dgRungeKuttaMultirate{
  private:
  fullMatrix<double> *_A;
  fullMatrix<double> *_b;
  fullMatrix<double> *_c;
  fullMatrix<double> *_AOuter;
  fullMatrix<double> *_bOuter;
  fullMatrix<double> *_cOuter;
  fullMatrix<double> *_AInner;
  fullMatrix<double> *_bInner;
  fullMatrix<double> *_cInner;

  void computeInputForK(int iK,int exponent,bool isBuffer,int upperLeveliK);
  void updateSolution(int exponent,bool isBuffer);
  public:
  double splitForMultirate(int maxLevels, dgDofContainer *solution);
  double iterate(double dt, dgDofContainer *solution);
  dgRungeKuttaMultirateConservative(dgGroupCollection *gc,dgConservationLaw *law, fullMatrix<double> *A, fullMatrix<double> *b,fullMatrix<double> *c);
  void printButcher();
  static dgRungeKuttaMultirateConservative* new44(dgGroupCollection *gc, dgConservationLaw *law);
  static dgRungeKuttaMultirateConservative* new43(dgGroupCollection *gc, dgConservationLaw *law);
  static dgRungeKuttaMultirateConservative* new2a(dgGroupCollection *gc, dgConservationLaw *law);
  static dgRungeKuttaMultirateConservative* new2b(dgGroupCollection *gc, dgConservationLaw *law);
  static void registerBindings(binding *b);
};
