// $Id: 2D_Elliptic.cpp,v 1.19 2004-05-27 20:49:03 geuzaine Exp $
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

int MeshEllipticSurface(Surface * sur)
{
  int i, j, k, nb, N1, N2, N3, N4;
  Curve *GG[444];
  Vertex **list;
  double alpha, beta, gamma, u, v, lc, x, y, z;
  Vertex *S[4], *v11, *v12, *v13, *v21, *v22, *v23, *v31, *v32, *v33;
  List_T *l1, *l2, *l3, *l4;

  if(sur->Method != ELLIPTIC)
    return 0;

  nb = List_Nbr(sur->Generatrices);

  if(nb < 4)
    return 0;
  
  if(List_Nbr(sur->TrsfPoints) != 4)
    return 0;

  for(i = 0; i < nb; i++) {
    List_Read(sur->Generatrices, i, &GG[i]);
    List_Read(sur->TrsfPoints, i, &S[i]);
  }

  N1 = N2 = N3 = N4 = 0;

  // step 1
  l1 = List_Create(20, 10, sizeof(Vertex *));
  for(i = 0; i < nb; i++) {
    if(!compareVertex(&GG[i]->beg, &S[0])) {
      j = i;
      do {
        if(!List_Nbr(l1))
          List_Add(l1, List_Pointer(GG[j]->Vertices, 0));
        for(k = 1; k < List_Nbr(GG[j]->Vertices); k++)
          List_Add(l1, List_Pointer(GG[j]->Vertices, k));
        j = (j + 1 < nb) ? j + 1 : 0;
        if(j == i){
	  Msg(WARNING, "Wrong definition of Elliptic Surface %d", sur->Num);
	  List_Delete(l1);
          return 0;
	}
      }
      while(compareVertex(&GG[j]->beg, &S[1]));
    }
  }

  // step 2
  l2 = List_Create(20, 10, sizeof(Vertex *));
  for(i = 0; i < nb; i++) {
    if(!compareVertex(&GG[i]->beg, &S[1])) {
      j = i;
      do {
        if(!List_Nbr(l2))
          List_Add(l2, List_Pointer(GG[j]->Vertices, 0));
        for(k = 1; k < List_Nbr(GG[j]->Vertices); k++)
          List_Add(l2, List_Pointer(GG[j]->Vertices, k));
        j = (j + 1 < nb) ? j + 1 : 0;
        if(j == i){
	  Msg(WARNING, "Wrong definition of Elliptic Surface %d", sur->Num);
	  List_Delete(l1);
	  List_Delete(l2);
          return 0;
	}
      }
      while(compareVertex(&GG[j]->beg, &S[2]));
    }
  }

  // step 3
  l3 = List_Create(20, 10, sizeof(Vertex *));
  for(i = 0; i < nb; i++) {
    if(!compareVertex(&GG[i]->beg, &S[2])) {
      j = i;
      do {
        if(!List_Nbr(l3))
          List_Add(l3, List_Pointer(GG[j]->Vertices, 0));
        for(k = 1; k < List_Nbr(GG[j]->Vertices); k++)
          List_Add(l3, List_Pointer(GG[j]->Vertices, k));
        j = (j + 1 < nb) ? j + 1 : 0;
        if(j == i){
	  Msg(WARNING, "Wrong definition of Elliptic Surface %d", sur->Num);
	  List_Delete(l1);
	  List_Delete(l2);
	  List_Delete(l3);
          return 0;
	}
      }
      while(compareVertex(&GG[j]->beg, &S[3]));
    }
  }

  // step 4
  l4 = List_Create(20, 10, sizeof(Vertex *));
  for(i = 0; i < nb; i++) {
    if(!compareVertex(&GG[i]->beg, &S[3])) {
      j = i;
      do {
        if(!List_Nbr(l4))
          List_Add(l4, List_Pointer(GG[j]->Vertices, 0));
        for(k = 1; k < List_Nbr(GG[j]->Vertices); k++)
          List_Add(l4, List_Pointer(GG[j]->Vertices, k));
        j = (j + 1 < nb) ? j + 1 : 0;
        if(j == i){
	  Msg(WARNING, "Wrong definition of Elliptic Surface %d", sur->Num);
	  List_Delete(l1);
	  List_Delete(l2);
	  List_Delete(l3);
	  List_Delete(l4);
          return 0;
	}
      }
      while(compareVertex(&GG[j]->beg, &S[0]));
    }
  }

  N1 = List_Nbr(l1);
  N2 = List_Nbr(l2);
  N3 = List_Nbr(l3);
  N4 = List_Nbr(l4);
  if(N1 != N3 || N2 != N4) {
    Msg(WARNING, "Wrong definition of Elliptic Surface %d", sur->Num);
    List_Delete(l1);
    List_Delete(l2);
    List_Delete(l3);
    List_Delete(l4);
    return 0;
  }

  sur->Nu = N1;
  sur->Nv = N2;
  list = (Vertex **) Malloc(N1 * N2 * sizeof(Vertex *));

  for(i = 0; i < N1; i++) {
    for(j = 0; j < N2; j++) {
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
        u = 1. - 2. * (double)i / double (N1 - 1);
        v = 1. - 2. * (double)j / double (N2 - 1);
        x = 0.25 * ((S[0]->Pos.X * (1 + u) * (1. + v)) +
                    (S[1]->Pos.X * (1 - u) * (1. + v)) +
                    (S[2]->Pos.X * (1 - u) * (1. - v)) +
                    (S[3]->Pos.X * (1 + u) * (1. - v)));
        y = 0.25 * ((S[0]->Pos.Y * (1 + u) * (1. + v)) +
                    (S[1]->Pos.Y * (1 - u) * (1. + v)) +
                    (S[2]->Pos.Y * (1 - u) * (1. - v)) +
                    (S[3]->Pos.Y * (1 + u) * (1. - v)));
        z = 0.25 * ((S[0]->Pos.Z * (1 + u) * (1. + v)) +
                    (S[1]->Pos.Z * (1 - u) * (1. + v)) +
                    (S[2]->Pos.Z * (1 - u) * (1. - v)) +
                    (S[3]->Pos.Z * (1 + u) * (1. - v)));
        lc = 0.25 * ((S[0]->lc * (1 + u) * (1. + v)) +
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

  k = 0;
  while(1) {
    k++;
    if(k > 1000)
      break;
    for(i = 1; i < N1 - 1; i++) {
      for(j = 1; j < N2 - 1; j++) {
        v11 = list[i - 1 + N1 * (j - 1)];
        v12 = list[i + N1 * (j - 1)];
        v13 = list[i + 1 + N1 * (j - 1)];
        v21 = list[i - 1 + N1 * (j)];
        v22 = list[i + N1 * (j)];
        v23 = list[i + 1 + N1 * (j)];
        v31 = list[i - 1 + N1 * (j + 1)];
        v32 = list[i + N1 * (j + 1)];
        v33 = list[i + 1 + N1 * (j + 1)];

        alpha = 0.25 * (DSQR(v23->Pos.X - v21->Pos.X) +
                        DSQR(v23->Pos.Y - v21->Pos.Y));
        gamma = 0.25 * (DSQR(v32->Pos.X - v12->Pos.X) +
                        DSQR(v32->Pos.Y - v12->Pos.Y));
        beta = 0.0625 * ((v32->Pos.X - v12->Pos.X) *
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
  for(i = 0; i < N1 - 1; i++) {
    for(j = 0; j < N2 - 1; j++) {
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
