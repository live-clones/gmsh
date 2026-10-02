// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODELIO_GLTF_H
#define GMODELIO_GLTF_H

// Export of meshes and post-processing views in glTF 2.0 format (.gltf), with
// all the binary data embedded in the file as a base64 encoded buffer.

#include <string>

class GModel;
class PView;

namespace gltf {
  // write the mesh: one glTF mesh per surface, volume (all the faces of its
  // elements) and curve; high-order elements are saved as first order
  // elements
  bool writeMesh(GModel *m, const std::string &fileName, bool saveAll,
                 double scalingFactor);
  // write the view as displayed (time step, range, colors): one glTF mesh with
  // colored points, lines and triangles; only scalar data is exported
  bool writeView(PView *v, const std::string &fileName);
} // namespace gltf

#endif
