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
#ifndef _REVOROPT_RVD_POLYGON_HPP_
#define _REVOROPT_RVD_POLYGON_HPP_

#include <Eigen/Dense>
#include <vector>
#include <iostream>

namespace Revoropt {

/**{{{ Vertices **/

/* A RVD vertex acts as a traditionnal vector equipped with the combinatorial
 * information which defines it. The vertices of the input mesh and sites of the
 * diagram wich are involved in this combinatorics are stored, and the position
 * of the point can be recomputed from thins information. */

template<typename _Triangulation>
class RVDVertex : public Eigen::Matrix<double,_Triangulation::VertexDim,1> {

  public :

    /** Typedefs **/
    typedef _Triangulation Triangulation ;
    enum { Dim = Triangulation::VertexDim } ;
    typedef Eigen::Matrix<double,Dim,1> Vector ;
    const static unsigned int NO_COMBINATORICS = -1 ;

    /* The different configurations of the vertices of a restricted Voronoi diagram.
     * ORIGINAL is an original vertex of the input mesh, EDGE_VERTEX is the
     * intersection between an edge of the input mesh and a bissector of the Voronoi
     * diagram, and FACE_VERTEX is the intersection between a face of the input mesh
     * and a Voronoi edge. */

    enum Config {
      UNDEFINED,
      ORIGINAL,
      EDGE_VERTEX,
      FACE_VERTEX
    } ;


    /** Initialization **/
    /* build an UNDEFINED vertex */
    RVDVertex() { reset() ; }

    /* build an ORIGINAL vertex */
    RVDVertex( unsigned int x1_id,
               const Triangulation* mesh
             ) {
      reset(x1_id,mesh) ;
    }
    /* build an EDGE_VERTEX */
    RVDVertex( unsigned int x1_id, unsigned int x2_id,
               unsigned int v1_id, unsigned int v2_id,
               const Triangulation* mesh, const double* sites
             ) {
      reset(x1_id,x2_id,v1_id,v2_id,mesh,sites) ;
    }
    /* build a FACE_VERTEX */
    RVDVertex( unsigned int x1_id, unsigned int x2_id, unsigned int x3_id,
               unsigned int v1_id, unsigned int v2_id, unsigned int v3_id,
               const Triangulation* mesh, const double* sites
             ) {
      reset(x1_id,x2_id,x3_id,v1_id,v2_id,v3_id,mesh,sites) ;
    }

    /** Modification **/

    /* change into an UNDEFINED vertex */
    void reset() {
      config_ = UNDEFINED ;
    }

    /* change into an ORIGINAL vertex */
    void reset( unsigned int x1_id,
                const Triangulation* mesh
              ) {
      //set configuration
      config_ = ORIGINAL ;
      //set combinatorics
      combinatorics_[0] = x1_id ;
      combinatorics_[1] = NO_COMBINATORICS ;
      combinatorics_[2] = NO_COMBINATORICS ;
      combinatorics_[3] = NO_COMBINATORICS ;
      combinatorics_[4] = NO_COMBINATORICS ;
      combinatorics_[5] = NO_COMBINATORICS ;
      //compute corresponding position
      Eigen::Map<const Vector> x(mesh->vertex(combinatorics_[0])) ;
      this->array() = x ;
    }

    /* change into an EDGE_VERTEX */
    void reset( unsigned int x1_id, unsigned int x2_id,
                unsigned int v1_id, unsigned int v2_id,
                const Triangulation* mesh, const double* sites
              ) {
      //set configuration
      config_ = EDGE_VERTEX ;
      //set combinatorics
      combinatorics_[0] = x1_id ;
      combinatorics_[1] = x2_id ;
      combinatorics_[2] = NO_COMBINATORICS ;
      combinatorics_[3] = v1_id ;
      combinatorics_[4] = v2_id ;
      combinatorics_[5] = NO_COMBINATORICS ;
      //compute corresponding position
      //get the two vertices
      Eigen::Map<const Vector> x1(mesh->vertex(x1_id)) ;
      Eigen::Map<const Vector> x2(mesh->vertex(x2_id)) ;
      //get the two sites
      Eigen::Map<const Vector> v1(sites+Dim*v1_id) ;
      Eigen::Map<const Vector> v2(sites+Dim*v2_id) ;

      //compute the intersection between the bissector and the edge
      const Vector diff_sites = v2-v1 ;
      const Vector mid_sites = 0.5*(v1+v2) ;
      const Vector edge = x2-x1 ;

      const Vector pos = x1
                       + ( diff_sites.dot(mid_sites - x1)
                           / diff_sites.dot(edge)
                         )
                       * edge ;

      //position becomes the RVDVertex position
      this->array() = pos ;
    }

    /* change into a FACE_VERTEX */
    void reset( unsigned int x1_id, unsigned int x2_id, unsigned int x3_id,
                unsigned int v1_id, unsigned int v2_id, unsigned int v3_id,
                const Triangulation* mesh, const double* sites
              ) {
      //set configuration
      config_ = FACE_VERTEX ;
      //set combiatorics
      combinatorics_[0] = x1_id ;
      combinatorics_[1] = x2_id ;
      combinatorics_[2] = x3_id ;
      combinatorics_[3] = v1_id ;
      combinatorics_[4] = v2_id ;
      combinatorics_[5] = v3_id ;
      //compute corresponding position
      //get the three vertices
      Eigen::Map<const Vector> x1(mesh->vertex(x1_id)) ;
      Eigen::Map<const Vector> x2(mesh->vertex(x2_id)) ;
      Eigen::Map<const Vector> x3(mesh->vertex(x3_id)) ;

      //get the three sites
      Eigen::Map<const Vector> v1(sites+Dim*v1_id) ;
      Eigen::Map<const Vector> v2(sites+Dim*v2_id) ;
      Eigen::Map<const Vector> v3(sites+Dim*v3_id) ;

      //compute the intersection between the bissectors and the face
      const double c1 = (x2-x1).dot(v2-v1) ;
      const double c2 = (x3-x1).dot(v2-v1) ;
      const double c3 = 0.5*(v1+v2-2*x1).dot(v2-v1) ;
      const double c4 = (x2-x1).dot(v3-v1) ;
      const double c5 = (x3-x1).dot(v3-v1) ;
      const double c6 = 0.5*(v1+v3-2*x1).dot(v3-v1) ;

      const double det = (c1*c5-c2*c4) ;
#ifdef DEBUG
      if(det == 0) {
        std::cout << "0 determinant : "
                  << c1 << ", "
                  << c5 << ", "
                  << c2 << ", "
                  << c4 << std::endl ;
        std::cout << "Combinatorics : "
                  << combinatorics_[3] << ", "
                  << combinatorics_[4] << ", "
                  << combinatorics_[5] << std::endl ;
        std::cout << "v1 : ["
                  << v1[0] << ", "
                  << v1[1] << ", "
                  << v1[2] << " ]" << std::endl ;
        std::cout << "v2 : [ "
                  << v2[0] << ", "
                  << v2[1] << ", "
                  << v2[2] << " ]" << std::endl ;
        std::cout << "v3 : ["
                  << v3[0] << ", "
                  << v3[1] << ", "
                  << v3[2] << " ]" << std::endl ;
      }
#endif
      const double denom = 1/det ;
      const double bary1 = denom*(c3*c5-c2*c6) ;
      const double bary2 = denom*(c1*c6-c3*c4) ;

      const Vector pos = x1 + bary1*(x2-x1) + bary2*(x3-x1) ;

      //position becomes the
      this->array() = pos ;
    }

    /* Access to the configuration of the point */
    Config config() const { return config_ ; } ;

    /* Access to the combinatorics */
    const unsigned int* combinatorics() const { return combinatorics_ ; } ;

    /** Gradient computation **/
    /* WARNING : the gradient is filled in the output in COLUMN MAJOR order,
     * since this is the default behaviour in Eigen. You can probably work
     * around this by #defining the EIGEN_DEFAULT_MATRIX_STORAGE_ORDER_OPTION
     * to Eigen::RowMajor, which would be dangerous and ugly. */

    void derivative( const int comb_index,
                     const Triangulation* mesh,
                     const double* sites,
                     double* output
                   ) const {
      //fill result with zeros
      std::fill(output, output+Dim*Dim, 0) ;

      //filter cases
      switch(config_) {
        case UNDEFINED: {
          break ;
        }
        case ORIGINAL: {
          //the vertex only depends on one vertex of the mesh
          if(comb_index != 0) break ;

          //if the derivative is requested for this vertex, return identity
          for(int i=0; i<Dim; ++i) {
            output[Dim*i+i] = 1 ;
          }
          break ;
        }
        case EDGE_VERTEX: {
          //the vertex only depends on two vertices and two sites
          if((comb_index==2) || (comb_index==5)) break ;

          //check whether the derivative is requested wrt a vertex or a site
          if(comb_index < 3) {
            //derivative wrt a vertex
            e_vertex_derivative(comb_index,mesh,sites,output) ;
          } else {
            //derivative wrt a site
            e_site_derivative(comb_index,mesh,sites,output) ;
          }
          break ;
        }
        case FACE_VERTEX: {
          //check whether the derivative is requested wrt a vertex or a site
          if(comb_index < 3) {
            //derivative with respect to a vertex
            f_vertex_derivative(comb_index,mesh,sites,output) ;
          } else {
            //derivative with respect to a site
            f_site_derivative(comb_index,mesh,sites,output) ;
          }
          break ;
        }
      }
    }

  private :

    /* Specific gradient computation for every non trivial configuration */
    void e_vertex_derivative( const int comb_index,
                              const Triangulation* mesh,
                              const double* sites,
                              double* output
                            ) const {
      //get the two sites
      Eigen::Map<const Vector> v0(sites+Dim*combinatorics_[3]) ;
      Eigen::Map<const Vector> v1(sites+Dim*combinatorics_[4]) ;

      //get the two vertices
      Eigen::Map<const Vector> x0(
        mesh->vertex(combinatorics_[ comb_index     ])
      ) ;
      Eigen::Map<const Vector> x1(
        mesh->vertex(combinatorics_[(comb_index+1)%2])
      ) ;

      //compute the gradient
      const Vector edge = x1-x0 ;
      const Vector site_diff = v1-v0 ;
      const double k = 2*edge.dot(site_diff) ;
      const double a = (v0+v1-2*x0).dot(site_diff)/k ;

      Eigen::Map< Eigen::Matrix<double,Dim,Dim> > grad(output) ;
      grad = edge*site_diff.transpose() ;
      grad.noalias() = 2*(a-1)/k*grad ;
      for(int i=0; i<Dim; ++i) {
        grad(i,i) += (1-a) ;
      }
    }

    void e_site_derivative( const int comb_index,
                            const Triangulation* mesh,
                            const double* sites,
                            double* output
                          ) const {
      //get the two sites
      Eigen::Map<const Vector> v0(
        sites+Dim*combinatorics_[comb_index]
      ) ;
      Eigen::Map<const Vector> v1(
        sites+Dim*combinatorics_[3+((comb_index-2)%2)]
      ) ;

      //get the two vertices
      Eigen::Map<const Vector> x0(mesh->vertex(combinatorics_[0])) ;
      Eigen::Map<const Vector> x1(mesh->vertex(combinatorics_[1])) ;

      //compute the gradient
      const Vector edge = x1-x0 ;
      const Vector site_diff = v1-v0 ;
      const double half_k = edge.dot(site_diff) ;

      Eigen::Map< Eigen::Matrix<double,Dim,Dim> > grad(output) ;
      grad = edge*((*this)-v0).transpose() ;
      grad.noalias() = grad/half_k ;
    }

    void f_vertex_derivative( const int comb_index,
                              const Triangulation* mesh,
                              const double* sites,
                              double* output
                            ) const {
      //get the three sites
      Eigen::Map<const Vector> v0(sites+Dim*combinatorics_[3]) ;
      Eigen::Map<const Vector> v1(sites+Dim*combinatorics_[4]) ;
      Eigen::Map<const Vector> v2(sites+Dim*combinatorics_[5]) ;

      //get the three vertices
      Eigen::Map<const Vector> x0(
        mesh->vertex(combinatorics_[ comb_index     ])
      ) ;
      Eigen::Map<const Vector> x1(
        mesh->vertex(combinatorics_[(comb_index+1)%3])
      ) ;
      Eigen::Map<const Vector> x2(
        mesh->vertex(combinatorics_[(comb_index+2)%3])
      ) ;

      //compute the gradient
      const double c0 = (x0-x2).dot(v1-v0) ;
      const double c1 = (x0-x2).dot(v2-v0) ;
      const double c2 = (x2-x1).dot(v1-v0) ;
      const double c3 = (x2-x1).dot(v2-v0) ;

      const double b0 = (v0+v1-2*x2).dot(v1-v0) ;
      const double b1 = (v0+v2-2*x2).dot(v2-v0) ;

      const double quarter_k = (c0*c3-c2*c1) ;
      const double a = (b0*c3-c2*b1)/(2*quarter_k) ;

      //TODO cache the first part of this computation for other gradients
      Eigen::Map< Eigen::Matrix<double,Dim,Dim> > grad(output) ;
      grad = x0*(x2-x1).transpose()
           + x1*(x0-x2).transpose()
           + x2*(x1-x0).transpose() ;
      grad = grad * (  v0*(v2-v1).transpose()
                     + v1*(v0-v2).transpose()
                     + v2*(v1-v0).transpose() ) ;
      grad.noalias() = -grad/quarter_k ;
      for(int i=0; i<Dim; ++i) {
        grad(i,i) += 1 ;
      }
      grad.noalias() = a*grad ;
    }

    void f_site_derivative( const int comb_index,
                            const Triangulation* mesh,
                            const double* sites,
                            double* output
                          ) const {
      //get the three sites
      Eigen::Map<const Vector> v0(
        sites+Dim*combinatorics_[    comb_index      ]
      ) ;
      Eigen::Map<const Vector> v1(
        sites+Dim*combinatorics_[3+((comb_index-2)%3)]
      ) ;
      Eigen::Map<const Vector> v2(
        sites+Dim*combinatorics_[3+((comb_index-1)%3)]
      ) ;

      //get the three vertices
      Eigen::Map<const Vector> x0(mesh->vertex(combinatorics_[0])) ;
      Eigen::Map<const Vector> x1(mesh->vertex(combinatorics_[1])) ;
      Eigen::Map<const Vector> x2(mesh->vertex(combinatorics_[2])) ;

      //compute the gradient
      const double c0 = (x1-x0).dot(v0-v2) ;
      const double c1 = (x2-x0).dot(v0-v2) ;
      const double c2 = (x1-x0).dot(v2-v1) ;
      const double c3 = (x2-x0).dot(v2-v1) ;

      const double quarter_k = (c0*c3-c2*c1) ;

      Eigen::Map< Eigen::Matrix<double,Dim,Dim> > grad(output) ;
      grad = x0*(x2-x1).transpose()
           + x1*(x0-x2).transpose()
           + x2*(x1-x0).transpose() ;
      grad = grad * (v1-v2) * (v0-(*this)).transpose() ;
      grad.noalias() = grad/quarter_k ;
    }

    /* Configuration */
    Config config_ ;

    /* Sites and vertices involved. The array is arranged as follows depending
     * on the verrtex configuration, with the mesh vertices denoted by x_ and
     * the sites as v_ :
     *   - ORIGINAL    : [ x0, - , - , - , - , -  ]
     *   - EDGE_VERTEX : [ x0, x1, - , v0, v1, -  ]
     *   - FACE_VERTEX : [ x0, x1, x2, v0, v1, v2 ]
     * */
    unsigned int combinatorics_[6] ;
} ;

//}}}

/**{{{ Edges **/

/* A PolygonEdge encodes the vertex it starts from, its configuration, and
 * depending on its configuration, the corresponding symbolic information :
 *   -- FACE_EDGE : the index of the edge within the face ;
 *   -- BISECTOR_EDGE : the index of the site beyound the edge */

template<typename Triangulation>
class RVDEdge {

  public :

  /* There are two kinds of edges. A FACE_EDGE comes from the initial edges of the
   * clipped triangle, and a BISECTOR_EDGE results from the intersection between
   * the triangle and a bisector. */

  enum Config {
    FACE_EDGE,
    BISECTOR_EDGE
  } ;

  /* Configuration */
  Config config ;

  /* Origin Vertex */
  RVDVertex<Triangulation> vertex ;

  /* combinatorics */
  unsigned int combinatorics ;
} ;

//}}}

/**{{{ Polygons **/

/* Beware that inheriting from stl vector can be dangerous, since the destructor
 * of vectors is not declared virtual. This not a problem here, since we do not
 * need a destructor, and we do not intend to cas RVDPolygon pointers as vector
 * pointers.*/
template<typename _Triangulation>
class RVDPolygon : public std::vector< RVDEdge<_Triangulation> > {

  public :

  /* Typedefs */
  typedef _Triangulation Triangulation ;
  enum { Dim = Triangulation::VertexDim } ;
  typedef Eigen::Matrix<double,Dim,1> Vector ;

  /* Empty initialization */
  RVDPolygon() {} ;

  /* Initialization from a triangle of a mesh */
  RVDPolygon( unsigned int triangle,
              const Triangulation* mesh
            ) {
    reset(triangle, mesh) ;
  }

  /* Reset to a triangle of a mesh */
  void reset( unsigned int triangle,
              const Triangulation* mesh
            ) {
    //resize to three vertices
    (*this).resize(3) ;

    //get the triangle combinatorics from the mesh
    const unsigned int* triangle_verts = mesh->face(triangle) ;

    //assign the init_polygon
    for(int i=0; i<3; ++i) {
      //reset vertex
      const unsigned int edge_vertex = triangle_verts[i] ;
      (*this)[i].vertex.reset(edge_vertex,mesh) ;

      //assign edge combinatorics as its index within the triangle
      (*this)[i].combinatorics = i ;
    }
  }
} ;

//}}}


} //end of namespace Revoropt

#endif
