
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"

extern Context_T   CTX;
extern double      LC;

void Draw_Post_Triangle(Post_View *View, Post_Triangle *PT, 
			double ValMin, double ValMax, double Raise[3][5]){

  int     i, k, m, nb=0;
  double  d,dx,dy,dz,fact;
  double  x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, nn[3];
  double  xx[3],yy[3],zz[3];
  double  Xp[5],Yp[5],Zp[5],value[5],thev;
  char    Num[100] ;

  if(View->ShowElement)
    glEnable(GL_POLYGON_OFFSET_FILL);

  switch(PT->Type){	    
    
  case DRAW_POST_SCALAR:

    if(View->IntervalsType==DRAW_POST_NUMERIC){
      d = (PT->V[3*View->TimeStep]+PT->V[3*View->TimeStep+1]+PT->V[3*View->TimeStep+2]) / 3.;
      if(d >= ValMin && d <= ValMax){
	sprintf(Num, "%g", d);
	glColor4ubv((GLubyte*)&CTX.color.fg);
	glRasterPos3d((PT->X[0] + PT->X[1] + PT->X[2])/3.,
		      (PT->Y[0] + PT->Y[1] + PT->Y[2])/3.,
		      (PT->Z[0] + PT->Z[1] + PT->Z[2])/3.);
	Draw_String(Num);
      }
      break ;
    }

    if(View->IntervalsType!=DRAW_POST_ISO)
      for(i=0;i<3;i++)RaiseFill(i, PT->V[3*View->TimeStep+i], ValMin, Raise);
    
    if(View->Light){
      x1x0 = (PT->X[1]+Raise[0][1]) - (PT->X[0]+Raise[0][0]); 
      y1y0 = (PT->Y[1]+Raise[1][1]) - (PT->Y[0]+Raise[1][0]);
      z1z0 = (PT->Z[1]+Raise[2][1]) - (PT->Z[0]+Raise[2][0]); 
      x2x0 = (PT->X[2]+Raise[0][2]) - (PT->X[0]+Raise[0][0]);
      y2y0 = (PT->Y[2]+Raise[1][2]) - (PT->Y[0]+Raise[1][0]); 
      z2z0 = (PT->Z[2]+Raise[2][2]) - (PT->Z[0]+Raise[2][0]);
      nn[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
      nn[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
      nn[2]  = x1x0 * y2y0 - y1y0 * x2x0 ;
      //norme(nn); unnecessary with   glEnable(GL_NORMALIZE);
      /* BOF BOF BOF 
      if(nn[2] < -0.1){
	nn[0] = -nn[0];
	nn[1] = -nn[1];
	nn[2] = -nn[2];
      }
      */
      glNormal3dv(nn);
    }

    if(View->IntervalsType==DRAW_POST_CONTINUOUS){
      if(PT->V[3*View->TimeStep]  >=ValMin && PT->V[3*View->TimeStep]  <=ValMax &&
	 PT->V[3*View->TimeStep+1]>=ValMin && PT->V[3*View->TimeStep+1]<=ValMax &&
	 PT->V[3*View->TimeStep+2]>=ValMin && PT->V[3*View->TimeStep+2]<=ValMax){
	glBegin(GL_TRIANGLES);
	Palette2(View,ValMin,ValMax,PT->V[3*View->TimeStep]);
	glVertex3d(PT->X[0]+View->Offset[0]+Raise[0][0],
		   PT->Y[0]+View->Offset[1]+Raise[1][0],
		   PT->Z[0]+View->Offset[2]+Raise[2][0]);
	Palette2(View,ValMin,ValMax,PT->V[3*View->TimeStep+1]);
	glVertex3d(PT->X[1]+View->Offset[0]+Raise[0][1],
		   PT->Y[1]+View->Offset[1]+Raise[1][1],
		   PT->Z[1]+View->Offset[2]+Raise[2][1]);
	Palette2(View,ValMin,ValMax,PT->V[3*View->TimeStep+2]);
	glVertex3d(PT->X[2]+View->Offset[0]+Raise[0][2],
		   PT->Y[2]+View->Offset[1]+Raise[1][2],
		   PT->Z[2]+View->Offset[2]+Raise[2][2]);
	glEnd();
      }
      else{
	CutTriangle2D(PT->X,PT->Y,PT->Z,&PT->V[3*View->TimeStep],
		      ValMin,ValMax,ValMin,ValMax,
		      Xp,Yp,Zp,&nb,value);
	if(nb >= 3){	  
	  glBegin(GL_POLYGON);
	  for(i=0;i<nb;i++){
	    Palette2(View,ValMin,ValMax,value[i]);
	    RaiseFill(i,value[i],ValMin,Raise);
	    glVertex3d(Xp[i]+View->Offset[0]+Raise[0][i],
		       Yp[i]+View->Offset[1]+Raise[1][i],
		       Zp[i]+View->Offset[2]+Raise[2][i]);
	  }
	  glEnd();
	}
      }
    }
    else{
      for(k=0 ; k<View->NbIso ; k++){
	if(View->IntervalsType==DRAW_POST_DISCRETE){
	  Palette(View,View->NbIso,k);
	  CutTriangle2D(PT->X,PT->Y,PT->Z,&PT->V[3*View->TimeStep],
			View->GVFI(ValMin,ValMax,View->NbIso+1,k),
			View->GVFI(ValMin,ValMax,View->NbIso+1,k+1),
			ValMin,ValMax,
			Xp,Yp,Zp,&nb,value);	  
	  if(nb >= 3){
	    for(i=0;i<nb;i++) RaiseFill(i,value[i],ValMin,Raise);    
	    Draw_Polygon(nb,Xp,Yp,Zp,View->Offset,Raise);  
	  }
	}
	else{
	  Palette(View,View->NbIso,k);

	  thev = View->GVFI(ValMin,ValMax,View->NbIso,k);
	  CutTriangle1D(PT->X,PT->Y,PT->Z,&PT->V[3*View->TimeStep],
			thev, ValMin,ValMax,Xp,Yp,Zp,&nb);	  
	  if(nb == 2){
	    for(i=0;i<2;i++) RaiseFill(i,thev,ValMin,Raise);
	    Draw_Line(Xp,Yp,Zp,View->Offset,Raise);    
	  }
	}
      }
    }
    break;
    
  case DRAW_POST_VECTOR:
    
    if(View->ArrowType == DRAW_POST_DISPLACEMENT){
      fact = View->ArrowScale/100. ;
      for(m=0;m<3;m++){
	xx[m] = PT->X[m] + fact * PT->V[9*View->TimeStep + 3 * m ];
	yy[m] = PT->Y[m] + fact * PT->V[9*View->TimeStep + 3 * m + 1];
	zz[m] = PT->Z[m] + fact * PT->V[9*View->TimeStep + 3 * m + 2];
      }
      glEnable(GL_POLYGON_OFFSET_FILL);
      glColor4ubv((GLubyte*)&CTX.color.bg);
      if(View->IntervalsType!=DRAW_POST_ISO)
	Draw_Polygon (3, xx, yy, zz, View->Offset, Raise);
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINE_LOOP);
      for(m=0 ; m<3 ; m++) glVertex3d(xx[m], yy[m], zz[m]);
      glEnd();
      glDisable(GL_POLYGON_OFFSET_FILL);      
      break;
    }
    
    if(View->ArrowLocation == DRAW_POST_LOCATE_COG){
      dx = (PT->V[9*View->TimeStep]  +PT->V[9*View->TimeStep+3]+PT->V[9*View->TimeStep+6])/3.;
      dy = (PT->V[9*View->TimeStep+1]+PT->V[9*View->TimeStep+4]+PT->V[9*View->TimeStep+7])/3.;
      dz = (PT->V[9*View->TimeStep+2]+PT->V[9*View->TimeStep+5]+PT->V[9*View->TimeStep+8])/3.;
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
		    (PT->X[0] + PT->X[1] + PT->X[2])/3.,
		    (PT->Y[0] + PT->Y[1] + PT->Y[2])/3.,
		    (PT->Z[0] + PT->Z[1] + PT->Z[2])/3.,
		    fact*d, fact*dx, fact*dy, fact*dz,
		    View->Offset, Raise);
      }
    }
    else{
      for(k=0 ; k<3 ; k++){
	dx = PT->V[9*View->TimeStep  +3*k] ;
	dy = PT->V[9*View->TimeStep+1+3*k] ;
	dz = PT->V[9*View->TimeStep+2+3*k] ;		  
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
		      PT->X[k], PT->Y[k], PT->Z[k],
		      fact*d, fact*dx, fact*dy, fact*dz,
		      View->Offset, Raise);
	  
	}		
      }	      
    }
    break;
    
  case DRAW_POST_TENSOR :
    break;
    
  }

  if(View->ShowElement){
    glDisable(GL_POLYGON_OFFSET_FILL) ;
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_LINE_LOOP);
    for(i=0 ; i<3 ; i++) 
      glVertex3d(PT->X[i]+View->Offset[0]+Raise[0][i],
		 PT->Y[i]+View->Offset[1]+Raise[1][i],
		 PT->Z[i]+View->Offset[2]+Raise[2][i]);
    glEnd();
  }

}


