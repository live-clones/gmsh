// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CUT_SPHERE_H_
#define _CUT_SPHERE_H_

#include "Levelset.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin();
}

class GMSH_CutSpherePlugin : public GMSH_LevelsetPlugin
{
  double levelset(double x, double y, double z, double val) const;
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
 public:
  GMSH_CutSpherePlugin(){}
  std::string getName() const { return "CutSphere"; }
  std::string getShortHelp() const
  {
    return "Cut with a sphere";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);

  static double callbackX(int, int, double);
  static double callbackY(int, int, double);
  static double callbackZ(int, int, double);
  static double callbackR(int, int, double);
  static double callbackVol(int, int, double);
  static double callbackRecur(int, int, double);
  static void draw(void *context);
};

#endif
