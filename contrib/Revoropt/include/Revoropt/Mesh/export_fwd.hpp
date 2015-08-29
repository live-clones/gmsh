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
#ifndef _REVOROPT_MESH_EXPORT_H_
#define _REVOROPT_MESH_EXPORT_H_

#include <string>

namespace Revoropt {

/* write an obj file to describe the mesh */
template<typename Mesh>
void export_obj( const Mesh* mesh, const std::string& filename ) ;

/* write an obj file to describe the mesh and a mtl file for colors*/
template<typename Mesh>
void export_colored_obj( const Mesh* mesh, 
                         const unsigned int* color_indices,
                         const double* colormap,
                         const std::string& basename 
                       ) ;

} //end of namespace Revoropt

#endif
