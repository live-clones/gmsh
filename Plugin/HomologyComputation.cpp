// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Homology.h"
#include "HomologyComputation.h"

#if defined(HAVE_KBIPACK)

StringXNumber HomologyComputationOptions_Number[] = {
  {GMSH_FULLRC, "ComputeHomology", NULL, 1.},
  {GMSH_FULLRC, "ComputeCohomology", NULL, 0.},
  {GMSH_FULLRC, "HomologyPhysicalGroupsBegin", NULL, -1.},
  {GMSH_FULLRC, "CohomologyPhysicalGroupsBegin", NULL, -1.},
  {GMSH_FULLRC, "CreatePostProcessingViews", NULL, 1.},
  {GMSH_FULLRC, "ReductionOmit", NULL, 1.},
  {GMSH_FULLRC, "ReductionCombine", NULL, 2.},
  {GMSH_FULLRC, "PostProcessSmoothen", NULL, 1.}
};

StringXString HomologyComputationOptions_String[] = {
  {GMSH_FULLRC, "DomainPhysicalGroups", NULL, ""},
  {GMSH_FULLRC, "SubdomainPhysicalGroups", NULL, ""},
  {GMSH_FULLRC, "ReductionImmunePhysicalGroups", NULL, ""},
  {GMSH_FULLRC, "DimensionOfChainsToSave", NULL, "0, 1, 2, 3"},
  {GMSH_FULLRC, "Filename", NULL, "homology.msh"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHomologyComputationPlugin()
  {
    return new GMSH_HomologyComputationPlugin();
  }
}

std::string GMSH_HomologyComputationPlugin::getHelp() const
{
  return "Plugin(HomologyComputation) computes representative chains "
    "of basis elements of (relative) homology and cohomology spaces.\n\n"

    "Define physical groups in order to specify the computation "
    "domain and the relative subdomain. Otherwise the whole mesh "
    "is the domain and the relative subdomain is empty. \n\n"

    "Plugin(HomologyComputation) creates new views, one for each "
    "basis element. The resulting basis chains of desired dimension "
    "together with the mesh are saved to the given file.";
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

bool GMSH_HomologyComputationPlugin::parseStringOpt
(int stringOpt, std::vector<int>& intList)
{
  std::string list = HomologyComputationOptions_String[stringOpt].def;
  intList.clear();

  int n;
  char a;
  std::istringstream ss(list);
  while(ss >> n){
    intList.push_back(n);
    if(ss >> a){
      if(a != ',') {
        Msg::Error("Unexpected character \'%c\' while parsing \'%s\'", a,
                   HomologyComputationOptions_String[stringOpt].str);
        return false;
      }
    }
  }
  return true;
}

PView *GMSH_HomologyComputationPlugin::execute(PView *v)
{
  std::string fileName = HomologyComputationOptions_String[4].def;
  int hom = (int)HomologyComputationOptions_Number[0].def;
  int coh = (int)HomologyComputationOptions_Number[1].def;
  int hompg = (int)HomologyComputationOptions_Number[2].def;
  int cohpg = (int)HomologyComputationOptions_Number[3].def;
  bool pviews = (bool)HomologyComputationOptions_Number[4].def;
  bool omit = (bool)HomologyComputationOptions_Number[5].def;
  int combine = (int)HomologyComputationOptions_Number[6].def;
  bool smoothen = (bool)HomologyComputationOptions_Number[7].def;

  std::vector<int> domain;
  std::vector<int> subdomain;
  std::vector<int> imdomain;
  std::vector<int> dimsave;
  if(!parseStringOpt(0, domain)) return 0;
  if(!parseStringOpt(1, subdomain)) return 0;
  if(!parseStringOpt(2, imdomain)) return 0;
  if(!parseStringOpt(3, dimsave)) return 0;

  GModel* m = GModel::current();

  Homology* homology = new Homology(m, domain, subdomain, imdomain,
                                    true, combine, omit, smoothen);
  homology->setFileName(fileName);

  if(hom != 0) homology->findHomologyBasis(dimsave);
  if(coh != 0) homology->findCohomologyBasis(dimsave);

  for(unsigned int i = 0; i < dimsave.size(); i++) {
    int dim = dimsave.at(i);
    if(dim > -1 && dim < 4 && hom != 0) {
      homology->addChainsToModel(dim, pviews, hompg);
      if(hompg != -1) hompg += homology->betti(dim);
    }
    if(dim > -1 && dim < 4 && coh != 0) {
      homology->addCochainsToModel(dim, pviews, cohpg);
      if(cohpg != -1) cohpg += homology->betti(dim);
    }
  }

  delete homology;

  return 0;
}

#endif
