// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SMOOTH_DATA_H_
#define _SMOOTH_DATA_H_

#include <set>
#include <vector>
#include <string>

// Basic coordinate-based floating point data averager

struct xyzv {
  double x, y, z, *vals;
  int nbvals;
  int nboccurences;
  static double eps;
  xyzv(double xx, double yy, double zz)
    : x(xx), y(yy), z(zz), vals(0), nbvals(0), nboccurences(0) {}
  ~xyzv(){ if(vals) delete [] vals; }
  // these are needed for set<> operations since the default copy
  // constructor won't allocate *vals
  xyzv(const xyzv & other);
  xyzv & operator = (const xyzv &other);
  void update(int n, double *v);
};

struct lessthanxyzv {
  bool operator () (const xyzv &p2, const xyzv &p1) const
  {
    if(p1.x - p2.x > xyzv::eps)
      return true;
    if(p1.x - p2.x < -xyzv::eps)
      return false;
    if(p1.y - p2.y > xyzv::eps)
      return true;
    if(p1.y - p2.y < -xyzv::eps)
      return false;
    if(p1.z - p2.z > xyzv::eps)
      return true;
    return false;
  }
};

class smooth_data{
 private:
  std::set<xyzv, lessthanxyzv> c;  
 public:
  smooth_data() {}
  void add(double x, double y, double z, int n, double *vals);
  bool get(double x, double y, double z, int n, double *vals);
  void normalize();
  bool exportview(std::string filename);
};

// Normal smoother with threshold (saves memory by storing normals as
// chars and coordinates as floats)

struct nnb
{
  char nx, ny, nz;
  unsigned char nb;
};

struct xyzn
{
  float x, y, z;
  std::vector<nnb> n;
  static float eps;
  xyzn(float xx, float yy, float zz) : x(xx), y(yy), z(zz){}
  ~xyzn(){}
  float angle(int i, char n0, char n1, char n2);
  void update(char n0, char n1, char n2, float tol);
};

struct lessthanxyzn
{
  bool operator () (const xyzn &p2, const xyzn &p1) const
  {
    if(p1.x - p2.x > xyzn::eps)
      return true;
    if(p1.x - p2.x < -xyzn::eps)
      return false;
    if(p1.y - p2.y > xyzn::eps)
      return true;
    if(p1.y - p2.y < -xyzn::eps)
      return false;
    if(p1.z - p2.z > xyzn::eps)
      return true;
    return false;
  }
};

class smooth_normals{
 private:
  float tol;
  std::set<xyzn, lessthanxyzn> c;  
 public:
  smooth_normals(double angle) : tol((float)angle) {}
  void add(double x, double y, double z, double nx, double ny, double nz);
  bool get(double x, double y, double z, double &nx, double &ny, double &nz);
};

#endif
