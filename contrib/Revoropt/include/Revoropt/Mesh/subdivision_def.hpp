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
#ifndef _REVOROPT_MESH_SUBDIVISION_DEF_HPP_
#define _REVOROPT_MESH_SUBDIVISION_DEF_HPP_

#include "subdivision_fwd.hpp"

namespace Revoropt {

namespace Subdivision {

template<typename Scalar>
Stencil<Scalar> Stencil<Scalar>::operator+( const Stencil& rhs ) const {
  //result
  Stencil res ;

  //iterator on each stencil
  unsigned int pos1 = 0 ;
  unsigned int pos2 = 0 ;

  //fusion
  while(pos1 != size() && pos2 != rhs.size()) {
    if((*this)[pos1].index < rhs[pos2].index) {
      res.contributions_.push_back((*this)[pos1]) ;
      ++pos1 ;
    } else if(contributions_[pos1].index > rhs[pos2].index) {
      res.contributions_.push_back(rhs[pos2]) ;
      ++pos2 ;
    } else {
      res.contributions_.push_back((*this)[pos1] + rhs[pos2]) ;
      ++pos1 ;
      ++pos2 ;
    }
  }

  //handle remaining contributions
  if(pos1 == size()) {
    res.contributions_.insert(
        res.contributions_.end(),
        rhs.contributions_.begin() + pos2, 
        rhs.contributions_.end()
        ) ;
  } else {
    res.contributions_.insert(
        res.contributions_.end(),
        contributions_.begin() + pos1, 
        contributions_.end() 
        ) ;
  }

  //finalize
  return res ;
}

} //end of namespace Subdivision

template<
  int _VertexDim,
  typename _Scalar
>
void CatmullClark<_VertexDim, _Scalar>::update() {
  //vector type
  typedef Eigen::Matrix<Scalar,VertexDim,1> Vector ;

  vertices_.reserve(VertexDim*stencils_.size()) ;
  vertices_.resize(VertexDim*stencils_.size()) ;

  for(unsigned int i = 0; i < stencils_.size(); ++i) {
    //vertex to update
    Eigen::Map<Vector> x(vertices_.data() + VertexDim*i) ;
    x = Vector::Zero() ;

    //apply the vertex stencil
    const Subdivision::Stencil<Scalar>& stencil = stencils_[i] ;
    for(unsigned int j = 0; j < stencil.size(); ++j) {
      //control vertex
      unsigned int index = stencil[j].index ;
      Scalar factor = stencil[j].factor ;
      Eigen::Map<const Vector> cv(ctrl_vertices_ + VertexDim*index) ;
      x += factor*cv ;
    }
  }
}

template<
  int _VertexDim,
  typename _Scalar
>
template<typename Mesh>
void CatmullClark<_VertexDim, _Scalar>::subdivide( const Mesh* mesh ) {
  //setup control vertices if a new mesh is provided
  if((void*) mesh != (void*) this) {
    ctrl_vertices_ = mesh->vertices() ;
  }

  //reserve space for new stencils
  stencils_.reserve(
      mesh->vertices_size() //original vertices
      + mesh->faces_size() //face vertices
      + mesh->face_vertices_size() / 2 //edge vertices
      ) ;

  //reinitialize stencils if the mesh is not this
  if((void*) mesh != (void*) this) {
    stencils_.resize(0) ;
    for(unsigned int v = 0; v < mesh->vertices_size(); ++v) {
      stencils_.emplace_back(v) ;
    }
  }

  //face vertices
  const unsigned int fvstart = stencils_.size() ;
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    const unsigned int fsize = mesh->face_size(f) ;
    const unsigned int* fverts = mesh->face(f) ;
    Subdivision::Stencil<Scalar> stencil ;
    for(unsigned int v = 0; v < fsize; ++v) {
      stencil += stencils_[fverts[v]] ;
    }
    stencil.normalize() ;
    stencils_.push_back(stencil) ;
  }

  //edge vertices
  const unsigned int evstart = stencils_.size() ;
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    const unsigned int fsize = mesh->face_size(f) ;
    const unsigned int* fverts = mesh->face(f) ;
    const unsigned int* fneigh = mesh->face_neighbours(f) ;
    for(unsigned int v = 0; v < fsize; ++v) {
      if(f < fneigh[v]) { //avoid handling edges twice
        Subdivision::Stencil<Scalar> stencil ;
        stencil += stencils_[fverts[ v         ]] ;
        stencil += stencils_[fverts[(v+1)%fsize]] ;
        if(fneigh[v] != Mesh::NO_NEIGHBOUR) {
          //not considered for border edges
          stencil += stencils_[fvstart + f        ] ;
          stencil += stencils_[fvstart + fneigh[v]] ;
        }
        stencil.normalize() ;
        stencils_.push_back(stencil) ;
      }
    }
  }

  //original vertices
  std::vector< Subdivision::Stencil<Scalar> > contribs(2*mesh->vertices_size()) ;
  std::vector<int> valence(mesh->vertices_size(), 0) ;
  unsigned int eindex = 0 ;
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    const unsigned int fsize = mesh->face_size(f) ;
    const unsigned int* fverts = mesh->face(f) ;
    const unsigned int* fneigh = mesh->face_neighbours(f) ;
    for(unsigned int v = 0; v < fsize; ++v) {
      const unsigned ev1 = fverts[ v         ] ;
      const unsigned ev2 = fverts[(v+1)%fsize] ;
      //neighbouring face points considered only for non boundary vertices
      if(valence[ev1] >= 0) {
        contribs[2*ev1+1] += stencils_[fvstart + f] ;
        ++valence[ev1] ;
      }
      if(f < fneigh[v]) { //avoid handling edges twice
        if(fneigh[v] == Mesh::NO_NEIGHBOUR) {
          //border vertices => valence < 0
          if(valence[ev1] >= 0) {
            //only inner edges considered so far
            //reset edge contributions to consider only border edges
            contribs[2*ev1] = stencils_[evstart + eindex] ;
            valence[ev1] = -1 ;
          } else {
            contribs[2*ev1] += stencils_[evstart + eindex] ;
          }
          if(valence[ev2] >= 0) {
            contribs[2*ev2] = stencils_[evstart + eindex] ;
            valence[ev2] = -1 ;
          } else {
            contribs[2*ev2] += stencils_[evstart + eindex] ;
          }
        } else {
          if(valence[ev1] >= 0) {
            contribs[2*ev1] += stencils_[evstart + eindex] ;
          }
          if(valence[ev2] >= 0) {
            contribs[2*ev2] += stencils_[evstart + eindex] ;
          }
        }
        ++eindex ;
      }
    }
  }
  //final mixture for original vertices
  for(unsigned int v = 0; v < mesh->vertices_size(); ++v) {
    if(valence[v] > 2) {
      contribs[2*v  ].normalize() ;
      contribs[2*v+1].normalize() ;
      if(valence[v] > 3) {
        stencils_[v] *= valence[v] - 3 ;
        stencils_[v] += 2*contribs[2*v] ;
      } else {
        stencils_[v] = 2*contribs[2*v] ;
      }
      stencils_[v] += contribs[2*v+1] ;
    } else {
      contribs[2*v].normalize() ;
      stencils_[v] += contribs[2*v] ;
    }
    stencils_[v].normalize() ;
  }

  //faces
  std::vector<unsigned int> new_faces ;
  std::vector<unsigned int> new_neighbourhoods ;
  std::vector<unsigned int> new_face_patches ;
  new_faces.reserve(4*mesh->face_vertices_size()) ;
  new_neighbourhoods.reserve(4*mesh->face_vertices_size()) ;
  new_face_patches.reserve(mesh->face_vertices_size()) ;
  eindex = 0 ;
  std::vector<unsigned int> boundary_info ;
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    const unsigned int fsize = mesh->face_size(f) ;
    const unsigned int* fverts = mesh->face(f) ;
    const unsigned int* fneigh = mesh->face_neighbours(f) ;
    //recover edge neighbouring information
    boundary_info.resize(4*fsize) ;
    for(unsigned int v = 0; v < fsize; ++v) {
      if(fneigh[v] == Mesh::NO_NEIGHBOUR || f < fneigh[v]) {
        boundary_info[4*v  ] = evstart + eindex ;
        boundary_info[4*v+1] = Mesh::NO_NEIGHBOUR ;
        boundary_info[4*v+2] = Mesh::NO_NEIGHBOUR ;
        ++eindex ;
      } else {
        //edge vertices
        const unsigned int ev1 = fverts[ v         ] ;
        const unsigned int ev2 = fverts[(v+1)%fsize] ;
        //neighbouring face info
        const unsigned int nfsize = mesh->face_size(fneigh[v]) ;
        const unsigned int* nfverts = mesh->face(fneigh[v]) ;
        const unsigned int nfoffset = mesh->face_offset(fneigh[v]) ;
        //index of the edge in the neighbouring face in the old mesh
        const unsigned int neindex = mesh->edge_face_index(fneigh[v], ev1, ev2) ;
        //index of the new face containing ev1 from the neighbouring face
        if(nfverts[neindex] == ev2) {
          boundary_info[4*v  ] = new_faces[4*(nfoffset + neindex) + 1] ;
          boundary_info[4*v+1] = nfoffset + ((neindex+1)%nfsize) ;
          boundary_info[4*v+2] = nfoffset + neindex ;
          boundary_info[4*v+3] = 0 ;
        } else {
          boundary_info[4*v  ] = new_faces[4*(nfoffset + neindex) + 1] ;
          boundary_info[4*v+1] = nfoffset + neindex ;
          boundary_info[4*v+2] = nfoffset + ((neindex+1)%nfsize) ;
          boundary_info[4*v+3] = 1 ;
        }
      }
    }
    //build the faces
    const unsigned int fstart = mesh->face_offset(f) ;
    for(unsigned int v = 0; v < fsize; ++v) {
      const unsigned int prev_index = (v+fsize-1)%fsize ;
      //face vertices
      new_faces.push_back(fverts[v]) ;
      new_faces.push_back(boundary_info[4*v]) ;
      new_faces.push_back(fvstart + f) ;
      new_faces.push_back(boundary_info[4*prev_index]) ;
      //face patch
      if((void*) mesh != (void*) this) {
        new_face_patches[fstart + v] = f ;
      } else {
        new_face_patches[fstart + v] = face_patches_[f] ;
      }
      //face neighbourhoods
      if(fneigh[v] == Mesh::NO_NEIGHBOUR || f < fneigh[v]) {
        new_neighbourhoods.push_back(Mesh::NO_NEIGHBOUR) ;
      } else {
        new_neighbourhoods.push_back(boundary_info[4*v+1]) ;
      }
      new_neighbourhoods.push_back(fstart + ((v+1)%fsize)) ;
      new_neighbourhoods.push_back(fstart + prev_index) ;
      new_neighbourhoods.push_back(boundary_info[4*prev_index+2]) ;
      if(fneigh[v] != Mesh::NO_NEIGHBOUR && f > fneigh[v]) {
        if(boundary_info[4*v+3]) {
          //opposite face is coherently oriented
          new_neighbourhoods[4*boundary_info[4*v+1]  ] = fstart + v ;
          new_neighbourhoods[4*boundary_info[4*v+2]+3] = fstart+((v+1)%fsize) ;
        }
          //opposite face is flipped
          new_neighbourhoods[4*boundary_info[4*v+1]+3] = fstart + v ;
          new_neighbourhoods[4*boundary_info[4*v+2]  ] = fstart+((v+1)%fsize) ;
      }
    }
  }

  faces_.swap(new_faces) ;
  face_neighbourhoods_.swap(new_neighbourhoods) ;
  face_patches_.swap(new_face_patches) ;

  //compute vertex positions
  update() ;

  //finalize pointers
  Base::vertices_ = vertices_.data() ;
  Base::vertices_size_ = vertices_.size() / VertexDim ;
  Base::faces_ = faces_.data() ;
  Base::faces_size_ = faces_.size() / 4 ;
  Base::face_neighbourhoods_ = face_neighbourhoods_.data() ;
  Base::set_dirty() ;
}

} //end of namespace Revoropt

#endif
