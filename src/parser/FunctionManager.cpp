// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <stack>
#include <string>
#include "FunctionManager.h"

class File_Position
{
 public:
  int lineno;
  fpos_t position;
  FILE *file;
  std::string filename;
};

class FunctionManagerStack
{
 public:
  std::stack<File_Position> s;
};

class FunctionManagerMap
{
 public:
  std::map<std::string, File_Position> m;
};

FunctionManager *FunctionManager::instance = nullptr;

FunctionManager::FunctionManager()
{
  functions = new FunctionManagerMap;
  calls = new FunctionManagerStack;
}

FunctionManager *FunctionManager::Instance()
{
  if(!instance) {
    instance = new FunctionManager;
  }
  return instance;
}

void FunctionManager::clear()
{
  functions->m.clear();
}

int FunctionManager::enterFunction(const std::string &name, FILE **f,
                                   std::string &filename, int &lno) const
{
  if(functions->m.find(name) == functions->m.end())
    return 0;
  File_Position fpold;
  fpold.lineno = lno;
  fpold.filename = filename;
  fpold.file = *f;
  fgetpos(fpold.file, &fpold.position);
  calls->s.push(fpold);
  File_Position fp = (functions->m)[name];
  fsetpos(fp.file, &fp.position);
  *f = fp.file;
  filename = fp.filename;
  lno = fp.lineno;
  return 1;
}

int FunctionManager::leaveFunction(FILE **f, std::string &filename, int &lno)
{
  if(!calls->s.size())
    return 0;
  File_Position fp;
  fp = calls->s.top();
  calls->s.pop();
  fsetpos(fp.file, &fp.position);
  *f = fp.file;
  filename = fp.filename;
  lno = fp.lineno;
  return 1;
}

int FunctionManager::createFunction(const std::string &name, FILE *f,
                                    const std::string &filename, int lno)
{
  if(functions->m.find(name) != functions->m.end())
    return 0;
  File_Position fp;
  fp.file = f;
  fp.filename = filename;
  fp.lineno = lno;
  fgetpos(fp.file, &fp.position);
  (functions->m)[name] = fp;
  return 1;
}
