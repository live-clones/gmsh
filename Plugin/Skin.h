// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SKIN_H_
#define _SKIN_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSkinPlugin();
}

class GMSH_SkinPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_SkinPlugin(){}
  std::string getName() const { return "Skin"; }
  std::string getShortHelp() const
  {
    return "Extract boundary of a view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
