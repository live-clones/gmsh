// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "ExtractEdges.h"

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

std::string GMSH_ExtractEdgesPlugin::getHelp() const
{
  return "Plugin(ExtractEdges) extracts the geometry edges\n"
         "from the surface view `iView', using `Angle' as\n"
         "the dihedral angle tolerance. If `iView' < 0, then\n"
         "plugin is run on the current view.\n"
         "\n"
         "Plugin(ExtractEdges) creates one new view.\n";
}

int GMSH_ExtractEdgesPlugin::getNbOptions() const
{
  return sizeof(ExtractEdgesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractEdgesPlugin::getOption(int iopt)
{
  return &ExtractEdgesOptions_Number[iopt];
}

PView *GMSH_ExtractEdgesPlugin::execute(PView *v)
{
  int iView = (int)ExtractEdgesOptions_Number[1].def;
  //double angle = ExtractEdgesOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  //BDS_Mesh bds;
  //bds.import_view(v1, CTX::instance()->lc * 1.e-12);
  //bds.classify(angle * M_PI / 180.);

  Msg::Error("classify(angle, edge_prolongation) must be reinterfaced");

  data2->setName(data1->getName() + "_ExtractEdges");
  data2->setFileName(data1->getName() + "_ExtractEdges.pos");
  data2->finalize();

  return v2;
}
