// $Id: Visibility.cpp,v 1.4 2002-05-18 07:56:48 geuzaine Exp $
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

#include "Gmsh.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "DataBase.h"
#include "Parser.h"
#include "Visibility.h"

extern Mesh *THEM;

static List_T *ElementaryEntities = NULL, *PhysicalEntities = NULL;
static Tree_T *VisibleThroughPhysical[4] = {NULL,NULL,NULL,NULL};
static List_T *NumxSymb = NULL;
static int Sort = 1;

int Entity::Num(){
  switch(type){
  case 1 :
  case 2 :
  case 3 :
  case 4 : return data.physical ? data.physical->Num : 0;
  case 5 : return data.vertex ? data.vertex->Num : 0;
  case 6 : return data.curve ? data.curve->Num : 0;
  case 7 : return data.surface ? data.surface->Num : 0;
  case 8 : return data.volume ? data.volume->Num : 0;
  default : return 0;
  }
}

char * Entity::Type(){
  switch(type){
  case 1 :
  case 5 : return "Point";
  case 2 :
  case 6 : return "Curve";
  case 3 :
  case 7 : return "Surface";
  case 4 :
  case 8 : return "Volume";
  default : return "Unknown";
  }
}

char * Entity::Name(){
  char *tmp="";
  return str?str:tmp;
}

static char browserline[512];
char * Entity::BrowserLine(){
  if(type){
    sprintf(browserline, "\t%s\t%d\t%s", Type(), Num(), Name());
    return browserline;
  }
  else
    return Name();
}

int Entity::Visible(){
  switch(type){
  case 1 : 
  case 2 : 
  case 3 : 
  case 4 : return data.physical ? data.physical->Visible : 0;
  case 5 : return data.vertex ? data.vertex->Visible : 0;
  case 6 : return data.curve ? data.curve->Visible : 0;
  case 7 : return data.surface ? data.surface->Visible : 0;
  case 8 : return data.volume ? data.volume->Visible : 0;
  default : return 0;
  }
}

void Entity::Visible(int mode){
  Vertex *v;
  Curve *c;
  Surface *s;
  Volume *V;
  int i,j;

  switch(type){
  case 1 :
    if(!data.physical) break;
    data.physical->Visible = mode;
    for(i=0;i<List_Nbr(data.physical->Entities);i++){
      List_Read(data.physical->Entities,i,&j);
      if((v=FindPoint(j,THEM))){
	if(Tree_Search(VisibleThroughPhysical[0],&j)){
	  v->Visible = v->Visible|mode;
	}
	else{
	  v->Visible = mode;
	  if(mode) Tree_Add(VisibleThroughPhysical[0],&j);
	}
      }
    }
    break;
  case 2 :
    if(!data.physical) break;
    data.physical->Visible = mode;
    for(i=0;i<List_Nbr(data.physical->Entities);i++){
      List_Read(data.physical->Entities,i,&j);
      if((c=FindCurve(abs(j),THEM))){
	if(Tree_Search(VisibleThroughPhysical[1],&j)){
	  c->Visible = c->Visible|mode;
	}
	else{
	  c->Visible = mode;
	  if(mode) Tree_Add(VisibleThroughPhysical[1],&j);
	}
      }
    }
    break;
  case 3 :
    if(!data.physical) break;
    data.physical->Visible = mode;
    for(i=0;i<List_Nbr(data.physical->Entities);i++){
      List_Read(data.physical->Entities,i,&j);
      if((s=FindSurface(abs(j),THEM))){
	if(Tree_Search(VisibleThroughPhysical[2],&j)){
	  s->Visible = s->Visible|mode;
	}
	else{
	  s->Visible = mode;
	  if(mode) Tree_Add(VisibleThroughPhysical[2],&j);
	}
      };
    }
    break;
  case 4 :
    if(!data.physical) break;
    data.physical->Visible = mode;
    for(i=0;i<List_Nbr(data.physical->Entities);i++){
      List_Read(data.physical->Entities,i,&j);
      if((V=FindVolume(abs(j),THEM))){
	if(Tree_Search(VisibleThroughPhysical[3],&j)){
	  V->Visible = V->Visible|mode;
	}
	else{
	  V->Visible = mode;
	  if(mode) Tree_Add(VisibleThroughPhysical[3],&j);
	}
      }
    }
    break;
  case 5 : if(!data.vertex) break; data.vertex->Visible = mode; break;
  case 6 : if(!data.curve) break; data.curve->Visible = mode; break;
  case 7 : if(!data.surface) break; data.surface->Visible = mode; break;
  case 8 : if(!data.volume) break; data.volume->Visible = mode; break;
  }
}

static void Recur(Curve *c, int mode){
  int k;
  Vertex *v;
  for(k=0;k<List_Nbr(c->Control_Points);k++){
    List_Read(c->Control_Points,k,&v);
    v->Visible = v->Visible|mode;
  }
}

static void Recur(Surface *s, int mode){
  int k,l;
  Vertex *v;
  Curve *c;
  for(k=0;k<List_Nbr(s->Generatrices);k++){
    List_Read(s->Generatrices,k,&c);
    if(c->Num<0) c = FindCurve(-c->Num,THEM);
    if(c){
      c->Visible = c->Visible|mode;
      for(l=0;l<List_Nbr(c->Control_Points);l++){
	List_Read(c->Control_Points,l,&v);
	v->Visible = v->Visible|mode;
      }
    }
  }
}

static void Recur(Volume *V, int mode){
  int k,l,m;
  Vertex *v;
  Curve *c;
  Surface *s;
  for(k=0;k<List_Nbr(V->Surfaces);k++){
    List_Read(V->Surfaces,k,&s);
    s->Visible = s->Visible|mode;
    for(l=0;l<List_Nbr(s->Generatrices);l++){
      List_Read(s->Generatrices,l,&c);
      if(c->Num<0) c = FindCurve(-c->Num,THEM);
      if(c){
	c->Visible = c->Visible|mode;
	for(m=0;m<List_Nbr(c->Control_Points);m++){
	  List_Read(c->Control_Points,m,&v);
	  v->Visible = v->Visible|mode;
	}
      }
    }
  }
}

void Entity::RecurVisible(){
  int j,k,mode;
  Curve *c;
  Surface *s;
  Volume *V;

  mode = Visible();
  if(mode){
    switch(type){
    case 1 : break;
    case 2 :
      if(!data.physical) break; 
      for(j=0;j<List_Nbr(data.physical->Entities);j++){
	List_Read(data.physical->Entities,j,&k);
	if((c=FindCurve(abs(k),THEM))) Recur(c,mode);
      }
      break;
    case 3 :
      if(!data.physical) break; 
      for(j=0;j<List_Nbr(data.physical->Entities);j++){
	List_Read(data.physical->Entities,j,&k);
	if((s=FindSurface(abs(k),THEM))) Recur(s,mode);
      }
      break;
    case 4 :
      if(!data.physical) break; 
      for(j=0;j<List_Nbr(data.physical->Entities);j++){
	List_Read(data.physical->Entities,j,&k);
	if((V=FindVolume(abs(k),THEM))) Recur(V,mode);
      }
      break;
    case 5 : break;
    case 6 : if(!data.curve) break; Recur(data.curve,mode); break;
    case 7 : if(!data.surface) break; Recur(data.surface,mode); break;
    case 8 : if(!data.volume) break; Recur(data.volume,mode); break;
    }
  }
}




void SetVisibilitySort(int sort){
  if(Sort == sort)
    Sort = -sort;
  else
    Sort = sort;
}

static int CompareEntity(const void *a, const void *b){
  Entity *p=(Entity*)a, *q=(Entity*)b;
  switch(Sort){
  case 1  : return p->type - q->type;
  case -1 : return q->type - p->type;
  case 2  : return p->Num() - q->Num();
  case -2 : return q->Num() - p->Num();
  case 3  : return strcmp(p->Name(), q->Name());
  case -3 : return strcmp(q->Name(), p->Name());
  default : return 0;
  }
}

static int CompareNxS(const void *a, const void *b){
  NxS *p=(NxS*)a, *q=(NxS*)b;
  return p->n - q->n;
}

static char * GetString(int num){
  NxS nxs, *pnxs;
  nxs.n = num;
  if((pnxs = (NxS*)List_PQuery(NumxSymb,&nxs,CompareNxS)))
    return pnxs->s;
  else
    return NULL;
}

static void AddPhysical(void *a, void *b){
  PhysicalGroup *p=*(PhysicalGroup**)a;
  Entity e;
  switch(p->Typ){
  case MSH_PHYSICAL_POINT  : e.type = 1; break;
  case MSH_PHYSICAL_LINE   : e.type = 2; break;
  case MSH_PHYSICAL_SURFACE: e.type = 3; break;
  case MSH_PHYSICAL_VOLUME : e.type = 4; break;
  }
  e.data.physical = p;
  e.str = GetString(p->Num);
  List_Add(PhysicalEntities, &e);
}

static void AddVertex(void *a, void *b){
  Vertex *v=*(Vertex**)a;
  Entity e;
  e.type = 5;
  e.data.vertex = v;
  e.str = GetString(v->Num);
  List_Add(ElementaryEntities, &e);
}

static void AddCurve(void *a, void *b){
  Curve *c=*(Curve**)a;
  if(c->Num < 0) return;
  Entity e;
  e.type = 6;
  e.data.curve = c;
  e.str = GetString(c->Num);
  List_Add(ElementaryEntities, &e);
}

static void AddSurface(void *a, void *b){
  Surface *s=*(Surface**)a;
  Entity e;
  e.type = 7;
  e.data.surface = s;
  e.str = GetString(s->Num);
  List_Add(ElementaryEntities, &e);
}

static void AddVolume(void *a, void *b){
  Volume *v=*(Volume**)a;
  Entity e;
  e.type = 8;
  e.data.volume = v;
  e.str = GetString(v->Num);
  List_Add(ElementaryEntities, &e);
}

List_T* GetVisibilityList(int type){
  int i, j;
  Symbol *s;
  NxS nxs;

  if(!ElementaryEntities) 
    ElementaryEntities = List_Create(100,100,sizeof(Entity));
  else
    List_Reset(ElementaryEntities);

  if(!PhysicalEntities)
    PhysicalEntities = List_Create(100,100,sizeof(Entity));
  else
    List_Reset(PhysicalEntities);

  if(!NumxSymb) 
    NumxSymb = List_Create(100,100,sizeof(NxS));
  else
    List_Reset(NumxSymb);

  for(i=0; i<List_Nbr(Symbol_L); i++){
    s=(Symbol*)List_Pointer(Symbol_L,i);
    for(j=0; j<List_Nbr(s->val); j++){
      nxs.n = (int)(*(double*)List_Pointer(s->val, j));
      nxs.s = s->Name;
      List_Add(NumxSymb, &nxs);
    }
  }

  List_Action(THEM->PhysicalGroups, AddPhysical);

  Tree_Action(THEM->Points, AddVertex);
  Tree_Action(THEM->Curves, AddCurve);
  Tree_Action(THEM->Surfaces, AddSurface);
  Tree_Action(THEM->Volumes, AddVolume);
  
  List_Sort(ElementaryEntities, CompareEntity);
  List_Sort(PhysicalEntities, CompareEntity);

  switch(type){
  case ELEMENTARY : return ElementaryEntities;
  case PHYSICAL : return PhysicalEntities;
  default : return NULL;
  }
}

void ClearVisibilityList(int type){
  int i;
  Entity *e;
  List_T *list = (type==ELEMENTARY) ? ElementaryEntities : PhysicalEntities;
  for(i=0;i<List_Nbr(list);i++){
    e = (Entity*)List_Pointer(list, i);
    e->Visible(0);
  }
}

void InitVisibilityThroughPhysical(){
  int i;
  for(i=0;i<4;i++){
    if(VisibleThroughPhysical[i]) Tree_Delete(VisibleThroughPhysical[i]);
    VisibleThroughPhysical[i] = Tree_Create(sizeof(int),fcmp_absint);
  }
}

static int vnod, velm, vcur, vsur, vvol;
static void vis_nod(void *a, void *b){ (*(Vertex**)a)->Visible = vnod; }
static void vis_sim(void *a, void *b){ (*(Simplex**)a)->Visible = velm; }
static void vis_hex(void *a, void *b){ (*(Hexahedron**)a)->Visible = velm; }
static void vis_pri(void *a, void *b){ (*(Prism**)a)->Visible = velm; }
static void vis_pyr(void *a, void *b){ (*(Pyramid**)a)->Visible = velm; }
static void vis_cur(void *a, void *b){ (*(Curve**)a)->Visible = vcur; }
static void vis_sur(void *a, void *b){ (*(Surface**)a)->Visible = vsur; }
static void vis_vol(void *a, void *b){ (*(Volume**)a)->Visible = vvol; }

void SetVisibilityByNumber(char *str, int type, int mode){
  static int allnod=1, allelm=1, allpnt=1, allcur=1, allsur=1, allvol=1;
  int i, found, num;
  List_T *tmp;
  Vertex vv,*v,**pv;
  Curve *c;
  Surface *s;
  Volume *V;
  Simplex SS, *S, **pS;
  Hexahedron HH, *H, **pH;
  Prism PP, *P, **pP;
  Pyramid QQ, *Q, **pQ;

  if (!strcmp(str,"all") || !strcmp(str,"*")){
    switch(type){
    case 0: //node
      allnod = !allnod;
      vnod = allnod ? VIS_MESH : 0;
      Tree_Action(THEM->Vertices, vis_nod);
      break;
    case 1: //element
      allelm = !allelm;
      velm = allelm ? VIS_MESH : 0;
      tmp = Tree2List(THEM->Curves);
      for(i=0; i<List_Nbr(tmp); i++){
	List_Read(tmp, i, &c);
	Tree_Action(c->Simplexes, vis_sim);
      }
      List_Delete(tmp);
      tmp = Tree2List(THEM->Surfaces);
      for(i=0; i<List_Nbr(tmp); i++){
	List_Read(tmp, i, &s);
	Tree_Action(s->Simplexes, vis_sim);
      }
      List_Delete(tmp);
      Tree_Action(THEM->Simplexes, vis_sim);
      tmp = Tree2List(THEM->Volumes);
      for(i=0; i<List_Nbr(tmp); i++){
	List_Read(tmp, i, &V);
	Tree_Action(V->Hexahedra, vis_hex);
	Tree_Action(V->Prisms, vis_pri);
	Tree_Action(V->Pyramids, vis_pyr);
      }
      List_Delete(tmp);
      break;
    case 2: //point
      allpnt = !allpnt;
      vnod = allpnt ? VIS_MESH|VIS_GEOM : 0;
      Tree_Action(THEM->Points, vis_nod);
      break;
    case 3: //curve
      allcur = !allcur;
      vcur = allcur ? VIS_MESH|VIS_GEOM : 0;
      Tree_Action(THEM->Curves, vis_cur);
      break;
    case 4: //surface
      allsur = !allsur;
      vsur = allsur ? VIS_MESH|VIS_GEOM : 0;
      Tree_Action(THEM->Surfaces, vis_sur);
      break;
    case 5: //volume
      allvol= !allvol;
      vvol = allvol ? VIS_MESH|VIS_GEOM : 0;
      Tree_Action(THEM->Volumes, vis_vol);
      break;
    }
  }
  else{ 
    num = atoi(str);

    switch(type){
    case 0: //node
      vv.Num = num; v = &vv;
      if((pv = (Vertex**)Tree_PQuery(THEM->Vertices, &v)))
	(*pv)->Visible = (*pv)->Visible ? 0 : VIS_MESH;
      else
	Msg(WARNING, "Unknown node %d (use '*' to hide/show all nodes)", num);
      break;
    case 1: //element
      SS.Num = num; S = &SS;
      HH.Num = num; H = &HH;
      PP.Num = num; P = &PP;
      QQ.Num = num; Q = &QQ;
      found = 0;
      tmp = Tree2List(THEM->Curves);
      for(i=0; i<List_Nbr(tmp); i++){
	List_Read(tmp, i, &c);
	if((pS = (Simplex**)Tree_PQuery(c->Simplexes, &S))){
	  (*pS)->Visible = (*pS)->Visible ? 0 : VIS_MESH; found = 1; break;
	}
      }
      List_Delete(tmp);
      if(!found){
	tmp = Tree2List(THEM->Surfaces);
	for(i=0; i<List_Nbr(tmp); i++){
	  List_Read(tmp, i, &s);
	  if((pS = (Simplex**)Tree_PQuery(s->Simplexes, &S))){
	    (*pS)->Visible = (*pS)->Visible ? 0 : VIS_MESH; found = 1; break;
	  }
	}
	List_Delete(tmp);
	if(!found){
	  if((pS = (Simplex**)Tree_PQuery(THEM->Simplexes, &S))){
	    (*pS)->Visible = (*pS)->Visible ? 0 : VIS_MESH;
	  }
	  else{
	    tmp = Tree2List(THEM->Volumes);
	    for(i=0; i<List_Nbr(tmp); i++){
	      List_Read(tmp, i, &V);
	      if((pH = (Hexahedron**)Tree_PQuery(V->Hexahedra, &H))){
		(*pH)->Visible = (*pH)->Visible ? 0 : VIS_MESH; found = 1; break;
	      }
	      if((pP = (Prism**)Tree_PQuery(V->Prisms, &P))){
		(*pP)->Visible = (*pP)->Visible ? 0 : VIS_MESH; found = 1; break;
	      }
	      if((pQ = (Pyramid**)Tree_PQuery(V->Pyramids, &Q))){
		(*pQ)->Visible = (*pQ)->Visible ? 0 : VIS_MESH; found = 1; break;
	      }
	    }
	    List_Delete(tmp);
	    if(!found) 
	      Msg(WARNING, "Unknown element %d (use '*' to hide/show all elements)", num);
	  }
	}
      }
      break;
    case 2: //point
      if((v=FindPoint(num,THEM))) v->Visible = v->Visible ? 0 : VIS_GEOM|VIS_MESH ;
      else Msg(WARNING, "Unknown point %d (use '*' to hide/show all points)", num);
      break;
    case 3: //curve
      if((c=FindCurve(num,THEM))) c->Visible = c->Visible ? 0 : VIS_GEOM|VIS_MESH ;
      else Msg(WARNING, "Unknown curve %d (use '*' to hide/show all curves)", num);
      break;
    case 4: //surface
      if((s=FindSurface(num,THEM))) s->Visible = s->Visible ? 0 : VIS_GEOM|VIS_MESH ;
      else Msg(WARNING, "Unknown surface %d (use '*' to hide/show all surfaces)", num);
      break;
    case 5: //volume
      if((V=FindVolume(num,THEM))) V->Visible = V->Visible ? 0 : VIS_GEOM|VIS_MESH ;
      else Msg(WARNING, "Unknown volume %d (use '*' to hide/show all volumes)", num);
      break;
    }
  }
}
