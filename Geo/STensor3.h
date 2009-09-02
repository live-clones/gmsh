// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _STENSOR3_H_
#define _STENSOR3_H_

#include "SVector3.h"
#include "GmshMatrix.h"
#include "Numeric.h"

// concrete class for symmetric positive definite 3x3 matrix
class SMetric3 {
 protected:
  // lower diagonal storage
  // 00 10 11 20 21 22 
  double _val[6];
 public:
  inline int getIndex(int i, int j) const{
    static int _index[3][3] = {{0,1,3},{1,2,4},{3,4,5}};
    return _index[i][j];
  }
  void getMat (gmshMatrix<double> & mat) const{
    for (int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        mat(i,j) = _val[getIndex(i,j)];                      
      }
    }
  }
  void setMat (const gmshMatrix<double> & mat){
    for (int i=0;i<3;i++)
      for (int j=i;j<3;j++)
        _val[getIndex(i,j)] = mat(i,j);                      
  }
  SMetric3(const SMetric3& m){
    for (int i=0; i<6; i++) _val[i]=m._val[i];
  }
  // default constructor, identity 
  SMetric3(const double v = 1.0){
    _val[0] = _val[2] = _val[5] = v;
    _val[1] = _val[3] = _val[4] = 0.0;
  }
/*   SMetric3(const double l1, // (h_1)^-2 */
/*         const double l2, */
/*         const double l3, */
/*         const SVector3 &t1, */
/*         const SVector3 &t2, */
/*         const SVector3 &t3){ */
/*     SVector3 t1b = t1; */
/*     SVector3 t2b = t2; */
/*     SVector3 t3b = t3; */
/*     t1b[0] *= l1; t2b[0] *= l1; t3b[0] *= l1; */
/*     t1b[1] *= l2; t2b[1] *= l2; t3b[1] *= l2; */
/*     t1b[2] *= l3; t2b[2] *= l3; t3b[2] *= l3; */
/*     _val[0] = dot (t1b,t1); */
/*     _val[1] = dot (t2b,t1); */
/*     _val[2] = dot (t2b,t2); */
/*     _val[3] = dot (t3b,t1); */
/*     _val[4] = dot (t3b,t2);     */
/*     _val[5] = dot (t3b,t3); */
/*   } */
  SMetric3(const double l1, // l1 = h1^-2
           const double l2,
           const double l3,
           const SVector3 &t1,
           const SVector3 &t2,
           const SVector3 &t3)
    {
      // M = e^1 * diag * e^1^t
      // where the elements of diag are l_i = h_i^-2
      // and the rows of e are the UNIT and ORTHOGONAL directions

      gmshMatrix<double> e(3,3);
      e(0,0) = t1(0); e(0,1) = t1(1); e(0,2) = t1(2);
      e(1,0) = t2(0); e(1,1) = t2(1); e(1,2) = t2(2);
      e(2,0) = t3(0); e(2,1) = t3(1); e(2,2) = t3(2);
      e.invertInPlace();
    
      gmshMatrix<double> tmp(3,3);
      tmp(0,0) = l1 * e(0,0);
      tmp(0,1) = l2 * e(0,1);
      tmp(0,2) = l3 * e(0,2);
      tmp(1,0) = l1 * e(1,0);
      tmp(1,1) = l2 * e(1,1);
      tmp(1,2) = l3 * e(1,2);
      tmp(2,0) = l1 * e(2,0);
      tmp(2,1) = l2 * e(2,1);
      tmp(2,2) = l3 * e(2,2);
      
      e.transposeInPlace();

      _val[0] = tmp(0,0) * e(0,0) + tmp(0,1) * e(1,0) + tmp(0,2) * e(2,0);
      _val[1] = tmp(1,0) * e(0,0) + tmp(1,1) * e(1,0) + tmp(1,2) * e(2,0);
      _val[2] = tmp(1,0) * e(0,1) + tmp(1,1) * e(1,1) + tmp(1,2) * e(2,1);
      _val[3] = tmp(2,0) * e(0,0) + tmp(2,1) * e(1,0) + tmp(2,2) * e(2,0);
      _val[4] = tmp(2,0) * e(0,1) + tmp(2,1) * e(1,1) + tmp(2,2) * e(2,1);
      _val[5] = tmp(2,0) * e(0,2) + tmp(2,1) * e(1,2) + tmp(2,2) * e(2,2);
  }
  inline double &operator()(int i, int j){ 
    return _val[getIndex(i,j)];
  }
  inline double operator()(int i, int j) const{ 
    return _val[getIndex(i,j)];
  }  
  SMetric3 invert () const {
    gmshMatrix<double> m(3,3);
    getMat(m);
    m.invertInPlace();
    SMetric3 ithis;
    ithis.setMat(m);
    return ithis;
  }
  SMetric3 operator + (const SMetric3 &other) const {
    SMetric3 res(*this);
    for (int i=0;i<6;i++)res._val[i]+=other._val[i];
    return res;
  }
  SMetric3& operator += (const SMetric3 &other)  {
    for (int i=0;i<6;i++)_val[i]+=other._val[i];
    return *this;
  }
  SMetric3& operator *= (const double &other) {
    for (int i=0;i<6;i++)_val[i]*=other;
    return *this;
  }
  SMetric3& operator *= (const SMetric3 &other) {
    gmshMatrix<double> m1(3,3),m2(3,3),m3(3,3);
    getMat(m1);
    other.getMat(m2);
    m1.mult(m2,m3);
    setMat(m3);
    return *this;
  }
  SMetric3 transform (gmshMatrix<double> &V){
    gmshMatrix<double> m(3,3);
    getMat(m);
    gmshMatrix<double> result(3,3),temp(3,3);
    V.transpose().mult(m,temp);
    temp.mult(V,result);
    SMetric3 a; a.setMat(result);
    return a;    
  }
  // s: true if eigenvalues are sorted (from min to max of the REAL part)
  void eig (gmshMatrix<double> &V, gmshVector<double> &S, bool s=false) const {
    gmshMatrix<double> me(3,3),right(3,3);
    gmshVector<double> im(3);
    getMat(me);
    me.eig(V,S,im,right,s);
  }
  void print(const char *) const;
};

// scalar product with respect to the metric
inline double dot(const SVector3 &a, const SMetric3 &m, const SVector3 &b)
{ return 
    b.x() * ( m(0,0) * a.x() + m(1,0) * a.y() + m(2,0) * a.z() ) + 
    b.y() * ( m(0,1) * a.x() + m(1,1) * a.y() + m(2,1) * a.z() ) + 
    b.z() * ( m(0,2) * a.x() + m(1,2) * a.y() + m(2,2) * a.z() ) ;}

// compute the largest inscribed ellipsoid...
SMetric3 intersection (const SMetric3 &m1, 
                              const SMetric3 &m2);
SMetric3 interpolation (const SMetric3 &m1, 
                        const SMetric3 &m2, 
                        const double t);
SMetric3 interpolation (const SMetric3 &m1, 
                        const SMetric3 &m2, 
                        const SMetric3 &m3, 
                        const double u,
                        const double v);
SMetric3 interpolation (const SMetric3 &m1, 
                        const SMetric3 &m2, 
                        const SMetric3 &m3, 
                        const SMetric3 &m4, 
                        const double u,
                        const double v,
                        const double w);

#endif
