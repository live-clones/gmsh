// $Id: 2D_Mesh_Shewchuk.cpp,v 1.6 2001-09-04 16:25:05 geuzaine Exp $

#include "Gmsh.h"
#include "Mesh.h"
#include "Numeric.h"
#include "Context.h"

#define ANSI_DECLARATORS
#define REAL double

extern "C" {
#include "triangle.h"
}

extern int         CurrentNodeNumber;
extern Context_T   CTX;

void AddInMesh(Surface *sur, int nbbound, Vertex **vertexbound,
	       struct triangulateio *out){
  int i;
  Vertex **vtable;
  Simplex *s;

  //Msg(INFO, "Add in database...");

  vtable = (Vertex**) Malloc(out->numberofpoints*sizeof(Vertex*));

  for (i = 0; i < nbbound; i++) vtable[i] = vertexbound[i];
  Free(vertexbound);
  
  for (i = nbbound; i < out->numberofpoints; i++) {
    vtable[i] = Create_Vertex (++CurrentNodeNumber, 
			       out->pointlist[i * 2], out->pointlist[i * 2 + 1], 0.0, 
			       out->pointattributelist[i], 0.0);
    Tree_Add (sur->Vertices, &vtable[i]);
  }

  Free(out->pointlist);
  Free(out->pointattributelist);

  for (i = 0; i < out->numberoftriangles; i++) {
    s = Create_Simplex(vtable[out->trianglelist[i * out->numberofcorners + 0]],
		       vtable[out->trianglelist[i * out->numberofcorners + 1]],		
		       vtable[out->trianglelist[i * out->numberofcorners + 2]],
		       NULL);
    s->iEnt = sur->Num;
    Tree_Add (sur->Simplexes, &s);
  }
  
  Free(vtable);
  Free(out->trianglelist);
  Free(out->triangleattributelist);

  //Msg(INFO, "...done");
}

// This is horrible...

void FindPointInHole(List_T* verts, REAL *x, REAL *y){
  Vertex *v1, *v2;
  double a[3], b[3], c[3];
  List_Read (verts, 0, &v1);
  List_Read (verts, 1, &v2);
  a[0] = v2->Pos.X - v1->Pos.X;
  a[1] = v2->Pos.Y - v1->Pos.Y;
  a[2] = 0.;
  b[0] = 0.;
  b[1] = 0.;
  b[2] = 1.;
  prodve(b,a,c);
  norme(c);
  *x = 0.5*(v1->Pos.X + v2->Pos.X) + 1.e-12*CTX.lc * c[0];
  *y = 0.5*(v1->Pos.Y + v2->Pos.Y) + 1.e-12*CTX.lc * c[1];
}

int Mesh_Shewchuk(Surface *s){
  char opts[128];
  int i, j, k, l, NbPts=0, first;
  double val;
  List_T *list;
  Vertex *v, **vtable;
  struct triangulateio in, mid, out;

  for (i = 0; i < List_Nbr (s->Contours); i++){
    List_Read (s->Contours, i, &list);
    NbPts += List_Nbr(list);
  }

  in.numberofpoints = NbPts;
  in.pointlist = (REAL *) Malloc(in.numberofpoints * 2 * sizeof(REAL));
  vtable = (Vertex**) Malloc(in.numberofpoints*sizeof(Vertex*));
  in.numberofpointattributes = 1;
  in.pointattributelist = (REAL *) Malloc(in.numberofpoints *
                                          in.numberofpointattributes *
                                          sizeof(REAL));
  in.pointmarkerlist = NULL; 
  in.numberofsegments = NbPts;
  in.segmentlist = (int*)Malloc(in.numberofsegments * 2 * sizeof(int));
  in.segmentmarkerlist = (int *) Malloc(in.numberofsegments * sizeof(int));
  in.numberofregions = 0;
  in.regionlist = NULL; 

  k=0; l=0;
  for (i = 0; i < List_Nbr(s->Contours); i++){
    List_Read (s->Contours, i, &list);
    first = l;
    for (j = 0; j < List_Nbr(list); j++){
      List_Read (list, j, &v);
      in.pointlist[k] = v->Pos.X;
      in.pointlist[k+1] = v->Pos.Y;
      in.pointattributelist[l] = v->lc;
      vtable[l] = v;
      in.segmentlist[k] = l;
      in.segmentlist[k+1] = (j==List_Nbr(list)-1)? (first) : (l+1);
      in.segmentmarkerlist[l] = i;
      k+=2;
      l++;
    }
  }

  if(List_Nbr(s->Contours) > 1){
    in.numberofholes = List_Nbr(s->Contours)-1;
    in.holelist = (REAL *) Malloc(in.numberofholes * 2 * sizeof(REAL));
    for(i = 1; i < List_Nbr(s->Contours); i++){
      List_Read (s->Contours, i, &list);
      FindPointInHole(list, &in.holelist[(i-1)*2], &in.holelist[(i-1)*2+1]);
    }
  }
  else{
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

  // triangulate the points with minimum angle > 20 deg, with no boundary breaking

  strcpy(opts, "pqzY");
  if(CTX.verbosity < 3) strcat(opts, "Q");
  triangulate(opts, &in, &mid, NULL);

  Free(in.pointlist);
  Free(in.pointattributelist);
  Free(in.pointmarkerlist);
  Free(in.regionlist);
  Free(in.segmentlist);
  Free(in.segmentmarkerlist);
  Free(in.holelist);

  if(CTX.mesh.initial_only==2){
    AddInMesh(s, NbPts, vtable, &mid);
    return 0;
  }

#ifndef BGMESH

  mid.trianglearealist = (REAL *) Malloc(mid.numberoftriangles * sizeof(REAL));
  for (i = 0; i < mid.numberoftriangles; i++) {
    val = 0;
    for (j = 0; j < mid.numberofcorners; j++) {
      k = mid.trianglelist[i * mid.numberofcorners + j];
      val += mid.pointattributelist[k];
    }
    val /= mid.numberofcorners;
    val = val*val / 2. ; // we generate isotropic meshes
    mid.trianglearealist[i] = val;
  }

#else
  
  Msg(FATAL, "Triangle is not ready to be used with a background mesh");
  
#endif

  out.pointlist = NULL;
  out.pointattributelist = NULL;
  out.trianglelist = NULL;
  out.triangleattributelist = NULL;

  // refine the triangulation according to the triangle area constraints

  strcpy(opts, "praqzBPY");
  if(CTX.verbosity < 3) strcat(opts, "Q");
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
