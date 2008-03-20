// $Id: Smooth.cpp,v 1.31 2008-03-20 11:44:14 geuzaine Exp $
//
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

#include "Smooth.h"

StringXNumber SmoothOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSmoothPlugin()
  {
    return new GMSH_SmoothPlugin();
  }
}


GMSH_SmoothPlugin::GMSH_SmoothPlugin()
{
  ;
}

void GMSH_SmoothPlugin::getName(char *name) const
{
  strcpy(name, "Smooth");
}

void GMSH_SmoothPlugin::getInfos(char *author, char *copyright,
                                 char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Smooth) averages the values at the nodes\n"
         "of the scalar view `iView'. If `iView' < 0, the\n"
         "plugin is run on the current view.\n"
         "\n"
         "Plugin(Smooth) is executed in-place.\n");
}

int GMSH_SmoothPlugin::getNbOptions() const
{
  return sizeof(SmoothOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SmoothPlugin::getOption(int iopt)
{
  return &SmoothOptions_Number[iopt];
}

void GMSH_SmoothPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Smooth failed...");
}

PView *GMSH_SmoothPlugin::execute(PView *v)
{
  int iView = (int)SmoothOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  v1->getData()->smooth();
  v1->setChanged(true);

  return v1;
}
