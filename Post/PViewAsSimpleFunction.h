#ifndef _PVIEW_AS_SIMPLEFUNCTION_H
#define _PVIEW_AS_SIMPLEFUNCTION_H
#include "simpleFunction.h"
class PView;
class PViewEvaluator : public simpleFunction<double> {
  PView *_pv;
  int _step;
public:
  PViewEvaluator (PView *pv) : _pv(pv),_step(0) {}
  double operator() (const double x, const double y, const double z) const;
  void setStep (int s) {_step=s;}
};

#endif
