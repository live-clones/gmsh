/* $Id: Geom.cpp,v 1.4 2000-11-25 15:26:10 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Verif.h"
#include "Interpolation.h"
#include "Numeric.h"

extern Context_T  CTX;

extern Mesh      *THEM;
extern double     LC;

/* ------------------------------------------------------------------------ */
/*  D r a w _ P o i n t                                                     */
/* ------------------------------------------------------------------------ */

static int   Highlighted = 0; 

void Draw_Point (void *a, void *b){
  Vertex **v;
  char Num[100];

  v = (Vertex**)a;

  if(CTX.render_mode == GMSH_SELECT){
    glLoadName(0);
    glPushName((*v)->Num);
  }

  if((*v)->Frozen){
    glPointSize(5);
    glColor4ubv((GLubyte*)&CTX.color.geom.point_sel);
  }
  else if(Highlighted){
    glPointSize(5);
    glColor4ubv((GLubyte*)&CTX.color.geom.point_hlt);
  }
  else{
    glPointSize(3);
    glColor4ubv((GLubyte*)&CTX.color.geom.point);
  }

  if(CTX.geom.points){
    glBegin(GL_POINTS);
    glVertex3d((*v)->Pos.X, (*v)->Pos.Y, (*v)->Pos.Z);
    glEnd();
  }

  if(CTX.geom.points_num){
    sprintf(Num,"%d",(*v)->Num);
    glRasterPos3d((*v)->Pos.X+3*CTX.pixel_equiv_x/CTX.s[0],
		  (*v)->Pos.Y+3*CTX.pixel_equiv_x/CTX.s[1], 
		  (*v)->Pos.Z+3*CTX.pixel_equiv_x/CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.render_mode == GMSH_SELECT){
    glPopName();
  }

}

/* ------------------------------------------------------------------------ */
/*  D r a w _ C u r v e                                                     */
/* ------------------------------------------------------------------------ */


void Draw_Curve (void *a, void *b){
  int     i,N;
  double  mod,dd;
  char    Num[100];
  Curve  *c;
  Vertex  v,dv;

  c = *(Curve**)a;

  if(c->Num<0 || !EntiteEstElleVisible(c->Num)) return;

  if(CTX.render_mode == GMSH_SELECT){
    glLoadName(1);
    glPushName(c->Num);
  }

  if((c)->ipar[3]){
    glLineWidth(2.);
    glColor4ubv((GLubyte*)&CTX.color.geom.line_sel);
  }
  else if(Highlighted){
    glLineWidth(2.);
    glColor4ubv((GLubyte*)&CTX.color.geom.line_hlt);
  }
  else{
    glLineWidth(1.);
    glColor4ubv((GLubyte*)&CTX.color.geom.line);
  }

  if(CTX.geom.lines){
  
    if(c->Typ == MSH_SEGM_LINE)
      N = List_Nbr(c->Control_Points);
    else
      N = 50;

    glBegin(GL_LINE_STRIP);
    for(i=0;i<N;i++){
      v = InterpolateCurve(c,(double)i/(double)(N-1),0);
      glVertex3d(v.Pos.X,v.Pos.Y,v.Pos.Z);
    }
    glEnd();

  }

  if(CTX.geom.lines_num){
    v = InterpolateCurve(c,0.5,0);
    sprintf(Num,"%d",c->Num);
    glRasterPos3d(v.Pos.X+3*CTX.pixel_equiv_x/CTX.s[0],
		  v.Pos.Y+3*CTX.pixel_equiv_x/CTX.s[1], 
		  v.Pos.Z+3*CTX.pixel_equiv_x/CTX.s[2]);
    Draw_String(Num);
  }
  
  if(CTX.geom.tangents){
    v  = InterpolateCurve(c,0.5,0);
    dv = InterpolateCurve(c,0.5,1);
    mod = sqrt(dv.Pos.X*dv.Pos.X+dv.Pos.Y*dv.Pos.Y+dv.Pos.Z*dv.Pos.Z);
    dv.Pos.X = dv.Pos.X / mod * CTX.geom.tangents * CTX.pixel_equiv_x/CTX.s[0] ;
    dv.Pos.Y = dv.Pos.Y / mod * CTX.geom.tangents * CTX.pixel_equiv_x/CTX.s[1] ;
    dv.Pos.Z = dv.Pos.Z / mod * CTX.geom.tangents * CTX.pixel_equiv_x/CTX.s[2] ;
    dd = sqrt(dv.Pos.X*dv.Pos.X+dv.Pos.Y*dv.Pos.Y+dv.Pos.Z*dv.Pos.Z);
    glColor4ubv((GLubyte*)&CTX.color.geom.tangents);
    Draw_Vector(DRAW_POST_ARROW, 0, v.Pos.X,v.Pos.Y,v.Pos.Z,
		dd, dv.Pos.X,dv.Pos.Y,dv.Pos.Z, NULL,NULL);
  }

  if(CTX.render_mode == GMSH_SELECT){
    glPopName ();
  }

}



/* ------------------------------------------------------------------------ */
/*  D r a w _ S u r f a c e                                                 */
/* ------------------------------------------------------------------------ */

void put_Z (Vertex *v, Surface *s){
  Vertex V;
  V.Pos.X = s->a;
  V.Pos.Y = s->b;
  V.Pos.Z = s->c; 
  Projette(&V,s->plan);
  if(V.Pos.Z != 0.0)
    v->Pos.Z = (s->d - V.Pos.X * v->Pos.X - V.Pos.Y * v->Pos.Y)/V.Pos.Z;
  else v->Pos.Z = 0.0;

  Projette(v,s->invplan);
}

int isPointOnPlanarSurface (Surface *S, double X, double Y, double Z, double n[3]){
  Curve *C;
  Vertex V,P1,P2;
  int i,j,N;
  double Angle,u1,u2;

  Angle = 0.0;
  V.Pos.X = X;
  V.Pos.Y = Y;
  V.Pos.Z = Z;

  for(i=0;i<List_Nbr(S->s.Generatrices);i++){
    List_Read(S->s.Generatrices,i,&C);

    switch(C->Typ){
    case MSH_SEGM_LINE:
      N = 1;
      break;
    default:
      N = 10;
      break;
    }
    for(j=0;j<N;j++){
      u1 = (double)j/(double)(N);
      u2 = (double)(j+1)/(double)(N);
      P1 = InterpolateCurve(C,u1,0);
      P2 = InterpolateCurve(C,u2,0);
      Angle += angle_plan(&V,&P1,&P2,n);
    }
  }

  if(fabs(Angle) > 6.0 && fabs(Angle) < 7.)return 1;
  return 0;

}

void Plan_SurfPlane (void *data,void *dum){
  Surface **pS , *s;
  Curve    *pC;
  Vertex   *v;
  int       ix,iy,iz,i,j,N;
  double    det,sys[3][3],b[3],res[3],mod,t1[3],t2[3],ex[3],s2s[2][2],r2[2],X,Y,Z;

  static List_T *points;
  static int deb=1;

  pS = (Surface**)data;
  s = *pS;

  if(deb){
    points = List_Create(10,10,sizeof(Vertex*));
    deb = 0;
  }

  if(s->Typ == MSH_SURF_PLAN){
    for(i=0;i<List_Nbr(s->s.Generatrices);i++){
      List_Read(s->s.Generatrices,i,&pC);
      for(j=0;j<List_Nbr(pC->Control_Points);j++){
	     List_Add(points,List_Pointer(pC->Control_Points,j));
      }
    }
  }
  else{
    return;
  }
  
  N = List_Nbr(points);

  for(i=0;i<3;i++){
    b[i] = 0.0;
    for(j=0;j<3;j++){
      sys[i][j] = 0.0;
    }
  }

  /* ax + by + cz = 1 */

  ix=iy=iz=0;

  for(i=0;i<N;i++){
    List_Read(points,i,&v);
    if(!i){
      X = v->Pos.X;
      Y = v->Pos.Y;
      Z = v->Pos.Z;
    }
    else{
      if(X != v->Pos.X ) ix = 1;
      if(Y != v->Pos.Y ) iy = 1;
      if(Z != v->Pos.Z ) iz = 1;
    }

    sys[0][0] += v->Pos.X * v->Pos.X;
    sys[1][1] += v->Pos.Y * v->Pos.Y;
    sys[2][2] += v->Pos.Z * v->Pos.Z;
    sys[0][1] += v->Pos.X * v->Pos.Y;
    sys[0][2] += v->Pos.X * v->Pos.Z;
    sys[1][2] += v->Pos.Y * v->Pos.Z;
    sys[2][1] = sys[1][2];
    sys[1][0] = sys[0][1];
    sys[2][0] = sys[0][2];
    b[0]      += v->Pos.X;
    b[1]      += v->Pos.Y;
    b[2]      += v->Pos.Z;
  }
 
  s->d = 1.0;

  /* x = X */

  if(!ix){
    s->d = X;
    res[0] = 1.;
    res[1] = res[2] = 0.0;

  }

  /* y = Y */

  else if(!iy){
    s->d = Y;
    res[1] = 1.;
    res[0] = res[2] = 0.0;
  }

  /* z = Z */

  else if(!iz){
    s->d = Z;
    res[2] = 1.;
    res[1] = res[0] = 0.0;
  }
  
  /* by + cz = -x */

  else if (!sys3x3(sys,b,res,&det) ){
    s->d = 0.0;
    s2s[0][0] = sys[1][1];
    s2s[0][1] = sys[1][2];
    s2s[1][0] = sys[1][2];
    s2s[1][1] = sys[2][2];
    b[0]      = -sys[0][1];
    b[1]      = -sys[0][2];
    if(sys2x2(s2s,b,r2)){
      res[0] = 1.;
      res[1] = r2[0];
      res[2] = r2[1];
    }    
    /* ax + cz = -y */    
    else {
      s->d = 0.0;
      s2s[0][0] = sys[0][0];
      s2s[0][1] = sys[0][2];
      s2s[1][0] = sys[0][2];
      s2s[1][1] = sys[2][2];
      b[0]      = -sys[0][1];
      b[1]      = -sys[1][2];
      if(sys2x2(s2s,b,r2)){
	res[0] = r2[0];
	res[1] = 1.;
	res[2] = r2[1];
      }      
      /* ax + by = -z */
      else {
	s->d = 1.0;
	s2s[0][0] = sys[0][0];
	s2s[0][1] = sys[0][1];
	s2s[1][0] = sys[0][1];
	s2s[1][1] = sys[1][1];
	b[0]      = -sys[0][2];
	b[1]      = -sys[1][2];
	if(sys2x2(s2s,b,r2)){
	  res[0] = r2[0];
	  res[1] = r2[1];
	  res[2] = 1.;
	}
	else {
	  Msg(ERROR, "Draw Geometry (Plan_SurfPlane)");
	}
      }
    }
  }
  
  s->a = res[0];
  s->b = res[1];
  s->c = res[2];
  mod = sqrt (res[0] * res[0] + res[1] * res[1] + res[2] * res[2]);
  for(i=0;i<3;i++) res[i]/=mod;
  
  /* L'axe n'est pas l'axe des x */
  if(res[0] > res[1]){
    ex[0] = 0.;
    ex[1] = 1.;
    ex[2] = 0.;
  }
  else{
    ex[0] = 1.;
    ex[1] = 0.;
    ex[2] = 0.;
  }
  
  prodve(res,ex,t1);
  
  mod = sqrt (t1[0] * t1[0] + t1[1] * t1[1] + t1[2] * t1[2] ) ;
  for(i=0;i<3;i++) t1[i]/=mod;

  prodve(t1,res,t2);

  mod = sqrt (t2[0] * t2[0] + t2[1] * t2[1] + t2[2] * t2[2] ) ;
  for(i=0;i<3;i++) t2[i]/=mod;

  for(i=0;i<3;i++)s->plan[0][i] = t1[i];
  for(i=0;i<3;i++)s->plan[1][i] = t2[i];
  for(i=0;i<3;i++)s->plan[2][i] = res[i];

  /* Matrice orthogonale */

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      s->invplan[i][j] = s->plan[j][i];
    }
  }
  List_Reset(points);
} 


void Draw_Plane_Surface (Surface *s){
  int i,k;
  Curve *c;
  double minx,miny,maxx,maxy,t,n[3],nn;
  Vertex P1,P2,P3,V[4],vv,vv1,vv2;
  char Num[100];

  if(!s->Orientations){
    s->Orientations = List_Create(20,2,sizeof(Vertex));
    Plan_SurfPlane(&s,NULL); 
    k = 0;
    
    for(i=0;i<List_Nbr(s->s.Generatrices);i++){
      List_Read (s->s.Generatrices,i,&c);
      P1 = InterpolateCurve(c,0.0,0);
      P2 = InterpolateCurve(c,0.5,0);
      P3 = InterpolateCurve(c,1.0,0);
      Projette(&P1,s->plan);
      Projette(&P2,s->plan);
      Projette(&P3,s->plan);

      if(!k){
	k = 1;
	minx = maxx = P1.Pos.X;
	miny = maxy = P1.Pos.Y;
      }
      minx = DMIN(DMIN(DMIN(minx,P1.Pos.X),P2.Pos.X),P3.Pos.X);      
      miny = DMIN(DMIN(DMIN(miny,P1.Pos.Y),P2.Pos.Y),P3.Pos.Y);      
      maxx = DMAX(DMAX(DMAX(maxx,P1.Pos.X),P2.Pos.X),P3.Pos.X);      
      maxy = DMAX(DMAX(DMAX(maxy,P1.Pos.Y),P2.Pos.Y),P3.Pos.Y);      
    }

    V[0].Pos.X = minx;
    V[0].Pos.Y = miny;

    V[1].Pos.X = maxx;
    V[1].Pos.Y = miny;
    
    V[2].Pos.X = maxx;
    V[2].Pos.Y = maxy;
    
    V[3].Pos.X = minx;
    V[3].Pos.Y = maxy;
    for(i=0;i<4;i++){
      V[i].Pos.Z = 0.0;
      put_Z(&V[i],s);
    }
    n[0] = s->plan[2][0];
    n[1] = s->plan[2][1];
    n[2] = s->plan[2][2];
    norme(n);

    k = 0;
    for(i=0;i<100;i++){
      t = (double)i/(double)(100);
      vv.Pos.X = t * 0.5 * (V[0].Pos.X + V[1].Pos.X) + (1.-t) * 
	0.5 * (V[2].Pos.X + V[3].Pos.X); 
      vv.Pos.Y = t * 0.5 * (V[0].Pos.Y + V[1].Pos.Y) + (1.-t) * 
	0.5 * (V[2].Pos.Y + V[3].Pos.Y); 
      vv.Pos.Z = t * 0.5 * (V[0].Pos.Z + V[1].Pos.Z) + (1.-t) * 
	0.5 * (V[2].Pos.Z + V[3].Pos.Z); 
      if(isPointOnPlanarSurface(s,vv.Pos.X,vv.Pos.Y,vv.Pos.Z,n)){
	if(!k){
	  List_Add(s->Orientations,&vv);
	  k = 1;
	}
      }
      else{
	if(k){
	  List_Add(s->Orientations,&vv);
	  k = 0;
	}    
      }
    }
    if(k) List_Add(s->Orientations,&vv);
    
    k = 0;
    for(i=0;i<100;i++){

      t = (double)i/(double)(100);
      vv.Pos.X = t*.5*(V[0].Pos.X+V[3].Pos.X)+(1.-t)*.5*(V[2].Pos.X+V[1].Pos.X); 
      vv.Pos.Y = t*.5*(V[0].Pos.Y+V[3].Pos.Y)+(1.-t)*.5*(V[2].Pos.Y+V[1].Pos.Y);
      vv.Pos.Z = t*.5*(V[0].Pos.Z+V[3].Pos.Z)+(1.-t)*.5*(V[2].Pos.Z+V[1].Pos.Z); 
      if(isPointOnPlanarSurface(s,vv.Pos.X,vv.Pos.Y,vv.Pos.Z,n)){
	if(!k){
	  List_Add(s->Orientations,&vv);
	  k = 1;
	}
      }
      else{
	if(k){
	  List_Add(s->Orientations,&vv);
	  k = 0;
	}    
      }
    }
    if(k)List_Add(s->Orientations,&vv);
    Msg(INFO, "Surface %d (%d points)",s->Num,List_Nbr(s->Orientations)); 
  }

  if(CTX.geom.surfaces){
    glBegin(GL_LINES);
    for(i=0;i<List_Nbr(s->Orientations);i++){
      List_Read(s->Orientations,i,&vv);
      glVertex3d(vv.Pos.X,vv.Pos.Y,vv.Pos.Z);
    }
    glEnd();
  }

  glDisable(GL_LINE_STIPPLE);

  if(CTX.geom.surfaces_num){
    List_Read(s->Orientations,0,&vv1);
    List_Read(s->Orientations,1,&vv2);
    sprintf(Num,"%d",s->Num);
    glRasterPos3d((vv2.Pos.X+vv1.Pos.X)/2. + 3*CTX.pixel_equiv_x/CTX.s[0],
		  (vv2.Pos.Y+vv1.Pos.Y)/2. + 3*CTX.pixel_equiv_x/CTX.s[1], 
		  (vv2.Pos.Z+vv1.Pos.Z)/2. + 3*CTX.pixel_equiv_x/CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.geom.normals) {
    List_Read(s->Orientations,0,&vv1);
    List_Read(s->Orientations,1,&vv2);
    n[0] = s->plan[2][0];
    n[1] = s->plan[2][1];
    n[2] = s->plan[2][2];
    norme(n);
    n[0] *= CTX.geom.normals * CTX.pixel_equiv_x/CTX.s[0] ;
    n[1] *= CTX.geom.normals * CTX.pixel_equiv_x/CTX.s[1] ;
    n[2] *= CTX.geom.normals * CTX.pixel_equiv_x/CTX.s[2] ;
    nn = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
    glColor4ubv((GLubyte*)&CTX.color.geom.normals);
    Draw_Vector(DRAW_POST_ARROW, 0, (vv2.Pos.X+vv1.Pos.X)/2., (vv2.Pos.Y+vv1.Pos.Y)/2., 
		(vv2.Pos.Z+vv1.Pos.Z)/2., nn, n[0],n[1],n[2],NULL,NULL);
  }

}


void Draw_NonPlane_Surface (Surface *s){
  Vertex   v,n1,n2,n3;
  int      i,NbTics,N;
  double   u,n[3],nn,nx[3],ny[3];
  double  tics[20];
  double u0, un,v0,vn;
  int kk;
  char Num[100];

  u0 =v0= 0;
  un =vn= 1;

  if(!s)return;

  if((s->Typ == MSH_SURF_NURBS)){
    NbTics = 5;
    u0 = s->ku[0];
    un = s->ku[s->OrderU + s->Nu];
    v0 = s->kv[0];
    vn = s->kv[s->OrderV + s->Nv];
    for(i=0;i<NbTics;i++){
      tics[i] = v0 + ((double)(i+1)/(double)NbTics) * (vn - v0);
    }
    if(CTX.geom.shade){
      GLUnurbsObj *nurb;
      nurb=gluNewNurbsRenderer();
      gluNurbsProperty(nurb,(GLenum)GLU_SAMPLING_TOLERANCE,50.0);
      gluNurbsProperty(nurb,(GLenum)GLU_DISPLAY_MODE,GLU_FILL );
      gluBeginSurface(nurb);
      gluNurbsSurface(nurb, s->Nu+s->OrderU+1,s->ku, s->Nv+s->OrderV+1,s->kv,
		      4, 4*s->Nu, s->cp, s->OrderU+1,s->OrderV+1,
		      GL_MAP2_VERTEX_4);
      gluEndSurface(nurb);
      gluDeleteNurbsRenderer(nurb);
      return;
    }
  }
  else {
    NbTics = 1;
    tics[0] = 0.5;
  }

  glEnable(GL_LINE_STIPPLE);


  if(CTX.geom.surfaces){
    for(kk = 0;kk<NbTics;kk++){
      N = 50;
      glBegin(GL_LINE_STRIP);
      for(i=0;i<N+1;i++){
    	u = u0 + (un-u0)*(double)i/(double)N;
    	v = InterpolateSurface(s,u,tics[kk],0,0);
    	glVertex3d(v.Pos.X,v.Pos.Y,v.Pos.Z);
      }
      glEnd();
    }
  }

  if(s->Typ == MSH_SURF_NURBS){
    for(i=0;i<NbTics;i++){
      tics[i] = u0+((double)(i+1)/(double)NbTics) * (un - u0);
    }
  }

  if(CTX.geom.surfaces){
    for( kk = 0;kk<NbTics;kk++){
      glBegin(GL_LINE_STRIP);
      for(i=0;i<N+1;i++){
    	u = v0 + (vn-v0)*(double)i/(double)N;
    	v = InterpolateSurface(s,tics[kk],u,0,0);
    	glVertex3d(v.Pos.X,v.Pos.Y,v.Pos.Z);
      }
      glEnd();
    }
  }

  if(s->Mat){
    glLineWidth(1.);
  }

  if(CTX.geom.surfaces_num){
    v = InterpolateSurface(s,0.5,0.5,0,0);
    sprintf(Num,"%d",s->Num);
    glRasterPos3d(v.Pos.X+3*CTX.pixel_equiv_x/CTX.s[0],
		  v.Pos.Y+3*CTX.pixel_equiv_x/CTX.s[1], 
		  v.Pos.Z+3*CTX.pixel_equiv_x/CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.geom.normals){
    glDisable(GL_LINE_STIPPLE);
    n1 = InterpolateSurface(s,0.5,0.5,0,0);
    n2 = InterpolateSurface(s,0.6,0.5,0,0);
    n3 = InterpolateSurface(s,0.5,0.6,0,0);
    nx[0] = n2.Pos.X - n1.Pos.X;
    nx[1] = n2.Pos.Y - n1.Pos.Y;
    nx[2] = n2.Pos.Z - n1.Pos.Z;
    ny[0] = n3.Pos.X - n1.Pos.X;
    ny[1] = n3.Pos.Y - n1.Pos.Y;
    ny[2] = n3.Pos.Z - n1.Pos.Z;
    prodve(nx,ny,n);
    norme(n);
    n[0] *= CTX.geom.normals * CTX.pixel_equiv_x/CTX.s[0] ;
    n[1] *= CTX.geom.normals * CTX.pixel_equiv_x/CTX.s[1] ;
    n[2] *= CTX.geom.normals * CTX.pixel_equiv_x/CTX.s[2] ;
    nn = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
    glColor4ubv((GLubyte*)&CTX.color.geom.normals);
    Draw_Vector(DRAW_POST_ARROW, 0, n1.Pos.X, n1.Pos.Y, n1.Pos.Z,
		nn, n[0],n[1],n[2],NULL,NULL);
    glEnable(GL_LINE_STIPPLE);
  }

}

void Draw_Simplex_Surfaces (void *a, void *b);

void Draw_Surface (void *a, void *b){
  Surface *s;

  s = *(Surface**)a;

  //  if(!s->Support)return;

  if(!EntiteEstElleVisible(s->Num)) return;

  if(CTX.render_mode == GMSH_SELECT){
    glLoadName(2);
    glPushName(s->Num);
  }

  if(!CTX.geom.shade){
    if(s->Mat){
      glLineWidth(2.);
      glColor4ubv((GLubyte*)&CTX.color.geom.surface_sel);
    }
    else if (Highlighted){
      glLineWidth(2.);
      glColor4ubv((GLubyte*)&CTX.color.geom.surface_hlt);
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1,0x0F0F);
    }
    else{
      glLineWidth(1.);
      glColor4ubv((GLubyte*)&CTX.color.geom.surface);
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1,0x0F0F);
    }
  }
  else{
    ColorSwitch(abs(s->Num));
  }

  if(s->Typ == MSH_SURF_STL){
    glDisable(GL_LINE_STIPPLE);
    Tree_Action(s->STL->Simplexes,Draw_Simplex_Surfaces);
  }
  else if(s->Typ == MSH_SURF_PLAN)
    Draw_Plane_Surface(s);
  else
    Draw_NonPlane_Surface(s);

  if(CTX.render_mode == GMSH_SELECT){
    glPopName ();
    glDisable(GL_LINE_STIPPLE);
  }

  glDisable(GL_LINE_STIPPLE);


}




/* ------------------------------------------------------------------------ */
/*  D r a w _ G e o m                                                       */
/* ------------------------------------------------------------------------ */

extern void DrawVolumes (Mesh *m);

void Draw_Geom (Mesh *m) {

  if(m->status == -1) return;

  if(CTX.geom.points || CTX.geom.points_num)
    Tree_Action(m->Points, Draw_Point);
  if(CTX.geom.lines || CTX.geom.lines_num)
    Tree_Action(m->Curves,  Draw_Curve  );
  if(CTX.geom.surfaces || CTX.geom.surfaces_num)
    Tree_Action(m->Surfaces,Draw_Surface);
  if(CTX.geom.volumes || CTX.geom.volumes_num)
    DrawVolumes(m);

}

void ZeroCurve(void *a,void *b){
  Curve *c;
  c = *(Curve**)a;
  c->ipar[3] = 0;
}

void ZeroPoint(void *a,void *b){
  Vertex *v;
  v = *(Vertex**)a;
  v->Frozen = 0;
}

void ZeroSurface(void *a,void *b){
  Surface *s;
  s = *(Surface**)a;
  s->Mat = 0;
}

void ZeroHighlight(Mesh *m){
  Tree_Action(m->Points,ZeroPoint);
  Tree_Action(m->Curves,ZeroCurve);
  Tree_Action(m->Surfaces,ZeroSurface);
}


/* ------------------------------------------------------------------------ */
/*  D r a w _ A x e s                                                       */
/* ------------------------------------------------------------------------ */

void Draw_Axes (double s) {
  double  f, g, b, c;
  
  if(s == 0.) return;

  f = 0.666 * s;
  g = 1.233 * s;
  b = .1 * s;
  c = 0.666 * b;

  glLineWidth(1.);
  glColor4ubv((GLubyte*)&CTX.color.axes);

  glBegin(GL_LINES);
  if(CTX.range[2] != 0.){
    /* X */
    glVertex3d(0.,   0.,   0.);  
    glVertex3d(s,    0.,   0.);  
    glVertex3d(g-b,  b,    0.);  
    glVertex3d(g+b, -b,    0.);  
    glVertex3d(g,   -b,    b);  
    glVertex3d(g,    b,   -b);  
    /* Y */
    glVertex3d(0.,   0.,   0.);  
    glVertex3d(0.,   s,    0.);  
    glVertex3d(-b,   g+b,  0.);  
    glVertex3d(0.,   g,    0.);  
    glVertex3d(0.,   g,    0.);  
    glVertex3d(0.,   g+b, -b);  
    glVertex3d(0.,   g,    0.);  
    glVertex3d(.5*b, g-b, .5*b);  
    /* Z */
    glVertex3d(0.,   0.,   0.);  
    glVertex3d(0.,   0.,   s);  
    glVertex3d(-b,   b,    g);  
    glVertex3d(0.,   b,    g-b);  
    glVertex3d(0.,   b,    g-b);  
    glVertex3d(0.,  -b,    g+b);  
    glVertex3d(0.,  -b,    g+b);  
    glVertex3d(b,   -b,    g);  
  }
  else{
    /* X */
    glVertex3d(0.,   0.,   0.);  
    glVertex3d(s,    0.,   0.);  
    glVertex3d(g-c,  b,    0.);  
    glVertex3d(g+c, -b,    0.);  
    glVertex3d(g-c, -b,    0.);  
    glVertex3d(g+c,  b,    0.);  
    /* Y */
    glVertex3d(0.,   0.,   0.);  
    glVertex3d(0.,   s,    0.);  
    glVertex3d(-c,   g+b,  0.);  
    glVertex3d(0.,   g,    0.);  
    glVertex3d(0.,   g,    0.);  
    glVertex3d(c,    g+b,  0.);  
    glVertex3d(0.,   g,    0.);  
    glVertex3d(0.,   g-b,  0.);
  }
  glEnd();
  
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(2,0x0F0F);
  glBegin(GL_LINES);
  if(CTX.range[2] != 0.){
    glVertex3d(f,  0., 0.);  
    glVertex3d(f,  0., f );  
    glVertex3d(f,  0., f );  
    glVertex3d(0., 0., f );  
    glVertex3d(0., 0., f );  
    glVertex3d(0., f,  f );  
    glVertex3d(0., f,  f );  
    glVertex3d(0., f,  0.);  
  }
  glVertex3d(0., f,  0.);  
  glVertex3d(f,  f,  0.);  
  glVertex3d(f,  f,  0.);  
  glVertex3d(f,  0., 0.);  
  glEnd();
  glDisable(GL_LINE_STIPPLE);

}


/* ------------------------------------------------------------------------ */
/*  H i g h l i g h t                                                       */
/* ------------------------------------------------------------------------ */

void BeginHighlight(void){
  if(CTX.geom.highlight){
    Highlighted = 1;
    if(CTX.overlay){ 
      InitOv();
    }
    else{ 
      Init();
    }
    glPushMatrix();
    InitPosition();    
    if(CTX.db) glDrawBuffer(GL_FRONT);
  }  
}


void EndHighlight(int permanent){
  Highlighted = 0;
  if(permanent){
    Init();
    Draw();
  }
  else{
    if(CTX.geom.highlight) {
      glPopMatrix();
      if(CTX.db) glDrawBuffer(GL_BACK);
    }
  }
}

void HighlightEntity(Vertex *v,Curve *c, Surface *s, int permanent){

  Curve *cc;
  Vertex *v1,*v2;
  char Message[256],temp[256];
  int i,nbg;

  if(v){
    if(permanent) v->Frozen = 1;
    if(CTX.geom.highlight) Draw_Point(&v,NULL);
    Msg(SELECT,"Point %d {%.5g,%.5g,%.5g} (%.5g)", v->Num,v->Pos.X,v->Pos.Y,v->Pos.Z,v->lc);
  }
  else if(c){
    if(permanent) c->ipar[3] = 1;
    if(CTX.geom.highlight) Draw_Curve(&c,NULL);

    List_Read(c->Control_Points,0,&v1);
    List_Read(c->Control_Points,List_Nbr(c->Control_Points)-1,&v2);
    Msg(SELECT,"Line %d  {%d->%d}",c->Num,v1->Num,v2->Num);
  }
  else if(s){
    if(permanent && s->Mat == 1) return;
    if(permanent) s->Mat = 1;
    if(CTX.geom.highlight) Draw_Surface(&s,NULL);

    if(s->Typ == MSH_SURF_PLAN)sprintf(Message,"Plan Surf %d {",s->Num);
    else if(s->Typ == MSH_SURF_REGL)sprintf(Message,"Ruld Surf %d {",s->Num);
    else sprintf(Message,"Surf %d {",s->Num);

    nbg = List_Nbr(s->s.Generatrices) ;

    if(nbg < 10){
      for(i=0;i<nbg;i++){
	List_Read(s->s.Generatrices,i,&cc);
	if(!i)sprintf(temp,"%d",cc->Num);
	else sprintf(temp,",%d",cc->Num);
	strcat(Message,temp);
      }
    }
    else{
      strcat(Message,"...");
    }
    strcat(Message,"}");
    Msg(SELECT,Message);
  }
  else{
    Msg(SELECT," ");
  }

}


void HighlightEntityNum(int v, int c, int s, int permanant){
  Vertex *pv,V;
  Curve *pc,C;
  Surface *ps,S;
  if(v){
    pv = &V;
    pv->Num = v;
    if(Tree_Query(THEM->Vertices,&pv)){
      HighlightEntity(pv,NULL,NULL,permanant);
    }
  }
  if(c){
    pc = &C;
    pc->Num = c;
    if(Tree_Query(THEM->Curves,&pc)){
      HighlightEntity(NULL,pc,NULL,permanant);
    }
  }
  if(s){
    ps = &S;
    ps->Num = s;
    if(Tree_Query(THEM->Surfaces,&ps)){
      HighlightEntity(NULL,NULL,ps,permanant);
    }
  }
  glFlush();
}

