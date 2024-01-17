// MeshQualityOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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

#ifndef OBJ_CONTRIB_INV_COND_H
#define OBJ_CONTRIB_INV_COND_H

#include <vector>
#include <algorithm>
#include "Patch.h"
#include "ObjContrib.h"

template <class FuncType>
class ObjContribInvCondNum
  : public ObjContrib
  , public FuncType {
public:
  ObjContribInvCondNum(double weight);
  virtual ~ObjContribInvCondNum() {}
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
};

template <class FuncType>
ObjContribInvCondNum<FuncType>::ObjContribInvCondNum(double weight)
  : ObjContrib("InvCondNum", FuncType::getNamePrefix() + "InvCondNum"),
    _mesh(nullptr), _weight(weight)
{
}

template <class FuncType>
ObjContrib *ObjContribInvCondNum<FuncType>::copy() const
{
  return new ObjContribInvCondNum<FuncType>(*this);
}

template <class FuncType>
void ObjContribInvCondNum<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initInvCondNum();
  updateMinMax();
  FuncType::initialize(_min, _max);
}

template <class FuncType>
bool ObjContribInvCondNum<FuncType>::addContrib(double &Obj,
                                                std::vector<double> &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for(int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> invCond(_mesh->nICNEl(iEl)); // Min. of Metric
    std::vector<double> gInvCond(
      _mesh->nICNEl(iEl) * _mesh->nPCEl(iEl)); // Dummy gradients of metric min.
    _mesh->invCondNumAndGradients(iEl, invCond, gInvCond);
    for(int l = 0; l < _mesh->nICNEl(iEl);
        l++) { // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(invCond[l]);
      const double dfact = _weight * FuncType::computeDiff(invCond[l]);
      for(int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl, iPC)] +=
          dfact * gInvCond[_mesh->indGICN(iEl, l, iPC)];
      _min = std::min(_min, invCond[l]);
      _max = std::max(_max, invCond[l]);
    }
  }

  return true;
}

template <class FuncType> void ObjContribInvCondNum<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for(int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> invCond(_mesh->nICNEl(iEl)); // Min. of Metric
    std::vector<double> dumGInvCond(
      _mesh->nICNEl(iEl) * _mesh->nPCEl(iEl)); // Dummy gradients of metric min.
    _mesh->invCondNumAndGradients(iEl, invCond, dumGInvCond);
    for(int l = 0; l < _mesh->nICNEl(iEl);
        l++) { // Add contribution for each Bezier coeff.
      _min = std::min(_min, invCond[l]);
      _max = std::max(_max, invCond[l]);
    }
  }
}

#endif
