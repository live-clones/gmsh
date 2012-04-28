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
#include <stack>

#ifdef HAVE_FLTK
#include "highOrderToolsWindow.h"
#include "FLGui.h"
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
      for (int i=0;i<tris.size();i++){
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
      for (int i=0;i<l.size();i++){
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


std::set<MVertex*> filter3D(GRegion *gr, int nbLayers, double _qual)
{
  std::set<MVertex*> touched;
  std::set<MVertex*> not_touched;
  std::set<MTetrahedron *> ts;
  for (int i=0;i<gr->tetrahedra.size();i++){
    MTetrahedron *t = gr->tetrahedra[i];
    if (t->distoShapeMeasure() < _qual){
      ts.insert(t);
      for(int j=0;j<t->getNumVertices();j++)touched.insert(t->getVertex(j));
    }
    //    if (ts.size() == 1)break;
  }  

  printf("FILTER3D : %d bad tets found among %6d\n",ts.size(),gr->tetrahedra.size());

  // add layers of elements around bad elements
  for (int layer = 0;layer<nbLayers; layer++){
    for (int i=0;i<gr->tetrahedra.size();i++){
      MTetrahedron *t = gr->tetrahedra[i];
      bool add_ = false;
      for(int j=0;j<t->getNumVertices();j++){
	if(touched.find(t->getVertex(j)) != touched.end()){
	  add_ = true;
	}
      }
      if (add_)ts.insert(t);
    }

    for (std::set<MTetrahedron*>::iterator it = ts.begin(); it != ts.end() ; ++it){
      for(int j=0;j<(*it)->getNumVertices();j++){
	touched.insert((*it)->getVertex(j));
      }
    }
  }

  for (int i=0;i<gr->tetrahedra.size();i++){
    if (ts.find(gr->tetrahedra[i]) == ts.end()){
      for(int j=0;j<gr->tetrahedra[i]->getNumVertices();j++){
	if (touched.find(gr->tetrahedra[i]->getVertex(j)) != touched.end())
	  not_touched.insert(gr->tetrahedra[i]->getVertex(j));
      }
    }
  }

  gr->tetrahedra.clear();
  gr->tetrahedra.insert(gr->tetrahedra.begin(),ts.begin(),ts.end());

  printf("FILTER3D : AFTER FILTERING %d tets remain %d nodes on the boundary\n",gr->tetrahedra.size(),not_touched.size());
  return not_touched;
}


std::set<MVertex*> filter2D_boundaryLayer(GFace *gf, 
					  int nbLayers, 
					  double _qual_min, 
					  double _qual_max, 
					  double F , 
					  std::set<MElement*> & badasses) {
  
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
  std::set<MElement*> result;
  intersection (result1,result2,result);
  //  printf("intsersection(%d,%d) = %d\n",result1.size(),result2.size(),result.size()); 
  

  gf->triangles.clear();
  gf->quadrangles.clear();
  for (std::set<MElement*>::iterator it = result.begin(); it != result.end(); ++it){
    MElement *e = *it;
    if (e->getType() == TYPE_QUA)gf->quadrangles.push_back((MQuadrangle*)e);
    else if (e->getType() == TYPE_TRI)gf->triangles.push_back((MTriangle*)e);
  }

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
					  double F ) {
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
  std::set<MElement*> result;
  intersection (result1,result2,result);
  //  printf("intsersection(%d,%d) = %d\n",result1.size(),result2.size(),result.size()); 
  

  gr->tetrahedra.clear();
  gr->hexahedra.clear();
  gr->prisms.clear();
  for (std::set<MElement*>::iterator it = result.begin(); it != result.end(); ++it){
    MElement *e = *it;
    if (e->getType() == TYPE_TET)gr->tetrahedra.push_back((MTetrahedron*)e);
    else if (e->getType() == TYPE_HEX)gr->hexahedra.push_back((MHexahedron*)e);
    else if (e->getType() == TYPE_PRI)gr->prisms.push_back((MPrism*)e);
  }

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


std::set<MVertex*> filter2D(GFace *gf, 
			    int nbLayers, 
			    double _qual_min, 
			    double _qual_max)
{
  std::set<MVertex*> touched;
  std::set<MVertex*> not_touched;
  std::set<MElement*> elements;
  std::set<MTriangle*> tt;
  std::set<MQuadrangle*> qq;

  for (int i = 0; i < gf->triangles.size(); i++) {
    MTriangle *t = gf->triangles[i];
    double jmin,jmax;
    t->scaledJacRange(jmin,jmax);
    if (jmin < _qual_min || jmax > _qual_max) {
      elements.insert(t);
      tt.insert(t);
      for (int j = 0; j < t->getNumVertices(); j++)
	touched.insert(t->getVertex(j));
    }
  }
  for (int i = 0; i < gf->quadrangles.size(); i++) {
    MQuadrangle *q = gf->quadrangles[i];
    double jmin,jmax;
    q->scaledJacRange(jmin,jmax);
    if (jmin < _qual_min || jmax > _qual_max) {
      elements.insert(q);
      qq.insert(q);
      for (int j = 0; j < q->getNumVertices(); j++)
	touched.insert(q->getVertex(j));
    }
  }
  
  // add layers of elements around bad elements
  for (int layer = 0; layer < nbLayers; layer++) {
    for (unsigned int i = 0; i < gf->getNumMeshElements(); ++i) {
      MElement *el = gf->getMeshElement(i);
      for (int j = 0; j < el->getNumVertices(); ++j) {
        if (touched.find(el->getVertex(j)) != touched.end()) {
          elements.insert(el);
	  if (el->getType() == TYPE_TRI)tt.insert((MTriangle*)el);
	  if (el->getType() == TYPE_QUA)qq.insert((MQuadrangle*)el);
          break;
        }
      }
    }
    for (std::set<MElement *>::iterator it = elements.begin(); it != elements.end(); ++it) {
      MElement *el = *it;
      for (int j = 0; j < el->getNumVertices(); ++j) {
        touched.insert(el->getVertex(j));
      }
    }
  }

  for (int i = 0; i < gf->getNumMeshElements(); i++) {
    if (elements.find(gf->getMeshElement(i)) == elements.end()) {
      for (int j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
	if (touched.find(gf->getMeshElement(i)->getVertex(j)) != touched.end()) not_touched.insert(gf->getMeshElement(i)->getVertex(j));
      }
    }
  }
  gf->triangles.clear();
  gf->triangles.insert(gf->triangles.begin(),tt.begin(),tt.end());
  gf->quadrangles.clear();
  gf->quadrangles.insert(gf->quadrangles.begin(),qq.begin(),qq.end());

  return not_touched;
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
  std::vector<std::set<MElement*> > splitted(color);
  for (size_t i = 0; i < elements.size(); ++i) {
    splitted[colors[i]].insert(elements[i]);
  }
  return splitted;
}

void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p)
{

  clock_t t1 = clock();

  int samples = 100;

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

  //  printf("p.method = %d\n",p.method);

//  int method = Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_RELAXBND | Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_PROJJAC;

  SVector3 BND(gm->bounds().max(), gm->bounds().min());
  double SIZE = BND.norm();

  OptHomMessage("High order mesh optimizer starts");

  double distMaxBND, distAvgBND, minJac, maxJac;
  if (p.dim == 2) {
    clock_t tf1 = clock();;
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
      while (1){
	std::vector<MTriangle*> tris = (*itf)->triangles;
	std::vector<MQuadrangle*> quas = (*itf)->quadrangles;
	std::set<MVertex*> toFix;

	if (p.filter == 1) toFix = filter2D_boundaryLayer(*itf, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, p.DistanceFactor, badasses);
	else toFix = filter2D(*itf, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX);
	OptHOM *temp = new OptHOM(*itf, toFix, method);
	//	temp->recalcJacDist();

	temp->getDistances(distMaxBND, distAvgBND,minJac, maxJac);
	//	if (minJac < 1.e2)OptHomMessage("Optimizing a blob of %4d elements  minJ %12.5E -- maxJ %12.5E",(*itf)->getNumMeshElements(), minJac, maxJac);
	std::ostringstream ossI;
	ossI << "initial_" << (*itf)->tag() << "ITER_" << ITER << ".msh";
	temp->mesh.writeMSH(ossI.str().c_str());
	(*itf)->triangles = tris;
	(*itf)->quadrangles = quas;
	if (minJac > p.BARRIER_MIN && maxJac < p.BARRIER_MAX) break;
	
	p.SUCCESS = std::min(p.SUCCESS,temp->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, samples, p.itMax));

	temp->getDistances(distMaxBND, distAvgBND,minJac, maxJac);
	//	temp->getJacDist(p.minJac, p.maxJac, distMaxBND, distAvgBND);
	temp->mesh.updateGEntityPositions();
	if (p.SUCCESS == -1) break;
	ITER ++;
	if (p.filter == 1 && ITER > badasses.size() * 2)break;

	//      std::ostringstream ossF;
	//      ossF << "final_" << (*itf)->tag() << ".msh";
	//      temp->mesh.writeMSH(ossF.str().c_str());
      }
      double DTF = (double)(clock()-tf1) / CLOCKS_PER_SEC;
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
      while (1){
      std::vector<MTetrahedron*> tets = (*itr)->tetrahedra;
      std::set<MVertex*> toFix;

      if (p.filter == 1) toFix = filter3D_boundaryLayer(*itr, p.nbLayers, p.BARRIER_MIN, p.BARRIER_MAX, p.DistanceFactor);
      else toFix = filter3D(*itr, p.nbLayers, p.BARRIER_MIN);

//      if ((*itr)->tetrahedra.size() > 0) {
        OptHOM *temp = new OptHOM(*itr, toFix, method);
        double distMaxBND, distAvgBND, minJac, maxJac;
	temp->getDistances(distMaxBND, distAvgBND,minJac, maxJac);
	//        temp->recalcJacDist();
	//        temp->getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
        if (minJac < 1.e2)Msg::Info("Optimizing a blob of %4d elements  minJ %12.5E -- maxJ %12.5E",(*itr)->getNumMeshElements(), minJac, maxJac);
        (*itr)->tetrahedra = tets;
        std::ostringstream ossI;
        ossI << "initial_" << (*itr)->tag() << "ITER_" << ITER << ".msh";
        temp->mesh.writeMSH(ossI.str().c_str());
        if (minJac > p.BARRIER_MIN  && maxJac < p.BARRIER_MAX) break;
        p.SUCCESS = temp->optimize(p.weightFixed, p.weightFree, p.BARRIER_MIN, p.BARRIER_MAX, samples, p.itMax);
	temp->getDistances(distMaxBND, distAvgBND,minJac, maxJac);
	//        temp->getJacDist(p.minJac, p.maxJac, distMaxBND, distAvgBND);
        temp->mesh.updateGEntityPositions();
        if (!p.SUCCESS) break;
//      }
      ITER ++;
      }
      Msg::Info("Model region %4d is done (%d subdomains were computed) SUCCESS %1d",(*itr)->tag(),ITER,p.SUCCESS);
      Msg::Info("----------------------------------------------------------------");
      //      temp->mesh.writeMSH("final.msh");
    }
  }  
  clock_t t2 = clock();
  p.CPU = (double)(t2-t1)/CLOCKS_PER_SEC;
}
