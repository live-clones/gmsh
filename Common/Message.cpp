// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Message.h"
#include "Gmsh.h"
#include "Options.h"
#include "Context.h"
#include "OS.h"

#if defined(HAVE_MPI)
#include <mpi.h>
#endif

#if defined(HAVE_FLTK)
#include "GUI.h"
#include "GUI_Extras.h"
extern GUI *WID;
#endif

extern Context_T CTX;

int Message::_commRank = 0;
int Message::_commSize = 1;
int Message::_verbosity = 3;
int Message::_progressMeterStep = 10;
int Message::_progressMeterCurrent = 0;
std::map<std::string, double> Message::_timers;
int Message::_warningCount = 0;
int Message::_errorCount = 0;
GmshMessage *Message::_callback = 0;

#if defined(HAVE_NO_VSNPRINTF)
static int vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
  if(strlen(fmt) > size - 1){ // just copy the format
    strncpy(str, fmt, size - 1);
    str[size - 1] = '\0';
    return size;
  }
  return vsprintf(str, fmt, ap);
}
#endif

void Message::Init(int argc, char **argv)
{
#if defined(HAVE_MPI)
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &_commRank);
  MPI_Comm_size(MPI_COMM_WORLD, &_commSize);
  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
#endif
}

void Message::Exit(int level)
{
  // delete the temp file
  if(!_commRank) UnlinkFile(CTX.tmp_filename_fullpath);

  // exit directly on abnormal program termination (level != 0). We
  // used to call abort() to flush open streams, but on modern OSes
  // this calls the annoying "report this crash to the mothership"
  // window... so just exit!
  if(level){
#if defined(HAVE_MPI)
    MPI_Finalize();
#endif
    exit(level);
  }
  
#if defined(HAVE_FLTK)
  // if we exit cleanly (level==0) and we are in full GUI mode, save
  // the persistent info to disk
  if(WID && !CTX.batch && !_commRank) {
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
      CTX.field_position[0] = WID->field_window->x();
      CTX.field_position[1] = WID->field_window->y();
      CTX.field_size[0] = WID->field_window->w();
      CTX.field_size[1] = WID->field_window->h();
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
#endif

#if defined(HAVE_MPI)
  MPI_Finalize();
#endif
  exit(0);
}

void Message::Fatal(const char *fmt, ...)
{
  _errorCount++;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Fatal", str);

#if defined(HAVE_FLTK)
  if(WID){
    WID->check();
    std::string tmp = std::string("@C1@.") + "Fatal   : " + str;
    WID->add_message(tmp.c_str());
    WID->create_message_window();
    WID->save_message(CTX.error_filename_fullpath);
    WID->fatal_error(CTX.error_filename_fullpath);
  }
#endif

  if(CTX.terminal){
    if(_commSize > 1)
      fprintf(stderr, "Fatal   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stderr, "Fatal   : %s\n", str);
    fflush(stderr);
  }

  // only exit if a callback is not provided
  if(!_callback) Exit(1);
}

void Message::Error(const char *fmt, ...)
{
  _errorCount++;

  if(_verbosity < 1) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Error", str);

#if defined(HAVE_FLTK)
  if(WID){
    WID->check();
    std::string tmp = std::string("@C1@.") + "Error   : " + str;
    WID->add_message(tmp.c_str());
    WID->create_message_window();
  }
#endif

  if(CTX.terminal){
    if(_commSize > 1) 
      fprintf(stderr, "Error   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stderr, "Error   : %s\n", str);
    fflush(stderr);
  }
}

void Message::Warning(const char *fmt, ...)
{
  _warningCount++;

  if(_commRank || _verbosity < 2) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Warning", str);

#if defined(HAVE_FLTK)
  if(WID){
    WID->check();
    std::string tmp = std::string("@C1@.") + "Warning : " + str;
    WID->add_message(tmp.c_str());
  }
#endif

  if(CTX.terminal){
    fprintf(stderr, "Warning : %s\n", str);
    fflush(stderr);
  }
}

void Message::Info(const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Info", str);

#if defined(HAVE_FLTK)
  if(WID){
    WID->check();
    std::string tmp = std::string("Info    : ") + str;
    WID->add_message(tmp.c_str());
  }
#endif

  if(CTX.terminal){
    fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}

void Message::Direct(const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  Direct(3, str);
}

void Message::Direct(int level, const char *fmt, ...)
{
  if(_commRank || _verbosity < level) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Direct", str);

#if defined(HAVE_FLTK)
  if(WID){
    WID->check();
    std::string tmp;
    if(level < 3)
      tmp = std::string("@C1@.") + str;
    else
      tmp = std::string("@C4@.") + str;
    WID->add_message(tmp.c_str());
    if(level == 1)
      WID->create_message_window();
  }
#endif
  
  if(CTX.terminal){
    fprintf(stdout, "%s\n", str);
    fflush(stdout);
  }
}

void Message::StatusBar(int num, bool log, const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;
  if(num < 1 || num > 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback && log) (*_callback)("Info", str);

#if defined(HAVE_FLTK)
  if(WID){
    if(log) WID->check();
    WID->set_status(str, num - 1);
    if(log){
      std::string tmp = std::string("Info    : ") + str;
      WID->add_message(tmp.c_str());
    }
  }
#endif

  if(log && CTX.terminal){
    fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}

void Message::Debug(const char *fmt, ...)
{
  if(_verbosity < 99) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Debug", str);

#if defined(HAVE_FLTK)
  if(WID){
    std::string tmp = std::string("Debug   : ") + str;
    WID->add_message(tmp.c_str());
  }
#endif

  if(CTX.terminal){
    if(_commSize > 1) 
      fprintf(stdout, "Debug   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stdout, "Debug   : %s\n", str);
    fflush(stdout);
  }
}

void Message::ProgressMeter(int n, int N, const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  double percent = 100. * (double)n/(double)N;

  if(percent >= _progressMeterCurrent){
    char str[1024], str2[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);

    if(strlen(fmt)) strcat(str, " ");
    sprintf(str2, "(%d %%)", _progressMeterCurrent);
    strcat(str, str2);

#if defined(HAVE_FLTK)
    if(WID){
      WID->set_status(str, 1);
      WID->check();
    }
#endif
    if(CTX.terminal){
      fprintf(stdout, "%s                     \r", str);
      fflush(stdout);
    }

    while(_progressMeterCurrent < percent)
      _progressMeterCurrent += _progressMeterStep;
  }

  if(n > N - 1){
#if defined(HAVE_FLTK)
    if(WID) WID->set_status("", 1);
#endif
    if(CTX.terminal){
      fprintf(stdout, "Done!                                              \r");
      fflush(stdout);
    }
  }
}

void Message::PrintTimers()
{
  // do a single stdio call!
  std::string str;
  for(std::map<std::string, double>::iterator it = _timers.begin(); 
      it != _timers.end(); it++){
    if(it != _timers.begin()) str += ", ";
    char tmp[256];
    sprintf(tmp, "%s = %gs ", it->first.c_str(), it->second);
    str += std::string(tmp);
  }
  if(!str.size()) return;

  if(CTX.terminal){
    if(_commSize > 1) 
      fprintf(stdout, "Timers  : [On processor %d] %s\n", _commRank, str.c_str());
    else
      fprintf(stdout, "Timers  : %s\n", str.c_str());
    fflush(stdout);
  }
}

void Message::PrintErrorCounter(const char *title)
{
  if(_commRank || _verbosity < 1) return;
  if(!_warningCount && !_errorCount) return;

  std::string prefix = _errorCount ? "Error   : " : "Warning : ";
  std::string help("Check the full log for details");
  std::string line(std::max(strlen(title), help.size()), '-');
  char warn[128], err[128];
  sprintf(warn, "%5d warning%s", _warningCount, _warningCount == 1 ? "" : "s");
  sprintf(err, "%5d error%s", _errorCount, _errorCount == 1 ? "" : "s");

#if defined(HAVE_FLTK)
  if(WID){
    std::string red("@C1@.");
    WID->add_message((red + prefix + line).c_str());
    WID->add_message((red + prefix + title).c_str());
    WID->add_message((red + prefix + warn).c_str());
    WID->add_message((red + prefix + err).c_str());
    WID->add_message((red + prefix + help).c_str());
    WID->add_message((red + prefix + line).c_str());
    if(_errorCount){
      WID->create_message_window();
      fl_beep();
    }
  }
#endif

  if(CTX.terminal){
    fprintf(stderr, "%s\n%s\n%s\n%s\n%s\n%s\n", (prefix + line).c_str(), 
	    (prefix + title).c_str(), (prefix + warn).c_str(),
	    (prefix + err).c_str(), (prefix + help).c_str(), 
	    (prefix + line).c_str());
    fflush(stderr);
  }
}

double Message::GetValue(const char *text, double defaultval)
{
  // if a callback is given let's assume we don't want to be bothered
  // with interactive stuff
  if(CTX.nopopup || _callback) return defaultval;

#if defined(HAVE_FLTK)
  if(!CTX.batch){
    char defaultstr[256];
    sprintf(defaultstr, "%.16g", defaultval);
    const char *ret = fl_input(text, defaultstr);
    if(!ret)
      return defaultval;
    else
      return atof(ret);
  }
#endif

  printf("%s (default=%.16g) ", text, defaultval);
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return atof(str);
}

bool Message::GetBinaryAnswer(const char *question, const char *yes, 
			      const char *no, bool defaultval)
{
  // if a callback is given let's assume we don't want to be bothered
  // with interactive stuff
  if(CTX.nopopup || _callback) return defaultval;

#if defined(HAVE_FLTK)
  if(!CTX.batch){
    if(fl_choice(question, no, yes, NULL))
      return true;
    else
      return false;
  }
#endif

  while(1){
    printf("%s\n\n[%s] or [%s]? (default=%s) ", question, yes, no, 
	   defaultval ? yes : no);
    char str[256];
    char *ret = fgets(str, sizeof(str), stdin);
    if(!ret || !strlen(str) || !strcmp(str, "\n"))
      return defaultval;
    else if(!strcmp(str, yes))
      return true;
    else if(!strcmp(str, no))
      return false;
  }
}

void Message::Barrier()
{
#if defined(HAVE_MPI)
  MPI_Barrier(MPI_COMM_WORLD);
#endif
}

#if defined(_OPENMP)

#include <omp.h>

int Message::GetNumThreads(){ return omp_get_num_threads(); }
int Message::GetMaxThreads(){ return omp_get_max_threads(); }
int Message::GetThreadNum(){ return omp_get_thread_num(); }

#else

int Message::GetNumThreads(){ return 1; }
int Message::GetMaxThreads(){ return 1; }
int Message::GetThreadNum(){ return 0; }

#endif
