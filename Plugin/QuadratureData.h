// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _QUADRATURE_POINT_DATA_H_
#define _QUADRATURE_POINT_DATA_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterQuadratureDataPlugin();
}


class GMSH_QuadratureDataPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_QuadratureDataPlugin(){}
  std::string getName() const { return "QuadratureData"; }
  std::string getShortHelp() const
  {
    return "Quadrature point data";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
