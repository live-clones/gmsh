// $Id: 3D_Extrude.cpp,v 1.32 2001-08-14 16:10:47 geuzaine Exp $

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Context.h"
#include "Create.h"

extern Mesh      *THEM;
extern int        CurrentNodeNumber;

static Tree_T *Tree_Ares = NULL, *Tree_Swaps = NULL;
static int TEST_IS_ALL_OK;
static Surface *THES;
static Volume *THEV;
static ExtrudeParams *ep;
static Tree_T *Vertex_Bound = NULL, *ToAdd = NULL;

// Vertex_Bound contains the vertices on the boundary (on the curves
// for extrude_mesh(surface) and on the surfaces for
// extrude_mesh(volume))

typedef struct{
  int a, b;
}nxn;

static int compnxn (const void *a, const void *b){
  nxn *q, *w;
  q = (nxn *) a;
  w = (nxn *) b;
  if (q->a > w->a)
    return 1;
  if (q->a < w->a)
    return -1;
  if (q->b > w->b)
    return 1;
  if (q->b < w->b)
    return -1;
  return 0;
}

void InitExtrude (){
  if (!Tree_Ares)
    Tree_Ares = Tree_Create (sizeof (nxn), compnxn);
  if (!Tree_Swaps)
    Tree_Swaps = Tree_Create (sizeof (nxn), compnxn);
  if(Vertex_Bound)
    Tree_Delete(Vertex_Bound);
  Vertex_Bound = Tree_Create (sizeof (Vertex *), comparePosition);
  List_T *l1 = Tree2List (THEM->Points);
  List_T *l2 = Tree2List (THEM->Vertices);

  for(int i=0;i<List_Nbr(l1);i++)Tree_Insert(Vertex_Bound,List_Pointer(l1,i));
  for(int i=0;i<List_Nbr(l2);i++)Tree_Insert(Vertex_Bound,List_Pointer(l2,i));

  List_Delete(l1);
  List_Delete(l2);
}

void ExitExtrude (){
  if (Tree_Ares)Tree_Delete(Tree_Ares);
  if (Tree_Swaps)Tree_Delete(Tree_Swaps);
  if(Vertex_Bound)Tree_Delete (Vertex_Bound);
  Tree_Ares = Tree_Swaps = NULL;
  ToAdd = Vertex_Bound = NULL;
}

int are_exist (Vertex * v1, Vertex * v2, Tree_T * t){
  nxn n;
  n.a = IMAX (v1->Num, v2->Num);
  n.b = IMIN (v1->Num, v2->Num);
  return Tree_Search (t, &n);
}

void are_cree (Vertex * v1, Vertex * v2, Tree_T * t){
  nxn n;
  n.a = IMAX (v1->Num, v2->Num);
  n.b = IMIN (v1->Num, v2->Num);
  Tree_Replace (t, &n);
}

void are_del (Vertex * v1, Vertex * v2, Tree_T * t){
  nxn n;
  n.a = IMAX (v1->Num, v2->Num);
  n.b = IMIN (v1->Num, v2->Num);
  Tree_Suppress (t, &n);
}


void Extrude_Simplex_Phase1 (void *data, void *dum){
  Simplex **pS, *s;
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4, *v5, *v6;

  pS = (Simplex **) data;
  s = *pS;

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      List_Read (s->V[0]->Extruded_Points, k, &v1);
      List_Read (s->V[1]->Extruded_Points, k, &v2);
      List_Read (s->V[2]->Extruded_Points, k, &v3);
      List_Read (s->V[0]->Extruded_Points, k + 1, &v4);
      List_Read (s->V[1]->Extruded_Points, k + 1, &v5);
      List_Read (s->V[2]->Extruded_Points, k + 1, &v6);
      if (ep->mesh.Simplexes){
        k++;
        if (!are_exist (v1, v5, Tree_Ares))
          are_cree (v2, v4, Tree_Ares);
        if (!are_exist (v5, v3, Tree_Ares))
          are_cree (v2, v6, Tree_Ares);
        if (!are_exist (v4, v3, Tree_Ares))
          are_cree (v1, v6, Tree_Ares);
      }
      else if (!s->V[3]){
      }
      else{
      }
    }
  }
}

void Extrude_Simplex_Phase3 (void *data, void *dum){

  Simplex **pS, *s, *news;
  Hexahedron *newh;
  Prism *newp;
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8;

  pS = (Simplex **) data;
  s = *pS;

  if(s->V[3] && !ep->mesh.Recombine){
    Msg(GERROR, "You have to use 'Recombine' to extrude quadrangular meshes");
    return;
  }

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){

      if(s->V[3]){
        List_Read(s->V[0]->Extruded_Points,k,&v1);
        List_Read(s->V[1]->Extruded_Points,k,&v2);
        List_Read(s->V[2]->Extruded_Points,k,&v3);
        List_Read(s->V[3]->Extruded_Points,k,&v4);
        List_Read(s->V[0]->Extruded_Points,k+1,&v5);
        List_Read(s->V[1]->Extruded_Points,k+1,&v6);
        List_Read(s->V[2]->Extruded_Points,k+1,&v7);
        List_Read(s->V[3]->Extruded_Points,k+1,&v8);
      }
      else{
        List_Read (s->V[0]->Extruded_Points, k, &v1);
        List_Read (s->V[1]->Extruded_Points, k, &v2);
        List_Read (s->V[2]->Extruded_Points, k, &v3);
        List_Read (s->V[0]->Extruded_Points, k + 1, &v4);
        List_Read (s->V[1]->Extruded_Points, k + 1, &v5);
        List_Read (s->V[2]->Extruded_Points, k + 1, &v6);
      }

      k++;
      if (ep->mesh.ZonLayer[i]){

        if(ep->mesh.Recombine){
          if(s->V[3]){
            newh = Create_Hexahedron(v1,v2,v3,v4,v5,v6,v7,v8);
            newh->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Hexahedra,&newh);
          }
          else{
            newp = Create_Prism(v1,v2,v3,v4,v5,v6);
            newp->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Prisms,&newp);
          }
        }
        else{
          
          if (are_exist (v4, v2, Tree_Ares) &&
              are_exist (v5, v3, Tree_Ares) &&
              are_exist (v4, v3, Tree_Ares)){
            news = Create_Simplex (v1, v2, v3, v4);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v5, v6, v3);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v2, v4, v5, v3);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v4, v2, Tree_Ares) &&
              are_exist (v2, v6, Tree_Ares) &&
              are_exist (v4, v3, Tree_Ares)){
            news = Create_Simplex (v1, v2, v3, v4);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v5, v6, v2);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v2, v6, v3);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v4, v2, Tree_Ares) &&
              are_exist (v2, v6, Tree_Ares) &&
              are_exist (v6, v1, Tree_Ares)){
            news = Create_Simplex (v1, v2, v3, v6);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v5, v6, v2);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v2, v4, v6, v1);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v5, v1, Tree_Ares) &&
              are_exist (v5, v3, Tree_Ares) &&
              are_exist (v4, v3, Tree_Ares)){
            news = Create_Simplex (v1, v2, v3, v5);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v5, v6, v3);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v1, v4, v5, v3);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v5, v1, Tree_Ares) &&
              are_exist (v5, v3, Tree_Ares) &&
              are_exist (v6, v1, Tree_Ares)){
            news = Create_Simplex (v1, v2, v3, v5);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v5, v6, v1);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v1, v3, v5, v6);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v5, v1, Tree_Ares) &&
              are_exist (v2, v6, Tree_Ares) &&
              are_exist (v6, v1, Tree_Ares)){
            news = Create_Simplex (v1, v2, v3, v6);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v4, v5, v6, v1);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v1, v2, v5, v6);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
        }
      }
    }
  }
}

void Extrude_Simplex_Phase2 (void *data, void *dum){

  Simplex **pS, *s;
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4, *v5, *v6;

  pS = (Simplex **) data;
  s = *pS;

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      List_Read (s->V[0]->Extruded_Points, k, &v1);
      List_Read (s->V[1]->Extruded_Points, k, &v2);
      List_Read (s->V[2]->Extruded_Points, k, &v3);
      List_Read (s->V[0]->Extruded_Points, k + 1, &v4);
      List_Read (s->V[1]->Extruded_Points, k + 1, &v5);
      List_Read (s->V[2]->Extruded_Points, k + 1, &v6);
      k++;
      if (are_exist (v4, v2, Tree_Ares) &&
          are_exist (v5, v3, Tree_Ares) &&
          are_exist (v1, v6, Tree_Ares)){
        TEST_IS_ALL_OK++;
        if (!are_exist (v4, v2, Tree_Swaps)){
          are_del (v4, v2, Tree_Ares);
          are_cree (v1, v5, Tree_Ares);
          are_cree (v1, v5, Tree_Swaps);
          are_cree (v4, v2, Tree_Swaps);
        }
        else if (!are_exist (v5, v3, Tree_Swaps)){
          are_del (v5, v3, Tree_Ares);
          are_cree (v2, v6, Tree_Ares);
          are_cree (v5, v3, Tree_Swaps);
          are_cree (v2, v6, Tree_Swaps);
        }
        else if (!are_exist (v1, v6, Tree_Swaps)){
          are_del (v1, v6, Tree_Ares);
          are_cree (v4, v3, Tree_Ares);
          are_cree (v1, v6, Tree_Swaps);
          are_cree (v4, v3, Tree_Swaps);
        }
      }
      else if (are_exist (v1, v5, Tree_Ares) && 
               are_exist (v2, v6, Tree_Ares) && 
               are_exist (v4, v3, Tree_Ares)){
        TEST_IS_ALL_OK++;
        if (!are_exist (v1, v5, Tree_Swaps)){
          are_del (v1, v5, Tree_Ares);
          are_cree (v4, v2, Tree_Ares);
          are_cree (v1, v5, Tree_Swaps);
          are_cree (v4, v2, Tree_Swaps);
        }
        else if (!are_exist (v2, v6, Tree_Swaps)){
          are_del (v2, v6, Tree_Ares);
          are_cree (v5, v3, Tree_Ares);
          are_cree (v5, v3, Tree_Swaps);
          are_cree (v2, v6, Tree_Swaps);
        }
        else if (!are_exist (v4, v3, Tree_Swaps)){
          are_del (v4, v3, Tree_Ares);
          are_cree (v1, v6, Tree_Ares);
          are_cree (v1, v6, Tree_Swaps);
          are_cree (v4, v3, Tree_Swaps);
        }
      }
    }
  }
}


void Extrude_Vertex (void *data, void *dum){

  Vertex **pV, *v, *newv;
  int i, j;

  pV = (Vertex **) data;
  v = *pV;

  // We should _not_ return here, since 1 point can be extruded along
  // several directions (this was of course not the case in the old
  // extrusion generator...)
  if (v->Extruded_Points) // return;
    List_Delete (v->Extruded_Points);

  v->Extruded_Points = List_Create (ep->mesh.NbLayer, 1, sizeof (Vertex *));
  List_Add (v->Extruded_Points, &v);

  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      newv = Create_Vertex (++CurrentNodeNumber, v->Pos.X,
                            v->Pos.Y, v->Pos.Z, v->lc, v->u);
      ep->Extrude (i, j + 1, newv->Pos.X, newv->Pos.Y, newv->Pos.Z);

      if (Vertex_Bound && (pV = (Vertex **) Tree_PQuery (Vertex_Bound, &newv))){
	Free_Vertex (&newv,0);
        List_Add (v->Extruded_Points, pV);
        if (ToAdd)
          Tree_Insert (ToAdd, pV);
      }
      else{
        List_Add (v->Extruded_Points, &newv);
        Tree_Insert (THEM->Vertices, &newv);
        Tree_Insert (Vertex_Bound, &newv);
        if (ToAdd)
          Tree_Insert (ToAdd, &newv);
      }
    }
  }
}

void Extrude_Surface1 (Surface * s){
  THES = s;
  Tree_Action (s->Vertices, Extrude_Vertex);
  if(!ep->mesh.Recombine) Tree_Action (s->Simplexes, Extrude_Simplex_Phase1);
}

void Extrude_Surface2 (Surface * s){
  THES = s;
  Tree_Action (s->Simplexes, Extrude_Simplex_Phase2);
}


void Extrude_Surface3 (Surface * s){
  THES = s;
  Tree_Action (s->Simplexes, Extrude_Simplex_Phase3);
}


void Extrude_Seg (Vertex * V1, Vertex * V2){
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4;
  Simplex *s;

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      List_Read (V1->Extruded_Points, k, &v1);
      List_Read (V2->Extruded_Points, k, &v2);
      List_Read (V1->Extruded_Points, k + 1, &v3);
      List_Read (V2->Extruded_Points, k + 1, &v4);
      if(ep->mesh.Recombine){
        s = Create_Quadrangle(v1,v2,v4,v3);
        s->iEnt = THES->Num; 
	s->Num = -s->Num; //Tag quadrangles to re-extrude
        Tree_Add(THES->Simplexes,&s);
      }
      else{
        if (are_exist (v3, v2, Tree_Ares)){
          s = Create_Simplex (v3, v2, v1, NULL);
          s->iEnt = THES->Num;
	  s->Num = -s->Num; //Tag triangles to re-extrude
          Tree_Add (THES->Simplexes, &s);
          s = Create_Simplex (v3, v4, v2, NULL);
          s->iEnt = THES->Num;
	  s->Num = -s->Num; //Tag triangles to re-extrude
          Tree_Add (THES->Simplexes, &s);
        }
        else{
          s = Create_Simplex (v3, v4, v1, NULL);
          s->iEnt = THES->Num;
	  s->Num = -s->Num; //Tag triangles to re-extrude
          Tree_Add (THES->Simplexes, &s);
          s = Create_Simplex (v1, v4, v2, NULL);
          s->iEnt = THES->Num;
	  s->Num = -s->Num; //Tag triangles to re-extrude
          Tree_Add (THES->Simplexes, &s);
        }
      }
      k++;
    }
  }
  
}

void Extrude_Curve (void *data, void *dum){
  Curve **pC, *c;
  Vertex *v1, *v2;
  int i;
  pC = (Curve **) data;
  c = *pC;

  //if (c->Num < 0) return;

  for (i = 0; i < List_Nbr (c->Vertices) - 1; i++){
    List_Read (c->Vertices, i, &v1);
    List_Read (c->Vertices, i + 1, &v2);
    Extrude_Seg (v1, v2);
  }
}

void copy_mesh (Curve * from, Curve * to, int direction){
  List_T *list = from->Vertices;
  Vertex *vi, *v, **vv, **vexist;

  int nb = List_Nbr(to->Vertices);
  if(nb){
    if(nb != List_Nbr(from->Vertices))
      Msg(GERROR, "Uncompatible extrusion of curve %d into curve %d",
	  from->Num, to->Num);
    return;
  }

  to->Vertices =  List_Create (List_Nbr(from->Vertices), 2, sizeof (Vertex *));

  vv = &to->beg;
  if ((vexist = (Vertex **) Tree_PQuery (THEM->Vertices, vv))){
    (*vexist)->u = to->ubeg;
    Tree_Insert (THEM->Vertices, vexist);
    if ((*vexist)->ListCurves)
      List_Add ((*vexist)->ListCurves, &to);
    List_Add (to->Vertices, vexist);
  }
  else{
    vi = Create_Vertex ((*vv)->Num, (*vv)->Pos.X, (*vv)->Pos.Y, (*vv)->Pos.Z,
			(*vv)->lc, to->ubeg);
    Tree_Insert (THEM->Vertices, &vi);
    vi->ListCurves = List_Create (1, 1, sizeof (Curve *));
    List_Add (vi->ListCurves, &to);
    List_Add (to->Vertices, &vi);
  }

  for (int i = 1; i < List_Nbr(list)-1; i++){
    if(direction < 0) 
      List_Read (list, List_Nbr(list)-1-i, &v);
    else
      List_Read (list, i, &v);
    vi = Create_Vertex (++CurrentNodeNumber, v->Pos.X,
			v->Pos.Y, v->Pos.Z, v->lc, (direction>0)?v->u:(1.-v->u));
    ep->Extrude (ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
		 vi->Pos.X, vi->Pos.Y, vi->Pos.Z);
    Tree_Insert (THEM->Vertices, &vi);
    if(!vi->ListCurves)
      vi->ListCurves = List_Create (1, 1, sizeof (Curve *));
    List_Add (vi->ListCurves, &to);
    List_Add (to->Vertices, &vi);
  }

  vv = &to->end;
  if ((vexist = (Vertex **) Tree_PQuery (THEM->Vertices, vv))){
    (*vexist)->u = to->uend;
    Tree_Insert (THEM->Vertices, vexist);
    if ((*vexist)->ListCurves)
      List_Add ((*vexist)->ListCurves, &to);
    List_Add (to->Vertices, vexist);
  }
  else{
    vi = Create_Vertex ((*vv)->Num, (*vv)->Pos.X, (*vv)->Pos.Y, (*vv)->Pos.Z, 
			(*vv)->lc, to->uend);
    Tree_Insert (THEM->Vertices, &vi);
    vi->ListCurves = List_Create (1, 1, sizeof (Curve *));
    List_Add (vi->ListCurves, &to);
    List_Add (to->Vertices, &vi);
  }


}

int Extrude_Mesh (Curve * c){
  int i;
  Vertex **v, *pV, **vexist, *v1;

  if (!c->Extrude || !c->Extrude->mesh.ExtrudeMesh) return false;

  InitExtrude();

  ep = c->Extrude;

  if (ep->geo.Mode == EXTRUDED_ENTITY){
    Extrude_Vertex (&c->beg, NULL);
    c->Vertices = List_Create (List_Nbr (c->beg->Extruded_Points), 2, sizeof (Vertex *));
    v = &c->beg;
    if ((vexist = (Vertex **) Tree_PQuery (THEM->Vertices, v))){
      (*vexist)->u = c->ubeg;
      Tree_Insert (THEM->Vertices, vexist);
      if ((*vexist)->ListCurves)
        List_Add ((*vexist)->ListCurves, &c);
      List_Add (c->Vertices, vexist);
    }
    else{
      pV = Create_Vertex ((*v)->Num, (*v)->Pos.X, (*v)->Pos.Y, (*v)->Pos.Z, (*v)->lc, 0.0);
      pV->ListCurves = List_Create (1, 1, sizeof (Curve *));
      List_Add (pV->ListCurves, &c);
      Tree_Insert (THEM->Vertices, &pV);
      List_Add (c->Vertices, &pV);
    }

    for (i = 1; i < List_Nbr (c->beg->Extruded_Points) - 1; i++){
      List_Read (c->beg->Extruded_Points, i, &v1);
      if (!v1->ListCurves) v1->ListCurves = List_Create (1, 1, sizeof (Curve *));
      List_Add (v1->ListCurves, &c);
      Tree_Insert (THEM->Vertices, &v1);
      v1->u = (double) i / (double) List_Nbr (c->beg->Extruded_Points);
      List_Add (c->Vertices, &v1);
    }

    v = &c->end;
    if ((vexist = (Vertex **) Tree_PQuery (THEM->Vertices, v))){
      (*vexist)->u = c->uend;
      Tree_Insert (THEM->Vertices, vexist);
      if ((*vexist)->ListCurves)
        List_Add ((*vexist)->ListCurves, &c);
      List_Add (c->Vertices, vexist);
    }
    else{
      pV = Create_Vertex ((*v)->Num, (*v)->Pos.X, (*v)->Pos.Y, (*v)->Pos.Z, (*v)->lc, 0.0);
      pV->ListCurves = List_Create (1, 1, sizeof (Curve *));
      List_Add (pV->ListCurves, &c);
      Tree_Insert (THEM->Vertices, &pV);
      List_Add (c->Vertices, &pV);
    }
    return true;
  }
  else{
    Curve *cc = FindCurve (abs(ep->geo.Source), THEM);
    if (!cc) return false;
    copy_mesh (cc, c, sign(ep->geo.Source));
    return true;
  }
}

void copy_mesh (Surface * from, Surface * to){
  List_T *list = Tree2List (from->Simplexes);
  Simplex *s, *news;
  Vertex **pV, *vi[3], *v;

  int nb = Tree_Nbr(to->Simplexes);
  if(nb){
    if(nb != Tree_Nbr(from->Simplexes))
      Msg(GERROR, "Uncompatible extrusion of surface %d into surface %d",
	  from->Num, to->Num);
    return;
  }

  for (int i = 0; i < List_Nbr (list); i++){
    List_Read (list, i, &s);
    for (int j = 0; j < 4; j++){
      if(s->V[j]){
	v = s->V[j];
	vi[j] = Create_Vertex (++CurrentNodeNumber, v->Pos.X,
			       v->Pos.Y, v->Pos.Z, v->lc, v->u);
	ep->Extrude (ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
		     vi[j]->Pos.X, vi[j]->Pos.Y, vi[j]->Pos.Z);
	if (Vertex_Bound && (pV = (Vertex **) Tree_PQuery (Vertex_Bound, &vi[j]))){
	  Free_Vertex(&vi[j],0);
	  vi[j] = *pV;
	}
	else{
	  Tree_Insert (THEM->Vertices, &vi[j]);
	  Tree_Insert (Vertex_Bound, &vi[j]);
	}
	if (ToAdd)
	  Tree_Insert (ToAdd, &vi[j]);
      }
      else{
	vi[j] = NULL;
      }
    }    
    if(vi[3])
      news = Create_Quadrangle (vi[0], vi[1], vi[2], vi[3]);
    else
      news = Create_Simplex (vi[0], vi[1], vi[2], NULL);
    news->iEnt = to->Num;
    Tree_Add (to->Simplexes, &news);
  }
  List_Delete (list);
}

int Extrude_Mesh (Surface * s){
  int i;
  Vertex *v1;
  Curve *cc;
  extern int FACE_DIMENSION;

  if (!s->Extrude || !s->Extrude->mesh.ExtrudeMesh) return false;

  InitExtrude ();

  FACE_DIMENSION = 2;

  ep = s->Extrude;
  THES = s;

  ToAdd = s->Vertices;

  for (i = 0; i < List_Nbr (s->Generatrices); i++){
    List_Read (s->Generatrices, i, &cc);
    for (int j = 0; j < List_Nbr (cc->Vertices); j++){
      List_Read (cc->Vertices, j, &v1);
      Tree_Insert (Vertex_Bound, &v1);
    }
  }
  if (ep->geo.Mode == EXTRUDED_ENTITY){
    Curve *c = FindCurve (abs(ep->geo.Source), THEM);
    if (!c) return false;
    for (i = 0; i < List_Nbr (c->Vertices); i++){
      List_Read (c->Vertices, i, &v1);
      Extrude_Vertex (&v1, NULL);
    }
    Extrude_Curve (&c, NULL);
    return true;
  }
  else{
    Surface *ss = FindSurface (ep->geo.Source, THEM);
    if (!ss) return false;
    copy_mesh (ss, s);
    return true;
  }

}

static Tree_T* tmp;

void Free_NegativeSimplex (void *a, void *b){
  Simplex *s = *(Simplex**)a;
  if(s){
    if(s->Num>=0){
      Tree_Add (tmp, &s);
    }
    else{
      delete s;
      s = NULL;
    }
  }
}

int Extrude_Mesh (Volume * v){
  int i, j;
  Surface *ss;
  Vertex *v1;

  if (!v->Extrude || !v->Extrude->mesh.ExtrudeMesh) return false;

  InitExtrude ();

  Msg(STATUS3, "Meshing Volume %d", v->Num);

  ep = v->Extrude;
  THEV = v;
  if (ep->geo.Mode == EXTRUDED_ENTITY){
    Surface *s = FindSurface (ep->geo.Source, THEM);
    if (!s) return false;

    List_T *list;
    for (i = 0; i < List_Nbr (v->Surfaces); i++){
      List_Read (v->Surfaces, i, &ss);
      list = Tree2List (ss->Vertices);
      for (int j = 0; j < List_Nbr (list); j++){
        List_Read (list, j, &v1);
        Tree_Insert (Vertex_Bound, &v1);
      }
      List_Delete (list);
    }

    Extrude_Surface1 (s);
    
    if(!ep->mesh.Recombine){
      j = 0;
      do{
        TEST_IS_ALL_OK = 0;
        Extrude_Surface2 (s);
	Msg(INFO, "Swapping %d",TEST_IS_ALL_OK);
        if (TEST_IS_ALL_OK == j)
          break;
        j = TEST_IS_ALL_OK;
      }
      while (TEST_IS_ALL_OK);
    }

    Extrude_Surface3 (s);

    // Well well ... I think I fixed the bug in extrude meshes.
    // Volume mesh cannot always comply with surface mesh, so I delete the
    // surface mesh and create a new one. Edges were stored in Tree_Ares
    // so that now, the surface mesh is ok (edge swapping is easy in 2d).
    // cretainly not the most efficient way to do it but it seems to work
    //
    // In order to suppress only the tri/qua that have to, i.e. all
    // those created by extrude_seg(), we tag tag them with a negative
    // number. These elts will keep this negative number during their
    // whole lives in order for adjacent volumes to respect the
    // coherence of their common boundaries.
    
    for (i = 0; i < List_Nbr (v->Surfaces); i++){
      List_Read (v->Surfaces, i, &ss);
      tmp = Tree_Create (sizeof (Simplex *), compareQuality);
      Tree_Action(ss->Simplexes, Free_NegativeSimplex);
      Tree_Delete(ss->Simplexes);
      ss->Simplexes = tmp;
      Extrude_Mesh(ss);
    }
    
    return true;
  }
  else{
    return false;
  }
}
