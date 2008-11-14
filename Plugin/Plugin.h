// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PLUGIN_H_
#define _PLUGIN_H_

// To create a plugin:
// 1) Create a dynamic lib containing GMSH_RegisterPlugin();
// 2) When there is an unacceptable error in the plugin, just throw
//    this, the plugin manager will be able to catch the exception.
//  Some Plugins are default gmsh plugins and are insterted directly
//  in the executable. I think that it's a good way to start.

#include <string.h>
#include <stdio.h>
#include "Options.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewDataList.h"
#include "GmshMatrix.h"

class PluginDialogBox;
class Vertex;

class GMSH_Plugin
{
 public :
  // 4 kinds of plugins
  typedef enum {
    GMSH_CAD_PLUGIN, 
    GMSH_MESH_PLUGIN, 
    GMSH_POST_PLUGIN, 
    GMSH_SOLVE_PLUGIN 
  } GMSH_PLUGIN_TYPE;

  // a dialog box for the user interface
  PluginDialogBox *dialogBox;

  // for internal use by PluginManager
  void *hlib;

  GMSH_Plugin() : dialogBox(0), hlib(0) {}
  virtual ~GMSH_Plugin(){}

  // return plugin type, name and info
  virtual GMSH_PLUGIN_TYPE getType() const = 0;
  virtual void getName(char *name) const = 0;
  virtual void getInfos(char *author, char *copyright, char *helpText) const = 0;

  // when an error is thrown by the plugin, the plugin manager will
  // show the message and hopefully continue
  virtual void catchErrorMessage(char *errorMessage) const = 0;

  // gmsh-style numeric options
  virtual int getNbOptions() const = 0;
  virtual StringXNumber *getOption(int iopt) = 0;

  // gmsh-style string options
  virtual int getNbOptionsStr() const = 0;
  virtual StringXString *getOptionStr(int iopt) = 0;

  // run the plugin
  virtual void run() = 0;
};

// The base class for post-processing plugins. The user can either
// modify or duplicate a post-processing view
class GMSH_Post_Plugin : public GMSH_Plugin
{
 public:
  inline GMSH_PLUGIN_TYPE getType() const { return GMSH_Plugin::GMSH_POST_PLUGIN; }
  virtual int getNbOptionsStr() const { return 0; }
  virtual StringXString *getOptionStr(int iopt) { return NULL; }
  virtual void run(){ execute(0); }
  // if the returned pointer is the same as the argument, then the
  // view is simply modified, else, a new view is added in the view
  // list
  virtual PView *execute(PView *) = 0;
  // get the view given an index and a default value
  virtual PView *getView(int index, PView *view);
  // get the data in list format
  virtual PViewDataList *getDataList(PView *view);
  virtual void assignSpecificVisibility() const {}
  virtual bool geometricalFilter(Double_Matrix *) const { return true; }
};

// The base class for solver plugins. The idea is to be able to
// associate some properties to physical entities, so that we can
// interface gmsh with a solver (ABAQUS...), i.e., create the input
// file for the solver
class GMSH_Solve_Plugin : public GMSH_Plugin
{
 public:
  virtual int getNbOptionsStr() const { return 0; }
  virtual StringXString *getOptionStr(int iopt) { return 0; }
  virtual int getNbOptions() const { return 0; }
  virtual StringXNumber *getOption(int iopt) { return 0; };
  inline GMSH_PLUGIN_TYPE getType() const { return GMSH_Plugin::GMSH_SOLVE_PLUGIN; }
  virtual void run() {} // do nothing
  // popup dialog box
  virtual void popupPropertiesForPhysicalEntity(int dim) = 0;
  // add the given group to the solver data
  virtual void receiveNewPhysicalGroup(int dim, int id) = 0;
  // load the solver input file related to the gmsh geo file
  virtual void readSolverFile(const char *) = 0;
  // save the solver file  
  virtual void writeSolverFile(const char *) const = 0;
  // enhance graphics for a giver geo point
  virtual bool GL_enhancePoint(Vertex *v) { return false; }
  // enhance graphics for a giver geo line
  virtual bool GL_enhanceLine(int CurveId, Vertex *v1, Vertex *v2) { return false; }
};

#endif
