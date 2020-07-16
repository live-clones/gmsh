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
#ifndef _REVOROPT_RVD_HPP_
#define _REVOROPT_RVD_HPP_

#include "polygon.hpp"
#include "nn_clipper.hpp"
#include "action.hpp"

#include <Revoropt/Tools/combinatorics.hpp>
#include <Revoropt/Tools/hash.hpp>

#ifdef USE_ANN
  #include "ann_backend.hpp"
#else
  #include "flann_backend.hpp"
#endif

#include <Eigen/Dense>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

namespace Revoropt {

/** Restricted Voronoi Diagram computer **/

template<typename _Triangulation>
class RVD {

  public :

  /* Types and template data */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;

  typedef RVDEdge<Triangulation> Edge ;
  typedef RVDEdge<Triangulation> Vertex ;

  /* Initialization */

  RVD() : mesh_(NULL), clipper_owned_(false), clipper_(NULL) {} ;

  ~RVD() {
    if(clipper_owned_) {
      delete clipper_ ;
    }
  }

  template<typename _Clipper>
  void set_clipper( _Clipper* clipper ) {
    //cleanup if necessary
    if(clipper_ != NULL && clipper_owned_) {
      delete clipper_ ;
    }
    clipper_owned_ = false ;
    clipper_ = clipper ;
  }

  void set_default_clipper() {
#ifdef USE_ANN
    typedef NNClipper< Triangulation,ANNBackend<Dim> > DefaultClipper ;
#else
    typedef NNClipper< Triangulation,FLANNBackend<Dim> > DefaultClipper ;
#endif
    //cleanup if necessary
    if(clipper_ != NULL && clipper_owned_) {
      delete clipper_ ;
    }
    //allocate
    DefaultClipper* clipper = new DefaultClipper ;
    //parameters
    clipper->set_neighbourhood_size(15) ;
    clipper->set_algorithm(DefaultClipper::CORNER_CLIPPING) ;
    //mark the clipper as owned
    clipper_owned_ = true ;
    //assign the clipper
    clipper_ = clipper ;
  }

  void set_mesh( const Triangulation* mesh  ) {
    mesh_ = mesh ;
    if(clipper_ == NULL) {
      set_default_clipper() ;
    }
    clipper_->set_mesh(mesh) ;
  }

  void set_sites( const double* sites, unsigned int sites_size ) {
    if(clipper_ == NULL) {
      set_default_clipper() ;
    }
    clipper_->set_sites(sites, sites_size) ;
  }

  /* Access */

  const double* sites() const { return clipper_->sites() ; }

  unsigned int sites_size() const { return clipper_->sites_size() ; }

  const Triangulation* mesh() const { return clipper_->mesh() ; }

  /* Computing the RVD and applying an action on each polygon */

  template<typename Action_T>
  void compute(Action_T& action) {
    //reset markers for triangles
    triangle_stacked_.assign(mesh_->faces_size(),false) ;

    //reset clipper
    clipper_->reset() ;

    //create the inner loop data
    const unsigned int site_size = clipper_->sites_size() ;
    //assign last triangle for each site to NO_NEIGHBOUR, therefore no triangle.
    site_last_triangle_.assign(site_size,Triangulation::NO_NEIGHBOUR) ;

    //loop over the connected components
    for( unsigned int init_triangle = 0;
         init_triangle<mesh_->faces_size();
         ++init_triangle
       ) {
      //check that the triangle was not previously treated
      if(!triangle_stacked_[init_triangle]) {
        //std::cout << "Found a connected component" << std::endl ;
        //find a site to initialize the propagation
        unsigned int outer_init_site = get_init_site(init_triangle) ;

        //std::cout << "Initializing site is " << outer_init_site << std::endl ;

        //initialize the outer loop
        Couple init_couple(init_triangle,outer_init_site) ;
        triangle_stacked_[init_triangle] = true ;
        triangle_stack_.push(init_couple) ;

        //launch the outer loop
        while(!triangle_stack_.empty()) {
          //get a triangle and a site
          unsigned int current_triangle = triangle_stack_.top().first ;
          unsigned int inner_init_site = triangle_stack_.top().second ;
          triangle_stack_.pop() ;

          //std::cout << "handling triangle " << current_triangle << std::endl ;

          //initialize the inner loop
          site_stack_.push(inner_init_site) ;
          site_last_triangle_[inner_init_site] = current_triangle ;

          //launch the inner loop
          while(!site_stack_.empty()) {
            //get a site to clip thetriangle
            unsigned int current_site = site_stack_.top() ;
            site_stack_.pop() ;

            //Create a polygon corresponding to the face and clip it
            RVDPolygon<Triangulation> face_polygon(
              current_triangle, mesh_
            ) ;
            clipper_->clip_by_cell(
              face_polygon, current_triangle, current_site
            ) ;

            //apply the action
            action(current_site, current_triangle, face_polygon) ;

            //propagate the computation from the edges of curr_polygon_
            propagate(face_polygon, current_triangle, current_site) ;
          }//end inner loop
        }//end outer loop on triangle--site couples
      }
    } //end of loop over connected components

    //call finalize method if it exists
    wrap_finalize(action) ;
  }

  private :

  /** Data for the outer loop **/

  typedef std::pair<unsigned int,unsigned int> Couple ;

  /* The triangle_stack_ contains mesh triangle candidates for the splitting,
   * with a site to initialize the splitting, done in an inner loop using the
   * site_stack_. A mesh triangle shall not be added twice to this stack.*/
  std::stack<Couple> triangle_stack_ ;

  /* A boolean encodes for each mesh triangle if it was previously stacked in
   * the triangle_stack_, to ensure that a mesh triangle is only stacked once in
   * this stack.  */
  std::vector<bool> triangle_stacked_ ;

  /** Data for the inner loop **/

  /* The site_stack_ contains new candidate sites for the splitting of a given
   * triangle of the mesh. This stack is used in a inner loop to split a mesh
   * triangle betwen Voronoi cells. A site shall not be added twice to this
   * stack. */
  std::stack<unsigned int> site_stack_ ;


  /* The last mesh triangle clipped for each site is stored, to ensure that a
   * site is not added twice in the site_stack_. */
  std::vector<unsigned int> site_last_triangle_ ;

  /** Initialization helpers for the compute method **/

  /* Get the nearest site from the centroid of a triangle */
  unsigned int get_init_site( unsigned int triangle ) {
    //compute the centroid of thetriangle
    const unsigned int* triangle_verts = mesh_->face(triangle) ;
    Eigen::Map<const Vector> x1(mesh_->vertex(triangle_verts[0])) ;
    Eigen::Map<const Vector> x2(mesh_->vertex(triangle_verts[1])) ;
    Eigen::Map<const Vector> x3(mesh_->vertex(triangle_verts[2])) ;

    const Vector g = (x1+x2+x3)/3. ;

    //get the site nearest to the centroid
    unsigned int nearest_site = clipper_->nearest_site(g.data()) ;
    return nearest_site ;
  }

  /** Propagation of the computations **/

  void propagate( RVDPolygon<Triangulation>& polygon,
                  unsigned int triangle,
                  unsigned int site
                ) {
    //get triangles neighbouring the triangle
    const unsigned int* triangle_neighbours =
      mesh_->face_neighbours(triangle) ;

    //iterate over the edges of curr_polygon
    for(unsigned int i = 0; i<polygon.size(); ++i) {
      //get the combinatorics of the edge
      unsigned int combinatorics = polygon[i].combinatorics ;
      if(polygon[i].config == Edge::BISECTOR_EDGE) {
        //the edge is the intersection between the triangle and a bisector
        //propagate the neighbouring site for the current triangle
        if(site_last_triangle_[combinatorics] != triangle) {
          //the neighbouring site has not been stacked for this triangle yet
          site_last_triangle_[combinatorics] = triangle ;
          site_stack_.push(combinatorics) ;

          //std::cout << "Propagating site " << combinatorics << std::endl ;
        }
      } else {
        //the edge is a portion of an original edge of the triangle
        //propagate the neighbouring triangle with the same site
        unsigned int neighbour_triangle = triangle_neighbours[combinatorics] ;
        if( neighbour_triangle != Triangulation::NO_NEIGHBOUR
            && !triangle_stacked_[neighbour_triangle]
          ) {
          //the triangle has not been stacked yet
          triangle_stacked_[neighbour_triangle] = true ;
          triangle_stack_.push(Couple(neighbour_triangle, site)) ;

          //std::cout << "Propagating triangle " << neighbour_triangle << std::endl ;
        }
      }
    }
    //std::cout << "Done propagating." << std::endl ;
  }

  /** Mesh **/
  const Triangulation* mesh_ ;

  /** Clipper **/
  bool clipper_owned_ ;
  Clipper<Triangulation>* clipper_ ;

} ;

/* Store a restricted Voronoi diagram */

template<typename Triangulation, int _OutDim = Triangulation::VertexDim>
class RVDStore {

  //typedefs
  enum { Dim = Triangulation::VertexDim, OutDim = _OutDim } ;
  typedef typename Triangulation::Scalar Scalar ;
  typedef tuplekey<3> CombVertexPart ;
  typedef tuple_hash<3, unsigned int> CVPHasher ;
  typedef std::pair<CombVertexPart,CombVertexPart> CombVertex ;

  class CVHasher {
    public :
      std::size_t operator()( const CombVertex& comb_vertex ) const {
        std::size_t seed = 0 ;
        hash_combine<CombVertexPart, CVPHasher>(seed, comb_vertex.first) ;
        hash_combine<CombVertexPart, CVPHasher>(seed, comb_vertex.second) ;
        return seed ;
      }
  } ;

  public :

  void operator()( unsigned int site, unsigned int triangle,
                   const RVDPolygon<Triangulation>& polygon
                 ) {
    unsigned int size = polygon.size() ;

    //collect the vertex indices of the polygon vertices
    std::vector<unsigned int> vert_indices(size) ;

    for(unsigned int vertex = 0; vertex < size; ++vertex) {
      //Combinatorial vertex
      const RVDVertex<Triangulation>& v = polygon[vertex].vertex ;
      //build the key to merge the vertex with any combinatorial equivalent
      CombVertexPart cv_part_1(v.combinatorics()) ;
      CombVertexPart cv_part_2(v.combinatorics()+3) ;
      CombVertex key(cv_part_1,cv_part_2) ;
      //check whether the combinatorics of this vertex is already existing
      vmap_iterator it = vmap.find(key) ;
      if( it == vmap.end() ) {
        //no such combinatorics in the map
        //add the vertex to the final mesh
        vert_indices[vertex] = rvd_mesh.push_vertex(v.data()) ;
        //associate the index with the combinatorics in the map
        vmap[key] = vert_indices[vertex] ;
        //store the combinatorics of the vertex
        vertex_combinatorics.push_back(key) ;
      } else {
        //the combinatorics was previously handled, recover the index
        vert_indices[vertex] = it->second ;
      }
    }

    //add the polygon to the mesh
    rvd_mesh.push_face(vert_indices.data(), size) ;
    //store the polygon site
    face_sites.push_back(site) ;
  }

  //collecting and merging RVD vertices
  std::unordered_map<CombVertex, unsigned int, CVHasher> vmap ;
  typedef typename std::unordered_map<
    CombVertex,
    unsigned int,
    CVHasher
  >::iterator vmap_iterator ;
  //output mesh
  MeshBuilder<Variable,OutDim,Scalar> rvd_mesh ;
  //recall the site index for every face
  std::vector<unsigned int> face_sites ;
  //recall the combinatorics for every vertex
  std::vector<CombVertex> vertex_combinatorics ;
} ;


} //end of namespace Revoropt

#endif
