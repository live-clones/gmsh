// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "Generator.h"
#include "GModel.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>
#include "SPoint3.h"
#include "SVector3.h"
#include "MFace.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "meshGRegion.h"
#include "meshCombine3D.h"

static void buildUniqueFaces(GRegion *gr,
                             std::map<MFace, GRegion *, MFaceLessThan> &bnd)
{
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    for(int j = 0; j < e->getNumFaces(); j++) {
      MFace f = e->getFace(j);
      auto it = bnd.find(f);
      if(it == bnd.end())
        bnd[f] = gr;
      else
        bnd.erase(it);
    }
  }
}

#if defined(HAVE_HXT)

#include "hxt_combine_cpp_api.h"

// Two tets standing on the two triangles of an unmatched hex or prism quad
// face, split along the same diagonal and sharing the vertex opposite to it,
// form a pyramid on that face: replace them with one pyramid. The four
// lateral triangles are preserved, and the base matches the quad face
// without a trihedron.
static std::size_t makeFreePyramids(GRegion *gr)
{
  std::map<MFace, std::vector<MTetrahedron *>, MFaceLessThan> tri2tet;
  for(MTetrahedron *t : gr->tetrahedra)
    for(int f = 0; f < 4; f++) tri2tet[t->getFace(f)].push_back(t);
  // a quad face on 2 tets has its 4 vertices on tets: the others are not
  // counted
  std::unordered_set<MVertex *> onTets;
  onTets.reserve(gr->tetrahedra.size());
  for(MTetrahedron *t : gr->tetrahedra)
    for(int k = 0; k < 4; k++) onTets.insert(t->getVertex(k));
  std::map<MFace, int, MFaceLessThan> quads;
  auto addQuads = [&](MElement *e, int nbFaces,
                      int (*face)(const int, const int)) {
    for(int f = 0; f < nbFaces; f++) {
      if(face(f, 3) < 0) continue; // a triangle
      bool candidate = true;
      for(int j = 0; j < 4 && candidate; j++)
        candidate = onTets.count(e->getVertex(face(f, j)));
      if(candidate) quads[e->getFace(f)]++;
    }
  };
  for(MHexahedron *h : gr->hexahedra) addQuads(h, 6, MHexahedron::faces_hexa);
  for(MPrism *p : gr->prisms) addQuads(p, 5, MPrism::faces_prism);

  auto apexOf = [](MTetrahedron *t, MVertex *x, MVertex *y, MVertex *z) {
    for(int k = 0; k < 4; k++) {
      MVertex *w = t->getVertex(k);
      if(w != x && w != y && w != z) return w;
    }
    return (MVertex *)nullptr;
  };
  std::set<MTetrahedron *> used;
  std::size_t n = 0;
  for(auto &kv : quads) {
    if(kv.second != 1) continue; // shared by two cells
    const MFace &q = kv.first;
    MVertex *v[4] = {q.getVertex(0), q.getVertex(1), q.getVertex(2),
                     q.getVertex(3)};
    for(int d = 0; d < 2; d++) {
      MVertex *a = v[d], *b = v[d + 1], *c = v[(d + 2) % 4],
              *e = v[(d + 3) % 4];
      auto i1 = tri2tet.find(MFace(a, b, c));
      auto i2 = tri2tet.find(MFace(c, e, a));
      if(i1 == tri2tet.end() || i2 == tri2tet.end()) continue;
      if(i1->second.size() != 1 || i2->second.size() != 1) continue;
      MTetrahedron *t1 = i1->second[0], *t2 = i2->second[0];
      if(t1 == t2 || used.count(t1) || used.count(t2)) continue;
      MVertex *apex = apexOf(t1, a, b, c);
      if(!apex || apex != apexOf(t2, c, e, a)) continue;
      // a warped face can leave one corner of the pyramid nearly flat:
      // keep a margin, later smoothing only protects the worst element of
      // each cavity
      const double minQuality = 0.1;
      MPyramid *p = new MPyramid(v[0], v[1], v[2], v[3], apex);
      if(!(p->minSICNShapeMeasure() >= minQuality)) {
        delete p;
        p = new MPyramid(v[0], v[3], v[2], v[1], apex);
        if(!(p->minSICNShapeMeasure() >= minQuality)) {
          delete p;
          continue;
        }
      }
      used.insert(t1);
      used.insert(t2);
      gr->pyramids.push_back(p);
      n++;
      break;
    }
  }
  if(n) {
    std::vector<MTetrahedron *> kept;
    kept.reserve(gr->tetrahedra.size());
    for(MTetrahedron *t : gr->tetrahedra) {
      if(used.count(t))
        delete t;
      else
        kept.push_back(t);
    }
    gr->tetrahedra.swap(kept);
  }
  return n;
}

// The volume of a first-order hex, exact as the Jacobian determinant of the
// trilinear map has degree 2 along each direction: 2x2x2 Gauss points, in
// closed form (MElement::getVolume takes 27 generic Jacobian evaluations)
static double hexVolume(const MHexahedron *h)
{
  static const double s[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1},
                                 {-1, 1, -1},  {-1, -1, 1}, {1, -1, 1},
                                 {1, 1, 1},    {-1, 1, 1}};
  const double g = 1. / std::sqrt(3.);
  double vol = 0.;
  for(int q = 0; q < 8; q++) {
    const double p[3] = {s[q][0] * g, s[q][1] * g, s[q][2] * g};
    double J[3][3] = {{0., 0., 0.}, {0., 0., 0.}, {0., 0., 0.}};
    for(int i = 0; i < 8; i++) {
      const MVertex *v = h->getVertex(i);
      const double x[3] = {v->x(), v->y(), v->z()};
      const double a = 1. + s[i][0] * p[0], b = 1. + s[i][1] * p[1],
                   c = 1. + s[i][2] * p[2];
      const double d[3] = {s[i][0] * b * c / 8., s[i][1] * a * c / 8.,
                           s[i][2] * a * b / 8.};
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) J[k][l] += x[k] * d[l];
    }
    vol += J[0][0] * (J[1][1] * J[2][2] - J[1][2] * J[2][1]) -
           J[0][1] * (J[1][0] * J[2][2] - J[1][2] * J[2][0]) +
           J[0][2] * (J[1][0] * J[2][1] - J[1][1] * J[2][0]);
  }
  return vol;
}

// The vertices numbered in the order in which the tets first reach them, the
// number kept in MVertex::_index (-1 for the vertices of the region that no
// tet reaches, if any, and 0 in the triangles for the ones of the boundary)
static void createMeshStore(GRegion *gr, HXTCombine::MeshStore &ms,
                            std::vector<MVertex *> &c2v)
{
  const std::vector<MTetrahedron *> &tets = gr->tetrahedra;
  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces)
    for(auto t : gf->triangles)
      for(std::size_t i = 0; i < 3; i++) t->getVertex(i)->setIndex(-1);
  for(auto v : gr->mesh_vertices) v->setIndex(-1);
  for(auto t : tets)
    for(std::size_t i = 0; i < 4; i++) t->getVertex(i)->setIndex(-1);
  c2v.clear();
  for(auto t : tets) {
    for(std::size_t i = 0; i < 4; i++) {
      MVertex *v = t->getVertex(i);
      if(v->getIndex() < 0) {
        v->setIndex(c2v.size());
        c2v.push_back(v);
      }
    }
  }

  const int64_t nv = c2v.size(), nt = tets.size();
  ms.vertices.resize(4 * nv);
  ms.tetCorners.resize(4 * nt);
#pragma omp parallel
  {
#pragma omp for schedule(static)
    for(int64_t i = 0; i < nv; i++) {
      ms.vertices[4 * i] = c2v[i]->x();
      ms.vertices[4 * i + 1] = c2v[i]->y();
      ms.vertices[4 * i + 2] = c2v[i]->z();
      ms.vertices[4 * i + 3] = 0.;
    }
#pragma omp for schedule(static)
    for(int64_t t = 0; t < nt; t++)
      for(std::size_t i = 0; i < 4; i++)
        ms.tetCorners[4 * t + i] = tets[t]->getVertex(i)->getIndex();
  }

  for(auto gf : faces) {
    for(auto t : gf->triangles) {
      ms.triangleColors.push_back(gf->tag());
      for(std::size_t i = 0; i < 3; i++)
        ms.triangleCorners.push_back(
          std::max(t->getVertex(i)->getIndex(), 0L));
    }
  }
  computeTetAdjacencies(ms);
}

int meshCombine3D(GRegion *gr, const CombineFrames *frames)
{
  if(gr->tetrahedra.empty()) {
    Msg::Error("Region %d has no tetrahedra to combine (Delaunay meshing "
               "likely failed for this region)",
               gr->tag());
    return -1;
  }

  const double tStart = TimeOfDay(), cStart = Cpu();
  Msg::Debug("Creating Mesh Wrapper for region %d", gr->tag());
  double volHex = 0, volTet = 0;
  int numHex = 0, numTet = 0;

  std::vector<MVertex *> c2v;
  HXTCombine::MeshStore ms;
  createMeshStore(gr, ms, c2v);
  // ----------------- I D E N T I F Y   H E X E S
  // -------------------------------------
  Msg::Debug("Identifying Hexes for region %d", gr->tag());
  HXTCombine::TetMeshForCombining tm4c(&ms);
  HXTCombine::HXTCombineCellStore ccs(tm4c);
  double minQuality = CTX::instance()->mesh.recombine3DMinimumQuality;

  // Mesh.Recombine3DLevel (0: hex, 1: hex+prisms, 2: hex+prism+pyramids)
  // controls whether prisms are also computed and let selectCellsGreedy
  // consider them alongside hexes. Different vertex-sharing arithmetic
  // (a hex+prism sharing a quad face: 8+6-4=10 boundary vertices) may
  // fit shapes a pure-hex assembly structurally cannot reach.
  if(CTX::instance()->mesh.recombine3DLevel >= 2)
    Msg::Warning("Mesh.Recombine3DLevel=2 (pyramids) is not implemented "
                 "yet; falling back to hex+prisms");
  bool enablePrisms = CTX::instance()->mesh.recombine3DLevel >= 1;

  std::vector<double> axes, sizes;
  std::size_t nbFramed = 0;
  if(frames && CTX::instance()->mesh.recombine3DCandidates == 1) {
    axes.assign(9 * c2v.size(), 0.);
    sizes.assign(c2v.size(), 0.);
    for(std::size_t i = 0; i < c2v.size(); i++) {
      auto it = frames->find(c2v[i]);
      if(it == frames->end()) continue;
      std::copy(it->second.axes, it->second.axes + 9, &axes[9 * i]);
      sizes[i] = it->second.size;
      nbFramed++;
    }
  }

  AddMeshStageTime("combination: setup", TimeOfDay() - tStart, Cpu() - cStart);
  const double tSelect = TimeOfDay(), cSelect = Cpu();
  if(nbFramed) {
    HXTCombine::FrameSelectionStatistics stats;
    ccs.selectAlongFrames(minQuality, axes, sizes, enablePrisms, &stats);
    // the CPU time with the clock of the others, shared as std::clock shares
    // it (it counts the system time as well)
    const double cpu = Cpu() - cSelect;
    const double share =
      stats.cpuCandidates + stats.cpuSelection > 0. ?
        stats.cpuCandidates / (stats.cpuCandidates + stats.cpuSelection) :
        0.5;
    AddMeshStageTime("combination: candidates", stats.wallCandidates,
                     share * cpu);
    AddMeshStageTime("combination: selection", stats.wallSelection,
                     (1. - share) * cpu);
    Msg::Debug("%zu Hexes proposed along the frames of %zu vertices, %zu "
               "selected", stats.nbProposedHexes, nbFramed,
               stats.nbSelectedProposedHexes);
    Msg::Debug("%zu Hexes proposed around the %zu vertices left in tets",
               stats.nbResidualHexes, stats.nbFreeVertices);
    if(enablePrisms)
      Msg::Debug("%zu Prisms proposed on the %zu tets left",
                 stats.nbProposedPrisms, stats.nbFreeTets);
  }
  else {
    ccs.computeHexes(minQuality);
    Msg::Debug("%d Hexes found", ccs.hexes().size());
    if(enablePrisms) {
      ccs.computePrisms(minQuality);
      Msg::Debug("%d Prisms found", ccs.prisms().size());
    }

    // ----------------- S E L E C T I N G   H E X E S
    // -------------------------------------
    std::array<bool, 4> cellTypes{true, enablePrisms, false, true};
    ccs.selectCellsGreedy(cellTypes);
    AddMeshStageTime("combination: candidates and selection",
                     TimeOfDay() - tSelect, Cpu() - cSelect);
  }
  const double tOutput = TimeOfDay(), cOutput = Cpu();
  Msg::Debug("%d Hexes selected", ccs.nbSelectedHexes());
  if(enablePrisms)
    Msg::Debug("%d Prisms selected", ccs.nbSelectedPrisms());
  //	ccs.saveMSH("hexdom.msh",cellTypes);


  // ----------------- C R E A T I N G  V O L U M E    E L E M E N T S
  // --------------------
  for(auto t : gr->tetrahedra) delete t;
  gr->tetrahedra.clear();

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);

  std::set<MFace, MFaceLessThan> faceToDelete;

  // only a cell face with its 4 vertices on the surface meshes can be made of
  // 2 boundary triangles: the others are not searched
  std::vector<char> onBoundary(c2v.size());
  for(std::size_t i = 0; i < c2v.size(); i++) {
    GEntity *ge = c2v[i]->onWhat();
    onBoundary[i] = ge && ge->dim() < 3;
  }
  auto faceOnBoundary = [&](const HXTCombine::HXTCombineCell &c,
                            int (*face)(const int, const int), int l) {
    for(int j = 0; j < 4; j++)
      if(!onBoundary[c.vertexes[face(l, j)]]) return false;
    return true;
  };

  // the vertices of the elements, by their number (MVertex::_index)
  std::vector<char> used(c2v.size(), 0);

  for(size_t k = 0; k < ccs.hexes().size(); k++) {
    if(ccs.selectedHexes()[k]) {
      MVertex *v0 = c2v[ccs.hexes()[k].vertexes[0]];
      MVertex *v1 = c2v[ccs.hexes()[k].vertexes[1]];
      MVertex *v2 = c2v[ccs.hexes()[k].vertexes[2]];
      MVertex *v3 = c2v[ccs.hexes()[k].vertexes[3]];
      MVertex *v4 = c2v[ccs.hexes()[k].vertexes[4]];
      MVertex *v5 = c2v[ccs.hexes()[k].vertexes[5]];
      MVertex *v6 = c2v[ccs.hexes()[k].vertexes[6]];
      MVertex *v7 = c2v[ccs.hexes()[k].vertexes[7]];
      used[v0->getIndex()] = 1;
      used[v1->getIndex()] = 1;
      used[v2->getIndex()] = 1;
      used[v3->getIndex()] = 1;
      used[v4->getIndex()] = 1;
      used[v5->getIndex()] = 1;
      used[v6->getIndex()] = 1;
      used[v7->getIndex()] = 1;
      MHexahedron *h = new MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7);
      volHex += hexVolume(h);
      numHex++;
      gr->hexahedra.push_back(h);
      for(int l = 0; l < 6; l++) {
        if(!faceOnBoundary(ccs.hexes()[k], MHexahedron::faces_hexa, l))
          continue;
        MFace f = h->getFace(l);
        MFace f012(f.getVertex(0), f.getVertex(1), f.getVertex(2));
        MFace f230(f.getVertex(2), f.getVertex(3), f.getVertex(0));
        GFace *gfound012 = findInFaceSearchStructure(f012, search);
        GFace *gfound230 = findInFaceSearchStructure(f230, search);
        if(gfound012 && gfound230 && gfound012 == gfound230) {
          gfound012->quadrangles.push_back(new MQuadrangle(
            f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
          faceToDelete.insert(f012);
          faceToDelete.insert(f230);
        }
        else {
          MFace f013(f.getVertex(0), f.getVertex(1), f.getVertex(3));
          MFace f312(f.getVertex(3), f.getVertex(1), f.getVertex(2));
          GFace *gfound013 = findInFaceSearchStructure(f013, search);
          GFace *gfound312 = findInFaceSearchStructure(f312, search);
          if(gfound013 && gfound312 && gfound013 == gfound312) {
            gfound013->quadrangles.push_back(new MQuadrangle(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
            faceToDelete.insert(f013);
            faceToDelete.insert(f312);
          }
        }
      }
    }
  }
  if(enablePrisms) {
    for(size_t k = 0; k < ccs.prisms().size(); k++) {
      if(!ccs.selectedPrisms()[k]) continue;
      MVertex *v0 = c2v[ccs.prisms()[k].vertexes[0]];
      MVertex *v1 = c2v[ccs.prisms()[k].vertexes[1]];
      MVertex *v2 = c2v[ccs.prisms()[k].vertexes[2]];
      MVertex *v3 = c2v[ccs.prisms()[k].vertexes[3]];
      MVertex *v4 = c2v[ccs.prisms()[k].vertexes[4]];
      MVertex *v5 = c2v[ccs.prisms()[k].vertexes[5]];
      used[v0->getIndex()] = 1;
      used[v1->getIndex()] = 1;
      used[v2->getIndex()] = 1;
      used[v3->getIndex()] = 1;
      used[v4->getIndex()] = 1;
      used[v5->getIndex()] = 1;
      MPrism *p = new MPrism(v0, v1, v2, v3, v4, v5);
      gr->prisms.push_back(p);
      // Faces 0 and 1 are the 2 triangular caps: they coincide with
      // existing surface triangles already in place, nothing to
      // reconcile. Faces 2-4 are the 3 quad facets: same
      // diagonal-pair-of-triangles-to-quadrangle reconciliation as for
      // hexahedra above.
      for(int l = 2; l < 5; l++) {
        if(!faceOnBoundary(ccs.prisms()[k], MPrism::faces_prism, l)) continue;
        MFace f = p->getFace(l);
        MFace f012(f.getVertex(0), f.getVertex(1), f.getVertex(2));
        MFace f230(f.getVertex(2), f.getVertex(3), f.getVertex(0));
        GFace *gfound012 = findInFaceSearchStructure(f012, search);
        GFace *gfound230 = findInFaceSearchStructure(f230, search);
        if(gfound012 && gfound230 && gfound012 == gfound230) {
          gfound012->quadrangles.push_back(new MQuadrangle(
            f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
          faceToDelete.insert(f012);
          faceToDelete.insert(f230);
        }
        else {
          MFace f013(f.getVertex(0), f.getVertex(1), f.getVertex(3));
          MFace f312(f.getVertex(3), f.getVertex(1), f.getVertex(2));
          GFace *gfound013 = findInFaceSearchStructure(f013, search);
          GFace *gfound312 = findInFaceSearchStructure(f312, search);
          if(gfound013 && gfound312 && gfound013 == gfound312) {
            gfound013->quadrangles.push_back(new MQuadrangle(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
            faceToDelete.insert(f013);
            faceToDelete.insert(f312);
          }
        }
      }
    }
  }

  for(unsigned int k = 0; k < ms.tetCorners.size() / 4; k++) {
    if(ccs.selectedTets()[k]) {
      MVertex *v0 = c2v[ms.tetCorners[4 * k]];
      MVertex *v1 = c2v[ms.tetCorners[4 * k + 1]];
      MVertex *v2 = c2v[ms.tetCorners[4 * k + 2]];
      MVertex *v3 = c2v[ms.tetCorners[4 * k + 3]];
      used[v0->getIndex()] = 1;
      used[v1->getIndex()] = 1;
      used[v2->getIndex()] = 1;
      used[v3->getIndex()] = 1;
      MTetrahedron *tet = new MTetrahedron(v0, v1, v2, v3);
      gr->tetrahedra.push_back(tet);
      volTet += tet->getVolume();
      numTet++;
    }
  }

  {
    std::vector<MVertex *> vr;
    for(auto v : gr->mesh_vertices) {
      if(v->getIndex() >= 0 && used[v->getIndex()])
        vr.push_back(v);
      else {
        delete v;
      }
    }
    Msg::Debug("%d vertices removed by the combination",
               (int)(gr->mesh_vertices.size() - vr.size()));
    gr->mesh_vertices = vr;
  }
  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces) {
    std::vector<MTriangle *> temp;
    for(auto t : gf->triangles) {
      if(faceToDelete.find(t->getFace(0)) == faceToDelete.end()) {
        temp.push_back(t);
      }
      else
        delete t;
    }
    gf->triangles = temp;
  }

  Msg::Debug("Volume Hex %12.5E --- Volume Tet %12.5E --- Percentage Vol Hex "
             "%12.5E", volHex, volTet, 100 * volHex / (volHex + volTet));
  Msg::Debug("Number Hex %12d --- Number Tet %12d --- Percentage Num Hex "
             "%12.5E", numHex, numTet,
             100 * (double)numHex / (numHex + numTet));

  AddMeshStageTime("combination: output", TimeOfDay() - tOutput,
                   Cpu() - cOutput);
  if(CTX::instance()->mesh.recombine3DConformity == 2) {
    const double tPyramids = TimeOfDay(), cPyramids = Cpu();
    const std::size_t nPyr = makeFreePyramids(gr);
    AddMeshStageTime("combination: pyramids", TimeOfDay() - tPyramids,
                     Cpu() - cPyramids);
    Msg::Debug("%zu pyramids on hex/prism quad faces (%zu tets merged), "
               "%zu tets left",
               nPyr, 2 * nPyr, gr->tetrahedra.size());
  }

  double volPrism = 0.;
  for(MPrism *p : gr->prisms) volPrism += std::abs(p->getVolume());
  Msg::Info("Region %d: %d hexahedra (%.1f%% of the volume), %zu prisms, %zu "
            "pyramids, %zu tetrahedra (Wall %gs)",
            gr->tag(), numHex, 100. * volHex / (volHex + volPrism + volTet),
            gr->prisms.size(), gr->pyramids.size(), gr->tetrahedra.size(),
            TimeOfDay() - tStart);

  return 0;
}
#else

int meshCombine3D(GRegion *gr, const CombineFrames *frames)
{
  Msg::Warning(
    "Gmsh must be compiled with HXT to enable hybrid mesh generation");
  return -1;
}

#endif

// the original version, on all the faces of the volume elements (and their
// polyhedra)
static bool makeConformalThroughTrihedraAllFaces(GModel *gm)
{
  fs_cont search;
  // on boundary.
  buildFaceSearchStructure(gm, search);
  std::map<MFace, GRegion *, MFaceLessThan> bnd;
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    // look at every face that only comes once
    buildUniqueFaces(gr, bnd);
  }
  // bnd2 contains non conforming faces
  std::map<MFace, GRegion *, MFaceLessThan> bnd2;
  for(auto itf = bnd.begin(); itf != bnd.end(); ++itf) {
    GFace *gfound = findInFaceSearchStructure(itf->first, search);
    if(!gfound) { bnd2[itf->first] = itf->second; }
  }
  bnd.clear();


  // create trihedron

  for(auto itf = bnd2.begin(); itf != bnd2.end(); ++itf) {
    const MFace &f = itf->first;
    if(f.getNumVertices() == 4) { // quad face
      auto it1 =
        bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(2)));
      auto it2 =
        bnd2.find(MFace(f.getVertex(2), f.getVertex(3), f.getVertex(0)));
      if(it1 != bnd2.end() && it2 != bnd2.end()) {
        MTrihedron *th = new MTrihedron(f.getVertex(3), f.getVertex(0),
                                        f.getVertex(1), f.getVertex(2));
        itf->second->trihedra.push_back(th);
      }
      else {
        it1 = bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(3)));
        it2 = bnd2.find(MFace(f.getVertex(3), f.getVertex(1), f.getVertex(2)));
        if(it1 != bnd2.end() && it2 != bnd2.end()) {
          MTrihedron *th = new MTrihedron(f.getVertex(0), f.getVertex(1),
                                          f.getVertex(2), f.getVertex(3));
          itf->second->trihedra.push_back(th);
          }
        else {
          Msg::Warning(
            "MakeMeshConformal: wrong mesh topology, quad verts %zu %zu "
            "%zu %zu",
            f.getVertex(0)->getNum(), f.getVertex(1)->getNum(),
            f.getVertex(2)->getNum(), f.getVertex(3)->getNum());
          //          return false;
        }
      }
    }
  }
  return true;
}

namespace {
  // a face by its vertices sorted by address (3 or 4, the 4th null for a
  // triangle)
  struct SortedFace {
    MVertex *v[4];
    bool operator==(const SortedFace &o) const
    {
      return v[0] == o.v[0] && v[1] == o.v[1] && v[2] == o.v[2] &&
             v[3] == o.v[3];
    }
  };
  struct SortedFaceHash {
    std::size_t operator()(const SortedFace &f) const
    {
      std::size_t h = 0;
      for(int i = 0; i < 4; i++)
        h = h * 0x9E3779B97F4A7C15ull + (std::size_t)f.v[i] / sizeof(void *);
      return h ^ (h >> 29);
    }
  };
  SortedFace sortedFace(MVertex *a, MVertex *b, MVertex *c,
                        MVertex *d = nullptr)
  {
    SortedFace f = {{a, b, c, d}};
    std::sort(f.v, f.v + (d ? 4 : 3));
    return f;
  }
} // namespace

// The quadrangular faces of the hexahedra, prisms and pyramids with two
// triangular faces on their other side get a trihedron, as the original
// version, without looking at all the faces of all the elements: such a face
// has its 4 vertices on elements with triangular faces, and only the faces
// meeting that condition (all the occurrences of a face do), and the
// triangles of the unmatched ones, are counted
bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm)
{
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit)
    if(!(*rit)->polyhedra.empty()) return makeConformalThroughTrihedraAllFaces(gm);

  // the vertices of the elements with triangular faces, marked 1 in
  // MVertex::_index (the other vertices of the quadrangular faces 0)
  bool anyTriangle = false;
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    auto mark = [](MElement *e, long m) {
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++)
        e->getVertex(k)->setIndex(m);
    };
    for(MHexahedron *e : gr->hexahedra) mark(e, 0);
    for(MTetrahedron *e : gr->tetrahedra) mark(e, 0);
    for(MPyramid *e : gr->pyramids) mark(e, 0);
    for(MPrism *e : gr->prisms) mark(e, 0);
    for(MTrihedron *e : gr->trihedra) mark(e, 0);
  }
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    auto mark = [&anyTriangle](MElement *e) {
      anyTriangle = true;
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++)
        e->getVertex(k)->setIndex(1);
    };
    for(MTetrahedron *e : gr->tetrahedra) mark(e);
    for(MPyramid *e : gr->pyramids) mark(e);
    for(MPrism *e : gr->prisms) mark(e);
    for(MTrihedron *e : gr->trihedra) mark(e);
  }
  if(!anyTriangle) return true;

  // the occurrences of the quadrangular faces with their 4 vertices there,
  // with the vertices in the order of their element, sorted by face (and
  // order of occurrence)
  struct QuadOccurrence {
    SortedFace key;
    MVertex *v[4];
    GRegion *gr;
    std::size_t rank;
  };
  std::vector<QuadOccurrence> quads;
  auto addQuads = [&](MElement *e, int nbFaces,
                      int (*face)(const int, const int), GRegion *gr) {
    for(int f = 0; f < nbFaces; f++) {
      if(face(f, 3) < 0) continue; // a triangle
      QuadOccurrence q;
      bool candidate = true;
      for(int j = 0; j < 4 && candidate; j++) {
        q.v[j] = e->getVertex(face(f, j));
        candidate = q.v[j]->getIndex() == 1;
      }
      if(!candidate) continue;
      q.key = sortedFace(q.v[0], q.v[1], q.v[2], q.v[3]);
      q.gr = gr;
      q.rank = quads.size();
      quads.push_back(q);
    }
  };
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    for(MHexahedron *e : gr->hexahedra)
      addQuads(e, 6, MHexahedron::faces_hexa, gr);
    for(MPrism *e : gr->prisms) addQuads(e, 5, MPrism::faces_prism, gr);
    for(MPyramid *e : gr->pyramids) addQuads(e, 5, MPyramid::faces_pyramid, gr);
    for(MTrihedron *e : gr->trihedra)
      addQuads(e, 3, MTrihedron::faces_trihedron, gr);
  }
  std::sort(quads.begin(), quads.end(),
            [](const QuadOccurrence &x, const QuadOccurrence &y) {
              for(int i = 0; i < 4; i++)
                if(x.key.v[i] != y.key.v[i]) return x.key.v[i] < y.key.v[i];
              return x.rank < y.rank;
            });

  // the faces of the surface meshes bounding the regions (as
  // buildFaceSearchStructure)
  std::unordered_set<SortedFace, SortedFaceHash> boundary;
  {
    std::set<GFace *> faces;
    for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
      std::vector<GFace *> f = (*rit)->faces();
      faces.insert(f.begin(), f.end());
    }
    for(GFace *gf : faces) {
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        const std::size_t n = e->getNumPrimaryVertices();
        if(n == 3)
          boundary.insert(
            sortedFace(e->getVertex(0), e->getVertex(1), e->getVertex(2)));
        else if(n == 4)
          boundary.insert(sortedFace(e->getVertex(0), e->getVertex(1),
                                     e->getVertex(2), e->getVertex(3)));
      }
    }
  }

  // the unmatched ones (an odd number of occurrences, the last one kept, as
  // the original version), not on the boundary, in the order of the original
  // version (MFaceLessThan: by sorted vertex numbers), and the triangles of
  // their two splits
  struct Hanging {
    std::size_t num[4];
    const QuadOccurrence *q;
  };
  std::vector<Hanging> hanging;
  std::unordered_map<SortedFace, int, SortedFaceHash> triangles;
  for(std::size_t i = 0; i < quads.size();) {
    std::size_t j = i + 1;
    while(j < quads.size() && quads[j].key == quads[i].key) j++;
    const QuadOccurrence &q = quads[j - 1];
    if((j - i) % 2 && !boundary.count(q.key)) {
      Hanging h;
      for(int k = 0; k < 4; k++) h.num[k] = q.v[k]->getNum();
      std::sort(h.num, h.num + 4);
      h.q = &q;
      hanging.push_back(h);
      MVertex *const *v = q.v;
      triangles[sortedFace(v[0], v[1], v[2])];
      triangles[sortedFace(v[2], v[3], v[0])];
      triangles[sortedFace(v[0], v[1], v[3])];
      triangles[sortedFace(v[3], v[1], v[2])];
    }
    i = j;
  }
  std::sort(hanging.begin(), hanging.end(),
            [](const Hanging &x, const Hanging &y) {
              return std::lexicographical_compare(x.num, x.num + 4, y.num,
                                                  y.num + 4);
            });

  // their occurrences as faces of the elements
  auto addTriangles = [&](MElement *e, int nbFaces,
                          int (*face)(const int, const int)) {
    for(int f = 0; f < nbFaces; f++) {
      if(face(f, 3) >= 0) continue; // a quadrangle
      auto it = triangles.find(sortedFace(e->getVertex(face(f, 0)),
                                          e->getVertex(face(f, 1)),
                                          e->getVertex(face(f, 2))));
      if(it != triangles.end()) it->second++;
    }
  };
  auto tetFace = [](const int f, const int j) {
    return j < 3 ? MTetrahedron::faces_tetra(f, j) : -1;
  };
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    for(MTetrahedron *e : gr->tetrahedra) addTriangles(e, 4, tetFace);
    for(MPyramid *e : gr->pyramids) addTriangles(e, 5, MPyramid::faces_pyramid);
    for(MPrism *e : gr->prisms) addTriangles(e, 5, MPrism::faces_prism);
    for(MTrihedron *e : gr->trihedra)
      addTriangles(e, 3, MTrihedron::faces_trihedron);
  }
  // unmatched and not on the boundary
  auto hangingTriangle = [&](MVertex *a, MVertex *b, MVertex *c) {
    const SortedFace f = sortedFace(a, b, c);
    auto it = triangles.find(f);
    return it != triangles.end() && it->second % 2 && !boundary.count(f);
  };

  int nbTrihedraCreated = 0;
  for(auto &h : hanging) {
    MVertex *const *v = h.q->v;
    if(hangingTriangle(v[0], v[1], v[2]) && hangingTriangle(v[2], v[3], v[0])) {
      h.q->gr->trihedra.push_back(new MTrihedron(v[3], v[0], v[1], v[2]));
      nbTrihedraCreated++;
    }
    else if(hangingTriangle(v[0], v[1], v[3]) &&
            hangingTriangle(v[3], v[1], v[2])) {
      h.q->gr->trihedra.push_back(new MTrihedron(v[0], v[1], v[2], v[3]));
      nbTrihedraCreated++;
    }
    else
      Msg::Warning("MakeMeshConformal: wrong mesh topology, quad verts %zu %zu "
                   "%zu %zu",
                   v[0]->getNum(), v[1]->getNum(), v[2]->getNum(),
                   v[3]->getNum());
  }
  Msg::Debug("%d hanging quadrangular faces, %d trihedra created",
             (int)hanging.size(), nbTrihedraCreated);
  return true;
}
