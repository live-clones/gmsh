#include <string>
class dgDofContainer;
class binding;
class dgFunctionIntegrator{
  std::string _fName;
  public:
  dgFunctionIntegrator(std::string fName);
  void compute(dgDofContainer *sol,fullMatrix<double> &result);
  static void registerBindings(binding *b);
};
