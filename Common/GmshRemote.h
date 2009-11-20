// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_REMOTE_H_
#define _GMSH_REMOTE_H_

#include <string>

#define MPI_GMSH_COMPUTE_VIEW  1
#define MPI_GMSH_DATA_READY    2
#define MPI_GMSH_VARRAY        3
#define MPI_GMSH_VARRAY_LEN    4
#define MPI_GMSH_SHUTDOWN      5
#define MPI_GMSH_PARSE_STRING  6
#define MPI_GMSH_MERGE_FILE    7

int GmshRemote();

#endif

