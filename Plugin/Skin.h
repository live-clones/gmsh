// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SKIN_H_
#define _SKIN_H_

#include "Plugin.h"
#include "ListUtils.h"
#include "TreeUtils.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSkinPlugin();
}

class GMSH_SkinPlugin : public GMSH_Post_Plugin
{
  typedef struct{
    double coord[12];
    double *val;
  } Elm;
  static List_T *_list;
  static Tree_T *_skin;
  static int *_nbList, _nbNod, _nbComp, _nbTimeStep;
  static int fcmpElm(const void *a, const void *b);
  static void addInView(void *a, void *b);
  void skinList(List_T *inList, int inNbList, 
                int inNbNod, int inNbFac, int fxn[6][4]);
 public:
  GMSH_SkinPlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);
};

#endif
