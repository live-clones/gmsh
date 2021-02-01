// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "GmshConfig.h"
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

StringXNumber SimplePartitionOptions_Number[] = {
  {GMSH_FULLRC, "NumSlicesX", nullptr, 4.},
  {GMSH_FULLRC, "NumSlicesY", nullptr, 1.},
  {GMSH_FULLRC, "NumSlicesZ", nullptr, 1.},
  {GMSH_FULLRC, "CreateTopology", nullptr, 1.},
};

StringXString SimplePartitionOptions_String[] = {
  {GMSH_FULLRC, "MappingX", nullptr, "t"},
  {GMSH_FULLRC, "MappingY", nullptr, "t"},
  {GMSH_FULLRC, "MappingZ", nullptr, "t"}};

extern "C" {
GMSH_Plugin *GMSH_RegisterSimplePartitionPlugin()
{
  return new GMSH_SimplePartitionPlugin();
}
}

std::string GMSH_SimplePartitionPlugin::getHelp() const
{
  return "Plugin(SimplePartition) partitions the current mesh into "
         "`NumSlicesX', `NumSlicesY' and `NumSlicesZ' slices along the X-, Y- "
         "and Z-axis, respectively. The distribtion of these slices is "
         "governed "
         "by `MappingX', `MappingY' and `MappingZ', where `t' is a normalized "
         "absissa along each direction. (Setting `MappingX' to `t' will thus "
         "lead "
         "to equidistant slices along the X-axis.)\n\n"
         "The plugin creates the topology of the partitioned entities if "
         "`CreateTopology' is set.";
}

int GMSH_SimplePartitionPlugin::getNbOptions() const
{
  return sizeof(SimplePartitionOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SimplePartitionPlugin::getOption(int iopt)
{
  return &SimplePartitionOptions_Number[iopt];
}

int GMSH_SimplePartitionPlugin::getNbOptionsStr() const
{
  return sizeof(SimplePartitionOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_SimplePartitionPlugin::getOptionStr(int iopt)
{
  return &SimplePartitionOptions_String[iopt];
}

void GMSH_SimplePartitionPlugin::run()
{
#if defined(HAVE_MESH)
  int numSlicesX = (int)SimplePartitionOptions_Number[0].def;
  int numSlicesY = (int)SimplePartitionOptions_Number[1].def;
  int numSlicesZ = (int)SimplePartitionOptions_Number[2].def;
  int createTopology = (int)SimplePartitionOptions_Number[3].def;
  std::vector<std::string> exprX(1), exprY(1), exprZ(1);
  exprX[0] = SimplePartitionOptions_String[0].def;
  exprY[0] = SimplePartitionOptions_String[1].def;
  exprZ[0] = SimplePartitionOptions_String[2].def;

  GModel *m = GModel::current();

  if(!m->getNumMeshElements()) {
    Msg::Error("Plugin(SimplePartition) requires a mesh");
    return;
  }

  if(numSlicesX < 1 || numSlicesY < 1 || numSlicesZ < 1) {
    Msg::Error("Number of slices should be strictly positive");
    return;
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

  std::vector<GEntity *> entities;
  m->getEntities(entities);
  std::vector<std::pair<MElement *, int> > elmToPartition;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      SPoint3 point = e->barycenter();
      int part = 0;
      for(int kx = 0; kx < numSlicesX; kx++) {
        if(part) break;
        for(int ky = 0; ky < numSlicesY; ky++) {
          if(part) break;
          for(int kz = 0; kz < numSlicesZ; kz++) {
            if(part) break;
            if((emptyX || (kx == 0 && ppX[0] == point[0]) ||
                (ppX[kx] < point[0] && point[0] <= ppX[kx + 1])) &&
               (emptyY || (ky == 0 && ppY[0] == point[1]) ||
                (ppY[ky] < point[1] && point[1] <= ppY[ky + 1])) &&
               (emptyZ || (kz == 0 && ppZ[0] == point[2]) ||
                (ppZ[kz] < point[2] && point[2] <= ppZ[kz + 1]))) {
              part = kx * numSlicesY * numSlicesZ + ky * numSlicesZ + kz + 1;
              elmToPartition.push_back(
                std::pair<MElement *, unsigned int>(e, part));
              e->setPartition(part); // this will be removed
            }
          }
        }
      }
    }
  }

  opt_mesh_partition_create_topology(0, GMSH_SET | GMSH_GUI, createTopology);

  int ier = PartitionUsingThisSplit(m, numSlicesX * numSlicesY * numSlicesZ,
                                    elmToPartition);
  if(!ier) {
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX::instance()->mesh.changed = ENT_ALL;
  }

#else
  Msg::Error("Gmsh must be compiled with Mesh support to partition meshes");
#endif
}
