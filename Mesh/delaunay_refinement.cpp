#ifdef _OPENMP
#include <omp.h>
#endif
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include "GmshMessage.h"
#include "SPoint3.h"
#include "delaunay3d_private.h"
#include "delaunay3d.h"
#include "rtree.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "GRegion.h"
#include "GFace.h"

typedef  std::set< Edge > edgeContainer2;

long int AVGSEARCH;

struct edgeContainer
{
  std::set< Edge > _hash2;
  std::vector<std::vector<Edge> > _hash;
  edgeContainer (unsigned int N = 1000000) {
    _hash.resize(N);
  }
  bool addNewEdge2 (const Edge &e) {
    std::set< Edge >::iterator it = _hash2.find(e);
    if (it != _hash2.end())return false;
    _hash2.insert(e);
    return true;
  }
  bool isNewEdge (const Edge &e) {
    size_t h = (size_t) e.first >> 3;
    std::vector<Edge> &v = _hash[h %_hash.size()];
    AVGSEARCH+=v.size();
    for (unsigned int i=0; i< v.size();i++)if (e == v[i]) {return false;}
    return true;    
  } 

  bool addNewEdge (const Edge &e) 
  {
    size_t h = (size_t) e.first >> 3;
    std::vector<Edge> &v = _hash[h %_hash.size()];
    AVGSEARCH+=v.size();
    for (unsigned int i=0; i< v.size();i++)if (e == v[i]) {return false;}
    v.push_back(e);
    return true;
  }
};

struct IPT {
  double _x1,_x2,_x3,_x4;
  IPT(double x1, double x2, double x3, double x4) :
    _x1(x1),_x2(x2),_x3(x3),_x4(x4){};
};

double adaptiveTrapezoidalRule (SPoint3 p1 , SPoint3 p2 , 
				double lc1 , double lc2 , 
				double (*f)(const SPoint3 &p, void *), 
				void *data, std::vector< IPT > & _result, 
				double &dl, double epsilon = 1.e-6)
{
  std::stack< IPT > _stack;
  _result.clear(); 
  // local parameters on the edge
  double t1 = 0.0;
  double t2 = 1.0;
  // edge vector
  SPoint3 dp = p2-p1;

  // value of f on both sides
  double f1 = lc1; //f(p1 + dp*t1,data);
  double f2 = lc2; //f(p1 + dp*t2,data);

  dl = p1.distance(p2);

  //  printf ("edge length %g lc %g %g\n",dl,f1,f2);

  // add one subsegment on the stack
  IPT top (t1,t2,f1,f2);
  _stack.push(top);
  // store total value of the integral
  double totalValue = 0.0;
  while(!_stack.empty()){
    IPT pp = _stack.top();
    _stack.pop();
    t1 = pp._x1;
    t2 = pp._x2;
    f1 = pp._x3;
    f2 = pp._x4;
    // mid point
    double t12 = 0.5* (t1+t2);
    SPoint3 pmid = p1 + dp*t12;
    double fmid = 0.5* (f1+f2);//f(pmid,data);
    double dt = t2-t1;
    // average should be compared to mid value    
    double f12 = 0.5* (f1+f2);
    if (fabs (f12 - 0.5*(f1+f2)) > epsilon*dt ) {
      IPT left  (t1,t12,f1,f12);
      IPT right (t12,t2,f12,f2);
      _stack.push(left);
      _stack.push(right);
    }
    else {
      _result.push_back (pp);
      // compute the integral using trapezoidal rule on both sides
      totalValue += 1./((0.5*f12+0.25*(f1+f2)))*dt;      
    }
  }
  // take into account the real length of the edge
  totalValue *= dl;
  //  printf("adimensional length %g\n",totalValue);
  return totalValue;
}


void saturateEdge (Edge &e, std::vector<Vertex*> &S, double (*f)(const SPoint3 &p, void *), void *data) {  
  std::vector< IPT > _result;
  double dl;
  SPoint3 p1 = e.first->point();
  SPoint3 p2 = e.second->point();
  double dN = adaptiveTrapezoidalRule (p1,p2,e.first->lc(), e.second->lc(), f,data,_result, dl);
  const int N = (int) (dN+0.1); 
  double interval = dN/N;  
  double L = 0.0;  
  
  //  printf("edge length %g %d intervals of size %g\n",dl,N,interval);

  for (unsigned int i=0; i< _result.size() ; i++) {
    double t1 = _result[i]._x1;
    double t2 = _result[i]._x2;
    double f1 = _result[i]._x3;
    double f2 = _result[i]._x4;
    double dL = 2.*(t2-t1) * dl / (f1+f2);
    //    printf("%g --> %g for %g --> %g\n",L,dL,t1,t2);
    double L0 = L;
    while (1) {
      double t = t1 + (L+interval-L0)*(t2-t1) / dL;
      if (t >= t2) {
	break;
      }
      else {
	SPoint3 p = p1 * (1.-t) + p2*t; 
	double lc = e.first->lc() * (1.-t) + e.second->lc()*t; 
	const double dx = 1.e-16 * (double) rand() / RAND_MAX;
	const double dy = 1.e-16 * (double) rand() / RAND_MAX;
	const double dz = 1.e-16 * (double) rand() / RAND_MAX;
	S.push_back(new Vertex(p.x()+dx,p.y()+dy,p.z()+dz,lc));
	L += interval;
      }
    }
  }
  
  //  printf("%d points added\n",S.size());

  //  exit(1);
}

void saturateEdges ( edgeContainer &ec, 
		     std::vector<Tet*> &T, 
		     int nbThreads, 
		     std::vector<Vertex*> &S, 
		     double (*f)(const SPoint3 &p, void *), void *data) {
  AVGSEARCH= 0;
  int counter = 0;
  for (int i=0;i<T.size();i++){
    if (T[i]->V[0] && T[i]->_modified){
      T[i]->_modified = false;
      for (int iEdge=0;iEdge<6;iEdge++){
	Edge ed = T[i]->getEdge(iEdge);
	bool isNew = ec.addNewEdge(ed);
	counter++;
	if (isNew){	  
	  saturateEdge (ed, S, f, data);
	}
      }
    }
  }    
  //  printf("a total of %d Tets counter %d AVG %d\n",T.size(),counter,AVGSEARCH/counter);
}

/////////////////////////   F I L T E R I N G ////////////////////////////////////////////////////

class volumePointWithExclusionRegion {
public : 
  Vertex *_v;
  volumePointWithExclusionRegion (Vertex *v) : _v(v){
  }

  bool inExclusionZone (volumePointWithExclusionRegion *p)
  {    
    double d = sqrt ((p->_v->x() - _v->x()) * (p->_v->x() - _v->x())+
		     (p->_v->y() - _v->y()) * (p->_v->y() - _v->y())+
		     (p->_v->z() - _v->z()) * (p->_v->z() - _v->z()));
    return d < .7*p->_v->lc();//_l;
  }
  void minmax (double _min[3], double _max[3]) const
  {
    _min[0] = _v->x() - 1.1*_v->lc();
    _min[1] = _v->y() - 1.1*_v->lc();
    _min[2] = _v->z() - 1.1*_v->lc();
    _max[0] = _v->x() + 1.1*_v->lc();
    _max[1] = _v->y() + 1.1*_v->lc();
    _max[2] = _v->z() + 1.1*_v->lc();
  }
};

struct my_wrapper_3D {
  bool _tooclose;
  volumePointWithExclusionRegion *_p;
  my_wrapper_3D (volumePointWithExclusionRegion *sp) : 
    _tooclose (false), _p(sp) {}
};


bool rtree_callback(volumePointWithExclusionRegion *neighbour,void* point)
{
  my_wrapper_3D *w = static_cast<my_wrapper_3D*>(point);

  if (neighbour->inExclusionZone(w->_p)){
    w->_tooclose = true;
    return false;
  }
  return true;
}

class vertexFilter {
  RTree<volumePointWithExclusionRegion*,double,3,double> _rtree;
public: 
  void insert (Vertex * v) {
    volumePointWithExclusionRegion *sp = new volumePointWithExclusionRegion (v);
    double _min[3],_max[3];
    sp->minmax(_min,_max);
    _rtree.Insert (_min,_max,sp);
  }

  bool inExclusionZone  (volumePointWithExclusionRegion *p)
  {
    my_wrapper_3D w (p);
    double _min[3] = {p->_v->x()-1.e-8, p->_v->y()-1.e-8, p->_v->z()-1.e-8};
    double _max[3] = {p->_v->x()+1.e-8, p->_v->y()+1.e-8, p->_v->z()+1.e-8};
    _rtree.Search(_min,_max,rtree_callback,&w);
    return w._tooclose;
  }
};

void filterVertices (const int numThreads, 
		     vertexFilter &_filter,
		     std::vector<Vertex*> &S, 
		     std::vector<Vertex*> &add,
		     double (*f)(const SPoint3 &p, void *), 
		     void *data) {
  //  printf("before : %d points to add\n",add.size());

  std::vector<Vertex*> _add = add;  
  for (unsigned int i=0;i<S.size();i++){
    SPoint3 p (S[i]->x(),S[i]->y(),S[i]->z());
    double l = f (p, data);
    _filter.insert( S[i] );
  }
  add.clear();
  for (unsigned int i=0;i<_add.size();i++){
    SPoint3 p (_add[i]->x(),_add[i]->y(),_add[i]->z());
    volumePointWithExclusionRegion v (_add[i]);
    if (! _filter. inExclusionZone (&v)){
      _filter.insert( _add[i]);
      add.push_back(_add[i]);
    }
    else
      delete _add[i];
  }  
  //  printf("after filter : %d points to add\n",add.size());
}


double _fx (const SPoint3 &p, void *){
  return fabs(0.0125 + .02*p.x());
}


static void _print (const char *name, std::vector<Vertex*> &T){
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"\"{\n");
  for (unsigned int i=0;i<T.size();i++){
    fprintf(f,"SP(%g,%g,%g){%d};\n",
	    T[i]->x(),T[i]->y(),T[i]->z(),i);
  }
  fprintf(f,"};\n");
  fclose(f);
}

typedef std::set<conn>   connSet;

void computeAdjacencies (Tet *t, int iFace, connSet &faceToTet){
  conn c (t->getFace(iFace), iFace, t);
  connSet::iterator it = faceToTet.find(c);
  if (it == faceToTet.end()){
    faceToTet.insert(c);
  }
  else{
    t->T[iFace] = it->t;
    it->t->T[it->i] =t;
    faceToTet.erase(it);
  }
}


void edgeBasedRefinement (const int numThreads, 
			  const int nptsatonce, 
			  GRegion *gr) {

  // fill up old Datastructures

  std::vector<MTetrahedron*> T = gr->tetrahedra;
  std::vector<Tet*> _tets;
  _tets.resize(T.size());
  std::vector<Vertex *> _vertices;
  edgeContainer ec;

  {
    std::set<MVertex *> all;
    for (int i=0;i<T.size();i++){
      for (int j=0;j<4;j++){
	all.insert(T[i]->getVertex(j));
      }
    }

    _vertices.resize(all.size());
    int counter=0;
    for (std::set<MVertex*>::iterator it = all.begin();it !=all.end(); ++it){
      MVertex *mv = *it;
      mv->setIndex(counter);
      Vertex *v = new Vertex (mv->x(),mv->y(),mv->z(),1.e22, counter);
      _vertices[counter] = v;
      counter++;
    }
    connSet faceToTet;
    for (unsigned int i=0;i<T.size();i++){
      int i0 = T[i]->getVertex(0)->getIndex();
      int i1 = T[i]->getVertex(1)->getIndex();
      int i2 = T[i]->getVertex(2)->getIndex();
      int i3 = T[i]->getVertex(3)->getIndex();
      Tet *t = new Tet (_vertices[i0],_vertices[i1],_vertices[i2],_vertices[i3]);
      computeAdjacencies (t,0,faceToTet);
      computeAdjacencies (t,1,faceToTet);
      computeAdjacencies (t,2,faceToTet);
      computeAdjacencies (t,3,faceToTet);
      _tets[i] = t;
    }
  }

  // do not allow to saturate boundary edges
  {
    for (unsigned int i=0;i<_tets.size();i++) {
      for (int j=0;j<4;j++){
	if (!_tets[i]->T[j]){
	  Face f = _tets[i]->getFace(j);
	  for (int k=0;k<3;k++){
	    Vertex *vi = f.V[k];
	    Vertex *vj = f.V[(k+1)%3];
	    double l = sqrt ((vi->x()-vj->x())*(vi->x()-vj->x())+
			     (vi->y()-vj->y())*(vi->y()-vj->y())+
			     (vi->z()-vj->z())*(vi->z()-vj->z()));
	    ec.addNewEdge(Edge(vi,vj));
	    vi->lc() = std::min (l,vi->lc() );
	    vj->lc() = std::min (l,vj->lc() );
	  }
	}
      }
    }
    for (unsigned int i=0;i<_tets.size();i++) {
      for (int j=0;j<6;j++){
	Edge e = _tets[i]->getEdge(j);
	if(e.first->lc() == 1.e22){printf("coucou\n");e.first->lc() = e.second->lc();}
	else if(e.second->lc() == 1.e22){printf("coucou\n");e.second->lc() = e.first->lc();}
      }
    }
  }

  {
    vertexFilter _filter;
    int iter = 1;

    Msg::Info("----------------------------------- SATUR FILTR SORTH DELNY TIME  TETS");

    clock_t __t__ = clock();
    while(1){
      char name[256];
      //      sprintf(name,"beforeRefinement%d.pos",iter);
      //      print (name,_tets);
      //      printf("ITER %3d\n",iter);
      std::vector<Vertex*> add;
      clock_t t1 = clock();
      saturateEdges (ec, _tets, numThreads, add, _fx, NULL);
      //      printf("%d points to add\n",add.size());
      //sprintf(name,"Points%d.pos",iter);
      //     _print (name,add);
      clock_t t2 = clock();
      filterVertices (numThreads, _filter, _vertices, add, _fx, NULL);
      clock_t t3 = clock();
      if (add.empty())break;
      std::vector<int> indices;
      SortHilbert(add, indices);
      clock_t t4 = clock();
      //      sprintf(name,"PointsFiltered%d.pos",iter);
      //      _print (name,add);
      delaunayTrgl (1,1,add.size(), _tets, &add);  
      clock_t t5 = clock();
      Msg::Info("IT %3d %6d points added, timings %5.2f %5.2f %5.2f %5.2f %5.2f %5d",iter,add.size(),
		(float)(t2-t1)/CLOCKS_PER_SEC,
		(float)(t3-t2)/CLOCKS_PER_SEC,
		(float)(t4-t3)/CLOCKS_PER_SEC,
		(float)(t5-t4)/CLOCKS_PER_SEC,
		(float)(t5-__t__)/CLOCKS_PER_SEC,
		_tets.size());
      iter++;
    }
    print ("afterRefinement.pos",_tets);
  }
}


