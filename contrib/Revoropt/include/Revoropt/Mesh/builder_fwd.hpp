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
#ifndef _REVOROPT_MESH_BUILDER_H_
#define _REVOROPT_MESH_BUILDER_H_

#include "base_fwd.hpp"
#include "connectivity_fwd.hpp"

namespace Revoropt {

/*** Mesh builder, managing the vertices and faces arrays ***/

/** Fixed face size case **/

template<
  int _FaceSize, 
  int _VertexDim, 
  typename _Scalar 
>
class MeshBuilder : public Mesh<_FaceSize,_VertexDim,_Scalar,0>
{
  public:
  
    typedef Mesh<_FaceSize,_VertexDim,_Scalar,0> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = _FaceSize,
      VertexDim = _VertexDim
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    MeshBuilder() : Base(), c_computer_(this) {} ;

    void clear() {
      //vertices
      v_vector_.resize(0) ;
      Base::vertices_size_ = 0 ;
      Base::vertices_ = NULL ;
      f_vector_.resize(0) ;
      Base::faces_size_ = 0 ;
      Base::faces_ = NULL ;
      Base::face_neighbourhoods_ = NULL ;
      Base::set_dirty() ;
    }

    /* init from another mesh */
    template<int _OtherDim, int _OtherOffset>
    void init( const ROMesh< _FaceSize,
                             _OtherDim,
                             _Scalar,
                             _OtherOffset
                           >* rhs
             ) ;

    template<int _OtherDim, int _OtherOffset>
    void operator=( const ROMesh< _FaceSize,
                                  _OtherDim,
                                  _Scalar,
                                  _OtherOffset
                                >& rhs
                  ) {
      init(&rhs) ;
      Base::set_dirty() ;
    }

    /** Edition **/


    /* Adding vertices, returns the index of the first vertex */
    unsigned int push_vertices( const Scalar* vertices, unsigned int size ) ;

    unsigned int push_vertex( const Scalar* vertex ) {
      return push_vertices(vertex,1) ;
    }

    /* Adding unitialized vertices */
    unsigned int extend_vertices( unsigned int size ) ;

    /* Removing vertices */
    void erase_vertices( unsigned int start, unsigned int end ) ;

    /* Adding faces, returns the index of the first face added */
    unsigned int push_faces( const unsigned int* faces, unsigned int size ) ;


    unsigned int push_face( const unsigned int* face, unsigned int size = 3 ) {
      assert(size == 3 && "trying to push a face with wrong size.") ;
      return push_face(face,1) ;
    }

    /* Adding unitialized faces */
    //second argument is provided for compatibility with the variable face
    //size case, and should always be the face size of the mesh
    unsigned int extend_faces( unsigned int size, 
                               unsigned int fsize = FaceSize //compatibility
                             ) ;

    /* Removing faces */
    void erase_faces( unsigned int start, unsigned int end ) ;

    /* Connecting faces (connecting twice leads to inconsistancy) */

    void glue_faces( unsigned int start, unsigned int end ) {
      c_computer_.glue_faces(start,end) ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }

    void glue_face( unsigned int face ) {
      glue_faces(face, face+1) ;
    }

    /* Disconnecting faces (disconnecting twice leads to inconsistancy) */

    void unglue_faces( unsigned int start, unsigned int end ) {
      c_computer_.unglue_faces(start,end) ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }

    void unglue_face( unsigned int face ) {
      unglue_faces(face, face+1) ;
    }

    /* Swaps */
    void swap( MeshBuilder& rhs ) {
      std::swap(Base::vertices_, rhs.vertices_) ;
      std::swap(Base::vertices_size_, rhs.vertices_size_) ;
      v_vector_.swap(rhs.v_vector_) ;
      std::swap(Base::faces_, rhs.faces_) ;
      std::swap(Base::face_neighbourhoods_, rhs.face_neighbourhoods_) ;
      std::swap(Base::faces_size_, rhs.faces_size_) ;
      f_vector_.swap(rhs.f_vector_) ;
      c_computer_.swap(rhs.c_computer_) ;
      Base::set_dirty() ;
    }

    void swap_vertices( std::vector<Scalar>& other  ) {
      unsigned int size = other.size() / VertexDim ;
      v_vector_.swap(other) ;
      Base::vertices_ = v_vector_.data() ;
      Base::vertices_size_ = size ;
      Base::set_dirty() ;
    }

    void swap_faces( std::vector<unsigned int>& other  ) {
      unsigned int size = other.size() / FaceSize ;
      f_vector_.swap(other) ;
      Base::faces_ = f_vector_.data() ;
      Base::faces_size_ = size ;
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }

  private:

  /* Vertices */
  std::vector<Scalar> v_vector_ ;

  /* Faces */
  std::vector<unsigned int> f_vector_ ;

  /* Neighbourhoods */
  ConnectivityComputer<Base> c_computer_ ;

} ;

/** Variable face size case **/

template<
  int _VertexDim,
  typename _Scalar
>
class MeshBuilder<Variable,_VertexDim,_Scalar> : 
  public Mesh<Variable,_VertexDim,_Scalar,0>
{
  public:
  
    typedef Mesh<Variable,_VertexDim,_Scalar,0> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = Variable,
      VertexDim = _VertexDim
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    MeshBuilder() : Base(), c_computer_(this) {} ;

    void clear() {
      //vertices
      v_vector_.resize(0) ;
      Base::vertices_size_ = 0 ;
      Base::vertices_ = NULL ;
      f_vector_.resize(0) ;
      fe_vector_.resize(0) ;
      Base::faces_size_ = 0 ;
      Base::faces_ = NULL ;
      Base::face_neighbourhoods_ = NULL ;
      Base::face_ends_ = NULL ;
      Base::set_dirty() ;
    }

    /* init from another mesh */
    template<int _OtherDim, int _OtherOffset>
    void init( const ROMesh< Variable,
                             _OtherDim,
                             Scalar,
                             _OtherOffset
                           >* rhs
             ) ;

    template<int _OtherDim, int _OtherOffset>
    void operator=( const ROMesh< Variable,
                                  _OtherDim,
                                  _Scalar,
                                  _OtherOffset
                                >& rhs
                  ) {
      init(&rhs) ;
      Base::set_dirty() ;
    }

    /** Edition **/

    /* Adding vertices, returns the index of the first vertex */
    unsigned int push_vertices( const Scalar* vertices, unsigned int size ) ;

    unsigned int push_vertex( const Scalar* vertex ) {
      return push_vertices(vertex,1) ;
    }

    /* Adding unitialized vertices */
    unsigned int extend_vertices( unsigned int size ) ;

    /* Removing vertices */
    void erase_vertices( unsigned int start, unsigned int end ) ;

    /* Adding faces, returns the index of the first face created */
    unsigned int push_faces( const unsigned int* faces, 
                             const unsigned int* face_ends,
                             unsigned int size 
                           ) ;

    unsigned int push_face( const unsigned int* face, unsigned int face_size ) {
      return push_faces(face,&face_size,1) ;
    }

    /* Adding unitialized faces, all the faces must have the same size */
    unsigned int extend_faces( unsigned int size, unsigned int face_size ) ;

    /* Removing faces */
    void erase_faces( unsigned int start, unsigned int end ) ;

    /* Connecting faces (connecting twice leads to inconsistancy) */

    void glue_faces( unsigned int start, unsigned int end ) {
      c_computer_.glue_faces(start,end) ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }

    void glue_face( unsigned int face ) {
      glue_faces(face, face+1) ;
    }

    /* Disconnecting faces (disconnecting twice leads to inconsistancy) */

    void unglue_faces( unsigned int start, unsigned int end ) {
      c_computer_.unglue_faces(start,end) ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }

    void unglue_face( unsigned int face ) {
      unglue_faces(face, face+1) ;
    }

    /* Swaps */
    void swap( MeshBuilder& rhs ) {
      std::swap(Base::vertices_, rhs.vertices_) ;
      std::swap(Base::vertices_size_, rhs.vertices_size_) ;
      v_vector_.swap(rhs.v_vector_) ;
      std::swap(Base::faces_, rhs.faces_) ;
      std::swap(Base::face_ends_, rhs.face_ends_) ;
      std::swap(Base::face_neighbourhoods_, rhs.face_neighbourhoods_) ;
      std::swap(Base::faces_size_, rhs.faces_size_) ;
      f_vector_.swap(rhs.f_vector_) ;
      fe_vector_.swap(rhs.fe_vector_) ;
      c_computer_.swap(rhs.c_computer_) ;
      Base::set_dirty() ;
    }

    void swap_vertices( std::vector<Scalar>& other  ) {
      unsigned int size = other.size() / VertexDim ;
      v_vector_.swap(other) ;
      Base::vertices_ = v_vector_.data() ;
      Base::vertices_size_ = size ;
      Base::set_dirty() ;
    }

    void swap_faces( std::vector<unsigned int>& other_faces,
                     std::vector<unsigned int>& other_face_ends
                   ) {
      unsigned int size = other_face_ends.size() ;
      f_vector_.swap(other_faces) ;
      fe_vector_.swap(other_face_ends) ;
      Base::faces_ = f_vector_.data() ;
      Base::face_ends_ = fe_vector_.data() ;
      Base::faces_size_ = size ;
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }

  private:

  /* Vertices */
  std::vector<Scalar> v_vector_ ;

  /* Faces */
  std::vector<unsigned int> f_vector_ ;
  std::vector<unsigned int> fe_vector_ ;

  /* Neighbourhoods */
  ConnectivityComputer<Base> c_computer_ ;

} ;

} //end of namespace Revoropt

#endif
