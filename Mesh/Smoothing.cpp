// $Id: Smoothing.cpp,v 1.6 2001-08-11 23:28:32 geuzaine Exp $

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"


void AmelioreSurface_EliminationTripet (Surface * surf, Mesh * m, Tree_T * tnxe){
  int i, j, k;
  List_T *lnxe = Tree2List (tnxe);
  Vertex *v1, *v2, *v3;
  List_T *ListNoeuds = List_Create (2, 1, sizeof (Vertex *));
  Simplex *s[3], *news;
  NXE nxe;
  bool ok;

  for (i = 0; i < List_Nbr (lnxe); i++){
    List_Read (lnxe, i, &nxe);
    if (List_Nbr (nxe.Liste) == 3){
      ok = true;
      if (nxe.v->ListCurves)
        ok = false;
      else{
        for (j = 0; j < 3; j++){
          List_Read (nxe.Liste, j, &s[j]);
          if (!Tree_Search (surf->Simplexes, &s[j]))
            ok = false;
          for (k = 0; k < 3; k++)
            if (compareVertex (&nxe.v, &s[j]->V[k]))
              List_Insert (ListNoeuds, &s[j]->V[k], compareVertex);
        }
      }
      if (ok){
        List_Read (ListNoeuds, 0, &v1);
        List_Read (ListNoeuds, 1, &v2);
        List_Read (ListNoeuds, 2, &v3);
        news = Create_Simplex (v1, v2, v3, 0);
        Tree_Suppress (surf->Simplexes, &s[0]);
        Tree_Suppress (surf->Simplexes, &s[1]);
        Tree_Suppress (surf->Simplexes, &s[2]);
        Tree_Suppress (m->Vertices, &nxe.v);
        Tree_Add (surf->Simplexes, &news);
      }
      List_Reset (ListNoeuds);
    }
  }
  List_Delete (ListNoeuds);
  List_Delete (lnxe);
}


void ActionLiss (void *data, void *dummy){
  List_T *nodes;

  NXE *pnxe;
  Simplex *s;
  double X, Y, Z, Sum;
  int i, j;


  pnxe = (NXE *) data;

  /* On Ne Lisse Point Les Points sur les courbes (quelle horreur) */
  if (pnxe->v->ListCurves)
    return;
  nodes = List_Create (2, 2, sizeof (Vertex *));

  X = Y = Z = Sum = 0.0;
  double volume_before = 0.0;
  double min_quality_old = 1.0;
  for (i = 0; i < List_Nbr (pnxe->Liste); i++){
    List_Read (pnxe->Liste, i, &s);
    min_quality_old = DMIN (min_quality_old, s->GammaShapeMeasure ());
    volume_before += s->Volume_Simplexe ();
    /* On Ne Lisse Point Les Points sur les surfaces quand les volumes sont mailles */
    if (s->V[3] && pnxe->v->ListSurf)
      return;
    for (j = 0; j < 4; j++){
      if (s->V[j] && compareVertex (&pnxe->v, &s->V[j])){
        Sum += 0.5;
        X += s->V[j]->Pos.X * 0.5;
        Y += s->V[j]->Pos.Y * 0.5;
        Z += s->V[j]->Pos.Z * 0.5;
      }
    }
  }
  
  double xold = pnxe->v->Pos.X;
  double yold = pnxe->v->Pos.Y;
  double zold = pnxe->v->Pos.Z;
  double a = 0.5;

  if (Sum != 0.0){
    pnxe->v->Pos.X = a * (X / Sum) + (1. - a) * pnxe->v->Pos.X;
    pnxe->v->Pos.Y = a * (Y / Sum) + (1. - a) * pnxe->v->Pos.Y;
    pnxe->v->Pos.Z = a * (Z / Sum) + (1. - a) * pnxe->v->Pos.Z;
  }

  double min_quality_new = 1.0;
  for (i = 0; i < List_Nbr (pnxe->Liste); i++){
    List_Read (pnxe->Liste, i, &s);
    min_quality_new = DMIN (min_quality_new, s->GammaShapeMeasure ());
  }
  
  double volume_after = 0.0;
  for (i = 0; i < List_Nbr (pnxe->Liste); i++){
    List_Read (pnxe->Liste, i, &s);
    volume_after += s->Volume_Simplexe ();
  }
  if (fabs (volume_after - volume_before) > 1.e-8 * fabs (volume_after + volume_before)
      || min_quality_old > min_quality_new){
    pnxe->v->Pos.X = xold;
    pnxe->v->Pos.Y = yold;
    pnxe->v->Pos.Z = zold;
  }
  List_Delete(nodes);
}


void ActionLissSurf (void *data, void *dummy){
  NXE *pnxe;
  Simplex *s;
  double X, Y, Z, Sum;
  int i, j;

  pnxe = (NXE *) data;

  /*
     On Ne Lisse Point Les Points sur les courbes
   */
  if (pnxe->v->ListCurves)
    return;

  X = Y = Z = Sum = 0.0;
  for (i = 0; i < List_Nbr (pnxe->Liste); i++){
    List_Read (pnxe->Liste, i, &s);
    /*
      On Ne Lisse Point Les Points sur les surfaces quand les
      volumes sont mailles
    */
    for (j = 0; j < 4; j++){
      if (s->V[j] && compareVertex (&pnxe->v, &s->V[j])){
        Sum += 0.5;
        X += s->V[j]->Pos.X * 0.5;
        Y += s->V[j]->Pos.Y * 0.5;
        Z += s->V[j]->Pos.Z * 0.5;
      }
    }
  }
  if (Sum != 0.0){
    pnxe->v->Pos.X = X / Sum;
    pnxe->v->Pos.Y = Y / Sum;
    pnxe->v->Pos.Z = Z / Sum;
  }
}

void RandomSwapEdges (Surface * s){
  int i;
  List_T *AllTrg = Tree2List (s->Simplexes);
  Simplex *t;
  for (i = 0; i < List_Nbr (AllTrg); i++){
    List_Read (AllTrg, i, &t);
    t->SwapEdge (1);
  }
}
