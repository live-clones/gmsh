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

void computeShapeFunctions ( Double_Matrix *coeffs, Double_Matrix *eexps , double u, double v, double *sf);

std::set<_point> _point::all_points;
std::list<_triangle*> _triangle::all_triangles;

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
      computeShapeFunctions (coeffs, eexps , x,y,kkk);
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

  printf("%d _triangle and %d _point created\n",_triangle::all_triangles.size(),_point::all_points.size());
}
void _triangle::Recur_Create (_triangle *t, int maxlevel, int level , Double_Matrix *coeffs, Double_Matrix *eexps) 
{
  all_triangles.push_back(t);
  if (level++ >= maxlevel)
    return;
  
  _point *p1  = t->p[0]; 
  _point *p2  = t->p[1]; 
  _point *p3  = t->p[2]; 
  _point *p12 = _point::New ( (p1->x+p2->x)*0.5,(p1->y+p2->y)*0.5,0, coeffs, eexps);
  _point *p13 = _point::New ( (p1->x+p3->x)*0.5,(p1->y+p3->y)*0.5,0, coeffs, eexps);
  _point *p23 = _point::New ( (p3->x+p2->x)*0.5,(p3->y+p2->y)*0.5,0, coeffs, eexps);
  _triangle *t1 = new _triangle (p1,p12,p13);
  Recur_Create (t1, maxlevel,level,coeffs,eexps);
  _triangle *t2 = new _triangle (p12,p23,p2);
  Recur_Create (t2, maxlevel,level,coeffs,eexps); 
  _triangle *t3 = new _triangle (p23,p13,p3);
  Recur_Create (t3, maxlevel,level,coeffs,eexps); 
  _triangle *t4 = new _triangle (p12,p23,p13);
  Recur_Create (t4, maxlevel,level,coeffs,eexps);
  t->t[0]=t1;t->t[1]=t2;t->t[2]=t3;t->t[3]=t4;      

}

void _triangle::Error ( double AVG , double tol )
{
  _triangle *t = *all_triangles.begin();
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

static double t0,t1,t2,t3;

void Adaptive_Post_View:: zoomElement (Post_View * view ,
				       int ielem ,
				       int level, 
				       GMSH_Post_Plugin *plug)
{
  std::set<_point>::iterator it  = _point::all_points.begin();
  std::set<_point>::iterator ite = _point::all_points.end();

  clock_t c0 = clock();

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
  
  clock_t c1 = clock();

  int kk=0;
  for ( ; it !=ite ; ++it)
    {
      _point *p = (_point*) &(*it);
      p->val = res(kk);
      //      for ( int k=0;k<N;++k)
      //	{
      //	  p->val += p->shape_functions[k] * (*_STval )( ielem , k );
      //	}	        
      //      p->X = (*_STposX) ( ielem , 0 ) * ( 1.-p->x-p->y) + (*_STposX) ( ielem , 1 ) * p->x + (*_STposX) ( ielem , 2 ) * p->y;
      //      p->Y = (*_STposY) ( ielem , 0 ) * ( 1.-p->x-p->y) + (*_STposY) ( ielem , 1 ) * p->x + (*_STposY) ( ielem , 2 ) * p->y;
      //      p->Z = (*_STposZ) ( ielem , 0 ) * ( 1.-p->x-p->y) + (*_STposZ) ( ielem , 1 ) * p->x + (*_STposZ) ( ielem , 2 ) * p->y;

      p->X = XYZ(kk,0);
      p->Y = XYZ(kk,1);
      p->Z = XYZ(kk,2);

      if (min > p->val) min = p->val;
      if (max < p->val) max = p->val;
      kk++;
    }

  clock_t c2 = clock();

  std::list<_triangle*>::iterator itt  = _triangle::all_triangles.begin();
  std::list<_triangle*>::iterator itte = _triangle::all_triangles.end();

  for ( ;itt != itte ; itt++)
    {
      (*itt)->visible = false;
    }


  if (plug)
    plug->assign_specific_visibility ();
  else
    _triangle::Error ( max-min, tol );
 
  clock_t c3 = clock();
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
  clock_t c4 = clock();

  t0 += (double)(c1-c0)/CLOCKS_PER_SEC;
  t1 += (double)(c2-c1)/CLOCKS_PER_SEC;
  t2 += (double)(c3-c2)/CLOCKS_PER_SEC;
  t3 += (double)(c4-c3)/CLOCKS_PER_SEC;

}

void Adaptive_Post_View:: setAdaptiveResolutionLevel (Post_View * view , int level, GMSH_Post_Plugin *plug)
{
  if (!view->ST)return;

  if (presentTol==tol && presentZoomLevel == level && !plug)return;

  _triangle::Create ( level, _coefs, _eexps );

  std::set<_point>::iterator it  = _point::all_points.begin();
  std::set<_point>::iterator ite = _point::all_points.end();

  const int N = _coefs->size1();
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
      zoomElement ( view , i , level, plug);
    }  

  printf("finished %g %g %g %g\n",t0,t1,t2,t3);

  view->Changed = 1;
  presentZoomLevel = level;
  presentTol = tol;
}
		      
void computeShapeFunctions ( Double_Matrix *coeffs, Double_Matrix *eexps , double u, double v, double *sf)
{

  static double powsuv[256];
  for (int j=0;j<coeffs->size2();++j)
    {
      double powu = (*eexps) ( j, 0);
      double powv = (*eexps) ( j, 1);
      powsuv[j] = pow(u,powu) *pow(v,powv);
    }

  for (int i=0;i<coeffs->size1();++i)
    {
      sf[i] = 0.0;
      for (int j=0;j<coeffs->size2();++j)
	{
	  sf[i] += (*coeffs)(i,j) * powsuv[j];
	}
    }
}

void Adaptive_Post_View:: initWithLowResolution (Post_View *view)
{

  List_T *myList = view->ST;
  int nbelm = view->NbST;
  int nbnod = 3;

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
      double *x = (double*)List_Pointer_Fast (view->ST,i);
      double *y = (double*)List_Pointer_Fast (view->ST,i+nbnod); 
      double *z = (double*)List_Pointer_Fast (view->ST,i+2*nbnod); 
      (*_STposX) ( k , 0) = x[0]; (*_STposX) ( k , 1) = x[1]; (*_STposX) ( k , 2) = x[2]; 
      (*_STposY) ( k , 0) = y[0]; (*_STposY) ( k , 1) = y[1]; (*_STposY) ( k , 2) = y[2]; 
      (*_STposZ) ( k , 0) = z[0]; (*_STposZ) ( k , 1) = z[1]; (*_STposZ) ( k , 2) = z[2]; 
      double *val = (double*)List_Pointer_Fast (view->ST,i+3*nbnod);
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
