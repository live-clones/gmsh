#ifndef _REVOROPT_MESH_MEASURE_FWD_HPP_
#define _REVOROPT_MESH_MEASURE_FWD_HPP_

#include <cstddef>

namespace Revoropt {

/*{{{ Area */

/* Area of a face of a mesh */
template<typename Mesh>
typename Mesh::Scalar mesh_face_area(const Mesh* mesh, unsigned int face) ;

/* Area of a mesh */
template<typename Mesh>
typename Mesh::Scalar mesh_area(const Mesh* mesh) ;

//}}}

/*{{{ Edge length */

template< typename Mesh >
typename Mesh::Scalar edge_length_from_vertices( const Mesh* mesh, 
                                                 unsigned int v0, 
                                                 unsigned int v1 
                                               ) ;

template< typename Mesh >
typename Mesh::Scalar edge_length_from_face_index( const Mesh* mesh, 
                                                   unsigned int face, 
                                                   unsigned int edge 
                                                 ) ;

/* Longest edge of a face */

template< typename Mesh >
unsigned int face_longest_edge( const Mesh* mesh,
                                unsigned int face,
                                typename Mesh::Scalar* output_length = NULL
                              ) ;

/* Longest edge of a mesh */
template< typename Mesh >
void mesh_longest_edge_vertices( const Mesh* mesh,
                                 unsigned int* v0,
                                 unsigned int* v1,
                                 typename Mesh::Scalar* output_length = NULL
                               ) ;

//}}}

/*{{{ Angles */

template<typename Mesh>
typename Mesh::Scalar face_angle_cos( const Mesh* mesh, 
                                      unsigned int face, 
                                      unsigned int vertex 
                                    ) ;

//}}}

/*{{{ Normalization */

template<typename Mesh>
void normalize_mesh( Mesh* mesh, double* out_center = NULL, double* out_scale = NULL ) ;

//}}}

/**{{{ Distance to a mesh **/

template<typename Mesh>
void mesh_distances( const Mesh* mesh,
                     typename Mesh::Scalar* queries,
                     unsigned int queries_size,
                     typename Mesh::Scalar radius,
                     typename Mesh::Scalar* output
                   ) ;

//}}}

/**{{{ Gradient of the mesh area wrt. its vertices **/

template<typename Triangulation>
void mesh_area_gradient( 
    const Triangulation* mesh, 
    double* output,
    double factor = 1
    ) ;

//}}}

} //end of namespace Revoropt

#endif
