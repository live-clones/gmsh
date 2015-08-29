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
#ifndef _REVOROPT_RVD_NN_CLIPPER_HPP_
#define _REVOROPT_RVD_NN_CLIPPER_HPP_

#include "clipper.hpp"

#include <vector>
#include <iostream>

namespace Revoropt {

/** Base class for clippers using nearest neighbour queries **/

template<typename _Triangulation, typename _NNBackend>
class NNClipper : public Clipper<_Triangulation> {

  public :

  /* Types and template data */
  typedef _Triangulation Triangulation ;
  typedef Clipper<Triangulation> Base ;
  typedef _NNBackend NNBackend ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef typename Triangulation::Scalar Scalar ;
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  typedef RVDEdge<Triangulation> Edge ;

  enum Algo { SITE_NEIGHBOURS, 
              TRIANGLE_NEIGHBOURS, 
              MIXED_TRIANGLE_NEIGHBOURS,
              CORNER_CLIPPING,
              CENTER_THEN_CORNER_CLIPPING
            } ;

  /* Initialization, destruction */
  NNClipper() : Base(), 
                neighbourhood_size_(10),
                algorithm_(CORNER_CLIPPING) {
  }

  NNClipper( const Scalar* sites, unsigned int sites_size,
             const Triangulation* mesh
           ) : Base(sites, sites_size, mesh),
               neighbourhood_size_(10),
               algorithm_(CORNER_CLIPPING) {
    set_sites(sites, sites_size) ;
  }

  virtual ~NNClipper() {}
            
  /* Choose algorithm */
  void set_algorithm( int algorithm ) {
    int algo = algorithm > 4 ? 4 : algorithm ;
    algorithm_ = (Algo) algo ;
  }

  /* Clipping */
  void clip_by_cell( RVDPolygon<Triangulation>& polygon, 
                     unsigned int triangle, 
                     unsigned int site 
                   ) {
    //reset max distance between the site and its neighbours so far
    max_neighbour_distance_ = 0 ;

    //get site position as a vector
    Eigen::Map<const Vector> site_pos(Base::sites_+Dim*site) ;

    //set current site as handled
    site_last_opposite_[site] = Couple(triangle, site) ;

    //compute distances between the site and the polygon vertices
    site_distances_.resize(0) ;

    //resize new_vertices array
    new_vertices_.assign(polygon.size(), true) ;

    for(unsigned int i=0; i<polygon.size(); ++i) {
      const Vector d = site_pos - polygon[i].vertex ;
      site_distances_.push_back(d.dot(d)) ;
    }

    unsigned int clippings = 0 ;
    if(algorithm_ == SITE_NEIGHBOURS) {
      clippings += full_neighbour_clip(polygon, triangle, site, neighbourhood_size_) ;
      return ;
    }
    if(algorithm_ == TRIANGLE_NEIGHBOURS) {
      clippings += full_radius_clip(polygon, triangle, site, neighbourhood_size_) ;
      return ;
    }
    clippings += neighbour_clip(polygon, triangle, site, neighbourhood_size_) ;
    if(algorithm_ == MIXED_TRIANGLE_NEIGHBOURS) {
      clippings += full_radius_clip(polygon, triangle, site, neighbourhood_size_) ;
      return ;
    }
    if(algorithm_ == CORNER_CLIPPING) {
      clippings += corner_clip(polygon, triangle, site) ;
      return ;
    }
    if(algorithm_ == CENTER_THEN_CORNER_CLIPPING) {
      clippings += center_then_corner_clip(polygon, triangle, site) ;
      return ;
    }
  }

  /* Nearest site */
  unsigned int nearest_site( const Scalar* query ) {
    //storage for the result
    unsigned int site ;
    Scalar distance ;
    //search
    nnbackend_.knnSearch(query, 1, &site, &distance) ;

    return site ;
  }

  /* Overloading site setting in clipper to update nearest neighbours */
  void set_sites( const Scalar* sites, unsigned int sites_size ) {
    //call parent update
    Base::set_sites( sites, sites_size ) ;

    //reset the site_last_opposite array
    reset() ;

    //initialize the nearest neighbour backend
    nnbackend_.set_sites(sites, sites_size) ;
  }

  /* set/get parameters */
  unsigned int neighbourhood_size() {
    return neighbourhood_size_ ;
  }
  void set_neighbourhood_size( unsigned int size ) {
    neighbourhood_size_ = size ;
  }

  /* reset */
  void reset() {
    site_last_opposite_.assign(
      Base::sites_size_, 
      Couple(Triangulation::NO_NEIGHBOUR,0)
    ) ;
  }

  private :

  /* Parameters */
  unsigned int neighbourhood_size_ ;

  /* Prevent multiple clippings by the same opposite site for a given site and
   * triangle. This array is reset with the reset method. */
  typedef std::pair<unsigned int, unsigned int> Couple ;
  std::vector<Couple> site_last_opposite_ ;

  /* Data for nearest neighbour searches */
  double max_neighbour_distance_ ;
  std::vector<unsigned int> nn_indices_ ;
  std::vector<Scalar> nn_distances_ ;

  /* Data for the ongoing clipping */
  //during clipping, the vertices of the clipped polygon are marked true in this
  //array and the new vertices of the clipped polygon are marked false.
  std::vector<bool> new_vertices_ ;
  std::vector<bool> next_new_vertices_ ;

  //distances between the site and the polygon vertices
  std::vector<double> site_distances_ ;
  std::vector<double> site_next_distances_ ;

  //distance between another site and the polygon vertices
  std::vector<double> opposite_distances_ ;

  /* Clipping by the sites nearest neighbours */
  unsigned int neighbour_clip( RVDPolygon<Triangulation>& polygon,
                               unsigned int triangle,
                               unsigned int site,
                               unsigned int nneighbours
                             ) {
    //query point
    const Scalar* query = Base::sites_ + Dim*site ;

    //count clippings
    unsigned int clippings = 0 ;

    //site radius : maximal squared distance to the polygon vertices
    double site_radius = *std::max_element( site_distances_.begin(), 
                                            site_distances_.end()
                                          ) ;

    //number of neighbours neighbours
    unsigned int neighbour_size = std::min(Base::sites_size_, nneighbours) ;
    nn_indices_.resize(neighbour_size) ;
    nn_distances_.resize(neighbour_size) ;

    nnbackend_.knnSearch( query, 
                         neighbour_size,
                         nn_indices_.data(), 
                         nn_distances_.data()
                       ) ;

    max_neighbour_distance_ = nn_distances_[neighbour_size-1] ;

    //iterate clip by nearest neighbours
    for(unsigned int i=0 ; i<neighbour_size ; ++i) {
      ++clippings ;
      unsigned int opposite_site = nn_indices_[i] ;

      if(opposite_site == site) {
        continue ;
      }
      //check if security readius is reached
      if(nn_distances_[i] > 4*site_radius) {
        return clippings-1 ;
      }
      //check whether this site was handled before
      if(site_last_opposite_[opposite_site] != Couple(triangle,site)) {
        //mark current opposite site as done for this clipping
        site_last_opposite_[opposite_site] = Couple(triangle,site) ;
        //perform the clipping
        clip_by_plane(polygon, triangle, site, opposite_site) ;
        if(polygon.size() > 0) {
           site_radius = *std::max_element( site_distances_.begin(), 
                                            site_distances_.end()
                                          ) ;
        } else {
          site_radius = 0 ;
        }
      }
    }
    return clippings ;
  }

  /* iterate neighbour clipping until termination */
  unsigned int full_neighbour_clip( RVDPolygon<Triangulation>& polygon,
                                    unsigned int triangle,
                                    unsigned int site,
                                    unsigned int nneighbours
                                  ) {
    unsigned int current_nneighbours = nneighbours ;
    unsigned int clippings = 0 ;
    do{
      //clip using the current neighbourhood size
      clippings = neighbour_clip(polygon, triangle, site, current_nneighbours) ;
      //check for security radius termination of the clipping
      if(clippings < current_nneighbours) {
        //in case of early termination, the clipping is correct
        return clippings ;
      }
      //no early termination, increase the size of the neighbourhood
      current_nneighbours += nneighbours ;
    } while(clippings < Base::sites_size_ ) ;
    //return the number of clippings required, all the sites at this point
    return clippings ;
  }

  /* Clipping using the nearest neighours of the polygon */
  unsigned int corner_clip( RVDPolygon<Triangulation>& polygon,
                            unsigned int triangle,
                            unsigned int site
                          ) {
    //mark all the vertices as new vertices
    new_vertices_.assign(polygon.size(),true) ;

    //total number of clippings
    unsigned int clippings = 0 ;

    //marked true if the polygon was clipped during current iteration
    bool clipped = false ;

    do {
      clipped = false ;

      //get the nearest neighbours of all the new polygon corners
      for(unsigned int i = 0; i<polygon.size(); ++i) {
        if(new_vertices_[i]) {
          if(site_distances_[i] >= 0.25*max_neighbour_distance_) {
            //get the nearest neighbour of the corner
            int opposite_site = nearest_site(polygon[i].vertex.data()) ;
            //Debug
            //Vector save = polygon[i].vertex ;
            if(site_last_opposite_[opposite_site] != Couple(triangle,site)) {
              //mark current opposite site as done for this clipping
              site_last_opposite_[opposite_site] = Couple(triangle,site) ;
              //perform the clipping
              clipped = clip_by_plane(polygon, triangle, site, opposite_site) ;
              if(!clipped) {
              //  for(int k = 0; k < site_next_distances_.size(); ++k) {
              //    std::cout << opposite_distances_[k] - site_next_distances_[k] << " " << std::flush ;
              //  }
              //  std::cout << std::endl ;
              //  std::cout << site << " " << opposite_site << " " << i << "/" << next_polygon_.size() << std::endl ;
              //  Eigen::Map<const Vector> spos(Base::sites_+Dim*site) ;
              //  Eigen::Map<const Vector> opos(Base::sites_+Dim*opposite_site) ;
              //  std::cout << (spos-save).norm() << " " <<  (opos-save).norm() << std::endl ;
              //  std::cout << nearest_site(next_polygon_[i].vertex.data()) << std::endl ;
              //  std::cout << nearest_site(save.data()) << std::endl ;
              //  std::cout << opposite_site << std::endl ;
              //  std::cout << opos << std::endl ;
              //  std::cout << "===" << std::endl ;
              //  std::cout << spos << std::endl ;
              //  std::cout << "===" << std::endl ;
              //  std::cout << save << std::endl ;
              //  std::cout << "===" << std::endl ;
              //  std::cout << "Warning, nearest neighbour of corner did not clip." << std::endl ;
              }
              ++clippings ;
              break ;
            } else {
              new_vertices_[i] = false ;
            }
          } else {
            new_vertices_[i] = false ;
          }
        }
      }
    } while( clipped ) ;
    return clippings ;
  }

  double compute_center_radius( RVDPolygon<Triangulation>& polygon, 
                                Vector& center,
                                double site_radius
                              ) {
    double center_radius = 0 ;
    for(unsigned int i=0; i<polygon.size(); ++i) {
      Vector d = (polygon[i].vertex - center) ;
      center_radius = std::max(center_radius, d.dot(d)) ;
    }
    center_radius = sqrt(center_radius) ;
    center_radius += sqrt(site_radius) ;
    center_radius *= center_radius ;
    
    return center_radius*center_radius ;
  }

  double compute_finer_center_radius( RVDPolygon<Triangulation>& polygon, 
                                      Vector& center,
                                      std::vector<double>& site_distances
                                    ) {
    double center_radius = 0 ;
    for(unsigned int i=0; i<polygon.size(); ++i) {
      Vector d = (polygon[i].vertex - center) ;
      center_radius = 
          std::max(center_radius, sqrt(d.dot(d)) + sqrt(site_distances[i])) ;
    }
    
    return center_radius*center_radius ;
  }

  /* Clipping using sites centered on the barycenter*/
  unsigned int radius_clip( RVDPolygon<Triangulation>& polygon,
                            unsigned int triangle,
                            unsigned int site,
                            unsigned int nneighbours
                          ) {
    if(polygon.size() < 3) return 0 ;
    //compute the centroid of the polygon
    Vector center = Vector::Zero() ;
    for(unsigned int i=0; i<polygon.size(); ++i) {
      center += polygon[i].vertex ;
    }
    center /= polygon.size() ;


    //compute the radius of the search
    double center_radius = 
      compute_finer_center_radius(polygon, center, site_distances_) ;

    //get nearest neighbours
    unsigned int neighbour_size = std::min(Base::sites_size_, nneighbours) ;
    nn_indices_.resize(neighbour_size) ;
    nn_distances_.resize(neighbour_size) ;

    nnbackend_.knnSearch( center.data(), 
                         neighbour_size,
                         nn_indices_.data(), 
                         nn_distances_.data()
                       ) ;

    unsigned int clippings = 0 ;

    for( unsigned int i = 0; i < neighbour_size; ++i ) {
      //increase the number of sites handled
      ++clippings ;

      //get neighbour index
      const unsigned int opposite_site = nn_indices_[i] ;

      //check that the neighbour was not previously handled
      if(site_last_opposite_[opposite_site] != Couple(triangle,site)) {

        site_last_opposite_[opposite_site] = Couple(triangle,site) ;

        //check that the neighbour is within the (updated) center radius
        if(nn_distances_[i] > center_radius) {
          return clippings-1 ;
        }

        //clip curr_polygon_ by the bisector between site and opposite_site
        clip_by_plane(polygon, triangle, site, opposite_site) ;
        
        //update the center radius
        if(polygon.size() > 0) {
           center_radius = 
             compute_finer_center_radius(polygon, center, site_distances_) ;
        } else {
          center_radius = 0 ;
        }
      }
    }

    return clippings ;
  }

  /* iterate radius clipping until termination */
  unsigned int full_radius_clip( RVDPolygon<Triangulation>& polygon,
                                    unsigned int triangle,
                                    unsigned int site,
                                    unsigned int nneighbours
                                  ) {
    unsigned int current_nneighbours = nneighbours ;
    unsigned int clippings = 0 ;
    do{
      //clip using the current neighbourhood size
      clippings = radius_clip(polygon, triangle, site, current_nneighbours) ;
      //check for security radius termination of the clipping
      if(clippings < current_nneighbours) {
        //in case of early termination, the clipping is correct
        return clippings ;
      }
      //no early termination, increase the size of the neighbourhood
      current_nneighbours += nneighbours ;
    } while(clippings < Base::sites_size_) ;
    //return the number of clippings required, all the sites at this point
    return clippings ;
  }

  /* Clipping using the nearest site from the barycenter */
  unsigned int center_clip( RVDPolygon<Triangulation>& polygon,
                            unsigned int triangle,
                            unsigned int site
                          ) {
    if(polygon.size() < 3) return 0 ;
    //compute the centroid of the polygon
    Vector center = Vector::Zero() ;
    for(unsigned int i=0; i<polygon.size(); ++i) {
      center += polygon[i].vertex ;
    }
    center /= polygon.size() ;

    nn_indices_.resize(2) ;
    nn_distances_.resize(2) ;

    nnbackend_.knnSearch( center.data(), 
                         2,
                         nn_indices_.data(), 
                         nn_distances_.data()
                       ) ;

    unsigned int opposite_site = nn_indices_[0] == site ? 
      nn_indices_[1] : nn_indices_[0] ;

    //check that the neighbour was not previously handled
    if(site_last_opposite_[opposite_site] == Couple(triangle,site)) {
      //no new site handled
      return 0 ;
    }

    site_last_opposite_[opposite_site] = Couple(triangle,site) ;

    //clip curr_polygon_ by the bisector between site and opposite_site
    clip_by_plane(polygon, triangle, site, opposite_site) ;

    //one new site was handled
    return 1 ;
  }

  /* iterate center clipping until no new site is handled, then corner clip */
  unsigned int center_then_corner_clip( RVDPolygon<Triangulation>& polygon,
                                        unsigned int triangle,
                                        unsigned int site
                                      ) {
    unsigned int clippings = 0 ;
    unsigned int last_clippings = 0 ;
    do{
      //clip using the polygon barycenter nearest neighbour
      last_clippings = center_clip(polygon, triangle, site) ;
      //add up potential new clip
      clippings += last_clippings ;
    } while(last_clippings == 1) ;
    //return the number of clippings required, all the sites at this point
    return clippings + corner_clip(polygon, triangle, site) ;
  }

  /* Clipping by a bisector */
  bool clip_by_plane( RVDPolygon<Triangulation>& polygon,
                      unsigned int triangle,
                      unsigned int site,
                      unsigned int opposite_site
                    ) {
    //polygon size
    unsigned int size = polygon.size() ;

    //get the site positions for distance computations
    Eigen::Map<const Vector> site_pos(Base::sites_ +Dim*site) ;
    Eigen::Map<const Vector> opp_site_pos(Base::sites_ +Dim*opposite_site) ;

    //compute distances between opposite site and polygon vertices
    opposite_distances_.resize(0) ;
    for(unsigned int i=0; i<size; ++i) {
      const Vector d = opp_site_pos - polygon[i].vertex ;
      opposite_distances_.push_back(d.dot(d)) ;
    }

    //reset next information
    next_new_vertices_.resize(0) ;
    next_polygon_.resize(0) ;
    site_next_distances_.resize(0) ;

    //return value, changed to true is some clipping occurs
    bool clipped = false ;

    //iterate over the vertices of the polygon
    for(unsigned int i = 0; i<size; ++i) {
      //get the sides of the current vertex and the next one
      const double my_side = opposite_distances_[i] - site_distances_[i] ;
      const double next_side = opposite_distances_[(i+1)%size] 
                             - site_distances_[(i+1)%size] ;
      //check whether the vertex is in or out
      if(my_side > 0) {
        //vertex is in, keep it and its distance
        next_new_vertices_.push_back(new_vertices_[i]) ;
        next_polygon_.push_back(polygon[i]) ;
        site_next_distances_.push_back(site_distances_[i]) ;
      }

      if(my_side <= 0) {
          //the vertex is out, the opposite site owns a piece of this polygon
          clipped = true ;
      }

      //check whether the next vertex is on the same side
      if( my_side*next_side < 0 || 
          (my_side == 0 && next_side > 0) ||
          (my_side > 0 && next_side == 0)
        ) {
        
        //different sides, an intersection point must be added
        const unsigned int* triangle_vertices = Base::mesh_->face(triangle) ;

        //add an uninitialized edge
        const unsigned int new_edge_index = next_polygon_.size() ;
        next_polygon_.resize(new_edge_index+1) ;
        RVDEdge<Triangulation>& new_edge = next_polygon_[new_edge_index] ;

        //build the intersection vertex
        if(polygon[i].config == Edge::FACE_EDGE) {
          //the intersection is an EDGE_VERTEX
          //recover the combinatorics
          const unsigned int edge_index = polygon[i].combinatorics ;

          const unsigned int x1 = triangle_vertices[(edge_index  )%3] ;
          const unsigned int x2 = triangle_vertices[(edge_index+1)%3] ;

          new_edge.vertex.reset( x1, x2, 
                                 site, opposite_site, 
                                 Base::mesh_, Base::sites_
                               ) ;

        } else {
          //the intersection is a FACE_VERTEX
          //recover the combinatorics
          const unsigned int x1 = triangle_vertices[0] ;
          const unsigned int x2 = triangle_vertices[1] ;
          const unsigned int x3 = triangle_vertices[2] ;
          const unsigned int other_site = polygon[i].combinatorics ;

          new_edge.vertex.reset( x1, x2, x3,
                                 site, opposite_site, other_site,
                                 Base::mesh_, Base::sites_
                               ) ;
        }

        //set the edge configuration
        if(my_side > 0) {
          new_edge.config = Edge::BISECTOR_EDGE ;
          new_edge.combinatorics = opposite_site ;
        } else {
          new_edge.config = polygon[i].config ;
          new_edge.combinatorics = polygon[i].combinatorics ;
        }

        //compute intersection distance with the center site
        Vector d = site_pos - new_edge.vertex ;
        //std::cout << "New vertex is at distance " << d.dot(d) << std::endl ;
        site_next_distances_.push_back(d.dot(d)) ;
        next_new_vertices_.push_back(true) ;
      }
    }

    //update current information
    new_vertices_.swap(next_new_vertices_) ;
    polygon.swap(next_polygon_) ;
    site_distances_.swap(site_next_distances_) ;

    //return clipped status
    return clipped ;
  }

  //during clipping the new polygon is built in this one and then swapped
  RVDPolygon<Triangulation> next_polygon_ ;

  /* Algorithm */
  Algo algorithm_ ;

  /* Nearest neighbour backend */
  NNBackend nnbackend_ ;
} ;

} //end of namespace Revoropt

#endif
