// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "CutMesh.h"
#include "GModel.h"
#include "gmshLevelset.h"


StringXNumber CutMeshOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.},
  {GMSH_FULLRC, "Split", NULL, 0.},
  {GMSH_FULLRC, "SaveTri", NULL, 0.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMeshPlugin() {
    return new GMSH_CutMeshPlugin();
  }
}

std::string GMSH_CutMeshPlugin::getHelp() const
{
  return "Plugin(CutMesh) cuts the mesh of the current GModel with "
    "the zero value of the levelset defined with the view 'View'."
    "Sub-elements are created in the new model (polygons in 2D and "
    "polyhedra in 3D) and border elements are created on the zero-levelset.\n\n"
    "If `Split' is nonzero, the plugin splits the mesh"
    "along the edges of the cut elements in the positive side.\n\n"
    "If 'SaveTri' is nonzero, the sub-elements are saved as simplices.\n\n"
    "Plugin(CutMesh) creates one new GModel.";
}

int GMSH_CutMeshPlugin::getNbOptions() const
{
  return sizeof(CutMeshOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutMeshPlugin::getOption(int iopt)
{
  return &CutMeshOptions_Number[iopt];
}

void GMSH_CutMeshPlugin::run(){
  
  int iView = (int)CutMeshOptions_Number[0].def;
  if(iView < 0)
    iView = PView::list.size() - 1;

  gLevelsetPostView *gLs = new gLevelsetPostView(iView);

  int split = (int)CutMeshOptions_Number[1].def;
  int saveTri = (int)CutMeshOptions_Number[2].def;
  GModel *gm = GModel::current();
  gm->buildCutGModel(gLs, !split, saveTri);
}

