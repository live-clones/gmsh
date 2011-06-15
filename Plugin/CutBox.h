// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CUT_BOX_H_
#define _CUT_BOX_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutBoxPlugin ();
}

class GMSH_CutBoxPlugin : public GMSH_PostPlugin
{
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  void addInView(int connect, int boundary, int numsteps, int nbcomp, 
                 double ****pnts, double ****vals, 
                 std::vector<double> &P, int *nP, 
                 std::vector<double> &L, int *nL, 
                 std::vector<double> &Q, int *nQ,
                 std::vector<double> &H, int *nH);
  PView *GenerateView (PView *v, int connectPoints, int boundary);
 public:
  GMSH_CutBoxPlugin(){}
  std::string getName() const { return "CutBox"; }
  std::string getShortHelp() const
  {
    return "Cut with a regular box defined by 4 points";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);

  static int getNbU ();
  static int getNbV ();
  static int getNbW ();
  static void getPoint(int iU, int iV, int iW, double *X );

  static double callbackX0(int, int, double);
  static double callbackY0(int, int, double);
  static double callbackZ0(int, int, double);
  static double callbackX1(int, int, double);
  static double callbackY1(int, int, double);
  static double callbackZ1(int, int, double);
  static double callbackX2(int, int, double);
  static double callbackY2(int, int, double);
  static double callbackZ2(int, int, double);
  static double callbackX3(int, int, double);
  static double callbackY3(int, int, double);
  static double callbackZ3(int, int, double);
  static double callbackU(int, int, double);
  static double callbackV(int, int, double);
  static double callbackW(int, int, double);
  static double callbackConnect(int, int, double);
  static double callbackBoundary(int, int, double);
  static void draw(void *context);
};

#endif
