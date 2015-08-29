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
#ifndef _REVOROPT_MESH_DEBUG_H_
#define _REVOROPT_MESH_DEBUG_H_

namespace Revoropt {

/* Printing the information relative to a face */
template< typename Mesh >
void print_face( const Mesh* mesh, unsigned int face ) ;

} //end of namespace Revoropt

#endif
