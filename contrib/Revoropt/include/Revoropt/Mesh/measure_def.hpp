#ifndef _REVOROPT_MESH_MEASURE_DEF_HPP_
#define _REVOROPT_MESH_MEASURE_DEF_HPP_

#include "measure_fwd.hpp"

#include <Revoropt/Tools/measure_def.hpp>
#include <Revoropt/Neighbours/neighbourhood_def.hpp>

#include <Eigen/Dense>

namespace Revoropt {

/*{{{ Area */

/* Area of a face of a mesh */
template<typename Mesh>
typename Mesh::Scalar mesh_face_area(const Mesh* mesh, unsigned int face) {
  //scalar type
  typedef typename Mesh::Scalar Scalar ;

  //result
  double area = 0 ;

  //iterate over the faces
  unsigned int fsize = mesh->face_size(face) ;
  const unsigned int* fverts = mesh->face(face) ;
  for(unsigned int v = 1; v < fsize-1; ++v) {
    area += triangle_area<Mesh::VertexDim,Scalar>(
              mesh->vertex(fverts[0]),
              mesh->vertex(fverts[v]),
              mesh->vertex(fverts[v+1])
            ) ;
  }

  return area ;
}

/* Area of a mesh */
template<typename Mesh>
typename Mesh::Scalar mesh_area(const Mesh* mesh) {
  //scalar type
  typedef typename Mesh::Scalar Scalar ;

  //the area will be stored here
  Scalar area = 0 ;

  //iterate over the faces
  for(unsigned int face = 0; face < mesh->faces_size(); ++face) {
    area += mesh_face_area(mesh, face) ;
  }

  return area ;
}

//}}}

/*{{{ Edge length */

template< typename Mesh >
typename Mesh::Scalar edge_length_from_vertices( const Mesh* mesh,
                                                 unsigned int v0,
                                                 unsigned int v1
                                               ) {
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;
  //vertex positions
  Eigen::Map<const Vector> v0_pos(mesh->vertex(v0)) ;
  Eigen::Map<const Vector> v1_pos(mesh->vertex(v1)) ;
  //length
  return (v1_pos-v0_pos).norm() ;
}

template< typename Mesh >
typename Mesh::Scalar edge_length_from_face_index( const Mesh* mesh,
                                                   unsigned int face,
                                                   unsigned int edge
                                                 ) {
  //edge vertex indices
  const unsigned int v0 = mesh->face_edge_start_vertex(face, edge) ;
  const unsigned int v1 = mesh->face_edge_end_vertex(face, edge) ;
  return edge_length_from_vertices(mesh,v0,v1) ;
}

/* Longest edge of a face */

template< typename Mesh >
unsigned int face_longest_edge( const Mesh* mesh,
                                unsigned int face,
                                typename Mesh::Scalar* output_length
                              ) {
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //size of the face
  const unsigned int face_size = mesh->face_size(face) ;
  //initialization
  unsigned int longest_edge = 0 ;
  Scalar longest_length = 0 ;
  //iterate over the edges
  for(unsigned int edge = 0; edge < face_size; ++edge) {
    //length
    Scalar length = edge_length_from_face_index(mesh, face, edge) ;
    //update
    if(length == longest_length) {
      //decide depending on edge vertices in lexicographic order
      const unsigned int v0 = mesh->face_edge_start_vertex(face, edge) ;
      const unsigned int v1 = mesh->face_edge_end_vertex(face, edge) ;
      const unsigned int v2 = mesh->face_edge_start_vertex(face, longest_edge) ;
      const unsigned int v3 = mesh->face_edge_end_vertex(face, longest_edge) ;
      const unsigned int v0_min = v0 < v1 ? v0 : v1 ;
      const unsigned int v0_max = v0 < v1 ? v1 : v0 ;
      const unsigned int v1_min = v2 < v3 ? v2 : v3 ;
      const unsigned int v1_max = v2 < v3 ? v3 : v2 ;
      if(v0_max == v1_max) {
        if(v0_min > v1_min) {
          longest_edge = edge ;
          longest_length = length ;
        }
      } else if(v0_max > v1_max){
        longest_edge = edge ;
        longest_length = length ;
      }

    } else if(length > longest_length) {
      longest_edge = edge ;
      longest_length = length ;
    }
  }
  //result
  if(output_length != NULL) {
    *output_length = longest_length ;
  }
  return longest_edge ;
}

/* Longest edge of a mesh */
template< typename Mesh >
void mesh_longest_edge_vertices( const Mesh* mesh,
                                 unsigned int* v0,
                                 unsigned int* v1,
                                 typename Mesh::Scalar* output_length
                               ) {
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //initialization
  unsigned int longest_face = 0 ;
  unsigned int longest_edge = 0 ;
  Scalar longest_length = 0 ;
  //variables  to store edges and lengths
  unsigned int edge ;
  Scalar length ;
  for(unsigned int face = 0; face < mesh->faces_size(); ++face) {
    //longest edge of the face
    edge = face_longest_edge(mesh, face, &length) ;
    if(length > longest_length) {
      longest_face = face ;
      longest_edge = edge ;
      longest_length = length ;
    }
  }
  //result
  if(output_length != NULL) {
    *output_length = longest_length ;
  }
  return mesh->face_edge_vertices(longest_face,longest_edge,v0,v1) ;
}

//}}}

/*{{{ Angles */

template<typename Mesh>
typename Mesh::Scalar face_angle_cos( const Mesh* mesh,
                                      unsigned int face,
                                      unsigned int vertex
                                    ) {
  //size of the face
  const unsigned int fsize = mesh->face_size(face) ;
  //vertices of the face
  const unsigned int* fverts = mesh->face(face) ;
  //previous and next vertex
  const unsigned int prev = fverts[(vertex+fsize-1) % fsize] ;
  const unsigned int next = fverts[(vertex      +1) % fsize] ;
  //angle cosine
  return angle_cos<Mesh::VertexDim>( mesh->vertex(vertex),
                                     mesh->vertex(prev),
                                     mesh->vertex(next)
                                   ) ;
}

//}}}

/*{{{ Normalization */

template<typename Mesh>
void normalize_mesh( Mesh* mesh, double* out_center, double* out_scale ) {
  //typedefs
  typedef typename Mesh::Scalar Scalar ;
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;
  //compute the new center
  Vector center = Vector::Zero() ;
  for(unsigned int i=0; i<mesh->vertices_size(); ++i) {
    Eigen::Map<const Vector> x(mesh->vertex(i)) ;
    center += x ;
  }
  center /= mesh->vertices_size() ;

  if(out_center) {
    for(int i = 0; i < 3; ++i) {
      out_center[i] = center[i] ;
    }
  }

  //center the mesh
  for(unsigned int i=0; i<mesh->vertices_size(); ++i) {
    Eigen::Map<Vector> x(mesh->vertex(i)) ;
    x -= center ;
  }

  //compute the scene radius
  Scalar radius = 0 ;
  for(unsigned int i=0; i<mesh->vertices_size(); ++i) {
    Eigen::Map<const Vector> x(mesh->vertex(i)) ;
    radius = std::max(radius,(center - x).norm()) ;
  }

  //scale the mesh
  for(unsigned int i=0; i<mesh->vertices_size(); ++i) {
    Eigen::Map<Vector> x(mesh->vertex(i)) ;
    x /= radius ;
  }

  if(out_scale) {
    *out_scale = radius ;
  }

  mesh->set_dirty() ;
}

//}}}

/*{{{ Distance to a mesh */

/* Action passed to a neighbourhood computer to compute normals */
template<typename Triangulation>
class NeighDistanceCompute {

  public :

  //scalar type, dimension and vector
  typedef typename Triangulation::Scalar Scalar ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  NeighDistanceCompute( const Triangulation* mesh,
                        const Scalar* queries,
                        const unsigned int* indices,
                        Scalar* output,
                        bool translate_queries = true
                      ) : mesh_(mesh),
                          queries_(queries),
                          indices_(indices),
                          output_(output),
                          translate_queries_(translate_queries) {} ;

  NeighDistanceCompute( const Triangulation* mesh,
                        const Scalar* queries,
                        Scalar* output
                      ) : mesh_(mesh),
                          queries_(queries),
                          indices_(NULL),
                          output_(output),
                          translate_queries_(false) {} ;

  void operator()( unsigned int query,
                   unsigned int triangle
                 ) {
    //position of the query
    const unsigned int q_in_index =
      translate_queries_ ? indices_[query] : query ;
    const Scalar* qp = queries_ +Dim*q_in_index ;
    Eigen::Map<const Vector> qv(qp) ;

    //vertices of the triangle
    const unsigned int* tverts = mesh_->face(triangle) ;
    Eigen::Map<const Vector> x0(mesh_->vertex(tverts[0])) ;
    Eigen::Map<const Vector> x1(mesh_->vertex(tverts[1])) ;
    Eigen::Map<const Vector> x2(mesh_->vertex(tverts[2])) ;

    //distance of the query to the triangle
    Scalar uv[2] ;
    point_in_triangle<Dim, Scalar>( qp, x0.data(), x1.data(), x2.data(), uv ) ;
    const Scalar distance = (uv[0]*x0+uv[1]*x1+(1-uv[0]-uv[1])*x2 - qv).norm() ;

    //assign the minimum distance
    const unsigned int q_out_index =
      indices_ == NULL ? query : indices_[query] ;
    output_[q_out_index] =
      distance < output_[q_out_index] ? distance : output_[q_out_index] ;
  }

  private :

  const Triangulation* mesh_ ;
  const Scalar* queries_ ;
  const unsigned int* indices_ ;
  bool translate_queries_ ;
  Scalar* output_ ;

} ;

template<typename Mesh>
void mesh_distances( const Mesh* mesh,
                     typename Mesh::Scalar* queries,
                     unsigned int queries_size,
                     typename Mesh::Scalar radius,
                     typename Mesh::Scalar* output
                   ) {
  //typedefs
  enum { Dim = Mesh::VertexDim, Offset = Mesh::VertexOffset } ;
  typedef typename Mesh::Scalar Scalar ;
  typedef ROMesh<3, Dim, Scalar, Offset> Triangulation ;

  //initialize the distance array
  for(unsigned int i = 0; i < queries_size; ++i) {
    output[i] = 2*radius ;
  }

  //wrap the mesh as a triangle mesh
  ROTriangulationWrapper<Dim, Scalar, Offset> trimesh(mesh) ;

  //use the neighbourhoods of the queries
  NeighbourhoodComputer<Triangulation> n_computer(
    &trimesh, queries, queries_size
  ) ;
  NeighDistanceCompute<Triangulation> action(&trimesh, queries, output) ;
  n_computer.compute(radius, action) ;
}

//}}}

/**{{{ Gradient of the mesh area wrt. its vertices **/

template<typename Triangulation>
void mesh_area_gradient(
    const Triangulation* mesh,
    double* output,
    double factor
    ) {
  typedef typename Triangulation::Scalar Scalar ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<Scalar, Dim, 1> Vector ;

  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    //flag for degenerate triangle
    bool degenerate = false ;
    //vertices of the triangle
    const unsigned int* fverts = mesh->face(f) ;

    //edges of the triangle
    Vector edges[3] ;
    Scalar e_len[3] ;
    for(unsigned int v = 0; v < 3; ++v) {
      Eigen::Map<const Vector> x0(mesh->vertex(fverts[v])) ;
      Eigen::Map<const Vector> x1(mesh->vertex(fverts[(v+1)%3])) ;
      edges[v] = x1 - x0 ;
      e_len[v] = edges[v].norm() ;
      degenerate |= (e_len[v] == 0) ;
      if(degenerate) break ;
    }
    if(degenerate) continue ;

    //heights of the triangle
    Vector heights[3] ;
    Scalar h_len[3] ;
    for(unsigned int v = 0; v < 3; ++v) {
      const Scalar& base_len = e_len[(v+1)%3] ;
      const Vector& base = edges[(v+1)%3] ;
      heights[v] = edges[(v+2)%3]
                 - edges[(v+2)%3].dot(base) * base / (base_len*base_len) ;
      h_len[v] = heights[v].norm() ;
      degenerate |= (h_len[v] == 0) ;
      if(degenerate) break ;
    }
    if(degenerate) continue ;

    //fill the gradient for the appropriate variables
    for(unsigned int v = 0; v < 3; ++v) {
      Eigen::Map<Vector> g(output + Dim*fverts[v]) ;
      g += factor * 0.5 * e_len[(v+1)%3] * heights[v] / h_len[v] ;
    }

  }

}

//}}}

} //end of namespace Revoropt

#endif
