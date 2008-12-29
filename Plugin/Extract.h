// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EXTRACT_H_
#define _EXTRACT_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractPlugin();
}

class GMSH_ExtractPlugin : public GMSH_Post_Plugin
{
 public:
  GMSH_ExtractPlugin(){}
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
