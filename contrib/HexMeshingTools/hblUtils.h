// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <string>

#include "hblTypes.hpp"

class BrepMesh;

namespace hbl {
  bool getOrderedVerticesFromEdges(id vStart, const std::vector<id2>& edge_pairs, std::vector<id>& orderedVertices);
  bool getOrderedVerticesFromEdges(const std::vector<id2>& edge_pairs, std::vector<id>& orderedVertices);
  id3 get_smallest_rotation(const id3& vec);
  id4 get_smallest_rotation(const id4& vec);
  bool system_reduction_using_graph(id n, const std::vector<id2>& equality_constraints, std::vector<id>& old2new, id& nbIndep);
  bool system_reduction_using_graph(id n, const std::vector<id2>& equality_constraints, const std::vector<bool>& toDel, std::vector<id>& old2new, id& nbIndep);
  bool extract_dual_polygon(const BrepMesh& Q, id v, std::vector<id>& adjacentEdgesOrdered);
  void visualization_show_cells(const BrepMesh& M, const std::vector<id>& cells, const std::string& viewName);
  void visualization_show_faces(const BrepMesh& M, const std::vector<id>& faces, const std::string& viewName);
  void vector_statistics(const std::vector<double>& values, double& vMin, double& vMax, double& vAvg);

}
