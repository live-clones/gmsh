// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "qoPack.h"
#include "qoOptimizer.h"
#include "qoQMorph.h"
#include "GFace.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "meshQuadQuasiStructured.h"

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

} // namespace QuadOpt
