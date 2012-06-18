/**************************************************************************************************
QuadTriExtruded3D.cpp

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

#include "QuadTriExtruded3D.h"

// By Geuzaine, Remacle...
static void addTetrahedron(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                           GRegion *to, MElement* source)
{
  MTetrahedron* newElem = new MTetrahedron(v1, v2, v3, v4);
  to->tetrahedra.push_back(newElem);
}

// By Geuzaine, Remacle...
static void addPyramid(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                       MVertex* v5, GRegion *to, MElement* source)
{
  MPyramid* newElem = new MPyramid(v1, v2, v3, v4, v5);
  to->pyramids.push_back(newElem);
}

// By Geuzaine, Remacle...
static void addPrism(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                     MVertex* v5, MVertex* v6, GRegion *to, MElement* source)
{
  MPrism* newElem = new MPrism(v1, v2, v3, v4, v5, v6);
  to->prisms.push_back(newElem);
}

// By Geuzaine, Remacle...
static void addHexahedron(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                          MVertex* v5, MVertex* v6, MVertex* v7, MVertex* v8,
                          GRegion *to, MElement* source)
{
  MHexahedron* newElem = new MHexahedron(v1, v2, v3, v4, v5, v6, v7, v8);
  to->hexahedra.push_back(newElem);
}


// Does the pair of MVertex pointers v1 and v2 exist in the set 'edges'?
static int edgeExists(MVertex *v1, MVertex *v2,
                      std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  std::pair<MVertex*, MVertex*> p(std::min(v1, v2), std::max(v1, v2));
  return edges.count(p);
}


// Create the pair of MVertex pointers v1 and v2 exist in the set 'edges.'
static void createEdge(MVertex *v1, MVertex *v2,
                       std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  std::pair<MVertex*, MVertex*> p(std::min(v1, v2), std::max(v1, v2));
  edges.insert(p);
}


// Create the entry for a forbidden edge in forbidden_edges (note that all four verts are
// forbidden, but only store two, using lowest vertex pointer diagonal).
static void createForbidden(std::vector<MVertex*> v,
                       std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges)
{
  if( v.size() != 4 ){
    Msg::Error("In createForbidden(), number of vertices not equal 4.");
    return;
  }
  int ind_low = 0;
  if( v[1] < v[ind_low] ) ind_low = 1;
  if( v[2] < v[ind_low] ) ind_low = 2;
  if( v[3] < v[ind_low] ) ind_low = 3;

  std::pair<MVertex*, MVertex*> p( v[ind_low], v[(ind_low+2)%4] );
  forbidden_edges.insert(p);
}


// Is the given vector of quad vertices forbidden to diagonalize (it is in forbidden_edges)?
static int forbiddenExists(std::vector<MVertex*> v,
                       std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges)
{

  if( v.size() != 4 ){
    Msg::Error("forbiddenExists() was passed a vector argument that was not of size 4.");
    return 0;
  }

  int ind_low = 0;
  if( v[1] < v[ind_low] ) ind_low = 1;
  if( v[2] < v[ind_low] ) ind_low = 2;
  if( v[3] < v[ind_low] ) ind_low = 3;

  std::pair<MVertex*, MVertex*> pair( v[ind_low], v[(ind_low+2)%4] );
  return forbidden_edges.count(pair);
}


// delete a pair of vertex pointers v1 and v2 from 'edges.'
static void deleteEdge(MVertex *v1, MVertex *v2,
                       std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  std::pair<MVertex*, MVertex*> p(std::min(v1, v2), std::max(v1, v2));
  edges.erase(p);
}


// Get the two mesh vertices extruded from vertices v0 and v1 on a lateral face at layer j, element k.
// Added 2010-01-26
static std::vector<MVertex*> getExtrudedLateralVertices( MVertex *v0, MVertex *v1, GEntity *entity,
                                     unsigned int j, unsigned int k, ExtrudeParams *loop_ep,
                                     std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{

  std::vector<MVertex*> verts;
  std::set<MVertex *, MVertexLessThanLexicographic>::iterator itp;
  double x[4] = {v0->x(), v1->x(), v0->x(), v1->x()};
  double y[4] = {v0->y(), v1->y(), v0->y(), v1->y()};
  double z[4] = {v0->z(), v1->z(), v0->z(), v1->z()};
  for(int p = 0; p < 2; p++){
    loop_ep->Extrude(j, k, x[p], y[p], z[p]);
    loop_ep->Extrude(j, k + 1, x[p + 2], y[p + 2], z[p + 2]);
  }
  for(int p = 0; p < 4; p++){
    MVertex tmp(x[p], y[p], z[p], 0, -1);
    itp = pos.find(&tmp);
    if(itp == pos.end()){ // FIXME: workaround
      Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
      itp = tmp.linearSearch(pos);
    }
    if(itp == pos.end()){
      Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g) in geometrical entity %d",
                  tmp.x(), tmp.y(), tmp.z(), entity->tag());

      verts.clear();
      return verts;
    }
    verts.push_back(*itp);
  }

  return verts;

}


// Get the extruded vertices from MElement *elem at layer j, element k.
// Added 2010-01-26
static int get2DExtrudedVertices( MElement *elem, ExtrudeParams *ep, unsigned int j, unsigned int k,
                                  std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                                  std::vector<MVertex *> &verts )
{
  std::vector<MVertex*> source_verts;
  elem->getVertices( source_verts );

  std::set<MVertex *, MVertexLessThanLexicographic>::iterator itp;
  int sz = source_verts.size();
  std::vector<double> x(sz), y(sz), z(sz);
  for( int p = 0; p < sz; p++ ){
    x[p] = source_verts[p]->x();
    y[p] = source_verts[p]->y();
    z[p] = source_verts[p]->z();
  }
  for(int p = 0; p < sz; p++){
    ep->Extrude(j, k, x[p], y[p], z[p]);
    MVertex tmp(x[p], y[p], z[p], 0, -1);
    itp = pos.find(&tmp);
    if(itp == pos.end()){ // FIXME: workaround
      Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
      itp = tmp.linearSearch(pos);
    }
    if(itp == pos.end()){
      Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g).",
                  tmp.x(), tmp.y(), tmp.z() );

      verts.clear();
      return verts.size();
    }
    verts.push_back(*itp);
  }

  return verts.size();

}


// Copied from meshGRegionExtruded.cpp, By Geuzaine, Remacle...
// Extrudes a set of source vertices in 3D
// added 2010-01-18
static int getExtrudedVertices(MElement *ele, ExtrudeParams *ep, int j, int k,
                               std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                               std::vector<MVertex*> &verts)
{
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
  double x[8], y[8], z[8];
  int n = ele->getNumVertices();
  for(int p = 0; p < n; p++){
    MVertex *v = ele->getVertex(p);
    x[p] = x[p + n] = v->x();
    y[p] = y[p + n] = v->y();
    z[p] = z[p + n] = v->z();
  }
  for(int p = 0; p < n; p++){
    ep->Extrude(j, k, x[p], y[p], z[p]);
    ep->Extrude(j, k + 1, x[p + n], y[p + n], z[p + n]);
  }
  for(int p = 0; p < 2 * n; p++){
    MVertex tmp(x[p], y[p], z[p], 0, -1);
    itp = pos.find(&tmp);
    if(itp == pos.end()){ // FIXME: workaround
      Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
      itp = tmp.linearSearch(pos);
    }
    if(itp == pos.end())
      Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g)",
                 tmp.x(), tmp.y(), tmp.z());
    else
      verts.push_back(*itp);
  }
  return verts.size();
}


// Determines whether the region is a valid QuadToTri region.  Performs some
// basic checks, including whether there is a valid top, valid source,
// and that the surfaces serving as laterals are structured
// Added 2010-12-30
bool IsValidQuadToTriRegion(GRegion *region, bool *allNonGlobalSharedLaterals)
{
  ExtrudeParams *ep = region->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh )
    return false;

  GModel *model = region->model();

  // find source face
  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source ){
    Msg::Error("In IsValidQuadToTriRegion(), could not find source face "
               "%d for region %d.", std::abs( ep->geo.Source ),
               region->tag() );
    return false;
  }

  // Find a source surface. Then find a COPIED_ENTITY that is the top surface.
  // Then determine if all the laterals are either all quad or all triangle.
  // If shared laterals are all static (quad or non subdivide triangles),
  // set the allNonGlobalSharedLaterals argument to true.
  // If any lateral is unstructured, error.

  bool foundTop = false, foundSource = false,
                  foundNoStruct = false;

  std::list<GFace *> faces = region->faces();
  std::list<GFace *>::iterator it = faces.begin();

  (*allNonGlobalSharedLaterals) = true;

  for( it = faces.begin(); it != faces.end(); it++ ){
    ExtrudeParams *face_tmp_ep = (*it)->meshAttributes.extrude;
    if( (*it) == reg_source )
      foundSource = true;
    else if( face_tmp_ep && face_tmp_ep->geo.Mode ==
        COPIED_ENTITY ){
      GFace *top_source_tmp = model->getFaceByTag(
                              std::abs( face_tmp_ep->geo.Source ) );
      if( !top_source_tmp ){
        Msg::Error("In IsValidQuadToTriRegion(), could not find source face "
                   "%d for copied surface %d of region %d.",
                   std::abs( face_tmp_ep->geo.Source ),
                   (*it)->tag(), region->tag() );
        return false;
      }
      else if( top_source_tmp == reg_source &&
               !IsSurfaceALateralForRegion(region, *it) )
        foundTop = true;
    }
    // This is a check to see if there are lateral surface triangles that need to be edged globally in subdivide operation
    else if( IsSurfaceALateralForRegion(region, *it) ){
      std::vector<GRegion *> neighbors;
      if( (*allNonGlobalSharedLaterals) && (*it)->triangles.size() && !(*it)->quadrangles.size()&&
          GetNeighborRegionsOfFace(*it, neighbors) > 1 ){
        GRegion *other_region = neighbors[0] != region ? neighbors[0] : neighbors[1];
        ExtrudeParams *oth_ep = other_region->meshAttributes.extrude;
        if( (ep && ep->mesh.ExtrudeMesh && !ep->mesh.Recombine) ||
            (oth_ep && oth_ep->mesh.ExtrudeMesh && !oth_ep->mesh.Recombine &&
             IsSurfaceALateralForRegion(other_region, *it)) )
          (*allNonGlobalSharedLaterals) = false;
      }
    }
    else
      foundNoStruct = true;
  }


  // test for errors
  bool detectConflict = false;
  if( !foundTop ){
    Msg::Error("In IsValidQuadToTriRegion(), could not find top face "
               "of region %d.", region->tag() );
    detectConflict = true;
  }
  if( !foundSource ){
    Msg::Error("In IsValidQuadToTriRegion(), source "
               "face %d of region %d was not found in region.",
                region->tag() );
    detectConflict = true;
  }
  if( foundNoStruct ){
    Msg::Error("In IsValidQuadToTriRegion(), found unstructured "
               "lateral in QuadToTri region %d.", region->tag() );
    detectConflict = true;
  }

  if( detectConflict )
    return false;

  // no errors, return true
  return true;
}


// This function returns a vector of integer values, each of which are codes for the
// status of each face of an undivided prism or hexahedron (including degenerate versions):
// 0 = degenerate line, 1 = single triangle, 2 = recombined quad,
// 3 = fixed diagonal, 4 = adjustable diagonal, 5 = totally free to diagonalize or not.
// Ordering of faces starts with the lateral face containing verts[0] and verts[1], then goes in order
// of increasing vertex index around element. Finally, the bottom, then the top.
// Added 2010-01-21
static std::map<std::string, std::vector<int> > getFaceTypes(GRegion *gr, MElement *elem, int j, int k,
                                     std::vector<MVertex *> &verts,
                                     std::set<MVertex*, MVertexLessThanLexicographic> &pos_src_edge,
                                     std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                     std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                     std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                     std::vector<bool> &vert_bnd, std::vector<int> &nfix1,
                                     std::vector<int> &nfix2, std::vector<int> &nadj1,
                                     std::vector<int> &nadj2, std::vector<int> &free_flag )
{
  std::map<std::string, std::vector<int> > face_types;
  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In getFaceTypes(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return face_types;
  }

  // get the starting indices of the top quadToTri layer
  int j_top_start = 0, k_top_start = 0;
  j_top_start = ep->mesh.NbLayer-1;
  k_top_start = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;



  // check nature of each face
  int n_lat_tmp = 0;
  if( verts.size() == 6 )
    n_lat_tmp = 3;
  else if( verts.size() == 8 )
    n_lat_tmp = 4;
  else{
    Msg::Error("In getFaceTypes(), size of verts vector was not 6 or 8 (region %d).",
               gr->tag() );
    return face_types;
  }

  const int n_lat = n_lat_tmp;

  // set defaults for the nfix, nadj vectors that store the nodes for each fixed or adjustable diagonal
  // And set the defaults for free_flag which tells whether a face is free (0)
  nfix1.clear(); nfix1.assign(n_lat+2, 0);
  nfix2.clear(); nfix2.assign(n_lat+2, 0);
  nadj1.clear(); nadj1.assign(n_lat+2, 0);
  nadj2.clear(); nadj2.assign(n_lat+2, 0);
  free_flag.clear(); free_flag.assign(n_lat+2, 0);
  for( int p = 0; p < n_lat+2; p++ ){
    nfix1[p] = -p*p-p-1;
    nfix2[p] = -p*p-p-2;
    nadj1[p] = -p*p-p-1;
    nadj2[p] = -p*p-p-2;
    free_flag[p] = 0;
  }

  // create an array that holds info about whether a face touches a boundary
  std::vector<int> touch_bnd(n_lat);

  fill_touch_bnd(&touch_bnd[0], vert_bnd, n_lat);

  // Classify the laterals of each little mesh volume:

  for( int p = 0; p < n_lat; p++ ){
    int p2 = (p+1)%n_lat;
    std::vector<MVertex*> v_face;
    v_face.assign(4, (MVertex*)(0));
    v_face[0] = verts[p]; v_face[1] = verts[p2];
    v_face[2] = verts[p2+n_lat]; v_face[3] = verts[p+n_lat];

    // is the face a degenerate line:
    if( verts[p] == verts[n_lat+p] &&
        verts[p2] == verts[n_lat+p2] ){
      face_types["degen"].push_back(p);
    }
    // is face a single triangle?
    else if( (verts[p] == verts[n_lat+p] &&
              verts[p2] != verts[n_lat+p2]) ||
             (verts[p] != verts[n_lat+p] &&
              verts[p2] == verts[n_lat+p2]) ){
      face_types["single_tri"].push_back(p);
    }
    // is face a recombined quad?
    else if( forbiddenExists( v_face, forbidden_edges ) )
      face_types["recomb"].push_back(p);

    // Does face contain a fixed diagonal edge?
    else if( edgeExists( verts[p], verts[p2+n_lat], quadToTri_edges ) ){
      nfix1[p] = p; nfix2[p] = p2+n_lat;
      face_types["fixed_diag"].push_back(p);
    }
    else if( edgeExists( verts[n_lat+p], verts[p2], quadToTri_edges ) ){
      nfix1[p] = p+n_lat; nfix2[p] = p2;
      face_types["fixed_diag"].push_back(p);
    }

    // Does the face have an adjustable but required diagonal?
    // ( this else if requires that the previous one about fixed diagonals
    //  comes FIRST )
    else if( edgeExists( verts[p], verts[p2+n_lat], lat_tri_diags ) ){
      nadj1[p] = p; nadj2[p] = p2+n_lat;
      face_types["adj_diag"].push_back(p);
    }
    else if( edgeExists( verts[n_lat+p], verts[p2], lat_tri_diags ) ){
      nadj1[p] = p+n_lat; nadj2[p] = p2;
      face_types["adj_diag"].push_back(p);
    }

    // If no previous option was true, then this face is an internal face.

    // If this face has NO vertices on a lateral surface, and is a triangle or
    //  not in the top quadToTri layer:
    // then the face is a recombined quad (QuadToTri only used in recombined extrusions).
    else if( !touch_bnd[p] &&
             ( j < j_top_start || (j == j_top_start && k < k_top_start) ) )
      face_types["recomb"].push_back(p);

    // Face is possibly free...will need to do tests after this loop is complete to
    // finalize that. But, for now....
    else{
      face_types["free"].push_back(p);
      free_flag[p] = 1;
    }
  }


  // set the bottom:
  if( n_lat == 3 )
    face_types["single_tri"].push_back(3);

  else{
    std::vector<MVertex *> v_bot;
    v_bot.assign(4, (MVertex*)(0));
    v_bot[0] = verts[0]; v_bot[1] = verts[1];
    v_bot[2] = verts[2]; v_bot[3] = verts[3];
    // is forbidden?
    if ( (j == 0 && k == 0) || forbiddenExists( v_bot, forbidden_edges ) )
      face_types["recomb"].push_back(4);
    else if( edgeExists( verts[0], verts[2], quadToTri_edges ) ){
      nfix1[4] = 0; nfix2[4] = 2;
      face_types["fixed_diag"].push_back(4);
    }
    else if( edgeExists( verts[1], verts[3], quadToTri_edges ) ){
      nfix1[4] = 1; nfix2[4] = 3;
      face_types["fixed_diag"].push_back(4);
    }
    // Does the face have an adjustable but required diagonal?
    // ( this else if requires that the previous one about fixed diagonals
    //  comes FIRST )
    // NOTE: THIS SITUATION SHOULD NEVER HAPPEN ON THIS FACE
    else if( edgeExists( verts[0], verts[2], lat_tri_diags ) ){
      nadj1[4] = 0; nadj2[4] = 2;
      face_types["adj_diag"].push_back(4);
    }
    else if( edgeExists( verts[1], verts[3], lat_tri_diags ) ){
      nadj1[4] = 1; nadj2[4] = 3;
      face_types["adj_diag"].push_back(4);
    }
    else{
      face_types["free"].push_back(4);
      free_flag[4] = 1;
    }
  }

  // set the top:
  if( n_lat == 3 )
      face_types["single_tri"].push_back(4);
  // if a hexahedron:
  else{
    std::vector<MVertex *> v_top;
    v_top.assign(4, (MVertex*)(0));
    v_top[0] = verts[4]; v_top[1] = verts[5];
    v_top[2] = verts[6]; v_top[3] = verts[7];
    // is forbidden ?
    if( forbiddenExists(v_top, forbidden_edges) )
      face_types["recomb"].push_back(5);
    // search for a fixed edge:
    else if( edgeExists( verts[4], verts[6], quadToTri_edges ) ){
      nfix1[5] = 4; nfix2[5] = 6;
      face_types["fixed_diag"].push_back(5);
    }
    else if( edgeExists( verts[5], verts[7], quadToTri_edges ) ){
      nfix1[5] = 5; nfix2[5] = 7;
      face_types["fixed_diag"].push_back(5);
    }
    // Does the face have an adjustable but required diagonal?
    // ( this else if requires that the previous one about fixed diagonals
    //  comes FIRST )
    // NOTE: THIS SITUATION SHOULD NEVER HAPPEN ON THIS FACE
    else if( edgeExists( verts[4], verts[6], lat_tri_diags ) ){
      nadj1[5] = 4; nadj2[5] = 6;
      face_types["adj_diag"].push_back(5);
    }
    else if( edgeExists( verts[5], verts[7], lat_tri_diags ) ){
      nadj1[5] = 5; nadj2[5] = 7;
      face_types["adj_diag"].push_back(5);
    }
    else{
      face_types["free"].push_back(5);
      free_flag[5] = 1;
    }
  }

  // now return face_types
  return face_types;

}


// Generate face diagonals used to subdivide prisms by BRUTE FORCE...NOT RECOMMENDED for general use, but it
// is required for some elements which have all vertices on an external region boundary.
// Added 2010-01-29
static void bruteForceEdgeQuadToTriPrism( GRegion *gr, MElement *elem,
                                      int j, int k, std::vector<MVertex *> verts,
                                      std::map<std::string, std::vector<int> > &face_types,
                                      std::set<std::pair<MVertex*, MVertex*> > &edges_new,
                                      std::set<std::pair<MVertex*, MVertex*> > &forbidden_new,
                                      std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                      std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                      std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                      std::vector<int> nfix1, std::vector<int> nfix2,
                                      std::vector<int> nadj1, std::vector<int> nadj2,
                                      std::vector<int> free_flag )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In bruteForceEdgeQuadToTriPrism(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In bruteForceEdgeQuadToTriPrism(), invalid model for region "
               "%d.", gr->tag() );
    return;
  }

  // now find and verify the source of region

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In bruteForceEdgeQuadToTriPrism(), invalid source face for region "
               "%d.", gr->tag() );
    return;
  }

  // verify number of vertices
  int n_lat;
  if( verts.size() != 6 ){
    Msg::Error("In bruteForceEdgeQuadToTriPrism(), number of vertices not equal "
               "6.");
    return;
  }
  else
    n_lat = 3;


  // NOTE THAT FACES ARE NUMBERED CONSECUTIVELY FROM 0, starting from vertex 0 and moving around laterally.
  // Hence, the face after vertex 0 is face 0, and so forth.  The bottom and top faces are numbered
  // (number of laterals + 1)  and (number of laterals + 2), respectively.

  // numbers of each type of face
  int num_degen = face_types["degen"].size();
  int num_single_tri = face_types["single_tri"].size();
  int num_recomb = face_types["recomb"].size();
  int num_fixed_diag = face_types["fixed_diag"].size();
  int num_adj_diag = face_types["adj_diag"].size();
  int num_free = face_types["free"].size();

  // Make sure all faces marked forbidden in face_types have all diagonals in forbidden_edges;
  for( int p = 0; p < num_recomb; p++){
    int ind = face_types["recomb"][p];
    std::vector<MVertex*> v;
    v.push_back(verts[ind]); v.push_back(verts[(ind+1)%3]); v.push_back(verts[(ind+1)%3+3]);
    v.push_back(verts[ind+3]);
    createForbidden(v, forbidden_new );
    createForbidden(v, forbidden_edges );
  }

  // following must be true if this is a triangle extrusion
  if( find(face_types["single_tri"].begin(), face_types["single_tri"].end(), 3) ==
          face_types["single_tri"].end()  ||
      find(face_types["single_tri"].begin(), face_types["single_tri"].end(), 4) ==
          face_types["single_tri"].end() ){
    Msg::Error("In bruteForceEdgeQuadToTriPrism(), invalid face code for top and/or "
               "bottom (region %d).", gr->tag() );
    return;
  }


  // Take care of the trivial case: tetrahedron:
  if( num_single_tri == 4 && num_degen == 1 )
    return;

  // Pyramid also very easy:

  else if ( num_single_tri == 4 ){
    int ind = 0;
    if( num_adj_diag ){
      ind = face_types["adj_diag"][0];
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new );
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges );
    }
    return;
  }


  // A PRISM IS MORE DIFFICULT:

  // First case, if exactly two laterals are forbidden to diagonalize:
  if( num_recomb == 2 ){
    if( num_free ){
      for( int p = 0; p < num_free; p++){
        int ind = face_types["free"][p];
        std::vector<MVertex*> v;
        v.push_back(verts[ind]); v.push_back(verts[(ind+1)%3]);
        v.push_back(verts[(ind+1)%3+3]); v.push_back(verts[ind+3]);
        createForbidden(v, forbidden_new );
        createForbidden(v, forbidden_edges );
      }
    }
    else{
      if( num_adj_diag ){
        int ind = face_types["adj_diag"][0];
        createEdge(verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges );
        createEdge(verts[nadj1[ind]], verts[nadj2[ind]], edges_new );
      }
      std::pair<unsigned int, unsigned int> jkpair(j,k);
      problems[elem].insert(jkpair);
      problems_new[elem].insert(jkpair);
    }
    return;
  }

  // If 1 lateral is forbidden to diagonalize and two free, diagonalize to lowest point vector on free edge:
  if( num_recomb == 1 && num_free == 2 ){
    int p_recomb = face_types["recomb"][0];
    int p_free = (p_recomb + 2)%3;
    int ind_low = verts[p_free] < verts[p_free+3]
                  ? p_free : p_free+3;
    int add = ind_low < 3 ? 0 : 3;
    createEdge( verts[ind_low], verts[(ind_low-add+1)%3+3-add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+1)%3+3-add], edges_new );
    createEdge( verts[ind_low], verts[(ind_low-add+2)%3+3-add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+2)%3+3-add], edges_new );

    return;
  }


  // If all faces are free, then diagonalize TWO faces based on smallest vertex pointer
  if( num_free >= 3 ){
    int ind_low;
    ind_low = 0;
    for( int p = 1; p < 6; p++ ){
      if( verts[ind_low] > verts[p] )
        ind_low = p;
    }

    int add = ind_low < 3 ? 0 : 3;

    createEdge( verts[ind_low], verts[(ind_low-add+1)%3+3-add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+1)%3+3-add], edges_new );
    createEdge( verts[ind_low], verts[(ind_low-add+2)%3+3-add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+2)%3+3-add], edges_new );

    return;
  }


  // If reach this point, then go through the loop of progressively permitting more face types
  // to be considered for diagonalization.  This loop could be slow, that's why previous special cases were
  // tried first.
  // t=0, fixed and preferred diagonals only.
  // t=1, allow preferred diagonals to be meshed with lowest vertex pointer in diagonal
  // t=2, allow free faces to be meshed with lowest vertex pointer in diagonal
  // t=3, allow any diagonal that works
  bool valid_division = false;
  int face_done[2]={0,0};  // holds the face numbers for the two faces that are done
  for( int t = 0; t < 4; t++ ){

    // variables that hold the face diagonal nodes.
    int n1[3], n2[3];

    // if the face is completely free (t==3), face_is_free = true;
    bool face_is_free[3];

    // set default values of the n variables
    // to unique negative numbers; bool to false.
    for( int p = 0; p < 3; p++ ){
      n1[p] = -p*p-p-1;
      n2[p] = -p*p-p-2;
      face_is_free[p] = false;
    }

    for( int p = 0; p < 3; p++ ){
      // fixed diagonals
      if( nfix1[p] >= 0 ){
        n1[p] = nfix1[p]; n2[p] = nfix2[p];
      }
      // preferred adjustable diagonals
      else if( !t && nadj1[p] >= 0 ){
        n1[p] = nadj1[p]; n2[p] = nadj2[p];
      }
      // choose lowest vertex for t < 3, any vertex for t == 3
      else if( (t >= 1 && t < 3 && nadj1[p] >= 0) ||
               (t == 2 && free_flag[p]) ){
        if( verts[p] < verts[(p+1)%3] &&
             verts[p] < verts[p+3] ||
            verts[(p+1)%3+3] < verts[(p+1)%3] &&
             verts[(p+1)%3+3] < verts[p+3] ){
          n1[p] = p; n2[p] = (p+1)%3+3;
        }
        else{
          n1[p] = p+3; n2[p] = (p+1)%3;
        }
      }
      else if( (t==3 && (nadj1[p] >= 0) || free_flag[p]) )
        face_is_free[p] = true;
    }

    // search for two faces that have diagonals which meet at a vertex
    for( int p = 0; p < 3; p++ ){
      // if both faces are free, fix one by using lowest vertex pointer
      if( face_is_free[p] && face_is_free[(p+1)%3] ){
        face_is_free[p] = false;
        if( verts[(p+1)%3] < verts[(p+1)%3+3] ){
          n1[p] = p+3;
          n2[p] = (p+1)%3;
        }
        else{
          n1[p] = p;
          n2[p] = (p+1)%3+3;
        }
      }
      // if first face is free and the other has a definite diagonal
      if( face_is_free[p] && n1[(p+1)%3] >= 0 ){
        valid_division = true;
        face_done[0] = p;
        face_done[1] = (p+1)%3;
        if( n1[(p+1)%3] == (p+1)%3 || n2[(p+1)%3] == (p+1)%3 ){
          n1[p] = p+3;
          n2[p] = (p+1)%3;
        }
        else{
          n1[p] = p;
          n2[p] = (p+1)%3+3;
        }
      }
      // if second face is free and the other has a definite diagonal
      else if( face_is_free[(p+1)%3] && n1[p] >= 0 ){
        valid_division = true;
        face_done[0] = p;
        face_done[1] = (p+1)%3;
        if( n2[p] == (p+1)%3 || n1[p] == (p+1)%3 ){
          n1[(p+1)%3] = (p+1)%3;
          n2[(p+1)%3] = (p+2)%3+3;
        }
        else{
          n1[(p+1)%3] = (p+1)%3+3;
          n2[(p+1)%3] = (p+2)%3;
        }
      }
      // if both faces had definite diagonals
      else if( n2[p] == n1[(p+1)%3] || n2[p] == n2[(p+1)%3] ||
               n1[p] == n1[(p+1)%3] || n1[p] == n2[(p+1)%3] ){
        valid_division = true;
        face_done[0] = p;
        face_done[1] = (p+1)%3;
      }

      if( valid_division ){
        createEdge( verts[n1[p]], verts[n2[p]], quadToTri_edges );
        createEdge( verts[n1[p]], verts[n2[p]], edges_new );
        createEdge( verts[n1[(p+1)%3]], verts[n2[(p+1)%3]], quadToTri_edges );
        createEdge( verts[n1[(p+1)%3]], verts[n2[(p+1)%3]], edges_new );
        break;
      }
    }

    // At this point, can break out if valid_division... OR if there is NO valid division AND
    // if num_fixed_diag == 3, or 2 and a recomb
    // break out of loop. This will need an internal vertex.
    if( valid_division || (!valid_division && num_fixed_diag + num_recomb == 3) )
      break;

  } // end of outer t-loop

  // create adjustable but required diagonals that weren't yet added
  for( int s = 0; s < num_adj_diag; s++ ){
    int ind = face_types["adj_diag"][s];
    if( ind != face_done[0] && ind != face_done[1] ){
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new );
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges );
    }
  }

  if( !valid_division ){
    std::pair<unsigned int, unsigned int> jk_pair(j,k);
    problems[elem].insert(jk_pair);
    problems_new[elem].insert(jk_pair);
  }

  return;

}  // end of bruteForceEdgeQuadToTriPrism()



// Divide hexahedron degenerated at two points (degenerate face is a line) by brute force
static void addEdgesForQuadToTriTwoPtDegenHexa( GRegion *gr, MElement *elem, ExtrudeParams *ep,
                                               int j, int k, std::vector<MVertex *> verts,
                                               std::map<std::string, std::vector<int> > &face_types,
                                               std::set<std::pair<MVertex*, MVertex*> > &edges_new,
                                               std::set<std::pair<MVertex*, MVertex*> > &forbidden_new,
                                               std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                               std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                               std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                               std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                               std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                               std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                                               std::vector<int> nfix1, std::vector<int> nfix2,
                                               std::vector<int> nadj1, std::vector<int> nadj2,
                                               std::vector<int> free_flag )
{

  if( !ep )
    return;

  // numbers of each type of face
  // int num_degen = face_types["degen"].size();
  // int num_single_tri = face_types["single_tri"].size();
  // int num_recomb = face_types["recomb"].size();
  // int num_fixed_diag = face_types["fixed_diag"].size();
  // int num_adj_diag = face_types["adj_diag"].size();
  int num_free = face_types["free"].size();

  int degen_face = face_types["degen"][0];

  // If all faces are free, then diagonalize TWO faces based on smallest vertex pointer
  if( num_free >= 3 ){
    int ind_low;
    ind_low = 0;
    for( int p = 1; p < 8; p++ ){
      if( verts[ind_low] > verts[p] )
        ind_low = p;
    }

    int add = ind_low < 4 ? 0 : 4;

    if( verts[ind_low-add] == verts[ind_low+4-add] ){
      createEdge( verts[ind_low], verts[(ind_low-add+2)%4], quadToTri_edges );
      createEdge( verts[ind_low], verts[(ind_low-add+2)%4], edges_new );
      createEdge( verts[ind_low], verts[(ind_low-add+2)%4+4], quadToTri_edges );
      createEdge( verts[ind_low], verts[(ind_low-add+2)%4+4], edges_new );
    }
    else{
      createEdge( verts[ind_low], verts[(ind_low-add+2)%4+4-add], quadToTri_edges );
      createEdge( verts[ind_low], verts[(ind_low-add+2)%4+4-add], edges_new );
      int ind2;
      if( verts[(ind_low-add+1)%4] == verts[(ind_low-add+1)%4+4] )
        ind2 = (ind_low-add+3)%4+4-add;
      else
        ind2 = (ind_low-add+1)%4+4-add;
      createEdge( verts[ind_low], verts[ind2], quadToTri_edges );
      createEdge( verts[ind_low], verts[ind2], edges_new );
    }

    return;
  }

  // If faces of prism not all free, look for a way to diagonalize and subdivide.
  // t = 0, fixed and preferred adjustable diagonals
  // t >= 1 < 3, lowest pointer on adjustables
  // t = 2, include free faces, lowest vertex pointer diagonal on adjustable and free
  // t = 3, not lowest vertex pointer diagonal on adjustable and free

  int face_done[2];
  face_done[0] = -1;
  face_done[1] = -2;

  // valid_division tells whether a valid division was found
  bool valid_division = false;

  for( int t = 0; t < 4; t++ ){
    // these variables hold the faces and their diagonal nodes in (n1,n2)
    int p_top = 5, n1_top = -2, n2_top = -3;
    bool p_top_is_free = false;
    int p_bot = 4, n1_bot = -4, n2_bot = -5;
    bool p_bot_is_free = false;
    int p_lat = (degen_face+2)%4, n1_lat = -10, n2_lat = -11;
    bool p_lat_is_free = false;
    for( int s = 0; s < 3; s++ ){
      int p_tmp=0, *n1_tmp=0, *n2_tmp=0;
      bool *p_is_free_tmp=0;
      if( !s ){
        p_tmp = p_bot;
        n1_tmp = &n1_bot;
        n2_tmp = &n2_bot;
        p_is_free_tmp = &p_bot_is_free;
      }
      if( s==1 ){
        p_tmp = p_top;
        n1_tmp = &n1_top;
        n2_tmp = &n2_top;
        p_is_free_tmp = &p_top_is_free;
      }
      if( s==2 ){
        p_tmp = p_lat;
        n1_tmp = &n1_lat;
        n2_tmp = &n2_lat;
        p_is_free_tmp = &p_lat_is_free;
      }

      // fixed diagonals
      if( nfix1[p_tmp] >= 0 ){
        *n1_tmp = nfix1[p_tmp]; *n2_tmp = nfix2[p_tmp];
      }
      // preferred adjustable diagonals
      else if( !t && nadj1[p_tmp] >= 0 ){
        *n1_tmp = nadj1[p_tmp]; *n2_tmp = nadj2[p_tmp];
      }
      // choose lowest vertex for t < 3, non-lowest vertex for t == 3
      else if( (t >= 1 && t < 3 && nadj1[p_tmp] >= 0) ||
               (t == 2 && free_flag[p_tmp]) ){
        if( p_tmp < 4 ){
          if( (verts[p_tmp] < verts[(p_tmp+1)%4] &&
               verts[p_tmp] < verts[p_tmp+4]) ||
              (verts[(p_tmp+1)%4+4] < verts[(p_tmp+1)%4] &&
               verts[(p_tmp+1)%4+4] < verts[p_tmp+4]) ){
            *n1_tmp = p_tmp; *n2_tmp = (p_tmp+1)%4+4;
          }
          else{
            *n1_tmp = p_tmp+4; *n2_tmp = (p_tmp+1)%4;
          }
        }
        else{
          int add = p_tmp==4 ? 0 : 4;
          if( (verts[0+add] < verts[1+add] && verts[0+add] < verts[3+add]) ||
              (verts[2+add] < verts[1+add] && verts[2+add] < verts[3+add]) ){
            *n1_tmp = 0+add; *n2_tmp = 2+add;
          }
          else{
            *n1_tmp = 1+add; *n2_tmp = 3+add;
          }
        }
      }
      else if( t==3 && (nadj1[p_tmp] >= 0 || free_flag[p_tmp]) )
        *p_is_free_tmp = true;

    }

    // Find any diagonals that meet at a vertex:

    // start with top surface and bottom surface
    if( ( n1_top >= 0 || p_top_is_free ) &&
        ( n1_bot >= 0 || p_bot_is_free ) ){
      if( p_top_is_free && p_bot_is_free ){
        if( (verts[4] < verts[5] && verts[4] < verts[7]) ||
            (verts[6] < verts[5] && verts[6] < verts[7]) ){
          n1_top = 4; n2_top = 6;
        }
        else{
          n1_top = 5; n2_top = 7;
        }
        n1_bot = n1_top-4;
        n2_bot = n2_top-4;
      }
      else if( n1_top >= 0 && p_bot_is_free ){
        n1_bot = n1_top-4;
        n2_bot = n2_top-4;
      }
      else if( n1_bot >= 0 && p_top_is_free ){
        n1_top = n1_bot+4;
        n2_top = n2_bot+4;
      }
      if( verts[n1_top] == verts[n1_bot] ||
          verts[n1_top] == verts[n2_bot] ||
          verts[n2_top] == verts[n1_bot] ||
          verts[n2_top] == verts[n2_bot] ){
        valid_division = true;
        face_done[0] = p_top;
        face_done[1] = p_bot;
        createEdge( verts[n1_top], verts[n2_top], quadToTri_edges );
        createEdge( verts[n1_top], verts[n2_top], edges_new );
        createEdge( verts[n1_bot], verts[n2_bot], quadToTri_edges );
        createEdge( verts[n1_bot], verts[n2_bot], edges_new );
      }
    }

    // Top surface and lateral surface
    if( !valid_division &&
        ( n1_top >= 0 || p_top_is_free ) &&
        ( n1_lat >= 0 || p_lat_is_free ) ){

      if( p_top_is_free && p_lat_is_free ){
        if( (verts[4] < verts[5] && verts[4] < verts[7]) ||
            (verts[6] < verts[5] && verts[6] < verts[7]) ){
          n1_top = 4; n2_top = 6;
        }
        else{
          n1_top = 5; n2_top = 7;
        }
        if( n1_top == (degen_face+2)%4+4 ||
            n2_top == (degen_face+2)%4+4 ){
          n1_lat = (degen_face+2)%4+4;
          n2_lat = (n1_lat-4+1)%4;
        }
        else{
          n1_lat = (degen_face+3)%4+4;
          n2_lat = (n1_lat-4+3)%4;
        }
      }
      else if( n1_top >= 0 && p_lat_is_free ){
        if( n1_top == (degen_face+2)%4+4 ||
            n2_top == (degen_face+2)%4+4 ){
          n1_lat = (degen_face+2)%4+4;
          n2_lat = (n1_lat-4+1)%4;
        }
        else{
          n1_lat = (degen_face+3)%4+4;
          n2_lat = (n1_lat-4+3)%4;
        }
      }
      else if( n1_lat >= 0 && p_top_is_free ){
        if( n1_lat == (degen_face+2)%4+4 ||
            n2_lat == (degen_face+2)%4+4 ){
          n1_top = (degen_face+2)%4+4;
          n2_top = (n1_top-4+2)%4+4;
        }
        else{
          n1_top = (degen_face+3)%4+4;
          n2_top = (n1_top-4+2)%4+4;
        }
      }
      if( verts[n1_top] == verts[n1_lat] ||
          verts[n1_top] == verts[n2_lat] ||
          verts[n2_top] == verts[n1_lat] ||
          verts[n2_top] == verts[n2_lat] ){
        valid_division = true;
        face_done[0] = p_top;
        face_done[1] = p_lat;
        createEdge( verts[n1_top], verts[n2_top], quadToTri_edges );
        createEdge( verts[n1_top], verts[n2_top], edges_new );
        createEdge( verts[n1_lat], verts[n2_lat], quadToTri_edges );
        createEdge( verts[n1_lat], verts[n2_lat], edges_new );
      }
    }

    // Bottom surface and lateral surface
    if( !valid_division &&
        ( n1_bot >= 0 || p_bot_is_free ) &&
        ( n1_lat >= 0 || p_lat_is_free ) ){

      if( p_bot_is_free && p_lat_is_free ){
        if( (verts[0] < verts[1] && verts[0] < verts[3]) ||
            (verts[2] < verts[1] && verts[2] < verts[3]) ){
          n1_bot = 0; n2_bot = 2;
        }
        else{
          n1_bot = 1; n2_bot = 3;
        }
        if( n1_bot == (degen_face+2)%4 ||
            n2_bot == (degen_face+2)%4 ){
          n1_lat = (degen_face+2)%4;
          n2_lat = (n1_lat+1)%4+4;
        }
        else{
          n1_lat = (degen_face+3)%4;
          n2_lat = (n1_lat+3)%4+4;
        }
      }
      else if( n1_bot >= 0 && p_lat_is_free ){
        if( n1_bot == (degen_face+2)%4 ||
            n2_bot == (degen_face+2)%4 ){
          n1_lat = (degen_face+2)%4;
          n2_lat = (n1_lat+1)%4+4;
        }
        else{
          n1_lat = (degen_face+3)%4;
          n2_lat = (n1_lat+3)%4+4;
        }
      }
      else if( n1_lat >= 0 && p_bot_is_free ){
        if( n1_lat == (degen_face+2)%4 ||
            n2_lat == (degen_face+2)%4 ){
          n1_bot = (degen_face+2)%4;
          n2_bot = (n1_bot+2)%4;
        }
        else{
          n1_bot = (degen_face+3)%4;
          n2_bot = (n1_bot+2)%4;
        }
      }
      if( verts[n1_bot] == verts[n1_lat] ||
          verts[n1_bot] == verts[n2_lat] ||
          verts[n2_bot] == verts[n1_lat] ||
          verts[n2_bot] == verts[n2_lat] ){
        valid_division = true;
        face_done[0] = p_bot;
        face_done[1] = p_lat;
        createEdge( verts[n1_bot], verts[n2_bot], quadToTri_edges );
        createEdge( verts[n1_bot], verts[n2_bot], edges_new );
        createEdge( verts[n1_lat], verts[n2_lat], quadToTri_edges );
        createEdge( verts[n1_lat], verts[n2_lat], edges_new );
      }
    }

    if( valid_division )
      break;

  }  // end of t-loop (outer loop)

  // take care of any adjustable but required diagonals not yet added
  for(unsigned int s = 0; s < face_types["adj_diag"].size(); s++ ){
    int ind = face_types["adj_diag"][s];
    if( ind != face_done[0] && ind != face_done[1] ){
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges  );
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new  );
    }
  }

  // if no division top found, need internal vertex.
  if( !valid_division ){
    std::pair<unsigned int, unsigned int> jkpair(j,k);
    problems[elem].insert(jkpair);
    problems_new[elem].insert(jkpair);
  }

  return;

}  // end of addEdgesForQuadToTriTwoPtDegenHexa()


// Divide a hexahedron degenerate at one point (one degenerate corner) by brute force.
static void addEdgesForQuadToTriOnePtDegenHexa( GRegion *gr, MElement *elem, ExtrudeParams *ep,
                                               int j, int k, std::vector<MVertex *> verts,
                                               std::map<std::string, std::vector<int> > &face_types,
                                               std::set<std::pair<MVertex*, MVertex*> > &edges_new,
                                               std::set<std::pair<MVertex*, MVertex*> > &forbidden_new,
                                               std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                               std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                               std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                               std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                               std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                               std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                                               std::vector<int> nfix1, std::vector<int> nfix2,
                                               std::vector<int> nadj1, std::vector<int> nadj2,
                                               std::vector<int> free_flag )
{

  if( !ep )
    return;

  // numbers of each type of face
  // int num_degen = face_types["degen"].size();
  // int num_single_tri = face_types["single_tri"].size();
  // int num_recomb = face_types["recomb"].size();
  // int num_fixed_diag = face_types["fixed_diag"].size();
  // int num_adj_diag = face_types["adj_diag"].size();
  int num_free = face_types["free"].size();

  // index of the degenerate corner
  int degen_ind = verts[face_types["single_tri"][0]]
                  == verts[face_types["single_tri"][0]+4]
                  ? face_types["single_tri"][0] : face_types["single_tri"][1];

  // If all faces are free, slice from degen corner top and bottom. done.
  if( num_free >= 4 ){
    createEdge( verts[degen_ind], verts[(degen_ind+2)%4], quadToTri_edges );
    createEdge( verts[degen_ind], verts[(degen_ind+2)%4], edges_new );
    createEdge( verts[degen_ind], verts[(degen_ind+2)%4+4], quadToTri_edges );
    createEdge( verts[degen_ind], verts[(degen_ind+2)%4+4], edges_new );
    return;
  }

  // If faces of degenerated hexahedron are not all free,
  // look for a way to diagonalize and subdivide.
  // t = 0, fixed and preferred adjustable diagonals
  // t >= 1 < 3, lowest pointer on adjustables
  // t = 2, include free faces, lowest vertex pointer diagonal on adjustable and free
  // t = 3, not lowest vertex pointer diagonal on adjustable and free
  int face_done[3];
  face_done[0] = -1;
  face_done[1] = -2;
  face_done[2] = -3;
  bool valid_division = false;
  for( int t = 0; t < 4; t++ ){
    // first test for top bottom parallel diagonals (g=0), then pyramid with
    // top on corner opposite degen corner (g=1), then pyramid with top on a corner
    // NOT opposite to the degenerate corner (g=2), then test for non-adjoining
    // lateral face diagonals (g=3).
    int p_top = 5, n1_top = -2, n2_top = -3;
    bool p_top_is_free = false;
    int p_bot = 4, n1_bot = -4, n2_bot = -5;
    bool p_bot_is_free = false;
    int p_lat1 = (degen_ind+1)%4, n1_lat1 = -10, n2_lat1 = -11;
    bool p_lat1_is_free = false;
    int p_lat2 = (degen_ind+2)%4, n1_lat2 = -12, n2_lat2 = -13;
    bool p_lat2_is_free = false;

    // get diagonals:
    for( int s = 0; s < 4; s++ ){
      int *n1_tmp, *n2_tmp, p_tmp;
      bool *p_tmp_is_free;
      if( !s ){
        p_tmp = p_top;
        n1_tmp = &n1_top;
        n2_tmp = &n2_top;
        p_tmp_is_free = &p_top_is_free;
      }
      else if( s==1 ){
        p_tmp = p_bot;
        n1_tmp = &n1_bot;
        n2_tmp = &n2_bot;
        p_tmp_is_free = &p_bot_is_free;
      }
      else if( s==2 ){
        p_tmp = p_lat1;
        n1_tmp = &n1_lat1;
        n2_tmp = &n2_lat1;
        p_tmp_is_free = &p_lat1_is_free;
      }
      else{
        p_tmp = p_lat2;
        n1_tmp = &n1_lat2;
        n2_tmp = &n2_lat2;
        p_tmp_is_free = &p_lat2_is_free;
      }
      // fixed diagonals
      if( nfix1[p_tmp] >= 0 ){
        *n1_tmp = nfix1[p_tmp]; *n2_tmp = nfix2[p_tmp];
      }
      // preferred adjustable diagonals
      else if( !t && nadj1[p_tmp] >= 0 ){
        *n1_tmp = nadj1[p_tmp]; *n2_tmp = nadj2[p_tmp];
      }
      // choose lowest vertex for t < 3, any vertex for t == 3
      else if( (t >= 1 && t < 3 && nadj1[p_tmp] >= 0) ||
               (t == 2 && free_flag[p_tmp]) ){
        if( p_tmp < 4 ){
          if( (verts[p_tmp] < verts[(p_tmp+1)%4] &&
               verts[p_tmp] < verts[p_tmp+4]) ||
              (verts[(p_tmp+1)%4+4] < verts[(p_tmp+1)%4] &&
               verts[(p_tmp+1)%4+4] < verts[p_tmp+4]) ){
            *n1_tmp = p_tmp; *n2_tmp = (p_tmp+1)%4+4;
          }
          else{
            *n1_tmp = p_tmp+4; *n2_tmp = (p_tmp+1)%4;
          }
        }
        else{
          int add = p_tmp==4 ? 0 : 4;
          if( (verts[0+add] < verts[1+add] && verts[0+add] < verts[3+add]) ||
              (verts[2+add] < verts[1+add] && verts[2+add] < verts[3+add]) ){
            *n1_tmp = 0+add; *n2_tmp = 2+add;
          }
          else{
            *n1_tmp = 1+add; *n2_tmp = 3+add;
          }
        }
      }
      else if( t==3 && (nadj1[p_tmp] >= 0 || free_flag[p_tmp]) )
        *p_tmp_is_free = true;
    }

    // Look for valid diagonalizations

    // look for aligned top and bottom diags.
    if( !valid_division ){
      // assign diagonals to the 'free' faces from above
      if( p_top_is_free && p_bot_is_free ){
        if( (verts[0] < verts[1] && verts[0] < verts[3]) ||
            (verts[2] < verts[1] && verts[2] < verts[3]) ){
          n1_bot = 0; n2_bot = 2;
        }
        else{
          n1_bot = 1; n2_bot = 3;
        }
        n1_top = n1_bot+4;
        n2_top = n2_bot+4;
      }
      else if( p_top_is_free &&  n1_bot >= 0 ){
        n1_top = n1_bot+4; n2_top = n2_bot+4;
      }
      else if( p_bot_is_free &&  n1_top >= 0 ){
        n1_bot = n1_top-4; n2_bot = n2_top-4;
      }
      // test for valid division
      if( n1_top-4 == n1_bot || n2_top-4 == n1_bot ||
          n1_top-4 == n2_bot || n2_top-4 == n2_bot ){
        valid_division = true;
        face_done[0] = 4; face_done[1] = 5;
        createEdge( verts[n1_top], verts[n2_top], quadToTri_edges );
        createEdge( verts[n1_top], verts[n2_top], edges_new );
        createEdge( verts[n1_bot], verts[n2_bot], quadToTri_edges );
        createEdge( verts[n1_bot], verts[n2_bot], edges_new );
      }
    }

    // pyramid with top opposite degenerate corner
    if( !valid_division ){
      if( ( n1_top == (degen_ind+2)%4+4 || n2_top == (degen_ind+2)%4+4 ||
            p_top_is_free ) &&
          ( n2_lat1 == (degen_ind+2)%4+4 || p_lat1_is_free ) &&
          ( n1_lat2 == (degen_ind+2)%4+4 || p_lat2_is_free ) ){
        valid_division = true;
        if( p_top_is_free ){
          n1_top = degen_ind+4; n2_top = (degen_ind+2)%4+4;
        }
        if( p_lat1_is_free ){
          n1_lat1 = (degen_ind+1)%4; n2_lat1 = (degen_ind+2)%4+4;
        }
        if( p_lat2_is_free ){
          n1_lat2 = (degen_ind+2)%4+4; n2_lat2 = (degen_ind+3)%4;
        }
        face_done[0] = 5;
        face_done[1] = (degen_ind+1)%4;
        face_done[2] = (degen_ind+2)%4;
        createEdge( verts[n1_top], verts[n2_top], quadToTri_edges );
        createEdge( verts[n1_top], verts[n2_top], edges_new );
      }
      else if( ( n1_bot == (degen_ind+2)%4 || n2_bot == (degen_ind+2)%4 ||
                 p_bot_is_free ) &&
               ( n2_lat1 == (degen_ind+2)%4 || p_lat1_is_free ) &&
               ( n1_lat2 == (degen_ind+2)%4 || p_lat2_is_free ) ){
        valid_division = true;
        if( p_bot_is_free ){
          n1_bot = degen_ind; n2_bot = (degen_ind+2)%4;
        }
        if( p_lat1_is_free ){
          n1_lat1 = (degen_ind+1)%4+4; n2_lat1 = (degen_ind+2)%4;
        }
        if( p_lat2_is_free ){
          n1_lat2 = (degen_ind+2)%4; n2_lat2 = (degen_ind+3)%4+4;
        }
        face_done[0] = 4;
        face_done[1] = (degen_ind+1)%4;
        face_done[2] = (degen_ind+2)%4;
        createEdge( verts[n1_bot], verts[n2_bot], quadToTri_edges );
        createEdge( verts[n1_bot], verts[n2_bot], edges_new );

      }

      if( valid_division ){
        createEdge( verts[n1_lat1], verts[n2_lat1], quadToTri_edges );
        createEdge( verts[n1_lat1], verts[n2_lat1], edges_new );
        createEdge( verts[n1_lat2], verts[n2_lat2], quadToTri_edges );
        createEdge( verts[n1_lat2], verts[n2_lat2], edges_new );
      }
    }

    // Pyramid top on corner NOT opposite to degenerate corner
    if( !valid_division ){
      // pyramid top on top face
      if( (n1_top >= 0 && n1_top != (degen_ind+2)%4+4 && n2_top != (degen_ind+2)%4+4) ||
          p_top_is_free ){
        if( n1_lat1 == (degen_ind+1)%4+4 || p_lat1_is_free ){
          valid_division = true;
          face_done[0] = (degen_ind+1)%4;
          if( p_lat1_is_free ){
            n1_lat1 = (degen_ind+1)%4+4; n2_lat1 = (degen_ind+2)%4;
          }
          createEdge( verts[n1_lat1], verts[n2_lat1], quadToTri_edges );
          createEdge( verts[n1_lat1], verts[n2_lat1], edges_new );
        }
        else if( n2_lat2 == (degen_ind+3)%4+4 || p_lat2_is_free ){
          valid_division = true;
          face_done[0] = (degen_ind+2)%4;
          if( p_lat2_is_free ){
            n1_lat2 = (degen_ind+2)%4; n2_lat2 = (degen_ind+3)%4+4;
          }
          createEdge( verts[n1_lat2], verts[n2_lat2], quadToTri_edges );
          createEdge( verts[n1_lat2], verts[n2_lat2], edges_new );
        }
        if( valid_division ){
          face_done[1] = 5;
          if( p_top_is_free ){
            n1_top = (degen_ind+1)%4+4; n2_top = (degen_ind+3)%4+4;
          }
          createEdge( verts[n1_top], verts[n2_top], quadToTri_edges );
          createEdge( verts[n1_top], verts[n2_top], edges_new );
        }
      }
      // pyramid top on bottom face
      if( (!valid_division && n1_bot >= 0 &&
           n1_bot != (degen_ind+2)%4 && n2_bot != (degen_ind+2)%4) ||
          p_bot_is_free ){
        if( n1_lat1 == (degen_ind+1)%4 || p_lat1_is_free ){
          valid_division = true;
          face_done[0] = (degen_ind+1)%4;
          if( p_lat1_is_free ){
            n1_lat1 = (degen_ind+1)%4; n2_lat1 = (degen_ind+2)%4+4;
          }
          createEdge( verts[n1_lat1], verts[n2_lat1], quadToTri_edges );
          createEdge( verts[n1_lat1], verts[n2_lat1], edges_new );
        }
        else if( n2_lat2 == (degen_ind+3)%4 || p_lat2_is_free ){
          valid_division = true;
          face_done[0] = (degen_ind+2)%4;
          if( p_lat2_is_free ){
            n1_lat2 = (degen_ind+2)%4+4; n2_lat2 = (degen_ind+3)%4;
          }
          createEdge( verts[n1_lat2], verts[n2_lat2], quadToTri_edges );
          createEdge( verts[n1_lat2], verts[n2_lat2], edges_new );
        }
        if( valid_division ){
          face_done[1] = 4;
          if( p_bot_is_free ){
            n1_bot = (degen_ind+1)%4; n2_bot = (degen_ind+3)%4;
          }
          createEdge( verts[n1_bot], verts[n2_bot], quadToTri_edges );
          createEdge( verts[n1_bot], verts[n2_bot], edges_new );
        }
      }
    }
    // see if the lateral diagonals have non-adjoining diagonals
    if( !valid_division ){
      if( ( n1_lat1 == (degen_ind+1)%4 || p_lat1_is_free ) &&
          ( n1_lat2 == (degen_ind+2)%4 || p_lat2_is_free ) ){
        valid_division = true;
        n1_lat1 = (degen_ind+1)%4;
        n2_lat1 = (degen_ind+2)%4+4;
        n1_lat2 = (degen_ind+2)%4;
        n2_lat2 = (degen_ind+3)%4+4;
      }
      else if( ( n1_lat1 == (degen_ind+1)%4+4 || p_lat1_is_free ) &&
          ( n1_lat2 == (degen_ind+2)%4+4 || p_lat2_is_free ) ){
        valid_division = true;
        n1_lat1 = (degen_ind+1)%4+4;
        n2_lat1 = (degen_ind+2)%4;
        n1_lat2 = (degen_ind+2)%4+4;
        n2_lat2 = (degen_ind+3)%4;
      }
      if( valid_division ){
        face_done[0] = (degen_ind+1)%4;
        face_done[1] = (degen_ind+2)%4;
        createEdge( verts[n1_lat1], verts[n2_lat1], quadToTri_edges );
        createEdge( verts[n1_lat1], verts[n2_lat1], edges_new );
        createEdge( verts[n1_lat2], verts[n2_lat2], quadToTri_edges );
        createEdge( verts[n1_lat2], verts[n2_lat2], edges_new );
      }
    }

    if( valid_division )
      break;
  }


  // if no subdivisiion, still take care of any adjustable but required diagonals not yet added
  for(unsigned int s = 0; s < face_types["adj_diag"].size(); s++ ){
    int ind = face_types["adj_diag"][s];
    if( ind != face_done[0] && ind != face_done[1] && ind != face_done[2] ){
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges  );
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new  );
    }
  }

  // if no division top found, need internal vertex.
  if( !valid_division ){
    std::pair<unsigned int, unsigned int> jkpair(j,k);
    problems[elem].insert(jkpair);
    problems_new[elem].insert(jkpair);
  }

}  // end of addEdgesForQuadToTriOnePtDegenHexa()



// Divide a fully non-degenerate hexahedron by brute force.
static void addEdgesForQuadToTriFullHexa( GRegion *gr, MElement *elem, ExtrudeParams *ep,
                                         int j, int k, std::vector<MVertex *> verts,
                                         std::map<std::string, std::vector<int> > &face_types,
                                         std::set<std::pair<MVertex*, MVertex*> > &edges_new,
                                         std::set<std::pair<MVertex*, MVertex*> > &forbidden_new,
                                         std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                         std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                         std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                         std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                         std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                         std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                                         std::vector<int> nfix1, std::vector<int> nfix2,
                                         std::vector<int> nadj1, std::vector<int> nadj2,
                                         std::vector<int> free_flag )
{

  // There are 4 main possibilities for minimum diags to guarantee slice:
  // 1. Three diagonals at a corner
  // 2. One PAIR of opposite diagonals, ABSOLUTELY ALL OTHER FACES FORBIDDEN
  // 2. Two PAIRS of opposite diags
  // 3. One PAIR of opposite diags PLUS a vertex with two ADDITIONAL diags meeting on it.

  if( !ep )
    return;

  // numbers of each type of face
  // int num_degen = face_types["degen"].size();
  // int num_single_tri = face_types["single_tri"].size();
  // int num_recomb = face_types["recomb"].size();
  int num_fixed_diag = face_types["fixed_diag"].size();
  int num_adj_diag = face_types["adj_diag"].size();
  int num_free = face_types["free"].size();

  // If all faces are free, then diagonalize the three faces adjacent to vertex with
  //  smallest vertex pointer
  if( num_free >= 6 ){
    int ind_low = getIndexForLowestVertexPointer(verts);
    int add = ind_low < 4 ? 0 : 4;

    createEdge( verts[ind_low], verts[(ind_low-add+2)%4+add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+2)%4+add], edges_new );
    createEdge( verts[ind_low], verts[(ind_low-add+1)%4+4-add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+1)%4+4-add], edges_new );
    createEdge( verts[ind_low], verts[(ind_low-add+3)%4+4-add], quadToTri_edges );
    createEdge( verts[ind_low], verts[(ind_low-add+3)%4+4-add], edges_new );
    return;
  }


  // Start the loop to progressively become more permissive in what diagonals to allow for
  // subdivision.
  // On t-loop, select types of diagonals to look for.
  // t = 0, fixed and preferred adjustables.
  // t = 1, include non-preferred adjustables with lowest vertex.
  // t = 2, include free face diagonal, lowest vertex.
  // t = 3, on adjustable or free faces, take any diagonal that works.

  // this variable records the faces selected for diagonalization
  int face_done[4];
  for(int p = 0; p < 4; p++ )
    face_done[p] = -1-p;

  // if find just two diagonals that could slice a prism with no other diags, remember ('hold') those diagonals until
  // end of loop in the following 'hold' variables.
  // Might have to resort to forbidding free surfaces and cutting two prisms only.
  // don't really want to forbid surfaces, though...that's why two prisms are not immediately
  // cut when found.
  int p1_hold = -1, p2_hold = -2;  // if found two opposite diags that could work alone
  int n1_hold[2]={0,0}, n2_hold[2]={0,0};      // hold diag nodes for p1_hold, p2_hold.
  bool valid_division = false;

  for( int t = 0; t < 4; t++ ){

    // variables that hold the face diagonal nodes.
    int n1[6], n2[6];

    // if the face is completely free (t==3), face_is_free = true;
    bool face_is_free[6];

    // set default values of the n variables
    // to unique negative numbers; bool to false.
    for( int p = 0; p < 6; p++ ){
      n1[p] = -p*p-p-1;
      n2[p] = -p*p-p-2;
      face_is_free[p] = false;
    }

    for( int p = 0; p < 6; p++ ){
      // fixed diagonals
      if( nfix1[p] >= 0 ){
        n1[p] = nfix1[p]; n2[p] = nfix2[p];
      }
      // preferred adjustable diagonals
      else if( !t && nadj1[p] >= 0 ){
        n1[p] = nadj1[p]; n2[p] = nadj2[p];
      }
      // choose lowest vertex for t < 3, any vertex for t == 3
      else if( (t >= 1 && t < 3 && nadj1[p] >= 0) ||
               (t == 2 && free_flag[p]) ){
        if( p < 4 ){
          if( (verts[p] < verts[(p+1)%4] &&
               verts[p] < verts[p+4]) ||
              (verts[(p+1)%4+4] < verts[(p+1)%4] &&
               verts[(p+1)%4+4] < verts[p+4]) ){
            n1[p] = p; n2[p] = (p+1)%4+4;
          }
          else{
            n1[p] = p+4; n2[p] = (p+1)%4;
          }
        }
        else{
          int add = p==4 ? 0 : 4;
          if( (verts[0+add] < verts[1+add] && verts[0+add] < verts[3+add]) ||
              (verts[2+add] < verts[1+add] && verts[2+add] < verts[3+add]) ){
            n1[p] = 0+add; n2[p] = 2+add;
          }
          else{
            n1[p] = 1+add; n2[p] = 3+add;
          }
        }
      }
      else if( t==3 && (nadj1[p] >= 0 || free_flag[p]) )
        face_is_free[p] = true;
    }

    // Now perform the tests to find the valid subdivision

    // first, do the test to find opposite aligned diagonals for "prism slice through"
    // Not verified, but I believe this gives better quality elements than 3-diag corners
    if( !valid_division ){
      for( int p = 0; p < 3; p++ ){
        int p1 = -1, p2 = -2;
        // prism slicing faces
        if( p > 1){
          p1 = 4; p2 = 5;
        }
        else{
          p1 = p; p2 = (p+2)%4;
        }

        // if these two faces do not work for opposite aligned diagonals, continue
        if( n1[p1] < 0 && !face_is_free[p1] ||
            n1[p2] < 0 && !face_is_free[p2] )
          continue;
        if( n1[p1] >= 0 && n1[p2] >= 0 ){
          if( p1 < 4 ){
            if( ( n1[p1] == p1 || n2[p1] == p1 ) &&
                  n1[p2] != p2+4 && n2[p2] != p2+4 ||
                ( n1[p1] == p1+4 || n2[p1] == p1+4 ) &&
                  n1[p2] != p2 && n2[p2] != p2 )
              continue;
          }
          else{
            int add = p1==4 ? 4 : -4;
            if( n1[p1]+add != n1[p2] && n2[p1]+add !=  n1[p2] )
              continue;
          }
        }

        // if TWO faces are free, set one to the lowest pointer
        if( face_is_free[p1] && face_is_free[p2] ){
          face_is_free[p1] = false;
          if( p1 < 4 ){
            if( (verts[p1] < verts[p1+4] && verts[p1] < verts[(p1+1)%4]) ||
                (verts[(p1+1)%4+4] < verts[p1+4] &&
                 verts[(p1+1)%4+4] < verts[(p1+1)%4]) ){
              n1[p1] = p1;
              n2[p1] = (p1+1)%4+4;
            }
            else{
              n1[p1] = (p1+4);
              n2[p1] = (p1+1)%4;
            }
          }
          else{
            int add = p1==4 ? 0 : 4;
            if( (verts[0+add] < verts[1+add] && verts[0+add] < verts[3+add]) ||
                (verts[2+add] < verts[1+add] && verts[2+add] < verts[3+add]) ){
              n1[p1] = 0+add;
              n2[p1] = 2+add;
            }
            else{
              n1[p1] = 1+add;
              n2[p1] = 3+add;
            }
          }
        }

        // if one and ONLY one face is free, go ahead and set it to match the other now.
        if( n1[p1] >= 0 && face_is_free[p2] ){
          if( p1 < 4 ){
            if( n1[p1] == p1 || n2[p1] == p1 ){
              n1[p2] = p2+4;
              n2[p2] = (p2+1)%4;
            }
            else{
              n1[p2] = p2;
              n2[p2] = (p2+1)%4+4;
            }
          }
          else{
            int add = p1==4 ? 4 : -4;
            n1[p2] = n1[p1]+add;
            n2[p2] = n2[p1]+add;
          }
          face_is_free[p2] = false;
        }
        else if( n1[p2] >= 0 && face_is_free[p1] ){
          if( p1 < 4 ){
            if( n1[p2] == p2 || n2[p2] == p2 ){
              n1[p1] = p1+4;
              n2[p1] = (p1+1)%4;
            }
            else{
              n1[p1] = p1;
              n2[p1] = (p1+1)%4+4;
            }
          }
          else{
            int add = p2==4 ? 4 : -4;
            n1[p1] = n1[p2]+add;
            n2[p1] = n2[p2]+add;
          }
          face_is_free[p1] = false;
        }

        // In case the whole loop finishes and
        // cannot make further diagonalizations on any faces to make the prism slice work,
        // AND if there are no oter required diagonals other than among these two diagonals,
        // then it will be possible to come back to these two opposing diagonals to make a
        // simple two-prism slice.  So, if there are no other diags, hold these two valid opposing
        // diagonals in case we want to come back to them later to just have two
        // opposing diagonals with the other faces forbidden.
        if( p1_hold < 0 || p2_hold < 0 ){
          int required_diag_count = 0;
          if( nfix1[p1] >= 0 || nadj1[p1] >= 0 )
            required_diag_count++;
          if( nfix1[p2] >= 0 || nadj1[p2] >= 0 )
            required_diag_count++;
          if( p1_hold < 0 && num_fixed_diag + num_adj_diag <= required_diag_count ){
            p1_hold = p1;
            p2_hold = p2;
            n1_hold[0] = n1[p1];
            n2_hold[0] = n2[p1];
            n1_hold[1] = n1[p2];
            n2_hold[1] = n2[p2];
          }
        }

        // Two tests to see if this prism slice-through will work:
        // 1: if there is another set of opposing faces with aligned diagonals.
        // 2: if two diagonals on one of the remaining 4 faces meet, valid.


        // Test 1: Another set of opposite, aligned diagonals.
        for( int s = 0; s < 3; s++ ){
          if( s == p1 || (s>1 && (p1==4 || p1==5)) )
            continue;
          int s1, s2;
          if( s > 1){
            s1 = 4; s2 = 5;
          }
          else{
            s1 = s; s2 = (s+2)%4;
          }
          // if these two faces do not work for opposite aligned diagonals, continue
          if( (n1[s1] < 0 && !face_is_free[s1]) ||
              (n1[s2] < 0 && !face_is_free[s2]) )
            continue;
          if( n1[s1] >= 0 && n1[s2] >= 0 ){
            if( s1 < 4 ){
              if( ( ( n1[s1] == s1 || n2[s1] == s1 ) &&
                    n1[s2] != s2+4 && n2[s2] != s2+4 ) ||
                  ( ( n1[s1] == s1+4 || n2[s1] == s1+4 ) &&
                    n1[s2] != s2 && n2[s2] != s2 ) )
                continue;
            }
            else{
              int add = s1==4 ? 4 : -4;
              if( n1[s1]+add != n1[s2] && n2[s1]+add !=  n1[s2] )
                continue;
            }
          }

          valid_division = true;
          face_done[0] = p1;
          face_done[1] = p2;
          face_done[2] = s1;
          face_done[3] = s2;

          // if TWO faces are free, set one to the lowest pointer
          if( face_is_free[s1] && face_is_free[s2] ){
            face_is_free[s1] = false;
            if( s1 < 4 ){
              if( (verts[s1] < verts[s1+4] && verts[s1] < verts[(s1+1)%4]) ||
                  (verts[(s1+1)%4+4] < verts[s1+4] &&
                   verts[(s1+1)%4+4] < verts[(s1+1)%4]) ){
                n1[s1] = s1;
                n2[s1] = (s1+1)%4+4;
              }
              else{
                n1[s1] = (s1+4);
                n2[s1] = (s1+1)%4;
              }
            }
            else{
              int add = s1==4 ? 0 : 4;
              if( (verts[0+add] < verts[1+add] && verts[0+add] < verts[3+add]) ||
                  (verts[2+add] < verts[1+add] && verts[2+add] < verts[3+add]) ){
                n1[s1] = 0+add;
                n2[s1] = 2+add;
              }
              else{
                n1[s1] = 1+add;
                n2[s1] = 3+add;
              }
            }
          }

          // if ONLY one face is free, go ahead and set it to match the other now.
          if( n1[s1] >= 0 && face_is_free[s2] ){
            if( s1 < 4 ){
              if( n1[s1] == s1 || n2[s1] == s1 ){
                n1[s2] = s2+4;
                n2[s2] = (s2+1)%4;
              }
              else{
                n1[s2] = s2;
                n2[s2] = (s2+1)%4+4;
              }
            }
            else{
              int add = s1==4 ? 4 : -4;
              n1[s2] = n1[s1]+add;
              n2[s2] = n2[s1]+add;
            }
            face_is_free[s2] = false;
          }
          else if( n1[s2] >= 0 && face_is_free[s1] ){
            if( s1 < 4 ){
              if( n1[s2] == s2 || n2[s2] == s2 ){
                n1[s1] = s1+4;
                n2[s1] = (s1+1)%4;
              }
              else{
                n1[s1] = s1;
                n2[s1] = (s1+1)%4+4;
              }
            }
            else{
              int add = s2==4 ? 4 : -4;
              n1[s1] = n1[s2]+add;
              n2[s1] = n2[s2]+add;
            }
            face_is_free[s1] = false;
          }

          if( valid_division )
           break;
        }


        // Test 2: any vertex has two diagonals meeting at it, NOT including the diagonals on
        // p1, p2;
        if( !valid_division ){
          for( int s = 0; s < 8; s++ ){  // looping over vertices now, be careful
            int add = s<4 ? 0 : 4;
            std::vector<int> faces;
            faces.assign(2,-1);
            int third_face = s<4 ? 4 : 5;
            int count_diags = 0;
            if( s-add != p1 && s-add != p2 &&
                (  n1[(s-add)] == s || n2[(s-add)] == s || face_is_free[(s-add)] ) ){
              faces[count_diags] = s-add;
              count_diags++;
            }
            if( (s-add+3)%4 != p1 && (s-add+3)%4 != p2 &&
                ( n1[(s-add+3)%4] == s || n2[(s-add+3)%4] == s || face_is_free[(s-add+3)%4] ) ){
              faces[count_diags] = (s-add+3)%4;
              count_diags++;
            }
            if( count_diags < 2 && third_face != p1 && third_face != p2 &&
                ( n1[third_face] == s || n2[third_face] == s || face_is_free[third_face] ) ){
              faces[count_diags] = third_face;
              count_diags++;
            }

            // if valid subdivision NOT found
            if( count_diags < 2 )
              continue;

            // if valid subdivision found

            valid_division = true;

            face_done[0] = p1;
            face_done[1] = p2;
            face_done[2] = faces[0];
            face_done[3] = faces[1];

            if( face_is_free[s-add] ){
              n1[s-add] = s;
              n2[s-add] = (s-add+1)%4+4-add;
            }
            if( face_is_free[(s-add+3)%4] ){
              n1[(s-add+3)%4] = s;
              n2[(s-add+3)%4] = (s-add+3)%4+4-add;
            }
            if( face_is_free[third_face] ){
              n1[third_face] = s;
              n2[third_face] = (s-add+2)%4+add;
            }

            if( valid_division )
              break;
          }
        }  // end of test 2

        if( valid_division ){
          createEdge( verts[n1[face_done[0]]], verts[n2[face_done[0]]], quadToTri_edges );
          createEdge( verts[n1[face_done[0]]], verts[n2[face_done[0]]], edges_new );
          createEdge( verts[n1[face_done[1]]], verts[n2[face_done[1]]], quadToTri_edges );
          createEdge( verts[n1[face_done[1]]], verts[n2[face_done[1]]], edges_new );
          createEdge( verts[n1[face_done[2]]], verts[n2[face_done[2]]], quadToTri_edges );
          createEdge( verts[n1[face_done[2]]], verts[n2[face_done[2]]], edges_new );
          createEdge( verts[n1[face_done[3]]], verts[n2[face_done[3]]], quadToTri_edges );
          createEdge( verts[n1[face_done[3]]], verts[n2[face_done[3]]], edges_new );
          break;
        }
      }  // end of p loop over first set of opposite faces
    }

    // Test for 3 diagonals on a corner.
    if( !valid_division ){
      for( int p = 0; p < 8; p++ ){  // looping over vertices now, be careful
        int add = p<4 ? 0 : 4;
        int third_face = p<4 ? 4 : 5;
        if( ( n1[(p-add)] == p || n2[(p-add)] == p || face_is_free[(p-add)] ) &&
            ( n1[(p-add+3)%4] == p || n2[(p-add+3)%4] == p || face_is_free[(p-add+3)%4] ) &&
            ( n1[third_face]  == p || n2[third_face] == p || face_is_free[third_face] ) ){
          valid_division = true;
          if( face_is_free[p-add] ){
            n1[p-add] = p;
            n2[p-add] = (p-add+1)%4+4-add;
          }
          if( face_is_free[(p-add+3)%4] ){
            n1[(p-add+3)%4] = p;
            n2[(p-add+3)%4] = (p-add+3)%4+4-add;
          }
          if( face_is_free[third_face] ){
            n1[third_face] = p;
            n2[third_face] = (p-add+2)%4+add;
          }

          face_done[0] = (p-add);
          face_done[1] = (p-add+3)%4;
          face_done[2] = third_face;

          createEdge( verts[n1[(p-add)]], verts[n2[(p-add)]], quadToTri_edges );
          createEdge( verts[n1[(p-add)]], verts[n2[(p-add)]], edges_new );
          createEdge( verts[n1[(p-add+3)%4]], verts[n2[(p-add+3)%4]], quadToTri_edges );
          createEdge( verts[n1[(p-add+3)%4]], verts[n2[(p-add+3)%4]], edges_new );
          createEdge( verts[n1[third_face]], verts[n2[third_face]], quadToTri_edges );
          createEdge( verts[n1[third_face]], verts[n2[third_face]], edges_new );
          break;
        }
      }
    }

    if( valid_division )
      break;

  }  // end of t loop (outer loop)

  // If no valid division yet but yet there were two opposite faces once
  // ( if this won't work, should be the case that p1_hold < 0 here )
  if( !valid_division && p1_hold >= 0 ){
    valid_division = true;
    face_done[0] = p1_hold;
    face_done[1] = p2_hold;
    createEdge( verts[n1_hold[0]], verts[n2_hold[0]], quadToTri_edges );
    createEdge( verts[n1_hold[0]], verts[n2_hold[0]], edges_new );
    createEdge( verts[n1_hold[1]], verts[n2_hold[1]], quadToTri_edges );
    createEdge( verts[n1_hold[1]], verts[n2_hold[1]], edges_new );

    // create forbidden faces
    for(unsigned int s = 0; s < face_types["free"].size(); s++ ){
      int s_tmp = face_types["free"][s];
      std::vector<MVertex*> v_free;
      if( s_tmp == p1_hold || s_tmp == p2_hold )
        continue;
      if( s_tmp < 4 ){
        v_free.push_back(verts[s_tmp]); v_free.push_back(verts[(s_tmp+1)%4]);
        v_free.push_back(verts[(s_tmp+1)%4+4]); v_free.push_back(verts[s_tmp+4]);
      }
      else{
        int add = s_tmp==4 ? 0 : 4;
        v_free.push_back(verts[add]); v_free.push_back(verts[add+1]);
        v_free.push_back(verts[add+2]); v_free.push_back(verts[add+3]);
      }
      createForbidden( v_free, forbidden_edges );
      createForbidden( v_free, forbidden_new );
    }
  }

  // take care of any adjustable but required diagonals not yet added
  for(unsigned int s = 0; s < face_types["adj_diag"].size(); s++ ){
    int ind = face_types["adj_diag"][s];
    if( ind == face_done[0] || ind == face_done[1] || ind == face_done[2] || ind == face_done[3] )
      continue;
    createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges  );
    createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new  );
  }

  // if no valid division found, problematic.
  if( !valid_division ){
    std::pair<unsigned int, unsigned int> jkpair(j,k);
    problems[elem].insert(jkpair);
    problems_new[elem].insert(jkpair);
  }

}  // end of addEdgesForQuadToTriFullHexa();


// Generate face diagonals to subdivide hexahedra by BRUTE FORCE.  Not recommended for general use, but it
// is required for some elements which have all vertices on an external region boundary.
// Added 2010-01-29
static void bruteForceEdgeQuadToTriHexa( GRegion *gr, MElement *elem,
                                     int j, int k, std::vector<MVertex *> verts,
                                      std::map<std::string, std::vector<int> > &face_types,
                                      std::set<std::pair<MVertex*, MVertex*> > &edges_new,
                                      std::set<std::pair<MVertex*, MVertex*> > &forbidden_new,
                                      std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                      std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                      std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                      std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                                      std::vector<int> nfix1, std::vector<int> nfix2,
                                      std::vector<int> nadj1, std::vector<int> nadj2,
                                      std::vector<int> free_flag )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In bruteForceEdgeQuadToTriHexa(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In bruteForceEdgeQuadToTriHexa(), invalid model for region "
               "%d.", gr->tag() );
    return;
  }

  // now find and verify the source and the top of region

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In bruteForceEdgeQuadToTriHexa(), invalid source face for region "
               "%d.", gr->tag() );
    return;
  }

  // verify number of vertices
  int n_lat;
  if( verts.size() != 8 ){
    Msg::Error("In bruteForceEdgeQuadToTriHexa(), number of vertices not equal 8.");
    return;
  }
  else
    n_lat = 4;

  // numbers of each type of face
  //int num_degen = face_types["degen"].size();
  //int num_single_tri = face_types["single_tri"].size();
  int num_recomb = face_types["recomb"].size();
  //int num_fixed_diag = face_types["fixed_diag"].size();
  int num_adj_diag = face_types["adj_diag"].size();
  //int num_free = face_types["free"].size();


  // Make sure all faces marked forbidden in face_types have all diagonals in forbidden_edges;
  for( int p = 0; p < num_recomb; p++){
    int ind = face_types["recomb"][p];
    std::vector<MVertex*> v;
    if( ind == 4 || ind == 5 ){
      int add = (ind == 4 ) ? 0 : 4;
      v.push_back(verts[0+add]); v.push_back(verts[1+add]); v.push_back(verts[2+add]);
      v.push_back(verts[3+add]);
    }
    else{
      v.push_back(verts[ind]); v.push_back(verts[(ind+1)%4]); v.push_back(verts[(ind+1)%4+4]);
      v.push_back(verts[ind+4]);
    }

    createForbidden(v, forbidden_new );
    createForbidden(v, forbidden_edges );
  }


  // If this element is marked problematic, make all the adjustable diags (none should exist if it's already
  // marked as a problem, but just make sure) and return.
  std::pair<unsigned int, unsigned int> jkpair(j,k);
  if( problems.find(elem) != problems.end() && problems[elem].count(jkpair) ){
    for( int s = 0; s < num_adj_diag; s++ ){
      int ind = face_types["adj_diag"][s];
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges  );
      createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new  );
    }
    return;
  }

  // test for right number of triangles with degenerate edges
  if( (face_types["single_tri"].size() != 0 && face_types["single_tri"].size() != 2) ||
      (face_types["degen"].size() && face_types["single_tri"].size() != 2) ){
    Msg::Error("In bruteForceEdgeQuadToTriHexa(), bad degenerated extrusion encountered.");
    std::pair<unsigned int, unsigned int> jkpair(j,k);
    problems[elem].insert(jkpair);
    problems_new[elem].insert(jkpair);
    if( num_adj_diag ){
      int ind = face_types["adj_diag"][0];
      if( nadj1[ind] >= 0 ){
        createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new );
        createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges );
      }
    }
    return;
  }

  // if there are not enough diagonals:
  if( 6 - face_types["single_tri"].size() - face_types["recomb"].size() < 2 ){
    // Can't be meshed without internal vertex
    if( face_types["adj_diag"].size() + face_types["fixed_diag"].size() ){
      std::pair<unsigned int, unsigned int> jkpair(j,k);
      problems[elem].insert(jkpair);
      problems_new[elem].insert(jkpair);
      for(unsigned int s = 0; s < face_types["adj_diag"].size(); s++ ){
        int ind = face_types["adj_diag"][s];
        createEdge( verts[nadj1[ind]], verts[nadj2[ind]], quadToTri_edges  );
        createEdge( verts[nadj1[ind]], verts[nadj2[ind]], edges_new  );
      }
    }
    // set the (at most) one free surface to forbidden and return
    else if( face_types["free"].size() ){
      int p_tmp = face_types["free"][0];
      std::vector<MVertex*> v_free;
      if( p_tmp < 4 ){
        v_free.push_back(verts[p_tmp]);
        v_free.push_back(verts[(p_tmp+1)%4]);
        v_free.push_back(verts[(p_tmp+1)%4+4]);
        v_free.push_back(verts[p_tmp+4]);
      }
      else{
        int add = p_tmp==4 ? 0 : 4;
        v_free.push_back(verts[add]);
        v_free.push_back(verts[add+1]);
        v_free.push_back(verts[add+2]);
        v_free.push_back(verts[add+3]);
      }
      createForbidden( v_free, forbidden_edges );
      createForbidden( v_free, forbidden_new );
    }
    return;
  }


  // Start looking at the different shape possibilities:


  // First shape: A PRISM
  // Only two possibilities.  Either the bottom can be divided along same diagonal as the top,
  // or the one quad side can be divided joining the top diagonal. Otherwise, problem.
  if( face_types["degen"].size() ){
    addEdgesForQuadToTriTwoPtDegenHexa( gr, elem, ep, j, k, verts, face_types, edges_new, forbidden_new,
                                 quadToTri_edges, forbidden_edges, lat_tri_diags, problems_new,
                                 problems, pos, nfix1, nfix2, nadj1, nadj2, free_flag );
    return;
  }

  // Second shape type: DEGENERATED HEXAHEDRON
  // Since this shape can be divided to create legitimate tets and/or pyramids,
  // let us try it.
  if( !face_types["degen"].size() && face_types["single_tri"].size() == 2 ){
    addEdgesForQuadToTriOnePtDegenHexa( gr, elem, ep, j, k, verts, face_types, edges_new, forbidden_new,
                                 quadToTri_edges, forbidden_edges, lat_tri_diags, problems_new,
                                 problems, pos, nfix1, nfix2, nadj1, nadj2, free_flag );
    return;
  }

  // Third SHAPE: FULL HEXAHEDRON
  // There are 4 main possibilities for minimum diags to guarantee slice:
  // 1. Three diagonals at a corner
  // 2. One PAIR of opposite diagonals, ABSOLUTELY ALL OTHER FACES FORBIDDEN
  // 2. Two PAIRS of opposite diags
  // 3. One PAIR of opposite diags PLUS a vertex with two ADDITIONAL diags meeting on it.
  if( !face_types["single_tri"].size() && !face_types["degen"].size() ){

    addEdgesForQuadToTriFullHexa( gr, elem, ep, j, k, verts, face_types, edges_new, forbidden_new,
                                  quadToTri_edges, forbidden_edges, lat_tri_diags, problems_new,
                                  problems, pos, nfix1, nfix2, nadj1, nadj2, free_flag );
    return;
  }

} // end of bruteForceEdgeQuadToTriHexa()



// This is a shortcut function to simply copy face diagonals all the way up a vertical column of extruded elements.
// This function may not save very many operations, but it is going to stay...
static int ExtrudeDiags( GRegion *gr, std::vector<MVertex*> v, unsigned int j_start,
                                    unsigned int k_start, unsigned int j_top, unsigned int k_top,
                                    MElement *elem, ExtrudeParams *loop_ep,
                                    std::set<std::pair<MVertex*, MVertex*> > &edges_new,
                                    std::set<std::pair<MVertex*, MVertex*> > &forbidden_new,
                                    std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                    std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                    std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                    std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                    std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  if( !loop_ep || !loop_ep->mesh.QuadToTri || !loop_ep->mesh.ExtrudeMesh ){
    Msg::Error("In ExtrudeDiags(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In ExtrudeDiags(), invalid model for region "
               "%d.", gr->tag() );
    return 0;
  }

  int elem_size = elem->getNumVertices();
  if( !( (v.size() == 6 && elem_size == 3) ||
         (v.size() == 8 && elem_size == 4) ) ){
    Msg::Error("In ExtrudeDiags(), vertex number mismatch "
               "between 2D source element and extruded volume.");
    return 0;
  }

  // first add the forbidden edges, then the new quadToTri_edges
  // w = 0 forbidden, w = 1 quadToTri_edges (fixed)
  for( int w = 0; w < 2; w++ ){
    std::set<std::pair<MVertex*, MVertex*> >::iterator it;
    std::set<std::pair<MVertex*, MVertex*> >::iterator it_start;
    std::set<std::pair<MVertex*, MVertex*> >::iterator it_end;
    it_start = (!w) ? forbidden_new.begin() : edges_new.begin();
    it_end =   (!w) ? forbidden_new.end()   : edges_new.end();

    for( it = it_start; it != it_end; it++ ){
      MVertex *v1, *v2;
      v1 = (*it).first; v2 = (*it).second;
      // find indices in v vector
      int ind1 = -1, ind2 = -1;
      for(unsigned int p = 0; p < v.size(); p++){
        if( v[p] == v1 )
          ind1 = p;
        if( v[p] == v2 )
          ind2 = p;
      }
      if( ind1 < 0 || ind2 < 0 ){
        Msg::Error("Error in ExtrudeDiags(): could not find vertex indices.");
        return 0;
      }
      // source verts:
      MVertex *sv1 = (ind1 < elem_size ) ? elem->getVertex(ind1) : elem->getVertex(ind1-elem_size);
      MVertex *sv2 = (ind2 < elem_size ) ? elem->getVertex(ind2) : elem->getVertex(ind2-elem_size);
      // extrude these two verts
      for( unsigned int j = j_start; j <= j_top; j++ ){
        int k_start_tmp = (j == j_start ) ? k_start+1 : 0;
        int k_stop = ( j == j_top ) ? k_top : loop_ep->mesh.NbElmLayer[j];
        for(int k = k_start_tmp; k < k_stop; k++ ){
          std::vector<MVertex*> v_extr = getExtrudedLateralVertices(sv1, sv2, gr, j, k, loop_ep, pos);
          if( v_extr.size() != 4 )
            return 0;
          if( !w ){
            // reorder v_ext
            MVertex *tmp = v_extr[2]; v_extr[2] = v_extr[3]; v_extr[3] = tmp;
            createForbidden( v_extr, forbidden_edges );
          }
          else{
            MVertex *v_final_1 = (ind1 < elem_size) ? v_extr[0] : v_extr[2];
            MVertex *v_final_2 = (ind2 < elem_size) ? v_extr[1] : v_extr[3];
            createEdge( v_final_1, v_final_2, quadToTri_edges );
          }
        }
      }
    }
  }

  // add problem elements
  std::pair<unsigned int, unsigned int> jk_start (j_start, k_start);
  std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > >::iterator itprob;

  if( problems_new.size() ){
    for( itprob = problems_new.begin(); itprob != problems_new.end(); itprob++ ){
      for( unsigned int j = j_start; j <= j_top; j++ ){
        int k_start_tmp = (j == j_start ) ? k_start+1 : 0;
        int k_stop = ( j == j_top ) ? k_top : loop_ep->mesh.NbElmLayer[j];
        for(int k = k_start_tmp; k < k_stop; k++ ){
          std::pair<unsigned int, unsigned int> pair_tmp (j, k);
          problems[(*itprob).first].insert(pair_tmp);
        }
      }
    }
  }

  return 1;
}


// Get set of locally fixed edges, forbidden edges, and all lateral surface diagonals.
// Fixed edges include top surface diagonals and any lateral surface diagonals that cannot be swapped.
// Added 2010-01-24
static bool QuadToTriGetRegionDiags(GRegion *gr,
                           std::set<std::pair<MVertex*,MVertex*> > &quadToTri_edges,
                           std::set<std::pair<MVertex*,MVertex*> > &forbidden_edges,
                           std::set<std::pair<MVertex*,MVertex*> > &lat_tri_diags,
                           std::set<MVertex *, MVertexLessThanLexicographic>  &pos)
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh )
    return false;

  GModel *model = gr->model();

  // find source face
  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source ){
    Msg::Error("In QuadToTriGetRegionDiags(), could not find source face "
               "%d for region %d.", std::abs( ep->geo.Source ),
               gr->tag() );
    return false;
  }

  // Find a source surface, find a COPIED_ENTITY that is the top surface,

  bool foundSource = false, foundTop = false;
  GFace *reg_top = NULL;
  std::list<GFace *> faces = gr->faces();
  std::list<GFace *>::iterator it = faces.begin();

  for( it = faces.begin(); it != faces.end(); it++ ){
    ExtrudeParams *face_tmp_ep = (*it)->meshAttributes.extrude;
    if( (*it) == reg_source )
      foundSource = true;
    else if( face_tmp_ep && face_tmp_ep->geo.Mode ==
        COPIED_ENTITY ){
      GFace *top_source_tmp = model->getFaceByTag(
                              std::abs( face_tmp_ep->geo.Source ) );
      if( !top_source_tmp ){
        Msg::Error("In QuadToTriGetRegionDiags(), could not find source face "
                   "%d for copied surface %d of region %d.",
                   std::abs( face_tmp_ep->geo.Source ),
                   (*it)->tag(), gr->tag() );
      }
      else if( top_source_tmp == reg_source ){
        foundTop = true;
        reg_top = (*it);
      }
    }
  }

  if( !foundTop )
    Msg::Warning("In QuadToTriGetRegionDiags(), could not find top face "
               "for region %d.", gr->tag() );


  if( !foundSource ){
    Msg::Error("In QuadToTriGetRegionDiags(), source face "
               "for region %d is not found in region face list.", gr->tag() );
    return false;
  }


  // Get Fixed and adjustable lateral diagonal element edges
  int counter = 0;
  for( it = faces.begin(); it != faces.end(); it++ ){
    counter++;
    // true if surface is a lateral...
    // ...The conditional is redundant for a reason.
    if( (*it) != reg_top && (*it) != reg_source &&
        IsSurfaceALateralForRegion(gr, *it) ){

      // take care of forbidden edges
      for( unsigned int i = 0; i < (*it)->quadrangles.size(); i++){
        std::vector<MVertex*> v;
        (*it)->quadrangles[i]->getVertices(v);
        createForbidden(v, forbidden_edges );
      }

      // at this point, if there are no triangles or if there are quads, continue
      if( !(*it)->triangles.size() || (*it)->quadrangles.size() )
        continue;

      ExtrudeParams *face_ep_tmp = (*it)->meshAttributes.extrude;
      // If face is shared with a neighbor region that ALREADY has elements,
      // if face is the source of the neighbor, if the neighbor is TRANSFINITE,
      // or if the face is not an EXTRUDED_ENTITY, then these edges are fixed.
      std::vector<GRegion *> neighbors;
      GetNeighborRegionsOfFace(*it, neighbors);
      GRegion *other_region = NULL;
      ExtrudeParams *oth_ep = NULL;
      ExtrudeParams *face_ep = (*it)->meshAttributes.extrude;
      if(neighbors.size() > 1){
        other_region = neighbors[0] != gr ? neighbors[0] : neighbors[1];
        oth_ep = other_region->meshAttributes.extrude;
      }
      bool is_fixed = false;

      // see if neighbor has already been meshed
      if( other_region &&
          ( other_region->pyramids.size() ||
            other_region->tetrahedra.size() ||
            other_region->hexahedra.size() ||
            other_region->prisms.size() ||
            other_region->polyhedra.size() ||
            other_region->getNumMeshElements() ) ){
        is_fixed = true;
      }
      // see if the diagonals are fixed for other reasons
      if( !( face_ep_tmp && face_ep_tmp->mesh.ExtrudeMesh &&
             face_ep_tmp->geo.Mode == EXTRUDED_ENTITY ) ||
          (other_region && oth_ep && oth_ep->mesh.ExtrudeMesh &&
           (*it) == model->getFaceByTag( std::abs( oth_ep->geo.Source ) ) ) ||
          (other_region && other_region->meshAttributes.Method == MESH_TRANSFINITE) ){
        is_fixed = true;
      }

      // Now extrude all vertices and find diagonal edges.
      // NOTE: This seems like the "hard way" because it is written to work
      // even if the original lateral for the region is replaced by another structured
      // surface.
      // (first find common edge between source and this lateral)
      std::list<GEdge*> source_edges = reg_source->edges();
      std::list<GEdge*> face_edges = (*it)->edges();
      std::list<GEdge*>::iterator itse;
      GEdge *common = NULL;
      int common_count = 0;
      for( itse = source_edges.begin(); itse != source_edges.end(); itse++ ){
        if( std::find( face_edges.begin(), face_edges.end(), (*itse) ) !=
            face_edges.end() ){
          common = (*itse); common_count++; }
      }
      if( !common || common_count != 1 )
        Msg::Error("In QuadToTriGetRegionDiags(), lateral surface and "
                   "source surface of region %d do not share one and only one edge.",
                   gr->tag() );


      // now find face source edge, if it exists:
      GEdge *face_source = NULL;
      if( face_ep && face_ep->mesh.ExtrudeMesh &&
           face_ep->geo.Mode == EXTRUDED_ENTITY ){
        face_source = model->getEdgeByTag( std::abs( face_ep->geo.Source ) );
        if( !face_source ){
          Msg::Error("In QuadToTriGetRegionDiags(), extruded face %d "
                     "has invalid source.", (*it)->tag() );
        }
      }
      // set up vertex finding loops according to whether this surface
      // is extruded or not (alternative to extruded is unrecombined transfinite surf with vertices
      // coincidentally in the right place).
      unsigned int num_lines = 0;
      std::vector<MLine *> *source_lines = NULL;
      ExtrudeParams *loop_ep = NULL;
      if( face_source ){
        num_lines = face_source->lines.size();
        source_lines = &face_source->lines;
        loop_ep = face_ep;
      }
      else{
        num_lines = common->lines.size();
        source_lines = &common->lines;
        loop_ep = ep;
      }
      unsigned int index_guess = 0;

      for( unsigned int i = 0; i < num_lines; i++ ){
        MVertex *v0 = (*source_lines)[i]->getVertex(0);
        MVertex *v1 = (*source_lines)[i]->getVertex(1);

        std::vector<MVertex*> verts;
        // test to see if this is a degenerate quad as triangle. If so, continue.
        verts = getExtrudedLateralVertices(v0, v1, (*it), 0, 0, loop_ep, pos);
        if( verts[0]==verts[2] || verts[1]==verts[3] ){
          for( int p = 0; p < loop_ep->mesh.NbLayer; p++ )
            index_guess += loop_ep->mesh.NbElmLayer[p];
          continue;
        }
        for(int j = 0; j < loop_ep->mesh.NbLayer; j++) {
          for(int k = 0; k < loop_ep->mesh.NbElmLayer[j]; k++) {
            verts.clear();
            verts = getExtrudedLateralVertices(v0, v1, (*it), j, k, loop_ep, pos);

            // Find diagonal:

            std::pair<int,int> diag (0,0);
            diag = FindDiagonalEdgeIndices( verts, (*it), true, index_guess );
            if( diag.first || diag.second ){
              int add = diag.first < 2 ? 1 : -1;
              // have to test if conflicting edge already exists in quadToTri_edges in case of global subdivide
              if( !edgeExists( verts[diag.first+add], verts[diag.second-add], quadToTri_edges ) ){
                createEdge( verts[diag.first], verts[diag.second], lat_tri_diags );
                if( is_fixed )
                  createEdge( verts[diag.first], verts[diag.second], quadToTri_edges );
              }
              else
                createEdge( verts[diag.first+add], verts[diag.second-add], lat_tri_diags );
            }
            else
              Msg::Error("In QuadToTriGetRegionDiags(), failed to find a diagonal on unrecombined lateral surface %d.", (*it)->tag() );

            index_guess += 2;
             /*

              std::vector<MVertex*> vface;
              vface.push_back(verts[0]);
              vface.push_back(verts[1]);
              vface.push_back(verts[3]);
              vface.push_back(verts[2]);
              if( k==2 && ( counter == 3 || counter == 3) ){
                if( k==0 || k ){
                  createEdge( verts[1], verts[2], lat_tri_diags );
                  createEdge( verts[1], verts[2], quadToTri_edges );
                }
                else{
                  createEdge( verts[0], verts[3], lat_tri_diags );
                  createEdge( verts[0], verts[3], quadToTri_edges );
                }
              }
              else if( k==2 && (counter == 5 || counter == 4 || counter == 6 ) ){
                createEdge( verts[0], verts[3], lat_tri_diags );
                createEdge( verts[0], verts[3], quadToTri_edges );
              }
              else if( k<2 )
                createForbidden(vface, forbidden_edges);
              else
                createEdge( elemEdge_tmp.first, elemEdge_tmp.second, lat_tri_diags );
              */

          }
        }
      }
    }

  }
  // Insert diagonals of the COPIED top surface into quadToTri_edges;
  unsigned int index_guess = reg_source->triangles.size();
  if( reg_top->quadrangles.size() ){
    Msg::Error("In QuadToTriGetRegionDiags(), top surface of region "
               "%d has quads.", gr->tag() );
    return false;
  }

  for( unsigned int i = 0; i < reg_source->quadrangles.size(); i++){
    int j_top = ep->mesh.NbLayer-1;
    int k_top = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1];

    MElement *elem = reg_source->quadrangles[i];
    std::vector<MVertex *> verts;
    get2DExtrudedVertices( elem, ep, j_top, k_top, pos, verts );
    if( verts.size() != 4 ) break;

    // Find diagonal:
    std::pair<int,int> diag(0,0);
    diag = FindDiagonalEdgeIndices( verts, reg_top, false, index_guess );
    if( diag.first || diag.second )
      createEdge( verts[diag.first], verts[diag.second], quadToTri_edges );
    else
      Msg::Error("In QuadToTriGetRegionDiags(), failed to find a diagonal on top surface %d.", reg_top->tag() );

    index_guess += 2;
  }
  return true;
}


// For use in QuadToTriEdgeGenerator:  Controls BRUTE FORCE edging of elements with ALL vertices
// on a lateral boundary surface.
// Added 04/08/2011
static int makeEdgesForElemsWithAllVertsOnBnd( GRegion *gr, bool is_dbl,
                                               CategorizedSourceElements &cat_src_elems,
                                               std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                               std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                               std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                               std::map<MElement*, std::set<std::pair<unsigned int,
                                                        unsigned int> > > &problems,
                                               std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In makeEdgesForElemsWithAllVertsOnBnd(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In makeEdgesForElemsWithAllVertsOnBnd(), invalid model for region "
               "%d.", gr->tag() );
    return 0;
  }

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In makeEdgesForElemsWithAllVertsOnBnd(), invalid source face for region "
               "%d.", gr->tag() );
    return 0;
  }

  if( gr != cat_src_elems.region || reg_source != cat_src_elems.source_face ){
    Msg::Error("In makeEdgesForElemsWithAllVertsOnBnd(), too many elements in the CategorizedSourceElements "
               " structure for given source face %d.", reg_source->tag() );
    return 0;
  }

  // find edge verts of source face
  std::set<MVertex *, MVertexLessThanLexicographic> pos_src_edge;
  QuadToTriInsertFaceEdgeVertices(reg_source, pos_src_edge );


  // while Loop to diagonalize 3-boundary point triangles and 4-boundary point quadrangles:
  bool finish_all_tri = false;
  // can afford temporary copies since these sets should be relatively small for all cases.
  std::set<unsigned int> tri_tmp, quad_tmp;
  tri_tmp = cat_src_elems.three_bnd_pt_tri;
  // if is_dbl, then don't track the quads
  if( !is_dbl )
    quad_tmp = cat_src_elems.four_bnd_pt_quad;

  while( tri_tmp.size() || quad_tmp.size() ){
    std::set<unsigned int>::iterator it;
    std::vector<unsigned int> done;
    // 3 bnd point triangle and 4 bnd point quad loop
    // s = 0 for triangles, s = 1 for quads
    for( int s = 0; s < 2; s++ ){
      std::set<unsigned int> *set_elems;
      std::set<std::pair<MVertex*,MVertex*> > edges_new, forbidden_new;
      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > problems_new;
      if( !s )  set_elems = &tri_tmp;
      else      set_elems = &quad_tmp;

      for( it = set_elems->begin(); it != set_elems->end(); it++ ){
        MElement *elem;
        if( !s ) elem = reg_source->triangles[(*it)];
        else     elem = reg_source->quadrangles[(*it)];

        // int elem_size = elem->getNumVertices();

        std::vector<bool> vert_bnd;
        if( !s ) vert_bnd.insert( vert_bnd.begin(), cat_src_elems.tri_bool.begin()+(4*(*it)+1),
                                  cat_src_elems.tri_bool.begin()+(4*(*it)+4) );
        else     vert_bnd.insert( vert_bnd.begin(), cat_src_elems.quad_bool.begin()+(5*(*it)+1),
                                  cat_src_elems.quad_bool.begin()+(5*(*it)+5) );
        int j_start, k_start;

        // if has lat_tri_diags or is a rotation with quads (may have to do the one point bnd quads to
        // get rid of degenerate hexahedra...they are invalid mesh volumes.
        if( lat_tri_diags.size() || ( reg_source->quadrangles.size() && (
            ep->geo.Type == ROTATE || ep->geo.Type == TRANSLATE_ROTATE ) ) ){
          j_start = 0;
          k_start = 0;
        }
        else{
          j_start = ep->mesh.NbLayer-1;
          k_start = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;
        }

        int num_levels = 0;
        if( lat_tri_diags.size() || ( reg_source->quadrangles.size() && (
            ep->geo.Type == ROTATE || ep->geo.Type == TRANSLATE_ROTATE ) ) ){
          for( int p = 0; p < ep->mesh.NbLayer; p++ )
            num_levels += ep->mesh.NbElmLayer[p];
        }
        else
          num_levels = 1;

        int num_edged = 0;

        // before starting extrusion loop, get the node numbers for the diagonal
        // in the region's top surface extruded from this source element
        // (will need this below)
        std::vector<MVertex *> verts_top;
        int ntop1 = -1, ntop2 = -2;
        getExtrudedVertices( elem, ep, ep->mesh.NbLayer-1,
                             ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1, pos, verts_top);
        if( edgeExists( verts_top[4], verts_top[6], quadToTri_edges ) ){
          ntop1 = 4; ntop2 = 6;
        }
        else if( edgeExists( verts_top[5], verts_top[7], quadToTri_edges ) ){
          ntop1 = 5; ntop2 = 7;
        }

        // start extrusion loop
        for( int j = j_start; j < ep->mesh.NbLayer; j++ ){
          int k_start_tmp, k_stop;
          if( j == j_start )
            k_start_tmp = k_start;
          else
            k_start_tmp = 0;
          k_stop = ep->mesh.NbElmLayer[j];
          for( int k = k_start_tmp; k < k_stop; k++ ){
            std::vector<MVertex*> verts;
            std::map<std::string, std::vector<int> > face_types;
            std::vector<int> nfix1, nfix2, nadj1, nadj2, free_flag;
            int vert_num = getExtrudedVertices(elem, ep, j, k, pos, verts);
            // if just starting and there is no diagonal on the bottom edge,
            // forbid it (this prevents some conflicts)
            if( vert_num == 8 && j==j_start && k==k_start &&
                !edgeExists(verts[0], verts[2], quadToTri_edges) &&
                !edgeExists(verts[1], verts[3], quadToTri_edges) ){
              std::vector<MVertex *> v_bot;
              v_bot.assign(4, (MVertex*)(0));
              v_bot[0] = verts[0]; v_bot[1] = verts[1];
              v_bot[2] = verts[2]; v_bot[3] = verts[3];
              createForbidden(v_bot, forbidden_edges);
              createForbidden(v_bot, forbidden_new);
            }

            if( !s ){
              face_types = getFaceTypes( gr, elem, j, k, verts, pos_src_edge, quadToTri_edges,
                                         forbidden_edges, lat_tri_diags, vert_bnd, nfix1, nfix2,
                                         nadj1, nadj2, free_flag);

              if( finish_all_tri || face_types["free"].size() + face_types["adj_diag"].size() < 2 ){
                bruteForceEdgeQuadToTriPrism( gr, elem, j, k, verts, face_types, edges_new,
                                          forbidden_new, quadToTri_edges, forbidden_edges,
                                          lat_tri_diags, problems_new, problems, nfix1, nfix2,
                                          nadj1, nadj2, free_flag);
                //IMPORTANT
                num_edged++;
              }
            }
            else if( s ){
              // a loop to try to force the top diagonal to align with the diagonal in the region's
              // top surface above this element.
              bool changed_diag = false;
              for( int g=0; g < 2; g++ ){
                // on first step, see if can put in the aligned top diagonal
                if( g==0 && ntop1 >=0 && ntop2 >= 0 &&
                    !edgeExists( verts[4], verts[6], quadToTri_edges ) &&
                    !edgeExists( verts[5], verts[7], quadToTri_edges ) ){
                  std::vector<MVertex *> v_top;
                  v_top.assign(4, (MVertex*)(0));
                  v_top[0] = verts[4]; v_top[1] = verts[5];
                  v_top[2] = verts[6]; v_top[3] = verts[7];
                  if( !forbiddenExists( v_top, forbidden_edges ) ){
                    changed_diag = true;
                    createEdge( verts[ntop1], verts[ntop2], quadToTri_edges );
                  }
                }
                // on second step, see if a problem was created from inserting aligned diagonal
                // if so, remove it and try again.
                std::pair<unsigned int, unsigned int> jk_pair(j,k);
                if( g==1 && changed_diag &&
                    problems[elem].find( jk_pair ) != problems[elem].end() ){
                  problems[elem].erase( jk_pair );
                  if( !problems[elem].size() )
                    problems.erase( elem );
                  deleteEdge( verts[ntop1], verts[ntop2], quadToTri_edges );
                }
                else if( g==1 ){
                  if( !problems[elem].size() )
                    problems.erase( elem );
                  break;
                }
                face_types = getFaceTypes( gr, elem, j, k, verts, pos_src_edge, quadToTri_edges,
                                           forbidden_edges, lat_tri_diags, vert_bnd, nfix1, nfix2,
                                           nadj1, nadj2, free_flag);

                bruteForceEdgeQuadToTriHexa( gr, elem, j, k, verts, face_types, edges_new,
                                             forbidden_new, quadToTri_edges, forbidden_edges,
                                             lat_tri_diags, problems_new, problems, pos, nfix1, nfix2,
                                             nadj1, nadj2, free_flag);
              }
              //IMPORTANT
              num_edged++;
            }
          }
        }

        // IMPORTANT
        if( num_edged == num_levels )
          done.push_back((*it));

        // If quads, break ( only do quads one at a time so can keep 3 bnd point triangles from
        // being trapped so that they can't be meshed without an internal vertex)
        if( s )
          break;

      }  // end loop over set of element indices (tri or quad)

      // remove elements that are done from list
      if( done.size() ){
        for(unsigned int i = 0; i < done.size(); i++ )
          set_elems->erase( done[i] );
        done.clear();
      }

      // skip over quads on this iteration if some modifications were made to triangle extrusion elements
      // ( need to make sure no triangles left with only one adjustable or free face or else
      //   meshing a quad might trap them so they can't be meshed without internal vertex ).
      if( !s && ( edges_new.size() || problems_new.size() ) )
        s = -1;

      // if quads are done, finish all triangles
      if( !quad_tmp.size() )
        finish_all_tri = true;

    }  // end of s-loop to choose between tri or quad

  }  // end of while

  return 1;

}  // end of makeEdgesForElemsWithAllVertsOnBnd




// For use in QuadToTriEdgeGenerator:  Does the edging of prisms with some but not all vertices
// on a lateral boundary surface.
// Added 04/08/2011
static int makeEdgesForOtherBndPrisms( GRegion *gr, bool is_dbl, CategorizedSourceElements &cat_src_elems,
                                       std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                       std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                       std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                       std::map<MElement*, std::set<std::pair<unsigned int,
                                                unsigned int> > > &problems,
                                       std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In makeEdgesForOtherBndPrisms(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In makeEdgesForOtherBndPrisms(), invalid model for region "
               "%d.", gr->tag() );
    return 0;
  }

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In makeEdgesForOtherBndPrisms(), invalid source face for region "
               "%d.", gr->tag() );
    return 0;
  }

  if( gr != cat_src_elems.region || reg_source != cat_src_elems.source_face ){
    Msg::Error("In makeEdgesForOtherBndPrisms(), CatergorizedSourceElements structure data "
               " does not correspond to region %d.", reg_source->tag() );
    return 0;
  }

  std::set<unsigned int >::iterator it;

  // skip the whole thing if this is true...NO reason to divide!!
  if( !lat_tri_diags.size() && !reg_source->quadrangles.size() )
    return 1;


  // edge other_bnd triangles loop
  // (draw from boundaries up toward interior)
  for( it = cat_src_elems.other_bnd_tri.begin();
       it != cat_src_elems.other_bnd_tri.end(); it++ ){


    std::set<std::pair<MVertex*,MVertex*> > edges_new, forbidden_new;
    std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > problems_new;
    std::vector<MVertex*> verts;
    std::vector<bool> vert_bnd;
    MElement *elem = reg_source->triangles[(*it)];
    int elem_size = elem->getNumVertices();

    vert_bnd.insert( vert_bnd.begin(), cat_src_elems.tri_bool.begin()+(4*(*it)+1),
                     cat_src_elems.tri_bool.begin()+(4*(*it)+4) );

    int j_start, k_start;
    // if has lat_tri_diags or is a rotation with quads (may have to do the one point bnd quads to
    // get rid of degenerate hexahedra...they are invalid mesh volumes.
    if( lat_tri_diags.size() || ( reg_source->quadrangles.size() && (
        ep->geo.Type == ROTATE || ep->geo.Type == TRANSLATE_ROTATE ) ) ){
      j_start = 0;
      k_start = 0;
    }
    else{
      j_start = ep->mesh.NbLayer-1;
      k_start = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;
    }

    // add edges
    for( int j = j_start; j < ep->mesh.NbLayer; j++ ){
      int k_start_tmp, k_stop;
      if( j == j_start )
        k_start_tmp = k_start;
      else
        k_start_tmp = 0;
      k_stop = ep->mesh.NbElmLayer[j];
      for( int k = k_start_tmp; k < k_stop; k++ ){
        std::vector<MVertex *> verts;
        getExtrudedVertices(elem, ep, j, k, pos, verts);
        // NOTE: bnd_face might not really be a bnd_face, but the code takes that into account below.
        for( int p = 0; p < elem_size; p++ ){
          if( vert_bnd[p] ){
            bool degen = false;
            int p2 = (p+1)%elem_size;
            int p3 = (p+elem_size-1)%elem_size;
            // test for degeneracy
            if( verts[p] == verts[p+elem_size] )
              degen = true;
            if( !degen && !vert_bnd[p2] ){
              createEdge( verts[p], verts[p2+elem_size], quadToTri_edges );
              createEdge( verts[p], verts[p2+elem_size], edges_new );
            }
            if( !degen && !vert_bnd[p3] ){
              createEdge( verts[p], verts[p3+elem_size], quadToTri_edges );
              createEdge( verts[p], verts[p3+elem_size], edges_new );
            }

            // make the adjustable diag (if it exists)
            // Note: p might not really be a bnd face, but this takes that into account
            if( edgeExists( verts[p], verts[p2+elem_size], lat_tri_diags ) &&
                 !edgeExists( verts[p+elem_size], verts[p2], quadToTri_edges ) )
              createEdge( verts[p], verts[p2+elem_size], quadToTri_edges );
            else if( edgeExists( verts[p+elem_size], verts[p2], lat_tri_diags ) &&
                     !edgeExists( verts[p], verts[p2+elem_size], quadToTri_edges ) )
              createEdge( verts[p+elem_size], verts[p2], quadToTri_edges );
          }
        }
      }
    }

  }  // end of boundary triangles loop

  return 1;

}  // end of makeEdgesForOtherBndPrisms()



// For use in QuadToTriEdgeGenerator:  Does the edging of hexahedra with some but not all vertices
// on a lateral boundary surface.
// Added 04/08/2011
static int makeEdgesForOtherBndHexa( GRegion *gr, bool is_dbl, CategorizedSourceElements &cat_src_elems,
                                     std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                     std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                     std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                     std::map<MElement*, std::set<std::pair<unsigned int,
                                              unsigned int> > > &problems,
                                     std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  // Edge creation for extruded quadrangles with some but not all vertices on a boundary.
  // (draw from boundaries up toward interior)
  // If no lat_tri_diags, just do the top layer.
  // Follow these instructions:
  // For 2 pts on boundary:
  //  Below top level, draw top diags only if there are lat_tri_diags touching elemnt or if
  //  element is not adjacent to any boundary (only touching it)
  //  Order of precedence in top edging decisions:
  //   a. if bottom diag exists, align top diagonal to it.
  //   b. if bnd vertices are on diametrically opposite corners, draw top diag NOT on them.
  //   c. if lateral surface diagonals touch element, connect to one at some vertex.
  //   d. otherwise, don't draw top diagonal.
  //  In any case, draw the lateral edges up from bottom boundary vertices toward interior.
  //  At top level, top diagonals should already be done in 2D mesh step.
  // For 3 pts on boundary:
  //  Draw the top diag from corner inward.  Draw laterals up from bottom  boundary vertices.
  // For 1 point on boundary:
  //  Draw lateral diagonals up from bottom boundary verts, draw top diagonal completely off the boundary.
  //  Draw diagonals toward the "pivot vertex", which is the vertex in the top element face
  //  diametrically opposite to the top face vertex on the boundary. Actually, this is only
  //  done in the first two extrusion layers, if those layers are not in the top layer.
  //  In first layer, draw diags to the top vertex diametrically opposite bnd vert, in the second
  //  layer, draw them down to the bottom such vertex.  Same vertex for both layers.  This is
  //  done to ensure that a one pt boundary quad in an unstructured surface can be divided without
  //  dividing the entire bottom layer. If two pivot vertices share an edge and these rules would conflict,
  //  just give precedence to the first pivot vertex encountered in the edging loop (this works, yes).
  //  Also, the internal elements touching this pivot vertex should
  //  have diagonals drawn to pivot vertex as well (done in different function, with same precedence).

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In makeEdgesForOtherBndHexa(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In makeEdgesForOtherBndHexa(), invalid model for region "
               "%d.", gr->tag() );
    return 0;
  }

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In makeEdgesForOtherBndHexa(), invalid source face for region "
               "%d.", gr->tag() );
    return 0;
  }

  if( gr != cat_src_elems.region || reg_source != cat_src_elems.source_face ){
    Msg::Error("In makeEdgesForOtherBndHexa(), CatergorizedSourceElements structure data "
               " does not correspond to region %d.", reg_source->tag() );
    return 0;
  }

  std::set<unsigned int>::iterator it;

  for( it = cat_src_elems.other_bnd_quad.begin();
       it != cat_src_elems.other_bnd_quad.end(); it++ ){

    MElement *elem = reg_source->quadrangles[(*it)];
    const int elem_size = elem->getNumVertices();

    std::vector<bool> vert_bnd;
    vert_bnd.insert( vert_bnd.begin(), cat_src_elems.quad_bool.begin()+(5*(*it)+1),
                     cat_src_elems.quad_bool.begin()+(5*(*it)+5) );

    // these locally hold each added edge/problem element temporarily
    std::set< std::pair<MVertex *, MVertex *> > edges_new;
    std::set< std::pair<MVertex *, MVertex *> > forbidden_new;
    std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > problems_new;

    // Get a count of bnd verts. If one point, that index will be in one_point_ind.
    // For 3 bnd vert quads  record the empty spot in 'skip.'
    int bnd_count = 0, skip = 0, one_point_ind = 0;
    for( int s = 0; s < elem_size; s++ ){
      if( vert_bnd[s] ){
        bnd_count++;
        one_point_ind = s;
      }
      else skip = s;
    }

    int j_start, k_start;

    // if has lat_tri_diags or is a rotation with quads (may have to do the one point bnd quads to
    // get rid of degenerate hexahedra...they are invalid mesh volumes.
    if( lat_tri_diags.size() || ( reg_source->quadrangles.size() && (
        ep->geo.Type == ROTATE || ep->geo.Type == TRANSLATE_ROTATE ) ) ){
      j_start = 0;
      k_start = 0;
    }
    else{
      j_start = ep->mesh.NbLayer-1;
      k_start = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;
    }

    // start of top layer
    int j_top_start = ep->mesh.NbLayer-1;
    int k_top_start = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;

    // add edges:

    // lateral diags in any case
    for( int j = j_start; j < ep->mesh.NbLayer; j++ ){
      int k_start_tmp, k_stop;
      if( j == j_start )
        k_start_tmp = k_start;
      else
        k_start_tmp = 0;
      k_stop = ep->mesh.NbElmLayer[j];
      for( int k = k_start_tmp; k < k_stop; k++ ){
        std::vector<MVertex *> verts;
        getExtrudedVertices(elem, ep, j, k, pos, verts);
        // int bnd_face = -1;
        // NOTE: bnd_face might not really be a bnd_face, but don't worry--it won't be diagonalized if not
        for( int p = 0; p < elem_size; p++ ){
          int p2 = (p+1)%elem_size;
          int p3 = (p+elem_size-1)%elem_size;
          if( vert_bnd[p] ){
            bool degen = false;
            // test for degeneracy
            if( verts[p] == verts[p+elem_size] )
              degen = true;
            if( !degen && !vert_bnd[p2] )
              createEdge( verts[p], verts[p2+elem_size], quadToTri_edges );
            if( !degen && !vert_bnd[p3] )
              createEdge( verts[p], verts[p3+elem_size], quadToTri_edges );

            // make the adjustable diag
            if( edgeExists( verts[p], verts[p2+elem_size], lat_tri_diags ) &&
                 !edgeExists( verts[p+elem_size], verts[p2], quadToTri_edges ) )
              createEdge( verts[p], verts[p2+elem_size], quadToTri_edges );
            else if( edgeExists( verts[p+elem_size], verts[p2], lat_tri_diags ) &&
                      !edgeExists( verts[p], verts[p2+elem_size], quadToTri_edges ) )
              createEdge( verts[p+elem_size], verts[p2], quadToTri_edges );
          }
          // if face not on boundary and in top layer...make an internal lateral
          else if( j == j_top_start && k == k_top_start && !vert_bnd[p2] ){
            int ind_low, ind2;
            if( verts[p+elem_size] < verts[p2+elem_size] ){
              ind_low = p+elem_size;
              ind2 = p2;
            }
            else{
              ind_low = p2+elem_size;
              ind2 = p;
            }
            createEdge( verts[ind_low], verts[ind2], quadToTri_edges );
          }

        }
      }
    }


    // Add top diags for 2-bnd point quads, below top layer
    // If there is a lateral diagonal, connect to it.  If this is a two boundary point quad
    // that is not adjacent to a boundary (it is possible), draw diagonal completely off boundary.
    // If neither of the above, don't make the top diagonal.
    // IF degenerate, be careful.
    if( bnd_count == 2 ){
      for( int j = j_start; j < ep->mesh.NbLayer; j++ ){
        int k_start_tmp, k_stop;
        if( j == j_start )
          k_start_tmp = k_start;
        else
          k_start_tmp = 0;
        k_stop = ep->mesh.NbElmLayer[j];
        if( j == ep->mesh.NbLayer-1 )
          k_stop--;  // dont go to top elements
        for( int k = k_start_tmp; k < k_stop; k++ ){
          std::vector<MVertex *> verts;
          getExtrudedVertices(elem, ep, j, k, pos, verts);
          int p1 = -1, p2 = -1;
          for( int p = 0; p < elem_size; p++ ){
            if( vert_bnd[p] ){
              p1 = p;
              int p2_tmp = (p+1)%elem_size;
              int p3_tmp = (p+elem_size-1)%elem_size;
              if( vert_bnd[p2_tmp] ){
                p1 = p; p2 = p2_tmp;
              }
              else if( vert_bnd[p3_tmp] ){
                p1 = p3_tmp; p2 = p;
              }
              break;
            }
          }
          if( p2 < 0 && p1 < 0 ){
            Msg::Error("In makeEdgesForOtherBndHexa(), error finding boundary points on "
                       "2-boundary point quadrangle.");
            break;
          }

          // First, if bottom diagonal exists, align top diagonal to it, OTHERWISE:
          //   if bnd verts oppose each other, draw top diagonal off boundary
          //   otherwise, connect to any existing lateral diagonal either totally ON boundary or totally OFF,
          //   but ONLY draw top diag if such a lateral exists
          // NOTE: since laterals were added first, any lat_tri_diag here is in quadToTri_edges already
          if( edgeExists( verts[0], verts[2], quadToTri_edges ) )
            createEdge( verts[4], verts[6], quadToTri_edges );
          else if( edgeExists( verts[1], verts[3], quadToTri_edges ) )
            createEdge( verts[5], verts[7], quadToTri_edges );
          else if( p2 < 0 && p1 >= 0 )
            createEdge( verts[(p1+1)%elem_size+elem_size],
                        verts[(p1+elem_size-1)%elem_size+elem_size], quadToTri_edges );
          else if( p1 >= 0 && edgeExists( verts[p1], verts[p2+elem_size], quadToTri_edges ) )
            createEdge( verts[p2+elem_size], verts[(p2+2)%elem_size+elem_size], quadToTri_edges );
          else if( p1 >= 0 && edgeExists( verts[p1+elem_size], verts[p2], quadToTri_edges ) )
            createEdge( verts[p1+elem_size], verts[(p1+2)%elem_size+elem_size], quadToTri_edges );
        }
      }
    }


    // top diags on corner quad  ( I *think* this always works for non-degen stuff, even for free wall spanning cases )
    else if( bnd_count == 3 && ( j_start < j_top_start || k_start < k_top_start ) ){
      std::vector<MVertex *> verts;
      getExtrudedVertices(elem, ep, j_start, k_start, pos, verts);
      problems_new.clear();
      forbidden_new.clear();
      edges_new.clear();
      createEdge( verts[skip+elem_size], verts[(skip+2)%elem_size+elem_size], quadToTri_edges );
      createEdge( verts[skip+elem_size], verts[(skip+2)%elem_size+elem_size], edges_new );
      // copies the diags in edges_new on up the extrusion but NOT on the top surface
      ExtrudeDiags( gr, verts, j_start, k_start, j_top_start, k_top_start,
                    elem, ep, edges_new, forbidden_new,
                    quadToTri_edges, forbidden_edges, problems_new, problems, pos);
    }

    // finally, top diagonal and other two laterals for 1 bnd point quad
    else if( bnd_count == 1 && ( j_start < j_top_start || k_start < k_top_start ) ){
      std::vector<MVertex*> verts;
      getExtrudedVertices(elem, ep, j_start, k_start, pos, verts);
      int p = one_point_ind;

      // to determine if there is a second level above the start but not in top layer
      int j_next, k_next;
      bool divide_next = false;
      std::vector<MVertex*> verts_next;
      if( ep->mesh.NbElmLayer[0] > 1 ){
        j_next = 0;
        k_next = 1;
      }
      else{
        j_next = std::min(ep->mesh.NbLayer-1, 1);
        k_next = 0;
      }
      if( j_next < j_top_start || k_next < k_top_start ){
        divide_next = true;
        getExtrudedVertices(elem, ep, j_next, k_next, pos, verts_next);
      }

      problems_new.clear();
      forbidden_new.clear();
      edges_new.clear();

      // Create the laterals that run up to the "pivot vertex" for this 1 bnd pt quad
      // Other internal elements have diagonals converging on the pivot index.
      // Only create it if there is NO conflicting diagonal in place, though--this CAN happen,
      // but this approach still give no conflicts.
      // NOTE THAT THESE ARE NOT PROPAGATED UP THE ENTIRE EXTRUSION.
      int p2 = (p+1)%elem_size;
      int p3 = (p+2)%elem_size;
      int p4 = (p+elem_size-1)%elem_size;
      if( !edgeExists( verts[p2+elem_size], verts[p3], quadToTri_edges ) )
        createEdge( verts[p2], verts[p3+elem_size], quadToTri_edges );
      if( !edgeExists( verts[p4+elem_size], verts[p3], quadToTri_edges ) )
        createEdge( verts[p4], verts[p3+elem_size], quadToTri_edges );

      // if there is a second extrusion level not on the top layer, add the 'reverse' of the
      // previous two diagonals
      if( divide_next && !edgeExists( verts_next[p2], verts_next[p3+elem_size], quadToTri_edges ) )
        createEdge( verts_next[p2+elem_size], verts_next[p3], quadToTri_edges );
      if( divide_next && !edgeExists( verts_next[p4], verts_next[p3+elem_size], quadToTri_edges ) )
        createEdge( verts_next[p4+elem_size], verts_next[p3], quadToTri_edges );

      // If this quad has degenerate vertex on boundary and the pivot laterals run to the
      // top pivot vertex and there is no pre-existing
      // top diagonal on other two vertices, draw diagonal out to
      // the pivot_vertex. Otherwise, draw it on the other two verts
      if( verts[p] == verts[p+elem_size] &&
          ( edgeExists( verts[p2], verts[p3+elem_size], quadToTri_edges ) ||
            verts[p2] == verts[p2+elem_size] ) &&
          ( edgeExists( verts[p4], verts[p3+elem_size], quadToTri_edges ) ||
            verts[p4] == verts[p4+elem_size] ) &&
          !edgeExists( verts[p2+elem_size], verts[p4+elem_size], quadToTri_edges ) ){
        createEdge( verts[p+elem_size], verts[p3+elem_size], quadToTri_edges );
        createEdge( verts[p+elem_size], verts[p3+elem_size], edges_new );
      }
      else{
        createEdge( verts[p2+elem_size], verts[p4+elem_size], quadToTri_edges );
        createEdge( verts[p2+elem_size], verts[p4+elem_size], edges_new );
      }
      // copies the top diag in edges_new up the extrusion but NOT to the top surface of region.
      ExtrudeDiags( gr, verts, 0, 0, j_top_start, k_top_start,
                    elem, ep, edges_new, forbidden_new,
                    quadToTri_edges, forbidden_edges, problems_new, problems, pos);
    }

  }  // end of boundary quadrangles loop

  return 1;

} // end of makeEdgesForOtherBndHexa()


// For use in QuadToTriEdgeGenerator:  Does the lateral edging of internal elements that touch
// a pivot vertex of a hexahedral element that has ONE SOURCE vertex on a lateral boundary surface.
// See inside function for a definition of the "pivot vertex."
// Added 04/08/2011
 static int makeEdgesForElemsTouchPivotVert( GRegion *gr, bool is_dbl, CategorizedSourceElements &cat_src_elems,
                                       std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                       std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                                       std::set<std::pair<MVertex*, MVertex*> > &forbidden_edges,
                                       std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  //  Draw diagonals toward the "pivot vertex" of a hexahedron whose source quad has only one
  //  vertex on a lateral boundary. Actually, this is only
  //  done in the first two extrusion layers, if those layers are not in the top layer. The pivot
  //  vertex is the vertex in the top face of the element that is diametrically opposite the top vertex
  //  on the lateral boundary of the region.
  //  In first layer, draw diags up from bottom to the pivot vertex, in the second
  //  layer, draw them down to pivot vertex.  Same vertex for both layers.  This is
  //  done to ensure that a one pt boundary quad in an unstructured surface can be divided without
  //  dividing the entire bottom layer.
  //  If two pivot vertices share an edge and these rules would conflict,
  //  just give precedence to the first pivot vertex encountered in the edging loop (this works, yes).


  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In makeEdgesForElemsTouchPivotVert(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In makeEdgesForElemsTouchPivotVert(), invalid model for region "
               "%d.", gr->tag() );
    return 0;
  }

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In makeEdgesForForElemsTouchPivotVert(), invalid source face for region "
               "%d.", gr->tag() );
    return 0;
  }

  if( gr != cat_src_elems.region || reg_source != cat_src_elems.source_face ){
    Msg::Error("In makeEdgesForElemsTouchPivotVert(), CatergorizedSourceElements structure data "
               " does not correspond to region %d.", reg_source->tag() );
    return 0;
  }

  // no need to do this if there are no lateral surface diagonals and if not a
  // rotation with quadrangles.
  if( !lat_tri_diags.size() &&
      ( !reg_source->quadrangles.size() ||
        (ep->geo.Type != ROTATE && ep->geo.Type != TRANSLATE_ROTATE) ) )
    return 1;

  int j_top_start, k_top_start;
  j_top_start = ep->mesh.NbLayer-1;
  k_top_start = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;

  // s = 0 for triangles; s = 1 for quadrangles
  // These diags are all repeated identically up the extrusion.
  for( int s = 0; s < 2; s++ ){


    std::set<unsigned int> *set_elems;
    std::set<unsigned int>::iterator it;

    if( !s )
      set_elems = &cat_src_elems.internal_tri_touch_one_bnd_pt_quad;
    else
      set_elems = &cat_src_elems.internal_quad_touch_one_bnd_pt_quad;

    for( it = set_elems->begin(); it != set_elems->end(); it++ ){
      MElement *elem;
      if( !s )
        elem = reg_source->triangles[(*it)];
      else
        elem = reg_source->quadrangles[(*it)];

      int elem_size = elem->getNumVertices();

      // find pivot vertex index
      int v_index;
      bool v_index_found = false;
      for( int p = 0; p < elem_size; p++ ){
        if( !s && cat_src_elems.tri_bool[4*(*it)+1+p] ){
          v_index = p; v_index_found = true; break;
        }
        else if( s && cat_src_elems.quad_bool[5*(*it)+1+p] ){
          v_index = p; v_index_found = true; break;
        }
      }
      if( !v_index_found ){
        Msg::Error("In makeEdgesForElemsTouchPivotVert(), could not find the pivot vertex for an element touching "
                   "a quad with one vertex on a face edge boundary in region %d. Skipping...", gr->tag() );
        continue;
      }

      std::vector<MVertex*> verts;
      getExtrudedVertices(elem, ep, 0, 0, pos, verts);

      // determine the j, k for the next layer above 0,0 so that the elements directly above
      // the base elements can divided AND higher layers may be closed off
      // (no need to divide the elements all the way up)
      int j_next, k_next;
      bool divide_next = false;
      std::vector<MVertex*> verts_next;
      if( ep->mesh.NbElmLayer[0] > 1 ){
        j_next = 0;
        k_next = 1;
      }
      else{
        j_next = std::min(ep->mesh.NbLayer-1, 1);
        k_next = 0;
      }
      if( j_next < j_top_start || k_next < k_top_start ){
        divide_next = true;
        getExtrudedVertices(elem, ep, j_next, k_next, pos, verts_next);
      }

      // add the lateral diagonals (skip faces that are already diagonalized)
      // note these are created in two layers, mirrored about the plane separating the layers
      int p2 = (v_index+1)%elem_size;
      int p3 = (v_index+elem_size-1)%elem_size;
      if( !edgeExists( verts[v_index], verts[p2+elem_size], quadToTri_edges ) ){
        createEdge( verts[v_index+elem_size], verts[p2], quadToTri_edges );
        if( divide_next )
          createEdge( verts_next[v_index], verts_next[p2+elem_size], quadToTri_edges );
      }
      if( !edgeExists( verts[v_index], verts[p3+elem_size], quadToTri_edges ) ){
        createEdge( verts[v_index+elem_size], verts[p3], quadToTri_edges );
        if( divide_next )
          createEdge( verts_next[v_index], verts_next[p3+elem_size], quadToTri_edges );
      }
      // make top diagonals for quads -- note: can't just draw to the preferred pivot because
      // it can touch two and the other might have laterals drawn to it already.  have to find
      // the one with two lateral diagonals drawn to it.
      if( s==1 && verts[v_index+elem_size] != verts[v_index] &&
          !edgeExists( verts[p2+elem_size], verts[p3+elem_size], quadToTri_edges ) )
        createEdge( verts[v_index+elem_size], verts[(v_index+2)%elem_size+elem_size], quadToTri_edges );

    }
  }


  // Now revisit the boundary quads that touched a one boundary point quad pivot.  These MAY have had
  // edges added and now need a top diagonal
  std::set<unsigned int>::iterator it;
  for( it = cat_src_elems.two_bnd_pt_quad_touch_one_bnd_pt_quad.begin();
       it !=  cat_src_elems.two_bnd_pt_quad_touch_one_bnd_pt_quad.end(); it++ ){
    MElement *elem = reg_source->quadrangles[(*it)];
    int elem_size = elem->getNumVertices();
    std::vector<bool> vert_bnd;
    vert_bnd.insert( vert_bnd.begin(), cat_src_elems.quad_bool.begin()+(5*(*it)+1),
                     cat_src_elems.quad_bool.begin()+(5*(*it)+5) );
    // find num boundary points
    int bnd_count = 0;
    for( int s = 0; s < elem_size; s++ ){
      if( vert_bnd[s] )
        bnd_count++;
    }
    if( bnd_count != 2 )
      continue;

    std::vector<MVertex*> verts;
    getExtrudedVertices(elem, ep, 0, 0, pos, verts);
    int p1 = -1, p2 = -1;
    for( int p = 0; p < elem_size; p++ ){
      if( vert_bnd[p] ){
        p1 = p;
        int p2_tmp = (p+1)%elem_size;
        int p3_tmp = (p+elem_size-1)%elem_size;
        if( vert_bnd[p2_tmp] ){
          p1 = p; p2 = p2_tmp;
        }
        else if( vert_bnd[p3_tmp] ){
          p1 = p3_tmp; p2 = p;
        }
        break;
      }
    }
    if( p2 < 0 && p1 < 0 ){
      Msg::Error("In makeEdgesForElemsTouchPivotVert(), error finding boundary points on "
                 "2-boundary point quadrangle.");
      break;
    }

    // find lateral boundary or internal lateral diagonals. If found, add top diagonal
    std::set< std::pair<MVertex*, MVertex*> > edges_new;
    std::set< std::pair<MVertex*, MVertex*> > forbidden_new;
    std::map< MElement*, std::set< std::pair<unsigned int, unsigned int> > > problems, problems_new;
    if( p1 >= 0 && p2 >= 0 &&
        edgeExists( verts[(p1+2)%elem_size], verts[(p1+elem_size-1)%elem_size+elem_size], quadToTri_edges ) &&
        !edgeExists( verts[p1+elem_size], verts[(p1+2)%elem_size+elem_size], quadToTri_edges ) ){
      createEdge( verts[(p1+1)%elem_size+elem_size], verts[(p1+elem_size-1)%elem_size+elem_size], quadToTri_edges );
      createEdge( verts[(p1+1)%elem_size+elem_size], verts[(p1+elem_size-1)%elem_size+elem_size], edges_new );
    }
    else if( p1 >= 0 && p2 >= 0 &&
             edgeExists( verts[(p1+2)%elem_size+elem_size], verts[(p1+elem_size-1)%elem_size], quadToTri_edges ) &&
             !edgeExists( verts[(p1+1)%elem_size+elem_size], verts[(p1+elem_size-1)%elem_size+elem_size], quadToTri_edges ) ){
      createEdge( verts[p1+elem_size], verts[(p1+2)%elem_size+elem_size], quadToTri_edges );
      createEdge( verts[p1+elem_size], verts[(p1+2)%elem_size+elem_size], edges_new );
    }

    if( edges_new.size() ){
      ExtrudeDiags( gr, verts, 0, 0, j_top_start, k_top_start,
                    elem, ep, edges_new, forbidden_new,
                    quadToTri_edges, forbidden_edges, problems_new, problems, pos);
    }
  }

  return 1;

}  // end of makeEdgesForElemsTouchPivotVert()


// For use in QuadToTriEdgeGenerator:  Does the lateral edging of internal elements in the top extrusion
// layer by lowest vertex pointer value in TOP FACE.
// Added 04/08/2011
static int makeEdgesInternalTopLayer( GRegion *gr, bool is_dbl, CategorizedSourceElements &cat_src_elems,
                                      std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                      std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In makeEdgesInternalTopLayer(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In makeEdgesInternalTopLayer(), invalid model for region "
               "%d.", gr->tag() );
    return 0;
  }

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In makeEdgesForInternalTopLayer(), invalid source face for region "
               "%d.", gr->tag() );
    return 0;
  }

  if( gr != cat_src_elems.region || reg_source != cat_src_elems.source_face ){
    Msg::Error("In makeEdgesInternalTopLayer(), CatergorizedSourceElements structure data "
               " does not correspond to region %d.", reg_source->tag() );
    return 0;
  }

  // s = 0 for triangles; s = 1 for quadrangles
  for( int s = 0; s < 2; s++ ){

    // no need to do this if there are no quads!!!
    if( !reg_source->quadrangles.size() )
      break;

    std::set<unsigned int> *set_elems;
    std::set<unsigned int>::iterator it;

    if( !s )
      set_elems = &cat_src_elems.internal_tri;
    else
      set_elems = &cat_src_elems.internal_quad;

    for( it = set_elems->begin(); it != set_elems->end(); it++ ){

      MElement *elem;
      if( !s )
        elem = reg_source->triangles[(*it)];
      else
        elem = reg_source->quadrangles[(*it)];
      int elem_size = elem->getNumVertices();
      std::vector<MVertex*> verts;
      int j = ep->mesh.NbLayer-1;
      int k = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;

      getExtrudedVertices(elem, ep, j, k, pos, verts);

      // do this by lowest pointer value IN THE TOP SURFACE
      for( int p = 0; p < elem_size; p++ ){
        int ind_low = p+elem_size;
        int ind_2 = (p+1)%elem_size;
        if( verts[ind_2+elem_size] < verts[ind_low] ){
          ind_low = ind_2+elem_size;
          ind_2 = p;
        }
        createEdge( verts[ind_low], verts[ind_2], quadToTri_edges );
      }
    }
  }

  return 1;

} // End of makeEdgesInternalTopLayer()


// Generate the set of QuadToTri diagonal edges to subdivide elements,
// and records problematic elements that need to be subvided with an internal vertex.
// Added 2010-01-19
int QuadToTriEdgeGenerator(GRegion *gr,  CategorizedSourceElements &cat_src_elems,
                           std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                           std::set<std::pair<MVertex*, MVertex*> > &lat_tri_diags,
                           std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                           std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh ){
    Msg::Error("In QuadToTriEdgeGenerator(), invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag() );
    return 0;
  }

  GModel *model = gr->model();
  if( !model ){
    Msg::Error("In QuadToTriEdgeGenerator(), invalid model for region "
               "%d.", gr->tag() );
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


  // now find and verify the source and the top of region

  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source  ){
    Msg::Error("In QuadToTriEdgeGenerator(), invalid source face for region "
               "%d.", gr->tag() );
    return 0;
  }

  std::list<GFace *> reg_faces = gr->faces();
  std::list<GFace *>::iterator itf = reg_faces.begin();

  // find top surface of extrusion
  GFace *reg_top = NULL;
  for( itf = reg_faces.begin(); itf != reg_faces.end(); itf++ ){
    ExtrudeParams *face_ep = (*itf)->meshAttributes.extrude;
    if( face_ep && face_ep->geo.Mode == COPIED_ENTITY &&
        reg_source == model->getFaceByTag( std::abs(face_ep->geo.Source) ) ){
      reg_top = (*itf);
      break;
    }
  }

  if( !reg_top ){
    Msg::Error("In QuadToTriEdgeGenerator(), invalid top surface for region "
               "%d.", gr->tag() );
    return 0;
  }

  // list of forbidden edges and boundary verts that are in triangles
  std::set<std::pair<MVertex*, MVertex*> > forbidden_edges;

  // insert ALL fixed edges into quadToTri_edges, all forbidden edges on recombined quads
  // into forbidden_edges, and insert into lat_tri_diags ALL lateral diagonal edges.
  QuadToTriGetRegionDiags( gr, quadToTri_edges, forbidden_edges, lat_tri_diags, pos );
  /*unsigned int Rnum = gr->tag()-1;
  std::vector<MVertex*> verts;
  MElement *elem;
  elem = reg_source->triangles[0];
  int vert_num = getExtrudedVertices(elem, ep, 0, 0, pos, verts);
  const int elem_size = verts.size() == 8 ? 4 : 3;
  for( int p = 0; p < elem_size; p++ ){
    int state = Rnum / std::pow(3,(elem_size-1-p));
    Rnum -= state*std::pow(3,(elem_size-1-p));
    if( p < elem_size ){
      if( verts[p] == verts[p+elem_size] || verts[(p+1)%elem_size] == verts[(p+1)%elem_size+elem_size] )
        continue;
      if( state == 1 ){
        //createEdge( verts[p], verts[(p+1)%elem_size+elem_size], quadToTri_edges );
        createEdge( verts[p], verts[(p+1)%elem_size+elem_size], lat_tri_diags );
      }
      else if( state == 2 ){
        //createEdge( verts[p+elem_size], verts[(p+1)%elem_size], quadToTri_edges );
        createEdge( verts[p+elem_size], verts[(p+1)%elem_size], lat_tri_diags );
      }
      else if( state == 0 ){
        std::vector<MVertex *> v_face;
        v_face.assign(4, (MVertex*)(NULL) );
        v_face[0] = verts[p]; v_face[1] = verts[(p+1)%elem_size];
        v_face[2] = verts[(p+1)%elem_size+elem_size];
        v_face[3] = verts[p+elem_size];
         createForbidden(v_face, forbidden_edges);
      }
      else if( state != 0 )
        Msg::Error("Failed in finding all combos...state = %d.", state);
    }
    else{
      int add = (p==4) ? 0 : 4;
      if( state == 1 )
        createEdge( verts[0+add], verts[2+add], quadToTri_edges );
      else if( state == 2 )
        createEdge( verts[1+add], verts[3+add], quadToTri_edges );
      else if( state == 0 ){
        std::vector<MVertex *> v_face;
        v_face.assign(4, (MVertex*)(NULL) );
        v_face[0] = verts[0+add]; v_face[1] = verts[1+add];
        v_face[2] = verts[2+add]; v_face[3] = verts[3+add];
        createForbidden(v_face, forbidden_edges);
      }
      else
        Msg::Error("Failed in finding all combos...state = %d.", state);
    }
  }*/

  // if this is a double layer extrusion, don't need adjustable lateral edges, so
  // put all lat_tri_diags into quadToTri_edges
  if( is_dbl)
    quadToTri_edges.insert(lat_tri_diags.begin(), lat_tri_diags.end());

  // If there are no lat_tri_diags and no quads, there is nothing  left to do
  if( !lat_tri_diags.size() && !reg_source->quadrangles.size() )
    return 1;


  // can return now if this is a double layer extrusion...nothing left to do
  if( is_dbl )
    return 1;


  // BRUTE FORCE diagonalization of elements with all vertices on a lateral boundary of region:
  // This has to be done for all cases with such elements if
  if( !makeEdgesForElemsWithAllVertsOnBnd( gr, is_dbl, cat_src_elems, quadToTri_edges,
                                           lat_tri_diags, forbidden_edges, problems, pos ) ){
     Msg::Error("In QuadToTriEdgeGenerator(), failed to make edges for the elements in region %d "
                "with all vertices on a lateral boundary", gr->tag() );
     return 0;
  }

  // now do the "elegant" diagonalization of all the rest of the surface elements....


  // Extrude source triangles that are on the source boundary edges and find any diagonals
  if( !makeEdgesForOtherBndPrisms( gr, is_dbl, cat_src_elems, quadToTri_edges,
                                   lat_tri_diags, forbidden_edges, problems, pos ) ){
    Msg::Error("In QuadToTriEdgeGenerator(), failed to make edges for the prism extrusions in region %d with "
               "source triangles having some but not all vertices on the boundary", gr->tag() );
    return 0;
  }


  // For a region with a structured all-quad source surface, none of the previous edging will be executed,
  // so this is the first place a region with a structured quad source surface starts getting
  // edges.

  // The rest of this function is only necessary for a single layer quadToTri method extrusions:


  // Edge creation for extruded quadrangles with some but not all vertices on a boundary.
  if( !makeEdgesForOtherBndHexa( gr, is_dbl, cat_src_elems, quadToTri_edges,
                                 lat_tri_diags, forbidden_edges, problems, pos ) ){
    Msg::Error("In QuadToTriEdgeGenerator(), failed to make edges for the hexahedral extrusions in region %d with "
               "source quads having some but not all vertices on the boundary", gr->tag() );
    return 0;
  }


  // Find diagonals for elements touching a "pivot vertex" of a hexa element that has
  // a source quad with only one vertex on a lateral boundary (see inside makeEdgesForOtherBndHexa() and
  // makeEdgesForElemsTouchingPivotVert() for details of "pivot vertex".
  if( !makeEdgesForElemsTouchPivotVert( gr, is_dbl, cat_src_elems, quadToTri_edges,
                                        lat_tri_diags, forbidden_edges, pos ) ){
    Msg::Error("In QuadToTriEdgeGenerator(), failed to make edges for "
               "the elements in region %d touching a \'pivot vertex\' of a "
               "hexa element with source quad having one vertex on a boundary.", gr->tag() );
    return 0;
  }

  // Mesh internal elements in the top layer (just add lateral diagonals for the
  // Do this by lowest pointer in top surface
  if( !makeEdgesInternalTopLayer( gr, is_dbl, cat_src_elems, quadToTri_edges, pos ) ){
    Msg::Error("In QuadToTriEdgeGenerator(), failed to make internal edges "
               "in top extrusion layer of region %d.", gr->tag() );
    return 0;
  }

  return 1;

}  // End of QuadToTriEdgeGenerator()


// Remesh the lateral 2D faces of QuadToTri regions using edges in quadToTri_edges as contraints
// Added 2010-01-24
static bool QuadToTriLateralRemesh( GRegion *gr, std::set<std::pair<MVertex*,MVertex*> > &quadToTri_edges )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh )
    return false;

  GModel *model = gr->model();

  // find source face
  GFace *reg_source = model->getFaceByTag( std::abs( ep->geo.Source ) );
  if( !reg_source ){
    Msg::Error("In QuadToTriLateralRemesh(), could not find source face "
               "%d for region %d.", std::abs( ep->geo.Source ),
               gr->tag() );
    return false;
  }


  // Find a source surface, find a COPIED_ENTITY that is the top surface,
  // If shared laterals are all static (quad or non subdivide triangles),
  // set the allStaticSharedLaterals argument to true.
  // If any lateral is unstructured, error.

  bool foundTop = false;
  GFace *reg_top = NULL;
  std::list<GFace *> faces = gr->faces();
  std::list<GFace *>::iterator it = faces.begin();

  for( it = faces.begin(); it != faces.end(); it++ ){
    ExtrudeParams *face_tmp_ep = (*it)->meshAttributes.extrude;
    if( face_tmp_ep && face_tmp_ep->geo.Mode ==
        COPIED_ENTITY ){
      GFace *top_source_tmp = model->getFaceByTag(
                              std::abs( face_tmp_ep->geo.Source ) );
      if( !top_source_tmp ){
        Msg::Error("In QuadToTriLateralRemesh(), could not find source face "
                   "%d for copied surface %d of region %d.",
                   std::abs( face_tmp_ep->geo.Source ),
                   (*it)->tag(), gr->tag() );
      }
      else if( top_source_tmp == reg_source ){
        foundTop = true;
        reg_top = (*it);
      }
    }
  }

  if( !foundTop )
    Msg::Warning("In QuadToTriLateralRemesh(), could not find top face "
                 "for region %d.", gr->tag() );

  Msg::Info("Remeshing lateral surfaces for QuadToTri region %d.", gr->tag() );

  // now loop through faces again, remeshing all laterals that need it.
  for( it = faces.begin(); it != faces.end(); it++ ){
    if( (*it) != reg_top && (*it) != reg_source &&
        IsSurfaceALateralForRegion(gr, *it)
        &&
        (*it)->triangles.size() && !(*it)->quadrangles.size() ){

      // *** JUST REMESH EVERY TRIANGLE SURFACE AGAIN TO BE SURE ***

      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
        delete (*it)->triangles[i];
      (*it)->triangles.clear();
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
        delete (*it)->quadrangles[i];
      (*it)->quadrangles.clear();
      MeshExtrudedSurface((*it), &quadToTri_edges);
    }
  }
  return foundTop;
}


// Adds the face- or body-center vertices needed for some QuadToTri elements
static bool addFaceOrBodyCenteredVertices( GRegion *to, CategorizedSourceElements &c,
                                           std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                           std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                           bool is_dbl, unsigned int lat_tri_diags_size,
                                           std::set<MVertex *, MVertexLessThanLexicographic> &pos )
{

  ExtrudeParams *ep = to->meshAttributes.extrude;
  if( !ep || !ep->mesh.ExtrudeMesh || !ep->mesh.QuadToTri )
    return false;

  GModel *model = to->model();
  GFace *from = model->getFaceByTag( std::abs(ep->geo.Source) );
  if( !from )
    return false;

  // need these for double layer extrusion purposes
  int j_second_from_top, k_second_from_top;
  if( ep->mesh.NbElmLayer[ep->mesh.NbLayer-1] > 1 ){
    j_second_from_top = ep->mesh.NbLayer-1;
    k_second_from_top = ep->mesh.NbElmLayer[j_second_from_top]-2;
  }
  else{
    j_second_from_top = std::max(ep->mesh.NbLayer-2, 0);
    k_second_from_top = ep->mesh.NbElmLayer[j_second_from_top]-1;
  }

  // find number of layers;
  unsigned int num_layer = 0;
  for( int p = 0; p < ep->mesh.NbLayer; p++ )
    num_layer += ep->mesh.NbElmLayer[p];

  // If !is_dbl, make the body centered internal vertices for all "problem" elements
  // If is_dbl, make face-centered verts where needed

  // create reserve capacity for the temp vector of new vertices:
  unsigned int cap_add = 0;
  if( !is_dbl ){
    std::map<MElement *, std::set< std::pair<unsigned int, unsigned int> > >::iterator itmap;
    for( itmap = problems.begin(); itmap != problems.end(); itmap++ )
      cap_add += itmap->second.size();
    to->mesh_vertices.reserve(to->mesh_vertices.size()+cap_add);
  }
  else{
    unsigned int NbBndElems = c.four_bnd_pt_quad.size() + c.three_bnd_pt_tri.size() +
                              c.other_bnd_quad.size()   + c.other_bnd_tri.size();
    unsigned int NbSourceElems = from->triangles.size() + from->quadrangles.size();
    cap_add = NbSourceElems + NbBndElems * ( num_layer-2 > 0 ? num_layer-2 : 0 );
  }

  // first the !is_dbl case
  if( problems.size() && !is_dbl ){
    std::map<MElement *, std::set< std::pair<unsigned int, unsigned int> > >::iterator itmap;
    for( itmap = problems.begin(); itmap != problems.end(); itmap++ ){
      MElement *elem = itmap->first;
      std::set< std::pair<unsigned int, unsigned int> >::iterator itpairs;
      for( itpairs = itmap->second.begin(); itpairs != itmap->second.end(); itpairs++ ){
        std::vector<MVertex *> verts;
        int j = (*itpairs).first;
        int k = (*itpairs).second;
        getExtrudedVertices(elem, ep, j, k, pos, verts);
        QtMakeCentroidVertex(verts, &(to->mesh_vertices), to, pos);
      }
    }
  }

  if( !is_dbl )
    return 1;

  // The rest of the function works for is_dbl, double layer quadToTri extrusion


  //Holds the new vertices...put them in to->mesh_vertices only at the end
  std::vector<MVertex *> v_tmp;
  v_tmp.reserve(cap_add);

  // triangles and quadrangles
  // t =0 triangles, t=1 quadrangles
  std::vector<MVertex*> verts3D;
  for( int t = 0; t < 2; t++ ){
    for( int s = 0; s < 3; s++ ){
      std::set<unsigned int> *set_elems;
      if( !t ){
        if( !s )        set_elems = &c.three_bnd_pt_tri;
        else if( s==1 ) set_elems = &c.other_bnd_tri;
        else            set_elems = &c.internal_tri;
      }
      else{
        if( !s )        set_elems = &c.four_bnd_pt_quad;
        else if( s==1 ) set_elems = &c.other_bnd_quad;
        else            set_elems = &c.internal_quad;
      }
      std::set<unsigned int>::iterator itset;
      for( itset = set_elems->begin(); itset != set_elems->end(); itset++ ){
        MElement *elem;
        if( !t ) elem = from->triangles[(*itset)];
        else     elem = from->quadrangles[(*itset)];
        int elem_size = elem->getNumVertices();
        // see if this element is on a boundary with lat_tri_diags or a degenerated hexahedron (always divide those)
        bool found_diags = false;
        bool degen_hex = false;
        verts3D.resize(0);
        getExtrudedVertices( elem, ep, 0, 0, pos, verts3D);
        for( int p = 0; p < elem_size; p++ ){
          // always look for degen hex
          if( t && verts3D[p] == verts3D[p+elem_size] &&
              verts3D[(p+1)%elem_size] != verts3D[(p+1)%elem_size+elem_size] &&
              verts3D[(p+elem_size-1)%elem_size] != verts3D[(p+elem_size-1)%elem_size+elem_size] ){
            degen_hex = true;
            break;
          }
          // skip the rest if no lat_tri_diags or if not on lateral boundary
          if( !lat_tri_diags_size || s >= 2 )
            continue;
          // if a triangle face, skip it
          if( verts3D[p] == verts3D[p+elem_size] ||
                   verts3D[(p+1)%elem_size] == verts3D[(p+1)%elem_size+elem_size] )
            continue;
          else if( edgeExists( verts3D[p], verts3D[(p+1)%elem_size+elem_size], quadToTri_edges ) )
            found_diags = true;
          else if( edgeExists( verts3D[p+elem_size], verts3D[(p+1)%elem_size], quadToTri_edges ) )
            found_diags = true;
        }
        // triangle extrusions don't need face centered verts if NO diags found
        // or if not on lateral boundary
        if( !t && ( !found_diags || s==2 ) )
          continue;

        int j_start, k_start;
        if( (s < 2 && found_diags) || degen_hex ){
          j_start = 0;
          k_start = 0;
        }
        else{  // only non quads not extruded into degen hexa should execute this
          j_start = j_second_from_top;
          k_start = k_second_from_top;
        }
        std::vector<MVertex*> v_face;
        for( int j = j_start; j < ep->mesh.NbLayer; j++ ){
          int k_start_tmp = (j == j_start) ? k_start : 0;
          int k_stop = (j == ep->mesh.NbLayer-1)
                       ? ep->mesh.NbElmLayer[j]-1 : ep->mesh.NbElmLayer[j];
          for( int k = k_start_tmp; k < k_stop; k++ ){
            v_face.resize(0);
            get2DExtrudedVertices( elem, ep, j, k+1, pos, v_face);
            QtMakeCentroidVertex(v_face, &v_tmp, to, pos);
          }
        }
      }
    }
  }
  // Don't forget to add v_tmp to to->mesh_vertices!!!
  to->mesh_vertices.reserve( to->mesh_vertices.size() + v_tmp.size() );
  for(unsigned int p = 0; p < v_tmp.size(); p++ )
    to->mesh_vertices.push_back(v_tmp[p]);
  return 1;

}



// Meshes either a prism or a hexahedral set of mesh vertices with an internal vertex
// created here in the function.
// Added 2010-03-30
static void MeshWithInternalVertex( GRegion *to, MElement *source, std::vector<MVertex *> v, std::vector<int> n1,
                                    std::vector<int> n2, std::set<MVertex *, MVertexLessThanLexicographic> &pos )
{

  int v_size = v.size();
  int n_lat_tmp;
  if( v_size == 6 )
    n_lat_tmp = 3;
  else if( v_size == 8 )
    n_lat_tmp = 4;
  else{
    Msg::Error("In MeshWithInternalVertex(), number of element vertices does not equal 6 or 8.");
    return;
  }

  const int n_lat = n_lat_tmp;

  if( (n_lat == 3 && n1.size() != 3) || (n_lat == 4 && n2.size() != 6) ){
    Msg::Error("In MeshWithInternalVertex(), size of diagonal node vectors is not does not equal 3 or 6.");
    return;
  }

  // find the internal vertex
  std::vector<double> centroid = QtFindVertsCentroid(v);
  MVertex tmp(centroid[0], centroid[1], centroid[2], 0, -1);

  // it's too dangerous to use the 'new' command in here even with face-centered vertices.

  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
  itp = pos.find(&tmp);
  if(itp == pos.end()){ // FIXME: workaround
    Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
    itp = tmp.linearSearch(pos);
  }
  if(itp == pos.end()){
    Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g) in geometrical entity %d",
                tmp.x(), tmp.y(), tmp.z(), to->tag());
    Msg::Error("MeshWithInternalVertex() failed to find body-centered vertex.");
    return;
  }

  MVertex *v_int = (*itp);

  // build all pyramids/tetra
  for( int p = 0; p < n_lat; p++ ){
    int p2 = (p+1)%n_lat;
    if( v[p] == v[p+n_lat] && v[p2] == v[p2+n_lat] )
      continue;
    else if( v[p] == v[p+n_lat] || v[p2] == v[p2+n_lat] ){
      MVertex *v_dup = (v[p] == v[p+n_lat]) ? v[p] : v[p2];
      MVertex *v_non_dup = (v_dup == v[p]) ? v[p2] : v[p];
      MVertex *v_non_dup2 = (v_non_dup == v[p]) ? v[p+n_lat] : v[p2+n_lat];
      addTetrahedron( v_dup, v_non_dup, v_non_dup2, v_int, to, source );
    }
    else if( n1[p] == p || n2[p] == p ){
      addTetrahedron( v[p], v[p2], v[p2+n_lat], v_int, to, source );
      addTetrahedron( v[p], v[p2+n_lat], v[p+n_lat], v_int, to, source );
    }
    else if( n1[p] == p+n_lat || n2[p] == p+n_lat ){
      addTetrahedron( v[p], v[p2], v[p+n_lat], v_int, to, source );
      addTetrahedron( v[p2], v[p2+n_lat], v[p+n_lat], v_int, to, source );
    }
    else
      addPyramid( v[p], v[p2], v[p2+n_lat], v[p+n_lat], v_int, to, source );
  }

  if( n_lat == 3){
    // bottom and top
    addTetrahedron( v[0], v[1], v[2], v_int, to, source);
    addTetrahedron( v[3], v[5], v[4], v_int, to, source);
  }
  else if( n_lat == 4 ){
    for( int p = 4; p < 6; p++ ){
      int add = (p == 4) ? 0 : 4;
      if( n1[p] == 0+add || n2[p] == 0+add  ){
        addTetrahedron( v[add], v[1+add], v[2+add], v_int, to, source );
        addTetrahedron( v[add], v[2+add], v[3+add], v_int, to, source );
      }
      else if( n1[p] == 1+add || n2[p] == 1+add ){
        addTetrahedron( v[1+add], v[2+add], v[3+add], v_int, to, source );
        addTetrahedron( v[1+add], v[3+add], v[add], v_int, to, source );
      }
      else
        addPyramid( v[add], v[1+add], v[2+add], v[3+add], v_int, to, source );
    }
  }

}

// Meshes either a prism or a hexahedral set of mesh vertices with face centered vertices
// Can pick top or bottom faces to have the vertex, or both, based on the top_flag and bottom_flag args.
// created here in the code
// Added 2010-04-05
static void MeshWithFaceCenteredVertex( GRegion *to, MElement *source, std::vector<MVertex *> v, std::vector<int> n1,
                                        std::vector<int> n2, bool bottom_flag, bool top_flag,
                                        std::set<MVertex *, MVertexLessThanLexicographic> &pos )
{

  int v_size = v.size();
  int n_lat_tmp;
  if( v_size == 6 )
    n_lat_tmp = 3;
  else if( v_size == 8 )
    n_lat_tmp = 4;
  else{
    Msg::Error("In MeshWithFaceCenteredVertex(), number of element vertices does not equal 6 or 8.");
    return;
  }

  const int n_lat = n_lat_tmp;

  if( !top_flag && !bottom_flag ){
    Msg::Error("In MeshWithFaceCenteredVertex(), neither the top nor the bottom face were selected for vertex creation.");
    return;
  }

  if( (n_lat == 3 && n1.size() != 3) || (n_lat == 4 && n2.size() != 6) ){
    Msg::Error("In MeshWithFaceCenteredVertex(), size of diagonal node vectors is not does not equal 3 or 6.");
    return;
  }

  std::vector<MVertex *> face_vertices;
  // create the face-centered vertices
  for( int s = 0; s < 2; s++ ){
    if( (!s && !bottom_flag) || (s && !top_flag) )
      continue;
    std::vector<MVertex *> v_face;
    v_face.assign(n_lat, (MVertex*)(NULL) );
    int add = !s ? 0 : n_lat;
    for( int t = 0; t < n_lat; t++ )
      v_face[t] = v[t+add];

    std::vector<double> centroid = QtFindVertsCentroid(v_face);
    MVertex tmp(centroid[0], centroid[1], centroid[2], 0, -1);

    // it's too dangerous to use the 'new' command in here on face-centered vertices.

    std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
    itp = pos.find(&tmp);
    if(itp == pos.end()){ // FIXME: workaround
      Msg::Info("Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
      itp = tmp.linearSearch(pos);
    }
    if(itp == pos.end()){
      Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g) in geometrical entity %d",
                  tmp.x(), tmp.y(), tmp.z(), to->tag());
      Msg::Error("MeshWithFaceCenteredVertex() failed to find face-centered vertex.");
      return;
    }

    face_vertices.push_back(*itp);

  }

  // If just one face-centered vertex, make a pyramid/tetra (or base-divided pyramid )
  // with the face-centered vertex as the apex. Fill in
  // pyramids/tetra aroud it laterally.
  if( face_vertices.size() == 1 ){
    int base, add;
    if( top_flag ){
      base = n_lat;
      add = 0;
    }
    else{
      base = n_lat+1;
      add = n_lat;
    }
    if( n_lat == 4 && n1[base] >= 0 ){
      addTetrahedron( v[n1[base]], v[n2[base]], v[(n1[base]-add+1)%n_lat+add], face_vertices[0], to, source );
      addTetrahedron( v[n1[base]], v[n2[base]], v[(n1[base]-add+n_lat-1)%n_lat+add], face_vertices[0], to, source );
    }
    else if( n_lat == 4 )
      addPyramid( v[0+add], v[1+add], v[2+add], v[3+add], face_vertices[0], to, source );
    else
      addTetrahedron( v[0+add], v[1+add], v[2+add], face_vertices[0], to, source );

    for( int p = 0; p < n_lat; p++ ){
      int p2 = (p+1)%n_lat;
      if( v[p] == v[p+n_lat] && v[p2] == v[p2+n_lat] )
        continue;
      else if( v[p] == v[p+n_lat] || v[p2] == v[p2+n_lat] ){
        MVertex *v_dup = (v[p] == v[p+n_lat]) ? v[p] : v[p2];
        MVertex *v_non_dup = (v_dup == v[p]) ? v[p2] : v[p];
        MVertex *v_non_dup2 = (v_non_dup == v[p]) ? v[p+n_lat] : v[p2+n_lat];
        addTetrahedron( v_dup, v_non_dup, v_non_dup2, face_vertices[0], to, source );
      }
      else if( n1[p] >= 0 ){
        int add_2 = n1[p] < n_lat ? n_lat : -n_lat;
        addTetrahedron( v[n1[p]], v[n2[p]], v[n1[p]+add_2], face_vertices[0], to, source );
        addTetrahedron( v[n1[p]], v[n2[p]], v[n2[p]-add_2], face_vertices[0], to, source );
      }
      else
        addPyramid( v[p], v[p+n_lat], v[p2+n_lat], v[p2], face_vertices[0], to, source );
    }
    return;
  }

   // If two face-centered vertices, make prisms around the central axis formed by the face-centered vertices.
  // Divide the prisms on the two inside faces to make the validity of the subdivision independent of the outer
  // later surface states (diagonalized or not)
  else if( face_vertices.size() == 2 ){
    for( int p = 0; p < n_lat; p++ ){
      int p2 = (p+1)%n_lat;
      if( v[p] == v[p+n_lat] && v[p2] == v[p2+n_lat] ){
        addTetrahedron( v[p], v[p2], face_vertices[0], face_vertices[1], to, source );
      }
      else if( v[p] == v[p+n_lat] || v[p2] == v[p2+n_lat] ){
        MVertex *v_dup = (v[p] == v[p+n_lat]) ? v[p] : v[p2];
        MVertex *v_non_dup = (v_dup == v[p]) ? v[p2] : v[p];
        MVertex *v_non_dup2 = (v_non_dup == v[p]) ? v[p+n_lat] : v[p2+n_lat];
        addTetrahedron( v_non_dup, v_non_dup2, face_vertices[1], v_dup, to, source );
        addTetrahedron( v_non_dup, face_vertices[0], face_vertices[1], v_dup, to, source );
      }
      else{
        addTetrahedron( v[p], v[(p+1)%n_lat], face_vertices[1], face_vertices[0], to, source );
        if( n1[p] >= 0 ){
          int add_2 = n1[p] < n_lat ? n_lat : -n_lat;
          addTetrahedron( v[n1[p]], v[n2[p]], v[n1[p]+add_2], face_vertices[1], to, source );
          addTetrahedron( v[n1[p]], v[n2[p]], v[n2[p]-add_2], face_vertices[1], to, source );
        }
        else
          addPyramid( v[p], v[p+n_lat], v[(p+1)%n_lat+n_lat], v[(p+1)%n_lat], face_vertices[1], to, source );
      }
    }
    return;
  }

  // If execute to here, send error message
  Msg::Error("MeshWithFaceCenteredVertex() failed. on region %d", to->tag() );

}


// Construct the elements that subdivide a prism (or degenerated prism)  in a QuadToTri interface;
// Added 2010-01-24
static inline void QuadToTriPriPyrTet(std::vector<MVertex*> &v, GRegion *to, int j,
                              int k, MElement* source,
                              std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                              std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                              std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                              unsigned int lat_tri_diags_size, bool bnd_elem, bool is_dbl, bool diag_search,
                              std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{
  int dup[3];
  int m = 0;
  for(int i = 0; i < 3; i++)
    if(v[i] == v[i + 3])
      dup[m++] = i;


  ExtrudeParams *ep = to->meshAttributes.extrude;

  // need these for double layer extrusion purposes
  unsigned int j_second_from_top = 0, k_second_from_top = 0;
  if( ep ){
    if( ep->mesh.NbElmLayer[ep->mesh.NbLayer-1] > 1 ){
      j_second_from_top = ep->mesh.NbLayer-1;
      k_second_from_top = ep->mesh.NbElmLayer[j_second_from_top]-2;
    }
    else{
      j_second_from_top = std::max(ep->mesh.NbLayer-2, 0);
      k_second_from_top = ep->mesh.NbElmLayer[j_second_from_top]-1;
    }
  }


  bool is_problem = false;
  if( !is_dbl ){
    std::pair<unsigned int, unsigned int> jk_pair (j,k);
    std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > >::iterator itprob;
    itprob = problems.find(source);
    if( itprob != problems.end() ){
      if( (*itprob).second.find(jk_pair) != (*itprob).second.end() )
        is_problem = true;
    }
  }

  if( m && is_problem ){
    Msg::Error("In QuadToTriPriPyrTet(), non-prismatic extrusion of triangle in region %d "
               "marked as needing internal vertex to complete. Skipping....", to->tag() );
    return;
  }

  // BAD SHAPE
  if( m > 2 || m < 0 ){
    Msg::Error("In QuadToTriPriPyrTet(), bad number of degenerate corners.");
    return;
  }

  // find vertex node indices for diagonalized faces
  std::vector<int> n1, n2;
  bool found_diags = false;
  n1.assign(3, -1);
  n2.assign(3, -2);
  if( diag_search ){
    for( int p = 0; p < 3; p++ ){
      n1[p] = -p*p-p-1; n2[p] = -p*p-p-2;
      if( v[p] == v[p+3] || v[(p+1)%3] == v[(p+1)%3+3] )
        continue;
      else if( edgeExists( v[p], v[(p+1)%3+3], quadToTri_edges ) ){
        n1[p] = p; n2[p] = (p+1)%3+3;
        found_diags = true;
      }
      else if( edgeExists( v[p+3], v[(p+1)%3], quadToTri_edges ) ){
        n1[p] = p+3; n2[p] = (p+1)%3;
        found_diags = true;
      }
    }
  }

  // mesh double layer
  // is this prism part of a QuadToTri Double Layer extrusion and does it need to be extruded as such?
  if( is_dbl && bnd_elem && found_diags ){
    if( j==0 && k==0 )
      MeshWithFaceCenteredVertex( to, source, v, n1, n2, 0, 1, pos );
    else if( j >= ep->mesh.NbLayer-1 && k >= ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1 )
      MeshWithFaceCenteredVertex( to, source, v, n1, n2, 1, 0, pos );
    else
      MeshWithFaceCenteredVertex( to, source, v, n1, n2, 1, 1, pos );
    return;
  }

  // The rest are for single layer extrusions or degenerate prisms:


  // tetrahedron
  if( m == 2 && !is_problem ) {
    int dup_face = (dup[0]+1)%3 == dup[1] ? dup[0] : dup[1];
    addTetrahedron(v[dup_face], v[(dup_face+1)%3], v[(dup_face+2)%3], v[(dup_face+2)%3+3], to, source);
    return;
  }
  // pyramid
  else if( m == 1 && !is_problem ) {
    int p = (dup[0]+1)%3;
    // determine if the pyramid is sliced into two tetrahedra
    if( n1[p] >= 0 ){
      int add = n1[p] < 3 ? 3 : -3;
      addTetrahedron(v[n1[p]], v[n2[p]], v[n1[p]+add], v[dup[0]], to, source);
      addTetrahedron(v[n1[p]], v[n2[p]-add], v[n2[p]], v[dup[0]], to, source);
    }
    else // pyramid
      addPyramid( v[p], v[p+3], v[(p+1)%3+3], v[(p+1)%3], v[dup[0]], to, source);

   return;
  }


  // Full prism: Start looking for a diagonal on a lateral.
  else if( m == 0 && !is_problem ){
    if( !found_diags ){
      addPrism( v[0], v[1], v[2], v[3], v[4], v[5], to, source );
      return;
    }
    else{
      for( int p = 0; p < 3; p++ ){
        if( n1[p] >= 0 && n2[p] == n1[(p+1)%3] ){
          int add = n2[p] < 3 ? 3 : -3;
          int tet_top = n2[p]+add;
          int pyr_top = n2[p];
          int base = (p+2)%3;
          addTetrahedron( v[n1[p]], v[n2[p]], v[n2[(p+1)%3]], v[tet_top], to, source );
          if( n1[(p+2)%3] >= 0 ){
            int add_2 = n1[base] < 3 ? 3 : -3;
            addTetrahedron( v[n1[base]], v[n2[base]], v[n1[base]+add_2], v[pyr_top], to, source );
            addTetrahedron( v[n1[base]], v[n2[base]], v[n2[base]-add_2], v[pyr_top], to, source );
          }
          else
            addPyramid( v[base], v[base+3], v[(base+1)%3+3], v[(base+1)%3], v[pyr_top], to, source );
          return;
        }
      }
    }
  }


  // At this point, if the function has not returned, element must be meshed with an additional vertex

  if( !is_problem ) {
    Msg::Error("In QuadToTriPriPyrTet(), Extruded prism needs subdivision, but cannot "
               " be divided without internal vertex, but was not previously detected as such. "
               " This is a bug. Please Report.");
    Msg::Error("j: %d, k: %d", j, k);
    QtMakeCentroidVertex( v, &(to->mesh_vertices), to, pos );
    std::pair<unsigned int, unsigned int> jk_pair(j,k);
    problems_new[source].insert(jk_pair);
    is_problem = true;
  }

  if( is_problem ){
    MeshWithInternalVertex( to, source, v, n1, n2, pos );
    return;
  }



}


// Construct the elements that subdivde a two-point degenerated hexahedron (prism).
static inline bool createTwoPtDegenHexElems( std::vector<MVertex*> &v, GRegion *to, ExtrudeParams *ep, int j,
                                      int k, int dup[], MElement* source, std::vector<int> n1, std::vector<int> n2,
                                      std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                      unsigned int lat_tri_diags_size, bool bnd_elem, bool is_dbl, bool found_diags,
                                      std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  if( !ep )
    return 0;

  // first find out what is the degenerate face
  int degen_face = (dup[0]+1)%4 == dup[1] ? dup[0] : dup[1];

  // if no diags found, make a prism and return
  if( !found_diags ){
    addPrism( v[degen_face], v[(degen_face+3)%4], v[(degen_face+3)%4+4],
              v[(degen_face+1)%4], v[(degen_face+2)%4], v[(degen_face+2)%4+4], to, source );
    return 1;
  }

  int tet_top = -1;
  int pyr_top = -2;

  // if faces 4 and 5 can make a slice
  if( n1[4] >= 0 &&
      ( n1[4]+4 == n1[5] || n2[4]+4 == n1[5] ) ){
    if( n1[4] == degen_face || n2[4] == degen_face ){
      pyr_top = degen_face;
      tet_top = (degen_face+1)%4;
    }
    else{
      pyr_top = (degen_face+1)%4;
      tet_top = degen_face;
    }
    addTetrahedron( v[pyr_top], v[(pyr_top+2)%4], v[(pyr_top+2)%4+4], v[tet_top], to, source );

    int base = (degen_face+2)%4;
    if( n1[base] >= 0 ){
      int add = n1[base] > 3 ? -4 : 4;
      addTetrahedron( v[n1[base]], v[n2[base]], v[n1[base]+add], v[pyr_top], to, source );
      addTetrahedron( v[n1[base]], v[n2[base]-add], v[n2[base]], v[pyr_top], to, source );
    }
    else
      addPyramid( v[base], v[base+4], v[(base+1)%4+4], v[(base+1)%4], v[pyr_top], to, source );

    return 1;
  }

  // if faces 4 and (degen_face+2)%4 make a slice
  if( tet_top < 0 && n1[4] >= 0 &&
      ( n1[4] == n1[(degen_face+2)%4] || n2[4] == n1[(degen_face+2)%4] ||
        n1[4] == n2[(degen_face+2)%4] || n2[4] == n2[(degen_face+2)%4] ) ){
    pyr_top = n1[(degen_face+2)%4] < 4 ? n1[(degen_face+2)%4] : n2[(degen_face+2)%4];
    tet_top = pyr_top==(degen_face+2)%4 ? (degen_face+3)%4 : (degen_face+2)%4;

    addTetrahedron( v[pyr_top], v[tet_top+4], v[(pyr_top+2)%4], v[tet_top], to, source );

    int base = 5;
    if( n1[base] >= 0 ){
      addTetrahedron( v[n1[base]], v[n2[base]], v[(n1[base]-4+1)%4+4], v[pyr_top], to, source );
      addTetrahedron( v[n1[base]], v[n2[base]], v[(n1[base]-4+3)%4+4], v[pyr_top], to, source );
    }
    else
      addPyramid( v[4], v[5], v[6], v[7], v[pyr_top], to, source );

    return 1;

  }

  // if faces 5 and (degen_face+2)%4 make a slice
  if( tet_top < 0 && n1[5] >= 0 &&
      ( n1[5] == n1[(degen_face+2)%4] || n2[5] == n1[(degen_face+2)%4] ||
        n1[5] == n2[(degen_face+2)%4] || n2[5] == n2[(degen_face+2)%4] ) ){
    pyr_top = n1[(degen_face+2)%4] < 4 ? n2[(degen_face+2)%4] : n1[(degen_face+2)%4];
    tet_top = pyr_top==(degen_face+2)%4+4 ? (degen_face+3)%4+4 : (degen_face+2)%4+4;

    addTetrahedron( v[pyr_top], v[(pyr_top-4+2)%4+4], v[tet_top-4], v[tet_top], to, source );

    int base = 4;
    if( n1[base] >= 0 ){
      addTetrahedron( v[n1[base]], v[n2[base]], v[(n1[base]+1)%4], v[pyr_top], to, source );
      addTetrahedron( v[n1[base]], v[n2[base]], v[(n1[base]+3)%4], v[pyr_top], to, source );
    }
    else
      addPyramid( v[0], v[1], v[2], v[3], v[pyr_top], to, source );

    return 1;
  }

  return 0;

}  // end of createTwoPtDegenHexElems()



// Construct the elements that subdivide a one-point degenerated hexahedron extrusion
static inline bool createOnePtDegenHexElems( std::vector<MVertex*> &v, GRegion *to, ExtrudeParams *ep, int j,
                                      int k, int dup[], MElement* source, std::vector<int> n1, std::vector<int> n2,
                                      std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                      std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                      unsigned int lat_tri_diags_size, bool bnd_elem, bool is_dbl, bool found_diags,
                                      std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  if( !ep )
    return 0;

  // if no diags, then just make the degenerate hexahedron and be done
  if( !found_diags ){
    addHexahedron( v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], to, source );
    Msg::Error("Degenerated hexahedron in extrusion of volume %d", to->tag());
    return 1;
  }
  // test for top and bottom diagonals parallel and incident on degen vertex
  else if( ( n1[4] == dup[0] || n2[4] == dup[0] ) &&
      ( n1[5] == dup[0]+4 || n2[5] == dup[0]+4 ) ){
    // first pyramid / tet set
    if( n1[(dup[0]+1)%4] >= 0 ){
      if( n1[(dup[0]+1)%4] == (dup[0]+1)%4 ){
        addTetrahedron( v[(dup[0]+1)%4], v[(dup[0]+1)%4+4], v[(dup[0]+2)%4+4], v[dup[0]], to, source );
        addTetrahedron( v[(dup[0]+1)%4], v[(dup[0]+2)%4+4], v[(dup[0]+2)%4], v[dup[0]], to, source );
      }
      else if( n1[(dup[0]+1)%4] == (dup[0]+1)%4+4 ){
        addTetrahedron( v[(dup[0]+1)%4+4], v[(dup[0]+2)%4], v[(dup[0]+1)%4], v[dup[0]], to, source );
        addTetrahedron( v[(dup[0]+1)%4+4], v[(dup[0]+2)%4+4], v[(dup[0]+2)%4], v[dup[0]], to, source );
      }
      else
        Msg::Error("1: In QuadToTriHexPri(), badly subdivided degenerate hexahedron. Mesh for region %d has errors.",
                   to->tag() );
    }
    else
      addPyramid( v[(dup[0]+1)%4], v[(dup[0]+1)%4+4], v[(dup[0]+2)%4+4], v[(dup[0]+2)%4], v[dup[0]], to, source );
    // second pyramid / tet set
    if( n1[(dup[0]+2)%4] >= 0 ){
      if( n1[(dup[0]+2)%4] == (dup[0]+2)%4 ){
        addTetrahedron( v[(dup[0]+2)%4], v[(dup[0]+2)%4+4], v[(dup[0]+3)%4+4], v[dup[0]], to, source );
        addTetrahedron( v[(dup[0]+2)%4], v[(dup[0]+3)%4+4], v[(dup[0]+3)%4], v[dup[0]], to, source );
      }
      else if( n1[(dup[0]+2)%4] == (dup[0]+2)%4+4 ){
        addTetrahedron( v[(dup[0]+2)%4+4], v[(dup[0]+3)%4], v[(dup[0]+2)%4], v[dup[0]], to, source );
        addTetrahedron( v[(dup[0]+2)%4+4], v[(dup[0]+3)%4+4], v[(dup[0]+3)%4], v[dup[0]], to, source );
      }
      else
        Msg::Error("2: In QuadToTriHexPri(), badly subdivided degenerate hexahedron. Mesh for region %d has errors.",
                   to->tag() );
    }
    else
      addPyramid( v[(dup[0]+2)%4], v[(dup[0]+2)%4+4], v[(dup[0]+3)%4+4], v[(dup[0]+3)%4], v[dup[0]], to, source );
    return 1;
  }

  // test for top and bottom diagonals parallel and NOT on degen vertex
  else if( ( n1[4] == (dup[0]+1)%4 || n2[4] == (dup[0]+1)%4 ) &&
           ( n1[5] == (dup[0]+1)%4+4 || n2[5] == (dup[0]+1)%4+4 ) ){
    // See if the prism section has to be divided and if it requires the inner surface to be cut

    int tet_top = -1;
    int n_inner[2];
    n_inner[0] = -1;
    n_inner[1] = -2;
    if( n1[(dup[0]+1)%4] >= 0 && n1[(dup[0]+2)%4] != n2[(dup[0]+1)%4] ){
      tet_top = n1[(dup[0]+1)%4];
      n_inner[0] = n1[(dup[0]+1)%4];
      int add = n_inner[0] > 3 ? 0 : 4;
      n_inner[1] = (dup[0]+3)%4+add;
    }
    else if( n1[(dup[0]+2)%4] >= 0 && n1[(dup[0]+2)%4] != n2[(dup[0]+1)%4] ){
      tet_top = n2[(dup[0]+2)%4];
      n_inner[1] = n2[(dup[0]+2)%4];
      int add = n_inner[1] > 3 ? 0 : 4;
      n_inner[0] = (dup[0]+1)%4+add;
    }
    else if( n1[(dup[0]+1)%4] >= 0 )
      tet_top = n2[(dup[0]+1)%4];

    if( tet_top >= 0 ){
      int add = tet_top > 3 ? 0 : 4;
      addTetrahedron( v[(dup[0]+1)%4+add], v[(dup[0]+2)%4+add], v[(dup[0]+3)%4+add], v[tet_top], to, source );
      if( n_inner[0] < 0 )
        addPyramid( v[(dup[0]+1)%4], v[(dup[0]+1)%4+4], v[(dup[0]+3)%4+4], v[(dup[0]+3)%4], v[tet_top], to, source );
      else{
        int base = tet_top-4+add == (dup[0]+1)%4 ? (dup[0]+2)%4 : (dup[0]+1)%4;
        if( n1[base] < 0 )
          addPyramid( v[base], v[base+4], v[(base+1)%4+4], v[(base+1)%4], v[tet_top], to, source );
        else{
          int add_2 = n1[base] > 3 ? -4 : 4;
          addTetrahedron( v[n1[base]], v[n1[base]+add_2], v[n2[base]], v[tet_top], to, source );
          addTetrahedron( v[n1[base]], v[n2[base]], v[n2[base]-add_2], v[tet_top], to, source );
        }
      }
    }
    else
      addPrism( v[(dup[0]+1)%4], v[(dup[0]+2)%4], v[(dup[0]+3)%4], v[(dup[0]+1)%4+4], v[(dup[0]+2)%4+4],
                v[(dup[0]+3)%4+4], to, source );
    // add the pyramid or tets that include the degen vertex
    if( n_inner[0] < 0 )
      addPyramid( v[(dup[0]+1)%4], v[(dup[0]+1)%4+4], v[(dup[0]+3)%4+4], v[(dup[0]+3)%4], v[dup[0]], to, source );
    else{
      int add = n_inner[0] > 3 ? -4 : 4;
      addTetrahedron( v[n_inner[0]], v[n_inner[0]+add], v[n_inner[1]], v[dup[0]], to, source );
      addTetrahedron( v[n_inner[0]], v[n_inner[1]], v[n_inner[1]-add], v[dup[0]], to, source );
    }
    return 1;
  }

  // see if there is a way to divide non-parallel top and bottom verts
  else if( n1[(dup[0]+1)%4] >= 0 || n1[(dup[0]+2)%4] >= 0 ){
    // parameters for a pyramid (that may or may not be divided into tets)
    int base = -1, top = -2;
    // if corner opposite degen corner has two diagonals meeting on it:
    if( n2[(dup[0]+1)%4] >= 0 && n1[(dup[0]+2)%4] == n2[(dup[0]+1)%4] ){
      if( n1[4] == n1[(dup[0]+2)%4] || n2[4] == n1[(dup[0]+2)%4] ){
        top = n1[(dup[0]+2)%4];
        base = 5;
      }
      else if( n1[5] == n1[(dup[0]+2)%4] || n2[5] == n1[(dup[0]+2)%4] ){
        top = n1[(dup[0]+2)%4];
        base = 4;
      }
    }
    // if a side corner not opposite the degenerate vertex has two diagonals meeting
    if( base < 0 && n2[(dup[0]+2)%4] >= 0 ){
      if( n2[(dup[0]+2)%4] == (dup[0]+3)%4+4 &&
          ( n1[5] == (dup[0]+3)%4+4 || n2[5] == (dup[0]+3)%4+4 ) ){
        top = (dup[0]+3)%4+4;
        base = 4;
      }
      else if( n2[(dup[0]+2)%4] == (dup[0]+3)%4 &&
               ( n1[4] == (dup[0]+3)%4 || n2[4] == (dup[0]+3)%4 ) ){
        top = (dup[0]+3)%4;
        base = 5;
      }
    }
    if( base < 0 && n1[(dup[0]+1)%4] >= 0 ){
      if( n1[(dup[0]+1)%4] == (dup[0]+1)%4+4 &&
          ( n1[5] == (dup[0]+1)%4+4 || n2[5] == (dup[0]+1)%4+4 ) ){
        top = (dup[0]+1)%4+4;
        base = 4;
      }
      else if( n1[(dup[0]+1)%4] == (dup[0]+1)%4 &&
               ( n1[4] == (dup[0]+1)%4 || n2[4] == (dup[0]+1)%4 ) ){
        top = (dup[0]+1)%4;
        base = 5;
      }
    }

    // if 4-corner lateral faces have diagonals that don't meet...
    if( base < 0 && n1[(dup[0]+1)%4] >= 0 && n1[(dup[0]+2)%4] >= 0 &&
        n1[(dup[0]+2)%4] != n2[(dup[0]+1)%4] ){
      top = n1[(dup[0]+1)%4];
      base = (top < 4) ? 5 : 4;
    }

    // if there is a valid top and base, make the element
    if( base >= 0 && top >= 0 ){
      // if pyramid top is NOT opposite degen vertex
      if( top == n1[(dup[0]+1)%4] || top == n2[(dup[0]+2)%4] ){
        int add = base == 4 ? 0 : 4;
        if( n1[base] < 0 ){
          addPyramid( v[0+add], v[1+add], v[2+add], v[3+add], v[top], to, source );
        }
        else{
          addTetrahedron( v[n1[base]], v[(n1[base]-add+1)%4+add],
                          v[n2[base]], v[top], to, source );
          addTetrahedron( v[n1[base]], v[n2[base]],
                          v[(n1[base]-add+3)%4+add], v[top], to, source );
        }
        int base2 = -1;
        if( base==4 && ( n1[5] == top || n2[5] == top ) ){
          base2 = top==(dup[0]+1)%4+4 ? (dup[0]+2)%4 : (dup[0]+1)%4;
        }
        else if( base==5 && ( n1[4] == top || n2[4] == top ) ){
          base2 = top==(dup[0]+1)%4 ? (dup[0]+2)%4 : (dup[0]+1)%4;
        }
        else
          base2 = base==5 ? 4 : 5;

        if( base2 != 4 &&  base2 != 5 ){
          addTetrahedron( v[top], v[(top-4+add+2)%4], v[(top-4+add+2)%4+4], v[dup[0]], to, source );
          if( n1[base2] >= 0 ){
            int add_base2 = n1[base2]<4 ? 4 : -4;
            addTetrahedron( v[n1[base2]], v[n1[base2]+add_base2], v[n2[base2]], v[top], to, source );
            addTetrahedron( v[n1[base2]], v[n2[base2]], v[n2[base2]-add_base2], v[top], to, source );
          }
          else
            addPyramid( v[base2], v[(base2+4)], v[(base2+1)%4+4], v[(base2+1)%4], v[top], to, source );
        }
        else{
          int top2 = (top-4+add+2)%4+add;
          if( n1[base2] >= 0 ){
            addTetrahedron( v[n1[base2]], v[(n1[base2]-4+add+1)%4+4-add], v[n2[base2]], v[top2], to, source );
            addTetrahedron( v[n1[base2]], v[(n1[base2]-4+add+3)%4+4-add], v[n2[base2]], v[top2], to, source );
          }
          else
            addPyramid( v[0+4-add], v[1+4-add], v[2+4-add], v[3+4-add], v[top2], to, source );

          int tet_base = top2-add==(dup[0]+1)%4 ? (dup[0]+1)%4 : (dup[0]+2)%4;
          if( tet_base == (dup[0]+1)%4 ){
            int add_tet_base = n2[tet_base] > 3 ? -4 : 4;
            addTetrahedron( v[n1[tet_base]], v[n2[tet_base]], v[n2[tet_base]+add_tet_base], v[top], to, source );
          }
          else{
            int add_tet_base = n1[tet_base] > 3 ? -4 : 4;
            addTetrahedron( v[n1[tet_base]], v[n2[tet_base]], v[n1[tet_base]+add_tet_base], v[top], to, source );
          }
        }
        return 1;
      }

      // if pyramid top is opposite degenerate vertex
      else if( top == (dup[0]+2)%4 || top == (dup[0]+2)%4+4 ){
        int add = base == 4 ? 0 : 4;
        if( n1[base] >= 0 ){
          addTetrahedron( v[n1[base]], v[(n1[base]-add+1)%4+add], v[n2[base]], v[top], to, source );
          addTetrahedron( v[n1[base]], v[(n1[base]-add+3)%4+add], v[n2[base]], v[top], to, source );
        }
        else
          addPyramid( v[0+add], v[1+add], v[2+add], v[3+add], v[top], to, source );

        addTetrahedron( v[dup[0]], v[(dup[0]+1)%4], v[(dup[0]+1)%4+4], v[top], to, source );
        addTetrahedron( v[dup[0]], v[(dup[0]+3)%4], v[(dup[0]+3)%4+4], v[top], to, source );
        return 1;
      }
      else
        Msg::Error("3: In createOnePtDegenHexElems(), badly subdivided degenerate hexahedron. Mesh for region %d has errors.",
                   to->tag() );
    }

  }

  return 0;

}  // end of createOnePtDegenHexElems()


// Construct the elements that subdivide a full hexahedron extrusion.
static inline bool createFullHexElems( std::vector<MVertex*> &v, GRegion *to, ExtrudeParams *ep, int j,
                                int k, int dup[], MElement* source, std::vector<int> n1, std::vector<int> n2,
                                std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                                std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                                std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                                unsigned int lat_tri_diags_size, bool bnd_elem, bool is_dbl, bool found_diags,
                                std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  if( !ep )
    return 0 ;


  // First: does this hexa have ANY dividing diagonals? If no, return
  if( !found_diags ){
     addHexahedron( v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], to, source );
     return 1;
  }

  // First test: Try to identify a corner with three diagonals converging on it
  // This is second because first test gives better quality...i think.

  int pyramid_top = -1, base_face_1 = -1;

  // variables to hold pyramid base corners and diagonal node indices:
  int b1_diag[2], b2_diag[2], b3_diag[2];
  for( int p = 0; p < 2; p++ ){
    b1_diag[p] = -1-p; b2_diag[p] = -2-p; b3_diag[p] = -3-p;
  }


  // find a 3-diag corner
  for( int s = 0; s < 2; s++ ){
    int p = !s ? 4 : 5;
    if( n1[p] >= 0 ){
      int add = !s ? 0 : 4;
      int p1 = n1[p]-add, p2 = (n1[p]-add+3)%4;
      if( n1[p1] >=0 && n1[p2] >= 0 &&
          ( n1[p] == n1[p1] || n1[p] == n2[p1] ) &&
          ( n1[p] == n1[p2] || n1[p] == n2[p2] ) ){
        pyramid_top = n1[p];
        base_face_1 = !s ? 5 : 4;
        break;
      }
      p1 = n2[p]-add;
      p2 = (n2[p]-add+3)%4;
      if( n1[p1] >=0 && n1[p2] >= 0 &&
          ( n2[p] == n1[p1] || n2[p] == n2[p1] ) &&
          ( n2[p] == n1[p2] || n2[p] == n2[p2] ) ){
        pyramid_top = n2[p];
        base_face_1 = !s ? 5 : 4;
        break;
      }
    }
  }

  // If pyramid top (3-diag corner) is found, then check for diagonal division of bases:

  if( pyramid_top >= 0 ){
    // ( base of first pyramid always the hexa's top or bottom )
    int add = pyramid_top < 4 ? 0 : 4;
    int base_face_2 = (pyramid_top-add+1)%4;
    int base_face_3 = (pyramid_top-add+2)%4;

    // Now construct shapes.
    for( int p = 0; p < 3; p++ ){
      int b[4], bn1, bn2;
      if( !p ){
        int add = base_face_1==4 ? 0 : 4;
        b[0] = 0+add; b[1] = 1+add; b[2] = 2+add; b[3] = 3+add;
        bn1 = n1[base_face_1]; bn2 = n2[base_face_1];
      }
      else if( p==1 ){
        b[0] = base_face_2; b[1] = b[0]+4;
        b[2] = (b[0]+1)%4+4; b[3] = (b[0]+1)%4;
        bn1 = n1[base_face_2]; bn2 = n2[base_face_3];
      }
      else{
        b[0] = base_face_3; b[1] = b[0]+4;
        b[2] = (b[0]+1)%4+4; b[3] = (b[0]+1)%4;
        bn1 = n1[base_face_3]; bn2 = n2[base_face_3];
      }

      if( bn1 < 0 )
        addPyramid( v[b[0]], v[b[1]], v[b[2]], v[b[3]], v[pyramid_top], to, source );
      else{
        if( bn1 == b[0] || bn2 == b[0] ){
          addTetrahedron( v[b[0]], v[b[1]], v[b[2]], v[pyramid_top], to, source );
          addTetrahedron( v[b[0]], v[b[2]], v[b[3]], v[pyramid_top], to, source );
        }
        else{
          addTetrahedron( v[b[0]], v[b[1]], v[b[3]], v[pyramid_top], to, source );
          addTetrahedron( v[b[1]], v[b[2]], v[b[3]], v[pyramid_top], to, source );
        }
      }
    }
    // return if successful
    return 1;
  }


  // Second full hexa division possibility  (two prisms, possibly subdivided):

  // YES, THIS IS HORRIBLE!!!!

    // Diagram of prism-centric coordinates:
    /*   ___________  p5
        |\         /|\
        | \      /  | \
        |  \   /    |  \
        |   \/______|___\
        |  / |      |   /|p2
     p3 |/___|___p4_| /  |
         \   |      /\   | prism 1,
          \  |    /   \  | external face 2 (side)
           \ |  /      \ |
            \|/_________\|
            p0           p1
                  prism 1,
                  external face 1 (bottom)

         NOTE: for Prism 2, the prism coords MIRROR the coords for
               prism 1 about the internal shared face.
    */


  // prism_v holds prism-centric indices of vertices--new coords!!!
  int prism_v[2][6], prism_face[2][2];
  // t_prism arrays for tet verts...p_prism arrays for pyramid verts (if any)
  int t_prism[2][3][4], p_prism[2][5];
  for( int s = 0; s < 2; s++ ){
    for( int t = 0; t < 5; t++ )
      p_prism[s][t] = -2*s-2;
    for( int t = 0; t < 3; t++ ){
      for( int w = 0; w < 4; w++ )
        t_prism[s][t][w] = -2*s*t*w-2;
    }
  }

  int prism_slice_valid = false; // set to true when found a valid slicing

  // find valid prism slicing
  for( int p_ind = 0; p_ind < 3; p_ind++ ){
    int p = p_ind;
    if( p_ind == 2 ) p = 4;  // move to the top-to-bottom slicing

    prism_slice_valid = false;

    // n_div1, n_div2 are indices of the vertice in the first diagonal
    int n_div1 = -1, n_div2 = -2;
    if( p < 4 ){
      if( ( n1[p] == p || n2[p] == p ) &&
          ( n1[(p+2)%4] == (p+2)%4+4 || n2[(p+2)%4] == (p+2)%4+4 ) ){
        n_div1 = p; n_div2 = (p+1)%4+4;
      }
      if( ( n1[p] == p+4 || n2[p] == p+4 ) &&
          ( n1[(p+2)%4] == (p+2)%4 || n2[(p+2)%4] == (p+2)%4 ) ){
        n_div1 = p+4; n_div2 = (p+1)%4;
      }
    }
    else{
      if( ( n1[4] == 0 || n2[4] == 0 ) &&
          ( n1[5] == 4 || n2[5] == 4 ) ){
        n_div1 = 0; n_div2 = 2;
      }
      if( ( n1[4] == 1 || n2[4] == 1 ) &&
          ( n1[5] == 5 || n2[5] == 5 ) ){
        n_div1 = 1; n_div2 = 3;
      }
    }

    if( n_div1 < 0 )
      continue;

    // There are two prisms.  Find the vertices of any external and internal prism
    //  face diagonals.
    int ext_diag[2][2][2], intern_diag[2];
    for( int s = 0; s < 2; s++ ){
      intern_diag[s] = -5-s*s-s;
      for( int t = 0; t < 2; t++ ){
        ext_diag[s][t][0] = -1-t*t-t; ext_diag[s][t][1] = -2-t*t-t;
      }
    }

    // Create arrays of verts of both prisms in prism-centric coords (see ascii diagram above)
    // to keep sanity.
    // p0 always refereces a vertex position on a slicing diagonal (see ascii diagram above again.
    int p0;
    if( (n_div1 > 3 && n_div2 < 4) || (n_div1 < 4 && n_div2 > 3) ){
      p0 = n_div1 < 4 ? p : (p+2)%4;
      prism_v[0][0] = p0; prism_v[0][1] = (p0+1)%4; prism_v[0][2] = (p0+1)%4+4;
      prism_v[0][3] = (p0+3)%4; prism_v[0][4] = (p0+2)%4; prism_v[0][5] = (p0+2)%4+4;
      prism_v[1][0] = p0; prism_v[1][1] = p0+4; prism_v[1][2] = (p0+1)%4+4;
      prism_v[1][3] = (p0+3)%4; prism_v[1][4] = (p0+3)%4+4; prism_v[1][5] = (p0+2)%4+4;
      prism_face[0][0] = 4;
      prism_face[0][1] = (p0+1)%4;
      prism_face[1][0] = (p0+3)%4;
      prism_face[1][1] = 5;
    }
    else{
      p0 = n_div1;
      prism_v[0][0] = p0; prism_v[0][1] = (p0+1)%4; prism_v[0][2] = (p0+2)%4;
      prism_v[0][3] = p0+4; prism_v[0][4] = (p0+1)%4+4; prism_v[0][5] = (p0+2)%4+4;
      prism_v[1][0] = p0; prism_v[1][1] = (p0+3)%4; prism_v[1][2] = (p0+2)%4;
      prism_v[1][3] = p0+4; prism_v[1][4] = (p0+3)%4+4; prism_v[1][5] = (p0+2)%4+4;
      prism_face[0][0] = p0;
      prism_face[0][1] = (p0+1)%4;
      prism_face[1][0] = (p0+3)%4;
      prism_face[1][1] = (p0+2)%4;
    }

    // 3 ways this prism slice can work:
    // 1. Two additional diagonals which meet at a vertex.
    // 2. Two additional opposing aligned diagonals
    // 3. No more diagonals, just two prisms

    // get external diagonals for first and second prism
    for( int s = 0; s < 2; s++ ){
      if( n1[prism_face[s][0]] == prism_v[s][1] ||
          n2[prism_face[s][0]] == prism_v[s][1] ){
        ext_diag[s][0][0] = 1; ext_diag[s][0][1] = 3;
      }
      else if( n1[prism_face[s][0]] == prism_v[s][4] ||
               n2[prism_face[s][0]] == prism_v[s][4] ){
        ext_diag[s][0][0] = 4; ext_diag[s][0][1] = 0;
      }
      if( n1[prism_face[s][1]] == prism_v[s][1] ||
          n2[prism_face[s][1]] == prism_v[s][1] ){
        ext_diag[s][1][0] = 1; ext_diag[s][1][1] = 5;
      }
      else if( n1[prism_face[s][1]] == prism_v[s][4] ||
               n2[prism_face[s][1]] == prism_v[s][4] ){
        ext_diag[s][1][0] = 4; ext_diag[s][1][1] = 2;
      }
    }

    // if first prism needs the internal diagonal
    if( ext_diag[0][0][0] >= 0 && ext_diag[0][1][0] != ext_diag[0][0][0] ){
      intern_diag[0] = ext_diag[0][0][1];
      if( ext_diag[0][0][1] == 0 )
        intern_diag[1] = 5;
      else
        intern_diag[1] = 2;
    }
    else if( ext_diag[0][1][0] >= 0 && ext_diag[0][0][0] != ext_diag[0][1][0] ){
      intern_diag[0] = ext_diag[0][1][1];
      if( ext_diag[0][1][1] == 2 )
        intern_diag[1] = 3;
      else
        intern_diag[1] = 0;
    }

    // if 2nd prism needs the internal diagonal to work, check to see if the internal
    // diagonal exists and, if so, if it is consistent.  If it doesn't exist, make it
    if( ( ext_diag[1][0][0] != ext_diag[1][1][0] || (ext_diag[1][0][0] < 0 &&
                                                     ext_diag[1][1][0] < 0) ) &&
        intern_diag[0] >= 0 && intern_diag[0] != ext_diag[1][0][1] &&
        intern_diag[0] != ext_diag[1][1][1] && intern_diag[1] != ext_diag[1][0][1] &&
        intern_diag[1] != ext_diag[1][1][1] ) {
      continue;
    }
    // add internal diagonal if needed
    else if( intern_diag[0] < 0 && ext_diag[1][0][0] >= 0 &&
             ext_diag[1][1][0] != ext_diag[1][0][0] ){
      intern_diag[0] = ext_diag[1][0][1];
      if( ext_diag[1][0][1] == 0 )
        intern_diag[1] = 5;
      else
        intern_diag[1] = 2;
    }
    else if( intern_diag[0] < 0 && ext_diag[1][1][0] >= 0 &&
             ext_diag[1][0][0] != ext_diag[1][1][0] ){
      intern_diag[0] = ext_diag[1][1][1];
      if( ext_diag[1][1][1] == 2 )
        intern_diag[1] = 3;
      else
        intern_diag[1] = 0;
    }

    // this check sees if the internal shared prism face is diagonalized, but
    // one prism has no other diags
    if( intern_diag[0] >= 0 &&
        ( (ext_diag[0][0][0] < 0 && ext_diag[0][1][0] < 0) ||
          (ext_diag[1][0][0] < 0 && ext_diag[1][1][0] < 0) ) ){
      continue;
    }

    // if make it to here, prism slice is valid
    prism_slice_valid = true;

    // make arrays of vertices for making the polyhedra
    if( prism_slice_valid ){
      for( int s = 0; s < 2; s++ ){
        if( ext_diag[s][0][0] < 0 && ext_diag[s][1][0] < 0 )
          continue;
        else if( ext_diag[s][0][0] >= 0 && ext_diag[s][0][0] == ext_diag[s][1][0] ){
          int add = (ext_diag[s][0][0] < 3) ? 3 : -3;
          t_prism[s][0][0] = ext_diag[s][0][0]; t_prism[s][0][1] = ext_diag[s][0][1];
          t_prism[s][0][2] = ext_diag[s][1][1]; t_prism[s][0][3] = ext_diag[s][0][0]+add;
          if( intern_diag[0] < 0 ){
            p_prism[s][0] = 0; p_prism[s][1] = 2;
            p_prism[s][2] = 5; p_prism[s][3] = 3;
            p_prism[s][4] = ext_diag[s][0][0];
          }
          else{
            int v_tmp1 = (intern_diag[0] == 0 || intern_diag[1] == 0) ? 2 : 0;
            int v_tmp2 = (intern_diag[0] == 0 || intern_diag[1] == 0) ? 3 : 5;

            t_prism[s][1][0] = intern_diag[0]; t_prism[s][1][1] = intern_diag[1];
            t_prism[s][1][2] = v_tmp1;        t_prism[s][1][3] = ext_diag[s][0][0];
            t_prism[s][2][0] = intern_diag[0]; t_prism[s][2][1] = intern_diag[1];
            t_prism[s][2][2] = v_tmp2;        t_prism[s][2][3] = ext_diag[s][0][0];
          }
        }
        else if( intern_diag[0] >= 0 ){
          int p_tet_start = (ext_diag[s][0][0] >= 0) ? ext_diag[s][0][0] : ext_diag[s][1][0];
          int p_pyr_top = (p_tet_start == ext_diag[s][0][0])
                          ? ext_diag[s][0][1] : ext_diag[s][1][1];
          int p_tet_top;
          if( p_tet_start == ext_diag[s][0][0] )
            p_tet_top = (ext_diag[s][0][1] == 3) ? 0 : 3;
          else
            p_tet_top = (ext_diag[s][1][1] == 5) ? 2 : 5;

          t_prism[s][0][0] = p_tet_start; t_prism[s][0][1] = intern_diag[0];
          t_prism[s][0][2] = intern_diag[1]; t_prism[s][0][3] = p_tet_top;

          if( p_tet_start == ext_diag[s][0][0] ){
            if( ext_diag[s][1][0] < 0 ){
              p_prism[s][0] = 1; p_prism[s][1] = 2;
              p_prism[s][2] = 5; p_prism[s][3] = 4;
              p_prism[s][4] = p_pyr_top;
            }
            else{
              t_prism[s][1][0] = ext_diag[s][1][0]; t_prism[s][1][1] = ext_diag[s][1][1];
              t_prism[s][1][2] = (ext_diag[s][1][0]==4) ? 1 : 4;
              t_prism[s][1][3] = p_pyr_top;
              t_prism[s][2][0] = ext_diag[s][1][0]; t_prism[s][2][1] = ext_diag[s][1][1];
              t_prism[s][2][2] = (ext_diag[s][1][0]==4) ? 5 : 2;
              t_prism[s][2][3] = p_pyr_top;
            }
          }
          else{
            if( ext_diag[s][0][0] < 0 ){
              p_prism[s][0] = 0; p_prism[s][1] = 1;
              p_prism[s][2] = 4; p_prism[s][3] = 3;
              p_prism[s][4] = p_pyr_top;
            }
            else{
              t_prism[s][1][0] = ext_diag[s][0][0]; t_prism[s][1][1] = ext_diag[s][0][1];
              t_prism[s][1][2] = (ext_diag[s][0][0]==4) ? 3 : 4;
              t_prism[s][1][3] = p_pyr_top;
              t_prism[s][2][0] = ext_diag[s][0][0]; t_prism[s][2][1] = ext_diag[s][0][1];
              t_prism[s][2][2] = (ext_diag[s][0][0]==4) ? 1 : 0;
              t_prism[s][2][3] = p_pyr_top;
            }
          }
        }
        // translate arrays to 'real' vertex coordinates
        for( int t = 0; t < 3; t++ ){
          for( int w = 0; w < 4; w++ )
            t_prism[s][t][w] = (t_prism[s][t][w] >= 0)
                               ? prism_v[s][t_prism[s][t][w]] : t_prism[s][t][w];
        }
        for( int t = 0; t < 5; t++ )
            p_prism[s][t] = (p_prism[s][t] >= 0)
                            ? prism_v[s][p_prism[s][t]] : p_prism[s][t];
      }

      // Now construct shapes for prism slice through configuration
      for( int s = 0; s < 2; s++ ){
        if( t_prism[s][0][0] < 0 && p_prism[s][0] < 0 ){
          addPrism( v[prism_v[s][0]], v[prism_v[s][1]], v[prism_v[s][2]], v[prism_v[s][3]],
                    v[prism_v[s][4]], v[prism_v[s][5]], to, source);
        }
        else{
          for( int t = 0; t < 3; t++ ){
            if( t_prism[s][t][0] >= 0 )
              addTetrahedron( v[t_prism[s][t][0]], v[t_prism[s][t][1]], v[t_prism[s][t][2]],
                              v[t_prism[s][t][3]], to, source );
          }
          if( p_prism[s][0] >= 0 )
            addPyramid( v[p_prism[s][0]], v[p_prism[s][1]], v[p_prism[s][2]], v[p_prism[s][3]],
                        v[p_prism[s][4]], to, source );
        }
      }
      // return now
      return 1;

    }  // end of "if prism_slice_valid" statement
  }    // end of p_ind loop over opposite pairs of diagonals

  return 0;  // if exhaust possibilities, default to this

}  // end of createFullHexElems()


// Overall function that creates the elements that subdivide any whole element extruded from a quadrangle.
static inline void QuadToTriHexPri(std::vector<MVertex*> &v, GRegion *to, int j,
                              int k, MElement* source,
                              std::set<std::pair<MVertex*, MVertex*> > &quadToTri_edges,
                              std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems,
                              std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > > &problems_new,
                              unsigned int lat_tri_diags_size, bool bnd_elem, bool is_dbl, bool diag_search,
                              std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  int dup[4];
  int m = 0;
  for(int i = 0; i < 4; i++)
    if(v[i] == v[i + 4])
      dup[m++] = i;

  bool is_problem = false;

  // is element marked as needing internal vertex?
  if( !is_dbl ){
    std::pair<unsigned int, unsigned int> jk_pair (j,k);
    std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > >::iterator itprob;
    itprob = problems.find(source);
    if( itprob != problems.end() ){
      if( (*itprob).second.find(jk_pair) != (*itprob).second.end() )
        is_problem = true;
    }
  }

  ExtrudeParams *ep = to->meshAttributes.extrude;

  // need these for double layer extrusion purposes
  int j_second_from_top = 0, k_second_from_top = 0;
  if( ep ){
    if( ep->mesh.NbElmLayer[ep->mesh.NbLayer-1] > 1 ){
      j_second_from_top = ep->mesh.NbLayer-1;
      k_second_from_top = ep->mesh.NbElmLayer[j_second_from_top]-2;
    }
    else{
      j_second_from_top = std::max(ep->mesh.NbLayer-2, 0);
      k_second_from_top = ep->mesh.NbElmLayer[j_second_from_top]-1;
    }
  }


  // variables to hold of each faces's diagonal vertex nodes
  bool found_diags = false;
  std::vector<int> n1, n2;
  n1.assign(6, -3);
  n2.assign(6, -4);
  if( diag_search ){
    for( int p = 0; p < 6; p++ ){
      n1[p] = -p*p-p-1; n2[p] = -p*p-p-2;  //unique negative numbers
      if( p < 4 ){
        if( edgeExists( v[p], v[(p+1)%4+4], quadToTri_edges ) ){
          n1[p] = p; n2[p] = (p+1)%4+4;
          found_diags = true;
        }
        else if( edgeExists( v[(p+1)%4], v[p+4], quadToTri_edges ) ){
          n1[p] = (p+4); n2[p] = (p+1)%4;
          found_diags = true;
        }
      }
      else{
        int add = (p == 4) ? 0 : 4;
        if( edgeExists( v[0+add], v[2+add], quadToTri_edges ) ){
          n1[p] = 0 + add;
          n2[p] = 2 + add;
          found_diags = true;
        }
        else if( edgeExists( v[1+add], v[3+add], quadToTri_edges ) ){
          n1[p] = 1 + add;
          n2[p] = 3 + add;
          found_diags = true;
        }
      }
    }
  }


  // BAD SHAPE
  if( m > 2 || m < 0 ){
    Msg::Error("In QuadToTriHexPri(), bad number of degenerate corners.");
    return;
  }


  // Divide by double layer extrusion method?
  if( is_dbl && ( found_diags || j > j_second_from_top || j==j_second_from_top && k >= k_second_from_top || m==1 ) ){
    if( j==0 && k==0 || j==j_second_from_top && k==k_second_from_top && ( !bnd_elem || !found_diags ) && m != 1 )
      MeshWithFaceCenteredVertex( to, source, v, n1, n2, 0, 1, pos );
    else if( j == ep->mesh.NbLayer-1 && k == ep->mesh.NbElmLayer[j]-1 )
      MeshWithFaceCenteredVertex( to, source, v, n1, n2, 1, 0, pos );
    else
      MeshWithFaceCenteredVertex( to, source, v, n1, n2, 1, 1, pos );
    return;
  }


  // The of the possibilites are for a single layer extrusion

  // PRISM
  else if( m == 2 && !is_problem ){
    if( createTwoPtDegenHexElems( v, to, ep, j, k, dup, source, n1, n2, quadToTri_edges, problems,
                                  problems_new, lat_tri_diags_size, bnd_elem, is_dbl, found_diags, pos ) )
      return;
  }

  // DEGENERATE HEXAHEDRON
  else if( m == 1 && !is_problem ){
    if( createOnePtDegenHexElems( v, to, ep, j, k, dup, source, n1, n2, quadToTri_edges, problems,
                                  problems_new, lat_tri_diags_size, bnd_elem, is_dbl, found_diags, pos ) )
      return;
  }


  // FULL HEXAHEDRON
  else if( !is_problem ){
    if( createFullHexElems( v, to, ep, j, k, dup, source, n1, n2, quadToTri_edges, problems,
                            problems_new, lat_tri_diags_size, bnd_elem, is_dbl, found_diags, pos ) )
      return;
  }

  // now take care of unexpected failure to divide without internal vertex
  if( !is_problem ) {
    Msg::Error("In QuadToTriHexPri(), Extruded hexahedron needs subdivision, but cannot "
               " be divided without internal vertex, and was not previously detected as such. "
               " This is a bug. Please Report.");
    Msg::Error("j: %d, k: %d", j, k);
    QtMakeCentroidVertex( v, &(to->mesh_vertices), to, pos );
    std::pair<unsigned int, unsigned int> jk_pair(j,k);
    problems_new[source].insert(jk_pair);
    is_problem = true;
  }

  // Mesh with internal vertex
  if( is_problem ){
    MeshWithInternalVertex( to, source, v, n1, n2, pos );
    return;
  }

}  // end of QuadToTriPriPyrTet()

// reserves approximately the right amount of memory for quadToTri extrusions
// in the element vectors in the region 'to'
// *** STILL EXPERIMENTAL -- It *kind* of works to limit memory footprint of vectors.
/*
static void reserveQuadToTriCapacityForRegion( GRegion *to, GFace *from,  bool is_dbl, unsigned int num_layers,
                                              unsigned int lat_tri_diags_size, CategorizedSourceElements *c,
                                              std::map<MElement*, std::set<std::pair<unsigned int,
                                                       unsigned int> > > *problems )
{

  ExtrudeParams *ep = to->meshAttributes.extrude;
  if( !ep )
    return;

  std::map<MElement*, std::set<std::pair<unsigned int, unsigned int> > >::iterator itprob;
  unsigned int num_prob_tri = 0, num_prob_quad = 0;
  for( itprob = problems->begin(); itprob != problems->end(); itprob++ ){
    if( itprob->first->getType() == TYPE_TRI )
      num_prob_tri += itprob->second.size();
    else
      num_prob_quad += itprob->second.size();
  }
  // unsigned int num_bnd_tri = c->three_bnd_pt_tri.size() + c->other_bnd_tri.size();
  // unsigned int num_bnd_quad = c->four_bnd_pt_quad.size() + c->other_bnd_quad.size();
  // unsigned int num_int_tri = c->internal_tri.size();
  // unsigned int num_int_quad = c->internal_quad.size();
  unsigned int num_tri = from->triangles.size();
  unsigned int num_quad = from->quadrangles.size();
  // in case !ep->Recombine is ever allowed...
  if( !ep->mesh.Recombine )
    to->tetrahedra.reserve( num_layers*(3*num_tri + 6*num_quad + 8*num_prob_tri + 12*num_prob_quad) );
  else if( !is_dbl ){
    //to->tetrahedra.reserve( (6*num_quad + 3*num_tri +2*lat_tri_diags_size + 8*num_prob_tri + 12*num_prob_quad) );
    to->prisms.reserve( num_tri*num_layers );
    to->hexahedra.reserve( num_quad*(num_layers-1) );
  }
  else{
    unsigned int extra_verts = to->mesh_vertices.size() - from->mesh_vertices.size()*(num_layers-1);
    to->hexahedra.reserve( num_quad*(num_layers-1) );
    to->prisms.reserve( num_tri*num_layers );
    to->pyramids.reserve( num_prob_quad + num_prob_tri + extra_verts*4 + num_quad );
    to->tetrahedra.reserve( num_prob_quad + num_prob_tri + extra_verts );
  }

}
*/

// displays for the user a list of the body centered vertices created for problem elements.
static void listBodyCenteredVertices( GRegion *to, bool is_dbl,
                                      std::map<MElement *, std::set<std::pair<unsigned int,unsigned int> > > *problems,
                                      std::map<MElement *, std::set<std::pair<unsigned int,unsigned int> > > *problems_new,
                                      std::set<MVertex*, MVertexLessThanLexicographic> *pos )
{

  ExtrudeParams *ep = to->meshAttributes.extrude;

  if( !ep )
    return;

  if( problems->size() || problems_new->size() ){

    std::map<MElement *, std::set<std::pair<unsigned int,unsigned int> > >::iterator it_begin;
    std::map<MElement *, std::set<std::pair<unsigned int,unsigned int> > >::iterator it_end;
    std::map<MElement *, std::set<std::pair<unsigned int,unsigned int> > >::iterator itmap;


    //insert all of problems_new into problems
    for( itmap = problems_new->begin(); itmap!= problems_new->end(); itmap++ )
      (*problems)[itmap->first].insert( itmap->second.begin(), itmap->second.end() );

    if( is_dbl ){
      it_begin = problems_new->begin();
      it_end = problems_new->end();
    }
    else{
      it_begin = problems->begin();
      it_end = problems->end();
    }

    unsigned int int_verts_count = 0;
    for( itmap = it_begin; itmap != it_end; itmap++ ){
      if( itmap->second.size() )
        int_verts_count += itmap->second.size();
    }

    if( int_verts_count ){
      if( int_verts_count == 1 )
        Msg::Error("QuadToTri meshed %d element in region %d "
                   "with a body-centered internal vertex.",
                   int_verts_count, to->tag() );
      else
        Msg::Error("QuadToTri meshed %d elements in region %d "
                   "with body-centered internal vertices.",
                   int_verts_count, to->tag() );
      Msg::Error("( Mesh *should* still conformal, but the user should be aware of these internal vertices. )" );

      unsigned int int_verts_count2 = 0;

      for( itmap = it_begin; itmap != it_end; itmap++ ){
        if( itmap->second.size() ){
          std::set<std::pair<unsigned int, unsigned int> >::iterator itset;
          for( itset = itmap->second.begin(); itset != itmap->second.end(); itset++ ){
            std::vector<MVertex *> verts;
            getExtrudedVertices( itmap->first, ep, (*itset).first,
                                 (*itset).second, (*pos), verts);
            // find centroid
            std::vector<double> centroid = QtFindVertsCentroid(verts);
            int_verts_count2++;
            Msg::Error("Internal Vertex %d at (x,y,z) = (%g, %g, %g).", int_verts_count2,
                       centroid[0], centroid[1], centroid[2] );
          }
        }
      }
    }
  }

}


// Function that makes all the elements in a QuadToTri region, both
// the divided elements and the whole elements, using already-created subdivision edges.
bool QuadToTriCreateElements(GRegion *to,  CategorizedSourceElements &cat_src_elems,
                            std::set<std::pair<MVertex*,MVertex*> > &quadToTri_edges,
                            std::set<std::pair<MVertex*,MVertex*> > &lat_tri_diags,
                            std::map<MElement*, std::set<std::pair<unsigned int,unsigned int> > > &problems,
                            std::set<MVertex *, MVertexLessThanLexicographic>  &pos)
{

  ExtrudeParams *ep = to->meshAttributes.extrude;
  if( !ep || !ep->mesh.ExtrudeMesh || !ep->mesh.QuadToTri )
    return false;

  GModel *model = to->model();
  GFace *from = model->getFaceByTag( std::abs(ep->geo.Source) );
  if( !from )
    return false;


  // set lat_tri_diags_size
  unsigned int lat_tri_diags_size = lat_tri_diags.size();

  // number of element layers
  unsigned int num_layers = 0;
  for( int j = 0; j < ep->mesh.NbLayer; j++ )
    num_layers += ep->mesh.NbElmLayer[j];

  // Is this a valid double layer extrusion?
  bool is_dbl = false;
  if( num_layers >= 2 && ( ep->mesh.QuadToTri == QUADTRI_DBL_1 || ep->mesh.QuadToTri == QUADTRI_DBL_1_RECOMB ) )
    is_dbl = true;

  // Find where top divided layer starts
  int j_top_start = 0, k_top_start = 0;
  if( is_dbl ){  // second from top
    if( ep->mesh.NbElmLayer[ep->mesh.NbLayer-1] > 1 ){
      j_top_start = ep->mesh.NbLayer-1;
      k_top_start = ep->mesh.NbElmLayer[j_top_start]-2;
    }
    else{
      j_top_start = std::max(ep->mesh.NbLayer-2, 0);
      k_top_start = ep->mesh.NbElmLayer[j_top_start]-1;
    }
  }
  else{ // first from top
    j_top_start = ep->mesh.NbLayer-1;
    k_top_start = ep->mesh.NbElmLayer[j_top_start]-1;
  }

  // for one point bd quads
  int j_second_from_bottom = ep->mesh.NbLayer-1,
      k_second_from_bottom = ep->mesh.NbElmLayer[ep->mesh.NbLayer-1]-1;
  if( ep->mesh.NbElmLayer[0] > 1 ){
    j_second_from_bottom = 0;
    k_second_from_bottom = 1;
  }
  else if( ep->mesh.NbLayer > 1 ){
    j_second_from_bottom = 1;
    k_second_from_bottom = 0;
  }


  // a container for new problem elements (if such new problems are found, there's a bug)
  std::map<MElement*, std::set<std::pair<unsigned int,unsigned int> > > problems_new;


  // Make the extra vertices needed for Some QuadToTri elements
  if( !addFaceOrBodyCenteredVertices( to, cat_src_elems, quadToTri_edges, problems, is_dbl,
                                      lat_tri_diags_size, pos ) ){
    Msg::Error("QuadToTriCreateElements() could not add face or body vertices for QuadToTri region %d.", to->tag() );
    return false;
  }

  // reserve enough capacity for all possible elements, try to find combination of simplicity and memory efficiency.
  //  *** EXPERIMENTAL ***
  //reserveQuadToTriCapacityForRegion( to, from, is_dbl, num_layers, lat_tri_diags_size, &cat_src_elems, &problems );

  // create elements:

  /*  std::vector<MElement*> elem_vec;
  elem_vec.reserve(num_layers);
  */
  // triangles
  for( int s = 0; s < 3; s++ ){
    std::vector<MVertex*> verts;
    verts.reserve(3);
    bool bnd_elem = s < 2 ? true : false;
    std::set<unsigned int> *set_elems;
    std::set<unsigned int>::iterator itset;
    if( !s )        set_elems = &cat_src_elems.three_bnd_pt_tri;
    else if( s==1 ) set_elems = &cat_src_elems.other_bnd_tri;
    else            set_elems = &cat_src_elems.internal_tri;
    for( itset = set_elems->begin(); itset != set_elems->end(); itset++ ){
      /* // *** SPEED IMPROVEMENT ***
      unsigned int hex, pyr, pri, tet;
      hex = to->hexahedra.size();
      pyr = to->pyramids.size();
      pri = to->prisms.size();
      tet = to->tetrahedra.size();
      // keeps old allocation
      elem_vec.resize(0);
      */
      MElement *elem = from->triangles[(*itset)];
      for(int j = 0; j < ep->mesh.NbLayer; j++) {
        for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
          // keeps old allocation
          verts.resize(0);
          if( getExtrudedVertices(elem, ep, j, k, pos, verts) == 6 ){
            QuadToTriPriPyrTet( verts, to, j, k, elem, quadToTri_edges,
                               problems, problems_new, lat_tri_diags_size,
                               bnd_elem, is_dbl, 1, pos );
          }
        }
      }
      /*// *** SPEED IMPROVEMENT ***
      elem_vec.insert(elem_vec.end(), to->hexahedra.begin()+hex, to->hexahedra.end() );
      elem_vec.insert(elem_vec.end(), to->tetrahedra.begin()+tet, to->tetrahedra.end() );
      elem_vec.insert(elem_vec.end(), to->prisms.begin()+pri, to->prisms.end() );
      elem_vec.insert(elem_vec.end(), to->pyramids.begin()+pyr, to->pyramids.end() );
      */
    }
  }

  if(from->quadrangles.size() && !ep->mesh.Recombine){
    Msg::Error("In QuadToTriCreateElements(), cannot extrude quadrangles without Recombine");
    return false;
  }
  else{
    std::vector<MVertex*> verts;
    verts.reserve(4);
    for( int s = 0; s < 3; s++ ){
      bool bnd_elem = s < 2 ? true : false;
      std::set<unsigned int> *set_elems;
      std::set<unsigned int>::iterator itset;
      if( !s )        set_elems = &cat_src_elems.four_bnd_pt_quad;
      else if( s==1 ) set_elems = &cat_src_elems.other_bnd_quad;
      else            set_elems = &cat_src_elems.internal_quad;

      for( itset = set_elems->begin(); itset != set_elems->end(); itset++ ){
        /*// *** SPEED IMPROVEMENT ***
        unsigned int hex, pyr, pri, tet;
        hex = to->hexahedra.size();
        pyr = to->pyramids.size();
        pri = to->prisms.size();
        tet = to->tetrahedra.size();

        // keeps old allocation
        elem_vec.resize(0);
        */
        MElement *elem = from->quadrangles[(*itset)];
        for(int j = 0; j < ep->mesh.NbLayer; j++) {
          for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
            // keeps old allocation
            verts.resize(0);
            if(getExtrudedVertices(elem, ep, j, k, pos, verts) == 8 ){
              QuadToTriHexPri(verts, to, j, k, elem, quadToTri_edges,
                              problems, problems_new, lat_tri_diags_size,
                              bnd_elem, is_dbl, 1, pos);
            }
          }
        }
        /*// *** SPEED IMPROVEMENT ***
        elem_vec.insert(elem_vec.end(), to->hexahedra.begin()+hex, to->hexahedra.end() );
        elem_vec.insert(elem_vec.end(), to->tetrahedra.begin()+tet, to->tetrahedra.end() );
        elem_vec.insert(elem_vec.end(), to->prisms.begin()+pri, to->prisms.end() );
        elem_vec.insert(elem_vec.end(), to->pyramids.begin()+pyr, to->pyramids.end() );
        */
      }
    }
  }

  // List for the user any elements with internal vertices:
  listBodyCenteredVertices( to, is_dbl, &problems, &problems_new, &pos );


  // Now revert any elements that have positive  volume.
  // Does this even need to be done?
 // *** KEEP THIS COMMENTED OUT UNLESS IT IS NEEDED ***
  /*for( int i = 0; i < to->tetrahedra.size(); i++ ){
    if( to->tetrahedra[i]->getVolumeSign() > 0 )
      to->tetrahedra[i]->revert();

  }
  for( int i = 0; i < to->prisms.size(); i++ ){
    if( to->prisms[i]->getVolumeSign() > 0 )
      to->prisms[i]->revert();
  }
  for( int i = 0; i < to->pyramids.size(); i++ ){
    if( to->pyramids[i]->getVolumeSign() > 0 )
      to->pyramids[i]->revert();
  }
  */

  // ***THE FOLLOWING COMMENTED OUT LINES ARE FOR DEBUGGING PURPOSES ONLY AND WON'T WORK WITHOUT
  //   A SPECIAL INCLUDE FILE.  THESE ARE USELESS WITHOUT THE DEBUG INCLUDE. ***
  /*GModel::riter rit;
  if( std::abs(to->tag() ) == 4  ){
    for( rit = model->firstRegion(); rit != model->lastRegion(); rit++ ){
      double total_volume = RegionVolByElems( (*rit) );
      Msg::Error( "Region %3d Volume = %14.7f.", (*rit)->tag(), total_volume );
    }
    for( rit = model->firstRegion(); rit != model->lastRegion(); rit++ ){
      unsigned int num_nonconformal = TestRegionConformality( (*rit) );
      //      if( num_nonconformal )
        Msg::Error( "Region %3d Noncomformal faces = %d.", (*rit)->tag(), num_nonconformal );
    }

  }*/

  return true;

}


// Mesh QuadToTri region from extrudeMesh() in meshGRegionExtruded.cpp
// Added 04/08/2011:
int meshQuadToTriRegion( GRegion *gr, std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{
  // Perform some checks to see if this is a valid QuadToTri region.
  // If so, a decision has to be made: if this surface is NOT laterally adjacent to
  // any subdivided extrusion, then it may be meshed here without worrying
  // about a global subdivide operation.
  // If the region has a lateral shared with a subdivide region, then it should be part
  // of the subdivide operation later...so just let the default
  // methods here create the vertices and quit.
  // Otherwise, engage in the meshing here.

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.ExtrudeMesh || !ep->mesh.QuadToTri || !ep->mesh.Recombine )
    return 0;

  // QuadToTri validity check:
  bool validQuadToTriReg = false;
  // if any laterals are shared with a subdivided region or an region that otherwise
  // should not have it's lateral diags changed, IsValidQuadToTriRegion will set following to 'false.'
  bool allNonGlobalSharedLaterals = true; // IsValidQuadToTriRegion will set this properly regardless of initial value
  validQuadToTriReg = IsValidQuadToTriRegion(gr, &allNonGlobalSharedLaterals);

  if( !validQuadToTriReg && ep->mesh.QuadToTri )
    Msg::Error("Mesh of QuadToTri region %d likely has errors.", gr->tag() );


  if( !allNonGlobalSharedLaterals ){
    Msg::Info("Delaying mesh of QuadToTri Region %d until after global subdivide operation....", gr->tag() );
    return 0;
  }

  // mesh quadToTri even if validQuadToTri is false. Try it anyway!
  if( allNonGlobalSharedLaterals ){
    std::set<std::pair<MVertex*, MVertex*> > quadToTri_edges;
    std::set<std::pair<MVertex*, MVertex*> > lat_tri_diags;
    std::map<MElement*, std::set<std::pair<unsigned int,unsigned int> > > problems;

    // data structure for boundary status-categorized source elements,
    // (member data containers defined in .h file)
    CategorizedSourceElements cat_src_elems( gr );
    if( !cat_src_elems.valid ){
      Msg::Error("In meshQuadToTriRegion(), failed to classify QuadToTri region %d's source face elements "
                 "according to boundary status.", gr->tag() );
      return 0;
    }

    if( !QuadToTriEdgeGenerator( gr, cat_src_elems, quadToTri_edges,
                                 lat_tri_diags, problems, pos) ){
      Msg::Error("In meshQuadToTriRegion(), failed to create edges for QuadToTri "
                 "region %d.", gr->tag() );
      return 0;
    }
    if( !QuadToTriCreateElements( gr, cat_src_elems, quadToTri_edges,
                                  lat_tri_diags, problems, pos) ){
      Msg::Error("In meshQuadToTriRegion, failed to create elements for QuadToTri "
                 "region %d.", gr->tag() );
      return 0;
    }

    QuadToTriLateralRemesh(gr, quadToTri_edges);

    return 1;
  }

  return 0;

}


// The function that is called from meshGRegionExtruded.cpp to mesh QuadToTri regions
// that are adjacent to subdivided regions, after the global Subdivide command is called.
// Added 04/08/11.
int meshQuadToTriRegionAfterGlobalSubdivide( GRegion *gr, std::set<std::pair<MVertex*, MVertex*> > *edges,
                                            std::set<MVertex*, MVertexLessThanLexicographic> &pos )
{

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if( !ep || !ep->mesh.ExtrudeMesh || !ep->mesh.QuadToTri || !ep->mesh.Recombine )
    return 0;

  // QuadToTri validity check:
  bool validQuadToTriReg = false;
  // if any laterals are shared with a subdivided region or any region that
  // should not have its lateral diags swapped, IsValidQuadToTriRegion() will set following to 'false.'
  bool allNonGlobalSharedLaterals = true; // IsValidQuadToTriRegion will set this properly regardless of initial value
  validQuadToTriReg = IsValidQuadToTriRegion(gr, &allNonGlobalSharedLaterals);

  if( !validQuadToTriReg && ep->mesh.QuadToTri )
    Msg::Error("Mesh of QuadToTri region %d likely has errors.", gr->tag() );

  // If all lateral edges were non-global, skip. (Region should already be meshed properly).
  if( allNonGlobalSharedLaterals )
    return 0;

  Msg::Info("Meshing Region %d (extruded).", gr->tag() );

  GFace *gr_src_face = gr->model()->getFaceByTag( std::abs(ep->geo.Source) );
  if( !gr_src_face ){
    Msg::Error("In meshQuadToTriRegionAfterGlobalSubdivide(), no source face for QuadToTri region %d.", gr->tag());
    return 0;
  }

  for(unsigned int i = 0; i < gr->hexahedra.size(); i++)
    delete gr->hexahedra[i];
  gr->hexahedra.clear();
  for(unsigned int i = 0; i < gr->prisms.size(); i++)
    delete gr->prisms[i];
  gr->prisms.clear();
  for(unsigned int i = 0; i < gr->pyramids.size(); i++)
    delete gr->pyramids[i];
  gr->pyramids.clear();
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
    delete gr->tetrahedra[i];
  gr->tetrahedra.clear();

  std::set<std::pair<MVertex*, MVertex*> > quadToTri_edges;
  std::set<std::pair<MVertex*, MVertex*> > lat_tri_diags;
  std::map<MElement*, std::set<std::pair<unsigned int,unsigned int> > > problems;

  // add edges to quadToTri_edges
  quadToTri_edges.insert( edges->begin(), edges->end() );

  // categorize source face elements
  CategorizedSourceElements cat_src_elems( gr );

  if( !cat_src_elems.valid ){
    Msg::Error("In meshQuadToTriRegionAfterGlobalSubdivide(), "
               "Failed to classify QuadToTri region %d's source face elements "
               "according to boundary status.", gr->tag() );
    return 0;
  }

  // Mesh quadToTri
  if( !QuadToTriEdgeGenerator( gr, cat_src_elems, quadToTri_edges,
                              lat_tri_diags, problems, pos ) ){
    Msg::Error("In meshQuadToTriRegionAfterGlobalSubdivide(), edge generation failed for QuadToTri "
               "region %d.", gr->tag() );
    return 0;
  }
  if( !QuadToTriCreateElements( gr, cat_src_elems, quadToTri_edges,
                               lat_tri_diags, problems, pos ) ){
    Msg::Error("In meshQuadToTriRegionAfterGlobalSubdivide(), element creation failed for QuadToTri "
               "region %d.", gr->tag() );
    return 0;
  }

  QuadToTriLateralRemesh(gr, quadToTri_edges);

  return 1;


}  // end of meshQuadToTriRegionAfterGlobalSubdivide()
