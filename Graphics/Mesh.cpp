// $Id: Mesh.cpp,v 1.15 2001-01-09 14:24:09 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "MinMax.h"
#include "gl2ps.h"
#include "Verif.h"
#include "Numeric.h"
#include "Visibility.h"

extern Mesh      *THEM;
extern Context_T  CTX;

static int        iVolume;

/* ------------------------------------------------------------------------ */
/*  D r a w _ M e s h                                                       */
/* ------------------------------------------------------------------------ */


void draw_polygon_2d (double r, double g, double b, int n, 
                      double *x, double *y, double *z){
  int i ;

  CalculateMinMax(THEM->Points);
  Init();
  InitPosition();

  glDisable(GL_DEPTH_TEST);
  glDrawBuffer(GL_FRONT);
  glColor3f(r,g,b);
  glBegin(GL_LINE_STRIP);
  for(i=0 ; i<n ; i++)
    if(z)glVertex3d(x[i], y[i],z[i]);
    else  glVertex2d(x[i], y[i]);
  glEnd();
  glFlush();
  glDrawBuffer(GL_BACK);
  glEnable(GL_DEPTH_TEST);

}

void ColorSwitch(int i){
  glColor4ubv((GLubyte*)&CTX.color.mesh.carousel[i%10]);
}

static int DrawVertexSupp ;

void Draw_Mesh (Mesh *M) {
  int i;

  if(CTX.mesh.shade)
    InitShading();
  else
    InitNoShading();

  InitPosition();

  for(i = 0 ; i < 6 ; i++)
    if(CTX.clip[i])
      glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), CTX.clip_plane[i]);

  glPointSize(2);
  glLineWidth(1);

  if(CTX.mesh.hidden) glEnable(GL_POLYGON_OFFSET_FILL);

  switch(M->status) {
  case 3 :
    if(CTX.mesh.draw && 
       (CTX.mesh.volumes || CTX.mesh.volumes_num) &&
       CTX.render_mode != GMSH_SELECT)
      Tree_Action(M->Volumes, Draw_Mesh_Volumes);
    /* fall-through! */
  case 2 :
    if(CTX.mesh.draw && 
       (CTX.mesh.surfaces || CTX.mesh.surfaces_num) &&
       CTX.render_mode != GMSH_SELECT){
      Tree_Action(M->Surfaces, Draw_Mesh_Surfaces);
    }
    /* fall-through! */
  case 1 :  
    if(CTX.mesh.draw && 
       (CTX.mesh.lines || CTX.mesh.lines_num) &&
       CTX.render_mode != GMSH_SELECT){
      Tree_Action(M->Curves, Draw_Mesh_Curves);
      DrawVertexSupp = 1 ; 
      Tree_Action(M->VertexEdges,Draw_Mesh_Points);
    }
    /* fall-through! */
  case 0 :  
    if(CTX.mesh.draw && 
       (CTX.mesh.points || CTX.mesh.points_num) &&
       CTX.render_mode != GMSH_SELECT){
      DrawVertexSupp = 0 ; 
      Tree_Action(M->Vertices,Draw_Mesh_Points);
    }
    glPointSize(4);
    if(!CTX.geom.shade) InitNoShading();
    Draw_Geom(M);
    break;
  default :
    break;
  }

  if(CTX.mesh.hidden) glDisable(GL_POLYGON_OFFSET_FILL);

  if(CTX.render_mode != GMSH_SELECT){
    if(CTX.axes) 
      Draw_Axes(CTX.lc_middle/4.);
    if(CTX.post.draw) /* les init de shading se font par view */
      Draw_Post();
  }
}

void Draw_Mesh_Volumes(void *a, void *b){
  Volume **v;
  v = (Volume**)a;
  Tree_Action((*v)->Simplexes, Draw_Simplex_Volume);
  Tree_Action((*v)->Hexahedra, Draw_Hexahedron_Volume);
  Tree_Action((*v)->Prisms, Draw_Prism_Volume);
}

void PremierVolume(int iSurf, int *iVol);

void Draw_Mesh_Surfaces (void *a,void *b){
  Surface **s;
  s = (Surface**)a;
  PremierVolume(abs((*s)->Num),&iVolume);
  iVolume = -iVolume;
  Tree_Action((*s)->Simplexes, Draw_Simplex_Surfaces);
}

void Draw_Mesh_Curves (void *a, void *b){
  Curve **c;

  c = (Curve**)a;
  if((*c)->Num < 0)return;
  Tree_Action((*c)->Simplexes,Draw_Simplex_Points);
}


void Draw_Mesh_Points (void *a, void *b){
  Vertex **v;
  char Num[100];

  v = (Vertex**)a;

  if(CTX.render_mode == GMSH_SELECT){
    glLoadName(0);
    glPushName((*v)->Num);
  }

  glPointSize(3);
  if(DrawVertexSupp) 
    glColor4ubv((GLubyte*)&CTX.color.mesh.vertex_supp);
  else
    glColor4ubv((GLubyte*)&CTX.color.mesh.vertex);

  if(CTX.mesh.points){
    glBegin(GL_POINTS);
    glVertex3d((*v)->Pos.X, (*v)->Pos.Y, (*v)->Pos.Z);
    glEnd();
  }
  
  if(CTX.mesh.points_num){
    sprintf(Num,"%d",(*v)->Num);
    glRasterPos3d((*v)->Pos.X+3*CTX.pixel_equiv_x/CTX.s[0],
                  (*v)->Pos.Y+3*CTX.pixel_equiv_x/CTX.s[1], 
                  (*v)->Pos.Z+3*CTX.pixel_equiv_x/CTX.s[2]);
    Draw_String(Num);
  }
  
  if(CTX.render_mode == GMSH_SELECT){
    glPopName();
  }
}

/* ------------------------------------------------------------------------ */
/*  D r a w _ S i m p l e x                                                 */
/* ------------------------------------------------------------------------ */

void Draw_Simplex_Volume (void *a, void *b){
  Simplex **s;
  char Num[100];
  double X[4],Y[4],Z[4];

  s = (Simplex**)a;

  if(!EntiteEstElleVisible((*s)->iEnt)) return;

  if(!(*s)->V[3]) return;

  if(CTX.mesh.limit_gamma){
    if((*s)->GammaShapeMeasure() > CTX.mesh.limit_gamma) return;
  }
  if(CTX.mesh.limit_eta){
    if((*s)->EtaShapeMeasure() > CTX.mesh.limit_eta) return;
  }
  if(CTX.mesh.limit_rho){
    if((*s)->RhoShapeMeasure() > CTX.mesh.limit_rho) return;
  }

  ColorSwitch((*s)->iEnt+1);

  double Xc = .25 * ((*s)->V[0]->Pos.X + (*s)->V[1]->Pos.X + 
                     (*s)->V[2]->Pos.X + (*s)->V[3]->Pos.X);
  double Yc = .25 * ((*s)->V[0]->Pos.Y + (*s)->V[1]->Pos.Y + 
                     (*s)->V[2]->Pos.Y + (*s)->V[3]->Pos.Y);
  double Zc = .25 * ((*s)->V[0]->Pos.Z + (*s)->V[1]->Pos.Z + 
                     (*s)->V[2]->Pos.Z + (*s)->V[3]->Pos.Z);

  for (int i=0 ; i<4 ; i++) {
     X[i] = Xc + CTX.mesh.explode * ((*s)->V[i]->Pos.X - Xc);
     Y[i] = Yc + CTX.mesh.explode * ((*s)->V[i]->Pos.Y - Yc);
     Z[i] = Zc + CTX.mesh.explode * ((*s)->V[i]->Pos.Z - Zc);
  }

  if(CTX.mesh.volumes){
    glBegin(GL_LINES);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[0], Y[0], Z[0]);
    
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[0], Y[0], Z[0]);
    
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[0], Y[0], Z[0]);
    
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[1], Y[1], Z[1]);
    
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[2], Y[2], Z[2]);
    
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[3], Y[3], Z[3]);
    glEnd();
  }

  if(CTX.mesh.volumes_num){
    sprintf(Num,"%d",(*s)->Num);
    glRasterPos3d(Xc,Yc,Zc);
    Draw_String(Num);
  }


  if (CTX.mesh.dual){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d((X[0]+X[1]+X[2])/3., (Y[0]+Y[1]+Y[2])/3., (Z[0]+Z[1]+Z[2])/3.);
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d((X[0]+X[1]+X[3])/3., (Y[0]+Y[1]+Y[3])/3., (Z[0]+Z[1]+Z[3])/3.);
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d((X[0]+X[2]+X[3])/3., (Y[0]+Y[2]+Y[3])/3., (Z[0]+Z[2]+Z[3])/3.);
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d((X[1]+X[2]+X[3])/3., (Y[1]+Y[2]+Y[3])/3., (Z[1]+Z[2]+Z[3])/3.);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

#if 0 /* never here for the moment */

  double n[4], x1x0, y1y0, z1z0, x2x0, y2y0, z2z0;

  ColorSwitch((*s)->iEnt);

  if (CTX.mesh.hidden) {

    x1x0 = X[1]-X[0]; y1y0 = Y[1]-Y[0];
    z1z0 = Z[1]-Z[0]; x2x0 = X[2]-X[0];
    y2y0 = Y[2]-Y[0]; z2z0 = Z[2]-Z[0];
    n[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    n[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    n[2]  = x1x0 * y2y0 - y1y0 * x2x0;
    glNormal3dv(n);

    glBegin(GL_TRIANGLES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glEnd();

    x1x0 = X[1]-X[0]; y1y0 = Y[1]-Y[0];
    z1z0 = Z[1]-Z[0]; x2x0 = X[3]-X[0];
    y2y0 = Y[3]-Y[0]; z2z0 = Z[3]-Z[0];
    n[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    n[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    n[2]  = x1x0 * y2y0 - y1y0 * x2x0;
    glNormal3dv(n);

    glBegin(GL_TRIANGLES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[3], Y[3], Z[3]);
    glEnd();

    x1x0 = X[3]-X[0]; y1y0 = Y[3]-Y[0];
    z1z0 = Z[3]-Z[0]; x2x0 = X[2]-X[0];
    y2y0 = Y[2]-Y[0]; z2z0 = Z[2]-Z[0];
    n[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    n[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    n[2]  = x1x0 * y2y0 - y1y0 * x2x0;
    glNormal3dv(n);


    glBegin(GL_TRIANGLES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[3], Y[3], Z[3]);
    glEnd();

    x1x0 = X[3]-X[1]; y1y0 = Y[3]-Y[1];
    z1z0 = Z[3]-Z[1]; x2x0 = X[2]-X[1];
    y2y0 = Y[2]-Y[1]; z2z0 = Z[2]-Z[1];
    n[0]  = y1y0 * z2z0 - z1z0 * y2y0 ;
    n[1]  = z1z0 * x2x0 - x1x0 * z2z0 ;
    n[2]  = x1x0 * y2y0 - y1y0 * x2x0;
    glNormal3dv(n);

    glBegin(GL_TRIANGLES);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glEnd();

  }

#endif

}


void Draw_Simplex_Surfaces (void *a, void *b){

  Simplex **s;
  double X[4],Y[4],Z[4],Xc,Yc,Zc,pX[8],pY[8],pZ[8];
  double x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, n[3], m[3], mm;
  int i,j,K,L,k;
  char Num[256];
  
  s = (Simplex**)a;

  if(!(*s)->V[2]) return ;

  if(!EntiteEstElleVisible ((*s)->iEnt)) return;
  
  if((*s)->VSUP) L=1;
  else L=0;

  if ((*s)->V[3]) {
    K = 4;
    Xc = .25 * ((*s)->V[0]->Pos.X + (*s)->V[1]->Pos.X + 
                (*s)->V[2]->Pos.X + (*s)->V[3]->Pos.X);
    Yc = .25 * ((*s)->V[0]->Pos.Y + (*s)->V[1]->Pos.Y + 
                (*s)->V[2]->Pos.Y + (*s)->V[3]->Pos.Y);
    Zc = .25 * ((*s)->V[0]->Pos.Z + (*s)->V[1]->Pos.Z + 
                (*s)->V[2]->Pos.Z + (*s)->V[3]->Pos.Z);
  }
  else {
    K = 3;
    Xc = ((*s)->V[0]->Pos.X + (*s)->V[1]->Pos.X + (*s)->V[2]->Pos.X) / 3. ;
    Yc = ((*s)->V[0]->Pos.Y + (*s)->V[1]->Pos.Y + (*s)->V[2]->Pos.Y) / 3. ;
    Zc = ((*s)->V[0]->Pos.Z + (*s)->V[1]->Pos.Z + (*s)->V[2]->Pos.Z) / 3. ;
  }

  k=0;
  for (i=0 ; i<K ; i++) {
    pX[k] = Xc + CTX.mesh.explode * ((*s)->V[i]->Pos.X - Xc);
    pY[k] = Yc + CTX.mesh.explode * ((*s)->V[i]->Pos.Y - Yc);
    pZ[k] = Zc + CTX.mesh.explode * ((*s)->V[i]->Pos.Z - Zc);
    k+=(L+1);
  }
  
  if(L){
    k=1;
    for (i=0 ; i<K ; i++) {
      pX[k] = Xc + CTX.mesh.explode * ((*s)->VSUP[i]->Pos.X - Xc);
      pY[k] = Yc + CTX.mesh.explode * ((*s)->VSUP[i]->Pos.Y - Yc);
      pZ[k] = Zc + CTX.mesh.explode * ((*s)->VSUP[i]->Pos.Z - Zc);      
      k+=(L+1);
    }
  }

  if (CTX.mesh.dual){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    for (i=0 ; i<K ; i++) {
      (!i) ? j = K-1 : j = i-1 ;
      glVertex3d(Xc,   Yc,    Zc);  
      glVertex3d((pX[i]+pX[j])/2., (pY[i]+pY[j])/2., (pZ[i]+pZ[j])/2.);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if (CTX.mesh.normals || CTX.mesh.shade){
    for (i=0 ; i<K ; i++) {
     X[i] = Xc + CTX.mesh.explode * ((*s)->V[i]->Pos.X - Xc);
     Y[i] = Yc + CTX.mesh.explode * ((*s)->V[i]->Pos.Y - Yc);
     Z[i] = Zc + CTX.mesh.explode * ((*s)->V[i]->Pos.Z - Zc);
    }
    x1x0 = X[1]-X[0]; y1y0 = Y[1]-Y[0];
    z1z0 = Z[1]-Z[0]; x2x0 = X[2]-X[0];
    y2y0 = Y[2]-Y[0]; z2z0 = Z[2]-Z[0];
    n[0] = m[0] = y1y0 * z2z0 - z1z0 * y2y0 ;
    n[1] = m[1] = z1z0 * x2x0 - x1x0 * z2z0 ;
    n[2] = m[2] = x1x0 * y2y0 - y1y0 * x2x0;
    // norme(n); not necessary with glEnable(GL_NORMALIZE);
    /* BOF BOF BOF
    if(n[2] < -0.1){
      n[0] = -n[0];
      n[1] = -n[1];
      n[2] = -n[2];
    }
    */
  }

  if (CTX.mesh.hidden && CTX.mesh.shade){
    glNormal3dv(n);
  }
  
  //  ColorSwitch(abs(iVolume));
  //  printf("%d\n",(*s)->iEnt);
  ColorSwitch((*s)->iEnt);

  if(CTX.mesh.surfaces_num){
    sprintf(Num,"%d",(*s)->Num);
    glRasterPos3d(Xc,Yc,Zc);
    Draw_String(Num);
  }


  if(CTX.mesh.surfaces){

    if (CTX.mesh.hidden) { 
      glBegin(GL_POLYGON);
      for(i=0 ; i<K*(1+L) ; i++) glVertex3d(pX[i], pY[i], pZ[i]);
      glEnd();
    }
    
    if(CTX.mesh.lines){
      glColor4ubv((GLubyte*)&CTX.color.mesh.line);
      glBegin(GL_LINE_LOOP);
      for(i=0 ; i<K*(1+L) ; i++){
        glVertex3d(pX[i],pY[i],pZ[i]);
      }
      glEnd();    
    }

  }
  
  if(CTX.mesh.normals) {
    norme(m);
    glColor4ubv((GLubyte*)&CTX.color.mesh.normals);
    m[0] *= CTX.mesh.normals * CTX.pixel_equiv_x/CTX.s[0] ;
    m[1] *= CTX.mesh.normals * CTX.pixel_equiv_x/CTX.s[1] ;
    m[2] *= CTX.mesh.normals * CTX.pixel_equiv_x/CTX.s[2] ;
    mm=sqrt(m[0]*m[0]+m[1]*m[1]+m[2]*m[2]);
    Draw_Vector(DRAW_POST_ARROW, 0, Xc,Yc,Zc, mm, m[0],m[1],m[2],NULL,NULL);
  }
  

}


void Draw_Simplex_Points(void *a,void *b){
  Simplex *s;
  char Num[100];

  s = *(Simplex**)a;

  glColor4ubv((GLubyte*)&CTX.color.mesh.vertex);
  
  glBegin(GL_POINTS);
  glVertex3d(s->V[1]->Pos.X, s->V[1]->Pos.Y, s->V[1]->Pos.Z);
  glEnd();    
  
  if(s->VSUP){
    glColor4ubv((GLubyte*)&CTX.color.mesh.vertex_supp);
    glBegin(GL_POINTS);
    glVertex3d(s->VSUP[0]->Pos.X, s->VSUP[0]->Pos.Y, s->VSUP[0]->Pos.Z);
    glEnd();    
  }

  if(CTX.mesh.lines_num){
    glColor4ubv((GLubyte*)&CTX.color.mesh.line);
    sprintf(Num,"%d",s->Num);
    glRasterPos3d(0.5*(s->V[0]->Pos.X+s->V[1]->Pos.X) + 3*CTX.pixel_equiv_x/CTX.s[0],
                  0.5*(s->V[0]->Pos.Y+s->V[1]->Pos.Y) + 3*CTX.pixel_equiv_x/CTX.s[1], 
                  0.5*(s->V[0]->Pos.Z+s->V[1]->Pos.Z) + 3*CTX.pixel_equiv_x/CTX.s[2]);
    Draw_String(Num);
  }


}


/* ------------------------------------------------------------------------ */
/*  D r a w _ H e x a e d r o n                                             */
/* ------------------------------------------------------------------------ */

void Draw_Hexahedron_Volume (void *a, void *b){
  Hexahedron **h;
  int i ;
  double Xc = 0.0 , Yc = 0.0, Zc = 0.0 ;

  h = (Hexahedron**)a;

  if(!EntiteEstElleVisible((*h)->iEnt)) return;
  
  //glColor4ubv((GLubyte*)&CTX.color.mesh.hexahedron);
  ColorSwitch((*h)->iEnt+1);

  glBegin(GL_LINE_LOOP);
  glVertex3d((*h)->V[0]->Pos.X, (*h)->V[0]->Pos.Y, (*h)->V[0]->Pos.Z);
  glVertex3d((*h)->V[1]->Pos.X, (*h)->V[1]->Pos.Y, (*h)->V[1]->Pos.Z);
  glVertex3d((*h)->V[2]->Pos.X, (*h)->V[2]->Pos.Y, (*h)->V[2]->Pos.Z);
  glVertex3d((*h)->V[3]->Pos.X, (*h)->V[3]->Pos.Y, (*h)->V[3]->Pos.Z);
  glEnd();    

  glBegin(GL_LINE_LOOP);
  glVertex3d((*h)->V[4]->Pos.X, (*h)->V[4]->Pos.Y, (*h)->V[4]->Pos.Z);
  glVertex3d((*h)->V[5]->Pos.X, (*h)->V[5]->Pos.Y, (*h)->V[5]->Pos.Z);
  glVertex3d((*h)->V[6]->Pos.X, (*h)->V[6]->Pos.Y, (*h)->V[6]->Pos.Z);
  glVertex3d((*h)->V[7]->Pos.X, (*h)->V[7]->Pos.Y, (*h)->V[7]->Pos.Z);
  glEnd();    

  glBegin(GL_LINES);
  glVertex3d((*h)->V[0]->Pos.X, (*h)->V[0]->Pos.Y, (*h)->V[0]->Pos.Z);
  glVertex3d((*h)->V[4]->Pos.X, (*h)->V[4]->Pos.Y, (*h)->V[4]->Pos.Z);
  glVertex3d((*h)->V[1]->Pos.X, (*h)->V[1]->Pos.Y, (*h)->V[1]->Pos.Z);
  glVertex3d((*h)->V[5]->Pos.X, (*h)->V[5]->Pos.Y, (*h)->V[5]->Pos.Z);
  glVertex3d((*h)->V[2]->Pos.X, (*h)->V[2]->Pos.Y, (*h)->V[2]->Pos.Z);
  glVertex3d((*h)->V[6]->Pos.X, (*h)->V[6]->Pos.Y, (*h)->V[6]->Pos.Z);
  glVertex3d((*h)->V[3]->Pos.X, (*h)->V[3]->Pos.Y, (*h)->V[3]->Pos.Z);
  glVertex3d((*h)->V[7]->Pos.X, (*h)->V[7]->Pos.Y, (*h)->V[7]->Pos.Z);
  glEnd();    

  if (CTX.mesh.dual){
    for(i=0 ; i<8 ; i++){
      Xc += (*h)->V[i]->Pos.X;
      Yc += (*h)->V[i]->Pos.Y;
      Zc += (*h)->V[i]->Pos.Z;
    }
    Xc /= 8. ; 
    Zc /= 8. ; 
    Yc /= 8. ; 

    glColor4ubv((GLubyte*)&CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*h)->V[0]->Pos.X+(*h)->V[1]->Pos.X+(*h)->V[5]->Pos.X+(*h)->V[4]->Pos.X)/4.,
        ((*h)->V[0]->Pos.Y+(*h)->V[1]->Pos.Y+(*h)->V[5]->Pos.Y+(*h)->V[4]->Pos.Y)/4.,
        ((*h)->V[0]->Pos.Z+(*h)->V[1]->Pos.Z+(*h)->V[5]->Pos.Z+(*h)->V[4]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*h)->V[0]->Pos.X+(*h)->V[3]->Pos.X+(*h)->V[2]->Pos.X+(*h)->V[1]->Pos.X)/4.,
        ((*h)->V[0]->Pos.Y+(*h)->V[3]->Pos.Y+(*h)->V[2]->Pos.Y+(*h)->V[1]->Pos.Y)/4.,
        ((*h)->V[0]->Pos.Z+(*h)->V[3]->Pos.Z+(*h)->V[2]->Pos.Z+(*h)->V[1]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*h)->V[0]->Pos.X+(*h)->V[4]->Pos.X+(*h)->V[7]->Pos.X+(*h)->V[3]->Pos.X)/4.,
        ((*h)->V[0]->Pos.Y+(*h)->V[4]->Pos.Y+(*h)->V[7]->Pos.Y+(*h)->V[3]->Pos.Y)/4.,
        ((*h)->V[0]->Pos.Z+(*h)->V[4]->Pos.Z+(*h)->V[7]->Pos.Z+(*h)->V[3]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*h)->V[1]->Pos.X+(*h)->V[2]->Pos.X+(*h)->V[6]->Pos.X+(*h)->V[5]->Pos.X)/4.,
        ((*h)->V[1]->Pos.Y+(*h)->V[2]->Pos.Y+(*h)->V[6]->Pos.Y+(*h)->V[5]->Pos.Y)/4.,
        ((*h)->V[1]->Pos.Z+(*h)->V[2]->Pos.Z+(*h)->V[6]->Pos.Z+(*h)->V[5]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*h)->V[2]->Pos.X+(*h)->V[3]->Pos.X+(*h)->V[7]->Pos.X+(*h)->V[6]->Pos.X)/4.,
        ((*h)->V[2]->Pos.Y+(*h)->V[3]->Pos.Y+(*h)->V[7]->Pos.Y+(*h)->V[6]->Pos.Y)/4.,
        ((*h)->V[2]->Pos.Z+(*h)->V[3]->Pos.Z+(*h)->V[7]->Pos.Z+(*h)->V[6]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*h)->V[4]->Pos.X+(*h)->V[5]->Pos.X+(*h)->V[6]->Pos.X+(*h)->V[7]->Pos.X)/4.,
        ((*h)->V[4]->Pos.Y+(*h)->V[5]->Pos.Y+(*h)->V[6]->Pos.Y+(*h)->V[7]->Pos.Y)/4.,
        ((*h)->V[4]->Pos.Z+(*h)->V[5]->Pos.Z+(*h)->V[6]->Pos.Z+(*h)->V[7]->Pos.Z)/4. );
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

}

/* ------------------------------------------------------------------------ */
/*  D r a w _ P r i s m                                                     */
/* ------------------------------------------------------------------------ */

void Draw_Prism_Volume (void *a, void *b){
  Prism **p;
  int i ;
  double Xc = 0.0 , Yc = 0.0, Zc = 0.0 ;

  p = (Prism**)a;

  if(!EntiteEstElleVisible((*p)->iEnt)) return;
  
  //glColor4ubv((GLubyte*)&CTX.color.mesh.prism);
  ColorSwitch((*p)->iEnt+1);

  glBegin(GL_LINE_LOOP);
  glVertex3d((*p)->V[0]->Pos.X, (*p)->V[0]->Pos.Y, (*p)->V[0]->Pos.Z);
  glVertex3d((*p)->V[1]->Pos.X, (*p)->V[1]->Pos.Y, (*p)->V[1]->Pos.Z);
  glVertex3d((*p)->V[2]->Pos.X, (*p)->V[2]->Pos.Y, (*p)->V[2]->Pos.Z);
  glEnd();    

  glBegin(GL_LINE_LOOP);
  glVertex3d((*p)->V[3]->Pos.X, (*p)->V[3]->Pos.Y, (*p)->V[3]->Pos.Z);
  glVertex3d((*p)->V[4]->Pos.X, (*p)->V[4]->Pos.Y, (*p)->V[4]->Pos.Z);
  glVertex3d((*p)->V[5]->Pos.X, (*p)->V[5]->Pos.Y, (*p)->V[5]->Pos.Z);
  glEnd();    

  glBegin(GL_LINES);
  glVertex3d((*p)->V[0]->Pos.X, (*p)->V[0]->Pos.Y, (*p)->V[0]->Pos.Z);
  glVertex3d((*p)->V[3]->Pos.X, (*p)->V[3]->Pos.Y, (*p)->V[3]->Pos.Z);
  glVertex3d((*p)->V[1]->Pos.X, (*p)->V[1]->Pos.Y, (*p)->V[1]->Pos.Z);
  glVertex3d((*p)->V[4]->Pos.X, (*p)->V[4]->Pos.Y, (*p)->V[4]->Pos.Z);
  glVertex3d((*p)->V[2]->Pos.X, (*p)->V[2]->Pos.Y, (*p)->V[2]->Pos.Z);
  glVertex3d((*p)->V[5]->Pos.X, (*p)->V[5]->Pos.Y, (*p)->V[5]->Pos.Z);
  glEnd();    

  if (CTX.mesh.dual){
    for(i=0 ; i<6 ; i++){
      Xc += (*p)->V[i]->Pos.X;
      Yc += (*p)->V[i]->Pos.Y;
      Zc += (*p)->V[i]->Pos.Z;
    }
    Xc /= 6. ; 
    Zc /= 6. ; 
    Yc /= 6. ; 

    glColor4ubv((GLubyte*)&CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*p)->V[0]->Pos.X+(*p)->V[2]->Pos.X+(*p)->V[1]->Pos.X)/3.,
        ((*p)->V[0]->Pos.Y+(*p)->V[2]->Pos.Y+(*p)->V[1]->Pos.Y)/3.,
        ((*p)->V[0]->Pos.Z+(*p)->V[2]->Pos.Z+(*p)->V[1]->Pos.Z)/3. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*p)->V[3]->Pos.X+(*p)->V[4]->Pos.X+(*p)->V[5]->Pos.X)/3.,
        ((*p)->V[3]->Pos.Y+(*p)->V[4]->Pos.Y+(*p)->V[5]->Pos.Y)/3.,
        ((*p)->V[3]->Pos.Z+(*p)->V[4]->Pos.Z+(*p)->V[5]->Pos.Z)/3. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*p)->V[0]->Pos.X+(*p)->V[1]->Pos.X+(*p)->V[4]->Pos.X+(*p)->V[3]->Pos.X)/4.,
        ((*p)->V[0]->Pos.Y+(*p)->V[1]->Pos.Y+(*p)->V[4]->Pos.Y+(*p)->V[3]->Pos.Y)/4.,
        ((*p)->V[0]->Pos.Z+(*p)->V[1]->Pos.Z+(*p)->V[4]->Pos.Z+(*p)->V[3]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*p)->V[0]->Pos.X+(*p)->V[3]->Pos.X+(*p)->V[5]->Pos.X+(*p)->V[2]->Pos.X)/4.,
        ((*p)->V[0]->Pos.Y+(*p)->V[3]->Pos.Y+(*p)->V[5]->Pos.Y+(*p)->V[2]->Pos.Y)/4.,
        ((*p)->V[0]->Pos.Z+(*p)->V[3]->Pos.Z+(*p)->V[5]->Pos.Z+(*p)->V[2]->Pos.Z)/4. );
    glVertex3d(Xc,   Yc,    Zc);  
    glVertex3d
      ( ((*p)->V[1]->Pos.X+(*p)->V[2]->Pos.X+(*p)->V[5]->Pos.X+(*p)->V[4]->Pos.X)/4.,
        ((*p)->V[1]->Pos.Y+(*p)->V[2]->Pos.Y+(*p)->V[5]->Pos.Y+(*p)->V[4]->Pos.Y)/4.,
        ((*p)->V[1]->Pos.Z+(*p)->V[2]->Pos.Z+(*p)->V[5]->Pos.Z+(*p)->V[4]->Pos.Z)/4. );
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }


}

