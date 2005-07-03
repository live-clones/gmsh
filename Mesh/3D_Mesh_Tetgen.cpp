// $Id: 3D_Mesh_Tetgen.cpp,v 1.2 2005-07-03 08:02:24 geuzaine Exp $
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
//
// Contributor(s):
//   Nicolas Tardieu
//

#include "Gmsh.h"
#include "Geo.h"
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

class Tetgen{
 private:
  List_T *_surverts, *_volverts;
  Volume *_vol;
  tetgenio *in, *out;
 public:
  Tetgen(Volume *vol);
  ~Tetgen();
  void MeshVolume();
  void TransferVolumeMesh();
};

Tetgen::Tetgen(Volume *vol)
  : _volverts(0), _vol(vol)
{
  // ===================================
  //     TRANSFER GMSH => TETGEN
  // ===================================
  
  // creates Tetgen mesh structure
  tetgenio *in = new tetgenio;
  tetgenio *out = new tetgenio;
  tetgenio::facet *f;
  tetgenio::polygon *p;

  // All indices start from 1.
  in->firstnumber = 1;
  
  // Get all surface vertices (the same vertex can belong to several
  // surfaces...)
  Tree_T *tree = Tree_Create(sizeof(Vertex*), compareVertex);
  for(int i = 0; i < List_Nbr(_vol->Surfaces); i++) {
    Surface *s;
    List_Read(_vol->Surfaces, i, &s);
    Tree_Unit(tree, s->Vertices);
  }
  _surverts = Tree2List(tree);
  List_Sort(_surverts, compareVertex);

  Tree_Delete(tree);
  
  // Tetgen points input data
  in->numberofpoints = List_Nbr(_surverts);
  in->pointlist = new REAL[in->numberofpoints * 3];

  // Transfer the vertices
  for(int i = 0; i < List_Nbr(_surverts); i++){
    Vertex *v;
    List_Read(_surverts, i, &v);
    in->pointlist[3*i + 0]  = v->Pos.X;
    in->pointlist[3*i + 1]  = v->Pos.Y;
    in->pointlist[3*i + 2]  = v->Pos.Z;
  }

  // Count number of facets
  int NbOfFacets=0;
  for(int i = 0; i < List_Nbr(_vol->Surfaces); i++) {
    Surface *s;
    List_Read(_vol->Surfaces, i, &s);
    List_T *simplist = Tree2List(s->Simplexes);
    NbOfFacets = NbOfFacets + List_Nbr(simplist);
  }
  // Tetgen elements input data
  in->numberoffacets = NbOfFacets;
  in->facetlist = new tetgenio::facet[in->numberoffacets];
  in->facetmarkerlist = new int[in->numberoffacets];

  // Transfert all surface simplices
  int currentFacet=0;
  for(int i = 0; i < List_Nbr(_vol->Surfaces); i++) {
    Surface *s;
    List_Read(_vol->Surfaces, i, &s);
    int sign;
    List_Read(_vol->SurfacesOrientations, i, &sign);
    List_T *simplist = Tree2List(s->Simplexes);
    for(int j = 0; j < List_Nbr(simplist); j++) {
      Simplex *simp;
      List_Read(simplist, j, &simp);
      int tmp[3], index[3];
      if(sign > 0){
	index[0] = 0;
	index[1] = 1;
	index[2] = 2;
      }
      else{
	index[0] = 0;
	index[1] = 2;
	index[2] = 1;
      }
      tmp[0] = 1 + List_ISearch(_surverts, &simp->V[index[0]], compareVertex);
      tmp[1] = 1 + List_ISearch(_surverts, &simp->V[index[1]], compareVertex);
      tmp[2] = 1 + List_ISearch(_surverts, &simp->V[index[2]], compareVertex);
      
      f = &in->facetlist[currentFacet];
      f->numberofpolygons = 1;
      f->polygonlist = new tetgenio::polygon[f->numberofpolygons];
      f->numberofholes = 0;
      f->holelist = NULL;
      p = &f->polygonlist[0];
      p->numberofvertices = 3;
      p->vertexlist = new int[p->numberofvertices];
      p->vertexlist[0] = tmp[0];
      p->vertexlist[1] = tmp[1];
      p->vertexlist[2] = tmp[2];
      in->facetmarkerlist[currentFacet] = 0;
      currentFacet=currentFacet+1;
    }
    List_Delete(simplist);
  }
  // In order to check the input...
  in->save_nodes("barin");
  in->save_poly("barin");


  
  
  // ===================================
  //     MESHING...
  // ===================================
  tetrahedralize("pqV", in, out);
  
  
  
  
  // ===================================
  //     TRANSFER TETGEN => GMSH
  // ===================================
  // Gets total number of vertices of Tetgen's mesh
  int nbv = out->numberofpoints;
  Msg(INFO, " NIKO : nbv=%i",nbv);

  for(int i = 0; i < List_Nbr(_vol->Surfaces); i++) {
    Surface *s;
    List_Read(_vol->Surfaces, i, &s);
    Tree_Delete(s->Simplexes);
  }
  Tree_Delete(_vol->Vertices);
  Tree_Delete(THEM->Vertices);
  _vol->Vertices = Tree_Create(sizeof(Simplex *), compareSimplex);
  THEM->Vertices = Tree_Create(sizeof(Simplex *), compareSimplex);
  THEM->MaxPointNum=0;

  // Create new vertices
  Vertex **vtable = (Vertex **)Malloc(nbv * sizeof(Vertex*));
  for(int i = 0; i < nbv; i++) {
    vtable[i] = Create_Vertex(++(THEM->MaxPointNum), out->pointlist[3*i + 0], out->pointlist[3*i + 1],out->pointlist[3*i + 2], 1., 0);
    Tree_Add(_vol->Vertices, &vtable[i]);
    Tree_Add(THEM->Vertices, &vtable[i]);
  }

  Msg(INFO, "<NIKO>: nbTriFace=%i",out->numberoftrifaces);
  if(!nbv) {
    Msg(STATUS3, "<NIKO>: AUCUN ELEMENT");
    return;}

  
  // Get total number of simplices of Tetgen's mesh
  int nbe = out->numberoftetrahedra;

  // Create new volume simplices
  for(int i = 0; i < nbe; i++) {
    Simplex *simp = Create_Simplex(vtable[out->tetrahedronlist[4*i + 0]-1], vtable[out->tetrahedronlist[4*i + 1]-1],
				   vtable[out->tetrahedronlist[4*i + 2]-1], vtable[out->tetrahedronlist[4*i + 3]-1]);
    simp->iEnt = _vol->Num;
    Tree_Add(_vol->Simplexes, &simp);
    // also add a copy in the global simplex tree
    Tree_Add(THEM->Simplexes, &simp);
  }
  
  Free(vtable);
}


Tetgen::~Tetgen()
{
  List_Delete(_surverts);
  List_Delete(_volverts);
  // Strange : this method is not seen by the compiler 
  // tetgenio::deinitialize();
}

void Tetgen::MeshVolume()
{
  tetrahedralize("pqV", in, out);
}

void Tetgen::TransferVolumeMesh()
{
  // Gets total number of vertices of Tetgen's mesh
  int nbv = out->numberofpoints;
  Msg(INFO, " NIKO : nbv=%i",nbv);

  if(!nbv) {
    Msg(STATUS3, " NIKO : AUCUN ELEMENT");
    return;}

  Vertex **vtable = (Vertex **)Malloc(nbv * sizeof(Vertex*));
  
  // Get existing unmodified surface vertices
  for(int i = 0; i < List_Nbr(_surverts); i++){
    List_Read(_surverts, i, &vtable[i]);
    Tree_Insert(_vol->Vertices, &vtable[i]);
    Tree_Insert(THEM->Vertices, &vtable[i]);
  }

  // Create new volume vertices
  for(int i = List_Nbr(_surverts); i < nbv; i++) {
    vtable[i] = Create_Vertex(++(THEM->MaxPointNum), out->pointlist[3*i + 0], out->pointlist[3*i + 1],out->pointlist[3*i + 2], 1., 0);
    Tree_Add(_vol->Vertices, &vtable[i]);
    Tree_Add(THEM->Vertices, &vtable[i]);
  }

  // Get total number of simplices of Tetgen's mesh
  int nbe = out->numberoftetrahedra;

  // Create new volume simplices
  for(int i = 0; i < nbe; i++) {
    Msg(INFO, " NIKO out->tetrahedronlist: =%i",out->tetrahedronlist[4*i + 0]);
    Simplex *simp = Create_Simplex(vtable[out->tetrahedronlist[4*i + 0]], vtable[out->tetrahedronlist[4*i + 1]],
				   vtable[out->tetrahedronlist[4*i + 2]], vtable[out->tetrahedronlist[4*i + 3]]);
    simp->iEnt = _vol->Num;
    Tree_Add(_vol->Simplexes, &simp);
    // also add a copy in the global simplex tree
    Tree_Add(THEM->Simplexes, &simp);
  }
  
  Free(vtable);
}


int Mesh_Tetgen(Volume * v)
{
  if(CTX.mesh.algo3d != DELAUNAY_TETGEN)
    return 0;

  Msg(GERROR, "Tetgen is not ready yet!");
  return 0;

  if(THEM->BGM.Typ == ONFILE){
    Msg(GERROR, "Tetgen is not ready to be used with a background mesh");
    return 0;
  }

  Msg(STATUS3, "Meshing volume %d", v->Num);
  Tetgen tg(v);
  //tg.MeshVolume();
  //tg.TransferVolumeMesh();
  
  return 1;
}

#endif // !HAVE_TETGEN
