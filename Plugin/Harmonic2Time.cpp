// $Id: Harmonic2Time.cpp,v 1.10 2004-02-05 22:52:33 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
#include "Harmonic2Time.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber Harmonic2TimeOptions_Number[] = {
  {GMSH_FULLRC, "realPart", NULL, 0.},
  {GMSH_FULLRC, "imaginaryPart", NULL, 1.},
  {GMSH_FULLRC, "nbSteps", NULL, 20.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHarmonic2TimePlugin()
  {
    return new GMSH_Harmonic2TimePlugin();
  }
}


GMSH_Harmonic2TimePlugin::GMSH_Harmonic2TimePlugin()
{
  ;
}

void GMSH_Harmonic2TimePlugin::getName(char *name) const
{
  strcpy(name, "Harmonic2Time");
}

void GMSH_Harmonic2TimePlugin::getInfos(char *author, char *copyright,
                                        char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Harmonic2Time) takes the values in the\n"
	 "time steps 'realPart' and 'imaginaryPart' of\n"
         "the view 'iView', and creates a new view\n"
         "containing ('iView'['realPart'] * cos(p) -\n"
         "'iView'['imaginaryPart'] * sin(p)), with\n"
         "p = 2*Pi*k/'nbSteps', k = 0, ..., 'nbSteps'-1.\n"
	 "If 'iView' < 0, the plugin is run on the\n"
	 "current view.\n"
	 "\n"
	 "Plugin(Harmonic2Time) creates one new view.\n");
}

int GMSH_Harmonic2TimePlugin::getNbOptions() const
{
  return sizeof(Harmonic2TimeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Harmonic2TimePlugin::getOption(int iopt)
{
  return &Harmonic2TimeOptions_Number[iopt];
}

void GMSH_Harmonic2TimePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Harmonic2Time failed...");
}


static void harmonic2time(Post_View * vv, Post_View * View,
                          int rIndex, int iIndex, int nbSteps)
{
  int i, j, k;
  double val, valr, vali, p;
  for(i = 0; i < nbSteps; i++) {
    p = Deux_Pi * i / (nbSteps - 1);
    for(j = 0; j < VIEW_NB_ELEMENT_TYPES; j++) {
      for(k = 0; k < VIEW_MAX_ELEMENT_NODES; k++) {
        if(vv->get_val(j, k, rIndex, &valr) &&
           vv->get_val(j, k, iIndex, &vali)) {
          val = valr * cos(p) - vali * sin(p);
          View->add_val(j, k, i, val);
        }
      }
    }
  }
}

Post_View *GMSH_Harmonic2TimePlugin::execute(Post_View * v)
{
  Post_View *vv, *View;
  int rIndex, iIndex, nbSteps, iView;

  rIndex = (int)Harmonic2TimeOptions_Number[0].def;
  iIndex = (int)Harmonic2TimeOptions_Number[1].def;
  nbSteps = (int)Harmonic2TimeOptions_Number[2].def;
  iView = (int)Harmonic2TimeOptions_Number[3].def;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(WARNING, "View[%d] does not exist", iView);
      return 0;
    }
  }

  if(MIN(rIndex, iIndex) >= 0 && vv->NbTimeStep >= MAX(rIndex, iIndex)) {
    // FIXME: this is not secure: if BeginView forces a post.list
    // reallocation, vv is wrong
    View = BeginView(1);
    harmonic2time(vv, View, rIndex, iIndex, nbSteps);
    // create time data
    // FIXME: todo
    // finalize
    char name[1024], filename[1024];
    sprintf(name, "h2t-%s", vv->Name);
    sprintf(filename, "h2t-%s", vv->FileName);
    EndView(View, 1, filename, name);
    Msg(INFO, "Created view '%s'", name);
    return View;
  }

  return 0;
}

