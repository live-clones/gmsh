/* $Id: Scale.cpp,v 1.10 2000-12-20 10:40:52 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Const.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "gl2ps.h"

extern Context_T   CTX;

#ifdef _UNIX
#include "XContext.h"
extern XContext_T  XCTX;
#define FONTHEIGHT  XCTX.xfont.helve_h
#define FONTASCENT  XCTX.xfont.helve_a
#else
#define FONTHEIGHT  21
#define FONTASCENT  21
#endif

/* Even if all computations in these routines are made in window
   coordinates, double precision is used to work at subpixel accuracy */

extern List_T   *Post_ViewList;

/* ------------------------------------------------------------------------ */
/*  D r a w _ S t r i n g                                                   */
/* ------------------------------------------------------------------------ */

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


#ifdef _UNIX
static int          dir,ascent, descent;
static XCharStruct  overall;
#define CHECK_W                                                                         \
  XTextExtents(XCTX.xfont.helve, label, strlen(label), &dir,&ascent,&descent,&overall); \
  if(overall.width > cv_w) cv_w=overall.width
#else
#define CHECK_W  cv_w=200
#endif


/* ------------------------------------------------------------------------ */
/*  D r a w _ S c a l e                                                     */
/* ------------------------------------------------------------------------ */

extern double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso, int Iso);
extern double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso, int Iso);
extern int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso, double Val);
extern int GiveIndexFromValue_Log(double ValMin, double ValMax, int NbIso, double Val);

void draw_scale(Post_View *v, double xmin, double ymin, double *width, double height){
  int       i, nbv;
  double    font_h, font_a, label_h;
  double    cs_xmin, cs_ymin, cs_h, cs_w, cs_bh;
  double    cv_xmin, cv_ymin, cv_h, cv_w, cv_bh;
  char      label[128] ;
  double    Val, ValMin, ValMax;

  font_h  = FONTHEIGHT ;              /* hauteur totale de la fonte */
  font_a  = FONTASCENT ;              /* hauteur de la fonte au dessus de pt de ref */
  label_h = 1.8*font_h ;              /* hauteur du label */

  cs_xmin = xmin ;                    /* colorscale xmin */
  cs_ymin = ymin+label_h ;            /* colorscale ymin */
  cs_w    = 16. ;                     /* colorscale width */
  cs_h    = height-label_h ;          /* colorscale height */
  cs_bh   = cs_h/v->NbIso ;           /* colorscale box height */

  cv_xmin = cs_xmin+cs_w+5 ;          /* valuescale xmin */
  cv_ymin = cs_ymin ;                 /* valuescale ymin */
  cv_w    = 0.0 ;                     /* valuescale width: to be computed */
  cv_h    = cs_h ;                    /* valuescale height */
  cv_bh   = 0.0 ;                     /* valuescale box height: to be computed */


  switch(v->IntervalsType){
  case DRAW_POST_CONTINUOUS : 
    glShadeModel(GL_SMOOTH); break;
  case DRAW_POST_ISO : 
  case DRAW_POST_DISCRETE : 
    glShadeModel(GL_FLAT); break;
  }
  
  switch(v->RangeType){
  case DRAW_POST_DEFAULT : ValMin = v->Min ; ValMax = v->Max ; break;
  case DRAW_POST_CUSTOM  : ValMin = v->CustomMin ; ValMax = v->CustomMax ; break;
  }
  
  switch(v->ScaleType){
  case DRAW_POST_LINEAR : 
    v->GIFV = GiveIndexFromValue_Lin ;
    v->GVFI = GiveValueFromIndex_Lin ;
    break;
  case DRAW_POST_LOGARITHMIC : 
    v->GIFV = GiveIndexFromValue_Log ;
    v->GVFI = GiveValueFromIndex_Log ;
    break;
  }

  /* background : bidouille
     il faudra changer l'ordre des operations
   */

  if(!v->TransparentScale){
    sprintf(label, v->Format, (ValMin+ValMax)/Pi);
    CHECK_W;
    *width = cv_xmin-cs_xmin+cv_w;   
    glColor4ubv((GLubyte*)&CTX.color.bg);
    glBegin(GL_QUADS);
    glVertex2d(xmin,        ymin);
    glVertex2d(xmin+*width, ymin);
    glVertex2d(xmin+*width, ymin+height);
    glVertex2d(xmin,        ymin+height);
    glEnd();    
  }

  /* colorscale */

  for(i=0;i<v->NbIso;i++){
    if(v->IntervalsType==DRAW_POST_DISCRETE){
      Palette(v,v->NbIso,i);   
      glBegin(GL_QUADS);
      glVertex2d(cs_xmin,      cs_ymin+i*cs_bh);
      glVertex2d(cs_xmin+cs_w, cs_ymin+i*cs_bh);
      glVertex2d(cs_xmin+cs_w, cs_ymin+(i+1)*cs_bh);
      glVertex2d(cs_xmin,      cs_ymin+(i+1)*cs_bh);
      glEnd();
    }
    else if (v->IntervalsType==DRAW_POST_CONTINUOUS){
      glBegin(GL_QUADS);
      Palette2(v,ValMin,ValMax,ValMin+i*(ValMax-ValMin)/v->NbIso);
      glVertex2d(cs_xmin,      cs_ymin+i*cs_bh);
      glVertex2d(cs_xmin+cs_w, cs_ymin+i*cs_bh);
      Palette2(v,ValMin,ValMax,ValMin+(i+1)*(ValMax-ValMin)/v->NbIso);
      glVertex2d(cs_xmin+cs_w, cs_ymin+(i+1)*cs_bh);
      glVertex2d(cs_xmin,      cs_ymin+(i+1)*cs_bh);
      glEnd();  
    }
    else{
      Palette(v,v->NbIso,i);
      glBegin(GL_LINES);
      glVertex2d(cs_xmin,      cs_ymin+i*cs_bh+0.5*cs_bh);
      glVertex2d(cs_xmin+cs_w, cs_ymin+i*cs_bh+0.5*cs_bh);
      glEnd();
    }
  }  
  
  /* valuescale */
  
  nbv = (v->NbIso<floor(cs_h/font_h))?v->NbIso:-1;
  cv_bh = cv_h/nbv;

  glColor4ubv((GLubyte*)&CTX.color.text);

  /* only min and max if not enough room */
  if(nbv<0){
    if(v->IntervalsType!=DRAW_POST_ISO){
      sprintf(label, v->Format, ValMin);
      glRasterPos2d(cv_xmin,cv_ymin-font_a/3.);
      Draw_String(label); CHECK_W;

      sprintf(label, v->Format, ValMax);
      glRasterPos2d(cv_xmin,cv_ymin+cv_h-font_a/3.);
      Draw_String(label); CHECK_W;
    }
    else {
      sprintf(label, v->Format, ValMin);
      glRasterPos2d(cv_xmin,cv_ymin+(cs_bh/2)-font_a/3.);
      Draw_String(label); CHECK_W;

      sprintf(label, v->Format, ValMax);
      glRasterPos2d(cv_xmin,cv_ymin+cv_h-(cs_bh/2)-font_a/3.);
      Draw_String(label); CHECK_W;
    }
  }

  /* all the values if enough space */
  else {
    if(v->IntervalsType!=DRAW_POST_ISO){
      for(i=0 ; i<nbv+1 ; i++){
        Val = v->GVFI(ValMin,ValMax,nbv+1,i); 
        sprintf(label, v->Format, Val);
        glRasterPos2d(cv_xmin,cv_ymin+i*cv_bh-font_a/3.);
        Draw_String(label); CHECK_W;
      }
    }
    else {
      for(i=0 ; i<nbv ; i++){
        Val = v->GVFI(ValMin,ValMax,nbv,i); 
        sprintf(label, v->Format, Val);
        glRasterPos2d(cv_xmin,cv_ymin+(2*i+1)*(cv_bh/2)-font_a/3.);
        Draw_String(label); CHECK_W;
      }
    }
  }

  /* the label */
  
  glRasterPos2d(cv_xmin,ymin);
  if(List_Nbr(v->Time)>1 && v->ShowTime)
    sprintf(label, "%s (%g)", v->Name, *(double*)List_Pointer(v->Time,v->TimeStep));
  else
    sprintf(label, "%s", v->Name);
  Draw_String(label); CHECK_W;


  /* compute the width */
  *width = cv_xmin-cs_xmin+cv_w;

}

static List_T  *todraw=NULL;

void Draw_Scales(void){
  int         i;
  double      xmin, ymin, width, height, xsep, ysep;
  double      oldwidth, totalwidth;
  Post_View  *v;

  if(!Post_ViewList) return;

  /* scales to draw ? */
  
  if(!todraw)
    todraw = List_Create(5,5,sizeof(Post_View*));
  else
    List_Reset(todraw);

  for(i=0;i<List_Nbr(Post_ViewList);i++){
    v = (Post_View*)List_Pointer(Post_ViewList,i);
    if(v->Visible && v->ShowScale) List_Add(todraw,&v);
  }
  
  if(!List_Nbr(todraw)){
    return;
  }

  if(List_Nbr(todraw)==1){
    xsep = 20. ;
    ysep = (CTX.viewport[3]-CTX.viewport[1])/6. ;
    xmin = CTX.viewport[0] + xsep ;    
    ymin = CTX.viewport[1] + ysep ;
    width = 0.0;
    height = CTX.viewport[3]-CTX.viewport[1] - 2*ysep ;

    v = *((Post_View**)List_Pointer(todraw,0));
    draw_scale(v,xmin,ymin,&width,height);
  }
  else{
    xsep = 20. ;
    ysep = (CTX.viewport[3]-CTX.viewport[1])/15. ;    
    xmin = CTX.viewport[0] + xsep ;
    ymin = CTX.viewport[1] + ysep ;
    width = 0.0;
    totalwidth = 0.0;
    height = (CTX.viewport[3]-CTX.viewport[1]-3*ysep)/2. ;

    for(i=0;i<List_Nbr(todraw);i++){
      v = *(Post_View**)List_Pointer(todraw,i);
      oldwidth = width;
      draw_scale(v,
                 xmin+totalwidth+(i/2)*xsep,
                 ymin+(1-i%2)*(height+ysep),
                 &width,
                 height);      
      if(i%2) totalwidth += DMAX(width,oldwidth);
    }
  }

}

