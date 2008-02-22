// $Id: Message.cpp,v 1.84 2008-02-22 07:59:00 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <signal.h>
#include "Message.h"
#include "GmshUI.h"
#include "Context.h"
#include "Options.h"
#include "GUI.h"
#include "GUI_Extras.h"
#include "OS.h"

extern GUI *WID;
extern Context_T CTX;

// Handle signals. It is a crime to call stdio functions in a signal
// handler. But who cares? ;-)

void Signal(int sig_num)
{
  switch (sig_num) {
  case SIGSEGV:
    Msg(FATAL1, "Segmentation violation (invalid memory reference)");
    Msg(FATAL2, "------------------------------------------------------");
    Msg(FATAL2, "You have discovered a bug in Gmsh! You may report it");
    Msg(FATAL2, "by e-mail (together with any helpful data permitting to");
    Msg(FATAL3, "reproduce it) to <gmsh@geuz.org>");
    break;
  case SIGFPE:
    Msg(FATAL, "Floating point exception (division by zero?)");
    break;
  case SIGINT:
    Msg(INFO, "Interrupt (generated from terminal special character)");
    Exit(1);
    break;
  default:
    Msg(FATAL, "Unknown signal");
    break;
  }
}

// General purpose message routine

void Debug()
{
  printf("debug!\n");
}

void Msg(int level, const char *fmt, ...)
{
  va_list args;
  int abort = 0, verb = 0, window = -1, log = 1, color = 0;
  char *str = NULL;

  // standard messages in black
  // errors, wanrnings in red
  // external and or direct messages in blue
  
  switch(level){
  case DIRECT   : color = 4; verb = 2; break ;
  case SOLVER   : color = 4; verb = 3; break ;
  case SOLVERR  : color = 1; verb = 3; break ;

  case PROGRESS : log = 0; window = 1; break ;

  case STATUS1N : log = 0; //fallthrough
  case STATUS1  : str = INFO_STR; verb = 1; window = 0; break ;
  case STATUS2N : log = 0; //fallthrough
  case STATUS2  : str = INFO_STR; verb = 1; window = 1; break ;
  case ONSCREEN : log = 0; verb = 1; window = 3; break ;

  case FATAL    : str = FATAL_STR; abort = 1; break ;
  case FATAL1   : str = FATAL_STR; break ;
  case FATAL2   : str = WHITE_STR; break ;
  case FATAL3   : str = WHITE_STR; abort = 1; break ;
				     		  
  case GERROR   : 		     		  
  case GERROR1  : str = ERROR_STR; break ;
  case GERROR2  : 		     
  case GERROR3  : str = WHITE_STR; break ;
				     	  
  case WARNING  : 		     	  
  case WARNING1 : str = WARNING_STR; verb = 1; break ;
  case WARNING2 : 		     	  
  case WARNING3 : str = WHITE_STR; verb = 1; break ;
				     	  
  case INFO     :		     	  
  case INFO1    : str = INFO_STR; verb = 3; break ;
  case INFO2    :		     	  
  case INFO3    : str = WHITE_STR; verb = 3; break ;
				     	  
  case DEBUG    :		     	  
  case DEBUG1   : str = DEBUG_STR; verb = 4; break ;
  case DEBUG2   :		     	  
  case DEBUG3   : str = WHITE_STR; verb = 4; break ;

  default : return;
  }

  if(verb < 2)
    color = 1;

#define BUFFSIZE 1024

  static char buff1[BUFFSIZE], buff2[BUFFSIZE], buff[5][BUFFSIZE];

  if(CTX.verbosity >= verb) {

    if(!WID){
      window = -1;
    }
    else{
      // This is pretty costly, but permits to keep the app
      // responsive. The downside is that it can cause race
      // conditions: everytime we output a Msg, a pending callback can
      // be executed! We fix this by encapsulating critical sections
      // (mai3d(), CreateFile(), etc.) with 'CTX.threads_lock', but
      // this is far from perfect...
      if(level != DEBUG &&
	 level != DEBUG1 &&
	 level != DEBUG2 &&
	 level != DEBUG3 &&
	 level != STATUS1N &&
	 level != STATUS2N){
	WID->check();
      }
    }

    va_start(args, fmt);

    if(window >= 0) {
#if defined(HAVE_NO_VSNPRINTF)
      vsprintf(buff[window], fmt, args);
#else
      vsnprintf(buff[window], BUFFSIZE, fmt, args);
#endif
      WID->set_status(buff[window], window);
      if(log && strlen(buff[window])){
	strcpy(buff1, str ? str : "");
	strncat(buff1, buff[window], BUFFSIZE-strlen(buff1));
        WID->add_message(buff1);
      }
    }
    else if(log) {
      sprintf(buff1, "@C%d@.", color);
      if(str)
        strncat(buff1, str, BUFFSIZE-strlen(buff1));

#if defined(HAVE_NO_VSNPRINTF)
      vsprintf(buff2, fmt, args);
#else
      vsnprintf(buff2, BUFFSIZE, fmt, args);
#endif
      strncat(buff1, buff2, BUFFSIZE-strlen(buff1));
      if(CTX.terminal)
        fprintf(stderr, "%s\n", &buff1[5]);
      if(WID) {
        if(color)
          WID->add_message(buff1);
        else
          WID->add_message(&buff1[5]);
        if(!verb)
          WID->create_message_window();
      }
    }
    va_end(args);

    if(CTX.terminal)
      fflush(stderr);
  }

  if(abort) {
    Debug();
    if(WID) {
      WID->save_message(CTX.error_filename_fullpath);
      WID->fatal_error(CTX.error_filename_fullpath);
    }
    Exit(1);
  }
}

// Clean exit

void Exit(int level)
{
  // delete the temp file
  UnlinkFile(CTX.tmp_filename_fullpath);

  if(level){
    // in case of an abnormal exit, force the abort directly
    // (bypassing any post main stuff, e.g. destructors for static
    // variables). This still guarantees that any open streams are
    // flushed and closed, but can prevent nasty infinite loops.
    abort();
  }

  // if we exit cleanly (level==0) and we are in full GUI mode, save
  // the persistent info to disk
  if(WID && !CTX.batch) {
    if(CTX.session_save) {
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
      CTX.plugin_position[0] = WID->plugin_window->x();
      CTX.plugin_position[1] = WID->plugin_window->y();
      CTX.plugin_size[0] = WID->plugin_window->w();
      CTX.plugin_size[1] = WID->plugin_window->h();
      CTX.stat_position[0] = WID->stat_window->x();
      CTX.stat_position[1] = WID->stat_window->y();
      CTX.vis_position[0] = WID->vis_window->x();
      CTX.vis_position[1] = WID->vis_window->y();
      CTX.clip_position[0] = WID->clip_window->x();
      CTX.clip_position[1] = WID->clip_window->y();
      CTX.manip_position[0] = WID->manip_window->x();
      CTX.manip_position[1] = WID->manip_window->y();
      CTX.ctx_position[0] = WID->context_geometry_window->x();
      CTX.ctx_position[1] = WID->context_geometry_window->y();
      CTX.solver_position[0] = WID->solver[0].window->x();
      CTX.solver_position[1] = WID->solver[0].window->y();
      file_chooser_get_position(&CTX.file_chooser_position[0],
				&CTX.file_chooser_position[1]);
      Print_Options(0, GMSH_SESSIONRC, 0, 0, CTX.session_filename_fullpath);
    }
    if(CTX.options_save)
      Print_Options(0, GMSH_OPTIONSRC, 1, 0, CTX.options_filename_fullpath);
  }

  exit(0);
}

double GetValue(const char *text, double defaultval)
{
  if(CTX.nopopup)
    return defaultval;

  if(WID && !CTX.batch){ // pop up GUI dialog
    char defaultstr[256];
    sprintf(defaultstr, "%.16g", defaultval);
    const char *ret = fl_input(text, defaultstr);
    if(!ret)
      return defaultval;
    else
      return atof(ret);
  }
  else{
    printf("%s (default=%.16g): ", text, defaultval);
    char str[256];
    char *ret = fgets(str, sizeof(str), stdin);
    if(!ret || !strlen(str) || !strcmp(str, "\n"))
      return defaultval;
    else
      return atof(str);
  }
}

bool GetBinaryAnswer(const char *question, const char *yes, const char *no, 
		     bool defaultval)
{
  if(CTX.nopopup || CTX.batch || !WID)
    return defaultval;

  if(fl_choice(question, no, yes, NULL))
    return true;
  else
    return false;
}
