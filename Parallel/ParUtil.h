#ifndef _H_ParUtil
#define _H_ParUtil
#include <stdio.h>

#ifdef PARALLEL
#include "mpi.h"
#endif

/**
   ParUtil is a Singleton. It gives some
   general services for parallel implementation.
*/

class ParUtil {
  ParUtil();
  ~ParUtil();
public:
  /// Message severity level
  typedef enum MessageLevel {DEBUG1,DEBUG2,INFO,WARNING,ERROR};
  /// returne the only instance
  static ParUtil* Instance();
  /// initialization, needed for mpi and autopack
  void init(int &argc, char **&argv);
  /// adds a barrier
  void Barrier(int, const char*);
  /// compute wall time
  double wTime () const;
  /// gets the processor name
  void processorName(char *name) const;
  /// set the verbosity level (0,1,2,3)
  inline void setVertbosityLevel(int i){vl = i;}
  /// prints a message, same format as printf
  void Msg(MessageLevel lev, char *fmt, ...);
  /// abort a calculation
  void Abort();
#ifdef PARALLEL
  inline int rank() { return myrank; }
  inline int size() { return mysize; }
  inline int master() { return myrank==0; }
#else
  /// gets the processor id
  inline int rank() { return 0; }
  /// gets the number of processors
  inline int size() { return 1; }
  /// tells if it's processor 0
  inline int master() { return 1; }
#endif
private:
  static ParUtil *instance;
  FILE *log;
  int vl;
  int procSpeed;
  char *procName;
#ifdef PARALLEL
  int myrank;
  int mysize;
  MPI_Comm seq_local_comm;
#endif
};

#endif






