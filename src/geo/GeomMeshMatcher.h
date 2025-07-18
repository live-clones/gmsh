// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Bastien Gorissen
//

#ifndef GEOM_MESH_MATCHER_H
#define GEOM_MESH_MATCHER_H

#include <vector>
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

class GeomMeshMatcher {
private:
  std::vector<std::pair<GVertex *, GVertex *> > *
  matchVertices(GModel *m1, GModel *m2, bool &ok);
  std::vector<std::pair<GEdge *, GEdge *> > *
  matchEdges(GModel *m1, GModel *m2,
             std::vector<std::pair<GVertex *, GVertex *> > *coresp_v, bool &ok);
  std::vector<std::pair<GFace *, GFace *> > *
  matchFaces(GModel *m1, GModel *m2,
             std::vector<std::pair<GEdge *, GEdge *> > *coresp_e, bool &ok);
  std::vector<std::pair<GRegion *, GRegion *> > *
  matchRegions(GModel *m1, GModel *m2,
               std::vector<std::pair<GFace *, GFace *> > *coresp_f, bool &ok);
  static GeomMeshMatcher *_gmm_instance;
  GeomMeshMatcher() {}
  ~GeomMeshMatcher() {}

public:
  static GeomMeshMatcher *instance();
  static void destroy();
  int match(GModel *geom, GModel *mesh);
  int forceTomatch(GModel *geom, GModel *mesh, const double TOL);
};

#endif
