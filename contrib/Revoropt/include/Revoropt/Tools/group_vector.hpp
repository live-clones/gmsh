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
#ifndef _REVOROPT_TOOLS_GROUP_VECTOR_HPP_
#define _REVOROPT_TOOLS_GROUP_VECTOR_HPP_

#include "container_wrapper.hpp"

#include <map>
#include <vector>
#include <string>

namespace Revoropt {

template<typename T>
class group_vector {

  public :

    /* Typedefs */
    typedef T value_type ;
    typedef typename composite<T>::iterator iterator ;
    typedef typename composite<T>::const_iterator const_iterator ;

    /* Construction, destruction */
    group_vector() {
      all_contained_.push_back(self_contained_) ;
    }

    /* Iteration */
    iterator begin() {
      return all_contained_.begin() ;
    }

    const_iterator begin() const {
      return all_contained_.begin() ;
    }

    iterator end() {
      return all_contained_.end() ;
    }

    const_iterator end() const {
      return all_contained_.end() ;
    }

    /* Content management */
    void insert(T* t) {
      self_contained_.push_back(t) ;
    }

    template< typename Container >
    void insert_group( const std::string& name, Container& container ) {
      groups_[name] = all_contained_.push_back(container) ;
    }

    template< typename Tp >
    void insert_group( const std::string& name, Tp begin, Tp end ) {
      groups_[name] = all_contained_.push_back(begin, end) ;
    }
    
    void erase_group( const std::string& name ) {
      g_iterator it = groups_.find(name) ;
      if(it != groups_.end()) {
        all_contained_.erase(it->second) ;
      }
    }

  protected :

    /* Wrapped container for groups */
    composite<T> all_contained_ ;

  private :
    /* Inner container for individual elements */
    std::vector<T*> self_contained_ ;

    /* Group management */
    typedef typename std::map<
      std::string, 
      typename composite<T>::sub_iterator
    >::iterator g_iterator ;
    std::map<
      std::string, 
      typename composite<T>::sub_iterator
    > groups_ ;
} ;

} //end of namespace Revoropt

#endif
