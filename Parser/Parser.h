/* $Id: Parser.h,v 1.3 2000-11-23 14:11:38 geuzaine Exp $ */
#ifndef _PARSER_H_
#define _PARSER_H_

typedef struct {
  char *Name;
  double val;
} Symbol;

void InitSymbols (void);
void DeleteSymbols(void);
int  CompareSymbols (const void *a, const void *b);

extern List_T *Symbol_L;

int yyparse (void);
int yylex ();

extern FILE   *yyin;
extern int     yylineno;
extern char    yyname[NAME_STR_L];
extern char   *yytext;
extern int     yyerrorstate;


#endif
