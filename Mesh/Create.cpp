// $Id: Create.cpp,v 1.57 2004-05-28 19:22:13 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "CAD.h"
#include "Mesh.h"
#include "Utils.h"
#include "Context.h"
#include "Create.h"

// This file contains the C-style interface for creation/deletion of
// objects. All this could be easily rewritten in C++ (and split into
// separate classes: Line, Surface, Volume, etc.).

extern Mesh *THEM;
extern Context_T CTX;

int compareNXE(const void *a, const void *b)
{
  NXE *q, *w;

  q = (NXE *) a;
  w = (NXE *) b;
  return compareVertex(&q->v, &w->v);
}

int compareFxE(const void *a, const void *b)
{
  FxE *q, *w;

  q = (FxE *) a;
  w = (FxE *) b;
  return compareFace(&q->Sorted, &w->Sorted);
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

int compareQuality(const void *a, const void *b)
{
  double d;
  Simplex **q, **w;

  q = (Simplex **) a;
  w = (Simplex **) b;
  d = (*q)->Quality - (*w)->Quality;

  if(d > 0)
    return (1);
  if(d < 0)
    return (-1);
  return ((*q)->Num - (*w)->Num);
}

int compareCurve(const void *a, const void *b)
{
  Curve **q, **w;

  q = (Curve **) a;
  w = (Curve **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareAttractor(const void *a, const void *b)
{
  Attractor **q, **w;

  q = (Attractor **) a;
  w = (Attractor **) b;
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

int compareSxF(const void *a, const void *b)
{
  SxF *q, *w;

  q = (SxF *) a;
  w = (SxF *) b;
  return compareFace(&q->F, &w->F);
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

int compareMeshPartitionNum(const void *a, const void *b)
{
  MeshPartition *q, *w;
  q = *(MeshPartition **) a;
  w = *(MeshPartition **) b;
  return (q->Num - w->Num);
}

int compareMeshPartitionIndex(const void *a, const void *b)
{
  MeshPartition *q, *w;
  q = *(MeshPartition **) a;
  w = *(MeshPartition **) b;
  return (q->Index - w->Index);
}

Attractor *Create_Attractor(int Num, double lc1, double lc2, double Radius,
                            Vertex * v, Curve * c, Surface * s)
{
  Attractor *pA;

  pA = (Attractor *) Malloc(sizeof(Attractor));
  pA->v = v;
  pA->c = c;
  pA->s = s;
  pA->lc1 = lc1;
  pA->lc2 = lc2;
  pA->Radius = Radius;
  return pA;
}

PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T * intlist)
{
  PhysicalGroup *p = (PhysicalGroup *) Malloc(sizeof(PhysicalGroup));
  p->Entities = List_Create(List_Nbr(intlist), 1, sizeof(int));
  p->Num = Num;
  THEM->MaxPhysicalNum = IMAX(THEM->MaxPhysicalNum, Num);
  p->Typ = typ;
  p->Visible = VIS_GEOM | VIS_MESH;
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

int Add_MeshPartition(int Num, Mesh * M)
{
  MeshPartition P, *p, **pp;
  p = &P;
  p->Num = Num;
  if((pp = (MeshPartition**)List_PQuery(M->Partitions, &p, compareMeshPartitionNum))){
    return (*pp)->Index;
  }
  else{
    p = (MeshPartition*)Malloc(sizeof(MeshPartition));
    p->Num = Num;
    p->Visible = VIS_GEOM | VIS_MESH;
    p->Index = List_Nbr(M->Partitions);
    List_Add(M->Partitions, &p);
    return p->Index;
  }
}

void Free_MeshPartition(void *a, void *b)
{
  MeshPartition *p = *(MeshPartition **) a;
  if(p) {
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

    if(CTX.geom.circle_warning && Curve->Num > 0 && A3-A1 >= Pi){
      Msg(GERROR1, "Circle or ellipse arc %d greater than/equal to Pi (angle=%g)",
	  Curve->Num, A3-A1);
      Msg(GERROR2, "(If you understand what this implies, you can disable this error");
      Msg(GERROR2, "message by setting Geometry.CircleWarning to 0. Otherwise, please");
      Msg(GERROR3, "subdivide the arc in smaller pieces)");
    }

  }

  if(c->cp)
    Free(c->cp);
  c->cp = (float *)Malloc(4 * List_Nbr(c->Control_Points) * sizeof(float));
  for(i = 0; i < List_Nbr(c->Control_Points); i++) {
    List_Read(c->Control_Points, i, &v[0]);
    c->cp[4 * i] = v[0]->Pos.X;
    c->cp[4 * i + 1] = v[0]->Pos.Y;
    c->cp[4 * i + 2] = v[0]->Pos.Z;
    c->cp[4 * i + 3] = v[0]->w;
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
  Curve *pC;
  Vertex *v;
  int i, j, iPnt;
  double d;
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

  pC = (Curve *) Malloc(sizeof(Curve));
  pC->Dirty = 0;
  pC->Color.type = 0;
  pC->Visible = VIS_GEOM | VIS_MESH;
  pC->cp = NULL;
  pC->Vertices = NULL;
  pC->Extrude = NULL;
  pC->Typ = Typ;
  pC->Num = Num;
  THEM->MaxLineNum = IMAX(THEM->MaxLineNum, Num);
  pC->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
  pC->Method = LIBRE;
  pC->degre = Order;
  pC->Circle.n[0] = 0.0;
  pC->Circle.n[1] = 0.0;
  pC->Circle.n[2] = 1.0;
  for(i = 0; i < 4; i++) {
    pC->ipar[i] = 0;
    pC->dpar[i] = 0.0;
  }

  if(Typ == MSH_SEGM_SPLN) {
    for(i = 0; i < 4; i++)
      for(j = 0; j < 4; j++)
        pC->mat[i][j] = matcr[i][j];
  }
  else if(Typ == MSH_SEGM_BSPLN) {
    for(i = 0; i < 4; i++)
      for(j = 0; j < 4; j++)
        pC->mat[i][j] = matbs[i][j] / 6.0;
  }
  else if(Typ == MSH_SEGM_BEZIER) {
    for(i = 0; i < 4; i++)
      for(j = 0; j < 4; j++)
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
    for(i = 0; i < List_Nbr(Knots); i++) {
      List_Read(Knots, i, &d);
      pC->k[i] = (float)d;
    }
  }
  else
    pC->k = NULL;

  if(Liste) {
    pC->Control_Points = List_Create(List_Nbr(Liste), 1, sizeof(Vertex *));
    for(j = 0; j < List_Nbr(Liste); j++) {
      List_Read(Liste, j, &iPnt);
      if((v = FindPoint(iPnt, THEM)))
        List_Add(pC->Control_Points, &v);
      else{
        Msg(GERROR, "Unknown control point %d in Curve %d", iPnt, pC->Num);
	pC->Dirty = 1;
      }
    }
  }
  else {
    pC->Control_Points = NULL;
    return pC;
  }

  if(p1 < 0) {
    List_Read(pC->Control_Points, 0, &pC->beg);
    List_Read(pC->Control_Points, List_Nbr(pC->Control_Points) - 1, &pC->end);
  }
  else {
    if((v = FindPoint(p1, THEM))) {
      Msg(INFO, "Curve %d first control point %d ", pC->Num, v->Num);
      pC->beg = v;
    }
    else {
      Msg(GERROR, "Unknown control point %d in Curve %d", p1, pC->Num);
      pC->Dirty = 1;
    }
    if((v = FindPoint(p2, THEM))) {
      Msg(INFO, "Curve %d first control point %d ", pC->Num, v->Num);
      pC->end = v;
    }
    else {
      Msg(GERROR, "Unknown control point %d in Curve %d", p2, pC->Num);
      pC->Dirty = 1;
    }
  }

  End_Curve(pC);

  return pC;
}

void Free_Curve(void *a, void *b)
{
  Curve *pC = *(Curve **) a;
  if(pC) {
    List_Delete(pC->Vertices);
    Tree_Action(pC->Simplexes, Free_Simplex);
    Tree_Delete(pC->Simplexes);
    Free(pC->k);
    List_Delete(pC->Control_Points);
    Free(pC->cp);
    Free(pC);
    pC = NULL;
  }
}

Surface *Create_Surface(int Num, int Typ)
{
  Surface *pS;
  int i;  

  pS = (Surface *) Malloc(sizeof(Surface));
  pS->Dirty = 0;
  pS->thePolyRep = 0;
  pS->Color.type = 0;
  pS->Visible = VIS_GEOM | VIS_MESH;
  pS->Num = Num;
  THEM->MaxSurfaceNum = IMAX(THEM->MaxSurfaceNum, Num);
  pS->Typ = Typ;
  pS->Method = LIBRE;
  for(i = 0; i < 5; i++)
    pS->ipar[i] = 0;
  pS->Recombine = 0;
  pS->RecombineAngle = 90;
  pS->TrsfPoints = List_Create(4, 4, sizeof(Vertex *));
  pS->Simplexes = Tree_Create(sizeof(Simplex *), compareQuality);
  pS->Quadrangles = Tree_Create(sizeof(Quadrangle *), compareQuadrangle);
  pS->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);
  pS->TrsfVertices = List_Create(1, 10, sizeof(Vertex *));
  pS->Contours = List_Create(1, 1, sizeof(List_T *));
  pS->Orientations = List_Create(20, 2, sizeof(Vertex));
  pS->Support = pS;
  pS->Control_Points = List_Create(1, 10, sizeof(Vertex *));
  pS->Generatrices = NULL;
  pS->Edges = NULL;
  pS->Extrude = NULL;
  pS->STL = NULL;
  pS->vertexArray = NULL;
  return (pS);
}

void Free_Surface(void *a, void *b)
{
  Surface *pS = *(Surface **) a;
  if(pS) {
    List_Delete(pS->TrsfPoints);
    Tree_Action(pS->Simplexes, Free_Simplex);
    Tree_Delete(pS->Simplexes);
    Tree_Action(pS->Quadrangles, Free_Quadrangle);
    Tree_Delete(pS->Quadrangles);
    Tree_Delete(pS->Vertices);
    List_Delete(pS->TrsfVertices);
    List_Delete(pS->Contours);
    List_Delete(pS->Orientations);
    List_Delete(pS->Control_Points);
    List_Delete(pS->Generatrices);
    if(pS->Edges) {
      Tree_Action(pS->Edges, Free_Edge);
      Tree_Delete(pS->Edges);
    }
    if(pS->vertexArray)
      delete pS->vertexArray;
    Free(pS);
    pS = NULL;
  }
}

Volume *Create_Volume(int Num, int Typ)
{
  Volume *pV;
  int i;

  pV = (Volume *) Malloc(sizeof(Volume));
  pV->Dirty = 0;
  pV->Color.type = 0;
  pV->Visible = VIS_GEOM | VIS_MESH;
  pV->Num = Num;
  THEM->MaxVolumeNum = IMAX(THEM->MaxVolumeNum, Num);
  pV->Typ = Typ;
  pV->Method = LIBRE;
  for(i = 0; i < 8; i++)
    pV->ipar[i] = 0;
  pV->TrsfPoints = List_Create(6, 6, sizeof(Vertex *));
  pV->Surfaces = List_Create(1, 2, sizeof(Surface *));
  pV->Simplexes = Tree_Create(sizeof(Simplex *), compareQuality);
  pV->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);
  pV->Hexahedra = Tree_Create(sizeof(Hexahedron *), compareHexahedron);
  pV->Prisms = Tree_Create(sizeof(Prism *), comparePrism);
  pV->Pyramids = Tree_Create(sizeof(Pyramid *), comparePyramid);
  pV->Extrude = NULL;
  pV->Edges = NULL;
  pV->Faces = NULL;
  // for old extrusion mesh generator
  pV->Simp_Surf = Tree_Create(sizeof(Simplex *), compareSimplex);
  pV->Quad_Surf = Tree_Create(sizeof(Simplex *), compareQuadrangle);
  return pV;
}

void Free_Volume(void *a, void *b)
{
  Volume *pV = *(Volume **) a;
  if(pV) {
    List_Delete(pV->TrsfPoints);
    List_Delete(pV->Surfaces);  // surfaces freed elsewhere
    Tree_Action(pV->Simplexes, Free_Simplex);
    Tree_Delete(pV->Simplexes);
    Tree_Delete(pV->Simp_Surf); // for old extrusion mesh generator
    Tree_Delete(pV->Quad_Surf); // for old extrusion mesh generator
    Tree_Delete(pV->Vertices);  // vertices freed elsewhere
    Tree_Action(pV->Hexahedra, Free_Hexahedron);
    Tree_Delete(pV->Hexahedra);
    Tree_Action(pV->Prisms, Free_Prism);
    Tree_Delete(pV->Prisms);
    Tree_Action(pV->Pyramids, Free_Pyramid);
    Tree_Delete(pV->Pyramids);
    Tree_Action(pV->Edges, Free_Edge);
    Tree_Delete(pV->Edges);
    Tree_Delete(pV->Faces);
    Free(pV);
    pV = NULL;
  }
}

