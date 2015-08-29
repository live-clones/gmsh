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
#ifndef _REVOROPT_AABOX_FWD_HPP_
#define _REVOROPT_AABOX_FWD_HPP_

#include <Revoropt/Mesh/wrapper_fwd.hpp>

#include <vector>

//TODO bring back potential inline functions

namespace Revoropt {

template< int _Dim = 3, typename _Scalar = double >
class AABox {

  public :

  /* Typedefs */
  enum { Dim = _Dim } ;
  typedef _Scalar Scalar ;
  typedef Eigen::Matrix<Scalar, Dim, 1> Vector ;

  /* Construction */
  AABox() ;

  AABox( Scalar bounds[2*Dim] ) ;

  virtual ~AABox() {} ;

  /* Setting bounds */
  void set_bounds( Scalar bounds[2*Dim] ) ;

  //initialize a 0 volume box to a point position
  void init_to( const Scalar point[Dim] ) ;

  //increase the box size to contain the given point
  void fit_to( const Scalar point[Dim] ) ;

  //grow the box (decrease min bounds and increase max bounds) given an offset
  void grow( Scalar offset ) ;

  /* Accessing bounds */
  Scalar* axis_bounds( int axis ) ;
  Scalar& min_axis_bound( int axis ) ;
  Scalar& max_axis_bound( int axis ) ;

  const Scalar* axis_bounds( int axis ) const  ;
  const Scalar& min_axis_bound( int axis ) const  ;
  const Scalar& max_axis_bound( int axis ) const  ;

  /* Splitting */
  void split_at_pos( int axis, Scalar pos, AABox& b1, AABox& b2 ) const ;

  void split_at_ratio( int axis, Scalar ratio, AABox& b1, AABox& b2 ) const ;

  /* Point query */
  bool contains( const Scalar point[Dim] ) const ;

  /* AABox clipping */
  bool clips_aabox( const AABox<Dim,Scalar>& rhs ) const ;

  bool aabox_intersection( const AABox<Dim,Scalar>& rhs, 
                           AABox<Dim,Scalar>& output 
                         ) const ;

  /* Triangle clipping */
  template< typename Triangulation >
  bool clips_triangle_bbox( const unsigned int triangle, 
                            const Triangulation* mesh
                          ) const ;

  bool clips_triangle_bbox( const unsigned int* triangle, 
                            const Scalar* vertices
                          ) const ;

  template< typename Triangulation >
  bool triangle_intersection( const unsigned int triangle, 
                              const Triangulation* mesh,
                              std::vector<Scalar>& output
                            ) const ;

  bool triangle_intersection( const unsigned int* triangle, 
                              const Scalar* vertices,
                              std::vector<Scalar>& output
                            ) const ;

  template< typename Triangulation >
  bool clips_triangle( const unsigned int triangle, 
                       const Triangulation* mesh 
                     ) const ;

  bool clips_triangle( const unsigned int* triangle, 
                       const Scalar* vertices 
                     ) const ;

  protected :

  Scalar bounds_[2*Dim] ;

  /** Triangle intersection internals **/

  /* during intersections, vertex types */
  enum VertexType { 
    ORIGINAL_V, //an original vertex of a triangle
    EDGE_V, //intersection between a triangle edge and a box side
    FACE_V //intersection between a triangle and two box sides
  } ;

  /* during intersections, edge types */
  enum EdgeType {
    ORIGINAL_E, //a piece of a triangle edge
    BOUNDARY_E //the intersection between a boundary and the triangle
  } ;

  /* during intersection, symbolic representation of the polygon vertices */
  template< typename Triangulation>
  class ClipVertex {

    public :

    VertexType type ;

    //symbolic vertex, depending on the type :
    // - ORIGINAL_V : the index of the vertex, and 0,0
    // - EDGE_V : the index of the edge, the offset of the intersection, 0
    // - FACE_V : 0 as index, barycentric coordinates of the intersection
    int symi ;
    Scalar symd[2] ;

    //symbolic edge starting t the vertex
    EdgeType edge_type ;
    //depending on the type of symbolic edge :
    // - ORIGINAL_E : the index of the triangle edge
    // - BOUNDARY_E : the index of the boundary
    int esym ;

    // determine if the vertex coordinate determined by axis is in the bounds
    // returns +1 if over bounds, 0 if in bounds, and -1 is below bounds

    int in_bounds( int axis, const Scalar bounds[2], 
                   const unsigned int triangle, const Triangulation* mesh
                 ) ;

    void position( const unsigned int triangle,
                   const Triangulation* mesh,
                   Scalar* output 
                 ) ;
  } ;

  template< typename Triangulation >
  void fill_edge_vertex( int bound_index,
                         int edge_index,
                         const unsigned int triangle,
                         const Triangulation* mesh,
                         ClipVertex<Triangulation>& target
                       ) const ;

  template< typename Triangulation >
  void fill_face_vertex( int bound_index1,
                         int bound_index2,
                         const unsigned int triangle,
                         const Triangulation* mesh,
                         ClipVertex<Triangulation>& target
                       ) const ;

  /* during intersection, symbolic polygon representing the clipped triangle */
  /* template typedef would be nicer */
  template< typename Triangulation >
  class Polygon : public std::vector< ClipVertex<Triangulation> > {} ;

  /* intersection initialization */
  template< typename Triangulation >
  void init_intersection( Polygon<Triangulation>& polygon ) const ;

  /* clip the polygon along one axis */
  template< typename Triangulation >
  void clip_by_axis( int axis, Polygon<Triangulation>& polygon, 
                     const unsigned int triangle, 
                     const Triangulation* mesh
                   ) const ;

  //mesh wrapper
  typedef ROMeshWrapper<3,Dim,Scalar> WrapMesh ;

  static const unsigned int NO_NEIGHBOUR = WrapMesh::NO_NEIGHBOUR ;

  //neighbour array for easy mesh wrapping
  static const unsigned int no_neighbours[3] ;
} ;

template< int Dim, typename Scalar>
const unsigned int AABox<Dim, Scalar>::no_neighbours[3] = 
  {NO_NEIGHBOUR, NO_NEIGHBOUR, NO_NEIGHBOUR} ;

} //end of namespace Revoropt

#endif
