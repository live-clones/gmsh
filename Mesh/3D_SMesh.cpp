// $Id: 3D_SMesh.cpp,v 1.17 2003-03-02 16:10:28 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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

/*  
  Maillage transfini volumique

                     a0   s0 s1  f0  s0 s1 s5 s4              s6      
   s7        s6      a1   s1 s2  f1  s1 s2 s6 s4              *       
     *-------*       a2   s3 s2  f2  s3 s2 s6 s7             /|\      
     |\s4    |\      a3   s0 s3  f3  s0 s3 s7 s4            / | \     
     | *-------* s5  a4   s4 s5  f4  s0 s1 s2 s3      s7/s4/  |s2\    
     | |   s2| |     a5   s5 s6  f5  s4 s5 s6 s7          *---*---* s5
  s3 *-|-----* |     a6   s7 s6                           |  / \  |   
      \|      \|     a7   s4 s7                           | /   \ |   
       *-------*     a8   s0 s4                           |/     \|   
 v w  s0       s1    a9   s1 s5                           *-------*     
  \|                 a10  s2 s6                  v w    s3/s0     s1    
   *--u              a11  s3 s7                   \|                 
                                                   *--u              


  Remarque : La definition d'un volume prismatique doit se faire dans l'ordre
             donne sur le schema. (degenerescence obligatoirement en s0/s4)

*/

#include "Gmsh.h"
#include "Mesh.h"
#include "Interpolation.h"
#include "Create.h"

extern Mesh *THEM;

int index2d(int flag, int M, int N, int m, int n)
{
  switch (flag) {
  case 0:
    return (n + N * m);
  case 1:
    return (M * N - M * (n + 1) + m);
  case 2:
    return (M * N - (n + N * m) - 1);
  case 3:
    return (M + n * M - m - 1);
  case 4:
    return (N + m * N - n - 1);
  case 5:
    return (M * N - (m + M * n) - 1);
  case 6:
    return (M * N - N * (m + 1) + n);
  case 7:
    return (m + M * n);
  default:
    return 0;
  }
}

void index_uv(int flag, Vertex * ver, double *u, double *v)
{
  switch (flag) {
  case 0:
    *u = ver->us[0];
    *v = ver->us[1];
    break;
  case 1:
    *u = ver->us[1];
    *v = 1. - ver->us[0];
    break;
  case 2:
    *u = 1. - ver->us[0];
    *v = 1. - ver->us[1];
    break;
  case 3:
    *u = 1. - ver->us[1];
    *v = ver->us[0];
    break;
  case 4:
    *u = ver->us[0];
    *v = 1. - ver->us[1];
    break;
  case 5:
    *u = 1. - ver->us[1];
    *v = 1. - ver->us[0];
    break;
  case 6:
    *u = 1. - ver->us[0];
    *v = ver->us[1];
    break;
  case 7:
    *u = ver->us[1];
    *v = ver->us[0];
    break;
  }
}

#define CREATE_HEX Create_Hexahedron(list[(i)   + N1*(j)   + N1*N2*(k)],   \
                                     list[(i+1) + N1*(j)   + N1*N2*(k)],   \
                                     list[(i+1) + N1*(j+1) + N1*N2*(k)],   \
                                     list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                     list[(i)   + N1*(j)   + N1*N2*(k+1)], \
                                     list[(i+1) + N1*(j)   + N1*N2*(k+1)], \
                                     list[(i+1) + N1*(j+1) + N1*N2*(k+1)], \
                                     list[(i)   + N1*(j+1) + N1*N2*(k+1)])

#define CREATE_PRISM_1 Create_Prism(list[(i)   + N1*(j)   + N1*N2*(k)],   \
                                    list[(i+1) + N1*(j)   + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i)   + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i)   + N1*(j+1) + N1*N2*(k+1)])

#define CREATE_PRISM_2 Create_Prism(list[(i+1) + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i+1) + N1*(j)   + N1*N2*(k)],   \
                                    list[(i+1) + N1*(j+1) + N1*N2*(k+1)], \
                                    list[(i)   + N1*(j+1) + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j)   + N1*N2*(k+1)])

#define CREATE_SIM_1 Create_Simplex(list[(i)   + N1*(j)   + N1*N2*(k)],   \
                                    list[(i+1) + N1*(j)   + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i)   + N1*(j)   + N1*N2*(k+1)])

#define CREATE_SIM_2 Create_Simplex(list[(i+1) + N1*(j)   + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i)   + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j)   + N1*N2*(k+1)])

#define CREATE_SIM_3 Create_Simplex(list[(i)   + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k+1)])

#define CREATE_SIM_4 Create_Simplex(list[(i+1) + N1*(j)   + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i+1) + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j+1) + N1*N2*(k)])

#define CREATE_SIM_5 Create_Simplex(list[(i)   + N1*(j+1) + N1*N2*(k)],   \
                                    list[(i)   + N1*(j+1) + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j+1) + N1*N2*(k)])

#define CREATE_SIM_6 Create_Simplex(list[(i+1) + N1*(j)   + N1*N2*(k+1)], \
                                    list[(i)   + N1*(j+1) + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j+1) + N1*N2*(k+1)], \
                                    list[(i+1) + N1*(j+1) + N1*N2*(k)])

int MeshTransfiniteVolume(Volume * vol)
{
  int i, j, k, flag, nbs, nbp, nbg;
  int nbtet = 0, nbpri = 0, nbhex = 0;
  Surface *G[6], *GG[6];
  Vertex V, **vexist, *pV, *CP[4], **list;
  double u, v, w, dum;
  int F_flag[6];
  int N1, N2, N3;
  Vertex *F[6], *C[12], *Stmp[8], *S[8];
  Hexahedron *hexa;
  Prism *prism;
  Simplex *simp;
  int NbFacesFound = 0;

  static int tab1hex[] = { 0, 1, 5, 4, 
			   1, 2, 6, 5,
			   3, 2, 6, 7, 
			   0, 3, 7, 4, 
			   0, 1, 2, 3, 
			   4, 5, 6, 7 };

  static int tab2[] = { 0, 1, 2, 3,
			1, 2, 3, 0,
			2, 3, 0, 1,
			3, 0, 1, 2,
			3, 2, 1, 0,
			2, 1, 0, 3, 
			1, 0, 3, 2,
			0, 3, 2, 1 };

  if(vol->Method != TRANSFINI)
    return (0);

  nbs = List_Nbr(vol->Surfaces);

  if(nbs == 5)
    nbp = 6;
  else if(nbs == 6)
    nbp = 8;
  else
    return (0);

  Msg(STATUS3, "Meshing Volume %d", vol->Num);

  for(i = 0; i < 6; i++)
    G[i] = NULL;

  for(i = 0; i < nbp; i++) {
    V.Num = vol->ipar[i];
    pV = &V;
    if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, &pV)) == NULL) {
      Msg(WARNING, "Unknown control point %d in Transfinite Volume %d",
          V.Num, vol->Num);
      return (0);
    }
    else {
      Stmp[i] = *vexist;
    }
  }

  if(nbp == 8) {
    for(i = 0; i < 8; i++)
      S[i] = Stmp[i];
  }
  else if(nbp == 6) {
    S[0] = S[3] = Stmp[0];
    S[1] = Stmp[1];
    S[2] = Stmp[2];
    S[4] = S[7] = Stmp[3];
    S[5] = Stmp[4];
    S[6] = Stmp[5];
  }

  /*
     for(i=0;i<8;i++) printf("S[%d]=%d \n", i, S[i]->Num);
   */

  for(i = 0; i < nbs; i++)
    List_Read(vol->Surfaces, i, &GG[i]);

  for(i = 0; i < nbs; i++) {
    nbg = List_Nbr(GG[i]->Generatrices);

    for(j = 0; j < nbg; j++) {
      V.Num = GG[i]->ipar[j];
      pV = &V;
      if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, &pV)) == NULL) {
        Msg(WARNING, "Unknown control point %d in Transfinite Surface %d",
            V.Num, GG[i]->Num);
        return (0);
      }
      else {
        CP[j] = *vexist;
      }
    }

    if(nbg == 3)
      CP[3] = CP[0];

    for(flag = 0; flag < 8; flag++) {
      for(k = 0; k < 6; k++) {
        if(S[tab1hex[4 * k]]->Num == CP[tab2[4 * flag]]->Num &&
           S[tab1hex[4 * k + 1]]->Num == CP[tab2[4 * flag + 1]]->Num &&
           S[tab1hex[4 * k + 2]]->Num == CP[tab2[4 * flag + 2]]->Num &&
           S[tab1hex[4 * k + 3]]->Num == CP[tab2[4 * flag + 3]]->Num) {
          G[k] = GG[i];
          F_flag[k] = flag;
          NbFacesFound++;
          /*
             printf("TR3D: (k=%d) face trouvee %d (flag = %d) : nodes %d %d %d %d \n", 
             k,GG[i]->Num, flag, 
             S[tab1hex[4*k  ]]->Num, 
             S[tab1hex[4*k+1]]->Num,
             S[tab1hex[4*k+2]]->Num,
             S[tab1hex[4*k+3]]->Num);
           */
        }
      }
    }
  }

  if(nbs == 6 && NbFacesFound != 6) {
    Msg(WARNING, "Wrong definition of hexahedric Transfinite Volume %d",
        vol->Num);
    return (0);
  }

  if(nbs == 5 && NbFacesFound != 5) {
    Msg(WARNING1, "Wrong definition of prismatic Transfinite Volume %d",
        vol->Num);
    Msg(WARNING2, "Possibly because the first and fourth points are not the");
    Msg(WARNING3, "degenerated ones");
    return (0);
  }

  if(nbs == 6) {
    for(i = 0; i < 6; i++) {
      if(G[i] == NULL) {
        Msg(WARNING, "Wrong definition of hexahedric Transfinite Volume %d",
            vol->Num);
        return (0);
      }
    }
  }
  else if(nbs == 5) {
    for(i = 0; i < 6; i++) {
      if(i != 3) {
        if(G[i] == NULL) {
          Msg(WARNING1, "Wrong definition of prismatic Transfinite Volume %d",
              vol->Num);
          Msg(WARNING2,
              "Possibly because the first and fourth points are not the");
          Msg(WARNING3, "degenerated ones");
          return (0);
        }
      }
    }
  }


  N1 = (F_flag[4] % 2 == 0) ? G[4]->Nu : G[4]->Nv;
  N2 = (F_flag[4] % 2 == 0) ? G[4]->Nv : G[4]->Nu;
  N3 = (F_flag[0] % 2 == 0) ? G[0]->Nv : G[0]->Nu;

  /*
     printf("N1(%d) N2(%d) N3(%d)\n", N1,N2,N3);
   */

  list = (Vertex **) Malloc(N1 * N2 * N3 * sizeof(Vertex *));

  for(i = 0; i < N1; i++) {

    for(j = 0; j < N2; j++) {

      List_Read(G[4]->TrsfVertices, index2d(F_flag[4], N1, N2, i, 0), &C[0]);
      List_Read(G[4]->TrsfVertices, index2d(F_flag[4], N1, N2, N1 - 1, j), &C[1]);
      List_Read(G[4]->TrsfVertices, index2d(F_flag[4], N1, N2, i, N2 - 1), &C[2]);
      List_Read(G[4]->TrsfVertices, index2d(F_flag[4], N1, N2, 0, j), &C[3]);
      List_Read(G[5]->TrsfVertices, index2d(F_flag[5], N1, N2, i, 0), &C[4]);
      List_Read(G[5]->TrsfVertices, index2d(F_flag[5], N1, N2, N1 - 1, j), &C[5]);
      List_Read(G[5]->TrsfVertices, index2d(F_flag[5], N1, N2, i, N2 - 1), &C[6]);
      List_Read(G[5]->TrsfVertices, index2d(F_flag[5], N1, N2, 0, j), &C[7]);

      List_Read(G[4]->TrsfVertices, index2d(F_flag[4], N1, N2, i, j), &F[4]);
      List_Read(G[5]->TrsfVertices, index2d(F_flag[5], N1, N2, i, j), &F[5]);

      index_uv(F_flag[4], F[4], &u, &v);

      for(k = 0; k < N3; k++) {

        List_Read(G[0]->TrsfVertices, index2d(F_flag[0], N1, N3, 0, k), &C[8]);
        List_Read(G[0]->TrsfVertices, index2d(F_flag[0], N1, N3, N1 - 1, k), &C[9]);
        List_Read(G[2]->TrsfVertices, index2d(F_flag[2], N1, N3, N1 - 1, k), &C[10]);
        List_Read(G[2]->TrsfVertices, index2d(F_flag[2], N1, N3, 0, k), &C[11]);

        List_Read(G[0]->TrsfVertices, index2d(F_flag[0], N1, N3, i, k), &F[0]);
        List_Read(G[1]->TrsfVertices, index2d(F_flag[1], N2, N3, j, k), &F[1]);
        List_Read(G[2]->TrsfVertices, index2d(F_flag[2], N1, N3, i, k), &F[2]);
        if(nbs == 6)
          List_Read(G[3]->TrsfVertices, index2d(F_flag[3], N2, N3, j, k), &F[3]);
        else if(nbs == 5)
          F[3] = C[8];

        index_uv(F_flag[0], F[0], &dum, &w);

        if(i && j && k && i != N1 - 1 && j != N2 - 1 && k != N3 - 1) {
          V = TransfiniteHex(*F[0], *F[1], *F[2], *F[3], *F[4], *F[5],
                             *C[0], *C[1], *C[2], *C[3], *C[4], *C[5],
                             *C[6], *C[7], *C[8], *C[9], *C[10], *C[11],
                             *S[0], *S[1], *S[2], *S[3], *S[4], *S[5], *S[6],
                             *S[7], u, v, w);
          list[i + N1 * j + N1 * N2 * k] =
            Create_Vertex(++THEM->MaxPointNum, V.Pos.X, V.Pos.Y, V.Pos.Z,
                          V.lc, 0.0);
          /*
             printf(" NEW node : %f %f %f\n", list[i+N1*j+N1*N2*k]->Pos.X, 
             list[i+N1*j+N1*N2*k]->Pos.Y, list[i+N1*j+N1*N2*k]->Pos.Z);
           */
        }

        else if(!i) {
          list[i + N1 * j + N1 * N2 * k] = F[3];
        }
        else if(!j) {
          list[i + N1 * j + N1 * N2 * k] = F[0];
        }
        else if(!k) {
          list[i + N1 * j + N1 * N2 * k] = F[4];
        }
        else if(i == N1 - 1) {
          list[i + N1 * j + N1 * N2 * k] = F[1];
        }
        else if(j == N2 - 1) {
          list[i + N1 * j + N1 * N2 * k] = F[2];
        }
        else if(k == N3 - 1) {
          list[i + N1 * j + N1 * N2 * k] = F[5];
        }

      }
    }
  }

  for(i = 0; i < N1; i++) {
    for(j = 0; j < N2; j++) {
      for(k = 0; k < N3; k++) {
        Tree_Replace(THEM->Vertices, &list[i + N1 * j + N1 * N2 * k]);
        Tree_Replace(vol->Vertices, &list[i + N1 * j + N1 * N2 * k]);
      }
    }
  }

  if(nbs == 6) {
    for(i = 0; i < N1 - 1; i++) {
      for(j = 0; j < N2 - 1; j++) {
        for(k = 0; k < N3 - 1; k++) {
          if(G[0]->Recombine && G[1]->Recombine && G[2]->Recombine &&
             G[3]->Recombine && G[4]->Recombine && G[5]->Recombine) {
            hexa = CREATE_HEX;
            hexa->iEnt = vol->Num;
            Tree_Replace(vol->Hexahedra, &hexa);

            nbhex++;
          }
          else if(!G[0]->Recombine && G[1]->Recombine && !G[2]->Recombine &&
                  G[3]->Recombine && G[4]->Recombine && G[5]->Recombine) {
            prism = Create_Prism(list[(i) + N1 * (j) + N1 * N2 * (k)],
                                 list[(i + 1) + N1 * (j) + N1 * N2 * (k)],
                                 list[(i) + N1 * (j) + N1 * N2 * (k + 1)],
                                 list[(i) + N1 * (j + 1) + N1 * N2 * (k)],
                                 list[(i + 1) + N1 * (j + 1) + N1 * N2 * (k)],
                                 list[(i) + N1 * (j + 1) + N1 * N2 * (k + 1)]);
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);

            prism = Create_Prism(list[(i + 1) + N1 * (j) + N1 * N2 * (k + 1)],
                                 list[(i) + N1 * (j) + N1 * N2 * (k + 1)],
                                 list[(i + 1) + N1 * (j) + N1 * N2 * (k)],
                                 list[(i + 1) + N1 * (j + 1) + N1 * N2 * (k + 1)],
                                 list[(i) + N1 * (j + 1) + N1 * N2 * (k + 1)],
                                 list[(i + 1) + N1 * (j + 1) + N1 * N2 * (k)]);
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);

            nbpri += 2;
          }
          else if(G[0]->Recombine && !G[1]->Recombine && G[2]->Recombine &&
                  !G[3]->Recombine && G[4]->Recombine && G[5]->Recombine) {
            prism = Create_Prism(list[(i + 1) + N1 * (j) + N1 * N2 * (k)],
                                 list[(i + 1) + N1 * (j + 1) + N1 * N2 * (k)],
                                 list[(i + 1) + N1 * (j) + N1 * N2 * (k + 1)],
                                 list[(i) + N1 * (j) + N1 * N2 * (k)],
                                 list[(i) + N1 * (j + 1) + N1 * N2 * (k)],
                                 list[(i) + N1 * (j) + N1 * N2 * (k + 1)]);
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);

            prism =
              Create_Prism(list[(i + 1) + N1 * (j + 1) + N1 * N2 * (k + 1)],
                           list[(i + 1) + N1 * (j) + N1 * N2 * (k + 1)],
                           list[(i + 1) + N1 * (j + 1) + N1 * N2 * (k)],
                           list[(i) + N1 * (j + 1) + N1 * N2 * (k + 1)],
                           list[(i) + N1 * (j) + N1 * N2 * (k + 1)],
                           list[(i) + N1 * (j + 1) + N1 * N2 * (k)]);
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);

            nbpri += 2;
          }
          else if(G[0]->Recombine && G[1]->Recombine && G[2]->Recombine &&
                  G[3]->Recombine && !G[4]->Recombine && !G[5]->Recombine) {
            prism = CREATE_PRISM_1;
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);
            prism = CREATE_PRISM_2;
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);

            nbpri += 2;
          }
          else if(!G[0]->Recombine && !G[1]->Recombine && !G[2]->Recombine &&
                  !G[3]->Recombine && !G[4]->Recombine && !G[5]->Recombine) {
            simp = CREATE_SIM_1;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_2;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_3;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_4;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_5;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_6;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);

            nbtet += 6;
          }
          else {
            Msg(WARNING, "Wrong surface recombining in Transfinite Volume %d",
                vol->Num);
            return (0);
          }
        }
      }
    }
  }
  else if(nbs == 5) {
    for(j = 0; j < N2 - 1; j++) {
      for(k = 0; k < N3 - 1; k++) {
        if((G[0]->Recombine && G[1]->Recombine && G[2]->Recombine &&
            G[4]->Recombine && G[5]->Recombine) ||
           (G[0]->Recombine && G[1]->Recombine && G[2]->Recombine &&
            !G[4]->Recombine && !G[5]->Recombine)) {
          prism = Create_Prism(list[N1 * (j) + N1 * N2 * (k)],
                               list[1 + N1 * (j) + N1 * N2 * (k)],
                               list[1 + N1 * (j + 1) + N1 * N2 * (k)],
                               list[N1 * (j) + N1 * N2 * (k + 1)],
                               list[1 + N1 * (j) + N1 * N2 * (k + 1)],
                               list[1 + N1 * (j + 1) + N1 * N2 * (k + 1)]);
          prism->iEnt = vol->Num;
          Tree_Replace(vol->Prisms, &prism);

          nbpri++;
        }
        else if(!G[0]->Recombine && !G[1]->Recombine && !G[2]->Recombine &&
                !G[4]->Recombine && !G[5]->Recombine) {
          simp = Create_Simplex(list[+N1 * (j) + N1 * N2 * (k)],
                                list[1 + N1 * (j) + N1 * N2 * (k)],
                                list[1 + N1 * (j + 1) + N1 * N2 * (k)],
                                list[+N1 * (j) + N1 * N2 * (k + 1)]);
          simp->iEnt = vol->Num;
          Tree_Replace(vol->Simplexes, &simp);

          simp = Create_Simplex(list[1 + N1 * (j) + N1 * N2 * (k)],
                                list[1 + N1 * (j + 1) + N1 * N2 * (k)],
                                list[+N1 * (j) + N1 * N2 * (k + 1)],
                                list[1 + N1 * (j) + N1 * N2 * (k + 1)]);
          simp->iEnt = vol->Num;
          Tree_Replace(vol->Simplexes, &simp);

          simp = Create_Simplex(list[+N1 * (j) + N1 * N2 * (k + 1)],
                                list[1 + N1 * (j + 1) + N1 * N2 * (k + 1)],
                                list[1 + N1 * (j) + N1 * N2 * (k + 1)],
                                list[1 + N1 * (j + 1) + N1 * N2 * (k)]);
          simp->iEnt = vol->Num;
          Tree_Replace(vol->Simplexes, &simp);

          nbtet += 2;
        }
        else {
          Msg(WARNING, "Wrong surface recombining in Transfinite Volume %d",
              vol->Num);
          return (0);
        }
      }
    }
    for(i = 1; i < N1 - 1; i++) {
      for(j = 0; j < N2 - 1; j++) {
        for(k = 0; k < N3 - 1; k++) {
          if(G[0]->Recombine && G[1]->Recombine && G[2]->Recombine &&
             G[4]->Recombine && G[5]->Recombine) {
            hexa = CREATE_HEX;
            hexa->iEnt = vol->Num;
            Tree_Replace(vol->Hexahedra, &hexa);

            nbhex++;
          }
          else if(G[0]->Recombine && G[1]->Recombine && G[2]->Recombine &&
                  !G[4]->Recombine && !G[5]->Recombine) {
            prism = CREATE_PRISM_1;
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);
            prism = CREATE_PRISM_2;
            prism->iEnt = vol->Num;
            Tree_Replace(vol->Prisms, &prism);

            nbpri += 2;
          }
          else if(!G[0]->Recombine && !G[1]->Recombine && !G[2]->Recombine &&
                  !G[4]->Recombine && !G[5]->Recombine) {
            simp = CREATE_SIM_1;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_2;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_3;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_4;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_5;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);
            simp = CREATE_SIM_6;
            simp->iEnt = vol->Num;
            Tree_Replace(vol->Simplexes, &simp);

            nbtet += 6;
          }
          else {
            Msg(WARNING, "Wrong surface recombining in Transfinite Volume %d",
                vol->Num);
            return (0);
          }
        }
      }
    }
  }

  return (1);

}
