// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EVALUATE_H_
#define _EVALUATE_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEvaluatePlugin();
}

class GMSH_EvaluatePlugin : public GMSH_PostPlugin
{
public:
  GMSH_EvaluatePlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);  
  PView *execute(PView *);
};

#endif
