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

namespace QMT {

  /* return squared distance */
  double project_point_segment_l2(const vec3& query, const vec3& a, const vec3& b, vec3& proj, double& lambda);
  double project_point_triangle_l2(const vec3& query, const vec3& V0, const vec3& V1, const vec3& V2, vec3& proj, double lambda[3]);


  class BoundaryProjector {
    public:
      BoundaryProjector(const TMesh& mesh);
      ~BoundaryProjector();
      bool projectionOnEntityAvailable(int dim, int tag) const;
      bool project(int dim, int tag, vec3 query, vec3& projection) const;
      bool project(int dim, int tag, vec3 query, vec3& projection, id& cache) const;
      bool closestEntity(const std::vector<vec3>& queries, double& dist, int& dim, int& tag) const;
      bool closestEntity(const vec3& query, double& dist, int& dim, int& tag) const;
      void show_projector(const std::string& viewPrefix = "bp") const;

    protected:
      const TMesh M; /* deep copy */

      std::vector<vec3> nodes;
      size_t N_search = 5;

      std::vector<void*> curve_tree;
      std::vector<std::vector<std::vector<id>>> cTreeIdToEdges;

      std::vector<void*> surface_tree;
      std::vector<std::vector<std::vector<id>>> sTreeIdToTris;

      std::vector<void*> pcs;
      std::vector<void*> pcas;
  };

  bool assignClosestEntities(QMesh& M, const BoundaryProjector& projector);

}
