// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <vector>
#include <set>
#include "SVector3.h"
#include "SBoundingBox3d.h"

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
  std::set<ElementData<3>, ElementDataLessThan<3> > _data3;
  std::set<Barycenter, BarycenterLessThan> _barycenters;
  // std::tr1::unordered_set<Barycenter, BarycenterHash, BarycenterEqual>
  // _barycenters;

  // add stuff in the arrays
  void _addVertex(float x, float y, float z);
  void _addNormal(float nx, float ny, float nz);
  void _addColor(unsigned char r, unsigned char g, unsigned char b,
                 unsigned char a);
  void _addElement(MElement *ele);

public:
  VertexArray(int numVerticesPerElement, int numElements);
  ~VertexArray() {}
  // return the number of vertices in the array
  int getNumVertices() { return (int)_vertices.size() / 3; }
  // return the number of vertices per element
  int getNumVerticesPerElement() { return _numVerticesPerElement; }
  // return the number of element pointers
  int getNumElementPointers() { return (int)_elements.size(); }
  // return a pointer to the raw vertex array (warning: 1) we don't
  // range check 2) calling this if _vertices.size() == 0 will cause
  // some compilers to throw an exception)
  float *getVertexArray(int i = 0) { return &_vertices[i]; }
  std::vector<float>::iterator firstVertex() { return _vertices.begin(); }
  std::vector<float>::iterator lastVertex() { return _vertices.end(); }

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
  double getMemoryInMb();
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
};

#endif
