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
#include <iterator>
#include <string.h>
#include "GmshConfig.h"
#include "OptHOM.h"
#include "OptHomRun.h"
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

#if defined(HAVE_BFGS)

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

static std::set<MVertex *> getAllBndVertices
  (std::set<MElement*> &elements,
   const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{
  std::set<MVertex*> bnd;
  for (std::set<MElement*>::iterator itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find
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

// Approximate test of intersection element with circle/sphere by sampling
static bool testElInDist(const SPoint3 p, double limDist, MElement *el)
{
  const double sampleLen = 0.5*limDist;                                   // Distance between sample points

  if (el->getDim() == 2) {                                                // 2D?
    for (int iEd = 0; iEd < el->getNumEdges(); iEd++) {                   // Loop over edges of element
      MEdge ed = el->getEdge(iEd);
      const int nPts = int(ed.length()/sampleLen)+2;                      // Nb of sample points based on edge length
      for (int iPt = 0; iPt < nPts; iPt++) {                              // Loop over sample points
        const SPoint3 pt = ed.interpolate(iPt/float(nPts-1));
        if (p.distance(pt) < limDist) return true;
      }
    }
  }
  else {                                                                  // 3D
    for (int iFace = 0; iFace < el->getNumFaces(); iFace++) {             // Loop over faces of element
      MFace face = el->getFace(iFace);
      double lMax = 0.;                                                   // Max. edge length in face
      const int nVert = face.getNumVertices();
      for (int iEd = 0; iEd < nVert; iEd++)
        lMax = std::max(lMax, face.getEdge(iEd).length());
      const int nPts = int(lMax/sampleLen)+2;                             // Nb of sample points based on max. edge length in face
      for (int iPt0 = 0; iPt0 < nPts; iPt0++) {
        const double u = iPt0/float(nPts-1);
        for (int iPt1 = 0; iPt1 < nPts; iPt1++) {                         // Loop over sample points
          const double vMax = (nVert == 3) ? 1.-u : 1.;
          const SPoint3 pt = face.interpolate(u, vMax*iPt1/float(nPts-1));
          if (p.distance(pt) < limDist) return true;
        }
      }
    }
  }

  return false;
}

static std::set<MElement*> getSurroundingBlob
   (MElement *el, int depth,
    const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
    const double distFactor, int forceDepth, bool optPrimSurfMesh)
{

  const SPoint3 p = el->barycenter(true);
  const double dist = el->maxDistToStraight();
  const double limDist = ((optPrimSurfMesh && (dist < 1.e-10)) ?
                          el->getOuterRadius() : dist) * distFactor;

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
          if ((d < forceDepth) || testElInDist(p, limDist, *itN)){
            // Assume that if an el is too far, its neighbours are too far as well
            if (blob.insert(*itN).second) currentLayer.push_back(*itN);
          }
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

static void calcVertex2Elements(int dim, GEntity *entity,
                                std::map<MVertex*, std::vector<MElement *> > &vertex2elements)
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
    element2entity.insert(std::pair<MElement*,GEntity*>(element,entity));
  }
}

static std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > getConnectedBlobs
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::set<MElement*> &badElements, int depth, const double distFactor,
   bool weakMerge, bool optPrimSurfMesh)
{

  Msg::Info("Starting blob generation from %i bad elements...", badElements.size());

  // Contruct primary blobs
  Msg::Info("Constructing %i primary blobs", badElements.size());
  std::vector<std::set<MElement*> > primBlobs;
  primBlobs.reserve(badElements.size());
  for (std::set<MElement*>::const_iterator it = badElements.begin(); it != badElements.end(); ++it) {
    //const int minLayers = ((*it)->getDim() == 3) ? 1 : 0;
    const int minLayers = 3;
    primBlobs.push_back(getSurroundingBlob(*it, depth, vertex2elements,
                                distFactor, minLayers, optPrimSurfMesh));
  }

  // Compute blob connectivity
  Msg::Info("Computing blob connectivity...");
  std::map<MElement*, std::set<int> > tags;
  std::vector<std::set<int> > blobConnect(primBlobs.size());
  for (int iB = 0; iB < primBlobs.size(); ++iB) {
    std::set<MElement*> &blob = primBlobs[iB];
    for(std::set<MElement*>::iterator itEl = blob.begin(); itEl != blob.end(); ++itEl) {
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
  std::list<std::set<MElement*> > blobs;
  for (std::list<std::set<int> >::iterator itG = groups.begin();
       itG != groups.end(); ++itG) {
    blobs.push_back(std::set<MElement*>());
    for (std::set<int>::iterator itB = itG->begin(); itB != itG->end(); ++itB) {
      std::set<MElement*> primBlob = primBlobs[*itB];
      blobs.back().insert(primBlob.begin(), primBlob.end());
    }
  }

  // Store and compute blob boundaries
  Msg::Info("Computing boundaries for %i blobs...", blobs.size());
  std::vector<std::pair<std::set<MElement *>, std::set<MVertex*> > > result;
  for (std::list<std::set<MElement*> >::iterator itB = blobs.begin();
       itB != blobs.end(); ++itB)
    result.push_back(std::pair<std::set<MElement*>, std::set<MVertex*> >
                     (*itB, getAllBndVertices(*itB, vertex2elements)));

  Msg::Info("Generated %i blobs", blobs.size());

  return result;
}

static void optimizeConnectedBlobs
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::map<MElement*,GEntity*> &element2entity,
   std::set<MElement*> &badasses,
   OptHomParameters &p, int samples, bool weakMerge = false)
{
  p.SUCCESS = 1;
  p.minJac = 1.e100;
  p.maxJac = -1.e100;

  std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > toOptimize =
                          getConnectedBlobs(vertex2elements, badasses, p.nbLayers,
                                    p.distanceFactor, weakMerge, p.optPrimSurfMesh);

  //#pragma omp parallel for schedule(dynamic, 1)
  for (int i = 0; i < toOptimize.size(); ++i) {
//    if (toOptimize[i].first.size() > 10000) continue;
    Msg::Info("Optimizing a blob %i/%i composed of %4d elements", i+1,
              toOptimize.size(), toOptimize[i].first.size());
    fflush(stdout);
    OptHOM temp(element2entity, toOptimize[i].first, toOptimize[i].second, p.fixBndNodes);
    std::ostringstream ossI1;
    ossI1 << "initial_blob-" << i << ".msh";
    temp.mesh.writeMSH(ossI1.str().c_str());
    int success = -1;
    if (temp.mesh.nPC() == 0)
      Msg::Info("Blob %i has no degree of freedom, skipping", i+1);
    else
      success = temp.optimize(p.weightFixed, p.weightFree, p.optCADWeight, p.BARRIER_MIN,
                              p.BARRIER_MAX, false, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax, p.discrTolerance);
    if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
      Msg::Info("Jacobian optimization succeed, starting svd optimization");
      success = temp.optimize(p.weightFixed, p.weightFree, p.optCADWeight, p.BARRIER_MIN_METRIC, p.BARRIER_MAX,
                              true, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,p.discrTolerance);
    }
    double minJac, maxJac, distMaxBND, distAvgBND;
    temp.recalcJacDist();
    temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
    p.minJac = std::min(p.minJac,minJac);
    p.maxJac = std::max(p.maxJac,maxJac);
    temp.mesh.updateGEntityPositions();
    //if (success <= 0) {
      std::ostringstream ossI2;
      ossI2 << "final_ITER_" << i << ".msh";
      temp.mesh.writeMSH(ossI2.str().c_str());
    //}
    //#pragma omp critical
    p.SUCCESS = std::min(p.SUCCESS, success);
  }

}

static MElement *getWorstElement(std::set<MElement*> &badasses, OptHomParameters &p)
{
  double worst = 1.e300;
  MElement *worstEl = 0;

  for (std::set<MElement*>::iterator it=badasses.begin(); it!=badasses.end(); it++) {
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

static std::set<MVertex *> getPrimBndVertices
  (std::set<MElement*> &elements,
   const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{
  std::set<MVertex*> bnd;
  for (std::set<MElement*>::iterator itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find
        ((*itE)->getVertex(i))->second;
      for (size_t k = 0; k < neighbours.size(); ++k) {
        if (elements.find(neighbours[k]) == elements.end()) {
            bnd.insert((*itE)->getVertex(i));
        }
      }
    }
  }
  return bnd;
}

static std::set<MElement*> getSurroundingBlob3D
  (MElement *el, int depth,
   const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
   const double distFactor)
{
  const double limDist = el->maxDistToStraight() * distFactor;

  std::set<MElement*> blob;
  std::list<MElement*> currentLayer, lastLayer;

  std::list<SPoint3> seedPts;

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
             itN != neighbours.end(); ++itN) {
          // Check distance from all seed points
          SPoint3 pt = (*itN)->barycenter();
          bool nearSeed = false;
          for (std::list<SPoint3>::const_iterator itS = seedPts.begin();
               itS != seedPts.end(); ++itS)
            if (itS->distance(pt) < limDist) {
              nearSeed = true;
              break;
            }
          if ((d == 0) || nearSeed){
            // Assume that if an el is too far, its neighbours are too far as well
            if (blob.insert(*itN).second) currentLayer.push_back(*itN);
          }
        }
      }
    }
    if (d == 0) // Elts of 1st layer are seed points
      for (std::list<MElement*>::iterator itL = currentLayer.begin();
           itL != currentLayer.end(); ++itL)
        seedPts.push_back((*itL)->barycenter_infty());
    lastLayer = currentLayer;
  }

  return blob;

}

static std::set<MElement*> addBlobLayer
  (std::set<MElement*> &blob,
   const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{
  std::set<MElement*> layer;
  const std::set<MElement*> initBlob = blob;

  for (std::set<MElement*>::const_iterator it = initBlob.begin();
       it != initBlob.end(); ++it)
    for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find
        ((*it)->getVertex(i))->second;
      for (std::vector<MElement*>::const_iterator itN = neighbours.begin();
           itN != neighbours.end(); ++itN)
        if (blob.insert(*itN).second) layer.insert(*itN);
    }
  return layer;
}

static bool detectNewBrokenElement(std::set<MElement*> &layer,
                                   std::set<MElement*> &badasses,
                                   OptHomParameters &p)
{
  for (std::set<MElement*>::iterator it=layer.begin(); it!=layer.end(); it++)
    if (badasses.find(*it) == badasses.end()) {
      double jmin, jmax, val;
      (*it)->scaledJacRange(jmin,jmax);
      if ((jmin < p.BARRIER_MIN) || (jmax > p.BARRIER_MAX)) return true;
    }
  return false;
}

static void optimizeOneByOne
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::map<MElement*,GEntity*> &element2entity,
   std::set<MElement*> badElts, OptHomParameters &p, int samples)
{
  p.SUCCESS = 1;
  p.minJac = 1.e100;
  p.maxJac = -1.e100;

  const int initNumBadElts = badElts.size();
  Msg::Info("%d badasses, starting to iterate...", initNumBadElts);

  for (int iBadEl=0; iBadEl<initNumBadElts; iBadEl++) {

    if (badElts.empty()) break;

    // Create blob around worst element and remove it from badElts
    MElement *worstEl = getWorstElement(badElts,p);
    badElts.erase(worstEl);

    int nbLayers = p.nbLayers;
    double distanceFactor = p.distanceFactor;

    int success;

    for (int iterBlob=0; iterBlob<p.maxAdaptBlob; iterBlob++) {

//      OptHOM *opt;
//
//      // First step: small blob with unsafe optimization (only 1st-order
//      // bnd. vertices fixed)
//      std::set<MElement*> toOptimizePrim = getSurroundingBlob
//        (worstEl, nbLayers, vertex2elements, distanceFactor, 0, p.optPrimSurfMesh);
//      std::set<MVertex*> toFix1 = getPrimBndVertices(toOptimizePrim, vertex2elements);
//      std::set<MElement*> toOptimize1;
//      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),
//                          badElts.begin(),badElts.end(), // Do not optimize badElts
//                          std::inserter(toOptimize1, toOptimize1.end()));
//      Msg::Info("Optimizing primary blob %i (max. %i remaining) composed of"
//                " %4d elements", iBadEl, badElts.size(), toOptimize1.size());
//      fflush(stdout);
//      opt = new OptHOM(element2entity, toOptimize1, toFix1, p.fixBndNodes);
//      //std::ostringstream ossI1;
//      //ossI1 << "initial_primary_" << iter << ".msh";
//      //opt->mesh.writeMSH(ossI1.str().c_str());
//      success = opt->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX,
//                              false, samples, p.itMax, p.optPassMax);
//
//      // Second step: add external layer, check it and optimize it safely (all
//      // bnd. vertices fixed) if new broken element
//      if (success > 0) {
//        opt->mesh.updateGEntityPositions();
//        std::set<MElement*> layer = addBlobLayer(toOptimizePrim, vertex2elements);
//        if (detectNewBrokenElement(layer, badElts, p)) {
//          delete opt;
//          std::set<MVertex*> toFix2 = getAllBndVertices(toOptimizePrim, vertex2elements);
//          std::set<MElement*> toOptimize2;
//          std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),
//                              badElts.begin(),badElts.end(),
//                              std::inserter(toOptimize2, toOptimize2.end()));
//          Msg::Info("Optimizing corrective blob %i (max. %i remaining) "
//                    "composed of %4d elements", iBadEl, badElts.size(),
//                    toOptimize2.size());
//          fflush(stdout);
//          opt = new OptHOM(element2entity, toOptimize2, toFix2, p.fixBndNodes);
//          //std::ostringstream ossI1;
//          //ossI1 << "initial_corrective_" << iter << ".msh";
//          //opt->mesh.writeMSH(ossI1.str().c_str());
//          success = opt->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN,
//                                  p.BARRIER_MAX, false, samples, p.itMax, p.optPassMax);
//          if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
//            Msg::Info("Jacobian optimization succeed, starting svd optimization");
//            success = opt->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN_METRIC,
//                                    p.BARRIER_MAX, true, samples, p.itMax, p.optPassMax);
//          }
//        }
//        else {
//          Msg::Info("Primary blob %i did not break new elements, "
//                    "no correction needed", iBadEl);
//          fflush(stdout);
//        }
//      }

      std::set<MElement*> toOptimizePrim = getSurroundingBlob
        (worstEl, nbLayers, vertex2elements, distanceFactor, 1, p.optPrimSurfMesh);
//    std::set<MElement*> layer = addBlobLayer(toOptimizePrim, vertex2elements);
      std::set<MVertex*> toFix = getAllBndVertices(toOptimizePrim, vertex2elements);
      std::set<MElement*> toOptimize;
      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),
                          badElts.begin(),badElts.end(),
                          std::inserter(toOptimize, toOptimize.end()));
      Msg::Info("Optimizing blob %i (max. %i remaining) "
                "composed of %4d elements", iBadEl, badElts.size(),
                toOptimize.size());
      fflush(stdout);
      OptHOM *opt = new OptHOM(element2entity, toOptimize, toFix, p.fixBndNodes);
      std::ostringstream ossI1;
      ossI1 << "initial_blob-" << iBadEl << ".msh";
      opt->mesh.writeMSH(ossI1.str().c_str());
      success = opt->optimize(p.weightFixed, p.weightFree, p.optCADWeight, p.BARRIER_MIN,
                              p.BARRIER_MAX, false, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,p.discrTolerance);
      if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
        Msg::Info("Jacobian optimization succeed, starting svd optimization");
        success = opt->optimize(p.weightFixed, p.weightFree, p.optCADWeight, p.BARRIER_MIN_METRIC,
                                p.BARRIER_MAX, true, samples, p.itMax, p.optPassMax, p.optCAD, p.optCADDistMax,p.discrTolerance);
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
	//	if(distanceDefinition == 1)printf("%d %12.5E\n",iEl,DISTE);
	maxd = std::max(maxd,DISTE);
	sum += DISTE;
      }
    }
  }
  if (distanceDefinition == 2 && NUM) return sum / (double)NUM;
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
  std::set<MElement*> badasses;
  double maxdist = 0.;                                                  // TODO: To be cleaned?
  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != p.dim || (p.onlyVisible && !entity->getVisibility())) continue;
    Msg::Info("Computing connectivity and bad elements for entity %d...",
              entity->tag());
    calcVertex2Elements(p.dim,entity,vertex2elements);
    if (p.optPrimSurfMesh) calcElement2Entity(entity,element2entity);
    for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) {       // Detect bad elements
      double jmin, jmax;
      MElement *el = entity->getMeshElement(iEl);
      if (el->getDim() == p.dim) {
        if (p.optCAD) {
          const double DISTE =computeBndDist(el,2,fabs(p.discrTolerance));
          maxdist = std::max(DISTE, maxdist);
          if (DISTE > p.optCADDistMax) badasses.insert(el);
        }
        el->scaledJacRange(jmin, jmax, p.optPrimSurfMesh ? entity : 0);
        if (p.BARRIER_MIN_METRIC > 0) jmax = jmin;
        if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX) badasses.insert(el);
      }
    }
  }
  printf("maxdist = %g badasses size = %lu\n", maxdist, badasses.size());

  if (p.strategy == 0)
    optimizeConnectedBlobs(vertex2elements, element2entity, badasses, p, samples, false);
  else if (p.strategy == 2)
    optimizeConnectedBlobs(vertex2elements, element2entity, badasses, p, samples, true);
  else
    optimizeOneByOne(vertex2elements, element2entity, badasses, p, samples);

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
#include "MeshOptCommon.h"
#include "MeshOptObjContribFunc.h"
#include "MeshOptObjContrib.h"
#include "MeshOptObjContribScaledNodeDispSq.h"
#include "OptHomObjContribScaledJac.h"
#include "OptHomObjContribMetricMin.h"
#include "MeshOptimizer.h"


struct HOPatchDefParameters : public MeshOptParameters::PatchDefParameters
{
  HOPatchDefParameters(const OptHomParameters &p);
  virtual ~HOPatchDefParameters() {}
  virtual double elBadness(const MElement *el);
  virtual double maxDistance(const MElement *el);
private:
  double jacMin, jacMax;
  double distanceFactor;
};


HOPatchDefParameters::HOPatchDefParameters(const OptHomParameters &p)
{
  jacMin = p.BARRIER_MIN;
  jacMax = (p.BARRIER_MAX > 0.) ? p.BARRIER_MAX : 1.e300;
  strategy = (p.strategy == 1) ? MeshOptParameters::STRAT_ONEBYONE :
                                        MeshOptParameters::STRAT_CONNECTED;
  minLayers = (p.dim == 3) ? 1 : 0;
  maxLayers = p.nbLayers;
  distanceFactor = p.distanceFactor;
  if (strategy == MeshOptParameters::STRAT_CONNECTED)
    weakMerge = (p.strategy == 2);
  else {
    maxAdaptPatch = p.maxAdaptBlob;
    maxLayersAdaptFact = p.adaptBlobLayerFact;
    distanceAdaptFact = p.adaptBlobDistFact;
  }
}


double HOPatchDefParameters::elBadness(const MElement *el) {
  double jmin, jmax;
  el->scaledJacRange(jmin, jmax);
  return std::min(jmin-jacMin, 0.) + std::min(jacMax-jmax, 0.);
}


double HOPatchDefParameters::maxDistance(const MElement *el) {
  return distanceFactor * el->maxDistToStraight();
}


void HighOrderMeshOptimizerNew(GModel *gm, OptHomParameters &p)
{
  Msg::StatusBar(true, "Optimizing high order mesh...");

  MeshOptParameters par;
  par.dim = p.dim;
  par.onlyVisible = p.onlyVisible;
  par.fixBndNodes = p.fixBndNodes;
  HOPatchDefParameters patchDef(p);
  par.patchDef = &patchDef;
  par.optDisplay = 30;
  par.verbose = 4;

  ObjContribScaledNodeDispSq<ObjContribFuncSimple> nodeDistFunc(p.weightFixed, p.weightFree);
  ObjContribScaledJac<ObjContribFuncBarrierMin> minJacBarFunc(1.);
  minJacBarFunc.setTarget(p.BARRIER_MIN, 1.);
  ObjContribScaledJac<ObjContribFuncBarrierMinMax> minMaxJacBarFunc(1.);
  minMaxJacBarFunc.setTarget(p.BARRIER_MAX, 1.);
  par.allContrib.resize(3);
  par.allContrib[0] = &nodeDistFunc;
  par.allContrib[1] = &minJacBarFunc;
  par.allContrib[2] = &minMaxJacBarFunc;

  MeshOptParameters::PassParameters minJacPass;
  minJacPass.barrierIterMax = p.optPassMax;
  minJacPass.optIterMax = p.itMax;
  minJacPass.contribInd.resize(2);
  minJacPass.contribInd[0] = 0;
  minJacPass.contribInd[1] = 1;
  par.pass.push_back(minJacPass);

  if (p.BARRIER_MAX > 0.) {
    MeshOptParameters::PassParameters minMaxJacPass;
    minMaxJacPass.barrierIterMax = p.optPassMax;
    minMaxJacPass.optIterMax = p.itMax;
    minMaxJacPass.contribInd.resize(2);
    minMaxJacPass.contribInd[0] = 0;
    minMaxJacPass.contribInd[1] = 2;
    par.pass.push_back(minMaxJacPass);
  }

  MeshOptResults res;

  meshOptimizer(gm, par, res);

  p.CPU = res.CPU;
  p.minJac = res.minScaledJac;
  p.maxJac = res.maxScaledJac;

  Msg::StatusBar(true, "Done optimizing high order mesh (%g s)", p.CPU);
}
