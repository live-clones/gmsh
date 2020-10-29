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
#ifndef _REVOROPT_VSDM_SAMPLER_H_
#define _REVOROPT_VSDM_SAMPLER_H_

#include <Eigen/Sparse>
#include <vector>

namespace Revoropt {

namespace VSDM {

/** Generic sampler classes **/

/* Sample a mesh */

template<typename Mesh>
class Sampler {

  public :

  virtual ~Sampler() {}

  /** Typedefs **/
  typedef typename Mesh::Scalar Scalar ;
  enum { Dim = Mesh::VertexDim } ;

  /** Construction **/

  /* Set the mesh to sample */
  virtual void set_mesh( const Mesh* mesh ) = 0 ;

  /** Access **/

  /* Provides the sample points. If no mesh was set, returns NULL */
  const double* samples() const { return samples_.data() ; }
  double* samples() { return samples_.data() ; }
  unsigned int sample_size() const { return samples_.size()/Dim ; }

  protected :

  /* Samples */
  std::vector<double> samples_ ;

} ;

/* Sample and compute the derivatives of the samples wrt. the mesh vertices */

template<typename Mesh>
class DiffSampler : public Sampler<Mesh> {

  protected :

  typedef Sampler<Mesh> Base ;
  using Base::Scalar ;
  using Base::Dim ;
  using Base::samples_ ;

  public :

  using Base::samples ;
  using Base::sample_size ;

  virtual ~DiffSampler() {}

  /** Differenciation **/

  /* Transfer a derivative wrt the samples to a derivative wrt. the vertices */

  virtual void chain_derivative(
      const double* sample_derivative,
      double* vertex_derivative,
      bool reset_output = true
      ) const = 0 ;

} ;

/* Linearly sample a mesh */

template<typename Mesh>
class LinearSampler : public DiffSampler<Mesh> {

  protected :

  typedef DiffSampler<Mesh> Base ;
  using Base::Scalar ;
  using Base::Dim ;
  using Base::samples_ ;

  public :

  using Base::samples ;
  using Base::sample_size ;

  virtual ~LinearSampler() {}

  virtual void set_mesh( const Mesh* mesh ) {
    //map the sample coordinates in a sample_size_ x 3 matrix
    Eigen::Map< Eigen::Matrix<double,Eigen::Dynamic,Dim>,
                Eigen::Unaligned,
                Eigen::Stride<1,Dim>
              > sample_coord(samples(), sample_size(), Dim) ;

    //map the mesh vertex coordinates in a vertex_size x 3 matrix
    Eigen::Map< const Eigen::Matrix<double,Eigen::Dynamic,Dim>,
                Eigen::Unaligned,
                Eigen::Stride<1,Dim>
              > vertex_coord(mesh->vertices(), mesh->vertices_size(), Dim) ;

    //apply linear combinations
    sample_coord = S_*vertex_coord ;
  }

  /** Differenciation **/

  void chain_derivative(
      const double* sample_derivative,
      double* vertex_derivative,
      bool reset_output = true
      ) const {
    //map the sample coordinates in a sample_size_ x 3 matrix
    Eigen::Map<
        const Eigen::Matrix<double,Eigen::Dynamic,Dim>,
        Eigen::Unaligned,
        Eigen::Stride<1,Dim>
      > sdiff(sample_derivative, sample_size(), Dim) ;

    //map the mesh vertex coordinates in a vertex_size x 3 matrix
    Eigen::Map<
        Eigen::Matrix<double,Eigen::Dynamic,Dim>,
        Eigen::Unaligned,
        Eigen::Stride<1,Dim>
      > vdiff(vertex_derivative, S_.cols(), Dim) ;

    //apply linear combinations backwards
    if(reset_output) {
      vdiff = S_.transpose()*sdiff ;
    } else {
      vdiff.noalias() = vdiff + S_.transpose()*sdiff ;
    }
  }


  protected :

  /* Linear coefficients are stored as a sparse matrix */
  Eigen::SparseMatrix<double> S_ ;

} ;

/** Some particular samplers **/

/* Vertex sampler */

template<typename Mesh>
class VertexSampler : public DiffSampler<Mesh> {

  protected :

  typedef DiffSampler<Mesh> Base ;
  using Base::Scalar ;
  using Base::Dim ;
  using Base::samples_ ;

  public :

  using Base::samples ;
  using Base::sample_size ;

  virtual ~VertexSampler() {}

  /* set the mesh to sample */
  void set_mesh( const Mesh* mesh ) {
    samples_.assign(
        mesh->vertices(),
        mesh->vertices() + Dim * mesh->vertices_size()
        ) ;
  }

  /** Differenciation **/

  void chain_derivative( const double* sample_derivative,
                         double* vertex_derivative,
                         bool reset_output = true
                       ) const {
    std::copy(
        sample_derivative,
        sample_derivative + Dim * sample_size(),
        vertex_derivative
        ) ;
  }

} ;

/* Mid face sampler : one sample per face, at the centroid */

template<typename Mesh>
class MidFaceSampler : public LinearSampler<Mesh> {

  protected :

  typedef LinearSampler<Mesh> Base ;
  using Base::Scalar ;
  using Base::Dim ;
  using Base::samples_ ;
  using Base::S_ ;

  public :

  using Base::samples ;
  using Base::sample_size ;

  virtual ~MidFaceSampler() {}

  /* set the mesh to sample */
  void set_mesh( const Mesh* mesh ) {
    //the number of samples is the number of faces
    samples_.resize(Dim * mesh->faces_size()) ;

    //generate the matrix with the linear combinations
    std::vector< Eigen::Triplet<double> > triplets ;
    //each sample linearly depends at least on three vertices
    triplets.reserve(3*sample_size()) ;

    //generate the coeffs per face/sample
    for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
      //size of the face
      const unsigned int fsize = mesh->face_size(f) ;
      //recover the vertices of the face
      const unsigned int* fverts = mesh->face(f) ;
      //barycentric coeff for this face
      const double coeff = 1./fsize ;
      //buid one coeff per vertex
      for(unsigned int v = 0; v < fsize; ++v) {
        triplets.push_back(
            Eigen::Triplet<double>(f,fverts[v],coeff)
            ) ;
      }
    }

    //assemble the matrix from the triplets
    S_.resize(sample_size(),mesh->vertices_size()) ;
    S_.setFromTriplets(triplets.begin(), triplets.end()) ;

    //call parent method
    Base::set_mesh(mesh) ;
  }

} ;

} //end of namespace VSDM

} //end of namespace Revoropt

#endif
