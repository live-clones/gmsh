/* $Id: Static.h,v 1.6 2000-11-26 15:43:44 geuzaine Exp $ */
#ifndef _STATIC_H_
#define _STATIC_H_

/* This file defines the static structures for Gmsh. It should be
   included only once, in your 'main' file */

char        TheFileName[NAME_STR_L], TheBaseFileName[NAME_STR_L];
char        yyname[NAME_STR_L];
int         yyerrorstate;

int         CurrentNodeNumber, CurrentSimplexNumber;

Context_T   CTX ;
Mesh        M, *THEM, *LOCAL;

Tree_T     *EntitesVisibles = NULL;
int         FLAG_OLD_CIRCLE = 0 ; /* Pour David : cercles > Pi */

#endif
