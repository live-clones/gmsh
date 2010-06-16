// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include <string>
#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDistancePlugin();
}

class GMSH_DistancePlugin : public GMSH_PostPlugin
{
 public:
  GMSH_DistancePlugin(){}
  std::string getName() const { return "Distance"; }
  std::string getShortHelp() const
  {
    return "Compute distance to boundaries";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "E. Marchandise"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
