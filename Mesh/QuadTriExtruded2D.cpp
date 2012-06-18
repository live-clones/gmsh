/**************************************************************************************************
QuadTriExtruded2D.cpp

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

#include "QuadTriExtruded2D.h"

// By Geuzaine, Remacle...
static void addTriangle(MVertex* v1, MVertex* v2, MVertex* v3,
                        GFace *to, MElement* source)
{
  MTriangle* newTri = new MTriangle(v1, v2, v3);
  to->triangles.push_back(newTri);
}

// The function that tests whether a 2D surface is a lateral of a valid QuadToTri
// region and whether there are conflicts. If surface is not part of valid QuadToTri region
// or if there are QuadToTri conflicts, return 0.  Note that RemoveDuplicateSurfaces()
// makes this DIFFICULT. Also, the tri_quad_flag determins whether the surface
// should be meshed with triangles or quadrangles:
// tri_quad_values: 0 = no override, 1 = mesh as quads, 2 = mesh as triangles.
// Added 2010-12-09.
int IsValidQuadToTriLateral(GFace *face, int *tri_quad_flag, bool *detectQuadToTriLateral )
{
  (*tri_quad_flag) = 0;
  (*detectQuadToTriLateral) = false;

  GModel *model = face->model();


  ExtrudeParams *ep = face->meshAttributes.extrude;

  if( !ep || !ep->mesh.ExtrudeMesh || !ep->geo.Mode == EXTRUDED_ENTITY ){
    Msg::Error("In IsValidQuadToTriLateral(), face %d is not a structured extrusion.",
               face->tag() );
    return 0;
  }

  GEdge *face_source = model->getEdgeByTag( std::abs( ep->geo.Source ) );
  if( !face_source ){
    Msg::Error("In IsValidQuadToTriLateral(), face %d has no source edge.",
               face->tag() );
  }

  // It seems the member pointers to neighboring regions for extruded lateral faces are not set.
  // For now, have to loop through
  // ALL the regions to see if the presently considered face belongs to the region and if
  // any neighboring region is QUADTRI.
  // The following loop will find all the regions that the face bounds, and determine
  // whether the face is a lateral of the region (including whether the region is even extruded).
  // After that information is determined, function can test for QuadToTri neighbor conflicts.

  std::vector<GRegion *> lateral_regions;
  std::vector<GRegion *> adjacent_regions;
  int numRegions = 0;
  int numLateralRegions = 0;

  numRegions = GetNeighborRegionsOfFace(face, adjacent_regions);
  for( int i_reg = 0; i_reg < numRegions; i_reg++ ){
    GRegion *region = adjacent_regions[i_reg];

    // is region in the current model's region's or is it deleted?
    if( !FindVolume( ( region->tag() ) ) )
      continue;

    // is the region mesh extruded?
    if( !region->meshAttributes.extrude ||
        ( region->meshAttributes.extrude &&
          !region->meshAttributes.extrude->mesh.ExtrudeMesh ) )
      continue;
    if( region->meshAttributes.extrude->geo.Mode != EXTRUDED_ENTITY )
      continue;

    // Test whether the face is a lateral
    if( IsSurfaceALateralForRegion(region, face) ){
      lateral_regions.push_back(region);
      numLateralRegions++;
      if( region->meshAttributes.extrude->mesh.QuadToTri )
        (*detectQuadToTriLateral) = true;
    }

  }

  // MAIN test of whether this is even a quadToTri extrusion lateral
  // the only return 0 path that is NOT an error
  if( !(*detectQuadToTriLateral) )
    return 0;

  // now will start conflict checks

  if(numRegions > 2){
    Msg::Error("In IsValidQuadToTriLateral(), too many regions adjacent to surface %d.",
               face->tag() );
    return 0;
  }

  bool detect_conflict = false;


  // Set the tri_quad_flag that lets extrudeMesh override ep->Recombine;
  // tri_quad_values: 0 = no override, 1 = mesh as quads, 2 = mesh as triangles.

  // if this face is a free surface:
  if( adjacent_regions.size() == 1 ){
    if( lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_SNGL_1_RECOMB ||
        lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_DBL_1_RECOMB )
      (*tri_quad_flag) = 1;
    else if( lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_SNGL_1 ||
             lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_DBL_1 )
      (*tri_quad_flag) = 2;
    else
      (*tri_quad_flag) = 0;
  }
  else if( adjacent_regions.size() > 1 ){
    GRegion *adj_region = NULL;
    ExtrudeParams *adj_ep = NULL;
    if( lateral_regions[0] == adjacent_regions[0] )
      adj_region = adjacent_regions[1];
    else
      adj_region = adjacent_regions[0];
    adj_ep = adj_region->meshAttributes.extrude;

    // if Neighbor is Transfinite, go with the default, non-QuadTri recombine for this surface
    if( adj_region && adj_region->meshAttributes.Method == MESH_TRANSFINITE )
       (*tri_quad_flag) = 0;
    // if a neighbor
    // has no extrusion structure,
    // don't even consider QuadToTri Recomb on this face.
    else if( adj_region && !(adj_ep && adj_ep->mesh.ExtrudeMesh) )
      (*tri_quad_flag) = 2;
    // This face is the source face of a second
    // neighboring extrusion.
    else if( adj_ep && adj_ep->mesh.ExtrudeMesh &&
             model->getFaceByTag( std::abs( adj_ep->geo.Source ) ) == face ){
      if( lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_SNGL_1_RECOMB ||
          lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_DBL_1_RECOMB )
        (*tri_quad_flag) = 1;
      else if( lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_SNGL_1 ||
               lateral_regions[0]->meshAttributes.extrude->mesh.QuadToTri == QUADTRI_DBL_1 )
        (*tri_quad_flag) = 2;
      else
        (*tri_quad_flag) = 0;
    }
    // if both neighbors are structured but none of the previous apply:
    else if( adj_ep && adj_ep->mesh.ExtrudeMesh ){
      if( (adj_ep && !adj_ep->mesh.QuadToTri && adj_ep->mesh.Recombine) ||
          (ep && !ep->mesh.QuadToTri && ep->mesh.Recombine) )
        (*tri_quad_flag) = 1;
      else if( (adj_ep && !adj_ep->mesh.QuadToTri && !adj_ep->mesh.Recombine) ||
               (ep && !ep->mesh.QuadToTri && !ep->mesh.Recombine) )
        (*tri_quad_flag) = 2;
      // if both are quadToTri and either are quadToTri recomblaterals, recombine
      else if( ep->mesh.QuadToTri == QUADTRI_SNGL_1_RECOMB ||
               (adj_ep && adj_ep->mesh.QuadToTri == QUADTRI_SNGL_1_RECOMB) )
        (*tri_quad_flag) = 1;
      else if( ep->mesh.QuadToTri == QUADTRI_DBL_1_RECOMB ||
               (adj_ep && adj_ep->mesh.QuadToTri == QUADTRI_DBL_1_RECOMB) )
        (*tri_quad_flag) = 1;
      else
        (*tri_quad_flag) = 2;
    }
    // any other adjacent surface, just default to the QuadToTri region's non-QuadToTri
    // default recombination method.  Any mistakes at this point are not this feature's.
    else
      (*tri_quad_flag) = 0;
  }
  // if this executes, there's a mistake here :
  else{
   detect_conflict = true;
   (*tri_quad_flag) = 0;
  }

  if( detect_conflict )
    return 0;
  else
    return 1;

}



// The function that tests whether a surface is a QuadToTri top surface and whether
// there are conflicts. If surface is not a top for a valid QuadToTri region or if
// there are QuadToTri conflicts, return 0.  Note that RemoveDuplicateSurfaces()
// makes this DIFFICULT. Also, the type of QuadToTri interface is placed into the
// pointer argument quadToTri. .
// Added 2010-12-09.
int IsValidQuadToTriTop(GFace *face, int *quadToTri, bool *detectQuadToTriTop)
{
  (*quadToTri) = NO_QUADTRI;
  (*detectQuadToTriTop) = false;

  GModel *model = face->model();

  // It seems the member pointers to neighboring regions for extruded top faces are not set.
  // For now, have to loop through
  // ALL the regions to see if the presently considered face belongs to the region.
  // The following loop will find all the regions that the face bounds, and determine
  // whether the face is a top face of the region (including whether the region is even extruded).
  // After that information is determined, function can test for QuadToTri neighbor conflicts.

  std::vector<GRegion *> top_regions;
  std::vector<GRegion *> adjacent_regions;
  std::vector<GRegion *> all_regions;
  int numRegions = 0;
  int numTopRegions = 0;

  std::set<GRegion *, GEntityLessThan>::iterator itreg;
  for( itreg = model->firstRegion(); itreg != model->lastRegion(); itreg++ )
    all_regions.push_back( (*itreg) );

  for(unsigned int i_reg = 0; i_reg < all_regions.size(); i_reg++ ){

    // save time
    if( numRegions >= 2 )
      break;

    GRegion *region = all_regions[i_reg];

    // is region in the current model's regions or is it deleted?
    if( !FindVolume( ( region->tag() ) ) )
      continue;

    // does face belong to region?
    std::list<GFace *> region_faces = std::list<GFace *>( region->faces() );
    if( std::find( region_faces.begin(), region_faces.end(), face ) !=
          region_faces.end() ){
      adjacent_regions.push_back(region);
      numRegions++;
    }
    else
      continue;

    // is region extruded?
    if( !region->meshAttributes.extrude )
      continue;
    if( region->meshAttributes.extrude->geo.Mode != EXTRUDED_ENTITY )
      continue;

    // Test whether the face is a top for the region
    if( IsSurfaceATopForRegion(region, face) ){
      top_regions.push_back(region);
      numTopRegions++;
      if( region->meshAttributes.extrude->mesh.QuadToTri )
        (*detectQuadToTriTop) = true;
    }

  }

  // MAIN test of whether this is even a quadToTri extrusion lateral
  // the only return 0 path that is NOT an error
  if( !(*detectQuadToTriTop) )
    return 0;



  ExtrudeParams *ep = face->meshAttributes.extrude;

  if(!ep){
    Msg::Error("In IsValidQuadToTriTop(), no extrude info for surface %d.",
               face->tag() );
    return 0;
  }

  if( ep->geo.Mode != COPIED_ENTITY){
    Msg::Error("In IsValidQuadToTriTop(), surface %d is not copied from source.",
               face->tag() );
    return 0;
  }

  if( ep->mesh.QuadToTri == 0){
    Msg::Error("In IsValidQuadToTriTop(), surface %d was determined to be the top surface "
               "for a QuadToTri extrusion, but does not have QuadToTri parameters set within itself.",
               face->tag() );
    return 0;
  }

  GFace *face_source = model->getFaceByTag(std::abs(ep->geo.Source));
  if(!face_source){
    Msg::Error("In IsValidQuadToTriTop(), unknown source face number %d.",
                 face->meshAttributes.extrude->geo.Source);
    return 0;
  }

  if(numRegions > 2){
    Msg::Error("In IsValidQuadToTriTop(), too many regions adjacent to surface %d.",
               face->tag() );
    return 0;
  }


  if( top_regions.size() ){
    (*quadToTri) = top_regions[0]->meshAttributes.extrude->mesh.QuadToTri;
  }

  // Make sure that face is the top for only one region. if not, then there will likely
  // be conflicts (two regions extruded into each other).
  if( top_regions.size() > 1 ){
    Msg::Error("In IsValidQuadToTriTop(), QuadToTri top surface %d identified as top "
               "surface for more than one region. Likely conflict.",  face->tag() );
    return 0;
  }

  return 1;
}


// this function specifically meshes a quadToTri top in an unstructured way
// return 1 if success, return 0 if failed.
// Added 2010-12-20
static int MeshQuadToTriTopUnstructured(GFace *from, GFace *to,
                                   std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{

  // if the source is all triangles, then just return 1.
  if( from->triangles.size() && !from->quadrangles.size() )
    return 1;

  if( !to->meshAttributes.extrude || !to->meshAttributes.extrude->mesh.QuadToTri  )
    return 0;


  // in weird case of NO quads and NO tri
  if( !from->triangles.size() && !from->quadrangles.size() )
    return 0;


  // make set of source edge vertices
  std::set<MVertex*, MVertexLessThanLexicographic> pos_src_edge;
  QuadToTriInsertFaceEdgeVertices(from, pos_src_edge);

  // Loop through all the quads and make the triangles with diagonals running
  // in a selected direction.

  to->triangles.reserve(to->triangles.size()+from->quadrangles.size()*2);
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;

  for(unsigned int i = 0; i < from->quadrangles.size(); i++){
    std::vector<MVertex*> verts;
    for(int j = 0; j < from->quadrangles[i]->getNumVertices(); j++){
      MVertex *v = from->quadrangles[i]->getVertex(j);
      MVertex tmp(v->x(), v->y(), v->z(), 0, -1);
      ExtrudeParams *ep = to->meshAttributes.extrude;
      ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
                  tmp.x(), tmp.y(), tmp.z());
      itp = pos.find(&tmp);
      if(itp == pos.end()){ // FIXME: workaround
        Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
        itp = tmp.linearSearch(pos);
      }
      if(itp == pos.end()) {
        Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g) in surface %d",
            tmp.x(), tmp.y(), tmp.z(), to->tag());
        to->triangles.reserve(to->triangles.size()+1);
        return 0;
      }
      verts.push_back(*itp);
    }


    if( verts.size() != 4 ){
      Msg::Error("During mesh of QuadToTri surface %d, %d vertices found "
                 "in quad of source surface %d.", to->tag(), verts.size(),
                 from->tag() );
      return 0;
    }

    // make the element
    MElement *element = from->quadrangles[i];

    // draw other diagonals to minimize difference in average edge length with diagonal length, in quadrature

    double mag_sq_ave = 0.0;
    for( int p = 0; p < 4; p++ ){
      int d_leg = verts[p]->distance(verts[(p+1)%4]);
      mag_sq_ave += d_leg*d_leg;
    }
    mag_sq_ave /= 4;

    double d1 = verts[0]->distance(verts[2]);
    double d2 = verts[1]->distance(verts[3]);

    if(fabs(d1*d1-mag_sq_ave) <= fabs(d2*d2-mag_sq_ave) ){
      addTriangle(verts[0],verts[1],verts[2],to,element);
      addTriangle(verts[0],verts[2],verts[3],to,element);
    }
    else{
      addTriangle(verts[1],verts[2],verts[3],to,element);
      addTriangle(verts[1],verts[3],verts[0],to,element);
    }
  }

  return 1;
}


// This function meshes the top surface of a QuadToTri extrusion.  It returns 0 if it is given a
// non-quadToTri extrusion or if it fails.
// Args:
//       'GFace *to' is the top surface to mesh, 'from' is the source surface, 'pos' is a std::set
//       of vertex positions for the top surface.
int MeshQuadToTriTopSurface( GFace *from, GFace *to, std::set<MVertex*,
                             MVertexLessThanLexicographic> &pos)
{
  if( !to->meshAttributes.extrude || !to->meshAttributes.extrude->mesh.QuadToTri  )
    return 0;

  // if the source is all triangles, then just let this function is not needed. Return 1.
  if( from->triangles.size() && !from->quadrangles.size() )
    return 1;

  // in weird case of NO quads and NO tri
  if( !from->triangles.size() && !from->quadrangles.size() )
    return 0;

  ExtrudeParams *ep = to->meshAttributes.extrude;
  if( !ep || !ep->mesh.ExtrudeMesh || !ep->geo.Mode == COPIED_ENTITY ){
    Msg::Error("In MeshQuadToTriTopSurface(), incomplete or no "
               "extrude information for top face %d.", to->tag() );
    return 0;
  }

  // number of extrusion layers
  int num_layers = 0;
  for( int p = 0; p < ep->mesh.NbLayer; p++ )
    num_layers += ep->mesh.NbElmLayer[p];

  // is this a valid double layer extrusion?
  bool is_dbl = false;
  if( num_layers >= 2 && ( ep->mesh.QuadToTri == QUADTRI_DBL_1 || ep->mesh.QuadToTri == QUADTRI_DBL_1_RECOMB ) )
    is_dbl = true;

  // IF this is a SINGLE layer quadToTri, mesh the surfaces according to this modified
  // least point value method: if a 3 boundary point quad, draw diagonals from middle corner toward
  // interior.  If a a 2- or 1- point boundary quad, draw toward lowest pointer number NOT on boundary.
  // All interior quad, draw diagonal to vertex with lowest pointer number.

  if( !is_dbl ){

    std::set<MVertex*, MVertexLessThanLexicographic> pos_src_edge;
    QuadToTriInsertFaceEdgeVertices(from, pos_src_edge);
    std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;

    // loop through each element source quadrangle and extrude
    for(unsigned int i = 0; i < from->quadrangles.size(); i++){
      std::vector<MVertex*> verts;
      for(int j = 0; j < from->quadrangles[i]->getNumVertices(); j++){
        MVertex *v = from->quadrangles[i]->getVertex(j);
        MVertex tmp(v->x(), v->y(), v->z(), 0, -1);
        ExtrudeParams *ep = to->meshAttributes.extrude;
        ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
                    tmp.x(), tmp.y(), tmp.z());
        itp = pos.find(&tmp);
        if(itp == pos.end()){ // FIXME: workaround
          Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
          itp = tmp.linearSearch(pos);
        }
        if(itp == pos.end()) {
          Msg::Error("In MeshQuadToTriTopSurface(), Could not find "
                     "extruded vertex (%.16g, %.16g, %.16g) in surface %d",
              tmp.x(), tmp.y(), tmp.z(), to->tag());
          to->triangles.reserve(to->triangles.size()+1);
          return 0;
        }
        verts.push_back(*itp);
      }


      if( verts.size() != 4 ){
        Msg::Error("During mesh of QuadToTri surface %d, %d vertices found "
                   "in quad of source surface %d.", to->tag(), verts.size(),
                   from->tag() );
        return 0;
      }

      // make the element
      MElement *element = from->quadrangles[i];

      // count vertices that are on a boundary edge
      int edge_verts_count = 0;
      int skip_index = 0;
      int bnd_indices[4];
      for( int p = 0; p < element->getNumVertices(); p++ ){
        if( pos_src_edge.find( element->getVertex(p) ) != pos_src_edge.end() ){
          edge_verts_count++;
          bnd_indices[p] = 1;
        }
        else{
          skip_index = p;
          bnd_indices[p] = 0;
        }
      }

      // Apply modified lowest vertex pointer diagonalization
      int low_index = -1;
      if( edge_verts_count == 3 || edge_verts_count == 2 || edge_verts_count == 1 ){
        for( int p = 0; p < 4; p++ ){
          if( !bnd_indices[p] && verts[p] != element->getVertex(p) ){
            if( low_index < 0 )
              low_index = p;
            else if( verts[p] < verts[low_index] )
              low_index = p;
          }
        }
        if( low_index < 0 ) // what if they are all degenerate?  Avoid the out-of-bounds error.
          low_index = 0;
      }

      // lowest possible vertex pointer, regardless of if on edge or not
      else if( edge_verts_count == 4 || edge_verts_count == 0 )
        low_index = getIndexForLowestVertexPointer(verts);

      addTriangle( verts[low_index],verts[(low_index+1)%verts.size()],
                   verts[(low_index+2)%verts.size()],to,element);
      addTriangle( verts[low_index],verts[(low_index+2)%verts.size()],
                   verts[(low_index+3)%verts.size()],to,element);
    }
    return 1;
  }


  // AFTER THIS POINT IN FUNCTION, CODE IS ALL FOR DOUBLE LAYER EXTRUSIONS (Less restrictive).

  // if double layer and unstructured, can try to make the top mesh a little neater
  GFace *root_source = findRootSourceFaceForFace( from );
  ExtrudeParams *ep_src = root_source->meshAttributes.extrude;
  bool struct_root = false;
  if( root_source &&
      ( ep_src && ep_src->mesh.ExtrudeMesh && ep_src->geo.Mode == EXTRUDED_ENTITY ||
        root_source->meshAttributes.Method == MESH_TRANSFINITE ) )
    struct_root = true;

  if( !struct_root && MeshQuadToTriTopUnstructured(from, to, pos) )
    return 1;

  // And top surface for a structured double layer can be meshed quite easily
  else{
    std::set<MVertex *, MVertexLessThanLexicographic >::iterator itp;
    // loop through each element source quadrangle and extrude
    for(unsigned int i = 0; i < from->quadrangles.size(); i++){
      std::vector<MVertex*> verts;
      for(int j = 0; j < from->quadrangles[i]->getNumVertices(); j++){
        MVertex *v = from->quadrangles[i]->getVertex(j);
        MVertex tmp(v->x(), v->y(), v->z(), 0, -1);
        ExtrudeParams *ep = to->meshAttributes.extrude;
        ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
                    tmp.x(), tmp.y(), tmp.z());
        itp = pos.find(&tmp);
        if(itp == pos.end()){ // FIXME: workaround
          Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
          itp = tmp.linearSearch(pos);
        }
        if(itp == pos.end()) {
          Msg::Error("In MeshQuadToTriTopSurface(), Could not find "
                     "extruded vertex (%.16g, %.16g, %.16g) in surface %d",
              tmp.x(), tmp.y(), tmp.z(), to->tag());
          to->triangles.reserve(to->triangles.size()+1);
          return 0;
        }
        verts.push_back(*itp);
      }


      if( verts.size() != 4 ){
        Msg::Error("During mesh of QuadToTri surface %d, %d vertices found "
                   "in quad of source surface %d.", to->tag(), verts.size(),
                   from->tag() );
        return 0;
      }

      // make the element
      MElement *element = from->quadrangles[i];
      addTriangle( verts[0],verts[2], verts[3],to,element);
      addTriangle( verts[0],verts[1], verts[2],to,element);
    }
    return 1;
  }

  return 0;

}
