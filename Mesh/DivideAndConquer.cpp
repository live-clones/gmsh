// $Id: DivideAndConquer.cpp,v 1.6 2006-11-30 13:55:20 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

/*
   A L G O R I T H M E    D I V I D E    A N D     C O N Q U E R   

   le noeud de cette methode est de pouvoir fusionner
   deux triangulations de Delaunay en une seule (routine merge)
   on procede alors recursivement en separant les points en deux
   groupes puis en separant les groupes en 2 ... jusqu'a n'obtenir
   que 1 2 ou 3 points (la triangulation est alors triviale)

   Dans le mailleur, on utilise cet algorithme pour construire 
   le maillage initial 

   !!! il faut PERTURBER les points d'une faible valeur aleatoire
   pour eviter d'avoir 3 points alignes ou 4 points cocycliques !!!

   doc : structure contenant la triangulation
*/

#include "Gmsh.h"
#include "Numeric.h"
#include "DivideAndConquer.h"
#include "Context.h"

#define EXTERN    1
#define INTERN    2

#define NOTTOLINK 1
#define TOLINK    2

extern Context_T CTX;

static PointRecord *pPointArray;

int Insert(PointNumero a, PointNumero b);
int Delete(PointNumero a, PointNumero b);

PointNumero Predecessor(PointNumero a, PointNumero b)
{
  DListPeek p = pPointArray[a].adjacent;
  if(p == NULL)
    return -1;

  do {
    if(p->point_num == b)
      return Pred(p)->point_num;
    p = Pred(p);
  } while(p != pPointArray[a].adjacent);

  return -1;
}

PointNumero Successor(PointNumero a, PointNumero b)
{
  DListPeek p = pPointArray[a].adjacent;
  if(p == NULL)
    return -1;

  do {
    if(p->point_num == b)
      return Succ(p)->point_num;
    p = Succ(p);
  } while(p != pPointArray[a].adjacent);

  return -1;
}

int FixFirst(PointNumero x, PointNumero f)
{
  DListPeek p = pPointArray[x].adjacent;
  if(p == NULL)
    return 0;

  int out = 0;
  DListPeek copy = p;
  do {
    if(p->point_num == f) {
      pPointArray[x].adjacent = p;
      out = 1;
    }
    else
      p = p->next;
  } while((p != copy) && !out);
  return out;
}

PointNumero First(PointNumero x)
{
  return (pPointArray[x].adjacent)->point_num;
}

int Is_left_of(PointNumero x, PointNumero y, PointNumero check)
{
  double pa[2] = {(double)pPointArray[x].where.h, (double)pPointArray[x].where.v};
  double pb[2] = {(double)pPointArray[y].where.h, (double)pPointArray[y].where.v};
  double pc[2] = {(double)pPointArray[check].where.h, (double)pPointArray[check].where.v};
  // we use robust predicates here
  double result = gmsh::orient2d(pa, pb, pc);
  return result > 0;
}

int Is_right_of(PointNumero x, PointNumero y, PointNumero check)
{
  return Is_left_of(y, x, check);
}

Segment LowerCommonTangent(DT vl, DT vr)
{
  PointNumero x, y, z, z1, z2, temp;
  Segment s;

  x = vl.end;   /* vu le tri, c'est le point le + a droite     */
  y = vr.begin; /* idem, le + a gauche     */
  z = First(y);
  z1 = First(x);
  z2 = Predecessor(x, z1);
  for(;;) {
    if(Is_right_of(x, y, z)) {
      temp = z;
      z = Successor(z, y);
      y = temp;
    }
    else if(Is_right_of(x, y, z2)) {
      temp = z2;
      z2 = Predecessor(z2, x);
      x = temp;
    }
    else {
      s.from = x;
      s.to = y;
      return s;
    }
  }
}

Segment UpperCommonTangent(DT vl, DT vr)
{
  PointNumero x, y, z, z1, z2, temp;
  Segment s;

  x = vl.end;   /* vu le tri, c'est le point le + a droite     */
  y = vr.begin; /* idem, le + a gauche     */
  z = First(y);
  z1 = First(x);
  z2 = Predecessor(y, z);
  for(;;) {
    if(Is_left_of(x, y, z2)) {
      temp = z2;
      z2 = Predecessor(z2, y);
      y = temp;
    }
    else if(Is_left_of(x, y, z1)) {
      temp = z1;
      z1 = Successor(z1, x);
      x = temp;
    }
    else {
      s.from = x;
      s.to = y;
      return s;
    }
  }
}

/* return 1 if the point k is NOT in the circumcircle of triangle
   hij */
int Qtest(PointNumero h, PointNumero i, PointNumero j, PointNumero k)
{
  if((h == i) && (h == j) && (h == k)) {
    Msg(GERROR, "3 identical points in Qtest");
    return 0; /* returning 1 will cause looping for ever */
  }
  
  double pa[2] = {(double)pPointArray[h].where.h, (double)pPointArray[h].where.v};
  double pb[2] = {(double)pPointArray[i].where.h, (double)pPointArray[i].where.v};
  double pc[2] = {(double)pPointArray[j].where.h, (double)pPointArray[j].where.v};
  double pd[2] = {(double)pPointArray[k].where.h, (double)pPointArray[k].where.v};

  // we use robust predicates here  
  double result = gmsh::incircle(pa, pb, pc, pd) * gmsh::orient2d(pa, pb, pc);
  
  return (result < 0) ? 1 : 0;
}

int merge(DT vl, DT vr)
{
  Segment bt, ut;
  int a, b, out;
  PointNumero r, r1, r2, l, l1, l2;

  bt = LowerCommonTangent(vl, vr);
  ut = UpperCommonTangent(vl, vr);
  l = bt.from;  /* left endpoint of BT     */
  r = bt.to;    /* right endpoint of BT     */

  while((l != ut.from) || (r != ut.to)) {
    a = b = 0;
    if(!Insert(l, r))
      return 0;

    r1 = Predecessor(r, l);
    if(r1 == -1)
      return 0;
    if(Is_right_of(l, r, r1))
      a = 1;
    else {
      out = 0;
      while(!out) {
        r2 = Predecessor(r, r1);
        if(r2 == -1)
          return 0;
        if(r2 < vr.begin)
          out = 1;
        else if(Qtest(l, r, r1, r2))
          out = 1;
        else {
          if(!Delete(r, r1))
            return 0;
          r1 = r2;
          if(Is_right_of(l, r, r1))
            out = a = 1;
        }
      }
    }

    l1 = Successor(l, r);
    if(l1 == -1)
      return 0;
    if(Is_left_of(r, l, l1))
      b = 1;
    else {
      out = 0;
      while(!out) {
        l2 = Successor(l, l1);
        if(l2 == -1)
          return 0;
        if(l2 > vl.end)
          out = 1;
        else if(Qtest(r, l, l1, l2))
          out = 1;
        else {
          if(!Delete(l, l1))
            return 0;
          l1 = l2;
          if(Is_left_of(r, l, l1))
            out = b = 1;
        }
      }
    }

    if(a)
      l = l1;
    else if(b)
      r = r1;
    else {
      if(Qtest(l, r, r1, l1))
        r = r1;
      else
        l = l1;
    }
  }
  if(!Insert(l, r))
    return 0;

  if(!FixFirst(ut.to, ut.from))
    return 0;
  if(!FixFirst(bt.from, bt.to))
    return 0;
  return 1;
}

DT recur_trig(PointNumero left, PointNumero right)
{
  int n, m;
  DT dt;

  dt.begin = left;
  dt.end = right;
  n = right - left + 1; /* nombre de points a triangulariser */
  switch (n) {
  case 0:
  case 1:
    /* 0 ou 1 points -> rien a faire */
    break;

  case 2:      /* deux points : cas trivial     */
    Insert(left, right);
    FixFirst(left, right);
    FixFirst(right, left);
    break;

  case 3:      /* trois points : cas trivial     */
    Insert(left, right);
    Insert(left, left + 1);
    Insert(left + 1, right);
    if(Is_right_of(left, right, left + 1)) {
      FixFirst(left, left + 1);
      FixFirst(left + 1, right);
      FixFirst(right, left);
    }
    else {
      FixFirst(left, right);
      FixFirst(left + 1, left);
      FixFirst(right, left + 1);
    }
    break;

  default:     /* plus de trois points : cas recursif     */
    m = (left + right) >> 1;
    if(!merge(recur_trig(left, m), recur_trig(m + 1, right)))

      break;
  }
  return dt;
}

int comparePoints(const void *i, const void *j)
{
  double x, y;

  x = ((PointRecord *) i)->where.h - ((PointRecord *) j)->where.h;
  if(x == 0.) {
    y = ((PointRecord *) i)->where.v - ((PointRecord *) j)->where.v;
    return (y < 0.) ? -1 : 1;
  }
  else
    return (x < 0.) ? -1 : 1;
}

/*  this fonction builds the delaunay triangulation and the voronoi
    for a window. All error handling is done here. */
int DelaunayAndVoronoi(DocPeek doc)
{
  pPointArray = doc->points;

  if(doc->numPoints < 2)
    return 1;

  qsort(doc->points, doc->numPoints, sizeof(PointRecord), comparePoints);
  recur_trig(0, doc->numPoints - 1);

  return 1;
}

/* This routine insert the point 'newPoint' in the list dlist,
   respecting the clock-wise orientation. */
int DListInsert(DListRecord ** dlist, MPoint center, PointNumero newPoint)
{
  DListRecord *p, *newp;
  double alpha1, alpha, beta, xx, yy;
  int first;

  newp = (DListRecord *) Malloc(sizeof(DListRecord));
  newp->point_num = newPoint;

  if(*dlist == NULL) {
    *dlist = newp;
    Pred(*dlist) = newp;
    Succ(*dlist) = newp;
    return 1;
  }
  if(Succ(*dlist) == *dlist) {
    Pred(*dlist) = newp;
    Succ(*dlist) = newp;
    Pred(newp) = *dlist;
    Succ(newp) = *dlist;
    return 1;
  }
  /*  If we are here, the double-linked circular list has 2 or more
     elements, so we have to calculate where to put the new one. */

  p = *dlist;
  first = p->point_num;

  /* first, compute polar coord. of the first point. */
  yy = (double)(pPointArray[first].where.v - center.v);
  xx = (double)(pPointArray[first].where.h - center.h);
  alpha1 = atan2(yy, xx);

  /* compute polar coord of the point to insert. */
  yy = (double)(pPointArray[newPoint].where.v - center.v);
  xx = (double)(pPointArray[newPoint].where.h - center.h);
  beta = atan2(yy, xx) - alpha1;
  if(beta <= 0)
    beta += Deux_Pi;

  do {
    yy = (double)(pPointArray[Succ(p)->point_num].where.v - center.v);
    xx = (double)(pPointArray[Succ(p)->point_num].where.h - center.h);
    alpha = atan2(yy, xx) - alpha1;
    if(alpha <= 1.e-15)
      alpha += Deux_Pi;
    if(alpha >= beta) {
      Succ(newp) = Succ(p);
      Succ(p) = newp;
      Pred(newp) = p;
      Pred(Succ(newp)) = newp;
      return 1;
    }
    p = Succ(p);
  } while(p != *dlist);

  /* never here! */
  return 0;
}

int Insert(PointNumero a, PointNumero b)
{
  int rslt;

  /* This routine inserts the point 'a' in the adjency list of 'b' and
     the point 'b' in the adjency list of 'a'.          */

  rslt = DListInsert(&pPointArray[a].adjacent, pPointArray[a].where, b);
  rslt &= DListInsert(&pPointArray[b].adjacent, pPointArray[b].where, a);

  return rslt;
}

int DListDelete(DListPeek * dlist, PointNumero oldPoint)
{
  DListPeek p;

  if(*dlist == NULL)
    return 0;
  if(Succ(*dlist) == *dlist) {
    if((*dlist)->point_num == oldPoint) {
      Free(*dlist);
      *dlist = NULL;
      return 1;
    }
    else
      return 0;
  }
  p = *dlist;
  do {
    if(p->point_num == oldPoint) {
      Succ(Pred(p)) = Succ(p);
      Pred(Succ(p)) = Pred(p);
      if(p == *dlist) {
        *dlist = Succ(p);
      }
      Free(p);
      return 1;
    }
    p = Succ(p);
  } while(p != *dlist);

  return 0;
}

/* This routine removes the point 'a' in the adjency list of 'b' and
   the point 'b' in the adjency list of 'a'.          */

int Delete(PointNumero a, PointNumero b)
{
  int rslt;

  rslt = DListDelete(&pPointArray[a].adjacent, b);
  rslt &= DListDelete(&pPointArray[b].adjacent, a);

  return rslt;
}

/* compte les points sur le polygone convexe */

int CountPointsOnHull(int n, PointRecord * pPointArray)
{
  PointNumero p, p2, temp;
  int i;

  if(pPointArray[0].adjacent == NULL)
    return 0;
  i = 1;
  p = 0;
  p2 = First(0);
  while((p2 != 0) && (i < n)) {
    i++;
    temp = p2;
    p2 = Successor(p2, p);
    p = temp;
  }
  return (i <= n) ? i : -1;
}

PointNumero *ConvertDlistToArray(DListPeek * dlist, int *n)
{
  DListPeek p, temp;
  int i, max = 0;
  PointNumero *ptr;

  p = *dlist;
  do {
    max++;
    p = Pred(p);
  } while(p != *dlist);
  ptr = (PointNumero *) Malloc((max + 1) * sizeof(PointNumero));
  if(ptr == NULL)
    return NULL;
  p = *dlist;
  for(i = 0; i < max; i++) {
    ptr[i] = p->point_num;
    temp = p;
    p = Pred(p);
    Free(temp);
  }
  ptr[max] = ptr[0];
  *dlist = NULL;
  *n = max;
  return ptr;
}

void filldel(Delaunay * deladd, int aa, int bb, int cc,
             PointRecord * points)
{
  double qual, newqual;
  MPoint pt2;

  deladd->t.a = aa;
  deladd->t.b = bb;
  deladd->t.c = cc;
  deladd->v.voisin1 = NULL;
  deladd->v.voisin2 = NULL;
  deladd->v.voisin3 = NULL;
}

/* Convertir les listes d'adjacence en triangles */

int Conversion(DocPeek doc)
{
  /* on suppose que n >= 3      gPointArray est suppose OK. */

  Striangle *striangle;
  int n, i, j;
  int count = 0, count2 = 0;
  PointNumero aa, bb, cc;
  PointRecord *ptemp;

  PointRecord *gPointArray = doc->points;

  n = doc->numPoints;
  striangle = (Striangle *) Malloc(n * sizeof(Striangle));
  count2 = (int)CountPointsOnHull(n, doc->points);

  /* nombre de triangles que l'on doit obtenir */
  count2 = 2 * (n - 1) - count2;

  if(doc->delaunay)
    Free(doc->delaunay);

  doc->delaunay = (Delaunay *) Malloc(2 * count2 * sizeof(Delaunay));

  for(i = 0; i < n; i++) {
    /* on cree une liste de points connectes au point i (t) + nombre de points (t_length) */
    striangle[i].t =
      ConvertDlistToArray(&gPointArray[i].adjacent, &striangle[i].t_length);
    striangle[i].info = NULL;
    striangle[i].info_length = 0;
  }

  /* on balaye les noeuds de gauche a droite -> on cree les triangles  */
  count = 0;
  for(i = 0; i < n; i++) {
    for(j = 0; j < striangle[i].t_length; j++) {
      if((striangle[i].t[j] > i) && (striangle[i].t[j + 1] > i) &&
         (Is_right_of(i, striangle[i].t[j], striangle[i].t[j + 1]))) {
        aa = i;
        bb = striangle[i].t[j];
        cc = striangle[i].t[j + 1];
        filldel(&doc->delaunay[count], aa, bb, cc, gPointArray);
        count++;
      }
    }
  }
  for(i = 0; i < n; i++)
    Free(striangle[i].t);
  Free(striangle);
  doc->numTriangles = count2;

  return 1;
}

/*  Cette routine efface toutes les listes d'adjacence du pPointArray. */

void remove_all_dlist(int n, PointRecord * pPointArray)
{
  int i;
  DListPeek p, temp;

  for(i = 0; i < n; i++)
    if(pPointArray[i].adjacent != NULL) {
      p = pPointArray[i].adjacent;
      do {
        temp = p;
        p = Pred(p);
        Free(temp);
      } while(p != pPointArray[i].adjacent);
      pPointArray[i].adjacent = NULL;
    }
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
