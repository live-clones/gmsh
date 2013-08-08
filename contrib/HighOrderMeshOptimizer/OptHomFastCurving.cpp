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

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string.h>
#include "GmshConfig.h"
#include "OptHomFastCurving.h"
#include "GModel.h"
#include "Gmsh.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MLine.h"
#include "OS.h"
#include <stack>
#include "SuperEl.h"
#include "SVector3.h"
#include "BasisFactory.h"



namespace {



void exportMeshToDassault(GModel *gm, const std::string &fn, int dim)
{
  FILE *f = fopen(fn.c_str(),"w");

  int numVertices = gm->indexMeshVertices(true);
  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  fprintf(f,"%d %d\n", numVertices, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      if (dim == 2)
        fprintf(f,"%d %22.15E %22.15E\n", v->getIndex(), v->x(), v->y());
      else if (dim == 3)
        fprintf(f,"%d %22.15E %22.15E %22.5E\n", v->getIndex(), v->x(),
                v->y(), v->z());
    }

  if (dim == 2){
    int nt = 0;
    int order  = 0;
    for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf){
      std::vector<MTriangle*> &tris = (*itf)->triangles;
      nt += tris.size();
      if (tris.size())order = tris[0]->getPolynomialOrder();
    }
    fprintf(f,"%d %d\n", nt,(order+1)*(order+2)/2);
    int count = 1;
    for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf){
      std::vector<MTriangle*> &tris = (*itf)->triangles;
      for (size_t i=0;i<tris.size();i++){
  MTriangle *t = tris[i];
  fprintf(f,"%d ", count++);
  for (int j=0;j<t->getNumVertices();j++){
    fprintf(f,"%d ", t->getVertex(j)->getIndex());
  }
  fprintf(f,"\n");
      }
    }
    int ne = 0;
    for (GModel::eiter ite = gm->firstEdge(); ite != gm->lastEdge(); ++ite){
      std::vector<MLine*> &l = (*ite)->lines;
      ne += l.size();
    }
    fprintf(f,"%d %d\n", ne,(order+1));
    count = 1;
    for (GModel::eiter ite = gm->firstEdge(); ite != gm->lastEdge(); ++ite){
      std::vector<MLine*> &l = (*ite)->lines;
      for (size_t i=0;i<l.size();i++){
  MLine *t = l[i];
  fprintf(f,"%d ", count++);
  for (int j=0;j<t->getNumVertices();j++){
    fprintf(f,"%d ", t->getVertex(j)->getIndex());
  }
  fprintf(f,"%d \n",(*ite)->tag());
      }
    }
  }
  fclose(f);
}



//double distMaxStraight(MElement *el)
//{
//  const polynomialBasis *lagrange = (polynomialBasis*)el->getFunctionSpace();
//  const polynomialBasis *lagrange1 = (polynomialBasis*)el->getFunctionSpace(1);
//  int nV = lagrange->points.size1();
//  int nV1 = lagrange1->points.size1();
//  SPoint3 sxyz[256];
//  for (int i = 0; i < nV1; ++i) {
//    sxyz[i] = el->getVertex(i)->point();
//  }
//  for (int i = nV1; i < nV; ++i) {
//    double f[256];
//    lagrange1->f(lagrange->points(i, 0), lagrange->points(i, 1),
//                 lagrange->points(i, 2), f);
//    for (int j = 0; j < nV1; ++j)
//      sxyz[i] += sxyz[j] * f[j];
//  }
//
//  double maxdx = 0.0;
//  for (int iV = nV1; iV < nV; iV++) {
//    SVector3 d = el->getVertex(iV)->point()-sxyz[iV];
//    double dx = d.norm();
//    if (dx > maxdx) maxdx = dx;
//  }
//
//  return maxdx;
//}



void calcVertex2Elements(int dim, GEntity *entity,
                                std::map<MVertex*, std::vector<MElement *> > &vertex2elements)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    if (element->getDim() == dim)
      for (int j = 0; j < element->getNumPrimaryVertices(); ++j)
        vertex2elements[element->getVertex(j)].push_back(element);
  }
}



//void getNormals2D(const std::vector<MVertex*> &edgeVert, SVector3 &n0, SVector3 &n1) {
//
////  if (v0->onWhat() != 0) {
//  if (false) {
//    GEdge *ent = edgeVert.front()->onWhat()->cast2Edge();
//    std::map<MVertex*, SVector3, std::less<MVertex*> > &allNormals = ent->getNormals();
//    n0 = allNormals[edgeVert[0]];
//    n1 = allNormals[edgeVert[1]];
//  }
//  else {
//    const int &Nsf = edgeVert.size();
//    const nodalBasis* fs = BasisFactory::getNodalBasis(nodalBasis::getTag(TYPE_LIN,Nsf-1,false));
//    double dsf0[Nsf][3], dsf1[Nsf][3];
//    fs->df(fs->points(0,0),0.,0.,dsf0);
//    fs->df(fs->points(1,0),0.,0.,dsf1);
//    double t0x = 0., t0y = 0., t1x = 0., t1y = 0.;
//    for (int i=0; i<Nsf; ++i) {
//      t0x += dsf0[i][0]*edgeVert[i]->x();
//      t0y += dsf0[i][0]*edgeVert[i]->y();
//      t1x += dsf1[i][0]*edgeVert[i]->x();
//      t1y += dsf1[i][0]*edgeVert[i]->y();
//    }
//    n0[0] = -t0y; n0[1] = t0x; n0[2] = 0.;
//    n0.normalize();
//    n1[0] = -t1y; n1[1] = t1x; n1[2] = 0.;
//    n1.normalize();
//  }
//
//}



//void getBaseVertsAndNormals(std::set<MElement*> badElts, std::map<MElement*,std::vector<MVertex*> > &faces,
//                                 std::map<MVertex*,SVector3> &normals) {
//
//  typedef std::map<MVertex*,std::vector<SVector3> > normalMap;
//  normalMap allNormals;
//
//  for (std::set<MElement*>::iterator itBE = badElts.begin(); itBE != badElts.end(); itBE++) {
//    std::vector<MVertex*> baseVert;
//    for (int i=0; i<(*itBE)->getNumEdges(); i++) {
//      (*itBE)->getEdgeVertices(i,baseVert);
//      if (isEdgeCurved(baseVert)) {
//        const SPoint3 p0 = baseVert[0]->point(), p1 = baseVert[1]->point(), pC = (*itBE)->barycenter(true);
//        SVector3 n(p0.y()-p1.y(), p1.x()-p0.x(), 0.), p0C(p0,pC);
//        if (dot(n,p0C) < 0.) n *= -1.;
//        n.normalize();
//        allNormals[baseVert[0]].push_back(n);
//        allNormals[baseVert[1]].push_back(n);
//        faces[*itBE] = baseVert;
//        break;
//      }
//    }
//  }
//
//  for(normalMap::iterator itAN = allNormals.begin(); itAN != allNormals.end(); itAN++) {
//    std::vector<SVector3> &normSet = itAN->second;
////    std::cout << "DBGTT: Considering node " << itAN->first->getNum() << "\n";
//    SVector3 norm(0.);
//    for (std::vector<SVector3>::iterator itN = normSet.begin(); itN != normSet.end(); itN++) {
////      std::cout << "DBGTT:  -> accumulating normal (" << itN->x() << ", "<< itN->y() << ", "<< itN->z() << ")\n";
//      norm += *itN;
//    }
//    norm *= 1./double(normSet.size());
//    normals[itAN->first] = norm;
//  }
//
//}



//bool isEdgeCurved(const std::vector<MVertex*> &edgeVert) {
//
//  static const double eps = 1.e-8;
//
//  const double n = edgeVert.size();
//  const MVertex *vS = edgeVert[0];
//  const double vSEx = edgeVert[1]->x()-vS->x(), vSEy = edgeVert[1]->y()-vS->y();
//  const double normSE = vSEx*vSEx+vSEy*vSEy;
//
//  double distSq = 0.;
//  for (int i=2; i<n; ++i) {
//    const double vSix = edgeVert[i]->x()-vS->x(), vSiy = edgeVert[i]->y()-vS->y();
//    const double fact = (vSix*vSEx+vSiy*vSEy)/normSE;
//    const double dvx = vSix-fact*vSEx, dvy = vSiy-fact*vSEy;
//    distSq += dvx*dvx+dvy*dvy;
//  }
//
//  return (distSq > eps*normSE);
//
//}



// Among edges connected to a given vertex, return the direction of the one that is closest to the given normal
// Return the given normal if no edge is sufficiently close
SVector3 getNormalEdge(MVertex *vert, const SVector3 &n,
                       const std::map<MVertex*, std::vector<MElement*> > &vertex2elements) {

//  static const double spLimit = 0.70711;                          // Limit in dot product below which we return the normal
  static const double spLimit = 0.5;                          // Limit in dot product below which we return the normal

  const std::vector<MElement*> &elts = (*vertex2elements.find(vert)).second;     // All elements connected to vertex

  double spMax = 0.;
  SVector3 normalEdge;
//  std::cout << "DBGTT: Looking for normal edge at vertex " << vert->getNum()
//              << " with n = (" << n.x() << ", " << n.y() << ", " << n.z() << ")\n";

  for (std::vector<MElement*>::const_iterator itEl = elts.begin(); itEl != elts.end(); ++itEl)
    for (int i=0; i<(*itEl)->getNumEdges(); i++) {
      std::vector<MVertex*> edgeVert;
      (*itEl)->getEdgeVertices(i,edgeVert);
      SVector3 edge;
      if (edgeVert[0] == vert) edge = SVector3(vert->point(),edgeVert[1]->point());
      else if (edgeVert[1] == vert) edge = SVector3(vert->point(),edgeVert[0]->point());
      else continue;
      edge.normalize();
      double sp = dot(edge,n);
      if (sp > spMax) {                                           // Retain the edge giving max. dot product with normal
        spMax = sp;
        normalEdge = edge;
      }
//      std::cout << "DBGTT:   -> checking edge " << edgeVert[0]->getNum() << " - " << edgeVert[1]->getNum()
//                  << ", sp = " << sp << "\n";
    }

  if (spMax < spLimit) { std::cout << "DBGTT: no normal edge\n"; normalEdge = n; }                            // If max. dot product is below limit, just take normal

  return normalEdge;

}



//// Detect whether edge/face is curved, and give (non-oriented) normal
//bool isCurvedAndNormal(int type, int order, const std::vector<MVertex*> &faceVert, SVector3 &normal) {
//
//  static const double eps = 1.e-8;
//
//  const nodalBasis *lagrange = BasisFactory::getNodalBasis(ElementType::getTag(type,order,false));
//  const nodalBasis *lagrange1 = BasisFactory::getNodalBasis(ElementType::getTag(type,1,false));
//  int nV = lagrange->points.size1();
//  int nV1 = lagrange1->points.size1();
//  SPoint3 sxyz[256];
//  for (int i = 0; i < nV1; ++i) sxyz[i] = faceVert[i]->point();
//  for (int i = nV1; i < nV; ++i) {
//    double f[256];
//    lagrange1->f(lagrange->points(i, 0), lagrange->points(i, 1), lagrange->points(i, 2), f);
//    for (int j = 0; j < nV1; ++j)
//      sxyz[i] += sxyz[j] * f[j];
//  }
//
//  double sumDistSq = 0.;
//  for (int iV = nV1; iV < nV; iV++) sumDistSq += SVector3(sxyz[iV],faceVert[iV]->point()).normSq();
//
//  double scale;
//  if (type == TYPE_LIN) {
//    const SPoint3 &p0 = sxyz[0], &p1 = sxyz[1];
//    normal = SVector3(p0.y()-p1.y(),p1.x()-p0.x(),0.);
//    scale = normal.normSq();
//  }
//  else {
//    const SPoint3 &p0 = sxyz[0], &p1 = sxyz[1], &p2 = sxyz[2];
//    SVector3 p01(p0,p1), p02(p0,p2);
//    normal = crossprod(p01,p02);
//    scale = normal.norm();
//  }
//  normal.normalize();
//
////  std::cout << "DBGTT: v0 is " << faceVert[0]->getNum() << ", v1 is " << faceVert[1]->getNum() << ", sumDistSq = " << sumDistSq << ", scale = " << scale << ", test = " << (sumDistSq > eps*double(nV)*scale) << "\n";
//  return (sumDistSq > eps*double(nV)*scale);
//
//}
//
//
//
//void getBaseVertsAndNormals(std::set<MElement*> badElts,
//                              const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
//                              std::map<MElement*,int> &baseType,
//                              std::map<MElement*,std::vector<MVertex*> > &baseVert,
//                              std::map<MElement*,std::vector<SVector3> > &normals) {
//
//  for (std::set<MElement*>::iterator itBE = badElts.begin(); itBE != badElts.end(); itBE++) {
//    const bool is2D = ((*itBE)->getDim() == 2);
//    const int order = (*itBE)->getPolynomialOrder();
//    const int numFaces = is2D ? (*itBE)->getNumEdges() : (*itBE)->getNumFaces();
//    for (int iFace=0; iFace<numFaces; iFace++) {            // Loop on edges/faces
//      std::vector<MVertex*> bv;                             // Vertices of edge/face
//      int type, numPrimVert;
//      if (is2D) {
//        (*itBE)->getEdgeVertices(iFace,bv);
//        type = TYPE_LIN;
//        numPrimVert = 2;
//      }
//      else {
//        (*itBE)->getFaceVertices(iFace,bv);
//        MFace face = (*itBE)->getFace(iFace);
//        numPrimVert = face.getNumVertices();
//        type = (numPrimVert == 3) ? TYPE_TRI : TYPE_QUA;
//      }
//      SVector3 n;                                           // Normal to straight edge/face
//      if (isCurvedAndNormal(type,order,bv,n)) {             // Check whether edge/face is curved and compute straight normal
//        std::cout << "DBGTT: Curved edge/face in el. " << (*itBE)->getNum() << "\n";
//        if (baseVert.find(*itBE) != baseVert.end()) {       // If more than 1 curved edge/face in bad el., drop it
//          baseVert.erase(*itBE);
//          normals.erase(*itBE);
//          std::cout << "DBGTT: More than 1 curved edge/face detected in el. " << (*itBE)->getNum() << "\n";
//          break;
//        }
//        baseType[*itBE] = type;
//        baseVert[*itBE] = bv;
//        const SPoint3 p0 = bv[0]->point(), pC = (*itBE)->barycenter(true);
//        SVector3 p0C(p0,pC);
//        if (dot(n,p0C) < 0.) n *= -1.;                                      // Make straight normal in-going
//        for (int iV=0; iV<numPrimVert; iV++)                                // Compute normals to prim. vert. of edge/face
//          normals[*itBE].push_back(getNormalEdge(bv[iV],n,vertex2elements));
//      }
//    }
//  }
//
//}



// Detect whether edge/face is curved, and give normal
bool isCurvedAndNormal(int type, int order, const std::vector<MVertex*> &faceVert,
                       const SPoint3 pBar, SVector3 &normal, double &maxDist) {

//  static const double eps = 1.e-10;
  static const double eps = 1.e-6;

  // Compute HO points in straight edge/face
  const nodalBasis *lagrange = BasisFactory::getNodalBasis(ElementType::getTag(type,order,false));
  const nodalBasis *lagrange1 = BasisFactory::getNodalBasis(ElementType::getTag(type,1,false));
  int nV = lagrange->points.size1();
  int nV1 = lagrange1->points.size1();
  SPoint3 sxyz[256];
  for (int i = 0; i < nV1; ++i) sxyz[i] = faceVert[i]->point();
  for (int i = nV1; i < nV; ++i) {
    double f[256];
    lagrange1->f(lagrange->points(i, 0), lagrange->points(i, 1), lagrange->points(i, 2), f);
    for (int j = 0; j < nV1; ++j)
      sxyz[i] += sxyz[j] * f[j];
  }

  // Compute (non-oriented) unit normal to straight edge/face and its scale [length]
  double scale;
  const SPoint3 &p0 = sxyz[0], &p1 = sxyz[1];
  if (type == TYPE_LIN) {
    normal = SVector3(p0.y()-p1.y(),p1.x()-p0.x(),0.);
    scale = normal.normalize();
  }
  else {
    const SPoint3 &p2 = sxyz[2];
    SVector3 p01(p0,p1), p02(p0,p2);
    normal = crossprod(p01,p02);
    scale = sqrt(normal.normalize());
  }

  // Orient normal with help of pBar
  SVector3 p0C(p0,pBar);
  if (dot(normal,p0C) < 0.) normal *= -1.;                                      // Make straight normal in-going

  // Calc max. normal dist. from straight to HO points
  maxDist = 0.;
  for (int iV = nV1; iV < nV; iV++) {
    const double normalDisp = dot(SVector3(sxyz[iV],faceVert[iV]->point()),normal);
    maxDist = std::max(maxDist,fabs(normalDisp));
  }

  std::cout << "DBGTT: v0 is " << faceVert[0]->getNum() << ", v1 is " << faceVert[1]->getNum()
            << ", v2 is " << faceVert[2]->getNum() << ", maxDist = " << maxDist
            << ", scale = " << scale << ", test = " << (maxDist > eps*scale) << "\n";
  return (maxDist > eps*scale);

}



bool getCurvedFace(MElement* badEl,
                   const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                   std::vector<MVertex*> &baseVert, std::vector<SVector3> &normals,
                   int &baseType, double &baseMaxDist) {

  bool found = false;
  const int dim = badEl->getDim();
  const int order = badEl->getPolynomialOrder();
  const int numFaces = (dim == 2) ? badEl->getNumEdges() : badEl->getNumFaces();

  for (int iFace=0; iFace<numFaces; iFace++) {            // Loop on edges/faces

    // Get face info (type, vertices)
    std::vector<MVertex*> bv;                             // Vertices of edge/face
    int numPrimVert, type;
    if (dim == 2) {
      badEl->getEdgeVertices(iFace,bv);
      type = TYPE_LIN;
      numPrimVert = 2;
    }
    else {
      badEl->getFaceVertices(iFace,bv);
      MFace face = badEl->getFace(iFace);
      numPrimVert = face.getNumVertices();
      type = (numPrimVert == 3) ? TYPE_TRI : TYPE_QUA;
    }

    // Skip face if at least 1 vertex not on boundary
    bool inDom = false;
    for (int iV=0; iV<bv.size(); ++iV)
      if (bv[iV]->onWhat()->dim() == dim) inDom = true;
    if (inDom) continue;

    //    std::cout << "DBGTT: Checking edge/face " << iFace << " in el. " << badEl->getNum() << ": "
//              << numPrimVert << " vert., type " << type << "\n";
    // If face curved, mark it and compute normals to its primary vertices
    SVector3 n;                                                           // Normal to straight edge/face
    double maxDist;                                                       // TOFIX: Max. normal. dist. to straight in curved face
    const SPoint3 pBar = badEl->barycenter(true);                         // Bary. of el. to help orienting normal
    if (isCurvedAndNormal(type,order,bv,pBar,n,maxDist)) {                // Check whether edge/face is curved and compute straight normal
      std::cout << "DBGTT: Curved edge/face in el. " << badEl->getNum() << "\n";
      if (found) {                                                        // If more than 1 curved edge/face in bad el., drop it
        std::cout << "DBGTT: More than 1 curved edge/face detected in el. " << badEl->getNum() << "\n";
        return false;
      }
      for (int iV=0; iV<numPrimVert; iV++)                                // Compute normals to prim. vert. of edge/face
        normals.push_back(getNormalEdge(bv[iV],n,vertex2elements));
      baseVert = bv;
      baseType = type;
      baseMaxDist = maxDist;
      found = true;
    }

  }

  return found;

}



void makeStraight(MElement *el, const std::set<MVertex*> &movedVert) {

  const nodalBasis *nb = el->getFunctionSpace();
  const fullMatrix<double> &pts = nb->points;

  SPoint3 p;

  for(int iPt = el->getNumPrimaryVertices(); iPt < el->getNumVertices(); ++iPt) {
    MVertex *vert = el->getVertex(iPt);
    if (movedVert.find(vert) == movedVert.end()) {
      el->primaryPnt(pts(iPt,0),pts(iPt,1),pts(iPt,2),p);
      vert->setXYZ(p.x(),p.y(),p.z());
    }
  }

}



std::set<MElement*> getSuperElBlob(MElement *el, const std::map<MVertex*,
                                   std::vector<MElement*> > &vertex2elements,
                                   const SuperEl *sEl)
{

  static const int depth = 100;

  std::set<MElement*> blob;
  std::list<MElement*> currentLayer, lastLayer;

  blob.insert(el);
  lastLayer.push_back(el);
  for (int d = 0; d < depth; ++d) {
    currentLayer.clear();
    for (std::list<MElement*>::iterator it = lastLayer.begin();
         it != lastLayer.end(); ++it) {
      for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
        const std::vector<MElement*> &neighbours = vertex2elements.find
          ((*it)->getVertex(i))->second;
        for (std::vector<MElement*>::const_iterator itN = neighbours.begin();
             itN != neighbours.end(); ++itN){
          if (sEl->isPointIn((*itN)->barycenter(true))) {
            // Assume that if an el is too far, its neighbours are too far as well
            if (blob.insert(*itN).second) currentLayer.push_back(*itN);
          }
        }
      }
    }
    lastLayer = currentLayer;
    if (currentLayer.empty()) break;
  }

  return blob;
}



void curveMesh(std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
               std::set<MElement*> &badElements, FastCurvingParameters &p, int samples)
{

  const int nbBadElts = badElements.size();
  std::vector<MElement*> badElts;
//  std::vector<int> types;
//  std::vector<std::vector<MVertex*> > faces;
//  std::vector<std::vector<SVector3> > &normals;
//  std::vector<double> &maxDist;
  std::vector<SuperEl*> superElts;
  badElts.reserve(nbBadElts);
//  types.reserve(nbBadElts);
//  faces.reserve(nbBadElts);
//  normals.reserve(nbBadElts);
//  maxDist.reserve(nbBadElts);
  superElts.reserve(nbBadElts);

  std::ofstream of("dum.pos");
  of << "View \" \"{\n";

  for (std::set<MElement*>::const_iterator itBE = badElements.begin(); itBE != badElements.end(); ++itBE) {
    std::vector<MVertex*> faceBE;
    std::vector<SVector3> normalsBE;
    int typeBE;
    double maxDistBE;
    if (getCurvedFace(*itBE,vertex2elements,faceBE,normalsBE,typeBE,maxDistBE)) {
      badElts.push_back(*itBE);
//      types.push_back(typeBE);
//      faces.push_back(faceBE);
//      normals.push_back(normalsBE);
//      maxDist.push_back(maxDistBE);
      superElts.push_back(new SuperEl(*itBE,maxDistBE*p.distanceFactor,typeBE,faceBE,normalsBE));
//      superElts.push_back(new SuperEl(*itBE,distMaxStraight(*itBE)*p.distanceFactor,typeBE,faceBE,normalsBE));
//      movedVert.insert(faceBE.begin(),faceBE.end());                                                // Do not touch vert. of curved face
      of << superElts.back()->printPOS();
    }
  }

  of << "};\n";
  of.close();

  std::set<MVertex*> movedVert;
  for (int iBE=0; iBE<badElts.size(); ++iBE) {
//    std::set<MElement*> blob = getSurroundingBlob(badElts[iBE], p.nbLayers, vertex2elements, p.distanceFactor);
    std::set<MElement*> blob = getSuperElBlob(badElts[iBE], vertex2elements, superElts[iBE]);
    std::cout << "DBGTT: Blob of bad el. " << badElts[iBE]->getNum() << " contains elts.";
    for (std::set<MElement*>::iterator itE = blob.begin(); itE != blob.end(); ++itE) std::cout << " " << (*itE)->getNum();
    std::cout << "\n";
    makeStraight(badElts[iBE],movedVert);                                             // Make bad. el. straight
    for (std::set<MElement*>::iterator itE = blob.begin(); itE != blob.end(); ++itE)
      for (int i = 0; i < (*itE)->getNumVertices(); ++i) {                            // For each vert. of each el. in blob
        MVertex* vert = (*itE)->getVertex(i);
        if (movedVert.find(vert) == movedVert.end()) {                                // If vert. not already moved
          double xyzS[3] = {vert->x(), vert->y(), vert->z()}, xyzC[3];
          if (superElts[iBE]->straightToCurved(xyzS,xyzC)) {
            std::cout << "DBGTT: moving vertex " << vert->getNum() << " from (" << xyzS[0] << "," << xyzS[1] << "," << xyzS[2] << ") to (" << xyzC[0] << "," << xyzC[1] << "," << xyzC[2] << ")\n";
            vert->setXYZ(xyzC[0],xyzC[1],xyzC[2]);
            movedVert.insert(vert);
          }
          else std::cout << "DBGTT: Failed to move vertex " << vert->getNum() << " with bad. el " << badElts[iBE]->getNum() << "\n";
        }
//        else std::cout << "DBGTT: Already moved vertex " << vert->getNum() << " with bad. el " << badElts[iBE]->getNum() << "\n";
      }
  }

}



}



//static void optimizeBL(std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
//                       std::set<MElement*> &badElements, OptHomParameters &p, int samples)
//{
//
//  const int nbBadElts = badElements.size();
//  std::vector<MElement*> &badElts();
//  std::map<MElement*,int> types;                                 // Type (LIN, TRI, QUA) of curved face in bad. el.
//  std::map<MElement*,std::vector<MVertex*> > faces;              // Vertices of curved face in bad. el.
//  std::map<MElement*,std::vector<SVector3> > normals;            // Normal to each prim. vertex of curved face in bad. el.
//  getBaseVertsAndNormals(badElements,vertex2elements,types,faces,normals);
//
//  std::ofstream of("dum.pos");
//  of << "View \" \"{\n";
//
//  for (std::set<MElement*>::const_iterator itBE = badElements.begin(); itBE != badElements.end(); ++itBE) {
//
//    if (faces.find(*itBE) == faces.end()) continue;           // No base edge/face -> no super el. for this bad. el.
//
//    SuperEl se(*itBE,distMaxStraight(*itBE)*p.distanceFactor,types[*itBE],faces[*itBE],normals[*itBE]);
//
//    std::set<MElement*> blob = getSurroundingBlob(*itBE, p.nbLayers, vertex2elements, p.distanceFactor);
//    std::set<MVertex*> toMove;
//    for (std::set<MElement*>::iterator itE = blob.begin(); itE != blob.end(); ++itE)
//      for (int i = 0; i < (*itE)->getNumVertices(); ++i) toMove.insert((*itE)->getVertex(i));
//
////    std::cout << "DBGTT: Before makeStraight:\n";
////    se.printCoord();
//    makeStraight(*itBE);                                      // Make bad. el. straight
////    for (std::set<MElement*>::iterator itE = blob.begin(); itE != blob.end(); ++itE) makeStraight(*itE);
////    std::cout << "DBGTT: After makeStraight:\n";
////    se.printCoord();
//
//    // Apply transformation straight -> curved to all vertices in super el.
//    for (std::set<MVertex*>::iterator itV = toMove.begin(); itV != toMove.end(); ++itV) {
//      double xyzS[3] = {(*itV)->x(), (*itV)->y(), (*itV)->z()}, xyzC[3];
//      if (se.straightToCurved(xyzS,xyzC)) {
////        std::cout << "DBGTT: moving vertex " << (*itV)->getNum() << " from (" << xyzS[0] << "," << xyzS[1] << "," << xyzS[2] << ") to (" << xyzC[0] << "," << xyzC[1] << "," << xyzC[2] << ")\n";
//        (*itV)->setXYZ(xyzC[0],xyzC[1],xyzC[2]);
//      }
//      else std::cout << "DBGTT: Failed to move vertex " << (*itV)->getNum() << " with bad. el " << (*itBE)->getNum() << "\n";
//    }
//
////    std::cout << se.printPOS();
//    of << se.printPOS();
//
//  }
//
//  of << "};\n";
//  of.close();
//
//}



void HighOrderMeshFastCurving(GModel *gm, FastCurvingParameters &p)
{

  double t1 = Cpu();

  int samples = 30;

  double tf1 = Cpu();

  Msg::StatusBar(true, "Optimizing high order mesh...");
  std::vector<GEntity*> entities;
  gm->getEntities(entities);

  std::map<MVertex*, std::vector<MElement *> > vertex2elements;
  std::set<MElement*> badasses;
  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != p.dim || (p.onlyVisible && !entity->getVisibility())) continue;
    Msg::Info("Computing connectivity and bad elements for entity %d...",
              entity->tag());
    calcVertex2Elements(p.dim,entity,vertex2elements); // Compute vert. -> elt. connectivity
//    std::cout << "DBGTT: num. el. = " << entity->getNumMeshElements() << "\n";
    for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) { // Detect bad elements
      double jmin, jmax;
      MElement *el = entity->getMeshElement(iEl);
      if (el->getDim() == p.dim) {
        el->scaledJacRange(jmin, jmax);
//        std::cout << "El. " << iEl << ", jmin = " << jmin << ", jmax = " << jmax << "\n";
//        Msg::Info("El %i, jmin = %g, jmax = %g\n",iEl,jmin,jmax);
        if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX) badasses.insert(el);
      }
    }
  }

  curveMesh(vertex2elements, badasses, p, samples);

  double t2 = Cpu();

  Msg::StatusBar(true, "Done curving high order mesh (%g s)", t2-t1);

}
