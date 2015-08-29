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
#ifndef _REVOROPT_RVD_CLIPPER_HPP_
#define _REVOROPT_RVD_CLIPPER_HPP_

#include "polygon.hpp"

namespace Revoropt {

/** Interface for clipping polygons by Voronoï cells **/

template<typename _Triangulation>
class Clipper {

  public :

  /* Types and template data */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef typename Triangulation::Scalar Scalar ;
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  /* Initialization */
  Clipper() : sites_(NULL), sites_size_(0), mesh_(NULL) {} ;

  Clipper( const Scalar* sites, unsigned int sites_size,
           const Triangulation* mesh 
         ) : sites_(sites), sites_size_(sites_size), mesh_(mesh) {
  }

  virtual ~Clipper() {}

  /* Given the polygon, the site, the site and vertex positions, update the
   * polygon by clipping it by the Voronoï cell of the site. Beware that calling
   * this function several times on the same triangle / site couple without
   * running the reset method may lead to bad behaviour.*/

  virtual void clip_by_cell( RVDPolygon<Triangulation>& polygon, 
                             unsigned int triangle,
                             unsigned int site
                           ) = 0 ;

  /* Given a query point, provide the nearest site */
  virtual unsigned int nearest_site( const Scalar* query ) = 0 ;

  /* Updating the sites and mesh */
  virtual void set_sites( const Scalar* sites, 
                             unsigned int sites_size 
                        ) {
    sites_ = sites ;
    sites_size_ = sites_size ;
  }

  virtual void set_mesh( const Triangulation* mesh ) {
    mesh_ = mesh ;
  }

  /* Providing sites and mesh */
  const Scalar* sites() { return sites_ ; }
  unsigned int sites_size() { return sites_size_ ; }
  const Triangulation* mesh() {return mesh_ ; }

  /* resetting internal data of the clipper */
  virtual void reset() {} ;

  protected :

  /* Sites */
  const Scalar* sites_ ;
  unsigned int sites_size_ ;

  /* Mesh */
  const Triangulation* mesh_ ;

} ;

} //end of namespace Revoropt

#endif
