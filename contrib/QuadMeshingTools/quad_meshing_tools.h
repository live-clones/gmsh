// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <string>
#include <vector>
#include <map>

#include "qmt_types.hpp"
#include "qmt_projection.h"

/* QuadMeshingTools module
 * See contrib/QuadMeshingTools/README.md for a more detailed description */

namespace QMT {

  /**
   * @brief Generate a quadrilateral mesh (type QMesh) from a colored triangulation. Each
   *        color (surface entity) must be a patch with four boundaries (curve entity).
   *
   * @warning this function calls the gmsh API
   * @param[in] modelName Name of the model in gmsh
   * @param[in] H_tag Index of the view that contains H (computed from cross field, used for conformal sizemap)
   * @param[in] size_min Minimum edge size in the output
   * @param[in] size_max Maximal edge size in the ouput (only used if size_min = 0.)
   * @param[in] initialGeometryName Name of the geometric model on which to project
   * @param[in] projector From projection on initial geometry, ignored if NULL
   * @param[in,out] entityToInitialEntity Entity mapping, from current entity to initial geometry. Can be completed if missing info.
   * @param[out] M Generated quad mesh
   * @return True if the generation succeed
   */
  bool generate_quad_mesh_from_gmsh_colored_triangulation(
      const std::string& modelName,
      int H_tag,
      double size_min,
      double size_max,
      QMesh& M,
      const BoundaryProjector* projector = NULL,
      const std::map<std::pair<int,int>,std::pair<int,int>>* entityToInitialEntity = NULL);

  /**
   * @brief Generate a new model (named meshName) in gmsh, which contains the quadrilateral mesh M
   *
   * @warning this function calls the gmsh API
   * @param[in] M Input quadrilateral mesh
   * @param[in] meshName name of the model to create (new model entity in gmsh)
   * @return True if the export succeed
   */
  bool export_qmesh_to_gmsh_mesh(const QMesh& M, const std::string& meshName);

  /**
   * @brief Simplify the quad mesh structure by iteratively collapsing chords.
   *
   * @param[in,out] M Mesh to simplify
   * @param[in] size_collapse Chords whose width is inferior to size_collapse will be removed
   * @param[in] nb_collapse_max Limit the number of collapses, no limit if -1
   * @param[in] projector From projection on initial geometry, ignored if NULL
   * @return True if the simplification succeed
   */
  bool simplify_quad_mesh(
      QMesh& M, 
      double size_collapse, 
      int nb_collapse_max = -1,
      const BoundaryProjector* projector = NULL);

  /**
   * @brief Smooth the vertex positions of a quad mesh, using Winslow smoothing.
   *
   * @param[in,out] M Quadrilateral mesh to smooth
   * @param[in] iter_max Number of explicit iterations (loop over all vertices)
   * @param[in] projector From projection on initial geometry, ignored if NULL
   * @warning current implementation will shrink the geometry
   * @return True if the smoothing succeed
   */
  bool smooth_quad_mesh(
      QMesh& M, 
      size_t iter_max = 10,
      const BoundaryProjector* projector = NULL);

  /**
   * @brief Compute a cross field (one cross per edge) with the successive heat diffusion 
   * and projection. See the README.md for more details. Very fast if MUMPS is enabled.
   *
   * @param[in] meshName Name of the gmsh model that contains the triangulation used for the computation
   * @param[out] crossFieldTag Index of the view that will contains the generated cross field
   * @param[in] nbSteps Number of timesteps in the scheme. One timestep corresponds to a given diffusion length.
   *                    Should be sufficient (>= 3) but not too much (<10) for fast computation. 
   *                    nbSteps = 4 is a good trade-off.
   * @param[in,out] edge_to_angle If not NULL, the function will fill the map with the cross angle (relative to the edge vector)
   *                              for each edge [v1,v2] (with v1 < v2) of the triangulation.
   * @warning this function calls the gmsh API
   * @return True if the computation succeed
   */
  bool compute_cross_field_with_heat(
      const std::string& meshName,
      int& crossFieldTag,
      int nbSteps = 4,
      std::map<std::pair<size_t,size_t>,double>* edge_to_angle = NULL);


  /**
   * @brief Fill the triangular mesh M from the gmsh mesh in the model meshName
   *
   * @warning this function calls the gmsh API
   * @param[in] meshName name of the model containing the mesh in gmsh, ignored if equals to "current"
   * @param[out] M Output mesh containing lines and triangles
   * @return True if the import succeed
   */
  bool import_TMesh_from_gmsh(const std::string& meshName, TMesh& M);





  /****************************************************************************************/
  /******************************* prototypes, not ready **********************************/
  /****************************************************************************************/

  bool generate_quad_mesh_via_tmesh_quantization(
      const std::string& modelName,
      int sizemapTag,
      double size_min,
      double size_max,
      QMesh& M,
      const BoundaryProjector* projector,
      const std::map<std::pair<int,int>,std::pair<int,int>>* entityToInitialEntity);



  bool create_scaled_cross_field_view(const std::string& meshName, int tagCrossField, int tagH, bool viewIsModelData, const std::string& viewName, int& viewTag);

  bool detect_cross_field_singularities(int crossFieldTag, std::vector<std::pair<size_t,int>>& sings, bool create_view = true);
}


