// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MeshSizeFieldView.h"
#include "GmshConfig.h"
#include "GModel.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

StringXNumber MeshSizeFieldViewOptions_Number[] = {
  {GMSH_FULLRC, "MeshSizeField", nullptr, 0.},
  {GMSH_FULLRC, "View", nullptr, -1.},
  {GMSH_FULLRC, "Component", nullptr, 0.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshSizeFieldViewPlugin()
{
  return new GMSH_MeshSizeFieldViewPlugin();
}
}

std::string GMSH_MeshSizeFieldViewPlugin::getHelp() const
{
  return "Plugin(MeshSizeFieldView) evaluates the mesh size field "
         "`MeshSizeField' "
         "on specified `Component` (0 for scalar) of the post-processing view "
         "`View'.";
}

int GMSH_MeshSizeFieldViewPlugin::getNbOptions() const
{
  return sizeof(MeshSizeFieldViewOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MeshSizeFieldViewPlugin::getOption(int iopt)
{
  return &MeshSizeFieldViewOptions_Number[iopt];
}

PView *GMSH_MeshSizeFieldViewPlugin::execute(PView *view)
{
#if defined(HAVE_MESH)
  int field = (int)MeshSizeFieldViewOptions_Number[0].def;
  int iView = (int)MeshSizeFieldViewOptions_Number[1].def;
  int comp = (int)MeshSizeFieldViewOptions_Number[2].def;

  PView *v1 = getView(iView, view);
  if(!v1) return view;
  Field *f = GModel::current()->getFields()->get(field);
  if(f)
    f->putOnView(v1, comp);
  else
    Msg::Error("Unknown mesh size field %d", field);
  return v1;
#else
  Msg::Error("Plugin(MeshSizeFieldView) requires the mesh module");
  return view;
#endif
}
