// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtCrossField.h"

/* System includes */
#include <vector>
#include <array>
#include <unordered_map>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <limits>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "gmsh.h"

/* Linear algebra solver */
#if defined(HAVE_EIGEN)
#include <Eigen/IterativeLinearSolvers>
#include <Eigen/SparseCholesky>
#include <Eigen/SparseLU>
#endif
#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemGmm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "linearSystemMUMPS.h"
#include "linearSystemEigen.h"
#endif

/* QuadMeshingTools includes */
#include "arrayGeometry.h"
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "geolog.h"

/* TODO list:
 * - Cross field smoother with a single Laplacian solve
 * - Cross field smoother with a single factorization
 * - MUMPS support
 */

using namespace ArrayGeometry;
using namespace CppUtils;

using std::array;
using std::pair;
using std::unordered_map;
using std::vector;

namespace QMT {

  constexpr double EPS = 1.e-14;

  using id = uint32_t;
  using sid = int64_t;
  using id2 = std::array<id, 2>;
  using id3 = std::array<id, 3>;
  using sid3 = std::array<sid, 3>;
  constexpr id NO_ID = (id)-1;
  constexpr sid NO_SID = (sid)NO_ID;

  struct IJV {
    id2 ij;
    double val;
    bool operator<(const IJV &b) const
    {
      return ij[0] < b.ij[0] || (ij[0] == b.ij[0] && ij[1] < b.ij[1]);
    }
  };

  struct IV {
    id i;
    double val;
    bool operator<(const IV &b) const { return i < b.i; }
  };

  class CrossFieldLinearSystem {
  protected:
    size_t N = 0;
#if defined(HAVE_EIGEN)
    Eigen::VectorXd x, b;
    Eigen::SparseMatrix<double> A;
    Eigen::SparseLU<Eigen::SparseMatrix<double> > solver;
#endif

  public:
    CrossFieldLinearSystem(size_t N_) : N(N_)
    {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: initialize sparse matrix, vectors and solver");
      x.resize(N);
      x.fill(0.);
      b.resize(N);
      b.fill(0.);
      A.resize(N, N);
#else
      Msg::Error("Linear solver Eigen required");
#endif
    }

    bool
    add_sparse_coefficients(const std::vector<std::vector<size_t> > &columns,
                            const std::vector<std::vector<double> > &values,
                            bool firstTime = false)
    {
#if defined(HAVE_EIGEN)
      // Msg::Debug("Eigen call: add coefficients");
      std::vector<Eigen::Triplet<double, size_t> > triplets;
      triplets.reserve(values.size());
      if(firstTime) {
        for(size_t i = 0; i < columns.size(); ++i) {
          for(size_t k = 0; k < columns[i].size(); ++k) {
            size_t j = columns[i][k];
            double val = values[i][k];
            triplets.push_back({i, j, val});
          }
        }
        A.setFromTriplets(triplets.begin(), triplets.end());
      }
      else {
        for(size_t i = 0; i < columns.size(); ++i) {
          for(size_t k = 0; k < columns[i].size(); ++k) {
            size_t j = columns[i][k];
            double val = values[i][k];
            A.coeffRef(i, j) += val; /* entry (i,j) should already exists */
          }
        }
      }
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool set_rhs_values(const std::vector<double> &rhs)
    {
#if defined(HAVE_EIGEN)
      // Msg::Debug("Eigen call: add rhs values");
      for(size_t i = 0; i < rhs.size(); ++i)
        if(rhs[i] != 0.) { b[i] = rhs[i]; }
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool preprocess_sparsity_pattern()
    {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: analyse sparse matrix sparsity pattern");
      solver.analyzePattern(A);
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool factorize()
    {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: factorize sparse matrix");
      solver.factorize(A);
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool solve(std::vector<double> &slt)
    {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: solve linear system");
      x = solver.solve(b);
      if(solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning(
          "Eigen: failed to solve linear system with SparseLU (%li variables)",
          N);
        return false;
      }
      slt.resize(x.size());
      for(size_t i = 0; i < N; ++i) slt[i] = x[i];
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }
  };

  bool compute_triangle_adjacencies(const vector<id3> &triangles,
                                    vector<sid3> &triangle_neighbors,
                                    vector<vector<id> > &nm_triangle_neighbors,
                                    vector<id2> &uIEdges, vector<id> &old2IEdge,
                                    vector<vector<id> > &uIEdgeToOld)
  {
    triangle_neighbors.clear();
    triangle_neighbors.resize(triangles.size(), {NO_ID, NO_ID, NO_ID});
    nm_triangle_neighbors.clear();

    constexpr size_t NBF = 3;

    /* Store element 'faces', with duplicates for further 'equality test' */
    std::vector<id2> faces;
    for(size_t i = 0; i < triangles.size(); ++i) {
      for(size_t lf = 0; lf < NBF; ++lf) {
        id2 face = {triangles[i][lf], triangles[i][(lf + 1) % NBF]};
        std::sort(face.begin(), face.end());
        faces.push_back(face);
      }
    }

    /* Reduce 'duplicated faces' to 'unique faces', keeping the 'old2new'
     * mapping */
    size_t nbUniques = sort_unique_with_perm(faces, uIEdges, old2IEdge);

    /* Build the 'unique face to elements' mapping */
    uIEdgeToOld.resize(nbUniques);
    for(size_t i = 0; i < triangles.size(); ++i) {
      for(size_t lf = 0; lf < NBF; ++lf) {
        id facePos = NBF * i + lf;
        uIEdgeToOld[old2IEdge[facePos]].push_back(facePos);
      }
    }

    /* Loop over 'unique face to elements' and set the element adjacencies */
    constexpr id2 NO_FACE = {NO_ID, NO_ID};
    for(size_t i = 0; i < nbUniques; ++i) {
      if(uIEdges[i] == NO_FACE) continue;
      if(uIEdges[i][0] == NO_ID) return false;
      if(uIEdges[i][1] == NO_ID) return false;
      if(uIEdgeToOld[i].size() == 1) { /* boundary */
        id eltId = uIEdgeToOld[i][0] / NBF;
        id lf = uIEdgeToOld[i][0] % NBF;
        triangle_neighbors[eltId][lf] = NO_ID;
      }
      else if(uIEdgeToOld[i].size() == 2) { /* regular face */
        id e1 = uIEdgeToOld[i][0] / NBF;
        id lf1 = uIEdgeToOld[i][0] % NBF;
        id e2 = uIEdgeToOld[i][1] / NBF;
        id lf2 = uIEdgeToOld[i][1] % NBF;
        triangle_neighbors[e1][lf1] = NBF * e2 + lf2;
        triangle_neighbors[e2][lf2] = NBF * e1 + lf1;
      }
      else if(uIEdgeToOld[i].size() > 2) { /* non manifold face */
        for(size_t j = 0; j < uIEdgeToOld[i].size(); ++j) {
          id e = uIEdgeToOld[i][j] / NBF;
          id lf = uIEdgeToOld[i][j] % NBF;
          std::vector<id> neighs;
          for(size_t k = 0; k < uIEdgeToOld[i].size(); ++k) {
            if(uIEdgeToOld[i][k] != uIEdgeToOld[i][j]) {
              neighs.push_back(uIEdgeToOld[i][k]);
            }
          }
          neighs.shrink_to_fit();
          id pos = nm_triangle_neighbors.size();
          nm_triangle_neighbors.push_back(neighs);
          triangle_neighbors[e][lf] = -((sid)pos + 1);
        }
      }
    }

    /* Reduce memory consumption */
    triangle_neighbors.shrink_to_fit();
    nm_triangle_neighbors.shrink_to_fit();

    return true;
  }

  /* two unknowns (x_2i, x_2i+1) for each edge */
  bool stiffness_coefficient(int N,
                             const std::vector<std::array<double, 3> > &points,
                             const std::vector<std::array<id, 3> > &triangles,
                             id e, const vector<id2> &uIEdges,
                             const vector<id> &old2IEdge,
                             const vector<vector<id> > &uIEdgeToOld,
                             vector<IV> &iv, vector<IJV> &ijv)
  {
    if(uIEdgeToOld[e].size() != 2) {
      Msg::Error("assembly, edge %li: uIEdgeToOld[e].size() = %li", e,
                 uIEdgeToOld[e].size());
      return false;
    }
    /* edge vertices */
    id v1 = uIEdges[e][0];
    id v2 = uIEdges[e][1];
    vec3 e_x = points[v2] - points[v1];
    double lenr = length(e_x);
    if(lenr < EPS) {
      Msg::Error("edge too small: v1=%li, v2=%li, length = %e", v1, v2, lenr);
      return false;
    }
    e_x = (1. / lenr) * e_x;
    /* four neighbor edges */
    id bvars[4] = {NO_ID, NO_ID, NO_ID, NO_ID};
    double alpha[4] = {0., 0., 0., 0.};
    double CR_weight[4] = {-1. / 4, -1. / 4, -1. / 4, -1. / 4};
    vec3 prevN;
    for(size_t s = 0; s < 2; ++s) { /* two triangles */
      id oe = uIEdgeToOld[e][s];
      id t = oe / 3;
      id le = oe % 3;
      vec3 N = triangleNormal(points[triangles[t][0]], points[triangles[t][1]],
                              points[triangles[t][2]]);
      if(s == 1 && dot(prevN, N) < 0.) N = -1. * N;
      prevN = N;
      // N = {0,0,1};
      vec3 e_y = cross(N, e_x);
      if(maxAbs(e_y) == 0.) {
        Msg::Error("length(e_y) = %f", length(e_y));
        return false;
      }
      normalize(e_y);

      for(size_t k = 0; k < 2; ++k) { /* two other edges in triangle t */
        id aoe = 3 * t + (le + 1 + k) % 3;
        id ae = old2IEdge[aoe];
        id2 aedge = uIEdges[ae];

        bvars[2 * s + k] = ae;
        vec3 edg = points[aedge[1]] - points[aedge[0]];
        double len = length(edg);
        if(len < EPS) {
          Msg::Error("edge too small: t=%li, k = %li, edge=%li, length = %e", t,
                     k, aedge, len);
          return false;
        }
        edg = (1. / len) * edg;

        /* 360deg angle (used for the angle rotation) */
        double cx = dot(edg, e_x);
        double cy = dot(edg, e_y);
        alpha[2 * s + k] = atan2(cy, cx);
        if(alpha[2 * s + k] < 0.) alpha[2 * s + k] += 2. * M_PI;

        /* 180deg edge-edge angle (used for the Crouzeix Raviart) */
        double agl = 0.;
        if(aedge[0] == v1) { agl = angleVectorsAlreadyNormalized(edg, e_x); }
        else if(aedge[1] == v1) {
          agl = angleVectorsAlreadyNormalized(edg, -1. * e_x);
        }
        else if(aedge[0] == v2) {
          agl = angleVectorsAlreadyNormalized(-1. * edg, e_x);
        }
        else if(aedge[1] == v2) {
          agl = angleVectorsAlreadyNormalized(-1. * edg, -1. * e_x);
        }
        else {
          Msg::Error("should not happen");
          return false;
        }
        CR_weight[2 * s + k] = -2. / tan(agl);
      }
    }
    /* compute coefficients */
    double isum =
      -1. * (CR_weight[0] + CR_weight[1] + CR_weight[2] + CR_weight[3]);
    for(size_t k = 0; k < 4; ++k) CR_weight[k] = CR_weight[k] / isum;

    iv.clear();
    ijv.clear();
    id x_i = 2 * e;
    id y_i = 2 * e + 1;
    iv.push_back({x_i, 1.});
    iv.push_back({y_i, 1.});
    double Nd = double(N);
    for(size_t j = 0; j < 4; ++j) {
      id x_j = 2 * bvars[j];
      id y_j = 2 * bvars[j] + 1;
      ijv.push_back({{x_i, x_j}, CR_weight[j] * cos(Nd * alpha[j])});
      ijv.push_back({{x_i, y_j}, CR_weight[j] * -1. * sin(Nd * alpha[j])});
      ijv.push_back({{y_i, x_j}, CR_weight[j] * sin(Nd * alpha[j])});
      ijv.push_back({{y_i, y_j}, CR_weight[j] * cos(Nd * alpha[j])});
    }

    return true;
  }

  bool prepare_system(const vector<IV> &K_diag, const vector<IJV> &K_coefs,
                      vector<vector<size_t> > &columns,
                      vector<vector<double> > &values)
  {
    vector<IJV> coefs = K_coefs;
    coefs.resize(coefs.size() + K_diag.size());
    for(size_t i = 0; i < K_diag.size(); ++i) {
      coefs[K_coefs.size() + i] = {{id(K_diag[i].i), id(K_diag[i].i)},
                                   K_diag[i].val};
    }
    std::sort(coefs.begin(), coefs.end());

    size_t cur_i = coefs[0].ij[0];
    size_t cur_j = coefs[0].ij[1];
    double acc_val = coefs[0].val;
    for(size_t k = 1; k < coefs.size(); ++k) {
      id i = coefs[k].ij[0];
      id j = coefs[k].ij[1];
      double v = coefs[k].val;
      if(i != cur_i) {
        if(std::abs(acc_val) > EPS) {
          columns[cur_i].push_back(cur_j);
          values[cur_i].push_back(acc_val);
        }
        cur_i = i;
        acc_val = v;
        cur_j = j;
      }
      else if(j != cur_j) {
        if(std::abs(acc_val) > EPS) {
          columns[cur_i].push_back(cur_j);
          values[cur_i].push_back(acc_val);
        }
        cur_i = i;
        acc_val = v;
        cur_j = j;
      }
      else {
        acc_val += v;
      }
    }
    if(std::abs(acc_val) > EPS) {
      columns[cur_i].push_back(cur_j);
      values[cur_i].push_back(acc_val);
    }

    return true;
  }

  bool expand_dirichlet_boundary_conditions(
    int N, const std::vector<std::array<double, 3> > &points,
    const std::vector<std::array<id, 3> > &triangles,
    const vector<id2> &uIEdges, const vector<id> &old2IEdge,
    const vector<vector<id> > &uIEdgeToOld, size_t nb_layers,
    vector<bool> &dirichletEdge, vector<vec2> &dirichletValue, int verbosity)
  {
    /* Look for expanded BC edges */
    vector<bool> extDirichletEdge = dirichletEdge;
    vector<id> new_edges;
    for(size_t layer = 0; layer < nb_layers; ++layer) {
      for(size_t e = 0; e < uIEdges.size(); ++e)
        if(extDirichletEdge[e]) {
          for(size_t i = 0; i < uIEdgeToOld[e].size(); ++i) {
            id t = uIEdgeToOld[e][i] / 3;
            for(size_t le = 0; le < 3; ++le) {
              id oe2 = 3 * t + le;
              id e2 = old2IEdge[oe2];
              if(!extDirichletEdge[e2]) { new_edges.push_back(e2); }
            }
          }
        }
      sort_unique(new_edges);
      for(size_t i = 0; i < new_edges.size(); ++i) {
        extDirichletEdge[new_edges[i]] = true;
      }
    }
    if(new_edges.size() == 0) {
      if(verbosity >= 2)
        Msg::Warning("no new edges to expand dirichlet boundary conditions");
      return false;
    }

    if(verbosity >= 2)
      Msg::Info("Dirichlet B.C. expansion: added %li edges (for %li layers)",
                new_edges.size(), nb_layers);

    /* Small system for BC expansion */
    vector<IJV> K_coefs;
    for(size_t k = 0; k < new_edges.size(); ++k) {
      id e = new_edges[k];
      vector<IV> iv;
      vector<IJV> ijv;
      bool oks = stiffness_coefficient(N, points, triangles, e, uIEdges,
                                       old2IEdge, uIEdgeToOld, iv, ijv);
      if(!oks || iv.size() != 2 || iv[0].i != 2 * e || iv[1].i != 2 * e + 1) {
        Msg::Error("failed to get stiffness coefficients for edge e = %li", e);
        return false;
      }
      /* Add coefficients for interaction i-j of edges in extDirichletEdge */
      for(size_t l = 0; l < ijv.size(); ++l)
        if(extDirichletEdge[ijv[l].ij[1] / 2]) { K_coefs.push_back(ijv[l]); }
    }
    vector<IV> K_diag;
    vector<vector<size_t> > A_col(2 * uIEdges.size());
    vector<vector<double> > A_coef(2 * uIEdges.size());
    bool okp = prepare_system(K_diag, K_coefs, A_col, A_coef);
    if(!okp) {
      Msg::Error("failed to prepare system");
      return false;
    }

    /* Explicit solver (local smoothing) */
    for(size_t e = 0; e < uIEdges.size(); ++e)
      if(extDirichletEdge[e] && !dirichletEdge[e]) {
        dirichletValue[e] = {0., 0.};
      }
    for(size_t iter = 0; iter < 10 * nb_layers; ++iter) {
      for(size_t e = 0; e < uIEdges.size(); ++e)
        if(extDirichletEdge[e] && !dirichletEdge[e]) {
          for(size_t d = 0; d < 2; ++d) {
            id i = 2 * e + d;
            dirichletValue[e][d] = 0.;
            for(size_t l = 0; l < A_col[i].size(); ++l) {
              id j = A_col[i][l];
              if(!extDirichletEdge[j / 2]) continue;
              double w = A_coef[i][l];
              dirichletValue[e][d] += -1. * w * dirichletValue[j / 2][j % 2];
            }
          }
          double n2 = length(dirichletValue[e]);
          if(n2 < EPS) { continue; }
          dirichletValue[e][0] /= n2;
          dirichletValue[e][1] /= n2;
        }
    }

    /* Set expanded edges as Dirichlet edges */
    for(size_t e = 0; e < uIEdges.size(); ++e)
      if(extDirichletEdge[e] && !dirichletEdge[e] &&
         length(dirichletValue[e]) > EPS) {
        dirichletEdge[e] = true;
      }

    return true;
  }

  bool compute_cross_field_with_multilevel_diffusion(
    int N, const std::vector<std::array<double, 3> > &points,
    const std::vector<std::array<id, 2> > &lines,
    const std::vector<std::array<id, 3> > &triangles,
    std::vector<std::array<double, 3> > &triEdgeTheta, int nbDiffusionLevels,
    double thresholdNormConvergence, int nbBoundaryExtensionLayer,
    int verbosity)
  {
    if(N != 4 && N != 6) return false;

    /* Build unique edges and association with adjacent triangles,
     * including the non-manifold cases */
    vector<id2> uIEdges;
    vector<id> old2IEdge;
    vector<vector<id> > uIEdgeToOld;
    std::vector<sid3> triangle_neighbors;
    std::vector<std::vector<id> > nm_triangle_neighbors;
    bool oka = compute_triangle_adjacencies(triangles, triangle_neighbors,
                                            nm_triangle_neighbors, uIEdges,
                                            old2IEdge, uIEdgeToOld);
    if(!oka) {
      Msg::Error("failed to compute mesh adjacencies");
      return false;
    }

    /* Bbox diagonal is used later to specify the diffusion length */
    double diag = bboxDiag(points);
    if(verbosity > 0)
      Msg::Info("Heat-based cross field computation, input: %li points, %li "
                "lines, %li triangles, %li internal edges, bbox diag = %li",
                points.size(), lines.size(), triangles.size(), uIEdges.size(),
                diag);

    if(uIEdges.size() == 0) {
      Msg::Error("no internal edges");
      return false;
    }

    /* System unknowns: cos(Nt),sin(Nt) for each edge */
    vector<double> x(2 * uIEdges.size(), 0.);

    /* Initial Dirichlet boundary conditions
     * alignment of crosses with edges (relative angle = 0)
     * theta_e = 0 => (cos4t/sin4t) = (1,0) */
    size_t nbc = 0;
    vector<bool> dirichletEdge(uIEdges.size(), false);
    vector<vec2> dirichletValue(uIEdges.size(), {1., 0.});
    for(size_t e = 0; e < uIEdges.size(); ++e)
      if(uIEdgeToOld[e].size() != 2) {
        dirichletEdge[e] = true;
        dirichletValue[e] = {1., 0.};
        nbc += 1;
      }
    for(size_t l = 0; l < lines.size(); ++l) {
      /* mark the lines as boundary conditions */
      id2 edge = sorted(lines[l][0], lines[l][1]);
      auto it = std::find(uIEdges.begin(), uIEdges.end(), edge);
      if(it != uIEdges.end()) {
        id e = id(it - uIEdges.begin());
        dirichletEdge[e] = true;
        dirichletValue[e] = {1., 0.};
        nbc += 1;
      }
    }
    if(verbosity >= 2)
      Msg::Info("- boundary conditions: %li crosses fixed on edges", nbc);

    if(nbBoundaryExtensionLayer > 0) {
      bool oke = expand_dirichlet_boundary_conditions(
        N, points, triangles, uIEdges, old2IEdge, uIEdgeToOld,
        nbBoundaryExtensionLayer, dirichletEdge, dirichletValue, verbosity);
      if(!oke) {
        Msg::Warning("failed to expand dirichlet boundary conditions");
      }
      for(size_t e = 0; e < uIEdges.size(); ++e) {
        x[2 * e + 0] = dirichletValue[e][0];
        x[2 * e + 1] = dirichletValue[e][1];
      }
    }

    if(verbosity >= 2)
      Msg::Info(
        "- compute stiffness matrix coefficients (Crouzeix-Raviart) ...");

    vector<IV> K_diag;
    vector<IJV> K_coefs;
    vector<double> rhs(2 * uIEdges.size(), 0.);
    vector<double> Mass(2 * uIEdges.size(),
                        1.); /* diagonal for Crouzeix-Raviart */
    for(size_t e = 0; e < uIEdges.size(); ++e) {
      if(!dirichletEdge[e]) {
        vector<IV> iv;
        vector<IJV> ijv;
        bool oks = stiffness_coefficient(N, points, triangles, e, uIEdges,
                                         old2IEdge, uIEdgeToOld, iv, ijv);
        if(!oks) {
          Msg::Error(
            "failed to compute stiffness matrix coefficients for e = %li", e);
          return false;
        }
        for(size_t i = 0; i < iv.size(); ++i) K_diag.push_back(iv[i]);
        for(size_t i = 0; i < ijv.size(); ++i) K_coefs.push_back(ijv[i]);
        id t1 = uIEdgeToOld[e][0] / 3;
        id t2 = uIEdgeToOld[e][1] / 3;
        double area1 =
          triangleArea(points[triangles[t1][0]], points[triangles[t1][1]],
                       points[triangles[t1][2]]);
        double area2 =
          triangleArea(points[triangles[t2][0]], points[triangles[t2][1]],
                       points[triangles[t2][2]]);
        Mass[2 * e + 0] = 1. / 3 * (area1 + area2);
        Mass[2 * e + 1] = 1. / 3 * (area1 + area2);
      }
      else { /* Dirichlet BC */
        K_diag.push_back({id(2 * e + 0), 1.});
        rhs[2 * e + 0] = dirichletValue[e][0];
        K_diag.push_back({id(2 * e + 1), 1.});
        rhs[2 * e + 1] = dirichletValue[e][1];
      }
    }

    double eavg = 0.;
    double emin = DBL_MAX;
    double emax = -DBL_MAX;
    for(size_t e = 0; e < uIEdges.size(); ++e) {
      double len = length(points[uIEdges[e][1]] - points[uIEdges[e][0]]);
      eavg += len;
      emin = std::min(len, emin);
      emax = std::max(len, emax);
    }
    eavg /= uIEdges.size();

    if(verbosity >= 2)
      Msg::Info("- edge size: min=%.3f, avg=%.3f, max=%.3f | bbox diag: %.3f",
                emin, eavg, emax, diag);

    /* prepare system */
    vector<vector<size_t> > K_columns(2 * uIEdges.size());
    vector<vector<double> > K_values(2 * uIEdges.size());
    {
      bool okp = prepare_system(K_diag, K_coefs, K_columns, K_values);
      if(!okp) {
        Msg::Error("failed to prepare system");
        return false;
      }
    }

    double dtInitial = (0.1 * diag) * (0.1 * diag);
    double dtFinal = (3. * emin) * (3. * emin);

    if(verbosity >= 1)
      Msg::Info("- diffusion and projection loop (%li levels, %li unknowns, dt "
                "= %.3f .. %.3f) ...",
                nbDiffusionLevels, 2 * uIEdges.size(), dtInitial, dtFinal);

    double wti = TimeOfDay();
    for(size_t e = 0; e < uIEdges.size(); ++e) {
      x[2 * e + 0] = dirichletValue[e][0];
      x[2 * e + 1] = dirichletValue[e][1];
    }

    vector<double> steps;
    if(nbDiffusionLevels > 1) {
      for(size_t i = 0; i < nbDiffusionLevels;
          ++i) { /* resolution transition */
        double dt = dtInitial + (dtFinal - dtInitial) * double(i) /
                                  double(nbDiffusionLevels - 1);
        steps.push_back(dt);
      }
    }
    else {
      steps.push_back(dtFinal);
    }

    {
      /* Initialize system (I/dt + M^-1 * L) x_(i+1) = 1/dt * x_i     (Ax = B)
       */
      vector<vector<size_t> > Acol = K_columns;
      vector<vector<double> > Aval_add = K_values; /* to get sparsity pattern */
      for(size_t i = 0; i < Aval_add.size(); ++i)
        std::fill(Aval_add[i].begin(), Aval_add[i].end(), 0.);
      vector<double> B = x;
      vector<double> norms(uIEdges.size(), 0.);
      vector<double> prevNorms = norms;

      CrossFieldLinearSystem solver(2 * uIEdges.size());

      vector<double> diag_sum(2 * uIEdges.size(), 0.);
      for(size_t i = 0; i < Acol.size(); ++i) {
        if(!dirichletEdge[i / 2]) {
          for(size_t j = 0; j < Acol[i].size(); ++j) {
            Aval_add[i][j] = 1. / Mass[i] * K_values[i][j];
          }
        }
        else {
          Aval_add[i] = {1.};
        }
      }
      solver.add_sparse_coefficients(Acol, Aval_add, true);
      for(size_t i = 0; i < Aval_add.size(); ++i) Aval_add[i].clear();
      for(size_t i = 0; i < Acol.size(); ++i) Acol[i].clear();
      bool okp = solver.preprocess_sparsity_pattern();
      if(!okp) {
        Msg::Error("linear solver analysis failed");
        return false;
      }

      /* Loop over the changing timesteps */
      double prev_dt = DBL_MAX;
      for(int iter = 0; iter < steps.size(); ++iter) {
        if(iter > 0 && steps[iter] > prev_dt) continue;
        double dt = steps[iter];
        prev_dt = dt;

        if(verbosity >= 1)
          Msg::Info("  - step %li/%li | dt = %.3f, linear system loop ...",
                    iter + 1, steps.size(), dt);

        /* Update LHS matrix with the new timestep */
        for(size_t i = 0; i < Acol.size(); ++i) {
          if(!dirichletEdge[i / 2]) {
            Acol[i] = {i};
            Aval_add[i] = {-diag_sum[i] + 1. / dt};
            diag_sum[i] = 1. / dt;
          }
        }
        bool oku = solver.add_sparse_coefficients(Acol, Aval_add, false);
        if(!oku) {
          Msg::Error("failed to update linear system");
          return false;
        }
        solver.factorize();

        /* Loop at fixed time step */
        constexpr size_t subiter_max = 25;
        for(size_t subiter = 0; subiter < subiter_max; ++subiter) {
          prevNorms = norms;

          /* Update RHS */
          B = x;
          for(size_t i = 0; i < B.size(); ++i)
            if(!dirichletEdge[i / 2]) B[i] /= dt;
          solver.set_rhs_values(B);

          bool oks = solver.solve(x);
          if(!oks) {
            Msg::Error("failed to solve linear system");
            return false;
          }

          /* Normalize cross field and gather norm stats */
          double nmi = DBL_MAX;
          double nma = -DBL_MAX;
          for(size_t e = 0; e < uIEdges.size(); ++e) {
            norms[e] =
              std::sqrt(x[2 * e] * x[2 * e] + x[2 * e + 1] * x[2 * e + 1]);
            nmi = std::min(nmi, norms[e]);
            nma = std::max(nma, norms[e]);
            if(!dirichletEdge[e] && norms[e] > EPS) {
              x[2 * e + 0] /= norms[e];
              x[2 * e + 1] /= norms[e];
            }
          }
          // Msg::Info("            |   norm, min = {}, max = {}", nmi, nma);
          const double EPS_NORM = 1.e-1;
          if(nma > 1. + EPS_NORM) {
            steps[iter] /= 10;
            dt = steps[iter];
            iter -= 1;
            if(verbosity >= 2)
              Msg::Warning("           |   max(norm)=%.3f (should be 1.), "
                           "solve failed, new time step: dt = %.3f",
                           nma, dt);
            break;
          }
          if(subiter > 0 || iter > 0) {
            double linf = 0.;
            for(size_t i = 0; i < norms.size(); ++i)
              if(!dirichletEdge[i]) {
                linf = std::max(linf, norms[i] - prevNorms[i]);
              }
            if(verbosity >= 3)
              Msg::Info("           |   system solved, norm diff max: %.3f, "
                        "norm range: %.3f - %.3f",
                        linf, nmi, nma);
            if(linf < 1.e-3) break;
          }
          else {
            if(verbosity >= 3) Msg::Info("           |   system solved");
          }
        }
      }
    }
    double et = TimeOfDay() - wti;
    if(verbosity >= 2) Msg::Info("- cross field elapsed time: %.3f", et);

    { /* Export solution */
      triEdgeTheta.resize(triangles.size());
      for(size_t t = 0; t < triangles.size(); ++t) {
        for(size_t le = 0; le < 3; ++le) {
          id e = old2IEdge[3 * t + le];
          double len =
            std::sqrt(x[2 * e] * x[2 * e] + x[2 * e + 1] * x[2 * e + 1]);
          double theta =
            (len > EPS) ?
              1. / double(N) * atan2(x[2 * e + 1] / len, x[2 * e] / len) :
              0.;
          triEdgeTheta[t][le] = theta;
        }
      }
    }

    return true;
  }

  inline SVector3 tri_normal(MTriangle *t)
  {
    SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
                 t->getVertex(1)->y() - t->getVertex(0)->y(),
                 t->getVertex(1)->z() - t->getVertex(0)->z());
    SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
                 t->getVertex(2)->y() - t->getVertex(0)->y(),
                 t->getVertex(2)->z() - t->getVertex(0)->z());
    SVector3 normal_to_triangle = crossprod(v20, v10);
    normal_to_triangle.normalize();
    return normal_to_triangle;
  }

  inline SVector3 crouzeix_raviart_interpolation(SVector3 lambda,
                                                 SVector3 edge_values[3])
  {
    double x = lambda[1];
    double y = lambda[2];
    SVector3 shape = {1.0 - 2.0 * y, -1.0 + 2.0 * (x + y), 1.0 - 2.0 * x};
    return shape[0] * edge_values[0] + shape[1] * edge_values[1] +
           shape[2] * edge_values[2];
  }

  int local_frame(const MVertex *v, const std::vector<MTriangle *> &tris,
                  SVector3 &e_x, SVector3 &e_y, SVector3 &e_z)
  {
    e_x = SVector3(DBL_MAX, DBL_MAX, DBL_MAX);
    SVector3 avg(0., 0., 0.);
    for(MTriangle *t : tris) {
      avg += tri_normal(t);
      if(e_x.x() == DBL_MAX) {
        for(size_t le = 0; le < 3; ++le) {
          MVertex *v1 = t->getVertex(le);
          MVertex *v2 = t->getVertex((le + 1) % 3);
          if(v1 == v) {
            e_x = v2->point() - v1->point();
            break;
          }
          else if(v2 == v) {
            e_x = v1->point() - v2->point();
            break;
          }
        }
      }
    }
    if(avg.norm() < 1.e-16) {
      Msg::Error("local frame for %li triangles: avg normal = %.2f, %.2f, %.2f",
                 tris.size(), avg.x(), avg.y(), avg.z());
      return -1;
    }
    if(e_x.norm() < 1.e-16) {
      Msg::Error("local frame for %li triangles: e_x = %.2f, %.2f, %.2f",
                 tris.size(), e_x.x(), e_x.y(), e_x.z());
      return -1;
    }
    e_x.normalize();
    avg.normalize();
    e_z = avg;
    e_y = crossprod(e_z, e_x);
    if(e_y.norm() < 1.e-16) {
      Msg::Error("local frame for %li triangles: e_y = %.2f, %.2f, %.2f",
                 tris.size(), e_y.x(), e_y.y(), e_y.z());
      return -1;
    }
    e_y.normalize();

    return 0;
  }

  int ordered_fan_around_vertex(const MVertex *v,
                                const std::vector<MTriangle *> &tris,
                                std::vector<std::array<MVertex *, 2> > &vPairs)
  {
    vPairs.clear();
    if(tris.size() < 3) return -1;

    std::unordered_set<MTriangle *> done;
    { /* Init */
      MTriangle *t = tris[0];
      for(size_t le = 0; le < 3; ++le) {
        MVertex *v1 = t->getVertex(le);
        MVertex *v2 = t->getVertex((le + 1) % 3);
        if(v1 != v && v2 != v) {
          vPairs.push_back({v1, v2});
          done.insert(t);
          break;
        }
      }
    }

    while(vPairs.back().back() != vPairs[0][0]) {
      MVertex *last = vPairs.back().back();
      /* Look for next edge connected to last */
      bool found = false;
      for(MTriangle *t : tris) {
        if(done.find(t) != done.end()) continue;
        for(size_t le = 0; le < 3; ++le) {
          MVertex *v1 = t->getVertex(le);
          MVertex *v2 = t->getVertex((le + 1) % 3);
          if(v1 != v && v2 != v) {
            if(v1 == last) {
              vPairs.push_back({v1, v2});
              done.insert(t);
              found = true;
              break;
            }
            else if(v2 == last) {
              vPairs.push_back({v2, v1});
              done.insert(t);
              found = true;
              break;
            }
          }
        }
        if(found) break;
      }
      if(!found) {
        Msg::Error("failed to order fan vertex pairs");
        return -1;
      }
    }

    return 0;
  }
} // namespace QMT

int computeCrossFieldWithHeatEquation(
  int N, const std::vector<MTriangle *> &triangles,
  const std::vector<MLine *> &lines,
  std::vector<std::array<double, 3> > &triEdgeTheta, int nbDiffusionLevels,
  double thresholdNormConvergence, int nbBoundaryExtensionLayer, int verbosity)
{
  /* Build discrete mesh without reference to gmsh structures */
  std::vector<std::array<double, 3> > dpoints;
  std::vector<std::array<QMT::id, 2> > dlines;
  std::vector<std::array<QMT::id, 3> > dtriangles;
  std::vector<QMT::id> old2new;
  {
    old2new.reserve(3 * triangles.size());
    dpoints.reserve(3 * triangles.size());
    dlines.reserve(lines.size());
    dtriangles.reserve(triangles.size());

    constexpr QMT::id X = std::numeric_limits<QMT::id>::max();

    for(MLine *l : lines) {
      std::array<QMT::id, 2> line;
      for(size_t lv = 0; lv < 2; ++lv) {
        MVertex *v = l->getVertex(lv);
        size_t num = v->getNum();
        if(num >= old2new.size()) { old2new.resize(num + 1, X); }
        if(old2new[num] == X) {
          old2new[num] = dpoints.size();
          std::array<double, 3> pt = {v->x(), v->y(), v->z()};
          dpoints.push_back(pt);
        }
        line[lv] = old2new[num];
      }
      std::sort(line.begin(), line.end());
      dlines.push_back(line);
    }
    for(MTriangle *t : triangles) {
      std::array<QMT::id, 3> tri;
      for(size_t lv = 0; lv < 3; ++lv) {
        MVertex *v = t->getVertex(lv);
        size_t num = v->getNum();
        if(num >= old2new.size()) { old2new.resize(num + 1, X); }
        if(old2new[num] == X) {
          old2new[num] = dpoints.size();
          std::array<double, 3> pt = {v->x(), v->y(), v->z()};
          dpoints.push_back(pt);
        }
        tri[lv] = old2new[num];
      }
      dtriangles.push_back(tri);
    }
  }

  bool ok = QMT::compute_cross_field_with_multilevel_diffusion(
    N, dpoints, dlines, dtriangles, triEdgeTheta, nbDiffusionLevels,
    thresholdNormConvergence, nbBoundaryExtensionLayer, verbosity);
  return ok ? 0 : -1;
}

// inline double compat_orientation_extrinsic(
//     int Ns,
//     const SVector3 &o0,
//     const SVector3 &n0,
//     const SVector3 &o1,
//     const SVector3 &n1,
//     SVector3 &a1, SVector3 &b1)
// {
//   SVector3 t0 = crossprod(n0, o0);
//   SVector3 t1 = crossprod(n1, o1);
//   t0.normalize();
//   t1.normalize();
//   std::vector<SVector3> A(Ns);
//   std::vector<SVector3> B(Ns);
//   for (int i = 0; i < Ns; ++i) {
//     double agl = double(i)/double(Ns) * 2. * M_PI;
//     A[i] = o0 * cos(agl) + t0 * sin(agl);
//     B[i] = o1 * cos(agl) + t1 * sin(agl);
//   }
//   double maxx = -1;
//   size_t is = 0;
//   size_t js = 0;
//   for (int i = 0; i < Ns; ++i) {
//     for (int j = 0; j < Ns; ++j) {
//       const double xx = dot(A[i], B[j]);
//       if(xx > maxx) {
//         is = i;
//         js = j;
//         maxx = xx;
//       }
//     }
//   }
//   a1 = A[is];
//   b1 = B[js];
//   return maxx;
// }
//
// inline void cross_normalize(int Ns, double &a)
// {
//   double D = 2. * M_PI / double(Ns);
//   if(a < 0)
//     while(a < 0) a += D;
//   if(a >= D)
//     while(a >= D) a -= D;
// }
//
// inline double cross_lifting(int Ns, double _a, double a)
// {
//   double D = 2. * M_PI / double(Ns);
//   if(fabs(_a - a) < fabs(_a - (a + D)) && fabs(_a - a) < fabs(_a - (a - D)))
//   {
//     return a;
//   }
//   else if(fabs(_a - (a + D)) < fabs(_a - a) &&
//       fabs(_a - (a + D)) < fabs(_a - (a - D))) {
//     return a + D;
//   }
//   else {
//     return a - D;
//   }
//   return DBL_MAX;
// }

inline double compat_orientation_extrinsic(int Ns, const SVector3 &o0,
                                           const SVector3 &n0,
                                           const SVector3 &o1,
                                           const SVector3 &n1, SVector3 &a1,
                                           SVector3 &b1)
{
  if(Ns != 4) return DBL_MAX;

  SVector3 t0 = crossprod(n0, o0);
  SVector3 t1 = crossprod(n1, o1);

  const size_t permuts[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0},
                                {0, 1}, {1, 1}, {2, 1}, {3, 1}};
  SVector3 A[4]{o0, t0, -o0, -t0};
  SVector3 B[2]{o1, t1};

  double maxx = -1;
  int index = 0;
  for(size_t i = 0; i < 8; i++) {
    const double xx = dot(A[permuts[i][0]], B[permuts[i][1]]);
    if(xx > maxx) {
      index = i;
      maxx = xx;
    }
  }
  a1 = A[permuts[index][0]];
  b1 = B[permuts[index][1]];
  return maxx;
}

inline void cross_normalize(int Ns, double &a)
{
  if(Ns != 4) {
    a = DBL_MAX;
    return;
  }
  double D = M_PI * .5;
  if(a < 0)
    while(a < 0) a += D;
  if(a >= D)
    while(a >= D) a -= D;
}

inline double cross_lifting(int Ns, double _a, double a)
{
  if(Ns != 4) return DBL_MAX;
  double D = M_PI * .5;
  if(fabs(_a - a) < fabs(_a - (a + D)) && fabs(_a - a) < fabs(_a - (a - D))) {
    return a;
  }
  else if(fabs(_a - (a + D)) < fabs(_a - a) &&
          fabs(_a - (a + D)) < fabs(_a - (a - D))) {
    return a + D;
  }
  else {
    return a - D;
  }
  return DBL_MAX;
}

int computeCrossFieldConformalScaling(
  int Ns, const std::vector<MTriangle *> &triangles,
  const std::vector<std::array<double, 3> > &triEdgeTheta,
  std::unordered_map<MVertex *, double> &scaling)
{
#if defined(HAVE_SOLVER)
  Msg::Debug("compute cross field scaling (N=%i, %li triangles) ...", Ns,
             triangles.size());
  if(triangles.size() != triEdgeTheta.size()) {
    Msg::Error("conformal scaling: incoherent number of elements in inputs");
    return -1;
  }

#if defined(HAVE_EIGEN)
  Msg::Debug("- with EIGEN solver");
  linearSystemEigen<double> *_lsys = new linearSystemEigen<double>;
#elif defined(HAVE_PETSC)
  Msg::Debug("- with PETSc solver");
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_MUMPS)
  Msg::Debug("- with MUMPS solver");
  linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
#else
  Msg::Debug("- with dense solver (slow, should not be used)");
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif
  dofManager<double> *myAssembler = new dofManager<double>(_lsys);

  /* Vertex unknowns */
  std::set<MVertex *, MVertexPtrLessThan> vs;
  for(MTriangle *t : triangles) {
    for(size_t k = 0; k < 3; k++) { vs.insert(t->getVertex(k)); }
  }
  for(MVertex *v : vs) myAssembler->numberVertex(v, 0, 1);

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(0, 1, &ONE);

  /* Collect gradient of theta (cross field directions) */
  std::map<MTriangle *, SVector3> gradients_of_theta;
  for(size_t i = 0; i < triangles.size(); ++i) {
    MTriangle *t = triangles[i];

    SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
                 t->getVertex(1)->y() - t->getVertex(0)->y(),
                 t->getVertex(1)->z() - t->getVertex(0)->z());
    SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
                 t->getVertex(2)->y() - t->getVertex(0)->y(),
                 t->getVertex(2)->z() - t->getVertex(0)->z());
    SVector3 normal_to_triangle = crossprod(v20, v10);
    normal_to_triangle.normalize();

    SElement se(t);
    l.addToMatrix(*myAssembler, &se);

    SVector3 t_i, o_i, o_1, o_2, tgt0;
    for(size_t le = 0; le < 3; ++le) {
      /* Edge ordered lower index to largest */
      std::array<MVertex *, 2> edge = {t->getVertex(le),
                                       t->getVertex((le + 1) % 3)};
      if(edge[0]->getNum() > edge[1]->getNum())
        std::reverse(edge.begin(), edge.end());

      /* Edge tangent */
      SVector3 tgt = edge[1]->point() - edge[0]->point();
      if(tgt.norm() < 1.e-16) {
        Msg::Warning("Edge (tri=%i,le=%i), length = %.e", t->getNum(), le,
                     tgt.norm());
        if(tgt.norm() == 0.) { return -1; }
      }
      tgt.normalize();
      SVector3 tgt2 = crossprod(normal_to_triangle, tgt);
      tgt2.normalize();

      /* Cross angle  (from Crouzeix-Raviart cross field) */
      double A = triEdgeTheta[i][le];

      SVector3 o = tgt * cos(A) + tgt2 * sin(A);
      o.normalize();
      o -= normal_to_triangle * dot(normal_to_triangle, o_i);
      o.normalize();

      if(le == 0) {
        t_i = crossprod(normal_to_triangle, tgt);
        t_i -= normal_to_triangle * dot(normal_to_triangle, t_i);
        t_i.normalize();
        o_i = o;
        tgt0 = tgt;
      }
      else if(le == 1) {
        o_1 = o;
      }
      else if(le == 2) {
        o_2 = o;
      }
    }

    SVector3 x0, x1, x2, x3;
    compat_orientation_extrinsic(Ns, o_i, normal_to_triangle, o_1,
                                 normal_to_triangle, x0, x1);
    compat_orientation_extrinsic(Ns, o_i, normal_to_triangle, o_2,
                                 normal_to_triangle, x2, x3);

    double a0 = atan2(dot(t_i, o_i), dot(tgt0, o_i));

    x0 -= normal_to_triangle * dot(normal_to_triangle, x0);
    x0.normalize();
    x1 -= normal_to_triangle * dot(normal_to_triangle, x1);
    x1.normalize();
    x2 -= normal_to_triangle * dot(normal_to_triangle, x2);
    x2.normalize();
    x3 -= normal_to_triangle * dot(normal_to_triangle, x3);
    x3.normalize();

    cross_normalize(Ns, a0);
    double A1 = atan2(dot(t_i, x1), dot(tgt0, x1));
    double A2 = atan2(dot(t_i, x3), dot(tgt0, x3));
    cross_normalize(Ns, A1);
    double a1 = cross_lifting(Ns, a0, A1);
    cross_normalize(Ns, A2);
    double a2 = cross_lifting(Ns, a0, A2);

    double a[3] = {a0 + a2 - a1, a0 + a1 - a2, a1 + a2 - a0};
    double g[3] = {0, 0, 0};
    t->interpolateGrad(a, 0, 0, 0, g);
    gradients_of_theta[t] = SVector3(g[0], g[1], g[2]);
    SPoint3 pp = t->barycenter();

    SVector3 G(g[0], g[1], g[2]);
    SVector3 GT = crossprod(G, normal_to_triangle);

    double g1[3];
    a[0] = 1;
    a[1] = 0;
    a[2] = 0;
    t->interpolateGrad(a, 0, 0, 0, g1);
    double RHS1 = g1[0] * GT.x() + g1[1] * GT.y() + g1[2] * GT.z();
    a[0] = 0;
    a[1] = 1;
    a[2] = 0;
    t->interpolateGrad(a, 0, 0, 0, g1);
    double RHS2 = g1[0] * GT.x() + g1[1] * GT.y() + g1[2] * GT.z();
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    t->interpolateGrad(a, 0, 0, 0, g1);
    double RHS3 = g1[0] * GT.x() + g1[1] * GT.y() + g1[2] * GT.z();
    int num1 = myAssembler->getDofNumber(l.getLocalDofR(&se, 0));
    int num2 = myAssembler->getDofNumber(l.getLocalDofR(&se, 1));
    int num3 = myAssembler->getDofNumber(l.getLocalDofR(&se, 2));
    double V = -t->getVolume();
    _lsys->addToRightHandSide(num1, RHS1 * V);
    _lsys->addToRightHandSide(num2, RHS2 * V);
    _lsys->addToRightHandSide(num3, RHS3 * V);
  }

  int status = _lsys->systemSolve();

  if(status == -1) { /* failed to solve */
    Msg::Warning("conformal scaling (%li triangles, %li variables), failed to "
                 "solve linear system, use uniform scaling",
                 triangles.size(), vs.size());
    for(MVertex *v : vs) { scaling[v] = 1.; }
    delete _lsys;
    delete myAssembler;
    return 0;
  }

  /* Extract solution */
  double sMin = DBL_MAX;
  double sMax = -DBL_MAX;
  size_t i = 0;
  for(MVertex *v : vs) {
    double h;
    myAssembler->getDofValue(v, 0, 1, h);
    double cs = exp(-h);
    scaling[v] = cs;
    sMin = std::min(sMin, cs);
    sMax = std::max(sMax, cs);
    i += 1;
  }
  if(sMin == DBL_MAX || sMax == -DBL_MAX || sMin == 0.) {
    Msg::Warning("Conformal scaling computed (%d unknowns, %li triangles -> "
                 "min=%.3f, max=%.3f), wrong, use uniform scaling",
                 myAssembler->sizeOfR(), triangles.size(), sMin, sMax);
    for(MVertex *v : vs) { scaling[v] = 1.; }
    delete _lsys;
    return 0;
  }
  else {
    Msg::Debug("Conformal scaling computed (%d unknowns, %li triangles -> "
               "min=%.3f, max=%.3f, width=%.3f)",
               myAssembler->sizeOfR(), triangles.size(), sMin, sMax,
               sMax - sMin);
  }

  delete _lsys;
  delete myAssembler;

  if(false) {
    std::vector<MElement *> elts =
      dynamic_cast_vector<MTriangle *, MElement *>(triangles);
    GeoLog::add(elts, scaling, "h=exp(-H)");
    GeoLog::flush();
  }

#else
  Msg::Error("Computing cross field scaling requires the SOLVER module");
  return -1;
#endif

  return 0;
}

int computeQuadSizeMapFromCrossFieldConformalFactor(
  const std::vector<MTriangle *> &triangles, std::size_t targetNumberOfQuads,
  std::unordered_map<MVertex *, double> &scaling)
{
  Msg::Debug("Offset quad size map from cross field conformal factor to target "
             "%li quads ...",
             targetNumberOfQuads);

  if(targetNumberOfQuads == 0) {
    Msg::Error("targetNumberOfQuads: %i should be positive",
               targetNumberOfQuads);
    return -1;
  }

  double csMin = DBL_MAX;
  double csMax = -DBL_MAX;
  double Hmin = DBL_MAX;
  double Hmax = -DBL_MAX;
  size_t nWoCorner = 0;
  for(MTriangle *t : triangles) {
    for(size_t lv = 0; lv < 3; ++lv) {
      MVertex *v = t->getVertex(lv);
      auto it = scaling.find(v);
      if(it == scaling.end()) {
        Msg::Error("scaling not found for vertex %i", v->getNum());
        return -1;
      }
      GVertex *gv = v->onWhat()->cast2Vertex();
      if(gv != nullptr) continue; /* Remove corner values from range */
      csMin = std::min(csMin, it->second);
      csMax = std::max(csMax, it->second);
      nWoCorner += 1;
    }
  }

  if(nWoCorner > 0 && (csMin == DBL_MAX || csMax == -DBL_MAX)) {
    Msg::Warning("conformal scaling is wrong, %li values, min=DBL_MAX or "
                 "max=-DBL_MAX, filling with unit values",
                 scaling.size(), csMin, csMax);
    for(MTriangle *t : triangles) {
      for(size_t lv = 0; lv < 3; ++lv) {
        MVertex *v = t->getVertex(lv);
        scaling[v] = 1.;
      }
    }
  }

  /* Compute integral of current size map */
  double integral = 0.;
  double smin = DBL_MAX;
  double smax = -DBL_MAX;
  std::vector<MVertex *> vertices;
  vertices.reserve(3 * triangles.size());
  for(MTriangle *t : triangles) {
    double values[3] = {0, 0, 0};
    for(size_t lv = 0; lv < 3; ++lv) {
      MVertex *v = t->getVertex(lv);
      auto it = scaling.find(v);
      if(it == scaling.end()) {
        Msg::Error("scaling value not found for v=%li", v->getNum());
        return -1;
      }
      /* Clamp with range without corners */
      if(nWoCorner > 0 && (it->second < csMin || it->second > csMax)) {
        it->second = clamp(it->second, csMin, csMax);
      }
      values[lv] = it->second;
      smin = std::min(smin, values[lv]);
      smax = std::max(smax, values[lv]);
      vertices.push_back(v);
    }
    double a = std::abs(t->getVolume());
    double avg = 1. / 3. * (values[0] + values[1] + values[2]);
    if(avg == 0.) continue;
    integral += a * 1. / std::pow(avg, 2);
  }

  if(integral == 0.) {
    Msg::Warning("Size map from conformal scaling: total integral is 0 ... "
                 "(%li triangles, smin=%.3e, smax=%.3e)",
                 triangles.size(), smin, smax);
    return -1;
  }
  Msg::Debug("- %li triangles, conformal scaling: min=%.3e, max=%.3e, #=%.3e",
             triangles.size(), smin, smax, integral);
  std::sort(vertices.begin(), vertices.end());
  vertices.erase(std::unique(vertices.begin(), vertices.end()), vertices.end());

  /* Apply the scaling */
  double target = double(targetNumberOfQuads);
  double FAC = double(target) / integral;
  double sf = 1. / std::sqrt(FAC);
  smin = DBL_MAX;
  smax = -DBL_MAX;
  for(size_t j = 0; j < vertices.size(); ++j) {
    MVertex *v = vertices[j];
    auto it = scaling.find(v);
    it->second = sf * it->second;
    smin = std::min(smin, it->second);
    smax = std::max(smax, it->second);
  }
  Msg::Debug(
    "- %li triangles, sizemap range: [%.3e, %.3e] (factor applied: %3f)",
    triangles.size(), smin, smax, FAC);

  return 0;
}

int convertToPerTriangleCrossFieldDirections(
  int Ns, const std::vector<MTriangle *> &triangles,
  const std::vector<std::array<double, 3> > &triEdgeTheta,
  std::vector<std::array<double, 9> > &triangleDirections)
{
  triangleDirections.resize(triangles.size());

  for(size_t f = 0; f < triangles.size(); ++f) {
    MTriangle *t = triangles[f];

    SVector3 N = QMT::tri_normal(t);

    /* Compute one branch at triangle vertices */
    SVector3 refCross = {0., 0., 0.};
    SVector3 avgCross = {0., 0., 0.};
    SVector3 lifted_dirs[3];
    for(size_t le = 0; le < 3; ++le) {
      /* Get cross angle */
      std::array<MVertex *, 2> edge = {t->getVertex(le),
                                       t->getVertex((le + 1) % 3)};
      if(edge[0]->getNum() > edge[1]->getNum())
        std::reverse(edge.begin(), edge.end());

      double A = triEdgeTheta[f][le];

      /* Local reference frame */
      SVector3 tgt = edge[1]->point() - edge[0]->point();
      if(tgt.norm() < 1.e-16) {
        Msg::Warning("Edge (tri=%i,le=%i), length = %.e", t->getNum(), le,
                     tgt.norm());
        if(tgt.norm() == 0.) { return -1; }
      }
      tgt.normalize();
      SVector3 tgt2 = crossprod(N, tgt);
      tgt2.normalize();

      SVector3 cross1 = tgt * cos(A) + tgt2 * sin(A);
      cross1.normalize();

      SVector3 cross2 = crossprod(N, cross1);
      cross2.normalize();

      if(le == 0) {
        refCross = cross1;
        avgCross = avgCross + cross1;
        lifted_dirs[le] = refCross;
      }
      else {
        SVector3 closest = {0., 0., 0.};
        double dotmax = -DBL_MAX;
        for(int k = 0; k < Ns; ++k) {
          double agl = A + double(k) / double(Ns) * 2. * M_PI;
          SVector3 candidate = tgt * cos(agl) + tgt2 * sin(agl);
          candidate.normalize();
          if(dot(candidate, refCross) > dotmax) {
            closest = candidate;
            dotmax = dot(candidate, refCross);
          }
        }
        // SVector3 candidates[4] = {cross1,-1.*cross1,cross2,-1.*cross2};
        // SVector3 closest = {0.,0.,0.};
        // double dotmax = -DBL_MAX;
        // for (size_t k = 0; k < 4; ++k) {
        //   if (dot(candidates[k],refCross) > dotmax) {
        //     closest = candidates[k];
        //     dotmax = dot(candidates[k],refCross);
        //   }
        // }
        lifted_dirs[le] = closest;
        avgCross = avgCross + closest;
      }
    }
    SVector3 vertex_dirs[3];
    std::array<double, 9> tDirs;
    for(size_t lv = 0; lv < 3; ++lv) {
      SVector3 lambda = {0., 0., 0.};
      lambda[lv] = 1.;
      SVector3 dir = QMT::crouzeix_raviart_interpolation(lambda, lifted_dirs);
      if(length2(dir) != 0.) dir.normalize();
      for(size_t d = 0; d < 3; ++d) { tDirs[3 * lv + d] = dir.data()[d]; }
    }
    triangleDirections[f] = tDirs;
  }

  return 0;
}

inline double angle2PI(const SVector3 &u, const SVector3 &v, const SVector3 &n)
{
  const double dp = dot(u, v);
  const double tp = dot(n, crossprod(u, v));
  double angle = atan2(tp, dp);
  if(angle < 0) angle += 2. * M_PI;
  return angle;
}

int detectCrossFieldSingularities(
  int Ns, const std::vector<MTriangle *> &triangles,
  const std::vector<std::array<double, 3> > &triEdgeTheta,
  bool addSingularitiesAtAcuteCorners, double thresholdInDeg,
  std::vector<std::pair<SPoint3, int> > &singularities)
{
  singularities.clear();
  if(triangles.size() != triEdgeTheta.size()) {
    Msg::Error("detect cross field singularities: wrong inputs");
    return -1;
  }

  /* Get interior vertices and adjacent triangles */
  unordered_map<MVertex *, vector<MTriangle *> > v2t;

  /* put edge angles here, maybe a bit slow ... */
  unordered_map<MEdge, double, MEdgeHash, MEdgeEqual> edgeTheta;

  for(size_t i = 0; i < triangles.size(); ++i) {
    MTriangle *t = triangles[i];
    for(size_t le = 0; le < 3; ++le) {
      MVertex *v1 = t->getVertex(le);
      MVertex *v2 = t->getVertex((le + 1) % 3);

      MEdge edg(v1, v2);
      edgeTheta[edg] = triEdgeTheta[i][le];

      GFace *gf = dynamic_cast<GFace *>(v1->onWhat());
      if(gf == nullptr) continue;
      v2t[v1].push_back(t);
    }
  }

  /* Compute index at each vertex (looking on the one rings) */
  unordered_map<MVertex *, int> vertexIndex;
  for(auto &kv : v2t) {
    MVertex *v = kv.first;
    const vector<MTriangle *> &tris = kv.second;

    SVector3 e_x, e_y, N;
    int st = QMT::local_frame(v, tris, e_x, e_y, N);
    if(st != 0) {
      Msg::Error("no local frame for v=%li", v->getNum());
      continue;
    }

    std::vector<std::array<MVertex *, 2> > vPairs;
    int st2 = QMT::ordered_fan_around_vertex(v, tris, vPairs);
    if(st2 != 0) {
      Msg::Error("no ordered fan around v=%li", v->getNum());
      continue;
    }

    double angle_deficit = 2. * M_PI;
    std::vector<SVector3> rep_vectors(
      vPairs.size()); /* cross field representation vector in local frame
                         (+e_x,+e_y) */
    for(size_t j = 0; j < vPairs.size(); ++j) {
      MVertex *v1 = vPairs[j][0];
      MVertex *v2 = vPairs[j][1];
      angle_deficit -= angle3Vertices(v1, v, v2); /* gaussian curvature */

      SVector3 tgt;
      if(v1->getNum() < v2->getNum()) { tgt = v2->point() - v1->point(); }
      else {
        tgt = v1->point() - v2->point();
      }
      tgt.normalize();
      SVector3 tgt2 = crossprod(N, tgt);
      tgt2.normalize();
      std::array<size_t, 2> vPair = {v1->getNum(), v2->getNum()};
      if(vPair[1] < vPair[0]) vPair = {v2->getNum(), v1->getNum()};
      MEdge query(v1, v2);
      auto it = edgeTheta.find(query);
      if(it == edgeTheta.end()) {
        Msg::Error("Edge (%li,%li) not found in edgeTheta", vPair[0], vPair[1]);
        return -1;
      }
      double A = it->second;

      SVector3 branchInQuadrant;
      bool found = false;
      double dpmax = -DBL_MAX;
      size_t kmax = (size_t)-1;
      for(size_t k = 0; k < Ns; ++k) { /* Loop over branches */
        double agl = A + double(k) / double(Ns) * 2. * M_PI;
        SVector3 branch = tgt * cos(agl) + tgt2 * sin(agl);
        if(dot(branch, e_x) >= 0. && dot(branch, e_y) >= 0.) {
          branchInQuadrant = branch;
          found = true;
          break;
        }
        double dp = dot(branch, SVector3(std::sqrt(2), std::sqrt(2), 0.));
        if(dp > dpmax) {
          dpmax = dp;
          kmax = k;
        }
      }
      if(!found && kmax != (size_t)-1) { /* if numerical errors */
        double agl = A + double(kmax) / double(Ns) * 2. * M_PI;
        branchInQuadrant = tgt * cos(agl) + tgt2 * sin(agl);
      }

      double theta = acos(dot(branchInQuadrant, e_x));
      rep_vectors[j] = {cos(double(Ns) * theta), sin(double(Ns) * theta), 0.};
    }
    double sum_diff = 0.;
    for(size_t j = 0; j < vPairs.size(); ++j) {
      SVector3 vertical(0., 0., 1.);
      const SVector3 r1 = rep_vectors[j];
      const SVector3 r2 = rep_vectors[(j + 1) % rep_vectors.size()];
      double diff_angle = angle2PI(r1, r2, vertical);
      if(diff_angle > M_PI) diff_angle -= 2. * M_PI;
      sum_diff += diff_angle;
    }
    if(std::abs(sum_diff - 2 * M_PI) < 0.05 * M_PI) { vertexIndex[v] = -1; }
    else if(std::abs(sum_diff + 2 * M_PI) < 0.05 * M_PI) {
      vertexIndex[v] = 1;
    }
    else if(std::abs(sum_diff) > 0.05 * M_PI) {
      Msg::Debug(
        "singularity detection, v=%i, sum of diff is %.3f deg, ignored",
        v->getNum(), sum_diff);
    }
  }

  /* Three types of singularities with Crouzeix-Raviart interpolation:
   * - on vertex
   * - on edge
   * - on triangle */

  /* triangle singularities */
  for(MTriangle *t : triangles) {
    MVertex *v1 = t->getVertex(0);
    MVertex *v2 = t->getVertex(1);
    MVertex *v3 = t->getVertex(2);
    for(double index : {-1., 1.}) {
      if(vertexIndex[v1] == index && vertexIndex[v2] == index &&
         vertexIndex[v3] == index) {
        SPoint3 p = (v1->point() + v2->point() + v3->point()) * double(1. / 3.);
        singularities.push_back({p, index});
        /* remove from list of available singularities */
        vertexIndex[v1] = 0.;
        vertexIndex[v2] = 0.;
        vertexIndex[v3] = 0.;
      }
    }
  }
  /* edge singularities */
  for(MTriangle *t : triangles) {
    for(size_t le = 0; le < 3; ++le) {
      MVertex *v1 = t->getVertex(le);
      MVertex *v2 = t->getVertex((le + 1) % 3);
      for(double index : {-1., 1.}) {
        if(vertexIndex[v1] == index && vertexIndex[v2] == index) {
          SPoint3 p = (v1->point() + v2->point()) * 0.5;
          singularities.push_back({p, index});
          /* remove from list of available singularities */
          vertexIndex[v1] = 0.;
          vertexIndex[v2] = 0.;
        }
      }
    }
  }
  /* vertex singularities */
  for(auto &kv : vertexIndex)
    if(kv.second != 0) {
      singularities.push_back({kv.first->point(), kv.second});
    }

  Msg::Debug(
    "detect cross field singularities: found %li singularities (%li triangles)",
    singularities.size(), triangles.size());

  if(addSingularitiesAtAcuteCorners) {
    size_t nb = singularities.size();
    unordered_map<MVertex *, double> cornerAngle;
    unordered_map<MVertex *, std::vector<MTriangle *> > cornerToTris;
    for(MTriangle *t : triangles) {
      for(size_t le = 0; le < 3; ++le) {
        MVertex *v2 = t->getVertex((le + 1) % 3);
        if(v2->onWhat()->cast2Vertex() != NULL) {
          MVertex *v1 = t->getVertex(le);
          MVertex *v3 = t->getVertex((le + 2) % 3);
          double agl = std::abs(angle3Vertices(v1, v2, v3));
          cornerAngle[v2] += agl;
          cornerToTris[v2].push_back(t);
        }
      }
    }
    for(const auto &kv : cornerAngle) {
      MVertex *v = kv.first;
      double agl = kv.second;
      if(agl * 180. / M_PI < thresholdInDeg) {
        std::vector<MTriangle *> &tris = cornerToTris[v];
        if(tris.size() == 0) continue;
        SPoint3 p(0., 0., 0.);
        for(MTriangle *t : tris) { p += t->barycenter(); }
        p = p * double(1. / double(tris.size()));
        singularities.push_back({p, 1});
      }
    }
    if(singularities.size() > nb) {
      Msg::Debug("detect cross field singularities: added %li artificial "
                 "singularities at acute corners",
                 singularities.size() - nb);
    }
  }

  return 0;
}
