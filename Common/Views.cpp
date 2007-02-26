// $Id: Views.cpp,v 1.194 2007-02-26 08:25:36 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   Nicolas Tardieu

#include <set>
#include "Gmsh.h"
#include "Numeric.h"
#include "Views.h"
#include "Context.h"
#include "Options.h"
#include "ColorTable.h"
#include "SmoothData.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

extern Context_T CTX;

#if defined(HAVE_FLTK)
void UpdateViewsInGUI();
#endif

// Static reference view

Post_View *Post_ViewReference = NULL;

// FIXME: the whole View interface should be rewritten in C++...

int fcmpPostViewNum(const void *v1, const void *v2)
{
  return ((*(Post_View **) v1)->Num - (*(Post_View **) v2)->Num);
}

int fcmpPostViewAliasOf(const void *v1, const void *v2)
{
  return ((*(Post_View **) v1)->AliasOf - (*(Post_View **) v2)->AliasOf);
}

int fcmpPostViewName(const void *v1, const void *v2)
{
  return strcmp((*(Post_View **) v1)->Name, (*(Post_View **) v2)->Name);
}

int fcmpPostViewVisibility(const void *v1, const void *v2)
{
  return ((*(Post_View **) v2)->Visible - (*(Post_View **) v1)->Visible);
}

Post_View *BeginView(int allocate)
{
  Post_View *v = (Post_View *)Malloc(sizeof(Post_View));
  static int UniqueNum = 0;

  if(!CTX.post.list)
    CTX.post.list = List_Create(100, 100, sizeof(Post_View *));

  // Important notes:
  // - each view *must* have a unique number
  // - the view list is assumned to be sorted with increasing nums

  if(!CTX.post.force_num) {
    v->Num = ++UniqueNum;
    List_Add(CTX.post.list, &v);
  }
  else {
    v->Num = CTX.post.force_num;
    List_Replace(CTX.post.list, &v, fcmpPostViewNum);
    // invalidate the background mesh
    if(v->Num == CTX.mesh.bgmesh_view_num) CTX.mesh.bgmesh_view_num = -1;
  }
  
  int i = List_ISearch(CTX.post.list, &v, fcmpPostViewNum);
  List_Read(CTX.post.list, i, &v);

  v->Index = i;
  v->Dirty = 1;
  v->TriVertexArray = NULL;
  v->LinVertexArray = NULL;
  v->NbTimeStep = 1;
  v->TimeStepMin = NULL;
  v->TimeStepMax = NULL;
  v->NbSP = v->NbVP = v->NbTP = 0;
  v->NbSL = v->NbVL = v->NbTL = v->NbSL2 = v->NbVL2 = v->NbTL2 = 0;
  v->NbST = v->NbVT = v->NbTT = v->NbST2 = v->NbVT2 = v->NbTT2 = 0;
  v->NbSQ = v->NbVQ = v->NbTQ = v->NbSQ2 = v->NbVQ2 = v->NbTQ2 = 0;
  v->NbSS = v->NbVS = v->NbTS = v->NbSS2 = v->NbVS2 = v->NbTS2 = 0;
  v->NbSH = v->NbVH = v->NbTH = v->NbSH2 = v->NbVH2 = v->NbTH2 = 0;
  v->NbSI = v->NbVI = v->NbTI = v->NbSI2 = v->NbVI2 = v->NbTI2 = 0;
  v->NbSY = v->NbVY = v->NbTY = v->NbSY2 = v->NbVY2 = v->NbTY2 = 0;
  v->NbT2 = v->NbT3 = 0;

  if(allocate) {
    v->DataSize = sizeof(double);
    v->Grains = new  std::map < int , List_T * > ;
    v->DisplayListsOfGrains= new  std::map < int , int > ;

#define LCD List_Create(1, 1000, sizeof(double))
    v->Time = LCD;
    v->SP = LCD; v->VP = LCD; v->TP = LCD;
    v->SL = LCD; v->VL = LCD; v->TL = LCD; v->SL2 = LCD; v->VL2 = LCD; v->TL2 = LCD; 
    v->ST = LCD; v->VT = LCD; v->TT = LCD; v->ST2 = LCD; v->VT2 = LCD; v->TT2 = LCD; 
    v->SQ = LCD; v->VQ = LCD; v->TQ = LCD; v->SQ2 = LCD; v->VQ2 = LCD; v->TQ2 = LCD; 
    v->SS = LCD; v->VS = LCD; v->TS = LCD; v->SS2 = LCD; v->VS2 = LCD; v->TS2 = LCD; 
    v->SH = LCD; v->VH = LCD; v->TH = LCD; v->SH2 = LCD; v->VH2 = LCD; v->TH2 = LCD; 
    v->SI = LCD; v->VI = LCD; v->TI = LCD; v->SI2 = LCD; v->VI2 = LCD; v->TI2 = LCD; 
    v->SY = LCD; v->VY = LCD; v->TY = LCD; v->SY2 = LCD; v->VY2 = LCD; v->TY2 = LCD; 
#undef LCD

    v->T2D = List_Create(1, 100, sizeof(double));
    v->T2C = List_Create(1, 100, sizeof(char));
    v->T3D = List_Create(1, 100, sizeof(double));
    v->T3C = List_Create(1, 100, sizeof(char));
  }
  else {
    v->Time = NULL;
    v->Grains = 0;
    v->DisplayListsOfGrains = 0;
    v->SP = v->VP = v->TP = NULL;
    v->SL = v->VL = v->TL = v->SL2 = v->VL2 = v->TL2 = NULL;
    v->ST = v->VT = v->TT = v->ST2 = v->VT2 = v->TT2 = NULL;
    v->SQ = v->VQ = v->TQ = v->SQ2 = v->VQ2 = v->TQ2 = NULL;
    v->SS = v->VS = v->TS = v->SS2 = v->VS2 = v->TS2 = NULL;
    v->SH = v->VH = v->TH = v->SH2 = v->VH2 = v->TH2 = NULL;
    v->SI = v->VI = v->TI = v->SI2 = v->VI2 = v->TI2 = NULL;
    v->SY = v->VY = v->TY = v->SY2 = v->VY2 = v->TY2 = NULL;
    v->T2D = v->T2C = NULL;
    v->T3D = v->T3C = NULL;
  }

  // Copy all options from the reference view initialized in InitOptions()
  CopyViewOptions(Post_ViewReference, v);
  
  v->Changed = 1;
  v->Links = 0;
  v->AliasOf = 0;
  v->ScalarOnly = 1;
  v->TextOnly = 1;
  v->normals = new smooth_normals(v->AngleSmoothNormals);
  v->Min = VAL_INF;
  v->Max = -VAL_INF;
  v->adaptive = 0;
  for(i = 0; i < 3; i++) {
    v->BBox[2 * i] = v->TmpBBox[2 * i] = VAL_INF;
    v->BBox[2 * i + 1] = v->TmpBBox[2 * i + 1] = -VAL_INF;
  }
  for(i = 0; i < 3; i++)
    v->GenRaise_f[i] = NULL;

  return v;
}

void Post_View::reset_normals()
{
  if(normals)
    delete normals;
  normals = new smooth_normals(AngleSmoothNormals);
}

double ComputeVonMises(double *V)
{
  static const double THIRD = 1.e0 / 3.e0;
  double tr = (V[0] + V[4] + V[8]) * THIRD;
  double v11 = V[0] - tr;
  double v12 = V[1];
  double v13 = V[2];
  double v21 = V[3];
  double v22 = V[4] - tr;
  double v23 = V[5];
  double v31 = V[6];
  double v32 = V[7];
  double v33 = V[8] - tr;
  return sqrt(1.5 * (v11 * v11 + v12 * v12 + v13 * v13 +
                     v21 * v21 + v22 * v22 + v23 * v23 +
                     v31 * v31 + v32 * v32 + v33 * v33));
}
  
void Stat_Element(Post_View *v, int type, int nbnod, int N,
                  double *X, double *Y, double *Z, double *V)
{
  int i;
  double l0;

  switch (type) {

  case 0:      // scalar
    if(v->Min == VAL_INF || v->Max == -VAL_INF) {
      v->NbTimeStep = N / nbnod;
      if(v->TimeStepMin) Free(v->TimeStepMin);
      if(v->TimeStepMax) Free(v->TimeStepMax);
      v->TimeStepMin = (double*)Malloc(v->NbTimeStep * sizeof(double));
      v->TimeStepMax = (double*)Malloc(v->NbTimeStep * sizeof(double));
      for(i = 0; i < v->NbTimeStep; i++){
	v->TimeStepMin[i] = VAL_INF;
	v->TimeStepMax[i] = -VAL_INF;
      }
    }
    else if(N / nbnod < v->NbTimeStep){
      // if some elts have less steps, reduce the total number!
      v->NbTimeStep = N / nbnod;
    }

    for(i = 0; i < N; i++) {
      l0 = V[i];
      if(l0 < v->Min)
        v->Min = l0;
      if(l0 > v->Max)
        v->Max = l0;
      int ts = i / nbnod;
      if(ts < v->NbTimeStep){ // security
	if(l0 < v->TimeStepMin[ts])
	  v->TimeStepMin[ts] = l0;
	if(l0 > v->TimeStepMax[ts])
	  v->TimeStepMax[ts] = l0;
      }
    }
    break;

  case 1:      // vector
    if(v->Min == VAL_INF || v->Max == -VAL_INF) {
      v->NbTimeStep = N / (3 * nbnod);
      if(v->TimeStepMin) Free(v->TimeStepMin);
      if(v->TimeStepMax) Free(v->TimeStepMax);
      v->TimeStepMin = (double*)Malloc(v->NbTimeStep * sizeof(double));
      v->TimeStepMax = (double*)Malloc(v->NbTimeStep * sizeof(double));
      for(i = 0; i < v->NbTimeStep; i++){
	v->TimeStepMin[i] = VAL_INF;
	v->TimeStepMax[i] = -VAL_INF;
      }
    }
    else if(N / (3 * nbnod) < v->NbTimeStep){
      v->NbTimeStep = N / (3 * nbnod);
    }

    for(i = 0; i < N; i += 3) {
      l0 = sqrt(DSQR(V[i]) + DSQR(V[i + 1]) + DSQR(V[i + 2]));
      if(l0 < v->Min)
        v->Min = l0;
      if(l0 > v->Max)
        v->Max = l0;
      int ts = i / (3 * nbnod);
      if(ts < v->NbTimeStep){ // security
	if(l0 < v->TimeStepMin[ts])
	  v->TimeStepMin[ts] = l0;
	if(l0 > v->TimeStepMax[ts])
	  v->TimeStepMax[ts] = l0;
      }
    }
    v->ScalarOnly = 0;
    break;

  case 2:      // tensor
    if(v->Min == VAL_INF || v->Max == -VAL_INF) {
      v->NbTimeStep = N / (9 * nbnod);
      if(v->TimeStepMin) Free(v->TimeStepMin);
      if(v->TimeStepMax) Free(v->TimeStepMax);
      v->TimeStepMin = (double*)Malloc(v->NbTimeStep * sizeof(double));
      v->TimeStepMax = (double*)Malloc(v->NbTimeStep * sizeof(double));
      for(i = 0; i < v->NbTimeStep; i++){
	v->TimeStepMin[i] = VAL_INF;
	v->TimeStepMax[i] = -VAL_INF;
      }
    }
    else if(N / (9 * nbnod) < v->NbTimeStep){
      v->NbTimeStep = N / (9 * nbnod);
    }

    for(i = 0; i < N; i += 9) {
      // by lack of any current better solution, tensors are displayed
      // as their Von Mises invariant (J2 invariant)
      l0 = ComputeVonMises(V+i);
      if(l0 < v->Min)
        v->Min = l0;
      if(l0 > v->Max)
        v->Max = l0;
      int ts = i / (9 * nbnod);
      if(ts < v->NbTimeStep){ // security
	if(l0 < v->TimeStepMin[ts])
	  v->TimeStepMin[ts] = l0;
	if(l0 > v->TimeStepMax[ts])
	  v->TimeStepMax[ts] = l0;
      }
    }
    v->ScalarOnly = 0;
    break;

  }

  for(i = 0; i < nbnod; i++) {
    if(X[i] < v->BBox[0]) v->BBox[0] = X[i];
    if(X[i] > v->BBox[1]) v->BBox[1] = X[i];
    if(Y[i] < v->BBox[2]) v->BBox[2] = Y[i];
    if(Y[i] > v->BBox[3]) v->BBox[3] = Y[i];
    if(Z[i] < v->BBox[4]) v->BBox[4] = Z[i];
    if(Z[i] > v->BBox[5]) v->BBox[5] = Z[i];
  }

  v->TextOnly = 0;
}

void Stat_List(Post_View * v, List_T * listelm, int type, int nbelm,
               int nbnod)
{
  int i, nb;
  if(nbelm) {
    nb = List_Nbr(listelm) / nbelm;
    for(i = 0; i < List_Nbr(listelm); i += nb)
      Stat_Element(v, type, nbnod, nb - 3 * nbnod,
                   (double *)List_Pointer_Fast(listelm, i),
                   (double *)List_Pointer_Fast(listelm, i + 1 * nbnod),
                   (double *)List_Pointer_Fast(listelm, i + 2 * nbnod),
                   (double *)List_Pointer_Fast(listelm, i + 3 * nbnod));
  }
}

void Stat_Text(Post_View * v, List_T *D, List_T *C, int nb)
{
  for(int i = 0; i < List_Nbr(D); i += nb){
    double beg, end;
    List_Read(D, i+nb-1, &beg);
    if(i > List_Nbr(D) - 2*nb)
      end = (double)List_Nbr(C);
    else
      List_Read(D, i+nb+nb-1, &end);
    char *c = (char*)List_Pointer(C, (int)beg);
    int nbtime = 0;
    for(int j = 0; j < (int)(end-beg); j++)
      if(c[j] == '\0') nbtime++;
    if(nbtime > v->NbTimeStep) 
      v->NbTimeStep = nbtime;
  }

  if(nb == 5){
    for(int i = 0; i < List_Nbr(D); i += nb){
      double x, y, z;
      List_Read(D, i, &x);
      List_Read(D, i+1, &y);
      List_Read(D, i+2, &z);
      if(x < v->BBox[0]) v->BBox[0] = x;
      if(x > v->BBox[1]) v->BBox[1] = x;
      if(y < v->BBox[2]) v->BBox[2] = y;
      if(y > v->BBox[3]) v->BBox[3] = y;
      if(z < v->BBox[4]) v->BBox[4] = z;
      if(z > v->BBox[5]) v->BBox[5] = z;
    }
  }
}

void EndView(Post_View * v, int add_in_gui, char *file_name, char *name)
{
  int i;
  double d;

  // Stat text strings first, to get the max value of NbTimeStep for
  // srings-only (strings are designed to degrade gracefully when some
  // have fewer time steps than others). If there are any elements in
  // the view, this value will be replaced by the minimum number of
  // time steps common to all elements.
  Stat_Text(v, v->T2D, v->T2C, 4);
  Stat_Text(v, v->T3D, v->T3C, 5);

  // convert all curved (geometrically 2nd order) elements into linear
  // elements *AND* free all the data associated with the curved
  // elements
  v->splitCurvedElements();
  
  // Points
  Stat_List(v, v->SP, 0, v->NbSP, 1);
  Stat_List(v, v->VP, 1, v->NbVP, 1);
  Stat_List(v, v->TP, 2, v->NbTP, 1);

  // Lines               
  Stat_List(v, v->SL, 0, v->NbSL, 2);
  Stat_List(v, v->VL, 1, v->NbVL, 2);
  Stat_List(v, v->TL, 2, v->NbTL, 2);

  // Triangles           
  Stat_List(v, v->ST, 0, v->NbST, 3);
  Stat_List(v, v->VT, 1, v->NbVT, 3);
  Stat_List(v, v->TT, 2, v->NbTT, 3);

  // Quadrangles  
  Stat_List(v, v->SQ, 0, v->NbSQ, 4);
  Stat_List(v, v->VQ, 1, v->NbVQ, 4);
  Stat_List(v, v->TQ, 2, v->NbTQ, 4);

  // Tetrahedra          
  Stat_List(v, v->SS, 0, v->NbSS, 4);
  Stat_List(v, v->VS, 1, v->NbVS, 4);
  Stat_List(v, v->TS, 2, v->NbTS, 4);

  // Hexahedra           
  Stat_List(v, v->SH, 0, v->NbSH, 8);
  Stat_List(v, v->VH, 1, v->NbVH, 8);
  Stat_List(v, v->TH, 2, v->NbTH, 8);

  // Prisms              
  Stat_List(v, v->SI, 0, v->NbSI, 6);
  Stat_List(v, v->VI, 1, v->NbVI, 6);
  Stat_List(v, v->TI, 2, v->NbTI, 6);

  // Pyramids            
  Stat_List(v, v->SY, 0, v->NbSY, 5);
  Stat_List(v, v->VY, 1, v->NbVY, 5);
  Stat_List(v, v->TY, 2, v->NbTY, 5);

  // Dummy time values if none (or too few) provided (e.g. using old
  // parsed format)
  if(v->Time && List_Nbr(v->Time) < v->NbTimeStep) {
    for(i = List_Nbr(v->Time); i < v->NbTimeStep; i++) {
      d = (double)i;
      List_Add(v->Time, &d);
    }
  }

  opt_view_name(v->Index, GMSH_SET | GMSH_GUI, name);
  opt_view_filename(v->Index, GMSH_SET | GMSH_GUI, file_name);
  opt_view_nb_timestep(v->Index, GMSH_GUI, 0);
  opt_view_timestep(v->Index, GMSH_SET | GMSH_GUI, v->TimeStep);

  if(CTX.post.smooth)
    v->smooth();

#if defined(HAVE_FLTK)
  if(add_in_gui)
    UpdateViewsInGUI();
#endif

  v->Dirty = 0; //the view is complete, we may draw it

  Msg(DEBUG, "Added View[%d]", v->Index);
}

void AliasView(int index, int withoptions)
{
  if(index < 0 || index >= List_Nbr(CTX.post.list)) {
    return;
  }

  Post_View v, *pv, **ppv;

  Post_View *v1 = *(Post_View **) List_Pointer(CTX.post.list, index);

  Post_View *v2 = BeginView(0);
  EndView(v2, 0, v1->FileName, v1->Name);

  if(!v1->AliasOf) {
    v2->AliasOf = v1->Num;
    v1->Links++;
  }
  else {
    v.Num = v1->AliasOf;
    pv = &v;
    if(!(ppv = (Post_View **) List_PQuery(CTX.post.list, &pv, fcmpPostViewNum))) {
      v2->AliasOf = v1->Num;
      v1->Links++;
    }
    else {
      v2->AliasOf = (*ppv)->Num;
      (*ppv)->Links++;
    }
  }

  // When we create an alias we just point to a reference view: we
  // DON'T allocate a new data set!
  v2->Time = v1->Time;
  v2->TimeStepMin = v1->TimeStepMin;
  v2->TimeStepMax = v1->TimeStepMax;

  v2->NbSP = v1->NbSP; v2->SP = v1->SP; 
  v2->NbVP = v1->NbVP; v2->VP = v1->VP; 
  v2->NbTP = v1->NbTP; v2->TP = v1->TP;

  v2->NbSL = v1->NbSL; v2->SL = v1->SL; 
  v2->NbVL = v1->NbVL; v2->VL = v1->VL; 
  v2->NbTL = v1->NbTL; v2->TL = v1->TL;

  v2->NbST = v1->NbST; v2->ST = v1->ST; 
  v2->NbVT = v1->NbVT; v2->VT = v1->VT; 
  v2->NbTT = v1->NbTT; v2->TT = v1->TT;

  v2->NbSQ = v1->NbSQ; v2->SQ = v1->SQ; 
  v2->NbVQ = v1->NbVQ; v2->VQ = v1->VQ; 
  v2->NbTQ = v1->NbTQ; v2->TQ = v1->TQ;

  v2->NbSS = v1->NbSS; v2->SS = v1->SS; 
  v2->NbVS = v1->NbVS; v2->VS = v1->VS; 
  v2->NbTS = v1->NbTS; v2->TS = v1->TS;

  v2->NbSH = v1->NbSH; v2->SH = v1->SH; 
  v2->NbVH = v1->NbVH; v2->VH = v1->VH; 
  v2->NbTH = v1->NbTH; v2->TH = v1->TH;

  v2->NbSI = v1->NbSI; v2->SI = v1->SI; 
  v2->NbVI = v1->NbVI; v2->VI = v1->VI; 
  v2->NbTI = v1->NbTI; v2->TI = v1->TI;

  v2->NbSY = v1->NbSY; v2->SY = v1->SY; 
  v2->NbVY = v1->NbVY; v2->VY = v1->VY; 
  v2->NbTY = v1->NbTY; v2->TY = v1->TY;

  v2->NbT2 = v1->NbT2; v2->T2D = v1->T2D; v2->T2C = v1->T2C;
  v2->NbT3 = v1->NbT3; v2->T3D = v1->T3D; v2->T3C = v1->T3C;

  v2->DataSize    = v1->DataSize;
  v2->ScalarOnly  = v1->ScalarOnly;
  v2->TextOnly    = v1->TextOnly;
  v2->Min         = v1->Min;       
  v2->Max         = v1->Max;      
  v2->NbTimeStep  = v1->NbTimeStep;
  for(int i=0 ; i<6 ; i++)
    v2->BBox[i]   = v1->BBox[i];

  if(withoptions)
    CopyViewOptions(v1, v2);

#if defined(HAVE_FLTK)
  UpdateViewsInGUI();
#endif
}

bool RemoveViewByIndex(int index)
{
  if(index < 0 || index >= List_Nbr(CTX.post.list)) {
    return false;
  }

  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, index);
  FreeView(v);
  List_PSuppress(CTX.post.list, index);

  // recalculate the indices
  for(int i = 0; i < List_Nbr(CTX.post.list); i++){
    v = *(Post_View **) List_Pointer(CTX.post.list, i);
    v->Index = i;
  }

  Msg(DEBUG, "Removed View[%d] (%d views left)", index, List_Nbr(CTX.post.list));
  return true;
}

bool RemoveViewByNumber(int num)
{
  Post_View v, *pv;

  v.Num = num;
  pv = &v;
  int i = List_ISearch(CTX.post.list, &pv, fcmpPostViewNum);
  
  return RemoveViewByIndex(i);
}

void FreeView(Post_View * v)
{
  Post_View vv, *pvv, **ppvv;
  int i, numdup, free = 1;

  if(v->AliasOf) {
    vv.Num = v->AliasOf;
    pvv = &vv;
    Msg(DEBUG, "This view is a duplicata");
    if(!(ppvv = (Post_View **) List_PQuery(CTX.post.list, &pvv, fcmpPostViewNum))) {
      Msg(DEBUG, "  -the original view is gone");
      numdup = 0;
      for(i = 0; i < List_Nbr(CTX.post.list); i++)
        numdup += ((*(Post_View **) List_Pointer(CTX.post.list, i))->AliasOf
		   == v->AliasOf);
      if(numdup == 1) {
        Msg(DEBUG, "  -there are no other duplicata, so I can free");
        free = 1;
      }
      else {
        Msg(DEBUG, "  -there are still duplicata, so I cannot free");
        free = 0;
      }
    }
    else {
      (*ppvv)->Links--;
      free = 0;
      Msg(DEBUG, "  -the original still exists, so I cannot free");
    }
  }

  if(free && !v->Links) {
    Msg(DEBUG, "Freeing View!");
    List_Delete(v->Time);
    Free(v->TimeStepMin);
    Free(v->TimeStepMax);
    List_Delete(v->SP); List_Delete(v->VP); List_Delete(v->TP);
    List_Delete(v->SL); List_Delete(v->VL); List_Delete(v->TL);
    List_Delete(v->ST); List_Delete(v->VT); List_Delete(v->TT);
    List_Delete(v->SQ); List_Delete(v->VQ); List_Delete(v->TQ);
    List_Delete(v->SS); List_Delete(v->VS); List_Delete(v->TS);
    List_Delete(v->SH); List_Delete(v->VH); List_Delete(v->TH);
    List_Delete(v->SI); List_Delete(v->VI); List_Delete(v->TI);
    List_Delete(v->SY); List_Delete(v->VY); List_Delete(v->TY);
    List_Delete(v->T2D); List_Delete(v->T2C);
    List_Delete(v->T3D); List_Delete(v->T3C);
    delete v->Grains;
    delete v->DisplayListsOfGrains;
    // Note: all the second order elements have already been freed in xxxx
    if(v->normals) delete v->normals;
    if(v->TriVertexArray) delete v->TriVertexArray;
    if(v->LinVertexArray) delete v->LinVertexArray;
    if(v->adaptive) delete v->adaptive;
    FreeGeneralizedRaise(v);
    Free(v);
  }
}

void CopyViewOptions(Post_View * src, Post_View * dest)
{
  dest->Type = src->Type;
  dest->AutoPosition = src->AutoPosition;
  dest->AxesAutoPosition = src->AxesAutoPosition;
  dest->Position[0] = src->Position[0];
  dest->Position[1] = src->Position[1];
  dest->Size[0] = src->Size[0];
  dest->Size[1] = src->Size[1];
  for(int i = 0; i < 6; i++) dest->AxesPosition[i] = src->AxesPosition[i];
  for(int i = 0; i < 3; i++) dest->AxesTics[i] = src->AxesTics[i];
  strcpy(dest->Format, src->Format);
  for(int i = 0; i < 3; i++) strcpy(dest->AxesFormat[i], src->AxesFormat[i]);
  for(int i = 0; i < 3; i++) strcpy(dest->AxesLabel[i], src->AxesLabel[i]);
  dest->CustomMin = src->CustomMin;
  dest->CustomMax = src->CustomMax;
  dest->Offset[0] = src->Offset[0];
  dest->Offset[1] = src->Offset[1];
  dest->Offset[2] = src->Offset[2];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      dest->Transform[i][j] = src->Transform[i][j];
  dest->Raise[0] = src->Raise[0];
  dest->Raise[1] = src->Raise[1];
  dest->Raise[2] = src->Raise[2];
  dest->ArrowSize = src->ArrowSize;
  dest->ArrowSizeProportional = src->ArrowSizeProportional;
  dest->ArrowRelHeadRadius = src->ArrowRelHeadRadius;
  dest->ArrowRelStemLength = src->ArrowRelStemLength;
  dest->ArrowRelStemRadius = src->ArrowRelStemRadius;
  dest->Normals = src->Normals;
  dest->Tangents = src->Tangents;
  dest->DisplacementFactor = src->DisplacementFactor;
  dest->Explode = src->Explode;
  dest->Visible = src->Visible;
  dest->IntervalsType = src->IntervalsType;
  dest->SaturateValues = src->SaturateValues;
  dest->Boundary = src->Boundary;
  dest->NbIso = src->NbIso;
  dest->Light = src->Light;
  dest->LightTwoSide = src->LightTwoSide;
  dest->LightLines = src->LightLines;
  dest->SmoothNormals = src->SmoothNormals;
  dest->AngleSmoothNormals = src->AngleSmoothNormals;
  dest->ShowElement = src->ShowElement;
  dest->ShowTime = src->ShowTime;
  dest->ShowScale = src->ShowScale;
  dest->DrawPoints = src->DrawPoints;
  dest->DrawLines = src->DrawLines;
  dest->DrawTriangles = src->DrawTriangles;
  dest->DrawQuadrangles = src->DrawQuadrangles;
  dest->DrawTetrahedra = src->DrawTetrahedra;
  dest->DrawHexahedra = src->DrawHexahedra;
  dest->DrawPrisms = src->DrawPrisms;
  dest->DrawPyramids = src->DrawPyramids;
  dest->DrawScalars = src->DrawScalars;
  dest->DrawVectors = src->DrawVectors;
  dest->DrawTensors = src->DrawTensors;
  dest->DrawStrings = src->DrawStrings;
  dest->ScaleType = src->ScaleType;
  dest->RangeType = src->RangeType;
  dest->VectorType = src->VectorType;
  dest->GlyphLocation = src->GlyphLocation;
  dest->TensorType = src->TensorType;
  dest->TimeStep = src->TimeStep;
  dest->PointSize = src->PointSize;
  dest->LineWidth = src->LineWidth;
  dest->PointType = src->PointType;
  dest->LineType = src->LineType;
  dest->Axes = src->Axes;
  dest->ExternalViewIndex = src->ExternalViewIndex;
  dest->ViewIndexForGenRaise = src->ViewIndexForGenRaise;
  dest->UseGenRaise = src->UseGenRaise;
  dest->FakeTransparency = src->FakeTransparency;
  dest->GenRaiseFactor = src->GenRaiseFactor;
  strcpy(dest->GenRaiseX, src->GenRaiseX);
  strcpy(dest->GenRaiseY, src->GenRaiseY);
  strcpy(dest->GenRaiseZ, src->GenRaiseZ);
  dest->UseStipple = src->UseStipple;
  for(int i = 0; i < 10; i++){
    dest->Stipple[i][0] = src->Stipple[i][0];
    dest->Stipple[i][1] = src->Stipple[i][1];
    strcpy(dest->StippleString[i], src->StippleString[i]);
  }
  dest->color.point = src->color.point;
  dest->color.line = src->color.line;
  dest->color.triangle = src->color.triangle;
  dest->color.quadrangle = src->color.quadrangle;
  dest->color.tetrahedron = src->color.tetrahedron;
  dest->color.hexahedron = src->color.hexahedron;
  dest->color.prism = src->color.prism;
  dest->color.pyramid = src->color.pyramid;
  dest->color.tangents = src->color.tangents;
  dest->color.normals = src->color.normals;
  dest->color.text2d = src->color.text2d;
  dest->color.text3d = src->color.text3d;
  dest->color.axes = src->color.axes;
  ColorTable_Copy(&src->CT);
  ColorTable_Paste(&dest->CT);
}

GmshColorTable *Get_ColorTable(int num)
{
  Post_View *v;

  if(!CTX.post.list){
    v = Post_ViewReference;
    if(!v) return NULL;
  }
  else{
    Post_View **vv = (Post_View **) List_Pointer_Test(CTX.post.list, num);
    if(!vv) return NULL;
    v = *vv;
  }
  v->Changed = 1; // let's assume that if we get the ct we change it
  return &v->CT;
}

void Print_ColorTable(int num, int diff, char *prefix, FILE * file)
{
  char tmp[1024];
  Post_View *v;

  if(!CTX.post.list){
    v = Post_ViewReference;
    if(!v) return;
  }
  else{
    Post_View **vv = (Post_View **) List_Pointer_Test(CTX.post.list, num);
    if(!vv) return;
    v = *vv;
  }

  if(diff){
    // compare the current colormap with a vanilla colormap having the
    // parameters
    GmshColorTable ref;
    ColorTable_InitParam(v->CT.ipar[COLORTABLE_NUMBER], &ref); 
    for(int i = 0; i < COLORTABLE_NBMAX_PARAM; i++){
      ref.ipar[i] = v->CT.ipar[i];
      ref.dpar[i] = v->CT.dpar[i];
    }
    ColorTable_Recompute(&ref);
    if(!ColorTable_Diff(&ref, &v->CT))
      return;
  }

  sprintf(tmp, "%s = {", prefix);
  if(file)
    fprintf(file, "%s\n", tmp);
  else
    Msg(DIRECT, tmp);
  ColorTable_Print(&v->CT, file);
  sprintf(tmp, "};");
  if(file)
    fprintf(file, "%s\n", tmp);
  else
    Msg(DIRECT, tmp);
}

Post_View *Create2DGraph(char *xname, char *yname,
                         int nbdata, double *x, double *y)
{
  Post_View *v = BeginView(1);
  for(int i = 0; i < nbdata; i++) {
    double d;
    if(x){
      List_Add(v->SP, &x[i]);
    }
    else{
      d = nbdata > 1 ? (double)i/(double)(nbdata - 1) : 0;
      List_Add(v->SP, &d);
    }
    d = 0.;
    List_Add(v->SP, &d);
    List_Add(v->SP, &d);
    List_Add(v->SP, &y[i]);
    v->NbSP++;
  }
  char filename[1024];
  sprintf(filename, "%s.pos", yname);
  EndView(v, 1, filename, yname);
  v->Type = DRAW_POST_2D_SPACE;
  v->Axes = 2;
  strcpy(v->AxesLabel[0], xname);
  return v;
}

// Transform curved elements into linear ones and delete all the
// curved element data. This is a temporary solution, until we can use
// an Adaptive_Post_View on curved elements, too.

void splitCurvedElement(List_T **in, int *nbin, List_T *out, int *nbout, 
			int nodin, int nodout, int nbcomp, int nbsplit, int split[][8],
			int remove=1)
{
  if(*nbin){
    int nb = List_Nbr(*in) / *nbin;
    int nbstep = (nb - 3 * nodin) / (nodin * nbcomp); // we don't know this yet for the view
    for(int i = 0; i < List_Nbr(*in); i += nb) {
      double *coord = (double *)List_Pointer_Fast(*in, i);
      double *val = (double *)List_Pointer_Fast(*in, i + 3 * nodin);
      for(int j = 0; j < nbsplit; j++){
	for(int k = 0; k < nodout; k++)
	  List_Add(out, &coord[split[j][k]]);
	for(int k = 0; k < nodout; k++)
	  List_Add(out, &coord[nodin + split[j][k]]);
	for(int k = 0; k < nodout; k++)
	  List_Add(out, &coord[2 * nodin + split[j][k]]);
	for(int ts = 0; ts < nbstep; ts++){
	  for(int k = 0; k < nodout; k++){
	    for(int l = 0; l < nbcomp; l++){
	      List_Add(out, &val[nodin * nbcomp * ts + nbcomp * split[j][k] + l]);
	    }
	  }
	}
	(*nbout)++;
      }
    }
  }

  if(remove){
    *nbin = 0;
    List_Delete(*in);
    *in = NULL;
  }
}

void Post_View::splitCurvedElements()
{
  // we could keep track of the starting index in SL, VL, ..., so that
  // we could draw the boundaries correctly

  int lin[2][8] = { // 2-split
    {0,2}, {2,1}
  };
  splitCurvedElement(&SL2, &NbSL2, SL, &NbSL, 3,2, 1, 2, lin);
  splitCurvedElement(&VL2, &NbVL2, VL, &NbVL, 3,2, 3, 2, lin);
  splitCurvedElement(&TL2, &NbTL2, TL, &NbTL, 3,2, 9, 2, lin);

  int tri[4][8] = { // 4-split
    {0,3,5}, {1,4,3}, {2,5,4}, {3,4,5}
  };
  splitCurvedElement(&ST2, &NbST2, ST, &NbST, 6,3, 1, 4, tri);
  splitCurvedElement(&VT2, &NbVT2, VT, &NbVT, 6,3, 3, 4, tri);
  splitCurvedElement(&TT2, &NbTT2, TT, &NbTT, 6,3, 9, 4, tri);

  int qua[4][8] = { // 4-split
    {0,4,8,7}, {1,5,8,4}, {2,6,8,5}, {3,7,8,6}
  };
  splitCurvedElement(&SQ2, &NbSQ2, SQ, &NbSQ, 9,4, 1, 4, qua);
  splitCurvedElement(&VQ2, &NbVQ2, VQ, &NbVQ, 9,4, 3, 4, qua);
  splitCurvedElement(&TQ2, &NbTQ2, TQ, &NbTQ, 9,4, 9, 4, qua);

  int tet[8][8] = { // 8-split
    {0,4,6,7}, {1,5,4,9}, {2,6,5,8}, {3,9,7,8},
    {4,6,7,8}, {4,6,5,8}, {4,5,9,8}, {4,7,9,8}
  };
  splitCurvedElement(&SS2, &NbSS2, SS, &NbSS, 10,4, 1, 8, tet);
  splitCurvedElement(&VS2, &NbVS2, VS, &NbVS, 10,4, 3, 8, tet);
  splitCurvedElement(&TS2, &NbTS2, TS, &NbTS, 10,4, 9, 8, tet);

  int hex[8][8] = { // 8-split
    {0,8,20,9, 10,21,26,22}, {8,1,11,20, 21,12,23,26},
    {9,20,13,3, 22,26,24,15}, {20,11,2,13, 26,23,14,24},
    {10,21,26,22, 4,16,25,17}, {21,12,23,26, 16,5,18,25},
    {22,26,24,15, 17,25,19,7}, {26,23,14,24, 25,18,6,19}
  };
  splitCurvedElement(&SH2, &NbSH2, SH, &NbSH, 27,8, 1, 8, hex);
  splitCurvedElement(&VH2, &NbVH2, VH, &NbVH, 27,8, 3, 8, hex);
  splitCurvedElement(&TH2, &NbTH2, TH, &NbTH, 27,8, 9, 8, hex);

  int pri[8][8] = { // 8-split
    {0,6,7, 8,15,16}, {1,9,6, 10,17,15}, {2,7,9, 11,16,17}, {6,9,7, 15,17,16},
    {8,15,16, 3,12,13}, {10,17,15, 4,14,12}, {11,16,17, 5,13,14}, {15,17,16, 12,14,13}
  };
  splitCurvedElement(&SI2, &NbSI2, SI, &NbSI, 18,6, 1, 8, pri);
  splitCurvedElement(&VI2, &NbVI2, VI, &NbVI, 18,6, 3, 8, pri);
  splitCurvedElement(&TI2, &NbTI2, TI, &NbTI, 18,6, 9, 8, pri);

  int pyr[6][8] = { // 6 pyramids
    {0,5,13,6, 7}, {5,1,8,13, 9}, {6,13,10,3, 12}, {13,8,2,10, 11},
    {7,9,11,12, 4}, {7,12,11,9, 13}
  };
  splitCurvedElement(&SY2, &NbSY2, SY, &NbSY, 14,5, 1, 6, pyr, 0); // don't remove yet
  splitCurvedElement(&VY2, &NbVY2, VY, &NbVY, 14,5, 3, 6, pyr, 0);
  splitCurvedElement(&TY2, &NbTY2, TY, &NbTY, 14,5, 9, 6, pyr, 0);

  int pyr2[4][8] = { // + 4 tets to fill the holes
    {6,12,7,13}, {7,9,5,13}, {9,11,8,13}, {12,10,11,13}
  };
  splitCurvedElement(&SY2, &NbSY2, SS, &NbSS, 14,4, 1, 4, pyr2);
  splitCurvedElement(&VY2, &NbVY2, VS, &NbVS, 14,4, 3, 4, pyr2);
  splitCurvedElement(&TY2, &NbTY2, TS, &NbTS, 14,4, 9, 4, pyr2);
}

// Smoothing

void generate_connectivities(List_T *list, int nbList, 
			     int nbTimeStep, int nbVert, smooth_data &data)
{
  if(!nbList) return;

  double *vals = new double[nbTimeStep];
  int nb = List_Nbr(list) / nbList;
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbVert);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbVert);
    double *v = (double *)List_Pointer_Fast(list, i + 3 * nbVert);
    for(int j = 0; j < nbVert; j++) {
      for(int k = 0; k < nbTimeStep; k++)
        vals[k] = v[j + k * nbVert];
      data.add(x[j], y[j], z[j], nbTimeStep, vals);
    }
  }
  delete [] vals;
}

void smooth_list(List_T *list, int nbList,
		 double *min, double *max, double *tsmin, double *tsmax, 
                 int nbTimeStep, int nbVert, smooth_data &data)
{
  if(!nbList)
    return;

  double *vals = new double[nbTimeStep];
  int nb = List_Nbr(list)/nbList;
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbVert);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbVert);
    double *v = (double *)List_Pointer_Fast(list, i + 3 * nbVert);
    for(int j = 0; j < nbVert; j++) {
      if(data.get(x[j], y[j], z[j], nbTimeStep, vals)){
	for(int k = 0; k < nbTimeStep; k++) {
	  double dd = vals[k];
          v[j + k * nbVert] = dd;
          if(dd < *min) *min = dd;
          if(dd > *max) *max = dd;
	  if(dd < tsmin[k]) tsmin[k] = dd;
	  if(dd > tsmax[k]) tsmax[k] = dd;
        }
      }
    }
  }
  delete [] vals;
}

void Post_View::smooth()
{
  double old_eps = xyzv::eps;
  xyzv::eps = CTX.lc * 1.e-8;
  
  if(NbSL || NbST || NbSQ || NbSS || NbSH || NbSI || NbSY) {
    Msg(INFO, "Smoothing scalar primitives in View[%d]", Index);
    Min = VAL_INF;
    Max = -VAL_INF;
    for(int k = 0; k < NbTimeStep; k++) {
      TimeStepMin[k] = VAL_INF;
      TimeStepMax[k] = -VAL_INF;
    }
    smooth_data data;
    generate_connectivities(SL, NbSL, NbTimeStep, 2, data);
    generate_connectivities(ST, NbST, NbTimeStep, 3, data);
    generate_connectivities(SQ, NbSQ, NbTimeStep, 4, data);
    generate_connectivities(SS, NbSS, NbTimeStep, 4, data);
    generate_connectivities(SH, NbSH, NbTimeStep, 8, data);
    generate_connectivities(SI, NbSI, NbTimeStep, 6, data);
    generate_connectivities(SY, NbSY, NbTimeStep, 5, data);
    smooth_list(SL, NbSL, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 2, data);
    smooth_list(ST, NbST, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 3, data);
    smooth_list(SQ, NbSQ, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 4, data);
    smooth_list(SS, NbSS, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 4, data);
    smooth_list(SH, NbSH, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 8, data);
    smooth_list(SI, NbSI, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 6, data);
    smooth_list(SY, NbSY, &Min, &Max, TimeStepMin, TimeStepMax, NbTimeStep, 5, data);
    Changed = 1;
  }

  xyzv::eps = old_eps;  
}

// Combine views (merge elements or merge time steps)

struct nameidx{
  char name[256];
  List_T *indices;
};

static int fcmp_name(const void *a, const void *b){
  char *name1 = ((struct nameidx*)a)->name;
  char *name2 = ((struct nameidx*)b)->name;
  return strcmp(name1, name2);
}

static void combine(List_T * a, List_T * b)
{
  if(!a || !b)
    return;
  for(int i = 0; i < List_Nbr(a); i++) {
    List_Add(b, List_Pointer(a, i));
  }
}

static void combine_strings(Post_View *a, Post_View *b)
{
  for(int i = 0; i < List_Nbr(a->T2D); i+=4){
    List_Add(b->T2D, List_Pointer(a->T2D, i));
    List_Add(b->T2D, List_Pointer(a->T2D, i+1));
    List_Add(b->T2D, List_Pointer(a->T2D, i+2)); 
    double d = List_Nbr(b->T2C);
    List_Add(b->T2D, &d);
    double beg, end;
    List_Read(a->T2D, i+3, &beg); 
    if(i > List_Nbr(a->T2D) - 8)
      end = (double)List_Nbr(a->T2C);
    else
      List_Read(a->T2D, i+3+4, &end); 
    char *c = (char*)List_Pointer(a->T2C, (int)beg);
    for(int j = 0; j < (int)(end-beg); j++)
      List_Add(b->T2C, &c[j]); 
    b->NbT2++;
  }
  for(int i = 0; i < List_Nbr(a->T3D); i+=5){
    List_Add(b->T3D, List_Pointer(a->T3D, i));
    List_Add(b->T3D, List_Pointer(a->T3D, i+1));
    List_Add(b->T3D, List_Pointer(a->T3D, i+2)); 
    List_Add(b->T3D, List_Pointer(a->T3D, i+3)); 
    double d = List_Nbr(b->T3C);
    List_Add(b->T3D, &d);
    double beg, end;
    List_Read(a->T3D, i+4, &beg); 
    if(i > List_Nbr(a->T3D) - 10)
      end = (double)List_Nbr(a->T3C);
    else
      List_Read(a->T3D, i+4+5, &end); 
    char *c = (char*)List_Pointer(a->T3C, (int)beg);
    for(int j = 0; j < (int)(end-beg); j++)
      List_Add(b->T3C, &c[j]); 
    b->NbT3++;
  }
}

static void combine_space(struct nameidx *id, List_T *to_remove)
{
  int index;

  // sanity check
  int nbt = 0;
  for(int i = 0; i < List_Nbr(id->indices); i++) {
    List_Read(id->indices, i, &index);
    Post_View *v = *(Post_View **)List_Pointer(CTX.post.list, index);
    if(!i){
      nbt = v->NbTimeStep;
    }
    else{
      if(v->NbTimeStep != nbt){
	Msg(GERROR, "Cannot combine views having different number of time steps");
	return;
      }
    }
  }

  Post_View *vm = BeginView(1);
  for(int i = 0; i < List_Nbr(id->indices); i++) {
    List_Read(id->indices, i, &index);
    Post_View *v = *(Post_View **)List_Pointer(CTX.post.list, index);
    List_Insert(to_remove, &v->Num, fcmp_int);
    combine(v->SP,vm->SP); vm->NbSP += v->NbSP;
    combine(v->VP,vm->VP); vm->NbVP += v->NbVP; 
    combine(v->TP,vm->TP); vm->NbTP += v->NbTP;
    combine(v->SL,vm->SL); vm->NbSL += v->NbSL;
    combine(v->VL,vm->VL); vm->NbVL += v->NbVL;
    combine(v->TL,vm->TL); vm->NbTL += v->NbTL;
    combine(v->ST,vm->ST); vm->NbST += v->NbST;
    combine(v->VT,vm->VT); vm->NbVT += v->NbVT;
    combine(v->TT,vm->TT); vm->NbTT += v->NbTT;
    combine(v->SQ,vm->SQ); vm->NbSQ += v->NbSQ;
    combine(v->VQ,vm->VQ); vm->NbVQ += v->NbVQ;
    combine(v->TQ,vm->TQ); vm->NbTQ += v->NbTQ;
    combine(v->SS,vm->SS); vm->NbSS += v->NbSS;
    combine(v->VS,vm->VS); vm->NbVS += v->NbVS;
    combine(v->TS,vm->TS); vm->NbTS += v->NbTS;
    combine(v->SH,vm->SH); vm->NbSH += v->NbSH;
    combine(v->VH,vm->VH); vm->NbVH += v->NbVH;
    combine(v->TH,vm->TH); vm->NbTH += v->NbTH;
    combine(v->SI,vm->SI); vm->NbSI += v->NbSI;
    combine(v->VI,vm->VI); vm->NbVI += v->NbVI;
    combine(v->TI,vm->TI); vm->NbTI += v->NbTI;
    combine(v->SY,vm->SY); vm->NbSY += v->NbSY;
    combine(v->VY,vm->VY); vm->NbVY += v->NbVY;
    combine(v->TY,vm->TY); vm->NbTY += v->NbTY;
    combine_strings(v,vm);
  }

#if 0
  // debug strings:
  for(int i=0; i<List_Nbr(vm->T2D); i++)
    printf("%g ", *(double*)List_Pointer(vm->T2D, i));
  printf("\n");
  for(int i=0; i<List_Nbr(vm->T2C); i++)
    printf("%c ", *(char*)List_Pointer(vm->T2C, i));
  printf("\n");
#endif

  // finalize
  char name[256], filename[256], tmp[256];
  if(!strcmp(id->name, "__all__"))
    strcpy(tmp, "all");
  else if(!strcmp(id->name, "__vis__"))
    strcpy(tmp, "visible");
  else
    strcpy(tmp, id->name);
  sprintf(name, "%s_Combine", tmp);
  sprintf(filename, "%s_Combine.pos", tmp);
  EndView(vm, 0, filename, name);
}

static void combine_time(struct nameidx *id, List_T *to_remove)
{
  int index, *nbe=0, *nbe2=0, nbn, nbn2, nbc, nbc2;
  List_T *list=0, *list2=0;
  
  if(List_Nbr(id->indices) < 2){
    return; // nothing to do
  }

  Post_View *vm = BeginView(1);

  // use the first view as the reference
  List_Read(id->indices, 0, &index);
  Post_View *v = *(Post_View **)List_Pointer(CTX.post.list, index);
  for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
    vm->get_raw_data(i, &list, &nbe, &nbc, &nbn);
    v->get_raw_data(i, &list2, &nbe2, &nbc2, &nbn2);
    *nbe = *nbe2;
  }
  vm->NbT2 = v->NbT2;
  vm->NbT3 = v->NbT3;

  // merge values for all element types
  for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
    vm->get_raw_data(i, &list, &nbe, &nbc, &nbn);
    for(int j = 0; j < *nbe; j++){
      for(int k = 0; k < List_Nbr(id->indices); k++){
	List_Read(id->indices, k, &index);
	v = *(Post_View **)List_Pointer(CTX.post.list, index);
	v->get_raw_data(i, &list2, &nbe2, &nbc2, &nbn2);
	if(*nbe && *nbe == *nbe2){
	  List_Insert(to_remove, &v->Num, fcmp_int);
	  int nb2 = List_Nbr(list2) / *nbe2;
	  if(!k){ 
	    // copy coordinates of elm j (we are always here as
	    // expected, since the ref view is the first one!)
	    for(int l = 0; l < 3*nbn2; l++){
	      List_Add(list, List_Pointer(list2, j*nb2+l));
	    }
	  }
	  // copy values of elm j
	  for(int l = 0; l < v->NbTimeStep*nbc2*nbn2; l++){
	    List_Add(list, List_Pointer(list2, j*nb2+3*nbn2+l));
	  }
	}
      }
    }
  }

  // and a bit of spaghetti code for you now:

  // merge 2d strings
  for(int j = 0; j < vm->NbT2; j++){
    for(int k = 0; k < List_Nbr(id->indices); k++){
      List_Read(id->indices, k, &index);
      v = *(Post_View **)List_Pointer(CTX.post.list, index);
      if(vm->NbT2 == v->NbT2){
	List_Insert(to_remove, &v->Num, fcmp_int);
	if(!k){
	  // copy coordinates 
	  List_Add(vm->T2D, List_Pointer(v->T2D, j*4));
	  List_Add(vm->T2D, List_Pointer(v->T2D, j*4+1));
	  List_Add(vm->T2D, List_Pointer(v->T2D, j*4+2));
	  // index
	  double d = List_Nbr(vm->T2C);
	  List_Add(vm->T2D, &d);
	}
	// copy char values
	double beg, end;
	List_Read(v->T2D, j*4+3, &beg);
	if(j == vm->NbT2 - 1)
	  end = (double)List_Nbr(v->T2C);
	else
	  List_Read(v->T2D, j*4+4+3, &end);
	char *c = (char*)List_Pointer(v->T2C, (int)beg);
	for(int l = 0; l < (int)(end-beg); l++)
	  List_Add(vm->T2C, &c[l]);
      }
    }
  }

  // merge 3d strings
  for(int j = 0; j < vm->NbT3; j++){
    for(int k = 0; k < List_Nbr(id->indices); k++){
      List_Read(id->indices, k, &index);
      v = *(Post_View **)List_Pointer(CTX.post.list, index);
      if(vm->NbT3 == v->NbT3){
	List_Insert(to_remove, &v->Num, fcmp_int);
	if(!k){
	  // copy coordinates 
	  List_Add(vm->T3D, List_Pointer(v->T3D, j*5));
	  List_Add(vm->T3D, List_Pointer(v->T3D, j*5+1));
	  List_Add(vm->T3D, List_Pointer(v->T3D, j*5+2));
	  List_Add(vm->T3D, List_Pointer(v->T3D, j*5+3));
	  // index
	  double d = List_Nbr(vm->T3C);
	  List_Add(vm->T3D, &d);
	}
	// copy char values
	double beg, end;
	List_Read(v->T3D, j*5+4, &beg);
	if(j == vm->NbT3 - 1)
	  end = (double)List_Nbr(v->T3C);
	else
	  List_Read(v->T3D, j*5+5+4, &end);
	char *c = (char*)List_Pointer(v->T3C, (int)beg);
	for(int l = 0; l < (int)(end-beg); l++)
	  List_Add(vm->T3C, &c[l]);
      }
    }
  }

  // create the time data
  for(int i = 0; i < List_Nbr(id->indices); i++){
    List_Read(id->indices, i, &index);
    v = *(Post_View **)List_Pointer(CTX.post.list, index);
    for(int j = 0; j < List_Nbr(v->Time); j++){
      List_Add(vm->Time, List_Pointer(v->Time, j));
    }
  }

  // if all the time values are the same, it probably means that the
  // original views didn't have any time data: let's put some indices,
  // then
  double time0 = 0.0;
  if(List_Nbr(vm->Time)) List_Read(vm->Time, 0, &time0);
  int nbtime = List_Nbr(vm->Time), ok = 0;
  for(int i = 1; i < nbtime; i++){
    if(time0 != *(double*)List_Pointer(vm->Time, i)){
      ok = 1;
      break;
    }
  }
  if(!ok){
    List_Reset(vm->Time);
    for(int i = 0; i < nbtime; i++){
      double time = i;
      List_Add(vm->Time, &time);
    }
  }

  // finalize
  char name[256], filename[256], tmp[256];
  if(!strcmp(id->name, "__all__"))
    strcpy(tmp, "all");
  else if(!strcmp(id->name, "__vis__"))
    strcpy(tmp, "visible");
  else
    strcpy(tmp, id->name);
  sprintf(name, "%s_Combine", tmp);
  sprintf(filename, "%s_Combine.pos", tmp);
  EndView(vm, 0, filename, name);
}

void CombineViews(int time, int how, int remove)
{
  // time==0: combine the elements
  // time==1: combine the timesteps

  // how==0: try to combine all visible views
  // how==1: try to combine all views
  // how==2: try to combine all views having identical names

  List_T *ids = List_Create(10, 10, sizeof(nameidx));
  List_T *to_remove = List_Create(10, 10, sizeof(int));
  struct nameidx *pid;

  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    if(how || v->Visible) {
      nameidx id;
      // this might potentially lead to unwanted results if there are
      // views named "__all__" or "__vis__", but what the heck...
      if(how == 2)
	strcpy(id.name, v->Name);
      else if(how == 1)
	strcpy(id.name, "__all__");
      else
	strcpy(id.name, "__vis__");
      if((pid = (struct nameidx*)List_PQuery(ids, &id, fcmp_name))){
	List_Add(pid->indices, &i);
      }
      else{
	id.indices = List_Create(10, 10, sizeof(int));
	List_Add(id.indices, &i);
	List_Add(ids, &id);
      }
    }
  }

  for(int i = 0; i < List_Nbr(ids); i++){
    pid = (struct nameidx*)List_Pointer(ids, i);
    if(time)
      combine_time(pid, to_remove);
    else
      combine_space(pid, to_remove);
    List_Delete(pid->indices);
  }
  List_Delete(ids);

  // remove original view?
  if(remove){
    for(int i = 0; i < List_Nbr(to_remove); i++){
      int num;
      List_Read(to_remove, i, &num);
      RemoveViewByNumber(num);
    }
  }
  List_Delete(to_remove);

#if defined(HAVE_FLTK)
  UpdateViewsInGUI();
#endif
}

// generic access functions

int Post_View::empty(){
  if(NbSP || NbVP || NbTP ||
     NbSL || NbVL || NbTL ||
     NbST || NbVT || NbTT ||
     NbSQ || NbVQ || NbTQ ||
     NbSS || NbVS || NbTS ||
     NbSH || NbVH || NbTH ||
     NbSI || NbVI || NbTI ||
     NbSY || NbVY || NbTY ||
     NbT2 || NbT3)
    return 0;
  else
    return 1;
}

void Post_View::get_raw_data(int type, List_T **list, int **nbe, int *nbc, int *nbn){
  switch(type){
  case 0 : *list = SP; *nbe = &NbSP; *nbc = 1; *nbn = 1; break;
  case 1 : *list = VP; *nbe = &NbVP; *nbc = 3; *nbn = 1; break;
  case 2 : *list = TP; *nbe = &NbTP; *nbc = 9; *nbn = 1; break;
  case 3 : *list = SL; *nbe = &NbSL; *nbc = 1; *nbn = 2; break;
  case 4 : *list = VL; *nbe = &NbVL; *nbc = 3; *nbn = 2; break;
  case 5 : *list = TL; *nbe = &NbTL; *nbc = 9; *nbn = 2; break;
  case 6 : *list = ST; *nbe = &NbST; *nbc = 1; *nbn = 3; break;
  case 7 : *list = VT; *nbe = &NbVT; *nbc = 3; *nbn = 3; break;
  case 8 : *list = TT; *nbe = &NbTT; *nbc = 9; *nbn = 3; break;
  case 9 : *list = SQ; *nbe = &NbSQ; *nbc = 1; *nbn = 4; break;
  case 10: *list = VQ; *nbe = &NbVQ; *nbc = 3; *nbn = 4; break;
  case 11: *list = TQ; *nbe = &NbTQ; *nbc = 9; *nbn = 4; break;
  case 12: *list = SS; *nbe = &NbSS; *nbc = 1; *nbn = 4; break;
  case 13: *list = VS; *nbe = &NbVS; *nbc = 3; *nbn = 4; break;
  case 14: *list = TS; *nbe = &NbTS; *nbc = 9; *nbn = 4; break;
  case 15: *list = SH; *nbe = &NbSH; *nbc = 1; *nbn = 8; break;
  case 16: *list = VH; *nbe = &NbVH; *nbc = 3; *nbn = 8; break;
  case 17: *list = TH; *nbe = &NbTH; *nbc = 9; *nbn = 8; break;
  case 18: *list = SI; *nbe = &NbSI; *nbc = 1; *nbn = 6; break;
  case 19: *list = VI; *nbe = &NbVI; *nbc = 3; *nbn = 6; break;
  case 20: *list = TI; *nbe = &NbTI; *nbc = 9; *nbn = 6; break;
  case 21: *list = SY; *nbe = &NbSY; *nbc = 1; *nbn = 5; break;
  case 22: *list = VY; *nbe = &NbVY; *nbc = 3; *nbn = 5; break;
  case 23: *list = TY; *nbe = &NbTY; *nbc = 9; *nbn = 5; break;
  default: Msg(GERROR, "Wrong type in Post_View::get_raw_data"); break;
  }
}

// Generalized raise

void InitGeneralizedRaise(Post_View *v)
{
  FreeGeneralizedRaise(v);

  char *expr[3] = { v->GenRaiseX, v->GenRaiseY, v->GenRaiseZ };
#if defined(HAVE_MATH_EVAL)
  for(int i = 0; i < 3; i++) {
    if(strlen(expr[i])) {
      if(!(v->GenRaise_f[i] = evaluator_create(expr[i])))
        Msg(GERROR, "Invalid expression '%s'", expr[i]);
    }
  }
#else
  for(int i = 0; i < 3; i++) {
    if(!strcmp(expr[i], "v0")) v->GenRaise_f[i] = (void*)0;
    else if(!strcmp(expr[i], "v1")) v->GenRaise_f[i] = (void*)1;
    else if(!strcmp(expr[i], "v2")) v->GenRaise_f[i] = (void*)2;
    else if(!strcmp(expr[i], "v3")) v->GenRaise_f[i] = (void*)3;
    else if(!strcmp(expr[i], "v4")) v->GenRaise_f[i] = (void*)4;
    else if(!strcmp(expr[i], "v5")) v->GenRaise_f[i] = (void*)5;
    else if(!strcmp(expr[i], "v6")) v->GenRaise_f[i] = (void*)6;
    else if(!strcmp(expr[i], "v7")) v->GenRaise_f[i] = (void*)7;
    else if(!strcmp(expr[i], "v8")) v->GenRaise_f[i] = (void*)8;
    else if(strlen(expr[i])) {
      Msg(GERROR, "Invalid expression '%s'", expr[i]);
      return;
    }
  }
#endif
}

void FreeGeneralizedRaise(Post_View *v)
{
  for(int i = 0; i < 3; i++){
#if defined(HAVE_MATH_EVAL)
    if(v->GenRaise_f[i])
      evaluator_destroy(v->GenRaise_f[i]);
    v->GenRaise_f[i] = NULL;
#else
    v->GenRaise_f[i] = (void*)-1;
#endif
  }
}

void ApplyGeneralizedRaise(Post_View * v, int numNodes, int numComp, double *vals,
			   double *x, double *y, double *z)
{
  double *coords[3] = { x, y, z };

  for(int k = 0; k < numNodes; k++) {
    double d[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
    for(int l = 0; l < numComp; l++)
      d[l] = vals[numComp * k + l];
#if defined(HAVE_MATH_EVAL)
    char *names[] = { "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8" ,
		      "x", "y", "z" };
    double values[] = { d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8],
			x[k], y[k], z[k] };
    for(int i = 0; i < 3; i++) {
      if(v->GenRaise_f[i])
        coords[i][k] += 
	  evaluator_evaluate(v->GenRaise_f[i], sizeof(names) / 
			     sizeof(names[0]), names, values) * v->GenRaiseFactor;
    }
#else
    for(int i = 0; i < 3; i++){
      int comp = (int)v->GenRaise_f[i];
      if(comp >= 0)
	coords[i][k] += d[comp] * v->GenRaiseFactor;
    }
#endif
  }
}
