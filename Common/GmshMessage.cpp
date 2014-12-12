// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshConfig.h"

#if defined(HAVE_MPI)
#include <mpi.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "GmshMessage.h"
#include "GmshSocket.h"
#include "Gmsh.h"
#include "GModel.h"
#include "Options.h"
#include "Context.h"
#include "OpenFile.h"
#include "StringUtils.h"
#include "OS.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif
#if defined(HAVE_ONELAB2)
#include "OnelabDatabase.h"
#endif
#include "gmshLocalNetworkClient.h"

#if defined(HAVE_PETSC)
#include <petsc.h>
#endif

#if defined(HAVE_SLEPC)
#include <slepc.h>
#endif

#if defined(HAVE_FLTK)
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "extraDialogs.h"
#endif

int Msg::_commRank = 0;
int Msg::_commSize = 1;
int Msg::_verbosity = 5;
int Msg::_progressMeterStep = 20;
int Msg::_progressMeterCurrent = 0;
std::map<std::string, double> Msg::_timers;
int Msg::_warningCount = 0;
int Msg::_errorCount = 0;
std::string Msg::_firstWarning;
std::string Msg::_firstError;
GmshMessage *Msg::_callback = 0;
std::string Msg::_commandLine;
std::string Msg::_launchDate;
GmshClient *Msg::_client = 0;
std::string Msg::_execName;
#if defined(HAVE_ONELAB)
onelab::client *Msg::_onelabClient = 0;
onelab::server *onelab::server::_server = 0;
#endif
std::string Msg::_gmshOnelabAction = "";

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

#if defined(_MSC_VER) && (_MSC_VER == 1310) //NET 2003
#define vsnprintf _vsnprintf
#endif

static void addGmshPathToEnvironmentVar(const std::string &name)
{
  std::vector<std::string> split = SplitFileName(CTX::instance()->argv0);
  std::string path;
  char *tmp = getenv(name.c_str());
  if(tmp){
    path = tmp;
#if defined(WIN32)
    path += ";" + split[0];
#else
    path += ":" + split[0];
#endif
  }
  else
    path = split[0];
  SetEnvironmentVar(name.c_str(), path.c_str());
}

void Msg::Init(int argc, char **argv)
{
#if defined(HAVE_MPI)
  int flag;
  MPI_Initialized(&flag);
  if(!flag) MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &_commRank);
  MPI_Comm_size(MPI_COMM_WORLD, &_commSize);
  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
#endif
#if defined(HAVE_PETSC)
  int sargc = 0;
  char **sargv = new char*[argc + 1];
  // prune argv from gmsh-specific options that make PETSc verbose
  for(int i = 0; i < argc; i++){
    std::string val(argv[i]);
    if(val != "-info" && val != "-help" && val != "-v")
      sargv[sargc++] = argv[i];
  }
  PetscInitialize(&sargc, &sargv, PETSC_NULL, PETSC_NULL);
  PetscPopSignalHandler();
#if defined(HAVE_SLEPC)
  SlepcInitialize(&sargc, &sargv, PETSC_NULL, PETSC_NULL);
#endif
  delete [] sargv;
#endif
  time_t now;
  time(&now);
  _launchDate = ctime(&now);
  _launchDate.resize(_launchDate.size() - 1);
  _commandLine.clear();
  for(int i = 0; i < argc; i++){
    if(i) _commandLine += " ";
    _commandLine += argv[i];
  }

  if(argc && argv){
    CTX::instance()->argv0 = std::string(argv[0]);
    // add the directory where the binary is installed to the path where Python
    // looks for modules, and to the path for executables (this allows us to
    // find the onelab.py module or subclients automatically)
    addGmshPathToEnvironmentVar("PYTHONPATH");
    addGmshPathToEnvironmentVar("PATH");
  }

  InitializeOnelab("Gmsh");
}

void Msg::Exit(int level)
{
  // delete the temp file
  if(!_commRank) UnlinkFile(CTX::instance()->homeDir + CTX::instance()->tmpFileName);

  // exit directly on abnormal program termination (level != 0). We
  // used to call abort() to flush open streams, but on modern OSes
  // this calls the annoying "report this crash to the mothership"
  // window... so just exit!
  if(level){
#if defined(HAVE_SLEPC)
    SlepcFinalize();
#endif
#if defined(HAVE_PETSC)
    PetscFinalize();
#endif
#if defined(HAVE_MPI)
    // force general abort (wven if the fatal error occurred on 1 cpu only)
    MPI_Abort(MPI_COMM_WORLD, level);
    MPI_Finalize();
#endif
    FinalizeOnelab();
    exit(level);
  }

#if defined(HAVE_FLTK)
  // if we exit cleanly (level==0) and we are in full GUI mode, save
  // the persistent info to disk
  if(FlGui::available() && !_commRank) {
    if(CTX::instance()->sessionSave)
      PrintOptions(0, GMSH_SESSIONRC, 0, 0,
                   (CTX::instance()->homeDir + CTX::instance()->sessionFileName).c_str());
    if(CTX::instance()->optionsSave == 1)
      PrintOptions(0, GMSH_OPTIONSRC, 1, 0,
                   (CTX::instance()->homeDir + CTX::instance()->optionsFileName).c_str());
    else if(CTX::instance()->optionsSave == 2){
      std::string fileName = GModel::current()->getFileName() + ".opt";
      PrintOptions(0, GMSH_FULLRC, 1, 0, fileName.c_str());
    }
  }
#endif

#if defined(HAVE_SLEPC)
  SlepcFinalize();
#endif
#if defined(HAVE_PETSC)
  PetscFinalize();
#endif
#if defined(HAVE_MPI)
  MPI_Finalize();
#endif
  FinalizeOnelab();
  exit(_errorCount);
}

static int streamIsFile(FILE* stream)
{
  // the given stream is definitely not interactive if it is a regular file
  struct stat stream_stat;
  if(fstat(fileno(stream), &stream_stat) == 0){
    if(stream_stat.st_mode & S_IFREG) return 1;
  }
  return 0;
}

static int streamIsVT100(FILE* stream)
{
  // if running inside emacs the terminal is not VT100
  const char* emacs = getenv("EMACS");
  if(emacs && *emacs == 't') return 0;

  // list of known terminal names (from cmake)
  static const char* names[] =
    {"Eterm", "ansi", "color-xterm", "con132x25", "con132x30", "con132x43",
     "con132x60", "con80x25",  "con80x28", "con80x30", "con80x43", "con80x50",
     "con80x60",  "cons25", "console", "cygwin", "dtterm", "eterm-color", "gnome",
     "gnome-256color", "konsole", "konsole-256color", "kterm", "linux", "msys",
     "linux-c", "mach-color", "mlterm", "putty", "rxvt", "rxvt-256color",
     "rxvt-cygwin", "rxvt-cygwin-native", "rxvt-unicode", "rxvt-unicode-256color",
     "screen", "screen-256color", "screen-256color-bce", "screen-bce", "screen-w",
     "screen.linux", "vt100", "xterm", "xterm-16color", "xterm-256color",
     "xterm-88color", "xterm-color", "xterm-debian", 0};
  const char** t = 0;
  const char* term = getenv("TERM");
  if(term){
    for(t = names; *t && strcmp(term, *t) != 0; ++t) {}
  }
  if(!(t && *t)) return 0;
  return 1;
}

void Msg::Fatal(const char *fmt, ...)
{
  _errorCount++;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Fatal", str);
  if(_client) _client->Error(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    FlGui::instance()->check();
    std::string tmp = std::string("@C1@.") + "Fatal   : " + str;
    FlGui::instance()->addMessage(tmp.c_str());
    if(_firstError.empty()) _firstError = str;
    FlGui::instance()->setLastStatus(FL_RED);
    FlGui::instance()->saveMessages
      ((CTX::instance()->homeDir + CTX::instance()->errorFileName).c_str());
    fl_alert("A fatal error has occurred which will force Gmsh to abort.\n"
             "The error messages have been saved in the following file:\n\n%s",
             (CTX::instance()->homeDir + CTX::instance()->errorFileName).c_str());
  }
#endif

  if(CTX::instance()->terminal){
    const char *c0 = "", *c1 = "";
    if(!streamIsFile(stderr) && streamIsVT100(stderr)){
      c0 = "\33[1m\33[31m"; c1 = "\33[0m";  // bold red
    }
    if(_commSize > 1)
      fprintf(stderr, "%sFatal   : [rank %3d] %s%s\n", c0, _commRank, str, c1);
    else
      fprintf(stderr, "%sFatal   : %s%s\n", c0, str, c1);
    fflush(stderr);
  }

  // only exit if a callback is not provided
  if(!_callback) Exit(1);
}

void Msg::Error(const char *fmt, ...)
{
  _errorCount++;

  if(_verbosity < 1) return;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Error", str);
  if(_client) _client->Error(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    FlGui::instance()->check();
    std::string tmp = std::string("@C1@.") + "Error   : " + str;
    FlGui::instance()->addMessage(tmp.c_str());
    if(_firstError.empty()) _firstError = str;
    FlGui::instance()->setLastStatus(FL_RED);
  }
#endif

  if(CTX::instance()->terminal){
    const char *c0 = "", *c1 = "";
    if(!streamIsFile(stderr) && streamIsVT100(stderr)){
      c0 = "\33[1m\33[31m"; c1 = "\33[0m";  // bold red
    }
    if(_commSize > 1)
      fprintf(stderr, "%sError   : [rank %3d] %s%s\n", c0, _commRank, str, c1);
    else
      fprintf(stderr, "%sError   : %s%s\n", c0, str, c1);
    fflush(stderr);
  }
}

void Msg::Warning(const char *fmt, ...)
{
  _warningCount++;

  if(_verbosity < 2) return;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Warning", str);
  if(_client) _client->Warning(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    FlGui::instance()->check();
    std::string tmp = std::string("@C5@.") + "Warning : " + str;
    FlGui::instance()->addMessage(tmp.c_str());
    if(_firstWarning.empty()) _firstWarning = str;
    FlGui::instance()->setLastStatus();
  }
#endif

  if(CTX::instance()->terminal){
    const char *c0 = "", *c1 = "";
    if(!streamIsFile(stderr) && streamIsVT100(stderr)){
      c0 = "\33[35m"; c1 = "\33[0m";  // magenta
    }
    if(_commSize > 1)
      fprintf(stderr, "%sWarning : [rank %3d] %s%s\n", c0, _commRank, str, c1);
    else
      fprintf(stderr, "%sWarning : %s%s\n", c0, str, c1);
    fflush(stderr);
  }
}

void Msg::Info(const char *fmt, ...)
{
  if(_verbosity < 4) return;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Info", str);
  if(_client) _client->Info(str);

#if defined(HAVE_FLTK)
#if defined(_OPENMP)
  #pragma omp critical
#endif
  {
    if(FlGui::available()){
      FlGui::instance()->check();
      std::string tmp = std::string("Info    : ") + str;
      FlGui::instance()->addMessage(tmp.c_str());
    }
  }
#endif

  if(CTX::instance()->terminal){
    if(_commSize > 1)
      fprintf(stdout, "Info    : [rank %3d] %s\n", _commRank, str);
    else
      fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}
void Msg::RequestRender()
{
  if(_callback) (*_callback)("RequestRender", "");
}

void Msg::Direct(const char *fmt, ...)
{
  if(_verbosity < 3) return;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Direct", str);
  if(_client) _client->Info(str);

#if defined(HAVE_FLTK)
#if defined(_OPENMP)
#pragma omp master
#endif
  {
    if(FlGui::available()){
      FlGui::instance()->check();
      std::string tmp = std::string("@C4@.") + str;
      FlGui::instance()->addMessage(tmp.c_str());
    }
  }
#endif

  if(CTX::instance()->terminal){
    const char *c0 = "", *c1 = "";
    if(!streamIsFile(stdout) && streamIsVT100(stdout)){
      c0 = "\33[34m"; c1 = "\33[0m";  // blue
    }
    if(_commSize > 1)
      fprintf(stdout, "%s[rank %3d] %s%s\n", c0, _commRank, str, c1);
    else
      fprintf(stdout, "%s%s%s\n", c0, str, c1);
    fflush(stdout);
  }
}

void Msg::StatusBar(bool log, const char *fmt, ...)
{
  if(_verbosity < 4) return;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback && log) (*_callback)("Info", str);
  if(_client && log) _client->Info(str);

#if defined(HAVE_FLTK)
#if defined(_OPENMP)
#pragma omp master
#endif
  {
    if(FlGui::available()){
      if(log) FlGui::instance()->check();
      if(!log || _verbosity > 4)
	FlGui::instance()->setStatus(str);
      if(log){
	std::string tmp = std::string("Info    : ") + str;
	FlGui::instance()->addMessage(tmp.c_str());
      }
    }
  }
#endif

  if(log && CTX::instance()->terminal){
    if(_commSize > 1)
      fprintf(stdout, "Info    : [rank %3d] %s\n", _commRank, str);
    else
      fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}

void Msg::StatusGl(const char *fmt, ...)
{
#if defined(HAVE_FLTK)
  if(_commRank) return;
  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  if(FlGui::available())
    FlGui::instance()->setStatus(str, true);
#endif
}

void Msg::Debug(const char *fmt, ...)
{
  if(_verbosity < 99) return;

  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Debug", str);
  if(_client) _client->Info(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    std::string tmp = std::string("Debug   : ") + str;
    FlGui::instance()->addMessage(tmp.c_str());
  }
#endif

  if(CTX::instance()->terminal){
    if(_commSize > 1)
      fprintf(stdout, "Debug   : [rank %3d] %s\n", _commRank, str);
    else
      fprintf(stdout, "Debug   : %s\n", str);
    fflush(stdout);
  }
}

void Msg::ProgressMeter(int n, int N, bool log, const char *fmt, ...)
{
  if(_commRank || _verbosity < 4 ||
     _progressMeterStep <= 0 || _progressMeterStep >= 100) return;

  double percent = 100. * (double)n/(double)N;

  if(percent >= _progressMeterCurrent || n > N - 1){
    char str[5000], str2[5000];
    va_list args;
    va_start(args, fmt);
    vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);
    sprintf(str2, "%3d%%    : %s", _progressMeterCurrent, str);

    if(_client) _client->Progress(str2);

#if defined(HAVE_FLTK)
    if(FlGui::available() && _verbosity > 4){
      FlGui::instance()->check();
      FlGui::instance()->setProgress(str, (n > N - 1) ? 0 : n, 0, N);
    }
#endif
    if(_callback) (*_callback)("Progress", str);
    if(!streamIsFile(stdout) && log && CTX::instance()->terminal){
      fprintf(stdout, "%s                                          \r",
              (n > N - 1) ? "" : str2);
      fflush(stdout);
    }

    while(_progressMeterCurrent < percent)
      _progressMeterCurrent += _progressMeterStep;
  }
}

void Msg::PrintTimers()
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

  if(CTX::instance()->terminal){
    if(_commSize > 1)
      fprintf(stdout, "Timers  : [rank %3d] %s\n", _commRank, str.c_str());
    else
      fprintf(stdout, "Timers  : %s\n", str.c_str());
    fflush(stdout);
  }
}

void Msg::ResetErrorCounter()
{
  _warningCount = 0; _errorCount = 0;
  _firstWarning.clear(); _firstError.clear();
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->setLastStatus();
#endif
}

void Msg::PrintErrorCounter(const char *title)
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
  if(FlGui::available()){
    std::string col = _errorCount ? "@C1@." : "@C5@.";
    FlGui::instance()->addMessage((col + prefix + line).c_str());
    FlGui::instance()->addMessage((col + prefix + title).c_str());
    FlGui::instance()->addMessage((col + prefix + warn).c_str());
    FlGui::instance()->addMessage((col + prefix + err).c_str());
    FlGui::instance()->addMessage((col + prefix + help).c_str());
    FlGui::instance()->addMessage((col + prefix + line).c_str());
    if(_errorCount) fl_beep();
  }
#endif

  if(CTX::instance()->terminal){
    const char *c0 = "", *c1 = "";
    if(!streamIsFile(stderr) && streamIsVT100(stderr)){
      c0 = _errorCount ? "\33[1m\33[31m" : "\33[35m"; // bold red or magenta
      c1 = "\33[0m";
    }
    fprintf(stderr, "%s%s\n%s\n%s\n%s\n%s\n%s%s\n", c0, (prefix + line).c_str(),
            (prefix + title).c_str(), (prefix + warn).c_str(),
            (prefix + err).c_str(), (prefix + help).c_str(),
            (prefix + line).c_str(), c1);
    fflush(stderr);
  }
}

double Msg::GetValue(const char *text, double defaultval)
{
  // if a callback is given let's assume we don't want to be bothered
  // with interactive stuff
  if(CTX::instance()->noPopup || _callback) return defaultval;

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    char defaultstr[256];
    sprintf(defaultstr, "%.16g", defaultval);
    const char *ret = fl_input(text, defaultstr, "");
    if(!ret)
      return defaultval;
    else
      return atof(ret);
  }
#endif

  printf("%s (default=%.16g): ", text, defaultval);
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return atof(str);
}

std::string Msg::GetString(const char *text, std::string defaultval)
{
  // if a callback is given let's assume we don't want to be bothered
  // with interactive stuff
  if(CTX::instance()->noPopup || _callback) return defaultval;

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    const char *ret = fl_input(text, defaultval.c_str(), "");
    if(!ret)
      return defaultval;
    else
      return std::string(ret);
  }
#endif

  printf("%s (default=%s): ", text, defaultval.c_str());
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return std::string(str);
}

int Msg::GetAnswer(const char *question, int defaultval, const char *zero,
                   const char *one, const char *two)
{
  // if a callback is given let's assume we don't want to be bothered
  // with interactive stuff
  if(CTX::instance()->noPopup || _callback) return defaultval;

#if defined(HAVE_FLTK)
  if(FlGui::available())
    return fl_choice(question, zero, one, two, "");
#endif

  if(two)
    printf("%s\n\n0=[%s] 1=[%s] 2=[%s] (default=%d): ", question,
           zero, one, two, defaultval);
  else
    printf("%s\n\n0=[%s] 1=[%s] (default=%d): ", question,
           zero, one, defaultval);
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return atoi(ret);
}

bool Msg::UseOnelab()
{
#if defined(HAVE_ONELAB)
  return _onelabClient ? true : false;
#else
  return false;
#endif
}

void Msg::SetOnelabNumber(std::string name, double val, bool visible)
{
#ifdef HAVE_ONELAB2
  std::vector<onelab::number> numbers;
  OnelabDatabase::instance()->get(numbers, name);
  if(numbers.empty()) {
    numbers.resize(1);
    numbers[0].setName(name);
  }
  numbers[0].setValue(val);
  numbers[0].setVisible(visible);
  OnelabDatabase::instance()->set(numbers[0], std::string("Gmsh"));
#elif defined(HAVE_ONELAB)
  if(_onelabClient){
    std::vector<onelab::number> numbers;
    _onelabClient->get(numbers, name);
    if(numbers.empty()){
      numbers.resize(1);
      numbers[0].setName(name);
    }
    numbers[0].setValue(val);
    numbers[0].setVisible(visible);
    _onelabClient->set(numbers[0]);
  }
#endif
}

void Msg::SetOnelabString(std::string name, std::string val, bool visible)
{
#ifdef HAVE_ONELAB2
    std::vector<onelab::string> strings;
    OnelabDatabase::instance()->get(strings, name);
    if(strings.empty()){
      strings.resize(1);
      strings[0].setName(name);
    }
    strings[0].setValue(val);
    strings[0].setVisible(visible);
    OnelabDatabase::instance()->set(strings[0], std::string("Gmsh"));
#elif defined(HAVE_ONELAB)
  if(_onelabClient){
    std::vector<onelab::string> strings;
    _onelabClient->get(strings, name);
    if(strings.empty()){
      strings.resize(1);
      strings[0].setName(name);
    }
    strings[0].setValue(val);
    strings[0].setVisible(visible);
    _onelabClient->set(strings[0]);
  }
#endif
}

#if defined(HAVE_ONELAB)
class localGmsh : public onelab::localClient {
public:
  localGmsh() : onelab::localClient("Gmsh") {}
  // redefinition of virtual onelab_client::sendMergeFileRequest
  void sendMergeFileRequest(const std::string &name)
  {
    if(name.find(".geo") != std::string::npos){
      MergePostProcessingFile(name, CTX::instance()->solver.autoShowViews,
                              CTX::instance()->solver.autoShowLastStep, true);
      GModel::current()->setFileName(name);
    }
    else if((name.find(".opt") != std::string::npos)){
      MergeFile(name);
    }
    else if((name.find(".macro") != std::string::npos)){
      MergeFile(name);
    }
    else
      MergePostProcessingFile(name, CTX::instance()->solver.autoShowViews,
                              CTX::instance()->solver.autoShowLastStep, true);
  }
  void sendInfo(const std::string &msg){ Msg::Info("%s", msg.c_str()); }
  void sendWarning(const std::string &msg){ Msg::Warning("%s", msg.c_str()); }
  void sendError(const std::string &msg){ Msg::Error("%s", msg.c_str()); }
};
#endif

void Msg::InitializeOnelab(const std::string &name, const std::string &sockname)
{
#if defined(HAVE_ONELAB)
  if(_onelabClient) delete _onelabClient;
  if(sockname.empty()){
    _onelabClient = new localGmsh();
    if(name != "Gmsh"){ // load db from file:
      FILE *fp = Fopen(name.c_str(), "rb");
      if(fp){
#ifdef HAVE_ONELAB2
       OnelabDatabase::instance()->fromFile(fp); 
#else
        _onelabClient->fromFile(fp);
#endif
        fclose(fp);
      }
      else
        Error("Error loading onelab database '%s'", name.c_str());
    }
  }
  else{
    // TODO ONELAB2 client...
    onelab::remoteNetworkClient *c = new onelab::remoteNetworkClient(name, sockname);
    _onelabClient = c;
    _client = c->getGmshClient();

    SetOnelabNumber(name + "/UseCommandLine", 1, false);
    SetOnelabString(name + "/FileExtension", ".geo", false);
    SetOnelabString(name + "/9CheckCommand", "-", false);
    SetOnelabString(name + "/9ComputeCommand", "-3", false);

    std::vector<onelab::string> ps;
    _onelabClient->get(ps, name + "/Action");
    if(ps.size()){
      //Info("Performing ONELAB '%s'", ps[0].getValue().c_str());
      if(ps[0].getValue() == "initialize") Exit(0);
    }
  }
#endif
}

void Msg::LoadOnelabClient(const std::string &clientName, const std::string &sockName)
{
#if defined(HAVE_ONELAB)
  onelab::remoteNetworkClient *client = 0;
  client = new onelab::remoteNetworkClient(clientName,sockName);
  if(client){
    std::string action, cmd;
    std::vector<onelab::string> ps;
    client->get(ps,clientName+"/Action");
    if(ps.size() && ps[0].getValue().size())
      action.assign(ps[0].getValue());

    //cmd.assign("");
    if(!action.compare("compute")){
      std::vector<onelab::string> ps;
      client->get(ps,clientName+"/FullCmdLine");
      if(ps.size() && ps[0].getValue().size())
	cmd.assign(ps[0].getValue());

      if(cmd.size()){
	Msg::Info("Loader calls <%s>",cmd.c_str());
	//client->sendInfo(strcat("Loader calls",cmd.c_str()));
	std::cout << "Loader calls " << cmd << std::endl;
	SystemCall(cmd.c_str(),true); //true->blocking
      }
      else
	Msg::Info("No full command line found for <%s>",
		    clientName.c_str());
    }
    Msg::Info("Stopping client <%s>", clientName.c_str());
    delete client;
  }
  exit(1);
#endif
}

#if defined(HAVE_ONELAB)
static void _setStandardOptions(onelab::parameter *p,
                                std::map<std::string, std::vector<double> > &fopt,
                                std::map<std::string, std::vector<std::string> > &copt)
{
  // strings
  if(copt.count("Label")) p->setLabel(copt["Label"][0]);
  if(copt.count("ShortHelp")) // for backward compatibility
    p->setLabel(copt["ShortHelp"][0]);
  if(copt.count("Help")) p->setHelp(copt["Help"][0]);
  if(copt.count("Highlight")) p->setAttribute("Highlight", copt["Highlight"][0]);
  if(copt.count("Macro")) p->setAttribute("Macro", copt["Macro"][0]);
  if(copt.count("GmshOption")) p->setAttribute("GmshOption", copt["GmshOption"][0]);
  if(copt.count("AutoCheck")) // for backward compatibility
    p->setAttribute("AutoCheck", copt["AutoCheck"][0]);

  // numbers
  if(fopt.count("Visible")) p->setVisible(fopt["Visible"][0] ? true : false);
  if(fopt.count("ReadOnly")) p->setReadOnly(fopt["ReadOnly"][0] ? true : false);
  if(fopt.count("NeverChanged")) p->setNeverChanged(fopt["NeverChanged"][0] ? true : false);
  if(fopt.count("ReadOnlyRange"))
    p->setAttribute("ReadOnlyRange", fopt["ReadOnlyRange"][0] ? "1" : "0");
  if(fopt.count("AutoCheck"))
    p->setAttribute("AutoCheck", fopt["AutoCheck"][0] ? "1" : "0");
}

static std::string _getParameterName(const std::string &key,
                                     std::map<std::string, std::vector<std::string> > &copt)
{
  std::string name(key);
  if(copt.count("Path")){
    std::string path = copt["Path"][0];
    // if path ends with a number, assume it's for ordering purposes
    if(path.size() && path[path.size() - 1] >= '0' && path[path.size() - 1] <= '9')
      name = path + name;
    else if(path.size() && path[path.size() - 1] == '/')
      name = path + name;
    else
      name = path + "/" + name;
  }
  return name;
}
#endif

void Msg::ExchangeOnelabParameter(const std::string &key,
                                  std::vector<double> &val,
                                  std::map<std::string, std::vector<double> > &fopt,
                                  std::map<std::string, std::vector<std::string> > &copt)
{
#if defined(HAVE_ONELAB)
  if(!_onelabClient || val.empty()) return;

  std::string name;
  if(copt.count("Name"))
    name = copt["Name"][0];

  if(name.empty()){
    if(copt.size() || fopt.size())
      Msg::Error("From now on you need to use the `Name' attribute to create a "
                 "ONELAB parameter: `Name \"%s\"'",
                 _getParameterName(key, copt).c_str());
    return;
  }

  std::vector<onelab::number> ps;
#ifdef HAVE_ONELAB2
  OnelabDatabase::instance()->get(ps, name);
#else
  _onelabClient->get(ps, name);
#endif
  bool noRange = true, noChoices = true, noLoop = true;
  bool noGraph = true, noClosed = true;
  if(ps.size()){
    if(fopt.count("ReadOnly") && fopt["ReadOnly"][0])
      ps[0].setValue(val[0]); // use local value
    else
      val[0] = ps[0].getValue(); // use value from server
    // keep track of these attributes, which can be changed server-side (unless
    // they are not visible or, for the range/choices, when explicitely setting
    // these attributes as ReadOnly)
    if(ps[0].getVisible()){
      if(!(fopt.count("ReadOnlyRange") && fopt["ReadOnlyRange"][0])){
        if(ps[0].getMin() != -onelab::parameter::maxNumber() ||
           ps[0].getMax() != onelab::parameter::maxNumber() ||
           ps[0].getStep() != 0.) noRange = false;
        if(ps[0].getChoices().size()) noChoices = false;
      }
      if(ps[0].getAttribute("Loop").size()) noLoop = false;
      if(ps[0].getAttribute("Graph").size()) noGraph = false;
      if(ps[0].getAttribute("Closed").size()) noClosed = false;
    }
  }
  else{
    ps.resize(1);
    ps[0].setName(name);
    ps[0].setValue(val[0]);
  }
  // send updated parameter to server
  if(noRange && fopt.count("Range") && fopt["Range"].size() == 2){
    ps[0].setMin(fopt["Range"][0]); ps[0].setMax(fopt["Range"][1]);
  }
  else if(noRange && fopt.count("Min") && fopt.count("Max")){
    ps[0].setMin(fopt["Min"][0]); ps[0].setMax(fopt["Max"][0]);
  }
  else if(noRange && fopt.count("Min")){
    ps[0].setMin(fopt["Min"][0]); ps[0].setMax(onelab::parameter::maxNumber());
  }
  else if(noRange && fopt.count("Max")){
    ps[0].setMax(fopt["Max"][0]); ps[0].setMin(-onelab::parameter::maxNumber());
  }
  if(noRange && fopt.count("Step")) ps[0].setStep(fopt["Step"][0]);
  // if no range/min/max/step info is provided, try to compute a reasonnable
  // range and step (this makes the gui much nicer to use)
  if(noRange && !fopt.count("Range") && !fopt.count("Step") &&
     !fopt.count("Min") && !fopt.count("Max")){
    bool isInteger = (floor(val[0]) == val[0]);
    double fact = isInteger ? 5. : 20.;
    if(val[0] > 0){
      ps[0].setMin(val[0] / fact);
      ps[0].setMax(val[0] * fact);
      ps[0].setStep((ps[0].getMax() - ps[0].getMin()) / 100.);
    }
    else if(val[0] < 0){
      ps[0].setMin(val[0] * fact);
      ps[0].setMax(val[0] / fact);
      ps[0].setStep((ps[0].getMax() - ps[0].getMin()) / 100.);
    }
    if(val[0] && isInteger){
      ps[0].setMin((int)ps[0].getMin());
      ps[0].setMax((int)ps[0].getMax());
      ps[0].setStep((int)ps[0].getStep());
    }
  }
  if(noChoices && fopt.count("Choices")){
    ps[0].setChoices(fopt["Choices"]);
    if(copt.count("Choices")) ps[0].setChoiceLabels(copt["Choices"]);
  }
  if(noLoop && copt.count("Loop")) // for backward compatibity
    ps[0].setAttribute("Loop", copt["Loop"][0]);
  if(noLoop && fopt.count("Loop"))
    ps[0].setAttribute("Loop", (fopt["Loop"][0] == 3.) ? "3" :
                       (fopt["Loop"][0] == 2.) ? "2" :
                       (fopt["Loop"][0] == 1.) ? "1" : "");
  if(noGraph && copt.count("Graph")) ps[0].setAttribute("Graph", copt["Graph"][0]);
  if(noClosed && copt.count("Closed")) // for backward compatibility
    ps[0].setAttribute("Closed", copt["Closed"][0]);
  if(noClosed && fopt.count("Closed"))
    ps[0].setAttribute("Closed", fopt["Closed"][0] ? "1" : "0");
  _setStandardOptions(&ps[0], fopt, copt);
#ifdef HAVE_ONELAB2
  OnelabDatabase::instance()->set(ps[0], std::string("Gmsh"));
#else
  _onelabClient->set(ps[0]);
#endif
#endif
}

void Msg::ExchangeOnelabParameter(const std::string &key,
                                  std::string &val,
                                  std::map<std::string, std::vector<double> > &fopt,
                                  std::map<std::string, std::vector<std::string> > &copt)
{
#if defined(HAVE_ONELAB)
  if(!_onelabClient || val.empty()) return;

  std::string name;
  if(copt.count("Name"))
    name = copt["Name"][0];

  if(name.empty()){
    if(copt.size() || fopt.size())
      Msg::Error("From now on you need to use the `Name' attribute to create a "
                 "ONELAB parameter: `Name \"%s\"'",
                 _getParameterName(key, copt).c_str());
    return;
  }

  std::vector<onelab::string> ps;
#ifdef HAVE_ONELAB2
  OnelabDatabase::instance()->get(ps, name);
#else
  _onelabClient->get(ps, name);
#endif
  bool noChoices = true, noClosed = true, noMultipleSelection = true;
  if(ps.size()){
    if(fopt.count("ReadOnly") && fopt["ReadOnly"][0])
      ps[0].setValue(val); // use local value
    else
      val = ps[0].getValue(); // use value from server
    // keep track of these attributes, which can be changed server-side (unless
    // they are not visible)
    if(ps[0].getVisible()){
      if(ps[0].getChoices().size()) noChoices = false;
      if(ps[0].getAttribute("Closed").size()) noClosed = false;
      if(ps[0].getAttribute("MultipleSelection").size()) noMultipleSelection = false;
    }
  }
  else{
    ps.resize(1);
    ps[0].setName(name);
    ps[0].setValue(val);
  }
  if(copt.count("Kind")) ps[0].setKind(copt["Kind"][0]);
  if(noChoices && copt.count("Choices")) ps[0].setChoices(copt["Choices"]);
  if(noClosed && copt.count("Closed")) // for backward compatibility
    ps[0].setAttribute("Closed", copt["Closed"][0]);
  if(noClosed && fopt.count("Closed"))
    ps[0].setAttribute("Closed", fopt["Closed"][0] ? "1" : "0");
  if(noMultipleSelection && copt.count("MultipleSelection"))
    ps[0].setAttribute("MultipleSelection", copt["MultipleSelection"][0]);
  _setStandardOptions(&ps[0], fopt, copt);
#ifdef HAVE_ONELAB2
    OnelabDatabase::instance()->set(ps[0], std::string("Gmsh"));
#else
  _onelabClient->set(ps[0]);
#endif
#endif
}

void Msg::UndefineOnelabParameter(const std::string &name)
{
#if defined(HAVE_ONELAB)
  if(!_onelabClient) return;
  _onelabClient->clear(name);
#endif
}

void Msg::ImportPhysicalsAsOnelabRegions()
{
#if defined(HAVE_ONELAB)
  if(_onelabClient){
    std::map<int, std::vector<GEntity*> > groups[4];
    GModel::current()->getPhysicalGroups(groups);
    for(int dim = 0; dim <= 3; dim++){
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
          it != groups[dim].end(); it++){
        // create "read-only" onelab region
        std::string name = GModel::current()->getPhysicalName(dim, it->first);
        std::ostringstream num;
        num << it->first;
        if(name.empty())
          name = std::string("Physical") +
            ((dim == 3) ? "Volume" : (dim == 2) ? "Surface" :
             (dim == 1) ? "Line" : "Point") + num.str();
        name.insert(0, "Gmsh parameters/Physical groups/");
        onelab::region p(name, num.str());
        p.setDimension(dim);
        p.setReadOnly(true);
        p.setVisible(false);
        p.setAttribute("Closed", "1");
        _onelabClient->set(p);
      }
    }
  }
#endif
}

void Msg::RunOnelabClient(const std::string &name, const std::string &command)
{
#if defined(HAVE_ONELAB)
  onelab::server::citer it = onelab::server::instance()->findClient(name);
  onelab::client *client = 0;
  if(it != onelab::server::instance()->lastClient()){
    client = it->second;
  }
  else{
    if(command.empty()){
      Msg::Error("Unknown ONELAB client `%s'", name.c_str());
      return;
    }
    onelab::string o(name + "/Action", "initialize");
    o.setVisible(false);
    o.setNeverChanged(true);
    onelab::server::instance()->set(o);
#if defined(HAVE_FLTK)
    Msg::Info("Creating new ONELAB client `%s' (%s)", name.c_str(), command.c_str());
    client = new gmshLocalNetworkClient(name, command);
    client->run();
#else
    Msg::Error("Cannot create ONELAB client without FLTK");
    return;
#endif
  }
  onelab::string o(name + "/Action", "compute");
  o.setVisible(false);
  o.setNeverChanged(true);
  onelab::server::instance()->set(o);
  client->run();
#endif
}

void Msg::FinalizeOnelab()
{
#if defined(HAVE_ONELAB)
  if(_onelabClient){
    delete _onelabClient;
    _onelabClient = 0;
    _client = 0;
  }
#endif
}

void Msg::Barrier()
{
#if defined(HAVE_MPI)
  MPI_Barrier(MPI_COMM_WORLD);
#endif
}

#if defined(_OPENMP)

#include <omp.h>

int Msg::GetNumThreads(){ return omp_get_num_threads(); }
int Msg::GetMaxThreads(){ return omp_get_max_threads(); }
int Msg::GetThreadNum(){ return omp_get_thread_num(); }

#else

int Msg::GetNumThreads(){ return 1; }
int Msg::GetMaxThreads(){ return 1; }
int Msg::GetThreadNum(){ return 0; }

#endif
