/* $Id: Entity.cpp,v 1.3 2000-11-26 15:43:46 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"

extern Context_T   CTX;

/* ------------------------------------------------------------------------ */
/*  D r a w _ P o i n t                                                     */
/* ------------------------------------------------------------------------ */

void Draw_Point (double *x, double *y, double *z,
                 double *Offset, double Raise[3][5]){
  glBegin(GL_POINTS);
  glVertex3d(x[0]+Offset[0]+Raise[0][0],
             y[0]+Offset[1]+Raise[1][0],
             z[0]+Offset[2]+Raise[2][0]);
  glEnd();
}

/* ------------------------------------------------------------------------ */
/*  D r a w _ L i n e                                                       */
/* ------------------------------------------------------------------------ */

void Draw_Line (double *x, double *y, double *z,
                double *Offset, double Raise[3][5]){
  glBegin(GL_LINES);
  glVertex3d(x[0]+Offset[0]+Raise[0][0],
             y[0]+Offset[1]+Raise[1][0],
             z[0]+Offset[2]+Raise[2][0]);
  glVertex3d(x[1]+Offset[0]+Raise[0][1],
             y[1]+Offset[1]+Raise[1][1],
             z[1]+Offset[2]+Raise[2][1]);
  glEnd();
}

/* ------------------------------------------------------------------------ */
/*  D r a w _ T r i a n g l e                                               */
/* ------------------------------------------------------------------------ */

void Draw_Triangle (double *x, double *y, double *z,
                    double *Offset, double Raise[3][5], int shade){

  double x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, nn[3];

  if (shade){
    x1x0 = (x[1]+Raise[0][1]) - (x[0]+Raise[0][0]); 
    y1y0 = (y[1]+Raise[1][1]) - (y[0]+Raise[1][0]);
    z1z0 = (z[1]+Raise[2][1]) - (z[0]+Raise[2][0]); 
    x2x0 = (x[2]+Raise[0][2]) - (x[0]+Raise[0][0]);
    y2y0 = (y[2]+Raise[1][2]) - (y[0]+Raise[1][0]); 
    z2z0 = (z[2]+Raise[2][2]) - (z[0]+Raise[2][0]);
    nn[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    nn[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    nn[2]  = x1x0 * y2y0 - y1y0 * x2x0 ;
    /* BOF BOF
    if(nn[2] < -0.1){
      nn[0] = -nn[0];
      nn[1] = -nn[1];
      nn[2] = -nn[2];
    }
    */
    glNormal3dv(nn);
  }

  glBegin(GL_TRIANGLES);
  glVertex3d(x[0]+Offset[0]+Raise[0][0],
             y[0]+Offset[1]+Raise[1][0],
             z[0]+Offset[2]+Raise[2][0]);
  glVertex3d(x[1]+Offset[0]+Raise[0][1],
             y[1]+Offset[1]+Raise[1][1],
             z[1]+Offset[2]+Raise[2][1]);
  glVertex3d(x[2]+Offset[0]+Raise[0][2],
             y[2]+Offset[1]+Raise[1][2],
             z[2]+Offset[2]+Raise[2][2]);
  glEnd();

}

/* ------------------------------------------------------------------------ */
/*  D r a w _ Q u a d r a n g l e                                           */
/* ------------------------------------------------------------------------ */

void Draw_Quadrangle (double *x, double *y, double *z,
                      double *Offset, double Raise[3][5], int shade){

  double x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, nn[3];

  if (shade){
    x1x0 = (x[1]+Raise[0][1]) - (x[0]+Raise[0][0]); 
    y1y0 = (y[1]+Raise[1][1]) - (y[0]+Raise[1][0]);
    z1z0 = (z[1]+Raise[2][1]) - (z[0]+Raise[2][0]); 
    x2x0 = (x[2]+Raise[0][2]) - (x[0]+Raise[0][0]);
    y2y0 = (y[2]+Raise[1][2]) - (y[0]+Raise[1][0]); 
    z2z0 = (z[2]+Raise[2][2]) - (z[0]+Raise[2][0]);
    nn[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    nn[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    nn[2]  = x1x0 * y2y0 - y1y0 * x2x0 ;
    /* BOF BOF
    if(nn[2] < -0.1){
      nn[0] = -nn[0];
      nn[1] = -nn[1];
      nn[2] = -nn[2];
    }
    */
    glNormal3dv(nn);
  }
  /* dessin de quandrangles "non convexes" */

  glBegin(GL_TRIANGLE_FAN);
  glVertex3d(x[0]+Offset[0]+Raise[0][0],
             y[0]+Offset[1]+Raise[1][0],
             z[0]+Offset[2]+Raise[2][0]);
  glVertex3d(x[1]+Offset[0]+Raise[0][1],
             y[1]+Offset[1]+Raise[1][1],
             z[1]+Offset[2]+Raise[2][1]);
  glVertex3d(x[2]+Offset[0]+Raise[0][2],
             y[2]+Offset[1]+Raise[1][2],
             z[2]+Offset[2]+Raise[2][2]);
  glVertex3d(x[3]+Offset[0]+Raise[0][3],
             y[3]+Offset[1]+Raise[1][3],
             z[3]+Offset[2]+Raise[2][3]);
  glVertex3d(x[1]+Offset[0]+Raise[0][1],
             y[1]+Offset[1]+Raise[1][1],
             z[1]+Offset[2]+Raise[2][1]);
  glEnd();  
}

/* ------------------------------------------------------------------------ */
/*  D r a w _ P o l y g o n                                                 */
/* ------------------------------------------------------------------------ */

void Draw_Polygon (int n, double *x, double *y, double *z,
                   double *Offset, double Raise[3][5]){
  int i;
  
  glBegin(GL_POLYGON);
  for(i=0;i<n;i++) glVertex3d(x[i]+Offset[0]+Raise[0][i],
                              y[i]+Offset[1]+Raise[1][i],
                              z[i]+Offset[2]+Raise[2][i]);
  glEnd();
}

/* ------------------------------------------------------------------------ */
/*  D r a w _ V e c t o r                                                   */
/* ------------------------------------------------------------------------ */

void Draw_Vector (int Type, int Fill, 
                  double x, double y, double z, 
                  double d, double dx, double dy, double dz,
                  double *Offset, double Raise[3][5]){

  double  n[3],t[3],u[3];
  double  l,b,c, f1, f2;

  if(d == 0.0) return;
  
  if(Offset != NULL && Raise != NULL){
    x += Offset[0]+Raise[0][0] ; 
    y += Offset[1]+Raise[1][0] ; 
    z += Offset[2]+Raise[2][0] ; 
  }

  if(Type ==  DRAW_POST_SEGMENT){
    glBegin(GL_LINES);
    glVertex3d(x,    y,    z);
    glVertex3d(x+dx, y+dy, z+dz);
    glEnd();
    return;
  }

  n[0] = dx/d ; n[1] = dy/d ; n[2] = dz/d ;
  
  if( (fabs(n[0]) >= fabs(n[1]) && fabs(n[0]) >= fabs(n[2])) || 
      (fabs(n[1]) >= fabs(n[0]) && fabs(n[1]) >= fabs(n[2])) ){
    t[0] = n[1] ; t[1] = -n[0] ; t[2] = 0. ;
  }
  else{
    t[0] = 0. ; t[1] = n[2] ; t[2] = -n[1] ;
  }

  l = sqrt(t[0]*t[0]+t[1]*t[1]+t[2]*t[2]);
  t[0] /= l ; t[1] /= l ; t[2] /= l ;

  u[0] = n[1]*t[2]-n[2]*t[1];
  u[1] = n[2]*t[0]-n[0]*t[2];
  u[2] = n[0]*t[1]-n[1]*t[0];

  l = sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]);
  u[0] /= l ; u[1] /= l ; u[2] /= l ;

  switch(Type){

  case DRAW_POST_ARROW :

    b = 0.0666 * d;

    f1 = 0.85 ;
    f2 = 0.8 ;


    b *= 2 ;
    f1 /= 1.5 ;
    f2 /= 1.5 ;
    
    if(Fill){
      glBegin(GL_LINES);
      glVertex3d(x,                  y,                  z);
      glVertex3d(x+dx,               y+dy,               z+dz);
      glEnd();
      
      glBegin(GL_TRIANGLES);
      glVertex3d(x+dx,             y+dy,             z+dz);
      glVertex3d(x+f2*dx+b*(t[0]), y+f2*dy+b*(t[1]), z+f2*dz+b*(t[2]));
      glVertex3d(x+f1*dx,          y+f1*dy,          z+f1*dz);
      
      glVertex3d(x+dx,              y+dy,              z+dz);
      glVertex3d(x+f2*dx+b*(-t[0]), y+f2*dy+b*(-t[1]), z+f2*dz+b*(-t[2]));
      glVertex3d(x+f1*dx,           y+f1*dy,           z+f1*dz);
      
      glVertex3d(x+dx,              y+dy,              z+dz);
      glVertex3d(x+f2*dx+b*(-u[0]), y+f2*dy+b*(-u[1]), z+f2*dz+b*(-u[2]));
      glVertex3d(x+f1*dx,           y+f1*dy,           z+f1*dz);
      
      glVertex3d(x+dx,              y+dy,             z+dz);
      glVertex3d(x+f2*dx+b*(u[0]),  y+f2*dy+b*(u[1]), z+f2*dz+b*(u[2]));
      glVertex3d(x+f1*dx,           y+f1*dy,          z+f1*dz);
      glEnd();
    }
    else{
      glBegin(GL_LINE_STRIP);
      glVertex3d(x,                 y,                 z);
      glVertex3d(x+dx,              y+dy,              z+dz);
      glVertex3d(x+f2*dx+b*(t[0]),  y+f2*dy+b*(t[1]),  z+f2*dz+b*(t[2]));
      glVertex3d(x+f1*dx,           y+f1*dy,           z+f1*dz);
      glVertex3d(x+f2*dx+b*(-t[0]), y+f2*dy+b*(-t[1]), z+f2*dz+b*(-t[2]));
      glVertex3d(x+dx,              y+dy,              z+dz);
      glVertex3d(x+f2*dx+b*(-u[0]), y+f2*dy+b*(-u[1]), z+f2*dz+b*(-u[2]));
      glVertex3d(x+f1*dx,           y+f1*dy,           z+f1*dz);
      glVertex3d(x+f2*dx+b*(u[0]),  y+f2*dy+b*(u[1]),  z+f2*dz+b*(u[2]));
      glVertex3d(x+dx,              y+dy,              z+dz);
      glEnd();
    }
    break ;
    
  case DRAW_POST_ARROW_HEAD :
    Msg(ERROR, "Arrow Head not done");
    break ;

  case DRAW_POST_PYRAMID :

    b = .1333 * d;
    
    if(Fill){
      glBegin(GL_TRIANGLES);
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      glVertex3d(x+b*(u[0]),  y+b*(u[1]),  z+b*(u[2]));
      
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(u[0]),  y+b*(u[1]),  z+b*(u[2]));
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glEnd();
    }
    else{
      glBegin(GL_LINE_LOOP);
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      glVertex3d(x+b*(u[0]),  y+b*(u[1]),  z+b*(u[2]));
      glEnd();
      
      glBegin(GL_LINES);
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      
      glVertex3d (x+b*(u[0]), y+b*(u[1]),  z+b*(u[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      glEnd();
    }
    break ;

  case DRAW_POST_CONE :

    b = .1333 * d;
    c = .7071 * b; 

    if(Fill){
      glBegin(GL_TRIANGLES);
      glVertex3d(x+b*(t[0]),       y+b*(t[1]),       z+b*(t[2]));
      glVertex3d(x+c*(t[0]-u[0]),  y+c*(t[1]-u[1]),  z+c*(t[2]-u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(t[0]-u[0]),  y+c*(t[1]-u[1]),  z+c*(t[2]-u[2]));
      glVertex3d(x+b*(-u[0]),      y+b*(-u[1]),      z+b*(-u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+b*(-u[0]),      y+b*(-u[1]),      z+b*(-u[2]));
      glVertex3d(x+c*(-t[0]-u[0]), y+c*(-t[1]-u[1]), z+c*(-t[2]-u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(-t[0]-u[0]), y+c*(-t[1]-u[1]), z+c*(-t[2]-u[2]));
      glVertex3d(x+b*(-t[0]),      y+b*(-t[1]),      z+b*(-t[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+b*(-t[0]),      y+b*(-t[1]),      z+b*(-t[2]));
      glVertex3d(x+c*(u[0]-t[0]),  y+c*(u[1]-t[1]),  z+c*(u[2]-t[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(u[0]-t[0]),  y+c*(u[1]-t[1]),  z+c*(u[2]-t[2]));
      glVertex3d(x+b*(u[0]),       y+b*(u[1]),       z+b*(u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+b*(u[0]),       y+b*(u[1]),       z+b*(u[2]));
      glVertex3d(x+c*(t[0]+u[0]),  y+c*(t[1]+u[1]),  z+c*(t[2]+u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(t[0]+u[0]),  y+c*(t[1]+u[1]),  z+c*(t[2]+u[2]));
      glVertex3d(x+b*(t[0]),       y+b*(t[1]),       z+b*(t[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      glEnd();
    }
    else{
      glBegin(GL_LINE_LOOP);
      glVertex3d(x+b*(t[0]),       y+b*(t[1]),       z+b*(t[2]));
      glVertex3d(x+c*(t[0]-u[0]),  y+c*(t[1]-u[1]),  z+c*(t[2]-u[2]));
      glVertex3d(x+b*(-u[0]),      y+b*(-u[1]),      z+b*(-u[2]));
      glVertex3d(x+c*(-t[0]-u[0]), y+c*(-t[1]-u[1]), z+c*(-t[2]-u[2]));
      glVertex3d(x+b*(-t[0]),      y+b*(-t[1]),      z+b*(-t[2]));
      glVertex3d(x+c*(u[0]-t[0]),  y+c*(u[1]-t[1]),  z+c*(u[2]-t[2]));
      glVertex3d(x+b*(u[0]),       y+b*(u[1]),       z+b*(u[2]));
      glVertex3d(x+c*(t[0]+u[0]),  y+c*(t[1]+u[1]),  z+c*(t[2]+u[2]));
      glEnd();
      
      glBegin(GL_LINES);
      glVertex3d(x+b*(t[0]),       y+b*(t[1]),       z+b*(t[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(t[0]-u[0]),  y+c*(t[1]-u[1]),  z+c*(t[2]-u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+b*(-u[0]),      y+b*(-u[1]),      z+b*(-u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(-t[0]-u[0]), y+c*(-t[1]-u[1]), z+c*(-t[2]-u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+b*(-t[0]),      y+b*(-t[1]),      z+b*(-t[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(u[0]-t[0]),  y+c*(u[1]-t[1]),  z+c*(u[2]-t[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+b*(u[0]),       y+b*(u[1]),       z+b*(u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      
      glVertex3d(x+c*(t[0]+u[0]),  y+c*(t[1]+u[1]),  z+c*(t[2]+u[2]));
      glVertex3d(x+dx,             y+dy,             z+dz);
      glEnd();
    }
    break ;

  default :
    Msg(ERROR, "Unknown Type of Vector to Draw");
    break;
  }
  
}

