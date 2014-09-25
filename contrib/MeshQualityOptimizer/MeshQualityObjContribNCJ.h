// TODO: Copyright

#ifndef _MESHQUALITYCONTRIBNCJ_H_
#define _MESHQUALITYCONTRIBNCJ_H_

#include "MeshOptPatch.h"
#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribNCJ : public ObjContrib, public FuncType
{
public:
  ObjContribNCJ(double weight);
  virtual ~ObjContribNCJ() {}
  virtual ObjContrib *copy() const;
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return _min <= 0.; }
  virtual bool addContrib(double &Obj, alglib::real_1d_array &gradObj);
  virtual void updateParameters() { FuncType::updateParameters(_min, _max); }
  virtual bool targetReached() { return FuncType::targetReached(_min, _max); }
  virtual bool stagnated() { return FuncType::stagnated(_min, _max); }
  virtual void updateMinMax();

protected:
  Patch *_mesh;
  double _weight;
};


template<class FuncType>
ObjContribNCJ<FuncType>::ObjContribNCJ(double weight) :
  ObjContrib("NCJ", FuncType::getNamePrefix()+"NCJ"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
ObjContrib *ObjContribNCJ<FuncType>::copy() const
{
  return new ObjContribNCJ<FuncType>(*this);
}


template<class FuncType>
void ObjContribNCJ<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initNCJ();
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribNCJ<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> NCJ(_mesh->nNCJEl(iEl));                                        // Scaled Jacobians
    std::vector<double> gNCJ(_mesh->nNCJEl(iEl)*_mesh->nPCEl(iEl));                     // Gradients of scaled Jacobians
    _mesh->NCJAndGradients(iEl, NCJ, gNCJ);
    for (int l = 0; l < _mesh->nNCJEl(iEl); l++) {                                      // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(NCJ[l]);
      const double dfact = _weight * FuncType::computeDiff(NCJ[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl, iPC)] += dfact * gNCJ[_mesh->indGNCJ(iEl, l, iPC)];
      _min = std::min(_min, NCJ[l]);
      _max = std::max(_max, NCJ[l]);
    }
  }

  return true;
}


template<class FuncType>
void ObjContribNCJ<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> NCJ(_mesh->nNCJEl(iEl));                         // Scaled Jacobians
    _mesh->NCJ(iEl, NCJ);
    for (int l = 0; l < _mesh->nBezEl(iEl); l++) {                      // Check each Bezier coeff.
      _min = std::min(_min, NCJ[l]);
      _max = std::max(_max, NCJ[l]);
    }
  }
}


#endif /* _MESHQUALITYCONTRIBNCJ_H_ */
