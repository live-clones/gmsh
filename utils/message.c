
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <stdarg.h>

void Msg(int level, char *fmt, ...){
  va_list  args;
  va_start (args, fmt);
  vfprintf(stderr, fmt, args); fprintf(stderr, "\n");
  va_end (args);
}

