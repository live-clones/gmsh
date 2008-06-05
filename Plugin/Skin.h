#ifndef _SKIN_H_
#define _SKIN_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Plugin.h"
#include "gmshList.h"
#include "Tree.h"

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
