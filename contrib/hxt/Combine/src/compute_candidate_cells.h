#ifndef HXT_COMBINE_COMPUTE_CANDIDATE_CELLS
#define HXT_COMBINE_COMPUTE_CANDIDATE_CELLS

#include "basic_types.h"
#include "combine_quality.h"
#include "tet_mesh.h"
#include "hxt_quality.h"

/**
* \file compute_candidate_cell.h THE algorithms to identify hexes, prisms and pyramids
*  in a tetrahedral mesh
*
* \author Jeanne Pellerin
*/

namespace HXTCombine{

  using HXTCombine::vec3;

/**
* \addtogroup Combine
* @{
*/
  
/**
* Resizes the sorted (decreasing order) vector \param input such
* that all values are strictly above \param minValue.
*/
inline double cellQuality(const TetMeshWrapper& tets, const vector<VertexIndex>& vertices)
{
  vector<vec3> points(vertices.size());
  for (unsigned int i = 0; i < vertices.size(); ++i) {
    points[i] = tets.point(vertices[i]);
  }
  if      (vertices.size() == 8) return cellApproximateQuality<Hex>(points.data());
  else if (vertices.size() == 6) return cellApproximateQuality<Prism>(points.data());
  else if (vertices.size() == 5) return cellApproximateQuality<Pyramid>(points.data()); 
  else return -1.;
}

inline bool isCellReallyValid(const TetMeshWrapper& tets, const vector<VertexIndex>& vertices)
{
  vector<vec3> points(vertices.size());
  for (unsigned int i = 0; i < vertices.size(); ++i) {
    points[i] = tets.point(vertices[i]);
  }
  // Dirty casting to the vec3 class that is used in the hext_quality.cpp file
  // till a better solution is available
  if      (vertices.size() == 8) return hexExactValidity((::point3d*) points.data());
  else if (vertices.size() == 6) return prismValidity((::point3d*)points.data());
  else if (vertices.size() == 5) return pyramidValidityNotImplemented((::point3d*)points.data());
  else return false;
}

/**
* @}
*/

}

#endif
