// $Id: DiscreteSurface.cpp,v 1.6 2005-03-14 18:12:29 geuzaine Exp $
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
// Please report all bugs and problems to "gmsh@geuz.org".
//
// Contributor(s):
//   Nicolas Tardieu
//

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "DiscreteSurface.h"
#include "CAD.h"
#include "Geo.h"
#include "Create.h"
#include "Interpolation.h"
#include "Context.h"

extern Mesh *THEM;
extern Context_T CTX;

#define VAL_INF 1.e200

static Tree_T * VertexBound = NULL;

static void InsertInVertexBound(void *a, void *b)
{
  Tree_Insert(VertexBound, a);
}

// Polygonal representation of discrete surfaces

POLY_rep::POLY_rep()
  : num_points(0), num_polys(0)
{
  points_and_normals = List_Create(100, 100, sizeof(double));
  polygons = List_Create(100, 100, sizeof(double));
  bounding_box[0] = bounding_box[2] = bounding_box[4] = VAL_INF;
  bounding_box[1] = bounding_box[3] = bounding_box[5] = -VAL_INF;
}

POLY_rep::POLY_rep(int _num_points, int _num_polys, List_T *_p, List_T *_pol)
  : num_points(_num_points), num_polys(_num_polys),
    points_and_normals(_p), polygons(_pol)
{
  bounding_box[0] = bounding_box[2] = bounding_box[4] = VAL_INF;
  bounding_box[1] = bounding_box[3] = bounding_box[5] = -VAL_INF;

  // check num points
  if(List_Nbr(points_and_normals) != num_points * 6){
    Msg(GERROR, "Wrong number of points in discrete surface");
    if(polygons){
      List_Delete(polygons);
      polygons = 0;      
    }
    if(points_and_normals){
      List_Delete(points_and_normals);
      points_and_normals = 0;
    }
    return;
  }

  // compute the bbox
  compute_bounding_box();

  // check polygons
  int k = 0;
  while (k < List_Nbr(polygons)){
    double *points = (double*)List_Pointer(polygons,k);
    k += ((int)points[0] + 1);
    for(int i = 0; i < (int)points[0]; i++){
      if(6 * (int)points[1+i] >= List_Nbr(points_and_normals)){
	Msg(GERROR, "Wrong point index in discrete surface");
	if(polygons){
	  List_Delete(polygons);
	  polygons = 0;      
	}
	if(points_and_normals){
	  List_Delete(points_and_normals);
	  points_and_normals = 0;
	}
	return;
      }
    }
  }
}

void POLY_rep::compute_bounding_box()
{
  for(int i = 0; i < List_Nbr(points_and_normals); i+=6){
    double *points = (double*)List_Pointer(points_and_normals, i);
    if(points[0] < bounding_box[0]) bounding_box[0] = points[0];
    if(points[0] > bounding_box[1]) bounding_box[1] = points[0];
    if(points[1] < bounding_box[2]) bounding_box[2] = points[1];
    if(points[1] > bounding_box[3]) bounding_box[3] = points[1];
    if(points[2] < bounding_box[4]) bounding_box[4] = points[2];
    if(points[2] > bounding_box[5]) bounding_box[5] = points[2];
  }
}

POLY_rep::~POLY_rep()
{
  if(polygons) List_Delete(polygons);
  if(points_and_normals) List_Delete(points_and_normals);
}

double SetLC(Vertex *v1, Vertex *v2, Vertex *v3, double factor)
{ 
  double lc1 = sqrt((v1->Pos.X - v2->Pos.X) * (v1->Pos.X - v2->Pos.X) +
		    (v1->Pos.Y - v2->Pos.Y) * (v1->Pos.Y - v2->Pos.Y) +
		    (v1->Pos.Z - v2->Pos.Z) * (v1->Pos.Z - v2->Pos.Z));
  double lc2 = sqrt((v1->Pos.X - v3->Pos.X) * (v1->Pos.X - v3->Pos.X) +
		    (v1->Pos.Y - v3->Pos.Y) * (v1->Pos.Y - v3->Pos.Y) +
		    (v1->Pos.Z - v3->Pos.Z) * (v1->Pos.Z - v3->Pos.Z));
  double lc3 = sqrt((v2->Pos.X - v3->Pos.X) * (v2->Pos.X - v3->Pos.X) +
		    (v2->Pos.Y - v3->Pos.Y) * (v2->Pos.Y - v3->Pos.Y) +
		    (v2->Pos.Z - v3->Pos.Z) * (v2->Pos.Z - v3->Pos.Z));
  double lc = DMAX(lc1, DMAX(lc2, lc3)) * factor;
  v1->lc = v2->lc = v3->lc = lc;
  return lc;
}

void POLY_rep_To_Mesh(POLY_rep *prep, Surface *s)
{  
  VertexBound = Tree_Create(sizeof(Vertex *), comparePosition);
  Tree_Action(THEM->Vertices, InsertInVertexBound);

  Vertex **verts = new Vertex*[List_Nbr(prep->points_and_normals)/6];

  for(int i = 0; i < List_Nbr(prep->points_and_normals); i+=6){
    double *point = (double*)List_Pointer(prep->points_and_normals, i);
    Vertex *v = Create_Vertex(++THEM->MaxPointNum, point[0], point[1], point[2], 1.0, 0.0);
    Vertex **pv;
    if(!(pv = (Vertex**)Tree_PQuery(VertexBound, &v))){
      Tree_Add(VertexBound, &v);
      Tree_Add(s->Vertices, &v);
      verts[i/6] = v;
    }
    else{
      Free_Vertex(&v, NULL);
      Tree_Insert(s->Vertices, pv);
      verts[i/6] = *pv;
    }
  }
  
  int k = 0;
  while (k < List_Nbr(prep->polygons)){
    double *points = (double*)List_Pointer(prep->polygons,k);
    k+= ((int)points[0] + 1);
    if (points[0] == 3){
      Vertex *v1 = verts[(int)points[1]];
      Vertex *v2 = verts[(int)points[2]];
      Vertex *v3 = verts[(int)points[3]];
      SetLC(v1, v2, v3, CTX.mesh.lc_factor);
      Simplex *simp = Create_Simplex(v1, v2, v3, NULL);
      simp->iEnt = s->Num;
      Tree_Add(s->Simplexes, &simp);
    }
    else if (points[0] == 4){
      Vertex *v1 = verts[(int)points[1]];
      Vertex *v2 = verts[(int)points[2]];
      Vertex *v3 = verts[(int)points[3]];
      Vertex *v4 = verts[(int)points[4]];
      SetLC(v1, v2, v3, CTX.mesh.lc_factor);
      v4->lc = v1->lc;
      Quadrangle *quad = Create_Quadrangle(v1, v2, v3, v4);
      quad->iEnt = s->Num;
      Tree_Add(s->Quadrangles, &quad);
    }
  }
  
  Tree_Delete(VertexBound);
  delete [] verts;
}

// Routines to process STL surfaces

static Surface *STL_Surf;

static void ComputeNormal(Surface * Surface, double Normal[3])
{
  Curve *Curve1;
  List_Read(Surface->Generatrices, 0, &Curve1);

  Curve *Curve2;
  List_Read(Surface->Generatrices, 1, &Curve2);

  Vertex *Point11 = Curve1->beg;
  Vertex *Point12 = Curve1->end;

  Vertex *Point21 = Curve2->beg;
  Vertex *Point22 = Curve2->end;

  double vec1[3];
  vec1[0] = (Point12->Pos.X) - (Point11->Pos.X);
  vec1[1] = (Point12->Pos.Y) - (Point11->Pos.Y);
  vec1[2] = (Point12->Pos.Z) - (Point11->Pos.Z);

  double vec2[3];
  vec2[0] = (Point22->Pos.X) - (Point21->Pos.X);
  vec2[1] = (Point22->Pos.Y) - (Point21->Pos.Y);
  vec2[2] = (Point22->Pos.Z) - (Point21->Pos.Z);

  prodve(vec1, vec2, Normal);
  norme(Normal);
}

static bool BelongToPhysicalEntity(int SurfaceNumber,
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

static void AddCorrectNeighborToPhysical(Surface * Surf1, PhysicalGroup * CurrentPhysicalGroup)
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

static void CreatePhysicalSurface()
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

void STLStartSolid()
{
  VertexBound = Tree_Create(sizeof(Vertex *), comparePosition);
  if(CTX.geom.stl_create_elementary){
    Tree_Action(THEM->Points, InsertInVertexBound);
  }
  else{
    STL_Surf = Create_Surface(NEWSURFACE(), MSH_SURF_DISCRETE);
    STL_Surf->thePolyRep = new POLY_rep();
  }
}

void STLEndSolid()
{
  if(CTX.geom.stl_create_elementary){
    ReplaceAllDuplicates(THEM);
    if(CTX.geom.stl_create_physical)
      CreatePhysicalSurface();
  }
  else{
    STL_Surf->thePolyRep->compute_bounding_box();
    STL_Surf->Support = STL_Surf;
    End_Surface(STL_Surf);
    Tree_Add(THEM->Surfaces, &STL_Surf);
    Tree_Action(VertexBound, Free_Vertex);
  }
  Tree_Delete(VertexBound);
}

void STLAddFacet(double x1, double y1, double z1,
		 double x2, double y2, double z2,
		 double x3, double y3, double z3,
		 double n1, double n2, double n3)
{
  Vertex **ppv;

  // Create the nodes
  Vertex *v1 = Create_Vertex(++THEM->MaxPointNum, x1, y1, z1, 1., 0);
  if((ppv = (Vertex **) Tree_PQuery(VertexBound, &v1))) {
    Free_Vertex(&v1, NULL);
    v1 = *ppv;
  }
  else {
    Tree_Add(VertexBound, &v1);
    if(CTX.geom.stl_create_elementary) Tree_Add(THEM->Points, &v1);
  }

  Vertex *v2 = Create_Vertex(++THEM->MaxPointNum, x2, y2, z2, 1., 0);
  if((ppv = (Vertex **) Tree_PQuery(VertexBound, &v2))) {
    Free_Vertex(&v2, NULL);
    v2 = *ppv;
  }
  else {
    Tree_Add(VertexBound, &v2);
    if(CTX.geom.stl_create_elementary) Tree_Add(THEM->Points, &v2);
  }

  Vertex *v3 = Create_Vertex(++THEM->MaxPointNum, x3, y3, z3, 1., 0);
  if((ppv = (Vertex **) Tree_PQuery(VertexBound, &v3))) {
    Free_Vertex(&v3, NULL);
    v3 = *ppv;
  }
  else {
    Tree_Add(VertexBound, &v3);
    if(CTX.geom.stl_create_elementary) Tree_Add(THEM->Points, &v3);
  }

  if(CTX.geom.stl_create_elementary){
    // Compute a reasonnable Characteristic Length
    SetLC(v1, v2, v3, 1.);

    // Create each curve
    Curve *c1 = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c1->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    List_Add(c1->Control_Points, &v1);
    List_Add(c1->Control_Points, &v2);
    c1->beg = v1;
    c1->end = v2;
    End_Curve(c1);
    Tree_Add(THEM->Curves, &c1);
    CreateReversedCurve(THEM, c1);
    
    Curve *c2 = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c2->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    List_Add(c2->Control_Points, &v2);
    List_Add(c2->Control_Points, &v3);
    c2->beg = v2;
    c2->end = v3;
    End_Curve(c2);
    Tree_Add(THEM->Curves, &c2);
    CreateReversedCurve(THEM, c2);
    
    Curve *c3 = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c3->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    List_Add(c3->Control_Points, &v3);
    List_Add(c3->Control_Points, &v1);
    c3->beg = v3;
    c3->end = v1;
    End_Curve(c3);
    Tree_Add(THEM->Curves, &c3);
    CreateReversedCurve(THEM, c3);
    
    // Creation Of Each Surface
    Surface *s = Create_Surface(NEWSURFACE(), MSH_SURF_PLAN);
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
    STL_Surf->thePolyRep->num_points += 3;
    STL_Surf->thePolyRep->num_polys += 1;
    List_T *pts = STL_Surf->thePolyRep->points_and_normals;
    double num = List_Nbr(pts) / 6;
    List_Add(pts, &v1->Pos.X); List_Add(pts, &v1->Pos.Y); List_Add(pts, &v1->Pos.Z);
    List_Add(pts, &n1); List_Add(pts, &n2); List_Add(pts, &n3);
    List_Add(pts, &v2->Pos.X); List_Add(pts, &v2->Pos.Y); List_Add(pts, &v2->Pos.Z);
    List_Add(pts, &n1); List_Add(pts, &n2); List_Add(pts, &n3);
    List_Add(pts, &v3->Pos.X); List_Add(pts, &v3->Pos.Y); List_Add(pts, &v3->Pos.Z);
    List_Add(pts, &n1); List_Add(pts, &n2); List_Add(pts, &n3);
    List_T *pol = STL_Surf->thePolyRep->polygons;
    double n = 3;
    List_Add(pol, &n); 
    List_Add(pol, &num); num += 1.;
    List_Add(pol, &num); num += 1.;
    List_Add(pol, &num);
  }
}

// Representation of discrete curves

SEGM_rep::SEGM_rep()
  : num_points(0)
{
  points = List_Create(100, 100, sizeof(double));
  bounding_box[0] = bounding_box[2] = bounding_box[4] = VAL_INF;
  bounding_box[1] = bounding_box[3] = bounding_box[5] = -VAL_INF;
}

SEGM_rep::SEGM_rep(int _num_points, List_T *_p)
  : num_points(_num_points), points(_p)
{
  bounding_box[0] = bounding_box[2] = bounding_box[4] = VAL_INF;
  bounding_box[1] = bounding_box[3] = bounding_box[5] = -VAL_INF;

  // check num points
  if(List_Nbr(points) != num_points * 3){
    Msg(GERROR, "Wrong number of points in discrete curve");
    if(points){
      List_Delete(points);
      points = 0;
    }
    return;
  }

  // compute the bbox
  compute_bounding_box();
}

void SEGM_rep::compute_bounding_box()
{
  for(int i = 0; i < List_Nbr(points); i+=3){
    double *p = (double*)List_Pointer(points, i);
    if(p[0] < bounding_box[0]) bounding_box[0] = p[0];
    if(p[0] > bounding_box[1]) bounding_box[1] = p[0];
    if(p[1] < bounding_box[2]) bounding_box[2] = p[1];
    if(p[1] > bounding_box[3]) bounding_box[3] = p[1];
    if(p[2] < bounding_box[4]) bounding_box[4] = p[2];
    if(p[2] > bounding_box[5]) bounding_box[5] = p[2];
  }
}

SEGM_rep::~SEGM_rep()
{
  if(points) List_Delete(points);
}

double SetLC(Vertex *v1, Vertex *v2, double factor)
{ 
  double lc = sqrt((v1->Pos.X - v2->Pos.X) * (v1->Pos.X - v2->Pos.X) +
		   (v1->Pos.Y - v2->Pos.Y) * (v1->Pos.Y - v2->Pos.Y) +
		   (v1->Pos.Z - v2->Pos.Z) * (v1->Pos.Z - v2->Pos.Z));
  v1->lc = v2->lc = lc;
  return lc;
}

void SEGM_rep_To_Mesh(SEGM_rep *srep, Curve *c)
{  
  VertexBound = Tree_Create(sizeof(Vertex *), comparePosition);
  Tree_Action(THEM->Vertices, InsertInVertexBound);

  int N = List_Nbr(srep->points)/3;

  Vertex **verts = new Vertex*[N];

  for(int i = 0; i < List_Nbr(srep->points); i+=3){
    double *point = (double*)List_Pointer(srep->points, i);
    // if the curve's end points exist, use their identification
    // numbers (that's how we do things in 1D_Mesh, and it makes
    // things easier for point extrusions in the old extrusion
    // algorithm)
    int num;
    if(i == 0 && c->beg)
      num = c->beg->Num;
    else if(i/3 == N-1 && c->end)
      num = c->end->Num;
    else
      num = ++THEM->MaxPointNum;
    Vertex *v = Create_Vertex(num, point[0], point[1], point[2], 1.0, 0.0);
    Vertex **pv;
    if(!(pv = (Vertex**)Tree_PQuery(VertexBound, &v))){
      Tree_Add(VertexBound, &v);
      List_Add(c->Vertices, &v);
      v->ListCurves = List_Create(1, 1, sizeof(Curve *));
      List_Add(v->ListCurves, &c);
      Tree_Add(THEM->Vertices, &v);
      verts[i/3] = v;
    }
    else{
      Free_Vertex(&v, NULL);
      List_Add(c->Vertices, pv);
      if((*pv)->ListCurves)
	List_Add((*pv)->ListCurves, &c);
      verts[i/3] = *pv;
    }
  }
  
  for(int i = 0; i < N-1; i++){
    Vertex *v1 = verts[i];
    Vertex *v2 = verts[i+1];
    SetLC(v1, v2, CTX.mesh.lc_factor);
    Simplex *simp = Create_Simplex(v1, v2, NULL, NULL);
    simp->iEnt = c->Num;
    Tree_Add(c->Simplexes, &simp);
  }

  Tree_Delete(VertexBound);
  delete [] verts;
}

// Public interface for discrete surface/curve mesh algo

int MeshDiscreteSurface(Surface *s)
{
  if(s->thePolyRep){
    // Use the polygonal representation as the surface mesh. Most of
    // the time we should of course remesh/enhance/refine this (as
    // there is no guarantee that a polygonal CAD mesh is conform,
    // that it respects the boundaries, etc.), but we don't have any
    // routines to do that at the moment--so let's just use it and
    // hope for the best.
    POLY_rep_To_Mesh(s->thePolyRep, s);
    return 1;
  }
  else if(s->Typ == MSH_SURF_DISCRETE){
    // nothing else to do: we assume that the elements have alreay
    // been created
    return 1;
  }
  else
    return 0;
}

int MeshDiscreteCurve(Curve *c)
{
  if(c->theSegmRep){
    // Use the discrete representation as the curve mesh. Most of the
    // time we should of course remesh/enhance/refine this (as there
    // is no guarantee that this mesh fits at interfaces, etc.), but
    // we don't have any routines to do that at the moment--so let's
    // just use it and hope for the best.
    SEGM_rep_To_Mesh(c->theSegmRep, c);
    return 1;
  }
  else if(c->Typ == MSH_SEGM_DISCRETE){
    // nothing else to do: we assume that the elements have alreay
    // been created
    return 1;
  }
  else
    return 0;
}
