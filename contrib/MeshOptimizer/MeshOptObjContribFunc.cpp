// TODO: Copyright

#include <cmath>
#include "MeshOptObjContribFunc.h"


const double ObjContribFuncSimpleTargetMin::STAGTHRESHOLD = 0.01;


ObjContribFuncSimpleTargetMin::ObjContribFuncSimpleTargetMin() :
    _target(0.), _init(0.)
{
}


void ObjContribFuncSimpleTargetMin::setTarget(double target)
{
  _target = target;
}


void ObjContribFuncSimpleTargetMin::updateParameters(double vMin, double vMax)
{
  _init = vMin;
}


bool ObjContribFuncSimpleTargetMin::stagnated(double vMin, double vMax)
{
  return (fabs((vMin-_init)/_init) < STAGTHRESHOLD);
}


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


void ObjContribFuncBarrierMovMin::updateParameters(double vMin, double vMax)
{
  _init = vMin;
  _barrier = vMin > 0. ? LOWMARGINMULT*vMin : UPMARGINMULT*vMin;
}


bool ObjContribFuncBarrierMovMin::stagnated(double vMin, double vMax)
{
  return (fabs((vMin-_init)/_init) < STAGTHRESHOLD);
}


void ObjContribFuncBarrierMovMax::updateParameters(double vMin, double vMax)
{
  _init = vMax;
  _barrier = vMax > 0. ? UPMARGINMULT*vMax : LOWMARGINMULT*vMax;
}


bool ObjContribFuncBarrierMovMax::stagnated(double vMin, double vMax)
{
  return (fabs((vMax-_init)/_init) < STAGTHRESHOLD);
}


void ObjContribFuncBarrierFixMinMovMax::initialize(double vMin, double vMax)
{
  ObjContribFuncBarrierMovMax::initialize(vMin, vMax);
  _fixedMinBarrier = vMin > 0. ? LOWMARGINMULT*vMin : UPMARGINMULT*vMin;
}
