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
#ifndef _REVOROPT_RVD_ANN_BACKEND_HPP_
#define _REVOROPT_RVD_ANN_BACKEND_HPP_

#include <ANN/ANN.h>
#include <vector>
#include <iostream>

namespace Revoropt {

/** Nearest neighbour backend for ann **/

template<int _Dim>
class ANNBackend {

  public :

  /* Types and template data */
  enum { Dim = _Dim } ;

  /* Initialization, destruction */
  ANNBackend() : ann_sites_(NULL), ann_tree_(NULL) {
  }

  ANNBackend( const double* sites, 
              unsigned int sites_size
            ) : ann_sites_(NULL), ann_tree_(NULL) {
    set_sites(sites, sites_size) ;
  }
            
  ~ANNBackend() {
    delete [] ann_sites_ ;
    delete ann_tree_ ;
    //annClose() ; // FIXME : memory leak if not used after all ann trees are
    //deleted, perhaps use a static counter of instances and close when instances
    //of clippers fall to 0. Would however break any other ANN tree built in a
    //program using this code, which is highly undesireable. Memory leak may
    //therefore be the only solution.
  }

  /* Nearest site */
  void knnSearch( const double* query, unsigned int size,
                  unsigned int* nnsites, double* nndistances
                ) {
    ann_tree_->annkSearch( const_cast<double*>(query), 
                           size,
                           (int*) nnsites, 
                           nndistances
                         ) ;
  }

  /* Overloading site setting in clipper to update nearest neighbours */
  void set_sites( const double* sites, unsigned int sites_size ) {
    //build ann tree
    delete [] ann_sites_ ;
    delete ann_tree_ ;

    ann_sites_ = new double*[sites_size] ;
    for(unsigned int i=0 ; i < sites_size ; ++i) {
      ann_sites_[i] = const_cast<double*>(sites + Dim*i) ;
    }

    ann_tree_ = new ANNkd_tree(ann_sites_, sites_size, Dim) ;
  }

  private :

  /* ANN data */
  double** ann_sites_ ;
  ANNkd_tree* ann_tree_ ;
} ;

} //end of namespace Revoropt

#endif
