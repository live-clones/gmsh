// $Id: Edge.cpp,v 1.6 2001-08-11 23:28:32 geuzaine Exp $

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Edge.h"
#include "Tools.h"

static int edges_quad[4][2] = { {0, 1},
                                {1, 2},
                                {2, 3},
                                {3, 0} };
static int edges_tetra[6][2] = { {0, 1},
                                 {1, 2},
                                 {2, 0},
                                 {3, 0},
                                 {3, 2},
                                 {3, 1} };
static int edges_non[3] = {2, 0, 1};

int compareedge (const void *a, const void *b){
  int i1, i2, j1, j2;
  Edge *q, *w;

  q = (Edge *) a;
  w = (Edge *) b;
  i1 = IMAX (q->V[0]->Num, q->V[1]->Num);
  i2 = IMAX (w->V[0]->Num, w->V[1]->Num);
  j1 = IMIN (q->V[0]->Num, q->V[1]->Num);
  j2 = IMIN (w->V[0]->Num, w->V[1]->Num);

  if (i1 < i2)
    return (1);
  if (i1 > i2)
    return (-1);
  if (j1 < j2)
    return (1);
  if (j1 > j2)
    return (-1);
  return 0;
}

int compareedge_angle (const void *a, const void *b){
  Edge *q, *w;

  q = (Edge *) a;
  w = (Edge *) b;
  if (q->a >= w->a)
    return (1);
  return (-1);
}

void EdgesContainer::AddEdges (Simplex * s, bool EdgesInVolume){
  int N, i, j;
  Edge E, *pE;
  int edges[6][2];

  if (s->V[3] && EdgesInVolume){
    N = 6;
    for (i = 0; i < N; i++)
      for (j = 0; j < 2; j++)
        edges[i][j] = edges_tetra[i][j];
  }
  else if (s->V[3]){
    N = 4;
    for (i = 0; i < N; i++)
      for (j = 0; j < 2; j++)
        edges[i][j] = edges_quad[i][j];
  }
  else if (s->V[2]){
    N = 3;
    for (i = 0; i < N; i++)
      for (j = 0; j < 2; j++)
        edges[i][j] = edges_tetra[i][j];
  }
  else{
    N = 1;
    for (i = 0; i < N; i++)
      for (j = 0; j < 2; j++)
        edges[i][j] = edges_tetra[i][j];
  }

  for (i = 0; i < N; i++){
    E.V[0] = s->V[edges[i][0]];
    E.V[1] = s->V[edges[i][1]];
    if ((pE = (Edge *) Tree_PQuery (AllEdges, &E))){
      List_Add (pE->Simplexes, &s);
      if (N == 3)
        pE->O[1] = s->V[edges_non[i]];
    }
    else{
      E.Simplexes = List_Create (2, 1, sizeof (Simplex *));
      if (N == 3)
        E.O[0] = s->V[edges_non[i]];
      if (N == 3)
        E.O[1] = NULL;
      List_Add (E.Simplexes, &s);
      E.newv = NULL;
      Tree_Replace (AllEdges, &E);
    }
  }
}

EdgesContainer::EdgesContainer (Tree_T * Simplexes, bool EdgesInVolume){
  AllEdges = Tree_Create (sizeof (Edge), compareedge);
  AddTree (Simplexes, EdgesInVolume);
}

EdgesContainer::EdgesContainer (List_T * Surfaces){
  AllEdges = Tree_Create (sizeof (Edge), compareedge);
  Surface *s;
  for (int i = 0; i < List_Nbr (Surfaces); i++){
      List_Read (Surfaces, i, &s);
      AddTree (s->Simplexes, false);
    }
}


void EdgesContainer::AddTree (Tree_T * Simplexes, bool EdgesInVolume){
  Simplex *s;
  List_T *temp = Tree2List (Simplexes);
  for (int i = 0; i < List_Nbr (temp); i++){
    List_Read (temp, i, &s);
    AddEdges (s, EdgesInVolume);
  }
  List_Delete (temp);
}

void Free_Edge (void *a, void *b)
{
  Edge *e = (Edge*)a;
  if(e->Liste)List_Delete(e->Liste);
  if(e->Simplexes)List_Delete(e->Simplexes);
  if(e->Points)List_Delete(e->Points);  
}

EdgesContainer::~EdgesContainer (){
  Tree_Action (AllEdges,Free_Edge);
  Tree_Delete (AllEdges);
}
bool EdgesContainer::Search (Vertex * v1, Vertex * v2){
  Edge E;
  E.V[0] = v1;
  E.V[1] = v2;
  if (!Tree_Search (AllEdges, &E))
    return false;
  return true;
}

void EdgesContainer::SwapEdge (Vertex * V[2]){
  Edge *e, E;
  Simplex *s, *s1, *s2;
  int i, j;
  Vertex *p[2], *q[2];

  E.V[0] = V[0];
  E.V[1] = V[1];
  e = (Edge *) Tree_PQuery (AllEdges, &E);
  E = *e;
  if (!e)
    return;
  List_Read (e->Simplexes, 0, &s1);
  List_Read (e->Simplexes, 1, &s2);

  for (i = 0; i < 3; i++){
    if (s1->S[i] == s2){
      s1->ExtractOppositeEdges (i, p, q);
      if (!s1->SwapEdge (i))
        return;
      Tree_Suppress (AllEdges, &E);
      E.V[0] = q[0];
      E.V[1] = q[1];
      Tree_Add (AllEdges, &E);
      
      E.V[0] = q[0];
      E.V[1] = p[0];
      e = (Edge *) Tree_PQuery (AllEdges, &E);
      for (j = 0; j < 2; j++){
        List_Read (e->Simplexes, j, &s);
        if (s == s2)
          List_Write (e->Simplexes, j, &s1);
      }
      
      E.V[0] = q[1];
      E.V[1] = p[1];
      e = (Edge *) Tree_PQuery (AllEdges, &E);
      for (j = 0; j < 2; j++){
        List_Read (e->Simplexes, j, &s);
        if (s == s1)
          List_Write (e->Simplexes, j, &s2);
      }
      V[0] = q[0];
      V[1] = q[1];
    }
  }
}
