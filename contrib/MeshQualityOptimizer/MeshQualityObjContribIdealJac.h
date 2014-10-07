// TODO: Copyright

#ifndef _MESHQUALITYOBJCONTRIBIDEALJAC_H_
#define _MESHQUALITYOBJCONTRIBIDEALJAC_H_

#include "MeshOptPatch.h"
#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribIdealJac : public ObjContrib, public FuncType
{
public:
  ObjContribIdealJac(double weight);
  virtual ~ObjContribIdealJac() {}
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
ObjContribIdealJac<FuncType>::ObjContribIdealJac(double weight) :
  ObjContrib("IdealJac", FuncType::getNamePrefix()+"IdealJac"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
ObjContrib *ObjContribIdealJac<FuncType>::copy() const
{
  return new ObjContribIdealJac<FuncType>(*this);
}


template<class FuncType>
void ObjContribIdealJac<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initIdealJac();
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribIdealJac<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> iJ(_mesh->nIJacEl(iEl));                                       // Scaled Jacobians
    std::vector<double> gIJ(_mesh->nIJacEl(iEl)*_mesh->nPCEl(iEl));                    // Gradients of scaled Jacobians
    _mesh->idealJacAndGradients(iEl, iJ, gIJ);
    for (int l = 0; l < _mesh->nIJacEl(iEl); l++) {                                    // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(iJ[l]);
      const double dfact = _weight * FuncType::computeDiff(iJ[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl, iPC)] += dfact * gIJ[_mesh->indGIJac(iEl, l, iPC)];
      _min = std::min(_min, iJ[l]);
      _max = std::max(_max, iJ[l]);
    }
  }

  return true;
}


template<class FuncType>
void ObjContribIdealJac<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> iJ(_mesh->nIJacEl(iEl));                         // Scaled Jacobians
    std::vector<double> dumGIJ(_mesh->nIJacEl(iEl)*_mesh->nPCEl(iEl));   // Gradients of scaled Jacobians
    _mesh->idealJacAndGradients(iEl, iJ, dumGIJ);
    for (int l = 0; l < _mesh->nIJacEl(iEl); l++) {                      // Check each Bezier coeff.
      _min = std::min(_min, iJ[l]);
      _max = std::max(_max, iJ[l]);
    }
  }
}


#endif /* _MESHQUALITYOBJCONTRIBIDEALJAC_H_ */
