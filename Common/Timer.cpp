// $Id: Timer.cpp,v 1.4 2001-02-09 07:59:50 geuzaine Exp $

#if defined(WIN32) && !defined(__CYGWIN__)

long GetTime(){
  return 0;
}

#else

#include <sys/time.h>
#include <unistd.h>
long GetTime(){
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

#endif
