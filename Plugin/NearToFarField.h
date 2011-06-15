// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _NEARTOFARFIELD_H_
#define _NEARTOFARFIELD_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterNearToFarFieldPlugin();
}

class GMSH_NearToFarFieldPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_NearToFarFieldPlugin(){}
  std::string getName() const { return "NearToFarField"; }
  std::string getShortHelp() const
  {
    return "Compute Far Field pattern from Near Field on a surface";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
 
  static double getFarField(PViewData *eData, PViewData *hData, double k0, double r_far, double theta, double phi) ;
  static void CartesianToSpherical(int numSteps, double theta, double phi, double **Fc, double **Fsp) ;
    
};

#endif
