// $Id: Draw.cpp,v 1.15 2001-01-08 08:05:43 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "MinMax.h"
#include "CbGeneral.h"

extern Context_T    CTX ;
extern Mesh         M;

/* ------------------------------------------------------------------------ */
/*  d r a w                                                                 */
/* ------------------------------------------------------------------------ */

void Draw3d(void){
  int i;

  if(CTX.alpha){
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA);
  }
  else{
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA);
  }
  glPolygonOffset(1.0, 1);

  for(i = 0 ; i < 6 ; i++)
    if(CTX.clip[i]) glEnable((GLenum)(GL_CLIP_PLANE0 + i));

  /* This is sufficient, since we NEVER give different normals to nodes of one polygon */
  glShadeModel(GL_FLAT);   //glShadeModel(GL_SMOOTH);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);

  /* glEnable(GL_CULL_FACE); */

  glPushMatrix();
  Draw_Mesh(&M);
  glPopMatrix();  
}

void Draw2d(void){
  int i;

  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glShadeModel(GL_FLAT);

  for(i = 0 ; i < 6 ; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* to draw directly in screen coords */
  glOrtho((double)CTX.viewport[0],
          (double)CTX.viewport[2],
          (double)CTX.viewport[1],
          (double)CTX.viewport[3],-1.,1.);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
  if(CTX.post.scales) Draw_Scales();
  if(CTX.small_axes) Draw_SmallAxes();
  glPopMatrix();
}

/* ------------------------------------------------------------------------ */
/*  o r t h o                                                               */
/* ------------------------------------------------------------------------ */

void Orthogonalize(int x, int y){
  double Va,Wa;
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if(CTX.render_mode == GMSH_SELECT)
    gluPickMatrix ((GLdouble)x, 
                   (GLdouble)(CTX.viewport[3]-y),
                   5.0,
                   5.0,
                   CTX.viewport);

  Va = (GLdouble)(CTX.viewport[3]-CTX.viewport[1]) / 
       (GLdouble)(CTX.viewport[2]-CTX.viewport[0]) ;
  
  Wa = (CTX.max[1]-CTX.min[1]) / (CTX.max[0]-CTX.min[0]);
  
  if(Va>Wa){
    CTX.vxmin = CTX.min[0];
    CTX.vxmax = CTX.max[0];
    CTX.vymin = 0.5*(CTX.min[1]+CTX.max[1]-Va*(CTX.max[0]-CTX.min[0]));
    CTX.vymax = 0.5*(CTX.min[1]+CTX.max[1]+Va*(CTX.max[0]-CTX.min[0]));
  }
  else{
    CTX.vxmin = 0.5*(CTX.min[0]+CTX.max[0]-(CTX.max[1]-CTX.min[1])/Va);
    CTX.vxmax = 0.5*(CTX.min[0]+CTX.max[0]+(CTX.max[1]-CTX.min[1])/Va);
    CTX.vymin = CTX.min[1];
    CTX.vymax = CTX.max[1];
  }
  CTX.vxmin -= (CTX.vxmax-CTX.vxmin)/3.; CTX.vxmax += 0.25*(CTX.vxmax-CTX.vxmin);
  CTX.vymin -= (CTX.vymax-CTX.vymin)/3.; CTX.vymax += 0.25*(CTX.vymax-CTX.vymin);

  CTX.pixel_equiv_x = (CTX.vxmax-CTX.vxmin)/(CTX.viewport[2]-CTX.viewport[0]);
  CTX.pixel_equiv_y = (CTX.vymax-CTX.vymin)/(CTX.viewport[3]-CTX.viewport[1]);
  
  if(CTX.ortho) {
    glOrtho(CTX.vxmin,CTX.vxmax,CTX.vymin,CTX.vymax,0,100*CTX.lc);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
    glTranslated(0.0, 0.0, -50*CTX.lc);
  }
  else{
    glFrustum(CTX.vxmin,CTX.vxmax,CTX.vymin,CTX.vymax,CTX.lc,100*CTX.lc);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
    glTranslated(0.0, 0.0, -10*CTX.lc);
    glScaled(10.,10.,10.);
  }


}

/* ------------------------------------------------------------------------ */
/*  i n i t                                                                 */
/* ------------------------------------------------------------------------ */

void InitShading(void){
  GLfloat specular[4];
  int i;

  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  for(i = 0 ; i < 6 ; i++){
    if(CTX.light[i]){
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_POSITION, CTX.light_position[i]);
      glEnable((GLenum)(GL_LIGHT0 + i));
    }
  }

  /* simple color commands will automatically create appropriate materials */
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  /* let's add some shininess to all these automatically created materials */
  glMaterialf(GL_FRONT, GL_SHININESS, 40.);
  specular[0] = CTX.shine;
  specular[1] = CTX.shine;
  specular[2] = CTX.shine;
  specular[3] = 1.0;
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
}


void InitNoShading(void){
  glDisable(GL_LIGHTING);
}

void InitPosition(void){
  glScaled    (CTX.s[0], CTX.s[1], CTX.s[2]);
  glTranslated(CTX.t[0], CTX.t[1], CTX.t[2]);

  CTX.buildRotmatrix();
  glMultMatrixf(&(CTX.rot[0][0]));
}

/* ------------------------------------------------------------------------ */
/*  r e p l o t                                                             */
/* ------------------------------------------------------------------------ */

/* n'est plus utilise que dans les cas ou des points peuvent etre
   ajoutes dans la base de donnee -> dans cb_geom */
void Replot(void){
  CalculateMinMax(M.Points);
  Init();
  Draw();
}

/* ------------------------------------------------------------------------ */
/*  e n t i t y   s e l e c t i o n                                         */
/* ------------------------------------------------------------------------ */

void Process_SelectionBuffer(int x, int y, int *n, GLuint *ii, GLuint *jj){
  GLuint selectBuf[SELECTION_BUFFER_SIZE];
  GLint  i,j,hits,names,*ptr;

  glSelectBuffer(SELECTION_BUFFER_SIZE, selectBuf);

  glRenderMode(GL_SELECT); 
  CTX.render_mode = GMSH_SELECT;

  glInitNames();
  glPushName(0);

  glPushMatrix();
  Orthogonalize(x,y);
  Draw_Mesh(&M);
  glPopMatrix ();

  hits = glRenderMode(GL_RENDER);
  CTX.render_mode = GMSH_RENDER ;
  
  if(hits<0) return; /* Selection Buffer Overflow */

  ptr = (GLint*)selectBuf;
  
  for(i=0; i<hits; i++){ 
    names = *ptr;
    ptr++; ptr++; ptr++;
    for(j=0; j<names; j++){
      if (j==0) ii[i] = *ptr;
      else if (j==1) jj[i] = *ptr;
      ptr++;
    }
  }
  *n = hits;
}

void Filter_SelectionBuffer(int n, GLuint *typ, GLuint *ient, Vertex **thev,
                            Curve **thec, Surface **thes, Mesh *m){

  Vertex   *v=NULL, V;
  Curve    *c=NULL, C;
  Surface  *s=NULL, S;

  int      i;
  GLuint   typmin;

  typmin = 4;
  for(i=0;i<n;i++){
    if(typ[i]<typmin) typmin = typ[i];
  }
  
  for(i=0;i<n;i++){
    if(typ[i] == typmin){
      switch(typ[i]){
      case 0: 
        v = &V; 
        v->Num = ient[i];
        if(Tree_Query(m->Points,&v)) *thev = v;
        break;
      case 1:
        c = &C;
        c->Num = ient[i];
        if(Tree_Query(m->Curves,&c)) *thec = c;
        break;
      case 2:
        s = &S;
        s->Num = ient[i];
        if(Tree_Query(m->Surfaces,&s)) *thes = s;
        break;
      }
    }
  }
}

/* ------------------------------------------------------------------------ */
/*  z o o m                                                                 */
/* ------------------------------------------------------------------------ */


void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2){
  GLdouble  xscale1, yscale1;

  xscale1 = CTX.s[0];
  yscale1 = CTX.s[1];
  set_s(0, CTX.s[0] * (CTX.vxmax-CTX.vxmin)/(X2-X1));
  set_s(1, CTX.s[1] * (CTX.vymax-CTX.vymin)/(Y1-Y2));
  /* bif bif bif */
  set_s(2, 0.5*(CTX.s[0]+CTX.s[1]));
  set_t(0, CTX.t[0] * (xscale1/CTX.s[0]) - ((Xc1+Xc2)/2.)*(1.-(xscale1/CTX.s[0])));
  set_t(1, CTX.t[1] * (yscale1/CTX.s[1]) - ((Yc1+Yc2)/2.)*(1.-(yscale1/CTX.s[1])));
  Init();
  Draw();
}

