#ifndef _H_ParUtil
#define _H_ParUtil

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

/**
   ParUtil is a Singleton. It gives some
   general services for parallel implementation.
*/

class ParUtil {
  ParUtil();
  ~ParUtil();
public:
  /// returne the only instance
  static ParUtil* Instance();
  /// initialization, needed for mpi and autopack
  void init(int &argc, char **&argv);
  /// adds a barrier
  void Barrier(int, const char*);
  /// compute wall time
  void Exit();
  /// compute wall time
  double wTime () const;
  /// gets the processor name
  void processorName(char *name) const;
  /// abort a calculation
  void Abort();
#ifdef PARALLEL
  inline int rank() { return myrank; }
  inline int size() { return mysize; }
  inline int master() { return myrank==0; }
#else
  /// gets the processor id
  inline int rank() { return 0; }
  /// gets the number of processors
  inline int size() { return 1; }
  /// tells if it's processor 0
  inline int master() { return 1; }
#endif
private:
  static ParUtil *instance;
  char *procName;
#ifdef PARALLEL
  int myrank;
  int mysize;
#endif
};

#endif






