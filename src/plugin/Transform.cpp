// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Transform.h"

GMSH_TransformPlugin::GMSH_TransformPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "A11", nullptr, 1., ""},
                     {GMSH_FULLRC, "A12", nullptr, 0., ""},
                     {GMSH_FULLRC, "A13", nullptr, 0., ""},
                     {GMSH_FULLRC, "A21", nullptr, 0., ""},
                     {GMSH_FULLRC, "A22", nullptr, 1., ""},
                     {GMSH_FULLRC, "A23", nullptr, 0., ""},
                     {GMSH_FULLRC, "A31", nullptr, 0., ""},
                     {GMSH_FULLRC, "A32", nullptr, 0., ""},
                     {GMSH_FULLRC, "A33", nullptr, 1., ""},
                     {GMSH_FULLRC, "Tx", nullptr, 0., ""},
                     {GMSH_FULLRC, "Ty", nullptr, 0.,
                      ""}, // cannot use T2 (reserved token in parser)
                     {GMSH_FULLRC, "Tz", nullptr, 0.,
                      ""}, // cannot use T3 (reserved token in parser)
                     {GMSH_FULLRC, "SwapOrientation", nullptr, 0., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_TransformPlugin::getHelp() const
{
  return "Plugin(Transform) transforms the homogeneous "
         "node coordinates (x,y,z,1) of the elements in "
         "the view `View' by the matrix\n\n"
         "[`A11' `A12' `A13' `Tx']\n"
         "[`A21' `A22' `A23' `Ty']\n"
         "[`A31' `A32' `A33' `Tz'].\n\n"
         "If `SwapOrientation' is set, the orientation of the "
         "elements is reversed.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Transform) is executed in-place.";
}

PView *GMSH_TransformPlugin::execute(PView *v)
{
  double mat[3][4];

  mat[0][0] = option(0);
  mat[0][1] = option(1);
  mat[0][2] = option(2);
  mat[1][0] = option(3);
  mat[1][1] = option(4);
  mat[1][2] = option(5);
  mat[2][0] = option(6);
  mat[2][1] = option(7);
  mat[2][2] = option(8);

  mat[0][3] = option(9);
  mat[1][3] = option(10);
  mat[2][3] = option(11);

  int swap = (int)option(12);
  int iView = (int)option(13);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

  // elements are reversed at step 0, for all steps
  if(swap) {
    for(int ent = 0; ent < data1->getNumEntities(0); ent++)
      for(int ele = 0; ele < data1->getNumElements(0, ent); ele++)
        data1->reverseElement(0, ent, ele);
  }

  forEachNode(data1, [&](int step, int ent, int ele, int nod) {
    double x, y, z;
    data1->getNode(step, ent, ele, nod, x, y, z);
    double x2 = mat[0][0] * x + mat[0][1] * y + mat[0][2] * z + mat[0][3];
    double y2 = mat[1][0] * x + mat[1][1] * y + mat[1][2] * z + mat[1][3];
    double z2 = mat[2][0] * x + mat[2][1] * y + mat[2][2] * z + mat[2][3];
    data1->setNode(step, ent, ele, nod, x2, y2, z2);
  });

  data1->finalize();

  v1->setChanged(true);
  return v1;
}
