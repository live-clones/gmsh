// $Id: Opengl.cpp,v 1.15 2001-02-03 13:10:26 geuzaine Exp $

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
/*  Draw                                                               */
/* ------------------------------------------------------------------------ */

void InitOpengl(void){
  WID->make_opengl_current();
  Orthogonalize(0,0);
}

void InitOverlay(void){
  WID->make_overlay_current();
  Orthogonalize(0,0);
}

void Draw(void){
  WID->redraw_opengl();
}

void DrawUI(void){
  WID->check();
}

void Draw_String(char *s){

  if(CTX.stream == TO_FILE){
    if(!CTX.print.gl_fonts && CTX.print.eps_quality > 0){
      gl2psText(s,CTX.print.font,CTX.print.font_size);
      return ;
    }
  }

  gl_font(FL_HELVETICA, CTX.gl_fontsize);
  //CTX.gl_fontheight = gl_height() ;
  //CTX.gl_fontascent = gl_height()-gl_descent() ;
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
  int     hits;
  GLuint  ii[SELECTION_BUFFER_SIZE],jj[SELECTION_BUFFER_SIZE];

  *v = NULL; *c = NULL; *s = NULL;
  
  WID->try_selection = 0;
  WID->quit_selection = 0;
  WID->end_selection = 0;
  
  while(1){
    Fl::check();
    if(WID->quit_selection){
      WID->quit_selection = 0;
      return 0;
    }
    if(WID->end_selection){
      WID->end_selection = 0;
      return -1;
    }
    if(WID->try_selection){
      WID->try_selection = 0;
      Process_SelectionBuffer(Fl::event_x(), Fl::event_y(), &hits, ii, jj);
      Filter_SelectionBuffer(hits,ii,jj,v,c,s,&M);
      if(check_type(type,*v,*c,*s)){
        BeginHighlight();
        HighlightEntity(*v,*c,*s,1);
        EndHighlight(1);
        return(1);
      }
    }
  }

}


