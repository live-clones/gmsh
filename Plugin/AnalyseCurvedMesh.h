// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _ANALYSECURVEDMESH_H_
#define _ANALYSECURVEDMESH_H_

#include <string>
#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin();
}

class GMSH_AnalyseCurvedMeshPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_AnalyseCurvedMeshPlugin(){}
  std::string getName() const { return "AnalyseCurvedMesh"; }
  std::string getShortHelp() const
  {
    return "Check that the curved mesh isn't wretched";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  PView *execute(PView *);
};

#endif
