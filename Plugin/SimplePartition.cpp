// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "SimplePartition.h"
#include "GModel.h"
#include "MElement.h"
#if defined(HAVE_MESH)
#include "meshPartition.h"
#endif

StringXNumber SimplePartitionOptions_Number[] = {
  {GMSH_FULLRC, "NumSlices", NULL, 4.},
  {GMSH_FULLRC, "Direction", NULL, 0.},
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
    "the value of `Direction' (0,1,2).";
}

int GMSH_SimplePartitionPlugin::getNbOptions() const
{
  return sizeof(SimplePartitionOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SimplePartitionPlugin::getOption(int iopt)
{
  return &SimplePartitionOptions_Number[iopt];
}

PView *GMSH_SimplePartitionPlugin::execute(PView *v)
{
  int numSlices = (int)SimplePartitionOptions_Number[0].def;
  int direction = (int)SimplePartitionOptions_Number[1].def;

  // partition the current model
  GModel *m = GModel::current();
  SBoundingBox3d bbox = m->bounds();
  double pmin = bbox.min()[direction], pmax = bbox.max()[direction];
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    int n = entities[i]->getNumMeshElements();
    for(int j = 0; j < n; j++){
      MElement *e = entities[i]->getMeshElement(j);
      double val = pmax;
      for(int k = 0; k < e->getNumVertices(); k++){
        MVertex *v = e->getVertex(k);
        val = std::min(val, v->point()[direction]);
      }
      for(int p = 0; p < numSlices; p++){
        double p1 = pmin + p * (pmax - pmin) / numSlices;
        double p2 = pmin + (p + 1) * (pmax - pmin) / numSlices;
        if(val >= p1 && val < p2){
          e->setPartition(p + 1);
          break;
        }
      }
    }
  }
  m->recomputeMeshPartitions();

#if defined(HAVE_MESH)
  CreatePartitionBoundaries(m, false, false);
#endif
  return v;
}
