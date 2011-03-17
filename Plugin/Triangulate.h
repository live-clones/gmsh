// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _TRIANGULATE_H_
#define _TRIANGULATE_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTriangulatePlugin();
}

class GMSH_TriangulatePlugin : public GMSH_PostPlugin
{
 public:
  GMSH_TriangulatePlugin(){}
  std::string getName() const { return "Triangulate"; }
  std::string getShortHelp() const
  {
    return "Mesh 2D point cloud";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

#endif
