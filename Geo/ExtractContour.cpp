// $Id: ExtractContour.cpp,v 1.6 2005-01-01 19:35:28 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "Geo.h"
#include "GeoUtils.h"
#include "CAD.h"
#include "Mesh.h"
#include "Numeric.h"

// Note: we use List_ISearchSeq so that the input lists don't get
// sorted: it's less efficient, but it allows us to do multi-level
// user-friendly "undo"s...

extern Mesh *THEM;

typedef struct{
  int n, a;
}nxa;

typedef struct{
  int n;
  List_T *l;
}lnk;

int complink(const void *a, const void *b)
{
  lnk *q, *w;
  q = (lnk *) a;
  w = (lnk *) b;
  return (q->n - w->n);
}

// Find all linked edges

void recurFindLinkedEdges(int ed, List_T * edges, Tree_T * points, Tree_T * links)
{
  lnk lk;
  nxa na;
  int ip[2];
  Curve *c = FindCurve(ed, THEM);
  if(!c){
    Msg(GERROR, "Unknown curve %d", ed);
    return;
  }
  
  ip[0] = c->beg->Num;
  ip[1] = c->end->Num;

  for(int l = 0; l < 2; l++) {
    lk.n = ip[l];
    if(!Tree_Search(points, &lk.n))
      Tree_Add(points, &lk.n);
    else
      Tree_Suppress(points, &lk.n);
    Tree_Query(links, &lk);
    if(List_Nbr(lk.l) == 2) {
      for(int i = 0; i < 2; i++) {
	List_Read(lk.l, i, &na);
	if(na.a != ed) {
	  if(List_ISearchSeq(edges, &na.a, fcmp_absint) < 0){
	    List_Add(edges, &na.a);
	    recurFindLinkedEdges(na.a, edges, points, links);
	  }
	}
      }
    }
  }
}

void createEdgeLinks(Tree_T *links)
{
  lnk li, *pli;
  nxa na;
  Curve *c;

  List_T *temp = Tree2List(THEM->Curves);

  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &c);
    if(c->Num > 0) {
      na.a = c->Num;
      int ip[2];
      ip[0] = c->beg->Num;
      ip[1] = c->end->Num;
      for(int k = 0; k < 2; k++){
	li.n = ip[k];
	if((pli = (lnk *) Tree_PQuery(links, &li))) {
	  List_Add(pli->l, &na);
	}
	else {
	  li.l = List_Create(20, 1, sizeof(nxa));
	  List_Add(li.l, &na);
	  Tree_Add(links, &li);
	}
      }
    }
  }
  List_Delete(temp);
}

void orientAndSortEdges(List_T *edges, Tree_T *links)
{
  // this orients all the edges in a line loop in a consistent manner
  // (left- or right-oriented, depending on the orientation of the
  // first edge) *and* sorts them so that they form a path
  int num;
  lnk lk;
  nxa na;

  List_T *temp = List_Create(List_Nbr(edges), 1, sizeof(int));
  List_Copy(edges, temp);
  List_Reset(edges);
  
  List_Read(temp, 0, &num);
  List_Add(edges, &num);
  Curve *c0 = FindCurve(abs(num), THEM);
  if(!c0){
    Msg(GERROR, "Unknown curve %d", abs(num));
    return;
  }

  int sign = 1;
  while(List_Nbr(edges) < List_Nbr(temp)){
    if(sign > 0)
      lk.n = c0->end->Num;
    else
      lk.n = c0->beg->Num;
    Tree_Query(links, &lk);
    for(int j = 0; j < List_Nbr(lk.l); j++){
      List_Read(lk.l, j, &na);
      if(c0->Num != na.a && List_Search(temp, &na.a, fcmp_absint)){
	Curve *c1 = FindCurve(abs(na.a), THEM);
	if(!c1){
	  Msg(GERROR, "Unknown curve %d", abs(na.a));
	  return;
	}
	if(lk.n == c1->beg->Num){
	  sign = 1;
	  num = na.a;
	}
	else{
	  sign = -1;
	  num = -na.a;
	}
	List_Add(edges, &num);
	c0 = c1;
	break;
      }
    }
  }
  
  List_Delete(temp);
}

int allEdgesLinked(int ed, List_T * edges)
{
  Tree_T *links = Tree_Create(sizeof(lnk), complink);
  Tree_T *points = Tree_Create(sizeof(int), fcmp_int);

  createEdgeLinks(links);

  // initialize point tree with all hanging points
  for(int i = 0; i < List_Nbr(edges); i++){
    int num;
    List_Read(edges, i, &num);
    Curve *c = FindCurve(abs(num), THEM);
    if(!c){
      Msg(GERROR, "Unknown curve %d", abs(num));
      return 0;
    }
    int ip[2];
    ip[0] = c->beg->Num;
    ip[1] = c->end->Num;
    for(int k = 0; k < 2; k++){
      if(!Tree_Search(points, &ip[k]))
	Tree_Add(points, &ip[k]);
      else
	Tree_Suppress(points, &ip[k]);
    }
  }

  if(List_ISearchSeq(edges, &ed, fcmp_absint) < 0){
    List_Add(edges, &ed);
    recurFindLinkedEdges(ed, edges, points, links);
  }

  int found = 0;

  if(!Tree_Nbr(points)){
    found = 1;
    // we can only orient things now since we allow to select
    // disconnected parts of the loop interactively
    orientAndSortEdges(edges, links);
  }

  Tree_Delete(links);
  Tree_Delete(points);

  return found;
}

// Find all linked faces

void recurFindLinkedFaces(int fac, List_T * faces, Tree_T * edges, Tree_T * links)
{
  lnk lk;
  nxa na;
  Curve *c;
  Surface *s = FindSurface(abs(fac), THEM);
  if(!s){
    Msg(GERROR, "Unknown surface %d", abs(fac));
    return;
  }

  for(int l = 0; l < List_Nbr(s->Generatrices); l++) {
    List_Read(s->Generatrices, l, &c);
    lk.n = abs(c->Num);
    if(!Tree_Search(edges, &lk.n))
      Tree_Add(edges, &lk.n);
    else
      Tree_Suppress(edges, &lk.n);
    Tree_Query(links, &lk);
    if(List_Nbr(lk.l) == 2) {
      for(int i = 0; i < 2; i++) {
        List_Read(lk.l, i, &na);
        if(na.a != fac) {
          if(List_ISearchSeq(faces, &na.a, fcmp_absint) < 0){
	    List_Add(faces, &na.a);
	    recurFindLinkedFaces(na.a, faces, edges, links);
	  }
	}
      }
    }
  }
}

void createFaceLinks(Tree_T * links)
{
  lnk li, *pli;
  nxa na;
  Surface *s;
  Curve *c;

  List_T *temp = Tree2List(THEM->Surfaces);

  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &s);
    if(s->Num > 0){
      na.a = s->Num;
      for(int k = 0; k < List_Nbr(s->Generatrices); k++) {
	List_Read(s->Generatrices, k, &c);
	li.n = abs(c->Num);
	if((pli = (lnk *) Tree_PQuery(links, &li))) {
	  List_Add(pli->l, &na);
	}
	else {
	  li.l = List_Create(20, 1, sizeof(nxa));
	  List_Add(li.l, &na);
	  Tree_Add(links, &li);
	}
      }
    }
  }
  List_Delete(temp);
}

void recurOrientFace(int face, List_T *faces, List_T *available, Tree_T *links)
{
  Surface *s = FindSurface(abs(face), THEM);
  if(!s){
    Msg(GERROR, "Unknown surface %d", abs(face));
    return;
  }
  int ori = sign(face);

  for(int i = 0; i < List_Nbr(s->Generatrices); i++){
    Curve *c;
    List_Read(s->Generatrices, i, &c);
    lnk lk;
    lk.n = abs(c->Num);
    Tree_Query(links, &lk);
    for(int j = 0; j < List_Nbr(lk.l); j++){
      nxa na;
      List_Read(lk.l, j, &na);
      int num = abs(na.a);
      if(num != abs(s->Num) && List_Search(available, &num, fcmp_absint) &&
	 List_ISearchSeq(faces, &num, fcmp_absint) < 0){
	Surface *s2 = FindSurface(num, THEM);
	if(!s2){
	  Msg(GERROR, "Unknown surface %d", num);
	  return;
	}
	for(int k = 0; k < List_Nbr(s2->Generatrices); k++){
	  Curve *c2;
	  List_Read(s2->Generatrices, k, &c2);
	  if(abs(c->Num) == abs(c2->Num)){
	    if(c->Num * c2->Num > 0)
	      num *= -ori;
	    else
	      num *= ori;
	    List_Add(faces, &num);
	    recurOrientFace(num, faces, available, links);
	    break;
	  }
	}
      }
    }
  }
}

void orientFaces(List_T *faces, Tree_T *links)
{
  // this orients all the faces in a surface loop in a consistent
  // manner (all normals pointing inside or outside--depending on the
  // orientation of the first face)

  List_T *temp = List_Create(List_Nbr(faces), 1, sizeof(int));
  List_Copy(faces, temp);
  List_Reset(faces);

  int num;
  List_Read(temp, 0, &num);
  List_Add(faces, &num);
  recurOrientFace(num, faces, temp, links);

  List_Delete(temp);
}

int allFacesLinked(int fac, List_T * faces)
{
  Tree_T *links = Tree_Create(sizeof(lnk), complink);
  Tree_T *edges = Tree_Create(sizeof(int), fcmp_int);
  
  createFaceLinks(links);

  // initialize edge tree with all boundary edges
  for(int i = 0; i < List_Nbr(faces); i++){
    int num;
    List_Read(faces, i, &num);
    Surface *s = FindSurface(abs(num), THEM);
    if(!s){
      Msg(GERROR, "Unknown surface %d", abs(num));
      return 0;
    }
    for(int k = 0; k < List_Nbr(s->Generatrices); k++) {
      Curve *c;
      List_Read(s->Generatrices, k, &c);
      int ic = abs(c->Num);
      if(!Tree_Search(edges, &ic))
	Tree_Add(edges, &ic);
      else
	Tree_Suppress(edges, &ic);
    }
  }

  if(List_ISearchSeq(faces, &fac, fcmp_absint) < 0){
    List_Add(faces, &fac);
    // Warning: this is correct ONLY if the surfaces are defined
    // correctly, i.e., if the surface hole boundaries are oriented
    // consistently with the surface exterior boundaries. There is
    // currently *nothing* in the code that checks this.
    recurFindLinkedFaces(fac, faces, edges, links);
  }

  int found = 0;

  if(!Tree_Nbr(edges)){
    found = 1;
    // we can only orient things now since we allow to select
    // disconnected parts of the loop interactively
    orientFaces(faces, links);
  }

  Tree_Delete(links);
  Tree_Delete(edges);

  return found;
}
