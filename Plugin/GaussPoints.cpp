// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GaussPoints.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"

StringXNumber GaussPointsOptions_Number[] = {
  {GMSH_FULLRC, "Order", NULL, 0},
  {GMSH_FULLRC, "Dimension", NULL, 2},
  {GMSH_FULLRC, "PhysicalGroup", NULL, 0}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGaussPointsPlugin()
  {
    return new GMSH_GaussPointsPlugin();
  }
}

int GMSH_GaussPointsPlugin::getNbOptions() const
{
  return sizeof(GaussPointsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_GaussPointsPlugin::getOption(int iopt)
{
  return &GaussPointsOptions_Number[iopt];
}

std::string GMSH_GaussPointsPlugin::getHelp() const
{
  return "Given an input mesh, Plugin(GaussPoints) creates a view containing "
    "the Gauss points for a given polynomial `Order'.\n\n"
    "If `PhysicalGroup' is nonzero, the plugin only creates points for the "
    "elements belonging to the group.";
}

PView* GMSH_GaussPointsPlugin::execute(PView *v)
{
  int order = (int)GaussPointsOptions_Number[0].def;
  int dim = (int)GaussPointsOptions_Number[1].def;
  int physical = (int)GaussPointsOptions_Number[2].def;

  GModel *m = GModel::current();
  std::vector<GEntity*> entities;
  if(physical){
    std::map<int, std::vector<GEntity*> > groups[4];
    m->getPhysicalGroups(groups);
    entities = groups[dim][physical];
  }
  else{
    m->getEntities(entities, dim);
  }

  if(entities.empty()){
    Msg::Error("No entities");
    return v;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      MElement *e = entities[i]->getMeshElement(j);
      int npts; IntPt *gp;
      e->getIntegrationPoints(order, &npts, &gp);
      for (int i = 0; i < npts; i++){
        double u = gp[i].pt[0];
        double v = gp[i].pt[1];
        double w = gp[i].pt[2];
        //double weight = gp[i].weight;
        SPoint3 p;
        e->pnt(u, v, w, p);
        data2->SP.push_back(p.x());
        data2->SP.push_back(p.y());
        data2->SP.push_back(p.z());
        data2->SP.push_back(e->getNum());
        data2->NbSP++;
      }
    }
  }

  data2->setName("GaussPoints");
  data2->setFileName("GaussPoints.pos");
  data2->finalize();

  return v;
}
