// $Id: STL.cpp,v 1.12 2004-02-28 00:48:50 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   Nicolas Tardieu
//

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "STL.h"
#include "CAD.h"
#include "Geo.h"
#include "Create.h"
#include "Interpolation.h"
#include "Context.h"

extern Mesh *THEM;
extern Context_T CTX;

bool BelongToPhysicalEntity(int SurfaceNumber,
                            PhysicalGroup * CurrentPhysicalGroup)
{
  PhysicalGroup *PhysicalGroup;
  int NbPhysicalGroup = List_Nbr(THEM->PhysicalGroups);
  bool Belong = false;

  // Search if the current Surface belongs to the current PhysicalGroup
  if(CurrentPhysicalGroup != NULL) {
    if(List_Search(CurrentPhysicalGroup->Entities, &SurfaceNumber, fcmp_int)) {
      Belong = true;
    }
  }

  // Search if the current Surface belongs to another PhysicalGroup
  if(!Belong) {
    for(int i = 0; i < NbPhysicalGroup; i++) {
      List_Read(THEM->PhysicalGroups, i, &PhysicalGroup);
      if((PhysicalGroup->Typ == MSH_PHYSICAL_SURFACE) && (!Belong)) {
        if(List_Search(PhysicalGroup->Entities, &SurfaceNumber, fcmp_int)) {
          Belong = true;
          break;
        }
      }
    }
  }
  return Belong;
}


void ComputeNormal(Surface * Surface, double Normal[3])
{
  Curve *Curve1;
  Curve *Curve2;
  Vertex *Point11;
  Vertex *Point12;
  Vertex *Point21;
  Vertex *Point22;

  double vec1[3];
  double vec2[3];

  List_Read(Surface->Generatrices, 0, &Curve1);
  List_Read(Surface->Generatrices, 1, &Curve2);

  Point11 = Curve1->beg;
  Point12 = Curve1->end;

  Point21 = Curve2->beg;
  Point22 = Curve2->end;

  vec1[0] = (Point12->Pos.X) - (Point11->Pos.X);
  vec1[1] = (Point12->Pos.Y) - (Point11->Pos.Y);
  vec1[2] = (Point12->Pos.Z) - (Point11->Pos.Z);

  vec2[0] = (Point22->Pos.X) - (Point21->Pos.X);
  vec2[1] = (Point22->Pos.Y) - (Point21->Pos.Y);
  vec2[2] = (Point22->Pos.Z) - (Point21->Pos.Z);

  prodve(vec1, vec2, Normal);
  norme(Normal);
}

void AddCorrectNeighborToPhysical(Surface * Surf1, PhysicalGroup * CurrentPhysicalGroup)
{

  double Normal1[3], Normal2[3];
  int elem2;
  List_T *pSurfaceList = Tree2List(THEM->Surfaces);
  Surface *Surf2;
  int NbSimplex = Tree_Nbr(THEM->Surfaces);
  Curve *Curve1;
  Curve *Curve2;

  ComputeNormal(Surf1, Normal1);

  // Scan all the elements to find a Surface not belonging to an existing PhysicalGroup
  for(elem2 = 1; elem2 < NbSimplex; elem2++) {
    List_Read(pSurfaceList, elem2, &Surf2);
    if(BelongToPhysicalEntity(Surf2->Num, CurrentPhysicalGroup)) {
      continue;
    }

    ComputeNormal(Surf2, Normal2);
    double Scal =
      Normal1[0] * Normal2[0] + Normal1[1] * Normal2[1] +
      Normal1[2] * Normal2[2];
    // If the normals are OK, determine if the surfaces are neighbors
    if((fabs(Scal) > 0.90) && ((Surf1->Num) != (Surf2->Num))) {
      bool Exit = false;
      for(int i = 0; i < 3; i++) {
        if(!Exit) {
          for(int j = 0; j < 3; j++) {
            List_Read(Surf1->Generatrices, i, &Curve1);
            List_Read(Surf2->Generatrices, j, &Curve2);
            // The Surface have a common Edge
	    if(fabs(Curve1->Num) == fabs(Curve2->Num)) {
              List_Add(CurrentPhysicalGroup->Entities, &(Surf2->Num));
              AddCorrectNeighborToPhysical(Surf2, CurrentPhysicalGroup);
              Exit = true;
              break;
            }
          }
        }
      }
    }
  }
}

STL_Data::STL_Data()
{
  Vertices = Tree_Create(sizeof(Vertex *), comparePosition);
  Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
  LSimplexes = NULL;
  LVertices = NULL;
}

STL_Data::~STL_Data()
{
}

void STL_Data::Add_Facet(double x1, double y1, double z1,
                         double x2, double y2, double z2,
                         double x3, double y3, double z3,
			 int in_geometry)
{
  Vertex **ppv;

  // Calculation Of Characterisctic Length
  double lc1 =
    sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) +
         (z1 - z2) * (z1 - z2));
  double lc2 =
    sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) +
         (z1 - z3) * (z1 - z3));
  double lc3 =
    sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) +
         (z2 - z3) * (z2 - z3));
  double lc = DMAX(lc1, DMAX(lc2, lc3));


  // Importation Of Nodes
  Vertex *v1 = Create_Vertex(Tree_Nbr(Vertices) + 1, x1, y1, z1, lc, 0);
  if((ppv = (Vertex **) Tree_PQuery(Vertices, &v1))) {
    delete v1;
    v1 = *ppv;
  }
  else {
    Tree_Add(Vertices, &v1);
    Tree_Add(THEM->Points, &v1);
  }

  Vertex *v2 = Create_Vertex(Tree_Nbr(Vertices) + 1, x2, y2, z2, lc, 0);
  if((ppv = (Vertex **) Tree_PQuery(Vertices, &v2))) {
    delete v2;
    v2 = *ppv;
  }
  else {
    Tree_Add(Vertices, &v2);
    Tree_Add(THEM->Points, &v2);
  }

  Vertex *v3 = Create_Vertex(Tree_Nbr(Vertices) + 1, x3, y3, z3, lc, 0);
  if((ppv = (Vertex **) Tree_PQuery(Vertices, &v3))) {
    delete v3;
    v3 = *ppv;
  }
  else {
    Tree_Add(Vertices, &v3);
    Tree_Add(THEM->Points, &v3);
  }

  if(in_geometry){
    // Creation Of Each Curve
    Curve *c1;
    c1 = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c1->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    List_Add(c1->Control_Points, &v1);
    List_Add(c1->Control_Points, &v2);
    c1->beg = v1;
    c1->end = v2;
    End_Curve(c1);
    Tree_Add(THEM->Curves, &c1);
    CreateReversedCurve(THEM, c1);
    
    Curve *c2;
    c2 = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c2->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    List_Add(c2->Control_Points, &v2);
    List_Add(c2->Control_Points, &v3);
    c2->beg = v2;
    c2->end = v3;
    End_Curve(c2);
    Tree_Add(THEM->Curves, &c2);
    CreateReversedCurve(THEM, c2);
    
    Curve *c3;
    c3 = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c3->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    List_Add(c3->Control_Points, &v3);
    List_Add(c3->Control_Points, &v1);
    c3->beg = v3;
    c3->end = v1;
    End_Curve(c3);
    Tree_Add(THEM->Curves, &c3);
    CreateReversedCurve(THEM, c3);
    
    // Creation Of Each Surface
    Surface *s;
    s = Create_Surface(NEWSURFACE(), MSH_SURF_PLAN);
    s->Method = LIBRE;
    s->Generatrices = List_Create(4, 1, sizeof(Curve *));
    List_Add(s->Generatrices, &c1);
    List_Add(s->Generatrices, &c2);
    List_Add(s->Generatrices, &c3);
    s->Support = s;
    End_Surface(s);
    Tree_Insert(THEM->Surfaces, &s);
  }
  else{
    Simplex *s = Create_Simplex(v1, v2, v3, NULL);
    Tree_Add(Simplexes, &s);
  }
}

void STL_Data::ReplaceDuplicate()
{
  ReplaceAllDuplicates(THEM);
}

void STL_Data::CreatePhysicalSurface()
{
  Surface *Surf1;
  PhysicalGroup *CurrentPhysicalGroup;
  int NbSimplex = Tree_Nbr(THEM->Surfaces);
  List_T *pSurfaceList = Tree2List(THEM->Surfaces);

  // Scan all Simplexes to find correct Neighbors and add them to a PhysicalGroup
  for(int elem1 = 0; elem1 < NbSimplex; elem1++) {
    List_Read(pSurfaceList, elem1, &Surf1);
    if(BelongToPhysicalEntity((Surf1->Num), NULL))
      continue;
    CurrentPhysicalGroup = (PhysicalGroup *) Malloc(sizeof(PhysicalGroup));
    CurrentPhysicalGroup->Num = List_Nbr(THEM->PhysicalGroups)+1;
    CurrentPhysicalGroup->Entities = List_Create(1, 1, sizeof(int));
    CurrentPhysicalGroup->Typ = MSH_PHYSICAL_SURFACE;
    CurrentPhysicalGroup->Visible = VIS_GEOM | VIS_MESH;
    List_Add(CurrentPhysicalGroup->Entities, &(Surf1->Num));
    AddCorrectNeighborToPhysical(Surf1, CurrentPhysicalGroup);
    if(List_Nbr(CurrentPhysicalGroup->Entities) > 0)
      List_Add(THEM->PhysicalGroups, &CurrentPhysicalGroup);
    else
      Free(CurrentPhysicalGroup);
  }
}

void STL_Data::GetFacet(int ifac, int &v1, int &v2, int &v3)
{
  Simplex *s;
  if(!LSimplexes)
    LSimplexes = Tree2List(Simplexes);
  List_Read(LSimplexes, ifac - 1, &s);
  v1 = s->V[0]->Num;
  v2 = s->V[1]->Num;
  v3 = s->V[2]->Num;
}

void STL_Data::GetVertex(int i, double &x, double &y, double &z)
{
  Vertex *v;
  if(!LVertices)
    LVertices = Tree2List(Vertices);
  List_Read(LVertices, i - 1, &v);
  x = v->Pos.X;
  y = v->Pos.Y;
  z = v->Pos.Z;
}
