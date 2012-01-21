// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MODULUS_PHASE_H_
#define _MODULUS_PHASE_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterModulusPhasePlugin();
}

class GMSH_ModulusPhasePlugin : public GMSH_PostPlugin
{
 public:
  GMSH_ModulusPhasePlugin(){}
  std::string getName() const { return "ModulusPhase"; }
  std::string getShortHelp() const
  {
    return "Compute modulus/phase of a complex view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
