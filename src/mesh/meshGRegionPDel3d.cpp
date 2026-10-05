// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include "GmshConfig.h"
#include "meshGRegionPDel3d.h"
#include "pdel3d.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"
#include "GmshMessage.h"
#include "BackgroundMeshTools.h"
#include "Context.h"
#include "OS.h"

#include "meshGRegion.h"
#include "meshGRegionBoundaryRecovery.h"

static int numThreads3D()
{
  int n = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    n = CTX::instance()->mesh.maxNumThreads3D;
  if(!n) n = Msg::GetMaxThreads();
  return n;
}

void delaunayMeshIn3DPDel3d(std::vector<MVertex *> &v,
                            std::vector<MTetrahedron *> &tets)
{
  const double t0 = TimeOfDay();
  const std::size_t n = v.size();
  pdel3d::Mesh m;
  m.xyz.resize(4 * n);
  for(std::size_t i = 0; i < n; i++) {
    m.xyz[4 * i + 0] = v[i]->x();
    m.xyz[4 * i + 1] = v[i]->y();
    m.xyz[4 * i + 2] = v[i]->z();
    m.xyz[4 * i + 3] = 0.;
  }
  m.reserveTets(8 * n + 16384);
  std::vector<pdel3d::vIdx> toInsert(n);
  std::iota(toInsert.begin(), toInsert.end(), 0);
  std::vector<std::uint8_t> status;
  pdel3d::DelaunayOptions opt;
  opt.numThreads = numThreads3D();
  opt.reorderVertices = true; // toInsert[i] = original index of vertex i
  opt.verbosity = Msg::GetVerbosity() > 5 ? 2 : 1;
  pdel3d::DelaunayStats stats;
  pdel3d::insertVertices(m, opt, toInsert, status, &stats);
  if(Msg::GetVerbosity() > 5) m.verify(true);
  tets.reserve(m.numRealTets());
  for(std::size_t t = 0; t < m.ntet; t++) {
    if(m.isGhost((pdel3d::tIdx)t)) continue;
    const pdel3d::vIdx *nd = &m.node[4 * t];
    tets.push_back(new MTetrahedron(v[toInsert[nd[0]]], v[toInsert[nd[1]]],
                                    v[toInsert[nd[2]]], v[toInsert[nd[3]]]));
  }
  Msg::Info("pdel3d: %lu points, %lu tets (Wall %gs: sort %g, insert %g)", n,
            tets.size(), TimeOfDay() - t0, stats.timeSort, stats.timeInsert);
}

// ---------------------------------------------------------------------------
// volume meshing
// ---------------------------------------------------------------------------

namespace {

  // the surface mesh of a group of regions, in pdel3d numbering
  struct SurfaceMesh {
    std::vector<GFace *> surfaces;
    std::vector<GEdge *> curves;
    std::vector<GVertex *> points;
    std::vector<MVertex *> vertices; // index -> vertex
    std::vector<pdel3d::vIdx> triNode, lineNode, pointNode;
    std::vector<std::uint32_t> triColor, lineColor;
    // surface tags bounding (or embedded in) each region
    std::vector<std::vector<std::uint32_t>> volumes;
    // the surfaces forming a compound with each surface (a member may carry
    // no element when the elements are classified on the originals)
    std::map<std::uint32_t, std::vector<std::uint32_t>> siblings;
  };

  // returns false when the input is not supported (non-triangular elements).
  // The surfaces are the boundary and embedded surfaces of the regions (a
  // compound surface replacing its members when their elements are not
  // reclassified on them); the curves to preserve are the ones embedded in
  // the regions, the others being edges of the surface triangles
  bool collectSurfaceMesh(std::vector<GRegion *> &regions, SurfaceMesh &s)
  {
    std::set<GFace *, GEntityPtrLessThan> surfaces;
    std::set<GEdge *, GEntityPtrLessThan> curves;
    const bool compounds = (CTX::instance()->mesh.compoundClassify == 0);
    auto surface = [&](GFace *gf) {
      return (compounds && gf->compoundSurface) ? gf->compoundSurface : gf;
    };
    for(GRegion *gr : regions) {
      std::set<std::uint32_t> tags;
      for(GFace *gf : gr->faces()) {
        surfaces.insert(surface(gf));
        tags.insert(surface(gf)->tag());
      }
      for(GFace *gf : gr->embeddedFaces()) {
        surfaces.insert(surface(gf));
        tags.insert(surface(gf)->tag());
      }
      s.volumes.push_back(std::vector<std::uint32_t>(tags.begin(), tags.end()));
      for(GEdge *ge : gr->embeddedEdges()) curves.insert(ge);
      for(GVertex *gv : gr->embeddedVertices()) s.points.push_back(gv);
    }
    for(GFace *gf : surfaces) {
      if(gf->quadrangles.size() || gf->polygons.size()) {
        Msg::Warning("Surface %d contains elements which are not triangles: "
                     "the Parallel Delaunay algorithm only supports triangles",
                     gf->tag());
        return false;
      }
    }
    s.surfaces.assign(surfaces.begin(), surfaces.end());
    s.curves.assign(curves.begin(), curves.end());
    for(GFace *gf : s.surfaces) {
      if(gf->compound.empty()) continue;
      std::vector<std::uint32_t> &sib = s.siblings[gf->tag()];
      for(GEntity *ge : gf->compound) sib.push_back(ge->tag());
    }
    // number the vertices in order of appearance
    auto index = [&](MVertex *v) -> pdel3d::vIdx {
      if(v->getIndex() < 0) {
        v->setIndex((long)s.vertices.size());
        s.vertices.push_back(v);
      }
      return (pdel3d::vIdx)v->getIndex();
    };
    for(GFace *gf : s.surfaces)
      for(MTriangle *t : gf->triangles)
        for(int k = 0; k < 3; k++) t->getVertex(k)->setIndex(-1);
    for(GEdge *ge : s.curves)
      for(MLine *l : ge->lines)
        for(int k = 0; k < 2; k++) l->getVertex(k)->setIndex(-1);
    for(GVertex *gv : s.points)
      for(MPoint *p : gv->points) p->getVertex(0)->setIndex(-1);
    for(GFace *gf : s.surfaces) {
      for(MTriangle *t : gf->triangles) {
        for(int k = 0; k < 3; k++) s.triNode.push_back(index(t->getVertex(k)));
        s.triColor.push_back(gf->tag());
      }
    }
    for(GEdge *ge : s.curves) {
      for(MLine *l : ge->lines) {
        for(int k = 0; k < 2; k++) s.lineNode.push_back(index(l->getVertex(k)));
        s.lineColor.push_back(ge->tag());
      }
    }
    for(GVertex *gv : s.points)
      for(MPoint *p : gv->points) s.pointNode.push_back(index(p->getVertex(0)));
    return true;
  }

  // mesh size at the surface vertices: the mean length of their edges in the
  // triangles and lines, and the prescribed size at embedded points
  void surfaceSizes(const SurfaceMesh &s, pdel3d::Mesh &m, double factor)
  {
    const std::size_t nv = m.numVertices();
    std::vector<double> sum(nv, 0.), count(nv, 0.);
    auto addEdge = [&](pdel3d::vIdx a, pdel3d::vIdx b) {
      const double l =
        std::sqrt(std::pow(m.xyz[4 * a] - m.xyz[4 * b], 2) +
                  std::pow(m.xyz[4 * a + 1] - m.xyz[4 * b + 1], 2) +
                  std::pow(m.xyz[4 * a + 2] - m.xyz[4 * b + 2], 2));
      sum[a] += l;
      sum[b] += l;
      count[a] += 1.;
      count[b] += 1.;
    };
    for(std::size_t i = 0; i < s.triNode.size() / 3; i++)
      for(int j = 0; j < 3; j++)
        addEdge(s.triNode[3 * i + j], s.triNode[3 * i + (j + 1) % 3]);
    for(std::size_t i = 0; i < s.lineNode.size() / 2; i++)
      addEdge(s.lineNode[2 * i], s.lineNode[2 * i + 1]);
    for(std::size_t v = 0; v < nv; v++) {
      if(m.xyz[4 * v + 3] > 0.) continue; // prescribed
      m.xyz[4 * v + 3] = count[v] > 0. ? sum[v] / (count[v] * factor) : 0.;
    }
  }

  struct SizeData {
    std::vector<GRegion *> *regions;
    bool failed;
  };

  // perturb the coordinates of the vertices by a random fraction of the
  // model size, and restore them on destruction
  class perturbedCoordinates {
  private:
    std::vector<MVertex *> _vertices;
    std::vector<double> _xyz;

  public:
    perturbedCoordinates(const std::vector<MVertex *> &vertices, double factor)
    {
      if(factor <= 0. || vertices.empty()) return;
      _vertices = vertices;
      _xyz.resize(3 * vertices.size());
      double d = 0.;
      for(std::size_t i = 0; i < vertices.size(); i++) {
        MVertex *v = vertices[i];
        _xyz[3 * i] = v->x();
        _xyz[3 * i + 1] = v->y();
        _xyz[3 * i + 2] = v->z();
        d =
          std::max(d, std::max(std::fabs(v->x()),
                               std::max(std::fabs(v->y()), std::fabs(v->z()))));
      }
      d *= std::sqrt(3.) * factor;
      std::uint32_t seed = 12345;
      auto r = [&seed]() {
        seed = seed * 1664525u + 1013904223u;
        return seed * (1. / 4294967296.);
      };
      for(MVertex *v : _vertices) {
        v->x() += d * r();
        v->y() += d * r();
        v->z() += d * r();
      }
    }
    ~perturbedCoordinates()
    {
      for(std::size_t i = 0; i < _vertices.size(); i++)
        _vertices[i]->setXYZ(_xyz[3 * i], _xyz[3 * i + 1], _xyz[3 * i + 2]);
    }
  };

  // the gmsh mesh size field at the candidate points
  void sizeCallback(double *xyzs, const std::uint32_t *color, std::size_t n,
                    void *data)
  {
    SizeData *sd = (SizeData *)data;
    std::vector<GRegion *> &regions = *sd->regions;
    const double lcGlob = CTX::instance()->lc;
    const bool extend = Extend2dMeshIn3dVolumes();
    const int nthreads = CTX::instance()->numThreadsFor(n, 1 << 12);
    bool exceptions = false;
#pragma omp parallel for schedule(dynamic, 256) num_threads(nthreads)
    for(std::size_t i = 0; i < n; i++) {
      if(exceptions || color[i] >= regions.size()) continue;
      try { // OpenMP forbids leaving the block through an exception
        const double lc =
          BGM_MeshSizeWithoutScaling(regions[color[i]], 0, 0, xyzs[4 * i],
                                     xyzs[4 * i + 1], xyzs[4 * i + 2]);
        if(extend && xyzs[4 * i + 3] > 0.)
          xyzs[4 * i + 3] = std::min(xyzs[4 * i + 3], std::min(lcGlob, lc));
        else
          xyzs[4 * i + 3] = std::min(lcGlob, lc);
      } catch(...) {
        exceptions = true;
      }
    }
    if(exceptions) sd->failed = true;
  }

  // boundary recovery with TetGen (meshGRegionBoundaryRecovery), starting
  // from the current tetrahedralization; the recovered tets (covering the
  // convex hull) come back as elements of regions[0], and the curve and
  // surface meshes may have changed (Steiner points). The mesh is rebuilt
  // from them: vertices, tets, adjacencies and ghosts
  bool recoverBoundary(pdel3d::Mesh &m, SurfaceMesh &s,
                       std::vector<GRegion *> &regions)
  {
    initialTetrahedralization init;
    init.vertices = s.vertices;
    std::vector<pdel3d::tIdx> realIndex(m.ntet, pdel3d::NO_TET);
    pdel3d::tIdx n = 0;
    for(std::size_t t = 0; t < m.ntet; t++)
      if(!m.isDeleted((pdel3d::tIdx)t) && !m.isGhost((pdel3d::tIdx)t))
        realIndex[t] = n++;
    init.tetNode.reserve(4 * n);
    init.neighbors.reserve(4 * n);
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(realIndex[t] == pdel3d::NO_TET) continue;
      for(int k = 0; k < 4; k++) {
        init.tetNode.push_back(m.node[4 * t + k]);
        const pdel3d::tRef r = m.neigh[4 * t + k];
        init.neighbors.push_back(realIndex[r >> 2] == pdel3d::NO_TET ?
                                   -1 :
                                   (std::int64_t)realIndex[r >> 2]);
      }
    }
    GRegion *gr = regions[0];
    bool ok;
    {
      regionGroupBoundary group(regions);
      for(MVertex *v : gr->mesh_vertices) v->setIndex(-1);
      ok = meshGRegionBoundaryRecovery(gr, nullptr, &init);
    }
    if(!ok) return false;
    // the surface mesh again (it may have changed), then the vertices of the
    // tets that are not in it (Steiner points in the volume)
    s = SurfaceMesh();
    if(!collectSurfaceMesh(regions, s)) return false;
    for(MVertex *v : gr->mesh_vertices) v->setIndex(-1);
    for(MTetrahedron *t : gr->tetrahedra) {
      for(int k = 0; k < 4; k++) {
        MVertex *v = t->getVertex(k);
        if(v->getIndex() < 0) {
          v->setIndex((long)s.vertices.size());
          s.vertices.push_back(v);
        }
      }
    }
    const std::size_t nv = s.vertices.size();
    m.xyz.assign(4 * nv, 0.);
    for(std::size_t v = 0; v < nv; v++) {
      m.xyz[4 * v + 0] = s.vertices[v]->x();
      m.xyz[4 * v + 1] = s.vertices[v]->y();
      m.xyz[4 * v + 2] = s.vertices[v]->z();
    }
    // the tets, oriented with orient3d(n0, n1, n2, n3) < 0
    const std::size_t ntet = gr->tetrahedra.size();
    m.ntet = 0;
    m.reserveTets(2 * ntet + 4096); // room for the ghosts
    m.ntet = ntet;
    for(std::size_t t = 0; t < ntet; t++) {
      MTetrahedron *tet = gr->tetrahedra[t];
      for(int k = 0; k < 4; k++)
        m.node[4 * t + k] = (pdel3d::vIdx)tet->getVertex(k)->getIndex();
      if(tet->getVolumeSign() < 0) std::swap(m.node[4 * t], m.node[4 * t + 1]);
      m.flag[t] = 0;
      for(int k = 0; k < 4; k++) m.neigh[4 * t + k] = pdel3d::NO_ADJ;
      delete tet;
    }
    gr->tetrahedra.clear();
    // adjacencies through the sorted facets
    struct facetKey {
      pdel3d::vIdx a, b, c;
      pdel3d::tRef ref;
    };
    std::vector<facetKey> facets(4 * ntet);
    for(std::size_t t = 0; t < ntet; t++) {
      for(unsigned f = 0; f < 4; f++) {
        pdel3d::vIdx a = m.node[4 * t + pdel3d::facetNode0(f)],
                     b = m.node[4 * t + pdel3d::facetNode1(f)],
                     c = m.node[4 * t + pdel3d::facetNode2(f)];
        if(a > b) std::swap(a, b);
        if(b > c) std::swap(b, c);
        if(a > b) std::swap(a, b);
        facets[4 * t + f] = {a, b, c, (pdel3d::tRef)(4 * t + f)};
      }
    }
    std::sort(facets.begin(), facets.end(),
              [](const facetKey &x, const facetKey &y) {
                if(x.a != y.a) return x.a < y.a;
                if(x.b != y.b) return x.b < y.b;
                return x.c < y.c;
              });
    std::vector<pdel3d::tRef> hull;
    for(std::size_t i = 0; i < facets.size();) {
      if(i + 1 < facets.size() && facets[i].a == facets[i + 1].a &&
         facets[i].b == facets[i + 1].b && facets[i].c == facets[i + 1].c) {
        m.neigh[facets[i].ref] = facets[i + 1].ref;
        m.neigh[facets[i + 1].ref] = facets[i].ref;
        i += 2;
      }
      else {
        hull.push_back(facets[i].ref);
        i++;
      }
    }
    // a ghost tet on each hull facet, connected to its neighbors through the
    // hull edges
    struct edgeKey {
      pdel3d::vIdx a, b;
      pdel3d::tRef ref;
    };
    std::vector<edgeKey> edges;
    edges.reserve(3 * hull.size());
    for(auto r : hull) {
      const pdel3d::tIdx t = r >> 2, g = (pdel3d::tIdx)m.ntet++;
      const unsigned f = r & 3;
      const pdel3d::vIdx *tn = &m.node[4 * t];
      // ballNodes order: (vta, b0, b1, b2) is a valid tet when vta is on the
      // side of the tet, so (b0, b1, b2, GHOST) is a valid ghost
      static const unsigned ballNodes[4][3] = {
        {1, 2, 3}, {2, 0, 3}, {0, 1, 3}, {1, 0, 2}};
      pdel3d::vIdx *gn = &m.node[4 * g];
      gn[0] = tn[ballNodes[f][0]];
      gn[1] = tn[ballNodes[f][1]];
      gn[2] = tn[ballNodes[f][2]];
      gn[3] = pdel3d::GHOST;
      m.flag[g] = 0;
      m.neigh[4 * g + 3] = r;
      m.neigh[r] = 4 * g + 3;
      // facet k of the ghost (k < 3) is opposite gn[k]: it holds the edge of
      // the two other hull nodes
      for(unsigned k = 0; k < 3; k++) {
        pdel3d::vIdx a = gn[(k + 1) % 3], b = gn[(k + 2) % 3];
        if(a > b) std::swap(a, b);
        edges.push_back({a, b, (pdel3d::tRef)(4 * g + k)});
      }
    }
    std::sort(edges.begin(), edges.end(),
              [](const edgeKey &x, const edgeKey &y) {
                if(x.a != y.a) return x.a < y.a;
                return x.b < y.b;
              });
    for(std::size_t i = 0; i + 1 < edges.size(); i += 2) {
      if(edges[i].a != edges[i + 1].a || edges[i].b != edges[i + 1].b) {
        Msg::Error("Hull edge without two hull facets in the recovered mesh");
        return false;
      }
      m.neigh[edges[i].ref] = edges[i + 1].ref;
      m.neigh[edges[i + 1].ref] = edges[i].ref;
    }
    m.color.assign(m.tetCapacity(), pdel3d::Mesh::COLOR_OUT);
    if(Msg::GetVerbosity() > 5) m.verify(false);
    return true;
  }

  // give the mesh to the regions: the new vertices (in the volume of the
  // tets referencing them) and the tets, created in parallel with explicit
  // numbers (the counters of the model are atomic)
  std::size_t exportMesh(pdel3d::Mesh &m, SurfaceMesh &s,
                         std::vector<GRegion *> &regions, int nthreads)
  {
    std::vector<pdel3d::vIdx> newIndex;
    m.removeUnusedVertices(newIndex, nthreads);
    const std::size_t nv = m.numVertices(), nr = regions.size();
    std::vector<MVertex *> c2v(nv, nullptr);
    std::size_t numOld = 0;
    for(std::size_t v = 0; v < s.vertices.size(); v++) {
      if(newIndex[v] == pdel3d::GHOST) continue;
      c2v[newIndex[v]] = s.vertices[v];
      numOld++;
    }
    // the surface vertices come first and are all used
    const std::size_t firstNew = numOld;
    GModel *model = regions[0]->model();
    const std::size_t baseV = model->getMaxVertexNumber(),
                      baseE = model->getMaxElementNumber();
    const int nt = std::max(1, nthreads);
    // the region of each new vertex (any tet referencing it)
    std::vector<std::uint32_t> owner(nv - firstNew, 0);
    std::vector<std::size_t> chunkTets(nt + 1, 0);
#pragma omp parallel for schedule(static) num_threads(nt)
    for(int c = 0; c < nt; c++) {
      std::size_t count = 0;
      for(std::size_t t = c * m.ntet / nt; t < (c + 1) * m.ntet / nt; t++) {
        if(m.isGhost((pdel3d::tIdx)t) || m.color[t] >= nr) continue;
        count++;
        for(int k = 0; k < 4; k++) {
          const pdel3d::vIdx v = m.node[4 * t + k];
          if(v >= firstNew) owner[v - firstNew] = m.color[t];
        }
      }
      chunkTets[c + 1] = count;
    }
    for(int c = 0; c < nt; c++) chunkTets[c + 1] += chunkTets[c];
    const std::size_t total = chunkTets[nt];
    std::vector<std::vector<std::vector<MVertex *>>> localVertices(
      nt, std::vector<std::vector<MVertex *>>(nr));
    std::vector<std::vector<std::vector<MTetrahedron *>>> localTets(
      nt, std::vector<std::vector<MTetrahedron *>>(nr));
#pragma omp parallel num_threads(nt)
    {
#pragma omp for schedule(static)
      for(int c = 0; c < nt; c++) {
        for(std::size_t v = firstNew + c * (nv - firstNew) / nt;
            v < firstNew + (c + 1) * (nv - firstNew) / nt; v++) {
          GRegion *gr = regions[owner[v - firstNew]];
          const double *x = &m.xyz[4 * v];
          c2v[v] = new MVertex(x[0], x[1], x[2], gr, baseV + 1 + v - firstNew);
          localVertices[c][owner[v - firstNew]].push_back(c2v[v]);
        }
      }
#pragma omp for schedule(static)
      for(int c = 0; c < nt; c++) {
        std::size_t rank = chunkTets[c];
        for(std::size_t t = c * m.ntet / nt; t < (c + 1) * m.ntet / nt; t++) {
          if(m.isGhost((pdel3d::tIdx)t) || m.color[t] >= nr) continue;
          const pdel3d::vIdx *n = &m.node[4 * t];
          localTets[c][m.color[t]].push_back(
            new MTetrahedron(c2v[n[0]], c2v[n[1]], c2v[n[2]], c2v[n[3]],
                             (int)(baseE + 1 + rank++)));
        }
      }
    }
    model->setMaxVertexNumber(baseV + nv - firstNew);
    model->setMaxElementNumber(baseE + total);
    for(std::size_t r = 0; r < nr; r++) {
      std::size_t numV = 0, numT = 0;
      for(int c = 0; c < nt; c++) {
        numV += localVertices[c][r].size();
        numT += localTets[c][r].size();
      }
      GRegion *gr = regions[r];
      gr->mesh_vertices.reserve(gr->mesh_vertices.size() + numV);
      gr->tetrahedra.reserve(gr->tetrahedra.size() + numT);
      for(int c = 0; c < nt; c++) {
        gr->mesh_vertices.insert(gr->mesh_vertices.end(),
                                 localVertices[c][r].begin(),
                                 localVertices[c][r].end());
        gr->tetrahedra.insert(gr->tetrahedra.end(), localTets[c][r].begin(),
                              localTets[c][r].end());
      }
    }
    return total;
  }

} // namespace

int meshGRegionPDel3d(std::vector<GRegion *> &regions)
{
  if(regions.empty()) return 0;
  const double t0 = TimeOfDay();
  const int nthreads = numThreads3D();
  const int verbosity = Msg::GetVerbosity() > 5 ? 2 : 1;
  SurfaceMesh s;
  if(!collectSurfaceMesh(regions, s)) return 2;
  // As del3d, work on slightly perturbed coordinates: the nodes of curved
  // surfaces (spheres) are cospherical to rounding, which sends every
  // in-sphere test of the tetrahedralization to the exact arithmetic. The
  // exact coordinates are restored when the mesh is handed back (the
  // optimization leaves no tet thin enough to be inverted by that)
  perturbedCoordinates perturbation(s.vertices,
                                    CTX::instance()->mesh.randFactor3d);
  pdel3d::Mesh m;
  const std::size_t nv = s.vertices.size();
  m.xyz.resize(4 * nv);
  for(std::size_t v = 0; v < nv; v++) {
    m.xyz[4 * v + 0] = s.vertices[v]->x();
    m.xyz[4 * v + 1] = s.vertices[v]->y();
    m.xyz[4 * v + 2] = s.vertices[v]->z();
    m.xyz[4 * v + 3] = 0.;
  }
  const double sizeFactor =
    CTX::instance()->mesh.lcFactor * regions[0]->getMeshSizeFactor();
  if(CTX::instance()->mesh.lcFromPoints) {
    for(GVertex *gv : s.points) {
      if(gv->prescribedMeshSizeAtVertex() == MAX_LC) continue;
      for(MPoint *p : gv->points)
        m.xyz[4 * p->getVertex(0)->getIndex() + 3] =
          gv->prescribedMeshSizeAtVertex() / sizeFactor;
    }
  }
  surfaceSizes(s, m, sizeFactor);

  // the Delaunay tetrahedralization of the surface vertices
  Msg::Info("Tetrahedrizing %lu nodes...", nv);
  m.reserveTets(10 * nv + 16384);
  m.color.resize(m.tetCapacity(), pdel3d::Mesh::COLOR_OUT);
  {
    std::vector<pdel3d::vIdx> toInsert(nv);
    std::iota(toInsert.begin(), toInsert.end(), 0);
    std::vector<std::uint8_t> status;
    pdel3d::DelaunayOptions opt;
    opt.numThreads = nthreads;
    opt.verbosity = verbosity;
    opt.reorderVertices = true;
    pdel3d::insertVertices(m, opt, toInsert, status);
    // renumber the surface mesh after the reordering
    std::vector<pdel3d::vIdx> inverse(nv);
    for(std::size_t i = 0; i < nv; i++) inverse[toInsert[i]] = (pdel3d::vIdx)i;
    std::vector<MVertex *> vertices(nv);
    for(std::size_t i = 0; i < nv; i++) {
      vertices[i] = s.vertices[toInsert[i]];
      vertices[i]->setIndex((long)i);
    }
    s.vertices.swap(vertices);
    for(auto &v : s.triNode) v = inverse[v];
    for(auto &v : s.lineNode) v = inverse[v];
    for(auto &v : s.pointNode) v = inverse[v];
    std::size_t notInserted = 0;
    for(std::size_t i = 0; i < nv; i++)
      if(status[i] != pdel3d::ST_INSERTED) notInserted++;
    if(notInserted)
      Msg::Warning("%lu surface node(s) could not be inserted (duplicates?)",
                   notInserted);
  }
  const double t1 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %lu nodes (Wall %gs)", nv, t1 - t0);

  // the surface mesh must be in the tetrahedralization
  std::vector<pdel3d::tRef> tri2tet;
  std::size_t missing = pdel3d::triangleToTetMap(m, s.triNode, tri2tet);
  std::vector<std::uint8_t> lineInTriangle;
  pdel3d::linesInTriangles(s.triNode, s.lineNode, lineInTriangle);
  std::vector<std::uint64_t> line2tet;
  std::size_t missingLines =
    pdel3d::lineToTetMap(m, s.lineNode, lineInTriangle, line2tet);
  const bool recovered = missing || missingLines;
  if(recovered) {
    Msg::Info("Recovering %lu missing triangle(s) and %lu missing line(s)...",
              missing, missingLines);
    if(!recoverBoundary(m, s, regions)) {
      Msg::Error("Boundary recovery failed");
      return 1;
    }
    if(CTX::instance()->mesh.lcFromPoints) {
      for(GVertex *gv : s.points) {
        if(gv->prescribedMeshSizeAtVertex() == MAX_LC) continue;
        for(MPoint *p : gv->points)
          m.xyz[4 * p->getVertex(0)->getIndex() + 3] =
            gv->prescribedMeshSizeAtVertex() / sizeFactor;
      }
    }
    surfaceSizes(s, m, sizeFactor);
    missing = pdel3d::triangleToTetMap(m, s.triNode, tri2tet);
    pdel3d::linesInTriangles(s.triNode, s.lineNode, lineInTriangle);
    missingLines =
      pdel3d::lineToTetMap(m, s.lineNode, lineInTriangle, line2tet);
    if(missing || missingLines) {
      Msg::Error(
        "%lu triangle(s) and %lu line(s) still missing after boundary recovery",
        missing, missingLines);
      return 1;
    }
  }
  pdel3d::constrainFacets(m, tri2tet);
  pdel3d::constrainEdges(m, line2tet);
  if(!pdel3d::colorVolumes(m, tri2tet, s.triColor, s.volumes, s.siblings))
    return 1;
  if(Msg::GetVerbosity() > 5) m.verify(!recovered);
  const double t2 = TimeOfDay();
  Msg::Info("Done recovering the boundary (Wall %gs)", t2 - t1);

  // refinement
  const std::size_t numFixed = m.numVertices();
  {
    pdel3d::RefineOptions opt;
    opt.numThreads = nthreads;
    opt.numVolumes = (std::uint32_t)regions.size();
    opt.sizeMin = CTX::instance()->mesh.lcMin;
    opt.sizeMax = CTX::instance()->mesh.lcMax;
    opt.sizeFactor = sizeFactor;
    SizeData sd = {&regions, false};
    opt.sizeCallback = sizeCallback;
    opt.sizeData = &sd;
    opt.verbosity = verbosity;
    pdel3d::refine(m, opt);
    if(sd.failed) {
      Msg::Error("Mesh size evaluation failed");
      return 1;
    }
  }
  double t3 = TimeOfDay();
  Msg::Info("Done refining (Wall %gs)", t3 - t2);
  if(Msg::GetVerbosity() > 5) m.verify(false);
  if(CTX::instance()->mesh.optimize > 0 &&
     CTX::instance()->mesh.optimizeThreshold > 0.) {
    Msg::Info("Optimizing mesh...");
    pdel3d::OptimizeOptions opt;
    opt.numThreads = nthreads;
    opt.numVolumes = (std::uint32_t)regions.size();
    opt.numFixedVertices = numFixed;
    opt.qualityMin = CTX::instance()->mesh.optimizeThreshold;
    opt.verbosity = verbosity;
    pdel3d::optimize(m, opt);
    if(Msg::GetVerbosity() > 5) m.verify(false);
    Msg::Info("Done optimizing mesh (Wall %gs)", TimeOfDay() - t3);
    t3 = TimeOfDay();
  }

  const std::size_t numTets = exportMesh(m, s, regions, nthreads);
  Msg::Info("Done exporting %lu tets (Wall %gs)", numTets, TimeOfDay() - t3);
  return 0;
}
