// $Id: 2D_Bowyer.cpp,v 1.15 2004-02-07 01:40:20 geuzaine Exp $
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

/*
   A L G O R I T H M E   D E   B O W Y E R  -  W A T S O N

   definition : il est possible d'obtenir une triangulation de Delaunay en partant 
   d'une triangulation existante en lui ajoutant un noeud de la facon suivante :

   - on elimine les triangles de la premiere triangulation dont le cercle
   circonscrit contient le nouveau point
   - on reconstuit une triangulation en joignant le point aux noeuds du polygone
   defini par les triangles effaces

   ListEdges = liste liee circulaire et triee contenant les points du polygone
   listkill = liste des pointeurs des triangles a effacer
   listDelforLink = liste des triangles a la peripherie du polygone
   PE_Del_Triangle = Peut-Etre va-t-on effacer le triangle del, si on l'efface alors
   on appelle recursivement 3 fois PE_Del_Triangle avec ses trois voisins (si il en a)
   comme argument
*/

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "2D_Mesh.h"

extern PointRecord *gPointArray;

int Is_pt_in_CircCircle(Delaunay * del, MPoint pt)
{
  double rc, dc, Xa, Ya;
  PointNumero a;

  dc = DSQR(del->t.xc - pt.h) + DSQR(del->t.yc - pt.v);

  a = del->t.a;

  Xa = gPointArray[a].where.h;
  Ya = gPointArray[a].where.v;

  rc = DSQR(del->t.xc - Xa) + DSQR(del->t.yc - Ya);

  if(rc >= dc)
    return 1;
  return 0;

}

int PE_Del_Triangle(Delaunay * del, MPoint pt, DListPeek * ListEdges,
                    List_T * listkill, List_T * listDelforlink,
                    int *numlink, int *numdel)
{
  int rslt;
  PointNumero a, b, c;
  int count, order[3], same;
  DListPeek p;
  Delaunay *de1, *de2, *de3;

  rslt = Is_pt_in_CircCircle(del, pt);

  if((!rslt) && (*numdel == 0)) {
    return (0);
  }
  if(!rslt) {

    /* On retient les triangles du pourtour */

    del->t.info = NOTTOLINK;
    List_Put(listDelforlink, *numlink, &del);
    (*numlink)++;

    return (1);

  }
  else {

    List_Put(listkill, *numdel, &del);
    (*numdel)++;

    a = del->t.a;
    b = del->t.b;
    c = del->t.c;

    if(*ListEdges == NULL) {

      rslt = DListInsert(ListEdges, pt, a);
      rslt &= DListInsert(ListEdges, pt, b);
      rslt &= DListInsert(ListEdges, pt, c);
      if(!rslt)
        Msg(GERROR, "List insert failed in Boyer Watson");

    }
    else {

      count = 0;
      p = *ListEdges;
      order[0] = order[1] = order[2] = 0;
      same = 0;

      do {
        if(p->point_num == a) {
          same = same + 1;
          order[count] = a;
          count++;
        }
        if(p->point_num == b) {
          same = same + 10;
          order[count] = b;
          count++;
        }
        if(p->point_num == c) {
          same = same + 100;
          order[count] = c;
          count++;
        }
        p = Pred(p);
      } while(p != *ListEdges);
      if(count == 1) {
        return (0);
      }
      else if(count == 2) {
        if(same == 11) {
          rslt = DListInsert(ListEdges, pt, c);
        }
        if(same == 101) {
          rslt = DListInsert(ListEdges, pt, b);
        }
        if(same == 110) {
          rslt = DListInsert(ListEdges, pt, a);
        }
      }
      else if(count == 3) {
        rslt = DListDelete(ListEdges, order[1]);
      }
      else {
        return (0);
      }
    }

    de1 = del->v.voisin1;
    de2 = del->v.voisin2;
    de3 = del->v.voisin3;


    if(de1 != NULL) {
      if(de1->v.voisin1 == del)
        de1->v.voisin1 = NULL;
      else if(de1->v.voisin2 == del)
        de1->v.voisin2 = NULL;
      else if(de1->v.voisin3 == del)
        de1->v.voisin3 = NULL;
      else
        Msg(GERROR, "Bad link in Boyer Watson");
    }
    if(de2 != NULL) {
      if(de2->v.voisin1 == del)
        de2->v.voisin1 = NULL;
      else if(de2->v.voisin2 == del)
        de2->v.voisin2 = NULL;
      else if(de2->v.voisin3 == del)
        de2->v.voisin3 = NULL;
      else
        Msg(GERROR, "Bad link in Boyer Watson");
    }
    if(de3 != NULL) {
      if(de3->v.voisin1 == del)
        de3->v.voisin1 = NULL;
      else if(de3->v.voisin2 == del)
        de3->v.voisin2 = NULL;
      else if(de3->v.voisin3 == del)
        de3->v.voisin3 = NULL;
      else
        Msg(GERROR, "Bad link in Boyer Watson");
    }

    del->v.voisin1 = NULL;
    del->v.voisin2 = NULL;
    del->v.voisin3 = NULL;


    if(de1 != NULL) {
      if(!PE_Del_Triangle
         (de1, pt, ListEdges, listkill, listDelforlink, numlink, numdel))
        return (0);
    }
    if(de2 != NULL) {
      if(!PE_Del_Triangle
         (de2, pt, ListEdges, listkill, listDelforlink, numlink, numdel))
        return (0);
    }
    if(de3 != NULL) {
      if(!PE_Del_Triangle
         (de3, pt, ListEdges, listkill, listDelforlink, numlink, numdel))
        return (0);
    }
    return (1);
  }
}
