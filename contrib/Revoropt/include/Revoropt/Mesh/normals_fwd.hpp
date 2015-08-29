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
#ifndef _REVOROPT_MESH_NORMALS_FWD_HPP_
#define _REVOROPT_MESH_NORMALS_FWD_HPP_

namespace Revoropt {

/* Face normal */
template<typename Mesh>
void face_normal ( const Mesh* mesh, 
                   unsigned int index, 
                   typename Mesh::Scalar* output 
                 ) ;

/* Connected normals (based on the faces connected to the vertex) */
template<typename Mesh>
void connected_vertex_normals( const Mesh* mesh, 
                               typename Mesh::Scalar* output 
                             ) ;

/* Robust normals on boundary vertices (handling disconnected meshes) */
template<typename Mesh>
void robust_vertex_normals( const Mesh* mesh, 
                            typename Mesh::Scalar radius,
                            typename Mesh::Scalar* output
                          ) ;

/* Robust normals on every vertex */
template<typename Mesh>
void full_robust_vertex_normals( const Mesh* mesh, 
                                 typename Mesh::Scalar radius,
                                 typename Mesh::Scalar* output
                               ) ;

/* Connected edge normals baseg on the mesh connectivty */
template< typename Mesh >
void connected_edge_normals( const Mesh* mesh, 
                             typename Mesh::Scalar* output 
                           ) ;

/* Robust edge normals */
template<typename Mesh>
void robust_edge_normals( const Mesh* mesh, 
                          typename Mesh::Scalar radius,
                          typename Mesh::Scalar* output
                        ) ;

} //end of namespace Revoropt

#endif
