// $Id: Remove.cpp,v 1.11 2007-09-11 14:01:55 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterRemovePlugin()
  {
    return new GMSH_RemovePlugin();
  }
}

GMSH_RemovePlugin::GMSH_RemovePlugin()
{
  ;
}

void GMSH_RemovePlugin::getName(char *name) const
{
  strcpy(name, "Remove");
}

void GMSH_RemovePlugin::getInfos(char *author, char *copyright,
				   char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Remove) removes the marked items\n"
	 "from the view `iView'. If `iView' < 0, the plugin\n"
	 "is run on the current view.\n"
	 "\n"
	 "Plugin(Remove) is executed in-place.\n");
}

int GMSH_RemovePlugin::getNbOptions() const
{
  return sizeof(RemoveOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_RemovePlugin::getOption(int iopt)
{
  return &RemoveOptions_Number[iopt];
}

void GMSH_RemovePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Remove failed...");
}

PView *GMSH_RemovePlugin::execute(PView *v)
{
  int iView = (int)RemoveOptions_Number[13].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;
  
  if(v1->getAliasOf() || v1->getLinks()){
    Msg(GERROR, "Cannot remove data from aliased view");
    return v1;
  }

  int scalar = (int)RemoveOptions_Number[10].def;
  int vector = (int)RemoveOptions_Number[11].def;
  int tensor = (int)RemoveOptions_Number[12].def;

  if(RemoveOptions_Number[0].def){ 
    data1->NbT2 = 0; List_Reset(data1->T2D); List_Reset(data1->T2C); 
  }
  if(RemoveOptions_Number[1].def){ 
    data1->NbT3 = 0; List_Reset(data1->T3D); List_Reset(data1->T3C); 
  }
  if(RemoveOptions_Number[2].def){ 
    if(scalar){ data1->NbSP = 0; List_Reset(data1->SP); }
    if(vector){ data1->NbVP = 0; List_Reset(data1->VP); }
    if(tensor){ data1->NbTP = 0; List_Reset(data1->TP); }
  }
  if(RemoveOptions_Number[3].def){
    if(scalar){ data1->NbSL = 0; List_Reset(data1->SL); }
    if(vector){ data1->NbVL = 0; List_Reset(data1->VL); }
    if(tensor){ data1->NbTL = 0; List_Reset(data1->TL); }
  }
  if(RemoveOptions_Number[4].def){ 
    if(scalar){ data1->NbST = 0; List_Reset(data1->ST); }
    if(vector){ data1->NbVT = 0; List_Reset(data1->VT); }
    if(tensor){ data1->NbTT = 0; List_Reset(data1->TT); }
  }
  if(RemoveOptions_Number[5].def){ 
    if(scalar){ data1->NbSQ = 0; List_Reset(data1->SQ); }
    if(vector){ data1->NbVQ = 0; List_Reset(data1->VQ); }
    if(tensor){ data1->NbTQ = 0; List_Reset(data1->TQ); }
  }
  if(RemoveOptions_Number[6].def){
    if(scalar){ data1->NbSS = 0; List_Reset(data1->SS); }
    if(vector){ data1->NbVS = 0; List_Reset(data1->VS); }
    if(tensor){ data1->NbTS = 0; List_Reset(data1->TS); }
  }
  if(RemoveOptions_Number[7].def){
    if(scalar){ data1->NbSH = 0; List_Reset(data1->SH); }
    if(vector){ data1->NbVH = 0; List_Reset(data1->VH); }
    if(tensor){ data1->NbTH = 0; List_Reset(data1->TH); }
  }
  if(RemoveOptions_Number[8].def){
    if(scalar){ data1->NbSI = 0; List_Reset(data1->SI); }
    if(vector){ data1->NbVI = 0; List_Reset(data1->VI); }
    if(tensor){ data1->NbTI = 0; List_Reset(data1->TI); }
  }
  if(RemoveOptions_Number[9].def){
    if(scalar){ data1->NbSY = 0; List_Reset(data1->SY); }
    if(vector){ data1->NbVY = 0; List_Reset(data1->VY); }
    if(tensor){ data1->NbTY = 0; List_Reset(data1->TY); }
  }

  data1->finalize();
  v1->setChanged(true);

  return v1;
}
