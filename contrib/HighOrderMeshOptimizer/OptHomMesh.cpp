#include "GmshMessage.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "ParamCoord.h"
#include "OptHomMesh.h"



std::map<int, fullMatrix<double> > Mesh::_gradShapeFunctions;
std::map<int, fullMatrix<double> > Mesh::_lag2Bez;



fullMatrix<double> Mesh::computeGSF(const polynomialBasis *lagrange, const bezierBasis *bezier)
{
  // bezier points are defined in the [0,1] x [0,1] quad
  fullMatrix<double> bezierPoints = bezier->points;
  if (lagrange->parentType == TYPE_QUA) {
    for (int i = 0; i < bezierPoints.size1(); ++i) {
      bezierPoints(i, 0) = -1 + 2 * bezierPoints(i, 0);
      bezierPoints(i, 1) = -1 + 2 * bezierPoints(i, 1);
    }
  }

  fullMatrix<double> allDPsi;
  lagrange->df(bezierPoints, allDPsi);
  return allDPsi;
}



Mesh::Mesh(GEntity *ge, const std::set<MElement*> &els, std::set<MVertex*> &toFix, int method) :
    _ge(ge)
{
  _dim = _ge->dim();

  if (method & METHOD_PHYSCOORD) {
    if (_dim == 2) _pc = new ParamCoordPhys2D;
    else _pc = new ParamCoordPhys3D;
    Msg::Debug("METHOD: Using physical coordinates");
  }
  else if (method & METHOD_SURFCOORD)  {
    if (_dim == 2) {
      _pc = new ParamCoordSurf(_ge);
      Msg::Debug("METHOD: Using surface parametric coordinates");
    }
    else Msg::Error("ERROR: Surface parametric coordinates only for 2D optimization");
  }
  else {
    _pc = new ParamCoordParent;
    Msg::Debug("METHOD: Using parent parametric coordinates");
  }

  if (method & METHOD_RELAXBND)Msg::Debug("METHOD: Relaxing boundary vertices");
  else if (method & METHOD_FIXBND) Msg::Debug("METHOD: Fixing all boundary vertices");
  else Msg::Debug("METHOD: Fixing vertices on geometric points and \"toFix\" boundary");

  // Initialize elements, vertices, free vertices and element->vertices connectivity
  const int nElements = els.size();
  _nPC = 0;
  _el.resize(nElements);
  _el2FV.resize(nElements);
  _el2V.resize(nElements);
  _nBezEl.resize(nElements);
  _nNodEl.resize(nElements);
  _indPCEl.resize(nElements);
  int iEl = 0;
  for(std::set<MElement*>::const_iterator it = els.begin(); it != els.end(); ++it, ++iEl) {
    MElement *el = *it;
    _el[iEl] = el;
    const polynomialBasis *lagrange = el->getFunctionSpace();
    const bezierBasis *bezier = JacobianBasis::find(lagrange->type)->bezier;
    if (_lag2Bez.find(lagrange->type) == _lag2Bez.end()) {
      _gradShapeFunctions[lagrange->type] = computeGSF(lagrange, bezier);
      _lag2Bez[lagrange->type] = bezier->matrixLag2Bez;
    }
    _nBezEl[iEl] = bezier->points.size1();
    _nNodEl[iEl] = lagrange->points.size1();
    for (int iVEl = 0; iVEl < lagrange->points.size1(); iVEl++) {
      MVertex *vert = el->getVertex(iVEl);
      int iV = addVert(vert);
      _el2V[iEl].push_back(iV);
      const int nPCV = _pc->nCoord(vert);
      bool isFV = false;
      if (method & METHOD_RELAXBND) isFV = true;
      else if (method & METHOD_FIXBND) isFV = (vert->onWhat()->dim() == _dim) && (toFix.find(vert) == toFix.end());
      else isFV = (vert->onWhat()->dim() >= 1) && (toFix.find(vert) == toFix.end());
      if (isFV) {
        int iFV = addFreeVert(vert,iV,nPCV,toFix);
        _el2FV[iEl].push_back(iFV);
        for (int i=_startPCFV[iFV]; i<_startPCFV[iFV]+nPCV; i++) _indPCEl[iEl].push_back(i);
      }
      else _el2FV[iEl].push_back(-1);
    }
  }

  // Initial coordinates
  _ixyz.resize(nVert());
  for (int iV = 0; iV < nVert(); iV++) _ixyz[iV] = _vert[iV]->point();
  _iuvw.resize(nFV());
  for (int iFV = 0; iFV < nFV(); iFV++) _iuvw[iFV] = _pc->getUvw(_freeVert[iFV]);

  // Set current coordinates
  _xyz = _ixyz;
  _uvw = _iuvw;

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial Jacobians of 3D elements
  if (_dim == 2) {
    _normEl.resize(nEl());
    for (int iEl = 0; iEl < nEl(); iEl++) _normEl[iEl] = getNormalEl(iEl);
  }
  else {
    _invStraightJac.resize(nEl(),1.);
    double dumJac[3][3];
    for (int iEl = 0; iEl < nEl(); iEl++) _invStraightJac[iEl] = 1. / _el[iEl]->getPrimaryJacobian(0.,0.,0.,dumJac);
  }
  if ((_dim == 2) && (method & METHOD_PROJJAC)) {
    projJac = true;
    Msg::Debug("METHOD: Using projected Jacobians");
  }
  else {
    projJac = false;
    Msg::Debug("METHOD: Using usual Jacobians");
  }
}



SVector3 Mesh::getNormalEl(int iEl)
{

  switch (_el[iEl]->getType()) {
    case TYPE_TRI: {
      const int iV0 = _el2V[iEl][0], iV1 = _el2V[iEl][1], iV2 = _el2V[iEl][2];
      SVector3 v10 = _xyz[iV1]-_xyz[iV0], v20 = _xyz[iV2]-_xyz[iV0];
      SVector3 n = crossprod(v10, v20);
      double xxx = n.norm();
      n *= 1./(xxx*xxx);
      return n;
      break;
    }
    case TYPE_QUA: {
      const int iV0 = _el2V[iEl][0], iV1 = _el2V[iEl][1], iV3 = _el2V[iEl][3];
      SVector3 v10 = _xyz[iV1]-_xyz[iV0], v30 = _xyz[iV3]-_xyz[iV0];
      SVector3 n = crossprod(v10, v30);
      double xxx = n.norm();
      n *= 4./(xxx*xxx);
      return n;
      break;
    }
    case TYPE_TET: {
      return SVector3(0.);
      break;
    }
    default:
      std::cout << "ERROR: getNormalEl: Unknown element type" << std::endl;
      break;
  }

  return SVector3(0.);  // Just to avoid compilation warnings...

}



int Mesh::addVert(MVertex* vert)
{

  std::vector<MVertex*>::iterator itVert = find(_vert.begin(),_vert.end(),vert);
  if (itVert == _vert.end()) {
    _vert.push_back(vert);
    return _vert.size()-1;
  }
  else return std::distance(_vert.begin(),itVert);

}



int Mesh::addFreeVert(MVertex* vert, const int iV, const int nPCV, std::set<MVertex*> &toFix)
{

  std::vector<MVertex*>::iterator itVert = find(_freeVert.begin(),_freeVert.end(),vert);
  if (itVert == _freeVert.end()) {
    const int iStart = (_startPCFV.size() == 0)? 0 : _startPCFV.back()+_nPCFV.back();
    const bool forcedV = (vert->onWhat()->dim() < 2) || (toFix.find(vert) != toFix.end());
    _freeVert.push_back(vert);
    _fv2V.push_back(iV);
    _startPCFV.push_back(iStart);
    _nPCFV.push_back(nPCV);
    _nPC += nPCV;
    _forced.push_back(forcedV);
    return _freeVert.size()-1;
  }
  else return std::distance(_freeVert.begin(),itVert);

}



void Mesh::getUvw(double *it)
{

//  std::vector<double>::iterator it = uvw.begin();
  for (int iFV = 0; iFV < nFV(); iFV++) {
    SPoint3 &uvwV = _uvw[iFV];
    *it = uvwV[0]; it++;
    if (_nPCFV[iFV] >= 2) { *it = uvwV[1]; it++; }
    if (_nPCFV[iFV] == 3) { *it = uvwV[2]; it++; }
  }

}



void Mesh::updateMesh(const double *it)
{

//  std::vector<double>::const_iterator it = uvw.begin();
  for (int iFV = 0; iFV < nFV(); iFV++) {
    int iV = _fv2V[iFV];
    SPoint3 &uvwV = _uvw[iFV];
    uvwV[0] = *it; it++;
    if (_nPCFV[iFV] >= 2) { uvwV[1] = *it; it++; }
    if (_nPCFV[iFV] == 3) { uvwV[2] = *it; it++; }
    _xyz[iV] = _pc->uvw2Xyz(_freeVert[iFV],uvwV);
  }

}


void Mesh::distSqToStraight(std::vector<double> &dSq)
{
  std::vector<SPoint3> sxyz(nVert());
  for (int iEl = 0; iEl < nEl(); iEl++) {
    MElement *el = _el[iEl];
    const polynomialBasis *lagrange = el->getFunctionSpace();
    const polynomialBasis *lagrange1 = el->getFunctionSpace(1);
    int nV = lagrange->points.size1();
    int nV1 = lagrange1->points.size1();
    for (int i = 0; i < nV1; ++i) {
      sxyz[_el2V[iEl][i]] = _vert[_el2V[iEl][i]]->point();
    }
    int dim = lagrange->points.size2();
    for (int i = nV1; i < nV; ++i) {
      double f[256];
      lagrange1->f(lagrange->points(i, 0), dim > 1 ? lagrange->points(i, 1) : 0., dim > 2 ? lagrange->points(i, 2) : 0., f);
      for (int j = 0; j < nV1; ++j)
        sxyz[_el2V[iEl][i]] += sxyz[_el2V[iEl][j]] * f[j];
    }
  }

  for (int iV = 0; iV < nVert(); iV++) {
    SPoint3 d = _xyz[iV]-sxyz[iV];
    dSq[iV] = d[0]*d[0]+d[1]*d[1]+d[2]*d[2];
  }
}



void Mesh::updateGEntityPositions()
{
  for (int iV = 0; iV < nVert(); iV++)
    _vert[iV]->setXYZ(_xyz[iV].x(),_xyz[iV].y(),_xyz[iV].z()); 
  for (int iFV = 0; iFV < nFV(); iFV++)
    _pc->exportParamCoord(_freeVert[iFV], _uvw[iFV]);
}


void Mesh::metricMinAndGradients(int iEl, std::vector<double> &lambda , std::vector<double> &gradLambda)
{
  fullMatrix<double> &gsf = _gradShapeFunctions[_el[iEl]->getTypeForMSH()];
  //const fullMatrix<double> &l2b = _lag2Bez[_el[iEl]->getTypeForMSH()];
  const int nbBez = _nBezEl[iEl];
  const int nbNod = _nNodEl[iEl];
  fullVector<double> lambdaJ(nbBez), lambdaB(nbBez);
  fullMatrix<double> gradLambdaJ(nbBez, 2 * nbNod);
  fullMatrix<double> gradLambdaB(nbBez, 2 * nbNod);

  // jacobian of the straight elements (only triangles for now)
  SPoint3 *IXYZ[3] = {&_ixyz[_el2V[iEl][0]], &_ixyz[_el2V[iEl][1]], &_ixyz[_el2V[iEl][2]]};
  double jaci[2][2] = {
    {IXYZ[1]->x() - IXYZ[0]->x(), IXYZ[2]->x() - IXYZ[0]->x()},
    {IXYZ[1]->y() - IXYZ[0]->y(), IXYZ[2]->y() - IXYZ[0]->y()}
  };
  double invJaci[2][2];
  inv2x2(jaci, invJaci);
  
  for (int l = 0; l < nbBez; l++) {
    fullMatrix<double> dPsi(gsf, l * 3, 3);
    double jac[2][2] = {{0., 0.}, {0., 0.}};
    for (int i = 0; i < nbNod; i++) {
      int &iVi = _el2V[iEl][i];
      const double dpsidx = dPsi(i, 0) * invJaci[0][0] + dPsi(i, 1) * invJaci[1][0];
      const double dpsidy = dPsi(i, 0) * invJaci[0][1] + dPsi(i, 1) * invJaci[1][1];
      jac[0][0] += _xyz[iVi].x() * dpsidx;
      jac[0][1] += _xyz[iVi].x() * dpsidy;
      jac[1][0] += _xyz[iVi].y() * dpsidx;
      jac[1][1] += _xyz[iVi].y() * dpsidy;
    }
    const double dxdx = jac[0][0] * jac[0][0] + jac[0][1] * jac[0][1];
    const double dydy = jac[1][0] * jac[1][0] + jac[1][1] * jac[1][1];
    const double dxdy = jac[0][0] * jac[1][0] + jac[0][1] * jac[1][1];
    const double sqr = sqrt((dxdx - dydy) * (dxdx - dydy) + 4 * dxdy * dxdy);
    const double osqr = sqr > 1e-8 ? 1/sqr : 0;
    lambdaJ(l) = 0.5 * (dxdx + dydy - sqr);
    const double axx = (1 - (dxdx - dydy) * osqr) * jac[0][0] - 2 * dxdy * osqr * jac[1][0];
    const double axy = (1 - (dxdx - dydy) * osqr) * jac[0][1] - 2 * dxdy * osqr * jac[1][1];
    const double ayx = -2 * dxdy * osqr * jac[0][0] + (1 - (dydy - dxdx) * osqr) * jac[1][0];
    const double ayy = -2 * dxdy * osqr * jac[0][1] + (1 - (dydy - dxdx) * osqr) * jac[1][1];
    const double axixi   = axx * invJaci[0][0] + axy * invJaci[0][1];
    const double aetaeta = ayx * invJaci[1][0] + ayy * invJaci[1][1];
    const double aetaxi  = ayx * invJaci[0][0] + ayy * invJaci[0][1];
    const double axieta  = axx * invJaci[1][0] + axy * invJaci[1][1];
    for (int i = 0; i < nbNod; i++) {
      gradLambdaJ(l, i + 0 * nbNod) = axixi * dPsi(i, 0) + axieta * dPsi(i, 1);
      gradLambdaJ(l, i + 1 * nbNod) = aetaxi * dPsi(i, 0) + aetaeta * dPsi(i, 1);
    }
  }
  
  //l2b.mult(lambdaJ, lambdaB);
  //l2b.mult(gradLambdaJ, gradLambdaB);
  lambdaB = lambdaJ;
  gradLambdaB = gradLambdaJ;

  int iPC = 0;
  std::vector<SPoint3> gXyzV(nbBez);
  std::vector<SPoint3> gUvwV(nbBez);
  for (int l = 0; l < nbBez; l++) {
    lambda[l] = lambdaB(l);
  }
  for (int i = 0; i < nbNod; i++) {
    int &iFVi = _el2FV[iEl][i];
    if (iFVi >= 0) {
      for (int l = 0; l < nbBez; l++) {
        gXyzV [l] = SPoint3(gradLambdaB(l,i+0*nbNod),gradLambdaB(l,i+1*nbNod),/*BDB(l,i+2*nbNod)*/ 0.);
      }
      _pc->gXyz2gUvw(_freeVert[iFVi],_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < nbBez; l++) {
        gradLambda[indGSJ(iEl,l,iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gradLambda[indGSJ(iEl,l,iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gradLambda[indGSJ(iEl,l,iPC+2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}

/*
  A faster version that computes jacobians and their gradients

  Terms of jacobian are of the form  J_{11} = dX / dU        

  X = \sum \phi_j X_{j}

  d J_{11} / dX_k = d \phi_k / du    

 */



void Mesh::scaledJacAndGradients(int iEl, std::vector<double> &sJ , std::vector<double> &gSJ) {
  
  // if (_dim == 2 && !projJac){
  //   //    printf("coucou\n");
  //   gradScaledJac(iEl,gSJ);
  //   scaledJac(iEl,sJ);    
  //   return;
  // }
  
  SVector3 n ;
  if (_dim == 2)
    n = _normEl[iEl];
  
  //  std::vector<double> OLD = sJ;
  //  std::vector<double> OLD = gSJ;
  //  gradScaledJac(iEl,OLD);
  //  scaledJac(iEl,OLD);

  fullMatrix<double> &gsf = _gradShapeFunctions[_el[iEl]->getTypeForMSH()];
  const fullMatrix<double> &l2b = _lag2Bez[_el[iEl]->getTypeForMSH()];
  const int nbBez = _nBezEl[iEl];
  const int nbNod = _nNodEl[iEl];
  fullMatrix<double> JDJ (nbBez,3*nbNod+1);
  fullMatrix<double> BDB (nbBez,3*nbNod+1);
  
  double jac[3][3];
  for (int l = 0; l < nbBez; l++) {
    fullMatrix<double> dPsi(gsf, l * 3, 3);

    jac[0][0] = jac[0][1] = jac[0][2] = 0.;
    jac[1][0] = jac[1][1] = jac[1][2] = 0.;
    jac[2][0] = (_dim == 2) ? n.x() : 0.0; jac[2][1] = (_dim == 2) ? n.y() : 0.0; jac[2][2] = (_dim == 2) ? n.z() : 0.0;

    const double INVJ = (_dim == 3) ? _invStraightJac[iEl] : 1.0;
    for (int i = 0; i < nbNod; i++) {
      int &iVi = _el2V[iEl][i];
      const double x = _xyz[iVi].x();
      const double y = _xyz[iVi].y();
      const double z = _xyz[iVi].z();
      for (int k = 0; k < _dim; k++) {
	const double gg = dPsi(i, k);
	jac[k][0] += x * gg;
	jac[k][1] += y * gg;
	jac[k][2] += z * gg;
      }
    }
    for (int i = 0; i < nbNod; i++) {
      JDJ (l,i+0*nbNod) = 
	( dPsi(i, 0) * jac[1][1] * jac[2][2] + jac[0][2] *  dPsi(i, 1) * jac[2][1] +
	 jac[0][1] * jac[1][2] *  dPsi(i, 2) - jac[0][2] * jac[1][1] *  dPsi(i, 2) -
	  dPsi(i, 0) * jac[1][2] * jac[2][1] - jac[0][1] *  dPsi(i, 1) * jac[2][2])
	* INVJ; 
      JDJ (l,i+1*nbNod) = 
	(jac[0][0] * dPsi(i, 1) * jac[2][2] + jac[0][2] * jac[1][0] * dPsi(i, 2) +
	 dPsi(i, 0) * jac[1][2] * jac[2][0] - jac[0][2] * dPsi(i, 1) * jac[2][0] -
	 jac[0][0] * jac[1][2] * dPsi(i, 2) - dPsi(i, 0) * jac[1][0] * jac[2][2])
	* INVJ; 
      JDJ (l,i+2*nbNod) = 
	(jac[0][0] * jac[1][1] * dPsi(i, 2) + dPsi(i, 0) * jac[1][0] * jac[2][1] +
	 jac[0][1] * dPsi(i, 1) * jac[2][0] - dPsi(i, 0) * jac[1][1] * jac[2][0] -
	 jac[0][0] * dPsi(i, 1) * jac[2][1] - jac[0][1] * jac[1][0] * dPsi(i, 2))
	* INVJ; 
    }    
    const double dJ = 
      jac[0][0] * jac[1][1] * jac[2][2] + jac[0][2] * jac[1][0] * jac[2][1] +
      jac[0][1] * jac[1][2] * jac[2][0] - jac[0][2] * jac[1][1] * jac[2][0] -
      jac[0][0] * jac[1][2] * jac[2][1] - jac[0][1] * jac[1][0] * jac[2][2];
    JDJ(l,3*nbNod) = dJ * INVJ;        
  }
  
  //  (N_b x N_b) x (N_b x 3*N_n + 1) 
  l2b.mult(JDJ,BDB);

  // the scaled jacobian
  //  printf("ELEMENT %d\n",iEl);
  for (int l = 0; l < nbBez; l++) {
    sJ [l] = BDB (l,3*nbNod);    
    //    printf("OLD %12.5E NEW %12.5E\n",OLD[l],sJ[l]);
  }

  // gradients of the scaled jacobian
  int iPC = 0;
  std::vector<SPoint3> gXyzV(nbBez);
  std::vector<SPoint3> gUvwV(nbBez);
  for (int i = 0; i < nbNod; i++) {
    int &iFVi = _el2FV[iEl][i];
    if (iFVi >= 0) {
      for (int l = 0; l < nbBez; l++) {
	gXyzV [l] = SPoint3(BDB(l,i+0*nbNod),BDB(l,i+1*nbNod),BDB(l,i+2*nbNod));
      }
      _pc->gXyz2gUvw(_freeVert[iFVi],_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < nbBez; l++) {
	gSJ[indGSJ(iEl,l,iPC)] = gUvwV[l][0];
	if (_nPCFV[iFVi] >= 2) gSJ[indGSJ(iEl,l,iPC+1)] = gUvwV[l][1];
	if (_nPCFV[iFVi] == 3) gSJ[indGSJ(iEl,l,iPC+2)] = gUvwV[l][2];
	//	if (fabs(OLD[indGSJ(iEl,l,iPC+2)]-gSJ[indGSJ(iEl,l,iPC+2)]) > 1.e-6)
	//	  printf("OLD = %12.5E new = %12.5E\n",OLD[indGSJ(iEl,l,iPC+2)],gSJ[indGSJ(iEl,l,iPC+2)]);
      }
      iPC += _nPCFV[iFVi];
    } 
  }
}



void Mesh::pcScale(int iFV, std::vector<double> &scale)
{

  // Calc. derivative of x, y & z w.r.t. parametric coordinates
  const SPoint3 dX(1.,0.,0.), dY(0.,1.,0.), dZ(0.,0.,1.);
  SPoint3 gX, gY, gZ;
  _pc->gXyz2gUvw(_freeVert[iFV],_uvw[iFV],dX,gX);
  _pc->gXyz2gUvw(_freeVert[iFV],_uvw[iFV],dY,gY);
  _pc->gXyz2gUvw(_freeVert[iFV],_uvw[iFV],dZ,gZ);

  // Scale = inverse norm. of vector (dx/du, dy/du, dz/du)
  scale[0] = 1./sqrt(gX[0]*gX[0]+gY[0]*gY[0]+gZ[0]*gZ[0]);
  if (_nPCFV[iFV] >= 2) scale[1] = 1./sqrt(gX[1]*gX[1]+gY[1]*gY[1]+gZ[1]*gZ[1]);
  if (_nPCFV[iFV] == 3) scale[2] = 1./sqrt(gX[2]*gX[2]+gY[2]*gY[2]+gZ[2]*gZ[2]);

}



void Mesh::writeMSH(const char *filename)
{
  FILE *f = fopen(filename, "w");

  fprintf(f, "$MeshFormat\n");
  fprintf(f, "2.2 0 8\n");
  fprintf(f, "$EndMeshFormat\n");

  fprintf(f, "$Nodes\n");
  fprintf(f, "%d\n", nVert());
  for (int i = 0; i < nVert(); i++)
    fprintf(f, "%d %22.15E %22.15E %22.15E\n", i + 1, _xyz[i].x(), _xyz[i].y(), _xyz[i].z());
  fprintf(f, "$EndNodes\n");

  fprintf(f, "$Elements\n");
  fprintf(f, "%d\n", nEl());
  for (int iEl = 0; iEl < nEl(); iEl++) {
//    MElement *MEl = _el[iEl];
    fprintf(f, "%d %d 2 0 %d", iEl+1, _el[iEl]->getTypeForMSH(), _ge->tag());
    for (size_t iVEl = 0; iVEl < _el2V[iEl].size(); iVEl++) fprintf(f, " %d", _el2V[iEl][iVEl] + 1);
    fprintf(f, "\n");
  }
  fprintf(f, "$EndElements\n");

  fclose(f);

}
