// $Id: Main.cpp,v 1.19 2001-03-04 22:58:01 remacle Exp $

#include <signal.h>

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
#include "Plugin.h"

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
          Msg(GERROR, "Invalid Background Mesh (no View)");
      }
      if(CTX.batch > 0){
        mai3d(THEM, CTX.batch);
        Print_Mesh(THEM,NULL,CTX.mesh.format);
      }
      else
        Print_Geo(THEM, NULL);
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

  Msg(LOG_INFO, "-------------------------------------------------------");
  Msg(LOG_INFO, gmsh_os);
  Msg(LOG_INFO, gmsh_date);
  Msg(LOG_INFO, gmsh_host);
  Msg(LOG_INFO, gmsh_packager);
  Msg(LOG_INFO, "-------------------------------------------------------");

  // Display the GUI to have a quick "a la Windows" launch time

  WID->check();

  // Register Default Plugins (in test ...)
  GMSH_PluginManager::Instance()->RegisterDefaultPlugins();

  // Open project file

  OpenProblem(CTX.filename);

  // Merge all other input files

  for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
  
  // Init first context (geometry or post)

  if(List_Nbr(Post_ViewList))
    WID->set_context(menu_post, 0);
  else
    WID->set_context(menu_geometry, 0); 

  // Read background mesh on disk

  if(TheBgmFileName){
    MergeProblem(TheBgmFileName);
    if(List_Nbr(Post_ViewList))
      BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
    else
      Msg(GERROR, "Invalid Background Mesh (no View)");
  }

  // Draw the actual scene
  Draw();
  CTX.expose = 1 ;

  // loop
  WID->run();

}
  
