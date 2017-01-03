// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _CRACK_H_
#define _CRACK_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCrackPlugin();
}

class GMSH_CrackPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_CrackPlugin(){}
  std::string getName() const { return "Crack"; }
  std::string getShortHelp() const
  {
    return "Crack generator";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  PView *execute(PView *);
};

#endif
