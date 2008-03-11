// $Id: Main.cpp,v 1.120 2008-03-11 22:30:31 geuzaine Exp $
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

#include <string>
#include <time.h>
#include "GUI.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "Message.h"
#include "Generator.h"
#include "CreateFile.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Solvers.h"
#include "PluginManager.h"
#include "GModel.h"
#include "Field.h"
#include "BackgroundMesh.h"
#include "PView.h"

Context_T CTX;
GUI *WID = 0;

int main(int argc, char *argv[])
{
  // Log some info
  time_t now;
  time(&now);
  std::string currtime(ctime(&now));
  currtime[currtime.size() - 1] = '\0';
  std::string cmdline;
  for(int i = 0; i < argc; i++){
    if(i) cmdline += " ";
    cmdline += argv[i];
  }

  // Hack to generate automatic documentation (before getting
  // user-defined options)
  if(argc == 2 && std::string(argv[1]) == "-doc"){
    Init_Options(0);
    GMSH_PluginManager::instance()->registerDefaultPlugins();
    Print_OptionsDoc();
    exit(0);
  }

  // Initialize static stuff (parser symbols, options)
  GmshInitialize(argc, argv);

  // Always print info on terminal for non-interactive execution
  if(CTX.batch) CTX.terminal = 1;

  // Create a new model
  new GModel;

  // Non-interactive Gmsh
  if(CTX.batch) {
    Msg(INFO, "'%s' started on %s", cmdline.c_str(), currtime.c_str());
    OpenProject(CTX.filename);
    if(gmsh_yyerrorstate)
      exit(1);
    else {
      for(unsigned int i = 1; i < CTX.files.size(); i++)
        MergeFile(CTX.files[i].c_str());
      if(CTX.post.combine_time)
	PView::combine(true, 2, CTX.post.combine_remove_orig);
      if(CTX.bgm_filename) {
        MergeFile(CTX.bgm_filename);
        if(PView::list.size()){
	  Field *field = new PostViewField(PView::list.back());
	  BGMAddField(field);
	  fields.insert(field);
        }
        else
          Msg(GERROR, "Invalid background mesh (no view)");
      }
      if(CTX.batch == 4) {
        AdaptMesh(GModel::current());
        CreateOutputFile(CTX.output_filename, CTX.mesh.format);
      }
      else if(CTX.batch > 0) {
        GModel::current()->mesh(CTX.batch);
        CreateOutputFile(CTX.output_filename, CTX.mesh.format);
      }
      else if(CTX.batch == -1)
        CreateOutputFile(CTX.output_filename, FORMAT_GEO);
      else if(CTX.batch == -2)
	GModel::current()->checkMeshCoherence();
      exit(0);
    }
  }

  // Interactive Gmsh
  CTX.batch = -1; // The GUI is not ready yet for interactivity

  // Create the GUI
  WID = new GUI(argc, argv);

  // Set all previously defined options in the GUI
  Init_Options_GUI(0);

  // The GUI is ready
  CTX.batch = 0;

  // Say welcome!
  Msg(STATUS1N, "Geometry");
  Msg(STATUS2N, "Gmsh %s", Get_GmshVersion());

  // Log the following for bug reports
  Msg(INFO, "-------------------------------------------------------");
  Msg(INFO, "Gmsh version   : %s", Get_GmshVersion());
  Msg(INFO, gmsh_os);
  Msg(INFO, "%s%s", gmsh_options, Get_BuildOptions());
  Msg(INFO, gmsh_date);
  Msg(INFO, gmsh_host);
  Msg(INFO, gmsh_packager);
  Msg(INFO, "Home directory : %s", CTX.home_dir);
  Msg(INFO, "Launch date    : %s", currtime.c_str());
  Msg(INFO, "Command line   : %s", cmdline.c_str());
  Msg(INFO, "-------------------------------------------------------");

  // Display the GUI immediately to have a quick "a la Windows" launch time
  WID->check();

  // Open project file and merge all other input files
  OpenProject(CTX.filename);
  for(unsigned int i = 1; i < CTX.files.size(); i++)
    MergeFile(CTX.files[i].c_str());
  if(CTX.post.combine_time){
    PView::combine(true, 2, CTX.post.combine_remove_orig);
    WID->update_views();
  }

  // Init first context
  switch (CTX.initial_context) {
  case 1: WID->set_context(menu_geometry, 0); break;
  case 2: WID->set_context(menu_mesh, 0); break;
  case 3: WID->set_context(menu_solver, 0); break;
  case 4: WID->set_context(menu_post, 0); break;
  default: // automatic
    if(PView::list.size())
      WID->set_context(menu_post, 0);
    else
      WID->set_context(menu_geometry, 0);
    break;
  }

  // Read background mesh on disk
  if(CTX.bgm_filename) {
    MergeFile(CTX.bgm_filename);
    if(PView::list.size()){
      Field *field = new PostViewField(PView::list.back());
      BGMAddField(field);
      fields.insert(field);
    }
    else
      Msg(GERROR, "Invalid background mesh (no view)");
  }

  // Draw the actual scene
  Draw();

  // Listen to external solvers
  if(CTX.solver.listen) Solver(-1, NULL);

  // loop
  return WID->run();
}
