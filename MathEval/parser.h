#ifndef BISON_PARSER_HPP
# define BISON_PARSER_HPP

#ifndef YYSTYPE
typedef union {
  Node *node;
  Record *record;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
# define	NUMBER	257
# define	VARIABLE	258
# define	FUNCTION	259
# define	NEG	260


extern YYSTYPE melval;

#endif /* not BISON_PARSER_HPP */
