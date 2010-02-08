// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DIVERGENCE_H_
#define _DIVERGENCE_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDivergencePlugin();
}

class GMSH_DivergencePlugin : public GMSH_PostPlugin
{
 public:
  GMSH_DivergencePlugin(){}
  std::string getName() const { return "Divergence"; }
  std::string getShortHelp() const 
  { 
    return "Compute the divergence of a vector view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
