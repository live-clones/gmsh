// $Id: Main.cpp,v 1.2 2001-01-08 08:02:57 geuzaine Exp $

#include <signal.h>

#include "Gmsh.h"
#include "GmshUI.h"

#include "Geo.h"
#include "Verif.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "ColorTable.h"
#include "Parser.h"
#include "Static.h"
#include "Version.h"
#include "GUI.h"
#include "OpenFile.h"
#include "GetOptions.h"

extern List_T *Post_ViewList;
int            SHOW_ALL_ENTITIES ;

void AddViewInUI(int, char *, int){}

GUI *WID ;

int main(int argc, char *argv[]){
  int     i, nbf;
  extern char  TextAbout[1024];
 
  // Gmsh default context options
  
  Init_Context();

  // Command line options

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
          Msg(ERROR, "Invalid Background Mesh (no View)");
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

  // Text for about window

  sprintf(TextAbout, "%s\n \n%s%.2f\n%s\n%s\n%s\n%s\n%s\n%s\n \n%s\n \n"
          "Type 'gmsh -help' for command line options",
          gmsh_progname, gmsh_version, GMSH_VERSION, 
          gmsh_os, gmsh_date, gmsh_host, gmsh_packager, 
          gmsh_url, gmsh_email, gmsh_copyright);

  // Create the GUI
  
  WID = new GUI();

  // The GUI is ready
  CTX.interactive = 0 ; 
  CTX.expose = 1 ;

  // Say welcome!

  Msg(STATUS, "Ready");
  Msg(SELECT, "Gmsh %.2f", GMSH_VERSION);

  // Display the GUI to have a quick "a la Windows" launch time

  WID->check();

  // Open input file

  OpenProblem(CTX.filename);

  // Merge all Input Files, then init first context (geometry or post)

  if(nbf > 1){
    for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    //ActualizeContextCb (NULL,(XtPointer)CONTEXT_POST,NULL); 
  }
  else {
    //ActualizeContextCb(NULL,(XtPointer)CONTEXT_GEOM,NULL);
  }

  // Read background mesh on disk

  if(TheBgmFileName){
    MergeProblem(TheBgmFileName);
    if(List_Nbr(Post_ViewList))
      BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
    else
      Msg(ERROR, "Invalid Background Mesh (no View)");
  }

  // Draw the actual scene
  Init();
  Draw();

  // loop
  WID->run();

}
  
