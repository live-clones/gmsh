// $Id: 3D_Divide.cpp,v 1.15 2002-05-18 07:18:02 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

/* Routine de division des elements tetraedriques
   ou triangulaires

        1 triangle -> 4 triangles ;
        1 tetraedre -> noeuds 1 2 3 4
                       faces  1 4 2
                              1
*/

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"

extern Mesh * THEM;
extern int    edges_tetra[6][2];

static Tree_T *New_Edges = NULL;
static int    IENT;

typedef struct {
  int i;
  int j;
}nxn;

static int are_exists (Vertex *v1, Vertex *v2){
  nxn nx;
  nx.i = IMAX(v1->Num,v2->Num);
  nx.j = IMIN(v1->Num,v2->Num);
  return Tree_Search(New_Edges,&nx);
}

static void are_add (Vertex *v1, Vertex *v2){
  nxn nx;
  nx.i = IMAX(v1->Num,v2->Num);
  nx.j = IMIN(v1->Num,v2->Num);
  Tree_Add(New_Edges,&nx);
}

static int compnxn (const void *a, const void *b){
  nxn *q,*w;
  q = (nxn*)a;
  w = (nxn*)b;
  if(q->i>w->i)return 1;
  if(q->i<w->i)return -1;
  if(q->j>w->j)return 1;
  if(q->j<w->j)return -1;
  return 0;
}

static int FF,FV,EV,EE,FE,EEE,EEEE;
void Remise_A_Zero (void){
  FF=EE=FV=EV=FE=EEE=EEEE=0;
}

void Impression_Resultats (void){

  Msg(INFO1, "===================================================");
  Msg(INFO2, "Surface coherence results (number of intersections)");
  Msg(INFO2, "%d EV, %d EE, %d FV, %d FF, %d FE, %d EEE, %d EEEE",
      EV, EE, FV, FF, FE, EEE, EEEE);
  Msg(INFO3, "===================================================");
	  
}

int PARLE = 0;

void cut_prism (Vertex * v1, Vertex * v2, Vertex * v3,
                Vertex * v4, Vertex * v5, Vertex * v6,
                Tree_T * newpoints, Tree_T * AddedTet){

  Simplex *news;
  Vertex *e1;

  //Msg(INFO, "Prism cut");

  /* test des meilleures aretes a creer */
  /*
     if(!are_exists(v1,v6) &&
     !are_exists(v4,v3)){

     if(fabs(angle_3p(v1,v4,v6)) >
     fabs(angle_3p(v4,v6,v3))){
     are_add(v4,v3);
     }
     else{
     are_add(v1,v6);
     }
     }

     if(!are_exists(v3,v5) &&
     !are_exists(v6,v2)){

     if(fabs(angle_3p(v6,v5,v2)) >
     fabs(angle_3p(v5,v2,v3))){
     are_add(v5,v3);
     }
     else{
     are_add(v2,v6);
     }
     }

     if(!are_exists(v1,v5) &&
     !are_exists(v4,v2)){

     if(fabs(angle_3p(v1,v4,v5)) >
     fabs(angle_3p(v4,v5,v2))){
     are_add(v4,v2);
     }
     else{
     are_add(v1,v5);
     }
     }
   */
  if (!are_exists (v1, v5) &&   //OK
      !are_exists (v6, v2) &&
      !are_exists (v6, v1)){
    news = Create_Simplex (v1, v2, v3, v4);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v5, v6, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v2, v4, v5, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    are_add (v4, v2);
    are_add (v5, v3);
    are_add (v4, v3);
  }
  else if (!are_exists (v1, v5) &&      //OK
           !are_exists (v3, v5) &&
           !are_exists (v1, v6)){
    news = Create_Simplex (v1, v2, v3, v4);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v5, v6, v2);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v2, v6, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    are_add (v4, v2);
    are_add (v2, v6);
    are_add (v4, v3);
  }
  else if (!are_exists (v1, v5) &&      //OK
           !are_exists (v3, v5) &&
           !are_exists (v4, v3)){
    news = Create_Simplex (v1, v2, v3, v6);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v5, v6, v2);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v2, v4, v6, v1);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    are_add (v4, v2);
    are_add (v2, v6);
    are_add (v6, v1);
  }
  else if (!are_exists (v4, v2) &&      //OK
           !are_exists (v6, v2) &&
           !are_exists (v6, v1)){
    news = Create_Simplex (v1, v2, v3, v5);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v5, v6, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v1, v4, v5, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    are_add (v5, v1);
    are_add (v5, v3);
    are_add (v4, v3);
  }
  else if (!are_exists (v4, v2) &&      //OK
           !are_exists (v6, v2) &&
           !are_exists (v4, v3)){
    news = Create_Simplex (v1, v2, v3, v5);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v5, v6, v1);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v1, v3, v5, v6);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    are_add (v5, v1);
    are_add (v5, v3);
    are_add (v6, v1);
  }
  else if (!are_exists (v4, v2) &&      //OK
           !are_exists (v3, v5) &&
           !are_exists (v4, v3)){
    news = Create_Simplex (v1, v2, v3, v6);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v4, v5, v6, v1);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (v1, v2, v5, v6);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    are_add (v5, v1);
    are_add (v2, v6);
    are_add (v6, v1);
  }

  else if (are_exists (v6, v1) &&
           are_exists (v5, v3) &&
           are_exists (v4, v2)) {
    Msg(INFO, "Found steiner prism 1!");
    
    e1 = Create_Vertex 
      (++THEM->MaxPointNum,
       (v1->Pos.X + v2->Pos.X + v3->Pos.X + v4->Pos.X + v5->Pos.X + v6->Pos.X) / 6.,
       (v1->Pos.Y + v2->Pos.Y + v3->Pos.Y + v4->Pos.Y + v5->Pos.Y + v6->Pos.Y) / 6.,
       (v1->Pos.Z + v2->Pos.Z + v3->Pos.Z + v4->Pos.Z + v5->Pos.Z + v6->Pos.Z) / 6.,
       (v1->lc + v2->lc + v3->lc + v4->lc + v5->lc + v6->lc) / 6.,
       0.0);
    Tree_Add (newpoints, &e1);
    news = Create_Simplex (e1, v6, v1, v4);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v6, v1, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v5, v3, v6);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v5, v3, v2);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v4, v2, v1);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v4, v2, v5);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
  }

  else if (are_exists (v4, v3) &&
           are_exists (v6, v2) &&
           are_exists (v5, v1)){
    Msg(INFO, "Found steiner prism 2!");

    e1 = Create_Vertex 
      (++THEM->MaxPointNum,
       (v1->Pos.X + v2->Pos.X + v3->Pos.X + v4->Pos.X + v5->Pos.X + v6->Pos.X) / 6.,
       (v1->Pos.Y + v2->Pos.Y + v3->Pos.Y + v4->Pos.Y + v5->Pos.Y + v6->Pos.Y) / 6.,
       (v1->Pos.Z + v2->Pos.Z + v3->Pos.Z + v4->Pos.Z + v5->Pos.Z + v6->Pos.Z) / 6.,
       (v1->lc + v2->lc + v3->lc + v4->lc + v5->lc + v6->lc) / 6.,
       0.0);
    Tree_Add (newpoints, &e1);
    news = Create_Simplex (e1, v4, v3, v6);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v4, v3, v1);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v6, v2, v5);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v6, v2, v3);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v5, v1, v4);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    news = Create_Simplex (e1, v5, v1, v2);
    news->iEnt = IENT;
    Tree_Add (AddedTet, &news);
    
  }
  else{
    Msg(GERROR, "Uncoherent prism");
  }
}


void cut_tetraedre (Intersection * pI, Tree_T * AddedTet, Tree_T * TetDel,
                    Tree_T * newpoints){
  int i;
  nxn nx;
  Simplex *s;
  Vertex *common, *other1, *other2, *lonely, *e1, *e2, *point1, *point2, *point3, *point4;
  Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8;

  if (!New_Edges)
    New_Edges = Tree_Create (sizeof (nxn), compnxn);

  IENT = pI->s->iEnt;

  /* 1 tetraedre -> 2 tetraedres */

  if ((pI->NbEdge == 0) && (pI->NbFace == 0)){
  }
  else if (pI->NbEdge == 1 && pI->NbFace == 0){

    Tree_Add (TetDel, &pI->s);
    
    
    EV++;
    if (pI->E[0] == 0){
      /* Verifie */
      s = Create_Simplex (pI->s->V[2], pI->s->V[3], pI->s->V[0], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s = Create_Simplex (pI->s->V[1], pI->s->V[3], pI->s->V[2], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
    if (pI->E[0] == 1){
      /* Verifie */
      s = Create_Simplex (pI->s->V[0], pI->s->V[3], pI->s->V[2], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[3], pI->s->V[1], pI->s->V[0], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
    if (pI->E[0] == 2){
      /* Verifie */
      s = Create_Simplex (pI->s->V[0], pI->s->V[1], pI->s->V[3], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->s->V[3], pI->s->V[2], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
    if (pI->E[0] == 3){
      /* Verifie */
      s = Create_Simplex (pI->s->V[0], pI->s->V[1], pI->s->V[2], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->s->V[2], pI->s->V[3], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
    if (pI->E[0] == 4){
      /* Verifie */
      s = Create_Simplex (pI->s->V[2], pI->s->V[0], pI->s->V[1], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n",
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->s->V[3], pI->s->V[0], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
    if (pI->E[0] == 5){
      /* Verifie */
      s = Create_Simplex (pI->s->V[0], pI->s->V[3], pI->s->V[2], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n",
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[0], pI->s->V[1], pI->s->V[2], pI->VE[0]);
      if (PARLE)
        printf ("ajout %d %d %d %d\n", 
		s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
  }
  else if (pI->NbVertex == 1 && pI->NbFace == 1){
    FV++;
    Tree_Add (TetDel, &pI->s);
    s = Create_Simplex (pI->V[0], pI->VF[0], pI->F[0]->V[0], pI->F[0]->V[1]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    s = Create_Simplex (pI->V[0], pI->VF[0], pI->F[0]->V[1], pI->F[0]->V[2]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    s = Create_Simplex (pI->V[0], pI->VF[0], pI->F[0]->V[2], pI->F[0]->V[0]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
  }

  /* DU CUL LES COPINES
     TROIS ARETES QUI PENETRENT LA MEME FACE
     TRIPLETTE, TRIPLE PENETRATION */
  
  else if (pI->NbEdge == 3){
    EEE++;
    /*
      printf("tet %d %d %d %d\n",
              pI->s->V[0]->Num,pI->s->V[1]->Num,pI->s->V[2]->Num,pI->s->V[3]->Num);
      printf("ed %d %d\n",pI->s->V[edges_tetra[pI->E[0]][0]]->Num,
      pI->s->V[edges_tetra[pI->E[0]][1]]->Num);
      printf("ed %d %d\n",pI->s->V[edges_tetra[pI->E[1]][0]]->Num,
      pI->s->V[edges_tetra[pI->E[1]][1]]->Num);
      printf("ed %d %d\n",pI->s->V[edges_tetra[pI->E[2]][0]]->Num,
      pI->s->V[edges_tetra[pI->E[2]][1]]->Num);
    */
    Tree_Add (TetDel, &pI->s);
    v4 = pI->VE[0];
    v5 = pI->VE[1];
    v6 = pI->VE[2];
    if (pI->E[0] == 0 && pI->E[1] == 1 && pI->E[2] == 5){
      v1 = pI->s->V[0];
      v2 = pI->s->V[2];
      v3 = pI->s->V[3];
      v7 = pI->s->V[1];
    }
    else if (pI->E[0] == 0 && pI->E[1] == 2 && pI->E[2] == 3){
      v1 = pI->s->V[1];
      v2 = pI->s->V[2];
      v3 = pI->s->V[3];
      v7 = pI->s->V[0];
    }
    else if (pI->E[0] == 1 && pI->E[1] == 2 && pI->E[2] == 4){
      v1 = pI->s->V[1];
      v2 = pI->s->V[0];
      v3 = pI->s->V[3];
      v7 = pI->s->V[2];
    }
    else if (pI->E[0] == 3 && pI->E[1] == 4 && pI->E[2] == 5){
      v1 = pI->s->V[0];
      v2 = pI->s->V[2];
      v3 = pI->s->V[1];
      v7 = pI->s->V[3];
    }
    else{
      Msg(GERROR, "Three edges cut without common point!");
      return;
    }
    
    s = Create_Simplex (v4, v5, v6, v7);
    Tree_Add (AddedTet, &s);
    cut_prism (v1, v2, v3, v4, v5, v6, newpoints, AddedTet);
    
  }

  else if (pI->NbFace == 2){
    FF++;
    point3 = NULL;
    Tree_Add (TetDel, &pI->s);
    if (PARLE){
      printf ("simp  = %d %d %d %d\n", 
	      pI->s->V[0]->Num, pI->s->V[1]->Num, pI->s->V[2]->Num, pI->s->V[3]->Num);
      printf ("are   = %d %d\n", 
	      pI->VF[0]->Num, pI->VF[1]->Num);
      printf ("face1 = %d %d %d\n", 
	      pI->F[0]->V[0]->Num, pI->F[0]->V[1]->Num, pI->F[0]->V[2]->Num);
      printf ("face2 = %d %d %d\n", 
	      pI->F[1]->V[0]->Num, pI->F[1]->V[1]->Num, pI->F[1]->V[2]->Num);
    }
    for (i = 0; i < 4; i++){
      if (compareVertex (&pI->F[0]->V[0], &pI->s->V[i]) &&
          compareVertex (&pI->F[0]->V[1], &pI->s->V[i]) &&
          compareVertex (&pI->F[0]->V[2], &pI->s->V[i]))
        point1 = pI->s->V[i];
      else if (compareVertex (&pI->F[1]->V[0], &pI->s->V[i]) &&
               compareVertex (&pI->F[1]->V[1], &pI->s->V[i]) &&
               compareVertex (&pI->F[1]->V[2], &pI->s->V[i]))
        point2 = pI->s->V[i];
      else if (point3)
        point4 = pI->s->V[i];
      else
        point3 = pI->s->V[i];
    }
    s = Create_Simplex (point3, point4, pI->VF[0], pI->VF[1]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    if (PARLE)
      printf ("simp  = %d %d %d %d\n",
	      s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
    s = Create_Simplex (point1, point4, pI->VF[0], pI->VF[1]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    if (PARLE)
      printf ("simp  = %d %d %d %d\n",
	      s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
    s = Create_Simplex (point1, point3, pI->VF[0], pI->VF[1]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    if (PARLE)
      printf ("simp  = %d %d %d %d\n",
	      s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
    s = Create_Simplex (point2, point4, point1, pI->VF[0]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    if (PARLE)
      printf ("simp  = %d %d %d %d\n",
	      s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
    s = Create_Simplex (point2, point3, point1, pI->VF[0]);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    if (PARLE)
      printf ("simp  = %d %d %d %d\n",
	      s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);
  }

  else if (pI->NbEdge == 2){
    EE++;
    Tree_Add (TetDel, &pI->s);
    if (pI->E[0] == 1 && pI->E[1] == 3){
      s = Create_Simplex (pI->s->V[0], pI->VE[1], pI->s->V[1], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[0], pI->VE[1], pI->s->V[2], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->VE[1], pI->s->V[3], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[2], pI->VE[1], pI->s->V[3], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      return;
    }
    else if (pI->E[0] == 2 && pI->E[1] == 5){
      s = Create_Simplex (pI->s->V[0], pI->VE[1], pI->s->V[1], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->VE[1], pI->s->V[2], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[0], pI->VE[1], pI->s->V[3], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[2], pI->VE[1], pI->s->V[3], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      return;
    }
    
    else if (pI->E[0] == 0 && pI->E[1] == 4){
      s = Create_Simplex (pI->s->V[0], pI->VE[1], pI->s->V[2], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->VE[1], pI->s->V[2], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[0], pI->VE[1], pI->s->V[3], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (pI->s->V[1], pI->VE[1], pI->s->V[3], pI->VE[0]);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      return;
    }
    
    e1 = pI->VE[0];
    e2 = pI->VE[1];
    
    if (!compareVertex (&pI->s->V[edges_tetra[pI->E[0]][0]], 
			&pI->s->V[edges_tetra[pI->E[1]][0]])){
      common = pI->s->V[edges_tetra[pI->E[0]][0]];
      other1 = pI->s->V[edges_tetra[pI->E[0]][1]];
      other2 = pI->s->V[edges_tetra[pI->E[1]][1]];
    }
    else if (!compareVertex (&pI->s->V[edges_tetra[pI->E[0]][0]],
			     &pI->s->V[edges_tetra[pI->E[1]][1]])){
      common = pI->s->V[edges_tetra[pI->E[0]][0]];
      other1 = pI->s->V[edges_tetra[pI->E[0]][1]];
      other2 = pI->s->V[edges_tetra[pI->E[1]][0]];
    }
    else if (!compareVertex (&pI->s->V[edges_tetra[pI->E[0]][1]],
			     &pI->s->V[edges_tetra[pI->E[1]][0]])){
      common = pI->s->V[edges_tetra[pI->E[0]][1]];
      other1 = pI->s->V[edges_tetra[pI->E[0]][0]];
      other2 = pI->s->V[edges_tetra[pI->E[1]][1]];
    }
    else if (!compareVertex (&pI->s->V[edges_tetra[pI->E[0]][1]],
			     &pI->s->V[edges_tetra[pI->E[1]][1]])){
      common = pI->s->V[edges_tetra[pI->E[0]][1]];
      other1 = pI->s->V[edges_tetra[pI->E[0]][0]];
      other2 = pI->s->V[edges_tetra[pI->E[1]][0]];
    }
    
    for (i = 0; i < 4; i++){
      if (compareVertex (&pI->s->V[i], &common) &&
          compareVertex (&pI->s->V[i], &other1) &&
          compareVertex (&pI->s->V[i], &other2))
        lonely = pI->s->V[i];
    }
    
    nx.i = IMAX (e1->Num, other2->Num);
    nx.j = IMIN (e1->Num, other2->Num);
    
    if (Tree_Search (New_Edges, &nx)){
      s = Create_Simplex (e1, other1, other2, lonely);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (e2, e1, common, lonely);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (e2, other2, e1, lonely);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
    else{
      nx.i = IMAX (e2->Num, other1->Num);
      nx.j = IMIN (e2->Num, other1->Num);
      Tree_Add (New_Edges, &nx);
      s = Create_Simplex (e1, other1, e2, lonely);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (e2, e1, common, lonely);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
      s = Create_Simplex (e2, other1, other2, lonely);
      s->iEnt = IENT;
      Tree_Add (AddedTet, &s);
    }
  }
  else if (pI->NbFace == 1 && pI->NbEdge == 1){
    FE++;
    
    Tree_Add (TetDel, &pI->s);
    for (i = 0; i < 4; i++)
      if (compareVertex (&pI->s->V[i], &pI->F[0]->V[0]) &&
          compareVertex (&pI->s->V[i], &pI->F[0]->V[1]) &&
          compareVertex (&pI->s->V[i], &pI->F[0]->V[2]))
        v1 = pI->s->V[i];
    v2 = NULL;
    v3 = NULL;
    
    for (i = 0; i < 4; i++){
      if (compareVertex (&pI->s->V[i], &v1)){
        if (compareVertex (&pI->s->V[i], &pI->s->V[edges_tetra[pI->E[0]][0]]) &&
            compareVertex (&pI->s->V[i], &pI->s->V[edges_tetra[pI->E[0]][1]])){
          if (v2)
            v3 = pI->s->V[i];
          else
            v2 = pI->s->V[i];
        }
        else{
          v4 = pI->s->V[i];
        }
      }
    }
    
    e1 = pI->VE[0];
    e2 = pI->VF[0];
    
    s = Create_Simplex (e1, e2, v3, v4);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    s = Create_Simplex (e1, e2, v2, v4);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    s = Create_Simplex (e1, e2, v2, v3);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    s = Create_Simplex (e1, v1, v2, v3);
    s->iEnt = IENT;
    Tree_Add (AddedTet, &s);
    
  }
  else if (pI->NbEdge == 4){
    EEEE++;
    
    // Allez j-f il faut le faire !
    
    Tree_Add (TetDel, &pI->s);
    if (pI->E[0] == 1 && pI->E[1] == 2 && pI->E[2] == 3 && pI->E[3] == 5){
      v1 = pI->s->V[0];
      v2 = pI->s->V[1];
      v3 = pI->s->V[2];
      v4 = pI->s->V[3];
      v5 = pI->VE[1];
      v6 = pI->VE[2];
      v7 = pI->VE[0];
      v8 = pI->VE[3];
    }
    else if (pI->E[0] == 0 && pI->E[1] == 2 && pI->E[2] == 4 && pI->E[3] == 5){
      v1 = pI->s->V[1];
      v2 = pI->s->V[2];
      v3 = pI->s->V[0];
      v4 = pI->s->V[3];
      v5 = pI->VE[0];
      v6 = pI->VE[3];
      v7 = pI->VE[1];
      v8 = pI->VE[2];
    }
    else if (pI->E[0] == 0 && pI->E[1] == 1 && pI->E[2] == 3 && pI->E[3] == 4){
      v1 = pI->s->V[0];
      v2 = pI->s->V[2];
      v3 = pI->s->V[1];
      v4 = pI->s->V[3];
      v5 = pI->VE[0];
      v6 = pI->VE[2];
      v7 = pI->VE[1];
      v8 = pI->VE[3];
    }
    else{
      Msg(GERROR, "Incoherent 4 edges intersection");
      return;
    }
    cut_prism (v8, v4, v6, v7, v3, v5, newpoints, AddedTet);
    cut_prism (v2, v8, v7, v1, v6, v5, newpoints, AddedTet);
  }
  else{
    Msg(GERROR, "Error on cut %d %d %d", pI->NbVertex, pI->NbEdge, pI->NbFace);
  }
}





