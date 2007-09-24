// $Id: ExtractEdges.cpp,v 1.7 2007-09-24 08:14:29 geuzaine Exp $
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

#include "ExtractEdges.h"
#include "BDS.h"

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

PView *GMSH_ExtractEdgesPlugin::execute(PView *v)
{
  int iView = (int)ExtractEdgesOptions_Number[1].def;
  //double angle = ExtractEdgesOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  BDS_Mesh bds;
  //bds.import_view(v1, CTX.lc * 1.e-12);
  //bds.classify(angle * M_PI / 180.);

  Msg(GERROR, "BDS->classify(angle, edge_prolongation) must be reinterfaced");

  std::list<BDS_Edge*>::iterator it  = bds.edges.begin();
  std::list<BDS_Edge*>::iterator ite = bds.edges.end();
  while (it != ite){
    BDS_GeomEntity *g = (*it)->g;
    if(g && g->classif_degree == 1) {
      List_Add(data2->SL, &(*it)->p1->X); List_Add(data2->SL, &(*it)->p2->X);
      List_Add(data2->SL, &(*it)->p1->Y); List_Add(data2->SL, &(*it)->p2->Y);
      List_Add(data2->SL, &(*it)->p1->Z); List_Add(data2->SL, &(*it)->p2->Z);
      double val = g->classif_tag;
      List_Add(data2->SL, &val);
      List_Add(data2->SL, &val);
      data2->NbSL++;
    }
    ++it;
  }


  data2->setName(data1->getName() + "_ExtractEdges");
  data2->setFileName(data1->getName() + "_ExtractEdges.pos");
  data2->finalize();

  return v2;
}
