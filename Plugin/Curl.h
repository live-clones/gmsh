// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CURL_H_
#define _CURL_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCurlPlugin();
}

class GMSH_CurlPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_CurlPlugin(){}
  std::string getName() const { return "Curl"; }
  std::string getShortHelp() const
  {
    return "Compute the curl of a vector view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
