// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

#include "meshGRegionOptimizeFlat.h"
#include "meshGRegionLocalMeshMod.h"
#include "GRegion.h"
#include "GEntity.h"
#include "GmshMessage.h"
#include "MTetrahedron.h"
#include "MVertex.h"
#include "Context.h"
#include "OS.h"

// Flat port of optimizeMesh(): the mesh is held in index-based arrays (four
// vertex indices and four packed neighbors per tet, coordinates per vertex)
// instead of MTet4 wrappers over MTetrahedron over MVertex. The optimization
// itself is unchanged - sweep the tets, edge-swap the ones below the quality
// threshold, then relocate the nodes of those that remain - but the sweeps
// walk contiguous arrays, the adjacency is built once on dense indices, and
// a swap rewrites integers instead of allocating elements.

namespace {

const std::uint32_t FLAT_NONE = 0xffffffff;

// the same local numbering as the object-based operators
const int fEdges[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
const int fEfaces[6][2] = {{0, 2}, {0, 1}, {1, 2}, {0, 3}, {2, 3}, {1, 3}};
const int fFaces[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2, 3}};
const int fVFac[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2, 3}};

struct flatOpt {
  const qmTetrahedron::Measures qm;

  // vertices
  std::vector<double> xyz; // 3 per vertex
  std::vector<MVertex *> vPtr;
  std::vector<std::uint8_t> movable; // relocatable, i.e. strictly inside

  // tets
  std::vector<std::uint32_t> tetV; // 4 vertex indices
  std::vector<std::uint32_t> tetN; // 4 packed neighbors (4 * tet + face)
  std::vector<double> tetQual;
  std::vector<std::uint8_t> tetDeleted;
  std::vector<MTetrahedron *> tetMT; // element object, null for created tets
  std::vector<std::uint32_t> freeSlots;

  flatOpt(const qmTetrahedron::Measures &m) : qm(m) {}

  std::size_t nTets() const { return tetQual.size(); }

  const double *pt(std::uint32_t v) const { return &xyz[3 * v]; }

  double quality(std::uint32_t t, double *volume) const
  {
    const std::uint32_t *v = &tetV[4 * t];
    const double *a = pt(v[0]), *b = pt(v[1]), *c = pt(v[2]), *d = pt(v[3]);
    return qmTetrahedron::qm(a[0], a[1], a[2], b[0], b[1], b[2], c[0], c[1],
                             c[2], d[0], d[1], d[2], qm, volume);
  }
  // same value as fabs(MTetrahedron::getVolume())
  double volume(std::uint32_t t) const
  {
    const std::uint32_t *v = &tetV[4 * t];
    const double *a = pt(v[0]), *b = pt(v[1]), *c = pt(v[2]), *d = pt(v[3]);
    const double ax = b[0] - a[0], ay = b[1] - a[1], az = b[2] - a[2];
    const double bx = c[0] - a[0], by = c[1] - a[1], bz = c[2] - a[2];
    const double cx = d[0] - a[0], cy = d[1] - a[1], cz = d[2] - a[2];
    return fabs((ax * (by * cz - bz * cy) - ay * (bx * cz - bz * cx) +
                 az * (bx * cy - by * cx)) / 6.);
  }

  std::uint32_t newSlot()
  {
    if(!freeSlots.empty()) {
      std::uint32_t s = freeSlots.back();
      freeSlots.pop_back();
      tetDeleted[s] = 0;
      tetMT[s] = nullptr;
      for(int k = 0; k < 4; k++) tetN[4 * s + k] = FLAT_NONE;
      return s;
    }
    std::uint32_t s = (std::uint32_t)nTets();
    tetV.resize(tetV.size() + 4);
    tetN.resize(tetN.size() + 4, FLAT_NONE);
    tetQual.push_back(0.);
    tetDeleted.push_back(0);
    tetMT.push_back(nullptr);
    return s;
  }

  bool importRegion(GRegion *gr);
  void buildAdjacencies();
  void connectLocal(const std::vector<std::uint32_t> &tets);
  bool buildEdgeCavity(std::uint32_t t, int iLocalEdge, std::uint32_t &v1,
                       std::uint32_t &v2, std::vector<std::uint32_t> &cavity,
                       std::vector<std::uint32_t> &outside,
                       std::vector<std::uint32_t> &ring);
  bool edgeSwap(std::uint32_t t, int iLocalEdge, int &nbCreated);
  bool vertexCavity(std::uint32_t t, std::uint32_t vIdx,
                    std::vector<std::uint32_t> &cavity);
  bool smoothVertex(std::uint32_t t, int iVertex);
  void exportRegion(GRegion *gr);
};

// Import the tets of a region. Vertex indices are assigned densely, in the
// order the tets reference them; returns false if anything the flat path
// does not handle is met.
bool flatOpt::importRegion(GRegion *gr)
{
  const std::size_t n = gr->tetrahedra.size();
  tetV.resize(4 * n);
  tetN.assign(4 * n, FLAT_NONE);
  tetQual.resize(n);
  tetDeleted.assign(n, 0);
  tetMT.resize(n);

  // mark all the vertices in play, then number them
  for(std::size_t i = 0; i < n; i++)
    for(int k = 0; k < 4; k++) gr->tetrahedra[i]->getVertex(k)->setIndex(-1);

  std::uint32_t nv = 0;
  for(std::size_t i = 0; i < n; i++) {
    MTetrahedron *mt = gr->tetrahedra[i];
    tetMT[i] = mt;
    for(int k = 0; k < 4; k++) {
      MVertex *mv = mt->getVertex(k);
      if(mv->getIndex() < 0) {
        mv->setIndex((int)nv);
        vPtr.push_back(mv);
        xyz.push_back(mv->x());
        xyz.push_back(mv->y());
        xyz.push_back(mv->z());
        movable.push_back(mv->onWhat() && mv->onWhat()->dim() == 3 ? 1 : 0);
        nv++;
      }
      tetV[4 * i + k] = (std::uint32_t)mv->getIndex();
    }
  }
  return true;
}

// Bucket the faces on their smallest vertex (a counting sort), then sort
// each bucket on the two others: the two copies of a face end up adjacent.
void flatOpt::buildAdjacencies()
{
  struct tetFace {
    std::uint32_t v1, v2, t, i;
    bool operator<(const tetFace &o) const
    {
      if(v1 != o.v1) return v1 < o.v1;
      return v2 < o.v2;
    }
  };
  const std::size_t nv = vPtr.size();
  std::vector<std::uint32_t> start(nv + 1, 0);
  for(std::size_t t = 0; t < nTets(); t++) {
    if(tetDeleted[t]) continue;
    const std::uint32_t *v = &tetV[4 * t];
    for(int j = 0; j < 4; j++) {
      std::uint32_t a = std::min(std::min(v[fFaces[j][0]], v[fFaces[j][1]]),
                                 v[fFaces[j][2]]);
      start[a + 1]++;
    }
  }
  for(std::size_t i = 1; i <= nv; i++) start[i] += start[i - 1];
  const std::size_t nf = start[nv];
  if(!nf) return;

  std::vector<tetFace> sorted(nf);
  {
    std::vector<std::uint32_t> cursor(start.begin(), start.end() - 1);
    for(std::size_t t = 0; t < nTets(); t++) {
      if(tetDeleted[t]) continue;
      const std::uint32_t *v = &tetV[4 * t];
      for(int j = 0; j < 4; j++) {
        std::uint32_t a = v[fFaces[j][0]], b = v[fFaces[j][1]],
                      c = v[fFaces[j][2]];
        if(a > b) std::swap(a, b);
        if(b > c) std::swap(b, c);
        if(a > b) std::swap(a, b);
        tetFace &f = sorted[cursor[a]++];
        f.v1 = b;
        f.v2 = c;
        f.t = (std::uint32_t)t;
        f.i = (std::uint32_t)j;
      }
    }
  }
  for(std::size_t v = 0; v < nv; v++) {
    const std::size_t b = start[v], e = start[v + 1];
    if(e - b < 2) continue;
    std::sort(sorted.begin() + b, sorted.begin() + e);
    for(std::size_t k = b; k + 1 < e; k++) {
      if(sorted[k].v1 == sorted[k + 1].v1 && sorted[k].v2 == sorted[k + 1].v2) {
        const tetFace &f1 = sorted[k], &f2 = sorted[k + 1];
        tetN[4 * f1.t + f1.i] = 4 * f2.t + f2.i;
        tetN[4 * f2.t + f2.i] = 4 * f1.t + f1.i;
        k++;
      }
    }
  }
}

// reconnect a handful of tets after a local modification: same face
// matching, on an array small enough to sort directly
void flatOpt::connectLocal(const std::vector<std::uint32_t> &tets)
{
  struct tetFace {
    std::uint32_t v0, v1, v2, t, i;
    bool operator<(const tetFace &o) const
    {
      if(v0 != o.v0) return v0 < o.v0;
      if(v1 != o.v1) return v1 < o.v1;
      return v2 < o.v2;
    }
  };
  std::vector<tetFace> conn;
  conn.reserve(4 * tets.size());
  for(auto t : tets) {
    if(tetDeleted[t]) continue;
    const std::uint32_t *v = &tetV[4 * t];
    for(int j = 0; j < 4; j++) {
      std::uint32_t a = v[fFaces[j][0]], b = v[fFaces[j][1]],
                    c = v[fFaces[j][2]];
      if(a > b) std::swap(a, b);
      if(b > c) std::swap(b, c);
      if(a > b) std::swap(a, b);
      conn.push_back({a, b, c, t, (std::uint32_t)j});
    }
  }
  std::sort(conn.begin(), conn.end());
  for(std::size_t k = 0; k + 1 < conn.size(); k++) {
    const tetFace &f1 = conn[k], &f2 = conn[k + 1];
    if(f1.v0 == f2.v0 && f1.v1 == f2.v1 && f1.v2 == f2.v2 && f1.t != f2.t) {
      tetN[4 * f1.t + f1.i] = 4 * f2.t + f2.i;
      tetN[4 * f2.t + f2.i] = 4 * f1.t + f1.i;
      k++;
    }
  }
}

// same walk as buildEdgeCavity(): turn around the edge, collecting the tets
// that share it and the ring of opposite vertices
bool flatOpt::buildEdgeCavity(std::uint32_t t, int iLocalEdge,
                              std::uint32_t &v1, std::uint32_t &v2,
                              std::vector<std::uint32_t> &cavity,
                              std::vector<std::uint32_t> &outside,
                              std::vector<std::uint32_t> &ring)
{
  cavity.clear();
  ring.clear();

  v1 = tetV[4 * t + fEdges[iLocalEdge][0]];
  v2 = tetV[4 * t + fEdges[iLocalEdge][1]];

  std::uint32_t lastinring = tetV[4 * t + fEdges[5 - iLocalEdge][0]];
  ring.push_back(lastinring);
  cavity.push_back(t);

  while(1) {
    std::uint32_t ov1 = tetV[4 * t + fEdges[5 - iLocalEdge][0]];
    std::uint32_t ov2 = tetV[4 * t + fEdges[5 - iLocalEdge][1]];
    int K = ov1 == lastinring ? 1 : 0;
    lastinring = ov1 == lastinring ? ov2 : ov1;
    int iFace;
    const int iFace1 = fEfaces[iLocalEdge][0];
    const int iFace2 = fEfaces[iLocalEdge][1];
    const int want = fEdges[5 - iLocalEdge][K];
    if(fFaces[iFace1][0] == want || fFaces[iFace1][1] == want ||
       fFaces[iFace1][2] == want)
      iFace = iFace1;
    else if(fFaces[iFace2][0] == want || fFaces[iFace2][1] == want ||
            fFaces[iFace2][2] == want)
      iFace = iFace2;
    else
      return false;

    const std::uint32_t np = tetN[4 * t + iFace];
    if(np == FLAT_NONE) return false;
    t = np >> 2;
    if(tetDeleted[t]) return false;
    if(t == cavity[0]) break;
    ring.push_back(lastinring);
    cavity.push_back(t);
    iLocalEdge = -1;
    for(int i = 0; i < 6; i++) {
      const std::uint32_t a = tetV[4 * t + fEdges[i][0]];
      const std::uint32_t b = tetV[4 * t + fEdges[i][1]];
      if((a == v1 && b == v2) || (a == v2 && b == v1)) {
        iLocalEdge = i;
        break;
      }
    }
    if(iLocalEdge == -1) return false;
    if(cavity.size() > 1000) return false;
  }

  // the tets around the cavity, whose adjacency the swap rewrites
  outside.clear();
  for(auto c : cavity) {
    for(int j = 0; j < 4; j++) {
      const std::uint32_t np = tetN[4 * c + j];
      if(np == FLAT_NONE) continue;
      const std::uint32_t nb = np >> 2;
      if(std::find(cavity.begin(), cavity.end(), nb) != cavity.end()) continue;
      if(std::find(outside.begin(), outside.end(), nb) == outside.end())
        outside.push_back(nb);
    }
  }
  return true;
}

// same decision and same retriangulation as edgeSwap()
bool flatOpt::edgeSwap(std::uint32_t tet, int iLocalEdge, int &nbCreated)
{
  static const int permut[6] = {0, 3, 1, 2, 5, 4};
  iLocalEdge = permut[iLocalEdge];

  static thread_local std::vector<std::uint32_t> cavity, outside, ring, touched;
  std::uint32_t v1, v2;
  if(!buildEdgeCavity(tet, iLocalEdge, v1, v2, cavity, outside, ring))
    return false;

  double volumeRef = 0.0;
  double tetQualityRef = 1.;
  for(auto c : cavity) {
    volumeRef += volume(c);
    tetQualityRef = std::min(tetQualityRef, tetQual[c]);
  }

  SwapPattern sp;
  switch(ring.size()) {
  case 3: BuildSwapPattern3(&sp); break;
  case 4: BuildSwapPattern4(&sp); break;
  case 5: BuildSwapPattern5(&sp); break;
  case 6: BuildSwapPattern6(&sp); break;
  case 7: BuildSwapPattern7(&sp); break;
  default: return false;
  }

  double tetQuality1[100], tetQuality2[100], volume1[100], volume2[100];
  for(int i = 0; i < sp.nbr_triangles; i++) {
    const double *p1 = pt(ring[sp.triangles[i][0]]);
    const double *p2 = pt(ring[sp.triangles[i][1]]);
    const double *p3 = pt(ring[sp.triangles[i][2]]);
    const double *a = pt(v1), *b = pt(v2);
    tetQuality1[i] =
      qmTetrahedron::qm(p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], p3[0], p3[1],
                        p3[2], a[0], a[1], a[2], qm, &(volume1[i]));
    tetQuality2[i] =
      qmTetrahedron::qm(p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], p3[0], p3[1],
                        p3[2], b[0], b[1], b[2], qm, &(volume2[i]));
  }

  double minQuality[100];
  for(int i = 0; i < sp.nbr_trianguls; i++) {
    minQuality[i] = 1;
    double vol = 0;
    for(int j = 0; j < sp.nbr_triangles_2; j++) {
      const int iT = sp.trianguls[i][j];
      minQuality[i] = std::min(minQuality[i], tetQuality1[iT]);
      minQuality[i] = std::min(minQuality[i], tetQuality2[iT]);
      vol += (volume1[iT] + volume2[iT]);
    }
    if(fabs(vol - volumeRef) > 1.e-10 * (vol + volumeRef)) minQuality[i] = -1;
  }

  int iBest = 0;
  double best = -1.0;
  for(int i = 0; i < sp.nbr_trianguls; i++) {
    if(minQuality[i] > best) {
      best = minQuality[i];
      iBest = i;
    }
  }
  if(best <= tetQualityRef + 1e-20) return false;

  // the cavity is replaced by the tets of the best retriangulation
  for(auto c : cavity) {
    tetDeleted[c] = 1;
    freeSlots.push_back(c);
  }
  touched = outside;
  for(int j = 0; j < sp.nbr_triangles_2; j++) {
    const int iT = sp.trianguls[iBest][j];
    const std::uint32_t p1 = ring[sp.triangles[iT][0]];
    const std::uint32_t p2 = ring[sp.triangles[iT][1]];
    const std::uint32_t p3 = ring[sp.triangles[iT][2]];
    const std::uint32_t s1 = newSlot();
    tetV[4 * s1 + 0] = p1;
    tetV[4 * s1 + 1] = p2;
    tetV[4 * s1 + 2] = p3;
    tetV[4 * s1 + 3] = v1;
    tetQual[s1] = tetQuality1[iT];
    const std::uint32_t s2 = newSlot();
    tetV[4 * s2 + 0] = p3;
    tetV[4 * s2 + 1] = p2;
    tetV[4 * s2 + 2] = p1;
    tetV[4 * s2 + 3] = v2;
    tetQual[s2] = tetQuality2[iT];
    touched.push_back(s1);
    touched.push_back(s2);
    nbCreated += 2;
  }

  // the faces of the cavity tets no longer exist: their outside neighbors
  // are relinked by the local reconnection below
  for(auto o : touched) {
    if(tetDeleted[o]) continue;
    for(int j = 0; j < 4; j++) {
      const std::uint32_t np = tetN[4 * o + j];
      if(np != FLAT_NONE && tetDeleted[np >> 2]) tetN[4 * o + j] = FLAT_NONE;
    }
  }
  connectLocal(touched);
  return true;
}

// same cavity as buildVertexCavity_recur()
bool flatOpt::vertexCavity(std::uint32_t t, std::uint32_t vIdx,
                           std::vector<std::uint32_t> &cavity)
{
  int iV = -1;
  for(int i = 0; i < 4; i++) {
    if(tetV[4 * t + i] == vIdx) {
      iV = i;
      break;
    }
  }
  if(iV == -1) return false;
  for(int i = 0; i < 3; i++) {
    const std::uint32_t np = tetN[4 * t + fVFac[iV][i]];
    if(np == FLAT_NONE || tetDeleted[np >> 2]) continue;
    const std::uint32_t nb = np >> 2;
    if(std::find(cavity.begin(), cavity.end(), nb) == cavity.end()) {
      cavity.push_back(nb);
      if(cavity.size() > 1000) return false;
      if(!vertexCavity(nb, vIdx, cavity)) return false;
    }
  }
  return true;
}

// same relocation as smoothVertex(): move the node to the volume-weighted
// centroid of its cavity, and keep the move only if it does not degrade the
// worst quality nor the total volume
bool flatOpt::smoothVertex(std::uint32_t t, int iVertex)
{
  const std::uint32_t vIdx = tetV[4 * t + iVertex];
  if(!movable[vIdx]) return false;

  static thread_local std::vector<std::uint32_t> cavity;
  static thread_local std::vector<double> newQuals;
  cavity.clear();
  cavity.push_back(t);
  if(!vertexCavity(t, vIdx, cavity)) return false;

  double xcg = 0, ycg = 0, zcg = 0, vTot = 0, worst = 1.0;
  for(auto c : cavity) {
    const double vol = volume(c);
    worst = std::min(worst, tetQual[c]);
    const std::uint32_t *v = &tetV[4 * c];
    for(int k = 0; k < 4; k++) {
      xcg += 0.25 * xyz[3 * v[k] + 0] * vol;
      ycg += 0.25 * xyz[3 * v[k] + 1] * vol;
      zcg += 0.25 * xyz[3 * v[k] + 2] * vol;
    }
    vTot += vol;
  }
  xcg /= vTot;
  ycg /= vTot;
  zcg /= vTot;

  const double x = xyz[3 * vIdx + 0], y = xyz[3 * vIdx + 1],
               z = xyz[3 * vIdx + 2];
  xyz[3 * vIdx + 0] = xcg;
  xyz[3 * vIdx + 1] = ycg;
  xyz[3 * vIdx + 2] = zcg;

  double volumeAfter = 0.0, worstAfter = 1.0;
  newQuals.resize(cavity.size());
  for(std::size_t i = 0; i < cavity.size(); i++) {
    double vol;
    newQuals[i] = quality(cavity[i], &vol);
    volumeAfter += vol;
    worstAfter = std::min(worstAfter, newQuals[i]);
  }

  if(fabs(volumeAfter - vTot) > 1.e-10 * (volumeAfter + vTot) ||
     worstAfter < worst) {
    xyz[3 * vIdx + 0] = x;
    xyz[3 * vIdx + 1] = y;
    xyz[3 * vIdx + 2] = z;
    return false;
  }
  for(std::size_t i = 0; i < cavity.size(); i++)
    tetQual[cavity[i]] = newQuals[i];
  return true;
}

// hand the mesh back: the elements of the tets that survived are reused,
// the ones of the deleted tets are recycled for the tets the swaps created
void flatOpt::exportRegion(GRegion *gr)
{
  for(std::size_t i = 0; i < vPtr.size(); i++) {
    if(movable[i]) {
      vPtr[i]->x() = xyz[3 * i + 0];
      vPtr[i]->y() = xyz[3 * i + 1];
      vPtr[i]->z() = xyz[3 * i + 2];
    }
  }

  std::vector<MTetrahedron *> spare;
  for(std::size_t t = 0; t < nTets(); t++) {
    if(tetDeleted[t] && tetMT[t]) {
      spare.push_back(tetMT[t]);
      tetMT[t] = nullptr;
    }
  }

  gr->tetrahedra.clear();
  gr->tetrahedra.reserve(nTets());
  std::size_t iSpare = 0;
  for(std::size_t t = 0; t < nTets(); t++) {
    if(tetDeleted[t]) continue;
    const std::uint32_t *v = &tetV[4 * t];
    MTetrahedron *mt = tetMT[t];
    if(!mt) {
      if(iSpare < spare.size()) {
        mt = spare[iSpare++];
        for(int k = 0; k < 4; k++) mt->setVertex(k, vPtr[v[k]]);
      }
      else {
        mt = new MTetrahedron(vPtr[v[0]], vPtr[v[1]], vPtr[v[2]], vPtr[v[3]]);
      }
    }
    gr->tetrahedra.push_back(mt);
  }
  for(; iSpare < spare.size(); iSpare++) delete spare[iSpare];
}

} // namespace

bool optimizeMeshFlat(GRegion *gr, const qmTetrahedron::Measures &qm)
{
  const double qMin = CTX::instance()->mesh.optimizeThreshold;
  if(qMin <= 0.0) return true;
  if(gr->tetrahedra.empty()) return true;

  // the flat path handles plain tetrahedral regions only
  if(!gr->hexahedra.empty() || !gr->prisms.empty() || !gr->pyramids.empty())
    return false;
  if(!gr->embeddedFaces().empty() || !gr->embeddedEdges().empty() ||
     !gr->embeddedVertices().empty())
    return false;

  double w1 = TimeOfDay();

  flatOpt K(qm);
  if(!K.importRegion(gr)) return false;
  K.buildAdjacencies();

  for(std::size_t t = 0; t < K.nTets(); t++) {
    double vol;
    K.tetQual[t] = K.quality((std::uint32_t)t, &vol);
  }

  {
    double worst = 1.0, avg = 0.;
    std::size_t count = 0;
    for(std::size_t t = 0; t < K.nTets(); t++) {
      worst = std::min(worst, K.tetQual[t]);
      avg += K.tetQual[t];
      count++;
    }
    Msg::Info("Optimization starts with worst = %g / average = %g:", worst,
              count ? avg / count : 0.);
  }

  int nbESwap = 0, nbReloc = 0;
  double worstA = 0.0;

  while(1) {
    int nbCreated = 0;
    const std::size_t nBefore = K.nTets();
    for(std::size_t t = 0; t < nBefore; t++) {
      if(K.tetDeleted[t]) continue;
      if(K.tetQual[t] < qMin) {
        for(int i = 0; i < 6; i++) {
          if(K.edgeSwap((std::uint32_t)t, i, nbCreated)) {
            nbESwap++;
            break;
          }
        }
      }
    }
    if(!nbCreated) break;

    for(std::size_t t = 0; t < K.nTets(); t++) {
      if(K.tetDeleted[t]) continue;
      if(K.tetQual[t] < qMin) {
        for(int i = 0; i < 4; i++) {
          if(K.smoothVertex((std::uint32_t)t, i)) nbReloc++;
        }
      }
    }

    double worst = 1.0, avg = 0.;
    std::size_t count = 0;
    for(std::size_t t = 0; t < K.nTets(); t++) {
      if(K.tetDeleted[t]) continue;
      worst = std::min(worst, K.tetQual[t]);
      avg += K.tetQual[t];
      count++;
    }
    Msg::Info("%d edge swaps, %d node relocations: worst = %g / average = %g "
              "(Wall %gs)",
              nbESwap, nbReloc, worst, count ? avg / count : 0.,
              TimeOfDay() - w1);
    if(worstA != 0.0 && worst - worstA < 1.e-6) break;
    worstA = worst;
  }

  {
    double vol = 0., worst = 1.0, avg = 0.;
    std::size_t count = 0;
    for(std::size_t t = 0; t < K.nTets(); t++) {
      if(K.tetDeleted[t]) continue;
      vol += K.volume((std::uint32_t)t);
      worst = std::min(worst, K.tetQual[t]);
      avg += K.tetQual[t];
      count++;
    }
    Msg::Info("Optimization done (volume = %g) with worst = %g / average = %g:",
              vol, worst, count ? avg / count : 0.);
  }

  K.exportRegion(gr);
  return true;
}
