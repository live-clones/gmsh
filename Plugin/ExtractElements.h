// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EXTRACT_ELEMENTS_H_
#define _EXTRACT_ELEMENTS_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractElementsPlugin();
}

class GMSH_ExtractElementsPlugin : public GMSH_Post_Plugin
{
 public:
  GMSH_ExtractElementsPlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
