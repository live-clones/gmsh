// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Matti Pellikka <matti.pellikka@microsoft.com>.

#ifndef _HOMOLOGY_COMPUTATION_H_
#define _HOMOLOGY_COMPUTATION_H_

#include <string>
#include "Plugin.h"

#if defined(HAVE_KBIPACK)

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHomologyComputationPlugin();
}

class GMSH_HomologyComputationPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_HomologyComputationPlugin(){}
  std::string getName() const { return "HomologyComputation"; }
  std::string getShortHelp() const
  {
    return "Compute relative (co)homology spaces";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "M. Pellikka"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
  bool parseStringOpt(int stringOpt, std::vector<int>& intList);
};

#endif

#endif
