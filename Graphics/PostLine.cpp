
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"

extern Context_T   CTX;
extern double      LC;

void Draw_Post_Line(Post_View *View, Post_Line *PL, 
		    double ValMin, double ValMax, double Raise[3][5]){

  int     i,k,nb=0;
  double  d,dx,dy,dz,fact;
  double  Xp[5],Yp[5],Zp[5],value[5],thev;
  char    Num[100] ;

  switch(PL->Type){	    
  case DRAW_POST_SCALAR:	    

    if(View->IntervalsType==DRAW_POST_NUMERIC){
      d = (PL->V[2*View->TimeStep]+PL->V[2*View->TimeStep+1]) / 2.;
      if(d >= ValMin && d <= ValMax){
	sprintf(Num, "%g", d);
	glColor4ubv((GLubyte*)&CTX.color.fg);
	glRasterPos3d((PL->X[0] + PL->X[1])/2.,
		      (PL->Y[0] + PL->Y[1])/2.,
		      (PL->Z[0] + PL->Z[1])/2.);
	Draw_String(Num);
      }
      break ;
    }

    glDisable(GL_LINE_STIPPLE);
    for(k=0 ; k<2 ; k++) RaiseFill(k, PL->V[2*View->TimeStep+k], ValMin, Raise);

    if(View->IntervalsType==DRAW_POST_CONTINUOUS){
      glBegin(GL_LINES);
      Palette2(View,ValMin,ValMax,PL->V[2*View->TimeStep]);
      glVertex3d(PL->X[0]+View->Offset[0]+Raise[0][0],
		 PL->Y[0]+View->Offset[1]+Raise[1][0],
		 PL->Z[0]+View->Offset[2]+Raise[2][0]);
      Palette2(View,ValMin,ValMax,PL->V[2*View->TimeStep+1]);
      glVertex3d(PL->X[1]+View->Offset[0]+Raise[0][1],
		 PL->Y[1]+View->Offset[1]+Raise[1][1],
		 PL->Z[1]+View->Offset[2]+Raise[2][1]);
      glEnd();
    }
    else{
      for(k=0 ; k<View->NbIso ; k++){
	Palette(View,View->NbIso,k);
	if(View->IntervalsType==DRAW_POST_DISCRETE){
	  CutLine1D(PL->X,PL->Y,PL->Z,&PL->V[2*View->TimeStep],
		    View->GVFI(ValMin,ValMax,View->NbIso+1,k),
		    View->GVFI(ValMin,ValMax,View->NbIso+1,k+1),
		    ValMin,ValMax,Xp,Yp,Zp,&nb,value);	  
	  if(nb == 2){
	    for(i=0;i<2;i++) RaiseFill(i,value[i],ValMin,Raise);    
	    Draw_Line(Xp,Yp,Zp,View->Offset,Raise);  
	  }
	}
	else{
	  thev = View->GVFI(ValMin,ValMax,View->NbIso,k);
	  CutLine0D(PL->X,PL->Y,PL->Z,&PL->V[2*View->TimeStep],
		    thev, ValMin,ValMax,Xp,Yp,Zp,&nb);	  
	  if(nb){
	    RaiseFill(0,thev,ValMin,Raise);
	    Draw_Point(Xp,Yp,Zp,View->Offset,Raise);    
	  }
	}
      }

    }
    break;
    
  case DRAW_POST_VECTOR:	    
    if(View->ArrowLocation == DRAW_POST_LOCATE_COG){
      dx = 0.5 * (PL->V[6*View->TimeStep]  +PL->V[6*View->TimeStep+3]);
      dy = 0.5 * (PL->V[6*View->TimeStep+1]+PL->V[6*View->TimeStep+4]);
      dz = 0.5 * (PL->V[6*View->TimeStep+2]+PL->V[6*View->TimeStep+5]);
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
		    0.5 * (PL->X[0] + PL->X[1]),
		    0.5 * (PL->Y[0] + PL->Y[1]),
		    0.5 * (PL->Z[0] + PL->Z[1]),
		    fact*d, fact*dx, fact*dy, fact*dz,
		    View->Offset, Raise);
      }
    }
    else{
      for(k=0 ; k<2 ; k++){
	dx = PL->V[6*View->TimeStep  +3*k] ;
	dy = PL->V[6*View->TimeStep+1+3*k] ;
	dz = PL->V[6*View->TimeStep+2+3*k] ;		  
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
		      PL->X[k], PL->Y[k], PL->Z[k],
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

