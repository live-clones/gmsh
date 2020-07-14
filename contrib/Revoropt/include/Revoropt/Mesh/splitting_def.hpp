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
#ifndef _REVOROPT_MESH_SPLITTING_DEF_HPP_
#define _REVOROPT_MESH_SPLITTING_DEF_HPP_

#include "splitting_fwd.hpp"
#include "all_def.hpp"
#include "debug_def.hpp"
#include "connectivity_def.hpp"
#include "measure_def.hpp"
#include "normals_def.hpp"

#include <Eigen/Dense>
#include <queue>

namespace Revoropt {

/**{{{ Splitting edges in halves (decimation) **/

/* Split a face of the mesh in two given an edge index and the index of its
 * center vertex. The neighbourhoods along the split edge are set to none.
 * Returns the indices of the two split faces and their sizes. within these
 * faces, the layout of the vertices is such that :
 *   - the first face uses the mid vertex and the next one along the edge
 *   - the second face uses the first vertex of the edge and the mid one
 *   - the mid vertex is the last vertex in both faces */
template<typename MeshBuilder>
void face_split( MeshBuilder* mesh,
                 unsigned int face,
                 unsigned int edge_index,
                 unsigned int mid_vertex_index,
                 unsigned int* split_face_indices //output
               ) {
  //size of the face
  const unsigned int fsize = mesh->face_size(face) ;
  //vertices of the face
  const unsigned int* fverts = mesh->face(face) ;
  //neighbours of the face
  const unsigned int* fneigh = mesh->face_neighbours(face) ;

  //copy the face vertices
  std::vector<unsigned int> fverts_copy(fverts, fverts+fsize) ;
  //copy the face neighbours
  std::vector<unsigned int> fneigh_copy(fneigh, fneigh+fsize) ;

  //split face sizes
  unsigned int split_face_sizes[2] ;
  split_face_sizes[0] = fsize/2 + 2 ;
  split_face_sizes[1] = fsize - split_face_sizes[0] + 3 ;

  //allocation
  if(fsize < 5) {
    //the first new face exactly has the size of the split face
    //indices of the new fces
    split_face_indices[0] = face ;
    //compatibility of the mesh face size is checked here
    split_face_indices[1] = mesh->extend_faces(1,split_face_sizes[1]) ;
  } else {
    //translate face vector to remove one face
    mesh->erase_faces(face, face+1) ;
    //allocate space for the new faces
    //indices of the new faces
    //compatibility of the mesh face size is checked here
    split_face_indices[0] = mesh->extend_faces(1,split_face_sizes[0]) ;
    split_face_indices[1] = mesh->extend_faces(1,split_face_sizes[1]) ;
  }

  //index of the vertex to connect to the mid vertex of the split edge
  const unsigned int vopp = (edge_index + fsize/2 + 1) % fsize ;

  //fill the first face vertices and neighbours
  unsigned int* split_verts0 = mesh->face(split_face_indices[0]) ;
  unsigned int* split_neigh0 = mesh->face_neighbours(split_face_indices[0]) ;
  for(unsigned int k = 0 ; k < split_face_sizes[0]-1 ; ++k) {
    //vertex
    const unsigned int v0 = fverts_copy[(edge_index+1+k)%fsize] ;
    //set a vertex of the new face
    split_verts0[k] = v0 ;
    if(k != split_face_sizes[0]-2) {
      //neighbouring face
      const unsigned int n_face = fneigh_copy[(edge_index+1+k)%fsize] ;
      //next vertex
      const unsigned int v1 = fverts_copy[(edge_index+2+k)%fsize] ;
      //set a neighbour of the new face
      split_neigh0[k] = n_face ;
      //set the neighbour of the neighbour face
      if(n_face != MeshBuilder::NO_NEIGHBOUR) {
        const unsigned int n_edge_index = mesh->edge_face_index(n_face,v0,v1) ;
        assert( n_edge_index != MeshBuilder::NO_INDEX &&
                "error : connectivity mismatch"
              ) ;
        mesh->face_neighbours(n_face)[n_edge_index] = split_face_indices[0] ;
      }
    }
  }
  //add the new vertex to the first face
  split_verts0[split_face_sizes[0]-1] = mid_vertex_index ;

  //fill the second face vertices
  unsigned int* split_verts1 = mesh->face(split_face_indices[1]) ;
  unsigned int* split_neigh1 = mesh->face_neighbours(split_face_indices[1]) ;
  for(unsigned int k = 0 ; k < split_face_sizes[1]-1 ; ++k) {
    //vertex
    const unsigned int v0 = fverts_copy[(vopp+k)%fsize] ;
    //set a vertex of the new face
    split_verts1[k] = v0 ;
    if(k != split_face_sizes[1]-2) {
      //neighbouring face
      const unsigned int n_face = fneigh_copy[(vopp+k)%fsize] ;
      //next vertex
      const unsigned int v1 = fverts_copy[(vopp+k+1)%fsize] ;
      //set a neighbour of the new face
      split_neigh1[k] = n_face ;
      if(n_face != MeshBuilder::NO_NEIGHBOUR) {
        //set the neighbour of the neighbour face
        const unsigned int n_edge_index = mesh->edge_face_index(n_face,v0,v1) ;
        assert( n_edge_index != MeshBuilder::NO_INDEX &&
                "error : connectivity mismatch"
              ) ;
        mesh->face_neighbours(n_face)[n_edge_index] = split_face_indices[1] ;
      }
    }
  }
  //add the new vertex to the second face
  split_verts1[split_face_sizes[1]-1] = mid_vertex_index ;

  //set the neighbourhoods along the split edge
  split_neigh0[split_face_sizes[0]-2] = split_face_indices[1] ;
  split_neigh1[split_face_sizes[1]-1] = split_face_indices[0] ;

  //set the neighbourhoods along the pieces of the split edge to NO_NEIGHBOUR
  split_neigh0[split_face_sizes[0]-1] = MeshBuilder::NO_NEIGHBOUR ;
  split_neigh1[split_face_sizes[1]-2] = MeshBuilder::NO_NEIGHBOUR ;

}

/* Split an edge of a mesh builder. If the provided arrays are not NULL, returns
 * the indices and sizes of the new faces. The size of the arrays to provide is
 * two in case of a border edge, and 4 otherwise.*/
template<typename MeshBuilder>
void edge_split( MeshBuilder* mesh,
                 unsigned int face,
                 unsigned int edge_index,
                 unsigned int* split_face_indices = NULL //output
                ) {
  //types
  typedef Eigen::Matrix< typename MeshBuilder::Scalar,
                         MeshBuilder::VertexDim,
                         1
                       > Vector ;

  //handle NULL output
  bool handle_null_input = split_face_indices == NULL ;
  if(handle_null_input){
    split_face_indices = new unsigned int[4] ;
  }

  //size of the face
  const unsigned int fsize = mesh->face_size(face) ;
  //vertices of the face
  const unsigned int* fverts = mesh->face(face) ;
  //neighbours of the face
  const unsigned int* fneigh = mesh->face_neighbours(face) ;

  //vertices of the edge
  const unsigned int v1 = fverts[ edge_index         ] ;
  const unsigned int v2 = fverts[(edge_index+1)%fsize] ;

  //reserve space for a new vertex
  const unsigned int vmid = mesh->extend_vertices(1) ;

  //add the edge center to the vertices
  Eigen::Map<const Vector> v1pos(mesh->vertex(v1)) ;
  Eigen::Map<const Vector> v2pos(mesh->vertex(v2)) ;
  Eigen::Map<Vector> vmidpos(mesh->vertex(vmid)) ;
  vmidpos = 0.5*(v1pos+v2pos) ;

  //neighbouring face along the edge
  const unsigned int n_face = fneigh[edge_index] ;

  //check if the face edge is on the buondary
  if(n_face == MeshBuilder::NO_NEIGHBOUR) {
    //the edge is on the boundary, no neighbouring face to handle
    //split the face
    face_split( mesh,
                face, edge_index, vmid,
                split_face_indices
              ) ;
  } else {
    //a neighbouring face exists and is to be handled
    //index of the edge within the neighbouring face
    unsigned int n_edge_index = mesh->edge_face_index(n_face,v1,v2) ;
    assert( n_edge_index != MeshBuilder::NO_INDEX &&
            "error : connectivity mismatch."
          ) ;
    //determine orientation
    const unsigned int shift = mesh->face(n_face)[n_edge_index]==v2 ? 0 : 1 ;
    //split the face
    face_split( mesh,
                face, edge_index, vmid,
                split_face_indices
              ) ;
    //split the neighbouring face
    face_split( mesh,
                n_face, n_edge_index, vmid,
                split_face_indices + 2
              ) ;

    //reconnect the split faces along the split edge
    //neighbourhoods of the split faces
    unsigned int* split_fneigh[4] ;
    unsigned int split_fsize[4] ;
    for(int i=0; i<4; ++i) {
      split_fneigh[i] = mesh->face_neighbours(split_face_indices[i]) ;
      split_fsize[i] = mesh->face_size(split_face_indices[i]) ;
    }
    //fisrt face from the split of face
    const unsigned int s_face0 = split_face_indices[0] ;
    //second face from the split of face
    const unsigned int s_face1 = split_face_indices[1] ;
    //face from the split of n_face next to the first split face of face
    const unsigned int ns_face0 = split_face_indices[3-shift] ;
    //face from the split of n_face next to the second split face of face
    const unsigned int ns_face1 = split_face_indices[2+shift] ;
    //connect
    split_fneigh[0][split_fsize[0]-1] = ns_face0 ;
    split_fneigh[3-shift][split_fsize[3-shift]-2+shift] = s_face0 ;
    split_fneigh[1][split_fsize[1]-2] = ns_face1 ;
    split_fneigh[2+shift][split_fsize[2+shift]-1-shift] = s_face1 ;
  }

  //cleanup if necessary
  if(handle_null_input){
    delete[] split_face_indices ;
  }
}

template<typename Mesh, typename MeshBuilder>
void split_longest_edge( const Mesh* input,
                         unsigned int niter,
                         MeshBuilder* mesh
                       ) {
  //dimension
  enum { Dim = Mesh::VertexDim } ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vertex pair
  typedef std::pair<unsigned int, unsigned int> VertexPair ;
  //heap edge
  typedef Decimate::HeapEdge<Scalar> HeapEdge ;

  //initialize the output mesh
  mesh->init(input) ;

  //the longest edge for each face
  std::vector<VertexPair> longest_edge(mesh->faces_size()) ;

  //a heap to track the longest edge
  std::vector<HeapEdge> edge_heap ;

  //initialize the heap and longest edges
  for(unsigned int face = 0; face < mesh->faces_size(); ++face) {
    //size of the face
    const unsigned int fsize = mesh->face_size(face) ;
    //vertices of the face
    const unsigned int* fverts = mesh->face(face) ;
    //neighbours of the face
    const unsigned int* fneigh = mesh->face_neighbours(face) ;
    //longest edge of the face
    Scalar length ;
    unsigned int edge = face_longest_edge(mesh, face, &length) ;
    //vertices of the edge
    const unsigned int v0 = fverts[ edge         ] ;
    const unsigned int v1 = fverts[(edge+1)%fsize] ;
    //sort indices
    const unsigned int vmin = v0 < v1 ? v0 : v1 ;
    const unsigned int vmax = v0 < v1 ? v1 : v0 ;
    //add the longest edge for the current face
    longest_edge[face] = VertexPair(vmin,vmax) ;
    //check if that edge was already added into the heap
    const unsigned int n_face = fneigh[edge] ;
    if((n_face > face) || (longest_edge[n_face] != VertexPair(vmin,vmax))) {
      //the edge has not been added, add it
      edge_heap.resize(edge_heap.size()+1) ;
      HeapEdge& he = edge_heap.back() ;
      he.face = face ;
      he.edge = edge ;
      he.vmin = vmin ;
      he.vmax = vmax ;
      he.length = length ;
    }
  }

  //sort the heap
  std::make_heap(edge_heap.begin(), edge_heap.end()) ;

  //TODO erase from longest edge if original face not reused

  //iteratively split the longest edge
  unsigned int new_faces[4] ;
  for(unsigned int iter = 0; iter < niter; ++iter) {
    //get the longest edge
    const HeapEdge& he = edge_heap.front() ;
    Scalar ref_len ;
    //number of faces before the split
    const unsigned int mesh_size = mesh->faces_size() ;
    //opposite face split
    const unsigned int split_nface = mesh->face_neighbours(he.face)[he.edge] ;

    //split the edge
    edge_split(mesh, he.face, he.edge, new_faces) ;

    //number of faces split (1 or 2 depending on whether the edge is a boundary)
    const unsigned int nsplits = mesh->faces_size() - mesh_size ;

    //update longest edge array in case of face erase
    if(mesh->face_size(he.face) > 4) {
      longest_edge.erase(longest_edge.begin()+he.face) ;
    }
    if( (split_nface != Mesh::NO_NEIGHBOUR) &&
        (mesh->face_size(split_nface) > 4) ) {
      longest_edge.erase(longest_edge.begin()+split_nface) ;
    }

    //remove the edge from the heap
    std::pop_heap(edge_heap.begin(), edge_heap.end());
    edge_heap.pop_back() ;

    //resize longest edge array
    longest_edge.resize(longest_edge.size()+nsplits) ;

    //add (if necessary) the longest face edges of the new faces
    for(unsigned int i = 0; i < 2*nsplits; ++i ) {
      //new face
      const unsigned int face = new_faces[i] ;
      //size of the face
      const unsigned int fsize = mesh->face_size(face) ;
      //vertices of the face
      const unsigned int* fverts = mesh->face(face) ;
      //neighbours of the face
      const unsigned int* fneigh = mesh->face_neighbours(face) ;
      //longest edge of the face
      Scalar length ;
      unsigned int edge = face_longest_edge(mesh, face, &length) ;
      //vertices of the edge
      const unsigned int v0 = fverts[ edge         ] ;
      const unsigned int v1 = fverts[(edge+1)%fsize] ;
      //sort indices
      const unsigned int vmin = v0 < v1 ? v0 : v1 ;
      const unsigned int vmax = v0 < v1 ? v1 : v0 ;
      //add the longest edge for the current face
      longest_edge[face] = VertexPair(vmin,vmax) ;
      //check if that edge was already added into the heap
      const unsigned int n_face = fneigh[edge] ;
      bool n_face_is_new_and_after = false ;
      for(unsigned int new_face = i+1; new_face < 2*nsplits; ++new_face) {
        if(new_face < 4 && n_face == new_faces[new_face]) {
          n_face_is_new_and_after = true ;
          break ;
        }
      }
      if( n_face_is_new_and_after || (n_face == Mesh::NO_NEIGHBOUR) ||
          (longest_edge[n_face] != VertexPair(vmin,vmax))
        ) {
        //the edge has not been added, add it
        edge_heap.resize(edge_heap.size()+1) ;
        HeapEdge& new_he = edge_heap.back() ;
        new_he.face = face ;
        new_he.edge = edge ;
        new_he.vmin = vmin ;
        new_he.vmax = vmax ;
        new_he.length = length ;
        //preserve the heap property
        std::push_heap(edge_heap.begin(), edge_heap.end()) ;
      } else {
      }
    }
  }
}

//}}}

/**{{{ Normal bevel : split triangles to improve normal interpolation **/

namespace Bevel {

/* criterion based on the normal to decide whether an edge needs splitting */
template<typename Mesh>
EdgeSplitType NormalSplitCriterion<Mesh>::edge_type( unsigned int face,
                                                     unsigned int edge
                                                   ) const {
  //edge index
  const unsigned int edge_index = mesh_->face_offset(face) + edge ;
  //face size
  const unsigned int fsize = mesh_->face_size(face) ;
  //face vertices
  const unsigned int* fverts = mesh_->face(face) ;
  //edge vertices
  const unsigned int v0 = fverts[edge] ;
  const unsigned int v1 = fverts[(edge+1)%fsize] ;
  //in case of boundary restriction, do not split inner edges
  if(restrict_to_boundary_) {
    if(!boundary_vertices_[v0] && !boundary_vertices_[v1]) {
      return SPLIT_NONE ;
    }
  }
  ////other vertices centroid
  //Vector g = Vector::Zero() ;
  //for(unsigned int v = 2; v < fsize; ++v) {
  //  g += Eigen::Map<const Vector>(mesh_->vertex(fverts[(edge+v)%fsize])) ;
  //}
  //g /= fsize-2 ;
  ////opposite angle criterion
  //const Vector gv0 = g - Eigen::Map<const Vector>(mesh_->vertex(v0)) ;
  //const Vector gv1 = g - Eigen::Map<const Vector>(mesh_->vertex(v1)) ;
  //if(gv0.dot(gv1)/(gv0.norm()*gv1.norm()) > cosine_threshold_) {
  //  return SPLIT_NONE ;
  //}
  //normals
  Eigen::Map<const Vector> enormal(edge_normals_.data() + 3*edge_index) ;
  Eigen::Map<const Vector> vnormal0(vertex_normals_.data() + 3*v0) ;
  Eigen::Map<const Vector> vnormal1(vertex_normals_.data() + 3*v1) ;
  //test
  int split_type = 0 ;
  if(enormal.dot(vnormal0) < cosine_threshold_) {
    split_type += 1 ;
  } else {
    //std::cout << enormal.dot(vnormal0) << std::endl ;
  }
  if(enormal.dot(vnormal1) < cosine_threshold_) {
    split_type += 2 ;
  } else {
    //std::cout << enormal.dot(vnormal1) << std::endl ;
  }
  return (EdgeSplitType) split_type ;
}

template<typename Mesh>
void NormalSplitCriterion<Mesh>::init() {
  //allocate space for normals
  edge_normals_.resize(3*mesh_->face_vertices_size()) ;
  vertex_normals_.resize(3*mesh_->vertices_size()) ;
  boundary_vertices_.assign(mesh_->vertices_size(), false) ;
  //compute vertex normals
  full_robust_vertex_normals(mesh_,normal_radius_,vertex_normals_.data()) ;
  //compute edge normals
  robust_edge_normals(mesh_,normal_radius_,edge_normals_.data()) ;

  //FIXME
  EdgeLayer<Mesh> edge_layer(mesh_) ;
  edge_midpoints_.assign(3*mesh_->face_vertices_size(),0) ;
  for(unsigned int edge = 0; edge < mesh_->face_vertices_size(); ++edge) {
    //vertices of the edge
    const unsigned int v0 = edge_layer.edge_start_vertex(edge) ;
    const unsigned int v1 = edge_layer.edge_end_vertex(edge) ;
    if(edge_layer.is_border(edge)) {
      boundary_vertices_[v0] = true ;
      boundary_vertices_[v1] = true ;
    }
    Eigen::Map<const Vector> v0_pos(mesh_->vertex(v0)) ;
    Eigen::Map<const Vector> v1_pos(mesh_->vertex(v1)) ;
    //add its midpoint
    Eigen::Map<Vector> midpoint(edge_midpoints_.data() + 3*edge) ;
    midpoint = 0.5*(v0_pos + v1_pos) ;
  }
}

/* triangle classification, depending on its edges split types */
void normalize_triangle_split( const EdgeSplitType edge_types[3],
                               FaceSplitType* split_type //output
                             ) {
  /* precomputed triangle split type translation */
  static const unsigned char triangle_split_translate[64] = {
    0 , 1 , 1 , 2 , 1 , 3 , 4 , 5 ,
    1 , 6 , 3 , 7 , 2 , 7 , 5 , 8 ,
    1 , 3 , 6 , 7 , 3 , 9 , 10, 11,
    4 , 10, 10, 12, 5 , 11, 13, 14,
    1 , 4 , 3 , 5 , 6 , 10, 10, 13,
    3 , 10, 9 , 11, 7 , 12, 11, 14,
    2 , 5 , 7 , 8 , 7 , 11, 12, 14,
    5 , 13, 11, 14, 8 , 14, 14, 15
  } ;

  //initialize minimal index
  split_type->index = 64 ;
  //initialize rotation and symetry
  split_type->rotation = 0 ;
  split_type->symetry = false ;
  //loop over the transformations
  unsigned int cur_index = 0 ;
  for(int sym = -1; sym < 2; sym += 2) {
    for(int rot = 0; rot < 3; ++rot) {
      //reinitialize index
      cur_index = 0 ;
      //compute index
      for(int edge = 0; edge < 3; ++edge) {
        cur_index *= 4 ;
        cur_index += sym < 0 ?
          edge_types[(5 + sym*(rot+edge))%3] :
          edge_split_type_sym(edge_types[(5 + sym*(rot+edge))%3]) ;
      }
      //check if this index is minimal for this configuration
//      std::cout << "score is " << cur_index << " for rotation " << rot << " and symmetry " << (sym==1) << std::endl ;
      if(cur_index < split_type->index) {
        //store the index, rotation and symetry
        split_type->index = cur_index ;
        split_type->rotation = rot ;
        split_type->symetry = (sym == 1) ;
      }
    }
  }
  //translate type index
  split_type->index = triangle_split_translate[split_type->index] ;
}

/* compute the split points of an edge given its type, a radius and length */
/* returns the split really performed given the radius and edge length */

template<typename Mesh>
EdgeSplitType edge_split( const Mesh* mesh,
                          unsigned int face,
                          unsigned int edge,
                          typename Mesh::Scalar radius,
                          EdgeSplitType split_type,
                          std::vector<typename Mesh::Scalar>& coords, //i/o
                          std::vector<unsigned int>& edge_split_verts //output
                        ) {
  //dimension
  enum { Dim = Mesh::VertexDim } ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;

  if(split_type == SPLIT_NONE) {
    //edge is not split
    edge_split_verts.push_back(NO_VERTEX) ;
    edge_split_verts.push_back(NO_VERTEX) ;
  } else {
    //size of the face
    const unsigned int fsize = mesh->face_size(face) ;
    //face vertices
    const unsigned int* fverts = mesh->face(face) ;
    //vertices of the edge
    const unsigned int v0 = fverts[ edge         ] ;
    const unsigned int v1 = fverts[(edge+1)%fsize] ;
    //cosines of the angles at the extremities
    const Scalar v0cos = 0 ;//face_angle_cos(mesh, face,  edge         ) ;
    const Scalar v1cos = 0 ;//face_angle_cos(mesh, face, (edge+1)%fsize) ;
    //vertex positions
    Eigen::Map<const Vector> v0_pos(mesh->vertex(v0)) ;
    Eigen::Map<const Vector> v1_pos(mesh->vertex(v1)) ;
    //edge vector
    const Vector edge_vect = (v1_pos - v0_pos) ;
    //length of the edge
    const Scalar e_len = edge_vect.norm() ;
    //lehgths of the cuts at each extremity
    const Scalar v0len = v0cos == 1 ? e_len : radius/sqrt(1-v0cos*v0cos) ;
    const Scalar v1len = v1cos == 1 ? e_len : radius/sqrt(1-v1cos*v1cos) ;
    if(split_type == SPLIT_BOTH) {
      //edge is split at both ends
      //handle merging
      if(e_len > (v0len + v1len + radius)) {
        //no merging
        //split vertex indices
        const unsigned int vsplit0 = coords.size()/Dim ;
        const unsigned int vsplit1 = vsplit0+1 ;
        //allocate space for new vertices
        coords.resize(coords.size() + 2*Dim) ;
        //split vertex positions
        Eigen::Map<Vector> vsplit0_pos(coords.data() + Dim*vsplit0) ;
        Eigen::Map<Vector> vsplit1_pos(coords.data() + Dim*vsplit1) ;
        vsplit0_pos = v0_pos + v0len/e_len*edge_vect ;
        vsplit1_pos = v1_pos - v1len/e_len*edge_vect ;
        //append split vertex indices
        edge_split_verts.push_back(vsplit0) ;
        edge_split_verts.push_back(vsplit1) ;
//        std::cout << "split both at " << vsplit0 << " " << vsplit1 << std::endl ;
        return SPLIT_BOTH ;
      } else if(e_len > (v0len + v1len)) {
        //merging at the edge barycenter with weights v0len and v1len
        //split vertex index
        const unsigned int vsplit = coords.size()/Dim ;
        //allocate space for new vertices
        coords.resize(coords.size() + Dim) ;
        //split vertex positions
        Eigen::Map<Vector> vsplit_pos(coords.data() + Dim*vsplit) ;
        vsplit_pos = (v1len*v0_pos + v0len*v1_pos) / (v0len + v1len) ;
        //append split vertex indices, duplicated here because of the merge
        edge_split_verts.push_back(vsplit) ;
        edge_split_verts.push_back(vsplit) ;
        return SPLIT_BOTH ;
      } else {
        //splitting canceled
        edge_split_verts.push_back(NO_VERTEX) ;
        edge_split_verts.push_back(NO_VERTEX) ;
        return SPLIT_NONE ;
      }
    } else {
      //one single end is split
      //handle merging
      const Scalar cutlen = split_type == SPLIT_FIRST ? v0len : v1len ;
      if(e_len > (cutlen + radius)) {
        //no merging
        //split vertex index
        const unsigned int vsplit = coords.size()/Dim ;
        //allocate space for new vertices
        coords.resize(coords.size() + Dim) ;
        //split vertex positions
        Eigen::Map<Vector> vsplit_pos(coords.data() + Dim*vsplit) ;
        if(split_type == SPLIT_FIRST) {
          vsplit_pos = v0_pos + cutlen/e_len*edge_vect ;
          //append split vertex indices
          edge_split_verts.push_back(vsplit) ;
          edge_split_verts.push_back(NO_VERTEX) ;
          return SPLIT_FIRST ;
        } else {
          vsplit_pos = v1_pos - cutlen/e_len*edge_vect ;
          //append split vertex indices
          edge_split_verts.push_back(NO_VERTEX) ;
          edge_split_verts.push_back(vsplit) ;
          return SPLIT_SECOND ;
        }
      } else {
        //splitting canceled
        edge_split_verts.push_back(NO_VERTEX) ;
        edge_split_verts.push_back(NO_VERTEX) ;
        return SPLIT_NONE ;
      }
    }
  }
  return SPLIT_NONE ;
}

/* split a face given its split type and the edge split vertices */
template<typename Mesh>
void face_split( const Mesh* mesh,
                 unsigned int face,
                 typename Mesh::Scalar radius,
                 const EdgeSplitType edge_types[3],
                 const unsigned int edge_split_verts[6],
                 std::vector<typename Mesh::Scalar>& coords, //output
                 std::vector<unsigned int>& split_faces //output
               ) {
  /* predifined triangle split patterns    Ref edge types */
  static const unsigned char triangle_split_0[3]   = { //0 0 0
    0,1,2
  } ;
  static const unsigned char triangle_split_1[6]   = { //1 0 0
    0,1,3,1,2,3
  } ;
  static const unsigned char triangle_split_2[9]   = { //3 0 0
    0,1,4,1,2,4,2,3,4
  } ;
  static const unsigned char triangle_split_3[9]   = { //1 1 0
    0,1,4,1,2,3,1,3,4
  } ;
  static const unsigned char triangle_split_4[9]   = { //2 1 0
    0,1,3,1,2,3,0,3,4
  } ;
  static const unsigned char triangle_split_5[12]  = { //3 1 0
    0,1,5,1,2,4,1,4,5,2,3,4
  } ;
  static const unsigned char triangle_split_6[9]   = { //1 2 0
    0,1,3,0,3,4,1,2,3
  } ;
  static const unsigned char triangle_split_7[12]  = { //3 2 0
    0,4,5,0,1,4,1,2,4,2,3,4
  } ;
  static const unsigned char triangle_split_8[15]  = { //3 3 0
    0,5,6,0,1,5,1,4,5,1,2,4,2,3,4
  } ;
  static const unsigned char triangle_split_9[12]  = { //1 1 1
    0,1,5,1,3,5,1,2,3,5,3,4
  } ;
  static const unsigned char triangle_split_10[12] = { //2 1 1
    0,1,5,1,3,5,1,2,3,5,3,4
  } ;
  static const unsigned char triangle_split_11[15] = { //3 1 1
    0,1,6,1,2,6,2,3,4,2,4,6,4,5,6
  } ;
  static const unsigned char triangle_split_12[21] = { //3 2 1
    0,1,7,0,7,6,1,2,7,2,3,7,7,3,4,6,7,4,6,4,5
  } ;
  static const unsigned char triangle_split_13[15] = { //2 3 1
    0,1,6,1,2,3,1,3,6,6,3,4,6,4,5
  } ;
  static const unsigned char triangle_split_14[24] = { //3 3 1
    0,1,8,0,8,7,1,2,8,2,4,8,2,3,4,8,5,7,8,4,5,7,5,6
  } ;
  static const unsigned char triangle_split_15[39] = { //3 3 3
    0,1,8,1,9,8,1,2,9,2,10,9,2,4,10,2,3,4,9,10,11,
    8,9,11,8,11,7,10,4,5,10,5,11,11,5,7,6,7,5
  } ;
  static const unsigned char triangle_split_sizes[16] = {
    1,2,3,3,3,4,3,4,5,4,4,5,7,5,8,13
  } ;
  static const unsigned char* triangle_patterns[16] = {
    triangle_split_0,
    triangle_split_1,
    triangle_split_2,
    triangle_split_3,
    triangle_split_4,
    triangle_split_5,
    triangle_split_6,
    triangle_split_7,
    triangle_split_8,
    triangle_split_9,
    triangle_split_10,
    triangle_split_11,
    triangle_split_12,
    triangle_split_13,
    triangle_split_14,
    triangle_split_15
  } ;

  //dimension
  enum { Dim = Mesh::VertexDim } ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;

  //normalize the triangle split
  FaceSplitType face_type ;
  normalize_triangle_split(edge_types, &face_type) ;

  //collect the triangle boundary vertices
  std::vector<unsigned int> triangle_vertices ;
//  std::cout << "face rotation " << face_type.rotation << std::endl ;
//  std::cout << "face symetry " << std::boolalpha << face_type.symetry << std::endl ;
  for(int edge = 0; edge < 3; ++edge) {
    //compute the edge index given the normalization
    const int edge_face_index = face_type.symetry ?
      (4+face_type.rotation-edge)%3 :
      (3-face_type.rotation+edge)%3 ;

    //add the edge start vertex
    const unsigned int edge_start_vertex = face_type.symetry ?
      mesh->face_edge_end_vertex(face, edge_face_index) :
      mesh->face_edge_start_vertex(face, edge_face_index) ;
    triangle_vertices.push_back(edge_start_vertex) ;

    //add the edge split vertices
    const unsigned int* this_edge_split_verts =
      edge_split_verts + 2*edge_face_index ;
    const EdgeSplitType edge_type = edge_types[edge_face_index] ;
//    std::cout << "edge face index " << edge_face_index << std::endl ;
//    std::cout << "edge type at collect " << edge_type << std::endl ;
//    std::cout << "pushing vertex " << edge_start_vertex << std::endl ;
    if(edge_type == SPLIT_FIRST) {
      triangle_vertices.push_back(this_edge_split_verts[0]) ;
    } else if(edge_type == SPLIT_SECOND) {
      triangle_vertices.push_back(this_edge_split_verts[1]) ;
    } else if(edge_type == SPLIT_BOTH) {
      if(face_type.symetry) {
        triangle_vertices.push_back(this_edge_split_verts[1]) ;
        triangle_vertices.push_back(this_edge_split_verts[0]) ;
      } else {
        triangle_vertices.push_back(this_edge_split_verts[0]) ;
        triangle_vertices.push_back(this_edge_split_verts[1]) ;
      }
    }
  }
//  std::cout << "configuration : " << face_type.index << std::endl ;
//  std::cout << "triangle vertices size : " << triangle_vertices.size() << std::endl ;

  //add the necessary face split vertices
  if(face_type.index == 12) {
    //one face vertex to add
    //allocate space for the face vertex
    const unsigned int vsplit = coords.size()/Dim ;
    coords.resize(coords.size() + Dim) ;
    Eigen::Map<Vector> vsplit_pos(coords.data() + Dim*vsplit) ;
    //check the face area to avoid degeneracies
    if(mesh_face_area(mesh, face) < 8*radius*radius) {
      //special case
      //the central vertex becomes the centroid of the vertices it connects to
      Eigen::Map<const Vector> pos0(coords.data()+Dim*triangle_vertices[0]) ;
      Eigen::Map<const Vector> pos1(coords.data()+Dim*triangle_vertices[1]) ;
      Eigen::Map<const Vector> pos2(coords.data()+Dim*triangle_vertices[2]) ;
      Eigen::Map<const Vector> pos3(coords.data()+Dim*triangle_vertices[3]) ;
      Eigen::Map<const Vector> pos4(coords.data()+Dim*triangle_vertices[4]) ;
      Eigen::Map<const Vector> pos6(coords.data()+Dim*triangle_vertices[6]) ;
      vsplit_pos = (pos0 + pos1 + pos2 + pos3 + pos4 + pos6)/6 ;
    } else {
      //compute the vertex position position
      Eigen::Map<const Vector> pos4(coords.data()+Dim*triangle_vertices[4]) ;
      Eigen::Map<const Vector> pos5(coords.data()+Dim*triangle_vertices[5]) ;
      Eigen::Map<const Vector> pos6(coords.data()+Dim*triangle_vertices[6]) ;
      vsplit_pos = pos4 + pos6 - pos5 ;
    }
    //add the vertex to the triangle vertices
    triangle_vertices.push_back(vsplit) ;
  } else if(face_type.index == 14) {
    //one face to add
    //allocate space for the face vertex
    const unsigned int vsplit = coords.size()/Dim ;
    coords.resize(coords.size() + Dim) ;
    Eigen::Map<Vector> vsplit_pos(coords.data() + Dim*vsplit) ;
    //check the face area to avoid degeneracies
    if(mesh_face_area(mesh, face) < 8*radius*radius) {
      //special case
      //the central vertex becomes the centroid of the vertices it connects to
      Eigen::Map<const Vector> pos0(coords.data()+Dim*triangle_vertices[0]) ;
      Eigen::Map<const Vector> pos1(coords.data()+Dim*triangle_vertices[1]) ;
      Eigen::Map<const Vector> pos2(coords.data()+Dim*triangle_vertices[2]) ;
      Eigen::Map<const Vector> pos4(coords.data()+Dim*triangle_vertices[4]) ;
      Eigen::Map<const Vector> pos5(coords.data()+Dim*triangle_vertices[5]) ;
      Eigen::Map<const Vector> pos7(coords.data()+Dim*triangle_vertices[7]) ;
      vsplit_pos = (pos0 + pos1 + pos2 + pos4 + pos5 + pos7)/6 ;
    } else {
      //compute its position
      Eigen::Map<const Vector> pos5(coords.data()+Dim*triangle_vertices[5]) ;
      Eigen::Map<const Vector> pos6(coords.data()+Dim*triangle_vertices[6]) ;
      Eigen::Map<const Vector> pos7(coords.data()+Dim*triangle_vertices[7]) ;
      vsplit_pos = pos5 + pos7 - pos6 ;
    }
    //add the vertex to the triangle vertices
    triangle_vertices.push_back(vsplit) ;
  } else if(face_type.index == 15) {
    //three potential face vertices, merged if too close
    //compute their positions
    Vector fv[3] ;
    for(int i = 0; i < 3; ++i) {
      Eigen::Map<const Vector> v0(coords.data()+Dim*triangle_vertices[(8+3*i)%9]) ;
      Eigen::Map<const Vector> v1(coords.data()+Dim*triangle_vertices[(0+3*i)%9]) ;
      Eigen::Map<const Vector> v2(coords.data()+Dim*triangle_vertices[(1+3*i)%9]) ;
      fv[i] = v0 + v2 - v1 ;
    }
    //merge the vertices if necessary
    int merge_size = 0 ;
    int last_merge = 0 ;
    for(int i = 0; i < 3; ++i) {
      //split vertices of the edge
      const unsigned int sv0 = triangle_vertices[1+3*i] ;
      const unsigned int sv1 = triangle_vertices[2+3*i] ;
      //check whether
      //  1/ the edge split vertices were merged
      //  2/ the inner vertices along this edge are not too close
      if((sv0 == sv1) || ((fv[i] - fv[(i+1)%3]).norm() < radius)) {
        ++merge_size ;
        last_merge = i ;
      }
    }
    if(merge_size > 0) {
      if(merge_size == 1) {
        //two new vertices are too close and merged
        //allocate space for two vertices
        const unsigned int vsplit0 = coords.size()/Dim ;
        const unsigned int vsplit1 = vsplit0 + 1 ;
        coords.resize(coords.size() + 2*Dim) ;
        Eigen::Map<Vector> vsplit0_pos(coords.data()+Dim*vsplit0) ;
        Eigen::Map<Vector> vsplit1_pos(coords.data()+Dim*vsplit1) ;
        //merged vertex
        vsplit0_pos = 0.5*(fv[last_merge] + fv[(last_merge+1)%3]) ;
        //other vertex
        vsplit1_pos = fv[(last_merge+2)%3] ;
        //add the vertices to the triangle vertices
        for(int i = 0; i < 3; ++i) {
          if(i == (last_merge+2)%3) {
            triangle_vertices.push_back(vsplit1) ;
          } else {
            triangle_vertices.push_back(vsplit0) ;
          }
        }
      } else {
        //the three vertices are merged
        //allocate space for one vertex
        const unsigned int vsplit = coords.size()/Dim ;
        coords.resize(coords.size() + Dim) ;
        Eigen::Map<Vector> vsplit_pos(coords.data()+Dim*vsplit) ;
        //merged vertex
        vsplit_pos = (fv[0] + fv[1] + fv[2])/3 ;
        //add the vertices to the triangle vertices
        for(int i = 0; i < 3; ++i) {
          triangle_vertices.push_back(vsplit) ;
        }
      }
    } else {
      //no merge
      //allocate space for three vertices
      const unsigned int vsplit0 = coords.size()/Dim ;
      const unsigned int vsplit1 = vsplit0 + 1 ;
      const unsigned int vsplit2 = vsplit1 + 1 ;
      coords.resize(coords.size() + 3*Dim) ;
      Eigen::Map<Vector> vsplit0_pos(coords.data()+Dim*vsplit0) ;
      Eigen::Map<Vector> vsplit1_pos(coords.data()+Dim*vsplit1) ;
      Eigen::Map<Vector> vsplit2_pos(coords.data()+Dim*vsplit2) ;
      //copy vertex positions
      vsplit0_pos = fv[0] ;
      vsplit1_pos = fv[1] ;
      vsplit2_pos = fv[2] ;
      //add the vertices to the triangle vertices
      triangle_vertices.push_back(vsplit0) ;
      triangle_vertices.push_back(vsplit1) ;
      triangle_vertices.push_back(vsplit2) ;
    }
  }

//  std::cout << "Adding split triangles" << std::endl ;
//  std::cout << "Original size is " << (int) triangle_split_sizes[face_type.index] << std::endl ;

  //add the new triangles if they are not degenerate
  //subdivision pattern for this triangle
  const unsigned char* split_triangles = triangle_patterns[face_type.index] ;
  //add the triangles
  for( unsigned char triangle = 0 ;
       triangle < triangle_split_sizes[face_type.index] ;
       ++triangle
     ) {
    //vertices of the triangle
    const unsigned char* tverts = split_triangles + 3*triangle ;
    //check if the triangle is degenerate
    bool regular = true ;
    for(int i = 0; i < 3; ++i) {
      if(triangle_vertices[tverts[i]] == triangle_vertices[tverts[(i+1)%3]]) {
        regular = false ;
        break ;
      }
    }
    if(regular) {
      //the triangle is not degenerate, add it
      if(face_type.symetry) {
        for(int i = 2; i >= 0; --i) {
          const unsigned int vertex = triangle_vertices[tverts[i]] ;
//          std::cout << "triangle vertex " << vertex << std::endl ;
          split_faces.push_back(vertex) ;
        }
      } else {
        for(int i = 0; i < 3; ++i) {
          const unsigned int vertex = triangle_vertices[tverts[i]] ;
//          std::cout << "triangle vertex " << vertex << std::endl ;
          split_faces.push_back(vertex) ;
        }
      }
    } else {
//      std::cout << "degenerate triangle !" << std::endl ;
    }
  }
}

} //end of namespace Bevel

template< typename Triangulation,
          typename TriangulationBuilder,
          typename Criterion >
void bevel( const Triangulation* mesh,
            const Criterion* criterion,
            typename Triangulation::Scalar radius,
            TriangulationBuilder* mesh_builder //output
          ) {
  using namespace Bevel ;

  //dimension
  enum { Dim = Triangulation::VertexDim } ;
  //scalar type
  typedef typename Triangulation::Scalar Scalar ;

  //arrays of the new mesh
  std::vector<Scalar> split_verts ;
  std::vector<unsigned int> split_faces ;

  //copy the vertices of the original mesh
  //FIXME problem if mesh has vertex offset
  split_verts.assign(
    mesh->vertices(),
    mesh->vertices() + Dim*mesh->vertices_size()
  ) ;

  //split the mesh faces and edges according to the criterion used
  //edge split types
  std::vector<EdgeSplitType> edge_types ;
  edge_types.reserve(mesh->face_vertices_size()) ;
  //edge split vertices
  std::vector<unsigned int> edge_split_verts ;
  edge_split_verts.reserve(2*mesh->face_vertices_size()) ;
  //iterate over faces
  //unsigned int set = 1 ;
  //for(unsigned int face = 125*set; face < 125*(set+1); ++face) {
  for(unsigned int face = 0; face < mesh->faces_size(); ++face) {
    //face size
    const unsigned int fsize = mesh->face_size(face) ;
    //face vertices
    const unsigned int* fverts = mesh->face(face) ;
    //face neighbours
    const unsigned int* fneigh = mesh->face_neighbours(face) ;
    //split the edges or recover information from the opposite edge
//    std::cout << "edge split" << std::endl ;
    for(unsigned int edge = 0; edge < fsize; ++edge) {
      //opposite face
      const unsigned int opp_face = fneigh[edge] ;
      if(opp_face > face || opp_face == Triangulation::NO_NEIGHBOUR) {
//        std::cout << "  do split" << std::endl ;
        //the opposite face is not split, split the edge
        //get its a priori split type
        EdgeSplitType edge_type = criterion->edge_type(face, edge) ;
        //split and update the split type
        edge_type = edge_split( mesh, face, edge, radius, edge_type,
                                split_verts, edge_split_verts ) ;
        //save the plis type
        edge_types.push_back(edge_type) ;
//        std::cout << "  edge type is " << edge_type << std::endl ;
      } else {
//        std::cout << "  copy split" << std::endl ;
        //the opposite face is already split, recover edge type and vertices
        //edge vertices
        const unsigned int v0 = fverts[ edge         ] ;
        const unsigned int v1 = fverts[(edge+1)%fsize] ;
        //opposite edge index in opposite face
        const unsigned int opp_edge = mesh->edge_face_index(opp_face, v0, v1) ;
        //opposite offset
        const unsigned int opp_offset = mesh->face_offset(opp_face) ;
        //check orientation
        if(v1 == mesh->face_edge_start_vertex(opp_face, opp_edge)) {
          //opposite orientations, switch orientation in copy
          //edge type
          edge_types.push_back(
            edge_split_type_sym(edge_types[opp_offset + opp_edge])
          ) ;
          //edge_vertices
          edge_split_verts.push_back(
            edge_split_verts[2*(opp_offset + opp_edge) + 1]
          ) ;
          edge_split_verts.push_back(
            edge_split_verts[2*(opp_offset + opp_edge)    ]
          ) ;
        } else {
          //edge type
          edge_types.push_back(
            edge_types[opp_offset + opp_edge]
          ) ;
          //edge_vertices
          edge_split_verts.push_back(
            edge_split_verts[2*(opp_offset + opp_edge)    ]
          ) ;
          edge_split_verts.push_back(
            edge_split_verts[2*(opp_offset + opp_edge) + 1]
          ) ;
        }
      }
    }
    //split the face
//    std::cout << "edge type length " << edge_types.size() << std::endl ;
//    std::cout << "edge split verts length " << edge_split_verts.size() << std::endl ;
//    std::cout << "face split" << std::endl ;
    //face offset
    const unsigned int foffset = mesh->face_offset(face) ;
//    std::cout << "face offset " << foffset << std::endl ;
    face_split( mesh, face, radius,
                edge_types.data() + foffset,
                edge_split_verts.data() + 2*foffset,
                split_verts, split_faces
              ) ;
  }

//  std::cout << "face size " << split_faces.size() << std::endl ;
//  std::cout << "vert size " << split_verts.size() << std::endl ;
  //swap content
  mesh_builder->swap_vertices(split_verts) ;
  mesh_builder->swap_faces(split_faces) ;
}

//}}}

} //end of namespace Revoropt

#endif
