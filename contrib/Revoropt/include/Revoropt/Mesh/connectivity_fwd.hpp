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
#ifndef _REVOROPT_MESH_CONNECTIVITY_FWD_HPP_
#define _REVOROPT_MESH_CONNECTIVITY_FWD_HPP_

#include <Revoropt/Tools/combinatorics.hpp>

#include <assert.h>
#include <vector>
#include <unordered_map>

namespace Revoropt {

/***{{{ Connectivity computer ***/

template<typename MeshType>
class ConnectivityComputer {
  public:

    static const unsigned int NO_NEIGHBOUR ;

    ConnectivityComputer() : mesh_(NULL) {} ;
    ConnectivityComputer( const MeshType* mesh ) : mesh_(mesh) {
      //reset face neighbourhoods
      face_neighbourhoods_.assign(mesh_->face_vertices_size(),NO_NEIGHBOUR) ;
    } ;

    /* Resizing */
    void resize( unsigned int size ) {
      face_neighbourhoods_.resize(size,NO_NEIGHBOUR) ;
    }

    /* Provide a pointer to the neighbourhood array */
    unsigned int* data() {
      return face_neighbourhoods_.data() ;
    }

    const unsigned int* data() const {
      return face_neighbourhoods_.data() ;
    }

    /* Setting the mesh */
    void set_mesh(const MeshType* mesh) {
      mesh_ = mesh ;

      //reset face neighbourhoods
      face_neighbourhoods_.assign(mesh_->face_vertices_size(),NO_NEIGHBOUR) ;

      //Reset border edges
      border_edges_.clear() ;
    }

    /* Incrementally gluing faces  */
    void glue_face( unsigned int face_index ) ;

    void glue_faces( unsigned int face_start, unsigned int face_end ) ;

    /* Ungluing faces */

    void unglue_face( unsigned int face_index ) ;

    void unglue_faces( unsigned int face_start, unsigned int face_end ) ;

    /* Removing faces */

    void erase_neighbourhoods( unsigned int face_start, unsigned int face_end ) ;

    /* Reset neighbourhoods and glue all the faces from scratch */
    void compute_connectivity() {
      //reset border edges
      border_edges_.clear() ;

      //resize according to the mesh
      resize(mesh_->face_vertices_size()) ;

      //glue all the faces
      glue_faces(0,mesh_->faces_size()) ;
    }

    /* Swapping */
    void swap( ConnectivityComputer<MeshType>& rhs ) ;

  private:

    /** Mesh holding the face information **/
    const MeshType* mesh_ ;

    /** Computing the face neighbourhoods **/

    /* Neighbourhood storage */
    std::vector<unsigned int> face_neighbourhoods_ ;

    /* Face neighbours from an index */
    unsigned int* face_neighbours( unsigned int face_index ) {
      const unsigned int offset = mesh_->face_offset(face_index) ;
      return data() + offset ;
    }

    /* Border edges */
    typedef tuplekey<2> EdgeKey ;
    typedef std::pair<unsigned int, unsigned int> EdgeInfo ;
    typedef tuple_hash<2> EdgeHash ;
    typedef std::unordered_map<EdgeKey, EdgeInfo, EdgeHash>::iterator bedge_iterator ;
    std::unordered_map<EdgeKey, EdgeInfo, EdgeHash> border_edges_ ;
} ;

template<typename MeshType>
const unsigned int ConnectivityComputer<MeshType>::NO_NEIGHBOUR = MeshType::NO_NEIGHBOUR ;

//}}}

/***{{{ Edge layer : building edges over a mesh ***/

class MeshEdge {

  public :
  /* other classical half edge data like next, prev, vertex 
   * are available via the mesh on which these edges are built*/

  /* face corresponding to this edge */
  unsigned int face ;

  /* opposite edge index */
  unsigned int opposite ;
} ;

template< typename Mesh >
class EdgeLayer {

  public :

  static const unsigned int NO_EDGE ;

  //TODO boundary

  /** Construction **/

  EdgeLayer( const Mesh* mesh ) : mesh_(mesh) {
    update() ;
  }

  void update() ;

  /* Resize edges according to the faces without initializing them */
  void fit_to_faces() {
    //resize
    edges_.resize(mesh_->face_vertices_size()) ;
  }

  /* Commented since the complexity was nearly that of an update */
  /* Erase edges corresponding to faces. Do it BEFORE erasing faces *//*
  void erase_face_edges( unsigned int start, unsigned int end ) {
    //first edge to remove
    const unsigned int start_edge = mesh_->face_offset(start) ;
    //first edge to keep above range
    const unsigned int end_edge = end >= mesh_->faces_size() ?
      mesh_->face_vertices_size() :
      mesh_->face_offset(end) ;
    //disconnect opposite edges
    for(unsigned int face = start; face < end; ++face) {
      //face size
      const unsigned int fsize = mesh_->face_size(face) ;
      //face edges
      MeshEdge* fedges = face_edges(face) ;
      //iterate over opposite edges
      for(unsigned int edge = 0; edge < fsize; ++edge) {
        //assign opposite edge opposite to NO_EDGE
        if(fedges[edge].opposite != NO_EDGE) {
          edges_[fedges[edge].opposite].opposite = NO_EDGE ;
        }
      }
    }
    //erase edges
    edges_.erase(edges_.begin() + start_edge, edges_.begin() + end_edge) ;
    //number of edges removed
    const unsigned int erase_size = end_edge - start_edge ;
    //number of faces removed
    const unsigned int face_erase_size = end - start ;
    //shift edge indices
    for(unsigned int edge = 0; edge < edges_.size(); ++edge) {
      unsigned int& opp_edge = edges_[edge].opposite ;
      if((opp_edge != NO_EDGE) && (opp_edge > start_edge)) {
        opp_edge -= erase_size ;
      }
      unsigned int& face = edges_[edge].face ;
      if(face >= start) {
        face -= face_erase_size ;
      }
    }
    //reset vertex edges
    for(unsigned int face = 0; face < mesh_->faces_size(); ++face) {
      if((face < start) || (face >= end)) {
        //size of the face
        const unsigned int fsize = mesh_->face_size(face) ;
        //offset of the face
        const unsigned int foffset = mesh_->face_offset(face) ;
        //vertices of the face
        const unsigned int* fverts = mesh_->face(face) ;
        for(unsigned int i = 0; i < fsize; ++i) {
          //vertices of the edge
          const unsigned int v1 = fverts[i] ;
          //(re)assign the edge of the vertex
          vertex_edges_[v1] = foffset + i ;
        }
      }
    }
    for(unsigned int vertex = 0; vertex < mesh_->vertices_size(); ++vertex) {
      //assign the vertex edge to the first border found circulating backwards
      vertex_edges_[vertex] = first_border_vertex_edge(vertex) ;
      //shift if necessary
      unsigned int& vedge = vertex_edges_[vertex] ;
      if((vedge != NO_EDGE) && (vedge > start_edge)) {
        vedge -= erase_size ;
      }
    }
  }
  */

  /** Access **/

  /* edge from its index */
  MeshEdge* edge_info( unsigned int index ) {
    return edges_.data() + index ;
  }

  /* edge array of a face */
  MeshEdge* face_edges( unsigned int index ) {
    return edges_.data() + mesh_->face_offset(index) ;
  }

  /* edge of a vertex */
  unsigned int vertex_edge( unsigned int vertex ) {
    if(vertex >= mesh_->vertices_size()) return NO_EDGE ;
    return vertex_edges_[vertex] ;
  }

  /** Tools **/

  /* opposite edge */
  unsigned int edge_opposite( unsigned int edge ) {
    if(edge == NO_EDGE) return NO_EDGE ;
    return edge_info(edge)->opposite ;
  }

  /* face of an edge */
  unsigned int edge_face( unsigned int edge ) {
    if(edge == NO_EDGE) return Mesh::NO_NEIGHBOUR ;
    return edge_info(edge)->face ;
  }

  /* index of an edge from its pointer */
  unsigned int edge_index( MeshEdge* edge ) {
    if((edge >= edges_.data()) && (edge < edges_.data() + edges_.size())) {
      return (unsigned int) (edge - edges_.data()) ;
    } else {
      return NO_EDGE ;
    }
  }

  /* index of an edge within its face */
  unsigned int edge_face_index( unsigned int edge ) {
    return edge - mesh_->face_offset(edges_[edge].face) ;
  }

  /* vertex at the start of the edge */
  unsigned int edge_start_vertex( unsigned int edge ) {
    //face of the edge
    const unsigned int face = edge_face(edge) ;
    //offset of the face
    const unsigned int foffset = mesh_->face_offset(face) ;
    //edge index within the face
    const unsigned int efindex = edge - foffset ;
    //face vertices
    const unsigned int* fverts = mesh_->face(face) ;
    //output
    return fverts[efindex] ;
  }

  /* vertex at the start of the edge */
  unsigned int edge_end_vertex( unsigned int edge ) {
    //face of the edge
    const unsigned int face = edge_face(edge) ;
    //size of the face
    const unsigned int fsize = mesh_->face_size(face) ;
    //offset of the face
    const unsigned int foffset = mesh_->face_offset(face) ;
    //edge index within the face
    const unsigned int efindex = edge - foffset ;
    //face vertices
    const unsigned int* fverts = mesh_->face(face) ;
    //output
    return fverts[(efindex+1)%fsize] ;
  }

  /* vertex of the edge different from the provided one */
  unsigned int edge_other_vertex( unsigned int edge, unsigned int vertex ) {
    //face of the edge
    const unsigned int face = edge_face(edge) ;
    //size of the face
    const unsigned int fsize = mesh_->face_size(face) ;
    //offset of the face
    const unsigned int foffset = mesh_->face_offset(face) ;
    //edge index within the face
    const unsigned int efindex = edge - foffset ;
    //face vertices
    const unsigned int* fverts = mesh_->face(face) ;
    //output
    if(fverts[efindex] == vertex) {
      return fverts[(efindex+1)%fsize] ;
    } else {
      return fverts[ efindex         ] ;
    }
  }

  /* test if the opposite edge has a lower index */
  bool is_resp( unsigned int edge ) {
    unsigned int opp_edge = edge_opposite(edge) ;
    //implicitly works for NO_EDGE since it is the biggest unsigned int
    return (edge < opp_edge) ;
  }

  /* test if the edge is on the boundary */
  bool is_border( unsigned int edge ) {
    unsigned int opp_edge = edge_opposite(edge) ;
    //implicitly works for NO_EDGE since it is the biggest unsigned int
    return (opp_edge == NO_EDGE) ;
  }

  /** Circulation **/

  /* Around faces */

  /* next edge around a face */
  unsigned int next_around_face( unsigned int edge ) {
    //face of the edge
    const unsigned int face = edge_face(edge) ;
    //size of the face
    const unsigned int fsize = mesh_->face_size(face) ;
    //offset of the face
    const unsigned int foffset = mesh_->face_offset(face) ;
    //edge index within the face
    const unsigned int efindex = edge - foffset ;
    //next edge index within the face
    const unsigned int next_efindex = (efindex+1)%fsize ;
    //output
    return foffset + next_efindex ;
  }

  /* previous edge around a face */
  unsigned int prev_around_face( unsigned int edge ) {
    //face of the edge
    const unsigned int face = edge_face(edge) ;
    //size of the face
    const unsigned int fsize = mesh_->face_size(face) ;
    //offset of the face
    const unsigned int foffset = mesh_->face_offset(face) ;
    //edge index within the face
    const unsigned int efindex = edge - foffset ;
    //previous edge index within the face
    const unsigned int prev_efindex = (efindex+fsize-1)%fsize ;
    //output
    return foffset + prev_efindex ;
  }

  /* Around vertices */

  /* circulation direction : given an edge, next searches the other edge sharing
   * the vertex in the same face, and returns the edge opposite to this other
   * edge. This ensures circulation. If the mesh is consistently oriented, the
   * circulation direction is positive if the provided edge starts at the
   * vertex, and negative otherwise. */

  /* next edge around a vertex */
  unsigned int next_around_vertex( unsigned int vertex, unsigned int edge ) {
    //if NO_EDGE is provided, circulation is finished
    if(edge == NO_EDGE) {
      return NO_EDGE ;
    }
    //find the other edge in the face pointing at this edge
    unsigned int other_edge = other_face_edge_for_vertex(vertex, edge) ;
    //return its opposite
    return edge_opposite(other_edge) ;
  }

  /* previous edge around a vertex */
  unsigned int prev_around_vertex( unsigned int vertex, unsigned int edge ) {
    //if NO_EDGE is provided, circulation is finished
    if(edge == NO_EDGE) {
      return NO_EDGE ;
    }
    //opposite edge
    const unsigned int opp_edge = edge_opposite(edge) ;
    //if no opposite edge exists, circulation is finished
    if(opp_edge == NO_EDGE) {
      return NO_EDGE ;
    }
    //find the other edge pointing at this vertex
    return other_face_edge_for_vertex(vertex,opp_edge) ;
  }

  /* other edge in the same face using a vertex */
  unsigned int other_face_edge_for_vertex( unsigned int vertex, 
                                           unsigned int edge 
                                         ) {
    if(edge_start_vertex(edge) == vertex) {
      return prev_around_face(edge) ;
    } else {
      if(edge_end_vertex(edge) == vertex) {
        return next_around_face(edge) ;
      } else {
        return NO_EDGE ;
      }
    }
  }

  private :

  /* Rotate around a vertex to set the vertex edge to a border edge if any */
  unsigned int first_border_vertex_edge( unsigned int vertex ) ;

  /* Mesh */
  const Mesh* mesh_ ;

  /* Half edges, stored per face with the same layout as the vertices */
  std::vector<MeshEdge> edges_ ;

  /* One edge per vertex */
  std::vector<unsigned int> vertex_edges_ ;
} ;

template<typename Mesh>
const unsigned int EdgeLayer<Mesh>::NO_EDGE = -1 ;

//}}}

} //end of namespace Revoropt

#endif
