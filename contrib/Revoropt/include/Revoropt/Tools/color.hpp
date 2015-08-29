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
#ifndef _REVOROPT_TOOLS_COLOR_HPP_
#define _REVOROPT_TOOLS_COLOR_HPP_

#include <cstdlib>

namespace Revoropt {

//generate random bright colors
template<typename Scalar>
void random_bright_color(Scalar* output) {
  //random hsv with value 1
  Scalar h = (Scalar) rand() / (Scalar) RAND_MAX ;
  h *= 6 ;
  Scalar s = (Scalar) rand() / (Scalar) RAND_MAX ;
  s = 0.5*s + 0.5 ;
  Scalar v = (Scalar) rand() / (Scalar) RAND_MAX ;
  v = 0.5*v+0.5 ;

  int hi = (int) h ;
  Scalar hr = h - hi ;

  Scalar l = v*(1-s) ;
  Scalar m = v*(1-hr*s);
  Scalar n = v*(1-(1-hr)*s);

  if(h<1) {
    output[0] = v ;
    output[1] = n ;
    output[2] = l ;
  } else if(h<2) {
    output[0] = m ;
    output[1] = v ;
    output[2] = l ;
  } else if(h<3) {
    output[0] = l ;
    output[1] = v ;
    output[2] = n ;
  } else if(h<4) {
    output[0] = l ;
    output[1] = m ;
    output[2] = v ;
  } else if(h<5) {
    output[0] = n ;
    output[1] = l ;
    output[2] = v ;
  } else {
    output[0] = v ;
    output[1] = l ;
    output[2] = m ;
  }
}

//generate bright colormaps
template<typename Scalar>
void generate_bright_colormap(unsigned int size, Scalar* output) {
  for(unsigned int i = 0; i < size; ++i) {
    random_bright_color(output + 3*i) ;
  }
}

} //end of namespace Revoropt

#endif
