#ifndef _PARSER_H_
#define _PARSER_H_

// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

typedef struct {
  char *Name;
  List_T *val;
} Symbol;

void InitSymbols (void);
void DeleteSymbols(void);
int  CompareSymbols (const void *a, const void *b);

extern List_T *Symbol_L;

int yyparse (void);
int yylex ();

extern FILE   *yyin;
extern int     yylineno;
extern char    yyname[256];
extern char   *yytext;
extern int     yyerrorstate;


#endif
