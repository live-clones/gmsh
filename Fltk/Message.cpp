// $Id: Message.cpp,v 1.7 2001-01-12 00:43:05 geuzaine Exp $

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
    Msg(FATAL1, "Segmentation Violation (Invalid Memory Reference)");
    Msg(FATAL2, "------------------------------------------------------");
    Msg(FATAL2, "You have discovered a bug in Gmsh. You may e-mail the");
    Msg(FATAL2, "context in which it occurred to one of the authors:");
    Msg(FATAL3, "type 'gmsh -info' to get feedback information"); 
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
  int      abort=0, verb;
  char     *str;
  static char buff1[1024], buff2[1024];

  if(level != FATAL && level != GERROR && level != PARSER_ERROR &&
     CTX.interactive && !CTX.verbosity) 
    return ;

  WID->check();

  va_start (args, fmt);

  switch(level){
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
    va_end (args);
    return ;
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
    va_end (args);
    return ;
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
    va_end (args);
    return ;
  }

  switch(level){
  case FATAL : str = FATAL_STR ; abort = 1; verb=0; break ;
  case FATAL1 : str = FATAL_STR ; abort = 0; verb=0; break ;
  case FATAL2 : str = FATAL_NIL ; abort = 0; verb=0; break ;
  case FATAL3 : str = FATAL_NIL ; abort = 1; verb=0; break ;
  case GERROR :
  case GERROR1 : str = ERROR_STR ; verb = 0; break ;
  case GERROR2 : 
  case GERROR3 : str = ERROR_NIL ; verb = 0; break ;
  case WARNING : 
  case WARNING1 : str = WARNING_STR ; verb = 1; break ;
  case WARNING2 : 
  case WARNING3 : str = WARNING_NIL ; verb = 1; break ;
  case INFOS :
  case INFOS1 : str = INFOS_STR ; verb = 2; break ;
  case INFOS2 :
  case INFOS3 : str = INFOS_NIL ; verb = 2; break ;
  case PARSER_ERROR : str = PARSER_ERROR_STR ; verb = 0; break ;
  case PARSER_INFO : str = PARSER_INFO_STR ; verb = 2; break ;
  case DEBUG :
  case DEBUG1 : str = DEBUG_STR ; verb = 3; break ;
  case DEBUG2 :
  case DEBUG3 : str = DEBUG_NIL ; verb = 3; break ;
  default : str = NULL ; verb = 3; break ;
  }

  if(CTX.verbosity >= verb){
    strcpy(buff1, "@C1");
    if(str) strcat(buff1, str);
    vsprintf(buff2, fmt, args); 
    strcat(buff1,buff2);
    fprintf(stderr, "%s\n", &buff1[3]);
    if(!CTX.interactive){
      if(verb<2)
	WID->add_message(buff1);
      else
	WID->add_message(&buff1[3]);
    }
  }

  va_end (args);

  if(!verb) WID->create_message_window();

  if(abort){
    WID->save_message("error.log");
    exit(1);
  }
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
