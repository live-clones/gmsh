#ifndef _ANNOTATE_H_
#define _ANNOTATE_H_

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
  GMSH_Plugin *GMSH_RegisterAnnotatePlugin();
}

class GMSH_AnnotatePlugin : public GMSH_Post_Plugin
{
private:
  static double callback(int num, int action, double value, double *opt,
			 double step, double min, double max);
  static char *callbackStr(int num, int action, char *value, char **opt);
public:
  GMSH_AnnotatePlugin();
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);  
  Post_View *execute(Post_View *);

  static double callbackX(int, int, double);
  static double callbackY(int, int, double);
  static double callbackZ(int, int, double);
  static double callback3D(int, int, double);
  static double callbackFontSize(int, int, double);
  static char *callbackText(int, int, char *);
  static char *callbackFont(int, int, char *);
  static char *callbackAlign(int, int, char *);
  static void draw();
};

#endif
