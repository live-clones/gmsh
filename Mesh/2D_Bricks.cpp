// $Id: 2D_Bricks.cpp,v 1.14 2005-01-01 19:35:30 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "Mesh.h"
#include "2D_Mesh.h"

static double XmaxGrid, YmaxGrid, XminGrid, YminGrid, ZmaxGrid, ZminGrid;
static double XminBox, XmaxBox, YminBox, YmaxBox, ZminBox, ZmaxBox;
static int Nx = 0, Ny = 0, Nz = 0;
static List_T *GridList = NULL;
static DocRecord *MyMesh = NULL;

extern PointRecord *gPointArray;

int fcmp_Map(const void *a, const void *b)
{
  return ((struct Map *)a)->Num - ((struct Map *)b)->Num;
}

void Invert_MappingLists(List_T * List1, List_T * List2)
{
  struct Map TmpMap1, TmpMap2;
  struct Map *TmpMap;
  List_T *TmpList;

  int i, j, Entity, CurrentEntity;

  TmpList = List_Create(10 * List_Nbr(List1), 100, sizeof(int));

  for(i = 0; i < List_Nbr(List1); i++) {
    List_Read(List1, i, &TmpMap1);
    for(j = 0; j < List_Nbr(TmpMap1.List); j++) {
      List_Read(TmpMap1.List, j, &Entity);
      List_Add(TmpList, &Entity);
    }
  }

  List_Sort(TmpList, fcmp_int);

  List_Read(TmpList, 0, &CurrentEntity);
  TmpMap1.Num = CurrentEntity;
  TmpMap1.List = List_Create(10, 10, sizeof(int));
  List_Add(List2, &TmpMap1);
  for(i = 1; i < List_Nbr(TmpList); i++) {
    List_Read(TmpList, i, &Entity);
    if(Entity != CurrentEntity) {
      CurrentEntity = Entity;
      TmpMap1.Num = CurrentEntity;
      TmpMap1.List = List_Create(10, 10, sizeof(int));
      List_Add(List2, &TmpMap1);
    }
  }

  for(i = 0; i < List_Nbr(List1); i++) {
    List_Read(List1, i, &TmpMap1);
    for(j = 0; j < List_Nbr(TmpMap1.List); j++) {
      List_Read(TmpMap1.List, j, &Entity);
      TmpMap2.Num = Entity;
      if((TmpMap =
          (struct Map *)List_PQuery(List2, &TmpMap2, fcmp_Map)) != NULL) {
        List_Add(TmpMap->List, &TmpMap1.Num);
      }
    }
  }

  List_Delete(TmpList);
}

int InWhichBrick(double X, double Y, double Z)
{
  int Ix, Iy, Iz;

  if(X > XmaxGrid || X < XminGrid || Y > YmaxGrid ||
     Y < YminGrid || Z > ZmaxGrid || Z < ZminGrid)
    return (-1);

  Ix = (int)((double)Nx * (X - XminGrid) / (XmaxGrid - XminGrid));
  Iy = (int)((double)Ny * (Y - YminGrid) / (YmaxGrid - YminGrid));
  Iz = (int)((double)Nz * (Z - ZminGrid) / (ZmaxGrid - ZminGrid));
  Ix = (Ix < Nx) ? Ix : Nx - 1;
  Iy = (Iy < Ny) ? Iy : Ny - 1;
  Iz = (Iz < Nz) ? Iz : Nz - 1;
  return (1 + Ix + Iy * Nx + Iz * Nx * Ny);
}

List_T *AllBricksForABox(void)
{
  List_T *List;
  int Ix1, Ix2, Iy1, Iy2, Iz1, Iz2;
  int i, j, k, Num;

  Ix1 = (int)((double)Nx * (XminBox - XminGrid) / (XmaxGrid - XminGrid));
  Ix2 = (int)((double)Nx * (XmaxBox - XminGrid) / (XmaxGrid - XminGrid));
  Iy1 = (int)((double)Ny * (YminBox - YminGrid) / (YmaxGrid - YminGrid));
  Iy2 = (int)((double)Ny * (YmaxBox - YminGrid) / (YmaxGrid - YminGrid));
  Iz1 = (int)((double)Nz * (ZminBox - ZminGrid) / (ZmaxGrid - ZminGrid));
  Iz2 = (int)((double)Nz * (ZmaxBox - ZminGrid) / (ZmaxGrid - ZminGrid));
  Ix1 = (Ix1 < Nx) ? Ix1 : Nx - 1;
  Ix2 = (Ix2 < Nx) ? Ix2 : Nx - 1;
  Iy1 = (Iy1 < Ny) ? Iy1 : Ny - 1;
  Iy2 = (Iy2 < Ny) ? Iy2 : Ny - 1;
  Iz1 = (Iz1 < Nz) ? Iz1 : Nz - 1;
  Iz2 = (Iz2 < Nz) ? Iz2 : Nz - 1;

  List =
    List_Create((Ix2 - Ix1 + 1) * (Iy2 - Iy1 + 1) * (Iz2 - Iz1 + 1), 1,
                sizeof(int));

  for(i = Ix1; i <= Ix2; i++) {
    for(j = Iy1; j <= Iy2; j++) {
      for(k = Iz1; k <= Iz2; k++) {
        Num = 1 + i + j * Nx + k * Nx * Ny;
        List_Add(List, &Num);
      }
    }
  }
  return (List);
}

void InitBricks(DocRecord * MESH)
{
  int i, j, a, b, c;
  List_T *InvList;
  struct Map InvMap;
  double X[3], Y[3], dx, dy;

  MyMesh = MESH;

  if(!MyMesh) return;

  Nx = (int)sqrt((double)MESH->numTriangles) + 1;
  Ny = Nx;
  Nz = 1;
  ZminGrid = 0.;
  ZmaxGrid = 1.;

  if(GridList)
    List_Delete(GridList);
  GridList = List_Create(Nx * Ny * Nz, 1, sizeof(struct Map));
  InvList = List_Create(MESH->numTriangles, 1, sizeof(struct Map));

  for(i = 0; i < MESH->numTriangles; i++) {
    a = MESH->delaunay[i].t.a;
    b = MESH->delaunay[i].t.b;
    c = MESH->delaunay[i].t.c;

    X[0] = MESH->points[a].where.h;
    X[1] = MESH->points[b].where.h;
    X[2] = MESH->points[c].where.h;
    Y[0] = MESH->points[a].where.v;
    Y[1] = MESH->points[b].where.v;
    Y[2] = MESH->points[c].where.v;

    if(!i) {
      XminGrid = XmaxGrid = X[0];
      YminGrid = YmaxGrid = Y[0];
    }

    for(j = 0; j < 3; j++) {
      XmaxGrid = DMAX(XmaxGrid, X[j]);
      XminGrid = DMIN(XminGrid, X[j]);
      YmaxGrid = DMAX(YmaxGrid, Y[j]);
      YminGrid = DMIN(YminGrid, Y[j]);
    }
  }
  dx = XmaxGrid - XminGrid;
  dy = YmaxGrid - YminGrid;
  XmaxGrid += 0.01 * dx;
  YmaxGrid += 0.01 * dy;
  XminGrid -= 0.01 * dx;
  YminGrid -= 0.01 * dy;

  for(i = 0; i < MESH->numTriangles; i++) {
    a = MESH->delaunay[i].t.a;
    b = MESH->delaunay[i].t.b;
    c = MESH->delaunay[i].t.c;

    X[0] = XminBox = XmaxBox = MESH->points[a].where.h;
    X[1] = MESH->points[b].where.h;
    X[2] = MESH->points[c].where.h;
    Y[0] = YminBox = YmaxBox = MESH->points[a].where.v;
    Y[1] = MESH->points[b].where.v;
    Y[2] = MESH->points[c].where.v;

    for(j = 1; j < 3; j++) {
      XmaxBox = DMAX(XmaxBox, X[j]);
      XminBox = DMIN(XminBox, X[j]);
      YmaxBox = DMAX(YmaxBox, Y[j]);
      YminBox = DMIN(YminBox, Y[j]);
    }
    ZmaxBox = 1.0;
    ZminBox = 0.0;

    InvMap.Num = i;
    InvMap.List = AllBricksForABox();
    List_Add(InvList, &InvMap);
  }

  Invert_MappingLists(InvList, GridList);
  List_Delete(InvList);
}


Delaunay *Find_Triangle(MPoint pt, DocRecord * MESH, int typ)
{
  int a, b, c, i, found, KeyBrick, j;
  Delaunay *del, *del2;
  double Z, Znew;
  PointRecord *ptr;
  double Xcg, Ycg;
  struct Map *pBrick;

  ptr = gPointArray;
  gPointArray = MESH->points;

  if(MyMesh == MESH) {
    KeyBrick = InWhichBrick(pt.h, pt.v, 0.0);
    if((pBrick =
        (struct Map *)List_PQuery(GridList, &KeyBrick, fcmp_Map)) == NULL) {
      if(typ == A_TOUT_PRIX) {
        gPointArray = ptr;
        return (NULL);
      }
    }
    else {
      for(i = 0; i < List_Nbr(pBrick->List); i++) {
        j = *(int *)List_Pointer(pBrick->List, i);
        a = MESH->delaunay[j].t.a;
        b = MESH->delaunay[j].t.b;
        c = MESH->delaunay[j].t.c;
        if(MESH->delaunay[j].t.position != EXTERN || typ == BOF) {
          if(PtInTriangle(pt, a, b, c)) {
            gPointArray = ptr;
            return (&MESH->delaunay[j]);
          }
        }
      }
      if(typ == A_TOUT_PRIX) {
        gPointArray = ptr;
        return NULL;
      }
    }
  }
  else {
    i = 0;
    found = 0;
    while(!found && i < MESH->numTriangles) {
      if((!PtInTriangle(pt, MESH->delaunay[i].t.a, MESH->delaunay[i].t.b,
                        MESH->delaunay[i].t.c)) ||
         (MESH->delaunay[i].t.position == EXTERN && typ != BOF))
        i++;
      else
        found = 1;
    };

    if(found == 1) {
      gPointArray = ptr;
      return (&(MESH->delaunay[i]));
    }
    if(typ == A_TOUT_PRIX) {
      gPointArray = ptr;
      return NULL;
    }
  }

  del = &(MESH->delaunay[0]);

  Xcg = gPointArray[del->t.a].where.h +
    gPointArray[del->t.b].where.h + gPointArray[del->t.c].where.h;

  Ycg = gPointArray[del->t.a].where.v +
    gPointArray[del->t.b].where.v + gPointArray[del->t.c].where.v;

  Xcg /= 3.;
  Ycg /= 3.;

  Z = DSQR(Xcg - pt.h) + DSQR(Ycg - pt.v);

  for(i = 1; i < MESH->numTriangles; i++) {
    del2 = &(MESH->delaunay[i]);
    Xcg = gPointArray[del2->t.a].where.h +
      gPointArray[del2->t.b].where.h + gPointArray[del2->t.c].where.h;
    Ycg = gPointArray[del2->t.a].where.v +
      gPointArray[del2->t.b].where.v + gPointArray[del2->t.c].where.v;
    Xcg /= 3.;
    Ycg /= 3.;
    Znew = DSQR(Xcg - pt.h) + DSQR(Ycg - pt.v);
    if(Znew < Z) {
      del = del2;
      Z = Znew;
    }
  }

  gPointArray = ptr;
  return del;
}

int PtInTriangle(MPoint p, PointNumero a, PointNumero b, PointNumero c)
{
  double Xmin, Xmax, Ymin, Ymax, Xtr[4], Ytr[4], A[2], B[2], X, Y, Signus[3];
  int i;

  X = p.h;
  Y = p.v;
  Xtr[0] = Xmax = Xmin = gPointArray[a].where.h;
  Xtr[3] = gPointArray[a].where.h;
  Xtr[1] = gPointArray[b].where.h;
  Xtr[2] = gPointArray[c].where.h;
  Ytr[0] = Ymax = Ymin = gPointArray[a].where.v;
  Ytr[3] = gPointArray[a].where.v;
  Ytr[1] = gPointArray[b].where.v;
  Ytr[2] = gPointArray[c].where.v;

  for(i = 1; i < 3; i++) {
    Xmin = (Xtr[i] < Xmin) ? Xtr[i] : Xmin;
    Xmax = (Xtr[i] > Xmax) ? Xtr[i] : Xmax;
    Ymin = (Ytr[i] < Ymin) ? Ytr[i] : Ymin;
    Ymax = (Ytr[i] > Ymax) ? Ytr[i] : Ymax;
  }

  if(X > Xmax || X < Xmin || Y > Ymax || Y < Ymin)
    return (0);

  for(i = 0; i < 3; i++) {
    A[0] = Xtr[i + 1] - Xtr[i];
    A[1] = Ytr[i + 1] - Ytr[i];
    B[0] = X - Xtr[i];
    B[1] = Y - Ytr[i];
    Signus[i] = A[0] * B[1] - A[1] * B[0];
  }
  for(i = 0; i < 2; i++) {
    if((Signus[i] * Signus[i + 1]) <= 0)
      return (0);
  }
  return (1);
}
