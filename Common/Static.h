/* $Id: Static.h,v 1.5 2000-11-25 15:26:10 geuzaine Exp $ */
#ifndef _STATIC_H_
#define _STATIC_H_

/* This file defines the static structures for Gmsh. It should be
   included only once, in your 'main' file */

char  TheFileName[NAME_STR_L], TheBaseFileName[NAME_STR_L];
char  yyname[NAME_STR_L];
int   yyerrorstate;

Context_T   CTX ;
Mesh        M, *THEM, *LOCAL;
int         TYPBGMESH=WITHPOINTS,CurrentNodeNumber, CurrentSimplexNumber;
Tree_T     *EntitesVisibles = NULL;

double      LC, MiddleLC ;
int         LC_ORDER;

int         FLAG_OLD_CIRCLE = 0 ; /* Pour David : cercles > Pi */


#endif
