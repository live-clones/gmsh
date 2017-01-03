// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PVIEW_AS_SIMPLEFUNCTION_H
#define _PVIEW_AS_SIMPLEFUNCTION_H

#include "simpleFunction.h"

class PView;

class PViewEvaluator : public simpleFunction<double> {
  PView *_pv;
  int _step;
 public:
  PViewEvaluator (PView *pv) : _pv(pv), _step(0) {}
  double operator() (double x, double y, double z) const;
  void setStep (int s) { _step = s; }
};

#endif
