#ifndef _EVALUATE_H_
#define _EVALUATE_H_

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
#include "OctreePost.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEvaluatePlugin();
}

class GMSH_EvaluatePlugin : public GMSH_Post_Plugin
{
private:
  OctreePost *_octree;
  void evaluate(PView *v1, List_T *list1, int nbElm1,
		PView *v2, List_T *list2, int nbElm2,
		int nbNod, int nbComp, int comp, 
		int timeStep, int timeStep2,
		const char *expression);
public:
  GMSH_EvaluatePlugin();
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
