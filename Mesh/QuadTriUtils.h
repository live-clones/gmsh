/************************************************************************************************** 
QuadTriUtils.h

The code in this file was written by Dr. Trevor S. Strickler.
email: <trevor.strickler@gmail.com> 

This file is part of the QuadTri contribution to Gmsh. QuadTri allows the conformal interface
of quadrangle faces to triangle faces using pyramids and other mesh elements. 

See READMEQUADTRI.txt for more information. The license information is in LICENSE.txt.

Trevor S. Strickler hereby transfers copyright of QuadTri files to 
Christophe Geuzaine and J.-F. Remacle with the understanding that 
his contribution shall be cited appropriately.

All reused or original Gmsh code is Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
Gmsh is available at: www.geuz.org/gmsh

For Gmsh license information, see the LICENSE.txt file for license information. Please report all
Gmsh bugs and problems to <gmsh@geuz.org>.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, Version 2,
as published by the Free Software Foundation, or (at your option) 
any later version, with or without the exception given in the 
LICENSE.txt file supplied with this code and with Gmsh.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

****************************************************************************************************/

#if !defined(_QUADTRIUTILS_H_)
#define _QUADTRIUTILS_H_

#include "ExtrudeParams.h"
#include "Geo.h"
#include "GEntity.h"
#include "GFace.h"
#include "GRegion.h"
#include "GEdge.h"
#include "GModel.h"
#include "GmshDefines.h"
#include "MVertex.h"
#include "Context.h"
#include "GModel.h"
#include "meshGFace.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "Numeric.h"
#include <map>
#include <math.h>


// CategorizedSourceElements: This is a data structure to hold categorized source element info for extruded regions.
// In addition to the region and source face pointers, there are sets and a vector that are set by the constructor.
// All containers except for the bool vectors contain indices to the source face's vectors of mesh elements:
//
// three_bnd_pt_tri : triangle vector indices for triangles with three vertices on a surface boundary edge
// four_bnd_pt_quad : quadrangle vector indices for quads with four vertices on a surface boundary edge
// other_bnd_pt_tri, other_bnd_pt_quad : vector indices of the respective elements that have some
//                                       but not all vertices on a boundary edge.
// internal_quad_touch_one_bnd_pt_quad : quad vector indices of quads that share a vertex with a 
//                                       one boundary point quad.
// internal_tri_touch_one_bnd_pt_quad  : triangle vector indices of triangles that share a vertex with a 
//                                       one boundary point quad.
// two_pt_bnd_quad_touch_one_bnd_pt_quad : set of indices to quads with two points on a boundary that also touch quads
//                                         with one point on a boundary.
// internal_tri, internal_quad : The indices for the internal elements that don't touch a boundary...
//                               NOTE: These DO include the internal_[tri,quad]_touch_one_bnd_pt_quad elements.
//
// The vectors:
//
// tri_bool, quad_bool : These vectors hold bits to tell which vertices in which elements are on the boundary, OR
//             in the case of the [*]_touch_one_bnd_pt_quad elements, what vertex is the non-boundary 'pivot' vertex shared
//             with a quad having one point on a boundary (diagonals are drawn to the pivot vertex in the single layer quadToTri
//             method). 
//             Format: In tri_bool, there are 4*(number of triangles) elements. Each source triangle of index i has  
//             four consecutive bool in tri_bool, beginning at i*4.  The first bool is true if the triangle touches an edge
//             boundary (or touches a one boundary point quad). The other bools correspond to triangle vertices, in order 
//             of appearance in the triangle's own vertex vector, and are true if the corresponding vertex is on the boundary. 
//             Everything about tri_bool applies to quad_bool, but there are 5 bool per quad, accessed starting at i*5.
// 

struct CategorizedSourceElements{
 public:
  GRegion *region; 
  GFace *source_face;
  bool valid;
  std::set<unsigned int> three_bnd_pt_tri, four_bnd_pt_quad, 
                         other_bnd_tri, other_bnd_quad;
  std::set<unsigned int> internal_tri_touch_one_bnd_pt_quad, 
                         internal_quad_touch_one_bnd_pt_quad,
                         two_bnd_pt_quad_touch_one_bnd_pt_quad;

  std::set<unsigned int> internal_tri, internal_quad;
  std::vector<bool> tri_bool, quad_bool;
  // constructor
  CategorizedSourceElements( GRegion *gr );
};


// This is a member function for the element map in ExtrudeParams.
// This allows insertion of a whole vector at once.
/*void ExtrudeParams::
ExtrusionElementMap::addExtrudedElemVector(MElement* source, std::vector<MElement*> *extrudedVector );
*/

// Insert all vertices on a region's source edge, including corners,
// into pos_src_edge set.
// Added 2010-01-09
void QuadToTriInsertSourceEdgeVertices(GRegion *gr, 
                              std::set<MVertex*, MVertexLessThanLexicographic> &pos_src_edge);

// Insert all vertices on a faces edges, including corners,
// into pos_edges set.
// Added 2010-01-18
void QuadToTriInsertFaceEdgeVertices(GFace *face, 
                              std::set<MVertex*, MVertexLessThanLexicographic> &pos_edges);

// Find centroid of vertices in vector v, return in vector
std::vector<double> QtFindVertsCentroid( std::vector<MVertex*> v );

// Add a new vertex at the centroid of a vector of vertices (this goes into a region
// Added 2010-02-06
MVertex* QtMakeCentroidVertex( std::vector<MVertex*> v, std::vector<MVertex*> *target, 
                             GEntity *entity, std::set<MVertex*, MVertexLessThanLexicographic> &pos );

// Finds the index of the lowest valued pointer in a vector of MVertex pointers
// Added 2011-03-10
int getIndexForLowestVertexPointer( std::vector<MVertex*> v );


// Given 4 verts on a face, find an existent diagonal, if any.
// Two possible methods:  If the 'index_guess' argument is the index of the correct triangle,
// finding it is simple. If not, have to do a complete pedantic search.
// Added 2010-01-26
std::pair<int, int> FindDiagonalEdgeIndices( std::vector<MVertex*> verts, GFace *face, bool lateral, 
                                             unsigned int index_guess = 0 );

// Get number of regions neighboring a face
int GetNeighborRegionsOfFace(GFace *face, std::vector<GRegion *> &neighbors);

// Tests whether a surface is a lateral of a region
// Added 12/09/10
int IsSurfaceALateralForRegion(GRegion *region, GFace *face);


// Function to determine if a face is a top surface for a region.  It returns 1
// if the face is COPIED_ENTITY with source = region's source and if face belongs to region. 
// Otherwise, return 0 (NOTE: ReplaceDuplicateSurfaces() can remove a top surface
// and replace it.  If that happens, this will return 0.  That is INTENDED for THIS function.
// Added 2010-12-13
int IsSurfaceATopForRegion(GRegion *region, GFace *face);


// Find the bottom root source surface of an extruded surface (source of source of source, etc.)
GFace* findRootSourceFaceForFace(GFace *face);


// Input is vert_bnd[], which describes some 2D element: vert_bnd[i] is true if 
// the ith vertex the element touches a lateral edge boundary of the surface the 
// element is in. 
// Output is touch_bnd[]: Each element of touch_bnd[] corresponds to an edge of 
// the element described by vert_bnd[].  Edge i of touch_bnd[] is formed by
// vertices i and (i+1)%element_size of the element. The value of touch_bnd[i] is non-zero 
// if that edge touches a boundary edge of the surface that the element is in.
// Added 2011-03-10
void fill_touch_bnd( int touch_bnd[], std::vector<bool> vert_bnd, int n_lat );


#endif
