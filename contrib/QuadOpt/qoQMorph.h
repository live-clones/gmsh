// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"
#include "qoOptions.h"

class GFace;
class GModel;

namespace QuadOpt {

  // Q-Morph post-processing of an existing first-order triangle surface mesh.
  // The triangulation can come from any mesher. Quadrangle fronts advance layer
  // by layer, with nine angular front priorities (qoQMorph.cpp); the optimizer
  // (qoOptimizer.cpp) then pairs the remaining triangles and optimizes the mesh,
  // sharing the face import/export and geometry (qoFace.h) with it.
  // CAD boundary and embedded-curve meshes are preserved. Interior vertices
  // and connectivity may change; the result can contain residual triangles.
  // Returns true on completion, false on failure with this face unchanged.
  // Apply before meshing adjacent volumes or generating high-order elements.
  // Partitioned meshes and master/slave periodic meshes are not supported.
  GMSH_API bool qMorph(GFace *face, const Options &options = Options());

  // Apply qMorph to the faces of a model, skipping empty faces and faces that
  // already contain only quadrangles. Returns false if any face fails; faces
  // processed successfully remain modified. Refresh the model's mesh caches
  // and display arrays after processing.
  GMSH_API bool qMorph(GModel *model, const Options &options = Options());

} // namespace QuadOpt
