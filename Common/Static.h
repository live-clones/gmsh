#ifndef _STATIC_H_
#define _STATIC_H_

/* This file defines the static structures for Gmsh. It should be
   included only once, in any 'main' file */

#include "Version.h"

char gmsh_progname[]  = "This is Gmsh" ;
char gmsh_copyright[] = "Copyright (C) 1997-2000 J.-F. Remacle, C. Geuzaine";
char gmsh_version[]   = "Version          : " ;
char gmsh_os[]        = "Operating System : " GMSH_OS ;
char gmsh_date[]      = "Build Date       : " GMSH_DATE ;
char gmsh_host[]      = "Build Host       : " GMSH_HOST ;
char gmsh_packager[]  = "Packager         : " GMSH_PACKAGER ;
char gmsh_email[]     = "E-Mail           : "
                        "Christophe.Geuzaine@ulg.ac.be, Remacle@scorec.rpi.edu";
char gmsh_url[]       = "URL              : http://www.geuz.org/gmsh/";


char TheFileName[NAME_STR_L], TheBaseFileName[NAME_STR_L];
char yyname[NAME_STR_L];
int  yyerrorstate;

Context_T   CTX ;
Mesh        M, *THEM, *LOCAL;
int         CurrentNodeNumber, CurrentSimplexNumber;
Tree_T     *EntitesVisibles = NULL;
List_T     *Post_ViewList = NULL;

double      LC, MiddleLC ;
int         LC_ORDER;
double      FACTEUR_MULTIPLICATIF=1.0, GLOBALSCALINGFACTOR=1.0;

/* Some garbage */

int  TYPBGMESH=WITHPOINTS;
int  FLAG_OLD_CIRCLE = 0 ; /* Pour David : cercles > Pi */


#endif
