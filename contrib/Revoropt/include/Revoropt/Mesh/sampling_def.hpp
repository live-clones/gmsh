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
#ifndef _REVOROPT_MESH_SAMPLING_HPP_
#define _REVOROPT_MESH_SAMPLING_HPP_

#include <Revoropt/Tools/measure_def.hpp>

#include "sampling_fwd.hpp"

namespace Revoropt {

/* Generate a random set of sites on a mesh */
template<typename Triangulation>
void generate_random_sites( const Triangulation* mesh, 
                            unsigned int sites_size,
                            typename Triangulation::Scalar* output_sites, 
                            typename Triangulation::Scalar* triangle_weights,
                            bool reset_random
                          ) {
  //typedefs
  enum { Dim = Triangulation::VertexDim } ;
  typedef typename Triangulation::Scalar Scalar ;
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  //initialize random generator if requested
  if(reset_random) {
    srand(0) ;
  }

  //sizes
  const unsigned int fsize = mesh->faces_size() ;

  //compute the area range of the triangles (without cross products)
  Scalar area_ranges[fsize] ;
  for(unsigned int i=0; i<fsize; ++i) {
    const unsigned int* fverts = mesh->face(i) ;
    const Scalar* v0 = mesh->vertex(fverts[0]) ;
    const Scalar* v1 = mesh->vertex(fverts[1]) ;
    const Scalar* v2 = mesh->vertex(fverts[2]) ;

    const Scalar area = triangle_weights == NULL ?
      triangle_area<Dim>(v0,v1,v2) :
      triangle_weights[i]*triangle_area<Dim>(v0,v1,v2) ;

    area_ranges[i] = i==0 ? area : area_ranges[i-1]+area ;
    if(area_ranges[i] != area_ranges[i]) {
      std::cout << "nan area range for face " << i << ", area " << area_ranges[i] << std::endl ;
      for(int j = 0; j < Dim; ++j) { std::cout << v0[j] << " " ; } ;
      std::cout << std::endl ;
      for(int j = 0; j < Dim; ++j) { std::cout << v1[j] << " " ; } ;
      std::cout << std::endl ;
      for(int j = 0; j < Dim; ++j) { std::cout << v2[j] << " " ; } ;
      std::cout << std::endl ;
      if(triangle_weights != NULL) {
        std::cout << triangle_weights[i] << std::endl ;
      }
      assert(false) ;
    }
  }
  const Scalar max_area = area_ranges[fsize-1] ;

  //generate random sites
  for(unsigned int i=0; i<sites_size; ++i) {
    //get a random triangle by area
    Scalar rand_area = ((Scalar) rand() / (Scalar) RAND_MAX) * max_area ;
    Scalar* pos = std::upper_bound(area_ranges,area_ranges+fsize,rand_area) ;
    unsigned int tri_index = pos - area_ranges ;

    //get random barycentric coordinates
    Scalar u = sqrt((Scalar) rand() / (Scalar) RAND_MAX) ;
    Scalar v = (Scalar) rand() / (Scalar) RAND_MAX ;
    v *= u ;
    u = 1-u ;
    Scalar w = 1-u-v ;
    
    const unsigned int* fverts = mesh->face(tri_index) ;
    Eigen::Map<const Vector> v0(mesh->vertex(fverts[0])) ;
    Eigen::Map<const Vector> v1(mesh->vertex(fverts[1])) ;
    Eigen::Map<const Vector> v2(mesh->vertex(fverts[2])) ;

    //add the new site
    Eigen::Map<Vector> site(output_sites + Dim*i) ;
    site = u*v0 + v*v1 + w*v2 ;
  }
}

} //end of namespace Revoropt

#endif
