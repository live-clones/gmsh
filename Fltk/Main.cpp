// $Id: Main.cpp,v 1.53 2003-11-29 19:29:26 geuzaine Exp $
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

#include <signal.h>
#include <time.h>

#include "PluginManager.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"

#include "Geo.h"
#include "Verif.h"
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

char yyname[256]="";
int yyerrorstate=0;
Context_T CTX;
Mesh M, *THEM = NULL, *LOCAL = NULL;
GUI *WID = NULL;

int main(int argc, char *argv[])
{
  int i, nbf;
  char *cmdline, currtime[100];
  time_t now;

  // log some info

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

  // Generate automatic documentation
  
  if(argc == 2 && !strcmp(argv[1], "-doc")){
    Print_OptionsDoc();
    exit(0);
  }

  // Configuration files and command line options

  Get_Options(argc, argv, &nbf);

  // This does not work with FLTK right now...

  CTX.overlay = 0;
  CTX.geom.highlight = 0;

  // Always print info on terminal for non-interactive execution

  if(CTX.batch)
    CTX.terminal = 1;

  if(CTX.verbosity && CTX.terminal)
    fprintf(stderr, "%s, version %d.%d.%d, started %s\n",
            gmsh_progname, GMSH_MAJOR_VERSION, GMSH_MINOR_VERSION,
            GMSH_PATCH_VERSION, currtime);

  // Register Default Plugins
  if(CTX.default_plugins)
    GMSH_PluginManager::instance()->registerDefaultPlugins();

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
  M.Metric = NULL;

  // Signal handling

  signal(SIGINT, Signal);
  signal(SIGSEGV, Signal);
  signal(SIGFPE, Signal);

  // Non-interactive Gmsh

  if(CTX.batch) {
    check_gsl();
    Msg(DIRECT, "Command line : %s", cmdline);
    OpenProblem(CTX.filename);
    if(yyerrorstate)
      exit(1);
    else {
      for(i = 1; i < nbf; i++)
        MergeProblem(TheFileNameTab[i]);
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
  Msg(STATUS1, "Gmsh %d.%d.%d", GMSH_MAJOR_VERSION, GMSH_MINOR_VERSION,
      GMSH_PATCH_VERSION);

  // Log the following for bug reports

  Msg(LOG_INFO, "-------------------------------------------------------");
  Msg(LOG_INFO, gmsh_os);
  Msg(LOG_INFO, "%s%s", gmsh_options, Get_BuildOptions());
  Msg(LOG_INFO, gmsh_date);
  Msg(LOG_INFO, gmsh_host);
  Msg(LOG_INFO, gmsh_packager);
  Msg(LOG_INFO, "Home directory : %s", CTX.home_dir);
  Msg(LOG_INFO, "Launch date    : %s", currtime);
  Msg(LOG_INFO, "Command line   : %s", cmdline);
  Msg(LOG_INFO, "-------------------------------------------------------");

  Free(cmdline);

  // Check for buggy obsolete GSL versions

  check_gsl();

  // Display the GUI immediately to have a quick "a la Windows" launch time

  WID->check();

  // Open project file

  OpenProblem(CTX.filename);

  // Merge all other input files

  for(i = 1; i < nbf; i++)
    MergeProblem(TheFileNameTab[i]);

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
  CTX.expose = 1;

  // loop
  return WID->run();
}
