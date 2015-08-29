#ifndef _REVOROPT_TOOLS_INTERSECTIONS_FWD_HPP_
#define _REVOROPT_TOOLS_INTERSECTIONS_FWD_HPP_

namespace Revoropt {

/* 2d orientation check */
template<typename Scalar>
char orientation( const Scalar v0[2], const Scalar v1[2] ) ;

/* Checks whether a point is in a segment (including endpoints)
 * If the offset pointer is provided, it is filled with the value of a 
 * such that p = p0 + a*(p1-p0). If the p is not in the segment, the point
 * q = p0 + a*(p1-p0) is the point of the segment nearest to p. */
template<int Dim, typename Scalar>
bool point_in_segment( const Scalar p_coords[Dim],
                       const Scalar p0_coords[Dim],
                       const Scalar p1_coords[Dim],
                       Scalar* offset = NULL //output
                     ) ;

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
template<int Dim, typename Scalar>
bool segment_intersection( const Scalar p0_coords[2],
                           const Scalar p1_coords[2],
                           const Scalar p2_coords[2],
                           const Scalar p3_coords[2],
                           Scalar* s0_offset = NULL, //output
                           Scalar* s1_offset = NULL  //output
                         ) ;


/* Checks whether a point is strictly in a sphere. 
 * The *squared* radius is required */
template<int Dim, typename Scalar>
bool point_in_sphere( const Scalar point[Dim], 
                      const Scalar center[Dim], 
                      Scalar radius 
                    ) ;

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
                                          ) ;

/* Check whether a point lies in a triangle.
 * If the bar_coords pointer is provided, it is filled with two scalars a and b
 * such that the point a.x0 + b.x1 + (1-a-b).x2 is the point in the triangle
 * x0,x1,x2 nearest to p. */
template<int Dim, typename Scalar>
bool point_in_triangle( const Scalar p_coords[Dim],
                        const Scalar x0_coords[Dim],
                        const Scalar x1_coords[Dim],
                        const Scalar x2_coords[Dim],
                        Scalar bar_coords[2] = NULL
                      ) ;

} //end of namespace Revoropt

#endif
