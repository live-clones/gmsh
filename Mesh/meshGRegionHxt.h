// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_HXT_H
#define MESH_GREGION_HXT_H

#include <vector>
#include <map>

#if defined(HAVE_HXT)
extern "C" {
#include "hxt_mesh.h"
}
#endif

class GRegion;
class GModel;
class MVertex;

HXTStatus hxtGmshMsgCallback(HXTMessage *msg);

int meshGRegionHxt(std::vector<GRegion *> &regions);
HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions,
		   HXTMesh *m,
		   std::map<MVertex *, int> &v2c,
		   std::vector<MVertex *> &c2v);

HXTStatus Gmsh2Hxt(GModel *gm,
		   HXTMesh *m,
		   std::map<MVertex *, int> &v2c,
		   std::vector<MVertex *> &c2v);

HXTStatus Hxt2Gmsh(std::vector<GRegion *> &regions, HXTMesh *m,
		   std::map<MVertex *, int> &v2c,
		   std::vector<MVertex *> &c2v);
  

HXTStatus Hxt2Gmsh(GModel *gm, HXTMesh *m,
		   std::map<MVertex *, int> &v2c,
		   std::vector<MVertex *> &c2v);

#endif
