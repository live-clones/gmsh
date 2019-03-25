// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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

#ifndef OBJ_CONTRIB_CAD_DIST_H
#define OBJ_CONTRIB_CAD_DIST_H

#include <vector>
#include <algorithm>
#include "ObjContrib.h"

template <class FuncType>
class ObjContribCADDistSq
  : public ObjContrib
  , public FuncType {
public:
  ObjContribCADDistSq(double weight, double refDist);
  virtual ~ObjContribCADDistSq() {}
  virtual ObjContrib *copy() const;
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return false; }
  virtual bool addContrib(double &Obj, std::vector<double> &gradObj);
  virtual void updateParameters() { FuncType::updateParameters(_min, _max); }
  virtual bool targetReached() { return FuncType::targetReached(_min, _max); }
  virtual bool stagnated() { return FuncType::stagnated(_min, _max); }
  virtual void updateMinMax();

protected:
  Patch *_mesh;
  double _weight;
  double _refDist;
};

template <class FuncType>
ObjContribCADDistSq<FuncType>::ObjContribCADDistSq(double weight,
                                                   double refDist)
  : ObjContrib("ScaledCADDistSq",
               FuncType::getNamePrefix() + "ScaledCADDistSq"),
    _mesh(0), _weight(weight), _refDist(refDist)
{
}

template <class FuncType>
ObjContrib *ObjContribCADDistSq<FuncType>::copy() const
{
  return new ObjContribCADDistSq<FuncType>(*this);
}

template <class FuncType>
void ObjContribCADDistSq<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledCADDistSq(_refDist);
  updateMinMax();
  FuncType::initialize(_min, _max);
}

template <class FuncType>
bool ObjContribCADDistSq<FuncType>::addContrib(double &Obj,
                                               std::vector<double> &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  const int bndDim = _mesh->dim() - 1;

  for(int iBndEl = 0; iBndEl < _mesh->nBndEl(); iBndEl++) {
    const int nVEl = _mesh->nNodBndEl(iBndEl);
    double f;
    std::vector<double> gradF(nVEl * bndDim);
    _mesh->scaledCADDistSqAndGradients(iBndEl, f, gradF);
    _min = std::min(_min, f);
    _max = std::max(_max, f);
    Obj += FuncType::compute(f) * _weight;
    const double dFact = _weight * FuncType::computeDiff(f);
    for(int i = 0; i < nVEl; i++) {
      const int iFVi = _mesh->bndEl2FV(iBndEl, i);
      if(iFVi >= 0) { // Skip if not free vertex
        if(bndDim == 1)
          gradObj[_mesh->indPCFV(iFVi, 0)] += gradF[i] * dFact; // 2D
        else { // 3D
          gradObj[_mesh->indPCFV(iFVi, 0)] +=
            gradF[2 * i] *
            dFact; // Deriv. w.r.t. 1st param.coord (edge or face vertex)
          if(_mesh->nPCFV(iFVi) > 1)
            gradObj[_mesh->indPCFV(iFVi, 1)] +=
              gradF[2 * i + 1] *
              dFact; // Deriv. w.r.t. 2nd param. coord. (only if face vertex)
        }
      }
    }
  }

  return true;
}

template <class FuncType> void ObjContribCADDistSq<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  const int bndDim = _mesh->dim() - 1;

  for(int iBndEl = 0; iBndEl < _mesh->nBndEl(); iBndEl++) {
    const int nVEl = _mesh->nNodBndEl(iBndEl);
    double f;
    std::vector<double> dumGradF(nVEl * bndDim);
    _mesh->scaledCADDistSqAndGradients(iBndEl, f, dumGradF);
    _min = std::min(_min, f);
    _max = std::max(_max, f);
  }
}

#endif
