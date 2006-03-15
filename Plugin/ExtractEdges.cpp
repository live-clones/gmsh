// $Id: ExtractEdges.cpp,v 1.2.2.1 2006-03-15 19:13:55 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "ExtractEdges.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"
#include "BDS.h"

extern Context_T CTX;

StringXNumber ExtractEdgesOptions_Number[] = {
  {GMSH_FULLRC, "Angle", NULL, 22.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractEdgesPlugin()
  {
    return new GMSH_ExtractEdgesPlugin();
  }
}

GMSH_ExtractEdgesPlugin::GMSH_ExtractEdgesPlugin()
{
  ;
}

void GMSH_ExtractEdgesPlugin::getName(char *name) const
{
  strcpy(name, "Extract Edges");
}

void GMSH_ExtractEdgesPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(ExtractEdges) extracts the geometry edges\n"
	 "from the surface view `iView', using `Angle' as\n"
	 "the dihedral angle tolerance. If `iView' < 0, then\n"
	 "plugin is run on the current view.\n"
	 "\n"
	 "Plugin(ExtractEdges) creates one new view.\n");
}

int GMSH_ExtractEdgesPlugin::getNbOptions() const
{
  return sizeof(ExtractEdgesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractEdgesPlugin::getOption(int iopt)
{
  return &ExtractEdgesOptions_Number[iopt];
}

void GMSH_ExtractEdgesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Extract Edges failed...");
}

Post_View *GMSH_ExtractEdgesPlugin::execute(Post_View * v)
{
  int iView = (int)ExtractEdgesOptions_Number[1].def;
  double angle = ExtractEdgesOptions_Number[0].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = BeginView(1);

  BDS_Mesh bds;
  bds.import_view(v1, CTX.lc * 1.e-12);
  bds.classify(angle * M_PI / 180.);
  std::list<BDS_Edge*>::iterator it  = bds.edges.begin();
  std::list<BDS_Edge*>::iterator ite = bds.edges.end();
  while (it != ite){
    BDS_GeomEntity *g = (*it)->g;
    if(g && g->classif_degree == 1) {
      List_Add(v2->SL, &(*it)->p1->X); List_Add(v2->SL, &(*it)->p2->X);
      List_Add(v2->SL, &(*it)->p1->Y); List_Add(v2->SL, &(*it)->p2->Y);
      List_Add(v2->SL, &(*it)->p1->Z); List_Add(v2->SL, &(*it)->p2->Z);
      double val = g->classif_tag;
      List_Add(v2->SL, &val);
      List_Add(v2->SL, &val);
      v2->NbSL++;
    }
    ++it;
  }

  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_ExtractEdges", v1->Name);
  sprintf(filename, "%s_ExtractEdges.pos", v1->Name);
  EndView(v2, 1, filename, name);
  return v2;
}
