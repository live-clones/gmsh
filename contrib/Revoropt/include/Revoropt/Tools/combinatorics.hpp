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
#ifndef _REVOROPT_TOOLS_COMBINATORICS_HPP_
#define _REVOROPT_TOOLS_COMBINATORICS_HPP_

#include "meta.hpp"
#include "hash.hpp"

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <functional>

namespace Revoropt {

namespace tuplekey_impl {

//Dummy class and operator << to declare a friend function for 
//tuplekey_base when the provided type has no operator<<

struct dummy {} ;

template<int size, typename T>
std::ostream& operator<<(std::ostream&, const dummy&) ;

//Forward declarations

template<int size, typename T>
class tuplekey_base ;

template<int size, typename T>
typename std::enable_if<is_printable<T>::value,std::ostream>::type& operator<<(
  std::ostream&, const tuplekey_base<size,T>&
) ;

//Base class for tuple keys (elements in the tuple are sorted)
template<int _size, typename _T>
class tuplekey_base {
  public :

    /* Typedefs */
    enum { size = _size } ;
    typedef _T T ;

    /* Construction */
    tuplekey_base() {} ; //only here to allocate arrays of tuplekeys

    tuplekey_base(const T data[size]) {
      std::copy(data, data+size, vals) ;
      std::sort(vals, vals+size) ;
    }

    /* Printing if operator<< is defined for T */
    friend std::ostream& operator<<<size,T>( 
      std::ostream& os, 
      const typename std::conditional< 
          is_printable<T>::value,
          tuplekey_base<size,T>,
          dummy
        >::type& key 
    ) ; 

    /* Comparison */
    bool operator<(const tuplekey_base& rhs) const {
      for(unsigned int i = 0; i < size; ++i) {
        if((vals[i] < rhs.vals[i]) || (rhs.vals[i] < vals[i])) {
          return vals[i] < rhs.vals[i] ;
        }
      }
      return false ;
    }

    bool operator==(const tuplekey_base& rhs) const {
      return !((rhs < *this) || (*this < rhs)) ;
    }

    /* Values */
    const T& operator[]( unsigned int i ) const { return vals[i] ; }

    const T* values() const { return vals ; }

    T vals[size] ;
} ;


/* Printing tuples */
template<int size, typename T>
typename std::enable_if<is_printable<T>::value,std::ostream>::type& operator<<( 
  std::ostream& os, 
  const tuplekey_base<size,T>& key 
) {
  os << "[ " ;
  for(int i = 0; i < size; ++i) {
    os << key.vals[i] << " " ;
  }
  os << "]" ;
}

} //end of namespace tuplekey_impl


/* General tuple key (for any number of elements) */
template<int size, typename T=unsigned int>
class tuplekey : public tuplekey_impl::tuplekey_base<size,T> {
  typedef tuplekey_impl::tuplekey_base<size,T> Base ;
  public:
  tuplekey() : Base() {}
  tuplekey(const T data[size]) : Base(data) {}
} ;

/* Specialization for couples */
template<typename T>
class tuplekey<2,T> : public tuplekey_impl::tuplekey_base<2,T> {
  /* Typedefs */
  typedef tuplekey_impl::tuplekey_base<2,T> Base ;
  using Base::vals ;

  public:

  /* Basic construction */
  tuplekey() : Base() {}
  tuplekey(const T data[2]) : Base(data) {}

  /* Construction from a pair of values */
  tuplekey(const T &v1, const T &v2) {
    vals[0] = v1 < v2 ? v1 : v2 ;
    vals[1] = v1 < v2 ? v2 : v1 ;
  }

  /* Values */
  const T& min() const { return vals[0] ; }
  const T& max() const { return vals[1] ; }

} ;

/* Specialization for triples */
template<typename T>
class tuplekey<3,T> : public tuplekey_impl::tuplekey_base<3,T> {
  /* Typedefs */
  typedef tuplekey_impl::tuplekey_base<3,T> Base ;
  using Base::vals ;

  public:

  /* Basic construction */
  tuplekey() : Base() {}
  tuplekey(const T data[3]) : Base(data) {}

  /* Construction from a triplet of values */
  tuplekey(const T &v1, const T &v2, const T &v3) {
    if(v1 < v2) {
      vals[0] = v1 ;
      vals[1] = v2 ;
    } else {
      vals[0] = v2 ;
      vals[1] = v1 ;
    }
    if(vals[1] < v3) {
      vals[2] = v3 ;
    } else if (vals[0] < v3) {
      vals[2] = vals[1] ;
      vals[1] = v3 ;
    } else {
      vals[2] = vals[1] ;
      vals[1] = vals[0] ;
      vals[0] = v3 ;
    }
  }

  /* Values */
  const T& min() const { return vals[0] ; }
  const T& mid() const { return vals[1] ; }
  const T& max() const { return vals[2] ; }
} ;

/* Hashing */

template <int size, typename T = unsigned int>
class tuple_hash {
  public :

  std::size_t operator()( const tuplekey<size, T>& tuple ) const {
    std::size_t seed = 0 ;
    for(int i = 0; i < size; ++i) {
      hash_combine(seed, tuple[i])  ;
    }
    return seed ;
  }
} ;

} //end of namespace Revoropt

#endif
