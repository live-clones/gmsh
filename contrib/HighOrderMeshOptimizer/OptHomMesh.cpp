// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include "GmshMessage.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "ParamCoord.h"
#include "OptHomMesh.h"
#include "BasisFactory.h"
#include "JacobianBasis.h"
#include "OptHomIntegralBoundaryDist.h"

Mesh::Mesh(const std::map<MElement*,GEntity*> &element2entity,
           const std::set<MElement*, Less_ElementPtr> &els, std::set<MVertex*> &toFix,
           bool fixBndNodes, bool fastJacEval) :
  _fastJacEval(fastJacEval)
{

  _dim = (*els.begin())->getDim();

  // Initialize elements, vertices, free vertices and element->vertices
  // connectivity
  const int nElements = els.size();
  _nPC = 0;
  _el.resize(nElements);
  _el2FV.resize(nElements);
  _el2V.resize(nElements);
  _nBezEl.resize(nElements);
  _nNodEl.resize(nElements);
  _indPCEl.resize(nElements);
  int iEl = 0;
  bool nonGeoMove = false;
  for(std::set<MElement*>::const_iterator it = els.begin();
      it != els.end(); ++it, ++iEl) {
    _el[iEl] = *it;
    const JacobianBasis *jac = _el[iEl]->getJacobianFuncSpace();
    _nBezEl[iEl] = _fastJacEval ? jac->getNumJacNodesFast() : jac->getNumJacNodes();
    _nNodEl[iEl] = jac->getNumMapNodes();
    for (int iVEl = 0; iVEl < jac->getNumMapNodes(); iVEl++) {
      MVertex *vert = _el[iEl]->getVertex(iVEl);
      GEntity *ge = vert->onWhat();
      const int vDim = ge->dim();
      const bool hasParam = ge->haveParametrization();
      int iV = addVert(vert);
      _el2V[iEl].push_back(iV);
      if ((vDim > 0) && (toFix.find(vert) == toFix.end()) && (!fixBndNodes || vDim == _dim)) {   // Free vertex?
        ParamCoord *param;
        if (vDim == 3) param = new ParamCoordPhys3D();
        else if (hasParam) param = new ParamCoordParent(vert);
        else {
          if (vDim == 2) param = new ParamCoordLocalSurf(vert);
          else param = new ParamCoordLocalLine(vert);
          nonGeoMove = true;
        }
        int iFV = addFreeVert(vert,iV,vDim,param,toFix);
        _el2FV[iEl].push_back(iFV);
        for (int i=_startPCFV[iFV]; i<_startPCFV[iFV]+vDim; i++) _indPCEl[iEl].push_back(i);
      }
      else _el2FV[iEl].push_back(-1);
    }
  }

  if (nonGeoMove) Msg::Info("WARNING: Some vertices will be moved along local lines "
                            "or planes, they may not remain on the exact geometry");

  // Initial coordinates
  _ixyz.resize(nVert());
  for (int iV = 0; iV < nVert(); iV++) _ixyz[iV] = _vert[iV]->point();
  _iuvw.resize(nFV());
  for (int iFV = 0; iFV < nFV(); iFV++) _iuvw[iFV] = _paramFV[iFV]->getUvw(_freeVert[iFV]);

  // Set current coordinates
  _xyz = _ixyz;
  _uvw = _iuvw;

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
  // Jacobians of 3D elements
  if (_dim == 2) {
    _scaledNormEl.resize(nEl());
    for (int iEl = 0; iEl < nEl(); iEl++) calcScaledNormalEl2D(element2entity,iEl);
  }
  else {
    _invStraightJac.resize(nEl(),1.);
    double dumJac[3][3];
    for (int iEl = 0; iEl < nEl(); iEl++)
      _invStraightJac[iEl] = 1. / fabs(_el[iEl]->getPrimaryJacobian(0.,0.,0.,dumJac));

    // initialize _scaledNormEl with empty fullMatrix for use in function
    // Mesh::scaledJacAndGradients(..)
    _scaledNormEl.resize(nEl());
  }

}

void Mesh::calcScaledNormalEl2D(const std::map<MElement*,GEntity*> &element2entity, int iEl)
{
  const JacobianBasis *jac = _el[iEl]->getJacobianFuncSpace();

  fullMatrix<double> primNodesXYZ(jac->getNumPrimMapNodes(),3);
  SVector3 geoNorm(0.,0.,0.);
  std::map<MElement*,GEntity*>::const_iterator itEl2ent = element2entity.find(_el[iEl]);
  GEntity *ge = (itEl2ent == element2entity.end()) ? 0 : itEl2ent->second;
  bool hasGeoNorm = ge && (ge->dim() == 2) && ge->haveParametrization();
  for (int i=0; i<jac->getNumPrimMapNodes(); i++) {
    const int &iV = _el2V[iEl][i];
    primNodesXYZ(i,0) = _xyz[iV].x();
    primNodesXYZ(i,1) = _xyz[iV].y();
    primNodesXYZ(i,2) = _xyz[iV].z();
    if (hasGeoNorm && (_vert[iV]->onWhat() == ge)) {
      double u, v;
      _vert[iV]->getParameter(0,u);
      _vert[iV]->getParameter(1,v);
      geoNorm += ((GFace*)ge)->normal(SPoint2(u,v));
    }
  }
  if (hasGeoNorm && (geoNorm.normSq() == 0.)) {
    SPoint2 param = ((GFace*)ge)->parFromPoint(_el[iEl]->barycenter(true),false);
    geoNorm = ((GFace*)ge)->normal(param);
  }
  if (!hasGeoNorm && ge && ge->geomType() == GEntity::DiscreteSurface) {
    SBoundingBox3d bb = ge->bounds();
    // If we don't have the CAD, check if the mesh is 2D:
    if (!bb.empty() && bb.max().z() - bb.min().z() == .0) {
      hasGeoNorm = true;
      geoNorm = SVector3(0, 0, 1);
    }
  }
  else if (!ge) {
    Msg::Warning("don't have the entity");
  }

  fullMatrix<double> &elNorm = _scaledNormEl[iEl];
  elNorm.resize(1,3);
  const double norm = jac->getPrimNormal2D(primNodesXYZ,elNorm);
  double factor = 1./norm;
  if (hasGeoNorm) {
    const double scal = geoNorm(0)*elNorm(0,0)+geoNorm(1)*elNorm(0,1)+geoNorm(2)*elNorm(0,2);
    if (scal < 0.) factor = -factor;
  }
  elNorm.scale(factor);   // Re-scaling normal here is faster than an extra scaling operation on the Jacobian
  //  elNorm.setAll(1);
}

int Mesh::getFreeVertexStartIndex(MVertex* vert)
{
  std::map<MVertex*,int>::iterator itVert = _startPC4FV.find(vert);
  if (itVert == _startPC4FV.end()) {
    //    Msg::Fatal("OptHOM Error : cannot find free vertex %d class %d %d (%d free vertices)",vert->getNum(),vert->onWhat()->tag(),vert->onWhat()->dim(),_freeVert.size());
    return -1;
  }  
  return itVert->second;    
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

int Mesh::addFreeVert(MVertex* vert, const int iV, const int nPCV,
                      ParamCoord *param, std::set<MVertex*> &toFix)
{
  std::vector<MVertex*>::iterator itVert = find(_freeVert.begin(),
                                                _freeVert.end(),vert);
  if (itVert == _freeVert.end()) {
    const int iStart = (_startPCFV.size() == 0)? 0 : _startPCFV.back()+_nPCFV.back();
    const bool forcedV = (vert->onWhat()->dim() < 2) || (toFix.find(vert) != toFix.end());
    _startPC4FV[vert] = iStart;
    _freeVert.push_back(vert);
    _paramFV.push_back(param);
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
  for (int iFV = 0; iFV < nFV(); iFV++) {
    SPoint3 &uvwV = _uvw[iFV];
    *it = uvwV[0]; it++;
    if (_nPCFV[iFV] >= 2) { *it = uvwV[1]; it++; }
    if (_nPCFV[iFV] == 3) { *it = uvwV[2]; it++; }
  }

}

void Mesh::updateMesh(const double *it)
{
  for (int iFV = 0; iFV < nFV(); iFV++) {
    int iV = _fv2V[iFV];
    SPoint3 &uvwV = _uvw[iFV];
    uvwV[0] = *it; it++;
    if (_nPCFV[iFV] >= 2) { uvwV[1] = *it; it++; }
    if (_nPCFV[iFV] == 3) { uvwV[2] = *it; it++; }
    _xyz[iV] = _paramFV[iFV]->uvw2Xyz(uvwV);
  }

}

void Mesh::distSqToStraight(std::vector<double> &dSq) {
  for (int iEl = 0; iEl < nEl(); iEl++) {
    const double d = _el[iEl]->maxDistToStraight();
    dSq[iEl] = d*d;
  }
}

void Mesh::elSizeSq(std::vector<double> &sSq)
{
  for (int iEl = 0; iEl < nEl(); iEl++) {
    const double s = _el[iEl]->getOuterRadius();
    sSq[iEl] = s*s;
  }
}

void Mesh::elInSize(std::vector<double> &s)
{
  for (int iEl = 0; iEl < nEl(); iEl++)
    s[iEl] = fabs(_el[iEl]->getInnerRadius());
}

void Mesh::getGEntityPositions(std::vector<SPoint3> &xyz,
			       std::vector<SPoint3> &uvw) 
{
  xyz.resize(nVert());
  uvw.resize(nFV());
  for (int iV = 0; iV < nVert(); iV++)
    xyz[iV] = SPoint3(_vert[iV]->x(),_vert[iV]->y(),_vert[iV]->z());
  for (int iFV = 0; iFV < nFV(); iFV++){
    MVertex *v = _freeVert[iFV];
    if (v->onWhat()->dim() == 1){
      double t;
      v->getParameter(0,t);
      uvw[iFV] = SPoint3(t,0,0);
    }
    if (v->onWhat()->dim() == 2){
      double uu,vv;
      v->getParameter(0,uu);
      v->getParameter(1,vv);
      uvw[iFV] = SPoint3(uu,vv,0);
    }
  }
}

void Mesh::updateGEntityPositions(const std::vector<SPoint3> &xyz,
				  const std::vector<SPoint3> &uvw)
{
  for (int iV = 0; iV < nVert(); iV++)
    _vert[iV]->setXYZ(xyz[iV].x(),xyz[iV].y(),xyz[iV].z());
  for (int iFV = 0; iFV < nFV(); iFV++)
      _paramFV[iFV]->exportParamCoord(uvw[iFV]);
}

void Mesh::updateGEntityPositions()
{
  updateGEntityPositions(_xyz,_uvw);
}

void Mesh::metricMinAndGradients(int iEl, std::vector<double> &lambda,
                                 std::vector<double> &gradLambda)
{
  const JacobianBasis *jacBasis = _el[iEl]->getJacobianFuncSpace();
  const int &numJacNodes = jacBasis->getNumJacNodes();
  const int &numMapNodes = jacBasis->getNumMapNodes();
  const int &numPrimMapNodes = jacBasis->getNumPrimMapNodes();
  fullVector<double> lambdaJ(numJacNodes), lambdaB(numJacNodes);
  fullMatrix<double> gradLambdaJ(numJacNodes, 2 * numMapNodes);
  fullMatrix<double> gradLambdaB(numJacNodes, 2 * numMapNodes);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes,3), nodesXYZStraight(numPrimMapNodes,3);
  for (int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i,0) = _xyz[iVi].x();
    nodesXYZ(i,1) = _xyz[iVi].y();
    nodesXYZ(i,2) = _xyz[iVi].z();
    if (i < numPrimMapNodes) {
      nodesXYZStraight(i,0) = _ixyz[iVi].x();
      nodesXYZStraight(i,1) = _ixyz[iVi].y();
      nodesXYZStraight(i,2) = _ixyz[iVi].z();
    }
  }

  jacBasis->getMetricMinAndGradients(nodesXYZ,nodesXYZStraight,lambdaJ,gradLambdaJ);

  //l2b.mult(lambdaJ, lambdaB);
  //l2b.mult(gradLambdaJ, gradLambdaB);
  lambdaB = lambdaJ;
  gradLambdaB = gradLambdaJ;

  int iPC = 0;
  std::vector<SPoint3> gXyzV(numJacNodes);
  std::vector<SPoint3> gUvwV(numJacNodes);
  for (int l = 0; l < numJacNodes; l++) {
    lambda[l] = lambdaB(l);
  }
  for (int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if (iFVi >= 0) {
      for (int l = 0; l < numJacNodes; l++) {
        gXyzV [l] = SPoint3(gradLambdaB(l,i+0*numMapNodes),
                            gradLambdaB(l,i+1*numMapNodes),/*BDB(l,i+2*nbNod)*/ 0.);
      }
      _paramFV[iFVi]->gXyz2gUvw(_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gradLambda[indGSJ(iEl,l,iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gradLambda[indGSJ(iEl,l,iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gradLambda[indGSJ(iEl,l,iPC+2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}

void Mesh::approximationErrorAndGradients(int iEl, double &f, std::vector<double> &gradF, double eps,
					  simpleFunction<double> &fct)
{
  std::vector<SPoint3> _xyz_temp;
  for (int iV = 0; iV < nVert(); iV++){
    _xyz_temp.push_back(SPoint3( _vert[iV]->x(), _vert[iV]->y(), _vert[iV]->z()));
    _vert[iV]->setXYZ(_xyz[iV].x(),_xyz[iV].y(),_xyz[iV].z());
  }

  MElement *element = _el[iEl];

  f = approximationError (fct, element);
  // FIME
  //  if (iEl < 1)printf("approx error elem %d = %g\n",iEl,f);
  int currentId = 0;
  // compute the size of the gradient
  // depends on how many dofs exist per vertex (0,1,2 or 3)
  for (size_t i = 0; i < element->getNumVertices(); ++i) {
    if (_el2FV[iEl][i] >= 0) {// some free coordinates
      currentId += _nPCFV[_el2FV[iEl][i]];
    }
  }
  gradF.clear();
  gradF.resize(currentId, 0.);
  currentId = 0;
  for (size_t i = 0; i < element->getNumVertices(); ++i) {
    if (_el2FV[iEl][i] >= 0) {// some free coordinates
      MVertex *v =  element->getVertex(i);
      // vertex classified on a model edge
      if (_nPCFV[_el2FV[iEl][i]] == 1){
	double t = _uvw[_el2FV[iEl][i]].x();
	GEdge *ge = (GEdge*)v->onWhat();
	SPoint3 p (v->x(),v->y(),v->z());
	GPoint d = ge->point(t+eps);
	v->setXYZ(d.x(),d.y(),d.z());
	double f_d = approximationError (fct, element);
	gradF[currentId++] = (f_d-f)/eps;
	if (iEl < 1)printf("df = %g\n",(f_d-f)/eps);
	v->setXYZ(p.x(),p.y(),p.z());
      }
      else if (_nPCFV[_el2FV[iEl][i]] == 2){
	double uu = _uvw[_el2FV[iEl][i]].x();
	double vv = _uvw[_el2FV[iEl][i]].y();
	GFace *gf = (GFace*)v->onWhat();
	SPoint3 p (v->x(),v->y(),v->z());
	GPoint  d = gf->point(uu+eps,vv);
	v->setXYZ(d.x(),d.y(),d.z());
	double f_u = approximationError (fct, element);
	gradF[currentId++] = (f_u-f)/eps;
	d = gf->point(uu,vv+eps);
	v->setXYZ(d.x(),d.y(),d.z());
	double f_v = approximationError (fct, element);
	gradF[currentId++] = (f_v-f)/eps;
	v->setXYZ(p.x(),p.y(),p.z());
	//	if (iEl < 1)printf("df = %g %g\n",(f_u-f)/eps,(f_v-f)/eps);
      }
    }
  }
  for (int iV = 0; iV < nVert(); iV++)
    _vert[iV]->setXYZ(_xyz_temp[iV].x(),_xyz_temp[iV].y(),_xyz_temp[iV].z());

}


bool Mesh::bndDistAndGradients(int iEl, double &f , std::vector<double> &gradF, double eps)
{
  MElement *element = _el[iEl];
  f = 0.;
  // dommage ;-)
  if (element->getDim() != 2)
    return false;

  int currentId = 0;
  bool touches_boundary = false;
  std::vector<int> vertex2param(element->getNumVertices());
  for (size_t i = 0; i < element->getNumVertices(); ++i) {
    if (_el2FV[iEl][i] >= 0) {
      if ( _nPCFV[_el2FV[iEl][i]] == 1) touches_boundary = true;
      vertex2param[i] = currentId;
      currentId += _nPCFV[_el2FV[iEl][i]];
    }
    else
      vertex2param[i] = -1;
  }
  gradF.clear();
  gradF.resize(currentId, 0.);

  if (!touches_boundary){/*printf("ele %d\n",iEl);*/return true;}
  const nodalBasis &elbasis = *element->getFunctionSpace();
  bool edgeFound = false;
  for (int iEdge = 0; iEdge < element->getNumEdges(); ++iEdge) {
    int clId = elbasis.getClosureId(iEdge, 1);
    const std::vector<int> &closure = elbasis.closures[clId];
    std::vector<MVertex *> vertices;
    GEdge *edge = NULL;
    for (size_t i = 0; i < closure.size(); ++i) {
      MVertex *v = element->getVertex(closure[i]);
      vertices.push_back(v);
      // only valid in 2D
      if ((int)i >= 2 && v->onWhat() && v->onWhat()->dim() == 1) {
        edge = v->onWhat()->cast2Edge();
      }
    }
    if (edge) {
      edgeFound = true;
      std::vector<double> localgrad;
      std::vector<SPoint3> nodes(closure.size());
      std::vector<double> params(closure.size());
      std::vector<bool> onedge(closure.size());
      for (size_t i = 0; i < closure.size(); ++i) {
        nodes[i] = _xyz[_el2V[iEl][closure[i]]];
        onedge[i] = element->getVertex(closure[i])->onWhat() == edge && _el2FV[iEl][closure[i]] >= 0;
        if (onedge[i]) {
          params[i] = _uvw[_el2FV[iEl][closure[i]]].x();
        }else
          reparamMeshVertexOnEdge(element->getVertex(closure[i]), edge, params[i]);
      }
      f += computeBndDistAndGradient(edge, params, vertices, *BasisFactory::getNodalBasis(elbasis.getClosureType(clId)), nodes, onedge, localgrad, eps);
      for (size_t i = 0; i < closure.size(); ++i) {
        if (onedge[i])
	  gradF[vertex2param[closure[i]]] += localgrad[i];
      }
    }
  }
  return edgeFound;
}

void Mesh::scaledJacAndGradients(int iEl, std::vector<double> &sJ,
                                 std::vector<double> &gSJ)
{
  const JacobianBasis *jacBasis = _el[iEl]->getJacobianFuncSpace();
  const int &numJacNodes = _nBezEl[iEl];
  const int &numMapNodes = _nNodEl[iEl];
  fullMatrix<double> JDJ(numJacNodes,3*numMapNodes+1), BDB(numJacNodes,3*numMapNodes+1);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes,3), normals(_dim,3);
  for (int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i,0) = _xyz[iVi].x();
    nodesXYZ(i,1) = _xyz[iVi].y();
    nodesXYZ(i,2) = _xyz[iVi].z();
  }

  // Calculate Jacobian and gradients, scale if 3D (already scaled by
  // regularization normals in 2D)
  if (_fastJacEval)
    jacBasis->getSignedJacAndGradientsFast(nodesXYZ,_scaledNormEl[iEl],JDJ);
  else
    jacBasis->getSignedJacAndGradients(nodesXYZ,_scaledNormEl[iEl],JDJ);
  if (_dim == 3) JDJ.scale(_invStraightJac[iEl]);

  // Transform Jacobian and gradients from Lagrangian to Bezier basis
  if (_fastJacEval)
    BDB = JDJ;
  else
    jacBasis->lag2Bez(JDJ,BDB);

  // Scaled jacobian
  for (int l = 0; l < numJacNodes; l++) sJ [l] = BDB (l,3*numMapNodes);

  // Gradients of the scaled jacobian
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numJacNodes);
  std::vector<SPoint3> gUvwV(numJacNodes);
  for (int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if (iFVi >= 0) {
      for (int l = 0; l < numJacNodes; l++)
        gXyzV [l] = SPoint3(BDB(l,i+0*numMapNodes), BDB(l,i+1*numMapNodes),
                            BDB(l,i+2*numMapNodes));
      _paramFV[iFVi]->gXyz2gUvw(_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gSJ[indGSJ(iEl,l,iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gSJ[indGSJ(iEl,l,iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gSJ[indGSJ(iEl,l,iPC+2)] = gUvwV[l][2];
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
  _paramFV[iFV]->gXyz2gUvw(_uvw[iFV],dX,gX);
  _paramFV[iFV]->gXyz2gUvw(_uvw[iFV],dY,gY);
  _paramFV[iFV]->gXyz2gUvw(_uvw[iFV],dZ,gZ);

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
    fprintf(f, "%d %d 2 0 0", _el[iEl]->getNum(), _el[iEl]->getTypeForMSH());
    for (size_t iVEl = 0; iVEl < _el2V[iEl].size(); iVEl++)
      fprintf(f, " %d", _el2V[iEl][iVEl] + 1);
    fprintf(f, "\n");
  }
  fprintf(f, "$EndElements\n");

  fclose(f);
}
