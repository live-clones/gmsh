// $Id: 2D_Elliptic.cpp,v 1.20 2004-12-17 04:12:13 geuzaine Exp $
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

extern Mesh *THEM;

static void getVertices(Vertex *start, Vertex *end, Curve *c[4], List_T *list)
{
  for(int i = 0; i < 4; i++) {
    if(!compareVertex(&c[i]->beg, &start) && 
       !compareVertex(&c[i]->end, &end)){
      for(int j = 0; j < List_Nbr(c[i]->Vertices); j++)
	List_Add(list, List_Pointer(c[i]->Vertices, j));
      return;
    }
    if(!compareVertex(&c[i]->beg, &end) && 
       !compareVertex(&c[i]->end, &start)){
      for(int j = 0; j < List_Nbr(c[i]->Vertices); j++)
	List_Add(list, List_Pointer(c[i]->Vertices, List_Nbr(c[i]->Vertices) - 1 - j));
      return;
    }
  }
}

int MeshEllipticSurface(Surface * sur)
{
  if(sur->Method != ELLIPTIC)
    return 0;

  if(List_Nbr(sur->Generatrices) != 4 ||
     List_Nbr(sur->TrsfPoints) != 4)
    return 0;

  Curve *GG[4];  
  Vertex *S[4];
  for(int i = 0; i < 4; i++) {
    List_Read(sur->Generatrices, i, &GG[i]);
    List_Read(sur->TrsfPoints, i, &S[i]);
  }

  List_T *l1 = List_Create(20, 10, sizeof(Vertex *));
  getVertices(S[0], S[1], GG, l1);
  List_T *l2 = List_Create(20, 10, sizeof(Vertex *));
  getVertices(S[1], S[2], GG, l2);
  List_T *l3 = List_Create(20, 10, sizeof(Vertex *));
  getVertices(S[2], S[3], GG, l3);
  List_T *l4 = List_Create(20, 10, sizeof(Vertex *));
  getVertices(S[3], S[0], GG, l4);

  int N1 = List_Nbr(l1);
  int N2 = List_Nbr(l2);
  int N3 = List_Nbr(l3);
  int N4 = List_Nbr(l4);
  if(!N1 || !N2 || !N3 || !N4 || (N1 != N3) || (N2 != N4)) {
    Msg(WARNING, "Wrong definition of Elliptic Surface %d", sur->Num);
    List_Delete(l1);
    List_Delete(l2);
    List_Delete(l3);
    List_Delete(l4);
    return 0;
  }

  sur->Nu = N1;
  sur->Nv = N2;
  Vertex **list = (Vertex **) Malloc(N1 * N2 * sizeof(Vertex *));

  for(int i = 0; i < N1; i++) {
    for(int j = 0; j < N2; j++) {
      if(i == 0) {
        List_Read(l4, N2 - j - 1, &list[i + N1 * j]);
      }
      else if(i == N1 - 1) {
        List_Read(l2, j, &list[i + N1 * j]);
      }
      else if(j == 0) {
        List_Read(l1, i, &list[i + N1 * j]);
      }
      else if(j == N2 - 1) {
        List_Read(l3, N1 - i - 1, &list[i + N1 * j]);
      }
      else {
        double u = 1. - 2. * (double)i / double (N1 - 1);
        double v = 1. - 2. * (double)j / double (N2 - 1);
        double x = 0.25 * ((S[0]->Pos.X * (1 + u) * (1. + v)) +
			   (S[1]->Pos.X * (1 - u) * (1. + v)) +
			   (S[2]->Pos.X * (1 - u) * (1. - v)) +
			   (S[3]->Pos.X * (1 + u) * (1. - v)));
        double y = 0.25 * ((S[0]->Pos.Y * (1 + u) * (1. + v)) +
			   (S[1]->Pos.Y * (1 - u) * (1. + v)) +
			   (S[2]->Pos.Y * (1 - u) * (1. - v)) +
			   (S[3]->Pos.Y * (1 + u) * (1. - v)));
        double z = 0.25 * ((S[0]->Pos.Z * (1 + u) * (1. + v)) +
			   (S[1]->Pos.Z * (1 - u) * (1. + v)) +
			   (S[2]->Pos.Z * (1 - u) * (1. - v)) +
			   (S[3]->Pos.Z * (1 + u) * (1. - v)));
        double lc = 0.25 * ((S[0]->lc * (1 + u) * (1. + v)) +
			    (S[1]->lc * (1 - u) * (1. + v)) +
			    (S[2]->lc * (1 - u) * (1. - v)) +
			    (S[3]->lc * (1 + u) * (1. - v)));
        list[i + N1 * j] = Create_Vertex(++THEM->MaxPointNum, x, y, z, lc, 0.0);
	Tree_Insert(sur->Vertices, &list[i + N1 * j]);
        List_Add(sur->TrsfVertices, &list[i + N1 * j]);
      }
    }
  }

  List_Delete(l1);
  List_Delete(l2);
  List_Delete(l3);
  List_Delete(l4);

  int k = 0;
  while(1) {
    k++;
    if(k > 1000)
      break;
    for(int i = 1; i < N1 - 1; i++) {
      for(int j = 1; j < N2 - 1; j++) {
        Vertex *v11 = list[i - 1 + N1 * (j - 1)];
        Vertex *v12 = list[i + N1 * (j - 1)];
        Vertex *v13 = list[i + 1 + N1 * (j - 1)];
        Vertex *v21 = list[i - 1 + N1 * (j)];
	Vertex *v22 = list[i + N1 * (j)];
	Vertex *v23 = list[i + 1 + N1 * (j)];
	Vertex *v31 = list[i - 1 + N1 * (j + 1)];
	Vertex *v32 = list[i + N1 * (j + 1)];
	Vertex *v33 = list[i + 1 + N1 * (j + 1)];
	
	double alpha = 0.25 * (DSQR(v23->Pos.X - v21->Pos.X) +
			       DSQR(v23->Pos.Y - v21->Pos.Y));
        double gamma = 0.25 * (DSQR(v32->Pos.X - v12->Pos.X) +
			       DSQR(v32->Pos.Y - v12->Pos.Y));
        double beta = 0.0625 * ((v32->Pos.X - v12->Pos.X) *
				(v23->Pos.X - v21->Pos.X) +
				(v32->Pos.Y - v12->Pos.Y) *
				(v23->Pos.Y - v21->Pos.Y));

        v22->Pos.X = 0.5 * (alpha * (v32->Pos.X + v12->Pos.X) +
                            gamma * (v23->Pos.X + v21->Pos.X) -
                            2. * beta * (v33->Pos.X - v13->Pos.X -
                                         v31->Pos.X + v11->Pos.X))
          / (alpha + gamma);
        v22->Pos.Y = 0.5 * (alpha * (v32->Pos.Y + v12->Pos.Y) +
                            gamma * (v23->Pos.Y + v21->Pos.Y) -
                            2. * beta * (v33->Pos.Y - v13->Pos.Y -
                                         v31->Pos.Y + v11->Pos.Y))
          / (alpha + gamma);
        v22->Pos.Z = 0.5 * (alpha * (v32->Pos.Z + v12->Pos.Z) +
                            gamma * (v23->Pos.Z + v21->Pos.Z) -
                            2. * beta * (v33->Pos.Z - v13->Pos.Z -
                                         v31->Pos.Z + v11->Pos.Z))
          / (alpha + gamma);
      }
    }
  }
  for(int i = 0; i < N1 - 1; i++) {
    for(int j = 0; j < N2 - 1; j++) {
      if(sur->Recombine) {
        Quadrangle *q = Create_Quadrangle
          (list[(i) + N1 * (j)], list[(i + 1) + N1 * (j)],
           list[(i + 1) + N1 * (j + 1)], list[i + N1 * (j + 1)]);
        q->iEnt = sur->Num;
        Tree_Add(sur->Quadrangles, &q);
      }
      else {
	Simplex *simp = Create_Simplex(list[(i) + N1 * (j)], list[(i + 1) + N1 * (j)],
				       list[(i) + N1 * (j + 1)], NULL);
        simp->iEnt = sur->Num;
        Tree_Add(sur->Simplexes, &simp);
	
        simp = Create_Simplex(list[(i + 1) + N1 * (j + 1)],
			      list[(i) + N1 * (j + 1)], list[(i + 1) + N1 * (j)],
			      NULL);
        simp->iEnt = sur->Num;
        Tree_Add(sur->Simplexes, &simp);
      }
    }
  }

  Free(list);

  return 1;
}
