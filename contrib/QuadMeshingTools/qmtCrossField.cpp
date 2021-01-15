// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtCrossField.h"

/* System includes */
#include <vector>
#include <array>
#include <unordered_map>
#include <cstdint>
#include <math.h>
#include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"

/* Direct linear solver */
#if defined(HAVE_EIGEN)
  #include<Eigen/IterativeLinearSolvers>
  #include<Eigen/SparseCholesky>
  #include<Eigen/SparseLU>
#endif

/* QuadMeshingTools includes */
#include "arrayGeometry.h"
#include "cppUtils.h"


/* TODO list:
 * - Cross field smoother with a single Laplacian solve
 * - Cross field smoother with a single factorization
 */

namespace QMT {
  using namespace ArrayGeometry;
  using namespace CppUtils;

  constexpr double EPS = 1.e-14;

  using std::vector;
  using std::unordered_map;
  using std::array;
  using std::pair;
  using id   = uint32_t;
  using sid  = int64_t;
  using id2  = std::array<id,2>;
  using id3  = std::array<id,3>;
  using sid3 = std::array<sid,3>;
  constexpr id   NO_ID  = (id) -1;
  constexpr sid  NO_SID = (sid) NO_ID;

  struct IJV {
    id2 ij;
    double val;
    bool operator<(const IJV& b) const { return ij[0] < b.ij[0] || (ij[0] == b.ij[0] && ij[1] < b.ij[1]); }
  };

  struct IV {
    id i;
    double val;
    bool operator<(const IV& b) const { return i < b.i; }
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
    CrossFieldLinearSystem(size_t N_):N(N_) {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: initialize sparse matrix, vectors and solver");
      x.resize(N);
      x.fill(0.);
      b.resize(N);
      b.fill(0.);
      A.resize(N,N);
#else
      Msg::Error("Linear solver Eigen required");
#endif
    }

    bool add_sparse_coefficients(
        const std::vector<std::vector<size_t>>& columns,
        const std::vector<std::vector<double>>& values,
        bool firstTime = false) {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: add coefficients");
      std::vector<Eigen::Triplet<double> > triplets;
      triplets.reserve(values.size());
      if (firstTime) {
        for (size_t i = 0; i < columns.size(); ++i) {
          for (size_t k = 0; k < columns[i].size(); ++k) {
            size_t j = columns[i][k];
            double val = values[i][k];
            triplets.push_back({i,j,val});
          }
        }
        A.setFromTriplets(triplets.begin(),triplets.end());
      } else {
        for (size_t i = 0; i < columns.size(); ++i) {
          for (size_t k = 0; k < columns[i].size(); ++k) {
            size_t j = columns[i][k];
            double val = values[i][k];
            A.coeffRef(i,j) += val; /* entry (i,j) should already exists */
          }
        }
      }
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool set_rhs_values(const std::vector<double>& rhs) {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: add rhs values");
      for (size_t i = 0; i < rhs.size(); ++i) if (rhs[i] != 0.) {
        b[i] = rhs[i];
      }
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool preprocess_sparsity_pattern() {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: analyse sparse matrix sparsity pattern");
      solver.analyzePattern(A);
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool factorize() {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: factorize sparse matrix");
      solver.factorize(A);
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

    bool solve(std::vector<double>& slt) {
#if defined(HAVE_EIGEN)
      Msg::Debug("Eigen call: solve linear system");
      x = solver.solve(b);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("Eigen: failed to solve linear system with SparseLU (%li variables)", N);
        return false;
      }
      slt.resize(x.size());
      for (size_t i = 0; i < N; ++i) slt[i] = x[i];
      return true;
#else
      Msg::Error("Linear solver Eigen required");
      return false;
#endif
    }

  };


  bool compute_triangle_adjacencies(
      const vector<id3>& triangles,
      vector<sid3>& triangle_neighbors,
      vector<vector<id>>& nm_triangle_neighbors,
      vector<id2>& uIEdges,
      vector<id>& old2IEdge,
      vector<vector<id>>& uIEdgeToOld
      ) {
    triangle_neighbors.clear();
    triangle_neighbors.resize(triangles.size(),{NO_ID,NO_ID,NO_ID});
    nm_triangle_neighbors.clear();

    constexpr size_t NBF = 3;

    /* Store element 'faces', with duplicates for further 'equality test' */
    std::vector<id2> faces;
    for (size_t i = 0; i < triangles.size(); ++i) {
      for (size_t lf = 0; lf < NBF; ++lf) {
        id2 face = {triangles[i][lf],triangles[i][(lf+1)%NBF]};
        std::sort(face.begin(),face.end());
        faces.push_back(face);
      }
    }

    /* Reduce 'duplicated faces' to 'unique faces', keeping the 'old2new' mapping */
    size_t nbUniques = sort_unique_with_perm(faces, uIEdges, old2IEdge);

    /* Build the 'unique face to elements' mapping */
    uIEdgeToOld.resize(nbUniques);
    for (size_t i = 0; i < triangles.size(); ++i) {
      for (size_t lf = 0; lf < NBF; ++lf) {
        id facePos = NBF*i+lf;
        uIEdgeToOld[old2IEdge[facePos]].push_back(facePos);
      }
    }

    /* Loop over 'unique face to elements' and set the element adjacencies */
    constexpr id2 NO_FACE = {NO_ID,NO_ID};
    for (size_t i = 0; i < nbUniques; ++i) {
      if (uIEdges[i] == NO_FACE) continue;
      if(uIEdges[i][0] == NO_ID) return false;
      if(uIEdges[i][1] == NO_ID) return false;
      if (uIEdgeToOld[i].size() == 1) { /* boundary */
        id eltId = uIEdgeToOld[i][0] / NBF;
        id lf = uIEdgeToOld[i][0] % NBF;
        triangle_neighbors[eltId][lf] = NO_ID;
      } else if (uIEdgeToOld[i].size() == 2) { /* regular face */
        id e1 = uIEdgeToOld[i][0] / NBF;
        id lf1 = uIEdgeToOld[i][0] % NBF;
        id e2 = uIEdgeToOld[i][1] / NBF;
        id lf2 = uIEdgeToOld[i][1] % NBF;
        triangle_neighbors[e1][lf1] = NBF*e2+lf2;
        triangle_neighbors[e2][lf2] = NBF*e1+lf1;
      } else if (uIEdgeToOld[i].size() > 2) { /* non manifold face */
        for (size_t j = 0; j < uIEdgeToOld[i].size(); ++j) {
          id e = uIEdgeToOld[i][j] / NBF;
          id lf = uIEdgeToOld[i][j] % NBF;
          std::vector<id> neighs;
          for (size_t k = 0; k < uIEdgeToOld[i].size(); ++k) {
            if (uIEdgeToOld[i][k] != uIEdgeToOld[i][j]) {
              neighs.push_back(uIEdgeToOld[i][k]);
            }
          }
          neighs.shrink_to_fit();
          id pos = nm_triangle_neighbors.size();
          nm_triangle_neighbors.push_back(neighs);
          triangle_neighbors[e][lf] = -((sid) pos + 1);
        }
      }
    }

    /* Reduce memory consumption */
    triangle_neighbors.shrink_to_fit();
    nm_triangle_neighbors.shrink_to_fit();

    return true;
  }

  /* two unknowns (x_2i, x_2i+1) for each edge */
  bool stiffness_coefficient(
      const std::vector<std::array<double,3> >& points,
      const std::vector<std::array<id,3> >& triangles,
      id e, 
      const vector<id2>& uIEdges,
      const vector<id>& old2IEdge,
      const vector<vector<id>>& uIEdgeToOld,
      vector<IV>& iv,
      vector<IJV>& ijv) {
    if (uIEdgeToOld[e].size() != 2) {
      Msg::Error("assembly, edge %li: uIEdgeToOld[e].size() = %li", e, uIEdgeToOld[e].size());
      return false;
    }
    /* edge vertices */
    id v1 = uIEdges[e][0];
    id v2 = uIEdges[e][1];
    vec3 e_x = points[v2] - points[v1];
    double lenr = length(e_x);
    if (lenr < EPS) {
      Msg::Error("edge too small: v1=%li, v2=%li, length = %e", v1, v2, lenr);
      return false;
    }
    e_x = (1./lenr) * e_x;
    /* four neighbor edges */
    id bvars[4] = {NO_ID,NO_ID,NO_ID,NO_ID};
    double alpha[4] = {0.,0.,0.,0.};
    double CR_weight[4] = {-1./4,-1./4,-1./4,-1./4};
    vec3 prevN;
    for (size_t s = 0; s < 2; ++s) { /* two triangles */
      id oe = uIEdgeToOld[e][s];
      id t = oe / 3;
      id le = oe % 3;
      vec3 N = triangleNormal(points[triangles[t][0]],points[triangles[t][1]],points[triangles[t][2]]);
      if (s == 1 && dot(prevN,N) < 0.)  N = -1. * N;
      prevN = N;
      // N = {0,0,1};
      vec3 e_y = cross(N,e_x);
      if (maxAbs(e_y) == 0.) {
        Msg::Error("length(e_y) = {}", length(e_y));
        return false;
      }
      normalize(e_y);

      for (size_t k = 0; k < 2; ++k) { /* two other edges in triangle t */
        id aoe = 3*t+(le+1+k)%3;
        id ae = old2IEdge[aoe];
        id2 aedge = uIEdges[ae];

        bvars[2*s+k] = ae;
        vec3 edg = points[aedge[1]]-points[aedge[0]];
        double len = length(edg);
        if (len < EPS) {
          Msg::Error("edge too small: t=%li, k = %li, edge=%li, length = %e", t, k, aedge, len);
          return false;
        }
        edg = (1./len) * edg;

        /* 360deg angle (used for the angle rotation) */
        double cx = dot(edg,e_x);
        double cy = dot(edg,e_y);
        alpha[2*s+k] = atan2(cy,cx);
        if (alpha[2*s+k] < 0.) alpha[2*s+k] += 2.*M_PI;

        /* 180deg edge-edge angle (used for the Crouzeix Raviart) */
        double agl = 0.;
        if (aedge[0] == v1) {
          agl = angleVectorsAlreadyNormalized(edg,e_x);
        } else if (aedge[1] == v1) {
          agl = angleVectorsAlreadyNormalized(edg, -1. * e_x);
        } else if (aedge[0] == v2) {
          agl = angleVectorsAlreadyNormalized(-1. * edg, e_x);
        } else if (aedge[1] == v2) {
          agl = angleVectorsAlreadyNormalized(-1. * edg, -1. * e_x);
        } else {
          Msg::Error("should not happen");
          return false;
        }
        CR_weight[2*s+k] = -2. / tan(agl);
      }
    }
    /* compute coefficients */
    double isum = -1. * (CR_weight[0] + CR_weight[1] + CR_weight[2] + CR_weight[3]);
    for (size_t k = 0; k < 4; ++k)
      CR_weight[k] = CR_weight[k] / isum;

    iv.clear();
    ijv.clear();
    id x_i = 2*e;
    id y_i = 2*e+1;
    iv.push_back({x_i,1.});
    iv.push_back({y_i,1.});
    for (size_t j = 0; j < 4; ++j) {
      id x_j = 2*bvars[j];
      id y_j = 2*bvars[j]+1;
      ijv.push_back({{x_i,x_j},CR_weight[j]    *cos(4.*alpha[j])});
      ijv.push_back({{x_i,y_j},CR_weight[j]*-1.*sin(4.*alpha[j])});
      ijv.push_back({{y_i,x_j},CR_weight[j]    *sin(4.*alpha[j])});
      ijv.push_back({{y_i,y_j},CR_weight[j]    *cos(4.*alpha[j])});
    }

    return true;
  }

  bool prepare_system(
      const vector<IV>& K_diag,
      const vector<IJV>& K_coefs,
      vector<vector<size_t>>& columns,
      vector<vector<double>>& values) {
    vector<IJV> coefs = K_coefs;
    coefs.resize(coefs.size()+K_diag.size());
    for (size_t i = 0; i < K_diag.size(); ++i) {
      coefs[K_coefs.size()+i] = {{id(K_diag[i].i),id(K_diag[i].i)},K_diag[i].val};
    }
    std::sort(coefs.begin(),coefs.end());

    size_t cur_i = coefs[0].ij[0];
    size_t cur_j = coefs[0].ij[1];
    double acc_val = coefs[0].val;
    for (size_t k = 1; k < coefs.size(); ++k) {
      id i = coefs[k].ij[0];
      id j = coefs[k].ij[1];
      double v = coefs[k].val;
      if (i != cur_i) {
        if (std::abs(acc_val) > EPS) {
          columns[cur_i].push_back(cur_j);
          values[cur_i].push_back(acc_val);
        }
        cur_i = i;
        acc_val = v;
        cur_j = j;
      } else if (j != cur_j) {
        if (std::abs(acc_val) > EPS) {
          columns[cur_i].push_back(cur_j);
          values[cur_i].push_back(acc_val);
        }
        cur_i = i;
        acc_val = v;
        cur_j = j;
      } else {
        acc_val += v;
      }
    }
    if (std::abs(acc_val) > EPS) {
      columns[cur_i].push_back(cur_j);
      values[cur_i].push_back(acc_val);
    }

    return true;
  }


  bool expand_dirichlet_boundary_conditions(
      const std::vector<std::array<double,3> >& points,
      const std::vector<std::array<id,3> >& triangles,
      const vector<id2>& uIEdges,
      const vector<id>& old2IEdge,
      const vector<vector<id>>& uIEdgeToOld,
      size_t nb_layers,
      vector<bool>& dirichletEdge,
      vector<vec2>& dirichletValue,
      int verbosity) {
    /* Look for expanded BC edges */
    vector<bool> extDirichletEdge = dirichletEdge;
    vector<id> new_edges;
    for (size_t layer = 0; layer < nb_layers; ++layer) {
      for (size_t e = 0; e < uIEdges.size(); ++e) if (extDirichletEdge[e]) {
        for (size_t i = 0; i < uIEdgeToOld[e].size(); ++i) {
          id t = uIEdgeToOld[e][i] / 3;
          for (size_t le = 0; le < 3; ++le) {
            id oe2 = 3*t+le;
            id e2 = old2IEdge[oe2];
            if (!extDirichletEdge[e2]) {
              new_edges.push_back(e2);
            }
          }
        }
      }
      sort_unique(new_edges);
      for (size_t i = 0; i < new_edges.size(); ++i)  {
        extDirichletEdge[new_edges[i]] = true;
      }
    }
    if (new_edges.size() == 0) {
      if (verbosity >= 2)
        Msg::Warning("no new edges to expand dirichlet boundary conditions");
      return false;
    }

    if (verbosity >= 2)
      Msg::Info("Dirichlet B.C. expansion: added %li edges (for %li layers)", new_edges.size(), nb_layers);

    /* Small system for BC expansion */
    vector<IJV> K_coefs;
    for (size_t k = 0; k < new_edges.size(); ++k)  {
      id e = new_edges[k];
      vector<IV> iv;
      vector<IJV> ijv;
      bool oks = stiffness_coefficient(points, triangles, e, uIEdges, old2IEdge, uIEdgeToOld, iv, ijv);
      if (!oks || iv.size() != 2 || iv[0].i != 2*e || iv[1].i != 2*e+1) {
        Msg::Error("failed to get stiffness coefficients for edge e = %li", e);
        return false;
      }
      /* Add coefficients for interaction i-j of edges in extDirichletEdge */
      for (size_t l = 0; l < ijv.size(); ++l) if (extDirichletEdge[ijv[l].ij[1]/2]) {
        K_coefs.push_back(ijv[l]);
      }
    }
    vector<IV> K_diag;
    vector<vector<size_t>> A_col(2*uIEdges.size());
    vector<vector<double>> A_coef(2*uIEdges.size());
    bool okp = prepare_system(K_diag, K_coefs, A_col, A_coef);
    if (!okp) {
      Msg::Error("failed to prepare system");
      return false;
    }

    /* Explicit solver (local smoothing) */
    for (size_t e = 0; e < uIEdges.size(); ++e) if (extDirichletEdge[e] && !dirichletEdge[e]) {
      dirichletValue[e] = {0.,0.};
    }
    for (size_t iter = 0; iter < 10*nb_layers; ++iter) {
      for (size_t e = 0; e < uIEdges.size(); ++e) if (extDirichletEdge[e] && !dirichletEdge[e]) {
        for (size_t d = 0; d < 2; ++d) {
          id i = 2*e+d;
          dirichletValue[e][d] = 0.;
          for (size_t l = 0; l < A_col[i].size(); ++l) {
            id j = A_col[i][l];
            if (!extDirichletEdge[j/2]) continue;
            double w = A_coef[i][l];
            dirichletValue[e][d] += -1. * w * dirichletValue[j/2][j%2];
          }
        }
        double n2 = length(dirichletValue[e]);
        if (n2 < EPS) {
          continue;
        }
        dirichletValue[e][0] /= n2;
        dirichletValue[e][1] /= n2;
      }
    }

    /* Set expanded edges as Dirichlet edges */
    for (size_t e = 0; e < uIEdges.size(); ++e) if (extDirichletEdge[e] 
        && !dirichletEdge[e] && length(dirichletValue[e]) > EPS) {
      dirichletEdge[e] = true;
    }

    return true;
  }

  bool compute_cross_field_with_multilevel_diffusion(
      const std::vector<std::array<double,3> >& points,
      const std::vector<std::array<id,2> >& lines,
      const std::vector<std::array<id,3> >& triangles,
      std::vector<std::array<double,3> >& triEdgeTheta, 
      int nbDiffusionLevels,
      double thresholdNormConvergence,
      int nbBoundaryExtensionLayer,
      int verbosity) {

    /* Build unique edges and association with adjacent triangles,
     * including the non-manifold cases */
    vector<id2> uIEdges;
    vector<id> old2IEdge;
    vector<vector<id>> uIEdgeToOld;
    std::vector<sid3> triangle_neighbors;
    std::vector<std::vector<id>> nm_triangle_neighbors;
    bool oka = compute_triangle_adjacencies(triangles, triangle_neighbors, nm_triangle_neighbors, uIEdges, old2IEdge, uIEdgeToOld);
    if (!oka) {
      Msg::Error("failed to compute mesh adjacencies");
      return false;
    }

    /* Bbox diagonal is used later to specify the diffusion length */
    double diag = bboxDiag(points);
    if (verbosity > 0)
      Msg::Info("input: %li points, %li lines, %li triangles, %li internal edges, bbox diag = %li", points.size(),lines.size(),triangles.size(),uIEdges.size(), diag);

    if (uIEdges.size() == 0) {
      Msg::Error("no internal edges");
      return false;
    }

    /* System unknowns: cos(4t),sin(4t) for each edge */
    vector<double> x(2*uIEdges.size(),0.);

    /* Initial Dirichlet boundary conditions 
     * alignement of crosses with edges (relative angle = 0) 
     * theta_e = 0 => (cos4t/sin4t) = (1,0) */
    size_t nbc = 0;
    vector<bool> dirichletEdge(uIEdges.size(),false);
    vector<vec2> dirichletValue(uIEdges.size(),{1.,0.});
    for (size_t e = 0; e < uIEdges.size(); ++e) if (uIEdgeToOld[e].size() != 2) {
      dirichletEdge[e] = true;
      dirichletValue[e] = {1.,0.};
      nbc += 1;
    }
    for (size_t l = 0; l < lines.size(); ++l) {
      /* mark the lines as boundary conditions */
      id2 edge = sorted(lines[l][0],lines[l][1]);
      auto it = std::find(uIEdges.begin(),uIEdges.end(),edge);
      if (it != uIEdges.end()) {
        id e = id(it - uIEdges.begin());
        dirichletEdge[e] = true;
        dirichletValue[e] = {1.,0.};
        nbc += 1;
      }
    }
    if (verbosity >= 2)
      Msg::Info("boundary conditions: %li crosses fixed on edges", nbc);

    if (nbBoundaryExtensionLayer > 0) {
      bool oke = expand_dirichlet_boundary_conditions(points, triangles, uIEdges, old2IEdge, uIEdgeToOld, nbBoundaryExtensionLayer, dirichletEdge, dirichletValue, verbosity);
      if (!oke) {
        Msg::Warning("failed to expand dirichlet boundary conditions");
      }
      for (size_t e = 0; e < uIEdges.size(); ++e) {
        x[2*e+0] = dirichletValue[e][0];
        x[2*e+1] = dirichletValue[e][1];
      }
    }

    if (verbosity >= 2)
      Msg::Info("compute stiffness matrix coefficients (Crouzeix-Raviart) ...");

    vector<IV> K_diag;
    vector<IJV> K_coefs;
    vector<double> rhs(2*uIEdges.size(),0.);
    vector<double> Mass(2*uIEdges.size(),1.); /* diagonal for Crouzeix-Raviart */
    for (size_t e = 0; e < uIEdges.size(); ++e) {
      if (!dirichletEdge[e]) {
        vector<IV> iv;
        vector<IJV> ijv;
        bool oks = stiffness_coefficient(points, triangles, e, uIEdges, old2IEdge, uIEdgeToOld, iv, ijv);
        if (!oks) {
          Msg::Error("failed to compute stiffness matrix coefficients for e = %li", e);
          return false;
        }
        for (size_t i = 0; i < iv.size(); ++i) 
          K_diag.push_back(iv[i]);
        for (size_t i = 0; i < ijv.size(); ++i) 
          K_coefs.push_back(ijv[i]);
        id t1 = uIEdgeToOld[e][0]/3;
        id t2 = uIEdgeToOld[e][1]/3;
        double area1 = triangleArea(points[triangles[t1][0]],points[triangles[t1][1]],points[triangles[t1][2]]);
        double area2 = triangleArea(points[triangles[t2][0]],points[triangles[t2][1]],points[triangles[t2][2]]);
        Mass[2*e+0] = 1./3 * (area1 + area2);
        Mass[2*e+1] = 1./3 * (area1 + area2);
      } else { /* Dirichlet BC */
        K_diag.push_back({id(2*e+0),1.});
        rhs[2*e+0] = dirichletValue[e][0];
        K_diag.push_back({id(2*e+1),1.});
        rhs[2*e+1] = dirichletValue[e][1];
      }
    }

    double eavg = 0.;
    double emin = DBL_MAX;
    double emax = -DBL_MAX;
    for (size_t e = 0; e < uIEdges.size(); ++e) {
      double len = length(points[uIEdges[e][1]]-points[uIEdges[e][0]]);
      eavg += len;
      emin = std::min(len,emin);
      emax = std::max(len,emax);
    }
    eavg /= uIEdges.size();

    if (verbosity >= 2)
      Msg::Info("edge size: min=%.3f, avg=%.3f, max=%.3f | bbox diag: %.3f",emin,eavg,emax,diag);


    /* prepare system */
    vector<vector<size_t>> K_columns(2*uIEdges.size());
    vector<vector<double>> K_values(2*uIEdges.size());
    {
      bool okp = prepare_system(K_diag, K_coefs, K_columns, K_values);
      if (!okp) {
        Msg::Error("failed to prepare system");
        return false;
      }
    }
    
    double dtInitial = (0.1*diag)*(0.1*diag);
    double dtFinal = (3.*emin)*(3.*emin);

    if (verbosity >= 1)
      Msg::Info("heat diffusion and projection loop (%li levels, %li unknowns, dt = %.3f .. %.3f) ...", nbDiffusionLevels, 2*uIEdges.size(),dtInitial, dtFinal);

    double wti = TimeOfDay();
    for (size_t e = 0; e < uIEdges.size(); ++e) {
      x[2*e+0] = dirichletValue[e][0];
      x[2*e+1] = dirichletValue[e][1];
    }

    vector<double> steps;
    if (nbDiffusionLevels > 1) {
      for (size_t i = 0; i < nbDiffusionLevels; ++i) {/* resolution transition */
        double dt = dtInitial + (dtFinal-dtInitial) * double(i)/double(nbDiffusionLevels-1);
        steps.push_back(dt);
      }
    } else {
      steps.push_back(dtFinal);
    }

    {
      /* Initialize system (I/dt + M^-1 * L) x_(i+1) = 1/dt * x_i     (Ax = B) */
      vector<vector<size_t>> Acol = K_columns;
      vector<vector<double>> Aval_add = K_values; /* to get sparsity pattern */
      for (size_t i = 0; i < Aval_add.size(); ++i) 
        std::fill(Aval_add[i].begin(),Aval_add[i].end(),0.);
      vector<double> B = x;
      vector<double> norms(uIEdges.size(),0.);
      vector<double> prevNorms = norms;

      CrossFieldLinearSystem solver(2*uIEdges.size());

      vector<double> diag_sum(2*uIEdges.size(), 0.);
      for (size_t i = 0; i < Acol.size(); ++i) {
        if (!dirichletEdge[i/2]) {
          for (size_t j = 0; j < Acol[i].size(); ++j) {
            Aval_add[i][j] = 1. / Mass[i] * K_values[i][j];
          }
        } else {
          Aval_add[i] = {1.};
        }
      }
      solver.add_sparse_coefficients(Acol, Aval_add, true);
      for (size_t i = 0; i < Aval_add.size(); ++i) Aval_add[i].clear();
      for (size_t i = 0; i < Acol.size(); ++i) Acol[i].clear();
      bool okp = solver.preprocess_sparsity_pattern();
      if (!okp) {
        Msg::Error("linear solver analysis failed");
        return false;
      }

      /* Loop over the changing timesteps */
      double prev_dt = DBL_MAX;
      for (int iter = 0; iter < steps.size(); ++iter) {
        if (iter > 0 && steps[iter] > prev_dt) continue;
        double dt = steps[iter];
        prev_dt = dt;

        if (verbosity >= 1)
          Msg::Info("  step %li/%li | dt = %.3f, linear system loop ...", iter+1, steps.size(), dt);

        /* Update LHS matrix with the new timestep */
        for (size_t i = 0; i < Acol.size(); ++i) {
          if (!dirichletEdge[i/2]) {
            Acol[i] = {i};
            Aval_add[i] = {-diag_sum[i] + 1./dt};
            diag_sum[i] = 1./dt;
          }
        }
        bool oku = solver.add_sparse_coefficients(Acol, Aval_add, false);
        if (!oku) {
          Msg::Error("failed to update linear system");
          return false;
        }
        solver.factorize();

        /* Loop at fixed time step */
        constexpr size_t subiter_max = 25;
        for (size_t subiter = 0; subiter < subiter_max; ++subiter) {
          prevNorms = norms;

          /* Update RHS */
          B = x;
          for (size_t i = 0; i < B.size(); ++i) if (!dirichletEdge[i/2])
            B[i] /= dt;
          solver.set_rhs_values(B);

          bool oks = solver.solve(x);
          if (!oks) {
            Msg::Error("failed to solve linear system");
            return false;
          }

          
          /* Normalize cross field and gather norm stats */
          double nmi = DBL_MAX;
          double nma = -DBL_MAX;
          for (size_t e = 0; e < uIEdges.size(); ++e) {
            norms[e] = std::sqrt(x[2*e]*x[2*e]+x[2*e+1]*x[2*e+1]);
            nmi = std::min(nmi,norms[e]);
            nma = std::max(nma,norms[e]);
            if (!dirichletEdge[e] && norms[e] > EPS) {
              x[2*e+0] /= norms[e];
              x[2*e+1] /= norms[e];
            }
          }
          // Msg::Info("            |   norm, min = {}, max = {}", nmi, nma);
          const double EPS_NORM = 1.e-1;
          if (nma > 1. + EPS_NORM) {
            steps[iter] /= 10;
            dt = steps[iter];
            iter -= 1;
            if (verbosity >= 2)
              Msg::Warning("           |   max(norm)=%.3f (should be 1.), solve failed, new time step: dt = %.3f", nma, dt);
            break;
          }
          if (subiter > 0 || iter > 0) {
            double linf = 0.;
            for (size_t i = 0; i < norms.size(); ++i) if (!dirichletEdge[i]) {
              linf = std::max(linf,norms[i]-prevNorms[i]);
            }
            if (verbosity >= 3)
              Msg::Info("           |   system solved, norm diff max: %.3f, norm range: %.3f - %.3f", linf, nmi, nma);
            if (linf < 1.e-3) break;
          } else {
            if (verbosity >= 3)
              Msg::Info("           |   system solved");
          }
        }
      }
    }
    double et = TimeOfDay() - wti;
    if (verbosity >= 2)
      Msg::Info("cross field elapsed time: %.3f", et);


    { /* Export solution */
      triEdgeTheta.resize(triangles.size());
      for (size_t t = 0; t < triangles.size(); ++t) {
        for (size_t le = 0; le < 3; ++le) {
          id e = old2IEdge[3*t+le];
          double len = std::sqrt(x[2*e]*x[2*e]+x[2*e+1]*x[2*e+1]);
          double theta = (len > EPS) ? 1./4*atan2(x[2*e+1]/len,x[2*e]/len) : 0.;
          triEdgeTheta[t][le] = theta;
        }
      }
    }

    return true;
  }

}


int computeCrossFieldWithHeatEquation(
    const std::vector<MTriangle*>& triangles, 
    const std::vector<MLine*>& lines, 
    std::vector<std::array<double,3> >& triEdgeTheta, 
    int nbDiffusionLevels, 
    double thresholdNormConvergence,
    int nbBoundaryExtensionLayer,
    int verbosity) {

  /* Build discrete mesh without reference to gmsh structures */
  std::vector<std::array<double,3> > dpoints;
  std::vector<std::array<QMT::id,2> > dlines;
  std::vector<std::array<QMT::id,3> > dtriangles;
  std::vector<QMT::id> old2new;
  {
    old2new.reserve(3*triangles.size());
    dpoints.reserve(3*triangles.size());
    dlines.reserve(lines.size());
    dtriangles.reserve(triangles.size());

    constexpr QMT::id X = std::numeric_limits<QMT::id>::max();

    for (MLine* l: lines) {
      std::array<QMT::id,2> line;
      for (size_t lv = 0; lv < 2; ++lv) {
        MVertex* v = l->getVertex(lv);
        size_t num = v->getNum();
        if (num >= old2new.size()) {
          old2new.resize(num+1,X);
        }
        if (old2new[num] == X) {
          old2new[num] = dpoints.size();
          std::array<double,3> pt = {v->x(), v->y(), v->z()};
          dpoints.push_back(pt);
        }
        line[lv] = old2new[num];
      }
      std::sort(line.begin(),line.end());
      dlines.push_back(line);
    }
    for (MTriangle* t: triangles) {
      std::array<QMT::id,3> tri;
      for (size_t lv = 0; lv < 3; ++lv) {
        MVertex* v = t->getVertex(lv);
        size_t num = v->getNum();
        if (num >= old2new.size()) {
          old2new.resize(num+1,X);
        }
        if (old2new[num] == X) {
          old2new[num] = dpoints.size();
          std::array<double,3> pt = {v->x(), v->y(), v->z()};
          dpoints.push_back(pt);
        }
        tri[lv] = old2new[num];
      }
      dtriangles.push_back(tri);
    }
  }


  bool ok = QMT::compute_cross_field_with_multilevel_diffusion(
      dpoints, dlines, dtriangles, triEdgeTheta,
      nbDiffusionLevels, thresholdNormConvergence,nbBoundaryExtensionLayer,
      verbosity);
  return ok ? 0 : -1;
}
