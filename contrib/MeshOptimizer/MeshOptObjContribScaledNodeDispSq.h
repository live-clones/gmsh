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
  double _invLengthScaleSq;                         // Square inverse of a length for node displacement scaling
  inline double scaledNodeDispSq(int iFV);
  inline void gradScaledNodeDispSq(int iFV, std::vector<double> &gDSq);

};


template<class FuncType>
ObjContribScaledNodeDispSq<FuncType>::ObjContribScaledNodeDispSq(double weightFixed,
                                                                    double weightFree) :
  ObjContrib("ScaledNodeDispSq", FuncType::getNamePrefix()+"ScaledNodeDispSq"),
  _mesh(0), _weightFixed(weightFixed), _weightFree(weightFree), _invLengthScaleSq(0.)
{
}


template<class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;

  double maxDSq = 0.;
  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    const double d = _mesh->el(iEl)->maxDistToStraight(), dd = d*d;
    if (dd > maxDSq) maxDSq = dd;
  }
  if (maxDSq < 1.e-10) {
    double maxSSq = 0.;
    for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
      const double s = _mesh->el(iEl)->getOuterRadius(), ss = s*s;
      if (ss > maxSSq) maxSSq = ss;
    }
    _invLengthScaleSq = 1./maxSSq;
  }
  else _invLengthScaleSq = 1./maxDSq;

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
    const double dSq = scaledNodeDispSq(iFV);
    Obj += Factor * FuncType::compute(dSq);
    std::vector<double> gDSq(_mesh->nPCFV(iFV));
    gradScaledNodeDispSq(iFV, gDSq);
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
    const double dSq = scaledNodeDispSq(iFV);
    _min = std::min(_min, dSq);
    _max = std::max(_max, dSq);
  }
}


template<class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::updateResults(MeshOptResults &res) const
{
  const double scaleSq = 1./_invLengthScaleSq;
  res.minNodeDisp = std::min(sqrt(_min*scaleSq), res.minNodeDisp);
  res.maxNodeDisp = std::max(sqrt(_max*scaleSq), res.maxNodeDisp);
}


template<class FuncType>
double ObjContribScaledNodeDispSq<FuncType>::scaledNodeDispSq(int iFV)
{
  const int &iV = _mesh->fv2V(iFV);
  const SPoint3 d = _mesh->xyz(iV)-_mesh->ixyz(iV);
  return (d[0]*d[0]+d[1]*d[1]+d[2]*d[2])*_invLengthScaleSq;
}


template<class FuncType>
void ObjContribScaledNodeDispSq<FuncType>::gradScaledNodeDispSq(int iFV, std::vector<double> &gDSq)
{
  const int &iV = _mesh->fv2V(iFV);
  const SPoint3 gXyz = (_mesh->xyz(iV)-_mesh->ixyz(iV))*2.*_invLengthScaleSq;
  SPoint3 gUvw;
  _mesh->gXyz2gUvw(iFV, gXyz, gUvw);

  gDSq[0] = gUvw[0];
  if (_mesh->nPCFV(iFV) >= 2) gDSq[1] = gUvw[1];
  if (_mesh->nPCFV(iFV) == 3) gDSq[2] = gUvw[2];
}


#endif /* _MESHOPTOBJCONTRIBSCALEDNODEDISPSQ_H_ */
