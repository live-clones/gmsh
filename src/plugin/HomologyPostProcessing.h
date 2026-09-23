// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Matti Pellikka (initial implementation)

#ifndef HOMOLOGY_POST_PROCESSING_H
#define HOMOLOGY_POST_PROCESSING_H

#include <string>
#include "Plugin.h"
#include "Chain.h"

class GMSH_HomologyPostProcessingPlugin : public GMSH_PostPlugin {
public:
  GMSH_HomologyPostProcessingPlugin();
  std::string getName() const { return "HomologyPostProcessing"; }
  std::string getShortHelp() const
  {
    return "Post-process (co)homology space bases";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "M. Pellikka"; }
  PView *execute(PView *);
  bool invertIntegerMatrix(std::vector<int> &matrix);
  int detIntegerMatrix(std::vector<int> &matrix);
};

#endif
