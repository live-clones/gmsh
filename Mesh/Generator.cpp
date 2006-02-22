// $Id: Generator.cpp,v 1.78 2006-02-22 19:39:50 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "BDS.h"
#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Create.h"
#include "Context.h"
#include "OpenFile.h"
#include "Views.h"
#include "PartitionMesh.h"

extern Mesh *THEM;
extern Context_T CTX;

static int nbOrder2 = 0;

void countOrder2(void *a, void *b)
{
  Vertex *v = *(Vertex**)a;
  if(v->Degree == 2) nbOrder2++;
}

void GetStatistics(double stat[50])
{
  for(int i = 0; i < 50; i++)
    stat[i] = 0.;

  if(!THEM)
    return;

  stat[0] = Tree_Nbr(THEM->Points);
  stat[1] = Tree_Nbr(THEM->Curves);
  stat[2] = Tree_Nbr(THEM->Surfaces);
  stat[3] = Tree_Nbr(THEM->Volumes);
  stat[45] = List_Nbr(THEM->PhysicalGroups);
  
  stat[4] = 0.;
  if(Tree_Nbr(THEM->Curves)) {
    List_T *curves = Tree2List(THEM->Curves);
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      stat[4] += List_Nbr(c->Vertices);
    }
    List_Delete(curves);
  }

  stat[5] = stat[7] = stat[8] = 0.;
  if(Tree_Nbr(THEM->Surfaces)) {
    List_T *surfaces = Tree2List(THEM->Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++){
      Surface *s;
      List_Read(surfaces, i, &s);
      stat[5] += Tree_Nbr(s->Vertices);
      stat[7] += Tree_Nbr(s->Simplexes) + Tree_Nbr(s->SimplexesBase);
      stat[8] += Tree_Nbr(s->Quadrangles);
    }
    List_Delete(surfaces);
  }

  stat[6] = stat[9] = stat[10] = stat[11] = stat[12] = 0.;
  if(Tree_Nbr(THEM->Volumes)) {
    List_T *volumes = Tree2List(THEM->Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      stat[6] += Tree_Nbr(v->Vertices);
      stat[9] += Tree_Nbr(v->Simplexes) + Tree_Nbr(v->SimplexesBase);
      stat[10] += Tree_Nbr(v->Hexahedra);
      stat[11] += Tree_Nbr(v->Prisms);
      stat[12] += Tree_Nbr(v->Pyramids);
    }
    List_Delete(volumes);
  }

  // hack... (Read_Mesh does not fill-in the vertices)
  int nbnod = Tree_Nbr(THEM->Vertices);
  if(nbnod && !stat[4] && !stat[5] && !stat[6]){
    if(stat[9] || stat[10] || stat[11] || stat[12])
      stat[6] = nbnod;
    else if(stat[7] || stat[8])
      stat[5] = nbnod;
    else
      stat[4] = nbnod;
  }

  stat[13] = THEM->timing[0];
  stat[14] = THEM->timing[1];
  stat[15] = THEM->timing[2];

  nbOrder2 = 0;
  Tree_Action(THEM->Vertices, countOrder2);
  stat[16] = nbOrder2;

  stat[17] = THEM->quality_gamma[0];
  stat[18] = THEM->quality_gamma[1];
  stat[19] = THEM->quality_gamma[2];
  stat[20] = THEM->quality_eta[0];
  stat[21] = THEM->quality_eta[1];
  stat[22] = THEM->quality_eta[2];
  stat[23] = THEM->quality_rho[0];
  stat[24] = THEM->quality_rho[1];
  stat[25] = THEM->quality_rho[2];

  stat[26] = List_Nbr(CTX.post.list);
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    stat[27] += v->NbSP + v->NbVP + v->NbTP;
    stat[28] += v->NbSL + v->NbVL + v->NbTL;
    stat[29] += v->NbST + v->NbVT + v->NbTT;
    stat[30] += v->NbSQ + v->NbVQ + v->NbTQ;
    stat[31] += v->NbSS + v->NbVS + v->NbTS;
    stat[32] += v->NbSH + v->NbVH + v->NbTH;
    stat[33] += v->NbSI + v->NbVI + v->NbTI;
    stat[34] += v->NbSY + v->NbVY + v->NbTY;
    stat[35] += v->NbT2 + v->NbT3;
    if(v->Visible) {
      if(v->DrawPoints)
        stat[36] += 
	  (v->DrawScalars ? v->NbSP : 0) + (v->DrawVectors ? v->NbVP : 0) + 
	  (v->DrawTensors ? v->NbTP : 0);
      if(v->DrawLines)
        stat[37] += 
	  (v->DrawScalars ? v->NbSL : 0) + (v->DrawVectors ? v->NbVL : 0) + 
	  (v->DrawTensors ? v->NbTL : 0);
      if(v->DrawTriangles)
        stat[38] += 
	  (v->DrawScalars ? v->NbST : 0) + (v->DrawVectors ? v->NbVT : 0) + 
	  (v->DrawTensors ? v->NbTT : 0);
      if(v->DrawQuadrangles)
        stat[39] +=
	  (v->DrawScalars ? v->NbSQ : 0) + (v->DrawVectors ? v->NbVQ : 0) + 
	  (v->DrawTensors ? v->NbTQ : 0);
      if(v->DrawTetrahedra)
        stat[40] += 
	  (v->DrawScalars ? v->NbSS : 0) + (v->DrawVectors ? v->NbVS : 0) + 
	  (v->DrawTensors ? v->NbTS : 0);
      if(v->DrawHexahedra)
        stat[41] +=
	  (v->DrawScalars ? v->NbSH : 0) + (v->DrawVectors ? v->NbVH : 0) +
	  (v->DrawTensors ? v->NbTH : 0);
      if(v->DrawPrisms)
        stat[42] += 
	  (v->DrawScalars ? v->NbSI : 0) + (v->DrawVectors ? v->NbVI : 0) +
	  (v->DrawTensors ? v->NbTI : 0);
      if(v->DrawPyramids)
        stat[43] += 
	  (v->DrawScalars ? v->NbSY : 0) + (v->DrawVectors ? v->NbVY : 0) + 
	  (v->DrawTensors ? v->NbTY : 0);
      if(v->DrawStrings)
        stat[44] += v->NbT2 + v->NbT3;
    }
  }

}

static double SumOfAllLc = 0.;
void GetSumOfAllLc(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  SumOfAllLc += v->lc;
}

void ApplyLcFactor_Point(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  if(v->lc <= 0.0) {
    Msg(GERROR, 
	"Wrong characteristic length (%g <= 0) for Point %d, defaulting to 1.0",
        v->lc, v->Num);
    v->lc = 1.0;
  }
  v->lc *= CTX.mesh.lc_factor;
}

void ApplyLcFactor_Attractor(void *a, void *b)
{
  Attractor *v = *(Attractor **) a;
  v->lc1 *= CTX.mesh.lc_factor;
  v->lc2 *= CTX.mesh.lc_factor;
}

void ApplyLcFactor(Mesh * M)
{
  Tree_Action(M->Points, ApplyLcFactor_Point);
  List_Action(M->Metric->Attractors, ApplyLcFactor_Attractor);
}

void Move_SimplexBaseToSimplex(Mesh * M, int dimension)
{
  if(dimension >= 1){
    List_T *Curves = Tree2List(M->Curves);
    for(int i = 0; i < List_Nbr(Curves); i++) {
      Curve *c;
      List_Read(Curves, i, &c);
      Move_SimplexBaseToSimplex(&c->SimplexesBase, c->Simplexes);
    }
    List_Delete(Curves);
  }

  if(dimension >= 2){
    List_T *Surfaces = Tree2List(M->Surfaces);
    for(int i = 0; i < List_Nbr(Surfaces); i++){
      Surface *s;
      List_Read(Surfaces, i, &s);
      Move_SimplexBaseToSimplex(&s->SimplexesBase, s->Simplexes);
    }
    List_Delete(Surfaces);
  }
  
  if(dimension >= 3){
    List_T *Volumes = Tree2List(M->Volumes);
    for(int i = 0; i < List_Nbr(Volumes); i++){
      Volume *v;
      List_Read(Volumes, i, &v);
      Move_SimplexBaseToSimplex(&v->SimplexesBase, v->Simplexes);
    }
    List_Delete(Volumes);
  }
}

bool TooManyElements(Mesh *M, int dim){
  if(CTX.expert_mode) return false;

  // try to detect obvious mistakes in characteristic lenghts (one of
  // the most common cause for erroneous bug reports on the mailing
  // list)
  SumOfAllLc = 0.;
  Tree_Action(M->Points, GetSumOfAllLc);
  SumOfAllLc /= (double)Tree_Nbr(M->Points);
  if(pow(CTX.lc / SumOfAllLc, dim) < 1.e7) return false;

  return !GetBinaryAnswer("Your choice of characteristic lengths will likely produce\n"
			  "a very large mesh. Do you really want to continue?\n\n"
			  "(To disable this warning in the future, select `Enable\n"
			  "expert mode' in the option dialog.)",
			  "Continue", "Cancel");
}

void Maillage_Dimension_1(Mesh * M)
{
  if(TooManyElements(M, 1)) return;

  double t1 = Cpu();

  Tree_Action(M->Curves, Maillage_Curve);

  double t2 = Cpu();
  M->timing[0] = t2 - t1;
}

void Maillage_Dimension_2(Mesh * M)
{
  if(TooManyElements(M, 2)) return;

  double shortest = 1.e300;

  double t1 = Cpu();

  // create reverse 1D meshes

  List_T *Curves = Tree2List(M->Curves);
  for(int i = 0; i < List_Nbr(Curves); i++) {
    Curve *c;
    List_Read(Curves, i, &c);
    if(c->Num > 0) {
      if(c->l < shortest)
        shortest = c->l;
      Curve C;
      Curve *neew = &C;
      neew->Num = -c->Num;
      Tree_Query(M->Curves, &neew);
      neew->Vertices =
        List_Create(List_Nbr(c->Vertices), 1, sizeof(Vertex *));
      List_Invert(c->Vertices, neew->Vertices);
    }
  }
  List_Delete(Curves);

  Msg(DEBUG, "Shortest curve has length %g", shortest);

  // mesh 2D

  Tree_Action(M->Surfaces, Maillage_Surface);

  // global "all-quad" recombine

  if(CTX.mesh.algo_recombine == 2)
    Recombine_All(M);

  double t2 = Cpu();

  M->timing[1] = t2 - t1;
}

static Volume *IVOL;

void TransferData(void *a, void *b)
{
  Simplex *s = *(Simplex**)a;
  if(s->iEnt == IVOL->Num){
    Tree_Add(IVOL->Simplexes, &s);
    for(int i = 0; i < 4; i++)
      Tree_Insert(IVOL->Vertices, &s->V[i]);
  }
}

void Maillage_Dimension_3(Mesh * M)
{
  if(TooManyElements(M, 3)) return;

  double t1 = Cpu();

  // merge all the delaunay parts in a single special volume
  Volume *v = Create_Volume(99999, 99999);
  List_T *list = Tree2List(M->Volumes);
  for(int i = 0; i < List_Nbr(list); i++) {
    Volume *vol;
    List_Read(list, i, &vol);
    if((!vol->Extrude || !vol->Extrude->mesh.ExtrudeMesh) &&
       (vol->Method != TRANSFINI)) {
      for(int j = 0; j < List_Nbr(vol->Surfaces); j++) {
        List_Replace(v->Surfaces, List_Pointer(vol->Surfaces, j),
                     compareSurface);
      }
    }
  }
  Tree_Insert(M->Volumes, &v);

  if(CTX.mesh.oldxtrude) {
    Extrude_Mesh_Old(M); // old extrusion
  }
  else {
    Extrude_Mesh(M->Volumes); // new extrusion
    Tree_Action(M->Volumes, Maillage_Volume); // delaunay of remaining parts
  }

  // transfer data back to individual volumes and remove special volume
  for(int i = 0; i < List_Nbr(list); i++){
    List_Read(list, i, &IVOL);
    Tree_Action(v->Simplexes, TransferData);
  }
  Tree_Suppress(M->Volumes, &v);
  Free_Volume_But_Not_Elements(&v, NULL);

  List_Delete(list);

  double t2 = Cpu();

  M->timing[2] = t2 - t1;
}

void Init_Mesh0(Mesh * M)
{
  THEM = M;
  M->bds = 0;
  M->bds_mesh = 0;
  M->Vertices = NULL;
  M->Simplexes = NULL;
  M->Points = NULL;
  M->Curves = NULL;
  M->SurfaceLoops = NULL;
  M->EdgeLoops = NULL;
  M->Surfaces = NULL;
  M->Volumes = NULL;
  M->PhysicalGroups = NULL;
  M->Partitions = NULL;
  M->Metric = NULL;
}

void Init_Mesh(Mesh * M)
{
  THEM = M;
  M->MaxPointNum = 0;
  M->MaxLineNum = 0;
  M->MaxLineLoopNum = 0;
  M->MaxSurfaceNum = 0;
  M->MaxSurfaceLoopNum = 0;
  M->MaxVolumeNum = 0;
  M->MaxPhysicalNum = 0;

  Element::TotalNumber = 0;

  ExitExtrude();

  if(M->bds) delete M->bds;
  M->bds = 0;

  Tree_Action(M->Vertices, Free_Vertex);  
  Tree_Delete(M->Vertices);

  Tree_Action(M->Points, Free_Vertex);  
  Tree_Delete(M->Points);

  // Note: don't free the simplices here (with Tree_Action
  // (M->Simplexes, Free_Simplex)): we free them in each curve,
  // surface, volume
  Tree_Delete(M->Simplexes);

  Tree_Action(M->Curves, Free_Curve);
  Tree_Delete(M->Curves);

  Tree_Action(M->SurfaceLoops, Free_SurfaceLoop);
  Tree_Delete(M->SurfaceLoops);

  Tree_Action(M->EdgeLoops, Free_EdgeLoop);
  Tree_Delete(M->EdgeLoops);

  Tree_Action(M->Surfaces, Free_Surface);
  Tree_Delete(M->Surfaces);

  Tree_Action(M->Volumes, Free_Volume);
  Tree_Delete(M->Volumes);

  List_Action(M->PhysicalGroups, Free_PhysicalGroup);
  List_Delete(M->PhysicalGroups);

  List_Action(M->Partitions, Free_MeshPartition);
  List_Delete(M->Partitions);

  if(M->Metric)
    delete M->Metric;

  if(M->normals)
    delete M->normals;

  M->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);
  M->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
  M->Points = Tree_Create(sizeof(Vertex *), compareVertex);
  M->Curves = Tree_Create(sizeof(Curve *), compareCurve);
  M->SurfaceLoops = Tree_Create(sizeof(SurfaceLoop *), compareSurfaceLoop);
  M->EdgeLoops = Tree_Create(sizeof(EdgeLoop *), compareEdgeLoop);
  M->Surfaces = Tree_Create(sizeof(Surface *), compareSurface);
  M->Volumes = Tree_Create(sizeof(Volume *), compareVolume);
  M->PhysicalGroups = List_Create(5, 5, sizeof(PhysicalGroup *));
  M->Partitions = List_Create(5, 5, sizeof(MeshPartition *));
  M->Metric = new GMSHMetric;
  M->normals = new smooth_normals(CTX.mesh.angle_smooth_normals);

  M->status = 0;
  M->BackgroundMeshType = WITHPOINTS;

  for(int i = 0; i < 3; i++){
    M->timing[i] = 0.0;
    M->quality_gamma[i] = 0.0;
    M->quality_eta[i] = 0.0;
    M->quality_rho[i] = 0.0;
  }
  CTX.mesh.changed = 1;
}

void mai3d(Mesh * M, int Asked)
{
  double t1, t2;
  int oldstatus;

  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }

  oldstatus = M->status;

  // Re-read data

  if((Asked > oldstatus && Asked >= 0 && oldstatus < 0) ||
     (Asked < oldstatus)) {
    OpenProblem(CTX.filename);
    M->status = 0;
  }

  CTX.threads_lock = 1;

  // Clean up all the 2nd order nodes and transfer all SimplexBase
  // into "real" Simplexes

  Degre1();

  // 1D mesh

  if((Asked > oldstatus && Asked > 0 && oldstatus < 1) ||
     (Asked < oldstatus && Asked > 0)) {
    Msg(STATUS2, "Mesh 1D...");
    t1 = Cpu();

    if(M->status > 1) {
      OpenProblem(CTX.filename);
    }

    Maillage_Dimension_1(M);
    t2 = Cpu();
    Msg(STATUS2, "Mesh 1D complete (%g s)", t2 - t1);
    M->status = 1;
  }

  // 2D mesh

  if((Asked > oldstatus && Asked > 1 && oldstatus < 2) ||
     (Asked < oldstatus && Asked > 1)) {
    Msg(STATUS2, "Mesh 2D...");
    t1 = Cpu();

    if(M->status == 3) {
      OpenProblem(CTX.filename);
      Maillage_Dimension_1(M);
    }

    Maillage_Dimension_2(M);
    t2 = Cpu();
    Msg(STATUS2, "Mesh 2D complete (%g s)", t2 - t1);
    M->status = 2;
  }

  // 3D mesh

  if((Asked > oldstatus && Asked > 2 && oldstatus < 3) ||
     (Asked < oldstatus && Asked > 2)) {
    Msg(STATUS2, "Mesh 3D...");
    t1 = Cpu();
    Maillage_Dimension_3(M);
    t2 = Cpu();
    Msg(STATUS2, "Mesh 3D complete (%g s)", t2 - t1);
    M->status = 3;
  }

  // Optimize quality

  if(M->status == 3 && CTX.mesh.optimize)
    Optimize_Netgen(M);

  // Create second order elements

  if(M->status && CTX.mesh.order == 2)
    Degre2(M->status);

  // Partition

  if(M->status > 1 && CTX.mesh.nbPartitions != 1)
    PartitionMesh(M, CTX.mesh.nbPartitions);

  CTX.threads_lock = 0;
  CTX.mesh.changed = 1;
}
