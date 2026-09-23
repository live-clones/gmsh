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

  if(option(0)) {
    data1->NbT2 = 0;
    data1->T2D.clear();
    data1->T2C.clear();
  }
  if(option(1)) {
    data1->NbT3 = 0;
    data1->T3D.clear();
    data1->T3C.clear();
  }
  if(option(2)) {
    if(scalar) {
      data1->NbSP = 0;
      data1->SP.clear();
    }
    if(vector) {
      data1->NbVP = 0;
      data1->VP.clear();
    }
    if(tensor) {
      data1->NbTP = 0;
      data1->TP.clear();
    }
  }
  if(option(3)) {
    if(scalar) {
      data1->NbSL = 0;
      data1->SL.clear();
    }
    if(vector) {
      data1->NbVL = 0;
      data1->VL.clear();
    }
    if(tensor) {
      data1->NbTL = 0;
      data1->TL.clear();
    }
  }
  if(option(4)) {
    if(scalar) {
      data1->NbST = 0;
      data1->ST.clear();
    }
    if(vector) {
      data1->NbVT = 0;
      data1->VT.clear();
    }
    if(tensor) {
      data1->NbTT = 0;
      data1->TT.clear();
    }
  }
  if(option(5)) {
    if(scalar) {
      data1->NbSQ = 0;
      data1->SQ.clear();
    }
    if(vector) {
      data1->NbVQ = 0;
      data1->VQ.clear();
    }
    if(tensor) {
      data1->NbTQ = 0;
      data1->TQ.clear();
    }
  }
  if(option(6)) {
    if(scalar) {
      data1->NbSS = 0;
      data1->SS.clear();
    }
    if(vector) {
      data1->NbVS = 0;
      data1->VS.clear();
    }
    if(tensor) {
      data1->NbTS = 0;
      data1->TS.clear();
    }
  }
  if(option(7)) {
    if(scalar) {
      data1->NbSH = 0;
      data1->SH.clear();
    }
    if(vector) {
      data1->NbVH = 0;
      data1->VH.clear();
    }
    if(tensor) {
      data1->NbTH = 0;
      data1->TH.clear();
    }
  }
  if(option(8)) {
    if(scalar) {
      data1->NbSI = 0;
      data1->SI.clear();
    }
    if(vector) {
      data1->NbVI = 0;
      data1->VI.clear();
    }
    if(tensor) {
      data1->NbTI = 0;
      data1->TI.clear();
    }
  }
  if(option(9)) {
    if(scalar) {
      data1->NbSY = 0;
      data1->SY.clear();
    }
    if(vector) {
      data1->NbVY = 0;
      data1->VY.clear();
    }
    if(tensor) {
      data1->NbTY = 0;
      data1->TY.clear();
    }
  }

  data1->finalize();
  v1->setChanged(true);

  return v1;
}
