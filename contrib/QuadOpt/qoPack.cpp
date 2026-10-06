// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "qoPack.h"
#include "qoOptimizer.h"
#include "Context.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "GVertex.h"
#include "GmshMessage.h"
#include "meshQuadQuasiStructured.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

namespace QuadOpt {

  // PACK finalization: seams, patterns for simple faces, then the optimizer.
  void finishPackMesh(GModel *m)
  {
    for(GFace *gf : m->getFaces())
      if(gf->meshStatistics.status == GFace::DONE)
        gf->meshStatistics.status = GFace::PENDING;

    transferSeamGEdgesVerticesToGFace(m);
    if(CTX::instance()->mesh.packPatterns)
      quadMeshingOfSimpleFacesWithPatterns(m, .02);
    if(CTX::instance()->mesh.packCleanupMethod != 2)
      optimizeQuads(m);
    else
      Msg::Info("PACK cleanup disabled: preserving generated mesh");

    for(GFace *gf : m->getFaces())
      if(gf->meshStatistics.status == GFace::PENDING)
        gf->meshStatistics.status = GFace::DONE;
  }

  // PACK uses the standard mesh size settings. For uniform sizes, derive
  // cleanup bounds and preserve boundary loops; variable size fields keep
  // their local sizing. Restore temporary meshing settings after generation.
  struct PackMeshScope::State {
    bool active = false;
    bool packing = false;
    int recombineAll = 0;
    int minCurveNodes = 0;
    int smoothingPasses = 0;
    int forceAllPackedPoints = 0;
    double minimumEdgeLength = 0.;
    double maximumEdgeLength = 0.;
    std::map<GEdge *, int> minimumSegmentsByEdge;

    void preserveDiscreteBoundaryLoops()
    {
      GModel *model = GModel::current();
      if(!model) return;
      const auto requireSegments = [&](GEdge *edge, int minimum) {
        if(edge->meshAttributes.minimumMeshSegments >= minimum) return;
        minimumSegmentsByEdge.emplace(
          edge, edge->meshAttributes.minimumMeshSegments);
        edge->meshAttributes.minimumMeshSegments = minimum;
      };
      for(GFace *face : model->getFaces()) {
        if(face->geomType() != GEntity::DiscreteSurface) continue;
        // Imported discrete faces need not populate GFace::edgeLoops. Recover
        // the one- and two-curve loops from their actual boundary edges and
        // endpoints; embedded curves are deliberately not included. OCCFace
        // already imposes these same topological minima on its wires.
        std::map<std::pair<int, int>, std::set<GEdge *>> edgesByEndpoints;
        for(GEdge *edge : face->edges()) {
          GVertex *first = edge->getBeginVertex();
          GVertex *second = edge->getEndVertex();
          if(!first || !second) continue;
          if(first == second)
            requireSegments(edge, 3);
          else
            edgesByEndpoints[std::minmax(first->tag(), second->tag())].insert(edge);
        }
        for(const auto &entry : edgesByEndpoints)
          if(entry.second.size() == 2)
            for(GEdge *edge : entry.second) requireSegments(edge, 2);
      }
    }

    State()
    {
      contextMeshOptions &mesh = CTX::instance()->mesh;
      const bool uniformSize =
        mesh.lcMin > 0. && mesh.lcMax > 0. && mesh.lcFactor > 0. &&
        std::isfinite(mesh.lcFactor) &&
        std::isfinite(mesh.lcMin) && std::isfinite(mesh.lcMax) &&
        std::abs(mesh.lcMax - mesh.lcMin) <=
          1.e-12 * std::max({1., mesh.lcMin, mesh.lcMax});
      const double h = (.5 * mesh.lcMin + .5 * mesh.lcMax) * mesh.lcFactor;
      packing = mesh.algo2d == ALGO_2D_PACK_PRLGRMS;
      active = packing && uniformSize && h > 0. && std::isfinite(h) &&
               !(mesh.optimizeQuadsMinimumEdgeLength > 0.) &&
               !(mesh.optimizeQuadsMaximumEdgeLength > 0.);
      // PACK is a quad mesher: recombine its triangulation of the packed
      // points whatever the size specification (uniform or a size field)
      if(packing) {
        recombineAll = mesh.recombineAll;
        mesh.recombineAll = 1;
      }
      if(!active) return;

      minCurveNodes = mesh.minCurveNodes;
      smoothingPasses = mesh.nbSmoothing;
      forceAllPackedPoints = mesh.packForceAllPoints;
      minimumEdgeLength = mesh.optimizeQuadsMinimumEdgeLength;
      maximumEdgeLength = mesh.optimizeQuadsMaximumEdgeLength;

      preserveDiscreteBoundaryLoops();
      mesh.minCurveNodes = 1;
      mesh.nbSmoothing =
        std::max(mesh.nbSmoothing, mesh.optimizeQuadsSmartLaplacian ? 3 : 5);
      mesh.packForceAllPoints = 1;
      mesh.optimizeQuadsMinimumEdgeLength = .5 * h;
      mesh.optimizeQuadsMaximumEdgeLength = 2. * h;

      Msg::Info("PACK uniform size: h=%g, admissible edges=[%g,%g], "
                "3D packing forced",
                h, mesh.optimizeQuadsMinimumEdgeLength,
                mesh.optimizeQuadsMaximumEdgeLength);
    }

    ~State()
    {
      contextMeshOptions &mesh = CTX::instance()->mesh;
      if(packing) mesh.recombineAll = recombineAll;
      if(!active) return;
      mesh.minCurveNodes = minCurveNodes;
      mesh.nbSmoothing = smoothingPasses;
      mesh.packForceAllPoints = forceAllPackedPoints;
      mesh.optimizeQuadsMinimumEdgeLength = minimumEdgeLength;
      mesh.optimizeQuadsMaximumEdgeLength = maximumEdgeLength;
      for(const auto &entry : minimumSegmentsByEdge)
        entry.first->meshAttributes.minimumMeshSegments = entry.second;
    }
  };

  PackMeshScope::PackMeshScope() : _state(new State) {}
  PackMeshScope::~PackMeshScope() = default;

} // namespace QuadOpt
