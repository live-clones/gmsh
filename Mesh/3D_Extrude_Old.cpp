// $Id: 3D_Extrude_Old.cpp,v 1.17 2001-12-05 16:02:38 geuzaine Exp $

// This is the old extrusion mesh generator -> only available through
// the command line option -extrude (w/o -recombine). This mesh
// generator pre-supposes a definition of surfaces in the XY plane,
// and will extrude everything along the Z axis, taking parameters
// interactively from standard input, e.g.
//
// gmsh test -extrude -recombine < params.ext
//
// The progression ratio defines a geometric progression for the
// definition of the elements heights: a factor of 2 means that the
// next element will be twice as high than the preceding one.
//
// All geometrical entities are automatically numbered:
//
//         volumes: 3 * K1 + layer * K2 + surf->num
// New XY surfaces: 2 * K1 + layer * K2 + surf->num
//  perp. surfaces: 1 * K1 + layer * K2 + curve->num
//     perp. lines: 4 * K1 + layer * K2 + point->Num
//    New XY lines: 5 * K1 + layer * K2 + curve->Num
//

#define MAXLAYERS 100
#define K1 100.e6
#define K2 1.e6 // to store MAXLAYERS

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Context.h"
#include "Create.h"

extern Context_T CTX ;
extern Mesh   *LOCAL, *THEM;

static Tree_T *Tree_Ares, *Tree_Swaps;

FILE          *file;
Mesh          *THEm;
Surface       *THES;
Volume        *THEV;
int            TEST_IS_ALL_OK, NbLayer;
int            NbElmLayer [MAXLAYERS];
int            ZonLayer   [MAXLAYERS];
int            LineLayer  [MAXLAYERS+1];
int            SurfLayer  [MAXLAYERS+1];
double         hLayer     [MAXLAYERS];
double         parLayer   [MAXLAYERS];


typedef struct {
  int a,b;
}nxn;

static int compnxn(const void *a, const void *b){
  nxn *q,*w;
  q = (nxn*)a;
  w = (nxn*)b;
  if(q->a > w->a)return 1;
  if(q->a < w->a)return -1;
  if(q->b > w->b)return 1;
  if(q->b < w->b)return -1;
  return 0;
}

static void InitExtrudeParams (void){
  int i;
  printf("Number of layers: ");
  scanf("%d",&NbLayer);
  if(NbLayer >MAXLAYERS)
    Msg(GERROR, "Max number of layer exceeded");
  fprintf(file, "%d\n", NbLayer); fflush(file);
  for(i=0;i<NbLayer;i++){
    printf("Number of elements in layer %d: ",i+1);
    scanf("%d",&NbElmLayer[i]);
    fprintf(file, "%d\n", NbElmLayer[i]);fflush(file);

    printf("Depth of layer %d: ",i+1);
    scanf("%lf",&hLayer[i]);
    fprintf(file, "%g\n", hLayer[i]);fflush(file);

    printf("Progresion ratio for layer %d: ",i+1);
    scanf("%lf",&parLayer[i]);
    fprintf(file, "%g\n", parLayer[i]);fflush(file);
  }
  Tree_Ares = Tree_Create(sizeof(nxn),compnxn);
  Tree_Swaps = Tree_Create(sizeof(nxn),compnxn);
}

static int are_exist(Vertex *v1,Vertex *v2, Tree_T *t){
  nxn n;
  n.a = IMAX(v1->Num,v2->Num);
  n.b = IMIN(v1->Num,v2->Num);
  return Tree_Search(t,&n);
}

static void are_cree(Vertex *v1,Vertex *v2, Tree_T *t){
  nxn n;
  n.a = IMAX(v1->Num,v2->Num);
  n.b = IMIN(v1->Num,v2->Num);
  Tree_Replace(t,&n);
}

static void are_del(Vertex *v1,Vertex *v2, Tree_T *t){
  nxn n;
  n.a = IMAX(v1->Num,v2->Num);
  n.b = IMIN(v1->Num,v2->Num);
  Tree_Suppress(t,&n);
}


static void Extrude_Simplex_Phase1 (void *data , void *dum){
  
  Simplex **pS , *s;
  int i,j,k;
  Vertex *v1,*v2,*v3,*v4,*v5,*v6;

  pS = (Simplex**)data;
  s = *pS;

  k = 0;
  for(i=0;i<NbLayer;i++){
    for(j=0;j<NbElmLayer[i];j++){
      List_Read(s->V[0]->Extruded_Points,k,&v1);
      List_Read(s->V[1]->Extruded_Points,k,&v2);
      List_Read(s->V[2]->Extruded_Points,k,&v3);
      List_Read(s->V[0]->Extruded_Points,k+1,&v4);
      List_Read(s->V[1]->Extruded_Points,k+1,&v5);
      List_Read(s->V[2]->Extruded_Points,k+1,&v6);
      k++;
      if(!are_exist(v1,v5,Tree_Ares))are_cree(v2,v4,Tree_Ares);
      if(!are_exist(v5,v3,Tree_Ares))are_cree(v2,v6,Tree_Ares);
      if(!are_exist(v4,v3,Tree_Ares))are_cree(v1,v6,Tree_Ares);
    }
  }  
}

static void Extrude_Simplex_Phase3 (void *data , void *dum){
  
  Simplex **pS , *s, *news;
  Prism   *newp;
  Hexahedron *newh;
  int i,j,k;
  Vertex *v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8;

  pS = (Simplex**)data;
  s = *pS;

  if(s->V[3] && !CTX.mesh.oldxtrude_recombine){
    Msg(GERROR, "Non recombined extrusion impossible with quadrangles (use -recombine)");
  }

  k = 0;
  for(i=0;i<=NbLayer;i++){
    if(SurfLayer[i]){
      List_Read(s->V[0]->Extruded_Points,k,&v1);
      List_Read(s->V[1]->Extruded_Points,k,&v2);
      List_Read(s->V[2]->Extruded_Points,k,&v3);      
      news = Create_Simplex(v1,v2,v3,NULL);
      if(s->V[3]){
	List_Read(s->V[3]->Extruded_Points,k,&v4);
	news->V[3] = v4;
      }
      news->iEnt = SurfLayer[i];
      Tree_Add(THEV->Simp_Surf,&news);
    }
    for(j=0;j<NbElmLayer[i];j++){
      k++;
    }
  }
  
  k = 0;
  for(i=0;i<NbLayer;i++){
    for(j=0;j<NbElmLayer[i];j++){

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
	List_Read(s->V[0]->Extruded_Points,k,&v1);
	List_Read(s->V[1]->Extruded_Points,k,&v2);
	List_Read(s->V[2]->Extruded_Points,k,&v3);
	List_Read(s->V[0]->Extruded_Points,k+1,&v4);
	List_Read(s->V[1]->Extruded_Points,k+1,&v5);
	List_Read(s->V[2]->Extruded_Points,k+1,&v6);
      }

      k++;
      if(ZonLayer[i]){
	if(CTX.mesh.oldxtrude_recombine){
	  if(s->V[3]){
	    newh = Create_Hexahedron(v1,v2,v3,v4,v5,v6,v7,v8);
	    newh->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Hexahedra,&newh);
	  }
	  else{
	    newp = Create_Prism(v1,v2,v3,v4,v5,v6);
	    newp->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Prisms,&newp);
	  }
	}
	else{
	  if(are_exist(v4,v2,Tree_Ares) && 
	     are_exist(v5,v3,Tree_Ares) && 
	     are_exist(v4,v3,Tree_Ares) ){
	    news = Create_Simplex(v1,v2,v3,v4);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v5,v6,v3);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v2,v4,v5,v3);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	  }
	  if(are_exist(v4,v2,Tree_Ares) && 
	     are_exist(v2,v6,Tree_Ares) && 
	     are_exist(v4,v3,Tree_Ares) ){
	    news = Create_Simplex(v1,v2,v3,v4);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v5,v6,v2);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v2,v6,v3);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	  }
	  if(are_exist(v4,v2,Tree_Ares) && 
	     are_exist(v2,v6,Tree_Ares) && 
	     are_exist(v6,v1,Tree_Ares) ){
	    news = Create_Simplex(v1,v2,v3,v6);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v5,v6,v2);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v2,v4,v6,v1);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	  }
	  if(are_exist(v5,v1,Tree_Ares) && 
	     are_exist(v5,v3,Tree_Ares) && 
	     are_exist(v4,v3,Tree_Ares)  ){
	    news = Create_Simplex(v1,v2,v3,v5);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v5,v6,v3);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v1,v4,v5,v3);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	  }
	  if(are_exist(v5,v1,Tree_Ares) && 
	     are_exist(v5,v3,Tree_Ares) && 
	     are_exist(v6,v1,Tree_Ares)  ){
	    news = Create_Simplex(v1,v2,v3,v5);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v5,v6,v1);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v1,v3,v5,v6);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	  }
	  if(are_exist(v5,v1,Tree_Ares) && 
	     are_exist(v2,v6,Tree_Ares) && 
	     are_exist(v6,v1,Tree_Ares)  ){
	    news = Create_Simplex(v1,v2,v3,v6);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v4,v5,v6,v1);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	    news = Create_Simplex(v1,v2,v5,v6);
	    news->iEnt = ZonLayer[i];
	    Tree_Add(THEV->Simplexes,&news);
	  }
	}
      }
    }
  }  
}

static void Extrude_Simplex_Phase2 (void *data , void *dum){
  
  Simplex **pS , *s;
  int i,j,k;
  Vertex *v1,*v2,*v3,*v4,*v5,*v6;

  pS = (Simplex**)data;
  s = *pS;

  k = 0;
  for(i=0;i<NbLayer;i++){
    for(j=0;j<NbElmLayer[i];j++){
      List_Read(s->V[0]->Extruded_Points,k,&v1);
      List_Read(s->V[1]->Extruded_Points,k,&v2);
      List_Read(s->V[2]->Extruded_Points,k,&v3);
      List_Read(s->V[0]->Extruded_Points,k+1,&v4);
      List_Read(s->V[1]->Extruded_Points,k+1,&v5);
      List_Read(s->V[2]->Extruded_Points,k+1,&v6);
      k++;
      if(are_exist(v4,v2,Tree_Ares) && 
	 are_exist(v5,v3,Tree_Ares) && 
	 are_exist(v1,v6,Tree_Ares)){
	TEST_IS_ALL_OK++;
	if(!are_exist(v4,v2,Tree_Swaps)){
	  are_del(v4,v2,Tree_Ares);
	  are_cree(v1,v5,Tree_Ares);
	  are_cree(v1,v5,Tree_Swaps);
	  are_cree(v4,v2,Tree_Swaps);
	}
	else if(!are_exist(v5,v3,Tree_Swaps)){
	  are_del(v5,v3,Tree_Ares);
	  are_cree(v2,v6,Tree_Ares);
	  are_cree(v5,v3,Tree_Swaps);
	  are_cree(v2,v6,Tree_Swaps);
	}
	else if(!are_exist(v1,v6,Tree_Swaps)){
	  are_del(v1,v6,Tree_Ares);
	  are_cree(v4,v3,Tree_Ares);
	  are_cree(v1,v6,Tree_Swaps);
	  are_cree(v4,v3,Tree_Swaps);
	}
      }
      else if(are_exist(v1,v5,Tree_Ares) && 
	      are_exist(v2,v6,Tree_Ares) && 
	      are_exist(v4,v3,Tree_Ares)){
	TEST_IS_ALL_OK++;
	if(!are_exist(v1,v5,Tree_Swaps)){
	  are_del(v1,v5,Tree_Ares);
	  are_cree(v4,v2,Tree_Ares);
	  are_cree(v1,v5,Tree_Swaps);
	  are_cree(v4,v2,Tree_Swaps);
	}
	else if(!are_exist(v2,v6,Tree_Swaps)){
	  are_del(v2,v6,Tree_Ares);
	  are_cree(v5,v3,Tree_Ares);
	  are_cree(v5,v3,Tree_Swaps);
	  are_cree(v2,v6,Tree_Swaps);
	}
	else if(!are_exist(v4,v3,Tree_Swaps)){
	  are_del(v4,v3,Tree_Ares);
	  are_cree(v1,v6,Tree_Ares);
	  are_cree(v1,v6,Tree_Swaps);
	  are_cree(v4,v3,Tree_Swaps);
	}	
      }
    }
  }  
}

static void Extrude_Vertex (void *data , void *dum){

  Vertex **pV , *v, *newv;
  int i,j;
  double h,a;

  pV = (Vertex**)data;
  v = *pV;
  if(v->Extruded_Points)return;
  v->Extruded_Points = List_Create(NbLayer,1,sizeof(Vertex*));
  List_Add(v->Extruded_Points,&v);
  h = 0.0;

  //printf("-extruding vertex %d %p\n", v->Num, v);
 
  for(i=0;i<NbLayer;i++){

    // Geometric progression ar^i
    // Sum of n (=NbElmLayer[i]) terms = hLayer[i] = a (r^n-1)/(r-1)

    if(parLayer[i] == 1.)
      a = hLayer[i]/(double)NbElmLayer[i];
    else
      a = hLayer[i] * (parLayer[i]-1.)/(pow(parLayer[i],NbElmLayer[i])-1.) ;

    for(j=0;j<NbElmLayer[i];j++){

      //h += hLayer[i]/(double)NbElmLayer[i];
      
      h += a*pow(parLayer[i],j);

      newv = Create_Vertex(++THEM->MaxPointNum,v->Pos.X,v->Pos.Y,v->Pos.Z + h, v->lc , v->u );
      Tree_Add(THEM->Vertices,&newv);
      List_Add(v->Extruded_Points,&newv);
    }
  }
}


static void Extrude_Surface1 (void *data , void *dum){
  Surface **pS , *s;
  if(!NbLayer)return;
  pS = (Surface**)data;
  s = THES = *pS;

  Tree_Action(s->Vertices,Extrude_Vertex);
  if(!CTX.mesh.oldxtrude_recombine) Tree_Action(s->Simplexes,Extrude_Simplex_Phase1);
}

static void Extrude_Surface2 (void *data , void *dum){
  Surface **pS , *s;
  if(!NbLayer)return;
  pS = (Surface**)data;
  s = THES = *pS;

  Tree_Action(s->Simplexes,Extrude_Simplex_Phase2);
}


static void Extrude_Surface3 (void *data , void *dum){
  Surface **pS , *s;
  int i;
  if(!NbLayer)return;
  pS = (Surface**)data;
  s = THES = *pS;

  /* Numerotation automatique des entites physiques */
  Msg(INFO, "Extruding Surface %d", s->Num);
  for(i=0;i<NbLayer;i++){
    ZonLayer[i] = (int)(3 * K1) + (int) ((i+1) * K2) + s->Num ;
  }
  SurfLayer[0] = s->Num ;
  for(i=0;i<NbLayer;i++){
    SurfLayer[i+1] = (int)(2 * K1) + (int)((i+1) * K2) + s->Num ;
  }

  Tree_Action(s->Simplexes,Extrude_Simplex_Phase3);
}


static void Extrude_Seg(Vertex *V1, Vertex *V2){

  int i,j,k;
  Vertex *v1,*v2,*v3,*v4;
  Simplex *s;

  //printf("-curve vertex %d %p   %d %p\n", V1->Num, V1, V2->Num, V2);

  k = 0;
  for(i=0;i<=NbLayer;i++){
    if(LineLayer[i]){
      List_Read(V1->Extruded_Points,k,&v1);
      List_Read(V2->Extruded_Points,k,&v2);
      s = Create_Simplex(v1,v2,NULL,NULL);
      s->iEnt = LineLayer[i];
      Tree_Add(THEV->Simp_Surf,&s);
    }
    for(j=0;j<NbElmLayer[i];j++){
      k++;
    }
  }

  k = 0;
  for(i=0;i<NbLayer;i++){
    for(j=0;j<NbElmLayer[i];j++){
      List_Read(V1->Extruded_Points,k,&v1);
      List_Read(V2->Extruded_Points,k,&v2);
      List_Read(V1->Extruded_Points,k+1,&v3);
      List_Read(V2->Extruded_Points,k+1,&v4);
      if(SurfLayer[i]){
	if(CTX.mesh.oldxtrude_recombine){
	  s = Create_Simplex(v1,v2,v4,NULL);
	  s->V[3] = v3;
	  s->iEnt = SurfLayer[i];
	  Tree_Add(THEV->Simp_Surf,&s);
	}
	else{
	  if(are_exist(v3,v2,Tree_Ares)){
	    s = Create_Simplex(v3,v2,v1,NULL);
	    s->iEnt = SurfLayer[i];
	    Tree_Add(THEV->Simp_Surf,&s);
	    s = Create_Simplex(v3,v4,v2,NULL);
	    s->iEnt = SurfLayer[i];
	    Tree_Add(THEV->Simp_Surf,&s);
	  }
	  else{
	    s = Create_Simplex(v3,v4,v1,NULL);
	    s->iEnt = SurfLayer[i];
	    Tree_Add(THEV->Simp_Surf,&s);
	    s = Create_Simplex(v1,v4,v2,NULL);
	    s->iEnt = SurfLayer[i];
	    Tree_Add(THEV->Simp_Surf,&s);
	  }
	}
      }
      k++;
    }
  }  

}

static void Extrude_Curve (void *data , void *dum){
  Curve **pC , *c;
  Vertex *v1,*v2;
  int i;
  if(!NbLayer)return;
  pC = (Curve**)data;
  c = *pC;
  
  if (c->Num < 0) return;

  /* Numerotation automatique des entites physiques */
  Msg(INFO, "Extruding Curve %d", c->Num);

  LineLayer[0] = c->Num ;
  for(i=0;i<NbLayer;i++){
    SurfLayer[i] = (int)(1 * K1) + (int)((i+1) * K2) + c->Num ;
    LineLayer[i+1] = (int)(5 * K1) + (int)((i+1) * K2) + c->Num ;
  }

  for(i=0;i<List_Nbr(c->Vertices)-1;i++){
    List_Read(c->Vertices,i,&v1);
    List_Read(c->Vertices,i+1,&v2);
    Extrude_Seg(v1,v2);
  } 
}

static void Extrude_Pnt(Vertex *V1){
  int i,j,k;
  Vertex *v1,*v2;
  Simplex *s;

  k = 0;
  for(i=0;i<NbLayer;i++){
    for(j=0;j<NbElmLayer[i];j++){
      List_Read(V1->Extruded_Points,k,&v1);
      List_Read(V1->Extruded_Points,k+1,&v2);
      if(LineLayer[i]){
	s = Create_Simplex(v1,v2,NULL,NULL);
	s->iEnt = LineLayer[i];
	Tree_Add(THEV->Simp_Surf,&s);
      }
      k++;
    }
  }  
  
}

static void Extrude_Point (void *data , void *dum){
  Vertex **pV, *v, **pV2;
  int i;

  if(!NbLayer)return;
  pV = (Vertex**)data;
  v = *pV;
  
  /* Numerotation automatique des entites physiques */
  Msg(INFO, "Extruding Vertex %d", v->Num);
  for(i=0;i<NbLayer;i++){
    LineLayer[i] = (int)(4 * K1) + (int)((i+1) * K2) + v->Num ;
  }

  if((pV2 = (Vertex**)Tree_PQuery(THEM->Vertices, pV))){
    Extrude_Vertex(pV2, NULL);
    Extrude_Pnt(*pV2);
  }

}

void FreeEP(void *a, void *b){
  Vertex *v = *((Vertex**)a);
  Free_ExtrudedPoints(v->Extruded_Points);
  v->Extruded_Points = NULL;
}

void Extrude_Mesh_Old(Mesh *M){
  int j;
  Mesh MM;

  file = fopen("xtrude","w");

  InitExtrudeParams();
  LOCAL = &MM;
  THEM  = M;

  //clean up Extruded_Points stuff (in case another extrusion was
  //performed before)
  Tree_Action(THEM->Vertices,FreeEP);

  Create_BgMesh (WITHPOINTS, .2, LOCAL);

  Tree_Left(M->Volumes,&THEV);
  Tree_Action(M->Surfaces, Extrude_Surface1);

  if(!CTX.mesh.oldxtrude_recombine){
    j = 0;
    do{
      TEST_IS_ALL_OK=0;
      Tree_Action ( M->Surfaces , Extrude_Surface2 );
      Msg(INFO, "%d swaps", TEST_IS_ALL_OK);
      if(TEST_IS_ALL_OK == j)break;
      j = TEST_IS_ALL_OK;
    }while(TEST_IS_ALL_OK);
  }

  Tree_Action ( M->Surfaces , Extrude_Surface3 );
  Tree_Action ( M->Curves , Extrude_Curve );
  Tree_Action ( M->Points , Extrude_Point );

  fclose(file);

}

