// $Id: 2D_Recombine.cpp,v 1.21 2004-05-26 00:33:37 geuzaine Exp $
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
#include "Mesh.h"
#include "Utils.h"
#include "2D_Mesh.h"
#include "Create.h"
#include "Context.h"

extern Context_T CTX;

static Tree_T *RecEdges, *Triangles, *RecSimplex, *TREEELM;
static List_T *SimplexesToRemove;
static double ALPHA;
static int RECNUM;

// Note: these routines temporarily leave quads in the simplex tree,
// and only remove them at the end...

void addTriangles(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  if(s->V[2] && !s->V[3])
    Tree_Add(Triangles, &s);
}

void addRecEdges(void *a, void *b)
{
  Edge *ed = (Edge *) a;
  if(ed->a < ALPHA)
    Tree_Add(RecEdges, ed);
}

void computeAngles(void *a, void *b)
{
  Edge *ed = (Edge *) a;
  if(List_Nbr(ed->Simplexes) != 2) {
    ed->a = 180.;
    return;
  }

  double Angle;
  Angle = fabs(90. - angle_3pts(ed->O[0], ed->V[0], ed->O[1]));
  Angle = DMAX(fabs(90. - angle_3pts(ed->V[0], ed->O[1], ed->V[1])), Angle);
  Angle = DMAX(fabs(90. - angle_3pts(ed->O[1], ed->V[1], ed->O[0])), Angle);
  Angle = DMAX(fabs(90. - angle_3pts(ed->V[0], ed->O[0], ed->V[1])), Angle);
  ed->a = Angle;
}

void recombineFace(void *a, void *b)
{
  Edge *ed = (Edge *) a;

  if(List_Nbr(ed->Simplexes) != 2)
    return;

  if(ed->a < ALPHA) {
    Simplex *s1, *s2;
    List_Read(ed->Simplexes, 0, &s1);
    List_Read(ed->Simplexes, 1, &s2);
    if(Tree_Search(RecSimplex, &s1))
      return;
    if(s1->V[3])
      return;
    if(Tree_Search(RecSimplex, &s2))
      return;
    if(s2->V[3])
      return;
    Tree_Add(RecSimplex, &s1);
    Tree_Suppress(TREEELM, &s1);
    s2->V[3] = ed->V[0];
    s2->V[2] = ed->O[0];
    s2->V[1] = ed->V[1];
    s2->V[0] = ed->O[1];
    RECNUM++;
  }
}

void removeQuads(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  if(s->V[3])
    List_Add(SimplexesToRemove, &s);
}

int Recombine(Tree_T * Vertices, Tree_T * Simplexes, Tree_T * Quadrangles, 
	      double a)
{
  Tree_T *tnxe;
  int ntot;

  ALPHA = a;
  TREEELM = Simplexes;
  ntot = 0;

  while(1) {

    // Initialization
    RECNUM = 0;
    RecEdges = Tree_Create(sizeof(Edge), compareEdgeAngle);
    RecSimplex = Tree_Create(sizeof(Simplex *), compareSimplex);
    Triangles = Tree_Create(sizeof(Simplex *), compareSimplex);

    // Recombination
    Tree_Action(Simplexes, addTriangles);
    EdgesContainer edges(Triangles);
    Tree_Action(edges.AllEdges, computeAngles);
    Tree_Action(edges.AllEdges, addRecEdges);
    Tree_Action(RecEdges, recombineFace);

    // Smoothing
    if(CTX.mesh.nb_smoothing) {
      tnxe = Tree_Create(sizeof(NXE), compareNXE);
      create_NXE(Vertices, Simplexes, tnxe);
      for(int i = 0; i < CTX.mesh.nb_smoothing; i++)
        Tree_Action(tnxe, ActionLissSurf);
      delete_NXE(tnxe);
    }

    // Destruction
    Tree_Delete(RecEdges);
    Tree_Action(RecSimplex, Free_Simplex);
    Tree_Delete(RecSimplex);
    Tree_Delete(Triangles);

    ntot += RECNUM;
    if(!RECNUM)
      break;
  }

  // remove the quads from the simplex tree
  SimplexesToRemove = List_Create(100, 100, sizeof(Simplex*));
  Tree_Action(Simplexes, removeQuads);
  for(int i = 0; i < List_Nbr(SimplexesToRemove); i++){
    Simplex *s;
    List_Read(SimplexesToRemove, i, &s);
    Quadrangle *q = Create_Quadrangle(s->V[0], s->V[1], s->V[2], s->V[3]);
    q->iEnt = s->iEnt;
    Tree_Add(Quadrangles, &q);
    Tree_Suppress(Simplexes, &s);
    Free_Simplex(&s, NULL);
  }
  List_Delete(SimplexesToRemove);

  Msg(STATUS2, "Recombined %d quadrangles", ntot);

  return ntot;
}
