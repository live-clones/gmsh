// $Id: ParUtil.cpp,v 1.11 2005-01-01 19:35:32 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParUtil.h"
#ifdef HAVE_PARALLEL
#include "mpi.h"
#else
#include <sys/time.h>
#endif

ParUtil *ParUtil::Instance()
{
  if(!instance) {
    instance = new ParUtil;
  }
  return instance;
}

ParUtil::~ParUtil()
{
  ;
}

ParUtil::ParUtil()
{
  ;
}

void ParUtil::init(int &argc, char **&argv)
{
#ifdef HAVE_PARALLEL
  int namelen;
  char name[1024];
  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &mysize);

  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
  MPI_Get_processor_name(name, &namelen);
  procName = new char[namelen + 1];
  strcpy(procName, name);
#endif
}

double ParUtil::wTime() const
{
#ifdef HAVE_PARALLEL
  return MPI_Wtime();
#else
  struct timeval tp;
  struct timezone tzp;
  double timeval;

  gettimeofday(&tp, &tzp);

  timeval = (double)tp.tv_sec;
  timeval = timeval + (double)((double).000001 * (double)tp.tv_usec);

  return (timeval);
#endif
}

void ParUtil::processorName(char *name) const
{
#ifdef HAVE_PARALLEL
  strcpy(name, procName);
#else
  strcpy(name, "localhost");
#endif
}

void ParUtil::Abort()
{
#ifdef HAVE_PARALLEL
  MPI_Abort(MPI_COMM_WORLD, 1);
#else
  abort();
#endif
}

void ParUtil::Exit()
{
#ifdef HAVE_PARALLEL
  MPI_Finalize();
#else
  exit(0);
#endif
}

void ParUtil::Barrier(int line, const char *fn)
{
#ifdef HAVE_PARALLEL
  MPI_Barrier(MPI_COMM_WORLD);
#endif
}

ParUtil *ParUtil::instance = 0;
