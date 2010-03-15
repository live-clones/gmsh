#include <string>
class dgDofContainer;
class binding;
class function;
class dgFunctionIntegrator{
  const function *_f;
  public:
  dgFunctionIntegrator(const function *f);
  void compute(dgDofContainer *sol,fullMatrix<double> &result);
  static void registerBindings(binding *b);
};
