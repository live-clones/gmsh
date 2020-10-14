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
#ifndef _REVOROPT_MESH_NORMALS_FWD_HPP_
#define _REVOROPT_MESH_NORMALS_FWD_HPP_

#include <Revoropt/Tools/normals_def.hpp>
#include <Revoropt/Neighbours/neighbourhood_def.hpp>

#include <Eigen/Dense>
#include <cassert>
#include <cmath>
#include <vector>

namespace Revoropt {

/* Face normal */
template<typename Mesh>
void face_normal ( const Mesh* mesh,
                   unsigned int index,
                   typename Mesh::Scalar* output
                 ) {
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //face_size
  const unsigned int fsize = mesh->face_size(index) ;
  //face vertex indices
  const unsigned int* fverts = mesh->face(index) ;

  //call triangle normal
  for(unsigned int i = 1; i<fsize-1; ++i) {
    const Scalar n_len = triangle_normal( mesh->vertex(fverts[0]),
                                          mesh->vertex(fverts[i]),
                                          mesh->vertex(fverts[i+1]),
                                          output
                                        ) ;
    if(n_len !=0) return ;
  }
}

/* Connected normals (based on the faces connected to the vertex) */
template<typename Mesh>
void connected_vertex_normals( const Mesh* mesh,
                               typename Mesh::Scalar* output
                             ) {
  assert((Mesh::VertexDim == 3) && "normals are only defined for 3D meshes") ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;
  //average normals on vertices
  for(unsigned int face; face < mesh->faces_size(); ++face) {
    //number of vertices for this face
    const unsigned int fsize = mesh->face_size(face) ;
    if(fsize < 3) continue ;
    //get the normal of the face
    Vector fnormal ;
    face_normal(mesh,face,fnormal.data()) ;
    if(fnormal.dot(fnormal) == 0) continue ;
    //vertex indices of the face
    const unsigned int* fverts = mesh->face(face) ;
    //add the weighted normal for each vertex
    for(unsigned int vertex = 0; vertex < fsize; ++vertex) {
      const unsigned int previndex = fverts[(vertex+fsize-1)%fsize] ;
      const unsigned int currindex = fverts[ vertex               ] ;
      const unsigned int nextindex = fverts[(vertex      +1)%fsize] ;
      Eigen::Map<const Vector> vprev(mesh->vertex(previndex)) ;
      Eigen::Map<const Vector> vcurr(mesh->vertex(currindex)) ;
      Eigen::Map<const Vector> vnext(mesh->vertex(nextindex)) ;
      //normal weight for this vertex
      const Vector e1 = (vprev-vcurr) ;
      const Scalar e1_len = e1.norm() ;
      const Vector e2 = (vcurr-vnext) ;
      const Scalar e2_len = e2.norm() ;
      if(e1_len*e2_len != 0) {
        Scalar angle_cos = -e1.dot(e2)/(e1_len*e2_len) ;
        angle_cos = std::min(angle_cos,1.) ;
        angle_cos = std::max(angle_cos,-1.) ;
        const Scalar angle = acos(angle_cos) ;
        //add the face contribution to the vertex
        Eigen::Map<Vector> vnormal(output + 3*currindex) ;
        vnormal += angle*fnormal ;
      }
    }
  }
  //normalize vertex normals
  for(unsigned int vertex = 0; vertex < mesh->vertices_size(); ++vertex) {
    Eigen::Map<Vector> vnormal(output + 3*vertex) ;
    Scalar vnormal_len = vnormal.norm() ;
    if(vnormal_len != 0) {
      vnormal /= vnormal_len ;
    }
  }
}

/* Action passed to a neighbourhood computer to compute robust normals */
template<typename Triangulation>
class NeighNormalCompute {

  public :

  //normals are only for dimension 3
  typedef char normals_only_meaningful_for_dimension_3[
    Triangulation::VertexDim==3 ? 1 : -1
  ] ;

  //scalar and vector
  typedef typename Triangulation::Scalar Scalar ;
  typedef Eigen::Matrix<Scalar,3,1> Vector ;

  NeighNormalCompute( const Triangulation* mesh,
                      const Scalar* queries,
                      const unsigned int* indices,
                      Scalar radius,
                      Scalar* output,
                      bool translate_queries = true
                    ) : mesh_(mesh),
                        queries_(queries),
                        indices_(indices),
                        translate_queries_(translate_queries),
                        radius_(radius),
                        output_(output) {} ;

  NeighNormalCompute( const Triangulation* mesh,
                      const Scalar* queries,
                      Scalar radius,
                      Scalar* output
                    ) : mesh_(mesh),
                        queries_(queries),
                        indices_(NULL),
                        translate_queries_(false),
                        radius_(radius),
                        output_(output) {} ;

  void operator()( unsigned int query,
                   unsigned int triangle
                 ) {
    //position of the query
    const unsigned int q_in_index = translate_queries_ ? indices_[query] : query ;
    const Scalar* q = queries_ +3*q_in_index ;

    //vertices of the triangle
    const unsigned int* tverts = mesh_->face(triangle) ;

    //area of the triangle portion within a ball
    //of the provided radius around the query
    const Scalar clip_area = triangle_sphere_intersection_area<3>(
      mesh_->vertex(tverts[0]),
      mesh_->vertex(tverts[1]),
      mesh_->vertex(tverts[2]),
      q,
      radius_
    ) ;

    if(clip_area == 0) return ;

    //normal of the mesh triangle
    Vector normal ;
    face_normal(mesh_, triangle, normal.data()) ;

    //add the contribution to the normalif the normal is not 0
    if(normal.dot(normal) != 0) {
      const unsigned int q_out_index = indices_ == NULL ? query : indices_[query] ;
      Eigen::Map<Vector> n_out(output_ + 3*q_out_index) ;
      n_out += clip_area*normal ;
    }
  }

  private :

  const Triangulation* mesh_ ;
  const Scalar* queries_ ;
  const unsigned int* indices_ ;
  bool translate_queries_ ;
  Scalar radius_ ;
  Scalar* output_ ;

} ;

/* Robust normals on boundary vertices (handling disconnected meshes) */
template<typename Mesh>
void robust_vertex_normals( const Mesh* mesh,
                            typename Mesh::Scalar radius,
                            typename Mesh::Scalar* output
                          ) {
  assert((Mesh::VertexDim == 3) && "normals are only defined for 3D meshes") ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,3,1> Vector ;

  //compute normals based on connectivity
  connected_vertex_normals(mesh,output) ;

  //for boundary normals, use the geometric neighbourhood instead
  //get boundary vertices
  std::vector<unsigned int> boundary_vertices ;
  std::vector<bool> boundary_flag(mesh->vertices_size(),false) ;
  //iterate over faces
  for(unsigned int face = 0; face < mesh->faces_size(); ++face) {
    //size of the face
    const unsigned int fsize = mesh->face_size(face) ;
    //vertices of the face
    const unsigned int* vertices = mesh->face(face) ;
    //neighbours of the face
    const unsigned int* neighbours = mesh->face_neighbours(face) ;
    //circulate around the face to find border vertices
    for(unsigned int edge = 0; edge < fsize; ++edge) {
      //test if the edge is a boundary edge
      if(neighbours[edge] == Mesh::NO_NEIGHBOUR) {
        //boundary edge get its vertices
        const unsigned int v1 = vertices[ edge         ] ;
        const unsigned int v2 = vertices[(edge+1)%fsize] ;
        //mark vertices as handled, and add them to the list
        if(!boundary_flag[v1]) {
          boundary_vertices.push_back(v1) ;
        }
        if(!boundary_flag[v2]) {
          boundary_vertices.push_back(v2) ;
        }
      }
    }
  }
  //cleanup
  std::vector<bool>().swap(boundary_flag) ;

  //check if any vertex is on the boundary
  const unsigned int bvsize = boundary_vertices.size() ;
  if(bvsize > 0) {
    //get the boundary vertices coordinates
    std::vector<Scalar> queries(3*bvsize) ;
    for(unsigned int vertex = 0; vertex < bvsize; ++vertex) {
      const unsigned int v = boundary_vertices[vertex] ;
      std::copy(mesh->vertex(v), mesh->vertex(v)+3, queries.data() + 3*vertex) ;
      for(int i = 0;i < 3; ++i) {
        output[3*v+i] = 0 ;
      }
    }

    //compute normals on geometric neighbourhoods
    NeighbourhoodComputer<Mesh> n_computer(mesh,queries.data(),bvsize) ;
    NeighNormalCompute<Mesh> action( mesh,
                                     queries.data(),
                                     radius,
                                     output
                                   ) ;
    n_computer.compute(radius,action) ;

    //normalize the boundary vertex normals
    for(unsigned int vertex = 0; vertex < bvsize; ++vertex) {
      const unsigned int v = boundary_vertices[vertex] ;
      Eigen::Map<Vector> normal(output + 3*v) ;
      const Scalar n_len = normal.norm() ;
      if(n_len != 0) {
        normal /= n_len ;
      }
    }
  }
}

/* Robust normals on every vertex */
template<typename Mesh>
void full_robust_vertex_normals( const Mesh* mesh,
                                 typename Mesh::Scalar radius,
                                 typename Mesh::Scalar* output
                               ) {
  assert((Mesh::VertexDim == 3) && "normals are only defined for 3D meshes") ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,3,1> Vector ;

  const Scalar* queries ;
  std::vector<Scalar> vertex_copy ;
  if(Mesh::VertexOffset == 0) {
    queries = mesh->vertices() ;
  } else {
    //the vertex array is has an offset, copy the vertices
    for(unsigned int vertex = 0; vertex < mesh->vertices_size() ; ++vertex) {
      const Scalar* v = mesh->vertex(vertex) ;
      vertex_copy.insert(vertex_copy.end(), v, v+3) ;
    }
    queries = vertex_copy.data() ;
  }
  //compute normals on geometric neighbourhoods
  NeighbourhoodComputer<Mesh> n_computer( mesh,
                                          queries,
                                          mesh->vertices_size()
                                        ) ;
  NeighNormalCompute<Mesh> action( mesh,
                                   queries,
                                   radius,
                                   output
                                 ) ;
  n_computer.compute(radius,action) ;

  //normalize the vertex normals
  for(unsigned int vertex = 0; vertex < mesh->vertices_size(); ++vertex) {
    Eigen::Map<Vector> normal(output + 3*vertex) ;
    const Scalar n_len = normal.norm() ;
    if(n_len != 0) {
      normal /= n_len ;
    }
  }
}

/* Connected edge normals based on the mesh connectivty */
template< typename Mesh >
void connected_edge_normals( const Mesh* mesh,
                             typename Mesh::Scalar* output
                           ) {
  assert((Mesh::VertexDim == 3) && "normals are only defined for 3D meshes") ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;

  //face normals
  std::vector<Scalar> face_normals(3*mesh->faces_size(), 0) ;
  for(unsigned int face = 0; face < mesh->faces_size(); ++face) {
    //number of vertices/edges for this face
    const unsigned int fsize = mesh->face_size(face) ;
    if(fsize < 3) continue ;
    face_normal(mesh,face,face_normals.data() + 3*face) ;
  }

  //edge layer
  EdgeLayer<Mesh> edge_layer(mesh) ;

  //edge normals
  for(unsigned int edge = 0; edge < mesh->face_vertices_size(); ++edge) {
    Eigen::Map<Vector> enormal(output + 3*edge) ;
    //face of the edge
    const unsigned int eface = edge_layer.edge_face(edge) ;
    //add the face contribution
    Eigen::Map<const Vector> fnormal(face_normals.data() + 3*eface) ;
    enormal += fnormal ;
    //test if the edge is on the boundary
    if(!edge_layer.is_border(edge)) {
      //not on boundary, opposite edge and face
      const unsigned int oedge = edge_layer.edge_opposite(edge) ;
      const unsigned int oface = edge_layer.edge_face(oedge) ;
      //add the opposite face contribution
      Eigen::Map<const Vector> ofnormal(face_normals.data() + 3*oface) ;
      enormal += ofnormal ;
      //normalize
      const Scalar n_len = enormal.norm() ;
      if(n_len != 0) {
        enormal /= n_len ;
      }
    }
  }
}

/* Robust edge normals */
template<typename Mesh>
void robust_edge_normals( const Mesh* mesh,
                          typename Mesh::Scalar radius,
                          typename Mesh::Scalar* output
                        ) {
  assert((Mesh::VertexDim == 3) && "normals are only defined for 3D meshes") ;
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,3,1> Vector ;

  //compute normals based on connectivity
  connected_edge_normals(mesh,output) ;

  //for boundary edge normals, use the geometric neighbourhood instead
  //collect boundary edges, and their midpoint
  std::vector<unsigned int> boundary_edges ;
  std::vector<Scalar> edge_midpoints ;
  //edge layer
  EdgeLayer<Mesh> edge_layer(mesh) ;
  for(unsigned int edge = 0; edge < mesh->face_vertices_size(); ++edge) {
    if(edge_layer.is_border(edge)) {
      //add the edge to the boundary edges
      boundary_edges.push_back(edge) ;
      //vertices of the edge
      const unsigned int v0 = edge_layer.edge_start_vertex(edge) ;
      const unsigned int v1 = edge_layer.edge_end_vertex(edge) ;
      Eigen::Map<const Vector> v0_pos(mesh->vertex(v0)) ;
      Eigen::Map<const Vector> v1_pos(mesh->vertex(v1)) ;
      //add its midpoint
      const unsigned int midpos = edge_midpoints.size() ;
      edge_midpoints.resize(midpos+3) ;
      Eigen::Map<Vector> midpoint(edge_midpoints.data() + midpos) ;
      midpoint = 0.5*(v0_pos + v1_pos) ;
    }
  }

  //check if any edge is on the boundary
  const unsigned int besize = boundary_edges.size() ;
  if(besize > 0) {
    //reset the edge normals of the boundary edges
    for(unsigned int e_index = 0; e_index < boundary_edges.size(); ++e_index) {
      const unsigned int edge = boundary_edges[e_index] ;
      for(int i = 0; i < 3; ++i) {
        output[3*edge+i] = 0 ;
      }
    }

    //compute normals on geometric neighbourhoods
    NeighbourhoodComputer<Mesh> n_computer( mesh,
                                            edge_midpoints.data(),
                                            besize
                                          ) ;
    NeighNormalCompute<Mesh> action( mesh,
                                     edge_midpoints.data(),
                                     boundary_edges.data(),
                                     radius,
                                     output,
                                     false
                                   ) ;
    n_computer.compute(radius,action) ;

    //normalize the boundary edge normals
    for(unsigned int e_index = 0; e_index < boundary_edges.size(); ++e_index) {
      const unsigned int edge = boundary_edges[e_index] ;
      Eigen::Map<Vector> normal(output + 3*edge) ;
      const Scalar n_len = normal.norm() ;
      if(n_len != 0) {
        normal /= n_len ;
      }
    }
  }
}

} //end of namespace Revoropt

#endif
