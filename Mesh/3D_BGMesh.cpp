// $Id: 3D_BGMesh.cpp,v 1.26 2004-05-07 18:42:48 geuzaine Exp $
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
#include "Mesh.h"
#include "2D_Mesh.h"
#include "3D_Mesh.h"
#include "Views.h"
#include "Numeric.h"
#include "Context.h"

extern Mesh *THEM;
extern Context_T CTX;

void ExportLcFieldOnVolume(Mesh * M)
{
  List_T *l = Tree2List(M->Volumes);
  Volume *vol;
  Simplex *simp;
  FILE *f = fopen("OutFile.pos", "w");

  if(!f) {
    Msg(GERROR, "Unable to open file");
    return;
  }

  fprintf(f, "View \"LC_FIELD\" Offset{0,0,0} {\n");
  for(int i = 0; i < List_Nbr(l); i++) {
    List_Read(l, i, &vol);
    List_T *ll = Tree2List(vol->Simplexes);
    for(int j = 0; j < List_Nbr(ll); j++) {
      List_Read(ll, j, &simp);
      simp->ExportLcField(f);
    }
    List_Delete(ll);
  }
  List_Delete(l);
  fprintf(f, "};\n");
  fclose(f);
}

void ExportLcFieldOnSurfaces(Mesh * M)
{
  List_T *l = Tree2List(M->Surfaces);
  Surface *surf;
  Simplex *simp;
  FILE *f = fopen("OutFileS.pos", "w");

  if(!f) {
    Msg(GERROR, "Unable to open file");
    return;
  }

  fprintf(f, "View \"LC_FIELD\" Offset{0,0,0} {\n");
  for(int i = 0; i < List_Nbr(l); i++) {
    List_Read(l, i, &surf);
    List_T *ll = Tree2List(surf->Simplexes);
    for(int j = 0; j < List_Nbr(ll); j++) {
      List_Read(ll, j, &simp);
      simp->ExportLcField(f);
    }
    List_Delete(ll);
  }
  List_Delete(l);
  fprintf(f, "};\n");
  fclose(f);
}

static double XX, YY, ZZ, D, LL;

void findcloser(void *a, void *b)
{
  Vertex *v;
  double dd;
  v = *(Vertex **) a;
  dd = DSQR(v->Pos.X - XX) + DSQR(v->Pos.Y - YY) + DSQR(v->Pos.Z - ZZ);
  if(dd < D) {
    D = dd;
    LL = v->lc;
  }
}

static Mesh *TMPM = NULL;

void LCBGM(double X, double Y, double Z, double *l)
{
  if(Pt_In_Volume(X, Y, Z, TMPM, l, .01));
  else if(Pt_In_Volume(X, Y, Z, TMPM, l, .02));
  else if(Pt_In_Volume(X, Y, Z, TMPM, l, .07));
  else if(Pt_In_Volume(X, Y, Z, TMPM, l, .1));
  else if(Pt_In_Volume(X, Y, Z, TMPM, l, .2));
  else if(Pt_In_Volume(X, Y, Z, TMPM, l, .8));
  else if(Pt_In_Volume(X, Y, Z, TMPM, l, 20.));
  else {
    XX = X;
    YY = Y;
    ZZ = Z;
    D = 1.e24;
    LL = 1;
    Tree_Action(TMPM->Vertices, findcloser);
    *l = LL;
  }
}

double Lc_XYZ(double X, double Y, double Z, Mesh * m)
{
  double l;

  //l = 0.1 * fabs(cos(2 * 3.14159 * X) * cos( 2 * 3.14159 * Y))  + 0.01;
  //return l;

  switch (m->BGM.Typ) {
  case FUNCTION:
    break;
  case CONSTANT:
    l = m->BGM.lc;
    break;
  case ONFILE:
    LCBGM(X, Y, Z, &l);
    break;
  case WITHPOINTS:
    Msg(WARNING, "Send a mail to <gmsh@geuz.org> if you see this (Lc_XYZ)");
    if(Pt_In_Volume(X, Y, Z, m, &l, 0.0));
    else if(Pt_In_Volume(X, Y, Z, m, &l, 0.2));
    else if(Pt_In_Volume(X, Y, Z, m, &l, 0.5));
    else {
      Msg(GERROR, "Exterior Point (%g,%g,%g)", X, Y, Z);
      l = 1.e-25;
    }
    break;
  }
  return CTX.mesh.lc_factor * l;
}

static void AIG(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  AddSimplexInGrid(TMPM, s, BOITE);
}

int BGMWithView(Post_View * ErrView)
{
  Vertex *VertexUp, *v, V, *ver[4];
  Tree_T *Pts;
  int i, j, k, nb;
  double *X, *Y, *Z, *Val;
  Simplex *si;

  if(TMPM){
    Tree_Action(TMPM->Vertices, Free_Vertex);    
    Tree_Action(TMPM->Simplexes, Free_Simplex);    
    Tree_Delete(TMPM->Vertices);
    Tree_Delete(TMPM->Simplexes);
    delete TMPM;
  }

  Pts = Tree_Create(sizeof(Vertex *), comparePosition);
  VertexUp = Create_Vertex(-1, 0., 0., 1., 1., -1.0);

  TMPM = new Mesh;
  TMPM->BGM.Typ = ONFILE;
  TMPM->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);
  TMPM->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
  Create_BgMesh(ONFILE, .2, THEM);

  k = 1;
  if(ErrView->NbST) {
    nb = List_Nbr(ErrView->ST) / ErrView->NbST;
    for(i = 0; i < List_Nbr(ErrView->ST); i += nb) {
      X = (double *)List_Pointer_Fast(ErrView->ST, i);
      Y = (double *)List_Pointer_Fast(ErrView->ST, i + 3);
      Z = (double *)List_Pointer_Fast(ErrView->ST, i + 6);
      Val = (double *)List_Pointer_Fast(ErrView->ST, i + 9);

      for(j = 0; j < 3; j++) {
        v = &V;
        v->Pos.X = X[j];
        v->Pos.Y = Y[j];
        v->Pos.Z = Z[j];
        if(Tree_Query(Pts, &v)) {
          ver[j] = v;
        }
        else {
          v = Create_Vertex(k++, X[j], Y[j], Z[j], Val[j], -1.0);
          ver[j] = v;
          Tree_Add(TMPM->Vertices, &v);
          Tree_Add(Pts, &v);
        }
      }
      si = Create_Simplex(ver[0], ver[1], ver[2], VertexUp);
      Tree_Add(TMPM->Simplexes, &si);
    }
  }

  if(ErrView->NbSS) {
    nb = List_Nbr(ErrView->SS) / ErrView->NbSS;
    for(i = 0; i < List_Nbr(ErrView->SS); i += nb) {
      X = (double *)List_Pointer_Fast(ErrView->SS, i);
      Y = (double *)List_Pointer_Fast(ErrView->SS, i + 4);
      Z = (double *)List_Pointer_Fast(ErrView->SS, i + 8);
      Val = (double *)List_Pointer_Fast(ErrView->SS, i + 12);

      for(j = 0; j < 4; j++) {
        v = &V;
        v->Pos.X = X[j];
        v->Pos.Y = Y[j];
        v->Pos.Z = Z[j];
        if(Tree_Query(Pts, &v)) {
          ver[j] = v;
        }
        else {
          v = Create_Vertex(k++, X[j], Y[j], Z[j], Val[j], -1.0);
          ver[j] = v;
          Tree_Add(TMPM->Vertices, &v);
          Tree_Add(Pts, &v);
        }
      }
      si = Create_Simplex(ver[0], ver[1], ver[2], ver[3]);
      Tree_Add(TMPM->Simplexes, &si);
    }
  }

  TMPM->Grid.init = 0;
  TMPM->Grid.Nx = 10;
  TMPM->Grid.Ny = 10;
  TMPM->Grid.Nz = 10;
  Tree_Action(TMPM->Vertices, findminmax);
  getminmax(&TMPM->Grid.min.X, &TMPM->Grid.min.Y, &TMPM->Grid.min.Z,
            &TMPM->Grid.max.X, &TMPM->Grid.max.Y, &TMPM->Grid.max.Z);

  if(TMPM->Grid.max.Z == TMPM->Grid.min.Z) {
    TMPM->Grid.Nz = 1;
    Tree_Add(TMPM->Vertices, &VertexUp);
    Tree_Action(TMPM->Vertices, findminmax);
    getminmax(&TMPM->Grid.min.X, &TMPM->Grid.min.Y, &TMPM->Grid.min.Z,
              &TMPM->Grid.max.X, &TMPM->Grid.max.Y, &TMPM->Grid.max.Z);
  }

  Tree_Action(TMPM->Simplexes, AIG);

  Tree_Delete(Pts);

  Msg(INFO, "Background mesh loaded (%d nodes, %d elements)",
      Tree_Nbr(TMPM->Vertices), Tree_Nbr(TMPM->Simplexes));

  return 1;
}


double ErrorInView(Post_View * ErrView, int *n)
{
  double e, tot = 0.0, *Val;
  int i, j = 0, nb;

  if(ErrView == NULL) {
    Msg(WARNING, "Empty error view");
    return 0.;
  }

  if(ErrView->NbST) {
    nb = List_Nbr(ErrView->ST) / ErrView->NbST;
    for(i = 0; i < List_Nbr(ErrView->ST); i += nb) {
      Val = (double *)List_Pointer_Fast(ErrView->ST, i + 9);
      e = (Val[0] + Val[1] + Val[2]) / 3.;
      tot += e * e;
      j++;
    }
  }

  if(ErrView->NbSS) {
    nb = List_Nbr(ErrView->SS) / ErrView->NbSS;
    for(i = 0; i < List_Nbr(ErrView->SS); i += nb) {
      Val = (double *)List_Pointer_Fast(ErrView->SS, i + 12);
      e = (Val[0] + Val[1] + Val[2] + Val[3]) * 0.25;
      tot += e * e;
      j++;
    }
  }

  *n = j;

  return 100 * sqrt(tot);
}
