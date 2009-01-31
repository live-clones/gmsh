// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EVALUATE_H_
#define _EVALUATE_H_

#include "Plugin.h"
#include "OctreePost.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEvaluatePlugin();
}

class GMSH_EvaluatePlugin : public GMSH_PostPlugin
{
private:
  OctreePost *_octree;
  void evaluate(PView *v1, List_T *list1, int nbElm1,
                PView *v2, List_T *list2, int nbElm2,
                int nbNod, int nbComp, int comp, 
                int timeStep, int timeStep2,
                const char *expression);
public:
  GMSH_EvaluatePlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);  
  PView *execute(PView *);
};

#endif
