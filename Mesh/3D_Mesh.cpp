// $Id: 3D_Mesh.cpp,v 1.23 2001-08-01 16:37:15 geuzaine Exp $

/*
 
  J-F Remacle 1995

  MAILLAGE DELAUNAY 3D 

  tant que l'arbre des tetraedres de qualites inacceptables 
  n'est pas vide {
    prendre le plus mauvais tetraedre;
    creer un nouveau point;
    eliminer les tetraedres dont le cercle circonscrit contient le point;
    reconstruire le volume convexe;
  } 

*/

#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"
#include "3D_Mesh.h"
#include "Create.h"
#include "Numeric.h"
#include "Context.h"

extern Mesh       *THEM, *LOCAL;
extern Context_T   CTX;
extern int         CurrentNodeNumber, FACE_DIMENSION;

static Tree_T *Tsd, *Sim_Sur_Le_Bord, *POINTS_TREE;
static List_T *Simplexes_Destroyed, *Simplexes_New, *Suppress;
static List_T *LLL, *POINTS;
static Simplex *THES;
static Vertex *THEV;
static Tree_T *SimXFac;
static double volume, LC3D;
static int ZONEELIMINEE, Methode = 0;

Simplex  MyNewBoundary;
int      Alerte_Point_Scabreux;

void DebugSimplexe (Simplex * s){
  int i;

  fprintf (stderr, "Simplexe %p = %d %d %d %d \n",
           s, s->V[0]->Num, s->V[1]->Num, s->V[2]->Num, s->V[3]->Num);

  for (i = 0; i < 4; i++){
    if (s->S[i] != &MyNewBoundary)
      printf (" face : %d %d %d -> Simplexe %p\n",
              s->F[i].V[0]->Num, s->F[i].V[1]->Num, s->F[i].V[2]->Num, s->S[i]);
    else
      printf (" face : %d %d %d -> Simplexe Boundary\n",
              s->F[i].V[0]->Num, s->F[i].V[1]->Num, s->F[i].V[2]->Num);
  }
}

void VSIM (void *a, void *b){
  Simplex *S;

  S = *(Simplex **) a;
  if (S->V[3])
    volume += fabs (S->Volume_Simplexe ());
}

void add_points (void *a, void *b){
  Tree_Insert (POINTS_TREE, a);
}

void add_points_2 (void *a, void *b){
  List_Add (POINTS, a);
}


double Interpole_lcTetraedre (Simplex * s, Vertex * v){
  double mat[3][3], rhs[3], sol[3], det;

  s->matsimpl (mat);
  rhs[0] = v->Pos.X - s->V[0]->Pos.X;
  rhs[1] = v->Pos.Y - s->V[0]->Pos.Y;
  rhs[2] = v->Pos.Z - s->V[0]->Pos.Z;

  sys3x3 (mat, rhs, sol, &det);
  if (det == 0.0 ||
      (1. - sol[0] - sol[1] - sol[2]) > 1. ||
      (1. - sol[0] - sol[1] - sol[2]) < 0. ||
      sol[0] > 1. ||
      sol[1] > 1. ||
      sol[2] > 1. ||
      sol[0] < 0. ||
      sol[1] < 0. ||
      sol[2] < 0.){
    return DMAX (s->V[0]->lc, DMAX (s->V[1]->lc, DMAX (s->V[2]->lc, s->V[3]->lc)));
    //sol[0] = sol[1] = sol[2] = 0.25;
  }

  return (s->V[0]->lc * (1. - sol[0] - sol[1] - sol[2]) +
          sol[0] * s->V[1]->lc +
          sol[1] * s->V[2]->lc +
          sol[2] * s->V[3]->lc);
}

Vertex *NewVertex (Simplex * s){
  Vertex *v;

  v = Create_Vertex (++CurrentNodeNumber, s->Center.X, s->Center.Y, s->Center.Z, 1., 0.0);
  v->lc = Interpole_lcTetraedre (s, v);

  return (v);
}

int Pt_In_Volume (double X, double Y, double Z, Mesh * m,
                  double *l, double tol){
  int i;
  Vertex V;
  double uvw[3];
  Simplex *s;
  Brick B;

  V.Pos.X = X;
  V.Pos.Y = Y;
  V.Pos.Z = Z;

  if (!(m->BGM.Typ == ONFILE) && !m->BGM.bgm){
    *l = -1.0;
    return (1);
  }

  B = LaBrique (&m->Grid, X, Y, Z);

  if (B.N < 0){
    return (0);
  }

  for (i = 0; i < List_Nbr (B.pT); i++){
    List_Read (B.pT, i, &s);
    if (s->Pt_In_Simplexe (&V, uvw, tol)){
      *l = (1. - uvw[0] - uvw[1] - uvw[2]) * s->V[0]->lc
        + uvw[0] * s->V[1]->lc
        + uvw[1] * s->V[2]->lc
        + uvw[2] * s->V[3]->lc;
      return (1);
    }
  }

  return (0);
}

int Pt_In_Circum (Simplex * s, Vertex * v){
  double d1, d2, eps;

  /* Determine si un point est dans le cercle circonscrit a un simplexe */

  d1 = s->Radius;
  d2 = sqrt (DSQR (v->Pos.X - s->Center.X) +
             DSQR (v->Pos.Y - s->Center.Y) +
             DSQR (v->Pos.Z - s->Center.Z));

  eps = fabs (d1 - d2) / (d1 + d2);

  if (eps < 1.e-12){
    return (0); // return 1 ? 0 ?
  }
      
  if (d2 < d1)
    return (1);

  return (0);
}

void Action_First_Simplexes (void *a, void *b){
  Simplex **q;

  if (!THES){
    q = (Simplex **) a;
    if (Pt_In_Circum (*q, THEV)){
      THES = *q;
    }
  }
}

void LiS (void *a, void *b){
  int j, N;
  SxF SXF, *pSXF;
  Simplex **pS, *S;

  pS = (Simplex **) a;
  S = *pS;
  N = (S->V[3]) ? 4 : 3;

  for (j = 0; j < N; j++){
    SXF.F = S->F[j];
    if ((pSXF = (SxF *) Tree_PQuery (SimXFac, &SXF))){
      /* Creation du lien */
      S->S[j] = pSXF->S;
      pSXF->S->S[pSXF->NumFaceSimpl] = S;
    }
    else{
      SXF.S = S;
      SXF.NumFaceSimpl = j;
      Tree_Add (SimXFac, &SXF);
    }
  }
}

void RzS (void *a, void *b){
  int j, N;
  Simplex **pS, *S;
  pS = (Simplex **) a;
  S = *pS;

  N = (S->V[3]) ? 4 : 3;

  for (j = 0; j < N; j++){
    if ((S->S[j]) == NULL){
      S->S[j] = &MyNewBoundary;
    }
  }
}

/* Cree les liens entre les simplexes, c.a.d recherche les voisins */

void Link_Simplexes (List_T * Sim, Tree_T * Tim){
  Simplex *S;
  int i;

  SimXFac = Tree_Create (sizeof (SxF), compareSxF);
  if (Sim){
    for (i = 0; i < List_Nbr (Sim); i++){
      List_Read (Sim, i, &S);
      LiS (&S, NULL);
    }
    for (i = 0; i < List_Nbr (Sim); i++){
      List_Read (Sim, i, &S);
      RzS (&S, NULL);
    }
  }
  else{
    Tree_Action (Tim, LiS);
    Tree_Action (Tim, RzS);
  }
  Tree_Delete (SimXFac);
}

void Box_6_Tetraedron (List_T * P, Mesh * m){
#define FACT 1.1
#define LOIN 0.2

  int i, j;
  static int pts[8][3] = { {0, 0, 0},
                           {1, 0, 0},
                           {1, 1, 0},
                           {0, 1, 0},
                           {0, 0, 1},
                           {1, 0, 1},
                           {1, 1, 1},
                           {0, 1, 1}};
  static int tet[6][4] = { {1, 5, 2, 4},
                           {2, 5, 6, 4},
                           {4, 5, 6, 8},
                           {6, 4, 8, 7},
                           {6, 4, 7, 3},
                           {2, 3, 4, 6}};
  double Xm, Ym, Zm, XM, YM, ZM, Xc, Yc, Zc;
  Simplex *S, *ps;
  Vertex *V, *v, *pv;
  List_T *smp;

  smp = List_Create (8, 1, sizeof (Simplex *));

  V = (Vertex *) Malloc (8 * sizeof (Vertex));

  for (i = 0; i < List_Nbr (P); i++){
    List_Read (P, i, &v);
    if (!i){
      Xm = XM = v->Pos.X;
      Ym = YM = v->Pos.Y;
      Zm = ZM = v->Pos.Z;
    }
    else{
      Xm = DMIN (Xm, v->Pos.X);
      XM = DMAX (XM, v->Pos.X);
      Ym = DMIN (Ym, v->Pos.Y);
      YM = DMAX (YM, v->Pos.Y);
      Zm = DMIN (Zm, v->Pos.Z);
      ZM = DMAX (ZM, v->Pos.Z);
    }
  }
  if (Xm == XM)
    XM = Xm + 1.;
  if (Ym == YM)
    YM = Ym + 1.;
  if (Zm == ZM)
    ZM = Zm + 1.;

  Xc = XM - Xm;
  Yc = YM - Ym;
  Zc = ZM - Zm;

  /* initialisation de la grille */

  m->Grid.init = 0;
  m->Grid.min.X = Xm - LOIN * FACT * Xc;
  m->Grid.min.Y = Ym - LOIN * FACT * Yc;
  m->Grid.min.Z = Zm - LOIN * FACT * Zc;
  m->Grid.max.X = XM + LOIN * FACT * Xc;
  m->Grid.max.Y = YM + LOIN * FACT * Yc;
  m->Grid.max.Z = ZM + LOIN * FACT * Zc;

  m->Grid.Nx = m->Grid.Ny = m->Grid.Nz = 20;

  /* Longueur Caracteristique */

  LC3D = sqrt (Xc * Xc + Yc * Yc + Zc * Zc);

  /* Points de la boite de 1 a 8 

     Z    8____________7
     |   /|           /|
     |  / |          / |
     | /  |         /  |
     5|/___|________/6  |
     |   4|________|___|3
     |   /         |   /
     |  / Y        |  /
     | /           | /
     |/____________|/___ X
     1             2

   */

  for (i = 0; i < 8; i++){
    if (pts[i][0])
      V[i].Pos.X = Xm - LOIN * Xc;
    else
      V[i].Pos.X = XM + LOIN * Xc;
    
    if (pts[i][1])
      V[i].Pos.Y = Ym - LOIN * Yc;
    else
      V[i].Pos.Y = YM + LOIN * Yc;
    
    if (pts[i][2])
      V[i].Pos.Z = Zm - LOIN * Zc;
    else
      V[i].Pos.Z = ZM + LOIN * Zc;
    
    V[i].Num = -(++CurrentNodeNumber);
    pv = &V[i];
    pv->lc = 1.0;
    pv->Mov = NULL;
    Tree_Replace (m->Vertices, &pv);
  }

  /* 6 Tetraedres forment le maillage de la boite */

  for (i = 0; i < 6; i++){
    S = Create_Simplex (&V[tet[i][0] - 1], &V[tet[i][1] - 1], 
                        &V[tet[i][2] - 1], &V[tet[i][3] - 1]);
    List_Add (smp, &S);
  }
  
  Link_Simplexes (smp, NULL);
  for (i = 0; i < List_Nbr (smp); i++){
    List_Read (smp, i, &ps);
    for (j = 0; j < 4; j++)
      if (ps->S[j] == NULL)
        ps->S[j] = &MyNewBoundary;
    Tree_Replace (m->Simplexes, &ps);
  }
  
}


void Fill_Sim_Des (void *a, void *b){
  Simplex **S;
  S = (Simplex **) a;
  if (Pt_In_Circum (*S, THEV))
    List_Add (Simplexes_Destroyed, a);
}

void TStoLS (void *a, void *b){
  List_Add (Simplexes_Destroyed, a);
}

void TAtoLA (void *a, void *b){
  List_Add (Simplexes_New, a);
}

void CrSi (void *a, void *b){
  SxF *S;
  Simplex *s;
  S = (SxF *) a;
  if (S->NumFaceSimpl == 1){
    s = Create_Simplex (THEV, S->F.V[0], S->F.V[1], S->F.V[2]);
    s->iEnt = ZONEELIMINEE;
    THEM->Metric->setSimplexQuality (s);
    List_Add (Simplexes_New, &s);
  }
  else if (S->NumFaceSimpl != 2){
    Msg(WARNING, "Huh! Panic in CrSi");
  }
}


void NewSimplexes (Mesh * m, List_T * Sim, List_T * news){
  int i, j;
  Tree_T *SimXFac;
  Simplex *S;
  SxF SXF, *pSXF;

  SimXFac = Tree_Create (sizeof (SxF), compareSxF);

  for (i = 0; i < List_Nbr (Sim); i++){
    List_Read (Sim, i, &S);
    if (!i)
      ZONEELIMINEE = S->iEnt;
    else {
      if (S->iEnt != ZONEELIMINEE){
        Msg(WARNING, "Huh! The elimination failed %d %d",
            S->iEnt, ZONEELIMINEE);
      }
    }
    for (j = 0; j < 4; j++){
      SXF.F = S->F[j];
      if ((pSXF = (SxF *) Tree_PQuery (SimXFac, &SXF))){
        (pSXF->NumFaceSimpl)++;
      }
      else{
        SXF.NumFaceSimpl = 1;
        Tree_Add (SimXFac, &SXF);
      }
    }
  }

  /* Les faces non communes sont obligatoirement a la frontiere ... 
     -> Nouveaux simplexes */

  Tree_Action (SimXFac, CrSi);
  Tree_Delete (SimXFac);
}



/* Methode recursive : Rempli Tsd les simplexes detruits 
   Invariant : Le simplexe est a eliminer
   Le simplexe n'est pas encore considere */

int recur_bowyer (Simplex * s){
  int i;

  Tree_Insert (Tsd, &s);
  for (i = 0; i < 4; i++){
    if (s->S[i] && s->S[i] != &MyNewBoundary && !Tree_Query (Tsd, &s->S[i])){
      if (Pt_In_Circum (s->S[i], THEV) && (s->iEnt == s->S[i]->iEnt)){
        recur_bowyer (s->S[i]);
      }
      else{
        if (s->iEnt != s->S[i]->iEnt){
	  //Msg(WARNING, "Point scabreux %d", s->S[i]->Num);
          Alerte_Point_Scabreux = 1;
        }
        Tree_Insert (Sim_Sur_Le_Bord, &s->S[i]);
      }
    }
  }
  return 1;
}

bool Bowyer_Watson (Mesh * m, Vertex * v, Simplex * S, int force){
  int i;
  Simplex *s;
  //  static int init = 1;
  double volumeold, volumenew;

  THEV = v;

  double x = (S->V[0]->Pos.X + S->V[1]->Pos.X + S->V[2]->Pos.X + S->V[3]->Pos.X) / 4.;
  double y = (S->V[0]->Pos.Y + S->V[1]->Pos.Y + S->V[2]->Pos.Y + S->V[3]->Pos.Y) / 4.;
  double z = (S->V[0]->Pos.Z + S->V[1]->Pos.Z + S->V[2]->Pos.Z + S->V[3]->Pos.Z) / 4.;

  if (force)
    THEM->Metric->Identity ();
  else
    THEM->Metric->setMetric (x, y, z);

  Tsd = Tree_Create (sizeof (Simplex *), compareSimplex);
  Sim_Sur_Le_Bord = Tree_Create (sizeof (Simplex *), compareSimplex);
  //  if (init){
    //    init = 0;
    //  }
  List_Reset (Simplexes_Destroyed);
  List_Reset (Simplexes_New);


  if (Methode){
    Tree_Action (m->Simplexes, Fill_Sim_Des);
  }
  else{
    recur_bowyer (S);
  }
  
  Tree_Action (Tsd, TStoLS);
  NewSimplexes (m, Simplexes_Destroyed, Simplexes_New);

  /* calcul des volumes des simplexes crees */

  if (Alerte_Point_Scabreux || !CTX.mesh.speed_max){
    volume = 0.0;
    for (i = 0; i < List_Nbr (Simplexes_Destroyed); i++){
      VSIM (List_Pointer (Simplexes_Destroyed, i), NULL);
    }
    volumeold = volume;
    volume = 0.0;
    for (i = 0; i < List_Nbr (Simplexes_New); i++){
      VSIM (List_Pointer (Simplexes_New, i), NULL);
    }
    volumenew = volume;
  }
  else{
    volumeold = 1.0;
    volumenew = 1.0;
  }

  /* critere du volume */

  if ((fabs (volumeold - volumenew) / (volumeold + volumenew)) > 1.e-8){
    if (Tree_Suppress (m->Simplexes, &S)){
      S->Quality = 0.0;
      Tree_Add (m->Simplexes, &S);
    }
    if(force){
      List_Reset (Simplexes_Destroyed);
      List_Reset (Simplexes_New);
      Tree_Delete (Sim_Sur_Le_Bord);
      Tree_Delete (Tsd);
      //printf(" Aie Aie Aie volume changed %g -> %g\n",volumeold,volumenew);
      return false;
    }
  }
  else{
    Tree_Add (m->Vertices, &THEV);
    for (i = 0; i < List_Nbr (Simplexes_New); i++){
      Tree_Add (m->Simplexes, List_Pointer (Simplexes_New, i));
    }
    
    /* Suppression des simplexes elimines */
    
    for (i = 0; i < List_Nbr (Simplexes_Destroyed); i++){
      List_Read (Simplexes_Destroyed, i, &s);
      if (!Tree_Suppress (m->Simplexes, &s))
        Msg(GERROR, "Impossible to delete simplex");
      // CORRECTION FROM Free(s) to that
      Free_Simplex (&s,0);
    }
    
    /* Creation des liens entre nouveaux simplexes */
    
    Tree_Action (Sim_Sur_Le_Bord, TAtoLA);
    Link_Simplexes (Simplexes_New, m->Simplexes);
  }

  Tree_Delete (Sim_Sur_Le_Bord);
  Tree_Delete (Tsd);
  return true;
}

double rand_sign(){
  double d = ((double)rand()/(double)RAND_MAX) ;
  return (d < 0.5)?-1.0:1.0;
}

void Convex_Hull_Mesh (List_T * Points, Mesh * m){
  int i, j, N, n;
  int Nbr_OK = 0, Nbr_NOTOK = 0;

  N = List_Nbr (Points);
  n = IMAX (N / 20, 1);

  Msg(STATUS2, "Mesh 3D... (initial)");

  Box_6_Tetraedron (Points, m);
  // List_Sort (Points, comparePosition);

  for (i = 0; i < N; i++){
    THES = NULL;
    List_Read (Points, i, &THEV);

    if (Simplexes_New)
      for (j = 0; j < List_Nbr (Simplexes_New); j++){
        Action_First_Simplexes (List_Pointer (Simplexes_New, j), NULL);
      }
    
    if (!THES){
      Tree_Action (m->Simplexes, Action_First_Simplexes);
      Nbr_OK++;
    }
    else{
      Nbr_NOTOK++;
    }
    if (i % n == n - 1){
      volume = 0.0;
      Tree_Action (m->Simplexes, VSIM);
      Msg(STATUS3, "Nod=%d/%d Elm=%d", i+1,N,Tree_Nbr(m->Simplexes)); 
      Msg(STATUS1, "Vol=%g",volume); 
    }
    if (!THES){
      Msg(WARNING, "Vertex (%g,%g,%g) in no simplex",
          THEV->Pos.X,THEV->Pos.Y,THEV->Pos.Z); 
      THEV->Pos.X += 10 * CTX.mesh.rand_factor * LC3D * (double)rand()/(double)RAND_MAX;
      THEV->Pos.Y += 10 * CTX.mesh.rand_factor * LC3D * (double)rand()/(double)RAND_MAX;
      THEV->Pos.Z += 10 * CTX.mesh.rand_factor * LC3D * (double)rand()/(double)RAND_MAX;
      Tree_Action (m->Simplexes, Action_First_Simplexes);
    }
    bool  ca_marche = Bowyer_Watson (m, THEV, THES, 1);
    int count = 0;
    while(!ca_marche){
      //Msg(INFO, "Unable to add point %d (%g,%g,%g)",
      //	  THEV->Num, THEV->Pos.X,THEV->Pos.Y,THEV->Pos.Z );
      count ++;
      double dx = rand_sign() * 1000 * CTX.mesh.rand_factor * LC3D *
	(double)rand()/(double)RAND_MAX;
      double dy = rand_sign() * 1000 * CTX.mesh.rand_factor * LC3D *
	(double)rand()/(double)RAND_MAX;
      double dz = rand_sign() * 1000 * CTX.mesh.rand_factor * LC3D *
	(double)rand()/(double)RAND_MAX;
      THEV->Pos.X += dx;
      THEV->Pos.Y += dy;
      THEV->Pos.Z += dz;
      THES = NULL;
      Tree_Action (m->Simplexes, Action_First_Simplexes);
      ca_marche = Bowyer_Watson (m, THEV, THES, 1);
      THEV->Pos.X -= dx;
      THEV->Pos.Y -= dy;
      THEV->Pos.Z -= dz;          
      if(count > 5){
        N++;
        List_Add(POINTS,&THEV);
        Msg(WARNING, "Unable to add point %d (will do it later)",
            THEV->Num);
        break;
      }
    }
  }
}

void suppress_vertex (void *data, void *dum){
  Vertex **pv;

  pv = (Vertex **) data;
  if ((*pv)->Num < 0)
    List_Add (Suppress, pv);
}

void suppress_simplex (void *data, void *dum){
  Simplex **pv;

  pv = (Simplex **) data;
  if ((*pv)->iEnt == 0)
    List_Add (Suppress, pv);

  /*
  else{
    for(i=0;i<List_Nbr(TrsfVolNum);i++)
      if((*pv)->iEnt == (*(int*)List_Pointer(TrsfVolNum,i))->Num)
        List_Add(Suppress,pv);
  }
  */
}

void add_in_bgm (void *a, void *b){
  Simplex **s, *S;

  s = (Simplex **) a;
  S = *s;
  List_Add (LLL, S);
}

void Bgm_With_Points (Mesh * bgm){
  int i;
  Simplex *s;

  bgm->BGM.bgm = List_Create (Tree_Nbr (bgm->Simplexes), 10, sizeof (Simplex));
  LLL = bgm->BGM.bgm;
  Tree_Action (bgm->Simplexes, add_in_bgm);
  for (i = 0; i < List_Nbr (LLL); i++){
    s = (Simplex *) List_Pointer (LLL, i);
    AddSimplexInGrid (bgm, s, BOITE);
  }
}

void Create_BgMesh (int Type, double lc, Mesh * m){
  m->BGM.Typ = Type;
  switch (Type){
  case CONSTANT:
    m->BGM.lc = lc;
    break;
  case ONFILE:
    break;
  case WITHPOINTS:
    m->BGM.bgm = NULL;
    break;
  }
}

void Maillage_Volume (void *data, void *dum){
  Volume *v, **pv;
  Mesh M;
  Surface S, *s;
  Simplex *simp;
  Vertex *newv;
  int n, N;
  double uvw[3];
  int i;

  // WE SHOULD ALLOCATE THESE GUYS HERE AND NOT IN Bowyer_Watson 
  // MEMORY BUG -JF

  Simplexes_New = List_Create (10, 10, sizeof (Simplex *));
  Simplexes_Destroyed = List_Create (10, 10, sizeof (Simplex *));

  FACE_DIMENSION = 2;

  pv = (Volume **) data;
  v = *pv;

  if(v->Dirty){
    Msg(INFO, "Not meshing dirty Volume %d", v->Num);
    return;
  }

  if (Extrude_Mesh (v)){
  }

  if (v->Method == TRANSFINI){
    MeshTransfiniteVolume (v);
  }
  else if (v->Typ == 99999){
    Msg(STATUS3, "Nod=0 Elm=0"); 

    LOCAL = &M;
    Create_BgMesh (THEM->BGM.Typ, .2, LOCAL);
    s = &S;
    
    POINTS_TREE = Tree_Create (sizeof (Vertex *), comparePosition);
    POINTS = List_Create (100, 100, sizeof (Vertex *));
    LOCAL->Simplexes = v->Simplexes;
    LOCAL->Vertices = v->Vertices;
    
    for (i = 0; i < List_Nbr (v->Surfaces); i++){
      List_Read (v->Surfaces, i, &s);
      Tree_Action (s->Vertices, add_points);
    }
    Tree_Action (POINTS_TREE, add_points_2);
    Tree_Delete (POINTS_TREE);
    
    N = List_Nbr (POINTS);
    n = N / 30 + 1;
    
    /* Creation d'un maillage initial respectant la frontiere */
    
    if(!List_Nbr(POINTS))return;
    
    Convex_Hull_Mesh (POINTS, LOCAL);
    
    while (!Coherence (v, LOCAL));

    Link_Simplexes (NULL, LOCAL->Simplexes);
    
    /* Suppression des noeuds de num < 0 */
    
    Suppress = List_Create (10, 10, sizeof (Vertex *));
    Tree_Action (v->Vertices, suppress_vertex);
    for (i = 0; i < List_Nbr (Suppress); i++){
      Tree_Suppress (v->Vertices, List_Pointer (Suppress, i));
    }
    List_Delete (Suppress);

    /* Suppression des elements dont le num de vol == 0 (cad qui
       n'appartiennent a auncun volume defini) */

    Suppress = List_Create (10, 10, sizeof (Simplex *));
    Tree_Action (v->Simplexes, suppress_simplex);
    for (i = 0; i < List_Nbr (Suppress); i++){
      Tree_Suppress (v->Simplexes, List_Pointer (Suppress, i));
    }
    
    List_Delete (Suppress);
    
    if (Tree_Nbr (LOCAL->Simplexes) == 0)
      return;

    /* Si il reste quelque chose a mailler en volume : */
    
    v->Simplexes = LOCAL->Simplexes;
    
    Bgm_With_Points (LOCAL);
    POINTS_TREE = THEM->Simplexes;
    
    Msg(STATUS2, "Mesh 3D... (final)");

    Tree_Right (LOCAL->Simplexes, &simp);
    i = 0;
    Progress (102);
    while (simp->Quality > CONV_VALUE){
      newv = NewVertex (simp);
      //double l;
      //while(!Pt_In_Volume(newv->Pos.X,newv->Pos.Y,newv->Pos.Z,LOCAL,&l,0.0)){
      
      while (!simp->Pt_In_Simplexe (newv, uvw, 1.e-5) &&                 
             (simp->S[0] == &MyNewBoundary ||
              !simp->S[0]->Pt_In_Simplexe (newv, uvw, 1.e-5)) &&
             (simp->S[1] == &MyNewBoundary ||
              !simp->S[1]->Pt_In_Simplexe (newv, uvw, 1.e-5)) &&
             (simp->S[2] == &MyNewBoundary ||
              !simp->S[2]->Pt_In_Simplexe (newv, uvw, 1.e-5)) &&
             (simp->S[3] == &MyNewBoundary ||
              !simp->S[3]->Pt_In_Simplexe (newv, uvw, 1.e-5))) {
        Tree_Suppress (LOCAL->Simplexes, &simp);
        simp->Quality = 0.1;
        Tree_Insert (LOCAL->Simplexes, &simp);
        Tree_Right (LOCAL->Simplexes, &simp);
        if (simp->Quality < CONV_VALUE)
          break;
        newv = NewVertex (simp);
      }
      if (simp->Quality < CONV_VALUE)
        break;
      i++;
      if (i % n == n - 1){
        volume = 0.0;
        Tree_Action (LOCAL->Simplexes, VSIM);
        Msg(STATUS3, "Nod=%d Elm=%d",
            Tree_Nbr (LOCAL->Vertices), Tree_Nbr (LOCAL->Simplexes));
        Msg(STATUS1, "Vol(%g) Conv(%g->%g)", volume, simp->Quality, CONV_VALUE);
        double adv = 100. * (CONV_VALUE / simp->Quality);
        Progress ((int) adv);
      }
      Bowyer_Watson (LOCAL, newv, simp, 0);
      Tree_Right (LOCAL->Simplexes, &simp);
    }
    
    POINTS_TREE = THEM->Vertices;
    Tree_Action (v->Vertices, add_points);
    POINTS_TREE = THEM->Simplexes;
    Tree_Action (v->Simplexes, add_points);
    
    Progress(-1);

    if (CTX.mesh.quality){
      extern void SwapEdges3D (Mesh * M, Volume * v, double GammaPrescribed, bool order);
      Msg(STATUS3, "Swapping edges (1st pass)");
      SwapEdges3D (THEM, v, CTX.mesh.quality, true);
      Msg(STATUS3, "Swapping edges (2nd pass)");
      SwapEdges3D (THEM, v, CTX.mesh.quality, false);
      Msg(STATUS3, "Swapping edges (last pass)");
      SwapEdges3D (THEM, v, CTX.mesh.quality, true);
    }

    if (CTX.mesh.nb_smoothing){
      /*
      Msg(STATUS3, "Laplacian smoothing");
      tnxe = Tree_Create (sizeof (NXE), compareNXE);
      create_NXE (v->Vertices, v->Simplexes, tnxe);
      for (int i = 0; i < CTX.mesh.nb_smoothing; i++)
        Tree_Action (tnxe, ActionLiss);
      delete_NXE (tnxe);
      Msg(STATUS3, "Swapping edges (last pass)");
      SwapEdges3D (THEM, v, 0.5, true);
      */
    }

    if (CTX.mesh.degree == 2)
      Degre2 (THEM->Vertices, THEM->VertexEdges, v->Simplexes, NULL, NULL);
  }

  THEM->Statistics[6] += Tree_Nbr(v->Vertices);
  THEM->Statistics[9] += Tree_Nbr(v->Simplexes);
  THEM->Statistics[10] += Tree_Nbr(v->Hexahedra);
  THEM->Statistics[11] += Tree_Nbr(v->Prisms);

  if(v->Typ == 99999){
    Gamma_Maillage (THEM, &THEM->Statistics[17], &THEM->Statistics[18], &THEM->Statistics[19]);
    Eta_Maillage (THEM, &THEM->Statistics[20], &THEM->Statistics[21], &THEM->Statistics[22]);
    R_Maillage (THEM, &THEM->Statistics[23], &THEM->Statistics[24], &THEM->Statistics[25]);
  }
  // WE SHOULD DESALLOCATE THESE GUYS HERE AND NOT NOWHERE ;-)
  // MEMORY BUG -JF
  List_Delete(Simplexes_New);
  List_Delete(Simplexes_Destroyed);
}
