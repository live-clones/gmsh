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
#ifndef _REVOROPT_AABOX_DEF_HPP_
#define _REVOROPT_AABOX_DEF_HPP_

#include "aabox_fwd.hpp"

#include <algorithm>

namespace Revoropt {

template< int Dim , typename Scalar >
AABox<Dim,Scalar>::AABox() {
  //initialize to an empty box
  if(Dim == 0) return ;
  bounds_[0] = 1 ;
  bounds_[1] = 1 ;
} ;

template< int Dim , typename Scalar >
AABox<Dim,Scalar>::AABox( Scalar bounds[2*Dim] ) { 
  set_bounds(bounds) ;
  std::copy(bounds, bounds+2*Dim, bounds_) ; 
} ;

/* Setting bounds */
template< int Dim , typename Scalar >
void AABox<Dim,Scalar>::set_bounds( Scalar bounds[2*Dim] ) {
  std::copy(bounds, bounds+2*Dim, bounds_) ; 
}

//initialize a 0 volume box to a point position
template< int Dim , typename Scalar >
void AABox<Dim,Scalar>::init_to( const Scalar point[Dim] ) {
  for(int axis = 0; axis < Dim; ++axis) {
    bounds_[2*axis  ] = point[axis] ;
    bounds_[2*axis+1] = point[axis] ;
  }
}

//increase the box size to contain the given point
template< int Dim , typename Scalar >
void AABox<Dim,Scalar>::fit_to( const Scalar point[Dim] ) {
  for(int axis = 0; axis < Dim; ++axis) {
    bounds_[2*axis  ] = std::min(point[axis],bounds_[2*axis  ]) ;
    bounds_[2*axis+1] = std::max(point[axis],bounds_[2*axis+1]) ;
  }
}

//grow the box (decrease min bounds and increase max bounds) given an offset
template< int Dim , typename Scalar >
void AABox<Dim,Scalar>::grow( Scalar offset ) {
  for(int axis = 0; axis < Dim; ++axis) {
    bounds_[2*axis  ] -= offset ;
    bounds_[2*axis+1] += offset ;
  }
}

/* Accessing bounds */
template< int Dim , typename Scalar >
Scalar* AABox<Dim,Scalar>::axis_bounds( int axis ) { 
  return bounds_ + 2*axis ; 
} ;
template< int Dim , typename Scalar >
Scalar& AABox<Dim,Scalar>::min_axis_bound( int axis ) { 
  return bounds_[2*axis  ] ; 
} ;
template< int Dim , typename Scalar >
Scalar& AABox<Dim,Scalar>::max_axis_bound( int axis ) { 
  return bounds_[2*axis+1] ; 
} ;

template< int Dim , typename Scalar >
const Scalar* AABox<Dim,Scalar>::axis_bounds( int axis ) const { 
  return bounds_ + 2*axis ; 
} ;
template< int Dim , typename Scalar >
const Scalar& AABox<Dim,Scalar>::min_axis_bound( int axis ) const { 
  return bounds_[2*axis  ] ; 
} ;
template< int Dim , typename Scalar >
const Scalar& AABox<Dim,Scalar>::max_axis_bound( int axis ) const { 
  return bounds_[2*axis+1] ; 
} ;

/* Splitting */
template< int Dim , typename Scalar >
void AABox<Dim,Scalar>::split_at_pos( int axis, 
                                      Scalar pos, 
                                      AABox& b1, 
                                      AABox& b2 
                                    ) const {
  //copy the bounds
  std::copy(bounds_, bounds_+2*Dim, b1.bounds_) ;
  std::copy(bounds_, bounds_+2*Dim, b2.bounds_) ;
  //reduce the split boxes according to the split position
  b1.bounds_[2*axis] = bounds_[2*axis] ;
  b1.bounds_[2*axis+1] = std::min(pos,bounds_[2*axis+1]) ;
  b2.bounds_[2*axis] = std::max(pos,bounds_[2*axis]) ;
  b2.bounds_[2*axis+1] = bounds_[2*axis+1] ;
  //note that in case pos is outside the range, one box will be the current
  //box while the other will be empty (max bound is below min bound)
}

template< int Dim , typename Scalar >
void AABox<Dim,Scalar>::split_at_ratio( int axis, 
                                        Scalar ratio, 
                                        AABox& b1, 
                                        AABox& b2 
                                      ) const {
  //split position
  Scalar pos = (1-ratio)*bounds_[2*axis] + ratio*bounds_[2*axis+1] ;
  //split
  split_at_pos(axis,pos,b1,b2) ;
}

/* Point query */
template< int Dim , typename Scalar >
bool AABox<Dim,Scalar>::contains( const Scalar point[Dim] ) const {
  //test for every dimension
  for(int axis=0; axis<Dim; ++axis) {
    if((point[axis] < bounds_[2*axis]) || (point[axis] > bounds_[2*axis+1])) {
      return false ;
    }
  }
  //beware that a box of dimension 0 contains anything
  return true ;
}

/* AABox clipping */
template< int Dim , typename Scalar >
bool AABox<Dim,Scalar>::clips_aabox( const AABox<Dim,Scalar>& rhs ) const {
  //for each axis check that the intervals intersect
  for(int axis=0; axis<Dim; ++axis) {
    Scalar bmin = std::max(bounds_[2*axis  ],rhs.bounds_[2*axis  ]) ;
    Scalar bmax = std::min(bounds_[2*axis+1],rhs.bounds_[2*axis+1]) ;
    if(bmax < bmin) return false ;
  }
  return true ;
}

template< int Dim , typename Scalar >
bool AABox<Dim,Scalar>::aabox_intersection( const AABox<Dim,Scalar>& rhs, 
                                            AABox<Dim,Scalar>& output 
                                          ) const {
  //for each axis check that the intervals intersect
  for(int axis=0; axis<Dim; ++axis) {
    Scalar bmin = std::max(bounds_[2*axis],rhs.bounds_[2*axis]) ;
    Scalar bmax = std::min(bounds_[2*axis+1],rhs.bounds_[2*axis+1]) ;
    if(bmax <= bmin) return false ;
    output.bounds_[2*axis] = bmin ;
    output.bounds_[2*axis+1] = bmax ;
  }
  return true ;
}

/* Triangle clipping */
template< int Dim , typename Scalar >
template< typename Triangulation >
bool AABox<Dim,Scalar>::clips_triangle_bbox( const unsigned int triangle, 
                                             const Triangulation* mesh
                                           ) const {
  //triangle vertices
  const unsigned int* tverts = mesh->face(triangle) ;
  //initialize the bbox of the triangle
  AABox<Dim,Scalar> bbox ;
  bbox.init_to(mesh->vertex(tverts[0])) ;
  //compute the bounds
  for(int i = 1; i<3; ++i) {
    bbox.fit_to(mesh->vertex(tverts[i])) ;
  }
  return clips_aabox(bbox) ;
}

template< int Dim , typename Scalar >
bool AABox<Dim,Scalar>::clips_triangle_bbox( const unsigned int* triangle, 
                                             const Scalar* vertices
                                           ) const {
  //wrap th triangle as a mesh
  WrapMesh mesh(vertices, 3, triangle, no_neighbours, 1) ;
  return clips_triangle_bbox(0, &mesh) ;
}

template< int Dim , typename Scalar >
template< typename Triangulation >
bool AABox<Dim,Scalar>::triangle_intersection( const unsigned int triangle, 
                                               const Triangulation* mesh,
                                               std::vector<Scalar>& output
                                             ) const {
  if(!clips_triangle_bbox(triangle,mesh)) return false ;
  //initialize clipping polygon
  Polygon<Triangulation> polygon ;
  init_intersection(polygon) ;
  //iterate over the dimensions
  for(int axis=0; axis<Dim; ++axis) {
    clip_by_axis(axis,polygon,triangle,mesh) ;
    if(polygon.size() < 3) return false ;
  }
  //compute and output the clipped polygon vertices
  output.resize(Dim*polygon.size()) ;
  for(unsigned int vertex = 0; vertex < polygon.size(); ++vertex) {
    polygon[vertex].position(triangle, mesh, output.data() + Dim*vertex) ;
  }
  //beware that a box of dimension 0 always contains any triangle
  return true ;
}

template< int Dim , typename Scalar >
bool AABox<Dim,Scalar>::triangle_intersection( const unsigned int* triangle, 
                                               const Scalar* vertices,
                                               std::vector<Scalar>& output
                                             ) const {
  //wrap th triangle as a mesh
  WrapMesh mesh(vertices, 3, triangle, no_neighbours, 1) ;
  return triangle_intersection(0, &mesh, output);
}

template< int Dim , typename Scalar >
template< typename Triangulation >
bool AABox<Dim,Scalar>::clips_triangle( const unsigned int triangle, 
                                        const Triangulation* mesh 
                                      ) const {
  if(!clips_triangle_bbox(triangle,mesh)) return false ;
  //initialize clipping polygon
  Polygon<Triangulation> polygon ;
  init_intersection(polygon) ;
  //iterate over the dimensions
  for(int axis=0; axis<Dim; ++axis) {
    clip_by_axis(axis,polygon,triangle,mesh) ;
    if(polygon.size() < 3) return false ;
  }
  //beware that a box of dimension 0 always clips any triangle
  return true ;
}

template< int Dim , typename Scalar >
bool AABox<Dim,Scalar>::clips_triangle( const unsigned int* triangle, 
                                        const Scalar* vertices 
                                      ) const {
  //wrap th triangle as a mesh
  WrapMesh mesh(vertices, 3, triangle, no_neighbours, 1) ;
  return clips_triangle(0, &mesh);
}

  /* during intersection, symbolic representation of the polygon vertices */
template< int Dim , typename Scalar >
template< typename Tgl>
int AABox<Dim,Scalar>::ClipVertex<Tgl>::in_bounds( int axis, 
                                                   const Scalar bounds[2], 
                                                   const unsigned int triangle, 
                                                   const Tgl* mesh
                                                 ) {
  //vertices of the triangle
  const Scalar* verts[3] ;
  for(int i=0; i<3; ++i) {
    verts[i] = mesh->vertex(mesh->face(triangle)[i]) ;
  }
  //coordinate of the vertex to test
  Scalar coord = 0;
  if(type == ORIGINAL_V) {
    //original vertex, return its coordinate
    coord = verts[symi][axis] ;
  } else if(type == EDGE_V) {
    //edge vertex, combine the coordinates of the edge vertices
    coord =    symd[0]  * verts[symi][axis]
          + (1-symd[0]) * verts[(symi+1)%3][axis] ;
  } else if(type == FACE_V) {
    //face vertex, combine the coordinates of the triangle vertices
    coord =    symd[0]          * verts[0][axis]
          +    symd[1]          * verts[1][axis]
          + (1-symd[0]-symd[1]) * verts[2][axis] ;
  }
  //below bounds
  if(coord < bounds[0]) return -1 ;
  //above bounds
  if(coord > bounds[1]) return  1 ;
  //in bounds
  return 0 ;
}

template< int Dim , typename Scalar >
template< typename Tgl>
void AABox<Dim,Scalar>::ClipVertex<Tgl>::position( const unsigned int triangle,
                                                   const Tgl* mesh,
                                                   Scalar* output 
                                                 ) {
  //vertices of the triangle
  const unsigned int* tverts = mesh->face(triangle) ;
  if(type == ORIGINAL_V) {
    //original vertex, copy its coordinate
    std::copy(mesh->vertex(tverts[symi]), 
              mesh->vertex(tverts[symi]) + Dim, 
              output
    ) ;
  } else if(type == EDGE_V) {
    //edge vertex, combine the edge vertices
    const Scalar* x0 = mesh->vertex(tverts[ symi     ]) ;
    const Scalar* x1 = mesh->vertex(tverts[(symi+1)%3]) ;
    for(int axis=0; axis < Dim; ++axis) {
      output[axis] = symd[0]*x0[axis] + (1-symd[0])*x1[axis] ;
    }
  } else if(type == FACE_V) {
    //face vertex, combine the triangle vertices
    const Scalar* x0 = mesh->vertex(tverts[0]) ;
    const Scalar* x1 = mesh->vertex(tverts[1]) ;
    const Scalar* x2 = mesh->vertex(tverts[2]) ;
    for(int axis=0; axis < Dim; ++axis) {
      output[axis] =    symd[0]         *x0[axis] 
                   +    symd[1]         *x1[axis] 
                   + (1-symd[0]-symd[1])*x2[axis] ;
    }
  }
}

template< int Dim , typename Scalar >
template< typename Triangulation >
void AABox<Dim,Scalar>::fill_edge_vertex( int bound_index,
                                          int edge_index,
                                          const unsigned int triangle,
                                          const Triangulation* mesh,
                                          ClipVertex<Triangulation>& target
                                        ) const {
  //triangle vertices
  const unsigned int* tverts = mesh->face(triangle) ;
  //axis corresponding to the vertex
  target.symi = edge_index ;
  //bound corresponding to the vertex
  Scalar x = bounds_[bound_index] ;
  //corresponding vertex coordinates
  Scalar x0 = mesh->vertex(tverts[ edge_index     ])[bound_index/2] ;
  Scalar x1 = mesh->vertex(tverts[(edge_index+1)%3])[bound_index/2] ;
  //barycentric coordinate of the edge point along the edge
  if(x0 != x1) {
    target.symd[0] = (x-x1)/(x0-x1) ;
  } else {
    target.symd[0] = 0 ;
  }
  target.symd[1] = 0 ;
  //type of the vertex
  target.type = EDGE_V ;
}

template< int Dim , typename Scalar >
template< typename Triangulation >
void AABox<Dim,Scalar>::fill_face_vertex( int bound_index1,
                                          int bound_index2,
                                          const unsigned int triangle,
                                          const Triangulation* mesh,
                                          ClipVertex<Triangulation>& target
                                        ) const {
  //triangle vertice
  const unsigned int* tverts = mesh->face(triangle) ;
  target.symi = 0 ;
  //bounds corresponding to the vertex
  Scalar x = bounds_[bound_index1] ;
  Scalar y = bounds_[bound_index2] ;
  //corresponding vertex coordinates
  Scalar x0 = mesh->vertex(tverts[0])[bound_index1/2] ;
  Scalar y0 = mesh->vertex(tverts[0])[bound_index2/2] ;
  Scalar x1 = mesh->vertex(tverts[1])[bound_index1/2] ;
  Scalar y1 = mesh->vertex(tverts[1])[bound_index2/2] ;
  Scalar x2 = mesh->vertex(tverts[2])[bound_index1/2] ;
  Scalar y2 = mesh->vertex(tverts[2])[bound_index2/2] ;
  //determinant of the system
  Scalar det = (x0-x2)*(y1-y2) - (x1-x2)*(y0-y2) ;
  if(det == 0) {
    target.symd[0] = 0 ;
    target.symd[1] = 0 ;
  } else {
    target.symd[0] = ((x-x2)*(y1-y2)-(x1-x2)*(y-y2))/det ;
    target.symd[1] = ((x0-x2)*(y-y2)-(x-x2)*(y0-y2))/det ;
  }
  //type of the vertex
  target.type = FACE_V ;
}


/* intersection initialization */
template< int Dim , typename Scalar >
template< typename Triangulation >
void AABox<Dim,Scalar>::init_intersection( Polygon<Triangulation>& polygon 
                                         ) const {
  //initialize the polygon as a triangle
  //since the polygon is symbolic, this does not depend on the triangle
  polygon.resize(3) ;
  for(int i=0; i<3; ++i) {
    polygon[i].type = ORIGINAL_V ;
    polygon[i].symi = i ;
    polygon[i].symd[0] = 0 ;
    polygon[i].symd[1] = 0 ;
    polygon[i].esym = i ;
  }
}

/* clip the polygon along one axis */
template< int Dim , typename Scalar >
template< typename Triangulation >
void AABox<Dim,Scalar>::clip_by_axis( int axis, Polygon<Triangulation>& polygon, 
                                      const unsigned int triangle, 
                                      const Triangulation* mesh
                                    ) const {
  //size of the input polygon
  unsigned int size = polygon.size() ;
  //polygon in which the clipped polygon will be built
  Polygon<Triangulation> next_polygon ;
  next_polygon.reserve(size) ;
  //bounds corresponding to the axis
  const Scalar* bounds = axis_bounds(axis) ;
  //sides of the polygon vertices wrt. the bounds
  int* sides = new int[size] ;
  for(unsigned int vertex = 0; vertex < size; ++vertex) {
    sides[vertex] = 
      polygon[vertex].in_bounds(axis, bounds, triangle, mesh) ;
  }
  //build the clipped polygon
  for(unsigned int vertex = 0; vertex < size; ++vertex) {
    //sides of two consecutive vertices
    int my_side = sides[vertex] ;
    int next_side = sides[(vertex+1)%size] ;
    //check if the current vertex is to be kept
    if(my_side == 0) {
      //the vertex is in, keep it
      next_polygon.push_back(polygon[vertex]) ;
    }
    //test if an intersection has to be inserted
    if(my_side != next_side) {
      //test the number of intersections
      if(my_side*next_side != 0) {
        //the order of traversal of the bounds
        int first_bound = my_side < 0 ? 2*axis : 2*axis+1 ;
        int second_bound = my_side < 0 ? 2*axis+1 : 2*axis ;
        //two intersections
        next_polygon.resize(next_polygon.size()+2) ;
        ClipVertex<Triangulation>& intersection1 = 
          next_polygon[next_polygon.size()-2] ;
        intersection1.edge_type = polygon[vertex].edge_type ;
        intersection1.esym = polygon[vertex].esym ;
        ClipVertex<Triangulation>& intersection2 = 
          next_polygon[next_polygon.size()-1] ;
        intersection2.edge_type = BOUNDARY_E ;
        intersection2.esym = second_bound ;
        //types of the intersections
        if(polygon[vertex].edge_type == ORIGINAL_E) {
          //the intersection vertices types are EDGE_V
          fill_edge_vertex( first_bound, 
                            polygon[vertex].esym, 
                            triangle, 
                            mesh, 
                            intersection1
                         ) ;
          fill_edge_vertex( second_bound, 
                            polygon[vertex].esym, 
                            triangle, 
                            mesh, 
                            intersection2
                         ) ;
        } else {
          //the intersection vertices types are FACE_V
          fill_face_vertex( first_bound, 
                            polygon[vertex].esym, 
                            triangle, 
                            mesh, 
                            intersection1
                         ) ;
          fill_face_vertex( second_bound, 
                            polygon[vertex].esym, 
                            triangle, 
                            mesh, 
                            intersection2
                         ) ;
        }
      } else {
        //crossed bound
        int bound_index ;
        //one intersection
        next_polygon.resize(next_polygon.size()+1) ;
        ClipVertex<Triangulation>& intersection = 
          next_polygon[next_polygon.size()-1] ;
        //edge type of the intersection
        if(my_side != 0) {
          //getting in, the edge type is that of the current vertex
          bound_index = my_side < 0 ? 2*axis : 2*axis+1 ;
          intersection.edge_type = polygon[vertex].edge_type ;
          intersection.esym = polygon[vertex].esym ;
        } else {
          //going out, the edge corresponds to the current clipping axis
          bound_index = next_side < 0 ? 2*axis : 2*axis+1 ;
          intersection.edge_type = BOUNDARY_E ;
          intersection.esym = bound_index ;
        }
        //vertex type of the intersection
        if(polygon[vertex].edge_type == ORIGINAL_E) {
          //the vertex type is EDGE_V
          fill_edge_vertex( bound_index, 
                            polygon[vertex].esym, 
                            triangle, 
                            mesh, 
                            intersection
                         ) ;
        } else {
          //the vertex type is FACE_V
          fill_face_vertex( bound_index, 
                            polygon[vertex].esym, 
                            triangle, 
                            mesh, 
                            intersection
                         ) ;
        }
      }
    }
  }

  //swap polygons
  polygon.swap(next_polygon) ;
  //cleanup
  delete [] sides ;
}

} //end of namespace Revoropt

#endif
