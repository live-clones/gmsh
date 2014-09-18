// TODO: Copyright

#ifndef _OPTHOMOBJCONTRIBCADDIST_H_
#define _OPTHOMOBJCONTRIBCADDIST_H_

#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribCADDist : public ObjContrib, public FuncType
{
public:
  ObjContribCADDist(double weight);
  virtual ~ObjContribCADDist() {}
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
  std::vector<int> _nBezEl;                                                             // Number of Bezier poly. and for an el.
  inline const int &nBezEl(int iEl) { return _nBezEl[iEl]; }
  inline int indGSJ(int iEl, int l, int iPC) { return iPC*_nBezEl[iEl]+l; }
  void metricMinAndGradients(int iEl, std::vector<double> &sJ, std::vector<double> &gSJ);
};


template<class FuncType>
ObjContribCADDist<FuncType>::ObjContribCADDist(double weight) :
  ObjContrib("MetricMin", FuncType::getNamePrefix()+"MetricMin"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
void ObjContribCADDist<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;

  // Initialize _nBezEl
  _nBezEl.resize(_mesh->nEl());
  for (int iEl=0; iEl<_mesh->nEl(); iEl++)
   _nBezEl[iEl] = _mesh->el(iEl)->getJacobianFuncSpace()->getNumJacNodes();

  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribCADDist<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> mM(_nBezEl[iEl]);                       // Min. of Metric
    std::vector<double> gMM(_nBezEl[iEl]*_mesh->nPCEl(iEl));    // Dummy gradients of metric min.
    metricMinAndGradients(iEl, mM, gMM);
    for (int l = 0; l < _nBezEl[iEl]; l++) {                    // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(mM[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl,iPC)] +=
            _weight * FuncType::computeDiff(mM[l], gMM[indGSJ(iEl, l, iPC)]);
      _min = std::min(_min, mM[l]);
      _max = std::max(_max, mM[l]);
    }
  }

  return true;
}


template<class FuncType>
void ObjContribCADDist<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> mM(_nBezEl[iEl]);                         // Min. of Metric
    std::vector<double> dumGMM(_nBezEl[iEl]*_mesh->nPCEl(iEl));   // Dummy gradients of metric min.
    metricMinAndGradients(iEl, mM, dumGMM);
    for (int l = 0; l < _nBezEl[iEl]; l++) {                      // Check each Bezier coeff.
      _min = std::min(_min, mM[l]);
      _max = std::max(_max, mM[l]);
    }
  }
}


template<class FuncType>
void ObjContribCADDist<FuncType>::updateResults(MeshOptResults &res) const
{
  res.minMetricMin = std::min(_min, res.minMetricMin);
  res.maxMetricMin = std::max(_max, res.maxMetricMin);
}


//bool MeshOpt::addBndObjGrad(double factor, double &Obj, alglib::real_1d_array &gradObj)
//{
//  maxDistCAD = 0.0;
//
//  std::vector<double> gradF;
//  double DISTANCE = 0.0;
//  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
//    double f;
//    if (mesh.bndDistAndGradients(iEl, f, gradF, geomTol)) {
//      maxDistCAD = std::max(maxDistCAD,f);
//      DISTANCE += f;
//      Obj += f * factor;
//      for (size_t i = 0; i < mesh.nPCEl(iEl); ++i){
//        gradObj[mesh.indPCEl(iEl, i)] += gradF[i] * factor;
//  //  printf("gradf[%d] = %12.5E\n",i,gradF[i]*factor);
//      }
//    }
//  }
//  //  printf("DIST = %12.5E\n",DISTANCE);
//  return true;
//
//}


#endif /* _OPTHOMOBJCONTRIBCADDIST_H_ */
