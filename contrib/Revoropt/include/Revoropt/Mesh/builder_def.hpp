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
#ifndef _REVOROPT_MESH_BUILDER_DEF_HPP_
#define _REVOROPT_MESH_BUILDER_DEF_HPP_

#include "builder_fwd.hpp"
#include "connectivity_def.hpp"

namespace Revoropt {

/*** {{{ constant face size case ***/

template< int _FaceSize, int _VertexDim, typename _Scalar >
template< int OtherDim, int OtherOffset >
void MeshBuilder<_FaceSize,_VertexDim,_Scalar>::init( const ROMesh< _FaceSize,
                                                                    OtherDim,
                                                                    _Scalar,
                                                                    OtherOffset
                                                                  >* rhs) {
  //vertex copy
  //automatic projection if dimensions do not match
  if(OtherDim + OtherOffset == VertexDim) {
    //linear copy
    v_vector_.assign( rhs->vertices(),
                      rhs->vertices()+VertexDim*rhs->vertices_size()
                    ) ;
    //reset vertex pointer and size
    Base::vertices_ = v_vector_.data() ;
    Base::vertices_size_ = rhs->vertices_size() ;
  } else {
    //number of coordinates that can be copied
    const int copy_size = std::min((int)VertexDim,OtherDim+OtherOffset) ;
    //resize vertex vector
    v_vector_.resize(VertexDim*rhs->vertices_size()) ;
    //reset vertex pointer and size
    Base::vertices_ = v_vector_.data() ;
    Base::vertices_size_ = rhs->vertices_size() ;
    for(unsigned int vertex = 0; vertex < rhs->vertices_size(); ++vertex) {
      //copy vertex positions
      std::copy( rhs->vertex(vertex), 
                 rhs->vertex(vertex)+copy_size,
                 Base::vertex(vertex)
               ) ;
      //add zeros if necessary
      std::fill( Base::vertex(vertex)+copy_size, 
                 Base::vertex(vertex)+VertexDim,
                 0
               ) ;
    }
  }
  //face copy
  f_vector_.assign(rhs->faces(),rhs->faces() + rhs->face_vertices_size()) ;
  //reset face pointer and size
  Base::faces_ = f_vector_.data() ;
  Base::faces_size_ = rhs->faces_size() ;
  //recompute neighbourhoods
  c_computer_.compute_connectivity() ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
}

template< int FaceSize, int VertexDim, typename Scalar >
unsigned int MeshBuilder<FaceSize,VertexDim,Scalar>::push_vertices( 
  const Scalar* vertices, unsigned int size
) {
  //resize the vertex container
  const unsigned int start = v_vector_.size() ;
  v_vector_.resize(start + VertexDim*size) ;
  //copy he provided vertices
  std::copy(vertices, vertices+VertexDim*size, v_vector_.begin() + start) ;
  //update pointer and size
  Base::vertices_ = v_vector_.data() ;
  Base::vertices_size_ += size ;
  Base::set_dirty() ;
  //return a pointer to the first vertex pushed
  return start/VertexDim ;
}

template< int FaceSize, int VertexDim, typename Scalar >
unsigned int MeshBuilder<FaceSize,VertexDim,Scalar>::extend_vertices( 
  unsigned int size
) {
  //resize the vertex container
  const unsigned int start = v_vector_.size() ;
  v_vector_.resize(start + VertexDim*size) ;
  //update pointer and size
  Base::vertices_ = v_vector_.data() ;
  Base::vertices_size_ += size ;
  Base::set_dirty() ;
  //return a pointer to the first vertex pushed
  return start/VertexDim ;
}

template< int FaceSize, int VertexDim, typename Scalar >
void MeshBuilder<FaceSize,VertexDim,Scalar>::erase_vertices( unsigned int start,
                                                             unsigned int end
                                                           ) {
  if(end > start) {
    v_vector_.erase( v_vector_.begin() + VertexDim*start,
                     v_vector_.begin() + VertexDim*end
                   ) ;
    Base::vertices_ = v_vector_.data() ;
    Base::vertices_size_ -= end - start ;
    Base::set_dirty() ;
  }
}

template< int FaceSize, int VertexDim, typename Scalar >
unsigned int MeshBuilder<FaceSize,VertexDim,Scalar>::push_faces( 
  const unsigned int* faces, unsigned int size
) {
  //starting index of the new faces
  const unsigned int start = Base::faces_size_ ;
  //original face vertices size
  const unsigned int fv_start = FaceSize*start ;
  //append the faces
  f_vector_.resize(fv_start + FaceSize*size) ;
  std::copy(faces, faces + FaceSize*size, f_vector_.begin() + fv_start) ;
  //reset face pointer and size
  Base::faces_ = f_vector_.data() ;
  Base::faces_size_ += size ;
  //glue the new faces
  c_computer_.resize(fv_start + FaceSize*size) ;
  glue_faces(start,start+size) ;
  Base::set_dirty() ;
  //return pointer to the first face added
  return start ;
}

template< int _FaceSize, int _VertexDim, typename _Scalar >
unsigned int MeshBuilder<_FaceSize,_VertexDim,_Scalar>::extend_faces( 
  unsigned int size, unsigned int fsize
) {
  assert( (fsize == FaceSize) && 
          "Trying to extend a fixed face size mesh "
           "with a face of the wrong size."
        ) ;
  //starting index of the new faces
  const unsigned int start = f_vector_.size() ;
  //append the faces
  f_vector_.resize(start + FaceSize*size) ;
  //reset face pointer and size
  Base::faces_ = f_vector_.data() ;
  Base::faces_size_ += size ;
  //extend neighbourhoods for the new faces
  c_computer_.resize(start + FaceSize*size) ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
  //return pointer to the first face added
  return start/FaceSize ;
}

template< int _FaceSize, int _VertexDim, typename _Scalar >
void MeshBuilder<_FaceSize,_VertexDim,_Scalar>::erase_faces( unsigned int start,
                                                             unsigned int end
                                                           ) {
  if(end > start) {
    c_computer_.erase_neighbourhoods(start,end) ;
    Base::face_neighbourhoods_ = c_computer_.data() ;
    f_vector_.erase( f_vector_.begin() + FaceSize*start,
                     f_vector_.begin() + FaceSize*end
                   ) ;
    Base::faces_ = f_vector_.data() ;
    Base::faces_size_ -= end - start ;
    Base::set_dirty() ;
  }
}

//}}}

/*** {{{ variable face size case ***/

template< int _VertexDim, typename _Scalar >
template< int OtherDim, int OtherOffset >
void MeshBuilder<Variable,_VertexDim,_Scalar>::init( const ROMesh< Variable,
                                                                   OtherDim,
                                                                   _Scalar,
                                                                   OtherOffset
                                                                 >* rhs) {
  //vertex copy
  //automatic projection if dimensions do not match
  if(OtherDim + OtherOffset == VertexDim) {
    //linear copy
    v_vector_.assign( rhs->vertices(),
                      rhs->vertices() + VertexDim*rhs->vertices_size()) ;
    //reset vertex pointer and size
    Base::vertices_ = v_vector_.data() ;
    Base::vertices_size_ = rhs->vertices_size() ;
  } else {
    //number of coordinates that can be copied
    const int copy_size = std::min((int)VertexDim,OtherDim+OtherOffset) ;
    //resize vertex vector
    v_vector_.resize(VertexDim*rhs->vertices_size()) ;
    //reset vertex pointer and size
    Base::vertices_ = v_vector_.data() ;
    Base::vertices_size_ = rhs->vertices_size() ;
    for(unsigned int vertex = 0; vertex < rhs->vertices_size(); ++vertex) {
      Scalar* v = Base::vertex(vertex) ;
      //copy vertex positions
      std::copy( rhs->vertex(vertex), 
                 rhs->vertex(vertex)+copy_size,
                 v
               ) ;
      //add zeros if necessary
      std::fill( v+copy_size, 
                 v+VertexDim,
                 0
               ) ;
    }
  }
  //face copy
  f_vector_.assign(rhs->faces_,rhs->faces_ + rhs->face_vertices_size()) ;
  fe_vector_.assign(rhs->face_ends_,rhs->face_ends_ + rhs->faces_size_) ;
  //reset face pointer and size
  Base::faces_ = f_vector_.data() ;
  Base::face_ends_ = fe_vector_.data() ;
  Base::faces_size_ = rhs->faces_size_ ;
  //recompute neighbourhoods
  c_computer_.compute_connectivity() ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
}

template< int _VertexDim, typename _Scalar >
unsigned int MeshBuilder<Variable,_VertexDim,_Scalar>::push_vertices( 
  const Scalar* vertices, unsigned int size
) {
  //resize the vertex container
  const unsigned int start = v_vector_.size() ;
  v_vector_.resize(start + VertexDim*size) ;
  //copy he provided vertices
  std::copy(vertices, vertices+VertexDim*size, v_vector_.begin() + start) ;
  //update pointer and size
  Base::vertices_ = v_vector_.data() ;
  Base::vertices_size_ += size ;
  Base::set_dirty() ;
  //return a pointer to the first vertex pushed
  return start/VertexDim ;
}

template< int _VertexDim, typename _Scalar >
unsigned int MeshBuilder<Variable,_VertexDim,_Scalar>::extend_vertices( 
  unsigned int size
) {
  //resize the vertex container
  const unsigned int start = v_vector_.size() ;
  v_vector_.resize(start + VertexDim*size) ;
  //update pointer and size
  Base::vertices_ = v_vector_.data() ;
  Base::vertices_size_ += size ;
  Base::set_dirty() ;
  //return a pointer to the first vertex pushed
  return start/VertexDim ;
}

template< int _VertexDim, typename _Scalar >
void MeshBuilder<Variable,_VertexDim,_Scalar>::erase_vertices( 
  unsigned int start, unsigned int end
) {
  if(end > start) {
    v_vector_.erase( v_vector_.begin() + VertexDim*start,
                     v_vector_.begin() + VertexDim*end
                   ) ;
    Base::vertices_ = v_vector_.data() ;
    Base::vertices_size_ -= end - start ;
    Base::set_dirty() ;
  }
}

template< int _VertexDim, typename _Scalar >
unsigned int MeshBuilder<Variable,_VertexDim,_Scalar>::push_faces( 
  const unsigned int* faces, const unsigned int* face_ends, unsigned int size
) {
  //starting index of the new faces
  const unsigned int f_start = f_vector_.size() ;
  const unsigned int fe_start = fe_vector_.size() ;
  //number of vertex indices to add to the faces
  const unsigned int fv_size = face_ends[size-1] ;
  //append the faces and face_ends
  f_vector_.resize(f_start + fv_size) ;
  fe_vector_.resize(fe_start + size) ;
  std::copy(faces, faces + fv_size, f_vector_.begin() + f_start) ;
  std::copy(face_ends, face_ends + size, fe_vector_.begin() + fe_start) ;
  //shift the face ends to account for the previous faces of the mesh
  for(unsigned int f = fe_start; f < fe_start + size; ++f) {
    fe_vector_[f] += f_start ;
  }
  //reset face pointers and size
  Base::faces_ = f_vector_.data() ;
  Base::face_ends_ = fe_vector_.data() ;
  Base::faces_size_ += size ;
  //glue the new faces
  c_computer_.resize(f_start + fv_size) ;
  glue_faces(fe_start,fe_start+size) ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
  //return the index of the first face
  return fe_start ;
}

template< int _VertexDim, typename _Scalar >
unsigned int MeshBuilder<Variable,_VertexDim,_Scalar>::extend_faces( 
  unsigned int size, unsigned int face_size
) {
  //starting index of the new faces
  const unsigned int f_start = f_vector_.size() ;
  const unsigned int fe_start = fe_vector_.size() ;
  //append the faces and face_ends
  f_vector_.resize(f_start + size*face_size) ;
  fe_vector_.resize(fe_start + size) ;
  //set the face ends of the new faces
  for(unsigned int face = fe_start; face < fe_vector_.size(); ++face) {
    fe_vector_[face] = face==0 ? face_size : fe_vector_[face-1]+face_size ;
    ;
  }
  //reset face pointers and size
  Base::faces_ = f_vector_.data() ;
  Base::face_ends_ = fe_vector_.data() ;
  Base::faces_size_ += size ;
  //allocate neighbours for the new faces
  c_computer_.resize(f_start + size*face_size) ;
  Base::face_neighbourhoods_ = c_computer_.data() ;
  Base::set_dirty() ;
  //return the index of the first face
  return fe_start ;
}

template< int _VertexDim, typename _Scalar >
void MeshBuilder<Variable,_VertexDim,_Scalar>::erase_faces( unsigned int start, 
                                                            unsigned int end
                                                          ) {
  if(end > start) {
    //update neighbourhoods
    c_computer_.erase_neighbourhoods(start,end) ;
    Base::face_neighbourhoods_ = c_computer_.data() ;
    //number of face vertices to remove
    const unsigned int fv_start = Base::face_offset(start) ;
    const unsigned int fv_end = end < Base::faces_size_ ?
      Base::face_offset(end) :
      Base::face_vertices_size()
    ;
    //remove faces and face_ends
    f_vector_.erase( f_vector_.begin() + fv_start,
                     f_vector_.begin() + fv_end
                   ) ;
    fe_vector_.erase( fe_vector_.begin() + start,
                      fe_vector_.begin() + end
                    ) ;
    //shift the face_ends after the end
    const unsigned int offset = fv_end - fv_start ;
    for(unsigned int f = start; f < fe_vector_.size(); ++f) {
      fe_vector_[f] -= offset ;
    }
    Base::faces_ = f_vector_.data() ;
    Base::face_ends_ = fe_vector_.data() ;
    Base::faces_size_ -= end - start ;
    Base::set_dirty() ;
  }
}

//}}}

} //end of namespace Revoropt

#endif
