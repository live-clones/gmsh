// $Id: 2D_Mesh.cpp,v 1.70 2005-01-01 19:35:30 geuzaine Exp $
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
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Utils.h"
#include "Create.h"
#include "2D_Mesh.h"
#include "Context.h"
#include "Interpolation.h"

extern Mesh *THEM;
extern Context_T CTX;

PointRecord *gPointArray;
DocRecord *BGMESH, *FGMESH;
double LC2D;

static int is_3D = 0;
static Surface *THESURFACE, *THESUPPORT;

void ProjetteSurface(void *a, void *b)
{
  Vertex *v;
  v = *(Vertex **) a;

  if(!v->ListCurves)
    ProjectPointOnSurface(THESUPPORT, *v);
}

void Projette_Plan_Moyen(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  Projette(v, THESURFACE->plan);
}

void Projette_Inverse(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  Projette(v, THESURFACE->invplan);
}

void Plan_Moyen(void *data, void *dum)
{
  int i, j;
  Vertex *v;
  Curve *pC;
  Surface **pS, *s;
  static List_T *points;
  static int deb = 1;

  pS = (Surface **) data;
  s = *pS;

  if(deb) {
    points = List_Create(10, 10, sizeof(Vertex *));
    deb = 0;
  }
  else
    List_Reset(points);

  switch (s->Typ) {
  case MSH_SURF_PLAN:
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_NURBS:
  case MSH_SURF_TRIMMED:
    for(i = 0; i < List_Nbr(s->Generatrices); i++) {
      List_Read(s->Generatrices, i, &pC);
      for(j = 0; j < List_Nbr(pC->Vertices); j++) {
        List_Read(pC->Vertices, j, &v);
        List_Add(points, &v);
        Tree_Insert(s->Vertices, List_Pointer(pC->Vertices, j));
      }
    }
    break;
  }

  MeanPlane(points, s);
}


int Calcule_Contours(Surface * s)
{
  int i, j, ori, ORI = 0;
  Vertex *v, *first, *last;
  List_T *l, *linv;
  Curve *c;
  double n[] = { 0., 0., 1. };

  l = List_Create(10, 10, sizeof(Vertex *));
  for(i = 0; i < List_Nbr(s->Generatrices); i++) {
    List_Read(s->Generatrices, i, &c);
    if(!List_Nbr(l)) {
      List_Read(c->Vertices, 0, &first);
    }
    for(j = 1; j < List_Nbr(c->Vertices); j++) {
      List_Read(c->Vertices, j, &v);
      List_Add(l, &v);
      if(j == List_Nbr(c->Vertices) - 1) {
        last = v;
      }
    }
    if(!compareVertex(&last, &first)) {
      ori = Oriente(l, n);

      /* Le premier contour est oriente aire a droite
         Les autes sont des trous orientes aire a gauche */

      if(!List_Nbr(s->Contours))
        ORI = ori;

      if((!List_Nbr(s->Contours) && !ori) || (List_Nbr(s->Contours) && ori)) {
        linv = List_Create(10, 10, sizeof(Vertex *));
        List_Invert(l, linv);
        List_Delete(l);
        l = linv;
      }
      List_Add(s->Contours, &l);
      l = List_Create(10, 10, sizeof(Vertex *));
    }
  }
  return ORI;
}


void Calcule_Z(void *data, void *dum)
{
  Vertex **pv, *v;
  double Z, U, V;

  pv = (Vertex **) data;
  v = *pv;
  if(v->Frozen || v->Num < 0)
    return;

  XYtoUV(THESUPPORT, &v->Pos.X, &v->Pos.Y, &U, &V, &Z, 1.0);
  v->Pos.Z = Z;
}

void Calcule_Z_Plan(void *data, void *dum)
{
  Vertex **pv, *v;
  Vertex V;

  V.Pos.X = THESURFACE->a;
  V.Pos.Y = THESURFACE->b;
  V.Pos.Z = THESURFACE->c;

  Projette(&V, THESURFACE->plan);

  pv = (Vertex **) data;
  v = *pv;
  if(V.Pos.Z != 0.0)
    v->Pos.Z = (THESURFACE->d - V.Pos.X * v->Pos.X - V.Pos.Y * v->Pos.Y)
      / V.Pos.Z;
  else
    v->Pos.Z = 0.0;
}


void Add_In_Mesh(void *a, void *b)
{
  if(!Tree_Search(THEM->Vertices, a))
    Tree_Add(THEM->Vertices, a);
}

void Freeze_Vertex(void *a, void *b)
{
  Vertex *pv;
  pv = *(Vertex **) a;
  pv->Freeze.X = pv->Pos.X;
  pv->Freeze.Y = pv->Pos.Y;
  pv->Freeze.Z = pv->Pos.Z;
  pv->Frozen = 1;
}

void deFreeze_Vertex(void *a, void *b)
{
  Vertex *pv;
  pv = *(Vertex **) a;
  if(!pv->Frozen)
    return;
  pv->Pos.X = pv->Freeze.X;
  pv->Pos.Y = pv->Freeze.Y;
  pv->Pos.Z = pv->Freeze.Z;
  pv->Frozen = 0;
}

void PutVertex_OnSurf(void *a, void *b)
{
  Vertex *pv;
  pv = *(Vertex **) a;
  if(!pv->ListSurf)
    pv->ListSurf = List_Create(1, 1, sizeof(Surface *));
  List_Add(pv->ListSurf, &THESURFACE);
}


/* remplis la structure Delaunay d'un triangle cree */

Delaunay *testconv(avlptr *root, int *conv, DocRecord * ptr)
{
  double qual;
  Delaunay *pdel = NULL;

  *conv = 0;
  if(*root == NULL)
    *conv = 1;
  else {
    pdel = findrightest(*root, ptr);
    qual = pdel->t.quality_value;
    if(qual < CONV_VALUE)
      *conv = 1;
  }
  return pdel;
}


int mesh_domain(ContourPeek * ListContours, int numcontours,
                maillage * mai, int *numpoints, int OnlyTheInitialMesh)
{
  List_T *kill_L, *del_L;
  MPoint pt;
  DocRecord docm, *doc;
  int conv, i, j, nump, numact, numlink, numkil, numaloc, numtri, numtrr,
    numtrwait;
  Delaunay *del, *del_P, *deladd;
  PointNumero aa, bb, cc, a, b, c;
  DListPeek list, p, q;
  avlptr *root, *root_w;
  double volume_old, volume_new;

  root = (avlptr *) Malloc(sizeof(avlptr));
  root_w = (avlptr *) Malloc(sizeof(avlptr));

  nump = 0;
  for(i = 0; i < numcontours; i++)
    nump += ListContours[i]->numpoints;

  /* creation du maillage initial grace au puissant algorithme "divide and conquer" */

  doc = &docm;
  FGMESH = &docm;
  doc->points = (PointRecord *) Malloc((nump + 100) * sizeof(PointRecord));
  gPointArray = doc->points;

  numaloc = nump;
  doc->delaunay = 0;
  doc->numPoints = nump;
  doc->numTriangles = 0;
  mai->numtriangles = 0;
  mai->numpoints = 0;

  if(!numcontours) {
    Msg(GERROR, "No contour");
    return -1;
  }

  numact = 0;
  for(i = 0; i < numcontours; i++) {
    for(j = 0; j < ListContours[i]->numpoints; j++) {
      doc->points[numact + j].where.h =
        ListContours[i]->oriented_points[j].where.h
        + ListContours[i]->perturbations[j].h;
      doc->points[numact + j].where.v =
        ListContours[i]->oriented_points[j].where.v
        + ListContours[i]->perturbations[j].v;
      doc->points[numact + j].quality =
        ListContours[i]->oriented_points[j].quality;
      doc->points[numact + j].initial =
        ListContours[i]->oriented_points[j].initial;
      ListContours[i]->oriented_points[j].permu = numact + j;
      doc->points[numact + j].permu = numact + j;
      doc->points[numact + j].numcontour = ListContours[i]->numerocontour;
      doc->points[numact + j].adjacent = NULL;
    }
    numact += ListContours[i]->numpoints;
  }

  DelaunayAndVoronoi(doc);
  Conversion(doc);
  remove_all_dlist(doc->numPoints, doc->points);

  if(!is_3D || CTX.mesh.constrained_bgmesh)
    BGMESH = doc;
  else
    BGMESH = NULL;

  InitBricks(BGMESH);

  /* elimination des triangles exterieurs + verification de l'existence
     des edges (coherence) */

  makepermut(nump);
  del_L = List_Create(doc->numTriangles, 1000, sizeof(Delaunay *));

  for(i = 0; i < doc->numTriangles; i++) {
    del_P = &doc->delaunay[i];
    if((del_P->t.a == del_P->t.b) && (del_P->t.a == del_P->t.c)) {
      Msg(GERROR, "Initial mesh is wrong. Try the new isotropic algorithm.");
    }
    else
      List_Add(del_L, &del_P);
  }
  doc->numTriangles = List_Nbr(del_L);

  verify_edges(del_L, ListContours, numcontours);
  verify_inside(doc->delaunay, doc->numTriangles);

  /* creation des liens ( triangles voisins ) */

  CreateLinks(del_L, doc->numTriangles, ListContours, numcontours);

  /* initialisation de l'arbre  */

  (*root) = (*root_w) = NULL;

  int onlyinit = OnlyTheInitialMesh;

  if(doc->numTriangles == 1) {
    doc->delaunay[0].t.position = INTERN;
    Msg(INFO, "Only one triangle in initial mesh (skipping refinement)");
    onlyinit = 1;
  }

  for(i = 0; i < doc->numTriangles; i++) {
    if(doc->delaunay[i].t.position != EXTERN) {
      del = &doc->delaunay[i];
      Insert_Triangle(root, del);
    }
  }

  /* maillage proprement dit :
     1) Les triangles sont tries dans l'arbre suivant leur qualite
     2) on ajoute un noeud au c.g du plus mauvais
     3) on reconstruit le delaunay par Bowyer-Watson
     4) on ajoute les triangles dans l'arbre et on recommence
     jusque quand tous les triangles sont OK */

  del = testconv(root, &conv, doc);

  PushgPointArray(doc->points);

  List_Reset(del_L);
  kill_L = List_Create(1000, 1000, sizeof(Delaunay *));

  if(onlyinit)
    conv = 1;

  while(conv != 1) {

    pt = Localize(del, doc);

    numlink = 0;
    numkil = 0;
    list = NULL;

    if(!PE_Del_Triangle(del, pt, &list, kill_L, del_L, &numlink, &numkil)) {
      Msg(WARNING, "Triangle non deleted");
      Delete_Triangle(root, del);
      Delete_Triangle(root_w, del);
      del->t.quality_value /= 10.;
      Insert_Triangle(root, del);
      numlink = numkil = 0;
      if(list != NULL) {
        p = list;
        do {
          q = p;
          p = Pred(p);
          Free(q);
        }
        while(p != list);
      }
      list = NULL;
      del = testconv(root, &conv, doc);
      continue;
    }

    /* Test du Volume */

    i = 0;
    p = list;
    volume_new = 0.0;
    do {
      q = p->next;
      bb = p->point_num;
      cc = q->point_num;
      volume_new += fabs((doc->points[bb].where.h - pt.h) *
                         (doc->points[cc].where.v - doc->points[bb].where.v) -
                         (doc->points[cc].where.h - doc->points[bb].where.h) *
                         (doc->points[bb].where.v - pt.v));
      p = q;
    } while(p != list);

    volume_old = 0.0;
    for(i = 0; i < numkil; i++) {
      del_P = *(Delaunay **) List_Pointer(kill_L, i);
      aa = del_P->t.a;
      bb = del_P->t.b;
      cc = del_P->t.c;
      volume_old += fabs((doc->points[bb].where.h - doc->points[aa].where.h) *
                         (doc->points[cc].where.v - doc->points[bb].where.v) -
                         (doc->points[cc].where.h - doc->points[bb].where.h) *
                         (doc->points[bb].where.v - doc->points[aa].where.v));
    }

    if((volume_old - volume_new) / (volume_old + volume_new) > 1.e-6) {
      Msg(WARNING, "Volume has changed (%g->%g)", volume_old, volume_new);
      Delete_Triangle(root, del);
      Delete_Triangle(root_w, del);
      del->t.quality_value /= 10.;
      Insert_Triangle(root, del);
      numlink = numkil = 0;
      if(list != NULL) {
        p = list;
        do {
          q = p;
          p = Pred(p);
          Free(q);
        } while(p != list);
      }
      list = NULL;
      del = testconv(root, &conv, doc);
      continue;
    }

    /* Fin test du volume */

    for(i = 0; i < numkil; i++) {
      del_P = *(Delaunay **) List_Pointer(kill_L, i);
      Delete_Triangle(root, del_P);
      // MEMORY_LEAK -JF
      // Free(del_P);
    }

    *numpoints = doc->numPoints;
    Insert_Point(pt, numpoints, &numaloc, doc, BGMESH, is_3D);
    doc->points = gPointArray;
    doc->numPoints = *numpoints;

    i = 0;
    p = list;

    do {
      q = p->next;

      aa = doc->numPoints - 1;
      bb = p->point_num;
      cc = q->point_num;

      deladd = (Delaunay *) Malloc(sizeof(Delaunay));

      filldel(deladd, aa, bb, cc, doc->points, BGMESH);

      List_Put(del_L, numlink + i, &deladd);
      i++;
      p = q;

    } while(p != list);

    p = list;

    do {
      q = p;
      p = Pred(p);
      Free(q);
    } while(p != list);

    CreateLinks(del_L, i + numlink, ListContours, numcontours);

    for(j = 0; j < i; j++) {
      del_P = *(Delaunay **) List_Pointer(del_L, j + numlink);
      Insert_Triangle(root, del_P);
    }

    del = testconv(root, &conv, doc);

  }

  List_Delete(kill_L);

  numtrwait = 0;
  if(*root_w != NULL)
    avltree_count(*root_w, &numtrwait);

  numtrr = 0;
  avltree_count(*root, &numtrr);

  mai->listdel = (delpeek *) Malloc((numtrr + numtrwait + 1) * sizeof(delpeek));

  numtri = 0;
  avltree_print(*root, mai->listdel, &numtri);
  if(numtrwait != 0) {
    numtri = 0;
    avltree_print(*root_w, (Delaunay **) del_L->array, &numtri);
    for(i = 0; i < numtrwait; i++) {
      mai->listdel[i + numtrr] = *(Delaunay **) List_Pointer(del_L, i);
    }
    avltree_remove(root_w);
  }
  avltree_remove(root);

  List_Delete(del_L);

  mai->numtriangles = numtrr + numtrwait;
  mai->numpoints = doc->numPoints;
  mai->points = doc->points;

  /* Tous Les Triangles doivent etre orientes */

  if(!mai->numtriangles) {
    Msg(GERROR, "No triangles in surface mesh");
    return 0;
    //mai->numtriangles = 1;
  }

  for(i = 0; i < mai->numtriangles; i++) {
    a = mai->listdel[i]->t.a;
    b = mai->listdel[i]->t.b;
    c = mai->listdel[i]->t.c;

    mai->listdel[i]->v.voisin1 = NULL;
    if(((doc->points[b].where.h - doc->points[a].where.h) *
        (doc->points[c].where.v - doc->points[b].where.v) -
        (doc->points[c].where.h - doc->points[b].where.h) *
        (doc->points[b].where.v - doc->points[a].where.v)) > 0.0) {
      mai->listdel[i]->t.a = b;
      mai->listdel[i]->t.b = a;
    }
  }
  // MEMORY LEAK (JF)
  //  Free(doc->delaunay);
  //  doc->delaunay = 0;
  return 1;
}

void Maillage_Automatique_VieuxCode(Surface * pS, Mesh * m, int ori)
{
  ContourRecord *cp, **liste;
  List_T *c;
  Vertex *v, V[3], *ver[3], **pp[3];
  maillage M;
  int err, i, j, k, N, a, b, d;
  Simplex *s;
  double Xmin = 0., Xmax = 0., Ymin = 0., Ymax = 0.;


  if(m->BGM.Typ == WITHPOINTS) {
    is_3D = 0;
  }
  else {
    is_3D = 1;
  }

  liste =
    (ContourPeek *) Malloc(List_Nbr(pS->Contours) * sizeof(ContourPeek));

  k = 0;

  for(i = 0; i < List_Nbr(pS->Contours); i++) {
    cp = (ContourRecord *) Malloc(sizeof(ContourRecord));
    List_Read(pS->Contours, i, &c);
    cp->oriented_points =
      (PointRecord *) Malloc(List_Nbr(c) * sizeof(PointRecord));
    cp->perturbations = (MPoint *) Malloc(List_Nbr(c) * sizeof(MPoint));
    cp->numerocontour = i;

    for(j = 0; j < List_Nbr(c); j++) {
      List_Read(c, j, &v);
      if(!j) {
        Xmin = Xmax = v->Pos.X;
        Ymin = Ymax = v->Pos.Y;
      }
      else {
        Xmin = DMIN(Xmin, v->Pos.X);
        Xmax = DMAX(Xmax, v->Pos.X);
        Ymin = DMIN(Ymin, v->Pos.Y);
        Ymax = DMAX(Ymax, v->Pos.Y);
      }
    }

    LC2D = sqrt(DSQR(Xmax - Xmin) + DSQR(Ymax - Ymin));

    for(j = 0; j < List_Nbr(c); j++) {
      List_Read(c, j, &v);
      cp->oriented_points[j].where.h = v->Pos.X;
      cp->oriented_points[j].where.v = v->Pos.Y;

      // On pourrait imaginer diviser les perturbations par un facteur
      // dependant de v->lc, mais ca n'a pas l'air d'ameliorer le bignou

      cp->perturbations[j].h = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;
      cp->perturbations[j].v = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;

      cp->oriented_points[j].numcontour = i;
      cp->oriented_points[j].quality = v->lc;
      cp->oriented_points[j].permu = k++;
      cp->oriented_points[j].initial = v->Num;
    }
    cp->numpoints = List_Nbr(c);
    liste[i] = cp;
  }

  int res_mesh_domain = 1;
  if(pS->Method)
    res_mesh_domain = mesh_domain(liste, List_Nbr(pS->Contours), &M, &N,
				  (CTX.mesh.initial_only == 2));

  for(i = 0; i < M.numpoints; i++) {
    if(gPointArray[i].initial < 0) {
      gPointArray[i].initial = ++THEM->MaxPointNum;
      v = Create_Vertex(gPointArray[i].initial, gPointArray[i].where.h,
                        gPointArray[i].where.v, 0.0, gPointArray[i].quality,
                        0.0);
      if(!Tree_Search(pS->Vertices, &v))
        Tree_Add(pS->Vertices, &v);
    }
  }
  for(i = 0; i < 3; i++)
    ver[i] = &V[i];

  for(i = 0; i < M.numtriangles; i++) {

    a = M.listdel[i]->t.a;
    b = M.listdel[i]->t.b;
    d = M.listdel[i]->t.c;

    ver[0]->Num = gPointArray[a].initial;
    ver[1]->Num = gPointArray[b].initial;
    ver[2]->Num = gPointArray[d].initial;
    err = 0;
    for(j = 0; j < 3; j++) {
      if(!(pp[j] = (Vertex **) Tree_PQuery(pS->Vertices, &ver[j]))) {
        err = 1;
        Msg(GERROR, "Unknown vertex %d", ver[j]->Num);
      }
    }

    /*
       Je n'ai pas l'impression que ceci fonctionne comme voulu (essaie
       e.g. avec demos/machine.geo)...
       if (ori && !err)
       s = Create_Simplex (*pp[0], *pp[1], *pp[2], NULL);
       else if (!err)
       s = Create_Simplex (*pp[0], *pp[2], *pp[1], NULL);
       if (!err){
       s->iEnt = pS->Num;
       Tree_Insert (pS->Simplexes, &s);
       } 
     */
    if(!err) {
      s = Create_Simplex(*pp[0], *pp[2], *pp[1], NULL);
      s->iEnt = pS->Num;
      Tree_Insert(pS->Simplexes, &s);
    }

    // MEMORY LEAK (JF)
    //printf("%d %d %d\n", M.listdel[i]->t.a, M.listdel[i]->t.b, M.listdel[i]->t.c);
    //xxxxFree(M.listdel[i]);

  }
  
  if(res_mesh_domain >= 0)
    Free(M.listdel);
  Free(gPointArray);
}


void Make_Mesh_With_Points(DocRecord * ptr, PointRecord * Liste,
                           int Numpoints)
{
  ptr->numTriangles = 0;
  ptr->points = Liste;
  ptr->numPoints = Numpoints;
  ptr->delaunay = 0;
  DelaunayAndVoronoi(ptr);
  Conversion(ptr);
  remove_all_dlist(ptr->numPoints, ptr->points);
}

void filldel(Delaunay * deladd, int aa, int bb, int cc,
             PointRecord * points, DocRecord * mesh)
{
  double qual, newqual;
  MPoint pt2;
  Vertex *v, *dum;

  deladd->t.a = aa;
  deladd->t.b = bb;
  deladd->t.c = cc;
  deladd->t.info = TOLINK;
  deladd->t.info2 = 0;
  deladd->v.voisin1 = NULL;
  deladd->v.voisin2 = NULL;
  deladd->v.voisin3 = NULL;

  CircumCircle(points[aa].where.h, points[aa].where.v,
               points[bb].where.h, points[bb].where.v,
               points[cc].where.h, points[cc].where.v, 
	       &deladd->t.xc, &deladd->t.yc);

  pt2.h = deladd->t.xc;
  pt2.v = deladd->t.yc;
  if(!is_3D) {
    if(mesh) {
      newqual = find_quality(pt2, mesh);
    }
    else {
      newqual =
        (points[aa].quality + points[bb].quality + points[cc].quality) / 3.;
    }
    v = Create_Vertex(-1, pt2.h, pt2.v, 0.0, 0.0, 0.0);
    Calcule_Z_Plan(&v, &dum);
    Projette_Inverse(&v, &dum);
    Free_Vertex(&v, 0);
  }
  else {
    v = Create_Vertex(-1, pt2.h, pt2.v, 0.0, 0.0, 0.0);
    Calcule_Z_Plan(&v, &dum);
    Projette_Inverse(&v, &dum);
    qual = Lc_XYZ(v->Pos.X, v->Pos.Y, v->Pos.Z, THEM);
    if(CTX.mesh.constrained_bgmesh) {
      if(mesh) {
        newqual = MIN(qual, find_quality(pt2, mesh));
      }
      else {
        newqual =
          MIN(qual,
              (points[aa].quality + points[bb].quality +
               points[cc].quality) / 3.);
      }
    }
    else
      newqual = qual;
    Free_Vertex(&v, 0);
  }

  deladd->t.quality_value =
    sqrt((deladd->t.xc - points[cc].where.h) * (deladd->t.xc -
						points[cc].where.h) +
	 (deladd->t.yc - points[cc].where.v) * (deladd->t.yc -
						points[cc].where.v)
	 ) / newqual;
  deladd->t.position = INTERN;
}

void ActionEndTheCurve(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  End_Curve(c);
}

void ActionInvertTri(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  Vertex *tmp = s->V[1];
  s->V[1] = s->V[2];
  s->V[2] = tmp;
}

void ActionInvertQua(void *a, void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  Vertex *tmp = q->V[1];
  q->V[1] = q->V[3];
  q->V[3] = tmp;
}

// A little routine that re-orients the surface meshes so that they
// match the geometrical orientations. It would be better to generate
// the meshes correctly in the first place (!), but it's actually
// pretty nice to do it here since we use many algorithms (some
// closed) and since the mean plane computation doesn't take the
// original orientation into account.

void ReOrientSurfaceMesh(Surface *s)
{
  if(!List_Nbr(s->Generatrices))
    return;

  Curve *c;
  List_Read(s->Generatrices, 0, &c);

  if(List_Nbr(c->Vertices) < 2)
    return;

  // take the first edge (even if there are holes, we know that this
  // edge belongs to the exterior loop, due to the ordering of
  // s->Generatrices)
  Vertex *v1, *v2;
  List_Read(c->Vertices, 0, &v1);
  List_Read(c->Vertices, 1, &v2);
  Edge edge;
  edge.V[0] = v1;
  edge.V[1] = v2;

  if(Tree_Nbr(s->Simplexes)){
    EdgesContainer edges;
    edges.AddSimplexTree(s->Simplexes);
    Edge *e = (Edge*)Tree_PQuery(edges.AllEdges, &edge);
    if(e && e->V[0]->Num == v2->Num && e->V[1]->Num == v1->Num){
      Tree_Action(s->Simplexes, ActionInvertTri);
      if(Tree_Nbr(s->Quadrangles)) // for partially recombined meshes
	Tree_Action(s->Quadrangles, ActionInvertQua);
    }
  }

  if(Tree_Nbr(s->Quadrangles)){
    EdgesContainer edges;
    edges.AddQuadrangleTree(s->Quadrangles);
    Edge *e = (Edge*)Tree_PQuery(edges.AllEdges, &edge);
    if(e && e->V[0]->Num == v2->Num && e->V[1]->Num == v1->Num){
      Tree_Action(s->Quadrangles, ActionInvertQua);
      if(Tree_Nbr(s->Simplexes)) // for partially recombined meshes
	Tree_Action(s->Simplexes, ActionInvertTri);
    }
  }
}

void Maillage_Surface(void *data, void *dum)
{
  Surface **pS, *s;
  Tree_T *tnxe;
  int ori;

  pS = (Surface **) data;
  s = *pS;

  if(!s->Support)
    return;

  if(s->Dirty) {
    Msg(INFO, "Not meshing dirty Surface %d", s->Num);
    return;
  }

  if(s->Typ == MSH_SURF_STL) {
    Msg(GERROR, "Remeshing of STL surfaces is not implemented (yet)");
    return;
  }

  THESUPPORT = s->Support;
  THESURFACE = s;

  if(Tree_Nbr(s->Simplexes))
    Tree_Delete(s->Simplexes);
  s->Simplexes = Tree_Create(sizeof(Simplex *), compareQuality);
  if(Tree_Nbr(s->Vertices))
    Tree_Delete(s->Vertices);
  s->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);

  Msg(STATUS3, "Meshing surface %d", s->Num);

  if(MeshTransfiniteSurface(s) ||
     MeshEllipticSurface(s) ||
     MeshCylindricalSurface(s) ||
     MeshParametricSurface(s) ||
     Extrude_Mesh(s)) {
    Tree_Action(THEM->Points, PutVertex_OnSurf);
    Tree_Action(s->Vertices, PutVertex_OnSurf);
    Tree_Action(s->Vertices, Add_In_Mesh);
  }
  else{
    int TypSurface = s->Typ;
    Plan_Moyen(pS, dum);
    Tree_Action(THEM->Points, Freeze_Vertex);
    Tree_Action(s->Vertices, Freeze_Vertex);
    Tree_Action(THEM->Points, Projette_Plan_Moyen);
    Tree_Action(s->Vertices, Projette_Plan_Moyen);
    Tree_Action(THEM->Curves, ActionEndTheCurve);
    s->Typ = MSH_SURF_PLAN;
    End_Surface(s, 0);

    ori = Calcule_Contours(s);
    
    if(CTX.mesh.algo2d == DELAUNAY_ISO)
      Maillage_Automatique_VieuxCode(s, THEM, ori);
    else if(CTX.mesh.algo2d == DELAUNAY_ANISO)
      AlgorithmeMaillage2DAnisotropeModeJF(s);
    else
      Mesh_Triangle(s);
    
    if(CTX.mesh.nb_smoothing) {
      Msg(STATUS3, "Smoothing surface %d", s->Num);
      tnxe = Tree_Create(sizeof(NXE), compareNXE);
      create_NXE(s->Vertices, s->Simplexes, tnxe);
      for(int i = 0; i < CTX.mesh.nb_smoothing; i++)
	Tree_Action(tnxe, ActionLiss);
      delete_NXE(tnxe);
    }
    
    if(s->Recombine){
      Msg(STATUS3, "Recombining surface %d", s->Num);
      Recombine(s->Vertices, s->Simplexes, s->Quadrangles, s->RecombineAngle);
    }

    s->Typ = TypSurface;
    
    if(s->Typ != MSH_SURF_PLAN) {
      if(s->Extrude)
	s->Extrude->Rotate(s->plan);
      Tree_Action(s->Vertices, Calcule_Z);
      if(s->Extrude)
	s->Extrude->Rotate(s->invplan);
    }
    else
      Tree_Action(s->Vertices, Calcule_Z_Plan);

    Tree_Action(s->Vertices, Projette_Inverse);
    Tree_Action(THEM->Points, Projette_Inverse);
    
    Tree_Action(THEM->Points, deFreeze_Vertex);
    Tree_Action(s->Vertices, deFreeze_Vertex);
    
    Tree_Action(THEM->Points, PutVertex_OnSurf);
    Tree_Action(s->Vertices, PutVertex_OnSurf);
    Tree_Action(s->Vertices, Add_In_Mesh);
    
    Tree_Action(THEM->Curves, ActionEndTheCurve);
    End_Surface(s->Support, 0);
    End_Surface(s, 0);
    
    ReOrientSurfaceMesh(s);
  }
}
