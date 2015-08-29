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
#ifndef _REVOROPT_MESH_SAMPLING_FWD_HPP_
#define _REVOROPT_MESH_SAMPLING_FWD_HPP_

namespace Revoropt {

/* Generate a random set of sites on a mesh */
template<typename Triangulation>
void generate_random_sites( const Triangulation* mesh, 
                            unsigned int sites_size,
                            typename Triangulation::Scalar* output_sites, 
                            typename Triangulation::Scalar* triangle_weights = NULL,
                            bool reset_random = false
                          ) ;

} //end of namespace Revoropt

#endif
