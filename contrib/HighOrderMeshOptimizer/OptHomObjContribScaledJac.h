// TODO: Copyright

#ifndef _OPTHOMOBJCONTRIBSCALEDJAC_H_
#define _OPTHOMOBJCONTRIBSCALEDJAC_H_

#include "MeshOptPatch.h"
#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribScaledJac : public ObjContrib, public FuncType
{
public:
  ObjContribScaledJac(double weight);
  virtual ~ObjContribScaledJac() {}
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
ObjContribScaledJac<FuncType>::ObjContribScaledJac(double weight) :
  ObjContrib("ScaledJac", FuncType::getNamePrefix()+"ScaledJac"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
ObjContrib *ObjContribScaledJac<FuncType>::copy() const
{
  return new ObjContribScaledJac<FuncType>(*this);
}


template<class FuncType>
void ObjContribScaledJac<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledJac();
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribScaledJac<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> sJ(_mesh->nBezEl(iEl));                                       // Scaled Jacobians
    std::vector<double> gSJ(_mesh->nBezEl(iEl)*_mesh->nPCEl(iEl));                    // Gradients of scaled Jacobians
    _mesh->scaledJacAndGradients(iEl, sJ, gSJ);
    for (int l = 0; l < _mesh->nBezEl(iEl); l++) {                                    // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(sJ[l]);
      const double dfact = _weight * FuncType::computeDiff(sJ[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl, iPC)] += dfact * gSJ[_mesh->indGSJ(iEl, l, iPC)];
      _min = std::min(_min, sJ[l]);
      _max = std::max(_max, sJ[l]);
    }
  }

  return true;
}


template<class FuncType>
void ObjContribScaledJac<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> sJ(_mesh->nBezEl(iEl));                         // Scaled Jacobians
    std::vector<double> dumGSJ(_mesh->nBezEl(iEl)*_mesh->nPCEl(iEl));   // Gradients of scaled Jacobians
    _mesh->scaledJacAndGradients(iEl, sJ, dumGSJ);
    for (int l = 0; l < _mesh->nBezEl(iEl); l++) {                      // Check each Bezier coeff.
      _min = std::min(_min, sJ[l]);
      _max = std::max(_max, sJ[l]);
    }
  }
}


#endif /* _OPTHOMOBJCONTRIBSCALEDJAC_H_ */
