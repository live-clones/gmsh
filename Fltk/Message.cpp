// $Id: Message.cpp,v 1.36 2003-02-25 16:49:36 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>

#ifdef __APPLE__
#define   RUSAGE_SELF      0
#define   RUSAGE_CHILDREN -1
#endif

#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"
#include "Context.h"
#include "Options.h"
#include "GUI.h"

extern GUI       *WID;
extern Context_T  CTX;

// Handle signals. It is a crime to call stdio functions in a signal
// handler. But who cares? ;-)

void Signal (int sig_num){

  switch (sig_num){
  case SIGSEGV : 
    Msg(FATAL1, "Segmentation violation (invalid memory reference)");
    Msg(FATAL2, "------------------------------------------------------");
    Msg(FATAL2, "You have discovered a bug in Gmsh! You may report it");
    Msg(FATAL2, "by e-mail (together with any helpful data permitting to");
    Msg(FATAL3, "reproduce it) to <gmsh@geuz.org>"); 
    break;
  case SIGFPE : 
    Msg(FATAL, "Floating point exception (division by zero?)"); 
    break;
  case SIGINT :
    Msg(INFO, "Interrupt (generated from terminal special character)"); 
    Exit(1);
    break;
  default :
    Msg(FATAL, "Unknown signal");
    break;
  }
}

// General purpose message routine

void Debug(){
}

void Msg(int level, char *fmt, ...){
  va_list  args;
  int      abort = 0, verb = 0, window = -1, log = 1;
  char     *str = NULL;

  // *INDENT-OFF*
  switch(level){
  case DIRECT   : verb = 2; break ;

  case STATUS1N : log = 0; //fallthrough
  case STATUS1  : verb = 1; window = 0; break ;
  case STATUS2N : log = 0; //fallthrough
  case STATUS2  : verb = 1; window = 1; break ;
  case STATUS3N : log = 0; //fallthrough
  case STATUS3  : verb = 1; window = 2; break ;

  case FATAL    : str = FATAL_STR; abort = 1; break ;
  case FATAL1   : str = FATAL_STR; break ;
  case FATAL2   : str = FATAL_NIL; break ;
  case FATAL3   : str = FATAL_NIL; abort = 1; break ;
				     		  
  case GERROR   : 		     		  
  case GERROR1  : str = ERROR_STR; break ;
  case GERROR2  : 		     
  case GERROR3  : str = ERROR_NIL; break ;
				     	  
  case WARNING  : 		     	  
  case WARNING1 : str = WARNING_STR; verb = 1; break ;
  case WARNING2 : 		     	  
  case WARNING3 : str = WARNING_NIL; verb = 1; break ;
				     	  
  case INFO     :		     	  
  case INFO1    : str = INFO_STR; verb = 2; break ;
  case INFO2    :		     	  
  case INFO3    : str = INFO_NIL; verb = 2; break ;
				     	  
  case DEBUG    :		     	  
  case DEBUG1   : str = DEBUG_STR; verb = 3; break ;
  case DEBUG2   :		     	  
  case DEBUG3   : str = DEBUG_NIL; verb = 3; break ;

  case LOG_INFO : verb = 2 ; window = 3; break ;

  default : return;
  }
  // *INDENT-ON*

  static char buff1[1024], buff2[1024], buff[4][1024];

  if(CTX.verbosity >= verb){

    if(!WID)
      window = -1;
    else 
      WID->check(); 
    // this is pretty costly, but permits to keep the app
    // responsive... the downside is that it can cause race
    // conditions. Let's move it in here at least, so that we don;t
    // check() on DEBUG calls when not in debug mode.

    va_start (args, fmt);

    if(window >= 0){
      vsprintf(buff[window], fmt, args); 
      if(window <= 2) WID->set_status(buff[window], window);
      if(log && strlen(buff[window])) WID->add_message(buff[window]);
    }
    else{
      strcpy(buff1, "@C1");
      if(str) strcat(buff1, str);
      vsprintf(buff2, fmt, args); 
      strcat(buff1,buff2);
      if(CTX.terminal) fprintf(stderr, "%s\n", &buff1[3]);
      if(WID){
	if(verb<2)
	  WID->add_message(buff1);
	else
	  WID->add_message(&buff1[3]);
	if(!verb) WID->create_message_window();
      }
    }
    va_end (args);

    if(CTX.terminal) fflush(stderr);
  }

  if(abort){
    Debug();
    if(WID){
      WID->save_message(CTX.error_filename);
      WID->fatal_error(CTX.error_filename);
    }
    Exit(1);
  }
}


// Clean exit

void Exit(int level){
  if(WID && !CTX.batch){
    if(CTX.session_save){
      CTX.position[0] = WID->m_window->x();
      CTX.position[1] = WID->m_window->y();
      CTX.gl_position[0] = WID->g_window->x();
      CTX.gl_position[1] = WID->g_window->y();
      CTX.msg_position[0] = WID->msg_window->x();
      CTX.msg_position[1] = WID->msg_window->y();
      CTX.msg_size[0] = WID->msg_window->w();
      CTX.msg_size[1] = WID->msg_window->h();
      CTX.opt_position[0] = WID->opt_window->x();
      CTX.opt_position[1] = WID->opt_window->y();
      CTX.stat_position[0] = WID->stat_window->x();
      CTX.stat_position[1] = WID->stat_window->y();
      CTX.vis_position[0] = WID->vis_window->x();
      CTX.vis_position[1] = WID->vis_window->y();
      Print_Options(0, GMSH_SESSIONRC, CTX.sessionrc_filename);
    }
    if(CTX.options_save)
      Print_Options(0, GMSH_OPTIONSRC, CTX.optionsrc_filename);
  }
  unlink(CTX.tmp_filename);//delete temp file
  exit(level);
}

// CPU time computation, etc.

void GetResources(long *s, long *us, long *mem){
  static struct rusage r;

  getrusage(RUSAGE_SELF,&r);
  *s   = (long)r.ru_utime.tv_sec ;
  *us  = (long)r.ru_utime.tv_usec ;
  *mem = (long)r.ru_maxrss ;
}

void PrintResources(char *fmt, long s, long us, long mem){
  Msg(DIRECT, "Resources = %scpu %ld.%ld s / mem %ld kb\n", fmt, s, us, mem);
}

double Cpu(void){
  long s, us, mem;
  GetResources(&s, &us, &mem);
  return (double)s + (double)us/1.e6 ;
}

