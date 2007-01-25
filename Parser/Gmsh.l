%{
// $Id: Gmsh.l,v 1.83 2007-01-25 15:50:58 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "Gmsh.tab.hpp"

char yyname[256] = "";
int  yylineno = 1;
int  yyerrorstate = 0;

void   parsestring(char endchar);
char  *strsave(char *ptr);
void   skipcomments(void);
void   skipline(void);

#define YY_ALWAYS_INTERACTIVE 1

#define YY_INPUT(buf,result,max_size)					\
   if ( yy_current_buffer->yy_is_interactive )				\
     {									\
       int c = '*', n;							\
       for ( n = 0; n < max_size &&					\
	       (c = getc( yyin )) != EOF && c != '\n'; ++n )		\
	 buf[n] = (char) c;						\
       if ( c == '\n' ){						\
	 buf[n++] = (char) c;						\
	 yylineno++;							\
       }								\
       if ( c == EOF && ferror( yyin ) )				\
	 Msg(FATAL, "Input in flex scanner failed");			\
       result = n;							\
     }									\
   else if ( ((result = fread( buf, 1, max_size, yyin )) == 0)		\
	     && ferror( yyin ) )					\
     Msg(FATAL, "Input in flex scanner failed");

%}

alpha	[a-zA-Z\_]
dieze	[\#]
special	[\.]
digit	[0-9]
exp	[Ee][-+]?{digit}+
string	{alpha}({alpha}|{digit})*

%e       2000
%p       7000
%n       2000
%k       1500
%a       7000
%o       7000

%%

[\ \t\n\r\f]		/* none */;
";"                     return tEND;
"/*"			skipcomments();
"//"			skipline();
"\""			{parsestring('\"'); return tBIGSTR;}
"\'"			{parsestring('\''); return tBIGSTR;}
"newreg"		{yylval.d = NEWREG(); return tDOUBLE;}
"newp"  		{yylval.d = NEWPOINT(); return tDOUBLE;}
"newl"  		{yylval.d = NEWLINE(); return tDOUBLE;}
"newc"  		{yylval.d = NEWLINE(); return tDOUBLE;}
"newll"  		{yylval.d = NEWLINELOOP(); return tDOUBLE;}
"news"  		{yylval.d = NEWSURFACE(); return tDOUBLE;}
"newsl"  		{yylval.d = NEWSURFACELOOP(); return tDOUBLE;}
"newv"  		{yylval.d = NEWVOLUME(); return tDOUBLE;}
"="                     return tAFFECT;
"+="                    return tAFFECTPLUS;
"-="                    return tAFFECTMINUS;
"*="                    return tAFFECTTIMES;
"/="                    return tAFFECTDIVIDE;
":"                     return tDOTS;
"..."                   return tDOTS;
"||"                    return tOR;
"&&"                    return tAND;
"++"                    return tPLUSPLUS;
"--"                    return tMINUSMINUS;
"=="                    return tEQUAL;
"!="                    return tNOTEQUAL;
"<="                    return tLESSOREQUAL;
">="                    return tGREATEROREQUAL;

Acos                    return tAcos;
ArcCos                  return tAcos;
Alias                   return tAlias;
AliasWithOptions        return tAliasWithOptions;
Asin                    return tAsin;
ArcSin                  return tAsin;
Atan                    return tAtan;
ArcTan                  return tAtan;
Atan2                   return tAtan2;
ArcTan2                 return tAtan2;
Attractor		return tAttractor;

Bezier			return tBezier;
Bump                    return tBump;
BSpline			return tBSpline;
BoundingBox             return tBoundingBox;

Ceil                    return tCeil;
Combine                 return tCombine;
Cosh                    return tCosh;
Cos                     return tCos;
Characteristic          return tCharacteristic;
Circle                  return tCircle;
Coherence               return tCoherence;
Complex                 return tComplex;
Color                   return tColor;
ColorTable              return tColorTable;
CatmullRom		return tSpline;
Call                    return tCall;

Delete                  return tDelete;
Dilate                  return tDilate;
Duplicata               return tDuplicata;
Draw                    return tDraw;

Exp                     return tExp;
Ellipsis                return tEllipse;
Ellipse                 return tEllipse;
Extrude                 return tExtrude;
Elliptic		return tElliptic;
EndFor                  return tEndFor;
EndIf                   return tEndIf;
Exit                    return tExit;

Fabs                    return tFabs;
Floor                   return tFloor;
Fmod                    return tFmod;
For                     return tFor;
Function                return tFunction;

GetValue                return tGetValue;
GMSH_MAJOR_VERSION      return tGMSH_MAJOR_VERSION;
GMSH_MINOR_VERSION      return tGMSH_MINOR_VERSION;
GMSH_PATCH_VERSION      return tGMSH_PATCH_VERSION;

Hide                    return tHide;
Hypot                   return tHypot;

In                      return tIn;
If                      return tIf;

Knots			return tKnots;

Length                  return tLength;
Line                    return tLine;
Loop                    return tLoop;
Log                     return tLog;
Log10                   return tLog10;
Layers                  return tLayers;

Modulo                  return tModulo;
MPI_Rank                return tMPI_Rank;
MPI_Size                return tMPI_Size;

Nurbs			return tNurbs;

Order			return tOrder;

Physical                return tPhysical;
Pi                      return tPi;
Plane                   return tPlane;
Point                   return tPoint;
Power                   return tProgression;
Progression             return tProgression;
Parametric		return tParametric;
Printf                  return tPrintf;
Plugin                  return tPlugin;

Recombine               return tRecombine;
Rotate                  return tRotate;
Ruled                   return tRuled;
Rand                    return tRand;
Return                  return tReturn;

Sqrt                    return tSqrt;
Sin                     return tSin;
Sinh                    return tSinh;
Spline                  return tSpline;
Surface                 return tSurface;
Symmetry                return tSymmetry;
Sprintf                 return tSprintf;
StrCat                  return tStrCat;
StrPrefix               return tStrPrefix;
StrRelative             return tStrRelative;
Show                    return tShow;

Transfinite             return tTransfinite;
Translate               return tTranslate;
Tanh                    return tTanh;
Tan                     return tTan;
Today                   return tToday;

Using                   return tUsing;

Volume                  return tVolume;

T2                      return tText2D;
T3                      return tText3D;
INTERPOLATION_SCHEME    return tInterpolationScheme;
TIME                    return tTime;
GRAIN                   return tGrain;

{digit}+ |
{digit}+"."{digit}*({exp})? |
{digit}*"."{digit}+({exp})? |
{digit}+{exp}           {yylval.d = atof((char *)yytext); return tDOUBLE;}

{string}		{yylval.c = strsave((char*)yytext); return tSTRING;}

.                       return yytext[0];

%%

#undef yywrap

int yywrap() {return 1;}

void skipcomments(void){
  int c;

  while (1) {
    while ((c = yyinput()) != '*'){
      if(c == EOF){
        Msg(GERROR, "End of file in commented region");
        return;
      }
    }
    if ((c = yyinput()) == '/')
      return;
    unput(c);
  }
}

void parsestring(char endchar){
  int c;
  char tmp[1024];
  
  // Note that we keep special characters (end-of-line \n, tabs \t,
  // etc.) "as is" in the output string: see yyinput() above
  int i = 0;
  while ((c = yyinput()) != endchar) {
    if(c == EOF){
      Msg(GERROR, "End of file in string");
      break;
    }
    else if(i >= (int)sizeof(tmp)-1){
      Msg(GERROR, "String too long");
      break;
    }
    else{
      tmp[i++] = (char)c;
    }
  }
  tmp[i] = '\0';
  yylval.c = strsave(tmp);
}

char *strsave(char *ptr){
  return((char*)strcpy((char*)malloc(strlen(ptr)+1),ptr));
}

void skipline(void){
  int c;
  while ((c = yyinput()) != '\n'){
    if(c == EOF) return;
  }
}

void skip_until(char *skip, char *until){
  int i, nb_skip;
  int l, l_skip, l_until;
  char chars[256];

  nb_skip = 0;

  if(skip)
    l_skip = strlen(skip);
  else
    l_skip = 0;

  l_until = strlen(until);

  while(1){
    while (1){
      chars[0] = yyinput();
      if(chars[0] == (char)EOF){
        Msg(GERROR, "Unexpected end of file");
	return;
      }
      if(chars[0] == until[0]) break;
      if(skip && chars[0] == skip[0]) break;
    }

    l = MAX(l_skip,l_until);
    if(l >= (int)sizeof(chars)){
      Msg(GERROR, "Search pattern too long in skip_until");
      return;
    }
    for(i=1; i<l; i++){
      chars[i] = yyinput();
      if(chars[i] == (char)EOF){
	l = i;
	break;
      }
    }

    if(!strncmp(chars,until,l_until)){
      if(!nb_skip){
	return;
      }
      else{
	nb_skip--;
      }
    }
    else if(skip && !strncmp(chars,skip,l_skip)){
      nb_skip++;
    }
    else{
      for(i=1;i<l-1;i++){
	unput(chars[l-i]);
      }
    }

  }
}

void force_yyflush() { YY_FLUSH_BUFFER; }
