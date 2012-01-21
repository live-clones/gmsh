/************************************************************************************************** 
QuadTriTransfinite3D.cpp

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

#include "QuadTriTransfinite3D.h"

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


static void addTetrahedron(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4, 
                           GRegion *to)
{
  MTetrahedron* newElem = new MTetrahedron(v1, v2, v3, v4);
  to->tetrahedra.push_back(newElem);
}

static void addPyramid(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                       MVertex* v5, GRegion *to)
{
  MPyramid* newElem = new MPyramid(v1, v2, v3, v4, v5);
  to->pyramids.push_back(newElem);
}

static void addPrism(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                     MVertex* v5, MVertex* v6, GRegion *to)
{
  MPrism* newElem = new MPrism(v1, v2, v3, v4, v5, v6);
  to->prisms.push_back(newElem);
}

static void addHexahedron(MVertex* v1, MVertex* v2, MVertex* v3, MVertex* v4,
                          MVertex* v5, MVertex* v6, MVertex* v7, MVertex* v8,
                          GRegion *to)
{
  MHexahedron* newElem = new MHexahedron(v1, v2, v3, v4, v5, v6, v7, v8);
  to->hexahedra.push_back(newElem);
}


// Function to get all the diagonals from external surfaces of a given Transfinite region tr
// and place them in boundary_diags.
int getTransfiniteBoundaryDiags( GRegion *gr, std::set< std::pair<MVertex*,
				              MVertex*> > *boundary_diags )
{
  // Get list of faces
  std::list<GFace*> faces = gr->faces();

  // Perform some tests of the Transfinite volume

  // Is the region Transfinite?
  if( gr->meshAttributes.Method != MESH_TRANSFINITE ){
    Msg::Error( "In getTransfiniteBoundaryDiags(), region %d was not detected "
                "to be a transfinite volume", gr->tag() );
    return 0;
  }
  
  // Found right number of faces?
  if( faces.size() != 5 && faces.size() != 6 ){
    Msg::Error( "In getTransfiniteBoundaryDiags(), number of faces does not equal "
                "5 or 6 for region %d.", gr->tag() );
    return 0;
  }

  // Are all the faces Transfinite?
  std::list<GFace*>::iterator itf;
  for( itf = faces.begin(); itf != faces.end(); itf++ ){
    if( (*itf)->meshAttributes.Method != MESH_TRANSFINITE ){
      Msg::Error( "In getTransfiniteBoundaryDiags(), surface %d was not detected "
                  "to be transfinite", (*itf)->tag() );
      return 0;
    }
    if( !(*itf)->transfinite_vertices.size() ){
      Msg::Error( "In getTransfiniteBoundaryDiags(), no transfinite vertices found for "
                  "surface %d.", (*itf)->tag() );
      return 0;
    }
  }
    
  
  // Now loop through all surfaces checking for unrecombined faces. On 3-sided surfaces, skip the 
  // first layer of triangles because they ALWAYS exist even for recombined faces.
  for( itf = faces.begin(); itf != faces.end(); itf++ ){
    if( (*itf)->quadrangles.size() )
      continue;
    // For this face, loop through all sets of 4 vertices that could form a quadrangle
    // if not subdivided.  Find which of the 4 vertices are on the diagonal that subdivides
    // the four vertices.
    std::list<GEdge*> edges = (*itf)->edges();
    int index_guess = 0;
    int i_low = 0;
    if( edges.size() == 3 ){
      if( (*itf)->transfinite_vertices.size() <= 2 )
        continue;
      index_guess += (*itf)->transfinite_vertices[1].size()-1;
      i_low = 1;
    }
 
    for( int i = i_low; i < (*itf)->transfinite_vertices.size()-1; i++ ){
      for( int j = 0; j < (*itf)->transfinite_vertices[i].size()-1; j++ ){
        std::vector<MVertex*> verts;
        verts.resize(4);
        verts[0] = (*itf)->transfinite_vertices[i][j];
        verts[1] = (*itf)->transfinite_vertices[i+1][j];
        verts[2] = (*itf)->transfinite_vertices[i+1][j+1];
        verts[3] = (*itf)->transfinite_vertices[i][j+1];
        std::pair<int,int> ind_pair = FindDiagonalEdgeIndices( verts, (*itf), 
                                                               0, index_guess );
        createEdge( verts[ind_pair.first], verts[ind_pair.second], (*boundary_diags) );         
        index_guess += 2;
      }
    }
  }

  return 1;

} // End of getTransfiniteBoundaryDiags()


// Meshes either a prism or a hexahedral set of mesh vertices in a Transfinite Region with an internal vertex 
// that is created here in the function.
void meshTransfElemWithInternalVertex( GRegion *gr, std::vector<MVertex *> v, 
                                       std::set< std::pair<MVertex*, MVertex*> > *boundary_diags )
{
    
  int v_size = v.size();
  int n_lat_tmp;
  if( v_size == 6 )
    n_lat_tmp = 3;
  else if( v_size == 8 )
    n_lat_tmp = 4;
  else{
    Msg::Error("In meshTransfElemWithInternalVertex(), number of element vertices does not equal 6 or 8.");
    return;
  }

  const int n_lat = n_lat_tmp;

  
  // find vertex node indices for diagonalized faces
  std::vector<int> n1, n2;
  bool found_diags = false;
  int n_size = 0;
  if( n_lat == 3 ){
    n1.assign(n_lat, -1);
    n2.assign(n_lat, -2);
    n_size = 3;
  }
  else if( n_lat == 4 ){
    n1.assign(n_lat+2, -1);
    n2.assign(n_lat+2, -1);
    n_size = 6;
  }

  for( int p = 0; p < n_size; p++ ){
    n1[p] = -p*p-p-1; n2[p] = -p*p-p-2;
    if( p < n_lat || n_lat == 3 ){
      if( v[p] == v[p+n_lat] || v[(p+1)%n_lat] == v[(p+1)%n_lat+n_lat] )
        continue;
      else if( edgeExists( v[p], v[(p+1)%n_lat+n_lat], (*boundary_diags) ) ){
        n1[p] = p; n2[p] = (p+1)%n_lat+n_lat;
        found_diags = true;
      } 
      else if( edgeExists( v[p+n_lat], v[(p+1)%n_lat], (*boundary_diags) ) ){
        n1[p] = p+n_lat; n2[p] = (p+1)%n_lat;
        found_diags = true;
      }
    }
    else{
      int add = ( p == n_lat ) ? 0 : n_lat;
      if( edgeExists( v[add], v[add+2], (*boundary_diags) ) ){
        n1[p] = add; n2[p] = add+2;
        found_diags = true;
      } 
      else if( edgeExists( v[add+1], v[add+3], (*boundary_diags) ) ){
        n1[p] = add+1; n2[p] = add+3;
        found_diags = true;
      }
    }
  }


 
  if( !found_diags ){
    if( n_lat == 3 )
      addPrism( v[0], v[1], v[2], v[3], v[4], v[5], gr );
    else if( n_lat ==4 )
      addHexahedron( v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], gr );
    return;
  }

  // make the internal vertex
  std::vector<double> centroid = QtFindVertsCentroid(v);
  MVertex *v_int = new MVertex(centroid[0], centroid[1], centroid[2], gr);
  gr->mesh_vertices.push_back( v_int );

  // build all pyramids/tetra
  for( int p = 0; p < n_lat; p++ ){
    int p2 = (p+1)%n_lat; 
    if( v[p] == v[p+n_lat] && v[p2] == v[p2+n_lat] )
      continue;
    else if( v[p] == v[p+n_lat] || v[p2] == v[p2+n_lat] ){
      MVertex *v_dup = (v[p] == v[p+n_lat]) ? v[p] : v[p2];
      MVertex *v_non_dup = (v_dup == v[p]) ? v[p2] : v[p];
      MVertex *v_non_dup2 = (v_non_dup == v[p]) ? v[p+n_lat] : v[p2+n_lat]; 
      addTetrahedron( v_dup, v_non_dup, v_non_dup2, v_int, gr);  
    }
    else if( n1[p] == p || n2[p] == p ){
      addTetrahedron( v[p], v[p2], v[p2+n_lat], v_int, gr );  
      addTetrahedron( v[p], v[p2+n_lat], v[p+n_lat], v_int, gr );  
    }
    else if( n1[p] == p+n_lat || n2[p] == p+n_lat ){  
      addTetrahedron( v[p], v[p2], v[p+n_lat], v_int, gr );  
      addTetrahedron( v[p2], v[p2+n_lat], v[p+n_lat], v_int, gr );  
    }  
    else
      addPyramid( v[p], v[p2], v[p2+n_lat], v[p+n_lat], v_int, gr );
  }

  if( n_lat == 3){
    // bottom and top
    addTetrahedron( v[0], v[1], v[2], v_int, gr );   
    addTetrahedron( v[3], v[5], v[4], v_int, gr );
  }
  else if( n_lat == 4 ){
    for( int p = 4; p < 6; p++ ){
      int add = (p == 4) ? 0 : 4;
      if( n1[p] == 0+add || n2[p] == 0+add  ){
        addTetrahedron( v[add], v[1+add], v[2+add], v_int, gr );  
        addTetrahedron( v[add], v[2+add], v[3+add], v_int, gr );  
      }
      else if( n1[p] == 1+add || n2[p] == 1+add ){  
        addTetrahedron( v[1+add], v[2+add], v[3+add], v_int, gr );  
        addTetrahedron( v[1+add], v[3+add], v[add], v_int, gr );  
      }  
      else
        addPyramid( v[add], v[1+add], v[2+add], v[3+add], v_int, gr );
    }
  } 

} // End of meshTransfiniteWithInternalVertex()
