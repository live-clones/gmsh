#ifndef STRUCTURAL_SOLVER_H_
#define STRUCTURAL_SOLVER_H_
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include <list>
#include "Mesh.h"
#include "Plugin.h"
#include <string>

#ifdef HAVE_FLTK
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_draw.H>
#include <FL/gl.h>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Bitmap.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/x.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Tooltip.H>
#endif

extern "C"
{
  GMSH_Plugin *GMSH_RegisterStructuralSolverPlugin();
}

struct Structural_BeamSection
{
  Mesh m;
  std::string name;
  Structural_BeamSection ( const char *direct, std::string _name );
  ~Structural_BeamSection();
};


class StructuralSolver : public GMSH_Solve_Plugin
{
  std::list < struct Structural_BeamSection* > beam_sections;
  void RegisterBeamSections ();
#ifdef HAVE_FLTK 
  Fl_Window        *context_mesh_window ;
  Fl_Input         *context_mesh_input[20] ;
  Fl_Choice        *context_mesh_choice[20] ;
#endif
public:
  StructuralSolver();
  ~StructuralSolver();
  virtual void getName(char *name) const;
  virtual void getInfos(char *author, char *copyright, char *helpText) const;

  // When an error is thrown by the plugin, the plugin manager will
  // show the message and hopefully continue
  virtual void catchErrorMessage(char *errorMessage) const;
  virtual void popupPropertiesForPhysicalEntity (int dim);
  virtual void receiveNewPhysicalGroup (int dim, int id){}
  virtual void writeSolverFile ( FILE *f ) const{} 
  virtual void loadSolverFile  ( FILE *f ){}
};

#endif

