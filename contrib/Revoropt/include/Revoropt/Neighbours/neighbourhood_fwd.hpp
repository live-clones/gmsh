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
#ifndef _REVOROPT_NEIGHBOURHOOD_FWD_HPP_
#define _REVOROPT_NEIGHBOURHOOD_FWD_HPP_

#include <Revoropt/Neighbours/aabox_fwd.hpp>

namespace Revoropt {

/** An action performed on a neighbourhood **/

class NeighbourhoodAction {

  public :

  virtual void operator()( unsigned int query, 
                           unsigned int triangle 
                         ) = 0 ;

} ;

/** A neighbourhood computer **/

template< typename Triangulation >
class NeighbourhoodComputer {

  public :

  /* Typedefs and enums */
  enum { Dim = Triangulation::VertexDim } ;
  typedef typename Triangulation::Scalar Scalar ;
  typedef AABox<Dim,Scalar> Box ;

  NeighbourhoodComputer( const Triangulation* mesh,
                         const Scalar* queries,
                         unsigned int queries_size
                       ) : mesh_(mesh), 
                           queries_(queries), 
                           queries_size_(queries_size) {
  }

  /* Computing the neighbourhoods, applying the action on them */
  template< typename Action >
  void compute( Scalar radius, Action& action ) {
    //initialize query indices arrays sorted along each axis
    init_sorted_queries() ;
    init_triangle_indices() ;
    compute_internal(radius,action) ;
  }

  private :

  /* Mesh */
  const Triangulation* mesh_ ;

  /* Queries */
  const Scalar* queries_ ;
  unsigned int queries_size_ ;

  /* Query indices sorted along all the axis */
  std::vector<unsigned int> sorted_indices_[Dim] ;

  class CircularLexicoCompare {
    //lexicographic comparison of queries from their indices
    public :
    //construction
    CircularLexicoCompare( const Scalar* queries, int axis ) 
      : queries_(queries), axis_(axis) {
    }
    //comparison
    bool operator()( unsigned int i1, unsigned int i2 ) ;
    private :
    //query points
    const Scalar* queries_ ;
    //first axis for the lexical order
    unsigned int axis_ ;

  } ;

  void init_sorted_queries() ;

  //Split the queries in range [begin,end) in two along the provided axis.
  //All the lists along other axes are reordered according to the split.
  //After the reordering, all the lists contain the same sets of sorted
  //indices between [begin,mid) and [mid,end) with mid = 0.5*(begin + end)
  void split_sorted_queries( int axis, unsigned int begin, unsigned int end ) ;

  /* Compute the bounding box of a set of query points */
  void compute_queries_bbox( Scalar radius, 
                             unsigned int q_begin, 
                             unsigned int q_end,
                             Box& bbox_out
                           ) ;

  /* Initialize the set of triangle indices */
  void init_triangle_indices() ;

  /* Filter a set of triangles to keep only the ones intersecting a box */
  unsigned int filter_triangle_indices( const Box& box, 
                                        unsigned int t_end 
                                      ) ;

  /* Recursively compute the robust normals */
  template< typename Action >
  void compute_internal( Scalar radius, Action& action) {
    compute_internal(radius,action,0,queries_size_,mesh_->faces_size()) ;
  }

  template< typename Action >
  void compute_internal( Scalar radius, Action& action,
                         unsigned int q_begin,
                         unsigned int q_end,
                         unsigned int t_end
                       ) ;

  std::vector<unsigned int> t_indices_ ;

} ;

} //end of namespace Revoropt

#endif
