// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ONELAB_MESSAGE_H_
#define _ONELAB_MESSAGE_H_

#include <map>
#include <string>
#include <set>
#include <stdarg.h>
#include "onelab.h"

class GmshClient;

// the external message handler
class GmshMessage{
 public:
  GmshMessage(){}
  virtual ~GmshMessage(){}
  virtual void operator()(std::string level, std::string message){}
};

class fullNameLessThan{
public:
  int compareFullNames(const std::string a, const std::string b) const;
  bool operator()(const std::string p1, const std::string p2) const{
    return compareFullNames(p1,p2);
  }
};

// a class to manage messages
class OLMsg {
 private:
  // current cpu number and total number of cpus
  static int _commRank, _commSize;
  // verbosity level (0: silent except fatal errors, 1: +errors, 2:
  // +warnings, 3: +info except status bar, 4: normal, 99: debug)
  static int _verbosity;
  // step (in %) of the progress meter and current progress %
  static int _progressMeterStep, _progressMeterCurrent;
  // timers
  static std::map<std::string, double> _timers;
  // counters
  static int _warningCount, _errorCount;
  // callback
  static GmshMessage *_callback;
  // command-line and startup time
  static std::string _commandLine, _launchDate;
  // communication with Gmsh when run remotely
  static GmshClient *_client;
  // communication with onelab server
  static onelab::client *_onelabClient;
  // dictionnary for parameter names
  static std::set<std::string, fullNameLessThan> _fullNameDict;
  // Gmsh wait function 
  static void (*gui_wait_fct)(double time);
 public:
  OLMsg() {}
  static void Init(int argc, char **argv);
  static void Exit(int level);
  /* static int GetCommRank(){ return _commRank; } */
  /* static int GetCommSize(){ return _commSize; } */
  /* static void SetCommRank(int val){ _commRank = val; } */
  /* static void SetCommSize(int val){ _commSize = val; } */
  /* static void SetCallback(GmshMessage *callback){ _callback = callback; } */
  /* static void Barrier(); */
  /* static int GetNumThreads(); */
  /* static int GetMaxThreads(); */
  /* static int GetThreadNum(); */
  static void SetVerbosity(int val){ _verbosity = val; }
  static int GetVerbosity(){ return _verbosity; }
  /* static std::string GetLaunchDate(){ return _launchDate; } */
  /* static std::string GetCommandLineArgs(){ return _commandLine; } */
  static void Fatal(const char *fmt, ...);
  static void Error(const char *fmt, ...);
  static void Warning(const char *fmt, ...);
  static void Info(const char *fmt, ...);
  static void Direct(const char *fmt, ...);
  static void Direct(int level, const char *fmt, ...);
  static void StatusBar(int num, bool log, const char *fmt, ...);
  static void Debug(const char *fmt, ...);
  static void ProgressMeter(int n, int N, const char *fmt, ...);
  static void ProgressMeter(int n, int N){ ProgressMeter(n, N, ""); }
  static void SetProgressMeterStep(int step){ _progressMeterStep = step; }
  static void ResetProgressMeter(){ if(!_commRank) _progressMeterCurrent = 0; }
  static double &Timer(std::string str){ return _timers[str]; }
  static void PrintTimers();

  static void ResetErrorCounter(){ _warningCount = 0; _errorCount = 0; }
  static void PrintErrorCounter(const char *title);
  static int GetErrorCount(){ return _errorCount; }

  static double GetValue(const char *text, double defaultval);
  static std::string GetString(const char *text, std::string defaultval);
  static int GetAnswer(const char *question, int defaultval, const char *zero,
                       const char *one, const char *two=0);
  //static void InitClient(std::string sockname);
  //static void FinalizeClient();
  static GmshClient *GetClient(){ return _client; }

  //static void SetLoaderName(const std::string &name){ _loaderName = name; }
  //static std::string GetLoaderName(){ return _loaderName; }
  static void SetGuiWaitFunction(void (*fct)(double time));
  static void (*GetGuiWaitFunction())(double);
  static void SetOnelabClient(onelab::client *client){ _onelabClient = client;}

  static void InitializeOnelab(const std::string &name);
  static void FinalizeOnelab();

  static void SetOnelabNumber(std::string name, double val, bool visible=true);
  static void GetOnelabNumber(std::string name, double *val);
  static double GetOnelabNumber(std::string name);
  static void SetOnelabString(std::string name, std::string val, bool visible=true);
  static std::string GetOnelabString(std::string name);
  static void SetOnelabAttributeString(std::string name,
				       std::string attrib,std::string val);
  static std::string GetOnelabAttributeString(std::string name,std::string attrib);
  static std::string GetOnelabAttributeNumber(std::string name,
					      std::string attrib);
  //static std::vector<std::string> GetOnelabChoices(std::string name);
  static bool GetOnelabChoices(std::string name, std::vector<std::string> &choices);
  static void ExchangeOnelabParameter(const std::string &key,
				      std::vector<double> &val,
				      std::map<std::string,
				      std::vector<double> > &fopt,
				      std::map<std::string,
				      std::vector<std::string> > &copt);
  static void MergeFile(const std::string &name);
  static bool hasGmsh;
  static void recordFullName(const std::string &name);
  static std::string obtainFullName(const std::string &name);
};

#endif
