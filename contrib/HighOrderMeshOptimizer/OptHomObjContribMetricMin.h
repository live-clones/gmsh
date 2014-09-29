// TODO: Copyright

#ifndef _OPTHOMOBJCONTRIBMETRICMIN_H_
#define _OPTHOMOBJCONTRIBMETRICMIN_H_

#include "MeshOptPatch.h"
#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribMetricMin : public ObjContrib, public FuncType
{
public:
  ObjContribMetricMin(double weight);
  virtual ~ObjContribMetricMin() {}
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
};


template<class FuncType>
ObjContribMetricMin<FuncType>::ObjContribMetricMin(double weight) :
  ObjContrib("MetricMin", FuncType::getNamePrefix()+"MetricMin"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
ObjContrib *ObjContribMetricMin<FuncType>::copy() const
{
  return new ObjContribMetricMin<FuncType>(*this);
}


template<class FuncType>
void ObjContribMetricMin<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledJac();
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribMetricMin<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> mM(_mesh->nBezEl(iEl));                                     // Min. of Metric
    std::vector<double> gMM(_mesh->nBezEl(iEl)*_mesh->nPCEl(iEl));                  // Dummy gradients of metric min.
    _mesh->metricMinAndGradients(iEl, mM, gMM);
    for (int l = 0; l < _mesh->nBezEl(iEl); l++) {                                  // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(mM[l]);
      const double dfact = _weight * FuncType::computeDiff(mM[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl,iPC)] += dfact *  gMM[_mesh->indGSJ(iEl, l, iPC)];
      _min = std::min(_min, mM[l]);
      _max = std::max(_max, mM[l]);
    }
  }

  return true;
}


template<class FuncType>
void ObjContribMetricMin<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> mM(_mesh->nBezEl(iEl));                         // Min. of Metric
    std::vector<double> dumGMM(_mesh->nBezEl(iEl)*_mesh->nPCEl(iEl));   // Dummy gradients of metric min.
    _mesh->metricMinAndGradients(iEl, mM, dumGMM);
    for (int l = 0; l < _mesh->nBezEl(iEl); l++) {                      // Check each Bezier coeff.
      _min = std::min(_min, mM[l]);
      _max = std::max(_max, mM[l]);
    }
  }
}


#endif /* _OPTHOMOBJCONTRIBMETRICMIN_H_ */
