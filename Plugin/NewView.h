// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _NEWVIEW_H_
#define _NEWVIEW_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterNewViewPlugin();
}

class GMSH_NewViewPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_NewViewPlugin(){}
  std::string getName() const { return "NewView"; }
  std::string getShortHelp() const
  {
    return "Create an empty New View from a mesh";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
