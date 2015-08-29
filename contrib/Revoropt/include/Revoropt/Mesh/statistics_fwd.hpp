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
#ifndef _REVOROPT_MESH_STATISTICS_H_
#define _REVOROPT_MESH_STATISTICS_H_

namespace Revoropt {

/* Angles */

template<typename Mesh>
void face_angles( const Mesh* mesh, typename Mesh::Scalar* angles ) ;

template<typename Mesh>
void triangle_quality( const Mesh* mesh, typename Mesh::Scalar* qualities ) ;

/* Edge lengths */
//inner edges are twice accounted for

template<typename Mesh>
void edge_lengths( const Mesh* mesh, typename Mesh::Scalar* lengths ) ;

/* Histogram */

template<typename Scalar>
void histogram( const Scalar* data, unsigned int size, 
                Scalar min, Scalar max, unsigned int bins, 
                unsigned int* output
              ) ;

template<typename Scalar>
void histogram( const Scalar* data, unsigned int size, 
                Scalar min, Scalar max, unsigned int bins, 
                const char* filename
              ) ;

} //end of namespace Revoropt

#endif
