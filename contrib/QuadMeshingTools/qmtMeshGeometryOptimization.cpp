// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtMeshGeometryOptimization.h"

/* System includes */
#include <queue>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "robin_hood.h"
#include "meshOctreeLibOL.h"
#include "Context.h"
#include "gmsh.h" // api
#include "GmshConfig.h"

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

/* WinslowUntangler includes */
#if defined(HAVE_WINSLOWUNTANGLER)
#include "winslowUntangler.h"
#include "meshSurfaceUntangling.h"
#endif

#if defined(HAVE_EIGEN)
#include <Eigen/SparseLU>
#include <Eigen/IterativeLinearSolvers>
#endif

constexpr bool DBG_VIZU_K = false;
constexpr bool DBG_VIZU_G = false;
constexpr bool DBG_VIZU_U = false;

using namespace CppUtils;
using namespace ArrayGeometry;

using std::vector;
using vec4 = std::array<double, 4>;
using vec5 = std::array<double, 5>;

template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_map =
  robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

template <typename Key, typename Hash = robin_hood::hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_set =
  robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;

namespace QMT {
  constexpr size_t NO_SIZE_T = (size_t)-1;
  constexpr uint32_t NO_U32 = (uint32_t)-1;

  bool SHOW_QUALITY = false; /* Debug only */

  inline bool kernelWinslowSpecialStencil(const vec3 ptsStencil[8],
                                          vec3 &newPos)
  {
    /* Stencil:
     *   6---1---4
     *   |   |   |
     *   2--- ---0
     *   |   |   |
     *   7---3---5
     */
    /* warning: 2D stencil but 3D coordinates */
    const double hx = 1.;
    const double hy = 1.;

    /* 1. Compute the winslow coefficients (alpha_i, beta_i in the Karman paper)
     */
    /*    a. Compute first order derivatives of the position */
    vec3 r_i[2];
    r_i[0] = 1. / hx * (ptsStencil[0] - ptsStencil[2]);
    r_i[1] = 1. / hy * (ptsStencil[1] - ptsStencil[3]);
    /*    b. Compute the alpha_i coefficients */
    const double alpha_0 = dot(r_i[1], r_i[1]);
    const double alpha_1 = dot(r_i[0], r_i[0]);
    /*    c. Compute the beta coefficient */
    const double beta = dot(r_i[0], r_i[1]);

    /* cross derivative */
    const vec3 u_xy =
      1. / (4. * hx * hy) *
      (ptsStencil[4] + ptsStencil[7] - ptsStencil[6] - ptsStencil[5]);

    /* 2. Compute the "winslow new position" */
    const double denom = 2. * alpha_0 / (hx * hx) + 2. * alpha_1 / (hy * hy);
    if(std::abs(denom) < 1.e-18) return false;
    newPos = 1. / denom *
             (alpha_0 / (hx * hx) * (ptsStencil[0] + ptsStencil[2]) +
              alpha_1 / (hy * hy) * (ptsStencil[1] + ptsStencil[3]) -
              2. * beta * u_xy);
    return true;
  }

  inline bool kernelWinslow(const std::array<vec3, 8> &stencil, vec3 &newPos)
  {
    /* Continuous ordering in input stencil */
    const std::array<uint32_t, 8> o2n = {0, 2, 4, 6, 1, 7, 3, 5};
    const std::array<vec3, 8> winStencil = {
      stencil[o2n[0]], stencil[o2n[1]], stencil[o2n[2]], stencil[o2n[3]],
      stencil[o2n[4]], stencil[o2n[5]], stencil[o2n[6]], stencil[o2n[7]]};
    return kernelWinslowSpecialStencil(winStencil.data(), newPos);
  }

  bool kernelLaplacian(const std::vector<vec3> &points, vec3 &newPos)
  {
    const size_t N = points.size();
    if(N == 0) return false;
    newPos = {0., 0., 0.};
    for(size_t i = 0; i < N; ++i) { newPos = newPos + points[i]; }
    newPos = 1. / double(N) * newPos;
    return true;
  }

  bool kernelAngleBased(const vec3 &center, const std::vector<vec3> &points,
                        vec3 &newPos)
  {
    const size_t N = points.size();
    std::vector<vec3> rotated(N);
    std::vector<double> angles(N);
    double sum_angle = 0.;
    for(size_t i = 0; i < N; ++i) {
      const vec3 &prev = points[(N + i - 1) % N];
      const vec3 &cur = points[i];
      const vec3 &next = points[(i + 1) % N];
      vec3 oldDir = (center - cur);
      double len = length(oldDir);
      if(len == 0.) return false;
      vec3 d1 = prev - cur;
      if(length2(d1) == 0.) return false;
      vec3 d2 = next - cur;
      if(length2(d2) == 0.) return false;
      normalize(d1);
      normalize(d2);
      vec3 newDir = d1 + d2;
      if(length2(newDir) == 0.) return false;
      normalize(newDir);
      if(dot(newDir, oldDir) < 0.) { newDir = -1. * newDir; }
      rotated[i] = cur + len * newDir;
      normalize(oldDir);
      double agl = angleVectorsAlreadyNormalized(newDir, oldDir);
      angles[i] = agl;
      sum_angle += agl;
    }
    if(sum_angle == 0.) return false;
    newPos.data()[0] = 0.;
    newPos.data()[1] = 0.;
    newPos.data()[2] = 0.;
    for(size_t i = 0; i < N; ++i) {
      double w = angles[i] / sum_angle;
      // double w = 1./double(N);
      newPos = newPos + w * rotated[i];
    }
    return true;
  }

  std::array<vec3, 8>
  fillStencilRegular(size_t v, const std::vector<vec3> &points,
                     const std::vector<size_t> &one_ring_first,
                     const std::vector<uint32_t> &one_ring_values)
  {
    return std::array<vec3, 8>{points[one_ring_values[one_ring_first[v] + 0]],
                               points[one_ring_values[one_ring_first[v] + 1]],
                               points[one_ring_values[one_ring_first[v] + 2]],
                               points[one_ring_values[one_ring_first[v] + 3]],
                               points[one_ring_values[one_ring_first[v] + 4]],
                               points[one_ring_values[one_ring_first[v] + 5]],
                               points[one_ring_values[one_ring_first[v] + 6]],
                               points[one_ring_values[one_ring_first[v] + 7]]};
  }

  void fillStencilIrregular(size_t v, const std::vector<vec3> &points,
                            const std::vector<size_t> &one_ring_first,
                            const std::vector<uint32_t> &one_ring_values,
                            std::vector<vec3> &stencil, bool oneOverTwo = false)
  {
    if(oneOverTwo) {
      size_t n = (one_ring_first[v + 1] - one_ring_first[v]) / 2;
      stencil.resize(n);
      for(size_t i = 0; i < stencil.size(); ++i) {
        stencil[i] = points[one_ring_values[one_ring_first[v] + 2 * i]];
      }
    }
    else {
      stencil.resize(one_ring_first[v + 1] - one_ring_first[v]);
      for(size_t i = 0; i < stencil.size(); ++i) {
        stencil[i] = points[one_ring_values[one_ring_first[v] + i]];
      }
    }
  }

  double stencilAverageLength(const std::array<vec3, 8> &stencil)
  {
    double avg = 0.;
    const uint32_t N = stencil.size();
    for(uint32_t i = 0; i < N; ++i) {
      const vec3 &p0 = stencil[i];
      const vec3 &p1 = stencil[(i + 1) % N];
      avg += length(p1 - p0);
    }
    avg /= double(N);
    return avg;
  }

  double stencilAverageLength(const std::vector<vec3> &stencil)
  {
    double avg = 0.;
    const uint32_t N = stencil.size();
    for(uint32_t i = 0; i < N; ++i) {
      const vec3 &p0 = stencil[i];
      const vec3 &p1 = stencil[(i + 1) % N];
      avg += length(p1 - p0);
    }
    avg /= double(N);
    return avg;
  }

  /* p0, p1, p2, p3: the four (ordered and oriented) corners
   * Quad normal reference computed from the corners. Element should not
   * be inverted or too tangled */
  inline double quad_shape_ln(const vec3 &p0, const vec3 &p1, const vec3 &p2,
                              const vec3 &p3)
  {
    /* Based on Sandia Verdict document */
    constexpr double EPS = 1.e-16;
    constexpr double EPS2 = EPS * EPS;
    const vec3 L0 = p1 - p0;
    const vec3 L1 = p2 - p1;
    const vec3 L2 = p3 - p2;
    const vec3 L3 = p0 - p3;
    const vec3 X1 = L0 - L2;
    const vec3 X2 = L1 - L3;
    vec3 Nc = cross(X1, X2);
    const double lenNc_sq = length2(Nc);
    if(lenNc_sq < EPS2) return -1.;
    normalize(Nc);
    const double len0_sq = length2(L0);
    const double len1_sq = length2(L1);
    const double len2_sq = length2(L2);
    const double len3_sq = length2(L3);
    if(len0_sq < EPS2 || len1_sq < EPS2 || len2_sq < EPS2 || len3_sq < EPS2)
      return 0.;
    const vec3 N0 = cross(L3, L0);
    const vec3 N1 = cross(L0, L1);
    const vec3 N2 = cross(L1, L2);
    const vec3 N3 = cross(L2, L3);
    const double a0 = dot(Nc, N0); /* bad if non planar quad ? */
    const double a1 = dot(Nc, N1);
    const double a2 = dot(Nc, N2);
    const double a3 = dot(Nc, N3);
    const double q0 = a0 / (len3_sq + len0_sq);
    const double q1 = a1 / (len0_sq + len1_sq);
    const double q2 = a2 / (len1_sq + len2_sq);
    const double q3 = a3 / (len2_sq + len3_sq);
    if(SHOW_QUALITY && (q0 < 0 || q1 < 0 || q2 < 0 || q3 < 0)) {
      vec3 mid = (p0 + p1 + p2 + p3) * 0.25;
      DBG(q0, q1, q2, q3);
      GeoLog::add(mid, Nc, "Nc");
      GeoLog::add(p0, N0, "Ni");
      GeoLog::add(p1, N1, "Ni");
      GeoLog::add(p2, N2, "Ni");
      GeoLog::add(p3, N3, "Ni");
      GeoLog::add({p0, p1, p2, p3}, 0., "quad");
      GeoLog::flush();
      gmsh::fltk::run();
      abort();
    }
    return 2. * std::min(std::min(q0, q1), std::min(q2, q3));
  }

  inline double stencilQualitySICNmin(const vec3 &center,
                                      const std::array<vec3, 8> &stencil,
                                      double breakIfBelowThreshold = -DBL_MAX)
  {
    double qmin = DBL_MAX;
    constexpr uint32_t N = 4;
    for(uint32_t i = 0; i < N; ++i) {
      const vec3 &p0 = stencil[2 * i + 0];
      const vec3 &p1 = stencil[2 * i + 1];
      const size_t i2 = (2 * i + 2) % (2 * N);
      const vec3 &p2 = stencil[i2];
      const double q = quad_shape_ln(p0, p1, p2, center);
      qmin = std::min(q, qmin);
      if(qmin < breakIfBelowThreshold) return qmin;
    }
    return qmin;
  }

  inline double stencilQualitySICNmin(const vec3 &center,
                                      const std::vector<vec3> &stencil,
                                      double breakIfBelowThreshold = -DBL_MAX)
  {
    if(stencil.size() % 2 != 0) return -DBL_MAX;
    double qmin = DBL_MAX;
    const uint32_t N = stencil.size() / 2;
    for(uint32_t i = 0; i < N; ++i) {
      const vec3 &p0 = stencil[2 * i + 0];
      const vec3 &p1 = stencil[2 * i + 1];
      const size_t i2 = (2 * i + 2) % (2 * N);
      const vec3 &p2 = stencil[i2];
      const double q = quad_shape_ln(p0, p1, p2, center);
      qmin = std::min(q, qmin);
      if(qmin < breakIfBelowThreshold) return qmin;
    }
    return qmin;
  }

  inline double
  stencilQualitySICNminGmsh(const vec3 &center,
                            const std::array<vec3, 8> &stencil,
                            double breakIfBelowThreshold = -DBL_MAX)
  {
    double qmin = DBL_MAX;
    constexpr uint32_t N = 4;
    for(uint32_t i = 0; i < N; ++i) {
      const vec3 &p0 = stencil[2 * i + 0];
      const vec3 &p1 = stencil[2 * i + 1];
      const size_t i2 = (2 * i + 2) % (2 * N);
      const vec3 &p2 = stencil[i2];
      MVertex a(p0[0], p0[1], p0[2]);
      MVertex b(p1[0], p1[1], p1[2]);
      MVertex c(p2[0], p2[1], p2[2]);
      MVertex d(center[0], center[1], center[2]);
      MQuadrangle quad(&a, &b, &c, &d);
      double q = quad.minSICNShapeMeasure();
      if(std::isnan(q)) q = -1.;
      qmin = std::min(q, qmin);
      if(qmin < breakIfBelowThreshold) return qmin;
    }
    return qmin;
  }

  inline double
  stencilQualitySICNminGmsh(const vec3 &center,
                            const std::vector<vec3> &stencil,
                            double breakIfBelowThreshold = -DBL_MAX)
  {
    if(stencil.size() % 2 != 0) return -DBL_MAX;
    double qmin = DBL_MAX;
    const uint32_t N = stencil.size() / 2;
    for(uint32_t i = 0; i < N; ++i) {
      const vec3 &p0 = stencil[2 * i + 0];
      const vec3 &p1 = stencil[2 * i + 1];
      const size_t i2 = (2 * i + 2) % (2 * N);
      const vec3 &p2 = stencil[i2];
      MVertex a(p0[0], p0[1], p0[2]);
      MVertex b(p1[0], p1[1], p1[2]);
      MVertex c(p2[0], p2[1], p2[2]);
      MVertex d(center[0], center[1], center[2]);
      MQuadrangle quad(&a, &b, &c, &d);
      double q = quad.minSICNShapeMeasure();
      qmin = std::min(q, qmin);
      if(qmin < breakIfBelowThreshold) return qmin;
    }
    return qmin;
  }

  struct OneRing {
    vec5 *p_uv = NULL;
    uint32_t n = 0;
    vec2 jump = {{0., 0.}};
    vec3 range = {{0., 0., 0.}};
  };

  bool buildCondensedStructure(const std::vector<MVertex *> &freeVertices,
                               const std::vector<MElement *> &elements,
                               std::unordered_map<MVertex *, size_t> &old2new,
                               std::vector<vector<size_t> > &v2v)
  {
    /* Build the old2new mapping */
    size_t vcount = 0;
    for(MVertex *v : freeVertices) {
      old2new[v] = vcount;
      vcount += 1;
    }
    size_t nInterior = vcount;
    if(nInterior == 0) return true; /* nothing to smooth */
    v2v.resize(nInterior);
    for(MElement *f : elements) {
      for(size_t le = 0; le < 4; ++le) {
        MVertex *vs[2] = {f->getVertex(le), f->getVertex((le + 1) % 4)};
        size_t nvs[2];
        for(size_t lv = 0; lv < 2; ++lv) {
          MVertex *v = vs[lv];
          size_t nv = NO_SIZE_T;
          auto it = old2new.find(v);
          if(it == old2new.end()) {
            old2new[v] = vcount;
            nv = vcount;
            vcount += 1;
          }
          else {
            nv = it->second;
          }
          nvs[lv] = nv;
        }
        if(nvs[0] < nInterior) v2v[old2new[vs[0]]].push_back(old2new[vs[1]]);
        if(nvs[1] < nInterior) v2v[old2new[vs[1]]].push_back(old2new[vs[0]]);
      }
      constexpr bool addDiags = false;
      if(addDiags) {
        for(size_t d = 0; d < 2; ++d) {
          MVertex *vs[2] = {f->getVertex(d), f->getVertex((d + 2) % 4)};
          size_t nvs[2] = {old2new[vs[0]], old2new[vs[1]]};
          if(nvs[0] < nInterior) v2v[old2new[vs[0]]].push_back(old2new[vs[1]]);
          if(nvs[1] < nInterior) v2v[old2new[vs[1]]].push_back(old2new[vs[0]]);
        }
      }
    }
    return true;
  }

  bool buildCondensedStructure(const std::vector<MElement *> &elements,
                               const std::vector<MVertex *> &freeVertices,
                               std::unordered_map<MVertex *, uint32_t> &old2new,
                               std::vector<MVertex *> &new2old,
                               std::vector<std::array<uint32_t, 4> > &quads,
                               std::vector<std::vector<uint32_t> > &v2q,
                               std::vector<std::vector<uint32_t> > &oneRings,
                               std::vector<std::array<double, 3> > &points)
  {
    new2old.reserve(2 * freeVertices.size());
    v2q.reserve(2 * freeVertices.size());
    points.reserve(2 * freeVertices.size());

    size_t vcount = 0;
    for(MVertex *v : freeVertices) {
      old2new[v] = vcount;
      vec3 pt = SVector3(v->point());
      points.push_back(pt);
      new2old.push_back(v);
      vcount += 1;
    }

    v2q.resize(vcount);
    quads.clear();
    quads.resize(elements.size(), {NO_U32, NO_U32, NO_U32, NO_U32});
    for(size_t f = 0; f < elements.size(); ++f) {
      MElement *q = elements[f];
      if(q->getNumVertices() > 4) {
        Msg::Error(
          "buildCondensedStructure: element with %li vertices not supported",
          q->getNumVertices());
        return false;
      }
      for(size_t lv = 0; lv < q->getNumVertices(); ++lv) {
        MVertex *v = q->getVertex(lv);
        auto it = old2new.find(v);
        size_t nv;
        if(it == old2new.end()) {
          old2new[v] = vcount;
          new2old.push_back(v);
          nv = vcount;
          vcount += 1;
          vec3 pt = SVector3(v->point());
          points.push_back(pt);
          if(nv >= v2q.size()) { v2q.resize(nv + 1); }
        }
        else {
          nv = it->second;
        }
        quads[f][lv] = nv;
        v2q[nv].push_back(f);
      }
    }
    points.shrink_to_fit();
    quads.shrink_to_fit();
    new2old.shrink_to_fit();
    v2q.shrink_to_fit();

    /* Build the one rings for the free vertices */
    oneRings.resize(freeVertices.size());
    vector<MElement *> adjElts;
    for(size_t v = 0; v < freeVertices.size(); ++v) {
      adjElts.resize(v2q[v].size());
      for(size_t lq = 0; lq < v2q[v].size(); ++lq) {
        adjElts[lq] = elements[v2q[v][lq]];
      }
      std::vector<MVertex *> bnd;
      bool okb = buildBoundary(adjElts, bnd);
      if(!okb) {
        Msg::Warning(
          "buildCondensedStructure: failed to build boundary for stencil");
        return false;
      }
      if(bnd.back() == bnd.front()) bnd.pop_back();

      /* Be sure the first vertex on the boundary is edge-connected to v */
      /* Start of the stencil */
      MVertex *vp = freeVertices[v];
      MVertex *v0 = NULL;
      for(MElement *e : adjElts) {
        size_t N = e->getNumVertices();
        for(size_t j = 0; j < N; ++j) {
          MVertex *a = e->getVertex(j);
          MVertex *b = e->getVertex((j + 1) % N);
          if(a == vp) {
            v0 = b;
            break;
          }
          else if(b == vp) {
            v0 = a;
            break;
          }
        }
        if(v0 != NULL) break;
      }
      if(v0 == NULL) {
        Msg::Warning("buildCondensedStructure: failed to found v0");
        return false;
      }
      for(size_t j = 0; j < bnd.size(); ++j) {
        if(bnd[j] == v0 && j > 0) {
          std::rotate(bnd.begin(), bnd.begin() + j, bnd.end());
          break;
        }
      }
      if(bnd.front() != v0) {
        Msg::Warning("buildCondensedStructure: wrong start (bnd size: %li)",
                     bnd.size());
        return false;
      }

      if(bnd.size() < 3) {
        Msg::Warning("buildCondensedStructure: wrong boundary, size %li",
                     bnd.size());
        return false;
      }

      oneRings[v].resize(bnd.size());
      for(size_t j = 0; j < bnd.size(); ++j) {
        auto it = old2new.find(bnd[j]);
        if(it != old2new.end()) { oneRings[v][j] = it->second; }
        else {
          Msg::Error("buildCondensedStructure: vertex not found in old2new");
          return false;
        }
      }
    }

    return true;
  }

  bool buildUVSmoothingDataStructures(
    GFace *gf, const std::vector<MElement *> &elements,
    const std::vector<MVertex *> &freeVertices, std::vector<vec5> &point_uv,
    std::vector<size_t> &one_ring_first, std::vector<uint32_t> &one_ring_values,
    std::vector<MVertex *> &new2old)
  {
    std::unordered_map<MVertex *, uint32_t> old2new;
    std::vector<std::array<uint32_t, 4> > quads;
    std::vector<std::vector<uint32_t> > v2q;
    std::vector<std::vector<uint32_t> > oneRings;
    std::vector<std::array<double, 3> > points;
    bool okc = buildCondensedStructure(elements, freeVertices, old2new, new2old,
                                       quads, v2q, oneRings, points);
    if(!okc) {
      Msg::Warning(
        "buildCondensedStructure: failed to build condensed representation");
      return false;
    }

    /* Get associated uv in GFace */
    std::vector<std::array<double, 2> > uvs(old2new.size(), {DBL_MAX, DBL_MAX});
    for(size_t i = 0; i < elements.size(); ++i) {
      std::vector<SPoint2> quad_uvs = paramOnElement(gf, elements[i]);
      for(size_t lv = 0; lv < 4; ++lv) {
        size_t v = quads[i][lv];
        if(v == NO_U32) continue;
        if(uvs[v][0] == DBL_MAX) {
          uvs[v][0] = quad_uvs[lv][0];
          uvs[v][1] = quad_uvs[lv][1];
        }
      }
    }

    /* Compact 3D + uv */
    point_uv.resize(points.size());
    for(size_t i = 0; i < points.size(); ++i) {
      point_uv[i][0] = points[i][0];
      point_uv[i][1] = points[i][1];
      point_uv[i][2] = points[i][2];
      point_uv[i][3] = uvs[i][0];
      point_uv[i][4] = uvs[i][1];
    }

    /* One ring adjacencies in contiguous memory */
    compress(oneRings, one_ring_first, one_ring_values);

    return true;
  }

  bool getContinuousUVOnLoop(GFace *gf,
                             const std::vector<MVertex *> &bndOrdered,
                             std::vector<SPoint2> &bndUvs)
  {
    if(bndOrdered.size() < 3) return false;

    /* If periodic parametrization, get periods */
    double Ts[2] = {0., 0.};
    if(gf->periodic(0)) Ts[0] = gf->period(0);
    if(gf->periodic(1)) Ts[1] = gf->period(1);

    /* Get start point on the loop, inside GFace if possible */
    size_t i0 = 0;
    for(size_t i = 0; i < bndOrdered.size(); ++i) {
      MVertex *v = bndOrdered[i];
      if(v->onWhat() == gf) {
        i0 = i;
        break;
      }
    }

    /* Get all the parameters on the loop */
    bndUvs.resize(bndOrdered.size());
    reparamMeshVertexOnFace(bndOrdered[i0], gf, bndUvs[i0], true);
    SPoint2 prevUV = bndUvs[i0];

    double gapMax[2] = {0., 0.};
    const size_t N = bndOrdered.size();
    for(size_t k = 1; k < N; ++k) {
      size_t i = (i0 + k) % N;
      MVertex *v = bndOrdered[i];
      bool okr = reparamMeshVertexOnFaceWithRef(gf, v, prevUV, bndUvs[i]);
      if(!okr) return false;

      gapMax[0] =
        std::max(gapMax[0], std::abs(bndUvs[i].data()[0] - prevUV.data()[0]));
      gapMax[1] =
        std::max(gapMax[1], std::abs(bndUvs[i].data()[1] - prevUV.data()[1]));
      prevUV = bndUvs[i];
    }
    gapMax[0] = std::max(
      gapMax[0], std::abs(bndUvs.front().data()[0] - bndUvs.back().data()[0]));
    gapMax[1] = std::max(
      gapMax[1], std::abs(bndUvs.front().data()[1] - bndUvs.back().data()[1]));

    if(Ts[0] > 0 && gapMax[0] > 0.5 * Ts[0]) {
      Msg::Debug(
        "getContinuousUVOnLoop: reject because gap on boundary: %f (period %f)",
        gapMax[0], Ts[0]);
      return false;
    }
    if(Ts[1] > 0 && gapMax[1] > 0.5 * Ts[1]) {
      Msg::Debug(
        "getContinuousUVOnLoop: reject because gap on boundary: %f (period %f)",
        gapMax[1], Ts[1]);
      return false;
    }

    return true;
  }

  bool
  getPlanarParametrization(const GFaceMeshPatch &patch,
                           std::unordered_map<MVertex *, SPoint2> &vertexParam)
  {
    if(patch.intVertices.size() == 0) return false;
    GFace *gf = patch.gf;
    if(!gf->haveParametrization()) return false;
    vertexParam.clear();

    /* If periodic parametrization, get periods */
    double Ts[2] = {0., 0.};
    if(gf->periodic(0)) Ts[0] = gf->period(0);
    if(gf->periodic(1)) Ts[1] = gf->period(1);

    std::unordered_map<MVertex *, std::vector<MVertex *> > v2v;
    buildVertexToVertexMap(patch.elements, v2v);
    MVertex *v0 = patch.intVertices[0];

    std::queue<MVertex *> Q;
    Q.push(v0);
    SPoint2 uv0(0., 0.);
    v0->getParameter(0, uv0.data()[0]);
    v0->getParameter(1, uv0.data()[1]);
    vertexParam[v0] = uv0;
    while(Q.size() > 0) {
      MVertex *v = Q.front();
      Q.pop();
      SPoint2 uv = vertexParam[v];
      for(MVertex *v2 : v2v[v]) {
        auto it = vertexParam.find(v2);
        if(it != vertexParam.end()) {
          if(Ts[0] != 0. || Ts[1] != 0.) {
            /* Check jump */
            SPoint2 uv2 = it->second;
            if(Ts[0] != 0. && std::abs(uv.x() - uv2.x()) > 0.5 * Ts[0])
              return false;
            if(Ts[1] != 0. && std::abs(uv.y() - uv2.y()) > 0.5 * Ts[1])
              return false;
          }
          continue;
        }
        SPoint2 uv2(0., 0.);
        bool okr = reparamMeshVertexOnFaceWithRef(patch.gf, v2, uv, uv2);
        if(!okr) {
          Msg::Debug("getPlanarParametrization | failed to reparam v2");
          return false;
        }
        vertexParam[v2] = uv2;
        Q.push(v2);
      }
    }

    return true;
  }

  bool solveLaplaceLinearSystem(size_t nInterior,
                                const vector<vector<size_t> > &v2v,
                                vector<SPoint2> &uvs)
  {
    if(nInterior > 100) {
      Msg::Debug("... solve laplace linear system (%li unknowns) ...",
                 nInterior);
    }

#if defined(HAVE_EIGEN)
    size_t N = uvs.size();
    Eigen::VectorXd x_u(N), x_v(N), b_u(N), b_v(N);
    Eigen::SparseMatrix<double> A(N, N);
    b_u.fill(0.);
    b_v.fill(0.);
    double PENALTY = 1.e8;

    std::vector<Eigen::Triplet<double, size_t> > triplets;
    for(size_t v = 0; v < uvs.size(); ++v) {
      if(v < nInterior) {
        triplets.push_back({v, v, 1.});
        if(v2v[v].size() == 0) continue;
        double sum = double(v2v[v].size());
        for(size_t v2 : v2v[v]) { triplets.push_back({v, v2, -1. / sum}); }
      }
      else { /* fixed value */
        triplets.push_back({v, v, PENALTY});
        b_u[v] = PENALTY * uvs[v][0];
        b_v[v] = PENALTY * uvs[v][1];
      }
    }
    A.setFromTriplets(triplets.begin(), triplets.end());

    bool solveOk = true;
    { /* Try SparseLU */
      Eigen::SparseLU<Eigen::SparseMatrix<double> > solver;
      solver.analyzePattern(A);
      solver.factorize(A);
      x_u = solver.solve(b_u);
      if(solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning(
          "failed to solve linear system with SparseLU (%li variables)", N);
        solveOk = false;
      }
      x_v = solver.solve(b_v);
      if(solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning(
          "failed to solve linear system with SparseLU (%li variables)", N);
        solveOk = false;
      }
    }
    if(!solveOk) { /* Try least square */
      solveOk = true;
      Eigen::LeastSquaresConjugateGradient<Eigen::SparseMatrix<double> > solver;
      solver.compute(A);
      x_u = solver.solve(b_u);
      if(solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning(
          "failed to solve linear system with least-square (%li variables)", N);
        solveOk = false;
      }
      x_v = solver.solve(b_v);
      if(solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning(
          "failed to solve linear system with least-square (%li variables)", N);
        solveOk = false;
      }
    }

    for(size_t v = 0; v < nInterior; ++v) {
      uvs[v][0] = x_u[v];
      uvs[v][1] = x_v[v];
    }
    if(!solveOk) {
      Msg::Error("failed to solve linear system to solve uv");
      return false;
    }

#else
    Msg::Error("solveLaplaceLinearSystem requires the EIGEN module");
    return -1;
#endif
    return true;
  }

  /* p0, p1, p2, p3: the four (ordered and oriented) corners
   * N: reference normal (normalized) */
  inline double quad_shape(const vec3 &p0, const vec3 &p1, const vec3 &p2,
                           const vec3 &p3, const vec3 &N)
  {
    /* Based on Sandia Verdict document */
    constexpr double EPS = 1.e-16;
    constexpr double EPS2 = EPS * EPS;
    const vec3 L0 = p1 - p0;
    const vec3 L1 = p2 - p1;
    const vec3 L2 = p3 - p2;
    const vec3 L3 = p0 - p3;
    const double len0_sq = length2(L0);
    const double len1_sq = length2(L1);
    const double len2_sq = length2(L2);
    const double len3_sq = length2(L3);
    if(len0_sq < EPS2 || len1_sq < EPS2 || len2_sq < EPS2 || len3_sq < EPS2)
      return -1.;
    const vec3 N0 = cross(L3, L0);
    const vec3 N1 = cross(L0, L1);
    const vec3 N2 = cross(L1, L2);
    const vec3 N3 = cross(L2, L3);
    const double a0 = dot(N, N0); /* bad if non planar quad ? */
    const double a1 = dot(N, N1);
    const double a2 = dot(N, N2);
    const double a3 = dot(N, N3);
    const double q0 = a0 / (len3_sq + len0_sq);
    const double q1 = a1 / (len0_sq + len1_sq);
    const double q2 = a2 / (len1_sq + len2_sq);
    const double q3 = a3 / (len2_sq + len3_sq);
    if(SHOW_QUALITY && (q0 < 0 || q1 < 0 || q2 < 0 || q3 < 0)) {
      DBG("------");
      DBG(len0_sq, len1_sq, len2_sq, len3_sq);
      DBG(N);
      DBG(N0, N1, N2, N3);
      DBG(q0, q1, q2, q3);
      vec3 mid = (p0 + p1 + p2 + p3) * 0.25;
      GeoLog::add(mid, N, "Ni");
      GeoLog::add(p0, N0, "Ni");
      GeoLog::add(p1, N1, "Ni");
      GeoLog::add(p2, N2, "Ni");
      GeoLog::add(p3, N3, "Ni");
      GeoLog::add({p0, p1, p2, p3}, 0., "quad");
      GeoLog::flush();
      gmsh::fltk::run();
      abort();
    }
    return 2. * std::min(std::min(q0, q1), std::min(q2, q3));
  }

  inline double
  computeQualityQuadOneRing(const vec5 &v, const OneRing &ring,
                            const vec3 &normal,
                            double breakIfBelowThreshold = -DBL_MAX)
  {
    if(ring.n % 2 != 0) return -DBL_MAX;
    double qmin = DBL_MAX;
    const vec3 p = {v[0], v[1], v[2]};
    for(uint32_t i = 0; i < ring.n / 2; ++i) {
      const vec3 p0 = {ring.p_uv[2 * i + 0][0], ring.p_uv[2 * i + 0][1],
                       ring.p_uv[2 * i + 0][2]};
      const vec3 p1 = {ring.p_uv[2 * i + 1][0], ring.p_uv[2 * i + 1][1],
                       ring.p_uv[2 * i + 1][2]};
      const size_t i2 = (2 * i + 2) % ring.n;
      const vec3 p2 = {ring.p_uv[i2][0], ring.p_uv[i2][1], ring.p_uv[i2][2]};
      const double q = quad_shape(p0, p1, p2, p, normal);
      qmin = std::min(q, qmin);
      if(qmin < breakIfBelowThreshold) return qmin;
    }
    return qmin;
  }

  inline double dist_abs(double a, double b) { return std::abs(a - b); }

  inline vec2 uv_adjust_jump(vec2 uv, const vec2 &uv_ref, const vec2 &jump)
  {
    for(uint32_t d = 0; d < 2; ++d)
      if(jump[d] != 0.) {
        if(uv[d] < uv_ref[d]) {
          double cand = uv[d] + jump[d];
          while(dist_abs(cand, uv_ref[d]) < dist_abs(uv[d], uv_ref[d])) {
            uv[d] = cand;
            cand = uv[d] + jump[d];
          }
        }
        else {
          double cand = uv[d] - jump[d];
          while(dist_abs(cand, uv_ref[d]) < dist_abs(uv[d], uv_ref[d])) {
            uv[d] = cand;
            cand = uv[d] - jump[d];
          }
        }
      }
    return uv;
  }

  inline double abs_diff_wperiod(double a, double b, double T)
  {
    if(T == 0.) return std::abs(a - b);
    return std::abs(fmod(a - b, T));
  }

  inline vec2 getDeltaUV(const vec5 &v, const OneRing &ring)
  {
    constexpr bool useBboxUV = false;
    bool periodic = (ring.jump[0] != 0. || ring.jump[1] != 0.);
    if(useBboxUV) {
      const vec2 uv_0 = {v[3], v[4]};
      double u_range[2] = {DBL_MAX, -DBL_MAX};
      double v_range[2] = {DBL_MAX, -DBL_MAX};
      for(uint32_t i = 0; i < ring.n; ++i) {
        vec2 uv_i = {ring.p_uv[i][3], ring.p_uv[i][4]};
        if(periodic) uv_i = uv_adjust_jump(uv_i, uv_0, ring.jump);
        u_range[0] = std::min(u_range[0], uv_i[0]);
        u_range[1] = std::max(u_range[1], uv_i[0]);
        v_range[0] = std::min(v_range[0], uv_i[1]);
        v_range[1] = std::max(v_range[1], uv_i[1]);
      }
      const double du = u_range[1] - u_range[0];
      const double dv = v_range[1] - v_range[0];
      return {du, dv};
    }
    else {
      bool periodic = (ring.jump[0] != 0. || ring.jump[1] != 0.);
      const vec2 uv_0 = {v[3], v[4]};
      double du = 0.;
      double dv = 0.;
      // DBG(uv_0, ring.jump);
      for(uint32_t i = 0; i < ring.n; ++i) {
        double duc = abs_diff_wperiod(
          ring.p_uv[i][3], ring.p_uv[(i + 1) % ring.n][3], ring.jump[0]);
        double dvc = abs_diff_wperiod(
          ring.p_uv[i][4], ring.p_uv[(i + 1) % ring.n][4], ring.jump[1]);
        if(ring.jump[0] > 0. && duc > 0.5 * ring.jump[0]) duc = 0.;
        if(ring.jump[1] > 0. && dvc > 0.5 * ring.jump[1]) dvc = 0.;
        du = std::max(du, duc);
        dv = std::max(dv, dvc);
      }
      return {2. * du, 2. * dv};
    }
  }

  inline double getRingDispMax(const vec5 &v, const OneRing &ring)
  {
    double dMax2 = 0.;
    for(uint32_t i = 0; i < ring.n; ++i) {
      vec3 p_i = {ring.p_uv[i][0], ring.p_uv[i][1], ring.p_uv[i][2]};
      vec3 p_n = {ring.p_uv[(i + 1) % ring.n][0],
                  ring.p_uv[(i + 1) % ring.n][1],
                  ring.p_uv[(i + 1) % ring.n][2]};
      dMax2 = std::max(dMax2, length2(p_i - p_n));
    }
    return std::sqrt(dMax2);
  }

  inline vec4 getGrid(const vec5 &v, vec2 deltaUV, size_t n, double w)
  {
    const vec2 uv_0 = {v[3], v[4]};
    const vec4 grid = {
      uv_0[0] - w * deltaUV[0], /* grid_u_min */
      uv_0[1] - w * deltaUV[1], /* grid_v_min */
      uv_0[0] + w * deltaUV[0], /* grid_u_max */
      uv_0[1] + w * deltaUV[1] /* grid_v_max */
    };
    return grid;
  }

  vec5 dmoOptimizeVertexPosition(GFace *gf, vec5 v, const OneRing &ring,
                                 size_t n, size_t nIter, vec3 normal,
                                 double &qmax)
  {
    double w = 0.5;
    if(qmax == DBL_MAX || qmax == -DBL_MAX) {
      /* Only compute input quality if not given */
      qmax = computeQualityQuadOneRing(v, ring, normal);
    }
    vec5 vmax = v;
    vec2 deltaUV = getDeltaUV(v, ring);

    /* Sanity check on the UV variation */
    if(ring.jump[0] > 0. && deltaUV[0] > 0.5 * ring.jump[0]) return v;
    if(ring.jump[1] > 0. && deltaUV[1] > 0.5 * ring.jump[1]) return v;
    if(deltaUV[0] > 0.05 * ring.range[0]) return v;
    if(deltaUV[1] > 0.05 * ring.range[1]) return v;

    const bool checkDisplacement = ring.jump[0] != 0. || ring.jump[1] != 0.;
    const double dispMax = checkDisplacement ? getRingDispMax(v, ring) : 0.;

    for(size_t iter = 0; iter < nIter; ++iter) {
      vec4 grid = getGrid(v, deltaUV, n, w);
      SPoint2 uv;
      for(size_t i = 0; i < n; ++i) {
        uv.data()[0] = double(i) / double(n - 1) * grid[0] +
                       double(n - 1 - i) / double(n - 1) * grid[2];
        for(size_t j = 0; j < n; ++j) {
          uv.data()[1] = double(j) / double(n - 1) * grid[1] +
                         double(n - 1 - j) / double(n - 1) * grid[3];
          GPoint newPos = gf->point(uv);
          if(!newPos.succeeded()) continue;
          if(checkDisplacement) {
            double disp = length(vec3{newPos.x(), newPos.y(), newPos.z()} -
                                 vec3{v[0], v[1], v[2]});
            // if (disp > 1 || dispMax > 1) {
            //   // DBG(disp, dispMax, v, deltaUV, uv, ring.jump);
            //   // abort();
            //   //gmsh::fltk::run();
            //   //abort();
            // }
            if(disp > dispMax) continue;
          }
          const vec5 v2 = {newPos.x(), newPos.y(), newPos.z(), uv.data()[0],
                           uv.data()[1]};
          double q2 = computeQualityQuadOneRing(v2, ring, normal, qmax);
          if(q2 > qmax) {
            vmax = v2;
            qmax = q2;
          }
        }
      }
      w = w * 2. / double(n - 1);
    }

    return vmax;
  }
} // namespace QMT
using namespace QMT;

void computeSICN(const std::vector<MElement *> &elements, double &sicnMin,
                 double &sicnAvg)
{
  sicnMin = DBL_MAX;
  sicnAvg = 0.;
  for(size_t i = 0; i < elements.size(); ++i) {
    double q = elements[i]->minSICNShapeMeasure();
    if(std::isnan(q)) { q = -1.; }
    sicnMin = std::min(sicnMin, q);
    sicnAvg += q;
  }
  if(elements.size() > 0) sicnAvg /= double(elements.size());
}

int patchOptimizeGeometryGlobal(GFaceMeshPatch &patch, GeomOptimStats &stats)
{
  GFace *gf = patch.gf;
  if(gf == NULL) return -1;
  if(!gf->haveParametrization()) {
    Msg::Debug("optimize geometry global: face %i have no parametrization",
               gf->tag());
    return -2;
  }
  if(patch.bdrVertices.size() != 1) {
    Msg::Debug(
      "optimize geometry global: patch has multiple boundary loops (%li)",
      patch.bdrVertices.size());
    return -1;
  }
  if(patch.intVertices.size() == 0) {
    Msg::Debug("optimize geometry global: no interior vertices (%li bdr "
               "vertices, %li elements)",
               patch.bdrVertices.front().size(), patch.elements.size());
    return -1;
  }

  bool debugCreateViews = DBG_VIZU_G;
  if(Msg::GetVerbosity() >= 999 &&
     CTX::instance()->debugSurface == patch.gf->tag()) {
    debugCreateViews = true;
  }
  const int rdi = (int)(((double)rand() / RAND_MAX) *
                        1e4); /* only to get a random name for debugging */

  double t1 = Cpu();

  std::unordered_map<MVertex *, size_t> old2new;
  std::vector<vector<size_t> > v2v;
  bool oks =
    buildCondensedStructure(patch.intVertices, patch.elements, old2new, v2v);
  if(!oks) {
    Msg::Debug("optimize geometry global: failed to build edge graph");
    return -1;
  }

  /* uvs/v2v: first all the free vertices, then the bdr vertices */
  vector<SPoint2> uvs(old2new.size(), SPoint2(DBL_MAX, DBL_MAX));
  /* Interior vertices initialized to (0,0) */
  size_t nInterior = patch.intVertices.size();
  for(size_t v = 0; v < nInterior; ++v) {
    sort_unique(v2v[v]);
    uvs[v] = SPoint2(0., 0.);
  }

  /* Boundary vertices */
  for(size_t loop = 0; loop < patch.bdrVertices.size(); ++loop) {
    vector<SPoint2> bndUvs;
    bool okl = getContinuousUVOnLoop(gf, patch.bdrVertices[loop], bndUvs);
    if(!okl) {
      Msg::Debug("optimize geometry global: failed to get continuous UV on "
                 "boundary loop");
      return -2;
    }
    for(size_t i = 0; i < patch.bdrVertices[loop].size(); ++i) {
      MVertex *v = patch.bdrVertices[loop][i];
      auto it = old2new.find(v);
      if(it == old2new.end()) {
        Msg::Error("optimize geometry global: bdr vertex not found in old2new");
        return -1;
      }
      size_t idx = it->second;
      if(uvs[idx].x() != DBL_MAX) continue;
      uvs[idx] = bndUvs[i];
      double dist =
        std::pow(bndUvs[(i + 1) % bndUvs.size()].x() - bndUvs[i].x(), 2) +
        std::pow(bndUvs[(i + 1) % bndUvs.size()].y() - bndUvs[i].y(), 2);
      dist = std::sqrt(dist);
    }
  }

  computeSICN(patch.elements, stats.sicnMinBefore, stats.sicnAvgBefore);

  /* Laplacian smoothing via linear system */
  bool ok = solveLaplaceLinearSystem(nInterior, v2v, uvs);
  if(!ok) {
    Msg::Warning("optimize geometry global: failed to solve linear system");
    return -1;
  }

  if(debugCreateViews) {
    GeoLog::add(patch.elements, "optim_Duv_IN_" + std::to_string(rdi) + "_" +
                                  std::to_string(stats.sicnAvgBefore));
  }

  /* Apply CAD mapping */
  for(MVertex *v : patch.intVertices) {
    size_t idx = old2new[v];
    SPoint2 uv = uvs[idx];
    v->setParameter(0, uv[0]);
    v->setParameter(1, uv[1]);
    GPoint p = gf->point(uv);
    if(p.succeeded()) { v->setXYZ(p.x(), p.y(), p.z()); }
    else {
      Msg::Error("optimize geometry global: CAD evaluation failed on face %i "
                 "at uv=(%f,%f)",
                 gf->tag(), uv[0], uv[1]);
    }
  }

  computeSICN(patch.elements, stats.sicnMinAfter, stats.sicnAvgAfter);

  if(debugCreateViews) {
    GeoLog::add(patch.elements, "optim_Duv_OUT_" + std::to_string(rdi) + "_" +
                                  std::to_string(stats.sicnAvgAfter));
  }

  double t2 = Cpu();
  stats.timeCpu = t2 - t1;
  stats.nFree = patch.intVertices.size();
  stats.nLock = patch.bdrVertices.front().size();

  Msg::Debug(
    "optimize geometry global (UV Laplacian): %li/%li free vertices, %li "
    "elements, SICN min: %.3f -> %.3f, SICN avg: %.3f -> %.3f, time: %.3fsec",
    patch.intVertices.size(),
    patch.intVertices.size() + patch.bdrVertices.front().size(),
    patch.elements.size(), stats.sicnMinBefore, stats.sicnMinAfter,
    stats.sicnAvgBefore, stats.sicnAvgAfter, stats.timeCpu);

  return 0;
}

bool kernelLoopWithParametrization(GFaceMeshPatch &patch,
                                   const GeomOptimOptions &opt,
                                   GeomOptimStats &stats)
{
  GFace *gf = patch.gf;
  if(!gf->haveParametrization()) {
    Msg::Error("optimize geometry kernel: face %i have no parametrization",
               gf->tag());
    return false;
  }

  /* Data for smoothing */
  std::vector<vec5> point_uv;
  std::vector<size_t> one_ring_first;
  std::vector<uint32_t> one_ring_values;
  std::vector<MVertex *> new2old;
  bool okb = buildUVSmoothingDataStructures(
    gf, patch.elements, patch.intVertices, point_uv, one_ring_first,
    one_ring_values, new2old);
  if(!okb) {
    Msg::Warning(
      "optimize geometry kernel: failed to build adjacency datastructures");
    return false;
  }
  OneRing ring;
  std::vector<vec5> ringGeometric(10);
  if(gf->periodic(0)) ring.jump[0] = gf->period(0);
  if(gf->periodic(1)) ring.jump[1] = gf->period(1);
  ring.range[0] = gf->parBounds(0).high() - gf->parBounds(0).low();
  ring.range[1] = gf->parBounds(1).high() - gf->parBounds(1).low();
  ring.p_uv = ringGeometric.data();
  const double sign = opt.invertCADNormals ? -1. : 1.;

  size_t dmo_grid_width = 8;
  size_t dmo_grid_depth = 3;
  if(!haveNiceParametrization(gf)) {
    dmo_grid_width = 12;
    dmo_grid_depth = 4;
  }

  /* Initialization: all vertices unlocked */
  std::vector<bool> locked(patch.intVertices.size(), false);
  if(opt.qualityRangeTechnique) {
    std::fill(locked.begin(), locked.end(), true);
  }

  /* Explicit smoothing loop */
  const size_t nFree = patch.intVertices.size();
  for(size_t iter = 0; iter < opt.outerLoopIterMax; ++iter) {
    size_t nMoved = 0;
    double iterQmin = 1.;

    /* Loop over interior vertices */
    for(size_t v = 0; v < nFree; ++v) {
      /* Fill the OneRing geometric information */
      ring.n = one_ring_first[v + 1] - one_ring_first[v];
      if(ring.n >= ringGeometric.size()) {
        ringGeometric.resize(ring.n);
        ring.p_uv = ringGeometric.data();
      }
      for(size_t lv = 0; lv < ring.n; ++lv) {
        ring.p_uv[lv] = point_uv[one_ring_values[one_ring_first[v] + lv]];
      }

      /* Current position, normal and quality */
      vec5 pos = point_uv[v];
      vec3 normal = sign * gf->normal(SPoint2(pos[3], pos[4]));
      if(length2(normal) == 0.) {
        Msg::Warning("optimize geometry kernel: CAD normal length is 0 !");
        continue;
      }
      normalize(normal);
      double quality = computeQualityQuadOneRing(pos, ring, normal);

      if(opt.qualityRangeTechnique && iter == 0) {
        /* First iteration: unlocked low quality vertices */
        if(quality < opt.qualityRangeMin) { locked[v] = false; }
        else {
          continue;
        }
      }
      if(opt.qualityRangeTechnique && quality > opt.qualityRangeMax) {
        locked[v] = true;
        continue;
      }

      /* Optimize vertex position with DMO (adaptive grid sampling) */
      if(opt.qualityRangeTechnique || quality < opt.useDmoIfSICNbelow) {
        vec5 newPos = dmoOptimizeVertexPosition(
          gf, pos, ring, dmo_grid_width, dmo_grid_depth, normal, quality);
        point_uv[v] = newPos;
        iterQmin = std::min(iterQmin, quality);
        nMoved += 1;
      }

      if(opt.qualityRangeTechnique) {
        if(quality > opt.qualityRangeTechnique) {
          locked[v] = true;
          continue;
        }
        else { /* Unlock neighbors ! */
          for(size_t lv = 0; lv < ring.n; ++lv) {
            uint32_t v2 = one_ring_values[one_ring_first[v] + lv];
            if(v2 < nFree) locked[v2] = false;
          }
        }
      }
      else {
        // TODO: lock vertex is local dx reduction
      }
    }
    // DBG(iter, nMoved, iterQmin);
  }

  /* Update the positions */
  for(size_t i = 0; i < patch.intVertices.size(); ++i) {
    new2old[i]->setParameter(0, point_uv[i][3]);
    new2old[i]->setParameter(1, point_uv[i][4]);
    new2old[i]->setXYZ(point_uv[i][0], point_uv[i][1], point_uv[i][2]);
  }

  return true;
}

bool movePointWithKernelAndProjection(
  uint32_t v, const std::vector<std::array<double, 3> > &points,
  const std::vector<size_t> &one_ring_first,
  const std::vector<uint32_t> &one_ring_values,
  const SmoothingKernel &kernelRegular, const SmoothingKernel &kernelIrregular,
  bool project, SurfaceProjector *sp, vec3 &newPos, vec2 &newUv,
  bool smartVariant = false)
{
  if(project && sp == nullptr) {
    Msg::Error("cannot project with surface projector");
    return false;
  }

  size_t n = one_ring_first[v + 1] - one_ring_first[v];

  GPoint proj;
  double stDx = 0.;
  double sicnMinB = 0.; /* only used if smartVariant */
  double sicnMinA = 0.; /* only used if smartVariant */
  if(n == 8 && kernelRegular ==
                 SmoothingKernel::WinslowFDM) { /* Winslow for regular vertex */
    /* Extract geometric stencil */
    std::array<vec3, 8> stencil =
      fillStencilRegular(v, points, one_ring_first, one_ring_values);
    if(smartVariant) {
      sicnMinB = stencilQualitySICNmin(points[v], stencil);
      if(sicnMinB < 0.3)
        sicnMinB = stencilQualitySICNminGmsh(points[v], stencil);
    }

    /* Smoothing (in 3D, not on surface) */
    bool ok = kernelWinslow(stencil, newPos);
    if(!ok) return false;

    if(project) { /* Projection on surface */
      proj = sp->closestPoint(newPos.data(), false, false);
      if(!proj.succeeded()) {
        Msg::Debug("kernel smoothing: projection failed");
        return false;
      }
      newPos = {proj.x(), proj.y(), proj.z()};
      newUv = {proj.u(), proj.v()};
    }

    if(smartVariant) {
      sicnMinA = stencilQualitySICNmin(newPos, stencil);
      if(sicnMinA < 0.3) sicnMinA = stencilQualitySICNminGmsh(newPos, stencil);
    }
  }
  else { /* irregular vertex */
    std::vector<vec3> stencilIrreg(8);

    bool angleBased = false;
    if(n > 4 && n % 2 == 0) {
      if(n == 8 && kernelRegular == AngleBased) { angleBased = true; }
      else if(kernelIrregular == AngleBased) {
        angleBased = true;
      }
    }

    /* Extract geometric stencil */
    bool oneOverTwo = angleBased; /* angle-based does not use diagonals */
    fillStencilIrregular(v, points, one_ring_first, one_ring_values,
                         stencilIrreg, oneOverTwo);

    if(smartVariant) {
      std::vector<vec3> stencilIrregFull = stencilIrreg;
      if(oneOverTwo) {
        fillStencilIrregular(v, points, one_ring_first, one_ring_values,
                             stencilIrregFull, false);
      }
      sicnMinB = stencilQualitySICNmin(points[v], stencilIrregFull);
      if(sicnMinB < 0.3)
        sicnMinB = stencilQualitySICNminGmsh(points[v], stencilIrregFull);
    }

    /* Smoothing (in 3D, not on surface) */
    bool ok = false;
    if(angleBased) { ok = kernelAngleBased(points[v], stencilIrreg, newPos); }
    else {
      ok = kernelLaplacian(stencilIrreg, newPos);
    }
    if(!ok) return false;

    if(project) { /* Projection on surface */
      proj = sp->closestPoint(newPos.data(), false, false);
      if(!proj.succeeded()) {
        Msg::Debug("kernel smoothing: projection failed");
        return false;
      }
      newPos = {proj.x(), proj.y(), proj.z()};
      newUv = {proj.u(), proj.v()};
    }

    if(smartVariant) {
      std::vector<vec3> stencilIrregFull = stencilIrreg;
      if(oneOverTwo) {
        fillStencilIrregular(v, points, one_ring_first, one_ring_values,
                             stencilIrregFull, false);
      }
      sicnMinA = stencilQualitySICNmin(newPos, stencilIrregFull);
      if(sicnMinA < 0.3)
        sicnMinA = stencilQualitySICNminGmsh(newPos, stencilIrregFull);
    }
  }
  if(smartVariant && sicnMinA < sicnMinB) return false;
  return true;
}

bool kernelLoopWithProjection(GFaceMeshPatch &patch,
                              const GeomOptimOptions &opt,
                              GeomOptimStats &stats,
                              bool finalCADprojection = false)
{
  GFace *gf = patch.gf;
  if(opt.sp == nullptr) {
    Msg::Error("kernel loop with projection: no surface projector");
    return false;
  }

  /* Data for smoothing */
  std::vector<size_t> one_ring_first;
  std::vector<uint32_t> one_ring_values;
  std::vector<MVertex *> new2old;
  std::unordered_map<MVertex *, uint32_t> old2new;
  std::vector<std::array<double, 3> > points;
  {
    std::vector<std::array<uint32_t, 4> > quads;
    std::vector<std::vector<uint32_t> > v2q;
    std::vector<std::vector<uint32_t> > oneRings;
    bool okc =
      buildCondensedStructure(patch.elements, patch.intVertices, old2new,
                              new2old, quads, v2q, oneRings, points);
    if(!okc) {
      Msg::Warning(
        "kernelLoopWithProjection: failed to build condensed representation");
      return false;
    }
    compress(oneRings, one_ring_first, one_ring_values);
  }
  const size_t nFree = patch.intVertices.size();

  std::vector<std::array<double, 2> > point_uvs;
  if(gf->haveParametrization()) {
    point_uvs.resize(points.size());
    for(size_t v = 0; v < nFree; ++v) {
      new2old[v]->getParameter(0, point_uvs[v][0]);
      new2old[v]->getParameter(1, point_uvs[v][1]);
    }
  }

  /* Local sizes */
  vector<double> localAvgSize(nFree, 0.);
  for(size_t v = 0; v < nFree; ++v) {
    size_t n = one_ring_first[v + 1] - one_ring_first[v];
    if(n == 0) continue;
    for(size_t lv = 0; lv < n; ++lv) {
      uint32_t v2 = one_ring_values[one_ring_first[v] + lv];
      localAvgSize[v] += length(points[v] - points[v2]);
    }
    localAvgSize[v] /= double(n);
  }

  bool project = opt.project;
  if(opt.project && gf->geomType() == GFace::GeomType::Plane) project = false;

  /* Initialization: all vertices unlocked */
  std::vector<bool> locked(patch.intVertices.size(), false);

  /* Explicit smoothing loop */
  double t0 = Cpu();
  double sum_dx0 = 0;
  std::vector<vec3> stencilIrreg(10);
  for(size_t iter = 0; iter < opt.outerLoopIterMax; ++iter) {
    size_t nMoved = 0;

    double sum_dx = 0.;
    /* Loop over interior vertices */
    for(size_t v = 0; v < nFree; ++v) {
      if(locked[v]) continue;

      vec3 newPos = points[v];
      vec2 newUv;
      if(point_uvs.size()) { newUv = point_uvs[v]; }

      bool ok = movePointWithKernelAndProjection(
        v, points, one_ring_first, one_ring_values, opt.kernelRegular,
        opt.kernelIrregular, project, opt.sp, newPos, newUv);
      if(ok) {
        double dx = length(newPos - points[v]);
        sum_dx += dx;
        /* Modify the coordinates */
        points[v] = newPos;
        if(point_uvs.size()) point_uvs[v] = newUv;
        if(opt.localLocking && dx < opt.dxLocalMax * localAvgSize[v]) {
          locked[v] = true;
        }
        else {
          nMoved += 1;
        }
      }
      else {
        locked[v] = true;
      }
    }

    if(iter == 0) { sum_dx0 = sum_dx; }
    else {
      if(sum_dx < opt.dxGlobalMax * sum_dx0) {
        Msg::Debug("kernelLoopWithProjection: stop at iter %li/%li because "
                   "sum_dx = %f < %f",
                   iter, opt.outerLoopIterMax, sum_dx,
                   opt.dxGlobalMax * sum_dx0);
        break;
      }
      if(nMoved == 0) {
        Msg::Debug("kernelLoopWithProjection: stop at iter %li/%li because no "
                   "point moved",
                   iter, opt.outerLoopIterMax);
        break;
      }
    }

    if(Cpu() - t0 > opt.timeMax) {
      Msg::Debug("kernelLoopWithProjection: stop at iter %li/%li because "
                 "timeout (%f sec)",
                 iter, opt.outerLoopIterMax, Cpu() - t0);
      break;
    }
  }

  /* Update the positions */
  for(size_t i = 0; i < patch.intVertices.size(); ++i) {
    MVertex *v = new2old[i];
    v->setXYZ(points[i][0], points[i][1], points[i][2]);
    if(point_uvs.size()) {
      v->setParameter(0, point_uvs[i][0]);
      v->setParameter(1, point_uvs[i][1]);

      if(finalCADprojection) {
        SPoint3 query = v->point();
        GPoint proj = gf->closestPoint(query, point_uvs[i].data());
        if(proj.succeeded()) {
          v->setXYZ(proj.x(), proj.y(), proj.z());
          v->setParameter(0, proj.u());
          v->setParameter(1, proj.v());
        }
      }
    }
  }

  return true;
}

vec3 quad_opposite_right_angled_corner(vec3 pPrev, vec3 pCorner, vec3 pNext)
{
  double radius = 0.5 * length(pPrev - pNext);
  vec3 center = 0.5 * (pPrev + pNext);
  if(length(center - pCorner) < 1.e-10) { return center; }
  vec3 dir = center - pCorner;
  normalize(dir);
  return center + radius * dir;
}

bool quadMeshSpecialAcuteCornerOptimization(GFace *gf,
                                            SurfaceProjector *sp = nullptr)
{
  std::unordered_map<MVertex *, int> bdrVal;
  std::unordered_map<MVertex *, double> bdrAgl;
  std::unordered_map<MVertex *, std::vector<MQuadrangle *> > corner2quads;
  std::unordered_map<MVertex *, std::vector<MQuadrangle *> > v2quads;
  for(MQuadrangle *q : gf->quadrangles) {
    bool keep = false;
    for(size_t lv = 0; lv < 4; ++lv) {
      MVertex *v = q->getVertex(lv);
      if(v->onWhat() != nullptr && v->onWhat()->dim() < 2) {
        bdrVal[v] += 1;
        MVertex *vp = q->getVertex((lv - 1 + 4) % 4);
        MVertex *vn = q->getVertex((lv + 1) % 4);
        double agl = std::abs(angle3Vertices(vp, v, vn));
        bdrAgl[v] += agl;
        if(v->onWhat()->dim() == 0) {
          corner2quads[v].push_back(q);
          keep = true;
        }
      }
    }
    if(keep) {
      for(size_t lv = 0; lv < 4; ++lv) {
        MVertex *v = q->getVertex(lv);
        v2quads[v].push_back(q);
      }
    }
  }

  size_t nMoved = 0;
  for(auto &kv : corner2quads)
    if(kv.second.size() == 1) {
      MVertex *v = kv.first;
      MQuadrangle *q = kv.second[0];
      double agl = bdrAgl[v];
      if(agl * 180. / M_PI > 30) continue; // not acute corner
      for(size_t lv = 0; lv < 4; ++lv) {
        MVertex *vc = q->getVertex(lv);
        if(vc != v) continue;
        MVertex *vp = q->getVertex((lv - 1 + 4) % 4);
        MVertex *vn = q->getVertex((lv + 1) % 4);
        MVertex *vo = q->getVertex((lv + 2) % 4);
        if(vo->onWhat() != nullptr && vo->onWhat()->dim() != 2) continue;

        const bool BY_OPTIM = true;
        bool oku = false;
        if(BY_OPTIM) {
          GFaceMeshPatch patch;
          bool okp = patchFromQuads(gf, v2quads[vo], patch);
          if(!okp) continue;
          bool backupRestore = true;
          GeometryOptimizer optu;
          optu.initialize(patch);
          bool projectOnCad = true;
          size_t iter = 10;
          GeometryOptimizer::PlanarMethod method =
            GeometryOptimizer::PlanarMethod::MeanPlane;
          oku = optu.smoothWithWinslowUntangler(method, iter, backupRestore,
                                                projectOnCad);
        }

        if(!oku) {
          double sige_before = q->minSIGEShapeMeasure();
          SPoint3 backup = vc->point();
          vec3 pp = vp->point();
          vec3 pc = vc->point();
          vec3 pn = vn->point();
          vec3 po = quad_opposite_right_angled_corner(pp, pc, pn);
          vo->setXYZ(po[0], po[1], po[2]);
          if(sp) {
            GPoint proj = sp->closestPoint(po.data(), false, false);
            if(proj.succeeded()) { vo->setXYZ(proj.x(), proj.y(), proj.z()); }
          }
          double sige_after = q->minSIGEShapeMeasure();
          if(sige_after < sige_before) {
            vo->setXYZ(backup.x(), backup.y(), backup.z());
          }
          else {
            nMoved += 1;
          }
        }
      }
    }
  Msg::Debug(
    "- acute corners, set right-angle position of %li interior vertices",
    nMoved);

  return true;
}

size_t nbVerticesOnBoundary(const GFaceMeshPatch &patch)
{
  size_t n = 0;
  for(size_t i = 0; i < patch.bdrVertices.size(); ++i)
    n += patch.bdrVertices[i].size();
  return n;
}

bool patchOptimizeGeometryWithKernel(GFaceMeshPatch &patch,
                                     const GeomOptimOptions &opt,
                                     GeomOptimStats &stats)
{
  /* Debug visualization */
  bool debugCreateViews = DBG_VIZU_K;
  if(Msg::GetVerbosity() >= 999 &&
     CTX::instance()->debugSurface == patch.gf->tag()) {
    debugCreateViews = true;
  }
  const int rdi = (int)(((double)rand() / RAND_MAX) *
                        1e4); /* only to get a random name for debugging */

  GFace *gf = patch.gf;
  if(gf == NULL || patch.elements.size() == 0) return false;
  if(patch.intVertices.size() == 0) return false;

  stats.sicnMinBefore = -1.; /* if no element */
  stats.sicnAvgBefore = -1.;
  double t1 = Cpu();
  computeSICN(patch.elements, stats.sicnMinBefore, stats.sicnAvgBefore);

  if(patch.intVertices.size() == 0) {
    Msg::Debug("optimize geometry kernel: no interior vertices (%li elements)",
               patch.elements.size());
    stats.sicnMinAfter = stats.sicnMinBefore;
    stats.sicnAvgAfter = stats.sicnAvgBefore;
    return true;
  }

  PatchGeometryBackup *backup = nullptr;
  if(opt.withBackup) { backup = new PatchGeometryBackup(patch); }

  bool useParam = gf->haveParametrization();
  if(opt.sp != nullptr) useParam = false;
  if(opt.force3DwithProjection) useParam = false;

  if(debugCreateViews) {
    std::string method =
      "K" + (useParam ? std::string("uv") : std::string("3d+p"));
    GeoLog::add(patch.elements, "optim_" + method + "_IN_" +
                                  std::to_string(rdi) + "_" +
                                  std::to_string(stats.sicnAvgBefore));
  }

  if(useParam) {
    bool okl = kernelLoopWithParametrization(patch, opt, stats);
    if(!okl) {
      Msg::Warning(
        "optimize geometry kernel: the loop with param. failed (%li elements)",
        patch.elements.size());
      return -1;
    }
  }
  else {
    bool okl = kernelLoopWithProjection(patch, opt, stats);
    if(!okl) {
      Msg::Warning("optimize geometry kernel: the loop with projection failed "
                   "(%li elements)",
                   patch.elements.size());
      return -1;
    }
  }

  /* Statistics */
  computeSICN(patch.elements, stats.sicnMinAfter, stats.sicnAvgAfter);

  bool cancel = false;

  if(opt.withBackup && backup && stats.sicnMinAfter < stats.sicnMinBefore) {
    Msg::Debug("optimize geometry kernel: restore patch geometry with backup",
               patch.elements.size());
    backup->restore();
    stats.sicnMinAfter = stats.sicnMinBefore;
    stats.sicnAvgAfter = stats.sicnAvgBefore;
    cancel = true;
  }

  /* Debug visualization */
  if(debugCreateViews) {
    std::string method =
      "K" + (useParam ? std::string("uv") : std::string("3d+p"));
    GeoLog::add(patch.elements, "optim_" + method + "_OUT_" +
                                  std::to_string(rdi) + "_" +
                                  std::to_string(stats.sicnAvgAfter));
    GeoLog::flush();
  }

  double t2 = Cpu();
  stats.timeCpu = t2 - t1;
  stats.nFree = patch.intVertices.size();
  stats.nLock = nbVerticesOnBoundary(patch);

  if(backup) delete backup;

  if(cancel) return true;

  if(useParam) {
    Msg::Debug(
      "optimize geometry kernel (using CAD param): %li/%li free vertices, %li "
      "elements, SICN min: %.3f -> %.3f, SICN avg: %.3f -> %.3f, time: %.3fsec",
      patch.intVertices.size(), stats.nFree + stats.nLock,
      patch.elements.size(), stats.sicnMinBefore, stats.sicnMinAfter,
      stats.sicnAvgBefore, stats.sicnAvgAfter, stats.timeCpu);
  }
  else {
    Msg::Debug("optimize geometry kernel (using triangulation): %li/%li free "
               "vertices, %li elements, SICN min: %.3f -> %.3f, SICN avg: %.3f "
               "-> %.3f, time: %.3fsec",
               patch.intVertices.size(), stats.nFree + stats.nLock,
               patch.elements.size(), stats.sicnMinBefore, stats.sicnMinAfter,
               stats.sicnAvgBefore, stats.sicnAvgAfter, stats.timeCpu);
  }

  return true;
}

bool patchProjectOnSurface(GFaceMeshPatch &patch, SurfaceProjector *sp)
{
  Msg::Debug("patch surface projection (%i vertices) ...",
             patch.intVertices.size());
  bool useParam = patch.gf->haveParametrization();
  for(MVertex *v : patch.intVertices) {
    GPoint proj;
    if(sp != nullptr) {
      /* Triangulation projection */
      proj = sp->closestPoint(v->point().data(), false, false);
      if(proj.succeeded()) { v->setXYZ(proj.x(), proj.y(), proj.z()); }
      if(useParam) {
        /* CAD projection */
        double uv[2] = {proj.u(), proj.v()};
        GPoint proj2 = patch.gf->closestPoint(v->point(), uv);
        if(proj2.succeeded()) {
          v->setXYZ(proj2.x(), proj2.y(), proj2.z());
          v->setParameter(0, proj2.u());
          v->setParameter(1, proj2.v());
        }
      }
    }
    else if(useParam) {
      double uv[2];
      v->getParameter(0, uv[0]);
      v->getParameter(1, uv[1]);
      /* CAD projection */
      GPoint proj2 = patch.gf->closestPoint(v->point(), uv);
      if(proj2.succeeded()) {
        v->setXYZ(proj2.x(), proj2.y(), proj2.z());
        v->setParameter(0, proj2.u());
        v->setParameter(1, proj2.v());
      }
    }
    else {
      Msg::Error(
        "patch projection: no parametrization and no surface projector");
      return false;
    }
  }
  return true;
}

bool optimizeGeometryQuadMesh(GFace *gf, SurfaceProjector *sp, double timeMax,
                              bool withBackup)
{
  // TODO FIXME: replace by optimizeGeometryQuadTriMesh when it works well

  if(!gf->haveParametrization() && sp == nullptr) {
    Msg::Error("optimize geometry: face %i, no CAD and no surface projector",
               gf->tag());
    return false;
  }

  if(gf->quadrangles.size() == 0) {
    Msg::Error("optimize geometry: face %i, no quads", gf->tag());
    return false;
  }

  bool forceEvenIfBadBoundary = true;
  GFaceMeshPatch patch;
  bool okp = patchFromQuads(gf, gf->quadrangles, patch, forceEvenIfBadBoundary);
  if(!okp) {
    Msg::Warning("optimize geometry: face %i, failed to build patch",
                 gf->tag());
    return false;
  }

  bool debugCreateViews = DBG_VIZU_G;
  if(Msg::GetVerbosity() >= 999 &&
     CTX::instance()->debugSurface == patch.gf->tag()) {
    debugCreateViews = true;
  }
  const int rdi = (int)(((double)rand() / RAND_MAX) *
                        1e4); /* only to get a random name for debugging */

  /* Idea is to try many things (with backups each time):
   * - if planar: Winslow untangler
   * - else:
   *   - if CAD: try Winslow untangler in uv
   *   - try Winslow untangler on mean plane
   * - kernel smoother with proj
   */

  bool backupRestore = true;
  GeometryOptimizer optu;
  optu.initialize(patch, sp);
  bool oku = false;
  if(gf->geomType() == GEntity::Plane || !gf->haveParametrization()) {
    /* Winslow untangler on mean plane */
    size_t iter = 10;
    bool projectOnCad = true;
    GeometryOptimizer::PlanarMethod method =
      GeometryOptimizer::PlanarMethod::MeanPlane;
    oku = optu.smoothWithWinslowUntangler(method, iter, backupRestore,
                                          projectOnCad);
  }
  else if(gf->haveParametrization()) {
    /* Winslow untangler on uv param */
    size_t iter = 10;
    bool projectOnCad = true;
    GeometryOptimizer::PlanarMethod method =
      GeometryOptimizer::PlanarMethod::ParamCAD;
    // TODOMX: untangler in UV disabled for the moment
    //         should enable it only if param has no large distortion ?
    // oku = optu.smoothWithWinslowUntangler(method, iter, backupRestore,
    // projectOnCad);
    if(!oku) { /* try mean plane ... */
      method = GeometryOptimizer::PlanarMethod::MeanPlane;
      oku = optu.smoothWithWinslowUntangler(method, iter, backupRestore,
                                            projectOnCad);
    }
  }

  double minSICN = DBL_MAX;
  double avgSICN = 0.;
  computeSICN(patch.elements, minSICN, avgSICN);
  if(!oku || minSICN < 0.5) {
    int countMax = 3;
    bool running = true;
    size_t niter = 50;
    int count = 0;
    if(gf->geomType() == GEntity::Plane) {
      /* Much faster projection, we can smooth */
      niter = 100;
    }
    GeomOptimOptions opt;
    opt.sp = sp;
    opt.outerLoopIterMax = niter;
    opt.timeMax = timeMax;
    opt.localLocking = true;
    opt.dxGlobalMax = 1.e-3;
    opt.dxLocalMax = 1.e-5;
    opt.force3DwithProjection = true;
    opt.withBackup = false;
    SmoothingKernel kernelRegular = SmoothingKernel::WinslowFDM;

    if(false && gf->tag() == 100170) {
      Msg::Warning("SPECIAL SMOOTHING FOR DEBUGGING");
      niter = 100;
      countMax = 5;
      opt.dxGlobalMax = 1.e-5;
      opt.dxLocalMax = 1.e-7;
      kernelRegular = SmoothingKernel::Laplacian;
    }

    double t0 = Cpu();

    bool smartVariant = false;
    while(running && count < countMax) {
      running = false;
      count += 1;
      if(Cpu() - t0 > timeMax) {
        Msg::Debug("optimize geometry: face %i, reached time limit", gf->tag());
        break;
      }

      PatchGeometryBackup backup(patch);
      double minSICNb = DBL_MAX;
      double avgSICNb = 0.;
      computeSICN(patch.elements, minSICNb, avgSICNb);

      bool finalCADprojection = false;
      double t1 = Cpu();
      optu.smoothWithKernel(kernelRegular, SmoothingKernel::Laplacian, timeMax,
                            niter, false, true, 1.e-5, 1.e-3, true,
                            finalCADprojection, smartVariant);

      double etime = Cpu() - t1;
      double minSICNa = DBL_MAX;
      double avgSICNa = 0.;
      computeSICN(patch.elements, minSICNa, avgSICNa);

      bool keep = true;
      if(minSICNa < minSICNb && avgSICNa < avgSICNb) keep = false;
      if(minSICNa < 0.1 && minSICNa < minSICNb) keep = false;
      if(minSICNa < 0.75 * minSICNb) keep = false;

      if(false && gf->tag() == 100170) {
        Msg::Warning("SPECIAL SMOOTHING FOR DEBUGGING");
        keep = true;
        niter *= 1.5;
        running = true;
      }

      if(keep) {
        Msg::Debug("- Face %i: kernel smoothing (Mix Winslow/Angle, explicit "
                   "with projections, %li vertices, %li iter max, %.3f sec), "
                   "SICN min: %f -> %f, avg: %f -> %f",
                   gf->tag(), gf->mesh_vertices.size(), niter, etime, minSICNb,
                   minSICNa, avgSICNb, avgSICNa);
        if(minSICNa >= minSICNb && 0.99 * avgSICNa > avgSICNb && etime < 1) {
          niter *= 1.5;
          running = true;
        }
      }
      else {
        if(smartVariant) {
          /* Already using smart variant, time to stop .. */
          Msg::Debug("- Face %i: worst quality after global smoothing (Mix "
                     "Winslow/Angle, explicit, %li iter max), roll back (SICN "
                     "min: %f -> %f, avg: %f -> %f)",
                     gf->tag(), niter, minSICNb, minSICNa, avgSICNb, avgSICNa);
          if(withBackup) { backup.restore(); }
          break;
        }
        else {
          Msg::Debug("- Face %i: worst quality after global smoothing (Mix "
                     "Winslow/Angle, explicit, %li iter max), roll back, try "
                     "smart (SICN min: %f -> %f, avg: %f -> %f)",
                     gf->tag(), niter, minSICNb, minSICNa, avgSICNb, avgSICNa);
          if(withBackup) { backup.restore(); }
          /* Try to smooth with smart variant ... */
          running = true;
          smartVariant = true;
          count -= 1;
        }
      }
    }
  }

  double minSICNf = DBL_MAX;
  double avgSICNf = 0.;
  computeSICN(patch.elements, minSICNf, avgSICNf);
  Msg::Info("- Face %i: SICN min: %f -> %f, avg: %f -> %f", gf->tag(), minSICN,
            minSICNf, avgSICN, avgSICNf);

  return true;
}

bool optimizeGeometryQuadTriMesh(GFace *gf, SurfaceProjector *sp,
                                 double timeMax)
{
  // TODO FIXME: replace by optimizeGeometryQuadMesh when it works well

  if(!gf->haveParametrization() && sp == nullptr) {
    Msg::Error("optimize geometry: face %i, no CAD and no surface projector",
               gf->tag());
    return false;
  }

  if(gf->quadrangles.size() == 0) {
    Msg::Error("optimize geometry: face %i, no quads", gf->tag());
    return false;
  }

  bool forceEvenIfBadBoundary = true;
  GFaceMeshPatch patch;
  std::vector<MElement *> elements =
    dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles);
  append(elements, dynamic_cast_vector<MTriangle *, MElement *>(gf->triangles));
  bool okp = patchFromElements(gf, elements, patch, forceEvenIfBadBoundary);
  if(!okp) {
    Msg::Warning("optimize geometry: face %i, failed to build patch",
                 gf->tag());
    return false;
  }

  bool debugCreateViews = DBG_VIZU_G;
  if(Msg::GetVerbosity() >= 999 &&
     CTX::instance()->debugSurface == patch.gf->tag()) {
    debugCreateViews = true;
  }
  const int rdi = (int)(((double)rand() / RAND_MAX) *
                        1e4); /* only to get a random name for debugging */

  int countMax = 3;
  bool running = true;
  size_t niter = 50;
  int count = 0;
  if(gf->geomType() == GEntity::Plane) {
    /* Much faster projection, we can smooth */
    niter = 100;
  }

  double t0 = Cpu();

  while(running && count < countMax) {
    running = false;
    count += 1;
    if(Cpu() - t0 > timeMax) {
      Msg::Debug("optimize geometry: face %i, reached time limit", gf->tag());
      break;
    }

    PatchGeometryBackup backup(patch);

    double minSICNb = DBL_MAX;
    double avgSICNb = 0.;
    computeSICN(patch.elements, minSICNb, avgSICNb);

    if(debugCreateViews) {
      std::string method = "GFace_K";
      GeoLog::add(patch.elements, "optim_" + method + "_IN_" +
                                    std::to_string(rdi) + "_" +
                                    std::to_string(minSICNb));
    }

    GeomOptimStats stats;
    GeomOptimOptions opt;
    opt.sp = sp;
    opt.outerLoopIterMax = niter;
    opt.timeMax = timeMax;
    opt.localLocking = true;
    opt.dxGlobalMax = 1.e-3;
    opt.dxLocalMax = 1.e-5;
    opt.force3DwithProjection = true;
    opt.withBackup = false;
    double t1 = Cpu();
    bool okk = kernelLoopWithProjection(patch, opt, stats);
    if(!okk) { return false; }
    double etime = Cpu() - t1;

    double minSICNa = DBL_MAX;
    double avgSICNa = 0.;
    computeSICN(patch.elements, minSICNa, avgSICNa);

    bool keep = true;
    if(minSICNa < minSICNb && avgSICNa < avgSICNb) keep = false;
    if(minSICNa < 0.1 && minSICNa < minSICNb) keep = false;
    if(minSICNa < 0.75 * minSICNb) keep = false;

    if(debugCreateViews) {
      std::string method = "GFace_K";
      GeoLog::add(patch.elements,
                  "optim_" + method + "_OUT_" + std::to_string(rdi) + "_" +
                    std::to_string(minSICNa) + "_keep=" + std::to_string(keep));
    }

    if(keep) {
      Msg::Debug("- Face %i: kernel smoothing (Mix Winslow/Angle, explicit "
                 "with projections, %li vertices, %li iter max, %.3f sec), "
                 "SICN min: %f -> %f, avg: %f -> %f",
                 gf->tag(), gf->mesh_vertices.size(), niter, etime, minSICNb,
                 minSICNa, avgSICNb, avgSICNa);
      if(minSICNa >= minSICNb && 0.99 * avgSICNa > avgSICNb && etime < 1) {
        niter *= 1.5;
        running = true;
      }
    }
    else {
      Msg::Debug("- Face %i: worst quality after global smoothing (Mix "
                 "Winslow/Angle, explicit, %li iter max), roll back (SICN min: "
                 "%f -> %f, avg: %f -> %f)",
                 gf->tag(), niter, minSICNb, minSICNa, avgSICNb, avgSICNa);
      backup.restore();
      break;
    }
  }

  return true;
}

bool GeometryOptimizer::initialize(GFaceMeshPatch &patch, SurfaceProjector *_sp)
{
  std::vector<std::vector<uint32_t> > v2q;
  std::vector<std::vector<uint32_t> > oneRings;
  patchPtr = &patch;
  sp = _sp;
  bool okc = buildCondensedStructure(patch.elements, patch.intVertices, old2new,
                                     new2old, quads, v2q, oneRings, points);
  if(!okc) {
    Msg::Warning(
      "GeometryOptimizer initialize: failed to build condensed representation");
    return false;
  }
  compress(oneRings, one_ring_first, one_ring_values);
  nFree = patch.intVertices.size();
  if(patch.gf->haveParametrization()) {
    uvs.resize(points.size());
    for(size_t v = 0; v < nFree; ++v) {
      new2old[v]->getParameter(0, uvs[v][0]);
      new2old[v]->getParameter(1, uvs[v][1]);
    }
  }
  return true;
}

bool GeometryOptimizer::smoothWithKernel(
  SmoothingKernel kernelRegular, SmoothingKernel kernelIrregular,
  double timeMax, int iterMax, double withBackup,
  bool localLocking, /* Lock if small displacement, unlocked neighbors else */
  double dxLocalMax, /* lock a vertex if dx < dxLocalMax * local_size */
  double dxGlobalMax, /* stop if sum(dx) < dxGlobalMax * sum(dx_0) */
  bool project, /* project with SurfaceProjector */
  bool finalCADprojection, bool smartVariant)
{
  /* Geometry backup */
  PatchGeometryBackup *backup = nullptr;
  double sicnMinBefore = -1.; /* if no element */
  double sicnAvgBefore = -1.;
  if(withBackup) {
    computeSICN(patchPtr->elements, sicnMinBefore, sicnAvgBefore);
    backup = new PatchGeometryBackup(*patchPtr);
  }

  /* Local sizes */
  vector<double> localAvgSize(nFree, 0.);
  for(size_t v = 0; v < nFree; ++v) {
    size_t n = one_ring_first[v + 1] - one_ring_first[v];
    if(n == 0) continue;
    for(size_t lv = 0; lv < n; ++lv) {
      uint32_t v2 = one_ring_values[one_ring_first[v] + lv];
      localAvgSize[v] += length(points[v] - points[v2]);
    }
    localAvgSize[v] /= double(n);
  }

  /* Initialization: all free vertices unlocked */
  std::vector<bool> locked(nFree, false);

  /* Explicit smoothing loop */
  double t0 = Cpu();
  double sum_dx0 = 0;
  std::vector<vec3> stencilIrreg(10);
  for(size_t iter = 0; iter < iterMax; ++iter) {
    size_t nMoved = 0;

    double sum_dx = 0.;
    /* Loop over interior vertices */
    for(size_t v = 0; v < nFree; ++v) {
      if(locked[v]) continue;

      vec3 newPos = points[v];
      vec2 newUv;
      if(uvs.size()) { newUv = uvs[v]; }

      bool ok = movePointWithKernelAndProjection(
        v, points, one_ring_first, one_ring_values, kernelRegular,
        kernelIrregular, project, sp, newPos, newUv, smartVariant);
      if(ok) {
        double dx = length(newPos - points[v]);
        sum_dx += dx;
        /* Modify the coordinates */
        points[v] = newPos;
        if(uvs.size()) uvs[v] = newUv;
        if(localLocking && dx < dxLocalMax * localAvgSize[v]) {
          locked[v] = true;
        }
        else {
          nMoved += 1;
        }
      }
      else {
        locked[v] = true;
      }
    }

    if(iter == 0) { sum_dx0 = sum_dx; }
    else {
      if(sum_dx < dxGlobalMax * sum_dx0) {
        Msg::Debug(
          "smoothWithKernel: stop at iter %li/%li because sum_dx = %f < %f",
          iter, iterMax, sum_dx, dxGlobalMax * sum_dx0);
        break;
      }
      if(nMoved == 0) {
        Msg::Debug(
          "smoothWithKernel: stop at iter %li/%li because no point moved", iter,
          iterMax);
        break;
      }
    }

    if(Cpu() - t0 > timeMax) {
      Msg::Debug(
        "smoothWithKernel: stop at iter %li/%li because timeout (%f sec)", iter,
        iterMax, Cpu() - t0);
      break;
    }
  }

  /* Update the positions */
  for(size_t i = 0; i < nFree; ++i) {
    MVertex *v = new2old[i];
    v->setXYZ(points[i][0], points[i][1], points[i][2]);
    if(uvs.size()) {
      v->setParameter(0, uvs[i][0]);
      v->setParameter(1, uvs[i][1]);

      if(finalCADprojection) {
        SPoint3 query = v->point();
        GPoint proj = patchPtr->gf->closestPoint(query, uvs[i].data());
        if(proj.succeeded()) {
          v->setXYZ(proj.x(), proj.y(), proj.z());
          v->setParameter(0, proj.u());
          v->setParameter(1, proj.v());
        }
      }
    }
  }

  if(withBackup && backup) {
    double sicnMinAfter;
    double sicnAvgAfter;
    computeSICN(patchPtr->elements, sicnMinAfter, sicnAvgAfter);
    if(sicnMinAfter < sicnMinBefore) { backup->restore(); }
  }

  if(backup) delete backup;

  return true;
}

void invertTrianglesIfNecessary(
  const std::vector<std::array<double, 2> > &points,
  std::vector<std::array<uint32_t, 3> > &tris)
{
  double area = 0.;
  for(size_t i = 0; i < tris.size(); ++i) {
    area +=
      triangleArea(points[tris[i][0]], points[tris[i][1]], points[tris[i][2]]);
  }
  if(area < 0.) {
    Msg::Debug(
      "invert 2D triangle orientations (total area was %f for %li tris)", area,
      tris.size());
    for(size_t i = 0; i < tris.size(); ++i) {
      uint32_t v1 = tris[i][1];
      tris[i][1] = tris[i][2];
      tris[i][2] = v1;
    }
  }
}

bool GeometryOptimizer::smoothWithWinslowUntangler(PlanarMethod planar,
                                                   int iterMax,
                                                   double withBackup,
                                                   bool finalCADprojection,
                                                   double nonPlanarRatioMax)
{
  if(nFree == 0) {
    Msg::Debug("geometry optimize: no free vertices, nothing to optimize");
    return true;
  }
  if(nFree == points.size()) {
    Msg::Debug("geometry optimize: no locked vertices, cannot optimize");
    return false;
  }
  vector<bool> locked(points.size(), false);
  for(size_t v = nFree; v < points.size(); ++v) { locked[v] = true; }
  Msg::Debug("- smoothWithWinslowUntangler: method %i, %li/%li free vertices",
             planar, nFree, points.size());

  /* Initial quality computation */
  double sicnMin, sicnAvg;
  computeSICN(patchPtr->elements, sicnMin, sicnAvg);
  if(DBG_VIZU_U) {
    GeoLog::add(patchPtr->elements, "optim_NU_IN_" + std::to_string(sicnMin));
    GeoLog::flush();
  }

  /* Backup of current geometry */
  PatchGeometryBackup backup(*patchPtr);

  double t1 = Cpu();

  /* Get planar points for the untangler */
  std::vector<vec2> points_2D(points.size());
  mean_plane mp;
  SVector3 normal, tangent, binormal;
  SPoint3 pop;
  if(planar == PlanarMethod::MeanPlane) {
    /* Compute the mean plane from the locked vertices */
    std::vector<SPoint3> vInit;
    vInit.reserve(points.size() - nFree);
    for(size_t v = nFree; v < points.size(); ++v) {
      vInit.push_back(SPoint3(points[v][0], points[v][1], points[v][2]));
    }
    computeMeanPlaneSimple(vInit, mp);
    double denom = std::pow(mp.a, 2) + std::pow(mp.b, 2) + std::pow(mp.c, 2);
    if(denom < 1.e-16) {
      Msg::Warning("geometry optimize: invalid mean plane");
      return false;
    }
    normal = SVector3(mp.a, mp.b, mp.c);
    buildOrthoBasis(normal, tangent, binormal);
    pop = SPoint3(mp.x, mp.y, mp.z);

    /* Projects points on mean plane, with 2D coordinates, before smoothing */
    {
      double omax = 0.;
      double du[2] = {DBL_MAX,-DBL_MAX};
      double dv[2] = {DBL_MAX,-DBL_MAX};
      for(size_t v = 0; v < points.size(); ++v) {
        SPoint3 p(points[v][0], points[v][1], points[v][2]);
        points_2D[v] = {dot(p - pop, tangent), dot(p - pop, binormal)};
        omax = std::max(omax,std::abs(dot(p - pop, normal)));
        du[0] = std::min(du[0],points_2D[v][0]);
        du[1] = std::max(du[1],points_2D[v][0]);
        dv[0] = std::min(dv[0],points_2D[v][1]);
        dv[1] = std::max(dv[1],points_2D[v][1]);
      }
      double denom = std::max(du[1]-du[0],dv[1]-dv[0]);
      if (denom < 1.e-14) return false;
      double ratio = omax / denom;
      if (ratio > nonPlanarRatioMax) {
        if (this->patchPtr && this->patchPtr->gf) {
          Msg::Debug("- Face %i: cancel mean plane winslow untangling because non planar ratio = %.3f > %.3f",
              this->patchPtr->gf->tag(),
              ratio, nonPlanarRatioMax);
        } else {
          Msg::Debug("- Untangling: cancel mean plane winslow untangling because non planar ratio = %.3f > %.3f",
              ratio, nonPlanarRatioMax);
        }
        return false;
      }
    }
  }
  else if(planar == PlanarMethod::ParamCAD) {
    std::unordered_map<MVertex *, SPoint2> vertexParam;
    bool okp = getPlanarParametrization(*patchPtr, vertexParam);
    if(!okp) {
      Msg::Debug("- Untangle: failed to get planar parametrization from CAD");
      return false;
    }
    for(size_t v = 0; v < points.size(); ++v) {
      auto it = vertexParam.find(new2old[v]);
      points_2D[v] = {it->second.x(), it->second.y()};
    }

    if(DBG_VIZU_U) {
      for(size_t i = 0; i < quads.size(); ++i) {
        std::vector<vec3> pts = {
          {points_2D[quads[i][0]][0], points_2D[quads[i][0]][1], 0.},
          {points_2D[quads[i][1]][0], points_2D[quads[i][1]][1], 0.},
          {points_2D[quads[i][2]][0], points_2D[quads[i][2]][1], 0.},
          {points_2D[quads[i][3]][0], points_2D[quads[i][3]][1], 0.}};
        GeoLog::add(pts, 0., "nancy_b" + std::to_string(sicnMin));
      }
    }
  }

  /* Triangles from quads */
  std::vector<std::array<vec2, 3> > triIdealShapes;
  std::vector<std::array<uint32_t, 3> > triangles;
  bool preserveQuadAnisotropy = false;
#if defined(HAVE_WINSLOWUNTANGLER)
  buildTrianglesAndTargetsFromElements(points_2D, quads, triangles,
                                       triIdealShapes, preserveQuadAnisotropy);
#else
  Msg::Error("smoothWithWinslowUntangler requires WinslowUntangler");
#endif

  /* Planar smoothing with Winslow untangler */
  Msg::Debug("- Untangle/Smooth quad mesh (%li quads -> %li optim tris, %li "
             "vertices, SICN min initial: %f) ...",
             quads.size(), triangles.size(), points_2D.size(), sicnMin);
  invertTrianglesIfNecessary(points_2D, triangles);
  int iterMaxOuter = iterMax;
  int iterMaxInner = 500;
  int nFailMax = 5;
  double lambda = 1. / 127.;
  int verbosity = 0;
  double timeMax = 1000;
  if(Msg::GetVerbosity() >= 99) verbosity = 1;
  std::string pp = "Debug   : ---- ";
#if defined(HAVE_WINSLOWUNTANGLER)
  bool oku =
    untangle_triangles_2D(points_2D, locked, triangles, triIdealShapes, lambda,
                          iterMaxInner, iterMaxOuter, nFailMax, timeMax);
  if(!oku) { Msg::Debug("---- failed to untangle"); }
#else
  Msg::Error("smoothWithWinslowUntangler requires WinslowUntangler");
#endif

  // {
  //   for (size_t v = 0; v < points_2D.size(); ++v) {
  //     GeoLog::add({points_2D[v][0],points_2D[v][1],0.},double(locked[v]),"2D_aftersmooth");
  //   }
  //   GeoLog::flush();
  // }

  /* Project back to surface */
  if(planar == PlanarMethod::MeanPlane) {
    SPoint3 proj;
    // {
    //   for (size_t v = 0; v < points_2D.size(); ++v) {
    //     SPoint3 onPlane = SPoint3(mp.x,mp.y,mp.z)
    //       + points_2D[v][0] * tangent
    //       + points_2D[v][1] * binormal;
    //     GeoLog::add(onPlane,double(locked[v]),"reproj_plane");
    //   }
    //   GeoLog::flush();
    // }
    for(size_t v = 0; v < nFree; ++v) {
      SPoint3 onPlane =
        pop + points_2D[v][0] * tangent + points_2D[v][1] * binormal;

      GPoint proj;
      if(sp != nullptr) {
        proj = sp->closestPoint(onPlane.data(), false, false);
        if(proj.succeeded()) {
          points[v] = {proj.x(), proj.y(), proj.z()};
          if(uvs.size() > 0) { uvs[v] = {proj.u(), proj.v()}; }
        }
        else {
          Msg::Warning("sp proj failed");
        }
      }
      if(patchPtr->gf->haveParametrization() &&
         (!proj.succeeded() || finalCADprojection)) {
        double initGuess[2] = {0., 0.};
        if(uvs.size() > 0) {
          initGuess[0] = uvs[v][0];
          initGuess[1] = uvs[v][1];
        }
        proj = patchPtr->gf->closestPoint(onPlane.data(), initGuess);
        if(proj.succeeded()) {
          points[v] = {proj.x(), proj.y(), proj.z()};
          if(uvs.size() > 0) { uvs[v] = {proj.u(), proj.v()}; }
        }
        else {
          Msg::Warning("CAD proj failed");
        }
      }
    }
    /* Update the patch */
    for(size_t v = 0; v < nFree; ++v) {
      new2old[v]->setXYZ(points[v][0], points[v][1], points[v][2]);
      if(uvs.size()) {
        new2old[v]->setParameter(0, uvs[v][0]);
        new2old[v]->setParameter(1, uvs[v][1]);
      }
    }
  }
  else if(planar == PlanarMethod::ParamCAD) {
    for(size_t v = 0; v < nFree; ++v) {
      GPoint p = patchPtr->gf->point(points_2D[v][0], points_2D[v][1]);
      new2old[v]->setXYZ(p.x(), p.y(), p.z());
      new2old[v]->setParameter(0, points_2D[v][0]);
      new2old[v]->setParameter(1, points_2D[v][1]);
    }
  }

  double t2 = Cpu();
  double sicnMinA, sicnAvgA;
  computeSICN(patchPtr->elements, sicnMinA, sicnAvgA);

  if(DBG_VIZU_U) {
    GeoLog::add(patchPtr->elements, "optim_NU_OUT_" + std::to_string(sicnMinA));
    GeoLog::flush();
    if(planar == PlanarMethod::ParamCAD) {
      for(size_t i = 0; i < quads.size(); ++i) {
        std::vector<vec3> pts = {
          {points_2D[quads[i][0]][0], points_2D[quads[i][0]][1], 0.},
          {points_2D[quads[i][1]][0], points_2D[quads[i][1]][1], 0.},
          {points_2D[quads[i][2]][0], points_2D[quads[i][2]][1], 0.},
          {points_2D[quads[i][3]][0], points_2D[quads[i][3]][1], 0.}};
        GeoLog::add(pts, 0., "nancy_a" + std::to_string(sicnMinA));
      }
      GeoLog::flush();
    }
  }

  bool keep = true;
  if(sicnMinA < sicnMin && sicnAvgA < 0.99 * sicnAvg) keep = false;
  if(sicnMinA < 0. && sicnMinA < sicnMin) keep = false;
  if(sicnMinA < 0.75 * sicnMin) keep = false;
  if(keep) {
    Msg::Debug("optimize with Winslow untangler (uv param: %i): %li/%li free "
               "vertices, %li elements, SICN min: %.3f -> %.3f, SICN avg: %.3f "
               "-> %.3f, time: %.3fsec",
               planar, patchPtr->intVertices.size(), points.size(),
               patchPtr->elements.size(), sicnMin, sicnMinA, sicnAvg, sicnAvgA,
               t2 - t1);
  }
  else {
    backup.restore();
    Msg::Debug("optimize with Winslow untangler (uv param: %i): %li/%li free "
               "vertices, %li elements, SICN min: %.3f -> %.3f, SICN avg: %.3f "
               "-> %.3f, time: %.3fsec, rollback",
               planar, patchPtr->intVertices.size(), points.size(),
               patchPtr->elements.size(), sicnMin, sicnMinA, sicnAvg, sicnAvgA,
               t2 - t1);
    return false;
  }

  return true;
}

bool optimizeGeometryQuadqs(GModel *gm)
{
  Msg::Info("Optimize geometry of quad mesh ...");

  vector<GFace *> faces = model_faces(gm);
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;

    SurfaceProjector sp;
    fillSurfaceProjector(gf, &sp);
    double tMax = double(gf->mesh_vertices.size()) / 100.;
    bool withBackup = true;
    optimizeGeometryQuadMesh(gf, &sp, tMax, withBackup);
    quadMeshSpecialAcuteCornerOptimization(gf, &sp);
  }

  return true;
}
