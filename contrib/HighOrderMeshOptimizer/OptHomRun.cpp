//#include <fenv.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include "OptHomRun.h"
#include "GModel.h"
#include "Gmsh.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MLine.h"
#include "highOrderTools.h"
#include "OptHomMesh.h"
#include "OptHOM.h"
#include "OS.h"
#include <stack>

#ifdef HAVE_FLTK
#include "highOrderToolsWindow.h"
#include "FlGui.h"
#endif



void OptHomMessage (const char *s, ...) {
  char str[1024];
  va_list args;
  va_start(args, s);
  vsnprintf(str, sizeof(str), s, args);
  va_end(args);
#ifdef HAVE_FLTK
  if(FlGui::available()){
    FlGui::instance()->check();
    FlGui::instance()->highordertools->messages->add(str, 0);
    if(FlGui::instance()->highordertools->win->shown() &&
       FlGui::instance()->highordertools->messages->h() >= 10){
      FlGui::instance()->highordertools->messages->bottomline(FlGui::instance()->highordertools->messages->size());
      FlGui::instance()->highordertools->messages->show();
    }
  }
  else
    fprintf(stdout,"%s\n", str);
#else
  fprintf(stdout,"%s\n", str);
#endif
}



double distMaxStraight (MElement *el)
{
  const polynomialBasis *lagrange = (polynomialBasis*)el->getFunctionSpace();
  const polynomialBasis *lagrange1 = (polynomialBasis*)el->getFunctionSpace(1);
  int nV = lagrange->points.size1();
  int nV1 = lagrange1->points.size1();
  SPoint3 sxyz[256];
  for (int i = 0; i < nV1; ++i) {
    sxyz[i] = el->getVertex(i)->point();
  }
  for (int i = nV1; i < nV; ++i) {
    double f[256];
    lagrange1->f(lagrange->points(i, 0), lagrange->points(i, 1), lagrange->points(i, 2), f);
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



void exportMeshToDassault (GModel *gm, const std::string &fn, int dim){
  FILE *f = fopen(fn.c_str(),"w");

  int numVertices = gm->indexMeshVertices(true);
  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  fprintf(f,"%d %d\n", numVertices, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      if (dim == 2)fprintf(f,"%d %22.15E %22.15E\n", v->getIndex(), v->x(), v->y());
      else if (dim == 3)fprintf(f,"%d %22.15E %22.15E %22.5E\n", v->getIndex(), v->x(), v->y(), v->z());
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



static std::set<MVertex *> getAllBndVertices(std::set<MElement*> &elements,
            const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{
  std::set<MVertex*> bnd;
  for (std::set<MElement*>::iterator itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find((*itE)->getVertex(i))->second;
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



static std::set<MElement*> getSurroundingBlob(MElement *el, int depth,
                                              const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                                              const double distFactor, int forceDepth = 0)
{

  const SPoint3 p = el->barycenter_infty();
  const double limDist = distMaxStraight(el)*distFactor;

  std::set<MElement*> blob;
  std::list<MElement*> currentLayer, lastLayer;

  blob.insert(el);
  lastLayer.push_back(el);
  for (int d = 0; d < depth; ++d) {
    currentLayer.clear();
    for (std::list<MElement*>::iterator it = lastLayer.begin(); it != lastLayer.end(); ++it) {
      for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
        const std::vector<MElement*> &neighbours = vertex2elements.find((*it)->getVertex(i))->second;
        for (std::vector<MElement*>::const_iterator itN = neighbours.begin(); itN != neighbours.end(); ++itN)
          if ((d < forceDepth) || (p.distance((*itN)->barycenter_infty()) < limDist))
            if (blob.insert(*itN).second) currentLayer.push_back(*itN);       // Assume that if an el is too far, its neighbours are too far as well
      }
    }
    lastLayer = currentLayer;
  }

  return blob;

}



static void addBlobChaintoGroup(std::set<int> &group, const std::vector<std::set<int> > &groupConnect, std::vector<bool> &todoPB, int iB)
{

  if (todoPB[iB]) {
    todoPB[iB] = false;
    group.insert(iB);
    const std::set<int> &connect = groupConnect[iB];
    for (std::set<int>::const_iterator itBC = connect.begin(); itBC != connect.end(); ++itBC)
      addBlobChaintoGroup(group, groupConnect, todoPB, *itBC);
  }

}



static void calcVertex2Elements(int dim, GEntity *entity, std::map<MVertex*, std::vector<MElement *> > &vertex2elements)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    if (element->getDim() == dim)
      for (int j = 0; j < element->getNumPrimaryVertices(); ++j)
        vertex2elements[element->getVertex(j)].push_back(element);
  }
}



static std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > getConnectedBlobs(
                                const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
                                const std::set<MElement*> &badElements, int depth, const double distFactor)
{

  OptHomMessage("Starting blob generation from %i bad elements...",badElements.size());

  // Contruct primary blobs
  std::cout << "Constructing " << badElements.size() << " primary blobs...\n";
  std::vector<std::set<MElement*> > primBlobs;
  primBlobs.reserve(badElements.size());
  for (std::set<MElement*>::const_iterator it = badElements.begin(); it != badElements.end(); ++it)
    primBlobs.push_back(getSurroundingBlob(*it, depth, vertex2elements, distFactor));


  // Compute blob connectivity
  std::cout << "Computing blob connectivity...\n";
  std::map<MElement*, std::set<int> > tags;
  std::vector<std::set<int> > blobConnect(primBlobs.size());
  for (int iB = 0; iB < primBlobs.size(); ++iB) {
    std::set<MElement*> &blob = primBlobs[iB];
    for(std::set<MElement*>::iterator itEl = blob.begin(); itEl != blob.end(); ++itEl) {
      std::set<int> &blobInd = tags[*itEl];
      if (!blobInd.empty()) {
        for (std::set<int>::iterator itBS = blobInd.begin(); itBS != blobInd.end(); ++itBS) blobConnect[*itBS].insert(iB);
        blobConnect[iB].insert(blobInd.begin(), blobInd.end());
      }
      blobInd.insert(iB);
    }
  }

  // Identify groups of connected blobs
  std::cout << "Identifying groups of primary blobs...\n";
  std::list<std::set<int> > groups;
  std::vector<bool> todoPB(primBlobs.size(), true);
  for (int iB = 0; iB < primBlobs.size(); ++iB)
    if (todoPB[iB]) {
      std::set<int> group;
      addBlobChaintoGroup(group, blobConnect, todoPB, iB);
      groups.push_back(group);
    }

  // Merge primary blobs according to groups
  std::cout << "Merging primary blobs into " << groups.size() << " blobs...\n";
  std::list<std::set<MElement*> > blobs;
  for (std::list<std::set<int> >::iterator itG = groups.begin(); itG != groups.end(); ++itG) {
    blobs.push_back(std::set<MElement*>());
    for (std::set<int>::iterator itB = itG->begin(); itB != itG->end(); ++itB) {
      std::set<MElement*> primBlob = primBlobs[*itB];
      blobs.back().insert(primBlob.begin(), primBlob.end());
    }
  }

  // Store and compute blob boundaries
  std::cout << "Computing boundaries for " << blobs.size() << " blobs...\n";
  std::vector<std::pair<std::set<MElement *>, std::set<MVertex*> > > result;
  for (std::list<std::set<MElement*> >::iterator itB = blobs.begin(); itB != blobs.end(); ++itB)
    result.push_back(std::pair<std::set<MElement*>, std::set<MVertex*> >(*itB, getAllBndVertices(*itB, vertex2elements)));

  OptHomMessage("Generated %i blobs",blobs.size());

  return result;

}



static void optimizeConnectedBlobs(const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
                                   std::set<MElement*> &badasses,
                                   OptHomParameters &p, int samples)
{

  p.SUCCESS = 1;
  p.minJac = 1.e100;
  p.maxJac = -1.e100;

  std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > toOptimize =
      getConnectedBlobs(vertex2elements, badasses, p.nbLayers, p.distanceFactor);

  //#pragma omp parallel for schedule(dynamic, 1)
  for (int i = 0; i < toOptimize.size(); ++i) {
    OptHomMessage("Optimizing a blob %i/%i composed of %4d elements", i+1, toOptimize.size(), toOptimize[i].first.size());
    fflush(stdout);
    OptHOM temp(toOptimize[i].first, toOptimize[i].second, p.fixBndNodes);
//std::ostringstream ossI1;
//ossI1 << "initial_ITER_" << i << ".msh";
//temp.mesh.writeMSH(ossI1.str().c_str());
    int success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX,
                                false, samples, p.itMax, p.optPassMax);
    if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
      OptHomMessage("Jacobian optimization succeed, starting svd optimization");
      success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN_METRIC, p.BARRIER_MAX,
                              true, samples, p.itMax, p.optPassMax);
    }
    double minJac, maxJac, distMaxBND, distAvgBND;
    temp.recalcJacDist();
    temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
    p.minJac = std::min(p.minJac,minJac);
    p.maxJac = std::max(p.maxJac,maxJac);
    temp.mesh.updateGEntityPositions();
    if (success <= 0) {
      std::ostringstream ossI2;
      ossI2 << "final_ITER_" << i << ".msh";
      temp.mesh.writeMSH(ossI2.str().c_str());
    }
    //#pragma omp critical
    p.SUCCESS = std::min(p.SUCCESS, success);
  }

}



static MElement *getWorstElement(const std::set<MElement*> &badasses, OptHomParameters &p){

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



static std::set<MVertex *> getPrimBndVertices(std::set<MElement*> &elements,
            const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{
  std::set<MVertex*> bnd;
  for (std::set<MElement*>::iterator itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find((*itE)->getVertex(i))->second;
      for (size_t k = 0; k < neighbours.size(); ++k) {
        if (elements.find(neighbours[k]) == elements.end()) {
            bnd.insert((*itE)->getVertex(i));
        }
      }
    }
  }
  return bnd;
}



static std::set<MElement*> getSurroundingBlob3D(MElement *el, int depth,
                                                const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                                                const double distFactor)
{

  const double limDist = distMaxStraight(el)*distFactor;

  std::set<MElement*> blob;
  std::list<MElement*> currentLayer, lastLayer;

  std::list<SPoint3> seedPts;

  blob.insert(el);
  lastLayer.push_back(el);
  for (int d = 0; d < depth; ++d) {
    currentLayer.clear();
    for (std::list<MElement*>::iterator it = lastLayer.begin(); it != lastLayer.end(); ++it) {
      for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
        const std::vector<MElement*> &neighbours = vertex2elements.find((*it)->getVertex(i))->second;
        for (std::vector<MElement*>::const_iterator itN = neighbours.begin(); itN != neighbours.end(); ++itN) {
          SPoint3 pt = (*itN)->barycenter_infty();                            // Check distance from all seed points
          bool nearSeed = false;
          for (std::list<SPoint3>::const_iterator itS = seedPts.begin(); itS != seedPts.end(); ++itS)
            if (itS->distance(pt) < limDist) {
              nearSeed = true;
              break;
            }
          if ((d == 0) || nearSeed)
            if (blob.insert(*itN).second) currentLayer.push_back(*itN);       // Assume that if an el is too far, its neighbours are too far as well
        }
      }
    }
    if (d == 0)                                                               // Elts of 1st layer are seed points
      for (std::list<MElement*>::iterator itL = currentLayer.begin(); itL != currentLayer.end(); ++itL)
        seedPts.push_back((*itL)->barycenter_infty());
    lastLayer = currentLayer;
  }

  return blob;

}



static std::set<MElement*> addBlobLayer(std::set<MElement*> &blob,
                                        const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{

  std::set<MElement*> layer;
  const std::set<MElement*> initBlob = blob;

  for (std::set<MElement*>::const_iterator it = initBlob.begin(); it != initBlob.end(); ++it)
    for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find((*it)->getVertex(i))->second;
      for (std::vector<MElement*>::const_iterator itN = neighbours.begin(); itN != neighbours.end(); ++itN)
          if (blob.insert(*itN).second) layer.insert(*itN);
    }

  return layer;

}



static bool detectNewBrokenElement(const std::set<MElement*> &layer,
                                   const std::set<MElement*> &badasses, OptHomParameters &p){

  for (std::set<MElement*>::iterator it=layer.begin(); it!=layer.end(); it++)
    if (badasses.find(*it) == badasses.end()) {
      double jmin, jmax, val;
      (*it)->scaledJacRange(jmin,jmax);
      if ((jmin < p.BARRIER_MIN) || (jmax > p.BARRIER_MAX)) return true;
    }

  return false;

}



static void optimizeOneByOne(const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
                             std::set<MElement*> badElts, OptHomParameters &p, int samples)
{

  p.SUCCESS = 1;
  p.minJac = 1.e100;
  p.maxJac = -1.e100;

  const int initNumBadElts = badElts.size();
  std::cout << "DBGTT: " << initNumBadElts << " badasses, starting to iterate...\n";

  for (int iBadEl=0; iBadEl<initNumBadElts; iBadEl++) {

    if (badElts.empty()) break;

    // Create blob around worst element and remove it from badElts
    MElement *worstEl = getWorstElement(badElts,p);
    badElts.erase(worstEl);

    int nbLayers = p.nbLayers;
    double distanceFactor = p.distanceFactor;

    int success;

    for (int iterBlob=0; iterBlob<p.maxAdaptBlob; iterBlob++) {

      OptHOM *opt;

      // First step: small blob with unsafe optimization (only 1st-order bnd. vertices fixed)
      std::set<MElement*> toOptimizePrim = getSurroundingBlob(worstEl, nbLayers, vertex2elements, distanceFactor, 0);
      std::set<MVertex*> toFix1 = getPrimBndVertices(toOptimizePrim, vertex2elements);
      std::set<MElement*> toOptimize1;
      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),badElts.begin(),badElts.end(),    // Do not optimize badElts
                          std::inserter(toOptimize1, toOptimize1.end()));
      OptHomMessage("Optimizing primary blob %i (max. %i remaining) composed of %4d elements", iBadEl,
                    badElts.size(), toOptimize1.size());
      fflush(stdout);
      opt = new OptHOM(toOptimize1, toFix1, p.fixBndNodes);
//std::ostringstream ossI1;
//ossI1 << "initial_primary_" << iter << ".msh";
//opt->mesh.writeMSH(ossI1.str().c_str());
      success = opt->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX,
                              false, samples, p.itMax, p.optPassMax);

      // Second step: add external layer, check it and optimize it safely (all bnd. vertices fixed) if new broken element
      if (success > 0) {
        opt->mesh.updateGEntityPositions();
        std::set<MElement*> layer = addBlobLayer(toOptimizePrim, vertex2elements);
        if (detectNewBrokenElement(layer, badElts, p)) {
          delete opt;
          std::set<MVertex*> toFix2 = getAllBndVertices(toOptimizePrim, vertex2elements);
          std::set<MElement*> toOptimize2;
          std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),badElts.begin(),badElts.end(),
                              std::inserter(toOptimize2, toOptimize2.end()));
          OptHomMessage("Optimizing corrective blob %i (max. %i remaining) composed of %4d elements", iBadEl,
                        badElts.size(), toOptimize2.size());
          fflush(stdout);
          opt = new OptHOM(toOptimize2, toFix2, p.fixBndNodes);
//std::ostringstream ossI1;
//ossI1 << "initial_corrective_" << iter << ".msh";
//opt->mesh.writeMSH(ossI1.str().c_str());
          success = opt->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX,
                                  false, samples, p.itMax, p.optPassMax);
        }
        else {
          OptHomMessage("Primary blob %i did not break new elements, no correction needed", iBadEl);
          fflush(stdout);
        }
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
        OptHomMessage("Blob %i failed (adapt #%i), adapting with increased size", iBadEl, iterBlob);
        if (iterBlob == p.maxAdaptBlob-1) {
          std::ostringstream ossI2;
          ossI2 << "final_" << iBadEl << ".msh";
          opt->mesh.writeMSH(ossI2.str().c_str());
        }
      }
      else break;

    }

    //#pragma omp critical
    p.SUCCESS = std::min(p.SUCCESS, success);

  }

}



//static void optimizeOneByOneTest(const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
//                                 std::set<MElement*> badasses, OptHomParameters &p, int method, int samples)
//{
//
//  p.SUCCESS = 1;
//  p.minJac = 1.e100;
//  p.maxJac = -1.e100;
//
//  const int initNumBadAsses = badasses.size();
//  std::cout << "DBGTT: " << initNumBadAsses << " badasses, starting to iterate...\n";
//
//  for (int iter=0; iter<initNumBadAsses; iter++) {
//
//    if (badasses.empty()) break;
//
//    // Create blob around worst element
//    MElement *worstEl = getWorstElement(badasses,p);
//
//    const int maxRepeatBlob = 1;
//    const int repeatBlobLayerFact = 2;
//    const int repeatBlobDistFact = 2.;
//
//    int nbLayers = p.nbLayers, minNbLayers = 1;
//    double distanceFactor = p.distanceFactor;
//
//    int success;
//
//    for (int iterBlob=0; iterBlob<maxRepeatBlob; iterBlob++) {
//
//      // TODO: First opt. with only 1st-order bnd. vertices fixed,
//      //       then add external layer and opt. with all bnd. vert. fixed
////      std::set<MElement*> toOptimizePrim = getSurroundingBlob(worstEl, nbLayers, vertex2elements, distanceFactor, 0);
////      std::set<MVertex*> toFix = getBndVertices3D(toOptimizePrim, vertex2elements);
//      std::set<MElement*> toOptimizePrim = getSurroundingBlob3D(worstEl, nbLayers, vertex2elements, distanceFactor);
//      std::set<MVertex*> toFix = getAllBndVertices(toOptimizePrim, vertex2elements);
//      badasses.erase(worstEl);
//      std::set<MElement*> toOptimize;
//      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),badasses.begin(),badasses.end(),
//                          std::inserter(toOptimize, toOptimize.end()));
//
//      // Optimize blob
//      OptHomMessage("Optimizing blob %i (max. %i remaining) composed of %4d elements", iter,
//                    badasses.size(), toOptimize.size());
//      fflush(stdout);
//      OptHOM temp(toOptimize, toFix, method);
////std::cout << "DBGTT: toOptimize:\n";
////for (std::set<MElement*>::iterator it=toOptimize.begin(); it!=toOptimize.end(); it++ ) {
////  SPoint3 bar = (*it)->barycenter();
////  std::cout << "DBGTT:   -> (" << bar.x() << "," << bar.y() << "," << bar.z() << ")\n";
////  std::cout << "DBGTT:   -> (" << (*it)->getVertex(0)->onWhat()->dim();
////  for (int j=1; j<(*it)->getNumVertices(); j++) std::cout << "," << (*it)->getVertex(j)->onWhat()->dim();
////  std::cout << ")\n";
////}
////std::cout << "DBGTT: toFix:\n";
////for (std::set<MVertex*>::iterator it=toFix.begin(); it!=toFix.end(); it++ )
////  std::cout << "DBGTT:   -> (" << (*it)->x() << "," << (*it)->y() << "," << (*it)->z() << ")\n";
//std::ostringstream ossI1;
//ossI1 << "initial_ITER_" << iter << ".msh";
//temp.mesh.writeMSH(ossI1.str().c_str());
//      success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX,
//                                  false, samples, p.itMax, p.optPassMax);
//      if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
//        OptHomMessage("Jacobian optimization succeed, starting svd optimization");
//        success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN_METRIC, p.BARRIER_MAX,
//                                true, samples, p.itMax, p.optPassMax);
//      }
//
//      // Measure min and max Jac, update mesh
//      double minJac, maxJac, distMaxBND, distAvgBND;
//      temp.recalcJacDist();
//      temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
//      p.minJac = std::min(p.minJac,minJac);
//      p.maxJac = std::max(p.maxJac,maxJac);
//      temp.mesh.updateGEntityPositions();
//
////std::ostringstream ossI2;
////ossI2 << "final_ITER_" << iter << ".msh";
////temp.mesh.writeMSH(ossI2.str().c_str());
//      if (success <= 0) {
//        distanceFactor *= repeatBlobDistFact;
//        nbLayers *= repeatBlobLayerFact;
//        OptHomMessage("Blob %i failed (repeat %i), repeating with increased size", iter, iterBlob);
//        if (iterBlob == maxRepeatBlob-1) {
//          std::ostringstream ossI2;
//          ossI2 << "final_ITER_" << iter << ".msh";
//          temp.mesh.writeMSH(ossI2.str().c_str());
//        }
//      }
//      else break;
//
//    }
//
//    //#pragma omp critical
//    p.SUCCESS = std::min(p.SUCCESS, success);
//
//  }
//
//}
//
//
//
//static void optimizePropagate(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
//                              std::set<MElement*> badasses, OptHomParameters &p, int method, int samples)
//{
//
//  p.SUCCESS = 1;
//  p.minJac = 1.e100;
//  p.maxJac = -1.e100;
//
//  const int initNumBadAsses = badasses.size();
//  std::cout << "DBGTT: " << initNumBadAsses << " badasses, starting to iterate...\n";
//
//  std::set<MVertex*> toFix;
//  std::set<MElement*> done;
//
//  while (!badasses.empty()) {
//
//    OptHomMessage("Optimizing first of %i bad elements, %i already done", badasses.size(), done.size());
//    fflush(stdout);
////char dum;
////std::cin >> dum;
//
//    MElement *el = *badasses.begin();
//
//    // Optimize element
//    std::set<MElement*> blob;
//    blob.insert(el);
//    OptHOM temp(blob, toFix, method);
////std::ostringstream ossI1;
////ossI1 << "initial.msh";
////temp.mesh.writeMSH(ossI1.str().c_str());
//    int success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX,
//                                false, samples, p.itMax, p.optPassMax);
//    if (success <= 0) {
//      OptHomMessage("Error, element optimization failed");
//      fflush(stdout);
//      std::ostringstream ossI1;
//      ossI1 << "failed_" << el->getNum() << ".msh";
//      temp.mesh.writeMSH(ossI1.str().c_str());
//    }
////std::ostringstream ossI2;
////ossI2 << "final.msh";
////temp.mesh.writeMSH(ossI2.str().c_str());
//
//    // Move element from list of bad elements to liste of elements done
//    badasses.erase(el);
//    done.insert(el);
//std::cout << "DBGTT: Removing el. " << el->getNum() << "\n";
//
//    // Measure success, min and max Jac and update mesh
//    double minJac, maxJac, distMaxBND, distAvgBND;
//    temp.recalcJacDist();
//    temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
//    p.minJac = std::min(p.minJac,minJac);
//    p.maxJac = std::max(p.maxJac,maxJac);
//    p.SUCCESS = std::min(p.SUCCESS, success);
//    temp.mesh.updateGEntityPositions();
//
//    // Fix elements nodes
//    for (int i = 0; i < el->getNumVertices(); ++i) toFix.insert(el->getVertex(i));
//
//    // Add elements that have been broken by optimization to list of bad elements
//    std::set<MElement*> layer;
//    for (int i = 0; i < el->getNumPrimaryVertices(); ++i) {
//      const std::vector<MElement*> &neighbours = vertex2elements.find(el->getVertex(i))->second;
//      for (size_t k = 0; k < neighbours.size(); ++k) layer.insert(neighbours[k]);
//    }
//    for (std::set<MElement*>::const_iterator it = layer.begin(); it != layer.end(); ++it)
//      if (done.find(*it) == done.end()) {           // Add only if not done
//        double jmin, jmax;
//        (*it)->scaledJacRange(jmin, jmax);
//        if (p.BARRIER_MIN_METRIC > 0) jmax = jmin;
//        if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX) {
//std::cout << "DBGTT: Adding el. " << (*it)->getNum() << "\n";
//          badasses.insert(*it);
//        }
//      }
//
//  }
//
//}



void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p)
{

  double t1 = Cpu();

  int samples = 30;

  double tf1 = Cpu();

  OptHomMessage("High order mesh optimizer starts");
  std::vector<GEntity*> entities;
  gm->getEntities(entities);

  std::map<MVertex*, std::vector<MElement *> > vertex2elements;
  std::set<MElement*> badasses;
  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != p.dim || (p.onlyVisible && !entity->getVisibility())) continue;
    std::cout << "Computing connectivity and bad elements for entity " << entity->tag() << " ...\n";
    calcVertex2Elements(p.dim,entity,vertex2elements);                       // Compute vert. -> elt. connectivity
//std::cout << " -> " << entity->getNumMeshElements()
//            << " elements, vertex2elements.size() = " << vertex2elements.size() << "\n";
    for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) {                  // Detect bad elements
      double jmin, jmax;
      MElement *el = entity->getMeshElement(iEl);
      if (el->getDim() == p.dim) {
        el->scaledJacRange(jmin, jmax);
        if (p.BARRIER_MIN_METRIC > 0) jmax = jmin;
        if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX) badasses.insert(el);
      }
    }
  }

  if (p.strategy == 0) optimizeConnectedBlobs(vertex2elements, badasses, p, samples);
  else optimizeOneByOne(vertex2elements, badasses, p, samples);

  double DTF = Cpu()-tf1;
  if (p.SUCCESS == 1)
    OptHomMessage("Optimization succeeded (CPU %g sec)", DTF);
  else if (p.SUCCESS == 0)
    OptHomMessage("Warning : All jacobians positive but not all in the range (CPU %g sec)", DTF);
  else if (p.SUCCESS == -1)
    OptHomMessage("Error : Still negative jacobians (CPU %g sec)", DTF);

  double t2 = Cpu();
  p.CPU = t2-t1;

}
