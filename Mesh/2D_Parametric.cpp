/* $Id: 2D_Parametric.cpp,v 1.2 2000-11-23 14:11:34 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "CAD.h"
#include "Interpolation.h"
#include "Mesh.h"
#include "2D_Mesh.h"
#include "Create.h"
#include "Context.h"
#include "Numeric.h"

extern Mesh      *THEM;
extern Context_T  CTX;

static Surface *SURF;
Surface *PARAMETRIC;

/* SURFACES CYLINDRIQUES */

void XYZtoUV (void *a, void *dum){
  Vertex *v;
  double uu, vv;
  v = *(Vertex **) a;
  ProjectPointOnSurface (SURF->Support, v, &uu, &vv);
  v->Pos.X = uu;
  v->Pos.Y = vv;
  v->Pos.Z = 0.0;
}

void UVtoXYZ (void *a, void *dum){
  Vertex *v, n;
  v = *(Vertex **) a;

  n = InterpolateSurface (SURF->Support, v->Pos.X, v->Pos.Y, 0, 0);

  v->Pos.X = n.Pos.X;
  v->Pos.Y = n.Pos.Y;
  v->Pos.Z = n.Pos.Z;
}

void printMetric (Mesh * m, Surface * s, char *name){

  int N = 10, M = 10, i, j;
  double u, v;
  FILE *f = fopen (name, "w");
  if (!f)
    return;
  fprintf (f, "View \"metric\" Offset{0,0,0} {\n");
  for (i = 0; i < N; i++){
    u = (s->ku[0]) + (s->ku[s->Nu + s->OrderU] - s->ku[0]) 
      * (double) i / (double) (N - 1);
    for (j = 0; j < M; j++){
      v = (s->kv[0]) + (s->kv[s->Nv + s->OrderV] - s->kv[0]) 
	* (double) j / (double) (M - 1);
      m->Metric->setMetric (u, v, s);
      fprintf (f, "VT (%f,%f,0,%f,%f,0,%f,%f,0)"
	       "{%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
	       u, v, u, v, u, v, 
	       m->Metric->m[0][0], m->Metric->m[0][1], 0.0,
	       m->Metric->m[0][0], m->Metric->m[0][1], 0.0, 
	       m->Metric->m[0][0], m->Metric->m[0][1], 0.0);
	  fprintf (f, "VT (%f,%f,0,%f,%f,0,%f,%f,0)"
		   "{%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
		   u, v, u, v, u, v, 
		   m->Metric->m[1][0], m->Metric->m[1][1], 0.0,
		   m->Metric->m[1][0], m->Metric->m[1][1], 0.0,
		   m->Metric->m[1][0], m->Metric->m[1][1], 0.0);
    }
  }
  fprintf (f, "};\n");
  fclose (f);
}

int MeshParametricSurface (Surface * s){

  int i, j, ori;
  Curve *pC;
  Vertex *v;
  Tree_T *tnxe;

  PARAMETRIC = s;

  if (s->Typ == MSH_SURF_NURBS)
    return 1;
  if (s->Typ != MSH_SURF_TRIMMED || s->Support->Typ != MSH_SURF_NURBS)
    return 0;

  SURF = s;
  if (!List_Nbr (s->s.Generatrices))
    return 1;
  for (i = 0; i < List_Nbr (s->s.Generatrices); i++){
    List_Read (s->s.Generatrices, i, &pC);
    for (j = 0; j < List_Nbr (pC->Vertices); j++){
      List_Read (pC->Vertices, j, &v);
      Tree_Insert (s->Vertices, List_Pointer (pC->Vertices, j));
    }
  }

  //printMetric(THEM,s,"metric.pos");

  Tree_Action (s->Vertices, Freeze_Vertex);

  Tree_Action (s->Vertices, XYZtoUV);
  ori = Calcule_Contours (s);

  if (!AlgorithmeMaillage2DAnisotropeModeJF (s))
    Maillage_Automatique_VieuxCode (s, THEM, ori);

  if (CTX.mesh.nb_smoothing){
    tnxe = Tree_Create (sizeof (NXE), compareNXE);
    create_NXE (s->Vertices, s->Simplexes, tnxe);
    
    for(i = 0 ; i < CTX.mesh.nb_smoothing ; i++)
      Tree_Action (tnxe, ActionLiss);
    
    //AmelioreSurface_EliminationTripet (s, THEM, tnxe);
    
    Tree_Delete (tnxe);
  }

  Tree_Action (s->Vertices, UVtoXYZ);
  Tree_Action (s->Vertices, deFreeze_Vertex);

  PARAMETRIC = NULL;

  return 1;
}
