// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "GmshConfig.h"
#include "HilbertPartition.h"
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

StringXNumber HilbertPartitionOptions_Number[] = {
  {GMSH_FULLRC, "NumPartitions", nullptr, 4., ""},
};

StringXString HilbertPartitionOptions_String[] = {
};

extern "C" {
GMSH_Plugin *GMSH_RegisterHilbertPartitionPlugin()
{
  return new GMSH_HilbertPartitionPlugin();
}
}

std::string GMSH_HilbertPartitionPlugin::getHelp() const
{
  return "Plugin(HilbertPartition) partitions the current mesh into "
         "`NumPartitions' partitions using a Hilbert curve.";
}

int GMSH_HilbertPartitionPlugin::getNbOptions() const
{
  return sizeof(HilbertPartitionOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HilbertPartitionPlugin::getOption(int iopt)
{
  return &HilbertPartitionOptions_Number[iopt];
}

int GMSH_HilbertPartitionPlugin::getNbOptionsStr() const
{
  return sizeof(HilbertPartitionOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_HilbertPartitionPlugin::getOptionStr(int iopt)
{
  return &HilbertPartitionOptions_String[iopt];
}

int GMSH_HilbertPartitionPlugin::run()
{
#if defined(HAVE_MESH)
  int numPartitions = (int)HilbertPartitionOptions_Number[0].def;

  GModel *m = GModel::current();

  if(!m->getNumMeshElements()) {
    Msg::Error("Plugin(HilbertPartition) requires a mesh");
    return 0;
  }

  if(numPartitions < 1) {
    Msg::Error("Number of partitions should be strictly positive");
    return 0;
  }
  m->unpartitionMesh();

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

  int ier = PartitionUsingThisSplit(m, elmToPartition);
  if(!ier) {
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX::instance()->mesh.changed = ENT_ALL;
  }

#else
  Msg::Error("Gmsh must be compiled with Mesh support to partition meshes");
#endif

  return 0;
}
