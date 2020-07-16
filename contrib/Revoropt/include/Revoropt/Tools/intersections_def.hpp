#ifndef _REVOROPT_TOOLS_INTERSECTIONS_DEF_HPP_
#define _REVOROPT_TOOLS_INTERSECTIONS_DEF_HPP_

#include <Eigen/Dense>

#include "intersections_fwd.hpp"

namespace Revoropt {

/* 2d orientation check */
template<typename Scalar>
char orientation( const Scalar v0[2], const Scalar v1[2] ) {
  Scalar det = v0[0]*v1[1] - v1[0]*v0[1] ;
  if(det > 0) return 1 ;
  if(det < 0) return -1 ;
  return 0 ;
}

/* Checks whether a point is in a segment (including endpoints)
 * If the offset pointer is provided, it is filled with the value of a
 * such that p = p0 + a*(p1-p0). If the p is not in the segment, the point
 * q = p0 + a*(p1-p0) is the point of the segment nearest to p. */
template<int Dim, typename Scalar>
bool point_in_segment( const Scalar p_coords[Dim],
                       const Scalar p0_coords[Dim],
                       const Scalar p1_coords[Dim],
                       Scalar* offset //output
                     ) {
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  //segment extremities and point
  Eigen::Map<const Vector> p0(p0_coords) ;
  Eigen::Map<const Vector> p1(p1_coords) ;
  Eigen::Map<const Vector> p(p_coords) ;

  //direction of the segment
  Vector u = p1-p0 ;
  const Scalar u_len = u.norm() ;
  if(u_len == 0) {
    //p1 and p0 are the same point
    if(offset != NULL) {
      //by convention, p0 is the nearest point
      *offset = 0 ;
    }
    //check whether p is that point too
    return (p == p0) ;
  }
  u /= u_len ;
  //project p on the segment line
  const Vector p_vect = p-p0 ;
  const Scalar p_offset = p_vect.dot(u) ;
  //check that the projection is within the extremities
  if(p_offset < 0) {
    if(offset != NULL) {
      *offset = 0 ;
    }
    return false ;
  }
  if(p_offset > u_len) {
    if(offset != NULL) {
      *offset = 1 ;
    }
    return false ;
  }
  //no return, the projection is within the segment
  if(offset != NULL) {
    //assign the offset
    *offset = p_offset / u_len ;
  }
  //check that the projected point is the actual point
  return (p_offset == p_vect.norm()) ;
}

/* Segment intersection */
/* Returns true if the segments are coplanar and intersect.
 * If the s0_offset pointer is provided, it is filled with the value of a
 *   such that the intersection I1 = p0 + a*(p1-p0). If the segments do not
 *   intersect, I0 is the point of [p0,p1] nearest to [p2,p3].
 * If the s1_offset pointer is provided, it is filled with the value of b
 *   such that the intersection I2 = p2 + b*(p3-p2). If the segments do not
 *   intersect, I1 is the point of [p2,p3] nearest to [p0,p1].
 * If the segments do not intersect, I0 and I1 are the points archieving the
 * smallest distance between [p0,p1] and [p2,p3]. */

namespace segment_intersection_impl{

template<int Dim, typename Scalar>
class si_impl {
  public:
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;
  //2d vector type
  typedef Eigen::Matrix<Scalar,2,1> Vector2 ;

  static bool do_it( const Scalar p0_coords[Dim],
                     const Scalar p1_coords[Dim],
                     const Scalar p2_coords[Dim],
                     const Scalar p3_coords[Dim],
                     Scalar* s0_offset, //output
                     Scalar* s1_offset  //output
                   ) {
    //segment extremities
    Eigen::Map<const Vector> p0(p0_coords) ;
    Eigen::Map<const Vector> p1(p1_coords) ;
    Eigen::Map<const Vector> p2(p2_coords) ;
    Eigen::Map<const Vector> p3(p3_coords) ;

    //projection matri on a plane parallel to both segments
    Eigen::Matrix<Scalar,2,Dim> P ;

    //unit direction of the first segment
    P.row(0) = p1-p0 ;
    const Scalar P0_len = P.row(0).norm() ;
    if(P0_len == 0) {
      //the first segment is reduced to a point
      if(s0_offset != NULL) {
        //by convention the p0 is nearest to [p2,p3]
        *s0_offset = 0 ;
      }
      //point_segment intersection
      return point_in_segment<Dim>(p0_coords, p2_coords, p3_coords, s1_offset) ;
    }
    P.row(0) /= P0_len ;

    //direction of the second segment
    P.row(1) = p3-p2 ;
    if(P.row(1).dot(P.row(1)) == 0) {
      //the second segment is reduced to a point
      if(s1_offset != NULL) {
        //by convention the p2 is nearest to [p0,p1]
        *s1_offset = 0 ;
      }
      //point_segment intersection
      return point_in_segment<Dim>(p2_coords, p0_coords, p1_coords, s0_offset) ;
    }

    //orthogonalize the direction wrt the direction of the first segment
    P.row(1) -= P.row(1).dot(P.row(0))*P.row(0) ;
    const Scalar P1_len = P.row(1).norm() ;
    if(P1_len != 0) {
      //if the segments are parallel, v is 0, otherwise it is normalized
      P.row(1) /= P1_len ;
    }

    //projection of one of each segment endpoints
    //Dim dimensional vectors here, although 2d in the end
    Vector2 pp0 = Vector2::Zero() ;
    Vector2 pp2 = P*(p2-p0) ;

    //check whether the segments are coplanar : same offsets wrt the plane
    const Vector p2_proj = p2 - P.transpose()*pp2 ;
    const bool segments_coplanar = p2_proj.dot(p2_proj) == 0 ;

    //early return if the segments are not coplanar, and no offset required
    if((s0_offset == NULL) && !segments_coplanar) return false ;

    //projections the remaining extremities
    Vector2 pp1 = P*(p1-p0) ;
    Vector2 pp3 = P*(p3-p0) ;

    //switch to 2D
    const bool intersect_2d = si_impl<2,Scalar>::do_it( pp0.data(),
                                                        pp1.data(),
                                                        pp2.data(),
                                                        pp3.data(),
                                                        s0_offset,
                                                        s1_offset
                                                      ) ;

    return intersect_2d && segments_coplanar ;
  }
} ;

template<typename Scalar>
class si_impl<2,Scalar> {
  public:
  //vector type
  typedef Eigen::Matrix<Scalar,2,1> Vector ;

  static bool do_it( const Scalar p0_coords[2],
                     const Scalar p1_coords[2],
                     const Scalar p2_coords[2],
                     const Scalar p3_coords[2],
                     Scalar* s0_offset, //output
                     Scalar* s1_offset  //output
                   ) {
    //segment extremities
    Eigen::Map<const Vector> p0(p0_coords) ;
    Eigen::Map<const Vector> p1(p1_coords) ;
    Eigen::Map<const Vector> p2(p2_coords) ;
    Eigen::Map<const Vector> p3(p3_coords) ;

    //segment vectors
    const Vector s0 = p1-p0 ;
    const Vector s1 = p3-p2 ;

    //orientation check
    Vector tested = p2-p0 ;
    const char o02 = orientation(s0.data(), tested.data()) ;
    tested = p3-p0 ;
    const char o03 = orientation(s0.data(), tested.data()) ;
    tested = p0-p2 ;
    const char o10 = orientation(s1.data(), tested.data()) ;
    tested = p1-p2 ;
    const char o11 = orientation(s1.data(), tested.data()) ;

    //basic intersection check, no enough if the segments are aligned
    const bool basic_intersect = (o02 != o03) && (o10 != o11) ;

    //no offset is required, return fastly if the intersection is sure
    if(basic_intersect && (s0_offset == NULL)) return true ;

    //segment normals in a matrix
    Eigen::Matrix<Scalar,2,2> A ;
    A << -s0[1], s0[0], -s1[1], s1[0] ;

    //check parallelism of the segments
    const Scalar det = A.determinant() ;

    if(det == 0) {
      //the segments are parallel or at least one is 0
      //length of [p0,p1]
      const Scalar s0_len = s0.norm() ;
      if(s0_len == 0) {
        //p0 and p1 are the same point
        if(s0_offset != NULL) {
          //by convention p0 is nearest to [p2,p3]
          *s0_offset = 0 ;
        }
        return point_in_segment<2>(p0_coords, p2_coords, p3_coords, s1_offset) ;
      }
      //from now on we know that p0 and p1 are different
      //project p2 and p3 on [p0,p1]
      const Scalar pp2 = p2.dot(s0)/s0_len ;
      const Scalar pp3 = p3.dot(s0)/s0_len ;
      const Scalar minp = pp2 < pp3 ? pp2 : pp3 ;
      const Scalar maxp = pp2 < pp3 ? pp3 : pp2 ;
      //cases
      if((minp <= 0) && (maxp >= 0)) {
        //p0 is a point reaching minimal distance to [p2,p3]
        if(s0_offset != NULL) {
          //assign it as nearest to [p2,p3] if asked
          *s0_offset = 0 ;
        }
        return point_in_segment<2>(p0_coords, p2_coords, p3_coords, s1_offset) ;
      }
      if((minp <= s0_len) && (maxp >= s0_len)) {
        //p1 is a point reaching minimal distance to [p2,p3]
        if(s0_offset != NULL) {
          //assign it as nearest to [p2,p3] if asked
          *s0_offset = 1 ;
        }
        return point_in_segment<2>(p1_coords, p2_coords, p3_coords, s1_offset) ;
      }
      if(minp > s0_len) {
        //no intersection
        //p1 is nearest to [p2,p3] and the nearest point is at minp
        if(s0_offset != NULL) {
          //assign it as nearest to [p2,p3] if asked
          *s0_offset = 1 ;
        }
        if(s1_offset != NULL)  {
          //assign the point projected at minp as nearest to [p0,p1]
          *s1_offset = minp == pp2 ? 0 : 1 ;
        }
        return false ;
      }
      if(maxp < 0) {
        //no intersection
        //p0 is nearest to [p2,p3] and the nearest point is at maxp
        if(s0_offset != NULL) {
          //assign it as nearest to [p2,p3] if asked
          *s0_offset = 0 ;
        }
        if(s1_offset != NULL)  {
          //assign the point projected at minp as nearest to [p0,p1]
          *s1_offset = maxp == pp2 ? 0 : 1 ;
        }
        return false ;
      }
      //from now on both p2 and p3 project inside [p0,p1]
      //by convention p2 is nearest to [p0,p1]
      if(s1_offset != NULL) {
        *s1_offset = 0 ;
      }
      return point_in_segment<2>(p2_coords, p0_coords, p1_coords, s0_offset) ;
    }
    //the segments are not parallel
    //if they intersect, the basic_intersect detected it
    if(s0_offset == NULL) return false ;
    //intersection between (p0,p1) and (p2,p3)
    Vector lhs ;
    lhs << A.row(0).dot(p0), A.row(1).dot(p2) ;
    const Vector I = A.inverse()*lhs ;
    //offsets of the intersection
    const Scalar s0_tmp_offset = s0.dot(I-p0) / s0.dot(s0) ; //no division by 0
    const Scalar s1_tmp_offset = s1.dot(I-p2) / s1.dot(s1) ; //no division by 0
    //if the segments basically intersect, return these offsets
    if(basic_intersect) {
      *s0_offset = s0_tmp_offset ;
      if(s1_offset != NULL) *s1_offset = s1_tmp_offset ;
      return true ;
    }
    //from now on the segments do not intersect
    if(o02 != o03) {
      //I lies in [p2,p3]
      //I does not lie in [p0,p1] otherwise basic_intersect
      //the extremity of [p0,p1] nearest to I reaches minimal distance
      const Scalar* s0_nearest = s0_tmp_offset > 0.5 ? p1_coords : p0_coords ;
      *s0_offset = s0_nearest == p1_coords ? 1 : 0 ;
      if(s1_offset != NULL) {
        point_in_segment<2>(s0_nearest, p2_coords, p3_coords, s1_offset) ;
      }
      return false ;
    }
    //from now on I lies outside [p2,p3]
    //get the extremity of [p2,p3] nearest to I
    const Scalar* s1_nearest = s1_tmp_offset > 0.5 ? p3_coords : p2_coords ;
    //point in [p0,p1] nearest to that point
    point_in_segment<2>(s1_nearest, p0_coords, p1_coords, s0_offset) ;
    if((*s0_offset >=0) && (*s0_offset <= 1)) {
      //s1_nearest reaches minimal distance
      if(s1_offset != NULL) {
        *s1_offset = s1_nearest == p3_coords ? 1 : 0 ;
      }
      return false ;
    }
    //s1_nearest may not reach minimal distance
    //the extremity of [p0,p1] nearest to I reaches minimal distance anyway
    *s0_offset = s0_tmp_offset > 0.5 ? 1 : 0 ;
    if(s1_offset != NULL) {
      //get that extremity
      const Scalar* s0_nearest = s0_offset == 0 ? p0_coords : p1_coords ;
      point_in_segment<2>(s0_nearest, p2_coords, p3_coords, s1_offset) ;
    }
    return false ;
  }
} ;

} //end of namespace segment_intersection_impl

template<int Dim, typename Scalar>
bool segment_intersection( const Scalar p0_coords[2],
                           const Scalar p1_coords[2],
                           const Scalar p2_coords[2],
                           const Scalar p3_coords[2],
                           Scalar* s0_offset, //output
                           Scalar* s1_offset  //output
                         ) {
  using namespace segment_intersection_impl ;
  return si_impl<Dim,Scalar>::do_it( p0_coords,
                                     p1_coords,
                                     p2_coords,
                                     p3_coords,
                                     s0_offset,
                                     s1_offset
                                   ) ;
}


/* Checks whether a point is strictly in a sphere.
 * The *squared* radius is required */
template<int Dim, typename Scalar>
bool point_in_sphere( const Scalar point[Dim],
                      const Scalar center[Dim],
                      Scalar radius
                    ) {
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  Eigen::Map<const Vector> p(point) ;
  Eigen::Map<const Vector> c(center) ;
  Vector edge = p-c ;

  //distance check
  return edge.dot(edge) < radius*radius ;
}

/* Intersection between the interior of a segment and a sphere.
 * Returns the number of intersections.
 * The *squared* radius is required.
 * The provided output array receives the intersections p
 * as the values of u such that p = p1 + u(p2-p1) */
template<int Dim, typename Scalar>
unsigned char segment_sphere_intersections( const Scalar p0_coords[Dim],
                                            const Scalar p1_coords[Dim],
                                            const Scalar center[Dim],
                                            Scalar radius,
                                            Scalar intersections[2] //output
                                          ) {
  //vector type
  typedef Eigen::Matrix<Scalar,Dim,1> Vector ;

  Eigen::Map<const Vector> p0(p0_coords) ;
  Eigen::Map<const Vector> p1(p1_coords) ;
  Eigen::Map<const Vector> c(center) ;

  //edge vector and its squared length
  const Vector edge = p1-p0 ;
  const Scalar sq_elen = edge.dot(edge) ;
  //center vector and its squared length
  const Vector cv = p0-c ;
  const Scalar sq_cvlen = cv.dot(cv) ;
  //dot product between the two
  const Scalar edgedotcv = edge.dot(cv) ;

  //discriminant
  const Scalar disc = edgedotcv*edgedotcv - sq_elen*(sq_cvlen - radius*radius) ;

  //no intersection case
  if(disc < 0) return 0 ;

  //intersections, compute their positions
  const Scalar dist_rt = sqrt(disc) ;
  const Scalar u0 = (-edgedotcv - dist_rt)/sq_elen ;
  const Scalar u1 = (-edgedotcv + dist_rt)/sq_elen ;

  //check these positions are in the interior of the segment
  //and count the number of valid intersections
  unsigned char number_of_intersections = 0 ;
  if((u0 > 0) && (u0 < 1)) {
    intersections[0] = u0 ;
    ++number_of_intersections ;
  }
  if((u1 > 0) && (u1 < 1)) {
    intersections[number_of_intersections] = u1 ;
    ++number_of_intersections ;
  }

  //return the number of intersections
  return number_of_intersections ;
}

/* Check whether a point lies in a triangle.
 * If the bar_coords pointer is provided, it is filled with two scalars a and b
 * such that the point a.x0 + b.x1 + (1-a-b).x2 is the point in the triangle
 * x0,x1,x2 nearest to p. */

namespace point_in_triangle_impl {

//classes for partial template specialization, unavailable for functions
template<int Dim, typename Scalar>
class pit_impl {
  public:
  static bool do_it( const Scalar p_coords[Dim],
                     const Scalar x0_coords[Dim],
                     const Scalar x1_coords[Dim],
                     const Scalar x2_coords[Dim],
                     Scalar bar_coords[2] = NULL
                   ) {
    //vector type
    typedef Eigen::Matrix<Scalar,Dim,1> Vector ;
    //2d vector type
    typedef Eigen::Matrix<Scalar,2,1> Vector2 ;

    Eigen::Map<const Vector> p(p_coords) ;
    Eigen::Map<const Vector> x0(x0_coords) ;
    Eigen::Map<const Vector> x1(x1_coords) ;
    Eigen::Map<const Vector> x2(x2_coords) ;

    //projection matrix
    Eigen::Matrix<Scalar,2,Dim,Eigen::RowMajor> P ;
    //base of the triangle
    P.row(0) = x1-x0 ;
    const Scalar base_len = P.row(0).norm() ;
    if(base_len == 0) {
      //x0 and x1 are identical
      if(bar_coords != NULL) {
        //by convention the nearest point is on segment [x0,x2]
        bar_coords[1] = 0 ;
      }
      return point_in_segment<Dim>(p_coords,x2_coords,x0_coords,bar_coords) ;
    }
    P.row(0) /= base_len ;

    //height of the triangle
    P.row(1) = x2-x0 ;
    P.row(1) -= P.row(1).dot(P.row(0))*P.row(0) ;
    const Scalar height_len = P.row(1).norm() ;
    if(height_len == 0) {
      //get the vector used for the height
      const Vector h = x2-x2 ;
      //compute the dot product with the base (theoretically 1 or -1)
      const Scalar bdoth = h.dot(P.row(0)) ;
      if(bdoth < 0) {
        //x0 lies on [x1,x2]
        if(bar_coords != NULL) {
          //by convention the nearest point is on segment [x1,x2]
          bar_coords[0] = 0 ;
          return point_in_segment<Dim>( p_coords,
                                        x2_coords,
                                        x1_coords,
                                        bar_coords+1
                                      ) ;
        }
        return point_in_segment<Dim>(p_coords,x2_coords,x1_coords) ;
      } else {
        if(h.dot(h) < base_len*base_len) {
          //x2 lies on [x0,x1]
          if(bar_coords != NULL) {
            //by convention the nearest point is on segment [x0,x1]
            bool intersect = point_in_segment<Dim>( p_coords,
                                                    x0_coords,
                                                    x1_coords,
                                                    bar_coords+1
                                                  ) ;
            bar_coords[0] = 1-bar_coords[1] ;
            return intersect ;
          }
          return point_in_segment<Dim>(p_coords,x0_coords,x1_coords) ;
        } else {
          //x1 lies on [x0,x2]
          if(bar_coords != NULL) {
            //by convention the nearest point is on segment [x0,x2]
            bar_coords[1] = 0 ;
          }
          return point_in_segment<Dim>( p_coords,
                                        x2_coords,
                                        x0_coords,
                                        bar_coords
                                      ) ;
        }
      }
    }
    P.row(1) /= height_len ;

    //project everything
    Vector2 pp, x0p, x1p, x2p ;
    pp = P*(p-x0) ;
    x0p = Vector2::Zero() ;
    x1p = P*(x1-x0) ;
    x2p = P*(x2-x0) ;

    //coplanarity test
    const Vector p_proj = p - P.transpose()*pp ;
    bool coplanar = p_proj.dot(p_proj) == 0 ;
    if((bar_coords == NULL) && (!coplanar)) return false ;

    //switch to 2D
    bool intersect =  pit_impl<2,Scalar>::do_it( pp.data(),
                                                 x0p.data(),
                                                 x1p.data(),
                                                 x2p.data(),
                                                 bar_coords
                                               ) ;

    return (coplanar && intersect) ;
  }
} ;

template<typename Scalar>
class pit_impl<2,Scalar> {
  public:
  static bool do_it( const Scalar p_coords[2],
                     const Scalar x0_coords[2],
                     const Scalar x1_coords[2],
                     const Scalar x2_coords[2],
                     Scalar bar_coords[2] = NULL
                   ) {
    //Vector type
    typedef Eigen::Matrix<Scalar,2,1> Vector ;

    //Query point
    Eigen::Map<const Vector> p(p_coords) ;

    //Triangle vertices
    const Scalar* x[3] ;
    x[0] = x0_coords ;
    x[1] = x1_coords ;
    x[2] = x2_coords ;

    //matrix for sides and point vectors
    Eigen::Matrix<Scalar,4,3, Eigen::ColMajor> m ;

    for(int i=0; i<3; ++i) {
      Eigen::Map<const Vector> x1(x[(i+1)%3]) ;
      Eigen::Map<const Vector> x2(x[(i+2)%3]) ;
      m.template block<2,1>(0,i) = x2-x1 ;
      m.template block<2,1>(2,i) = p -x1 ;
    }

    //twice the triangle area
    const Scalar twoarea = m.template topLeftCorner<2,2>().determinant() ;

    //barycentric coordinates wrt x0, x1 and x2
    Scalar b[3] ;
    for(int i = 0; i<3; ++i) {
      Eigen::Map< Eigen::Matrix<Scalar,2,2> > mini(m.col(i).data()) ;
      b[i] = mini.determinant()/twoarea ;
    }

    for(int i = 0; i<3; ++i) {
      if(b[i] < 0) {
        //p is on the wrong side of [x{[i+1)%3],x[(i+2)%3]]
        if(b[(i+1)%3] < 0) {
          //p is also on the wrong side of [x[(i+2)%3],x[i]]
          //x[(i+2)%3] is the vertex in common
          if( m.template block<2,1>(0,i).dot(
              m.template block<2,1>(2,(i+1)%3))*twoarea
              > 0
            ) {
            //the nearest side is [x[(i+2)%3],x[i]]
            bool intersect = point_in_segment<2>( p_coords,
                                                  x[(i+2)%3],
                                                  x[i],
                                                  bar_coords
                                                ) ;
            if(bar_coords != NULL) {
              b[i] = bar_coords[0] ;
              b[(i+1)%3] = 0 ;
              b[(i+2)%3] = 1-bar_coords[0] ;
              bar_coords[0] = b[0] ;
              bar_coords[1] = b[1] ;
            }
            return intersect ;
          }
        }
        if(b[(i+2)%3] < 0) {
          //p is also on the wrong side of [x[i],x[(i+1)%3]]
          //x[(i+1)%3] is the vertex in common
          if( m.template block<2,1>(0,i).dot(
              m.template block<2,1>(2,(i+2)%3))*twoarea
              < 0
            ) {
            //the nearest side is [x[i],x[(i+1)%3]]
            bool intersect = point_in_segment<2>( p_coords,
                                                  x[(i+1)%3],
                                                  x[i],
                                                  bar_coords
                                                ) ;
            if(bar_coords != NULL) {
              b[i] = bar_coords[0] ;
              b[(i+1)%3] = 1-bar_coords[0] ;
              b[(i+2)%3] = 0 ;
              bar_coords[0] = b[0] ;
              bar_coords[1] = b[1] ;
            }
            return intersect ;
          }
        }
        //no return, the nearest point is on [x[(i+1)%3],x[(i+2)%3]]
        bool intersect = point_in_segment<2>( p_coords,
                                              x[(i+1)%3],
                                              x[(i+2)%3],
                                              bar_coords
                                            ) ;
        if(bar_coords != NULL) {
          b[i] = 0 ;
          b[(i+1)%3] = 1-bar_coords[0] ;
          b[(i+2)%3] = bar_coords[0] ;
          bar_coords[0] = b[0] ;
          bar_coords[1] = b[1] ;
        }
        return intersect ;
      }
    }
    //no return, p is in the triangle

    if(bar_coords != NULL) {
      bar_coords[0] = b[0] ;
      bar_coords[1] = b[1] ;
    }
    return true ;
  }
} ;
}//end of namespace point_in_triangle_impl

template<int Dim, typename Scalar>
bool point_in_triangle( const Scalar p_coords[Dim],
                        const Scalar x0_coords[Dim],
                        const Scalar x1_coords[Dim],
                        const Scalar x2_coords[Dim],
                        Scalar bar_coords[2]
                      ) {
  using namespace point_in_triangle_impl ;
  return pit_impl<Dim,Scalar>::do_it( p_coords,
                                      x0_coords,
                                      x1_coords,
                                      x2_coords,
                                      bar_coords
                                    ) ;
}

} //end of namespace Revoropt

#endif
