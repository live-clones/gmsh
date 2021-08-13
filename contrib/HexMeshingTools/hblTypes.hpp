// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <cstdint>
#include <array>

#include "arrayGeometry.h"
#include "cppUtils.h"

namespace hbl {
  /* Basic types */
  using id   = uint32_t;
  using sid  = int64_t;
  using id2  = std::array<id, 2>;
  using id3  = std::array<id, 3>;
  using id4  = std::array<id, 4>;
  using id6  = std::array<id, 6>;
  using id8  = std::array<id, 8>;
  using sid2 = std::array<sid, 2>;
  using sid3 = std::array<sid, 3>;
  using sid4 = std::array<sid, 4>;

  constexpr hbl::id   NO_ID  = (hbl::id) -1;
  constexpr hbl::sid  NO_SID = (hbl::sid) NO_ID;
  constexpr uint8_t   NO_U8 = (uint8_t) -1;

  constexpr ArrayGeometry::vec3 NO_VEC3 = {DBL_MAX,DBL_MAX,DBL_MAX};

  struct SimpleMesh {
    std::vector<ArrayGeometry::vec3> points;
    std::vector<id> origin;
    std::vector<id3> triangles;
    std::vector<id4> tets;
    std::vector<id8> hexahedra;
  };
}
