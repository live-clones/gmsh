// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PARTICLES_H_
#define _PARTICLES_H

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterParticlesPlugin ();
}

class GMSH_ParticlesPlugin : public GMSH_PostPlugin
{
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
 public:
  GMSH_ParticlesPlugin(){}
  std::string getName() const { return "Particles"; }
  std::string getShortHelp() const
  {
    return "Compute particle trajectories in force field";
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
  static void draw(void *context);
};

#endif
