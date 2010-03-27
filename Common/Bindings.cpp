// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Jonathan Lambrechts
//

#include <stdarg.h>
#include <stdio.h>
#include "Bindings.h"

void methodBinding::setArgNames(const char *arg1, ...)
{
  va_list ap;
  va_start(ap, arg1);
  const char *name=arg1;
  while(name != NULL){
    _argNames.push_back(name);
    name = va_arg(ap, const char *);
  }
  va_end(ap);
}
