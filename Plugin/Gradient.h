// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GRADIENT_H_
#define _GRADIENT_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGradientPlugin();
}

class GMSH_GradientPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_GradientPlugin(){}
  std::string getName() const { return "Gradient"; }
  std::string getShortHelp() const
  {
    return "Compute the gradient of a scalar view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
