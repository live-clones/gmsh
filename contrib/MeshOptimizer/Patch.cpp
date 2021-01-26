// MeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include "GmshMessage.h"
#include "GFace.h"
#include "BasisFactory.h"
#include "CondNumBasis.h"
#include "IntegralBoundaryDist.h"
#include "CADDistances.h"
#include "qualityMeasures.h"
#include "Patch.h"
#include "bezierBasis.h"
#include "nodalBasis.h"

Patch::Patch(const std::map<MElement *, GEntity *> &element2entity,
             const std::map<MElement *, GEntity *> &bndEl2Ent,
             const std::set<MElement *> &els, std::set<MVertex *> &toFix,
             const std::set<MElement *> &bndEls, bool fixBndNodes)
  : _typeLengthScale(LS_NONE), _invLengthScaleSq(0.)
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
  if(!element2entity.empty()) _gEnt.resize(nElements);
  int iEl = 0;
  bool nonGeoMove = false;
  for(auto it = els.begin(); it != els.end(); ++it, ++iEl) {
    _el[iEl] = *it;
    if(!element2entity.empty()) {
      auto itEl2Ent = element2entity.find(*it);
      _gEnt[iEl] = (itEl2Ent == element2entity.end()) ? 0 : itEl2Ent->second;
    }
    _nNodEl[iEl] = _el[iEl]->getNumVertices();
    for(int iVEl = 0; iVEl < _nNodEl[iEl]; iVEl++) {
      MVertex *vert = _el[iEl]->getVertex(iVEl);
      GEntity *ge = vert->onWhat();
      const int vDim = ge->dim();
      const bool hasParam = ge->haveParametrization();
      int iV = addVert(vert);
      _el2V[iEl].push_back(iV);
      if((vDim > 0) && (toFix.find(vert) == toFix.end()) &&
         (!fixBndNodes || vDim == _dim)) { // Free vertex?
        VertexCoord *coord;
        if(vDim == 3)
          coord = new VertexCoordPhys3D();
        else if(hasParam)
          coord = new VertexCoordParent(vert);
        else {
          if(vDim == 2)
            coord = new VertexCoordLocalSurf(vert);
          else
            coord = new VertexCoordLocalLine(vert);
          nonGeoMove = true;
        }
        int iFV = addFreeVert(vert, iV, vDim, coord, toFix);
        _el2FV[iEl].push_back(iFV);
        for(int i = _startPCFV[iFV]; i < _startPCFV[iFV] + vDim; i++)
          _indPCEl[iEl].push_back(i);
      }
      else
        _el2FV[iEl].push_back(-1);
    }
  }

  if(nonGeoMove)
    Msg::Warning("Some nodes will be moved along local lines "
                 "or planes, they may not remain on the exact geometry");

  // Initialize boundary elements and related connectivity if required
  if(!bndEls.empty()) {
    int nBndElts = bndEls.size();
    _bndEl.resize(nBndElts);
    _bndEl2Ent.resize(nBndElts);
    _bndEl2V.resize(nBndElts);
    _bndEl2FV.resize(nBndElts);
    int iBndEl = 0;
    bool unknownVert = false;
    for(auto it = bndEls.begin(); it != bndEls.end(); ++it, ++iBndEl) {
      MElement *bndEl = *it;
      _bndEl[iBndEl] = bndEl;
      auto itBndEl2Ent = bndEl2Ent.find(bndEl);
      _bndEl2Ent[iBndEl] =
        (itBndEl2Ent == bndEl2Ent.end()) ? 0 : itBndEl2Ent->second;
      int nBndElVerts = bndEl->getNumVertices();
      _bndEl2V[iBndEl].resize(nBndElVerts);
      _bndEl2FV[iBndEl].resize(nBndElVerts);
      for(int iVBndEl = 0; iVBndEl < nBndElVerts; iVBndEl++) {
        MVertex *vert = bndEl->getVertex(iVBndEl);
        auto itV = std::find(_vert.begin(), _vert.end(), vert);
        if(itV == _vert.end())
          unknownVert = true;
        else
          _bndEl2V[iBndEl][iVBndEl] = std::distance(_vert.begin(), itV);
        auto itFV = std::find(_freeVert.begin(), _freeVert.end(), vert);
        if(itFV == _freeVert.end())
          _bndEl2FV[iBndEl][iVBndEl] = -1;
        else
          _bndEl2FV[iBndEl][iVBndEl] = std::distance(_freeVert.begin(), itFV);
      }
    }
    if(unknownVert)
      Msg::Error("Unknown nodes in boundary element at patch initialization");
  }

  // Initial coordinates
  _ixyz.resize(nVert());
  for(int iV = 0; iV < nVert(); iV++) _ixyz[iV] = _vert[iV]->point();
  _iuvw.resize(nFV());
  for(int iFV = 0; iFV < nFV(); iFV++)
    _iuvw[iFV] = _coordFV[iFV]->getUvw(_freeVert[iFV]);

  // Set current coordinates
  _xyz = _ixyz;
  _uvw = _iuvw;
}

int Patch::addVert(MVertex *vert)
{
  auto itVert = find(_vert.begin(), _vert.end(), vert);
  if(itVert == _vert.end()) {
    _vert.push_back(vert);
    return _vert.size() - 1;
  }
  else
    return std::distance(_vert.begin(), itVert);
}

int Patch::addFreeVert(MVertex *vert, const int iV, const int nPCV,
                       VertexCoord *param, std::set<MVertex *> &toFix)
{
  auto itVert = find(_freeVert.begin(), _freeVert.end(), vert);
  if(itVert == _freeVert.end()) {
    const int iStart =
      (_startPCFV.size() == 0) ? 0 : _startPCFV.back() + _nPCFV.back();
    const bool forcedV =
      (vert->onWhat()->dim() < 2) || (toFix.find(vert) != toFix.end());
    _freeVert.push_back(vert);
    _coordFV.push_back(param);
    _fv2V.push_back(iV);
    _startPCFV.push_back(iStart);
    _nPCFV.push_back(nPCV);
    _nPC += nPCV;
    return _freeVert.size() - 1;
  }
  else
    return std::distance(_freeVert.begin(), itVert);
}

void Patch::getUvw(double *it)
{
  for(int iFV = 0; iFV < nFV(); iFV++) {
    SPoint3 &uvwV = _uvw[iFV];
    *it = uvwV[0];
    it++;
    if(_nPCFV[iFV] >= 2) {
      *it = uvwV[1];
      it++;
    }
    if(_nPCFV[iFV] == 3) {
      *it = uvwV[2];
      it++;
    }
  }
}

void Patch::updateMesh(const double *it)
{
  for(int iFV = 0; iFV < nFV(); iFV++) {
    int iV = _fv2V[iFV];
    SPoint3 &uvwV = _uvw[iFV];
    uvwV[0] = *it;
    it++;
    if(_nPCFV[iFV] >= 2) {
      uvwV[1] = *it;
      it++;
    }
    if(_nPCFV[iFV] == 3) {
      uvwV[2] = *it;
      it++;
    }
    _xyz[iV] = _coordFV[iFV]->uvw2Xyz(uvwV);
  }
}

void Patch::updateGEntityPositions()
{
  for(int iV = 0; iV < nVert(); iV++)
    _vert[iV]->setXYZ(_xyz[iV].x(), _xyz[iV].y(), _xyz[iV].z());
  for(int iFV = 0; iFV < nFV(); iFV++)
    _coordFV[iFV]->exportVertexCoord(_uvw[iFV]);
}

void Patch::pcScale(int iFV, std::vector<double> &scale)
{
  // Calc. derivative of x, y & z w.r.t. parametric coordinates
  const SPoint3 dX(1., 0., 0.), dY(0., 1., 0.), dZ(0., 0., 1.);
  SPoint3 gX, gY, gZ;
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV], dX, gX);
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV], dY, gY);
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV], dZ, gZ);

  // Scale = inverse norm. of vector (dx/du, dy/du, dz/du)
  scale[0] = 1. / sqrt(gX[0] * gX[0] + gY[0] * gY[0] + gZ[0] * gZ[0]);
  if(_nPCFV[iFV] >= 2)
    scale[1] = 1. / sqrt(gX[1] * gX[1] + gY[1] * gY[1] + gZ[1] * gZ[1]);
  if(_nPCFV[iFV] == 3)
    scale[2] = 1. / sqrt(gX[2] * gX[2] + gY[2] * gY[2] + gZ[2] * gZ[2]);
}

void Patch::writeMSH(const char *filename)
{
  FILE *f = fopen(filename, "w");

  fprintf(f, "$MeshFormat\n");
  fprintf(f, "2.2 0 8\n");
  fprintf(f, "$EndMeshFormat\n");

  fprintf(f, "$Nodes\n");
  fprintf(f, "%d\n", nVert());
  for(int i = 0; i < nVert(); i++)
    fprintf(f, "%d %22.15E %22.15E %22.15E\n", i + 1, _xyz[i].x(), _xyz[i].y(),
            _xyz[i].z());
  fprintf(f, "$EndNodes\n");

  fprintf(f, "$Elements\n");
  fprintf(f, "%d\n", nEl());
  for(int iEl = 0; iEl < nEl(); iEl++) {
    fprintf(f, "%d %d 2 0 0", _el[iEl]->getNum(), _el[iEl]->getTypeForMSH());
    for(size_t iVEl = 0; iVEl < _el2V[iEl].size(); iVEl++)
      fprintf(f, " %d", _el2V[iEl][iVEl] + 1);
    fprintf(f, "\n");
  }
  fprintf(f, "$EndElements\n");

  fclose(f);
}

void Patch::initScaledNodeDispSq(LengthScaling scaling)
{
  if((_invLengthScaleSq == 0.) || _typeLengthScale != scaling) {
    _typeLengthScale = scaling;
    double maxDSq = 0.;
    switch(scaling) {
    case LS_MAXNODEDIST: {
      for(int iEl = 0; iEl < nEl(); iEl++) {
        const double d = _el[iEl]->maxDistToStraight(), dd = d * d;
        if(dd > maxDSq) maxDSq = dd;
      }
      break;
    }
    case LS_MAXOUTERRADIUS: {
      for(int iEl = 0; iEl < nEl(); iEl++) {
        const double d = _el[iEl]->getOuterRadius(), dd = d * d;
        if(dd > maxDSq) maxDSq = dd;
      }
      break;
    }
    case LS_MINEDGELENGTH: {
      for(int iEl = 0; iEl < nEl(); iEl++) {
        const double d = _el[iEl]->minEdge(), dd = d * d;
        if(dd > maxDSq) maxDSq = dd;
      }
      break;
    }
    }
    _invLengthScaleSq = 1. / maxDSq;
  }
}

double Patch::scaledNodeDispSq(int iFV)
{
  const int &iV = _fv2V[iFV];
  const SPoint3 d = _xyz[iV] - _ixyz[iV];
  return (d[0] * d[0] + d[1] * d[1] + d[2] * d[2]) * _invLengthScaleSq;
}

void Patch::gradScaledNodeDispSq(int iFV, std::vector<double> &gDSq)
{
  const int &iV = _fv2V[iFV];
  const SPoint3 gXyz = (_xyz[iV] - _ixyz[iV]) * 2. * _invLengthScaleSq;
  SPoint3 gUvw;
  gXyz2gUvw(iFV, gXyz, gUvw);

  gDSq[0] = gUvw[0];
  if(_nPCFV[iFV] >= 2) gDSq[1] = gUvw[1];
  if(_nPCFV[iFV] == 3) gDSq[2] = gUvw[2];
}

void Patch::initScaledJac()
{
  // Initialize _nBezEl
  if(_nBezEl.empty()) {
    _nBezEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++)
      _nBezEl[iEl] = _el[iEl]->getJacobianFuncSpace()->getNumSamplingPnts();
  }

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
  // Jacobians of 3D elements
  if((_dim == 2) && _jacNormEl.empty()) {
    _jacNormEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++)
      calcNormalEl2D(iEl, NS_INVNORM, _jacNormEl[iEl], false);
  }
  else if(_invStraightJac.empty()) {
    _invStraightJac.resize(nEl(), 1.);
    double dumJac[3][3];
    for(int iEl = 0; iEl < nEl(); iEl++)
      _invStraightJac[iEl] =
        1. / fabs(_el[iEl]->getPrimaryJacobian(0., 0., 0., dumJac));
  }
}

void Patch::initMetricMin()
{
  // Initialize _nBezEl
  if(_nBezEl.empty()) {
    _nBezEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++)
      _nBezEl[iEl] = _el[iEl]->getJacobianFuncSpace()->getNumSamplingPnts();
  }
}

void Patch::initScaledCADDistSq(double refCADDist)
{
  _invRefCADDistSq = 1. / (refCADDist * refCADDist);
}

void Patch::calcNormalEl2D(int iEl, NormalScaling scaling,
                           fullMatrix<double> &elNorm, bool ideal)
{
  const JacobianBasis *jac = _el[iEl]->getJacobianFuncSpace();

  fullMatrix<double> primNodesXYZ(jac->getNumPrimMapNodes(), 3);
  SVector3 geoNorm(0., 0., 0.);
  GEntity *ge = (_gEnt.empty()) ? nullptr : _gEnt[iEl];
  const bool hasGeoNorm = ge && (ge->dim() == 2) && ge->haveParametrization();
  for(int i = 0; i < jac->getNumPrimMapNodes(); i++) {
    const int &iV = _el2V[iEl][i];
    primNodesXYZ(i, 0) = _xyz[iV].x();
    primNodesXYZ(i, 1) = _xyz[iV].y();
    primNodesXYZ(i, 2) = _xyz[iV].z();
    if(hasGeoNorm && (_vert[iV]->onWhat() == ge)) {
      double u, v;
      _vert[iV]->getParameter(0, u);
      _vert[iV]->getParameter(1, v);
      geoNorm += ((GFace *)ge)->normal(SPoint2(u, v));
    }
  }
  if(hasGeoNorm && (geoNorm.normSq() == 0.)) {
    SPoint2 param =
      ((GFace *)ge)->parFromPoint(_el[iEl]->barycenter(true), false);
    geoNorm = ((GFace *)ge)->normal(param);
  }

  elNorm.resize(1, 3);
  const double norm = jac->getPrimNormal2D(primNodesXYZ, elNorm, ideal);
  double factor;
  switch(scaling) {
  case NS_UNIT: factor = 1.; break;
  case NS_INVNORM: factor = 1. / norm; break;
  case NS_SQRTNORM: factor = sqrt(norm); break;
  }
  if(hasGeoNorm) {
    const double scal = geoNorm(0) * elNorm(0, 0) + geoNorm(1) * elNorm(0, 1) +
                        geoNorm(2) * elNorm(0, 2);
    if(scal < 0.) factor = -factor;
  }
  elNorm.scale(factor); // Re-scaling normal here is faster than an extra
                        // scaling operation on the Jacobian
}

void Patch::scaledJacAndGradients(int iEl, std::vector<double> &sJ,
                                  std::vector<double> &gSJ)
{
  const JacobianBasis *jacBasis = _el[iEl]->getJacobianFuncSpace();
  const int &numSamplingPnts = _nBezEl[iEl];
  const int &numMapNodes = _nNodEl[iEl];
  fullMatrix<double> JDJ(numSamplingPnts, 3 * numMapNodes + 1);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes, 3), normals(_dim, 3);
  for(int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i, 0) = _xyz[iVi].x();
    nodesXYZ(i, 1) = _xyz[iVi].y();
    nodesXYZ(i, 2) = _xyz[iVi].z();
  }

  // Calculate Jacobian and gradients, scale if 3D (already scaled by
  // regularization normals in 2D)
  jacBasis->getSignedJacAndGradients(nodesXYZ, _jacNormEl[iEl], JDJ);
  if(_dim == 3) JDJ.scale(_invStraightJac[iEl]);

  // Transform Jacobian and gradients from Lagrangian to Bezier basis
  bezierCoeff BDB(jacBasis->getFuncSpaceData(), JDJ);

  // Scaled jacobian
  for(int l = 0; l < numSamplingPnts; l++) sJ[l] = BDB(l, 3 * numMapNodes);

  // Gradients of the scaled jacobian
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numSamplingPnts);
  std::vector<SPoint3> gUvwV(numSamplingPnts);
  for(int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if(iFVi >= 0) {
      for(int l = 0; l < numSamplingPnts; l++)
        gXyzV[l] =
          SPoint3(BDB(l, i + 0 * numMapNodes), BDB(l, i + 1 * numMapNodes),
                  BDB(l, i + 2 * numMapNodes));
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi], gXyzV, gUvwV);
      for(int l = 0; l < numSamplingPnts; l++) {
        gSJ[indGSJ(iEl, l, iPC)] = gUvwV[l][0];
        if(_nPCFV[iFVi] >= 2) gSJ[indGSJ(iEl, l, iPC + 1)] = gUvwV[l][1];
        if(_nPCFV[iFVi] == 3) gSJ[indGSJ(iEl, l, iPC + 2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}

void Patch::metricMinAndGradients(int iEl, std::vector<double> &lambda,
                                  std::vector<double> &gradLambda)
{
  const JacobianBasis *jacBasis = _el[iEl]->getJacobianFuncSpace();
  const int &numSamplingPnts = jacBasis->getNumSamplingPnts();
  const int &numMapNodes = jacBasis->getNumMapNodes();
  const int &numPrimMapNodes = jacBasis->getNumPrimMapNodes();
  fullVector<double> lambdaJ(numSamplingPnts), lambdaB(numSamplingPnts);
  fullMatrix<double> gradLambdaJ(numSamplingPnts, 2 * numMapNodes);
  fullMatrix<double> gradLambdaB(numSamplingPnts, 2 * numMapNodes);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes, 3),
    nodesXYZStraight(numPrimMapNodes, 3);
  for(int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i, 0) = _xyz[iVi].x();
    nodesXYZ(i, 1) = _xyz[iVi].y();
    nodesXYZ(i, 2) = _xyz[iVi].z();
    if(i < numPrimMapNodes) {
      nodesXYZStraight(i, 0) = _ixyz[iVi].x();
      nodesXYZStraight(i, 1) = _ixyz[iVi].y();
      nodesXYZStraight(i, 2) = _ixyz[iVi].z();
    }
  }

  jacBasis->getMetricMinAndGradients(nodesXYZ, nodesXYZStraight, lambdaJ,
                                     gradLambdaJ);

  // l2b.mult(lambdaJ, lambdaB);
  // l2b.mult(gradLambdaJ, gradLambdaB);
  lambdaB = lambdaJ;
  gradLambdaB = gradLambdaJ;

  int iPC = 0;
  std::vector<SPoint3> gXyzV(numSamplingPnts);
  std::vector<SPoint3> gUvwV(numSamplingPnts);
  for(int l = 0; l < numSamplingPnts; l++) { lambda[l] = lambdaB(l); }
  for(int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if(iFVi >= 0) {
      for(int l = 0; l < numSamplingPnts; l++) {
        gXyzV[l] =
          SPoint3(gradLambdaB(l, i + 0 * numMapNodes),
                  gradLambdaB(l, i + 1 * numMapNodes), /*BDB(l,i+2*nbNod)*/ 0.);
      }
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi], gXyzV, gUvwV);
      for(int l = 0; l < numSamplingPnts; l++) {
        gradLambda[indGSJ(iEl, l, iPC)] = gUvwV[l][0];
        if(_nPCFV[iFVi] >= 2) gradLambda[indGSJ(iEl, l, iPC + 1)] = gUvwV[l][1];
        if(_nPCFV[iFVi] == 3) gradLambda[indGSJ(iEl, l, iPC + 2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}

bool Patch::bndDistAndGradients(int iEl, double &f, std::vector<double> &gradF,
                                double eps)
{
  MElement *element = _el[iEl];
  f = 0.;
  // dommage ;-)
  if(element->getDim() != 2) return false;

  int currentId = 0;
  std::vector<int> vertex2param(element->getNumVertices());
  for(size_t i = 0; i < element->getNumVertices(); ++i) {
    if(_el2FV[iEl][i] >= 0) {
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
  for(int iEdge = 0; iEdge < element->getNumEdges(); ++iEdge) {
    int clId = elbasis.getClosureId(iEdge, 1);
    const std::vector<int> &closure = elbasis.closures[clId];
    std::vector<MVertex *> vertices;
    GEdge *edge = nullptr;
    for(size_t i = 0; i < closure.size(); ++i) {
      MVertex *v = element->getVertex(closure[i]);
      vertices.push_back(v);
      // only valid in 2D
      if((int)i >= 2 && v->onWhat() && v->onWhat()->dim() == 1) {
        edge = v->onWhat()->cast2Edge();
      }
    }
    if(edge) {
      edgeFound = true;
      std::vector<double> localgrad;
      std::vector<SPoint3> nodes(closure.size());
      std::vector<double> params(closure.size());
      std::vector<bool> onedge(closure.size());
      for(size_t i = 0; i < closure.size(); ++i) {
        nodes[i] = _xyz[_el2V[iEl][closure[i]]];
        onedge[i] = element->getVertex(closure[i])->onWhat() == edge &&
                    _el2FV[iEl][closure[i]] >= 0;
        if(onedge[i]) { params[i] = _uvw[_el2FV[iEl][closure[i]]].x(); }
        else
          reparamMeshVertexOnEdge(element->getVertex(closure[i]), edge,
                                  params[i]);
      }
      f += computeBndDistAndGradient(
        edge, params, vertices,
        *BasisFactory::getNodalBasis(elbasis.getClosureType(clId)), nodes,
        onedge, localgrad, eps);
      for(size_t i = 0; i < closure.size(); ++i)
        if(onedge[i]) gradF[vertex2param[closure[i]]] += localgrad[i];
    }
  }
  return edgeFound;
}

void Patch::scaledCADDistSqAndGradients(int iBndEl, double &scaledDist,
                                        std::vector<double> &gradScaledDist)
{
  const std::vector<int> &iV = _bndEl2V[iBndEl], &iFV = _bndEl2FV[iBndEl];
  const int nV = iV.size();
  const GradientBasis *gb;
  const int tag = _bndEl[iBndEl]->getTypeForMSH();
  gb = BasisFactory::getGradientBasis(tag, FuncSpaceData(_bndEl[iBndEl]));

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(nV, 3);
  for(int i = 0; i < nV; i++) {
    const int &iVi = iV[i];
    nodesXYZ(i, 0) = _xyz[iVi].x();
    nodesXYZ(i, 1) = _xyz[iVi].y();
    nodesXYZ(i, 2) = _xyz[iVi].z();
  }

  // Compute distance and gradients (CAUTION: returns gradients w.r.t. vertices,
  // not free vertices)
  if(_dim == 2) { // 2D
    const GEdge *ge = _bndEl2Ent[iBndEl]->cast2Edge();
    const Range<double> parBounds = ge->parBounds(0);
    const double eps = 1.e-6 * (parBounds.high() - parBounds.low());
    std::vector<SVector3> tanCAD(nV);
    for(int i = 0; i < nV; i++) {
      const int &iVi = iV[i], &iFVi = iFV[i];
      MVertex *&vert = _vert[iVi];
      double tCAD;
      if(iFVi >= 0) // If free vertex, ...
        tCAD =
          _uvw[iFVi].x(); // ... get stored param. coord. (can be only line).
      else { // Otherwise, get param. coord. from CAD.
        if(ge->getBeginVertex() &&
           ge->getBeginVertex()->mesh_vertices[0] == vert)
          tCAD = parBounds.low();
        else if(ge->getEndVertex() &&
                ge->getEndVertex()->mesh_vertices[0] == vert)
          tCAD = parBounds.high();
        else
          tCAD = ge->parFromPoint(_xyz[iVi]);
      }
      tanCAD[i] = ge->firstDer(tCAD); // Compute tangent at vertex
      tanCAD[i].normalize(); // Normalize tangent
    }
    scaledDist = _invRefCADDistSq * taylorDistanceSq1D(gb, nodesXYZ, tanCAD);
    for(int i = 0; i < nV; i++) {
      const int &iFVi = iFV[i];
      if(iFVi < 0) continue; // Skip if not free vertex
      const double xS = nodesXYZ(i, 0), yS = nodesXYZ(i, 1),
                   zS = nodesXYZ(i, 2); // Save coord. of perturbed node for FD
      const SVector3 tanCADS =
        tanCAD[i]; // Save tangent to CAD at perturbed node
      const double tCAD =
        _uvw[iFVi].x() + eps; // New param. coord. of perturbed node
      GPoint gp = ge->point(tCAD); // New coord. of perturbed node
      nodesXYZ(i, 0) = gp.x();
      nodesXYZ(i, 1) = gp.y();
      nodesXYZ(i, 2) = gp.z();
      tanCAD[i] = ge->firstDer(tCAD); // New tangent to CAD at perturbed node
      tanCAD[i].normalize(); // Normalize new tangent
      const double sDistDiff =
        _invRefCADDistSq *
        taylorDistanceSq1D(gb, nodesXYZ,
                           tanCAD); // Compute distance with perturbed node
      gradScaledDist[i] = (sDistDiff - scaledDist) / eps; // Compute gradient
      nodesXYZ(i, 0) = xS;
      nodesXYZ(i, 1) = yS;
      nodesXYZ(i, 2) = zS; // Restore coord. of perturbed node
      tanCAD[i] = tanCADS; // Restore tan. to CAD at perturbed node
    }
  }
  else { // 3D
    const GFace *gf = _bndEl2Ent[iBndEl]->cast2Face();
    const Range<double> parBounds0 = gf->parBounds(0),
                        parBounds1 = gf->parBounds(1);
    const double eps0 = 1.e-6 * (parBounds0.high() - parBounds0.low());
    const double eps1 = 1.e-6 * (parBounds1.high() - parBounds1.low());
    std::vector<SVector3> normCAD(nV);
    for(int i = 0; i < nV; i++) {
      const int &iVi = iV[i], &iFVi = iFV[i];
      MVertex *&vert = _vert[iVi];
      SPoint2 pCAD;
      if(iFVi >= 0) { // If free vertex...
        if(vert->onWhat() == gf) // If on surface, ...
          pCAD = SPoint2(_uvw[iFVi].x(),
                         _uvw[iFVi].y()); // ... get stored param. coord.
        else { // Otherwise, reparametrize on surface
          const GEdge *ge = vert->onWhat()->cast2Edge();
          pCAD = ge->reparamOnFace(gf, _uvw[iFVi].x(), 1);
        }
      }
      else
        reparamMeshVertexOnFace(
          vert, gf, pCAD); // If not free vertex, reparametrize on surface
      normCAD[i] = gf->normal(pCAD); // Compute normal at vertex
      normCAD[i].normalize(); // Normalize normal
    }
    scaledDist = _invRefCADDistSq * taylorDistanceSq2D(gb, nodesXYZ, normCAD);
    //    std::cout << "DBGTT: bnd el. " << _bndEl[iBndEl]->getNum() << ":
    //    scaledDist = " << scaledDist << "\n";
    for(int i = 0; i < nV; i++) {
      const int &iVi = iV[i], &iFVi = iFV[i];
      if(iFVi < 0) continue; // Skip if not free vertex
      const double xS = nodesXYZ(i, 0), yS = nodesXYZ(i, 1),
                   zS = nodesXYZ(i, 2); // Save coord. of perturbed node for FD
      const SVector3 normCADS =
        normCAD[i]; // Save normal to CAD at perturbed node
      if(_nPCFV[iFVi] == 2) { // Vertex classified on surface, 2D gradient
        const SPoint2 pCAD0 = SPoint2(
          _uvw[iFVi].x() + eps0,
          _uvw[iFVi].y()); // New param. coord. of perturbed node in 1st dir.
        GPoint gp0 =
          gf->point(pCAD0); // New coord. of perturbed node in 1st dir.
        nodesXYZ(i, 0) = gp0.x();
        nodesXYZ(i, 1) = gp0.y();
        nodesXYZ(i, 2) = gp0.z();
        normCAD[i] =
          gf->normal(pCAD0); // New normal to CAD at perturbed node in 1st dir.
        normCAD[i].normalize(); // Normalize new normal
        const double sDistDiff0 =
          _invRefCADDistSq *
          taylorDistanceSq2D(
            gb, nodesXYZ,
            normCAD); // Compute distance with perturbed node in 1st dir.
        gradScaledDist[2 * i] =
          (sDistDiff0 - scaledDist) / eps0; // Compute gradient in 1st dir.
        const SPoint2 pCAD1 =
          SPoint2(_uvw[iFVi].x(),
                  _uvw[iFVi].y() +
                    eps1); // New param. coord. of perturbed node in 2nd dir.
        GPoint gp1 =
          gf->point(pCAD1); // New coord. of perturbed node in 2nd dir.
        nodesXYZ(i, 0) = gp1.x();
        nodesXYZ(i, 1) = gp1.y();
        nodesXYZ(i, 2) = gp1.z();
        normCAD[i] =
          gf->normal(pCAD1); // New normal to CAD at perturbed node in 2nd dir.
        normCAD[i].normalize(); // Normalize new normal
        double sDistDiff1 =
          _invRefCADDistSq *
          taylorDistanceSq2D(
            gb, nodesXYZ,
            normCAD); // Compute distance with perturbed node in 2nd dir.
        gradScaledDist[2 * i + 1] =
          (sDistDiff1 - scaledDist) / eps1; // Compute gradient in 2nd dir.
      }
      else if(_nPCFV[iFVi] == 1) { // Vertex classified on edge, 1D gradient
        MVertex *&vert = _vert[iVi];
        const GEdge *ge = vert->onWhat()->cast2Edge();
        const Range<double> parBounds = ge->parBounds(0);
        const double eps = 1.e-6 * (parBounds.high() - parBounds.low());
        const double tCAD =
          _uvw[iFVi].x() + eps; // New param. coord. of perturbed node
        GPoint gp = ge->point(tCAD); // New coord. of perturbed node
        nodesXYZ(i, 0) = gp.x();
        nodesXYZ(i, 1) = gp.y();
        nodesXYZ(i, 2) = gp.z();
        SPoint2 pCAD = gf->parFromPoint(
          SPoint3(gp.x(), gp.y(), gp.z()),
          true); // Get param. coord. of perturbed node in face from CAD
        normCAD[i] = gf->normal(pCAD); // New normal to CAD at perturbed node
        normCAD[i].normalize(); // Normalize new normal
        const double sDistDiff =
          _invRefCADDistSq *
          taylorDistanceSq2D(gb, nodesXYZ,
                             normCAD); // Compute distance with perturbed node
        gradScaledDist[2 * i] =
          (sDistDiff - scaledDist) / eps; // Compute gradient
      }
      else
        std::cout << "DBGTT: Inconsistent _nPCFV(iFVi), vert. "
                  << _vert[iVi]->getNum() << "\n";
      nodesXYZ(i, 0) = xS;
      nodesXYZ(i, 1) = yS;
      nodesXYZ(i, 2) = zS; // Restore coord. of perturbed node
      normCAD[i] = normCADS; // Restore tan. to CAD at perturbed node
    }
  }
}

void Patch::initIdealJac()
{
  // Initialize _nBezEl
  if(_nIJacEl.empty()) {
    _nIJacEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++)
      _nIJacEl[iEl] = _el[iEl]->getJacobianFuncSpace()->getNumSamplingPnts();
  }

  // Set normals to 2D elements (with magnitude of inverse Jacobian) or initial
  // Jacobians of 3D elements
  if((_dim == 2) && _IJacNormEl.empty()) {
    _IJacNormEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++)
      calcNormalEl2D(iEl, NS_INVNORM, _IJacNormEl[iEl], true);
  }
  else if(_invStraightJac.empty()) {
    _invIJac.resize(nEl(), 1.);
    for(int iEl = 0; iEl < nEl(); iEl++) {
      int nEd = _el[iEl]->getNumEdges();
      double sumEdLength = 0.;
      for(int iEd = 0; iEd < nEd; iEd++)
        sumEdLength += _el[iEl]->getEdge(iEd).length();
      const double invMeanEdLength = double(nEd) / sumEdLength;
      _invIJac[iEl] = invMeanEdLength * invMeanEdLength * invMeanEdLength;
    }
  }
}

void Patch::idealJacAndGradients(int iEl, std::vector<double> &iJ,
                                 std::vector<double> &gIJ)
{
  const JacobianBasis *jacBasis = _el[iEl]->getJacobianFuncSpace();
  const int &numSamplingPnts = _nIJacEl[iEl];
  const int &numMapNodes = _nNodEl[iEl];
  fullMatrix<double> JDJ(numSamplingPnts, 3 * numMapNodes + 1);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes, 3), normals(_dim, 3);
  for(int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i, 0) = _xyz[iVi].x();
    nodesXYZ(i, 1) = _xyz[iVi].y();
    nodesXYZ(i, 2) = _xyz[iVi].z();
  }

  // Calculate Jacobian and gradients, scale if 3D (already scaled by
  // regularization normals in 2D)
  jacBasis->getSignedIdealJacAndGradients(nodesXYZ, _IJacNormEl[iEl], JDJ);
  if(_dim == 3) JDJ.scale(_invIJac[iEl]);

  // Transform Jacobian and gradients from Lagrangian to Bezier basis
  bezierCoeff BDB(jacBasis->getFuncSpaceData(), JDJ);

  // Scaled jacobian
  for(int l = 0; l < numSamplingPnts; l++) iJ[l] = BDB(l, 3 * numMapNodes);

  // Gradients of the scaled jacobian
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numSamplingPnts);
  std::vector<SPoint3> gUvwV(numSamplingPnts);
  for(int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if(iFVi >= 0) {
      for(int l = 0; l < numSamplingPnts; l++)
        gXyzV[l] = SPoint3(BDB(l, i), BDB(l, i + numMapNodes),
                           BDB(l, i + 2 * numMapNodes));
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi], gXyzV, gUvwV);
      for(int l = 0; l < numSamplingPnts; l++) {
        gIJ[indGIJac(iEl, l, iPC)] = gUvwV[l][0];
        if(_nPCFV[iFVi] >= 2) gIJ[indGIJac(iEl, l, iPC + 1)] = gUvwV[l][1];
        if(_nPCFV[iFVi] == 3) gIJ[indGIJac(iEl, l, iPC + 2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}

void Patch::initInvCondNum()
{
  // Initialize _nBezEl
  if(_nICNEl.empty()) {
    _nICNEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++) {
      const CondNumBasis *cnBasis =
        BasisFactory::getCondNumBasis(_el[iEl]->getTypeForMSH());
      _nICNEl[iEl] = cnBasis->getNumCondNumNodes();
    }
  }

  // Set normals to 2D elements
  if((_dim == 2) && _condNormEl.empty()) {
    _condNormEl.resize(nEl());
    for(int iEl = 0; iEl < nEl(); iEl++)
      calcNormalEl2D(iEl, NS_UNIT, _condNormEl[iEl], true);
  }
}

void Patch::invCondNumAndGradients(int iEl, std::vector<double> &condNum,
                                   std::vector<double> &gCondNum)
{
  const CondNumBasis *cnBasis =
    BasisFactory::getCondNumBasis(_el[iEl]->getTypeForMSH());
  const int &numICN = _nICNEl[iEl];
  const int &numMapNodes = _nNodEl[iEl];
  fullMatrix<double> IDI(numICN, 3 * numMapNodes + 1);

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(numMapNodes, 3), normals;
  for(int i = 0; i < numMapNodes; i++) {
    int &iVi = _el2V[iEl][i];
    nodesXYZ(i, 0) = _xyz[iVi].x();
    nodesXYZ(i, 1) = _xyz[iVi].y();
    nodesXYZ(i, 2) = _xyz[iVi].z();
  }

  // Calculate ICN and gradients
  cnBasis->getSignedInvCondNumAndGradients(nodesXYZ, _condNormEl[iEl], IDI);

  // Inverse condition number
  for(int l = 0; l < numICN; l++) condNum[l] = IDI(l, 3 * numMapNodes);

  // Gradients of the inverse condition number
  int iPC = 0;
  std::vector<SPoint3> gXyzV(numICN);
  std::vector<SPoint3> gUvwV(numICN);
  for(int i = 0; i < numMapNodes; i++) {
    int &iFVi = _el2FV[iEl][i];
    if(iFVi >= 0) {
      for(int l = 0; l < numICN; l++)
        gXyzV[l] = SPoint3(IDI(l, i), IDI(l, i + numMapNodes),
                           IDI(l, i + 2 * numMapNodes));
      _coordFV[iFVi]->gXyz2gUvw(_uvw[iFVi], gXyzV, gUvwV);
      for(int l = 0; l < numICN; l++) {
        gCondNum[indGICN(iEl, l, iPC)] = gUvwV[l][0];
        if(_nPCFV[iFVi] >= 2) gCondNum[indGICN(iEl, l, iPC + 1)] = gUvwV[l][1];
        if(_nPCFV[iFVi] == 3) gCondNum[indGICN(iEl, l, iPC + 2)] = gUvwV[l][2];
      }
      iPC += _nPCFV[iFVi];
    }
  }
}
