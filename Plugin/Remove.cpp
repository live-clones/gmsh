// $Id: Remove.cpp,v 1.8 2006-11-27 22:22:32 geuzaine Exp $
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

#include "Plugin.h"
#include "Remove.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

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
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
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

Post_View *GMSH_RemovePlugin::execute(Post_View * v)
{
  int iView = (int)RemoveOptions_Number[13].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  
  if(v1->AliasOf || v1->Links){
    Msg(GERROR, "Cannot remove data from aliased view");
    return v1;
  }

  int scalar = (int)RemoveOptions_Number[10].def;
  int vector = (int)RemoveOptions_Number[11].def;
  int tensor = (int)RemoveOptions_Number[12].def;

  if(RemoveOptions_Number[0].def){ 
    v1->NbT2 = 0; List_Reset(v1->T2D); List_Reset(v1->T2C); 
  }
  if(RemoveOptions_Number[1].def){ 
    v1->NbT3 = 0; List_Reset(v1->T3D); List_Reset(v1->T3C); 
  }
  if(RemoveOptions_Number[2].def){ 
    if(scalar){ v1->NbSP = 0; List_Reset(v1->SP); }
    if(vector){ v1->NbVP = 0; List_Reset(v1->VP); }
    if(tensor){ v1->NbTP = 0; List_Reset(v1->TP); }
  }
  if(RemoveOptions_Number[3].def){
    if(scalar){ v1->NbSL = 0; List_Reset(v1->SL); }
    if(vector){ v1->NbVL = 0; List_Reset(v1->VL); }
    if(tensor){ v1->NbTL = 0; List_Reset(v1->TL); }
  }
  if(RemoveOptions_Number[4].def){ 
    if(scalar){ v1->NbST = 0; List_Reset(v1->ST); }
    if(vector){ v1->NbVT = 0; List_Reset(v1->VT); }
    if(tensor){ v1->NbTT = 0; List_Reset(v1->TT); }
  }
  if(RemoveOptions_Number[5].def){ 
    if(scalar){ v1->NbSQ = 0; List_Reset(v1->SQ); }
    if(vector){ v1->NbVQ = 0; List_Reset(v1->VQ); }
    if(tensor){ v1->NbTQ = 0; List_Reset(v1->TQ); }
  }
  if(RemoveOptions_Number[6].def){
    if(scalar){ v1->NbSS = 0; List_Reset(v1->SS); }
    if(vector){ v1->NbVS = 0; List_Reset(v1->VS); }
    if(tensor){ v1->NbTS = 0; List_Reset(v1->TS); }
  }
  if(RemoveOptions_Number[7].def){
    if(scalar){ v1->NbSH = 0; List_Reset(v1->SH); }
    if(vector){ v1->NbVH = 0; List_Reset(v1->VH); }
    if(tensor){ v1->NbTH = 0; List_Reset(v1->TH); }
  }
  if(RemoveOptions_Number[8].def){
    if(scalar){ v1->NbSI = 0; List_Reset(v1->SI); }
    if(vector){ v1->NbVI = 0; List_Reset(v1->VI); }
    if(tensor){ v1->NbTI = 0; List_Reset(v1->TI); }
  }
  if(RemoveOptions_Number[9].def){
    if(scalar){ v1->NbSY = 0; List_Reset(v1->SY); }
    if(vector){ v1->NbVY = 0; List_Reset(v1->VY); }
    if(tensor){ v1->NbTY = 0; List_Reset(v1->TY); }
  }
  v1->Changed = 1;

  // recompute min/max, etc.:
  v1->Min = VAL_INF;
  v1->Max = -VAL_INF;
  for(int i = 0; i < 3; i++) {
    v1->BBox[2 * i] = VAL_INF;
    v1->BBox[2 * i + 1] = -VAL_INF;
  }
  EndView(v1, 0, v1->FileName, v1->Name);

  return v1;
}
