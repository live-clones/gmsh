// $Id: FunctionManager.cpp,v 1.24 2006-08-19 01:12:40 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include <stdio.h>
#include <stack>
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
  char filename[256];
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

int FunctionManager::enterFunction(char *name, FILE ** f, char *filename,
                                   int &lno) const
{
  if(functions->m.find(name) == functions->m.end())
    return 0;
  File_Position fpold;
  fpold.lineno = lno;
  strcpy(fpold.filename, filename);
  fpold.file = *f;
  fgetpos(fpold.file, &fpold.position);
  calls->s.push(fpold);
  File_Position fp = (functions->m)[name];
  fsetpos(fp.file, &fp.position);
  *f = fp.file;
  strcpy(filename, fp.filename);
  lno = fp.lineno;
  return 1;
}

int FunctionManager::leaveFunction(FILE ** f, char *filename, int &lno)
{
  if(!calls->s.size())
    return 0;
  File_Position fp;
  fp = calls->s.top();
  calls->s.pop();
  fsetpos(fp.file, &fp.position);
  *f = fp.file;
  strcpy(filename, fp.filename);
  lno = fp.lineno;
  return 1;
}

int FunctionManager::createFunction(char *name, FILE * f, char *filename,
                                    int lno)
{
  File_Position fp;
  fp.file = f;
  strcpy(fp.filename, filename);
  fp.lineno = lno;
  fgetpos(fp.file, &fp.position);
  (functions->m)[name] = fp;
  return 1;
}
