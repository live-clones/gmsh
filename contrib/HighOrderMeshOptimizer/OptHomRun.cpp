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
    fprintf(stdout,"%s\n",str);
#else
  fprintf(stdout,"%s\n",str);
#endif
}


// get all elements that are neighbors

double distMaxStraight (MElement *el){
  const polynomialBasis *lagrange = el->getFunctionSpace();
  const polynomialBasis *lagrange1 = el->getFunctionSpace(1);
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
    if (dx > maxdx)maxdx=dx;
  }
  return maxdx;
}

void exportMeshToDassault (GModel *gm, const std::string &fn, int dim){
  FILE *f = fopen(fn.c_str(),"w");

  int numVertices = gm->indexMeshVertices(true);
  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  fprintf(f,"%d %d\n",numVertices,dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      if (dim == 2)fprintf(f,"%d %22.15E %22.15E\n",v->getIndex(),v->x(),v->y());
      else if (dim == 3)fprintf(f,"%d %22.15E %22.15E %22.5E\n",v->getIndex(),v->x(),v->y(),v->z());
    }

  if (dim == 2){
    int nt = 0;
    int order  = 0;
    for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf){
      std::vector<MTriangle*> &tris = (*itf)->triangles;
      nt += tris.size();
      if (tris.size())order = tris[0]->getPolynomialOrder();
    }
    fprintf(f,"%d %d\n",nt,(order+1)*(order+2)/2);
    int count = 1;
    for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf){
      std::vector<MTriangle*> &tris = (*itf)->triangles;
      for (size_t i=0;i<tris.size();i++){
	MTriangle *t = tris[i];
	fprintf(f,"%d ",count++);
	for (int j=0;j<t->getNumVertices();j++){
	  fprintf(f,"%d ",t->getVertex(j)->getIndex());
	}
	fprintf(f,"\n");
      }
    }
    int ne = 0;
    for (GModel::eiter ite = gm->firstEdge(); ite != gm->lastEdge(); ++ite){
      std::vector<MLine*> &l = (*ite)->lines;
      ne += l.size();
    }
    fprintf(f,"%d %d\n",ne,(order+1));
    count = 1;
    for (GModel::eiter ite = gm->firstEdge(); ite != gm->lastEdge(); ++ite){
      std::vector<MLine*> &l = (*ite)->lines;
      for (size_t i=0;i<l.size();i++){
	MLine *t = l[i];
	fprintf(f,"%d ",count++);
	for (int j=0;j<t->getNumVertices();j++){
	  fprintf(f,"%d ",t->getVertex(j)->getIndex());
	}
	fprintf(f,"%d \n",(*ite)->tag());
      }
    }
  }
  fclose(f);
}



static void getTopologicalNeighbors(int nbLayers,
				    const std::vector<MElement*> &all,
				    const std::vector<MElement*> &elements,
				    std::set<MElement*> &result){


  std::set<MVertex*> touched;

  for (int i = 0; i < elements.size(); i++)
    for (int j=0;j<elements[i]->getNumVertices();j++)
      touched.insert(elements[i]->getVertex(j));

  for (int layer = 0; layer < nbLayers; layer++) {
    for (int i = 0; i < all.size(); i++) {
      MElement *t = all[i];
      bool add_ = false;
      for (int j = 0; j < t->getNumVertices(); j++) {
        if (touched.find(t->getVertex(j)) != touched.end()) {
          add_ = true;
        }
      }
      if (add_) result.insert(t);
    }
    for (std::set<MElement*>::iterator it = result.begin(); it != result.end(); ++it) {
      for (int j = 0; j < (*it)->getNumVertices(); j++) {
        touched.insert((*it)->getVertex(j));
      }
    }
  }
  //  printf("%d %d %d %d\n",all.size(),elements.size(), result.size(),nbLayers);
  //  exit(1);
}

static void getGeometricalNeighbors (MElement *e, const std::vector<MElement*> &all, double F, std::set<MElement*> &result) {

  double R = distMaxStraight (e);

  SPoint3 p = e->barycenter_infty();
  for (int i = 0; i < all.size(); i++) {
    MElement *e = all[i];
    double dist = p.distance(e->barycenter_infty());
    if (dist < R*F)result.insert(e);
  }
}

static void intersection (const std::set<MElement*> &a, const std::set<MElement*> &b, std::set<MElement*> &result){
  for (std::set<MElement*>::const_iterator it = a.begin() ; it != a.end() ; ++it ){
    if (b.find(*it) != b.end()){
      result.insert(*it);
    }
  }
}

static void computeVertices (const std::set<MElement*> &a, std::set<MVertex*> &result){
  for (std::set<MElement*>::const_iterator it = a.begin() ; it != a.end() ; ++it ){
    for (int i=0;i<(*it)->getNumVertices();++i){
      result.insert((*it)->getVertex(i));
    }
  }
}

static MElement * compare_worst (MElement *a, MElement *b){
  if (!a)return b;
  if (!b)return a;
  if (a->distoShapeMeasure() < b->distoShapeMeasure()) return a;
  return b;
}

template <class ITERATOR>
MElement* getTheWorstElementDown (const ITERATOR &beg, const ITERATOR &end, double &q) {
  MElement *worst = 0;
  q = 1.e22;
  ITERATOR it = beg;
  for (;it != end;++it){
    MElement *t = *it;
    double jmin,jmax;
    t->scaledJacRange(jmin,jmax);
    if (jmin < q) {
      worst = t;q = jmin;
    }
  }
  return worst;
}

template <class ITERATOR>
MElement* getTheWorstElementUp (const ITERATOR &beg, const ITERATOR &end, double &q) {
  MElement *worst = 0;
  q = -1.e22;
  ITERATOR it = beg;
  for (;it != end;++it){
    MElement *t = *it;
    double jmin,jmax;
    t->scaledJacRange(jmin,jmax);
    if (jmax > q) {
      worst = t;q = jmax;
    }
  }
  return worst;
}

static std::set<MVertex*> filterSimple(GEntity *ge,
					  int nbLayers,
					  double _qual_min,
					  double _qual_max,
            std::set<MElement*> &result) {
  std::vector<MElement*> badElements, allElements;
  for (int i = 0; i < ge->getNumMeshElements(); ++i) {
    MElement *e = ge->getMeshElement(i);
    double Q = e->distoShapeMeasure();
    allElements.push_back(e);
    if (Q < _qual_min || Q > _qual_max) {
      badElements.push_back(e);
    }
  }
  getTopologicalNeighbors(nbLayers, allElements, badElements,result);
  std::set<MVertex*> vs;
  for (int i = 0; i < allElements.size(); i++) {
    if (result.find(allElements[i]) == result.end()) {
      for (int j = 0; j < allElements[i]->getNumVertices(); j++) {
        vs.insert(allElements[i]->getVertex(j));
      }
    }
  }
  return vs;
}

std::set<MVertex*> filter2D_boundaryLayer(GFace *gf,
					  int nbLayers,
					  double _qual_min,
					  double _qual_max,
					  double F ,
					  std::set<MElement*> & badasses,
            std::set<MElement*> & result
            ) {
  double jmin, jmax;
  MElement *worstDown = getTheWorstElementDown(badasses.begin(),badasses.end(),jmin);
  MElement *worstUp   = getTheWorstElementUp(badasses.begin(),badasses.end(),jmax);
  MElement *worst;
  if (jmin < _qual_min)worst = worstDown;
  else worst = worstUp;

  //  MElement *worst = compare_worst (getTheWorstElement(gf->triangles),
  //				   getTheWorstElement(gf->quadrangles));

  std::vector<MElement*> vworst; vworst.push_back(worst);
  std::vector<MElement*> all;
  all.insert(all.begin(),gf->triangles.begin(),gf->triangles.end());
  all.insert(all.begin(),gf->quadrangles.begin(),gf->quadrangles.end());
  std::set<MElement*> result1;
  getTopologicalNeighbors(nbLayers, all, vworst,result1);
  std::set<MElement*> result2;
  getGeometricalNeighbors (worst, all, F, result2);
  intersection (result1,result2,result);
  //  printf("intsersection(%d,%d) = %d\n",result1.size(),result2.size(),result.size());

  std::set<MVertex*> vs;
  for (int i = 0; i < all.size(); i++) {
    if (result.find(all[i]) == result.end()) {
      for (int j = 0; j < all[i]->getNumVertices(); j++) {
	vs.insert(all[i]->getVertex(j));
      }
    }
  }
  return vs;
}


std::set<MVertex*> filter3D_boundaryLayer(GRegion *gr,
					  int nbLayers,
					  double _qual_min,
					  double _qual_max,
					  double F,
            std::set<MElement *> &result) {
  double jmin,jmax;
  MElement *worst = compare_worst (getTheWorstElementDown(gr->tetrahedra.begin(),gr->tetrahedra.end(),jmin),
				   getTheWorstElementDown(gr->prisms.begin(),gr->prisms.end(),jmin));
  worst = compare_worst (worst,getTheWorstElementDown(gr->hexahedra.begin(),gr->hexahedra.end(),jmin));

  std::vector<MElement*> vworst; vworst.push_back(worst);
  std::vector<MElement*> all;
  all.insert(all.begin(),gr->tetrahedra.begin(),gr->tetrahedra.end());
  all.insert(all.begin(),gr->prisms.begin(),gr->prisms.end());
  all.insert(all.begin(),gr->hexahedra.begin(),gr->hexahedra.end());
  std::set<MElement*> result1;
  getTopologicalNeighbors(nbLayers, all, vworst,result1);
  std::set<MElement*> result2;
  getGeometricalNeighbors (worst, all, F, result2);
  intersection (result1,result2,result);
  //  printf("intsersection(%d,%d) = %d\n",result1.size(),result2.size(),result.size());

  std::set<MVertex*> vs;
  for (int i = 0; i < all.size(); i++) {
    if (result.find(all[i]) == result.end()) {
      for (int j = 0; j < all[i]->getNumVertices(); j++) {
	vs.insert(all[i]->getVertex(j));
      }
    }
  }
  return vs;
}

static std::vector<std::set<MElement*> > splitConnex(const std::set<MElement*> &in)
{
  std::map<int, std::vector<int> > vertex2elements;
  std::vector<MElement *> elements(in.begin(), in.end());
  for (size_t i = 0; i < elements.size(); ++i) {
    for (int j = 0; j < elements[i]->getNumPrimaryVertices(); ++j) {
      vertex2elements[elements[i]->getVertex(j)->getNum()].push_back(i);
    }
  }
  std::vector<int> colors(elements.size(), -1);
  int color = 0;
  for (size_t i = 0; i < elements.size(); ++i) {
    if (colors[i] == -1) {
      colors[i] = color;
      std::stack<int> todo;
      todo.push(i);
      while (! todo.empty()) {
        int top = todo.top();
        todo.pop();
        for (int j = 0; j < elements[top]->getNumPrimaryVertices(); ++j) {
          const std::vector<int> &neighbours = vertex2elements[elements[top]->getVertex(j)->getNum()];
          for (size_t k = 0; k < neighbours.size(); ++k) {
            if (colors[neighbours[k]] == -1) {
              colors[neighbours[k]] = color;
              todo.push(neighbours[k]);
            }
          }
        }
      }
      color ++;
    }
  }
  std::vector<std::set<MElement*> > split(color);
  for (size_t i = 0; i < elements.size(); ++i) {
    split[colors[i]].insert(elements[i]);
  }
  return split;
}

void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p)
{

  double t1 = Cpu();

  int samples = 30;

//  int method = Mesh::METHOD_RELAXBND | Mesh::METHOD_PHYSCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_FIXBND | Mesh::METHOD_PHYSCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_FIXBND | Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
  int method;
  if (p.method == 0)
    method = Mesh::METHOD_FIXBND | Mesh::METHOD_PROJJAC;
  else if (p.method == 1)
    method = Mesh::METHOD_PROJJAC;
  else if (p.method == 2)
    method = Mesh::METHOD_FIXBND | Mesh::METHOD_PHYSCOORD | Mesh::METHOD_PROJJAC;
  else if(p.method < 0)
    method = -p.method;

  //  printf("p.method = %d\n",p.method);

//  int method = Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_RELAXBND | Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_PROJJAC;

  SVector3 BND(gm->bounds().max(), gm->bounds().min());
  double SIZE = BND.norm();

  OptHomMessage("High order mesh optimizer starts");

  double distMaxBND, distAvgBND, minJac, maxJac;
  if (p.dim == 2) {
    double tf1 = Cpu();;
    for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
      if (p.onlyVisible && !(*itf)->getVisibility())continue;
      int ITER = 0;
      OptHomMessage("Optimizing Model face %4d...",(*itf)->tag());
      p.SUCCESS = 1;
      std::set<MElement*> badasses;
      if (p.filter == 1){
	for (int i=0;i<(*itf)->getNumMeshElements();i++){
	  double jmin,jmax;
	  (*itf)->getMeshElement(i)->scaledJacRange(jmin,jmax);
	  if (jmin < p.BARRIER_MIN || jmax > p.BARRIER_MAX)badasses.insert((*itf)->getMeshElement(i));
	}
	//	printf("START WITH %d bad asses\n",badasses.size());
	if (badasses.size() == 0)continue;
      }
      if (p.filter == 0) {
        std::set<MVertex*> toFix;
        std::set<MElement*> toOptimize;
        toFix = filterSimple(*itf, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, toOptimize);
        std::vector<std::set<MElement*> > toOptimizeSplit = splitConnex(toOptimize);
        for (int i = 0; i < toOptimizeSplit.size(); ++i) {
          OptHOM temp(*itf, toOptimizeSplit[i], toFix, method);
          temp.recalcJacDist();
          temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
          OptHomMessage("Optimizing a blob %i/%i composed of %4d elements  minJ %12.5E -- maxJ %12.5E", i+1, toOptimizeSplit.size(), toOptimizeSplit[i].size(), minJac, maxJac);
          p.SUCCESS = std::min(p.SUCCESS,temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, samples, p.itMax));
          temp.mesh.updateGEntityPositions();
        }
      }
      else while (1){
	std::set<MVertex*> toFix;
	std::set<MElement*> toOptimize;

	toFix = filter2D_boundaryLayer(*itf, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, p.DistanceFactor, badasses, toOptimize);
	OptHOM temp(*itf, toOptimize, toFix, method);

	temp.recalcJacDist();
	temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
	//	if (minJac < 1.e2)OptHomMessage("Optimizing a blob of %4d elements  minJ %12.5E -- maxJ %12.5E",(*itf)->getNumMeshElements(), minJac, maxJac);
	std::ostringstream ossI;
	ossI << "initial_" << (*itf)->tag() << "ITER_" << ITER << ".msh";
	temp.mesh.writeMSH(ossI.str().c_str());
	if (minJac > p.BARRIER_MIN && maxJac < p.BARRIER_MAX) break;

	p.SUCCESS = std::min(p.SUCCESS,temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, samples, p.itMax));

//  temp.recalcJacDist();
//  temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
	temp.mesh.updateGEntityPositions();
	if (p.SUCCESS == -1) break;
	ITER ++;
	if (p.filter == 1 && ITER > badasses.size() * 2)break;

	//      std::ostringstream ossF;
	//      ossF << "final_" << (*itf)->tag() << ".msh";
	//      temp.mesh.writeMSH(ossF.str().c_str());
      }
      double DTF = Cpu()-tf1;
      if (p.SUCCESS == 1){
	OptHomMessage("Optimization succeeded (CPU %g sec)",DTF);
      }
      else if (p.SUCCESS == 0)
	OptHomMessage("Warning : Model face %4d has all jacobians positive but not all in the range CPU %g",(*itf)->tag(),DTF);
      else if (p.SUCCESS == -1)
	OptHomMessage("Error : Model face %4d has still negative jacobians",(*itf)->tag());

      Msg::Info("---------------------------------------------------------------------------------------------------------------");
    }
    exportMeshToDassault (gm,gm->getName() + "_opti.das", 2);
  }
  else if (p.dim == 3) {
    for (GModel::riter itr = gm->firstRegion(); itr != gm->lastRegion(); ++itr) {
      if (p.onlyVisible && !(*itr)->getVisibility())continue;
      int ITER = 0;
      Msg::Info("Model region %4d is considered",(*itr)->tag());
      p.SUCCESS = true;
      if (p.filter == 0) {
        std::set<MVertex*> toFix;
        std::set<MElement*> toOptimize;
        toFix = filterSimple(*itr, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, toOptimize);
        std::vector<std::set<MElement*> > toOptimizeSplit = splitConnex(toOptimize);
        for (int i = 0; i < toOptimizeSplit.size(); ++i) {
          OptHOM temp(*itr, toOptimizeSplit[i], toFix, method);
          temp.recalcJacDist();
          temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
	  std::ostringstream ossI;
	  ossI << "initial_" << (*itr)->tag() << "BLOB_" << i << ".msh";
	  temp.mesh.writeMSH(ossI.str().c_str());
          OptHomMessage("Optimizing a blob %i/%i composed of %4d elements  minJ %12.5E -- maxJ %12.5E", i+1, toOptimizeSplit.size(), toOptimizeSplit[i].size(), minJac, maxJac);
          p.SUCCESS = std::min(p.SUCCESS,temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, samples, p.itMax));
	  temp.mesh.updateGEntityPositions();
        }
      }
      else while (1){
      std::set<MVertex*> toFix;
      std::set<MElement*> toOptimize;

      if (p.filter == 1) toFix = filter3D_boundaryLayer(*itr, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, p.DistanceFactor, toOptimize);
      else toFix = filterSimple(*itr, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, toOptimize);

//      if ((*itr)->tetrahedra.size() > 0) {
        OptHOM temp(*itr, toOptimize, toFix, method);
        double distMaxBND, distAvgBND, minJac, maxJac;
        temp.recalcJacDist();
        temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
        if (minJac < 1.e2)Msg::Info("Optimizing a blob of %4d elements  minJ %12.5E -- maxJ %12.5E",(*itr)->getNumMeshElements(), minJac, maxJac);
        std::ostringstream ossI;
        ossI << "initial_" << (*itr)->tag() << "ITER_" << ITER << ".msh";
        temp.mesh.writeMSH(ossI.str().c_str());
        if (minJac > p.BARRIER_MIN  && maxJac < p.BARRIER_MAX) break;
        p.SUCCESS = temp.optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, samples, p.itMax);
        temp.recalcJacDist();
        temp.getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
        temp.mesh.updateGEntityPositions();
        if (!p.SUCCESS) break;
//      }
      ITER ++;
      }
      Msg::Info("Model region %4d is done (%d subdomains were computed) SUCCESS %1d",(*itr)->tag(),ITER,p.SUCCESS);
      Msg::Info("----------------------------------------------------------------");
      //      temp.mesh.writeMSH("final.msh");
    }
  }
  double t2 = Cpu();
  p.CPU = t2-t1;
}
