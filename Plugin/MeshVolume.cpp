// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MeshVolume.h"
#include "GModel.h"
#include "PViewOptions.h"

StringXNumber MeshVolumeOptions_Number[] = {
  {GMSH_FULLRC, "PhysicalGroup", nullptr, -1},
  {GMSH_FULLRC, "Dimension", nullptr, 3}};

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshVolumePlugin()
{
  return new GMSH_MeshVolumePlugin();
}
}

std::string GMSH_MeshVolumePlugin::getHelp() const
{
  return "Plugin(MeshVolume) computes the volume of the mesh.\n\n"
         "Only the elements in the physical group `PhysicalGroup' "
         "of dimension `Dimension' are taken into account, unless "
         "'PhysicalGroup' is negative, in which case all the elements of "
         "the given `Dimension' are considered. If `Dimension` is "
         "negative, all the elments are considered.\n\n"
         "Plugin(MeshVolume) creates one new list-based view.";
}

int GMSH_MeshVolumePlugin::getNbOptions() const
{
  return sizeof(MeshVolumeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MeshVolumePlugin::getOption(int iopt)
{
  return &MeshVolumeOptions_Number[iopt];
}

PView *GMSH_MeshVolumePlugin::execute(PView *v)
{
  int physical = (int)MeshVolumeOptions_Number[0].def;
  int dim = (int)MeshVolumeOptions_Number[1].def;

  GModel *model = GModel::current();
  if(!model->getNumMeshVertices()) {
    Msg::Error("Plugin(MeshVolume) needs a mesh");
    return v;
  }

  std::vector<GEntity *> entities;
  if(physical == -1) { model->getEntities(entities, dim); }
  else {
    std::map<int, std::vector<GEntity *> > groups;
    model->getPhysicalGroups(dim, groups);
    entities = groups[physical];
  }

  if(entities.empty()) Msg::Warning("The specified domain is empty");

  double vol = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
      vol += entities[i]->getMeshElement(j)->getVolume();

  Msg::Info("Mesh volume (physical %d | dimension %d): %g", physical, dim, vol);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  SBoundingBox3d bbox = model->bounds();
  data2->SP.push_back(bbox.center().x());
  data2->SP.push_back(bbox.center().y());
  data2->SP.push_back(bbox.center().z());
  data2->SP.push_back(vol);
  data2->NbSP = 1;
  v2->getOptions()->intervalsType = PViewOptions::Numeric;
  data2->setName("MeshVolume");
  data2->setFileName("MeshVolume.pos");
  data2->finalize();
  return v2;
}
