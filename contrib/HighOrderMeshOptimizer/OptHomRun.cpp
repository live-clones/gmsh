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

#include <stdio.h>
#include <sstream>
#include <iterator>
#include <string.h>
#include "GmshConfig.h"
#include "OptHOM.h"
#include "OptHomRun.h"
#include "OptHomPeriodicity.h"
#include "GModel.h"
#include "Gmsh.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MLine.h"
#include "CADDistances.h"
#include "OS.h"
#include <stack>

#if defined(HAVE_BFGS)

typedef std::vector<MElement*> elVec;
typedef elVec::const_iterator elVecConstIter;
typedef std::set<MElement*, Less_ElementPtr> elSet;
typedef elSet::iterator elSetIter;
typedef std::set<MVertex*> vertSet;

typedef std::map<MVertex*, elVec> vertElVecMap;
typedef std::map<MElement*, elSet> elElSetMap;
typedef std::pair<elSet, vertSet> elSetVertSetPair;

double distMaxStraight(MElement *el)
{
  const polynomialBasis *lagrange = (polynomialBasis*)el->getFunctionSpace();
  const polynomialBasis *lagrange1 = (polynomialBasis*)el->getFunctionSpace(1);
  int nV = lagrange->points.size1();
  int nV1 = lagrange1->points.size1();
  int dim = lagrange1->dimension;
  SPoint3 sxyz[256];
  for (int i = 0; i < nV1; ++i) {
    sxyz[i] = el->getVertex(i)->point();
  }
  for (int i = nV1; i < nV; ++i) {
    double f[256];
    lagrange1->f(lagrange->points(i, 0), lagrange->points(i, 1),
                 dim < 3 ? 0 : lagrange->points(i, 2), f);
    for (int j = 0; j < nV1; ++j)
      sxyz[i] += sxyz[j] * f[j];
  }

  double maxdx = 0.0;
  for (int iV = nV1; iV < nV; iV++) {
    SVector3 d = el->getVertex(iV)->point()-sxyz[iV];
    double dx = d.norm();
    if (dx > maxdx) maxdx = dx;
  }

  return maxdx;
}

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

static vertSet getAllBndVertices(elSet &elements, const vertElVecMap &vertex2elements)
{
  vertSet bnd;
  for (elSetIter itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const elVec &neighbours = vertex2elements.find
        ((*itE)->getVertex(i))->second;
      for (size_t k = 0; k < neighbours.size(); ++k) {
        if (elements.find(neighbours[k]) == elements.end()) {
          for (int j = 0; j < neighbours[k]->getNumVertices(); ++j) {
            bnd.insert(neighbours[k]->getVertex(j));
          }
        }
      }
    }
  }
  return bnd;
}


// Test intersection between sphere and segment
static bool testSegSphereIntersect(SPoint3 A, SPoint3 B, const SPoint3& P, const double rr)
{
  // Test if separating plane between sphere and segment vertices
  // For each vertex, separation if vertex is outside sphere and P on opposite side
  // to other seg. vertex w.r.t plane of normal (vertex-P) through vertex
  const SVector3 PA(P, A), PB(P, B);
  const double aa = dot(PA, PA), ab = dot(PA, PB);
  if ((aa > rr) & (ab > aa)) return false;
  const double  bb = dot(PB, PB);
  if ((bb > rr) & (ab > bb)) return false;

  // Test if separating plane between sphere and line
  // For A, separation if projection Q of P on (AB) lies outside the sphere
  const SVector3 AB(A, B);
  const double d = ab - aa, e = dot(AB, AB);
  const  SVector3 PQ = PA * e - d * AB;
  if (dot(PQ, PQ) > rr * e * e) return false;

  // Return true (intersection) if no separation at all
  return true;
}


// Test intersection between sphere and triangle
// Inspired by Christer Ericson, http://realtimecollisiondetection.net/blog/?p=103
static bool testTriSphereIntersect(SPoint3 A, SPoint3 B, SPoint3 C,
                                   const SPoint3& P, const double rr)
{
  // Test if separating plane between sphere and triangle plane
  const SVector3 PA(P, A), AB(A, B), AC(A, C);
  const SVector3 V = crossprod(AB, AC);                                   // Normal to triangle plane
  const double d = dot(PA, V);                                            // Dist. from P to triangle plane times norm of V
  const double e = dot(V, V);                                             // Norm of V
  if (d * d > rr * e) return false;                                       // Test if separating plane between sphere and triangle plane

  // Test if separating plane between sphere and triangle vertices
  const SVector3 PB(P, B), PC(P, B);
  const double aa = dot(PA, PA), ab = dot(PA, PB), ac = dot(PA, PC);
  const double bb = dot(PB, PB), bc = dot(PB, PC), cc = dot(PC, PC);
  if ((aa > rr) & (ab > aa) & (ac > aa)) return false;                    // For each triangle vertex, separation if vertex is outside sphere
  if ((bb > rr) & (ab > bb) & (bc > bb)) return false;                    // and P on opposite side to other two triangle vertices w.r.t
  if ((cc > rr) & (ac > cc) & (bc > cc)) return false;                    // plane of normal (vertex-P) through vertex

  // Test if separating plane between sphere and triangle edges
  const SVector3 BC(B, C);
  const double d1 = ab - aa, d2 = bc - bb, d3 = ac - cc;
  const double e1 = dot(AB, AB), e2 = dot(BC, BC), e3 = dot(AC, AC);
  const SVector3 PQ1 = PA * e1 - d1 * AB;                                 // Q1 projection of P on line (AB)
  const SVector3 PQ2 = PB * e2 - d2 * BC;                                 // Q2 projection of P on line (BC)
  const SVector3 PQ3 = PC * e3 + d3 * AC;                                 // Q3 projection of P on line (AC)
  const SVector3 PQC = PC * e1 - PQ1;
  const SVector3 PQA = PA * e2 - PQ2;
  const SVector3 PQB = PB * e3 - PQ3;
  if ((dot(PQ1, PQ1) > rr * e1 * e1) & (dot(PQ1, PQC) > 0)) return false; // For A, separation if Q lies outside the sphere and if P and C
  if ((dot(PQ2, PQ2) > rr * e2 * e2) & (dot(PQ2, PQA) > 0)) return false; // are on opposite sides of plane through AB with normal PQ
  if ((dot(PQ3, PQ3) > rr * e3 * e3) & (dot(PQ3, PQB) > 0)) return false; // Same for other two vertices

  // Return true (intersection) if no separation at all
  return true;
}

// Approximate test of intersection element with circle/sphere by sampling
static bool testElInDist(const SPoint3 p, double limDist, MElement *el)
{
  const double limDistSq = limDist*limDist;

  if (el->getDim() == 2) {                                                // 2D?
    for (int iEd = 0; iEd < el->getNumEdges(); iEd++) {                   // Loop over edges of element
      std::vector<MVertex*> edgeVert;
      el->getEdgeVertices(iEd, edgeVert);
      const SPoint3 A = edgeVert[0]->point();
      const SPoint3 B = edgeVert[1]->point();
      if (testSegSphereIntersect(A, B, p, limDistSq)) return true;
    }
  }
  else {                                                                  // 3D
    for (int iFace = 0; iFace < el->getNumFaces(); iFace++) {             // Loop over faces of element
      std::vector<MVertex*> faceVert;
      el->getFaceVertices(iFace, faceVert);
      const SPoint3 A = faceVert[0]->point();
      const SPoint3 B = faceVert[1]->point();
      const SPoint3 C = faceVert[2]->point();
      if (faceVert.size() == 3)
        if (testTriSphereIntersect(A, B, C, p, limDistSq)) return true;
      else {
        const SPoint3 D = faceVert[3]->point();
        if (testTriSphereIntersect(A, B, C, p, limDistSq) ||
            testTriSphereIntersect(A, C, D, p, limDistSq)) return true;
      }
    }
  }

  return false;
}

// Get neighbours of element (computes and store them only if needed)
static void getElementNeighbours(MElement *el, const vertElVecMap &v2e,
                                 elElSetMap &e2e, elSet &neighbours)
{
  elElSetMap::iterator it = e2e.find(el);
  if (it == e2e.end()) {                                                          // If not in e2e, compute and store
    neighbours.clear();
    for (int i = 0; i < el->getNumPrimaryVertices(); ++i) {
      const elVec &adjEl = v2e.find(el->getVertex(i))->second;
      for(elVecConstIter itA = adjEl.begin(); itA != adjEl.end(); itA++)
        if (*itA != el) neighbours.insert(*itA);
    }
    e2e.insert(std::pair<MElement*, elSet>(el, neighbours));
  }
  else neighbours = it->second;
}

static elSet getSurroundingBlob(MElement *el, int maxLayers,
                                const vertElVecMap &vertex2elements,
                                elElSetMap &element2elements, const double distFactor,
                                int minLayers, bool optPrimSurfMesh)
{
  const SPoint3 p = el->barycenter(true);
  const double dist = el->maxDistToStraight();
  const double limDist = ((optPrimSurfMesh && (dist < 1.e-10)) ?
                          el->getOuterRadius() : dist) * distFactor;

  elSet blob, currentLayer, lastLayer, outOfDist;

  blob.insert(el);
  lastLayer.insert(el);
  for (int d = 0; d < maxLayers; ++d) {
    currentLayer.clear();
    for (elSetIter it = lastLayer.begin(); it != lastLayer.end(); ++it) {             // Loop over elements in last layer
      elSet neighbours;
      getElementNeighbours(*it, vertex2elements, element2elements, neighbours);
      for (elSetIter itN = neighbours.begin(); itN != neighbours.end(); ++itN) {      // Loop over neighbours
        if (lastLayer.find(*itN) == lastLayer.end()) {                                // If neighbour already in last layer, skip
          bool isInserted = false;
          if (d < minLayers) isInserted = blob.insert(*itN).second;                   // Below minLayers: insert neighbour in blob
          else if (outOfDist.find(*itN) == outOfDist.end()) {                         // Above minLayers: check distance criterion
            if (testElInDist(p, limDist, *itN))
              isInserted = blob.insert(*itN).second;
            else
              outOfDist.insert(*itN);
          }
          if (isInserted) currentLayer.insert(*itN);                                  // If inserted in blob, insert in current layer
        }
      }
    }
    lastLayer = currentLayer;
  }

  return blob;
}

static void addBlobChaintoGroup(std::set<int> &group,
                                const std::vector<std::set<int> > &groupConnect,
                                std::vector<bool> &todoPB, int iB)
{
  if (todoPB[iB]) {
    todoPB[iB] = false;
    group.insert(iB);
    const std::set<int> &connect = groupConnect[iB];
    for (std::set<int>::const_iterator itBC = connect.begin(); itBC != connect.end(); ++itBC)
      addBlobChaintoGroup(group, groupConnect, todoPB, *itBC);
  }
}

static void calcVertex2Elements(int dim, GEntity *entity, vertElVecMap &vertex2elements)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    if (element->getDim() == dim)
      for (int j = 0; j < element->getNumPrimaryVertices(); ++j)
        vertex2elements[element->getVertex(j)].push_back(element);
  }
}

static void calcElement2Entity(GEntity *entity, std::map<MElement*,GEntity*> &element2entity)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    element2entity.insert(std::pair<MElement*, GEntity*>(element, entity));
  }
}

static std::vector<elSetVertSetPair> getConnectedBlobs
  (const vertElVecMap &vertex2elements,
   const elSet &badElements, int depth, const double distFactor,
   bool weakMerge, bool optPrimSurfMesh)
{

  Msg::Info("Starting blob generation from %i bad elements...", badElements.size());

  elElSetMap element2elements;                                                            // Element to element connectivity, built progressively

  // Contruct primary blobs
  Msg::Info("Constructing %i primary blobs", badElements.size());
  std::vector<elSet> primBlobs;
  primBlobs.reserve(badElements.size());
  for (elSet::const_iterator it = badElements.begin(); it != badElements.end(); ++it) {
    const int minLayers = ((*it)->getDim() == 3) ? 1 : 0;
    primBlobs.push_back(getSurroundingBlob(*it, depth, vertex2elements, element2elements,
                                distFactor, minLayers, optPrimSurfMesh));
  }

  // Compute blob connectivity
  Msg::Info("Computing blob connectivity...");
  std::map<MElement*, std::set<int> > tags;
  std::vector<std::set<int> > blobConnect(primBlobs.size());
  for (int iB = 0; iB < primBlobs.size(); ++iB) {
    elSet &blob = primBlobs[iB];
    for(elSetIter itEl = blob.begin(); itEl != blob.end(); ++itEl) {
      std::set<int> &blobInd = tags[*itEl];
      if (!blobInd.empty() && (badElements.find(*itEl) != badElements.end() ||
                               !weakMerge)) {
        for (std::set<int>::iterator itBS = blobInd.begin();
             itBS != blobInd.end(); ++itBS) blobConnect[*itBS].insert(iB);
        blobConnect[iB].insert(blobInd.begin(), blobInd.end());
      }
      blobInd.insert(iB);
    }
  }

  // Identify groups of connected blobs
  Msg::Info("Identifying groups of primary blobs...");
  std::list<std::set<int> > groups;
  std::vector<bool> todoPB(primBlobs.size(), true);
  for (int iB = 0; iB < primBlobs.size(); ++iB)
    if (todoPB[iB]) {
      std::set<int> group;
      addBlobChaintoGroup(group, blobConnect, todoPB, iB);
      groups.push_back(group);
    }

  // Merge primary blobs according to groups
  Msg::Info("Merging primary blobs into %i blobs...", groups.size());
  std::list<elSet> blobs;
  for (std::list<std::set<int> >::iterator itG = groups.begin();
       itG != groups.end(); ++itG) {
    blobs.push_back(elSet());
    for (std::set<int>::iterator itB = itG->begin(); itB != itG->end(); ++itB) {
      elSet primBlob = primBlobs[*itB];
      blobs.back().insert(primBlob.begin(), primBlob.end());
    }
  }

  // Store and compute blob boundaries
  Msg::Info("Computing boundaries for %i blobs...", blobs.size());
  std::vector<elSetVertSetPair> result;
  for (std::list<elSet>::iterator itB = blobs.begin();
       itB != blobs.end(); ++itB)
    result.push_back(elSetVertSetPair
                     (*itB, getAllBndVertices(*itB, vertex2elements)));

  Msg::Info("Generated %i blobs", blobs.size());

  return result;
}

static void optimizeConnectedBlobs(const vertElVecMap &vertex2elements,
                                   const std::map<MElement*,GEntity*> &element2entity,
                                   elSet &badasses, OptHomParameters &p,
                                   int samples, bool weakMerge = false)
{
  p.SUCCESS = 1;
  p.minJac = 1.e100;
  p.maxJac = -1.e100;

  std::vector<elSetVertSetPair> toOptimize =
                          getConnectedBlobs(vertex2elements, badasses, p.nbLayers,
                                    p.distanceFactor, weakMerge, p.optPrimSurfMesh);
  p.numBlobs = static_cast<int>(toOptimize.size());

  //#pragma omp parallel for schedule(dynamic, 1)
  for (int i = 0; i < toOptimize.size(); ++i) {
//    if (toOptimize[i].first.size() > 10000) continue;
    Msg::Info("Optimizing a blob %i/%i composed of %4d elements", i+1,
              toOptimize.size(), toOptimize[i].first.size());
    fflush(stdout);
    OptHOM temp(element2entity, toOptimize[i].first, toOptimize[i].second, p.fixBndNodes);
    //std::ostringstream ossI1;
    //ossI1 << "initial_blob-" << i << ".msh";
    //temp.mesh.writeMSH(ossI1.str().c_str());
    int success = -1;
    if (temp.mesh.nPC() == 0)
      Msg::Info("Blob %i has no degree of freedom, skipping", i+1);
    else
      success = temp.optimize(p.weight, p.optCADWeight, p.BARRIER_MIN, p.BARRIER_MAX,
                              false, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,
                              p.discrTolerance);
    if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
      Msg::Info("Jacobian optimization succeed, starting svd optimization");
      success = temp.optimize(p.weight, p.optCADWeight, p.BARRIER_MIN_METRIC, p.BARRIER_MAX,
                              true, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,
                              p.discrTolerance);
    }
    double minJac, maxJac, distMaxBND, distAvgBND;
    temp.recalcJacDist();
    temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
    p.minJac = std::min(p.minJac,minJac);
    p.maxJac = std::max(p.maxJac,maxJac);
    temp.mesh.updateGEntityPositions();
    //if (success <= 0) {
      //std::ostringstream ossI2;
      //ossI2 << "final_ITER_" << i << ".msh";
      //temp.mesh.writeMSH(ossI2.str().c_str());
    //}
    //#pragma omp critical
    p.SUCCESS = std::min(p.SUCCESS, success);
  }

}

static MElement *getWorstElement(elSet &badasses, OptHomParameters &p)
{
  double worst = 1.e300;
  MElement *worstEl = 0;

  for (elSetIter it=badasses.begin(); it!=badasses.end(); it++) {
    double jmin, jmax, val;
    (*it)->scaledJacRange(jmin,jmax);
    val = jmin-p.BARRIER_MIN + p.BARRIER_MAX-jmax;
    if (val < worst) {
      worst = val;
      worstEl = *it;
    }
  }

  return worstEl;
}

static void optimizeOneByOne
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::map<MElement*,GEntity*> &element2entity,
   elSet badElts, OptHomParameters &p, int samples)
{
  p.SUCCESS = 1;
  p.minJac = 1.e100;
  p.maxJac = -1.e100;

  const int initNumBadElts = badElts.size();
  Msg::Info("%d badasses, starting to iterate...", initNumBadElts);
  p.numBlobs = initNumBadElts;

  elElSetMap element2elements;                                          // Element to element connectivity, built progressively

  for (int iBadEl=0; iBadEl<initNumBadElts; iBadEl++) {

    if (badElts.empty()) break;

    // Create blob around worst element and remove it from badElts
    MElement *worstEl = getWorstElement(badElts,p);
    badElts.erase(worstEl);

    int nbLayers = p.nbLayers;
    double distanceFactor = p.distanceFactor;

    int success;

    for (int iterBlob=0; iterBlob<p.maxAdaptBlob; iterBlob++) {
      elSet toOptimizePrim = getSurroundingBlob(worstEl, nbLayers,
                                                vertex2elements, element2elements,
                                                distanceFactor, 1, p.optPrimSurfMesh);
      vertSet toFix = getAllBndVertices(toOptimizePrim, vertex2elements);
      elSet toOptimize;
      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),
                          badElts.begin(),badElts.end(),
                          std::inserter(toOptimize, toOptimize.end()));
      Msg::Info("Optimizing blob %i (max. %i remaining) "
                "composed of %4d elements", iBadEl, badElts.size(),
                toOptimize.size());
      fflush(stdout);
      OptHOM *opt = new OptHOM(element2entity, toOptimize, toFix, p.fixBndNodes);
      //std::ostringstream ossI1;
      //ossI1 << "initial_blob-" << iBadEl << ".msh";
      //opt->mesh.writeMSH(ossI1.str().c_str());
      success = opt->optimize(p.weight, p.optCADWeight, p.BARRIER_MIN, p.BARRIER_MAX,
                              false, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,
                              p.discrTolerance);
      if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
        Msg::Info("Jacobian optimization succeed, starting svd optimization");
        success = opt->optimize(p.weight, p.optCADWeight, p.BARRIER_MIN_METRIC, p.BARRIER_MAX,
                                true, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,
                                p.discrTolerance);
      }

      // Measure min and max Jac., update mesh
      if ((success > 0) || (iterBlob == p.maxAdaptBlob-1)) {
        double minJac, maxJac, distMaxBND, distAvgBND;
        opt->recalcJacDist();
        opt->getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
        p.minJac = std::min(p.minJac,minJac);
        p.maxJac = std::max(p.maxJac,maxJac);
        opt->mesh.updateGEntityPositions();
      }

      //std::ostringstream ossI2;
      //ossI2 << "final_ITER_" << iter << ".msh";
      //temp.mesh.writeMSH(ossI2.str().c_str());
      if (success <= 0) {
        distanceFactor *= p.adaptBlobDistFact;
        nbLayers *= p.adaptBlobLayerFact;
        Msg::Info("Blob %i failed (adapt #%i), adapting with increased size",
                  iBadEl, iterBlob);
//        if (iterBlob == p.maxAdaptBlob-1) {
          std::ostringstream ossI2;
          ossI2 << "final_blob-" << iBadEl << ".msh";
          opt->mesh.writeMSH(ossI2.str().c_str());
//        }
      }
      else break;
    }

    //#pragma omp critical
    p.SUCCESS = std::min(p.SUCCESS, success);

  }
}

#endif

#include "OptHomIntegralBoundaryDist.h"

//double ComputeDistanceToGeometry (GModel* gm)
//{
//  return distanceToGeometry(gm);
//}


double ComputeDistanceToGeometry (GEntity *ge , int distanceDefinition, double tolerance)
{
  double maxd = 0.0;
  double sum = 0.0;
  int NUM = 0;
  for (int iEl = 0; iEl < ge->getNumMeshElements();iEl++) {
    MElement *el = ge->getMeshElement(iEl);
    if (ge->dim() == el->getDim()){
      const double DISTE =computeBndDist(el,distanceDefinition, tolerance);
      if (DISTE != 0.0){
        NUM++;
        //        if(distanceDefinition == 1)printf("%d %12.5E\n",iEl,DISTE);
        maxd = std::max(maxd,DISTE);
        sum += DISTE;
      }
    }
  }
  if (distanceDefinition == 2) return sum;
  if (distanceDefinition == 6) return sum;
  return maxd;
}

void HighOrderMeshOptimizer(GModel *gm, OptHomParameters &p)
{
#if defined(HAVE_BFGS)
  double t1 = Cpu();

  int samples = 30;

  double tf1 = Cpu();

  Msg::StatusBar(true, "Optimizing high order mesh...");
  std::vector<GEntity*> entities;
  gm->getEntities(entities);

  std::map<MVertex*, std::vector<MElement *> > vertex2elements;
  std::map<MElement*,GEntity*> element2entity;
  double maxdist = 0.;                                                  // TODO: To be cleaned?

  std::map<MElement*,double> distances;
  distanceFromElementsToGeometry(gm, p.dim,distances);

  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != p.dim || (p.onlyVisible && !entity->getVisibility())) continue;
    Msg::Info("Computing connectivity and bad elements for entity %d...",
              entity->tag());
    calcVertex2Elements(p.dim,entity,vertex2elements);

    if (p.optPrimSurfMesh) calcElement2Entity(entity,element2entity);
    // Otherwise, still compute element2entity: Hack for using the geometry
    // normal in the computation of the Jacobian when optimizing surface meshes.
    // Warning: Accurate for planar surface but not really for curved surface...
    else calcElement2Entity(entity,element2entity);
  }

  OptHomPeriodicity periodicity = OptHomPeriodicity(entities);
  do {
    // Detect bad elements
    elSet badasses;
    for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
      GEntity* &entity = entities[iEnt];
      if (entity->dim() != p.dim || (p.onlyVisible && !entity->getVisibility())) continue;
      for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) {
        MElement *el = entity->getMeshElement(iEl);
        if (p.optCAD) {
          const double DISTE =distances[el];
          maxdist = std::max(DISTE, maxdist);
          if (DISTE > p.optCADDistMax) badasses.insert(el);
        }
        double jmin, jmax;
        el->scaledJacRange(jmin, jmax, p.optPrimSurfMesh ? entity : 0);
        if (p.BARRIER_MIN_METRIC > 0) jmax = jmin;
        if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX) badasses.insert(el);
      }
    }
    printf("maxdist = %g badasses size = %lu\n", maxdist, badasses.size());
    if (p.strategy == 0)
      optimizeConnectedBlobs(vertex2elements, element2entity, badasses, p, samples, false);
    else if (p.strategy == 2)
      optimizeConnectedBlobs(vertex2elements, element2entity, badasses, p, samples, true);
    else
      optimizeOneByOne(vertex2elements, element2entity, badasses, p, samples);
    if (p.numBlobs) periodicity.fixPeriodicity();
  } while (p.SUCCESS == 1 && p.numBlobs);

  if (p.SUCCESS == 1)
    Msg::Info("Optimization succeeded");
  else if (p.SUCCESS == 0)
    Msg::Warning("All jacobians positive but not all in the range");
  else if (p.SUCCESS == -1)
    Msg::Error("Still negative jacobians");

  double t2 = Cpu();
  p.CPU = t2-t1;

  Msg::StatusBar(true, "Done optimizing high order mesh (%g s)", p.CPU);
#else
  Msg::Error("High-order mesh optimizer requires BFGS");
#endif
}


//#include "GModel.h"
#include "GEntity.h"
//#include "MElement.h"
//#include "OptHomRun.h"
#include "CADDistances.h"
#include "MeshOptCommon.h"
#include "MeshOptObjContribFunc.h"
#include "MeshOptObjContrib.h"
#include "MeshOptObjContribScaledNodeDispSq.h"
#include "OptHomObjContribScaledJac.h"
#include "OptHomObjContribMetricMin.h"
#include "OptHomObjContribCADDist.h"
#include "MeshOptimizer.h"


struct HOPatchDefParameters : public MeshOptPatchDef
{
  HOPatchDefParameters(const OptHomParameters &p);
  virtual ~HOPatchDefParameters() {}
  virtual double elBadness(MElement *el, GEntity* gEnt) const;
  virtual double bndElBadness(MElement *el, GEntity* gEnt) const;
  virtual double maxDistance(MElement *el) const;
  virtual int inPatch(const SPoint3 &badBary,
                      double limDist, MElement *el,
                      GEntity* gEnt) const;
private:
  double jacMin, jacMax;
  double distanceFactor;
  bool optCAD;
  double optCADDistMax, optCADWeight;
};


HOPatchDefParameters::HOPatchDefParameters(const OptHomParameters &p)
{
  jacMin = p.BARRIER_MIN;
  jacMax = (p.BARRIER_MAX > 0.) ? p.BARRIER_MAX : 1.e300;
  strategy = (p.strategy == 1) ? MeshOptPatchDef::STRAT_ONEBYONE :
                                 MeshOptPatchDef::STRAT_DISJOINT;
  minLayers = (p.dim == 3) ? 1 : 0;
  maxLayers = p.nbLayers;
  distanceFactor = p.distanceFactor;
  if (strategy == MeshOptPatchDef::STRAT_DISJOINT)
    weakMerge = (p.strategy == 2);
  else {
    maxPatchAdapt = p.maxAdaptBlob;
    maxLayersAdaptFact = p.adaptBlobLayerFact;
    distanceAdaptFact = p.adaptBlobDistFact;
  }
  optCAD = p.optCAD;
  optCADDistMax = p.optCADDistMax;
  optCADWeight = p.optCADWeight;
}


double HOPatchDefParameters::elBadness(MElement *el, GEntity* gEnt) const
{
  double jmin, jmax;
  el->scaledJacRange(jmin, jmax);
  double badness = std::min(jmin-jacMin, 0.) + std::min(jacMax-jmax, 0.);
  return badness;
}


double HOPatchDefParameters::bndElBadness(MElement *el, GEntity* gEnt) const
{
  if (optCAD) {
    if (el->getType() == TYPE_LIN) {                                              // 2D
      if (gEnt->geomType() != GEntity::Line)                                      // Straight geometric line -> no distance
        return optCADDistMax -
               taylorDistanceEdge(static_cast<MLine*>(el), gEnt->cast2Edge());
    }
    else {                                                                        // 3D
      if (gEnt->geomType() != GEntity::Plane)                                     // Straight geometric plance -> no distance
        return optCADDistMax -
               taylorDistanceFace(el, gEnt->cast2Face());
    }
  }
  return 1.;
}


double HOPatchDefParameters::maxDistance(MElement *el) const
{
  return distanceFactor * el->maxDistToStraight();
}


int HOPatchDefParameters::inPatch(const SPoint3 &badBary,
                                  double limDist, MElement *el,
                                  GEntity* gEnt) const
{
  return testElInDist(badBary, limDist, el) ? 1 : 0;
}


void HighOrderMeshOptimizerNew(std::vector<GEntity*> &entities, OptHomParameters &p)
{
  Msg::StatusBar(true, "Optimizing high order mesh...");

  MeshOptParameters par;
  par.dim = p.dim;
  par.onlyVisible = p.onlyVisible;
  par.fixBndNodes = p.fixBndNodes;
  par.useGeomForPatches = false;
  par.useGeomForOpt = false;
  par.useBoundaries = p.optCAD;
  HOPatchDefParameters patchDef(p);
  par.patchDef = &patchDef;
  par.displayInterv = 30;
  par.verbose = 4;
  par.logFileName = "";
  par.nCurses = false;

  ObjContribScaledNodeDispSq<ObjContribFuncSimple> nodeDistFunc(p.weight,
                                                                Patch::LS_MAXNODEDIST);
  ObjContribScaledJac<ObjContribFuncBarrierMovMin> minJacBarFunc(1.);
  minJacBarFunc.setTarget(p.BARRIER_MIN, 1.);
  ObjContribScaledJac<ObjContribFuncBarrierFixMinMovMax> minMaxJacBarFunc(1.);
  minMaxJacBarFunc.setTarget(p.BARRIER_MAX, 1.);
//  ObjContribCADDistSq<ObjContribFuncSimpleTargetMax> CADDistFunc(p.optCADWeight, p.optCADDistMax);
//  CADDistFunc.setTarget(0.);
  ObjContribCADDistSq<ObjContribFuncBarrierMovMax> CADDistFunc(p.optCADWeight, p.optCADDistMax);
  CADDistFunc.setTarget(1., 0.);
  ObjContribScaledJac<ObjContribFuncBarrierFixMin> minJacFixBarFunc(1.);
  minJacFixBarFunc.setTarget(p.BARRIER_MIN, 1.);

  MeshOptPass minJacPass;
  minJacPass.maxParamUpdates = p.optPassMax;
  minJacPass.maxOptIter = p.itMax;
  minJacPass.contrib.push_back(&nodeDistFunc);
  minJacPass.contrib.push_back(&minJacBarFunc);
//  if (p.optCAD) minJacPass.contrib.push_back(&CADDistFunc);
  par.pass.push_back(minJacPass);

  if (p.BARRIER_MAX > 0.) {
    MeshOptPass minMaxJacPass;
    minMaxJacPass.maxParamUpdates = p.optPassMax;
    minMaxJacPass.maxOptIter = p.itMax;
    minMaxJacPass.contrib.push_back(&nodeDistFunc);
    minMaxJacPass.contrib.push_back(&minMaxJacBarFunc);
//    if (p.optCAD) minMaxJacPass.contrib.push_back(&CADDistFunc);
    par.pass.push_back(minMaxJacPass);
  }

  if (p.optCAD) {
    MeshOptPass maxCADDistPass;
    maxCADDistPass.maxParamUpdates = p.optPassMax;
    maxCADDistPass.maxOptIter = p.itMax;
    maxCADDistPass.contrib.push_back(&nodeDistFunc);
    maxCADDistPass.contrib.push_back(&minJacFixBarFunc);
    maxCADDistPass.contrib.push_back(&CADDistFunc);
    par.pass.push_back(maxCADDistPass);
  }

  meshOptimizer(entities, par);

  p.CPU = par.CPU;
  p.minJac = minMaxJacBarFunc.getMin();
  p.maxJac = minMaxJacBarFunc.getMax();

  Msg::StatusBar(true, "Done optimizing high order mesh (%g s)", p.CPU);
}


void HighOrderMeshOptimizerNew(GModel *gm, OptHomParameters &p)
{
  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  HighOrderMeshOptimizerNew(entities, p);
}
