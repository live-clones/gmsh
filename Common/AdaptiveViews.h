#ifndef _ADAPTIVE_VIEWS_H_
#define _ADAPTIVE_VIEWS_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "List.h"
#include "GmshMatrix.h"
#include <list>

#define MAX_LEVEL_OF_ZOOM 8

class Post_View;
class GMSH_Post_Plugin;

// On a triangle, we suppose that there exists an interpolation scheme
// such that u = \sum_i u_i \phi_i, phi_i being polynomials of order
// p, i goes from 1...(p+1)(p+2)/2 and phi_i = \sum_j coeffs_{ij}
// monomials_j and monomials are 1,x,y,x^2,xy,y^2,x^3,x^2y,xy^2,y^3...

class adapt_point
{
public :
  double x,y,z;
  double X,Y,Z,val,valx,valy,valz;
  double shape_functions[128];
  static adapt_point * New (double x, double y, double z, 
			    Double_Matrix *coeffs, Double_Matrix *eexps); 
  void print () const
  {
    printf("p %g %g\n" ,x,y);
  }
  bool operator < (const adapt_point & other) const
  {
    if(other.x < x) return true;
    if(other.x > x) return false;
    if(other.y < y) return true;
    if(other.y > y) return false;
    if(other.z < z) return true;
    return false;
  }
  static std::set<adapt_point> all_points;
};

class adapt_edge
{
public:
  adapt_edge (adapt_point *p1,adapt_point *p2)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    e[0] = e[1] = 0;
  } 
  inline double V () const
  {
    return (p[0]->val + p[1]->val)/2.;    
  }
  inline static void GSF (const double u, const double v, double w, double sf[]) 
  {
    sf[0] = (1-u)/2.;
    sf[1] = (1+u)/2.;
  }
  void print ()
  {
    printf("p1 %g %g p2 %g %g\n", p[0]->x, p[0]->y, p[1]->x, p[1]->y);
  }
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) ;
  static void Recur_Create (adapt_edge *e, int maxlevel, int level, 
			    Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error (double AVG , double tol );
  static void Recur_Error (adapt_edge *e, double AVG, double tol);
  bool visible;
  adapt_point *p[2];
  adapt_edge  *e[2];
  static std::list<adapt_edge*> all_elems;
  static int nbNod;
};

class adapt_triangle
{
public:
  adapt_triangle (adapt_point *p1, adapt_point *p2, adapt_point *p3)
    : visible (false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    e[0] = e[1] = e[2] = e[3] = 0;
  }
  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val)/3.;    
  }
  inline static void GSF (const double u, const double v, double w, double sf[]) 
  {
    sf[0] = 1-u-v;
    sf[1] = u;
    sf[2] = v;
  }
  void print ()
  {
    printf("p1 %g %g p2 %g %g p3 %g %g\n", 
	   p[0]->x, p[0]->y, p[1]->x, p[1]->y, p[2]->x, p[2]->y);
  }
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Recur_Create (adapt_triangle *t, int maxlevel, int level,
			    Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error (double AVG, double tol);
  static void Recur_Error (adapt_triangle *t, double AVG, double tol);
  bool visible;
  adapt_point *p[3];
  adapt_triangle *e[4];
  static std::list<adapt_triangle*> all_elems;
  static int nbNod;
};

class adapt_quad
{
public:
  adapt_quad (adapt_point *p1, adapt_point *p2, adapt_point *p3, adapt_point *p4)    
    : visible (false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    e[0] = e[1] = e[2] = e[3] = 0;
  }
  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val)/4.;    
  }
  inline static void GSF (const double u, const double v, double w, double sf[]) 
  {
    sf[0] = 0.25 * (1 - u) * (1 - v);
    sf[1] = 0.25 * (1 + u) * (1 - v);
    sf[2] = 0.25 * (1 + u) * (1 + v);
    sf[3] = 0.25 * (1 - u) * (1 + v);
  }
  void print ()
  {
    printf("p1 %g %g p2 %g %g p3 %g %g\n",
	   p[0]->x, p[0]->y, p[1]->x, p[1]->y, p[2]->x, p[2]->y);
  }
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Recur_Create (adapt_quad *q, int maxlevel, int level,
			    Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error (double AVG, double tol);
  static void Recur_Error (adapt_quad *q, double AVG, double tol);
  bool visible;
  adapt_point *p[4];
  adapt_quad *e[4];
  static std::list<adapt_quad*> all_elems;
  static int nbNod;
};

class adapt_tet
{
public:
  adapt_tet (adapt_point *p1, adapt_point *p2, adapt_point *p3, adapt_point *p4)    
    : visible (false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    e[0] = e[1] = e[2] = e[3] = 0;
    e[4] = e[5] = e[6] = e[7] = 0;
  }
  inline static void GSF (const double u, const double v, double w, double sf[])
  {
    sf[0] = 1-u-v-w;
    sf[1] = u;
    sf[2] = v;
    sf[3] = w;
  }
  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val)/4.;    
  }
  void print ()
  {
    printf("p1 %g %g p2 %g %g p3 %g %g\n",
	   p[0]->x, p[0]->y, p[1]->x, p[1]->y, p[2]->x, p[2]->y);
  }
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Recur_Create (adapt_tet *t, int maxlevel, int level, 
			    Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error (double AVG, double tol);
  static void Recur_Error (adapt_tet *t, double AVG, double tol);
  bool visible;
  adapt_point *p[4];
  adapt_tet *e[8];
  static std::list<adapt_tet*> all_elems;
  static int nbNod;
};

class adapt_hex
{
public:
  adapt_hex (adapt_point *p1, adapt_point *p2, adapt_point *p3, adapt_point *p4,
	     adapt_point *p5, adapt_point *p6, adapt_point *p7, adapt_point *p8)    
    : visible (false)
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
  inline static void GSF (const double u, const double v, double w, double sf[])
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
  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val+ p[3]->val +
	    p[4]->val + p[5]->val + p[6]->val+ p[7]->val)/8.;    
  }
  void print ()
  {
    printf("p1 %g %g p2 %g %g p3 %g %g\n",
	   p[0]->x, p[0]->y, p[1]->x, p[1]->y, p[2]->x, p[2]->y);
  }
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Recur_Create (adapt_hex *h, int maxlevel, int level,
			    Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error (double AVG, double tol);
  static void Recur_Error (adapt_hex *h, double AVG, double tol);
  bool visible;
  adapt_point *p[8];
  adapt_hex *e[8];
  static std::list<adapt_hex*> all_elems;
  static int nbNod;
};

class Adaptive_Post_View 
{
  double tol;
  double min,max;
  int presentZoomLevel;
  double presentTol;
  Double_Matrix * _eexps;
  Double_Matrix * _coefs;
  Double_Matrix * _STposX;
  Double_Matrix * _STposY;
  Double_Matrix * _STposZ;
  Double_Matrix * _STval;
  // for vectors
  Double_Matrix * _STvalX;
  Double_Matrix * _STvalY;
  Double_Matrix * _STvalZ;
  Double_Matrix * _Interpolate;
  Double_Matrix * _Geometry;
public:
  Adaptive_Post_View (Post_View *view, List_T *_coeffs, List_T *_eexps);
  ~Adaptive_Post_View ();
  int getGlobalResolutionLevel () const { return presentZoomLevel; }
  void setGlobalResolutionLevel (Post_View * view, int level)
  {
    setAdaptiveResolutionLevel(view, level);
  }
  template <class ELEM>
  void setAdaptiveResolutionLevel_TEMPL(Post_View * view, int level, int lemvelmax,
					GMSH_Post_Plugin *plug, List_T **myList,
					int *counter, int *done);
  void setAdaptiveResolutionLevel (Post_View * view , int levelmax, 
				   GMSH_Post_Plugin *plug = 0);
  void initWithLowResolution (Post_View *view);
  void setTolerance (const double eps) { tol=eps; }
  double getTolerance () const { return tol; }
  template <class ELEM>
  int zoomElement (Post_View * view, int ielem, int level, int levelmax, 
		   GMSH_Post_Plugin *plug, List_T *theList, int *counter);
};

template <class ELEM>
void cleanElement ()
{  
  typename std::list<ELEM*>::iterator it =  ELEM::all_elems.begin();
  typename std::list<ELEM*>::iterator ite =  ELEM::all_elems.end();
  for (; it != ite; ++it){
    delete *it;
  }
  ELEM::all_elems.clear();
  adapt_point::all_points.clear();
}

#endif
