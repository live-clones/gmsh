// $Id: 3D_Mesh_Netgen.cpp,v 1.1 2004-06-26 17:58:14 geuzaine Exp $
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
//
// Contributor(s):
//   Nicolas Tardieu
//

#include "Gmsh.h"
#include "Mesh.h"
#include "Numeric.h"
#include "Context.h"

#if !defined(HAVE_NETGEN)

int Mesh_Netgen(Surface * s)
{
  Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
  return 0;
}

#else

extern "C"
{
#include "nglib.h"
}

extern Context_T CTX;
extern Mesh *THEM;

int Mesh_Netgen(Volume * v)
{
  if(CTX.mesh.algo3d != FRONTAL_NETGEN)
    return 0;

  if(THEM->BGM.Typ == ONFILE){
    Msg(GERROR, "Netgen is not ready to be used with a background mesh");
    return 0;
  }

  List_T *lSurfaceVertexList = List_Create(100, 100, sizeof(Vertex*));
  
  // ===================================
  //         GMSH => NETGEN 
  // ===================================
  
  // creates Netgen mesh structure
  Ng_Init();
  Ng_Mesh *lNetgenMesh = Ng_NewMesh();

  // Transfert all surface vertices to Netgen
  for(int i = 0; i < List_Nbr(v->Surfaces); i++) {
    Surface *s;
    List_Read(v->Surfaces, i, &s);
    List_T *lVertexList = Tree2List(s->Vertices);
    for(int j = 0; j < List_Nbr(lVertexList); j++) {
      Vertex *lVertex;
      List_Read(lVertexList, j, &lVertex);
      // We must *not* add 2 times the same vertex (the same vertex
      // can belong to several surfaces)
      if(List_ISearchSeq(lSurfaceVertexList, &lVertex, compareVertex) < 0) {
	List_Add(lSurfaceVertexList, &lVertex);
	double tmp[3];
	tmp[0] = lVertex->Pos.X;
	tmp[1] = lVertex->Pos.Y;
	tmp[2] = lVertex->Pos.Z;
      	Ng_AddPoint(lNetgenMesh, tmp);
      }
    }
    List_Delete(lVertexList) ;
  }
      
  // Transfert all surface simplices to Netgen
  for(int i = 0; i < List_Nbr(v->Surfaces); i++) {
    Surface *s;
    int sign;
    List_Read(v->Surfaces, i, &s);
    List_Read(v->SurfacesOrientations, i, &sign);
    List_T *lSimplexeList = Tree2List(s->Simplexes);
    for(int j = 0; j < List_Nbr(lSimplexeList); j++) {
      Simplex *lSimplex;
      List_Read(lSimplexeList, j, &lSimplex);
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
      tmp[0] = 1 + List_ISearchSeq(lSurfaceVertexList, &lSimplex->V[index[0]],
				   compareVertex);
      tmp[1] = 1 + List_ISearchSeq(lSurfaceVertexList, &lSimplex->V[index[1]],
				   compareVertex);
      tmp[2] = 1 + List_ISearchSeq(lSurfaceVertexList, &lSimplex->V[index[2]],
				   compareVertex);
      Ng_AddSurfaceElement(lNetgenMesh, NG_TRIG, tmp);
    }
    List_Delete(lSimplexeList);
  }

  // ===================================
  //            MESHING
  // ===================================
  
  // define Netgen meshing option
  Ng_Meshing_Parameters mp;
  mp.maxh = 1;
  mp.fineness = 1;
  mp.secondorder = 0;

  // generate Netgen volume mesh
  Msg(STATUS3, "Meshing volume %d", v->Num);
  Ng_GenerateVolumeMesh(lNetgenMesh, &mp);
  
  // ===================================
  //            NETGEN => GMSH
  // ===================================
  
  // Gets total number of vertices of Netgen's mesh
  int lNbOfNGPoints = Ng_GetNP(lNetgenMesh);
  Vertex **vtable = (Vertex **)Malloc(lNbOfNGPoints * sizeof(Vertex*));
  
  // Writes existing surface vertices
  for(int i = 0; i < List_Nbr(lSurfaceVertexList); i++)
    List_Read(lSurfaceVertexList, i, &vtable[i]);

  // Writes and transfers new volume vertices
  for(int i = List_Nbr(lSurfaceVertexList); i < lNbOfNGPoints; i++) {
    double tmp[3];
    Ng_GetPoint(lNetgenMesh, i+1, tmp);
    vtable[i] = Create_Vertex(++(THEM->MaxPointNum), tmp[0], tmp[1], tmp[2], 1., 0);
    Tree_Add(v->Vertices, &vtable[i]);
    Tree_Add(THEM->Vertices, &vtable[i]);
  }

  // Get total number of simplices of Netgen's mesh
  int lNbOfNGElements = Ng_GetNE(lNetgenMesh);
  // Transfers new volume simplices
  for(int i = 1; i <= lNbOfNGElements; i++) {
    int tmp[4];
    Ng_GetVolumeElement(lNetgenMesh, i, tmp);
    Simplex *lSimplex = Create_Simplex(vtable[tmp[0]-1], vtable[tmp[1]-1],
				       vtable[tmp[2]-1], vtable[tmp[3]-1]);
    lSimplex->iEnt = v->Num;
    Tree_Add(v->Simplexes, &lSimplex);
  }

  List_Delete(lSurfaceVertexList);
  Free(vtable);

  Ng_DeleteMesh(lNetgenMesh);
  Ng_Exit();

  return 1;
}

#endif // !HAVE_NETGEN
