// $Id: Message.cpp,v 1.4 2001-01-10 08:50:29 geuzaine Exp $

#include <signal.h>
#ifndef WIN32
#include <sys/resource.h>
#endif

#include "Gmsh.h"
#include "GmshUI.h"
#include "Version.h"
#include "Context.h"
#include "GUI.h"

extern GUI       *WID;
extern Context_T  CTX;

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

#define PUT_IN_COMMAND_WIN			\
    vfprintf(stderr, fmt, args); 		\
    fprintf(stderr, "\n");

void Msg(int level, char *fmt, ...){
  va_list  args;
  int      abort=0;

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
  case INFOS :
    if(CTX.interactive || !CTX.command_win){
      if(CTX.verbosity > 1){
        fprintf(stderr, INFOS_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      PUT_IN_COMMAND_WIN ;
    }
    break;
  case INFO :
    if(CTX.interactive){
      if(CTX.verbosity > 1){
        fprintf(stderr, INFO_STR);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
      }
    }
    else{
      static char buffer[128];
      vsprintf(buffer, fmt, args);
      WID->set_status(buffer, 1) ;
    }
    break;
  case SELECT :
    if(CTX.interactive){
      if(CTX.verbosity > 1){
        fprintf(stderr, SELECT_STR);
        vfprintf(stderr, fmt, args); 
        fprintf(stderr, "\n");
      }
    }
    else{
      static char buffer[128];
      vsprintf(buffer, fmt, args);
      WID->set_status(buffer, 0) ;
    }
    break;
  case STATUS :
    if(CTX.interactive){
      if(CTX.verbosity > 1){
        fprintf(stderr, STATUS_STR);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
      }
    }
    else{
      static char buffer[128];
      vsprintf(buffer, fmt, args);
      WID->set_status(buffer, 2) ;
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
#ifndef WIN32
  static struct rusage r;

  getrusage(RUSAGE_SELF,&r);
  *s   = (long)r.ru_utime.tv_sec ;
  *us  = (long)r.ru_utime.tv_usec ;
  *mem = (long)r.ru_maxrss ;
#else
  *s = *us = *mem = 0;
#endif

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
