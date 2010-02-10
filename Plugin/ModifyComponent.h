// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MODIFY_COMPONENT_H_
#define _MODIFY_COMPONENT_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterModifyComponentPlugin();
}

class GMSH_ModifyComponentPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_ModifyComponentPlugin(){}
  std::string getName() const { return "ModifyComponent"; }
  std::string getShortHelp() const
  {
    return "Modify a component using a mathematical expression";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);  
  PView *execute(PView *);
};

#endif
