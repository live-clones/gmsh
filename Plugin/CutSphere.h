#ifndef _CUT_SPHERE_H_
#define _CUT_SPHERE_H_

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

#include "Levelset.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin();
}

class GMSH_CutSpherePlugin : public GMSH_LevelsetPlugin
{
  double levelset(double x, double y, double z, double val) const;
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
public:
  GMSH_CutSpherePlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);

  static double callbackX(int, int, double);
  static double callbackY(int, int, double);
  static double callbackZ(int, int, double);
  static double callbackR(int, int, double);
  static double callbackVol(int, int, double);
  static double callbackRecur(int, int, double);
  static void draw();
};

#endif
