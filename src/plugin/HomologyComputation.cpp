// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Matti Pellikka (initial implementation)

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Homology.h"
#include "HomologyComputation.h"
#include "Context.h"

GMSH_HomologyComputationPlugin::GMSH_HomologyComputationPlugin()
  : GMSH_PostPlugin(
      {{GMSH_FULLRC, "ComputeHomology", nullptr, 1.},
       {GMSH_FULLRC, "ComputeCohomology", nullptr, 0.},
       {GMSH_FULLRC, "HomologyPhysicalGroupsBegin", nullptr, -1.},
       {GMSH_FULLRC, "CohomologyPhysicalGroupsBegin", nullptr, -1.},
       {GMSH_FULLRC, "CreatePostProcessingViews", nullptr, 1.},
       {GMSH_FULLRC, "ReductionOmit", nullptr, 1.},
       {GMSH_FULLRC, "ReductionCombine", nullptr, 3.},
       {GMSH_FULLRC, "PostProcessSimplify", nullptr, 1.},
       {GMSH_FULLRC, "ReductionHeuristic", nullptr, 1.},
       {GMSH_FULLRC, "PeriodicIdentification", nullptr, 0.},
       {GMSH_FULLRC, "PeriodicSlavePhysicalGroup", nullptr, -1.},
       {GMSH_FULLRC, "PeriodicMasterPhysicalGroup", nullptr, -1.}},
      {{GMSH_FULLRC, "DomainPhysicalGroups", nullptr, ""},
       {GMSH_FULLRC, "SubdomainPhysicalGroups", nullptr, ""},
       {GMSH_FULLRC, "ReductionImmunePhysicalGroups", nullptr, ""},
       {GMSH_FULLRC, "DimensionOfChainsToSave", nullptr, "0, 1, 2, 3"},
       {GMSH_FULLRC, "Filename", nullptr, ""}})
{
}

std::string GMSH_HomologyComputationPlugin::getHelp() const
{
  return "Plugin(HomologyComputation) computes representative chains "
         "of basis elements of (relative) homology and cohomology spaces.\n\n"

         "Define physical groups in order to specify the computation "
         "domain and the relative subdomain. Otherwise the whole mesh "
         "is the domain and the relative subdomain is empty. \n\n"

         "Plugin(HomologyComputation) creates new views, one for each "
         "basis element. If `Filename' is provided, the plugin saves the "
         "resulting basis chains of desired dimension along with the "
         "mesh.";
}

bool GMSH_HomologyComputationPlugin::parseStringOpt(int stringOpt,
                                                    std::vector<int> &intList)
{
  std::string list = optionStr(stringOpt);
  intList.clear();

  int n;
  char a;
  std::istringstream ss(list);
  while(ss >> n) {
    intList.push_back(n);
    if(ss >> a) {
      if(a != ',') {
        Msg::Error("Unexpected character \'%c\' while parsing \'%s\'", a,
                   getOptionStr(stringOpt)->str);
        return false;
      }
    }
  }
  return true;
}

PView *GMSH_HomologyComputationPlugin::execute(PView *v)
{
  std::string fileName = optionStr(4);
  int hom = (int)option(0);
  int coh = (int)option(1);
  int hompg = (int)option(2);
  int cohpg = (int)option(3);
  bool pviews = (bool)option(4);
  bool omit = (bool)option(5);
  int combine = (int)option(6);
  bool smoothen = (bool)option(7);
  int heuristic = (int)option(8);
  bool periodic = (bool)option(9);
  int perslave = (int)option(10);
  int permaster = (int)option(11);

  std::vector<int> domain;
  std::vector<int> subdomain;
  std::vector<int> imdomain;
  std::vector<int> dimsave;
  if(!parseStringOpt(0, domain)) return nullptr;
  if(!parseStringOpt(1, subdomain)) return nullptr;
  if(!parseStringOpt(2, imdomain)) return nullptr;
  if(!parseStringOpt(3, dimsave)) return nullptr;

  // a negative physical group means no restriction on that side
  std::vector<int> perslaves;
  std::vector<int> permasters;
  if(perslave > 0) perslaves.push_back(perslave);
  if(permaster > 0) permasters.push_back(permaster);

  GModel *m = GModel::current();

  Homology *homology = new Homology(m, domain, subdomain, imdomain, true,
                                    combine, omit, smoothen, heuristic);
  homology->setPeriodic(periodic, perslaves, permasters);

  if(hom != 0) homology->findHomologyBasis(dimsave);
  if(coh != 0) homology->findCohomologyBasis(dimsave);

  for(std::size_t i = 0; i < dimsave.size(); i++) {
    int dim = dimsave.at(i);
    if(dim > -1 && dim < 4 && hom != 0) {
      homology->addChainsToModel(dim, pviews, hompg);
      if(hompg != -1) hompg += homology->betti(dim);
    }
  }
  for(std::size_t i = 0; i < dimsave.size(); i++) {
    int dim = dimsave.at(i);
    if(dim > -1 && dim < 4 && coh != 0) {
      homology->addCochainsToModel(dim, pviews, cohpg);
      if(cohpg != -1) cohpg += homology->betti(dim);
    }
  }

  // as GModel::computeHomology(), and write the file once the chains are in
  // the model
  m->pruneMeshVertexAssociations();
  if(fileName.size()) {
    homology->setFileName(fileName);
    homology->writeBasisMSH();
  }
  delete homology;
  CTX::instance()->meshChanged();

  return nullptr;
}
