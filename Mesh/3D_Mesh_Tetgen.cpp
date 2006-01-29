// $Id: 3D_Mesh_Tetgen.cpp,v 1.6 2006-01-29 22:53:41 geuzaine Exp $
//
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
//
// Contributor(s):
//   Jozef Vesely
//

#include "Gmsh.h"
#include "Mesh.h"
#include "Create.h"
#include "Numeric.h"
#include "Context.h"

extern Context_T CTX;
extern Mesh *THEM;

#if !defined(HAVE_TETGEN)

int Mesh_Tetgen(Volume * v)
{
  if(CTX.mesh.algo3d == DELAUNAY_TETGEN)
    Msg(GERROR, "Tetgen is not compiled in this version of Gmsh");
  return 0;
}
#else

#include "tetgen.h"

int Mesh_Tetgen(Volume * vol) {
  tetgenio in, out;
  char opts[128];

  if(CTX.mesh.algo3d != DELAUNAY_TETGEN)
    return 0;

  if(THEM->BackgroundMeshType == ONFILE){
    Msg(GERROR, "Tetgen is not ready to be used with a background mesh");
    return 0;
  }

  Msg(STATUS3, "Meshing volume %d with experimental tetgen", vol->Num);
  
  // Get all surface vertices (from all surfaces)
  Tree_T *treeVrtx = Tree_Create(sizeof(Vertex*), compareVertex);
  Tree_T *treeSimp = Tree_Create(sizeof(Simplex*), compareSimplex);
  
  for(int i = 0; i < List_Nbr(vol->Surfaces); i++) {
    Surface *sur;
    List_Read(vol->Surfaces, i, &sur);
    
    Tree_Unit(treeVrtx, sur->Vertices);
    Tree_Unit(treeSimp, sur->Simplexes);
    
    // DELETE all triangles and vertices,
    // tetgen will refine also surface mesh
    Tree_Delete(sur->Simplexes);
    Tree_Delete(sur->Vertices);
    sur->Simplexes = Tree_Create(sizeof(Simplex *), compareQuality);
    sur->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);
  }

  List_T *listVrtx = Tree2List(treeVrtx);
  List_T *listSimp = Tree2List(treeSimp);
  
  Tree_Delete(treeVrtx);
  Tree_Delete(treeSimp);

  // Set input parameters  
  in.mesh_dim = 3;
  in.firstnumber = 1;
  
  in.numberofpoints = List_Nbr(listVrtx);
  in.pointlist = new REAL[in.numberofpoints * 3];
  in.pointmarkerlist = NULL;
  
  in.numberoffacets = List_Nbr(listSimp);
  in.facetlist = new tetgenio::facet[in.numberoffacets];
  in.facetmarkerlist = new int[in.numberoffacets];

  double lc_max = -1.0;
  for(int i = 0; i < List_Nbr(listVrtx); i++){
    Vertex *v;
    List_Read(listVrtx, i, &v);
    in.pointlist[i*3 + 0] = v->Pos.X;
    in.pointlist[i*3 + 1] = v->Pos.Y;
    in.pointlist[i*3 + 2] = v->Pos.Z;
    if(v->lc > lc_max) lc_max = v->lc;
    
    // DELETE the vertices from global mesh
    Tree_Suppress(THEM->Vertices, &v);
  }
 
  for(int i = 0; i < List_Nbr(listSimp); i++) {
    Simplex *s;
    List_Read(listSimp, i, &s);
    
    tetgenio::facet *f = &in.facetlist[i];
    tetgenio::init(f);
    
    f->numberofholes = 0;
    f->numberofpolygons = 1;
    tetgenio::polygon *p = f->polygonlist = new tetgenio::polygon[f->numberofpolygons];
    tetgenio::init(p);
    
    p->numberofvertices = 3;
    p->vertexlist = new int[p->numberofvertices];
    p->vertexlist[0] = List_ISearch(listVrtx, &s->V[0], compareVertex) +1; 
    p->vertexlist[1] = List_ISearch(listVrtx, &s->V[1], compareVertex) +1;
    p->vertexlist[2] = List_ISearch(listVrtx, &s->V[2], compareVertex) +1;
    
    in.facetmarkerlist[i] = s->iEnt;
  }
 
  sprintf(opts, "pqa%f%c", (float)CTX.mesh.quality, 
	  (CTX.verbosity < 3)? 'Q': (CTX.verbosity > 6)? 'V': '\0');
  Msg(STATUS3, "Meshing with volume constraint %f", (float)CTX.mesh.quality);
  
  tetrahedralize(opts, &in, &out);
 
  // CHECK
  // out.trifacemarkerlist != NULL
  // out.numberofcorners == 4
  // out.mesh_dim == 3 
  
  Vertex **vtable = new Vertex*[out.numberofpoints]; 
  for (int i = 0; i < out.numberofpoints; i++) {
    vtable[i] = Create_Vertex(++(THEM->MaxPointNum), 
			      out.pointlist[i * 3 + 0], 
			      out.pointlist[i * 3 + 1],
			      out.pointlist[i * 3 + 2],
			      1., 0);
    Tree_Add(vol->Vertices, &vtable[i]);
    Tree_Add(THEM->Vertices, &vtable[i]);
  }
  
  for(int j = 0; j < List_Nbr(vol->Surfaces); j++){
    Surface *sur;
    List_Read(vol->Surfaces, j, &sur);
    for (int i = 0; i<out.numberoftrifaces; i++){
      if (out.trifacemarkerlist[i] == sur->Num) {
	Simplex *s = Create_Simplex(vtable[ out.trifacelist[i * 3 + 0]-1 ],
				    vtable[ out.trifacelist[i * 3 + 1]-1 ],
				    vtable[ out.trifacelist[i * 3 + 2]-1 ],
				    NULL);
	s->iEnt = sur->Num;
	Tree_Add(sur->Simplexes, &s);
      }
    } 
  }
  
  for (int i = 0; i < out.numberoftetrahedra; i++) {
    Simplex *s = Create_Simplex(vtable[ out.tetrahedronlist[i * 4 + 0] -1],
				vtable[ out.tetrahedronlist[i * 4 + 1] -1],
				vtable[ out.tetrahedronlist[i * 4 + 2] -1],
				vtable[ out.tetrahedronlist[i * 4 + 3] -1]);
    s->iEnt = vol->Num;
    Tree_Add(vol->Simplexes, &s);
    Tree_Add(THEM->Simplexes, &s);
  }
  
  List_Delete(listVrtx);
  List_Delete(listSimp);
  return 1;
}

#endif // !HAVE_TETGEN
