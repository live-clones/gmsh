// $Id: Graph2D.cpp,v 1.3 2001-10-29 14:27:40 geuzaine Exp $

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

void addval(Post_View *v, double min, double max, 
	    int i, int j, int j_inc, 
	    double xtop, double dx, double ybot,
	    int numeric){
  char label[256];
  double d, x, y;

  if(v->GraphType==DRAW_POST_2D_SPACE){
    d = ((double*)List_Pointer_Fast(v->SP,j+3))[v->TimeStep];
    x = xtop+j/j_inc*dx;
  }
  else{
    d = ((double*)List_Pointer_Fast(v->SP,i+3))[j];
    x = xtop+j*dx;
  }
  y = ybot+(d-min)/(max-min)*v->GraphSize[1];

  if(v->SaturateValues){
    if(d > max) d = max;
    else if(d < min) d = min;
  }
  if(d>=min && d<=max){      
    Palette2(v,min,max,d);
    if(numeric){
      glRasterPos2d(x+3,y+3);
      sprintf(label, v->Format, d);
      Draw_String(label);
    }
    else
      glVertex2d(x,y);
  }
}


void Draw_Graph2D(Post_View *v){
  char label[1024] ;
  int font_h = gl_height() ; // hauteur totale de la fonte
  int font_a = gl_height()-gl_descent() ; // hauteur de la fonte au dessus de pt de ref
  int i, i_inc, i_max, j, j_inc, j_max, k, nb;
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

  // The axes + labels
  
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
      sprintf(label, v->Format, (i==v->NbIso)?ValMin:(ValMax-i*dv));
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
      dx = v->GraphSize[0]/(double)(v->NbSP-1);
      nb = v->NbSP;
    }
    else if(v->NbTimeStep>1){
      dx = v->GraphSize[0]/(double)(v->NbTimeStep-1);
      nb = v->NbTimeStep;
    }
    else{
      nb = 0;
    }

    double dist=0., p1[3]={0.,0.,0.}, p2[3];
    j=0;

    for(i=0; i<nb; i++){
      glBegin(GL_LINES);
      glVertex2d(xtop+i*dx,ybot);
      glVertex2d(xtop+i*dx,ybot+TIC);
      glEnd();
      if(v->GraphType==DRAW_POST_2D_SPACE){
	for(k=0;k<3;k++){
	  List_Read(v->SP,j+k,&p2[k]);
	  p1[k] = p2[k]-p1[k];
	}
	dist += sqrt (p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2]);
	sprintf(label, v->Format, dist);
	for(k=0;k<3;k++){
	  p1[k] = p2[k];
	}	    
	j += List_Nbr(v->SP) / v->NbSP;
      }
      else
	sprintf(label, v->Format, *(double*)List_Pointer(v->Time,i));
      glRasterPos2d(xtop+i*dx-gl_width(label)/2.,ybot-1.5*font_h);
      Draw_String(label);
    }
  }

  // The curve(s)

  glPointSize(v->PointSize); 
  gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(v->LineWidth); 
  gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

  if(v->GraphType==DRAW_POST_2D_SPACE){
    i_inc = 1;
    i_max = 1;
    dx = v->GraphSize[0]/(double)(v->NbSP-1);
    j_inc = List_Nbr(v->SP) / v->NbSP ;
    j_max = List_Nbr(v->SP);
  }
  else if(v->NbTimeStep>1){
    i_inc = List_Nbr(v->SP) / v->NbSP ;
    i_max = List_Nbr(v->SP) ;
    dx = v->GraphSize[0]/(double)(v->NbTimeStep-1);
    j_inc = 1;
    j_max = v->TimeStep+1;
  }
  else{
    i_max = 0;
  }
  
  for(i=0; i<i_max; i+=i_inc){
    if(v->IntervalsType == DRAW_POST_ISO || 
       v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_NUMERIC){
      glBegin(GL_POINTS); 
      for(j=0; j<j_max; j+=j_inc) 
	addval(v,ValMin,ValMax,i,j,j_inc,xtop,dx,ybot,0);
      glEnd();
    }
    if(v->IntervalsType == DRAW_POST_NUMERIC){
      for(j=0; j<j_max; j+=j_inc){
	addval(v,ValMin,ValMax,i,j,j_inc,xtop,dx,ybot,1);
      }
    }
    if(v->IntervalsType == DRAW_POST_DISCRETE || 
       v->IntervalsType == DRAW_POST_CONTINUOUS){
      glBegin(GL_LINE_STRIP); 
      for(j=0; j<j_max; j+=j_inc)
	addval(v,ValMin,ValMax,i,j,j_inc,xtop,dx,ybot,0);
      glEnd();
    }
  
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

