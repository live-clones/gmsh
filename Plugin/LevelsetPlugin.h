#ifndef _LEVELSETPLUGIN_H_
#define _LEVELSETPLUGIN_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Plugin.h"

#define ORIENT_NONE   0
#define ORIENT_MAP    1
#define ORIENT_PLANE  2
#define ORIENT_SPHERE 3

class GMSH_LevelsetPlugin : public GMSH_Post_Plugin
{
protected:
  int _ith_field_to_draw_on_the_iso;
  int _orientation;
  double _ref[3];
private:
  virtual double levelset     (double x, double y, double z, double val) const = 0;
  virtual double what_to_draw (double x, double y, double z, 
			       int p1, int p2, double coef, double *val) const;
public:
  GMSH_LevelsetPlugin();
  virtual Post_View *execute (Post_View *);
  virtual void Run();
  virtual void Save();
};
#endif
