// $Id: Main.cpp,v 1.72 2004-09-28 17:13:49 geuzaine Exp $
//
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

#include <signal.h>
#include <time.h>

#include "PluginManager.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"

#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"
#include "ColorTable.h"
#include "Parser.h"
#include "GUI.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Numeric.h"

char yyname[256] = "";
int yyerrorstate = 0;
Context_T CTX;
Mesh M, *THEM = NULL, *LOCAL = NULL;
GUI *WID = NULL;

int main(int argc, char *argv[])
{
  int i, nbf;
  char *cmdline, currtime[100];
  time_t now;

  // Log some info
  
  time(&now);
  strcpy(currtime, ctime(&now));
  currtime[strlen(currtime) - 1] = '\0';

  int cll = 0;
  for(i = 0; i < argc; i++) {
    cll += strlen(argv[i]);
  }
  cmdline = (char*)Malloc((cll+argc+1)*sizeof(char));
  cmdline[0] = '\0';
  for(i = 0; i < argc; i++) {
    strcat(cmdline, argv[i]);
    strcat(cmdline, " ");
  }

  // Gmsh default options

  Init_Options(0);

  // Initialize the static Mesh

  M.Vertices = NULL;
  M.Simplexes = NULL;
  M.Points = NULL;
  M.Curves = NULL;
  M.SurfaceLoops = NULL;
  M.EdgeLoops = NULL;
  M.Surfaces = NULL;
  M.Volumes = NULL;
  M.PhysicalGroups = NULL;
  M.Partitions = NULL;
  M.Metric = NULL;
  M.BGM.bgm = NULL;
  M.Grid.init = 0;

  // Initialize the default plugins

  GMSH_PluginManager::instance()->registerDefaultPlugins();

  // Generate automatic documentation (before getting user-defined options)
  
  if(argc == 2 && !strcmp(argv[1], "-doc")){
    Print_OptionsDoc();
    exit(0);
  }

  // Read configuration files and command line options

  Get_Options(argc, argv, &nbf);

  // Always print info on terminal for non-interactive execution

  if(CTX.batch)
    CTX.terminal = 1;

  // Signal handling

  signal(SIGINT, Signal);
  signal(SIGSEGV, Signal);
  signal(SIGFPE, Signal);

  // Non-interactive Gmsh

  if(CTX.batch) {
    check_gsl();
    Msg(INFO, "'%s' started on %s", cmdline, currtime);
    OpenProblem(CTX.filename);
    if(yyerrorstate)
      exit(1);
    else {
      for(i = 1; i < nbf; i++)
        MergeProblem(TheFileNameTab[i]);
      if(CTX.post.combine_time)
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      if(TheBgmFileName) {
        MergeProblem(TheBgmFileName);
        if(List_Nbr(CTX.post.list))
          BGMWithView((Post_View *)
                      List_Pointer(CTX.post.list,
                                   List_Nbr(CTX.post.list) - 1));
        else
          Msg(GERROR, "Invalid background mesh (no view)");
      }
      if(CTX.batch > 0) {
        mai3d(THEM, CTX.batch);
        Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
      }
      else
        Print_Geo(THEM, CTX.output_filename);
      if(CTX.mesh.histogram) {
        Mesh_Quality(THEM);
        Print_Histogram(THEM->Histogram[0]);
      }
      exit(0);
    }
  }


  // Interactive Gmsh

  CTX.batch = -1;       // The GUI is not ready yet for interactivity

  // Create the GUI

  WID = new GUI(argc, argv);

  // Set all previously defined options in the GUI

  Init_Options_GUI(0);

  // The GUI is ready

  CTX.batch = 0;

  // Say welcome!

  Msg(STATUS3N, "Ready");
  Msg(STATUS1N, "Gmsh %s", GMSH_VERSION);

  // Log the following for bug reports

  Msg(INFO, "-------------------------------------------------------");
  Msg(INFO, "Gmsh version   : %s", GMSH_VERSION);
  Msg(INFO, gmsh_os);
  Msg(INFO, "%s%s", gmsh_options, Get_BuildOptions());
  Msg(INFO, gmsh_date);
  Msg(INFO, gmsh_host);
  Msg(INFO, gmsh_packager);
  Msg(INFO, "Home directory : %s", CTX.home_dir);
  Msg(INFO, "Launch date    : %s", currtime);
  Msg(INFO, "Command line   : %s", cmdline);
  Msg(INFO, "-------------------------------------------------------");

  Free(cmdline);

  // Check for buggy obsolete GSL versions

  check_gsl();

  // Display the GUI immediately to have a quick "a la Windows" launch time

  WID->check();

  // Open project file and merge all other input files

  OpenProblem(CTX.filename);
  for(i = 1; i < nbf; i++)
    MergeProblem(TheFileNameTab[i]);
  if(CTX.post.combine_time)
    CombineViews(1, 2, CTX.post.combine_remove_orig);
  
  // Init first context

  switch (CTX.initial_context) {
  case 1:
    WID->set_context(menu_geometry, 0);
    break;
  case 2:
    WID->set_context(menu_mesh, 0);
    break;
  case 3:
    WID->set_context(menu_solver, 0);
    break;
  case 4:
    WID->set_context(menu_post, 0);
    break;
  default:     // automatic
    if(List_Nbr(CTX.post.list))
      WID->set_context(menu_post, 0);
    else
      WID->set_context(menu_geometry, 0);
    break;
  }

  // Read background mesh on disk

  if(TheBgmFileName) {
    MergeProblem(TheBgmFileName);
    if(List_Nbr(CTX.post.list))
      BGMWithView((Post_View *)
                  List_Pointer(CTX.post.list, List_Nbr(CTX.post.list) - 1));
    else
      Msg(GERROR, "Invalid background mesh (no view)");
  }

  // Draw the actual scene
  Draw();

  // loop
  return WID->run();
}
