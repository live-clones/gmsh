/* $Id: SwapEdge.cpp,v 1.2 2000-11-23 14:11:36 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"
#include "SwapPatterns.h"

extern Simplex MyNewBoundary;
extern int edges_tetra[6][2];


int TrouveCoquille (Simplex * s, Vertex * Ed[2],
		    List_T * Coquille, Tree_T * TreeSimpl,
		    Vertex * Contour[100]){
  Simplex *stack[256], *actual;
  Vertex *other[2];
  int K, i, N = 0;
  List_T *Edges = List_Create (12, 2, sizeof (Edge));
  Edge E;

  stack[N++] = s;

  while (N > 0){
    actual = stack[--N];
    if (!Tree_Search (TreeSimpl, &actual)){
      Tree_Add (TreeSimpl, &actual);
      if (actual->EdgeIn (Ed[0], Ed[1], other)){
	List_Add (Coquille, &actual);
	if (actual != s)
	  actual->Radius = -1.;
	E.V[0] = other[0];
	E.V[1] = other[1];
	List_Add (Edges, &E);
	for (i = 0; i < 4; i++){
	  if (actual->S[i] && actual->S[i] != &MyNewBoundary)
	    stack[N++] = actual->S[i];
	  else
	    return 0;
	}
      }
    }
  }

  List_Read (Edges, 0, &E);
  N = 0;
  Contour[N++] = E.V[0];
  Contour[N++] = E.V[1];
  List_Suppress (Edges, &E, compareedge);
  K = 0;

  while (List_Nbr (Edges)){
    if (K++ > Tree_Nbr (TreeSimpl))
      return 0;
    for (i = 0; i < List_Nbr (Edges); i++){
      List_Read (Edges, i, &E);
      if (!compareVertex (&Contour[N - 1], &E.V[0]) &&
	  compareVertex (&Contour[N - 2], &E.V[1])){
	Contour[N++] = E.V[1];
	List_Suppress (Edges, &E, compareedge);
	break;
      }
      if (!compareVertex (&Contour[N - 1], &E.V[1]) &&
	  compareVertex (&Contour[N - 2], &E.V[0])){
	Contour[N++] = E.V[0];
	List_Suppress (Edges, &E, compareedge);
	break;
      }
    }
    
  }
  if (!compareVertex (&Contour[0], &Contour[N - 1]))
    return N - 1;
  return 0;
}

bool FindBestPattern (int N, Vertex * Contour[100], Vertex * Ed[2],
		      List_T * Coquille, List_T * Pattern){
  int i, j, k, kk, tri[3];
  Simplex *s, *Pat[100];
  double old_volume, new_volume;
  double worst_tet_old, worst_tet_new;
  bool stop = false;
  SwapPattern *sp = NULL;
  SwapPattern3 *x3;
  SwapPattern4 *x4;
  SwapPattern5 *x5;
  SwapPattern6 *x6;
  SwapPattern7 *x7;
  SwapPatternN *xN;
  switch (N){
  case 3:
    x3 = new SwapPattern3;
    sp = x3;
    break;
  case 4:
    x4 = new SwapPattern4;
    sp = x4;
    break;
  case 5:
    if (stop)
      return false;
    x5 = new SwapPattern5;
    sp = x5;
    break;
  case 6:
    if (stop)
      return false;
    x6 = new SwapPattern6;
    sp = x6;
    break;
  case 7:
    if (stop)
      return false;
    x7 = new SwapPattern7;
    sp = x7;
    break;
  default:
    if (stop)
      return false;
    xN = new SwapPatternN (N);
    sp = xN;
    break;
  }

  old_volume = 0.0;
  worst_tet_old = 1.;
  int IENT;
  for (k = 0; k < List_Nbr (Coquille); k++){
    List_Read (Coquille, k, &s);
    IENT = s->iEnt;
    old_volume += fabs (s->Volume_Simplexe ());
    worst_tet_old = DMIN (worst_tet_old, s->GammaShapeMeasure ());
  }

  for (i = 0; i < sp->GetNbPatterns (); i++){
    for (j = 0; j < sp->GetNbRotations (i); j++){
      new_volume = 0.;
      worst_tet_new = 1.;
      kk = 0;
      for (k = 0; k < sp->GetNbTriangles (); k++){
	sp->GetTriangle (i, k, tri);
	s = Create_Simplex (Contour[tri[0]],
			    Contour[tri[1]],
			    Contour[tri[2]],
			    Ed[0]);
	s->iEnt = IENT;
	Pat[kk++] = s;
	new_volume += fabs (s->Volume_Simplexe ());
	worst_tet_new = DMIN (worst_tet_new, s->GammaShapeMeasure ());
	s = Create_Simplex (Contour[tri[0]],
			    Contour[tri[1]],
			    Contour[tri[2]],
			    Ed[1]);
	s->iEnt = IENT;
	Pat[kk++] = s;
	new_volume += fabs (s->Volume_Simplexe ());
	worst_tet_new = DMIN (worst_tet_new, s->GammaShapeMeasure ());
      }
      if (fabs (new_volume - old_volume) > 1.e-5 * fabs (new_volume + old_volume))
	Msg(INFO, "Edge swapping failed");
      if (fabs (new_volume - old_volume) > 1.e-5 * fabs (new_volume + old_volume)
	  || worst_tet_new < worst_tet_old){
	for (k = 0; k < 2 * sp->GetNbTriangles (); k++){
	  delete Pat[k];
	}
      }
      else{
	for (k = 0; k < List_Nbr (Pattern); k++){
	  List_Read (Pattern, k, &s);
	  delete s;
	}
	List_Reset (Pattern);
	for (k = 0; k < 2 * sp->GetNbTriangles (); k++){
	  List_Add (Pattern, &Pat[k]);
	}
	worst_tet_old = worst_tet_new;
      }
    }
  }
  
  delete sp;
  return true ;
}


bool SwapEdge (Mesh * M, Volume * v, Simplex * s, int iEdge){
  int i;
  Vertex *Contour[100];
  Vertex *Ed[2];
  Simplex *simp;
  Tree_T *TreeSimpl = Tree_Create (sizeof (Simplex *), compareSimplex);
  List_T *Coquille = List_Create (10, 10, sizeof (Simplex *));
  Ed[0] = s->V[edges_tetra[iEdge][0]];
  Ed[1] = s->V[edges_tetra[iEdge][1]];
  int N = TrouveCoquille (s, Ed, Coquille, TreeSimpl, Contour);

  List_T *Pattern = List_Create (2 * N - 4, 1, sizeof (Simplex *));

  FindBestPattern (N, Contour, Ed, Coquille, Pattern);

  if (List_Nbr (Pattern)){
    for (i = 0; i < List_Nbr (Coquille); i++){
      List_Read (Coquille, i, &simp);
      Tree_Suppress (v->Simplexes, &simp);
      Tree_Suppress (TreeSimpl, &simp);
    }
    for (i = 0; i < List_Nbr (Pattern); i++){
      List_Read (Pattern, i, &simp);
      Tree_Add (v->Simplexes, &simp);
      Tree_Add (TreeSimpl, &simp);
    }
    Link_Simplexes (NULL, TreeSimpl /*v->Simplexes */ );
  }
  Tree_Delete (TreeSimpl);
  List_Delete (Coquille);
  List_Delete (Pattern);
  return true ;
}

int GetWorstEdge (Simplex * s, EdgesContainer & ec, bool order){
  Vertex *v11, *v12;
  Vertex *v21, *v22;
  v11 = s->V[edges_tetra[0][0]];
  v12 = s->V[edges_tetra[0][1]];
  v21 = s->V[edges_tetra[4][0]];
  v22 = s->V[edges_tetra[4][1]];
  Vertex d11 = *(v12) - *(v11);
  Vertex d12 = *(v22) - *(v21);
  d12.norme ();
  d11.norme ();
  double prosc1 = fabs (d11 * d12);

  v11 = s->V[edges_tetra[1][0]];
  v12 = s->V[edges_tetra[1][1]];
  v21 = s->V[edges_tetra[3][0]];
  v22 = s->V[edges_tetra[3][1]];
  Vertex d21 = *(v12) - *(v11);
  Vertex d22 = *(v22) - *(v21);
  d22.norme ();
  d21.norme ();
  double prosc2 = fabs (d21 * d22);

  v11 = s->V[edges_tetra[2][0]];
  v12 = s->V[edges_tetra[2][1]];
  v21 = s->V[edges_tetra[5][0]];
  v22 = s->V[edges_tetra[5][1]];
  Vertex d31 = *(v12) - *(v11);
  Vertex d32 = *(v22) - *(v21);
  d32.norme ();
  d31.norme ();
  double prosc3 = fabs (d31 * d32);

  if (prosc1 < prosc2 && prosc1 < prosc3){
    if (!order && !ec.Search (s->V[edges_tetra[0][0]], s->V[edges_tetra[0][1]]))
      return 0;
    if (!ec.Search (s->V[edges_tetra[4][0]], s->V[edges_tetra[4][1]]))
      return 4;
    if (!ec.Search (s->V[edges_tetra[0][0]], s->V[edges_tetra[0][1]]))
      return 0;
    return -1;
  }
  if (prosc2 < prosc1 && prosc2 < prosc3){
    if (!order && !ec.Search (s->V[edges_tetra[1][0]], s->V[edges_tetra[1][1]]))
      return 1;
    if (!ec.Search (s->V[edges_tetra[3][0]], s->V[edges_tetra[3][1]]))
      return 3;
    if (!ec.Search (s->V[edges_tetra[1][0]], s->V[edges_tetra[1][1]]))
      return 1;
    return -1;
  }
  if (prosc3 < prosc2 && prosc3 < prosc1){
    if (!order && !ec.Search (s->V[edges_tetra[2][0]], s->V[edges_tetra[2][1]]))
      return 2;
    if (!ec.Search (s->V[edges_tetra[5][0]], s->V[edges_tetra[5][1]]))
      return 5;
    if (!ec.Search (s->V[edges_tetra[2][0]], s->V[edges_tetra[2][1]]))
      return 2;
    return -1;
  }
  return -1;
}

void SwapEdges3D (Mesh * M, Volume * v, double GammaPrescribed, bool order){
  List_T *list = Tree2List (v->Simplexes);
  List_T *srfs = Tree2List (M->Surfaces);
  if (!List_Nbr (srfs))
    return;
  EdgesContainer ec (srfs);
  Simplex *s;
  Progress (102);
  for (int i = 0; i < List_Nbr (list); i++){
    if (i % 100 == 1)
      Progress ((100 * i) / List_Nbr (list));
    List_Read (list, i, &s);
    if (s->GammaShapeMeasure () < GammaPrescribed){
      int iEdge = GetWorstEdge (s, ec, order);
      if (iEdge >= 0)
	SwapEdge (M, v, s, iEdge);
    }
  }
  Progress (-1);
  List_Delete (srfs);
  List_Delete (list);
}
