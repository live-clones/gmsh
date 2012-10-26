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



static std::set<MVertex *> getBndVertices(std::set<MElement*> &elements, std::map<MVertex *, std::vector<MElement*> > &vertex2elements)
{
  std::set<MVertex*> bnd;
  for (std::set<MElement*>::iterator itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements[(*itE)->getVertex(i)];
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



static std::set<MElement*> getSurroundingBlob(MElement *el, int depth, std::map<MVertex *, std::vector<MElement*> > &vertex2elements, const double distFactor)
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
        const std::vector<MElement*> &neighbours = vertex2elements[(*it)->getVertex(i)];
        for (std::vector<MElement*>::const_iterator itN = neighbours.begin(); itN != neighbours.end(); ++itN)
          if (p.distance((*itN)->barycenter_infty()) < limDist)
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



static std::vector<std::pair<std::set<MElement*> , std::set<MVertex*> > > getConnectedBlobs(GEntity &entity, const std::set<MElement*> &badElements, int depth, const double distFactor)
{

  OptHomMessage("Starting blob generation from %i bad elements...",badElements.size());

  // Compute vertex -> element connectivity
  std::cout << "Computing vertex -> element connectivity...\n";
  std::map<MVertex*, std::vector<MElement *> > vertex2elements;
  for (size_t i = 0; i < entity.getNumMeshElements(); ++i) {
    MElement &element = *entity.getMeshElement(i);
    for (int j = 0; j < element.getNumPrimaryVertices(); ++j) {
      vertex2elements[element.getVertex(j)].push_back(&element);
    }
  }

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
    result.push_back(std::pair<std::set<MElement*>, std::set<MVertex*> >(*itB, getBndVertices(*itB, vertex2elements)));

  OptHomMessage("Generated %i blobs",blobs.size());

  return result;

}



void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p)
{

  double t1 = Cpu();

  int samples = 30;

  int method = 0;
  if (p.method == 0)
    method = Mesh::METHOD_FIXBND | Mesh::METHOD_PROJJAC;
  else if (p.method == 1)
    method = Mesh::METHOD_PROJJAC;
  else if (p.method == 2)
    method = Mesh::METHOD_FIXBND | Mesh::METHOD_PHYSCOORD | Mesh::METHOD_PROJJAC;
  else if(p.method < 0)
    method = -p.method;

  SVector3 BND(gm->bounds().max(), gm->bounds().min());

  OptHomMessage("High order mesh optimizer starts");
  std::vector<GEntity*> entities;
  gm->getEntities(entities);

  for (int i = 0; i < entities.size(); ++i) {

    double tf1 = Cpu();
    GEntity &entity = *entities[i];

    if (entity.dim() != p.dim || (p.onlyVisible && !entity.getVisibility())) continue;

    OptHomMessage("Optimizing Model entity %4d...", entity.tag());
    std::set<MElement*> badasses;
    for (int i = 0; i < entity.getNumMeshElements();i++) {
      double jmin, jmax;
      entity.getMeshElement(i)->scaledJacRange(jmin, jmax);
      if (p.BARRIER_MIN_METRIC > 0) jmax = jmin;
      if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX)
        badasses.insert(entity.getMeshElement(i));
    }
    if (badasses.empty()) continue;

    std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > toOptimize = getConnectedBlobs(entity, badasses, p.nbLayers, p.DistanceFactor);

    //#pragma omp parallel for schedule(dynamic, 1)
    p.SUCCESS = 1;
    p.minJac = 1.e100;
    p.maxJac = -1.e100;
    for (int i = 0; i < toOptimize.size(); ++i) {
      OptHomMessage("Optimizing a blob %i/%i composed of %4d elements", i+1, toOptimize.size(), toOptimize[i].first.size());
      fflush(stdout);
      OptHOM temp(&entity, toOptimize[i].first, toOptimize[i].second, method);
      int success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, false, samples, p.itMax, p.optPassMax);
      if (success >= 0 && p.BARRIER_MIN_METRIC > 0) {
        OptHomMessage("Jacobian optimization succeed, starting svd optimization");
        success = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN_METRIC, p.BARRIER_MAX, true, samples, p.itMax, p.optPassMax);
      }
      double minJac, maxJac, distMaxBND, distAvgBND;
      temp.recalcJacDist();
      temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
      p.minJac = std::min(p.minJac,minJac);
      p.maxJac = std::max(p.maxJac,maxJac);
      temp.mesh.updateGEntityPositions();
      if (success <= 0) {
        std::ostringstream ossI2;
        ossI2 << "final_" << entity.tag() << "ITER_" << i << ".msh";
        temp.mesh.writeMSH(ossI2.str().c_str());
      }
      //#pragma omp critical
      p.SUCCESS = std::min(p.SUCCESS, success);
    }

    double DTF = Cpu()-tf1;
    if (p.SUCCESS == 1)
      OptHomMessage("Optimization succeeded for entity %d (CPU %g sec)", entity.tag(), DTF);
    else if (p.SUCCESS == 0)
      OptHomMessage("Warning : Model entity %4d has all jacobians positive but not all in the range (CPU %g sec)", entity.tag(), DTF);
    else if (p.SUCCESS == -1)
      OptHomMessage("Error : Model entity %4d has still negative jacobians (CPU %g sec)", entity.tag(), DTF);

  }

  double t2 = Cpu();
  p.CPU = t2-t1;

}
