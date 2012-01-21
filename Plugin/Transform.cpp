// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Transform.h"

StringXNumber TransformOptions_Number[] = {
  {GMSH_FULLRC, "A11", NULL, 1.},
  {GMSH_FULLRC, "A12", NULL, 0.},
  {GMSH_FULLRC, "A13", NULL, 0.},
  {GMSH_FULLRC, "A21", NULL, 0.},
  {GMSH_FULLRC, "A22", NULL, 1.},
  {GMSH_FULLRC, "A23", NULL, 0.},
  {GMSH_FULLRC, "A31", NULL, 0.},
  {GMSH_FULLRC, "A32", NULL, 0.},
  {GMSH_FULLRC, "A33", NULL, 1.},
  {GMSH_FULLRC, "Tx", NULL, 0.}, 
  {GMSH_FULLRC, "Ty", NULL, 0.}, // cannot use T2 (reserved token in parser)
  {GMSH_FULLRC, "Tz", NULL, 0.}, // cannot use T3 (reserved token in parser)
  {GMSH_FULLRC, "SwapOrientation", NULL, 0.},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin()
  {
    return new GMSH_TransformPlugin();
  }
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

int GMSH_TransformPlugin::getNbOptions() const
{
  return sizeof(TransformOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TransformPlugin::getOption(int iopt)
{
  return &TransformOptions_Number[iopt];
}

PView *GMSH_TransformPlugin::execute(PView *v)
{
  double mat[3][4];

  mat[0][0] = TransformOptions_Number[0].def;
  mat[0][1] = TransformOptions_Number[1].def;
  mat[0][2] = TransformOptions_Number[2].def;
  mat[1][0] = TransformOptions_Number[3].def;
  mat[1][1] = TransformOptions_Number[4].def;
  mat[1][2] = TransformOptions_Number[5].def;
  mat[2][0] = TransformOptions_Number[6].def;
  mat[2][1] = TransformOptions_Number[7].def;
  mat[2][2] = TransformOptions_Number[8].def;

  mat[0][3] = TransformOptions_Number[9].def;
  mat[1][3] = TransformOptions_Number[10].def;
  mat[2][3] = TransformOptions_Number[11].def;

  int swap = (int)TransformOptions_Number[12].def;
  int iView = (int)TransformOptions_Number[13].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

  // tag all the nodes with "0" (the default tag)
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
        if(data1->skipElement(step, ent, ele)) continue;
        if(swap) data1->revertElement(step, ent, ele);
        for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++)
          data1->tagNode(step, ent, ele, nod, 0);
      }
    }
  }
  
  // transform all "0" nodes
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
        if(data1->skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++){
          double x, y, z;
          int tag = data1->getNode(step, ent, ele, nod, x, y, z);
          if(!tag){
            double x2, y2, z2;
            x2 = mat[0][0] * x + mat[0][1] * y + mat[0][2] * z + mat[0][3];
            y2 = mat[1][0] * x + mat[1][1] * y + mat[1][2] * z + mat[1][3];
            z2 = mat[2][0] * x + mat[2][1] * y + mat[2][2] * z + mat[2][3];
            data1->setNode(step, ent, ele, nod, x2, y2, z2);
            data1->tagNode(step, ent, ele, nod, 1);
          }
        }
      }
    }
  }

  data1->finalize();

  v1->setChanged(true);
  return v1;
}
