// $Id: 3D_Mesh_Netgen.cpp,v 1.25 2006-08-05 13:31:28 geuzaine Exp $
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
//   Nicolas Tardieu
//

#include "Gmsh.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"
#include "Numeric.h"
#include "Context.h"
#include "OS.h"

extern Context_T CTX;
extern Mesh *THEM;

#if !defined(HAVE_NETGEN)

int Mesh_Netgen(Volume * v)
{
  if(CTX.mesh.algo3d == FRONTAL_NETGEN)
    Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
  return 0;
}

void Optimize_Netgen(Volume * v)
{
  Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
}

void Optimize_Netgen()
{
  Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
}

#else

namespace nglib {
#include "nglib.h"
#include "nglib_addon.h"
}

using namespace nglib;

class Netgen{
 private:
  List_T *_surverts, *_volverts;
  Volume *_vol;
  Ng_Mesh *_ngmesh;
 public:
  Netgen(Volume *vol, int importVolumeMesh = 0);
  Netgen(Surface *sur, int importSurfaceMesh = 0);
  ~Netgen();
  void MeshVolume();
  void TransferVolumeMesh();
  void OptimizeVolume();
};

Netgen::Netgen(Volume *vol, int importVolumeMesh)
  : _volverts(0), _vol(vol)
{
  // creates Netgen mesh structure
  //Ng_Init();
  NgAddOn_Init();
  _ngmesh = Ng_NewMesh();
  
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

  if(importVolumeMesh){
    Tree_T *tree2 = Tree_Soustraction(_vol->Vertices, tree);
    _volverts = Tree2List(tree2);
    List_Sort(_volverts, compareVertex);
    Tree_Delete(tree2);
  }

  Tree_Delete(tree);
  
  // Transfer the vertices
  for(int i = 0; i < List_Nbr(_surverts); i++){
    Vertex *v;
    List_Read(_surverts, i, &v);
    double tmp[3];
    tmp[0] = v->Pos.X;
    tmp[1] = v->Pos.Y;
    tmp[2] = v->Pos.Z;
    Ng_AddPoint(_ngmesh, tmp);
  }
  for(int i = 0; i < List_Nbr(_volverts); i++){
    Vertex *v;
    List_Read(_volverts, i, &v);
    double tmp[3];
    tmp[0] = v->Pos.X;
    tmp[1] = v->Pos.Y;
    tmp[2] = v->Pos.Z;
    Ng_AddPoint(_ngmesh, tmp);
  }

  // Transfert all surface simplices
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
      Ng_AddSurfaceElement(_ngmesh, NG_TRIG, tmp);
    }
    List_Delete(simplist);
  }
  
  // Transfer the volume elements
  if(importVolumeMesh){
    List_T *simplist = Tree2List(_vol->Simplexes);
    for(int i = 0; i < List_Nbr(simplist); i++) {
      Simplex *simp;
      List_Read(simplist, i, &simp);
      if(simp->Volume_Simplexe() > 0) { // FIXME: check this!
	Vertex *temp = simp->V[0];
	simp->V[0] = simp->V[1];
	simp->V[1] = temp;
      }
      int tmp[4];
      tmp[0] = 1 + List_ISearch(_surverts, &simp->V[0], compareVertex);
      tmp[1] = 1 + List_ISearch(_surverts, &simp->V[1], compareVertex);
      tmp[2] = 1 + List_ISearch(_surverts, &simp->V[2], compareVertex);
      tmp[3] = 1 + List_ISearch(_surverts, &simp->V[3], compareVertex);
      int n = List_Nbr(_surverts) + 1;
      if(!tmp[0]) tmp[0] = n + List_ISearch(_volverts, &simp->V[0], compareVertex);
      if(!tmp[1]) tmp[1] = n + List_ISearch(_volverts, &simp->V[1], compareVertex);
      if(!tmp[2]) tmp[2] = n + List_ISearch(_volverts, &simp->V[2], compareVertex);
      if(!tmp[3]) tmp[3] = n + List_ISearch(_volverts, &simp->V[3], compareVertex);
      Ng_AddVolumeElement(_ngmesh, NG_TET, tmp);
    }
    List_Delete(simplist);    
  }
}

Netgen::Netgen(Surface *sur, int importSurfaceMesh)
{
  // todo
}

Netgen::~Netgen()
{
  List_Delete(_surverts);
  List_Delete(_volverts);
  Ng_DeleteMesh(_ngmesh);
  Ng_Exit();
}

void Netgen::MeshVolume()
{
  Ng_Meshing_Parameters mp;
  mp.maxh = 1;
  mp.fineness = 1;
  mp.secondorder = 0;
  //Ng_GenerateVolumeMesh(_ngmesh, &mp);
  NgAddOn_GenerateVolumeMesh(_ngmesh, &mp); // does not optimize
}

void Netgen::TransferVolumeMesh()
{
  // Gets total number of vertices of Netgen's mesh
  int nbv = Ng_GetNP(_ngmesh);
  
  if(!nbv) return;

  Vertex **vtable = (Vertex **)Malloc(nbv * sizeof(Vertex*));
  
  // Get existing unmodified surface vertices
  for(int i = 0; i < List_Nbr(_surverts); i++){
    List_Read(_surverts, i, &vtable[i]);
    Tree_Insert(_vol->Vertices, &vtable[i]);
    Tree_Insert(THEM->Vertices, &vtable[i]);
  }

  // Create new volume vertices
  for(int i = List_Nbr(_surverts); i < nbv; i++) {
    double tmp[3];
    Ng_GetPoint(_ngmesh, i+1, tmp);
    vtable[i] = Create_Vertex(++(THEM->MaxPointNum), tmp[0], tmp[1], tmp[2], 1., 0);
    Tree_Add(_vol->Vertices, &vtable[i]);
    Tree_Add(THEM->Vertices, &vtable[i]);
  }

  // Get total number of simplices of Netgen's mesh
  int nbe = Ng_GetNE(_ngmesh);

  // Create new volume simplices
  for(int i = 0; i < nbe; i++) {
    int tmp[4];
    Ng_GetVolumeElement(_ngmesh, i+1, tmp);
    Simplex *simp = Create_Simplex(vtable[tmp[0]-1], vtable[tmp[1]-1],
				   vtable[tmp[2]-1], vtable[tmp[3]-1]);
    simp->iEnt = _vol->Num;
    Tree_Add(_vol->Simplexes, &simp);
    // also add a copy in the global simplex tree
    Tree_Add(THEM->Simplexes, &simp);
  }
  
  Free(vtable);
}

static void suppressSimplex(void *a, void *b)
{
  Tree_Suppress(THEM->Simplexes, a);
}

void Netgen::OptimizeVolume()
{
  Ng_Meshing_Parameters mp;
  mp.maxh = 1;
  mp.fineness = 1;
  mp.secondorder = 0;

  // remove the pure volume vertices from the mesh
  for(int i = 0; i < List_Nbr(_volverts); i++){
    Vertex *v;
    List_Read(_volverts, i, &v);
    Tree_Suppress(_vol->Vertices, &v);
    Tree_Suppress(THEM->Vertices, &v);
    Free_Vertex(&v, NULL);
  }
  // remove the tets
  Tree_Action(_vol->Simplexes, suppressSimplex);
  Tree_Action(_vol->Simplexes, Free_Simplex);
  Tree_Delete(_vol->Simplexes);
  _vol->Simplexes = Tree_Create(sizeof(Simplex*), compareQuality);

  NgAddOn_OptimizeVolumeMesh(_ngmesh, &mp);
}

int Mesh_Netgen(Volume * v)
{
  if(CTX.mesh.algo3d != FRONTAL_NETGEN)
    return 0;

  if(CTX.mesh.bgmesh_type == ONFILE){
    Msg(GERROR, "Netgen is not ready to be used with a background mesh");
    return 0;
  }

  Msg(STATUS2, "Meshing volume %d", v->Num);
  Netgen ng(v);
  ng.MeshVolume();
  ng.TransferVolumeMesh();
  
  return 1;
}

void Optimize_Netgen(Volume * v)
{
  // abort of we don't have real volumes (volume has no CAD, or has no
  // surface loop w/ oriented surfaces) or if there are no simplices
  // to optimize
  if(v->Typ == MSH_VOLUME_DISCRETE || v->Method == TRANSFINI ||
     Extrude_Mesh(v) || !Tree_Nbr(v->Simplexes))
    return;

  Msg(STATUS2, "Optimizing volume %d", v->Num);
  Netgen ng(v, 1);
  ng.OptimizeVolume();
  ng.TransferVolumeMesh();
}

void Optimize_Netgen()
{
  Msg(STATUS1, "Mesh optimize 3D...");
  double t1 = Cpu();

  // cleanup 2nd order vertices, if any
  Degre1(); 

  // make sure we don't have ONFILE (so that when we create simplices
  // we don't try to compute the quality from the bgmesh)
  CTX.mesh.bgmesh_type = WITHPOINTS; 

  List_T *list = Tree2List(THEM->Volumes);
  for(int i = 0; i < List_Nbr(list); i++){
    Volume *v;
    List_Read(list, i, &v);
    Optimize_Netgen(v);
  }
  List_Delete(list);

  double t2 = Cpu();
  Msg(STATUS1, "Mesh optimize 3D complete (%g s)", t2 - t1);
}

#endif // !HAVE_NETGEN
