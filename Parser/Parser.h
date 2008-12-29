// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PARSER_H_
#define _PARSER_H_

#include <map>
#include <string>
#include <vector>

int gmsh_yyparse();
int gmsh_yylex();
void gmsh_yyflush();

// global parser variables that need to be exported
extern FILE *gmsh_yyin;
extern int gmsh_yylineno;
extern char *gmsh_yytext;
extern int gmsh_yyviewindex;
extern char gmsh_yyname[256];
extern int gmsh_yyerrorstate;
extern std::map<std::string, std::vector<double> > gmsh_yysymbols;

#endif
