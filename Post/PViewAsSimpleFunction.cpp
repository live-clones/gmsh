#include "PView.h"
#include "PViewData.h"
#include "PViewAsSimpleFunction.h"
double PViewEvaluator::operator() (const double x, const double y, const double z) const{
  PViewData * pvd = _pv->getData();
  double value;
  bool found = pvd->searchScalar(x,y,z,&value,_step);
  if (found) return value;
  return 1.e22;
}
