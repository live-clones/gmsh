#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef SUN4
#include <sys/varargs.h>
#else
#include <stdarg.h>
#endif
#include "ParUtil.h"
#ifdef PARALLEL
#include "autopack.h"
#else
#include <sys/time.h>
#endif

ParUtil* ParUtil::Instance()
{
  if(!instance)
    {
      instance = new ParUtil;
    }
  return instance;
}

ParUtil::~ParUtil() 
{
}

ParUtil::ParUtil() 
{
}

void ParUtil::init(int &argc, char **&argv) {

#ifdef PARALLEL
  int namelen;
  char name[1024];
  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &mysize);
  
  MPI_Comm_dup(MPI_COMM_WORLD, &seq_local_comm);
  MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  AP_init(&argc, &argv);
  AP_setparam(10*4096, 1, 1024, -1);
  MPI_Get_processor_name(name,&namelen);
  procName = new char[namelen+1];
  strcpy(procName,name);
  char logname[256];
  sprintf(logname,"log-proc%d-%s.dat",myrank,procName);
  log = fopen (logname,"w");
  vl = 1;
#endif
}

double ParUtil::wTime() const
{

#ifdef PARALLEL
  return MPI_Wtime(); 
#else
  struct timeval tp;
  struct timezone tzp;
  double timeval;
  
  gettimeofday(&tp,&tzp);
  
  timeval = (double) tp.tv_sec;
  timeval = timeval + (double) ((double) .000001 * (double) tp.tv_usec);
  
  return(timeval);
#endif
}

void ParUtil::processorName(char *name) const
{
#ifdef PARALLEL
  strcpy(name,procName);
#else
  strcpy(name,"localhost");
#endif
}

void ParUtil:: Msg(ParUtil::MessageLevel level, char *fmt, ...)
{ 
  char buff[1024];
  va_list  args;
  va_start (args, fmt);
  vsprintf(buff, fmt, args);
  va_end (args);

  switch(level)
    {
    case DEBUG1:
      if(vl > 1)
	{
	  fprintf(log,"%s",buff);
	  fflush(log);
	}
      break;
    case DEBUG2:
      if(vl > 2)
	{
	  fprintf(log,"%s",buff);
	  fflush(log);
	}
      break;
    case INFO:
      if(vl >= 0 && master())
	{
	  //	  fprintf(log,"%s",buff);
	  fprintf(stdout,"%s",buff);
	  //	  fflush(log);
	}
      if(vl > 2)
	{
	  //	  fprintf(log,"%s",buff);
	  //	  fflush(log);
	}
      break;
    case WARNING:
      fprintf(stdout,"Processor %d AOMD WARNING : %s",rank(),buff);
      fflush(stdout);
      break;
    case ERROR:
      fprintf(stdout,"AOMD FATAL ERROR : %s",buff);
      fflush(stdout);
      Abort();
      break;
    }
}

void ParUtil::Abort()
{
#ifdef PARALLEL
  MPI_Abort(MPI_COMM_WORLD, 1);
#else
  abort();
#endif
}

void ParUtil::Barrier(int line, const char *fn)
{
#ifdef PARALLEL
  Msg(DEBUG2,"BARRIER : Line %d in %s\n",line,fn);
  MPI_Barrier(MPI_COMM_WORLD);
  Msg(DEBUG2,"BARRIER PASSED : Line %d in %s\n",line,fn);
#endif
}

ParUtil* ParUtil::instance = 0;
