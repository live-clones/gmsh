/* A Bison parser, made from geometry.yy
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "geometry.yy"

//define YYDEBUG 1

extern int yylex ();

#include <mystdlib.h>

#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>

namespace netgen
{
netgen::CSGeometry * parsegeom;
}

using namespace netgen;

// extern ARRAY<Surface*> surfaces;
// extern SYMBOLTABLE<Solid*> solids;


int yyerror (char * s);
splinetube * tube;
spline3d * middlecurve;
Point<3> splinep1;
BSplineCurve2d *bspline;
Flags parseflags;
extern int linenum;
ARRAY<double> doublearray;
ARRAY<char*> stringarray;

Polyhedra * polyhedron;
// Revolution * revolution;

#line 38 "geometry.yy"
#ifndef YYSTYPE
typedef union {
double val;
char * chptr;
Solid * solidtype;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		260
#define	YYFLAG		-32768
#define	YYNTBASE	42

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 287 ? yytranslate[x] : 67)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,     2,     2,    38,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     1,     6,     7,    11,    12,    19,    21,    23,
      27,    31,    34,    38,    49,    66,    85,   100,   115,   116,
     125,   136,   149,   166,   185,   189,   191,   195,   197,   203,
     209,   217,   221,   223,   227,   229,   233,   245,   246,   252,
     253,   254,   261,   262,   266,   272,   279,   285,   291,   296,
     300,   305,   320,   329,   334,   335,   338,   339,   342,   345,
     350,   355,   360,   365,   366,   371,   373,   377,   378,   383,
     385,   389,   391
};
static const short yyrhs[] =
{
      -1,    43,     5,    44,    54,     0,     0,    44,    45,    34,
       0,     0,     4,     8,    35,    47,    46,    56,     0,    48,
       0,     9,     0,    47,    19,    47,     0,    47,    20,    47,
       0,    21,    47,     0,    36,    47,    37,     0,    10,    36,
       3,    38,     3,    38,     3,    34,     3,    37,     0,    11,
      36,     3,    38,     3,    38,     3,    34,     3,    38,     3,
      38,     3,    34,     3,    37,     0,    12,    36,     3,    38,
       3,    38,     3,    34,     3,    34,     3,    38,     3,    38,
       3,    34,     3,    37,     0,    13,    36,     3,    38,     3,
      38,     3,    34,     3,    38,     3,    38,     3,    37,     0,
      16,    36,     3,    38,     3,    38,     3,    34,     3,    38,
       3,    38,     3,    37,     0,     0,    17,    36,    49,    50,
      34,    34,    51,    37,     0,    22,    36,     3,    38,     3,
      38,     3,    34,    47,    37,     0,    23,    36,     3,    38,
       3,    38,     3,    34,     3,    34,    47,    37,     0,    24,
      36,     3,    38,     3,    38,     3,    34,     3,    38,     3,
      38,     3,    34,    47,    37,     0,    25,    36,     3,    38,
       3,    38,     3,    34,     3,    38,     3,    38,     3,    34,
       3,    34,    47,    37,     0,    50,    34,    52,     0,    52,
       0,    51,    34,    53,     0,    53,     0,     3,    38,     3,
      38,     3,     0,     3,    38,     3,    38,     3,     0,     3,
      38,     3,    38,     3,    38,     3,     0,    67,    34,    68,
       0,    68,     0,     3,    38,     3,     0,    70,     0,    70,
      38,    69,     0,     3,    38,     3,    38,     3,    38,     3,
      38,     3,    38,     3,     0,     0,     3,    38,     3,    72,
      73,     0,     0,     0,    38,     3,    38,     3,    74,    73,
       0,     0,    54,    55,    34,     0,    26,    27,     3,     9,
       9,     0,    26,    28,     3,     9,     9,     9,     0,    29,
      30,     9,     9,    56,     0,    29,    31,     9,     9,     9,
       0,    29,    32,     9,     9,     0,     6,     9,    56,     0,
       6,     9,     9,    56,     0,     7,    36,     3,    38,     3,
      38,     3,    34,     3,    38,     3,    38,     3,    37,     0,
      28,    36,     3,    38,     3,    38,     3,    37,     0,    33,
       9,     9,     3,     0,     0,    57,    58,     0,     0,    59,
      58,     0,    39,    66,     0,    39,    66,    35,    66,     0,
      39,    66,    35,     3,     0,    39,    66,    35,    60,     0,
      39,    66,    35,    63,     0,     0,    40,    61,    62,    41,
       0,     3,     0,    62,    38,     3,     0,     0,    40,    64,
      65,    41,     0,    66,     0,    65,    38,    66,     0,     8,
       0,     9,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    61,    61,    79,    81,    84,    84,    94,    96,    97,
      98,    99,   100,   103,   112,   123,   135,   144,   158,   158,
     197,   206,   222,   231,   285,   287,   289,   291,   293,   300,
     306,   315,   317,   319,   331,   333,   335,   345,   345,   354,
     356,   356,   372,   374,   377,   385,   394,   409,   425,   439,
     453,   470,   477,   482,   511,   511,   516,   518,   521,   524,
     526,   528,   530,   535,   535,   540,   542,   545,   545,   556,
     563,   574,   576
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "NUM", "TOK_SOLID", "TOK_RECO", "TOK_TLO", 
  "TOK_BOUNDINGBOX", "IDENT", "IDENTSOLID", "TOK_SPHERE", "TOK_CYLINDER", 
  "TOK_CONE", "TOK_PLAIN", "TOK_TUBE", "TOK_GENCYL", "TOK_ORTHOBRICK", 
  "TOK_POLYHEDRON", "TOK_REVOLUTION", "TOK_OR", "TOK_AND", "TOK_NOT", 
  "TOK_TRANSLATE", "TOK_MULTITRANSLATE", "TOK_ROTATE", "TOK_MULTIROTATE", 
  "TOK_SINGULAR", "TOK_EDGE", "TOK_POINT", "TOK_IDENTIFY", 
  "TOK_CLOSESURFACES", "TOK_CLOSEEDGES", "TOK_PERIODIC", 
  "TOK_BOUNDARYCONDITION", "';'", "'='", "'('", "')'", "','", "'-'", 
  "'['", "']'", "input", "@1", "recsoliddef", "soliddef", "@2", "solid", 
  "solidprimitive", "@3", "polyhedronpoints", "polyhedronfaces", 
  "polyhedronpoint", "polyhedronface", "recadddef", "adddef", "flaglist", 
  "@6", "recflaglist", "flag", "numlistbrack", "@7", "numlist", 
  "stringlistbrack", "@8", "stringlist", "anyident", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    43,    42,    44,    44,    46,    45,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    48,    48,    49,    48,
      48,    48,    48,    48,    50,    50,    51,    51,    52,    53,
      53,    67,    67,    68,    69,    69,    70,    72,    71,    73,
      74,    73,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    57,    56,    58,    58,    59,    59,
      59,    59,    59,    61,    60,    62,    62,    64,    63,    65,
      65,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     0,     4,     0,     3,     0,     6,     1,     1,     3,
       3,     2,     3,    10,    16,    18,    14,    14,     0,     8,
      10,    12,    16,    18,     3,     1,     3,     1,     5,     5,
       7,     3,     1,     3,     1,     3,    11,     0,     5,     0,
       0,     6,     0,     3,     5,     6,     5,     5,     4,     3,
       4,    14,     8,     4,     0,     2,     0,     2,     2,     4,
       4,     4,     4,     0,     4,     1,     3,     0,     4,     1,
       3,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       1,     0,     3,    42,     0,     0,     2,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,    54,    49,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    11,
       0,     0,     0,     0,     0,     0,     0,    54,    50,     0,
      55,    56,     0,     0,     0,     0,    54,     0,    48,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     9,    10,     6,    71,    72,    58,    57,     0,    44,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    67,    61,    62,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,    65,     0,     0,
      69,     0,     0,     0,     0,     0,     0,    28,     0,     0,
      19,     0,     0,     0,     0,     0,    64,     0,    68,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,    66,    70,     0,    13,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,    51,     0,     0,     0,     0,    30,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,     0,     0,
      14,     0,    22,     0,     0,     0,    15,    23,     0,     0,
       0
};

static const short yydefgoto[] =
{
     258,     1,     3,     5,    67,    40,    41,    85,   110,   161,
     111,   162,     6,    15,    43,    44,    70,    71,   133,   150,
     168,   134,   151,   169,    96
};

static const short yypact[] =
{
  -32768,     5,-32768,    18,    21,     7,    14,    11,-32768,    52,
      35,    36,    39,    28,    56,    42,     2,    58,    66,    74,
      75,    76,    71,    72,    73,    77,-32768,-32768,    48,    49,
      51,    53,    55,    57,     2,    59,    60,    61,    62,     2,
      54,-32768,-32768,-32768,    44,    50,    81,    83,    63,    85,
      90,    91,    99,   100,   101,   102,   103,   104,-32768,-32768,
     105,   106,   107,   108,    -3,     2,     2,-32768,-32768,    47,
  -32768,    44,   109,   110,   111,   112,-32768,   113,-32768,-32768,
      78,    79,    80,    86,    87,   118,    88,    89,    92,    93,
  -32768,-32768,-32768,-32768,-32768,-32768,    94,-32768,    95,-32768,
     114,    96,-32768,-32768,   125,   129,   132,   133,   134,   115,
     116,-32768,   135,   136,   137,   138,    -1,   139,-32768,   140,
     117,   119,   120,   121,   122,   141,     1,   123,   124,   126,
     127,-32768,   142,-32768,-32768,-32768,   144,   130,   143,   145,
     146,   148,   149,   128,   151,-32768,   153,   160,   165,   166,
     167,    47,   168,-32768,   147,   150,   152,   154,   155,   169,
     156,   -28,-32768,   157,   158,   159,   161,-32768,    -8,    16,
  -32768,   162,   170,   171,   172,   173,   176,-32768,   177,   151,
  -32768,     2,   179,   180,   182,   184,-32768,    47,-32768,   187,
     164,   174,   163,   175,   178,   183,-32768,    25,   181,   185,
     186,-32768,-32768,   188,-32768,   193,   195,   196,   199,   200,
  -32768,     2,   201,   202,   203,   189,   190,   191,   192,   194,
      29,   197,   198,   204,   205,   206,   208,   211,   214,-32768,
     215,   217,-32768,   209,   207,   210,   212,-32768,   216,   218,
     219,   222,-32768,-32768,     2,   228,   220,   221,    31,   224,
  -32768,   230,-32768,     2,   223,    33,-32768,-32768,   234,   237,
  -32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,-32768,   -34,-32768,-32768,-32768,-32768,
     -13,   -65,-32768,-32768,   -39,-32768,   213,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  -115
};


#define	YYLAST		284


static const short yytable[] =
{
      59,   135,   131,    68,   109,    64,   179,    94,    95,   180,
       2,    27,    28,    29,    30,    31,    65,    66,    32,    33,
       9,    10,     4,    34,    35,    36,    37,    38,    93,     7,
     185,    91,    92,   186,    90,   144,   170,   102,    39,   132,
      11,     8,    12,    13,    65,    66,    16,    14,    65,    66,
      65,    66,    65,    66,   187,    94,    95,   188,    22,    23,
      24,    17,   210,    19,    20,    25,   229,    42,   252,    45,
     257,    18,   202,    65,    66,    21,    26,    46,    47,    48,
      49,    50,    51,    69,    53,    54,    52,    55,    72,    56,
      73,    57,    74,    58,    76,    60,    61,    62,    63,    77,
      78,    75,    79,    80,    81,    82,    83,    84,    86,    87,
      88,    89,    98,   145,   196,   101,   104,   105,   106,    99,
     100,   109,   103,   118,   107,   108,   112,   113,   120,   116,
     114,   115,   121,   117,   119,   122,   123,   124,   127,   128,
     129,   130,   136,   137,   143,   -63,   154,   197,   155,   156,
     126,   157,   158,   125,   160,   138,   163,   139,   140,   141,
     142,   146,   147,   164,   148,   149,   159,   153,   165,   166,
     167,   171,   177,   190,   191,   192,   193,   220,   152,   194,
     195,   172,   198,   199,   173,   200,   174,   201,   175,   176,
     203,   181,   182,   183,   178,   184,   215,   206,   216,   217,
     189,   204,   218,   219,   221,   222,   223,     0,   233,   234,
     248,   235,   205,   207,   236,   211,   208,   237,   238,   255,
     239,   209,   246,   212,   213,   247,   214,   224,   225,   226,
     227,   249,   228,   254,   259,   230,   231,   260,     0,     0,
       0,   232,     0,   240,     0,   241,     0,   242,     0,   243,
     244,     0,   245,     0,     0,   251,     0,   250,   253,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97
};

static const short yycheck[] =
{
      34,   116,     3,    42,     3,    39,    34,     8,     9,    37,
       5,     9,    10,    11,    12,    13,    19,    20,    16,    17,
       6,     7,     4,    21,    22,    23,    24,    25,    67,     8,
      38,    65,    66,    41,    37,    34,   151,    76,    36,    40,
      26,    34,    28,    29,    19,    20,    35,    33,    19,    20,
      19,    20,    19,    20,    38,     8,     9,    41,    30,    31,
      32,     9,    37,    27,    28,     9,    37,     9,    37,     3,
      37,    36,   187,    19,    20,    36,    34,     3,     3,     3,
       9,     9,     9,    39,    36,    36,     9,    36,    38,    36,
       9,    36,     9,    36,     9,    36,    36,    36,    36,     9,
       9,    38,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   126,   179,     3,    38,    38,    38,     9,
       9,     3,     9,     9,    38,    38,    38,    38,     3,    35,
      38,    38,     3,    38,    38,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   181,     3,     3,
      34,     3,     3,    38,     3,    38,     3,    38,    38,    38,
      38,    38,    38,     3,    38,    38,    38,    37,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   211,    34,     3,
       3,    34,     3,     3,    34,     3,    34,     3,    34,    34,
       3,    34,    34,    34,    38,    34,     3,    34,     3,     3,
      38,    37,     3,     3,     3,     3,     3,    -1,     3,     3,
     244,     3,    38,    38,     3,    34,    38,     3,     3,   253,
       3,    38,     3,    38,    38,     3,    38,    38,    38,    38,
      38,     3,    38,     3,     0,    38,    38,     0,    -1,    -1,
      -1,    37,    -1,    34,    -1,    38,    -1,    37,    -1,    37,
      34,    -1,    34,    -1,    -1,    34,    -1,    37,    34,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#ifndef YYPARSE_RETURN_TYPE
#define YYPARSE_RETURN_TYPE int
#endif

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || ((YYLTYPE_IS_TRIVIAL || ! YYLSP_NEEDED) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 319 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
YYPARSE_RETURN_TYPE yyparse (void *);
# else
YYPARSE_RETURN_TYPE yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

YYPARSE_RETURN_TYPE
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 1:
#line 62 "geometry.yy"
{
		  linenum = 1;
		;
    break;}
case 2:
#line 69 "geometry.yy"
{
		int i;
		extern ARRAY<char*> parsestrings;
		for (i = 0; i < parsestrings.Size(); i++)
 		  delete [] parsestrings[i];
		parsestrings.SetSize(0);
		;
    break;}
case 5:
#line 86 "geometry.yy"
{ parsegeom->SetSolid(yyvsp[-2].chptr, new Solid (Solid::ROOT, yyvsp[0].solidtype)); 
		  ;
    break;}
case 6:
#line 89 "geometry.yy"
{ 
		  parsegeom->SetFlags(yyvsp[-4].chptr, parseflags); 
		  ;
    break;}
case 8:
#line 96 "geometry.yy"
{ yyval.solidtype = (Solid*)parsegeom->GetSolid(yyvsp[0].chptr);  ;
    break;}
case 9:
#line 97 "geometry.yy"
{ yyval.solidtype = new Solid (Solid::UNION, yyvsp[-2].solidtype, yyvsp[0].solidtype); ;
    break;}
case 10:
#line 98 "geometry.yy"
{ yyval.solidtype = new Solid (Solid::SECTION, yyvsp[-2].solidtype, yyvsp[0].solidtype); ;
    break;}
case 11:
#line 99 "geometry.yy"
{ yyval.solidtype = new Solid (Solid::SUB, yyvsp[0].solidtype); ;
    break;}
case 12:
#line 100 "geometry.yy"
{ yyval.solidtype = yyvsp[-1].solidtype; ;
    break;}
case 13:
#line 106 "geometry.yy"
{ 
		   OneSurfacePrimitive * surf = new Sphere (Point<3> (yyvsp[-7].val, yyvsp[-5].val, yyvsp[-3].val), yyvsp[-1].val); 
		   parsegeom -> AddSurface (surf);
		   surf->SetSurfaceId (0, parsegeom->GetNSurf()-1);
                   yyval.solidtype = new Solid (surf);
                 ;
    break;}
case 14:
#line 116 "geometry.yy"
{
		   OneSurfacePrimitive * surf = new Cylinder (Point<3> (yyvsp[-13].val, yyvsp[-11].val, yyvsp[-9].val),
	                                       Point<3> (yyvsp[-7].val, yyvsp[-5].val, yyvsp[-3].val), yyvsp[-1].val);
		   parsegeom->AddSurface (surf);
		   surf->SetSurfaceId (0, parsegeom->GetNSurf()-1);
                   yyval.solidtype = new Solid (surf);
                 ;
    break;}
case 15:
#line 128 "geometry.yy"
{
		   OneSurfacePrimitive * surf = new Cone (Point<3> (yyvsp[-15].val, yyvsp[-13].val, yyvsp[-11].val),
	                                     	 Point<3> (yyvsp[-7].val, yyvsp[-5].val, yyvsp[-3].val), yyvsp[-9].val, yyvsp[-1].val);
		   parsegeom->AddSurface (surf);
		   surf->SetSurfaceId (0, parsegeom->GetNSurf()-1);
                   yyval.solidtype = new Solid (surf);
                 ;
    break;}
case 16:
#line 137 "geometry.yy"
{
		   OneSurfacePrimitive * surf = new Plane ( Point<3> (yyvsp[-11].val, yyvsp[-9].val, yyvsp[-7].val),
	                                        Vec<3> (yyvsp[-5].val, yyvsp[-3].val, yyvsp[-1].val) );
		   parsegeom->AddSurface (surf);
		   surf->SetSurfaceId (0, parsegeom->GetNSurf()-1);
                   yyval.solidtype = new Solid (surf);
                 ;
    break;}
case 17:
#line 146 "geometry.yy"
{
		  Primitive * nprim = new OrthoBrick (Point<3> (yyvsp[-11].val, yyvsp[-9].val, yyvsp[-7].val),
		                                      Point<3> (yyvsp[-5].val, yyvsp[-3].val, yyvsp[-1].val));
                  for (int j = 0; j < nprim->GetNSurfaces(); j++)
		    {
		      parsegeom->AddSurface (&nprim->GetSurface(j));
		      nprim->SetSurfaceId (j, parsegeom->GetNSurf()-1);
		      yyval.solidtype = new Solid (nprim);
		    }
		;
    break;}
case 18:
#line 159 "geometry.yy"
{
		  polyhedron = new Polyhedra ();
		;
    break;}
case 19:
#line 164 "geometry.yy"
{
		  int j;
                  for (j = 0; j < polyhedron->GetNSurfaces(); j++)
		    {
		      parsegeom->AddSurface (&polyhedron->GetSurface(j));
		      polyhedron->SetSurfaceId (j, parsegeom->GetNSurf()-1);
		      yyval.solidtype = new Solid (polyhedron);
		    }	
		;
    break;}
case 20:
#line 198 "geometry.yy"
{
                  Solid * nsol = yyvsp[-1].solidtype -> Copy(*parsegeom);
                  Vec<3> v(yyvsp[-7].val, yyvsp[-5].val, yyvsp[-3].val);
                  Transformation<3> trans(v);
		  nsol -> Transform (trans);
                  yyval.solidtype = nsol;
		;
    break;}
case 21:
#line 207 "geometry.yy"
{
		  int i;
                  Solid * hsol = yyvsp[-1].solidtype;
	          for (i = 1; i <= yyvsp[-3].val; i++)
                    {
                      Solid * nsol = yyvsp[-1].solidtype -> Copy(*parsegeom);
                      Vec<3> v(yyvsp[-9].val, yyvsp[-7].val, yyvsp[-5].val);
		      v *= i;
                      Transformation<3> trans(v);
		      nsol -> Transform (trans);
                      hsol = new Solid (Solid::UNION, hsol, nsol); 
                    }
		  yyval.solidtype = hsol;
		;
    break;}
case 22:
#line 223 "geometry.yy"
{
                  Solid * nsol = yyvsp[-1].solidtype -> Copy(*parsegeom);
                  Point<3> c(yyvsp[-13].val, yyvsp[-11].val, yyvsp[-9].val);
                  Transformation<3> rot(c, yyvsp[-7].val, yyvsp[-5].val, yyvsp[-3].val);
		  nsol -> Transform (rot);
                  yyval.solidtype = nsol;
		;
    break;}
case 23:
#line 234 "geometry.yy"
{
		  int i;
                  Solid * hsol = yyvsp[-1].solidtype;                      

		  Point<3> c(yyvsp[-15].val, yyvsp[-13].val, yyvsp[-11].val);
                  Transformation<3> trans(c, yyvsp[-9].val, yyvsp[-7].val, yyvsp[-5].val);
		  Transformation<3> multi(Vec<3>(0,0,0));
		  Transformation<3> ht;

	          for (i = 1; i <= yyvsp[-3].val; i++)
                    {
                      Solid * nsol = yyvsp[-1].solidtype -> Copy(*parsegeom);
		      nsol -> Transform (multi);
                      hsol = new Solid (Solid::UNION, hsol, nsol); 

		      ht=multi;
                      multi.Combine (trans, ht);
                    }
		  yyval.solidtype = hsol;
		;
    break;}
case 28:
#line 295 "geometry.yy"
{
		polyhedron->AddPoint (Point<3> (yyvsp[-4].val, yyvsp[-2].val, yyvsp[0].val));
 		cout << " " << yyvsp[-4].val << " " << yyvsp[-2].val << " " << yyvsp[0].val << endl;
	;
    break;}
case 29:
#line 302 "geometry.yy"
{ 
		polyhedron->AddFace (int(yyvsp[-4].val)-1, int(yyvsp[-2].val)-1, int(yyvsp[0].val)-1);
		cout << yyvsp[-4].val << " " << yyvsp[-2].val << " " << yyvsp[0].val << endl; 
	;
    break;}
case 30:
#line 307 "geometry.yy"
{ 	
		cout << "face, 1 = " << yyvsp[-6].val << " " << yyvsp[-4].val << " "  << yyvsp[-2].val << " " << yyvsp[0].val << endl; 
		polyhedron->AddFace (int(yyvsp[-6].val)-1, int(yyvsp[-4].val)-1, int(yyvsp[-2].val)-1);
		polyhedron->AddFace (int(yyvsp[-6].val)-1, int(yyvsp[-2].val)-1, int(yyvsp[0].val)-1);
		cout << yyvsp[-6].val << yyvsp[-4].val << yyvsp[-2].val << yyvsp[0].val << endl; 
	;
    break;}
case 33:
#line 321 "geometry.yy"
{
//		revolution->AddPoint (Point<2> ($1, $3));
 		cout << " " << yyvsp[-2].val << " " << yyvsp[0].val << endl;
	;
    break;}
case 36:
#line 338 "geometry.yy"
{
	        middlecurve->AddSegment (splinep1, Point<3> (yyvsp[-10].val, yyvsp[-8].val, yyvsp[-6].val), Point<3> (yyvsp[-4].val, yyvsp[-2].val, yyvsp[0].val));
		splinep1(0) = yyvsp[-4].val; splinep1(1) = yyvsp[-2].val; splinep1(2) = yyvsp[0].val;
		;
    break;}
case 37:
#line 347 "geometry.yy"
{
                bspline = new BSplineCurve2d;
                bspline -> AddPoint (Point<2> (yyvsp[-2].val, yyvsp[0].val));
		cout << "first point" << endl;
                ;
    break;}
case 39:
#line 355 "geometry.yy"
{ ;
    break;}
case 40:
#line 357 "geometry.yy"
{
               bspline -> AddPoint (Point<2> (yyvsp[-2].val, yyvsp[0].val));
		cout << "Add Point: " << yyvsp[-2].val << "-" << yyvsp[0].val << endl;
               ;
    break;}
case 44:
#line 379 "geometry.yy"
{ cout << "singular edge:" << yyvsp[-2].val << " between "
		 << yyvsp[-1].chptr << " and " << yyvsp[0].chptr << endl; 
	  parsegeom->singedges.Append 
	    (new SingularEdge (yyvsp[-2].val, parsegeom->GetSolid(yyvsp[-1].chptr), 
				parsegeom->GetSolid(yyvsp[0].chptr)));
	;
    break;}
case 45:
#line 387 "geometry.yy"
{ cout << "singular point:" << yyvsp[-3].val << " between "
		 << yyvsp[-2].chptr << ", " << yyvsp[-1].chptr << " and " << yyvsp[0].chptr << endl; 
	  parsegeom->singpoints.Append 
	    (new SingularPoint (yyvsp[-3].val, parsegeom->GetSolid(yyvsp[-2].chptr), 
				parsegeom->GetSolid(yyvsp[-1].chptr),
				parsegeom->GetSolid(yyvsp[0].chptr)));
	;
    break;}
case 46:
#line 396 "geometry.yy"
{ 	
	  ARRAY<int> si1, si2;
	  parsegeom->GetSolid(yyvsp[-2].chptr)->GetSurfaceIndices(si1);
	  parsegeom->GetSolid(yyvsp[-1].chptr)->GetSurfaceIndices(si2);

	  parsegeom->AddIdentification (
		new CloseSurfaceIdentification (
			parsegeom->GetNIdentifications()+1,
			*parsegeom, 
			parsegeom->GetSurface (si1[0]),
			parsegeom->GetSurface (si2[0]),
			parseflags));
	;
    break;}
case 47:
#line 411 "geometry.yy"
{ 	
	  ARRAY<int> si1, si2, si3;
	  parsegeom->GetSolid(yyvsp[-2].chptr)->GetSurfaceIndices(si1);
	  parsegeom->GetSolid(yyvsp[-1].chptr)->GetSurfaceIndices(si2);
	  parsegeom->GetSolid(yyvsp[0].chptr)->GetSurfaceIndices(si3);

	  parsegeom->AddIdentification (
		new CloseEdgesIdentification (
			parsegeom->GetNIdentifications()+1,
			*parsegeom, 
			parsegeom->GetSurface (si1.Get(1)),
			parsegeom->GetSurface (si2.Get(1)),
			parsegeom->GetSurface (si3.Get(1))));
	;
    break;}
case 48:
#line 427 "geometry.yy"
{ 
	  ARRAY<int> si1, si2;
	  parsegeom->GetSolid(yyvsp[-1].chptr)->GetSurfaceIndices(si1);
	  parsegeom->GetSolid(yyvsp[0].chptr)->GetSurfaceIndices(si2);

	  parsegeom->AddIdentification (
		new PeriodicIdentification (
			parsegeom->GetNIdentifications()+1,
			*parsegeom,
			parsegeom->GetSurface (si1.Get(1)),
			parsegeom->GetSurface (si2.Get(1))));
	;
    break;}
case 49:
#line 441 "geometry.yy"
{
	  int tlonr = 
            parsegeom->SetTopLevelObject ((Solid*)parsegeom->GetSolid(yyvsp[-1].chptr));
	  TopLevelObject * tlo = parsegeom->GetTopLevelObject (tlonr);
	  if (parseflags.NumListFlagDefined ("col"))
	    {
	      const ARRAY<double> & col = parseflags.GetNumListFlag ("col");
	      tlo->SetRGB (col[0], col[1], col[2]);
	    }
	  if (parseflags.GetDefineFlag ("transparent"))
	    tlo->SetTransparent (1);
	;
    break;}
case 50:
#line 455 "geometry.yy"
{
	  ARRAY<int> si;
	  parsegeom->GetSolid(yyvsp[-1].chptr)->GetSurfaceIndices(si);
	  int tlonr = 
	    parsegeom->SetTopLevelObject ((Solid*)parsegeom->GetSolid(yyvsp[-2].chptr),
					  (Surface*)parsegeom->GetSurface(si.Get(1)));
	  TopLevelObject * tlo = parsegeom->GetTopLevelObject (tlonr);
	  if (parseflags.NumListFlagDefined ("col"))
	    {
	      const ARRAY<double> & col = parseflags.GetNumListFlag ("col");
	      tlo->SetRGB (col.Get(1), col.Get(2), col.Get(3));
	    }
	  if (parseflags.GetDefineFlag ("transparent"))
	    tlo->SetTransparent (1);
	;
    break;}
case 51:
#line 473 "geometry.yy"
{
	  parsegeom->SetBoundingBox (Box<3> (Point<3> (yyvsp[-11].val, yyvsp[-9].val, yyvsp[-7].val), 
                                             Point<3> (yyvsp[-5].val, yyvsp[-3].val, yyvsp[-1].val)));
	;
    break;}
case 52:
#line 479 "geometry.yy"
{
	  parsegeom->AddUserPoint (Point<3> (yyvsp[-5].val, yyvsp[-3].val, yyvsp[-1].val));
	;
    break;}
case 53:
#line 484 "geometry.yy"
{
  	  CSGeometry::BCModification bcm;
	  ARRAY<int> si;

	  parsegeom->GetSolid(yyvsp[-2].chptr)->GetSurfaceIndices(si);
	
          bcm.tlonr = -1;
	  int i;	
	  for (i = 0; i < parsegeom->GetNTopLevelObjects(); i++)
	    if (strcmp (parsegeom->GetTopLevelObject(i)->GetSolid()->Name(), yyvsp[-1].chptr) == 0)
	      {
	        bcm.tlonr = i;
	        break;
              }

	  bcm.bcnr = int(yyvsp[0].val);
	  for (i = 0; i < si.Size(); i++)
            {
	      bcm.si = si[i];
              parsegeom->bcmodifications.Append (bcm);
            }
	;
    break;}
case 54:
#line 512 "geometry.yy"
{ parseflags.DeleteFlags (); ;
    break;}
case 58:
#line 523 "geometry.yy"
{ parseflags.SetFlag (yyvsp[0].chptr); ;
    break;}
case 59:
#line 525 "geometry.yy"
{ parseflags.SetFlag (yyvsp[-2].chptr, yyvsp[0].chptr); ;
    break;}
case 60:
#line 527 "geometry.yy"
{ parseflags.SetFlag (yyvsp[-2].chptr, yyvsp[0].val); ;
    break;}
case 61:
#line 529 "geometry.yy"
{ parseflags.SetFlag (yyvsp[-2].chptr, doublearray); ;
    break;}
case 62:
#line 531 "geometry.yy"
{ parseflags.SetFlag (yyvsp[-2].chptr, stringarray); ;
    break;}
case 63:
#line 536 "geometry.yy"
{ doublearray.SetSize (0); ;
    break;}
case 65:
#line 541 "geometry.yy"
{ doublearray.Append (yyvsp[0].val); ;
    break;}
case 66:
#line 542 "geometry.yy"
{ doublearray.Append (yyvsp[0].val); ;
    break;}
case 67:
#line 547 "geometry.yy"
{
	  int i;
	  for (i = 0; i < stringarray.Size(); i++)
	     delete stringarray[i];
	  stringarray.SetSize (0);
	;
    break;}
case 69:
#line 558 "geometry.yy"
{
			stringarray.Append (new char[strlen(yyvsp[0].chptr)+1]);
			strcpy (stringarray.Last(), yyvsp[0].chptr);
		;
    break;}
case 70:
#line 564 "geometry.yy"
{
			stringarray.Append (new char[strlen(yyvsp[0].chptr)+1]);
			strcpy (stringarray.Last(), yyvsp[0].chptr);
		;
    break;}
case 71:
#line 575 "geometry.yy"
{ yyval.chptr = yyvsp[0].chptr; ;
    break;}
case 72:
#line 576 "geometry.yy"
{ yyval.chptr = yyvsp[0].chptr; ;
    break;}
}

#line 709 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 577 "geometry.yy"



int yyerror (char * s)
{	
  cerr << s << " in line " << linenum << endl;
  return 0;
}

