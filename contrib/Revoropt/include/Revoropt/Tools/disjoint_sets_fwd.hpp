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
#ifndef _REVOROPT_TOOLE_DISJOINT_SETS_H_
#define _REVOROPT_TOOLE_DISJOINT_SETS_H_

#include <vector>
#include <unordered_map>
#include <functional>

namespace Revoropt {

struct uf_node {
  unsigned int rep ;
  unsigned int rank ;
} ;

template< typename T, typename hasher = std::hash<T> >
class DisjointSets {

  public :

  static const unsigned int NO_CLASS ;

  /* Construction */
  
  DisjointSets() {} ;

  /* Manipulation */

  unsigned int insert( const T& item ) ;
  bool contains( const T& item ) ;

  /* Operations */

  unsigned int merge_classes( unsigned int c1, unsigned int c2 ) ;
  unsigned int merge_items( const T& item1, const T& item2 ) ;

  unsigned int get_rep( unsigned int c ) ;
  unsigned int item_class( const T& item ) ;

  private :

  unsigned int get_rank( unsigned int c ) ;
  void set_rank(unsigned int c, unsigned int rank) ;
  void set_rep( unsigned int c, unsigned int rep ) ;

  std::vector<uf_node> nodes_ ;
  std::unordered_map<T, unsigned int, hasher> items_ ;
  typedef typename std::unordered_map<
      T, unsigned int, hasher
    >::iterator item_it ;

} ;

} //end of namespace Revoropt

#endif
