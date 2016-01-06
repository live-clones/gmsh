// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _CVT_REMESH_H_
#define _CVT_REMESH_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCVTRemeshPlugin();
}

class GMSH_CVTRemeshPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_CVTRemeshPlugin(){}
  std::string getName() const { return "CVTRemesh"; }
  std::string getShortHelp() const
  {
    return "Remesh an object using Centroïdal Voronoï Tesslation";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
