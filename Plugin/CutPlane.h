// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_PLANE_H
#define CUT_PLANE_H

#include "Levelset.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterCutPlanePlugin();
}

class GMSH_CutPlanePlugin : public GMSH_LevelsetPlugin {
  double levelset(double x, double y, double z, double val) const;
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  static int iview;

public:
  GMSH_CutPlanePlugin() {}
  std::string getName() const { return "CutPlane"; }
  std::string getShortHelp() const
  {
    return "Cut with the plane A*X + B*Y + C*Z + D = 0";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
  virtual bool geometricalFilter(fullMatrix<double> *) const;

  static double callbackA(int, int, double);
  static double callbackB(int, int, double);
  static double callbackC(int, int, double);
  static double callbackD(int, int, double);
  static double callbackVol(int, int, double);
  static double callbackRecur(int, int, double);
  static double callbackTarget(int, int, double);
  static void draw(void *context);
};

#endif
