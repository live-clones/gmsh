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
#ifndef _REVOROPT_MESH_BASE_DEF_HPP_
#define _REVOROPT_MESH_BASE_DEF_HPP_

#include "base_fwd.hpp"

namespace Revoropt {

/* Basic mesh with constant face size */

template< int FaceSize, int VertexDim, typename Scalar, int VertexOffset >
unsigned int ROMesh<FaceSize, VertexDim, Scalar, VertexOffset
                   >::edge_face_index( unsigned int face_index, 
                                       unsigned int v1, 
                                       unsigned int v2 
                                     ) const {
  //vertices of the face
  const unsigned int* verts = face(face_index) ;
  //loop over the vertices
  for(unsigned int i = 0; i < FaceSize; ++i) {
    unsigned int vi = verts[ i            ] ;
    unsigned int vj = verts[(i+1)%FaceSize] ;
    if(((vi==v1)&&(vj==v2))||((vi==v2)&&(vj==v1))) {
      return i ;
    }
  }
  //if no return was issued before, the edge was not found
  return NO_INDEX ;
}

/* Basic mesh with variable face size */

template< int VertexDim, typename Scalar, int VertexOffset >
unsigned int ROMesh<Variable, VertexDim, Scalar, VertexOffset
                   >::edge_face_index( unsigned int face_index, 
                                       unsigned int v1, 
                                       unsigned int v2 
                                     ) const {
  //vertices of the face
  const unsigned int* verts = face(face_index) ;
  //size of the face
  unsigned int fsize = face_size(face_index) ;
  //loop over the vertices
  for(unsigned int i = 0; i < fsize; ++i) {
    unsigned int vi = verts[ i         ] ;
    unsigned int vj = verts[(i+1)%fsize] ;
    if(((vi==v1)&&(vj==v2))||((vi==v2)&&(vj==v1))) {
      return i ;
    }
  }
  //if no return was issued before, the edge was not found
  return NO_INDEX ;
}

} //end of namespace Revoropt

#endif
