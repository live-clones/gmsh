// $Id: DataBase.cpp,v 1.23 2003-02-25 04:02:50 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "CAD.h"
#include "Create.h"
#include "Verif.h"
#include "Context.h"

extern Context_T  CTX ;
extern Mesh      *THEM;

// Points

void Cdbpts101(int ip, double x, double y, double z, double l, double w){
  Vertex *v;
  v = Create_Vertex(ip,
		    CTX.geom.scaling_factor*x,
		    CTX.geom.scaling_factor*y,
		    CTX.geom.scaling_factor*z,
		    CTX.geom.scaling_factor*l,
		    0.0);
  v->w = w;
  Tree_Insert(THEM->Points,&v);
}

// Curves

void AddCurveInDataBase (int NumCurve, int TypCurve, int Order,
                         List_T *ControlPoints, List_T *Knots,
                         int VertexBeg, int VertexEnd,
                         double uBeg, double uEnd){
  Curve *c;

  if(NumCurve<0) return; /* Negative Curves are reversed from positive ones*/

  c = Create_Curve(NumCurve,TypCurve,Order,ControlPoints,Knots,
                   VertexBeg,VertexEnd,uBeg,uEnd);

  // curve in reverse direction
  
  Curve *rc = CreateReversedCurve(THEM,c);
  Tree_Insert(THEM->Curves,&c);
  Tree_Insert(THEM->Curves,&rc);
}

void AddCircleInDataBase (int NumCurve, int TypCurve, List_T *ControlPoints,
                          double n[3]){
  Curve *c;
  
  if(NumCurve<0) return; /* Negative Curves are reversed from positive ones*/

  c = Create_Curve(NumCurve,TypCurve,2,ControlPoints,NULL,-1,-1,0.,1.);

  c->Circle.n[0] = n[0];
  c->Circle.n[1] = n[1];
  c->Circle.n[2] = n[2];
  
  End_Curve(c);

  // curve in reverse direction
  
  Curve *rc = CreateReversedCurve(THEM,c);
  
  rc->Circle.n[0] = n[0];
  rc->Circle.n[1] = n[1];
  rc->Circle.n[2] = n[2];
  End_Curve(rc);
  
  Tree_Insert(THEM->Curves,&c);
  Tree_Insert(THEM->Curves,&rc);
}

void Cdbseg101(int iseg, int typseg, int degre, List_T *liste, List_T *listint,
               int i1,int i2,double u1 ,double u2,char *c1, char *c2, char *c3){
  int i,j;
  double d;
  List_T *Temp;
  if(listint){
    AddCurveInDataBase (iseg,typseg,degre,listint,NULL,i1,i2,u1,u2);
  }
  else{
    Temp = List_Create(List_Nbr(liste),1,sizeof(int));
    for(i=0;i<List_Nbr(liste);i++){
      List_Read(liste,i,&d);
      j = (int)d;
      List_Add(Temp,&j);
    }
    AddCurveInDataBase (iseg,typseg,degre,Temp,NULL,i1,i2,u1,u2);
    List_Delete(Temp);
  }
  
}


// Surfaces and volumes

void AddQuadricSurfaceInDataBase (int Typ, int NumQuadric, double zaxis[3],
                                  double xaxis[3], double center[3],
                                  double radius1, double radius2, List_T *loops){
  int ic,i,j,NbLoop,iLoop;
  Surface *s;
  Curve *c;
  EdgeLoop *el;
  
  s = Create_Surface(NumQuadric,Typ);
  s->Method = LIBRE;
  for(i=0;i<3;i++)s->Cyl.xaxis[i] = xaxis[i];
  for(i=0;i<3;i++)s->Cyl.zaxis[i] = zaxis[i];
  for(i=0;i<3;i++)s->Cyl.center[i] = center[i];
  s->Cyl.radius1 = radius1;
  s->Cyl.radius2 = radius2;
  s->Generatrices = List_Create(4, 1, sizeof(Curve*));

  NbLoop = List_Nbr(loops);
  s->Generatrices = List_Create(4, 1, sizeof(Curve*));
  for(i=0;i<NbLoop;i++){
    List_Read(loops,i,&iLoop);
    if(!(el = FindEdgeLoop(iLoop,THEM))){
      Msg(GERROR, "Unknown Line Loop %d", iLoop);
      List_Delete(s->Generatrices);
      Free(s);
      return;
    }
    else{
      for(j=0;j<List_Nbr(el->Curves);j++){
        List_Read(el->Curves,j,&ic);
        if(!(c = FindCurve(ic,THEM))){
          Msg(GERROR, "Unknown Curve %d", ic);
	  List_Delete(s->Generatrices);
	  Free(s);
	  return;
	}
        else
          List_Add (s->Generatrices, &c);
      }
    }
  }
  s->Support = s;
  End_Surface(s);
  Tree_Insert (THEM->Surfaces , &s);
}

void CreateSurfaceFromOldCrappyDatabase (int izon, int typzon, int o1, int o2,
                                         int nbu, int nbv, int sup,
                                         List_T *liste, List_T *loops, Mesh *M){
  int      ic,i,j,l,NbLoop,iLoop;
  Surface *s,*pS;
  Curve   *c;
  Vertex V,*v;
  EdgeLoop *el;

  s = Create_Surface(izon,typzon);
  s->Method = LIBRE;
  
  NbLoop = List_Nbr(loops);
  s->Generatrices = List_Create(4, 1, sizeof(Curve*));
  for(i=0;i<NbLoop;i++){
    List_Read(loops,i,&iLoop);
    if(!(el = FindEdgeLoop(iLoop,THEM))){
      Msg(GERROR, "Unknown Line Loop %d", iLoop);
      List_Delete(s->Generatrices);
      Free(s);
      return;
    }	  
    else{
      for(j=0;j<List_Nbr(el->Curves);j++){
        List_Read(el->Curves,j,&ic);
        if(!(c = FindCurve(ic,THEM))){
          Msg(GERROR, "Unknown Curve %d", ic);
	  List_Delete(s->Generatrices);
	  Free(s);
	  return;
	}
        else
          List_Add (s->Generatrices, &c);
      }
    }
  }
  
  if((pS = FindSurface(sup,THEM))){
    s->Support = pS;
  }
  else{
    s->Support = s;
  }

  if(typzon == MSH_SURF_NURBS && !pS){
    s->Control_Points = List_Create(4, 1, sizeof(Vertex*));
    s->OrderU = o1;
    s->OrderV = o2;
    s->Nu = nbu;
    s->Nv = nbv;
    for(l=0;l<List_Nbr(liste);l++){
      List_Read(liste,l,&iLoop);
      v = &V;
      v->Num = iLoop;
      List_Add (s->Control_Points, Tree_PQuery(M->Points, &v));
    }
  }

  End_Surface(s);
  Tree_Insert (M->Surfaces , &s);
}

void CreateVolumeFromOldCrappyDatabase (int izon, List_T *loops, Mesh *M){
  SurfaceLoop *sl;
  int i,j,iLoop,is;
  Surface *s;
  Volume *v;
  
  v = Create_Volume(izon,MSH_VOLUME);
  v->Surfaces = List_Create(4, 1, sizeof(Surface*));
  for(i=0;i<List_Nbr(loops);i++){
    List_Read(loops,i,&iLoop);
    if(!(sl = FindSurfaceLoop(iLoop,THEM))){
      Msg(GERROR, "Unknown Surface Loop %d", iLoop);
      List_Delete(v->Surfaces);
      Free(v);
      return;
    }
    else{
      for(j=0;j<List_Nbr(sl->Surfaces);j++){
        List_Read(sl->Surfaces,j,&is);
        if(!(s = FindSurface(abs(is),THEM))){
          Msg(GERROR, "Unknown Surface %d", is);
	  List_Delete(v->Surfaces);
	  Free(v);
	  return;
	}
        else
          List_Add (v->Surfaces, &s);
      }
    }
  }
  Tree_Add(M->Volumes,&v);
}


void Cdbz101(int izon, int typzon,int o1, int o2, int nbu, int nbv,
                int support, List_T *ListCP, List_T *liste,
                List_T *intlist){

  int      i,j;
  double   f;
  List_T  *templist = NULL;
  Curve   *c, *c0, *c1, *c2;

  if(liste){
    templist = List_Create(List_Nbr(liste),1,sizeof(int));
    for(i=0;i<List_Nbr(liste);i++){
      List_Read (liste, i, &f);
      j = (int)f;
      List_Add(templist,&j);
    }
  }
  else if (intlist){
    templist = intlist;
  }

  if(typzon == MSH_SURF_REGL || typzon == MSH_SURF_TRIC ||
     typzon == MSH_SURF_PLAN || typzon == MSH_SURF_TRIMMED ||
     typzon == MSH_SURF_NURBS ){
    CreateSurfaceFromOldCrappyDatabase (izon, typzon, o1,o2, nbu, nbv,
                                        support, ListCP,templist,THEM);
  }
  else if(typzon == MSH_SURF_LOOP){
    Add_SurfaceLoop(izon,templist,THEM);
  }
  else  if(typzon == MSH_SEGM_LOOP){

    // We sort the lines in the line loops. Without this sort, it very
    // difficult to write general scriptable surface generation in
    // complex cases.

    int NbCurves = List_Nbr(templist) ;
    List_T *curves = List_Create(NbCurves,1,sizeof(Curve*));
    for(i=0 ; i<NbCurves ; i++){
      if((c = FindCurve(*(int*)List_Pointer(templist,i), THEM)))
	List_Add(curves, &c);
      else
	Msg(GERROR, "Unknown Curve %d in Line Loop %d", 
	    *(int*)List_Pointer(templist,i), izon);
    }
    List_Reset(templist);

    int j = 0, k = 0;
    c0 = c1 = *(Curve**)List_Pointer(curves, 0);
    List_Add(templist, &c1->Num);
    List_PSuppress(curves, 0);
    while(List_Nbr(templist) < NbCurves){
      for(i=0 ; i<List_Nbr(curves); i++){
	c2 = *(Curve**)List_Pointer(curves, i);
	if(c1->end == c2->beg){
	  List_Add(templist, &c2->Num);
	  List_PSuppress(curves, i);
	  c1 = c2 ;
	  if(c2->end == c0->beg){
	    if(List_Nbr(curves)){
	      Msg(INFO, "Starting subloop %d in Line Loop %d (are you sure about this?)",
		  ++k, izon);
	      c0 = c1 = *(Curve**)List_Pointer(curves, 0);
	      List_Add(templist, &c1->Num);
	      List_PSuppress(curves, 0);
	    }
	  }
	  break;
	}
      }
      if(j++ > NbCurves){
	Msg(GERROR, "Line Loop %d is wrong", izon);
	break;
      }
    }  
    List_Delete(curves);

    /*
    printf("Line Loop %d = {", izon);
    for(i=0 ; i<List_Nbr(templist); i++){
      printf(" %d", *(int*)List_Pointer(templist, i));
    }
    printf("}\n");
    */
    Add_EdgeLoop(izon,templist,THEM);
  }
  else  if(typzon == MSH_VOLUME){
    CreateVolumeFromOldCrappyDatabase (izon,templist,THEM);
  }
  else{
    Add_PhysicalGroup(izon,typzon,templist,THEM);
  }
  
  if(liste)List_Delete (templist);
    

}

void CreateNurbsSurfaceSupport (int Num , int Order1, int Order2 ,
                                List_T *List, List_T *ku, List_T *kv){
  
  List_T *ListOfDouble_L;
  List_T *ListCP;
  int i,j,Nv,Nu,N;
  Surface *s;
  double d;
  float f;
  ListCP  = List_Create(2,2,sizeof(int));
  
  for(j=0;j<List_Nbr(List);j++){
    List_Read(List,j,&ListOfDouble_L);
    for(i=0;i<List_Nbr(ListOfDouble_L);i++){
      List_Read(ListOfDouble_L,i,&d);
      N = (int)d;
      List_Add(ListCP,&N);
    }
  }
  List_Read(List,0,&ListOfDouble_L);
  Nu = List_Nbr(List);
  Nv = List_Nbr(ListOfDouble_L);
  Cdbz101(Num,MSH_SURF_NURBS,Order1,Order2,Nv,Nu,0,ListCP,NULL,NULL);

  if(!(s = FindSurface(Num,THEM))){
    Msg(GERROR, "Unknown Surface Loop %d", Num);
    return;
  }
  else{
    s->ku = (float*)malloc(List_Nbr(ku)*sizeof(float));
    s->kv = (float*)malloc(List_Nbr(kv)*sizeof(float));
    s->Support = NULL;
  
    double kumin = 0., kumax = 1.;
    double kvmin = 0., kvmax = 1.;
    /*
      List_Read(ku,0,&kumin);
      List_Read(ku,List_Nbr(ku)-1,&kumax);
      List_Read(kv,0,&kvmin);
      List_Read(kv,List_Nbr(kv)-1,&kvmax);
    */
    
    for(i=0;i<List_Nbr(ku);i++){
      List_Read(ku,i,&d);
      f = (float) ((d-kumin)/(kumax-kumin));
      s->ku[i] = f;
    }
    for(i=0;i<List_Nbr(kv);i++) {
      List_Read(kv,i,&d);
      f = (float) ((d-kvmin)/(kvmax-kvmin));
      s->kv[i] = f;
    }
  }

  List_Delete(ListCP);
}

void CreateNurbsSurface (int Num , int Order1 , int Order2 , List_T *List,
                         List_T *ku, List_T *kv ){
  List_T *ListOfDouble_L;
  List_T *Listint,*ListCP;
  int i,j,Loop[4],N,Nu,Nv;
  double d;
  int TypLine = MSH_SEGM_NURBS;
  Curve *cc;
  
  Listint = List_Create(2,2,sizeof(int));
  ListCP  = List_Create(2,2,sizeof(int));

  double kumin, kumax;
  List_Read(ku,0,&kumin);
  List_Read(ku,List_Nbr(ku)-1,&kumax);
  double kvmin, kvmax;
  List_Read(kv,0,&kvmin);
  List_Read(kv,List_Nbr(kv)-1,&kvmax);
  for(j=0;j<List_Nbr(List);j++){
    List_Read(List,j,&ListOfDouble_L);
    for(i=0;i<List_Nbr(ListOfDouble_L);i++){
      List_Read(ListOfDouble_L,i,&d);
      N = (int)d;
      List_Add(ListCP,&N);
    }
  }
  
  List_Read(List,0,&ListOfDouble_L);
  Nu = List_Nbr(List);
  Nv = List_Nbr(ListOfDouble_L);
  
  for(i=0;i<List_Nbr(ListOfDouble_L);i++){
    List_Read(ListOfDouble_L,i,&d);
    j = (int)d;
    List_Add(Listint,&j);
  }
  if(recognize_seg(TypLine,Listint,&Loop[0])){
  }
  else{
    Loop[0] = NEWREG();
    Cdbseg101(Loop[0],TypLine,Order1,ListOfDouble_L,NULL,-1,-1,kumin,kumax,NULL,NULL,NULL);
    if(!(cc = FindCurve(Loop[0],THEM))){
      Msg(GERROR, "Unknown Curve %d", Loop[0]);
      List_Delete(Listint);
      List_Delete(ListCP);
      return;
    }
    else{
      cc->k = (float*)malloc(4*List_Nbr(ku)*sizeof(float));
      for(i=0;i<List_Nbr(ku);i++){
        List_Read(ku,i,&d);
        cc->k[i] = (float)d/*((d-kumin)/(kumax-kumin))*/;
      }
    }
  }
  List_Reset(Listint);
  
  List_Read(List,List_Nbr(List)-1,&ListOfDouble_L);
  for(i=0;i<List_Nbr(ListOfDouble_L);i++){
    List_Read(ListOfDouble_L,i,&d);
    j = (int)d;
    List_Add(Listint,&j);
  }
  if(recognize_seg(TypLine,Listint,&Loop[2])){
  }
  else{
    Loop[2] = NEWREG();
    Cdbseg101(Loop[2],TypLine,Order1,ListOfDouble_L,NULL,-1,-1,kumin,kumax,NULL,NULL,NULL);
    if(!(cc = FindCurve(Loop[2],THEM))){
      Msg(GERROR, "Unknown Curve %d", Loop[2]);
      List_Delete(Listint);
      List_Delete(ListCP);
      return;
    }
    else{
      cc->k = (float*)malloc(4*List_Nbr(ku)*sizeof(float));
      for(i=0;i<List_Nbr(ku);i++){
        List_Read(ku,i,&d);
        cc->k[i] = (float)d/*((d-kumin)/(kumax-kumin))*/;
      }
    }
  }
  List_Reset(Listint);
  
  List_T *List1 = List_Create(List_Nbr(List),1,sizeof(double));
  List_T *List2 = List_Create(List_Nbr(List),1,sizeof(double));
  
  for(i=0;i<List_Nbr(List);i++){
    List_Read(List,i,&ListOfDouble_L);
    List_Add(List1,List_Pointer(ListOfDouble_L,0));
    List_Add(List2,List_Pointer(ListOfDouble_L,List_Nbr(ListOfDouble_L)-1));
  }
  
  for(i=0;i<List_Nbr(List1);i++){
    List_Read(List1,i,&d);
    j = (int)d;
    List_Add(Listint,&j);
  }
  if(recognize_seg(TypLine,Listint,&Loop[1])){
  }
  else{
    Loop[1] = NEWREG();
    Cdbseg101(Loop[1],TypLine,Order2,List1,NULL,-1,-1,kvmin,kvmax,NULL,NULL,NULL);
    if(!(cc = FindCurve(Loop[1],THEM))){
      Msg(GERROR, "Unknown Curve %d", Loop[1]);
      List_Delete(List1);
      List_Delete(List2);
      List_Delete(Listint);
      List_Delete(ListCP);
      return;
    }
    else{
      cc->k = (float*)malloc(4*List_Nbr(kv) * sizeof(float));
      for(i=0;i<List_Nbr(kv);i++){
        List_Read(kv,i,&d);
        cc->k[i] = (float)d/*((d-kvmin)/(kvmax-kvmin))*/;
      }
    }
  }
  List_Reset(Listint);
  
  for(i=0;i<List_Nbr(List2);i++){
    List_Read(List2,i,&d);
    j = (int)d;
    List_Add(Listint,&j);
  }
  if(recognize_seg(TypLine,Listint,&Loop[3])){
  }
  else{
    Loop[3] = NEWREG();
    Cdbseg101(Loop[3],TypLine,Order2,List2,NULL,-1,-1,kvmin,kvmax,NULL,NULL,NULL);
    if(!(cc = FindCurve(Loop[3],THEM)))
      Msg(GERROR, "Unknown Curve %d", Loop[3]);
    else{
      cc->k = (float*)malloc(4*List_Nbr(kv)*sizeof(float));
      for(i=0;i<List_Nbr(kv);i++){
        List_Read(kv,i,&d);
        cc->k[i] = (float)d/*((d-kvmin)/(kvmax-kvmin))*/;
      }
    }
  }
  
  List_Reset(Listint);
  List_Delete(List1);
  List_Reset(List2);
  double f = (double)-Loop[0];
  List_Add(List2,&f);
  f = (double)Loop[1];
  List_Add(List2,&f);
  f = (double)Loop[2];
  List_Add(List2,&f);
  f = (double)-Loop[3];
  List_Add(List2,&f);
  
  int topnew = NEWREG();
  CreateNurbsSurfaceSupport (topnew,Order1 , Order2 ,List,ku,kv);
  j = NEWREG();
  Cdbz101(j,MSH_SEGM_LOOP,0,0,0,0,0,NULL,List2,NULL);
  List_Delete(List2);
  List_Add(Listint,&j);
  j = NEWREG();
  Cdbz101(j,MSH_SURF_TRIMMED,Order1,Order2,Nv,Nu,topnew,ListCP,NULL,Listint);
  List_Delete(Listint);
  List_Delete(ListCP);
}

