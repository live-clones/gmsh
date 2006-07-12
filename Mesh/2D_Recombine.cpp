// $Id: 2D_Recombine.cpp,v 1.28 2006-07-12 07:24:14 geuzaine Exp $
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
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "Interpolation.h"
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

/*
  This function recombines EVERYTHING. 

  First, all characteristic lengths are divided by 2.

  This is done in 3 steps.
  -) the previous technique is applied to every surface
  -) remainder triangles are split into 3 quads and all recombined quads
     are split into 4 quads
  -) Enhancements are performned on the quad mesh.
 */

int Recombine_All (Mesh *M)
{
  if(!Tree_Nbr(M->Surfaces)) 
    return 0;

  List_T *surfaces = Tree2List(M->Surfaces);

  // check if we need to do something
  int to_do = 0;
  for(int i = 0; i < List_Nbr(surfaces); i++){
    Surface *s;
    List_Read(surfaces, i, &s);
    if(s->Recombine){
      to_do = 1;
      break;
    }
  }
  
  if(!to_do){
    List_Delete(surfaces);
    return 0;
  }
  
  // add 2nd order nodes to all elements 
  Degre2(2);

  Msg(STATUS3, "Splitting all elements");

  // then split everybody
  for(int i = 0; i < List_Nbr(surfaces); i++){
    Surface *s;
    List_Read(surfaces, i, &s);

    List_T *Quadrangles = Tree2List(s->Quadrangles);
    for(int j=0 ; j<List_Nbr(Quadrangles); j++){
      Quadrangle *q;
      List_Read(Quadrangles, j, &q);
      Quadrangle *q1 = Create_Quadrangle(q->V[0], q->VSUP[0], q->VSUP[4], q->VSUP[3]);
      Quadrangle *q2 = Create_Quadrangle(q->V[1], q->VSUP[1], q->VSUP[4], q->VSUP[0]);
      Quadrangle *q3 = Create_Quadrangle(q->V[2], q->VSUP[2], q->VSUP[4], q->VSUP[1]);
      Quadrangle *q4 = Create_Quadrangle(q->V[3], q->VSUP[3], q->VSUP[4], q->VSUP[2]);
      q1->iEnt = q2->iEnt = q3->iEnt = q4->iEnt = q->iEnt;      
      for(int k = 0; k < 5; k++){
	q->VSUP[k]->Degree = 1;
	Tree_Insert(s->Vertices, &q->VSUP[k]);
      }
      Tree_Add(s->Quadrangles, &q1);
      Tree_Add(s->Quadrangles, &q2);
      Tree_Add(s->Quadrangles, &q3);
      Tree_Add(s->Quadrangles, &q4);
      Tree_Suppress(s->Quadrangles, &q);
      Free_Quadrangle(&q, 0);
    }
    List_Delete(Quadrangles);
    
    List_T *Triangles = Tree2List(s->Simplexes);
    if(s->Recombine){
      for(int j=0 ; j<List_Nbr(Triangles); j++){
	Simplex *t;
	List_Read(Triangles, j, &t);
	Vertex *c;
	if(s->Typ == MSH_SURF_PLAN || s->Typ == MSH_SURF_DISCRETE){
	  c = Create_Vertex(++M->MaxPointNum, 
			    (t->V[0]->Pos.X+t->V[1]->Pos.X+t->V[2]->Pos.X)/3.,
			    (t->V[0]->Pos.Y+t->V[1]->Pos.Y+t->V[2]->Pos.Y)/3.,
			    (t->V[0]->Pos.Z+t->V[1]->Pos.Z+t->V[2]->Pos.Z)/3.,
			    (t->V[0]->lc+t->V[1]->lc+t->V[2]->lc)/3.,
			    (t->V[0]->u+t->V[1]->u+t->V[2]->u)/3.);
	}
	else{
	  double U1, U2, U3, V1, V2, V3;
	  XYZtoUV(s, t->V[0]->Pos.X, t->V[0]->Pos.Y, t->V[0]->Pos.Z, &U1, &V1, 1.0);
	  XYZtoUV(s, t->V[1]->Pos.X, t->V[1]->Pos.Y, t->V[1]->Pos.Z, &U2, &V2, 1.0);
	  XYZtoUV(s, t->V[2]->Pos.X, t->V[2]->Pos.Y, t->V[2]->Pos.Z, &U3, &V3, 1.0);
	  double U = (U1 + U2 + U3)/.3;
	  double V = (V1 + V2 + V3)/3.;
	  Vertex v = InterpolateSurface(s, U, V, 0, 0);
	  c = Create_Vertex(++M->MaxPointNum, v.Pos.X, v.Pos.Y, v.Pos.Z, v.lc, v.u);
	}  
        Tree_Add(M->Vertices, &c);
        Tree_Insert(s->Vertices, &c);
	Quadrangle *q1 = Create_Quadrangle(t->V[0], t->VSUP[0], c, t->VSUP[2]);
	Quadrangle *q2 = Create_Quadrangle(t->V[1], t->VSUP[1], c, t->VSUP[0]);
	Quadrangle *q3 = Create_Quadrangle(t->V[2], t->VSUP[2], c, t->VSUP[1]);
	q1->iEnt = q2->iEnt = q3->iEnt = t->iEnt;
	for(int k = 0; k < 3; k++){
	  t->VSUP[k]->Degree = 1;
	  Tree_Insert(s->Vertices, &t->VSUP[k]);
	}
	Tree_Add(s->Quadrangles, &q1);
	Tree_Add(s->Quadrangles, &q2);
	Tree_Add(s->Quadrangles, &q3);
	Tree_Suppress(s->Simplexes, &t);
	Free_Simplex(&t, 0);
      }
    }
    else{
      for(int j=0 ; j<List_Nbr(Triangles); j++){
	Simplex *t;
	List_Read(Triangles, j, &t);
	Simplex *t1 = Create_Simplex(t->V[0], t->VSUP[0],t->VSUP[2], 0);
	Simplex *t2 = Create_Simplex(t->V[1], t->VSUP[1],t->VSUP[0], 0);
	Simplex *t3 = Create_Simplex(t->V[2], t->VSUP[2],t->VSUP[1], 0);
	Simplex *t4 = Create_Simplex(t->VSUP[0], t->VSUP[1],t->VSUP[2], 0);
	t1->iEnt = t2->iEnt = t3->iEnt = t4->iEnt = t->iEnt;
	for(int k = 0; k < 3; k++){
	  t->VSUP[k]->Degree = 1;
	  Tree_Insert(s->Vertices, &t->VSUP[k]);
	}
	Tree_Add(s->Simplexes, &t1);
	Tree_Add(s->Simplexes, &t2);
	Tree_Add(s->Simplexes, &t3);
	Tree_Add(s->Simplexes, &t4);
	Tree_Suppress(s->Simplexes, &t);
	Free_Simplex(&t, 0);
      }
    }
    List_Delete(Triangles);
  }

  List_Delete(surfaces);

  List_T *curves = Tree2List(M->Curves);
  for(int i = 0; i < List_Nbr(curves); i++){
    Curve *c;
    List_Read(curves, i, &c);

    List_T *Lines = Tree2List(c->Simplexes);
    for(int j=0 ; j<List_Nbr(Lines); j++){
      Simplex *l;
      List_Read(Lines, j, &l);
      Simplex *l1 = Create_Simplex(l->V[0], l->VSUP[0], 0, 0);
      Simplex *l2 = Create_Simplex(l->VSUP[0], l->V[1], 0, 0);
      l1->iEnt = l2->iEnt = l->iEnt;
      l->VSUP[0]->Degree = 1;
      Tree_Add(c->Simplexes, &l1);
      Tree_Add(c->Simplexes, &l2);
      Tree_Suppress(c->Simplexes, &l);
      Free_Simplex(&l, 0);
    }
    List_Delete(Lines);
  }
  
  List_Delete(curves);

  Degre1();

  return 1;
}
