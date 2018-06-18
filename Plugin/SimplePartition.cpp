// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "SimplePartition.h"
#include "GModel.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MFace.h"
#include "MEdge.h"
#include "mathEvaluator.h"

#if defined(HAVE_MESH)
#include "meshPartition.h"
#endif

#if __cplusplus >= 201103L
#include <unordered_map>
#define hashmap std::unordered_map
#else
#include <map>
#define hashmap std::map
#endif

int PartitionUsingThisSplit(GModel *const model, unsigned int npart,
                            hashmap<MElement*, unsigned int> &elmToPartition);

StringXNumber SimplePartitionOptions_Number[] = {
  {GMSH_FULLRC, "NumSlices", NULL, 4.},
  {GMSH_FULLRC, "Direction", NULL, 0.},
  {GMSH_FULLRC, "CreateTopology", NULL, 1.},
};

StringXString SimplePartitionOptions_String[] = {
  {GMSH_FULLRC, "Mapping", NULL, "t"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSimplePartitionPlugin()
  {
    return new GMSH_SimplePartitionPlugin();
  }
}

std::string GMSH_SimplePartitionPlugin::getHelp() const
{
  return "Plugin(SimplePartition) partitions the current mesh into "
    "`NumSlices' slices, along the X-, Y- or Z-axis depending on "
    "the value of `Direction' (0,1,2). The plugin creates partition "
    "topology if `CreateTopology' is set.";
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
#if defined(HAVE_METIS) && defined(HAVE_MESH)
  int numSlices = (int)SimplePartitionOptions_Number[0].def;
  int direction = (int)SimplePartitionOptions_Number[1].def;
  int createTopology = (int)SimplePartitionOptions_Number[2].def;
  std::vector<std::string> expr(1);
  expr[0] = SimplePartitionOptions_String[0].def;

  // partition the highest dimension elements in the current model (lower
  // dimension elements on boundaries cannot be tagged a priori: there are
  // special geometrical cases where this will fail)
  Msg::Info("Partitioning highest dimension elements");
  GModel *m = GModel::current();
  SBoundingBox3d bbox = m->bounds();
  double pmin = bbox.min()[direction], pmax = bbox.max()[direction];
  std::vector<double> pp(numSlices + 1);

  std::vector<std::string> variables(1);
  variables[0] = "t";
  mathEvaluator f(expr, variables);
  if(expr.empty()) return;
  std::vector<double> values(1), res(1);
  for(int p = 0; p <= numSlices; p++){
    double t = values[0] = (double)p / (double)numSlices;
    if(f.eval(values, res)) t = res[0];
    pp[p] = pmin + t * (pmax - pmin);
  }
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  hashmap<MElement*, unsigned int> elmToPartition;
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    for(unsigned int j = 0; j < ge->getNumMeshElements(); j++){
      MElement *e = ge->getMeshElement(j);
      SPoint3 point = e->barycenter();
      for(unsigned int k = 0; k < numSlices; k++){
        if(pp[k] < point[direction] && pp[k+1] >= point[direction]){
          elmToPartition.insert(std::pair<MElement*, unsigned int>(e, k+1));
          break;
        }

        if(pp[0] == point[direction]){
          elmToPartition.insert(std::pair<MElement*, unsigned int>(e, 0+1));
          break;
        }
      }
    }
  }

  opt_mesh_partition_create_topology(0, GMSH_SET, createTopology);

  PartitionUsingThisSplit(m, numSlices, elmToPartition);

#else
  Msg::Error("Gmsh must be compiled with Mesh and METIS support to partition meshes");
#endif
}
