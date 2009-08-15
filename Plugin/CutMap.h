// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CUT_MAP_H_
#define _CUT_MAP_H_

#include "Levelset.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMapPlugin();
}

class GMSH_CutMapPlugin : public GMSH_LevelsetPlugin
{
  double levelset(double x, double y, double z, double val) const;
 public:
  GMSH_CutMapPlugin(){}
  std::string getName() const { return "CutMap"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
  static double callbackA(int, int, double);
  static double callbackVol(int, int, double);
  static double callbackRecur(int, int, double);
  static double callbackTarget(int, int, double);
};

#endif
