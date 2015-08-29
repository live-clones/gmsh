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
#ifndef _REVOROPT_MESH_SPLITTING_FWD_HPP_
#define _REVOROPT_MESH_SPLITTING_FWD_HPP_

#include "all_fwd.hpp"
#include "debug_fwd.hpp"
#include "connectivity_fwd.hpp"

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
               ) ;

/* Split an edge of a mesh builder. If the provided arrays are not NULL, returns
 * the indices and sizes of the new faces. The size of the arrays to provide is 
 * two in case of a border edge, and 4 otherwise.*/
template<typename MeshBuilder>
void edge_split( MeshBuilder* mesh, 
                 unsigned int face, 
                 unsigned int edge_index,
                 unsigned int* split_face_indices = NULL //output
                ) ;
/* Tools */
namespace Decimate {
  
  /* An edge index with its length, vertices, and face information */
  template<typename Scalar>
  class HeapEdge {
    public :
  
    /* A face connected to the edge */
    unsigned int face ;

    /* The index of the edge in that face */
    unsigned int edge ;

    /* Sorted vertices of the edge */
    unsigned int vmin, vmax ;

    /* Length of the edge */
    Scalar length ;
  
    bool operator<(const HeapEdge& rhs) {
      //in case of equality, use vertex indices
      if(length == rhs.length) {
        if(vmax == rhs.vmax) {
          return vmin < rhs.vmin ;
        } else {
          return vmax < rhs.vmax ;
        }
      }
      return length < rhs.length ;
    }
  } ;

} //end of namespace Decimate

template<typename Mesh, typename MeshBuilder>
void split_longest_edge( const Mesh* input, 
                         unsigned int niter, 
                         MeshBuilder* mesh
                       ) ;
//}}}

/**{{{ Normal bevel : split triangles to improve normal interpolation **/

namespace Bevel {

/* edge split types */
enum EdgeSplitType { 
  SPLIT_NONE = 0, 
  SPLIT_FIRST = 1, 
  SPLIT_SECOND = 2, 
  SPLIT_BOTH = 3 
} ;

/* face split types */
struct FaceSplitType {
  unsigned int index ;
  unsigned int rotation ;
  bool symetry ;
} ;

const unsigned int NO_VERTEX = -1 ;

/* criterion based on the normal to decide whether an edge needs splitting */
template<typename Mesh>
class NormalSplitCriterion {

  public :
  /* Typedefs */
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type (dimension 3 since we are dealing with normals)
  typedef Eigen::Matrix<Scalar,3,1> Vector ;

  /* Construction */
  NormalSplitCriterion(const Mesh* mesh) : 
    cosine_threshold_(0.85),
    bevel_radius_(0.002),
    normal_radius_(0.001),
    restrict_to_boundary_(false),
    mesh_(mesh)
  {
    init() ;
  }

  /* Parameters */

  void set_cosine_threshold( Scalar threshold ) {
    cosine_threshold_ = threshold ;
  }

  Scalar cosine_threshold() const {
    return cosine_threshold_ ;
  }

  void set_bevel_radius( Scalar in_radius ) {
    bevel_radius_ = in_radius ;
  }

  void set_normal_radius( Scalar in_radius ) {
    normal_radius_ = in_radius ;
  }

  Scalar bevel_radius() const {
    return bevel_radius_ ;
  }

  void set_boundary_restriction( bool status ) {
    restrict_to_boundary_ = status ;
  }

  bool restrict_to_boundary() {
    return restrict_to_boundary_ ;
  }

  /* Decision */

  EdgeSplitType edge_type( unsigned int face, unsigned int edge ) const ;
  private :

  /* Initialization */
  void init() ;

  /* Parameters */
  Scalar cosine_threshold_ ;
  Scalar bevel_radius_ ;
  Scalar normal_radius_ ;
  bool restrict_to_boundary_ ;

  /* Mesh */
  const Mesh* mesh_ ;

  //FIXME
  public :
  /* Edge midpoints */
  std::vector<Scalar> edge_midpoints_ ;

  /* Edge normals */
  std::vector<Scalar> edge_normals_ ;

  /* Vertex normals */
  std::vector<Scalar> vertex_normals_ ;

  /*Boundary vertices*/
  std::vector<bool> boundary_vertices_ ;

} ;

/* test criterion based on the triangle and edge indices */
template<typename Mesh>
class TestSplitCriterion {

  public:

  EdgeSplitType edge_type( unsigned int face, unsigned int edge ) const {
    int res = face/150 ;
    for(int i = 0; i < edge; ++i) {
      res /= 4 ;
    }
    return (EdgeSplitType) (res%4) ;
  }

} ;

/* criterion always requiring split */
class TrueSplitCriterion {

  public:

  EdgeSplitType edge_type( unsigned int face, unsigned int edge ) const {
    return SPLIT_BOTH ;
  }

} ;

/* given the type of an edge, type of the oppositely oriented edge*/
EdgeSplitType edge_split_type_sym( EdgeSplitType type ) {
  static const EdgeSplitType sym[4] = { SPLIT_NONE, 
                                        SPLIT_SECOND, 
                                        SPLIT_FIRST, 
                                        SPLIT_BOTH
                                      } ;
  return sym[type] ;
}

/* triangle classification, depending on its edges split types */
void normalize_triangle_split( const EdgeSplitType edge_types[3],
                               FaceSplitType* split_type //output
                             ) ;
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
                        ) ;

/* split a face given its split type and the edge split vertices */
template<typename Mesh>
void face_split( const Mesh* mesh,
                 unsigned int face,
                 typename Mesh::Scalar radius,
                 const EdgeSplitType edge_types[3],
                 const unsigned int edge_split_verts[6],
                 std::vector<typename Mesh::Scalar>& coords, //output
                 std::vector<unsigned int>& split_faces //output
               ) ;

} //end of namespace Bevel

template< typename Triangulation, 
          typename TriangulationBuilder, 
          typename Criterion >
void bevel( const Triangulation* mesh, 
            const Criterion* criterion, 
            typename Triangulation::Scalar radius,
            TriangulationBuilder* mesh_builder //output
          ) ;
//}}}

} //end of namespace Revoropt

#endif
