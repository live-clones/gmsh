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
#ifndef _REVOROPT_TOOLS_EIGEN_HELPERS_HPP_
#define _REVOROPT_TOOLS_EIGEN_HELPERS_HPP_

#include <Eigen/Dense>

#include <iostream>
#include <sstream>
#include <algorithm>

namespace Revoropt {

template<typename Scalar, int Dim>
std::istream& operator>>( std::istream& in, Eigen::Matrix<Scalar,Dim,1>& v ) {
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  //save the stream position
  std::streampos in_pos = in.tellg() ;

  //load buffer
  Vector data = Vector::Constant(0) ;

  //try loading with spaces
  for(int i = 0; i<Dim; ++i) {
    if(in.good()) {
      in >> data[i] ;
    } else {
      break ;
    }
  }
  if(!in.fail()) {
    data.swap(v) ;
  } else {
    //reload backup
    in.clear() ;
    in.seekg(in_pos) ;
    std::string input ;
    in >> input ;

    std::replace(input.begin(), input.end(), ';', ' ') ;
    std::stringstream ss(input) ;

    //try copy
    for(int i = 0; i<Dim; ++i) {
      if(ss.good()) {
        ss >> data[i] ;
      } else {
        break ;
      }
    }
    if(!ss.fail()) {
      data.swap(v) ;
    }
  }
  return in ;
}

} //end of namespace Revoropt

#endif
