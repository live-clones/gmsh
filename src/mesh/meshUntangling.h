// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Maxence Reberol

#pragma once

#include <array>
#include <cstdint>
#include <vector>

class GFace;
class GRegion;

// Untangle the triangles and quadrangles of a face with the Winslow untangler.
// The face is covered by patches that are nearly planar; each patch is
// untangled in its mean plane, with its boundary fixed, and the moved vertices
// are projected back on the face. Vertices on curves are fixed.
bool untangleGFaceMeshConstrained(GFace *gf);

// Build the input of WinslowUntangler::untangle2D from triangles and quads
// (triangles have elements[i][3] == (uint32_t)-1): each triangle is kept with
// an equilateral target, each quad gives four overlapping corner triangles with
// right-angled targets.
bool buildTrianglesAndTargetsFromElements(
  const std::vector<std::array<uint32_t, 4>> &elements,
  std::vector<std::array<uint32_t, 3>> &triangles,
  std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes);

// Untangle the linear tetrahedra, hexahedra and pyramids of a region with the
// Winslow untangler; hexahedra and pyramids are split into overlapping
// tetrahedra. Vertices on surfaces, curves and points are fixed. iterMax is the
// number of outer iterations, timeMax the CPU time budget in seconds.
bool untangleGRegionMeshConstrained(GRegion *gr, int iterMax = 10,
                                    double timeMax = 9999.);
