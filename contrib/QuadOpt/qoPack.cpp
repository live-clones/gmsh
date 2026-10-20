// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "qoPack.h"
#include "qoOptimizer.h"
#include "qoQMorph.h"
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
  void finishPackMesh(GModel *m, const Options &options)
  {
    for(GFace *gf : m->getFaces())
      if(gf->meshStatistics.status == GFace::DONE)
        gf->meshStatistics.status = GFace::PENDING;

    transferSeamGEdgesVerticesToGFace(m);
    if(options.patterns)
      quadMeshingOfSimpleFacesWithPatterns(m, .02);
    if(options.qMorph) {
      // Q-Morph on the triangles; a face already made of quads (patterns) is
      // only optimized. Both include the cavity optimizer.
      for(GFace *gf : m->getFaces()) {
        if(gf->triangles.empty() && gf->quadrangles.empty()) continue;
        if(gf->quadrangles.empty()) qMorph(gf, options);
        else optimizeFace(gf, options);
      }
      m->deleteVertexArrays();
    }
    else if(options.optimize)
      optimizeQuads(m, options);
    else
      Msg::Info("PACK cleanup disabled: preserving generated mesh");

    for(GFace *gf : m->getFaces())
      if(gf->meshStatistics.status == GFace::PENDING)
        gf->meshStatistics.status = GFace::DONE;
  }

  // PACK uses the standard mesh size settings and the options as the user
  // set them: only the recombination is forced, and the loops of discrete
  // faces kept polygons. Restored after generation.
  struct PackMeshScope::State {
    bool packing = false;
    int recombineAll = 0;
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

    explicit State(const Options &options)
    {
      contextMeshOptions &mesh = CTX::instance()->mesh;
      packing = mesh.algo2d == ALGO_2D_PACK_PRLGRMS;
      if(!packing) return;
      // PACK is a quad mesher: recombine its triangulation of the packed
      // points
      recombineAll = mesh.recombineAll;
      mesh.recombineAll = options.qMorph ? 0 : 1;
      // the loops of discrete faces must stay polygons
      preserveDiscreteBoundaryLoops();
    }

    ~State()
    {
      if(!packing) return;
      CTX::instance()->mesh.recombineAll = recombineAll;
      for(const auto &entry : minimumSegmentsByEdge)
        entry.first->meshAttributes.minimumMeshSegments = entry.second;
    }
  };

  PackMeshScope::PackMeshScope(const Options &options)
    : _state(new State(options))
  {
  }
  PackMeshScope::~PackMeshScope() = default;

} // namespace QuadOpt
