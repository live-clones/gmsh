// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ANALYSECURVEDMESH_H_
#define _ANALYSECURVEDMESH_H_

#include "Plugin.h"
#include "MElement.h"
#include <vector>

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
  int getNbOptions() const;
  StringXNumber *getOption(int);  
  PView *execute(PView *);
  bool isJacPositive(MElement *);
  int method_1_1(MElement *, int depth);
  int method_1_2(MElement *, int depth);
  int method_1_3(MElement *, int depth);
  void method_2_2(MElement *const *, std::vector<int> &tags, int depth);
  void method_2_3(MElement *const *, std::vector<int> &tags, int depth);
  //int checkJacobian(MElement *, int depth);
  //int *checkJacobian2(MElement *const *, int numEl, int depth);
  int *checkJacobian(MElement *const *, int numEl, int depth, int method);
  int division(const bezierBasis *, const fullVector<double> &, int depth);
};

#endif
