#ifndef BISON_GEOMETRY_H
# define BISON_GEOMETRY_H

#ifndef YYSTYPE
typedef union {
double val;
char * chptr;
Solid * solidtype;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
# define	NUM	257
# define	TOK_SOLID	258
# define	TOK_RECO	259
# define	TOK_TLO	260
# define	TOK_BOUNDINGBOX	261
# define	IDENT	262
# define	IDENTSOLID	263
# define	TOK_SPHERE	264
# define	TOK_CYLINDER	265
# define	TOK_CONE	266
# define	TOK_PLAIN	267
# define	TOK_TUBE	268
# define	TOK_GENCYL	269
# define	TOK_ORTHOBRICK	270
# define	TOK_POLYHEDRON	271
# define	TOK_REVOLUTION	272
# define	TOK_OR	273
# define	TOK_AND	274
# define	TOK_NOT	275
# define	TOK_TRANSLATE	276
# define	TOK_MULTITRANSLATE	277
# define	TOK_ROTATE	278
# define	TOK_MULTIROTATE	279
# define	TOK_SINGULAR	280
# define	TOK_EDGE	281
# define	TOK_POINT	282
# define	TOK_IDENTIFY	283
# define	TOK_CLOSESURFACES	284
# define	TOK_CLOSEEDGES	285
# define	TOK_PERIODIC	286
# define	TOK_BOUNDARYCONDITION	287


extern YYSTYPE yylval;

#endif /* not BISON_GEOMETRY_H */
