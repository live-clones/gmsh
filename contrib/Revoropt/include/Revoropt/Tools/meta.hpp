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
#ifndef _REVOROPT_TOOLS_META_HPP_
#define _REVOROPT_TOOLS_META_HPP_

#include <iostream>
#include <type_traits>

namespace Revoropt {

/* test whether the operator<< for a type exists */

namespace is_printable_impl {

  typedef char yes[1] ;
  typedef char  no[2] ;

  struct any_t {
    template<typename T> any_t( const T& ) ;
  } ;

  no& operator<<(std::ostream const&, const any_t&) ;

  yes& test( std::ostream& ) ;
  no&  test( no& ) ;

  template<typename T>
  struct is_printable {
    static std::ostream &s ;
    static const T& t ;
    static const bool value = sizeof(test((s<<t))) == sizeof(yes) ;
  } ;
}

template<typename T>
struct is_printable : is_printable_impl::is_printable<T> {
} ;

/* automatic dereferencement */
/* here be dragons */

template <typename T>
class is_dereferenceable
{
    //used to check which of the test methods below is used
    //in the definition of the value public attribute
    typedef char yes[1] ;
    typedef char  no[2] ;

    //this class is only instanciated when *C is legal
    template <typename C, int sz = sizeof(**static_cast<C*>(NULL))>
    struct check {} ;

    //this method can only be instanciated if *C is legal
    template <typename C> static yes &test( check<C>* ) ;
    //this method is always instanciated
    template <typename C> static no  &test(    ...    ) ;

  public:
    //if the size of the return type of the test function used here is yes
    //the first test function was instanciated, and therefore *T is legal
    static bool const value = sizeof(test<T>(0)) == sizeof(yes) ;
} ;

template<typename T>
class is_dereferenceable<T&>
{
  public:
  static bool const value = is_dereferenceable<T>::value ;
} ;

/* base type of a pointing chain */

//one dereferencement
//basic case, fallback when T is non dereferenceable : no type field
template<typename T, bool chk = false>
struct one_deref_type_impl {
} ;

//case when T is a reference non dereferenceable
template<typename T>
struct one_deref_type_impl<T&,false> {
} ;

//basic case for dereferenceables
//only works for (references to) iterators and pointers
template<typename T>
struct one_deref_type_impl<T,true> {
  typedef typename one_deref_type_impl<
    typename std::iterator_traits<T>::pointer,
    true
  >::type type ;
} ;

//case for pointers
template<typename T>
struct one_deref_type_impl<T*,true> {
  typedef T type ;
} ;

//case for references to dereferenceables
template<typename T>
struct one_deref_type_impl<T&,true> {
  typedef typename one_deref_type_impl<T,true>::type type ;
} ;

//case for const dereferenceables
template<typename T>
struct one_deref_type_impl<T const,true> {
  typedef typename one_deref_type_impl<T,true>::type type ;
} ;

//encapsulation to mask the boolean attribute, and prevent bad usage : 
//providing true with T being not dereferenceable
template<typename T>
struct one_deref_type {
  //use the implementation backend
  typedef typename one_deref_type_impl<
    T, 
    is_dereferenceable<T>::value
  >::type type ;
} ;

//full dereferencement
//basic case, fallback when T is non dereferenceable
template<typename T, bool chk = false>
struct full_deref_type_impl {
  typedef T type ;
} ;

//case when T is dereferenceable
template<typename T>
struct full_deref_type_impl<T, true> {
  //get the basic type of T dereferenced once
  typedef typename full_deref_type_impl<
    //define the type of T dereferenced once
    typename one_deref_type<T>::type,
    //check whether T dereferenced once is still dereferenceable
    is_dereferenceable<typename one_deref_type<T>::type>::value
  >::type type ;
} ;

//encapsulation to mask the boolean attribute, and prevent bad usage : 
//providing true with T being not dereferenceable
template<typename T>
struct full_deref_type {
  //use the implementation backend
  typedef typename full_deref_type_impl<
    T, 
    is_dereferenceable<T>::value
  >:: type type ;
} ;

/* full dereferencement */

//basic case, fallback when T us not dereferenceable
template<typename T, bool chk = true>
class full_deref_impl {
  public:
  //take a reference to the value provided to the constructor
  full_deref_impl( T& _value ) : value(_value) {} ;
  T& value ;
} ;

//case when T is dereferenceable
template<typename T>
class full_deref_impl<T,true> {
  //define the type of T dereferenced once
  //only works for pointers and iterators
  typedef typename one_deref_type<T>::type deref_type ;
  public:
  //get the fully dereferenced value of _value dereferenced once
  full_deref_impl( T _value ) : value(
    //recursive call
    full_deref_impl<
      deref_type, 
      //check that T dereferenced once is stille dereferenceable
      is_dereferenceable<deref_type>::value
    >(*_value).value
  ) {} ;
  //reference on the fully dereferenced value
  typename full_deref_type<T>::type& value ;
} ;

//encapsulation in a function, performing full dereferencement,
//masking the template parameter by automatic deduction

//case when the provided type is dereferenceable : no reference
template<typename T>
typename std::enable_if<
  is_dereferenceable<T>::value,
  typename full_deref_type<T>::type&
>::type full_deref( T dereferenceable ) {
  //use the implementation backend
  return full_deref_impl<
    T, 
    is_dereferenceable<T>::value
  >(dereferenceable).value ;
}

//case when the provided type is not dereferenceable : reference
template<typename T>
typename std::enable_if<
  !is_dereferenceable<T>::value,
  T&
>::type full_deref( T& non_dereferenceable ) {
  //use the implementation backend
  return non_dereferenceable ;
}

} //end of namespace Revoropt

#endif
