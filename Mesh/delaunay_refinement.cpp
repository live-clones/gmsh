#ifdef _OPENMP
#include <omp.h>
#endif
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include "GmshMessage.h"
#include "OS.h"
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
	const double dx = 1.e-12 * (double) rand() / RAND_MAX;
	const double dy = 1.e-12 * (double) rand() / RAND_MAX;
	const double dz = 1.e-12 * (double) rand() / RAND_MAX;
	S.push_back(new Vertex(p.x()+dx,p.y()+dy,p.z()+dz,lc));
	L += interval;
      }
    }
  }

  //  printf("%d points added\n",S.size());

  //  exit(1);
}

void saturateEdges ( edgeContainer &ec,
		     tetContainer &T,
		     int nbThreads,
		     std::vector<Vertex*> &S,
		     double (*f)(const SPoint3 &p, void *), void *data) {
  AVGSEARCH= 0;
  int counter = 0;
  // FIXME
  for (int i=0;i<T.size(0);i++){
    Tet *t = T(0,i);
    if (t->V[0] && t->_modified){
      t->_modified = false;
      for (int iEdge=0;iEdge<6;iEdge++){
	Edge ed = t->getEdge(iEdge);
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
    return d < .8*p->_v->lc();//_l;
  }
  void minmax (double _min[3], double _max[3]) const
  {
    _min[0] = _v->x() - 1.01*_v->lc();
    _min[1] = _v->y() - 1.01*_v->lc();
    _min[2] = _v->z() - 1.01*_v->lc();
    _max[0] = _v->x() + 1.01*_v->lc();
    _max[1] = _v->y() + 1.01*_v->lc();
    _max[2] = _v->z() + 1.01*_v->lc();
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

  tetContainer allocator (numThreads,1000000);

  std::vector<Vertex *> _vertices;
  edgeContainer ec;
  std::map<Vertex*,MVertex*> _ma;

  {
    std::vector<MTetrahedron*> &T = gr->tetrahedra;
    std::set<MVertex *> all;
    for (int i=0;i<T.size();i++){
      for (int j=0;j<4;j++){
	all.insert(T[i]->getVertex(j));
      }
    }


    //    FILE *f = fopen ("pts_init.dat","w");
    //    fprintf(f,"%d\n",all.size());
    //    for (std::set<MVertex*>::iterator it = all.begin();it !=all.end(); ++it){
    //      MVertex *mv = *it;      
    //      fprintf(f,"%12.5E %12.5E %12.5E\n",mv->x(),mv->y(),mv->z());
    //    }
    //    fclose(f);


    _vertices.resize(all.size());
    int counter=0;
    for (std::set<MVertex*>::iterator it = all.begin();it !=all.end(); ++it){
      MVertex *mv = *it;
      mv->setIndex(counter);
      Vertex *v = new Vertex (mv->x(),mv->y(),mv->z(),1.e22, counter);
      _vertices[counter] = v;
      _ma[v] = mv;
      counter++;
    }

    {
      connSet faceToTet;
      // FIXME MULTITHREADING
      for (unsigned int i=0;i<T.size();i++){
	MTetrahedron  *tt = T[i];
	int i0 = tt->getVertex(0)->getIndex();
	int i1 = tt->getVertex(1)->getIndex();
	int i2 = tt->getVertex(2)->getIndex();
	int i3 = tt->getVertex(3)->getIndex();
	Tet *t = allocator.newTet(0) ; t->setVertices (_vertices[i0],_vertices[i1],_vertices[i2],_vertices[i3]);
	computeAdjacencies (t,0,faceToTet);
	computeAdjacencies (t,1,faceToTet);
	computeAdjacencies (t,2,faceToTet);
	computeAdjacencies (t,3,faceToTet);
	delete tt;
      }
      T.clear();
    }
  }

  // do not allow to saturate boundary edges
  {
    for (unsigned int i=0;i< allocator.size(0);i++) {
      Tet  *tt = allocator (0,i);
      for (int j=0;j<4;j++){
	if (!tt->T[j]){
	  Face f = tt->getFace(j);
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
    for (unsigned int i=0;i< allocator.size(0);i++) {
      Tet  *tt = allocator (0,i);
      for (int j=0;j<6;j++){
	Edge e = tt->getEdge(j);
	if(e.first->lc() == 1.e22){/*printf("coucou\n");*/e.first->lc() = e.second->lc();}
	else if(e.second->lc() == 1.e22){/*printf("coucou\n");*/e.second->lc() = e.first->lc();}
      }
    }
  }

  std::vector<Vertex*> add_all;
  {
    vertexFilter _filter;
    int iter = 1;

    Msg::Info("----------------------------------- SATUR FILTR SORTH DELNY TIME  TETS");

    double __t__ = Cpu();
    Tet::in_sphere_counter = 0;
    while(1){
      std::vector<Vertex*> add;
      double t1 = Cpu();
      saturateEdges (ec, allocator, numThreads, add, _fx, NULL);
      double t2 = Cpu();
      filterVertices (numThreads, _filter, _vertices, add, _fx, NULL);
      double t3 = Cpu();
      if (add.empty())break;
      // randomize vertices (EXTREMELY IMPORTANT FOR NOT DETERIORATING PERFORMANCE)
      std::random_shuffle(add.begin(), add.end());
      // sort them using BRIO
      std::vector<int> indices;
      SortHilbert(add, indices);
      double t4 = Cpu();
      delaunayTrgl (1,1,add.size(), &add,allocator);  
      double t5 = Cpu();
      add_all.insert (add_all.end(), add.begin(), add.end());
      //      if (iter == 1){
      //	FILE *f = fopen ("pts.dat","w");
      //	fprintf(f,"%d\n",add.size());
      //	for (unsigned int i=0;i<add.size();i++){
      //	  fprintf(f,"%12.5E %12.5E %12.5E\n",add[i]->x(),add[i]->y(),add[i]->z());
      //	}
      //	fclose(f);
      //      }
      Msg::Info("IT %3d %6d points added, timings %5.2f %5.2f %5.2f %5.2f %5.2f %5d",iter,add.size(),
		(t2-t1),
		(t3-t2),
		(t4-t3),
		(t5-t4),
		(t5-__t__),
		allocator.size(0));
      //      printf("%d calls to inSphere\n",Tet::in_sphere_counter);
      iter++;
    }
  }



  for (unsigned int i=0; i< allocator.size(0);i++){
    Tet  *tt = allocator (0,i);
    MVertex *mvs[4];
    if (tt->V[0]){      
      for (int j=0;j<4;j++){
	Vertex *v = tt->V[j];
	std::map<Vertex*,MVertex*>::iterator it = _ma.find(v);
	if (it == _ma.end()){
	  MVertex *mv = new MVertex (v->x(),v->y(),v->z(),gr);
	  gr->mesh_vertices.push_back(mv);
	  _ma[v] = mv;
	  mvs[j] = mv;
	}
	else mvs[j] = it->second;
      }
      gr->tetrahedra.push_back(new MTetrahedron(mvs[0],mvs[1],mvs[2],mvs[3]));
    }
  }

  if (Msg::GetVerbosity() == 99) {
    std::map<Edge,double> _sizes;
    for (unsigned int i=0; i< allocator.size(0);i++){
      Tet  *tt = allocator (0,i);
      if (tt->V[0]){      
	for (int j=0;j<6;j++){
	  Edge e =  tt->getEdge(j);
	  std::map<Edge,double>::iterator it = _sizes.find(e);
	  if (it == _sizes.end()){
	    double l = sqrt ((e.first->x() -  e.second->x()) * (e.first->x() -  e.second->x()) +
			     (e.first->y() -  e.second->y()) * (e.first->y() -  e.second->y()) +
			     (e.first->z() -  e.second->z()) * (e.first->z() -  e.second->z()));
	    _sizes[e]= 2* l / (e.first->lc() + e.second->lc());
	  }
	}
      }
    }
    std::map<Edge,double>::iterator it = _sizes.begin();
    double sum = 0;
    int nbBad = 0;
    for (; it !=_sizes.end();++it){
      double d = it->second;
      double tau = d < 1 ? d - 1 : 1./d - 1;
      if (d > 2.)nbBad++;
      sum += tau;
    }
    Msg::Info("MESH EFFICIENCY : %22.15E %6d edges among %d are out of range",exp (sum / _sizes.size()),nbBad,_sizes.size());
  }
}
