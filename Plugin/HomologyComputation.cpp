// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka

#include <stdlib.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "CellComplex.h"
#include "HomologyComputation.h"


StringXNumber HomologyComputationOptions_Number[] = {
  {GMSH_FULLRC, "test number", NULL, 1.},
};

StringXString HomologyComputationOptions_String[] = {
  {GMSH_FULLRC, "test string", NULL, "test string"},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHomologyComputationPlugin()
  {
    return new GMSH_HomologyComputationPlugin();
  }
}

void GMSH_HomologyComputationPlugin::getName(char *name) const
{
  strcpy(name, "Homology Computation");
}

void GMSH_HomologyComputationPlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "Matti Pellikka");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(HomologyComputation) is here!\n"
         "\n"
         "Plugin(HomologyComputation) creates a new view.\n");
}

int GMSH_HomologyComputationPlugin::getNbOptions() const
{
  return sizeof(HomologyComputationOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HomologyComputationPlugin::getOption(int iopt)
{
  return &HomologyComputationOptions_Number[iopt];
}

int GMSH_HomologyComputationPlugin::getNbOptionsStr() const
{
  return sizeof(HomologyComputationOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_HomologyComputationPlugin::getOptionStr(int iopt)
{
  return &HomologyComputationOptions_String[iopt];
}

void GMSH_HomologyComputationPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Homology Computation failed...");
}


PView *GMSH_HomologyComputationPlugin::execute(PView *v)
{
  std::string testString = HomologyComputationOptions_String[0].def;
  int testInt = (int)HomologyComputationOptions_Number[0].def;

  GModel *m = GModel::current();
  std::map<int, std::vector<GEntity*> > groups[4];
  m->getPhysicalGroups(groups);

  std::map<int, std::vector<double> > data;

  std::vector<GEntity*> domain;
  std::vector<GEntity*> subdomain;

  // Here's the problem, linker cannot find the method for the constructor of 
  // CellComplex class, or any other methods coded in Geo/CellComplex.cpp
  
  //CellComplex* testComplex = new CellComplex(domain, subdomain);
  
  // insert homology fun here
  
  PView *pv = new PView("homology", "ElementData", m, data, 0.);
  
  Msg::Error("test.");
  
  return 0;
}
