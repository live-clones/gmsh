// $Id: CAD.cpp,v 1.56 2003-02-20 10:05:09 remacle Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "DataBase.h"
#include "Interpolation.h"
#include "Create.h"
#include "CAD.h"
#include "Edge.h"
#include "Context.h"

#if defined(HAVE_GSL)
#include "gsl_newt.h"
#include "gsl_brent.h"
#else
#include "NR.h"
#endif
                                    
extern Mesh      *THEM;
extern Context_T  CTX;

static List_T  *ListOfTransformedPoints=NULL;

// Basic functions

int NEWPOINT(void){
  return (THEM->MaxPointNum + 1);
}

int NEWLINE(void){
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxLineNum + 1);
}

int NEWLINELOOP(void){
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxLineLoopNum + 1);
}

int NEWSURFACE(void){
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxSurfaceNum + 1);
}

int NEWSURFACELOOP(void){
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxSurfaceLoopNum + 1);
}

int NEWVOLUME(void){
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxVolumeNum + 1);
}

int NEWPHYSICAL(void){
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxPhysicalNum + 1);
}

int NEWREG(void){
  return (IMAX(THEM->MaxLineNum,
	       IMAX(THEM->MaxLineLoopNum,
		    IMAX(THEM->MaxSurfaceNum,
			 IMAX(THEM->MaxSurfaceLoopNum,
			      IMAX(THEM->MaxVolumeNum, THEM->MaxPhysicalNum)))))
	  + 1);
}




int compare2Lists (List_T *List1, List_T *List2,
                   int (*fcmp)(const void *a, const void *b)){
  int i,found;

  if(List_Nbr(List1) != List_Nbr(List2))return  List_Nbr(List1) - List_Nbr(List2);
  
  List_T *List1Prime = List_Create(List_Nbr(List1),1,List1->size);
  List_T *List2Prime = List_Create(List_Nbr(List2),1,List2->size);
  List_Copy(List1,List1Prime);
  List_Copy(List2,List2Prime);
  List_Sort(List1Prime,fcmp);
  List_Sort(List2Prime,fcmp);
  
  for(i=0;i<List_Nbr(List1Prime);i++){
    found = fcmp(List_Pointer(List1Prime,i),
                 List_Pointer(List2Prime,i));
    if(found != 0){
      List_Delete(List1Prime);
      List_Delete(List2Prime);
      return found;
    }
  }
  List_Delete(List1Prime);
  List_Delete(List2Prime);
  return 0;
}

void dist_ddg(double x1,double y1,double z1,
              double x2,double y2,double z2,
              double x3,double y3,double z3,
              double x4,double y4,double z4,
              double *x,double *y,double *z){

  double v[3],u[3],d;

  u[0] = x1-x3;
  u[1] = y1-y3;
  u[2] = z1-z3;

  v[0] = x4-x3;
  v[1] = y4-y3;
  v[2] = z4-z3;

  norme(v);
  prosca(u,v,&d);

  *x = d* x4 + x3 * (1.-d);
  *y = d* y4 + y3 * (1.-d);
  *z = d* z4 + z3 * (1.-d);
}


Vertex *FindPoint(int inum, Mesh *M){
  Vertex  C,*pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(M->Points,&pc)){
    return pc;
  }
  return NULL;
}

Vertex *FindVertex(int inum, Mesh *M){
  Vertex  C,*pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(M->Vertices,&pc)){
    return pc;
  }
  return NULL;
}

Curve *FindCurve(int inum, Mesh *M){
  Curve C,*pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(M->Curves,&pc)){
    return pc;
  }
  return NULL;
}

Surface *FindSurface(int inum, Mesh *M){
  Surface S,*ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(M->Surfaces,&ps)){
    return ps;
  }
  return NULL;
}

Volume *FindVolume(int inum, Mesh *M){
  Volume V,*pv;
  pv = &V;
  pv->Num = inum;
  if(Tree_Query(M->Volumes,&pv)){
    return pv;
  }
  return NULL;
}

EdgeLoop *FindEdgeLoop(int inum, Mesh *M){
  EdgeLoop S,*ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(M->EdgeLoops,&ps)){
    return ps;
  }
  return NULL;
}

SurfaceLoop *FindSurfaceLoop(int inum, Mesh *M){
  SurfaceLoop S,*ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(M->SurfaceLoops,&ps)){
    return ps;
  }
  return NULL;
}

void CopyVertex (Vertex *v, Vertex *vv){
  vv->lc = v->lc;
  vv->u = v->u;
  vv->Pos.X = v->Pos.X;
  vv->Pos.Y = v->Pos.Y;
  vv->Pos.Z = v->Pos.Z;
  vv->Freeze.X = v->Freeze.X;
  vv->Freeze.Y = v->Freeze.Y;
  vv->Freeze.Z = v->Freeze.Z;
}

Vertex *DuplicateVertex (Vertex *v){
  Vertex *pv;
  pv = Create_Vertex(NEWPOINT(),0,0,0,0,0);
  CopyVertex (v,pv);
  Tree_Insert(THEM->Points,&pv);
  return pv;
}

void CopyCurve (Curve *c, Curve *cc){
  int i,j;
  cc->Typ = c->Typ;
  //We should not copy the meshing method : if the meshes are to
  //be copied, the meshing algorithm will take care of it
  //(e.g. ExtrudeMesh()).
  //cc->Method = c->Method; 
  for(i=0;i<4;i++)cc->ipar[i] = c->ipar[i];
  for(i=0;i<4;i++)cc->dpar[i] = c->dpar[i];
  cc->l = c->l;
  for(i=0;i<4;i++)for(j=0;j<4;j++)cc->mat[i][j] = c->mat[i][j];
  cc->beg = c->beg;
  cc->end = c->end;
  cc->ubeg = c->ubeg;
  cc->uend = c->uend;
  cc->Control_Points = List_Create(List_Nbr(c->Control_Points),1,sizeof(Vertex*));
  List_Copy(c->Control_Points,cc->Control_Points);
  End_Curve(cc);
  Tree_Insert(THEM->Curves,&cc);
}

Curve *DuplicateCurve (Curve *c){
  Curve *pc;
  Vertex *v,*newv;
  pc = Create_Curve(NEWLINE(),0,1,NULL,NULL,-1,-1,0.,1.);
  CopyCurve(c,pc);
  for(int i=0;i<List_Nbr(c->Control_Points);i++){
    List_Read(pc->Control_Points,i,&v);
    newv = DuplicateVertex(v);
    List_Write(pc->Control_Points,i,&newv);
  }
  pc->beg = DuplicateVertex(c->beg);
  pc->end = DuplicateVertex(c->end);
  CreateReversedCurve (THEM,pc);
  
  return pc;
}

void CopySurface (Surface *s, Surface *ss){
  int i,j;
  ss->Typ = s->Typ;
  //We should not copy the meshing method: if the meshes are to
  //be copied, the meshing algorithm will take care of it
  //(e.g. ExtrudeMesh()).
  //ss->Method = s->Method;
  ss->Recombine = s->Recombine;
  ss->RecombineAngle = s->RecombineAngle;
  for(i=0;i<4;i++)ss->ipar[i] = s->ipar[i];
  ss->Nu = s->Nu;
  ss->Nv = s->Nv;
  ss->a = s->a;ss->b = s->b;ss->c = s->c; ss->d = s->d;
  for(i=0;i<3;i++)for(j=0;j<3;j++)ss->plan[i][j] = s->plan[i][j];
  for(i=0;i<3;i++)for(j=0;j<3;j++)ss->invplan[i][j] = s->invplan[i][j];
  ss->Generatrices = List_Create(List_Nbr(s->Generatrices),1,sizeof(Curve*));
  List_Copy(s->Generatrices,ss->Generatrices);
  if(s->Control_Points){
    ss->Control_Points = List_Create(List_Nbr(s->Control_Points),1,sizeof(Vertex*));
    List_Copy(s->Control_Points,ss->Control_Points);
  }
  End_Surface(ss);
  Tree_Insert(THEM->Surfaces,&ss);
}

Surface *DuplicateSurface (Surface *s){
  Surface *ps;
  Curve *c,*newc;
  Vertex *v,*newv;
  int i;

  ps = Create_Surface(NEWSURFACE(),0);
  CopySurface(s,ps);
  for(i=0;i<List_Nbr(ps->Generatrices);i++){
    List_Read(ps->Generatrices,i,&c);
    newc = DuplicateCurve(c);
    List_Write(ps->Generatrices,i,&newc);
  }
  
  for(i=0;i<List_Nbr(ps->Control_Points);i++){
    List_Read(ps->Control_Points,i,&v);
    newv = DuplicateVertex(v);
    List_Write(ps->Control_Points,i,&newv);
  }

  return ps;
}

void CopyShape(int Type, int Num, int *New){
  Surface *s,*news;
  Curve *c, *newc;
  Vertex *v,*newv;
  
  switch(Type){
  case MSH_POINT:
    if(!(v = FindPoint(Num,THEM))){
      Msg(GERROR, "Unknown Vertex %d", Num);
      return;
    }
    newv = DuplicateVertex(v);
    *New = newv->Num;
    break;
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_CIRC:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_NURBS:
    if(!(c = FindCurve(Num,THEM))){
      Msg(GERROR, "Unknown Curve %d", Num);
      return;
    }
    newc = DuplicateCurve(c);
    *New = newc->Num;
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
    if(!(s = FindSurface(Num,THEM))){
      Msg(GERROR, "Unknown Surface %d", Num);
      return;
    }
    news = DuplicateSurface(s);
    *New = news->Num;
    break;
  default:
    Msg(GERROR, "Impossible to copy entity %d (of type %d)", Num, Type);
    break;
  }
}

void DeletePoint(int ip){
  Vertex *v = FindPoint(ip,THEM);
  if(!v) return;
  List_T *Curves = Tree2List(THEM->Curves);
  for(int i=0;i<List_Nbr(Curves);i++){
    Curve *c;
    List_Read(Curves,i,&c);
    for(int j=0;j<List_Nbr(c->Control_Points);j++){
      if(!compareVertex(List_Pointer(c->Control_Points,j),&v))return;
    }
  }
  List_Delete(Curves);
  if(v->Num == THEM->MaxPointNum) THEM->MaxPointNum--;
  Tree_Suppress(THEM->Points,&v);
}

void DeleteCurve(int ip){
  Curve *c = FindCurve(ip,THEM);
  if(!c) return;
  List_T *Surfs = Tree2List(THEM->Surfaces);
  for(int i=0;i<List_Nbr(Surfs);i++){
    Surface *s;
    List_Read(Surfs,i,&s);
    for(int j=0;j<List_Nbr(s->Generatrices);j++){
      if(!compareCurve(List_Pointer(s->Generatrices,j),&c))return;
    }
  }
  List_Delete(Surfs);
  if(c->Num == THEM->MaxLineNum) THEM->MaxLineNum--;
  Tree_Suppress(THEM->Curves,&c);
}

void DeleteSurface(int is){
  // Il faut absolument coder une
  // structure coherente pour les volumes.
  Surface *s = FindSurface(is,THEM);
  if(!s) return;
  List_T *Vols = Tree2List(THEM->Volumes);
  for(int i=0;i<List_Nbr(Vols);i++){
    Volume *v;
    List_Read(Vols,i,&v);
    for(int j=0;j<List_Nbr(v->Surfaces);j++){
      if(!compareCurve(List_Pointer(v->Surfaces,j),&s))return;
    }
  }
  List_Delete(Vols);
  if(s->Num == THEM->MaxSurfaceNum) THEM->MaxSurfaceNum--;
  Tree_Suppress(THEM->Surfaces,&s);
}

void DeleteShape(int Type, int Num){

  switch(Type){
  case MSH_POINT:
    DeletePoint(Num);
    break;
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_CIRC:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_NURBS:
    DeleteCurve(Num);
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
    DeleteSurface(Num);
    break;
  default:
    Msg(GERROR, "Impossible to delete entity %d (of type %d)", Num, Type);
    break;
  }
}

void ColorCurve(int ip, unsigned int col){
  Curve *c = FindCurve(ip,THEM);
  if(!c) return;
  c->Color.type = 1;
  c->Color.mesh = c->Color.geom = col;
}

void ColorSurface(int is, unsigned int col){
  Surface *s = FindSurface(is,THEM);
  if(!s) return;
  s->Color.type = 1;
  s->Color.mesh = s->Color.geom = col;
}

void ColorShape(int Type, int Num, unsigned int Color){

  switch(Type){
  case MSH_POINT:
    break;
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_CIRC:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_NURBS:
    ColorCurve(Num,Color);
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
    ColorSurface(Num,Color);
    break;
  default:
    break;
  }
}

Curve * CreateReversedCurve (Mesh *M,Curve *c){
  Curve *newc;
  Vertex *e1,*e2,*e3,*e4;
  int i;
  newc = Create_Curve(-c->Num, c->Typ,1,NULL,NULL,-1,-1,0.,1.);
  newc->Control_Points = List_Create(List_Nbr(c->Control_Points), 1, sizeof(Vertex*));
  if (c->Typ == MSH_SEGM_ELLI || c->Typ == MSH_SEGM_ELLI_INV){
    List_Read(c->Control_Points,0,&e1);
    List_Read(c->Control_Points,1,&e2);
    List_Read(c->Control_Points,2,&e3);
    List_Read(c->Control_Points,3,&e4);
    List_Add(newc->Control_Points,&e4);
    List_Add(newc->Control_Points,&e2);
    List_Add(newc->Control_Points,&e3);
    List_Add(newc->Control_Points,&e1);
  }
  else
    List_Invert(c->Control_Points, newc->Control_Points);
  
  if (c->Typ == MSH_SEGM_NURBS && c->k){
    newc->k = (float*)malloc((c->degre + List_Nbr(c->Control_Points)+1)*sizeof(float));
    for(i=0;i<c->degre + List_Nbr(c->Control_Points)+1;i++)
      newc->k[c->degre + List_Nbr(c->Control_Points)-i] = c->k[i];
  }
  
  if (c->Typ == MSH_SEGM_CIRC) newc->Typ =  MSH_SEGM_CIRC_INV;
  if (c->Typ == MSH_SEGM_CIRC_INV) newc->Typ =  MSH_SEGM_CIRC;
  if (c->Typ == MSH_SEGM_ELLI) newc->Typ =  MSH_SEGM_ELLI_INV;
  if (c->Typ == MSH_SEGM_ELLI_INV) newc->Typ =  MSH_SEGM_ELLI;
  newc->Vertices = List_Create(10 ,1 ,sizeof(Vertex*));
  newc->Method = c->Method;
  newc->degre  = c->degre;
  newc->beg = c->end;
  newc->end = c->beg;
  newc->ubeg = 1. - c->uend;
  newc->uend = 1. - c->ubeg;
  End_Curve(newc);
  
  Curve **pc;

  if((pc = (Curve**)Tree_PQuery(M->Curves,&newc))){
    Free_Curve(&newc,0);
    return *pc;
  }
  else 
    Tree_Insert(M->Curves, &newc);

  return newc;
}



void ModifyLcPoint(int ip, double lc){
  Vertex *v = FindPoint(ip,THEM);
  if(v) v->lc = lc;
}


int recognize_seg(int typ, List_T * liste, int *seg){
  int i,beg,end;
  Curve *pc;

  List_T *temp = Tree2List(THEM->Curves);
  List_Read(liste,0,&beg);
  List_Read(liste,List_Nbr(liste)-1,&end);
  for(i=0;i<List_Nbr(temp);i++){
    List_Read(temp,i,&pc);
    if(pc->Typ == typ &&
       pc->beg->Num == beg &&
       pc->end->Num == end){
      List_Delete(temp);
      *seg = pc->Num;
      return 1;
    }
  }
  List_Delete(temp);
  return 0;
}



int recognize_loop(List_T * liste, int *loop){
  int i,res;
  EdgeLoop *pe;

  res = 0;
  *loop = 0;
  List_T *temp = Tree2List(THEM->EdgeLoops);
  for(i=0;i<List_Nbr(temp);i++){
    List_Read(temp,i,&pe);
    if(!compare2Lists(pe->Curves,liste,fcmp_absint)){
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

int recognize_surfloop(List_T * liste, int *loop){
  int i,res;
  EdgeLoop *pe;

  res = 0;
  *loop = 0;
  List_T *temp = Tree2List(THEM->SurfaceLoops);
  for(i=0;i<List_Nbr(temp);i++){
    List_Read(temp,i,&pe);
    if(!compare2Lists(pe->Curves,liste,fcmp_absint)){
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

// Linear applications

void SetTranslationMatrix (double matrix[4][4],double T[3]){
  int i, j;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      matrix[i][j] = (i==j)? 1.0:0.0;
    }
  }
  for(i=0;i<3;i++)matrix[i][3] = T[i];
}

void SetSymmetryMatrix (double matrix[4][4],double A, double B, double C, double D){
  double F = -2.0 / (A*A+B*B+C*C);
  matrix[0][0] = 1. + A*A*F;
  matrix[0][1] =      A*B*F;
  matrix[0][2] =      A*C*F;
  matrix[0][3] =      A*D*F;
  matrix[1][0] =      A*B*F;
  matrix[1][1] = 1. + B*B*F;
  matrix[1][2] =      B*C*F;
  matrix[1][3] =      B*D*F;
  matrix[2][0] =      A*C*F;
  matrix[2][1] =      B*C*F;
  matrix[2][2] = 1. + C*C*F;
  matrix[2][3] =      C*D*F;
  matrix[3][0] =      B*C*F;
  matrix[3][1] =      0.0;
  matrix[3][2] =      0.0;
  matrix[3][3] =      1.0;
}

void SetDilatationMatrix (double matrix[4][4],double T[3],double A){
  matrix[0][0] = A;
  matrix[0][1] = 0.0;
  matrix[0][2] = 0.0;
  matrix[0][3] = T[0]*(1.0-A);
  matrix[1][0] = 0.0;
  matrix[1][1] = A;
  matrix[1][2] = 0.0;
  matrix[1][3] = T[1]*(1.0-A);
  matrix[2][0] = 0.0;
  matrix[2][1] = 0.0;
  matrix[2][2] = A;
  matrix[2][3] = T[2]*(1.0-A);
  matrix[3][0] = 0.0;
  matrix[3][1] = 0.0;
  matrix[3][2] = 0.0;
  matrix[3][3] = 1.0;
}

static void GramSchmidt (double v1[3], double v2[3], double v3[3]){
  double tmp[3];
  norme(v1);
  prodve(v3,v1,tmp);
  norme(tmp);
  v2[0] = tmp[0];v2[1] = tmp[1];v2[2] = tmp[2];
  prodve(v1,v2,v3);
  norme(v3);
}

void SetRotationMatrix(double matrix[4][4],double Axe[3], double alpha){
  double t1[3],t2[3];
  if(Axe[0] != 0.0){
    t1[0] = 0.0;
    t1[1] = 1.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 0.0;
    t2[2] = 1.0;
  }
  else if(Axe[1] != 0.0){
    t1[0] = 1.0;
    t1[1] = 0.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 0.0;
    t2[2] = 1.0;
  }
  else {
    t1[0] = 1.0;
    t1[1] = 0.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 1.0;
    t2[2] = 0.0;
  }
  GramSchmidt(Axe,t1,t2);
  double rot[3][3],plan[3][3],invplan[3][3];
  plan[0][0] = Axe[0]; plan[0][1] = Axe[1]; plan[0][2] = Axe[2];
  plan[1][0] = t1[0] ; plan[1][1] = t1[1];  plan[1][2] = t1[2];
  plan[2][0] = t2[0] ; plan[2][1] = t2[1];  plan[2][2] = t2[2];
  rot[2][2] = cos(alpha) ; rot[2][1] =  sin(alpha) ; rot[2][0] = 0.;
  rot[1][2] = -sin(alpha); rot[1][1] =  cos(alpha) ; rot[1][0] = 0.;
  rot[0][2] = 0.         ; rot[0][1] = 0.          ; rot[0][0] = 1.;
  int i,j,k;
  for(i=0;i<3;i++)for(j=0;j<3;j++)invplan[i][j] = plan[j][i];
  double interm[3][3];
  for(i=0;i<3;i++)for(j=0;j<3;j++){
    interm[i][j] = 0.0;
    for(k=0;k<3;k++)interm[i][j] += invplan[i][k] * rot[k][j];
  }
  for(i=0;i<4;i++)for(j=0;j<4;j++)matrix[i][j] = 0.0;
  for(i=0;i<3;i++)for(j=0;j<3;j++){
    for(k=0;k<3;k++)matrix[i][j] += interm[i][k] * plan[k][j];
  }
  matrix[3][3] = 1.0;
}

static void vecmat4x4(double mat[4][4],double vec[4], double res[4]){
  int i,j;
  for(i=0;i<4;i++){
    res[i] = 0.0;
    for(j=0;j<4;j++){
      res[i] += mat[i][j] * vec[j];
    }
  }
}

void ApplyTransformationToPoint(double matrix[4][4], Vertex *v){
  double pos[4],vec[4];

  if(!ListOfTransformedPoints)
    ListOfTransformedPoints = List_Create(50,50,sizeof(int));
  
  if(!List_Search(ListOfTransformedPoints,&v->Num,fcmp_absint)){
    List_Add(ListOfTransformedPoints,&v->Num);
  }
  else
    return;
  
  vec[0] = v->Pos.X;
  vec[1] = v->Pos.Y;
  vec[2] = v->Pos.Z;
  vec[3] = v->w;
  vecmat4x4(matrix,vec,pos);
  v->Pos.X = pos[0];
  v->Pos.Y = pos[1];
  v->Pos.Z = pos[2];
  v->w = pos[3];
}

void ApplyTransformationToCurve (double matrix[4][4],Curve *c){
  Vertex *v;
  
  ApplyTransformationToPoint (matrix,c->beg);
  ApplyTransformationToPoint (matrix,c->end);
  
  for(int i=0;i<List_Nbr(c->Control_Points);i++){
    List_Read(c->Control_Points,i,&v);
    ApplyTransformationToPoint (matrix,v);
  }
  End_Curve(c);
}

void printCurve(Curve *c){
  Vertex *v;
  int N = List_Nbr(c->Control_Points);
  Msg(DEBUG,"Curve %d %d cp (%d->%d)",c->Num,N,c->beg->Num,c->end->Num);
  for(int i=0;i<N;i++){
    List_Read(c->Control_Points,i,&v);
    Msg(DEBUG,"Vertex %d (%g,%g,%g,%g)",v->Num,v->Pos.X,v->Pos.Y,v->Pos.Z,v->lc);
  }
}

void ApplyTransformationToSurface (double matrix[4][4],Surface *s){
  Curve *c;
  Vertex *v;
  int i;

  for(i=0;i<List_Nbr(s->Generatrices);i++){
    List_Read(s->Generatrices,i,&c);
    ApplyTransformationToCurve (matrix,c);
  }
  for(i=0;i<List_Nbr(s->Control_Points);i++){
    List_Read(s->Control_Points,i,&v);
    ApplyTransformationToPoint (matrix,v);
  }
  End_Surface(s);
}

void printSurface(Surface*s){
  Curve *c;
  int N = List_Nbr(s->Generatrices);

  Msg(DEBUG,"Surface %d, %d generatrices",s->Num,N);
  for(int i=0;i<N;i++){
    List_Read(s->Generatrices,i,&c);
    printCurve(c);
  }
}

void ApplicationOnShapes(double matrix[4][4], List_T *ListShapes){
  int i;
  Shape O;
  Vertex *v;
  Curve *c;
  Surface *s;
  
  List_Reset(ListOfTransformedPoints);

  for(i=0;i<List_Nbr(ListShapes);i++){
    List_Read(ListShapes,i,&O);
    switch(O.Type){
    case MSH_POINT:
      v = FindPoint(O.Num,THEM);
      if(v) ApplyTransformationToPoint(matrix, v);
      else Msg(GERROR, "Unknown Point %d", O.Num); 
      break;
    case MSH_SEGM_LINE:
    case MSH_SEGM_SPLN:
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
    case MSH_SEGM_CIRC:
    case MSH_SEGM_ELLI:
    case MSH_SEGM_NURBS:
      c = FindCurve(O.Num,THEM);
      if(c) ApplyTransformationToCurve(matrix, c);
      else Msg(GERROR, "Unknown Curve %d", O.Num); 
      break;
    case MSH_SURF_NURBS :
    case MSH_SURF_REGL :
    case MSH_SURF_TRIC :
    case MSH_SURF_PLAN :
      s = FindSurface(O.Num,THEM);
      if(s) ApplyTransformationToSurface(matrix, s);
      else Msg(GERROR, "Unknown Surface %d", O.Num); 
      break;
    default:
      Msg(GERROR, "Impossible to transform entity %d (of type %d)", O.Num, O.Type);
      break;
    }
  }

  List_Reset(ListOfTransformedPoints);
}

void TranslateShapes(double X,double Y,double Z,
                     List_T *ListShapes, int isFinal){
  double T[3],matrix[4][4];

  T[0] = X; T[1] = Y; T[2] = Z;
  SetTranslationMatrix(matrix,T);
  ApplicationOnShapes(matrix,ListShapes);

  if(CTX.geom.auto_coherence && isFinal) ReplaceAllDuplicates(THEM);
}

void DilatShapes(double X,double Y,double Z, double A,
                 List_T *ListShapes, int isFinal){
  double T[3],matrix[4][4];

  T[0] = X; T[1] = Y; T[2] = Z;
  SetDilatationMatrix(matrix,T,A);
  ApplicationOnShapes(matrix,ListShapes);

  if(CTX.geom.auto_coherence) ReplaceAllDuplicates(THEM);
}


void RotateShapes (double Ax,double Ay,double Az,
                   double Px,double Py, double Pz,
                   double alpha, List_T *ListShapes){
  double A[3], T[3], matrix[4][4];

  T[0] = -Px; T[1] = -Py; T[2] = -Pz;
  SetTranslationMatrix(matrix,T);
  ApplicationOnShapes(matrix,ListShapes);

  A[0] = Ax; A[1] = Ay; A[2] = Az;
  SetRotationMatrix(matrix,A,alpha);
  ApplicationOnShapes(matrix,ListShapes);

  T[0] = Px; T[1] = Py; T[2] = Pz;
  SetTranslationMatrix(matrix,T);
  ApplicationOnShapes(matrix,ListShapes);

  if(CTX.geom.auto_coherence) ReplaceAllDuplicates(THEM);
}

void SymmetryShapes (double A,double B,double C,
                     double D, List_T *ListShapes, int x){
  double matrix[4][4];

  SetSymmetryMatrix(matrix,A,B,C,D);
  ApplicationOnShapes(matrix,ListShapes);

  if(CTX.geom.auto_coherence) ReplaceAllDuplicates(THEM);
}


// Extrusion routines

void ProtudeXYZ (double &x, double &y, double &z, ExtrudeParams *e){
  double matrix[4][4];
  double T[3];
  Vertex v(x,y,z);

  T[0] = -e->geo.pt[0];
  T[1] = -e->geo.pt[1];
  T[2] = -e->geo.pt[2];
  SetTranslationMatrix(matrix,T);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix,&v);

  SetRotationMatrix(matrix,e->geo.axe,e->geo.angle);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix,&v);

  T[0] = -T[0]; T[1] = -T[1]; T[2] = -T[2];
  SetTranslationMatrix(matrix,T);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix,&v);

  x = v.Pos.X;
  y = v.Pos.Y;
  z = v.Pos.Z;

  List_Reset(ListOfTransformedPoints);
}


void Extrude_ProtudePoint(int type, int ip, 
			  double T0, double T1, double T2,
			  double A0, double A1, double A2,
                          double X0, double X1, double X2, double alpha,
                          Curve **pc, Curve **prc, 
			  ExtrudeParams *e){
  double xnew,ynew,znew,matrix[4][4],T[3],Ax[3],d;
  Vertex V,*pv,*newp,*chapeau;
  Curve *c;
  int i;
  
  pv= &V;
  pv->Num = ip;
  *pc = *prc = NULL;
  if(!Tree_Query(THEM->Points, &pv)) return;

  Msg(DEBUG, "Extrude Point %d", ip);

  chapeau = DuplicateVertex(pv);

  switch(type){

  case TRANSLATE :
    T[0] = T0; T[1] = T1; T[2] = T2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix,chapeau);

    if(!comparePosition(&pv,&chapeau)) return ;
    c = Create_Curve(NEWLINE(),MSH_SEGM_LINE,1,NULL,NULL,-1,-1,0.,1.);
    c->Control_Points = List_Create(2,1,sizeof(Vertex*));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
    if(e) c->Extrude->mesh = e->mesh;

    List_Add(c->Control_Points,&pv);
    List_Add(c->Control_Points,&chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;

  case ROTATE :
    T[0] = -X0; T[1] = -X1; T[2] = -X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix,chapeau);

    Ax[0] = A0; Ax[1] = A1; Ax[2] = A2;
    SetRotationMatrix(matrix,Ax,alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix,chapeau);

    T[0] = X0; T[1] = X1; T[2] = X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix,chapeau);

    if(!comparePosition(&pv,&chapeau)) return ;
    c = Create_Curve(NEWLINE(),MSH_SEGM_CIRC,1,NULL,NULL,-1,-1,0.,1.);
    c->Control_Points = List_Create(3,1,sizeof(Vertex*));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
    if(e) c->Extrude->mesh = e->mesh;

    List_Add(c->Control_Points,&pv);
    dist_ddg(pv->Pos.X,pv->Pos.Y,pv->Pos.Z,
             chapeau->Pos.X,chapeau->Pos.Y,chapeau->Pos.Z,
             X0,X1,X2,X0+A0,X1+A1,X2+A2,&xnew,&ynew,&znew);
    newp = DuplicateVertex(pv);
    newp->Pos.X = xnew;
    newp->Pos.Y = ynew;
    newp->Pos.Z = znew;
    List_Add(c->Control_Points,&newp);
    List_Add(c->Control_Points,&chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;

  case TRANSLATE_ROTATE :
    d = CTX.geom.extrude_spline_points;
    d = d?d:1;
    c = Create_Curve(NEWLINE(),MSH_SEGM_SPLN,1,NULL,NULL,-1,-1,0.,1.);
    c->Control_Points = List_Create(CTX.geom.extrude_spline_points+1,1,sizeof(Vertex*));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
    if(e) c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points,&pv);
    c->beg = pv;
    for(i=0 ; i<CTX.geom.extrude_spline_points ; i++){
      if(i) chapeau = DuplicateVertex(chapeau);

      T[0] = -X0; T[1] = -X1; T[2] = -X2;
      SetTranslationMatrix(matrix,T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix,chapeau);

      Ax[0] = A0; Ax[1] = A1; Ax[2] = A2;
      SetRotationMatrix(matrix,Ax,alpha/d);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix,chapeau);

      T[0] = X0; T[1] = X1; T[2] = X2;
      SetTranslationMatrix(matrix,T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix,chapeau);

      T[0] = T0/d; T[1] = T1/d; T[2] = T2/d;
      SetTranslationMatrix(matrix,T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix,chapeau);

      List_Add(c->Control_Points,&chapeau);
    }
    c->end = chapeau;
    break;

  default :
    Msg(GERROR, "Unknown extrusion type");
    return;
  }

  End_Curve(c);
  Tree_Add(THEM->Curves,&c);
  CreateReversedCurve (THEM,c);
  *pc = c;
  *prc = FindCurve(-c->Num,THEM);

  List_Reset(ListOfTransformedPoints);
}

Surface *Extrude_ProtudeCurve(int type, int ic,
                              double T0, double T1, double T2,
                              double A0, double A1, double A2,
                              double X0, double X1, double X2, double alpha, 
			      int final, ExtrudeParams *e){
  double matrix[4][4],T[3],Ax[3];
  Curve *CurveBeg,*CurveEnd;
  Curve *ReverseChapeau,*ReverseBeg,*ReverseEnd;
  Curve *pc, *revpc, *chapeau;
  Surface *s;
  
  pc    = FindCurve(ic,THEM);
  revpc = FindCurve(-ic,THEM);
  
  if(!pc || !revpc) return NULL;

  Msg(DEBUG, "Extrude Curve %d", ic);

  chapeau = DuplicateCurve(pc);
  
  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
  chapeau->Extrude->geo.Source = pc->Num;
  if(e) chapeau->Extrude->mesh = e->mesh;
  
  switch(type){
  case TRANSLATE :
    T[0] = T0; T[1] = T1; T[2] = T2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    break;
  case ROTATE :
    T[0] = -X0; T[1] = -X1; T[2] = -X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    
    Ax[0] = A0; Ax[1] = A1; Ax[2] = A2;
    SetRotationMatrix(matrix,Ax,alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    
    T[0] = X0; T[1] = X1; T[2] = X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    break;
  case TRANSLATE_ROTATE :
    T[0] = -X0; T[1] = -X1; T[2] = -X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    
    Ax[0] = A0; Ax[1] = A1; Ax[2] = A2;
    SetRotationMatrix(matrix,Ax,alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    
    T[0] = X0; T[1] = X1; T[2] = X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);

    T[0] = T0; T[1] = T1; T[2] = T2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix,chapeau);
    break;
  default :
    Msg(GERROR, "Unknown extrusion type");
    return NULL;
  }

  Extrude_ProtudePoint(type,pc->beg->Num,T0,T1,T2,
		       A0,A1,A2,X0,X1,X2,alpha,
                       &CurveBeg,&ReverseBeg,e);
  Extrude_ProtudePoint(type,pc->end->Num,T0,T1,T2,
		       A0,A1,A2,X0,X1,X2,alpha,
                       &CurveEnd,&ReverseEnd,e);
  
  if(!CurveBeg && !CurveEnd) return NULL;

  if(!CurveBeg || !CurveEnd)
    s = Create_Surface(NEWSURFACE(),MSH_SURF_TRIC);
  else
    s = Create_Surface(NEWSURFACE(),MSH_SURF_REGL);

  s->Generatrices = List_Create(4,1,sizeof(Curve*));
  s->Extrude = new ExtrudeParams;
  s->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
  s->Extrude->geo.Source = pc->Num;
  if(e) s->Extrude->mesh = e->mesh;
  
  ReverseChapeau = FindCurve(-chapeau->Num,THEM);

  if(!CurveBeg){
    List_Add(s->Generatrices,&pc);
    List_Add(s->Generatrices,&CurveEnd);
    List_Add(s->Generatrices,&ReverseChapeau);
  }
  else if(!CurveEnd){
    List_Add(s->Generatrices,&ReverseChapeau);
    List_Add(s->Generatrices,&ReverseBeg);
    List_Add(s->Generatrices,&pc);
  }
  else{
    List_Add(s->Generatrices,&pc);
    List_Add(s->Generatrices,&CurveEnd);
    List_Add(s->Generatrices,&ReverseChapeau);
    List_Add(s->Generatrices,&ReverseBeg);
  }

  End_Surface(s);
  Tree_Add(THEM->Surfaces,&s);

  List_Reset(ListOfTransformedPoints);

  if(final && CTX.geom.auto_coherence){
    ReplaceAllDuplicates(THEM);
    return NULL;
  }
  else
    return s;
}

void Extrude_ProtudeSurface(int type, int is,
                            double T0, double T1, double T2,
                            double A0, double A1, double A2,
                            double X0, double X1, double X2, double alpha,
                            int NewVolume, ExtrudeParams *e){
  double matrix[4][4],T[3],Ax[3];
  Curve *c,*c2;
  int i;
  Surface *s,*ps, *chapeau;
  Volume *pv = NULL;
  
  if(!(ps = FindSurface(is,THEM))) return;

  Msg(DEBUG, "Extrude Surface %d", is);

  chapeau = DuplicateSurface(ps);
  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
  chapeau->Extrude->geo.Source = ps->Num;
  if(e) chapeau->Extrude->mesh = e->mesh;
  
  for(i=0;i<List_Nbr(chapeau->Generatrices);i++) {
    List_Read(ps->Generatrices,i,&c2);
    List_Read(chapeau->Generatrices,i,&c);
    if(c->Num<0)
      if(!(c = FindCurve(-c->Num,THEM))){
         Msg(GERROR, "Unknown Curve %d", -c->Num);
	 return;
      }
    c->Extrude = new ExtrudeParams(COPIED_ENTITY);
    c->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
    //pas de abs()! il faut le signe pour copy_mesh dans ExtrudeMesh
    c->Extrude->geo.Source = c2->Num; 
    if(e) c->Extrude->mesh = e->mesh;
  }
  
  if(NewVolume){
    pv = Create_Volume(NewVolume,0);
    pv->Extrude = new ExtrudeParams;
    pv->Extrude->fill(type,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha);
    pv->Extrude->geo.Source = is;
    if(e) pv->Extrude->mesh = e->mesh;
    if(pv) List_Add(pv->Surfaces,&ps);
  }
  if(pv) List_Add(pv->Surfaces,&chapeau);

  for(i=0;i<List_Nbr(ps->Generatrices);i++){
    List_Read(ps->Generatrices,i,&c);
    s = Extrude_ProtudeCurve(type,c->Num,T0,T1,T2,A0,A1,A2,X0,X1,X2,alpha,0,e);
    if(pv && s) List_Add(pv->Surfaces,&s);
  }

  switch(type){
  case TRANSLATE :
    T[0] = T0; T[1] = T1; T[2] = T2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    break;
  case ROTATE :
    T[0] = -X0; T[1] = -X1; T[2] = -X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    
    Ax[0] = A0; Ax[1] = A1; Ax[2] = A2;
    SetRotationMatrix(matrix,Ax,alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    
    T[0] = X0; T[1] = X1; T[2] = X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    break;
  case TRANSLATE_ROTATE :
    T[0] = -X0; T[1] = -X1; T[2] = -X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    
    Ax[0] = A0; Ax[1] = A1; Ax[2] = A2;
    SetRotationMatrix(matrix,Ax,alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    
    T[0] = X0; T[1] = X1; T[2] = X2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);

    T[0] = T0; T[1] = T1; T[2] = T2;
    SetTranslationMatrix(matrix,T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix,chapeau);
    break;
  default :
    Msg(GERROR, "Unknown extrusion type");
    return;
  }

  Tree_Suppress(THEM->Surfaces,&chapeau);

  chapeau->Num = NEWSURFACE();
  THEM->MaxSurfaceNum = chapeau->Num;

  Tree_Add(THEM->Surfaces,&chapeau);
  
  if(pv) Tree_Add(THEM->Volumes,&pv);
  
  if(CTX.geom.auto_coherence) ReplaceAllDuplicates(THEM);

  List_Reset(ListOfTransformedPoints);
}

// Duplicate removal

int compareTwoCurves (const void *a, const void *b){
  Curve *c1, *c2;
  c1 = *(Curve**)a;
  c2 = *(Curve**)b;
  int comp;
  
  if(c1->Typ != c2->Typ)return c1->Typ - c2->Typ;
  comp = compareVertex(&c1->beg,&c2->beg);
  if(comp)return comp;
  comp = compareVertex(&c1->end,&c2->end);
  if(comp)return comp;
  // a finir pour des splines !!
  return 0;
  //return c1->Num - c2->Num;
}

int compareAbsCurve (const void *a, const void *b){
  Curve **q, **w;

  q = (Curve **) a;
  w = (Curve **) b;
  return (abs((*q)->Num) - abs((*w)->Num));
}

int compareTwoSurfaces (const void *a, const void *b){
  Surface *s1, *s2;
  s1 = *(Surface**)a;
  s2 = *(Surface**)b;
  return compare2Lists(s1->Generatrices,
                       s2->Generatrices,
                       compareAbsCurve);
}

void MaxNumPoint(void *a, void *b){
  Vertex *v = *(Vertex**)a;
  THEM->MaxPointNum = MAX(THEM->MaxPointNum,v->Num);
}

void MaxNumCurve(void *a, void *b){
  Curve *c = *(Curve**)a;
  THEM->MaxLineNum = MAX(THEM->MaxLineNum,c->Num);
}

void MaxNumSurface(void *a, void *b){
  Surface *s = *(Surface**)a;
  THEM->MaxSurfaceNum = MAX(THEM->MaxSurfaceNum,s->Num);
}

void ReplaceDuplicatePoints(Mesh *m){
  List_T *All;
  Tree_T *allNonDulpicatedPoints;
  Vertex *v, **pv, **pv2;
  Curve *c;
  Surface *s;
  int i,j,start,end;

  List_T *points2delete = List_Create(100,100,sizeof(Vertex*));

  // Create unique points

  start = Tree_Nbr(m->Points);

  All = Tree2List(m->Points);
  allNonDulpicatedPoints = Tree_Create(sizeof(Vertex*),comparePosition);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&v);
    if(!Tree_Search(allNonDulpicatedPoints,&v)){
      Tree_Insert(allNonDulpicatedPoints,&v);
    }
    else{
      Tree_Suppress(m->Points,&v);
      Tree_Suppress(m->Vertices,&v);      
      //List_Add(points2delete,&v);      
    }
  }
  List_Delete(All);

  end = Tree_Nbr(m->Points);

  if(start == end){
    Tree_Delete(allNonDulpicatedPoints);
    List_Delete(points2delete);
    return;
  }

  Msg(DEBUG, "Removed %d duplicate points", start-end);

  if(CTX.geom.old_newreg){
    m->MaxPointNum=0;
    Tree_Action(m->Points,MaxNumPoint);
    Tree_Action(m->Vertices,MaxNumPoint);
  }

  // Replace old points in curves

  All = Tree2List(m->Curves);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&c);
    if(!Tree_Query(allNonDulpicatedPoints,&c->beg))
      Msg(GERROR, "Weird point %d in Coherence", c->beg->Num);
    if(!Tree_Query(allNonDulpicatedPoints,&c->end))
      Msg(GERROR, "Weird point %d in Coherence", c->end->Num);
    for(j=0;j<List_Nbr(c->Control_Points);j++){
      pv = (Vertex**)List_Pointer(c->Control_Points,j);
      if(!(pv2 = (Vertex**)Tree_PQuery(allNonDulpicatedPoints, pv)))
	Msg(GERROR, "Weird point %d in Coherence", (*pv)->Num);
      else
	List_Write(c->Control_Points,j,pv2);
    }
  }
  List_Delete(All);

  // Replace old points in surfaces

  All = Tree2List(m->Surfaces);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&s);
    for(j=0;j<List_Nbr(s->Control_Points);j++){
      pv = (Vertex**)List_Pointer(s->Control_Points,j);
      if(!(pv2 = (Vertex**)Tree_PQuery(allNonDulpicatedPoints,pv)))
	Msg(GERROR, "Weird point %d in Coherence", (*pv)->Num);
      else
	List_Write(s->Control_Points,j,pv2);
    }
  }
  List_Delete(All);

  for(int k = 0; k < List_Nbr(points2delete);k++){
    List_Read(points2delete,i,&v);      
    Free_Vertex(&v,0);
  }

  Tree_Delete(allNonDulpicatedPoints);
  List_Delete(points2delete);

}

void ReplaceDuplicateCurves(Mesh *m){
  List_T *All;
  Tree_T *allNonDulpicatedCurves;
  Curve *c,*c2,**pc,**pc2;
  Surface *s;
  int i,j,start,end;

  // Create unique curves

  start = Tree_Nbr(m->Curves);

  All = Tree2List(m->Curves);
  allNonDulpicatedCurves = Tree_Create(sizeof(Curve*),compareTwoCurves);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&c);
    if(c->Num > 0){
      if(!Tree_Search(allNonDulpicatedCurves,&c)){
        Tree_Insert(allNonDulpicatedCurves,&c);
        if(!(c2 = FindCurve(-c->Num,m))){
          Msg(GERROR, "Unknown Curve %d", -c->Num);
	  List_Delete(All);
	  return;
	}
        Tree_Insert(allNonDulpicatedCurves,&c2);
      }
      else{
        Tree_Suppress(m->Curves,&c);
        if(!(c2 = FindCurve(-c->Num,m))){
          Msg(GERROR, "Unknown Curve %d", -c->Num);
	  List_Delete(All);
	  return;
	}
        Tree_Suppress(m->Curves,&c2);
      }
    }
  }
  List_Delete(All);

  end = Tree_Nbr(m->Curves);

  if(start == end){
    Tree_Delete(allNonDulpicatedCurves);
    return;
  } 

  Msg(DEBUG, "Removed %d duplicate curves", start-end);

  if(CTX.geom.old_newreg){
    m->MaxLineNum=0;
    Tree_Action(m->Curves,MaxNumCurve);
  }

  // Replace old curves in surfaces

  All = Tree2List(m->Surfaces);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&s);
    for(j=0;j<List_Nbr(s->Generatrices);j++){
      pc = (Curve**)List_Pointer(s->Generatrices,j);
      if(!(pc2 = (Curve**)Tree_PQuery(allNonDulpicatedCurves,pc)))
	Msg(GERROR, "Weird curve %d in Coherence", (*pc)->Num);
      else{
	List_Write(s->Generatrices,j,pc2);
	// Arghhh. Revoir compareTwoCurves !
	End_Curve(*pc2);
      }
    }
  }
  List_Delete(All);
  
  Tree_Delete(allNonDulpicatedCurves);
}

void ReplaceDuplicateSurfaces(Mesh *m){
  List_T *All;
  Tree_T *allNonDulpicatedSurfaces;
  Surface *s, **ps, **ps2;
  Volume *vol;
  int i,j,start,end;

  // Create unique surfaces

  start = Tree_Nbr(m->Surfaces);

  All = Tree2List(m->Surfaces);
  allNonDulpicatedSurfaces = Tree_Create(sizeof(Curve*),compareTwoSurfaces);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&s);
    if(s->Num > 0){
      if(!Tree_Search(allNonDulpicatedSurfaces,&s)){
        Tree_Insert(allNonDulpicatedSurfaces,&s);
      }
      else{
        Tree_Suppress(m->Surfaces,&s);
      }
    }
  }
  List_Delete(All);

  end = Tree_Nbr(m->Surfaces);

  if(start == end){
    Tree_Delete(allNonDulpicatedSurfaces);
    return;
  }

  Msg(DEBUG, "Removed %d duplicate surfaces", start-end);

  if(CTX.geom.old_newreg){
    m->MaxSurfaceNum=0;
    Tree_Action(m->Surfaces,MaxNumSurface);
  }

  // Replace old surfaces in volumes

  All = Tree2List(m->Volumes);
  for(i=0;i<List_Nbr(All);i++){
    List_Read(All,i,&vol);
    for(j=0;j<List_Nbr(vol->Surfaces);j++){
      ps = (Surface**)List_Pointer(vol->Surfaces,j);
      if(!(ps2 = (Surface**)Tree_PQuery(allNonDulpicatedSurfaces,ps)))
	Msg(GERROR, "Weird surface %d in Coherence", (*ps)->Num);
      else
	List_Write(vol->Surfaces,j,ps2);
    }
  }
  List_Delete(All);

  Tree_Delete(allNonDulpicatedSurfaces);
}

void ReplaceAllDuplicates(Mesh *m){
  ReplaceDuplicatePoints(m);
  ReplaceDuplicateCurves(m);
  ReplaceDuplicateSurfaces(m);
}


// Inetersection routines
// FIXME: this code is full of crap :-)

/*
  S = (sx(u,v),sy(u,v),sz(u,v))
  C = (cx(w),cy(w),cz(w))

  sx - cx = 0
  sy - cy = 0
  sz - cz = 0
  
  3eqs 3incs
*/

static Curve *CURVE, *CURVE_2;
static Surface *SURFACE;
static Vertex *VERTEX;

double min1d (double (*funct)(double), double *xmin){
  double ax=1.e-15, bx=1.e-12, xx, fa, fb, fx, tol = 1.e-8;
  mnbrak(&ax,&xx,&bx,&fa,&fx,&fb,funct);
  return(brent(ax,xx,bx,funct,tol,xmin));
}

static void intersectCS (int N, double x[], double res[]){
  //x[1] = u x[2] = v x[3] = w
  Vertex s,c;
  s = InterpolateSurface(SURFACE,x[1],x[2],0,0);
  c = InterpolateCurve (CURVE,x[3],0);
  res[1] = s.Pos.X - c.Pos.X;
  res[2] = s.Pos.Y - c.Pos.Y;
  res[3] = s.Pos.Z - c.Pos.Z;
}

static void intersectCC (int N, double x[], double res[]){
  //x[1] = u x[2] = v
  Vertex c2,c;
  c2 = InterpolateCurve(CURVE_2,x[2],0);
  c = InterpolateCurve (CURVE,x[1],0);
  res[1] = c2.Pos.X - c.Pos.X;
  res[2] = c2.Pos.Y - c.Pos.Y;
}

static void projectPS (int N, double x[], double res[]){
  //x[1] = u x[2] = v
  Vertex du,dv,c;
  c  = InterpolateSurface(SURFACE,x[1],x[2],0,0);
  du = InterpolateSurface(SURFACE,x[1],x[2],1,1);
  dv = InterpolateSurface(SURFACE,x[1],x[2],1,2);
  res[1] =
    (c.Pos.X - VERTEX->Pos.X)*du.Pos.X +
    (c.Pos.Y - VERTEX->Pos.Y)*du.Pos.Y +
    (c.Pos.Z - VERTEX->Pos.Z)*du.Pos.Z;
  res[2] = 
    (c.Pos.X - VERTEX->Pos.X)*dv.Pos.X +
    (c.Pos.Y - VERTEX->Pos.Y)*dv.Pos.Y +
    (c.Pos.Z - VERTEX->Pos.Z)*dv.Pos.Z;
}

static double projectPC (double u){
  //x[1] = u x[2] = v
  if(u<CURVE->ubeg)u = CURVE->ubeg;
  if(u<CURVE->ubeg)u = CURVE->ubeg;
  Vertex c;
  c = InterpolateCurve(CURVE,u,0);
  return sqrt(DSQR(c.Pos.X -VERTEX->Pos.X)+
	      DSQR(c.Pos.Y -VERTEX->Pos.Y)+
	      DSQR(c.Pos.Z -VERTEX->Pos.Z));
}

static int UFIXED=0;
static double FIX;
static double projectPCS (double u){
  //x[1] = u x[2] = v
  double tmin,tmax;
  if(UFIXED){
    tmin = SURFACE->kv[0];
    tmax = SURFACE->kv[SURFACE->Nv+SURFACE->OrderV];
  }
  else{
    tmin = SURFACE->ku[0];
    tmax = SURFACE->ku[SURFACE->Nu+SURFACE->OrderU];
  }
  
  if(u<tmin)u = tmin;
  if(u>tmax)u = tmax;
  Vertex c;
  if(UFIXED)
    c = InterpolateSurface(SURFACE,FIX,u,0,0);
  else
    c = InterpolateSurface(SURFACE,u,FIX,0,0);
  return sqrt(DSQR(c.Pos.X -VERTEX->Pos.X)+
              DSQR(c.Pos.Y -VERTEX->Pos.Y)+
              DSQR(c.Pos.Z -VERTEX->Pos.Z));
}

bool ProjectPointOnCurve (Curve *c, Vertex *v, Vertex *RES, Vertex *DER){
  double xmin;
  CURVE = c;
  VERTEX = v;
  min1d (projectPC, &xmin);
  *RES = InterpolateCurve(CURVE,xmin,0);
  *DER = InterpolateCurve(CURVE,xmin,1);
  if(xmin > c->uend){
    *RES = InterpolateCurve(CURVE,c->uend,0);
    *DER = InterpolateCurve(CURVE,c->uend,1);
  }
  else if(xmin < c->ubeg){
    *RES = InterpolateCurve(CURVE,c->ubeg,0);
    *DER = InterpolateCurve(CURVE,c->ubeg,1);
  }
  return true;
}

bool search_in_boundary (Surface *s, Vertex *p, double t, int Fixu, 
			 double *uu, double *vv){
  double l,umin,vmin,lmin = 1.e24;
  int i,N;
  Vertex vr;
  double tmin, tmax,u,v;
  
  if(Fixu){
    tmin = s->kv[0];
    tmax = s->kv[s->Nv+s->OrderV];
    N = 3*s->Nu;
  }
  else{
    tmin = s->ku[0];
    tmax = s->ku[s->Nu+s->OrderU];
    N = 3*s->Nv;
  }
  for(i=0;i<N;i++){
    if(Fixu){
      u = t;
      v = tmin + (tmax-tmin)*(double)(i)/(double)(N-1);
    }
    else {
      v = t;
      u = tmin + (tmax-tmin)*(double)(i)/(double)(N-1);
    }
    vr = InterpolateSurface(SURFACE,u,v,0,0);
    l =  sqrt(DSQR(vr.Pos.X - p->Pos.X) +  
              DSQR(vr.Pos.Y - p->Pos.Y) +
              DSQR(vr.Pos.Z - p->Pos.Z));
    if(l<lmin){
      lmin = l;
      umin = u;
      vmin = v;
    }
  }

  FIX = t;
  UFIXED = Fixu;
  double xm;
  if(Fixu)xm = vmin;
  else xm = umin;
  if(lmin > 1.e-3) min1d (projectPCS, &xm);
  if(Fixu){
    *uu = t;
    *vv = xm;
  }
  else{
    *vv = t;
    *uu = xm;
  }
  vr = InterpolateSurface(SURFACE,*uu,*vv,0,0);
  l =  sqrt(DSQR(vr.Pos.X - p->Pos.X) +
            DSQR(vr.Pos.Y - p->Pos.Y) +
            DSQR(vr.Pos.Z - p->Pos.Z));
  if(l<1.e-3)return true;
  return false;
}

bool try_a_value(Surface *s, Vertex *p, double u, double v,double *uu, double *vv){
  Vertex vr = InterpolateSurface(s,u,v,0,0);
  double l =  sqrt(DSQR(vr.Pos.X - p->Pos.X) +  
                   DSQR(vr.Pos.Y - p->Pos.Y) + 
                   DSQR(vr.Pos.Z - p->Pos.Z));
  *uu = u;*vv=v;
  if(l<1.e-3)return true;
  return false;
}

bool ProjectPointOnSurface (Surface *s, Vertex &p){
  double x[3] = {0.5,0.5,0.5};
  Vertex vv;
  int check;
  SURFACE = s;
  VERTEX = &p;
  double UMIN = 0.;
  double UMAX = 1.;
  double VMIN = 0.;
  double VMAX = 1.;
  while(1){
    newt(x,2,&check,projectPS);
    vv = InterpolateSurface(s,x[1],x[2],0,0);
    if(x[1] >= UMIN && x[1] <= UMAX && x[2] >=VMIN && x[2] <= VMAX) break;
    x[1] = UMIN + (UMAX-UMIN)*((rand() % 10000)/10000.);
    x[2] = VMIN + (VMAX-VMIN)*((rand() % 10000)/10000.);
  }
  p.Pos.X = vv.Pos.X;
  p.Pos.Y = vv.Pos.Y;
  p.Pos.Z = vv.Pos.Z;
  if(!check){
    return false;
  }
  return true;
}

bool ProjectPointOnSurface (Surface *s, Vertex *p,double *u, double *v){
  static double x[3];
  int check;
  static int deb = 1;
  double VMIN,VMAX,UMIN,UMAX,l, lmin;
  Vertex vv;

  SURFACE = s;
  VERTEX = p;
  lmin = 1.e24;
  UMAX = s->ku[s->Nu + s->OrderU];
  UMIN = s->ku[0];
  VMAX = s->kv[s->Nv + s->OrderV];
  VMIN = s->kv[0];
  if(deb){
    x[1] = UMIN + (UMAX-UMIN)*((rand() % 10000)/10000.);
    x[2] = VMIN + (VMAX-VMIN)*((rand() % 10000)/10000.);
    deb = 0;
  }

  if(p->Num == 160){
    lmin += 1.e90;
    if(p->Num == 133)UMAX = s->ku[s->Nu + s->OrderU];
  }
  
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[0]+VERTEX->u,
                 SURFACE->kv[0],u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[0]+VERTEX->u,
                 SURFACE->kv[SURFACE->Nv+SURFACE->OrderV],u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[SURFACE->Nu+SURFACE->OrderU]-VERTEX->u,
                 SURFACE->kv[0],u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[SURFACE->Nu+SURFACE->OrderU]-VERTEX->u,
                 SURFACE->kv[SURFACE->Nv+SURFACE->OrderV],u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[0],SURFACE->kv[0]+VERTEX->u,u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[0],
                 SURFACE->kv[SURFACE->Nv+SURFACE->OrderV]-VERTEX->u,u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[SURFACE->Nu+SURFACE->OrderU],
                 SURFACE->kv[0]+VERTEX->u,u,v))
    return true;
  if(try_a_value(SURFACE,VERTEX,SURFACE->ku[SURFACE->Nu+SURFACE->OrderU],
                 SURFACE->kv[SURFACE->Nv+SURFACE->OrderV]-VERTEX->u,u,v))
    return true;
 
  
  if(search_in_boundary(SURFACE,VERTEX,SURFACE->kv[0],0,u,v))
    return true;
  if(search_in_boundary(SURFACE,VERTEX,SURFACE->kv[SURFACE->Nv+SURFACE->OrderV],0,u,v))
    return true;
  if(search_in_boundary(SURFACE,VERTEX,SURFACE->ku[0],1,u,v))
    return true;
  if(search_in_boundary(SURFACE,VERTEX,SURFACE->ku[SURFACE->Nu+SURFACE->OrderU],1,u,v))
    return true;
  
  while(1){
    newt(x,2,&check,projectPS);
    vv = InterpolateSurface(s,x[1],x[2],0,0);
    l =  sqrt(DSQR(vv.Pos.X - p->Pos.X) +
              DSQR(vv.Pos.Y - p->Pos.Y) +
              DSQR(vv.Pos.Z - p->Pos.Z));
    if(l < 1.e-1) break;
    else {
      x[1] = UMIN + (UMAX-UMIN)*((rand() % 10000)/10000.);
      x[2] = VMIN + (VMAX-VMIN)*((rand() % 10000)/10000.);
    }
  }
  *u = x[1];
  *v = x[2];
  
  if(!check){
    return false;
  }
  return true;
}

bool IntersectCurveSurface (Curve *c, Surface *s){
  double x[4];
  int check;
  SURFACE = s;
  CURVE = c;
  newt(x,3,&check,intersectCS);
  if(!check)return false;
  return true;
}


void DivideCurve (Curve *c , double u, Vertex *v, Curve **c1, Curve **c2){
  (*c1) = Create_Curve(NEWLINE(),c->Typ,1,NULL,NULL,-1,-1,0.,1.);
  (*c2) = Create_Curve(NEWLINE(),c->Typ,1,NULL,NULL,-1,-1,0.,1.);
  CopyCurve(c,*c1);
  CopyCurve(c,*c2);
  (*c1)->uend = u;
  (*c2)->ubeg = u;
  (*c1)->end = v;
  (*c2)->beg = v;
}

bool IntersectCurves (Curve *c1, Curve *c2,
                      Curve **c11, Curve **c12,
                      Curve **c21, Curve **c22, Vertex **v){
  double x[3];
  Vertex v1,v2;
  int check;
  
  if(!compareVertex(&c1->beg,&c2->beg))return false;
  if(!compareVertex(&c1->end,&c2->end))return false;
  if(!compareVertex(&c1->beg,&c2->end))return false;
  if(!compareVertex(&c2->beg,&c1->end))return false;

  CURVE_2 = c2;
  CURVE = c1;
  x[1] = x[2] =  0.0;
  newt(x,2,&check,intersectCC);
  if(check) return false;
  v1 = InterpolateCurve(c1,x[1],0);
  v2 = InterpolateCurve(c2,x[2],0);
  //  Msg(INFO, "success : %lf %lf,%lf,%lf\n",v1.Pos.X,v1.Pos.Y,x[1],x[2]);
  if(x[1] <= c1->ubeg) return false;
  if(x[1] >= c1->uend) return false;
  if(x[2] <= c2->ubeg) return false;
  if(x[2] >= c2->uend) return false;
  if(fabs(v1.Pos.Z - v2.Pos.Z) > 1.e-08 * CTX.lc) return false;
  *v = Create_Vertex(NEWPOINT(), v1.Pos.X,v1.Pos.Y,v1.Pos.Z,v1.lc,x[1]);
  Tree_Insert(THEM->Points,v);
  DivideCurve(c1,x[1],*v,c11,c12);
  DivideCurve(c2,x[2],*v,c21,c22);
  return true;
}

bool IntersectAllSegmentsTogether (void) {
  bool intersectionfound = true;
  List_T *TempList;
  Curve *c1,*c2,*c11,*c12,*c21,*c22;
  Vertex *v;
  int i,j;

  while(intersectionfound){
    TempList = Tree2List(THEM->Curves);
    if(!List_Nbr(TempList))return true;
    for(i=0;i<List_Nbr(TempList);i++){
      List_Read(TempList,i,&c1);
      intersectionfound = false;
      for(j=0;j<List_Nbr(TempList);j++){
        List_Read(TempList,j,&c2);
        if(c1->Num > 0 && c2->Num >0 && i!=j && intersectionfound == false){
          if(IntersectCurves(c1,c2,&c11,&c12,&c21,&c22,&v)){
            Msg(INFO, "Intersection Curve %d->%d",c1->Num,c2->Num);
            intersectionfound = true;
            DeleteCurve(c1->Num);
            DeleteCurve(c2->Num);
            Tree_Add(THEM->Curves,&c11);
            Tree_Add(THEM->Curves,&c12);
            Tree_Add(THEM->Curves,&c21);
            Tree_Add(THEM->Curves,&c22);
            
            CreateReversedCurve(THEM,c11);
            CreateReversedCurve(THEM,c12);
            CreateReversedCurve(THEM,c21);
            CreateReversedCurve(THEM,c22);
            return true;
          }
        }
      }
      if(intersectionfound) break;
    }
    List_Delete(TempList);
  }
  return false;

}

void IntersectSurfaces (Surface *s1, Surface *s2){

}
