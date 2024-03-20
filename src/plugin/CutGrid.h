// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_GRID_H
#define CUT_GRID_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterCutGridPlugin();
}

class GMSH_CutGridPlugin : public GMSH_PostPlugin {
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  void addInView(int numsteps, int connect, int nbcomp, double ***pnts,
                 double ***vals, std::vector<double> &P, int *nP,
                 std::vector<double> &L, int *nL, std::vector<double> &Q,
                 int *nQ);
  PView *GenerateView(PView *v, int connectPoints);

public:
  GMSH_CutGridPlugin() {}
  std::string getName() const { return "CutGrid"; }
  std::string getShortHelp() const
  {
    return "Cut with a regular grid defined by 3 points";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);

  static int getNbU();
  static int getNbV();
  static void getPoint(int iU, int iV, double *X);

  static double callbackX0(int, int, double);
  static double callbackY0(int, int, double);
  static double callbackZ0(int, int, double);
  static double callbackX1(int, int, double);
  static double callbackY1(int, int, double);
  static double callbackZ1(int, int, double);
  static double callbackX2(int, int, double);
  static double callbackY2(int, int, double);
  static double callbackZ2(int, int, double);
  static double callbackU(int, int, double);
  static double callbackV(int, int, double);
  static double callbackConnect(int, int, double);
  static void draw(void *context);
};

#endif
