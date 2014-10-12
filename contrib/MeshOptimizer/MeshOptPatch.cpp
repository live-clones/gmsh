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
// <gmsh@geuz.org>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include "GmshMessage.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "BasisFactory.h"
#include "CondNumBasis.h"
#include "OptHomIntegralBoundaryDist.h"
#include "qualityMeasures.h"
#include "MeshOptPatch.h"


Patch::Patch(const std::map<MElement*,GEntity*> &element2entity,
           const std::set<MElement*> &els, std::set<MVertex*> &toFix,
           bool fixBndNodes) :
  _typeLengthScale(LS_NONE), _invLengthScaleSq(0.)
{

  _dim = (*els.begin())->getDim();

  // Initialize elements, vertices, free vertices and element->vertices
  // connectivity
  const int nElements = els.size();
  _nPC = 0;
  _el.resize(nElements);
  _el2FV.resize(nElements);
  _el2V.resize(nElements);
  _nNodEl.resize(nElements);
  _indPCEl.resize(nElements);
  int iEl = 0;
  bool nonGeoMove = false;
  for(std::set<MElement*>::const_iterator it = els.begin();
      it != els.end(); ++it, ++iEl) {
    _el[iEl] = *it;
    _nNodEl[iEl] = _el[iEl]->getNumVertices();
    for (int iVEl = 0; iVEl < _nNodEl[iEl]; iVEl++) {
      MVertex *vert = _el[iEl]->getVertex(iVEl);
      GEntity *ge = vert->onWhat();
      const int vDim = ge->dim();
      const bool hasParam = ge->haveParametrization();
      int iV = addVert(vert);
      _el2V[iEl].push_back(iV);
      if ((vDim > 0) && (toFix.find(vert) == toFix.end()) && (!fixBndNodes || vDim == _dim)) {   // Free vertex?
        VertexCoord *coord;
        if (vDim == 3) coord = new VertexCoordPhys3D();
        else if (hasParam) coord = new VertexCoordParent(vert);
        else {
          if (vDim == 2) coord = new VertexCoordLocalSurf(vert);
          else coord = new VertexCoordLocalLine(vert);
          nonGeoMove = true;
        }
        int iFV = addFreeVert(vert, iV, vDim, coord, toFix);
        _el2FV[iEl].push_back(iFV);
        for (int i=_startPCFV[iFV]; i<_startPCFV[iFV]+vDim; i++) _indPCEl[iEl].push_back(i);
      }
      else _el2FV[iEl].push_back(-1);
    }
  }

  if (nonGeoMove) Msg::Warning("Some vertices will be moved along local lines "
                            "or planes, they may not remain on the exact geometry");

  // Initial coordinates
  _ixyz.resize(nVert());
  for (int iV = 0; iV < nVert(); iV++) _ixyz[iV] = _vert[iV]->point();
  _iuvw.resize(nFV());
  for (int iFV = 0; iFV < nFV(); iFV++) _iuvw[iFV] = _coordFV[iFV]->getUvw(_freeVert[iFV]);

  // Set current coordinates
  _xyz = _ixyz;
  _uvw = _iuvw;
}


int Patch::addVert(MVertex* vert)
{
  std::vector<MVertex*>::iterator itVert = find(_vert.begin(),_vert.end(),vert);
  if (itVert == _vert.end()) {
    _vert.push_back(vert);
    return _vert.size()-1;
  }
  else return std::distance(_vert.begin(),itVert);

}


int Patch::addFreeVert(MVertex* vert, const int iV, const int nPCV,
                      VertexCoord *param, std::set<MVertex*> &toFix)
{
  std::vector<MVertex*>::iterator itVert = find(_freeVert.begin(),
                                                _freeVert.end(),vert);
  if (itVert == _freeVert.end()) {
    const int iStart = (_startPCFV.size() == 0)? 0 : _startPCFV.back()+_nPCFV.back();
    const bool forcedV = (vert->onWhat()->dim() < 2) || (toFix.find(vert) != toFix.end());
    _freeVert.push_back(vert);
    _coordFV.push_back(param);
    _fv2V.push_back(iV);
    _startPCFV.push_back(iStart);
    _nPCFV.push_back(nPCV);
    _nPC += nPCV;
    _forced.push_back(forcedV);
    return _freeVert.size()-1;
  }
  else return std::distance(_freeVert.begin(),itVert);

}


void Patch::getUvw(double *it)
{
  for (int iFV = 0; iFV < nFV(); iFV++) {
    SPoint3 &uvwV = _uvw[iFV];
    *it = uvwV[0]; it++;
    if (_nPCFV[iFV] >= 2) { *it = uvwV[1]; it++; }
    if (_nPCFV[iFV] == 3) { *it = uvwV[2]; it++; }
  }

}


void Patch::updateMesh(const double *it)
{
  for (int iFV = 0; iFV < nFV(); iFV++) {
    int iV = _fv2V[iFV];
    SPoint3 &uvwV = _uvw[iFV];
    uvwV[0] = *it; it++;
    if (_nPCFV[iFV] >= 2) { uvwV[1] = *it; it++; }
    if (_nPCFV[iFV] == 3) { uvwV[2] = *it; it++; }
    _xyz[iV] = _coordFV[iFV]->uvw2Xyz(uvwV);
  }

}


void Patch::updateGEntityPositions()
{
  for (int iV = 0; iV < nVert(); iV++)
    _vert[iV]->setXYZ(_xyz[iV].x(),_xyz[iV].y(),_xyz[iV].z());
  for (int iFV = 0; iFV < nFV(); iFV++)
    _coordFV[iFV]->exportVertexCoord(_uvw[iFV]);
}


void Patch::pcScale(int iFV, std::vector<double> &scale)
{
  // Calc. derivative of x, y & z w.r.t. parametric coordinates
  const SPoint3 dX(1.,0.,0.), dY(0.,1.,0.), dZ(0.,0.,1.);
  SPoint3 gX, gY, gZ;
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV],dX,gX);
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV],dY,gY);
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV],dZ,gZ);

  // Scale = inverse norm. of vector (dx/du, dy/du, dz/du)
  scale[0] = 1./sqrt(gX[0]*gX[0]+gY[0]*gY[0]+gZ[0]*gZ[0]);
  if (_nPCFV[iFV] >= 2) scale[1] = 1./sqrt(gX[1]*gX[1]+gY[1]*gY[1]+gZ[1]*gZ[1]);
  if (_nPCFV[iFV] == 3) scale[2] = 1./sqrt(gX[2]*gX[2]+gY[2]*gY[2]+gZ[2]*gZ[2]);
}


void Patch::writeMSH(const char *filename)
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


void Patch::initScaledNodeDispSq(LengthScaling scaling)
{
  if ((_invLengthScaleSq == 0.) || _typeLengthScale != scaling) {
    _typeLengthScale = scaling;
    double maxDSq = 0.;
    switch(scaling) {
      case LS_MAXNODEDIST : {
        for (int iEl = 0; iEl < nEl(); iEl++) {
          const double d = el(iEl)->maxDistToStraight(), dd = d*d;
          if (dd > maxDSq) maxDSq = dd;
        }
        break;
      }
      case LS_MAXOUTERRADIUS : {
        for (int iEl = 0; iEl < nEl(); iEl++) {
          const double d = el(iEl)->getOuterRadius(), dd = d*d;
          if (dd > maxDSq) maxDSq = dd;
        }
        break;
      }
      case LS_MINEDGELENGTH : {
        for (int iEl = 0; iEl < nEl(); iEl++) {
          const double d = el(iEl)->minEdge(), dd = d*d;
          if (dd > maxDSq) maxDSq = dd;
        }
        break;
      }
    }
    _invLengthScaleSq = 1./maxDSq;
  }
}


double Patch::scaledNodeDispSq(int iFV)
{
  const int &iV = _fv2V[iFV];
  const SPoint3 d = _xyz[iV]-_ixyz[iV];
  return (d[0]*d[0]+d[1]*d[1]+d[2]*d[2])*_invLengthScaleSq;
}


void Patch::gradScaledNodeDispSq(int iFV, std::vector<double> &gDSq)
{
  const int &iV = _fv2V[iFV];
  const SPoint3 gXyz = (_xyz[iV]-_ixyz[iV])*2.*_invLengthScaleSq;
  SPoint3 gUvw;
  gXyz2gUvw(iFV, gXyz, gUvw);

  gDSq[0] = gUvw[0];
  if (_nPCFV[iFV] >= 2) gDSq[1] = gUvw[1];
  if (_nPCFV[iFV] == 3) gDSq[2] = gUvw[2];
}


void Patch::initScaledJac()
{
  // Initialize _nBezEl
  if (_nBezEl.empty()) {
    _nBezEl.resize(nEl());
    for (int iEl=0; iEl<nEl(); iEl++)
     _nBezEl[iEl] = _el[iEl]->getJacobianFuncSpace()->getNumJacNodes();
  }

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
  // Jacobians of 3D elements
  if ((_dim == 2) && _JacNormEl.empty()) {
    _JacNormEl.resize(nEl());
//    for (int iEl = 0; iEl < nEl(); iEl++) calcScaledNormalEl2D(element2entity,iEl);
    for (int iEl = 0; iEl < nEl(); iEl++)
      calcNormalEl2D(iEl, NS_INVNORM, _JacNormEl[iEl], false);
  }
  else if (_invStraightJac.empty()) {
    _invStraightJac.resize(nEl(), 1.);
    double dumJac[3][3];
    for (int iEl = 0; iEl < nEl(); iEl++)
      _invStraightJac[iEl] = 1. / fabs(_el[iEl]->getPrimaryJacobian(0.,0.,0.,dumJac));
  }
}


void Patch::initMetricMin()
{
  // Initialize _nBezEl
  if (_nBezEl.empty()) {
    _nBezEl.resize(nEl());
    for (int iEl=0; iEl<nEl(); iEl++)
     _nBezEl[iEl] = _el[iEl]->getJacobianFuncSpace()->getNumJacNodes();
  }
}


// TODO: Re-introduce normal to geometry?
//void Mesh::calcScaledNormalEl2D(const std::map<MElement*,GEntity*> &element2entity, int iEl)
void Patch::calcNormalEl2D(int iEl, NormalScaling scaling,
                           fullMatrix<double> &elNorm, bool ideal)
{
  const JacobianBasis *jac = _el[iEl]->getJacobianFuncSpace();

  fullMatrix<double> primNodesXYZ(jac->getNumPrimMapNodes(),3);
//  SVector3 geoNorm(0.,0.,0.);
//  std::map<MElement*,GEntity*>::const_iterator itEl2ent = element2entity.find(_el[iEl]);
//  GEntity *ge = (itEl2ent == element2entity.end()) ? 0 : itEl2ent->second;
//  const bool hasGeoNorm = ge && (ge->dim() == 2) && ge->haveParametrization();
  for (int i=0; i<jac->getNumPrimMapNodes(); i++) {
    const int &iV = _el2V[iEl][i];
    primNodesXYZ(i, 0) = _xyz[iV].x();
    primNodesXYZ(i, 1) = _xyz[iV].y();
    primNodesXYZ(i, 2) = _xyz[iV].z();
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

  elNorm.resize(1, 3);
  const double norm = jac->getPrimNormal2D(primNodesXYZ, elNorm, ideal);
  double factor;
  switch (scaling) {
    case NS_UNIT:
      factor = 1.;
      break;
    case NS_INVNORM:
      factor = 1./norm;
      break;
    case NS_SQRTNORM:
      factor = sqrt(norm);
      break;
  }
//  if (hasGeoNorm) {
//    const double scal = geoNorm(0)*elNorm(0,0)+geoNorm(1)*elNorm(0,1)+geoNorm(2)*elNorm(0,2);
//    if (scal < 0.) factor = -factor;
//  }
  elNorm.scale(factor);   // Re-scaling normal here is faster than an extra scaling operation on the Jacobian
}


void Patch::scaledJacAndGradients(int iEl, std::vector<double> &sJ,
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
  jacBasis->getSignedJacAndGradients(nodesXYZ,_JacNormEl[iEl],JDJ);
  if (_dim == 3) JDJ.scale(_invStraightJac[iEl]);

  // Transform Jacobian and gradients from Lagrangian to Bezier basis
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
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gSJ[indGSJ(iEl,l,iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gSJ[indGSJ(iEl,l,iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gSJ[indGSJ(iEl,l,iPC+2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}


void Patch::metricMinAndGradients(int iEl, std::vector<double> &lambda,
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
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gradLambda[indGSJ(iEl,l,iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gradLambda[indGSJ(iEl,l,iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gradLambda[indGSJ(iEl,l,iPC+2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}


bool Patch::bndDistAndGradients(int iEl, double &f, std::vector<double> &gradF, double eps)
{
  MElement *element = _el[iEl];
  f = 0.;
  // dommage ;-)
  if (element->getDim() != 2)
    return false;

  int currentId = 0;
  std::vector<int> vertex2param(element->getNumVertices());
  for (size_t i = 0; i < element->getNumVertices(); ++i) {
    if (_el2FV[iEl][i] >= 0) {
      vertex2param[i] = currentId;
      currentId += _nPCFV[_el2FV[iEl][i]];
    }
    else
      vertex2param[i] = -1;
  }
  gradF.clear();
  gradF.resize(currentId, 0.);

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
      f += computeBndDistAndGradient(edge, params, vertices,
            *BasisFactory::getNodalBasis(elbasis.getClosureType(clId)), nodes, onedge, localgrad, eps);
      for (size_t i = 0; i < closure.size(); ++i)
        if (onedge[i]) gradF[vertex2param[closure[i]]] += localgrad[i];
    }
  }
  return edgeFound;
}


void Patch::initIdealJac()
{
  // Initialize _nBezEl
  if (_nIJacEl.empty()) {
    _nIJacEl.resize(nEl());
    for (int iEl=0; iEl<nEl(); iEl++)
      _nIJacEl[iEl] = _el[iEl]->getJacobianFuncSpace()->getNumJacNodes();
  }

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
  // Jacobians of 3D elements
  if ((_dim == 2) && _IJacNormEl.empty()) {
    _IJacNormEl.resize(nEl());
//    for (int iEl = 0; iEl < nEl(); iEl++) calcScaledNormalEl2D(element2entity,iEl);
    for (int iEl = 0; iEl < nEl(); iEl++)
      calcNormalEl2D(iEl, NS_INVNORM, _IJacNormEl[iEl], true);
  }
  else if (_invStraightJac.empty()) {
    _invIJac.resize(nEl(), 1.);
    for (int iEl = 0; iEl < nEl(); iEl++) {
      int nEd = _el[iEl]->getNumEdges();
      double sumEdLength = 0.;
      for(int iEd = 0; iEd < nEd; iEd++)
        sumEdLength += _el[iEl]->getEdge(iEd).length();
      const double invMeanEdLength = double(nEd)/sumEdLength;
      _invIJac[iEl] = invMeanEdLength*invMeanEdLength*invMeanEdLength;
    }
  }
}


void Patch::idealJacAndGradients(int iEl, std::vector<double> &iJ, std::vector<double> &gIJ)
{
  const JacobianBasis *jacBasis = _el[iEl]->getJacobianFuncSpace();
  const int &numJacNodes = _nIJacEl[iEl];
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
  jacBasis->getSignedIdealJacAndGradients(nodesXYZ,_IJacNormEl[iEl],JDJ);
  if (_dim == 3) JDJ.scale(_invIJac[iEl]);
//  if (_el[iEl]->getNum() == 90370) {
//    std::cout << "DBGTT: bad el.: " << _el[iEl]->getNum() << "\n";
//    for (int i = 0; i < numMapNodes; i++)
//      std::cout << "DBGTT: {x,y,z}" << i << " = (" << nodesXYZ(i,0)
//                << ", " << nodesXYZ(i,1) << ", " << nodesXYZ(i,2) << ")\n";
//   for (int l = 0; l < numJacNodes; l++) {
//      for (int i = 0; i < numMapNodes; i++)
//        std::cout << "DBGTT: dJ" << l << "d{x,y,z}" << i << " = (" << JDJ(l, i)
//                  << ", " << JDJ(l, i+numMapNodes) << ", " << JDJ(l, i+2*numMapNodes)<< ")\n";
//      std::cout << "DBGTT: J" << l << " = " << JDJ(l, 3*numMapNodes)<< "\n";
//    }
//  }

  // Transform Jacobian and gradients from Lagrangian to Bezier basis
  jacBasis->lag2Bez(JDJ,BDB);

  // Scaled jacobian
  for (int l = 0; l < numJacNodes; l++) iJ [l] = BDB (l,3*numMapNodes);

  // Gradients of the scaled jacobian
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numJacNodes);
  std::vector<SPoint3> gUvwV(numJacNodes);
  for (int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if (iFVi >= 0) {
      for (int l = 0; l < numJacNodes; l++)
        gXyzV [l] = SPoint3(BDB(l,i), BDB(l,i+numMapNodes), BDB(l,i+2*numMapNodes));
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi],gXyzV,gUvwV);
      for (int l = 0; l < numJacNodes; l++) {
        gIJ[indGIJac(iEl,l,iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gIJ[indGIJac(iEl,l,iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gIJ[indGIJac(iEl,l,iPC+2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}


void Patch::initInvCondNum()
{
  // Initialize _nBezEl
  if (_nICNEl.empty()) {
    _nICNEl.resize(nEl());
    for (int iEl=0; iEl<nEl(); iEl++) {
      const CondNumBasis *cnBasis = BasisFactory::getCondNumBasis(_el[iEl]->getTypeForMSH());
      _nICNEl[iEl] = cnBasis->getNumCondNumNodes();
    }
  }

//  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
//  // Jacobians of 3D elements
//  if ((_dim == 2) && _condNormEl.empty()) {
//    _condNormEl.resize(nEl());
////    for (int iEl = 0; iEl < nEl(); iEl++) calcScaledNormalEl2D(element2entity,iEl);
//    for (int iEl = 0; iEl < nEl(); iEl++)
//      calcNormalEl2D(iEl, NS_SQRTNORM, _condNormEl[iEl], true);
//  }
}


void Patch::invCondNumAndGradients(int iEl, std::vector<double> &condNum,
                                std::vector<double> &gCondNum)
{
  const CondNumBasis *cnBasis = BasisFactory::getCondNumBasis(_el[iEl]->getTypeForMSH());
  const int &numICN = _nICNEl[iEl];
  const int &numMapNodes = _nNodEl[iEl];
  fullMatrix<double> IDI(numICN, 3*numMapNodes+1);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes,3), normals;
  for (int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i,0) = _xyz[iVi].x();
    nodesXYZ(i,1) = _xyz[iVi].y();
    nodesXYZ(i,2) = _xyz[iVi].z();
  }

  // Calculate ICN and gradients
  // TODO: Use signed measure for 2D as well
  if (_dim == 3) {
    cnBasis->getSignedInvCondNumAndGradients(nodesXYZ, normals, IDI);
  }
  else
    cnBasis->getInvCondNumAndGradients(nodesXYZ, IDI);

  // Inverse condition number
  for (int l = 0; l < numICN; l++) condNum[l] = IDI(l, 3*numMapNodes);

  // Gradients of the inverse condition number
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numICN);
  std::vector<SPoint3> gUvwV(numICN);
  for (int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if (iFVi >= 0) {
      for (int l = 0; l < numICN; l++)
        gXyzV[l] = SPoint3(IDI(l, i), IDI(l, i+numMapNodes),
                            IDI(l, i+2*numMapNodes));
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi], gXyzV, gUvwV);
      for (int l = 0; l < numICN; l++) {
        gCondNum[indGICN(iEl, l, iPC)] = gUvwV[l][0];
        if (_nPCFV[iFVi] >= 2) gCondNum[indGICN(iEl, l, iPC+1)] = gUvwV[l][1];
        if (_nPCFV[iFVi] == 3) gCondNum[indGICN(iEl, l, iPC+2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}
