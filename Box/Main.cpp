// $Id: Main.cpp,v 1.6 2001-08-08 15:36:09 remacle Exp $

#include <signal.h>
#include "ParUtil.h"

#include <signal.h>
#if !defined(WIN32) || defined(__CYGWIN__)
#include <sys/resource.h>
#endif

#include "Gmsh.h"
#include "GmshVersion.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "Parser.h"
#include "Context.h"
#include "Options.h"
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
    Print_Usage(arg0);
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

  ParUtil::Instance()->init(argc,argv);

  if(argc < 2) Info(0,argv[0]);

  Init_Options(0);

  Get_Options(argc, argv, &nbf);

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

  signal(SIGINT,  Signal);
  signal(SIGSEGV, Signal);
  signal(SIGFPE,  Signal);

  OpenProblem(CTX.filename);
  if(yyerrorstate)
    ParUtil::Instance()->Abort();
  else{
    for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    if(TheBgmFileName){
      MergeProblem(TheBgmFileName);
      if(List_Nbr(Post_ViewList))
        BGMWithView((Post_View*)List_Pointer(Post_ViewList, List_Nbr(Post_ViewList)-1));
      else
        fprintf(stderr, ERROR_STR "Invalid background mesh (no view)\n"); exit(1);
    }
    if(CTX.batch > 0){
      mai3d(THEM, CTX.batch);
      Print_Mesh(THEM,CTX.output_filename,CTX.mesh.format);
    }
    else
      Print_Geo(THEM, CTX.output_filename);
    if(CTX.mesh.histogram)
      Print_Histogram(THEM->Histogram[0]);
    ParUtil::Instance()->Exit();
  }

}


/* ------------------------------------------------------------------------ */
/*  S i g n a l                                                             */
/* ------------------------------------------------------------------------ */


void Signal (int sig_num){

  switch (sig_num){
  case SIGSEGV : Msg(FATAL, "Segmentation violation (invalid memory reference)"); break;
  case SIGFPE  : Msg(FATAL, "Floating point exception (division by zero?)"); break;
  case SIGINT  : Msg(FATAL, "Interrupt (generated from terminal special char)"); break;
  default      : Msg(FATAL, "Unknown signal"); break;
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

  case DIRECT :
    vfprintf(stdout, fmt, args); fprintf(stdout, "\n");
    break;

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

  case DEBUG    :		     	  
  case DEBUG1   : 
  case DEBUG2   :		     	  
  case DEBUG3   : 
    if(CTX.verbosity > 2){
      fprintf(stderr, DEBUG_STR);
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break;

  default :
    if(CTX.verbosity > 0){
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

void GetResources(long *s, long *us, long *mem){
#if !defined(WIN32) || defined(__CYGWIN__)
  static struct rusage r;

  getrusage(RUSAGE_SELF,&r);
  *s   = (long)r.ru_utime.tv_sec ;
  *us  = (long)r.ru_utime.tv_usec ;
  *mem = (long)r.ru_maxrss ;
#else
  *s = *us = *mem = 0;
#endif

}

double Cpu(void){
  long s, us, mem;
  GetResources(&s, &us, &mem);
  return (double)s + (double)us/1.e6 ;
}

/* ------------------------------------------------------------------------ */
/*  P r o g r e s s                                                         */
/* ------------------------------------------------------------------------ */

void Progress(int i){
}

void   AddALineInTheEditGeometryForm (char* line){
};
