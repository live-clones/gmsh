// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol
//
// This module re-implements the constrained 2d/3d untangler described in the
// paper:
//
//      Foldover-free maps in 50 lines of code.
//      Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
//      Sokolov, D. (2021). arXiv preprint arXiv:2102.03069.
//      reference implementation: https://github.com/ssloy/invertible-maps

#include "winslowUntangler.h"

#include <math.h>
#include <iostream> // debugging
#include <cfloat>

#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"

#if defined(HAVE_EIGEN)
#include <Eigen/Core>
#include <Eigen/Dense>
#endif

#if defined(HAVE_ALGLIB)
#include <stdafx.h>
#include <optimization.h>
#endif

bool untangle_triangles_2D(
  std::vector<std::array<double, 2> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3> > &triangles,
  const std::vector<std::array<std::array<double, 3>, 3> > &triIdealShapes,
  double theta, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB)
  Msg::Error("Winslow untangler not implemented yet");
  return false;
#else
  Msg::Error("Winslow untangler requires Eigen and Alglib");
  return false;
#endif
}

bool untangle_tetrahedra(
  std::vector<std::array<double, 3> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4> > &tets,
  const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
  double theta, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB)
  Msg::Error("Winslow untangler not implemented yet");
  return false;
#else
  Msg::Error("Winslow untangler requires Eigen and Alglib");
  return false;
#endif
}
