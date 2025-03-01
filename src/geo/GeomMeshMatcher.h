// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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
#include "GPoint.h"
#include "GCurve.h"
#include "GSurface.h"
#include "GVolume.h"

class GeomMeshMatcher {
private:
  std::vector<std::pair<GPoint *, GPoint *> > *
  matchVertices(GModel *m1, GModel *m2, bool &ok);
  std::vector<std::pair<GCurve *, GCurve *> > *
  matchEdges(GModel *m1, GModel *m2,
             std::vector<std::pair<GPoint *, GPoint *> > *coresp_v, bool &ok);
  std::vector<std::pair<GSurface *, GSurface *> > *
  matchFaces(GModel *m1, GModel *m2,
             std::vector<std::pair<GCurve *, GCurve *> > *coresp_e, bool &ok);
  std::vector<std::pair<GVolume *, GVolume *> > *
  matchRegions(GModel *m1, GModel *m2,
               std::vector<std::pair<GSurface *, GSurface *> > *coresp_f, bool &ok);
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
