/* $Id: PostSimplex.cpp,v 1.6 2000-12-18 08:31:45 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"

extern Context_T   CTX;

/* ------------------------------------------------------------------------ */
/*  P o i n t s                                                             */
/* ------------------------------------------------------------------------ */

void Draw_ScalarPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][5],
		      double *X, double *Y, double *Z, double *V){
  double   d;

  d = V[View->TimeStep];  
  if(d>=ValMin && d<=ValMax){      
    RaiseFill(0, d, ValMin, Raise);
    Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
    Draw_Point(X,Y,Z,View->Offset,Raise);
  }
}

void Draw_VectorPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][5],
		      double *X, double *Y, double *Z, double *V){
  int      i;
  double   d,dx,dy,dz,fact;
          
  if(View->ArrowType == DRAW_POST_DISPLACEMENT){

    fact = View->ArrowScale/100. ;
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_POINTS);
    glVertex3d(fact*V[3*View->TimeStep],
	       fact*V[3*View->TimeStep+1],
	       fact*V[3*View->TimeStep+2]);
    glEnd();
    if(View->TimeStep){
      glBegin(GL_LINE_STRIP);
      for(i=0 ; i<View->TimeStep+1 ; i++)
	glVertex3d(fact*V[3*(View->TimeStep-i)],
		   fact*V[3*(View->TimeStep-i)+1],
		   fact*V[3*(View->TimeStep-i)+2]);
      glEnd();
    }

  }
  else{

    dx = V[3*View->TimeStep];  
    dy = V[3*View->TimeStep+1];
    dz = V[3*View->TimeStep+2];
    d = sqrt(dx*dx+dy*dy+dz*dz);
    
    if(d!=0.0 && d>=ValMin && d<=ValMax){
      Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
      fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;
      if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
        dx /= d ; dy /= d ; dz /= d ;
        d = log10(d/ValMin) ; 
        dx *= d ; dy *= d ; dz *= d ;
      }
      RaiseFill(0, d, ValMin, Raise);
      Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO, 
                  X[0], Y[0], Z[0],
                  fact*d, fact*dx, fact*dy, fact*dz,
                  View->Offset, Raise);
    }

  }
}

void Draw_TensorPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][5],
		      double *X, double *Y, double *Z, double *V){
}

/* ------------------------------------------------------------------------ */
/*  L i n e s                                                               */
/* ------------------------------------------------------------------------ */

void Draw_ScalarLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][5],
		     double *X, double *Y, double *Z, double *V){

  int     i,k,nb=0;
  double  d;
  double  Xp[5],Yp[5],Zp[5],value[5],thev;
  char    Num[100] ;

  if(View->IntervalsType == DRAW_POST_NUMERIC){

    d = (V[2*View->TimeStep]+V[2*View->TimeStep+1]) / 2.;
    if(d >= ValMin && d <= ValMax){
      RaiseFill(0, d, ValMin, Raise);
      Palette2(View,ValMin,ValMax,d);
      sprintf(Num, "%g", d);
      glRasterPos3d((X[0] + X[1])/2.,
		    (Y[0] + Y[1])/2.,
		    (Z[0] + Z[1])/2.);
      Draw_String(Num);
    }

  }
  else{

    for(k=0 ; k<2 ; k++) RaiseFill(k, V[2*View->TimeStep+k], ValMin, Raise);
    
    if(View->IntervalsType==DRAW_POST_CONTINUOUS){
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

void Draw_VectorLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][5],
		     double *X, double *Y, double *Z, double *V){

  int     k;
  double  d,dx,dy,dz,fact;

  if(View->ArrowLocation == DRAW_POST_LOCATE_COG){
    dx = 0.5 * (V[6*View->TimeStep]  +V[6*View->TimeStep+3]);
    dy = 0.5 * (V[6*View->TimeStep+1]+V[6*View->TimeStep+4]);
    dz = 0.5 * (V[6*View->TimeStep+2]+V[6*View->TimeStep+5]);
    d = sqrt(dx*dx+dy*dy+dz*dz);          
    if(d!=0.0 && d>=ValMin && d<=ValMax){           
      Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));            
      fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;            
      if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	dx /= d ; dy /= d ; dz /= d ;
	d = log10(d/ValMin) ; 
	dx *= d ; dy *= d ; dz *= d ;
      }
      RaiseFill(0, d, ValMin, Raise);         
      Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
		  0.5 * (X[0] + X[1]),
		  0.5 * (Y[0] + Y[1]),
		  0.5 * (Z[0] + Z[1]),
		  fact*d, fact*dx, fact*dy, fact*dz,
		  View->Offset, Raise);
    }
  }
  else{
    for(k=0 ; k<2 ; k++){
      dx = V[6*View->TimeStep  +3*k] ;
      dy = V[6*View->TimeStep+1+3*k] ;
      dz = V[6*View->TimeStep+2+3*k] ;              
      d = sqrt(dx*dx+dy*dy+dz*dz);            
      if(d!=0.0 && d>=ValMin && d<=ValMax){           
	Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
	fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;          
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

void Draw_TensorLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][5],
		     double *X, double *Y, double *Z, double *V){
}


/* ------------------------------------------------------------------------ */
/*  T r i a n g l e s                                                       */
/* ------------------------------------------------------------------------ */

void Draw_ScalarTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][5],
			 double *X, double *Y, double *Z, double *V){

  int     i, k, nb=0;
  double  d;
  double  x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, nn[3];
  double  Xp[5],Yp[5],Zp[5],value[5],thev;
  char    Num[100] ;


  if(View->IntervalsType == DRAW_POST_NUMERIC){

    d = (V[3*View->TimeStep]+V[3*View->TimeStep+1]+V[3*View->TimeStep+2]) / 3.;
    if(d >= ValMin && d <= ValMax){
      sprintf(Num, "%g", d);
      RaiseFill(0, d, ValMin, Raise);
      Palette2(View,ValMin,ValMax,d);
      glRasterPos3d((X[0] + X[1] + X[2])/3.+Raise[0][0],
		    (Y[0] + Y[1] + Y[2])/3.+Raise[1][0],
		    (Z[0] + Z[1] + Z[2])/3.+Raise[2][0]);
      Draw_String(Num);
    }

  }
  else{

    if(View->ShowElement ||
       View->IntervalsType == DRAW_POST_CONTINUOUS)
      for(i = 0 ; i<3 ; i++) RaiseFill(i, V[3*View->TimeStep+i], ValMin, Raise);
    
    if(View->ShowElement){
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINE_LOOP);
      for(i=0 ; i<3 ; i++) 
	glVertex3d(X[i]+View->Offset[0]+Raise[0][i],
		   Y[i]+View->Offset[1]+Raise[1][i],
		   Z[i]+View->Offset[2]+Raise[2][i]);
      glEnd();
    }

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

void Draw_VectorTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][5],
			 double *X, double *Y, double *Z, double *V){

  int     k, m;
  double  d,dx,dy,dz,fact;
  double  xx[3],yy[3],zz[3];

  if(View->ArrowType == DRAW_POST_DISPLACEMENT){

    fact = View->ArrowScale/100. ;
    for(m=0 ; m<3 ; m++){
      xx[m] = X[m] + fact * V[9*View->TimeStep + 3 * m ];
      yy[m] = Y[m] + fact * V[9*View->TimeStep + 3 * m + 1];
      zz[m] = Z[m] + fact * V[9*View->TimeStep + 3 * m + 2];
    }
    glColor4ubv((GLubyte*)&CTX.color.bg);
    if(View->IntervalsType!=DRAW_POST_ISO)
      Draw_Polygon (3, xx, yy, zz, View->Offset, Raise);
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_LINE_LOOP);
    for(m=0 ; m<3 ; m++) glVertex3d(xx[m], yy[m], zz[m]);
    glEnd();

  }
  else{
    
    if(View->ArrowLocation == DRAW_POST_LOCATE_COG){
      dx = (V[9*View->TimeStep]  +V[9*View->TimeStep+3]+V[9*View->TimeStep+6])/3.;
      dy = (V[9*View->TimeStep+1]+V[9*View->TimeStep+4]+V[9*View->TimeStep+7])/3.;
      dz = (V[9*View->TimeStep+2]+V[9*View->TimeStep+5]+V[9*View->TimeStep+8])/3.;
      d = sqrt(dx*dx+dy*dy+dz*dz);
      if(d!=0.0 && d>=ValMin && d<=ValMax){             
        Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));            
        fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;            
        if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
          dx /= d ; dy /= d ; dz /= d ;
          d = log10(d/ValMin) ; 
          dx *= d ; dy *= d ; dz *= d ;
        }
        RaiseFill(0, d, ValMin, Raise);         
        Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
                    (X[0] + X[1] + X[2])/3.,
                    (Y[0] + Y[1] + Y[2])/3.,
                    (Z[0] + Z[1] + Z[2])/3.,
                    fact*d, fact*dx, fact*dy, fact*dz,
                    View->Offset, Raise);
      }
    }
    else{
      for(k=0 ; k<3 ; k++){
        dx = V[9*View->TimeStep  +3*k] ;
        dy = V[9*View->TimeStep+1+3*k] ;
        dz = V[9*View->TimeStep+2+3*k] ;              
        d = sqrt(dx*dx+dy*dy+dz*dz);
        
        if(d!=0.0 && d>=ValMin && d<=ValMax){           
          Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
          fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;          
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

}

void Draw_TensorTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][5],
			 double *X, double *Y, double *Z, double *V){
}


/* ------------------------------------------------------------------------ */
/*  T e t r a h e d r a                                                     */
/* ------------------------------------------------------------------------ */

void Draw_ScalarTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][5],
			    double *X, double *Y, double *Z, double *V){

  int     k;

  for(k=0 ; k<View->NbIso ; k++){
    Palette(View,View->NbIso,k);
    IsoSimplex(X, Y, Z, &V[4*View->TimeStep],
	       View->GVFI(ValMin,ValMax,View->NbIso,k), 
	       ValMin, ValMax, View->Offset, Raise, View->Light);
  }

}


void Draw_VectorTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][5],
			    double *X, double *Y, double *Z, double *V){

  int     k;
  double  d,dx,dy,dz,fact;

  /* 
     la plus grande fleche (d=ValMax) est de taille CTX.lc/50
     (View->ArrowScale == 100 par defaut)
  */
    
  if(View->ArrowLocation == DRAW_POST_LOCATE_COG){
    dx = 0.25 * (V[12*View->TimeStep]  +V[12*View->TimeStep+3]+
		 V[12*View->TimeStep+6]+V[12*View->TimeStep+9] );
    dy = 0.25 * (V[12*View->TimeStep+1]+V[12*View->TimeStep+4]+
		 V[12*View->TimeStep+7]+V[12*View->TimeStep+10] );
    dz = 0.25 * (V[12*View->TimeStep+2]+V[12*View->TimeStep+5]+
		 V[12*View->TimeStep+8]+V[12*View->TimeStep+11] );
    d = sqrt(dx*dx+dy*dy+dz*dz);
    
    if(d!=0.0 && d>=ValMin && d<=ValMax){             
      Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
      fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;            
      if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	dx /= d ; dy /= d ; dz /= d ;
	d = log10(d/ValMin) ; 
	dx *= d ; dy *= d ; dz *= d ;
      }
      RaiseFill(0, d, ValMin, Raise);         
      Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO,
		  0.25 * (X[0] + X[1] + X[2] + X[3]),
		  0.25 * (Y[0] + Y[1] + Y[2] + Y[3]),
		  0.25 * (Z[0] + Z[1] + Z[2] + Z[3]),
		  fact*d, fact*dx, fact*dy, fact*dz,
		  View->Offset, Raise);
    }
  }
  else{
    for(k=0 ; k<4 ; k++){
      dx = V[12*View->TimeStep  +3*k] ;
      dy = V[12*View->TimeStep+1+3*k] ;
      dz = V[12*View->TimeStep+2+3*k] ;             
      d = sqrt(dx*dx+dy*dy+dz*dz);
      
      if(d!=0.0 && d>=ValMin && d<=ValMax){     
	Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
	fact = 2.e-4 * CTX.lc * View->ArrowScale/View->Max ;          
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

void Draw_TensorTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][5],
			    double *X, double *Y, double *Z, double *V){
}
