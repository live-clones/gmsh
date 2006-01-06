// $Id: 3D_BGMesh.cpp,v 1.38 2006-01-06 00:34:25 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

static FILE *statfile = NULL;

void ExportStatistics(void *a, void *b)
{
  Element *ele = *(Element**)a;
  if(statfile) ele->ExportStatistics(statfile);
}

void ExportMeshStatistics(Mesh * M, char *filename, int volume, int surface)
{
  if(!Tree_Nbr(M->Volumes) && !Tree_Nbr(M->Surfaces)){
    Msg(GERROR, "No volumes or surfaces to save");
    return;
  }
  else if(volume && !surface && !Tree_Nbr(M->Volumes)){
    Msg(GERROR, "No volumes to save");
    return;
  }
  else if(!volume && surface && !Tree_Nbr(M->Surfaces)){
    Msg(GERROR, "No surfaces to save");
    return;
  }

  statfile = fopen(filename, "w");

  if(!statfile) {
    Msg(GERROR, "Unable to open file '%s'", filename);
    return;
  }

  if(volume && Tree_Nbr(M->Volumes)){
    List_T *l = Tree2List(M->Volumes);
    fprintf(statfile, "View \"Volume Statistics\" {\n");
    fprintf(statfile, "T2(1.e5,30,%d){\"Characteristic Length\", \"Gamma\", \"Eta\", "
	    "\"Rho\", \"Element Number\"};\n", (1<<16)|(4<<8));
    for(int i = 0; i < List_Nbr(l); i++) {
      Volume *vol;
      List_Read(l, i, &vol);
      Tree_Action(vol->Simplexes, ExportStatistics);
      Tree_Action(vol->SimplexesBase, ExportStatistics);
      Tree_Action(vol->Hexahedra, ExportStatistics);
      Tree_Action(vol->Prisms, ExportStatistics);
      Tree_Action(vol->Pyramids, ExportStatistics);
    }
    List_Delete(l);
    fprintf(statfile, "};\n");
  }
  
  if(surface && Tree_Nbr(M->Surfaces)){
    List_T *l = Tree2List(M->Surfaces);
    fprintf(statfile, "View \"Surface Statistics\" {\n");
    fprintf(statfile, "T2(1.e5,30,%d){\"Characteristic Length\", \"Gamma\", \"Eta\", "
	    "\"Rho\", \"Element Number\"};\n", (1<<16)|(4<<8));
    for(int i = 0; i < List_Nbr(l); i++) {
      Surface *surf;
      List_Read(l, i, &surf);
      Tree_Action(surf->Simplexes, ExportStatistics);
      Tree_Action(surf->SimplexesBase, ExportStatistics);
      Tree_Action(surf->Quadrangles, ExportStatistics);
    }
    List_Delete(l);
    fprintf(statfile, "};\n");
  }

  fclose(statfile);
  statfile = NULL;
}

static Mesh *TMPM = NULL;
static double XX, YY, ZZ, DD, LL;

void findcloser(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  double d = DSQR(v->Pos.X - XX) + DSQR(v->Pos.Y - YY) + DSQR(v->Pos.Z - ZZ);
  if(d < DD) {
    DD = d;
    LL = v->lc;
  }
}

double Lc_XYZ(double X, double Y, double Z, Mesh * m)
{
  double l;

  switch (m->BGM.Typ) {
  case FUNCTION:
    // for testing...
    l = 0.1 * fabs(cos(2 * 3.14159 * X) * cos( 2 * 3.14159 * Y))  + 0.01;
    break;
  case CONSTANT:
    l = m->BGM.lc;
    break;
  case ONFILE:
    if(Pt_In_Volume(X, Y, Z, TMPM, &l, .01));
    else if(Pt_In_Volume(X, Y, Z, TMPM, &l, .02));
    else if(Pt_In_Volume(X, Y, Z, TMPM, &l, .07));
    else if(Pt_In_Volume(X, Y, Z, TMPM, &l, .1));
    else if(Pt_In_Volume(X, Y, Z, TMPM, &l, .2));
    else if(Pt_In_Volume(X, Y, Z, TMPM, &l, .8));
    else if(Pt_In_Volume(X, Y, Z, TMPM, &l, 20.));
    else {
      XX = X;
      YY = Y;
      ZZ = Z;
      DD = 1.e24;
      LL = 1;
      Tree_Action(TMPM->Vertices, findcloser);
      l = LL;
    }
    break;
  case WITHPOINTS:
    Msg(GERROR, "We should never call Lc_XYZ with BGM.Typ == WITHPOINTS!");
    l = 1.0;
    break;
  }

  if(l <= 0.){
    Msg(WARNING, "Characteristic length <= 0: setting to 1.0");
    l = 1.0;
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
