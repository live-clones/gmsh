// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "sizeField.h"
#include "GModel.h"
#include "GFace.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "BackgroundMeshTools.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtCrossField.h"
#include "qmtSizeMap.h"
#endif

static void printSizeField(const char *fn, std::vector<MTriangle *> &triangles,
                           std::unordered_map<MVertex *, double> &sizeField)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View\"SIZE FIELD\"{\n");
  for(auto t : triangles) {
    fprintf(f,
            "ST(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E)"
            "{%12.5E,%12.5E,%12.5E};\n",
            t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
            t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
            t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
            sizeField[t->getVertex(0)], sizeField[t->getVertex(1)],
            sizeField[t->getVertex(2)]);
  }
  fprintf(f, "};\n");
  fclose(f);
}

int createSizeFieldFromExistingMesh(GModel *gm, bool computeCrosses)
{
  return 0;
#if defined(HAVE_QUADMESHINGTOOLS)

  std::vector<MTriangle *> triangles;
  for(auto itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
    //    quadsToTriangles(gf, minqual);
    if((*itf)->tag() < 100000)
      triangles.insert(triangles.end(), (*itf)->triangles.begin(),
                       (*itf)->triangles.end());
  }

  std::unordered_map<MVertex *, std::vector<MVertex *> > v2v;
  buildVertexToVertexMap(triangles, v2v);

  std::unordered_map<MVertex *, double> sizeField;

  for(auto it : v2v) {
    MVertex *v = it.first;
    double size = 1.e22, U, V;
    if(v->onWhat()->dim() == 1) {
      v->getParameter(0, U);
      size = BGM_MeshSize(v->onWhat(), U, 0., v->x(), v->y(), v->z());
    }
    else if(v->onWhat()->dim() == 2) {
      v->getParameter(0, U);
      v->getParameter(1, V);
      size = BGM_MeshSize(v->onWhat(), U, V, v->x(), v->y(), v->z());
    }
    else
      size = BGM_MeshSize(v->onWhat(), 0., 0., v->x(), v->y(), v->z());
    sizeField[v] = size;
  }

  printSizeField("size_field.pos", triangles, sizeField);
  int sows = sizeMapOneWaySmoothing(triangles, sizeField, 1.2);
  if(sows != 0) {
    Msg::Warning("failed to smooth size map");
    return sows;
  }
  printSizeField("smoothed_size_field.pos", triangles, sizeField);
#endif
  return 0;
}
