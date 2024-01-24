// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FUNCTION_MANAGER_H
#define FUNCTION_MANAGER_H

#include <cstdio>
#include <string>

// Singleton, one function manager for all parsers.

class FunctionManagerStack;
class FunctionManagerMap;

class FunctionManager
{
  FunctionManagerMap *functions;
  FunctionManagerStack *calls;
  FunctionManager ();
  static FunctionManager *instance;
 public :
  static FunctionManager* Instance();
  int createFunction(const std::string &name, FILE *f,
                     const std::string &filename, int lineno);
  int enterFunction(const std::string &name, FILE **f,
                    std::string &filename, int &lineno) const;
  int leaveFunction(FILE **f, std::string &filename, int &lineno);
  void clear();
};

#endif
