// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FIELD_VIEW_H_
#define _FIELD_VIEW_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterFieldViewPlugin();
}

class GMSH_FieldViewPlugin : public GMSH_PostPlugin
{
 public:
  std::string getName() const { return "FieldView"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "J. Lambrechts"; }
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
