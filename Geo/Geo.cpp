// $Id: Geo.cpp,v 1.67 2006-12-20 15:50:57 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "GeoUtils.h"
#include "GeoInterpolation.h"
#include "Context.h"

extern Mesh *THEM;
extern Context_T CTX;

static List_T *ListOfTransformedPoints = NULL;

void Mesh::alloc_all()
{
  MaxPointNum = MaxLineNum = MaxLineLoopNum = MaxSurfaceNum = 0;
  MaxSurfaceLoopNum = MaxVolumeNum = MaxPhysicalNum = 0;
  Points = Tree_Create(sizeof(Vertex *), compareVertex);
  Curves = Tree_Create(sizeof(Curve *), compareCurve);
  EdgeLoops = Tree_Create(sizeof(EdgeLoop *), compareEdgeLoop);
  Surfaces = Tree_Create(sizeof(Surface *), compareSurface);
  SurfaceLoops = Tree_Create(sizeof(SurfaceLoop *), compareSurfaceLoop);
  Volumes = Tree_Create(sizeof(Volume *), compareVolume);
  PhysicalGroups = List_Create(5, 5, sizeof(PhysicalGroup *));
}

void Mesh::free_all()
{
  MaxPointNum = MaxLineNum = MaxLineLoopNum = MaxSurfaceNum = 0;
  MaxSurfaceLoopNum = MaxVolumeNum = MaxPhysicalNum = 0;
  Tree_Action(THEM->Points, Free_Vertex); Tree_Delete(THEM->Points);
  Tree_Action(THEM->Curves, Free_Curve); Tree_Delete(THEM->Curves);
  Tree_Action(THEM->EdgeLoops, Free_EdgeLoop); Tree_Delete(THEM->EdgeLoops);
  Tree_Action(THEM->Surfaces, Free_Surface); Tree_Delete(THEM->Surfaces);
  Tree_Action(THEM->SurfaceLoops, Free_SurfaceLoop); Tree_Delete(THEM->SurfaceLoops);
  Tree_Action(THEM->Volumes, Free_Volume); Tree_Delete(THEM->Volumes);
  List_Action(THEM->PhysicalGroups, Free_PhysicalGroup); List_Delete(THEM->PhysicalGroups);
}

// Comparison routines

int compareVertex(const void *a, const void *b)
{
  int i, j;
  Vertex **q, **w;

  q = (Vertex **) a;
  w = (Vertex **) b;
  i = abs((*q)->Num);
  j = abs((*w)->Num);
  return (i - j);
}

int comparePosition(const void *a, const void *b)
{
  int i, j;
  Vertex **q, **w;
  // TOLERANCE ! WARNING WARNING
  double eps = 1.e-6 * CTX.lc; 
  // the above tol was changed in 1.61 (before 1.61, it was set to
  // double eps = 1.e-10 * CTX.lc;

  q = (Vertex **) a;
  w = (Vertex **) b;
  i = ((*q)->Num);
  j = ((*w)->Num);

  if((*q)->Pos.X - (*w)->Pos.X > eps)
    return (1);
  if((*q)->Pos.X - (*w)->Pos.X < -eps)
    return (-1);
  if((*q)->Pos.Y - (*w)->Pos.Y > eps)
    return (1);
  if((*q)->Pos.Y - (*w)->Pos.Y < -eps)
    return (-1);
  if((*q)->Pos.Z - (*w)->Pos.Z > eps)
    return (1);
  if((*q)->Pos.Z - (*w)->Pos.Z < -eps)
    return (-1);

  if(i != j) {
    /*
     *w = *q;
     printf("Les points %d et %d sont a la meme position\n",i,j);
     printf("%12.5E %12.5E %12.5E\n",(*w)->Pos.X,(*w)->Pos.Y,(*w)->Pos.Z);
     printf("%12.5E %12.5E %12.5E\n",(*q)->Pos.X,(*q)->Pos.Y,(*q)->Pos.Z);
     */
  }
  return 0;

}

int compareSurfaceLoop(const void *a, const void *b)
{
  SurfaceLoop **q, **w;

  q = (SurfaceLoop **) a;
  w = (SurfaceLoop **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareEdgeLoop(const void *a, const void *b)
{
  EdgeLoop **q, **w;

  q = (EdgeLoop **) a;
  w = (EdgeLoop **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareCurve(const void *a, const void *b)
{
  Curve **q, **w;

  q = (Curve **) a;
  w = (Curve **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareSurface(const void *a, const void *b)
{
  Surface **q, **w;

  q = (Surface **) a;
  w = (Surface **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareVolume(const void *a, const void *b)
{
  Volume **q, **w;

  q = (Volume **) a;
  w = (Volume **) b;
  return ((*q)->Num - (*w)->Num);
}

int comparePhysicalGroup(const void *a, const void *b)
{
  PhysicalGroup *q, *w;
  int cmp;

  q = *(PhysicalGroup **) a;
  w = *(PhysicalGroup **) b;
  cmp = q->Typ - w->Typ;

  if(cmp)
    return cmp;
  else
    return (q->Num - w->Num);
}

// Basic entity creation/deletion functions

Vertex *Create_Vertex(int Num, double X, double Y, double Z, double lc,
                      double u)
{
  Vertex *pV;

  pV = new Vertex(X, Y, Z, lc);
  pV->w = 1.0;
  pV->Num = Num;
  THEM->MaxPointNum = IMAX(THEM->MaxPointNum, Num);
  pV->u = u;
  return pV;
}

void Free_Vertex(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  if(v) {
    delete v;
    v = NULL;
  }
}

PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T * intlist)
{
  PhysicalGroup *p = (PhysicalGroup *) Malloc(sizeof(PhysicalGroup));
  p->Entities = List_Create(List_Nbr(intlist), 1, sizeof(int));
  p->Num = Num;
  THEM->MaxPhysicalNum = IMAX(THEM->MaxPhysicalNum, Num);
  p->Typ = typ;
  p->Visible = 1;
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(p->Entities, &j);
  }
  return p;
}

void Free_PhysicalGroup(void *a, void *b)
{
  PhysicalGroup *p = *(PhysicalGroup **) a;
  if(p) {
    List_Delete(p->Entities);
    Free(p);
    p = NULL;
  }
}

EdgeLoop *Create_EdgeLoop(int Num, List_T * intlist)
{
  EdgeLoop *l = (EdgeLoop *) Malloc(sizeof(EdgeLoop));
  l->Curves = List_Create(List_Nbr(intlist), 1, sizeof(int));
  l->Num = Num;
  THEM->MaxLineLoopNum = IMAX(THEM->MaxLineLoopNum, Num);
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(l->Curves, &j);
  }
  return l;
}

void Free_EdgeLoop(void *a, void *b)
{
  EdgeLoop *l = *(EdgeLoop **) a;
  if(l) {
    List_Delete(l->Curves);
    Free(l);
    l = NULL;
  }
}

SurfaceLoop *Create_SurfaceLoop(int Num, List_T * intlist)
{
  SurfaceLoop *l = (SurfaceLoop *) Malloc(sizeof(SurfaceLoop));
  l->Surfaces = List_Create(List_Nbr(intlist), 1, sizeof(int));
  l->Num = Num;
  THEM->MaxSurfaceLoopNum = IMAX(THEM->MaxSurfaceLoopNum, Num);
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(l->Surfaces, &j);
  }
  return l;
}

void Free_SurfaceLoop(void *a, void *b)
{
  SurfaceLoop *l = *(SurfaceLoop **) a;
  if(l) {
    List_Delete(l->Surfaces);
    Free(l);
    l = NULL;
  }
}

void End_Curve(Curve * c)
{
  double R2, mat[3][3], R, A3, A1, A4;
  Vertex *v[4], v0, v2, v3;
  double f1, f2, dir32[3], dir12[3], n[3], m[3], dir42[3];
  double rhs[2], sys[2][2], sol[2];
  int i;
  Curve *Curve;

  if(c->Typ == MSH_SEGM_CIRC || c->Typ == MSH_SEGM_CIRC_INV ||
     c->Typ == MSH_SEGM_ELLI || c->Typ == MSH_SEGM_ELLI_INV) {

    Curve = c;

    // v[0] = first point
    // v[1] = center
    // v[2] = last point
    // v[3] = major axis point

    if(List_Nbr(Curve->Control_Points) == 4)
      List_Read(Curve->Control_Points, 2, &v[3]);
    else
      v[3] = NULL;

    if(Curve->Typ == MSH_SEGM_CIRC_INV || Curve->Typ == MSH_SEGM_ELLI_INV) {
      List_Read(Curve->Control_Points, 0, &v[2]);
      List_Read(Curve->Control_Points, 1, &v[1]);
      if(!v[3])
        List_Read(Curve->Control_Points, 2, &v[0]);
      else
        List_Read(Curve->Control_Points, 3, &v[0]);
    }
    else {
      List_Read(Curve->Control_Points, 0, &v[0]);
      List_Read(Curve->Control_Points, 1, &v[1]);
      if(!v[3])
        List_Read(Curve->Control_Points, 2, &v[2]);
      else
        List_Read(Curve->Control_Points, 3, &v[2]);
    }

    direction(v[1], v[0], dir12);
    direction(v[1], v[2], dir32);
    if(v[3])
      direction(v[1], v[3], dir42);

    // v0 = vector center->first pt
    // v2 = vector center->last pt
    // v3 = vector center->major axis pt

    v0.Pos.X = dir12[0];
    v0.Pos.Y = dir12[1];
    v0.Pos.Z = dir12[2];
    v2.Pos.X = dir32[0];
    v2.Pos.Y = dir32[1];
    v2.Pos.Z = dir32[2];
    if(v[3]) {
      v3.Pos.X = dir42[0];
      v3.Pos.Y = dir42[1];
      v3.Pos.Z = dir42[2];
    }

    norme(dir12);
    norme(dir32);
    prodve(dir12, dir32, n);
    norme(n);
    // use provided plane if unable to compute it from input points...
    if(fabs(n[0]) < 1.e-5 && fabs(n[1]) < 1.e-5 && fabs(n[2]) < 1.e-5) {
      n[0] = Curve->Circle.n[0];
      n[1] = Curve->Circle.n[1];
      n[2] = Curve->Circle.n[2];
      norme(n);
    }
    prodve(n, dir12, m);
    norme(m);

    mat[2][0] = Curve->Circle.invmat[0][2] = n[0];
    mat[2][1] = Curve->Circle.invmat[1][2] = n[1];
    mat[2][2] = Curve->Circle.invmat[2][2] = n[2];
    mat[1][0] = Curve->Circle.invmat[0][1] = m[0];
    mat[1][1] = Curve->Circle.invmat[1][1] = m[1];
    mat[1][2] = Curve->Circle.invmat[2][1] = m[2];
    mat[0][0] = Curve->Circle.invmat[0][0] = dir12[0];
    mat[0][1] = Curve->Circle.invmat[1][0] = dir12[1];
    mat[0][2] = Curve->Circle.invmat[2][0] = dir12[2];

    // assume circle in z=0 plane
    if(CTX.geom.old_circle) {
      if(n[0] == 0.0 && n[1] == 0.0) {
        mat[2][0] = Curve->Circle.invmat[0][2] = 0;
        mat[2][1] = Curve->Circle.invmat[1][2] = 0;
        mat[2][2] = Curve->Circle.invmat[2][2] = 1;
        mat[1][0] = Curve->Circle.invmat[0][1] = 0;
        mat[1][1] = Curve->Circle.invmat[1][1] = 1;
        mat[1][2] = Curve->Circle.invmat[2][1] = 0;
        mat[0][0] = Curve->Circle.invmat[0][0] = 1;
        mat[0][1] = Curve->Circle.invmat[1][0] = 0;
        mat[0][2] = Curve->Circle.invmat[2][0] = 0;
      }
    }

    Projette(&v0, mat);
    Projette(&v2, mat);
    if(v[3])
      Projette(&v3, mat);

    R = sqrt(v0.Pos.X * v0.Pos.X + v0.Pos.Y * v0.Pos.Y);
    R2 = sqrt(v2.Pos.X * v2.Pos.X + v2.Pos.Y * v2.Pos.Y);

    if(!R || !R2)       // check radius
      Msg(GERROR, "Zero radius in Circle/Ellipse %d", c->Num);
    else if(!v[3] && fabs((R - R2) / (R + R2)) > 0.1)   // check cocircular pts (allow 10% error)
      Msg(GERROR, "Control points of Circle %d are not cocircular %g %g",
          c->Num, R, R2);

    // A1 = angle first pt
    // A3 = angle last pt
    // A4 = angle major axis

    if(v[3]) {
      A4 = myatan2(v3.Pos.Y, v3.Pos.X);
      A4 = angle_02pi(A4);
      double x1 = v0.Pos.X * cos(A4) + v0.Pos.Y * sin(A4);
      double y1 = -v0.Pos.X * sin(A4) + v0.Pos.Y * cos(A4);
      double x3 = v2.Pos.X * cos(A4) + v2.Pos.Y * sin(A4);
      double y3 = -v2.Pos.X * sin(A4) + v2.Pos.Y * cos(A4);
      sys[0][0] = x1 * x1;
      sys[0][1] = y1 * y1;
      sys[1][0] = x3 * x3;
      sys[1][1] = y3 * y3;
      rhs[0] = 1;
      rhs[1] = 1;
      sys2x2(sys, rhs, sol);
      if(sol[0] <= 0 || sol[1] <= 0) {
        Msg(GERROR, "Ellipse %d is wrong", Curve->Num);
        A1 = A3 = 0.;
        f1 = f2 = R;
      }
      else {
        f1 = sqrt(1. / sol[0]);
        f2 = sqrt(1. / sol[1]);
        // myasin() permet de contourner les problemes de precision
        // sur y1/f2 ou y3/f2, qui peuvent legerement etre hors de
        // [-1,1]
        if(x1 < 0)
          A1 = -myasin(y1 / f2) + A4 + Pi;
        else
          A1 = myasin(y1 / f2) + A4;
        if(x3 < 0)
          A3 = -myasin(y3 / f2) + A4 + Pi;
        else
          A3 = myasin(y3 / f2) + A4;
      }
    }
    else {
      A1 = myatan2(v0.Pos.Y, v0.Pos.X);
      A3 = myatan2(v2.Pos.Y, v2.Pos.X);
      A4 = 0.;
      f1 = f2 = R;
    }

    A1 = angle_02pi(A1);
    A3 = angle_02pi(A3);
    if(A1 >= A3)
      A3 += 2 * Pi;

    //printf("f1=%g f2=%g a1=%g a3=%g a4=%g\n", 
    //     f1, f2, A1*180./M_PI, A3*180./Pi, A4*180./Pi);

    Curve->Circle.t1 = A1;
    Curve->Circle.t2 = A3;
    Curve->Circle.incl = A4;
    Curve->Circle.f1 = f1;
    Curve->Circle.f2 = f2;

    for(i = 0; i < 4; i++)
      Curve->Circle.v[i] = v[i];

    if(!CTX.expert_mode && Curve->Num > 0 && A3-A1 >= Pi){
      Msg(GERROR1, "Circle or ellipse arc %d greater than/equal to Pi (angle=%g)",
	  Curve->Num, A3-A1);
      Msg(GERROR2, "(If you understand what this implies, you can disable this error");
      Msg(GERROR2, "message by selecting `Enable expert mode' in the option dialog.");
      Msg(GERROR3, "Otherwise, please subdivide the arc in smaller pieces.)");
    }

  }

  if(c->cp){
    Free(c->cp);
    c->cp = NULL;
  }

  if(List_Nbr(c->Control_Points)){
    c->cp = (float *)Malloc(4 * List_Nbr(c->Control_Points) * sizeof(float));
    for(i = 0; i < List_Nbr(c->Control_Points); i++) {
      List_Read(c->Control_Points, i, &v[0]);
      c->cp[4 * i] = v[0]->Pos.X;
      c->cp[4 * i + 1] = v[0]->Pos.Y;
      c->cp[4 * i + 2] = v[0]->Pos.Z;
      c->cp[4 * i + 3] = v[0]->w;
    }
  }
}

void End_Surface(Surface * s, int reset_orientations)
{
  int i;
  Vertex *v;
  
  if(reset_orientations) 
    List_Reset(s->Orientations);

  if(!s->Control_Points || !List_Nbr(s->Control_Points))
    return;

  s->cp = (float *)Malloc(4 * List_Nbr(s->Control_Points) * sizeof(float));
  for(i = 0; i < List_Nbr(s->Control_Points); i++) {
    List_Read(s->Control_Points, i, &v);
    s->cp[4 * i] = v->Pos.X;
    s->cp[4 * i + 1] = v->Pos.Y;
    s->cp[4 * i + 2] = v->Pos.Z;
    s->cp[4 * i + 3] = v->w;
  }

}


Curve *Create_Curve(int Num, int Typ, int Order, List_T * Liste,
                    List_T * Knots, int p1, int p2, double u1, double u2)
{
  double matcr[4][4] = { {-0.5, 1.5, -1.5, 0.5},
			 {1.0, -2.5, 2.0, -0.5},
			 {-0.5, 0.0, 0.5, 0.0},
			 {0.0, 1.0, 0.0, 0.0} };
  double matbs[4][4] = { {-1.0, 3, -3, 1},
			 {3, -6, 3.0, 0},
			 {-3, 0.0, 3, 0.0},
			 {1, 4, 1, 0.0} };
  double matbez[4][4] = { {-1.0, 3, -3, 1},
			  {3, -6, 3.0, 0},
			  {-3, 3.0, 0, 0.0},
			  {1, 0, 0, 0.0} };

  Curve *pC = (Curve *) Malloc(sizeof(Curve));
  pC->Color.type = 0;
  pC->Visible = 1;
  pC->cp = NULL;
  pC->Extrude = NULL;
  pC->Typ = Typ;
  pC->Num = Num;
  THEM->MaxLineNum = IMAX(THEM->MaxLineNum, Num);
  pC->Method = LIBRE;
  pC->degre = Order;
  pC->Circle.n[0] = 0.0;
  pC->Circle.n[1] = 0.0;
  pC->Circle.n[2] = 1.0;
  for(int i = 0; i < 4; i++) {
    pC->ipar[i] = 0;
    pC->dpar[i] = 0.0;
  }

  if(Typ == MSH_SEGM_SPLN) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        pC->mat[i][j] = matcr[i][j];
  }
  else if(Typ == MSH_SEGM_BSPLN) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        pC->mat[i][j] = matbs[i][j] / 6.0;
  }
  else if(Typ == MSH_SEGM_BEZIER) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        pC->mat[i][j] = matbez[i][j];
  }

  pC->ubeg = u1;
  pC->uend = u2;

  if(Knots) {
    pC->k = (float *)Malloc(List_Nbr(Knots) * sizeof(float));
    double kmin = .0, kmax = 1.;
    List_Read(Knots, 0, &kmin);
    List_Read(Knots, List_Nbr(Knots) - 1, &kmax);
    pC->ubeg = kmin;
    pC->uend = kmax;
    for(int i = 0; i < List_Nbr(Knots); i++) {
      double d;
      List_Read(Knots, i, &d);
      pC->k[i] = (float)d;
    }
  }
  else
    pC->k = NULL;

  if(Liste) {
    pC->Control_Points = List_Create(List_Nbr(Liste), 1, sizeof(Vertex *));
    for(int j = 0; j < List_Nbr(Liste); j++) {
      int iPnt;
      List_Read(Liste, j, &iPnt);
      Vertex *v;
      if((v = FindPoint(iPnt)))
        List_Add(pC->Control_Points, &v);
      else{
        Msg(GERROR, "Unknown control point %d in Curve %d", iPnt, pC->Num);
      }
    }
  }
  else {
    pC->Control_Points = NULL;
    pC->beg = NULL;
    pC->end = NULL;
    return pC;
  }

  if(p1 < 0) {
    List_Read(pC->Control_Points, 0, &pC->beg);
    List_Read(pC->Control_Points, List_Nbr(pC->Control_Points) - 1, &pC->end);
  }
  else {
    Vertex *v;
    if((v = FindPoint(p1))) {
      Msg(INFO, "Curve %d first control point %d ", pC->Num, v->Num);
      pC->beg = v;
    }
    else {
      Msg(GERROR, "Unknown control point %d in Curve %d", p1, pC->Num);
    }
    if((v = FindPoint(p2))) {
      Msg(INFO, "Curve %d first control point %d ", pC->Num, v->Num);
      pC->end = v;
    }
    else {
      Msg(GERROR, "Unknown control point %d in Curve %d", p2, pC->Num);
    }
  }

  End_Curve(pC);

  return pC;
}

void Free_Curve(void *a, void *b)
{
  Curve *pC = *(Curve **) a;
  if(pC) {
    Free(pC->k);
    List_Delete(pC->Control_Points);
    Free(pC->cp);
    Free(pC);
    pC = NULL;
  }
}

Surface *Create_Surface(int Num, int Typ)
{
  Surface *pS = (Surface *) Malloc(sizeof(Surface));
  pS->Color.type = 0;
  pS->Visible = 1;
  pS->Num = Num;
  THEM->MaxSurfaceNum = IMAX(THEM->MaxSurfaceNum, Num);
  pS->Typ = Typ;
  pS->Method = LIBRE;
  for(int i = 0; i < 5; i++)
    pS->ipar[i] = 0;
  pS->Recombine = 0;
  pS->Recombine_Dir = -1;
  pS->RecombineAngle = 75;
  pS->TrsfPoints = List_Create(4, 4, sizeof(Vertex *));
  pS->Contours = List_Create(1, 1, sizeof(List_T *));
  pS->Orientations = List_Create(20, 2, sizeof(Vertex));
  pS->Support = pS;
  pS->Control_Points = List_Create(1, 10, sizeof(Vertex *));
  pS->Generatrices = NULL;
  pS->EmbeddedPoints = NULL;
  pS->EmbeddedCurves = NULL;
  pS->Extrude = NULL;
  return (pS);
}

void CreateNurbsSurfaceSupport(int Num, int Order1, int Order2,
                               List_T * List, List_T * ku, List_T * kv)
{
  // This routine has been heavily modified to fit the new interfaces,
  // but has not been tested since then. It's probably full of bugs
  // now.
  List_T *ListOfDouble_L;
  List_T *ListCP = List_Create(2, 2, sizeof(int));

  for(int j = 0; j < List_Nbr(List); j++) {
    List_Read(List, j, &ListOfDouble_L);
    for(int i = 0; i < List_Nbr(ListOfDouble_L); i++) {
      double d;
      List_Read(ListOfDouble_L, i, &d);
      int N = (int)d;
      List_Add(ListCP, &N);
    }
  }
  List_Read(List, 0, &ListOfDouble_L);
  int Nu = List_Nbr(List);
  int Nv = List_Nbr(ListOfDouble_L);

  Surface *s = Create_Surface(Num, MSH_SURF_NURBS);
  s->Support = NULL;
  s->Control_Points = List_Create(4, 1, sizeof(Vertex *));
  s->OrderU = Order1;
  s->OrderV = Order2;
  s->Nu = Nu;
  s->Nv = Nv;
  for(int i = 0; i < List_Nbr(ListCP); i++) {
    int j;
    List_Read(ListCP, i, &j);
    Vertex *v = FindPoint(j);
    if(v){
      List_Add(s->Control_Points, &v);
    }
    else{
      Msg(GERROR, "Unknown control point %d in nurbs surface", j);
    }
  }

  s->ku = (float *)malloc(List_Nbr(ku) * sizeof(float));
  s->kv = (float *)malloc(List_Nbr(kv) * sizeof(float));

  double kumin = 0., kumax = 1.;
  double kvmin = 0., kvmax = 1.;

  for(int i = 0; i < List_Nbr(ku); i++) {
    double d;
    List_Read(ku, i, &d);
    float f = (float)((d - kumin) / (kumax - kumin));
    s->ku[i] = f;
  }
  for(int i = 0; i < List_Nbr(kv); i++) {
    double d;
    List_Read(kv, i, &d);
    float f = (float)((d - kvmin) / (kvmax - kvmin));
    s->kv[i] = f;
  }

  List_Delete(ListCP);

  End_Surface(s);
  Tree_Add(THEM->Surfaces, &s);
}

void CreateNurbsSurface(int Num, int Order1, int Order2, List_T * List,
                        List_T * ku, List_T * kv)
{
  // This routine has been heavily modified to fit the new interfaces,
  // but has not been tested since then. It's probably full of bugs
  // now.

  List_T *ListOfDouble_L, *Listint, *ListCP;
  int Loop[4];

  ListCP = List_Create(2, 2, sizeof(int));

  double kumin, kumax;
  List_Read(ku, 0, &kumin);
  List_Read(ku, List_Nbr(ku) - 1, &kumax);
  double kvmin, kvmax;
  List_Read(kv, 0, &kvmin);
  List_Read(kv, List_Nbr(kv) - 1, &kvmax);
  for(int j = 0; j < List_Nbr(List); j++) {
    List_Read(List, j, &ListOfDouble_L);
    for(int i = 0; i < List_Nbr(ListOfDouble_L); i++) {
      double d;
      List_Read(ListOfDouble_L, i, &d);
      int N = (int)d;
      List_Add(ListCP, &N);
    }
  }

  // 1st and 3rd gen
  List_Read(List, 0, &ListOfDouble_L);
  Listint = ListOfDouble2ListOfInt(ListOfDouble_L);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[0])) {
  }
  else {
    Loop[0] = NEWREG();
    Curve *c = Create_Curve(Loop[0], MSH_SEGM_NURBS, Order1, Listint, NULL, 
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(c);
    c->k = (float *)malloc(4 * List_Nbr(ku) * sizeof(float));
    for(int i = 0; i < List_Nbr(ku); i++) {
      double d;
      List_Read(ku, i, &d);
      c->k[i] = (float)d /*((d-kumin)/(kumax-kumin)) */ ;
    }
  }
  List_Delete(Listint);

  List_Read(List, List_Nbr(List) - 1, &ListOfDouble_L);
  Listint = ListOfDouble2ListOfInt(ListOfDouble_L);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[2])) {
  }
  else {
    Loop[2] = NEWREG();
    Curve *c = Create_Curve(Loop[2], MSH_SEGM_NURBS, Order1, Listint, NULL, 
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(c);
    c->k = (float *)malloc(4 * List_Nbr(ku) * sizeof(float));
    for(int i = 0; i < List_Nbr(ku); i++) {
      double d;
      List_Read(ku, i, &d);
      c->k[i] = (float)d /*((d-kumin)/(kumax-kumin)) */ ;
    }
  }
  List_Delete(Listint);

  // 2nd and 4th gen
  List_T *List1 = List_Create(List_Nbr(List), 1, sizeof(double));
  List_T *List2 = List_Create(List_Nbr(List), 1, sizeof(double));
  for(int i = 0; i < List_Nbr(List); i++) {
    List_Read(List, i, &ListOfDouble_L);
    List_Add(List1, List_Pointer(ListOfDouble_L, 0));
    List_Add(List2, List_Pointer(ListOfDouble_L, List_Nbr(ListOfDouble_L) - 1));
  }

  Listint = ListOfDouble2ListOfInt(List1);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[1])) {
  }
  else {
    Loop[1] = NEWREG();
    Curve *c = Create_Curve(Loop[1], MSH_SEGM_NURBS, Order2, Listint, NULL, 
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(c);
    c->k = (float *)malloc(4 * List_Nbr(kv) * sizeof(float));
    for(int i = 0; i < List_Nbr(kv); i++) {
      double d;
      List_Read(kv, i, &d);
      c->k[i] = (float)d /*((d-kvmin)/(kvmax-kvmin)) */ ;
    }
  }
  List_Delete(Listint);

  Listint = ListOfDouble2ListOfInt(List2);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[3])) {
  }
  else {
    Loop[3] = NEWREG();
    Curve *c = Create_Curve(Loop[3], MSH_SEGM_NURBS, Order2, Listint, NULL,
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(c);
    c->k = (float *)malloc(4 * List_Nbr(kv) * sizeof(float));
    for(int i = 0; i < List_Nbr(kv); i++) {
      double d;
      List_Read(kv, i, &d);
      c->k[i] = (float)d /*((d-kvmin)/(kvmax-kvmin)) */ ;
    }
  }
  List_Delete(Listint);
  List_Delete(List1);
  List_Delete(List2);

  Listint = List_Create(10, 10, sizeof(int));
  int l0 = -Loop[0];
  List_Add(Listint, &l0);
  List_Add(Listint, &Loop[1]);
  List_Add(Listint, &Loop[2]);
  int l3 = -Loop[3];
  List_Add(Listint, &l3);

  int topnew = NEWREG();
  CreateNurbsSurfaceSupport(topnew, Order1, Order2, List, ku, kv);

  int il = NEWREG();
  SurfaceLoop *l = Create_SurfaceLoop(il, Listint);
  Tree_Add(THEM->SurfaceLoops, &l);
  List_Reset(Listint);
  List_Add(Listint, &il);

  Surface *s = Create_Surface(NEWREG(), MSH_SURF_TRIMMED);
  setSurfaceGeneratrices(s, Listint);
  s->Support = s;
  End_Surface(s);
  Tree_Add(THEM->Surfaces, &s);

  List_Delete(Listint);
  List_Delete(ListCP);
}

void Free_Surface(void *a, void *b)
{
  Surface *pS = *(Surface **) a;
  if(pS) {
    List_Delete(pS->TrsfPoints);
    List_Delete(pS->Contours);
    List_Delete(pS->Orientations);
    List_Delete(pS->Control_Points);
    List_Delete(pS->Generatrices);
    List_Delete(pS->EmbeddedCurves);
    List_Delete(pS->EmbeddedPoints);
    Free(pS);
    pS = NULL;
  }
}

Volume *Create_Volume(int Num, int Typ)
{
  Volume *pV = (Volume *) Malloc(sizeof(Volume));
  pV->Color.type = 0;
  pV->Visible = 1;
  pV->Num = Num;
  THEM->MaxVolumeNum = IMAX(THEM->MaxVolumeNum, Num);
  pV->Typ = Typ;
  pV->Method = LIBRE;
  for(int i = 0; i < 8; i++)
    pV->ipar[i] = 0;
  pV->TrsfPoints = List_Create(6, 6, sizeof(Vertex *));
  pV->Surfaces = List_Create(1, 2, sizeof(Surface *));
  pV->SurfacesOrientations = List_Create(1, 2, sizeof(int));
  pV->Extrude = NULL;
  return pV;
}

void Free_Volume(void *a, void *b)
{
  Free_Volume_But_Not_Elements(a, b);
}

void Free_Volume_But_Not_Elements(void *a, void *b)
{
  Volume *pV = *(Volume **) a;
  if(pV) {
    List_Delete(pV->TrsfPoints);
    List_Delete(pV->Surfaces);
    List_Delete(pV->SurfacesOrientations);
    Free(pV);
    pV = NULL;
  }
}

int NEWPOINT(void)
{
  return (THEM->MaxPointNum + 1);
}

int NEWLINE(void)
{
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxLineNum + 1);
}

int NEWLINELOOP(void)
{
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxLineLoopNum + 1);
}

int NEWSURFACE(void)
{
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxSurfaceNum + 1);
}

int NEWSURFACELOOP(void)
{
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxSurfaceLoopNum + 1);
}

int NEWVOLUME(void)
{
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxVolumeNum + 1);
}

int NEWPHYSICAL(void)
{
  if(CTX.geom.old_newreg)
    return NEWREG();
  else
    return (THEM->MaxPhysicalNum + 1);
}

int NEWREG(void)
{
  return (IMAX(THEM->MaxLineNum,
               IMAX(THEM->MaxLineLoopNum,
                    IMAX(THEM->MaxSurfaceNum,
                         IMAX(THEM->MaxSurfaceLoopNum,
                              IMAX(THEM->MaxVolumeNum,
                                   THEM->MaxPhysicalNum)))))
          + 1);
}




int compare2Lists(List_T * List1, List_T * List2,
                  int (*fcmp) (const void *a, const void *b))
{
  int i, found;

  if(!List_Nbr(List1) && !List_Nbr(List2))
    return 0;

  if(!List_Nbr(List1) || !List_Nbr(List2) || 
     (List_Nbr(List1) != List_Nbr(List2)))
    return List_Nbr(List1) - List_Nbr(List2);
  
  List_T *List1Prime = List_Create(List_Nbr(List1), 1, List1->size);
  List_T *List2Prime = List_Create(List_Nbr(List2), 1, List2->size);
  List_Copy(List1, List1Prime);
  List_Copy(List2, List2Prime);
  List_Sort(List1Prime, fcmp);
  List_Sort(List2Prime, fcmp);

  for(i = 0; i < List_Nbr(List1Prime); i++) {
    found = fcmp(List_Pointer(List1Prime, i), List_Pointer(List2Prime, i));
    if(found != 0) {
      List_Delete(List1Prime);
      List_Delete(List2Prime);
      return found;
    }
  }
  List_Delete(List1Prime);
  List_Delete(List2Prime);
  return 0;
}

Vertex *FindPoint(int inum)
{
  Vertex C, *pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(THEM->Points, &pc)) {
    return pc;
  }
  return NULL;
}

Curve *FindCurve(int inum)
{
  Curve C, *pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(THEM->Curves, &pc)) {
    return pc;
  }
  return NULL;
}

Surface *FindSurface(int inum)
{
  Surface S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(THEM->Surfaces, &ps)) {
    return ps;
  }
  return NULL;
}

Volume *FindVolume(int inum)
{
  Volume V, *pv;
  pv = &V;
  pv->Num = inum;
  if(Tree_Query(THEM->Volumes, &pv)) {
    return pv;
  }
  return NULL;
}

EdgeLoop *FindEdgeLoop(int inum)
{
  EdgeLoop S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(THEM->EdgeLoops, &ps)) {
    return ps;
  }
  return NULL;
}

SurfaceLoop *FindSurfaceLoop(int inum)
{
  SurfaceLoop S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(THEM->SurfaceLoops, &ps)) {
    return ps;
  }
  return NULL;
}

PhysicalGroup *FindPhysicalGroup(int num, int type)
{
  PhysicalGroup P, *pp, **ppp;
  pp = &P;
  pp->Num = num;
  pp->Typ = type;
  if((ppp = (PhysicalGroup **) List_PQuery(THEM->PhysicalGroups, &pp,
                                           comparePhysicalGroup))) {
    return *ppp;
  }
  return NULL;
}

void CopyVertex(Vertex * v, Vertex * vv)
{
  vv->lc = v->lc;
  vv->u = v->u;
  vv->Pos.X = v->Pos.X;
  vv->Pos.Y = v->Pos.Y;
  vv->Pos.Z = v->Pos.Z;
}

Vertex *DuplicateVertex(Vertex * v)
{
  if(!v) return NULL;
  Vertex *pv = Create_Vertex(NEWPOINT(), 0, 0, 0, 0, 0);
  CopyVertex(v, pv);
  Tree_Insert(THEM->Points, &pv);
  return pv;
}

int compareAbsCurve(const void *a, const void *b)
{
  Curve **q, **w;

  q = (Curve **) a;
  w = (Curve **) b;
  return (abs((*q)->Num) - abs((*w)->Num));
}

void CopyCurve(Curve * c, Curve * cc)
{
  int i, j;
  cc->Typ = c->Typ;
  // We should not copy the meshing method : if the meshes are to be
  // copied, the meshing algorithm will take care of it
  // (e.g. ExtrudeMesh()).
  //cc->Method = c->Method; 
  for(i = 0; i < 4; i++)
    cc->ipar[i] = c->ipar[i];
  for(i = 0; i < 4; i++)
    cc->dpar[i] = c->dpar[i];
  cc->l = c->l;
  for(i = 0; i < 4; i++)
    for(j = 0; j < 4; j++)
      cc->mat[i][j] = c->mat[i][j];
  cc->beg = c->beg;
  cc->end = c->end;
  cc->ubeg = c->ubeg;
  cc->uend = c->uend;
  cc->Control_Points =
    List_Create(List_Nbr(c->Control_Points), 1, sizeof(Vertex *));
  List_Copy(c->Control_Points, cc->Control_Points);
  if(c->Typ == MSH_SEGM_PARAMETRIC){
    strcpy(cc->functu, c->functu);
    strcpy(cc->functv, c->functv);
    strcpy(cc->functw, c->functw);
  }
  End_Curve(cc);
  Tree_Insert(THEM->Curves, &cc);
}

Curve *DuplicateCurve(Curve * c)
{
  Curve *pc;
  Vertex *v, *newv;
  pc = Create_Curve(NEWLINE(), 0, 1, NULL, NULL, -1, -1, 0., 1.);
  CopyCurve(c, pc);
  for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
    List_Read(pc->Control_Points, i, &v);
    newv = DuplicateVertex(v);
    List_Write(pc->Control_Points, i, &newv);
  }
  pc->beg = DuplicateVertex(c->beg);
  pc->end = DuplicateVertex(c->end);
  CreateReversedCurve(pc);

  return pc;
}

void CopySurface(Surface * s, Surface * ss)
{
  int i, j;
  ss->Typ = s->Typ;
  // We should not copy the meshing method (or the recombination
  // status): if the meshes are to be copied, the meshing algorithm
  // will take care of it (e.g. ExtrudeMesh()).
  //ss->Method = s->Method;
  //ss->Recombine = s->Recombine;
  //ss->RecombineAngle = s->RecombineAngle;
  for(i = 0; i < 4; i++)
    ss->ipar[i] = s->ipar[i];
  ss->Nu = s->Nu;
  ss->Nv = s->Nv;
  ss->a = s->a;
  ss->b = s->b;
  ss->c = s->c;
  ss->d = s->d;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      ss->plan[i][j] = s->plan[i][j];
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      ss->invplan[i][j] = s->invplan[i][j];
  ss->Generatrices =
    List_Create(List_Nbr(s->Generatrices), 1, sizeof(Curve *));
  List_Copy(s->Generatrices, ss->Generatrices);
  if(s->Control_Points) {
    ss->Control_Points =
      List_Create(List_Nbr(s->Control_Points), 1, sizeof(Vertex *));
    List_Copy(s->Control_Points, ss->Control_Points);
  }
  End_Surface(ss);
  Tree_Insert(THEM->Surfaces, &ss);
}

Surface *DuplicateSurface(Surface * s)
{
  Surface *ps;
  Curve *c, *newc;
  Vertex *v, *newv;
  int i;

  ps = Create_Surface(NEWSURFACE(), 0);
  CopySurface(s, ps);
  for(i = 0; i < List_Nbr(ps->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c);
    newc = DuplicateCurve(c);
    List_Write(ps->Generatrices, i, &newc);
  }

  for(i = 0; i < List_Nbr(ps->Control_Points); i++) {
    List_Read(ps->Control_Points, i, &v);
    newv = DuplicateVertex(v);
    List_Write(ps->Control_Points, i, &newv);
  }

  return ps;
}

void CopyShape(int Type, int Num, int *New)
{
  Surface *s, *news;
  Curve *c, *newc;
  Vertex *v, *newv;

  switch (Type) {
  case MSH_POINT:
    if(!(v = FindPoint(Num))) {
      Msg(GERROR, "Unknown vertex %d", Num);
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
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_PARAMETRIC:
    if(!(c = FindCurve(Num))) {
      Msg(GERROR, "Unknown curve %d", Num);
      return;
    }
    newc = DuplicateCurve(c);
    *New = newc->Num;
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
    if(!(s = FindSurface(Num))) {
      Msg(GERROR, "Unknown surface %d", Num);
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

void DeletePoint(int ip)
{
  Vertex *v = FindPoint(ip);
  if(!v)
    return;
  List_T *Curves = Tree2List(THEM->Curves);
  for(int i = 0; i < List_Nbr(Curves); i++) {
    Curve *c;
    List_Read(Curves, i, &c);
    for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
      if(!compareVertex(List_Pointer(c->Control_Points, j), &v)){
	List_Delete(Curves);
        return;
      }
    }
  }
  List_Delete(Curves);
  if(v->Num == THEM->MaxPointNum)
    THEM->MaxPointNum--;
  Tree_Suppress(THEM->Points, &v);
  Free_Vertex(&v, NULL);
}

void DeleteCurve(int ip)
{
  Curve *c = FindCurve(ip);
  if(!c)
    return;
  List_T *Surfs = Tree2List(THEM->Surfaces);
  for(int i = 0; i < List_Nbr(Surfs); i++) {
    Surface *s;
    List_Read(Surfs, i, &s);
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      if(!compareAbsCurve(List_Pointer(s->Generatrices, j), &c)){
	List_Delete(Surfs);
        return;
      }
    }
  }
  List_Delete(Surfs);
  if(c->Num == THEM->MaxLineNum)
    THEM->MaxLineNum--;
  Tree_Suppress(THEM->Curves, &c);
  Free_Curve(&c, NULL);
}

void DeleteSurface(int is)
{
  Surface *s = FindSurface(is);
  if(!s)
    return;
  List_T *Vols = Tree2List(THEM->Volumes);
  for(int i = 0; i < List_Nbr(Vols); i++) {
    Volume *v;
    List_Read(Vols, i, &v);
    for(int j = 0; j < List_Nbr(v->Surfaces); j++) {
      if(!compareSurface(List_Pointer(v->Surfaces, j), &s)){
	List_Delete(Vols);
        return;
      }
    }
  }
  List_Delete(Vols);
  if(s->Num == THEM->MaxSurfaceNum)
    THEM->MaxSurfaceNum--;
  Tree_Suppress(THEM->Surfaces, &s);
  Free_Surface(&s, NULL);
}

void DeleteVolume(int iv)
{
  Volume *v = FindVolume(iv);
  if(!v)
    return;
  if(v->Num == THEM->MaxVolumeNum)
    THEM->MaxVolumeNum--;
  Tree_Suppress(THEM->Volumes, &v);
  Free_Volume(&v, NULL);
}

void DeleteShape(int Type, int Num)
{
  switch (Type) {
  case MSH_POINT:
    DeletePoint(Num);
    break;
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_PARAMETRIC:
    DeleteCurve(Num);
    DeleteCurve(-Num);
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
    DeleteSurface(Num);
    break;
  case MSH_VOLUME:
    DeleteVolume(Num);
    break;
  default:
    Msg(GERROR, "Impossible to delete entity %d (of type %d)", Num, Type);
    break;
  }
}

void ColorCurve(int ip, unsigned int col)
{
  Curve *c = FindCurve(ip);
  if(!c)
    return;
  c->Color.type = 1;
  c->Color.mesh = c->Color.geom = col;
}

void ColorSurface(int is, unsigned int col)
{
  Surface *s = FindSurface(is);
  if(!s)
    return;
  s->Color.type = 1;
  s->Color.mesh = s->Color.geom = col;
}

void ColorVolume(int iv, unsigned int col)
{
  Volume *v = FindVolume(iv);
  if(!v)
    return;
  v->Color.type = 1;
  v->Color.mesh = v->Color.geom = col;
}

void ColorShape(int Type, int Num, unsigned int Color)
{
  switch (Type) {
  case MSH_POINT:
    break;
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_PARAMETRIC:
  case MSH_SEGM_DISCRETE:
    ColorCurve(Num, Color);
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_DISCRETE:
    ColorSurface(Num, Color);
    break;
  case MSH_VOLUME:
  case MSH_VOLUME_DISCRETE:
    ColorVolume(Num, Color);
    break;
  default:
    break;
  }
}

void VisibilityShape(int Type, int Num, int Mode)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  Volume *V;

  switch (Type) {
  case MSH_POINT:
    if((v = FindPoint(Num)))
      v->Visible = Mode;
    else
      Msg(WARNING, "Unknown point %d (use '*' to hide/show all points)", Num);
    break;
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_PARAMETRIC:
  case MSH_SEGM_DISCRETE:
    if((c = FindCurve(Num)))
      c->Visible = Mode;
    else
      Msg(WARNING, "Unknown line %d (use '*' to hide/show all lines)", Num);
    break;
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_DISCRETE:
    if((s = FindSurface(Num)))
      s->Visible = Mode;
    else
      Msg(WARNING, "Unknown surface %d (use '*' to hide/show all surfaces)", Num);
    break;
  case MSH_VOLUME:
  case MSH_VOLUME_DISCRETE:
    if((V = FindVolume(Num)))
      V->Visible = Mode;
    else
      Msg(WARNING, "Unknown volume %d (use '*' to hide/show all volumes)", Num);
    break;
  default:
    break;
  }
}

static int vmode;
static void vis_nod(void *a, void *b){ (*(Vertex **) a)->Visible = vmode; }
static void vis_cur(void *a, void *b){ (*(Curve **) a)->Visible = vmode; }
static void vis_sur(void *a, void *b){ (*(Surface **) a)->Visible = vmode; }
static void vis_vol(void *a, void *b){ (*(Volume **) a)->Visible = vmode; }

void VisibilityShape(char *str, int Type, int Mode)
{
  vmode = Mode;

  if(!strcmp(str, "all") || !strcmp(str, "*")) {
    switch (Type) {
    case 0: Tree_Action(THEM->Points, vis_nod); break;
    case 1: Tree_Action(THEM->Curves, vis_cur); break;
    case 2: Tree_Action(THEM->Surfaces, vis_sur); break;
    case 3: Tree_Action(THEM->Volumes, vis_vol); break;
    }
  }
  else {
    VisibilityShape(Type, atoi(str), Mode);
  }
}

Curve *CreateReversedCurve(Curve * c)
{
  Curve *newc;
  Vertex *e1, *e2, *e3, *e4;
  int i;
  newc = Create_Curve(-c->Num, c->Typ, 1, NULL, NULL, -1, -1, 0., 1.);

  if(List_Nbr(c->Control_Points)){
    newc->Control_Points =
      List_Create(List_Nbr(c->Control_Points), 1, sizeof(Vertex *));
    if(c->Typ == MSH_SEGM_ELLI || c->Typ == MSH_SEGM_ELLI_INV) {
      List_Read(c->Control_Points, 0, &e1);
      List_Read(c->Control_Points, 1, &e2);
      List_Read(c->Control_Points, 2, &e3);
      List_Read(c->Control_Points, 3, &e4);
      List_Add(newc->Control_Points, &e4);
      List_Add(newc->Control_Points, &e2);
      List_Add(newc->Control_Points, &e3);
      List_Add(newc->Control_Points, &e1);
    }
    else
      List_Invert(c->Control_Points, newc->Control_Points);
  }

  if(c->Typ == MSH_SEGM_NURBS && c->k) {
    newc->k =
      (float *)malloc((c->degre + List_Nbr(c->Control_Points) + 1) *
                      sizeof(float));
    for(i = 0; i < c->degre + List_Nbr(c->Control_Points) + 1; i++)
      newc->k[c->degre + List_Nbr(c->Control_Points) - i] = c->k[i];
  }

  if(c->Typ == MSH_SEGM_CIRC)
    newc->Typ = MSH_SEGM_CIRC_INV;
  if(c->Typ == MSH_SEGM_CIRC_INV)
    newc->Typ = MSH_SEGM_CIRC;
  if(c->Typ == MSH_SEGM_ELLI)
    newc->Typ = MSH_SEGM_ELLI_INV;
  if(c->Typ == MSH_SEGM_ELLI_INV)
    newc->Typ = MSH_SEGM_ELLI;


  newc->beg = c->end;
  newc->end = c->beg;
  newc->Method = c->Method;
  newc->degre = c->degre;
  newc->ubeg = 1. - c->uend;
  newc->uend = 1. - c->ubeg;
  End_Curve(newc);


  Curve **pc;

  if((pc = (Curve **) Tree_PQuery(THEM->Curves, &newc))) {
    Free_Curve(&newc, NULL);
    return *pc;
  }
  else{
    Tree_Add(THEM->Curves, &newc);
    return newc;
  }
}

void ModifyLcPoint(int ip, double lc)
{
  Vertex *v = FindPoint(ip);
  if(v)
    v->lc = lc;
}

int recognize_seg(int typ, List_T * liste, int *seg)
{
  int i, beg, end;
  Curve *pc;

  List_T *temp = Tree2List(THEM->Curves);
  List_Read(liste, 0, &beg);
  List_Read(liste, List_Nbr(liste) - 1, &end);
  for(i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &pc);
    if(pc->Typ == typ && pc->beg->Num == beg && pc->end->Num == end) {
      List_Delete(temp);
      *seg = pc->Num;
      return 1;
    }
  }
  List_Delete(temp);
  return 0;
}

int recognize_loop(List_T * liste, int *loop)
{
  int i, res;
  EdgeLoop *pe;

  res = 0;
  *loop = 0;
  List_T *temp = Tree2List(THEM->EdgeLoops);
  for(i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &pe);
    if(!compare2Lists(pe->Curves, liste, fcmp_absint)) {
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

int recognize_surfloop(List_T * liste, int *loop)
{
  int i, res;
  EdgeLoop *pe;

  res = 0;
  *loop = 0;
  List_T *temp = Tree2List(THEM->SurfaceLoops);
  for(i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &pe);
    if(!compare2Lists(pe->Curves, liste, fcmp_absint)) {
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

// Linear applications

void SetTranslationMatrix(double matrix[4][4], double T[3])
{
  int i, j;

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      matrix[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }
  for(i = 0; i < 3; i++)
    matrix[i][3] = T[i];
}

void SetSymmetryMatrix(double matrix[4][4], double A, double B, double C,
                       double D)
{
  double F = -2.0 / (A * A + B * B + C * C);
  matrix[0][0] = 1. + A * A * F;
  matrix[0][1] = A * B * F;
  matrix[0][2] = A * C * F;
  matrix[0][3] = A * D * F;
  matrix[1][0] = A * B * F;
  matrix[1][1] = 1. + B * B * F;
  matrix[1][2] = B * C * F;
  matrix[1][3] = B * D * F;
  matrix[2][0] = A * C * F;
  matrix[2][1] = B * C * F;
  matrix[2][2] = 1. + C * C * F;
  matrix[2][3] = C * D * F;
  matrix[3][0] = B * C * F;
  matrix[3][1] = 0.0;
  matrix[3][2] = 0.0;
  matrix[3][3] = 1.0;
}

void SetDilatationMatrix(double matrix[4][4], double T[3], double A)
{
  matrix[0][0] = A;
  matrix[0][1] = 0.0;
  matrix[0][2] = 0.0;
  matrix[0][3] = T[0] * (1.0 - A);
  matrix[1][0] = 0.0;
  matrix[1][1] = A;
  matrix[1][2] = 0.0;
  matrix[1][3] = T[1] * (1.0 - A);
  matrix[2][0] = 0.0;
  matrix[2][1] = 0.0;
  matrix[2][2] = A;
  matrix[2][3] = T[2] * (1.0 - A);
  matrix[3][0] = 0.0;
  matrix[3][1] = 0.0;
  matrix[3][2] = 0.0;
  matrix[3][3] = 1.0;
}

static void GramSchmidt(double v1[3], double v2[3], double v3[3])
{
  double tmp[3];
  norme(v1);
  prodve(v3, v1, tmp);
  norme(tmp);
  v2[0] = tmp[0];
  v2[1] = tmp[1];
  v2[2] = tmp[2];
  prodve(v1, v2, v3);
  norme(v3);
}

void SetRotationMatrix(double matrix[4][4], double Axe[3], double alpha)
{
  double t1[3], t2[3];
  if(Axe[0] != 0.0) {
    t1[0] = 0.0;
    t1[1] = 1.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 0.0;
    t2[2] = 1.0;
  }
  else if(Axe[1] != 0.0) {
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
  GramSchmidt(Axe, t1, t2);
  double rot[3][3], plan[3][3], invplan[3][3];
  plan[0][0] = Axe[0];
  plan[0][1] = Axe[1];
  plan[0][2] = Axe[2];
  plan[1][0] = t1[0];
  plan[1][1] = t1[1];
  plan[1][2] = t1[2];
  plan[2][0] = t2[0];
  plan[2][1] = t2[1];
  plan[2][2] = t2[2];
  rot[2][2] = cos(alpha);
  rot[2][1] = sin(alpha);
  rot[2][0] = 0.;
  rot[1][2] = -sin(alpha);
  rot[1][1] = cos(alpha);
  rot[1][0] = 0.;
  rot[0][2] = 0.;
  rot[0][1] = 0.;
  rot[0][0] = 1.;
  int i, j, k;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      invplan[i][j] = plan[j][i];
  double interm[3][3];
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      interm[i][j] = 0.0;
      for(k = 0; k < 3; k++)
        interm[i][j] += invplan[i][k] * rot[k][j];
    }
  for(i = 0; i < 4; i++)
    for(j = 0; j < 4; j++)
      matrix[i][j] = 0.0;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      for(k = 0; k < 3; k++)
        matrix[i][j] += interm[i][k] * plan[k][j];
    }
  matrix[3][3] = 1.0;
}

static void vecmat4x4(double mat[4][4], double vec[4], double res[4])
{
  int i, j;
  for(i = 0; i < 4; i++) {
    res[i] = 0.0;
    for(j = 0; j < 4; j++) {
      res[i] += mat[i][j] * vec[j];
    }
  }
}

void printCurve(Curve * c)
{
  Vertex *v;
  int N = List_Nbr(c->Control_Points);
  Msg(DEBUG, "Curve %d %d cp (%d->%d)", c->Num, N, c->beg->Num, c->end->Num);
  for(int i = 0; i < N; i++) {
    List_Read(c->Control_Points, i, &v);
    Msg(DEBUG, "Vertex %d (%g,%g,%g,%g)", v->Num, v->Pos.X, v->Pos.Y,
        v->Pos.Z, v->lc);
  }
}

void printSurface(Surface * s)
{
  Curve *c;
  int N = List_Nbr(s->Generatrices);

  Msg(DEBUG, "Surface %d, %d generatrices", s->Num, N);
  for(int i = 0; i < N; i++) {
    List_Read(s->Generatrices, i, &c);
    printCurve(c);
  }
}

void ApplyTransformationToPoint(double matrix[4][4], Vertex * v,
				bool end_curve_surface=false)
{
  double pos[4], vec[4];

  if(!ListOfTransformedPoints)
    ListOfTransformedPoints = List_Create(50, 50, sizeof(int));

  if(!List_Search(ListOfTransformedPoints, &v->Num, fcmp_absint)) {
    List_Add(ListOfTransformedPoints, &v->Num);
  }
  else
    return;

  vec[0] = v->Pos.X;
  vec[1] = v->Pos.Y;
  vec[2] = v->Pos.Z;
  vec[3] = v->w;
  vecmat4x4(matrix, vec, pos);
  v->Pos.X = pos[0];
  v->Pos.Y = pos[1];
  v->Pos.Z = pos[2];
  v->w = pos[3];

  // Warning: in theory we should always redo these checks if
  // end_curve_surface is true; but in practice this is so slow for
  // big models that we need to provide a way to bypass it (which is
  // OK if the guy who builds the geometry knowns what he's
  // doing). Instead of adding one more option, let's just bypass all
  // the checks if auto_coherence==0...
  if(CTX.geom.auto_coherence && end_curve_surface){
    List_T *All = Tree2List(THEM->Curves);
    for(int i = 0; i < List_Nbr(All); i++) {
      Curve *c;
      List_Read(All, i, &c);
      for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
	Vertex *pv = *(Vertex **) List_Pointer(c->Control_Points, j);
	if(pv->Num == v->Num){
	  End_Curve(c);
	  break;
	}
      }
    }
    List_Delete(All);
    All = Tree2List(THEM->Surfaces);
    for(int i = 0; i < List_Nbr(All); i++) {
      Surface *s;
      List_Read(All, i, &s);
      for(int j = 0; j < List_Nbr(s->Control_Points); j++) {
	Vertex *pv = *(Vertex **) List_Pointer(s->Control_Points, j);
	if(pv->Num == v->Num){
	  End_Surface(s);
	  break;
	}
      }
    }
    List_Delete(All);
  }
}

void ApplyTransformationToCurve(double matrix[4][4], Curve * c)
{
  Vertex *v;

  if(!c->beg || !c->end){
    Msg(GERROR, "Cannot transform curve with no begin/end points");
    return;
  }

  ApplyTransformationToPoint(matrix, c->beg);
  ApplyTransformationToPoint(matrix, c->end);

  for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
    List_Read(c->Control_Points, i, &v);
    ApplyTransformationToPoint(matrix, v);
  }
  End_Curve(c);
}

void ApplyTransformationToSurface(double matrix[4][4], Surface * s)
{
  Curve *c;
  Vertex *v;
  int i;

  for(i = 0; i < List_Nbr(s->Generatrices); i++) {
    List_Read(s->Generatrices, i, &c);
    // FIXME: this fixes benchmarks/bug/transfo_neg_curves.geo, but is
    // it the correct fix?
    //ApplyTransformationToCurve(matrix, c);
    Curve *cc = FindCurve(abs(c->Num));
    ApplyTransformationToCurve(matrix, cc);
  }
  for(i = 0; i < List_Nbr(s->Control_Points); i++) {
    List_Read(s->Control_Points, i, &v);
    ApplyTransformationToPoint(matrix, v);
  }
  End_Surface(s);
}

void ApplicationOnShapes(double matrix[4][4], List_T * ListShapes)
{
  int i;
  Shape O;
  Vertex *v;
  Curve *c;
  Surface *s;

  List_Reset(ListOfTransformedPoints);

  for(i = 0; i < List_Nbr(ListShapes); i++) {
    List_Read(ListShapes, i, &O);
    switch (O.Type) {
    case MSH_POINT:
      v = FindPoint(O.Num);
      if(v)
        ApplyTransformationToPoint(matrix, v, true);
      else
        Msg(GERROR, "Unknown point %d", O.Num);
      break;
    case MSH_SEGM_LINE:
    case MSH_SEGM_SPLN:
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
    case MSH_SEGM_CIRC:
    case MSH_SEGM_CIRC_INV:
    case MSH_SEGM_ELLI:
    case MSH_SEGM_ELLI_INV:
    case MSH_SEGM_NURBS:
    case MSH_SEGM_PARAMETRIC:
      c = FindCurve(O.Num);
      if(c)
        ApplyTransformationToCurve(matrix, c);
      else
        Msg(GERROR, "Unknown curve %d", O.Num);
      break;
    case MSH_SURF_NURBS:
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_PLAN:
      s = FindSurface(O.Num);
      if(s)
        ApplyTransformationToSurface(matrix, s);
      else
        Msg(GERROR, "Unknown surface %d", O.Num);
      break;
    default:
      Msg(GERROR, "Impossible to transform entity %d (of type %d)", O.Num,
          O.Type);
      break;
    }
  }

  List_Reset(ListOfTransformedPoints);
}

void TranslateShapes(double X, double Y, double Z,
                     List_T * ListShapes, int final)
{
  double T[3], matrix[4][4];

  T[0] = X;
  T[1] = Y;
  T[2] = Z;
  SetTranslationMatrix(matrix, T);
  ApplicationOnShapes(matrix, ListShapes);

  if(CTX.geom.auto_coherence && final)
    ReplaceAllDuplicates();
}

void DilatShapes(double X, double Y, double Z, double A,
                 List_T * ListShapes, int final)
{
  double T[3], matrix[4][4];

  T[0] = X;
  T[1] = Y;
  T[2] = Z;
  SetDilatationMatrix(matrix, T, A);
  ApplicationOnShapes(matrix, ListShapes);

  if(CTX.geom.auto_coherence && final)
    ReplaceAllDuplicates();
}

void RotateShapes(double Ax, double Ay, double Az,
                  double Px, double Py, double Pz,
                  double alpha, List_T * ListShapes, int final)
{
  double A[3], T[3], matrix[4][4];

  T[0] = -Px;
  T[1] = -Py;
  T[2] = -Pz;
  SetTranslationMatrix(matrix, T);
  ApplicationOnShapes(matrix, ListShapes);

  A[0] = Ax;
  A[1] = Ay;
  A[2] = Az;
  SetRotationMatrix(matrix, A, alpha);
  ApplicationOnShapes(matrix, ListShapes);

  T[0] = Px;
  T[1] = Py;
  T[2] = Pz;
  SetTranslationMatrix(matrix, T);
  ApplicationOnShapes(matrix, ListShapes);

  if(CTX.geom.auto_coherence && final)
    ReplaceAllDuplicates();
}

void SymmetryShapes(double A, double B, double C,
                    double D, List_T * ListShapes, int final)
{
  double matrix[4][4];

  SetSymmetryMatrix(matrix, A, B, C, D);
  ApplicationOnShapes(matrix, ListShapes);

  if(CTX.geom.auto_coherence && final)
    ReplaceAllDuplicates();
}


// Extrusion routines

void ProtudeXYZ(double &x, double &y, double &z, ExtrudeParams * e)
{
  double matrix[4][4];
  double T[3];
  Vertex v(x, y, z);

  T[0] = -e->geo.pt[0];
  T[1] = -e->geo.pt[1];
  T[2] = -e->geo.pt[2];
  SetTranslationMatrix(matrix, T);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix, &v);

  SetRotationMatrix(matrix, e->geo.axe, e->geo.angle);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix, &v);

  T[0] = -T[0];
  T[1] = -T[1];
  T[2] = -T[2];
  SetTranslationMatrix(matrix, T);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix, &v);

  x = v.Pos.X;
  y = v.Pos.Y;
  z = v.Pos.Z;

  List_Reset(ListOfTransformedPoints);
}

int Extrude_ProtudePoint(int type, int ip,
			 double T0, double T1, double T2,
			 double A0, double A1, double A2,
			 double X0, double X1, double X2, double alpha,
			 Curve ** pc, Curve ** prc, int final, 
			 ExtrudeParams * e)
{
  double matrix[4][4], T[3], Ax[3], d;
  Vertex V, *pv, *newp, *chapeau;
  Curve *c;
  int i;

  pv = &V;
  pv->Num = ip;
  *pc = *prc = NULL;
  if(!Tree_Query(THEM->Points, &pv))
    return 0;

  Msg(DEBUG, "Extrude Point %d", ip);

  chapeau = DuplicateVertex(pv);

  switch (type) {

  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);

    if(!comparePosition(&pv, &chapeau))
      return pv->Num;
    c = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e)
      c->Extrude->mesh = e->mesh;

    List_Add(c->Control_Points, &pv);
    List_Add(c->Control_Points, &chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;

  case ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);

    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);

    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);

    if(!comparePosition(&pv, &chapeau))
      return pv->Num;
    c = Create_Curve(NEWLINE(), MSH_SEGM_CIRC, 1, NULL, NULL, -1, -1, 0., 1.);
    c->Control_Points = List_Create(3, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e)
      c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    // compute circle center
    newp = DuplicateVertex(pv);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    norme(Ax);
    T[0] = pv->Pos.X - X0;
    T[1] = pv->Pos.Y - X1;
    T[2] = pv->Pos.Z - X2;
    prosca(T, Ax, &d);
    newp->Pos.X = X0 + d * Ax[0];
    newp->Pos.Y = X1 + d * Ax[1]; 
    newp->Pos.Z = X2 + d * Ax[2]; 
    List_Add(c->Control_Points, &newp);
    List_Add(c->Control_Points, &chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;

  case TRANSLATE_ROTATE:
    d = CTX.geom.extrude_spline_points;
    d = d ? d : 1;
    c = Create_Curve(NEWLINE(), MSH_SEGM_SPLN, 1, NULL, NULL, -1, -1, 0., 1.);
    c->Control_Points =
      List_Create(CTX.geom.extrude_spline_points + 1, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e)
      c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    c->beg = pv;
    for(i = 0; i < CTX.geom.extrude_spline_points; i++) {
      if(i)
        chapeau = DuplicateVertex(chapeau);

      T[0] = -X0;
      T[1] = -X1;
      T[2] = -X2;
      SetTranslationMatrix(matrix, T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);

      Ax[0] = A0;
      Ax[1] = A1;
      Ax[2] = A2;
      SetRotationMatrix(matrix, Ax, alpha / d);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);

      T[0] = X0;
      T[1] = X1;
      T[2] = X2;
      SetTranslationMatrix(matrix, T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);

      T[0] = T0 / d;
      T[1] = T1 / d;
      T[2] = T2 / d;
      SetTranslationMatrix(matrix, T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);

      List_Add(c->Control_Points, &chapeau);
    }
    c->end = chapeau;
    break;

  default:
    Msg(GERROR, "Unknown extrusion type");
    return pv->Num;
  }

  End_Curve(c);
  Tree_Add(THEM->Curves, &c);
  CreateReversedCurve(c);
  *pc = c;
  *prc = FindCurve(-c->Num);

  List_Reset(ListOfTransformedPoints);

  if(CTX.geom.auto_coherence && final)
    ReplaceAllDuplicates();

  return chapeau->Num;
}

int Extrude_ProtudeCurve(int type, int ic,
			 double T0, double T1, double T2,
			 double A0, double A1, double A2,
			 double X0, double X1, double X2, double alpha,
			 Surface ** ps, int final, 
			 ExtrudeParams * e)
{
  double matrix[4][4], T[3], Ax[3];
  Curve *CurveBeg, *CurveEnd;
  Curve *ReverseChapeau, *ReverseBeg, *ReverseEnd;
  Curve *pc, *revpc, *chapeau;
  Surface *s;

  pc = FindCurve(ic);
  revpc = FindCurve(-ic);
  *ps = NULL;

  if(!pc || !revpc){
    return 0;
  }

  if(!pc->beg || !pc->end){
    Msg(GERROR, "Cannot extrude curve with no begin/end points");
    return 0;
  }

  Msg(DEBUG, "Extrude Curve %d", ic);

  chapeau = DuplicateCurve(pc);

  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  chapeau->Extrude->geo.Source = pc->Num;
  if(e)
    chapeau->Extrude->mesh = e->mesh;

  switch (type) {
  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    break;
  case ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);

    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);

    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    break;
  case TRANSLATE_ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);

    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);

    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);

    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    break;
  default:
    Msg(GERROR, "Unknown extrusion type");
    return pc->Num;
  }

  Extrude_ProtudePoint(type, pc->beg->Num, T0, T1, T2,
                       A0, A1, A2, X0, X1, X2, alpha,
                       &CurveBeg, &ReverseBeg, 0, e);
  Extrude_ProtudePoint(type, pc->end->Num, T0, T1, T2,
                       A0, A1, A2, X0, X1, X2, alpha,
                       &CurveEnd, &ReverseEnd, 0, e);

  if(!CurveBeg && !CurveEnd){
    return pc->Num;
  }

  if(!CurveBeg || !CurveEnd)
    s = Create_Surface(NEWSURFACE(), MSH_SURF_TRIC);
  else
    s = Create_Surface(NEWSURFACE(), MSH_SURF_REGL);

  s->Generatrices = List_Create(4, 1, sizeof(Curve *));
  s->Extrude = new ExtrudeParams;
  s->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  s->Extrude->geo.Source = pc->Num;
  if(e)
    s->Extrude->mesh = e->mesh;

  ReverseChapeau = FindCurve(-chapeau->Num);

  if(!CurveBeg) {
    List_Add(s->Generatrices, &pc);
    List_Add(s->Generatrices, &CurveEnd);
    List_Add(s->Generatrices, &ReverseChapeau);
  }
  else if(!CurveEnd) {
    List_Add(s->Generatrices, &ReverseChapeau);
    List_Add(s->Generatrices, &ReverseBeg);
    List_Add(s->Generatrices, &pc);
  }
  else {
    List_Add(s->Generatrices, &pc);
    List_Add(s->Generatrices, &CurveEnd);
    List_Add(s->Generatrices, &ReverseChapeau);
    List_Add(s->Generatrices, &ReverseBeg);
  }

  End_Surface(s);
  Tree_Add(THEM->Surfaces, &s);

  List_Reset(ListOfTransformedPoints);

  *ps = s;

  if(CTX.geom.auto_coherence && final)
    ReplaceAllDuplicates();

  return chapeau->Num;
}

int Extrude_ProtudeSurface(int type, int is,
			   double T0, double T1, double T2,
			   double A0, double A1, double A2,
			   double X0, double X1, double X2, double alpha,
			   Volume **pv, ExtrudeParams * e)
{
  double matrix[4][4], T[3], Ax[3];
  Curve *c, *c2;
  int i;
  Surface *s, *ps, *chapeau;

  *pv = NULL;

  if(!(ps = FindSurface(is)))
    return 0;

  Msg(DEBUG, "Extrude Surface %d", is);

  chapeau = DuplicateSurface(ps);

  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  chapeau->Extrude->geo.Source = ps->Num;
  if(e)
    chapeau->Extrude->mesh = e->mesh;

  for(i = 0; i < List_Nbr(chapeau->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c2);
    List_Read(chapeau->Generatrices, i, &c);
    if(c->Num < 0)
      if(!(c = FindCurve(-c->Num))) {
        Msg(GERROR, "Unknown curve %d", -c->Num);
        return ps->Num;
      }
    c->Extrude = new ExtrudeParams(COPIED_ENTITY);
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    //pas de abs()! il faut le signe pour copy_mesh dans ExtrudeMesh
    c->Extrude->geo.Source = c2->Num;
    if(e)
      c->Extrude->mesh = e->mesh;
  }

  // FIXME: this is a really ugly hack for backward compatibility, so
  // that we don't screw up the old .geo files too much. (Before
  // version 1.54, we didn't always create new volumes during "Extrude
  // Surface". Now we do, but with "CTX.geom.old_newreg==1", this
  // bumps the NEWREG() counter, and thus changes the whole automatic
  // numbering sequence.) So we locally force old_newreg to 0: in most
  // cases, since we define points, curves, etc., before defining
  // volumes, the NEWVOLUME() call below will return a fairly low
  // number, that will not interfere with the other numbers...
  int tmp = CTX.geom.old_newreg;
  CTX.geom.old_newreg = 0;
  Volume *v = Create_Volume(NEWVOLUME(), MSH_VOLUME);
  CTX.geom.old_newreg = tmp;

  v->Extrude = new ExtrudeParams;
  v->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  v->Extrude->geo.Source = is;
  if(e)
    v->Extrude->mesh = e->mesh;
  int ori = -1;
  List_Add(v->Surfaces, &ps);
  List_Add(v->SurfacesOrientations, &ori);
  ori = 1;
  List_Add(v->Surfaces, &chapeau);
  List_Add(v->SurfacesOrientations, &ori);

  for(i = 0; i < List_Nbr(ps->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c);
    Extrude_ProtudeCurve(type, c->Num, T0, T1, T2, A0, A1, A2, X0, X1, X2,
			 alpha, &s, 0, e);
    if(s){
      if(c < 0)
	ori = -1;
      else
	ori = 1;
      List_Add(v->Surfaces, &s);
      List_Add(v->SurfacesOrientations, &ori);
    }
  }

  switch (type) {
  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    break;
  case ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);

    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);

    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    break;
  case TRANSLATE_ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);

    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);

    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);

    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    break;
  default:
    Msg(GERROR, "Unknown extrusion type");
    return ps->Num;
  }

  // FIXME: why do we do this? only for backward compatibility?
  Tree_Suppress(THEM->Surfaces, &chapeau);
  chapeau->Num = NEWSURFACE();
  THEM->MaxSurfaceNum = chapeau->Num;
  Tree_Add(THEM->Surfaces, &chapeau);

  Tree_Add(THEM->Volumes, &v);

  *pv = v;

  if(CTX.geom.auto_coherence)
    ReplaceAllDuplicates();

  List_Reset(ListOfTransformedPoints);

  return chapeau->Num;
}

void ExtrudeShape(int extrude_type, int shape_type, int shape_num,
		  double T0, double T1, double T2,
		  double A0, double A1, double A2,
		  double X0, double X1, double X2, double alpha,
		  ExtrudeParams *e,
		  List_T *out)
{
  Shape shape;
  shape.Type = shape_type;
  shape.Num = shape_num;
  List_T *tmp = List_Create(1, 1, sizeof(Shape));
  List_Add(tmp, &shape);
  ExtrudeShapes(extrude_type, tmp,
		T0, T1, T2,
		A0, A1, A2,
		X0, X1, X2, alpha,
		e,
		out);
  List_Delete(tmp);
}

void ExtrudeShapes(int type, List_T *in, 
		   double T0, double T1, double T2,
		   double A0, double A1, double A2,
		   double X0, double X1, double X2, double alpha,
		   ExtrudeParams *e,
		   List_T *out)
{
  Shape O, TheShape;
  Curve *pc, *prc;
  Surface *ps;
  Volume *pv;
      
  for(int i = 0; i < List_Nbr(in); i++){
    List_Read(in, i, &O);
    switch(O.Type){
    case MSH_POINT:
      TheShape.Num = Extrude_ProtudePoint(type, O.Num, T0, T1, T2,
					  A0, A1, A2, X0, X1, X2, alpha,
					  &pc, &prc, 1, e);
      TheShape.Type = MSH_POINT;
      List_Add(out, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(out, &TheShape);
      }
      break;
    case MSH_SEGM_LINE:
    case MSH_SEGM_SPLN:
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
    case MSH_SEGM_CIRC:
    case MSH_SEGM_CIRC_INV:
    case MSH_SEGM_ELLI:
    case MSH_SEGM_ELLI_INV:
    case MSH_SEGM_NURBS:
    case MSH_SEGM_PARAMETRIC:
      TheShape.Num = Extrude_ProtudeCurve(type, O.Num, T0, T1, T2,
					  A0, A1, A2, X0, X1, X2, alpha,
					  &ps, 1, e);
      pc = FindCurve(TheShape.Num);
      if(!pc){
	//Msg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = pc->Typ;
      }
      List_Add(out, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(out, &TheShape);
      }
      break;
    case MSH_SURF_NURBS:
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_PLAN:
      TheShape.Num = Extrude_ProtudeSurface(type, O.Num, T0, T1, T2,
					    A0, A1, A2, X0, X1, X2, alpha,
					    &pv, e);
      ps = FindSurface(TheShape.Num);
      if(!ps){
	//Msg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = ps->Typ;
      }
      List_Add(out, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(out, &TheShape);
      }
      break;
    default:
      Msg(GERROR, "Impossible to extrude entity %d (of type %d)", O.Num,
          O.Type);
      break;
    }
  }
}

// Duplicate removal

int compareTwoCurves(const void *a, const void *b)
{
  Curve *c1 = *(Curve **) a;
  Curve *c2 = *(Curve **) b;
  int comp;

  if(c1->Typ != c2->Typ){
    if((c1->Typ == MSH_SEGM_CIRC && c2->Typ == MSH_SEGM_CIRC_INV) ||
       (c1->Typ == MSH_SEGM_CIRC_INV && c2->Typ == MSH_SEGM_CIRC) ||
       (c1->Typ == MSH_SEGM_ELLI && c2->Typ == MSH_SEGM_ELLI_INV) ||
       (c1->Typ == MSH_SEGM_ELLI_INV && c2->Typ == MSH_SEGM_ELLI)){
      // this is still ok
    }
    else
      return c1->Typ - c2->Typ;
  }

  if(List_Nbr(c1->Control_Points) != List_Nbr(c2->Control_Points))
    return List_Nbr(c1->Control_Points) - List_Nbr(c2->Control_Points);
  
  if(!List_Nbr(c1->Control_Points)){
    if(!c1->beg || !c2->beg)
      return 1;
    comp = compareVertex(&c1->beg, &c2->beg);
    if(comp)
      return comp;
    if(!c1->end || !c2->end)
      return 1;
    comp = compareVertex(&c1->end, &c2->end);
    if(comp)
      return comp;
  }
  else {
    for(int i = 0; i < List_Nbr(c1->Control_Points); i++){
      Vertex *v1, *v2;
      List_Read(c1->Control_Points, i, &v1);
      List_Read(c2->Control_Points, i, &v2);
      comp = compareVertex(&v1, &v2);
      if(comp)
	return comp;
    }
  }

  return 0;
}

int compareTwoSurfaces(const void *a, const void *b)
{
  Surface *s1 = *(Surface **) a;
  Surface *s2 = *(Surface **) b;
  return compare2Lists(s1->Generatrices, s2->Generatrices, compareAbsCurve);
}

void MaxNumPoint(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  THEM->MaxPointNum = MAX(THEM->MaxPointNum, v->Num);
}

void MaxNumCurve(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  THEM->MaxLineNum = MAX(THEM->MaxLineNum, c->Num);
}

void MaxNumSurface(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  THEM->MaxSurfaceNum = MAX(THEM->MaxSurfaceNum, s->Num);
}

void ReplaceDuplicatePoints()
{
  List_T *All;
  Tree_T *allNonDuplicatedPoints;
  Vertex *v, **pv, **pv2;
  Curve *c;
  Surface *s;
  Volume *vol;
  int i, j, start, end;

  List_T *points2delete = List_Create(100, 100, sizeof(Vertex *));

  // Create unique points

  start = Tree_Nbr(THEM->Points);

  All = Tree2List(THEM->Points);
  allNonDuplicatedPoints = Tree_Create(sizeof(Vertex *), comparePosition);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &v);
    if(!Tree_Search(allNonDuplicatedPoints, &v)) {
      Tree_Insert(allNonDuplicatedPoints, &v);
    }
    else {
      Tree_Suppress(THEM->Points, &v);
      //List_Add(points2delete,&v);      
    }
  }
  List_Delete(All);

  end = Tree_Nbr(THEM->Points);

  if(start == end) {
    Tree_Delete(allNonDuplicatedPoints);
    List_Delete(points2delete);
    return;
  }

  Msg(DEBUG, "Removed %d duplicate points", start - end);

  if(CTX.geom.old_newreg) {
    THEM->MaxPointNum = 0;
    Tree_Action(THEM->Points, MaxNumPoint);
  }

  // Replace old points in curves

  All = Tree2List(THEM->Curves);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    if(!Tree_Query(allNonDuplicatedPoints, &c->beg))
      Msg(GERROR, "Weird point %d in Coherence", c->beg->Num);
    if(!Tree_Query(allNonDuplicatedPoints, &c->end))
      Msg(GERROR, "Weird point %d in Coherence", c->end->Num);
    for(j = 0; j < List_Nbr(c->Control_Points); j++) {
      pv = (Vertex **) List_Pointer(c->Control_Points, j);
      if(!(pv2 = (Vertex **) Tree_PQuery(allNonDuplicatedPoints, pv)))
        Msg(GERROR, "Weird point %d in Coherence", (*pv)->Num);
      else
        List_Write(c->Control_Points, j, pv2);
    }
  }
  List_Delete(All);

  // Replace old points in surfaces

  All = Tree2List(THEM->Surfaces);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    for(j = 0; j < List_Nbr(s->Control_Points); j++) {
      pv = (Vertex **) List_Pointer(s->Control_Points, j);
      if(!(pv2 = (Vertex **) Tree_PQuery(allNonDuplicatedPoints, pv)))
        Msg(GERROR, "Weird point %d in Coherence", (*pv)->Num);
      else
        List_Write(s->Control_Points, j, pv2);
    }
    for(j = 0; j < List_Nbr(s->TrsfPoints); j++){
      pv = (Vertex **) List_Pointer(s->TrsfPoints, j);
      if(!(pv2 = (Vertex **) Tree_PQuery(allNonDuplicatedPoints, pv)))
	Msg(GERROR, "Weird point %d in Coherence", (*pv)->Num);
      else
	List_Write(s->TrsfPoints, j, pv2);
    }
  }
  List_Delete(All);
  
  // Replace old points in volumes

  All = Tree2List(THEM->Volumes);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &vol);
    for(j = 0; j < List_Nbr(vol->TrsfPoints); j++){
      pv = (Vertex **) List_Pointer(vol->TrsfPoints, j);
      if(!(pv2 = (Vertex **) Tree_PQuery(allNonDuplicatedPoints, pv)))
	Msg(GERROR, "Weird point %d in Coherence", (*pv)->Num);
      else
	List_Write(vol->TrsfPoints, j, pv2);
    }
  }
  List_Delete(All);

  for(int k = 0; k < List_Nbr(points2delete); k++) {
    List_Read(points2delete, i, &v);
    Free_Vertex(&v, 0);
  }

  Tree_Delete(allNonDuplicatedPoints);
  List_Delete(points2delete);

}

void ReplaceDuplicateCurves()
{
  List_T *All;
  Tree_T *allNonDuplicatedCurves;
  Curve *c, *c2, **pc, **pc2;
  Surface *s;
  int i, j, start, end;

  // Create unique curves

  start = Tree_Nbr(THEM->Curves);

  All = Tree2List(THEM->Curves);
  allNonDuplicatedCurves = Tree_Create(sizeof(Curve *), compareTwoCurves);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    if(c->Num > 0) {
      if(!Tree_Search(allNonDuplicatedCurves, &c)) {
        Tree_Insert(allNonDuplicatedCurves, &c);
        if(!(c2 = FindCurve(-c->Num))) {
          Msg(GERROR, "Unknown curve %d", -c->Num);
          List_Delete(All);
          return;
        }
        Tree_Insert(allNonDuplicatedCurves, &c2);
      }
      else {
        Tree_Suppress(THEM->Curves, &c);
        if(!(c2 = FindCurve(-c->Num))) {
          Msg(GERROR, "Unknown curve %d", -c->Num);
          List_Delete(All);
          return;
        }
        Tree_Suppress(THEM->Curves, &c2);
      }
    }
  }
  List_Delete(All);

  end = Tree_Nbr(THEM->Curves);

  if(start == end) {
    Tree_Delete(allNonDuplicatedCurves);
    return;
  }

  Msg(DEBUG, "Removed %d duplicate curves", start - end);

  if(CTX.geom.old_newreg) {
    THEM->MaxLineNum = 0;
    Tree_Action(THEM->Curves, MaxNumCurve);
  }

  // Replace old curves in surfaces

  All = Tree2List(THEM->Surfaces);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    for(j = 0; j < List_Nbr(s->Generatrices); j++) {
      pc = (Curve **) List_Pointer(s->Generatrices, j);
      if(!(pc2 = (Curve **) Tree_PQuery(allNonDuplicatedCurves, pc)))
        Msg(GERROR, "Weird curve %d in Coherence", (*pc)->Num);
      else {
        List_Write(s->Generatrices, j, pc2);
        // Arghhh. Revoir compareTwoCurves !
        End_Curve(*pc2);
      }
    }
  }
  List_Delete(All);

  Tree_Delete(allNonDuplicatedCurves);
}

void ReplaceDuplicateSurfaces()
{
  List_T *All;
  Tree_T *allNonDuplicatedSurfaces;
  Surface *s, **ps, **ps2;
  Volume *vol;
  int i, j, start, end;

  // Create unique surfaces

  start = Tree_Nbr(THEM->Surfaces);

  All = Tree2List(THEM->Surfaces);
  allNonDuplicatedSurfaces = Tree_Create(sizeof(Curve *), compareTwoSurfaces);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    if(s->Num > 0) {
      if(!Tree_Search(allNonDuplicatedSurfaces, &s)) {
        Tree_Insert(allNonDuplicatedSurfaces, &s);
      }
      else {
        Tree_Suppress(THEM->Surfaces, &s);
      }
    }
  }
  List_Delete(All);

  end = Tree_Nbr(THEM->Surfaces);

  if(start == end) {
    Tree_Delete(allNonDuplicatedSurfaces);
    return;
  }

  Msg(DEBUG, "Removed %d duplicate surfaces", start - end);

  if(CTX.geom.old_newreg) {
    THEM->MaxSurfaceNum = 0;
    Tree_Action(THEM->Surfaces, MaxNumSurface);
  } 

  // Replace old surfaces in volumes

  All = Tree2List(THEM->Volumes);
  for(i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &vol);
    for(j = 0; j < List_Nbr(vol->Surfaces); j++) {
      ps = (Surface **) List_Pointer(vol->Surfaces, j);
      if(!(ps2 = (Surface **) Tree_PQuery(allNonDuplicatedSurfaces, ps)))
        Msg(GERROR, "Weird surface %d in Coherence", (*ps)->Num);
      else
        List_Write(vol->Surfaces, j, ps2);
    }
  }
  List_Delete(All);

  Tree_Delete(allNonDuplicatedSurfaces);
}

void ReplaceAllDuplicates()
{
  ReplaceDuplicatePoints();
  ReplaceDuplicateCurves();
  ReplaceDuplicateSurfaces();
}


// Projection of point on curve or surface

static Curve *CURVE;
static Surface *SURFACE;
static Vertex *VERTEX;

double min1d(double (*funct) (double), double *xmin)
{
  // we should think about the tolerance more carefully...
  double ax = 1.e-15, bx = 1.e-12, cx = 1.e-11, fa, fb, fx, tol = 1.e-4;
  mnbrak(&ax, &bx, &cx, &fa, &fx, &fb, funct);
  //Msg(INFO, "--MIN1D : ax %12.5E bx %12.5E cx %12.5E",ax,bx,cx);  
  return (brent(ax, bx, cx, funct, tol, xmin));
}

static void projectPS(int N, double x[], double res[])
{
  //x[1] = u x[2] = v
  Vertex du, dv, c;
  c = InterpolateSurface(SURFACE, x[1], x[2], 0, 0);
  du = InterpolateSurface(SURFACE, x[1], x[2], 1, 1);
  dv = InterpolateSurface(SURFACE, x[1], x[2], 1, 2);
  res[1] =
    (c.Pos.X - VERTEX->Pos.X) * du.Pos.X +
    (c.Pos.Y - VERTEX->Pos.Y) * du.Pos.Y +
    (c.Pos.Z - VERTEX->Pos.Z) * du.Pos.Z;
  res[2] =
    (c.Pos.X - VERTEX->Pos.X) * dv.Pos.X +
    (c.Pos.Y - VERTEX->Pos.Y) * dv.Pos.Y +
    (c.Pos.Z - VERTEX->Pos.Z) * dv.Pos.Z;
}

static double projectPC(double u)
{
  //x[1] = u x[2] = v
  if(u < CURVE->ubeg)
    u = CURVE->ubeg;
  if(u < CURVE->ubeg)
    u = CURVE->ubeg;
  Vertex c;
  c = InterpolateCurve(CURVE, u, 0);
  return sqrt(DSQR(c.Pos.X - VERTEX->Pos.X) +
              DSQR(c.Pos.Y - VERTEX->Pos.Y) + DSQR(c.Pos.Z - VERTEX->Pos.Z));
}

static int UFIXED = 0;
static double FIX;
static double projectPCS(double u)
{
  //x[1] = u x[2] = v
  double tmin, tmax;
  if(UFIXED) {
    tmin = SURFACE->kv[0];
    tmax = SURFACE->kv[SURFACE->Nv + SURFACE->OrderV];
  }
  else {
    tmin = SURFACE->ku[0];
    tmax = SURFACE->ku[SURFACE->Nu + SURFACE->OrderU];
  }

  if(u < tmin)
    u = tmin;
  if(u > tmax)
    u = tmax;
  Vertex c;
  if(UFIXED)
    c = InterpolateSurface(SURFACE, FIX, u, 0, 0);
  else
    c = InterpolateSurface(SURFACE, u, FIX, 0, 0);
  return sqrt(DSQR(c.Pos.X - VERTEX->Pos.X) +
              DSQR(c.Pos.Y - VERTEX->Pos.Y) + DSQR(c.Pos.Z - VERTEX->Pos.Z));
}

bool ProjectPointOnCurve(Curve * c, Vertex * v, Vertex * RES, Vertex * DER)
{
  double xmin;
  CURVE = c;
  VERTEX = v;
  min1d(projectPC, &xmin);
  *RES = InterpolateCurve(CURVE, xmin, 0);
  *DER = InterpolateCurve(CURVE, xmin, 1);
  if(xmin > c->uend) {
    xmin = c->uend;
    *RES = InterpolateCurve(CURVE, c->uend, 0);
    *DER = InterpolateCurve(CURVE, c->uend, 1);
  }
  else if(xmin < c->ubeg) {
    xmin = c->ubeg;
    *RES = InterpolateCurve(CURVE, c->ubeg, 0);
    *DER = InterpolateCurve(CURVE, c->ubeg, 1);
  }  
  return true;
}

bool search_in_boundary(Surface * s, Vertex * p, double t, int Fixu,
                        double *uu, double *vv)
{
  double l, umin = 0., vmin = 0., lmin = 1.e200;
  int i, N;
  Vertex vr;
  double tmin, tmax, u, v;

  if(Fixu) {
    tmin = s->kv[0];
    tmax = s->kv[s->Nv + s->OrderV];
    N = 3 * s->Nu;
  }
  else {
    tmin = s->ku[0];
    tmax = s->ku[s->Nu + s->OrderU];
    N = 3 * s->Nv;
  }
  for(i = 0; i < N; i++) {
    if(Fixu) {
      u = t;
      v = tmin + (tmax - tmin) * (double)(i) / (double)(N - 1);
    }
    else {
      v = t;
      u = tmin + (tmax - tmin) * (double)(i) / (double)(N - 1);
    }
    vr = InterpolateSurface(SURFACE, u, v, 0, 0);
    l = sqrt(DSQR(vr.Pos.X - p->Pos.X) +
             DSQR(vr.Pos.Y - p->Pos.Y) + DSQR(vr.Pos.Z - p->Pos.Z));
    if(l < lmin) {
      lmin = l;
      umin = u;
      vmin = v;
    }
  }

  FIX = t;
  UFIXED = Fixu;
  double xm;
  if(Fixu)
    xm = vmin;
  else
    xm = umin;
  if(lmin > 1.e-3)
    min1d(projectPCS, &xm);
  if(Fixu) {
    *uu = t;
    *vv = xm;
  }
  else {
    *vv = t;
    *uu = xm;
  }
  vr = InterpolateSurface(SURFACE, *uu, *vv, 0, 0);
  l = sqrt(DSQR(vr.Pos.X - p->Pos.X) +
           DSQR(vr.Pos.Y - p->Pos.Y) + DSQR(vr.Pos.Z - p->Pos.Z));
  if(l < 1.e-3)
    return true;
  return false;
}

bool try_a_value(Surface * s, Vertex * p, double u, double v, double *uu,
                 double *vv)
{
  Vertex vr = InterpolateSurface(s, u, v, 0, 0);
  double l = sqrt(DSQR(vr.Pos.X - p->Pos.X) +
                  DSQR(vr.Pos.Y - p->Pos.Y) + DSQR(vr.Pos.Z - p->Pos.Z));
  *uu = u;
  *vv = v;
  if(l < 1.e-3)
    return true;
  return false;
}

bool ProjectPointOnSurface(Surface * s, Vertex & p)
{
  double x[3] = { 0.5, 0.5, 0.5 };
  Vertex vv;
  int check;
  SURFACE = s;
  VERTEX = &p;
  double UMIN = 0.;
  double UMAX = 1.;
  double VMIN = 0.;
  double VMAX = 1.;
  while(1) {
    newt(x, 2, &check, projectPS);
    vv = InterpolateSurface(s, x[1], x[2], 0, 0);
    if(x[1] >= UMIN && x[1] <= UMAX && x[2] >= VMIN && x[2] <= VMAX)
      break;
    x[1] = UMIN + (UMAX - UMIN) * ((rand() % 10000) / 10000.);
    x[2] = VMIN + (VMAX - VMIN) * ((rand() % 10000) / 10000.);
  }
  p.Pos.X = vv.Pos.X;
  p.Pos.Y = vv.Pos.Y;
  p.Pos.Z = vv.Pos.Z;
  p.us[0] = x[1];
  p.us[1] = x[2];
  if(!check) {
    return false;
  }
  return true;
}

bool ProjectPointOnSurface(Surface * s, Vertex * p, double *u, double *v)
{
  static double x[3];
  int check;
  static int deb = 1;
  double VMIN, VMAX, UMIN, UMAX, l, lmin;
  Vertex vv;

  SURFACE = s;
  VERTEX = p;
  lmin = 1.e24;
  UMAX = s->ku[s->Nu + s->OrderU];
  UMIN = s->ku[0];
  VMAX = s->kv[s->Nv + s->OrderV];
  VMIN = s->kv[0];
  if(deb) {
    x[1] = UMIN + (UMAX - UMIN) * ((rand() % 10000) / 10000.);
    x[2] = VMIN + (VMAX - VMIN) * ((rand() % 10000) / 10000.);
    deb = 0;
  }

  if(try_a_value(SURFACE, VERTEX, SURFACE->ku[0] + VERTEX->u,
                 SURFACE->kv[0], u, v))
    return true;
  if(try_a_value(SURFACE, VERTEX, SURFACE->ku[0] + VERTEX->u,
                 SURFACE->kv[SURFACE->Nv + SURFACE->OrderV], u, v))
    return true;
  if(try_a_value
     (SURFACE, VERTEX, SURFACE->ku[SURFACE->Nu + SURFACE->OrderU] - VERTEX->u,
      SURFACE->kv[0], u, v))
    return true;
  if(try_a_value
     (SURFACE, VERTEX, SURFACE->ku[SURFACE->Nu + SURFACE->OrderU] - VERTEX->u,
      SURFACE->kv[SURFACE->Nv + SURFACE->OrderV], u, v))
    return true;
  if(try_a_value
     (SURFACE, VERTEX, SURFACE->ku[0], SURFACE->kv[0] + VERTEX->u, u, v))
    return true;
  if(try_a_value(SURFACE, VERTEX, SURFACE->ku[0],
                 SURFACE->kv[SURFACE->Nv + SURFACE->OrderV] - VERTEX->u, u,
                 v))
    return true;
  if(try_a_value(SURFACE, VERTEX, SURFACE->ku[SURFACE->Nu + SURFACE->OrderU],
                 SURFACE->kv[0] + VERTEX->u, u, v))
    return true;
  if(try_a_value(SURFACE, VERTEX, SURFACE->ku[SURFACE->Nu + SURFACE->OrderU],
                 SURFACE->kv[SURFACE->Nv + SURFACE->OrderV] - VERTEX->u, u,
                 v))
    return true;


  if(search_in_boundary(SURFACE, VERTEX, SURFACE->kv[0], 0, u, v))
    return true;
  if(search_in_boundary
     (SURFACE, VERTEX, SURFACE->kv[SURFACE->Nv + SURFACE->OrderV], 0, u, v))
    return true;
  if(search_in_boundary(SURFACE, VERTEX, SURFACE->ku[0], 1, u, v))
    return true;
  if(search_in_boundary
     (SURFACE, VERTEX, SURFACE->ku[SURFACE->Nu + SURFACE->OrderU], 1, u, v))
    return true;

  while(1) {
    newt(x, 2, &check, projectPS);
    vv = InterpolateSurface(s, x[1], x[2], 0, 0);
    l = sqrt(DSQR(vv.Pos.X - p->Pos.X) +
             DSQR(vv.Pos.Y - p->Pos.Y) + DSQR(vv.Pos.Z - p->Pos.Z));
    if(l < 1.e-1)
      break;
    else {
      x[1] = UMIN + (UMAX - UMIN) * ((rand() % 10000) / 10000.);
      x[2] = VMIN + (VMAX - VMIN) * ((rand() % 10000) / 10000.);
    }
  }
  *u = x[1];
  *v = x[2];

  if(!check) {
    return false;
  }
  return true;
}

void direction(Vertex * v1, Vertex * v2, double d[3])
{
  d[0] = v2->Pos.X - v1->Pos.X;
  d[1] = v2->Pos.Y - v1->Pos.Y;
  d[2] = v2->Pos.Z - v1->Pos.Z;
}

void Projette(Vertex * v, double mat[3][3])
{
  double X, Y, Z;

  X = v->Pos.X * mat[0][0] + v->Pos.Y * mat[0][1] + v->Pos.Z * mat[0][2];
  Y = v->Pos.X * mat[1][0] + v->Pos.Y * mat[1][1] + v->Pos.Z * mat[1][2];
  Z = v->Pos.X * mat[2][0] + v->Pos.Y * mat[2][1] + v->Pos.Z * mat[2][2];
  v->Pos.X = X;
  v->Pos.Y = Y;
  v->Pos.Z = Z;
}
