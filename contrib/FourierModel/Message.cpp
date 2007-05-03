#include <stdlib.h>
#include <stdio.h>

#if !defined(WIN32) || defined(__CYGWIN__)
#include <sys/time.h>
#include <sys/resource.h>
#endif

#if defined(__APPLE__)
#define RUSAGE_SELF      0
#define RUSAGE_CHILDREN -1
#endif

#include "Message.h"

int Message::_commRank = 0;
int Message::_commSize = 1;
int Message::_verbosity = 3;
int Message::_progressMeterStep = 10;
int Message::_progressMeterCurrent = 0;

void Message::Fatal(char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  if(_commSize > 1) 
    fprintf(stderr, "Fatal   : [On processor %d] ", _commRank);
  else
    fprintf(stderr, "Fatal   : ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}

void Message::Error(char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  if(_commSize > 1) 
    fprintf(stderr, "Error   : [On processor %d] ", _commRank);
  else
    fprintf(stderr, "Error   : ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
}

void Message::Warning(char *fmt, ...)
{
  if(_commRank) return;
  if(_verbosity >= 1){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Warning : ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
  }
}

void Message::Info(char *fmt, ...)
{
  if(_commRank) return;
  if(_verbosity >= 2){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Info    : ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
  }
}

void Message::Debug(char *fmt, ...)
{
  if(_commRank) return;
  if(_verbosity >= 99){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Debug   : ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
  }
}

void Message::Cpu(char *fmt, ...)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  if(_commRank) return;
  if(_verbosity >= 1){
    static struct rusage r;
    getrusage(RUSAGE_SELF, &r);
    double s = (double)r.ru_utime.tv_sec;
    double us = (double)r.ru_utime.tv_usec;
    double mem = (double)r.ru_maxrss;
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Info    : ");
    vfprintf(stderr, fmt, args);
    if(mem)
      fprintf(stderr, " (CPU = %gs Mem = %gkb)\n", s + 1.e-6 * us, mem);
    else
      fprintf(stderr, " (CPU = %gs)\n", s + 1.e-6 * us);
    va_end(args);
  }
#endif
}

void Message::ResetProgressMeter(int step)
{
  _progressMeterStep = step;
  _progressMeterCurrent = 0;
}

void Message::ProgressMeter(int n, int N, char *fmt, ...)
{
  if(_commRank) return;
  if(_verbosity >= 2){
    va_list args;
    va_start(args, fmt);
    if(100. * (double)n/(double)N >= _progressMeterCurrent){
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "(%d %%)                     \r", _progressMeterCurrent);
      _progressMeterCurrent += _progressMeterStep;
    }
    if(n >= N - 1)
      fprintf(stderr, "Done!                                              \r");
  }
}

void Message::ProgressMeter(int n, int N)
{
  if(_commRank) return;
  if(_verbosity >= 2){
    if(100. * (double)n/(double)N >= _progressMeterCurrent){
      fprintf(stderr, "(%d %%)\r", _progressMeterCurrent);
      _progressMeterCurrent += _progressMeterStep;
    }
    if(n >= N - 1)
      fprintf(stderr, "          \r") ;
  }
}

#if defined(HAVE_PETSC)

#include "petsc.h"

void Message::Barrier()
{
  MPI_Barrier(PETSC_COMM_WORLD);
}

#else

void Message::Barrier()
{
}

#endif
