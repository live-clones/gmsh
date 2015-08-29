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
#ifndef _REVOROPT_TOOLS_NORMALS_FWD_HPP_
#define _REVOROPT_TOOLS_NORMALS_FWD_HPP_

/* Normal of a triangle, with the triangle area as norm */
template<typename Scalar>
void triangle_area_normal( const Scalar* x0_p,
                           const Scalar* x1_p,
                           const Scalar* x2_p,
                           Scalar output[3]
                         ) ;

/* Normalized normal of a triangle, null if the triangle is flat */
template<typename Scalar>
Scalar triangle_normal( const Scalar* x0_p,
                        const Scalar* x1_p,
                        const Scalar* x2_p,
                        Scalar output[3]
                      ) ;

#endif
