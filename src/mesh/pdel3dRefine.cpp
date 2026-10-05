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
#include <memory>
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

    // drop the vertices from `first` on that were not inserted (status[i]
    // is the status of toInsert[i]), renumbering the nodes of the tets
    void compactNewVertices(Mesh &m, std::size_t first,
                            const std::vector<vIdx> &toInsert,
                            const std::vector<std::uint8_t> &status,
                            int nthreads)
    {
      const std::size_t nv = m.numVertices(), nnew = nv - first;
      std::vector<vIdx> newIndex(nnew, GHOST);
      for(std::size_t i = 0; i < toInsert.size(); i++)
        if(status[i] == ST_INSERTED) newIndex[toInsert[i] - first] = 0;
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
      m.numDefaultDist = std::min(m.numDefaultDist, first);
#pragma omp parallel for schedule(static) num_threads(nthreads)
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
#pragma omp parallel for schedule(static) num_threads(nthreads)
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
    dopt.curveFilterWindow = opt.curveFilterWindow;
    dopt.compact = false; // once at the end
    dopt.verbosity = opt.verbosity;
    DelaunayStats stats;
    std::size_t totalCandidates = 0, totalInserted = 0, totalKept = 0;
    double timeCandidates = 0., timeSizes = 0., timeCompact = 0.;
    std::vector<std::vector<double>> localPts(nthreads);
    std::vector<std::vector<tIdx>> localTets(nthreads);
    std::size_t lastKept = m.ntet / 8;
    for(int iter = 0; iter < 42; iter++) {
      const double t1 = TimeOfDay();
      // one candidate per unprocessed tet; the unprocessed tets are the new
      // ones, gathered at the end of the array, hence the dynamic schedule.
      // The candidates are processed in batches per thread: the size
      // callback gives them their size, and those too close to a node of
      // their tet are dropped, while the nodes are still in cache
      const std::size_t ntet = m.ntet;
      std::size_t numCandidates = 0;
      std::vector<double> localTimeSizes(nthreads, 0.);
#pragma omp parallel num_threads(nthreads) reduction(+ : numCandidates)
      {
        const int tid = Msg::GetThreadNum();
        double &timeSizesLocal = localTimeSizes[tid];
        std::vector<double> &pts = localPts[tid];
        std::vector<tIdx> &tets = localTets[tid];
        pts.clear();
        tets.clear();
        const std::size_t expected = lastKept / nthreads + 4096;
        pts.reserve(4 * (expected + expected / 4));
        tets.reserve(expected + expected / 4);
        constexpr std::size_t B = 2048;
        double bpts[4 * B];
        tIdx btets[B];
        std::uint32_t bcolors[B];
        std::size_t nb = 0;
        auto flush = [&]() {
          if(opt.sizeCallback) {
            const double ts = TimeOfDay();
            opt.sizeCallback(bpts, bcolors, nb, opt.sizeData);
            timeSizesLocal += TimeOfDay() - ts;
          }
          for(std::size_t i = 0; i < nb; i++) {
            const double *q = &bpts[4 * i];
            bool close = q[3] <= 0.;
            const vIdx *n = &m.node[4 * btets[i]];
            for(int k = 0; k < 4 && !close; k++) {
              const double *x = &m.xyz[4 * n[k]];
              close = tooClose(x[3], q[3], sqDist(x, q), opt);
            }
            if(close) continue;
            pts.insert(pts.end(), q, q + 4);
            tets.push_back(btets[i]);
          }
          numCandidates += nb;
          nb = 0;
        };
#pragma omp for schedule(dynamic, 4096) nowait
        for(std::size_t t = 0; t < ntet; t++) {
          if(m.flag[t] & (F_PROCESSED | F_DELETED)) continue;
          m.flag[t] |= F_PROCESSED;
          double p[4][4], s[4];
          for(int i = 0; i < 4; i++) {
            const vIdx v = m.node[4 * t + i];
            for(int k = 0; k < 3; k++) p[i][k] = m.xyz[4 * v + k];
            s[i] = m.xyz[4 * v + 3];
          }
          double *center = &bpts[4 * nb];
          if(bestCenter(p, s, center, opt) && !opt.sizeCallback) continue;
          btets[nb] = (tIdx)t;
          bcolors[nb] = m.color[t];
          if(++nb == B) flush();
        }
        flush();
      }
      totalCandidates += numCandidates;
      if(!numCandidates) break;
      // the candidates kept, appended to the mesh vertices
      std::vector<std::size_t> offset(nthreads + 1, 0);
      for(int i = 0; i < nthreads; i++)
        offset[i + 1] = offset[i] + localTets[i].size();
      const std::size_t numKept = offset[nthreads];
      lastKept = numKept;
      const std::size_t first = m.numVertices();
      std::vector<vIdx> toInsert(numKept);
      std::vector<tIdx> hints(numKept);
      if(m.xyz.capacity() < 4 * (first + numKept))
        m.xyz.reserve(4 * (first + numKept) + 2 * (first + numKept));
      m.xyz.resize(4 * (first + numKept));
#pragma omp parallel for schedule(static) num_threads(nthreads)
      for(int i = 0; i < nthreads; i++) {
        std::copy(localPts[i].begin(), localPts[i].end(),
                  &m.xyz[4 * (first + offset[i])]);
        for(std::size_t j = 0; j < localTets[i].size(); j++) {
          toInsert[offset[i] + j] = (vIdx)(first + offset[i] + j);
          hints[offset[i] + j] = localTets[i][j];
        }
      }
      const double t4 = TimeOfDay();
      const double timeSizesRound =
        *std::max_element(localTimeSizes.begin(), localTimeSizes.end());
      timeSizes += timeSizesRound;
      if(toInsert.empty()) break;
      totalKept += toInsert.size();
      if(opt.verbosity > 0)
        Msg::Info("Refinement round %d: %lu candidates from %lu tets, %lu kept",
                  iter, numCandidates, ntet, toInsert.size());
      dopt.partitionability = 1. - std::pow(0.5, iter);
      dopt.numVerticesInMesh = first;
      std::vector<std::uint8_t> status;
      const std::size_t before = stats.inserted;
      insertVertices(m, dopt, toInsert, status, &stats, &hints);
      const double t5 = TimeOfDay();
      compactNewVertices(m, first, toInsert, status, nthreads);
      timeCandidates += t4 - t1 - timeSizesRound;
      timeCompact += TimeOfDay() - t5;
      totalInserted += stats.inserted - before;
      if(stats.inserted == before) break;
    }
    const double t6 = TimeOfDay();
    m.removeDeleted(nthreads);
    timeCompact += TimeOfDay() - t6;
    m.removeDeleted();
    if(opt.verbosity > 0)
      Msg::Info(
        "Refinement: %lu nodes inserted out of %lu candidates (%lu "
        "kept, %lu filtered on the curve, %lu in their cavity) in %lu "
        "rounds (Wall %gs: candidates %g, sizes %g, sort %g, insert %g, "
        "compaction %g)",
        totalInserted, totalCandidates, totalKept, stats.curveFiltered,
        stats.filtered, stats.rounds, TimeOfDay() - t0, timeCandidates,
        timeSizes, stats.timeSort, stats.timeInsert, timeCompact);
  }

} // namespace pdel3d
