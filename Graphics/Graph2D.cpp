// $Id: Graph2D.cpp,v 1.6 2001-10-30 08:18:50 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "gl2ps.h"

extern Context_T   CTX;

#define TIC 5

static void addval(Post_View *v, double min, double max, 
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

  if(v->SaturateValues){
    if(d > max) d = max;
    else if(d < min) d = min;
  }
  y = ybot+(d-min)/(max-min)*v->GraphSize[1];

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


static void Draw_Graph2D(Post_View *v){
  char label[1024] ;
  int font_h, font_a ;
  int i, i_inc, i_max, j, j_inc, j_max, k, nb;
  double dx, dy, dv;
  double xtop = v->GraphPosition[0];
  double ytop = CTX.viewport[3]-v->GraphPosition[1];
  double ybot = ytop-v->GraphSize[1];
  double ValMin, ValMax;

  gl_font(FL_HELVETICA,CTX.gl_fontsize);
  font_h = gl_height() ; // hauteur totale de la fonte
  font_a = gl_height()-gl_descent() ; // hauteur de la fonte au dessus de pt de ref

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
    glPointSize(CTX.point_size); 
    gl2psPointSize(CTX.point_size * CTX.print.eps_point_size_factor);

    glLineWidth(CTX.line_width); 
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);

    // 2 axes
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_LINE_STRIP);
    glVertex2d(xtop,ytop);
    glVertex2d(xtop,ytop-v->GraphSize[1]);
    glVertex2d(xtop+v->GraphSize[0],ybot);
    glEnd();

    // y tics + labels
    if(v->NbIso * font_h > v->GraphSize[1])
      nb = 1;
    else
      nb = v->NbIso;
    dy = v->GraphSize[1]/(double)nb;
    dv = (ValMax-ValMin)/(double)nb;
    for(i=0; i<nb+1; i++){
      glBegin(GL_LINES);
      glVertex2d(xtop,ytop-i*dy);
      glVertex2d(xtop+TIC,ytop-i*dy);
      glEnd();
      sprintf(label, v->Format, (i==nb)?ValMin:(ValMax-i*dv));
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
    if(v->GraphType==DRAW_POST_2D_SPACE)
      nb = v->NbSP;
    else
      nb = v->NbTimeStep;
    if(nb == 1) nb=0;
    sprintf(label, v->Format, 9.999);
    if(nb*gl_width(label) > v->GraphSize[0])
      nb = 2;
    dx = v->GraphSize[0]/(double)(nb-1);
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
	  if(i) p1[k] = p2[k]-p1[k];
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
    nb = v->NbSP;
    j_inc = List_Nbr(v->SP) / v->NbSP ;
    j_max = List_Nbr(v->SP);
  }
  else{
    i_inc = List_Nbr(v->SP) / v->NbSP ;
    i_max = List_Nbr(v->SP) ;
    nb = v->NbTimeStep;
    j_inc = 1;
    j_max = v->TimeStep+1;
  }

  if(nb==1) nb=0;
  dx = v->GraphSize[0]/(double)(nb-1);

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

