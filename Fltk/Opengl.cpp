// $Id: Opengl.cpp,v 1.4 2001-01-09 15:45:03 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"

extern GUI *WID;
extern Mesh M;
extern Context_T CTX;

void Process_SelectionBuffer(int x, int y, int *n, GLuint *ii, GLuint *jj);
void Filter_SelectionBuffer(int n, GLuint *typ, GLuint *ient, Vertex **thev,
                            Curve **thec, Surface **thes, Mesh *m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);

/* ------------------------------------------------------------------------ */
/*  Init/Draw                                                               */
/* ------------------------------------------------------------------------ */

void Init(void){
  WID->make_gl_current();
}

void InitOverlay(void){
}

void Draw(void){
  WID->draw_gl();
}

void DrawOverlay(void){
  WID->draw_gl_overlay();
}

void DrawUI(void){
  WID->check();
}


/* ------------------------------------------------------------------------ 
    set_XXX
   ------------------------------------------------------------------------ */

void set_r(int i, double val){
  if(!CTX.useTrackball){
    if(!CTX.rlock[i]){
      CTX.r[i] = val;
    }
  }
}

void set_t(int i, double val){
  if(!CTX.tlock[i]){
    CTX.t[i] = val;
  }
}

void set_s(int i, double val){
  if(!CTX.slock[i]){
    CTX.s[i] = val;
  }
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
  int             hits;
  GLuint          ii[SELECTION_BUFFER_SIZE],jj[SELECTION_BUFFER_SIZE];
  int event;

  *v = NULL; *c = NULL; *s = NULL;

  printf("select entity...\n");

  while(1){
    Fl::check();
    if((event = Fl::event_key())){
      if(event == 'q') return(0);
      if(event == 'e') return(-1);
    }
    if(Fl::event_is_click()){
      Process_SelectionBuffer(Fl::event_x(), Fl::event_y(), &hits, ii, jj);
      Filter_SelectionBuffer(hits,ii,jj,v,c,s,&M);
      if(check_type(type,*v,*c,*s)){
        BeginHighlight();
        HighlightEntity(*v,*c,*s,1);
        EndHighlight(1);
        return(Fl::event_button());
      }
    }
  }

}


/* ------------------------------------------------------------------------ */
/*  The OpenGL Widget                                                       */
/* ------------------------------------------------------------------------ */

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
    WID->set_gl_size(CTX.viewport[2]-CTX.viewport[0],
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

  /* -------------------------------------------------------------
     S h o r t c u t s
     ------------------------------------------------------------- */

  case FL_SHORTCUT:
    /*
    m = menu->test_shortcut();
    if (m) {m->do_callback(this, (void*)m); return 1;}
    */
    return 0;

  /* -------------------------------------------------------------
     B u t t o n P r e s s
     ------------------------------------------------------------- */

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
        Init();
        Draw();
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
        Init();
        Draw();
      }
      else{
        ZoomClick=0;
        clear_overlay();
      }
      break;
    }

    return 1;

  /* -------------------------------------------------------------
      B u t t o n R e l e a s e
     ------------------------------------------------------------- */

  case FL_RELEASE:

    if(ButtonPressed>0){
      ButtonPressed--;
      ibut = Fl::event_button();
      x    = Fl::event_x();
      y    = Fl::event_y();
    }
    if(!ZoomClick){
      Init();
      previous_mesh_draw = CTX.mesh.draw ;
      previous_post_draw = CTX.post.draw ;
      if(ButtonPressed>0){
        if(CTX.fast) CTX.mesh.draw = CTX.post.draw = 0;
      }
      Draw();
      CTX.mesh.draw = previous_mesh_draw ;
      CTX.post.draw = previous_post_draw ;
    }

    return 1;

      
  /* -------------------------------------------------------------
      M o t i o n N o t i f y 
     ------------------------------------------------------------- */

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
      draw_overlay();
    }
    else {
      if(ButtonPressed){

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
        Init();
        previous_mesh_draw = CTX.mesh.draw ;
        previous_post_draw = CTX.post.draw ;
        if(CTX.fast) CTX.mesh.draw = CTX.post.draw = 0;
        Draw();
        CTX.mesh.draw = previous_mesh_draw ;
        CTX.post.draw = previous_post_draw ;
      }
      else{
        Process_SelectionBuffer(Fl::event_x(), Fl::event_y(), &hits, ii, jj);
        ov = v; oc = c; os = s; 
        v = NULL; c = NULL; s = NULL;
        Filter_SelectionBuffer(hits,ii,jj,&v,&c,&s,&M);
	draw_overlay_highlight();
      }
      x += movx; 
      y += movy; 
    }

    return 1;

  /* -------------------------------------------------------------
      O t h er
     ------------------------------------------------------------- */

  default: // pass other events to the base class...
    return Fl_Gl_Window::handle(event);

  }

}

