// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Remove.h"

GMSH_RemovePlugin::GMSH_RemovePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "Text2D", nullptr, 1., ""},
                     {GMSH_FULLRC, "Text3D", nullptr, 1., ""},
                     {GMSH_FULLRC, "Points", nullptr, 0., ""},
                     {GMSH_FULLRC, "Lines", nullptr, 0., ""},
                     {GMSH_FULLRC, "Triangles", nullptr, 0., ""},
                     {GMSH_FULLRC, "Quadrangles", nullptr, 0., ""},
                     {GMSH_FULLRC, "Tetrahedra", nullptr, 0., ""},
                     {GMSH_FULLRC, "Hexahedra", nullptr, 0., ""},
                     {GMSH_FULLRC, "Prisms", nullptr, 0., ""},
                     {GMSH_FULLRC, "Pyramids", nullptr, 0., ""},
                     {GMSH_FULLRC, "Scalar", nullptr, 1., ""},
                     {GMSH_FULLRC, "Vector", nullptr, 1., ""},
                     {GMSH_FULLRC, "Tensor", nullptr, 1., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_RemovePlugin::getHelp() const
{
  return "Plugin(Remove) removes the marked items from the list-based "
         "view `View'.\n\nIf `View' < 0, the plugin is run on the current "
         "view.\n\nPlugin(Remove) is executed in-place.";
}

PView *GMSH_RemovePlugin::execute(PView *v)
{
  int iView = (int)option(13);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  int scalar = (int)option(10);
  int vector = (int)option(11);
  int tensor = (int)option(12);

  if(option(0)) data1->clearStrings(2);
  if(option(1)) data1->clearStrings(3);
  // options 2 to 9: points, lines, triangles, quadrangles, tetrahedra,
  // hexahedra, prisms and pyramids
  const int types[8] = {TYPE_PNT, TYPE_LIN, TYPE_TRI, TYPE_QUA,
                        TYPE_TET, TYPE_HEX, TYPE_PRI, TYPE_PYR};
  for(int i = 0; i < 8; i++) {
    if(!option(2 + i)) continue;
    if(scalar) data1->clearList(1, types[i]);
    if(vector) data1->clearList(3, types[i]);
    if(tensor) data1->clearList(9, types[i]);
  }

  data1->finalize();
  v1->setChanged(true);

  return v1;
}
