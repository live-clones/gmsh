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
#ifndef _REVOROPT_NEIGHBOURHOOD_DEF_HPP_
#define _REVOROPT_NEIGHBOURHOOD_DEF_HPP_

#include "neighbourhood_fwd.hpp"
#include "aabox_def.hpp"

#include <assert.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

namespace Revoropt {

template< typename Triangulation >
bool NeighbourhoodComputer<Triangulation>::CircularLexicoCompare::operator()( 
  unsigned int i1, unsigned int i2 
) {
  const Scalar* q1 = queries_ + Dim*i1 ;
  const Scalar* q2 = queries_ + Dim*i2 ;
  for( int i = 0; i<Dim; ++i) {
    const int coord = (axis_+i)%Dim ;
    if(q1[coord] != q2[coord]) return (q1[coord] < q2[coord]) ;
  }
  return i1 < i2 ;
}

template< typename Triangulation >
void NeighbourhoodComputer<Triangulation>::init_sorted_queries() {
  //create and sort indices arrays for each axis
  for(int axis = 0; axis < Dim; ++axis) {
    sorted_indices_[axis].resize(queries_size_) ;
    for(unsigned int i = 0; i < queries_size_; ++i) {
      sorted_indices_[axis][i] = i ;
    }
    std::sort( sorted_indices_[axis].begin(),
               sorted_indices_[axis].end(),
               CircularLexicoCompare(queries_,axis)
             ) ;
  }
}

template< typename Triangulation >
void NeighbourhoodComputer<Triangulation>::split_sorted_queries( 
  int axis, unsigned int begin, unsigned int end 
) {
  //Split the queries in range [begin,end) in two along the provided axis.
  //All the lists along other axes are reordered according to the split.
  //After the reordering, all the lists contain the same sets of sorted
  //indices between [begin,mid) and [mid,end) with mid = 0.5*(begin + end)

  //index of the medial query point along axis
  const unsigned int mid_index = sorted_indices_[axis][(begin+end)/2] ;
  //comparison corresponding to the axis
  CircularLexicoCompare comp(queries_, axis) ;

  //temporary array to filter the lists
  std::vector<unsigned int> filtered_indices(end - begin) ;
  //indices used to fill the filtered_indices_array
  unsigned int low_index, high_index ;
  //filter the sorted lists of all the axes
  for(int i = 0; i < Dim; ++i) {
    //the splitting axis is already split and sorted correctly
    if(axis == i) continue ;
    //initialize filling indices
    low_index = 0 ;
    high_index = (end-begin)/2 ;
    //filter
    for(unsigned int q = begin; q < end; ++q) {
      const unsigned int index = sorted_indices_[i][q] ;
      if(comp(index,mid_index)) {
        filtered_indices[low_index] = index ;
        ++low_index ;
      } else {
        filtered_indices[high_index] = index ;
        ++high_index ;
      }
    }
    //overwrite the indices
    std::copy( filtered_indices.begin(),
               filtered_indices.end(),
               sorted_indices_[i].data()+begin
             ) ;
  }
}

template< typename Triangulation >
void NeighbourhoodComputer<Triangulation>::compute_queries_bbox( 
  Scalar radius, unsigned int q_begin, unsigned int q_end, Box& bbox_out
) {
  //initialize the bounding box
  const unsigned int init_index = sorted_indices_[0][q_begin] ;
  const Scalar* init_query = queries_ + Dim*init_index ;
  bbox_out.init_to(init_query) ;
  //iterate over the remaining queries
  for(unsigned int i = q_begin+1; i < q_end; ++i) {
    const unsigned int index = sorted_indices_[0][i] ;
    const Scalar* query = queries_ + Dim*index ;
    bbox_out.fit_to(query) ;
  }
  //consider the radius around the query points
  bbox_out.grow(radius) ;
}

template< typename Triangulation >
void NeighbourhoodComputer<Triangulation>::init_triangle_indices() {
  //allocate space
  t_indices_.resize(mesh_->faces_size()) ;
  //initialize the list of indices
  for(unsigned int i = 0; i < t_indices_.size(); ++i) {
    t_indices_[i] = i ;
  }
}

template< typename Triangulation >
unsigned int NeighbourhoodComputer<Triangulation>::filter_triangle_indices( 
  const Box& box, unsigned int t_end 
) {
  //sanity check
  assert((t_end>0) && "the number ot triangles is zero or negative") ;
  //positions
  unsigned int t_in = 0 ;
  unsigned int t_out = t_end-1 ;
  //iterate over the triantles
  while(t_in <= t_out) {
    if(box.clips_triangle_bbox(t_indices_[t_in], mesh_)) {
      ++t_in ;
    } else {
      //std::cout << t_in << " " << t_out << " " << std::endl ;
      if(t_in != t_out) {
        std::swap(t_indices_[t_in],t_indices_[t_out]) ;
      } else {
        //std::cout << "skip swap" << std::endl ;
      }
      if(t_out == 0) break ;
      --t_out ;
    }
  }
  //return the end of the triangles clipping the box
  return t_in ;
}

template< typename Triangulation >
template < typename Action >
void NeighbourhoodComputer<Triangulation>::compute_internal( 
  Scalar radius, 
  Action& action,
  unsigned int q_begin,
  unsigned int q_end,
  unsigned int t_end
) {
  assert((q_end>q_begin) && "the query interval is empty or reversed") ;
  //test the number of remaining queries
  if((q_end-q_begin) == 1) { //one single query
    /*
    //compute the box around the query
    Box box ;
    compute_queries_bbox(radius,q_begin,q_end,box) ;
    //initialize a polygon to clip the triangles
    std::vector<Scalar> polygon ;
    //clip each triangle
    for(unsigned int t = 0; t < t_end; ++t) {
      //get the triangle from its index
      const unsigned int* triangle = mesh_->face(t_indices_[t]) ;
      //clip it really (not just the bounding box)
      bool clips = 
        box.triangle_intersection(triangle,mesh_->vertices(),polygon) ;
      if(clips) {
        //perform the action on the clipping
        action(sorted_indices_[0][q_begin],polygon) ;
      }
    }
    */
    //perform the action on all the triangles remaining for the unique query
    for(unsigned int t = 0; t < t_end; ++t) {
      action(sorted_indices_[0][q_begin], t_indices_[t]) ;
    }
  } else { //several queries
    //compute the bounding box of the queries
    Box full_box ;
    compute_queries_bbox(radius,q_begin,q_end,full_box) ;
    //find the longest axis
    unsigned int major_axis = 0 ;
    Scalar major_size = 
      full_box.max_axis_bound(0) = full_box.min_axis_bound(0) ;
    for(int axis = 1; axis < Dim; ++axis) {
      const Scalar len =
        full_box.max_axis_bound(axis) = full_box.min_axis_bound(axis) ;
      if(len > major_size) {
        major_size = len ;
        major_axis = axis ;
      }
    }
    //split the queries along the longest axis
    const unsigned int q_mid = (q_begin + q_end)/2 ;
    split_sorted_queries(major_axis,q_begin,q_end) ;
    //bounding boxes of the two parts
    Box b1, b2 ;
    compute_queries_bbox(radius,q_begin,q_mid,b1) ;
    compute_queries_bbox(radius,q_mid,q_end,b2) ;
    //compute the triangle sets of the first box
    unsigned int t_limit = filter_triangle_indices(b1,t_end) ;
    //handle the first box
    if(t_limit != 0) {
      compute_internal(radius,action,q_begin,q_mid,t_limit) ;
    }
    //compute the triangle sets of the second box
    t_limit = filter_triangle_indices(b2,t_end) ;
    //handle the second box
    if(t_limit != 0) {
      compute_internal(radius,action,q_mid,q_end,t_limit) ;
    }
  }
}

} //end of namespace Revoropt

#endif
