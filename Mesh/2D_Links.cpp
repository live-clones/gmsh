// $Id: 2D_Links.cpp,v 1.18 2004-03-03 22:26:33 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "Mesh.h"
#include "2D_Mesh.h"
#include "Context.h"

extern Context_T CTX;
extern PointRecord *gPointArray;
extern DocRecord *FGMESH;

extern PointNumero First(PointNumero x);

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
  return ((i <= n) ? i : -1);
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


/* Convertir les listes d'adjacence en triangles */

int Conversion(DocPeek doc)
{
  /* on suppose que n >= 3      gPointArray est suppose OK. */

  Striangle *striangle;
  int n, i, j;
  int count = 0, count2 = 0;
  PointNumero aa, bb, cc;
  PointRecord *ptemp;

  ptemp = gPointArray;
  gPointArray = doc->points;

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
        filldel(&doc->delaunay[count], aa, bb, cc, gPointArray, NULL);
        count++;
      }
    }
  }
  for(i = 0; i < n; i++)
    Free(striangle[i].t);
  Free(striangle);
  doc->numTriangles = count2;
  gPointArray = ptemp;
  return (1);
}


int compareEdge(const void *e1, const void *e2)
{
  PointNumero tmp;

  if((tmp = ((edge *) e1)->from - ((edge *) e2)->from) != 0)
    return (tmp);
  return (((edge *) e1)->to - ((edge *) e2)->to);
}

/* pour la liste de delaunays ListDelaunay, CreateLinks cree les liens entre
   triangles c.a.d determine les voisins de chaque triangle                  */

int CreateLinks(List_T * ListDelaunay, int NumDelaunay,
                ContourRecord ** ListContours, int Nc)
{
  int i;
  edge *ListEdges;
  MPoint pt;
  Delaunay *del_Pi, *del_Pj;

  ListEdges = (edge *) Malloc((3 * NumDelaunay + 1) * sizeof(edge));

  ListEdges[3 * NumDelaunay].num = 0;
  ListEdges[3 * NumDelaunay].from = 0;
  ListEdges[3 * NumDelaunay].to = 0;

  for(i = 0; i < NumDelaunay; i++) {

    del_Pi = *(Delaunay **) List_Pointer(ListDelaunay, i);

    /* arete a b */
    if(del_Pi->t.a > del_Pi->t.b) {
      ListEdges[3 * i].from = del_Pi->t.a;
      ListEdges[3 * i].to = del_Pi->t.b;
      ListEdges[3 * i].num = i;
    }
    else {
      ListEdges[3 * i].from = del_Pi->t.b;
      ListEdges[3 * i].to = del_Pi->t.a;
      ListEdges[3 * i].num = i;
    }

    /* arete  b c */
    if(del_Pi->t.b > del_Pi->t.c) {
      ListEdges[3 * i + 1].from = del_Pi->t.b;
      ListEdges[3 * i + 1].to = del_Pi->t.c;
      ListEdges[3 * i + 1].num = i;
    }
    else {
      ListEdges[3 * i + 1].from = del_Pi->t.c;
      ListEdges[3 * i + 1].to = del_Pi->t.b;
      ListEdges[3 * i + 1].num = i;
    }

    /* arete   c a */
    if(del_Pi->t.c > del_Pi->t.a) {
      ListEdges[3 * i + 2].from = del_Pi->t.c;
      ListEdges[3 * i + 2].to = del_Pi->t.a;
      ListEdges[3 * i + 2].num = i;
    }
    else {
      ListEdges[3 * i + 2].from = del_Pi->t.a;
      ListEdges[3 * i + 2].to = del_Pi->t.c;
      ListEdges[3 * i + 2].num = i;
    }

  }

  qsort(ListEdges, 3 * NumDelaunay, sizeof(edge), compareEdge);

  i = 0;

  do {

    if((ListEdges[i].from == ListEdges[i + 1].from) &&
       (ListEdges[i].to == ListEdges[i + 1].to)) { 
      /* create link */

      del_Pi = *(Delaunay **) List_Pointer(ListDelaunay, ListEdges[i].num);
      del_Pj = *(Delaunay **) List_Pointer(ListDelaunay, ListEdges[i + 1].num);

      if((del_Pi->t.position != EXTERN) &&
         (del_Pj->t.position != EXTERN) &&
         ((del_Pj->t.info == TOLINK) || (del_Pi->t.info == TOLINK))) {

        if(del_Pi->v.voisin1 == NULL)
          del_Pi->v.voisin1 = del_Pj;
        else if(del_Pi->v.voisin2 == NULL)
          del_Pi->v.voisin2 = del_Pj;
        else if(del_Pi->v.voisin3 == NULL)
          del_Pi->v.voisin3 = del_Pj;
        else
          Msg(GERROR, "Bad link for triangle");

        if(del_Pj->v.voisin1 == NULL)
          del_Pj->v.voisin1 = del_Pi;
        else if(del_Pj->v.voisin2 == NULL)
          del_Pj->v.voisin2 = del_Pi;
        else if(del_Pj->v.voisin3 == NULL)
          del_Pj->v.voisin3 = del_Pi;
        else
          Msg(GERROR, "Bad link for triangle");
      }
      i += 2;
    }
    else{
      i++;
    }
  } while(i < 3 * NumDelaunay);

  Free(ListEdges);

  for(i = 0; i < NumDelaunay; i++) {
    del_Pi = *(Delaunay **) List_Pointer(ListDelaunay, i);

    if(del_Pi->t.position != EXTERN) {
      pt.h = del_Pi->t.xc;
      pt.v = del_Pi->t.yc;

      if(!PtInTriangle(pt, del_Pi->t.a, del_Pi->t.b, del_Pi->t.c)) {
        if(!Find_Triangle(pt, FGMESH, A_TOUT_PRIX)) {
          del_Pi->t.quality_value /= 1000.;
        }
      }
    }
  }

  return (1);
}
