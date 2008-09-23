#ifndef FILE_PARTHREADS
#define FILE_PARTHREADS

/**************************************************************************/
/* File:   parthreads.hh                                                  */
/* Author: Joachim Schoeberl                                              */
/* Date:   22. Nov. 2000                                                  */
/**************************************************************************/

/*
  Parallel thread, Mutex, 
*/

#ifdef NO_PARALLEL_THREADS

class NgMutex { };

class NgLock
{
public:	
  NgLock (NgMutex & mut, bool lock = 0) { ; }
  void Lock () { ; }
  void UnLock () { ; }
};


#else

#ifdef WIN32

class NgMutex
{
  CCriticalSection cs;
  
public:
  NgMutex () 
  { ; }
  friend class NgLock;
};

class NgLock
{
  CSingleLock sl;
  bool locked;
public:	
  NgLock (NgMutex & mut, bool lock = 0)
    : sl(&mut.cs)
  {
    if (lock) sl.Lock();
    locked = lock;
  }

  ~NgLock ()
  {
    if (locked) sl.Unlock();
  }

  void Lock ()
  {
    sl.Lock(); 
    locked = 1;
  }

  void UnLock ()
  { 
    sl.Unlock(); 
    locked = 0;
  }
};

#else


#include <pthread.h>

class NgMutex
{
  pthread_mutex_t mut;
public:
  NgMutex ()
  {
    pthread_mutex_init (&mut, NULL);
  }
  friend class NgLock;
};

class NgLock 
{
  pthread_mutex_t & mut;
  bool locked;
public:
  NgLock (NgMutex & ngmut, bool lock = 0)
    : mut (ngmut.mut)
  { 
    if (lock) pthread_mutex_lock (&mut); 
    locked = lock;
  };

  ~NgLock()
  {
    if (locked) pthread_mutex_unlock (&mut); 
  }
  
  void Lock ()
  { 
    pthread_mutex_lock (&mut); 
    locked = 1;
  }
  void UnLock ()
  { 
    pthread_mutex_unlock (&mut); 
    locked = 0;
  }
  /*
  int TryLock ()
  { 
    return pthread_mutex_trylock (&mut); 
  }
  */
};

#endif

#endif

#endif
