// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FUNCTION_MANAGER_H_
#define _FUNCTION_MANAGER_H_

class mystack;
class mymap;

#include <stdio.h>

// Singleton, one function manager for all parsers. 

class FunctionManager
{
  mymap *functions;
  mystack *calls;  
  FunctionManager ();
  static FunctionManager *instance;
 public :
  static FunctionManager* Instance();
  int createFunction(char *name, FILE *f, char *filename, int lineno);
  int enterFunction(char *name, FILE **f, char *filename, int &lineno) const;
  int leaveFunction(FILE **f, char *filename, int &lineno);
};

#endif
