// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _CURVEDBNDDIST_H_
#define _CURVEDBNDDIST_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCurvedBndDistPlugin();
}

class GMSH_CurvedBndDistPlugin : public GMSH_PostPlugin
{
 public :
  GMSH_CurvedBndDistPlugin(){}
  std::string getName() const { return "CurvedBndDist"; }
  std::string getShortHelp() const
  {
    return "Compute distance to curved boundary";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Jonathan Lambrechts"; }
  PView *execute(PView *);
};
#endif
