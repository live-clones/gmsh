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
#ifndef _REVOROPT_VSDM_REGUL_HPP_
#define _REVOROPT_VSDM_REGUL_HPP_

#include <Revoropt/RVD/rvd.hpp>

#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace Revoropt {

namespace VSDM {

//add the opportunity to modify the value of an Eigen::Triplet
class my_triplet : public Eigen::Triplet<double> {

  public:

  my_triplet(unsigned int i, unsigned int j, double value) :
    Eigen::Triplet<double>(i,j,value) {
  }

  //incrementation
  void incr_value() {
    ++m_value ;
  }
  //new value
  void set_value( double value ) {
    m_value = value ;
  }
} ;

template<int Dim>
class RegulTerm {

  public :

  RegulTerm(bool reset_gradient = true) :
      reset_gradient_(reset_gradient),
      factor_(1)
  {}

  /* Change the factor value. The default factor is 1/vsize where vsize is the
   * number of vertices of the mesh. The provided factor will be divided by
   * vsize as well.*/
  template<typename Mesh>
  void build_matrix(const Mesh* mesh) {
    //Size of the matrix
    unsigned int vsize = mesh->vertices_size() ;

    //Use triplets to encode a sparse matrix
    std::vector<my_triplet> triplets ;
    //1 coeff per vertex plus 2 per edge. At least 3*face_size/2 edges.
    triplets.reserve(vsize + 3*mesh->faces_size()) ;
    //the first triplets correspond to the vertices of the mesh
    for(unsigned int i = 0; i < vsize; ++i) {
      //assign the col and row of the diagonal coeffs
      triplets.push_back(my_triplet(i,i,0)) ;
    }
    //Build the quatratic form matrix
    for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
      //face data
      const unsigned int fsize = mesh->face_size(f) ;
      const unsigned int* fverts = mesh->face(f) ;
      const unsigned int* fneigh = mesh->face_neighbours(f) ;

      //iterate on edges to build edge coeffs and count edges for a vertex
      for(unsigned int v = 0; v < fsize; ++v) {
        //get the vertices of the edge
        unsigned int v1 = fverts[ v         ] ;
        unsigned int v2 = fverts[(v+1)%fsize] ;

        //to avoid treating edges twice, check canonical order
        if(f < fneigh[v]) {
          //increase vertex neighbourhood size
          triplets[v1].incr_value() ;
          triplets[v2].incr_value() ;

          //add coefficients
          triplets.push_back(my_triplet(v1,v2,1)) ;
          triplets.push_back(my_triplet(v2,v1,1)) ;
        }
      }
    }

    //Divide each edge coeff by the vertex neighbourhood size corresponding to its vertex
    for(unsigned int i = vsize; i < triplets.size(); ++i) {
      my_triplet& coeff = triplets[i] ;
      coeff.set_value(coeff.value()/triplets[coeff.row()].value()) ;
    }

    //Reset diagonal coeffs to -1
    for(unsigned int i = 0; i < vsize; ++i) {
      //std::cout << "Diagonal triplet has value " << triplets[i].value() << std::endl ;
      triplets[i].set_value(-1) ;
    }

    //Build matrix
    L_.resize(vsize, vsize) ;
    L_.setFromTriplets(triplets.begin(), triplets.end()) ;
  }

  void set_factor( double factor ) {
    factor_ = factor ;
  }

  template<typename Data>
  double operator()( Data* data ) {
    if(reset_gradient_) {
      std::fill(data->g, data->g+data->n,0) ;
    }

    double fx = 0 ;

    //accumulate result for each coordinate
    for(int i = 0; i < Dim; ++i) {
      //Map the raw pointer data to Eigen vector
      Eigen::Map< Eigen::VectorXd,
        Eigen::Unaligned,
        Eigen::Stride<0,Dim>
          > g(data->g+i, data->n/Dim) ;
      Eigen::Map< const Eigen::VectorXd,
        Eigen::Unaligned,
        Eigen::Stride<0,Dim>
          > x(data->x+i, data->n/Dim) ;
      //std::cout << "X norm is " << x.norm() << std::endl ;

      //Compute function falue
      const Eigen::VectorXd Lx = L_*x ;
      //std::cout << "LX norm is " << Lx.norm() << std::endl ;
      fx += Lx.dot(Lx) ;
      //std::cout << "fx is " << fx << std::endl ;
      //std::cout << "factor is " << factor_ << std::endl ;

      //Compute gradient, normalized by the vertex size
      g.noalias() = g + 2*Dim*factor_*L_.transpose()*Lx/data->n ;
    }

    //Return function value normalized by vertex size
    return Dim*factor_*fx/data->n ;
  }

  private :
  /* indicates whether the provided gradient should be reset to 0 */
  bool reset_gradient_ ;

  /* factor weighting the objective function, initialized to 1 */
  double factor_ ;

  /* Matrix storing the neighbourhoods */
  Eigen::SparseMatrix<double> L_ ;
} ;

} //end of namespace VSDM

} //end of namespace Revoropt

#endif
