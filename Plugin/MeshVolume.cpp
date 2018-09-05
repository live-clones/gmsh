// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "MeshVolume.h"
#include "GModel.h"


StringXNumber MeshVolumeOptions_Number[] = {
  {GMSH_FULLRC, "Physical",  NULL, -1},
  {GMSH_FULLRC, "Dimension", NULL,  3}
};

extern "C"{
  GMSH_Plugin *GMSH_RegisterMeshVolumePlugin(){
    return new GMSH_MeshVolumePlugin();
  }
}

std::string GMSH_MeshVolumePlugin::getHelp() const{
  return "Plugin(MeshVolume) computes the volume of the mesh. "
    "Only the elements tagged with the physical given in 'Physical' "
    "and with the dimension given in 'Dimension' are taken into account. "
    "If 'Physical' is equal to -1, "
    "the entire mesh (of the given dimension) is considered.";
}

int GMSH_MeshVolumePlugin::getNbOptions() const{
  return sizeof(MeshVolumeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MeshVolumePlugin::getOption(int iopt){
  return &MeshVolumeOptions_Number[iopt];
}

void GMSH_MeshVolumePlugin::run(){
  // Get input data //
  ////////////////////
  int physical = (int)MeshVolumeOptions_Number[0].def;
  int dim      = (int)MeshVolumeOptions_Number[1].def;

  // Current GModel //
  ////////////////////
  GModel* model = GModel::current();

  // Entities //
  //////////////
  std::vector<GEntity*> entities;
  // If we take all the entities, regardless of the physical tag
  if(physical == -1){
    model->getEntities(entities, dim);
  }
  // If we want only the entities of a given physical tag
  else{
    std::map<int, std::vector<GEntity*> > groups;
    model->getPhysicalGroups(dim, groups); // Physcial map (per dimension)
    entities = groups[physical];           // Requested entities
  }
  // Check
  if(entities.empty()){
    Msg::Error("Physical group %d (dimension %d) is empty", physical, dim);
    return;
  }

  // Iterate on elements and compute the volume //
  ////////////////////////////////////////////////
  double vol = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
      vol += entities[i]->getMeshElement(j)->getVolume();

  // Display volume as a message //
  /////////////////////////////////
  Msg::Info("Mesh volume (physical %d | dimension %d): %g", vol, physical, dim);
}
