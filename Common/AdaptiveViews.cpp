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
#include "Views.h"

void PascalgetIndices(int iFct, int &n, int &i)
{
  int k = 0;
  int l = 0;
  while(k<=iFct)
    {
      l++;
      k +=l;
    };
  n = l - 1;
  i = l - k + iFct;
}


void Post_Zoom::interpolate (  Double_Matrix *coeffs, double u, double v, double *sf)
{
  // 2 s = (p+1) (p+2)
  // p^2 + 3p + 2 = 2s 
  // p = -3 + sqrt ( 1 + 8 s ) / 2 
  //int p = (int) ( (-3. + sqrt ( 1 + 8 * coeffs->size2())) / 2);
  int nn,ii;
  for (int i=0;i<coeffs->size1();++i)
    {
      sf[i] = 0.0;
      for (int j=0;j<coeffs->size2();++j)
	{
	  PascalgetIndices(j,nn,ii);
	  sf[i] += (*coeffs)(i,j) * pow(u,nn-ii) * pow(v,ii);
	}
    }
}

Post_Zoom::Post_Zoom ( int level , Double_Matrix *coeffs)
{
  Points = new Double_Matrix ( (level+1)*(level+2)/2 , 2);
  M      = new Double_Matrix ( (level+1)*(level+2)/2 , coeffs->size2());
  MGeom  = new Double_Matrix ( (level+1)*(level+2)/2 , 3);
  int k=0;
  double sf[256];  

  for(int i=0;i<=level;i++)
    {
      for(int j=0;j<=level-i;j++)
	{
	  (*Points) ( k , 0 ) = (double)i / (level);
	  (*Points) ( k , 1 ) = (double)j / (level);	  

	  //	  printf ("%d %g %g\n",k,(*Points) ( k , 0 ),(*Points) ( k , 1 ));

	  interpolate ( coeffs, (*Points)(k,0),(*Points)(k,1),sf );
	  for (int m=0;m<coeffs->size2();++m)(*M)(k,m)=sf[m];
	  (*MGeom)(k,0) = 1- (*Points)(k,0)- (*Points)(k,1);
	  (*MGeom)(k,1) = (*Points)(k,0);
	  (*MGeom)(k,2) = (*Points)(k,1);
	  k++;
	}
    }
  Simplices = new Int_Matrix ( level*level , 3 );
  k=0;
  int s=0;
  for(int i=0;i<=level;i++)
    {
      for(int j=0;j<=level-i;j++)
	{
	  if (j!=level-i)
	    {
	      (*Simplices) ( s , 0 )   = k;
	      (*Simplices) ( s , 1 )   = k+1;
	      (*Simplices) ( s++ , 2 ) = k+level+1-i;
	      //	      printf ("A %d %d -  %d ==> %d %d %d\n",i,j,s,k,k+1,k+level+1-i);
	    }
	  if (j+1<level-i)
	    {
	      (*Simplices) ( s , 0 )   = k+1;
	      (*Simplices) ( s , 2 )   = k+level+1-i;
	      (*Simplices) ( s++ , 1 ) = k+level-i+2;
	      //	      printf ("B %d %d - %d ==> %d %d %d\n",i,j,s,k+1,k+level+1-i,k+level-i+2);
	    }
	  k++;
	}
    }  
}

void Adaptive_Post_View:: initWithLowResolution (Post_View *view)
{

  List_T *myList = view->ST;
  int nbelm = view->NbST;
  int nbnod = 3;

  int nb = List_Nbr(myList) / (nbelm);
  //  printf("nb = %d nbelem = %d size = %d\n ",
  //	 nb,nbelm,List_Nbr(myList)); 

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
      for (int j=0;j<nb-3*nbnod;j++)(*_STval)(k,j)=val[j];      
      k++;
    }
  
  setGlobalResolutionLevel(view,1);
}

void Adaptive_Post_View:: zoomElement (Post_View * view ,
				       int ielem ,
				       Post_Zoom *zoom)
{
  static double valelem[1024];
  static double x[1024];
  static double y[1024];
  static double z[1024];

  Double_Matrix *M         = zoom->M;
  Double_Matrix *MGeom     = zoom->MGeom;
  Int_Matrix    *Simplices = zoom->Simplices;
  for ( int j=0;j<M->size1();++j)
    {
      valelem[j] = 0.0;
      x[j] = 0.0;
      y[j] = 0.0;
      z[j] = 0.0;
      for ( int k=0;k<M->size2();++k)
	{
	  valelem[j] += (*M)(j,k) * (*_STval )( ielem , k );
	  if (view->Min > valelem[j]) view->Min = valelem[j];
	  if (view->Max < valelem[j]) view->Max = valelem[j];
	}	  
      for ( int k=0;k<3;++k)
	{
	  x[j] += (*MGeom)(j,k) * (*_STposX) ( ielem , k );
	  y[j] += (*MGeom)(j,k) * (*_STposY) ( ielem , k );
	  z[j] += (*MGeom)(j,k) * (*_STposZ) ( ielem , k );
	}	  
    }
  
  for (int i=0;i<Simplices->size1();++i)
    {
      int p1 = (*Simplices) (i,0);
      int p2 = (*Simplices) (i,1);
      int p3 = (*Simplices) (i,2);
      List_Add ( view->ST , &x[p1] );
      List_Add ( view->ST , &x[p2] );
      List_Add ( view->ST , &x[p3] );
      List_Add ( view->ST , &y[p1] );
      List_Add ( view->ST , &y[p2] );
      List_Add ( view->ST , &y[p3] );
      List_Add ( view->ST , &z[p1] );
      List_Add ( view->ST , &z[p2] );
      List_Add ( view->ST , &z[p3] );
      List_Add ( view->ST , &valelem[p1] );
      List_Add ( view->ST , &valelem[p2] );
      List_Add ( view->ST , &valelem[p3] );
      view->NbST++;
    }
}

void Adaptive_Post_View:: setAdaptiveResolutionLevel (Post_View * view , int level)
{
}

void Adaptive_Post_View:: setGlobalResolutionLevel (Post_View * view , int level)
{

  printf ("asking for resolution %d\n",level);
  
  if (!view->ST)return;
  if (presentZoomLevel==level)return;
  if (!ZOOMS[level]) 
    ZOOMS[level] = new Post_Zoom ( level , _coefs);

  
  List_Delete(view->ST); view->ST = 0;
  view->NbST = 0;

  int nbelm = _STposX->size1();

  view->ST = List_Create ( nbelm * 12 * ZOOMS[level]->Simplices->size1(), 100, sizeof(double));

  for ( int i=0;i<nbelm;++i)
    {
      zoomElement ( view , i , ZOOMS[level] );
    }  
  view->Changed = 1;
  presentZoomLevel=level;
}

Adaptive_Post_View:: Adaptive_Post_View (Post_View *view, List_T *_c)  
{
  //  printf ("the view is adaptive, yeah!\n");

  for (int i=0;i<MAX_LEVEL_OF_ZOOM+1;i++) ZOOMS[i] = 0;
  _coefs = new Double_Matrix ( List_Nbr (_c) , List_Nbr (_c)  );

  //  printf ("we have a %d x %d interpolation matrix\n", List_Nbr (_c), List_Nbr (_c));

  for (int i=0; i< List_Nbr ( _c ); ++i)
    {
      List_T **line = (List_T **) List_Pointer_Fast ( _c,i); 
      for (int j=0;j < List_Nbr ( *line ); ++j)
	{
	  double val;
	  List_Read ( *line, j, &val);
	  (*_coefs) ( i , j ) = val;
	  //	  printf("%g ",val); 
	}
      //	  printf("\n "); 
    }
  //  printf("\n "); 
  initWithLowResolution (view);  
}

