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
#ifndef _REVOROPT_RVD_RDT_HPP_
#define _REVOROPT_RVD_RDT_HPP_

#include <unordered_set>
#include <iostream>

#include "rvd.hpp"
#include "polygon.hpp"
#include <Revoropt/Tools/combinatorics.hpp>
#include <Revoropt/Mesh/builder_def.hpp>

namespace Revoropt {

/* Build a restricted Delaunay triangulation */

template<typename _Triangulation>
class RDTBuilder : public Action<_Triangulation> {

  public :

  /* Types and template data */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;
  typedef tuplekey<3> Triangle ;
  typedef tuple_hash<3> hasher ;
  typedef RVDVertex<Triangulation> Vertex ;

  RDTBuilder( std::vector<unsigned int>& output_triangles
            ) : triangles_(output_triangles) {
  }
  
  /* Reset */
  void reset() {
    built_triangles_.clear() ;
  }

  /* Action for to use on the RVD */
  void operator()( unsigned int site,
                   unsigned int triangle,
                   const RVDPolygon<Triangulation>& polygon
                 ) {
    //size of the polygon
    unsigned int size = polygon.size() ;
    if(size<3) return ;

    //build and add the triangles
    for(unsigned int i=0; i<size; ++i) {
      const RVDVertex<Triangulation>& v = polygon[i].vertex ;
      if(v.config() == Vertex::FACE_VERTEX) {
        unsigned int v1 = v.combinatorics()[3] ;
        unsigned int v2 = v.combinatorics()[4] ;
        unsigned int v3 = v.combinatorics()[5] ;

        Triangle key(v1,v2,v3) ;

        std::unordered_set<Triangle, hasher>::iterator it ;
        it = built_triangles_.find(key) ;
        if(it == built_triangles_.end()) {
          triangles_.push_back(v1) ; 
          triangles_.push_back(v2) ; 
          triangles_.push_back(v3) ; 
          built_triangles_.insert(key) ;
        }
      }
    }
  }

  private :

  /* Structure to avoid creating twice the same triangle */
  std::unordered_set<Triangle, hasher> built_triangles_ ;

  /* computed triangles are stored in a vector*/
  std::vector<unsigned int>& triangles_ ;

} ;

} //end of namespace Revoropt

#endif
