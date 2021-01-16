// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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
// Contributor: Thomas Toulorge

#include <iostream>
#include <sstream>
#include "GmshMessage.h"
#include "GEdge.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "BasisFactory.h"
#include "nodalBasis.h"
#include "MetaEl.h"

std::map<int, MetaEl::metaInfoType> MetaEl::_metaInfo;

MetaEl::metaInfoType::metaInfoType(int type, int order)
{
  static const double TOL = 1e-10;
  typedef std::vector<int>::iterator VIntIter;

  // Get basic info on dimension, faces and vertices
  int iBaseFace = 0, iTopFace = 0, nbEdVert = 0, nbPrimTopVert = 0;
  int baseFaceType = 0;
  switch(type) {
  case TYPE_QUA:
    dim = 2;
    iBaseFace = 0;
    iTopFace = 2;
    nbEdVert = 4 + 4 * (order - 1);
    nbPrimTopVert = 2;
    baseFaceType = TYPE_LIN;
    break;
  case TYPE_PRI:
    dim = 3;
    iBaseFace = 0;
    iTopFace = 1;
    nbEdVert = 6 + 9 * (order - 1);
    nbPrimTopVert = 3;
    baseFaceType = TYPE_TRI;
    break;
  case TYPE_HEX:
    dim = 3;
    iBaseFace = 0;
    iTopFace = 5;
    nbEdVert = 8 + 12 * (order - 1);
    nbPrimTopVert = 4;
    baseFaceType = TYPE_QUA;
    break;
  default:
    Msg::Error("MetaEl not implemented for element of type %d", type);
    dim = 0;
    nbVert = 0;
    return;
  }

  // Get HO nodal base
  const int tag =
    ElementType::getType(type, order); // Get tag for complete element type
  if(!tag) return;
  const nodalBasis *basis = BasisFactory::getNodalBasis(tag);
  nbVert = basis->getNumShapeFunctions();
  points = basis->points;

  // Get nodal bases (HO and linear) on base face
  const int baseFaceTag =
    ElementType::getType(baseFaceType, order); // Get tag for base face basis
  if(!baseFaceTag) return;
  baseFaceBasis = BasisFactory::getNodalBasis(baseFaceTag);
  const int nbBaseVert = baseFaceBasis->getNumShapeFunctions();
  baseGradShapeFuncVal.resize(nbBaseVert, 3 * nbBaseVert);
  const int linBaseFaceTag =
    ElementType::getType(baseFaceType, 1); // Get tag for base face linear basis
  if(!linBaseFaceTag) return;
  linBaseFaceBasis = BasisFactory::getNodalBasis(linBaseFaceTag);
  const int nbLinBaseShapeFunc = linBaseFaceBasis->getNumShapeFunctions();
  baseLinShapeFuncVal.resize(nbBaseVert, nbLinBaseShapeFunc);

  // Compute value of nodal bases of base face at base vertices
  const fullMatrix<double> basePoints = baseFaceBasis->getReferenceNodes();
  for(int iV = 0; iV < baseFaceBasis->getNumShapeFunctions(); iV++) {
    const double &u = basePoints(iV, 0), &v = basePoints(iV, 1);
    double linShapeFunc[1256];
    linBaseFaceBasis->f(u, v, 0., linShapeFunc);
    for(int iSF = 0; iSF < nbLinBaseShapeFunc; iSF++)
      baseLinShapeFuncVal(iV, iSF) = linShapeFunc[iSF];
    double gradShapeFunc[1256][3];
    baseFaceBasis->df(u, v, 0., gradShapeFunc);
    for(int iSF = 0; iSF < nbBaseVert; iSF++) {
      baseGradShapeFuncVal(iV, 3 * iSF) = gradShapeFunc[iSF][0];
      baseGradShapeFuncVal(iV, 3 * iSF + 1) = gradShapeFunc[iSF][1];
      baseGradShapeFuncVal(iV, 3 * iSF + 2) = gradShapeFunc[iSF][2];
    }
  }

  // Indices of vertices on base face
  std::set<int> foundVerts;
  baseInd = basis->getClosure(basis->getClosureId(iBaseFace, 1, 0));
  foundVerts.insert(baseInd.begin(), baseInd.end());

  // Indices of vertices on top face
  topInd = basis->getClosure(basis->getClosureId(iTopFace, 0, 0));
  foundVerts.insert(topInd.begin(), topInd.end());
  freeTopInd = std::vector<int>(topInd.begin() + nbPrimTopVert, topInd.end());
  freeTop2Base.resize(freeTopInd.size());
  for(int iVFT = 0; iVFT < freeTopInd.size(); iVFT++) {
    const int &indFT = freeTopInd[iVFT];
    const double &uTop = points(indFT, 0);
    const double &vTop = points(indFT, 1);
    for(int iVB = 0; iVB < baseInd.size();
        iVB++) { // Find corresponding base vertex
      const int &indB = baseInd[iVB];
      const double diffU = uTop - points(indB, 0);
      const double diffV = (dim == 3) ? vTop - points(indB, 1) : 0.;
      if(diffU * diffU + diffV * diffV < TOL) {
        freeTop2Base[iVFT] = iVB;
        break;
      }
    }
  }

  // Indices of vertices on edges (excluding base and top faces)
  for(int iV = 0; iV < nbEdVert; iV++)
    if(foundVerts.find(iV) == foundVerts.end()) {
      edgeInd.push_back(iV);
      foundVerts.insert(iV);
    }

  // Indices of remaining face and interior vertices
  for(int iV = 0; iV < nbVert; iV++) {
    if(foundVerts.find(iV) == foundVerts.end()) {
      otherInd.push_back(iV);
      foundVerts.insert(iV);
      const double &uFree = points(iV, 0);
      const double &vFree = points(iV, 1);
      for(int iVB = 0; iVB < baseInd.size();
          iVB++) { // Find corresponding base vertex
        const int &indB = baseInd[iVB];
        const double diffU = uFree - points(indB, 0);
        const double diffV = (dim == 3) ? vFree - points(indB, 1) : 0.;
        if(diffU * diffU + diffV * diffV < TOL) {
          other2Base.push_back(iVB);
          break;
        }
      }
      for(int iVT = 0; iVT < baseInd.size();
          iVT++) { // Find corresponding top vertex
        const int &indT = topInd[iVT];
        const double diffU = uFree - points(indT, 0);
        const double diffV = (dim == 3) ? vFree - points(indT, 1) : 0.;
        if(diffU * diffU + diffV * diffV < TOL) {
          other2Top.push_back(iVT);
          break;
        }
      }
    }
  }
}

const MetaEl::metaInfoType &MetaEl::getMetaInfo(int elType, int order)
{
  auto itMInfo = _metaInfo.find(elType);
  if(itMInfo == _metaInfo.end()) {
    const metaInfoType mInfo(elType, order);
    itMInfo =
      _metaInfo.insert(std::pair<int, metaInfoType>(elType, mInfo)).first;
  }
  return itMInfo->second;
}

void MetaEl::computeBaseNorm(const SVector3 &metaNorm,
                             const std::vector<MVertex *> &baseVert,
                             const std::vector<MVertex *> &topPrimVert,
                             std::vector<SVector3> &baseNorm)
{
  const int nbFaceNodes = baseVert.size(), nbPrimFaceNodes = topPrimVert.size();

  // Compute thickness at each primary vertex
  std::vector<double> linThick(nbPrimFaceNodes);
  for(int iV = 0; iV < nbPrimFaceNodes; iV++)
    linThick[iV] = topPrimVert[iV]->distance(baseVert[iV]);

  // Compute normal at each base vertex
  std::vector<double> thick(nbFaceNodes, 0.);
  baseNorm.resize(nbFaceNodes);
  for(int iV = 0; iV < nbFaceNodes; iV++) {
    for(int iSF = 0; iSF < nbPrimFaceNodes; iSF++)
      thick[iV] += linThick[iSF] * _mInfo.baseLinShapeFuncVal(iV, iSF);
    double jac[3][2] = {0., 0., 0., 0., 0., 0.};
    for(int iSF = 0; iSF < nbFaceNodes; iSF++) {
      MVertex *vert = baseVert[iSF];
      const double xyz[3] = {vert->x(), vert->y(), vert->z()};
      for(int iXYZ = 0; iXYZ < 3; iXYZ++) {
        jac[iXYZ][0] += xyz[iXYZ] * _mInfo.baseGradShapeFuncVal(iV, 3 * iSF);
        jac[iXYZ][1] +=
          xyz[iXYZ] * _mInfo.baseGradShapeFuncVal(iV, 3 * iSF + 1);
      }
    }
    SVector3 dXYZdU(jac[0][0], jac[1][0], jac[2][0]);
    SVector3 dXYZdV =
      (_mInfo.dim == 2) ? metaNorm : SVector3(jac[0][1], jac[1][1], jac[2][1]);
    baseNorm[iV] = crossprod(dXYZdV, dXYZdU);
    baseNorm[iV].normalize();
    baseNorm[iV] *= thick[iV];
  }
}

MetaEl::MetaEl(int type, int order, const std::vector<MVertex *> &baseVert,
               const std::vector<MVertex *> &topPrimVert)
  : _mInfo(getMetaInfo(type, order)), _metaEl(nullptr), _metaEl0(nullptr)
{
  // Get info on meta-element type
  if(_mInfo.nbVert == 0) return;
  const int &nbVert = _mInfo.nbVert;
  const fullMatrix<double> &points = _mInfo.points;
  const std::vector<int> &baseInd = _mInfo.baseInd;
  const std::vector<int> &topInd = _mInfo.topInd;
  const std::vector<int> &edgeInd = _mInfo.edgeInd;
  const std::vector<int> &otherInd = _mInfo.otherInd;

  // Add copies of vertices in base & top faces (only first-order vertices for
  // top face)
  _metaVert.resize(nbVert);
  for(int iV = 0; iV < baseInd.size(); iV++) {
    const MVertex *const &bVert = baseVert[iV];
    GEntity *geomEnt = bVert->onWhat();
    if(geomEnt->dim() == 0)
      _metaVert[baseInd[iV]] = new MVertex(*bVert);
    else if(geomEnt->dim() == 1) {
      double u;
      bVert->getParameter(0, u);
      _metaVert[baseInd[iV]] =
        new MEdgeVertex(bVert->x(), bVert->y(), bVert->z(), geomEnt, u);
    }
    else if(geomEnt->dim() == 2) {
      double u, v;
      bVert->getParameter(0, u);
      bVert->getParameter(1, v);
      _metaVert[baseInd[iV]] =
        new MFaceVertex(bVert->x(), bVert->y(), bVert->z(), geomEnt, u, v);
    }
  }
  for(int iV = 0; iV < topPrimVert.size(); iV++)
    _metaVert[topInd[iV]] = new MVertex(*topPrimVert[iV]);

  // Create first-order meta-element and normals to base face
  int faceType;
  SVector3 metaNorm;
  switch(type) {
  case TYPE_QUA: {
    _metaEl0 = new MQuadrangle(_metaVert);
    SVector3 v01(_metaVert[0]->point(), _metaVert[1]->point());
    SVector3 v03(_metaVert[0]->point(), _metaVert[3]->point());
    metaNorm = crossprod(v01, v03);
    faceType = TYPE_LIN;
    break;
  }
  case TYPE_PRI: {
    _metaEl0 = new MPrism(_metaVert);
    metaNorm = SVector3(0.);
    faceType = TYPE_TRI;
    break;
  }
  case TYPE_HEX: {
    _metaEl0 = new MHexahedron(_metaVert);
    metaNorm = SVector3(0.);
    faceType = TYPE_QUA;
    break;
  }
  default: {
    Msg::Error("SuperEl not implemented for element of type %d", type);
    return;
  }
  }
  computeBaseNorm(metaNorm, baseVert, topPrimVert, _baseNorm);

  // Add HO vertices in top face
  for(int iV = topPrimVert.size(); iV < topInd.size(); iV++) {
    SPoint3 p;
    const int ind = topInd[iV];
    _metaEl0->pnt(points(ind, 0), points(ind, 1), points(ind, 2), p);
    _metaVert[ind] = new MVertex(p.x(), p.y(), p.z());
  }

  // Add vertices on edges (excluding base and top faces)
  for(int iV = 0; iV < edgeInd.size(); iV++) {
    SPoint3 p;
    const int ind = edgeInd[iV];
    _metaEl0->pnt(points(ind, 0), points(ind, 1), points(ind, 2), p);
    _metaVert[ind] = new MVertex(p.x(), p.y(), p.z());
  }

  // Add remaining face and interior points
  for(int iV = 0; iV < otherInd.size(); iV++)
    _metaVert[otherInd[iV]] = new MVertex(0., 0., 0.);
  placeOtherNodes();

  // Create high-order meta-element
  switch(type) {
  case TYPE_QUA: _metaEl = new MQuadrangleN(_metaVert, order); break;
  case TYPE_PRI: _metaEl = new MPrismN(_metaVert, order); break;
  case TYPE_HEX: _metaEl = new MHexahedronN(_metaVert, order); break;
  }
}

MetaEl::~MetaEl()
{
  for(int i = 0; i < _metaVert.size(); i++) delete _metaVert[i];
  _metaVert.clear();
  if(_metaEl) delete _metaEl;
  if(_metaEl0) delete _metaEl0;
}

// Place free interior and face vertices equidistantly between top and base
// faces
void MetaEl::placeOtherNodes()
{
  for(int iVO = 0; iVO < _mInfo.otherInd.size(); iVO++) {
    const int &indF = _mInfo.otherInd[iVO];
    const int &iVB = _mInfo.other2Base[iVO], indB = _mInfo.baseInd[iVB];
    const int &iVT = _mInfo.other2Top[iVO], indT = _mInfo.topInd[iVT];
    const int iUVWNorm = _mInfo.dim - 1;
    const double fact = 0.5 * (_mInfo.points(indF, iUVWNorm) + 1.);
    SPoint3 pB = _metaVert[indB]->point(), pT = _metaVert[indT]->point();
    const double newX = (1. - fact) * pB.x() + fact * pT.x();
    const double newY = (1. - fact) * pB.y() + fact * pT.y();
    const double newZ = (1. - fact) * pB.z() + fact * pT.z();
    _metaVert[indF]->setXYZ(newX, newY, newZ);
  }
}

void MetaEl::setCurvedTop(double factor)
{
  // Place HO vertices of top face so that meta-elemnt has almost uniform
  // thickness
  for(int iVFT = 0; iVFT < _mInfo.freeTopInd.size(); iVFT++) {
    const int &indFT = _mInfo.freeTopInd[iVFT];
    const int &iVB = _mInfo.freeTop2Base[iVFT], indB = _mInfo.baseInd[iVB];
    const int iUVWNorm = _mInfo.dim - 1;
    const SPoint3 pB = _metaVert[indB]->point();
    const SVector3 &norm = _baseNorm[iVB];
    const double newX = pB.x() + factor * norm.x();
    const double newY = pB.y() + factor * norm.y();
    const double newZ = pB.z() + factor * norm.z();
    _metaVert[indFT]->setXYZ(newX, newY, newZ);
  }

  // Place the other free nodes equidistantly between base and top faces
  placeOtherNodes();
}

void MetaEl::setFlatTop()
{
  // Get info on meta-element type
  const fullMatrix<double> &points = _mInfo.points;
  const std::vector<int> &freeTopInd = _mInfo.topInd;

  // Put top vertices on straight meta-element
  for(int iVFT = 0; iVFT < freeTopInd.size(); iVFT++) {
    const int &indFT = freeTopInd[iVFT];
    SPoint3 p;
    _metaEl0->pnt(points(indFT, 0), points(indFT, 1), points(indFT, 2), p);
    _metaVert[indFT]->setXYZ(p.x(), p.y(), p.z());
  }

  // Place the other free nodes equidistantly between base and top faces
  placeOtherNodes();
}

bool MetaEl::isPointIn(const SPoint3 &p) const
{
  double xyz[3] = {p.x(), p.y(), p.z()}, uvw[3];
  _metaEl0->xyz2uvw(xyz, uvw);
  return _metaEl0->isInside(uvw[0], uvw[1], uvw[2]);
}

bool MetaEl::straightToCurved(double *xyzS, double *xyzC) const
{
  double uvw[3];
  _metaEl0->xyz2uvw(xyzS, uvw);
  if(!_metaEl0->isInside(uvw[0], uvw[1], uvw[2])) return false;

  SPoint3 pC;
  _metaEl->pnt(uvw[0], uvw[1], uvw[2], pC);
  xyzC[0] = pC[0];
  xyzC[1] = pC[1];
  xyzC[2] = pC[2];

  return true;
}

std::string MetaEl::printPOS()
{
  std::vector<MVertex *> verts;
  _metaEl->getVertices(verts);
  std::string posStr = _metaEl0->getStringForPOS();
  int n =
    (posStr[posStr.size() - 1] == '2' ? _metaEl : _metaEl0)->getNumVertices();

  std::ostringstream oss;

  oss << posStr << "(";
  for(int i = 0; i < n; i++) {
    if(i) oss << ",";
    oss << _metaVert[i]->x() << "," << _metaVert[i]->y() << ","
        << _metaVert[i]->z();
  }
  oss << "){0.";
  for(int i = 1; i < n; i++) oss << ",0.";
  oss << "};\n";

  return oss.str();
}
