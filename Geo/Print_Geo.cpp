// $Id: Print_Geo.cpp,v 1.37 2005-03-14 18:12:29 geuzaine Exp $
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
#include "Geo.h"
#include "Mesh.h"
#include "Vertex.h"
#include "CAD.h"
#include "SmoothNormals.h"
#include "Numeric.h"
#include "Context.h"

#include <map>

FILE *FOUT;

void Print_Point(void *a, void *b)
{
  Vertex *v;
  v = *(Vertex **) a;
  fprintf(FOUT, "Point(%d) = {%.16g, %.16g, %.16g, %.16g};\n",
          v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, v->lc);
}

void Print_Nurbs(Curve * c, FILE * f)
{
  int i, j;
  Vertex *v;

  fprintf(f, "Nurbs (%d) = {", c->Num);
  for(i = 0; i < List_Nbr(c->Control_Points); i++) {
    List_Read(c->Control_Points, i, &v);
    if(!i)
      fprintf(FOUT, "%d", v->Num);
    else
      fprintf(FOUT, ", %d", v->Num);
    if(i % 8 == 7 && i != List_Nbr(c->Control_Points) - 1)
      fprintf(FOUT, "\n");
  }
  fprintf(f, "}\n");
  fprintf(f, "  Knots {");
  for(j = 0; j < List_Nbr(c->Control_Points) + c->degre + 1; j++) {
    if(!j)
      fprintf(f, "%.16g", c->k[j]);
    else
      fprintf(f, ", %.16g", c->k[j]);
    if(j % 5 == 4 && j != List_Nbr(c->Control_Points) + c->degre)
      fprintf(FOUT, "\n        ");
  }
  fprintf(f, "}\n");
  fprintf(f, "  Order %d;\n", c->degre);
}

void Print_Curve(void *a, void *b)
{
  Curve *c;
  Vertex *v;
  int i;
  c = *(Curve **) a;

  if(c->Num < 0 || c->Dirty)
    return;

  switch (c->Typ) {
  case MSH_SEGM_LINE:
    fprintf(FOUT, "Line (%d) = ", c->Num);
    break;
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
    fprintf(FOUT, "Circle (%d) = ", c->Num);
    break;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    fprintf(FOUT, "Ellipse (%d) = ", c->Num);
    break;
  case MSH_SEGM_NURBS:
    Print_Nurbs(c, FOUT);
    return;
  case MSH_SEGM_SPLN:
    fprintf(FOUT, "CatmullRom (%d) = ", c->Num);
    break;
  case MSH_SEGM_BSPLN:
    fprintf(FOUT, "BSpline (%d) = ", c->Num);
    break;
  case MSH_SEGM_BEZIER:
    fprintf(FOUT, "Bezier (%d) = ", c->Num);
    break;
  default:
    Msg(GERROR, "Unknown curve type %d", c->Typ);
    return;
  }

  for(i = 0; i < List_Nbr(c->Control_Points); i++) {
    List_Read(c->Control_Points, i, &v);
    if(i)
      fprintf(FOUT, ", %d", v->Num);
    else
      fprintf(FOUT, "{%d", v->Num);
    if(i % 6 == 7)
      fprintf(FOUT, "\n");
  }

  switch (c->Typ) {
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    fprintf(FOUT, "} Plane{%.16g, %.16g, %.16g};\n",
            c->Circle.n[0], c->Circle.n[1], c->Circle.n[2]);
    break;
  default:
    fprintf(FOUT, "};\n");
    break;
  }

}

void Print_Discrete_Curve(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  
  if(c->Num < 0) return;
  
  // if we have a SEGM_rep, print it:

  if(c->theSegmRep){
    if(!List_Nbr(c->Control_Points))
      fprintf(FOUT, "Discrete Line (%d) = {%d}\n", 
	      c->Num, c->theSegmRep->num_points);
    else
      fprintf(FOUT, "Discrete Line {%d} = {%d}\n", 
	      c->Num, c->theSegmRep->num_points);
    
    fprintf(FOUT, "{\n");
    for(int i = 0; i < List_Nbr(c->theSegmRep->points); i++){
      if(i){
	fprintf(FOUT, ",");
	if(!(i%3)) fprintf(FOUT, "\n");
      }
      fprintf(FOUT, "%.16g", 
	      *(double*)List_Pointer_Fast(c->theSegmRep->points, i));
    }
    fprintf(FOUT, "};\n");
    return;
  }

  // else, print the mesh:

  if(!List_Nbr(c->Vertices))
    return;

  if(!List_Nbr(c->Control_Points))
    fprintf(FOUT, "Discrete Line (%d) = {%d}\n", 
	    c->Num, List_Nbr(c->Vertices));
  else
    fprintf(FOUT, "Discrete Line {%d} = {%d}\n", 
	    c->Num, List_Nbr(c->Vertices));

  fprintf(FOUT, "{\n");
  for(int i = 0; i < List_Nbr(c->Vertices); i++){
    Vertex *v = *(Vertex**)List_Pointer(c->Vertices, i);
    fprintf(FOUT, "  %.16g,%.16g,%.16g", v->Pos.X, v->Pos.Y, v->Pos.Z);
    if(i != List_Nbr(c->Vertices) - 1) 
      fprintf(FOUT, ",\n");
    else
      fprintf(FOUT, "\n");
  }
  fprintf(FOUT, "};\n");
}

void Print_Surface(void *a, void *b)
{
  Curve *c;
  Surface *s;
  Vertex *v;
  int i, j;
  s = *(Surface **) a;

  if(s->Dirty)
    return;

  int NUMLOOP = s->Num + 1000000;

  if(s->Typ != MSH_SURF_NURBS) {
    if(List_Nbr(s->Generatrices)){
      fprintf(FOUT, "Line Loop (%d) = ", NUMLOOP);
      for(i = 0; i < List_Nbr(s->Generatrices); i++) {
	List_Read(s->Generatrices, i, &c);
	if(i)
	  fprintf(FOUT, ", %d", c->Num);
	else
	  fprintf(FOUT, "{%d", c->Num);
      }
      fprintf(FOUT, "};\n");
    }
  }

  switch (s->Typ) {
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC:
    fprintf(FOUT, "Ruled Surface (%d) = {%d};\n", s->Num, NUMLOOP);
    break;
  case MSH_SURF_PLAN:
    fprintf(FOUT, "Plane Surface (%d) = {%d};\n", s->Num, NUMLOOP);
    break;
  case MSH_SURF_TRIMMED:
    fprintf(FOUT, "Trimmed Surface (%d) = %d {%d};\n", s->Num,
            s->Support->Num, NUMLOOP);
    break;
  case MSH_SURF_NURBS:
    fprintf(FOUT, "Nurbs Surface (%d) = {\n", s->Num);
    for(i = 0; i < s->Nv; i++) {
      fprintf(FOUT, "  {");
      for(j = 0; j < s->Nu; j++) {
        List_Read(s->Control_Points, j + s->Nu * i, &v);
        if(!j)
          fprintf(FOUT, "%d", v->Num);
        else
          fprintf(FOUT, ", %d", v->Num);
      }
      if(i != s->Nv - 1)
        fprintf(FOUT, "},\n");
      else
        fprintf(FOUT, "}}\n");
    }
    fprintf(FOUT, "  Knots\n  {");
    for(j = 0; j < s->Nu + s->OrderU + 1; j++) {
      if(!j)
        fprintf(FOUT, "%.16g", s->ku[j]);
      else
        fprintf(FOUT, ", %.16g", s->ku[j]);
      if(j % 5 == 4 && j != s->Nu + s->OrderU)
        fprintf(FOUT, "\n  ");
    }
    fprintf(FOUT, "}\n  {");
    for(j = 0; j < s->Nv + s->OrderV + 1; j++) {
      if(!j)
        fprintf(FOUT, "%.16g", s->kv[j]);
      else
        fprintf(FOUT, ", %.16g", s->kv[j]);
      if(j % 5 == 4 && j != s->Nv + s->OrderV)
        fprintf(FOUT, "\n  ");
    }
    fprintf(FOUT, "}\n  Order %d %d;\n", s->OrderU, s->OrderV);
    break;
  }
}

void Print_Discrete_Surface(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  
  // if we have a poly_rep, print it:

  if(s->thePolyRep){
    if(!List_Nbr(s->Generatrices))
      fprintf(FOUT, "Discrete Surface (%d) = {%d, %d}\n", 
	      s->Num, s->thePolyRep->num_points, s->thePolyRep->num_polys);
    else
      fprintf(FOUT, "Discrete Surface {%d} = {%d, %d}\n", 
	      s->Num, s->thePolyRep->num_points, s->thePolyRep->num_polys);
    
    fprintf(FOUT, "{\n");
    for(int i = 0; i < List_Nbr(s->thePolyRep->points_and_normals); i++){
      if(i){
	fprintf(FOUT, ",");
	if(!(i%6)) fprintf(FOUT, "\n");
      }
      fprintf(FOUT, "%.16g", 
	      *(double*)List_Pointer_Fast(s->thePolyRep->points_and_normals, i));
    }
    fprintf(FOUT, "}\n");
    fprintf(FOUT, "{\n");    
    for(int i = 0; i < List_Nbr(s->thePolyRep->polygons); i++){
      if(i){
	fprintf(FOUT, ",");
	if(!(i%4)) fprintf(FOUT, "\n");
      }
      fprintf(FOUT, "%.16g", *(double*)List_Pointer_Fast(s->thePolyRep->polygons, i));
    }
    fprintf(FOUT, "};\n");
    return;
  }

  // else, print the surface mesh:

  if(!Tree_Nbr(s->Vertices))
    return;

  List_T *verts = Tree2List(s->Vertices);  
  List_T *tmp = Tree2List(s->Simplexes);
  List_T *tris = Tree2List(s->SimplexesBase);
  List_Copy(tmp, tris);
  List_Delete(tmp);
  List_T *quads = Tree2List(s->Quadrangles);

  // compute smoothed normals
  smooth_normals norms;
  for(int i = 0; i < List_Nbr(tris); i++){
    SimplexBase *t = *(SimplexBase**)List_Pointer(tris, i);
    if(t->V[2]){
      double n[3];
      normal3points(t->V[0]->Pos.X, t->V[0]->Pos.Y, t->V[0]->Pos.Z,
		    t->V[1]->Pos.X, t->V[1]->Pos.Y, t->V[1]->Pos.Z,
		    t->V[2]->Pos.X, t->V[2]->Pos.Y, t->V[2]->Pos.Z, n);
      norms.add(t->V[0]->Pos.X, t->V[0]->Pos.Y, t->V[0]->Pos.Z, n[0], n[1], n[2]);
      norms.add(t->V[1]->Pos.X, t->V[1]->Pos.Y, t->V[1]->Pos.Z, n[0], n[1], n[2]);
      norms.add(t->V[2]->Pos.X, t->V[2]->Pos.Y, t->V[2]->Pos.Z, n[0], n[1], n[2]);
    }
  }
  for(int i = 0; i < List_Nbr(quads); i++){
    Quadrangle *q = *(Quadrangle**)List_Pointer(quads, i);
    double n[3];
    normal3points(q->V[0]->Pos.X, q->V[0]->Pos.Y, q->V[0]->Pos.Z,
		  q->V[1]->Pos.X, q->V[1]->Pos.Y, q->V[1]->Pos.Z,
		  q->V[2]->Pos.X, q->V[2]->Pos.Y, q->V[2]->Pos.Z, n);
    norms.add(q->V[0]->Pos.X, q->V[0]->Pos.Y, q->V[0]->Pos.Z, n[0], n[1], n[2]);
    norms.add(q->V[1]->Pos.X, q->V[1]->Pos.Y, q->V[1]->Pos.Z, n[0], n[1], n[2]);
    norms.add(q->V[2]->Pos.X, q->V[2]->Pos.Y, q->V[2]->Pos.Z, n[0], n[1], n[2]);
    norms.add(q->V[3]->Pos.X, q->V[3]->Pos.Y, q->V[3]->Pos.Z, n[0], n[1], n[2]);
  }

  if(!List_Nbr(s->Generatrices))
    fprintf(FOUT, "Discrete Surface (%d) = {%d, %d}\n", 
	    s->Num, List_Nbr(verts), List_Nbr(tris)+List_Nbr(quads));
  else
    fprintf(FOUT, "Discrete Surface {%d} = {%d, %d}\n", 
	    s->Num, List_Nbr(verts), List_Nbr(tris)+List_Nbr(quads));

  // print nodes and create dense vertex numbering
  fprintf(FOUT, "{\n");
  map<int, int> nodes;
  for(int i = 0; i < List_Nbr(verts); i++){
    Vertex *v = *(Vertex**)List_Pointer(verts, i);
    nodes[v->Num] = i;
    double n[3] = {0.,0.,0.};
    norms.get(v->Pos.X, v->Pos.Y, v->Pos.Z, n[0], n[1], n[2], 180.);
    fprintf(FOUT, "  %.16g,%.16g,%.16g, %g,%g,%g", 
	    v->Pos.X, v->Pos.Y, v->Pos.Z, n[0], n[1], n[2]);
    if(i != List_Nbr(verts) - 1) 
      fprintf(FOUT, ",\n");
    else
      fprintf(FOUT, "\n");
  }
  fprintf(FOUT, "}\n");
  
  // print polygons
  fprintf(FOUT, "{\n");
  for(int i = 0; i < List_Nbr(tris); i++){
    SimplexBase *t = *(SimplexBase**)List_Pointer(tris, i);
    if(t->V[2])
      fprintf(FOUT, "  3, %d,%d,%d", 
	      nodes[t->V[0]->Num], nodes[t->V[1]->Num], nodes[t->V[2]->Num]);
    if(List_Nbr(quads) || i != List_Nbr(tris) - 1) 
      fprintf(FOUT, ",\n");    
    else
      fprintf(FOUT, "\n");
  }
  for(int i = 0; i < List_Nbr(quads); i++){
    Quadrangle *q = *(Quadrangle**)List_Pointer(quads, i);
    fprintf(FOUT, "  4, %d,%d,%d,%d", nodes[q->V[0]->Num], nodes[q->V[1]->Num],
	    nodes[q->V[2]->Num], nodes[q->V[3]->Num]);
    if(i != List_Nbr(quads) - 1) 
      fprintf(FOUT, ",\n");
    else
      fprintf(FOUT, "\n");
  }
  fprintf(FOUT, "};\n");
  
  List_Delete(verts);
  List_Delete(tris);
  List_Delete(quads);
}

void Print_Volume(void *a, void *b)
{
  Surface *s;
  Volume *vol;
  int i;
  vol = *(Volume **) a;

  if(vol->Dirty)
    return;

  int NUMLOOP = vol->Num + 1000000;

  fprintf(FOUT, "Surface Loop (%d) = ", NUMLOOP);

  for(i = 0; i < List_Nbr(vol->Surfaces); i++) {
    List_Read(vol->Surfaces, i, &s);
    if(i)
      fprintf(FOUT, ", %d", s->Num);
    else
      fprintf(FOUT, "{%d", s->Num);
  }
  fprintf(FOUT, "};\n");

  switch (vol->Typ) {
  case MSH_VOLUME:
    fprintf(FOUT, "Volume (%d) = {%d};\n", vol->Num, NUMLOOP);
    break;
  }
}

void Print_PhysicalGroups(void *a, void *b)
{
  PhysicalGroup *pg;
  int i, j;

  pg = *(PhysicalGroup **) a;

  switch (pg->Typ) {
  case MSH_PHYSICAL_POINT:
    fprintf(FOUT, "Physical Point (%d) = ", pg->Num);
    break;
  case MSH_PHYSICAL_LINE:
    fprintf(FOUT, "Physical Line (%d) = ", pg->Num);
    break;
  case MSH_PHYSICAL_SURFACE:
    fprintf(FOUT, "Physical Surface (%d) = ", pg->Num);
    break;
  case MSH_PHYSICAL_VOLUME:
    fprintf(FOUT, "Physical Volume (%d) = ", pg->Num);
    break;
  }

  for(i = 0; i < List_Nbr(pg->Entities); i++) {
    List_Read(pg->Entities, i, &j);
    if(i)
      fprintf(FOUT, ", %d", j);
    else
      fprintf(FOUT, "{%d", j);
  }
  fprintf(FOUT, "};\n");

}

void Print_Geo(Mesh * M, char *filename, int discrete_curves, int discrete_surf)
{
  if(filename) {
    FOUT = fopen(filename, "w");
    if(!FOUT) {
      Msg(GERROR, "Unable to open file '%s'", filename);
      return;
    }
    Msg(INFO, "Writing flattened geometry file '%s'", filename);
  }
  else
    FOUT = stdout;

  Tree_Action(M->Points, Print_Point);
  Tree_Action(M->Curves, Print_Curve);
  Tree_Action(M->Surfaces, Print_Surface); 
  if(discrete_curves)
    Tree_Action(M->Curves, Print_Discrete_Curve);
  if(discrete_surf)
    Tree_Action(M->Surfaces, Print_Discrete_Surface);
  Tree_Action(M->Volumes, Print_Volume);
  List_Action(M->PhysicalGroups, Print_PhysicalGroups);

  if(filename) {
    Msg(INFO, "Wrote flattened geometry file '%s'", filename);
    Msg(STATUS2N, "Wrote '%s'", filename);
    fclose(FOUT);
  }

}
