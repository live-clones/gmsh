#ifndef HXT_POINT_GEN_OPTIONS_H
#define HXT_POINT_GEN_OPTIONS_H

#include <stdint.h>

/**
* \file hxt_point_gen_options.h Point generation.
* \author Christos Georgiadis 
*/

/**
 * \struct HXTPointGenOptions
 * 
 * Options for point generation 
 *
 */
typedef struct {

  int verbosity;              /**<
                               *  - if verbosity<=0: don't print information.
                               *  - if verbosity==1: print basic information on each pass
                               *  - if verbosity>=2: print everything */

  int generateLines;          /**< Generate points on mesh lines, 0 to get from input mesh */
  int generateSurfaces;       /**< Generate points on mesh surfaces, 0 to get from input mesh */
  int generateVolumes;        /**< Generate points on mesh volumes */
  int remeshSurfaces;         /**< Remesh surface with local mesh modifications */

  int walkMethod2D;           /**<
                               *  - if 0: simple 
                               *  - if 1: Runge-Kutta 4
                               *  - if 2: planar simple
                               *  - if 3: planar Runge-Kutta 4*/

  int walkMethod3D;           /**<
                               *  - if 0: simple 
                               *  - if 1: Runge-Kutta 4*/


  int dirType;                /**< 0 for hard-coded axis oriented 1 to compute for 3D */

  double uniformSize;         /**< Background mesh size  */

  double areaThreshold;       /**< Minimum triangle area */

  double tolerance;           /**< Tolerance for remeshing */

  uint64_t numTris;           /**< Desired number of triangles */

  uint16_t skipColor;         /**< Skip this color in pointGen (used in mixed quad-tri input) */


}HXTPointGenOptions;

#endif
