// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include "hblTypes.hpp"
#include <string>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <fstream>

namespace hbl {

  const size_t NBMAX = 30;

  using bdrsign_t = std::array<unsigned char,NBMAX>;
  struct bdrsign_t_hash {
    size_t operator()(bdrsign_t p) const noexcept {
      uint32_t hash = 0;
      for (size_t i = 0; i < p.size(); ++i) {
        hash += p[i];
        hash += hash << 10;
        hash ^= hash >> 6;
      }
      hash += hash << 3;
      hash ^= hash >> 11;
      hash += hash << 15;
      return hash;
    }
  };

  struct DTriangulation {
    id nb = 0;
    id nv = 0;
    std::vector<id3> triangles; /* vertex ids */
    std::vector<bool> vOnBdr;
    std::vector<id> vValence;
    std::vector<id2> edges;
    std::vector<bool> eOnBdr;

    bool fill_struct_from_triangles();
    bool load_triangulation(const std::vector<id>& tri_vertices);
    bool transform_to_canonical_boundary_loop();
  };

  bool compute_triangulation_boundary_valence_loop(
      const std::vector<id2>& bdrEdges,
      const std::vector<id>& vValence,
      std::vector<id>& bdr_val_loop);

  bool get_smallest_rotation(const std::vector<id>& bdrVal, const std::vector<id>& bdrLoop, 
      std::vector<id>& smallestBdrVal, std::vector<id>& smallestBdrLoop);

  bdrsign_t signature_from_boundary(const std::vector<id>& bdr_val_loop);

  struct DiskTriangulations {
    std::vector<std::unique_ptr<DTriangulation> > trgls;
    std::vector<std::unordered_map<bdrsign_t,std::vector<DTriangulation*>,bdrsign_t_hash> > nbv_sign_to_trgl;
    bool write(const std::string& path);
    bool read(const std::string& path);
  };

  bool load_disk_triangulations(DiskTriangulations& trgls);

  bool show_legal_configurations(const DiskTriangulations& dts, id nbv);

}
