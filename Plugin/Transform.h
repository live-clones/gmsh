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
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *help_text) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
