
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
    Msg(INFO, "File '%s' dos not exist", f);
    return;
  }

  fgets(String, sizeof(String), yyin) ; 
  rewind(yyin);

  if(!strncmp(String, "$PTS", 4) || 
     !strncmp(String, "$NO", 3) || 
     !strncmp(String, "$ELM", 4)){
    if(THEM->status < 0) mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_MSH);
  }
  else if(!strncmp(String, "$COL", 4)){
    if(List_Nbr(Post_ViewList)){
      v = (Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1);
      load_color_table(yyin, &v->CT);
    }
    else{
      Msg(WARNING, "No Post-Processing View available to set Colors");
    }
  }
  else{
    while(!feof(yyin)) yyparse();
  }
  fclose(yyin);
}

void MergeProblem(char *name){
  Msg(INFOS, "Merging %s",name); 

  ParseFile(name);  
  if (yyerrorstate) return;

  if (!EntitesVisibles) {
    RemplirEntitesVisibles(1);
    SHOW_ALL=1;
  }
}

void OpenProblem(char *name){
  char ext[6];
  
  InitSymbols();
  Init_Mesh(&M, 1);
  BD_EXISTS = 1;

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

  Msg(INFOS, "Opening %s", TheFileName); 

  ParseFile(TheFileName);  

  mai3d(THEM,0);  
  
  Maillage_Dimension_0(&M);
  ZeroHighlight(&M); 
  CalculateMinMax(THEM->Points);  
  if (!EntitesVisibles) {
    RemplirEntitesVisibles(1);
    SHOW_ALL=1;
  }

}


/* ------------------------------------------------------------------------ */
/*  G e t _ O p t i o n s                                                   */
/* ------------------------------------------------------------------------ */

void Get_Options (int argc, char *argv[]) {
  int i=1;
  
  strncpy(TheFileNameTab[0], "unnamed.geo",NAME_STR_L);
  
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
      else if(!strcmp(argv[i]+1, "path")){ 
	i++;
	if(argv[i] != NULL){
	  strncpy(ThePathForIncludes,argv[i++],NAME_STR_L);
	}
      }
      else if(!strcmp(argv[i]+1, "bgm")){ 
	i++;
	if(argv[i] != NULL){
	  strncpy(TheBgmFileName,argv[i++],NAME_STR_L);
	  INITIALBGMESH = ONFILE;
	}
      }
      else if(!strcmp(argv[i]+1, "alpha")){ 
	CTX.alpha = 1; i++;
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
      else if(!strcmp(argv[i]+1, "recombine")){
	CTX.mesh.reco_extrude = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "samevisual")){ 
	CTX.same_visual = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "factor")){
	i++;
	FACTEUR_MULTIPLICATIF = atof(argv[i]); i++;
      }
      else if(!strcmp(argv[i]+1, "scale") ||
	      !strcmp(argv[i]+1, "scaling")){
	i++;
	GLOBALSCALINGFACTOR = atof(argv[i]); i++;
      }
      else if(!strcmp(argv[i]+1, "raw")){ 
	LISSAGE = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "smooth")){ 
	i++;
	LISSAGE = atoi(argv[i]); i++;
      }
      else if(!strcmp(argv[i]+1, "degree")){  
	i++;
	if(argv[i]!=NULL){
	  CTX.mesh.degree = atoi(argv[i]); i++;
	  if(CTX.mesh.degree != 1 || CTX.mesh.degree != 2){
	    fprintf(stderr, "Error: Wrong degree\n");
	    exit(1);
	  }
	}
	else {	  
	  fprintf(stderr, "Error: Missing Number\n");
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
	    fprintf(stderr, "Error: Unknown mesh format\n");
	    exit(1);
	  }
	  i++;
	}
	else {	  
	  fprintf(stderr, "Error: Missing format\n");
	  exit(1);
	}
      }
      else if(!strcmp(argv[i]+1, "algo")){  
	i++;
	if(argv[i]!=NULL){
	  if(!strcmp(argv[i],"iso"))
	    CTX.mesh.algo = DELAUNAT_OLDALGO ;
	  else if(!strcmp(argv[i],"aniso"))
	    CTX.mesh.algo = DELAUNAT_NEWALGO ;
	  else{
	    fprintf(stderr, "Error: Unknown mesh algorithm\n");
	    exit(1);
	  }
	  i++;
	}
	else {	  
	  fprintf(stderr, "Error: Missing algorithm\n");
	  exit(1);
	}
      }
      else if(!strcmp(argv[i]+1, "noview")){ 
	CTX.post.initial_visibility = 0 ; i++;
      }
      else if(!strcmp(argv[i]+1, "fill")){ 
	CTX.post.initial_intervals = DRAW_POST_DISCRETE ; i++;
      }
      else if(!strcmp(argv[i]+1, "nbiso")){ 
	i++ ;
	CTX.post.initial_nbiso = atoi(argv[i]) ; i++ ;
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
	CTX.r[0] = atof(argv[i]) ; i++ ;
	CTX.r[1] = atof(argv[i]) ; i++ ;
	CTX.r[2] = atof(argv[i]) ; i++ ;
	CTX.t[0] = atof(argv[i]) ; i++ ;
	CTX.t[1] = atof(argv[i]) ; i++ ;
	CTX.t[2] = atof(argv[i]) ; i++ ;
	CTX.s[0] = atof(argv[i]) ; i++ ;
	CTX.s[1] = atof(argv[i]) ; i++ ;
	CTX.s[2] = atof(argv[i]) ; i++ ;
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
	      !strcmp(argv[i]+1, "iconic")   ||
	      !strcmp(argv[i]+1, "display")  ||
	      !strcmp(argv[i]+1, "fg")       ||
	      !strcmp(argv[i]+1, "bg")){
	i+=2;
      }
      else if(!strcmp(argv[i]+1, "version") || 
	      !strcmp(argv[i]+1, "v") ||
	      !strcmp(argv[i]+1, "-version") || 
	      !strcmp(argv[i]+1, "-v")){
	Info(2,argv[0]); 
      }
      else if(!strcmp(argv[i]+1, "info") || 
	      !strcmp(argv[i]+1, "-info")){
	Info(1,argv[0]); 
      }
      else if(!strcmp(argv[i]+1, "help") || 
	      !strcmp(argv[i]+1, "h") || 
	      !strcmp(argv[i]+1, "-help") || 
	      !strcmp(argv[i]+1, "-h")){
	Info(0,argv[0]);
      }
      else{
	fprintf(stderr, "Warning: Unknown option '%s'\n", argv[i]);
	Info(0,argv[0]);
      }
    }

    else {
      if(NbFileName<MAX_OPEN_FILES){
	strncpy(TheFileNameTab[NbFileName++], argv[i++], NAME_STR_L); 
      }
      else{
	fprintf(stderr, "Error: Too many input files\n");
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
  int     i;
  XColor  ov_color_def, ov_color_exact;
  
  /* Gmsh default context options */
  
  InitContext(&CTX);

  /* Command line options */

  Get_Options(argc, argv);

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
    else{
      if(NbFileName>1){
	for(i=1;i<NbFileName;i++) MergeProblem(TheFileNameTab[i]);
      }
      if(INITIALBGMESH == ONFILE){
	MergeProblem(TheBgmFileName);
	if(List_Nbr(Post_ViewList)){
	  BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
	  TYPBGMESH = ONFILE; 
	  Create_BgMesh(TYPBGMESH,.2,THEM);
	}
	else{
	  Msg(ERROR, "Invalid background mesh (no view)");
	}
      }
      if(CTX.interactive > 0){
	mai3d(THEM, CTX.interactive);
	Print_Mesh(THEM,NULL,CTX.mesh.format);
      }
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
	  gmsh_email, gmsh_url, gmsh_copyright);
  
  /* Xlib Threads init */
  
#ifndef _NOTHREADS  
  if(CTX.threads){
    if(!XInitThreads()){
      Msg(WARNING, "Xlib is not thread safe: reverting to '-nothreads'");
      CTX.threads = 0;
    }
  }
#else
  CTX.threads = 0;
#endif
  
  /* Xtoolkit init */
  
  XtToolkitInitialize();
  
#ifndef _NOTHREADS  
  if(CTX.threads){
    if(!XtToolkitThreadInitialize()){
      Msg(WARNING, "Xtoolkit is not thread safe: reverting to '-nothreads'");
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
    Msg(ERROR, "Unable to open the specified display. Set the `DISPLAY'\n"
   	"       environment variable properly or use the `xhost' command\n"
	"       to authorize access to the display");

  /* Check for GLX extension; for Mesa, this is always OK */
  
  if(!glXQueryExtension(XCTX.display,NULL,NULL))
    Msg(ERROR, "The specified display does not support the OpenGL extension (GLX).\n"
	"       You may consider using Mesa instead");
  
  /* Init with default screen num and default depth */
  
  XCTX.scrnum = DefaultScreen(XCTX.display);
  XCTX.depth  = DefaultDepth(XCTX.display, XCTX.scrnum);

  /* Init with default visual for the gui */

  XCTX.gui.visual = DefaultVisual(XCTX.display,XCTX.scrnum);

  /* Find visual the regular way for glw */
  
  if(CTX.db){
    if(!(XCTX.glw.visinfo = 
	 glXChooseVisual(XCTX.display,XCTX.scrnum, glw_attrib_db))){
      Msg(WARNING,"GBA double buffured visual not available");
      CTX.db = 0;
    }
  }
  
  if(!CTX.db){
    if(!(XCTX.glw.visinfo = 
	 glXChooseVisual(XCTX.display,XCTX.scrnum, glw_attrib_sb)))
      Msg(ERROR, "RGBA single buffured visual not available");
  }
  
  Msg(INFOS,"Visual id=%lx depth=%d screen=%d bits/rgb=%d class=%s dblbuf=%d",
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
      Msg(INFOS, "Overlay visual not available (using blend function instead)");
      CTX.overlay = 0;
      CTX.geom.highlight = 0;
    }
  }
#else
  CTX.overlay = 0 ;
  CTX.geom.highlight = 0;
#endif

  if(CTX.overlay){
    Msg(INFO,"Overlay Visual id=%lx depth=%d screen=%d bits/rgb=%d class=%s\n",
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
    Msg(INFOS,"Making another colormap for graphic window");
    XCTX.glw.colormap = XCreateColormap(XCTX.display, RootWindow(XCTX.display,XCTX.scrnum),
					XCTX.glw.visinfo->visual, AllocNone);
    if(!XCTX.glw.colormap)
      Msg(ERROR, "Unable to create colormap for graphic window: Try option '-flash'");
  }

  if(CTX.overlay){
    if(!CTX.flash && (XCTX.glo.visinfo->visual != XCTX.gui.visual)){
      Msg(INFOS, "Making another colormap for overlay window");
      XCTX.glo.colormap = XCreateColormap(XCTX.display, RootWindow(XCTX.display,XCTX.scrnum),
					  XCTX.glo.visinfo->visual, AllocNone);
      if(!XCTX.glo.colormap)
	Msg(ERROR, "Unable to create private colormap for overlay window:\n"
	    "       Try '-noov' and/or '-flash' options");
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
      Msg(WARNING, "Couldn't allocate white for overlay window: Reverting to '-noov'");
      CTX.overlay = 0;
    }
    else
      XCTX.xcolor.ovwhite = ov_color_def.pixel;
  }

  if(CTX.overlay){
    if (!XAllocNamedColor(XCTX.display, XCTX.glo.colormap, 
			  "black", &ov_color_def, &ov_color_exact)) {
      Msg(WARNING, "Couldn't allocate black for overlay window: Reverting to '-noov'");
      CTX.overlay = 0;
    }
    else
      XCTX.xcolor.ovblack = ov_color_def.pixel;
  }

  /* X font initialisation */
  XCTX.xfont.helve = XLoadQueryFont(XCTX.display, CTX.font_string); 
  XCTX.xfont.fixed = XLoadQueryFont(XCTX.display, CTX.colorbar_font_string);

  if(XCTX.xfont.helve == NULL){
    Msg(WARNING, "Unable to load font %s", CTX.font_string);
    XCTX.xfont.helve = XCTX.xfont.fixed ;
  }
  if(XCTX.xfont.fixed == NULL){
    Msg(ERROR, "Unable to load font %s", CTX.colorbar_font_string);
    exit(1);
  }
  
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
    Msg(ERROR, "Font out of OpenGL display lists");

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

  /* Open input file */

  OpenProblem(TheFileName);

  /* Merge all Input Files if any, then init first context (geometry or post) */

  if(NbFileName>1){
    for(i=1;i<NbFileName;i++) MergeProblem(TheFileNameTab[i]);
    ActualizeContextCb (NULL,(XtPointer)CONTEXT_POST,NULL); 
  }
  else {
    ActualizeContextCb(NULL,(XtPointer)CONTEXT_GEOM,NULL);
  }

  /* Read background mesh on disk if any */ 

  if(INITIALBGMESH == ONFILE){
    MergeProblem(TheBgmFileName);
    if(List_Nbr(Post_ViewList)){
      BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
      TYPBGMESH = ONFILE; 
      Create_BgMesh(TYPBGMESH,.2,THEM);
    }
    else{
      Msg(ERROR, "Invalid background mesh (no view)");
    }
  }
  
  /* Compute viewport and Draw */
  EXPOSE = 1;
  Init();
  Draw();
  
  /* Loop until were done */
  
  XtAppMainLoop(XCTX.AppContext);
  
  /* never here */
  
}
  
