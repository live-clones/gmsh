#ifndef _STATIC_H_
#define _STATIC_H_

/* This file defines the static structures for Gmsh. It should be
   included only once, in your 'main' file */

char        yyname[NAME_STR_L];
int         yyerrorstate;

int         CurrentNodeNumber, CurrentSimplexNumber;

Context_T   CTX ;
Mesh        M, *THEM, *LOCAL;

#endif
