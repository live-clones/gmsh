// @licstart revoropt
// This file is part of Revoropt, a library for the computation and 
// optimization of restricted Voronoi diagrams.
//
// Copyright (C) 2013 Vincent Nivoliers <vincent.nivoliers@univ-lyon1.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
// @licend revoropt
#ifndef _REVOROPT_MESH_CONNECTIVITY_DEF_HPP_
#define _REVOROPT_MESH_CONNECTIVITY_DEF_HPP_

#include "connectivity_fwd.hpp"

namespace Revoropt {

/***{{{ Connectivity computer ***/

template<typename MeshType>
void ConnectivityComputer<MeshType>::glue_face( unsigned int face_index ) {
  //number of edges of the face
  const unsigned int face_size = mesh_->face_size(face_index) ;
  //vertex indices of the face
  const unsigned int* face_vertices = mesh_->face(face_index) ;

  //iterate on edges
  for(unsigned int edge_index = 0; edge_index<face_size; ++edge_index) {
    //vertices of the edge
    const unsigned int v0 = face_vertices[ edge_index             ] ;
    const unsigned int v1 = face_vertices[(edge_index+1)%face_size] ;

    //build the edge
    EdgeKey edge(v0, v1) ;

    //info relative to this edge
    EdgeInfo edge_info(face_index,edge_index) ;

    //try to insert the edge in the border edges
    bedge_iterator it = border_edges_.find(edge) ;

    //connect the triangles if an other edge was already present
    if(it != border_edges_.end()) {
      //the edge is a border edge, connect the triangles
      //index of the neighbouring face
      const unsigned int n_face_index = it->second.first ;
      //edge index of the current edge in the neighbouring face
      const unsigned int n_edge_index = it->second.second ;
      //assign the neighbour of the current face
      face_neighbours(face_index)[edge_index] = n_face_index ;
      //assign the neighbour of the neighbouring face
      face_neighbours(n_face_index)[n_edge_index] = face_index ;
      //delete the edge from border edges
      border_edges_.erase(it) ;
    } else {
      border_edges_[edge] = edge_info ;
      //assign the edge as a border edge 
      face_neighbours(face_index)[edge_index] = NO_NEIGHBOUR ;
    }
  }
}

template<typename MeshType>
void ConnectivityComputer<MeshType>::glue_faces( unsigned int face_start,
                                                 unsigned int face_end
                                               ) {
  //iterate over the faces to glue
  for( unsigned int face_index = face_start; 
       face_index < face_end; 
       ++face_index
     ) {
    //glue the face
    glue_face(face_index) ;
  }
}

template<typename MeshType>
void ConnectivityComputer<MeshType>::unglue_face( unsigned int face_index ) {
  //number of edges of the face
  const unsigned int face_size = mesh_->face_size(face_index) ;
  //vertex indices of the face
  const unsigned int* face_vertices = mesh_->face(face_index) ;

  //iterate on edges
  for(unsigned int edge_index = 0; edge_index<face_size; ++edge_index) {
    //vertices of the edge
    const unsigned int v0 = face_vertices[ edge_index             ] ;
    const unsigned int v1 = face_vertices[(edge_index+1)%face_size] ;

    //build the edge
    EdgeKey edge(v0, v1) ;

    //get the neighbouring face information
    const unsigned int n_face_index = 
      face_neighbours(face_index)[edge_index] ;

    if(n_face_index == NO_NEIGHBOUR) {
      //if the edge is a border edge, remove it from the border edges
      border_edges_.erase(edge) ;
    } else {
      //corresponding edge index in the neighbouring face
      unsigned int n_edge_index = 
        mesh_->edge_face_index(n_face_index,v0,v1) ;
      assert( n_edge_index!=MeshType::NO_INDEX && 
              "error : connectivity mismatch."
            ) ;
      //info relative to the neighbouring edge
      EdgeInfo edge_info(n_face_index,n_edge_index) ;

      //try to insert the edge in the border edges
      bedge_iterator it = border_edges_.find(edge) ;

      //connect the triangles if an other edge was already present
      if(it != border_edges_.end()) {
        //the edge is a border edge, connect the triangles
        //index of the neighbouring face
        const unsigned int nn_face_index = it->second.first ;
        //edge index of the current edge in the neighbouring face
        const unsigned int nn_edge_index = it->second.second ;
        //assign the neighbour of the current face
        face_neighbours(n_face_index)[n_edge_index] = nn_face_index ;
        //assign the neighbour of the neighbouring face
        face_neighbours(nn_face_index)[nn_edge_index] = n_face_index ;
        //delete the edge from border edges
        border_edges_.erase(it) ;
      } else {
        border_edges_[edge] = edge_info ;
        //assign the edge as a border edge 
        face_neighbours(n_face_index)[n_edge_index] = NO_NEIGHBOUR ;
      }
    }
  }
}

template<typename MeshType>
void ConnectivityComputer<MeshType>::unglue_faces( unsigned int face_start,
                                                   unsigned int face_end
                                                 ) {
  //iterate over the faces to glue
  for( unsigned int face_index = face_start; 
       face_index < face_end; 
       ++face_index
     ) {
    //glue the face
    unglue_face(face_index) ;
  }
}

template<typename MeshType>
void ConnectivityComputer<MeshType>::erase_neighbourhoods( 
  unsigned int face_start, unsigned int face_end 
) {
  //unglue faces
  unglue_faces(face_start, face_end) ;
  //remove the corresponding neighbourhoods
  if(face_end >= mesh_->faces_size()) {
    //remove all the neighbourhoods up to the end of the array
    const unsigned int begin_index = mesh_->face_offset(face_start) ;
    face_neighbourhoods_.erase( face_neighbourhoods_.begin() + begin_index,
                                face_neighbourhoods_.end()
                              ) ;
  } else {
    //remove the neighbourhoods within the range
    const unsigned int begin_index = mesh_->face_offset(face_start) ;
    const unsigned int end_index = mesh_->face_offset(face_end) ;
    face_neighbourhoods_.erase( face_neighbourhoods_.begin() + begin_index,
                                face_neighbourhoods_.begin() + end_index
                              ) ;
    //shift the indices of the faces after the range
    const unsigned int offset = face_end - face_start ;
    for( unsigned int neighbour = 0 ; 
         neighbour < face_neighbourhoods_.size() ;
         ++neighbour
       ) {
      unsigned int& fneigh = face_neighbourhoods_[neighbour] ;
      if((fneigh >= face_end) && (fneigh != NO_NEIGHBOUR)) {
        face_neighbourhoods_[neighbour] -= offset ;
      }
    }
  }
}

template<typename MeshType>
void ConnectivityComputer<MeshType>::swap( ConnectivityComputer& rhs ) {
  std::swap(mesh_, rhs.mesh_) ;
  face_neighbourhoods_.swap(rhs.face_neighbourhoods_) ;
  border_edges_.swap(rhs.border_edges_) ;
}

//}}}

/***{{{ Edge layer : building edges over a mesh ***/

template< typename Mesh >
void EdgeLayer<Mesh>::update() {
  //one half edge per face vertex
  edges_.resize(mesh_->face_vertices_size()) ;
  //one edge per vertex
  vertex_edges_.assign(mesh_->vertices_size(),NO_EDGE) ;
  //assign (vertex_)edge data
  for(unsigned int face = 0; face < mesh_->faces_size(); ++face) {
    //size of the face
    const unsigned int fsize = mesh_->face_size(face) ;
    //offset of the face
    const unsigned int foffset = mesh_->face_offset(face) ;
    //vertices of the face
    const unsigned int* fverts = mesh_->face(face) ;
    //neighbouring faces of the face
    const unsigned int* fneigh = mesh_->face_neighbours(face) ;
    //edges of the face
    MeshEdge* fedges = face_edges(face) ;
    for(unsigned int i = 0; i < fsize; ++i) {
      //vertices of the edge
      const unsigned int v1 = fverts[ i         ] ;
      const unsigned int v2 = fverts[(i+1)%fsize] ;
      //assign the face of the edge
      fedges[i].face = face ;
      //(re)assign the edge of the vertex
      vertex_edges_[v1] = foffset + i ;
      //test if the edge is a border edge
      const unsigned int n_face = fneigh[i] ;
      if(n_face == Mesh::NO_NEIGHBOUR) {
        //assign the opposite edge as no edge
        fedges[i].opposite = NO_EDGE ;
      } else if(n_face > face) { //to handle ony once pairs of opposite edges
        //neighbouring face offset
        const unsigned int n_foffset = mesh_->face_offset(n_face) ;
        //neighbouring face edges
        MeshEdge* n_fedges = face_edges(n_face) ;
        //edge index in the neighbouring face
        const unsigned int j = mesh_->edge_face_index(n_face, v1, v2) ;
        assert( (j!=Mesh::NO_INDEX) &&
                "The neighbouring face has no such edge"
              ) ;
        fedges[i].opposite = n_foffset + j ;
        n_fedges[j].opposite = foffset + i ;
      }
    }
  }
  //handle border vertices
  for(unsigned int vertex = 0; vertex < mesh_->vertices_size(); ++vertex) {
    //assign the vertex edge to the first border found circulating backwards
    vertex_edges_[vertex] = first_border_vertex_edge(vertex) ;
  }
}

template< typename Mesh >
unsigned int EdgeLayer<Mesh>::first_border_vertex_edge( unsigned int vertex ) {
  //initial edge
  unsigned int edge = vertex_edge(vertex) ;
  //rotate back until a border edge is found
  unsigned int prev_edge = edge ;
  if(edge != NO_EDGE) {
    do {
      prev_edge = edge ;
      edge = prev_around_vertex(vertex, edge) ;
    } while((edge != NO_EDGE) && (edge != vertex_edge(vertex))) ;
  }
  //assign the edge vertex to the last non NO_EDGE edge
  return prev_edge ;
}

//}}}

} //end of namespace Revoropt

#endif

