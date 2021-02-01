// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@microsoft.com>.

#ifndef HOMOLOGY_POST_PROCESSING_H
#define HOMOLOGY_POST_PROCESSING_H

#include <string>
#include "Plugin.h"
#include "Chain.h"

#if defined(HAVE_KBIPACK)

extern "C" {
GMSH_Plugin *GMSH_RegisterHomologyPostProcessingPlugin();
}

class GMSH_HomologyPostProcessingPlugin : public GMSH_PostPlugin {
public:
  GMSH_HomologyPostProcessingPlugin() {}
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
  bool parseStringOpt(int stringOpt, std::vector<int> &intList);
  bool invertIntegerMatrix(std::vector<int> &matrix);
  int detIntegerMatrix(std::vector<int> &matrix);
};

#endif

#endif
