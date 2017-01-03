// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _FUNCTION_MANAGER_H_
#define _FUNCTION_MANAGER_H_

class mystack;
class mymap;

#include <string>
#include "GmshIO.h"

// Singleton, one function manager for all parsers.

class FunctionManager
{
  mymap *functions;
  mystack *calls;
  FunctionManager ();
  static FunctionManager *instance;
 public :
  static FunctionManager* Instance();
  int createFunction(const std::string &name, gmshFILE f,
                     const std::string &filename, int lineno);
  int enterFunction(const std::string &name, gmshFILE *f,
                    std::string &filename, int &lineno) const;
  int leaveFunction(gmshFILE *f, std::string &filename, int &lineno);
  void clear();
};

#endif
