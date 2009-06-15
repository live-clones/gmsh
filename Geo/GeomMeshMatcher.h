// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Bastien Gorissen

#ifndef GEOMMESHMATCHER_H
#define GEOMMESHMATCHER_H

#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "Pair.h"

#include <vector>

class GeomMeshMatcher {
 private:
  vector<Pair<GVertex*,GVertex*> >* matchVertices(GModel* m1, GModel *m2);
  vector<Pair<GEdge*,GEdge*> >* matchEdges(GModel* m1, GModel* m2, vector<Pair<GVertex*,GVertex*> >* coresp_v);
  vector<Pair<GFace*,GFace*> >* matchFaces(GModel* m1, GModel* m2,  vector<Pair<GEdge*,GEdge*> >* coresp_e);
  vector<Pair<GRegion*,GRegion*> >* matchRegions(GModel* m1, GModel* m2, vector<Pair<GFace*,GFace*> >* coresp_f);
  static GeomMeshMatcher* _gmm_instance;
  GeomMeshMatcher() {};
  ~GeomMeshMatcher() {};

 public:
  static GeomMeshMatcher* instance();
  static void destroy();
  int match(GModel* geom, GModel* mesh);
};




#endif
