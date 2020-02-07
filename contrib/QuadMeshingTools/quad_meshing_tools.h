// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include "qmt_types.hpp"
#include <string>
#include <vector>
#include <map>

/* QuadMeshingTools */
namespace QMT {


  /* warning: will call the gmsh API */
  bool generate_quad_mesh_from_gmsh_colored_triangulation(
      const std::string& modelName,
      int H_tag,
      double size_min,
      double size_max,
      QMesh& M);

  /* warning: will call the gmsh API */
  bool export_qmesh_to_gmsh_mesh(const QMesh& M, const std::string& meshName);

  bool simplify_quad_mesh(QMesh& M, double size_collapse, int nb_collapse_max = -1);

  bool smooth_quad_mesh(QMesh& M, size_t iter_max = 10);

  bool compute_cross_field_with_heat(
      const std::string& meshName,
      int& crossFieldTag,
      int nbIter = 5,
      std::map<std::pair<size_t,size_t>,double>* edge_to_angle = NULL);

}


