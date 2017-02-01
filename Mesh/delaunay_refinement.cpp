// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
#include "MLine.h"
#include "Context.h"
#include "SBoundingBox3d.h"
#include "GModel.h"
#include "Field.h"

#define SQR(X) (X)*(X)
const double EXCLUSION_FACTOR = 0.8;

struct IPT {
  double _x1,_x2,_x3,_x4, _x5;
  IPT(double x1, double x2, double x3, double x4)
    : _x1(x1), _x2(x2), _x3(x3), _x4(x4),_x5(0.0)
  {
  };
};

////int C_COUNT = 0;

//double _C1, _C2, _C3, _C4;
static double GMSHSIZE (const SPoint3 &p, Field *f, double lc_nodal) {
  double f_field = 1.e22;
  if (!CTX::instance()->mesh.lcExtendFromBoundary) lc_nodal = 1.e22;
  //  double _a = Cpu();
  if (f)f_field = (*f)(p.x(), p.y(), p.z());
  //  _C3 += Cpu() - _a;  

  double lc = std::min (lc_nodal,f_field);
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);
  //  C_COUNT++;
  return lc;
}


double adaptiveTrapezoidalRule(SPoint3 p1 , SPoint3 p2 ,
                               double lc1 , double lc2 ,
                               std::vector< IPT > & _result,
                               double &dl, std::stack<IPT> &_stack,
			       Field *bgm,
                               double epsilon = 5.e-2)
{
  //  _stack.clear();
  _result.clear();
  // local parameters on the edge
  double t1 = 0.0;
  double t2 = 1.0;
  // edge vector
  SPoint3 dp = p2-p1;

  // value of f on both sides
  double f1 = lc1;//GMSHSIZE(p1, bgm, lc1); //f(p1 + dp*t1,data);
  double f2 = lc2;//GMSHSIZE(p2, bgm, lc2); //f(p1 + dp*t2,data);  
  
  dl = p1.distance(p2);

  //     adim_lenght of half the edge should be bigger than EXCLUSION_FACTOR
  // +------x--------+
  
  if (dl / (2*std::min(lc1,lc2))  <= EXCLUSION_FACTOR){
    //    printf ("edge length %g lc %g %g\n",dl,f1,f2);
    return EXCLUSION_FACTOR;
  }

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
    const double t12 = 0.5* (t1+t2);
    const SPoint3 pmid = p1 + dp*t12;
    const double dt = t2-t1;
    // average should be compared to mid value
    //    double f12 = 0.5* (f1+f2);
    double f12 = GMSHSIZE(pmid, bgm, lc1 + t12 *(lc2-lc1) ); //f(p1 + dp*t2,data);
    const double AA = dt * dl;
    const double I1 = AA / f12;
    const double I2 = 2 * AA / (f1+f2);

    if (fabs (I1 - I2) > epsilon) {
      IPT left  (t1,t12,f1,f12);
      IPT right (t12,t2,f12,f2);
      _stack.push(left);
      _stack.push(right);
    }
    else {
      // compute the integral using trapezoidal rule on both sides
      totalValue += 1./((0.5*f12+0.25*(f1+f2)))*dt;
      pp._x5 = totalValue*dl;
      _result.push_back (pp);
    }
  }
  // take into account the real length of the edge
  totalValue *= dl;
  //  printf("adimensional length %g %d evals\n",totalValue,_result.size() );
  return totalValue;
}


void saturateEdge(Edge &e, std::vector<Vert*> &S, std::stack<IPT> &temp)
{
  std::vector< IPT > _result;
  double dl;
  SPoint3 p1 = e.first->point();
  SPoint3 p2 = e.second->point();

  FieldManager *fields = GModel::current()->getFields();
  Field *bgm = NULL;
  if(fields->getBackgroundField() > 0){
    bgm = fields->get(fields->getBackgroundField());
  }  

  if (1){
    const double length = p1.distance(p2);
    const double lc_avg = (e.first->lc() + e.second->lc())*.5;
    const double l_adim_approx =   length / lc_avg;
    if (l_adim_approx > 10.){
      SPoint3 pmid = (p1+p2)*0.5;
      const double lc = GMSHSIZE(pmid, bgm, lc_avg);
      S.push_back(new Vert(pmid.x(),pmid.y(),pmid.z(),lc));
      return;
    }
  }
  
  //  double _a = Cpu();
  
  const double dN = adaptiveTrapezoidalRule(p1,p2,e.first->lc(), e.second->lc(),
                                            _result, dl, temp, bgm);
  //  _C1 += Cpu() - _a;  
  //  _a = Cpu();

  const int N = (int) (dN+0.1);
  const double interval = dN/N;
  double L = 0.0;

  // printf("edge length %g %d intervals of size %g (%d results)\n",
  //        dl,N,interval,_result.size());
  const unsigned int Nr = _result.size();
  double _f = interval;
  for (unsigned int i=0; i< Nr ; i++) {
    const IPT & rr = _result[i];
    const double t1 = rr._x1;
    const double t2 = rr._x2;
    const double f1 = rr._x3;
    const double f2 = rr._x4;
    const double l1 = rr._x3;
    const double l2 = rr._x4;
    const double dL = 2.*(t2-t1) * dl / (f1+f2);

    const double _f1 = i ? _result[i-1]._x5 : 0.0;
    const double _f2 = rr._x5;

    // printf("%g --> %g for %g --> %g\n",L,dL,t1,t2);
    while (1) {
      const double  t = t1 + (L+interval-_f1)*(t2-t1) / dL;
      if (t >=  t2*.999) {
	break;
      }
      else {
	// printf("%g ",t);
	SPoint3 p = p1 * (1.-t) + p2*t;
	const double lc = l1 + (_f-_f1)*(l2-l1) / (_f2-_f1);
        const double dx = 0;//lc * 1.e-12 * (double) rand() / RAND_MAX;
        const double dy = 0;//lc * 1.e-12 * (double) rand() / RAND_MAX;
        const double dz = 0;//lc * 1.e-12 * (double) rand() / RAND_MAX;
	S.push_back(new Vert(p.x()+dx,p.y()+dy,p.z()+dz,lc));
	L += interval;
        _f += interval;
      }
    }
  }
  //  _C2 += Cpu() - _a;  
  //  printf(" press enter\n");
  //  getchar();
  //  printf("%d points added\n",S.size());

  //  exit(1);
}

void saturateEdges(edgeContainer &ec,
                   tetContainer &T,
                   int nbThreads,
                   std::vector<Vert*> &S)
{
  //  _C1 = 0;
  //  _C2 = 0;
  std::stack<IPT> temp;
  // FIXME
  const int N = T.size(0);
  for (int i=0;i<N;i++){
    Tet *t = T(0,i);
   if (t->V[0] && t->_modified){
      t->_modified = false;
      for (int iEdge=0;iEdge<6;iEdge++){
	Edge ed = t->getEdge(iEdge);
	bool isNew = ec.addNewEdge(ed);
	if (isNew){
	  //	  saturateEdge_A_LA_FACON_PaulLouis(ed, S);
	  saturateEdge (ed, S, temp);
	}
      }
    }
  }
  //  printf("timings %12.5E  %12.5E\n",_C1,_C2);
}

// F I L T E R I N G


class volumePointWithExclusionRegion {
public :
  Vert *_v;
  volumePointWithExclusionRegion (Vert *v) : _v(v) {}

  inline bool inExclusionZone (volumePointWithExclusionRegion *p) const
  {
    const double K = EXCLUSION_FACTOR*p->_v->lc();
    const double d =
      SQR(p->_v->x() - _v->x())+
      SQR(p->_v->y() - _v->y())+
      SQR(p->_v->z() - _v->z());
    //    printf(" %g %g\n",p-//>_v->lc(),d);
    return d < SQR(K);
  }
  void minmax (double _min[3], double _max[3]) const
  {
    _min[0] = _v->x() - _v->lc();
    _min[1] = _v->y() - _v->lc();
    _min[2] = _v->z() - _v->lc();
    _max[0] = _v->x() + _v->lc();
    _max[1] = _v->y() + _v->lc();
    _max[2] = _v->z() + _v->lc();
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
  void insert (Vert * v) {
    volumePointWithExclusionRegion *sp = new volumePointWithExclusionRegion (v);
    double _min[3],_max[3];
    sp->minmax(_min,_max);
    _rtree.Insert (_min,_max,sp);
  }

  bool inExclusionZone  (volumePointWithExclusionRegion *p)
  {
    my_wrapper_3D w (p);
    double _min[3] = {p->_v->x()-1.e-8, p->_v->y()-1.e-8, p->_v->z()-1.e-8};
    //    double _max[3] = {p->_v->x()+1.e-8, p->_v->y()+1.e-8, p->_v->z()+1.e-8};
    _rtree.Search(_min,_min,rtree_callback,&w);
    return w._tooclose;
  }
};

void filterVertices(const int numThreads,
                    vertexFilter &_filter,
                    std::vector<Vert*> &add)
{
  std::vector<int> indices;
  SortHilbert(add, indices);
  std::vector<Vert*> _add=add;

  // std::vector<Vert*> _add;
  // Vert *current = add[0];
  // printf("before %d\n",add.size());
  // for (unsigned int i=1;i<add.size();i++){
  //   const double d = sqrt (SQR(add[i]->x()-current->x())  +
  // 			   SQR(add[i]->y()-current->y())  +
  // 			   SQR(add[i]->z()-current->z())  );
  //   if (0.8*current->lc() > d){
  //     delete add[i];
  //   }
  //   else {
  //     current = add[i];
  //     _add.push_back(add[i]);
  //   }
  // }
  //  printf("after %d\n",_add.size());

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
}

/*
static void _print (const char *name, std::vector<Vert*> &T)
{
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"\"{\n");
  for (unsigned int i=0;i<T.size();i++){
    fprintf(f,"SP(%g,%g,%g){%d};\n",
	    T[i]->x(),T[i]->y(),T[i]->z(),i);
  }
  fprintf(f,"};\n");
  fclose(f);
}
*/

typedef std::set<conn>   connSet;

void computeAdjacencies (Tet *t, int iFace, connSet &faceToTet)
{
  conn c (t->getFace(iFace), iFace, t);
  connSet::iterator it = faceToTet.find(c);
  if (it == faceToTet.end()){
    faceToTet.insert(c);
  }
  else{
    t->T[iFace] = it->t;
    it->t->T[it->i] =t;
    //    faceToTet.erase(it);
  }
}

bool edgeSwaps(tetContainer &T, int myThread)
{
  // TODO
  return false;
}

void updateSize (MVertex *v, std::map<MVertex*, double> &s, double d){
  d = std::max(d,  CTX::instance()->mesh.lcMin);
  d = std::min(d,  CTX::instance()->mesh.lcMax);
  std::map<MVertex*, double>::iterator it = s.find(v);
  if (it == s.end())s[v]=d;
  else it->second = std::min(it->second, d);
}

void createEmbeddedEdges (GRegion *gr,
			  edgeContainer &embedded,
			  std::vector<Vert *> &_vertices){
  std::list<GEdge*> e = gr->embeddedEdges();
  for (std::list<GEdge*>::iterator it = e.begin() ; it != e.end(); ++it){
    for (unsigned int i = 0; i < (*it)->lines.size(); i++){
      Vert *v0 = _vertices[(*it)->lines[i]->getVertex(0)->getIndex()];
      Vert *v1 = _vertices[(*it)->lines[i]->getVertex(1)->getIndex()];
      Edge e (v0,v1);
      embedded.addNewEdge(e);
    }
  }
}


void disconnectEmbeddedFaces (GRegion *gr, connSet &faceToTet, std::vector<Vert *> &_vertices){
  std::list<GFace*> f = gr->embeddedFaces();
  for (std::list<GFace*>::iterator it = f.begin() ; it != f.end(); ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
      bool ok1 = false;
      bool ok2 = false;
      Vert *v0 = _vertices[(*it)->triangles[i]->getVertex(0)->getIndex()];
      Vert *v1 = _vertices[(*it)->triangles[i]->getVertex(1)->getIndex()];
      Vert *v2 = _vertices[(*it)->triangles[i]->getVertex(2)->getIndex()];
      Face f (v0,v1,v2);
      conn c(f,0,NULL);
      connSet::iterator itf = faceToTet.find(c);
      if (itf != faceToTet.end()){
	Tet *t1 = itf->t;
	Tet *t2 = itf->t->T[itf->i];
	//	if (!(f == t1->getFace(itf->i)))printf("aie\n");
	for (int k=0;k<4;k++){	  
	  if (t1 && t1->T[k] == t2){t1->T[k]=NULL;ok1=true;}
	  if (t2 && t2->T[k] == t1){t2->T[k]=NULL;ok2=true;}
	}
	if (!ok1 || !ok2)printf("oops %d %d %p %p\n",ok1,ok2,t1,t2);
      }
      else printf("oops2\n");
    }
  }
}

void computeMeshSizes (GRegion *gr, std::map<MVertex*, double> &s){
  std::list<GEdge*> e = gr->embeddedEdges();
  for (std::list<GEdge*>::iterator it = e.begin() ; it != e.end(); ++it){
    for (unsigned int i = 0; i < (*it)->lines.size(); i++){
      double d = distance((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1));
      updateSize ((*it)->lines[i]->getVertex(0), s, d);      
      updateSize ((*it)->lines[i]->getVertex(1), s, d);      
    }
  }
  std::list<GFace*> f ;
  std::list<GFace*> f1 = gr->faces();
  std::list<GFace*> f2 = gr->embeddedFaces();
  f.insert(f.end(),f1.begin(), f1.end());
  f.insert(f.end(),f2.begin(), f2.end());
  for (std::list<GFace*>::iterator it = f.begin() ; it != f.end(); ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
      for (unsigned int j = 0; j < 3; j++){
	double d = distance((*it)->triangles[i]->getVertex(j), (*it)->triangles[i]->getVertex((j+1)%3));
	updateSize ((*it)->triangles[i]->getVertex(j), s, d);
	updateSize ((*it)->triangles[i]->getVertex((j+1)%3), s, d);
      }
    }
  }    
}

void edgeBasedRefinement(const int numThreads,
                         const int nptsatonce,
                         GRegion *gr)
{
  // fill up old Datastructures

  edgeContainer embeddedEdges (10000);
  
  std::map<MVertex*, double> sizes;
  computeMeshSizes (gr, sizes);  
  
  tetContainer allocator (numThreads,1000000);

  SBoundingBox3d bb;
  std::vector<Vert *> _vertices;
  edgeContainer ec;
  std::map<Vert*,MVertex*> _ma;

  {
    std::vector<MTetrahedron*> &T = gr->tetrahedra;
    std::set<MVertex *> all;
    for (unsigned int i=0;i<T.size();i++){
      for (unsigned int j=0;j<4;j++){
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
      double size = CTX::instance()->mesh.lcMax;
      std::map<MVertex*,double>::iterator itv = sizes.find(mv);
      if (itv != sizes.end())size = itv->second;
      Vert *v = new Vert (mv->x(),mv->y(),mv->z(),size, counter);
      _vertices[counter] = v;
      bb += SPoint3(v->x(),v->y(),v->z());
      _ma[v] = mv;
      counter++;
    }
    bb *= 1.1;
    {
      connSet faceToTet;
      // FIXME MULTITHREADING
      for (unsigned int i=0;i<T.size();i++){
	MTetrahedron  *tt = T[i];
	int i0 = tt->getVertex(0)->getIndex();
	int i1 = tt->getVertex(1)->getIndex();
	int i2 = tt->getVertex(2)->getIndex();
	int i3 = tt->getVertex(3)->getIndex();
	Tet *t = allocator.newTet(0) ;
        t->setVertices(_vertices[i0],_vertices[i1],_vertices[i2],_vertices[i3]);
	computeAdjacencies (t,0,faceToTet);
	computeAdjacencies (t,1,faceToTet);
	computeAdjacencies (t,2,faceToTet);
	computeAdjacencies (t,3,faceToTet);
	delete tt;
      }
      T.clear();
      disconnectEmbeddedFaces (gr, faceToTet, _vertices);
      createEmbeddedEdges (gr, embeddedEdges, _vertices);
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
	    Vert *vi = f.V[k];
	    Vert *vj = f.V[(k+1)%3];
	    ec.addNewEdge(Edge(vi,vj));
	  }
	}
      }
    }
  }

  std::vector<Vert*> add_all;
  {
    //    vertexFilter _filter (bb, 20);
    vertexFilter _filter;
    for (unsigned int i=0;i<_vertices.size();i++){
      _filter.insert( _vertices[i] );
    }

    int iter = 1;
    Msg::Info("------------------------------------- SATUR FILTR SORTH DELNY TIME  TETS");

    double __t__ = Cpu();
    //    Tet::in_sphere_counter = 0;
    while(1){
      std::vector<Vert*> add;
      double t1 = Cpu();
      //      C_COUNT = 0;
      saturateEdges (ec, allocator, numThreads, add);
      //      printf("%d calls %d points added",C_COUNT,add.size());
      double t2 = Cpu();
      filterVertices (numThreads, _filter, add);
      //      printf(" %d points remain\n",add.size());
      double t3 = Cpu();
      if (add.empty())break;
      // randomize vertices (EXTREMELY IMPORTANT FOR NOT DETERIORATING PERFORMANCE)
      std::random_shuffle(add.begin(), add.end());
      // sort them using BRIO
      std::vector<int> indices;
      SortHilbert(add, indices);
      double t4 = Cpu();
      delaunayTrgl (1,1,add.size(), &add,allocator,embeddedEdges.empty() ? NULL : &embeddedEdges);
      double t5 = Cpu();
      add_all.insert (add_all.end(), add.begin(), add.end());
      Msg::Info("IT %3d %8d points added, timings %5.2f %5.2f %5.2f %5.2f %5.2f %5d",
                iter,add.size(),
		(t2-t1),
		(t3-t2),
		(t4-t3),
		(t5-t4),
		(t5-__t__),
		allocator.size(0));
      iter++;
    }
  }



  for (unsigned int i=0; i< allocator.size(0);i++){
    Tet  *tt = allocator (0,i);
    MVertex *mvs[4];
    if (tt->V[0]){
      for (int j=0;j<4;j++){
	Vert *v = tt->V[j];
	std::map<Vert*,MVertex*>::iterator it = _ma.find(v);
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
    Msg::Info("MESH EFFICIENCY : %22.15E %6d edges among %d are out of range",
              exp (sum / _sizes.size()),nbBad,_sizes.size());
  }
}
