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

#ifndef OBJ_CONTRIB_SCALED_NODE_DISP_SQ_H
#define OBJ_CONTRIB_SCALED_NODE_DISP_SQ_H

#include "Patch.h"
#include "ObjContrib.h"

template <class FuncType>
class ObjContribScaledNodeDispSq
  : public ObjContrib
  , public FuncType {
public:
  ObjContribScaledNodeDispSq(double weight, Patch::LengthScaling scaling);
  virtual ~ObjContribScaledNodeDispSq() {}
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
  Patch::LengthScaling _scaling;
};

template <class FuncType>
ObjContribScaledNodeDispSq<FuncType>::ObjContribScaledNodeDispSq(
  double weight, Patch::LengthScaling scaling)
  : ObjContrib("ScaledNodeDispSq",
               FuncType::getNamePrefix() + "ScaledNodeDispSq"),
    _mesh(nullptr), _weight(weight), _scaling(scaling)
{
}

template <class FuncType>
ObjContrib *ObjContribScaledNodeDispSq<FuncType>::copy() const
{
  return new ObjContribScaledNodeDispSq<FuncType>(*this);
}

template <class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledNodeDispSq(_scaling);
  updateMinMax();
  FuncType::initialize(_min, _max);
}

template <class FuncType>
bool ObjContribScaledNodeDispSq<FuncType>::addContrib(
  double &Obj, std::vector<double> &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for(int iFV = 0; iFV < _mesh->nFV(); iFV++) {
    const double dSq = _mesh->scaledNodeDispSq(iFV);
    Obj += _weight * FuncType::compute(dSq);
    std::vector<double> gDSq(_mesh->nPCFV(iFV));
    _mesh->gradScaledNodeDispSq(iFV, gDSq);
    const double dfact = _weight * FuncType::computeDiff(dSq);
    for(int iPC = 0; iPC < _mesh->nPCFV(iFV); iPC++)
      gradObj[_mesh->indPCFV(iFV, iPC)] += dfact * gDSq[iPC];
    _min = std::min(_min, dSq);
    _max = std::max(_max, dSq);
  }

  return true;
}

template <class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for(int iFV = 0; iFV < _mesh->nFV(); iFV++) {
    const double dSq = _mesh->scaledNodeDispSq(iFV);
    _min = std::min(_min, dSq);
    _max = std::max(_max, dSq);
  }
}

#endif
