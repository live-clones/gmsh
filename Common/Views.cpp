/* $Id: Views.cpp,v 1.2 2000-11-23 14:11:28 geuzaine Exp $ */

#include "Gmsh.h"
#include "Views.h"
#include "Context.h"
#include "ColorTable.h"

extern Context_T   CTX ;

extern List_T     *Post_ViewList;
extern double      LC;

static Post_View  *ActualView;
static int         ActualViewNum=0;

/* ------------------------------------------------------------------------ */
/*  V i e w s                                                               */
/* ------------------------------------------------------------------------ */

void AddView(int , char *, int);

void BeginView(int allocate){
  ActualView = (Post_View*)Malloc(sizeof(Post_View));
  ActualView->Num = ++ActualViewNum;
  ActualView->Changed = 1;
  if(allocate){
    ActualView->Allocated = 1;
    ActualView->Simplices = List_Create(100,100,sizeof(Post_Simplex));
    ActualView->Triangles = List_Create(100,100,sizeof(Post_Triangle));
    ActualView->Lines = List_Create(100,100,sizeof(Post_Line));
    ActualView->Points = List_Create(100,100,sizeof(Post_Point));
  }
  else{
    ActualView->Allocated = 0;
  }
  ActualView->NbIso = CTX.post.initial_nbiso;
  ActualView->IntervalsType = CTX.post.initial_intervals;
  ActualView->Light = 0;
  ActualView->ShowElement = 0;
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

void EndView(char *Name, double XOffset, double YOffset, double ZOffset){
  strcpy(ActualView->Name,Name);
  strcpy(ActualView->Format, "%.3e");
  ActualView->CustomMin = ActualView->Min;
  ActualView->CustomMax = ActualView->Max;

  ActualView->Offset[0] = XOffset*(CTX.range[0]?CTX.range[0]:LC)*1.e-3;
  ActualView->Offset[1] = YOffset*(CTX.range[1]?CTX.range[1]:LC)*1.e-3;
  ActualView->Offset[2] = ZOffset*(CTX.range[2]?CTX.range[2]:LC)*1.e-3;

  /* j'en alloue directement le max pour eviter les problemes avec 
   * CurrentView: cf. rem dans cb_post.c 
   */
  if(!Post_ViewList) 
    Post_ViewList = List_Create(20,1,sizeof(Post_View));

  List_Add(Post_ViewList,ActualView);
  
  AddView(List_Nbr(Post_ViewList), ActualView->Name, 1);
  ActualView = NULL;
}

/* ------------------------------------------------------------------------ */
/*  S i m p l e x                                                           */
/* ------------------------------------------------------------------------ */

void AddView_ScalarSimplex(double x0,double y0,double z0,
			   double x1,double y1,double z1,
			   double x2,double y2,double z2,
			   double x3,double y3,double z3,
			   List_T *v){
  Post_Simplex S;
  int i,N ;
  
  S.Type = DRAW_POST_SCALAR;
  S.X[0] = x0; S.X[1] = x1; S.X[2] = x2; S.X[3] = x3;
  S.Y[0] = y0; S.Y[1] = y1; S.Y[2] = y2; S.Y[3] = y3; 
  S.Z[0] = z0; S.Z[1] = z1; S.Z[2] = z2; S.Z[3] = z3; 

  N = List_Nbr(v);
  S.V = (double*)Malloc(N*sizeof(double));
  
  for(i=0 ; i<N ; i+=4){
    List_Read(v,i,  &S.V[i]) ;
    List_Read(v,i+1,&S.V[i+1]) ;
    List_Read(v,i+2,&S.V[i+2]) ;
    List_Read(v,i+3,&S.V[i+3]) ;

    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(DMIN(DMIN(S.V[i],S.V[i+1]),S.V[i+2]),S.V[i+3]);
      ActualView->Max = DMAX(DMAX(DMAX(S.V[i],S.V[i+1]),S.V[i+2]),S.V[i+3]);
      ActualView->NbTimeStep = N/4;
    }
    else{
      ActualView->Min = DMIN(DMIN(DMIN(DMIN(S.V[i],S.V[i+1]),S.V[i+2]),
				  S.V[i+3]),ActualView->Min);
      ActualView->Max = DMAX(DMAX(DMAX(DMAX(S.V[i],S.V[i+1]),S.V[i+2]),
				  S.V[i+3]),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/4,ActualView->NbTimeStep);
    }
  }
  
  List_Add(ActualView->Simplices,&S);
}

void AddView_VectorSimplex(double x0,double y0,double z0,
			   double x1,double y1,double z1,
			   double x2,double y2,double z2,
			   double x3,double y3,double z3,
			   List_T *v){
  Post_Simplex S;
  double l0,l1,l2,l3;
  int i,N ;
    
  S.Type = DRAW_POST_VECTOR;
  S.X[0] = x0; S.X[1] = x1; S.X[2] = x2; S.X[3] = x3;
  S.Y[0] = y0; S.Y[1] = y1; S.Y[2] = y2; S.Y[3] = y3;
  S.Z[0] = z0; S.Z[1] = z1; S.Z[2] = z2; S.Z[3] = z3;

  N = List_Nbr(v);
  S.V = (double*)Malloc(N*sizeof(double));
  
  for(i=0 ; i<N ; i+=12){
    List_Read(v,i,  &S.V[i]);   List_Read(v,i+1,&S.V[i+1]);   List_Read(v,i+2,&S.V[i+2]);
    List_Read(v,i+3,&S.V[i+3]); List_Read(v,i+4,&S.V[i+4]);   List_Read(v,i+5,&S.V[i+5]);
    List_Read(v,i+6,&S.V[i+6]); List_Read(v,i+7,&S.V[i+7]);   List_Read(v,i+8,&S.V[i+8]);
    List_Read(v,i+9,&S.V[i+9]); List_Read(v,i+10,&S.V[i+10]); List_Read(v,i+11,&S.V[i+11]);
    
    l0 = sqrt(S.V[i]  *S.V[i]  +S.V[i+1]*S.V[i+1]  +S.V[i+2]*S.V[i+2]);
    l1 = sqrt(S.V[i+3]*S.V[i+3]+S.V[i+4]*S.V[i+4]  +S.V[i+5]*S.V[i+5]);
    l2 = sqrt(S.V[i+6]*S.V[i+6]+S.V[i+7]*S.V[i+7]  +S.V[i+8]*S.V[i+8]);
    l3 = sqrt(S.V[i+9]*S.V[i+9]+S.V[i+10]*S.V[i+10]+S.V[i+11]*S.V[i+11]);
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(DMIN(DMIN(l0,l1),l2),l3);
      ActualView->Max = DMAX(DMAX(DMAX(l0,l1),l2),l3);
      ActualView->NbTimeStep = N/12;
    }
    else{
      ActualView->Min = DMIN(DMIN(DMIN(DMIN(l0,l1),l2),l3),ActualView->Min);
      ActualView->Max = DMAX(DMAX(DMAX(DMAX(l0,l1),l2),l3),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/12,ActualView->NbTimeStep);
    }
  }

  ActualView->ScalarOnly = 0;
  List_Add(ActualView->Simplices,&S);
}

void AddView_TensorSimplex(double x0,double y0,double z0,
			   double x1,double y1,double z1,
			   double x2,double y2,double z2,
			   double x3,double y3,double z3,
			   List_T *v){
}


/* ------------------------------------------------------------------------ */
/*  T r i a n g l e                                                         */
/* ------------------------------------------------------------------------ */

void AddView_ScalarTriangle(double x0,double y0,double z0,
			    double x1,double y1,double z1,
			    double x2,double y2,double z2,
			    List_T *v){
  Post_Triangle T;
  int i,N ;
  
  T.Type = DRAW_POST_SCALAR;
  T.X[0] = x0; T.X[1] = x1; T.X[2] = x2;
  T.Y[0] = y0; T.Y[1] = y1; T.Y[2] = y2;
  T.Z[0] = z0; T.Z[1] = z1; T.Z[2] = z2;

  N = List_Nbr(v);
  T.V = (double*)Malloc(N*sizeof(double));
  
  for(i=0 ; i<N ; i+=3){
    List_Read(v,i,  &T.V[i]) ;
    List_Read(v,i+1,&T.V[i+1]) ;
    List_Read(v,i+2,&T.V[i+2]) ;

    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(DMIN(T.V[i],T.V[i+1]),T.V[i+2]);
      ActualView->Max = DMAX(DMAX(T.V[i],T.V[i+1]),T.V[i+2]);
      ActualView->NbTimeStep = N/3;
    }
    else{
      ActualView->Min = DMIN(DMIN(DMIN(T.V[i],T.V[i+1]),T.V[i+2]),ActualView->Min);
      ActualView->Max = DMAX(DMAX(DMAX(T.V[i],T.V[i+1]),T.V[i+2]),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/3,ActualView->NbTimeStep);
    }
  }
  
  List_Add(ActualView->Triangles,&T);
}

void AddView_VectorTriangle(double x0,double y0,double z0,
			    double x1,double y1,double z1,
			    double x2,double y2,double z2,
			    List_T *v){
  Post_Triangle T;
  double l0,l1,l2;
  int i,N ;
    
  T.Type = DRAW_POST_VECTOR;
  T.X[0] = x0; T.X[1] = x1; T.X[2] = x2;
  T.Y[0] = y0; T.Y[1] = y1; T.Y[2] = y2;
  T.Z[0] = z0; T.Z[1] = z1; T.Z[2] = z2;

  N = List_Nbr(v);
  T.V = (double*)Malloc(N*sizeof(double));
  
  for(i=0 ; i<N ; i+=9){
    List_Read(v,i,  &T.V[i]);   List_Read(v,i+1,&T.V[i+1]); List_Read(v,i+2,&T.V[i+2]);
    List_Read(v,i+3,&T.V[i+3]); List_Read(v,i+4,&T.V[i+4]); List_Read(v,i+5,&T.V[i+5]);
    List_Read(v,i+6,&T.V[i+6]); List_Read(v,i+7,&T.V[i+7]); List_Read(v,i+8,&T.V[i+8]);
    
    l0 = sqrt(T.V[i]  *T.V[i]  +T.V[i+1]*T.V[i+1]+T.V[i+2]*T.V[i+2]);
    l1 = sqrt(T.V[i+3]*T.V[i+3]+T.V[i+4]*T.V[i+4]+T.V[i+5]*T.V[i+5]);
    l2 = sqrt(T.V[i+6]*T.V[i+6]+T.V[i+7]*T.V[i+7]+T.V[i+8]*T.V[i+8]);
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(DMIN(l0,l1),l2);
      ActualView->Max = DMAX(DMAX(l0,l1),l2);
      ActualView->NbTimeStep = N/9;
    }
    else{
      ActualView->Min = DMIN(DMIN(DMIN(l0,l1),l2),ActualView->Min);
      ActualView->Max = DMAX(DMAX(DMAX(l0,l1),l2),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/9,ActualView->NbTimeStep);
    }
  }

  ActualView->ScalarOnly = 0;
  List_Add(ActualView->Triangles,&T);
}

void AddView_TensorTriangle(double x0,double y0,double z0,
			    double x1,double y1,double z1,
			    double x2,double y2,double z2,
			    List_T *v){
  Post_Triangle T;
  double l0,l1,l2;
  int i,N ;
    
  T.Type = DRAW_POST_TENSOR;
  T.X[0] = x0; T.X[1] = x1; T.X[2] = x2;
  T.Y[0] = y0; T.Y[1] = y1; T.Y[2] = y2;
  T.Z[0] = z0; T.Z[1] = z1; T.Z[2] = z2;

  N = List_Nbr(v);
  T.V = (double*)Malloc(N*sizeof(double));
  
  for(i=0 ; i<N ; i+=27){
    List_Read(v,i,  &T.V[i]);     List_Read(v,i+1,&T.V[i+1]);   List_Read(v,i+2,&T.V[i+2]);
    List_Read(v,i+3,&T.V[i+3]);   List_Read(v,i+4,&T.V[i+4]);   List_Read(v,i+5,&T.V[i+5]);
    List_Read(v,i+6,&T.V[i+6]);   List_Read(v,i+7,&T.V[i+7]);   List_Read(v,i+8,&T.V[i+8]);
    List_Read(v,i+9,&T.V[i+9]);   List_Read(v,i+10,&T.V[i+10]); List_Read(v,i+11,&T.V[i+11]);
    List_Read(v,i+12,&T.V[i+12]); List_Read(v,i+13,&T.V[i+13]); List_Read(v,i+14,&T.V[i+14]);
    List_Read(v,i+15,&T.V[i+15]); List_Read(v,i+16,&T.V[i+16]); List_Read(v,i+17,&T.V[i+17]);
    List_Read(v,i+18,&T.V[i+18]); List_Read(v,i+19,&T.V[i+19]); List_Read(v,i+20,&T.V[i+20]);
    List_Read(v,i+21,&T.V[i+21]); List_Read(v,i+22,&T.V[i+22]); List_Read(v,i+23,&T.V[i+23]);
    List_Read(v,i+24,&T.V[i+24]); List_Read(v,i+25,&T.V[i+25]); List_Read(v,i+26,&T.V[i+26]);
    
    l0 = sqrt(T.V[i]  *T.V[i]  +T.V[i+1]*T.V[i+1]+T.V[i+2]*T.V[i+2]);
    l1 = sqrt(T.V[i+3]*T.V[i+3]+T.V[i+4]*T.V[i+4]+T.V[i+5]*T.V[i+5]);
    l2 = sqrt(T.V[i+6]*T.V[i+6]+T.V[i+7]*T.V[i+7]+T.V[i+8]*T.V[i+8]);
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(DMIN(l0,l1),l2);
      ActualView->Max = DMAX(DMAX(l0,l1),l2);
      ActualView->NbTimeStep = N/9;
    }
    else{
      ActualView->Min = DMIN(DMIN(DMIN(l0,l1),l2),ActualView->Min);
      ActualView->Max = DMAX(DMAX(DMAX(l0,l1),l2),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/9,ActualView->NbTimeStep);
    }
  }

  ActualView->ScalarOnly = 0;
  List_Add(ActualView->Triangles,&T);
}

/* ------------------------------------------------------------------------ */
/*  L i n e                                                                 */
/* ------------------------------------------------------------------------ */

void AddView_ScalarLine(double x0,double y0,double z0,
			double x1,double y1,double z1,
			List_T *v){
  Post_Line L;
  int i,N ;
  
  L.Type = DRAW_POST_SCALAR;
  L.X[0] = x0; L.X[1] = x1;  
  L.Y[0] = y0; L.Y[1] = y1;  
  L.Z[0] = z0; L.Z[1] = z1;  

  N = List_Nbr(v);
  L.V = (double*)Malloc(N*sizeof(double));
  
  for(i=0 ; i<N ; i+=2){
    List_Read(v,i,&L.V[i]) ;
    List_Read(v,i+1,&L.V[i+1]) ;
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(L.V[i],L.V[i+1]);
      ActualView->Max = DMAX(L.V[i],L.V[i+1]);
      ActualView->NbTimeStep = N/2;
    }
    else{
      ActualView->Min = DMIN(DMIN(L.V[i],L.V[i+1]),ActualView->Min);
      ActualView->Max = DMAX(DMAX(L.V[i],L.V[i+1]),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/2,ActualView->NbTimeStep);
    }
  }

  List_Add(ActualView->Lines,&L);
}


void AddView_VectorLine(double x0,double y0,double z0,
			double x1,double y1,double z1,
			List_T *v){
  Post_Line L;
  double l0,l1;
  int i,N ;
  
  L.Type = DRAW_POST_VECTOR;
  L.X[0] = x0; L.X[1] = x1; 
  L.Y[0] = y0; L.Y[1] = y1; 
  L.Z[0] = z0; L.Z[1] = z1; 

  N = List_Nbr(v);
  L.V = (double*)Malloc(N*sizeof(double));

  for(i=0 ; i<N ; i+=6){
    List_Read(v,i,  &L.V[i]);   List_Read(v,i+1,&L.V[i+1]); 
    List_Read(v,i+2,&L.V[i+2]); List_Read(v,i+3,&L.V[i+3]); 
    List_Read(v,i+4,&L.V[i+4]); List_Read(v,i+5,&L.V[i+5]); 

    l0 = sqrt(L.V[i]  *L.V[i]  +L.V[i+1]*L.V[i+1]+L.V[i+2]*L.V[i+2]);
    l1 = sqrt(L.V[i+3]*L.V[i+3]+L.V[i+4]*L.V[i+4]+L.V[i+5]*L.V[i+5]);
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = DMIN(l0,l1);
      ActualView->Max = DMAX(l0,l1);
      ActualView->NbTimeStep = N/6;
    }
    else{
      ActualView->Min = DMIN(DMIN(l0,l1),ActualView->Min);
      ActualView->Max = DMAX(DMAX(l0,l1),ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/6,ActualView->NbTimeStep);
    }
  }
 
  ActualView->ScalarOnly = 0;
  List_Add(ActualView->Lines,&L);
}

void AddView_TensorLine(double x0,double y0,double z0,
			double x1,double y1,double z1,
			List_T *v){
}


/* ------------------------------------------------------------------------ */
/*  P o i n t                                                               */
/* ------------------------------------------------------------------------ */

void AddView_ScalarPoint(double x0,double y0,double z0,
			 List_T *v){
  Post_Point P;
  double l;
  int i,N ;
  
  P.Type = DRAW_POST_SCALAR; 
  P.X = x0; 
  P.Y = y0; 
  P.Z = z0; 

  N = List_Nbr(v); 
  P.V = (double*)Malloc(N*sizeof(double));

  for(i=0 ; i<N ; i++){
    List_Read(v,i,  &P.V[i]); 
    l = P.V[i];
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = l;
      ActualView->Max = l;
      ActualView->NbTimeStep = N/3;
    }
    else{
      ActualView->Min = DMIN(l,ActualView->Min);
      ActualView->Max = DMAX(l,ActualView->Max);
      ActualView->NbTimeStep = IMIN(N,ActualView->NbTimeStep);
    }
  }

  ActualView->ScalarOnly = 1;
  List_Add(ActualView->Points,&P);
}


void AddView_VectorPoint(double x0,double y0,double z0,
			 List_T *v){
  Post_Point P;
  double l;
  int i,N ;
  
  P.Type = DRAW_POST_VECTOR; 
  P.X = x0; 
  P.Y = y0; 
  P.Z = z0; 

  N = List_Nbr(v); 
  P.V = (double*)Malloc(N*sizeof(double));

  for(i=0 ; i<N ; i+=3){
    List_Read(v,i,  &P.V[i]); 
    List_Read(v,i+1,&P.V[i+1]); 
    List_Read(v,i+2,&P.V[i+2]); 

    l = sqrt(P.V[i]*P.V[i] + P.V[i+1]*P.V[i+1] + P.V[i+2]*P.V[i+2]);
    if(!List_Nbr(ActualView->Points) && 
       !List_Nbr(ActualView->Lines) && 
       !List_Nbr(ActualView->Triangles) &&
       !List_Nbr(ActualView->Simplices)){
      ActualView->Min = l;
      ActualView->Max = l;
      ActualView->NbTimeStep = N/3;
    }
    else{
      ActualView->Min = DMIN(l,ActualView->Min);
      ActualView->Max = DMAX(l,ActualView->Max);
      ActualView->NbTimeStep = IMIN(N/3,ActualView->NbTimeStep);
    }
  }

  ActualView->ScalarOnly = 0;
  List_Add(ActualView->Points,&P);
}

void AddView_TensorPoint(double x0,double y0,double z0,
			 List_T *v){
}

