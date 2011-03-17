// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _HARMONIC_TO_TIME_H_
#define _HARMONIC_TO_TIME_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHarmonicToTimePlugin();
}

class GMSH_HarmonicToTimePlugin : public GMSH_PostPlugin
{
 public:
  GMSH_HarmonicToTimePlugin(){}
  std::string getName() const { return "HarmonicToTime"; }
  std::string getShortHelp() const
  {
    return "Transform harmonic data into time domain";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
