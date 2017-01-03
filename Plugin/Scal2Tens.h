// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _SCAL2TENS_H_
#define _SCAL2TENS_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterScal2TensPlugin();
}

class GMSH_Scal2TensPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_Scal2TensPlugin(){}
  std::string getName() const { return "Scal2Tens"; }
  std::string getShortHelp() const
  {
    return "Convert some scalar fields into a tensor field with several components";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
