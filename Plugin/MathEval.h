// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MATH_EVAL_H_
#define _MATH_EVAL_H_

#include "Plugin.h"
;
extern "C"
{
  GMSH_Plugin *GMSH_RegisterMathEvalPlugin();
}

class GMSH_MathEvalPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_MathEvalPlugin(){}
  std::string getName() const { return "MathEval"; }
  std::string getShortHelp() const
  {
    return "Create a view using mathematical expressions";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);  
  PView *execute(PView *);
};

#endif
