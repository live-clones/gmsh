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
#ifndef _REVOROPT_VSDM_MINIMIZER_HPP_
#define _REVOROPT_VSDM_MINIMIZER_HPP_

#include "regul.hpp"
#include "sampler.hpp"

#include <Revoropt/RVD/rvd.hpp>
#include <Revoropt/CVT/minimizer.hpp>
#include <Revoropt/Mesh/base_def.hpp>
#include <Revoropt/Mesh/wrapper_def.hpp>

#include <vector>

namespace Revoropt {

namespace VSDM {

enum SamplerSetting {
  SAMPLER_NONE,
  SAMPLER_MIDFACE
} ;

enum DiffSamplerSetting {
  DIFF_SAMPLER_NONE,
  DIFF_SAMPLER_MIDFACE
} ;

template< typename TMesh, typename SMesh>
class ObjFun {

  public :
  
  enum {Dim = TMesh::VertexDim} ;
  typedef ROMeshWrapper<
      SMesh::FaceSize, 
      SMesh::VertexDim,
      typename SMesh::Scalar,
      SMesh::VertexOffset
    > SMeshWrapper ;

  ObjFun( 
      bool reset_gradient = true
      ) :
    direct_obj_fun_(false),
    inverse_obj_fun_(false),
    regul_obj_fun_(false),
    target_sampler_(NULL),
    source_sampler_(NULL),
    global_factor_(1),
    direct_factor_(1),
    inverse_factor_(0),
    regul_factor_(1),
    reset_gradient_(reset_gradient) 
  {}

  ~ObjFun() {
    delete target_sampler_ ;
    delete source_sampler_ ;
  }

  /* Callback to compute the objective function */

  template< typename Data >
  double operator()( Data* data ) {
    if(reset_gradient_) {
      std::fill(data->g, data->g+data->n,0) ;
    }

    double fx = 0 ;
    if(global_factor_ > 0) {
      if(inverse_factor_ > 0) {
        fx += compute_inverse_CVT(data) ;
      }
      if(regul_factor_ > 0) {
        fx += compute_regul(data) ;
      }
      if(direct_factor_ > 0) {
        fx += compute_direct_CVT(data) ;
      }
    }
    return fx ;
  }

  /* Weighting the terms of the objective function */

  void set_global_factor( double factor ) {
    global_factor_ = factor ;
  }
  void set_direct_factor( double factor ) {
    direct_factor_ = factor ;
  }
  void set_inverse_factor( double factor ) {
    inverse_factor_ = factor ;
  }
  void set_regul_factor( double factor ) {
    regul_factor_ = factor ;
  }

  /* Mesh setting */

  void set_target(const TMesh* mesh) {
    target_mesh_ = mesh ;
    direct_obj_fun_.set_mesh(target_mesh_) ;
    if(target_sampler_) {
      target_sampler_->set_mesh(target_mesh_) ;
      inverse_obj_fun_.set_sites(
          target_sampler_->samples(), 
          target_sampler_->sample_size()
      ) ;
    } else {
      inverse_obj_fun_.set_sites(
          target_mesh_->vertices(), 
          target_mesh_->vertices_size()
      ) ;
    }
  }

  void set_source(SMesh* mesh) {
    source_mesh_.wrap(mesh) ;
    variables_ = mesh->vertices() ;
    variables_size_ = Dim * mesh->vertices_size() ;
    if(source_sampler_) {
      source_sampler_->set_mesh(&source_mesh_) ;
    }
    regul_obj_fun_.build_matrix(&source_mesh_) ;
  }

  /* CVT parameters */

  //FIXME
  ////TODO handle inverse anisotropy
  //void set_anisotropy( double anisotropy ) ;
  ////TODO use a separate edge RVD on edge meshes for boundary fitting
  //void set_border_weight( double border_weight ) ;

  /* Sampler setting */

  void set_target_sampler( SamplerSetting sampler_type ) {
    //cleanup previous sampler
    delete target_sampler_ ;

    switch(sampler_type){
      case SAMPLER_NONE: 
        {
          //none defaults to vertex sampling, which is specially treated
          target_sampler_ = NULL ;
          break ;
        }
      case SAMPLER_MIDFACE: 
        {
          //one sample per face center
          target_sampler_ = new MidFaceSampler<TMesh> ;
          break ;
        }
    }

    if(target_sampler_ && target_mesh_) {
      target_sampler_->set_mesh(target_mesh_) ;
    }
  }

  void set_source_sampler( DiffSamplerSetting diff_sampler_type ) {
    //cleanup previous sampler
    delete source_sampler_ ;

    switch(diff_sampler_type){
      case DIFF_SAMPLER_NONE: 
        {
          //none defaults to vertex sampling, which is specially treated
          source_sampler_ = NULL ;
          break ;
        }
      case DIFF_SAMPLER_MIDFACE: 
        {
          //one sample per face center
          source_sampler_ = new MidFaceSampler<SMeshWrapper> ;
          break ;
        }
    }

    if(source_sampler_) {
      source_sampler_->set_mesh(&source_mesh_) ;
    }
  }

  /* minimization */
  template<typename Solver>
  int minimize( unsigned int iterations ) {
    Solver solver ;
    return solver.solve(variables_, variables_size_, this, iterations) ;
  }

  template<typename Solver, typename IterCallback>
  int minimize( unsigned int iterations, IterCallback* iter_callback ) {
    Solver solver ;
    return solver.solve(variables_, variables_size_, this, iterations, iter_callback) ;
  }

  private :

  /*Computing the different terms */
  template<typename Data>
  double compute_direct_CVT( Data* data ) {
    direct_obj_fun_.set_factor(global_factor_*direct_factor_) ;
    if(!source_sampler_) {
      //no sampling, use default behaviour
      direct_obj_fun_.set_sites(data->x, data->n/Dim) ;
      return direct_obj_fun_(data->g) ;
    } else {
      //a sampler is used
      source_mesh_.set_vertices(data->x, data->n/Dim) ;
      source_sampler_->set_mesh(&source_mesh_) ;
      //reset the gradient wrt the samples
      source_sample_grad_.assign(Dim*source_sampler_->sample_size(), 0) ;
      //compute the gradient and value wrt. the samples
      direct_obj_fun_.set_sites(
          source_sampler_->samples(), 
          source_sampler_->sample_size()
          ) ;
      double fx = direct_obj_fun_( 
          source_sample_grad_.data()
          ) ;
      //chain to the gradient wrt. the template mesh vertices
      source_sampler_->chain_derivative( 
          source_sample_grad_.data(),
          data->g,
          false
          ) ;
      //return function value
      return fx ;
    }
  }
  
  template<typename Data>
  double compute_inverse_CVT( Data* data ) {
    inverse_obj_fun_.set_factor(global_factor_*inverse_factor_) ;
    source_mesh_.set_vertices(data->x, data->n/Dim) ;
    inverse_obj_fun_.set_mesh(&source_mesh_) ;
    return inverse_obj_fun_(data->g) ;
  }
  
  template<typename Data>
  double compute_regul( Data* data ) {
    regul_obj_fun_.set_factor(global_factor_*regul_factor_) ;
    return regul_obj_fun_(data) ;
  }

  /* Meshes */
  const TMesh* target_mesh_ ;
  SMeshWrapper source_mesh_ ;

  /* Variables */
  double* variables_ ;
  unsigned int variables_size_ ;

  /* Objective functions */
  CVT::DirectObjFun<TMesh> direct_obj_fun_ ;
  CVT::InverseObjFun<SMeshWrapper> inverse_obj_fun_ ;
  RegulTerm<Dim> regul_obj_fun_ ;
  
  /* Samplers */
  Sampler<TMesh>* target_sampler_ ;
  DiffSampler<SMeshWrapper>* source_sampler_ ;
  std::vector<double> source_sample_grad_ ;

  /* Parameters */
  double global_factor_ ;
  double direct_factor_ ;
  double inverse_factor_ ;
  double regul_factor_ ;

  bool reset_gradient_ ;

} ;

} //end of namespace VSDM

} //end of namespace Revoropt

#endif
