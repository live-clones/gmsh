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
#ifndef _REVOROPT_MESH_DEBUG_DEF_HPP_
#define _REVOROPT_MESH_DEBUG_DEF_HPP_

#include <iostream>
#include "debug_fwd.hpp"

namespace Revoropt {

/* Printing the information relative to a face */
template< typename Mesh >
void print_face( const Mesh* mesh, unsigned int face ) {
  std::cout << "=== face " << face << " ===" << std::endl ;
  if(face == Mesh::NO_NEIGHBOUR) return ;
  //face size
  const unsigned int fsize = mesh->face_size(face) ;
  //face vertices
  const unsigned int* fverts = mesh->face(face) ;
  //face neighbours
  const unsigned int* fneigh = mesh->face_neighbours(face) ;
  //display edge information
  for(unsigned int edge = 0; edge < fsize; ++edge) {
    //vertices of the edge
    const unsigned int v0 = fverts[ edge         ] ;
    const unsigned int v1 = fverts[(edge+1)%fsize] ;
    //display the edge vertices and neighbours
    std::cout << " * (" << v0 << "," << v1 << ") : " << fneigh[edge] << std::endl ;
  }
}

} //end of namespace Revoropt

#endif
