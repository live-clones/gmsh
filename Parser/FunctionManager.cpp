#include "FunctionManager.h"
#include <stdio.h>
#include <stack>
#include <map>

struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

class File_Position 
{
  public :
    fpos_t position;
    FILE *file;
};

class mystack
{
public:
  std::stack<File_Position> s;
};
class mymap
{
public :
  std::map<char*,File_Position,ltstr> m;
};

FunctionManager *FunctionManager::instance = 0;

FunctionManager::FunctionManager()
{
  functions = new mymap;
  calls = new mystack;
}

FunctionManager* FunctionManager::Instance()
{
  if(!instance)
    {
      instance = new FunctionManager;
    }
  return instance;
}

bool FunctionManager::enterFunction(char *name, FILE **f) const
{
  if(functions->m.find(name) == functions->m.end())return false;
  File_Position fpold;
  fpold.file = *f;
  fgetpos(fpold.file,&fpold.position);
  calls->s.push(fpold);
  File_Position fp = (functions->m)[name];
  fsetpos(fp.file,&fp.position);
  *f = fp.file;
  return true;
}

bool FunctionManager::leaveFunction(FILE **f)
{
  if(!calls->s.size())return false;
  File_Position fp;
  fp = calls->s.top();
  calls->s.pop();
  fsetpos(fp.file,&fp.position);
  *f = fp.file;
  return true;
}

bool FunctionManager::createFunction(char *name, FILE *f)
{
  File_Position fp;
  fp.file = f;
  fgetpos(fp.file,&fp.position);
  (functions->m)[name] = fp;
  return true;
}




