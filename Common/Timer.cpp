#include <sys/time.h>
#include <unistd.h>

long GetTime(){
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *) 0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

