// $Id: 3D_BGMesh.cpp,v 1.14 2001-01-09 19:40:56 remacle Exp $

#include "Gmsh.h"
#include "Mesh.h"
#include "2D_Mesh.h"
#include "3D_Mesh.h"
#include "Adapt.h"
#include "Views.h"
#include "Numeric.h"

extern Mesh *THEM;

static Mesh m;
static double XX, YY, ZZ, D, LL;

void ExportLcFieldOnVolume (Mesh * M){
  List_T *l = Tree2List (M->Volumes);
  Volume *vol;
  Simplex *simp;
  FILE *f = fopen ("OutFile.pos", "w");

  if(!f){
    Msg(GERROR, "Unable to Open File");
    return;
  }

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

  if(!f){
    Msg(GERROR, "Unable to Open File");
    return;
  }

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
      Msg(GERROR, "Exterior Point (%g,%g,%g)", X, Y, Z);
      l = 1.e-25;
    }
    break;
  }
  return l;
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
  int i, j, k, nb;
  double *X, *Y, *Z, *Val;
  Simplex *si;

  VertexUp = Create_Vertex (-1, 0., 0., 1., 1., -1.0);
  Pts = Tree_Create (sizeof (Vertex *), comparePosition);

  m.BGM.Typ = ONFILE;

  m.Vertices = Tree_Create (sizeof (Vertex *), compareVertex);
  m.Simplexes = Tree_Create (sizeof (Simplex *), compareSimplex);
  Create_BgMesh (ONFILE, .2, THEM);


  k = 1;
  if(ErrView->NbST){
    nb = List_Nbr(ErrView->ST) / ErrView->NbST ;
    for(i = 0 ; i < List_Nbr(ErrView->ST) ; i+=nb){
      X = (double*)List_Pointer_Fast(ErrView->ST,i);
      Y = (double*)List_Pointer_Fast(ErrView->ST,i+3);
      Z = (double*)List_Pointer_Fast(ErrView->ST,i+6);
      Val = (double*)List_Pointer_Fast(ErrView->ST,i+9);

      for (j = 0; j < 3; j++){
	v = &V;
	v->Pos.X = X[j];
	v->Pos.Y = Y[j];
	v->Pos.Z = Z[j];
	if (Tree_Query (Pts, &v)){
	  ver[j] = v;
	}
	else{
	  v = Create_Vertex (k++, X[j], Y[j], Z[j], Val[j], -1.0);
	  ver[j] = v;
	  Tree_Add (m.Vertices, &v);
	  Tree_Add (Pts, &v);
	}
      }
      si = Create_Simplex (ver[0], ver[1], ver[2], VertexUp);
      Tree_Add (m.Simplexes, &si);
    }
  }

  if(ErrView->NbSS){
    nb = List_Nbr(ErrView->SS) / ErrView->NbSS ;
    for(i = 0 ; i < List_Nbr(ErrView->SS) ; i+=nb){
      X = (double*)List_Pointer_Fast(ErrView->SS,i);
      Y = (double*)List_Pointer_Fast(ErrView->SS,i+4);
      Z = (double*)List_Pointer_Fast(ErrView->SS,i+8);
      Val = (double*)List_Pointer_Fast(ErrView->SS,i+12);

      for (j = 0; j < 4; j++){
	v = &V;
	v->Pos.X = X[j];
	v->Pos.Y = Y[j];
	v->Pos.Z = Z[j];
	if (Tree_Query (Pts, &v)){
	  ver[j] = v;
	}
	else{
	  v = Create_Vertex (k++, X[j], Y[j], Z[j], Val[j], -1.0);
	  ver[j] = v;
	  Tree_Add (m.Vertices, &v);
	  Tree_Add (Pts, &v);
	}
      }
      si = Create_Simplex (ver[0], ver[1], ver[2], ver[3]);
      Tree_Add (m.Simplexes, &si);
    }
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

  Msg(INFOS, "Background Mesh Loaded (%d Nodes, %d Elements)",
      Tree_Nbr(m.Vertices), Tree_Nbr(m.Simplexes)); 

  return (1);
}


double ErrorInView (Post_View * ErrView, int *n){
  double e, tot=0.0, *Val;
  int i, j=0, nb;

  if(ErrView == NULL){
    Msg(WARNING, "Empty Error View");
    return 0.;
  }

  if(ErrView->NbST){
    nb = List_Nbr(ErrView->ST) / ErrView->NbST ;
    for(i = 0 ; i < List_Nbr(ErrView->ST) ; i+=nb){
      Val = (double*)List_Pointer_Fast(ErrView->ST,i+9);
      e = (Val[0] + Val[1] + Val[2]) / 3. ;
      tot += e * e;
      j++;
    }
  }

  if(ErrView->NbSS){
    nb = List_Nbr(ErrView->SS) / ErrView->NbSS ;
    for(i = 0 ; i < List_Nbr(ErrView->SS) ; i+=nb){
      Val = (double*)List_Pointer_Fast(ErrView->SS,i+12);
      e = (Val[0] + Val[1] + Val[2] + Val[3]) * 0.25 ;
      tot += e * e;
      j++;
    }
  }

  *n = j;

  return 100 * sqrt (tot);
}


/* ------------------------------------------------------------------------ */
/*  C r e a t e B G M                                                       */
/* ------------------------------------------------------------------------ */

int CreateBGM (Post_View * ErrView, int OptiMethod, double Degree,
               double OptiValue, double *ObjFunct, char *OutFile){
  double *h, *p, *e, xc, yc, zc, c[3], *X, *Y, *Z, *Val;
  int N, i, j, dim, nb;
  Simplex smp;
  FILE *f;

  if (ErrView->NbSS)
    dim = 3;
  else
    dim = 2;

  N = ErrView->NbSS + ErrView->NbST + 2;

  h = (double *) malloc (N * sizeof (double));
  e = (double *) malloc (N * sizeof (double));
  p = (double *) malloc (N * sizeof (double));

  j = 0;

  if(ErrView->NbST){
    nb = List_Nbr(ErrView->ST) / ErrView->NbST ;
    for(i = 0 ; i < List_Nbr(ErrView->ST) ; i+=nb){
      X = (double*)List_Pointer_Fast(ErrView->ST,i);
      Y = (double*)List_Pointer_Fast(ErrView->ST,i+3);
      Z = (double*)List_Pointer_Fast(ErrView->ST,i+6);
      Val = (double*)List_Pointer_Fast(ErrView->ST,i+9);
      /*
	Attention, cette ligne est seulement valable en
	2d x-y. Si plus, calculer le centre du cercle en
	3d ou utiliser une autre mesure de taille.
      */
      CircumCircle (X[0], Y[0],
		    X[1], Y[1],
		    X[2], Y[2],
		    &xc, &yc);
      h[j + 1] = sqrt ((xc - X[0]) * (xc - X[0]) +
		       (yc - Y[0]) * (yc - Y[0]));
      p[j + 1] = Degree;
      e[j + 1] = (Val[0] + Val[1] + Val[2]) / 3. ;
      j++;
    }
  }

  if(ErrView->NbSS){
    nb = List_Nbr(ErrView->SS) / ErrView->NbSS ;
    for(i = 0 ; i < List_Nbr(ErrView->SS) ; i+=nb){
      X = (double*)List_Pointer_Fast(ErrView->SS,i);
      Y = (double*)List_Pointer_Fast(ErrView->SS,i+3);
      Z = (double*)List_Pointer_Fast(ErrView->SS,i+8);
      Val = (double*)List_Pointer_Fast(ErrView->SS,i+12);
    
      smp.center_tet (X, Y, Z, c);
      xc = c[0];
      yc = c[1];
      zc = c[2];
    
      h[j + 1] = sqrt ((xc - X[0]) * (xc - X[0]) +
		       (yc - X[0]) * (yc - X[0]) +
		       (zc - Y[0]) * (zc - Y[0]));
      p[j + 1] = Degree;
      e[j + 1] = (Val[0] + Val[1] + Val[2] + Val[3]) * 0.25;
      j++;
    }
  }

  *ObjFunct = AdaptMesh (j, OptiMethod, dim, e, h, p, OptiValue);

  f = fopen (OutFile, "w");

  if(!f){
    Msg(GERROR, "Unable to Open File '%s'", OutFile);
    return 0;
  }

  fprintf (f, "View \"Auto_BGMesh\" Offset{0,0,0} {\n");

  j = 0;

  if(ErrView->NbST){
    nb = List_Nbr(ErrView->ST) / ErrView->NbST ;
    for(i = 0 ; i < List_Nbr(ErrView->ST) ; i+=nb){
      X = (double*)List_Pointer_Fast(ErrView->ST,i);
      Y = (double*)List_Pointer_Fast(ErrView->ST,i+3);
      Z = (double*)List_Pointer_Fast(ErrView->ST,i+6);
      Val = (double*)List_Pointer_Fast(ErrView->ST,i+9);
      fprintf (f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	       X[0], Y[0], Z[0],
	       X[1], Y[1], Z[1],
	       X[2], Y[2], Z[2],
	       h[j], h[j], h[j]);
      j++;
    }
  }

  if(ErrView->NbSS){
    nb = List_Nbr(ErrView->SS) / ErrView->NbSS ;
    for(i = 0 ; i < List_Nbr(ErrView->SS) ; i+=nb){
      X = (double*)List_Pointer_Fast(ErrView->SS,i);
      Y = (double*)List_Pointer_Fast(ErrView->SS,i+3);
      Z = (double*)List_Pointer_Fast(ErrView->SS,i+8);
      Val = (double*)List_Pointer_Fast(ErrView->SS,i+12);
      fprintf (f, "SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
	       X[0], Y[0], Z[0],
	       X[1], Y[1], Z[1],
	       X[2], Y[2], Z[2],
	       X[3], Y[3], Z[3],
	       h[j], h[j], h[j], h[j]);
      j++;
    }
  }
  fprintf (f, "};\n");
  fclose (f);

  Msg(INFOS, "Background Mesh Wriiten in '%s'", OutFile); 

  return 1;

}

