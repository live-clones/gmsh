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
#ifndef _REVOROPT_CVT_COMPUTER_H_
#define _REVOROPT_CVT_COMPUTER_H_

#include <stddef.h>
#include <Eigen/Dense>

#include <Revoropt/RVD/rvd.hpp>
#include <Revoropt/RVD/polygon.hpp>
#include <Revoropt/Mesh/all_def.hpp>
#include <Revoropt/Mesh/measure_def.hpp>

namespace Revoropt {
namespace CVT {

template<typename _Triangulation>
class BaseComputer {// : public RVD::Action<_Triangulation> {

  public :

  /* Typedefs and template arguments */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;

  BaseComputer() : g_(NULL), fx_(0),
                   mesh_(NULL), sites_(NULL),
                   triangle_weights_(NULL),
                   mesh_area_(0), mesh_boundary_length_(0),
                   factor_(1), anisotropy_(1),
                   border_anisotropy_(1), border_weight_(0),
                   tolerance_(0) {
  }

  /* LBFGS variables to compute */
  void set_g( double* g ) { g_ = g ; }
  void set_fx( double val ) { fx_ = val ; }
  double get_fx() { return fx_ ; }

  /* Mesh and sites */
  void set_mesh( const Triangulation* mesh ) {
    mesh_ = mesh ;
    mesh_area_ = mesh_area(mesh) ;
    //FIXME
    //mesh_boundary_length_ = mesh->boundary_length() ;
  }

  const Triangulation* get_mesh() {
   return mesh_ ;
  }
  void set_sites( const double* sites ) {
    sites_ = sites ;
  }
  void set_triangle_weights( const double* triangle_weights ) {
    triangle_weights_ = triangle_weights ;
  }

  /* Parameter setting */
  void set_factor( double factor ) {
    factor_ = factor ;
  }

  void set_anisotropy( double anisotropy ) {
    anisotropy_ = anisotropy ;
  }

  void set_border_anisotropy( double border_anisotropy ) {
    border_anisotropy_ = border_anisotropy ;
  }

  void set_border_weight( double border_weight ) {
    border_weight_ = border_weight ;
  }

  void set_tolerance( double tolerance ) {
    tolerance_ = tolerance ;
  }

  protected :

  /* LBFGS variables to compute */
  double* g_ ;
  double fx_ ;

  /* Mesh and sites */
  const Triangulation* mesh_ ;
  const double* sites_ ;
  const double* triangle_weights_ ;

  double mesh_area_ ;
  double mesh_boundary_length_ ;

  /* Parameter variables */

  double factor_ ;
  double anisotropy_ ;
  double border_anisotropy_ ;
  double border_weight_ ;
  double tolerance_ ;
} ;

/** Direct computer **/

/* Compute the value and gradient of the direct CVT objective function when
 * passed to the corresponding RVD computer. The direct CVT objective function
 * optimizes a set of samples to sample uniformly a mesh. */

template<typename _Triangulation>
class DirectComputer : public BaseComputer<_Triangulation> {

  public :

  /* Typedefs and template arguments */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;
  typedef BaseComputer<Triangulation> Base ;

  typedef RVDEdge<Triangulation> Edge ;

  DirectComputer() : BaseComputer<Triangulation>() {}

  void operator()( unsigned int site,
                   unsigned int face,
                   const RVDPolygon<Triangulation>& polygon
                 ) {
    //number of vertices of the polygon
    const unsigned int size = polygon.size() ;

    if(size < 3) return ;

    //send triangles to the triangle backend
    for(unsigned int i=1; i<size-1; ++i) {
      triangle_compute( site,
                        face,
                        polygon[0],
                        polygon[i],
                        polygon[i+1]
                      ) ;
    }

    //std::cout << "after triangle " << fx_ << std::endl ;

    //compute a point inside the polygon for boundary normal computations
    Vector bar ;
    bar.setZero() ;
    for(unsigned int i=0; i<size; ++i) {
      bar += polygon[i].vertex ;
    }
    bar /= size ;

    //send bisector edges to the edge backend
    for(unsigned int i=0; i<size; ++i) {
      if(polygon[i].config == Edge::BISECTOR_EDGE) {
        edge_compute( site,
                      face,
                      polygon[i],
                      polygon[(i+1)%size],
                      bar
                    ) ;
      }

/* FIXME
      if(border_weight_ != 0 && mesh_boundary_length_ != 0) {
        //one dimensional CVT of the boundary of the mesh
        if(polygon[i].config == RVD::FACE_EDGE) {
          //get edge index
          const unsigned int edge_index = polygon[i].combinatorics ;
          //get the neighbours of the triangle
          const unsigned int* triangle_neighbours
            = mesh_->face_neighbours(triangle) ;
          //check whether the edge is a boundary edge
          if( triangle_neighbours[edge_index]
              == Triangulation::NO_NEIGHBOUR
            ) {
            border_compute(site, polygon[i], polygon[(i+1)%size]) ;
          }
        }
      }
*/
    }

    //std::cout << "after edges " << fx_ << std::endl ;
  }

  private :

  using Base::factor_ ;
  using Base::anisotropy_ ;
  using Base::tolerance_ ;
  using Base::mesh_area_ ;
  using Base::fx_ ;
  using Base::g_ ;
  using Base::sites_ ;
  using Base::mesh_ ;
  using Base::triangle_weights_ ;

  void triangle_compute( const unsigned int site,
                         const unsigned int triangle,
                         const RVDEdge<Triangulation>& e1,
                         const RVDEdge<Triangulation>& e2,
                         const RVDEdge<Triangulation>& e3
                       ) {
    //vertices of the triangle
    const Vector& c1 = e1.vertex ;
    const Vector& c2 = e2.vertex ;
    const Vector& c3 = e3.vertex ;

    //Triangle basis and area
    const Vector base = (c2-c1) ;
    const double base_len = base.norm() ;
    if(base_len <= tolerance_) return ;
    const Vector tb1 = base/base_len ;

    Vector height = (c3-c1)  ;
    height -= height.dot(tb1)*tb1 ;
    const double height_len = height.norm() ;
    if(height_len <= tolerance_) return ;
    const Vector tb2 = height/height_len ;

    //triangle weighting
    const double tweight = triangle_weights_ == NULL ?
      1 :
      triangle_weights_[triangle] ;
    const double area = 0.5*base_len*height_len*tweight ;

    if(area <= tolerance_) return ;

    //site position
    Eigen::Map<const Vector> v(sites_ + Dim*site) ;

    //function value

    //site vectors
    Vector sv[3] ;
    sv[0] = v-c1 ;
    sv[1] = v-c2 ;
    sv[2] = v-c3 ;

    //compute value
    double local_fx = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j <= i; ++j) {
        local_fx += sv[i].dot(sv[j]) ;
      }
    }
    local_fx /= 6 ;

    //compute gradient

    //centroid vector
    Vector g_vect = (c1+c2+c3)/3. ;
    g_vect = (v-g_vect) ;

    //anisotropy
    if(anisotropy_ > 1) {
      //normal component of the face-site vectors
      Vector normal_component = v-c1 ;
      normal_component -= normal_component.dot(tb1)*tb1 ;
      normal_component -= normal_component.dot(tb2)*tb2 ;
      ////FIXME keep component in normal space ?
      //for(int i = 3; i < Dim; ++i) {
      //  normal_component[i] = 0 ;
      //}

      //value modification
      local_fx += (anisotropy_*anisotropy_-1)
                * normal_component.dot(normal_component) ;

      //gradient modification
      g_vect += (anisotropy_*anisotropy_-1)
              * normal_component ;
    }

    //store result, normalize by mesh area
    fx_ += (factor_/mesh_area_)*area*local_fx ;
    Eigen::Map<Vector> grad(g_ + Dim*site) ;
    grad += factor_*area*2*g_vect/mesh_area_ ;
  }

  void edge_compute( const unsigned int site,
                     const unsigned int face,
                     const RVDEdge<Triangulation>& e1,
                     const RVDEdge<Triangulation>& e2,
                     const Vector& inner_point
                   ) {
    if(anisotropy_<=1) return ;

    //bisector containing the edge
    const unsigned int neighbour = e1.combinatorics ;

    //handling edges only once
    if (neighbour<site) return ;

    //sites
    Eigen::Map<const Vector> v1(sites_ + Dim*site) ;
    Eigen::Map<const Vector> v2(sites_ + Dim*neighbour) ;

    //vertices of the edge
    const Vector& c1 = e1.vertex ;
    const Vector& c2 = e2.vertex ;

    //edge vector
    Vector edge = c2-c1 ;
    double edge_len = edge.norm() ;
    if(edge_len <= tolerance_) return ;
    edge /= edge_len ;

    //triangle weighting
    const double tweight = triangle_weights_ == NULL ?
      1 :
      triangle_weights_[face] ;
    edge_len *= tweight ;

    //edge normal
    Vector edge_normal = c1-inner_point ;
    edge_normal -= edge_normal.dot(edge)*edge ;
    const double edge_normal_len = edge_normal.norm() ;
    if(edge_normal_len <= tolerance_) return ;
    edge_normal /= edge_normal_len ;

    const double boundary_speed_denom = edge_normal.dot(v1-v2) ;
    const double abs_bsd = boundary_speed_denom < 0 ?
                           - boundary_speed_denom :
                           boundary_speed_denom ;
    if(abs_bsd <= tolerance_) return ;

    //site vector normal component
    Vector nc1 = v1-c1 ;
    nc1 -= nc1.dot(edge)*edge ;
    nc1 -= nc1.dot(edge_normal)*edge_normal ;
    Vector nc2 = v2-c1 ;
    nc2 -= nc2.dot(edge)*edge ;
    nc2 -= nc2.dot(edge_normal)*edge_normal ;
    ////FIXME keep component in normal space ?
    //for(int i = 3; i < Dim; ++i) {
    //  nc1[i] = 0 ;
    //  nc2[i] = 0 ;
    //}

    //gradient common part
    const double tmp = (anisotropy_*anisotropy_-1)
                     * (nc1.dot(nc1)-nc2.dot(nc2))
                     / boundary_speed_denom
                     * edge_len
                     //normalize by the mesh area FIXME for triangle weights
                     * factor_/mesh_area_ ;

    //edge center
    const Vector edge_center = 0.5*(c1+c2) ;

    //gradient for v1
    Eigen::Map<Vector> grad1(g_ + Dim*site) ;
    grad1 += tmp*(v1-edge_center) ;

    //gradient for v2
    Eigen::Map<Vector> grad2(g_ + Dim*neighbour) ;
    grad2 -= tmp*(v2-edge_center) ;
  }

/* FIXME
  void border_compute( const unsigned int site,
                       const RVD::RVDEdge& e1,
                       const RVD::RVDEdge& e2
                     ) ;

  void border_vertex_compute( const unsigned int site,
                              const RVD::RVDVertex& c,
                              const Vector3d& edge
                            ) ;
*/
} ;

/** Inverse computer **/

/* Compute the value and gradient of the inverse CVT objective function when
 * passed to the corresponding RVD computer. The inverse CVT objective function
 * optimizes a mesh such that a given sampling regularly samples it.*/

template<typename _Triangulation>
class InverseComputer : public BaseComputer<_Triangulation> {

  public :

  /* Typedefs and template arguments */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;
  typedef Eigen::Matrix<double,Dim,Dim> Matrix ;

  typedef RVDVertex<Triangulation> Vertex ;

  typedef BaseComputer<Triangulation> Base ;

  InverseComputer() : BaseComputer<Triangulation>() {}

  void operator()( unsigned int site,
                   unsigned int face,
                   const RVDPolygon<Triangulation>& polygon
                 ) {
    //number of vertices of the polygon
    const unsigned int size = polygon.size() ;

    if(size < 3) return ;

    //send triangles to the triangle backend
    for(unsigned int i=1; i<size-1; ++i) {
      triangle_compute(site, face, polygon[0], polygon[i], polygon[i+1]) ;
    }
  }

  void add_mesh_area_gradient() {
    //add the contribution of the mesh area gradient
    mesh_area_gradient(mesh_, g_, -fx_ / mesh_area_) ;
  }

  void finalize() {
    add_mesh_area_gradient() ;
  }

  private :

  using Base::factor_ ;
  using Base::anisotropy_ ;
  using Base::tolerance_ ;
  using Base::mesh_area_ ;
  using Base::fx_ ;
  using Base::g_ ;
  using Base::sites_ ;
  using Base::mesh_ ;

  std::vector<double> area_gradient_ ;

  void triangle_compute( const unsigned int site,
                         const unsigned int face,
                         const RVDEdge<Triangulation>& e1,
                         const RVDEdge<Triangulation>& e2,
                         const RVDEdge<Triangulation>& e3
                       ) {
    //vertices of the triangle
    const RVDVertex<Triangulation>* c[3] ;
    c[0] = &e1.vertex ;
    c[1] = &e2.vertex ;
    c[2] = &e3.vertex ;

    //normalized edges of the triangle
    Vector ed[3] ;
    double ed_len[3] ;
    for(int i=0; i<3; ++i) {
      ed[i] = *(c[(i+2)%3]) - *(c[(i+1)%3]) ;
      ed_len[i] = ed[i].norm() ;
      if(ed_len[i] <= tolerance_) return ;
      ed[i] /= ed_len[i] ;
    }

    //normalized heights of the triangle
    Vector h[3] ;
    double h_len[3] ;
    for(int i=0; i<3; ++i) {
      h[i] = (ed[(i+1)%3] - (ed[(i+1)%3].dot(ed[i])*ed[i]))*ed_len[(i+1)%3] ;
      h_len[i] = h[i].norm() ;
      if(h_len[i] <= tolerance_) return ;
      h[i] /= h_len[i] ;
    }

    //area of the triangle
    double area = 0.5*h_len[0]*ed_len[0] ;
    if(area <= tolerance_) return ;

    //site
    Eigen::Map<const Vector> v(sites_ + Dim*site) ;

    //site vectors
    Vector sv[3] ;
    for(int i = 0; i < 3; ++i) {
      sv[i] = v-*(c[i]) ;
    }

    //unweighted objective function value
    double local_fx = 0 ;
    for(int i=0; i<3; ++i) {
      for(int j=0; j<=i; ++j) {
        local_fx += sv[i].dot(sv[j]) ;
      }
    }
    local_fx /= 6. ;

    //normal component of the site vector
    const Vector nv = *(c[0]) - v - v.dot(ed[0])*ed[0] - v.dot(h[0])*h[0] ;

    if(anisotropy_ > 1) {
      local_fx += (anisotropy_*anisotropy_ - 1)*nv.dot(nv) ;
    }

    //weighted should add local_fx *= area which is done later to use this
    //intermediate result for gradient computations.

    //gradient of the objective function
    Vector vertex_gradient ;
    const Vector g = *(c[0]) + *(c[1]) + *(c[2]) - 4*v ;
    for(int i=0; i<3; ++i) {
      //gradient wrt. the vertex c[i] of the triangle

      //variations of the integrand wrt. c[i]
      vertex_gradient = *(c[i]) + g ;

      if(anisotropy_ > 1) {
        vertex_gradient -=
          12*(anisotropy_*anisotropy_-1)/h_len[i]*(*(c[(i+1)%3])-v).dot(h[i])*nv ;
      }

      vertex_gradient *= area/6. ;

      //variation of the triangle area wrt. c[i]
      vertex_gradient += 0.5*ed_len[i]*h[i]*local_fx ;

      //composing to get the gradient wrt. the mesh vertices
      //number of mesh vertices involved in this RVD vertex
      if(c[i]->config() == Vertex::ORIGINAL) {
        //original vertex of the mesh
        //grab the portion of the gradient wrt. the mesh vertex
        Eigen::Map<Vector> vert_g(g_ + Dim*c[i]->combinatorics()[0]) ;
        vert_g += factor_ * vertex_gradient / mesh_area_ ;
      } else {
        //get the number of mesh vertices involved
        int comb_size = (c[i]->config() == Vertex::FACE_VERTEX) ? 3 : 2 ;

        //for each vertex in the combinatorics, get the derivative of the RVD
        //Vertex wrt. the mesh vertex, and compose the derivatives.
        Matrix diff_compose ;
        for(int j=0; j<comb_size; ++j) {
          //get the derivative
          c[i]->derivative(j, mesh_, sites_, diff_compose.data()) ;
          //grab the portion of the gradient wrt. the mesh vertex
          Eigen::Map<Vector> vert_g(g_ + Dim*c[i]->combinatorics()[j]) ;
          //compose the gradient
          vert_g += factor_*diff_compose.transpose()*vertex_gradient / mesh_area_ ;
        }
      }
    }

    //finishing the objective function value computation
    fx_ += factor_ * area * local_fx / mesh_area_ ;
  }
} ;

} //end of namespace CVT
} //end of namespace Revoropt

#endif
