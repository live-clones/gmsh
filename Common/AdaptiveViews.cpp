//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

// Don't indent this file
// *INDENT-OFF*
				       
#include <stdio.h>
#include <math.h>
#include <list>
#include <set>
#include "Views.h"
#include "Plugin.h"

// A recursive effective implementation

void computeShapeFunctions ( Double_Matrix *coeffs, Double_Matrix *eexps , double u, double v, double w,double *sf);

std::set<_point> _point::all_points;
std::list<_triangle*> _triangle::all_triangles;
std::list<_tet*> _tet::all_tets;
std::list<_quad*> _quad::all_quads;

_point * _point::New ( double x, double y, double z, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  _point p;
  p.x=x; p.y=y; p.z=z;
  std::set<_point> :: iterator it = all_points.find ( p );
  if ( it == all_points.end() )
    {
      all_points.insert (p);
      it = all_points.find ( p );
      double *kkk = (double*)(it->shape_functions);
      computeShapeFunctions (coeffs, eexps , x,y,z,kkk);
      return (_point*) & (*it);
    }
  else
    return (_point*) & (*it);
}
void _triangle::clean ()
{    
  std::list<_triangle*>::iterator it =  all_triangles.begin();
  std::list<_triangle*>::iterator ite =  all_triangles.end();
  for (;it!=ite;++it)
    {
      delete *it;
    }
  all_triangles.clear();
  _point::all_points.clear();
}

void _quad::clean ()
{    
  std::list<_quad*>::iterator it =  all_quads.begin();
  std::list<_quad*>::iterator ite =  all_quads.end();
  for (;it!=ite;++it)
    {
      delete *it;
    }
  all_quads.clear();
  _point::all_points.clear();
}

void _tet::clean ()
{    
  std::list<_tet*>::iterator it =  all_tets.begin();
  std::list<_tet*>::iterator ite =  all_tets.end();
  for (;it!=ite;++it)
    {
      delete *it;
    }
  all_tets.clear();
  _point::all_points.clear();
}


void _triangle::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  printf("creating the sub-elements\n");
  int level = 0;
  clean();
  _point *p1 = _point::New ( 0,0,0, coeffs, eexps);
  _point *p2 = _point::New ( 0,1,0, coeffs, eexps);
  _point *p3 = _point::New ( 1,0,0, coeffs, eexps);
  _triangle *t = new _triangle(p1,p2,p3);
  Recur_Create (t, maxlevel,level,coeffs,eexps) ;

  printf("%d _triangle and %d _point created\n",(int)_triangle::all_triangles.size(),(int)_point::all_points.size());
}

void _quad::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  printf("creating the sub-elements\n");
  int level = 0;
  clean();
  _point *p1 = _point::New ( -1,-1,0, coeffs, eexps);
  _point *p2 = _point::New ( -1,1,0, coeffs, eexps);
  _point *p3 = _point::New ( 1,1,0, coeffs, eexps);
  _point *p4 = _point::New ( 1,-1,0, coeffs, eexps);
  _quad *q = new _quad(p1,p2,p3,p4);
  Recur_Create (q, maxlevel,level,coeffs,eexps) ;

  printf("%d _triangle and %d _point created\n",(int)_triangle::all_triangles.size(),(int)_point::all_points.size());
}

void _tet::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  Msg(INFO, "creating sub-elements");
  int level = 0;
  clean();
  _point *p1 = _point::New ( 0,0,0, coeffs, eexps);
  _point *p2 = _point::New ( 0,1,0, coeffs, eexps);
  _point *p3 = _point::New ( 1,0,0, coeffs, eexps);
  _point *p4 = _point::New ( 0,0,1, coeffs, eexps);
  _tet *t = new _tet(p1,p2,p3,p4);
  Recur_Create (t, maxlevel,level,coeffs,eexps) ;
  Msg(INFO, "%d _triangle and %d _point created\n",(int)_tet::all_tets.size(),(int)_point::all_points.size());
}

void _triangle::Recur_Create (_triangle *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_triangles.push_back(t);
  if (level++ >= maxlevel)
    return;

  /*

  p3


  p13   p23


  p1    p12    p2


  */
  
  _point *p1  = t->p[0]; 
  _point *p2  = t->p[1]; 
  _point *p3  = t->p[2]; 
  _point *p12 = _point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,0, coeffs, eexps);
  _point *p13 = _point::New ( (p1->x+p3->x)*0.5,(p1->y+p3->y)*0.5,0, coeffs, eexps);
  _point *p23 = _point::New ( (p3->x+p2->x)*0.5,(p3->y+p2->y)*0.5,0, coeffs, eexps);
  _triangle *t1 = new _triangle (p1,p13,p12);
  Recur_Create (t1, maxlevel,level,coeffs,eexps);
  _triangle *t2 = new _triangle (p12,p23,p2);
  Recur_Create (t2, maxlevel,level,coeffs,eexps); 
  _triangle *t3 = new _triangle (p23,p13,p3);
  Recur_Create (t3, maxlevel,level,coeffs,eexps); 
  _triangle *t4 = new _triangle (p12,p13,p23);
  Recur_Create (t4, maxlevel,level,coeffs,eexps);
  t->t[0]=t1;t->t[1]=t2;t->t[2]=t3;t->t[3]=t4;      

}

void _quad::Recur_Create (_quad *q, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_quads.push_back(q);
  if (level++ >= maxlevel)
    return;

  /*

  p2   p23    p3


  p12  pc     p34


  p1    p14    p4


  */
  
  _point *p1  = q->p[0]; 
  _point *p2  = q->p[1]; 
  _point *p3  = q->p[2]; 
  _point *p4  = q->p[3]; 
  _point *p12 = _point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,0, coeffs, eexps);
  _point *p23 = _point::New ( (p2->x+p3->x)*0.5,(p2->y+p3->y)*0.5,0, coeffs, eexps);
  _point *p34 = _point::New ( (p4->x+p3->x)*0.5,(p4->y+p3->y)*0.5,0, coeffs, eexps);
  _point *p14 = _point::New ( (p1->x+p4->x)*0.5,(p1->y+p4->y)*0.5,0, coeffs, eexps);
  _point *pc = _point::New (  (p1->x+p2->x+p3->x+p4->x)*0.25,(p1->y+p2->y+p3->y+p4->y)*0.25,0, coeffs, eexps);
  _quad *q1 = new _quad (p1,p12,pc,p14);
  Recur_Create (q1, maxlevel,level,coeffs,eexps);
  _quad *q2 = new _quad (p12,p2,p23,pc);
  Recur_Create (q2, maxlevel,level,coeffs,eexps);
  _quad *q3 = new _quad (pc,p23,p3,p34);
  Recur_Create (q3, maxlevel,level,coeffs,eexps);
  _quad *q4 = new _quad (p14,pc,p34,p4);
  Recur_Create (q4, maxlevel,level,coeffs,eexps);
  q->q[0]=q1;q->q[1]=q2;q->q[2]=q3;q->q[3]=q4;      

}

void _tet::Recur_Create (_tet *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_tets.push_back(t);
  if (level++ >= maxlevel)
    return;

  _point *p0  = t->p[0]; 
  _point *p1  = t->p[1]; 
  _point *p2  = t->p[2]; 
  _point *p3  = t->p[3]; 
  _point *pe0 = _point::New ( (p0->x+p1->x)*0.5,(p0->y+p1->y)*0.5,(p0->z+p1->z)*0.5,coeffs, eexps);
  _point *pe1 = _point::New ( (p0->x+p2->x)*0.5,(p0->y+p2->y)*0.5,(p0->z+p2->z)*0.5,coeffs, eexps);
  _point *pe2 = _point::New ( (p0->x+p3->x)*0.5,(p0->y+p3->y)*0.5,(p0->z+p3->z)*0.5,coeffs, eexps);
  _point *pe3 = _point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,(p1->z+p2->z)*0.5,coeffs, eexps);
  _point *pe4 = _point::New ( (p1->x+p3->x)*0.5,(p1->y+p3->y)*0.5,(p1->z+p3->z)*0.5,coeffs, eexps);
  _point *pe5 = _point::New ( (p2->x+p3->x)*0.5,(p2->y+p3->y)*0.5,(p2->z+p3->z)*0.5,coeffs, eexps);

  _tet *t1 = new _tet (p0,pe0,pe2,pe1);
  Recur_Create (t1, maxlevel,level,coeffs,eexps);
  _tet *t2 = new _tet (p1,pe0,pe3,pe4);
  Recur_Create (t2, maxlevel,level,coeffs,eexps);
  _tet *t3 = new _tet (p2,pe3,pe1,pe5);
  Recur_Create (t3, maxlevel,level,coeffs,eexps);
  _tet *t4 = new _tet (p3,pe2,pe4,pe5);
  Recur_Create (t4, maxlevel,level,coeffs,eexps);

  _tet *t5 = new _tet (pe3,pe5,pe2,pe4);
  Recur_Create (t5, maxlevel,level,coeffs,eexps);
  _tet *t6 = new _tet (pe3,pe2,pe0,pe4);
  Recur_Create (t6, maxlevel,level,coeffs,eexps);
  _tet *t7 = new _tet (pe2,pe5,pe3,pe1);
  Recur_Create (t7, maxlevel,level,coeffs,eexps);
  _tet *t8 = new _tet (pe0,pe2,pe3,pe1);
  Recur_Create (t8, maxlevel,level,coeffs,eexps);

  t->t[0]=t1;t->t[1]=t2;t->t[2]=t3;t->t[3]=t4;      
  t->t[4]=t5;t->t[5]=t6;t->t[6]=t7;t->t[7]=t8;      
}


void _triangle::Error ( double AVG , double tol )
{
  _triangle *t = *all_triangles.begin();
  Recur_Error (t,AVG,tol);
}

void _quad::Error ( double AVG , double tol )
{
  _quad *q = *all_quads.begin();
  Recur_Error (q,AVG,tol);
}

void _tet::Error ( double AVG , double tol )
{
  _tet *t = *all_tets.begin();
  Recur_Error (t,AVG,tol);
}

void _triangle::Recur_Error ( _triangle *t, double AVG, double tol )
{
  if(!t->t[0])t->visible = true; 
  else
    {
      double vr;
      if (!t->t[0]->t[0])
	{
	  double v1 = t->t[0]->V();
	  double v2 = t->t[1]->V();
	  double v3 = t->t[2]->V();
	  double v4 = t->t[3]->V();
	  vr = (2*v1 + 2*v2 + 2*v3 + v4)/7.;
	  double v =  t->V();
	  if ( fabs(v - vr) > AVG * tol ) 
	    //if ( fabs(v - vr) > ((fabs(v) + fabs(vr) + AVG * tol) * tol ) ) 
	    {
	      t->visible = false;
	      Recur_Error (t->t[0],AVG,tol);
	      Recur_Error (t->t[1],AVG,tol);
	      Recur_Error (t->t[2],AVG,tol);
	      Recur_Error (t->t[3],AVG,tol);
	    } 
	  else
	    t->visible = true;
	}
      else
	{
	  double v11 = t->t[0]->t[0]->V();
	  double v12 = t->t[0]->t[1]->V();
	  double v13 = t->t[0]->t[2]->V();
	  double v14 = t->t[0]->t[3]->V();
	  double v21 = t->t[1]->t[0]->V();
	  double v22 = t->t[1]->t[1]->V();
	  double v23 = t->t[1]->t[2]->V();
	  double v24 = t->t[1]->t[3]->V();
	  double v31 = t->t[2]->t[0]->V();
	  double v32 = t->t[2]->t[1]->V();
	  double v33 = t->t[2]->t[2]->V();
	  double v34 = t->t[2]->t[3]->V();
	  double v41 = t->t[3]->t[0]->V();
	  double v42 = t->t[3]->t[1]->V();
	  double v43 = t->t[3]->t[2]->V();
	  double v44 = t->t[3]->t[3]->V();
	  double vr1 = (2*v11 + 2*v12 + 2*v13 + v14)/7.;
	  double vr2 = (2*v21 + 2*v22 + 2*v23 + v24)/7.;
	  double vr3 = (2*v31 + 2*v32 + 2*v33 + v34)/7.;
	  double vr4 = (2*v41 + 2*v42 + 2*v43 + v44)/7.;
	  vr = (2*vr1+2*vr2+2*vr3+vr4)/7.;
	  if ( fabs(t->t[0]->V() - vr1) > AVG * tol  || 
	       fabs(t->t[1]->V() - vr2) > AVG * tol  || 
	       fabs(t->t[2]->V() - vr3) > AVG * tol  || 
	       fabs(t->t[3]->V() - vr4) > AVG * tol  || 
	       fabs(t->V() - vr) > AVG * tol ) 
	    //if ( fabs(t->t[0]->V() - vr1) > (fabs(t->t[0]->V())+fabs(vr1)+AVG * tol)*tol  || 
	    //		 fabs(t->t[1]->V() - vr2) > (fabs(t->t[1]->V())+fabs(vr2)+AVG * tol)*tol  || 
	    //		 fabs(t->t[2]->V() - vr3) > (fabs(t->t[2]->V())+fabs(vr3)+AVG * tol)*tol  || 
	    //		 fabs(t->t[3]->V() - vr4) > (fabs(t->t[3]->V())+fabs(vr4)+AVG * tol)*tol  || 
	    //		 fabs(t->V() - vr) > (fabs(t->V())+fabs(vr)+AVG * tol ) *tol)
	    {
	      t->visible = false;
	      Recur_Error (t->t[0],AVG,tol);
	      Recur_Error (t->t[1],AVG,tol);
	      Recur_Error (t->t[2],AVG,tol);
	      Recur_Error (t->t[3],AVG,tol);
	    }
	  else
	    t->visible = true;	      
	}
    }
}

void _quad::Recur_Error ( _quad *q, double AVG, double tol )
{
  if(!q->q[0])q->visible = true; 
  else
    {
      double vr;
      if (!q->q[0]->q[0])
	{
	  double v1 = q->q[0]->V();
	  double v2 = q->q[1]->V();
	  double v3 = q->q[2]->V();
	  double v4 = q->q[3]->V();
	  vr = (v1 + v2 + v3 + v4)/4.;
	  double v =  q->V();
	  if ( fabs(v - vr) > AVG * tol ) 
	    //if ( fabs(v - vr) > ((fabs(v) + fabs(vr) + AVG * tol) * tol ) ) 
	    {
	      q->visible = false;
	      Recur_Error (q->q[0],AVG,tol);
	      Recur_Error (q->q[1],AVG,tol);
	      Recur_Error (q->q[2],AVG,tol);
	      Recur_Error (q->q[3],AVG,tol);
	    } 
	  else
	    q->visible = true;
	}
      else
	{
	  double v11 = q->q[0]->q[0]->V();
	  double v12 = q->q[0]->q[1]->V();
	  double v13 = q->q[0]->q[2]->V();
	  double v14 = q->q[0]->q[3]->V();
	  double v21 = q->q[1]->q[0]->V();
	  double v22 = q->q[1]->q[1]->V();
	  double v23 = q->q[1]->q[2]->V();
	  double v24 = q->q[1]->q[3]->V();
	  double v31 = q->q[2]->q[0]->V();
	  double v32 = q->q[2]->q[1]->V();
	  double v33 = q->q[2]->q[2]->V();
	  double v34 = q->q[2]->q[3]->V();
	  double v41 = q->q[3]->q[0]->V();
	  double v42 = q->q[3]->q[1]->V();
	  double v43 = q->q[3]->q[2]->V();
	  double v44 = q->q[3]->q[3]->V();
	  double vr1 = (v11 + v12 + v13 + v14)/4.;
	  double vr2 = (v21 + v22 + v23 + v24)/4.;
	  double vr3 = (v31 + v32 + v33 + v34)/4.;
	  double vr4 = (v41 + v42 + v43 + v44)/4.;
	  vr = (vr1+vr2+vr3+vr4)/4.;
	  if ( fabs(q->q[0]->V() - vr1) > AVG * tol  || 
	       fabs(q->q[1]->V() - vr2) > AVG * tol  || 
	       fabs(q->q[2]->V() - vr3) > AVG * tol  || 
	       fabs(q->q[3]->V() - vr4) > AVG * tol  || 
	       fabs(q->V() - vr) > AVG * tol ) 
	    //if ( fabs(t->t[0]->V() - vr1) > (fabs(t->t[0]->V())+fabs(vr1)+AVG * tol)*tol  || 
	    //		 fabs(t->t[1]->V() - vr2) > (fabs(t->t[1]->V())+fabs(vr2)+AVG * tol)*tol  || 
	    //		 fabs(t->t[2]->V() - vr3) > (fabs(t->t[2]->V())+fabs(vr3)+AVG * tol)*tol  || 
	    //		 fabs(t->t[3]->V() - vr4) > (fabs(t->t[3]->V())+fabs(vr4)+AVG * tol)*tol  || 
	    //		 fabs(t->V() - vr) > (fabs(t->V())+fabs(vr)+AVG * tol ) *tol)
	    {
	      q->visible = false;
	      Recur_Error (q->q[0],AVG,tol);
	      Recur_Error (q->q[1],AVG,tol);
	      Recur_Error (q->q[2],AVG,tol);
	      Recur_Error (q->q[3],AVG,tol);
	    }
	  else
	    q->visible = true;	      
	}
    }
}


void _tet::Recur_Error ( _tet *t, double AVG, double tol )
{
  if(!t->t[0])t->visible = true; 
  else
    {
      double vr;
      double v1 = t->t[0]->V();
      double v2 = t->t[1]->V();
      double v3 = t->t[2]->V();
      double v4 = t->t[3]->V();
      double v5 = t->t[4]->V();
      double v6 = t->t[5]->V();
      double v7 = t->t[6]->V();
      double v8 = t->t[7]->V();
      vr = (v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8)*.125;
      double v =  t->V();
      if ( fabs(v - vr) > AVG * tol ) 
	{
	  t->visible = false;
	  Recur_Error (t->t[0],AVG,tol);
	  Recur_Error (t->t[1],AVG,tol);
	  Recur_Error (t->t[2],AVG,tol);
	  Recur_Error (t->t[3],AVG,tol);
	  Recur_Error (t->t[4],AVG,tol);
	  Recur_Error (t->t[5],AVG,tol);
	  Recur_Error (t->t[6],AVG,tol);
	  Recur_Error (t->t[7],AVG,tol);
	} 
      else
	t->visible = true;
    }
}

static double t0,t1,t2,t3;

void Adaptive_Post_View:: zoomTriangle (Post_View * view ,
					int ielem ,
					int level, 
					GMSH_Post_Plugin *plug)
{
  std::set<_point>::iterator it  = _point::all_points.begin();
  std::set<_point>::iterator ite = _point::all_points.end();

  double c0 = Cpu();

  const int N = _coefs->size1();
  Double_Vector val ( N ), res(_point::all_points.size());
  Double_Matrix xyz (3,3);
  Double_Matrix XYZ (_point::all_points.size(),3);

  for ( int k=0;k<3;++k)
    {
      xyz(k,0) = (*_STposX) ( ielem , k );
      xyz(k,1) = (*_STposY) ( ielem , k );
      xyz(k,2) = (*_STposZ) ( ielem , k );
    }

  for ( int k=0;k<N;++k)
    {
      val(k) = (*_STval )( ielem , k );
    }	        
  _Interpolate->mult(val,res);
  _Geometry->mult(xyz,XYZ);
  
  double c1 = Cpu();

  int kk=0;
  for ( ; it !=ite ; ++it)
    {
      _point *p = (_point*) &(*it);
      p->val = res(kk);
      p->X = XYZ(kk,0);
      p->Y = XYZ(kk,1);
      p->Z = XYZ(kk,2);
      if (min > p->val) min = p->val;
      if (max < p->val) max = p->val;
      kk++;
    }

  double c2 = Cpu();

  std::list<_triangle*>::iterator itt  = _triangle::all_triangles.begin();
  std::list<_triangle*>::iterator itte = _triangle::all_triangles.end();

  for ( ;itt != itte ; itt++)
    {
      (*itt)->visible = false;
    }


  if (plug)
    plug->assign_specific_visibility ();
  else
    {
      _triangle::Error ( max-min, tol );
    }
  double c3 = Cpu();
  itt  = _triangle::all_triangles.begin();
  for ( ;itt != itte ; itt++)
    {
      if ((*itt)->visible)
	{
	  _point *p1 = (*itt)->p[0];
	  _point *p2 = (*itt)->p[1];
	  _point *p3 = (*itt)->p[2];
	  List_Add ( view->ST , &p1->X );
	  List_Add ( view->ST , &p2->X );
	  List_Add ( view->ST , &p3->X );
	  List_Add ( view->ST , &p1->Y );
	  List_Add ( view->ST , &p2->Y );
	  List_Add ( view->ST , &p3->Y );
	  List_Add ( view->ST , &p1->Z );
	  List_Add ( view->ST , &p2->Z );
	  List_Add ( view->ST , &p3->Z );
	  List_Add ( view->ST , &p1->val );
	  List_Add ( view->ST , &p2->val );
	  List_Add ( view->ST , &p3->val );
	  view->NbST++;
	}
    }
  double c4 = Cpu();

  t0 += c1-c0;
  t1 += c2-c1;
  t2 += c3-c2;
  t3 += c4-c3;

}

void Adaptive_Post_View:: zoomQuad (Post_View * view ,
				    int ielem ,
				    int level, 
				    GMSH_Post_Plugin *plug)
{
    std::set<_point>::iterator it  = _point::all_points.begin();
    std::set<_point>::iterator ite = _point::all_points.end();
  
    double c0 = Cpu();
    
    const int N = _coefs->size1();
    Double_Vector val ( N ), res(_point::all_points.size());
    Double_Matrix xyz (4,3);
    Double_Matrix XYZ (_point::all_points.size(),3);
    
    for ( int k=0;k<4;++k)
    {
	xyz(k,0) = (*_STposX) ( ielem , k );
	xyz(k,1) = (*_STposY) ( ielem , k );
	xyz(k,2) = (*_STposZ) ( ielem , k );
    }
    
    for ( int k=0;k<N;++k)
    {
	val(k) = (*_STval )( ielem , k );
    }	        
    _Interpolate->mult(val,res);
    _Geometry->mult(xyz,XYZ);
  
    double c1 = Cpu();
    
    int kk=0;
    for ( ; it !=ite ; ++it)
    {
	_point *p = (_point*) &(*it);
	p->val = res(kk);
	p->X = XYZ(kk,0);
	p->Y = XYZ(kk,1);
	p->Z = XYZ(kk,2);
	if (min > p->val) min = p->val;
	if (max < p->val) max = p->val;
	kk++;
    }

    double c2 = Cpu();
    
    std::list<_quad*>::iterator itt  = _quad::all_quads.begin();
    std::list<_quad*>::iterator itte = _quad::all_quads.end();

    for ( ;itt != itte ; itt++)
    {
	(*itt)->visible = false;
    }
    
    
    if (plug)
	plug->assign_specific_visibility ();
    else
    {
	_quad::Error ( max-min, tol );
    }
    double c3 = Cpu();
    itt  = _quad::all_quads.begin();
    for ( ;itt != itte ; itt++)
    {
	if ((*itt)->visible)
	{
	    _point *p1 = (*itt)->p[0];
	    _point *p2 = (*itt)->p[1];
	    _point *p3 = (*itt)->p[2];
	    _point *p4 = (*itt)->p[3];
	    List_Add ( view->SQ , &p1->X );
	    List_Add ( view->SQ , &p2->X );
	    List_Add ( view->SQ , &p3->X );
	    List_Add ( view->SQ , &p4->X );
	    List_Add ( view->SQ , &p1->Y );
	    List_Add ( view->SQ , &p2->Y );
	    List_Add ( view->SQ , &p3->Y );
	    List_Add ( view->SQ , &p4->Y );
	    List_Add ( view->SQ , &p1->Z );
	    List_Add ( view->SQ , &p2->Z );
	    List_Add ( view->SQ , &p3->Z );
	    List_Add ( view->SQ , &p4->Z );
	    List_Add ( view->SQ , &p1->val );
	    List_Add ( view->SQ , &p2->val );
	    List_Add ( view->SQ , &p3->val );
	    List_Add ( view->SQ , &p4->val );
	    view->NbSQ++;
	}
    }
    double c4 = Cpu();
    
    t0 += c1-c0;
    t1 += c2-c1;
    t2 += c3-c2;
    t3 += c4-c3;    
}


void Adaptive_Post_View:: zoomTet (Post_View * view ,
				   int ielem ,
				   int level, 
				   GMSH_Post_Plugin *plug,
				   Double_Vector & va2l,
				   Double_Vector & re2s,
				   Double_Matrix & XY2Z)
{
  std::set<_point>::iterator it  = _point::all_points.begin();
  std::set<_point>::iterator ite = _point::all_points.end();


  

  double c0 = Cpu();

  Double_Matrix xyz (4,3);

  for ( int k=0;k<4;++k)
    {
      xyz(k,0) = (*_STposX) ( ielem , k );
      xyz(k,1) = (*_STposY) ( ielem , k );
      xyz(k,2) = (*_STposZ) ( ielem , k );
    }
  
  const int N = _coefs->size1();
  Double_Vector val ( N ), res(_point::all_points.size());
  Double_Matrix XYZ (_point::all_points.size(),3);

  for ( int k=0;k<N;++k)
    {
      val(k) = (*_STval )( ielem , k );
    }	        

  _Interpolate->mult(val,res);
  _Geometry->mult(xyz,XYZ);

  double c1 = Cpu();

  int kk=0;
  for ( ; it !=ite ; ++it)
    {
      _point *p = (_point*) &(*it);
      p->val = res(kk);
      p->X = XYZ(kk,0);
      p->Y = XYZ(kk,1);
      p->Z = XYZ(kk,2);
      if (min > p->val) min = p->val;
      if (max < p->val) max = p->val;
      kk++;
    }

  double c2 = Cpu();

  std::list<_tet*>::iterator itt  = _tet::all_tets.begin();
  std::list<_tet*>::iterator itte = _tet::all_tets.end();

  for ( ;itt != itte ; itt++)
    {
      (*itt)->visible = false;
    }


  if (plug)
    plug->assign_specific_visibility ();
  else
    {
      _tet::Error ( max-min, tol );
    }
  double c3 = Cpu();
  itt  = _tet::all_tets.begin();
  for ( ;itt != itte ; itt++)
    {
      if ((*itt)->visible)
	{
	  _point *p1 = (*itt)->p[0];
	  _point *p2 = (*itt)->p[1];
	  _point *p3 = (*itt)->p[2];
	  _point *p4 = (*itt)->p[3];
	  List_Add ( view->SS , &p1->X );
	  List_Add ( view->SS , &p2->X );
	  List_Add ( view->SS , &p3->X );
	  List_Add ( view->SS , &p4->X );
	  List_Add ( view->SS , &p1->Y );
	  List_Add ( view->SS , &p2->Y );
	  List_Add ( view->SS , &p3->Y );
	  List_Add ( view->SS , &p4->Y );
	  List_Add ( view->SS , &p1->Z );
	  List_Add ( view->SS , &p2->Z );
	  List_Add ( view->SS , &p3->Z );
	  List_Add ( view->SS , &p4->Z );
	  List_Add ( view->SS , &p1->val );
	  List_Add ( view->SS , &p2->val );
	  List_Add ( view->SS , &p3->val );
	  List_Add ( view->SS , &p4->val );
	  view->NbSS++;
	}
    }
  double c4 = Cpu();

  t0 += c1-c0;
  t1 += c2-c1;
  t2 += c3-c2;
  t3 += c4-c3;

}


void Adaptive_Post_View:: setAdaptiveResolutionLevel (Post_View * view , int level, GMSH_Post_Plugin *plug)
{
    const int N = _coefs->size1();

    if (presentTol==tol && presentZoomLevel == level && !plug)return;

    if (view->NbST)
    {
	_triangle::Create ( level, _coefs, _eexps );
	std::set<_point>::iterator it  = _point::all_points.begin();
	std::set<_point>::iterator ite = _point::all_points.end();
	
	if (_Interpolate)
	    delete _Interpolate;
	if (_Geometry)
	    delete _Geometry;
	_Interpolate = new Double_Matrix ( _point::all_points.size(), N);
	_Geometry    = new Double_Matrix ( _point::all_points.size(), 3);
	
	int kk=0;
	for ( ; it !=ite ; ++it)
	{
	    _point *p = (_point*) &(*it);
	    for ( int k=0;k<N;++k)
	    {
		(*_Interpolate)(kk,k) = p->shape_functions[k];
	    }
	    (*_Geometry)(kk,0) = ( 1.-p->x-p->y);
	    (*_Geometry)(kk,1) = p->x;
	    (*_Geometry)(kk,2) = p->y;
	    kk++;	  
	}
	
	List_Delete(view->ST); view->ST = 0;  
	view->NbST = 0;
	/// for now, that's all we do, 1 TS
	view->NbTimeStep=1;
	int nbelm = _STposX->size1();
	view->ST = List_Create ( nbelm * 4, nbelm , sizeof(double));
	
	
	t0=t1 = t2 = t3 = 0;
	
	for ( int i=0;i<nbelm;++i)
	{
	    zoomTriangle ( view , i , level, plug);
	}  
	
	printf("finished %g %g %g %g\n",t0,t1,t2,t3);
    }
    else if (view->NbSS)
    {
	_tet::Create ( level, _coefs, _eexps );
	std::set<_point>::iterator it  = _point::all_points.begin();
	std::set<_point>::iterator ite = _point::all_points.end();
	
	if (_Interpolate)
	    delete _Interpolate;
	if (_Geometry)
	    delete _Geometry;
	_Interpolate = new Double_Matrix ( _point::all_points.size(), N);
	_Geometry    = new Double_Matrix ( _point::all_points.size(), 4);
	
	int kk=0;
	for ( ; it !=ite ; ++it)
	{
	    _point *p = (_point*) &(*it);
	    for ( int k=0;k<N;++k)
	    {
		(*_Interpolate)(kk,k) = p->shape_functions[k];
	    }
	    (*_Geometry)(kk,0) = ( 1.-p->x-p->y-p->z);
	    (*_Geometry)(kk,1) = p->x;
	    (*_Geometry)(kk,2) = p->y;
	    (*_Geometry)(kk,3) = p->z;
	    kk++;	  
	}
	
	List_Delete(view->SS); view->SS = 0;  
	view->NbSS = 0;
	/// for now, that's all we do, 1 TS
	view->NbTimeStep=1;
	int nbelm = _STposX->size1();
	view->SS = List_Create ( nbelm * 4, nbelm , sizeof(double));
	
	
	t0=t1 = t2 = t3 = 0;
	
	Double_Vector val ( N ), res(_point::all_points.size());
	Double_Matrix XYZ (_point::all_points.size(),3);

	for ( int i=0;i<nbelm;++i)
	{
	    zoomTet ( view , i , level, plug,val,res,XYZ);
	}  
	
	printf("finished B %g %g %g %g\n",t0,t1,t2,t3);
    }
    else if (view->NbSQ)
    {
	_quad::Create ( level, _coefs, _eexps );
	std::set<_point>::iterator it  = _point::all_points.begin();
	std::set<_point>::iterator ite = _point::all_points.end();
	
	if (_Interpolate)
	    delete _Interpolate;
	if (_Geometry)
	    delete _Geometry;
	_Interpolate = new Double_Matrix ( _point::all_points.size(), N);
	_Geometry    = new Double_Matrix ( _point::all_points.size(), 4);
	
	int kk=0;
	for ( ; it !=ite ; ++it)
	{
	    _point *p = (_point*) &(*it);
	    for ( int k=0;k<N;++k)
	    {
		(*_Interpolate)(kk,k) = p->shape_functions[k];
	    }
	    (*_Geometry)(kk,0) = ( 1.-p->x) * ( 1.-p->y) * .25;
	    (*_Geometry)(kk,1) = ( 1.+p->x) * ( 1.-p->y) * .25;
	    (*_Geometry)(kk,2) = ( 1.+p->x) * ( 1.+p->y) * .25;
	    (*_Geometry)(kk,3) = ( 1.-p->x) * ( 1.+p->y) * .25;
	    kk++;	  
	}
	
	List_Delete(view->SQ); view->SQ = 0;  
	view->NbSQ = 0;
	/// for now, that's all we do, 1 TS
	view->NbTimeStep=1;
	int nbelm = _STposX->size1();
	view->SQ = List_Create ( nbelm * 4, nbelm , sizeof(double));
	
	
	t0=t1 = t2 = t3 = 0;
	
	for ( int i=0;i<nbelm;++i)
	{
	    zoomQuad ( view , i , level, plug);
	}  
	
	printf("finished Q %g %g %g %g\n",t0,t1,t2,t3);
    }
    else 
	return;
    
    view->Changed = 1;
    presentZoomLevel = level;
    presentTol = tol;    
}

void computeShapeFunctions ( Double_Matrix *coeffs, Double_Matrix *eexps , double u, double v, double w,double *sf)
{
  
  static double powsuvw[256];
  for (int j=0;j<coeffs->size2();++j)
    {
      double powu = (*eexps) ( j, 0);
      double powv = (*eexps) ( j, 1);
      double poww = (*eexps) ( j, 2);
      powsuvw[j] = pow(u,powu) * pow(v,powv) * pow(w,poww);
    }
  
  for (int i=0;i<coeffs->size1();++i)
    {
      sf[i] = 0.0;
      for (int j=0;j<coeffs->size2();++j)
	{
	  sf[i] += (*coeffs)(i,j) * powsuvw[j];
	}
    }
}

void Adaptive_Post_View:: initWithLowResolution (Post_View *view)
{

  List_T *myList;
  int nbelm;
  int nbnod;
  if (view->NbST)
    {
      myList = view->ST;
      nbelm = view->NbST;
      nbnod = 3;
    }
  else if (view->NbSS)
    {
      myList = view->SS;
      nbelm = view->NbSS;
      nbnod = 4;
    }
  else if (view->NbSQ)
    {
      myList = view->SQ;
      nbelm = view->NbSQ;
      nbnod = 4;
    }
  else return;

  min = VAL_INF;
  max = -VAL_INF;

  int nb = List_Nbr(myList) / (nbelm);

  _STposX = new Double_Matrix ( nbelm , nbnod        );
  _STposY = new Double_Matrix ( nbelm , nbnod        );
  _STposZ = new Double_Matrix ( nbelm , nbnod        );
  _STval  = new Double_Matrix ( nbelm , nb-3*nbnod   );

  /// Store non interpolated data
  int k=0;
  for (int i=0;i<List_Nbr(myList);i+=nb)
    {    
      double *x = (double*)List_Pointer_Fast (myList,i);
      double *y = (double*)List_Pointer_Fast (myList,i+nbnod); 
      double *z = (double*)List_Pointer_Fast (myList,i+2*nbnod); 
      for (int NN=0;NN<nbnod;NN++)
	{
	  (*_STposX) ( k , NN) = x[NN]; 
	  (*_STposY) ( k , NN) = y[NN]; 
	  (*_STposZ) ( k , NN) = z[NN]; 
	}
      double *val = (double*)List_Pointer_Fast (myList,i+3*nbnod);
      for (int j=0;j<nb-3*nbnod;j++){
	(*_STval)(k,j)=val[j];      
      }      
      k++;
    }
  setAdaptiveResolutionLevel(view,0);
}

Adaptive_Post_View:: Adaptive_Post_View (Post_View *view, List_T *_c , List_T *_pol)  
  : tol(1.e-3)
{

  _Interpolate = _Geometry = 0;
  _coefs = new Double_Matrix ( List_Nbr (_c) , List_Nbr (_c)  );
  _eexps  = new Double_Matrix ( List_Nbr (_c) , 3  );

  for (int i=0; i< List_Nbr ( _c ); ++i)
    {
      List_T **line = (List_T **) List_Pointer_Fast ( _c,i); 
      List_T **eexp = (List_T **) List_Pointer_Fast ( _pol,i); 

      double dpowu,dpowv,dpoww;

      List_Read (*eexp, 0, &dpowu);
      List_Read (*eexp, 1, &dpowv);
      List_Read (*eexp, 2, &dpoww);

      (*_eexps) ( i , 0 ) = dpowu;
      (*_eexps) ( i , 1 ) = dpowv;
      (*_eexps) ( i , 2 ) = dpoww;

      for (int j=0;j < List_Nbr ( *line ); ++j)
	{
	  double val;
	  List_Read ( *line, j, &val);
	  (*_coefs) ( i , j ) = val;
	}
    }
  initWithLowResolution (view);  
}

Adaptive_Post_View::~Adaptive_Post_View()
{
  delete _coefs;
  delete _eexps;
  delete _STposX;
  delete _STposY;
  delete _STposZ;
  delete _STval;
  if(_Interpolate)delete _Interpolate;
  if(_Geometry)delete _Geometry;
  _triangle::clean();
}
