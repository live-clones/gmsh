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
#ifndef _REVOROPT_SOLVER_LBFGS_WRAPPER_H_
#define _REVOROPT_SOLVER_LBFGS_WRAPPER_H_

#include <lbfgs.h>

namespace Revoropt {
namespace Solver {

/** Solver encapsulation **/

class LBFGS {

  public :

  /* Types */

  typedef lbfgs_parameter_t SolverParams ;

  /** Iteration callback data **/
  
  typedef struct {
    const double* x ;    //current variable positions
    const double* g ;    //current gradient
    const double fx ;    //current value of the objective function
    const double xnorm ; //norm of x
    const double gnorm ; //norm of g
    const double step ;  //current step length
    int n ;        //size of x and g
    int k ;        //current iteration count
    int ls ;       //number of evaluations required for last iteration
  } IterData ;
  
  /** Objective function data **/
  
  typedef struct {
    const double* x ;   //current variable positions
    double* g ;   //output here the gradient of the objective function
    const int n ;       //size of x and g
    double step ; //current step length
  } EvalData ;

  /* Initialization */

  LBFGS() {
    lbfgs_parameter_init(&solver_param) ;
    solver_param.epsilon = 0 ;
    //solver_param.linesearch = LBFGS_LINESEARCH_BACKTRACKING_ARMIJO ;
    solver_param.max_linesearch = 20 ;
  }

  /* Solver interface */

  template<typename ObjFun>
  int solve( double* x, unsigned int size, 
             ObjFun* objfun, 
             unsigned int n_iter 
           ) {
    variables_ = x ;
    variables_size_ = size ;
    objfun_ = objfun ;
    solver_param.max_iterations = n_iter ;
    return solve_wrapper<ObjFun, void>(this) ;
  }

  template<typename ObjFun, typename IterCallback>
  int solve( double* x, unsigned int size, 
             ObjFun* objfun, 
             unsigned int n_iter,
             IterCallback* callback
           ) {
    variables_ = x ;
    variables_size_ = size ;
    objfun_ = objfun ;
    solver_param.max_iterations = n_iter ;
    iter_callback_ = callback ;
    return solve_wrapper<ObjFun, IterCallback>(this) ;
  }

  /* Solver parameters */

  SolverParams solver_param ;

  private :

  /* Variables */
  double* variables_ ;
  unsigned int variables_size_ ;

  /* Callbacks */

  void* objfun_ ;
  void* iter_callback_ ;

  /* Functions to be passed to lbfgs */
  template<typename ObjFun, typename IterCallback>
  static int solve_wrapper( LBFGS* instance ) ;

  template<typename IterCallback>
  static int iter_wrapper( void* instance,
                           const double* x,
                           const double* g,
                           const double fx,
                           const double xnorm,
                           const double gnorm,
                           const double step,
                           int n,
                           int k,
                           int ls
                         ) ;

  template<typename ObjFun>
  static double eval_wrapper( void* instance,
                              const double* x,
                              double* g,
                              const int n,
                              const double step
                            ) ;

} ;

template<typename ObjFun, typename IterCallback>
int LBFGS::solve_wrapper( LBFGS* instance ) {
  //solve
  return lbfgs( instance->variables_size_, 
                instance->variables_, 
                NULL,
                LBFGS::eval_wrapper<ObjFun>,
                LBFGS::iter_wrapper<IterCallback>,
                instance,
                &(instance->solver_param)
              ) ;
}

template<typename IterCallback>
int LBFGS::iter_wrapper( void* instance,
                         const double* x,
                         const double* g,
                         const double fx,
                         const double xnorm,
                         const double gnorm,
                         const double step,
                         int n,
                         int k,
                         int ls
                       ) {
  //the solver context is provided as the instance
  LBFGS* s = (LBFGS*) instance ;

  //the iteration callback is a member
  IterCallback* callback = (IterCallback*) s->iter_callback_ ;

  //call it
  LBFGS::IterData data = {x, g, fx, xnorm, gnorm, step, n, k, ls} ;
  return (*callback)(&data) ;
}

template<>
int LBFGS::iter_wrapper<void>( void* instance,
                               const double* x,
                               const double* g,
                               const double fx,
                               const double xnorm,
                               const double gnorm,
                               const double step,
                               int n,
                               int k,
                               int ls
                             ) {
  return 0 ;
}

template<typename ObjFun>
double LBFGS::eval_wrapper( void* instance,
                            const double* x,
                            double* g,
                            const int n,
                            const double step
                          ) {
  //the solver context is provided as the instance
  LBFGS* s = (LBFGS*) instance ;

  //the objective function is a member
  ObjFun* objfun = (ObjFun*) s->objfun_ ;

  //call the callback
  LBFGS::EvalData data = {x, g, n, step} ;
  const double result = (*objfun)(&data) ;
  return result ;
}

} //end of namespace Solver
} //end of namespace Revoropt

#endif

