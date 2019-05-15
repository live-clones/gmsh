#include <vector>
#include "gmshCrossFields.h"
#include "GModel.h"
#include "GFace.h"
#include "MEdge.h"
#include "MTriangle.h"
#include "GmshMessage.h"
#include "Context.h"
#if defined(_OPENMP)
#include <omp.h>
#endif

class cross2d {
public:
  MEdge _e;
  std::vector<MEdge> _neighbors;
  std::vector<cross2d*> _cneighbors;
  // euler angles
  double _a,_b,_c;
  double _atemp,_btemp,_ctemp;
  std::vector<MTriangle *> _t;
  cross2d (MEdge &e, MTriangle *r, MEdge &e1, MEdge &e2) : _e(e) , _a (0), _b(0), _c(0)
  {
    _t.push_back(r);
    _neighbors.push_back(e1);
    _neighbors.push_back(e2);
  }
  void normalize(double &a){
    double D = M_PI*.5;
    if (a < 0 ) while (a < 0) a += D; 
    if (a >= D) while (a >= D) a -= D; 
  }
  void finish ( std::map<MEdge,cross2d,Less_Edge > &C){
    for (size_t i=0;i<_neighbors.size();i++){
      std::map<MEdge,cross2d,Less_Edge >::iterator it = C.find(_neighbors[i]);
      if (it == C.end())Msg::Error("impossible situation");
      else _cneighbors.push_back(&(it->second));      
    }
    if (_cneighbors.size() != 4){
      _a = atan2 (_e.getVertex(1)->y()-_e.getVertex(0)->y(),_e.getVertex(1)->x()-_e.getVertex(0)->x());
      normalize(_a);
      _atemp = _a;
    }
    _neighbors.clear();
    _b = _btemp = sin (4*_a);
    _c = _ctemp = cos (4*_a);
  }
  double average_init (){
    if (_cneighbors.size() == 4){
      
      _btemp = 0.25*(_cneighbors[0]->_b+_cneighbors[1]->_b+_cneighbors[2]->_b+_cneighbors[3]->_b);
      _ctemp = 0.25*(_cneighbors[0]->_c+_cneighbors[1]->_c+_cneighbors[2]->_c+_cneighbors[3]->_c);
      _atemp = 0.25*atan2(_b,_c);
      normalize(_atemp);
      return 1;
    }
    return 1;
  }  

  void update () {
    _a = _atemp;
    _b = _btemp;
    _c = _ctemp;    
  }
  
  double grad () {
    if (_cneighbors.size() == 4){
      double D = M_PI*.5;
      double a[4]  = {_cneighbors[0]->_a,_cneighbors[1]->_a,
		      _cneighbors[2]->_a,_cneighbors[3]->_a};
      double b[4];
      for (int i=0;i<4;i++){
	if (fabs(_a - a[i]) < fabs(_a - (a[i]+D)) &&
	    fabs(_a - a[i]) < fabs(_a - (a[i]-D))) {b[i] = a[i];}
	else if (fabs(_a - (a[i]+D)) < fabs(_a - (a[i])) &&
		 fabs(_a - (a[i]+D)) < fabs(_a - (a[i]-D))) {b[i] = a[i]+D;}
	else {b[i] = a[i]-D;}	
      }
      return fabs(_a-b[0]) + fabs(_a-b[1]) + fabs(_a-b[2]) + fabs(_a-b[3]) ;
    }
    return 0;
  }
  
  double average (){
    if (_cneighbors.size() == 4){
      double D = M_PI*.5;
      double a[4]  = {_cneighbors[0]->_a,_cneighbors[1]->_a,
		      _cneighbors[2]->_a,_cneighbors[3]->_a};
      double b[4];
      double avg = 0.0;
      for (int i=0;i<4;i++){
	if (fabs(_a - a[i]) < fabs(_a - (a[i]+D)) &&
	    fabs(_a - a[i]) < fabs(_a - (a[i]-D))) {b[i] = a[i];}
	else if (fabs(_a - (a[i]+D)) < fabs(_a - (a[i])) &&
		 fabs(_a - (a[i]+D)) < fabs(_a - (a[i]-D))) {b[i] = a[i]+D;}
	else {b[i] = a[i]-D;}	
      }
      avg = 0.25*(b[0]+b[1]+b[2]+b[3]);
      
      normalize(avg);
      
      double d = fabs(_a-avg);
      _atemp = avg;
      return d;
    }
    return 0;
  }
};
// ---------------------------------------------
// TODO : MAKE IT PARALLEL AND SUPERFAST
//        DO IT ON SURFACES
// ---------------------------------------------

int computeCrossField2dTheta (GModel *gm,std::vector<GFace *> &f, const char * outputName){
  Msg::SetNumThreads(Msg::GetMaxThreads());
  
  std::map<MEdge,cross2d,Less_Edge > C;
  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      for (size_t k=0;k<3;k++){
	MEdge e = t->getEdge(k);
	MEdge e1 = t->getEdge((k+1)%3);
	MEdge e2 = t->getEdge((k+2)%3);
	cross2d c (e,t,e1,e2);
	std::map<MEdge,cross2d,Less_Edge >::iterator it = C.find(e);
	if (it == C.end())C.insert(std::make_pair(e,c));
	else {
	  it->second._t.push_back(t);
	  it->second._neighbors.push_back(e1);
	  it->second._neighbors.push_back(e2);
	}
      }
    }
  }

  std::map<MEdge,cross2d,Less_Edge >::iterator it = C.begin();
  for (; it !=C.end();++it)it->second.finish(C);

  std::vector<cross2d*> pc;
  for (it = C.begin(); it !=C.end();++it)pc.push_back(&(it->second));
  
  const int MAXITER = 20000;
  int ITER = 0;
  while (ITER++ < MAXITER){
    double DELTA = 0;
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (size_t i=0;i<pc.size(); i++){
      if (ITER<2000)DELTA += pc[i]->average_init();
      else DELTA += pc[i]->average();
    }

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (size_t i=0;i<pc.size(); i++)pc[i]->update();
    
    if (ITER%100 == 0)printf("DELTA = %12.5E\n",DELTA);
    if (DELTA  < 1.e-12)break;
    //    getchar();
  }

  FILE *of = fopen ("cross.pos","w");
  fprintf(of,"View \"\"{\n");
  for (it = C.begin(); it !=C.end();++it){
    double a = it->second.grad();
    MEdge e0 = it->second._e;
    fprintf(of,"SP(%g,%g,%g){%g};",
	    0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	    0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	    0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()), a);
  }
  
  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      MEdge e0 = t->getEdge(0);
      MEdge e1 = t->getEdge(1);
      MEdge e2 = t->getEdge(2);
      std::map<MEdge,cross2d,Less_Edge >::iterator it0 = C.find(e0);
      std::map<MEdge,cross2d,Less_Edge >::iterator it1 = C.find(e1);
      std::map<MEdge,cross2d,Less_Edge >::iterator it2 = C.find(e2);
      double a0 = it0->second._a;
      double a1 = it1->second._a;
      double a2 = it2->second._a;
      //      double avg = atan2 (sin(a1)+sin(a2)+sin(a0),
      //			  cos(a1)+cos(a2)+cos(a0));		 
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};",
	      0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	      0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	      0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	      cos (a0), sin(a0),0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};",
	      0.5*(e1.getVertex(0)->x()+e1.getVertex(1)->x()),
	      0.5*(e1.getVertex(0)->y()+e1.getVertex(1)->y()),
	      0.5*(e1.getVertex(0)->z()+e1.getVertex(1)->z()),
	      cos (a1), sin(a1),0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};",
	      0.5*(e2.getVertex(0)->x()+e2.getVertex(1)->x()),
	      0.5*(e2.getVertex(0)->y()+e2.getVertex(1)->y()),
	      0.5*(e2.getVertex(0)->z()+e2.getVertex(1)->z()),
	      cos (a2), sin(a2),0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};",
	      0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	      0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	      0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	      -sin (a0), cos(a0),0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};",
	      0.5*(e1.getVertex(0)->x()+e1.getVertex(1)->x()),
	      0.5*(e1.getVertex(0)->y()+e1.getVertex(1)->y()),
	      0.5*(e1.getVertex(0)->z()+e1.getVertex(1)->z()),
	      -sin (a1), cos(a1),0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};",
	      0.5*(e2.getVertex(0)->x()+e2.getVertex(1)->x()),
	      0.5*(e2.getVertex(0)->y()+e2.getVertex(1)->y()),
	      0.5*(e2.getVertex(0)->z()+e2.getVertex(1)->z()),
	      -sin (a2), cos(a2),0.0);
      
      /*
      fprintf(of,"VT(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g};",
	      t->getVertex(0)->x(),t->getVertex(0)->y(),t->getVertex(0)->z(),
	      t->getVertex(1)->x(),t->getVertex(1)->y(),t->getVertex(1)->z(),
	      t->getVertex(2)->x(),t->getVertex(2)->y(),t->getVertex(2)->z(),
	      cos(avg),sin(avg),0.,cos(avg),sin(avg),0.,cos(avg),sin(avg),0.);
      */
      
    }
  }
  fprintf(of,"};\n");
  fclose(of);
  return 0;
  
}

int computeCrossField (GModel *gm)
{
  std::vector<GFace *> f ;
  for (GModel::fiter it = gm->firstFace() ; it != gm->lastFace();++it){
    GFace *gf = *it;
    f.push_back(gf);
  }
  //  if (!strcmp(method,"theta"))
  return computeCrossField2dTheta (gm,f,"toto");
    //  else
    //    Msg::Error("Unknown Cross Field Computation Method %s",method);
}
