#include <vector>
#include <stack>
#include "GmshConfig.h"
#include "gmshCrossFields.h"
#include "GModel.h"
#include "GFace.h"
#include "MEdge.h"
#include "MTriangle.h"
#include "GmshMessage.h"
#include "Context.h"
#include "meshGFaceOptimize.h"


#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#endif


#if defined(_OPENMP)
#include <omp.h>
#endif


class cross2d {
public:
  MEdge _e;
  bool inCutGraph;
  std::vector<MEdge> _neighbors;
  std::vector<cross2d*> _cneighbors;
  // euler angles
  double _a,_b,_c;
  double _atemp,_btemp,_ctemp;
  std::vector<MTriangle *> _t;
  cross2d (MEdge &e, MTriangle *r, MEdge &e1, MEdge &e2) : _e(e) , inCutGraph(false), _a (0), _b(0), _c(0)
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

  double lifting (double a){
    double D = M_PI*.5;
    if (fabs(_a - a) < fabs(_a - (a+D)) &&
	fabs(_a - a) < fabs(_a - (a-D))) {return a;}
    else if (fabs(_a - (a+D)) < fabs(_a - a) &&
	     fabs(_a - (a+D)) < fabs(_a - (a-D))) {return a+D;}
    else {return a-D;}
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


static void computeLifting (cross2d *first, int branch){
  // store in _atemp the branch of the neighbor
  FILE *f  = fopen ("cutgraph.pos","w");
  fprintf(f,"View \"CUTGRAPH\"{\n");
  std::stack<cross2d*> _s;
  _s.push (first);
  first->_atemp = first->_a + branch *M_PI/2.0;
  first->_btemp = 10000.;
  while (!_s.empty()){
    cross2d *c = _s.top();
    _s.pop();
    for (size_t i=0;i<c->_cneighbors.size();i++){
      cross2d *n = c->_cneighbors[i];
      if (n->_btemp < 1000){
	n->_btemp = 10000;
	_s.push(n);
	n->_atemp = c->lifting (n->_a); 
      }
      else if (fabs(c->_atemp - n->_atemp) > M_PI/8){
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",
		c->_e.getVertex(0)->x(),
		c->_e.getVertex(0)->y(),
		c->_e.getVertex(0)->z(),
		c->_e.getVertex(1)->x(),
		c->_e.getVertex(1)->y(),
		c->_e.getVertex(1)->z());
      }
    }    
  }
  fprintf(f,"};\n");
  fclose(f);
}

static void duplicateNodesInCutGraph (std::vector<GFace *> &f,
				      std::map<MEdge,cross2d,Less_Edge > &C,
				      std::map<MVertex*,MVertex*> &new2old){

  FILE *_f = fopen("nodes.pos","w");
  fprintf(_f,"View \" nodes \"{\n");  
  v2t_cont adj;
		 
  for (size_t i=0;i<f.size();i++){
    buildVertexToElement(f[i]->triangles,adj);
  }

  v2t_cont::iterator it = adj.begin();
  std::set<MElement *> touched;
  std::set<MVertex *> vtouched;
  while(it != adj.end()) {
    std::vector <MElement*> els = it->second;
    std::stack<MElement*> _s;
    _s.push(els[0]);
    els.erase(els.begin());
    while (!_s.empty()){
      MElement *t = _s.top();
      _s.pop();
      for (int i=0;i<3;i++){
	MEdge e0 = t->getEdge(i);
	std::map<MEdge,cross2d,Less_Edge >::iterator it0 = C.find(e0);
	if (!it0->second.inCutGraph){
	  for (size_t j=0;j<it0->second._t.size();j++){
	    std::vector <MElement*>::iterator ite = std::find(els.begin(),els.end(),it0->second._t[j]);
	    if (ite != els.end()){
	      els.erase(ite);
	      _s.push(it0->second._t[j]);
	    }
	  }	     
	}
      }      
    }
    if (!els.empty()){
      MVertex *v = new MVertex (it->first->x(),it->first->y(),it->first->z(),f[0]);
      new2old[v] = it->first;
      f[0]->mesh_vertices.push_back(v);
      for (size_t i=0;i<els.size();i++){
	for (size_t j=0;j<3;j++){
	  if (els[i]->getVertex(j) == it->first)
	    els[i]->setVertex(j,v);
	}
      }
      fprintf(_f,"SP(%g,%g,%g){%d};\n",it->first->x(),it->first->y(),it->first->z(),
	      (int)els.size());  
      printf("found vertex with %d on one side\n",els.size());
    }
    ++it;
  }
  fprintf(_f,"};\n");
  fclose(_f);
}

  
static void computePotential (GModel *gm,std::vector<GFace *> &f,
			      const char * outputName,
			      dofManager<double> &dof,
			      int dir,
			      std::map<MEdge,cross2d,Less_Edge > &C,
			      std::map<MVertex*,MVertex*> &new2old){
  
#if defined(HAVE_SOLVER)
  double a[3];
  std::set<MVertex *>vs;
  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      for (size_t k=0;k<3;k++){
	vs.insert(t->getVertex(k));
      }
    }
  }

#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *_lsys = new linearSystemCSRGmm<double>;
  //  _lsys->setGmres(0);
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(_lsys);
  
  for(std::set<MVertex *>::iterator it = vs.begin(); it != vs.end(); ++it)
    myAssembler.numberVertex(*it, 0, 1);
    
  simpleFunction<double> ONE(1.0);
  laplaceTerm l(0, 1, &ONE);
  
  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      SElement se(t);
      l.addToMatrix(myAssembler, &se);
      MEdge e0 = t->getEdge(0);
      MEdge e1 = t->getEdge(1);
      MEdge e2 = t->getEdge(2);
      std::map<MEdge,cross2d,Less_Edge >::iterator it0 = C.find(e0);
      std::map<MEdge,cross2d,Less_Edge >::iterator it1 = C.find(e1);
      std::map<MEdge,cross2d,Less_Edge >::iterator it2 = C.find(e2);
      double a0 = 0;
      int n = 0;

      if (it0 != C.end()){
	n++; a0 += it0->second._atemp;
      }
      else {
	std::map<MVertex*,MVertex*>::iterator itx0 = new2old.find(e0.getVertex(0));
	std::map<MVertex*,MVertex*>::iterator itx1 = new2old.find(e0.getVertex(1));
	e0 = MEdge (itx0== new2old.end() ? e0.getVertex(0) : itx0->second,
		    itx1== new2old.end() ? e0.getVertex(1) : itx1->second);
	it0 = C.find(e0);
	if (it0 != C.end() && !it0->second.inCutGraph){
	  n++; a0 += it0->second._atemp;
	}
      }

      if (it1 != C.end()){
	n++; a0 += it1->second._atemp;
      }
      else {
	std::map<MVertex*,MVertex*>::iterator itx0 = new2old.find(e1.getVertex(0));
	std::map<MVertex*,MVertex*>::iterator itx1 = new2old.find(e1.getVertex(1));
	e1 = MEdge (itx0== new2old.end() ? e1.getVertex(0) : itx0->second,
		    itx1== new2old.end() ? e1.getVertex(1) : itx1->second);
	it1 = C.find(e1);
	if (it1 != C.end() && !it1->second.inCutGraph){
	  n++; a0 += it1->second._atemp;
	}
      }

      if (it2 != C.end()){
	n++; a0 += it2->second._atemp;
      }
      else {
	std::map<MVertex*,MVertex*>::iterator itx0 = new2old.find(e2.getVertex(0));
	std::map<MVertex*,MVertex*>::iterator itx1 = new2old.find(e2.getVertex(1));
	e2 = MEdge (itx0== new2old.end() ? e2.getVertex(0) : itx0->second,
		    itx1== new2old.end() ? e2.getVertex(1) : itx1->second);
	it2 = C.find(e2);
	if (it2 != C.end() && !it2->second.inCutGraph){
	  n++; a0 += it2->second._atemp ;
	}
      }
      if (n) a0 /= n;
      double va,vb,vc;
      std::map<MVertex*,MVertex*>::iterator itx = new2old.find(t->getVertex(0));
      dof.getDofValue(itx == new2old.end() ? t->getVertex(0): itx->second, 0, 1,va);
      itx = new2old.find(t->getVertex(1));
      dof.getDofValue(itx == new2old.end() ? t->getVertex(1): itx->second, 0, 1,vb);
      itx = new2old.find(t->getVertex(2));
      dof.getDofValue(itx == new2old.end() ? t->getVertex(2): itx->second, 0, 1,vc);

      double F = 1;//exp((va+vb+vc)/3.0);
      
      double c = dir == 1 ? F*cos(a0) : -F*sin (a0);
      double s = dir == 1 ? F*sin(a0) : F*cos (a0);
      double G1[3] = {c,s,0};
      double G2[3] = {c,s,0};
      double G3[3] = {c,s,0};
      double g1[3];
      a[0] = 1; a[1] = 0; a[2] = 0;
      t->interpolateGrad (a, 0,0,0,g1);
      double RHS1 = g1[0]*G1[0]+g1[1]*G1[1]+g1[2]*G1[2];
      a[0] = 0; a[1] = 1; a[2] = 0;
      t->interpolateGrad (a, 0,0,0,g1);
      double RHS2 = g1[0]*G2[0]+g1[1]*G2[1]+g1[2]*G2[2];
      a[0] = 0; a[1] = 0; a[2] = 1;
      t->interpolateGrad (a, 0,0,0,g1);
      double RHS3 = g1[0]*G3[0]+g1[1]*G3[1]+g1[2]*G3[2];
      int num1 = myAssembler.getDofNumber (l.getLocalDofR (&se,0));
      int num2 = myAssembler.getDofNumber (l.getLocalDofR (&se,1));
      int num3 = myAssembler.getDofNumber (l.getLocalDofR (&se,2));


      double V = t->getVolume();
      if (fabs(it0->second._atemp-it1->second._atemp) < M_PI/10 &&
      	  fabs(it0->second._atemp-it2->second._atemp) < M_PI/10 &&
      	  fabs(it1->second._atemp-it2->second._atemp) < M_PI/10 ){
	_lsys->addToRightHandSide (num1,RHS1*V);
	_lsys->addToRightHandSide (num2,RHS2*V);
	_lsys->addToRightHandSide (num3,RHS3*V);
      }
    }
  }
  _lsys->systemSolve();
  
  FILE *_f = fopen (outputName,"w");
  fprintf(_f,"View \"V\"{\n");

  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      double a,b,c;
      myAssembler.getDofValue(t->getVertex(0), 0, 1,a);
      myAssembler.getDofValue(t->getVertex(1), 0, 1,b);
      myAssembler.getDofValue(t->getVertex(2), 0, 1,c);
      
      fprintf(_f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(),t->getVertex(0)->y(),t->getVertex(0)->z(),
	      t->getVertex(1)->x(),t->getVertex(1)->y(),t->getVertex(1)->z(),
	      t->getVertex(2)->x(),t->getVertex(2)->y(),t->getVertex(2)->z(),
	      a,b,c);
    }
  }
  fprintf(_f,"};\n");
  fclose(_f);
#endif
}


int computeCrossField2dTheta (GModel *gm,std::vector<GFace *> &f, const char * outputName){
  Msg::SetNumThreads(Msg::GetMaxThreads());

  std::map<MEdge,cross2d,Less_Edge > C;
  std::set<MVertex *>vs;
  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      for (size_t k=0;k<3;k++){
	vs.insert(t->getVertex(k));
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
  fprintf(of,"View \"Direction fields\"{\n");
  for (it = C.begin(); it !=C.end();++it){
    double a = it->second.grad();
    double a0 = it->second._a;
    MEdge e0 = it->second._e;

    double fact = 1.-a;
    if (fact<.001) fact=.001;

    for (size_t I = 0 ; I< it->second._t.size();I++){
      
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
	      0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	      0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	      0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	      cos (a0)*fact, sin(a0)*fact,0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
	      0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	      0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	      0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	      -sin (a0)*fact, cos(a0)*fact,0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
	      0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	      0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	      0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	      -cos (a0)*fact, -sin(a0)*fact,0.0);
      fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
	      0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	      0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	      0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	      sin (a0)*fact, -cos(a0)*fact,0.0);
    }
    /*
        fprintf(of,"SP(%g,%g,%g){%g};",
    	    0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
    	    0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
    	    0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()), a);
    */
  }

#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *_lsys = new linearSystemCSRGmm<double>;
  //  _lsys->setGmres(0);
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(_lsys);
  
  //  myAssembler.fixVertex(*vs.begin(), 0, 1, 0);
  for(std::set<MVertex *>::iterator it = vs.begin(); it != vs.end(); ++it)
    myAssembler.numberVertex(*it, 0, 1);
  
  FILE *_f = fopen ("grad.pos","w");
  fprintf(_f,"View \"grad\"{\n");

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(0, 1, &ONE);

  
  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      SElement se(t);
      l.addToMatrix(myAssembler, &se);
      MEdge e0 = t->getEdge(0);
      MEdge e1 = t->getEdge(1);
      MEdge e2 = t->getEdge(2);
      std::map<MEdge,cross2d,Less_Edge >::iterator it0 = C.find(e0);
      std::map<MEdge,cross2d,Less_Edge >::iterator it1 = C.find(e1);
      std::map<MEdge,cross2d,Less_Edge >::iterator it2 = C.find(e2);
      double a0 = it0->second._a;
      double a1 = it0->second.lifting(it1->second._a);
      double a2 = it0->second.lifting(it2->second._a);

      double a[3] = {0.5*(a0+a2),0.5*(a0+a1),0.5*(a1+a2)};
      double g[3] = {0,0,0};
      t->interpolateGrad (a, 0,0,0,g);
      SPoint3 pp = t->barycenter();
      //      fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",pp.x(),pp.y(),pp.z(),
      //	      g[0],g[1],g[2]);
      fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",pp.x(),pp.y(),pp.z(),
	      -g[1],g[0],g[2]);
      double g1[3];
      a[0] = 1; a[1] = 0; a[2] = 0;
      t->interpolateGrad (a, 0,0,0,g1);
      double RHS1 = -g1[0]*g[1]+g1[1]*g[0]+g1[2]*g[2];
      //double RHS1 = g1[0]*g[0]+g1[1]*g[1]+g1[2]*g[2];
      a[0] = 0; a[1] = 1; a[2] = 0;
      t->interpolateGrad (a, 0,0,0,g1);
      double RHS2 = -g1[0]*g[1]+g1[1]*g[0]+g1[2]*g[2];
	    //double RHS2 = g1[0]*g[0]+g1[1]*g[1]+g1[2]*g[2];
      a[0] = 0; a[1] = 0; a[2] = 1;
      t->interpolateGrad (a, 0,0,0,g1);
      double RHS3 = -g1[0]*g[1]+g1[1]*g[0]+g1[2]*g[2];
	    //double RHS3 = g1[0]*g[0]+g1[1]*g[1]+g1[2]*g[2];
      int num1 = myAssembler.getDofNumber (l.getLocalDofR (&se,0));
      int num2 = myAssembler.getDofNumber (l.getLocalDofR (&se,1));
      int num3 = myAssembler.getDofNumber (l.getLocalDofR (&se,2));
      double V = t->getVolume();
      _lsys->addToRightHandSide (num1,RHS1*V);
      _lsys->addToRightHandSide (num2,RHS2*V);
      _lsys->addToRightHandSide (num3,RHS3*V);
      
    }
  }
  fprintf(_f,"};\n");
  fclose(_f);
  _lsys->systemSolve();

  _f = fopen ("H.pos","w");
  fprintf(_f,"View \"H\"{\n");

  for (size_t i=0;i<f.size();i++){
    for (size_t j=0;j<f[i]->triangles.size();j++){
      MTriangle *t = f[i]->triangles[j];
      double a,b,c;
      myAssembler.getDofValue(t->getVertex(0), 0, 1,a);
      myAssembler.getDofValue(t->getVertex(1), 0, 1,b);
      myAssembler.getDofValue(t->getVertex(2), 0, 1,c);
      
      fprintf(_f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(),t->getVertex(0)->y(),t->getVertex(0)->z(),
	      t->getVertex(1)->x(),t->getVertex(1)->y(),t->getVertex(1)->z(),
	      t->getVertex(2)->x(),t->getVertex(2)->y(),t->getVertex(2)->z(),
	      a,b,c);
    }
  }
  fprintf(_f,"};\n");
  fclose(_f);

  _f = fopen ("lifting1.pos","w");
  fprintf(_f,"View \"lifting\"{\n");
  computeLifting (&(C.begin()->second),0);


  for (it = C.begin(); it !=C.end();++it){
    MEdge e0 = it->second._e;
    double a0 = it->second._atemp;
    if (it->second._cneighbors.size() == 4){
      double a1 = it->second._cneighbors[0]->_atemp;
      double a2 = it->second._cneighbors[1]->_atemp;
      double b1 = it->second._cneighbors[2]->_atemp;
      double b2 = it->second._cneighbors[3]->_atemp;
      if ((fabs(a1-a0) > M_PI/6 && fabs(a2-a0) > M_PI/6)||
	  (fabs(b1-a0) > M_PI/6 && fabs(b2-a0) > M_PI/6)){
	it->second.inCutGraph = true;
	fprintf(_f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",
		e0.getVertex(0)->x(),
		e0.getVertex(0)->y(),
		e0.getVertex(0)->z(),
		e0.getVertex(1)->x(),
		e0.getVertex(1)->y(),
	        e0.getVertex(1)->z());	
      }
    }

    fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",
	    0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
	    0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
	    0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
	    cos (a0), sin(a0),0.0);
  }
  fprintf(_f,"};\n");
  fclose(_f);


  std::map<MVertex*,MVertex*> new2old;
  duplicateNodesInCutGraph (f,C,new2old);

  computePotential (gm,f,"potX.pos",myAssembler,0,C,new2old);
  computePotential (gm,f,"potY.pos",myAssembler,1,C,new2old);
  
#endif
  /*
  //      double avg = atan2 (sin(a1)+sin(a2)+sin(a0),
  //			  cos(a1)+cos(a2)+cos(a0));
  fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
  0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
  0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
  0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
  cos (a0), sin(a0),0.0);
  fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
  0.5*(e1.getVertex(0)->x()+e1.getVertex(1)->x()),
  0.5*(e1.getVertex(0)->y()+e1.getVertex(1)->y()),
  0.5*(e1.getVertex(0)->z()+e1.getVertex(1)->z()),
  cos (a1), sin(a1),0.0);
  fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
  0.5*(e2.getVertex(0)->x()+e2.getVertex(1)->x()),
  0.5*(e2.getVertex(0)->y()+e2.getVertex(1)->y()),
  0.5*(e2.getVertex(0)->z()+e2.getVertex(1)->z()),
  cos (a2), sin(a2),0.0);
  fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
  0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
  0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
  0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()),
  -sin (a0), cos(a0),0.0);
  fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
  0.5*(e1.getVertex(0)->x()+e1.getVertex(1)->x()),
  0.5*(e1.getVertex(0)->y()+e1.getVertex(1)->y()),
  0.5*(e1.getVertex(0)->z()+e1.getVertex(1)->z()),
  -sin (a1), cos(a1),0.0);
  fprintf(of,"VP(%g,%g,%g){%g,%g,%g};\n",
  0.5*(e2.getVertex(0)->x()+e2.getVertex(1)->x()),
  0.5*(e2.getVertex(0)->y()+e2.getVertex(1)->y()),
  0.5*(e2.getVertex(0)->z()+e2.getVertex(1)->z()),
  -sin (a2), cos(a2),0.0);
  }
  }
  */
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
