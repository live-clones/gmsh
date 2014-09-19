// TODO: Copyright

#ifndef _MESHOPTOBJCONTRIBSCALEDNODEDISPSQ_H_
#define _MESHOPTOBJCONTRIBSCALEDNODEDISPSQ_H_

#include "MeshOptPatch.h"
#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribScaledNodeDispSq : public ObjContrib, public FuncType
{
public:
  ObjContribScaledNodeDispSq(double weightFixed, double weightFree);
  virtual ~ObjContribScaledNodeDispSq() {}
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
  double _weightFixed, _weightFree;

};


template<class FuncType>
ObjContribScaledNodeDispSq<FuncType>::ObjContribScaledNodeDispSq(double weightFixed,
                                                                    double weightFree) :
  ObjContrib("ScaledNodeDispSq", FuncType::getNamePrefix()+"ScaledNodeDispSq"),
  _mesh(0), _weightFixed(weightFixed), _weightFree(weightFree)
{
}


template<class FuncType>
ObjContrib *ObjContribScaledNodeDispSq<FuncType>::copy() const
{
  return new ObjContribScaledNodeDispSq<FuncType>(*this);
}


template<class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initScaledNodeDispSq();
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribScaledNodeDispSq<FuncType>::addContrib(double &Obj,
                                                      alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iFV = 0; iFV < _mesh->nFV(); iFV++) {
    const double Factor = _mesh->forced(iFV) ? _weightFixed : _weightFree;
    const double dSq = _mesh->scaledNodeDispSq(iFV);
    Obj += Factor * FuncType::compute(dSq);
    std::vector<double> gDSq(_mesh->nPCFV(iFV));
    _mesh->gradScaledNodeDispSq(iFV, gDSq);
    const double dfact = Factor * FuncType::computeDiff(dSq);
    for (int iPC = 0; iPC < _mesh->nPCFV(iFV); iPC++)
      gradObj[_mesh->indPCFV(iFV, iPC)] += dfact * gDSq[iPC];
    _min = std::min(_min, dSq);
    _max = std::max(_max, dSq);
  }

  return true;
}


template<class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iFV = 0; iFV < _mesh->nFV(); iFV++) {
    const double dSq = _mesh->scaledNodeDispSq(iFV);
    _min = std::min(_min, dSq);
    _max = std::max(_max, dSq);
  }
}


template<class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::updateResults(MeshOptResults &res) const
{
  const double scaleSq = 1./_mesh->invLengthScaleSq();
  res.minNodeDisp = std::min(sqrt(_min*scaleSq), res.minNodeDisp);
  res.maxNodeDisp = std::max(sqrt(_max*scaleSq), res.maxNodeDisp);
}


#endif /* _MESHOPTOBJCONTRIBSCALEDNODEDISPSQ_H_ */
