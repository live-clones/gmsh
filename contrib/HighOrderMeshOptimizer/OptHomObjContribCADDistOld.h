// TODO: Copyright

#ifndef _OPTHOMOBJCONTRIBCADDISTOLD_H_
#define _OPTHOMOBJCONTRIBCADDISTOLD_H_

#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribCADDistOld : public ObjContrib, public FuncType
{
public:
  ObjContribCADDistOld(double weight, double geomTol);
  virtual ~ObjContribCADDistOld() {}
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
  double _geomTol;
};


template<class FuncType>
ObjContribCADDistOld<FuncType>::ObjContribCADDistOld(double weight, double geomTol) :
  ObjContrib("CADDistOld", FuncType::getNamePrefix()+"CADDistOld"),
  _mesh(0), _weight(weight), _geomTol(geomTol)
{
}


template<class FuncType>
ObjContrib *ObjContribCADDistOld<FuncType>::copy() const
{
  return new ObjContribCADDistOld<FuncType>(*this);
}


template<class FuncType>
void ObjContribCADDistOld<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;

  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribCADDistOld<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
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
void ObjContribCADDistOld<FuncType>::updateMinMax()
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


#endif /* _OPTHOMOBJCONTRIBCADDISTOLD_H_ */
