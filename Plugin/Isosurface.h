// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ISOSURFACE_H_
#define _ISOSURFACE_H_

#include "Levelset.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterIsosurfacePlugin();
}

class GMSH_IsosurfacePlugin : public GMSH_LevelsetPlugin
{
  double levelset(double x, double y, double z, double val) const;
 public:
  GMSH_IsosurfacePlugin(){}
  std::string getShortHelp() const
  {
    return "Extract a single isosurface";
  }
  std::string getName() const { return "Isosurface"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
  static double callbackValue(int, int, double);
  static double callbackVol(int, int, double);
  static double callbackRecur(int, int, double);
  static double callbackTarget(int, int, double);
};

#endif
