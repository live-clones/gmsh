#ifndef _2D_MESH_H_
#define _2D_MESH_H_

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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

typedef struct avl{
  void *treedata;
  int balance;
  struct avl *left;
  struct avl *right;
}avlstruct;

typedef avlstruct *avlptr;

int  remove_tree (avlstruct ** root);
int  insert_avltree (avlstruct ** root, void *item, 
                     int (*fcmp)(void *a, void *b));
int  delete_avltree (avlstruct ** root, void *item, 
                     int (*fcmp)(void *a, void *b));
int  avltree_remove (avlstruct **root);
void avltree_count (avlptr root, int *numtri);
void avltree_print (avlptr root, Delaunay **listdel, int *numtri);
int  avltree_insert (avlstruct **root, void *item, 
                     int (*fcmp)(void *a, void *b));
int  avltree_delete (avlstruct **root, void *item, 
                     int (*fcmp)(void *a, void *b));
void findtree(avlptr root, double *qualm, 
              Delaunay **delf, DocRecord *MESH);
Delaunay *findrightest(avlptr root, DocRecord *MESH);


PointNumero Successor(PointNumero a,PointNumero b);

Delaunay * Find_Triangle (MPoint pt, DocRecord *MESH, int typ);
int Insert_Triangle (avlstruct **root, Delaunay * del);
int Delete_Triangle ( avlstruct **root, Delaunay * del );
int Insert_Point (MPoint pt, int *numpoints, int *numalloc, 
                  DocRecord *doc, DocRecord *BGM, int is3d);
MPoint Localize (Delaunay * del , DocRecord *MESH);
void alloue_Mai_Pts(maillage *mai , int Nballoc , int incrAlloc);
void alloue_Mai_Del(maillage *mai , int Nballoc , int incrAlloc);

void InitBricks (DocRecord *MESH);
int PtInTriangle(MPoint p , PointNumero a , PointNumero b , PointNumero c);
int DelaunayAndVoronoi(DocPeek doc);

int Conversion(DocPeek doc );
int CreateLinks(List_T * ListDelaunay , int NumDelaunay, 
                ContourRecord **ListContours , int Nc);

void makepermut (int numpoints);
void verify_edges (List_T *ListDelaunay, ContourRecord **ListContour, 
                   int NumContours);
void verify_inside (Delaunay * ListDelaunay ,  int NumDelaunay );

void PushgPointArray(PointRecord *ptr);
void remove_all_dlist(int n, PointRecord *pPointArray);

int PE_Del_Triangle (Delaunay *del , MPoint pt, DListPeek *ListEdges ,
                     List_T *listkill, List_T *listDelforlink,
                     int *numlink, int *numdel);

void filldel (Delaunay * deladd, int aa, int bb, int cc,
              PointRecord * points, DocRecord * mesh);

int CircumCircle(double x1,double y1,double x2,double y2,double x3,double y3,
                 double *xc,double *yc);
double find_quality (MPoint center, DocRecord * BGMESH);
void create_NXE (Tree_T * TreeAllNod, Tree_T * TreeAllElg,
                 Tree_T * TreeAllNXE);
void delete_NXE (Tree_T * TreeAllNXE);

int Is_left_of(PointNumero x,PointNumero y,PointNumero check);
int Is_right_of(PointNumero x,PointNumero y,PointNumero check);
int DListInsert(DListRecord **dlist, MPoint center, PointNumero newPoint);
int DListDelete(DListPeek *dlist,PointNumero oldPoint);

#endif
