
#include <signal.h>
#include <sys/resource.h>

#include "Gmsh.h"
#include "GmshUI.h"
#include "Version.h"
#include "Context.h"
#include "Widgets.h"

extern Context_T   CTX;
extern Widgets_T   WID;

/* ------------------------------------------------------------------------ */
/*  I n f o                                                                 */
/* ------------------------------------------------------------------------ */

extern char gmsh_progname[], gmsh_version[], gmsh_os[], gmsh_date[];
extern char gmsh_host[], gmsh_packager[], gmsh_email[], gmsh_url[];
extern char gmsh_copyright[] ;

char clargs[]    = 
  "Usage: %s [options] [files]\n"
  "Mesh options:\n"
  "  -0                    parse input and exit\n"
  "  -1, -2, -3            batch 1-, 2- or 3-dimensional mesh\n"
  "  -format msh|unv       mesh format (default: msh)\n"
  "  -algo iso|aniso       mesh algorithm (default: iso)\n"
  "  -smooth int           mesh smoothing (default: 0)\n"
  "  -degree int           mesh degree (default: 1)\n"
  "  -scale float          scaling factor (default: 1.0)\n"
  "  -bgm file             load backround mesh from file\n"
  "  -interactive          display the mesh construction\n"
  "Post Processing options:\n"
  "  -dl                   enable display lists\n"
  "  -noview               hide all views at startup\n"
  "Display options:\n"	  
  "  -nodb                 no double buffer\n"
  "  -noov                 no overlay visual\n"
  "  -alpha                enable alpha blending\n"
  "  -visinfo              show visual information at startup\n"
  "  -geometry geom        specify main window geometry\n"
  "  -viewport 9*float     specify rotation, translation and scale\n"
  "  -display disp         specify display\n"
  "  -perspective          perspective instead of orthographic projection\n"
  "  -flash                allow colormap flashing\n"
  "  -samevisual           force same visual for OpenGL and GUI\n"
  "Other options:\n"	  
  "  -threads              enable threads\n"
  "  -path string          path for included files\n"
  "  -version              show version number\n"
  "  -info                 show detailed version information\n"
  "  -help                 show this message\n"
  ;

void Info (int level, char *arg0){
  switch(level){
  case 0 :
    fprintf(stderr, "%s\n", gmsh_progname);
    fprintf(stderr, "%s\n", gmsh_copyright);
    fprintf(stderr, clargs, arg0);
    exit(1);
  case 1:
    fprintf(stderr, "%s%g\n", gmsh_version, GMSH_VERSION);
    fprintf(stderr, "%s\n", gmsh_os);
    fprintf(stderr, "%s\n", gmsh_date);
    fprintf(stderr, "%s\n", gmsh_host);
    fprintf(stderr, "%s\n", gmsh_packager);
    fprintf(stderr, "%s\n", gmsh_email);
    fprintf(stderr, "%s\n", gmsh_url);
    exit(1) ; 
  case 2 :
    fprintf(stderr, "%g\n", GMSH_VERSION);
    exit(1);
  default :
    break;
  }
}


/* ------------------------------------------------------------------------ */
/*  S i g n a l                                                             */
/* ------------------------------------------------------------------------ */


void Signal (int sig_num){

  switch (sig_num){
  case SIGSEGV : 
    Msg(ERROR, "Segmentation Violation (invalid memory reference)\n"
	"----------------------------------------------------------------------\n"
	"You have probably discovered a bug in Gmsh...\n"
	"You may e-mail the context in which it occurred to one of the authors.\n"
	"Type 'gmsh -version' to get feedback information.");
    break;
  case SIGFPE  : Msg(ERROR, "Floating point exception (division by zero?)"); break;
  case SIGINT  : Msg(ERROR, "Interrupt (generated from terminal special char)"); break;
  default      : Msg(ERROR, "Unknown signal"); break;
  }
}


/* ------------------------------------------------------------------------ */
/*  M s g                                                                   */
/* ------------------------------------------------------------------------ */

char *TextBuffer;

#define PUT_IN_COMMAND_WIN						\
  vsprintf(TextBuffer, fmt, args);					\
  XmListAddItem(WID.C.commandList,XmStringCreateSimple(TextBuffer),0);	\
  XtSetArg(arg[0], XmNitemCount, &nb);					\
  XtSetArg(arg[1], XmNvisibleItemCount, &nbvis);			\
  XtGetValues(WID.C.commandList, arg, 2);				\
  XmListSetPos(WID.C.commandList,(nb>nbvis)?nb-nbvis+1:0);		\
  XmUpdateDisplay(WID.C.commandList);

void Msg(int level, char *fmt, ...){
  va_list  args;
  int      abort=0;
  Arg      arg[2];
  int      nb, nbvis;

  va_start (args, fmt);

  switch(level){

  case PARSER_ERROR :
    if(CTX.interactive || !CTX.command_win){
      fprintf(stderr, "Parse Error: "); vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break ;

  case PARSER_INFO :
    if(CTX.interactive || !CTX.command_win){
      fprintf(stderr, "Parse Info: "); vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break ;

  case ERROR :
    if(CTX.interactive || !CTX.command_win){
      fprintf(stderr, "Error: "); vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
      abort = 1;
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break ;

  case WARNING :
    if(CTX.interactive || !CTX.command_win){
      fprintf(stderr, "Warning: "); vfprintf(stderr, fmt,args); fprintf(stderr, "\n");
    }
    else {
      PUT_IN_COMMAND_WIN ;
    }
    break;

  case INFOS :
    if(CTX.interactive || !CTX.command_win){
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;

  case INFO :
    if(CTX.interactive){
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    else{
      vsprintf(TextBuffer, fmt, args);
      XtVaSetValues(WID.G.infoLabel, XmNlabelString, XmStringCreateSimple(TextBuffer), NULL);
      XmUpdateDisplay(WID.G.infoLabel);
    }
    break;

  case SELECT :
    if(CTX.interactive){
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    else{
      vsprintf(TextBuffer, fmt, args);
      XtVaSetValues(WID.G.selectLabel, XmNlabelString, XmStringCreateSimple(TextBuffer), NULL);
      XmUpdateDisplay(WID.G.selectLabel);
    }
    break;

  case STATUS :
    if(CTX.interactive){
      vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
    }
    else{
      vsprintf(TextBuffer, fmt, args);
      XtVaSetValues(WID.G.statusLabel, XmNlabelString, XmStringCreateSimple(TextBuffer), NULL);
      XmUpdateDisplay(WID.G.statusLabel);
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
  static struct rusage r;

  getrusage(RUSAGE_SELF,&r);
  *s   = (long)r.ru_utime.tv_sec ;
  *us  = (long)r.ru_utime.tv_usec ;
  *mem = (long)r.ru_maxrss ;
}

void PrintResources(FILE *stream, char *fmt, long s, long us, long mem){
  fprintf(stream, "Resources: %scpu %ld.%ld s / mem %ld kb\n", fmt, s, us, mem);
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
