// $Id: Graph2D.cpp,v 1.11 2001-11-14 14:39:39 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "gl2ps.h"

extern Context_T   CTX;

/* ------------------------------------------------------------------------
    2D graphics (gnuplot style)
   ------------------------------------------------------------------------ */

static void getval(Post_View *v, int i, int j, double *p1, double *p2, 
		   double *Abs, double *Val){
  int k;
  if(v->Type==DRAW_POST_2D_SPACE){
    for(k=0;k<3;k++){
      List_Read(v->SP,j+k,&p2[k]);
      if(j) p1[k] = p2[k]-p1[k];
    }
    *Abs += sqrt (p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2]);
    for(k=0;k<3;k++){
      p1[k] = p2[k];
    }
    *Val = ((double*)List_Pointer_Fast(v->SP,j+3))[v->TimeStep];
  }
  else{
    *Abs = *(double*)List_Pointer_Fast(v->Time,j);
    *Val = ((double*)List_Pointer_Fast(v->SP,i+3))[j];
  }
}

static void addval(Post_View *v, double Abs, double Val,
		   double AbsMin, double AbsMax, double ValMin, double ValMax,
		   double xtop, double width, double ybot, double height,
		   int numeric){
  char label[256];
  double x, y;

  if(AbsMax==AbsMin)
    x = xtop;
  else
    x = xtop+(Abs-AbsMin)/(AbsMax-AbsMin)*width;

  if(v->SaturateValues){
    if(Val > ValMax) Val = ValMax;
    else if(Val < ValMin) Val = ValMin;
  }
  
  if(ValMax==ValMin)
    y = ybot;
  else
    y = ybot+(Val-ValMin)/(ValMax-ValMin)*height;

  if(Val>=ValMin && Val<=ValMax){      
    Palette2(v,ValMin,ValMax,Val);
    if(numeric){
      glRasterPos2d(x+3,y+3);
      sprintf(label, v->Format, Val);
      Draw_String(label);
    }
    else
      glVertex2d(x,y);
  }
}


static void Draw_Graph2D(Post_View *v,
			 double xx, double yy, double width, double height,
			 double tic, double bb[4]){
  char label[1024] ;
  int font_h, font_a ;
  int i, i_inc, i_max, j, j_inc, j_max, k, nb;
  double dx, dy, dv;
  double xtop = xx;
  double ytop = CTX.viewport[3]-yy;
  double ybot = ytop-height;
  double Abs, Val, ValMin, ValMax, AbsMin, AbsMax;
  double p1[3], p2[3];

  if(!v->TransparentScale){
    glColor4ubv((GLubyte*)&CTX.color.bg);
    glBegin(GL_QUADS);
    glVertex2d(bb[0],CTX.viewport[3]-bb[1]);
    glVertex2d(bb[2],CTX.viewport[3]-bb[1]);
    glVertex2d(bb[2],CTX.viewport[3]-bb[3]);
    glVertex2d(bb[0],CTX.viewport[3]-bb[3]);
    glEnd();    
  }
  
  gl_font(FL_HELVETICA,CTX.gl_fontsize);
  font_h = gl_height() ; // hauteur totale de la fonte
  font_a = gl_height()-gl_descent() ; // hauteur de la fonte au dessus de pt de ref

  switch(v->RangeType){
  case DRAW_POST_DEFAULT : ValMin = v->Min ; ValMax = v->Max ; break;
  case DRAW_POST_CUSTOM  : ValMin = v->CustomMin ; ValMax = v->CustomMax ; break;
  }

  glPointSize(CTX.point_size); 
  gl2psPointSize(CTX.point_size * CTX.print.eps_point_size_factor);

  glLineWidth(CTX.line_width); 
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
  
  // axes

  if(v->Grid){
    glColor4ubv((GLubyte*)&CTX.color.fg);
    glBegin(GL_LINE_STRIP);
    glVertex2d(xtop,ytop);
    glVertex2d(xtop,ytop-height);
    glVertex2d(xtop+width,ybot);
    if(v->Grid>1){
      glVertex2d(xtop+width,ytop);
      glVertex2d(xtop,ytop);
    }
    glEnd();
  }
  
  // y tics + labels

  nb = v->NbIso;
  if(v->ShowScale && (v->NbIso * font_h > height)) nb = (int)floor(height/font_h);

  dy = height/(double)nb;
  dv = (ValMax-ValMin)/(double)nb;
  for(i=0; i<nb+1; i++){
    if(v->Grid>0){
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINES);
      glVertex2d(xtop,ytop-i*dy);
      glVertex2d(xtop+tic,ytop-i*dy);
      if(v->Grid>1){
	glVertex2d(xtop+width-tic,ytop-i*dy);
	glVertex2d(xtop+width,ytop-i*dy);
      }
      glEnd();
      if(v->Grid>2 && i!=0 && i!=nb){
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1,0x1111);
	gl2psEnable(GL2PS_LINE_STIPPLE);
	glLineWidth(1); 
	gl2psLineWidth(1 * CTX.print.eps_line_width_factor);
	glBegin(GL_LINES);
	glVertex2d(xtop,ytop-i*dy);
	glVertex2d(xtop+width,ytop-i*dy);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	gl2psDisable(GL2PS_LINE_STIPPLE);
	glLineWidth(CTX.line_width); 
	gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
      }
    }
    if(v->ShowScale){
      glColor4ubv((GLubyte*)&CTX.color.text);
      sprintf(label, v->Format, (i==nb)?ValMin:(ValMax-i*dv));
      if(CTX.stream == TO_FILE)
	glRasterPos2d(xtop-gl_width(label)-3*tic,ytop-i*dy-font_a/3.);
      else
	glRasterPos2d(xtop-gl_width(label)-tic,ytop-i*dy-font_a/3.);
      Draw_String(label);
    }
  }
  
  if(v->ShowScale){
    glColor4ubv((GLubyte*)&CTX.color.text);
    if(v->Type==DRAW_POST_2D_SPACE && List_Nbr(v->Time)>1 && v->ShowTime)
      sprintf(label, "%s (%g)", v->Name, *(double*)List_Pointer(v->Time,v->TimeStep));
    else
      sprintf(label, "%s", v->Name);
    glRasterPos2d(xtop-gl_width(label)/2.,ytop+1.5*font_h);
    Draw_String(label);
  }

  // x tics + labels

  if(v->Type==DRAW_POST_2D_SPACE){
    AbsMin = AbsMax = 0.;
    double p1[3]={0.,0.,0.}, p2[3];
    for(i=0; i<List_Nbr(v->SP); i+=List_Nbr(v->SP)/v->NbSP){
      for(k=0;k<3;k++){
	List_Read(v->SP,i+k,&p2[k]);
	if(i) p1[k] = p2[k]-p1[k];
      }
      AbsMax += sqrt (p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2]);
      for(k=0;k<3;k++){
	p1[k] = p2[k];
      }	    
    }
  }
  else{
    AbsMin = *(double*)List_Pointer(v->Time,0);
    AbsMax = *(double*)List_Pointer(v->Time,List_Nbr(v->Time)-1);
  }

  nb = v->NbAbscissa;
  if(v->ShowScale){
    sprintf(label, v->Format, AbsMin);
    double ww = gl_width(label);
    sprintf(label, v->Format, AbsMax);
    if(gl_width(label) > ww) ww = gl_width(label);
    if((nb-1)*(ww+2) > width) nb = (int)floor(width/(ww+2))+1;
  }
  if(nb==1)
    dx = width;
  else
    dx = width/(double)(nb-1);

  for(i=0; i<nb; i++){
    if(v->Grid>0){
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_LINES);
      glVertex2d(xtop+i*dx,ybot);
      glVertex2d(xtop+i*dx,ybot+tic);
      if(v->Grid>1){
	glVertex2d(xtop+i*dx,ytop);
	glVertex2d(xtop+i*dx,ytop-tic);
      }
      glEnd();
      if(v->Grid>2 && i!=0 && i!=nb-1){
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1,0x1111);
	gl2psEnable(GL2PS_LINE_STIPPLE);
	glLineWidth(1); 
	gl2psLineWidth(1 * CTX.print.eps_line_width_factor);
	glBegin(GL_LINES);
	glVertex2d(xtop+i*dx,ytop);
	glVertex2d(xtop+i*dx,ybot);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	gl2psDisable(GL2PS_LINE_STIPPLE);
	glLineWidth(CTX.line_width); 
	gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
      }
    }
    if(v->ShowScale){
      glColor4ubv((GLubyte*)&CTX.color.text);
      if(nb==1)
	sprintf(label, v->Format, AbsMin);
      else
	sprintf(label, v->Format, AbsMin+i*(AbsMax-AbsMin)/(double)(nb-1));
      glRasterPos2d(xtop+i*dx-gl_width(label)/2.,ybot-1.5*font_h);
      Draw_String(label);
    }
  }
  if(v->ShowScale){
    glColor4ubv((GLubyte*)&CTX.color.text);
    sprintf(label, "%s", v->AbscissaName);
    glRasterPos2d(xtop+width/2-gl_width(label)/2.,ybot-3*font_h);
    Draw_String(label);
  }

  // the curve(s)

  glPointSize(v->PointSize); 
  gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(v->LineWidth); 
  gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

  if(v->Type==DRAW_POST_2D_SPACE){
    i_inc = 1;
    i_max = 1;
    j_inc = List_Nbr(v->SP)/v->NbSP ;
    j_max = List_Nbr(v->SP);
  }
  else{
    i_inc = List_Nbr(v->SP)/v->NbSP ;
    i_max = List_Nbr(v->SP) ;
    j_inc = 1;
    j_max = v->TimeStep+1;
  }

  for(i=0; i<i_max; i+=i_inc){
    if(v->IntervalsType == DRAW_POST_ISO || 
       v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_NUMERIC){
      glBegin(GL_POINTS); 
      Abs = Val = p1[0] = p1[1] = p1[2] = 0.;
      for(j=0; j<j_max; j+=j_inc){
	getval(v,i,j,p1,p2,&Abs,&Val);
	addval(v,Abs,Val,AbsMin,AbsMax,ValMin,ValMax,xtop,width,ybot,height,0);
      }
      glEnd();
    }
    if(v->IntervalsType == DRAW_POST_NUMERIC){
      Abs = Val = p1[0] = p1[1] = p1[2] = 0.;
      for(j=0; j<j_max; j+=j_inc){
	getval(v,i,j,p1,p2,&Abs,&Val);
	addval(v,Abs,Val,AbsMin,AbsMax,ValMin,ValMax,xtop,width,ybot,height,1);
      }
    }
    if(v->IntervalsType == DRAW_POST_DISCRETE || 
       v->IntervalsType == DRAW_POST_CONTINUOUS){
      glBegin(GL_LINE_STRIP); 
      Abs = Val = p1[0] = p1[1] = p1[2] = 0.;
      for(j=0; j<j_max; j+=j_inc){
	getval(v,i,j,p1,p2,&Abs,&Val);
	addval(v,Abs,Val,AbsMin,AbsMax,ValMin,ValMax,xtop,width,ybot,height,0);
      }
      glEnd();
    }
  
  }
  
}

void getbb(double pos[2], double width, double height, 
	   double dx, double dy, double tic, double space, 
	   double bbtot[4], double bb[4]){
  bbtot[0] = pos[0]-dx-space;//topleft x
  bb[0] = bbtot[0];

  //don't recompute bbtot[1].
  bb[1] = pos[1]-1.5*dy-space;//topleft y
  
  bbtot[2] = MAX(bbtot[2],pos[0]+width+(dx-tic)/2+space);//bottomright x
  bb[2] = pos[0]+width+(dx-tic)/2+space;

  bbtot[3] = pos[1]+height+2*dy+space;//bottomright y
  bb[3] = bbtot[3];
}

void Draw_Graph2D(void){
  int i,nbauto=0;
  Post_View *v;
  double dx,dy,bb[4],bbtot[4]={0.,0.,0.,0.},pos[2],tic,space=10.;
  char label[1024];

  if(!CTX.post.list) return;

  for(i=0;i<List_Nbr(CTX.post.list);i++){
    v = (Post_View*)List_Pointer(CTX.post.list,i);
    if(v->Visible && v->NbSP && v->Type!=DRAW_POST_3D){
      tic = 5;
      dx = dy = 0.;
      if(v->ShowScale){
	gl_font(FL_HELVETICA,CTX.gl_fontsize);
	sprintf(label,v->Format,v->CustomMin);
	if(gl_width(label)+tic > dx) dx = gl_width(label)+tic;
	sprintf(label,v->Format,v->CustomMax);
	if(gl_width(label)+tic > dx) dx = gl_width(label)+tic;
	dy = 1.5*gl_height();//2 en dessous et 1 au dessus !
      }
      if(!v->AutoPosition || !nbauto){
	pos[0] = v->Position[0];
	pos[1] = v->Position[1];
	bbtot[1] = pos[1]-1.5*dy-space;//top y
	getbb(pos,v->Size[0],v->Size[1],dx,dy,tic,space,bbtot,bb);
	Draw_Graph2D(v,pos[0],pos[1],v->Size[0],v->Size[1],tic,bb);
      }
      else{
	if(bbtot[3]+v->Size[1]+3*dy+2*space < CTX.viewport[3]){//try to put below
	  pos[1] = bbtot[3]+1.5*dy+space;
	  getbb(pos,v->Size[0],v->Size[1],dx,dy,tic,space,bbtot,bb);
	  Draw_Graph2D(v,pos[0],pos[1],v->Size[0],v->Size[1],tic,bb);
	}
	else{ //start a new column
	  pos[0]=bbtot[2]+dx+space;
	  pos[1]=bbtot[1]+1.5*dy+space;
	  getbb(pos,v->Size[0],v->Size[1],dx,dy,tic,space,bbtot,bb);
	  Draw_Graph2D(v,pos[0],pos[1],v->Size[0],v->Size[1],tic,bb);
	}
      }
      nbauto++;
    }
  }
}


/* ------------------------------------------------------------------------
    2D text strings
   ------------------------------------------------------------------------ */

// T2(x,y,style){"str","str",...};
// T2D : x,y,style,index,x,y,style,index,...
// T2C : string\0,string\0,string\0,string\0,...

// T3(x,y,z,style){"str","str",...};
// T3D : x,y,z,style,index,x,y,z,style,index,...
// T3C : string\0,string\0,string\0,string\0,...

void Draw_Text2D3D(int dim, int timestep, int nb, List_T *td, List_T *tc){
  int j,k,l,nbd,index,stop;
  char *c;
  double *d1, *d2, style, x, y, z;

  if(dim==2) nbd=4;
  else if(dim==3) nbd=5;
  else return;

  for(j=0; j<nb; j++){
    d1 = (double*)List_Pointer(td, j*nbd);
    d2 = (double*)List_Pointer_Test(td, (j+1)*nbd);
    if(dim==2){
      x = d1[0];
      if(x<0) x = CTX.viewport[2] + x;
      y = CTX.viewport[3]-d1[1];
      if(d1[1]<0) y = -d1[1];
      z = 0.;
      style = d1[2];
      index = (int)d1[3];
      if(d2) stop=(int)d2[3];
      else stop=List_Nbr(tc)-index;
    }
    else{
      x = d1[0];
      y = d1[1];
      z = d1[2];
      style = d1[3];
      index = (int)d1[4];
      if(d2) stop=(int)d2[4];
      else stop=List_Nbr(tc)-index;
    }
    glRasterPos3d(x,y,z);
    c = (char*)List_Pointer(tc, index);
    k=l=0;
    while(k<stop && l!=timestep){
      if(c[k++]=='\0') l++;
    }
    if(k<stop && l==timestep)
      Draw_String(&c[k]);
    else
      Draw_String(c);
  }
}


void Draw_Text2D(void){
  int i;
  Post_View *v;

  if(!CTX.post.list) return;

  glColor4ubv((GLubyte*)&CTX.color.text);

  for(i=0;i<List_Nbr(CTX.post.list);i++){
    v = (Post_View*)List_Pointer(CTX.post.list,i);
    if(v->Visible && v->DrawStrings) 
      Draw_Text2D3D(2, v->TimeStep, v->NbT2, v->T2D, v->T2C);
  }

}

