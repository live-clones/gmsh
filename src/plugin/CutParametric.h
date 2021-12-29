// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_PARAMETRIC_H
#define CUT_PARAMETRIC_H

#include <string>
#include <vector>
#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterCutParametricPlugin();
}

class GMSH_CutParametricPlugin : public GMSH_PostPlugin {
private:
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  static std::string callbackStr(int num, int action, const std::string &value,
                                 std::string &opt);
  static int fillXYZ();
  static int recompute;
  static std::vector<double> x, y, z;

public:
  GMSH_CutParametricPlugin() {}
  std::string getName() const { return "CutParametric"; }
  std::string getShortHelp() const
  {
    return "Cut with the parametric curve (X(u,v), Y(u,v), Z(u,v))";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);

  static double callbackMinU(int, int, double);
  static double callbackMaxU(int, int, double);
  static double callbackNU(int, int, double);
  static double callbackMinV(int, int, double);
  static double callbackMaxV(int, int, double);
  static double callbackNV(int, int, double);
  static double callbackConnect(int, int, double);
  static std::string callbackX(int, int, const std::string &);
  static std::string callbackY(int, int, const std::string &);
  static std::string callbackZ(int, int, const std::string &);
  static void draw(void *context);
};

#endif
