// $Id: 2D_Util.cpp,v 1.23 2005-01-01 19:35:30 geuzaine Exp $
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
#include "Mesh.h"
#include "2D_Mesh.h"
#include "Context.h"

extern Context_T CTX;
extern PointRecord *gPointArray;
extern Mesh *THEM;

int Comparekey(void *d1, void *d2)
{
  double val;
  PointNumero a, b, c, aa, bb, cc;

  a = ((Delaunay *) d1)->t.a;
  b = ((Delaunay *) d1)->t.b;
  c = ((Delaunay *) d1)->t.c;
  aa = ((Delaunay *) d2)->t.a;
  bb = ((Delaunay *) d2)->t.b;
  cc = ((Delaunay *) d2)->t.c;

  val =
    ((Delaunay *) d2)->t.quality_value - ((Delaunay *) d1)->t.quality_value;

  if((aa == a) && (bb == b) && (cc == c)) {
    return 0;
  }
  else if(val > 1.e-21)
    return 1;
  else if(val < -1.e-21)
    return -1;
  else {
    if(((Delaunay *) d1)->t.xc > ((Delaunay *) d2)->t.xc)
      return -1;
    else
      return 1;
  }
}

int Insert_Triangle(avlstruct ** root, Delaunay * del)
{
  if(!avltree_insert(root, del, Comparekey))
    return (0);

  return (1);
}

int Delete_Triangle(avlstruct ** root, Delaunay * del)
{
  if(!avltree_delete(root, del, Comparekey))
    return (0);

  if(*root == NULL)
    return (0);
  return (1);
}

int Insert_Point(MPoint pt, int *numpoints, int *numalloc,
                 DocRecord * doc, DocRecord * BGM, int is3d)
{
  Vertex *v, *dum;
  double qual;

  if(*numpoints >= *numalloc) {
    gPointArray = (PointRecord *) Realloc(gPointArray,
                                          (*numalloc +
                                           1000) * sizeof(PointRecord));
    *numalloc += 1000;
    doc->points = gPointArray;
  }
  PushgPointArray(gPointArray);
  gPointArray[*numpoints].where.h = pt.h;
  gPointArray[*numpoints].where.v = pt.v;
  gPointArray[*numpoints].numcontour = -1;
  gPointArray[*numpoints].initial = -1;
  if(!is3d)
    gPointArray[*numpoints].quality = find_quality(pt, BGM);
  else {
    v = Create_Vertex(-1, pt.h, pt.v, 0.0, 0.0, 0.0);
    Calcule_Z_Plan(&v, &dum);
    Projette_Inverse(&v, &dum);
    qual = Lc_XYZ(v->Pos.X, v->Pos.Y, v->Pos.Z, THEM);
    if(CTX.mesh.constrained_bgmesh)
      gPointArray[*numpoints].quality = MIN(find_quality(pt, BGM), qual);
    else
      gPointArray[*numpoints].quality = qual;
    Free_Vertex(&v, 0);
  }

  (*numpoints)++;

  return 1;
}

void findtree(avlptr root, double *qualm, Delaunay ** delf, DocRecord * MESH)
{
  /* 
     trouve le triangle possedant le facteur de qualite max 
     modif : le centre du cercle circonscrit de ce triangle
     doit etre dans le domaine   
   */

  MPoint pt;
  double q;
  Delaunay *del;

  if(root != NULL) {
    findtree((root)->left, qualm, delf, MESH);
    del = (Delaunay *) root->treedata;
    q = del->t.quality_value;
    pt.h = del->t.xc;
    pt.v = del->t.yc;
    if((q > *qualm) && (Find_Triangle(pt, MESH, A_TOUT_PRIX) != NULL)) {
      *qualm = q;
      *delf = del;
    }
    findtree((root)->right, qualm, delf, MESH);
  }
}

Delaunay *findrightest(avlptr root, DocRecord * MESH)
{
  Delaunay *del, **dee;
  MPoint pt;
  avlptr exroot;
  double qualm;

  exroot = root;

  while((exroot)->left != NULL) {
    exroot = (exroot)->left;
  }

  del = (Delaunay *) (exroot)->treedata;
  pt.h = del->t.xc;
  pt.v = del->t.yc;

  if(Find_Triangle(pt, MESH, A_TOUT_PRIX) != NULL)
    return del;

  exroot = root;
  del = (Delaunay *) (root)->treedata;
  qualm = del->t.quality_value;
  dee = &del;
  findtree(exroot, &qualm, dee, MESH);
  del = *dee;

  return (del);
}

MPoint Localize(Delaunay * del, DocRecord * MESH)
{
  MPoint pt;

  switch (CTX.mesh.point_insertion) {
  case BARYCENTER:
    pt.h = (gPointArray[del->t.a].where.h + gPointArray[del->t.b].where.h
            + gPointArray[del->t.c].where.h) / 3.;
    pt.v = (gPointArray[del->t.a].where.v + gPointArray[del->t.b].where.v
            + gPointArray[del->t.c].where.v) / 3.;
    return pt;
  case CENTER_CIRCCIRC:
  default:
    pt.h = del->t.xc;
    pt.v = del->t.yc;
    return pt;
  }
}
