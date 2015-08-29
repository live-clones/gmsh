#ifndef _REVOROPT_TOOLS_MEASURE_FWD_HPP_
#define _REVOROPT_TOOLS_MEASURE_FWD_HPP_

namespace Revoropt {

/*{{{ Triangle height and area */

/* Height of a triangle, passing through the first vertex provided */
template<int Dim, typename Scalar>
Scalar triangle_height( const Scalar x0_p[Dim],
                        const Scalar x1_p[Dim],
                        const Scalar x2_p[Dim]
                      ) ;


/* Area of a triangle */
template<int Dim, typename Scalar>
Scalar triangle_area( const Scalar x0_p[Dim],
                      const Scalar x1_p[Dim],
                      const Scalar x2_p[Dim]
                    ) ;

//}}}

/*{{{ Barycentric coordinates of a point whithin a triangle */

template<int Dim, typename Scalar>
Scalar triangle_barycentric_coords( const Scalar x0_p[Dim],
                                    const Scalar x1_p[Dim],
                                    const Scalar x2_p[Dim],
                                    const Scalar p[Dim],
                                    Scalar coords[Dim] //output
                                  ) ;

//}}}

/*{{{ Find a projection plane for points based on SVD */

template< typename Scalar, int Dim >
void svd_plane( 
    const Scalar* coords, 
    unsigned int size , 
    Scalar paramU[Dim], //output
    Scalar paramV[Dim] //output
    ) ;

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
                       ) ;

/* Area of a circular segment. The parameters are the same as above. */
template<typename Scalar>
Scalar circle_segment_area( const Scalar radius,
                            const Scalar chord_len
                          ) ;

/* Triangle sphere intersection area */
template<int Dim, typename Scalar>
Scalar triangle_sphere_intersection_area( const Scalar x0_coords[Dim],
                                          const Scalar x1_coords[Dim],
                                          const Scalar x2_coords[Dim],
                                          const Scalar c_coords[Dim],
                                          Scalar radius
                                        ) ;

//}}}

/*{{{ Angles */

template<int Dim, typename Scalar>
Scalar angle_cos( const Scalar p0[Dim], const Scalar p1[Dim], const Scalar p2[Dim]) ;

//}}}

} //end of namespace Revoropt

#endif
