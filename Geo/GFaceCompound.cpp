// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GFaceCompound.h"
#include "MLine.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Octree.h"
#include "SBoundingBox3d.h"
#include "SPoint3.h"
#include "functionSpace.h"
#include "robustPredicates.h"
#include "MElementCut.h"
#include "GEntity.h"
#include "dofManager.h"
#include "laplaceTerm.h"
#include "distanceTerm.h"
#include "crossConfTerm.h"
#include "convexCombinationTerm.h"
#include "linearSystemGMM.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "CreateFile.h"
#include "Context.h"
#include "discreteFace.h"

// #if !defined(HAVE_NO_MESH)
// #include "meshGFace.h"
// #include "meshGFaceOptimize.h"
// #include "meshGEdge.h"
// #include "meshPartitionOptions.h"
// #include "meshPartition.h"
// #endif

static void fixEdgeToValue(GEdge *ed, double value, dofManager<double, double> &myAssembler)
{
  myAssembler.fixVertex(ed->getBeginVertex()->mesh_vertices[0], 0, 1, value);
  myAssembler.fixVertex(ed->getEndVertex()->mesh_vertices[0], 0, 1, value);
  for(unsigned int i = 0; i < ed->mesh_vertices.size(); i++){
    myAssembler.fixVertex(ed->mesh_vertices[i], 0, 1, value);
  }
}

static void computeCGKernelPolygon(std::map<MVertex*,SPoint3> &coordinates, 
                                   std::vector<MVertex*> &cavV, double &ucg, double &vcg)
{
  ucg = 0.0;
  vcg = 0.0;
  
  // place at CG KERNEL polygon

  int nbPts = cavV.size();
  fullMatrix<double> u(100,2);
  int i = 0;
  for(std::vector<MVertex*>::iterator it = cavV.begin(); it != cavV.end(); it++){
    SPoint3 vsp = coordinates[*it];
    u(i,0) = vsp[0];
    u(i,1) = vsp[1];
    i++;
  }    
  double eps = -5.e-7;
  int N = nbPts;
 
  std::set<int> setP;
  for(int k = 0; k < nbPts; k++) setP.insert(k);

  if(nbPts > 3){
    for(int i = 0; i < nbPts - 2; i++){
      int next = i + 1;
      double x1, x2, y1, y2; 
      x1 = u(i, 0); y1 = u(i, 1);
      x2 = u(next, 0); y2 = u(next, 1);
      for(int j = i + 2; j < nbPts; j++){
        int jnext = j + 1;
        if(j == nbPts - 1) jnext = 0; 
        double x3, x4, y3, y4, x,y;
        double a, b, c, d;
        x3 = u(j, 0); y3 = u(j, 1);  
        x4 = u(jnext, 0); y4 = u(jnext, 1);
        a = (y2 - y1) / (x2 - x1);
        c = (y4 - y3) / (x4 - x3);
        b = y1 - a * x1;
        d = y3 - c * x3;
        if(fabs(a - c) > 1.e-5 && x2 !=x1 && x4 != x3 && jnext != i){
          x = (d - b) / (a - c);
          y = a * x + b;
          bool exist= false;
          for(unsigned int k = 1; k < setP.size(); k++){
            if(x == u(k, 0) && y == u(k, 1)) exist = true;
          }
          if(!exist){
            u(N, 0) = x; u(N, 1) = y;
            setP.insert(N);
            N++;
          } 
        }
      }
    }

    int nbAll = setP.size();
    for(int i = 0; i <nbPts; i++){
      int next = i + 1;   
      if(next == nbPts) next = 0;
      double p1[2] = {u(next, 0) - u(i, 0), u(next, 1) - u(i, 1)};
      for(int k = 0; k < nbAll; k++){
	double p2[2] = {u(k, 0) - u(i, 0), u(k, 1) - u(i, 1)};
	double crossProd = p1[0] * p2[1] - p2[0] * p1[1];
	if(crossProd <  eps){
	  setP.erase(k);
	}
      }
    }
  }

  int nbFinal = setP.size();
  if(nbFinal > 0){
    for(std::set<int>::iterator it =setP.begin(); it != setP.end(); it++){
      ucg += u(*it,0);
      vcg += u(*it,1);
    }
    ucg/=nbFinal;
    vcg/=nbFinal;
  }
  else{
    Msg::Info("----> No Kernel for polygon:  place point at CG polygon.");
    //place at CG polygon
    for(std::vector<MVertex*>::iterator it = cavV.begin() ; it != cavV.end() ; ++it){
      SPoint3 vsp = coordinates[*it];
      ucg += vsp[0];
      vcg += vsp[1];
    }
    ucg /= nbPts;
    vcg /= nbPts;
  }

}

static void myPolygon(std::vector<MElement*> &vTri, std::vector<MVertex*> &vPoly)
{
  std::vector<MEdge> ePoly;
  for(unsigned int i = 0; i  < vTri.size() ; i++) {
    MTriangle *t = (MTriangle*) vTri[i];
    for(int iEdge = 0; iEdge < 3; iEdge++) {
      MEdge tmp_edge =  t->getEdge(iEdge);
      if(std::find(ePoly.begin(), ePoly.end(), tmp_edge) == ePoly.end())
	ePoly.push_back(tmp_edge);
      else
	ePoly.erase(std::find(ePoly.begin(), ePoly.end(),tmp_edge));
    }
  }

//   printf("epoly.size=%d  vTri=%d\n", ePoly.size(), vTri.size());
//   for(std::vector<MEdge>::iterator ite = ePoly.begin(); ite != ePoly.end(); ite++){
//      MVertex *vB = ite->getVertex(0);
//      MVertex *vE = ite->getVertex(1);
//      printf("VB=%d vE=%d \n", vB->getNum(), vE->getNum());
//   }

  std::vector<MEdge>::iterator ite= ePoly.begin() ;
  MVertex *vINIT = ite->getVertex(0);
  vPoly.push_back(vINIT);
  vPoly.push_back(ite->getVertex(1));
  ePoly.erase(ite);

   while(!ePoly.empty()){
     ite = ePoly.begin() ;
     while(ite != ePoly.end()){
       MVertex *vB = ite->getVertex(0);
       MVertex *vE = ite->getVertex(1);
       if(vB == vPoly.back()){
	 if(vE != vINIT) vPoly.push_back(vE);
	 ePoly.erase(ite);
       }
       else if(vE == vPoly.back()){
	 if(vB != vINIT) vPoly.push_back(vB);
	 ePoly.erase(ite);
       }
       else ite++;
     }
  }

//   printf("epoly.size=%d  vTri=%d, cavV.size =%d\n", ePoly.size(), vTri.size(), vPoly.size());
//   for(std::vector<MVertex*>::iterator itv = vPoly.begin(); itv != vPoly.end(); itv++){
//     printf("VV=%d \n", (*itv)->getNum());
//   }

}

bool GFaceCompound::trivial() const
{
  if(_compound.size() == 1 && 
     (*(_compound.begin()))->getNativeType() == GEntity::OpenCascadeModel &&
     (*(_compound.begin()))->geomType() != GEntity::DiscreteSurface){
    return true;
  }
  return false;
}

//check if the discrete harmonic map is correct
//by checking that all the mapped triangles have
//the same normal orientation
bool GFaceCompound::checkOrientation() const
{

  //Only check orientation for stl files (1 patch)
  if(_compound.size() > 1.0) return true;

  std::list<GFace*>::const_iterator it = _compound.begin();
  double a_old = 0, a_new;
  bool oriented = true;
  for( ; it != _compound.end(); ++it){
    int iter = 0;
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      SPoint3 v1 = coordinates[t->getVertex(0)];
      SPoint3 v2 = coordinates[t->getVertex(1)];
      SPoint3 v3 = coordinates[t->getVertex(2)];
      double p1[2] = {v1[0],v1[1]};
      double p2[2] = {v2[0],v2[1]};
      double p3[2] = {v3[0],v3[1]};
      a_new = robustPredicates::orient2d(p1, p2, p3);
      if(iter == 0) a_old=a_new;
      if(a_new*a_old < 0.){
	oriented = false;
	break;
      }
      else{
	a_old = a_new;
      }
      iter ++;
    }    
  }  

  if(!oriented ){
    Msg::Info("*** Could not compute reparametrization with the harmonic map.");
    Msg::Info("*** Force One-2-One Map.");
    one2OneMap();
    checkOrientation();
  }
  else{
    Msg::Info("Harmonic mapping successfully computed ...");
  }

  return oriented;

}

bool GFaceCompound::checkCavity(std::vector<MElement*> &vTri) const
{
  bool badCavity = false;
  
  unsigned int nbV = vTri.size();
  double a_old = 0, a_new;
  for(unsigned int i = 0; i < nbV; ++i){
    MTriangle *t = (MTriangle*) vTri[i];
    SPoint3 v1 = coordinates[t->getVertex(0)];
    SPoint3 v2 = coordinates[t->getVertex(1)];
    SPoint3 v3 = coordinates[t->getVertex(2)];  
    double p1[2] = {v1[0],v1[1]};
    double p2[2] = {v2[0],v2[1]};
    double p3[2] = {v3[0],v3[1]};
    //printf("p1=(%g %g) p2=(%g %g) p3=(%g %g)\n",v1[0],v1[1], v2[0],v2[1], v3[0],v3[1] );
    a_new = robustPredicates::orient2d(p1, p2, p3);
    if(i == 0) a_old=a_new;
    if(a_new*a_old < 0.)   badCavity = true;
    a_old = a_new;
  }
  
  return badCavity;
}

void GFaceCompound::one2OneMap() const
{
#if !defined(HAVE_NO_MESH)
  if(!mapv2Tri){
    std::vector<MTriangle*> allTri;
    std::list<GFace*>::const_iterator it = _compound.begin();
    for( ; it != _compound.end(); ++it){
      allTri.insert(allTri.end(), (*it)->triangles.begin(), (*it)->triangles.end() );
    }
    buildVertexToTriangle(allTri, adjv);
    mapv2Tri=true;
  }
  
  for(v2t_cont::iterator it = adjv.begin(); it!= adjv.end(); ++it){
    MVertex *v = it->first;
    std::map<MVertex*,SPoint3>::iterator itV = coordinates.find(v);
    
    std::vector<MVertex*> cavV;
    std::vector<MElement*> vTri = it->second;
    bool badCavity = checkCavity(vTri);
    
    if(badCavity){
      Msg::Info("Wrong cavity around vertex %d (onwhat=%d).",
                v->getNum(),  v->onWhat()->dim());
      Msg::Info("--> Place vertex at center of gravity of %d-Polygon kernel." ,
                vTri.size());
      
      double u_cg, v_cg;
      myPolygon(vTri, cavV);
      computeCGKernelPolygon(coordinates, cavV, u_cg, v_cg);
      SPoint3 p_cg(u_cg,v_cg,0);
      coordinates[v] = p_cg;
      
//      printf("Kernel CG: ucg=%g vcg=%g \n", u_cg, v_cg);
//      bool testbadCavity = checkCavity(vTri);
//      if(testbadCavity == true ) printf("**** New cavity is KO \n");
//      else  printf("-- New cavity is OK \n"); 

//      for(int i=0; i<  vTri.size(); i++){
//        MTriangle *t = (MTriangle*) vTri[i];
//        SPoint3 v1 = coordinates[t->getVertex(0)];
//        SPoint3 v2 = coordinates[t->getVertex(1)];
//        SPoint3 v3 = coordinates[t->getVertex(2)];
       
//        printf("//////////////////// \n " );
//        double p1[2] = {v1[0],v1[1]};
//        double p2[2] = {v2[0],v2[1]};
//        double p3[2] = {v3[0],v3[1]};
//        double a_new = robustPredicates::orient2d(p1, p2, p3);
//        MVertex *e1=t->getVertex(0);	MVertex *e2=t->getVertex(1);	MVertex *e3=t->getVertex(2);
//        printf("Point(%d)={%g, %g, 0}; \n ",e1->getNum(), v1[0],v1[1] );
//        printf("Point(%d)={%g, %g, 0}; \n ",e2->getNum(), v2[0],v2[1] );
//        printf("Point(%d)={%g, %g, 0}; \n ",e3->getNum(), v3[0],v3[1] );
//        printf("Line(%d)={%d,%d}; \n", e1->getNum()+e2->getNum() , e1->getNum(), e2->getNum());
//        printf("Line(%d)={%d,%d}; \n", e2->getNum()+e3->getNum() , e2->getNum(), e3->getNum());
//        printf("Line(%d)={%d,%d}; \n", e3->getNum()+e1->getNum() , e3->getNum(), e1->getNum());
//        printf("Surface(%d)={%d,%d, %d}; \n", e3->getNum()+e1->getNum() + e2->getNum(), e3->getNum(), e1->getNum()+e2->getNum() , 
// 	      e2->getNum()+e3->getNum() , e3->getNum()+e1->getNum() );
//        printf("//Area=%g \n", a_new);
//      }
      
    }
  }
#endif
}

void GFaceCompound::parametrize() const
{
  if(trivial()) return;

  if(!oct){

    coordinates.clear(); 
    
    //Laplace parametrization
    //-----------------
    if (_mapping == HARMONIC){
      parametrize(ITERU);
      parametrize(ITERV);
    }
    //Conformal map parametrization
    //----------------- 
    else if (_mapping == CONFORMAL){
      parametrize_conformal();
    }
    //Distance function
    //-----------------
    //compute_distance();

    checkOrientation();

    buildOct();
    computeNormals();
  }
}

void GFaceCompound::getBoundingEdges()
{
 
  for(std::list<GFace*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    (*it)->setCompound(this);
  }

  std::set<GEdge*> _unique;
  getUniqueEdges(_unique);
 
  l_edges.clear();

  if(_U0.size()){
    //in case the bounding edges are explicitely given
    std::list<GEdge*>::const_iterator it = _U0.begin();
    for( ; it != _U0.end() ; ++it){
      l_edges.push_back(*it);
      (*it)->addFace(this);
    }
    it = _V0.begin();
    for( ; it != _V0.end() ; ++it){
      l_edges.push_back(*it);
      (*it)->addFace(this);
    }
    std::list<GEdge*> loop;
    computeALoop(_unique, loop);
    while(!_unique.empty())  computeALoop(_unique,loop);
  }
  else{
    //in case the bounding edges are NOT explicitely given
    std::set<GEdge*>::iterator itf = _unique.begin(); 
    for( ; itf != _unique.end(); ++itf){
      l_edges.push_back(*itf);
      (*itf)->addFace(this);
    }
    computeALoop(_unique, _U0);
    while(!_unique.empty())  computeALoop(_unique,_U1);
  }

  return;

}

void GFaceCompound::getUniqueEdges(std::set<GEdge*> &_unique) 
{
  _unique.clear();
  // in case the bounding edges are not given Boundary { {} };
  std::multiset<GEdge*> _touched;
  std::list<GFace*>::iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    std::list<GEdge*> ed = (*it)->edges();
    std::list<GEdge*>::iterator ite = ed.begin();
    for( ; ite != ed.end(); ++ite){
      _touched.insert(*ite);
    }    
  }    
  it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    std::list<GEdge*> ed = (*it)->edges();
    std::list<GEdge*>::iterator ite = ed.begin();
    for( ; ite != ed.end() ; ++ite){
      if(!(*ite)->degenerate(0) && _touched.count(*ite) == 1) {	
	_unique.insert(*ite);      }
    }    
  }    

}
void GFaceCompound::computeALoop(std::set<GEdge*> &_unique, std::list<GEdge*> &loop) 
{
  std::list<GEdge*> _loop;

  if (_unique.empty()) return;

  while(!_unique.empty()) {
    std::set<GEdge*>::iterator it = _unique.begin();
    GVertex *vB = (*it)->getBeginVertex();
    GVertex *vE = (*it)->getEndVertex();
    _loop.push_back(*it);
    _unique.erase(it);
    it++;
    
    bool found = false;
    for(int i = 0; i < 2; i++) {           
      for(std::set<GEdge*>::iterator itx = _unique.begin(); 
          itx != _unique.end(); ++itx){
	GVertex *v1 = (*itx)->getBeginVertex();
	GVertex *v2 = (*itx)->getEndVertex();
	
	std::set<GEdge*>::iterator itp;
	if(v1 == vE){
	  _loop.push_back(*itx);
	  itp = itx;
	  itx++;
	  _unique.erase(itp);
	  vE = v2;
	  i = -1;
	}
	else if(v2 == vE){
	  _loop.push_back(*itx);
	  itp = itx;
	  itx++;
	  _unique.erase(itp);
	  vE = v1;
	  i=-1;
	}
	if(itx == _unique.end()) break;
      }
      
      if(vB == vE) {
	found = true;
	break;
      }
      
      if(_unique.empty())  break;
      
      GVertex *temp = vB;
      vB = vE;
      vE = temp;
    }

    if(found == true) break;
    
  } 
  
  loop = _loop;
  _interior_loops.push_back(loop);
  return;

}

GFaceCompound::GFaceCompound(GModel *m, int tag, std::list<GFace*> &compound,
			     std::list<GEdge*> &U0, std::list<GEdge*> &V0,
			     std::list<GEdge*> &U1, std::list<GEdge*> &V1,
			     linearSystem<double> *lsys, typeOfMapping mpg)
  : GFace(m, tag), _compound(compound), _U0(U0), _U1(U1), _V0(V0), _V1(V1), oct(0),
    _lsys(lsys),_mapping(mpg)
{

  if (!_lsys) {
#if defined(HAVE_TAUCS)
    _lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_PETSC)
    _lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
    linearSystemGmm<double> *_lsysb = new linearSystemGmm<double>;
    _lsysb->setGmres(1);
    _lsys = _lsysb;
#else
    _lsys = new linearSystemFull<double>;
#endif
  }
  nbSplit = 0;
  _checkedAR = false;
  _paramOK  = false;

  for(std::list<GFace*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    if(!(*it)){
      Msg::Error("Incorrect face in compound surface %d\n", tag);
      Msg::Exit(1);
    }
  }
  
  getBoundingEdges();
  if(!_U0.size()) _type = UNITCIRCLE;
  else if(!_V1.size()) _type = UNITCIRCLE;
  else _type = SQUARE;

  mapv2Tri = false;
}

GFaceCompound::~GFaceCompound()
{
  if(oct){
    Octree_Delete(oct);
    delete [] _gfct;
  }
  if (_lsys)delete _lsys;
}

static void boundVertices(const std::list<GEdge*> &e, std::vector<MVertex*> &l){

  l.clear();
  std::list<GEdge*>::const_iterator it = e.begin();
  for( ; it != e.end(); ++it ){
    for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
      MVertex *v0 = (*it)->lines[i]->getVertex(0);
      MVertex *v1 = (*it)->lines[i]->getVertex(1); 
      std::list<GEdge*>::const_iterator it = e.begin();
      if (std::find(l.begin(), l.end(), v0) == l.end())  l.push_back(v0);
      if (std::find(l.begin(), l.end(), v1) == l.end())  l.push_back(v1);
    }
  }

}
//order Vertices of a closed loop
static bool orderVertices(const std::list<GEdge*> &e, std::vector<MVertex*> &l,
                          std::vector<double> &coord)
{
  l.clear();
  coord.clear();

  //printf("%d lines\n",e.size());

  std::list<GEdge*>::const_iterator it = e.begin();
  std::list<MLine*> temp;
  double tot_length = 0;
  for( ; it != e.end(); ++it ){
    for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
      temp.push_back((*it)->lines[i]);
      MVertex *v0 = (*it)->lines[i]->getVertex(0);
      MVertex *v1 = (*it)->lines[i]->getVertex(1);    
      const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
                                 (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                 (v0->z() - v1->z()) * (v0->z() - v1->z()));
      tot_length += length;
    }
  }
    
  MVertex *first_v = (*temp.begin())->getVertex(0);
  MVertex *current_v = (*temp.begin())->getVertex(1);
  
  l.push_back(first_v);
  coord.push_back(0.0);
  temp.erase(temp.begin());

  while(temp.size()){
    bool found = false;
    for(std::list<MLine*>::iterator itl = temp.begin(); itl != temp.end(); ++itl){
      MLine *ll = *itl;
      MVertex *v0 = ll->getVertex(0);
      MVertex *v1 = ll->getVertex(1);
      if(v0 == current_v){
	found = true;
	l.push_back(current_v);
	current_v = v1;
	temp.erase(itl);
	const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
                                   (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                   (v0->z() - v1->z()) * (v0->z() - v1->z()));	
	coord.push_back(coord[coord.size()-1] + length / tot_length);
	break;
      }
      else if(v1 == current_v){
	found = true;
	l.push_back(current_v);
	current_v = v0;
	temp.erase(itl);
	const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
                                   (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                   (v0->z() - v1->z()) * (v0->z() - v1->z()));
	coord.push_back(coord[coord.size()-1] + length / tot_length);
	break;
      }
    }
    if(!found) return false;
  }    
  return true;
}

SPoint2 GFaceCompound::getCoordinates(MVertex *v) const 
{ 
  if(trivial()){
    SPoint2 param;
    reparamMeshVertexOnFace(v, (*(_compound.begin())),param);
    return param;
  }
  
  parametrize() ; 
  std::map<MVertex*,SPoint3>::iterator it = coordinates.find(v);

  if(it != coordinates.end()){
    return SPoint2(it->second.x(),it->second.y()); 
  }
  else{

    double tGlob, tLoc;
    double tL, tR;
    int iEdge;

    //getParameter Point
    v->getParameter(0,tGlob);
    //printf("*** global param for point (%g, %g, %g ) = %g\n", v->x(), v->y(), v->z(), tGlob);

    //find compound Edge
      GEdgeCompound *gec = dynamic_cast<GEdgeCompound*>(v->onWhat());
      //printf("tag compound=%d, beginvertex=%d, endvertex=%d \n", gec->tag(), gec->getBeginVertex()->tag(), gec->getEndVertex()->tag());
    
    if(gec){

      //compute local parameter on Edge
      gec->getLocalParameter(tGlob,iEdge,tLoc);
      std::vector<GEdge*> gev = gec->getEdgesOfCompound();
      GEdge *ge = gev[iEdge];
      //printf("iEdge =%d, leftV =%d, rightV=%d,  and local param=%g \n", ge->tag(), ge->getBeginVertex()->tag(), ge->getEndVertex()->tag(), tLoc);
      
      //left and right vertex of the Edge
      MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
      MVertex *v1 = ge->getEndVertex()->mesh_vertices[0];
      std::map<MVertex*,SPoint3>::iterator itL = coordinates.find(v0);
      std::map<MVertex*,SPoint3>::iterator itR = coordinates.find(v1);
  
      //for the Edge, find the left and right vertices of the initial 1D mesh and interpolate to find (u,v)
      //printf("number of vertices =%d for Edge =%d \n", ge->mesh_vertices.size(), ge->tag());
      MVertex *vL = v0;
      MVertex *vR = v1;
      double tB = ge->parBounds(0).low();
      double tE = ge->parBounds(0).high();
      //printf("tB=%g uv (%g %g) tE=%g (%g %g), tLoc=%g\n", tB, itL->second.x(), itL->second.y(), tE, itR->second.x(), itR->second.y(), tLoc);
      int j = 0;
      tL=tB;
      bool found = false;
      while(j < (int)ge->mesh_vertices.size()){
	vR = ge->mesh_vertices[j];
	vR->getParameter(0,tR);
	if(!vR->getParameter(0,tR)) {
	  Msg::Error("vertex vr %p not medgevertex \n", vR);
	  Msg::Exit(1);
	}
	//printf("***tLoc=%g tL=%g, tR=%g L=%p (%g,%g,%g) et R= %p (%g,%g,%g)\n", tLoc, tL, tR, vL, vL->x(),vL->y(),vL->z(),vR, vR->x(), vR->y(), vR->z());
	if(tLoc >= tL && tLoc <= tR){
	  found = true;
	  itR = coordinates.find(vR);
	  if(itR == coordinates.end()){
	    Msg::Error("vertex %p (%g %g %g) not found\n", vR, vR->x(), vR->y(), vR->z());
	    Msg::Exit(1);
	  }
	  break;
	}
	else{
	  itL = coordinates.find(vR);
	  vL = vR;
	  tL = tR;
	}
	j++;
	//printf("in while j =%d,  vL (%g,%g,%g), -> uv= (%g,%g)\n",j, vL->x(), vL->y(), vL->z(), itL->second.x(), itL->second.y());
      }
      if(!found) {
	vR = v1; 
	tR = tE;
      }
      //printf("vL (%g,%g,%g), -> uv= (%g,%g)\n",vL->x(), vL->y(), vL->z(), itL->second.x(), itL->second.y());
      //printf("vR (%g,%g,%g), -> uv= (%g,%g)\n",vR->x(), vR->y(), vR->z(), itR->second.x(), itR->second.y());
      //printf("tL:%g, tR=%g, tLoc=%g \n", tL, tR, tLoc);

      //Linear interpolation between tL and tR
      double uloc, vloc;
      uloc = itL->second.x() + (tLoc-tL)/(tR-tL) * (itR->second.x()-itL->second.x());
      vloc = itL->second.y() + (tLoc-tL)/(tR-tL) * (itR->second.y()-itL->second.y());
      //printf("uloc=%g, vloc=%g \n", uloc,vloc);
      //exit(1);

      return SPoint2(uloc,vloc);
    }
  }
  // never here
  return SPoint2(0, 0);
}

void GFaceCompound::parametrize(iterationStep step) const
{
  Msg::Info("Parametrizing Surface %d coordinate (ITER %d)", tag(), step); 
  
  dofManager<double, double> myAssembler(_lsys);
  simpleFunction<double> ONE(1.0);

  if(_type == UNITCIRCLE){
    // maps the boundary onto a circle
    std::vector<MVertex*> ordered;
    std::vector<double> coords;  
    bool success = orderVertices(_U0, ordered, coords);
    if(!success){
      Msg::Error("Could not order vertices on boundary");
      return;
    }

    for(unsigned int i = 0; i < ordered.size(); i++){
      MVertex *v = ordered[i];
      const double theta = 2 * M_PI * coords[i];
      if(step == ITERU) myAssembler.fixVertex(v, 0, 1, cos(theta));
      else if(step == ITERV) myAssembler.fixVertex(v, 0, 1, sin(theta));    
    }
  }
  else if(_type == SQUARE){
    if(step == ITERU){
      std::list<GEdge*>::const_iterator it = _U0.begin();
      for( ; it != _U0.end(); ++it){
	fixEdgeToValue(*it, 0.0, myAssembler);
      }
      it = _U1.begin();
      for( ; it != _U1.end(); ++it){
	fixEdgeToValue(*it, 1.0, myAssembler);
      }
    }
    else if(step == ITERV){
      std::list<GEdge*>::const_iterator it = _V0.begin();
      for( ; it != _V0.end(); ++it){
	fixEdgeToValue(*it, 0.0, myAssembler);
      }
      it = _V1.begin();
      for( ; it != _V1.end(); ++it){
	fixEdgeToValue(*it, 1.0, myAssembler);
      }
    }
  }
  else throw;

  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0), 0, 1);
      myAssembler.numberVertex(t->getVertex(1), 0, 1);
      myAssembler.numberVertex(t->getVertex(2), 0, 1); 
    }    
  }    

  Msg::Debug("Creating term %d dofs numbered %d fixed",
             myAssembler.sizeOfR(), myAssembler.sizeOfF());
  
  //convexCombinationTerm laplace(model(), 1, &ONE);
  clock_t t1 = clock();  
  laplaceTerm laplace(model(), 1, &ONE);
  it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      SElement se((*it)->triangles[i]);
      laplace.addToMatrix(myAssembler, &se);
    }
  }
  clock_t t2 = clock();
  Msg::Debug("Assembly done in %8.3f seconds",(double)(t2-t1)/CLOCKS_PER_SEC);
  _lsys->systemSolve();
  Msg::Debug("System solved");


  if(allNodes.empty()) buildAllNodes();
  
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value = myAssembler.getDofValue(v, 0, 1);
    std::map<MVertex*,SPoint3>::iterator itf = coordinates.find(v);
    if(itf == coordinates.end()){
      SPoint3 p(0, 0, 0);
      p[step] = value;
      coordinates[v] = p;
    }
    else{
      itf->second[step]= value;
    }
  }
  _lsys->clear();
}

void GFaceCompound::parametrize_conformal() const
{
  if(oct) return;

  Msg::Info("Parametrizing Surface %d", tag()); 
  
  dofManager<double, double> myAssembler(_lsys);

  std::vector<MVertex*> ordered;
  std::vector<double> coords;  
  bool success = orderVertices(_U0, ordered, coords);
  if(!success){
    Msg::Error("Could not order vertices on boundary");
    return;
  }

  MVertex *v1 = ordered[0];
  MVertex *v2 = ordered[1];
//   if (!_interior_loops.empty()){
//     std::vector<MVertex*> ordered2;
//     bool success2 = orderVertices(_U1, ordered2, coords);
//     v2 = ordered2[ordered.size()/4];
//   }
//   else{
//     v2 = ordered[1];
//   //v2 = ordered[ordered.size()/2];
//   }
   
  //printf("Pinned vertex  %g %g %g / %g %g %g \n", v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z());
  //exit(1);
 
  myAssembler.fixVertex(v1, 0, 1, 0);
  myAssembler.fixVertex(v1, 0, 2, 0);
  myAssembler.fixVertex(v2, 0, 1, 1);
  myAssembler.fixVertex(v2, 0, 2, 0);

  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0), 0, 1);
      myAssembler.numberVertex(t->getVertex(1), 0, 1);
      myAssembler.numberVertex(t->getVertex(2), 0, 1); 
      myAssembler.numberVertex(t->getVertex(0), 0, 2);
      myAssembler.numberVertex(t->getVertex(1), 0, 2);
      myAssembler.numberVertex(t->getVertex(2), 0, 2); 
    }    
  }    

  simpleFunction<double> ONE(1.0);
  simpleFunction<double> MONE(-1.0 );
  laplaceTerm laplace1(model(), 1, &ONE);
  laplaceTerm laplace2(model(), 2, &ONE);
  crossConfTerm cross12(model(), 1, 2, &ONE);
  crossConfTerm cross21(model(), 2, 1, &MONE);
  it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      SElement se((*it)->triangles[i]);
      laplace1.addToMatrix(myAssembler, &se);
      laplace2.addToMatrix(myAssembler, &se);
      cross12.addToMatrix(myAssembler, &se);
      cross21.addToMatrix(myAssembler, &se);
    }
  }
 
  Msg::Debug("Assembly done");
  _lsys->systemSolve();
  Msg::Debug("System solved");

  it = _compound.begin();
  std::set<MVertex *>allNodes;
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for(int j = 0; j < 3; j++){
	allNodes.insert(t->getVertex(j));
      }
    }
  }
  
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value1 = myAssembler.getDofValue(v,0,1);
    double value2 = myAssembler.getDofValue(v,0,2);
    coordinates[v] = SPoint3(value1,value2,0.0);
  }

  checkOrientation();  
  computeNormals();
  buildOct();
  _lsys->clear();
}

void GFaceCompound::compute_distance() const
{
  SBoundingBox3d bbox = model()->bounds();
  double L = norm(SVector3(bbox.max(), bbox.min())); 
  double mu = L/28;
  simpleFunction<double> DIFF(mu * mu), MONE(1.0);
  dofManager<double, double> myAssembler(_lsys);
  distanceTerm distance(model(), 1, &DIFF, &MONE);

  std::vector<MVertex*> ordered;
  boundVertices(_U0, ordered);
  for(unsigned int i = 0; i < ordered.size(); i++)
     myAssembler.fixVertex(ordered[i], 0, 1, 0.0);

  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0), 0, 1);
      myAssembler.numberVertex(t->getVertex(1), 0, 1);
      myAssembler.numberVertex(t->getVertex(2), 0, 1); 
    }    
  }  

  it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      SElement se((*it)->triangles[i]);
      distance.addToMatrix(myAssembler, &se);
    }
    groupOfElements g(*it);
    distance.addToRightHandSide(myAssembler, g);
  }

  Msg::Info("Distance Computation: Assembly done");
  _lsys->systemSolve();
  Msg::Info("Distance Computation: System solved");

  it = _compound.begin();
  std::set<MVertex *>allNodes;
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for(int j = 0; j < 3; j++){
	allNodes.insert(t->getVertex(j));
      }
    }
  }
  
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value =  std::min(0.9999, myAssembler.getDofValue(v, 0, 1));
    double dist = -mu * log(1. - value);
    coordinates[v] = SPoint3(dist, 0.0, 0.0);
  }

  _lsys->clear();

  printStuff();
  printf("End parametrize distance \n");
  printf("--> Write distance function in file: XYZU-*.pos\n");
  printf("--> Exit\n");
  exit(1);
}

void GFaceCompound::computeNormals(std::map<MVertex*,SVector3> &normals) const
{
  computeNormals ();
  normals = _normals;
}

void GFaceCompound::computeNormals() const
{
  _normals.clear();
  std::list<GFace*>::const_iterator it = _compound.begin();
  double J[3][3];
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      t->getJacobian(0, 0, 0, J);
      // SVector3 n (J[2][0],J[2][1],J[2][2]);
      SVector3 d1(J[0][0], J[0][1], J[0][2]);
      SVector3 d2(J[1][0], J[1][1], J[1][2]);
      SVector3 n = crossprod(d1, d2);
      n.normalize();
      for(int j = 0; j < 3; j++){
	std::map<MVertex*, SVector3>::iterator itn = _normals.find(t->getVertex(j));
	if(itn == _normals.end())_normals[t->getVertex(j)] = n;
	else itn->second += n;
      }
    }
  }    
  std::map<MVertex*,SVector3>::iterator itn = _normals.begin();
  for( ; itn != _normals.end() ; ++itn) itn->second.normalize();
}

double GFaceCompound::curvatureMax(const SPoint2 &param) const
{
  if(trivial()){
    return (*(_compound.begin()))->curvatureMax(param);
  }

  parametrize();
  double U, V;
  GFaceCompoundTriangle *lt;
  getTriangle(param.x(), param.y(), &lt, U,V);  
  if(!lt){
    return  0.0;
  }
  if(lt->gf && lt->gf->geomType() != GEntity::DiscreteSurface){
    SPoint2 pv = lt->gfp1*(1.-U-V) + lt->gfp2*U + lt->gfp3*V;
    return lt->gf->curvatureMax(pv);
  }
  return 0.;
}

double GFaceCompound::curvature(MTriangle *t, double u, double v) const
{
  SVector3 n1 = _normals[t->getVertex(0)];
  SVector3 n2 = _normals[t->getVertex(1)];
  SVector3 n3 = _normals[t->getVertex(2)];
  double val[9] = {n1.x(), n2.x(), n3.x(),
		   n1.y(), n2.y(), n3.y(),
		   n1.z(), n2.z(), n3.z()};
  return fabs(t->interpolateDiv(val, u, v, 0.0));
  return 0.;
}

GPoint GFaceCompound::point(double par1, double par2) const
{
  if(trivial()){
    return (*(_compound.begin()))->point(par1,par2);
  }

  parametrize();
  double U,V;
  double par[2] = {par1,par2};
  GFaceCompoundTriangle *lt;
  getTriangle (par1, par2, &lt, U,V);  
  SPoint3 p(3, 3, 0); 
  if(!lt){
    GPoint gp (p.x(),p.y(),p.z(),this);
    gp.setNoSuccess();
    return gp;
  }
  if(lt->gf && lt->gf->geomType() != GEntity::DiscreteSurface){
    SPoint2 pv = lt->gfp1*(1.-U-V) + lt->gfp2*U + lt->gfp3*V;
    return lt->gf->point(pv.x(),pv.y());
  }
  
  const bool LINEARMESH = false;

  if(LINEARMESH){

    //linear Lagrange mesh
    //-------------------------
    p = lt->v1*(1.-U-V) + lt->v2*U + lt->v3*V;
    return GPoint(p.x(),p.y(),p.z(),this,par);

  }
  else{

    //curved PN triangle
    //-------------------------

    const SVector3 n1 = _normals[lt->tri->getVertex(0)];
    const SVector3 n2 = _normals[lt->tri->getVertex(1)];
    const SVector3 n3 = _normals[lt->tri->getVertex(2)];
    
    SVector3 b300,b030,b003;
    SVector3 b210,b120,b021,b012,b102,b201,E,VV,b111;
    double  w12,w21,w23,w32,w31,w13;

    b300 = lt->v1;
    b030 = lt->v2;
    b003 = lt->v3;
    w12 = dot(lt->v2 - lt->v1, n1);
    w21 = dot(lt->v1 - lt->v2, n2);
    w23 = dot(lt->v3 - lt->v2, n2);
    w32 = dot(lt->v2 - lt->v3, n3);
    w31 = dot(lt->v1 - lt->v3, n3);
    w13 = dot(lt->v3 - lt->v1, n1);
    b210 = (2*lt->v1 + lt->v2 -w12*n1)*0.333; 
    b120 = (2*lt->v2 + lt->v1-w21*n2)*0.333;
    b021 = (2*lt->v2 + lt->v3-w23*n2)*0.333;
    b012 = (2*lt->v3 + lt->v2-w32*n3)*0.333;
    b102 = (2*lt->v3 + lt->v1-w31*n3)*0.333;
    b201 = (2*lt->v1 + lt->v3-w13*n1)*0.333;
    E=(b210+b120+b021+b012+b102+b201)*0.16667;
    VV=(lt->v1+lt->v2+lt->v3)*0.333;
    b111=E+(E-VV)*0.5;

    double W = 1-U-V;
    SVector3 point = b300*W*W*W+b030*U*U*U+b003*V*V*V+
      b210*3.*W*W*U+b120*3.*W*U*U+b201*3.*W*W*V+
      b021*3.*U*U*V+b102*3.*W*V*V+b012*3.*U*V*V+
      b111*6.*W*U*V;

    SPoint3 PP(point.x(), point.y(), point.z());
    return GPoint(PP.x(),PP.y(),PP.z(),this,par);
  }
}

Pair<SVector3,SVector3> GFaceCompound::firstDer(const SPoint2 &param) const
{
  if(trivial()){
    return (*(_compound.begin()))->firstDer(param);
  }

  parametrize();
  double U, V;
  GFaceCompoundTriangle *lt;
  getTriangle(param.x(), param.y(), &lt, U,V);
  if(!lt)
    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));

  double mat[2][2] = {{lt->p2.x() - lt->p1.x(), lt->p3.x() - lt->p1.x()},
		      {lt->p2.y() - lt->p1.y(), lt->p3.y() - lt->p1.y()}};
  double inv[2][2];
  inv2x2(mat,inv);
 
  SVector3 dXdxi(lt->v2 - lt->v1);
  SVector3 dXdeta(lt->v3 - lt->v1);

  SVector3 dXdu(dXdxi * inv[0][0] + dXdeta * inv[1][0]);
  SVector3 dXdv(dXdxi * inv[0][1] + dXdeta * inv[1][1]);

  return Pair<SVector3, SVector3>(dXdu,dXdv);
} 

void GFaceCompound::secondDer(const SPoint2 &param, 
                              SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  Msg::Error("Computation of the second derivatives not implemented for compound faces");
}

static void GFaceCompoundBB(void *a, double*mmin, double*mmax)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  mmin[0] = std::min(std::min(t->p1.x(), t->p2.x()), t->p3.x());
  mmin[1] = std::min(std::min(t->p1.y(), t->p2.y()), t->p3.y());
  mmax[0] = std::max(std::max(t->p1.x(), t->p2.x()), t->p3.x());
  mmax[1] = std::max(std::max(t->p1.y(), t->p2.y()), t->p3.y());
  mmin[2] = -1;
  mmax[2] = 1;

  const double dx = mmax[0] - mmin[0];
  const double dy = mmax[1] - mmin[1];
  const double eps = 0.0;//1.e-12;
  mmin[0] -= eps*dx;
  mmin[1] -= eps*dy;
  mmax[0] += eps*dx;
  mmax[1] += eps*dy;
}

static void GFaceCompoundCentroid(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  c[0] = (t->p1.x() + t->p2.x() + t->p3.x()) / 3.0;
  c[1] = (t->p1.y() + t->p2.y() + t->p3.y()) / 3.0;
  c[2] = 0.0;
}

static int GFaceCompoundInEle(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  double M[2][2],R[2],X[2];
  const double eps = 1.e-8;
  const SPoint3 p0 = t->p1;
  const SPoint3 p1 = t->p2;
  const SPoint3 p2 = t->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (c[0] - p0.x());
  R[1] = (c[1] - p0.y());
  sys2x2(M,R,X);
  if(X[0] > -eps && X[1] > -eps && 1. - X[0] - X[1] > -eps){
    return 1;
  }
  return 0;
}

void GFaceCompound::getTriangle(double u, double v, 
                                GFaceCompoundTriangle **lt,
                                double &_u, double &_v) const
{
  parametrize();
  
  double uv[3] = {u, v, 0};
  *lt = (GFaceCompoundTriangle*)Octree_Search(uv, oct);
 //  if(!(*lt)) {
//     for(int i=0;i<nbT;i++){
//       if(GFaceCompoundInEle (&_gfct[i],uv)){
// 	*lt = &_gfct[i];
// 	break;
//       }
//     } 
//   }
  if(!(*lt)){
    return;
  }

  double M[2][2],X[2],R[2];
  const SPoint3 p0 = (*lt)->p1;
  const SPoint3 p1 = (*lt)->p2;
  const SPoint3 p2 = (*lt)->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (u - p0.x());
  R[1] = (v - p0.y());
  sys2x2(M,R,X);
  _u = X[0];
  _v = X[1];
}

void GFaceCompound::buildOct() const
{
  printStuff();

  SBoundingBox3d bb;
  int count = 0;
  std::list<GFace*>::const_iterator it = _compound.begin();
  
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for(int j = 0; j < 3; j++){
	std::map<MVertex*,SPoint3>::const_iterator itj = 
	  coordinates.find(t->getVertex(j));
	bb += SPoint3(itj->second.x(),itj->second.y(),0.0);
      }
      count++;
    }
  }
  _gfct = new GFaceCompoundTriangle[count];
  double origin[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
  double ssize[3] = {bb.max().x() - bb.min().x(),
		     bb.max().y() - bb.min().y(),
		     bb.max().z() - bb.min().z()};
  const int maxElePerBucket = 11;
  oct = Octree_Create(maxElePerBucket, origin, ssize, GFaceCompoundBB,
                      GFaceCompoundCentroid, GFaceCompoundInEle);

  it = _compound.begin();
  count = 0;

  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::map<MVertex*,SPoint3>::const_iterator it0 = 
	coordinates.find(t->getVertex(0));
      std::map<MVertex*,SPoint3>::const_iterator it1 = 
	coordinates.find(t->getVertex(1));
      std::map<MVertex*,SPoint3>::const_iterator it2 = 
	coordinates.find(t->getVertex(2));
      _gfct[count].p1 = it0->second;
      _gfct[count].p2 = it1->second;
      _gfct[count].p3 = it2->second;
      if((*it)->geomType() != GEntity::DiscreteSurface){
	reparamMeshVertexOnFace(t->getVertex(0), *it, _gfct[count].gfp1); 
	reparamMeshVertexOnFace(t->getVertex(1), *it, _gfct[count].gfp2); 
	reparamMeshVertexOnFace(t->getVertex(2), *it, _gfct[count].gfp3); 
      }
      _gfct[count].v1 = SPoint3(t->getVertex(0)->x(), t->getVertex(0)->y(),
                                t->getVertex(0)->z());      
      _gfct[count].v2 = SPoint3(t->getVertex(1)->x(), t->getVertex(1)->y(),
                                t->getVertex(1)->z());      
      _gfct[count].v3 = SPoint3(t->getVertex(2)->x(), t->getVertex(2)->y(),
                                t->getVertex(2)->z());      
      _gfct[count].gf = *it;  
      _gfct[count].tri = t;  
      Octree_Insert(&_gfct[count], oct);
      count ++;
    }
  }
  nbT = count;
  Octree_Arrange(oct);
}
//Verify topological conditions for computing the harmonic map
bool GFaceCompound::checkTopology() const
{
  bool correctTopo = true;

  int Nb = _interior_loops.size();
  int G  = genusGeom() ;
  if( G != 0 || Nb < 1) correctTopo = false;

  if (!correctTopo){
    Msg::Info("--> Wrong topology: Genus=%d and N boundary=%d", G, Nb);
    nbSplit = std::max(G+1, 2);
  }
  else
    Msg::Info("Correct topology: Genus=%d and N boundary=%d", G, Nb);

  return correctTopo;
}

bool GFaceCompound::checkAspectRatio() const
{

  parametrize();

  if (!_checkedAR){

    bool paramOK = true;
    if(allNodes.empty()) buildAllNodes();
    
    double areaMax;
    std::list<GFace*>::const_iterator it = _compound.begin();
    for( ; it != _compound.end() ; ++it){
      for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
	MTriangle *t = (*it)->triangles[i];
	std::map<MVertex*,SPoint3>::const_iterator it0 = coordinates.find(t->getVertex(0));
	std::map<MVertex*,SPoint3>::const_iterator it1 = coordinates.find(t->getVertex(1));
	std::map<MVertex*,SPoint3>::const_iterator it2 = coordinates.find(t->getVertex(2));
	double p0[3] = {t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z()}; 
	double p1[3] = {t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z()};
	double p2[3] = {t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z()};
	double a_3D = fabs(triangle_area(p0, p1, p2));
	double q0[3] = {it0->second.x(), it0->second.y(), 0.0}; 
	double q1[3] = {it1->second.x(), it1->second.y(), 0.0};
	double q2[3] = {it2->second.x(), it2->second.y(), 0.0};
	double a_2D = fabs(triangle_area(q0, q1, q2));
	areaMax = std::max(areaMax,1./a_2D);
      }
    }
    
    if (areaMax > 1.e12) {
      nbSplit = 2;
      printf("--> Geometrical aspect ratio too high (1/area_2D=%g)\n", areaMax);
      printf("--> Partition geometry in N=%d parts\n", nbSplit);
      paramOK = false;
    }
    else {
      Msg::Info("Geometrical aspect ratio (1/area_2D=%g)", areaMax);
      paramOK = true;
    }
    
    _checkedAR = true;
    _paramOK = paramOK;
   }

  return _paramOK;

}

void GFaceCompound::buildAllNodes() const
{

 std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for(int j = 0; j < 3; j++){
	allNodes.insert(t->getVertex(j));
      }
    }
  }

}

int GFaceCompound::genusGeom() const
{
 std::list<GFace*>::const_iterator it = _compound.begin();
 std::set<MEdge, Less_Edge> es;
 std::set<MVertex*> vs;
 int N = 0;
 for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      N++;
      MTriangle *e = (*it)->triangles[i];
      for(int j = 0; j < e->getNumVertices(); j++){
	  vs.insert(e->getVertex(j));
      }
      for(int j = 0; j < e->getNumEdges(); j++){
	  es.insert(e->getEdge(j));
      }
    }
 }
 int poincare = vs.size() - es.size() + N; 

 return (int)(-poincare + 2 - _interior_loops.size())/2;

}

void GFaceCompound::printStuff() const
{
  std::list<GFace*>::const_iterator it = _compound.begin();

  char name0[256], name1[256], name2[256], name3[256];
  char name4[256], name5[256], name6[256];
  sprintf(name0, "UVAREA-%d.pos", (*it)->tag());
  sprintf(name1, "UVX-%d.pos", (*it)->tag());
  sprintf(name2, "UVY-%d.pos", (*it)->tag());
  sprintf(name3, "UVZ-%d.pos", (*it)->tag()); 
  sprintf(name4, "XYZU-%d.pos", (*it)->tag());
  sprintf(name5, "XYZV-%d.pos", (*it)->tag());
  sprintf(name6, "XYZC-%d.pos", (*it)->tag());

 // sprintf(name1, "UVX.pos");
//  sprintf(name2, "UVY.pos");
//  sprintf(name3, "UVZ.pos"); 
//  sprintf(name4, "XYZU.pos");
//  sprintf(name5, "XYZV.pos");
//  sprintf(name6, "XYZC.pos");

  FILE * uva = fopen(name0,"w");
  FILE * uvx = fopen(name1,"w");
  FILE * uvy = fopen(name2,"w");
  FILE * uvz = fopen(name3,"w");
  FILE * xyzu = fopen(name4,"w");
  FILE * xyzv = fopen(name5,"w");
  FILE * xyzc = fopen(name6,"w");

  fprintf(uva,"View \"\"{\n");
  fprintf(uvx,"View \"\"{\n");
  fprintf(uvy,"View \"\"{\n");
  fprintf(uvz,"View \"\"{\n");
  fprintf(xyzu,"View \"\"{\n");
  fprintf(xyzv,"View \"\"{\n");
  fprintf(xyzc,"View \"\"{\n");

  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::map<MVertex*,SPoint3>::const_iterator it0 = 
	coordinates.find(t->getVertex(0));
      std::map<MVertex*,SPoint3>::const_iterator it1 = 
	coordinates.find(t->getVertex(1));
      std::map<MVertex*,SPoint3>::const_iterator it2 = 
	coordinates.find(t->getVertex(2));
//       fprintf(xyzu,"VT(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
// 	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
// 	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
// 	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
// 	      (35.*it0->second.x()-t->getVertex(0)->x()), -t->getVertex(0)->y(), (35.*it0->second.y()-t->getVertex(0)->z()),
// 	      (35.*it1->second.x()-t->getVertex(1)->x()), -t->getVertex(1)->y(), (35.*it1->second.y()-t->getVertex(1)->z()),
// 	      (35.*it2->second.x()-t->getVertex(2)->x()), -t->getVertex(2)->y(), (35.*it2->second.y()-t->getVertex(2)->z()));
      fprintf(xyzv,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
	      it0->second.y(),it1->second.y(),it2->second.y());
      fprintf(xyzu,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
	      it0->second.x(),it1->second.x(),it2->second.x());
      //double K1 = curvature(t,it0->second.x(),it0->second.y());
      //double K2 = curvature(t,it1->second.x(),it1->second.y());
      //double K3 = curvature(t,it2->second.x(),it2->second.y());
      //      const double K = fabs(curvature (t));
      fprintf(xyzc,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
	      it0->second.z(),it1->second.z(),it2->second.z());
              //K1, K2, K3);
      
      double p0[3] = {t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z()}; 
      double p1[3] = {t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z()};
      double p2[3] = {t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z()};
      double a_3D = fabs(triangle_area(p0, p1, p2));
      double q0[3] = {it0->second.x(), it0->second.y(), 0.0}; 
      double q1[3] = {it1->second.x(), it1->second.y(), 0.0};
      double q2[3] = {it2->second.x(), it2->second.y(), 0.0};
      double a_2D = fabs(triangle_area(q0, q1, q2));
      double area = a_3D/a_2D;
      fprintf(uva,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      area, area, area);     
      fprintf(uvx,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      t->getVertex(0)->x(), t->getVertex(1)->x(), t->getVertex(2)->x());
      fprintf(uvy,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      t->getVertex(0)->y(), t->getVertex(1)->y(), t->getVertex(2)->y());
      fprintf(uvz,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      t->getVertex(0)->z(), t->getVertex(1)->z(), t->getVertex(2)->z());
    }
  }
  fprintf(uva,"};\n");
  fclose(uva);
  fprintf(uvx,"};\n");
  fclose(uvx);
  fprintf(uvy,"};\n");
  fclose(uvy);
  fprintf(uvz,"};\n");
  fclose(uvz);
  fprintf(xyzu,"};\n");
  fclose(xyzu);
  fprintf(xyzv,"};\n");
  fclose(xyzv);
  fprintf(xyzc,"};\n");
  fclose(xyzc);
}
