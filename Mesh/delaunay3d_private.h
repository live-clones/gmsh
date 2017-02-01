// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DELAUNAY3D_PRIVATE_H_
#define _DELAUNAY3D_PRIVATE_H_

#include <vector>
#include "SPoint3.h"
#include <math.h>
#include "robustPredicates.h"
#include <stdio.h>
#if defined(_OPENMP)
#include <omp.h>
#endif

#ifndef MAX_NUM_THREADS_
#define MAX_NUM_THREADS_ 1
#endif

typedef unsigned char CHECKTYPE;

struct Vert {
private :
  double _x[3];
  double _lc;
  unsigned int _num;
public :
  inline unsigned int getNum () const {return _num;}
  inline void setNum (unsigned int n)  {_num=n;}
  unsigned char _thread;
  inline double x() const {return _x[0];}
  inline double y() const {return _x[1];}
  inline double z() const {return _x[2];}
  inline double lc() const {return _lc;}
  inline double &x() {return _x[0];}
  inline double &y() {return _x[1];}
  inline double &z() {return _x[2];}
  inline double &lc() {return _lc;}
  inline operator double *() { return _x; }
  Vert (double X=0, double Y=0, double Z=0, double lc=0, int num = 0)
    : _num(num), _thread(0)
  {
    _x[0] = X; _x[1] = Y; _x[2] = Z; _lc = lc;
  }
  Vert operator + (const Vert &other)
  {
    return Vert (x()+other.x(),y()+other.y(),z()+other.z(),other.lc() + _lc);
  }
  Vert operator * (const double &other)
  {
    return Vert(x()*other, y()*other, z()*other, _lc*other);
  }
  inline SPoint3 point() const { return SPoint3(x(), y(), z()); }
};

inline double orientationTestFast(double *pa, double *pb, double *pc, double *pd)
{
  const double adx = pa[0] - pd[0];
  const double bdx = pb[0] - pd[0];
  const double cdx = pc[0] - pd[0];
  const double ady = pa[1] - pd[1];
  const double bdy = pb[1] - pd[1];
  const double cdy = pc[1] - pd[1];
  const double adz = pa[2] - pd[2];
  const double bdz = pb[2] - pd[2];
  const double cdz = pc[2] - pd[2];

  return adx * (bdy * cdz - bdz * cdy)
       + bdx * (cdy * adz - cdz * ady)
       + cdx * (ady * bdz - adz * bdy);
}

inline bool inSphereTest_s (Vert *va, Vert *vb, Vert *vc, Vert *vd , Vert *ve)
{
  double val = robustPredicates::insphere((double*)va, (double*)vb, (double*)vc,
                                          (double*)vd, (double*)ve);
  if (val == 0.0){
    Msg::Info("symbolic perturbation needed vol %22.15E",
              orientationTestFast((double*)va, (double*)vb, (double*)vc, (double*)vd));
    int count;
    // symbolic perturbation
    Vert *pt[5] = {va,vb,vc,vd,ve};
    int swaps = 0;
    int n = 5;
    do {
      count = 0;
      n = n - 1;
      for (int i = 0; i < n; i++) {
	if (pt[i] > pt[i+1]) {
	  Vert *swappt = pt[i]; pt[i] = pt[i+1]; pt[i+1] = swappt;
	  count++;
	}
      }
      swaps += count;
    } while (count > 0);
    double oriA = robustPredicates::orient3d((double*)pt[1], (double*)pt[2],
                                             (double*)pt[3], (double*)pt[4]);
    if (oriA != 0.0) {
      // Flip the sign if there are odd number of swaps.
      if ((swaps % 2) != 0) oriA = -oriA;
      val =  oriA;
    }
    else {
      double oriB = -robustPredicates::orient3d((double*)pt[0], (double*)pt[2],
                                                (double*)pt[3], (double*)pt[4]);
      if (oriB == 0.0) {
	Msg::Fatal("Symbolic perturbation failed in icCircle Predicate");
      }
      // Flip the sign if there are odd number of swaps.
      if ((swaps % 2) != 0) oriB = -oriB;
      val = oriB;
    }
  }
  return val > 0 ? 1 : 0;
}

inline double orientationTest (Vert *va, Vert *vb, Vert *vc, Vert *vd)
{
  return robustPredicates::orient3d ((double*)va,(double*)vb,(double*)vc,(double*)vd);
}

inline double orientationTestFast (Vert *va, Vert *vb, Vert *vc, Vert *vd)
{
  return orientationTestFast ((double*)va,(double*)vb,(double*)vc,(double*)vd);
}

class Edge {
public :
  Vert *first, *second;
  Edge (Vert *v1, Vert *v2) : first(std::min(v1,v2)), second(std::max(v1,v2))
  {
  }
  bool operator == (const Edge &e) const{
    return e.first == first && e.second == second;
  }
  bool operator < (const Edge &e) const{
    if (first < e.first) return true;
    if (first > e.first) return false;
    if (second < e.second) return true;
    return false;
  }
};

struct edgeContainer
{
  std::vector<std::vector<Edge> > _hash;
  size_t _size;
  edgeContainer(unsigned int N = 1000000)
  {
    _size = 0;
    _hash.resize(N);
  }

  inline bool find (const Edge &e) const {
    size_t h = ((size_t) e.first >> 8) ;
    const std::vector<Edge> &v = _hash[h %_hash.size()];
    for (unsigned int i=0; i< v.size();i++)if (e == v[i]) {return true;}
    return false;
  }

  bool empty () const {return _size == 0;}
  
  bool addNewEdge (const Edge &e)
  {
    size_t h = ((size_t) e.first >> 8) ;
    std::vector<Edge> &v = _hash[h %_hash.size()];
    for (unsigned int i=0; i< v.size();i++)if (e == v[i]) {return false;}
    v.push_back(e);
    _size++;
    return true;
  }
};


struct Face {
  Vert *v[3];
  Vert *V[3];
  Face (Vert *v1, Vert *v2, Vert *v3)
  {
    V[0] = v[0] = v1;
    V[1] = v[1] = v2;
    V[2] = v[2] = v3;
#define cswap(a,b) do { if(a > b) { Vert* tmp = a; a = b; b = tmp; } } while(0)
    cswap(v[0], v[1]);
    cswap(v[1], v[2]);
    cswap(v[0], v[1]);
  }
  bool operator == (const Face &other) const
  {
    return v[0] == other.v[0] && v[1] == other.v[1] && v[2] == other.v[2];
  }
  bool operator < (const Face &other) const
  {
    if (v[0] < other.v[0])return true;
    if (v[0] > other.v[0])return false;
    if (v[1] < other.v[1])return true;
    if (v[1] > other.v[1])return false;
    if (v[2] < other.v[2])return true;
    return false;
  }
};

struct Tet {
  Tet  *T[4];
  Vert *V[4];
  CHECKTYPE _bitset[MAX_NUM_THREADS_];
  bool _modified;
  //  static int in_sphere_counter;
  Tet ()  : _modified(true){
    V[0] = V[1] = V[2] = V[3] = NULL;
    T[0] = T[1] = T[2] = T[3] = NULL;
    setAllDeleted();
  }
  //  inline bool isFace () const {return V[3]==NULL;}
  int setVerticesNoTest (Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    _modified=true;
    V[0] = v0; V[1] = v1; V[2] = v2; V[3] = v3;
    //    for (int i=0;i<4;i++)_copy[i] = *V[i];
    return 1;
  }
  int setVertices (Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    _modified=true;
    double val = robustPredicates::orient3d((double*)v0, (double*)v1,
                                            (double*)v2, (double*)v3);
    V[0] = v0; V[1] = v1; V[2] = v2; V[3] = v3;
    if (val > 0){
      // for (int i=0;i<4;i++)_copy[i] = *V[i];
      return 1;
    }
    else if (val < 0){
      // throw;
      V[0] = v1; V[1] = v0; V[2] = v2; V[3] = v3;
      // for (int i=0;i<4;i++)_copy[i] = *V[i];
      return -1;
    }
    else {
      // throw;
      return 0;
    }
  }
  Tet(Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    setVertices (v0,v1,v2,v3);
    T[0] = T[1] = T[2] = T[3] = NULL;
    setAllDeleted();
  }
  void setAllDeleted()
  {
    for (int i = 0; i < MAX_NUM_THREADS_; i++) _bitset [i] = 0x0;
  }
  inline void unset(int thread, int iPnt)
  {
    _bitset[thread] &= ~(1 << iPnt);
  }
  inline void set(int thread, int iPnt)
  {
    _bitset [thread] |= (1 << iPnt);
  }
  inline CHECKTYPE isSet(int thread, int iPnt) const
  {
    return _bitset[thread] & (1 << iPnt);
  }
  inline Face getFace(int k) const
  {
    const int fac[4][3] = {{0,1,2},{1,3,2},{2,3,0},{1,0,3}};
    return Face(V[fac[k][0]], V[fac[k][1]], V[fac[k][2]]);
  }
  inline Vert* getOppositeVertex(int k) const
  {
    const int o[4] = {3,0,1,2};
    return V[o[k]];
  }
  inline Edge getEdge (int k) const
  {
    const int edg[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
    return Edge(std::min(V[edg[k][0]], V[edg[k][1]]),
                std::max(V[edg[k][0]], V[edg[k][1]]));
  }
  inline bool inSphere (Vert *vd, int thread)
  {
    //    in_sphere_counter++;
    return inSphereTest_s(V[0], V[1], V[2], V[3], vd);
  }
};

struct conn {
  Face f;
  int  i;
  Tet *t;
  conn () : f(0,0,0), i(0), t(0){}
  conn (Face _f, int _i, Tet *_t) : f(_f), i(_i), t(_t)
  {
  }
  inline bool operator == (const conn & c) const
  {
    return f == c.f;
  }
  inline bool operator < (const conn & c) const
  {
    return f < c.f;
  }
};


// tetrahedra (one per thread)
template <class T> class aBunchOfStuff {
public:
  std::vector<T*> _all;
  unsigned int _current;
  unsigned int _nbAlloc;
  unsigned int size ()
  {
    return _current + (_all.size()-1) * _nbAlloc;
  }
  inline T* operator () (unsigned int i)
  {
    const unsigned int _array = i / _nbAlloc;
    const unsigned int _offset = i % _nbAlloc;
    // printf("%d %d %d\n",i,_array,_offset);
    return _all [_array] + _offset;
  }
  aBunchOfStuff (unsigned int s) : _current(0), _nbAlloc (s)
  {
    _all.push_back(new T [_nbAlloc]);
  }
  ~aBunchOfStuff()
  {
    for (unsigned int i=0;i<_all.size();i++){
      delete [] _all[i];
    }
  }
  T* newStuff()
  {
    if (_current == _nbAlloc){
      _all.push_back(new T [_nbAlloc]);
      // printf("REALLOCATION %d\n",_all.size());
      _current = 0;
    }
    _current++;
    return _all[_all.size()-1]+(_current-1);
  }
};

// tetAllocator owns the tets that have been allocated by itself
class tetContainer {
  std::vector<aBunchOfStuff<Tet> *> _perThread;
 public:
  unsigned int size(int thread) const { return _perThread[thread]->size(); }
  inline Tet    * operator () (int thread, int j) const
  {
    return (*_perThread[thread])(j);
  }
  tetContainer (int nbThreads, int preallocSizePerThread)
  {
    // FIXME !!!
    if (nbThreads != 1) throw;
    _perThread.resize(nbThreads);
#if defined(_OPENMP)
#pragma omp parallel num_threads(nbThreads)
#endif
    {
#if defined(_OPENMP)
      int  myThread = omp_get_thread_num();
#else
      int  myThread = 0;
#endif
      _perThread [myThread] = new aBunchOfStuff<Tet>(preallocSizePerThread) ;
    }
  }
  inline Tet * newTet(int thread)
  {
    return _perThread[thread]->newStuff();
  }
  ~tetContainer()
  {
    delete _perThread [0];
  }
};

typedef std::vector<Tet*> cavityContainer;
typedef std::vector<conn> connContainer;

void SortHilbert(std::vector<Vert*>& v, std::vector<int> &indices);
void computeAdjacencies (Tet *t, int iFace, connContainer &faceToTet);
void __print(const char *name, int thread, tetContainer &T, Vert *v = 0);
void delaunayTrgl(const unsigned int numThreads,
                  const unsigned int NPTS_AT_ONCE,
                  unsigned int Npts,
                  std::vector<Vert*> assignTo[],
                  tetContainer &allocator, edgeContainer *embedded = 0);
bool edgeSwap(Tet *tet, int iLocalEdge,  tetContainer &T, int myThread);

#endif
