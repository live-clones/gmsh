/* $Id: PostSimplex.cpp,v 1.2 2000-11-23 14:11:32 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"

extern Context_T   CTX;
extern double      LC;

void Draw_Post_Simplex(Post_View *View, Post_Simplex *PS, 
		       double ValMin, double ValMax, double Raise[3][5]){

  int     k;
  double  d,dx,dy,dz,fact;

  switch(PS->Type){
  case DRAW_POST_SCALAR:	    
    for(k=0 ; k<View->NbIso ; k++){
      Palette(View,View->NbIso,k);
      IsoSimplex(PS->X, PS->Y, PS->Z, &PS->V[4*View->TimeStep],
		 View->GVFI(ValMin,ValMax,View->NbIso,k), 
		 ValMin, ValMax, View->Offset, Raise, View->Light);
    }
    break;
    
    /* 
       la plus grande fleche (d=ValMax) est de taille LC/50
       (View->ArrowScale == 100 par defaut)
       */
    
  case DRAW_POST_VECTOR:	    
    if(View->ArrowLocation == DRAW_POST_LOCATE_COG){
      dx = 0.25 * (PS->V[12*View->TimeStep]  +PS->V[12*View->TimeStep+3]+
		   PS->V[12*View->TimeStep+6]+PS->V[12*View->TimeStep+9] );
      dy = 0.25 * (PS->V[12*View->TimeStep+1]+PS->V[12*View->TimeStep+4]+
		   PS->V[12*View->TimeStep+7]+PS->V[12*View->TimeStep+10] );
      dz = 0.25 * (PS->V[12*View->TimeStep+2]+PS->V[12*View->TimeStep+5]+
		   PS->V[12*View->TimeStep+8]+PS->V[12*View->TimeStep+11] );
      d = sqrt(dx*dx+dy*dy+dz*dz);
      
      if(d!=0.0 && d>=ValMin && d<=ValMax){		
	Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
	fact = 2.e-4 * LC * View->ArrowScale/View->Max ;		
	if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	  dx /= d ; dy /= d ; dz /= d ;
	  d = log10(d/ValMin) ; 
	  dx *= d ; dy *= d ; dz *= d ;
	}
	RaiseFill(0, d, ValMin, Raise);		
	Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
		    0.25 * (PS->X[0] + PS->X[1] + PS->X[2] + PS->X[3]),
		    0.25 * (PS->Y[0] + PS->Y[1] + PS->Y[2] + PS->Y[3]),
		    0.25 * (PS->Z[0] + PS->Z[1] + PS->Z[2] + PS->Z[3]),
		    fact*d, fact*dx, fact*dy, fact*dz,
		    View->Offset, Raise);
      }
    }
    else{
      for(k=0 ; k<4 ; k++){
	dx = PS->V[12*View->TimeStep  +3*k] ;
	dy = PS->V[12*View->TimeStep+1+3*k] ;
	dz = PS->V[12*View->TimeStep+2+3*k] ;		  
	d = sqrt(dx*dx+dy*dy+dz*dz);
	
	if(d!=0.0 && d>=ValMin && d<=ValMax){	  
	  Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
	  fact = 2.e-4 * LC * View->ArrowScale/View->Max ;		
	  if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	    dx /= d ; dy /= d ; dz /= d ;
	    d = log10(d/ValMin) ; 
	    dx *= d ; dy *= d ; dz *= d ;
	  }
	  RaiseFill(0, d, ValMin, Raise);		
	  Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
		      PS->X[k], PS->Y[k], PS->Z[k],
		      fact*d, fact*dx, fact*dy, fact*dz,
		      View->Offset, Raise);
	}		
      }	      
    }
    break;
    
  case DRAW_POST_TENSOR :
    break;
    
  }

}

