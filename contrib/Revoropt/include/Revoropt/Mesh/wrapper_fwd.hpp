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
#ifndef _REVOROPT_MESH_WRAPPER_H_
#define _REVOROPT_MESH_WRAPPER_H_

#include "base_fwd.hpp"
#include "connectivity_fwd.hpp"

namespace Revoropt {

/*** Read only wrapper, to build a Read only mesh from given pointers ***/

/** Fixed face size case **/

template<
  int _FaceSize, 
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class ROMeshWrapper : public ROMesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset>
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
    ROMeshWrapper() : Base() {} ;

    /*  From raw arrays */
    ROMeshWrapper( const Scalar* vertices, 
                   unsigned int vertices_size,
                   const unsigned int* faces,
                   const unsigned int* face_neighbourhoods,
                   unsigned int faces_size
                 ) : Base( vertices, vertices_size, 
                           faces, face_neighbourhoods, faces_size
                         ) {
    };

    /*  From a set of vertices and the faces/neighbourhoods of another mesh */
    template<int _OtherDim, int _OtherOffset>
    ROMeshWrapper( const Scalar* vertices, 
                   unsigned int vertices_size,
                   const ROMesh< _FaceSize,
                                 _OtherDim,
                                 _Scalar,
                                 _OtherOffset
                               >* combinatorics
                 ) : Base( vertices, vertices_size, 
                           combinatorics->faces_, 
                           combinatorics->face_neighbourhoods_, 
                           combinatorics->faces_size_
                         ) {
    } ;

    /*  From another mesh */
    template<int _OtherDim, int _OtherOffset>
    ROMeshWrapper( const ROMesh< _FaceSize,
                                 _OtherDim,
                                 _Scalar,
                                 _OtherOffset
                             >* rhs
                 ) : Base( rhs->vertices_, rhs->vertices_size_,
                           rhs->faces_, 
                           rhs->face_neighbourhoods_, 
                           rhs->faces_size_
                         ) {
    } ;

    /** Changing pointers **/
    /* All pointers */
    template<int _OtherDim, int _OtherOffset>
    ROMeshWrapper& operator=( const ROMesh< FaceSize,
                                            _OtherDim,
                                            Scalar,
                                            _OtherOffset
                                            >& rhs ) { 
      wrap(&rhs) ;
      return *this ;
    }

    template<int _OtherDim, int _OtherOffset>
    void wrap( const ROMesh< FaceSize,
                             _OtherDim,
                             Scalar,
                             _OtherOffset
                             >* rhs ) {
      Base::vertices_ = 
        const_cast<_Scalar*>(rhs->vertices_) ;
      Base::vertices_size_ = 
        rhs->vertices_size_ ;
      Base::faces_ = 
        const_cast<unsigned int*>(rhs->faces_) ;
      Base::face_neighbourhoods_ = 
        const_cast<unsigned int*>(rhs->face_neighbourhoods_) ;
      Base::faces_size_ = 
        rhs->faces_size_ ;
      Base::set_dirty() ;
    }

    /* Vertex pointer */
    void set_vertices( const Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = const_cast<_Scalar*>(vertices) ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /* Face pointers */
    void set_faces( const unsigned int* faces,
                    const unsigned int* face_neighbourhoods,
                    unsigned int faces_size
                  ) {
      Base::faces_ = const_cast<unsigned int*>(faces) ;
      Base::face_neighbourhoods_ = const_cast<unsigned int*>(face_neighbourhoods) ;
      Base::faces_size_ = faces_size ;
      Base::set_dirty() ;
    }


} ;

/** Variable face size case **/

template<
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class ROMeshWrapper<Variable, _VertexDim, _Scalar, _VertexOffset> : 
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
    ROMeshWrapper() : Base() {} ;

    /*  From raw arrays */
    ROMeshWrapper( const Scalar* vertices, 
                   unsigned int vertices_size,
                   const unsigned int* faces,
                   const unsigned int* face_ends,
                   const unsigned int* face_neighbourhoods,
                   unsigned int faces_size
                 ) : Base( vertices, vertices_size, 
                           faces, face_ends, face_neighbourhoods, faces_size
                         ) {
    };

    /*  From a set of vertices and the faces/neighbourhoods of another mesh */
    template<int _OtherDim, int _OtherOffset>
    ROMeshWrapper( const Scalar* vertices, 
                   unsigned int vertices_size,
                   const ROMesh< Variable,
                                 _OtherDim,
                                 Scalar,
                                 _OtherOffset
                               >* combinatorics
                 ) : Base( vertices, vertices_size, 
                           combinatorics->faces_, 
                           combinatorics->face_ends_, 
                           combinatorics->face_neighbourhoods_, 
                           combinatorics->faces_size_
                         ) {
    } ;

    /*  From another mesh */
    template<int _OtherDim, int _OtherOffset>
    ROMeshWrapper( const ROMesh< Variable,
                                 _OtherDim,
                                 Scalar,
                                 _OtherOffset
                             >* rhs
                 ) : Base( rhs->vertices_, rhs->vertices_size_,
                           rhs->faces_, 
                           rhs->face_ends_,
                           rhs->face_neighbourhoods_, 
                           rhs->faces_size_
                         ) {
    } ;

    /** Changing pointers **/
    /* All pointers */
    template<int _OtherDim, int _OtherOffset>
    ROMeshWrapper& operator=( const ROMesh< Variable,
                                            _OtherDim,
                                            Scalar,
                                            _OtherOffset
                                            >& rhs ) { 
      wrap(&rhs) ;
      return *this ;
    }

    template<int _OtherDim, int _OtherOffset>
    void wrap( const ROMesh< Variable,
                             _OtherDim,
                             Scalar,
                             _OtherOffset
                             >* rhs ) {
      Base::vertices_ = 
        const_cast<_Scalar*>(rhs->vertices_) ;
      Base::vertices_size_ = 
        rhs->vertices_size_ ;
      Base::faces_ = 
        const_cast<unsigned int*>(rhs->faces_) ;
      Base::face_ends_ = 
        const_cast<unsigned int*>(rhs->face_ends_) ;
      Base::face_neighbourhoods_ = 
        const_cast<unsigned int*>(rhs->face_neighbourhoods_) ;
      Base::faces_size_ = 
        rhs->faces_size_ ;
      Base::set_dirty() ;
    }

    /* Vertex pointer */
    void set_vertices( const Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = const_cast<_Scalar*>(vertices) ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /* Face pointers */
    void set_faces( const unsigned int* faces,
                    const unsigned int* face_neighbourhoods,
                    const unsigned int* face_ends,
                    unsigned int faces_size
                  ) {
      Base::faces_ = const_cast<unsigned int*>(faces) ;
      Base::face_ends_ = const_cast<unsigned int*>(face_ends) ;
      Base::face_neighbourhoods_ = const_cast<unsigned int*>(face_neighbourhoods) ;
      Base::faces_size_ = faces_size ;
      Base::set_dirty() ;
    }


} ;

/*** Read write wrapper, to build a Read write mesh from given pointers ***/
/* Note, this is not a subclass of ROMeshWrapper, since the set_{vertices|faces} 
 * methods would allow setting the pointers of a RWMeshWrapper from const data.
 * */

/** Fixed face size case **/

template<
  int _FaceSize, 
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class MeshWrapper : public Mesh<_FaceSize,_VertexDim,_Scalar,_VertexOffset>
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
    MeshWrapper() : Base() {} ;

    /*  From raw arrays */
    MeshWrapper( Scalar* vertices, 
                 unsigned int vertices_size,
                 unsigned int* faces,
                 unsigned int* face_neighbourhoods,
                 unsigned int faces_size
               ) : Base( vertices, vertices_size, 
                         faces, face_neighbourhoods, faces_size
                       ) {
    };

    /*  From a set of vertices and the faces/neighbourhoods of another mesh */
    template<int _OtherDim, int _OtherOffset>
    MeshWrapper( Scalar* vertices, 
                 unsigned int vertices_size,
                 Mesh< _FaceSize,
                       _OtherDim,
                       _Scalar,
                       _OtherOffset
                     >* combinatorics
               ) : Base( vertices, vertices_size, 
                         combinatorics->faces_, 
                         combinatorics->face_neighbourhoods_, 
                         combinatorics->faces_size_
                       ) {
    } ;

    /*  From another mesh */
    template<int _OtherDim, int _OtherOffset>
    MeshWrapper( Mesh< _FaceSize,
                       _OtherDim,
                       _Scalar,
                       _OtherOffset
                   >* rhs
               ) : Base( rhs->vertices_, rhs->vertices_size_,
                           rhs->faces_, 
                           rhs->face_neighbourhoods_, 
                           rhs->faces_size_
                         ) {
    } ;

    /** Changing pointers **/
    template<int _OtherDim, int _OtherOffset>
    MeshWrapper& operator=( Mesh< FaceSize,
                                  _OtherDim,
                                  Scalar,
                                  _OtherOffset
                                  >& rhs ) { 
      wrap(&rhs) ;
      return *this ;
    }

    /* All pointers */
    template<int _OtherDim, int _OtherOffset>
    void wrap( Mesh< FaceSize,
                     _OtherDim,
                     Scalar,
                     _OtherOffset
                     >* rhs ) {
      Base::vertices_ = rhs->vertices_ ;
      Base::vertices_size_ = rhs->vertices_size_ ;
      Base::faces_ = rhs->faces_  ;
      Base::face_neighbourhoods_ = rhs->face_neighbourhoods_ ;
      Base::faces_size_ = rhs->faces_size_ ;
      Base::set_dirty() ;
    }

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
                    unsigned int* face_neighbourhoods,
                    unsigned int faces_size
                  ) {
      Base::faces_ = faces ;
      Base::face_neighbourhoods_ = face_neighbourhoods ;
      Base::faces_size_ = faces_size ;
      Base::set_dirty() ;
    }


} ;

/** Variable face size case **/

template<
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class MeshWrapper<Variable, _VertexDim, _Scalar, _VertexOffset> : 
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
    MeshWrapper() : Base() {} ;

    /*  From raw arrays */
    MeshWrapper( Scalar* vertices, 
                 unsigned int vertices_size,
                 unsigned int* faces,
                 unsigned int* face_ends,
                 unsigned int* face_neighbourhoods,
                 unsigned int faces_size
               ) : Base( vertices, vertices_size, 
                         faces, face_ends, face_neighbourhoods, faces_size
                       ) {
    };

    /*  From a set of vertices and the faces/neighbourhoods of another mesh */
    template<int _OtherDim, int _OtherOffset>
    MeshWrapper( Scalar* vertices, 
                 unsigned int vertices_size,
                 Mesh< Variable,
                       _OtherDim,
                       Scalar,
                       _OtherOffset
                     >* combinatorics
               ) : Base( vertices, vertices_size, 
                         combinatorics->faces_, 
                         combinatorics->face_ends_, 
                         combinatorics->face_neighbourhoods_, 
                         combinatorics->faces_size_
                       ) {
    } ;

    /*  From another mesh */
    template<int _OtherDim, int _OtherOffset>
    MeshWrapper( Mesh< Variable,
                       _OtherDim,
                       _Scalar,
                       _OtherOffset
                   >* rhs
               ) : Base( rhs->vertices_, rhs->vertices_size_,
                           rhs->faces_, 
                           rhs->face_ends_, 
                           rhs->face_neighbourhoods_, 
                           rhs->faces_size_
                         ) {
    } ;

    /** Changing pointers **/
    /* All pointers */
    template<int _OtherDim, int _OtherOffset>
    MeshWrapper& operator=( Mesh< Variable,
                                  _OtherDim,
                                  Scalar,
                                  _OtherOffset
                                  >& rhs ) { 
      wrap(&rhs) ;
      return *this ;
    }

    template<int _OtherDim, int _OtherOffset>
    void wrap( Mesh< Variable,
                     _OtherDim,
                     Scalar,
                     _OtherOffset
                     >* rhs ) {
      Base::vertices_ = rhs->vertices_ ;
      Base::vertices_size_ = rhs->vertices_size_ ;
      Base::faces_ = rhs->faces_  ;
      Base::face_ends_ = rhs->face_ends_  ;
      Base::face_neighbourhoods_ = rhs->face_neighbourhoods_ ;
      Base::faces_size_ = rhs->faces_size_ ;
      Base::set_dirty() ;
    }

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
                    unsigned int* face_neighbourhoods,
                    unsigned int* face_ends,
                    unsigned int faces_size
                  ) {
      Base::faces_ = faces ;
      Base::face_ends_ = face_ends ;
      Base::face_neighbourhoods_ = face_neighbourhoods ;
      Base::faces_size_ = faces_size ;
      Base::set_dirty() ;
    }


} ;

/*** Triangulation wrapper, triangulating a mesh ***/

template<
  int _VertexDim, 
  typename _Scalar, 
  int _VertexOffset
>
class ROTriangulationWrapper : 
  public ROMesh<3,_VertexDim,_Scalar,_VertexOffset>
{
  public:
  
    typedef ROMesh<3,_VertexDim,_Scalar,_VertexOffset> Base ;

    typedef _Scalar Scalar ;

    enum {
      FaceSize = 3,
      VertexDim = _VertexDim,
      VertexOffset = _VertexOffset
    } ;

    using Base::NO_NEIGHBOUR ;

    /** Construction **/
    ROTriangulationWrapper() : Base(), c_computer_(this) {}

    /*  Wrap other meshes */

    template <int _FaceSize>
    ROTriangulationWrapper( const ROMesh<_FaceSize,
                                         VertexDim,
                                         Scalar,
                                         VertexOffset
                                        >* mesh
                          ) : Base( mesh->vertices_, mesh->vertices_size_, 
                                    NULL, NULL, 0
                                  ),
                              c_computer_(this) {
      set_faces(mesh->faces_, _FaceSize, mesh->faces_size_) ;
    } ;

    ROTriangulationWrapper( const ROMesh<3,
                                         VertexDim,
                                         Scalar,
                                         VertexOffset
                                        >* mesh
                             ) : Base( mesh->vertices_, mesh->vertices_size_, 
                                       mesh->faces_, mesh->face_neighbourhoods_,
                                       mesh->faces_size_
                                     ),
                                 c_computer_() {
    } ;

    ROTriangulationWrapper( const ROMesh<Variable,
                                         VertexDim,
                                         Scalar,
                                         VertexOffset
                                        >* mesh
                          ) : Base( mesh->vertices_, mesh->vertices_size_, 
                                    NULL, NULL, 0
                                  ),
                              c_computer_(this) {

      set_faces(mesh->faces_, mesh->face_ends_, mesh->faces_size_) ;
    } ;



    /** Changing pointers **/
    template <int _FaceSize>
    void wrap( 
        const ROMesh<_FaceSize, VertexDim, Scalar, VertexOffset>* mesh
        ) {
      Base::vertices_ = mesh->vertices_ ;
      Base::vertices_size_ = mesh->vertices_size_ ;
      set_faces(mesh->faces, _FaceSize, mesh->faces_size_) ;
    }

    void wrap( 
        const ROMesh<Variable, VertexDim, Scalar, VertexOffset>* mesh
        ) {
      Base::vertices_ = mesh->vertices_ ;
      Base::vertices_size_ = mesh->vertices_size_ ;
      set_faces(mesh->faces_, mesh->face_ends_, mesh->faces_size_) ;
    }

    void wrap( 
        const ROMesh<3, VertexDim, Scalar, VertexOffset>* mesh
        ) {
      Base::vertices_ = mesh->vertices_ ;
      Base::vertices_size_ = mesh->vertices_size_ ;
      Base::faces_ = mesh->faces_ ;
      Base::face_neighbourhoods_ = mesh->face_neighbourhoods_ ;
      Base::faces_size_ = mesh->faces_size_ ;
    }

    /* Vertex pointer */
    void set_vertices( const Scalar* vertices, 
                       unsigned int vertices_size
                     ) {
      Base::vertices_ = vertices ;
      Base::vertices_size_ = vertices_size ;
      Base::set_dirty() ;
    }

    /** Provide new base faces for the triangles **/

    /* Fixed sized faces */
    void set_faces( const unsigned int* faces,
                    unsigned int face_size,
                    unsigned int faces_size
                  ) ;

    /* Variable sized faces */
    void set_faces( const unsigned int* faces,
                    const unsigned int* face_ends,
                    unsigned int faces_size
                  ) ;

    /* Access the triangles array */
    const unsigned int* triangles() const {
      if(Base::faces_size_ != 0 && triangles_.size() == 0) {
        return Base::faces() ;
      } else {
        return triangles_.data() ;
      }
    }

  private:

    /* Naïvely split a polygon into triangles */
    void split_polygon( const unsigned int* polygon_vertices, 
                        unsigned int polygon_size
                      ) ;

    /* Triangles */
    std::vector<unsigned int> triangles_ ;

    /* Neighbourhoods */
    ConnectivityComputer<Base> c_computer_ ;
} ;

} //end of namespace Revoropt

#endif
