// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Refinement of the pdel3d mesh: rounds of candidate points, one per tet that
// is too large for the mesh size, filtered and inserted all at once by the
// parallel Delaunay kernel (after HXT's hxt_tetRefine.c)

#include <algorithm>
#include <cmath>
#include <cfloat>
#include "pdel3d.h"
#include "GmshMessage.h"
#include "OS.h"

namespace pdel3d {

  namespace {

    inline double sqDist(const double *a, const double *b)
    {
      const double dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
      return dx * dx + dy * dy + dz * dz;
    }

    inline bool tooClose(double s0, double s1, double d2,
                         const RefineOptions &opt)
    {
      if(s0 > 0. && s1 > 0.) {
        const double s =
          std::min(opt.sizeMax, std::max(opt.sizeMin, 0.5 * (s0 + s1))) *
          opt.sizeFactor;
        return d2 < s * s;
      }
      return false;
    }

    // A point inside the tet of nodes p[4] (with sizes s[4]) likely to respect
    // the mesh size: the circumcenter of the tet measured in edge lengths
    // normalized by the sizes, or, when it falls outside the tet or too close
    // to a node, a point between the centroid and the isotomic conjugate of
    // the incenter. center[3] receives the size interpolated there. Returns
    // true when even that point is too close to a node (from HXT)
    bool bestCenter(const double p[4][4], const double nodalSize[4],
                    double center[4], const RefineOptions &opt)
    {
      double avg = 0., num = 0.;
      for(int i = 0; i < 4; i++) {
        if(nodalSize[i] > 0.) {
          avg += nodalSize[i];
          num += 1.;
        }
      }
      avg = num ? avg / num : 1.;
      const double s0 = nodalSize[0] > 0. ? nodalSize[0] : avg;
      const double s1 = nodalSize[1] > 0. ? nodalSize[1] : avg;
      const double s2 = nodalSize[2] > 0. ? nodalSize[2] : avg;
      const double s3 = nodalSize[3] > 0. ? nodalSize[3] : avg;
      // (edge length / mean size over the edge)^2
      const double e0l2 = sqDist(p[0], p[1]) / (0.25 * (s0 + s1) * (s0 + s1));
      const double e1l2 = sqDist(p[0], p[2]) / (0.25 * (s0 + s2) * (s0 + s2));
      const double e2l2 = sqDist(p[0], p[3]) / (0.25 * (s0 + s3) * (s0 + s3));
      const double e3l2 = sqDist(p[1], p[2]) / (0.25 * (s1 + s2) * (s1 + s2));
      const double e4l2 = sqDist(p[1], p[3]) / (0.25 * (s1 + s3) * (s1 + s3));
      const double e5l2 = sqDist(p[2], p[3]) / (0.25 * (s2 + s3) * (s2 + s3));
      // the tet with those edge lengths: O = (0,0,0), A = (xa,0,0),
      // B = (xb,yb,0), C = (xc,yc,zc)
      const double xa = std::sqrt(e0l2);
      const double invtwoxa = 1. / (2 * xa);
      const double xb = (e1l2 + e0l2 - e3l2) * invtwoxa;
      const double yb = std::sqrt(e1l2 - xb * xb);
      const double xc = (e2l2 + e0l2 - e4l2) * invtwoxa;
      const double yc = (e1l2 + e2l2 - e5l2 - 2 * xb * xc) / (2 * yb);
      const double zc = std::sqrt(e2l2 - xc * xc - yc * yc);
      const double xcrossbc = yb * zc, ycrossbc = -zc * xb,
                   zcrossbc = xb * yc - xc * yb;
      const double ycrossca = zc * xa, zcrossca = -xa * yc, zcrossab = xa * yb;
      const double denominator = 0.5 / (xa * yb * zc);
      const double xcirca = 0.5 * xa;
      const double ycirca = (e0l2 * ycrossbc + e1l2 * ycrossca) * denominator;
      const double zcirca =
        (e0l2 * zcrossbc + e1l2 * zcrossca + e2l2 * zcrossab) * denominator;
      double bary0 =
        (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
        (2. * denominator);
      double bary1 =
        (ycirca * ycrossca + zcirca * zcrossca) * (2. * denominator);
      double bary2 = (zcirca * zcrossab) * (2. * denominator);
      double bary3 = 1. - bary0 - bary1 - bary2;
      bool circumcenterOutside = false, circumcenterTooClose = false;
      if(bary0 > 0. && bary1 > 0. && bary2 > 0. && bary3 > 0.) {
        center[0] =
          bary0 * p[0][0] + bary1 * p[1][0] + bary2 * p[2][0] + bary3 * p[3][0];
        center[1] =
          bary0 * p[0][1] + bary1 * p[1][1] + bary2 * p[2][1] + bary3 * p[3][1];
        center[2] =
          bary0 * p[0][2] + bary1 * p[1][2] + bary2 * p[2][2] + bary3 * p[3][2];
        center[3] = bary0 * s0 + bary1 * s1 + bary2 * s2 + bary3 * s3;
        circumcenterTooClose =
          tooClose(s0, center[3], sqDist(p[0], center), opt) ||
          tooClose(s1, center[3], sqDist(p[1], center), opt) ||
          tooClose(s2, center[3], sqDist(p[2], center), opt) ||
          tooClose(s3, center[3], sqDist(p[3], center), opt);
      }
      else // also when a barycentric coordinate is not finite
        circumcenterOutside = true;
      bool otherCenterTooClose = false;
      if(circumcenterOutside || circumcenterTooClose) {
        // the sum of the cross products of the facets of a tet is zero
        const double xsumcros = xcrossbc, ysumcros = ycrossbc + ycrossca;
        const double zsumcros = zcrossab + zcrossbc + zcrossca;
        const double invA0x2 =
          1. / std::sqrt(xsumcros * xsumcros + ysumcros * ysumcros +
                         zsumcros * zsumcros);
        const double invA1x2 =
          1. / std::sqrt(xcrossbc * xcrossbc + ycrossbc * ycrossbc +
                         zcrossbc * zcrossbc);
        const double invA2x2 =
          1. / std::sqrt(ycrossca * ycrossca + zcrossca * zcrossca);
        const double invA3x2 = 1. / zcrossab;
        const double den = invA0x2 + invA1x2 + invA2x2 + invA3x2;
        const double alpha = 0.5;
        bary0 = (1. - alpha) * 0.25 + alpha * invA0x2 / den;
        bary1 = (1. - alpha) * 0.25 + alpha * invA1x2 / den;
        bary2 = (1. - alpha) * 0.25 + alpha * invA2x2 / den;
        bary3 = (1. - alpha) * 0.25 + alpha * invA3x2 / den;
        if(!std::isfinite(bary0) || !std::isfinite(bary1) ||
           !std::isfinite(bary2) || !std::isfinite(bary3))
          bary0 = bary1 = bary2 = bary3 = 0.25;
        double other[4];
        other[0] =
          bary0 * p[0][0] + bary1 * p[1][0] + bary2 * p[2][0] + bary3 * p[3][0];
        other[1] =
          bary0 * p[0][1] + bary1 * p[1][1] + bary2 * p[2][1] + bary3 * p[3][1];
        other[2] =
          bary0 * p[0][2] + bary1 * p[1][2] + bary2 * p[2][2] + bary3 * p[3][2];
        other[3] = bary0 * s0 + bary1 * s1 + bary2 * s2 + bary3 * s3;
        otherCenterTooClose =
          tooClose(s0, other[3], sqDist(p[0], other), opt) ||
          tooClose(s1, other[3], sqDist(p[1], other), opt) ||
          tooClose(s2, other[3], sqDist(p[2], other), opt) ||
          tooClose(s3, other[3], sqDist(p[3], other), opt);
        if(circumcenterOutside || !otherCenterTooClose) {
          for(int k = 0; k < 4; k++) center[k] = other[k];
        }
      }
      return otherCenterTooClose;
    }

    // drop the vertices from `first` on that no tet references, renumbering
    // the nodes of the tets
    void removeUnusedTail(Mesh &m, std::size_t first)
    {
      const std::size_t nv = m.numVertices();
      if(first >= nv) return;
      std::vector<vIdx> newIndex(nv - first, GHOST);
      for(std::size_t t = 0; t < m.ntet; t++) {
        if(m.isDeleted((tIdx)t)) continue;
        for(int k = 0; k < 4; k++) {
          const vIdx v = m.node[4 * t + k];
          if(v != GHOST && v >= first) newIndex[v - first] = 0;
        }
      }
      vIdx n = (vIdx)first;
      for(std::size_t v = first; v < nv; v++) {
        if(newIndex[v - first] == GHOST) continue;
        newIndex[v - first] = n;
        if(n != v)
          for(int k = 0; k < 4; k++) m.xyz[4 * n + k] = m.xyz[4 * v + k];
        n++;
      }
      if(n == nv) return;
      m.xyz.resize(4 * n);
      for(std::size_t t = 0; t < m.ntet; t++) {
        if(m.isDeleted((tIdx)t)) continue;
        for(int k = 0; k < 4; k++) {
          const vIdx v = m.node[4 * t + k];
          if(v != GHOST && v >= first) m.node[4 * t + k] = newIndex[v - first];
        }
      }
    }

  } // namespace

  void refine(Mesh &m, RefineOptions &opt)
  {
    const double t0 = TimeOfDay();
    const int nthreads = std::max(1, opt.numThreads);
    // only the tets of the volumes are refined
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t)) continue;
      if(m.color[t] >= opt.numVolumes)
        m.flag[t] |= F_PROCESSED;
      else
        m.flag[t] &= ~F_PROCESSED;
    }
    DelaunayOptions dopt;
    dopt.numThreads = nthreads;
    dopt.perfectDelaunay = false;
    dopt.allowOuterInsertion = false;
    dopt.filterOnSize = true;
    dopt.sizeMin = opt.sizeMin;
    dopt.sizeMax = opt.sizeMax;
    dopt.sizeFactor = opt.sizeFactor;
    dopt.verbosity = opt.verbosity - 1;
    DelaunayStats stats;
    std::size_t totalCandidates = 0, totalInserted = 0;
    double timeCandidates = 0., timeSizes = 0.;
    std::vector<std::vector<double>> localPts(nthreads);
    std::vector<std::vector<tIdx>> localTets(nthreads);
    for(int iter = 0; iter < 42; iter++) {
      const double t1 = TimeOfDay();
      // one candidate per unprocessed tet, in the order of the tets
      const std::size_t ntet = m.ntet;
      std::size_t numCandidates = 0;
#pragma omp parallel num_threads(nthreads)
      {
        const int tid = Msg::GetThreadNum();
        std::vector<double> &pts = localPts[tid];
        std::vector<tIdx> &tets = localTets[tid];
        pts.clear();
        tets.clear();
#pragma omp for schedule(static)
        for(std::size_t t = 0; t < ntet; t++) {
          if(m.flag[t] & (F_PROCESSED | F_DELETED)) continue;
          m.flag[t] |= F_PROCESSED;
          double p[4][4], s[4];
          for(int i = 0; i < 4; i++) {
            const vIdx v = m.node[4 * t + i];
            for(int k = 0; k < 3; k++) p[i][k] = m.xyz[4 * v + k];
            s[i] = m.xyz[4 * v + 3];
          }
          double center[4];
          if(bestCenter(p, s, center, opt) && !opt.sizeCallback) continue;
          pts.insert(pts.end(), center, center + 4);
          tets.push_back((tIdx)t);
        }
      }
      std::vector<std::size_t> offset(nthreads + 1, 0);
      for(int i = 0; i < nthreads; i++)
        offset[i + 1] = offset[i] + localTets[i].size();
      numCandidates = offset[nthreads];
      if(!numCandidates) break;
      std::vector<double> pts(4 * numCandidates);
      std::vector<tIdx> tets(numCandidates);
      for(int i = 0; i < nthreads; i++) {
        std::copy(localPts[i].begin(), localPts[i].end(),
                  pts.begin() + 4 * offset[i]);
        std::copy(localTets[i].begin(), localTets[i].end(),
                  tets.begin() + offset[i]);
      }
      totalCandidates += numCandidates;
      const double t2 = TimeOfDay();
      // the mesh sizes at the candidates
      if(opt.sizeCallback) {
        std::vector<std::uint32_t> colors(numCandidates);
        for(std::size_t i = 0; i < numCandidates; i++)
          colors[i] = m.color[tets[i]];
        opt.sizeCallback(pts.data(), colors.data(), numCandidates,
                         opt.sizeData);
      }
      const double t3 = TimeOfDay();
      // keep the candidates far enough from the nodes of their tet, appended
      // to the mesh vertices
      const std::size_t first = m.numVertices();
      std::vector<vIdx> toInsert;
      for(std::size_t i = 0; i < numCandidates; i++) {
        const double *c = &pts[4 * i];
        if(c[3] <= 0.) continue;
        const vIdx *n = &m.node[4 * tets[i]];
        bool close = false;
        for(int k = 0; k < 4 && !close; k++) {
          const double *q = &m.xyz[4 * n[k]];
          close = tooClose(q[3], c[3], sqDist(q, c), opt);
        }
        if(close) continue;
        toInsert.push_back((vIdx)m.numVertices());
        m.xyz.insert(m.xyz.end(), c, c + 4);
      }
      if(toInsert.empty()) break;
      if(opt.verbosity > 0)
        Msg::Info("Refinement round %d: %lu candidates from %lu tets, %lu kept",
                  iter, numCandidates, ntet, toInsert.size());
      dopt.partitionability = 1. - std::pow(0.5, iter);
      std::vector<std::uint8_t> status;
      const std::size_t before = stats.inserted;
      insertVertices(m, dopt, toInsert, status, &stats);
      removeUnusedTail(m, first);
      timeCandidates += t2 - t1;
      timeSizes += t3 - t2;
      totalInserted += stats.inserted - before;
      if(stats.inserted == before) break;
    }
    if(opt.verbosity > 0)
      Msg::Info("Refinement: %lu nodes inserted out of %lu candidates in %lu "
                "rounds (Wall %gs: candidates "
                "%g, sizes %g, sort %g, insert %g)",
                totalInserted, totalCandidates, stats.rounds, TimeOfDay() - t0,
                timeCandidates, timeSizes, stats.timeSort, stats.timeInsert);
  }

} // namespace pdel3d
