// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _REMOVE_H_
#define _REMOVE_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterRemovePlugin();
}

class GMSH_RemovePlugin : public GMSH_PostPlugin
{
 public:
  GMSH_RemovePlugin(){}
  std::string getName() const { return "Remove"; }
  std::string getShortHelp() const
  {
    return "Remove selected data from a view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
