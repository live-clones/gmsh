#ifndef _DIVIDE_AND_CONQUER_H_
#define _DIVIDE_AND_CONQUER_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

typedef struct _POINT PointRecord, *PointPeek;
typedef struct _CONTOUR ContourRecord, *ContourPeek;
typedef struct _DOC DocRecord, *DocPeek;
typedef struct _CDLIST DListRecord, *DListPeek;
typedef struct _MAILLAGE maillage, *maipeek;
typedef struct _DELAUNAY Delaunay, *delpeek;
typedef int PointNumero;

struct _DOC{
  PointRecord *points;  // points to triangulate
  int numPoints;        // number of points
  int numTriangles;     // number of triangles
  Delaunay *delaunay;   // 2D results
};

typedef struct{
  double v;
  double h;
}MPoint;

struct _POINT{
  MPoint where;
  DListPeek adjacent;
  int initial, permu, numcontour;
  double quality;
  void *data;
};

struct _CDLIST{
  PointNumero point_num;
  DListPeek next, prev;
};

typedef struct{
  PointNumero search;
  PointNumero already;
}demi_triangle;

typedef struct{
  demi_triangle *info;
  PointNumero *t;
  int t_length, info_length;
}Striangle;

typedef struct {
  PointNumero from;
  PointNumero to;
  int num;
  int seg;
}edge;

typedef struct{
  PointNumero begin;
  PointNumero end;
}DT;

typedef struct{
  PointNumero from;
  PointNumero to;
}Segment;

typedef struct{
  PointNumero a, b, c;
  double xc, yc;
  double quality_value;
  int position, info, info2;
}Triangle;

typedef struct {
  Delaunay *voisin1, *voisin2, *voisin3;
}Voronoi;

struct _DELAUNAY{
  Triangle t;
  Voronoi v;
};

struct _CONTOUR{
  PointRecord *oriented_points;
  MPoint *perturbations;
  int numpoints, numerocontour, numerozon, info;
};

struct _MAILLAGE{
  PointRecord *points;
  delpeek *listdel;
  edge *listedges;
  int numedges, numtriangles, numpoints;
  int zone;
};

void Make_Mesh_With_Points(DocRecord * ptr, PointRecord * Liste, int Numpoints);

#endif
