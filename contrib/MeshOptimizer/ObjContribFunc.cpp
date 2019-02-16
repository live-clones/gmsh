// MeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#include <cmath>
#include "GmshMessage.h"
#include "ObjContribFunc.h"

const double ObjContribFuncSimpleTargetMax::STAGTHRESHOLD = 0.01;

ObjContribFuncSimpleTargetMax::ObjContribFuncSimpleTargetMax()
  : _target(0.), _init(0.)
{
}

void ObjContribFuncSimpleTargetMax::setTarget(double target)
{
  _target = target;
}

void ObjContribFuncSimpleTargetMax::updateParameters(double vMin, double vMax)
{
  _init = vMax;
}

bool ObjContribFuncSimpleTargetMax::stagnated(double vMin, double vMax)
{
  return (fabs((vMax - _init) / _init) < STAGTHRESHOLD);
}

const double ObjContribFuncBarrier::MARGINCOEFF = 0.1;
const double ObjContribFuncBarrier::STAGTHRESHOLD = 0.01;

ObjContribFuncBarrier::ObjContribFuncBarrier()
  : _target(0.), _barrier(0.), _init(0.), _opt(0.), _defaultMargin(0.)
{
}

void ObjContribFuncBarrier::setTarget(double target, double opt,
                                      double defaultMargin)
{
  _target = target;
  _opt = opt;
  _defaultMargin = defaultMargin;
  if(_defaultMargin == 0.) {
    if(opt != 0.)
      _defaultMargin = MARGINCOEFF * fabs(opt);
    else if(target != 0.)
      _defaultMargin = MARGINCOEFF * fabs(target);
    else
      Msg::Warning(
        "Could not find value to define a scale for default barrier margin");
  }
}

void ObjContribFuncBarrierMovMin::updateParameters(double vMin, double vMax)
{
  _init = vMin;
  const double margin =
    (vMin == 0.) ? _defaultMargin : MARGINCOEFF * fabs(vMin);
  _barrier = vMin - margin;
}

bool ObjContribFuncBarrierMovMin::stagnated(double vMin, double vMax)
{
  return (fabs((vMin - _init) / _init) < STAGTHRESHOLD);
}

void ObjContribFuncBarrierMovMax::updateParameters(double vMin, double vMax)
{
  _init = vMax;
  const double margin =
    (vMax == 0.) ? _defaultMargin : MARGINCOEFF * fabs(vMax);
  _barrier = vMax + margin;
}

bool ObjContribFuncBarrierMovMax::stagnated(double vMin, double vMax)
{
  return (fabs((vMax - _init) / _init) < STAGTHRESHOLD);
}

void ObjContribFuncBarrierFixMin::initialize(double vMin, double vMax)
{
  const double margin =
    (vMin == 0.) ? _defaultMargin : MARGINCOEFF * fabs(vMin);
  _barrier = vMin - margin;
}

void ObjContribFuncBarrierFixMinMovMax::initialize(double vMin, double vMax)
{
  ObjContribFuncBarrierMovMax::initialize(vMin, vMax);
  const double margin =
    (vMin == 0.) ? _defaultMargin : MARGINCOEFF * fabs(vMin);
  _fixedMinBarrier = vMin - margin;
}
