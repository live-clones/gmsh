%{ /* $Id: Gmsh.l,v 1.23 2000-12-19 08:59:59 geuzaine Exp $ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Gmsh.h"
#include "Geo.h"
#include "CAD.h"
#include "Gmsh.tab.cpp.h"

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
stepid  {dieze}({digit})*

%e       2000
%p       7000
%n       2000
%k       1500
%a       7000
%o       7000

%%

[\ \t\n]		/* none */ ;
";"                     return tEND;
"/*"			skipcomments();
"//"			skipline();
"\""			{parsestring('\"'); return tBIGSTR;}
"\'"			{parsestring('\''); return tBIGSTR;}
"newreg"		{yylval.d = NEWREG(); return tDOUBLE;}
"newp"  		{yylval.d = NEWPOINT(); return tDOUBLE;}
"="                     return tAFFECT;
"+="                    return tAFFECTPLUS ;
"-="                    return tAFFECTMINUS ;
"*="                    return tAFFECTTIMES ;
"/="                    return tAFFECTDIVIDE ;
":"                     return tDOTS;
"..."                   return tDOTS;
"/\\"                   return tCROSSPRODUCT ;
"||"                    return tOR ;
"&&"                    return tAND ;
"++"                    return tPLUSPLUS ;
"--"                    return tMINUSMINUS ;
"=="                    return tEQUAL ;
"!="                    return tNOTEQUAL ;
"~="                    return tAPPROXEQUAL ;
"<="                    return tLESSOREQUAL ;
">="                    return tGREATEROREQUAL ;

Acos                    return tAcos ;
ArcCos                  return tAcos ;
Asin                    return tAsin;
ArcSin                  return tAsin;
Atan                    return tAtan ;
ArcTan                  return tAtan ;
Atan2                   return tAtan2 ;
ArcTan2                 return tAtan2 ;
Attractor		return tAttractor;

Bump                    return tBump;
BSpline			return tBSpline;
Bounds			return tBounds;

Ceil                    return tCeil ;
Cosh                    return tCosh ;
Cos                     return tCos ;
Characteristic          return tCharacteristic;
Circle                  return tCircle;
Coherence               return tCoherence;
Complex                 return tComplex;
Color                   return tColor;
CatmullRom		return tSpline;
Call                    return tCall;

Delete                  return tDelete;
Dilate                  return tDilate;
Duplicata               return tDuplicata;
Draw                    return tDraw;

Exp                     return tExp ;
Ellipsis                return tEllipsis;
Extrude                 return tExtrude;
Elliptic		return tElliptic;
ELLIPSE                 return tELLIPSE;
EndFor                  return tEndFor;
EndIf                   return tEndIf;
Exit                    return tExit;

Fabs                    return tFabs ;
Floor                   return tFloor ;
Fmod                    return tFmod ;
For                     return tFor;
Function                return tFunction;

Hypot                   return tHypot ;

In                      return tIn;
If                      return tIf;
Intersect               return tIntersect;

Knots			return tKnots;

Length                  return tLength;
Line                    return tLine;
Loop                    return tLoop;
Log                     return tLog ;
Log10                   return tLog10 ;
Layers                  return tLayers;

Modulo                  return tModulo ;
Meshes                  return tMesh;

Nurbs			return tNurbs;

Order			return tOrder;

Physical                return tPhysical;
Pi                      return tPi;
Plane                   return tPlane;
Point                   return tPoint;
Power                   return tProgression;
Progression             return tProgression;
Parametric		return tParametric;
Printf                  return tPrintf ;

Recombine               return tRecombine;
Rotate                  return tRotate;
Ruled                   return tRuled;
Rand                    return tRand;
Return                  return tReturn;

Sqrt                    return tSqrt ;
Sin                     return tSin ;
Sinh                    return tSinh ;
Spline                  return tSpline;
Surface                 return tSurface;
Symmetry                return tSymmetry;
Sprintf                 return tSprintf ;

Transfinite             return tTransfinite;
Translate               return tTranslate;
Tanh                    return tTanh ;
Tan                     return tTan;
Trimmed			return tTrimmed;

Using                   return tUsing;

View                    return tView;
Volume                  return tVolume;

With			return tWith;

SS                      return tScalarTetrahedron;
VS                      return tVectorTetrahedron;
TS                      return tTensorTetrahedron;
ST                      return tScalarTriangle;
VT                      return tVectorTriangle;
TT                      return tTensorTriangle;
SL                      return tScalarLine;
VL                      return tVectorLine;
TL                      return tTensorLine;
SP                      return tScalarPoint;
VP                      return tVectorPoint;
TP                      return tTensorPoint;


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
      if(c == EOF) {
        fprintf(stderr, "Error: End of File in Commented Region\n") ;
        exit(1);
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

void skipline(void)
{
   while (yyinput() != '\n') ;
}

void skip_until(char *until)
{
  int i;
  int l = strlen(until);
  char chars[256];
  while(1)
    {
      while (1)
	{
	  chars[0] = yyinput();
	  if(chars[0] == EOF) 
	    {
	      fprintf(stderr, "Error, Unexpected End Of File\n") ;
	      exit(1);
	    }
	  if(chars[0] == until[0])break;
	}
      
      //printf("%c",chars[0]); 
      for(i=1;i<l;i++)
	{
	  chars[i] = yyinput();
	  if(chars[i] == EOF) 
	    {
	      fprintf(stderr, "Error, Unexpected End Of File\n") ;
	      exit(1);
	    }
	}
      chars[l] = '\0';
      if(!strcmp(chars,until))
	{
	  return;
	}
      for(i=1;i<l-1;i++)
	{
	  unput(chars[l-i]);
	}      
    }
}

