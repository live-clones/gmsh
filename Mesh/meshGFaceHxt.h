// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_HXT_H
#define MESH_GFACE_HXT_H

class GModel;
class GFace;


// remeshing -- Christos's work
int meshGFaceHxt(GModel *gm);
int meshGFaceHxt(GFace *gf);

#if defined(HAVE_HXT)
  #include "hxt_mesh.h"
#else
  struct HXTMesh;
#endif
#include <vector>
#include <map>
#include <cstdint>
class MVertex;


int Gmsh2Hxt(GFace *gf, HXTMesh *m,
		   std::map<MVertex *, uint32_t> &v2c,
		   std::vector<MVertex *> &c2v);

#endif
