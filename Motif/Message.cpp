// $Id: Message.cpp,v 1.5 2001-01-24 11:24:06 geuzaine Exp $

#include <signal.h>
#include <sys/resource.h>

#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"
#include "Context.h"
#include "Widgets.h"

extern Context_T   CTX;
extern Widgets_T   WID;

/* ------------------------------------------------------------------------ */
/*  S i g n a l                                                             */
/* ------------------------------------------------------------------------ */

void Signal (int sig_num){

  switch (sig_num){
  case SIGSEGV : 
    Msg(FATAL, "Segmentation Violation (Invalid Memory Reference)\n"
        "------------------------------------------------------\n"
        "You have discovered a bug in Gmsh. You may e-mail the\n"
        "context in which it occurred to one of the authors:\n"
        "type 'gmsh -info' to get feedback information"); 
    break;
  case SIGFPE : 
    Msg(FATAL, "Floating Point Exception (Division by Zero?)"); 
    break;
  case SIGINT :
    Msg(FATAL, "Interrupt (Generated from Terminal Special Character)"); 
    break;
  default :
    Msg(FATAL, "Unknown Signal");
    break;
  }
}


/* ------------------------------------------------------------------------ */
/*  M s g                                                                   */
/* ------------------------------------------------------------------------ */

char *TextBuffer;

#define PUT_IN_COMMAND_WIN                                              \
  vsprintf(TextBuffer, fmt, args);                                      \
  XmListAddItem(WID.C.commandList,XmStringCreateSimple(TextBuffer),0);  \
  XtSetArg(arg[0], XmNitemCount, &nb);                                  \
  XtSetArg(arg[1], XmNvisibleItemCount, &nbvis);                        \
  XtGetValues(WID.C.commandList, arg, 2);                               \
  XmListSetPos(WID.C.commandList,(nb>nbvis)?nb-nbvis+1:0);              \
  XmUpdateDisplay(WID.C.commandList);

void Msg(int level, char *fmt, ...){
  va_list  args;
  int      abort=0;
  Arg      arg[2];
  int      nb, nbvis;

  if(level != FATAL && level != GERROR && level != PARSER_ERROR &&
     CTX.interactive && !CTX.verbosity) 
    return ;

  va_start (args, fmt);

  switch(level){
  case FATAL :
    fprintf(stderr, FATAL_STR);
    vfprintf(stderr, fmt, args); 
    fprintf(stderr, "\n");
    abort = 1; 
    break;
  case GERROR :
    if(CTX.interactive || !CTX.command_win){
      fprintf(stderr, ERROR_STR);
      vfprintf(stderr, fmt, args); 
      fprintf(stderr, "\n");
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;
  case WARNING :
    if(CTX.interactive || !CTX.command_win){
      if(CTX.verbosity > 0){
        fprintf(stderr, WARNING_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;
  case INFO :
    if(CTX.interactive || !CTX.command_win){
      if(CTX.verbosity > 1){
        fprintf(stderr, INFO_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;
  case STATUS2 :
  case STATUS2N :
    if(CTX.interactive){
      if(CTX.verbosity > 1){
        fprintf(stderr, STATUS_STR);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
      }
    }
    else{
      vsprintf(TextBuffer, fmt, args);
      XtVaSetValues(WID.G.infoLabel, XmNlabelString,
                    XmStringCreateSimple(TextBuffer), NULL);
      XmUpdateDisplay(WID.G.infoLabel);
    }
    break;
  case STATUS1 :
  case STATUS1N :
    if(CTX.interactive){
      if(CTX.verbosity > 1){
        fprintf(stderr, STATUS_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      vsprintf(TextBuffer, fmt, args);
      XtVaSetValues(WID.G.selectLabel, XmNlabelString, 
                    XmStringCreateSimple(TextBuffer), NULL);
      XmUpdateDisplay(WID.G.selectLabel);
    }
    break;
  case STATUS3 :
  case STATUS3N :
    if(CTX.interactive){
      if(CTX.verbosity > 1){
        fprintf(stderr, STATUS_STR);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
      }
    }
    else{
      vsprintf(TextBuffer, fmt, args);
      XtVaSetValues(WID.G.statusLabel, XmNlabelString,
                    XmStringCreateSimple(TextBuffer), NULL);
      XmUpdateDisplay(WID.G.statusLabel);
    }
    break;
  case PARSER_ERROR :
    if(CTX.interactive || !CTX.command_win){
      if(CTX.verbosity > 0){
        fprintf(stderr, PARSER_ERROR_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;
  case PARSER_INFO :
    if(CTX.interactive || !CTX.command_win){
      if(CTX.verbosity > 1){
        fprintf(stderr, PARSER_INFO_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;
  case DEBUG :
    if(CTX.interactive || !CTX.command_win){
      if(CTX.verbosity > 2){
        fprintf(stderr, DEBUG_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      PUT_IN_COMMAND_WIN ;
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
  fprintf(stream, "Resources = %scpu %ld.%ld s / mem %ld kb\n", fmt, s, us, mem);
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

/* ------------------------------------------------------------------------ */
/*  E d i t G e o m e t r y                                                 */
/* ------------------------------------------------------------------------ */

void AddALineInTheEditGeometryForm (char* line){
}
