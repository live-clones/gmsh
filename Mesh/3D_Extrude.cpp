// $Id: 3D_Extrude.cpp,v 1.48 2001-09-27 15:00:50 geuzaine Exp $

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Context.h"
#include "Create.h"

extern Context_T  CTX ;
extern Mesh      *THEM;
extern int        CurrentNodeNumber;

static int DIM, NUM; // current dimension of parent entity

static Tree_T *Tree_Ares = NULL, *Tree_Swaps = NULL;
static int TEST_IS_ALL_OK;
static Curve *THEC=NULL;
static Surface *THES=NULL;
static Volume *THEV=NULL;
static ExtrudeParams *ep;
static Tree_T *Vertex_Bound = NULL, *ToAdd = NULL;

// Vertex_Bound contains the vertices on the boundary (on the curves
// for extrude_mesh(surface) and on the surfaces for
// extrude_mesh(volume))

typedef struct{
  int Dim, Num;
  List_T * List;
}nxl;

static int compnxl (const void *a, const void *b){
  int val ;
  nxl *q = (nxl *)a, *w = (nxl *)b;

  if ((val = q->Dim - w->Dim) != 0) return val;
  return q->Num - w->Num;
}

List_T* getnxl(Vertex *v, Curve *c){
  nxl NXL;
  NXL.Dim = 1;
  NXL.Num = abs(c->Num);
  nxl *NXLP = (nxl*)List_PQuery(v->Extruded_Points, &NXL, compnxl);
  if(NXLP) return NXLP->List;
  return NULL;
}

List_T* getnxl(Vertex *v, Surface *s){
  nxl NXL;
  NXL.Dim = 2;
  NXL.Num = s->Num;
  nxl *NXLP = (nxl*)List_PQuery(v->Extruded_Points, &NXL, compnxl);
  if(NXLP) return NXLP->List;
  return NULL;
}

List_T* getnxl(Vertex *v, Volume *vol){
  nxl NXL;
  NXL.Dim = 3;
  NXL.Num = vol->Num;
  nxl *NXLP = (nxl*)List_PQuery(v->Extruded_Points, &NXL, compnxl);
  if(NXLP) return NXLP->List;
  return NULL;
}

List_T* getnxl(Vertex *v, int dim){
  int i, j;
  Curve *c;
  Surface *s;
  List_T *list;

  // the test on the source entity is in case we extrude a
  // curve/surface resulting from the extrusion of a point/curve...

  if(dim==1){
    if((list = getnxl(v, THEC)))
      return list;
  }
  else if(dim==2){
    if((list = getnxl(v, THES)))
      return list;
    else{
      for(i=0; i<List_Nbr(THES->Generatrices); i++){
	if((abs(ep->geo.Source)!=c->Num) && (list = getnxl(v, c))) 
	  return list;
      }
    }
  }
  else if(dim==3){
    if((list = getnxl(v, THEV))) 
      return list;
    else{
      for(i=0; i<List_Nbr(THEV->Surfaces); i++){
	List_Read(THEV->Surfaces, i, &s);
	if((ep->geo.Source!=s->Num) && (list = getnxl(v, s))) 
	  return list;
      }
      for(i=0; i<List_Nbr(THEV->Surfaces); i++){
	List_Read(THEV->Surfaces, i, &s);
	if(ep->geo.Source!=s->Num){
	  for(j=0; j<List_Nbr(s->Generatrices); j++){
	    List_Read(s->Generatrices, j, &c);
	    if((list = getnxl(v, c))) 
	      return list;
	  }
	}
      }
    }
  }

  Msg(FATAL, "Could not find extruded list for vertex %d", v->Num);
  return NULL;
}

void Free_ExtrudedPoints(List_T* Extruded_Points){
  nxl *NXL;
  for(int i=0; i<List_Nbr(Extruded_Points); i++){
    NXL = (nxl*)List_Pointer(Extruded_Points, i);
    List_Delete(NXL->List);
  }
  List_Delete(Extruded_Points);
}

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
  List_T *L0, *L1, *L2;

  pS = (Simplex **) data;
  s = *pS;

  L0 = getnxl(s->V[0],DIM);
  L1 = getnxl(s->V[1],DIM);
  L2 = getnxl(s->V[2],DIM);

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      List_Read (L0, k, &v1);
      List_Read (L1, k, &v2);
      List_Read (L2, k, &v3);
      List_Read (L0, k + 1, &v4);
      List_Read (L1, k + 1, &v5);
      List_Read (L2, k + 1, &v6);
      k++;
      if (!are_exist (v1, v5, Tree_Ares))
	are_cree (v2, v4, Tree_Ares);
      if (!are_exist (v5, v3, Tree_Ares))
	are_cree (v2, v6, Tree_Ares);
      if (!are_exist (v4, v3, Tree_Ares))
	are_cree (v1, v6, Tree_Ares);
    }
  }
}

void Create_HexPri(int iEnt, Vertex *v[8]){
  int i, j=0, dup[4];
  Hexahedron *newh;
  Prism *newp;

  if(CTX.mesh.allow_degenerated_extrude){
    newh = Create_Hexahedron(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
    newh->iEnt = iEnt;
    Tree_Add(THEV->Hexahedra,&newh);
    return;
  }

  for(i=0; i<4; i++)
    if(v[i]->Num == v[i+4]->Num) dup[j++] = i;
  
  if(j==2){
    if(dup[0]==0 && dup[1]==1)
      newp = Create_Prism(v[0],v[3],v[7],v[1],v[6],v[2]);
    else if(dup[0]==1 && dup[1]==2)
      newp = Create_Prism(v[0],v[1],v[4],v[3],v[2],v[7]);
    else if(dup[0]==2 && dup[1]==3)
      newp = Create_Prism(v[0],v[3],v[4],v[1],v[5],v[7]);
    else if(dup[0]==0 && dup[1]==3)
      newp = Create_Prism(v[0],v[1],v[5],v[3],v[2],v[6]);
    else{
      Msg(GERROR, "Uncoherent hexahedron  (nodes %d %d %d %d %d %d %d %d)",
	  v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
      return;
    }
    newp->iEnt = iEnt;
    Tree_Add(THEV->Prisms,&newp);
  }
  else{
    newh = Create_Hexahedron(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
    newh->iEnt = iEnt;
    Tree_Add(THEV->Hexahedra,&newh);
    if(j)
      Msg(GERROR, "Degenerated hexahedron %d (nodes %d %d %d %d %d %d %d %d)", 
	  newh->Num,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
  }
}

void Create_PriPyrTet(int iEnt, Vertex *v[6]){
  int i, j=0, dup[3];
  Prism *newp;
  Pyramid *newpyr;
  Simplex *news;

  if(CTX.mesh.allow_degenerated_extrude){
    newp = Create_Prism(v[0],v[1],v[2],v[3],v[4],v[5]);
    newp->iEnt = iEnt;
    Tree_Add(THEV->Prisms,&newp);
    return;
  }

  for(i=0; i<3; i++)
    if(v[i]->Num == v[i+3]->Num) dup[j++] = i;

  if(j==2){
    if(dup[0]==0 && dup[1]==1)
      news = Create_Simplex(v[0],v[1],v[2],v[5]);
    else if(dup[0]==1 && dup[1]==2)
      news = Create_Simplex(v[0],v[1],v[2],v[3]);
    else
      news = Create_Simplex(v[0],v[1],v[2],v[4]);
    news->iEnt = iEnt;
    Tree_Add(THEV->Simplexes,&news);
  }
  else if(j==1){
    if(dup[0]==0)
      newpyr = Create_Pyramid(v[1],v[4],v[5],v[2],v[0]);
    else if(dup[0]==1)
      newpyr = Create_Pyramid(v[0],v[2],v[5],v[3],v[1]);
    else
      newpyr = Create_Pyramid(v[0],v[1],v[4],v[3],v[2]);
    newpyr->iEnt = iEnt;
    Tree_Add(THEV->Pyramids,&newpyr);
  }
  else{
    newp = Create_Prism(v[0],v[1],v[2],v[3],v[4],v[5]);
    newp->iEnt = iEnt;
    Tree_Add(THEV->Prisms,&newp);
    if(j)
      Msg(GERROR, "Degenerated prism %d (nodes %d %d %d %d %d %d)", 
	  newp->Num,v[0],v[1],v[2],v[3],v[4],v[5]);
  }

}


void Extrude_Simplex_Phase3 (void *data, void *dum){

  Simplex **pS, *s, *news;
  int i, j, k;
  Vertex *v[8];
  List_T *L0, *L1, *L2, *L3;

  pS = (Simplex **) data;
  s = *pS;

  if(s->V[3] && !ep->mesh.Recombine){
    Msg(GERROR, "You have to use 'Recombine' to extrude quadrangular meshes");
    return;
  }

  L0 = getnxl(s->V[0],DIM);
  L1 = getnxl(s->V[1],DIM);
  L2 = getnxl(s->V[2],DIM);
  if(s->V[3]) L3 = getnxl(s->V[3],DIM);

  //printf("orig: %d %d %d %d\n",s->V[0]->Num,s->V[1]->Num,s->V[2]->Num,s->V[3]->Num);

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){

      if(s->V[3]){
        List_Read(L0,k,&v[0]);
        List_Read(L1,k,&v[1]);
        List_Read(L2,k,&v[2]);
        List_Read(L3,k,&v[3]);

	//printf("   1: %d %d %d %d\n",v[0]->Num,v[1]->Num,v[2]->Num,v[3]->Num);

        List_Read(L0,k+1,&v[4]);
        List_Read(L1,k+1,&v[5]);
        List_Read(L2,k+1,&v[6]);
        List_Read(L3,k+1,&v[7]);

	//printf("   2: %d %d %d %d\n",v[4]->Num,v[5]->Num,v[6]->Num,v[7]->Num);

      }		    
      else{	    
        List_Read(L0, k, &v[0]);
        List_Read(L1, k, &v[1]);
        List_Read(L2, k, &v[2]);
        List_Read(L0, k + 1, &v[3]);
        List_Read(L1, k + 1, &v[4]);
        List_Read(L2, k + 1, &v[5]);
      }

      k++;
      if (ep->mesh.ZonLayer[i]){

        if(ep->mesh.Recombine){
          if(s->V[3])
	    Create_HexPri(ep->mesh.ZonLayer[i],v);
          else
	    Create_PriPyrTet(ep->mesh.ZonLayer[i],v);
        }
        else{
          
          if (are_exist (v[3], v[1], Tree_Ares) &&
              are_exist (v[4], v[2], Tree_Ares) &&
              are_exist (v[3], v[2], Tree_Ares)){
            news = Create_Simplex (v[0], v[1], v[2], v[3]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[4], v[5], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[1], v[3], v[4], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v[3], v[1], Tree_Ares) &&
              are_exist (v[1], v[5], Tree_Ares) &&
              are_exist (v[3], v[2], Tree_Ares)){
            news = Create_Simplex (v[0], v[1], v[2], v[3]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[4], v[5], v[1]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[1], v[5], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v[3], v[1], Tree_Ares) &&
              are_exist (v[1], v[5], Tree_Ares) &&
              are_exist (v[5], v[0], Tree_Ares)){
            news = Create_Simplex (v[0], v[1], v[2], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[4], v[5], v[1]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[1], v[3], v[5], v[0]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v[4], v[0], Tree_Ares) &&
              are_exist (v[4], v[2], Tree_Ares) &&
              are_exist (v[3], v[2], Tree_Ares)){
            news = Create_Simplex (v[0], v[1], v[2], v[4]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[4], v[5], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[0], v[3], v[4], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v[4], v[0], Tree_Ares) &&
              are_exist (v[4], v[2], Tree_Ares) &&
              are_exist (v[5], v[0], Tree_Ares)){
            news = Create_Simplex (v[0], v[1], v[2], v[4]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[4], v[5], v[0]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[0], v[2], v[4], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
          }
          if (are_exist (v[4], v[0], Tree_Ares) &&
              are_exist (v[1], v[5], Tree_Ares) &&
              are_exist (v[5], v[0], Tree_Ares)){
            news = Create_Simplex (v[0], v[1], v[2], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[3], v[4], v[5], v[0]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add (THEV->Simplexes, &news);
            news = Create_Simplex (v[0], v[1], v[4], v[5]);
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
  List_T *L0, *L1, *L2;

  pS = (Simplex **) data;
  s = *pS;

  L0 = getnxl(s->V[0],DIM);
  L1 = getnxl(s->V[1],DIM);
  L2 = getnxl(s->V[2],DIM);

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      List_Read (L0, k, &v1);
      List_Read (L1, k, &v2);
      List_Read (L2, k, &v3);
      List_Read (L0, k + 1, &v4);
      List_Read (L1, k + 1, &v5);
      List_Read (L2, k + 1, &v6);
      k++;
      //if((double)rand()/(double)RAND_MAX < 0.1) break;
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
  nxl NXL;

  pV = (Vertex **) data;
  v = *pV;

  if(!v->Extruded_Points)
    v->Extruded_Points = List_Create (1, 1, sizeof (nxl));

  NXL.Num = NUM;
  NXL.Dim = DIM;
  if(List_Search(v->Extruded_Points, &NXL, compnxl))
    return;
  else
    NXL.List = List_Create(ep->mesh.NbLayer, 1, sizeof (Vertex *));

  List_Add (NXL.List, &v);

  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      newv = Create_Vertex (++CurrentNodeNumber, v->Pos.X,
                            v->Pos.Y, v->Pos.Z, v->lc, v->u);
      ep->Extrude (i, j + 1, newv->Pos.X, newv->Pos.Y, newv->Pos.Z);

      if (Vertex_Bound && (pV = (Vertex **) Tree_PQuery (Vertex_Bound, &newv))){
	Free_Vertex (&newv,0);
        List_Add (NXL.List, pV);
        if (ToAdd)
          Tree_Insert (ToAdd, pV);
      }
      else{
        List_Add (NXL.List, &newv);
        Tree_Insert (THEM->Vertices, &newv);
        Tree_Insert (Vertex_Bound, &newv);
        if (ToAdd)
          Tree_Insert (ToAdd, &newv);
      }
    }
  }

  List_Add(v->Extruded_Points, &NXL); 
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
  List_T *L1, *L2;

  L1 = getnxl(V1,DIM);
  L2 = getnxl(V2,DIM);

  k = 0;
  for (i = 0; i < ep->mesh.NbLayer; i++){
    for (j = 0; j < ep->mesh.NbElmLayer[i]; j++){
      List_Read (L1, k, &v1);
      List_Read (L2, k, &v2);
      List_Read (L1, k + 1, &v3);
      List_Read (L2, k + 1, &v4);
      if(ep->mesh.Recombine){
        s = Create_Quadrangle(v1,v2,v4,v3);
        s->iEnt = THES->Num; 
	s->Num = -s->Num; //Tag quadrangles to re-extrude
        Tree_Add(THES->Simplexes,&s);

	// This is horrible
	THEM->Statistics[8] += 1;
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
  List_T *L;

  if (!c->Extrude || !c->Extrude->mesh.ExtrudeMesh) return false;

  InitExtrude();
  THEC = c;
  DIM = 1;
  NUM = c->Num;
  ep = c->Extrude;

  if (ep->geo.Mode == EXTRUDED_ENTITY){
    Extrude_Vertex (&c->beg, NULL);
    L = getnxl(c->beg,DIM);

    c->Vertices = List_Create (List_Nbr(L), 2, sizeof (Vertex *));
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

    for (i = 1; i < List_Nbr(L) - 1; i++){
      List_Read (L, i, &v1);
      if (!v1->ListCurves) v1->ListCurves = List_Create (1, 1, sizeof (Curve *));
      List_Add(v1->ListCurves, &c);
      Tree_Insert (THEM->Vertices, &v1);
      v1->u = (double) i / (double) List_Nbr(L);
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
	  //Crash gcc2.95! Free_Vertex(&vi[j],0);
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
    if(vi[3]){
      news = Create_Quadrangle (vi[0], vi[1], vi[2], vi[3]);
      // This is horrible
      THEM->Statistics[8] += 1;
    }
    else
      news = Create_Simplex (vi[0], vi[1], vi[2], NULL);
    news->iEnt = to->Num;
    Tree_Add (to->Simplexes, &news);
  }
  List_Delete (list);
}

int Extrude_Mesh (Surface * s){
  int i, j;
  Vertex *v1;
  Curve *c;
  extern int FACE_DIMENSION;

  if (!s->Extrude || !s->Extrude->mesh.ExtrudeMesh) return false;

  InitExtrude ();
  THES = s;
  DIM = 2;
  NUM = s->Num;
  ep = s->Extrude;

  FACE_DIMENSION = 2;

  ToAdd = s->Vertices;

  for (i = 0; i < List_Nbr (s->Generatrices); i++){
    List_Read (s->Generatrices, i, &c);
    for (j = 0; j < List_Nbr (c->Vertices); j++){
      List_Read (c->Vertices, j, &v1);
      Tree_Insert (Vertex_Bound, &v1);
    }
  }
  if (ep->geo.Mode == EXTRUDED_ENTITY){
    c = FindCurve (abs(ep->geo.Source), THEM);
    if (!c) return false;
    for (i = 0; i < List_Nbr (c->Vertices); i++){
      List_Read (c->Vertices, i, &v1);
      Extrude_Vertex (&v1, NULL);
    }
    Extrude_Curve (&c, NULL);
  }
  else{
    Surface *ss = FindSurface (ep->geo.Source, THEM);
    if (!ss) return false;
    copy_mesh (ss, s);
  }

  return true;
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
  ep = v->Extrude;
  if (ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return true;
  else return false;
}

int Extrude_Mesh (Tree_T * Volumes){
  int i, j, extrude=0;
  Surface *s;
  Vertex *v1;
  List_T *list;

  InitExtrude ();
  DIM = 3;

  List_T *vol = Tree2List(Volumes);

  for (int ivol = 0; ivol < List_Nbr(vol); ivol++){
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY){
      extrude = 1;
      for (i = 0; i < List_Nbr (THEV->Surfaces); i++){
	List_Read (THEV->Surfaces, i, &s);
	list = Tree2List (s->Vertices);
	for (int j = 0; j < List_Nbr (list); j++){
	  List_Read (list, j, &v1);
	  Tree_Insert (Vertex_Bound, &v1);
	}
	List_Delete (list);
      }
    }
  }
  if(!extrude) return false;

  Msg(STATUS2, "Mesh 3D... (initial)");

  for (int ivol = 0; ivol < List_Nbr (vol); ivol++){
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    NUM = THEV->Num;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY){
      s = FindSurface (ep->geo.Source, THEM);
      if(s){
	Msg(STATUS3, "Meshing Volume %d", NUM);
	Extrude_Surface1 (s);
      }
    }
  }

  j = 0;
  do{
    TEST_IS_ALL_OK=0;
    for (int ivol = 0; ivol < List_Nbr (vol); ivol++){
      List_Read(vol, ivol, &THEV);
      ep = THEV->Extrude;
      NUM = THEV->Num;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY && 
	 !ep->mesh.Recombine){
	s = FindSurface (ep->geo.Source, THEM);
	if(s) Extrude_Surface2 (s);
      }
    }
    Msg(STATUS3, "Swapping %d", TEST_IS_ALL_OK); 
    if(TEST_IS_ALL_OK == j){
      if(j) Msg(GERROR, "Unable to swap all edges: try Recombine...");
      break;
    }
    j = TEST_IS_ALL_OK;
  }while(TEST_IS_ALL_OK);

  Msg(STATUS2, "Mesh 3D... (Final)"); 

  for (int ivol = 0; ivol < List_Nbr (vol); ivol++){
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    NUM = THEV->Num;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY){
      s = FindSurface (ep->geo.Source, THEM);
      if(s){
	Msg(STATUS3, "Meshing Volume %d", NUM);
	Extrude_Surface3 (s);
      }
    }
  }

  list= List_Create(100,100,sizeof(Surface*));
  for (int ivol = 0; ivol < List_Nbr (vol); ivol++){
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY && 
       !ep->mesh.Recombine){
      for (i = 0; i < List_Nbr (THEV->Surfaces); i++){
	List_Read(THEV->Surfaces, i, &s);
	if(!List_Search(list, &s, compareSurface))
	  List_Add(list, &s);
      }
    }
  }
  for(i = 0; i<List_Nbr(list); i++){
    List_Read (list, i, &s);
    tmp = Tree_Create (sizeof (Simplex *), compareQuality);
    Tree_Action(s->Simplexes, Free_NegativeSimplex);
    Tree_Delete(s->Simplexes);
    s->Simplexes = tmp;
    Msg(STATUS3, "Coherence Surface %d", s->Num);
    Extrude_Mesh(s);
  }

  List_Delete(list);
  List_Delete(vol);

  return true;

}

