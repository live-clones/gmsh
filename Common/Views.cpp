/* $Id: Views.cpp,v 1.4 2000-11-25 23:10:37 geuzaine Exp $ */

#include "Gmsh.h"
#include "Views.h"
#include "Context.h"
#include "ColorTable.h"

List_T  *Post_ViewList = NULL;
Post_View  *ActualView;

extern Context_T   CTX ;
extern double      LC;

static int         ActualViewNum=0;

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

  ActualView->NbSP = ActualView->NbVP = ActualView->NbTP = 0;
  ActualView->NbSL = ActualView->NbVL = ActualView->NbTL = 0;
  ActualView->NbST = ActualView->NbVT = ActualView->NbTT = 0;
  ActualView->NbSS = ActualView->NbVS = ActualView->NbTS = 0;

  if(allocate){
    ActualView->Time = List_Create(100,1000,sizeof(double));

    ActualView->SP = List_Create(100,1000,sizeof(double));
    ActualView->VP = List_Create(100,1000,sizeof(double));
    ActualView->TP = List_Create(100,1000,sizeof(double));
    ActualView->Points = List_Create(100,1000,sizeof(Post_Simplex));
    
    ActualView->SL = List_Create(100,1000,sizeof(double));
    ActualView->VL = List_Create(100,1000,sizeof(double));
    ActualView->TL = List_Create(100,1000,sizeof(double));
    ActualView->Lines = List_Create(100,1000,sizeof(Post_Simplex));
    
    ActualView->ST = List_Create(100,1000,sizeof(double));
    ActualView->VT = List_Create(100,1000,sizeof(double));
    ActualView->TT = List_Create(100,1000,sizeof(double));
    ActualView->Triangles = List_Create(100,1000,sizeof(Post_Simplex));
    
    ActualView->SS = List_Create(100,1000,sizeof(double));
    ActualView->VS = List_Create(100,1000,sizeof(double));
    ActualView->TS = List_Create(100,1000,sizeof(double));
    ActualView->Tetrahedra = List_Create(100,1000,sizeof(Post_Simplex));
  }

  ActualView->Changed = 1;
  ActualView->Links = 0;
  ActualView->DuplicateOf = 0;
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
  ActualView->Min = 1.e200;
  ActualView->Max = -1.e200;
  ActualView->NbTimeStep = 0;

  ActualView->CT.size = 255;
  ActualView->CT.ipar[COLORTABLE_MODE] = COLORTABLE_RGB;
  color_table_init_param(1, &ActualView->CT, 1, 1);
  color_table_recompute(&ActualView->CT, 1, 1);
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
      AddView_ScalarSimplex(0, (double*)List_Pointer(ActualView->SP,i),
			    nb-3, (double*)List_Pointer(ActualView->SP,i+3));
  }
  if(ActualView->NbVP){
    nb = List_Nbr(ActualView->VP) / ActualView->NbVP ;
    for(i = 0 ; i < List_Nbr(ActualView->VP) ; i+=nb)
      AddView_VectorSimplex(0, (double*)List_Pointer(ActualView->VP,i),
			    nb-3, (double*)List_Pointer(ActualView->VP,i+3));
  }
  if(ActualView->NbTP){
    nb = List_Nbr(ActualView->TP) / ActualView->NbTP ;
    for(i = 0 ; i < List_Nbr(ActualView->TP) ; i+=nb)
      AddView_TensorSimplex(0, (double*)List_Pointer(ActualView->TP,i),
			    nb-3, (double*)List_Pointer(ActualView->TP,i+3));
  }

  // Lines

  if(ActualView->NbSL){
    nb = List_Nbr(ActualView->SL) / ActualView->NbSL ;
    for(i = 0 ; i < List_Nbr(ActualView->SL) ; i+=nb)
      AddView_ScalarSimplex(1, (double*)List_Pointer(ActualView->SL,i),
			    nb-6, (double*)List_Pointer(ActualView->SL,i+6));
  }
  if(ActualView->NbVL){
    nb = List_Nbr(ActualView->VL) / ActualView->NbVL ;
    for(i = 0 ; i < List_Nbr(ActualView->VL) ; i+=nb)
      AddView_VectorSimplex(1, (double*)List_Pointer(ActualView->VL,i),
			    nb-6, (double*)List_Pointer(ActualView->VL,i+6));
  }
  if(ActualView->NbTL){
    nb = List_Nbr(ActualView->TL) / ActualView->NbTL ;
    for(i = 0 ; i < List_Nbr(ActualView->TL) ; i+=nb)
      AddView_TensorSimplex(1, (double*)List_Pointer(ActualView->TL,i),
			    nb-6, (double*)List_Pointer(ActualView->TL,i+6));
  }

  // Triangles

  if(ActualView->NbST){
    nb = List_Nbr(ActualView->ST) / ActualView->NbST ;
    for(i = 0 ; i < List_Nbr(ActualView->ST) ; i+=nb)
      AddView_ScalarSimplex(2, (double*)List_Pointer(ActualView->ST,i),
			    nb-9, (double*)List_Pointer(ActualView->ST,i+9));
  }
  if(ActualView->NbVT){
    nb = List_Nbr(ActualView->VT) / ActualView->NbVT ;
    for(i = 0 ; i < List_Nbr(ActualView->VT) ; i+=nb)
      AddView_VectorSimplex(2, (double*)List_Pointer(ActualView->VT,i),
			    nb-9, (double*)List_Pointer(ActualView->VT,i+9));
  }
  if(ActualView->NbTT){
    nb = List_Nbr(ActualView->TT) / ActualView->NbTT ;
    for(i = 0 ; i < List_Nbr(ActualView->TT) ; i+=nb)
      AddView_TensorSimplex(2, (double*)List_Pointer(ActualView->TT,i),
			    nb-9, (double*)List_Pointer(ActualView->TT,i+9));
  }

  // Tetrahedra

  if(ActualView->NbSS){
    nb = List_Nbr(ActualView->SS) / ActualView->NbSS ;
    for(i = 0 ; i < List_Nbr(ActualView->SS) ; i+=nb)
      AddView_ScalarSimplex(3, (double*)List_Pointer(ActualView->SS,i),
			    nb-12, (double*)List_Pointer(ActualView->SS,i+12));
  }
  if(ActualView->NbVS){
    nb = List_Nbr(ActualView->VS) / ActualView->NbVS ;
    for(i = 0 ; i < List_Nbr(ActualView->VS) ; i+=nb)
      AddView_VectorSimplex(3, (double*)List_Pointer(ActualView->VS,i),
			    nb-12, (double*)List_Pointer(ActualView->VS,i+12));
  }
  if(ActualView->NbTS){
    nb = List_Nbr(ActualView->TS) / ActualView->NbTS ;
    for(i = 0 ; i < List_Nbr(ActualView->TS) ; i+=nb)
      AddView_TensorSimplex(3, (double*)List_Pointer(ActualView->TS,i),
			    nb-12, (double*)List_Pointer(ActualView->TS,i+12));
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
  ActualView->Offset[0] = XOffset*(CTX.range[0]?CTX.range[0]:LC)*1.e-3;
  ActualView->Offset[1] = YOffset*(CTX.range[1]?CTX.range[1]:LC)*1.e-3;
  ActualView->Offset[2] = ZOffset*(CTX.range[2]?CTX.range[2]:LC)*1.e-3;

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
    List_Delete(v->Points);

    List_Delete(v->SL); List_Delete(v->VL); List_Delete(v->TL);
    List_Delete(v->Lines);

    List_Delete(v->ST); List_Delete(v->VT); List_Delete(v->TT);
    List_Delete(v->Triangles);

    List_Delete(v->SS); List_Delete(v->VS); List_Delete(v->TS);
    List_Delete(v->Tetrahedra);   
  }

}


/* ------------------------------------------------------------------------ */
/*  S c a l a r S i m p l e x                                               */
/* ------------------------------------------------------------------------ */

void AddView_ScalarSimplex(int dim, double *coord, int N, double *v){
  Post_Simplex S;
  int i,nbnod;

  S.Type = DRAW_POST_SCALAR;
  S.Dimension = dim;

  switch(dim){
  case 0 : nbnod = 1 ; break; // point
  case 1 : nbnod = 2 ; break; // line
  case 2 : nbnod = 3 ; break; // triangle
  case 3 : nbnod = 4 ; break; // tetrahedron
  }

  S.X = &coord[0] ; S.Y = &coord[nbnod] ; S.Z = &coord[2*nbnod] ; S.V = v ;

  if(!List_Nbr(ActualView->Points) &&    !List_Nbr(ActualView->Lines) && 
     !List_Nbr(ActualView->Triangles) && !List_Nbr(ActualView->Tetrahedra)){
    ActualView->Min = S.V[0];
    ActualView->Max = S.V[0];
    ActualView->NbTimeStep = N/nbnod;
  }
  else if(N/nbnod < ActualView->NbTimeStep)
    ActualView->NbTimeStep = N/nbnod ;

  for(i=0 ; i<N ; i++){
    if(S.V[i] < ActualView->Min) ActualView->Min = S.V[i] ;
    if(S.V[i] > ActualView->Max) ActualView->Max = S.V[i] ;
  }

  switch(dim){
  case 0 : List_Add(ActualView->Points,&S); break;
  case 1 : List_Add(ActualView->Lines,&S); break;
  case 2 : List_Add(ActualView->Triangles,&S); break;
  case 3 : List_Add(ActualView->Tetrahedra,&S); break;
  }
  
}

void AddView_VectorSimplex(int dim, double *coord, int N, double *v){
  Post_Simplex S;
  double l0;
  int nbnod, i;
    
  S.Type = DRAW_POST_VECTOR;
  S.Dimension = dim;

  switch(dim){
  case 0 : nbnod = 1 ; break; // point
  case 1 : nbnod = 2 ; break; // line
  case 2 : nbnod = 3 ; break; // triangle
  case 3 : nbnod = 4 ; break; // tetrahedron
  }

  S.X = &coord[0] ; S.Y = &coord[nbnod] ; S.Z = &coord[2*nbnod] ; S.V = v ;

  if(!List_Nbr(ActualView->Points) &&    !List_Nbr(ActualView->Lines) && 
     !List_Nbr(ActualView->Triangles) && !List_Nbr(ActualView->Tetrahedra)){
    l0 = sqrt(DSQR(S.V[0])+DSQR(S.V[1])+DSQR(S.V[2]));
    ActualView->Min = l0;
    ActualView->Max = l0;
    ActualView->NbTimeStep = N/(3*nbnod) ;
  }
  else if(N/(3*nbnod) < ActualView->NbTimeStep)
    ActualView->NbTimeStep = N/(3*nbnod) ;

  for(i=0 ; i<N ; i+=3){
    l0 = sqrt(DSQR(S.V[i])+DSQR(S.V[i+1])+DSQR(S.V[i+2]));
    if(l0 < ActualView->Min) ActualView->Min = l0 ;
    if(l0 > ActualView->Max) ActualView->Max = l0 ;
  }

  ActualView->ScalarOnly = 0;

  switch(dim){
  case 0 : List_Add(ActualView->Points,&S); break;
  case 1 : List_Add(ActualView->Lines,&S); break;
  case 2 : List_Add(ActualView->Triangles,&S); break;
  case 3 : List_Add(ActualView->Tetrahedra,&S); break;
  }
}

void AddView_TensorSimplex(int dim, double *coord, int N, double *v){
  Msg(ERROR, "Tensor Field Views not Implemented Yet");
}


/* ------------------------------------------------------------------------ */
/*  R e a d _ V i e w                                                       */
/* ------------------------------------------------------------------------ */

extern int Force_ViewNumber;

void Read_View(FILE *file, char *filename){
  char   str[NAME_STR_L], name[NAME_STR_L];
  int    nb, format, nbtimestep;
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
	     name, &nbtimestep,
	     &ActualView->NbSP, &ActualView->NbVP, &ActualView->NbTP, 
	     &ActualView->NbSL, &ActualView->NbVL, &ActualView->NbTL, 
	     &ActualView->NbST, &ActualView->NbVT, &ActualView->NbTT, 
	     &ActualView->NbSS, &ActualView->NbVS, &ActualView->NbTS);

      Msg(DEBUG, "View '%s' (%d TimeSteps): %d %d %d %d %d %d %d %d %d %d %d %d",
	  name, nbtimestep,
	  ActualView->NbSP, ActualView->NbVP, ActualView->NbTP, 
	  ActualView->NbSL, ActualView->NbVL, ActualView->NbTL, 
	  ActualView->NbST, ActualView->NbVT, ActualView->NbTT, 
	  ActualView->NbSS, ActualView->NbVS, ActualView->NbTS);

      ActualView->Time = List_CreateFromFile(nbtimestep, sizeof(double), file, format);

      if((nb = ActualView->NbSP + ActualView->NbVP + ActualView->NbTP))
	ActualView->Points = List_Create(nb,1,sizeof(Post_Simplex));
      else
	ActualView->Points = NULL ;
      nb = ActualView->NbSP ? 
	ActualView->NbSP * nbtimestep     + ActualView->NbSP * 3 : 0 ;
      ActualView->SP = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbVP ?
	ActualView->NbVP * nbtimestep * 3 + ActualView->NbVP * 3 : 0 ;
      ActualView->VP = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbTP ? 
	ActualView->NbTP * nbtimestep * 9 + ActualView->NbTP * 3 : 0 ;
      ActualView->TP = List_CreateFromFile(nb, sizeof(double), file, format);

      if((nb = ActualView->NbSL + ActualView->NbVL + ActualView->NbTL))
	ActualView->Lines = List_Create(nb,1,sizeof(Post_Simplex));
      else
	ActualView->Lines = NULL ;
      nb = ActualView->NbSL ? 
	ActualView->NbSL * nbtimestep * 2     + ActualView->NbSL * 6 : 0 ;
      ActualView->SL = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbVL ?
	ActualView->NbVL * nbtimestep * 2 * 3 + ActualView->NbVL * 6 : 0 ;
      ActualView->VL = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbTL ?
	ActualView->NbTL * nbtimestep * 2 * 9 + ActualView->NbTL * 6 : 0 ;
      ActualView->TL = List_CreateFromFile(nb, sizeof(double), file, format);

      if((nb = ActualView->NbST + ActualView->NbVT + ActualView->NbTT))
	ActualView->Triangles = List_Create(nb,1,sizeof(Post_Simplex));
      else
	ActualView->Triangles = NULL ;
      nb = ActualView->NbST ? 
	ActualView->NbST * nbtimestep * 3     + ActualView->NbST * 9 : 0 ;
      ActualView->ST = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbVT ? 
	ActualView->NbVT * nbtimestep * 3 * 3 + ActualView->NbVT * 9 : 0 ;
      ActualView->VT = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbTT ? 
	ActualView->NbTT * nbtimestep * 3 * 9 + ActualView->NbTT * 9 : 0 ;
      ActualView->TT = List_CreateFromFile(nb, sizeof(double), file, format);

      if((nb = ActualView->NbSS + ActualView->NbVS + ActualView->NbTS))
	ActualView->Tetrahedra = List_Create(nb,1,sizeof(Post_Simplex));
      else
	ActualView->Tetrahedra = NULL ;
      nb = ActualView->NbSS ?
	ActualView->NbSS * nbtimestep * 4     + ActualView->NbSS * 12 : 0 ;
      ActualView->SS = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbVS ? 
	ActualView->NbVS * nbtimestep * 4 * 3 + ActualView->NbVS * 12 : 0 ;
      ActualView->VS = List_CreateFromFile(nb, sizeof(double), file, format);
      nb = ActualView->NbTS ?
	ActualView->NbTS * nbtimestep * 4 * 9 + ActualView->NbTS * 12 : 0 ;
      ActualView->TS = List_CreateFromFile(nb, sizeof(double), file, format);

      Msg(DEBUG, "Read View '%s' (%d TimeSteps): %d %d %d %d %d %d %d %d %d %d %d %d",
	  name, nbtimestep,
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
