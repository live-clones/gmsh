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
#ifndef _REVOROPT_RVD_ACTION_HPP_
#define _REVOROPT_RVD_ACTION_HPP_

#include "polygon.hpp"

namespace Revoropt {

/* An action is triggered during the computation of the RVD, each time a
 * triangle was clipped by a Voronoi cell, on the resulting polygon. This
 * prototype is not necessarily to be used, since the action is passed via a
 * template parameter, but an action has to define the operator() in the same
 * way. */

template<typename _Triangulation>
class Action {

  public :

  /* Types and template data */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;

  /* Each polygon is decomposed into triangles, and the triangle_action is
   * applied on each of these triangles. */
  virtual void operator()( unsigned int site, unsigned int triangle,
                           const RVDPolygon<Triangulation>& polygon
                         ) = 0 ;
} ;

/* The action manager takes several actions, and groups them as a single
 * action, which runs them sequencially. */

template<typename _Triangulation>
class ActionManager {

  public :

  /* Types and template data */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;

  /* Call all the actions in sequence */
  void operator()( unsigned int site, unsigned int triangle,
                   const RVDPolygon<Triangulation>& polygon
                 ) {
    /* Call all the actions in sequence */
    for(unsigned int i=0; i<actions_.size(); ++i) {
      (*actions_[i])(site, triangle, polygon) ;
    }
  }

  /* Add new actions to be run */
  void add_action( Action<Triangulation>* action ) {
    actions_.push_back(action) ;
  }

  void clear_actions() {
    actions_.resize(0) ;
  }

  private :

  /* Storage for the actions */
  std::vector<Action<Triangulation>*> actions_ ;
  
} ;

/* Action finalization : when the RVD is fully computed, the finalize() method
 * of the action is called if it exists. The following tests whether a class has
 * a finalize method, and provides a wrapper to call it or not depending on its
 * existence. */

/* test whether a class has a finalize() method */

template< typename Wrapped >
class test_finalize {

  private :

    //used to check which of the test methods below is used
    //in the definition of the value public attribute
    typedef char yes[1] ;
    typedef char  no[2] ;

    template<typename C, int dummy = sizeof(&C::finalize)> struct check ;

    //this method can only be instanciated if Tested has void finalize()
    template <typename C> static yes &test( check<C>* ) ;
    //this method is always instanciated
    template <typename C> static no  &test(    ...    ) ;

  public:

    //if the size of the return type of the test function used here is yes
    //the first test function was instanciated, and therefore *T is legal
    static bool const value = sizeof(test<Wrapped>(0)) == sizeof(yes) ;
} ;

template<typename Wrapped, bool b>
class wrap_finalize_impl {
  public :
    static void wrap(Wrapped& wrapped) {}
} ;

template<typename Wrapped>
class wrap_finalize_impl<Wrapped, true> {
  public :
    static void wrap(Wrapped& wrapped) {
      wrapped.finalize() ;
    }
} ;

template<typename Wrapped>
void wrap_finalize(Wrapped& wrapped) {
  return wrap_finalize_impl<Wrapped, test_finalize<Wrapped>::value>::wrap(wrapped) ;
}

} //end of namespace Revoropt

#endif
