//
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

// Don't indent this file
// *INDENT-OFF*
				       
#include <stdio.h>
#include <math.h>
#include <list>
#include <set>
#include "AdaptiveViews.h"
#include "Plugin.h"

// A recursive effective implementation

void computeShapeFunctions ( Double_Matrix *coeffs, Double_Matrix *eexps , double u, double v, double w,double *sf);

std::set<adapt_point> adapt_point::all_points;
std::list<adapt_triangle*> adapt_triangle::all_elems;
std::list<adapt_tet*> adapt_tet::all_elems;
std::list<adapt_quad*> adapt_quad::all_elems;
std::list<adapt_hex*> adapt_hex::all_elems;
#define MAX_NB_NOD 8
int adapt_triangle::nbNod = 3;
int adapt_tet::nbNod = 4;
int adapt_quad::nbNod = 4;
int adapt_hex::nbNod = 8;

adapt_point * adapt_point::New ( double x, double y, double z, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  adapt_point p;
  p.x=x; p.y=y; p.z=z;
  std::set<adapt_point> :: iterator it = all_points.find ( p );
  if ( it == all_points.end() )
    {
      all_points.insert (p);
      it = all_points.find ( p );
      double *kkk = (double*)(it->shape_functions);
      computeShapeFunctions (coeffs, eexps , x,y,z,kkk);
      return (adapt_point*) & (*it);
    }
  else
    return (adapt_point*) & (*it);
}


void adapt_triangle::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  printf("creating the sub-elements\n");
  int level = 0;
  cleanElement<adapt_triangle> ();
  adapt_point *p1 = adapt_point::New ( 0,0,0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New ( 0,1,0, coeffs, eexps);
  adapt_point *p3 = adapt_point::New ( 1,0,0, coeffs, eexps);
  adapt_triangle *t = new adapt_triangle(p1,p2,p3);
  Recur_Create (t, maxlevel,level,coeffs,eexps) ;
}

void adapt_quad::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  printf("creating the sub-elements\n");
  int level = 0;
  cleanElement<adapt_quad> ();
  adapt_point *p1 = adapt_point::New ( -1,-1,0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New ( -1,1,0, coeffs, eexps);
  adapt_point *p3 = adapt_point::New ( 1,1,0, coeffs, eexps);
  adapt_point *p4 = adapt_point::New ( 1,-1,0, coeffs, eexps);
  adapt_quad *q = new adapt_quad(p1,p2,p3,p4);
  Recur_Create (q, maxlevel,level,coeffs,eexps) ;
}

void adapt_tet::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  Msg(INFO, "creating sub-elements");
  int level = 0;
  cleanElement<adapt_tet> ();
  adapt_point *p1 = adapt_point::New ( 0,0,0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New ( 0,1,0, coeffs, eexps);
  adapt_point *p3 = adapt_point::New ( 1,0,0, coeffs, eexps);
  adapt_point *p4 = adapt_point::New ( 0,0,1, coeffs, eexps);
  adapt_tet *t = new adapt_tet(p1,p2,p3,p4);
  Recur_Create (t, maxlevel,level,coeffs,eexps) ;
}

void adapt_hex::Create (int maxlevel, Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  Msg(INFO, "creating sub-elements");
  int level = 0;
  cleanElement<adapt_hex> ();
  adapt_point *p1 = adapt_point::New ( -1,-1,-1, coeffs, eexps);
  adapt_point *p2 = adapt_point::New ( -1,1,-1, coeffs, eexps);
  adapt_point *p3 = adapt_point::New ( 1,1,-1, coeffs, eexps);
  adapt_point *p4 = adapt_point::New ( 1,-1,-1, coeffs, eexps);
  adapt_point *p11 = adapt_point::New ( -1,-1,1, coeffs, eexps);
  adapt_point *p21 = adapt_point::New ( -1,1,1, coeffs, eexps);
  adapt_point *p31 = adapt_point::New ( 1,1,1, coeffs, eexps);
  adapt_point *p41= adapt_point::New ( 1,-1,1, coeffs, eexps);
  adapt_hex *h = new adapt_hex(p1,p2,p3,p4,p11,p21,p31,p41);
  Recur_Create (h, maxlevel,level,coeffs,eexps) ;
}

void adapt_triangle::Recur_Create (adapt_triangle *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_elems.push_back(t);
  if (level++ >= maxlevel)
    return;

  /*

  p3


  p13   p23


  p1    p12    p2


  */
  
  adapt_point *p1  = t->p[0]; 
  adapt_point *p2  = t->p[1]; 
  adapt_point *p3  = t->p[2]; 
  adapt_point *p12 = adapt_point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,0, coeffs, eexps);
  adapt_point *p13 = adapt_point::New ( (p1->x+p3->x)*0.5,(p1->y+p3->y)*0.5,0, coeffs, eexps);
  adapt_point *p23 = adapt_point::New ( (p3->x+p2->x)*0.5,(p3->y+p2->y)*0.5,0, coeffs, eexps);
  adapt_triangle *t1 = new adapt_triangle (p1,p13,p12);
  Recur_Create (t1, maxlevel,level,coeffs,eexps);
  adapt_triangle *t2 = new adapt_triangle (p12,p23,p2);
  Recur_Create (t2, maxlevel,level,coeffs,eexps); 
  adapt_triangle *t3 = new adapt_triangle (p23,p13,p3);
  Recur_Create (t3, maxlevel,level,coeffs,eexps); 
  adapt_triangle *t4 = new adapt_triangle (p12,p13,p23);
  Recur_Create (t4, maxlevel,level,coeffs,eexps);
  t->t[0]=t1;t->t[1]=t2;t->t[2]=t3;t->t[3]=t4;      

}

void adapt_quad::Recur_Create (adapt_quad *q, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_elems.push_back(q);
  if (level++ >= maxlevel)
    return;

  /*

  p2   p23    p3


  p12  pc     p34


  p1    p14    p4


  */
  
  adapt_point *p1  = q->p[0]; 
  adapt_point *p2  = q->p[1]; 
  adapt_point *p3  = q->p[2]; 
  adapt_point *p4  = q->p[3]; 
  adapt_point *p12 = adapt_point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,0, coeffs, eexps);
  adapt_point *p23 = adapt_point::New ( (p2->x+p3->x)*0.5,(p2->y+p3->y)*0.5,0, coeffs, eexps);
  adapt_point *p34 = adapt_point::New ( (p4->x+p3->x)*0.5,(p4->y+p3->y)*0.5,0, coeffs, eexps);
  adapt_point *p14 = adapt_point::New ( (p1->x+p4->x)*0.5,(p1->y+p4->y)*0.5,0, coeffs, eexps);
  adapt_point *pc = adapt_point::New (  (p1->x+p2->x+p3->x+p4->x)*0.25,(p1->y+p2->y+p3->y+p4->y)*0.25,0, coeffs, eexps);
  adapt_quad *q1 = new adapt_quad (p1,p12,pc,p14);
  Recur_Create (q1, maxlevel,level,coeffs,eexps);
  adapt_quad *q2 = new adapt_quad (p12,p2,p23,pc);
  Recur_Create (q2, maxlevel,level,coeffs,eexps);
  adapt_quad *q3 = new adapt_quad (pc,p23,p3,p34);
  Recur_Create (q3, maxlevel,level,coeffs,eexps);
  adapt_quad *q4 = new adapt_quad (p14,pc,p34,p4);
  Recur_Create (q4, maxlevel,level,coeffs,eexps);
  q->q[0]=q1;q->q[1]=q2;q->q[2]=q3;q->q[3]=q4;      

}

void adapt_tet::Recur_Create (adapt_tet *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_elems.push_back(t);
  if (level++ >= maxlevel)
    return;

  adapt_point *p0  = t->p[0]; 
  adapt_point *p1  = t->p[1]; 
  adapt_point *p2  = t->p[2]; 
  adapt_point *p3  = t->p[3]; 
  adapt_point *pe0 = adapt_point::New ( (p0->x+p1->x)*0.5,(p0->y+p1->y)*0.5,(p0->z+p1->z)*0.5,coeffs, eexps);
  adapt_point *pe1 = adapt_point::New ( (p0->x+p2->x)*0.5,(p0->y+p2->y)*0.5,(p0->z+p2->z)*0.5,coeffs, eexps);
  adapt_point *pe2 = adapt_point::New ( (p0->x+p3->x)*0.5,(p0->y+p3->y)*0.5,(p0->z+p3->z)*0.5,coeffs, eexps);
  adapt_point *pe3 = adapt_point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,(p1->z+p2->z)*0.5,coeffs, eexps);
  adapt_point *pe4 = adapt_point::New ( (p1->x+p3->x)*0.5,(p1->y+p3->y)*0.5,(p1->z+p3->z)*0.5,coeffs, eexps);
  adapt_point *pe5 = adapt_point::New ( (p2->x+p3->x)*0.5,(p2->y+p3->y)*0.5,(p2->z+p3->z)*0.5,coeffs, eexps);

  adapt_tet *t1 = new adapt_tet (p0,pe0,pe2,pe1);
  Recur_Create (t1, maxlevel,level,coeffs,eexps);
  adapt_tet *t2 = new adapt_tet (p1,pe0,pe3,pe4);
  Recur_Create (t2, maxlevel,level,coeffs,eexps);
  adapt_tet *t3 = new adapt_tet (p2,pe3,pe1,pe5);
  Recur_Create (t3, maxlevel,level,coeffs,eexps);
  adapt_tet *t4 = new adapt_tet (p3,pe2,pe4,pe5);
  Recur_Create (t4, maxlevel,level,coeffs,eexps);

  adapt_tet *t5 = new adapt_tet (pe3,pe5,pe2,pe4);
  Recur_Create (t5, maxlevel,level,coeffs,eexps);
  adapt_tet *t6 = new adapt_tet (pe3,pe2,pe0,pe4);
  Recur_Create (t6, maxlevel,level,coeffs,eexps);
  adapt_tet *t7 = new adapt_tet (pe2,pe5,pe3,pe1);
  Recur_Create (t7, maxlevel,level,coeffs,eexps);
  adapt_tet *t8 = new adapt_tet (pe0,pe2,pe3,pe1);
  Recur_Create (t8, maxlevel,level,coeffs,eexps);

  t->t[0]=t1;t->t[1]=t2;t->t[2]=t3;t->t[3]=t4;      
  t->t[4]=t5;t->t[5]=t6;t->t[6]=t7;t->t[7]=t8;      
}


void adapt_hex::Recur_Create (adapt_hex *h, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_elems.push_back(h);
  if (level++ >= maxlevel)
    return;

  adapt_point *p0  = h->p[0]; 
  adapt_point *p1  = h->p[1]; 
  adapt_point *p2  = h->p[2]; 
  adapt_point *p3  = h->p[3]; 
  adapt_point *p4  = h->p[4]; 
  adapt_point *p5  = h->p[5]; 
  adapt_point *p6  = h->p[6]; 
  adapt_point *p7  = h->p[7]; 
  adapt_point *p01 = adapt_point::New ( (p0->x+p1->x)*0.5,(p0->y+p1->y)*0.5,(p0->z+p1->z)*0.5,coeffs, eexps);
  adapt_point *p12 = adapt_point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,(p1->z+p2->z)*0.5,coeffs, eexps);
  adapt_point *p23 = adapt_point::New ( (p2->x+p3->x)*0.5,(p2->y+p3->y)*0.5,(p2->z+p3->z)*0.5,coeffs, eexps);
  adapt_point *p03 = adapt_point::New ( (p3->x+p0->x)*0.5,(p3->y+p0->y)*0.5,(p3->z+p0->z)*0.5,coeffs, eexps);
  adapt_point *p45 = adapt_point::New ( (p4->x+p5->x)*0.5,(p4->y+p5->y)*0.5,(p4->z+p5->z)*0.5,coeffs, eexps);
  adapt_point *p56 = adapt_point::New ( (p5->x+p6->x)*0.5,(p5->y+p6->y)*0.5,(p5->z+p6->z)*0.5,coeffs, eexps);
  adapt_point *p67 = adapt_point::New ( (p6->x+p7->x)*0.5,(p6->y+p7->y)*0.5,(p6->z+p7->z)*0.5,coeffs, eexps);
  adapt_point *p47 = adapt_point::New ( (p7->x+p4->x)*0.5,(p7->y+p4->y)*0.5,(p7->z+p4->z)*0.5,coeffs, eexps);
  adapt_point *p04 = adapt_point::New ( (p4->x+p0->x)*0.5,(p4->y+p0->y)*0.5,(p4->z+p0->z)*0.5,coeffs, eexps);
  adapt_point *p15 = adapt_point::New ( (p5->x+p1->x)*0.5,(p5->y+p1->y)*0.5,(p5->z+p1->z)*0.5,coeffs, eexps);
  adapt_point *p26 = adapt_point::New ( (p6->x+p2->x)*0.5,(p6->y+p2->y)*0.5,(p6->z+p2->z)*0.5,coeffs, eexps);
  adapt_point *p37 = adapt_point::New ( (p7->x+p3->x)*0.5,(p7->y+p3->y)*0.5,(p7->z+p3->z)*0.5,coeffs, eexps);

  adapt_point *p0145 = adapt_point::New ( (p45->x+p01->x)*0.5,(p45->y+p01->y)*0.5,(p45->z+p01->z)*0.5,coeffs, eexps);
  adapt_point *p1256 = adapt_point::New ( (p12->x+p56->x)*0.5,(p12->y+p56->y)*0.5,(p12->z+p56->z)*0.5,coeffs, eexps);
  adapt_point *p2367 = adapt_point::New ( (p23->x+p67->x)*0.5,(p23->y+p67->y)*0.5,(p23->z+p67->z)*0.5,coeffs, eexps);
  adapt_point *p0347 = adapt_point::New ( (p03->x+p47->x)*0.5,(p03->y+p47->y)*0.5,(p03->z+p47->z)*0.5,coeffs, eexps);
  adapt_point *p4756 = adapt_point::New ( (p47->x+p56->x)*0.5,(p47->y+p56->y)*0.5,(p47->z+p56->z)*0.5,coeffs, eexps);
  adapt_point *p0312 = adapt_point::New ( (p03->x+p12->x)*0.5,(p03->y+p12->y)*0.5,(p03->z+p12->z)*0.5,coeffs, eexps);

  adapt_point *pc = adapt_point::New ( (p0->x+p1->x+p2->x+p3->x+p4->x+p5->x+p6->x+p7->x)*0.125,
				(p0->y+p1->y+p2->y+p3->y+p4->y+p5->y+p6->y+p7->y)*0.125,
				(p0->z+p1->z+p2->z+p3->z+p4->z+p5->z+p6->z+p7->z)*0.125,
				coeffs, eexps);

  adapt_hex *h1 = new adapt_hex (p0,p01,p0312,p03,p04,p0145,pc,p0347);//p0
  Recur_Create (h1, maxlevel,level,coeffs,eexps);
  adapt_hex *h2 = new adapt_hex (p01,p0145,p15,p1,p0312,pc,p1256,p12);//p1
  Recur_Create (h2, maxlevel,level,coeffs,eexps);
  adapt_hex *h3 = new adapt_hex (p04,p4,p45,p0145,p0347,p47,p4756,pc);//p4
  Recur_Create (h3, maxlevel,level,coeffs,eexps);
  adapt_hex *h4 = new adapt_hex (p0145,p45,p5,p15,pc,p4756,p56,p1256);//p5
  Recur_Create (h4, maxlevel,level,coeffs,eexps);
  adapt_hex *h5 = new adapt_hex (p0347,p47,p4756,pc,p37,p7,p67,p2367);//p7
  Recur_Create (h5, maxlevel,level,coeffs,eexps);
  adapt_hex *h6 = new adapt_hex (pc,p4756,p56,p1256,p2367,p67,p6,p26);//p6
  Recur_Create (h6, maxlevel,level,coeffs,eexps);
  adapt_hex *h7 = new adapt_hex (p03,p0347,pc,p0312,p3,p37,p2367,p23);//p3
  Recur_Create (h7, maxlevel,level,coeffs,eexps);
  adapt_hex *h8 = new adapt_hex (p0312,pc,p1256,p12,p23,p2367,p26,p2);//p2
  Recur_Create (h8, maxlevel,level,coeffs,eexps);

  h->h[0]=h1;h->h[1]=h2;h->h[2]=h3;h->h[3]=h4;      
  h->h[4]=h5;h->h[5]=h6;h->h[6]=h7;h->h[7]=h8;      
}


void adapt_triangle::Error ( double AVG , double tol )
{
  adapt_triangle *t = *all_elems.begin();
  Recur_Error (t,AVG,tol);
}

void adapt_quad::Error ( double AVG , double tol )
{
  adapt_quad *q = *all_elems.begin();
  Recur_Error (q,AVG,tol);
}

void adapt_tet::Error ( double AVG , double tol )
{
  adapt_tet *t = *all_elems.begin();
  Recur_Error (t,AVG,tol);
}
void adapt_hex::Error ( double AVG , double tol )
{
  adapt_hex *h = *all_elems.begin();
  Recur_Error (h,AVG,tol);
}

void adapt_triangle::Recur_Error ( adapt_triangle *t, double AVG, double tol )
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

void adapt_quad::Recur_Error ( adapt_quad *q, double AVG, double tol )
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


void adapt_tet::Recur_Error ( adapt_tet *t, double AVG, double tol )
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

void adapt_hex::Recur_Error ( adapt_hex *h, double AVG, double tol )
{
  if(!h->h[0])h->visible = true; 
  else
    {
      double vr;
      double v1 = h->h[0]->V();
      double v2 = h->h[1]->V();
      double v3 = h->h[2]->V();
      double v4 = h->h[3]->V();
      double v5 = h->h[4]->V();
      double v6 = h->h[5]->V();
      double v7 = h->h[6]->V();
      double v8 = h->h[7]->V();
      vr = (v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8)*.125;
      double v =  h->V();
      if ( fabs(v - vr) > AVG * tol ) 
	{
	  h->visible = false;
	  Recur_Error (h->h[0],AVG,tol);
	  Recur_Error (h->h[1],AVG,tol);
	  Recur_Error (h->h[2],AVG,tol);
	  Recur_Error (h->h[3],AVG,tol);
	  Recur_Error (h->h[4],AVG,tol);
	  Recur_Error (h->h[5],AVG,tol);
	  Recur_Error (h->h[6],AVG,tol);
	  Recur_Error (h->h[7],AVG,tol);
	} 
      else
	h->visible = true;
    }
}

static double t0,t1,t2,t3;

template <class ELEM>
void Adaptive_Post_View:: zoomElement (Post_View * view ,
					int ielem ,
					int level, 
					GMSH_Post_Plugin *plug,
					List_T *theList,
					int *counter)
{

  const int nbNod = ELEM::nbNod; 

  typename std::set<adapt_point>::iterator it  = adapt_point::all_points.begin();
  typename std::set<adapt_point>::iterator ite = adapt_point::all_points.end();

  double c0 = Cpu();

  const int N = _coefs->size1();
  Double_Vector val ( N ), res(adapt_point::all_points.size());
  Double_Matrix xyz (nbNod,3);
  Double_Matrix XYZ (adapt_point::all_points.size(),3);

  for ( int k=0;k<nbNod;++k)
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
      adapt_point *p = (adapt_point*) &(*it);
      p->val = res(kk);
      p->X = XYZ(kk,0);
      p->Y = XYZ(kk,1);
      p->Z = XYZ(kk,2);
      if (min > p->val) min = p->val;
      if (max < p->val) max = p->val;
      kk++;
    }

  double c2 = Cpu();

  typename std::list<ELEM*>::iterator itt  = ELEM::all_elems.begin();
  typename std::list<ELEM*>::iterator itte = ELEM::all_elems.end();

  for ( ;itt != itte ; itt++)
    {
      (*itt)->visible = false;
    }


  if (!plug || tol != 0.0)
  {
      ELEM::Error ( max-min, tol );
  }
  if (plug)
      plug->assign_specific_visibility ();


  double c3 = Cpu();
  itt  = ELEM::all_elems.begin();

  adapt_point **p;

  for ( ;itt != itte ; itt++)
    {
      if ((*itt)->visible)
	{
	  p = (*itt)->p;
	  for (int k=0;k<nbNod;++k)List_Add ( theList , &p[k]->X );
	  for (int k=0;k<nbNod;++k)List_Add ( theList , &p[k]->Y );
	  for (int k=0;k<nbNod;++k)List_Add ( theList , &p[k]->Z );
	  for (int k=0;k<nbNod;++k)List_Add ( theList , &p[k]->val );
	  (*counter)++;
	}
    }
  double c4 = Cpu();

  t0 += c1-c0;
  t1 += c2-c1;
  t2 += c3-c2;
  t3 += c4-c3;

}


/*
  We first do the adaptive stuff at level 2 and will only process
  elements that have reached the maximal recursion level

  We compute first the matrix at max recursion level (those should be stored
  on disk once in the GMSHPLUGINSHOME directory, i'll do that at some point).

  

*/


void Adaptive_Post_View:: setAdaptiveResolutionLevel (Post_View * view , int level, GMSH_Post_Plugin *plug)
{
  setAdaptiveResolutionLevel_TEMPL <adapt_triangle> ( view,level,plug,&(view->ST),&(view->NbST)) ;
  setAdaptiveResolutionLevel_TEMPL <adapt_quad>     ( view,level,plug,&(view->SQ),&(view->NbSQ)) ;
  setAdaptiveResolutionLevel_TEMPL <adapt_hex>      ( view,level,plug,&(view->SH),&(view->NbSH)) ;
  setAdaptiveResolutionLevel_TEMPL <adapt_tet>      ( view,level,plug,&(view->SS),&(view->NbSS)) ;
}

template <class ELEM>
void Adaptive_Post_View:: setAdaptiveResolutionLevel_TEMPL (Post_View * view , int level, GMSH_Post_Plugin *plug, List_T **myList, int *counter)
{
  const int N = _coefs->size1();
  
  printf("coucou %d %d\n",*counter, ELEM::nbNod);

  if (presentTol==tol && presentZoomLevel == level && !plug)return;
  
  if (*counter)
    {
      //double sf[ELEM::nbNod]; // does not compile on my mac (iso c++
      //forbids variable-size arrays)
      double sf[MAX_NB_NOD];
      ELEM::Create ( level, _coefs, _eexps );
      std::set<adapt_point>::iterator it  = adapt_point::all_points.begin();
      std::set<adapt_point>::iterator ite = adapt_point::all_points.end();
      
      if (_Interpolate)
	delete _Interpolate;
      if (_Geometry)
	delete _Geometry;
      _Interpolate = new Double_Matrix ( adapt_point::all_points.size(), N);
      _Geometry    = new Double_Matrix ( adapt_point::all_points.size(), ELEM::nbNod);
      
      int kk=0;
      for ( ; it !=ite ; ++it)
	{
	  adapt_point *p = (adapt_point*) &(*it);
	  for ( int k=0;k<N;++k)
	    {
	      (*_Interpolate)(kk,k) = p->shape_functions[k];
	    }
	  ELEM::GSF ( p->x, p->y,p->z,sf);
	  for (int k=0;k<ELEM::nbNod;k++)(*_Geometry)(kk,k) = sf[k];
	  kk++;	  
	}
	
	List_Delete(*myList); *myList = 0;  
	*counter = 0;
	/// for now, that's all we do, 1 TS
	view->NbTimeStep=1;
	int nbelm = _STposX->size1();
	*myList = List_Create ( nbelm * 4, nbelm , sizeof(double));	
	
	t0=t1 = t2 = t3 = 0;
	
	for ( int i=0;i<nbelm;++i)
	{
	  zoomElement<ELEM> ( view , i , level, plug,*myList,counter);
	}  	
	printf("finished %g %g %g %g\n",t0,t1,t2,t3);
	view->Changed = 1;
	presentZoomLevel = level;
	presentTol = tol;    
    }
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
  else if (view->NbSH)
    {
      myList = view->SH;
      nbelm = view->NbSH;
      nbnod = 8;
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
  cleanElement<adapt_triangle> ();
  cleanElement<adapt_tet> ();
  cleanElement<adapt_hex> ();
  cleanElement<adapt_quad> ();
}
