#ifndef _ADAPTIVE_VIEWS_H_
#define _ADAPTIVE_VIEWS_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

// On a triangle, we suppose that there exists an
// interpolation scheme such that u = \sum_i u_i \phi_i
// phi_i being polynomials of order p, i goes from 1...(p+1)(p+2)/2
// and phi_i = \sum_j coeffs_{ij} monomials_j and
// monomials are 1,x,y,x^2,xy,y^2,x^3,x^2y,xy^2,y^3...
class adapt_point
{
public :
  double x,y,z;
  double X,Y,Z,val;
  double shape_functions[128];
  static adapt_point * New ( double x, double y, double z, Double_Matrix *coeffs, Double_Matrix *eexps); 
  void print ()const
  {
    printf ("p %g %g\n" ,x,y);
  }
  bool operator < ( const adapt_point & other ) const
  {
    if ( other.x < x) return true;
    if ( other.x > x) return false;
    if ( other.y < y) return true;
    if ( other.y > y) return false;
    if ( other.z < z) return true;
    return false;
  }
  static std::set<adapt_point> all_points;
};

class adapt_triangle
{
public:
  adapt_triangle (adapt_point *p1,adapt_point *p2,adapt_point *p3)    
    : visible (false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    t[0]=t[1]=t[2]=t[3]=0;
  }

  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val)/3.;    
  }
  void print ()
  {
    printf ("p1 %g %g p2 %g %g p3 %g %g \n",p[0]->x,p[0]->y,p[1]->x,p[1]->y,p[2]->x,p[2]->y);
  }
  static void clean ();
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) ;
  static void Recur_Create (adapt_triangle *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error ( double AVG , double tol );
  static void Recur_Error ( adapt_triangle *t, double AVG, double tol );
  bool visible;
  adapt_point     *p[3];
  adapt_triangle  *t[4];
  static std::list<adapt_triangle*> all_triangles;
};

class adapt_quad
{
public:
  adapt_quad (adapt_point *p1,adapt_point *p2,adapt_point *p3,adapt_point *p4)    
    : visible (false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    q[0]=q[1]=q[2]=q[3]=0;
  }

  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val+ p[3]->val)/4.;    
  }
  void print ()
  {
    printf ("p1 %g %g p2 %g %g p3 %g %g \n",p[0]->x,p[0]->y,p[1]->x,p[1]->y,p[2]->x,p[2]->y);
  }
  static void clean ();
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) ;
  static void Recur_Create (adapt_quad *q, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error ( double AVG , double tol );
  static void Recur_Error ( adapt_quad *q, double AVG, double tol );
  bool visible;
  adapt_point     *p[4];
  adapt_quad  *q[4];
  static std::list<adapt_quad*> all_quads;
};

class adapt_tet
{
public:
  adapt_tet (adapt_point *p1,adapt_point *p2,adapt_point *p3,adapt_point *p4)    
    : visible (false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    t[0]=t[1]=t[2]=t[3]=0;
    t[4]=t[5]=t[6]=t[7]=0;
  }

  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val+ p[3]->val)/4.;    
  }
  void print ()
  {
    printf ("p1 %g %g p2 %g %g p3 %g %g \n",p[0]->x,p[0]->y,p[1]->x,p[1]->y,p[2]->x,p[2]->y);
  }
  static void clean ();
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) ;
  static void Recur_Create (adapt_tet *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error ( double AVG , double tol );
  static void Recur_Error ( adapt_tet *t, double AVG, double tol );
  bool visible;
  adapt_point     *p[4];
  adapt_tet  *t[8];
  static std::list<adapt_tet*> all_tets;
};

class adapt_hex
{
public:
  adapt_hex (adapt_point *p1,adapt_point *p2,adapt_point *p3,adapt_point *p4,adapt_point *p5,adapt_point *p6,adapt_point *p7,adapt_point *p8)    
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
    h[0]=h[1]=h[2]=h[3]=0;
    h[4]=h[5]=h[6]=h[7]=0;
  }

  inline double V () const
  {
    return (p[0]->val + p[1]->val + p[2]->val+ p[3]->val+p[4]->val + p[5]->val + p[6]->val+ p[7]->val)/8.;    
  }
  void print ()
  {
    printf ("p1 %g %g p2 %g %g p3 %g %g \n",p[0]->x,p[0]->y,p[1]->x,p[1]->y,p[2]->x,p[2]->y);
  }
  static void clean ();
  static void Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) ;
  static void Recur_Create (adapt_hex *h, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps);
  static void Error ( double AVG , double tol );
  static void Recur_Error ( adapt_hex *h, double AVG, double tol );
  bool visible;
  adapt_point     *p[8];
  adapt_hex *h[8];
  static std::list<adapt_hex*> all_hexes;
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
  Double_Matrix * _Interpolate;
  Double_Matrix * _Geometry;
public:
  Adaptive_Post_View (Post_View *view, List_T *_coeffs, List_T *_eexps);
  ~Adaptive_Post_View();
  int getGlobalResolutionLevel ( ) const {return presentZoomLevel;}
  void setGlobalResolutionLevel ( Post_View * view , int level )
    {
      setAdaptiveResolutionLevel ( view , level );
    }
  void setAdaptiveResolutionLevel ( Post_View * view , int levelmax, GMSH_Post_Plugin *plug = 0);
  void initWithLowResolution (Post_View *view);
  void setTolerance (const double eps) {tol=eps;}
  double getTolerance () const {return tol;}
  void zoomQuad (Post_View * view ,
		 int ielem, int level, GMSH_Post_Plugin *plug);
  void zoomTriangle (Post_View * view ,
		    int ielem, int level, GMSH_Post_Plugin *plug);
  void zoomTet (Post_View * view ,
		int ielem, int level, GMSH_Post_Plugin *plug,
		Double_Vector & val,
		Double_Vector & res,
		Double_Matrix & XYZ);
  void zoomHex (Post_View * view ,
		int ielem, int level, GMSH_Post_Plugin *plug,
		Double_Vector & val,
		Double_Vector & res,
		Double_Matrix & XYZ);
};

#endif
