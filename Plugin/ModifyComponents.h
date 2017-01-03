// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MODIFY_COMPONENT_H_
#define _MODIFY_COMPONENT_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterModifyComponentsPlugin();
}

class GMSH_ModifyComponentsPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_ModifyComponentsPlugin(){}
  std::string getName() const { return "ModifyComponents"; }
  std::string getShortHelp() const
  {
    return "Modify components in a view using mathematical expressions";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
