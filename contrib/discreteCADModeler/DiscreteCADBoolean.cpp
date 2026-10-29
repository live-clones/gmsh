// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "DiscreteCADBoolean.h"

#if defined(HAVE_LIBIGL)
#include <igl/copyleft/cgal/mesh_boolean.h>
#endif

bool meshBooleanLibigl(int op, const std::vector<double> &xyzA,
                       const std::vector<int> &triA,
                       const std::vector<double> &xyzB,
                       const std::vector<int> &triB, std::vector<double> &xyz,
                       std::vector<int> &tri, std::vector<int> &birth)
{
#if defined(HAVE_LIBIGL)
  auto vertices = [](const std::vector<double> &x) {
    Eigen::MatrixXd v(x.size() / 3, 3);
    for(std::size_t i = 0; i < x.size() / 3; i++)
      for(int k = 0; k < 3; k++) v(i, k) = x[3 * i + k];
    return v;
  };
  auto triangles = [](const std::vector<int> &t) {
    Eigen::MatrixXi f(t.size() / 3, 3);
    for(std::size_t i = 0; i < t.size() / 3; i++)
      for(int k = 0; k < 3; k++) f(i, k) = t[3 * i + k];
    return f;
  };
  static const igl::MeshBooleanType types[3] = {
    igl::MESH_BOOLEAN_TYPE_UNION, igl::MESH_BOOLEAN_TYPE_INTERSECT,
    igl::MESH_BOOLEAN_TYPE_MINUS};
  if(op < 0 || op > 2) return false;
  Eigen::MatrixXd VC;
  Eigen::MatrixXi FC;
  Eigen::VectorXi J;
  try {
    if(!igl::copyleft::cgal::mesh_boolean(vertices(xyzA), triangles(triA),
                                          vertices(xyzB), triangles(triB),
                                          types[op], VC, FC, J))
      return false;
  } catch(...) {
    Msg::Error("libigl mesh boolean failed");
    return false;
  }
  xyz.resize(3 * VC.rows());
  for(Eigen::Index i = 0; i < VC.rows(); i++)
    for(int k = 0; k < 3; k++) xyz[3 * i + k] = VC(i, k);
  tri.resize(3 * FC.rows());
  birth.resize(FC.rows());
  for(Eigen::Index i = 0; i < FC.rows(); i++) {
    for(int k = 0; k < 3; k++) tri[3 * i + k] = FC(i, k);
    birth[i] = J(i);
  }
  return true;
#else
  Msg::Error("The boolean operations of the discrete CAD modeler require "
             "libigl");
  return false;
#endif
}
