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
ObjContribMetricMin<FuncType>::ObjContribMetricMin(double weight) :
  ObjContrib("MetricMin", FuncType::getNamePrefix()+"MetricMin"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
void ObjContribMetricMin<FuncType>::initialize(Patch *mesh)
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
bool ObjContribMetricMin<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
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
void ObjContribMetricMin<FuncType>::updateMinMax()
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
void ObjContribMetricMin<FuncType>::updateResults(MeshOptResults &res) const
{
  res.minMetricMin = std::min(_min, res.minMetricMin);
  res.maxMetricMin = std::max(_max, res.maxMetricMin);
}


template<class FuncType>
void ObjContribMetricMin<FuncType>::metricMinAndGradients(int iEl, std::vector<double> &lambda,
                                                                 std::vector<double> &gradLambda)
{
  const JacobianBasis *jacBasis = _mesh->el(iEl)->getJacobianFuncSpace();
  const int &numJacNodes = jacBasis->getNumJacNodes();
  const int &numMapNodes = jacBasis->getNumMapNodes();
  const int &numPrimMapNodes = jacBasis->getNumPrimMapNodes();
  fullVector<double> lambdaJ(numJacNodes), lambdaB(numJacNodes);
  fullMatrix<double> gradLambdaJ(numJacNodes, 2*numMapNodes);
  fullMatrix<double> gradLambdaB(numJacNodes, 2*numMapNodes);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes, 3), nodesXYZStraight(numPrimMapNodes, 3);
  for (int i = 0; i < numMapNodes; i++) {
    const int &iVi = _mesh->el2V(iEl, i);
    nodesXYZ(i, 0) = _mesh->xyz(iVi).x();
    nodesXYZ(i, 1) = _mesh->xyz(iVi).y();
    nodesXYZ(i, 2) = _mesh->xyz(iVi).z();
    if (i < numPrimMapNodes) {
      nodesXYZStraight(i, 0) = _mesh->ixyz(iVi).x();
      nodesXYZStraight(i, 1) = _mesh->ixyz(iVi).y();
      nodesXYZStraight(i, 2) = _mesh->ixyz(iVi).z();
    }
  }

  jacBasis->getMetricMinAndGradients(nodesXYZ, nodesXYZStraight, lambdaJ, gradLambdaJ);

  lambdaB = lambdaJ;
  gradLambdaB = gradLambdaJ;

  int iPC = 0;
  std::vector<SPoint3> gXyzV(numJacNodes);
  std::vector<SPoint3> gUvwV(numJacNodes);
  for (int l = 0; l < numJacNodes; l++) {
    lambda[l] = lambdaB(l);
  }
  for (int i = 0; i < numMapNodes; i++) {
    const int &iFVi = _mesh->el2FV(iEl, i);
    if (iFVi >= 0) {
      for (int l = 0; l < numJacNodes; l++) {
        gXyzV [l] = SPoint3(gradLambdaB(l, i),
                            gradLambdaB(l, i+numMapNodes),/*BDB(l,i+2*nbNod)*/ 0.);
      }
      _mesh->gXyz2gUvw(iFVi, gXyzV, gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gradLambda[indGSJ(iEl, l, iPC)] = gUvwV[l][0];
        if (_mesh->nPCFV(iFVi) >= 2) gradLambda[indGSJ(iEl, l, iPC+1)] = gUvwV[l][1];
        if (_mesh->nPCFV(iFVi) == 3) gradLambda[indGSJ(iEl, l, iPC+2)] = gUvwV[l][2];
      }
      iPC += _mesh->nPCFV(iFVi);
    }
  }
}


#endif /* _OPTHOMOBJCONTRIBMETRICMIN_H_ */
