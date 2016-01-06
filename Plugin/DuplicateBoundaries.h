// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DUPLICATEBOUNDARIES_H_
#define _DUPLICATEBOUNDARIES_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDuplicateBoundariesPlugin();
}

class GMSH_DuplicateBoundariesPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_DuplicateBoundariesPlugin(){}
  std::string getName() const { return "DuplicateBoundaries"; }
  std::string getShortHelp() const
  {
    return "Duplicate Boundaries";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  double abs(double x);
  PView *execute(PView *);
  PView *execute2D(PView *);
  PView *execute2DWithBound(PView *);
  PView *executeDuplicate(PView *);
  PView *executeBis(PView *);
  PView *executeTer(PView *);
  PView *executeFourth(PView *);
  PView *ComputeBestSeeds(PView *);
};

#endif
