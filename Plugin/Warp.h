// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _WARP_H_
#define _WARP_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterWarpPlugin();
}

class GMSH_WarpPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_WarpPlugin(){}
  std::string getName() const { return "Warp"; }
  std::string getShortHelp() const
  {
    return "Deform view using a vector field";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
