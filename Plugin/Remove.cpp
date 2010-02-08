// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Remove.h"

StringXNumber RemoveOptions_Number[] = {
  {GMSH_FULLRC, "Text2D", NULL, 1.},
  {GMSH_FULLRC, "Text3D", NULL, 1.},
  {GMSH_FULLRC, "Points", NULL, 0.},
  {GMSH_FULLRC, "Lines", NULL, 0.},
  {GMSH_FULLRC, "Triangles", NULL, 0.},
  {GMSH_FULLRC, "Quadrangles", NULL, 0.},
  {GMSH_FULLRC, "Tetrahedra", NULL, 0.},
  {GMSH_FULLRC, "Hexahedra", NULL, 0.},
  {GMSH_FULLRC, "Prisms", NULL, 0.},
  {GMSH_FULLRC, "Pyramids", NULL, 0.},
  {GMSH_FULLRC, "Scalar", NULL, 1.},
  {GMSH_FULLRC, "Vector", NULL, 1.},
  {GMSH_FULLRC, "Tensor", NULL, 1.},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterRemovePlugin()
  {
    return new GMSH_RemovePlugin();
  }
}

std::string GMSH_RemovePlugin::getHelp() const
{
  return "Plugin(Remove) removes the marked items\n"
    "from the view `View'.\n"
    "\n"
    "If `View' < 0, the plugin is run on the current view.\n"
    "\n"
    "Plugin(Remove) is executed in-place.\n";
}

int GMSH_RemovePlugin::getNbOptions() const
{
  return sizeof(RemoveOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_RemovePlugin::getOption(int iopt)
{
  return &RemoveOptions_Number[iopt];
}

PView *GMSH_RemovePlugin::execute(PView *v)
{
  int iView = (int)RemoveOptions_Number[13].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;
  
  int scalar = (int)RemoveOptions_Number[10].def;
  int vector = (int)RemoveOptions_Number[11].def;
  int tensor = (int)RemoveOptions_Number[12].def;

  if(RemoveOptions_Number[0].def){ 
    data1->NbT2 = 0; data1->T2D.clear(); data1->T2C.clear(); 
  }
  if(RemoveOptions_Number[1].def){ 
    data1->NbT3 = 0; data1->T3D.clear(); data1->T3C.clear(); 
  }
  if(RemoveOptions_Number[2].def){ 
    if(scalar){ data1->NbSP = 0; data1->SP.clear(); }
    if(vector){ data1->NbVP = 0; data1->VP.clear(); }
    if(tensor){ data1->NbTP = 0; data1->TP.clear(); }
  }
  if(RemoveOptions_Number[3].def){
    if(scalar){ data1->NbSL = 0; data1->SL.clear(); }
    if(vector){ data1->NbVL = 0; data1->VL.clear(); }
    if(tensor){ data1->NbTL = 0; data1->TL.clear(); }
  }
  if(RemoveOptions_Number[4].def){ 
    if(scalar){ data1->NbST = 0; data1->ST.clear(); }
    if(vector){ data1->NbVT = 0; data1->VT.clear(); }
    if(tensor){ data1->NbTT = 0; data1->TT.clear(); }
  }
  if(RemoveOptions_Number[5].def){ 
    if(scalar){ data1->NbSQ = 0; data1->SQ.clear(); }
    if(vector){ data1->NbVQ = 0; data1->VQ.clear(); }
    if(tensor){ data1->NbTQ = 0; data1->TQ.clear(); }
  }
  if(RemoveOptions_Number[6].def){
    if(scalar){ data1->NbSS = 0; data1->SS.clear(); }
    if(vector){ data1->NbVS = 0; data1->VS.clear(); }
    if(tensor){ data1->NbTS = 0; data1->TS.clear(); }
  }
  if(RemoveOptions_Number[7].def){
    if(scalar){ data1->NbSH = 0; data1->SH.clear(); }
    if(vector){ data1->NbVH = 0; data1->VH.clear(); }
    if(tensor){ data1->NbTH = 0; data1->TH.clear(); }
  }
  if(RemoveOptions_Number[8].def){
    if(scalar){ data1->NbSI = 0; data1->SI.clear(); }
    if(vector){ data1->NbVI = 0; data1->VI.clear(); }
    if(tensor){ data1->NbTI = 0; data1->TI.clear(); }
  }
  if(RemoveOptions_Number[9].def){
    if(scalar){ data1->NbSY = 0; data1->SY.clear(); }
    if(vector){ data1->NbVY = 0; data1->VY.clear(); }
    if(tensor){ data1->NbTY = 0; data1->TY.clear(); }
  }

  data1->finalize();
  v1->setChanged(true);

  return v1;
}
