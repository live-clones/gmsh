// $Id: FunctionManager.cpp,v 1.7 2001-01-09 19:40:56 remacle Exp $

#include <stdio.h>
#include <stack>
#include <map>
#include "FunctionManager.h"

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
};

// Pour utiliser un namespace global sur SGI, il faut compiler avec
// -LANG:std, et ajouter "use namespace std;". Dans tous les cas, il
// FAUT creer les librairies avec 'CC -ar', et pas avec 'ar'.

class mystack
{
public:
#ifdef WIN32
	std::stack<File_Position> s;
#else
	stack<File_Position> s;
#endif
};
class mymap
{
public :
#ifdef WIN32
    std::map<char*,File_Position,ltstr> m;
#else
	map<char*,File_Position,ltstr> m;
#endif
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

int FunctionManager::enterFunction(char *name, FILE **f, int &lno) const
{
  if(functions->m.find(name) == functions->m.end())return 0;
  File_Position fpold;
  fpold.lineno = lno;
  fpold.file = *f;
  fgetpos(fpold.file,&fpold.position);
  calls->s.push(fpold);
  File_Position fp = (functions->m)[name];
  fsetpos(fp.file,&fp.position);
  *f = fp.file;
  lno = fp.lineno;
  return 1;
}

int FunctionManager::leaveFunction(FILE **f,int &lno)
{
  if(!calls->s.size())return 0;
  File_Position fp;
  fp = calls->s.top();
  calls->s.pop();
  fsetpos(fp.file,&fp.position);
  *f = fp.file;
  lno = fp.lineno;
  return 1;
}

int FunctionManager::createFunction(char *name, FILE *f, int lno)
{
  File_Position fp;
  fp.file = f;
  fp.lineno = lno;
  fgetpos(fp.file,&fp.position);
  (functions->m)[name] = fp;
  return 1;
}




