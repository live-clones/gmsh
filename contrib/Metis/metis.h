/*
 * Copyright 1997, Regents of the University of Minnesota
 *
 * metis.h
 *
 * This file includes all necessary header files
 *
 * Started 8/27/94
 * George
 *
 * $Id: metis.h,v 1.3 2009-08-14 08:25:25 geuzaine Exp $
 */


#include <stdio.h>
#ifdef __STDC__
#include <stdlib.h>
#else
#include <malloc.h>
#endif
//#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

#include <metisdefs.h> /* changed from <defs.h> for Gmsh, due to conflict with Chaco */
#include <struct.h>
#include <macros.h>
#include <rename.h>
#include <proto.h>

