// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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

#ifndef OBJ_CONTRIB_SCALED_JAC_H
#define OBJ_CONTRIB_SCALED_JAC_H

#include <vector>
#include <algorithm>
#include "Patch.h"
#include "ObjContrib.h"

template <class FuncType>
class ObjContribScaledJac
  : public ObjContrib
  , public FuncType {
public:
  ObjContribScaledJac(double weight);
  virtual ~ObjContribScaledJac() {}
  virtual ObjContrib *copy() const;
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return _min <= 0.; }
  virtual bool addContrib(double &Obj, std::vector<double> &gradObj);
  virtual void updateParameters() { FuncType::updateParameters(_min, _max); }
  virtual bool targetReached() { return FuncType::targetReached(_min, _max); }
  virtual bool stagnated() { return FuncType::stagnated(_min, _max); }
  virtual void updateMinMax();

protected:
  Patch *_mesh;
  double _weight;
};

template <class FuncType>
ObjContribScaledJac<FuncType>::ObjContribScaledJac(double weight)
  : ObjContrib("ScaledJac", FuncType::getNamePrefix() + "ScaledJac"),
    _mesh(nullptr), _weight(weight)
{
}

template <class FuncType>
ObjContrib *ObjContribScaledJac<FuncType>::copy() const
{
  return new ObjContribScaledJac<FuncType>(*this);
}

template <class FuncType>
void ObjContribScaledJac<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledJac();
  updateMinMax();
  FuncType::initialize(_min, _max);
}

template <class FuncType>
bool ObjContribScaledJac<FuncType>::addContrib(double &Obj,
                                               std::vector<double> &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for(int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> sJ(_mesh->nBezEl(iEl)); // Scaled Jacobians
    std::vector<double> gSJ(_mesh->nBezEl(iEl) *
                            _mesh->nPCEl(iEl)); // Gradients of scaled Jacobians
    _mesh->scaledJacAndGradients(iEl, sJ, gSJ);
    for(int l = 0; l < _mesh->nBezEl(iEl);
        l++) { // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(sJ[l]);
      const double dfact = _weight * FuncType::computeDiff(sJ[l]);
      for(int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl, iPC)] +=
          dfact * gSJ[_mesh->indGSJ(iEl, l, iPC)];
      _min = std::min(_min, sJ[l]);
      _max = std::max(_max, sJ[l]);
    }
  }

  return true;
}

template <class FuncType> void ObjContribScaledJac<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for(int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> sJ(_mesh->nBezEl(iEl)); // Scaled Jacobians
    std::vector<double> dumGSJ(
      _mesh->nBezEl(iEl) * _mesh->nPCEl(iEl)); // Gradients of scaled Jacobians
    _mesh->scaledJacAndGradients(iEl, sJ, dumGSJ);
    for(int l = 0; l < _mesh->nBezEl(iEl); l++) { // Check each Bezier coeff.
      _min = std::min(_min, sJ[l]);
      _max = std::max(_max, sJ[l]);
    }
  }
}

#endif
