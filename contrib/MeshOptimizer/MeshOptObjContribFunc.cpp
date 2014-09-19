// TODO: Copyright

#include <cmath>
#include "MeshOptObjContribFunc.h"


const double ObjContribFuncBarrier::LOWMARGINMULT = 0.9;
const double ObjContribFuncBarrier::UPMARGINMULT = 1.1;
const double ObjContribFuncBarrier::STAGTHRESHOLD = 0.01;


ObjContribFuncBarrier::ObjContribFuncBarrier() :
    _target(0.), _barrier(0.), _init(0.), _opt(0.)
{
}


void ObjContribFuncBarrier::setTarget(double target, double opt)
{
  _target = target;
  _opt = opt;
}


void ObjContribFuncBarrierMin::updateParameters(double vMin, double vMax)
{
  _init = vMin;
  _barrier = vMin > 0. ? LOWMARGINMULT*vMin : UPMARGINMULT*vMin;
}


bool ObjContribFuncBarrierMin::stagnated(double vMin, double vMax)
{
  return (fabs((vMin-_init)/_init) < STAGTHRESHOLD);
}


void ObjContribFuncBarrierMax::updateParameters(double vMin, double vMax)
{
  _init = vMax;
  _barrier = vMax > 0. ? UPMARGINMULT*vMax : LOWMARGINMULT*vMax;
}


bool ObjContribFuncBarrierMax::stagnated(double vMin, double vMax)
{
  return (fabs((vMax-_init)/_init) < STAGTHRESHOLD);
}


void ObjContribFuncBarrierMinMax::initialize(double vMin, double vMax)
{
  ObjContribFuncBarrierMax::initialize(vMin, vMax);
  _fixedMinBarrier = vMin > 0. ? LOWMARGINMULT*vMin : UPMARGINMULT*vMin;
}
