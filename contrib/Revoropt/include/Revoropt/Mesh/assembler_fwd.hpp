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
#ifndef _REVOROPT_MESH_ASSEMBLER_H_
#define _REVOROPT_MESH_ASSEMBLER_H_

#include "base_def.hpp"
#include "connectivity_def.hpp"

namespace Revoropt {

/*** Mesh assembler, computes and internally holds face neighbourhoods ***/

/** Read only version **/

/** Fixed face size case **/

template<
  int _FaceSize = 3, 
  int _VertexDim = 3, 
  typename _Scalar = double, 
  int _VertexOffset = 0
>
class ROMeshAssembler : 
  public ROMesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset>
{
  public:
  
    typedef ROMesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = _FaceSize,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    ROMeshAssembler() : Base(), c_computer_(this) {} ;

    /*  From raw arrays */

    ROMeshAssembler( const Scalar* vertices, 
                     unsigned int vertices_size,
                     const unsigned int* faces,
                     unsigned int faces_size
                   ) : Base( vertices, vertices_size, 
                             faces, NULL, faces_size
                           ),
                       c_computer_(this) {
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
    };

    /** Changing pointers **/

    /* Vertex pointer */
    void set_vertices( const Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = vertices ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /* Face pointers */
    void set_faces( const unsigned int* faces,
                    unsigned int faces_size
                  ) {
      Base::faces_ = faces ;
      Base::faces_size_ = faces_size ;
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }
  private:

    ConnectivityComputer<Base> c_computer_ ;

} ;

/** Variable face size case **/

template<
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class ROMeshAssembler<Variable,_VertexDim,_Scalar,_VertexOffset> : 
  public ROMesh<Variable,_VertexDim,_Scalar,_VertexOffset>
{
  public:
  
    typedef ROMesh<Variable,_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = Variable,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    ROMeshAssembler() : Base(), c_computer_(this) {} ;

    /*  From raw arrays */

    ROMeshAssembler( const Scalar* vertices, 
                     unsigned int vertices_size,
                     const unsigned int* faces,
                     const unsigned int* face_ends,
                     unsigned int faces_size
                   ) : Base( vertices, vertices_size, 
                             faces, face_ends, NULL, faces_size
                           ),
                       c_computer_(this) {
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
    };

    /** Changing pointers **/

    /* Vertex pointer */
    void set_vertices( const Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = vertices ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /* Face pointers */
    void set_faces( const unsigned int* faces,
                    const unsigned int* face_ends,
                    unsigned int faces_size
                  ) {
      Base::faces_ = faces ;
      Base::face_ends_ = face_ends ;
      Base::faces_size_ = faces_size ;
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }
  private:

    ConnectivityComputer<Base> c_computer_ ;

} ;

/** Read write version **/

/** Fixed face size case **/

template<
  int _FaceSize = 3, 
  int _VertexDim = 3, 
  typename _Scalar = double, 
  int _VertexOffset = 0
>
class MeshAssembler : public Mesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset>
{
  public:
  
    typedef Mesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = _FaceSize,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    MeshAssembler() : Base(), c_computer_(this) {} ;

    /*  From raw arrays */

    MeshAssembler( Scalar* vertices, 
                   unsigned int vertices_size,
                   unsigned int* faces,
                   unsigned int faces_size
                 ) : Base( vertices, vertices_size, 
                           faces, NULL, faces_size
                         ),
                     c_computer_(this) {
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
    };

    /** Changing pointers **/

    /* Vertex pointer */
    void set_vertices( Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = vertices ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /* Face pointers */
    void set_faces( unsigned int* faces,
                    unsigned int faces_size
                  ) {
      Base::faces_ = faces ;
      Base::faces_size_ = faces_size ;
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }
  private:

    ConnectivityComputer<Base> c_computer_ ;

} ;

/** Variable face size case **/

template<
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class MeshAssembler<Variable,_VertexDim,_Scalar,_VertexOffset> : 
  public Mesh<Variable,_VertexDim,_Scalar,_VertexOffset>
{
  public:
  
    typedef Mesh<Variable,_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = Variable,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    MeshAssembler() : Base(), c_computer_(this) {} ;

    /*  From raw arrays */
    MeshAssembler( Scalar* vertices, 
                   unsigned int vertices_size,
                   unsigned int* faces,
                   unsigned int* face_ends,
                   unsigned int faces_size
                 ) : Base( vertices, vertices_size, 
                           faces, face_ends, NULL, faces_size
                         ),
                     c_computer_(this) {
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
    };

    /** Changing pointers **/

    /* Vertex pointer */
    void set_vertices( Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = vertices ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /* Face pointers */
    void set_faces( unsigned int* faces,
                    unsigned int* face_ends,
                    unsigned int faces_size
                  ) {
      Base::faces_ = faces ;
      Base::face_ends_ = face_ends ;
      Base::faces_size_ = faces_size ;
      c_computer_.compute_connectivity() ;
      Base::face_neighbourhoods_ = c_computer_.data() ;
      Base::set_dirty() ;
    }
  private:

    ConnectivityComputer<Base> c_computer_ ;

} ;

} //end of namespace Revoropt

#endif
