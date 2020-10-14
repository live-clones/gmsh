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
#ifndef _REVOROPT_TOOLS_NORMALS_DEF_HPP_
#define _REVOROPT_TOOLS_NORMALS_DEF_HPP_

#include <Eigen/Dense>

/* Normal of a triangle, with the triangle area as norm */
template<typename Scalar>
void triangle_area_normal( const Scalar* x0_p,
                           const Scalar* x1_p,
                           const Scalar* x2_p,
                           Scalar output[3]
                         ) {
  //vector type
  typedef Eigen::Matrix<Scalar,3,1> Vector ;
  //map vertices to eigen vectors
  Eigen::Map< const Vector> x0(x0_p) ;
  Eigen::Map< const Vector> x1(x1_p) ;
  Eigen::Map< const Vector> x2(x2_p) ;

  //map output to an eigen vector
  Eigen::Map<Vector> normal(output) ;

  //compute
  normal = 0.5*(x1-x0).cross(x2-x0) ;
}

/* Normalized normal of a triangle, null if the triangle is flat */
template<typename Scalar>
Scalar triangle_normal( const Scalar* x0_p,
                        const Scalar* x1_p,
                        const Scalar* x2_p,
                        Scalar output[3]
                      ) {
  //vector type
  typedef Eigen::Matrix<Scalar,3,1> Vector ;
  //get the area normal
  triangle_area_normal(x0_p,x1_p,x2_p,output) ;

  //map output to an eigen vector
  Eigen::Map<Vector> normal(output) ;

  //norm of the normal
  const Scalar n_len = normal.norm() ;
  if(n_len != 0) {
    normal /= n_len ;
  }
  return n_len ;
}

#endif
