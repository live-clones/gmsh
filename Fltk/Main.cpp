// $Id: Main.cpp,v 1.27 2001-05-23 07:29:42 geuzaine Exp $

#include <signal.h>

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
#include "Static.h"
#include "GUI.h"
#include "OpenFile.h"
#include "GetOptions.h"

GUI *WID = NULL;

int main(int argc, char *argv[]){
  int     i, nbf;
 
  // Gmsh default options
  
  Init_Options(0);

  // Configuration files and command line options

  Get_Options(argc, argv, &nbf);

  // This does not work with FLTK right now...

  CTX.overlay = 0 ;
  CTX.geom.highlight = 0 ;

  // Always print info on terminal for non-interactive execution

  if(CTX.batch)
    CTX.terminal = 1;

  if(CTX.verbosity && CTX.terminal)
    fprintf(stderr, "%s, Version %.2f\n", gmsh_progname, GMSH_VERSION);

  // Register Default Plugins (in test ...)
  if(CTX.default_plugins)
    GMSH_PluginManager::Instance()->RegisterDefaultPlugins();

  // Initialize the static Mesh

  M.Vertices = NULL ;
  M.VertexEdges = NULL ;
  M.Simplexes = NULL ;
  M.Points = NULL ;
  M.Curves = NULL ;
  M.SurfaceLoops = NULL ;
  M.EdgeLoops = NULL ;
  M.Surfaces = NULL ;
  M.Volumes = NULL ;
  M.PhysicalGroups = NULL ;
  M.Metric = NULL ;

  // Signal handling

  signal(SIGINT,  Signal); 
  signal(SIGSEGV, Signal);
  signal(SIGFPE,  Signal); 

  // Non-interactive Gmsh

  if(CTX.batch){
    OpenProblem(CTX.filename);
    if(yyerrorstate)
      exit(1);
    else {
      for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
      if(TheBgmFileName){
        MergeProblem(TheBgmFileName);
        if(List_Nbr(Post_ViewList))
          BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
        else
          Msg(GERROR, "Invalid background mesh (no view)");
      }
      if(CTX.batch > 0){
        mai3d(THEM, CTX.batch);
        Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
      }
      else
        Print_Geo(THEM, CTX.output_filename);
      if(CTX.mesh.histogram)
	Print_Histogram(THEM->Histogram[0]);
      exit(1);
    }    
  }
  

  // Interactive Gmsh

  CTX.batch = -1 ; // The GUI is not ready yet for interactivity

  // Create the GUI
  
  WID = new GUI(argc, argv);

  // Set all previously defined options in the GUI

  Init_Options_GUI(0);

  // The GUI is ready

  CTX.batch = 0 ; 

  // Say welcome!

  Msg(STATUS3N, "Ready");
  Msg(STATUS1, "Gmsh %.2f", GMSH_VERSION);

  // Log the following for bug reports
  
  Msg(LOG_INFO, "-------------------------------------------------------");
  Msg(LOG_INFO, gmsh_os);
  Msg(LOG_INFO, gmsh_date);
  Msg(LOG_INFO, gmsh_host);
  Msg(LOG_INFO, gmsh_packager);
  Msg(LOG_INFO, "Home directory   : '%s'", CTX.home_dir);
  Msg(LOG_INFO, "-------------------------------------------------------");

  // Display the GUI immediately to have a quick "a la Windows" launch time

  WID->check();

  // Open project file

  OpenProblem(CTX.filename);

  // Merge all other input files

  for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
  
  // Init first context

  switch(CTX.initial_context){
  case 1 :
    WID->set_context(menu_geometry, 0); 
    break;
  case 2 :
    WID->set_context(menu_mesh, 0); 
    break;
  case 3 :
    WID->set_context(menu_solver, 0); 
    break;
  case 4 :
    WID->set_context(menu_post, 0); 
    break;
  default : // automatic
    if(List_Nbr(Post_ViewList))
      WID->set_context(menu_post, 0);
    else
      WID->set_context(menu_geometry, 0); 
    break;
  }    

  // Read background mesh on disk

  if(TheBgmFileName){
    MergeProblem(TheBgmFileName);
    if(List_Nbr(Post_ViewList))
      BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
    else
      Msg(GERROR, "Invalid background mesh (no view)");
  }

  // Draw the actual scene
  Draw();
  CTX.expose = 1 ;

  // loop
  WID->run();

}
  
