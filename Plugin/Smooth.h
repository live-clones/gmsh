// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SMOOTH_H_
#define _SMOOTH_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSmoothPlugin();
}

class GMSH_SmoothPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_SmoothPlugin(){}
  std::string getName() const { return "Smooth"; }
  std::string getShortHelp() const
  {
    return "Apply nodal smoothing";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
