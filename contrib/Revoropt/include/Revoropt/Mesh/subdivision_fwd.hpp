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
#ifndef _REVOROPT_MESH_SUBDIVISION_FWD_HPP_
#define _REVOROPT_MESH_SUBDIVISION_FWD_HPP_

#include "base_def.hpp"

#include <Eigen/Dense>
#include <ostream>
#include <iostream>

namespace Revoropt {

namespace Subdivision {

template<typename Scalar>
class Contribution {
  public :
    /* Data */
    unsigned int index ;
    Scalar factor ;

    /* Construction */
    Contribution() {}

    Contribution(unsigned int _index) :
      index(_index), factor(1) {}

    Contribution(unsigned int _index, Scalar _factor) :
      index(_index), factor(_factor) {}

    /* Operations */
    Contribution operator*( Scalar rhs ) const {
      return Contribution(index, factor*rhs) ;
    }
    Contribution& operator*=( Scalar rhs ) {
      factor *= rhs ;
      return *this ;
    }
    Contribution operator+( const Contribution& rhs ) const {
      return Contribution(index, factor + rhs.factor) ;
    }
    Contribution& operator+=( const Contribution& rhs ) {
      factor += rhs.factor ;
      return *this ;
    }
} ;

template<typename Scalar, typename OtherScalar = Scalar>
Contribution<Scalar> operator*(OtherScalar lhs, const Contribution<Scalar>& rhs) {
  return rhs*((Scalar) lhs) ;
}

template<typename Scalar>
class Stencil {
  public :
    /* Construction */
    Stencil() {}

    Stencil(const Contribution<Scalar>& contrib) {
      contributions_.push_back(contrib) ;
    }

    Stencil( unsigned int index ) {
      contributions_.push_back(index) ;
    }

    void normalize() {
      Scalar sum = 0 ;
      for(unsigned int i = 0; i < size(); ++i) {
        sum += contributions_[i].factor ;
      }
      for(unsigned int i = 0; i < size(); ++i) {
        contributions_[i].factor /= sum ;
      }
    }

    /* Access */
    Contribution<Scalar>& operator[](unsigned int i) {
      return contributions_[i] ;
    }

    const Contribution<Scalar>& operator[](unsigned int i) const {
      return contributions_[i] ;
    }

    unsigned int size() const {
      return contributions_.size() ;
    }

    /* Operations */
    Stencil operator*( Scalar rhs ) const {
      Stencil res ;
      res.contributions_.reserve(size()) ;
      for(unsigned int i = 0; i < size(); ++i) {
        res.contributions_.push_back((*this)[i] * rhs) ;
      }
      return res ;
    }

    Stencil& operator*=( Scalar rhs ) {
      *this = *this * rhs ;
      return *this ;
    }

    Stencil operator+( const Stencil& rhs ) const ;

    Stencil& operator+=(const Stencil& rhs) {
      *this = *this + rhs ;
      return *this ;
    }

    Stencil compose( const Stencil* stencils ) const {
      Stencil res ;
      for(unsigned int i = 0; i < size(); ++i) {
        res += stencils[contributions_[i].index] * contributions_[i].factor ;
      }
      return res ;
    }

  private :
    /* Data */
    std::vector< Contribution<Scalar> > contributions_ ;
} ;

template<typename Scalar, typename OtherScalar = Scalar>
Stencil<Scalar> operator*(OtherScalar lhs, const Stencil<Scalar>& rhs) {
  return rhs*((Scalar) lhs) ;
}

template<typename Scalar>
std::ostream& operator<<(std::ostream& stream, const Stencil<Scalar>& rhs) {
  stream << "[ " ;
  for(unsigned int i = 0; i < rhs.size(); ++i) {
    stream << rhs[i].index << "(" << rhs[i].factor << ") " ;
  }
  stream << "]" ;
  return stream ;
}

} //end of namespace Subdivision

template<
  int _VertexDim = 3,
  typename _Scalar = double
>
class CatmullClark : public ROMesh<4, _VertexDim, _Scalar, 0>
{
  public :

    /* Typedefs */
    typedef ROMesh<4, _VertexDim, _Scalar, 0> Base ;
    typedef _Scalar Scalar ;
    enum {
      FaceSize = 4,
      VertexDim = _VertexDim
    } ;

    /* Construction */
    CatmullClark() : Base() {}

    template<typename Mesh>
    CatmullClark( const Mesh* mesh ) : Base() {
      subdivide(mesh) ;
    }

    /* Access */
    const unsigned int* face_patches() {
      return face_patches_.data() ;
    }

    /* Tools */
    void set_vertices(
        const Scalar* ctrl_vertices,
        unsigned int ctrl_vertices_size = 0 //for compatibility
        ) {
      ctrl_vertices_ = ctrl_vertices ;
      update() ;
      Base::set_dirty() ;
    }

    void update() ;

    template<typename Mesh>
    void subdivide( const Mesh* mesh ) ;

    void subdivide() {
      return subdivide(this) ;
    }

  private :

    /* Control Vertices */
    const Scalar* ctrl_vertices_ ;

    /* Subdivided vertices and faces */
    std::vector<Scalar> vertices_ ;
    std::vector<unsigned int> faces_ ;
    std::vector<unsigned int> face_neighbourhoods_ ;
    std::vector<unsigned int> face_patches_ ;

    /* Stencils */
    std::vector< Subdivision::Stencil<Scalar> > stencils_ ;
} ;

} //end of namespace Revoropt

#endif
