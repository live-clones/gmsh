// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MeshVolHexPercentage.h"
#include "GModel.h"
#include "PViewOptions.h"

StringXNumber MeshVolHexPercentageOptions_Number[] = {
  {GMSH_FULLRC, "PhysicalGroup", NULL, -1},
  {GMSH_FULLRC, "Dimension", NULL, 3}
};

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshVolHexPercentagePlugin()
{
  return new GMSH_MeshVolHexPercentagePlugin();
}
}

std::string GMSH_MeshVolHexPercentagePlugin::getHelp() const
{
  return "Plugin(MeshVolHexPercentage) computes the hex volume percentage of the mesh.\n\n"
         "Only the elements in the physical group `PhysicalGroup' "
         "of dimension `Dimension' are taken into account, unless "
         "'PhysicalGroup' is negative, in which case all the elements of "
         "the given `Dimension' are considered. If `Dimension` is "
         "negative, all the elments are considered.\n\n"
         "Plugin(MeshVolHexPercentage) creates one new view.";
}

int GMSH_MeshVolHexPercentagePlugin::getNbOptions() const
{
  return sizeof(MeshVolHexPercentageOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MeshVolHexPercentagePlugin::getOption(int iopt)
{
  return &MeshVolHexPercentageOptions_Number[iopt];
}

PView *GMSH_MeshVolHexPercentagePlugin::execute(PView *v)
{
  int physical = (int)MeshVolHexPercentageOptions_Number[0].def;
  int dim = (int)MeshVolHexPercentageOptions_Number[1].def;

  GModel *model = GModel::current();
  if(!model->getNumMeshVertices()) {
    Msg::Error("Plugin(MeshVolHexPercentage) needs a mesh");
    return v;
  }

  std::vector<GEntity *> entities;
  if(physical == -1) {
    model->getEntities(entities, dim);
  }
  else {
    std::map<int, std::vector<GEntity *> > groups;
    model->getPhysicalGroups(dim, groups);
    entities = groups[physical];
  }

  if(entities.empty())
    Msg::Warning("The specified domain is empty");

  double vol = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
      vol += entities[i]->getMeshElement(j)->getVolume();


  double volHex = 0;
  for(std::size_t i = 0; i < entities.size(); i++){
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++){

      if (entities[i]->getMeshElement(j)->getTypeForMSH() == 5 ) 
        volHex += entities[i]->getMeshElement(j)->getVolume();
    }
  }


  int hexes = 0;
  int tets = 0;
  int prisms = 0;
  int pyramids = 0;
  int total =0;
  for(std::size_t i = 0; i < entities.size(); i++){
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++){
      if (entities[i]->getMeshElement(j)->getTypeForMSH() == 4 ) tets++;
      if (entities[i]->getMeshElement(j)->getTypeForMSH() == 5 ) hexes++;
      if (entities[i]->getMeshElement(j)->getTypeForMSH() == 6 ) prisms++;
      if (entities[i]->getMeshElement(j)->getTypeForMSH() == 7 ) pyramids++;
      total++;
    }
  }


  Msg::Info("tets   = %d", tets);
  Msg::Info("hexes  = %d", hexes);
  Msg::Info("prisms = %d", prisms);
  Msg::Info("pyr    = %d", pyramids);
  Msg::Info("total  = %d\n", total);


  double volRatio = volHex/vol;
  Msg::Info("Element ratio = %f", (float)hexes/(float)total);
  Msg::Info("Volume ratio = %f\n", volRatio);

  Msg::Info("Hex volume  = %f", volHex);
  Msg::Info("Mesh volume (physical %d | dimension %d): %g",
            physical, dim, vol);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  SBoundingBox3d bbox = model->bounds();
  data2->SP.push_back(bbox.center().x());
  data2->SP.push_back(bbox.center().y());
  data2->SP.push_back(bbox.center().z());
  data2->SP.push_back(volRatio);
  data2->NbSP = 1;
  v2->getOptions()->intervalsType = PViewOptions::Numeric;
  data2->setName("MeshVolHexPercentage");
  data2->setFileName("MeshVolHexPercentage.pos");
  data2->finalize();
  return v2;
}
