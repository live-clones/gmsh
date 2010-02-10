// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <map>
#include <stdio.h>
#include <stack>
#include <string.h>
#include "FunctionManager.h"

struct ltstr
{
  bool operator() (const char *s1, const char *s2)const
  {
    return strcmp(s1, s2) < 0;
  }
};

class File_Position
{
 public:
  int lineno;
  fpos_t position;
  FILE *file;
  std::string filename;
};

class mystack
{
 public:
  std::stack<File_Position> s;
};

class mymap
{
 public: 
  std::map<char*, File_Position, ltstr> m;
};

FunctionManager *FunctionManager::instance = 0;

FunctionManager::FunctionManager()
{
  functions = new mymap;
  calls = new mystack;
}

FunctionManager *FunctionManager::Instance()
{
  if(!instance) {
    instance = new FunctionManager;
  }
  return instance;
}

int FunctionManager::enterFunction(char *name, FILE ** f, std::string &filename,
                                   int &lno) const
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

int FunctionManager::leaveFunction(FILE ** f, std::string &filename, int &lno)
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

int FunctionManager::createFunction(char *name, FILE * f, std::string &filename,
                                    int lno)
{
  File_Position fp;
  fp.file = f;
  fp.filename = filename;
  fp.lineno = lno;
  fgetpos(fp.file, &fp.position);
  (functions->m)[name] = fp;
  return 1;
}
