#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <stdarg.h>

// a class to manage messages
class Message {
 private:
  // current cpu number and total number of cpus
  static int _commRank, _commSize;
  // verbosity level
  static int _verbosity;
  // step (in %) of the progress meter and current progress %
  static int _progressMeterStep, _progressMeterCurrent;
 public:
  Message() {}
  static int GetCommRank(){ return _commRank; }
  static int GetCommSize(){ return _commSize; }
  static void SetCommRank(int val){ _commRank = val; }
  static void SetCommSize(int val){ _commSize = val; }
  static void Barrier();
  static void SetVerbosity(int val){ _verbosity = val; }
  static void Fatal(char *fmt, ...);
  static void Error(char *fmt, ...);
  static void Warning(char *fmt, ...);
  static void Info(char *fmt, ...);
  static void Debug(char *fmt, ...);
  static void Cpu(char *fmt, ...);
  static void ProgressMeter(int n, int N);
  static void ProgressMeter(int n, int N, char *fmt, ...);
  static void ResetProgressMeter(int step=10);
};

typedef Message Msg;

#endif
