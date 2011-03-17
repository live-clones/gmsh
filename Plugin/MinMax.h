// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MIN_MAX_H_
#define _MIN_MAX_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMinMaxPlugin();
}

class GMSH_MinMaxPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_MinMaxPlugin(){}
  std::string getName() const { return "MinMax"; }
  std::string getShortHelp() const
  {
    return "Get the min/max of a dataset";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
