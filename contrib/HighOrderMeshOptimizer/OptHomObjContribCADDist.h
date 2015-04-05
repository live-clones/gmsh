// TODO: Copyright

#ifndef _OPTHOMOBJCONTRIBCADDIST_H_
#define _OPTHOMOBJCONTRIBCADDIST_H_

#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribCADDistSq : public ObjContrib, public FuncType
{
public:
  ObjContribCADDistSq(double weight, double refDist);
  virtual ~ObjContribCADDistSq() {}
  virtual ObjContrib *copy() const;
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return false; }
  virtual bool addContrib(double &Obj, alglib::real_1d_array &gradObj);
  virtual void updateParameters() { FuncType::updateParameters(_min, _max); }
  virtual bool targetReached() { return FuncType::targetReached(_min, _max); }
  virtual bool stagnated() { return FuncType::stagnated(_min, _max); }
  virtual void updateMinMax();

protected:
  Patch *_mesh;
  double _weight;
  double _refDist;
};


template<class FuncType>
ObjContribCADDistSq<FuncType>::ObjContribCADDistSq(double weight, double refDist) :
  ObjContrib("ScaledCADDistSq", FuncType::getNamePrefix()+"ScaledCADDistSq"),
  _mesh(0), _weight(weight), _refDist(refDist)
{
}


template<class FuncType>
ObjContrib *ObjContribCADDistSq<FuncType>::copy() const
{
  return new ObjContribCADDistSq<FuncType>(*this);
}


template<class FuncType>
void ObjContribCADDistSq<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledCADDistSq(_refDist);
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribCADDistSq<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  const int bndDim = _mesh->dim()-1;

  for (int iBndEl = 0; iBndEl < _mesh->nBndEl(); iBndEl++) {
    const int nVEl = _mesh->nNodBndEl(iBndEl);
    double f;
    std::vector<double> gradF(nVEl*bndDim);
    _mesh->scaledCADDistSqAndGradients(iBndEl, f, gradF);
    _min = std::min(_min, f);
    _max = std::max(_max, f);
    Obj += FuncType::compute(f) * _weight;
    const double dFact = _weight * FuncType::computeDiff(f);
    for (int i=0; i<nVEl; i++) {
      const int iFVi = _mesh->bndEl2FV(iBndEl, i);
      if (iFVi >= 0) {                                                                            // Skip if not free vertex
        if (bndDim == 1) gradObj[_mesh->indPCFV(iFVi, 0)] += gradF[i] * dFact;                    // 2D
        else {                                                                                    // 3D
          gradObj[_mesh->indPCFV(iFVi, 0)] += gradF[2*i] * dFact;                                 // Deriv. w.r.t. 1st param.coord (edge or face vertex)
          if (_mesh->nPCFV(iFVi) > 1) gradObj[_mesh->indPCFV(iFVi, 1)] += gradF[2*i+1] * dFact;   // Deriv. w.r.t. 2nd param. coord. (only if face vertex)
        }
      }
    }
  }

  return true;
}


template<class FuncType>
void ObjContribCADDistSq<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  const int bndDim = _mesh->dim()-1;

  for (int iBndEl = 0; iBndEl < _mesh->nBndEl(); iBndEl++) {
    const int nVEl = _mesh->nNodBndEl(iBndEl);
    double f;
    std::vector<double> dumGradF(nVEl*bndDim);
    _mesh->scaledCADDistSqAndGradients(iBndEl, f, dumGradF);
    _min = std::min(_min, f);
    _max = std::max(_max, f);
  }
}


#endif /* _OPTHOMOBJCONTRIBCADDIST_H_ */
