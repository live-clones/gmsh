/* $Id: Views.cpp,v 1.17 2000-12-17 21:17:29 remacle Exp $ */

#include "Gmsh.h"
#include "Views.h"
#include "Context.h"
#include "ColorTable.h"

List_T  *Post_ViewList = NULL;
Post_View  *ActualView;

extern Context_T   CTX ;

static int  ActualViewNum=0;
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
  ActualView = (Post_View*)Malloc(sizeof(Post_View));

  NbPoints = NbLines = NbTriangles = NbTetrahedra = 0;

  ActualView->NbSP = ActualView->NbVP = ActualView->NbTP = 0;
  ActualView->NbSL = ActualView->NbVL = ActualView->NbTL = 0;
  ActualView->NbST = ActualView->NbVT = ActualView->NbTT = 0;
  ActualView->NbSS = ActualView->NbVS = ActualView->NbTS = 0;

  if(allocate){
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

  ActualView->Changed = 1;
  ActualView->Links = 0;
  ActualView->DuplicateOf = 0;
  ActualView->Min = 1.e200;
  ActualView->Max = -1.e200;
  ActualView->NbIso = CTX.post.initial_nbiso;
  ActualView->IntervalsType = CTX.post.initial_intervals;
  ActualView->Light = 0;
  ActualView->ShowElement = 0;
  ActualView->ShowTime = 1;
  ActualView->Visible = CTX.post.initial_visibility;
  ActualView->TimeStep = 0;
  ActualView->ArrowScale = 100.; 
  ActualView->ArrowType = DRAW_POST_ARROW; 
  ActualView->ArrowLocation = DRAW_POST_LOCATE_COG; 
  ActualView->RangeType = DRAW_POST_DEFAULT; 
  ActualView->ShowScale = 1;
  ActualView->TransparentScale = 1;
  ActualView->ScaleType = DRAW_POST_LINEAR; 
  ActualView->Raise[0] = 0.0;
  ActualView->Raise[1] = 0.0;
  ActualView->Raise[2] = 0.0;
  ActualView->ScalarOnly = 1;
  ActualView->NbTimeStep = 0;
  ActualView->CT.size = 255;
  ActualView->CT.ipar[COLORTABLE_MODE] = COLORTABLE_RGB;
  ColorTable_InitParam(1, &ActualView->CT, 1, 1);
  ColorTable_Recompute(&ActualView->CT, 1, 1);
}

void Stat_ScalarSimplex(int nbnod, int N, double *V){
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

  switch(nbnod){
  case 1 : NbPoints++; break;
  case 2 : NbLines++; break;
  case 3 : NbTriangles++; break;
  case 4 : NbTetrahedra++; break;
  }
}

void Stat_VectorSimplex(int nbnod, int N, double *V){
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

  ActualView->ScalarOnly = 0;

  switch(nbnod){
  case 1 : NbPoints++; break;
  case 2 : NbLines++; break;
  case 3 : NbTriangles++; break;
  case 4 : NbTetrahedra++; break;
  }
}

void Stat_TensorSimplex(int nbnod, int N, double *v){
  Msg(ERROR, "Tensor Field Views not Implemented Yet");
}

void EndView(int AddInUI, int Number, char *FileName, char *Name, 
             double XOffset, double YOffset, double ZOffset){
  int i, nb;
  double d;
  extern void AddViewInUI(int , char *, int);

  // Points

  if(ActualView->NbSP){
    nb = List_Nbr(ActualView->SP) / ActualView->NbSP ;
    for(i = 0 ; i < List_Nbr(ActualView->SP) ; i+=nb)
      Stat_ScalarSimplex(1, nb-3, (double*)List_Pointer(ActualView->SP,i+3));
  }
  if(ActualView->NbVP){
    nb = List_Nbr(ActualView->VP) / ActualView->NbVP ;
    for(i = 0 ; i < List_Nbr(ActualView->VP) ; i+=nb)
      Stat_VectorSimplex(1, nb-3, (double*)List_Pointer(ActualView->VP,i+3));
  }
  if(ActualView->NbTP){
    nb = List_Nbr(ActualView->TP) / ActualView->NbTP ;
    for(i = 0 ; i < List_Nbr(ActualView->TP) ; i+=nb)
      Stat_TensorSimplex(1, nb-3, (double*)List_Pointer(ActualView->TP,i+3));
  }

  // Lines

  if(ActualView->NbSL){
    nb = List_Nbr(ActualView->SL) / ActualView->NbSL ;
    for(i = 0 ; i < List_Nbr(ActualView->SL) ; i+=nb)
      Stat_ScalarSimplex(2, nb-6, (double*)List_Pointer(ActualView->SL,i+6));
  }
  if(ActualView->NbVL){
    nb = List_Nbr(ActualView->VL) / ActualView->NbVL ;
    for(i = 0 ; i < List_Nbr(ActualView->VL) ; i+=nb)
      Stat_VectorSimplex(2, nb-6, (double*)List_Pointer(ActualView->VL,i+6));
  }
  if(ActualView->NbTL){
    nb = List_Nbr(ActualView->TL) / ActualView->NbTL ;
    for(i = 0 ; i < List_Nbr(ActualView->TL) ; i+=nb)
      Stat_TensorSimplex(2, nb-6, (double*)List_Pointer(ActualView->TL,i+6));
  }

  // Triangles

  if(ActualView->NbST){
    nb = List_Nbr(ActualView->ST) / ActualView->NbST ;
    for(i = 0 ; i < List_Nbr(ActualView->ST) ; i+=nb)
      Stat_ScalarSimplex(3, nb-9, (double*)List_Pointer(ActualView->ST,i+9));
  }
  if(ActualView->NbVT){
    nb = List_Nbr(ActualView->VT) / ActualView->NbVT ;
    for(i = 0 ; i < List_Nbr(ActualView->VT) ; i+=nb)
      Stat_VectorSimplex(3, nb-9, (double*)List_Pointer(ActualView->VT,i+9));
  }
  if(ActualView->NbTT){
    nb = List_Nbr(ActualView->TT) / ActualView->NbTT ;
    for(i = 0 ; i < List_Nbr(ActualView->TT) ; i+=nb)
      Stat_TensorSimplex(3, nb-9, (double*)List_Pointer(ActualView->TT,i+9));
  }

  // Tetrahedra

  if(ActualView->NbSS){
    nb = List_Nbr(ActualView->SS) / ActualView->NbSS ;
    for(i = 0 ; i < List_Nbr(ActualView->SS) ; i+=nb)
      Stat_ScalarSimplex(4, nb-12, (double*)List_Pointer(ActualView->SS,i+12));
  }
  if(ActualView->NbVS){
    nb = List_Nbr(ActualView->VS) / ActualView->NbVS ;
    for(i = 0 ; i < List_Nbr(ActualView->VS) ; i+=nb)
      Stat_VectorSimplex(4, nb-12, (double*)List_Pointer(ActualView->VS,i+12));
  }
  if(ActualView->NbTS){
    nb = List_Nbr(ActualView->TS) / ActualView->NbTS ;
    for(i = 0 ; i < List_Nbr(ActualView->TS) ; i+=nb)
      Stat_TensorSimplex(4, nb-12, (double*)List_Pointer(ActualView->TS,i+12));
  }

  // Dummy time values if using old parsed format...
  if(!List_Nbr(ActualView->Time)){
    for(i=0 ; i<ActualView->NbTimeStep ; i++){
      d = (double)i;
      List_Add(ActualView->Time, &d);
    }
  }

  strcpy(ActualView->FileName,FileName);
  strcpy(ActualView->Name,Name);
  strcpy(ActualView->Format, "%.3e");
  if(ActualView->Min > ActualView->Max)
    ActualView->Min = ActualView->Max = 0.0 ;
  ActualView->CustomMin = ActualView->Min;
  ActualView->CustomMax = ActualView->Max;
  ActualView->Offset[0] = XOffset*(CTX.range[0]?CTX.range[0]:CTX.lc)*1.e-3;
  ActualView->Offset[1] = YOffset*(CTX.range[1]?CTX.range[1]:CTX.lc)*1.e-3;
  ActualView->Offset[2] = ZOffset*(CTX.range[2]?CTX.range[2]:CTX.lc)*1.e-3;

  /* j'en alloue directement le max pour eviter les problemes de
     reallocation (avec CurrentView) */
  if(!Post_ViewList) 
    Post_ViewList = List_Create(100,1,sizeof(Post_View));

  if(!Number){
    ActualView->Num = ++ActualViewNum;    
    List_Add(Post_ViewList,ActualView);
    if(AddInUI)
      AddViewInUI(List_Nbr(Post_ViewList), ActualView->Name, ActualView->Num);
  }
  else{
    ActualView->Num = Number;    
    List_Replace(Post_ViewList,ActualView,fcmpPostViewNum);
  }

  ActualView = NULL;
}

bool FreeView(int num){
  Post_View *v;

  printf("trying to free view %d\n",num);
  
  if(num < 0 || num >= List_Nbr(Post_ViewList)){
    return false ;
  }
  v = (Post_View*)List_Pointer(Post_ViewList, num);
  FreeView(v);
  List_Suppress(Post_ViewList, v, fcmpPostViewNum);
  printf("view deleted, %d views left %d\n",num,List_Nbr(Post_ViewList));
  return true;
}


void FreeView(Post_View *v){
  Post_View vv,*v2;
  int free = 1;

  if(v->DuplicateOf){
    vv.Num = v->DuplicateOf ;
    Msg(DEBUG, "This View is a Duplicata");
    if(!(v2 = (Post_View*)List_PQuery(Post_ViewList, &vv, fcmpPostViewNum))){
      Msg(DEBUG, " ->The Original View is Gone");
      if(!(v2 = (Post_View*)List_PQuery(Post_ViewList, v, fcmpPostViewDuplicateOf))){
        Msg(DEBUG, " ->There are no other duplicata");
        free = 1 ;
      }
      else{
        free = 0 ;
      }
    }
    else{
      v2->Links--;
      free = 0 ;
      Msg(DEBUG, " ->The original still exists, so I dont't free anything now");
    }
  }

  if(v->Links)
    Msg(DEBUG, " ->This view is linked: Cannot free");

  if(free && !v->Links){
    Msg(DEBUG, " ->Freeing View");
    List_Delete(v->Time);
    List_Delete(v->SP); List_Delete(v->VP); List_Delete(v->TP);
    List_Delete(v->SL); List_Delete(v->VL); List_Delete(v->TL);
    List_Delete(v->ST); List_Delete(v->VT); List_Delete(v->TT);
    List_Delete(v->SS); List_Delete(v->VS); List_Delete(v->TS);
  }

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
  dest->NbIso = src->NbIso;
  dest->Light = src->Light ;
  dest->ShowElement = src->ShowElement;
  dest->ShowTime = src->ShowTime;
  dest->ShowScale = src->ShowScale;
  dest->TransparentScale = src->TransparentScale;
  dest->ScaleType = src->ScaleType;
  dest->RangeType = src->RangeType;
  dest->ArrowType = src->ArrowType;
  dest->ArrowLocation = src->ArrowLocation;
  dest->TimeStep = src->TimeStep;
  ColorTable_Copy(&src->CT);
  ColorTable_Paste(&dest->CT);
}

char *Get_StringViewOption(int num, char *str, int *type){
  Post_View *v;

  if(num < 0 || num >= List_Nbr(Post_ViewList)){
    *type = -1 ;
    return NULL ;
  }
  v = (Post_View*)List_Pointer(Post_ViewList, num);

  if(!strcmp(str, "Format")) return v->Format ;
  else if(!strcmp(str, "FileName")) return v->FileName ;
  else if(!strcmp(str, "Name")) return v->Name ;
  else return NULL ;

}

void Print_StringViewOptions(int num, FILE *file){
  Post_View *v;

  if(num < 0 || num >= List_Nbr(Post_ViewList))
    return ;
  v = (Post_View*)List_Pointer(Post_ViewList, num);

  fprintf(file, "PostProcessing.View[%d].Format = \"%s\";\n", num, v->Format);
  fprintf(file, "PostProcessing.View[%d].FileName = \"%s\";\n", num, v->FileName);
  fprintf(file, "PostProcessing.View[%d].Name = \"%s\";\n", num, v->Name);
}

void *Get_NumberViewOption(int num, char *str, int *type){
  Post_View *v;

  if(num < 0 || num >= List_Nbr(Post_ViewList)){
    *type = -1 ;
    return NULL ;
  }
  v = (Post_View*)List_Pointer(Post_ViewList, num);

  if(!strcmp(str, "NbTimeStep")) { *type = GMSH_INT; return (void*)&v->NbTimeStep; }
  else if(!strcmp(str, "TimeStep")) { *type = GMSH_INT; return (void*)&v->TimeStep; }
  else if(!strcmp(str, "Min")) { *type = GMSH_DOUBLE; return (void*)&v->Min ; }
  else if(!strcmp(str, "Max")) { *type = GMSH_DOUBLE ; return (void*)&v->Max ; }
  else if(!strcmp(str, "CustomMin")) { *type = GMSH_DOUBLE ; return (void*)&v->CustomMin ; }
  else if(!strcmp(str, "CustomMax")) { *type = GMSH_DOUBLE ; return (void*)&v->CustomMax ; }
  else if(!strcmp(str, "Offset0")) { *type = GMSH_DOUBLE ; return (void*)&v->Offset[0] ; }
  else if(!strcmp(str, "Offset1")) { *type = GMSH_DOUBLE ; return (void*)&v->Offset[1] ; }
  else if(!strcmp(str, "Offset2")) { *type = GMSH_DOUBLE ; return (void*)&v->Offset[2] ; }
  else if(!strcmp(str, "Raise0")) { *type = GMSH_DOUBLE ; return (void*)&v->Raise[0] ; }
  else if(!strcmp(str, "Raise1")) { *type = GMSH_DOUBLE ; return (void*)&v->Raise[1] ; }
  else if(!strcmp(str, "Raise2")) { *type = GMSH_DOUBLE ; return (void*)&v->Raise[2] ; }
  else if(!strcmp(str, "ArrowScale")) { *type = GMSH_DOUBLE ; return (void*)&v->ArrowScale ; }
  else if(!strcmp(str, "Visible")) { *type = GMSH_INT ; return (void*)&v->Visible ; }
  else if(!strcmp(str, "IntervalsType")) { *type = GMSH_INT ; return (void*)&v->IntervalsType ; }
  else if(!strcmp(str, "NbIso")) { *type = GMSH_INT ; return (void*)&v->NbIso ; }
  else if(!strcmp(str, "Light")) { *type = GMSH_INT ; return (void*)&v->Light ; }
  else if(!strcmp(str, "ShowElement")) { *type = GMSH_INT ; return (void*)&v->ShowElement ; }
  else if(!strcmp(str, "ShowTime")) { *type = GMSH_INT ; return (void*)&v->ShowTime ; }
  else if(!strcmp(str, "ShowScale")) { *type = GMSH_INT ; return (void*)&v->ShowScale ; }
  else if(!strcmp(str, "TransparentScale")) { *type = GMSH_INT ; return (void*)&v->TransparentScale ; }
  else if(!strcmp(str, "ScaleType")) { *type = GMSH_INT ; return (void*)&v->ScaleType ; }
  else if(!strcmp(str, "RangeType")) { *type = GMSH_INT ; return (void*)&v->RangeType ; }
  else if(!strcmp(str, "ArrowType")) { *type = GMSH_INT ; return (void*)&v->ArrowType ; }
  else if(!strcmp(str, "ArrowLocation")) { *type = GMSH_INT ; return (void*)&v->ArrowLocation ; }
  else{
    return NULL ;
  }
}

void Print_NumberViewOptions(int num, FILE *file){
  Post_View *v;

  if(num < 0 || num >= List_Nbr(Post_ViewList))
    return ;
  v = (Post_View*)List_Pointer(Post_ViewList, num);

  fprintf(file, "PostProcessing.View[%d].NbTimeStep = %d;\n", num, v->NbTimeStep);
  fprintf(file, "PostProcessing.View[%d].TimeStep = %d;\n", num, v->TimeStep);
  fprintf(file, "PostProcessing.View[%d].Min = %g;\n", num, v->Min);
  fprintf(file, "PostProcessing.View[%d].Max = %g;\n", num, v->Max);
  fprintf(file, "PostProcessing.View[%d].CustomMin = %g;\n", num, v->CustomMin);
  fprintf(file, "PostProcessing.View[%d].CustomMax = %g;\n", num, v->CustomMax);
  fprintf(file, "PostProcessing.View[%d].ArrowScale = %g;\n", num, v->ArrowScale);
  fprintf(file, "PostProcessing.View[%d].Visible = %d;\n", num, v->Visible);
  fprintf(file, "PostProcessing.View[%d].IntervalsType = %d;\n", num, v->IntervalsType);
  fprintf(file, "PostProcessing.View[%d].NbIso = %d;\n", num, v->NbIso);
  fprintf(file, "PostProcessing.View[%d].Light = %d;\n", num, v->Light);
  fprintf(file, "PostProcessing.View[%d].ShowElement = %d;\n", num, v->ShowElement);
  fprintf(file, "PostProcessing.View[%d].ShowTime = %d;\n", num, v->ShowTime);
  fprintf(file, "PostProcessing.View[%d].ShowScale = %d;\n", num, v->ShowScale);
  fprintf(file, "PostProcessing.View[%d].TransparentScale = %d;\n", num, v->TransparentScale);
  fprintf(file, "PostProcessing.View[%d].ScaleType = %d;\n", num, v->ScaleType);
  fprintf(file, "PostProcessing.View[%d].RangeType = %d;\n", num, v->RangeType);
  fprintf(file, "PostProcessing.View[%d].ArrowType = %d;\n", num, v->ArrowType);
  fprintf(file, "PostProcessing.View[%d].ArrowLocation = %d;\n", num, v->ArrowLocation);
  fprintf(file, "PostProcessing.View[%d].Offset0 = %g;\n", num, v->Offset[0]);
  fprintf(file, "PostProcessing.View[%d].Offset1 = %g;\n", num, v->Offset[1]);
  fprintf(file, "PostProcessing.View[%d].Offset2 = %g;\n", num, v->Offset[2]);
  fprintf(file, "PostProcessing.View[%d].Raise0 = %g;\n", num, v->Raise[0]);
  fprintf(file, "PostProcessing.View[%d].Raise1 = %g;\n", num, v->Raise[1]);
  fprintf(file, "PostProcessing.View[%d].Raise2 = %g;\n", num, v->Raise[2]);
  fprintf(file, "PostProcessing.View[%d].Color = { ", num);
  ColorTable_Print(&v->CT, file);
  fprintf(file, " };\n");

}

ColorTable *Get_ColorTableViewOption(int num){
  Post_View *v;

  if(num < 0 || num >= List_Nbr(Post_ViewList))
    return NULL ;
  v = (Post_View*)List_Pointer(Post_ViewList, num);
  return &v->CT ;
}

/* ------------------------------------------------------------------------ */
/*  R e a d _ V i e w                                                       */
/* ------------------------------------------------------------------------ */

extern int Force_ViewNumber;

void Read_View(FILE *file, char *filename){
  char   str[NAME_STR_L], name[NAME_STR_L];
  int    nb, format, testone, swap=0;
  double version;

  while (1) {

    do { 
      fgets(str, NAME_STR_L, file) ; 
      if (feof(file))  break ;
    } while (str[0] != '$') ;  

    if (feof(file))  break ;

    /*  F o r m a t  */

    if (!strncmp(&str[1], "PostFormat", 10)){
      fscanf(file, "%lf %d\n", &version, &format) ;
      if(version < 0.995){
        Msg(ERROR, "The Version of this File is too old (<0.995)");
        return;
      }
      if(format == 0) format = LIST_FORMAT_ASCII ;
      else if(format == 1) format = LIST_FORMAT_BINARY ;
      else Msg(FATAL, "Unknown Format for View");
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

      if(format == LIST_FORMAT_BINARY){
	fread(&testone, sizeof(int), 1, file);
	if(testone != 1){
	  Msg(INFOS, "Swapping Bytes from Binary File");
	  swap = 1;
	}
      }

      // Time values
      ActualView->Time = List_CreateFromFile(ActualView->NbTimeStep, 
					     sizeof(double), file, format, swap);

      // Points
      nb = ActualView->NbSP ? ActualView->NbSP * (ActualView->NbTimeStep  +3) : 0 ;
      ActualView->SP = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbVP ? ActualView->NbVP * (ActualView->NbTimeStep*3+3) : 0 ;
      ActualView->VP = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbTP ? ActualView->NbTP * (ActualView->NbTimeStep*9+3) : 0 ;
      ActualView->TP = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      // Lines
      nb = ActualView->NbSL ? ActualView->NbSL * (ActualView->NbTimeStep*2  +6) : 0 ;
      ActualView->SL = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbVL ? ActualView->NbVL * (ActualView->NbTimeStep*2*3+6) : 0 ;
      ActualView->VL = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbTL ? ActualView->NbTL * (ActualView->NbTimeStep*2*9+6) : 0 ;
      ActualView->TL = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      // Triangles
      nb = ActualView->NbST ? ActualView->NbST * (ActualView->NbTimeStep*3  +9) : 0 ;
      ActualView->ST = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbVT ? ActualView->NbVT * (ActualView->NbTimeStep*3*3+9) : 0 ;
      ActualView->VT = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbTT ? ActualView->NbTT * (ActualView->NbTimeStep*3*9+9) : 0 ;
      ActualView->TT = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      // Tetrahedra
      nb = ActualView->NbSS ? ActualView->NbSS * (ActualView->NbTimeStep*4  +12) : 0 ;
      ActualView->SS = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbVS ? ActualView->NbVS * (ActualView->NbTimeStep*4*3+12) : 0 ;
      ActualView->VS = List_CreateFromFile(nb, sizeof(double), file, format, swap);

      nb = ActualView->NbTS ? ActualView->NbTS * (ActualView->NbTimeStep*4*9+12) : 0 ;
      ActualView->TS = List_CreateFromFile(nb, sizeof(double), file, format, swap);

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

      EndView(1, Force_ViewNumber, filename, name, 0., 0., 0.); 
    }

    do {
      fgets(str, NAME_STR_L, file) ;
      if (feof(file)) Msg(ERROR,"Prematured End of File");
    } while (str[0] != '$') ;

  }   /* while 1 ... */

}

