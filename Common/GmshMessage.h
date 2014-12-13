// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GMSH_MESSAGE_H_
#define _GMSH_MESSAGE_H_

#include <map>
#include <vector>
#include <string>
#include <stdarg.h>

#include "GmshConfig.h"

class GmshClient;
namespace onelab{ class client; }
#ifdef HAVE_ONELAB2
class GmshNetworkClient;
#endif

// the external message handler
class GmshMessage{
 public:
  GmshMessage(){}
  virtual ~GmshMessage(){}
  virtual void operator()(std::string level, std::string message){}
};

// a class to manage messages
class Msg {
 private:
  // current cpu number and total number of cpus
  static int _commRank, _commSize;
  // verbosity level (0: silent except fatal errors, 1: +errors, 2:
  // +warnings, 3: +direct, 4: +info except status bar, 5: normal, 99: debug)
  static int _verbosity;
  // step (in %) of the progress meter and current progress %
  static int _progressMeterStep, _progressMeterCurrent;
  // timers
  static std::map<std::string, double> _timers;
  // counters
  static int _warningCount, _errorCount;
  static std::string _firstWarning, _firstError;
  // callback
  static GmshMessage *_callback;
  // command-line and startup time
  static std::string _commandLine, _launchDate;
  // communication with Gmsh when run remotely
  static GmshClient *_client;
#if defined(HAVE_ONELAB2)
  // communication with onelab server (replace _client and old _onelabClient)
  static GmshNetworkClient *_onelabClient;
#elif defined(HAVE_ONELAB)
  // communication with onelab server
  static onelab::client *_onelabClient;
#endif
  // internal onelab status for Gmsh parser
  static std::string _gmshOnelabAction;
  // executable name
  static std::string _execName;
 public:
  Msg() {}
  static void Init(int argc, char **argv);
  static void Exit(int level);
  static int GetCommRank(){ return _commRank; }
  static int GetCommSize(){ return _commSize; }
  static void SetCommRank(int val){ _commRank = val; }
  static void SetCommSize(int val){ _commSize = val; }
  static void SetCallback(GmshMessage *callback){ _callback = callback; }
  static GmshMessage *GetCallback(){ return _callback; }
  static void Barrier();
  static int GetNumThreads();
  static int GetMaxThreads();
  static int GetThreadNum();
  static void SetVerbosity(int val){ _verbosity = val; }
  static int GetVerbosity(){ return _verbosity; }
  static std::string GetLaunchDate(){ return _launchDate; }
  static std::string GetCommandLineArgs(){ return _commandLine; }
  static void Fatal(const char *fmt, ...);
  static void Error(const char *fmt, ...);
  static void Warning(const char *fmt, ...);
  static void Info(const char *fmt, ...);
  static void RequestRender();
  static void Direct(const char *fmt, ...);
  static void StatusBar(bool log, const char *fmt, ...);
  static void StatusGl(const char *fmt, ...);
  static void Debug(const char *fmt, ...);
  static void ProgressMeter(int n, int N, bool log, const char *fmt, ...);
  static void SetProgressMeterStep(int step){ _progressMeterStep = step; }
  static int GetProgressMeterStep(){ return _progressMeterStep; }
  static void ResetProgressMeter(){ if(!_commRank) _progressMeterCurrent = 0; }
  static double &Timer(std::string str){ return _timers[str]; }
  static void PrintTimers();
  static void ResetErrorCounter();
  static void PrintErrorCounter(const char *title);
  static int GetWarningCount(){ return _warningCount; }
  static int GetErrorCount(){ return _errorCount; }
  static std::string GetFirstWarning(){ return _firstWarning; }
  static std::string GetFirstError(){ return _firstError; }
  static double GetValue(const char *text, double defaultval);
  static std::string GetString(const char *text, std::string defaultval);
  static int GetAnswer(const char *question, int defaultval, const char *zero,
                       const char *one, const char *two=0);
  static void InitializeOnelab(const std::string &name, const std::string &sockname="");
  static void SetExecutableName(const std::string &name) { _execName.assign(name); }
  static std::string GetExecutableName() { return _execName; }
  static void LoadOnelabClient(const std::string &name, const std::string &sockName);
  static GmshClient *GetGmshClient(){ return _client; }
#ifdef HAVE_ONELAB2
  static GmshNetworkClient *GetOnelabClient(){ return _onelabClient; }
#else
  static onelab::client *GetOnelabClient(){ return _onelabClient; }
#endif
  static void FinalizeOnelab();
  static bool UseOnelab();
  static void SetOnelabNumber(std::string name, double val, bool visible);
  static void SetOnelabString(std::string name, std::string val, bool visible);
  static void SetGmshOnelabAction(std::string action){ _gmshOnelabAction = action; }
  static std::string GetGmshOnelabAction(){ return _gmshOnelabAction; }
  static void ExchangeOnelabParameter(const std::string &key,
                                      std::vector<double> &val,
                                      std::map<std::string, std::vector<double> > &fopt,
                                      std::map<std::string, std::vector<std::string> > &copt);
  static void ExchangeOnelabParameter(const std::string &key,
                                      std::string &val,
                                      std::map<std::string, std::vector<double> > &fopt,
                                      std::map<std::string, std::vector<std::string> > &copt);
  static void UndefineOnelabParameter(const std::string &name);
  static void RunOnelabClient(const std::string &name, const std::string &command="");
  static void ImportPhysicalsAsOnelabRegions();
};

#endif
