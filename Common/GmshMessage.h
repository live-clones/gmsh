// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_MESSAGE_H_
#define _GMSH_MESSAGE_H_

#include <map>
#include <vector>
#include <string>
#include <stdarg.h>

#include "GmshConfig.h"

class GmshClient;
namespace onelab{ class client; }

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
  // verbosity level (0: silent except fatal errors, 1: +errors, 2: +warnings,
  // 3: +direct, 4: +info, 5 (=normal): +statusbar, 99: debug)
  static int _verbosity;
  // step (in %) of the progress meter and current progress %
  static int _progressMeterStep, _progressMeterCurrent;
  // timers
  static std::map<std::string, double> _timers;
  // report cpu time for each info message?
  static bool _infoCpu;
  // starting time (gettimeofday at startup)
  static double _startTime;
  // counters
  static int _warningCount, _errorCount, _atLeastOneErrorInRun;
  static std::string _firstWarning, _firstError;
  // callback
  static GmshMessage *_callback;
  // command-line and startup time
  static std::string _commandLine, _launchDate;
  // command-line-specified numbers and strings
  static std::map<std::string, std::vector<double> > _commandLineNumbers;
  static std::map<std::string, std::string> _commandLineStrings;
  // communication with Gmsh when run remotely
  static GmshClient *_client;
#if defined(HAVE_ONELAB)
  // communication with onelab server
  static onelab::client *_onelabClient;
#endif
  // executable name
  static std::string _execName;
  // log file
  static std::string _logFileName;
  static FILE *_logFile;
 public:
  Msg() {}
  static void Init(int argc, char **argv);
  static void Exit(int level);
  static int GetCommRank();
  static int GetCommSize();
  static void SetCommRank(int val);
  static void SetCommSize(int val);
  static void SetCallback(GmshMessage *callback);
  static GmshMessage *GetCallback();
  static void Barrier();
  static int GetNumThreads();
  static void SetNumThreads(int num);
  static int GetMaxThreads();
  static int GetThreadNum();
  static void SetVerbosity(int val);
  static void SetLogFile(const std::string &name);
  static int GetVerbosity();
  static std::string GetLaunchDate();
  static std::string GetCommandLineArgs();
  static std::map<std::string, std::vector<double> > &GetCommandLineNumbers();
  static std::map<std::string, std::string> &GetCommandLineStrings();
  static std::string PrintResources(bool printDate, bool printWallTime,
                                    bool printCpu, bool printMem);
  static void Fatal(const char *fmt, ...);
  static void Error(const char *fmt, ...);
  static void Warning(const char *fmt, ...);
  static void Info(const char *fmt, ...);
  static void RequestRender();
  static void Direct(const char *fmt, ...);
  static void StatusBar(bool log, const char *fmt, ...);
  static void StatusGl(const char *fmt, ...);
  static void SetWindowTitle(const std::string &title);
  static void Debug(const char *fmt, ...);
  static void ProgressMeter(int n, int N, bool log, const char *fmt, ...);
  static void SetProgressMeterStep(int step);
  static int GetProgressMeterStep();
  static void ResetProgressMeter();
  static void SetInfoCpu(bool val);
  static double &Timer(std::string str);
  static void PrintTimers();
  static void ResetErrorCounter();
  static void PrintErrorCounter(const char *title);
  static int GetWarningCount();
  static int GetErrorCount();
  static std::string GetFirstWarning();
  static std::string GetFirstError();
  static double GetValue(const char *text, double defaultval);
  static std::string GetString(const char *text, std::string defaultval);
  static int GetAnswer(const char *question, int defaultval, const char *zero,
                       const char *one, const char *two=0);
  static void InitializeOnelab(const std::string &name, const std::string &sockname="");
  static void SetExecutableName(const std::string &name);
  static std::string GetExecutableName();
  static void LoadOnelabClient(const std::string &name, const std::string &sockName);
  static int GetNumOnelabClients();
  static GmshClient *GetGmshClient();
#if defined(HAVE_ONELAB)
  static onelab::client *GetOnelabClient();
#endif
  static void FinalizeOnelab();
  static bool UseOnelab();
  static void SetOnelabNumber(std::string name, double val, bool visible=true,
                              bool persistent=false, bool readOnly=false,
                              int changedValue=3);
  static void SetOnelabString(std::string name, std::string val, bool visible=true,
                              bool persistent=false, bool readOnly=false,
                              int changedValue=3, const std::string &kind="");
  static double GetOnelabNumber(std::string name, double defaultValue=0.,
                                bool errorIfMissing=false);
  static std::string GetOnelabString(std::string name, const std::string &defaultValue="",
                                     bool errorIfMissing=false);
  static void AddOnelabStringChoice(std::string name, std::string kind,
                                    std::string value, bool updateValue=true,
                                    bool readOnly=false, bool visible=true);
  static void SetOnelabAction(const std::string &action);
  static std::string GetOnelabAction();
  static void ExchangeOnelabParameter(const std::string &key,
                                      std::vector<double> &val,
                                      std::map<std::string, std::vector<double> > &fopt,
                                      std::map<std::string, std::vector<std::string> > &copt);
  static void ExchangeOnelabParameter(const std::string &key,
                                      std::string &val,
                                      std::map<std::string, std::vector<double> > &fopt,
                                      std::map<std::string, std::vector<std::string> > &copt);
  static void UndefineOnelabParameter(const std::string &name);
  static void RunOnelabClient(const std::string &name, const std::string &exe="");
  static void SetOnelabChanged(int value, const std::string &client="Gmsh");
  static void ImportPhysicalGroupsInOnelab();
};

#endif
