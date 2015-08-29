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
#ifndef _REVOROPT_RVD_FLANN_BACKND_HPP_
#define _REVOROPT_RVD_FLANN_BACKND_HPP_

#include <flann/flann.hpp>
#include <vector>
#include <iostream>

namespace Revoropt {

/** Nearest neighbour backend for flann **/

template<int _Dim>
class FLANNBackend {

  public :

  /* Types and template data */
  enum { Dim = _Dim } ;

  /* Initialization, destruction */
  FLANNBackend() : index_(flann::KDTreeSingleIndexParams(10)),
                   flann_params_(flann::FLANN_CHECKS_UNLIMITED,0,true) {
  }

  FLANNBackend( const double* sites, 
                unsigned int sites_size
              ) : index_(flann::KDTreeSingleIndexParams(10)),
                  flann_params_(flann::FLANN_CHECKS_UNLIMITED,0,true) {
    set_sites(sites, sites_size) ;
  }

  /* Nearest neighbours */
  void knnSearch( const double* query, unsigned int size, 
                  unsigned int* nnsites, double* nndistances 
                ) {
    //convert input to flann matrices
    flann::Matrix<double> flann_query(const_cast<double*>(query), 1, Dim) ;
    flann::Matrix<int> flann_nnsites((int*) nnsites, 1, size) ;
    flann::Matrix<double> flann_nndistances(nndistances, 1, size) ;

    //query
    index_.knnSearch( flann_query, 
                      flann_nnsites, 
                      flann_nndistances,
                      size,
                      flann_params_
                    ) ;
  }

  /* Overloading site setting in clipper to update nearest neighbours */
  void set_sites( const double* sites, unsigned int sites_size ) {
    //build flann index
    flann_points_ = flann::Matrix<double>( 
      const_cast<double*>(sites), sites_size, Dim
    ) ;
    index_.buildIndex(flann_points_) ;
  }

  private :

  /* FLANN data */
  flann::Matrix<double> flann_points_ ;
  flann::Index< flann::L2<double> > index_ ;

  /* Parameters */
  flann::SearchParams flann_params_ ;
} ;

//}}}

} //end of namespace Revoropt

#endif
