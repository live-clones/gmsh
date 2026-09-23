// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "GmshConfig.h"
#include <algorithm>
#include "SimplePartition.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MFace.h"
#include "MEdge.h"
#include "mathEvaluator.h"
#include "Context.h"

#if defined(HAVE_MESH)
#include "meshPartition.h"
#endif

GMSH_SimplePartitionPlugin::GMSH_SimplePartitionPlugin()
  : GMSH_MeshPlugin({{GMSH_FULLRC, "NumSlicesX", nullptr, 4., ""},
                     {GMSH_FULLRC, "NumSlicesY", nullptr, 1., ""},
                     {GMSH_FULLRC, "NumSlicesZ", nullptr, 1., ""}},
                    {{GMSH_FULLRC, "MappingX", nullptr, "t", ""},
                     {GMSH_FULLRC, "MappingY", nullptr, "t", ""},
                     {GMSH_FULLRC, "MappingZ", nullptr, "t", ""}})
{
}

std::string GMSH_SimplePartitionPlugin::getHelp() const
{
  return "Plugin(SimplePartition) partitions the current mesh into "
         "`NumSlicesX', `NumSlicesY' and `NumSlicesZ' slices along the X-, Y- "
         "and Z-axis, respectively. The distribution of these slices is "
         "governed by `MappingX', `MappingY' and `MappingZ', where `t' is a "
         "normalized absissa along each direction. (Setting `MappingX' to "
         "`t' will thus lead to equidistant slices along the X-axis.)";
}

int GMSH_SimplePartitionPlugin::run()
{
#if defined(HAVE_MESH)
  int numSlicesX = (int)option(0);
  int numSlicesY = (int)option(1);
  int numSlicesZ = (int)option(2);
  std::vector<std::string> exprX(1), exprY(1), exprZ(1);
  exprX[0] = optionStr(0);
  exprY[0] = optionStr(1);
  exprZ[0] = optionStr(2);

  GModel *m = GModel::current();

  if(!m->getNumMeshElements()) {
    Msg::Error("Plugin(SimplePartition) requires a mesh");
    return 0;
  }

  if(numSlicesX < 1 || numSlicesY < 1 || numSlicesZ < 1) {
    Msg::Error("Number of slices should be strictly positive");
    return 0;
  }
  m->unpartitionMesh();

  SBoundingBox3d bbox = m->bounds();
  double pminX = bbox.min()[0], pmaxX = bbox.max()[0];
  double pminY = bbox.min()[1], pmaxY = bbox.max()[1];
  double pminZ = bbox.min()[2], pmaxZ = bbox.max()[2];
  std::vector<double> ppX(numSlicesX + 1);
  std::vector<double> ppY(numSlicesY + 1);
  std::vector<double> ppZ(numSlicesZ + 1);
  std::vector<std::string> variables(1, "t");
  std::vector<double> values(1), res(1);

  {
    mathEvaluator f(exprX, variables);
    for(int p = 0; p <= numSlicesX; p++) {
      double t = values[0] = (double)p / (double)numSlicesX;
      if(f.eval(values, res)) t = res[0];
      ppX[p] = pminX + t * (pmaxX - pminX);
    }
  }
  bool emptyX = (ppX[0] == ppX[numSlicesX]);
  {
    mathEvaluator f(exprY, variables);
    for(int p = 0; p <= numSlicesY; p++) {
      double t = values[0] = (double)p / (double)numSlicesY;
      if(f.eval(values, res)) t = res[0];
      ppY[p] = pminY + t * (pmaxY - pminY);
    }
  }
  bool emptyY = (ppY[0] == ppY[numSlicesY]);
  {
    mathEvaluator f(exprZ, variables);
    for(int p = 0; p <= numSlicesZ; p++) {
      double t = values[0] = (double)p / (double)numSlicesZ;
      if(f.eval(values, res)) t = res[0];
      ppZ[p] = pminZ + t * (pmaxZ - pminZ);
    }
  }
  bool emptyZ = (ppZ[0] == ppZ[numSlicesZ]);

  // the slab of a coordinate: the number of inner slab boundaries below it,
  // so that it is in (pp[k], pp[k + 1]], the first and last slabs extending
  // to whatever is beyond the ends
  auto slab = [](const std::vector<double> &pp, bool empty, double p) {
    if(empty) return 0;
    return (int)(std::lower_bound(pp.begin() + 1, pp.end() - 1, p) -
                 (pp.begin() + 1));
  };

  std::vector<GEntity *> entities;
  m->getEntities(entities);
  std::vector<std::pair<MElement *, int> > elmToPartition;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      SPoint3 point = e->barycenter();
      int kx = slab(ppX, emptyX, point[0]);
      int ky = slab(ppY, emptyY, point[1]);
      int kz = slab(ppZ, emptyZ, point[2]);
      int part = kx * numSlicesY * numSlicesZ + ky * numSlicesZ + kz + 1;
      elmToPartition.push_back(std::pair<MElement *, int>(e, part));
      e->setPartition(part); // this will be removed
    }
  }

  int ier = PartitionUsingThisSplit(m, elmToPartition);
  if(!ier) {
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX::instance()->meshChanged();
  }

#else
  Msg::Error("Gmsh must be compiled with Mesh support to partition meshes");
#endif

  return 0;
}
