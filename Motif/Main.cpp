// $Id: Main.cpp,v 1.9 2001-02-12 17:38:03 geuzaine Exp $

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
#include "Views.h"

#include "Widgets.h"
#include "Pixmaps.h"
#include "XColors.h"
#include "XContext.h"
#include "XRessources.h"
#include "CbContext.h"
#include "CbGeom.h"
#include "Register.h"
#include "Geometry.h"
#include "OpenFile.h"
#include "GetOptions.h"

#include "Static.h"
#include "XStatic.h"

char* ShowVisualClass(int cls){
  if(cls==TrueColor)   return "TrueColor";
  if(cls==DirectColor) return "DirectColor";
  if(cls==PseudoColor) return "PseudoColor";
  if(cls==StaticColor) return "StaticColor";
  if(cls==GrayScale)   return "GrayScale";
  if(cls==StaticGray)  return "StaticGray";
  return "Unknown";
}

int main(int argc, char *argv[]){
  int     i, nbf;
  XColor  ov_color_def, ov_color_exact;
  extern char  *TextBuffer, TextAbout[1024];
 
  /* Gmsh default context options */
  
  Init_Context(0);

  /* Command line options */

  Get_Options(argc, argv, &nbf);

  if(CTX.verbosity)
    fprintf(stderr, "%s, Version %.2f\n", gmsh_progname, GMSH_VERSION);

  /* Initialize the static Mesh */

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

  /* Signal handling */

  signal(SIGINT,  Signal); 
  signal(SIGSEGV, Signal);
  signal(SIGFPE,  Signal); 

  /* Non-interactive Gmsh */

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
  

  /* Interactive Gmsh */

  CTX.interactive = -1 ; /* The GUI is not ready yet for interactivity */

  /* Text for about window */

  sprintf(TextAbout, "%s\n \n%s%.2f\n%s\n%s%s\n%s\n%s\n%s\n%s\n%s\n \n%s\n \n"
          "Type 'gmsh -help' for command line options",
          gmsh_progname, gmsh_version, GMSH_VERSION, 
          gmsh_os, gmsh_gui, XmVERSION_STRING, 
	  gmsh_date, gmsh_host, gmsh_packager, 
          gmsh_url, gmsh_email, gmsh_copyright);
  
  /* Xlib Threads init */
  
#ifdef _USETHREADS  
  if(CTX.threads){
    if(!XInitThreads()){
      Msg(WARNING, "Xlib is not Thread Safe (Reverting to '-nothreads')");
      CTX.threads = 0;
    }
  }
#else
  CTX.threads = 0;
#endif
  
  /* Xtoolkit init */
  
  XtToolkitInitialize();
  
#ifdef _USETHREADS  
  if(CTX.threads){
    if(!XtToolkitThreadInitialize()){
      Msg(WARNING, "Xtoolkit is not Thread Safe (Reverting to '-nothreads')");
      CTX.threads = 0;
    }
  }
#endif
  
  XCTX.AppContext = XtCreateApplicationContext();
  
  /* X/Motif default resources */

  XtAppSetFallbackResources(XCTX.AppContext, FallbackResources);

  /* Open display */

  XCTX.display = XtOpenDisplay(XCTX.AppContext, NULL, "gmshGW", ".gmshrc", 
                               NULL, 0, &argc, argv);

  if(!XCTX.display){
    Msg(FATAL1, "Unable to open the specified display. Set the `DISPLAY'");
    Msg(FATAL2, "environment variable properly or use the `xhost' command");
    Msg(FATAL3, "to authorize access to the display");
  }

  /* Check for GLX extension; for Mesa, this is always OK */
  
  if(!glXQueryExtension(XCTX.display,NULL,NULL)){
    Msg(FATAL1, "The specified display does not support the OpenGL extension (GLX).");
    Msg(FATAL3, "You may consider using Mesa instead");
  }

  /* Init with default screen num and default depth */
  
  XCTX.scrnum = DefaultScreen(XCTX.display);
  XCTX.depth  = DefaultDepth(XCTX.display, XCTX.scrnum);

  /* Init with default visual for the gui */

  XCTX.gui.visual = DefaultVisual(XCTX.display,XCTX.scrnum);

  /* Find visual the regular way for glw */
  
  if(CTX.db){
    if(!(XCTX.glw.visinfo = 
         glXChooseVisual(XCTX.display,XCTX.scrnum, glw_attrib_db))){
      Msg(WARNING,"GBA Double Buffured Visual not Available");
      CTX.db = 0;
    }
  }
  
  if(!CTX.db){
    if(!(XCTX.glw.visinfo = 
         glXChooseVisual(XCTX.display,XCTX.scrnum, glw_attrib_sb)))
      Msg(FATAL, "RGBA Single Buffured Visual not Available");
  }
  
  Msg(DEBUG, "Visual id=%lx depth=%d screen=%d bits/rgb=%d class=%s dblbuf=%d",
      XCTX.glw.visinfo->visualid, XCTX.glw.visinfo->depth,
      XCTX.glw.visinfo->screen, XCTX.glw.visinfo->bits_per_rgb,
#if defined(__cplusplus) || defined(c_plusplus)
      ShowVisualClass(XCTX.glw.visinfo->c_class), 
#else
      ShowVisualClass(XCTX.glw.visinfo->class), 
#endif
      CTX.db);

  /* Find visual the regular way for glo */
  
#ifndef _NOOV
  if(CTX.overlay){
    if(!(XCTX.glo.visinfo = glXChooseVisual(XCTX.display,XCTX.scrnum,glo_attrib))){
      Msg(DEBUG, "Overlay Visual not Available (Using Blend Function Instead)");
      CTX.overlay = 0;
      CTX.geom.highlight = 0;
    }
  }
#else
  CTX.overlay = 0 ;
  CTX.geom.highlight = 0;
#endif

  if(CTX.overlay){
    Msg(DEBUG,"Overlay Visual id=%lx depth=%d screen=%d bits/rgb=%d class=%s",
        XCTX.glo.visinfo->visualid, XCTX.glo.visinfo->depth, 
        XCTX.glo.visinfo->screen, XCTX.glo.visinfo->bits_per_rgb, 
#if defined(__cplusplus) || defined(c_plusplus)
        ShowVisualClass(XCTX.glo.visinfo->c_class)
#else
        ShowVisualClass(XCTX.glo.visinfo->class)
#endif
        );
  }


  /* Init with default colormaps */

  XCTX.gui.colormap = DefaultColormap(XCTX.display,0);
  XCTX.glw.colormap = DefaultColormap(XCTX.display,0);
  XCTX.glo.colormap = DefaultColormap(XCTX.display,0);
  
  /*
    If not using default visual (i.e. not using the gui visual), we need a colormap for 
    this visual. Yes, the GL widget can allocate one itself, but we want to make sure 
    the GUI and the 3D have the same one (if hardware does not allow more than one 
    simultaneously). This prevents nasty flashing when the window with the 3D widget 
    looses the focus.
    */
  
  if(!CTX.flash && (XCTX.glw.visinfo->visual != XCTX.gui.visual)){
    Msg(DEBUG, "Making Another Colormap for Graphic Window");
    XCTX.glw.colormap = XCreateColormap(XCTX.display, RootWindow(XCTX.display,XCTX.scrnum),
                                        XCTX.glw.visinfo->visual, AllocNone);
    if(!XCTX.glw.colormap)
      Msg(FATAL, "Unable to Create Colormap for Graphic Window (Try Option '-flash')");
  }

  if(CTX.overlay){
    if(!CTX.flash && (XCTX.glo.visinfo->visual != XCTX.gui.visual)){
      Msg(DEBUG, "Making Another Colormap for Overlay Window");
      XCTX.glo.colormap = XCreateColormap(XCTX.display, RootWindow(XCTX.display,XCTX.scrnum),
                                          XCTX.glo.visinfo->visual, AllocNone);
      if(!XCTX.glo.colormap){
        Msg(FATAL1, "Unable to Create Private Colormap for Overlay Window");
	Msg(FATAL3, "(Try '-noov' and/or '-flash' Options)");
      }
    }
  }
  
  /* Force to use common visual for GUI and GL? Maybe you can invoke
     some hardware interrogation function and see if more than one
     hardware map is supported.  Here, we check for the -samevisual
     flag */
  
  if(CTX.same_visual){
    XCTX.gui.visual = XCTX.glw.visinfo->visual;
    XCTX.gui.colormap = XCTX.glw.colormap;
  }

  /* Create all the motif widgets */
   
  CreateWidgets(&WID);

  /* create the OpenGL contexts */

  XCTX.glw.context = glXCreateContext(XtDisplay(WID.G.glw),XCTX.glw.visinfo,NULL,GL_TRUE);  

  if(CTX.overlay){
    XCTX.glo.context = glXCreateContext(XtDisplay(WID.G.glo),
                                        XCTX.glo.visinfo,NULL,GL_TRUE);  

    if (!XAllocNamedColor(XCTX.display, XCTX.glo.colormap, 
                          "white", &ov_color_def, &ov_color_exact)) {
      Msg(WARNING, "Couldn't Allocate White for Overlay window (Reverting to '-noov')");
      CTX.overlay = 0;
    }
    else
      XCTX.xcolor.ovwhite = ov_color_def.pixel;
  }

  if(CTX.overlay){
    if (!XAllocNamedColor(XCTX.display, XCTX.glo.colormap, 
                          "black", &ov_color_def, &ov_color_exact)) {
      Msg(WARNING, "Couldn't Allocate Black for Overlay Window (Reverting to '-noov')");
      CTX.overlay = 0;
    }
    else
      XCTX.xcolor.ovblack = ov_color_def.pixel;
  }

  /* X font initialisation */
  XCTX.xfont.helve = XLoadQueryFont(XCTX.display, CTX.font); 
  XCTX.xfont.fixed = XLoadQueryFont(XCTX.display, CTX.fixed_font);

  if(XCTX.xfont.helve == NULL){
    Msg(WARNING, "Unable to Load Font '%s'", CTX.font);
    XCTX.xfont.helve = XCTX.xfont.fixed ;
  }
  if(XCTX.xfont.fixed == NULL)
    Msg(FATAL, "Unable to Load Font '%s'", CTX.fixed_font);
  
  XCTX.xfont.helve_h = XCTX.xfont.helve->max_bounds.ascent + 
    XCTX.xfont.helve->max_bounds.descent;
  XCTX.xfont.helve_a = XCTX.xfont.helve->max_bounds.ascent;
  XCTX.xfont.helve_w = XCTX.xfont.helve->max_bounds.width;

  XCTX.xfont.fixed_h = XCTX.xfont.fixed->max_bounds.ascent +
    XCTX.xfont.fixed->max_bounds.descent;
  XCTX.xfont.fixed_a = XCTX.xfont.fixed->max_bounds.ascent;
  XCTX.xfont.fixed_w = XCTX.xfont.fixed->max_bounds.width;

  CTX.gl_fontheight = XCTX.xfont.helve_h ;
  CTX.gl_fontascent = XCTX.xfont.helve_a ;


  /* X color initialisation (set the pixel format and allocate some colors in XCTX) */

  XColorInitialize();

  /* Force widget geometry */

  ForceGeometry(&WID);

  /* Register all the callbacks */

  RegisterCallbacks(&WID);

  /* Realize widgets in the 3 windows (M=menu, G=graphics, C=command) */

  XtRealizeWidget(WID.M.shell);
  XtRealizeWidget(WID.G.shell);
  if(CTX.command_win) XtRealizeWidget(WID.C.shell);

  /* Create the pixmaps */

  CreatePixmaps(&WID, &PIX, XCTX.depth);

  /* Select input events for the graphic window and raise overlay window */

  if(CTX.overlay){
    XRaiseWindow(XtDisplay(WID.G.glo), XtWindow(WID.G.glo));
    XSelectInput(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), EV_MASK);
  }
  else{
    XSelectInput(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), EV_MASK);
  }

  /* OpenGL display list for the font */

  if((CTX.font_base = glGenLists(XCTX.xfont.helve->max_char_or_byte2+1)) == 0)
    Msg(FATAL, "Font out of OpenGL Display Lists");

  glXUseXFont(XCTX.xfont.helve->fid, 
              XCTX.xfont.helve->min_char_or_byte2, 
              XCTX.xfont.helve->max_char_or_byte2-XCTX.xfont.helve->min_char_or_byte2+1, 
              CTX.font_base+XCTX.xfont.helve->min_char_or_byte2);

  /* The GUI is ready */
  CTX.interactive = 0 ; 
  CTX.expose = 1 ;

  /* Say welcome! */

  TextBuffer = (char*)Malloc(1024*sizeof(char));
  Msg(STATUS3, "Ready");
  Msg(STATUS1, "Gmsh %.2f", GMSH_VERSION);

  /* Open input file */

  OpenProblem(CTX.filename);

  /* Merge all Input Files if any, then init first context (geometry or post) */

  if(nbf > 1){
    for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    ActualizeContextCb (NULL,(XtPointer)CONTEXT_POST,NULL); 
  }
  else {
    ActualizeContextCb(NULL,(XtPointer)CONTEXT_GEOM,NULL);
  }

  /* Read background mesh on disk if any */ 

  if(TheBgmFileName){
    MergeProblem(TheBgmFileName);
    if(List_Nbr(Post_ViewList))
      BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
    else
      Msg(GERROR, "Invalid Background Mesh (no View)");
  }
  
  /* Draw the actual scene */
  Draw();

  /* Loop until were done */
  
  XtAppMainLoop(XCTX.AppContext);
  
  /* never here */
  
}
  
