// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CUT_PARAMETRIC_H_
#define _CUT_PARAMETRIC_H_

#include <string>
#include <vector>
#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutParametricPlugin ();
}

class GMSH_CutParametricPlugin : public GMSH_PostPlugin 
{ 
 private:
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  static std::string callbackStr(int num, int action, std::string value, 
                                 std::string &opt);
  static int fillXYZ();
  static int recompute;
  static std::vector<double> x, y, z;
 public:
  GMSH_CutParametricPlugin(){}
  std::string getName() const { return "CutParametric"; }
  std::string getShortHelp() const
  {
    return "Cut with the parametric curve (X(u), Y(u), Z(u))";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);  
  PView *execute(PView *);

  static double callbackMinU(int, int, double);
  static double callbackMaxU(int, int, double);
  static double callbackN(int, int, double);
  static double callbackConnect(int, int, double);
  static std::string callbackX(int, int, std::string);
  static std::string callbackY(int, int, std::string);
  static std::string callbackZ(int, int, std::string);
  static void draw(void *context);
};

#endif
