// $Id: GetOptions.cpp,v 1.4 2001-01-13 15:41:35 geuzaine Exp $

#include "Gmsh.h"
#include "GmshVersion.h"
#include "Const.h"
#include "Context.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "OpenFile.h"

extern Context_T  CTX;

char  *TheFileNameTab[MAX_OPEN_FILES];
char  *TheBgmFileName=NULL;
char   ThePathForIncludes[NAME_STR_L];

char gmsh_progname[]  = "This is Gmsh" ;
char gmsh_copyright[] = "Copyright (C) 1997-2001 J.-F. Remacle, C. Geuzaine";
char gmsh_version[]   = "Version          : " ;
char gmsh_os[]        = "Operating System : " GMSH_OS ;
char gmsh_date[]      = "Build Date       : " GMSH_DATE ;
char gmsh_host[]      = "Build Host       : " GMSH_HOST ;
char gmsh_packager[]  = "Packager         : " GMSH_PACKAGER ;
char gmsh_url[]       = "URL              : http://www.geuz.org/gmsh/" ;
char gmsh_email[]     = "E-Mail           : Christophe.Geuzaine@ulg.ac.be\n"
                        "                   Remacle@scorec.rpi.edu" ;
char gmsh_options[]   =
  "Usage: %s [options] [files]\n"
  "Geometry options:\n"
  "  -0                    parse input files, output flattened geometry, and exit\n"
  "Mesh options:\n"
  "  -1, -2, -3            perform batch 1D, 2D and 3D mesh generation\n"
  "  -format msh|unv|gref  set output mesh format (default: msh)\n"
  "  -algo iso|aniso       select 2D mesh algorithm (default: iso)\n"
  "  -smooth int           set mesh smoothing (default: 0)\n"
  "  -degree int           set mesh degree (default: 1)\n"
  "  -scale float          set global scaling factor (default: 1.0)\n"
  "  -meshscale float      set mesh scaling factor (default: 1.0)\n"
  "  -clscale float        set characteristic length scaling factor (default: 1.0)\n"
  "  -rand float           set random perturbation factor (default: 1.e-5)\n"
  "  -bgm file             load backround mesh from file\n"
#ifndef _BLACKBOX
  "  -interactive          display 2D mesh construction interactively\n"
  "Post Processing options:\n"
  "  -dl                   enable display lists\n"
  "  -noview               hide all views on startup\n"
  "  -link                 link all views on startup\n"
  "Display options:\n"    
  "  -nodb                 disable double buffering\n"
  "  -noov                 disable overlay visual\n"
  "  -fontsize int         size of the font for the user interface (default: 12)\n"
  "  -alpha                enable alpha blending\n"
  "  -notrack              don't use trackball mode for rotations\n"
  "  -display string       specify display\n"
  "  -perspective          set projection mode to perspective\n"
  "  -flash                allow colormap flashing\n"
  "  -samevisual           force same visual for graphics and UI\n"
#endif
  "Other options:\n"      
#ifndef _BLACKBOX
  "  -v int                set verbosity level (default: 2)\n"
#else
  "  -v                    be verbose\n"
#endif
  "  -nothreads            disable threads\n"
  "  -path string          set path for included files\n"
  "  -version              show version number\n"
  "  -info                 show detailed version information\n"
  "  -help                 show this message\n"
  ;


void Get_Options (int argc, char *argv[], int *nbfiles) {
  int i=1;

#ifdef _BLACKBOX
  void Info (int level, char *arg0);
  if(argc < 2) Info(0,argv[0]);
#endif

  // Get default options in the configuration file
  // we should do something more clever here (in $HOME?)
  CTX.configfilename = ".gmshrc"; 
  ParseFile(CTX.configfilename);

  // Get command line options

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
      else if(!strcmp(argv[i]+1, "old")){ 
        CTX.geom.old_circle = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "quality")){
        i++;
        if(argv[i]!=NULL) CTX.mesh.quality = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "scale")){
        i++;
        if(argv[i]!=NULL) CTX.geom.scaling_factor = atof(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i]+1, "meshscale")){
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
      else if(!strcmp(argv[i]+1, "version") || 
              !strcmp(argv[i]+1, "-version")){
        fprintf(stderr, "%.2f\n", GMSH_VERSION);
        exit(1);
      }
      else if(!strcmp(argv[i]+1, "info") || 
              !strcmp(argv[i]+1, "-info")){
        fprintf(stderr, "%s%.2f\n", gmsh_version, GMSH_VERSION);
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
        fprintf(stderr, gmsh_options, argv[0]);
        exit(1);
      }


#ifdef _BLACKBOX
      else if(!strcmp(argv[i]+1, "v")){ 
        CTX.verbosity = 5; i++;
      }
#else
      else if(!strcmp(argv[i]+1, "v")){  
        i++;
        if(argv[i]!=NULL) CTX.verbosity = atoi(argv[i++]);
        else {    
          fprintf(stderr, ERROR_STR "Missing Number\n");
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
        CTX.post.initial_visibility = 0 ; i++;
      }
      else if(!strcmp(argv[i]+1, "link")){ 
        CTX.post.link = 2 ; i++;
      }
      else if(!strcmp(argv[i]+1, "fill")){ 
        CTX.post.initial_intervals = DRAW_POST_CONTINUOUS ; i++;
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
          fprintf(stderr, ERROR_STR "Missing Number\n");
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
          fprintf(stderr, ERROR_STR "Missing Argument\n");
          exit(1);
        }
      }
#endif // _BLACKBOX


      else{
        fprintf(stderr, "Unknown Option '%s'\n", argv[i]);
        fprintf(stderr, gmsh_options, argv[0]);
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

  strncpy(CTX.filename, TheFileNameTab[0], NAME_STR_L);

}

