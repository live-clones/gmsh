// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EXTRACT_EDGES_H_
#define _EXTRACT_EDGES_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractEdgesPlugin();
}

class GMSH_ExtractEdgesPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_ExtractEdgesPlugin(){}
  std::string getName() const { return "ExtractEdges"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
