// $Id: 2D_Mesh_Triangle.cpp,v 1.10 2004-07-14 22:42:26 geuzaine Exp $
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
#include "Mesh.h"
#include "Numeric.h"
#include "Context.h"

#if !defined(HAVE_TRIANGLE)

int Mesh_Triangle(Surface * s)
{
  Msg(GERROR, "Triangle is not compiled in this version of Gmsh");
  return 1;
}

#else

#define ANSI_DECLARATORS
#define REAL double

extern "C"
{
#include "triangle.h"
}

extern Context_T CTX;
extern Mesh *THEM;

void AddInMesh(Surface * sur, int nbbound, Vertex ** vertexbound,
               struct triangulateio *out)
{
  int i;
  Vertex **vtable;
  Simplex *s;

  //Msg(INFO, "Add in database...");

  vtable = (Vertex **) Malloc(out->numberofpoints * sizeof(Vertex *));

  for(i = 0; i < nbbound; i++)
    vtable[i] = vertexbound[i];
  Free(vertexbound);

  for(i = nbbound; i < out->numberofpoints; i++) {
    vtable[i] = Create_Vertex(++(THEM->MaxPointNum),
                              out->pointlist[i * 2],
                              out->pointlist[i * 2 + 1], 0.0,
                              out->pointattributelist[i], 0.0);
    Tree_Add(sur->Vertices, &vtable[i]);
  }

  Free(out->pointlist);
  Free(out->pointattributelist);

  for(i = 0; i < out->numberoftriangles; i++) {
    s = Create_Simplex(vtable[out->trianglelist[i * out->numberofcorners + 0]],
		       vtable[out->trianglelist[i * out->numberofcorners + 1]],
		       vtable[out->trianglelist[i * out->numberofcorners + 2]],
		       NULL);
    s->iEnt = sur->Num;
    Tree_Add(sur->Simplexes, &s);
  }

  Free(vtable);
  Free(out->trianglelist);
  Free(out->triangleattributelist);

  //Msg(INFO, "...done");
}

// This is horrible...

void FindPointInHole(List_T * verts, REAL * x, REAL * y)
{
  Vertex *v1, *v2;
  double a[3], b[3], c[3];
  List_Read(verts, 0, &v1);
  List_Read(verts, 1, &v2);
  a[0] = v2->Pos.X - v1->Pos.X;
  a[1] = v2->Pos.Y - v1->Pos.Y;
  a[2] = 0.;
  b[0] = 0.;
  b[1] = 0.;
  b[2] = 1.;
  prodve(b, a, c);
  norme(c);
  *x = 0.5 * (v1->Pos.X + v2->Pos.X) + 1.e-12 * CTX.lc * c[0];
  *y = 0.5 * (v1->Pos.Y + v2->Pos.Y) + 1.e-12 * CTX.lc * c[1];
}

int Mesh_Triangle(Surface * s)
{
  char opts[128];
  int i, j, k, l, NbPts = 0, first;
  double val;
  List_T *list;
  Vertex *v, **vtable;
  struct triangulateio in, mid, out;

  for(i = 0; i < List_Nbr(s->Contours); i++) {
    List_Read(s->Contours, i, &list);
    NbPts += List_Nbr(list);
  }

  in.numberofpoints = NbPts;
  in.pointlist = (REAL *) Malloc(in.numberofpoints * 2 * sizeof(REAL));
  vtable = (Vertex **) Malloc(in.numberofpoints * sizeof(Vertex *));
  in.numberofpointattributes = 1;
  in.pointattributelist = (REAL *) Malloc(in.numberofpoints *
                                          in.numberofpointattributes *
                                          sizeof(REAL));
  in.pointmarkerlist = NULL;
  in.numberofsegments = NbPts;
  in.segmentlist = (int *)Malloc(in.numberofsegments * 2 * sizeof(int));
  in.segmentmarkerlist = (int *)Malloc(in.numberofsegments * sizeof(int));
  in.numberofregions = 0;
  in.regionlist = NULL;

  k = 0;
  l = 0;
  double lc_max = -1.0;
  for(i = 0; i < List_Nbr(s->Contours); i++) {
    List_Read(s->Contours, i, &list);
    first = l;
    for(j = 0; j < List_Nbr(list); j++) {
      List_Read(list, j, &v);
      in.pointlist[k] = v->Pos.X;
      in.pointlist[k + 1] = v->Pos.Y;
      in.pointattributelist[l] = v->lc;
      if(v->lc > lc_max) lc_max = v->lc;
      vtable[l] = v;
      in.segmentlist[k] = l;
      in.segmentlist[k + 1] = (j == List_Nbr(list) - 1) ? (first) : (l + 1);
      in.segmentmarkerlist[l] = i;
      k += 2;
      l++;
    }
  }

  if(List_Nbr(s->Contours) > 1) {
    in.numberofholes = List_Nbr(s->Contours) - 1;
    in.holelist = (REAL *) Malloc(in.numberofholes * 2 * sizeof(REAL));
    for(i = 1; i < List_Nbr(s->Contours); i++) {
      List_Read(s->Contours, i, &list);
      FindPointInHole(list, &in.holelist[(i - 1) * 2],
                      &in.holelist[(i - 1) * 2 + 1]);
    }
  }
  else {
    in.numberofholes = 0;
    in.holelist = NULL;
  }

  mid.pointlist = NULL;
  mid.pointattributelist = NULL;
  mid.pointmarkerlist = NULL;
  mid.trianglelist = NULL;
  mid.triangleattributelist = NULL;
  mid.neighborlist = NULL;
  mid.segmentlist = NULL;
  mid.segmentmarkerlist = NULL;
  mid.edgelist = NULL;
  mid.edgemarkerlist = NULL;

  // triangulate the points with minimum angle > 20 deg, with no
  // boundary breaking, 

  // TODO:
  // and with an area constraint related to the
  // maximum char. length allowed (this last constraint is to avoid an
  // extremely coarse initial grid, on which the interpolation of the
  // final char. lengths would be awful).

  //sprintf(opts, "pqzYa%e", lc_max*lc_max/2.);
  strcpy(opts, "pqzY");
  if(CTX.verbosity < 4)
    strcat(opts, "Q");
  triangulate(opts, &in, &mid, NULL);

  Free(in.pointlist);
  Free(in.pointattributelist);
  Free(in.pointmarkerlist);
  Free(in.regionlist);
  Free(in.segmentlist);
  Free(in.segmentmarkerlist);
  Free(in.holelist);

  if(CTX.mesh.initial_only == 2) {
    AddInMesh(s, NbPts, vtable, &mid);
    return 0;
  }

  mid.trianglearealist =
    (REAL *) Malloc(mid.numberoftriangles * sizeof(REAL));
  for(i = 0; i < mid.numberoftriangles; i++) {
    if(THEM->BGM.Typ == ONFILE) {
      double xx = 0.0, yy = 0.0;
      for(j = 0; j < mid.numberofcorners; j++) {
	k = mid.trianglelist[i * mid.numberofcorners + j];
	xx += mid.pointlist[2 * k];
	yy += mid.pointlist[2 * k + 1];
      }
      xx /= mid.numberofcorners;
      yy /= mid.numberofcorners;
      Vertex *v, *dum;
      v = Create_Vertex(-1, xx, yy, 0.0, 0.0, 0.0);
      Calcule_Z_Plan(&v, &dum);
      Projette_Inverse(&v, &dum);
      val = Lc_XYZ(v->Pos.X, v->Pos.Y, v->Pos.Z, THEM);
      val = val * val / 1.2;
      Free_Vertex(&v, 0);
    }
    else {
      val = 0;
      for(j = 0; j < mid.numberofcorners; j++) {
	k = mid.trianglelist[i * mid.numberofcorners + j];
	val += mid.pointattributelist[k];
      }
      val /= mid.numberofcorners;
      val = val * val / 1.5;
    }
    mid.trianglearealist[i] = val;
  }

  out.pointlist = NULL;
  out.pointattributelist = NULL;
  out.trianglelist = NULL;
  out.triangleattributelist = NULL;

  // refine the triangulation according to the triangle area
  // constraints

  //strcpy(opts, "praqzBPY");
  strcpy(opts, CTX.mesh.triangle_options);
  if(CTX.verbosity < 4)
    strcat(opts, "Q");
  triangulate(opts, &mid, &out, NULL);

  // free all allocated arrays + those allocated by Triangle

  Free(mid.pointlist);
  Free(mid.pointattributelist);
  Free(mid.pointmarkerlist);
  Free(mid.trianglelist);
  Free(mid.triangleattributelist);
  Free(mid.trianglearealist);
  Free(mid.segmentlist);
  Free(mid.segmentmarkerlist);

  AddInMesh(s, NbPts, vtable, &out);

  return 0;

}

#endif // !HAVE_TRIANGLE
