/* $Id: Box.cpp,v 1.4 2000-11-23 16:51:27 geuzaine Exp $ */

#include <signal.h>

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "Parser.h"
#include "Context.h"
#include "Main.h"
#include "MinMax.h"

#include "Static.h"

char *TheFileNameTab[MAX_OPEN_FILES];
char *ThePathForIncludes=NULL, *TheBgmFileName=NULL;
int   VERBOSE = 0 ;

char gmsh_progname[]  = "This is Gmsh (non-interactive)" ;
char gmsh_copyright[] = "Copyright (C) 1997-2000 J.-F. Remacle, C. Geuzaine";
char gmsh_version[]   = "Version          : " ;
char gmsh_os[]        = "Operating System : " GMSH_OS ;
char gmsh_date[]      = "Build Date       : " GMSH_DATE ;
char gmsh_host[]      = "Build Host       : " GMSH_HOST ;
char gmsh_packager[]  = "Packager         : " GMSH_PACKAGER ;
char gmsh_email[]     = "E-Mail           : " GMSH_EMAIL ;
char gmsh_url[]       = "URL              : " GMSH_URL ;
char gmsh_help[]      = 
  "Usage: %s [options] [files]\n"
  "Mesh options:\n"
  "  -0                    parse input and exit\n"
  "  -1, -2, -3            batch 1-, 2- or 3-dimensional mesh\n"
  "  -smooth int           mesh smoothing (default: 3)\n"
  "  -degree int           mesh degree (default: 1)\n"
  "  -format msh|unv|gref  mesh format (default: msh)\n"
  "  -algo iso|aniso       mesh algorithm (default: iso)\n"
  "  -scale float          scaling factor (default: 1.0)\n"
  "  -bgm file             load backround mesh from file\n"
  "Other options:\n"	  
  "  -v                    print debug information\n"
  "  -path string          set path for included files\n"
  "  -version              show version number\n"
  "  -info                 show detailed version information\n"
  "  -help                 show this message\n"
  ;


/* dummy defs for link purposes */

void color_table_init_param (int number, ColorTable * ct, int rgb_flag, int alpha_flag){;}
void color_table_recompute (ColorTable * ct, int rgb_flag, int alpha_flag){;}
void ZeroHighlight(Mesh *){;}
void AddView(int, char *, int){;}
void draw_polygon_2d (double, double, double, int, double *, double *, double *){;}

/* ------------------------------------------------------------------------ */
/*  p a r s e                                                               */
/* ------------------------------------------------------------------------ */

void ParseFile(char *f){
  strncpy(yyname,f,NAME_STR_L);
  yyerrorstate=0;
  yylineno=1;
  if(!(yyin = fopen(yyname,"r"))){
    Msg(INFO, "File '%s' dos not exist", f);
    return;
  }
  while(!feof(yyin)) yyparse();
  fclose(yyin);
}

void MergeProblem(char *name){
  Msg(INFOS, "Merging %s",name); 

  ParseFile(name);  
  if (yyerrorstate) return;
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

  Msg(INFOS, "Opening %s", TheFileName); 

  ParseFile(TheFileName);  

  mai3d(THEM,0);  
  
  Maillage_Dimension_0(&M);
  ZeroHighlight(&M); 
  CalculateMinMax(THEM->Points);  
}

/* ------------------------------------------------------------------------ */
/*  G e t _ O p t i o n s                                                   */
/* ------------------------------------------------------------------------ */

void Get_Options (int argc, char *argv[], int *nbfiles) {
  int i=1;

  if(argc < 2) Info(0,argv[0]);

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
      else if(!strcmp(argv[i]+1, "v")){ 
	VERBOSE = 1; i++;
      }
      else if(!strcmp(argv[i]+1, "path")){ 
	i++;
	if(argv[i] != NULL) ThePathForIncludes = argv[i++];
      }
      else if(!strcmp(argv[i]+1, "bgm")){ 
	i++;
	if(argv[i] != NULL) TheBgmFileName = argv[i++];
      }
      else if(!strcmp(argv[i]+1, "smooth")){ 
	i++;
	CTX.mesh.nb_smoothing = atoi(argv[i]); i++;
      }
      else if(!strcmp(argv[i]+1, "scale")){
	i++;
	GLOBALSCALINGFACTOR = atof(argv[i]); i++;
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
      else if(!strcmp(argv[i]+1, "format")){  
	i++;
	if(argv[i]!=NULL){
	  if(!strcmp(argv[i],"msh"))
	    CTX.mesh.format = FORMAT_MSH ;
	  else if(!strcmp(argv[i],"unv"))
	    CTX.mesh.format = FORMAT_UNV ;
	  else if(!strcmp(argv[i],"gref"))
	    CTX.mesh.format = FORMAT_GREF ;
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
	    CTX.mesh.algo = DELAUNAY_OLDALGO ;
	  else if(!strcmp(argv[i],"aniso"))
	    CTX.mesh.algo = DELAUNAY_NEWALGO ;
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
      else if(!strcmp(argv[i]+1, "info")){
	Info(2,argv[0]); 
      }
      else if(!strcmp(argv[i]+1, "version")){
	Info(1,argv[0]); 
      }
      else if(!strcmp(argv[i]+1, "help")){
	Info(0,argv[0]);
      }
      else{
	fprintf(stderr, "Warning: Unknown option '%s'\n", argv[i]);
	Info(0,argv[0]);
      }
    }

    else {
      if(*nbfiles < MAX_OPEN_FILES){
	TheFileNameTab[(*nbfiles)++] = argv[i++]; 
      }
      else{
	fprintf(stderr, "Error: Too many input files\n");
	exit(1);
      }
    }

  }

  strncpy(TheFileName, TheFileNameTab[0], NAME_STR_L);

}

/* ------------------------------------------------------------------------ */
/*  m a i n                                                                 */
/* ------------------------------------------------------------------------ */

int main(int argc, char *argv[]){
  int     i, nbf;

  InitContext(&CTX);
  Get_Options(argc, argv, &nbf);

  signal(SIGINT,  Signal); 
  signal(SIGSEGV, Signal);
  signal(SIGFPE,  Signal); 

  OpenProblem(TheFileName);
  if(yyerrorstate)
    exit(1);
  else{
    if(nbf>1){
      for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    }
    if(TheBgmFileName){
      MergeProblem(TheBgmFileName);
      if(List_Nbr(Post_ViewList)){
	BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
	TYPBGMESH = ONFILE; 
	Create_BgMesh(TYPBGMESH,.2,THEM);
      }
      else{
	fprintf(stderr, "Error: invalid BGM (no view)\n"); exit(1);
      }
    }
    if(CTX.interactive > 0){
      mai3d(THEM, CTX.interactive);
      Print_Mesh(THEM,NULL,CTX.mesh.format);
    }
    exit(1);
  }    

}



/* ------------------------------------------------------------------------ */
/*  I n f o                                                                 */
/* ------------------------------------------------------------------------ */

void Info (int level, char *arg0){
  switch(level){
  case 0 :
    fprintf(stderr, "%s\n", gmsh_progname);
    fprintf(stderr, "%s\n", gmsh_copyright);
    fprintf(stderr, gmsh_help, arg0);
    exit(1);
  case 1:
    fprintf(stderr, "%g\n", GMSH_VERSION);
    exit(1) ; 
  case 2:
    fprintf(stderr, "%s%g\n", gmsh_version, GMSH_VERSION);
    fprintf(stderr, "%s\n", gmsh_os);
    fprintf(stderr, "%s\n", gmsh_date);
    fprintf(stderr, "%s\n", gmsh_host);
    fprintf(stderr, "%s\n", gmsh_packager);
    fprintf(stderr, "%s\n", gmsh_email);
    fprintf(stderr, "%s\n", gmsh_url);
    exit(1) ; 
  default :
    break;
  }
}


/* ------------------------------------------------------------------------ */
/*  S i g n a l                                                             */
/* ------------------------------------------------------------------------ */


void Signal (int sig_num){

  switch (sig_num){
  case SIGSEGV : Msg(ERROR, "Segmentation Violation (invalid memory reference)"); break;
  case SIGFPE  : Msg(ERROR, "Floating point exception (division by zero?)"); break;
  case SIGINT  : Msg(ERROR, "Interrupt (generated from terminal special char)"); break;
  default      : Msg(ERROR, "Unknown signal"); break;
  }
}


/* ------------------------------------------------------------------------ */
/*  M s g                                                                   */
/* ------------------------------------------------------------------------ */

void Msg(int level, char *fmt, ...){
  va_list  args;
  int      abort=0;
  int      nb, nbvis;

  va_start (args, fmt);

  switch(level){

  case PARSER_ERROR :
    fprintf(stderr, "Parse Error: "); vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    break ;

  case PARSER_INFO :
    if(VERBOSE){
      fprintf(stderr, "Parse Info: "); vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break ;

  case ERROR :
    fprintf(stderr, "Error: "); vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    abort = 1 ;
    break ;

  case WARNING :
    fprintf(stderr, "Warning: "); vfprintf(stderr, fmt,args); fprintf(stderr, "\n");
    break;

  case INFOS :
  case INFO :
  case SELECT :
  case STATUS :
    if(VERBOSE){
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break;
  }

  va_end (args);

  if(abort) exit(1);

}

/* ------------------------------------------------------------------------ */
/*  C p u                                                                   */
/* ------------------------------------------------------------------------ */

double Cpu(void){
  return 0.;
}

/* ------------------------------------------------------------------------ */
/*  P r o g r e s s                                                         */
/* ------------------------------------------------------------------------ */

void Progress(int i){
}
