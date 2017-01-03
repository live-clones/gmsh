// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GAUSS_POINTS_H_
#define _GAUSS_POINTS_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGaussPointsPlugin();
}


class GMSH_GaussPointsPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_GaussPointsPlugin(){}
  std::string getName() const { return "GaussPoints"; }
  std::string getShortHelp() const
  {
    return "Gauss points";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  PView *execute(PView *);
};

#endif
