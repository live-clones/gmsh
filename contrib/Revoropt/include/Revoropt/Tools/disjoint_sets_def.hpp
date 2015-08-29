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
#include "disjoint_sets_fwd.hpp"

namespace Revoropt {

template<typename T, typename hasher>
const unsigned int DisjointSets<T, hasher>::NO_CLASS = -1 ;

/* Manipulation */

template<typename T, typename hasher>
unsigned int DisjointSets<T, hasher>::insert( const T& item ) {
  item_it it = items_.find(item) ;
  if(it != items_.end()) {
    return it->second ;
  } else {
    unsigned int index = nodes_.size() ;
    uf_node item_node = { .rep = index, .rank = 1 } ;
    nodes_.push_back(item_node) ;
    items_[item] = index ;
    return index ;
  }
}

template<typename T, typename hasher>
bool DisjointSets<T, hasher>::contains( const T& item ) {
  return items_.find(item) != items_.end() ;
}

/* Operations */

template<typename T, typename hasher>
unsigned int DisjointSets<T, hasher>::item_class( const T& item ) {
  item_it it = items_.find(item) ;
  return it == items_.end() ? NO_CLASS : get_rep(it->second) ;
}

template<typename T, typename hasher>
unsigned int DisjointSets<T, hasher>::merge_classes( 
    unsigned int c1, 
    unsigned int c2 
    ) {
  //get class representatives
  const unsigned int c1_rep = get_rep(c1) ;
  const unsigned int c2_rep = get_rep(c2) ;
  //if the classes are already merged, do nothing
  if(c1_rep == c2_rep) return c1_rep ;

  //merge
  //get the class ranks
  const unsigned int c1_rank = get_rank(c1_rep) ;
  const unsigned int c2_rank = get_rank(c2_rep) ;
  if(c1_rank < c2_rank) {
    //tree for c2 is deeper, use c2 as root
    set_rep(c1_rep, c2_rep) ;
    return c2_rep ;
  } else if(c2_rank < c1_rank) {
    //tree for c1 is deeper, use c1 as root
    set_rep(c2_rep, c1_rep) ;
    return c1_rep ;
  } else {
    //trees have the same depth, use c1 as root and increase its depth
    set_rep(c2_rep, c1_rep) ;
    set_rank(c1_rep, c1_rank+1) ;
    return c1_rep ;
  }
}

template<typename T, typename hasher>
unsigned int DisjointSets<T, hasher>::merge_items( 
    const T& item1, 
    const T& item2 
    ) {
  const unsigned int c1 = item_class(item1) ;
  if(c1 == NO_CLASS) return NO_CLASS ;
  const unsigned int c2 = item_class(item2) ;
  if(c2 == NO_CLASS) return NO_CLASS ;
  return merge_classes(c1, c2) ;
}
 
template<typename T, typename hasher>
unsigned int DisjointSets<T, hasher>::get_rep( unsigned int c ) {
  if(nodes_[c].rep != c) {
    //the element is within a class with a different root
    nodes_[c].rep = get_rep(nodes_[c].rep) ;
  }
  //return the representative
  return nodes_[c].rep ;
}

template<typename T, typename hasher>
void DisjointSets<T, hasher>::set_rep( unsigned int c, unsigned int rep ) {
  nodes_[c].rep = rep ;
}

template<typename T, typename hasher>
unsigned int DisjointSets<T, hasher>::get_rank( unsigned int c ) {
  return nodes_[c].rank ;
}

template<typename T, typename hasher>
void DisjointSets<T, hasher>::set_rank( unsigned int c, unsigned int rank ) {
  nodes_[c].rank = rank ;
}

} //end of namespace Revoropt
