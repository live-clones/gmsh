// $Id: PartitionMesh.cpp,v 1.5 2005-10-27 15:06:26 remacle Exp $
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "CAD.h"
#include "Geo.h"
#include "Create.h"
#include "Interpolation.h"
#include "Context.h"
#include "BDS.h"
#include "PartitionMesh.h"
#include "OpenFile.h"
#include "MinMax.h"

#ifdef HAVE_METIS
extern "C"
{
#include "metis.h"
}
#endif

extern void Mesh_To_BDS(Mesh * m);
extern void BDS_To_Mesh_2(Mesh * m);
extern void BDS_To_Mesh(Mesh * m);

void DeleteMesh(Mesh * M)
{
  List_T *Curves = Tree2List(M->Curves);
  for(int i = 0; i < List_Nbr(Curves); i++) {
    Curve *c;
    List_Read(Curves, i, &c);
    Tree_Action(c->Simplexes, Free_Simplex);
    Tree_Delete(c->Simplexes);
    Tree_Action(c->SimplexesBase, Free_SimplexBase);
    Tree_Delete(c->SimplexesBase);
    c->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
    c->SimplexesBase = Tree_Create(sizeof(SimplexBase *), compareSimplexBase);
  }
  List_T *Surfaces = Tree2List(M->Surfaces);
  for(int i = 0; i < List_Nbr(Surfaces); i++) {
    Surface *s;
    List_Read(Surfaces, i, &s);
    Tree_Action(s->Simplexes, Free_Simplex);
    Tree_Delete(s->Simplexes);
    Tree_Action(s->SimplexesBase, Free_SimplexBase);
    Tree_Delete(s->SimplexesBase);
    s->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
    s->SimplexesBase = Tree_Create(sizeof(SimplexBase *), compareSimplexBase);
  }
  List_Delete(Surfaces);

  List_T *Volumes = Tree2List(M->Volumes);
  for(int i = 0; i < List_Nbr(Volumes); i++) {
    Volume *v;
    List_Read(Volumes, i, &v);
    Tree_Action(v->Simplexes, Free_Simplex);
    Tree_Delete(v->Simplexes);
    Tree_Action(v->SimplexesBase, Free_SimplexBase);
    Tree_Delete(v->SimplexesBase);
    v->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
    v->SimplexesBase = Tree_Create(sizeof(SimplexBase *), compareSimplexBase);
  }
  List_Delete(Volumes);
}

void PartitionMesh(Mesh * M, int NP)
{
  Msg(INFO, "moving the mesh to BDS");
  Mesh_To_BDS(M);
  BDS_Mesh *m = M->bds;
  Msg(INFO, "Partitioning");
  PartitionMesh(m, NP);
  Msg(INFO, "Moving back to the old data str");
  DeleteMesh(M);
  //BDS_To_Mesh(M);
  M->bds_mesh = new BDS_Mesh(*M->bds);
  BDS_To_Mesh_2(M);
  delete M->bds;
  //delete M->bds_mesh;
  M->bds = 0;
  //M->bds_mesh = 0;
  SetBoundingBox();
}

void PartitionMesh(BDS_Mesh * m, int NP)
{
#ifdef HAVE_METIS
  //NN = number of nodes of the graph
  int dim = (m->tets.size() == 0) ? 2 : 3;
  int NN = (dim == 2) ? m->triangles.size() : m->tets.size();

  Msg(INFO, "%d nodes in the graph", NN);

  int *partitionVector = new int[NN];
  int *xadj = new int[NN + 2];

  int totCount = 0;

  std::list< BDS_Triangle*>::iterator it2 = m->triangles.begin();
  std::list< BDS_Tet*>::iterator it3 = m->tets.begin();

  xadj[0] = 0;
  for(int i = 0; i < NN; i++) {
    int nbAdj = 0;
    if(dim == 2) {
      BDS_Triangle *t = *it2;
      t->partition = i;
      ++it2;
      nbAdj = (t->e1->numfaces() + t->e2->numfaces() + t->e3->numfaces() - 3);
      totCount += nbAdj;
    }
    else if(dim == 3) {
      BDS_Tet *t = *it3;
      t->partition = i;
      ++it3;
      nbAdj = (t->f1->numtets() + t->f2->numtets() + 
	       t->f3->numtets() + t->f4->numtets() - 4);
      totCount += nbAdj;
    }
    xadj[i + 1] = xadj[i] + nbAdj;
  }

  Msg(INFO, "Tot Count %d", totCount);

  it2 = m->triangles.begin();
  it3 = m->tets.begin();

  int *adjncy = new int[totCount + 1];

  int count = 0;

  for(int i = 0; i < NN; i++) {
    if(dim == 2) {
      BDS_Triangle *t = *it2;
      for(int j = 0; j < t->e1->numfaces(); j++) {
        BDS_Triangle *f = t->e1->faces(j);
        if(f != t)
          adjncy[count++] = f->partition;
      }
      for(int j = 0; j < t->e2->numfaces(); j++) {
        BDS_Triangle *f = t->e2->faces(j);
        if(f != t)
          adjncy[count++] = f->partition;
      }
      for(int j = 0; j < t->e3->numfaces(); j++) {
        BDS_Triangle *f = t->e3->faces(j);
        if(f != t)
          adjncy[count++] = f->partition;
      }
      ++it2;
    }
    else if(dim == 3) {
      BDS_Tet *t = *it3;
      BDS_Tet *o = t->f1->opposite_tet(t);
      if(o)
        adjncy[count++] = o->partition;
      o = t->f2->opposite_tet(t);
      if(o)
        adjncy[count++] = o->partition;
      o = t->f3->opposite_tet(t);
      if(o)
        adjncy[count++] = o->partition;
      o = t->f4->opposite_tet(t);
      if(o)
        adjncy[count++] = o->partition;
      ++it3;
    }
  }

  int wgtflag = 0;
  int numflag = 0;
  int options[4];
  options[0] = 0;
  int edgecut;
  METIS_PartGraphRecursive(&NN, xadj, adjncy, 0, 0, &wgtflag,
                           &numflag, &NP, options, &edgecut, partitionVector);
  delete[]xadj;
  delete[]adjncy;

  it2 = m->triangles.begin();
  it3 = m->tets.begin();

  for(int i = 0; i < NN; i++) {
    if(dim == 2) {
      BDS_Triangle *t = *it2;
      t->partition = partitionVector[i];
      ++it2;
    }
    else if(dim == 3) {
      BDS_Tet *t = *it3;
      t->partition = partitionVector[i];
      ++it3;
    }
  }

  delete[]partitionVector;
#endif
}
