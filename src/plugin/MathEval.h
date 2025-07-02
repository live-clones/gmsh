// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MATH_EVAL_H
#define MATH_EVAL_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterMathEvalPlugin();
}

class GMSH_MathEvalPlugin : public GMSH_PostPlugin {
public:
  GMSH_MathEvalPlugin() {}
  std::string getName() const { return "MathEval"; }
  std::string getShortHelp() const
  {
    return "Create a view using mathematical expressions";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
