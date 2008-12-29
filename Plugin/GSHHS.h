// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GSHHS_H_
#define _GSHHS_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGSHHSPlugin();
}

class GMSH_GSHHSPlugin:public GMSH_Post_Plugin
{
public:
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *help_text) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  int getNbOptionsStr() const;
  StringXNumber *getOption(int iopt);
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
