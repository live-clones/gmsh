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
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return _min <= 0.; }
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
  std::vector<fullMatrix<double> > _scaledNormEl;                                       // Normals to 2D elements for Jacobian regularization and scaling
  std::vector<double> _invStraightJac;                                                  // Initial Jacobians for 3D elements
//  inline const int &nBezEl(int iEl) { return _nBezEl[iEl]; }
  inline int indGSJ(int iEl, int l, int iPC) { return iPC*_nBezEl[iEl]+l; }
  void scaledJacAndGradients(int iEl, std::vector<double> &sJ, std::vector<double> &gSJ);
//  void calcScaledNormalEl2D(const std::map<MElement*,GEntity*> &element2entity, int iEl);
  void calcScaledNormalEl2D(int iEl);
};


template<class FuncType>
ObjContribScaledJac<FuncType>::ObjContribScaledJac(double weight) :
  ObjContrib("ScaledJac", FuncType::getNamePrefix()+"ScaledJac"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
void ObjContribScaledJac<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;

  // Initialize _nBezEl
  _nBezEl.resize(_mesh->nEl());
  for (int iEl=0; iEl<_mesh->nEl(); iEl++)
   _nBezEl[iEl] = _mesh->el(iEl)->getJacobianFuncSpace()->getNumJacNodes();

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
  // Jacobians of 3D elements
  if (_mesh->dim() == 2) {
    _scaledNormEl.resize(_mesh->nEl());
//      for (int iEl = 0; iEl < nEl(); iEl++) calcScaledNormalEl2D(element2entity,iEl);
    for (int iEl = 0; iEl < _mesh->nEl(); iEl++) calcScaledNormalEl2D(iEl);
  }
  else {
    _invStraightJac.resize(_mesh->nEl());
    double dumJac[3][3];
    for (int iEl = 0; iEl < _mesh->nEl(); iEl++)
      _invStraightJac[iEl] = 1. / fabs(_mesh->el(iEl)->getPrimaryJacobian(0.,0.,0.,dumJac));
  }

  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribScaledJac<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> sJ(_nBezEl[iEl]);                                     // Scaled Jacobians
    std::vector<double> gSJ(_nBezEl[iEl]*_mesh->nPCEl(iEl));                  // Gradients of scaled Jacobians
    scaledJacAndGradients(iEl, sJ, gSJ);
    for (int l = 0; l < _nBezEl[iEl]; l++) {                                  // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(sJ[l]);
      const double dfact = _weight * FuncType::computeDiff(sJ[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl, iPC)] += dfact * gSJ[indGSJ(iEl, l, iPC)];
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
    std::vector<double> sJ(_nBezEl[iEl]);                         // Scaled Jacobians
    std::vector<double> dumGSJ(_nBezEl[iEl]*_mesh->nPCEl(iEl));   // Gradients of scaled Jacobians
    scaledJacAndGradients(iEl, sJ, dumGSJ);
    for (int l = 0; l < _nBezEl[iEl]; l++) {                      // Check each Bezier coeff.
      _min = std::min(_min, sJ[l]);
      _max = std::max(_max, sJ[l]);
    }
  }
}


template<class FuncType>
void ObjContribScaledJac<FuncType>::updateResults(MeshOptResults &res) const
{
  res.minScaledJac = std::min(_min, res.minScaledJac);
  res.maxScaledJac = std::max(_max, res.maxScaledJac);
}


// TODO: Re-introduce normal to geometry?
//void Mesh::calcScaledNormalEl2D(const std::map<MElement*,GEntity*> &element2entity, int iEl)
template<class FuncType>
void ObjContribScaledJac<FuncType>::calcScaledNormalEl2D(int iEl)
{
  const JacobianBasis *jac = _mesh->el(iEl)->getJacobianFuncSpace();

  fullMatrix<double> primNodesXYZ(jac->getNumPrimMapNodes(), 3);
//  SVector3 geoNorm(0.,0.,0.);
//  std::map<MElement*,GEntity*>::const_iterator itEl2ent = element2entity.find(_el[iEl]);
//  GEntity *ge = (itEl2ent == element2entity.end()) ? 0 : itEl2ent->second;
//  const bool hasGeoNorm = ge && (ge->dim() == 2) && ge->haveParametrization();
  for (int i=0; i<jac->getNumPrimMapNodes(); i++) {
    const int &iV = _mesh->el2V(iEl, i);
    primNodesXYZ(i,0) = _mesh->xyz(iV).x();
    primNodesXYZ(i,1) = _mesh->xyz(iV).y();
    primNodesXYZ(i,2) = _mesh->xyz(iV).z();
//    if (hasGeoNorm && (_vert[iV]->onWhat() == ge)) {
//      double u, v;
//      _vert[iV]->getParameter(0,u);
//      _vert[iV]->getParameter(1,v);
//      geoNorm += ((GFace*)ge)->normal(SPoint2(u,v));
//    }
  }
//  if (hasGeoNorm && (geoNorm.normSq() == 0.)) {
//    SPoint2 param = ((GFace*)ge)->parFromPoint(_el[iEl]->barycenter(true),false);
//    geoNorm = ((GFace*)ge)->normal(param);
//  }

  fullMatrix<double> &elNorm = _scaledNormEl[iEl];
  elNorm.resize(1, 3);
  const double norm = jac->getPrimNormal2D(primNodesXYZ, elNorm);
  double factor = 1./norm;
//  if (hasGeoNorm) {
//    const double scal = geoNorm(0)*elNorm(0,0)+geoNorm(1)*elNorm(0,1)+geoNorm(2)*elNorm(0,2);
//    if (scal < 0.) factor = -factor;
//  }
  elNorm.scale(factor);   // Re-scaling normal here is faster than an extra scaling operation on the Jacobian

}


template<class FuncType>
void ObjContribScaledJac<FuncType>::scaledJacAndGradients(int iEl, std::vector<double> &sJ,
                                                                   std::vector<double> &gSJ)
{
  const JacobianBasis *jacBasis = _mesh->el(iEl)->getJacobianFuncSpace();
  const int &numJacNodes = _nBezEl[iEl];
  const int &numMapNodes = _mesh->nNodEl(iEl);
  fullMatrix<double> JDJ(numJacNodes, 3*numMapNodes+1), BDB(numJacNodes, 3*numMapNodes+1);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes, 3), normals(_mesh->dim(), 3);
  for (int i = 0; i < numMapNodes; i++) {
    const int &iVi = _mesh->el2V(iEl, i);
    nodesXYZ(i, 0) = _mesh->xyz(iVi).x();
    nodesXYZ(i, 1) = _mesh->xyz(iVi).y();
    nodesXYZ(i, 2) = _mesh->xyz(iVi).z();
  }

  // Calculate Jacobian and gradients, scale if 3D (already scaled by
  // regularization normals in 2D)
  jacBasis->getSignedJacAndGradients(nodesXYZ, _scaledNormEl[iEl],JDJ);
  if (_mesh->dim() == 3) JDJ.scale(_invStraightJac[iEl]);

  // Transform Jacobian and gradients from Lagrangian to Bezier basis
  jacBasis->lag2Bez(JDJ,BDB);

  // Scaled jacobian
  for (int l = 0; l < numJacNodes; l++) sJ[l] = BDB (l, 3*numMapNodes);

  // Gradients of the scaled jacobian
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numJacNodes);
  std::vector<SPoint3> gUvwV(numJacNodes);
  for (int i = 0; i < numMapNodes; i++) {
    const int &iFVi = _mesh->el2FV(iEl, i);
    if (iFVi >= 0) {
      for (int l = 0; l < numJacNodes; l++)
        gXyzV[l] = SPoint3(BDB(l, i), BDB(l, i+numMapNodes), BDB(l, i+2*numMapNodes));
      _mesh->gXyz2gUvw(iFVi, gXyzV, gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gSJ[indGSJ(iEl, l, iPC)] = gUvwV[l][0];
        if (_mesh->nPCFV(iFVi) >= 2) gSJ[indGSJ(iEl, l, iPC+1)] = gUvwV[l][1];
        if (_mesh->nPCFV(iFVi) == 3) gSJ[indGSJ(iEl, l, iPC+2)] = gUvwV[l][2];
      }
      iPC += _mesh->nPCFV(iFVi);
    }
  }

}


#endif /* _OPTHOMOBJCONTRIBSCALEDJAC_H_ */
