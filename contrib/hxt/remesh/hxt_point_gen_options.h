#ifndef HXT_POINT_GEN_OPTIONS_H
#define HXT_POINT_GEN_OPTIONS_H

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

  int generateLines;          /**< Generate points on mesh lines */
  int generateSurfaces;       /**< Generate points on mesh surfaces */
  int generateVolumes;        /**< Generate points on mesh volumes */
  int remeshSurfaces;         /**< Remesh surface with local mesh modifications */

  int dirType;                /**< 0 for hard-coded axis oriented 1 to compute for 3D */

  double areaThreshold;       

  double uniformSize; 


}HXTPointGenOptions;

#endif
