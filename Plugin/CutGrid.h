#ifndef _CUT_GRID_H_
#define _CUT_GRID_H_

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

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutGridPlugin ();
}

class GMSH_CutGridPlugin : public GMSH_Post_Plugin
{
  static double callback(int num, int action, double value, double *opt,
			 double step, double min, double max);
  void addInView(PViewDataList *data, int connect, int nbcomp, 
		 double ***pnts, double ***vals, 
		 List_T *P, int *nP, 
		 List_T *L, int *nL, 
		 List_T *Q, int *nQ);
  PView *GenerateView (PView *v, int connectPoints);
public:
  GMSH_CutGridPlugin();
  void getName  (char *name) const;
  void getInfos (char *author, 
  		 char *copyright,
  		 char *help_text) const;
  void catchErrorMessage (char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber *getOption (int iopt);  
  PView *execute (PView *);

  static int getNbU ();
  static int getNbV ();
  static void getPoint(int iU, int iV, double *X );

  static double callbackX0(int, int, double);
  static double callbackY0(int, int, double);
  static double callbackZ0(int, int, double);
  static double callbackX1(int, int, double);
  static double callbackY1(int, int, double);
  static double callbackZ1(int, int, double);
  static double callbackX2(int, int, double);
  static double callbackY2(int, int, double);
  static double callbackZ2(int, int, double);
  static double callbackU(int, int, double);
  static double callbackV(int, int, double);
  static double callbackConnect(int, int, double);
  static void draw();
};

#endif
