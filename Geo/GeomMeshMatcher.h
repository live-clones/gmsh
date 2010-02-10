// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Bastien Gorissen
//

#ifndef _GEOM_MESH_MATCHER_H_
#define _GEOM_MESH_MATCHER_H_

#include <vector>
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "Pair.h"

class GeomMeshMatcher {
 private:
  std::vector<Pair<GVertex*, GVertex*> > *matchVertices(GModel *m1, GModel *m2, bool& ok);
  std::vector<Pair<GEdge*, GEdge*> > *matchEdges
    (GModel* m1, GModel* m2, std::vector<Pair<GVertex*, GVertex*> > *coresp_v, bool& ok);
  std::vector<Pair<GFace*, GFace*> > *matchFaces
    (GModel* m1, GModel* m2,  std::vector<Pair<GEdge*,GEdge*> > *coresp_e, bool& ok);
  std::vector<Pair<GRegion*, GRegion*> > *matchRegions
    (GModel *m1, GModel *m2, std::vector<Pair<GFace*,GFace*> > *coresp_f, bool& ok);
  static GeomMeshMatcher *_gmm_instance;
  GeomMeshMatcher() {}
  ~GeomMeshMatcher() {}

 public:
  static GeomMeshMatcher *instance();
  static void destroy();
  int match(GModel* geom, GModel* mesh);
};

#endif
