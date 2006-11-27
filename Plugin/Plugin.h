#ifndef _PLUGIN_H_
#define _PLUGIN_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

// To create a plugin for gmsh:
// 1) Create a dynamin lib (.so) containing 1 symbol 
//    GMSH_Plugin * GMSH_RegisterPlugin ();
// 2) When there is an unacceptable error in the plugin,
//    just throw this, the plugin manager will be able to 
//    catch the exception.

//  Some Plugins are default gmsh plugins and are insterted
//  directly in the executable. I think that it's a good 
//  way to start.

#include <string.h>
#include <stdio.h>

#include "Options.h"
#include "Message.h"
#include "Views.h"
#include "GmshMatrix.h"

class PluginDialogBox;
class Vertex;

class GMSH_Plugin
{
public :
  // a dialog box for user interface
  PluginDialogBox *dialogBox;

  // this is there for internal use, this variable will be used by the
  // PluginManager, just forget it
  void *hlib;

  // 3 kind of plugins, one for cad, one for mesh, one for postpro
  typedef enum {GMSH_CAD_PLUGIN, 
		GMSH_MESH_PLUGIN, 
		GMSH_POST_PLUGIN, 
		GMSH_SOLVE_PLUGIN} GMSH_PLUGIN_TYPE ;

  GMSH_Plugin() : dialogBox(0), hlib(0) {;};
  virtual ~GMSH_Plugin() {;};
  
  // returns the type of plugin for downcasting GMSH_Plugin into
  // GMSH_CAD_Plugin, GMSH_Mesh_Plugin and GMSH_Post_Plugin
  virtual GMSH_PLUGIN_TYPE getType() const = 0;
  virtual void getName(char *name) const = 0;
  virtual void getInfos(char *author, char *copyright, char *helpText) const = 0;

  // When an error is thrown by the plugin, the plugin manager will
  // show the message and hopefully continue
  virtual void catchErrorMessage(char *errorMessage) const = 0;

  // gmsh style numeric options
  virtual int getNbOptions() const = 0;
  virtual StringXNumber *getOption(int iopt) = 0;

  // gmsh style string options
  virtual int getNbOptionsStr() const = 0;
  virtual StringXString *getOptionStr(int iopt) = 0;

  // run the plugin
  virtual void run() = 0;
};


// Base class for Post-Processing Plugins. The user can either modify
// or duplicate a Post_View

class GMSH_Post_Plugin : public GMSH_Plugin
{
public:
  inline GMSH_PLUGIN_TYPE getType() const { return GMSH_Plugin::GMSH_POST_PLUGIN; }
  virtual int getNbOptionsStr() const { return 0; };
  virtual StringXString *getOptionStr(int iopt) { return NULL; };
  virtual void run(){ execute(0); }
  // If returned pointer is the same as the argument, then view is
  // simply modified, else, a new view is added in the view list
  virtual Post_View *execute(Post_View *) = 0;
  virtual void assign_specific_visibility() const {}
  virtual bool geometrical_filter(Double_Matrix *geometrical_nodes_positions) const {return true;}
  virtual bool functional_filter(Double_Matrix *function_values) const {return true;}
};

// A solver plugin. The idea here is to be able to associate some
// properties to physical entities. The goal is to be able to
// interface gmsh with a solver (ABAQUS...) i.e. create the input file
// for the solver.

class GMSH_Solve_Plugin : public GMSH_Plugin
{
public:
  virtual int getNbOptionsStr() const { return 0; };
  virtual StringXString *getOptionStr(int iopt) { return NULL; };
  virtual int getNbOptions() const { return 0; };
  virtual StringXNumber *getOption(int iopt) { return NULL; };
  inline GMSH_PLUGIN_TYPE getType() const { return GMSH_Plugin::GMSH_SOLVE_PLUGIN; }
  virtual void run() {}; // do nothing
  // popup dialog box
  virtual void popupPropertiesForPhysicalEntity(int dim) = 0;
  // add the given group to the solver data's
  virtual void receiveNewPhysicalGroup(int dim, int id) = 0;
  // load the solver input file related to the gmsh geo file
  virtual void readSolverFile(const char *) = 0;
  // save the solver file  
  virtual void writeSolverFile(const char *) const = 0;
  // enhance graphics for a giver geo point
  virtual bool GL_enhancePoint(Vertex *v) { return false; };
  // enhance graphics for a giver geo line
  virtual bool GL_enhanceLine (int CurveId, Vertex *v1, Vertex *v2) { return false; };
};

#endif
