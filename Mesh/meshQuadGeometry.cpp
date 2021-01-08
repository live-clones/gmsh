// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshQuadGeometry.h"
#include <map>
#include <iostream>
#include "meshGFace.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "discreteFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "Options.h"
#include "fastScaledCrossField.h"
#include "meshSurfaceProjection.h"
#include "meshWinslow2d.h"

#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing
#include "robin_hood.h"
#include "meshQuadUtils.h"
#include "geolog.h"

#if defined(_OPENMP)
#include <omp.h>
#endif


#if defined(HAVE_MESQUITE)
#include "Mesquite_all_headers.hpp"
#endif

using std::vector;
using std::array;
using namespace QuadUtils;
using namespace GeometryVec3;

template <size_t N>
bool kernelLaplacian(const std::array<vec3,N>& points, vec3& newPos) {
  if (N == 0) return false;
  newPos = {0.,0.,0.};
  for (size_t i = 0; i < N; ++i) {
    newPos = newPos + points[i];
  }
  newPos = 1./double(N) * newPos;
  return true;
}

template <size_t N>
bool kernelAngleBased(const vec3& center, const std::array<vec3,N>& points, vec3& newPos) {
  /* template version to avoid memory allocation */
  std::array<vec3,N> rotated;
  std::array<double,N> angles;
  double sum_angle = 0.;
  for (size_t i = 0; i < N; ++i) {
    const vec3& prev = points[(N+i-1)%N];
    const vec3& cur = points[i];
    const vec3& next = points[(i+1)%N];
    vec3 oldDir = (center - cur);
    double len = length(oldDir);
    if (len == 0.) return false;
    vec3 d1 = prev-cur;
    if (length2(d1) == 0.) return false;
    vec3 d2 = next-cur;
    if (length2(d2) == 0.) return false;
    normalize_accurate(d1);
    normalize_accurate(d2);
    vec3 newDir = d1+d2;
    if (length2(newDir) == 0.) return false;
    normalize_accurate(newDir);
    if (dot(newDir,oldDir) < 0.) {
      newDir = -1. * newDir;
    }
    rotated[i] = cur + len * newDir;
    normalize_accurate(oldDir);
    double agl = angleVectorsAlreadyNormalized(newDir,oldDir);
    angles[i] = agl;
    sum_angle += agl;
  }
  if (sum_angle == 0.) return false;
  newPos.data()[0] = 0.;
  newPos.data()[1] = 0.;
  newPos.data()[2] = 0.;
  for (size_t i = 0; i < N; ++i) {
    double w = angles[i] / sum_angle;
    // double w = 1./double(N);
    newPos = newPos + w * rotated[i];
  }
  return true;
}

bool kernelLaplacian(const std::vector<vec3>& points, vec3& newPos) {
  const size_t N = points.size();
  if (N == 0) return false;
  newPos = {0.,0.,0.};
  for (size_t i = 0; i < N; ++i) {
    newPos = newPos + points[i];
  }
  newPos = 1./double(N) * newPos;
  return true;
}

bool kernelAngleBased(const vec3& center, const std::vector<vec3>& points, vec3& newPos) {
  const size_t N = points.size();
  std::vector<vec3> rotated(N);
  std::vector<double> angles(N);
  double sum_angle = 0.;
  for (size_t i = 0; i < N; ++i) {
    const vec3& prev = points[(N+i-1)%N];
    const vec3& cur = points[i];
    const vec3& next = points[(i+1)%N];
    vec3 oldDir = (center - cur);
    double len = length(oldDir);
    if (len == 0.) return false;
    vec3 d1 = prev-cur;
    if (length2(d1) == 0.) return false;
    vec3 d2 = next-cur;
    if (length2(d2) == 0.) return false;
    normalize_accurate(d1);
    normalize_accurate(d2);
    vec3 newDir = d1+d2;
    if (length2(newDir) == 0.) return false;
    normalize_accurate(newDir);
    if (dot(newDir,oldDir) < 0.) {
      newDir = -1. * newDir;
    }
    rotated[i] = cur + len * newDir;
    normalize_accurate(oldDir);
    double agl = angleVectorsAlreadyNormalized(newDir,oldDir);
    angles[i] = agl;
    sum_angle += agl;
  }
  if (sum_angle == 0.) return false;
  newPos.data()[0] = 0.;
  newPos.data()[1] = 0.;
  newPos.data()[2] = 0.;
  for (size_t i = 0; i < N; ++i) {
    double w = angles[i] / sum_angle;
    // double w = 1./double(N);
    newPos = newPos + w * rotated[i];
  }
  return true;
}

inline bool kernelWinslowSpecialStencil(const vec3 ptsStencil[8], vec3& newPos) {
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

  /* 1. Compute the winslow coefficients (alpha_i, beta_i in the Karman paper) */
  /*    a. Compute first order derivatives of the position */
  vec3 r_i[2];
  r_i[0] = 1./hx * (ptsStencil[0] - ptsStencil[2]);
  r_i[1] = 1./hy * (ptsStencil[1] - ptsStencil[3]);
  /*    b. Compute the alpha_i coefficients */
  const double alpha_0 = dot(r_i[1],r_i[1]);
  const double alpha_1 = dot(r_i[0],r_i[0]);
  /*    c. Compute the beta coefficient */
  const double beta =  dot(r_i[0],r_i[1]);

  /* cross derivative */
  const vec3 u_xy = 1./(4.*hx*hy) * (ptsStencil[4]+ptsStencil[7]-ptsStencil[6]-ptsStencil[5]);

  /* 2. Compute the "winslow new position" */
  const double denom = 2. * alpha_0 / (hx*hx) + 2. * alpha_1 / (hy*hy);
  if (std::abs(denom) < 1.e-18) return false;
  newPos = 1. / denom * (
      alpha_0/(hx*hx) * (ptsStencil[0] + ptsStencil[2])
      + alpha_1/(hy*hy) * (ptsStencil[1] + ptsStencil[3])
      - 2. * beta * u_xy
      );
  return true;
}

inline bool kernelWinslow(const std::array<vec3,8>& stencil, vec3& newPos) {
  /* Continuous ordering in input stencil */
  const std::array<uint32_t,8> o2n = {0, 2, 4, 6, 1, 7, 3, 5};
  const std::array<vec3,8> winStencil = {
    stencil[o2n[0]], stencil[o2n[1]], stencil[o2n[2]], stencil[o2n[3]],
    stencil[o2n[4]], stencil[o2n[5]], stencil[o2n[6]], stencil[o2n[7]]};
  return kernelWinslowSpecialStencil(winStencil.data(), newPos);
}

double projectOnPlane(
    const vec3& query,
    const vec3& p1,
    const vec3& p2,
    const vec3& p3,
    vec3& proj) {
  const vec3 d1 = p2-p1;
  const vec3 d2 = p3-p1;
  vec3 n = cross(d1,d2);
  if (length2(n) == 0.) return DBL_MAX;
  normalize_accurate(n);
  double t = dot(query-p1,n);
  proj = query - t * n;
  return length2(proj-query);
}

template <size_t N>
  bool projectOnStencilTrianglePlanes(
      const vec3& center, 
      const std::array<vec3,N>& points, 
      const vec3& query,
      vec3& proj
      ) {
    double d2min = DBL_MAX;
    for (size_t i = 0; i < N; ++i) {
      const vec3& p2 = points[i];
      const vec3& p3 = points[(i+1)%N];
      vec3 cand;
      double d2 = projectOnPlane(query,center,p2,p3,cand);
      if (d2 < d2min) {
        d2min = d2;
        proj = cand;
      }
    }
    return true;
  }

bool projectOnStencilTrianglePlanes(
    const vec3& center, 
    const std::vector<vec3>& points, 
    const vec3& query,
    vec3& proj
    ) {
  const size_t N = points.size();
  double d2min = DBL_MAX;
  for (size_t i = 0; i < N; ++i) {
    const vec3& p2 = points[i];
    const vec3& p3 = points[(i+1)%N];
    vec3 cand;
    double d2 = projectOnPlane(query,center,p2,p3,cand);
    if (d2 < d2min) {
      d2min = d2;
      proj = cand;
    }
  }
  return true;
}


bool buildCondensedStructure(
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    robin_hood::unordered_map<MVertex*,uint32_t>& old2new,
    std::vector<MVertex*>& new2old,
    std::vector<std::array<uint32_t,4> >& quads,
    std::vector<std::vector<uint32_t> >& v2q,
    std::vector<std::vector<uint32_t> >& oneRings,
    std::vector<std::array<double,3> >& points
    ) {
  new2old.reserve(2*freeVertices.size());
  v2q.reserve(2*freeVertices.size());
  points.reserve(2*freeVertices.size());

  size_t vcount = 0;
  for (MVertex* v: freeVertices) {
    old2new[v] = vcount;
    vec3 pt = SVector3(v->point());
    points.push_back(pt);
    new2old.push_back(v);
    vcount += 1;
  }

  v2q.resize(vcount);
  quads.resize(elements.size());
  for (size_t f = 0; f < elements.size(); ++f) {
    MElement* q = elements[f];
    if (q->getNumVertices() != 4) {
      Msg::Error("buildCondensedStructure: element is not a quad");
      return false;
    }
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = q->getVertex(lv);
      auto it = old2new.find(v);
      size_t nv;
      if (it == old2new.end()) {
        old2new[v] = vcount;
        new2old.push_back(v);
        nv = vcount;
        vcount += 1;
        vec3 pt = SVector3(v->point());
        points.push_back(pt);
        if (nv >= v2q.size()) {
          v2q.resize(nv+1);
        }
      } else {
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
  vector<MElement*> adjQuads;
  for (size_t v = 0; v < freeVertices.size(); ++v) {
    adjQuads.resize(v2q[v].size());
    for (size_t lq = 0; lq < v2q[v].size(); ++lq) {
      adjQuads[lq] = elements[v2q[v][lq]];
    }
    std::vector<MVertex*> bnd;
    bool okb = buildBoundary(adjQuads, bnd);
    if (!okb) {
      Msg::Error("buildCondensedStructure: failed to build boundary for stencil");
      return false;
    }
    if (bnd.back() == bnd.front()) bnd.pop_back();

    /* Be sure the first vertex on the boundary is edge-connected to v */
    /* Start of the stencil */
    MVertex* vp = freeVertices[v];
    MVertex* v0 = NULL;
    for (MElement* e: adjQuads) {
      size_t N = e->getNumVertices();
      for (size_t j = 0; j < N; ++j) {
        MVertex* a = e->getVertex(j);
        MVertex* b = e->getVertex((j+1)%N);
        if (a == vp) {
          v0 = b;
          break;
        } else if (b == vp) {
          v0 = a;
          break;
        }
      }
      if (v0 != NULL) break;
    }
    if (v0 == NULL) {
      Msg::Error("buildCondensedStructure: failed to found v0");
      return false;
    }
    for (size_t j = 0; j < bnd.size(); ++j) {
      if (bnd[j] == v0 && j > 0) {
        std::rotate(bnd.begin(),bnd.begin()+j,bnd.end());
      }
    }
    if (bnd.front() != v0) {
      Msg::Error("buildCondensedStructure: wrong start");
      return false;
    }
    if (bnd.size() < 6 || bnd.size() % 2 != 0) {
      Msg::Error("buildCondensedStructure: wrong boundary, size %li", bnd.size());
      return false;
    }

    oneRings[v].resize(bnd.size());
    for (size_t j = 0; j < bnd.size(); ++j) {
      auto it = old2new.find(bnd[j]);
      if (it != old2new.end()) {
        oneRings[v][j] = it->second;
      } else {
        Msg::Error("buildCondensedStructure: vertex not found in old2new");
        return false;
      }
    }
  }

  return true;
}

template <size_t N>
bool extractGeometricStencil(
    const std::vector<uint32_t>& oneRing,
    const std::vector<vec3>& points,
    std::array<vec3,N>& stencil
    ) {
  if (oneRing.size() == N) {
    for (size_t i = 0; i < N; ++i) {
      stencil[i] = points[oneRing[i]];
    }
    return true;
  } else if (oneRing.size() == 2*N) {
    /* Extract one over two */
    for (size_t i = 0; i < N; ++i) {
      stencil[i] = points[oneRing[2*i]];
    }
    return true;
  } 
  return false;
}

bool extractGeometricStencil(
    const std::vector<uint32_t>& oneRing,
    const std::vector<vec3 >& points,
    std::vector<vec3 >& stencil
    ) {
  const size_t N = stencil.size();
  if (oneRing.size() == N) {
    for (size_t i = 0; i < N; ++i) {
      stencil[i] = points[oneRing[i]];
    }
    return true;
  } else if (oneRing.size() == 2*N) {
    /* Extract one over two */
    for (size_t i = 0; i < N; ++i) {
      stencil[i] = points[oneRing[2*i]];
    }
    return true;
  } 
  return false;
}

template <size_t N>
bool kernelSmoothingFloatingPoint(
    const LocalSmoothingKernel& kernel,
    const vec3 center,
    const std::array<vec3,N>& stencil,
    vec3& newPos) 
{
  if (N == 8 && kernel == WinslowAtRegular) {
    Msg::Error("winslow must be called directly... (template stuff)");
    return false;
  } else if (kernel == Laplacian) {
    bool okk = kernelLaplacian(stencil, newPos);
    if (!okk) return false;
  } else {
    bool okk = kernelAngleBased(center, stencil, newPos);
    if (!okk) return false;
  }
  return true;
}

bool kernelSmoothingFloatingPoint(
    const LocalSmoothingKernel& kernel,
    const vec3 center,
    const std::vector<vec3>& stencil,
    vec3& newPos) 
{
  if (kernel == Laplacian) {
    bool okk = kernelLaplacian(stencil, newPos);
    if (!okk) return false;
  } else {
    bool okk = kernelAngleBased(center, stencil, newPos);
    if (!okk) return false;
  }
  return true;
}

template <size_t N>
bool checkGeometryIsNotInverted(
    const vec3 center,
    const std::array<vec3,N>& stencil,
    vec3& newPos) 
{
  for (size_t i = 0; i < N; ++i) {
    const vec3& p2 = stencil[i];
    const vec3& p3 = stencil[(i+1)%N];
    const vec3 N_before = cross(p2-center,p3-center);
    const vec3 N_after = cross(p2-newPos,p3-newPos);
    if (dot(N_before,N_after) < 0.) return false;
  }
  return true;
}

bool checkGeometryIsNotInverted(
    const vec3 center,
    const std::vector<vec3>& stencil,
    vec3& newPos) 
{
  const size_t N = stencil.size();
  for (size_t i = 0; i < N; ++i) {
    const vec3& p2 = stencil[i];
    const vec3& p3 = stencil[(i+1)%N];
    const vec3 N_before = cross(p2-center,p3-center);
    const vec3 N_after = cross(p2-newPos,p3-newPos);
    if (dot(N_before,N_after) < 0.) return false;
  }
  return true;
}

const int KS_ERROR = 0;
const int KS_OK = 1;
const int KS_REJECTED_PROJECTION = 2;
const int KS_REJECTED_QUALITY = 3;

int kernelSmoothing(
    LocalSmoothingKernel kernel,
    uint32_t v,
    const std::vector<std::vector<uint32_t> >& oneRing,
    std::vector<std::array<double,3> >& points,
    /* Projection on surface */
    bool projOnPlanes,
    const SurfaceProjector* sp,
    /* Verify no element geometric inversion */
    bool smartVariant)
{
  constexpr bool spProjectOnCAD = false;
  size_t cache = (size_t) -1;

  /* Compute new position */
  const size_t N = oneRing[v].size();
  const vec3 center = points[v];
  vec3 newPos;

  /* Code is redundant, but it is used to encapsulate
   * template calls to remove heap allocations for
   * valence 3, 4, 5 */
  if (N == 8 && kernel == WinslowAtRegular) { /* Full one ring */
      std::array<vec3,8> stencil;
      bool oke = extractGeometricStencil(oneRing[v],points,stencil);
      if (!oke) return KS_ERROR;
      bool oks = kernelWinslow(stencil, newPos);
      if (!oks) return KS_ERROR;
      std::array<vec3,4> stencil2; /* edge-adjacent stencil */
      bool oke2 = extractGeometricStencil(oneRing[v],points,stencil2);
      if (!oke2) return KS_ERROR;
      if (projOnPlanes) {
        vec3 proj;
        bool okp = projectOnStencilTrianglePlanes(center, stencil2, newPos, proj);
        if (!okp) return KS_REJECTED_PROJECTION;
        newPos = proj;
      } else if (sp != NULL) {
        GPoint gp = sp->closestPoint(newPos.data(), cache, true, spProjectOnCAD);
        if (gp.succeeded()) {
          newPos = {gp.x(),gp.y(),gp.z()};
        } else {
          return KS_REJECTED_PROJECTION;
        }
      }
      if (smartVariant) {
        bool okg = checkGeometryIsNotInverted(center, stencil2, newPos);
        if (!okg) return KS_REJECTED_QUALITY;
      }
  } else { /* Only edge-adjacent one ring */
    if (kernel == WinslowAtRegular) kernel = AngleBased;

    if (N == 8) { /* regular */
      std::array<vec3,4> stencil;
      bool oke = extractGeometricStencil(oneRing[v],points,stencil);
      if (!oke) return KS_ERROR;
      bool oks = kernelSmoothingFloatingPoint(kernel, center, stencil, newPos);
      if (!oks) return KS_ERROR;
      if (projOnPlanes) {
        vec3 proj;
        bool okp = projectOnStencilTrianglePlanes(center, stencil, newPos, proj);
        if (!okp) return KS_REJECTED_PROJECTION;
        newPos = proj;
      } else if (sp != NULL) {
        GPoint gp = sp->closestPoint(newPos.data(), cache, true, spProjectOnCAD);
        if (gp.succeeded()) {
          newPos = {gp.x(),gp.y(),gp.z()};
        } else {
          return KS_REJECTED_PROJECTION;
        }
      }
      if (smartVariant) {
        bool okg = checkGeometryIsNotInverted(center, stencil, newPos);
        if (!okg) return KS_REJECTED_QUALITY;
      }
    } else if (N == 6) { /* valence 3 */
      std::array<vec3,3> stencil;
      bool oke = extractGeometricStencil(oneRing[v],points,stencil);
      if (!oke) return KS_ERROR;

      bool oks = kernelSmoothingFloatingPoint(kernel, center, stencil, newPos);
      if (!oks) return KS_ERROR;
      if (projOnPlanes) {
        vec3 proj;
        bool okp = projectOnStencilTrianglePlanes(center, stencil, newPos, proj);
        if (!okp) return KS_REJECTED_PROJECTION;
        newPos = proj;
      } else if (sp != NULL) {
        GPoint gp = sp->closestPoint(newPos.data(), cache, true, spProjectOnCAD);
        if (gp.succeeded()) {
          newPos = {gp.x(),gp.y(),gp.z()};
        } else {
          return KS_REJECTED_PROJECTION;
        }
      }
      if (smartVariant) {
        bool okg = checkGeometryIsNotInverted(center, stencil, newPos);
        if (!okg) return KS_REJECTED_QUALITY;
      }
    } else if (N == 10) { /* valence 5 */
      std::array<vec3,5> stencil;
      bool oke = extractGeometricStencil(oneRing[v],points,stencil);
      if (!oke) return KS_ERROR;
      bool oks = kernelSmoothingFloatingPoint(kernel, center, stencil, newPos);
      if (!oks) return KS_ERROR;
      if (projOnPlanes) {
        vec3 proj;
        bool okp = projectOnStencilTrianglePlanes(center, stencil, newPos, proj);
        if (!okp) return KS_REJECTED_PROJECTION;
        newPos = proj;
      } else if (sp != NULL) {
        GPoint gp = sp->closestPoint(newPos.data(), cache, true, spProjectOnCAD);
        if (gp.succeeded()) {
          newPos = {gp.x(),gp.y(),gp.z()};
        } else {
          return KS_REJECTED_PROJECTION;
        }
      }
      if (smartVariant) {
        bool okg = checkGeometryIsNotInverted(center, stencil, newPos);
        if (!okg) return KS_REJECTED_QUALITY;
      }
    } else if (N > 10 && N%2 == 0) {
      std::vector<vec3> stencil(N/2);
      bool oke = extractGeometricStencil(oneRing[v],points,stencil);
      if (!oke) return KS_ERROR;
      bool oks = kernelSmoothingFloatingPoint(kernel, center, stencil, newPos);
      if (!oks) return KS_ERROR;
      if (projOnPlanes) {
        vec3 proj;
        bool okp = projectOnStencilTrianglePlanes(center, stencil, newPos, proj);
        if (!okp) return KS_REJECTED_PROJECTION;
        newPos = proj;
      } else if (sp != NULL) {
        GPoint gp = sp->closestPoint(newPos.data(), cache, true, spProjectOnCAD);
        if (gp.succeeded()) {
          newPos = {gp.x(),gp.y(),gp.z()};
        } else {
          return KS_REJECTED_PROJECTION;
        }
      }
      if (smartVariant) {
        bool okg = checkGeometryIsNotInverted(center, stencil, newPos);
        if (!okg) return KS_REJECTED_QUALITY;
      }
    } else {
      return KS_ERROR;
    }
  }
  points[v] = newPos;
  return KS_OK;
}

// TODO a mixed smoother Winslow + angle-based
//      with smart option to do not degrade locally
bool smoothElementsWithLocalKernel(
    LocalSmoothingKernel kernel,
    GFace* gf,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    bool smartVariant, /* check quality of elements after each move, slow */
    size_t iterMaxOuterLoop,
    double global_dx_reduction, /* stop smoothing it the while deplacement is less than global_dx_reduction * dx0 */
    double local_dx_reduction /* lock a node if it moved less than local_dx_reduction * dx0(v) */
    ) {
  GEntity::GeomType GT = gf->geomType();
  bool projOnStencil = true;
  if (GT == GEntity::Plane) {
    sp = NULL;
    projOnStencil = false;
  }

  /* Condensed version (no pointers, less indirection, more cache efficient) */
  robin_hood::unordered_map<MVertex*,uint32_t> old2new;
  std::vector<MVertex*> new2old;
  std::vector<std::array<uint32_t,4> > quads;
  std::vector<std::vector<uint32_t> > v2q;
  std::vector<std::vector<uint32_t> > oneRings;
  std::vector<std::array<double,3> > points;
  bool okc = buildCondensedStructure(elements,freeVertices,old2new,new2old,
      quads,v2q,oneRings,points);
  if (!okc) {
    Msg::Error("smoothElementsWithLocalKernel: failed to build condensed representation");
    return false;
  }

  /* Local sizes */
  vector<double> localAvgSize(freeVertices.size(),0.);
  for (size_t i = 0; i < freeVertices.size(); ++i) if (oneRings[i].size() > 0) {
    for (size_t j = 0; j < oneRings[i].size(); ++j) {
      localAvgSize[i] += length(points[i]-points[oneRings[i][j]]);
    }
    localAvgSize[i] /= double(oneRings[i].size());
  }

  /* Optimization loop */
  vector<bool> running(freeVertices.size(),true);
  double sum_dx0 = 0.;
  double max_dx0 = 0.;
  size_t iter = 0;
  for (iter = 0; iter < iterMaxOuterLoop; ++iter) {
    /* Stencil projection is projection on the adj triangle
     * planes, fast but not very accurate */
    bool useStencilProjection = (projOnStencil && (iter < iterMaxOuterLoop-1));

    double sum_dx = 0.;
    double max_dx = 0.;
    size_t count = 0;
    for (size_t i = 0; i < freeVertices.size(); ++i) if (running[i]) {
      vec3 center = points[i];
      int status = kernelSmoothing(kernel, i, oneRings, points, useStencilProjection, 
          sp, smartVariant);
      if (status == KS_OK) {
        double dx = length(center-points[i]);
        max_dx = std::max(max_dx,dx);
        sum_dx += dx;
        /* Lock the vertex */
        if (dx < local_dx_reduction*localAvgSize[i]) {
          running[i] = false;
        } else {
          count += 1;
        }
      } else {
        running[i] = false;
      }
    }
    if (iter == 0) {
      sum_dx0 = sum_dx;
      max_dx0 = max_dx;
    } else {
      if (sum_dx < global_dx_reduction*sum_dx0) break;
      if (count == 0) break; /* all locked */
    }
  }
  for (size_t i = 0; i < freeVertices.size(); ++i) {
    // TODO: project on CAD ?
    new2old[i]->setXYZ(points[i][0],points[i][1],points[i][2]);
  }

  return true;
}

#if defined(HAVE_MESQUITE)
  struct QuadMeshData {
    vector<double> coords;
    vector<int> fixed;
    vector<MVertex*> origin;
    vector<unsigned long> quads;
  };

bool fillDataFromGFace(const GFace* gf, QuadMeshData& M,
  std::unordered_map<MVertex*,size_t>& old2new) {
  size_t vcount = 0;
  M.coords.reserve(3*gf->quadrangles.size());
  M.fixed.reserve(gf->quadrangles.size());
  M.origin.reserve(gf->quadrangles.size());
  M.quads.resize(4*gf->quadrangles.size());
  size_t qcount = 0;
  for (MQuadrangle* q: gf->quadrangles) {
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = q->getVertex(lv);
      auto it = old2new.find(v);
      size_t nv;
      if (it == old2new.end()) {
        old2new[v] = vcount;
        nv = vcount;
        vcount += 1;
        M.coords.push_back(v->x());
        M.coords.push_back(v->y());
        M.coords.push_back(v->z());
        M.origin.push_back(v);
        M.fixed.push_back(0);
      } else {
        nv = it->second;
      }
      M.quads[4*qcount+lv] = nv;
    }
    qcount += 1;
  }
  M.coords.shrink_to_fit();
  M.fixed.shrink_to_fit();
  M.origin.shrink_to_fit();
  M.quads.shrink_to_fit();

  return true;
}

bool fillDataFromCavity(
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    QuadMeshData& M,
    std::unordered_map<MVertex*,size_t>& old2new) {
  M.coords.reserve(3*freeVertices.size());
  M.fixed.reserve(freeVertices.size());
  M.origin.reserve(freeVertices.size());
  M.quads.resize(4*elements.size());
  size_t vcount = 0;
  for (MVertex* v: freeVertices) {
    old2new[v] = vcount;
    vcount += 1;
    M.coords.push_back(v->x());
    M.coords.push_back(v->y());
    M.coords.push_back(v->z());
    M.origin.push_back(v);
    M.fixed.push_back(0);
  }
  size_t qcount = 0;
  for (MElement* q: elements) {
    if (q->getNumVertices() != 4) return false;
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = q->getVertex(lv);
      auto it = old2new.find(v);
      size_t nv;
      if (it == old2new.end()) {
        old2new[v] = vcount;
        nv = vcount;
        vcount += 1;
        M.coords.push_back(v->x());
        M.coords.push_back(v->y());
        M.coords.push_back(v->z());
        M.origin.push_back(v);
        M.fixed.push_back(1);
      } else {
        nv = it->second;
      }
      M.quads[4*qcount+lv] = nv;
    }
    qcount += 1;
  }
  M.coords.shrink_to_fit();
  M.fixed.shrink_to_fit();
  M.origin.shrink_to_fit();
  M.quads.shrink_to_fit();

  return true;
}


using namespace Mesquite;

void quad_normal(const double* coords, unsigned long v0, unsigned long v1, unsigned long v2, unsigned long v3,
    double* normal) {
  double t_u[3];
  double t_v[3];
  for (size_t d = 0; d < 3; ++ d) {
    t_u[d] = 0.5 * (coords[3*v1+d]+coords[3*v2+d]-coords[3*v0+d]-coords[3*v3+d]);
    t_v[d] = 0.5 * (coords[3*v2+d]+coords[3*v3+d]-coords[3*v0+d]-coords[3*v1+d]);
  }
  normal[0] = t_u[1] * t_v[2] - t_v[1] * t_u[2];
  normal[1] = -(t_u[0] * t_v[2] - t_v[0] * t_u[2]);
  normal[2] = t_u[0] * t_v[1] - t_v[0] * t_u[1];
  double len = std::sqrt( normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
  normal[0] /= len;
  normal[1] /= len;
  normal[2] /= len;
}

GPoint project(MVertex* mv, SPoint3& query) {
  GFace* gf = dynamic_cast<GFace*>(mv->onWhat());
  if (gf != NULL) {
    SPoint2 uv;
    mv->getParameter(0,uv[0]);
    mv->getParameter(1,uv[1]);
    GPoint proj = gf->closestPoint(query,uv);
    return proj;
  } else {
    GEdge* ge = dynamic_cast<GEdge*>(mv->onWhat());
    if (ge != NULL) {
      double t;
      mv->getParameter(0,t);
      GPoint proj = ge->closestPoint(query,t);
      return proj;
    } else {
      GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
      if (gv != NULL) {
        GPoint proj(gv->x(),gv->y(),gv->z(),gv);
        return proj;
      } 
    }
  }
  GPoint proj;
  proj.setNoSuccess();
  return proj;
}

bool closestBoundaryPoint(const QuadMeshData& M, const SPoint3& query, SPoint3& closest) {
  double dMin = DBL_MAX;
  MVertex* best = NULL;
  for (MVertex* v: M.origin) {
    GFace* gf = dynamic_cast<GFace*>(v->onWhat());
    if (gf != NULL) continue;
    double d = query.distance(v->point());
    if (d < dMin) {
      dMin = d;
      best = v;
    }
  }
  if (best == NULL) return false;
  closest = best->point();
  return true;
}


class MeshDomainGFace : public MeshDomain
{
  public:

    MeshDomainGFace(GFace * gf_, const QuadMeshData& M_): gf(gf_), M(M_) {}

    virtual ~MeshDomainGFace() {}

    void snap_to( Mesh::VertexHandle entity_handle, Vector3D& coordinat ) const {
      size_t v = (size_t) (entity_handle);
      if (v >= M.origin.size()) { return; }
      MVertex* mv = M.origin[v];
      if (mv == NULL) { return; }
      SPoint3 query(coordinat.x(),coordinat.y(),coordinat.z());
      GPoint proj = project(mv,query);
      if (proj.succeeded()) {
        coordinat.set(proj.x(),proj.y(),proj.z());
      } else {
        Msg::Debug("MeshDomainGFace::snap_to(): failed to projected vertex %li, query=(%f,%f,%f), initial_position=(%f,%f,%f)", 
            v, query.x(),query.y(),query.z(),mv->x(),mv->y(),mv->z());
      }
    }

    void vertex_normal_at( Mesh::VertexHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t v = (size_t) (entity_handle);
      if (v >= M.origin.size()) { return; }
      MVertex* mv = M.origin[v];
      if (mv == NULL) { return; }
      SPoint3 query(coordinate.x(),coordinate.y(),coordinate.z());
      GPoint proj = project(mv,query);
      if (proj.succeeded()) {
        GFace* cgf = dynamic_cast<GFace*>(mv->onWhat());
        if (cgf != NULL) {
          SPoint2 uv(proj.u(),proj.v());
          SVector3 n = gf->normal(uv);
          coordinate.set(n.data());
        } 
      } 
      coordinate.set(0.,0.,0.);
    }

    void element_normal_at( Mesquite::Mesh::ElementHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t f = (size_t) (entity_handle);
      // TODO: project center and use CAD normal ?
      double n[3];
      quad_normal(M.coords.data(), M.quads[4*f+0], M.quads[4*f+1], M.quads[4*f+2], M.quads[4*f+3], n);
      coordinate.set(n);
    }

    void vertex_normal_at( const Mesh::VertexHandle* handles,
        Vector3D coordinates[],
        unsigned count,
        MsqError& err ) const {
      for (size_t i = 0; i < count; ++i) {
        vertex_normal_at(handles[i], coordinates[i]);
      }
      return;
    }

    void closest_point( Mesh::VertexHandle handle,
        const Vector3D& position,
        Vector3D& closest,
        Vector3D& normal,
        MsqError& err ) const {
      size_t v = (size_t) (handle);
      if (v >= M.origin.size()) {
        MSQ_SETERR(err)("MeshDomainGFace: VertexHandle not found", MsqError::INVALID_ARG);
        return;
      }
      MVertex* mv = M.origin[v];
      if (mv == NULL) {
        MSQ_SETERR(err)("MeshDomainGFace: MVertex* is null", MsqError::INVALID_ARG);
        return;
      }
      SPoint3 query(position.x(),position.y(),position.z());
      GPoint proj = project(mv,query);
      if (proj.succeeded()) {
        closest.set(proj.x(),proj.y(),proj.z());
        GFace* cgf = dynamic_cast<GFace*>(mv->onWhat());
        if (cgf != NULL) {
          SPoint2 uv(proj.u(),proj.v());
          SVector3 n = gf->normal(uv);
          normal.set(n.data());
        } else {
          normal.set(0.,0.,0.);
        }
        return;
      } else {
        GFace* dgf = dynamic_cast<GFace*>(mv->onWhat());
        SPoint3 clp;
        bool okc = closestBoundaryPoint(M, query, clp);
        if (okc) {
          closest.set(clp.data());
          normal.set(0.,0.,0.);
          return;
        }
        Msg::Debug("MeshDomainGFace::closest_point(): failed to projected vertex %li, query=(%f,%f,%f)", v, query.x(),query.y(),query.z());
        GEdge* dge = dynamic_cast<GEdge*>(mv->onWhat());
        GVertex* dgv = dynamic_cast<GVertex*>(mv->onWhat());
        Msg::Debug(" entity casts: GFace* %p, GEdge* %p, GVertex* %p", dgf, dge, dgv);
        MSQ_SETERR(err)("MeshDomainGFace::closest_point(): projection failed", MsqError::INVALID_ARG);
      } 
    }

    void domain_DoF( const Mesh::VertexHandle* handle_array,
        unsigned short* dof_array,
        size_t num_vertices,
        MsqError& err ) const {
      for (size_t i = 0; i < num_vertices; ++i) {
        size_t v = (size_t) handle_array[i];
        MVertex* mv = M.origin[v];
        GFace* cur_gf = dynamic_cast<GFace*>(mv->onWhat());
        if (cur_gf != NULL) {
          dof_array[i] = 2;
        } else {
          GEdge* ge = dynamic_cast<GEdge*>(mv->onWhat());
          if (ge != NULL) {
            dof_array[i] = 0;
          } else {
            GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
            if (gv != NULL) {
              dof_array[i] = 0;
            } else {
              MSQ_SETERR(err)("MeshDomainGFace: MVertex* has no valid entity", MsqError::INVALID_ARG);
              return;
            }
          }
        }
      }
    }

  private:
    GFace* gf;
    const QuadMeshData& M;
};

class MeshDomainSurfaceProjector : public MeshDomain
{
  public:

    MeshDomainSurfaceProjector(SurfaceProjector * sp_, const QuadMeshData& M_, bool useRealCAD_ = false): sp(sp_), M(M_), useRealCAD(useRealCAD_) {
      projectionCache = new std::unordered_map<Mesh::VertexHandle,size_t>;
    }

    virtual ~MeshDomainSurfaceProjector() {
      delete projectionCache;
    }

    void snap_to( Mesh::VertexHandle entity_handle, Vector3D& coordinat ) const {
      size_t cache = (*projectionCache)[entity_handle];
      SPoint3 query(coordinat.x(),coordinat.y(),coordinat.z());
      GPoint proj = sp->closestPoint(query.data(),cache,true,useRealCAD);
      if (proj.succeeded()) {
        coordinat.set(proj.x(),proj.y(),proj.z());
        (*projectionCache)[entity_handle] = cache;
      } else {
        Msg::Debug("MeshDomainSurfaceProjector::snap_to(): failed to projected query=(%f,%f,%f)", query.x(),query.y(),query.z());
      }
    }

    void vertex_normal_at( Mesh::VertexHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t cache = (*projectionCache)[entity_handle];
      SPoint3 query(coordinate.x(),coordinate.y(),coordinate.z());
      GPoint proj = sp->closestPoint(query.data(),cache,true,useRealCAD);
      if (proj.succeeded()) {
        SPoint2 uv(proj.u(),proj.v());
        SVector3 n = sp->gf->normal(uv);
        // n = -1. * n;
        coordinate.set(n.data());
        (*projectionCache)[entity_handle] = cache;
      } else {
        Msg::Debug("MeshDomainSurfaceProjector::vertex_normal_at(): failed to projected query=(%f,%f,%f)", query.x(),query.y(),query.z());
        coordinate.set(0.,0.,0.);
      }
    }

    void element_normal_at( Mesquite::Mesh::ElementHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t f = (size_t) (entity_handle);
      // TODO: project center and use CAD normal ?
      double n[3];
      quad_normal(M.coords.data(), M.quads[4*f+0], M.quads[4*f+1], M.quads[4*f+2], M.quads[4*f+3], n);
      coordinate.set(n);
    }

    void vertex_normal_at( const Mesh::VertexHandle* handles,
        Vector3D coordinates[],
        unsigned count,
        MsqError& err ) const {
      for (size_t i = 0; i < count; ++i) {
        vertex_normal_at(handles[i], coordinates[i]);
      }
      return;
    }

    void closest_point( Mesh::VertexHandle handle,
        const Vector3D& position,
        Vector3D& closest,
        Vector3D& normal,
        MsqError& err ) const {
      size_t cache = (*projectionCache)[handle];
      SPoint3 query(position.x(),position.y(),position.z());
      GPoint proj = sp->closestPoint(query.data(),cache,true,useRealCAD);
      if (proj.succeeded()) {
        closest.set(proj.x(),proj.y(),proj.z());
        SPoint2 uv(proj.u(),proj.v());
        SVector3 n = sp->gf->normal(uv);
        // n = -1. * n;
        normal.set(n.data());
        (*projectionCache)[handle] = cache;
      } else {
        Msg::Debug("MeshDomainSurfaceProjector::closestPoint(): failed to projected query=(%f,%f,%f)", query.x(),query.y(),query.z());
        MSQ_SETERR(err)("MeshDomainGFace::closest_point(): projection failed", MsqError::INVALID_ARG);
      }
    }

    void domain_DoF( const Mesh::VertexHandle* handle_array,
        unsigned short* dof_array,
        size_t num_vertices,
        MsqError& err ) const {
      for (size_t i = 0; i < num_vertices; ++i) {
        size_t v = (size_t) handle_array[i];
        MVertex* mv = M.origin[v];
        GFace* cur_gf = dynamic_cast<GFace*>(mv->onWhat());
        if (cur_gf != NULL) {
          dof_array[i] = 2;
        } else {
          GEdge* ge = dynamic_cast<GEdge*>(mv->onWhat());
          if (ge != NULL) {
            dof_array[i] = 1;
          } else {
            GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
            if (gv != NULL) {
              dof_array[i] = 0;
            } else {
              MSQ_SETERR(err)("MeshDomainSurfaceProjector: MVertex* has no valid entity", MsqError::INVALID_ARG);
              return;
            }
          }
        }
      }
    }

  private:
    SurfaceProjector* sp;
    const QuadMeshData& M;
    std::unordered_map<Mesh::VertexHandle,size_t>* projectionCache;
    bool useRealCAD;
};




int optimizeQuadGeometry(GFace* gf) {

  try {
    std::unordered_map<MVertex*,size_t> old2new;
    QuadMeshData M;
    fillDataFromGFace(gf, M, old2new);

    Mesquite::ArrayMesh mesh(3, 
        M.coords.size()/3,M.coords.data(),M.fixed.data(),
        M.quads.size()/4,Mesquite::QUADRILATERAL,M.quads.data());

    MeshDomainGFace domain(gf, M);

    for (size_t i = 0; i < M.origin.size(); ++i) {
      MVertex* v = M.origin[i];
      GEntity* ent = v->onWhat();
      if (dynamic_cast<GEdge*>(ent) != NULL) {
        M.fixed[i] = 1;
      } else if (dynamic_cast<GVertex*>(ent) != NULL) {
        M.fixed[i] = 1;
      }
    }

    Mesquite::MeshDomainAssoc mesh_and_domain(&mesh,&domain,true);
    Mesquite::MsqPrintError err(std::cout);

    bool untangle = true;
    if (untangle) {
      Mesquite::UntangleWrapper smoother;
      // smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::SHAPESIZE);
      smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::BETA);
      smoother.set_vertex_movement_limit_factor(1.e-3);
      // smoother.enable_culling(true);
      if (Msg::GetVerbosity() < 99) {
        smoother.quality_assessor().disable_printing_results();
      }
      smoother.run_instructions(&mesh_and_domain, err); 
    } else {
      Mesquite::ShapeImprovementWrapper smoother;
      if (Msg::GetVerbosity() < 99) {
        smoother.quality_assessor().disable_printing_results();
      }
      smoother.run_instructions(&mesh_and_domain, err); 
    }

    for (size_t i = 0; i < M.origin.size(); ++i) {
      M.origin[i]->x() = M.coords[3*i+0];
      M.origin[i]->y() = M.coords[3*i+1];
      M.origin[i]->z() = M.coords[3*i+2];
    }
  } catch (...) {
    Msg::Error("- Face %i: failed to optimize with Mesquite (%li quads)", gf->tag(), gf->quadrangles.size());
  }

  return 0;
}

void computeQualitySICN(const std::vector<MElement*>& elements, std::vector<double>& quality,
    double& minSICN, double& avgSICN) {
  minSICN = DBL_MAX;
  avgSICN = 0.;
  quality.resize(elements.size());
  for (size_t i = 0; i < elements.size(); ++i)  {
    quality[i] = elements[i]->minSICNShapeMeasure();
    minSICN = std::min(minSICN,quality[i]);
    avgSICN += quality[i];
  }
  if (elements.size() > 0) avgSICN /= double(elements.size());
}

void computeQualitySICN(const std::vector<MQuadrangle*>& elements, std::vector<double>& quality,
    double& minSICN, double& avgSICN) {
  minSICN = DBL_MAX;
  avgSICN = 0.;
  quality.resize(elements.size());
  for (size_t i = 0; i < elements.size(); ++i)  {
    quality[i] = elements[i]->minSICNShapeMeasure();
    minSICN = std::min(minSICN,quality[i]);
    avgSICN += quality[i];
  }
  if (elements.size() > 0) avgSICN /= double(elements.size());
}
int quadQualityStats(const std::vector<MElement*>& elements, double& qualityMin, double& qualityAvg) {
  vector<double> quality(elements.size());
  computeQualitySICN(elements, quality, qualityMin, qualityAvg);
  return 0;
}
int quadQualityStats(const std::vector<MQuadrangle*>& elements, double& qualityMin, double& qualityAvg) {
  vector<double> quality(elements.size());
  computeQualitySICN(elements, quality, qualityMin, qualityAvg);
  return 0;
}

int optimizeQuadCavity(
    const MesquiteOptions& opt,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    double& qualityMin,
    double& qualityAvg) {
  if (elements.size() == 0 || freeVertices.size() == 0) return 0;

  double minSICN, avgSICN;
  try {
    quadQualityStats(elements, minSICN, avgSICN);

    std::unordered_map<MVertex*,size_t> old2new;
    QuadMeshData M;
    fillDataFromCavity(elements, freeVertices, M, old2new);

    Mesquite::ArrayMesh mesh(3, 
        M.coords.size()/3,M.coords.data(),M.fixed.data(),
        M.quads.size()/4,Mesquite::QUADRILATERAL,M.quads.data());

    MeshDomainSurfaceProjector domain(sp, M, opt.use_real_CAD);

    bool full_compatibility_check = false;
    bool proceed = true;
    bool skip_compatibility_check = true;
    Mesquite::MeshDomainAssoc mesh_and_domain(&mesh,&domain,full_compatibility_check,proceed,skip_compatibility_check);
    Mesquite::MsqPrintError err(std::cout);

    bool untangle = (minSICN < 0.);
    if (untangle) {
      Mesquite::UntangleWrapper smoother;
      // smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::SHAPESIZE);
      smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::BETA);
      smoother.set_vertex_movement_limit_factor(1.e-3);
      // smoother.enable_culling(true);
      if (Msg::GetVerbosity() < 999) {
        smoother.quality_assessor().disable_printing_results();
      }
      if (opt.cpu_time_limit_sec != 0.) smoother.set_cpu_time_limit(opt.cpu_time_limit_sec);
      smoother.run_instructions(&mesh_and_domain, err); 
      for (size_t i = 0; i < freeVertices.size(); ++i) {
        M.origin[i]->x() = M.coords[3*i+0];
        M.origin[i]->y() = M.coords[3*i+1];
        M.origin[i]->z() = M.coords[3*i+2];
      }
      double minSICNb = minSICN;
      quadQualityStats(elements, minSICN, avgSICN);
      Msg::Debug("- Untangling of (%li quads, %li free vertices) with Mesquite: SICN %f -> %f", elements.size(), freeVertices.size(), minSICNb, minSICN);
    }

    if (minSICN > 0.) {
      if (opt.smoother == MesquiteShapeImprovement) {
        Mesquite::ShapeImprovementWrapper smoother;
        smoother.quality_assessor().disable_printing_results();
        if (Msg::GetVerbosity() < 999) smoother.quality_assessor().disable_printing_results();
        smoother.run_instructions(&mesh_and_domain, err); 
      } else if (opt.smoother == MesquitePaverMinEdgeLengthWrapper) {
        double relative_vtx_movement = 1.e-2;
        Mesquite::PaverMinEdgeLengthWrapper smoother(relative_vtx_movement);
        if (Msg::GetVerbosity() < 999) {
          smoother.quality_assessor().disable_printing_results();
        }
        smoother.run_instructions(&mesh_and_domain, err); 
      }

      for (size_t i = 0; i < freeVertices.size(); ++i) {
        M.origin[i]->x() = M.coords[3*i+0];
        M.origin[i]->y() = M.coords[3*i+1];
        M.origin[i]->z() = M.coords[3*i+2];
      }
      double minSICNb = minSICN;
      quadQualityStats(elements, minSICN, avgSICN);
      Msg::Debug("- Optimization of (%li quads, %li free vertices) with Mesquite: SICN %f -> %f", elements.size(), freeVertices.size(), minSICNb, minSICN);
    }
  } catch (...) {
    Msg::Error("- failed to optimize with Mesquite (%li quads)", elements.size());
  }

  qualityMin = minSICN;
  qualityAvg = avgSICN;

  return 0;
}

bool growCavity(
    const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
    vector<MElement*>& elements,
    int n = 1)  {

  vector<MElement*> bdr = elements;
  vector<MElement*> newElements;
  for (size_t iter = 0; iter < (size_t) n; ++iter) {
    newElements.clear();
    for (MElement* e: bdr) {
      for (size_t j=0;j<e->getNumVertices();j++){
        MVertex* v = e->getVertex(j);
        auto it = adj.find(v);
        if (it == adj.end()) {
          Msg::Error("growCavity: vertex %li not found in adj", v->getNum());
          continue;
        }
        for (MElement* e2: it->second) {
          newElements.push_back(e2);
        }
      }
    }
    sort_unique(newElements);
    bdr = newElements;
    append(elements,newElements);
    sort_unique(elements);
  }

  return true;
}

enum LocalSmoother {
  LS_MesquiteUntangler,
  LS_MesquiteShapeImprovement,
  LS_MesquitePaverMinEdgeLengthWrapper,
  LS_Winslow,
  LS_Laplacian,
  LS_SmartLaplacian,
};

bool tryLocalSmoothing(
    LocalSmoother smoother,
    GFace* gf,
    SurfaceProjector* sp,
    std::vector<MElement*>& elements,
    int iterMax,
    /* Conditions to keep the smoothing */
    double minimumQuality = 0.,
    double factorOnQualityMin = 1.,
    double factorOnQualityAvg = 1.,
    bool useRealCAD = false,
    double mesquiteTimeBudget = 1.)
{
  vector<MVertex*> bnd;
  bool okb = buildBoundary(elements, bnd);
  if (!okb) {
    Msg::Error("tryLocalSmoothing: failed to build boundary (%li quads)", elements.size());
    return false;
  }

  std::vector<MVertex*> freeVertices;
  bool oki = verticesStrictlyInside(elements, bnd, freeVertices);
  if (!oki) {
    Msg::Error("tryLocalSmoothing: failed to get vertices inside");
    return -1;
  }

  /* Save in case of deterioration */
  std::vector<SPoint3> before(freeVertices.size());
  for (size_t v = 0; v < freeVertices.size(); ++v) {
    before[v] = freeVertices[v]->point();
  }

  std::vector<MQuadrangle*> quads(elements.size());
  for (size_t i = 0; i < elements.size(); ++i) {
    quads[i] = dynamic_cast<MQuadrangle*>(elements[i]);
    if (quads[i] == NULL) {
      Msg::Error("tryLocalSmoothing: element is not a quad");
      return false;
    }
  }

  double minSICNb = DBL_MAX;
  double avgSICNb = 0.;
  quadQualityStats(elements, minSICNb, avgSICNb);

  bool keep = true;

  if (smoother == LS_Winslow) {
    meshWinslow2d(gf, quads, freeVertices, iterMax, NULL, false, sp);
  } else if (smoother == LS_MesquiteUntangler 
      || smoother == LS_MesquiteShapeImprovement 
      || smoother == LS_MesquitePaverMinEdgeLengthWrapper) {
    MesquiteOptions opt;
    opt.smoother = MesquiteUntangler;
    if (smoother == LS_MesquiteShapeImprovement) opt.smoother = MesquiteShapeImprovement;
    if (smoother == LS_MesquitePaverMinEdgeLengthWrapper) opt.smoother = MesquitePaverMinEdgeLengthWrapper;
    opt.outer_iteration_limit = iterMax;
    opt.cpu_time_limit_sec = mesquiteTimeBudget;
    opt.use_real_CAD = useRealCAD;
    double qmin, qavg;
    int ok = optimizeQuadCavity(opt, sp, elements, freeVertices, qmin, qavg);
    if (ok != 0) keep = false;
  } else {
    Msg::Warning("local smoother not supported yet");
    return false;
  }

  double minSICNa = DBL_MAX;
  double avgSICNa = 0.;
  quadQualityStats(elements, minSICNa, avgSICNa);

  Msg::Debug("- local smoothing, cavity with %li quads: SICN min: %f -> %f, avg: %f -> %f",
      elements.size(),minSICNb,minSICNa,avgSICNb,avgSICNa);

  if (minSICNa < factorOnQualityMin * minSICNb) keep = false;
  if (avgSICNa < factorOnQualityAvg * avgSICNa) keep = false;
  if (minSICNa < minimumQuality && minSICNa < minSICNb) keep = false;

  if (!keep) {
    Msg::Debug("-- smoothing rejected, roll back (stats were SICN min: %f -> %f, avg: %f -> %f)",
        elements.size(),minSICNb,minSICNa,avgSICNb,avgSICNa);
    for (size_t v = 0; v < freeVertices.size(); ++v) {
      freeVertices[v]->setXYZ(before[v].x(),before[v].y(),before[v].z());
    }
    return false;
  }

  return true;
}

int optimizeQuadMeshWithSubPatches(
    GFace* gf,
    SurfaceProjector* sp,
    double& qualityMin,
    double& qualityAvg) {
  if (gf->quadrangles.size() == 0) return 0;

  double minSICNb = DBL_MAX;
  double avgSICNb = 0.;
  quadQualityStats(gf->quadrangles, minSICNb, avgSICNb);

  vector<MElement*> elements(gf->quadrangles.size());
  for (size_t i = 0; i < gf->quadrangles.size(); ++i) {
    elements[i] = dynamic_cast<MQuadrangle*>(gf->quadrangles[i]);
  }
  vector<MVertex*> freeVertices = gf->mesh_vertices;

  /* Vertex to elements map */
  robin_hood::unordered_map<MVertex *, std::vector<MElement *> > adj;
  for (MElement* e: elements) {
    for (size_t i=0;i<e->getNumVertices();i++){
      MVertex* v = e->getVertex(i);
      adj[v].push_back(e);
    }
  }

  double qMin = DBL_MAX;
  double qAvg = 0.;
  robin_hood::unordered_flat_map<MElement*,double> quality;
  for (MElement* e: elements) {
    double q = e->minSICNShapeMeasure();
    quality[e] = q;
    qMin = std::min(qMin,q);
    qAvg += q;
  }
  qAvg /= double(elements.size());

  /* Local optimization loop */
  bool running = true;
  size_t iter = 0;
  size_t iterMax = 5;
  vector<std::pair<double,MElement*> > quality_elt;
  while (running && iter < iterMax) {
    running = false;
    iter += 1;
    quality_elt.clear();
    for (auto& kv: quality) if (kv.second < qAvg) {
      quality_elt.push_back({kv.second,kv.first});
    }
    std::sort(quality_elt.begin(),quality_elt.end());

    double q025 = quality_elt[quality_elt.size()/4].first;

    vector<MElement*> quads;
    for (auto& kv: quality_elt) {
      MElement* e = kv.second;
      double qual = quality[e];
      if (qual > q025) continue;
      quads = {e};
      growCavity(adj, quads, 3);

      double factorOnQualityMin = 0.999;
      double factorOnQualityAvg = 0.75;
      double qMin = factorOnQualityMin*kv.first;
      LocalSmoother smoother;
      if (qual <= 0.) {
        smoother = LS_MesquiteUntangler;
        qMin = 0.;
      } else if (qual <= 0.2) {
        smoother = LS_MesquiteShapeImprovement;
      } else {
        smoother = LS_Winslow;
        factorOnQualityAvg = 1.;
      }
      int iterMaxLocal = 10;
      bool useRealCAD = (qual <= 0.);
      double timeBudget = (qual <= 0.) ? 5. : 1.;
      bool okw = tryLocalSmoothing(smoother, gf, sp, quads, iterMaxLocal, 
          qMin,
          factorOnQualityMin, factorOnQualityAvg, useRealCAD, timeBudget);
      if (okw) {
        for (MElement* q: elements) {
          quality[q] = q->minSICNShapeMeasure();
        }
      }

      running = true;
    }
  }


  double minSICNa = DBL_MAX;
  double avgSICNa = 0.;
  quadQualityStats(gf->quadrangles, minSICNa, avgSICNa);

  if (minSICNa < 0.) {
    Msg::Error("- Face %i: local smoothing, SICN min: %f -> %f, avg: %f -> %f",
        gf->tag(),minSICNb,minSICNa,avgSICNb,avgSICNa);
  } else {
    Msg::Info("- Face %i: local smoothing, SICN min: %f -> %f, avg: %f -> %f",
        gf->tag(),minSICNb,minSICNa,avgSICNb,avgSICNa);
  }

  return 0;
}

#else

int optimizeQuadCavity(
    const MesquiteOptions& opt,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    std::vector<SPoint3>& freePositions,
    double& qualityMin,
    double& qualityAvg) {
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
  return -1;
}

int optimizeQuadGeometry(GFace* gf) {
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
  return -1;
}

int optimizeQuadMeshWithSubPatches(
    GFace* gf,
    SurfaceProjector* sp,
    double& qualityMin,
    double& qualityAvg
    ){
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
  return -1;
}

#endif
