#ifndef _DECOMPOSE_IN_SIMPLEX_H_
#define _DECOMPOSE_IN_SIMPLEX_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDecomposeInSimplexPlugin();
}

class GMSH_DecomposeInSimplexPlugin : public GMSH_Post_Plugin
{
public:
  GMSH_DecomposeInSimplexPlugin();
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *help_text) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  Post_View *execute(Post_View *);
};

class DecomposeInSimplex{
 private:
  // how many nodes in the element to decompose
  int _numNodes;
  // how many field components
  int _numComponents;
  // how many time steps
  int _numTimeSteps;
  // create a simplex
  void reorder(int map[4], int n,
	       double *x, double *y, double *z, double *val,
	       double *xn, double *yn, double *zn, double *valn);
 public:
  // default constructor
  DecomposeInSimplex(int numNodes, int numComponents, int numTimeSteps=1);
  // the number of simplices into which the element is decomposed
  int numSimplices();
  // the number of nodes of the simplex
  int numSimplexNodes();
  // returns the i-th simplex in the decomposition
  void decompose(int num, 
		 double *x, double *y, double *z, double *val,
		 double *xn, double *yn, double *zn, double *valn);
};

#endif
