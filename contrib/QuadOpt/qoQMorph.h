// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"

class GFace;
class GModel;

namespace QuadOpt {

  // Q-Morph post-processing of an existing first-order triangle surface mesh.
  // The triangulation can come from any mesher. The implementation belongs in
  // qoQMorph.cpp and uses HalfEdgeMesh from qoHalfEdge.h for all connectivity.
  // CAD boundary and embedded-curve meshes are preserved. Interior vertices
  // and connectivity may change; the result can contain residual triangles.
  // Returns true on completion, false on failure with this face unchanged.
  // Apply before meshing adjacent volumes or generating high-order elements.
  GMSH_API bool qMorph(GFace *face);

  // Apply qMorph to the faces of a model, skipping empty faces and faces that
  // already contain only quadrangles. Returns false if any face fails; faces
  // processed successfully remain modified. Refresh the model's mesh caches
  // and display arrays after processing.
  GMSH_API bool qMorph(GModel *model);

} // namespace QuadOpt
