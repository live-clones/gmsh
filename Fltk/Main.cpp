// $Id: Main.cpp,v 1.10 2001-01-13 15:41:35 geuzaine Exp $

#include <signal.h>

#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"

#include "Geo.h"
#include "Verif.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "ColorTable.h"
#include "Parser.h"
#include "Static.h"
#include "GUI.h"
#include "OpenFile.h"
#include "GetOptions.h"

GUI *WID ;

int main(int argc, char *argv[]){
  int     i, nbf;
 
  // Gmsh default context options
  
  Init_Context();

  // Configuration file and command line options

  Get_Options(argc, argv, &nbf);

  if(CTX.verbosity)
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

  if(CTX.interactive){
    OpenProblem(CTX.filename);
    if(yyerrorstate)
      exit(1);
    else {
      if(nbf > 1){
        for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
      }
      if(TheBgmFileName){
        MergeProblem(TheBgmFileName);
        if(List_Nbr(Post_ViewList))
          BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
        else
          Msg(GERROR, "Invalid Background Mesh (no View)");
      }
      if(CTX.interactive > 0){
        mai3d(THEM, CTX.interactive);
        Print_Mesh(THEM,NULL,CTX.mesh.format);
      }
      else
        Print_Geo(THEM, NULL);
      exit(1);
    }    
  }
  

  // Interactive Gmsh

  CTX.interactive = -1 ; // The GUI is not ready yet for interactivity

  // Create the GUI
  
  WID = new GUI();

  // The GUI is ready
  CTX.interactive = 0 ; 

  // Say welcome!

  Msg(STATUS3N, "Ready");
  Msg(STATUS1, "Gmsh %.2f", GMSH_VERSION);

  Msg(LOG_INFO, gmsh_os);
  Msg(LOG_INFO, gmsh_date);
  Msg(LOG_INFO, gmsh_host);
  Msg(LOG_INFO, gmsh_packager);

  // Display the GUI to have a quick "a la Windows" launch time

  WID->check();

  // Open input file

  OpenProblem(CTX.filename);

  // Merge all Input Files, then init first context (geometry or post)

  if(nbf > 1){
    for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    WID->set_context(menu_post, 0);
  }
  else {
    WID->set_context(menu_geometry, 0); 
  }

  // Read background mesh on disk

  if(TheBgmFileName){
    MergeProblem(TheBgmFileName);
    if(List_Nbr(Post_ViewList))
      BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
    else
      Msg(GERROR, "Invalid Background Mesh (no View)");
  }

  // Draw the actual scene
  Init();
  Draw();
  CTX.expose = 1 ;

  // loop
  WID->run();

}
  
