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
#ifndef _REVOROPT_CVT_MINIMIZER_H_
#define _REVOROPT_CVT_MINIMIZER_H_

#include "computer.hpp"

#include <Revoropt/RVD/rvd.hpp>
#include <Revoropt/Mesh/wrapper_def.hpp>

namespace Revoropt {
namespace CVT {

/* Minimization of the direct CVT objective function */

template<typename _Mesh>
class DirectObjFun {

  public :
  //typedefs and template information
  typedef _Mesh Mesh ;
  typedef typename Mesh::Scalar Scalar ;
  enum { Dim = Mesh::VertexDim } ;
  typedef ROTriangulationWrapper<
    Dim, 
    typename Mesh::Scalar, 
    Mesh::VertexOffset
  > Triangulation ;

  /* Initialization */

  DirectObjFun( bool reset_gradient = true ) :
    reset_gradient_(reset_gradient) {
  }

  void set_vertices( const Scalar* vertices, unsigned int vertices_size ) {
    triangulation_.set_vertices(vertices, vertices_size) ;
    rvd_.set_mesh(&triangulation_) ;
    computer_.set_mesh(&triangulation_) ;
  }

  void set_mesh( const Mesh* mesh ) {
    triangulation_.wrap(mesh) ;
    rvd_.set_mesh(&triangulation_) ;
    computer_.set_mesh(&triangulation_) ;
  }

  void set_sites(const double* sites, unsigned int sites_size ) {
    sites_ = sites ;
    sites_size_ = sites_size ;
    set_inner_sites(sites, sites_size) ;
  }

  /* Computing the gradient and value of the CVT objective function with respect
   * to the site positions */
  
  /* given the mesh and the set of sites */

  double operator() ( 
                      const Mesh* mesh,
                      const double* sites, 
                      unsigned int site_size,
                      double* grad
                    ) {
    set_mesh(mesh) ;
    set_sites(sites, site_size) ;

    return operator()(grad) ;
  }

  /* using the sites and mesh provided using set_mesh and set_sites */

  double operator() ( double* grad ) {
    if(reset_gradient_) {
      std::fill(grad, grad+Dim*sites_size_,0) ;
    }
    computer_.set_g(grad) ;
    computer_.set_fx(0) ;

    rvd_.compute(computer_) ;

    return computer_.get_fx() ;
  }

  /* Solver callback, using the provided variables as site positions */
  template<typename Data>
  double operator()( Data* data ) {
    set_inner_sites(data->x, data->n/Dim) ;
    return operator()(data->g) ;
  }

  /* Parameters */

  void set_factor( double factor ) {
    computer_.set_factor(factor) ;
  }
  void set_anisotropy( double anisotropy ) {
    computer_.set_anisotropy(anisotropy) ;
  }
  void set_border_anisotropy( double border_anisotropy ) {
    computer_.set_border_anisotropy(border_anisotropy) ;
  }
  void set_tolerance( double tolerance ) {
    computer_.set_tolerance(tolerance) ;
  }
  void set_border_weight( double border_weight ) {
    computer_.set_border_weight(border_weight) ;
  }
  void set_triangle_weights( const double* triangle_weights) {
    computer_.set_triangle_weights(triangle_weights) ;
  }

  protected :

  void set_inner_sites( const double* sites, unsigned int sites_size ) {
    rvd_.set_sites(sites, sites_size) ;
    computer_.set_sites(sites) ;
  }

  //sites
  const double* sites_ ;
  unsigned int sites_size_ ;

  //objective function computation
  DirectComputer<Triangulation> computer_ ;
  bool reset_gradient_ ;

  //Restricted Voronoï diagram
  RVD<Triangulation> rvd_ ;

  //Triangulation wrapper
  Triangulation triangulation_ ;

} ;

template<typename _Mesh>
class DirectMinimizer : public DirectObjFun<_Mesh> {

  public :
    enum { Dim = _Mesh::VertexDim } ;

    DirectMinimizer() : DirectObjFun<_Mesh>(true) {}
  
    void set_sites(double* sites, unsigned int sites_size ) {
      var_sites_ = sites ;
      DirectObjFun<_Mesh>::set_sites(sites, sites_size) ;
    }

    /* minimization */
    template<typename Solver>
    int minimize( unsigned int iterations ) {
      Solver solver ;
      return solver.solve(var_sites_, Dim*sites_size_, this, iterations) ;
    }

    template<typename Solver, typename IterCallback>
    int minimize( unsigned int iterations, IterCallback* iter_callback ) {
      Solver solver ;
      return solver.solve(var_sites_, Dim*sites_size_, this, iterations, iter_callback) ;
    }

  private :

    using DirectObjFun<_Mesh>::sites_size_ ;
    double* var_sites_ ;
} ;

/* LBFGS callback for the minimization of the inverse CVT objective function */

template<typename _Mesh>
class InverseObjFun {

  public :
  //typedefs and template information
  typedef _Mesh Mesh ;
  enum { Dim = Mesh::VertexDim } ;
  typedef typename Mesh::Scalar Scalar ;
  typedef ROTriangulationWrapper<
    Dim, 
    typename Mesh::Scalar, 
    Mesh::VertexOffset
  > Triangulation ;

  /* Initialization */

  InverseObjFun( bool reset_gradient = true ) : 
    reset_gradient_(reset_gradient) {
  }

  void set_vertices( const Scalar* vertices, unsigned int vertices_size ) {
    triangulation_.set_vertices(vertices, vertices_size) ;
    rvd_.set_mesh(&triangulation_) ;
    computer_.set_mesh(&triangulation_) ;
  }

  void set_mesh( Mesh* mesh ) {
    triangulation_.wrap(mesh) ;
    rvd_.set_mesh(&triangulation_) ;
    computer_.set_mesh(&triangulation_) ;
  }

  void set_sites( const Scalar* sites, unsigned int sites_size ) {
    rvd_.set_sites(sites, sites_size) ;
    computer_.set_sites(sites) ;
  }

  /* Computing the gradient and value of the CVT objective function with respect
   * to the mesh vertex positions */
  
  /* given the mesh and the set of sites */

  double operator() ( 
                      const Mesh* mesh,
                      const Scalar* sites, 
                      unsigned int site_size,
                      double* grad
                    ) {
    set_mesh(mesh) ;
    set_sites(sites, site_size) ;

    return operator()(grad) ;
  }

  /* using the sites and mesh provided using set_mesh, set_sites or set_rvd */

  double operator() ( double* grad ) {
    if(reset_gradient_) {
      std::fill(grad, grad+Dim*rvd_.mesh()->vertices_size(),0) ;
    }
    computer_.set_g(grad) ;
    computer_.set_fx(0) ;

    rvd_.compute(computer_) ;

    return computer_.get_fx() ;
  }

  /* Solver callback using the provided variables as mesh vertex positions */                  
  template<typename Data>
  double operator()( Data* data ) {
    set_vertices(data->x, data->n/Dim) ;
    return operator()(data->g) ;
  }

  /* Parameters */

  void set_factor( double factor ) {
    computer_.set_factor(factor) ;
  }
  void set_anisotropy( double anisotropy ) {
    computer_.set_anisotropy(anisotropy) ;
  }
  void set_border_anisotropy( double border_anisotropy ) {
    computer_.set_border_anisotropy(border_anisotropy) ;
  }
  void set_tolerance( double tolerance ) {
    computer_.set_tolerance(tolerance) ;
  }
  void set_border_weight( double border_weight ) {
    computer_.set_border_weight(border_weight) ;
  }
  void set_triangle_weights( const double* triangle_weights) {
    computer_.set_triangle_weights(triangle_weights) ;
  }

  private :

  //triangulation wrapper
  Triangulation triangulation_ ;

  //objective function computation
  InverseComputer<Triangulation> computer_ ;
  bool reset_gradient_ ;

  //restricted Voronoï diagram
  RVD<Triangulation> rvd_ ;

} ;

} //end of namespace CVT
} //end of namespace Revoropt

#endif

