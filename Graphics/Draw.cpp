
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "MinMax.h"

#include "CbGeneral.h"

#ifdef _UNIX
#include "Widgets.h"
#include "XContext.h"
extern XContext_T   XCTX ;
extern Widgets_T    WID ;
#endif

extern Context_T    CTX ;
extern GLdouble     vxmin, vxmax, vymin, vymax;
extern Mesh         M;
extern double       LC;
extern List_T      *Post_ViewList;

/* ------------------------------------------------------------------------ */
/*  d r a w                                                                 */
/* ------------------------------------------------------------------------ */

void Draw3d(void){
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
  glEnable(GL_CLIP_PLANE0);

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
  glDisable(GL_CLIP_PLANE0);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glShadeModel(GL_FLAT);

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
  if(CTX.little_axes) Draw_SmallAxes();
  glPopMatrix();
}

#ifdef _UNIX
void Draw(void){
  glClearColor(UNPACK_RED(CTX.color.bg)/255.,
	       UNPACK_GREEN(CTX.color.bg)/255.,
	       UNPACK_BLUE(CTX.color.bg)/255.,
	       0.);
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  if(CTX.db) glDrawBuffer(GL_BACK);    
  Draw3d();
  Draw2d();
  glFlush();
  if(CTX.db) glXSwapBuffers(XCTX.display,XtWindow(WID.G.glw));
}
#else
void Draw(void){
  if(CTX.db) glDrawBuffer(GL_BACK);
  glClearColor(UNPACK_RED(CTX.color.bg)/255.,
	       UNPACK_GREEN(CTX.color.bg)/255.,
	       UNPACK_BLUE(CTX.color.bg)/255.,
	       0.);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  Draw3d();
  Draw2d();
  glFlush();
  if(CTX.db) MySwapBuffers();
  if(CTX.db) glDrawBuffer(GL_FRONT);
}
#endif

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
    vxmin = CTX.min[0];
    vxmax = CTX.max[0];
    vymin = 0.5*(CTX.min[1]+CTX.max[1]-Va*(CTX.max[0]-CTX.min[0]));
    vymax = 0.5*(CTX.min[1]+CTX.max[1]+Va*(CTX.max[0]-CTX.min[0]));
  }
  else{
    vxmin = 0.5*(CTX.min[0]+CTX.max[0]-(CTX.max[1]-CTX.min[1])/Va);
    vxmax = 0.5*(CTX.min[0]+CTX.max[0]+(CTX.max[1]-CTX.min[1])/Va);
    vymin = CTX.min[1];
    vymax = CTX.max[1];
  }
  vxmin -= (vxmax-vxmin)/3.; vxmax += 0.25*(vxmax-vxmin);
  vymin -= (vymax-vymin)/3.; vymax += 0.25*(vymax-vymin);

  CTX.pixel_equiv_x = (vxmax-vxmin)/(CTX.viewport[2]-CTX.viewport[0]);
  CTX.pixel_equiv_y = (vymax-vymin)/(CTX.viewport[3]-CTX.viewport[1]);
  
  if(CTX.ortho) {
    glOrtho(vxmin,vxmax,vymin,vymax,0,100*LC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
    glTranslated(0.0, 0.0, -50*LC);
  }
  else{
    glFrustum(vxmin,vxmax,vymin,vymax,LC,100*LC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
    glTranslated(0.0, 0.0, -10*LC);
    glScaled(10.,10.,10.);
  }


}


/* ------------------------------------------------------------------------ */
/*  i n i t                                                                 */
/* ------------------------------------------------------------------------ */

void Init(void){
  /* 
     Attention:
     X11 interdit de changer le contexte (GLX) en mode GL_FEEDBACK ou GL_SELECT,
     ce qui serait le cas pour les sorties postscript...
  */
#ifdef _UNIX
  if(CTX.stream == TO_SCREEN)
    glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
#endif
  Orthogonalize(0,0);
}

void InitOv(void){
#ifdef _UNIX
  glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
#endif
  Orthogonalize(0,0);
}

void InitShading(void){
  GLfloat specular[4];

  glLightfv(GL_LIGHT0, GL_POSITION, CTX.light0);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);

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
  glRotated   (CTX.r[0], 1., 0., 0.);
  glRotated   (CTX.r[1], 0., 1., 0.);
  glRotated   (CTX.r[2], 0., 0., 1.);
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

void process_selection(int x, int y, int *n, GLuint *ii, GLuint *jj){
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
      if (j==0)	ii[i] = *ptr;
      else if (j==1) jj[i] = *ptr;
      ptr++;
    }
  }
  *n = hits;
}

void filtre_selection(int n, GLuint *typ, GLuint *ient, Vertex **thev,
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
	if(Tree_Query(m->Points,&v)){
	  *thev = v;
	}
	break;
      case 1:
	c = &C;
	c->Num = ient[i];
	if(Tree_Query(m->Curves,&c)){
	  *thec = c;
	}
	break;
      case 2:
	s = &S;
	s->Num = ient[i];
	if(Tree_Query(m->Surfaces,&s)){
	  *thes = s;
	}
	break;
      }
    }
  }
}


#ifdef _UNIX

int check_type(int type, Vertex *v, Curve *c, Surface *s){
  return ( (type==ENT_POINT   && v) ||
	   (type==ENT_LINE    && c) ||
	   (type==ENT_SURFACE && s) ) ;
}

int SelectEntity(int type, Vertex **v, Curve **c, Surface **s){
  XEvent          event;
  XComposeStatus  stat;
  KeySym          keysym;
  int             hits;
  GLuint          ii[SELECTION_BUFFER_SIZE],jj[SELECTION_BUFFER_SIZE];
  char            buf[100];

  *v = NULL;
  *c = NULL; 
  *s = NULL;

  while(1){
    XtAppNextEvent(XCTX.AppContext,&event);
    XtDispatchEvent(&event);
    switch(event.type){
    case KeyPress :
      XLookupString(&event.xkey, buf, sizeof(buf), &keysym, &stat);
      if(keysym == XK_q) return(0);
      if(keysym == XK_e) return(-1);
      break;
    case ButtonPress :
      process_selection(event.xbutton.x, event.xbutton.y, &hits, ii, jj);
      filtre_selection(hits,ii,jj,v,c,s,&M);
      if(check_type(type,*v,*c,*s)){
	begin_highlight();
	highlight_entity(*v,*c,*s,1);
	end_highlight(1);
	return(event.xbutton.button);
      }
    }
  }
}

#else

int SelectEntity(int x, int y, Vertex **v, Curve **c, Surface **s){
  int             hits,i,j;
  GLuint          ii[SELECTION_BUFFER_SIZE],jj[SELECTION_BUFFER_SIZE];

  process_selection(x, y, &hits, ii, jj);
  *v = NULL;
  *s = NULL;
  *c = NULL;
  filtre_selection(hits,ii,jj,v,c,s,&M);
  begin_highlight();
  highlight_entity(*v,*c,*s,1);
  end_highlight(1);
  return(1);
}

#endif


/* ------------------------------------------------------------------------ */
/*  z o o m                                                                 */
/* ------------------------------------------------------------------------ */


void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
	    GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2){
  GLdouble  xscale1, yscale1;

  xscale1 = CTX.s[0];
  yscale1 = CTX.s[1];
  set_s(0, CTX.s[0] * (vxmax-vxmin)/(X2-X1));
  set_s(1, CTX.s[1] * (vymax-vymin)/(Y1-Y2));
  /* bif bif bif */
  set_s(2, 0.5*(CTX.s[0]+CTX.s[1]));
  set_t(0, CTX.t[0] * (xscale1/CTX.s[0]) - ((Xc1+Xc2)/2.)*(1.-(xscale1/CTX.s[0])));
  set_t(1, CTX.t[1] * (yscale1/CTX.s[1]) - ((Yc1+Yc2)/2.)*(1.-(yscale1/CTX.s[1])));
  Init();
  Draw();
}

/* ------------------------------------------------------------------------ */
/*  InitCb, ResizeCb, ExposeCb                                              */
/* ------------------------------------------------------------------------ */

#ifdef _UNIX

void InitCb(Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *cb){
  glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
  CTX.viewport[0] = 0 ;
  CTX.viewport[1] = 0 ;
  CTX.viewport[2] = cb->width ;
  CTX.viewport[3] = cb->height ;
  glViewport(CTX.viewport[0],
	     CTX.viewport[1],
	     CTX.viewport[2],
	     CTX.viewport[3]);
}

void ResizeCb(Widget w,XtPointer client_data, GLwDrawingAreaCallbackStruct *cb){
  CTX.viewport[0] = 0 ;
  CTX.viewport[1] = 0 ;
  CTX.viewport[2] = cb->width ;
  CTX.viewport[3] = cb->height ;
  glViewport(CTX.viewport[0],
	     CTX.viewport[1],
	     CTX.viewport[2],
	     CTX.viewport[3]);
  Init();
  Draw();
  if(CTX.overlay) InitOv();
}

void ExposeCb(Widget w,XtPointer client_data, GLwDrawingAreaCallbackStruct *cb){

  /* compress incoming events as much as possible */
  if(cb->event->xexpose.count != 0){
    return;
  }

  if(!CTX.expose) return;
  Init();
  Draw(); 

}

#endif
