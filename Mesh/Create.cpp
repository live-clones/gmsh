/* $Id: Create.cpp,v 1.5 2000-11-23 23:20:35 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Numeric.h"

extern Mesh *THEM;
extern int CurrentSimplexNumber, FLAG_OLD_CIRCLE;

//static double CIRC_GRAN = 2.2;

int compareNXE (const void *a, const void *b){
  NXE *q, *w;

  q = (NXE *) a;
  w = (NXE *) b;
  return (compareVertex (&q->v, &w->v));
}

int compareFxE (const void *a, const void *b){
  FxE *q, *w;

  q = (FxE *) a;
  w = (FxE *) b;
  return (compareFace (&q->Sorted, &w->Sorted));
}

int compareHexahedron (const void *a, const void *b){
  Hexahedron **q, **w;

  q = (Hexahedron **) a;
  w = (Hexahedron **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareSurfaceLoop (const void *a, const void *b){
  SurfaceLoop **q, **w;

  q = (SurfaceLoop **) a;
  w = (SurfaceLoop **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareEdgeLoop (const void *a, const void *b){
  EdgeLoop **q, **w;

  q = (EdgeLoop **) a;
  w = (EdgeLoop **) b;
  return ((*q)->Num - (*w)->Num);
}

int comparePrism (const void *a, const void *b){
  Prism **q, **w;

  q = (Prism **) a;
  w = (Prism **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareQuality (const void *a, const void *b){
  double d;
  Simplex **q, **w;

  q = (Simplex **) a;
  w = (Simplex **) b;
  d = (*q)->Quality - (*w)->Quality;

  if (d > 0)
    return (1);
  if (d < 0)
    return (-1);
  return ((*q)->Num - (*w)->Num);
}

int compareCurve (const void *a, const void *b){
  Curve **q, **w;

  q = (Curve **) a;
  w = (Curve **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareAttractor (const void *a, const void *b){
  Attractor **q, **w;

  q = (Attractor **) a;
  w = (Attractor **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareSurface (const void *a, const void *b){
  Surface **q, **w;

  q = (Surface **) a;
  w = (Surface **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareVolume (const void *a, const void *b){
  Volume **q, **w;

  q = (Volume **) a;
  w = (Volume **) b;
  return ((*q)->Num - (*w)->Num);
}

int compareSxF (const void *a, const void *b){
  SxF *q, *w;

  q = (SxF *) a;
  w = (SxF *) b;
  return compareFace (&q->F, &w->F);
}

Attractor * Create_Attractor (int Num, double lc1, double lc2, double Radius,
			      Vertex * v, Curve * c, Surface * s){
  Attractor *pA;

  pA = (Attractor *) Malloc (sizeof (Attractor));
  pA->v = v;
  pA->c = c;
  pA->s = s;
  pA->lc1 = lc1;
  pA->lc2 = lc2;
  pA->Radius = Radius;
  return pA;
}

void Add_SurfaceLoop (int Num, List_T * intlist, Mesh * M){
  SurfaceLoop *pSL;
  int i, j;
  pSL = (SurfaceLoop *) Malloc (sizeof (SurfaceLoop));
  pSL->Surfaces = List_Create (List_Nbr (intlist), 1, sizeof (int));
  pSL->Num = Num;
  for (i = 0; i < List_Nbr (intlist); i++){
    List_Read (intlist, i, &j);
    List_Add (pSL->Surfaces, &j);
  }
  Tree_Add (M->SurfaceLoops, &pSL);
}

void Add_PhysicalGroup (int Num, int typ, List_T * intlist, Mesh * M){
  PhysicalGroup *pSL;
  int i, j;
  pSL = (PhysicalGroup *) Malloc (sizeof (PhysicalGroup));
  pSL->Entities = List_Create (List_Nbr (intlist), 1, sizeof (int));
  pSL->Num = Num;
  pSL->Typ = typ;
  for (i = 0; i < List_Nbr (intlist); i++){
    List_Read (intlist, i, &j);
    List_Add (pSL->Entities, &j);
  }
  List_Add (M->PhysicalGroups, &pSL);
}

void Add_EdgeLoop (int Num, List_T * intlist, Mesh * M){
  EdgeLoop *pEL;
  int i, j;
  pEL = (EdgeLoop *) Malloc (sizeof (EdgeLoop));
  pEL->Curves = List_Create (List_Nbr (intlist), 1, sizeof (int));
  pEL->Num = Num;
  for (i = 0; i < List_Nbr (intlist); i++){
    List_Read (intlist, i, &j);
    List_Add (pEL->Curves, &j);
  }
  Tree_Add (M->EdgeLoops, &pEL);
}

void End_Curve (Curve * c){
  double det, R2, mat[3][3], R, A3, A1, A4;
  Vertex *v[5], v1, v3, v4;
  double dd[3], qq[3], AX, f1, f2, DP, dir32[3], dir12[3], n[3], m[3], dir42[3];
  double rhs[2], sys[2][2], sol[2];
  int i;
  Curve *Curve;

  if (c->Typ == MSH_SEGM_CIRC ||
      c->Typ == MSH_SEGM_CIRC_INV ||
      c->Typ == MSH_SEGM_ELLI ||
      c->Typ == MSH_SEGM_ELLI_INV){

    Curve = c;

    if (List_Nbr (Curve->Control_Points) == 4)
      List_Read (Curve->Control_Points, 2, &v[4]);
    else
      v[4] = NULL;
    
    if (Curve->Typ == MSH_SEGM_CIRC_INV ||
	Curve->Typ == MSH_SEGM_ELLI_INV){
      List_Read (Curve->Control_Points, 0, &v[3]);
      List_Read (Curve->Control_Points, 1, &v[2]);
      if (!v[4])
	List_Read (Curve->Control_Points, 2, &v[1]);
      else
	List_Read (Curve->Control_Points, 3, &v[1]);
    }
    else{
      List_Read (Curve->Control_Points, 0, &v[1]);
      List_Read (Curve->Control_Points, 1, &v[2]);
      if (!v[4])
	List_Read (Curve->Control_Points, 2, &v[3]);
      else
	List_Read (Curve->Control_Points, 3, &v[3]);
    }
    
    direction (v[2], v[3], dir32);
    direction (v[2], v[1], dir12);
    if (v[4])
      direction (v[2], v[4], dir42);

    /*
      norme(dir32);
      norme(dir12);
      norme(dir42);
    */

    //prodve(dir12,dir32,n);
    dd[0] = dir12[0];
    dd[1] = dir12[1];
    dd[2] = dir12[2];
    qq[0] = dir32[0];
    qq[1] = dir32[1];
    qq[2] = dir32[2];
    norme (dd);
    norme (qq);
    prodve (dd, qq, n);
    if (fabs (n[0]) < 1.e-5 && fabs (n[1]) < 1.e-5 && fabs (n[2]) < 1.e-5){
      n[0] = Curve->Circle.n[0];
      n[1] = Curve->Circle.n[1];
      n[2] = Curve->Circle.n[2];
    }

    /* BOF BOF BOF */
    prodve (n, dir12, m);

    v1.Pos.X = dir12[0];
    v1.Pos.Y = dir12[1];
    v1.Pos.Z = dir12[2];
    v3.Pos.X = dir32[0];
    v3.Pos.Y = dir32[1];
    v3.Pos.Z = dir32[2];
    if (v[4]){
      v4.Pos.X = dir42[0];
      v4.Pos.Y = dir42[1];
      v4.Pos.Z = dir42[2];
    }
    norme (dir12);
    norme (n);
    norme (m);
    
    mat[2][0] = Curve->Circle.invmat[0][2] = n[0];
    mat[2][1] = Curve->Circle.invmat[1][2] = n[1];
    mat[2][2] = Curve->Circle.invmat[2][2] = n[2];
    mat[1][0] = Curve->Circle.invmat[0][1] = m[0];
    mat[1][1] = Curve->Circle.invmat[1][1] = m[1];
    mat[1][2] = Curve->Circle.invmat[2][1] = m[2];
    mat[0][0] = Curve->Circle.invmat[0][0] = dir12[0];
    mat[0][1] = Curve->Circle.invmat[1][0] = dir12[1];
    mat[0][2] = Curve->Circle.invmat[2][0] = dir12[2];
    
    if(FLAG_OLD_CIRCLE){
      if(n[0] == 0.0 && n[1] == 0.0){
	mat[2][0] = Curve->Circle.invmat[0][2] = 0;
	mat[2][1] = Curve->Circle.invmat[1][2] = 0;
	mat[2][2] = Curve->Circle.invmat[2][2] = 1;
	mat[1][0] = Curve->Circle.invmat[0][1] = 0;
	mat[1][1] = Curve->Circle.invmat[1][1] = 1;
	mat[1][2] = Curve->Circle.invmat[2][1] = 0;
	mat[0][0] = Curve->Circle.invmat[0][0] = 1;
	mat[0][1] = Curve->Circle.invmat[1][0] = 0;
	mat[0][2] = Curve->Circle.invmat[2][0] = 0;
      }
    }

    Projette (&v1, mat);
    Projette (&v3, mat);
    if (v[4])
      Projette (&v4, mat);

    R = sqrt (v1.Pos.X * v1.Pos.X + v1.Pos.Y * v1.Pos.Y);
    R2 = sqrt (v3.Pos.X * v3.Pos.X + v3.Pos.Y * v3.Pos.Y);
    A3 = myatan2 (v3.Pos.Y, v3.Pos.X);
    if (v[4])
      A4 = myatan2 (v4.Pos.Y, v4.Pos.X);
    else
      A4 = 0.0;
    A1 = myatan2 (v1.Pos.Y, v1.Pos.X);
    
    DP = 2 * Pi;
    
    A3 = angle_02pi (A3);
    A1 = angle_02pi (A1);
    if (v[4])
      A4 = angle_02pi (A4);
    if (A1 >= A3)
      A3 += DP;
    if (A4 > A1)
      A4 -= DP;
    
    if (v[4]){
      AX = (A1 - A4);
      sys[0][0] = cos (AX) * cos (A4);
      sys[0][1] = -sin (AX) * sin (A4);
      sys[1][0] = cos (AX) * sin (A4);
      sys[1][1] = sin (AX) * cos (A4);
      rhs[0] = v1.Pos.X;
      rhs[1] = v1.Pos.Y;
      det = sys[0][0] * sys[1][1] - sys[1][0] * sys[0][1];
      if (det < 1.e-12){
	AX = (A3 - A4);
	sys[0][0] = cos (AX) * cos (A4);
	sys[0][1] = -sin (AX) * sin (A4);
	sys[1][0] = cos (AX) * sin (A4);
	sys[1][1] = sin (AX) * cos (A4);
	rhs[0] = v3.Pos.X;
	rhs[1] = v3.Pos.Y;
	det = sys[0][0] * sys[1][1] - sys[1][0] * sys[0][1];
      }
      if (det < 1.e-12){
	f1 = DMAX (R, R2);
	f2 = DMIN (R, R2);
      }
      else{
	sys2x2 (sys, rhs, sol);
	f1 = sol[0];
	f2 = sol[1];
      }
    }
    else{
      f1 = f2 = R;
    }

    Curve->Circle.t1 = A1;
    Curve->Circle.t2 = A3;
    Curve->Circle.f1 = f1;
    Curve->Circle.f2 = f2;
    Curve->Circle.incl = A4;
    
    for (i = 0; i < 4; i++)
      Curve->Circle.v[i] = v[i];

    /*
    if (!c->Circle.done){
      float proj[4][4];
      for (i = 0; i < 4; i++){
	for (int j = 0; j < 4; j++){
	  if (i != 3 && j != 3)
	    proj[i][j] = Curve->Circle.f1 * Curve->Circle.invmat[i][j];
	  else
	    proj[i][j] = 0.0;
	}
      }
      proj[0][3] = Curve->Circle.v[2]->Pos.X;
      proj[1][3] = Curve->Circle.v[2]->Pos.Y;
      proj[2][3] = Curve->Circle.v[2]->Pos.Z;
      proj[3][3] = 1.0;
      c->Circle.done = 1;
    }
    */
    // Un cercle a au moins 16 pts par pi radiants
    
    // c->beg->lc = DMIN (R*Pi/(fabs(c->Circle.t1-c->Circle.t2)*CIRC_GRAN),c->beg->lc);
    // c->end->lc = DMIN (R*Pi/(fabs(c->Circle.t1-c->Circle.t2)*CIRC_GRAN),c->end->lc);
    
  }
  c->cp = (float *) malloc (4 * List_Nbr (c->Control_Points) * sizeof (float));
  for (i = 0; i < List_Nbr (c->Control_Points); i++){
    List_Read (c->Control_Points, i, &v[0]);
    c->cp[4 * i] = v[0]->Pos.X;
    c->cp[4 * i + 1] = v[0]->Pos.Y;
    c->cp[4 * i + 2] = v[0]->Pos.Z;
    c->cp[4 * i + 3] = v[0]->w;
  }

}

void End_Surface (Surface * s){
  int i;
  Vertex *v;

  if (!s->Control_Points || !List_Nbr(s->Control_Points))
    return;

  s->cp = (float *) Malloc (4 * List_Nbr (s->Control_Points) * sizeof (float));
  for (i = 0; i < List_Nbr (s->Control_Points); i++){
    List_Read (s->Control_Points, i, &v);
    s->cp[4 * i] = v->Pos.X;
    s->cp[4 * i + 1] = v->Pos.Y;
    s->cp[4 * i + 2] = v->Pos.Z;
    s->cp[4 * i + 3] = v->w;
  }

}



Curve *Create_Curve (int Num, int Typ, int Order, List_T * Liste,
		     List_T * Knots, int p1, int p2, double u1, double u2){
  Curve *pC;
  Vertex *v;
  int i, j, iPnt;
  double d;
  double matcr[4][4] = { {-0.5, 1.5, -1.5, 0.5},
			 {1.0, -2.5, 2.0, -0.5},
			 {-0.5, 0.0, 0.5, 0.0},
			 {0.0, 1.0, 0.0, 0.0} };
  double matbs[4][4] = { {-1.0, 3, -3, 1},
			 {3, -6, 3.0, 0},
			 {-3, 0.0, 3, 0.0},
			 {1, 4, 1, 0.0} };
  double matbez[4][4] = { {-1.0, 3, -3, 1},
			  {3, -6, 3.0, 0},
			  {-3, 3.0, 0, 0.0},
			  {1, 0, 0, 0.0} };

  pC = (Curve *) Malloc (sizeof (Curve));
  pC->Vertices = NULL;
  pC->Typ = Typ;
  pC->Num = Num;
  pC->Simplexes = Tree_Create (sizeof (Simplex *), compareSimplex);
  pC->TrsfSimplexes = List_Create (1, 10, sizeof (Simplex *));
  pC->ConnectedSurfaces = NULL;
  pC->Circle.done = 0;
  pC->Method = LIBRE;
  pC->degre = Order;
  pC->Circle.n[0] = 1.0;
  pC->Circle.n[1] = 0.0;
  pC->Circle.n[2] = 0.0;
  if (Typ == MSH_SEGM_SPLN){
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	pC->mat[i][j] = matcr[i][j];
    
  }
  else if (Typ == MSH_SEGM_BSPLN){
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	pC->mat[i][j] = matbs[i][j] / 6.0;
  }
  else if (Typ == MSH_SEGM_BEZIER){
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	pC->mat[i][j] = matbez[i][j];
  }

  pC->ubeg = u1;
  pC->uend = u2;

  if (Knots){
    pC->k = (float *) malloc (List_Nbr (Knots) * sizeof (float));
    double kmin = .0, kmax = 1.;
    List_Read (Knots, 0, &kmin);
    List_Read (Knots, List_Nbr (Knots) - 1, &kmax);
    pC->ubeg = kmin;
    pC->uend = kmax;
    for (i = 0; i < List_Nbr (Knots); i++){
      List_Read (Knots, i, &d);
      pC->k[i] = (float) d;
    }
  }
  else
    pC->k = NULL;

  if (Liste){
    pC->Control_Points = List_Create (List_Nbr (Liste), 1, sizeof (Vertex *));
    for (j = 0; j < List_Nbr (Liste); j++){
      List_Read (Liste, j, &iPnt);
      if ((v = FindVertex (iPnt, THEM)))
	List_Add (pC->Control_Points, &v);
      else
	Msg(FATAL, "Unknown Control Point %d in Curve %d", iPnt, pC->Num);
    }
  }
  else {
    //End_Curve(pC);
    return pC;
  }

  if (p1 < 0){
    List_Read (pC->Control_Points, 0, &pC->beg);
    List_Read (pC->Control_Points, List_Nbr (pC->Control_Points) - 1, &pC->end);
  }
  else {
    if ((v = FindVertex (p1, THEM))){
      pC->beg = v;
      Msg(INFOS, "Curve %d First Control Point %d ", pC->Num, v->Num);
    }
    else{
      List_Read (pC->Control_Points, 0, &pC->beg);
      Msg(FATAL, "Unknown Control Point %d in Curve %d", p1, pC->Num);
    }
    if ((v = FindVertex (p2, THEM))){
      pC->end = v;
      Msg(INFOS, "Curve %d First Control Point %d ", pC->Num, v->Num);
    }
    else{
      List_Read (pC->Control_Points, List_Nbr (pC->Control_Points) - 1, &pC->end);
      Msg(FATAL, "Unknown Control Point %d in Curve %d", p2, pC->Num);
    }
  }
  End_Curve (pC);
  pC->Extrude = NULL;
  return (pC);
}

Surface * Create_Surface (int Num, int Typ, int Mat){
  Surface *pS;

  pS = (Surface *) Malloc (sizeof (Surface));
  pS->Num = Num;
  pS->Typ = Typ;
  pS->Mat = Mat;
  pS->Method = LIBRE;
  pS->Recombine = 0;
  pS->RecombineAngle = 30;
  pS->Simplexes = Tree_Create (sizeof (Simplex *), compareQuality);
  pS->TrsfSimplexes = List_Create (1, 10, sizeof (Simplex *));
  pS->Vertices = Tree_Create (sizeof (Vertex *), compareVertex);
  pS->TrsfVertices = List_Create (1, 10, sizeof (Vertex *));
  pS->Contours = List_Create (1, 1, sizeof (List_T *));
  pS->Orientations = NULL;
  pS->Support = pS;
  pS->Control_Points = List_Create (1, 10, sizeof (Vertex *));
  pS->Extrude = NULL;
  pS->STL = NULL;
  return (pS);
}

Volume * Create_Volume (int Num, int Typ, int Mat){
  Volume *pV;

  pV = (Volume *) Malloc (sizeof (Volume));
  pV->Num = Num;
  pV->Typ = Typ;
  pV->Mat = Mat;
  pV->Method = LIBRE;
  pV->Surfaces = List_Create (1, 2, sizeof (Surface *));
  pV->Simplexes = Tree_Create (sizeof (Simplex *), compareQuality);
  pV->Vertices = Tree_Create (sizeof (Vertex *), compareVertex);
  pV->Hexahedra = Tree_Create (sizeof (Hexahedron *), compareHexahedron);
  pV->Prisms = Tree_Create (sizeof (Prism *), comparePrism);
  pV->Extrude = NULL;
  return pV;
}


Hexahedron * Create_Hexahedron (Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4,
				Vertex * v5, Vertex * v6, Vertex * v7, Vertex * v8){
  Hexahedron *h;

  h = (Hexahedron *) Malloc (sizeof (Hexahedron));
  h->iEnt = -1;
  h->Num = ++CurrentSimplexNumber;
  h->V[0] = v1;
  h->V[1] = v2;
  h->V[2] = v3;
  h->V[3] = v4;
  h->V[4] = v5;
  h->V[5] = v6;
  h->V[6] = v7;
  h->V[7] = v8;
  h->VSUP = NULL;

  return (h);
}

Prism * Create_Prism (Vertex * v1, Vertex * v2, Vertex * v3,
		      Vertex * v4, Vertex * v5, Vertex * v6){
  Prism *p;

  p = (Prism *) Malloc (sizeof (Prism));
  p->iEnt = -1;
  p->Num = ++CurrentSimplexNumber;
  p->V[0] = v1;
  p->V[1] = v2;
  p->V[2] = v3;
  p->V[3] = v4;
  p->V[4] = v5;
  p->V[5] = v6;
  p->VSUP = NULL;

  return (p);
}
