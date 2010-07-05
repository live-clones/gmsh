// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _NEAREST_NEIGHBOR_H_
#define _NEAREST_NEIGHBOR_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterNearestNeighborPlugin();
}

class GMSH_NearestNeighborPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_NearestNeighborPlugin(){}
  std::string getName() const { return "NearestNeighbor"; }
  std::string getShortHelp() const
  {
    return "Compute distance to the nearest neighbor";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
