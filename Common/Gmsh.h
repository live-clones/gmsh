#ifndef _GMSH_H_
#define _GMSH_H_

/* This header should be included in any Gmsh source file. Modify it
   only if really necessary, since it will force the whole code to be
   rebuilt... */

#undef bool
#define bool int

#undef true
#define true  1

#undef false
#define false 0

#define TEXT_BUFFER_SIZE       1024
#define SELECTION_BUFFER_SIZE  1024
#define LABEL_STR_L            16
#define MAX_OPEN_FILES         256

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Message.h"
#include "Malloc.h"
#include "List.h"
#include "Tree.h"
#include "Tools.h"

#endif
