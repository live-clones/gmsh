// $Id: Main.cpp,v 1.1 2001-02-17 22:08:53 geuzaine Exp $

#include <signal.h>

#include "Gmsh.h"
#include "GmshVersion.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "Parser.h"
#include "Context.h"
#include "OpenFile.h"
#include "GetOptions.h"
#include "MinMax.h"
#include "Static.h"

/* dummy defs for link purposes */

void AddViewInUI(int, char *, int){}
void draw_polygon_2d (double, double, double, int, double *, double *, double *){}
void set_r(int, double){}
void Draw(void){}
void DrawUI(void){}
void Replot(void){}
void CreateOutputFile(char *, int){}

/* ------------------------------------------------------------------------ */
/*  I n f o                                                                 */
/* ------------------------------------------------------------------------ */

void Info (int level, char *arg0){
  switch(level){
  case 0 :
    fprintf(stderr, "%s\n", gmsh_progname);
    fprintf(stderr, "%s\n", gmsh_copyright);
    Print_Options(arg0);
    exit(1);
  case 1:
    fprintf(stderr, "%.2f\n", GMSH_VERSION);
    exit(1) ; 
  case 2:
    fprintf(stderr, "%s%.2f\n", gmsh_version, GMSH_VERSION);
    fprintf(stderr, "%s\n", gmsh_os);
    fprintf(stderr, "%s\n", gmsh_date);
    fprintf(stderr, "%s\n", gmsh_host);
    fprintf(stderr, "%s\n", gmsh_packager);
    fprintf(stderr, "%s\n", gmsh_url);
    fprintf(stderr, "%s\n", gmsh_email);
    exit(1) ; 
  default :
    break;
  }
}

/* ------------------------------------------------------------------------ */
/*  m a i n                                                                 */
/* ------------------------------------------------------------------------ */

int main(int argc, char *argv[]){
  int     i, nbf;

  Init_Context(0);
  Get_Options(argc, argv, &nbf);

  signal(SIGINT,  Signal); 
  signal(SIGSEGV, Signal);
  signal(SIGFPE,  Signal); 

  OpenProblem(CTX.filename);
  if(yyerrorstate)
    exit(1);
  else{
    if(nbf>1){
      for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    }
    if(TheBgmFileName){
      MergeProblem(TheBgmFileName);
      if(List_Nbr(Post_ViewList))
        BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
      else
        fprintf(stderr, ERROR_STR "Invalid BGM (no view)\n"); exit(1);
    }
    if(CTX.interactive > 0){
      mai3d(THEM, CTX.interactive);
      Print_Mesh(THEM,NULL,CTX.mesh.format);
    }
    exit(1);
  }    

}


/* ------------------------------------------------------------------------ */
/*  S i g n a l                                                             */
/* ------------------------------------------------------------------------ */


void Signal (int sig_num){

  switch (sig_num){
  case SIGSEGV : Msg(FATAL, "Segmentation Violation (Invalid Memory Reference)"); break;
  case SIGFPE  : Msg(FATAL, "Floating Point Exception (Division by Zero?)"); break;
  case SIGINT  : Msg(FATAL, "Interrupt (Generated from Terminal Special Char)"); break;
  default      : Msg(FATAL, "Unknown Signal"); break;
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

  case FATAL :
  case FATAL1 :
  case FATAL2 :
  case FATAL3 :
    fprintf(stderr, FATAL_STR);
    vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    abort = 1 ;
    break ;

  case GERROR :
  case GERROR1 :
  case GERROR2 :
  case GERROR3 :
    fprintf(stderr, ERROR_STR);
    vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    abort = 1 ;
    break ;

  case WARNING :
  case WARNING1 :
  case WARNING2 :
  case WARNING3 :
    fprintf(stderr, WARNING_STR);
    vfprintf(stderr, fmt,args); fprintf(stderr, "\n");
    break;

  case PARSER_ERROR :
    fprintf(stderr, PARSER_ERROR_STR); 
    vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    break ;

  case PARSER_INFO :
    if(CTX.verbosity == 5){
      fprintf(stderr, PARSER_INFO_STR);
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break ;

  case DIRECT :
    vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    break;

  default :
    if(CTX.verbosity == 5){
      fprintf(stderr, INFO_STR);
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

void   AddALineInTheEditGeometryForm (char* line){
};
