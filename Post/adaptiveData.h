#ifndef _ADAPTIVE_DATA_H_
#define _ADAPTIVE_DATA_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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
  int _resolutionLevel;
  double _tolerance, _minVal, _maxVal;
  List_T *_listEle;
  int *_numEle;
  Double_Matrix *_coefs, *_eexps;
  Double_Matrix *_coefsGeom, *_eexpsGeom;
  Double_Matrix *_posX, *_posY, *_posZ;
  Double_Matrix *_val, *_valX, *_valY, *_valZ;
  Double_Matrix *_interpolate, *_geometry;
  void _changeResolution(int level, GMSH_Post_Plugin *plug, int *done);
  int _zoomElement(int ielem, int level, GMSH_Post_Plugin *plug);
 public:
  adaptiveElements(List_T *listEle, int *numEle,
		   List_T *coeffs, List_T *eexps, 
		   List_T *coeffsGeom=0, List_T *eexpsGeom=0);
  ~adaptiveElements();
  void initWithLowResolution(PViewData *data, int step);
  void changeResolution(int level, double tol, GMSH_Post_Plugin *plug=0);
};

class adaptiveData {
 private:
  PViewData *_inData;
  PViewDataList *_outData;
  adaptiveElements<adaptiveLine> *_lines;
  adaptiveElements<adaptiveTriangle> *_triangles;
  adaptiveElements<adaptiveQuadrangle> *_quadrangles;
  adaptiveElements<adaptiveTetrahedron> *_tetrahedra;
  adaptiveElements<adaptiveHexahedron> *_hexahedra;
 public:
  adaptiveData(PViewData *data);
  ~adaptiveData();
  PViewData *getData(){ return (PViewData*)_outData; }
  void initWithLowResolution(int step);
  void changeResolution(int level, double tol, GMSH_Post_Plugin *plug=0);
};

#endif
