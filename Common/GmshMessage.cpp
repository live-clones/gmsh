// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshSocket.h"
#include "Gmsh.h"
#include "GModel.h"
#include "Options.h"
#include "Context.h"
#include "OS.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

#if defined(HAVE_MPI)
#include <mpi.h>
#endif

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
int Msg::_progressMeterStep = 10;
int Msg::_progressMeterCurrent = 0;
std::map<std::string, double> Msg::_timers;
int Msg::_warningCount = 0;
int Msg::_errorCount = 0;
GmshMessage *Msg::_callback = 0;
std::string Msg::_commandLine;
std::string Msg::_launchDate;
GmshClient *Msg::_client = 0;
#if defined(HAVE_ONELAB)
onelab::client *Msg::_onelabClient = 0;
onelab::server *onelab::server::_server = 0;
#endif

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
  PetscInitialize(&argc, &argv, PETSC_NULL, PETSC_NULL);
  PetscPopSignalHandler();
#endif
#if defined(HAVE_SLEPC)
  SlepcInitialize(&argc, &argv, PETSC_NULL, PETSC_NULL);
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

void Msg::Fatal(const char *fmt, ...)
{
  _errorCount++;

  char str[1024];
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
    FlGui::instance()->showMessages();
    FlGui::instance()->saveMessages
      ((CTX::instance()->homeDir + CTX::instance()->errorFileName).c_str());
    fl_alert("A fatal error has occurred which will force Gmsh to abort.\n"
             "The error messages have been saved in the following file:\n\n%s",
             (CTX::instance()->homeDir + CTX::instance()->errorFileName).c_str());
  }
#endif

  if(CTX::instance()->terminal){
    if(_commSize > 1)
      fprintf(stderr, "Fatal   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stderr, "Fatal   : %s\n", str);
    fflush(stderr);
  }

  // only exit if a callback is not provided
  if(!_callback) Exit(1);
}

void Msg::Error(const char *fmt, ...)
{
  _errorCount++;

  if(_verbosity < 1) return;

  char str[1024];
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
    FlGui::instance()->showMessages();
  }
#endif

  if(CTX::instance()->terminal){
    if(_commSize > 1)
      fprintf(stderr, "Error   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stderr, "Error   : %s\n", str);
    fflush(stderr);
  }
}

void Msg::Warning(const char *fmt, ...)
{
  _warningCount++;

  if(_commRank || _verbosity < 2) return;

  char str[1024];
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
  }
#endif

  if(CTX::instance()->terminal){
    fprintf(stderr, "Warning : %s\n", str);
    fflush(stderr);
  }
}

void Msg::Info(const char *fmt, ...)
{
  if(_commRank || _verbosity < 4) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Info", str);
  if(_client) _client->Info(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    FlGui::instance()->check();
    std::string tmp = std::string("Info    : ") + str;
    FlGui::instance()->addMessage(tmp.c_str());
  }
#endif

  if(CTX::instance()->terminal){
    fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}

void Msg::Direct(const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  Direct(3, str);
}

void Msg::Direct(int level, const char *fmt, ...)
{
  if(_commRank || _verbosity < level) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Direct", str);
  if(_client) _client->Info(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    FlGui::instance()->check();
    std::string tmp;
    if(level < 2)
      tmp = std::string("@C1@.") + str;
    else if(level < 3)
      tmp = std::string("@C5@.") + str;
    else
      tmp = std::string("@C4@.") + str;
    FlGui::instance()->addMessage(tmp.c_str());
    if(level == 1)
      FlGui::instance()->showMessages();
  }
#endif

  if(CTX::instance()->terminal){
    fprintf(stdout, "%s\n", str);
    fflush(stdout);
  }
}

void Msg::StatusBar(int num, bool log, const char *fmt, ...)
{
  if(_commRank || _verbosity < 4) return;
  if(num < 1 || num > 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback && log) (*_callback)("Info", str);
  if(_client && log) _client->Info(str);

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(log) FlGui::instance()->check();
    if(!log || num != 2 || _verbosity > 4)
      FlGui::instance()->setStatus(str, num - 1);
    if(log){
      std::string tmp = std::string("Info    : ") + str;
      FlGui::instance()->addMessage(tmp.c_str());
    }
  }
#endif

  if(log && CTX::instance()->terminal){
    fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}

void Msg::Debug(const char *fmt, ...)
{
  if(_verbosity < 99) return;

  char str[1024];
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
      fprintf(stdout, "Debug   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stdout, "Debug   : %s\n", str);
    fflush(stdout);
  }
}

void Msg::ProgressMeter(int n, int N, const char *fmt, ...)
{
  if(_commRank || _verbosity < 4) return;

  double percent = 100. * (double)n/(double)N;

  if(percent >= _progressMeterCurrent){
    char str[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);

    if(strlen(fmt)) strcat(str, " ");

    char str2[1024];
    sprintf(str2, "%s(%d %%)", _progressMeterCurrent);

    if(_client) _client->Progress(str2);

#if defined(HAVE_FLTK)
    if(FlGui::available() && _verbosity > 4){
      FlGui::instance()->check();
      FlGui::instance()->setProgress(str, n, N);
    }
#endif

    if(CTX::instance()->terminal){
      fprintf(stdout, "%s                     \r", str2);
      fflush(stdout);
    }

    while(_progressMeterCurrent < percent)
      _progressMeterCurrent += _progressMeterStep;
  }

  if(n > N - 1){
    if(_client) _client->Progress("Done!");

#if defined(HAVE_FLTK)
    if(FlGui::available() && _verbosity > 4){
      FlGui::instance()->check();
      FlGui::instance()->setProgress("", 0, N);
    }
#endif

    if(CTX::instance()->terminal){
      fprintf(stdout, "Done!                                              \r");
      fflush(stdout);
    }
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
      fprintf(stdout, "Timers  : [On processor %d] %s\n", _commRank, str.c_str());
    else
      fprintf(stdout, "Timers  : %s\n", str.c_str());
    fflush(stdout);
  }
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
    std::string red("@C1@.");
    FlGui::instance()->addMessage((red + prefix + line).c_str());
    FlGui::instance()->addMessage((red + prefix + title).c_str());
    FlGui::instance()->addMessage((red + prefix + warn).c_str());
    FlGui::instance()->addMessage((red + prefix + err).c_str());
    FlGui::instance()->addMessage((red + prefix + help).c_str());
    FlGui::instance()->addMessage((red + prefix + line).c_str());
    if(_errorCount){
      FlGui::instance()->showMessages();
      fl_beep();
    }
  }
#endif

  if(CTX::instance()->terminal){
    fprintf(stderr, "%s\n%s\n%s\n%s\n%s\n%s\n", (prefix + line).c_str(),
            (prefix + title).c_str(), (prefix + warn).c_str(),
            (prefix + err).c_str(), (prefix + help).c_str(),
            (prefix + line).c_str());
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

void Msg::InitializeOnelab(const std::string &name, const std::string &sockname)
{
#if defined(HAVE_ONELAB)
  if(_onelabClient) delete _onelabClient;
  if(sockname.empty())
    _onelabClient = new onelab::localClient(name);
  else{
    onelab::remoteNetworkClient *c = new onelab::remoteNetworkClient(name, sockname);
    _onelabClient = c;
    _client = c->getGmshClient();

    onelab::number o5(name + "/UseCommandLine",1);
    o5.setVisible(false);
    _onelabClient->set(o5);
    onelab::string o(name + "/FileExtension", ".geo");
    o.setVisible(false);
    _onelabClient->set(o);
    onelab::string o3(name + "/9CheckCommand", "-");
    o3.setVisible(false);
    _onelabClient->set(o3);
    onelab::string o4(name + "/9ComputeCommand", "-3");
    o4.setVisible(false);
    _onelabClient->set(o4);

    std::vector<onelab::string> ps;
    _onelabClient->get(ps, name + "/Action");
    if(ps.size()){
      //Info("Performing OneLab '%s'", ps[0].getValue().c_str());
      if(ps[0].getValue() == "initialize") Exit(0);
    }

  }
#endif
}

void Msg::ExchangeOnelabParameter(const std::string &key,
                                  std::vector<double> &val,
                                  std::map<std::string, std::vector<double> > &fopt,
                                  std::map<std::string, std::vector<std::string> > &copt)
{
#if defined(HAVE_ONELAB)
  if(!_onelabClient || val.empty()) return;

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

  std::vector<onelab::number> ps;
  _onelabClient->get(ps, name);
  bool noRange = true, noChoices = true, noLoop = true, noGraph = true;
  if(ps.size()){
    val[0] = ps[0].getValue(); // always use value from server
    // keep track of these attributes, which can be changed server-side
    if(ps[0].getMin() != -onelab::parameter::maxNumber() ||
       ps[0].getMax() != onelab::parameter::maxNumber() ||
       ps[0].getStep() != 0.) noRange = false;
    if(ps[0].getChoices().size()) noChoices = false;
    if(ps[0].getAttribute("Loop").size()) noLoop = false;
    if(ps[0].getAttribute("Graph").size()) noGraph = false;
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
  if(noChoices && fopt.count("Choices")){
    ps[0].setChoices(fopt["Choices"]);
    if(copt.count("Choices")) ps[0].setChoiceLabels(copt["Choices"]);
  }
  if(fopt.count("Visible")) ps[0].setVisible(fopt["Visible"][0] ? true : false);
  if(fopt.count("ReadOnly")) {
    ps[0].setReadOnly(fopt["ReadOnly"][0] ? true : false);
    // If the parameter is set "read-only" here, the local value is used instead
    // of that from the server
    if(ps[0].getReadOnly()) ps[0].setValue(val[0]);
  }
  if(copt.count("Help")) ps[0].setHelp(copt["Help"][0]);
  if(copt.count("Label")) ps[0].setLabel(copt["Label"][0]);
  if(copt.count("ShortHelp")) ps[0].setLabel(copt["ShortHelp"][0]);
  if(noLoop && copt.count("Loop")) ps[0].setAttribute("Loop", copt["Loop"][0]);
  if(noGraph && copt.count("Graph")) ps[0].setAttribute("Graph", copt["Graph"][0]);
  if(copt.count("Highlight")) ps[0].setAttribute("Highlight", copt["Highlight"][0]);
  _onelabClient->set(ps[0]);
#endif
}

void Msg::ImportPhysicalsAsOnelabRegions()
{
#if defined(HAVE_ONELAB)
  if(_onelabClient){
    std::map<int, std::vector<GEntity*> > groups[4];
    GModel::current()->getPhysicalGroups(groups);
    for(int dim = 0; dim < 3; dim++){
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
        name.insert(0, "Gmsh/Physical groups/");
        onelab::region p(name, num.str());
        p.setDimension(dim);
        p.setReadOnly(true);
        _onelabClient->set(p);
      }
    }
  }
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
