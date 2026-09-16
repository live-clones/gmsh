// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "GModel.h"
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include "SPoint3.h"
#include "SVector3.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "meshGRegion.h"

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

static void createMeshStore(GRegion *gr, HXTCombine::MeshStore &ms,
                            std::map<MVertex *, uint32_t> &v2c,
                            std::vector<MVertex *> &c2v)
{
  for(auto t : gr->tetrahedra) {
    for(size_t i = 0; i < 4; i++) {
      MVertex *v = t->getVertex(i);
      if(v2c.find(v) == v2c.end()) {
        v2c[v] = c2v.size();
        c2v.push_back(v);
      }
    }
  }

  for(auto v : c2v) {
    ms.vertices.push_back(v->x());
    ms.vertices.push_back(v->y());
    ms.vertices.push_back(v->z());
    ms.vertices.push_back(0.0);
  }

  for(auto t : gr->tetrahedra) {
    for(size_t i = 0; i < 4; i++) {
      MVertex *v = t->getVertex(i);
      ms.tetCorners.push_back(v2c[v]);
    }
  }

  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces) {
    for(auto t : gf->triangles) {
      ms.triangleColors.push_back(gf->tag());
      for(size_t i = 0; i < 3; i++) {
        MVertex *v = t->getVertex(i);
        ms.triangleCorners.push_back(v2c[v]);
      }
    }
  }
  computeTetAdjacencies(ms);
}

int meshCombine3D(GRegion *gr)
{
  if(gr->tetrahedra.empty()) {
    Msg::Error("Region %d has no tetrahedra to combine (Delaunay meshing "
               "likely failed for this region)",
               gr->tag());
    return -1;
  }

  Msg::Info("Creating Mesh Wrapper for region %d", gr->tag());
  double volHex = 0, volTet = 0;
  int numHex = 0, numTet = 0;
  int debugTrackHexIdx = -1; // EXPERIMENTAL: see GMSH_INSPECT_PRISM_XYZ below

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  HXTCombine::MeshStore ms;
  createMeshStore(gr, ms, v2c, c2v);
  // ----------------- I D E N T I F Y   H E X E S
  // -------------------------------------
  Msg::Info("Identifying Hexes for region %d", gr->tag());
  HXTCombine::TetMeshForCombining tm4c(&ms);
  HXTCombine::HXTCombineCellStore ccs(tm4c);
  double minQuality = 0.0001;
  ccs.computeHexes(minQuality);
  Msg::Info("%d Hexes found", ccs.hexes().size());

  // Mesh.Recombine3DLevel (0: hex, 1: hex+prisms, 2: hex+prism+pyramids)
  // controls whether prisms are also computed and let selectCellsGreedy
  // consider them alongside hexes. Different vertex-sharing arithmetic
  // (a hex+prism sharing a quad face: 8+6-4=10 boundary vertices) may
  // fit shapes a pure-hex assembly structurally cannot reach.
  bool enablePrisms = CTX::instance()->mesh.recombine3DLevel >= 1;
  if(enablePrisms) {
    ccs.computePrisms(minQuality);
    Msg::Info("%d Prisms found", ccs.prisms().size());
  }

  // ----------------- S E L E C T I N G   H E X E S
  // -------------------------------------
  std::array<bool, 4> cellTypes{true, enablePrisms, false, true};
  ccs.selectCellsGreedy(cellTypes);
  Msg::Info("%d Hexes selected", ccs.nbSelectedHexes());
  if(enablePrisms)
    Msg::Info("%d Prisms selected", ccs.nbSelectedPrisms());
  //	ccs.saveMSH("hexdom.msh",cellTypes);

  if(getenv("GMSH_SELECTION_QUALITY_STATS")) {
    std::vector<double> hexQ(ccs.hexes().size());
    computeCellQualityVector(tm4c, ccs.hexes(), hexQ.data());
    double worstSelected = 1e300;
    int worstIdx = -1;
    for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
      if(!ccs.selectedHexes()[k]) continue;
      if(hexQ[k] < worstSelected) { worstSelected = hexQ[k]; worstIdx = (int)k; }
    }
    Msg::Info("- selection-time quality stats: worst SELECTED hex quality = "
              "%.6f (candidate idx %d)",
              worstSelected, worstIdx);
    if(worstIdx != -1) {
      std::ostringstream dbg;
      for(int i = 0; i < 8; i++)
        dbg << c2v[ccs.hexes()[(std::size_t)worstIdx].vertexes[i]]->getNum()
            << " ";
      Msg::Info("  - its node tags: %s", dbg.str().c_str());
    }
  }
  if(const char *tagsStr = getenv("GMSH_CHECK_HEX_TAGS")) {
    std::set<int> wanted;
    {
      std::istringstream iss(tagsStr);
      std::string tok;
      while(std::getline(iss, tok, ',')) wanted.insert(std::atoi(tok.c_str()));
    }
    std::vector<double> hexQ(ccs.hexes().size());
    computeCellQualityVector(tm4c, ccs.hexes(), hexQ.data());
    for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
      std::set<int> have;
      for(int i = 0; i < 8; i++)
        have.insert(c2v[ccs.hexes()[k].vertexes[i]]->getNum());
      if(have == wanted) {
        Msg::Info("- GMSH_CHECK_HEX_TAGS: found matching candidate idx %zu, "
                  "selection-time quality = %.6f, selected=%s",
                  k, hexQ[k], ccs.selectedHexes()[k] ? "yes" : "no");
      }
    }
  }

  if(getenv("GMSH_COMBINE_CHECK_CONFLICTS")) {
    std::vector<int> tetOwnerCheck(tm4c.nbTets(), -1);
    int nbConflicts = 0;
    for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
      if(!ccs.selectedHexes()[k]) continue;
      const HXTCombine::HXTCombineCell &h = ccs.hexes()[k];
      for(unsigned int i = 0; i < h.nbInteriorTets(); i++) {
        unsigned int t = h.interiorTets()[i];
        if(tetOwnerCheck[t] != -1) nbConflicts++;
        tetOwnerCheck[t] = (int)k;
      }
    }
    Msg::Info("- conflict check: %d interior-tet double-claims among %d "
              "selected hexes",
              nbConflicts, ccs.nbSelectedHexes());
  }

  // EXPERIMENTAL: find a leftover tet that NO candidate hex (selected or
  // not) ever touched at all -- a genuine candidate-GENERATION gap, not
  // a rejection -- and dump enough local detail to inspect why
  // computeAllHex's vertex-based search (Pellerin/Johnen/Remacle,
  // IMR26 2017) never even proposed anything there.
  if(getenv("GMSH_FIND_GENERATION_GAP")) {
    using namespace HXTCombine;
    const std::vector<bool> &leftover = ccs.selectedTets();
    unsigned int nbTets = tm4c.nbTets();
    std::vector<bool> touchedByAnyCandidate(nbTets, false);
    for(const HXTCombineCell &h : ccs.hexes())
      for(unsigned int i = 0; i < h.nbInteriorTets() + h.nbBoundaryTets();
          i++)
        touchedByAnyCandidate[h.tet(i)] = true;

    // Shape-quality histogram over ALL untouched leftover tets (not
    // just the first), to see whether generation gaps are systematically
    // slivers or include well-shaped tets too.
    {
      auto shapeQuality = [&](unsigned int t) {
        SPoint3 p[4];
        for(int lv = 0; lv < 4; lv++) p[lv] = c2v[tm4c.vertex(t, lv)]->point();
        SVector3 e01(p[1] - p[0]), e02(p[2] - p[0]), e03(p[3] - p[0]);
        double vol = fabs(dot(crossprod(e01, e02), e03)) / 6.0;
        double maxEdge = 0;
        for(int a = 0; a < 4; a++)
          for(int b = a + 1; b < 4; b++)
            maxEdge = std::max(maxEdge, p[a].distance(p[b]));
        double regVol = maxEdge * maxEdge * maxEdge / (6.0 * sqrt(2.0));
        return vol / regVol;
      };
      int nbUntouched = 0;
      int bucket[5] = {0, 0, 0, 0, 0}; // <0.02, <0.05, <0.1, <0.2, >=0.2
      double sumQ = 0, minQ = 1e30, maxQ = -1e30;
      for(unsigned int t = 0; t < nbTets; t++) {
        if(!leftover[t] || touchedByAnyCandidate[t]) continue;
        double q = shapeQuality(t);
        nbUntouched++;
        sumQ += q;
        minQ = std::min(minQ, q);
        maxQ = std::max(maxQ, q);
        if(q < 0.02) bucket[0]++;
        else if(q < 0.05) bucket[1]++;
        else if(q < 0.1) bucket[2]++;
        else if(q < 0.2) bucket[3]++;
        else bucket[4]++;
      }
      if(nbUntouched > 0)
        Msg::Info(
          "- generation gap shape histogram: %d untouched tets, quality "
          "(vol/regular-vol) min=%.4g max=%.4g avg=%.4g -- buckets "
          "<0.02:%d <0.05:%d <0.1:%d <0.2:%d >=0.2:%d",
          nbUntouched, minQ, maxQ, sumQ / nbUntouched, bucket[0], bucket[1],
          bucket[2], bucket[3], bucket[4]);
    }

    unsigned int gapTet = (unsigned int)-1;
    for(unsigned int t = 0; t < nbTets; t++) {
      if(leftover[t] && !touchedByAnyCandidate[t]) { gapTet = t; break; }
    }
    if(gapTet == (unsigned int)-1) {
      Msg::Info("- generation gap: no untouched leftover tet found");
    }
    else {
      std::ostringstream verts;
      for(int lv = 0; lv < 4; lv++)
        verts << c2v[tm4c.vertex(gapTet, lv)]->getNum() << " ";
      Msg::Info("- generation gap: tet %u, nodes [ %s], look it up in "
                "the GUI (Tools>Statistics or click a node)",
                gapTet, verts.str().c_str());

      // Is it a sliver? Compute its volume, longest edge, and a simple
      // normalized-volume quality (1.0 = regular tet, ~0 = degenerate).
      {
        SPoint3 p[4];
        for(int lv = 0; lv < 4; lv++)
          p[lv] = c2v[tm4c.vertex(gapTet, lv)]->point();
        SVector3 e01(p[1] - p[0]), e02(p[2] - p[0]), e03(p[3] - p[0]);
        double vol = fabs(dot(crossprod(e01, e02), e03)) / 6.0;
        double maxEdge = 0;
        SPoint3 *pp = p;
        for(int a = 0; a < 4; a++)
          for(int b = a + 1; b < 4; b++)
            maxEdge = std::max(maxEdge, pp[a].distance(pp[b]));
        // normalized shape quality: ratio of the tet's volume to that
        // of a regular tet with the same longest edge (1 = regular,
        // near 0 = sliver/degenerate)
        double regVol = maxEdge * maxEdge * maxEdge / (6.0 * sqrt(2.0));
        Msg::Info("  - shape: volume=%.6g, longest edge=%.6g, "
                  "volume/regular-volume=%.6g (1=regular tet, ~0=sliver)",
                  vol, maxEdge, vol / regVol);
      }
      // For each of the 4 vertices, count how many tets touch it and
      // how many candidates (of any quality) touch it -- to see if this
      // is a locally sparse/isolated area.
      for(int lv = 0; lv < 4; lv++) {
        VertexIndex v = tm4c.vertex(gapTet, lv);
        int nbTouchingTets = 0;
        for(unsigned int t = 0; t < nbTets; t++)
          for(int lv2 = 0; lv2 < 4; lv2++)
            if(tm4c.vertex(t, lv2) == v) { nbTouchingTets++; break; }
        int nbTouchingCandidates = 0;
        for(const HXTCombineCell &h : ccs.hexes())
          for(unsigned int i = 0; i < h.nbVertices(); i++)
            if(h.vertex(i) == v) { nbTouchingCandidates++; break; }
        Msg::Info("  - node %zu (internal %u): %d tets touch it, %d "
                  "candidate hexes touch it (any quality)",
                  c2v[v]->getNum(), v, nbTouchingTets, nbTouchingCandidates);
      }
    }
  }

  // EXPERIMENTAL: like GMSH_INSPECT_NODE used to, but locates the
  // nearest vertex to a given (x,y,z) instead of a node tag -- robust
  // to the mesh not being perfectly reproducible run to run, since a
  // barycenter/coordinate read off a previous run's GUI still points
  // at roughly the same place in a fresh run.
  if(const char *xyzStr = getenv("GMSH_INSPECT_XYZ")) {
    using namespace HXTCombine;
    double x, y, z;
    if(sscanf(xyzStr, "%lf,%lf,%lf", &x, &y, &z) != 3) {
      Msg::Info("- inspect xyz: could not parse '%s' (expected x,y,z)",
                xyzStr);
    }
    else {
      SPoint3 target(x, y, z);
      VertexIndex best = (VertexIndex)-1;
      double bestD = 1e300;
      for(std::size_t i = 0; i < c2v.size(); i++) {
        double d = c2v[i]->point().distance(target);
        if(d < bestD) { bestD = d; best = (VertexIndex)i; }
      }
      Msg::Info("- inspect xyz (%.4g,%.4g,%.4g): nearest vertex is node "
                "%zu (internal %u), distance %.4g",
                x, y, z, c2v[best]->getNum(), best, bestD);

      const std::vector<bool> &leftover = ccs.selectedTets();
      unsigned int nbTets = tm4c.nbTets();
      std::vector<int> interiorTetOwner(nbTets, -1);
      for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
        if(!ccs.selectedHexes()[k]) continue;
        const HXTCombineCell &h = ccs.hexes()[k];
        for(unsigned int i = 0; i < h.nbInteriorTets(); i++)
          interiorTetOwner[h.interiorTets()[i]] = (int)k;
      }
      std::vector<double> qualities(ccs.hexes().size());
      computeCellQualityVector(tm4c, ccs.hexes(), qualities.data());

      int nbTouchingTets = 0, nbLeftoverTets = 0;
      for(unsigned int t = 0; t < nbTets; t++) {
        bool touches = false;
        for(int lv = 0; lv < 4; lv++)
          if(tm4c.vertex(t, lv) == best) { touches = true; break; }
        if(!touches) continue;
        nbTouchingTets++;
        if(leftover[t]) {
          nbLeftoverTets++;
          SPoint3 p[4];
          for(int lv = 0; lv < 4; lv++)
            p[lv] = c2v[tm4c.vertex(t, lv)]->point();
          SVector3 e01(p[1] - p[0]), e02(p[2] - p[0]), e03(p[3] - p[0]);
          double vol = fabs(dot(crossprod(e01, e02), e03)) / 6.0;
          double maxEdge = 0;
          for(int a = 0; a < 4; a++)
            for(int b = a + 1; b < 4; b++)
              maxEdge = std::max(maxEdge, p[a].distance(p[b]));
          double regVol = maxEdge * maxEdge * maxEdge / (6.0 * sqrt(2.0));
          std::ostringstream verts;
          for(int lv = 0; lv < 4; lv++)
            verts << c2v[tm4c.vertex(t, lv)]->getNum() << " ";
          Msg::Info("  - leftover tet %u, nodes [ %s], shape=%.4g "
                    "(1=regular, ~0=sliver)",
                    t, verts.str().c_str(), vol / regVol);
        }
      }

      int nbCandidatesTouching = 0, nbSelectedTouching = 0;
      double bestRejectedQuality = -1.0;
      int bestRejectedIdx = -1;
      int nbRejectedTetConflict = 0, nbRejectedNoConflict = 0;
      for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
        const HXTCombineCell &h = ccs.hexes()[k];
        bool touches = false;
        for(unsigned int i = 0; i < h.nbVertices(); i++)
          if(h.vertex(i) == best) { touches = true; break; }
        if(!touches) continue;
        nbCandidatesTouching++;
        if(ccs.selectedHexes()[k]) { nbSelectedTouching++; continue; }
        bool tetConflict = false;
        for(unsigned int i = 0; i < h.nbInteriorTets(); i++)
          if(interiorTetOwner[h.interiorTets()[i]] != -1) {
            tetConflict = true;
            break;
          }
        if(tetConflict) nbRejectedTetConflict++;
        else {
          nbRejectedNoConflict++;
          if(qualities[k] > bestRejectedQuality) {
            bestRejectedQuality = qualities[k];
            bestRejectedIdx = (int)k;
          }
        }
      }
      Msg::Info(
        "  - %d tets touch this vertex (%d leftover), %d candidate hexes "
        "touch it (%d selected, %d rejected/tet-conflict, %d "
        "rejected/no-conflict, best rejected-no-conflict quality %.4f)",
        nbTouchingTets, nbLeftoverTets, nbCandidatesTouching,
        nbSelectedTouching, nbRejectedTetConflict, nbRejectedNoConflict,
        bestRejectedQuality);

      // Try to actually unlock this best candidate: find every currently
      // selected hex it shares a vertex with, build an isolated sub-mesh
      // containing the union of their tets (plus the candidate's own),
      // and re-run the REAL, committed combine pipeline
      // (computeHexes+selectCellsGreedy, unmodified) on it fresh -- this
      // uses the true compatibility checker, not a proxy.
      if(bestRejectedIdx != -1) {
        const HXTCombineCell &target = ccs.hexes()[(std::size_t)bestRejectedIdx];
        std::map<VertexIndex, int> selectedHexAtVertex; // -1 means "seen, multiple"
        std::vector<int> blockerHexes;
        std::set<int> blockerSet;
        for(unsigned int i = 0; i < target.nbVertices(); i++) {
          VertexIndex v = target.vertex(i);
          for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
            if(!ccs.selectedHexes()[k]) continue;
            const HXTCombineCell &h = ccs.hexes()[k];
            bool has = false;
            for(unsigned int j = 0; j < h.nbVertices(); j++)
              if(h.vertex(j) == v) { has = true; break; }
            if(has && blockerSet.insert((int)k).second)
              blockerHexes.push_back((int)k);
          }
        }

        std::set<unsigned int> region;
        for(unsigned int i = 0; i < target.nbInteriorTets() + target.nbBoundaryTets();
            i++)
          region.insert(target.tet(i));
        for(int bk : blockerHexes) {
          const HXTCombineCell &h = ccs.hexes()[(std::size_t)bk];
          for(unsigned int i = 0; i < h.nbInteriorTets() + h.nbBoundaryTets();
              i++)
            region.insert(h.tet(i));
        }

        std::map<VertexIndex, VertexIndex> remap;
        MeshStore subMs;
        for(unsigned int t : region) {
          for(int lv = 0; lv < 4; lv++) {
            VertexIndex v = tm4c.vertex(t, lv);
            if(remap.find(v) == remap.end()) {
              VertexIndex newId = (VertexIndex)remap.size();
              remap[v] = newId;
              vec3 p = tm4c.point(v);
              subMs.vertices.push_back(p.x);
              subMs.vertices.push_back(p.y);
              subMs.vertices.push_back(p.z);
              subMs.vertices.push_back(0.0);
            }
          }
        }
        for(unsigned int t : region)
          for(int lv = 0; lv < 4; lv++)
            subMs.tetCorners.push_back(remap[tm4c.vertex(t, lv)]);
        computeTetAdjacencies(subMs);

        TetMeshForCombining subTm(&subMs);
        HXTCombineCellStore subCcs(subTm);
        subCcs.computeHexes(minQuality);
        std::array<bool, 4> subCellTypes{true, false, false, true};
        subCcs.selectCellsGreedy(subCellTypes);
        std::vector<double> subQualities(subCcs.hexes().size());
        computeCellQualityVector(subTm, subCcs.hexes(), subQualities.data());
        double totalQuality = 0.0;
        for(std::size_t k = 0; k < subCcs.hexes().size(); k++)
          if(subCcs.selectedHexes()[k]) totalQuality += subQualities[k];

        Msg::Info(
          "  - unlock attempt: best candidate q=%.4f blocked by %d "
          "already-selected neighbor(s); isolated region = %d tets, %d "
          "vertices -> fresh combine finds %d selected (total quality "
          "%.2f) vs %d before (baseline neighbors alone)",
          bestRejectedQuality, (int)blockerHexes.size(), (int)region.size(),
          (int)remap.size(), (int)subCcs.nbSelectedHexes(), totalQuality,
          (int)blockerHexes.size());
      }
    }
  }

  // EXPERIMENTAL: locate the SELECTED PRISM whose barycenter is nearest
  // a given (x,y,z), find its quad-face-sharing selected-prism partner,
  // check for a matching hex candidate over their combined 8 vertices,
  // and -- unlike the earlier swap attempt, which required an EXACT tet
  // footprint match -- check whether the hex candidate's tets are a
  // SUBSET of the two prisms' combined tets (any leftover tet, e.g. a
  // genuine sliver, would simply remain an ordinary uncombined tet
  // afterwards, which is always safe). Then re-validate with the real,
  // committed combine pipeline on an isolated sub-mesh.
  if(enablePrisms && getenv("GMSH_INSPECT_PRISM_XYZ")) {
    using namespace HXTCombine;
    double x, y, z;
    if(sscanf(getenv("GMSH_INSPECT_PRISM_XYZ"), "%lf,%lf,%lf", &x, &y, &z) !=
       3) {
      Msg::Info("- inspect prism xyz: could not parse (expected x,y,z)");
    }
    else {
      SPoint3 target(x, y, z);
      int bestPrism = -1;
      double bestD = 1e300;
      for(std::size_t k = 0; k < ccs.prisms().size(); k++) {
        if(!ccs.selectedPrisms()[k]) continue;
        const HXTCombineCell &P = ccs.prisms()[k];
        SPoint3 bary(0, 0, 0);
        for(unsigned int i = 0; i < P.nbVertices(); i++) {
          vec3 p = tm4c.point(P.vertex(i));
          bary += SPoint3(p.x, p.y, p.z);
        }
        bary *= 1.0 / P.nbVertices();
        double d = bary.distance(target);
        if(d < bestD) { bestD = d; bestPrism = (int)k; }
      }
      if(bestPrism == -1) {
        Msg::Info("- inspect prism xyz: no selected prism found");
      }
      else {
        auto quadKey = [](const HXTCombineCell &p, unsigned int f) {
          std::array<VertexIndex, 4> k = {
            p.vertex(Prism::facetVertex[f][0]),
            p.vertex(Prism::facetVertex[f][1]),
            p.vertex(Prism::facetVertex[f][2]),
            p.vertex(Prism::facetVertex[f][3])};
          std::sort(k.begin(), k.end());
          return k;
        };
        const HXTCombineCell &PA = ccs.prisms()[(std::size_t)bestPrism];
        int prismB = -1;
        for(unsigned int fA = 2; fA <= 4 && prismB == -1; fA++) {
          auto keyA = quadKey(PA, fA);
          for(std::size_t k = 0; k < ccs.prisms().size(); k++) {
            if(!ccs.selectedPrisms()[k] || (int)k == bestPrism) continue;
            const HXTCombineCell &PB = ccs.prisms()[k];
            for(unsigned int fB = 2; fB <= 4; fB++)
              if(quadKey(PB, fB) == keyA) { prismB = (int)k; break; }
            if(prismB != -1) break;
          }
        }
        Msg::Info("- inspect prism xyz: nearest selected prism is index "
                  "%d (distance %.4g), quad-sharing partner = %d",
                  bestPrism, bestD, prismB);
        if(prismB != -1) {
          const HXTCombineCell &PB = ccs.prisms()[(std::size_t)prismB];
          std::set<VertexIndex> combinedV;
          for(unsigned int i = 0; i < PA.nbVertices(); i++)
            combinedV.insert(PA.vertex(i));
          for(unsigned int i = 0; i < PB.nbVertices(); i++)
            combinedV.insert(PB.vertex(i));
          std::set<unsigned int> prismTets;
          for(unsigned int i = 0; i < PA.nbInteriorTets() + PA.nbBoundaryTets();
              i++)
            prismTets.insert(PA.tet(i));
          for(unsigned int i = 0; i < PB.nbInteriorTets() + PB.nbBoundaryTets();
              i++)
            prismTets.insert(PB.tet(i));
          Msg::Info("  - combined vertex set size = %d, combined tet count "
                    "= %d",
                    (int)combinedV.size(), (int)prismTets.size());
          if(combinedV.size() == 8) {
            std::array<VertexIndex, 8> v;
            std::copy(combinedV.begin(), combinedV.end(), v.begin());
            int hexIdx = -1;
            for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
              std::array<VertexIndex, 8> hv;
              for(int i = 0; i < 8; i++) hv[i] = ccs.hexes()[k].vertex(i);
              std::sort(hv.begin(), hv.end());
              if(hv == v) { hexIdx = (int)k; break; }
            }
            if(hexIdx == -1) {
              Msg::Info("  - no hex candidate exists over these 8 vertices "
                        "at all");
            }
            else {
              debugTrackHexIdx = hexIdx;
              std::vector<double> hexQ(ccs.hexes().size());
              computeCellQualityVector(tm4c, ccs.hexes(), hexQ.data());
              const HXTCombineCell &H = ccs.hexes()[(std::size_t)hexIdx];
              if(const char *posPath = getenv("GMSH_DUMP_TRACKED_HEX")) {
                std::ofstream pos(posPath);
                static const int hf[6][4] = {{0, 1, 2, 3}, {4, 5, 6, 7},
                                              {0, 1, 5, 4}, {1, 2, 6, 5},
                                              {3, 2, 6, 7}, {0, 3, 7, 4}};
                pos << "View \"candidate hex " << hexIdx << "\" {\n";
                for(int f = 0; f < 6; f++) {
                  pos << "SQ(";
                  for(int i = 0; i < 4; i++) {
                    vec3 p = tm4c.point(H.vertex(hf[f][i]));
                    pos << p.x << "," << p.y << "," << p.z;
                    if(i < 3) pos << ",";
                  }
                  pos << "){0,0,0,0};\n";
                }
                pos << "};\n";
                static const int pf[5][4] = {{0, 1, 2, -1},
                                              {3, 4, 5, -1},
                                              {0, 1, 4, 3},
                                              {1, 2, 5, 4},
                                              {2, 0, 3, 5}};
                auto dumpPrism = [&](const char *name,
                                      const HXTCombineCell &P) {
                  pos << "View \"" << name << "\" {\n";
                  for(int f = 0; f < 5; f++) {
                    int nv = pf[f][3] == -1 ? 3 : 4;
                    pos << (nv == 3 ? "ST(" : "SQ(");
                    for(int i = 0; i < nv; i++) {
                      vec3 p = tm4c.point(P.vertex(pf[f][i]));
                      pos << p.x << "," << p.y << "," << p.z;
                      if(i < nv - 1) pos << ",";
                    }
                    pos << ")";
                    pos << (nv == 3 ? "{0,0,0};\n" : "{0,0,0,0};\n");
                  }
                  pos << "};\n";
                };
                dumpPrism("prism A", PA);
                dumpPrism("prism B", PB);
                Msg::Info("- dumped candidate hex + 2 prisms to %s", posPath);
              }
              std::set<unsigned int> hexTets;
              for(unsigned int i = 0;
                  i < H.nbInteriorTets() + H.nbBoundaryTets(); i++)
                hexTets.insert(H.tet(i));
              bool isSubset = true;
              for(unsigned int t : hexTets)
                if(!prismTets.count(t)) { isSubset = false; break; }
              int nbExtraTets = 0;
              for(unsigned int t : prismTets)
                if(!hexTets.count(t)) nbExtraTets++;
              int nbMissingTets = 0;
              for(unsigned int t : hexTets)
                if(!prismTets.count(t)) nbMissingTets++;
              Msg::Info(
                "  - matching hex candidate found: quality=%.4f, selected "
                "elsewhere=%s, its tets are a SUBSET of the 2 prisms' "
                "tets: %s (%d extra prism tet(s) not needed by the hex, %d "
                "extra tet(s) the hex needs beyond the 2 prisms, e.g. a "
                "sliver)",
                hexQ[hexIdx], ccs.selectedHexes()[hexIdx] ? "yes" : "no",
                isSubset ? "yes" : "no", nbExtraTets, nbMissingTets);

              if(!ccs.selectedHexes()[hexIdx]) {
                // Real validation: isolate this hex's own tets plus
                // every currently-selected HEX that shares a vertex with
                // it (the only cells that could make it incompatible),
                // and re-run the actual, committed combine pipeline on
                // that sub-mesh fresh.
                std::set<int> blockerHexes;
                for(unsigned int i = 0; i < H.nbVertices(); i++) {
                  VertexIndex vv = H.vertex(i);
                  for(std::size_t k = 0; k < ccs.hexes().size(); k++) {
                    if(!ccs.selectedHexes()[k]) continue;
                    const HXTCombineCell &hh = ccs.hexes()[k];
                    for(unsigned int j = 0; j < hh.nbVertices(); j++)
                      if(hh.vertex(j) == vv) { blockerHexes.insert((int)k); break; }
                  }
                }
                // For each neighbor, precisely how many vertices does it
                // share with our candidate, and does that shared set form
                // a genuine face of BOTH (the only pattern the user's
                // simple rule -- share nothing, or a full face -- allows)?
                for(int bk : blockerHexes) {
                  const HXTCombineCell &hh = ccs.hexes()[(std::size_t)bk];
                  std::vector<VertexIndex> shared;
                  for(unsigned int i = 0; i < H.nbVertices(); i++)
                    for(unsigned int j = 0; j < hh.nbVertices(); j++)
                      if(H.vertex(i) == hh.vertex(j)) { shared.push_back(H.vertex(i)); break; }
                  bool isFullFace = false;
                  if(shared.size() == 4) {
                    std::array<VertexIndex, 4> ss;
                    std::copy(shared.begin(), shared.end(), ss.begin());
                    std::sort(ss.begin(), ss.end());
                    for(unsigned int f = 0; f < 6 && !isFullFace; f++) {
                      std::array<VertexIndex, 4> fh = {
                        H.vertex(Hex::facetVertex[f][0]), H.vertex(Hex::facetVertex[f][1]),
                        H.vertex(Hex::facetVertex[f][2]), H.vertex(Hex::facetVertex[f][3])};
                      std::sort(fh.begin(), fh.end());
                      if(fh != ss) continue;
                      for(unsigned int g = 0; g < 6 && !isFullFace; g++) {
                        std::array<VertexIndex, 4> fg = {
                          hh.vertex(Hex::facetVertex[g][0]), hh.vertex(Hex::facetVertex[g][1]),
                          hh.vertex(Hex::facetVertex[g][2]), hh.vertex(Hex::facetVertex[g][3])};
                        std::sort(fg.begin(), fg.end());
                        if(fg == ss) isFullFace = true;
                      }
                    }
                  }
                  std::ostringstream sharedNodes, hhNodes;
                  for(VertexIndex sv : shared)
                    sharedNodes << c2v[sv]->getNum() << " ";
                  for(unsigned int i = 0; i < hh.nbVertices(); i++)
                    hhNodes << c2v[hh.vertex(i)]->getNum() << " ";
                  Msg::Info(
                    "    - blocker candidate index %d (isHex=%s, "
                    "nbVertices=%u, its 8 node tags: %s) shares %d "
                    "vertice(s) [node tags: %s] with our candidate "
                    "(full-face match on both sides: %s), selected=%s",
                    bk, hh.isHex() ? "yes" : "no", hh.nbVertices(),
                    hhNodes.str().c_str(), (int)shared.size(),
                    sharedNodes.str().c_str(), isFullFace ? "yes" : "no",
                    ccs.selectedHexes()[(std::size_t)bk] ? "yes" : "no");
                  if(shared.size() == 3) {
                    debugTrackHexIdx = bk;
                    if(const char *posPath = getenv("GMSH_DUMP_TRACKED_HEX")) {
                      std::ofstream pos(posPath, std::ios::app);
                      pos << "View \"conflicting blocker hex " << bk
                          << " (3-vertex conflict)\" {\n";
                      static const int hf[6][4] = {
                        {0, 1, 2, 3}, {4, 5, 6, 7}, {0, 1, 5, 4},
                        {1, 2, 6, 5}, {3, 2, 6, 7}, {0, 3, 7, 4}};
                      for(int f = 0; f < 6; f++) {
                        pos << "SQ(";
                        for(int i = 0; i < 4; i++) {
                          vec3 p = tm4c.point(hh.vertex(hf[f][i]));
                          pos << p.x << "," << p.y << "," << p.z;
                          if(i < 3) pos << ",";
                        }
                        pos << "){0,0,0,0};\n";
                      }
                      pos << "};\n";
                      pos.close();
                      Msg::Info("- appended conflicting blocker hex %d to %s",
                                bk, posPath);
                    }
                  }
                }
                std::set<unsigned int> region = hexTets;
                for(int bk : blockerHexes) {
                  const HXTCombineCell &hh = ccs.hexes()[(std::size_t)bk];
                  for(unsigned int i = 0;
                      i < hh.nbInteriorTets() + hh.nbBoundaryTets(); i++)
                    region.insert(hh.tet(i));
                }
                std::map<VertexIndex, VertexIndex> remap2;
                MeshStore subMs2;
                for(unsigned int t : region) {
                  for(int lv = 0; lv < 4; lv++) {
                    VertexIndex vv = tm4c.vertex(t, lv);
                    if(remap2.find(vv) == remap2.end()) {
                      VertexIndex newId = (VertexIndex)remap2.size();
                      remap2[vv] = newId;
                      vec3 p = tm4c.point(vv);
                      subMs2.vertices.push_back(p.x);
                      subMs2.vertices.push_back(p.y);
                      subMs2.vertices.push_back(p.z);
                      subMs2.vertices.push_back(0.0);
                    }
                  }
                }
                for(unsigned int t : region)
                  for(int lv = 0; lv < 4; lv++)
                    subMs2.tetCorners.push_back(remap2[tm4c.vertex(t, lv)]);
                computeTetAdjacencies(subMs2);
                TetMeshForCombining subTm2(&subMs2);
                HXTCombineCellStore subCcs2(subTm2);
                subCcs2.computeHexes(minQuality);
                std::array<bool, 4> subCellTypes2{true, false, false, true};
                subCcs2.selectCellsGreedy(subCellTypes2);
                Msg::Info(
                  "  - real compatibility check: %d blocking selected "
                  "hex(es) nearby, isolated region = %d tets -> fresh "
                  "combine selects %d hex(es) there (was %d before, i.e. "
                  "the %d blockers alone)",
                  (int)blockerHexes.size(), (int)region.size(),
                  (int)subCcs2.nbSelectedHexes(), (int)blockerHexes.size(),
                  (int)blockerHexes.size());

                // Per explicit request: do the swap in place, touching
                // NOTHING else -- leave the sliver as an ordinary
                // leftover tet, and let the existing, generic
                // MakeHybridHexTetMeshConformalThroughTriHedron pass
                // (already run unconditionally later in the pipeline)
                // insert a trihedron wherever this creates a hanging
                // face against a neighboring already-selected hex,
                // exactly as it already does for hex/prism-vs-tet
                // interfaces.
                if(getenv("GMSH_DO_PRISM_SWAP")) {
                  ccs.selectedPrisms()[(std::size_t)bestPrism] = false;
                  ccs.selectedPrisms()[(std::size_t)prismB] = false;
                  ccs.selectedHexes()[(std::size_t)hexIdx] = true;
                  Msg::Info("  - swap performed in place: prisms %d/%d -> "
                            "off, hex %d -> on (sliver left as-is)",
                            bestPrism, prismB, hexIdx);
                }
              }
            }
          }
        }
      }
    }
  }

  // Cavity database export, opt-in via GMSH_CAVITY_DB=<path to append to>:
  // extract the leftover-tet cavities (regions selectCellsGreedy could
  // not combine), classify which are topological balls (closed, single-
  // component, genus-0 boundary), and append their combinatorial
  // signature (boundary vertex valences + boundary edge graph) to a
  // shared text database, for cross-geometry shape matching later.
  if(const char *dbPath = getenv("GMSH_CAVITY_DB")) {
    using namespace HXTCombine;
    const std::vector<bool> &leftover = ccs.selectedTets();
    unsigned int nbTets = tm4c.nbTets();
    std::vector<int> comp(nbTets, -1);
    std::ofstream db(dbPath, std::ios::app);

    for(unsigned int seed = 0; seed < nbTets; seed++) {
      if(!leftover[seed] || comp[seed] != -1) continue;
      std::vector<unsigned int> tets;
      std::vector<unsigned int> stack(1, seed);
      comp[seed] = (int)seed + 1; // any non -1 marker unique enough here
      while(!stack.empty()) {
        unsigned int t = stack.back();
        stack.pop_back();
        tets.push_back(t);
        for(unsigned int lf = 0; lf < 4; lf++) {
          if(tm4c.isOnBoundary(t, lf)) continue;
          unsigned int nb = tm4c.adjacentTet(t, lf);
          if(leftover[nb] && comp[nb] == -1) {
            comp[nb] = (int)seed + 1;
            stack.push_back(nb);
          }
        }
      }
      if(tets.size() <= 1) continue; // a lone tet is never combinable

      std::set<std::array<VertexIndex, 3> > bndFaces;
      std::set<VertexIndex> bndVerts;
      std::map<std::pair<VertexIndex, VertexIndex>, int> edgeCount;
      for(unsigned int t : tets) {
        for(unsigned int lf = 0; lf < 4; lf++) {
          bool isCavityBoundary =
            tm4c.isOnBoundary(t, lf) || !leftover[tm4c.adjacentTet(t, lf)];
          if(!isCavityBoundary) continue;
          VertexIndex v0 = tm4c.vertex(t, Tet::facetVertex[lf][0]);
          VertexIndex v1 = tm4c.vertex(t, Tet::facetVertex[lf][1]);
          VertexIndex v2 = tm4c.vertex(t, Tet::facetVertex[lf][2]);
          std::array<VertexIndex, 3> face = {v0, v1, v2};
          std::sort(face.begin(), face.end());
          bndFaces.insert(face);
          bndVerts.insert(v0); bndVerts.insert(v1); bndVerts.insert(v2);
          VertexIndex e[3][2] = {{v0, v1}, {v1, v2}, {v0, v2}};
          for(auto &ed : e) {
            VertexIndex a = ed[0], b = ed[1];
            if(a > b) std::swap(a, b);
            edgeCount[{a, b}]++;
          }
        }
      }
      int V = (int)bndVerts.size();
      int F = (int)bndFaces.size();
      int E = (int)edgeCount.size();
      bool manifold = true;
      for(auto &kv : edgeCount)
        if(kv.second != 2) manifold = false;
      bool isBall = manifold && (V - E + F == 2);
      if(!isBall) continue;

      std::map<VertexIndex, int> localId;
      int nextId = 0;
      for(VertexIndex v : bndVerts) localId[v] = nextId++;

      db << "CAVITY V=" << V << " T=" << tets.size() << "\n";
      db << "VALENCE";
      std::map<VertexIndex, int> valence;
      for(auto &kv : edgeCount) {
        valence[kv.first.first]++;
        valence[kv.first.second]++;
      }
      for(VertexIndex v : bndVerts) db << " " << valence[v];
      db << "\n";
      for(auto &kv : edgeCount)
        db << "EDGE " << localId[kv.first.first] << " "
           << localId[kv.first.second] << "\n";
    }
    db.close();
  }
  if(debugTrackHexIdx != -1)
    Msg::Info("- debug: tracked hex candidate %d selected=%s right before "
              "building output elements",
              debugTrackHexIdx,
              ccs.selectedHexes()[(std::size_t)debugTrackHexIdx] ? "yes" : "no");

  // ----------------- C R E A T I N G  V O L U M E    E L E M E N T S
  // --------------------
  for(auto t : gr->tetrahedra) delete t;
  gr->tetrahedra.clear();

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);

  std::set<MFace, MFaceLessThan> faceToDelete;

  std::unordered_set<MVertex *> all_v;

  double worstHexSicnAtBuild = 1e300, worstHexSelectionQuality = 0;
  std::size_t worstHexBuildIdx = 0;
  bool haveWorstHexAtBuild = false;
  std::vector<double> hexQAtBuild;
  if(getenv("GMSH_CHECK_HEX_SICN_AT_BUILD")) {
    hexQAtBuild.resize(ccs.hexes().size());
    computeCellQualityVector(tm4c, ccs.hexes(), hexQAtBuild.data());
  }

  for(size_t k = 0; k < ccs.hexes().size(); k++) {
    if(ccs.selectedHexes()[k]) {
      if((int)k == debugTrackHexIdx) {
        std::ostringstream dbg;
        for(int i = 0; i < 8; i++)
          dbg << c2v[ccs.hexes()[k].vertexes[i]]->getNum() << " ";
        Msg::Info("- debug: entering output branch for tracked hex %d, "
                  "node tags now: %s",
                  (int)k, dbg.str().c_str());
      }
      MVertex *v0 = c2v[ccs.hexes()[k].vertexes[0]];
      MVertex *v1 = c2v[ccs.hexes()[k].vertexes[1]];
      MVertex *v2 = c2v[ccs.hexes()[k].vertexes[2]];
      MVertex *v3 = c2v[ccs.hexes()[k].vertexes[3]];
      MVertex *v4 = c2v[ccs.hexes()[k].vertexes[4]];
      MVertex *v5 = c2v[ccs.hexes()[k].vertexes[5]];
      MVertex *v6 = c2v[ccs.hexes()[k].vertexes[6]];
      MVertex *v7 = c2v[ccs.hexes()[k].vertexes[7]];
      all_v.insert(v0);
      all_v.insert(v1);
      all_v.insert(v2);
      all_v.insert(v3);
      all_v.insert(v4);
      all_v.insert(v5);
      all_v.insert(v6);
      all_v.insert(v7);
      MHexahedron *h = new MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7);
      volHex += h->getVolume();
      numHex++;
      gr->hexahedra.push_back(h);
      if(!hexQAtBuild.empty()) {
        double sicn = h->minSICNShapeMeasure();
        if(sicn < worstHexSicnAtBuild) {
          worstHexSicnAtBuild = sicn;
          worstHexSelectionQuality = hexQAtBuild[k];
          worstHexBuildIdx = k;
          haveWorstHexAtBuild = true;
        }
      }
      for(int l = 0; l < 6; l++) {
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
  if(haveWorstHexAtBuild) {
    std::ostringstream dbg;
    for(int i = 0; i < 8; i++)
      dbg << c2v[ccs.hexes()[worstHexBuildIdx].vertexes[i]]->getNum() << " ";
    Msg::Info("- debug: worst hex SICN at build time = %.6f (candidate idx "
              "%zu), its selection-time quality = %.6f, node tags: %s",
              worstHexSicnAtBuild, worstHexBuildIdx, worstHexSelectionQuality,
              dbg.str().c_str());
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
      all_v.insert(v0);
      all_v.insert(v1);
      all_v.insert(v2);
      all_v.insert(v3);
      all_v.insert(v4);
      all_v.insert(v5);
      MPrism *p = new MPrism(v0, v1, v2, v3, v4, v5);
      gr->prisms.push_back(p);
      // Faces 0 and 1 are the 2 triangular caps: they coincide with
      // existing surface triangles already in place, nothing to
      // reconcile. Faces 2-4 are the 3 quad facets: same
      // diagonal-pair-of-triangles-to-quadrangle reconciliation as for
      // hexahedra above.
      for(int l = 2; l < 5; l++) {
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
      all_v.insert(v0);
      all_v.insert(v1);
      all_v.insert(v2);
      all_v.insert(v3);
      MTetrahedron *tet = new MTetrahedron(v0, v1, v2, v3);
      gr->tetrahedra.push_back(tet);
      volTet += tet->getVolume();
      numTet++;
    }
  }

  {
    std::vector<MVertex *> vr;
    for(auto v : gr->mesh_vertices) {
      if(all_v.find(v) != all_v.end())
        vr.push_back(v);
      else {
        delete v;
      }
    }
    Msg::Info("%d vertice have been removed durin tet2hex combination",
              gr->mesh_vertices.size() - vr.size());
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

  Msg::Info("Hybrid mesh statistics");
  Msg::Info(
    "Volume Hex %12.5E --- Volume Tet %12.5E --- Percentage Vol Hex %12.5E",
    volHex, volTet, 100 * volHex / (volHex + volTet));
  Msg::Info("Number Hex %12d --- Number Tet %12d --- Percentage Num Hex %12.5E",
            numHex, numTet, 100 * (double)numHex / (numHex + numTet));

  return 0;
}
#else

int meshCombine3D(GRegion *gr)
{
  Msg::Warning(
    "Gmsh must be compiled with HXT to enable hybrid mesh generation");
  return -1;
}

#endif

bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm)
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

  if(getenv("GMSH_TRACE_TRIHEDRA"))
    Msg::Info("- MakeHybridHexTetMeshConformalThroughTriHedron: %d hanging "
              "faces",
              (int)bnd2.size());

  // create trihedron

  int nbTrihedraCreated = 0;
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
        nbTrihedraCreated++;
      }
      else {
        it1 = bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(3)));
        it2 = bnd2.find(MFace(f.getVertex(3), f.getVertex(1), f.getVertex(2)));
        if(it1 != bnd2.end() && it2 != bnd2.end()) {
          MTrihedron *th = new MTrihedron(f.getVertex(0), f.getVertex(1),
                                          f.getVertex(2), f.getVertex(3));
          itf->second->trihedra.push_back(th);
          nbTrihedraCreated++;
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
  if(getenv("GMSH_TRACE_TRIHEDRA"))
    Msg::Info("- MakeHybridHexTetMeshConformalThroughTriHedron: %d "
              "trihedra created",
              nbTrihedraCreated);
  return true;
}
