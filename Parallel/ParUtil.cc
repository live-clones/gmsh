#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParUtil.h"
#ifdef PARALLEL
#include "mpi.h"
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
  
  MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  MPI_Get_processor_name(name,&namelen);
  procName = new char[namelen+1];
  strcpy(procName,name);
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
  MPI_Barrier(MPI_COMM_WORLD);
#endif
}

ParUtil* ParUtil::instance = 0;

