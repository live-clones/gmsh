/* $Id: 3D_BGMesh.cpp,v 1.4 2000-11-23 16:07:12 geuzaine Exp $ */

#include "Gmsh.h"
#include "Mesh.h"
#include "2D_Mesh.h"
#include "3D_Mesh.h"
#include "Adapt.h"
#include "Views.h"
#include "Numeric.h"

extern double FACTEUR_MULTIPLICATIF;

static Mesh m;
static Vertex vvv;
static double XX, YY, ZZ, D, LL;

void ExportLcFieldOnVolume (Mesh * M){
  List_T *l = Tree2List (M->Volumes);
  Volume *vol;
  Simplex *simp;
  FILE *f = fopen ("OutFile.pos", "w");
  fprintf (f, "View \"LC_FIELD\" Offset{0,0,0} {\n");
  for (int i = 0; i < List_Nbr (l); i++){
    List_Read (l, i, &vol);
    List_T *ll = Tree2List (vol->Simplexes);
    for (int j = 0; j < List_Nbr (ll); j++){
      List_Read (ll, j, &simp);
      simp->ExportLcField (f);
    }
    List_Delete (ll);
  }
  List_Delete (l);
  fprintf (f, "};\n");
  fclose (f);
}

void ExportLcFieldOnSurfaces (Mesh * M){
  List_T *l = Tree2List (M->Surfaces);
  Surface *surf;
  Simplex *simp;
  FILE *f = fopen ("OutFileS.pos", "w");
  fprintf (f, "View \"LC_FIELD\" Offset{0,0,0} {\n");
  for (int i = 0; i < List_Nbr (l); i++){
    List_Read (l, i, &surf);
    List_T *ll = Tree2List (surf->Simplexes);
    for (int j = 0; j < List_Nbr (ll); j++){
      List_Read (ll, j, &simp);
      simp->ExportLcField (f);
    }
    List_Delete (ll);
  }
  List_Delete (l);
  fprintf (f, "};\n");
  fclose (f);
}

void findcloser (void *a, void *b){
  Vertex *v;
  double dd;
  v = *(Vertex **) a;
  dd = DSQR (v->Pos.X - XX) + DSQR (v->Pos.Y - YY) + DSQR (v->Pos.Z - ZZ);
  if (dd < D){
    D = dd;
    LL = v->lc;
  }
}

void LCBGM (double X, double Y, double Z, double *l){
  if (Pt_In_Volume (X, Y, Z, &m, l, .01));
  else if (Pt_In_Volume (X, Y, Z, &m, l, .02));
  else if (Pt_In_Volume (X, Y, Z, &m, l, .07));
  else if (Pt_In_Volume (X, Y, Z, &m, l, .1));
  else if (Pt_In_Volume (X, Y, Z, &m, l, .2));
  else if (Pt_In_Volume (X, Y, Z, &m, l, .8));
  else if (Pt_In_Volume (X, Y, Z, &m, l, 20.));
  else {
    XX = X;
    YY = Y;
    ZZ = Z;
    D = 1.e24;
    LL = 1;
    Tree_Action (m.Vertices, findcloser);
    *l = LL;
  }
}

double Lc_XYZ (double X, double Y, double Z, Mesh * m){
  double l;

  //l = 0.1 * fabs(cos(2 * 3.14159 * X) * cos( 2 * 3.14159 * Y))  + 0.01;
  //return l;

  switch (m->BGM.Typ){
  case FUNCTION:
    break;
  case CONSTANT:
    l = m->BGM.lc;
    break;
  case ONFILE:
    LCBGM (X, Y, Z, &l);
    break;
  case WITHPOINTS:
    if (Pt_In_Volume (X, Y, Z, m, &l, 0.0));
    else if (Pt_In_Volume (X, Y, Z, m, &l, 0.2));
    else if (Pt_In_Volume (X, Y, Z, m, &l, 0.5));
    else{
      Msg(WARNING, "Exterior Point");
      l = 1.e-25;
    }
    break;
  }
  return (FACTEUR_MULTIPLICATIF * l);
}

/* ------------------------------------------------------------------------ */
/*  B G M W i t h V i e w                                                   */
/* ------------------------------------------------------------------------ */

static Tree_T *Pts;

static void AIG (void *a, void *b){
  Simplex *s = *(Simplex **) a;
  AddSimplexInGrid (&m, s, BOITE);
}

int BGMWithView (Post_View * ErrView){

  static Vertex *VertexUp, *v, V, *ver[4];
  extern int TYPBGMESH;
  extern Mesh *THEM;
  int i, j, k;
  Post_Simplex s;
  Post_Triangle t;
  Simplex *si;

  VertexUp = Create_Vertex (-1, 0., 0., 1., 1., -1.0);
  Pts = Tree_Create (sizeof (Vertex *), comparePosition);

  m.BGM.Typ = TYPBGMESH = ONFILE;

  m.Vertices = Tree_Create (sizeof (Vertex *), compareVertex);
  m.Simplexes = Tree_Create (sizeof (Simplex *), compareSimplex);
  Create_BgMesh (TYPBGMESH, .2, THEM);

  k = 1;
  for (i = 0; i < List_Nbr (ErrView->Triangles); i++){
    List_Read (ErrView->Triangles, i, &t);
    for (j = 0; j < 3; j++){
      v = &V;
      v->Pos.X = t.X[j];
      v->Pos.Y = t.Y[j];
      v->Pos.Z = t.Z[j];
      if (0 /*Tree_Query(Pts,&v) */ ){
	/* Corriger la Lc pour lissage */
	ver[j] = v;
      }
      else{
	v = Create_Vertex (k++, t.X[j], t.Y[j], t.Z[j]
			   ,t.V[j], -1.0);
	ver[j] = v;
	Tree_Add (m.Vertices, &v);
	Tree_Add (Pts, &v);
      }
    }
    si = Create_Simplex (ver[0], ver[1], ver[2], VertexUp);
    Tree_Add (m.Simplexes, &si);
  }
  
  for (i = 0; i < List_Nbr (ErrView->Simplices); i++){
    List_Read (ErrView->Simplices, i, &s);
    for (j = 0; j < 4; j++){
      v = &V;
      v->Pos.X = s.X[j];
      v->Pos.Y = s.Y[j];
      v->Pos.Z = s.Z[j];
      if (Tree_Query (Pts, &v)){
	ver[j] = v;
      }
      else{
	v = Create_Vertex (k++, s.X[k], s.Y[j], s.Z[j], s.V[0], -1.0);
	ver[j] = v;
	Tree_Add (m.Vertices, &v);
	Tree_Add (Pts, &v);
      }
    }
    si = Create_Simplex (ver[0], ver[1], ver[2], ver[4]);
    Tree_Add (m.Simplexes, &si);
  }
  
  m.Grid.init = 0;
  m.Grid.Nx = 10;
  m.Grid.Ny = 10;
  m.Grid.Nz = 10;
  Tree_Action (m.Vertices, findminmax);
  getminmax (&m.Grid.min.X, &m.Grid.min.Y, &m.Grid.min.Z,
	     &m.Grid.max.X, &m.Grid.max.Y, &m.Grid.max.Z);

  if (m.Grid.max.Z == m.Grid.min.Z){
    m.Grid.Nz = 1;
    Tree_Add (m.Vertices, &VertexUp);
    Tree_Action (m.Vertices, findminmax);
    getminmax (&m.Grid.min.X, &m.Grid.min.Y, &m.Grid.min.Z,
	       &m.Grid.max.X, &m.Grid.max.Y, &m.Grid.max.Z);
  }

  Tree_Action (m.Simplexes, AIG);

  Msg(INFO, "Background Mesh Loaded (%d Nodes, %d Elements)",
	  Tree_Nbr(m.Vertices), Tree_Nbr(m.Simplexes)); 

  return (1);
}


double ErrorInView (Post_View * ErrView, int *n){

  Post_Triangle t;
  Post_Simplex s;
  double e, tot=0.0;
  int i, j=0;

  if(ErrView == NULL){
    Msg(WARNING, "Empty Error View");
    return 0.;
  }

  for (i = 0; i < List_Nbr (ErrView->Triangles); i++){
    List_Read (ErrView->Triangles, i, &t);
    e = (t.V[0] + t.V[1] + t.V[2]) / 3. ;
    tot += e * e;
    j++;
  }

  for (i = 0; i < List_Nbr (ErrView->Simplices); i++){
    List_Read (ErrView->Simplices, i, &s);
    e = (t.V[0] + t.V[1] + t.V[2] + t.V[3]) * 0.25;
    tot += e * e;
    j++;
  }

  *n = j;
  return 100 * sqrt (tot);
}


/* ------------------------------------------------------------------------ */
/*  C r e a t e B G M                                                       */
/* ------------------------------------------------------------------------ */

int CreateBGM (Post_View * ErrView, int OptiMethod, double Degree,
	       double OptiValue, double *ObjFunct, char *OutFile){

  Post_Triangle t;
  Post_Simplex s;
  double *h, *p, *e, xc, yc, zc, c[3];
  int N, i, j, dim;
  Simplex smp;
  FILE *f;

  if (List_Nbr (ErrView->Simplices))
    dim = 3;
  else
    dim = 2;

  N = List_Nbr (ErrView->Simplices) +
    List_Nbr (ErrView->Triangles) + 2;

  h = (double *) malloc (N * sizeof (double));
  e = (double *) malloc (N * sizeof (double));
  p = (double *) malloc (N * sizeof (double));

  j = 0;

  for (i = 0; i < List_Nbr (ErrView->Triangles); i++){
    List_Read (ErrView->Triangles, i, &t);

    /*
      Attention, cette ligne est seulement valable en
      2d x-y. Si plus, calculer le centre du cercle en
      3d ou utiliser une autre mesure de taille.
    */
    CircumCircle (t.X[0], t.Y[0],
		  t.X[1], t.Y[1],
		  t.X[2], t.Y[2],
		  &xc, &yc);
    h[j + 1] = sqrt ((xc - t.X[0]) * (xc - t.X[0]) +
		     (yc - t.Y[0]) * (yc - t.Y[0]));
    p[j + 1] = Degree;
    e[j + 1] = (t.V[0] + t.V[1] + t.V[2]) / 3. ;
    j++;
  }

  for (i = 0; i < List_Nbr (ErrView->Simplices); i++){
    List_Read (ErrView->Simplices, i, &s);
    
    smp.center_tet (t.X, t.Y, t.Z, c);
    
    xc = c[0];
    yc = c[1];
    zc = c[2];
    
    h[j + 1] = sqrt ((xc - t.X[0]) * (xc - t.X[0]) +
		     (yc - t.X[0]) * (yc - t.X[0]) +
		     (zc - t.Y[0]) * (zc - t.Y[0]));
    p[j + 1] = Degree;
    e[j + 1] = (t.V[0] + t.V[1] + t.V[2] + t.V[3]) * 0.25;
    j++;
  }

  *ObjFunct = optimesh (j, OptiMethod, dim, e, h, p, OptiValue, OptiValue);

  f = fopen (OutFile, "w");

  fprintf (f, "View \"Auto_BGMesh\" Offset{0,0,0} {\n");
  j = 0;
  for (i = 0; i < List_Nbr (ErrView->Triangles); i++){
    List_Read (ErrView->Triangles, i, &t);
    fprintf (f, "ST(%f,%f,%f,%f,%f,%f,%f,%f,%f){%12.5E,%12.5E,%12.5E};\n",
	     t.X[0], t.Y[0], t.Z[0],
	     t.X[1], t.Y[1], t.Z[1],
	     t.X[2], t.Y[2], t.Z[2],
	     h[j], h[j], h[j]);
    j++;
  }
  for (i = 0; i < List_Nbr (ErrView->Simplices); i++){
    List_Read (ErrView->Simplices, i, &s);
    fprintf (f, "SS(%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f){%12.5E,%12.5E,%12.5E,%12.5E};\n",
	     s.X[0], s.Y[0], s.Z[0],
	     s.X[1], s.Y[1], s.Z[1],
	     s.X[2], s.Y[2], s.Z[2],
	     s.X[3], s.Y[3], s.Z[3],
	     h[j], h[j], h[j], h[j]);
    j++;
  }
  fprintf (f, "};\n");
  fclose (f);

  Msg(INFO,"Wrote background mesh in '%s'", OutFile); 

  return 1;
}

