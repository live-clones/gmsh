// $Id: PostSimplex.cpp,v 1.16 2001-04-22 18:13:02 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "IsoSimplex.h"
#include "Context.h"

extern Context_T   CTX;

/* ------------------------------------------------------------------------ */
/*  Scalar Simplices                                                        */
/* ------------------------------------------------------------------------ */

void Draw_ScalarPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][5],
		      double *X, double *Y, double *Z, double *V){
  double   d;
  char Num[100];

  d = V[View->TimeStep];  
  RaiseFill(0, d, ValMin, Raise);

  if(View->ShowElement){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    Draw_Point(X,Y,Z,View->Offset,Raise);
  }

  if(d>=ValMin && d<=ValMax){      
    Palette2(View,ValMin,ValMax,d);
    if(View->IntervalsType == DRAW_POST_NUMERIC){
      glRasterPos3d(X[0]+Raise[0][0]+View->Offset[0],
		    Y[0]+Raise[1][0]+View->Offset[1],
		    Z[0]+Raise[2][0]+View->Offset[2]);
      sprintf(Num, View->Format, d);
      Draw_String(Num);
    }
    else
      Draw_Point(X,Y,Z,View->Offset,Raise);
  }
}

void Draw_ScalarLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][5],
		     double *X, double *Y, double *Z, double *V){

  int     i,k,nb=0;
  double  d;
  double  Xp[5],Yp[5],Zp[5],value[5],thev;
  char    Num[100] ;

  for(k=0 ; k<2 ; k++)
    RaiseFill(k, V[2*View->TimeStep+k], ValMin, Raise);

  if(View->ShowElement){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    Draw_Line(X,Y,Z,View->Offset,Raise);
  }

  if(View->IntervalsType == DRAW_POST_NUMERIC){

    d = (V[2*View->TimeStep]+V[2*View->TimeStep+1]) / 2.;

    if(d >= ValMin && d <= ValMax){
      Palette2(View,ValMin,ValMax,d);
      sprintf(Num, View->Format, d);
      glRasterPos3d((X[0]+Raise[0][0] + X[1]+Raise[0][1])/2. + View->Offset[0],
		    (Y[0]+Raise[1][0] + Y[1]+Raise[1][1])/2. + View->Offset[1],
		    (Z[0]+Raise[2][0] + Z[1]+Raise[2][1])/2. + View->Offset[2]);
      Draw_String(Num);
    }

  }
  else{

    if(View->IntervalsType==DRAW_POST_CONTINUOUS){

      if(V[2*View->TimeStep]  >=ValMin && V[2*View->TimeStep]  <=ValMax &&
         V[2*View->TimeStep+1]>=ValMin && V[2*View->TimeStep+1]<=ValMax){
	glBegin(GL_LINES);
	Palette2(View,ValMin,ValMax,V[2*View->TimeStep]);
	glVertex3d(X[0]+View->Offset[0]+Raise[0][0],
		   Y[0]+View->Offset[1]+Raise[1][0],
		   Z[0]+View->Offset[2]+Raise[2][0]);
	Palette2(View,ValMin,ValMax,V[2*View->TimeStep+1]);
	glVertex3d(X[1]+View->Offset[0]+Raise[0][1],
		   Y[1]+View->Offset[1]+Raise[1][1],
		   Z[1]+View->Offset[2]+Raise[2][1]);
	glEnd();
      }
      else{
	//todo
      }

    }
    else{
      for(k=0 ; k<View->NbIso ; k++){
	Palette(View,View->NbIso,k);
	if(View->IntervalsType==DRAW_POST_DISCRETE){
	  CutLine1D(X,Y,Z,&V[2*View->TimeStep],
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
	  CutLine0D(X,Y,Z,&V[2*View->TimeStep],
		    thev, ValMin,ValMax,Xp,Yp,Zp,&nb);    
	  if(nb){
	    RaiseFill(0,thev,ValMin,Raise);
	    Draw_Point(Xp,Yp,Zp,View->Offset,Raise);    
	  }
	}
      }
    }

  }

}

void Draw_ScalarTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][5],
			 double *X, double *Y, double *Z, double *V){

  int     i, k, nb=0;
  double  d;
  double  x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, nn[3];
  double  Xp[5],Yp[5],Zp[5],value[5],thev;
  char    Num[100] ;

  for(k=0 ; k<3 ; k++)
    RaiseFill(k, V[3*View->TimeStep+k], ValMin, Raise);

  if(View->Light){
    x1x0 = (X[1]+Raise[0][1]) - (X[0]+Raise[0][0]); 
    y1y0 = (Y[1]+Raise[1][1]) - (Y[0]+Raise[1][0]);
    z1z0 = (Z[1]+Raise[2][1]) - (Z[0]+Raise[2][0]); 
    x2x0 = (X[2]+Raise[0][2]) - (X[0]+Raise[0][0]);
    y2y0 = (Y[2]+Raise[1][2]) - (Y[0]+Raise[1][0]); 
    z2z0 = (Z[2]+Raise[2][2]) - (Z[0]+Raise[2][0]);
    nn[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    nn[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    nn[2]  = x1x0 * y2y0 - y1y0 * x2x0 ;
    glNormal3dv(nn);
  }

  if(View->ShowElement){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_LINE_LOOP);
    for(i=0 ; i<3 ; i++) 
      glVertex3d(X[i]+View->Offset[0]+Raise[0][i],
		 Y[i]+View->Offset[1]+Raise[1][i],
		 Z[i]+View->Offset[2]+Raise[2][i]);
    glEnd();
  }

  if(View->IntervalsType == DRAW_POST_NUMERIC){

    d = (V[3*View->TimeStep]+V[3*View->TimeStep+1]+V[3*View->TimeStep+2]) / 3.;
    if(d >= ValMin && d <= ValMax){
      Palette2(View,ValMin,ValMax,d);
      sprintf(Num, View->Format, d);
      glRasterPos3d( (X[0]+Raise[0][0] + X[1]+Raise[0][1] + X[2]+Raise[0][2])/3. + 
		     View->Offset[0],
		     (Y[0]+Raise[1][0] + Y[1]+Raise[1][1] + Y[2]+Raise[1][2])/3. +
		     View->Offset[1],
		     (Z[0]+Raise[2][0] + Z[1]+Raise[2][1] + Z[2]+Raise[2][2])/3. + 
		     View->Offset[2] );
      Draw_String(Num);
    }

  }
  else{
    
    if(View->IntervalsType == DRAW_POST_CONTINUOUS){
      if(V[3*View->TimeStep]  >=ValMin && V[3*View->TimeStep]  <=ValMax &&
         V[3*View->TimeStep+1]>=ValMin && V[3*View->TimeStep+1]<=ValMax &&
         V[3*View->TimeStep+2]>=ValMin && V[3*View->TimeStep+2]<=ValMax){
        glBegin(GL_TRIANGLES);
	Palette2(View,ValMin,ValMax,V[3*View->TimeStep]);
        glVertex3d(X[0]+View->Offset[0]+Raise[0][0],
                   Y[0]+View->Offset[1]+Raise[1][0],
                   Z[0]+View->Offset[2]+Raise[2][0]);
	Palette2(View,ValMin,ValMax,V[3*View->TimeStep+1]);
        glVertex3d(X[1]+View->Offset[0]+Raise[0][1],
                   Y[1]+View->Offset[1]+Raise[1][1],
                   Z[1]+View->Offset[2]+Raise[2][1]);
	Palette2(View,ValMin,ValMax,V[3*View->TimeStep+2]);
        glVertex3d(X[2]+View->Offset[0]+Raise[0][2],
                   Y[2]+View->Offset[1]+Raise[1][2],
                   Z[2]+View->Offset[2]+Raise[2][2]);
        glEnd();
      }
      else{
        CutTriangle2D(X,Y,Z,&V[3*View->TimeStep],
                      ValMin,ValMax,ValMin,ValMax,
                      Xp,Yp,Zp,&nb,value);
        if(nb >= 3){      
          glBegin(GL_POLYGON);
          for(i=0 ; i<nb ; i++){
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
        if(View->IntervalsType == DRAW_POST_DISCRETE){
          Palette(View,View->NbIso,k);
          CutTriangle2D(X,Y,Z,&V[3*View->TimeStep],
                        View->GVFI(ValMin,ValMax,View->NbIso+1,k),
                        View->GVFI(ValMin,ValMax,View->NbIso+1,k+1),
                        ValMin,ValMax,
                        Xp,Yp,Zp,&nb,value);      
          if(nb >= 3){
            for(i=0 ; i<nb ; i++) RaiseFill(i,value[i],ValMin,Raise);    
            Draw_Polygon(nb,Xp,Yp,Zp,View->Offset,Raise);  
          }
        }
        else{
          Palette(View,View->NbIso,k);
          thev = View->GVFI(ValMin,ValMax,View->NbIso,k);
          CutTriangle1D(X,Y,Z,&V[3*View->TimeStep],
                        thev, ValMin,ValMax,Xp,Yp,Zp,&nb);        
          if(nb == 2){
            for(i=0 ; i<2 ; i++) RaiseFill(i,thev,ValMin,Raise);
            Draw_Line(Xp,Yp,Zp,View->Offset,Raise);    
          }
        }
      }
    }

  }
    
}

void Draw_ScalarTetrahedron(Post_View *View,
			    int preproNormals,
			    double ValMin, 
			    double ValMax, 
			    double Raise[3][5],
			    double *X, 
			    double *Y, 
			    double *Z, 
			    double *V){

  int     k;
  double  d, xx[4], yy[4], zz[4];
  char Num[100];

  for(k=0 ; k<4 ; k++)
    RaiseFill(k, V[4*View->TimeStep+k], ValMin, Raise);

  if(View->ShowElement){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    for(k=0 ; k<4 ; k++){
      xx[k] = X[k]+View->Offset[0]+Raise[0][k] ;
      yy[k] = Y[k]+View->Offset[1]+Raise[1][k] ;
      zz[k] = Z[k]+View->Offset[2]+Raise[2][k] ;
    }
    glBegin(GL_LINES);
    glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[1], yy[1], zz[1]); glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[1], yy[1], zz[1]); glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[2], yy[2], zz[2]); glVertex3d(xx[3], yy[3], zz[3]);
    glEnd();
  }

  if(View->IntervalsType == DRAW_POST_NUMERIC && !preproNormals){

    d = 0.25 * (V[4*View->TimeStep]  +V[4*View->TimeStep+1]+
		V[4*View->TimeStep+2]+V[4*View->TimeStep+3]);
    if(d >= ValMin && d <= ValMax){
      Palette2(View,ValMin,ValMax,d);
      sprintf(Num, View->Format, d);
      glRasterPos3d(0.25 * (X[0]+Raise[0][0] + X[1]+Raise[0][1] + 
			    X[2]+Raise[0][2] + X[3]+Raise[0][3]) + View->Offset[0],
		    0.25 * (Y[0]+Raise[1][0] + Y[1]+Raise[1][1] + 
			    Y[2]+Raise[1][2] + Y[3]+Raise[1][3]) + View->Offset[1],
		    0.25 * (Z[0]+Raise[2][0] + Z[1]+Raise[2][1] + 
			    Z[2]+Raise[2][2] + Z[3]+Raise[2][3]) + View->Offset[2]);
      Draw_String(Num);
    }

  }
  else{

    for(k=0 ; k<View->NbIso ; k++){
      if(!preproNormals)Palette(View,View->NbIso,k);
      IsoSimplex(View,preproNormals,
		 X, Y, Z, &V[4*View->TimeStep],
		 View->GVFI(ValMin,ValMax,View->NbIso,k), 
		 ValMin, ValMax, View->Offset, Raise, View->Light);
    }

  }

}

/* ------------------------------------------------------------------------ */
/*  Vector Simplices                                                        */
/* ------------------------------------------------------------------------ */

void Draw_VectorSimplex(int nbnod, Post_View *View, 
			double ValMin, double ValMax, double Raise[3][5],
			double *X, double *Y, double *Z, double *V){
  int    j, k ;
  double d, dx, dy, dz, fact, xx[4], yy[4], zz[4], xc=0., yc=0., zc=0. ;
  char   Num[100];

  for(k=0 ; k<nbnod ; k++){
    dx = V[3*nbnod*View->TimeStep  +3*k] ;
    dy = V[3*nbnod*View->TimeStep+1+3*k] ;
    dz = V[3*nbnod*View->TimeStep+2+3*k] ;              
    d = sqrt(dx*dx+dy*dy+dz*dz);            
    RaiseFill(k, d, ValMin, Raise);
  }

  if(View->ArrowType == DRAW_POST_DISPLACEMENT){

    fact = View->ArrowScale/50. ;
    for(k=0 ; k<nbnod ; k++){
      xx[k] = X[k] + fact * V[3*nbnod*View->TimeStep  +3*k] + 
	Raise[0][k] + View->Offset[0];
      yy[k] = Y[k] + fact * V[3*nbnod*View->TimeStep+1+3*k] + 
	Raise[1][k] + View->Offset[1];
      zz[k] = Z[k] + fact * V[3*nbnod*View->TimeStep+2+3*k] + 
	Raise[2][k] + View->Offset[2];
    }

    switch(nbnod){
    case 1 :
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_POINTS);
      glVertex3d(xx[0],yy[0],zz[0]);
      glEnd();
      if(View->TimeStep){
	glBegin(GL_LINE_STRIP);
	for(j=0 ; j<View->TimeStep+1 ; j++)
	  glVertex3d(X[0] + fact*V[3*(View->TimeStep-j)]  + Raise[0][0] + View->Offset[0],
		     Y[0] + fact*V[3*(View->TimeStep-j)+1]+ Raise[1][0] + View->Offset[1],
		     Z[0] + fact*V[3*(View->TimeStep-j)+2]+ Raise[2][0] + View->Offset[2]);
	glEnd();
      }
      break;
    case 2 :
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINES);
      glVertex3d(xx[0], yy[0], zz[0]);
      glVertex3d(xx[1], yy[1], zz[1]);
      glEnd();
      break;
    case 3 :
      if(View->IntervalsType!=DRAW_POST_ISO){
	glColor4ubv((GLubyte*)&CTX.color.bg);
	glBegin(GL_TRIANGLES);
	glVertex3d(xx[0],yy[0],zz[0]);
	glVertex3d(xx[1],yy[1],zz[1]);
	glVertex3d(xx[2],yy[2],zz[2]);
	glEnd();
      }
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINE_LOOP);
      for(k=0 ; k<3 ; k++) glVertex3d(xx[k], yy[k], zz[k]);
      glEnd();
      break;
    case 4 :
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINES);
      glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[1], yy[1], zz[1]);
      glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[2], yy[2], zz[2]);
      glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[3], yy[3], zz[3]);
      glVertex3d(xx[1], yy[1], zz[1]); glVertex3d(xx[2], yy[2], zz[2]);
      glVertex3d(xx[1], yy[1], zz[1]); glVertex3d(xx[3], yy[3], zz[3]);
      glVertex3d(xx[2], yy[2], zz[2]); glVertex3d(xx[3], yy[3], zz[3]);
      glEnd();
      break;
    }

    return;
  }

  if(View->ShowElement){
    switch(nbnod){
    case 1 :
      glColor4ubv((GLubyte*)&CTX.color.fg);
      Draw_Point(X,Y,Z,View->Offset,Raise);
      break;
    case 2 :
      glColor4ubv((GLubyte*)&CTX.color.fg);
      Draw_Line(X,Y,Z,View->Offset,Raise);
      break;
    case 3 :
      glColor4ubv((GLubyte*)&CTX.color.bg);
      if(View->IntervalsType!=DRAW_POST_ISO)
	Draw_Polygon (3, X, Y, Z, View->Offset, Raise);
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINE_LOOP);
      for(k=0 ; k<3 ; k++) 
	glVertex3d(X[k]+View->Offset[0]+Raise[0][k],
		   Y[k]+View->Offset[1]+Raise[1][k],
		   Z[k]+View->Offset[2]+Raise[2][k]);
      glEnd();
      break;
    case 4 :
      glColor4ubv((GLubyte*)&CTX.color.fg);
      for(k=0 ; k<4 ; k++){
	xx[k] = X[k]+View->Offset[0]+Raise[0][k] ;
	yy[k] = Y[k]+View->Offset[1]+Raise[1][k] ;
	zz[k] = Z[k]+View->Offset[2]+Raise[2][k] ;
      }
      glBegin(GL_LINES);
      glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[1], yy[1], zz[1]);
      glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[2], yy[2], zz[2]);
      glVertex3d(xx[0], yy[0], zz[0]); glVertex3d(xx[3], yy[3], zz[3]);
      glVertex3d(xx[1], yy[1], zz[1]); glVertex3d(xx[2], yy[2], zz[2]);
      glVertex3d(xx[1], yy[1], zz[1]); glVertex3d(xx[3], yy[3], zz[3]);
      glVertex3d(xx[2], yy[2], zz[2]); glVertex3d(xx[3], yy[3], zz[3]);
      glEnd();
    }
  }

  if(View->ArrowLocation == DRAW_POST_LOCATE_COG ||
     View->IntervalsType == DRAW_POST_NUMERIC){
    switch(nbnod){
    case 1:
      dx = V[3*View->TimeStep];
      dy = V[3*View->TimeStep+1];
      dz = V[3*View->TimeStep+2];
      break;
    case 2:
      dx = 0.5 * (V[6*View->TimeStep]  +V[6*View->TimeStep+3]);
      dy = 0.5 * (V[6*View->TimeStep+1]+V[6*View->TimeStep+4]);
      dz = 0.5 * (V[6*View->TimeStep+2]+V[6*View->TimeStep+5]);
      break;
    case 3 :
      dx = (V[9*View->TimeStep]  +V[9*View->TimeStep+3]+V[9*View->TimeStep+6])/3.;
      dy = (V[9*View->TimeStep+1]+V[9*View->TimeStep+4]+V[9*View->TimeStep+7])/3.;
      dz = (V[9*View->TimeStep+2]+V[9*View->TimeStep+5]+V[9*View->TimeStep+8])/3.;
      break;
    case 4 :
      dx = 0.25 * (V[12*View->TimeStep]  +V[12*View->TimeStep+3]+
		   V[12*View->TimeStep+6]+V[12*View->TimeStep+9] );
      dy = 0.25 * (V[12*View->TimeStep+1]+V[12*View->TimeStep+4]+
		   V[12*View->TimeStep+7]+V[12*View->TimeStep+10] );
      dz = 0.25 * (V[12*View->TimeStep+2]+V[12*View->TimeStep+5]+
		   V[12*View->TimeStep+8]+V[12*View->TimeStep+11] );
      break;
    }
    d = sqrt(dx*dx+dy*dy+dz*dz);
    if(d!=0.0 && d>=ValMin && d<=ValMax){             
      Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));            
      if(View->IntervalsType == DRAW_POST_NUMERIC){
	for(k = 0 ; k<nbnod ; k++){
	  xc += X[k] + Raise[0][k] ; 
	  yc += Y[k] + Raise[1][k]; 
	  zc += Z[k] + Raise[2][k]; 
	}
	glRasterPos3d(xc/(double)nbnod + View->Offset[0],
		      yc/(double)nbnod + View->Offset[1],
		      zc/(double)nbnod + View->Offset[2]);
	sprintf(Num, View->Format, d);
	Draw_String(Num);
      }
      else{
	for(k = 0 ; k<nbnod ; k++){
	  xc += X[k] ; 
	  yc += Y[k] ; 
	  zc += Z[k] ; 
	}
	xc /= (double)nbnod;
	yc /= (double)nbnod;
	zc /= (double)nbnod;
	fact = CTX.pixel_equiv_x/CTX.s[0] * View->ArrowScale/ValMax ;
	if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	  dx /= d ; dy /= d ; dz /= d ;
	  d = log10(d/ValMin) ; 
	  dx *= d ; dy *= d ; dz *= d ;
	}
	RaiseFill(0, d, ValMin, Raise);         
	Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
		    xc, yc, zc,
		    fact*d, fact*dx, fact*dy, fact*dz,
		    View->Offset, Raise);
      }
    }
  }
  else{
    for(k=0 ; k<nbnod ; k++){
      dx = V[3*nbnod*View->TimeStep  +3*k] ;
      dy = V[3*nbnod*View->TimeStep+1+3*k] ;
      dz = V[3*nbnod*View->TimeStep+2+3*k] ;              
      d = sqrt(dx*dx+dy*dy+dz*dz);
      if(d!=0.0 && d>=ValMin && d<=ValMax){           
	Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
	fact = CTX.pixel_equiv_x/CTX.s[0] * View->ArrowScale/ValMax ;
	if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	  dx /= d ; dy /= d ; dz /= d ;
	  d = log10(d/ValMin) ; 
	  dx *= d ; dy *= d ; dz *= d ;
	}
	RaiseFill(0, d, ValMin, Raise);         
	Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
		    X[k], Y[k], Z[k],
		    fact*d, fact*dx, fact*dy, fact*dz,
		    View->Offset, Raise);
      }               
    }       
  }

}

void Draw_VectorPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][5],
		      double *X, double *Y, double *Z, double *V){
  Draw_VectorSimplex(1, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

void Draw_VectorLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][5],
		     double *X, double *Y, double *Z, double *V){
  Draw_VectorSimplex(2, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

void Draw_VectorTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][5],
			 double *X, double *Y, double *Z, double *V){
  Draw_VectorSimplex(3, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

void Draw_VectorTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][5],
			    double *X, double *Y, double *Z, double *V){
  Draw_VectorSimplex(4, View, ValMin, ValMax, Raise, X, Y, Z, V);
}


/* ------------------------------------------------------------------------ */
/*  Tensor Simplices                                                        */
/* ------------------------------------------------------------------------ */

static int TensorError = 0 ;

void Draw_TensorSimplex(int nbnod, Post_View *View, 
			double ValMin, double ValMax, double Raise[3][5],
			double *X, double *Y, double *Z, double *V){
  if(!TensorError){
    TensorError = 1;
    Msg(GERROR, "Tensor field visualization is not implemented");
    Msg(GERROR, "We *need* some ideas on how to implement this!");
    Msg(GERROR, "Send your ideas to <gmsh@geuz.org>!");
  }
}


void Draw_TensorPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][5],
		      double *X, double *Y, double *Z, double *V){
  Draw_TensorSimplex(1, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

void Draw_TensorLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][5],
		     double *X, double *Y, double *Z, double *V){
  Draw_TensorSimplex(2, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

void Draw_TensorTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][5],
			 double *X, double *Y, double *Z, double *V){
  Draw_TensorSimplex(3, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

void Draw_TensorTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][5],
			    double *X, double *Y, double *Z, double *V){
  Draw_TensorSimplex(4, View, ValMin, ValMax, Raise, X, Y, Z, V);
}

