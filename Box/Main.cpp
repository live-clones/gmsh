// $Id: Main.cpp,v 1.14 2001-12-05 10:53:11 geuzaine Exp $

#include <signal.h>
#include "ParUtil.h"

#include <signal.h>
#if !defined(WIN32) || defined(__CYGWIN__)
#include <sys/resource.h>
#endif

#include "PluginManager.h"
#include "Gmsh.h"
#include "GmshVersion.h"
#include "Numeric.h"
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
    if(ParUtil::Instance()->master())
      {
	fprintf(stderr, "%s\n", gmsh_progname);
	fprintf(stderr, "%s\n", gmsh_copyright);
	Print_Usage(arg0);
      }
    ParUtil::Instance()->Exit();
  case 1:
    if(ParUtil::Instance()->master())
      fprintf(stderr, "%d.%d.%d\n", GMSH_MAJOR_VERSION, GMSH_MINOR_VERSION, 
	      GMSH_PATCH_VERSION);
    ParUtil::Instance()->Exit();
  case 2:
    if(ParUtil::Instance()->master())
      {
	fprintf(stderr, "%s%d.%d.%d\n", gmsh_version, GMSH_MAJOR_VERSION, 
		GMSH_MINOR_VERSION, GMSH_PATCH_VERSION);
	fprintf(stderr, "%s\n", gmsh_os);
	fprintf(stderr, "%s\n", gmsh_date);
	fprintf(stderr, "%s\n", gmsh_host);
	fprintf(stderr, "%s\n", gmsh_packager);
	fprintf(stderr, "%s\n", gmsh_url);
	fprintf(stderr, "%s\n", gmsh_email);
      }
    ParUtil::Instance()->Exit();
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

  Init_Options(0);

  if(argc < 2) Info(0,argv[0]);

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

  if(CTX.default_plugins)
    GMSH_PluginManager::Instance()->RegisterDefaultPlugins();

  OpenProblem(CTX.filename);
  if(yyerrorstate)
    ParUtil::Instance()->Abort();
  else{
    for(i=1;i<nbf;i++) MergeProblem(TheFileNameTab[i]);
    if(TheBgmFileName){
      MergeProblem(TheBgmFileName);
      if(List_Nbr(CTX.post.list))
        BGMWithView((Post_View*)List_Pointer(CTX.post.list, List_Nbr(CTX.post.list)-1));
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
    ParUtil::Instance()->Barrier(__LINE__,__FILE__);
    ParUtil::Instance()->Exit();
    return 1;
  }
  ParUtil::Instance()->Barrier(__LINE__,__FILE__);
  ParUtil::Instance()->Exit();
  return 1;
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
    if(CTX.verbosity >=2 && ParUtil::Instance()->master()) {
     vfprintf(stdout, fmt, args); fprintf(stdout, "\n");
    }
    break;

  case FATAL :
  case FATAL1 :
  case FATAL2 :
  case FATAL3 :
    fprintf(stderr,"On processor %d : ", ParUtil::Instance()->rank());
    fprintf(stderr, FATAL_STR);
    vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    abort = 1 ;
    break ;

  case GERROR :
  case GERROR1 :
  case GERROR2 :
  case GERROR3 :
    fprintf(stderr,"On processor %d : ", ParUtil::Instance()->rank());
    fprintf(stderr, ERROR_STR);
    vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    break ;

  case WARNING :
  case WARNING1 :
  case WARNING2 :
  case WARNING3 :
    if(CTX.verbosity >= 1){
      fprintf(stderr,"On processor %d : ", ParUtil::Instance()->rank());
      fprintf(stderr, WARNING_STR);
      vfprintf(stderr, fmt,args); fprintf(stderr, "\n");
    }
    break;

  case PARSER_ERROR :
    if(ParUtil::Instance()->master()){
      fprintf(stderr, PARSER_ERROR_STR); 
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break ;

  case PARSER_INFO :
    if(CTX.verbosity >= 2 && ParUtil::Instance()->master()){
      fprintf(stderr, PARSER_INFO_STR);
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break ;

  case DEBUG    :		     	  
  case DEBUG1   : 
  case DEBUG2   :		     	  
  case DEBUG3   : 
    if(CTX.verbosity >= 3 && ParUtil::Instance()->master()){
      fprintf(stderr, DEBUG_STR);
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    break;

  default :
    if(CTX.verbosity >= 1 && ParUtil::Instance()->master()){
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
