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

#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "OptHomFastCurving.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Gmsh.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MEdge.h"
#include "MFace.h"
#include "OS.h"
#include "SVector3.h"
#include "BasisFactory.h"
#include "bezierBasis.h"
#include "JacobianBasis.h"
#include "MetaEl.h"
#include "qualityMeasuresJacobian.h"
#include "CADDistances.h"
#include "Field.h"
#include "boundaryLayersData.h"
#include "BoundaryLayerCurver.h"



namespace {



typedef std::map<MEdge, std::vector<MElement*>, Less_Edge> MEdgeVecMEltMap;
typedef std::map<MFace, std::vector<MElement*>, Less_Face> MFaceVecMEltMap;



// Compute edge -> element connectivity (for 2D elements)
void calcEdge2Elements(GEntity *entity, MEdgeVecMEltMap &ed2el)
{
  for (size_t iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
    MElement *elt = entity->getMeshElement(iEl);
    if (elt->getDim() == 2)
      for (int iEdge = 0; iEdge < elt->getNumEdges(); iEdge++) {
        ed2el[elt->getEdge(iEdge)].push_back(elt);
      }
  }
}



// Compute face -> element connectivity (for 3D elements)
void calcFace2Elements(GEntity *entity, MFaceVecMEltMap &face2el)
{
  for (size_t iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
    MElement *elt = entity->getMeshElement(iEl);
    if (elt->getDim() == 3)
      for (int iFace = 0; iFace < elt->getNumFaces(); iFace++)
        face2el[elt->getFace(iFace)].push_back(elt);
  }
}



void makeStraight(MElement *el, const std::set<MVertex*> &movedVert)
{
  const nodalBasis *nb = el->getFunctionSpace();
  const fullMatrix<double> &pts = nb->points;

  SPoint3 p;

  for (int iPt = el->getNumPrimaryVertices();
       iPt < el->getNumVertices(); iPt++) {
    MVertex *vert = el->getVertex(iPt);
    if (movedVert.find(vert) == movedVert.end()) {
      el->primaryPnt(pts(iPt,0),pts(iPt,1),pts(iPt,2),p);
      vert->setXYZ(p.x(),p.y(),p.z());
    }
  }
}



inline void insertIfCurved(MElement *el, std::list<MElement*> &bndEl)
{
  static const double curvedTol = 1.e-3;                                        // Tolerance to consider element as curved

  const double normalDispCurved = curvedTol*el->getInnerRadius();               // Threshold in normal displacement to consider element as curved
  const int dim = el->getDim();

  // Compute unit normal to straight edge/face
  SVector3 normal = (dim == 1) ? el->getEdge(0).normal() :
                                 el->getFace(0).normal();

  // Get functional spaces
  const nodalBasis *lagBasis = el->getFunctionSpace();
  const fullMatrix<double> &uvw = lagBasis->points;
  const int &nV = uvw.size1();
  const nodalBasis *lagBasis1 = el->getFunctionSpace(1);
  const int &nV1 = lagBasis1->points.size1();

  // Get first-order vertices
  std::vector<SPoint3> xyz1(nV1);
  for (int iV = 0; iV < nV1; ++iV) xyz1[iV] = el->getVertex(iV)->point();

  // Check normal displacement at each HO vertex
  for (int iV = nV1; iV < nV; ++iV) {                                           // Loop over HO nodes
    double f[256];
    lagBasis1->f(uvw(iV, 0), (dim > 1) ? uvw(iV, 1) : 0., 0., f);
    SPoint3 xyzS(0.,0.,0.);
    for (int iSF = 0; iSF < nV1; ++iSF) xyzS += xyz1[iSF]*f[iSF];               // Compute location of node in straight element
    const SVector3 vec(xyzS, el->getVertex(iV)->point());
    const double normalDisp = fabs(dot(vec, normal));                           // Normal component of displacement
    if (normalDisp > normalDispCurved) {
      bndEl.push_back(el);
      break;
    }
  }
}



void getOppositeEdgeQuad(MElement *el, const MEdge &elBaseEd, MEdge &elTopEd,
                         double &edLenMin, double &edLenMax)
{
  // Find base face
  int iElBaseEd, elBaseEdOrient;
  el->getEdgeInfo(elBaseEd, iElBaseEd, elBaseEdOrient);

  // Determine opposite and side edges
  int iOppEd, iSideEd0, iSideEd1;
  if (iElBaseEd == 0) { iOppEd = 2; iSideEd0 = 1; iSideEd1 = 3;}
  else if (iElBaseEd == 1) { iOppEd = 3; iSideEd0 = 0; iSideEd1 = 2;}
  else if (iElBaseEd == 2) { iOppEd = 0; iSideEd0 = 1; iSideEd1 = 3;}
  else { iOppEd = 1; iSideEd0 = 0; iSideEd1 = 2;}
  const MEdge elOppEd = el->getEdge(iOppEd);

  // Create top edge
  if (elBaseEdOrient > 0)
    elTopEd = MEdge(elOppEd.getVertex(1), elOppEd.getVertex(0));
  else
    elTopEd = elOppEd;

  // Compute max. and min. edge lengths
  edLenMax = elTopEd.length();
  edLenMin = std::min(el->getEdge(iSideEd0).length(),
                      el->getEdge(iSideEd1).length());
}



void getOppositeEdgeTri(MElement *el, const MEdge &elBaseEd, MEdge &elTopEd,
                        double &edLenMin, double &edLenMax)
{
  static const double BIG = 1e300;

  // Find base face
  int iElBaseEd, iDum;
  el->getEdgeInfo(elBaseEd, iElBaseEd, iDum);
  edLenMin = BIG;
  edLenMax = -BIG;
  MEdge elMaxEd;

  // Look for largest edge except base one
  for (int iElEd = 0; iElEd < el->getNumEdges(); iElEd++) {
    if (iElEd != iElBaseEd) {
      MEdge edTest = el->getEdge(iElEd);
      double edLenTest = edTest.length();
      if (edLenTest < edLenMin) edLenMin = edLenTest;
      if (edLenTest > edLenMax) {
        edLenMax = edLenTest;
        elMaxEd = edTest;
      }
    }
  }

  // Build top edge from max edge (with right orientation)
  if (elBaseEd.getVertex(0) == elMaxEd.getVertex(0)) elTopEd = elMaxEd;
  else elTopEd = MEdge(elMaxEd.getVertex(1), elMaxEd.getVertex(0));
}



void getColumnQuad(MEdgeVecMEltMap &ed2el, const FastCurvingParameters &p,
                   MEdge &elBaseEd, std::vector<MElement*> &blob,
                   MElement* &aboveElt)
{
  const double maxDP = std::cos(p.maxAngle);

  MElement *el = 0;

  for (int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
    std::vector<MElement*> newElts = ed2el[elBaseEd];
    if ((iLayer > 0) && (newElts.size() < 2)) { aboveElt = 0; break; }
    el = (newElts[0] == el) ? newElts[1] : newElts[0];
    aboveElt = el;
    if (el->getType() != TYPE_QUA) break;
    MEdge elTopEd;
    double edLenMin, edLenMax;
    getOppositeEdgeQuad(el, elBaseEd, elTopEd, edLenMin, edLenMax);

    if (edLenMin > edLenMax*p.maxRho) break;
    const double dp = dot(elBaseEd.normal(), elTopEd.normal());
    if (std::abs(dp) < maxDP) break;

    blob.push_back(el);
    elBaseEd = elTopEd;
  }
}



void getColumnTri(MEdgeVecMEltMap &ed2el, const FastCurvingParameters &p,
                  MEdge &elBaseEd, std::vector<MElement*> &blob,
                  MElement* &aboveElt)
{
  const double maxDP = std::cos(p.maxAngle);
  const double maxDPIn = std::cos(p.maxAngleInner);

  MElement *el0 = 0, *el1 = 0;

  for (int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
    // Get first element in layer
    std::vector<MElement*> newElts0 = ed2el[elBaseEd];
    if ((iLayer > 0) && (newElts0.size() < 2)) { aboveElt = 0; break; }
    el0 = (newElts0[0] == el1) ? newElts0[1] : newElts0[0];
    aboveElt = el0;
    if (el0->getType() != TYPE_TRI) break;
    MEdge elTopEd0;
    double edLenMin0, edLenMax0;
    getOppositeEdgeTri(el0, elBaseEd, elTopEd0, edLenMin0, edLenMax0);
    const SVector3 normBase = elBaseEd.normal();
    const SVector3 normTop0 = elTopEd0.normal();
    if (std::abs(dot(normBase, normTop0)) < maxDPIn) break;

    // Get second element in layer
    std::vector<MElement*> newElts1 = ed2el[elTopEd0];
    if (newElts1.size() < 2) { aboveElt = 0; break; }
    el1 = (newElts1[0] == el0) ? newElts1[1] : newElts1[0];
    if (el1->getType() != TYPE_TRI) break;
    MEdge elTopEd1;
    double edLenMin1, edLenMax1;
    getOppositeEdgeTri(el1, elTopEd0, elTopEd1, edLenMin1, edLenMax1);
    const SVector3 normTop1 = elTopEd1.normal();
    if (std::abs(dot(normTop0, normTop1)) < maxDPIn) break;

    // Check stop criteria
    const double edLenMin = std::min(edLenMin0, edLenMin1);
    const double edLenMax = std::max(edLenMax0, edLenMax1);
    if (edLenMin > edLenMax*p.maxRho) break;
    if (std::abs(dot(normBase, normTop1)) < maxDP) break;

    // Add elements to blob and pass top edge to next layer
    blob.push_back(el0);
    blob.push_back(el1);
    elBaseEd = elTopEd1;
  }
}



bool getColumn2D(MEdgeVecMEltMap &ed2el, const FastCurvingParameters &p,
                 const MEdge &baseEd, std::vector<MVertex*> &baseVert,
                 std::vector<MVertex*> &topPrimVert,
                 std::vector<MElement*> &blob, MElement* &aboveElt)
{
  // Get first element and base vertices
  std::vector<MElement*> firstElts = ed2el[baseEd];
  MElement *el = firstElts[0];
  int iFirstElEd, iDum;
  el->getEdgeInfo(baseEd, iFirstElEd, iDum);
  el->getEdgeVertices(iFirstElEd, baseVert);
  MEdge elBaseEd(baseVert[0], baseVert[1]);

  // Sweep column upwards by choosing largest edges in each element
  if (el->getType() == TYPE_TRI)
    getColumnTri(ed2el, p, elBaseEd, blob, aboveElt);
  else getColumnQuad(ed2el, p, elBaseEd, blob, aboveElt);

  topPrimVert.resize(2);
  topPrimVert[0] = elBaseEd.getVertex(0);
  topPrimVert[1] = elBaseEd.getVertex(1);
  return true;
}



void getOppositeFacePrism(MElement *el, const MFace &elBaseFace,
                          MFace &elTopFace, double &faceSurfMin,
                          double &faceSurfMax)
{
  // Find base face
  int iElBaseFace = -1, iDum;
  el->getFaceInfo(elBaseFace, iElBaseFace, iDum, iDum);

  // Check side edges to find opposite vertices
  const int sideEd[3] = {2, 4, 5};
  std::vector<MVertex*> topVert(3);
  for (int iEd = 0; iEd < 3; iEd++) {
    MEdge ed = el->getEdge(sideEd[iEd]);
    for (int iV = 0; iV < 3; iV++) {
      if (elBaseFace.getVertex(iV) == ed.getVertex(0))
        topVert[iV] = ed.getVertex(1);
      else if (elBaseFace.getVertex(iV) == ed.getVertex(1))
        topVert[iV] = ed.getVertex(0);
    }
  }
  elTopFace = MFace(topVert);

  // Compute min. (side faces) and max. (top face) face areas
  faceSurfMax = elTopFace.approximateArea();
  MFace sideFace0 = el->getFace(2);
  faceSurfMin = sideFace0.approximateArea();
  MFace sideFace1 = el->getFace(3);
  faceSurfMin = std::min(faceSurfMin, sideFace1.approximateArea());
  MFace sideFace2 = el->getFace(4);
  faceSurfMin = std::min(faceSurfMin, sideFace2.approximateArea());
}



void getOppositeFaceHex(MElement *el, const MFace &elBaseFace, MFace &elTopFace,
                        double &faceSurfMin, double &faceSurfMax)
{
  // Find base face
  int iElBaseFace = -1, iDum;
  el->getFaceInfo(elBaseFace, iElBaseFace, iDum, iDum);

  // Determine side edges
  int sideEd[4], sideFace[4];
  if ((iElBaseFace == 0) || (iElBaseFace == 5)) {
    sideEd[0] = 2; sideEd[1] = 4; sideEd[2] = 6; sideEd[3] = 7;
    sideFace[0] = 1; sideFace[1] = 2; sideFace[2] = 3; sideFace[3] = 4;
  }
  else if ((iElBaseFace == 1) || (iElBaseFace == 4)) {
    sideEd[0] = 1; sideEd[1] = 3; sideEd[2] = 10; sideEd[3] = 9;
    sideFace[0] = 0; sideFace[1] = 2; sideFace[2] = 3; sideFace[3] = 5;
  }
  else if ((iElBaseFace == 2) || (iElBaseFace == 3)) {
    sideEd[0] = 0; sideEd[1] = 5; sideEd[2] = 11; sideEd[3] = 8;
    sideFace[0] = 0; sideFace[1] = 1; sideFace[2] = 4; sideFace[3] = 5;
  }

  // Check side edges to find opposite vertices
  std::vector<MVertex*> topVert(4);
  for (int iEd = 0; iEd < 4; iEd++) {
    MEdge ed = el->getEdge(sideEd[iEd]);
    for (int iV = 0; iV < 4; iV++) {
      if (elBaseFace.getVertex(iV) == ed.getVertex(0))
        topVert[iV] = ed.getVertex(1);
      else if (elBaseFace.getVertex(iV) == ed.getVertex(1))
        topVert[iV] = ed.getVertex(0);
    }
  }
  elTopFace = MFace(topVert);

  // Compute min. (side faces) and max. (top face) face areas
  faceSurfMax = elTopFace.approximateArea();
  MFace sideFace0 = el->getFace(sideFace[0]);
  faceSurfMin = sideFace0.approximateArea();
  MFace sideFace1 = el->getFace(sideFace[1]);
  faceSurfMin = std::min(faceSurfMin, sideFace1.approximateArea());
  MFace sideFace2 = el->getFace(sideFace[2]);
  faceSurfMin = std::min(faceSurfMin, sideFace2.approximateArea());
  MFace sideFace3 = el->getFace(sideFace[3]);
  faceSurfMin = std::min(faceSurfMin, sideFace3.approximateArea());
}



void getOppositeFaceTet(MElement *el, const MFace &elBaseFace, MFace &elTopFace,
                        double &faceSurfMin, double &faceSurfMax)
{
  static const double BIG = 1e300;

  int iElBaseFace = -1, iDum;
  el->getFaceInfo(elBaseFace, iElBaseFace, iDum, iDum);
  faceSurfMin = BIG;
  faceSurfMax = -BIG;
  MFace elMaxFace;

  // Look for largest face except base one
  for (int iElFace = 0; iElFace < el->getNumFaces(); iElFace++) {
    if (iElFace != iElBaseFace) {
      MFace faceTest = el->getFace(iElFace);
      const double faceSurfTest = faceTest.approximateArea();
      if (faceSurfTest < faceSurfMin) faceSurfMin = faceSurfTest;
      if (faceSurfTest > faceSurfMax) {
        faceSurfMax = faceSurfTest;
        elMaxFace = faceTest;
      }
    }
  }

  // Build top face from max face (with right correspondance)
  MVertex *maxVert[3] = {elMaxFace.getVertex(0),
                         elMaxFace.getVertex(1), elMaxFace.getVertex(2)};
  std::vector<MVertex*> topVert(3, static_cast<MVertex*>(0));
  for (int iBaseV = 0; iBaseV < 3; iBaseV++)                                    // Two vertices of elTopFace are those of elMaxFace coinciding with elBaseFace
    for (int iMaxV = 0; iMaxV < 3; iMaxV++)
      if (elBaseFace.getVertex(iBaseV) == maxVert[iMaxV]) {
        topVert[iBaseV] = maxVert[iMaxV];
        maxVert[iMaxV] = 0;
      }
  MVertex *thirdMaxVert = (maxVert[0] != 0) ? maxVert[0] :                      // Set last vertex of elTopFace as remaining vertex in elMaxFace
                          (maxVert[1] != 0) ? maxVert[1] : maxVert[2];
  if (topVert[0] == 0) topVert[0] = thirdMaxVert;
  else if (topVert[1] == 0) topVert[1] = thirdMaxVert;
  else topVert[2] = thirdMaxVert;
  elTopFace = MFace(topVert);
}



// Column of tets: assume tets obtained from subdivision of prism
void getColumnTet(MFaceVecMEltMap &face2el,
                  const FastCurvingParameters &p, MFace &elBaseFace,
                  std::vector<MElement*> &blob, MElement* &aboveElt)
{
  const double maxDP = std::cos(p.maxAngle);
  const double maxDPIn = std::cos(p.maxAngleInner);

  MElement *el0 = 0, *el1 = 0, *el2 = 0;

  for (int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
    // Get first element in layer
    std::vector<MElement*> newElts0 = face2el[elBaseFace];
    if ((iLayer > 0) && (newElts0.size() < 2)) { aboveElt = 0; break; }
    el0 = (newElts0[0] == el2) ? newElts0[1] : newElts0[0];
    aboveElt = el0;
    if (el0->getType() != TYPE_TET) break;
    MFace elTopFace0;
    double faceSurfMin0, faceSurfMax0;
    getOppositeFaceTet(el0, elBaseFace, elTopFace0, faceSurfMin0, faceSurfMax0);
    const SVector3 normBase = elBaseFace.normal();
    const SVector3 normTop0 = elTopFace0.normal();
    if (std::abs(dot(normBase, normTop0)) < maxDPIn) break;

    // Get second element in layer
    std::vector<MElement*> newElts1 = face2el[elTopFace0];
    if (newElts1.size() < 2) { aboveElt = 0; break; }
    el1 = (newElts1[0] == el0) ? newElts1[1] : newElts1[0];
    if (el1->getType() != TYPE_TET) break;
    MFace elTopFace1;
    double faceSurfMin1, faceSurfMax1;
    getOppositeFaceTet(el1, elTopFace0, elTopFace1, faceSurfMin1, faceSurfMax1);
    const SVector3 normTop1 = elTopFace1.normal();
    if (std::abs(dot(normTop0, normTop1)) < maxDPIn) break;

    // Get third element in layer
    std::vector<MElement*> newElts2 = face2el[elTopFace1];
    if (newElts2.size() < 2) { aboveElt = 0; break; }
    el2 = (newElts2[0] == el1) ? newElts2[1] : newElts2[0];
    if (el2->getType() != TYPE_TET) break;
    MFace elTopFace2;
    double faceSurfMin2, faceSurfMax2;
    getOppositeFaceTet(el2, elTopFace1, elTopFace2, faceSurfMin2, faceSurfMax2);
    const SVector3 normTop2 = elTopFace2.normal();
    if (std::abs(dot(normTop1, normTop2)) < maxDPIn) break;

    // Check stop criteria
    const double faceSurfMin = std::min(faceSurfMin0,
                                        std::min(faceSurfMin1, faceSurfMin2));
    const double faceSurfMax = std::max(faceSurfMax0,
                                        std::min(faceSurfMax1, faceSurfMax2));
    if (faceSurfMin > faceSurfMax*p.maxRho) break;
    if (std::abs(dot(normBase, normTop2)) < maxDP) break;

    // Add elements to blob and pass top face to next layer
    blob.push_back(el0);
    blob.push_back(el1);
    blob.push_back(el2);
    elBaseFace = elTopFace2;
  }
}



void getColumnPrismHex(int elType, MFaceVecMEltMap &face2el,
                       const FastCurvingParameters &p, MFace &elBaseFace,
                       std::vector<MElement*> &blob, MElement* &aboveElt)
{
  const double maxDP = std::cos(p.maxAngle);

  MElement *el = 0;

  for (int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
    std::vector<MElement*> newElts = face2el[elBaseFace];
    if ((iLayer > 0) && (newElts.size() < 2)) { aboveElt = 0; break; }
    el = (newElts[0] == el) ? newElts[1] : newElts[0];
    aboveElt = el;
    if (el->getType() != elType) break;

    MFace elTopFace;
    double faceSurfMin, faceSurfMax;
    if (el->getType() == TYPE_PRI)
      getOppositeFacePrism(el, elBaseFace, elTopFace, faceSurfMin, faceSurfMax);
    else if (el->getType() == TYPE_HEX)
      getOppositeFaceHex(el, elBaseFace, elTopFace, faceSurfMin, faceSurfMax);

    if (faceSurfMin > faceSurfMax*p.maxRho) break;
    const double dp = dot(elBaseFace.normal(), elTopFace.normal());
    if (std::abs(dp) < maxDP) break;

    blob.push_back(el);
    elBaseFace = elTopFace;
  }
}



bool getColumn3D(MFaceVecMEltMap &face2el, const FastCurvingParameters &p,
                 const MFace &baseFace, std::vector<MVertex*> &baseVert,
                 std::vector<MVertex*> &topPrimVert,
                 std::vector<MElement*> &blob, MElement* &aboveElt)
{
  // Get first element and base vertices
  const int nbBaseFaceVert = baseFace.getNumVertices();
  std::vector<MElement*> firstElts = face2el[baseFace];
  MElement *el = firstElts[0];
  int iFirstElFace = -1, iDum;
  el->getFaceInfo(baseFace, iFirstElFace, iDum, iDum);
  el->getFaceVertices(iFirstElFace, baseVert);
  MFace elBaseFace(baseVert[0], baseVert[1], baseVert[2],
                   (nbBaseFaceVert == 3) ? 0 : baseVert[3]);

  // Sweep column upwards by choosing largest faces in each element
  if (nbBaseFaceVert == 3) {
    if (el->getType() == TYPE_PRI)                                              // Get BL column of prisms
      getColumnPrismHex(TYPE_PRI, face2el, p, elBaseFace, blob, aboveElt);
    else if (el->getType() == TYPE_TET)
      getColumnTet(face2el, p, elBaseFace, blob, aboveElt);
  }
  else if ((nbBaseFaceVert == 4) && (el->getType() == TYPE_HEX))                // Get BL column of hexas
    getColumnPrismHex(TYPE_HEX, face2el, p, elBaseFace, blob, aboveElt);
  else return false;                                                            // Not a BL
  if (blob.size() == 0) return false;                                           // Could not find column (may not be a BL)

  // Create top face of column with last face vertices
  topPrimVert.resize(nbBaseFaceVert);
  topPrimVert[0] = elBaseFace.getVertex(0);
  topPrimVert[1] = elBaseFace.getVertex(1);
  topPrimVert[2] = elBaseFace.getVertex(2);
  if (nbBaseFaceVert == 4) topPrimVert[3] = elBaseFace.getVertex(3);
  return true;
}



class DbgOutputMeta {
public:
  void addMetaEl(MetaEl &mEl) {
    MElement *elt = mEl.getMElement();
    elType_.push_back(elt->getTypeForMSH());
    nbVertEl_.push_back(elt->getNumVertices());
    for (int iV = 0; iV < elt->getNumVertices(); iV++)
      point_.push_back(elt->getVertex(iV)->point());
  }
  void write(std::string fNameBase, int tag) {
    std::ostringstream oss;
    oss << fNameBase << "_" << tag << ".msh";
    std::string fName = oss.str();
    FILE *fp = fopen(fName.c_str(), "w");
    if(!fp) return;
    fprintf(fp, "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n");
    fprintf(fp, "$Nodes\n");
    fprintf(fp, "%d\n", point_.size());
    for (int iV = 0; iV < point_.size(); iV++)
      fprintf(fp, "%i %g %g %g\n", iV+1, point_[iV].x(),
              point_[iV].y(), point_[iV].z());
    fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
    fprintf(fp, "%d\n", elType_.size());
    int iV = 0;
    for (int iEl = 0; iEl < elType_.size(); iEl++) {
      fprintf(fp, "%i %i 2 0 0 ", iEl+1, elType_[iEl]);
      for (int iVEl = 1; iVEl <= nbVertEl_[iEl]; iVEl++)
        fprintf(fp, " %i", iV+iVEl);
      fprintf(fp, "\n");
      iV += nbVertEl_[iEl];
    }
    fprintf(fp, "$EndElements\n");
    fclose(fp);
  }

private:
  std::vector<int> elType_;
  std::vector<int> nbVertEl_;
  std::vector<SPoint3> point_;
};



class DbgOutputCol {
public:
  void addBlob(const std::vector<MElement*> &blob) {
    for (int iEl = 0; iEl < blob.size(); iEl++) addElement(blob[iEl]);
  }
  void addElement(MElement* elt) {
    elt_.push_back(elt);
    for (int iV = 0; iV < elt->getNumVertices(); iV++)
      vert_.insert(elt->getVertex(iV));
  }
  void write(std::string fNameBase, int tag) {
    std::ostringstream oss;
    oss << fNameBase << "_" << tag << ".msh";
    std::string fName = oss.str();
    FILE *fp = fopen(fName.c_str(), "w");
    if(!fp) return;
    fprintf(fp, "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n");
    fprintf(fp, "$Nodes\n");
    fprintf(fp, "%d\n", vert_.size());
    for (std::set<MVertex*>::iterator itV = vert_.begin();
         itV != vert_.end(); ++itV) {
      SPoint3 p = (*itV)->point();
      fprintf(fp, "%i %g %g %g\n", (*itV)->getNum(), p.x(), p.y(), p.z());
    }
    fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
    fprintf(fp, "%d\n", elt_.size());
    int iV = 0;
    for (int iEl = 0; iEl < elt_.size(); iEl++) {
      fprintf(fp, "%i %i 2 0 0 ", elt_[iEl]->getNum(),
                                  elt_[iEl]->getTypeForMSH());
      for (int iVEl = 0; iVEl < elt_[iEl]->getNumVertices(); iVEl++)
        fprintf(fp, " %i", elt_[iEl]->getVertex(iVEl)->getNum());
      fprintf(fp, "\n");
    }
    fprintf(fp, "$EndElements\n");
    fclose(fp);
  }

private:
  std::set<MVertex*> vert_;
  std::vector<MElement*> elt_;
};



void curveElement(const MetaEl &metaElt, std::set<MVertex*> &movedVert,
                  MElement *elt)
{
    makeStraight(elt, movedVert);
    for (int iV = elt->getNumPrimaryVertices();
         iV < elt->getNumVertices(); iV++) {                                  // Loop over HO vert. of each el. in blob
      MVertex* vert = elt->getVertex(iV);
      if (movedVert.find(vert) == movedVert.end()) {                          // Try to move vert. not already moved
        double xyzS[3] = {vert->x(), vert->y(), vert->z()}, xyzC[3];
        if (metaElt.straightToCurved(xyzS, xyzC)) {
          vert->setXYZ(xyzC[0], xyzC[1], xyzC[2]);
          movedVert.insert(vert);
        }
      }
    }
}



double calcCADDistSq2D(GEntity *geomEnt, MElement *bndElt)
{
  const int nbVert = bndElt->getNumVertices();
  const int nbPrimVert = bndElt->getNumPrimaryVertices();
  const GradientBasis *gb = BasisFactory::getGradientBasis(FuncSpaceData(bndElt));

  // Coordinates of nodes
  fullMatrix<double> nodesXYZ(nbVert, 3);
  for (int iV = 0; iV < nbVert; iV++) {
    MVertex *vert = bndElt->getVertex(iV);
    nodesXYZ(iV, 0) = vert->x();
    nodesXYZ(iV, 1) = vert->y();
    nodesXYZ(iV, 2) = vert->z();
  }

  // Compute distance
  const GEdge *ge = geomEnt->cast2Edge();
  const Range<double> parBounds = ge->parBounds(0);
  std::vector<SVector3> tanCAD(nbVert);
  for (int iV = 0; iV < nbVert; iV++) {
    MVertex *vert = bndElt->getVertex(iV);
    double tCAD;
    if (vert->onWhat() == geomEnt)                                                       // If HO vertex, ...
      vert->getParameter(0, tCAD);                                                       // ... get stored param. coord. (can be only line).
    else {                                                                               // Otherwise, get param. coord. from CAD.
      if (ge->getBeginVertex() &&
          (ge->getBeginVertex()->mesh_vertices[0] == vert))
        tCAD = parBounds.low();
      else if (ge->getEndVertex() &&
               (ge->getEndVertex()->mesh_vertices[0] == vert))
        tCAD = parBounds.high();
      else
        tCAD = ge->parFromPoint(vert->point());
    }
    tanCAD[iV] = ge->firstDer(tCAD);                                                     // Compute tangent at vertex
    tanCAD[iV].normalize();                                                              // Normalize tangent
  }
  return taylorDistanceSq1D(gb, nodesXYZ, tanCAD);
}



double moveAndGetDistSq2DP2(GEdge *ge, MLine3 *bndMetaElt,
                           MVertex* vert, double u)
{
  vert->setParameter(0, u);
  GPoint gp = ge->point(u);
  vert->setXYZ(gp.x(), gp.y(), gp.z());
  return calcCADDistSq2D(ge, bndMetaElt);
}



void optimizeCADDist2DP2(GEntity *geomEnt, std::vector<MVertex*> &baseVert)
{
  // Parameters for secant method
  static const int MAXIT = 20;
  static const double TOL = 1e-3;

  // Boundary geometric and mesh entities, parametrization
  MLine3 bndMetaElt(baseVert);
  MVertex* &vert = baseVert[2];
  GEdge *ge = geomEnt->cast2Edge();
  const Range<double> parBounds = ge->parBounds(0);
  double uBV0, uBV1, uMin, uMax;
  reparamMeshVertexOnEdge(baseVert[0], ge, uBV0);
  reparamMeshVertexOnEdge(baseVert[1], ge, uBV1);
  if (uBV0 < uBV1) { uMin = uBV0; uMax = uBV1; }
  else { uMin = uBV1; uMax = uBV0; }
  const double du = uMax - uMin;
  
  // First initial value for secant method
  double u00 = uMin + 0.5*du;
  double distSq00 = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u00);
  const double edLen = bndMetaElt.getLength();

  // Second initial value for secant method
  const double u0A = uMin + 0.45*du, u0B = uMin + 0.55*du;
  const double distSq0A = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u0A);
  const double distSq0B = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u0B);
  double u0, distSq0;
  if (distSq0A < distSq0B) {
    u0 = u0A; distSq0 = distSq0A;
  }
  else {
    u0 = u0B; distSq0 = distSq0B;
  }

  // Secant method iteration
  double u;
  bool converged = false;
  for (int it = 0; it < MAXIT; it++) {
    u = (u00*distSq0 - u0*distSq00) / (distSq0 - distSq00);
    const double distSq = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u);
    if (std::abs(u-u0)/du < TOL) { converged = true; break; }
    u00 = u0; distSq00 = distSq0;
    u0 = u; distSq0 = distSq;
  }

  if (!converged || (u < uMin+TOL) || (u > uMax-TOL)) {                         // Set to mid-point if not converged
    u = uMin + 0.5*du;
    vert->setParameter(0, u);
    GPoint gp = ge->point(u);
    vert->setXYZ(gp.x(), gp.y(), gp.z());
  }
}



// void calcCADDistSqAndGradients(int dim, GEntity *geomEnt, MElement *bndElt,
//                                double &dist, std::vector<double> &gradDist)
// {
//   const int nbVert = bndElt->getNumVertices();
//   const int nbPrimVert = bndElt->getNumPrimaryVertices();
//   const GradientBasis *gb = BasisFactory::getGradientBasis(FuncSpaceData(bndElt));

//   // Coordinates of nodes
//   fullMatrix<double> nodesXYZ(nbVert, 3);
//   for (int iV = 0; iV < nbVert; iV++) {
//     MVertex *vert = bndElt->getVertex(iV);
//     nodesXYZ(iV, 0) = vert->x();
//     nodesXYZ(iV, 1) = vert->y();
//     nodesXYZ(iV, 2) = vert->z();
//   }

//   // Compute distance and gradients
//   if (dim == 2) {                                                                        // 2D
//     const GEdge *ge = geomEnt->cast2Edge();
//     const Range<double> parBounds = ge->parBounds(0);
//     const double eps = 1.e-6 * (parBounds.high()-parBounds.low());
//     std::vector<SVector3> tanCAD(nbVert);
//     for (int iV = 0; iV < nbVert; iV++) {
//       MVertex *vert = bndElt->getVertex(iV);
//       double tCAD;
//       if (iV >= nbPrimVert)                                                                // If HO vertex, ...
//         vert->getParameter(0, tCAD);                                                       // ... get stored param. coord. (can be only line).
//       else {                                                                               // Otherwise, get param. coord. from CAD.
//         if (ge->getBeginVertex() &&
//             (ge->getBeginVertex()->mesh_vertices[0] == vert))
//           tCAD = parBounds.low();
//         else if (ge->getEndVertex() &&
//                  (ge->getEndVertex()->mesh_vertices[0] == vert))
//           tCAD = parBounds.high();
//         else
//           tCAD = ge->parFromPoint(vert->point());
//       }
//       tanCAD[iV] = ge->firstDer(tCAD);                                                     // Compute tangent at vertex
//       tanCAD[iV].normalize();                                                              // Normalize tangent
//     }
//     dist = taylorDistanceSq1D(gb, nodesXYZ, tanCAD);
//     for (int iV = nbPrimVert; iV < nbVert; iV++) {
//       const double xS = nodesXYZ(iV, 0), yS = nodesXYZ(iV, 1),
//                    zS = nodesXYZ(iV, 2);                                                  // Save coord. of perturbed node for FD
//       const SVector3 tanCADS = tanCAD[iV];                                                // Save tangent to CAD at perturbed node
//       double tCAD;
//       bndElt->getVertex(iV)->getParameter(0, tCAD);
//       tCAD += eps;                                                                        // New param. coord. of perturbed node
//       GPoint gp = ge->point(tCAD);                                                        // New coord. of perturbed node
//       nodesXYZ(iV, 0) = gp.x();
//       nodesXYZ(iV, 1) = gp.y();
//       nodesXYZ(iV, 2) = gp.z();
//       tanCAD[iV] = ge->firstDer(tCAD);                                                    // New tangent to CAD at perturbed node
//       tanCAD[iV].normalize();                                                             // Normalize new tangent
//       const double sDistDiff = taylorDistanceSq1D(gb, nodesXYZ, tanCAD);                  // Compute distance with perturbed node
//       gradDist[iV-nbPrimVert] = (sDistDiff-dist) / eps;                       // Compute gradient
//       nodesXYZ(iV, 0) = xS; nodesXYZ(iV, 1) = yS; nodesXYZ(iV, 2) = zS;                   // Restore coord. of perturbed node
//       tanCAD[iV] = tanCADS;                                                               // Restore tan. to CAD at perturbed node
//     }
//   }
//   else {                                                                                  // 3D
//     const GFace *gf = geomEnt->cast2Face();
//     const Range<double> parBounds0 = gf->parBounds(0), parBounds1 = gf->parBounds(1);
//     const double eps0 = 1.e-6 * (parBounds0.high()-parBounds0.low());
//     const double eps1 = 1.e-6 * (parBounds1.high()-parBounds1.low());
//     std::vector<SVector3> normCAD(nbVert);
//     for (int iV = 0; iV < nbVert; iV++) {
//       MVertex *vert = bndElt->getVertex(iV);
//       SPoint2 pCAD;
//       if (iV >= nbPrimVert) {                                                               // If HO vertex, get parameters
//         vert->getParameter(0, pCAD[0]);
//         vert->getParameter(1, pCAD[1]);
//       }
//       else
//         reparamMeshVertexOnFace(vert, gf, pCAD);                                          // If not free vertex, reparametrize on surface
//       normCAD[iV] = gf->normal(pCAD);                                                     // Compute normal at vertex
//       normCAD[iV].normalize();                                                            // Normalize normal
//     }
//     dist = taylorDistanceSq2D(gb, nodesXYZ, normCAD);
//     for (int iV = nbPrimVert; iV < nbVert; iV++) {
//       MVertex *vert = bndElt->getVertex(iV);
//       const double xS = nodesXYZ(iV, 0), yS = nodesXYZ(iV, 1),
//                    zS = nodesXYZ(iV, 2);                                                  // Save coord. of perturbed node for FD
//       const SVector3 normCADS = normCAD[iV];                                              // Save normal to CAD at perturbed node
//       SPoint2 pCAD0;                                                                      // New param. coord. of perturbed node in 1st dir.
//       vert->getParameter(0, pCAD0[0]);
//       pCAD0 += eps0;
//       vert->getParameter(1, pCAD0[1]);
//       GPoint gp0 = gf->point(pCAD0);                                                    // New coord. of perturbed node in 1st dir.
//       nodesXYZ(iV, 0) = gp0.x();
//       nodesXYZ(iV, 1) = gp0.y();
//       nodesXYZ(iV, 2) = gp0.z();
//       normCAD[iV] = gf->normal(pCAD0);                                                  // New normal to CAD at perturbed node in 1st dir.
//       normCAD[iV].normalize();                                                          // Normalize new normal
//       const double sDistDiff0 = taylorDistanceSq2D(gb, nodesXYZ, normCAD);              // Compute distance with perturbed node in 1st dir.
//       gradDist[2*(iV-nbPrimVert)] = (sDistDiff0-dist) / eps0;                           // Compute gradient in 1st dir.
//       SPoint2 pCAD1;                                                                    // New param. coord. of perturbed node in 2nd dir.
//       vert->getParameter(0, pCAD1[0]);
//       vert->getParameter(1, pCAD1[1]);
//       pCAD1 += eps1;
//       GPoint gp1 = gf->point(pCAD1);                                                    // New coord. of perturbed node in 2nd dir.
//       nodesXYZ(iV, 0) = gp1.x();
//       nodesXYZ(iV, 1) = gp1.y();
//       nodesXYZ(iV, 2) = gp1.z();
//       normCAD[iV] = gf->normal(pCAD1);                                                   // New normal to CAD at perturbed node in 2nd dir.
//       normCAD[iV].normalize();                                                           // Normalize new normal
//       double sDistDiff1 = taylorDistanceSq2D(gb, nodesXYZ, normCAD);                     // Compute distance with perturbed node in 2nd dir.
//       gradDist[2*(iV-nbPrimVert)+1] = (sDistDiff1-dist) / eps1;                          // Compute gradient in 2nd dir.
//       nodesXYZ(iV, 0) = xS;                                                              // Restore coord. of perturbed node
//       nodesXYZ(iV, 1) = yS;
//       nodesXYZ(iV, 2) = zS;
//       normCAD[iV] = normCADS;                                                            // Restore tan. to CAD at perturbed node
//     }
//   }
// }



double curveAndMeasureAboveEl(MetaEl &metaElt, MElement *lastElt,
                              MElement *aboveElt, double deformFact)
{
  metaElt.setCurvedTop(deformFact);
  std::set<MVertex*> movedVertDum;
  curveElement(metaElt, movedVertDum, lastElt);
  if (aboveElt == 0) return 1.;
  double minJacDet, maxJacDet;
  jacobianBasedQuality::minMaxJacobianDeterminant(aboveElt, minJacDet, maxJacDet);
  return minJacDet/maxJacDet;
}



void curveColumn(const FastCurvingParameters &p, GEntity *ent,
                 GEntity *bndEnt, int metaElType,
                 std::vector<MVertex*> &baseVert,
                 const std::vector<MVertex*> &topPrimVert, MElement *aboveElt,
                 std::vector<MElement*> &blob, std::set<MVertex*> &movedVert,
                 DbgOutputMeta &dbgOut)
{
  static const double MINQUAL = 0.01, TOL = 0.01, MAXITER = 10;

  // Order
  const int order = blob[0]->getPolynomialOrder();

  // If 2D P2 and allowed, modify base vertices to minimize distance between wall edge and CAD
  if ((p.optimizeGeometry) && (metaElType == TYPE_QUA) && (order == 2))
    optimizeCADDist2DP2(bndEnt, baseVert);

  // Create meta-element
  MetaEl metaElt(metaElType, order, baseVert, topPrimVert);

  // If required, curve top face of meta-element
  if (p.curveOuterBL != FastCurvingParameters::OUTER_NOCURVE) {
    MElement* &lastElt = blob.back();
    double minJacDet, maxJacDet;
    double deformMin = 0., qualDeformMin = 1.;
    double deformMax = 1.;
    double qualDeformMax = curveAndMeasureAboveEl(metaElt, lastElt, aboveElt,
                                                  deformMax);
    // Bisection on displacement to avoid breaking the element above if required
    if ((p.curveOuterBL == FastCurvingParameters::OUTER_CURVECONSERVATIVE) &&
        (qualDeformMax < MINQUAL)) {                                              // Max deformation makes element above invalid
      for (int iter = 0; iter < MAXITER; iter++) {                                // Bisection to find max. deformation that makes element above valid
        const double deformMid = 0.5 * (deformMin + deformMax);
        const double qualDeformMid = curveAndMeasureAboveEl(metaElt, lastElt,
                                                            aboveElt, deformMid);
        if (std::abs(deformMax-deformMin) < TOL) break;
        const bool signDeformMax = (qualDeformMax < MINQUAL);
        const bool signDeformMid = (qualDeformMid < MINQUAL);
        if (signDeformMid == signDeformMax) deformMax = deformMid;
        else deformMin = deformMid;
      }
      metaElt.setFlatTop();
    }
    for (int iV = 0; iV < lastElt->getNumVertices(); iV++)
      movedVert.insert(lastElt->getVertex(iV));
  }

  // Curve elements
  dbgOut.addMetaEl(metaElt);
  for (int iEl = 0; iEl < blob.size(); iEl++) {
    curveElement(metaElt, movedVert, blob[iEl]);
    ent->curvedBLElements.insert(blob[iEl]);
  }
}

void computeFirstAndLastIdealBezierCoeff(const std::vector<MVertex*> &baseVert,
                                         const std::vector<MVertex*> &topVert,
                                         std::vector<double> &bezierCoeffIdeal,
                                         double &thickness0, double &thickness1)
{
  int tag = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  double sf[100][3];
  fs->df(-1, 0, 0, sf);
  double dxa = 0, dya = 0, dza = 0;
  for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
    const MVertex *v = baseVert[j];
    dxa += sf[j][0] * v->x();
    dya += sf[j][0] * v->y();
    dza += sf[j][0] * v->z();
  }

  SVector3 da = SVector3(dxa, dya, dza);
  SVector3 db = SVector3(topVert[0]->x() - baseVert[0]->x(),
                         topVert[0]->y() - baseVert[0]->y(),
                         topVert[0]->z() - baseVert[0]->z());
  db *= .5; // edge length of the reference quad is 2...
  bezierCoeffIdeal.push_back(norm(crossprod(da, db)));
  thickness0 = bezierCoeffIdeal[0] / norm(da);


  fs->df(1, 0, 0, sf);
  dxa = 0;
  dya = 0;
  dza = 0;
  for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
    const MVertex *v = baseVert[j];
    dxa += sf[j][0] * v->x();
    dya += sf[j][0] * v->y();
    dza += sf[j][0] * v->z();
  }

  da = SVector3(dxa, dya, dza);
  db = SVector3(topVert[1]->x() - baseVert[1]->x(),
                topVert[1]->y() - baseVert[1]->y(),
                topVert[1]->z() - baseVert[1]->z());
  db *= .5; // edge length of the reference quad is 2...
  bezierCoeffIdeal.push_back(norm(crossprod(da, db)));
  thickness1 = bezierCoeffIdeal[1] / norm(da);
}

double linearInterp(const double &value0,
                    const double &value1,
                    const double &xi)
{
  return value0 * (.5-xi/2) + value1 * (xi/2+.5);
}

void idealJacobianDeterminant(const std::vector<MVertex*> &baseVert,
                              double &thickness0, double &thickness1,
                              std::vector<double> &xi,
                              std::vector<double> &idealJacDet)
{
  int tag = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  for (int i = 0; i < xi.size(); ++i) {
    double sf[100][3];
    fs->df(xi[i], 0, 0, sf);
    double dx = 0, dy = 0, dz = 0;
    for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
      const MVertex *v = baseVert[j];
      dx += sf[j][0] * v->x();
      dy += sf[j][0] * v->y();
      dz += sf[j][0] * v->z();
    }
//    std::cout << " |" << xi[i] << ", " << std::sqrt(dx*dx + dy*dy + dz*dz);
//    std::cout << ", " << linearInterp(thickness0, thickness1, xi[i]) << "|";
    idealJacDet[i] = std::sqrt(dx*dx + dy*dy + dz*dz)
           * linearInterp(thickness0, thickness1, xi[i]);
  }
}

void computeOtherIdealBezierCoeff(const std::vector<MVertex*> &baseVert,
                                  std::vector<double> &bezierCoeffIdeal,
                                  double &thickness0, double &thickness1)
{
  // Find the polynomial curve that fit the best J_ideal = D_xi(x) * e(xi)
  // where x(xi) is the mapping, D_xi the derivative with respect to xi
  // and e is the thickness: e(xi) = thickness0 * (1-xi) + thickness1 * xi
  //
  // -> We use Remez's algorithm

  int bezierOrder = 2*baseVert.size()-3;
  int sizeSystem = bezierOrder;
  std::vector<double> xi(sizeSystem);
  for (int i = 0; i < sizeSystem; ++i) {
    // initial guess
    // TODO use extrema of the Chebyshev polynomial
    xi[i] = 2*(static_cast<double>(i+1)/(sizeSystem+1))-1;
  }

  // Construct system to solve
  fullMatrix<double> A(sizeSystem, sizeSystem);
  fullVector<double> b(sizeSystem), x(sizeSystem);
  int tagBez = ElementType::getTag(TYPE_LIN, bezierOrder);
  const bezierBasis *bfs = BasisFactory::getBezierBasis(tagBez);

  for (int cnt = 0; cnt < 4; ++cnt) {
    std::vector<double> f(sizeSystem);
    idealJacobianDeterminant(baseVert, thickness0, thickness1, xi, f);
    for (int i = 0; i < sizeSystem; ++i) {
      double bsf[100];
      bfs->f(xi[i], 0, 0, bsf);
      b(i) = f[i] - bezierCoeffIdeal[0] * bsf[0] - bezierCoeffIdeal[1] * bsf[1];
      for (int j = 0; j < sizeSystem - 1; ++j) {
        A(i, j) = bsf[j + 2];
      }
      A(i, sizeSystem - 1) = i % 2 ? 1 : -1;
    }

    A.luSolve(b, x);
    double debug_epsilon = x(sizeSystem - 1);


//    std::cout << std::setprecision(10);
//    std::cout << std::endl;
//    std::cout << "b_i " << bezierCoeffIdeal[0];
//    std::vector<double> debug_x = {bezierCoeffIdeal[0]};
//    for (int i = 0; i < sizeSystem - 1; ++i) {
//      debug_x.push_back(x(i));
//      std::cout << " " << x(i);
//    }
//    std::cout << " " << bezierCoeffIdeal[1] << std::endl;
//    double step = .01;
//    int N = 200;
//    std::vector<double> xiDebug = {-1};
//    for (int i = 0; i < N; ++i) {
//      xiDebug.push_back(xiDebug.back() + step);
//    }
//    std::vector<double> fDebug(xiDebug.size());
//    idealJacobianDeterminant(baseVert, thickness0, thickness1, xiDebug, fDebug);
//    std::cout << "f(x)";
//    for (int i = 0; i < fDebug.size(); ++i) {
//      std::cout << " " << fDebug[i];
//    }
//    std::cout << std::endl;

//    std::cout << std::endl;
    double dxi = 1. / sizeSystem / 100;
    for (int i = 0; i < sizeSystem; ++i) {
      std::vector<double> xi2 = {xi[i] - dxi, xi[i] + dxi};
      std::vector<double> f(2);
      idealJacobianDeterminant(baseVert, thickness0, thickness1, xi2, f);

      double bsfl[100];
      double bsfr[100];
      bfs->f(xi2[0], 0, 0, bsfl);
      bfs->f(xi2[1], 0, 0, bsfr);
      double Fleft = bezierCoeffIdeal[0] * bsfl[0] + bezierCoeffIdeal[1] * bsfl[1];
      double Fright = bezierCoeffIdeal[0] * bsfr[0] + bezierCoeffIdeal[1] * bsfr[1];
      for (int j = 0; j < sizeSystem - 1; ++j) {
        Fleft += x(j) * bsfl[j + 2];
        Fright += x(j) * bsfr[j + 2];
      }
      double stop = 1;
      Fleft -= f[0];
      Fright -= f[1];


      double Fm = std::abs(x(sizeSystem - 1));
      if (Fright + Fleft < 0) Fm = -Fm;
      double dF = (Fright - Fleft) / dxi / 2;
      //double ddF = (Fright + Fleft - 2*Fm)/dxi/dxi;
      //xi[i] -= dF/ddF; // does not work since can be on the opposite than the top
      int direction = (Fm > 0 && dF > 0) || (Fm < 0 && dF < 0) ? 1 : -1;
      double step = 1. / sizeSystem / 100;
      double previousF, F = Fm;
      std::vector<double> newxi = {xi[i]};
      do {
        previousF = F;
        newxi[0] += direction * step;
        std::vector<double> newf(1);
        idealJacobianDeterminant(baseVert, thickness0, thickness1, newxi, newf);
        double bsf[100];
        bfs->f(newxi[0], 0, 0, bsf);
        double shouldBeOne = bsf[0] + bsf[1];
        F = bezierCoeffIdeal[0] * bsf[0] + bezierCoeffIdeal[1] * bsf[1];
        for (int j = 0; j < sizeSystem - 1; ++j) {
          F += x(j) * bsf[j + 2];
          shouldBeOne += bsf[j+2];
        }
        double debug_F = F-newf[0];
        F -= newf[0];
      } while ((Fm > 0 && F > previousF) || (Fm < 0 && F < previousF));

      xi[i] = newxi[0];

      //std::cout << xi[i] << ":" << dF << ":" << ddF << " ";
    }
//    std::cout << std::endl << std::endl;
  }


  double minCoeff = x(0);
  for (int i = 0; i < sizeSystem-1; ++i) {
    bezierCoeffIdeal.push_back(x(i));
    minCoeff = std::min(minCoeff, x(i));
  }
  std::cout << "epsilon: " << -x(sizeSystem-1) << " [" << -x(sizeSystem-1)/minCoeff << "] ";
}


void computeIdealJacobian(const std::vector<MVertex*> &baseVert,
                          const std::vector<MVertex*> &topVert,
                          std::vector<double> &bezierCoeffIdeal)
{
  double thickness0, thickness1;
  // order_element = baseVert.size - 1
  // order_jacobian = 2 * order_element - 1
  // number_of_bezier_coeff = order_jacobian + 1
  bezierCoeffIdeal.reserve(2 * baseVert.size() - 2);
  computeFirstAndLastIdealBezierCoeff(baseVert, topVert, bezierCoeffIdeal,
                                      thickness0, thickness1);
  computeOtherIdealBezierCoeff(baseVert, bezierCoeffIdeal, thickness0,
                               thickness1);
}

void idealPositionTopEdge(const std::vector<MVertex *> &baseVert,
                          double &thickness0, double &thickness1,
                          double &tanAngle0, double &tanAngle1,
                          std::vector<double> &xi,
                          int nComponent,
                          std::vector<double> &idealPosition)
{
  int tag = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  for (int i = 0; i < xi.size(); ++i) {
    double f[100];
    double sf[100][3];
    fs->f(xi[i], 0, 0, f);
    fs->df(xi[i], 0, 0, sf);
    double x = 0, y = 0, z = 0;
    double dx = 0, dy = 0, dz = 0;
    for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
      const MVertex *v = baseVert[j];
      x += f[j] * v->x();
      y += f[j] * v->y();
      z += f[j] * v->z();
      dx += sf[j][0] * v->x();
      dy += sf[j][0] * v->y();
      dz += sf[j][0] * v->z();
    }
//    std::cout << " |" << xi[i] << ", " << std::sqrt(dx*dx + dy*dy + dz*dz);
//    std::cout << ", " << linearInterp(thickness0, thickness1, xi[i]) << "|";
    double coeff = linearInterp(thickness0, thickness1, xi[i])
                       / std::sqrt(dx*dx + dy*dy + dz*dz);
    double b = linearInterp(tanAngle0, tanAngle1, xi[i]);
    if (nComponent == 0) {
      idealPosition[i] = x + coeff * (-dy - b * dx);
    }
    if (nComponent == 1) {
      idealPosition[i] = y + coeff * (dx - b * dy);
    }
  }
}

void computeThicknessAngle(const std::vector<MVertex*> &baseVert,
                           const std::vector<MVertex*> &topVert,
                           double &thickness0, double &thickness1,
                           double &tanAngle0, double &tanAngle1)
{
  int tag = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  SVector3 r(0,0,1);

  double sf[100][3];
  fs->df(-1, 0, 0, sf);
  double dxa = 0, dya = 0, dza = 0;
  for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
    const MVertex *v = baseVert[j];
    dxa += sf[j][0] * v->x();
    dya += sf[j][0] * v->y();
    dza += sf[j][0] * v->z();
  }

  SVector3 da = SVector3(dxa, dya, dza);
  da *= 1/norm(da);
  SVector3 db = SVector3(topVert[0]->x() - baseVert[0]->x(),
                         topVert[0]->y() - baseVert[0]->y(),
                         topVert[0]->z() - baseVert[0]->z());
  SVector3 dc = crossprod(da, db);
  thickness0 = dot(dc, r);

  SVector3 n = crossprod(dc, da); // n is of length thickness0
  SVector3 diff = n - db;
  tanAngle0 = dot(diff, da) / thickness0;

  fs->df(1, 0, 0, sf);
  dxa = 0;
  dya = 0;
  dza = 0;
  for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
    const MVertex *v = baseVert[j];
    dxa += sf[j][0] * v->x();
    dya += sf[j][0] * v->y();
    dza += sf[j][0] * v->z();
  }

  da = SVector3(dxa, dya, dza);
  da *= 1/norm(da);
  db = SVector3(topVert[1]->x() - baseVert[1]->x(),
                topVert[1]->y() - baseVert[1]->y(),
                topVert[1]->z() - baseVert[1]->z());
  dc = crossprod(da, db);
  thickness1 = dot(dc, r);

  n = crossprod(dc, da); // n is of length thickness1
  diff = n - db;
  tanAngle1 = dot(diff, da) / thickness1;
}

void computePositionTopVert(const std::vector<MVertex*> &baseVert,
                            const std::vector<MVertex*> &topVert,
                            double &thickness0, double &thickness1,
                            double &tanAngle0, double &tanAngle1)
{
  // For each component, find the polynomial function that fit best
  //   x1(xi) = x0(xi) + h(xi) / cos(alpha) * R^alpha n(xi)
  // where x0(xi) is the position of the base edge
  //       h(xi) is the linear thickness
  //       alpha(xi) is the angle between x1-x0 and the normal n
  //       n(xi) is the unit normal of the base edge
  //
  // -> We use Remez's algorithm

  int order = baseVert.size()-1;
  int sizeSystem = order;

  std::vector<double> xi(sizeSystem);
  fullMatrix<double> A(sizeSystem, sizeSystem);
  fullVector<double> b(sizeSystem), x(sizeSystem);
  int tagBez = ElementType::getTag(TYPE_LIN, order);
  const bezierBasis *fs = BasisFactory::getBezierBasis(tagBez);

  double xy0[2] = {topVert[0]->x(), topVert[0]->y()};
  double xy1[2] = {topVert[1]->x(), topVert[1]->y()};

  // Solve for x and y separately
  for (int iComp = 0; iComp < 2; ++iComp) {

    // initial guess
    for (int i = 0; i < sizeSystem; ++i) {
      // TODO use extrema of the Chebyshev polynomial
      xi[i] = 2 * (static_cast<double>(i + 1) / (sizeSystem + 1)) - 1;
    }

    // TODO better thing that cnt = 0->3
    for (int cnt = 0; cnt < 4; ++cnt) {
      // Construct system to solve
      std::vector<double> f(sizeSystem);
      idealPositionTopEdge(baseVert, thickness0, thickness1,
                           tanAngle0, tanAngle1, xi, iComp, f);
      for (int i = 0; i < sizeSystem; ++i) {
        double bsf[100];
        fs->f(xi[i], 0, 0, bsf);
        b(i) = f[i] - xy0[iComp] * bsf[0] - xy1[iComp] * bsf[1];
        for (int j = 0; j < sizeSystem - 1; ++j) {
          A(i, j) = bsf[j + 2];
        }
        A(i, sizeSystem - 1) = i % 2 ? 1 : -1;
      }

      A.luSolve(b, x);

      //    double debug_epsilon = x(sizeSystem - 1);
      //    std::cout << std::setprecision(10);
      //    std::cout << std::endl;
      //    std::cout << "b_i " << xy0[iComp];
      //    std::vector<double> debug_x = {xy0[iComp]};
      //    for (int i = 0; i < sizeSystem - 1; ++i) {
      //      debug_x.push_back(x(i));
      //      std::cout << " " << x(i);
      //    }
      //    std::cout << " " << xy1[iComp] << std::endl;
      //    int N = 24;
      //    double step = 2. / N;
      //    std::vector<double> xiDebug = {-1};
      //    for (int i = 0; i < N; ++i) {
      //      xiDebug.push_back(xiDebug.back() + step);
      //    }
      //    std::vector<double> fDebug(xiDebug.size());
      //    idealPositionTopEdge(baseVert, thickness0, thickness1,
      //                         tanAngle0, tanAngle1, xiDebug, iComp, fDebug);
      //    std::cout << "eps " << debug_epsilon << std::endl;
      //    std::cout << "f(x)";
      //    for (int i = 0; i < fDebug.size(); ++i) {
      //      double bsf[100];
      //      fs->f(xiDebug[i], 0, 0, bsf);
      ////      double shouldBeOne = bsf[0] + bsf[1];
      //      double P = xy0[iComp] * bsf[0] + xy1[iComp] * bsf[1];
      ////      std::cout << "[" << bsf[0] << ", " << bsf[1];
      //      for (int j = 0; j < sizeSystem - 1; ++j) {
      //        P += x(j) * bsf[j + 2];
      ////        std::cout << ", " << bsf[j + 2];
      ////        shouldBeOne += bsf[j+2];
      //      }
      ////      std::cout << "]";
      //      std::cout << " " << (P - fDebug[i]) / debug_epsilon;
      ////      std::cout << " (" << P << " - " << fDebug[i] << ") ";
      //    }
      //    std::cout << std::endl;
      //    std::cout << std::endl;


      double dxi = 1. / sizeSystem / 100;
      for (int i = 0; i < sizeSystem; ++i) {
        std::vector<double> xi2 = {xi[i] - dxi, xi[i] + dxi};
        std::vector<double> f(2);
        idealPositionTopEdge(baseVert, thickness0, thickness1,
                             tanAngle0, tanAngle1, xi2, iComp, f);

        double bsfl[100];
        double bsfr[100];
        fs->f(xi2[0], 0, 0, bsfl);
        fs->f(xi2[1], 0, 0, bsfr);
        double Fleft = xy0[iComp] * bsfl[0] + xy1[iComp] * bsfl[1];
        double Fright = xy0[iComp] * bsfr[0] + xy1[iComp] * bsfr[1];
        for (int j = 0; j < sizeSystem - 1; ++j) {
          Fleft += x(j) * bsfl[j + 2];
          Fright += x(j) * bsfr[j + 2];
        }
        Fleft -= f[0];
        Fright -= f[1];

        double Fm = std::abs(x(sizeSystem - 1)); // the last is epsilon
        if (Fright + Fleft < 0) Fm = -Fm;
        double dF = (Fright - Fleft) / dxi / 2;
        //double ddF = (Fright + Fleft - 2*Fm)/dxi/dxi;
        //xi[i] -= dF/ddF; // does not work since can be on the opposite than the top
        int direction = (Fm * dF > 0) ? 1 : -1;
        double step = 1. / sizeSystem / 100;
        double previousF, F = Fm;
        std::vector<double> newxi = {xi[i]};
        do {
          previousF = F;
          newxi[0] += direction * step;
          std::vector<double> newf(1);
          idealPositionTopEdge(baseVert, thickness0, thickness1,
                               tanAngle0, tanAngle1, newxi, iComp, newf);
          double bsf[100];
          fs->f(newxi[0], 0, 0, bsf);
          //        double shouldBeOne = bsf[0] + bsf[1];
          F = xy0[iComp] * bsf[0] + xy1[iComp] * bsf[1];
          for (int j = 0; j < sizeSystem - 1; ++j) {
            F += x(j) * bsf[j + 2];
            //          shouldBeOne += bsf[j+2];
          }
          //        double debug_F = F-newf[0];
          F -= newf[0];
        } while ((Fm > 0 && F > previousF) || (Fm < 0 && F < previousF));

        xi[i] = newxi[0];
      }
    }

    for (int i = 1; i < order; ++i) {
      double bsf[100];
      double xi = -1 + 2. * i / order;
      fs->f(xi, 0, 0, bsf);
      double P = xy0[iComp] * bsf[0] + xy1[iComp] * bsf[1];
      for (int j = 0; j < sizeSystem - 1; ++j) {
        P += x(j) * bsf[j + 2];
      }
      if (iComp == 0) topVert[i + 1]->x() = P;
      else            topVert[i + 1]->y() = P;
    }
  }
}

void replaceIntermediateNode(const MElement *element, int iBaseEdge)
{
  bool intermediateAlongY = true;
  if (iBaseEdge == 1 || iBaseEdge == 3) intermediateAlongY = false;

  int order = element->getPolynomialOrder();

  // Create a map of discrete coordinate to the number of node
  // This is really really inefficient.. (could be done only one time per element type)
  const nodalBasis *fs = BasisFactory::getNodalBasis(element->getTypeForMSH());
  std::map<std::pair<int, int>, int> coordinate2num;
  std::map<int, std::pair<int, int>> num2coordinate;
  for (int i = 0; i < element->getNumVertices(); ++i) {
    const int x = std::lround((fs->points(i, 0) + 1) / 2. * order);
    const int y = std::lround((fs->points(i, 1) + 1) / 2. * order);
    coordinate2num[std::make_pair(x, y)] = i;
    num2coordinate[i] = std::make_pair(x, y);
  }

  if (intermediateAlongY) {
    for (int i = 0; i < element->getNumVertices(); ++i) {
      MVertex *v = const_cast<MVertex*>(element->getVertex(i));
      const std::pair<int, int> coordinates(num2coordinate[i]);
      const int &x = coordinates.first;
      const int &y = coordinates.second;
      const std::pair<int, int> coordinates0(x, 0);
      const std::pair<int, int> coordinates1(x, order);
      const MVertex *v0 = element->getVertex(coordinate2num[coordinates0]);
      const MVertex *v1 = element->getVertex(coordinate2num[coordinates1]);
      double factor = static_cast<double>(y) / order;
      v->x() = v0->x() * (1-factor) + v1->x() * factor;
      v->y() = v0->y() * (1-factor) + v1->y() * factor;
      v->z() = v0->z() * (1-factor) + v1->z() * factor;
    }
  }
  else {
    for (int i = 0; i < element->getNumVertices(); ++i) {
      MVertex *v = const_cast<MVertex*>(element->getVertex(i));
      const std::pair<int, int> coordinates(num2coordinate[i]);
      const int &x = coordinates.first;
      const int &y = coordinates.second;
      const std::pair<int, int> coordinates0(0, y);
      const std::pair<int, int> coordinates1(order, y);
      const MVertex *v0 = element->getVertex(coordinate2num[coordinates0]);
      const MVertex *v1 = element->getVertex(coordinate2num[coordinates1]);
      double factor = static_cast<double>(x) / order;
      v->x() = v0->x() * (1-factor) + v1->x() * factor;
      v->y() = v0->y() * (1-factor) + v1->y() * factor;
      v->z() = v0->z() * (1-factor) + v1->z() * factor;
    }
  }
}

void computeBezierCoefficientsOfJacobian(const MElement *element,
                                         fullVector<double> &bezierCoefficients,
                                         fullMatrix<double> *normals)
{
  const JacobianBasis *jfs;
  jfs = BasisFactory::getJacobianBasis(element->getTypeForMSH());

  fullMatrix<double> nodesXYZ(element->getNumVertices(), 3);
  element->getNodesCoord(nodesXYZ);

  fullVector<double> coeffLag(jfs->getNumJacNodes());
  bezierCoefficients.resize(jfs->getNumJacNodes());
  jfs->getSignedJacobian(nodesXYZ, coeffLag, normals);
  jfs->lag2Bez(coeffLag, bezierCoefficients);
}

double computeFunctional(const MElement *element,
                         const fullVector<double> &bezierCoefficients,
                         const std::vector<double> &bezierCoeffIdeal,
                         int iBaseEdge)
{
  bool intermediateAlongY = true;
  if (iBaseEdge == 1 || iBaseEdge == 3) intermediateAlongY = false;

  int order = element->getPolynomialOrder();

  // Create a map of discrete coordinate to the number of node
  // This is really really inefficient.. (could be done only one time per element type)
  int tag = ElementType::getTag(element->getType(), 2*order-1);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);
  int numCoeff = fs->getNumShapeFunctions();
  std::vector<int> num2ideal(numCoeff);
  for (int i = 0; i < numCoeff; ++i) {
    const int x = std::lround((fs->points(i, 0) + 1) / 2. * order);
    const int y = std::lround((fs->points(i, 1) + 1) / 2. * order);
    switch (iBaseEdge) {
      case 0: num2ideal[i] = x; break;
      case 1: num2ideal[i] = y; break;
      case 2: num2ideal[i] = order-x; break;
      case 3: num2ideal[i] = order-y; break;
    }
    if (num2ideal[i] > 0) ++num2ideal[i];
    if (num2ideal[i] == order+1) num2ideal[i] = 1;
  }

  double functional = 0;
  for (int i = 0; i < numCoeff; ++i) {
//    double bezCoeff = bezierCoefficients(i);
//    double ideal = bezierCoeffIdeal[num2ideal[i]];
    const double tmp = bezierCoefficients(i)/bezierCoeffIdeal[num2ideal[i]] - 1;
    functional += tmp*tmp;
  }
  return functional;
}

void computeDirections(const MElement *element,
                       const std::vector<MVertex*> &baseVert,
                       const std::vector<MVertex*> &topVert,
                       const std::vector<double> &bezierCoeffIdeal,
                       int iBaseEdge,
                       std::vector<double> &direction,
                       fullMatrix<double> *normals,
                       double lambda)
{
  std::vector<double> distances(baseVert.size());
  for (int i = 0; i < topVert.size(); ++i) {
    const double dx = topVert[i]->x() - baseVert[i]->x();
    const double dy = topVert[i]->y() - baseVert[i]->y();
    const double dz = topVert[i]->z() - baseVert[i]->z();
    distances[i] = std::sqrt(dx*dx + dy*dy + dz*dz);
  }
  const double delta = std::min(distances[0], distances[1])/1000;
  const double characteristicLength = 2 * *(std::max_element(distances.begin(),
                                                               distances.end()));

  fullVector<double> bezierCoefficients;
  double maxNormDfSqr = 0;
  for (int i = 2; i < topVert.size(); ++i) {
    const double x = topVert[i]->x();
    const double y = topVert[i]->y();
    const double z = topVert[i]->z();

    topVert[i]->x() += delta;
    replaceIntermediateNode(element, iBaseEdge);
    computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
    const double fxRight = computeFunctional(element, bezierCoefficients,
                                             bezierCoeffIdeal, iBaseEdge);
    topVert[i]->x() -= 2*delta;
    replaceIntermediateNode(element, iBaseEdge);
    computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
    const double fxLeft = computeFunctional(element, bezierCoefficients,
                                            bezierCoeffIdeal, iBaseEdge);
    topVert[i]->x() = x;

    topVert[i]->y() += delta;
    replaceIntermediateNode(element, iBaseEdge);
    computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
    const double fyRight = computeFunctional(element, bezierCoefficients,
                                             bezierCoeffIdeal, iBaseEdge);
    topVert[i]->y() -= 2*delta;
    replaceIntermediateNode(element, iBaseEdge);
    computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
    const double fyLeft = computeFunctional(element, bezierCoefficients,
                                            bezierCoeffIdeal, iBaseEdge);
    topVert[i]->y() = y;

    topVert[i]->z() += delta;
    replaceIntermediateNode(element, iBaseEdge);
    computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
    const double fzRight = computeFunctional(element, bezierCoefficients,
                                             bezierCoeffIdeal, iBaseEdge);
    topVert[i]->z() -= 2*delta;
    replaceIntermediateNode(element, iBaseEdge);
    computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
    const double fzLeft = computeFunctional(element, bezierCoefficients,
                                            bezierCoeffIdeal, iBaseEdge);
    topVert[i]->z() = z;

    const double &dfx = direction[3*(i-2)]   = (fxLeft-fxRight)/2/delta;
    const double &dfy = direction[3*(i-2)+1] = (fyLeft-fyRight)/2/delta;
    const double &dfz = direction[3*(i-2)+2] = (fzLeft-fzRight)/2/delta;
    maxNormDfSqr = std::max(maxNormDfSqr, dfx*dfx + dfy*dfy + dfz*dfz);
  }

  const double factor = lambda * characteristicLength / std::sqrt(maxNormDfSqr);
  for (int i = 0; i < direction.size(); ++i) {
    direction[i] *= factor;
  }
}

double objectiveFunction(double xi, MElement *element,
                         std::vector<MVertex*> &topVert,
                         std::vector<double> &direction,
                         std::vector<double> &bezierCoeffIdeal,
                         int iBaseEdge,
                         fullMatrix<double> *normals)
{
  std::vector<double> coordinate(direction.size());

  for (int i = 2; i < topVert.size(); ++i) {
    double j0 = 3*(i-2);
    coordinate[j0] = topVert[i]->x();
    coordinate[j0+1] = topVert[i]->y();
    coordinate[j0+2] = topVert[i]->z();
    topVert[i]->x() += direction[j0] * xi;
    topVert[i]->y() += direction[j0+1] * xi;
    topVert[i]->z() += direction[j0+2] * xi;
  }

  fullVector<double> bezierCoefficients;
  replaceIntermediateNode(element, iBaseEdge);
  computeBezierCoefficientsOfJacobian(element, bezierCoefficients, normals);
  const double f = computeFunctional(element, bezierCoefficients,
                                     bezierCoeffIdeal, iBaseEdge);

  for (int i = 2; i < topVert.size(); ++i) {
    double j0 = 3*(i-2);
    topVert[i]->x() = coordinate[j0];
    topVert[i]->y() = coordinate[j0+1];
    topVert[i]->z() = coordinate[j0+2];
  }
  return f;
}

void moveTopVertAfterGoldenSection(MElement *element,
                                   double xi, std::vector<MVertex*> &topVert,
                                   std::vector<double> &direction,
                                   int iBaseEdge)
{
  for (int i = 2; i < topVert.size(); ++i) {
    double j0 = 3*(i-2);
    topVert[i]->x() += direction[j0] * xi;
    topVert[i]->y() += direction[j0+1] * xi;
    topVert[i]->z() += direction[j0+2] * xi;
  }
  replaceIntermediateNode(element, iBaseEdge);
}

struct GoldenSectionSearchData {
  double factor;
  double functionalBefore;
  double functionalAfter;
  double xi;
};

void optimizeTopVertices(MElement *element,
                         std::vector<MVertex*> &baseVert,
                         std::vector<MVertex*> &topVert,
                         std::vector<double> &bezierCoeffIdeal,
                         std::set<MVertex*> &movedVert,
                         int iBaseEdge,
                         fullMatrix<double> *normals,
                         GoldenSectionSearchData &data)
{
  // TODO update movedVert
  std::vector<double> direction((topVert.size()-2)*3);
  computeDirections(element, baseVert, topVert, bezierCoeffIdeal,
                    iBaseEdge, direction, normals, data.factor);

  // Golden section
  const double tol = .001;
  const double astart = 0;
  const double fstart = objectiveFunction(0, element, topVert, direction,
                                          bezierCoeffIdeal, iBaseEdge, normals);

  static const double lambda = 0.5 * (std::sqrt(5) - 1.0);
  double a = astart;
  double b = 1;

  double xi1 = b - lambda * (b - a);
  double xi2 = a + lambda * (b - a);
  double f1 = objectiveFunction(xi1, element, topVert, direction,
                                bezierCoeffIdeal, iBaseEdge, normals);
  double f2 = objectiveFunction(xi2, element, topVert, direction,
                                bezierCoeffIdeal, iBaseEdge, normals);

  while (fabs(xi2 - xi1) > tol) {
    if (f1 < f2) {
      b = xi2;
      xi2 = xi1;
      f2 = f1;
      xi1 = b - lambda * (b - a);
      f1 = objectiveFunction(xi1, element, topVert, direction,
                             bezierCoeffIdeal, iBaseEdge, normals);
    }
    else {
      a = xi1;
      xi1 = xi2;
      f1 = f2;
      xi2 = a + lambda * (b - a);
      f2 = objectiveFunction(xi2, element, topVert, direction,
                             bezierCoeffIdeal, iBaseEdge, normals);
    }
  }


  double &xi = data.xi = f1 < f2 ? xi1 : xi2;
  double f = std::min(f1, f2);
  if (fstart < f ) {
    xi = astart;
    f = fstart;
  }
  moveTopVertAfterGoldenSection(element, xi, topVert, direction, iBaseEdge);
  //std::cout << " (" << f << "/" << fstart << ")";
  data.functionalBefore = fstart;
  data.functionalAfter = f;
}

void initialGuessTopVertices(std::vector<MVertex*> &baseVert,
                             std::vector<MVertex*> &topVert,
                             std::set<MVertex*> &movedVert)
{
  std::vector<double> v0(3),  v1(3);
  v0[0] = topVert[0]->x() - baseVert[0]->x();
  v0[1] = topVert[0]->y() - baseVert[0]->y();
  v0[2] = topVert[0]->z() - baseVert[0]->z();
  v1[0] = topVert[1]->x() - baseVert[1]->x();
  v1[1] = topVert[1]->y() - baseVert[1]->y();
  v1[2] = topVert[1]->z() - baseVert[1]->z();

  for (int i = 2; i < baseVert.size(); ++i) {
    double xi = (i-1)/(baseVert.size()-1);
    topVert[i]->x() = baseVert[i]->x() + (1-xi) * v0[0] + xi * v1[0];
    topVert[i]->y() = baseVert[i]->y() + (1-xi) * v0[1] + xi * v1[1];
    topVert[i]->z() = baseVert[i]->z() + (1-xi) * v0[2] + xi * v1[2];
    movedVert.insert(topVert[i]);
  }
}

void curveColumnRobustRecursive(int metaElType, std::vector<MVertex*> &baseVert,
                                std::vector<MElement*> &blob,
                                std::set<MVertex*> &movedVert,
                                DbgOutputMeta &dbgOut,
                                fullMatrix<double> *normals)
{
  MElement *el = blob[0];

  MEdge baseEdge(baseVert[0], baseVert[1]);
  int dummy, sign;
  el->getEdgeInfo(baseEdge, dummy, sign);
  if (sign == -1) {
    std::reverse(baseVert.begin(), baseVert.begin()+2);
    std::reverse(baseVert.begin()+2, baseVert.end());
  }

  MEdge topEdge;
  double minDummy, maxDummy;
  getOppositeEdgeQuad(el, baseEdge, topEdge, minDummy, maxDummy);
  std::vector<MVertex*> topVert;
  int iEdgeInElement;
  el->getEdgeInfo(topEdge, iEdgeInElement, dummy);
  el->getEdgeVertices(iEdgeInElement, topVert);
  std::reverse(topVert.begin(), topVert.begin()+2);
  std::reverse(topVert.begin()+2, topVert.end());

  bool newAlgo = true;
  if (newAlgo) {
//    std::cout << "EL " << el->getNum() << std::endl;
    double thickness0, thickness1, tanAngle0, tanAngle1;
    computeThicknessAngle(baseVert, topVert, thickness0,
                          thickness1, tanAngle0, tanAngle1);

    computePositionTopVert(baseVert, topVert, thickness0,
                           thickness1, tanAngle0, tanAngle1);

    replaceIntermediateNode(el, (iEdgeInElement + 2) % 4);
  }
  else {
    std::vector<double> bezierCoeffIdeal;
    computeIdealJacobian(baseVert, topVert, bezierCoeffIdeal);

    std::cout << "bezierCoeffIdeal el " << el->getNum() << ":";
    for (int i = 0; i < bezierCoeffIdeal.size(); ++i) {
      std::cout << " " << bezierCoeffIdeal[i];
    }
    std::cout << std::endl;

    initialGuessTopVertices(baseVert, topVert, movedVert);

    GoldenSectionSearchData data;
    data.factor = 1;
    data.functionalAfter = 1;
    double gain = 1;
    static double max = 0;
    while (gain > 1e-4 && data.functionalAfter > 1e-4) {
      optimizeTopVertices(el, baseVert, topVert, bezierCoeffIdeal, movedVert,
                          (iEdgeInElement + 2) % 4, normals, data);
      gain = (data.functionalBefore - data.functionalAfter) /
             data.functionalBefore;
      //std::cout << " " << data.functionalAfter << ":" << gain << ":" << data.factor;
      data.factor *= std::sqrt(data.xi / .5);
    }
    max = std::max(data.functionalAfter, max);
    std::cout << "<<" << data.functionalAfter << ":" << gain << ">> " << max;
    std::cout << std::endl;
  }

  if (blob.size() > 1) {
    blob.erase(blob.begin());
    baseVert = topVert;
    curveColumnRobustRecursive(metaElType, baseVert, blob, movedVert, dbgOut,
                               normals);
  }
}



void curveColumnRobust(const FastCurvingParameters &p, GEntity *geomEnt,
                       int metaElType, std::vector<MVertex*> &baseVert,
                       const std::vector<MVertex*> &topPrimVert, MElement *aboveElt,
                       std::vector<MElement*> &blob, std::set<MVertex*> &movedVert,
                       DbgOutputMeta &dbgOut,
                       fullMatrix<double> *normals)
{
  /*static const double MINQUAL = 0.01, TOL = 0.01, MAXITER = 10;*/

  // Order
  const int order = blob[0]->getPolynomialOrder();

  // If 2D P2 and allowed, modify base vertices to minimize distance between wall edge and CAD
  if ((p.optimizeGeometry) && (metaElType == TYPE_QUA) && (order == 2))
    optimizeCADDist2DP2(geomEnt, baseVert);

  curveColumnRobustRecursive(metaElType, baseVert, blob, movedVert, dbgOut,
                             normals);
}



void curveMeshFromBndElt(MEdgeVecMEltMap &ed2el, MFaceVecMEltMap &face2el,
                         GEntity *ent, GEntity *bndEnt,
                         MElement *bndElt, std::set<MVertex*> movedVert,
                         const FastCurvingParameters &p,
                         DbgOutputMeta &dbgOut,
                         fullMatrix<double> *normals)
{
  const int bndType = bndElt->getType();
  int metaElType;
  bool foundCol;
  std::vector<MVertex*> baseVert, topPrimVert;
  std::vector<MElement*> blob;
  MElement *aboveElt = 0;
  if (bndType == TYPE_LIN) { // 1D boundary
    MVertex *vb0 = bndElt->getVertex(0);
    MVertex *vb1 = bndElt->getVertex(1);
    metaElType = TYPE_QUA;
    MEdge baseEd(vb0, vb1);
    foundCol = getColumn2D(ed2el, p, baseEd, baseVert,
                           topPrimVert, blob, aboveElt);
  }
  else { // 2D boundary
    MVertex *vb0 = bndElt->getVertex(0);
    MVertex *vb1 = bndElt->getVertex(1);
    MVertex *vb2 = bndElt->getVertex(2);
    MVertex *vb3;
    if (bndType == TYPE_QUA) {
      vb3 = bndElt->getVertex(3);
      metaElType = TYPE_HEX;
    }
    else {
      vb3 = 0;
      metaElType = TYPE_PRI;
    }
    MFace baseFace(vb0, vb1, vb2, vb3);
    foundCol = getColumn3D(face2el, p, baseFace, baseVert, topPrimVert,
                           blob, aboveElt);
  }
  if (!foundCol || blob.empty()) return; // Skip bnd. el. if top vertices not found
  DbgOutputCol dbgOutCol;
  dbgOutCol.addBlob(blob);
  dbgOutCol.write("col_KO", bndElt->getNum());
  if (aboveElt == 0) std::cout << "DBGTT: aboveElt = 0 for bnd. elt. " << bndElt->getNum() << std::endl;
  if (p.robust)
    curveColumnRobust(p, bndEnt, metaElType, baseVert, topPrimVert, aboveElt, blob,
                      movedVert, dbgOut, normals);
  else
    curveColumn(p, ent, bndEnt, metaElType, baseVert, topPrimVert,
                aboveElt, blob, movedVert, dbgOut);
  dbgOutCol.write("col_OK", bndElt->getNum());
}

void getColumnsAndcurveBoundaryLayer(MEdgeVecMEltMap &ed2el,
                                     MFaceVecMEltMap &face2el,
                                     GEntity *ent, GEntity *bndEnt,
                                     std::list<MElement*> &bndElts,
                                     const FastCurvingParameters &p,
                                     fullMatrix<double> *normals)
{
  // inspired from curveMeshFromBndElt

  std::vector<std::pair<MElement*, std::vector<MElement*>>> bndEl2column;

  auto it = bndElts.begin();
  while (it != bndElts.end()) {
    MElement *bndEl = *it;
    const int bndType = bndEl->getType();
    bool foundCol;
    std::vector<MVertex*> baseVert, topPrimVert;
    MElement *aboveElt = 0;

    if (bndType == TYPE_LIN) { // 1D boundary
      MVertex *vb0 = bndEl->getVertex(0);
      MVertex *vb1 = bndEl->getVertex(1);
      MEdge baseEd(vb0, vb1);
      std::vector<MElement*> vec;
      bndEl2column.push_back(std::make_pair(bndEl, std::vector<MElement*>()));
      foundCol = getColumn2D(ed2el, p, baseEd, baseVert, topPrimVert,
                             bndEl2column.back().second, aboveElt);
    }
    else { // 2D boundary
      MVertex *vb0 = bndEl->getVertex(0);
      MVertex *vb1 = bndEl->getVertex(1);
      MVertex *vb2 = bndEl->getVertex(2);
      MVertex *vb3 = NULL;
      if (bndType == TYPE_QUA) vb3 = bndEl->getVertex(3);
      MFace baseFace(vb0, vb1, vb2, vb3);
      bndEl2column.push_back(std::make_pair(bndEl, std::vector<MElement*>()));
      foundCol = getColumn3D(face2el, p, baseFace, baseVert, topPrimVert,
                             bndEl2column.back().second, aboveElt);
    }
    if (!foundCol || bndEl2column.back().second.empty()) {
      bndEl2column.pop_back();
    } // Skip bnd. el. if top vertices not found

    ++it;
  }

  SVector3 normal;
  if (normals)
    normal = SVector3(normals(0, 0), normals(0, 1), normals(0, 2));
  else
    normal = SVector3(0, 0, 1);
  if (p.dim == 2) curve2DBoundaryLayer(bndEl2column, normal);
  else curve3DBoundaryLayer(bndEl2column);
}


void curveMeshFromBnd(MEdgeVecMEltMap &ed2el, MFaceVecMEltMap &face2el,
                      GEntity *ent, GEntity *bndEnt,
                      const FastCurvingParameters &p,
                      fullMatrix<double> *normals)
{
  // Build list of bnd. elements to consider
  std::list<MElement*> bndEl;
  if (bndEnt->dim() == 1) {
    GEdge *gEd = bndEnt->cast2Edge();
    for(unsigned int i = 0; i< gEd->lines.size(); i++)
      insertIfCurved(gEd->lines[i], bndEl);
  }
  else if (bndEnt->dim() == 2) {
    GFace *gFace = bndEnt->cast2Face();
    for(unsigned int i = 0; i< gFace->triangles.size(); i++) {
      if (p.thickness) bndEl.push_back(gFace->triangles[i]);
      else insertIfCurved(gFace->triangles[i], bndEl);
    }
    for(unsigned int i = 0; i< gFace->quadrangles.size(); i++)
      if (p.thickness) bndEl.push_back(gFace->quadrangles[i]);
      else insertIfCurved(gFace->quadrangles[i], bndEl);
  }
  else
    Msg::Error("Cannot process model entity %i of dim %i", bndEnt->tag(),
                                                           bndEnt->dim());

  if (p.thickness) {
    getColumnsAndcurveBoundaryLayer(ed2el, face2el, ent,
                                    bndEnt, bndEl, p, normals);
    return;
  }

  // Loop over boundary elements to curve them by columns
  DbgOutputMeta dbgOut;
  std::set<MVertex*> movedVert;
  for(std::list<MElement*>::iterator itBE = bndEl.begin();
      itBE != bndEl.end(); itBE++) // Loop over bnd. elements
    curveMeshFromBndElt(ed2el, face2el, ent, bndEnt, *itBE, movedVert, p,
                        dbgOut, normals);
  dbgOut.write("meta-elements", bndEnt->tag());
}





}



// Main function for fast curving
void HighOrderMeshFastCurving(GModel *gm, FastCurvingParameters &p,
                              bool requireBLInfo)
{
  double t1 = Cpu();
  Msg::StatusBar(true, "Curving high order boundary layer mesh...");

  // Retrieve geometric entities and boundary layer field
  std::vector<GEntity*> allGEnt;
  gm->getEntities(allGEnt);
  BoundaryLayerField *blField = getBLField(gm);

  // Curve mesh for non-straight boundary entities
  for (int iEnt = 0; iEnt < allGEnt.size(); ++iEnt) {
    // Retrieve entity
    GEntity* &gEnt = allGEnt[iEnt];
    if (gEnt->dim() != p.dim) continue;

    // Compute normal if planar surface
    fullMatrix<double> *normals = NULL;
    if (p.dim == 2) {
      if (gEnt->geomType() == GEntity::Plane &&
              gEnt->haveParametrization()) {
        double u = gEnt->parBounds(0).low();
        double v = gEnt->parBounds(1).low();
        SVector3 n = dynamic_cast<GFace*>(gEnt)->normal(SPoint2(u, v));
        normals = new fullMatrix<double>(1, 3);
        normals->set(0, 0, n[0]);
        normals->set(0, 1, n[1]);
        normals->set(0, 2, n[2]);
      }
      else if (gEnt->geomType() == GEntity::DiscreteSurface) {
        SBoundingBox3d bb = gEnt->bounds();
        // If we don't have the CAD, check if the mesh is 2D:
        if (!bb.empty() && bb.max().z() - bb.min().z() == .0) {
          normals = new fullMatrix<double>(1, 3);
          normals->set(0, 0, 0);
          normals->set(0, 1, 0);
          normals->set(0, 2, 1);
        }
      }
    }

    // Retrieve boundary entities and test if boundary layer
    std::vector<GEntity*> bndEnts;
    std::set<GEntity*> blBndEnts;
    if (p.dim == 2) {
      std::list<GEdge*> gEds = gEnt->edges();
      bndEnts = std::vector<GEntity*>(gEds.begin(), gEds.end());
      for (int iBndEnt = 0; iBndEnt < bndEnts.size(); iBndEnt++) {
        GEntity* &bndEnt = bndEnts[iBndEnt];
        if ((blField != 0) && blField->isEdgeBL(bndEnt->tag())) {
          blBndEnts.insert(bndEnt);
        }
      }
    }
    else {
      std::list<GFace*> gFaces = gEnt->faces();
      bndEnts = std::vector<GEntity*>(gFaces.begin(), gFaces.end());
    }
    if (requireBLInfo && blBndEnts.empty()) continue;                           // Skip if BL info is required but there is none

    // Compute edge/face -> elt. connectivity
    Msg::Info("Computing connectivity for entity %i...", gEnt->tag());
    MEdgeVecMEltMap ed2el;
    MFaceVecMEltMap face2el;
    if (p.dim == 2) calcEdge2Elements(gEnt, ed2el);
    else calcFace2Elements(gEnt, face2el);

    // Curve mesh from each boundary entity
    for (int iBndEnt = 0; iBndEnt < bndEnts.size(); iBndEnt++) {
      GEntity* &bndEnt = bndEnts[iBndEnt];
      if (p.onlyVisible && !bndEnt->getVisibility()) continue;                  // Skip if "only visible" required and entity is invisible
      if (!blBndEnts.empty() &&                                                 // Skip if there is BL info but not on this boundary
          (blBndEnts.find(bndEnt) == blBndEnts.end())) continue;
      const GEntity::GeomType bndType = bndEnt->geomType();
      if ((bndType == GEntity::Line) || (bndType == GEntity::Plane)) continue;  // Skip if boundary is straight
      Msg::Info("Curving elements in entity %d for boundary entity %d...",
                gEnt->tag(), bndEnt->tag());
      curveMeshFromBnd(ed2el, face2el, gEnt, bndEnt, p, normals);
    }
  }

  double t2 = Cpu();
  Msg::StatusBar(true, "Done curving high order boundary layer mesh (%g s)", t2-t1);
}
