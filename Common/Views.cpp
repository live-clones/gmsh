// $Id: Views.cpp,v 1.72 2002-06-15 21:25:27 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include <set>
#include "Gmsh.h"
#include "Numeric.h"
#include "Views.h"
#include "Context.h"
#include "Options.h"
#include "ColorTable.h"

extern Context_T   CTX ;

#define INFINITY 1.e200

// Static reference view

Post_View  *Post_ViewReference = NULL;

// FIXME: the whole View interface should be rewritten in C++...

int fcmpPostViewNum(const void *v1, const void *v2){
  return (((Post_View *)v1)->Num - ((Post_View *)v2)->Num);
}

int fcmpPostViewDuplicateOf(const void *v1, const void *v2){
  return (((Post_View *)v1)->DuplicateOf - ((Post_View *)v2)->DuplicateOf);
}

Post_View * BeginView(int allocate){
  Post_View vv, *v;
  static int  UniqueNum=0;
  int i;

  if(!CTX.post.list) CTX.post.list = List_Create(100,1,sizeof(Post_View));

  if(!CTX.post.force_num){
    vv.Num = ++UniqueNum; // each view _must_ have a unique number
    List_Add(CTX.post.list, &vv);
  }
  else{
    vv.Num = CTX.post.force_num;    
    List_Replace(CTX.post.list,&vv,fcmpPostViewNum);
  }

  i = List_ISearch(CTX.post.list, &vv, fcmpPostViewNum);
  v = (Post_View*)List_Pointer(CTX.post.list, i);

  v->Index = i;
  v->Dirty = 1;
  v->DisplayListNum = -1;
  v->NbTimeStep = 0;
  v->NbSP = v->NbVP = v->NbTP = 0;
  v->NbSL = v->NbVL = v->NbTL = 0;
  v->NbST = v->NbVT = v->NbTT = 0;
  v->NbSS = v->NbVS = v->NbTS = 0;
  v->NbT2 = v->NbT3 = 0;

  if(allocate){
    v->datasize = sizeof(double);

    v->Time = List_Create(100,1000,sizeof(double));

    v->SP = List_Create(100,1000,sizeof(double));
    v->VP = List_Create(100,1000,sizeof(double));
    v->TP = List_Create(100,1000,sizeof(double));
    
    v->SL = List_Create(100,1000,sizeof(double));
    v->VL = List_Create(100,1000,sizeof(double));
    v->TL = List_Create(100,1000,sizeof(double));
    
    v->ST = List_Create(100,1000,sizeof(double));
    v->VT = List_Create(100,1000,sizeof(double));
    v->TT = List_Create(100,1000,sizeof(double));
    
    v->SS = List_Create(100,1000,sizeof(double));
    v->VS = List_Create(100,1000,sizeof(double));
    v->TS = List_Create(100,1000,sizeof(double));

    v->T2D = List_Create(10,100,sizeof(double));
    v->T2C = List_Create(100,1000,sizeof(char));
    v->T3D = List_Create(10,100,sizeof(double));
    v->T3C = List_Create(100,1000,sizeof(char));
  }
  else{
    v->Time = NULL;
    v->SP = NULL; v->VP = NULL; v->TP = NULL;
    v->SL = NULL; v->VL = NULL; v->TL = NULL;
    v->ST = NULL; v->VT = NULL; v->TT = NULL;
    v->SS = NULL; v->VS = NULL; v->TS = NULL;
    v->T2D = NULL; v->T2C = NULL;
    v->T3D = NULL; v->T3C = NULL;
  }

  // Copy all options from the reference view initialized in InitOptions()
  CopyViewOptions(Post_ViewReference, v);

  v->Changed = 1;
  v->Links = 0;
  v->DuplicateOf = 0;
  v->ScalarOnly = 1;
  v->TextOnly = 1;
  v->normals = NULL;
  v->Min = INFINITY;
  v->Max = -INFINITY;
  for(i=0;i<3;i++){
    v->BBox[2*i] = INFINITY;
    v->BBox[2*i+1] = -INFINITY;
  }

  return v;
}

void Stat_ScalarSimplex(Post_View *v, int nbnod, int N, 
			double *X, double *Y, double *Z, double *V){
  int i;

  if(v->Min == INFINITY || v->Max == -INFINITY){
    v->Min = V[0];
    v->Max = V[0];
    v->NbTimeStep = N/nbnod;
  }
  else if(N/nbnod < v->NbTimeStep)
    v->NbTimeStep = N/nbnod ;

  for(i=0 ; i<N ; i++){
    if(V[i] < v->Min) v->Min = V[i] ;
    if(V[i] > v->Max) v->Max = V[i] ;
  }

  for(i=0 ; i<nbnod ; i++){
    if(X[i] < v->BBox[0]) v->BBox[0] = X[i] ;
    if(X[i] > v->BBox[1]) v->BBox[1] = X[i] ;
    if(Y[i] < v->BBox[2]) v->BBox[2] = Y[i] ;
    if(Y[i] > v->BBox[3]) v->BBox[3] = Y[i] ;
    if(Z[i] < v->BBox[4]) v->BBox[4] = Z[i] ;
    if(Z[i] > v->BBox[5]) v->BBox[5] = Z[i] ;
  }

  v->TextOnly = 0;
}

void Stat_VectorSimplex(Post_View *v, int nbnod, int N, 
			double *X, double *Y, double *Z, double *V){
  double l0;
  int i;

  if(v->Min == INFINITY || v->Max == -INFINITY){
    l0 = sqrt(DSQR(V[0])+DSQR(V[1])+DSQR(V[2]));
    v->Min = l0;
    v->Max = l0;
    v->NbTimeStep = N/(3*nbnod) ;
  }
  else if(N/(3*nbnod) < v->NbTimeStep)
    v->NbTimeStep = N/(3*nbnod) ;

  for(i=0 ; i<N ; i+=3){
    l0 = sqrt(DSQR(V[i])+DSQR(V[i+1])+DSQR(V[i+2]));
    if(l0 < v->Min) v->Min = l0 ;
    if(l0 > v->Max) v->Max = l0 ;
  }

  for(i=0 ; i<nbnod ; i++){
    if(X[i] < v->BBox[0]) v->BBox[0] = X[i] ;
    if(X[i] > v->BBox[1]) v->BBox[1] = X[i] ;
    if(Y[i] < v->BBox[2]) v->BBox[2] = Y[i] ;
    if(Y[i] > v->BBox[3]) v->BBox[3] = Y[i] ;
    if(Z[i] < v->BBox[4]) v->BBox[4] = Z[i] ;
    if(Z[i] > v->BBox[5]) v->BBox[5] = Z[i] ;
  }

  v->ScalarOnly = 0;
  v->TextOnly = 0;
}

void Stat_TensorSimplex(Post_View *v, int nbnod, int N, 
			double *X, double *Y, double *Z, double *V){
  double l0;
  int i;

  if(v->Min == INFINITY || v->Max == -INFINITY){
    l0 = sqrt(DSQR(V[0])+DSQR(V[1])+DSQR(V[2]));
    v->Min = l0;
    v->Max = l0;
    v->NbTimeStep = N/(3*nbnod) ;
  }
  else if(N/(3*nbnod) < v->NbTimeStep)
    v->NbTimeStep = N/(3*nbnod) ;

  for(i=0 ; i<N ; i+=3){
    l0 = sqrt(DSQR(V[i])+DSQR(V[i+1])+DSQR(V[i+2]));
    if(l0 < v->Min) v->Min = l0 ;
    if(l0 > v->Max) v->Max = l0 ;
  }

  for(i=0 ; i<nbnod ; i++){
    if(X[i] < v->BBox[0]) v->BBox[0] = X[i] ;
    if(X[i] > v->BBox[1]) v->BBox[1] = X[i] ;
    if(Y[i] < v->BBox[2]) v->BBox[2] = Y[i] ;
    if(Y[i] > v->BBox[3]) v->BBox[3] = Y[i] ;
    if(Z[i] < v->BBox[4]) v->BBox[4] = Z[i] ;
    if(Z[i] > v->BBox[5]) v->BBox[5] = Z[i] ;
  }

  v->ScalarOnly = 0;
  v->TextOnly = 0;
}


void EndView(Post_View *v, int add_in_gui, char *file_name, char *name){
  int i, nb;
  double d;

  // Points

  if(v->NbSP){
    nb = List_Nbr(v->SP) / v->NbSP ;
    for(i = 0 ; i < List_Nbr(v->SP) ; i+=nb)
      Stat_ScalarSimplex(v, 1, nb-3, 
			 (double*)List_Pointer_Fast(v->SP,i),
			 (double*)List_Pointer_Fast(v->SP,i+1),
			 (double*)List_Pointer_Fast(v->SP,i+2),
			 (double*)List_Pointer_Fast(v->SP,i+3));
  }
  if(v->NbVP){
    nb = List_Nbr(v->VP) / v->NbVP ;
    for(i = 0 ; i < List_Nbr(v->VP) ; i+=nb)
      Stat_VectorSimplex(v, 1, nb-3, 
			 (double*)List_Pointer_Fast(v->VP,i),
			 (double*)List_Pointer_Fast(v->VP,i+1),
			 (double*)List_Pointer_Fast(v->VP,i+2),
			 (double*)List_Pointer_Fast(v->VP,i+3));
  }
  if(v->NbTP){
    nb = List_Nbr(v->TP) / v->NbTP ;
    for(i = 0 ; i < List_Nbr(v->TP) ; i+=nb)
      Stat_TensorSimplex(v, 1, nb-3, 
			 (double*)List_Pointer_Fast(v->TP,i),
			 (double*)List_Pointer_Fast(v->TP,i+1),
			 (double*)List_Pointer_Fast(v->TP,i+2),
			 (double*)List_Pointer_Fast(v->TP,i+3));
  }

  // Lines

  if(v->NbSL){
    nb = List_Nbr(v->SL) / v->NbSL ;
    for(i = 0 ; i < List_Nbr(v->SL) ; i+=nb)
      Stat_ScalarSimplex(v, 2, nb-6,
			 (double*)List_Pointer_Fast(v->SL,i),
			 (double*)List_Pointer_Fast(v->SL,i+2),
			 (double*)List_Pointer_Fast(v->SL,i+4),
			 (double*)List_Pointer_Fast(v->SL,i+6));
  }
  if(v->NbVL){
    nb = List_Nbr(v->VL) / v->NbVL ;
    for(i = 0 ; i < List_Nbr(v->VL) ; i+=nb)
      Stat_VectorSimplex(v, 2, nb-6, 
			 (double*)List_Pointer_Fast(v->VL,i),
			 (double*)List_Pointer_Fast(v->VL,i+2),
			 (double*)List_Pointer_Fast(v->VL,i+4),
			 (double*)List_Pointer_Fast(v->VL,i+6));
  }
  if(v->NbTL){
    nb = List_Nbr(v->TL) / v->NbTL ;
    for(i = 0 ; i < List_Nbr(v->TL) ; i+=nb)
      Stat_TensorSimplex(v, 2, nb-6, 
			 (double*)List_Pointer_Fast(v->TL,i),
			 (double*)List_Pointer_Fast(v->TL,i+2),
			 (double*)List_Pointer_Fast(v->TL,i+4),
			 (double*)List_Pointer_Fast(v->TL,i+6));
  }

  // Triangles

  if(v->NbST){
    nb = List_Nbr(v->ST) / v->NbST ;
    for(i = 0 ; i < List_Nbr(v->ST) ; i+=nb)
      Stat_ScalarSimplex(v, 3, nb-9, 
			 (double*)List_Pointer_Fast(v->ST,i),
			 (double*)List_Pointer_Fast(v->ST,i+3),
			 (double*)List_Pointer_Fast(v->ST,i+6),
			 (double*)List_Pointer_Fast(v->ST,i+9));
  }
  if(v->NbVT){
    nb = List_Nbr(v->VT) / v->NbVT ;
    for(i = 0 ; i < List_Nbr(v->VT) ; i+=nb)
      Stat_VectorSimplex(v, 3, nb-9, 
			 (double*)List_Pointer_Fast(v->VT,i),
			 (double*)List_Pointer_Fast(v->VT,i+3),
			 (double*)List_Pointer_Fast(v->VT,i+6),
			 (double*)List_Pointer_Fast(v->VT,i+9));
  }
  if(v->NbTT){
    nb = List_Nbr(v->TT) / v->NbTT ;
    for(i = 0 ; i < List_Nbr(v->TT) ; i+=nb)
      Stat_TensorSimplex(v, 3, nb-9,
			 (double*)List_Pointer_Fast(v->TT,i),
			 (double*)List_Pointer_Fast(v->TT,i+3),
			 (double*)List_Pointer_Fast(v->TT,i+6),
			 (double*)List_Pointer_Fast(v->TT,i+9));
  }

  // Tetrahedra

  if(v->NbSS){
    nb = List_Nbr(v->SS) / v->NbSS ;
    for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb)
      Stat_ScalarSimplex(v, 4, nb-12, 
			 (double*)List_Pointer_Fast(v->SS,i),
			 (double*)List_Pointer_Fast(v->SS,i+4),
			 (double*)List_Pointer_Fast(v->SS,i+8),
			 (double*)List_Pointer_Fast(v->SS,i+12));
  }
  if(v->NbVS){
    nb = List_Nbr(v->VS) / v->NbVS ;
    for(i = 0 ; i < List_Nbr(v->VS) ; i+=nb)
      Stat_VectorSimplex(v, 4, nb-12,
			 (double*)List_Pointer_Fast(v->VS,i),
			 (double*)List_Pointer_Fast(v->VS,i+4),
			 (double*)List_Pointer_Fast(v->VS,i+8),
			 (double*)List_Pointer_Fast(v->VS,i+12));
  }
  if(v->NbTS){
    nb = List_Nbr(v->TS) / v->NbTS ;
    for(i = 0 ; i < List_Nbr(v->TS) ; i+=nb)
      Stat_TensorSimplex(v, 4, nb-12, 
			 (double*)List_Pointer_Fast(v->TS,i),
			 (double*)List_Pointer_Fast(v->TS,i+4),
			 (double*)List_Pointer_Fast(v->TS,i+8),
			 (double*)List_Pointer_Fast(v->TS,i+12));
  }

  // Dummy time values if using old parsed format
  if(v->Time && !List_Nbr(v->Time)){
    for(i=0 ; i<v->NbTimeStep ; i++){
      d = (double)i;
      List_Add(v->Time, &d);
    }
  }

  opt_view_name(v->Index, GMSH_SET|GMSH_GUI, name);
  opt_view_filename(v->Index, GMSH_SET|GMSH_GUI, file_name);
  opt_view_nb_timestep(v->Index, GMSH_GUI, 0);
  opt_view_timestep(v->Index, GMSH_SET|GMSH_GUI, v->TimeStep);
  if(v->Min > v->Max){
    opt_view_min(v->Index, GMSH_SET|GMSH_GUI, 0.);
    opt_view_max(v->Index, GMSH_SET|GMSH_GUI, 0.);
  }
  else{
    opt_view_min(v->Index, GMSH_GUI, 0);
    opt_view_max(v->Index, GMSH_GUI, 0);
  }
  opt_view_custom_min(v->Index, GMSH_SET|GMSH_GUI, v->Min);
  opt_view_custom_max(v->Index, GMSH_SET|GMSH_GUI, v->Max);

  if(CTX.post.smooth) v->smooth();

#ifndef _BLACKBOX
  extern int AddViewInUI(int, char *, int);
  if(!CTX.post.force_num && add_in_gui)
    AddViewInUI(List_Nbr(CTX.post.list), v->Name, v->Num);
#endif

  v->Dirty = 0; //the view is complete, we may draw it
}

bool FreeView(int num){
  Post_View *v;

  Msg(DEBUG, "Trying to free view %d",num);
  
  if(num < 0 || num >= List_Nbr(CTX.post.list)){
    return false ;
  }
  v = (Post_View*)List_Pointer(CTX.post.list, num);
  FreeView(v);
  List_PSuppress(CTX.post.list, num);

  Msg(INFO, "View %d deleted (%d views left)",num, List_Nbr(CTX.post.list));
  return true;
}


void FreeView(Post_View *v){
  Post_View vv,*v2;
  int i, numdup, free = 1;

  if(v->DuplicateOf){
    vv.Num = v->DuplicateOf ;
    Msg(DEBUG, "This view is a duplicata");
    if(!(v2 = (Post_View*)List_PQuery(CTX.post.list, &vv, fcmpPostViewNum))){
      Msg(DEBUG, "  -the original view is gone");
      numdup = 0;
      for(i=0 ; i<List_Nbr(CTX.post.list); i++)
	numdup += (((Post_View*)List_Pointer(CTX.post.list, i))->DuplicateOf == v->DuplicateOf);
      if(numdup == 1){
        Msg(DEBUG, "  -there are no other duplicata, so I can free");
        free = 1 ;
      }
      else{
        Msg(DEBUG, "  -there are still duplicata, so I cannot free");
        free = 0 ;
      }
    }
    else{
      v2->Links--;
      free = 0 ;
      Msg(DEBUG, "  -the original still exists, so I cannot free");
    }
  }

  if(free && !v->Links){
    Msg(DEBUG, "FREEING VIEW");
    List_Delete(v->Time);
    List_Delete(v->SP); List_Delete(v->VP); List_Delete(v->TP);
    List_Delete(v->SL); List_Delete(v->VL); List_Delete(v->TL);
    List_Delete(v->ST); List_Delete(v->VT); List_Delete(v->TT);
    List_Delete(v->SS); List_Delete(v->VS); List_Delete(v->TS);
    List_Delete(v->T2D); List_Delete(v->T2C);
    List_Delete(v->T3D); List_Delete(v->T3C);
    //set to NULL in case we don't free v (e.g. when doing a 'reload')
    //+ the reload does not work (e.g. the file is gone). This way,
    //the next Free stuff will still work gracefully.
    v->Time = NULL;
    v->SP = v->VP = v->TP = NULL;
    v->SL = v->VL = v->TL = NULL;
    v->ST = v->VT = v->TT = NULL;
    v->SS = v->VS = v->TS = NULL;
    v->T2D = v->T2C = NULL;
    v->T3D = v->T3C = NULL;
    v->reset_normals();
  }

}

void CopyViewOptions(Post_View *src, Post_View *dest){
  dest->Type = src->Type;
  dest->Position[0] = src->Position[0];
  dest->Position[1] = src->Position[1];
  dest->AutoPosition = src->AutoPosition;
  dest->Size[0] = src->Size[0];
  dest->Size[1] = src->Size[1];
  strcpy(dest->Format, src->Format);
  strcpy(dest->AbscissaName, src->AbscissaName);
  dest->CustomMin = src->CustomMin;
  dest->CustomMax = src->CustomMax;
  dest->Offset[0] = src->Offset[0];
  dest->Offset[1] = src->Offset[1];
  dest->Offset[2] = src->Offset[2];
  dest->Raise[0] = src->Raise[0];
  dest->Raise[1] = src->Raise[1];
  dest->Raise[2] = src->Raise[2];
  dest->ArrowScale = src->ArrowScale;
  dest->Explode = src->Explode;
  dest->Visible = src->Visible;
  dest->IntervalsType = src->IntervalsType;
  dest->SaturateValues = src->SaturateValues;
  dest->Boundary = src->Boundary ;
  dest->NbAbscissa = src->NbAbscissa;
  dest->NbIso = src->NbIso;
  dest->Light = src->Light ;
  dest->SmoothNormals = src->SmoothNormals ;
  dest->AngleSmoothNormals = src->AngleSmoothNormals ;
  dest->ShowElement = src->ShowElement;
  dest->ShowTime = src->ShowTime;
  dest->ShowScale = src->ShowScale;
  dest->DrawPoints = src->DrawPoints;
  dest->DrawLines = src->DrawLines;
  dest->DrawTriangles = src->DrawTriangles;
  dest->DrawTetrahedra = src->DrawTetrahedra;
  dest->DrawScalars = src->DrawScalars;
  dest->DrawVectors = src->DrawVectors;
  dest->DrawTensors = src->DrawTensors;
  dest->DrawStrings = src->DrawStrings;
  dest->TransparentScale = src->TransparentScale;
  dest->ScaleType = src->ScaleType;
  dest->RangeType = src->RangeType;
  dest->ArrowType = src->ArrowType;
  dest->ArrowLocation = src->ArrowLocation;
  dest->TensorType = src->TensorType;
  dest->TimeStep = src->TimeStep;
  dest->PointSize = src->PointSize;
  dest->LineWidth = src->LineWidth;
  dest->PointType = src->PointType;
  dest->Grid = src->Grid;
  ColorTable_Copy(&src->CT);
  ColorTable_Paste(&dest->CT);
}

GmshColorTable *Get_ColorTable(int num){
  Post_View *v;

  if(!CTX.post.list)
    v = Post_ViewReference ;
  else
    v = (Post_View*)List_Pointer_Test(CTX.post.list, num);
  if(v)
    return &v->CT ;
  else
    return NULL ;
}

void Print_ColorTable(int num, char *prefix, FILE *file){
  char tmp[1024];
  Post_View *v;
  if(!CTX.post.list)
    v = Post_ViewReference ;
  else
    v = (Post_View*)List_Pointer_Test(CTX.post.list, num);
  if(!v) return;
  sprintf(tmp, "%s = {", prefix);
  if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
  ColorTable_Print(&v->CT, file);
  sprintf(tmp, "};");
  if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
}

Post_View *Create2DGraph(char *xname, char *yname, 
			 int nbdata, double *x, double *y){
  int i;
  double d=0.;
  char filename[1024];
  Post_View *v;

  v = BeginView(1);
  for(i=0;i<nbdata;i++){
    List_Add(v->SP, &x[i]);
    List_Add(v->SP, &d);
    List_Add(v->SP, &d);
    List_Add(v->SP, &y[i]);
    v->NbSP++;
  }
  sprintf(filename,"%s.pos",yname);
  EndView(v, 1, filename, yname);
  v->Type = DRAW_POST_2D_SPACE;
  strcpy(v->AbscissaName, xname);
  return v;
}

// INput/output

void Read_View(FILE *file, char *filename){
  char   str[256], name[256];
  int    i, nb, format, size, testone, swap, t2l, t3l;
  double version;
  Post_View *v;

  while (1) {

    do { 
      fgets(str, 256, file) ; 
      if (feof(file))  break ;
    } while (str[0] != '$') ;  

    if (feof(file))  break ;

    /*  F o r m a t  */

    if (!strncmp(&str[1], "PostFormat", 10)){
      fscanf(file, "%lf %d %d\n", &version, &format, &size) ;
      if(version < 1.0){
        Msg(GERROR, "The version of this post-processing file is too old (%g < 1.0)", version);
        return;
      }
      if(size == sizeof(double))
	Msg(DEBUG, "Data is in double precision format (size==%d)", size);
      else if(size == sizeof(float))
	Msg(DEBUG, "Data is in single precision format (size==%d)", size);
      else{
        Msg(GERROR, "Unknown type of data (size = %d) in post-processing file", 
	    size);
        return;
      }
      if(format == 0)
	format = LIST_FORMAT_ASCII ;
      else if(format == 1)
	format = LIST_FORMAT_BINARY ;
      else{
	Msg(GERROR, "Unknown format for view");
	return ;
      }
    }

    /*  V i e w  */

    if (!strncmp(&str[1], "View", 4)) {

      v = BeginView(0);

      if(version >= 1.1){
	fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
	       name, &v->NbTimeStep,
	       &v->NbSP, &v->NbVP, &v->NbTP, 
	       &v->NbSL, &v->NbVL, &v->NbTL, 
	       &v->NbST, &v->NbVT, &v->NbTT, 
	       &v->NbSS, &v->NbVS, &v->NbTS,
	       &v->NbT2, &t2l, &v->NbT3, &t3l);
      }
      else{
	fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
	       name, &v->NbTimeStep,
	       &v->NbSP, &v->NbVP, &v->NbTP, 
	       &v->NbSL, &v->NbVL, &v->NbTL, 
	       &v->NbST, &v->NbVT, &v->NbTT, 
	       &v->NbSS, &v->NbVS, &v->NbTS);
	v->NbT2 = t2l = v->NbT3 = t3l = 0;
      }

      for(i=0;i<(int)strlen(name);i++) if(name[i]=='^') name[i]=' '; 

      swap = 0 ;
      if(format == LIST_FORMAT_BINARY){
	fread(&testone, sizeof(int), 1, file);
	if(testone != 1){
	  Msg(INFO, "Swapping bytes from binary file");
	  swap = 1;
	}
      }

      v->datasize = size ;

      // Time values
      v->Time = List_CreateFromFile(v->NbTimeStep, size, file, format, swap);

      // Points
      nb = v->NbSP ? v->NbSP * (v->NbTimeStep  +3) : 0 ;
      v->SP = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbVP ? v->NbVP * (v->NbTimeStep*3+3) : 0 ;
      v->VP = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbTP ? v->NbTP * (v->NbTimeStep*9+3) : 0 ;
      v->TP = List_CreateFromFile(nb, size, file, format, swap);

      // Lines
      nb = v->NbSL ? v->NbSL * (v->NbTimeStep*2  +6) : 0 ;
      v->SL = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbVL ? v->NbVL * (v->NbTimeStep*2*3+6) : 0 ;
      v->VL = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbTL ? v->NbTL * (v->NbTimeStep*2*9+6) : 0 ;
      v->TL = List_CreateFromFile(nb, size, file, format, swap);

      // Triangles
      nb = v->NbST ? v->NbST * (v->NbTimeStep*3  +9) : 0 ;
      v->ST = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbVT ? v->NbVT * (v->NbTimeStep*3*3+9) : 0 ;
      v->VT = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbTT ? v->NbTT * (v->NbTimeStep*3*9+9) : 0 ;
      v->TT = List_CreateFromFile(nb, size, file, format, swap);

      // Tetrahedra
      nb = v->NbSS ? v->NbSS * (v->NbTimeStep*4  +12) : 0 ;
      v->SS = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbVS ? v->NbVS * (v->NbTimeStep*4*3+12) : 0 ;
      v->VS = List_CreateFromFile(nb, size, file, format, swap);

      nb = v->NbTS ? v->NbTS * (v->NbTimeStep*4*9+12) : 0 ;
      v->TS = List_CreateFromFile(nb, size, file, format, swap);

      // Strings
      nb = v->NbT2 ? v->NbT2 * 4 : 0 ;
      v->T2D = List_CreateFromFile(nb, size, file, format, swap);
      v->T2C = List_CreateFromFile(t2l, sizeof(char), file, format, swap);      

      nb = v->NbT3 ? v->NbT3 * 5 : 0 ;
      v->T3D = List_CreateFromFile(nb, size, file, format, swap);
      v->T3C = List_CreateFromFile(t3l, sizeof(char), file, format, swap);      


      Msg(DEBUG, "Read View '%s' (%d TimeSteps): %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          name, v->NbTimeStep,
          v->NbSP, v->NbVP, v->NbTP, 
          v->NbSL, v->NbVL, v->NbTL, 
          v->NbST, v->NbVT, v->NbTT, 
          v->NbSS, v->NbVS, v->NbTS,
	  v->NbT2, v->NbT3);
      Msg(DEBUG, "List_Nbrs: "
	  "SP%d VP%d TP%d "
	  "SL%d VL%d TL%d "
	  "ST%d VT%d TT%d "
	  "SS%d VS%d TS%d "
	  "T2D%d T2C%d T3D%d T3C%d",
          List_Nbr(v->SP), List_Nbr(v->VP), List_Nbr(v->TP), 
          List_Nbr(v->SL), List_Nbr(v->VL), List_Nbr(v->TL), 
          List_Nbr(v->ST), List_Nbr(v->VT), List_Nbr(v->TT), 
          List_Nbr(v->SS), List_Nbr(v->VS), List_Nbr(v->TS),
	  List_Nbr(v->T2D), List_Nbr(v->T2C), List_Nbr(v->T3D), List_Nbr(v->T3C));

      EndView(v, 1, filename, name); 
    }

    do {
      fgets(str, 256, file) ;
      if (feof(file)) Msg(GERROR,"Prematured end of file");
    } while (str[0] != '$') ;

  }   /* while 1 ... */

}

// FIXME: add an integer per simplex (region num)
// FIXME: add a format similar to the msh format (node list + simplex list)
// FIXME: add a structured format

void Write_View(int Flag_BIN, Post_View *v, char *filename){
  FILE *file;
  char name[256];
  int i, f, One=1;

  if(filename){
    file = fopen(filename,"w");
    if(!file){
      Msg(GERROR, "Unable to open file '%s'", filename);
      return;
    }
  }
  else
    file = stdout;

  fprintf(file, "$PostFormat /* Gmsh 1.1, %s */\n", Flag_BIN ? "binary" : "ascii") ;
  fprintf(file, "1.1 %d %d\n", Flag_BIN, (int)sizeof(double)) ;
  fprintf(file, "$EndPostFormat\n") ;

  for(i=0;i<(int)strlen(v->Name);i++){
    if(v->Name[i]==' ') name[i]='^'; 
    else name[i]=v->Name[i];
  }
  name[i]='\0';

  fprintf(file, "$View /* %s */\n", v->Name);
  fprintf(file, "%s ", name);
  fprintf(file, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
	  List_Nbr(v->Time),
	  v->NbSP, v->NbVP, v->NbTP, v->NbSL, v->NbVL, v->NbTL, 
	  v->NbST, v->NbVT, v->NbTT, v->NbSS, v->NbVS, v->NbTS,
	  v->NbT2, List_Nbr(v->T2C), v->NbT3, List_Nbr(v->T3C));
  if(Flag_BIN){
    f = LIST_FORMAT_BINARY;
    fwrite(&One, sizeof(int), 1, file);
  }
  else
    f = LIST_FORMAT_ASCII;
  List_WriteToFile(v->Time, file, f); 
  List_WriteToFile(v->SP, file, f); List_WriteToFile(v->VP, file, f);
  List_WriteToFile(v->TP, file, f); List_WriteToFile(v->SL, file, f);
  List_WriteToFile(v->VL, file, f); List_WriteToFile(v->TL, file, f);
  List_WriteToFile(v->ST, file, f); List_WriteToFile(v->VT, file, f);
  List_WriteToFile(v->TT, file, f); List_WriteToFile(v->SS, file, f);
  List_WriteToFile(v->VS, file, f); List_WriteToFile(v->TS, file, f);
  List_WriteToFile(v->T2D, file, f); List_WriteToFile(v->T2C, file, f);
  List_WriteToFile(v->T3D, file, f); List_WriteToFile(v->T3C, file, f);
  fprintf(file, "\n");
  fprintf(file, "$EndView\n");

  if(filename){
    Msg(INFO, "View output complete '%s'", filename);
    Msg(STATUS2, "Wrote '%s'", filename);
    fclose(file);
  }

}

// Smoothing

using namespace std;

struct xyzv{
private:
public:
  double x,y,z,*vals;
  int nbvals;
  int nboccurences;
  static double eps;
  void update (int nbVals, double *);
  xyzv(double x, double y, double z);
  ~xyzv();
  xyzv & operator = ( const xyzv &);
  xyzv ( const xyzv &);
};

double xyzv::eps = 0.0;

xyzv::xyzv (double xx, double yy, double zz) 
  : x(xx),y(yy),z(zz),vals(0),nbvals(0),nboccurences(0){}

xyzv::~xyzv(){
  if(vals)delete [] vals;
}

xyzv::xyzv(const xyzv &other){
  x = other.x;
  y = other.y;
  z = other.z;
  nbvals = other.nbvals;
  nboccurences = other.nboccurences;
  if(other.vals && other.nbvals){
    vals = new double[other.nbvals];
    for(int i=0;i<nbvals;i++)vals[i] = other.vals[i];
  }
}

xyzv & xyzv::operator = (const xyzv &other){
  if(this != &other){ 
    x = other.x;
    y = other.y;
    z = other.z;
    nbvals = other.nbvals;
    nboccurences = other.nboccurences;
    if(other.vals && other.nbvals){
      vals = new double[other.nbvals];
      for(int i=0;i<nbvals;i++)vals[i] = other.vals[i];
    }
  }
  return *this;
}

void xyzv::update (int n, double *v){
  int i;
  if(!vals){
    vals = new double[n];
    for(i=0;i<n;i++)vals[i] = 0.0;
    nbvals = n;
    nboccurences = 0;
  }
  else if (nbvals != n){
    throw n;
  }

  double x1 = (double)(nboccurences)/ (double)(nboccurences + 1);
  double x2 = 1./(double)(nboccurences + 1);
  for(i=0;i<nbvals;i++)vals[i] = (x1 * vals[i] + x2 * v[i]);
  nboccurences++;

  //printf("val(%d,%f,%f,%f) = %f\n",nboccurences,x,y,z,vals[0]);
}

struct lessthanxyzv{
  bool operator () (const xyzv & p2, const xyzv &p1) const{
    if( p1.x - p2.x > xyzv::eps)return true;
    if( p1.x - p2.x <-xyzv::eps)return false;
    if( p1.y - p2.y > xyzv::eps)return true;
    if( p1.y - p2.y <-xyzv::eps)return false;
    if( p1.z - p2.z > xyzv::eps)return true;
    return false;  
  }
};

typedef set<xyzv,lessthanxyzv> mycont;
typedef mycont::const_iterator iter;

class smooth_container{
public :
  mycont c;
};

void smooth_list (List_T *SS , double *min, double *max,
		  int NbTimeStep, int nbvert, int nb, 
		  mycont & connectivities){
  double *x,*y,*z,*v;
  int i,j,k;
  double *vals = new double[NbTimeStep];
  *min = INFINITY;
  *max = -INFINITY;

  for(i = 0 ; i < List_Nbr(SS) ; i+=nb){
    x = (double*)List_Pointer_Fast(SS,i);
    y = (double*)List_Pointer_Fast(SS,i+nbvert);
    z = (double*)List_Pointer_Fast(SS,i+2*nbvert);
    v = (double*)List_Pointer_Fast(SS,i+3*nbvert);
    
    for(j=0;j<nbvert;j++){
      for(k=0;k<NbTimeStep;k++)vals[k] = v[j+k*nbvert];
      xyzv xyz(x[j],y[j],z[j]);
      iter it = connectivities.find(xyz);
      if(it == connectivities.end()){
	xyz.update(NbTimeStep,vals);
	connectivities.insert(xyz);
      }
      else{
	xyzv *xx = (xyzv*) &(*it); // a little weird ... becaus we know that 
	// this will not destroy the set ordering
	xx->update(NbTimeStep,vals);
      }
    }
  }   
  
  for(i = 0 ; i < List_Nbr(SS) ; i+=nb){
    x = (double*)List_Pointer_Fast(SS,i);
    y = (double*)List_Pointer_Fast(SS,i+nbvert);
    z = (double*)List_Pointer_Fast(SS,i+2*nbvert);
    v = (double*)List_Pointer_Fast(SS,i+3*nbvert);
    for(j=0;j<nbvert;j++){
      xyzv xyz(x[j],y[j],z[j]);
      iter it = connectivities.find(xyz);
      if(it != connectivities.end()){
	for(k=0;k<NbTimeStep;k++){
	  v[j+k*nbvert] = (*it).vals[k];
	  if(v[j+k*nbvert] < *min) *min = v[j+k*nbvert] ;
	  if(v[j+k*nbvert] > *max) *max = v[j+k*nbvert] ;
	}
      }
    }
  } 
  delete [] vals;
}

void Post_View :: smooth (){
  xyzv::eps = CTX.lc * 1.e-8;
  int nb;
  
  if(NbSS){
    mycont conSS;
    Msg(INFO,"Smoothing scalar tetrahedra in view...");
    nb = List_Nbr(SS) / NbSS ;
    smooth_list (SS , &Min, &Max, NbTimeStep, 4, nb, conSS);
    Msg(INFO,"...done");
  }
  if(NbST){
    mycont conST;
    Msg(INFO,"Smoothing scalar triangles in view...");
    nb = List_Nbr(ST) / NbST ;
    smooth_list (ST , &Min, &Max, NbTimeStep, 3, nb, conST);
    Msg(INFO,"...done");
  }
  
}
  
// Normal smoothing

void Post_View :: reset_normals(){
  if(normals) delete normals;
  normals  = 0;
}

void Post_View :: add_normal(double x, double y, double z, 
			     double nx, double ny, double nz){
  if(!normals) normals = new smooth_container;

  double n[3] = {nx,ny,nz};
  xyzv xyz(x,y,z);

  iter it = normals->c.find(xyz);

  if(it == normals->c.end()){
    xyz.update(3,n);
    normals->c.insert(xyz);
  }
  else{
    xyzv *xx = (xyzv*) &(*it); 
    xx->update(3,n);
  }
}

double get_angle (double * aa, double * bb){ 
 double angplan, cosc, sinc, a[3],b[3],c[3];
  if(!aa || !bb) return 0.;
  a[0] = aa[0];
  a[1] = aa[1];
  a[2] = aa[2];
  b[0] = bb[0];
  b[1] = bb[1];
  b[2] = bb[2];
  norme (a);
  norme (b);
  prodve (a, b, c);
  prosca (a, b, &cosc);
  sinc = sqrt (c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
  angplan = myatan2 (sinc, cosc);
  return angplan*180./Pi;
}

bool Post_View :: get_normal(double x, double y, double z, 
			     double &nx, double &ny, double &nz){
  if(!normals) return false;

  double n[3] = {nx,ny,nz};
  xyzv xyz(x,y,z);

  iter it = normals->c.find(xyz);

  if(it == normals->c.end()) return false;

  double angle = get_angle ((*it).vals, n);

  if(fabs(angle) < AngleSmoothNormals)
    {
      nx = (*it).vals[0];
      ny = (*it).vals[1];
      nz = (*it).vals[2];
    }

  return true;
}

// Transformation

static void transform(double mat[3][3], double v[3],
		      double *x, double *y, double *z){
  *x = mat[0][0]*v[0] + mat[0][1]*v[1] + mat[0][2]*v[2];
  *y = mat[1][0]*v[0] + mat[1][1]*v[1] + mat[1][2]*v[2];
  *z = mat[2][0]*v[0] + mat[2][1]*v[1] + mat[2][2]*v[2];
}

static void transform_list(List_T *V , int NbTimeStep, int nbvert,
			   int nb, double mat[3][3]){
  double *x,*y,*z, v[3];
  int i, j;

  for(i = 0 ; i < List_Nbr(V) ; i+=nb){
    x = (double*)List_Pointer_Fast(V,i);
    y = (double*)List_Pointer_Fast(V,i+nbvert);
    z = (double*)List_Pointer_Fast(V,i+2*nbvert);
    for(j=0; j<nbvert; j++){
      v[0] = x[j];
      v[1] = y[j];
      v[2] = z[j];
      transform(mat,v,&x[j],&y[j],&z[j]);
    }
  }
}

void Post_View :: transform (double mat[3][3]){
  int nb;

  if(NbSP){
    nb = List_Nbr(SP) / NbSP ;
    transform_list(SP, NbTimeStep, 1, nb, mat);
  }
  if(NbSL){
    nb = List_Nbr(SL) / NbSL ;
    transform_list(SL, NbTimeStep, 2, nb, mat);
  }
  if(NbST){
    nb = List_Nbr(ST) / NbST ;
    transform_list(ST, NbTimeStep, 3, nb, mat);
  }
  if(NbSS){
    nb = List_Nbr(SS) / NbSS ;
    transform_list(SS, NbTimeStep, 4, nb, mat);
  }


  if(NbVP){
    nb = List_Nbr(VP) / NbVP ;
    transform_list(VP, NbTimeStep, 1, nb, mat);
  }
  if(NbVL){
    nb = List_Nbr(VL) / NbVL ;
    transform_list(VL, NbTimeStep, 2, nb, mat);
  }
  if(NbVT){
    nb = List_Nbr(VT) / NbVT ;
    transform_list(VT, NbTimeStep, 3, nb, mat);
  }
  if(NbVS){
    nb = List_Nbr(VS) / NbVS ;
    transform_list(VS, NbTimeStep, 4, nb, mat);
  }
}

