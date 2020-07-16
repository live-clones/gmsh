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
#ifndef _REVOROPT_MESH_BASE_FWD_HPP_
#define _REVOROPT_MESH_BASE_FWD_HPP_

#include <Eigen/Dense>

#include <type_traits>

namespace Revoropt {

const int Variable = -1 ;

/***{{{ Forward declarations for friendship ***/
template<
  int _VertexDim = 3,
  typename _Scalar = double,
  int _VertexOffset = 0
>
class ROTriangulationWrapper ;

template<
  int _FaceSize = 3,
  int _VertexDim = 3,
  typename _Scalar = double,
  int _VertexOffset = 0
>
class ROMeshWrapper ;

template<
  int _FaceSize = 3,
  int _VertexDim = 3,
  typename _Scalar = double,
  int _VertexOffset = 0
>
class MeshWrapper ;

template<
  int _FaceSize = 3,
  int _VertexDim = 3,
  typename _Scalar = double
>
class MeshBuilder ;

/*
template<
  int _VertexDim = 3,
  typename _Scalar = double,
  int _VertexOffset = 0
>
class TriangulationWrapper ;
*/

//}}}

/***{{{ Base for all meshes, not for classical use ***/

template<
  int _VertexDim = 3, /* Dimension of the vertices */
  typename _Scalar = double, /* Type of coordinates */
  int _VertexOffset = 0 /* Offset between vertices for easy projection */
>
class ROMeshBase
{

  public:

    friend class ROTriangulationWrapper<_VertexDim,_Scalar,_VertexOffset> ;

    typedef _Scalar Scalar ;

    enum {
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    typedef Eigen::Matrix<Scalar,VertexDim,1> Vector ;

    static const unsigned int NO_NEIGHBOUR ;

    virtual ~ROMeshBase() {} ;

  /** Protected construction this class is only meant to be derived **/
  protected:
    ROMeshBase() :
      vertices_(NULL),
      vertices_size_(0),
      faces_(NULL),
      face_neighbourhoods_(NULL),
      faces_size_(0),
      dirty_(false)
    {}

    ROMeshBase( const Scalar* vertices,
                unsigned int vertices_size,
                const unsigned int* faces,
                const unsigned int* face_neighbourhoods,
                unsigned int faces_size
              ) :
      vertices_(vertices),
      vertices_size_(vertices_size),
      faces_(faces),
      face_neighbourhoods_(face_neighbourhoods),
      faces_size_(faces_size),
      dirty_(false)
    {}

  public:

    /** Vertices **/
    /* coordinate array of a vertex */
    const Scalar* vertex( unsigned int vertex_index ) const {
      return vertices_ + (_VertexDim + _VertexOffset) * vertex_index ;
    }

    /* number of vertices */
    unsigned int vertices_size() const {
      return vertices_size_ ;
    }

    /* vertex access when no offset */
    template< typename T = const Scalar* >
    typename std::enable_if<
      _VertexOffset == 0 && std::is_same<T,const Scalar*>::value,
      T
    >::type vertices() const {
      return vertices_ ;
    }

    /** Data status **/
    bool is_dirty() const { return dirty_ ; }
    void set_dirty() { dirty_ = true ; }
    void set_clean() { dirty_ = false ; }

  protected:

    /** Data pointers **/
    /* Note : these pointers do not really point to const data, and writable
     * meshes cast these to non const data. */

    /* vertex array */
    const Scalar* vertices_ ;

    unsigned int vertices_size_ ;

    /* face array */
    const unsigned int* faces_ ;

    /* face neighbourhoods */
    const unsigned int* face_neighbourhoods_ ;

    unsigned int faces_size_ ;

    /** Notification of data change **/
    bool dirty_ ;

} ;

template<
  int _VertexDim,
  typename _Scalar,
  int _VertexOffset
>
const unsigned int ROMeshBase<_VertexDim, _Scalar, _VertexOffset>::NO_NEIGHBOUR = -1 ;

//}}}

/***{{{ Read only mesh, a mesh that cannot be modified ***/

/*{{{ Default template parameters is triangulated 3D mesh. */

template<
  int _FaceSize = 3, /* Vertices per face, use Variable if non constant */
  int _VertexDim = 3, /* Dimension of the vertices */
  typename _Scalar = double, /* Type of coordinates */
  int _VertexOffset = 0 /* Offset between vertices for easy projection */
>
class ROMesh : public ROMeshBase<_VertexDim,_Scalar,_VertexOffset>
{
  public:

    friend class ROTriangulationWrapper<_VertexDim,_Scalar,_VertexOffset> ;

    template<
      int _OtherSize,
      int _OtherDim,
      typename _OtherScalar,
      int _OtherOffset
    >
    friend class ROMeshWrapper ;

    template<
      int _OtherSize,
      int _OtherDim,
      typename _OtherScalar,
      int _OtherOffset
    >
    friend class MeshWrapper ;

    template<
      int _OtherSize,
      int _OtherDim,
      typename _OtherScalar
    >
    friend class MeshBuilder ;

    typedef ROMeshBase<_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = _FaceSize,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;
    static const unsigned int NO_INDEX = -1 ;

  /** Protected construction this class is only meant to be derived **/
  protected:
    ROMesh() : Base() {}

    ROMesh( const Scalar* vertices,
            unsigned int vertices_size,
            const unsigned int* faces,
            const unsigned int* face_neighbourhoods,
            unsigned int faces_size
          ) : Base( vertices, vertices_size,
                    faces, face_neighbourhoods, faces_size
                  ) {
    }

  public:

    /** Faces **/

    /* vertex arrays of all faces */
    const unsigned int* faces() const {
      return Base::faces_ ;
    }

    /* position of a face in the face array */
    unsigned int face_offset( unsigned int face_index ) const {
      return FaceSize*face_index ;
    }

    /* vertex index array of a face */
    const unsigned int* face( unsigned int face_index ) const {
      return Base::faces_+face_offset(face_index)  ;
    }

    /* number of vertices of a face */
    unsigned int face_size( unsigned int face_index ) const {
      return FaceSize ;
    }

    /* number of faces */
    unsigned int faces_size() const {
      return Base::faces_size_ ;
    }

    /* number of faces */
    unsigned int face_vertices_size() const {
      return FaceSize*Base::faces_size_ ;
    }

    /** Edges **/

    /* vertices of an edge */
    void face_edge_vertices( unsigned int face_index,
                             unsigned int edge,
                             unsigned int* v0,
                             unsigned int* v1
                           ) const {
      //size of the face
      const unsigned int fsize = face_size(face_index) ;
      //face vertices
      const unsigned int* fverts = face(face_index) ;
      //edge vertices
      *v0 = fverts[ edge         ] ;
      *v1 = fverts[(edge+1)%fsize] ;
    }

    unsigned int face_edge_end_vertex( unsigned int face_index,
                                       unsigned int edge
                                     ) const {
      //edge vertices
      return face(face_index)[(edge+1)%face_size(face_index)] ;
    }

    unsigned int face_edge_start_vertex( unsigned int face_index,
                                         unsigned int edge
                                       ) const {
      //face vertices
      const unsigned int* fverts = face(face_index) ;
      return fverts[edge] ;
    }

    /** Neighbourhoods **/

    /* neighbouring face index array of a face */
    /* the neighbouring face of index i is aside the given face along the edge
     * starting at the vertex with index i within the face. */
    const unsigned int* face_neighbours( unsigned int face_index ) const {
      return Base::face_neighbourhoods_ + face_offset(face_index)  ;
    }

    /* index of an edge given by its vertices in a face (NO_INDEX if none) */
    unsigned int edge_face_index( unsigned int face_index,
                                  unsigned int v1,
                                  unsigned int v2
                                ) const ;

} ;

//}}}

/*{{{ Specialization for meshes with irregular face sizes */

template<
  int _VertexDim,
  typename _Scalar,
  int _VertexOffset
>
class ROMesh<Variable,_VertexDim,_Scalar,_VertexOffset> :
  public ROMeshBase<_VertexDim,_Scalar,_VertexOffset>
{
  public:

    friend class ROTriangulationWrapper<_VertexDim,_Scalar,_VertexOffset> ;

    template<
      int _OtherSize,
      int _OtherDim,
      typename _OtherScalar,
      int _OtherOffset
    >
    friend class ROMeshWrapper ;

    template<
      int _OtherSize,
      int _OtherDim,
      typename _OtherScalar,
      int _OtherOffset
    >
    friend class MeshWrapper ;

    template<
      int _OtherSize,
      int _OtherDim,
      typename _OtherScalar
    >
    friend class MeshBuilder ;

    typedef ROMeshBase<_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = Variable,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;
    static const unsigned int NO_INDEX = -1 ;

  /** Protected construction this class is only meant to be derived **/
  protected:
    ROMesh() : Base() {}

    ROMesh( const Scalar* vertices,
            unsigned int vertices_size,
            const unsigned int* faces,
            const unsigned int* face_ends,
            const unsigned int* face_neighbourhoods,
            unsigned int faces_size
          ) : Base( vertices, vertices_size,
                    faces, face_neighbourhoods, faces_size
                  ),
              face_ends_(face_ends) {
    }

  public:

    /** Faces **/

    /* vertex arrays of all faces */
    const unsigned int* faces() const {
      return Base::faces_ ;
    }
    const unsigned int* face_ends() const {
      return face_ends_ ;
    }

    /* position of a face in the face array */
    unsigned int face_offset( unsigned int face_index ) const {
      return face_index == 0 ?
        0 :
        face_ends_[face_index-1]  ;
    }

    /* vertex index array of a face */
    const unsigned int* face( unsigned int face_index ) const {
      return  Base::faces_+face_offset(face_index)  ;
    }

    /* number of vertices of a face */
    unsigned int face_size( unsigned int face_index ) const {
      return face_index == 0 ?
        face_ends_[face_index] :
        face_ends_[face_index] - face_ends_[face_index-1] ;
    }

    /* number of faces */
    unsigned int faces_size() const {
      return Base::faces_size_ ;
    }

    /* number of faces */
    unsigned int face_vertices_size() const {
      return Base::faces_size_ > 0 ?
        face_ends_[Base::faces_size_-1] :
        0 ;
    }

    /** Edges **/

    /* vertices of an edge */
    void face_edge_vertices( unsigned int face_index,
                             unsigned int edge,
                             unsigned int* v0,
                             unsigned int* v1
                           ) const {
      //size of the face
      const unsigned int fsize = face_size(face_index) ;
      //face vertices
      const unsigned int* fverts = face(face_index) ;
      //edge vertices
      *v0 = fverts[ edge         ] ;
      *v1 = fverts[(edge+1)%fsize] ;
    }

    unsigned int face_edge_end_vertex( unsigned int face_index,
                                       unsigned int edge
                                     ) const {
      //size of the face
      const unsigned int fsize = face_size(face_index) ;
      //face vertices
      const unsigned int* fverts = face(face_index) ;
      //edge vertices
      return fverts[(edge+1)%fsize] ;
    }

    unsigned int face_edge_start_vertex( unsigned int face_index,
                                         unsigned int edge
                                       ) const {
      //face vertices
      const unsigned int* fverts = face(face_index) ;
      return fverts[edge] ;
    }

    /** Neighbourhoods **/

    /* neighbouring face index array of a face */
    /* the neighbouring face of index i is aside the given face along the edge
     * starting at the vertex with index i within the face. */
    const unsigned int* face_neighbours( unsigned int face_index ) const {
      return Base::face_neighbourhoods_ + face_offset(face_index) ;
    }

    /* index of an edge given by its vertices in a face (NO_INDEX if none) */
    unsigned int edge_face_index( unsigned int face_index,
                                  unsigned int v1,
                                  unsigned int v2
                                ) const ;

  protected:

    /* face positions in face array, null unless variable case */
    const unsigned int* face_ends_ ;

} ;

//}}}

//}}}

/***{{{ Read Write mesh, allowing the vertices and faces to be modified ***/

/**{{{ Fixed size faces case **/

template<
  int _FaceSize = 3,
  int _VertexDim = 3,
  typename _Scalar = double,
  int _VertexOffset = 0
>
class Mesh : public ROMesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset>
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

  /** Protected construction this class is only meant to be derived **/
  /* Initialization from const is disabled */
  protected:
    Mesh() : Base() {}

    Mesh( Scalar* vertices,
          unsigned int vertices_size,
          unsigned int* faces,
          unsigned int* face_neighbourhoods,
          unsigned int faces_size
        ) : Base( vertices, vertices_size,
                  faces, face_neighbourhoods, faces_size
                ) {
    }

  public:

    /** Vertices **/

    using Base::vertices ;
    /* editable full vertex array when offset is 0 */
    template< typename T = Scalar* >
    typename std::enable_if<
      _VertexOffset == 0 && std::is_same<T,Scalar*>::value,
      T
    >::type vertices() {
      return const_cast<T>(Base::vertices()) ;
    }

    using Base::vertex ;
    /* editable coordinate array of a vertex */
    Scalar* vertex( unsigned int vertex_index ) {
      return const_cast<_Scalar*>(Base::vertex(vertex_index)) ;
    }

    /** Faces **/
    using Base::faces ;
    /* editable faces array */
    unsigned int* faces() {
      return const_cast<unsigned int*>(Base::faces()) ;
    }

    using Base::face ;
    /* editable vertex index array of a face */
    unsigned int* face( unsigned int face_index ) {
      return const_cast<unsigned int*>(Base::face(face_index)) ;
    }

    /** Neighbourhoods **/

    using Base::face_neighbours ;
    /* editable neighbouring face index array of a face */
    unsigned int* face_neighbours( unsigned int face_index ) {
      return const_cast<unsigned int*>(Base::face_neighbours(face_index)) ;
    }
} ;

//}}}

/**{{{ Variable size faces case **/

template<
  int _VertexDim,
  typename _Scalar,
  int _VertexOffset
>
class Mesh<Variable,_VertexDim,_Scalar,_VertexOffset> :
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

  /** Protected construction this class is only meant to be derived **/
  /* Initialization from const is disabled */
  protected:
    Mesh() : Base() {}

    Mesh( Scalar* vertices,
          unsigned int vertices_size,
          unsigned int* faces,
          unsigned int* face_ends,
          unsigned int* face_neighbourhoods,
          unsigned int faces_size
        ) : Base( vertices, vertices_size,
                  faces, face_ends, face_neighbourhoods, faces_size
                ) {
    }

  public:

    /** Vertices **/

    using Base::vertices ;
    /* editable full vertex array when offset is 0 */
    template< typename T = Scalar* >
    typename std::enable_if<
      _VertexOffset == 0 && std::is_same<T,Scalar*>::value,
      T
    >::type vertices() {
      return const_cast<T>(Base::vertices()) ;
    }

    using Base::vertex ;
    /* editable coordinate array of a vertex */
    Scalar* vertex( unsigned int vertex_index ) {
      return const_cast<_Scalar*>(Base::vertex(vertex_index)) ;
    }

    /** Faces **/
    using Base::faces ;
    unsigned int* faces() {
      return const_cast<unsigned int*>(Base::faces()) ;
    }

    using Base::face_ends ;
    unsigned int* face_ends() {
      return const_cast<unsigned int*>(Base::face_ends()) ;
    }

    using Base::face ;

    /* editable vertex index array of a face */
    unsigned int* face( unsigned int face_index ) {
      return const_cast<unsigned int*>(Base::face(face_index)) ;
    }

    /** Neighbourhoods **/

    using Base::face_neighbours ;

    /* editable neighbouring face index array of a face */
    unsigned int* face_neighbours( unsigned int face_index ) {
      return const_cast<unsigned int*>(Base::face_neighbours(face_index)) ;
    }
} ;

//}}}

//}}}

} //end of namespace Revoropt

#endif
