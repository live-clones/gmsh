/* $Id: Generator.cpp,v 1.6 2000-11-25 15:26:11 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"
#include "Create.h"
#include "Context.h"
#include "Main.h"

extern Mesh     *THEM;
extern Context_T CTX;
extern int TYPBGMESH;
extern int CurrentNodeNumber, CurrentSimplexNumber;

static List_T *Curves;

void GetStatistics (double s[50]){
  int i;
  THEM->Statistics[0] = Tree_Nbr (THEM->Points);
  THEM->Statistics[1] = Tree_Nbr (THEM->Curves);
  THEM->Statistics[2] = Tree_Nbr (THEM->Surfaces);
  THEM->Statistics[3] = Tree_Nbr (THEM->Volumes);
  for (i = 0; i < 50; i++) s[i] = THEM->Statistics[i];
}

void ApplyLcFactor_Point(void *a, void *b){
  Vertex *v = *(Vertex**)a;
  if(v->lc <= 0.0)
    Msg(FATAL, "Wrong characteristic Length (%g <= 0) for Point %d",
	v->lc, v->Num);
  v->lc *= CTX.mesh.lc_factor;
}
void ApplyLcFactor_Attractor(void *a, void *b){
  Attractor *v = *(Attractor**)a;
  v->lc1 *= CTX.mesh.lc_factor;
  v->lc2 *= CTX.mesh.lc_factor;
}
void ApplyLcFactor(Mesh *M){
  Tree_Action(M->Points, ApplyLcFactor_Point);
  List_Action(M->Metric->Attractors, ApplyLcFactor_Attractor);
}

void Maillage_Dimension_0 (Mesh * M){
  for (int i = 0; i < 20; i++) M->Statistics[i] = 0.0;
  Create_BgMesh (TYPBGMESH, .2, M);
}

void Maillage_Dimension_1 (Mesh * M){
  double t1, t2;
  t1 = Cpu();
  Tree_Action (M->Curves, Maillage_Curve);
  t2 = Cpu();
  M->Statistics[12] = t2 - t1;
}

void Maillage_Dimension_2 (Mesh * M){
  int i;
  Curve *c, *neew, C;
  double t1, t2;

  t1 = Cpu();

  /* maillage 1-D inverses */

  Curves = Tree2List (M->Curves);
  for (i = 0; i < List_Nbr (Curves); i++){
    List_Read (Curves, i, &c);
    if (c->Num > 0){
      neew = &C;
      neew->Num = -c->Num;
      Tree_Query (M->Curves, &neew);
      neew->Vertices = List_Create (List_Nbr (c->Vertices), 1, sizeof (Vertex *));
      List_Invert (c->Vertices, neew->Vertices);
    }
  }
  List_Delete (Curves);

  Tree_Action (M->Surfaces, Maillage_Surface);

  t2 = Cpu();

  M->Statistics[13] = t2 - t1;
}

void Maillage_Dimension_3 (Mesh * M){
  Volume *v;
  double t1, t2;
  Volume *vol;

  t1 = Cpu();

  v = Create_Volume (99999, 99999, 99999);

  List_T *list = Tree2List (M->Volumes);
  for (int i = 0; i < List_Nbr (list); i++){
    List_Read (list, i, &vol);
    if ((!vol->Extrude || !vol->Extrude->mesh.ExtrudeMesh) &&
	(vol->Method != TRANSFINI)){
      for (int j = 0; j < List_Nbr (vol->Surfaces); j++){
	List_Replace (v->Surfaces, List_Pointer (vol->Surfaces, j), compareSurface);
      }
    }
  }
  List_Delete (list);
  Tree_Insert (M->Volumes, &v);
  Tree_Action (M->Volumes, Maillage_Volume);

  t2 = Cpu();

  M->Statistics[14] = t2 - t1;
}

void Init_Mesh (Mesh * M, int all){
  THEM = M;

  if (M->Vertices){
    Tree_Action (M->Vertices, Free_Vertex);
    Tree_Delete (M->Vertices);
  }
  if (M->VertexEdges){
    Tree_Action (M->VertexEdges, Free_Vertex);
    Tree_Delete (M->VertexEdges);
  }
  if (M->Simplexes){
    Tree_Action (M->Simplexes, Free_Simplex);
    Tree_Delete (M->Simplexes);
  }
  if (M->Points){
    //Tree_Action (M->Points, Free_Vertex);
    Tree_Delete (M->Points);
  }
  if (M->Curves){
    //Tree_Action (M->Vertices, Free_Curve);
    Tree_Delete (M->Curves);
  }
  if (M->SurfaceLoops){
    //Tree_Action (M->Vertices, Free_SurfaceLoop);
    Tree_Delete (M->SurfaceLoops);
  }
  if (M->EdgeLoops){
    //Tree_Action (M->Vertices, Free_EdgeLoop);
    Tree_Delete (M->EdgeLoops);
  }
  if (M->Surfaces){
    //Tree_Action (M->Vertices, Free_Surface);
    Tree_Delete (M->Surfaces);
  }
  if (M->Volumes){
    //Tree_Action (M->Vertices, Free_Volume);
    Tree_Delete (M->Volumes);
  }
  if (M->PhysicalGroups){
    //Tree_Action (M->Vertices, Free_PhysicalGroup);
    List_Delete (M->PhysicalGroups);
  }
  if (M->Metric){
    Free (M->Metric);
  }

  M->Vertices = Tree_Create (sizeof (Vertex *), compareVertex);
  M->VertexEdges = Tree_Create (sizeof (Vertex *), compareVertex);
  M->Simplexes = Tree_Create (sizeof (Simplex *), compareSimplex);
  M->Points = Tree_Create (sizeof (Vertex *), compareVertex);
  M->Curves = Tree_Create (sizeof (Curve *), compareCurve);
  M->SurfaceLoops = Tree_Create (sizeof (SurfaceLoop *), compareSurfaceLoop);
  M->EdgeLoops = Tree_Create (sizeof (EdgeLoop *), compareEdgeLoop);
  M->Surfaces = Tree_Create (sizeof (Surface *), compareSurface);
  M->Volumes = Tree_Create (sizeof (Volume *), compareVolume);
  M->PhysicalGroups = List_Create (5, 5, sizeof (PhysicalGroup *));
  M->Metric = new GMSHMetric;
  M->BGM.bgm = NULL;

  CurrentNodeNumber = 1;
  CurrentSimplexNumber = 0;
  M->status = 0;
}

void mai3d (Mesh * M, int Asked){
  double t1, t2;
  int oldstatus;

  M->MeshParams.DelaunayAlgorithm = CTX.mesh.algo ;
  M->MeshParams.NbSmoothing = CTX.mesh.nb_smoothing ;
  M->MeshParams.InteractiveDelaunay = CTX.mesh.interactive ;

  oldstatus = M->status;

  /* initialisations - Maillage 0-D */

  if ((Asked > oldstatus && Asked >= 0 && oldstatus < 0) ||
      (Asked < oldstatus)){
    printf("ON PASSE ICI\n");
    OpenProblem (TheFileName);
    M->status = 0;
  }
  
  /* Maillage 1-D */
  
  if ((Asked > oldstatus && Asked > 0 && oldstatus < 1) ||
      (Asked < oldstatus && Asked > 0)){
    Msg (INFO, "Mesh 1D...");
    t1 = Cpu();
    Maillage_Dimension_1 (M);
    t2 = Cpu();
    Msg (INFO, "Mesh 1D complete (%g s)", t2 - t1);
    M->status = 1;
  }
  
  /* Maillage 2-D */
  
  if ((Asked > oldstatus && Asked > 1 && oldstatus < 2) ||
      (Asked < oldstatus && Asked > 1)){
    Msg (INFO, "Mesh 2D...");
    t1 = Cpu();
    Maillage_Dimension_2 (M);
    t2 = Cpu();
    Msg (INFO, "Mesh 2D complete (%g s)", t2 - t1);
    M->status = 2;
  }

  /* Maillage 3-D */

  if ((Asked > oldstatus && Asked > 2 && oldstatus < 3) ||
      (Asked < oldstatus && Asked > 2)){
    Msg (INFO, "Mesh 3D...");
    t1 = Cpu();
    Maillage_Dimension_3 (M);
    t2 = Cpu();
    Msg (INFO, "Mesh 3D complete (%g s)", t2 - t1);
    M->status = 3;
  }

}
