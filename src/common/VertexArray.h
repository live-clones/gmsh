// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <string.h>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include "SVector3.h"
#include "SBoundingBox3d.h"

#include "GmshConfig.h"
#if defined(HAVE_VISUDEV)
typedef float normal_type;
#else
typedef char normal_type;
#endif

class MElement;

template <int N> class ElementData {
private:
  float _x[N], _y[N], _z[N], _nx[N], _ny[N], _nz[N];
  unsigned char _r[N], _g[N], _b[N], _a[N];
  MElement *_ele;

public:
  ElementData(double *x, double *y, double *z, SVector3 *n, unsigned char *r,
              unsigned char *g, unsigned char *b, unsigned char *a,
              MElement *ele)
  {
    for(int i = 0; i < N; i++) {
      _x[i] = (float)x[i];
      _y[i] = (float)y[i];
      _z[i] = (float)z[i];
      if(n) {
        _nx[i] = (float)n[i].x();
        _ny[i] = (float)n[i].y();
        _nz[i] = (float)n[i].z();
      }
      else
        _nx[i] = _ny[i] = _nz[i] = 0.;
      if(r && g && b && a) {
        _r[i] = r[i];
        _g[i] = g[i];
        _b[i] = b[i];
        _a[i] = a[i];
      }
      else
        _r[i] = _g[i] = _b[i] = _a[i] = 0;
    }
    _ele = ele;
  }
  inline float x(int i) const { return _x[i]; }
  inline float y(int i) const { return _y[i]; }
  inline float z(int i) const { return _z[i]; }
  inline float nx(int i) const { return _nx[i]; }
  inline float ny(int i) const { return _ny[i]; }
  inline float nz(int i) const { return _nz[i]; }
  inline unsigned char r(int i) const { return _r[i]; }
  inline unsigned char g(int i) const { return _g[i]; }
  inline unsigned char b(int i) const { return _b[i]; }
  inline unsigned char a(int i) const { return _a[i]; }
  inline MElement *ele() const { return _ele; }
  SPoint3 barycenter() const
  {
    SPoint3 p(0., 0., 0.);
    for(int i = 0; i < N; i++) {
      p[0] += _x[i];
      p[1] += _y[i];
      p[2] += _z[i];
    }
    p[0] /= (double)N;
    p[1] /= (double)N;
    p[2] /= (double)N;
    return p;
  }
};

template <int N> class ElementDataLessThan {
public:
  static float tolerance;
  bool operator()(const ElementData<N> &e1, const ElementData<N> &e2) const
  {
    SPoint3 p1 = e1.barycenter();
    SPoint3 p2 = e2.barycenter();
    if(p1.x() - p2.x() > tolerance) return true;
    if(p1.x() - p2.x() < -tolerance) return false;
    if(p1.y() - p2.y() > tolerance) return true;
    if(p1.y() - p2.y() < -tolerance) return false;
    if(p1.z() - p2.z() > tolerance) return true;
    return false;
  }
};

// key used by the "unique" filter to detect elements that are drawn several
// times, e.g. an edge shared by several tetrahedra: the N corners are stored in
// canonical (sorted) order, together with the color, so that an element added
// twice with the same geometry and the same color is only kept once
template <int N> class CornerKey {
public:
  float p[3 * N];
  unsigned char c[4];
};

template <int N> class CornerKeyHash {
public:
  std::size_t operator()(const CornerKey<N> &k) const
  {
    const unsigned char *b = (const unsigned char *)&k;
    std::size_t h = 14695981039346656037ULL;
    for(std::size_t i = 0; i < sizeof(CornerKey<N>); i++) {
      h ^= b[i];
      h *= 1099511628211ULL;
    }
    return h;
  }
};

template <int N> class CornerKeyEqual {
public:
  bool operator()(const CornerKey<N> &a, const CornerKey<N> &b) const
  {
    return !memcmp(&a, &b, sizeof(CornerKey<N>));
  }
};

// filter used to detect elements that are drawn several times. The keys are
// spread over several shards, each with its own lock, so that the filter can be
// shared by the threads that fill the vertex arrays of a given entity.
class UniqueElementFilter {
private:
  enum { NUM_SHARDS = 256 };
  std::unordered_set<CornerKey<2>, CornerKeyHash<2>, CornerKeyEqual<2> >
    _s2[NUM_SHARDS];
  std::unordered_set<CornerKey<3>, CornerKeyHash<3>, CornerKeyEqual<3> >
    _s3[NUM_SHARDS];
  std::mutex _mutex[NUM_SHARDS];
  bool _threaded;

public:
  UniqueElementFilter(bool threaded) : _threaded(threaded) {}
  // switch on the locks: this must be called before the filter is shared, e.g.
  // when a first, small batch of elements has been treated serially
  void setThreaded() { _threaded = true; }
  // return true if an element with the same corners and the same color has
  // already been seen
  bool isDuplicate(int npe, double *x, double *y, double *z, unsigned char *r,
                   unsigned char *g, unsigned char *b, unsigned char *a);
};

class Barycenter {
private:
  float _x, _y, _z;

public:
  Barycenter(double x, double y, double z)
    : _x((float)x), _y((float)y), _z((float)z)
  {
  }
  inline float x() const { return _x; }
  inline float y() const { return _y; }
  inline float z() const { return _z; }
  void operator+=(const Barycenter &p)
  {
    _x += p.x();
    _y += p.y();
    _z += p.z();
  }
};

class BarycenterLessThan {
public:
  static float tolerance;
  bool operator()(const Barycenter &p1, const Barycenter &p2) const
  {
    if(p1.x() - p2.x() > tolerance) return true;
    if(p1.x() - p2.x() < -tolerance) return false;
    if(p1.y() - p2.y() > tolerance) return true;
    if(p1.y() - p2.y() < -tolerance) return false;
    if(p1.z() - p2.z() > tolerance) return true;
    return false;
  }
};

class BarycenterHash {
public:
  std::size_t operator()(const Barycenter &b) const
  {
    return (std::size_t)(b.x() + b.y() + b.z());
  }
};

class BarycenterEqual {
public:
  bool operator()(const Barycenter &a, const Barycenter &b) const
  {
    return (fabs(a.x() - b.x()) < BarycenterLessThan::tolerance &&
            fabs(a.y() - b.y()) < BarycenterLessThan::tolerance &&
            fabs(a.z() - b.z()) < BarycenterLessThan::tolerance);
  }
};

//#include <tr1/unordered_set>

class VertexArray {
private:
  int _numVerticesPerElement;
  std::vector<float> _vertices;
  std::vector<normal_type> _normals;
  std::vector<unsigned char> _colors;
  std::vector<MElement *> _elements;
  // optional index array: when non-empty, the vertex/normal/color arrays hold
  // unique vertices only, and _indices lists the vertices of each drawn corner
  std::vector<unsigned int> _indices;
  std::set<ElementData<3>, ElementDataLessThan<3> > _data3;
  // elements already added, when the "unique" filter is on: the filter can be
  // shared with other vertex arrays, in which case it is not owned
  UniqueElementFilter *_filter;
  bool _ownsFilter;
  long int _statUniqueIn, _statUniqueKept;
  std::set<Barycenter, BarycenterLessThan> _barycenters;
  // std::tr1::unordered_set<Barycenter, BarycenterHash, BarycenterEqual>
  // _barycenters;

  // add stuff in the arrays
  void _addVertex(float x, float y, float z);
  void _addNormal(float nx, float ny, float nz);
  void _addColor(unsigned char r, unsigned char g, unsigned char b,
                 unsigned char a);
  void _addElement(MElement *ele);
  // build (resp. undo) the index array by merging identical vertices
  void _buildIndex();
  void _deindex();

public:
  VertexArray(int numVerticesPerElement, int numElements);
  ~VertexArray();
  // return the filter used to drop elements that are drawn several times,
  // creating it if necessary
  UniqueElementFilter *getUniqueFilter(bool threaded);
  // use a filter owned by somebody else
  void setUniqueFilter(UniqueElementFilter *f);
  // return the number of vertices in the array
  int getNumVertices() { return (int)_vertices.size() / 3; }
  // return the number of vertices per element
  int getNumVerticesPerElement() { return _numVerticesPerElement; }
  // return true if the array is indexed
  bool isIndexed() { return !_indices.empty(); }
  // return the number of drawn corners: this is the number of indices if the
  // array is indexed, and the number of vertices otherwise
  int getNumCorners()
  {
    return isIndexed() ? (int)_indices.size() : getNumVertices();
  }
  // return the position, in the vertex arrays, of the i-th drawn corner
  int getCornerIndex(int i) { return isIndexed() ? (int)_indices[i] : i; }
  // return the number of indices, and a pointer to the raw index array
  int getNumIndices() { return (int)_indices.size(); }
  unsigned int *getIndexArray(int i = 0) { return &_indices[i]; }
  // return the number of element pointers
  int getNumElementPointers() { return (int)_elements.size(); }
  // return a pointer to the raw vertex array (warning: 1) we don't
  // range check 2) calling this if _vertices.size() == 0 will cause
  // some compilers to throw an exception)
  float *getVertexArray(int i = 0) { return &_vertices[i]; }
  std::vector<float>::iterator firstVertex() { return _vertices.begin(); }
  std::vector<float>::iterator lastVertex() { return _vertices.end(); }

  // return true if the array stores normals
  bool hasNormals() { return (int)_normals.size() == 3 * getNumVertices(); }
  // return a pointer to the raw normal array
  normal_type *getNormalArray(int i = 0) { return &_normals[i]; }
  std::vector<normal_type>::iterator firstNormal() { return _normals.begin(); }
  std::vector<normal_type>::iterator lastNormal() { return _normals.end(); }

  // return a pointer to the raw color array
  unsigned char *getColorArray(int i = 0) { return &_colors[i]; }
  std::vector<unsigned char>::iterator firstColor() { return _colors.begin(); }
  std::vector<unsigned char>::iterator lastColor() { return _colors.end(); }

  // return a pointer to the raw element array
  MElement **getElementPointerArray(int i = 0) { return &_elements[i]; }
  std::vector<MElement *>::iterator firstElementPointer()
  {
    return _elements.begin();
  }
  std::vector<MElement *>::iterator lastElementPointer()
  {
    return _elements.end();
  }

  // add element data in the arrays (if unique is set, only add the
  // element if another one with the same barycenter is not already
  // present)
  void add(double *x, double *y, double *z, SVector3 *n, unsigned int *col,
           MElement *ele = nullptr, bool unique = true, bool boundary = false);
  void add(double *x, double *y, double *z, SVector3 *n, unsigned char *r = nullptr,
           unsigned char *g = nullptr, unsigned char *b = nullptr, unsigned char *a = nullptr,
           MElement *ele = nullptr, bool unique = true, bool boundary = false);
  // finalize the arrays
  void finalize();
  // sort the arrays with elements back to front wrt the eye position
  void sort(double x, double y, double z);
  // estimate the size of the vertex array in megabytes
  double getMemoryInMB();
  // serialize the vertex array into a string (for sending over the
  // network)
  char *toChar(int num, const std::string &name, int type, double min,
               double max, int numsteps, double time,
               const SBoundingBox3d &bbox, int &len);
  void fromChar(int length, const char *bytes, int swap);
  static int decodeHeader(int length, const char *bytes, int swap,
                          std::string &name, int &tag, int &type, double &min,
                          double &max, int &numSteps, double &time,
                          double &xmin, double &ymin, double &zmin,
                          double &xmax, double &ymax, double &zmax);
  // merge another vertex array into this one
  void merge(VertexArray *va);

  // index the arrays in finalize() (set from the GMSH_INDEXED_VA env variable)
  static int indexing;
  // drop elements that are drawn several times (GMSH_UNIQUE_VA env variable)
  static int unique;
  // statistics gathered while indexing
  static long int statCorners, statVertices, statVerticesNoNormal;
  static long int statUniqueIn, statUniqueKept;
  static double statTime, statUniqueTime;
  static void printStats();
};

#endif
