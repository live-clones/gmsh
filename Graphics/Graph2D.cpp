// $Id: Graph2D.cpp,v 1.1 2001-10-29 08:52:19 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "gl2ps.h"

extern Context_T   CTX;

#define TIC 3

void Draw_Graph2D(Post_View *v){
  int font_h = gl_height() ; // hauteur totale de la fonte
  int font_a = gl_height()-gl_descent() ; // hauteur de la fonte au dessus de pt de ref
  char label[1024] ;
  int i;
  double dx, dy, dv;
  double xtop = v->GraphPosition[0];
  double ytop = CTX.viewport[3]-v->GraphPosition[1];
  double ybot = ytop-v->GraphSize[1];
  double ValMin, ValMax;

  switch(v->RangeType){
  case DRAW_POST_DEFAULT : ValMin = v->Min ; ValMax = v->Max ; break;
  case DRAW_POST_CUSTOM  : ValMin = v->CustomMin ; ValMax = v->CustomMax ; break;
  }

  if(!v->TransparentScale){
    glColor4ubv((GLubyte*)&CTX.color.bg);
    glBegin(GL_QUADS);
    glVertex2d(xtop,ytop);
    glVertex2d(xtop+v->GraphSize[0],ytop);
    glVertex2d(xtop+v->GraphSize[0],ybot);
    glVertex2d(xtop,ybot);
    glEnd();    
  }
  
  if(v->ShowScale){
    glPointSize(CTX.geom.point_size); 
    gl2psPointSize(CTX.geom.point_size * CTX.print.eps_point_size_factor);

    glLineWidth(CTX.geom.line_width); 
    gl2psLineWidth(CTX.geom.line_width * CTX.print.eps_line_width_factor);

    // 2 axes
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_LINE_STRIP);
    glVertex2d(xtop,ytop);
    glVertex2d(xtop,ytop-v->GraphSize[1]);
    glVertex2d(xtop+v->GraphSize[0],ybot);
    glEnd();

    // y tics + labels
    dy = v->GraphSize[1]/(double)v->NbIso;
    dv = (ValMax-ValMin)/(double)v->NbIso;
    for(i=0; i<v->NbIso+1; i++){
      glBegin(GL_LINES);
      glVertex2d(xtop,ytop-i*dy);
      glVertex2d(xtop+TIC,ytop-i*dy);
      glEnd();
      sprintf(label, v->Format, ValMax-i*dv);
      glRasterPos2d(xtop-gl_width(label)-TIC,ytop-i*dy-font_a/3.);
      Draw_String(label);
    }

    if(v->GraphType==DRAW_POST_2D_SPACE && List_Nbr(v->Time)>1 && v->ShowTime)
      sprintf(label, "%s (%g)", v->Name, *(double*)List_Pointer(v->Time,v->TimeStep));
    else
      sprintf(label, "%s", v->Name);
    glRasterPos2d(xtop-gl_width(label)/2.,ytop+1.5*font_h);
    Draw_String(label);

    // x tics + labels
    if(v->GraphType==DRAW_POST_2D_SPACE){
      dx = v->GraphSize[0]/(double)v->NbIso;
      for(i=0; i<v->NbIso+1; i++){
	glBegin(GL_LINES);
	glVertex2d(xtop+i*dx,ybot);
	glVertex2d(xtop+i*dx,ybot+TIC);
	glEnd();
	sprintf(label, v->Format, 1.);
	glRasterPos2d(xtop+i*dx-gl_width(label)/2.,ybot-1.5*font_h);
	Draw_String(label);
      }
    }
    else{
      dx = v->GraphSize[0]/(double)v->NbTimeStep;
      for(i=0; i<v->NbTimeStep; i++){
	glBegin(GL_LINES);
	glVertex2d(xtop+i*dx,ybot);
	glVertex2d(xtop+i*dx,ybot+TIC);
	glEnd();
	sprintf(label, v->Format, *(double*)List_Pointer(v->Time,i));
	glRasterPos2d(xtop+i*dx-gl_width(label)/2.,ybot-1.5*font_h);
	Draw_String(label);
      }
    }
  }


  glPointSize(v->PointSize); 
  gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(v->LineWidth); 
  gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

  // curve
  if(v->GraphType==DRAW_POST_2D_SPACE){
    int nb = List_Nbr(v->SP) / v->NbSP ;
    if(v->IntervalsType == DRAW_POST_ISO)
      glBegin(GL_POINTS);
    else
      glBegin(GL_LINE_STRIP);
    for(i=0; i<v->NbIso+1; i++){
      double *V = (double*)List_Pointer_Fast(v->SP,i*nb+3);
      double d = V[v->TimeStep];
      if(v->SaturateValues){
	if(d > ValMax) d = ValMax;
	else if(d < ValMin) d = ValMin;
      }
      if(d>=ValMin && d<=ValMax){      
	Palette2(v,ValMin,ValMax,d);
	glVertex2d(xtop+i*dx,ybot+(d-ValMin)/(ValMax-ValMin)*v->GraphSize[1]);
	if(v->IntervalsType == DRAW_POST_NUMERIC){
	  glRasterPos2d(xtop+i*dx+2,ybot+(d-ValMin)/(ValMax-ValMin)*v->GraphSize[1]+2);
	  sprintf(label, v->Format, d);
	  Draw_String(label);
	}
      }
    }
    glEnd();
  }
  else{
    
    
  }
  
}



void Draw_Graph2D(void){
  int i;
  Post_View *v;

  if(!CTX.post.list) return;

  for(i=0;i<List_Nbr(CTX.post.list);i++){
    v = (Post_View*)List_Pointer(CTX.post.list,i);
    if(v->Visible && v->NbSP && v->GraphType!=DRAW_POST_3D) Draw_Graph2D(v);
  }

}

