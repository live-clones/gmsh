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
extern char    yyname[256];
extern char   *yytext;
extern int     yyerrorstate;


#endif
