#include <stdarg.h>
#include "Bindings.h"
#include <stdio.h>
void methodBinding::setArgNames(const char *arg1, ...) {
  va_list ap;
  va_start(ap,arg1);
  const char * name=arg1;
  while(name!=NULL){
    _argNames.push_back(name);
    name = va_arg(ap,const char *);
  }
  va_end(ap);
}
