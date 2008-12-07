// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ADAPTIVE_DATA_H_
#define _ADAPTIVE_DATA_H_

#include <list>
#include <set>
#include "ListUtils.h"
#include "GmshMatrix.h"

class PViewData;
class PViewDataList;
class GMSH_Post_Plugin;

class adaptivePoint {
 public:
  double x, y, z, X, Y, Z;
  double val, valx, valy, valz;
  double shapeFunctions[128];
  static std::set<adaptivePoint> all;
 public:
  static adaptivePoint *create(double x, double y, double z, 
			       Double_Matrix *coeffs, Double_Matrix *eexps);
  bool operator < (const adaptivePoint &other) const
  {
    if(other.x < x) return true;
    if(other.x > x) return false;
    if(other.y < y) return true;
    if(other.y > y) return false;
    if(other.z < z) return true;
    return false;
  }
};

class adaptiveLine {
 public:
  bool visible;
  adaptivePoint *p[2];
  adaptiveLine *e[2];
  static std::list<adaptiveLine*> all;
  static int numNodes, numEdges;
 public:
  adaptiveLine(adaptivePoint *p1, adaptivePoint *p2)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    e[0] = e[1] = 0;
  } 
  inline double V() const
  {
    return (p[0]->val + p[1]->val) / 2.;
  }
  inline static void GSF(double u, double v, double w, double sf[])
  {
    sf[0] = (1 - u) / 2.;
    sf[1] = (1 + u) / 2.;
  }
  static void create(int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void recurCreate(adaptiveLine *e, int maxlevel, int level, 
			  Double_Matrix *coeffs, Double_Matrix *eexps);
  static void error(double AVG, double tol);
  static void recurError(adaptiveLine *e, double AVG, double tol);
};

class adaptiveTriangle {
 public:
  bool visible;
  adaptivePoint *p[3];
  adaptiveTriangle *e[4];
  static std::list<adaptiveTriangle*> all;
  static int numNodes, numEdges;
 public:
  adaptiveTriangle(adaptivePoint *p1, adaptivePoint *p2, adaptivePoint *p3)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    e[0] = e[1] = e[2] = e[3] = 0;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val) / 3.;
  }
  inline static void GSF(double u, double v, double w, double sf[])
  {
    sf[0] = 1. - u - v;
    sf[1] = u;
    sf[2] = v;
  }
  static void create(int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void recurCreate(adaptiveTriangle *t, int maxlevel, int level,
			  Double_Matrix *coeffs, Double_Matrix *eexps);
  static void error(double AVG, double tol);
  static void recurError(adaptiveTriangle *t, double AVG, double tol);
};

class adaptiveQuadrangle {
 public:
  bool visible;
  adaptivePoint *p[4];
  adaptiveQuadrangle *e[4];
  static std::list<adaptiveQuadrangle*> all;
  static int numNodes, numEdges;
 public:
  adaptiveQuadrangle(adaptivePoint *p1, adaptivePoint *p2, 
		     adaptivePoint *p3, adaptivePoint *p4)    
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    e[0] = e[1] = e[2] = e[3] = 0;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val) / 4.;
  }
  inline static void GSF(double u, double v, double w, double sf[])
  {
    sf[0] = 0.25 * (1. - u) * (1. - v);
    sf[1] = 0.25 * (1. + u) * (1. - v);
    sf[2] = 0.25 * (1. + u) * (1. + v);
    sf[3] = 0.25 * (1. - u) * (1. + v);
  }
  static void create(int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void recurCreate(adaptiveQuadrangle *q, int maxlevel, int level,
			  Double_Matrix *coeffs, Double_Matrix *eexps);
  static void error(double AVG, double tol);
  static void recurError(adaptiveQuadrangle *q, double AVG, double tol);
};

class adaptivePrism {
 public:
  bool visible;
  adaptivePoint *p[6];
  adaptivePrism *e[12];
  static std::list<adaptivePrism*> all;
  static int numNodes, numEdges;
 public:
  adaptivePrism(adaptivePoint *p1, adaptivePoint *p2, 
		      adaptivePoint *p3, adaptivePoint *p4, 
          adaptivePoint *p5, adaptivePoint *p6)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    e[0] = e[1] = e[2]  = e[3]  = NULL;
    e[4] = e[5] = e[6]  = e[7]  = NULL;
    e[8] = e[9] = e[10] = e[11] = NULL;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val + p[4]->val + p[5]->val) / 6.;
  }
  inline static void GSF(double u, double v, double w, double sf[])
  {
    sf[0] = (1. - u - v) * (1 - w) / 2;
    sf[1] = u * (1-w)/2;
    sf[2] = v*(1-w)/2;
    sf[3] = (1. - u - v)*(1+w)/2;
    sf[4] = u*(1+w)/2;
    sf[5] = v*(1+w)/2;
  }
  static void create(int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void recurCreate(adaptivePrism *p, int maxlevel, int level, 
			  Double_Matrix *coeffs, Double_Matrix *eexps);
  static void error(double AVG, double tol);
  static void recurError(adaptivePrism *p, double AVG, double tol);
};

class adaptiveTetrahedron {
 public:
  bool visible;
  adaptivePoint *p[4];
  adaptiveTetrahedron *e[8];
  static std::list<adaptiveTetrahedron*> all;
  static int numNodes, numEdges;
 public:
  adaptiveTetrahedron(adaptivePoint *p1, adaptivePoint *p2, 
		      adaptivePoint *p3, adaptivePoint *p4)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    e[0] = e[1] = e[2] = e[3] = 0;
    e[4] = e[5] = e[6] = e[7] = 0;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val) / 4.;
  }
  inline static void GSF(double u, double v, double w, double sf[])
  {
    sf[0] = 1. - u - v - w;
    sf[1] = u;
    sf[2] = v;
    sf[3] = w;
  }
  static void create(int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void recurCreate(adaptiveTetrahedron *t, int maxlevel, int level, 
			  Double_Matrix *coeffs, Double_Matrix *eexps);
  static void error(double AVG, double tol);
  static void recurError(adaptiveTetrahedron *t, double AVG, double tol);
};

class adaptiveHexahedron {
 public:
  bool visible;
  adaptivePoint *p[8];
  adaptiveHexahedron *e[8];
  static std::list<adaptiveHexahedron*> all;
  static int numNodes, numEdges;
 public:
  adaptiveHexahedron(adaptivePoint *p1, adaptivePoint *p2, adaptivePoint *p3, 
		     adaptivePoint *p4, adaptivePoint *p5, adaptivePoint *p6, 
		     adaptivePoint *p7, adaptivePoint *p8)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    p[6] = p7;
    p[7] = p8;
    e[0] = e[1] = e[2] = e[3] = 0;
    e[4] = e[5] = e[6] = e[7] = 0;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val+ p[3]->val +
            p[4]->val + p[5]->val + p[6]->val+ p[7]->val) / 8.;
  }
  inline static void GSF(double u, double v, double w, double sf[])
  {
    sf[0] = 0.125 * (1 - u) * (1 - v) * (1 - w);
    sf[1] = 0.125 * (1 + u) * (1 - v) * (1 - w);
    sf[2] = 0.125 * (1 + u) * (1 + v) * (1 - w);
    sf[3] = 0.125 * (1 - u) * (1 + v) * (1 - w);
    sf[4] = 0.125 * (1 - u) * (1 - v) * (1 + w);
    sf[5] = 0.125 * (1 + u) * (1 - v) * (1 + w);
    sf[6] = 0.125 * (1 + u) * (1 + v) * (1 + w);
    sf[7] = 0.125 * (1 - u) * (1 + v) * (1 + w);
  }
  static void create(int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void recurCreate(adaptiveHexahedron *h, int maxlevel, int level,
			  Double_Matrix *coeffs, Double_Matrix *eexps);
  static void error(double AVG, double tol);
  static void recurError(adaptiveHexahedron *h, double AVG, double tol);
};

template <class T>
class adaptiveElements {
 private:
  int _level;
  double _tol, _minVal, _maxVal;
  List_T *_listEle;
  int *_numEle;
  Double_Matrix *_coeffs, *_eexps;
  Double_Matrix *_coeffsGeom, *_eexpsGeom;
  Double_Matrix *_posX, *_posY, *_posZ;
  Double_Matrix *_val, *_valX, *_valY, *_valZ;
  Double_Matrix *_interpolate, *_geometry;
  void _changeResolution(int level, GMSH_Post_Plugin *plug, int *done);
  int _zoomElement(int ielem, int level, GMSH_Post_Plugin *plug);
 public:
  adaptiveElements(List_T *listEle, int *numEle,
		   Double_Matrix *coeffs, Double_Matrix *eexps, 
		   Double_Matrix *coeffsGeom=0, Double_Matrix *eexpsGeom=0)
    : _level(-1), _tol(-1.), _minVal(0.), _maxVal(0.),
      _listEle(listEle), _numEle(numEle), _coeffs(coeffs), _eexps(eexps),
      _coeffsGeom(coeffsGeom), _eexpsGeom(eexpsGeom), _posX(0), _posY(0), _posZ(0),
      _val(0), _valX(0), _valY(0), _valZ(0), _interpolate(0), _geometry(0){}
  ~adaptiveElements();
  // store data's step-th timestep data into _val and _pos arrays
  // (This makes adaptive views even more memory hungry than what they
  // already are due to their discontinous nature. We should evaluate
  // the performance hit incurred if we loop directly in data in
  // _zoomElement instead)
  void initData(PViewData *data, int step);
  // compute the adaptive representation and store it in _listEle
  void changeResolution(int level, double tol, GMSH_Post_Plugin *plug=0);
  // The number of nodes is supposed to be fixed in an adaptive view
  inline int getNumNodes () const { return _coeffsGeom ? _coeffsGeom->size1() : T::numNodes; }
};

class adaptiveData {
 private:
  int _step, _level;
  double _tol;
  PViewData *_inData;
  PViewDataList *_outData;
  adaptiveElements<adaptiveLine> *_lines;
  adaptiveElements<adaptiveTriangle> *_triangles;
  adaptiveElements<adaptiveQuadrangle> *_quadrangles;
  adaptiveElements<adaptiveTetrahedron> *_tetrahedra;
  adaptiveElements<adaptiveHexahedron> *_hexahedra;
  adaptiveElements<adaptivePrism> *_prisms;
 public:
  adaptiveData(PViewData *data);
  ~adaptiveData();
  PViewData *getData(){ return (PViewData*)_outData; }
  void changeResolution(int step, int level, double tol, GMSH_Post_Plugin *plug=0);
};

#endif
