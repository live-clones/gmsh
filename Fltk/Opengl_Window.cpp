// $Id: Opengl_Window.cpp,v 1.6 2001-01-10 21:35:08 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"
#include "Opengl_Window.h"

// This file defines the Opengl_Window class (subclass of Fl_GL_Window)

extern GUI *WID;
extern Mesh M;
extern Context_T CTX;

void Process_SelectionBuffer(int x, int y, int *n, GLuint *ii, GLuint *jj);
void Filter_SelectionBuffer(int n, GLuint *typ, GLuint *ient, Vertex **thev,
                            Curve **thec, Surface **thes, Mesh *m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);

void Opengl_Window::draw() {
  if (!valid()) {
    valid(1);
    CTX.viewport[0] = 0 ;
    CTX.viewport[1] = 0 ;
    CTX.viewport[2] = w() ;
    CTX.viewport[3] = h() ;
    glViewport(CTX.viewport[0],
	       CTX.viewport[1],
	       CTX.viewport[2],
	       CTX.viewport[3]);
  }
  if((w() != CTX.viewport[2]-CTX.viewport[0]) ||
     (h() != CTX.viewport[3]-CTX.viewport[1])){
    WID->set_size(CTX.viewport[2]-CTX.viewport[0],
		  CTX.viewport[3]-CTX.viewport[1]);
    glViewport(CTX.viewport[0],
	       CTX.viewport[1],
	       CTX.viewport[2],
	       CTX.viewport[3]);
  }
  Orthogonalize(0,0);
  glClearColor(UNPACK_RED(CTX.color.bg)/255.,
               UNPACK_GREEN(CTX.color.bg)/255.,
               UNPACK_BLUE(CTX.color.bg)/255.,
               0.);
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  Draw3d();
  Draw2d();
}

void Opengl_Window::clear_overlay() {
  if(CTX.overlay) {}
}

void Opengl_Window::draw_overlay_zoom() {
  /*
  if (!valid()) {
    valid(1);
    CTX.viewport[0] = 0 ;
    CTX.viewport[1] = 0 ;
    CTX.viewport[2] = w() ;
    CTX.viewport[3] = h() ;
    glViewport(CTX.viewport[0],
	       CTX.viewport[1],
	       CTX.viewport[2],
	       CTX.viewport[3]);
  }
  Orthogonalize(0,0);
  glClearIndex(0);
  glClear(GL_COLOR_BUFFER_BIT);  

  glLineWidth(1.);
  glClearIndex(0);
  glClear(GL_COLOR_BUFFER_BIT);  
  glIndexi((CTX.color.bg<CTX.color.fg)?FL_WHITE:FL_BLACK);
  glBegin(GL_LINE_STRIP);
  glVertex2d(xb,yb);
  glVertex2d(xb+movzx,yb);
  glVertex2d(xb+movzx,yb+movzy);
  glVertex2d(xb,yb+movzy);
  glVertex2d(xb,yb);
  glEnd();
  */
}

void Opengl_Window::draw_overlay_highlight(){
  /*
  if(CTX.overlay){
    glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
    if(ov != v || oc != c || os != s) { 
      glClearIndex(0);
      glClear(GL_COLOR_BUFFER_BIT);  
      glIndexi((CTX.color.bg<CTX.color.fg)?XCTX.xcolor.ovwhite:XCTX.xcolor.ovblack);
      BeginHighlight();
      HighlightEntity(v,c,s,0);
      EndHighlight(0);
    }
    glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
  }
  else{
    if(ov != v || oc != c || os != s) { 
      if(CTX.geom.highlight){
	Init();
	Draw();
      }
      BeginHighlight();
      HighlightEntity(v,c,s,0);
      EndHighlight(0);
    }
  }
  */
}

void Opengl_Window::draw_overlay() {
}


static int Modifier=0;

// le principe de FLTK est assez diffrent des autres toolkits: les
// events sont passes au handle du widget qui a le focus. Si ce handle
// revoie 1, alors l'event est considere comme traite, et est
// supprime. Si le handle retourne 0, l'event est passe au handle du
// parent.

int Opengl_Window::handle(int event) {
  GLuint          ii[SELECTION_BUFFER_SIZE], jj[SELECTION_BUFFER_SIZE];
  int             previous_mesh_draw, previous_post_draw ;
  int             width, height ;

  static int      ibut, hits;
  static int      ButtonPressed=0, ZoomClick=0, FirstClick=0;
  static int      x, y, movx, movy;
  static GLdouble xc1, yc1, xc2, yc2, xt1, yt1, xscale1, yscale1;
  static GLdouble xb, yb, xc, yc, xe, ye, xz, yz;
  static GLdouble movzx, movzy;
  static Vertex   *v=NULL, *ov;
  static Curve    *c=NULL, *oc;
  static Surface  *s=NULL, *os;
  
  width  = w() ;
  height = h() ;

  switch (event) {

  case FL_PUSH:
    ButtonPressed++;
    FirstClick=1;
    ibut = Fl::event_button();
    x    = Fl::event_x();
    y    = Fl::event_y();

    switch(ibut){
    case 1:
      if(!ZoomClick && Modifier){
        xb = CTX.vxmin + ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin);
        yb = CTX.vymax - ((GLdouble) y / height) * (CTX.vymax - CTX.vymin);
        xc1 = xb/CTX.s[0] - CTX.t[0];
        yc1 = yb/CTX.s[1] - CTX.t[1];
        ZoomClick=1;
        Modifier = 0;
      }
      else if(ZoomClick){
        xe = CTX.vxmin + ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin);
        ye = CTX.vymax - ((GLdouble) y / height) * (CTX.vymax - CTX.vymin);
        xc2 = xe/CTX.s[0] - CTX.t[0];
        yc2 = ye/CTX.s[1] - CTX.t[1];     
        ZoomClick=0;
        clear_overlay();
        if(xb!=xe && yb!=ye) myZoom(xb,xe,yb,ye,xc1,xc2,yc1,yc2);
      } 
      break;
    case 2:
      if(Modifier && !ZoomClick){
        Modifier = 0;
        set_s(1, CTX.s[0]);
        set_s(2, CTX.s[0]);
        DrawUpdate();
      }
      else{
        ZoomClick=0;
        clear_overlay();
      }
      break;      
    case 3:
      if(Modifier && !ZoomClick){
        Modifier = 0;
	if(CTX.useTrackball){
	  CTX.setQuaternion(0.,0.,0.,1.);
	}
	else{
	  set_r(0,0.); set_r(1,0.); set_r(2,0.); 
	}
        set_t(0,0.); set_t(1,0.); set_t(2,0.);
        set_s(0,1.); set_s(1,1.); set_s(2,1.);
        DrawUpdate();
      }
      else{
        ZoomClick=0;
        clear_overlay();
      }
      break;
    }

    return 1;

  case FL_RELEASE:
    if(ButtonPressed>0){
      ButtonPressed--;
      ibut = Fl::event_button();
      x    = Fl::event_x();
      y    = Fl::event_y();
    }
    if(!ZoomClick){
      previous_mesh_draw = CTX.mesh.draw ;
      previous_post_draw = CTX.post.draw ;
      if(ButtonPressed>0){
        if(CTX.fast) CTX.mesh.draw = CTX.post.draw = 0;
      }
      DrawUpdate();
      CTX.mesh.draw = previous_mesh_draw ;
      CTX.post.draw = previous_post_draw ;
    }
    return 1;

      
  case FL_DRAG:
    movx = Fl::event_x()-x;
    movy = Fl::event_y()-y;

    if(ZoomClick) {
      printf("should draw the zoom... %d %d %d %d\n", x, y, movx, movy);

      xz = CTX.vxmin + ((GLdouble) Fl::event_x() / width) *
	(CTX.vxmax - CTX.vxmin);
      yz = CTX.vymax - ((GLdouble) Fl::event_y() / height) * 
	(CTX.vymax - CTX.vymin) ;

      movzx = xz - xb; movzy = yz - yb;
    }
    else {
      clear_overlay();

      if(FirstClick){
	xc1 = ( ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin) 
		+ CTX.vxmin )/CTX.s[0] - CTX.t[0];
	yc1 = ( CTX.vymax - ((GLdouble) y / height) * 
		(CTX.vymax - CTX.vymin))/CTX.s[1] - CTX.t[1];
	xt1 = CTX.t[0];
	yt1 = CTX.t[1];
	xscale1 = CTX.s[0];
	yscale1 = CTX.s[1];
	FirstClick=0;
      }

      switch(ibut){
      case 1:
	if(CTX.useTrackball){
	  CTX.addQuaternion ((2.0*x - width) / width,
			     (height - 2.0*y) / height,
			     (2.0*Fl::event_x() - width) / width,
			     (height - 2.0*Fl::event_y()) / height);
	}
	else{
	  set_r(1, CTX.r[1] + ((abs(movx) > abs(movy))?180*(float)movx/(float)width:0));
	  set_r(0, CTX.r[0] + ((abs(movx) > abs(movy))?0:180*(float)movy/(float)height));
	}
	break;
      case 2:
	if(!CTX.useTrackball)
	  set_r(2, CTX.r[2] + ((abs(movy) > abs(movx))?0:-180*(float)movx/(float)width));         
	set_s(0, CTX.s[0] * ( (abs(movy) > abs(movx)) ?
			      ( (movy>0) ? (float)(1.04*(abs(movy)+height))/(float)height
				: (float)(height)/(float)(1.04*(abs(movy)+height)) )
			      : 1.) );                    
	set_s(1, CTX.s[0]);
	set_s(2, CTX.s[0]);
	if(abs(movy) > abs(movx)){
	  set_t(0, xt1*(xscale1/CTX.s[0])-xc1*(1.-(xscale1/CTX.s[0])));
	  set_t(1, yt1*(yscale1/CTX.s[1])-yc1*(1.-(yscale1/CTX.s[1])));
	}
	break;
      case 3:
	xc = ( ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin) + 
	       CTX.vxmin ) / CTX.s[0];
	yc = ( CTX.vymax - ((GLdouble) y / height) *
	       (CTX.vymax - CTX.vymin)) / CTX.s[1];
	set_t(0, xc-xc1);
	set_t(1, yc-yc1);
	set_t(2, 0.);
	break;
      }
      previous_mesh_draw = CTX.mesh.draw ;
      previous_post_draw = CTX.post.draw ;
      if(CTX.fast){
	CTX.mesh.draw = 0 ;
	CTX.post.draw = 0;
      }
      DrawUpdate();
      CTX.mesh.draw = previous_mesh_draw ;
      CTX.post.draw = previous_post_draw ;
    }
    x += movx; 
    y += movy; 
    return 1;
    

  case FL_MOVE:
    movx = Fl::event_x()-x;
    movy = Fl::event_y()-y;
    Process_SelectionBuffer(Fl::event_x(), Fl::event_y(), &hits, ii, jj);
    ov = v; oc = c; os = s; v = NULL; c = NULL; s = NULL;
    Filter_SelectionBuffer(hits,ii,jj,&v,&c,&s,&M);


            BeginHighlight();
            HighlightEntity(v,c,s,0);
            EndHighlight(0);


#if 0
    // l'overlay ne marche pas, meme dans les demos de fltk!
    // soumettre un bug ?
    if(ov != v || oc != c || os != s) { 
      WID->make_overlay_current();
      if(ov != v || oc != c || os != s) { 
	glClearIndex(0);
	glClear(GL_COLOR_BUFFER_BIT);  
	glIndexi((CTX.color.bg<CTX.color.fg)?FL_WHITE:FL_BLACK);
	BeginHighlight();
	HighlightEntity(v,c,s,0);
	EndHighlight(0);
      }
      WID->make_current();
    }
#endif
    x += movx; 
    y += movy; 
    return 1;

  default:
    return Fl_Gl_Window::handle(event);

  }

}

