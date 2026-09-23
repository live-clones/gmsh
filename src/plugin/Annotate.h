// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ANNOTATE_H
#define ANNOTATE_H

#include <string>
#include "Plugin.h"

class GMSH_AnnotatePlugin : public GMSH_PostPlugin {
private:
  double getStyle();

public:
  GMSH_AnnotatePlugin();
  std::string getName() const { return "Annotate"; }
  std::string getShortHelp() const { return "Add a text annotation"; }
  std::string getHelp() const;
  PView *execute(PView *);

  bool optionCallback(int iopt, int num, int action, double &value);
  bool optionStrCallback(int iopt, int num, int action, std::string &value);
  void drawPreview(void *context);
};

#endif
