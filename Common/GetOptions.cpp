// $Id: GetOptions.cpp,v 1.27 2001-06-25 13:12:50 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"
#include "Const.h"
#include "Context.h"
#include "Options.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "OpenFile.h"

extern Context_T  CTX;

char  *TheFileNameTab[MAX_OPEN_FILES];
char  *TheBgmFileName=NULL;

char gmsh_progname[]  = "This is Gmsh" ;
char gmsh_copyright[] = "Copyright (C) 1997-2001 Jean-Francois Remacle and Christophe Geuzaine";
char gmsh_version[]   = "Version          : " ;
char gmsh_os[]        = "Operating system : " GMSH_OS ;
char gmsh_gui[]       = "GUI toolkit      : " ;
char gmsh_date[]      = "Build date       : " GMSH_DATE ;
char gmsh_host[]      = "Build host       : " GMSH_HOST ;
char gmsh_packager[]  = "Packager         : " GMSH_PACKAGER ;
char gmsh_url[]       = "Web site         : http://www.geuz.org/gmsh/" ;
char gmsh_email[]     = "Mailing list     : gmsh@geuz.org" ;

void Print_Usage(char *name){
  Msg(DIRECT, "Usage: %s [options] [files]", name);
  Msg(DIRECT, "Geometry options:");
  Msg(DIRECT, "  -0                    parse input files, output flattened geometry, and exit");
  Msg(DIRECT, "Mesh options:");
  Msg(DIRECT, "  -1, -2, -3            perform batch 1D, 2D and 3D mesh generation");
  Msg(DIRECT, "  -o file               specify mesh output file name");
  Msg(DIRECT, "  -format msh|unv|gref  set output mesh format (default: msh)");
  Msg(DIRECT, "  -algo iso|aniso       select 2D mesh algorithm (default: iso)");
  Msg(DIRECT, "  -smooth int           set mesh smoothing (default: 0)");
  Msg(DIRECT, "  -degree int           set mesh degree (default: 1)");
  Msg(DIRECT, "  -scale float          set global scaling factor (default: 1.0)");
  Msg(DIRECT, "  -meshscale float      set mesh scaling factor (default: 1.0)");
  Msg(DIRECT, "  -clscale float        set characteristic length scaling factor (default: 1.0)");
  Msg(DIRECT, "  -rand float           set random perturbation factor (default: 1.e-4)");
  Msg(DIRECT, "  -bgm file             load backround mesh from file");
  Msg(DIRECT, "  -constrain            constrain background mesh with characteristic lengths");
  Msg(DIRECT, "  -histogram            print mesh quality histogram");
  Msg(DIRECT, "  -extrude              use old extrusion mesh generator");
  Msg(DIRECT, "  -recombine            recombine meshes from old extrusion mesh generator");
#ifndef _BLACKBOX
  Msg(DIRECT, "  -interactive          display 2D mesh construction interactively");
  Msg(DIRECT, "Post-processing options:");
  Msg(DIRECT, "  -dl                   enable display lists");
  Msg(DIRECT, "  -noview               hide all views on startup");
  Msg(DIRECT, "  -link                 link all views on startup");
  Msg(DIRECT, "  -convert file file    convert an ascii view into a binary one");
  Msg(DIRECT, "Display options:");    
  Msg(DIRECT, "  -nodb                 disable double buffering");
#ifdef _XMOTIF
  Msg(DIRECT, "  -noov                 disable overlay visual");
  Msg(DIRECT, "  -flash                allow colormap flashing");
  Msg(DIRECT, "  -samevisual           force same visual for graphics and GUI");
#else
  Msg(DIRECT, "  -fontsize int         specify the font size for the GUI (default: 12)");
#endif
  Msg(DIRECT, "  -alpha                enable alpha blending");
  Msg(DIRECT, "  -notrack              don't use trackball mode for rotations");
  Msg(DIRECT, "  -display string       specify display");
  Msg(DIRECT, "  -perspective          set projection mode to perspective");
#endif
  Msg(DIRECT, "Other options:");      
#ifndef _BLACKBOX
  Msg(DIRECT, "  -a, -g, -m, -s, -p    start in automatic, geometry, mesh, solver or");
  Msg(DIRECT, "                        post-processing mode (default: automatic)");
#endif
  Msg(DIRECT, "  -v int                set verbosity level (default: 2)");
#ifdef _XMOTIF
  Msg(DIRECT, "  -nothreads            disable threads");
#endif
  Msg(DIRECT, "  -version              show version number");
  Msg(DIRECT, "  -info                 show detailed version information");
  Msg(DIRECT, "  -help                 show this message");
}


void Get_Options (int argc, char *argv[], int *nbfiles) {
  int i=1;

  // Parse session and option files

  ParseFile(CTX.sessionrc_filename);
  ParseFile(CTX.optionsrc_filename);

  // Get command line options

  TheFileNameTab[0] = CTX.default_filename ;
  *nbfiles = 0;
  
  while (i < argc) {
    
    if (argv[i][0] == '-') {
      
      if(!strcmp(argv[i]+1, "a")){ 
        CTX.initial_context = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "g")){ 
        CTX.initial_context = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "m")){ 
        CTX.initial_context = 2; i++;
      }
      else if(!strcmp(argv[i]+1, "s")){ 
        CTX.initial_context = 3; i++;
      }
      else if(!strcmp(argv[i]+1, "p")){ 
        CTX.initial_context = 4; i++;
      }
      else if(!strcmp(argv[i]+1, "0")){ 
        CTX.batch = -1; i++;
      }
      else if(!strcmp(argv[i]+1, "1")){ 
        CTX.batch = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "2")){ 
        CTX.batch = 2; i++;
      }
      else if(!strcmp(argv[i]+1, "3")){ 
        CTX.batch = 3; i++;
      }
      else if(!strcmp(argv[i]+1, "extrude")){ //old extrusion mesh generator
        CTX.mesh.oldxtrude = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "recombine")){ //old extrusion mesh generator
        CTX.mesh.oldxtrude_recombine = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "histogram")){ 
        CTX.mesh.histogram = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "o")){ 
        i++;
        if(argv[i] != NULL) CTX.output_filename = argv[i++];
        else {    
          fprintf(stderr, ERROR_STR "Missing file name\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "bgm")){ 
        i++;
        if(argv[i] != NULL) TheBgmFileName = argv[i++];
        else {    
          fprintf(stderr, ERROR_STR "Missing file name\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "constrain")){ 
	CTX.mesh.constrained_bgmesh = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "convert")){ 
	i++;
	CTX.terminal = 1;
	if(argv[i] && argv[i+1]){
	  ParseFile(argv[i]);
	  if(List_Nbr(Post_ViewList))
	    Write_View(1,(Post_View*)List_Pointer(Post_ViewList, 0),argv[i+1]);
	  else
	    fprintf(stderr, ERROR_STR "No view to convert\n");
	}
	else
	  fprintf(stderr, "Usage: %s -convert view.ascii view.binary\n", argv[0]);
	exit(1);
      }
      else if(!strcmp(argv[i]+1, "old")){ 
        CTX.geom.old_circle = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "quality")){
        i++;
        if(argv[i]!=NULL) CTX.mesh.quality = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "scale")){
        i++;
        if(argv[i]!=NULL) CTX.geom.scaling_factor = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "meshscale")){
        i++;
        if(argv[i]!=NULL) CTX.mesh.scaling_factor = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "rand")){
        i++;
        if(argv[i]!=NULL) CTX.mesh.rand_factor = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "clscale")){
        i++;
        if(argv[i]!=NULL){
          CTX.mesh.lc_factor = atof(argv[i++]);
          if(CTX.mesh.lc_factor <= 0.0){
            fprintf(stderr, ERROR_STR 
                    "Characteristic length factor must be > 0\n");
            exit(1);
          }
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "smooth")){ 
        i++;
        if(argv[i]!=NULL) CTX.mesh.nb_smoothing = atoi(argv[i++]);
        else{
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "degree")){  
        i++;
        if(argv[i]!=NULL){
          CTX.mesh.degree = atoi(argv[i++]);
          if(CTX.mesh.degree != 1 && CTX.mesh.degree != 2){
            fprintf(stderr, ERROR_STR "Wrong degree\n");
            exit(1);
          }
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
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
            fprintf(stderr, ERROR_STR "Unknown mesh format\n");
            exit(1);
          }
          i++;
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing format\n");
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
            fprintf(stderr, ERROR_STR "Unknown mesh algorithm\n");
            exit(1);
          }
          i++;
        }
        else {    
          fprintf(stderr, ERROR_STR "Missing algorithm\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "version") || 
              !strcmp(argv[i]+1, "-version")){
        fprintf(stderr, "%.2f\n", GMSH_VERSION);
        exit(1);
      }
      else if(!strcmp(argv[i]+1, "info") || 
              !strcmp(argv[i]+1, "-info")){
        fprintf(stderr, "%s%.2f\n", gmsh_version, GMSH_VERSION);
        fprintf(stderr, "%s\n", gmsh_os);
#if _XMOTIF
        fprintf(stderr, "%s%s\n", gmsh_gui, XmVERSION_STRING);
#elif _FLTK
        fprintf(stderr, "%sFLTK %d.%d.%d\n", gmsh_gui, FL_MAJOR_VERSION, 
		FL_MINOR_VERSION, FL_PATCH_VERSION);
#else
        fprintf(stderr, "%snone\n", gmsh_gui);
#endif
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
	CTX.terminal = 1 ;
        Print_Usage(argv[0]);
        exit(1);
      }
      else if(!strcmp(argv[i]+1, "v")){  
        i++;
        if(argv[i]!=NULL) CTX.verbosity = atoi(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
#ifndef _BLACKBOX
      else if(!strcmp(argv[i]+1, "noterm")){ 
        CTX.terminal = 0; i++;
      }
      else if(!strcmp(argv[i]+1, "term")){ 
        CTX.terminal = 1; i++;
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
      else if(!strcmp(argv[i]+1, "dual")){ 
        CTX.mesh.dual = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "samevisual")){ 
        CTX.same_visual = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "interactive")){ 
        CTX.mesh.interactive = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "noview")){ 
        opt_view_visible(0, GMSH_SET, 0); i++;
      }
      else if(!strcmp(argv[i]+1, "plug")){ 
	opt_general_default_plugins(0, GMSH_SET, 1); i++;
      }
      else if(!strcmp(argv[i]+1, "link")){ 
        CTX.post.link = 2 ; i++;
      }
      else if(!strcmp(argv[i]+1, "fill")){ 
        opt_view_intervals_type(0, GMSH_SET, DRAW_POST_CONTINUOUS) ; i++;
      }
      else if(!strcmp(argv[i]+1, "nbiso")){ 
        i++ ;
        if(argv[i]!=NULL)
	  opt_view_nb_iso(0, GMSH_SET, atoi(argv[i++]));
        else{
          fprintf(stderr, ERROR_STR "Missing number\n");
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
      else if(!strcmp(argv[i]+1, "hh")){ 
        CTX.overlay = 0 ; CTX.geom.highlight = 1; i++;
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
      else if(!strcmp(argv[i]+1, "fontsize")){
        i++;
        if(argv[i]!=NULL){
	  CTX.fontsize = atoi(argv[i]);
          i++;
	}
        else {    
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "display")){
        i++;
        if(argv[i]!=NULL){
	  CTX.display = argv[i];
          i++;
	}
        else {    
          fprintf(stderr, ERROR_STR "Missing argument\n");
          exit(1);
        }
      }
#endif // !_BLACKBOX


      else{
        fprintf(stderr, "Unknown option '%s'\n", argv[i]);
	CTX.terminal = 1 ;
        Print_Usage(argv[0]);
        exit(1);
      }
    }

    else {
      if(*nbfiles < MAX_OPEN_FILES)
        TheFileNameTab[(*nbfiles)++] = argv[i++]; 
      else{
        fprintf(stderr, ERROR_STR "Too many input files\n");
        exit(1);
      }
    }

  }

  strncpy(CTX.filename, TheFileNameTab[0], NAME_STR_L);

}

