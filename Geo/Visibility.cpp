
#include "Gmsh.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "DataBase.h"

extern Mesh *THEM;

/* Gestion des entites visibles */

Tree_T  *EntitesVisibles=NULL;
int      SHOW_ALL_ENTITIES;

typedef struct{
 int Entite;
 int Visible;
}EntiteVisible;

int compareEntiteVisible(const void *a, const void *b){
  EntiteVisible *q,*w;
  q = (EntiteVisible*)a;
  w = (EntiteVisible*)b;
  return(q->Entite-w->Entite);
}

int EntiteEstElleVisible(int iEnt){
  EntiteVisible e;
  e.Entite = iEnt;
  if(Tree_Query(EntitesVisibles,&e))
    return e.Visible;
  return 1;
}

void ToutesLesEntitesRelatives(int iEnt, Tree_T *Tree, int add_rem){
  int i;
  EntiteVisible e;

  Surface *s;
  Volume *v;
  Curve *c;

  if((c = FindCurve(iEnt,THEM))){
  }
  else if((s = FindSurface(iEnt,THEM))){
    for(i=0;i<List_Nbr(s->s.Generatrices);i++){
      List_Read(s->s.Generatrices,i,&c);
      e.Entite = abs(c->Num);
      e.Visible = add_rem;
      Tree_Replace(Tree,&e);
    }
  }
  else if((v = FindVolume(iEnt,THEM))){
    for(i=0;i<List_Nbr(v->Surfaces);i++){
      List_Read(v->Surfaces,i,&s);
      e.Entite = abs(s->Num);
      e.Visible = add_rem;
      Tree_Replace(Tree,&e);
    }
  }

  e.Entite = abs(iEnt);
  e.Visible = add_rem;
  Tree_Replace(Tree,&e);
}

void RemplirEntitesVisibles (int add_rem){
  int i;
  Volume *v;
  Surface *s;
  Curve *c;

  List_T *ListVolumes = Tree2List (THEM->Volumes);
  List_T *ListSurfaces = Tree2List (THEM->Surfaces);
  List_T *ListCurves = Tree2List (THEM->Curves);
  EntitesVisibles = Tree_Create(sizeof(EntiteVisible),compareEntiteVisible);
  for(i=0;i<List_Nbr(ListVolumes);i++){
    List_Read(ListVolumes,i,&v);
    ToutesLesEntitesRelatives(v->Num,EntitesVisibles,add_rem);
  }
  for(i=0;i<List_Nbr(ListSurfaces);i++){
    List_Read(ListSurfaces,i,&s);
    ToutesLesEntitesRelatives(s->Num,EntitesVisibles,add_rem);
  }
  for(i=0;i<List_Nbr(ListCurves);i++){
    List_Read(ListCurves,i,&c);
    ToutesLesEntitesRelatives(c->Num,EntitesVisibles,add_rem);
  }
  List_Delete(ListVolumes);
  List_Delete(ListSurfaces);
  List_Delete(ListCurves);
}
