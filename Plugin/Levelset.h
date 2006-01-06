#ifndef _LEVELSET_H_
#define _LEVELSET_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include <vector>
using namespace std;

class GMSH_LevelsetPlugin : public GMSH_Post_Plugin
{
public:
  typedef enum {NONE, PLANE, SPHERE, MAP} ORIENTATION ;
  virtual double levelset(double x, double y, double z, double val) const = 0;
protected:
  double _ref[3], _targetError;
  int _valueTimeStep, _valueView, _valueIndependent, _recurLevel, _extractVolume;  
  ORIENTATION _orientation;
private:
  double _invert;
  void addElement(int timeStep, int np, int nbEdg, int dNbComp,
		  double xp[12], double yp[12], double zp[12],
		  double valp[12][9], vector<Post_View *> out);
  void evalLevelset(int nbNod, int nbComp,
		    double *x, double *y, double *z, double *val,
		    double *levels, double *scalarVal);
  void nonZeroLevelset(int timeStep, int nbVert, int nbEdg, int exn[12][2],
		       double *x, double *y, double *z, 
		       double *iVal, int iNbComp, double *dVal, int dNbComp,
		       vector<Post_View*> out);
  int zeroLevelset(int timeStep, int nbVert, int nbEdg, int exn[12][2],
		   double *x, double *y, double *z, 
		   double *iVal, int iNbComp, double *dVal, int dNbComp,
		   vector<Post_View*> out);
  void executeList(Post_View * iView, List_T * iList, 
		   int iNbElm, int iNbComp,
		   Post_View * dView, List_T * dList, 
		   int dNbElm, int dNbComp,
		   int nbVert, int nbEdg, int exn[12][2], 
		   vector<Post_View *> out);
  virtual void assign_specific_visibility () const;
public:
  GMSH_LevelsetPlugin();
  virtual Post_View *execute(Post_View *);
};

#endif
