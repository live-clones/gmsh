/**************************************************************************************************
QuadTriUtils.cpp

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

#include "QuadTriUtils.h"


// This is a member function for the element map in ExtrudeParams.
// This allows insertion of a whole vector at once.
/*void ExtrudeParams::
ExtrusionElementMap::addExtrudedElemVector(MElement* source, std::vector<MElement*> *extrudedVector )
{
  std::map<MElement*,std::vector<MElement*> >::iterator it = _extrudedElements.find(source);

  if(it != _extrudedElements.end()){
    it->second.reserve(it->second.size()+extrudedVector->size());
    it->second.insert(it->second.end(), extrudedVector->begin(), extrudedVector->end());
  }
  else {
    int totalNbElems = 0;
    for (int i = 0; i <_parent->mesh.NbLayer;i++)
      totalNbElems += _parent->mesh.NbElmLayer[i];
    unsigned int new_cap = totalNbElems > extrudedVector->size() ? totalNbElems : extrudedVector->size();
    // automatically creates source key in map (single argument 'insert' is also logarithmic too, just like this).
    std::vector<MElement*> *vec = &(_extrudedElements[source]);
    vec->reserve( new_cap );
    vec->insert( vec->end(), extrudedVector->begin(), extrudedVector->end());
  }

}*/

// Insert all vertices on a region's source edge, including corners,
// into pos_src_edge set.
// Added 2010-01-09
void QuadToTriInsertSourceEdgeVertices(GRegion *gr,
                              std::set<MVertex*, MVertexLessThanLexicographic> &pos_src_edge)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(!ep || !ep->mesh.ExtrudeMesh || ep->geo.Mode != EXTRUDED_ENTITY){
    Msg::Error("In QuadToTriInsertSourceEdgeVertices(), incomplete or no "
               "extrude info for region %d.", gr->tag() );
    return;
  }


  GFace *source_face = gr->model()->getFaceByTag( std::abs(ep->geo.Source) );

  std::list<GEdge*> edges = source_face->edges();
  std::list<GEdge*>::iterator ite = edges.begin();
  for(ite = edges.begin(); ite != edges.end(); ite++ ){
    pos_src_edge.insert( (*ite)->mesh_vertices.begin(), (*ite)->mesh_vertices.end() );
    pos_src_edge.insert( (*ite)->getBeginVertex()->mesh_vertices.begin(),
                          (*ite)->getBeginVertex()->mesh_vertices.end() );
    pos_src_edge.insert( (*ite)->getEndVertex()->mesh_vertices.begin(),
                          (*ite)->getEndVertex()->mesh_vertices.end() );
  }
}

// Insert all vertices on a faces edges, including corners,
// into pos_edges set.
// Added 2010-01-18
void QuadToTriInsertFaceEdgeVertices(GFace *face,
                              std::set<MVertex*, MVertexLessThanLexicographic> &pos_edges)
{


  std::list<GEdge*> edges = face->edges();
  std::list<GEdge*>::iterator ite = edges.begin();
  while(ite != edges.end()){
    pos_edges.insert((*ite)->mesh_vertices.begin(), (*ite)->mesh_vertices.end());
    pos_edges.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
               (*ite)->getBeginVertex()->mesh_vertices.end());
    pos_edges.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
               (*ite)->getEndVertex()->mesh_vertices.end());
    ++ite;
  }
}


// Constructor for the CategorizedSourceElements structure.
// See definition of CategorizedSourceElements in QuadTriUtils.h
// file for details.
CategorizedSourceElements::CategorizedSourceElements( GRegion *gr )
{
  region = (GRegion*)(NULL);
  source_face = (GFace*)(NULL);
  valid = false;

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In CategorizedSourceElements constructor, invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In CategorizedSourceElements constructor, invalid model for region "
               "%d.", gr->tag() );
    return;
  }

  // now find and verify the source face

  GFace *source_tmp = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !source_tmp  ){
    Msg::Error("In CategorizedSourceElements constructor, invalid source face for region "
               "%d.", gr->tag() );
    return;
  }

  // fill the data structure region and source face pointers
  valid = true;
  region = gr;
  source_face = source_tmp;

  // get source face boundary verts
  std::set<MVertex*, MVertexLessThanLexicographic> bnd_verts;
  QuadToTriInsertSourceEdgeVertices(gr, bnd_verts);


  unsigned int num_tri = source_face->triangles.size();
  unsigned int num_quad = source_face->quadrangles.size();

  // assign size to bool vectors
  tri_bool.assign(num_tri*4, false);
  quad_bool.assign(num_quad*5, false);


  // keep temporary set of one boundary point quad pivot indices
  std::set<MVertex*> one_pt_quad_pivots;

  // now classify the source elements in the vectors
  for( int t = 0; t < 2; t++ ){    // t = 0 loop over triangles, t=1 loop over quads

    int size = !t ? source_face->triangles.size() : source_face->quadrangles.size();
    for( int i = 0; i < size; i++ ){   // loop over total elements in current vector
      std::vector<MVertex*> elem_verts;
      MElement *elem;
      if( !t ){
        elem = source_face->triangles[i];
        elem->getVertices(elem_verts);
      }
      else{
        elem = source_face->quadrangles[i];
        elem->getVertices(elem_verts);
      }
      int elem_size = elem_verts.size();
      int bnd_count = 0;
      int bnd_vert = 0;
      // get the boundary vert bool values
      for( int k = 0; k < elem_size; k++ ){
        if( bnd_verts.find(elem_verts[k]) != bnd_verts.end() ){
          if( !t ) tri_bool[4*i+k+1] = true;
          else     quad_bool[5*i+k+1] = true;
          bnd_vert = k;
          bnd_count++;
        }
      }
      if( bnd_count ){
        if( !t ) tri_bool[4*i] = true;
        else     quad_bool[5*i] = true;
      }

      // Place element vector indices into appropriate set
      if( !bnd_count )
        (!t) ? internal_tri.insert(i) : internal_quad.insert(i);
      else if( bnd_count == 1 || bnd_count == 2 ||
              (bnd_count == 3 && t) )
        (!t) ? other_bnd_tri.insert(i) : other_bnd_quad.insert(i);
      else if( bnd_count == 3 && !t || bnd_count == 4 ){
        (!t) ? three_bnd_pt_tri.insert(i) : four_bnd_pt_quad.insert(i);
      }

      // if a one boundary point quad, record it in one_pt_quads set
      if( t && bnd_count == 1 ){
        one_pt_quad_pivots.insert(elem_verts[(bnd_vert+2)%4]);
      }
    }
  }

  // If there were one_bnd_pt_quads, go through the search for all elements
  //  touching at pivot index that are either internal or two bnd point quads.
  // This would take awhile if had to do this for every element (n^2). Fortunately,
  // such elements are NOT typical at all.
  if( !one_pt_quad_pivots.size() )
    return;

  std::set<std::pair<unsigned int, unsigned int> >::iterator it_quad;
  std::set<unsigned int>::iterator it_int;
  for( int s = 0; s < 2; s++ ){
    for( int q = 0; q < 2; q++ ){
      std::set<unsigned int> *int_elems;
      if( !s ){
        if( !q ) int_elems = &internal_tri;
        else  continue;
      }
      else
        int_elems = !q ? &internal_quad : &other_bnd_quad;

      for( it_int = (*int_elems).begin(); it_int != (*int_elems).end(); it_int++ ){
        std::vector<MVertex*> verts;
        if( !s )
          source_face->triangles[(*it_int)]->getVertices(verts);
        else
          source_face->quadrangles[(*it_int)]->getVertices(verts);

        // for t == s == 1 (other_bnd_quads), only retain those with two boundary verts
        if( s && q ){
          int bnd_count = 0;
          for(unsigned int k = 0; k < verts.size(); k++ ){
            if( quad_bool[5*(*it_int)+k+1] )
              bnd_count++;
          }
          if( bnd_count != 2 )
            continue;
        }

        // Don't eliminate the inner for loop with std::find because
        // or reverse the order of the two loops.  If an element touches multiple pivots,
        // always want to find the FIRST one in the pivots set so that there is precedence
        // and no conflicts at mesh time.  Looping through the element vertices as the outer loop
        // will sometimes choose the wrong pivot.
        std::set<MVertex*>::iterator it_piv;
        bool found = false;
        for( it_piv = one_pt_quad_pivots.begin(); it_piv != one_pt_quad_pivots.end(); it_piv++ ){
          for(unsigned int t = 0; t < verts.size(); t++ ){
            if( (*it_piv) == verts[t] ) {
              found = true;
              if( !s ){
                internal_tri_touch_one_bnd_pt_quad.insert(*it_int);
                tri_bool[4*(*it_int)] = true;
                tri_bool[4*(*it_int)+t+1] = true;
              }
              else{
                if( !q ){
                  internal_quad_touch_one_bnd_pt_quad.insert(*it_int);
                  quad_bool[5*(*it_int)] = true;
                  quad_bool[5*(*it_int)+t+1] = true;
                }
                else
                  two_bnd_pt_quad_touch_one_bnd_pt_quad.insert(*it_int);
              }
              break;
            }
          }
          if( found ) break;
        }
      }
    }
  }

} // end of CategorizedSourceElements::CategorizedSourceElements( GRegion *gr )


// Find centroid of vertices in vector v, return in vector
std::vector<double> QtFindVertsCentroid( std::vector<MVertex*> v )
{

  std::vector<double> v_return;
  const int v_size = v.size();

  if( v_size != 6 && v_size != 8 && v_size != 3 && v_size != 4 ){
    Msg::Error("In QtFindVertsCentroid(), number of vertices is not 3, 4, 6, or 8.");
    return v_return;
  }

  // for 3D
  int n_lat_tmp = 10;
  if( v_size==6 )
    n_lat_tmp = 3;
  else if( v_size==8 )
    n_lat_tmp = 4;

  const int n_lat = n_lat_tmp;

  double x = 0.0, y = 0.0, z = 0.0;
  int v_count = 0;
  for( int p = 0; p < v_size; p++){
    // skip degenerate vertices - 3D
    if( ( v_size == 6 || v_size == 8 ) && p > n_lat-1 && v[p] == v[p-n_lat] )
      continue;
    // skip degenerate vertices - 2D
    if( ( v_size == 3 || v_size == 4 ) && v[p] == v[(p+v_size-1)%v_size]  )
      continue;
    v_count++;
    x += v[p]->x(); y += v[p]->y(); z += v[p]->z();
  }
  x /= v_count; y /= v_count; z /= v_count;


  v_return.push_back(x);
  v_return.push_back(y);
  v_return.push_back(z);

  return v_return;

}

// Add a new vertex at the centroid of a vector of vertices (this goes into a region
// Added 2010-02-06
MVertex* QtMakeCentroidVertex( std::vector<MVertex*> v, std::vector<MVertex*> *target,
                             GEntity *entity, std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  int v_size = v.size();
  if( v_size != 6 && v_size != 8 && v_size != 3 && v_size != 4){
    Msg::Error("In makeCentroidVertex(), number of vertices does not equal 3, 4, 6, or 8.");
    return (MVertex*)(NULL);
  }

  // find the centroid of vertices
  std::vector<double> centroid = QtFindVertsCentroid(v);
  double x, y, z;
  if( centroid.size() ){
    x = centroid[0];
    y = centroid[1];
    z = centroid[2];
  }

  // make new vertex
  MVertex tmp(x, y, z, 0, -1);
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp = pos.find(&tmp);
  MVertex *v_int;
  // simple check if it exists
  if(itp == pos.end()){
    v_int = new MVertex(x, y, z, entity);
    target->push_back(v_int);
    pos.insert(v_int);
  }
  else
    v_int = (*itp);

  return (v_int);

}


// Finds the index of the lowest valued pointer in a vector of MVertex pointers
// Added 2011-03-10
int getIndexForLowestVertexPointer( std::vector<MVertex*> v )
{

  int ind_low = 0;
  int v_size = v.size();
  for( int i = 1; i < v_size; i++ ){
    if( v[i] < v[ind_low] )
      ind_low = i;
  }
  return ind_low;
}


// Given 4 verts on a face, find an existent diagonal, if any.
// Two possible methods:  If the 'index_guess' argument is the index of the correct triangle,
// finding it is simple. If not, have to do a complete pedantic search.
// Added 2010-01-26
std::pair<int, int> FindDiagonalEdgeIndices( std::vector<MVertex*> verts,
                                                           GFace *face, bool lateral,
                                                           unsigned int index_guess)
{
  if( verts.size() != 4 ){
    Msg::Error("FindDiagonalEdgeIndices(), size of verts array not equal 4.");
    return std::pair<int,int>(0,0);
  }
  if( !lateral ){
    MVertex *tmp = verts[2];  verts[2] = verts[3]; verts[3] = tmp;
  }

  int s_max = face->triangles.size();
  MElement *elem_tmp = NULL;
  bool wrong_guess = false;
  for( int s = 0; s < s_max; s++ ){
    if( s != 0 && !wrong_guess  ){
      wrong_guess = true;
      Msg::Error("FindDiagonalEdgeIndices() encountered unexpected surface configuration.");
    }
    int v_count0 = 0,  v_count1 = 0;
    elem_tmp = (MElement*)(face->triangles[(s+index_guess)%s_max]);
    int num_verts = elem_tmp->getNumVertices();
    for( int g = 0; g < num_verts; g++ ){
      if( elem_tmp->getVertex(g) == verts[0] ||
          elem_tmp->getVertex(g) == verts[3] )
        v_count0++;
      else if( elem_tmp->getVertex(g) == verts[1] ||
               elem_tmp->getVertex(g) == verts[2] )
        v_count1++;
      if( lateral ){
        if( v_count0 > 1 )
          return std::pair<int,int> ( std::min(0,3), std::max(0,3) );
        else if( v_count1 > 1 )
          return std::pair<int,int> ( std::min(1,2), std::max(1,2) );
      }
      else{
        if( v_count0 > 1 )
          return std::pair<int,int> ( std::min(0,2), std::max(0,2) );
        else if( v_count1 > 1 )
          return std::pair<int,int> ( std::min(1,3), std::max(1,3) );
      }
    }
  }

  Msg::Error("In FindDiagonalEdge(), could not "
             "find a diagonal on surface %d.",
             face->tag() );
  return std::pair<int,int>(0,0);

}


// Get number of regions neighboring a face
int GetNeighborRegionsOfFace(GFace *face, std::vector<GRegion *> &neighbors)
{
  GModel *model = face->model();

  if(!model){
    Msg::Error("GetNeighborRegionsOfFace(), face %d has no parent model.",
               face->tag() );
    return 0;
  }

  // first see if the face has the list of regions
  int regions_count = face->numRegions();
  if( regions_count > 0 ){
    neighbors.push_back(face->getRegion(0));
    if( regions_count > 1 )
      neighbors.push_back(face->getRegion(1));
    return regions_count;
  }
  else
    regions_count = 0;

  // pedantic search
  std::vector<GRegion *> all_regions;
  std::set<GRegion *, GEntityLessThan>::iterator itreg;
  for( itreg = model->firstRegion(); itreg != model->lastRegion(); itreg++ ){
    std::list<GFace *> reg_faces = (*itreg)->faces();
    if( std::find( reg_faces.begin(), reg_faces.end(), face ) !=
        reg_faces.end() ){
      regions_count++;
      face->addRegion( (*itreg) );
      neighbors.push_back( (*itreg) );
      if( regions_count >= 2 ) return regions_count;
    }
  }

  return regions_count;

}


// Tests whether a surface is a lateral of a region
// Trevor Strickler 12/09/10
int IsSurfaceALateralForRegion(GRegion *region, GFace *face)
{

  // NOTE: don't necessarily require the face to be extruded! just in the position
  //  of lateral is all we care about here.
  ExtrudeParams *ep = face->meshAttributes.extrude;
  ExtrudeParams *reg_ep = region->meshAttributes.extrude;

  // if there is no REGION extrude information, skip the rest
  if( !reg_ep )
    return 0;

  GModel *model = face->model();
  GEdge *face_source = NULL;
  if( ep && ep->geo.Mode == EXTRUDED_ENTITY)
    face_source = model->getEdgeByTag(std::abs(ep->geo.Source));

  GFace *reg_source = model->getFaceByTag( std::abs(reg_ep->geo.Source) );

  if(!reg_source){
    Msg::Error("In IsSurfaceALateralForRegion(), unknown source surface number %d.",
                region->meshAttributes.extrude->geo.Source);
    return 0;
  }

  // if face is the region's source, return 0
  if( reg_source == face )
    return 0;

  // of course, the face has to belong to the region!
  std::list<GFace *> region_faces = std::list<GFace *>( region->faces() );
  if( std::find( region_faces.begin(), region_faces.end(), face) ==
      region_faces.end() )
    return 0;


  // if this face is a COPIED_ENTITY with source = region source face, this is the top.  Exit.
  if( ep && ep->geo.Mode == COPIED_ENTITY &&
      reg_source == model->getFaceByTag(std::abs(ep->geo.Source)))
    return 0;

 //
 // Now to prove the face is lateral, it must not be the "top" face. If
 // this face has replaced the region's original lateral through
 // ReplaceDuplicateSurfaces(), then the previous test for "topness" won't
 // have signaled an error. However, this face COULD still be in the  top position.
 // So, check that the lateral shares AN edge (not the source edge, necessarily) with the
 // region's source face.
 // THEN, IF they share an edge, extrude all of the source GVertex positions and
 // see if they are found in this face.  IF so, then it is a top and not a lateral.

  std::list<GEdge*> region_source_edges = reg_source->edges();
  std::list<GEdge*> face_edges = face->edges();
  std::list<GEdge*>::iterator ite = face_edges.begin();

  bool edge_found = false;
  int common_count = 0;
  GEdge *common_edge = NULL;
  for( ite = region_source_edges.begin(); ite != region_source_edges.end(); ite++){
    if( std::find( face_edges.begin(), face_edges.end(), (*ite) )
         != face_edges.end() ){
      edge_found = true;
      common_edge = (*ite);
      common_count++;
      if( common_count > 1 )
        return 0;
    }
  }

  if( !edge_found )
    return 0;
  else if( reg_ep->geo.Type == ROTATE ||
           reg_ep->geo.Type == TRANSLATE_ROTATE ){
    // create lists of GVertex object for source face and present face
    std::list<GVertex*> face_v, source_v;
    face_v = face->vertices();
    source_v = reg_source->vertices();
    std::list<GVertex*>::iterator itvs;
    double tol = 1.00e-12;
    double eps = fabs( tol * CTX::instance()->lc );
    unsigned int j_top, k_top;
    j_top = reg_ep->mesh.NbLayer-1;
    k_top = reg_ep->mesh.NbElmLayer[j_top];
    bool found_all = true;
    for( itvs = source_v.begin(); itvs != source_v.end(); itvs++ ){
      double x1 = (*itvs)->x(), y1 = (*itvs)->y(), z1 = (*itvs)->z();
      reg_ep->Extrude( j_top, k_top, x1, y1, z1 );
      std::list<GVertex*>::iterator itvf;
      bool found_one = false;
      for( itvf = face_v.begin(); itvf != face_v.end(); itvf++ ){
        double x2 = (*itvf)->x(), y2 = (*itvf)->y(), z2 = (*itvf)->z();
        if( fabs(x2-x1) <= eps && fabs(y2-y1) <= eps && fabs(z2-z1) <= eps ){
          found_one = true;
          break;
        }
      }
      if( !found_one ){
        found_all = false;
        break;
      }
    }
    // if surface is certainly the top
    if( found_all ){
      return 0;
    }
  }

  return 1; // if code executes here, passed all tests
}


// Function to determine if a face is a top surface for a region.  It returns 1
// if the face is COPIED_ENTITY with source = region's source and if face belongs to region.
// Otherwise, return 0 (NOTE: ReplaceDuplicateSurfaces() can remove a top surface
// and replace it.  If that happens, this will return 0.  That is INTENDED for THIS function.
// Added 2010-12-13
int IsSurfaceATopForRegion(GRegion *region, GFace *face)
{
  // first make sure there is extrude info
  if( !region->meshAttributes.extrude || !face->meshAttributes.extrude )
    return 0;

  ExtrudeParams *reg_ep = region->meshAttributes.extrude;
  ExtrudeParams *face_ep = face->meshAttributes.extrude;
  GModel *model = face->model();
  GFace *reg_source = model->getFaceByTag(
                      std::abs(reg_ep->geo.Source));

  if( reg_ep->geo.Mode != EXTRUDED_ENTITY || !reg_source)
    return 0;

  if( face_ep->geo.Mode != COPIED_ENTITY || face == reg_source )
    return 0;

  GFace *face_source = model->getFaceByTag(
                       std::abs(face_ep->geo.Source));

  // whether face is a copy of region's source
  if( !reg_source || !face_source || reg_source != face_source )
    return 0;

  // of course, the face has to belong to the region!
  std::list<GFace *> region_faces = std::list<GFace *>( region->faces() );
  if( std::find( region_faces.begin(), region_faces.end(), face) ==
      region_faces.end() )
    return 0;

  // if make it this far, return 1
  return 1;
}


// Find the bottom root source surface of an extruded surface (source of source of source, etc.)
GFace* findRootSourceFaceForFace(GFace *face)
{

  ExtrudeParams *ep = face->meshAttributes.extrude;
  if( !(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY ) )
    return face;

  GFace *source_face;
  GModel *model = face->model();
  int max_iter = model->getNumFaces();
  int iter_counter = 0;
  ExtrudeParams *ep_iter = ep;
  while( iter_counter <= max_iter ){
    iter_counter++;
    source_face = model->getFaceByTag( std::abs(ep_iter->geo.Source) );
    if( !source_face ){
      Msg::Error("findRootSourceFaceForFace() could not find valid surface for tag %d.", ep->geo.Source );
      return (GFace*)(NULL);
    }
    ep_iter = source_face->meshAttributes.extrude;
    if( !( ep_iter && ep_iter->mesh.ExtrudeMesh && ep_iter->geo.Mode == COPIED_ENTITY ) )
      return source_face;
  }

  Msg::Error("findRootSourceFaceForFace() failed to find root source.");
  return (GFace*)(NULL);

}


// Input is vert_bnd[], which describes some 2D element: vert_bnd[i] is true if
// the ith vertex the element touches a lateral edge boundary of the surface the
// element is in.
// Output is touch_bnd[]: Each element of touch_bnd[] corresponds to an edge of
// the element described by vert_bnd[].  Edge i of touch_bnd[] is formed by
// vertices i and (i+1)%element_size of the element. The value of touch_bnd[i] is non-zero
// if that edge touches a boundary edge of the surface that the element is in.
// Added 2011-03-10
void fill_touch_bnd( int touch_bnd[], std::vector<bool> vert_bnd, int n_lat )
{
   for(int i = 0; i < n_lat; i++ )
    touch_bnd[i] = 0;

  for(int i = 0; i < n_lat; i++ ){
    if( vert_bnd[i] ){
      touch_bnd[i] = 1;
      touch_bnd[(i+n_lat-1)%n_lat] = 1;
    }
  }
}




