// TODO: Copyright

#ifndef _OPTHOMOBJCONTRIBCADDIST_H_
#define _OPTHOMOBJCONTRIBCADDIST_H_

#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribCADDist : public ObjContrib, public FuncType
{
public:
  ObjContribCADDist(double weight, double geomTol);
  virtual ~ObjContribCADDist() {}
  virtual ObjContrib *copy() const;
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return false; }
  virtual bool addContrib(double &Obj, alglib::real_1d_array &gradObj);
  virtual void updateParameters() { FuncType::updateParameters(_min, _max); }
  virtual bool targetReached() { return FuncType::targetReached(_min, _max); }
  virtual bool stagnated() { return FuncType::stagnated(_min, _max); }
  virtual void updateMinMax();
  virtual void updateResults(MeshOptResults &res) const;

protected:
  Patch *_mesh;
  double _weight;
  double _geomTol;
};


template<class FuncType>
ObjContribCADDist<FuncType>::ObjContribCADDist(double weight, double geomTol) :
  ObjContrib("MetricMin", FuncType::getNamePrefix()+"CADDist"),
  _mesh(0), _weight(weight), _geomTol(geomTol)
{
}


template<class FuncType>
ObjContrib *ObjContribCADDist<FuncType>::copy() const
{
  return new ObjContribCADDist<FuncType>(*this);
}


template<class FuncType>
void ObjContribCADDist<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;

  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribCADDist<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  std::vector<double> gradF;
  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    double f;
    if (_mesh->bndDistAndGradients(iEl, f, gradF, _geomTol)) {
      _min = std::min(_min, f);
      _max = std::max(_max, f);
      Obj += FuncType::compute(f) * _weight;
      const double dFact = _weight * FuncType::computeDiff(f);
      for (size_t i = 0; i < _mesh->nPCEl(iEl); ++i)
        gradObj[_mesh->indPCEl(iEl, i)] += gradF[i] * dFact;
    }
  }

  return true;
}


template<class FuncType>
void ObjContribCADDist<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  std::vector<double> dumGradF;
  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    double f;
    if (_mesh->bndDistAndGradients(iEl, f, dumGradF, _geomTol)) {
      _min = std::min(_min, f);
      _max = std::max(_max, f);
    }
  }
}


template<class FuncType>
void ObjContribCADDist<FuncType>::updateResults(MeshOptResults &res) const
{
  res.minCADDist = std::min(_min, res.minCADDist);
  res.maxCADDist = std::max(_max, res.maxCADDist);
}


#endif /* _OPTHOMOBJCONTRIBCADDIST_H_ */
