// $Id: Opengl.cpp,v 1.2 2001-01-10 10:06:18 geuzaine Exp $

#include <X11/IntrinsicP.h>

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "MinMax.h"
#include "Widgets.h"
#include "XContext.h"
#include "gl2ps.h"

extern XContext_T   XCTX ;
extern Widgets_T    WID ;
extern Context_T    CTX ;
extern Mesh         M;

void Process_SelectionBuffer(int x, int y, int *n, GLuint *ii, GLuint *jj);
void Filter_SelectionBuffer(int n, GLuint *typ, GLuint *ient, Vertex **thev,
                            Curve **thec, Surface **thes, Mesh *m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);

/* ------------------------------------------------------------------------ */
/*  Init/Draw                                                               */
/* ------------------------------------------------------------------------ */

void Init(void){

  /* Resize Graphical Window if told to do it */
  XWindowAttributes  xattrib;
  XGetWindowAttributes(XtDisplay(WID.G.bottomForm),XtWindow(WID.G.bottomForm),&xattrib);
  XtResizeWidget(WID.G.shell,
		 CTX.viewport[2]-CTX.viewport[0],
		 xattrib.height+CTX.viewport[3]-CTX.viewport[1],
		 0);

  /* X11 forbids to change the context (GLX) in GL_FEEDBACK or GL_SELECT mode,
     which would happen for postscript output */
  if(CTX.stream == TO_SCREEN)
    glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);

  Orthogonalize(0,0);
}

void InitOverlay(void){
  glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
  Orthogonalize(0,0);
}

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

void DrawOverlay(void){
}

void DrawUI(void){
}

void Draw_String(char *s){

  if(CTX.stream == TO_FILE){
    if(!CTX.print.gl_fonts && CTX.print.eps_quality > 0){
      gl2psText(s,CTX.print.font,CTX.print.font_size);
      return ;
    }
  }

  glListBase(CTX.font_base);
  glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte *)s);
}

/* ------------------------------------------------------------------------ */
/*  SelectEntity                                                            */
/* ------------------------------------------------------------------------ */


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
      Process_SelectionBuffer(event.xbutton.x, event.xbutton.y, &hits, ii, jj);
      Filter_SelectionBuffer(hits,ii,jj,v,c,s,&M);
      if(check_type(type,*v,*c,*s)){
        BeginHighlight();
        HighlightEntity(*v,*c,*s,1);
        EndHighlight(1);
        return(event.xbutton.button);
      }
    }
  }
}

/* ------------------------------------------------------------------------ */
/*  Callbacks                                                               */
/* ------------------------------------------------------------------------ */

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
  if(CTX.overlay) InitOverlay();
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

