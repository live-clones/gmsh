// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _HOMOLOGY_POST_PROCESSING_H_
#define _HOMOLOGY_POST_PROCESSING_H_

#include <string>
#include "Plugin.h"
#include "Chain.h"

#if defined(HAVE_KBIPACK)

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHomologyPostProcessingPlugin();
}

class GMSH_HomologyPostProcessingPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_HomologyPostProcessingPlugin(){}
  std::string getName() const { return "HomologyPostProcessing"; }
  std::string getShortHelp() const
  {
    return "Post-process (co)homology space bases";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "M. Pellikka"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
  bool parseStringOpt(int stringOpt, std::vector<int>& intList);
  bool invertIntegerMatrix(std::vector<int>& matrix);
  int detIntegerMatrix(std::vector<int>& matrix);
};

#endif

#endif
