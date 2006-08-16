#ifndef _CUT_PARAMETRIC_H_
#define _CUT_PARAMETRIC_H_

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

#include <vector>

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutParametricPlugin ();
}

class GMSH_CutParametricPlugin : public GMSH_Post_Plugin 
{ 
private:
  static double callback(int num, int action, double value, double *opt,
			 double step, double min, double max);
  static char *callbackStr(int num, int action, char *value, char **opt);
  static int fillXYZ();
  static int recompute;
  static std::vector<double> x, y, z;
public:
  GMSH_CutParametricPlugin();
  void getName  (char *name) const;
  void getInfos (char *author, 
  		 char *copyright,
  		 char *help_text) const;
  void catchErrorMessage (char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber *getOption (int iopt);  
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);  
  Post_View *execute (Post_View *);

  static double callbackMinU(int, int, double);
  static double callbackMaxU(int, int, double);
  static double callbackN(int, int, double);
  static double callbackConnect(int, int, double);
  static char *callbackX(int, int, char *);
  static char *callbackY(int, int, char *);
  static char *callbackZ(int, int, char *);
  static void draw();
};

#endif
