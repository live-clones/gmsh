// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshMessage.h"
#include "MallocUtils.h"
#include "GModel.h"
#include "TreeUtils.h"
#include "ListUtils.h"

typedef struct {
  int n, a;
} nxa;

typedef struct {
  int n;
  List_T *l;
} lnk;

static void freeLink(void *link)
{
  List_Delete(((lnk *)link)->l);
  Free(link);
}

static int complink(const void *a, const void *b)
{
  lnk *q = (lnk *)a;
  lnk *w = (lnk *)b;
  return q->n - w->n;
}

// Find all linked edges (note that we use List_ISearchSeq so that the input
// lists don't get sorted: it's less efficient, but it allows us to do
// multi-level, user-friendly undos in the GUI)

static void recurFindLinkedEdges(int ed, List_T *edges, Tree_T *points,
                                 Tree_T *links)
{
  GEdge *ge = GModel::current()->getEdgeByTag(ed);
  if(!ge) {
    Msg::Error("Unknown curve %d", ed);
    return;
  }
  if(!ge->getBeginVertex() || !ge->getEndVertex()) { return; }

  int ip[2];
  ip[0] = ge->getBeginVertex()->tag();
  ip[1] = ge->getEndVertex()->tag();

  for(int l = 0; l < 2; l++) {
    lnk lk;
    lk.n = ip[l];
    if(!Tree_Search(points, &lk.n))
      Tree_Add(points, &lk.n);
    else
      Tree_Suppress(points, &lk.n);
    Tree_Query(links, &lk);
    if(List_Nbr(lk.l) == 2) {
      for(int i = 0; i < 2; i++) {
        nxa na;
        List_Read(lk.l, i, &na);
        if(na.a != ed) {
          if(List_ISearchSeq(edges, &na.a, fcmp_absint) < 0) {
            List_Add(edges, &na.a);
            recurFindLinkedEdges(na.a, edges, points, links);
          }
        }
      }
    }
  }
}

static int createEdgeLinks(Tree_T *links)
{
  GModel *m = GModel::current();
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
    GEdge *ge = *it;
    if(!ge->getBeginVertex() || !ge->getEndVertex()) {
      Msg::Error("Cannot link curve %d with no begin or end point", ge->tag());
      return 0;
    }
    if(ge->tag() > 0) {
      nxa na;
      na.a = ge->tag();
      int ip[2];
      ip[0] = ge->getBeginVertex()->tag();
      ip[1] = ge->getEndVertex()->tag();
      for(int k = 0; k < 2; k++) {
        lnk li, *pli;
        li.n = ip[k];
        if((pli = (lnk *)Tree_PQuery(links, &li))) { List_Add(pli->l, &na); }
        else {
          li.l = List_Create(20, 1, sizeof(nxa));
          List_Add(li.l, &na);
          Tree_Add(links, &li);
        }
      }
    }
  }
  return 1;
}

static void orientAndSortEdges(List_T *edges, Tree_T *links)
{
  List_T *temp = List_Create(List_Nbr(edges), 1, sizeof(int));
  List_Copy(edges, temp);
  List_Reset(edges);

  int num;
  List_Read(temp, 0, &num);
  List_Add(edges, &num);

  GEdge *ge0 = GModel::current()->getEdgeByTag(abs(num));
  if(!ge0) {
    Msg::Error("Unknown curve %d", abs(num));
    List_Delete(temp);
    return;
  }
  if(!ge0->getBeginVertex() || !ge0->getEndVertex()) {
    Msg::Error("Cannot orient curve %d with no begin or end point", ge0->tag());
    return;
  }

  int sign = 1;
  while(List_Nbr(edges) < List_Nbr(temp)) {
    lnk lk;
    if(sign > 0)
      lk.n = ge0->getEndVertex()->tag();
    else
      lk.n = ge0->getBeginVertex()->tag();
    Tree_Query(links, &lk);
    for(int j = 0; j < List_Nbr(lk.l); j++) {
      nxa na;
      List_Read(lk.l, j, &na);
      if(ge0->tag() != na.a && List_Search(temp, &na.a, fcmp_absint)) {
        GEdge *ge1 = GModel::current()->getEdgeByTag(abs(na.a));
        if(!ge1) {
          Msg::Error("Unknown curve %d", abs(na.a));
          List_Delete(temp);
          return;
        }
        if(lk.n == ge1->getBeginVertex()->tag()) {
          sign = 1;
          num = na.a;
        }
        else {
          sign = -1;
          num = -na.a;
        }
        List_Add(edges, &num);
        ge0 = ge1;
        break;
      }
    }
  }

  List_Delete(temp);
}

int allEdgesLinked(int ed, List_T *edges)
{
  Tree_T *links = Tree_Create(sizeof(lnk), complink);
  Tree_T *points = Tree_Create(sizeof(int), fcmp_int);

  if(!createEdgeLinks(links)) {
    Tree_Delete(links, freeLink);
    Tree_Delete(points);
    return 0;
  }

  // initialize point tree with all hanging points
  for(int i = 0; i < List_Nbr(edges); i++) {
    int num;
    List_Read(edges, i, &num);
    GEdge *ge = GModel::current()->getEdgeByTag(abs(num));
    if(!ge) {
      Msg::Error("Unknown curve %d", abs(num));
      Tree_Delete(links, freeLink);
      Tree_Delete(points);
      return 0;
    }
    if(!ge->getBeginVertex() || !ge->getEndVertex()) {
      Msg::Error("Cannot link curve %d with no begin or end point", ge->tag());
      return 0;
    }
    int ip[2];
    ip[0] = ge->getBeginVertex()->tag();
    ip[1] = ge->getEndVertex()->tag();
    for(int k = 0; k < 2; k++) {
      if(!Tree_Search(points, &ip[k]))
        Tree_Add(points, &ip[k]);
      else
        Tree_Suppress(points, &ip[k]);
    }
  }

  if(List_ISearchSeq(edges, &ed, fcmp_absint) < 0) {
    List_Add(edges, &ed);
    recurFindLinkedEdges(ed, edges, points, links);
  }

  int found = 0;

  if(!Tree_Nbr(points)) {
    found = 1;
    // at this point we can orient all the edges in a curve loop in a consistent
    // manner (left- or right-oriented, depending on the orientation of the
    // first edge), and we can sort them so that they form a path (we can only
    // do this now since we allow to select disconnected parts of the loop in
    // the GUI)
    orientAndSortEdges(edges, links);
  }

  Tree_Delete(links, freeLink);
  Tree_Delete(points);

  return found;
}

// Find all linked faces

static void recurFindLinkedFaces(int fac, List_T *faces, Tree_T *edges,
                                 Tree_T *links)
{
  GFace *gf = GModel::current()->getFaceByTag(abs(fac));
  if(!gf) {
    Msg::Error("Unknown surface %d", abs(fac));
    return;
  }

  std::vector<GEdge *> const &l = gf->edges();
  for(auto it = l.begin(); it != l.end(); it++) {
    GEdge *ge = *it;
    if(ge->degenerate(0)) continue;
    lnk lk;
    lk.n = std::abs(ge->tag());
    if(!Tree_Search(edges, &lk.n))
      Tree_Add(edges, &lk.n);
    else
      Tree_Suppress(edges, &lk.n);
    Tree_Query(links, &lk);
    if(List_Nbr(lk.l) == 2) {
      for(int i = 0; i < 2; i++) {
        nxa na;
        List_Read(lk.l, i, &na);
        if(na.a != fac) {
          if(List_ISearchSeq(faces, &na.a, fcmp_absint) < 0) {
            List_Add(faces, &na.a);
            recurFindLinkedFaces(na.a, faces, edges, links);
          }
        }
      }
    }
  }
}

static void createFaceLinks(Tree_T *links)
{
  GModel *m = GModel::current();
  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    GFace *gf = *it;
    if(gf->tag() > 0) {
      nxa na;
      na.a = gf->tag();
      std::vector<GEdge *> const &l = gf->edges();
      for(auto ite = l.begin(); ite != l.end(); ite++) {
        GEdge *ge = *ite;
        if(ge->degenerate(0)) continue;
        lnk li, *pli;
        li.n = std::abs(ge->tag());
        if((pli = (lnk *)Tree_PQuery(links, &li))) { List_Add(pli->l, &na); }
        else {
          li.l = List_Create(20, 1, sizeof(nxa));
          List_Add(li.l, &na);
          Tree_Add(links, &li);
        }
      }
    }
  }
}

int allFacesLinked(int fac, List_T *faces)
{
  Tree_T *links = Tree_Create(sizeof(lnk), complink);
  Tree_T *edges = Tree_Create(sizeof(int), fcmp_int);

  createFaceLinks(links);

  // initialize edge tree with all boundary edges
  for(int i = 0; i < List_Nbr(faces); i++) {
    int num;
    List_Read(faces, i, &num);
    GFace *gf = GModel::current()->getFaceByTag(abs(num));
    if(!gf) {
      Msg::Error("Unknown surface %d", abs(num));
      Tree_Delete(links, freeLink);
      Tree_Delete(edges);
      return 0;
    }
    std::vector<GEdge *> const &l = gf->edges();
    for(auto it = l.begin(); it != l.end(); it++) {
      GEdge *ge = *it;
      if(ge->degenerate(0)) continue;
      int ic = std::abs(ge->tag());
      if(!Tree_Search(edges, &ic))
        Tree_Add(edges, &ic);
      else
        Tree_Suppress(edges, &ic);
    }
  }

  if(List_ISearchSeq(faces, &fac, fcmp_absint) < 0) {
    List_Add(faces, &fac);
    // Warning: this is correct only if the surfaces are defined with correct
    // orientations, i.e., if the hole boundaries are oriented consistently with
    // the exterior boundaries. There is currently nothing in the code that
    // checks this!
    recurFindLinkedFaces(fac, faces, edges, links);
  }

  int found = 0;

  if(!Tree_Nbr(edges)) {
    found = 1;
    // we could orient the faces here, but it's not really necessary...
  }

  Tree_Delete(links, freeLink);
  Tree_Delete(edges);

  return found;
}
