// $Id: Opengl.cpp,v 1.9 2001-01-10 21:20:39 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"
#include "gl2ps.h"

extern GUI       *WID;
extern Mesh       M;
extern Context_T  CTX;

void Process_SelectionBuffer(int x, int y, int *n, GLuint *ii, GLuint *jj);
void Filter_SelectionBuffer(int n, GLuint *typ, GLuint *ient, Vertex **thev,
                            Curve **thec, Surface **thes, Mesh *m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);

/* ------------------------------------------------------------------------ */
/*  Init/Draw                                                               */
/* ------------------------------------------------------------------------ */

void Init(void){
}

void InitOverlay(void){
  WID->make_overlay_current();
}

void Draw(void){
  WID->draw();
}

void DrawOverlay(void){
  WID->draw_overlay();
}

void DrawUI(void){
  WID->check();
}

// one should not call Opengl_Window::draw() from the handle(), but
// rather the following:

void DrawUpdate(){
  WID->make_current();
  Orthogonalize(0,0);
  glClearColor(UNPACK_RED(CTX.color.bg)/255.,
               UNPACK_GREEN(CTX.color.bg)/255.,
               UNPACK_BLUE(CTX.color.bg)/255.,
               0.);
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  Draw3d();
  Draw2d();
  WID->swap_buffers();
}

void Draw_String(char *s){

  if(CTX.stream == TO_FILE){
    if(!CTX.print.gl_fonts && CTX.print.eps_quality > 0){
      gl2psText(s,CTX.print.font,CTX.print.font_size);
      return ;
    }
  }

  gl_font(FL_HELVETICA, CTX.glfontsize);
  gl_draw(s);

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
  return 0;
  /*
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
  */
}


