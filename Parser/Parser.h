// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PARSER_H_
#define _PARSER_H_

#include "ListUtils.h"
#include "TreeUtils.h"

typedef struct {
  char *Name;
  List_T *val;
} Symbol;

void InitSymbols();

extern Tree_T *Symbol_T;

int gmsh_yyparse();
int gmsh_yylex();

void force_yyflush();

extern FILE *gmsh_yyin;
extern int gmsh_yylineno;
extern char *gmsh_yytext;

extern int gmsh_yyviewindex;
extern char gmsh_yyname[256];
extern int gmsh_yyerrorstate;

#endif
