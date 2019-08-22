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
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include "HighOrderMeshFastCurving.h"
#include "GmshConfig.h"
#include "GModel.h"
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
#include "MetaEl.h"
#include "qualityMeasuresJacobian.h"
#include "CADDistances.h"
#include "Field.h"
#include "boundaryLayersData.h"
#include "BoundaryLayerCurver.h"
#include "FuncSpaceData.h"

namespace {

  typedef std::map<MEdge, std::vector<MElement *>, Less_Edge> MEdgeVecMEltMap;
  typedef std::map<MFace, std::vector<MElement *>, Less_Face> MFaceVecMEltMap;

  // Compute edge -> element connectivity (for 2D elements)
  void calcEdge2Elements(GEntity *entity, MEdgeVecMEltMap &ed2el)
  {
    for(std::size_t iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
      MElement *elt = entity->getMeshElement(iEl);
      elt->setVisibility(0); // FIXMEDEBUG for visualisation
      if(elt->getDim() == 2)
        for(int iEdge = 0; iEdge < elt->getNumEdges(); iEdge++) {
          ed2el[elt->getEdge(iEdge)].push_back(elt);
        }
    }
  }

  // Compute face -> element connectivity (for 3D elements)
  void calcFace2Elements(GEntity *entity, MFaceVecMEltMap &face2el)
  {
    for(std::size_t iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
      MElement *elt = entity->getMeshElement(iEl);
      elt->setVisibility(0); // FIXMEDEBUG for visualisation
      if(elt->getDim() == 3)
        for(int iFace = 0; iFace < elt->getNumFaces(); iFace++)
          face2el[elt->getFace(iFace)].push_back(elt);
    }
  }

  void makeStraight(MElement *el, const std::set<MVertex *> &movedVert)
  {
    const nodalBasis *nb = el->getFunctionSpace();
    const fullMatrix<double> &pts = nb->points;

    SPoint3 p;

    for(int iPt = el->getNumPrimaryVertices(); iPt < el->getNumVertices();
        iPt++) {
      MVertex *vert = el->getVertex(iPt);
      if(movedVert.find(vert) == movedVert.end()) {
        el->primaryPnt(pts(iPt, 0), pts(iPt, 1), pts(iPt, 2), p);
        vert->setXYZ(p.x(), p.y(), p.z());
      }
    }
  }

  inline void insertIfCurved(MElement *el, std::list<MElement *> &bndEl)
  {
    static const double curvedTol =
      1.e-3; // Tolerance to consider element as curved

    const double normalDispCurved =
      curvedTol * el->getInnerRadius(); // Threshold in normal displacement to
                                        // consider element as curved
    const int dim = el->getDim();

    // Compute unit normal to straight edge/face
    SVector3 normal =
      (dim == 1) ? el->getEdge(0).normal() : el->getFace(0).normal();

    // Get functional spaces
    const nodalBasis *lagBasis = el->getFunctionSpace();
    const fullMatrix<double> &uvw = lagBasis->points;
    const int &nV = uvw.size1();
    const nodalBasis *lagBasis1 = el->getFunctionSpace(1);
    const int &nV1 = lagBasis1->points.size1();

    // Get first-order vertices
    std::vector<SPoint3> xyz1(nV1);
    for(int iV = 0; iV < nV1; ++iV) xyz1[iV] = el->getVertex(iV)->point();

    // Check normal displacement at each HO vertex
    for(int iV = nV1; iV < nV; ++iV) { // Loop over HO nodes
      double f[256];
      lagBasis1->f(uvw(iV, 0), (dim > 1) ? uvw(iV, 1) : 0., 0., f);
      SPoint3 xyzS(0., 0., 0.);
      for(int iSF = 0; iSF < nV1; ++iSF)
        xyzS +=
          xyz1[iSF] * f[iSF]; // Compute location of node in straight element
      const SVector3 vec(xyzS, el->getVertex(iV)->point());
      const double normalDisp =
        fabs(dot(vec, normal)); // Normal component of displacement
      if(normalDisp > normalDispCurved) {
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
    if(iElBaseEd == 0) {
      iOppEd = 2;
      iSideEd0 = 1;
      iSideEd1 = 3;
    }
    else if(iElBaseEd == 1) {
      iOppEd = 3;
      iSideEd0 = 0;
      iSideEd1 = 2;
    }
    else if(iElBaseEd == 2) {
      iOppEd = 0;
      iSideEd0 = 1;
      iSideEd1 = 3;
    }
    else {
      iOppEd = 1;
      iSideEd0 = 0;
      iSideEd1 = 2;
    }
    const MEdge elOppEd = el->getEdge(iOppEd);

    // Create top edge
    if(elBaseEdOrient > 0)
      elTopEd = MEdge(elOppEd.getVertex(1), elOppEd.getVertex(0));
    else
      elTopEd = elOppEd;

    // Compute max. and min. edge lengths
    edLenMax = elTopEd.length();
    edLenMin =
      std::min(el->getEdge(iSideEd0).length(), el->getEdge(iSideEd1).length());
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
    for(int iElEd = 0; iElEd < el->getNumEdges(); iElEd++) {
      if(iElEd == iElBaseEd) continue;
      MEdge edTest = el->getEdge(iElEd);
      double edLenTest = edTest.length();
      if(edLenTest < edLenMin) edLenMin = edLenTest;
      if(edLenTest > edLenMax) {
        edLenMax = edLenTest;
        elMaxEd = edTest;
      }
    }

    // Build top edge from max edge (with right orientation)
    if(elBaseEd.getVertex(0) == elMaxEd.getVertex(0))
      elTopEd = elMaxEd;
    else
      elTopEd = MEdge(elMaxEd.getVertex(1), elMaxEd.getVertex(0));
  }

  void getColumnQuad(MEdgeVecMEltMap &edge2el, const FastCurvingParameters &p,
                     MEdge &inOutEdge, std::vector<MElement *> &blob,
                     MElement *&aboveElt)
  {
    // inOutEdge: in = bottom edge of BL column, out = top edge of BL column
    const double maxDP = p.cosMaxAngle;

    blob.clear();
    MElement *el = NULL;
    MEdge baseEdge = inOutEdge;
    aboveElt = edge2el[baseEdge][0];

    for(int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
      MEdge topEdge;
      double edLenMin, edLenMax;

      el = aboveElt;
      if(el->getType() != TYPE_QUA) return;
      getOppositeEdgeQuad(el, baseEdge, topEdge, edLenMin, edLenMax);

      // Geometrical stopping criteria
      const double dp = dot(baseEdge.tangent(), topEdge.tangent());
      if(std::abs(dp) < maxDP) return;
      if(iLayer == 0 && edLenMin > edLenMax * p.maxRhoFirst) return;
      if(edLenMin > edLenMax * p.maxRho) break;

      // Add new layer
      blob.push_back(el);
      inOutEdge = topEdge;
      aboveElt = NULL;

      // Above element & update baseFace
      std::vector<MElement *> newElts = edge2el[topEdge];
      if(newElts.size() < 2) return;
      aboveElt = (newElts[0] == el) ? newElts[1] : newElts[0];
      baseEdge = topEdge;
    }
  }

  void getColumnTri(MEdgeVecMEltMap &edge2el, const FastCurvingParameters &p,
                    MEdge &inOutEdge, std::vector<MElement *> &blob,
                    MElement *&aboveElt)
  {
    // inOutEdge: in = bottom edge of BL column, out = top edge of BL column
    const double maxDP = p.cosMaxAngle;
    const double maxDPIn = p.cosMaxAngleInner;

    blob.clear();
    MElement *el0 = NULL, *el1 = NULL;
    MEdge baseEdge = inOutEdge;
    aboveElt = edge2el[baseEdge][0];

    for(int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
      MEdge topEdge0, topEdge1;
      double edLenMin0, edLenMax0, edLenMin1, edLenMax1;

      // first element of layer
      el0 = aboveElt;
      if(el0->getType() != TYPE_TRI) return;
      getOppositeEdgeTri(el0, baseEdge, topEdge0, edLenMin0, edLenMax0);

      // second element of layer
      std::vector<MElement *> newElts1 = edge2el[topEdge0];
      if(newElts1.size() < 2) return;
      el1 = (newElts1[0] == el0) ? newElts1[1] : newElts1[0];
      if(el1->getType() != TYPE_TRI) return;
      getOppositeEdgeTri(el1, topEdge0, topEdge1, edLenMin1, edLenMax1);

      // Geometrical stopping criteria
      const SVector3 tangentBase = baseEdge.tangent();
      const SVector3 tangentTop0 = topEdge0.tangent();
      const SVector3 tangentTop1 = topEdge1.tangent();
      if(std::abs(dot(tangentBase, tangentTop0)) < maxDPIn ||
         std::abs(dot(tangentTop0, tangentTop1)) < maxDPIn ||
         std::abs(dot(tangentBase, tangentTop1)) < maxDP)
        return;

      const double edLenMin = std::min(edLenMin0, edLenMin1);
      const double edLenMax = std::max(edLenMax0, edLenMax1);
      if(iLayer == 0 && edLenMin > edLenMax * p.maxRhoFirst) return;
      if(edLenMin > edLenMax * p.maxRho) return;

      // Add new layer
      blob.push_back(el0);
      blob.push_back(el1);
      inOutEdge = topEdge1;
      aboveElt = NULL;

      // Above element & update baseEdge
      std::vector<MElement *> newEltsnext = edge2el[topEdge1];
      if(newEltsnext.size() < 2) return;
      aboveElt = (newEltsnext[0] == el1) ? newEltsnext[1] : newEltsnext[0];
      baseEdge = topEdge1;
    }
  }

  void get2Dcolumn(MEdgeVecMEltMap &edge2el, const FastCurvingParameters &p,
                   MElement *bndEl, std::vector<MElement *> &column,
                   MElement *&aboveEl, MEdge &topEdge)
  {
    column.clear();

    MVertex *vb0 = bndEl->getVertex(0);
    MVertex *vb1 = bndEl->getVertex(1);
    MEdge edge(vb0, vb1);

    // Check if baseEd is adjacent to an element of the face
    // (the contrary can happen with degenerate edge, see fix b91a1b822)
    MEdgeVecMEltMap::iterator myit = edge2el.find(edge);
    if(myit == edge2el.end()) return;

    const int typeColumn = edge2el[edge][0]->getType();
    if(typeColumn == TYPE_TRI)
      getColumnTri(edge2el, p, edge, column, aboveEl);
    else
      getColumnQuad(edge2el, p, edge, column, aboveEl);

    topEdge = edge;
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
    std::vector<MVertex *> topVert(3);
    for(int iEd = 0; iEd < 3; iEd++) {
      MEdge ed = el->getEdge(sideEd[iEd]);
      for(int iV = 0; iV < 3; iV++) {
        if(elBaseFace.getVertex(iV) == ed.getVertex(0))
          topVert[iV] = ed.getVertex(1);
        else if(elBaseFace.getVertex(iV) == ed.getVertex(1))
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

  void getOppositeFaceHex(MElement *el, const MFace &elBaseFace,
                          MFace &elTopFace, double &faceSurfMin,
                          double &faceSurfMax)
  {
    // Find base face
    int iElBaseFace = -1, iDum;
    el->getFaceInfo(elBaseFace, iElBaseFace, iDum, iDum);

    // Determine side edges
    int sideEd[4], sideFace[4];
    if((iElBaseFace == 0) || (iElBaseFace == 5)) {
      sideEd[0] = 2;
      sideEd[1] = 4;
      sideEd[2] = 6;
      sideEd[3] = 7;
      sideFace[0] = 1;
      sideFace[1] = 2;
      sideFace[2] = 3;
      sideFace[3] = 4;
    }
    else if((iElBaseFace == 1) || (iElBaseFace == 4)) {
      sideEd[0] = 1;
      sideEd[1] = 3;
      sideEd[2] = 10;
      sideEd[3] = 9;
      sideFace[0] = 0;
      sideFace[1] = 2;
      sideFace[2] = 3;
      sideFace[3] = 5;
    }
    else if((iElBaseFace == 2) || (iElBaseFace == 3)) {
      sideEd[0] = 0;
      sideEd[1] = 5;
      sideEd[2] = 11;
      sideEd[3] = 8;
      sideFace[0] = 0;
      sideFace[1] = 1;
      sideFace[2] = 4;
      sideFace[3] = 5;
    }

    // Check side edges to find opposite vertices
    std::vector<MVertex *> topVert(4);
    for(int iEd = 0; iEd < 4; iEd++) {
      MEdge ed = el->getEdge(sideEd[iEd]);
      for(int iV = 0; iV < 4; iV++) {
        if(elBaseFace.getVertex(iV) == ed.getVertex(0))
          topVert[iV] = ed.getVertex(1);
        else if(elBaseFace.getVertex(iV) == ed.getVertex(1))
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

  void getOppositeFaceTet(MElement *el, const MFace &elBaseFace,
                          MFace &elTopFace, double &faceSurfMin,
                          double &faceSurfMax)
  {
    static const double BIG = 1e300;

    int iElBaseFace = -1, iDum;
    el->getFaceInfo(elBaseFace, iElBaseFace, iDum, iDum);
    faceSurfMin = BIG;
    faceSurfMax = -BIG;
    MFace elMaxFace;

    // Look for largest face except base one
    for(int iElFace = 0; iElFace < el->getNumFaces(); iElFace++) {
      if(iElFace == iElBaseFace) continue;
      MFace faceTest = el->getFace(iElFace);
      const double faceSurfTest = faceTest.approximateArea();
      if(faceSurfTest < faceSurfMin) faceSurfMin = faceSurfTest;
      if(faceSurfTest > faceSurfMax) {
        faceSurfMax = faceSurfTest;
        elMaxFace = faceTest;
      }
    }

    // Build top face from max face (with right correspondance)
    MVertex *maxVert[3] = {elMaxFace.getVertex(0), elMaxFace.getVertex(1),
                           elMaxFace.getVertex(2)};
    std::vector<MVertex *> topVert(3, static_cast<MVertex *>(0));
    for(int iBaseV = 0; iBaseV < 3;
        iBaseV++) // Two vertices of elTopFace are those of elMaxFace coinciding
                  // with elBaseFace
      for(int iMaxV = 0; iMaxV < 3; iMaxV++)
        if(elBaseFace.getVertex(iBaseV) == maxVert[iMaxV]) {
          topVert[iBaseV] = maxVert[iMaxV];
          maxVert[iMaxV] = 0;
        }
    MVertex *thirdMaxVert = (maxVert[0] != 0) ?
                              maxVert[0] : // Set last vertex of elTopFace as
                                           // remaining vertex in elMaxFace
                              (maxVert[1] != 0) ? maxVert[1] : maxVert[2];
    if(topVert[0] == 0)
      topVert[0] = thirdMaxVert;
    else if(topVert[1] == 0)
      topVert[1] = thirdMaxVert;
    else
      topVert[2] = thirdMaxVert;
    elTopFace = MFace(topVert);
  }

  void updateBLShell(MElement *el, std::set<MFace, Less_Face> &BLShell)
  {
    for(int i = 0; i < el->getNumFaces(); ++i) {
      MFace f = el->getFace(i);
      std::set<MFace, Less_Face>::iterator it = BLShell.find(f);
      if(it == BLShell.end())
        BLShell.insert(f);
      else
        BLShell.erase(it);
    }
  }

  // Column of tets: assume tets obtained from subdivision of prism
  void getColumnTet(MFaceVecMEltMap &face2el, const FastCurvingParameters &p,
                    MFace &inOutFace, std::vector<MElement *> &blob,
                    MElement *&aboveElt, std::set<MFace, Less_Face> &BLShell)
  {
    // inOutFace: in = bottom face of BL column, out = top face of BL column
    const double maxDP = p.cosMaxAngle;
    const double maxDPIn = p.cosMaxAngleInner;

    blob.clear();
    MElement *el0 = NULL, *el1 = NULL, *el2 = NULL;
    MFace baseFace = inOutFace;
    aboveElt = face2el[baseFace][0];
    BLShell.insert(baseFace);

    for(int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
      MFace topFace0, topFace1, topFace2;
      double faceSurfMin0, faceSurfMax0, faceSurfMin1, faceSurfMax1,
        faceSurfMin2, faceSurfMax2;

      // first element of layer
      el0 = aboveElt;
      if(el0->getType() != TYPE_TET) return;
      getOppositeFaceTet(el0, baseFace, topFace0, faceSurfMin0, faceSurfMax0);

      // second element of layer
      std::vector<MElement *> newElts1 = face2el[topFace0];
      if(newElts1.size() < 2) return;
      el1 = (newElts1[0] == el0) ? newElts1[1] : newElts1[0];
      if(el1->getType() != TYPE_TET) return;
      getOppositeFaceTet(el1, topFace0, topFace1, faceSurfMin1, faceSurfMax1);

      // Third element of layer
      std::vector<MElement *> newElts2 = face2el[topFace1];
      if(newElts2.size() < 2) return;
      el2 = (newElts2[0] == el1) ? newElts2[1] : newElts2[0];
      if(el2->getType() != TYPE_TET) return;
      getOppositeFaceTet(el2, topFace1, topFace2, faceSurfMin2, faceSurfMax2);

      // Geometrical stopping criteria
      const SVector3 normBase = baseFace.normal();
      const SVector3 normTop0 = topFace0.normal();
      const SVector3 normTop1 = topFace1.normal();
      const SVector3 normTop2 = topFace2.normal();
      if(std::abs(dot(normBase, normTop0)) < maxDPIn ||
         std::abs(dot(normTop0, normTop1)) < maxDPIn ||
         std::abs(dot(normTop1, normTop2)) < maxDPIn ||
         std::abs(dot(normBase, normTop2)) < maxDP)
        return;

      const double faceSurfMin =
        std::min(faceSurfMin0, std::min(faceSurfMin1, faceSurfMin2));
      const double faceSurfMax =
        std::max(faceSurfMax0, std::min(faceSurfMax1, faceSurfMax2));
      if(iLayer == 0 && faceSurfMin > faceSurfMax * p.maxRhoFirst) return;
      if(faceSurfMin > faceSurfMax * p.maxRho) return;

      // Add new layer
      blob.push_back(el0);
      blob.push_back(el1);
      blob.push_back(el2);
      inOutFace = topFace2;
      aboveElt = NULL;
      updateBLShell(el0, BLShell);
      updateBLShell(el1, BLShell);
      updateBLShell(el2, BLShell);

      // Above element & update baseFace
      std::vector<MElement *> newEltsnext = face2el[topFace2];
      if(newEltsnext.size() < 2) return;
      aboveElt = (newEltsnext[0] == el2) ? newEltsnext[1] : newEltsnext[0];
      baseFace = topFace2;
    }
  }

  void getColumnPrismHex(int elType, MFaceVecMEltMap &face2el,
                         const FastCurvingParameters &p, MFace &inOutFace,
                         std::vector<MElement *> &blob, MElement *&aboveElt,
                         std::set<MFace, Less_Face> &BLShell)
  {
    // inOutFace: in = bottom face of BL column, out = top face of BL column
    const double maxDP = p.cosMaxAngle;

    blob.clear();
    MElement *el = NULL;
    MFace baseFace = inOutFace;
    aboveElt = face2el[baseFace][0];
    BLShell.insert(baseFace);

    for(int iLayer = 0; iLayer < p.maxNumLayers; iLayer++) {
      MFace topFace;
      double faceSurfMin, faceSurfMax;

      el = aboveElt;
      if(el->getType() != elType) return;
      if(elType == TYPE_PRI)
        getOppositeFacePrism(el, baseFace, topFace, faceSurfMin, faceSurfMax);
      else if(elType == TYPE_HEX)
        getOppositeFaceHex(el, baseFace, topFace, faceSurfMin, faceSurfMax);

      // Geometrical stopping criteria
      // FIXME: for hexes, the following code is not robust
      //  (normal is of triangular face):
      const double dp = dot(baseFace.normal(), topFace.normal());
      if(std::abs(dp) < maxDP) return;
      if(iLayer == 0 && faceSurfMin > faceSurfMax * p.maxRhoFirst) return;
      if(faceSurfMin > faceSurfMax * p.maxRho) return;

      // Add new layer
      blob.push_back(el);
      inOutFace = topFace;
      aboveElt = NULL;
      updateBLShell(el, BLShell);

      // Above element & update baseFace
      std::vector<MElement *> newElts = face2el[topFace];
      if(newElts.size() < 2) return;
      aboveElt = (newElts[0] == el) ? newElts[1] : newElts[0];
      baseFace = topFace;
    }
  }

  void get3Dcolumn(MFaceVecMEltMap &face2el, const FastCurvingParameters &p,
                   MElement *bndEl, std::vector<MElement *> &column,
                   MElement *&aboveEl, std::set<MFace, Less_Face> &BLShell,
                   MFace &topFace)
  {
    const int typeBase = bndEl->getType();
    if(typeBase == TYPE_POLYG) return;

    column.clear();

    MVertex *vb0 = bndEl->getVertex(0);
    MVertex *vb1 = bndEl->getVertex(1);
    MVertex *vb2 = bndEl->getVertex(2);
    MVertex *vb3 = NULL;
    if(typeBase == TYPE_QUA) vb3 = bndEl->getVertex(3);
    MFace face(vb0, vb1, vb2, vb3);

    const int typeColumn = face2el[face][0]->getType();
    if(typeColumn == TYPE_TET)
      getColumnTet(face2el, p, face, column, aboveEl, BLShell);
    else if(typeColumn == TYPE_PRI || typeColumn == TYPE_HEX)
      getColumnPrismHex(typeColumn, face2el, p, face, column, aboveEl, BLShell);

    topFace = face;
  }

  class DbgOutputMeta {
  public:
    void addMetaEl(MetaEl &mEl)
    {
      MElement *elt = mEl.getMElement();
      elType_.push_back(elt->getTypeForMSH());
      nbVertEl_.push_back(elt->getNumVertices());
      for(int iV = 0; iV < elt->getNumVertices(); iV++)
        point_.push_back(elt->getVertex(iV)->point());
    }
    void write(const std::string &fNameBase, int tag)
    {
      std::ostringstream oss;
      oss << fNameBase << "_" << tag << ".msh";
      std::string fName = oss.str();
      FILE *fp = fopen(fName.c_str(), "w");
      if(!fp) return;
      fprintf(fp, "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n");
      fprintf(fp, "$Nodes\n");
      fprintf(fp, "%d\n", point_.size());
      for(int iV = 0; iV < point_.size(); iV++)
        fprintf(fp, "%i %g %g %g\n", iV + 1, point_[iV].x(), point_[iV].y(),
                point_[iV].z());
      fprintf(fp, "$EndNodes\n");
      fprintf(fp, "$Elements\n");
      fprintf(fp, "%d\n", elType_.size());
      int iV = 0;
      for(int iEl = 0; iEl < elType_.size(); iEl++) {
        fprintf(fp, "%i %i 2 0 0 ", iEl + 1, elType_[iEl]);
        for(int iVEl = 1; iVEl <= nbVertEl_[iEl]; iVEl++)
          fprintf(fp, " %i", iV + iVEl);
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
    void addBlob(const std::vector<MElement *> &blob)
    {
      for(int iEl = 0; iEl < blob.size(); iEl++) addElement(blob[iEl]);
    }
    void addElement(MElement *elt)
    {
      elt_.push_back(elt);
      for(int iV = 0; iV < elt->getNumVertices(); iV++)
        vert_.insert(elt->getVertex(iV));
    }
    void write(const std::string &fNameBase, int tag)
    {
      std::ostringstream oss;
      oss << fNameBase << "_" << tag << ".msh";
      std::string fName = oss.str();
      FILE *fp = fopen(fName.c_str(), "w");
      if(!fp) return;
      fprintf(fp, "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n");
      fprintf(fp, "$Nodes\n");
      fprintf(fp, "%d\n", vert_.size());
      for(std::set<MVertex *>::iterator itV = vert_.begin(); itV != vert_.end();
          ++itV) {
        SPoint3 p = (*itV)->point();
        fprintf(fp, "%i %g %g %g\n", (*itV)->getNum(), p.x(), p.y(), p.z());
      }
      fprintf(fp, "$EndNodes\n");
      fprintf(fp, "$Elements\n");
      fprintf(fp, "%d\n", elt_.size());
      int iV = 0;
      for(int iEl = 0; iEl < elt_.size(); iEl++) {
        fprintf(fp, "%i %i 2 0 0 ", elt_[iEl]->getNum(),
                elt_[iEl]->getTypeForMSH());
        for(int iVEl = 0; iVEl < elt_[iEl]->getNumVertices(); iVEl++)
          fprintf(fp, " %i", elt_[iEl]->getVertex(iVEl)->getNum());
        fprintf(fp, "\n");
      }
      fprintf(fp, "$EndElements\n");
      fclose(fp);
    }

  private:
    std::set<MVertex *> vert_;
    std::vector<MElement *> elt_;
  };

  void curveElement(const MetaEl &metaElt, std::set<MVertex *> &movedVert,
                    MElement *elt)
  {
    makeStraight(elt, movedVert);
    for(int iV = elt->getNumPrimaryVertices(); iV < elt->getNumVertices();
        iV++) { // Loop over HO vert. of each el. in blob
      MVertex *vert = elt->getVertex(iV);
      if(movedVert.find(vert) ==
         movedVert.end()) { // Try to move vert. not already moved
        double xyzS[3] = {vert->x(), vert->y(), vert->z()}, xyzC[3];
        if(metaElt.straightToCurved(xyzS, xyzC)) {
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
    const GradientBasis *gb;
    const int tag = bndElt->getTypeForMSH();
    gb = BasisFactory::getGradientBasis(tag, FuncSpaceData(bndElt));

    // Coordinates of nodes
    fullMatrix<double> nodesXYZ(nbVert, 3);
    for(int iV = 0; iV < nbVert; iV++) {
      MVertex *vert = bndElt->getVertex(iV);
      nodesXYZ(iV, 0) = vert->x();
      nodesXYZ(iV, 1) = vert->y();
      nodesXYZ(iV, 2) = vert->z();
    }

    // Compute distance
    const GEdge *ge = geomEnt->cast2Edge();
    const Range<double> parBounds = ge->parBounds(0);
    std::vector<SVector3> tanCAD(nbVert);
    for(int iV = 0; iV < nbVert; iV++) {
      MVertex *vert = bndElt->getVertex(iV);
      double tCAD;
      if(vert->onWhat() == geomEnt) // If HO vertex, ...
        vert->getParameter(
          0, tCAD); // ... get stored param. coord. (can be only line).
      else { // Otherwise, get param. coord. from CAD.
        if(ge->getBeginVertex() &&
           (ge->getBeginVertex()->mesh_vertices[0] == vert))
          tCAD = parBounds.low();
        else if(ge->getEndVertex() &&
                (ge->getEndVertex()->mesh_vertices[0] == vert))
          tCAD = parBounds.high();
        else
          tCAD = ge->parFromPoint(vert->point());
      }
      tanCAD[iV] = ge->firstDer(tCAD); // Compute tangent at vertex
      tanCAD[iV].normalize(); // Normalize tangent
    }
    return taylorDistanceSq1D(gb, nodesXYZ, tanCAD);
  }

  double moveAndGetDistSq2DP2(GEdge *ge, MLine3 *bndMetaElt, MVertex *vert,
                              double u)
  {
    vert->setParameter(0, u);
    GPoint gp = ge->point(u);
    vert->setXYZ(gp.x(), gp.y(), gp.z());
    return calcCADDistSq2D(ge, bndMetaElt);
  }

  void optimizeCADDist2DP2(GEntity *geomEnt, std::vector<MVertex *> &baseVert)
  {
    // Parameters for secant method
    static const int MAXIT = 20;
    static const double TOL = 1e-3;

    // Boundary geometric and mesh entities, parametrization
    MLine3 bndMetaElt(baseVert);
    MVertex *&vert = baseVert[2];
    GEdge *ge = geomEnt->cast2Edge();
    const Range<double> parBounds = ge->parBounds(0);
    double uBV0, uBV1, uMin, uMax;
    reparamMeshVertexOnEdge(baseVert[0], ge, uBV0);
    reparamMeshVertexOnEdge(baseVert[1], ge, uBV1);
    if(uBV0 < uBV1) {
      uMin = uBV0;
      uMax = uBV1;
    }
    else {
      uMin = uBV1;
      uMax = uBV0;
    }
    const double du = uMax - uMin;

    // First initial value for secant method
    double u00 = uMin + 0.5 * du;
    double distSq00 = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u00);
    const double edLen = bndMetaElt.getLength();

    // Second initial value for secant method
    const double u0A = uMin + 0.45 * du, u0B = uMin + 0.55 * du;
    const double distSq0A = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u0A);
    const double distSq0B = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u0B);
    double u0, distSq0;
    if(distSq0A < distSq0B) {
      u0 = u0A;
      distSq0 = distSq0A;
    }
    else {
      u0 = u0B;
      distSq0 = distSq0B;
    }

    // Secant method iteration
    double u;
    bool converged = false;
    for(int it = 0; it < MAXIT; it++) {
      u = (u00 * distSq0 - u0 * distSq00) / (distSq0 - distSq00);
      const double distSq = moveAndGetDistSq2DP2(ge, &bndMetaElt, vert, u);
      if(std::abs(u - u0) / du < TOL) {
        converged = true;
        break;
      }
      u00 = u0;
      distSq00 = distSq0;
      u0 = u;
      distSq0 = distSq;
    }

    if(!converged || (u < uMin + TOL) ||
       (u > uMax - TOL)) { // Set to mid-point if not converged
      u = uMin + 0.5 * du;
      vert->setParameter(0, u);
      GPoint gp = ge->point(u);
      vert->setXYZ(gp.x(), gp.y(), gp.z());
    }
  }

  double curveAndMeasureAboveEl(MetaEl &metaElt, MElement *lastElt,
                                MElement *aboveElt, double deformFact)
  {
    metaElt.setCurvedTop(deformFact);
    std::set<MVertex *> movedVertDum;
    curveElement(metaElt, movedVertDum, lastElt);
    if(aboveElt == 0) return 1.;
    double minJacDet, maxJacDet;
    jacobianBasedQuality::minMaxJacobianDeterminant(aboveElt, minJacDet,
                                                    maxJacDet);
    return minJacDet / maxJacDet;
  }

  void curveColumn(const FastCurvingParameters &p, GEntity *ent,
                   GEntity *bndEnt, int metaElType,
                   std::vector<MVertex *> &baseVert,
                   const std::vector<MVertex *> &topPrimVert,
                   MElement *aboveElt, std::vector<MElement *> &blob,
                   std::set<MVertex *> &movedVert, DbgOutputMeta &dbgOut)
  {
    static const double MINQUAL = 0.01, TOL = 0.01, MAXITER = 10;

    // Order
    const int order = blob[0]->getPolynomialOrder();

    // If 2D P2 and allowed, modify base vertices to minimize distance between
    // wall edge and CAD
    if((p.optimizeGeometry) && (metaElType == TYPE_QUA) && (order == 2))
      optimizeCADDist2DP2(bndEnt, baseVert);

    // Create meta-element
    MetaEl metaElt(metaElType, order, baseVert, topPrimVert);

    // If required, curve top face of meta-element
    if(p.curveOuterBL != FastCurvingParameters::OUTER_NOCURVE) {
      MElement *&lastElt = blob.back();
      double minJacDet, maxJacDet;
      double deformMin = 0., qualDeformMin = 1.;
      double deformMax = 1.;
      double qualDeformMax =
        curveAndMeasureAboveEl(metaElt, lastElt, aboveElt, deformMax);
      // Bisection on displacement to avoid breaking the element above if
      // required
      if((p.curveOuterBL == FastCurvingParameters::OUTER_CURVECONSERVATIVE) &&
         (qualDeformMax <
          MINQUAL)) { // Max deformation makes element above invalid
        for(int iter = 0; iter < MAXITER;
            iter++) { // Bisection to find max. deformation that makes element
                      // above valid
          const double deformMid = 0.5 * (deformMin + deformMax);
          const double qualDeformMid =
            curveAndMeasureAboveEl(metaElt, lastElt, aboveElt, deformMid);
          if(std::abs(deformMax - deformMin) < TOL) break;
          const bool signDeformMax = (qualDeformMax < MINQUAL);
          const bool signDeformMid = (qualDeformMid < MINQUAL);
          if(signDeformMid == signDeformMax)
            deformMax = deformMid;
          else
            deformMin = deformMid;
        }
        metaElt.setFlatTop();
      }
      for(int iV = 0; iV < lastElt->getNumVertices(); iV++)
        movedVert.insert(lastElt->getVertex(iV));
    }

    // Curve elements
    dbgOut.addMetaEl(metaElt);
    for(int iEl = 0; iEl < blob.size(); iEl++) {
      curveElement(metaElt, movedVert, blob[iEl]);
      ent->curvedBLElements.insert(blob[iEl]);
    }
  }

  void curveMeshFromBndElt(MEdgeVecMEltMap &ed2el, MFaceVecMEltMap &face2el,
                           GEntity *ent, GEntity *bndEnt, MElement *bndElt,
                           std::set<MVertex *> movedVert,
                           const FastCurvingParameters &p,
                           DbgOutputMeta &dbgOut)
  {
    const int bndType = bndElt->getType();
    int metaElType;
    std::vector<MVertex *> baseVert, topPrimVert;
    std::vector<MElement *> blob;
    MElement *aboveElt = 0;
    if(bndType == TYPE_LIN) { // 2D BL mesh
      MEdge topEdge;
      get2Dcolumn(ed2el, p, bndElt, blob, aboveElt, topEdge);
      topPrimVert.push_back(topEdge.getVertex(0));
      topPrimVert.push_back(topEdge.getVertex(1));
      metaElType = TYPE_QUA;
    }
    else { // 3D BL mesh
      MFace topFace;
      std::set<MFace, Less_Face> dum;
      get3Dcolumn(face2el, p, bndElt, blob, aboveElt, dum, topFace);
      for(std::size_t i = 0; i < topFace.getNumVertices(); ++i)
        topPrimVert.push_back(topFace.getVertex(i));
      if(bndType == TYPE_QUA)
        metaElType = TYPE_HEX;
      else
        metaElType = TYPE_PRI;
    }
    if(blob.empty()) return; // Skip bnd. el. if top vertices not found

    DbgOutputCol dbgOutCol;
    dbgOutCol.addBlob(blob);
    //  dbgOutCol.write("col_KO", bndElt->getNum());
    if(aboveElt == 0)
      std::cout << "DBGTT: aboveElt = 0 for bnd. elt. " << bndElt->getNum()
                << std::endl;

    bndElt->getVertices(baseVert);
    curveColumn(p, ent, bndEnt, metaElType, baseVert, topPrimVert, aboveElt,
                blob, movedVert, dbgOut);
    //  dbgOutCol.write("col_OK", bndElt->getNum());
  }

  void curveMeshFromBnd(MEdgeVecMEltMap &ed2el, MFaceVecMEltMap &face2el,
                        GEntity *ent, GEntity *bndEnt,
                        const FastCurvingParameters &p)
  {
    // Build list of bnd. elements to consider
    std::list<MElement *> bndEl;
    if(bndEnt->dim() == 1) {
      GEdge *gEd = bndEnt->cast2Edge();
      for(std::size_t i = 0; i < gEd->lines.size(); i++)
        insertIfCurved(gEd->lines[i], bndEl);
    }
    else if(bndEnt->dim() == 2) {
      GFace *gFace = bndEnt->cast2Face();
      for(std::size_t i = 0; i < gFace->triangles.size(); i++)
        insertIfCurved(gFace->triangles[i], bndEl);
      for(std::size_t i = 0; i < gFace->quadrangles.size(); i++)
        insertIfCurved(gFace->quadrangles[i], bndEl);
    }
    else
      Msg::Error("Cannot process model entity %i of dim %i", bndEnt->tag(),
                 bndEnt->dim());

    // Loop over boundary elements to curve them by columns
    DbgOutputMeta dbgOut;
    std::set<MVertex *> movedVert;
    for(std::list<MElement *>::iterator itBE = bndEl.begin();
        itBE != bndEl.end(); itBE++) // Loop over bnd. elements
      curveMeshFromBndElt(ed2el, face2el, ent, bndEnt, *itBE, movedVert, p,
                          dbgOut);
    //  dbgOut.write("meta-elements", bndEnt->tag());
  }

  void gather2Dcolumns(MEdgeVecMEltMap &edge2el, GEdge *gEdge,
                       const FastCurvingParameters &p,
                       VecPairMElemVecMElem &columns)
  {
    for(std::size_t i = 0; i < gEdge->getNumMeshElements(); ++i) {
      MElement *bndEl = gEdge->getMeshElement(i);
      std::vector<MElement *> col;
      MEdge dum;
      MElement *aboveEl;
      get2Dcolumn(edge2el, p, bndEl, col, aboveEl, dum);

      if(col.empty()) continue;

      col.push_back(aboveEl); // even if aboveEl is NULL
      columns.push_back(std::make_pair(bndEl, std::vector<MElement *>()));
      columns.back().second.swap(col);
    }
  }

  void gather3Dcolumns(MFaceVecMEltMap &face2el, GFace *gFace,
                       const FastCurvingParameters &p,
                       VecPairMElemVecMElem &columns,
                       std::set<MFace, Less_Face> &BLShell)
  {
    // An element can be in only one column and an element can be a top element
    // of multiple column but then cannot be inside a column.
    // BLShell: faces surrounding the BL except faces on the boundary. Note
    //   that columns can have different number of layers.

    for(std::size_t i = 0; i < gFace->getNumMeshElements(); ++i) {
      MElement *bndEl = gFace->getMeshElement(i);
      std::vector<MElement *> col;
      MFace dum;
      MElement *aboveEl;
      get3Dcolumn(face2el, p, bndEl, col, aboveEl, BLShell, dum);

      if(col.empty()) continue;

      col.push_back(aboveEl); // (even if aboveEl is NULL)
      columns.push_back(std::make_pair(bndEl, std::vector<MElement *>()));
      columns.back().second.swap(col);
    }
  }

  void computeMapMEdge2TouchedElements(GRegion *gr,
                                       VecPairMElemVecMElem &columns,
                                       std::set<MFace, Less_Face> &BLShell,
                                       MapMEdgeVecMElem &touchedElements)
  {
    std::set<MElement *> interiorElements;
    for(std::size_t i = 0; i < columns.size(); ++i) {
      std::vector<MElement *> &col = columns[i].second;
      interiorElements.insert(col.begin(), col.end());
      // // FIXMEDEBUG for visulization
      // for(int j = 0; j < col.size(); ++j) {
      //   if(col[j]) col[j]->setVisibility(1);
      // }
    }

    std::set<MEdge, Less_Edge> BLShellEdges;
    std::set<MFace, Less_Face>::iterator it;
    for(it = BLShell.begin(); it != BLShell.end(); ++it) {
      const MFace &f = *it;
      const std::size_t n = f.getNumVertices();
      for(std::size_t i = 0; i < n; ++i) {
        BLShellEdges.insert(f.getEdge(i));
      }
    }

    for(std::size_t i = 0; i < gr->getNumMeshElements(); ++i) {
      MElement *el = gr->getMeshElement(i);
      if(interiorElements.find(el) != interiorElements.end()) continue;

      const std::size_t n = el->getNumEdges();
      for(std::size_t i = 0; i < n; ++i) {
        MEdge edge = el->getEdge(i);
        if(BLShellEdges.find(edge) == BLShellEdges.end()) continue;
        touchedElements[edge].push_back(el);
      }
    }
  }

} // namespace

// Main functions for fast curving
void HighOrderMeshFastCurving(GEntity *ent, std::vector<GEntity *> &boundary,
                              FastCurvingParameters &p)
{
  const int dim = ent->dim();
  if(dim != p.dim || boundary.empty()) return;

  // If it is a planar surface: compute the normal for speedup
  SVector3 normal;
  bool haveNormal;
  if(dim == 2) haveNormal = ent->cast2Face()->uniqueNormal(normal);

  // Compute edge/face -> elt. connectivity
  Msg::Info("Computing connectivity for entity %i...", ent->tag());
  MEdgeVecMEltMap edge2el;
  MFaceVecMEltMap face2el;
  if(dim == 2)
    calcEdge2Elements(ent, edge2el);
  else
    calcFace2Elements(ent, face2el);

  // Compute columns and curve
  if(p.thickness) {
    VecPairMElemVecMElem columns;

    if(dim == 3) {
      std::set<MFace, Less_Face> BLShell;
      for(int i = 0; i < boundary.size(); i++)
        gather3Dcolumns(face2el, boundary[i]->cast2Face(), p, columns, BLShell);

      // FIXMEDEBUG for visualization
      for(int j = 0; j < columns.size(); ++j) {
        std::vector<MElement *> &col = columns[j].second;
        for(int k = 0; k < col.size(); ++k) {
          if(col[k]) col[k]->setVisibility(1);
        }
      }
      return;

      MapMEdgeVecMElem touchedElements;
      computeMapMEdge2TouchedElements(ent->cast2Region(), columns, BLShell,
                                      touchedElements);

      Msg::Info("Curving elements in volume %d...", ent->tag());
      curve3DBoundaryLayer(columns, touchedElements);
    }
    else {
      for(int i = 0; i < boundary.size(); i++) {
        columns.clear();
        gather2Dcolumns(edge2el, boundary[i]->cast2Edge(), p, columns);

        // // FIXMEDEBUG for visualization
        // for(int j = 0; j < columns.size(); ++j) {
        //   std::vector<MElement *> &col = columns[j].second;
        //   for(int k = 0; k < col.size(); ++k) {
        //     if(col[k]) col[k]->setVisibility(1);
        //   }
        // }
        // continue;

        if(haveNormal)
          curve2DBoundaryLayer(columns, normal, boundary[i]->cast2Edge());
        else
          curve2DBoundaryLayer(columns, ent->cast2Face(),
                               boundary[i]->cast2Edge());
      }
    }
    return;
  }
  else {
    Msg::Info("Curving elements...");
    for(int i = 0; i < boundary.size(); i++) {
      GEntity *bndEnt = boundary[i];
      curveMeshFromBnd(edge2el, face2el, ent, bndEnt, p);
    }
  }
}

void HighOrderMeshFastCurving(GModel *gm, FastCurvingParameters &p,
                              bool onlyIfBLInfo)
{
  double t1 = Cpu();
  Msg::StatusBar(true, "Curving high order boundary layer mesh...");

  // Get geometric entities
  std::vector<GEntity *> allEntities;
  gm->getEntities(allEntities);

  // Get boundary layer field
  std::vector<BoundaryLayerField *> blFields;
  FieldManager *fields = gm->getFields();
  for(int i = 0; i < fields->getNumBoundaryLayerFields(); ++i) {
    Field *bl_field = fields->get(fields->getBoundaryLayerField(i));
    if(bl_field == NULL) continue;
    blFields.push_back(dynamic_cast<BoundaryLayerField *>(bl_field));
  }
  if(onlyIfBLInfo && blFields.empty()) return;

  // Main loop
  for(std::size_t i = 0; i < allEntities.size(); ++i) {
    GEntity *entity = allEntities[i];
    if(entity->dim() != p.dim) continue;

    // Get boundary entities
    std::vector<GEntity *> boundary;
    if(p.dim == 2) {
      std::vector<GEdge *> edges = entity->edges();
      boundary.assign(edges.begin(), edges.end());
    }
    else {
      std::vector<GFace *> faces = entity->faces();
      boundary.assign(faces.begin(), faces.end());
    }

    // Remove undesired boundary entities
    int j = 0;
    while(j < boundary.size()) {
      GEntity *bndEntity = boundary[j];

      bool toRemove = false;
      if(p.onlyVisible && !bndEntity->getVisibility()) toRemove = true;
      const GEntity::GeomType type = bndEntity->geomType();
      if((type == GEntity::Line) || (type == GEntity::Plane)) toRemove = true;
      // Also remove if the model contains BL fields but this entity is
      // unequipped with one
      if(!toRemove && !blFields.empty()) {
        toRemove = true;
        for(std::size_t k = 0; k < blFields.size(); ++k) {
          if(blFields[k]->isEdgeBL(bndEntity->tag())) {
            toRemove = false;
            break;
          }
        }
      }

      if(toRemove) {
        boundary[j] = boundary.back();
        boundary.pop_back();
      }
      else
        ++j;
    }

    // Do the other stuffs
    HighOrderMeshFastCurving(entity, boundary, p);
  }

  double t2 = Cpu();
  Msg::StatusBar(true, "Done curving high order boundary layer mesh (%g s)",
                 t2 - t1);
}
