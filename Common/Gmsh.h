/* $Id: Gmsh.h,v 1.2 2000-11-23 14:11:27 geuzaine Exp $ */
#ifndef _GMSH_H_
#define _GMSH_H_

/* This header should be included in any Gmsh source file. Modify it
   only if really necessary, since it will force the whole code to be
   rebuilt... */

#undef true
#define true  1

#undef false
#define false 0

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
