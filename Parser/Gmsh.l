%{
// $Id: Gmsh.l,v 1.54 2004-02-28 00:48:50 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "CAD.h"
#include "Gmsh.tab.hpp"

char   TmpString[1024];
int    yywhere = INFILE;
int    yylineno = 1;

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
	 YY_FATAL_ERROR( "input in flex scanner failed" );		\
       result = n;							\
     }									\
   else if ( ((result = fread( buf, 1, max_size, yyin )) == 0)		\
	     && ferror( yyin ) )					\
     YY_FATAL_ERROR( "input in flex scanner failed" );

%}

alpha	[a-zA-Z\_]
dieze	[\#]
special	[\.]
digit	[0-9]
exp	[Ee][-+]?{digit}+
string	{alpha}({alpha}|{digit})*
stepid  {dieze}({digit})+

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
"news"  		{yylval.d = NEWSURFACE(); return tDOUBLE;}
"newv"  		{yylval.d = NEWVOLUME(); return tDOUBLE;}
"="                     return tAFFECT;
"+="                    return tAFFECTPLUS;
"-="                    return tAFFECTMINUS;
"*="                    return tAFFECTTIMES;
"/="                    return tAFFECTDIVIDE;
":"                     return tDOTS;
"..."                   return tDOTS;
"/\\"                   return tCROSSPRODUCT;
"||"                    return tOR;
"&&"                    return tAND;
"++"                    return tPLUSPLUS;
"--"                    return tMINUSMINUS;
"=="                    return tEQUAL;
"!="                    return tNOTEQUAL;
"~="                    return tAPPROXEQUAL;
"<="                    return tLESSOREQUAL;
">="                    return tGREATEROREQUAL;

Acos                    return tAcos;
ArcCos                  return tAcos;
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
Bounds			return tBounds;

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

Hide                    return tHide;
Hypot                   return tHypot;

In                      return tIn;
If                      return tIf;
Intersect               return tIntersect;

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
Show                    return tShow;

Triangulation           return tTriangulation;
Transfinite             return tTransfinite;
Translate               return tTranslate;
Tanh                    return tTanh;
Tan                     return tTan;
Trimmed			return tTrimmed;

Using                   return tUsing;

Volume                  return tVolume;

With			return tWith;

SP                      return tScalarPoint;
VP                      return tVectorPoint;
TP                      return tTensorPoint;
SL                      return tScalarLine;
VL                      return tVectorLine;
TL                      return tTensorLine;
ST                      return tScalarTriangle;
VT                      return tVectorTriangle;
TT                      return tTensorTriangle;
SQ                      return tScalarQuadrangle;
VQ                      return tVectorQuadrangle;
TQ                      return tTensorQuadrangle;
SS                      return tScalarTetrahedron;
VS                      return tVectorTetrahedron;
TS                      return tTensorTetrahedron;
SH                      return tScalarHexahedron;
VH                      return tVectorHexahedron;
TH                      return tTensorHexahedron;
SI                      return tScalarPrism;
VI                      return tVectorPrism;
TI                      return tTensorPrism;
SY                      return tScalarPyramid;
VY                      return tVectorPyramid;
TY                      return tTensorPyramid;
T2                      return tText2D;
T3                      return tText3D;


CARTESIAN_POINT         	   return tCARTESIAN_POINT;
B_SPLINE_SURFACE_WITH_KNOTS        return tB_SPLINE_SURFACE_WITH_KNOTS;
B_SPLINE_CURVE_WITH_KNOTS          return tB_SPLINE_CURVE_WITH_KNOTS;
.UNSPECIFIED.                      return tUNSPECIFIED;
.CONTINUOUS.                       return tCONTINUOUS;
".F."                              return tFALSE;
".T."                              return tTRUE;
".U."				   return tU;
".V."				   return tV;
ORIENTED_EDGE                      return tORIENTED_EDGE;
EDGE_CURVE			   return tEDGE_CURVE;
EDGE_LOOP 			   return tEDGE_LOOP;
ELLIPSE                            return tELLIPSE;
VERTEX_POINT			   return tVERTEX_POINT;
FACE_OUTER_BOUND     		   return tFACE_OUTER_BOUND;
FACE_BOUND		     	   return tFACE_BOUND;
ADVANCED_FACE			   return tADVANCED_FACE;
LINE				   return tLine;
VECTOR				   return tVECTOR;
DIRECTION			   return tDIRECTION;
AXIS2_PLACEMENT_3D 		   return tAXIS2_PLACEMENT_3D;
PLANE				   return tPLANE;
HEADER                             return tHEADER;
DATA                               return tDATA;
FILE_SCHEMA                        return tFILE_SCHEMA;
FILE_NAME	                   return tFILE_NAME;
FILE_DESCRIPTION                   return tFILE_DESCRIPTION;
"ISO-10303-21"			   return tISO;
"END-ISO-10303-21"		   return tENDISO;
ENDSEC				   return tENDSEC;
CLOSED_SHELL			   return tCLOSED_SHELL;
ADVANCED_BREP_SHAPE_REPRESENTATION  return  tADVANCED_BREP_SHAPE_REPRESENTATION;
MANIFOLD_SOLID_BREP		   return tMANIFOLD_SOLID_BREP;
CYLINDRICAL_SURFACE		   return tCYLINDRICAL_SURFACE;
CONICAL_SURFACE			   return tCONICAL_SURFACE;
TOROIDAL_SURFACE		   return tTOROIDAL_SURFACE;
CIRCLE				   return tCIRCLE;
TRIMMED_CURVE			   return tTRIMMED_CURVE;
GEOMETRIC_SET			   return tGEOMETRIC_SET;
COMPOSITE_CURVE_SEGMENT		   return tCOMPOSITE_CURVE_SEGMENT;
COMPOSITE_CURVE			   return tCOMPOSITE_CURVE;
PRODUCT_DEFINITION                 return tPRODUCT_DEFINITION;
PRODUCT_DEFINITION_SHAPE           return tPRODUCT_DEFINITION_SHAPE;
SHAPE_DEFINITION_REPRESENTATION    return tSHAPE_DEFINITION_REPRESENTATION;

vertex       return tVertex;
facet        return tFacet;
normal       return tNormal;
outer        return tOuter;
loop         return tLoopSTL;
endloop      return tEndLoop;
endfacet     return tEndFacet;
endsolid     {skipline();return tEndSolid;}
solid        {skipline();return tSolid;}

{stepid}                {yylval.d = (double)atoi((char*)(yytext+1)); return tDOUBLE;}

{digit}+ |
{digit}+"."{digit}*({exp})? |
{digit}*"."{digit}+({exp})? |
{digit}+{exp}           {yylval.d = atof((char *)yytext); return tDOUBLE;}

{string}		{yylval.c = strsave((char*)yytext); return tSTRING;}

.                       return yytext[0];

%%

#undef yywrap

int yywrap() {return 1;}

void skipcomments(void) {
  int c;

  while (1) {
    while ((c=yyinput()) != '*'){
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
  int c, i;

  c = yyinput();
  i = 0;
  while (c != endchar) {
    TmpString[i++] = c;
    c = yyinput();
  }
  TmpString[i++] = '\0';
  yylval.c = strsave(TmpString);
}

char *strsave(char *ptr){
  return((char*)strcpy((char*)malloc(strlen(ptr)+1),ptr));
}

void skipline(void){
   while (yyinput() != '\n');
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

