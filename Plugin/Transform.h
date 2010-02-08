// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin();
}

class GMSH_TransformPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_TransformPlugin(){}
  std::string getName() const { return "Transform"; }
  std::string getShortHelp() const
  {
    return "Apply simple geometrical transformation";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
