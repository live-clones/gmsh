// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MeshSizeFieldView.h"
#include "GmshConfig.h"
#include "GModel.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

GMSH_MeshSizeFieldViewPlugin::GMSH_MeshSizeFieldViewPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "MeshSizeField", nullptr, 0., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""},
                     {GMSH_FULLRC, "Component", nullptr, 0., ""}})
{
}

std::string GMSH_MeshSizeFieldViewPlugin::getHelp() const
{
  return "Plugin(MeshSizeFieldView) evaluates the mesh size field "
         "`MeshSizeField' "
         "on the component `Component' (0 for scalar data, all the components "
         "if negative) of the post-processing view `View'.";
}

PView *GMSH_MeshSizeFieldViewPlugin::execute(PView *view)
{
#if defined(HAVE_MESH)
  int field = (int)option(0);
  int iView = (int)option(1);
  int comp = (int)option(2);

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
