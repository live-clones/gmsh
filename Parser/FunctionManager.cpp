// $Id: FunctionManager.cpp,v 1.13 2001-10-04 14:32:11 geuzaine Exp $

#include <map>
#include <stdio.h>
#include <stack>
#include "FunctionManager.h"

using namespace std;

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
    int lineno;
    fpos_t position;
    FILE *file;
    char filename[256];
};

// Pour utiliser un namespace global sur SGI, il faut compiler avec
// -LANG:std, et ajouter "using namespace std;". Dans tous les cas, il
// FAUT creer les librairies avec 'CC -ar', et pas avec 'ar'.

class mystack
{
public:
  stack<File_Position> s;
};
class mymap
{
public :
  map<char*,File_Position,ltstr> m;
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

int FunctionManager::enterFunction(char *name, FILE **f, char *filename, int &lno) const
{
  if(functions->m.find(name) == functions->m.end())return 0;
  File_Position fpold;
  fpold.lineno = lno;
  strcpy(fpold.filename,filename);
  fpold.file = *f;
  fgetpos(fpold.file,&fpold.position);
  calls->s.push(fpold);
  File_Position fp = (functions->m)[name];
  fsetpos(fp.file,&fp.position);
  *f = fp.file;
  strcpy(filename, fp.filename);
  lno = fp.lineno;
  return 1;
}

int FunctionManager::leaveFunction(FILE **f, char *filename, int &lno)
{
  if(!calls->s.size())return 0;
  File_Position fp;
  fp = calls->s.top();
  calls->s.pop();
  fsetpos(fp.file,&fp.position);
  *f = fp.file;
  strcpy(filename, fp.filename);
  lno = fp.lineno;
  return 1;
}

int FunctionManager::createFunction(char *name, FILE *f, char *filename, int lno)
{
  File_Position fp;
  fp.file = f;
  strcpy(fp.filename, filename);
  fp.lineno = lno;
  fgetpos(fp.file,&fp.position);
  (functions->m)[name] = fp;
  return 1;
}




