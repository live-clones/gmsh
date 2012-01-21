// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SCAL2VEC_H_
#define _SCAL2VEC_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterScal2VecPlugin();
}

class GMSH_Scal2VecPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_Scal2VecPlugin(){}
  std::string getName() const { return "Scal2Vec"; }
  std::string getShortHelp() const
  {
    return "Convert some scalar fields into a vector field";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
