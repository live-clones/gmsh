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
#ifndef _REVOROPT_MESH_WRAPPER_DEF_HPP_
#define _REVOROPT_MESH_WRAPPER_DEF_HPP_

#include "wrapper_fwd.hpp"
#include "base_def.hpp"
#include "connectivity_def.hpp"

namespace Revoropt {

/*** Triangulation wrapper, triangulating a mesh ***/

/* fixed face size case */
template< int VertexDim, typename Scalar, int VertexOffset>
void ROTriangulationWrapper<VertexDim,Scalar,VertexOffset>::set_faces( 
  const unsigned int* faces, 
  unsigned int face_size, 
  unsigned int faces_size
) {
  //reset the triangle vector
  triangles_.resize(0) ;

  //split every single face
  for( unsigned int face_index = 0; 
       face_index < faces_size; 
       ++face_index ) {
    //face vertex indices
    const unsigned int* face_vertices = faces + face_size*face_index ;
    split_polygon(face_vertices, face_size) ;
  }

  //assign Mesh data fields
  Base::faces_ = triangles_.data() ;
  Base::faces_size_ = triangles_.size() / 3 ;
  c_computer_.compute_connectivity() ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
}

/* variable face size case */
template< int VertexDim, typename Scalar, int VertexOffset>
void ROTriangulationWrapper<VertexDim,Scalar,VertexOffset>::set_faces( 
  const unsigned int* faces, 
  const unsigned int* face_ends, 
  unsigned int faces_size
) {
  //reset the triangle vector
  triangles_.resize(0) ;

  //current face position
  const unsigned int* current_face = faces ;

  //split every single face
  for( unsigned int face_index = 0; 
       face_index < faces_size; 
       ++face_index ) {
    //face vertex indices
    const unsigned int face_size = 
      (faces + face_ends[face_index]) - current_face ;
    split_polygon(current_face, face_size) ;
    current_face = faces + face_ends[face_index] ;
  }

  //assign Mesh data fields
  Base::faces_ = triangles_.data() ;
  Base::faces_size_ = triangles_.size() / 3 ;
  c_computer_.compute_connectivity() ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
}

/* naïvely split a polygon into triangles */
template< int VertexDim, typename Scalar, int VertexOffset>
void ROTriangulationWrapper<VertexDim,Scalar,VertexOffset>::split_polygon( 
  const unsigned int* polygon_vertices, 
  unsigned int polygon_size
) {
  //iterate on edges
  for( unsigned int vertex_index = 1; 
       vertex_index < polygon_size-1; 
       ++vertex_index ) {
    //add a triangle to the triangle vector
    triangles_.push_back(polygon_vertices[0             ]) ;
    triangles_.push_back(polygon_vertices[vertex_index  ]) ;
    triangles_.push_back(polygon_vertices[vertex_index+1]) ;
  }
}

} //end of namespace Revoropt

#endif
