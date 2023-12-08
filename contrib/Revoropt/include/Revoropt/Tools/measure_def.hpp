#ifndef _REVOROPT_TOOLS_MEASURE_DEF_HPP_
#define _REVOROPT_TOOLS_MEASURE_DEF_HPP_

#include <Eigen/Dense>

#include "measure_fwd.hpp"
#include "intersections_def.hpp"

namespace Revoropt {

/*{{{ Triangle height and area */

/* Height of a triangle, passing through the first vertex provided */
template<int Dim, typename Scalar>
Scalar triangle_height( const Scalar x0_p[Dim],
                        const Scalar x1_p[Dim],
                        const Scalar x2_p[Dim]
                      ) {
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  //vertices of the triangle
  Eigen::Map<const Vector> x0(x0_p) ;
  Eigen::Map<const Vector> x1(x1_p) ;
  Eigen::Map<const Vector> x2(x2_p) ;

  //base of the triangle
  const Vector base = x2-x1 ;
  const Scalar base_len = base.norm() ;
  if(base_len == 0) return (x0-x1).norm() ;

  //height of the triangle
  Vector height = (x0-x1) ;
  height -= height.dot(base)*base/(base_len*base_len) ;
  return height.norm() ;
}


/* Area of a triangle */
template<int Dim, typename Scalar>
Scalar triangle_area( const Scalar x0_p[Dim],
                      const Scalar x1_p[Dim],
                      const Scalar x2_p[Dim]
                    ) {
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  //vertices of the triangle
  Eigen::Map<const Vector> x0(x0_p) ;
  Eigen::Map<const Vector> x1(x1_p) ;
  Eigen::Map<const Vector> x2(x2_p) ;

  //base of the triangle
  const Vector base = x1-x0 ;
  const Scalar base_len = base.norm() ;
  if(base_len == 0) return 0 ;

  //height of the triangle
  Vector height = (x2-x0) ;
  height -= height.dot(base)*base/(base_len*base_len) ;
  const Scalar height_len = height.norm() ;

  //area of the triangle
  return 0.5*height_len*base_len ;
}

//}}}

/*{{{ Barycentric coordinates of a point whithin a triangle */

template<int Dim, typename Scalar>
Scalar triangle_barycentric_coords( const Scalar x0_p[Dim],
                                    const Scalar x1_p[Dim],
                                    const Scalar x2_p[Dim],
                                    const Scalar p[Dim],
                                    Scalar coords[Dim] //output
                                  ) {
  const Scalar area0 = triangle_area<Dim>(p, x1_p, x2_p) ;
  const Scalar area1 = triangle_area<Dim>(x0_p, p, x2_p) ;
  const Scalar area2 = triangle_area<Dim>(x0_p, x1_p, p) ;
  const Scalar sum = area0 + area1 + area2 ;
  coords[0] = area0 / sum ;
  coords[1] = area1 / sum ;
  coords[2] = area2 / sum ;
}

//}}}

/*{{{ Find a projection plane for points based on SVD */

template< typename Scalar, int Dim >
void svd_plane(
    const Scalar* coords,
    unsigned int size ,
    Scalar paramU[Dim], //output
    Scalar paramV[Dim] //output
    ) {
  //std::cout << "Getting svd parametrisation" << std::endl ;
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;
  typedef Eigen::Matrix<Scalar,Dim, Eigen::Dynamic> PtMatrix ;

  //std::cout << "Dim is " << Dim << std::endl ;
  //std::cout << "Size is " << size << std::endl ;

  //centroid
  Vector g = Vector::Zero() ;
  for(unsigned int i = 0; i < size; ++i) {
    Eigen::Map<const Vector> p(coords + Dim*i) ;
    g += p ;
  }
  g /= size ;

  //point matrix
  //std::cout << "Initializing matrix" << std::endl ;
  PtMatrix M(Dim, size) ;
  //std::cout << "Filling matrix" << std::endl ;
  for(unsigned int i = 0; i < size; ++i) {
    Eigen::Map<const Vector> p(coords + Dim*i) ;
    M.col(i) = p-g ;
  }

  //svd
  //std::cout << "SVD" << std::endl ;
  Eigen::JacobiSVD<PtMatrix> svd(M, Eigen::ComputeFullU) ;
  //main eigenvectors
  //std::cout << "Result" << std::endl ;
  Eigen::Map<Vector> u(paramU) ;
  u = svd.matrixU().col(0) ;
  Eigen::Map<Vector> v(paramV) ;
  v = svd.matrixU().col(1) ;
  //std::cout << "u vector :" << std::endl << u << std::endl ;
  //std::cout << "v vector :" << std::endl << v << std::endl ;
}

//}}}

/*{{{ Disc areas */

/* Area of a disc sector, defined by the disc radius r
 * and the length d of the chord joining the extremities
 * of the sector
 *
 *     /\
 *    /  \ r
 *   /    \
 *  /___d__\
 *  \______/
 */
template<typename Scalar>
Scalar disc_sector_area( const Scalar radius,
                         const Scalar chord_len
                       ) {
  //sine of half the sector angle
  const Scalar d = chord_len/(2*radius) ;
  //check whether the chord is a diameter of the circle
  if(d >= 1) {
    //half circle area
    return 0.5*M_PI*radius*radius ;
  } else {
    //angle of the sector
    Scalar halftheta = asin(d) ;
    //area
    return halftheta*radius*radius ;
  }
}

/* Area of a circular segment. The parameters are the same as above. */
template<typename Scalar>
Scalar circle_segment_area( const Scalar radius,
                            const Scalar chord_len
                          ) {
  //sine of half the sector angle
  const Scalar d = chord_len/(2*radius) ;
  //check whether the chord is a diameter of the circle
  if(d >= 1) {
    return 0.5*M_PI*radius*radius ;
  } else {
    //angle of the sector
    Scalar theta = 2*asin(d) ;
    //area
    return 0.5*(theta-sin(theta))*radius*radius ;
  }
}

/* Triangle sphere intersection area */
namespace triangle_sphere_intersection_area_impl {

template<typename Scalar>
Scalar tsia_no_vertex_in_circle( const Scalar x0_coords[2],
                                 const Scalar x1_coords[2],
                                 const Scalar x2_coords[2],
                                 const Scalar c_coords[2],
                                 Scalar radius
                               ) {
  //Vector type
  typedef Eigen::Matrix<Scalar,2,1> Vector ;

  //radius and circle area
  const Scalar circle_area = M_PI*radius*radius ;

  Eigen::Map<const Vector> c(c_coords) ;
  const Scalar* x[3] = {x0_coords, x1_coords, x2_coords} ;

  //compute edge intersections, and sum the circle area out of the triangle
  Scalar area_out = 0 ;
  bool intersects = false ;
  for(int i = 0; i < 3; ++i) {
    //vertices of the edge
    Eigen::Map<const Vector> v0(x[i]) ;
    Eigen::Map<const Vector> v1(x[(i+1)%3]) ;
    Eigen::Map<const Vector> v2(x[(i+2)%3]) ;
    const Vector edge = (v1-v0) ;

    //barycentric coordinates of the circle / segment intersection
    Scalar intersections[2] ;
    const unsigned char ninter = segment_sphere_intersections<2>(
      v0.data(), v1.data(), c.data(), radius, intersections
    ) ;

    if(ninter > 0) {
      intersects = true ;
      //ninter can only be 2 since the two vertices of the edge are out
      assert( (ninter == 2)
              || "The edge intersects once with both vertices out."
            ) ;

      //positions of the intersections
      const Vector i0 = v0 + intersections[0]*edge ;
      const Vector i1 = v0 + intersections[1]*edge ;

      //area of the piece of circle out of that edge
      const Scalar segment_area = circle_segment_area(radius, (i0-i1).norm()) ;

      //check the side of the edge for the circle center
      const Vector redge = v2-v0 ;
      const Vector tedge = c-v0 ;
      const char in_side = orientation(edge.data(), redge.data()) ;
      if(orientation(edge.data(), tedge.data()) != in_side) {
        area_out += circle_area - segment_area ;
      } else {
        area_out += segment_area ;
      }
    }
  }

  assert(area_out == area_out) ;

  if(intersects) {
    //the circle intersects edges, return the circle area minus the area out
    return circle_area - area_out ;
  } else {
    //no edge intersects
    if(point_in_triangle<2>(c_coords, x0_coords, x1_coords, x2_coords)) {
      //the circle is completely in the triangle
      return circle_area ;
    } else {
      //the circle is completely out of the triangle
      return 0 ;
    }
  }
}

/* The vertex inside is x0 */
template<typename Scalar>
Scalar tsia_one_vertex_in_circle( const Scalar x0_coords[2],
                                  const Scalar x1_coords[2],
                                  const Scalar x2_coords[2],
                                  const Scalar c_coords[2],
                                  Scalar radius
                                ) {
  //Vector type
  typedef Eigen::Matrix<Scalar,2,1> Vector ;

  //radius and circle area
  const Scalar circle_area = M_PI*radius*radius ;

  Eigen::Map<const Vector> c(c_coords) ;
  Eigen::Map<const Vector> x0(x0_coords) ;
  Eigen::Map<const Vector> x1(x1_coords) ;
  Eigen::Map<const Vector> x2(x2_coords) ;

  //intersections with the edges adjacent to x0
  Scalar intersections[2] ;
  unsigned char ninter ;

  ninter =  segment_sphere_intersections<2>(
    x0.data(), x1.data(), c.data(), radius, intersections
  ) ;
  assert( (ninter == 1)
          || "x0 should be in the circle and x1 out."
        ) ;
  const Vector i01 = x0 + intersections[0]*(x1-x0) ;

  ninter =  segment_sphere_intersections<2>(
    x0.data(), x2.data(), c.data(), radius, intersections
  ) ;
  assert( (ninter == 1)
          || "x0 should be in the circle and x2 out."
        ) ;
  const Vector i02 = x0 + intersections[0]*(x2-x0) ;

  //area without considering the last edge
  Scalar area = triangle_area<2>(x0_coords, i01.data(), i02.data()) ;
  const Vector iedge0 = i02 - i01 ;
  const Vector redge0 = x0 - i01 ;
  const Vector tedge0 = c - i01 ;
  const char in_side0 = orientation(iedge0.data(), redge0.data()) ;
  if(orientation(iedge0.data(), tedge0.data()) != in_side0) {
    area += circle_area - circle_segment_area(radius, (iedge0).norm()) ;
  } else {
    area += circle_segment_area(radius, (iedge0).norm()) ;
  }

  //check the intersection of the last edge
  ninter =  segment_sphere_intersections<2>(
    x1.data(), x2.data(), c.data(), radius, intersections
  ) ;
  if(ninter > 0) {
    //ninter can only be 2 since the two vertices of the edge are out
    assert( (ninter == 2)
            || "Edge intersects once with both vertices out."
          ) ;

    //positions of the intersections
    const Vector edge = (x2-x1) ;
    const Vector i0 = x1 + intersections[0]*edge ;
    const Vector i1 = x1 + intersections[1]*edge ;

    //area of the piece of circle out of that edge
    const Scalar segment_area = circle_segment_area(radius, (i0-i1).norm()) ;

    //check the side of the edge for the circle center
    const Vector redge = (x0-x1) ;
    const Vector tedge = (c-x1) ;
    const char in_side = orientation(edge.data(), redge.data()) ;
    if(orientation(edge.data(), tedge.data()) != in_side) {
      area -= circle_area - segment_area ;
    } else {
      area -= segment_area ;
    }
  }
  assert(area == area) ;
  //prevent warning
  ninter += ninter ;
  return area ;
}

/* The vertices inside are x0 and x1 */
template<typename Scalar>
Scalar tsia_two_vertices_in_circle( const Scalar x0_coords[2],
                                    const Scalar x1_coords[2],
                                    const Scalar x2_coords[2],
                                    const Scalar c_coords[2],
                                    Scalar radius
                                  ) {
  //Vector type
  typedef Eigen::Matrix<Scalar,2,1> Vector ;

  //radius and circle area
  const Scalar circle_area = M_PI*radius*radius ;

  Eigen::Map<const Vector> c(c_coords) ;
  Eigen::Map<const Vector> x0(x0_coords) ;
  Eigen::Map<const Vector> x1(x1_coords) ;
  Eigen::Map<const Vector> x2(x2_coords) ;

  //intersections with the edges adjacent to x2
  Scalar intersections[2] ;
  unsigned char ninter ;

  ninter =  segment_sphere_intersections<2>(
    x0.data(), x2.data(), c.data(), radius, intersections
  ) ;
  assert( (ninter == 1)
          && "x0 should be in the circle and x2 out."
        ) ;
  const Vector i02 = x0 + intersections[0]*(x2-x0) ;

  ninter =  segment_sphere_intersections<2>(
    x1.data(), x2.data(), c.data(), radius, intersections
  ) ;
  assert( (ninter == 1)
          && "x1 should be in the circle and x2 out."
        ) ;
  const Vector i12 = x1 + intersections[0]*(x2-x1) ;

  //area without considering the last edge
  Scalar area = triangle_area<2>(x0_coords, i02.data(), i12.data()) ;
  area += triangle_area<2>(x0_coords, x1_coords, i12.data()) ;
  const Vector iedge = i12 - i02 ;
  const Vector redge = x0 - i02 ;
  const Vector tedge = c - i02 ;
  const char in_side = orientation(iedge.data(), redge.data()) ;
  if(orientation(iedge.data(), tedge.data()) != in_side) {
    area += circle_area - circle_segment_area(radius, (iedge).norm()) ;
  } else {
    area += circle_segment_area(radius, (iedge).norm()) ;
  }
  assert(area == area) ;

  //prevent warning
  ninter += ninter ;
  return area ;
}

template<typename Scalar>
Scalar tsia_three_vertices_in_circle( const Scalar x0_coords[2],
                                      const Scalar x1_coords[2],
                                      const Scalar x2_coords[2]
                                    ) {
  return triangle_area<2>(x0_coords, x1_coords, x2_coords) ;
}

template< int Dim, typename Scalar >
class tsia_impl {
  public:
  static Scalar do_it( const Scalar x0_coords[Dim],
                       const Scalar x1_coords[Dim],
                       const Scalar x2_coords[Dim],
                       const Scalar c_coords[Dim],
                       Scalar radius
                     ) {
    //vector type
    typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

    Eigen::Map<const Vector> c(c_coords) ;
    Eigen::Map<const Vector> x0(x0_coords) ;
    Eigen::Map<const Vector> x1(x1_coords) ;
    Eigen::Map<const Vector> x2(x2_coords) ;

    //projection matrix
    Eigen::Matrix<Scalar,2,Dim,Eigen::RowMajor> P ;
    //base of the triangle
    P.row(0) = x1-x0 ;
    const Scalar base_len = P.row(0).norm() ;
    if(base_len == 0) return 0 ;
    P.row(0) /= base_len ;

    //height of the triangle
    P.row(1) = x2-x0 ;
    P.row(1) -= P.row(1).dot(P.row(0))*P.row(0) ;
    const Scalar height_len = P.row(1).norm() ;
    if(height_len == 0) return 0 ;
    P.row(1) /= height_len ;

    //center projection vector
    Vector cproj = c - x0 ;

    cproj -= cproj.dot(P.row(0))*P.row(0) + cproj.dot(P.row(1))*P.row(1) ;
    const Scalar p_radius = sqrt(radius*radius - cproj.dot(cproj)) ;


    //radius of the circular intersection of the sphere and the triangle plane
    if(p_radius > 0) {
      //the sphere intersects the triangle plane
      //project enerything
      Eigen::Matrix<Scalar,2,1> cp, x0p, x1p, x2p ;
      cp = P*(c-x0) ;
      x0p = Eigen::Matrix<Scalar,2,1>::Zero() ;
      x1p = P*(x1-x0) ;
      x2p = P*(x2-x0) ;

      //switch to 2D
      return tsia_impl<2,Scalar>::do_it( x0p.data(),
                                         x1p.data(),
                                         x2p.data(),
                                         cp.data(),
                                         p_radius
                                       ) ;
    } else {
      //the sphere does not intersect the triangle plane
      return 0 ;
    }
  }
} ;

template< typename Scalar >
class tsia_impl<2,Scalar> {
  public:
  static Scalar do_it( const Scalar x0_coords[2],
                       const Scalar x1_coords[2],
                       const Scalar x2_coords[2],
                       const Scalar c_coords[2],
                       Scalar radius
                     ) {
    //check vertices inside
    unsigned char vertex_status ;
    vertex_status = point_in_sphere<2>(x0_coords, c_coords, radius) ;
    vertex_status *= 2 ;
    vertex_status += point_in_sphere<2>(x1_coords, c_coords, radius) ;
    vertex_status *= 2 ;
    vertex_status += point_in_sphere<2>(x2_coords, c_coords, radius) ;

    //handle the cases
    if(vertex_status == 0) {
      //no vertex_inside
      return tsia_no_vertex_in_circle( x0_coords,
                                       x1_coords,
                                       x2_coords,
                                       c_coords,
                                       radius
                                     ) ;
    } else if(vertex_status == 1) {
      //x2 inside
      return tsia_one_vertex_in_circle( x2_coords,
                                        x0_coords,
                                        x1_coords,
                                        c_coords,
                                        radius
                                      ) ;
    } else if(vertex_status == 2) {
      //x1 inside
      return tsia_one_vertex_in_circle( x1_coords,
                                        x2_coords,
                                        x0_coords,
                                        c_coords,
                                        radius
                                      ) ;
    } else if(vertex_status == 3) {
      //x1 and x2 inside
      return tsia_two_vertices_in_circle( x1_coords,
                                          x2_coords,
                                          x0_coords,
                                          c_coords,
                                          radius
                                        ) ;
    } else if(vertex_status == 4) {
      //x0 inside
      return tsia_one_vertex_in_circle( x0_coords,
                                        x1_coords,
                                        x2_coords,
                                        c_coords,
                                        radius
                                      ) ;
    } else if(vertex_status == 5) {
      //x0 and x2 inside
      return tsia_two_vertices_in_circle( x2_coords,
                                          x0_coords,
                                          x1_coords,
                                          c_coords,
                                          radius
                                        ) ;
    } else if(vertex_status == 6) {
      //x0 and x1 inside
      return tsia_two_vertices_in_circle( x0_coords,
                                          x1_coords,
                                          x2_coords,
                                          c_coords,
                                          radius
                                        ) ;
    } else if(vertex_status == 7) {
      //all vertices inside
      return tsia_three_vertices_in_circle( x0_coords,
                                            x1_coords,
                                            x2_coords
                                          ) ;
    }

    return 0 ;
  }
} ;

} //end of namespace triangle_sphere_intersection_area_impl

/* Triangle sphere intersection area, general case */
template<int Dim, typename Scalar>
Scalar triangle_sphere_intersection_area( const Scalar x0_coords[Dim],
                                          const Scalar x1_coords[Dim],
                                          const Scalar x2_coords[Dim],
                                          const Scalar c_coords[Dim],
                                          Scalar radius
                                        ) {
  //bring in the handling of the various cases
  using namespace triangle_sphere_intersection_area_impl ;

  return tsia_impl<Dim,Scalar>::do_it( x0_coords,
                                       x1_coords,
                                       x2_coords,
                                       c_coords,
                                       radius
                                     ) ;
}


//}}}

/*{{{ Angles */

template<int Dim, typename Scalar>
Scalar angle_cos( const Scalar p0[Dim], const Scalar p1[Dim], const Scalar p2[Dim]) ;

//}}}

} //end of namespace Revoropt

#endif
