/* $Id: Main.cpp,v 1.21 2000-12-06 18:28:30 remacle Exp $ */

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
#include "MinMax.h"

#include "Widgets.h"
#include "Pixmaps.h"

#include "XColors.h"
#include "XContext.h"
#include "XRessources.h"

#include "CbContext.h"
#include "CbGeom.h"
#include "Register.h"
#include "Geometry.h"

#include "Static.h"
#include "XStatic.h"

#include "Version.h"

char gmsh_progname[]  = "This is Gmsh" ;
char gmsh_copyright[] = "Copyright (C) 1997-2000 J.-F. Remacle, C. Geuzaine";
char gmsh_version[]   = "Version          : " ;
char gmsh_os[]        = "Operating System : " GMSH_OS ;
char gmsh_date[]      = "Build Date       : " GMSH_DATE ;
char gmsh_host[]      = "Build Host       : " GMSH_HOST ;
char gmsh_packager[]  = "Packager         : " GMSH_PACKAGER ;
char gmsh_url[]       = "URL              : http://www.geuz.org/gmsh/" ;
char gmsh_email[]     = "E-Mail           : Christophe.Geuzaine@ulg.ac.be\n"
                        "                   Remacle@scorec.rpi.edu" ;
char gmsh_help[]      = 
  "Usage: %s [options] [files]\n"
  "Geometry options:\n"
  "  -0                    output current options, flattened geometry and exit\n"
  "Mesh options:\n"
  "  -1, -2, -3            perform batch 1D, 2D and 3D mesh generation\n"
  "  -script               gmsh in script mode\n"
  "  -format msh|unv|gref  set output mesh format (default: msh)\n"
  "  -algo iso|aniso       select mesh algorithm (default: iso)\n"
  "  -smooth int           set mesh smoothing (default: 0)\n"
  "  -degree int           set mesh degree (default: 1)\n"
  "  -scale float          set global scaling factor (default: 1.0)\n"
  "  -clscale float        set characteristic length scaling factor (default: 1.0)\n"
  "  -bgm file             load backround mesh from file\n"
  "  -interactive          display 2D mesh construction interactively\n"
  "Post Processing options:\n"
  "  -dl                   enable display lists\n"
  "  -noview               hide all views at startup\n"
  "  -link                 link all views at startup\n"
  "Display options:\n"    
  "  -nodb                 disable double buffering\n"
  "  -noov                 disable overlay visual\n"
  "  -alpha                enable alpha blending\n"
  "  -notrack              don't use trackball mode for rotations\n"
  "  -geometry geom        specify main window geometry\n"
  "  -viewport 9*float     specify rotation, translation and scale\n"
  "  -display disp         specify display\n"
  "  -perspective          set projection mode to perspective\n"
  "  -flash                allow colormap flashing\n"
  "  -samevisual           force same visual for graphics and UI\n"
  "Other options:\n"      
  "  -v int                set verbosity level (default: 2)\n"
  "  -nothreads            disable threads\n"
  "  -path string          set path for included files\n"
  "  -version              show version number\n"
  "  -info                 show detailed version information\n"
  "  -help                 show this message\n"
  ;

char *TheFileNameTab[MAX_OPEN_FILES], *TheBgmFileName=NULL;
char  ThePathForIncludes[NAME_STR_L];

extern List_T *Post_ViewList;

/* ------------------------------------------------------------------------ */
/*  P a r s e                                                               */
/* ------------------------------------------------------------------------ */

void ParseFile(char *f){
  char String[256];
  Post_View *v;

  strncpy(yyname,f,NAME_STR_L);
  yyerrorstate=0;
  yylineno=1;

  if(!(yyin = fopen(yyname,"r"))){
    Msg(INFO, "File '%s' Does not Exist", f);
    return;
  }
  
  fpos_t position;
  fgetpos(yyin, &position);
  fgets(String, sizeof(String), yyin) ; 
  fsetpos(yyin, &position);

  printf("String :: %s",String);
  
  if(!strncmp(String, "$PTS", 4) || 
     !strncmp(String, "$NO", 3) || 
     !strncmp(String, "$ELM", 4)){
    if(THEM->status < 0) mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_MSH);
  }
  else if(!strncmp(String, "$COL", 4)){
    if(List_Nbr(Post_ViewList)){
      v = (Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1);
      ColorTable_Load(yyin, &v->CT);
    }
    else{
      Msg(WARNING, "No Post-Processing View Available to set Colors From");
    }
  }
  else if(!strncmp(String, "$PostFormat", 11) ||
          !strncmp(String, "$View", 5)){
    Read_View(yyin, yyname);
  }
  else{
    while(!feof(yyin)) yyparse();
  }
  fclose(yyin);
}

extern int SHOW_ALL_ENTITIES ;

void MergeProblem(char *name){
  Msg(INFOS, "Merging '%s'",name); 

  ParseFile(name);  
  if (yyerrorstate) return;

  if (!EntitesVisibles) {
    RemplirEntitesVisibles(1);
    SHOW_ALL_ENTITIES = 1;
  }
}

void OpenProblem(char *name){
  char ext[6];
  
  InitSymbols();
  Init_Mesh(&M, 1);

  strncpy(TheFileName,name,NAME_STR_L);
  strncpy(TheBaseFileName,name,NAME_STR_L);

  strcpy(ext,name+(strlen(name)-4));
  if(!strcmp(ext,".GEO") || 
     !strcmp(ext,".geo") || 
     !strcmp(ext,".msh") || 
     !strcmp(ext,".pos")){
    TheBaseFileName[strlen(name)-4] = '\0';
  }
  else{
    strcat(TheFileName,".geo");
  }

  strncpy(THEM->name, TheBaseFileName,NAME_STR_L);

  if(!CTX.interactive)
    XtVaSetValues(WID.G.shell,
                  XmNtitle, TheFileName,
                  XmNiconName, TheBaseFileName,
                  NULL);

  Msg(INFOS, "Opening '%s'", TheFileName); 

  ParseFile(TheFileName);  

  ApplyLcFactor(THEM);
  mai3d(THEM,0);  
  Maillage_Dimension_0(&M);

  ZeroHighlight(&M); 
  CalculateMinMax(THEM->Points);  
  if (!EntitesVisibles) {
    RemplirEntitesVisibles(1);
    SHOW_ALL_ENTITIES = 1;
  }

}


/* ------------------------------------------------------------------------ */
/*  G e t _ O p t i o n s                                                   */
/* ------------------------------------------------------------------------ */

void Get_Options (int argc, char *argv[], int *nbfiles) {
  int i=1;

  TheFileNameTab[0] = "unnamed.geo" ;
  *nbfiles = 0;
  
  while (i < argc) {
    
    if (argv[i][0] == '-') {
      
      if(!strcmp(argv[i]+1, "0")){ 
        CTX.interactive = -1; i++;
      }
      else if(!strcmp(argv[i]+1, "1")){ 
        CTX.interactive = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "2")){ 
        CTX.interactive = 2; i++;
      }
      else if(!strcmp(argv[i]+1, "3")){ 
        CTX.interactive = 3; i++;
      }
      else if(!strcmp(argv[i]+1, "script")){ 
        CTX.script = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "path")){ 
        i++;
        /* we need to make a copy because of bison */
        if(argv[i] != NULL) 
          strncpy(ThePathForIncludes, argv[i++], NAME_STR_L) ;
        else {    
          fprintf(stderr, ERROR_STR "Missing String\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "bgm")){ 
        i++;
        if(argv[i] != NULL) TheBgmFileName = argv[i++];
        else {    
          fprintf(stderr, ERROR_STR "Missing File Name\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "alpha")){ 
        CTX.alpha = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "notrack")){ 
        CTX.useTrackball = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "flash")){ 
        CTX.flash = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "old")){ 
        FLAG_OLD_CIRCLE = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "dual")){ 
        CTX.mesh.dual = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "samevisual")){ 
        CTX.same_visual = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "interactive")){ 
        CTX.mesh.interactive = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "scale")){
        i++;
        if(argv[i]!=NULL) CTX.mesh.scaling_factor = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "rand")){
        i++;
        if(argv[i]!=NULL) CTX.mesh.rand_factor = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "clscale")){
        i++;
        if(argv[i]!=NULL){
          CTX.mesh.lc_factor = atof(argv[i++]);
          if(CTX.mesh.lc_factor <= 0.0){
            fprintf(stderr, ERROR_STR 
                    "Characteristic Length Factor Must be > 0\n");
            exit(1);
          }
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "smooth")){ 
        i++;
        if(argv[i]!=NULL) CTX.mesh.nb_smoothing = atoi(argv[i++]);
        else{
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "degree")){  
        i++;
        if(argv[i]!=NULL){
          CTX.mesh.degree = atoi(argv[i++]);
          if(CTX.mesh.degree != 1 || CTX.mesh.degree != 2){
            fprintf(stderr, ERROR_STR "Wrong Degree\n");
            exit(1);
          }
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "format") ||  
              !strcmp(argv[i]+1, "f")){  
        i++;
        if(argv[i]!=NULL){
          if(!strcmp(argv[i],"msh") || 
             !strcmp(argv[i],"MSH") || 
             !strcmp(argv[i],"gmsh")){
            CTX.mesh.format = FORMAT_MSH ;
          }
          else if(!strcmp(argv[i],"unv") ||
                  !strcmp(argv[i],"UNV") || 
                  !strcmp(argv[i],"ideas")){
            CTX.mesh.format = FORMAT_UNV ;
          }
          else if(!strcmp(argv[i],"gref") ||
                  !strcmp(argv[i],"GREF") || 
                  !strcmp(argv[i],"Gref")){
            CTX.mesh.format = FORMAT_GREF ;
          }
          else{
            fprintf(stderr, ERROR_STR "Unknown Mesh Format\n");
            exit(1);
          }
          i++;
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing Format\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "algo")){  
        i++;
        if(argv[i]!=NULL){
          if(!strcmp(argv[i],"iso"))
            CTX.mesh.algo = DELAUNAY_OLDALGO ;
          else if(!strcmp(argv[i],"aniso"))
            CTX.mesh.algo = DELAUNAY_NEWALGO ;
          else{
            fprintf(stderr, ERROR_STR "Unknown Mesh Algorithm\n");
            exit(1);
          }
          i++;
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing Algorithm\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "noview")){ 
        CTX.post.initial_visibility = 0 ; i++;
      }
      else if(!strcmp(argv[i]+1, "link")){ 
        CTX.post.link = 2 ; i++;
      }
      else if(!strcmp(argv[i]+1, "fill")){ 
        CTX.post.initial_intervals = DRAW_POST_DISCRETE ; i++;
      }
      else if(!strcmp(argv[i]+1, "nbiso")){ 
        i++ ;
        if(argv[i]!=NULL) CTX.post.initial_nbiso = atoi(argv[i++]);
        else{
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "command") || 
              !strcmp(argv[i]+1, "c")){ 
        CTX.command_win = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "nocommand") ||
              !strcmp(argv[i]+1, "noc")){ 
        CTX.command_win = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "overlay") ||
              !strcmp(argv[i]+1, "ov")){ 
        CTX.overlay = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "nooverlay") ||
              !strcmp(argv[i]+1, "noov")){ 
        CTX.overlay = CTX.geom.highlight = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "perspective") ||
              !strcmp(argv[i]+1, "p")){ 
        CTX.ortho = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "ortho") ||
              !strcmp(argv[i]+1, "o")){ 
        CTX.ortho = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "threads")){
        CTX.threads = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "nothreads")){
        CTX.threads = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "viewport")){ 
        i++ ;
        if(argv[i]!=NULL){
          CTX.r[0] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.r[1] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.r[2] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.t[0] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.t[1] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.t[2] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.s[0] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.s[1] = atof(argv[i]) ; i++ ;
        }
        if(argv[i]!=NULL){
          CTX.s[2] = atof(argv[i]) ; i++ ;
        }
        else{
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "db")){ 
        CTX.db = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "nodb")){ 
        CTX.db = 0; CTX.geom.highlight = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "dl")){ 
        CTX.display_lists = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "nodl")){ 
        CTX.display_lists = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "geometry") ||
              !strcmp(argv[i]+1, "display")  ||
              !strcmp(argv[i]+1, "fg")       ||
              !strcmp(argv[i]+1, "bg")){
        i++;
        if(argv[i]!=NULL)
          i++;
        else {    
          fprintf(stderr, ERROR_STR "Missing Argument\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "iconic")){
	i++;
      }
      else if(!strcmp(argv[i]+1, "v")){  
        i++;
        if(argv[i]!=NULL) CTX.verbosity = atoi(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "version") || 
              !strcmp(argv[i]+1, "-version")){
        fprintf(stderr, "%g\n", GMSH_VERSION);
        exit(1);
      }
      else if(!strcmp(argv[i]+1, "info") || 
              !strcmp(argv[i]+1, "-info")){
        fprintf(stderr, "%s%g\n", gmsh_version, GMSH_VERSION);
        fprintf(stderr, "%s\n", gmsh_os);
        fprintf(stderr, "%s\n", gmsh_date);
        fprintf(stderr, "%s\n", gmsh_host);
        fprintf(stderr, "%s\n", gmsh_packager);
        fprintf(stderr, "%s\n", gmsh_url);
        fprintf(stderr, "%s\n", gmsh_email);
        exit(1) ; 
      }
      else if(!strcmp(argv[i]+1, "help") || 
              !strcmp(argv[i]+1, "-help")){
        fprintf(stderr, "%s\n", gmsh_progname);
        fprintf(stderr, "%s\n", gmsh_copyright);
        fprintf(stderr, gmsh_help, argv[0]);
        exit(1);
      }
      else{
        fprintf(stderr, "Unknown Option '%s'\n", argv[i]);
        fprintf(stderr, gmsh_help, argv[0]);
        exit(1);
      }
    }

    else {
      if(*nbfiles < MAX_OPEN_FILES)
        TheFileNameTab[(*nbfiles)++] = argv[i++]; 
      else{
        fprintf(stderr, ERROR_STR "Too Many Input Files\n");
        exit(1);
      }
    }

  }

  strncpy(TheFileName, TheFileNameTab[0], NAME_STR_L);

}

char* ShowVisualClass(int cls){
  if(cls==TrueColor)   return "TrueColor";
  if(cls==DirectColor) return "DirectColor";
  if(cls==PseudoColor) return "PseudoColor";
  if(cls==StaticColor) return "StaticColor";
  if(cls==GrayScale)   return "GrayScale";
  if(cls==StaticGray)  return "StaticGray";
  return "Unknown";
}

/* ------------------------------------------------------------------------ */
/*  M a i n                                                                 */
/* ------------------------------------------------------------------------ */

int main(int argc, char *argv[]){
  int     i, nbf;
  XColor  ov_color_def, ov_color_exact;
  extern char  *TextBuffer, TextAbout[1024];
 
  /* Gmsh default context options */
  
  Init_Context();

  /* Command line options */

  Get_Options(argc, argv, &nbf);

  if(CTX.verbosity)
    fprintf(stderr, "%s, Version %g\n", gmsh_progname, GMSH_VERSION);

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
    OpenProblem(TheFileName);
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
  

  /* Interactive Gmsh */

  CTX.interactive = -1 ; /* The GUI is not ready yet for interactivity */

  /* Text for about window */

  sprintf(TextAbout, "%s\n \n%s%g\n%s\n%s\n%s\n%s\n%s\n%s\n \n%s\n \n"
          "Type 'gmsh -help' for command line options",
          gmsh_progname, gmsh_version, GMSH_VERSION, 
          gmsh_os, gmsh_date, gmsh_host, gmsh_packager, 
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

  if(!XCTX.display)
    Msg(FATAL, "Unable to open the specified display. Set the `DISPLAY'\n"
        FATAL_NIL "environment variable properly or use the `xhost' command\n"
        FATAL_NIL "to authorize access to the display");

  /* Check for GLX extension; for Mesa, this is always OK */
  
  if(!glXQueryExtension(XCTX.display,NULL,NULL))
    Msg(FATAL, "The specified display does not support the OpenGL extension (GLX).\n"
        FATAL_NIL "You may consider using Mesa instead");
  
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
      if(!XCTX.glo.colormap)
        Msg(FATAL, "Unable to Create Private Colormap for Overlay Window\n"
            FATAL_NIL "(Try '-noov' and/or '-flash' Options)");
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

  /* Say welcome! */

  TextBuffer = (char*)Malloc(1024*sizeof(char));
  Msg(STATUS, "Ready");
  Msg(SELECT, "Gmsh %g", GMSH_VERSION);

  /* Compute viewport and Draw */
  CTX.expose = 1 ;
  Init();
  Draw();

  /* Open input file */

  OpenProblem(TheFileName);

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
      Msg(ERROR, "Invalid Background Mesh (no View)");
  }
  
  Replot();
  
  /* Loop until were done */
  
  XtAppMainLoop(XCTX.AppContext);
  
  /* never here */
  
}
  
