// $Id: Views.cpp,v 1.43 2001-07-30 18:34:26 geuzaine Exp $

#include <set>
#include "Gmsh.h"
#include "Views.h"
#include "Context.h"
#include "Options.h"
#include "ColorTable.h"

// this static stuff should be removed
int         Post_ViewForceNumber = 0;
List_T     *Post_ViewList = NULL;
Post_View  *Post_ViewReference = NULL, *ActualView;


extern Context_T   CTX ;

static int  ActualViewNum=0, ActualViewIndex=0;
static int  NbPoints, NbLines, NbTriangles, NbTetrahedra;

/* ------------------------------------------------------------------------ */
/*  V i e w s                                                               */
/* ------------------------------------------------------------------------ */

int fcmpPostViewNum(const void *v1, const void *v2){
  return (((Post_View *)v1)->Num - ((Post_View *)v2)->Num);
}

int fcmpPostViewDuplicateOf(const void *v1, const void *v2){
  return (((Post_View *)v1)->DuplicateOf - ((Post_View *)v2)->DuplicateOf);
}

void BeginView(int allocate){
  Post_View v;
  int i;

  if(!Post_ViewList) Post_ViewList = List_Create(100,1,sizeof(Post_View));

  if(!Post_ViewForceNumber){
    // each view MUST have a unique, non-reattributable, number
    v.Num = ++ActualViewNum;
    List_Add(Post_ViewList, &v);
  }
  else{
    v.Num = Post_ViewForceNumber;    
    List_Replace(Post_ViewList,&v,fcmpPostViewNum);
  }

  CTX.post.nb_views = List_Nbr(Post_ViewList);

  ActualViewIndex = List_ISearch(Post_ViewList, &v, fcmpPostViewNum);
  ActualView = (Post_View*)List_Pointer(Post_ViewList, ActualViewIndex);

  NbPoints = NbLines = NbTriangles = NbTetrahedra = 0;

  ActualView->NbTimeStep = 0;
  ActualView->NbSP = ActualView->NbVP = ActualView->NbTP = 0;
  ActualView->NbSL = ActualView->NbVL = ActualView->NbTL = 0;
  ActualView->NbST = ActualView->NbVT = ActualView->NbTT = 0;
  ActualView->NbSS = ActualView->NbVS = ActualView->NbTS = 0;

  if(allocate){
    ActualView->datasize = sizeof(double);

    ActualView->Time = List_Create(100,1000,sizeof(double));

    ActualView->SP = List_Create(100,1000,sizeof(double));
    ActualView->VP = List_Create(100,1000,sizeof(double));
    ActualView->TP = List_Create(100,1000,sizeof(double));
    
    ActualView->SL = List_Create(100,1000,sizeof(double));
    ActualView->VL = List_Create(100,1000,sizeof(double));
    ActualView->TL = List_Create(100,1000,sizeof(double));
    
    ActualView->ST = List_Create(100,1000,sizeof(double));
    ActualView->VT = List_Create(100,1000,sizeof(double));
    ActualView->TT = List_Create(100,1000,sizeof(double));
    
    ActualView->SS = List_Create(100,1000,sizeof(double));
    ActualView->VS = List_Create(100,1000,sizeof(double));
    ActualView->TS = List_Create(100,1000,sizeof(double));
  }
  else{
    ActualView->Time = NULL;
    ActualView->SP = NULL; ActualView->VP = NULL; ActualView->TP = NULL;
    ActualView->SL = NULL; ActualView->VL = NULL; ActualView->TL = NULL;
    ActualView->ST = NULL; ActualView->VT = NULL; ActualView->TT = NULL;
    ActualView->SS = NULL; ActualView->VS = NULL; ActualView->TS = NULL;
  }

  // Copy all options from the reference view initialized in InitOptions()
  CopyViewOptions(Post_ViewReference, ActualView);

  ActualView->Changed = 1;
  ActualView->Links = 0;
  ActualView->DuplicateOf = 0;
  ActualView->ScalarOnly = 1;
  ActualView->normals = NULL;
  ActualView->Min = 1.e200;
  ActualView->Max = -1.e200;
  for(i=0;i<3;i++){
    ActualView->BBox[2*i] = 1.e200;
    ActualView->BBox[2*i+1] = -1.e200;
  }

}

void Stat_ScalarSimplex(int nbnod, int N, double *X, double *Y, double *Z, double *V){
  int i;

  if(!NbPoints && !NbLines && !NbTriangles && !NbTetrahedra){
    ActualView->Min = V[0];
    ActualView->Max = V[0];
    ActualView->NbTimeStep = N/nbnod;
  }
  else if(N/nbnod < ActualView->NbTimeStep)
    ActualView->NbTimeStep = N/nbnod ;

  for(i=0 ; i<N ; i++){
    if(V[i] < ActualView->Min) ActualView->Min = V[i] ;
    if(V[i] > ActualView->Max) ActualView->Max = V[i] ;
  }

  for(i=0 ; i<nbnod ; i++){
    if(X[i] < ActualView->BBox[0]) ActualView->BBox[0] = X[i] ;
    if(X[i] > ActualView->BBox[1]) ActualView->BBox[1] = X[i] ;
    if(Y[i] < ActualView->BBox[2]) ActualView->BBox[2] = Y[i] ;
    if(Y[i] > ActualView->BBox[3]) ActualView->BBox[3] = Y[i] ;
    if(Z[i] < ActualView->BBox[4]) ActualView->BBox[4] = Z[i] ;
    if(Z[i] > ActualView->BBox[5]) ActualView->BBox[5] = Z[i] ;
  }

  switch(nbnod){
  case 1 : NbPoints++; break;
  case 2 : NbLines++; break;
  case 3 : NbTriangles++; break;
  case 4 : NbTetrahedra++; break;
  }
}

void Stat_VectorSimplex(int nbnod, int N, double *X, double *Y, double *Z, double *V){
  double l0;
  int i;

  if(!NbPoints && !NbLines && !NbTriangles && !NbTetrahedra){
    l0 = sqrt(DSQR(V[0])+DSQR(V[1])+DSQR(V[2]));
    ActualView->Min = l0;
    ActualView->Max = l0;
    ActualView->NbTimeStep = N/(3*nbnod) ;
  }
  else if(N/(3*nbnod) < ActualView->NbTimeStep)
    ActualView->NbTimeStep = N/(3*nbnod) ;

  for(i=0 ; i<N ; i+=3){
    l0 = sqrt(DSQR(V[i])+DSQR(V[i+1])+DSQR(V[i+2]));
    if(l0 < ActualView->Min) ActualView->Min = l0 ;
    if(l0 > ActualView->Max) ActualView->Max = l0 ;
  }

  for(i=0 ; i<nbnod ; i++){
    if(X[i] < ActualView->BBox[0]) ActualView->BBox[0] = X[i] ;
    if(X[i] > ActualView->BBox[1]) ActualView->BBox[1] = X[i] ;
    if(Y[i] < ActualView->BBox[2]) ActualView->BBox[2] = Y[i] ;
    if(Y[i] > ActualView->BBox[3]) ActualView->BBox[3] = Y[i] ;
    if(Z[i] < ActualView->BBox[4]) ActualView->BBox[4] = Z[i] ;
    if(Z[i] > ActualView->BBox[5]) ActualView->BBox[5] = Z[i] ;
  }

  ActualView->ScalarOnly = 0;

  switch(nbnod){
  case 1 : NbPoints++; break;
  case 2 : NbLines++; break;
  case 3 : NbTriangles++; break;
  case 4 : NbTetrahedra++; break;
  }
}

void Stat_TensorSimplex(int nbnod, int N, double *X, double *Y, double *Z, double *v){
  Msg(GERROR, "Tensor field views not implemented yet");
}


void EndView(int add_in_gui, char *file_name, char *name){
  int i, nb;
  double d;
  extern int AddViewInUI(int , char *, int);

  // Points

  if(ActualView->NbSP){
    nb = List_Nbr(ActualView->SP) / ActualView->NbSP ;
    for(i = 0 ; i < List_Nbr(ActualView->SP) ; i+=nb)
      Stat_ScalarSimplex(1, nb-3, 
			 (double*)List_Pointer_Fast(ActualView->SP,i),
			 (double*)List_Pointer_Fast(ActualView->SP,i+1),
			 (double*)List_Pointer_Fast(ActualView->SP,i+2),
			 (double*)List_Pointer_Fast(ActualView->SP,i+3));
  }
  if(ActualView->NbVP){
    nb = List_Nbr(ActualView->VP) / ActualView->NbVP ;
    for(i = 0 ; i < List_Nbr(ActualView->VP) ; i+=nb)
      Stat_VectorSimplex(1, nb-3, 
			 (double*)List_Pointer_Fast(ActualView->VP,i),
			 (double*)List_Pointer_Fast(ActualView->VP,i+1),
			 (double*)List_Pointer_Fast(ActualView->VP,i+2),
			 (double*)List_Pointer_Fast(ActualView->VP,i+3));
  }
  if(ActualView->NbTP){
    nb = List_Nbr(ActualView->TP) / ActualView->NbTP ;
    for(i = 0 ; i < List_Nbr(ActualView->TP) ; i+=nb)
      Stat_TensorSimplex(1, nb-3, 
			 (double*)List_Pointer_Fast(ActualView->TP,i),
			 (double*)List_Pointer_Fast(ActualView->TP,i+1),
			 (double*)List_Pointer_Fast(ActualView->TP,i+2),
			 (double*)List_Pointer_Fast(ActualView->TP,i+3));
  }

  // Lines

  if(ActualView->NbSL){
    nb = List_Nbr(ActualView->SL) / ActualView->NbSL ;
    for(i = 0 ; i < List_Nbr(ActualView->SL) ; i+=nb)
      Stat_ScalarSimplex(2, nb-6,
			 (double*)List_Pointer_Fast(ActualView->SL,i),
			 (double*)List_Pointer_Fast(ActualView->SL,i+2),
			 (double*)List_Pointer_Fast(ActualView->SL,i+4),
			 (double*)List_Pointer_Fast(ActualView->SL,i+6));
  }
  if(ActualView->NbVL){
    nb = List_Nbr(ActualView->VL) / ActualView->NbVL ;
    for(i = 0 ; i < List_Nbr(ActualView->VL) ; i+=nb)
      Stat_VectorSimplex(2, nb-6, 
			 (double*)List_Pointer_Fast(ActualView->VL,i),
			 (double*)List_Pointer_Fast(ActualView->VL,i+2),
			 (double*)List_Pointer_Fast(ActualView->VL,i+4),
			 (double*)List_Pointer_Fast(ActualView->VL,i+6));
  }
  if(ActualView->NbTL){
    nb = List_Nbr(ActualView->TL) / ActualView->NbTL ;
    for(i = 0 ; i < List_Nbr(ActualView->TL) ; i+=nb)
      Stat_TensorSimplex(2, nb-6, 
			 (double*)List_Pointer_Fast(ActualView->TL,i),
			 (double*)List_Pointer_Fast(ActualView->TL,i+2),
			 (double*)List_Pointer_Fast(ActualView->TL,i+4),
			 (double*)List_Pointer_Fast(ActualView->TL,i+6));
  }

  // Triangles

  if(ActualView->NbST){
    nb = List_Nbr(ActualView->ST) / ActualView->NbST ;
    for(i = 0 ; i < List_Nbr(ActualView->ST) ; i+=nb)
      Stat_ScalarSimplex(3, nb-9, 
			 (double*)List_Pointer_Fast(ActualView->ST,i),
			 (double*)List_Pointer_Fast(ActualView->ST,i+3),
			 (double*)List_Pointer_Fast(ActualView->ST,i+6),
			 (double*)List_Pointer_Fast(ActualView->ST,i+9));
  }
  if(ActualView->NbVT){
    nb = List_Nbr(ActualView->VT) / ActualView->NbVT ;
    for(i = 0 ; i < List_Nbr(ActualView->VT) ; i+=nb)
      Stat_VectorSimplex(3, nb-9, 
			 (double*)List_Pointer_Fast(ActualView->VT,i),
			 (double*)List_Pointer_Fast(ActualView->VT,i+3),
			 (double*)List_Pointer_Fast(ActualView->VT,i+6),
			 (double*)List_Pointer_Fast(ActualView->VT,i+9));
  }
  if(ActualView->NbTT){
    nb = List_Nbr(ActualView->TT) / ActualView->NbTT ;
    for(i = 0 ; i < List_Nbr(ActualView->TT) ; i+=nb)
      Stat_TensorSimplex(3, nb-9,
			 (double*)List_Pointer_Fast(ActualView->TT,i),
			 (double*)List_Pointer_Fast(ActualView->TT,i+3),
			 (double*)List_Pointer_Fast(ActualView->TT,i+6),
			 (double*)List_Pointer_Fast(ActualView->TT,i+9));
  }

  // Tetrahedra

  if(ActualView->NbSS){
    nb = List_Nbr(ActualView->SS) / ActualView->NbSS ;
    for(i = 0 ; i < List_Nbr(ActualView->SS) ; i+=nb)
      Stat_ScalarSimplex(4, nb-12, 
			 (double*)List_Pointer_Fast(ActualView->SS,i),
			 (double*)List_Pointer_Fast(ActualView->SS,i+4),
			 (double*)List_Pointer_Fast(ActualView->SS,i+8),
			 (double*)List_Pointer_Fast(ActualView->SS,i+12));
  }
  if(ActualView->NbVS){
    nb = List_Nbr(ActualView->VS) / ActualView->NbVS ;
    for(i = 0 ; i < List_Nbr(ActualView->VS) ; i+=nb)
      Stat_VectorSimplex(4, nb-12,
			 (double*)List_Pointer_Fast(ActualView->VS,i),
			 (double*)List_Pointer_Fast(ActualView->VS,i+4),
			 (double*)List_Pointer_Fast(ActualView->VS,i+8),
			 (double*)List_Pointer_Fast(ActualView->VS,i+12));
  }
  if(ActualView->NbTS){
    nb = List_Nbr(ActualView->TS) / ActualView->NbTS ;
    for(i = 0 ; i < List_Nbr(ActualView->TS) ; i+=nb)
      Stat_TensorSimplex(4, nb-12, 
			 (double*)List_Pointer_Fast(ActualView->TS,i),
			 (double*)List_Pointer_Fast(ActualView->TS,i+4),
			 (double*)List_Pointer_Fast(ActualView->TS,i+8),
			 (double*)List_Pointer_Fast(ActualView->TS,i+12));
  }

  // Dummy time values if using old parsed format...
  if(ActualView->Time && !List_Nbr(ActualView->Time)){
    for(i=0 ; i<ActualView->NbTimeStep ; i++){
      d = (double)i;
      List_Add(ActualView->Time, &d);
    }
  }

  opt_view_name(ActualViewIndex, GMSH_SET|GMSH_GUI, name);
  opt_view_filename(ActualViewIndex, GMSH_SET|GMSH_GUI, file_name);
  opt_view_nb_timestep(ActualViewIndex, GMSH_GUI, 0);
  opt_view_timestep(ActualViewIndex, GMSH_SET|GMSH_GUI, ActualView->TimeStep);
  if(ActualView->Min > ActualView->Max){
    opt_view_min(ActualViewIndex, GMSH_SET|GMSH_GUI, 0.);
    opt_view_max(ActualViewIndex, GMSH_SET|GMSH_GUI, 0.);
  }
  else{
    opt_view_min(ActualViewIndex, GMSH_GUI, 0);
    opt_view_max(ActualViewIndex, GMSH_GUI, 0);
  }
  opt_view_custom_min(ActualViewIndex, GMSH_SET|GMSH_GUI, ActualView->Min);
  opt_view_custom_max(ActualViewIndex, GMSH_SET|GMSH_GUI, ActualView->Max);

  if(CTX.post.smooth) ActualView->smooth();

  if(!Post_ViewForceNumber && add_in_gui)
    AddViewInUI(List_Nbr(Post_ViewList), ActualView->Name, ActualView->Num);
}

bool FreeView(int num){
  Post_View *v;

  Msg(DEBUG, "Trying to free view %d",num);
  
  if(num < 0 || num >= List_Nbr(Post_ViewList)){
    return false ;
  }
  v = (Post_View*)List_Pointer(Post_ViewList, num);
  FreeView(v);
  List_PSuppress(Post_ViewList, num);
  CTX.post.nb_views = List_Nbr(Post_ViewList);

  Msg(INFO, "View %d deleted (%d views left)",num, List_Nbr(Post_ViewList));
  return true;
}


void FreeView(Post_View *v){
  Post_View vv,*v2;
  int i, numdup, free = 1;

  if(v->DuplicateOf){
    vv.Num = v->DuplicateOf ;
    Msg(DEBUG, "This view is a duplicata");
    if(!(v2 = (Post_View*)List_PQuery(Post_ViewList, &vv, fcmpPostViewNum))){
      Msg(DEBUG, "  -the original view is gone");
      numdup = 0;
      for(i=0 ; i<List_Nbr(Post_ViewList); i++)
	numdup += (((Post_View*)List_Pointer(Post_ViewList, i))->DuplicateOf == v->DuplicateOf);
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
  }
  v->reset_normals();
}

void CopyViewOptions(Post_View *src, Post_View *dest){
  strcpy(dest->Format, src->Format);
  dest->CustomMin = src->CustomMin;
  dest->CustomMax = src->CustomMax;
  dest->Offset[0] = src->Offset[0];
  dest->Offset[1] = src->Offset[1];
  dest->Offset[2] = src->Offset[2];
  dest->Raise[0] = src->Raise[0];
  dest->Raise[1] = src->Raise[1];
  dest->Raise[2] = src->Raise[2];
  dest->ArrowScale = src->ArrowScale;
  dest->Visible = src->Visible;
  dest->IntervalsType = src->IntervalsType;
  dest->SaturateValues = src->SaturateValues;
  dest->Boundary = src->Boundary ;
  dest->NbIso = src->NbIso;
  dest->Light = src->Light ;
  dest->SmoothNormals = src->SmoothNormals ;
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
  dest->TransparentScale = src->TransparentScale;
  dest->ScaleType = src->ScaleType;
  dest->RangeType = src->RangeType;
  dest->ArrowType = src->ArrowType;
  dest->ArrowLocation = src->ArrowLocation;
  dest->TimeStep = src->TimeStep;
  ColorTable_Copy(&src->CT);
  ColorTable_Paste(&dest->CT);
}

ColorTable *Get_ColorTable(int num){
  Post_View *v;

  if(!Post_ViewList)
    v = Post_ViewReference ;
  else
    v = (Post_View*)List_Pointer_Test(Post_ViewList, num);
  if(v)
    return &v->CT ;
  else
    return NULL ;
}

void Print_ColorTable(int num, char *prefix, FILE *file){
  char tmp[1024];
  Post_View *v;
  if(!Post_ViewList)
    v = Post_ViewReference ;
  else
    v = (Post_View*)List_Pointer_Test(Post_ViewList, num);
  if(!v) return;
  sprintf(tmp, "%s = {", prefix);
  if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
  ColorTable_Print(&v->CT, file);
  sprintf(tmp, "};");
  if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
}


/* ------------------------------------------------------------------------ */
/*  R e a d _ V i e w                                                       */
/* ------------------------------------------------------------------------ */

void Read_View(FILE *file, char *filename){
  char   str[NAME_STR_L], name[NAME_STR_L];
  int    nb, format, size, testone, swap;
  double version;

  while (1) {

    do { 
      fgets(str, NAME_STR_L, file) ; 
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

      BeginView(0);

      fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
             name, &ActualView->NbTimeStep,
             &ActualView->NbSP, &ActualView->NbVP, &ActualView->NbTP, 
             &ActualView->NbSL, &ActualView->NbVL, &ActualView->NbTL, 
             &ActualView->NbST, &ActualView->NbVT, &ActualView->NbTT, 
             &ActualView->NbSS, &ActualView->NbVS, &ActualView->NbTS);

      swap = 0 ;
      if(format == LIST_FORMAT_BINARY){
	fread(&testone, sizeof(int), 1, file);
	if(testone != 1){
	  Msg(INFO, "Swapping bytes from binary file");
	  swap = 1;
	}
      }

      ActualView->datasize = size ;

      // Time values
      ActualView->Time = List_CreateFromFile(ActualView->NbTimeStep, 
					     size, file, format, swap);

      // Points
      nb = ActualView->NbSP ? ActualView->NbSP * (ActualView->NbTimeStep  +3) : 0 ;
      ActualView->SP = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbVP ? ActualView->NbVP * (ActualView->NbTimeStep*3+3) : 0 ;
      ActualView->VP = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbTP ? ActualView->NbTP * (ActualView->NbTimeStep*9+3) : 0 ;
      ActualView->TP = List_CreateFromFile(nb, size, file, format, swap);

      // Lines
      nb = ActualView->NbSL ? ActualView->NbSL * (ActualView->NbTimeStep*2  +6) : 0 ;
      ActualView->SL = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbVL ? ActualView->NbVL * (ActualView->NbTimeStep*2*3+6) : 0 ;
      ActualView->VL = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbTL ? ActualView->NbTL * (ActualView->NbTimeStep*2*9+6) : 0 ;
      ActualView->TL = List_CreateFromFile(nb, size, file, format, swap);

      // Triangles
      nb = ActualView->NbST ? ActualView->NbST * (ActualView->NbTimeStep*3  +9) : 0 ;
      ActualView->ST = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbVT ? ActualView->NbVT * (ActualView->NbTimeStep*3*3+9) : 0 ;
      ActualView->VT = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbTT ? ActualView->NbTT * (ActualView->NbTimeStep*3*9+9) : 0 ;
      ActualView->TT = List_CreateFromFile(nb, size, file, format, swap);

      // Tetrahedra
      nb = ActualView->NbSS ? ActualView->NbSS * (ActualView->NbTimeStep*4  +12) : 0 ;
      ActualView->SS = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbVS ? ActualView->NbVS * (ActualView->NbTimeStep*4*3+12) : 0 ;
      ActualView->VS = List_CreateFromFile(nb, size, file, format, swap);

      nb = ActualView->NbTS ? ActualView->NbTS * (ActualView->NbTimeStep*4*9+12) : 0 ;
      ActualView->TS = List_CreateFromFile(nb, size, file, format, swap);

      Msg(DEBUG, "Read View '%s' (%d TimeSteps): %d %d %d %d %d %d %d %d %d %d %d %d",
          name, ActualView->NbTimeStep,
          ActualView->NbSP, ActualView->NbVP, ActualView->NbTP, 
          ActualView->NbSL, ActualView->NbVL, ActualView->NbTL, 
          ActualView->NbST, ActualView->NbVT, ActualView->NbTT, 
          ActualView->NbSS, ActualView->NbVS, ActualView->NbTS);
      Msg(DEBUG, "List_Nbrs: %d %d %d %d %d %d %d %d %d %d %d %d",
          List_Nbr(ActualView->SP), List_Nbr(ActualView->VP), List_Nbr(ActualView->TP), 
          List_Nbr(ActualView->SL), List_Nbr(ActualView->VL), List_Nbr(ActualView->TL), 
          List_Nbr(ActualView->ST), List_Nbr(ActualView->VT), List_Nbr(ActualView->TT), 
          List_Nbr(ActualView->SS), List_Nbr(ActualView->VS), List_Nbr(ActualView->TS));

      EndView(1, filename, name); 
    }

    do {
      fgets(str, NAME_STR_L, file) ;
      if (feof(file)) Msg(GERROR,"Prematured end of file");
    } while (str[0] != '$') ;

  }   /* while 1 ... */

}

/* ------------------------------------------------------------------------ */
/*  W r i t e _ V i e w                                                     */
/* ------------------------------------------------------------------------ */

void Write_View(int Flag_BIN, Post_View *v, char *filename){
  FILE *file;
  int i, f, One=1;

  if(filename){
    file = fopen(filename,"w");
    if(!file){
      Msg(WARNING, "Unable to open file '%s'", filename);
      return;
    }
  }
  else
    file = stdout;
 
  fprintf(file, "$PostFormat /* Gmsh 1.0, %s */\n",
	  Flag_BIN ? "binary" : "ascii") ;
  fprintf(file, "1.0 %d %d\n", Flag_BIN, (int)sizeof(double)) ;
  fprintf(file, "$EndPostFormat\n") ;
  for(i=0;i<(int)strlen(v->Name);i++)
    if(v->Name[i]==' ') v->Name[i]='_'; 
  // -> Il faudra changer le format de post pour autoriser les blancs.
  // On ajoutera aussi un entier par simplexe (num de region).
  // Devrait-on passer a un format liste de noeuds + liste de
  // simplexes ?
  fprintf(file, "$View /* %s */\n", v->Name);
  fprintf(file, "%s ", v->Name);
  fprintf(file, "%d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
	  List_Nbr(v->Time),
	  v->NbSP, v->NbVP, v->NbTP, v->NbSL, v->NbVL, v->NbTL, 
	  v->NbST, v->NbVT, v->NbTT, v->NbSS, v->NbVS, v->NbTS);
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
  if(Flag_BIN) fprintf(file, "\n");
  fprintf(file, "$EndView\n");

  if(filename){
    Msg(INFO, "View output complete '%s'", filename);
    Msg(STATUS2, "Wrote '%s'", filename);
    fclose(file);
  }

}



/*
  A little util for smoothing a view.
*/

using namespace std;
struct xyzv
{
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

xyzv::xyzv (double xx, double yy, double zz) : x(xx),y(yy),z(zz),vals(0),nbvals(0),nboccurences(0){}
xyzv::~xyzv()
{
  if(vals)delete [] vals;
}
xyzv::xyzv(const xyzv &other)
{
  x = other.x;
  y = other.y;
  z = other.z;
  nbvals = other.nbvals;
  nboccurences = other.nboccurences;
  if(other.vals && other.nbvals)
    {
      vals = new double[other.nbvals];
      for(int i=0;i<nbvals;i++)vals[i] = other.vals[i];
    }
}
xyzv & xyzv::operator = (const xyzv &other)
{
  if(this != &other)
    { 
      x = other.x;
      y = other.y;
      z = other.z;
      nbvals = other.nbvals;
      nboccurences = other.nboccurences;
      if(other.vals && other.nbvals)
	{
	  vals = new double[other.nbvals];
	  for(int i=0;i<nbvals;i++)vals[i] = other.vals[i];
	}
    }
  return *this;
}

void xyzv::update (int n, double *v)
{
  int i;
  if(!vals)
    {
      vals = new double[n];
      for(i=0;i<n;i++)vals[i] = 0.0;
      nbvals = n;
      nboccurences = 0;
    }
  else if (nbvals != n)
    {
      throw n;
    }

  //  if(n==3)printf("val(%d,%f,%f,%f) = %f %f %f\n",nboccurences,x,y,z,v[0],v[1],v[2]);

  double x1 = (double)(nboccurences)/ (double)(nboccurences + 1);
  double x2 = 1./(double)(nboccurences + 1);
  for(i=0;i<nbvals;i++)vals[i] = (x1 * vals[i] + x2 * v[i]);
  nboccurences++;
}


struct lessthanxyzv
{
  bool operator () (const xyzv & p2, const xyzv &p1) const
  {
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

class smooth_container 
{
public :
  mycont c;
};

void smooth_list (List_T *SS ,
		  int NbTimeStep,
		  int nbvert,
		  int nb, 
		  mycont & connectivities)
{
  double *x,*y,*z,*v;
  int i,j,k;
  double *vals = new double[NbTimeStep];
  for(i = 0 ; i < List_Nbr(SS) ; i+=nb)
    {
      x = (double*)List_Pointer_Fast(SS,i);
      y = (double*)List_Pointer_Fast(SS,i+nbvert);
      z = (double*)List_Pointer_Fast(SS,i+2*nbvert);
      v = (double*)List_Pointer_Fast(SS,i+3*nbvert);
      
      for(j=0;j<nbvert;j++)
	{
	  for(k=0;k<NbTimeStep;k++)vals[k] = v[j+k*nbvert];
	  xyzv xyz(x[j],y[j],z[j]);
	  iter it = connectivities.find(xyz);
	  if(it == connectivities.end())
	    {
	      xyz.update(NbTimeStep,vals);
	      connectivities.insert(xyz);
	    }
	  else
	    {
	      xyzv *xx = (xyzv*) &(*it); // a little weird ... becaus we know that 
	      // this will not destroy the set ordering
	      xx->update(NbTimeStep,vals);
	    }
	}
    }   
  
  printf("phase 2\n");

  for(i = 0 ; i < List_Nbr(SS) ; i+=nb)
    {
      x = (double*)List_Pointer_Fast(SS,i);
      y = (double*)List_Pointer_Fast(SS,i+nbvert);
      z = (double*)List_Pointer_Fast(SS,i+2*nbvert);
      v = (double*)List_Pointer_Fast(SS,i+3*nbvert);
      for(j=0;j<nbvert;j++)
	{
	  xyzv xyz(x[j],y[j],z[j]);
	  //double l = sqrt((x[j])*(x[j]) + y[j]*y[j] + z[j] * z[j]);
	  iter it = connectivities.find(xyz);
	  if(it != connectivities.end())
	    for(k=0;k<NbTimeStep;k++)v[j+k*nbvert] = (*it).vals[k];
	  //for(k=0;k<NbTimeStep;k++)v[j+k*8] = l;
	}
    } 
  delete [] vals;
}

void Post_View :: smooth ()
{
  xyzv::eps = CTX.lc * 1.e-6;
  int nb;

  if(NbSS){
    mycont conSS;
    Msg(INFO,"Smoothing SS vector in a view ...");
    nb = List_Nbr(SS) / NbSS ;
    smooth_list (SS , NbTimeStep, 4, nb, conSS);
    Msg(INFO,"...done");
  }
  if(NbST){
    mycont conST;
    Msg(INFO,"Smoothing ST vector in a view ...");
    nb = List_Nbr(ST) / NbST ;
    smooth_list (ST , NbTimeStep, 3, nb, conST);
    Msg(INFO,"...done");
  }
  
}

/*
  Another util to smooth normals
*/

void Post_View :: reset_normals()
{
  if(normals)delete normals;
  normals  = 0;
}

void Post_View :: add_normal(double x, double y, double z, 
			     double nx, double ny, double nz)
{
  if(!normals)normals = new smooth_container;
  xyzv xyz(x,y,z);
  double n[3] = {nx,ny,nz};
  iter it = normals->c.find(xyz);
  if(it == normals->c.end())
    {
      xyz.update(3,n);
      normals->c.insert(xyz);
    }
  else
    {
      xyzv *xx = (xyzv*) &(*it); 
      xx->update(3,n);
    }
}

bool Post_View :: get_normal(double x, double y, double z, 
			     double &nx, double &ny, double &nz)
{
  if(!normals)
    return false;
  xyzv xyz(x,y,z);
  iter it = normals->c.find(xyz);
  if(it == normals->c.end())return false;
  nx = (*it).vals[0];
  ny = (*it).vals[1];
  nz = (*it).vals[2];
  return true;
}


