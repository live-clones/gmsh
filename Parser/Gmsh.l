%{
// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModelIO_GEO.h"
#include "Geo.h" // for Shape, NEWPOINT(), etc.
#include "Parser.h"
#include "Gmsh.tab.hpp"

void   parsestring(char endchar);
char  *strsave(char *ptr);
void   skipcomments(void);
void   skipline(void);

#define YY_INPUT(buf,result,max_size)					\
  {									\
    int c = '*', n;							\
    for(n = 0; n < (int) max_size && (c = fgetc(yyin)) != EOF &&        \
           c != '\n' && c != '\r'; ++n)                                 \
      buf[n] = (char) c;                                                \
    if(c == '\n' || c == '\r') {                                        \
      buf[n++] = (char) c;                                              \
      if(c == '\n') yylineno++;                                         \
    }                                                                   \
    if(c == EOF && ferror(yyin))                                        \
      Msg::Error("Input in flex scanner failed");			\
    result = n;                                                         \
  }

#if defined(WIN32)
#define isatty(arg) -1
#define YY_NO_UNISTD_H
#endif

// undefine register for C++11 compatibility of files generated with old
// versions of flex/bison
#define register

%}

alpha	[a-zA-Z\_]
dieze	[\#]
special	[\.]
digit	[0-9]
exp	[Ee][-+]?{digit}+
string	{alpha}({alpha}|{digit})*

%%

[\ \t\n\r\f]		/* none */;
";"                     return tEND;
"/*"			skipcomments();
"//"			skipline();
"\""			{ parsestring('\"'); return tBIGSTR; }
"\'"			{ parsestring('\''); return tBIGSTR; }
"newreg"		{ gmsh_yylval.d = NEWREG(); return tDOUBLE; }
"newp"  		{ gmsh_yylval.d = NEWPOINT(); return tDOUBLE; }
"newl"  		{ gmsh_yylval.d = NEWLINE(); return tDOUBLE; }
"newc"  		{ gmsh_yylval.d = NEWLINE(); return tDOUBLE; }
"newll"  		{ gmsh_yylval.d = NEWLINELOOP(); return tDOUBLE; }
"news"  		{ gmsh_yylval.d = NEWSURFACE(); return tDOUBLE; }
"newsl"  		{ gmsh_yylval.d = NEWSURFACELOOP(); return tDOUBLE; }
"newv"  		{ gmsh_yylval.d = NEWVOLUME(); return tDOUBLE; }
"newf"  		{ gmsh_yylval.d = NEWFIELD(); return tDOUBLE; }
"="                     return tAFFECT;
"+="                    return tAFFECTPLUS;
"-="                    return tAFFECTMINUS;
"*="                    return tAFFECTTIMES;
"/="                    return tAFFECTDIVIDE;
":"                     return tDOTS;
"..."                   return tDOTS;
"::"                    return tSCOPE;
"||"                    return tOR;
"&&"                    return tAND;
"++"                    return tPLUSPLUS;
"--"                    return tMINUSMINUS;
"=="                    return tEQUAL;
"!="                    return tNOTEQUAL;
"<="                    return tLESSOREQUAL;
">="                    return tGREATEROREQUAL;
">>"                    return tGREATERGREATER;
"<<"                    return tLESSLESS;

Abort                   return tAbort;
Abs                     return tAbs;
AbsolutePath            return tAbsolutePath;
Acos                    return tAcos;
AdaptMesh               return tAdaptMesh;
Affine                  return tAffine;
Alias                   return tAlias;
AliasWithOptions        return tAliasWithOptions;
ArcCos                  return tAcos;
Append                  return tAppend;
ArcSin                  return tAsin;
ArcTan                  return tAtan;
ArcTan2                 return tAtan2;
Asin                    return tAsin;
Atan                    return tAtan;
Atan2                   return tAtan2;

BSpline			return tBSpline;
Betti                   return tBetti;
Bezier			return tBezier;
Box                     return tBox;
Block                   return tBox;
BooleanCoherence        return tBooleanFragments;
BooleanCommon           return tBooleanIntersection;
BooleanCut              return tBooleanDifference;
BooleanDifference       return tBooleanDifference;
BooleanFragments        return tBooleanFragments;
BooleanFuse             return tBooleanUnion;
BooleanIntersection     return tBooleanIntersection;
BooleanSection          return tBooleanSection;
BooleanUnion            return tBooleanUnion;
BoundingBox             return tBoundingBox;

Call                    return tCall;
Catenary                return tCatenary;
CatmullRom		return tSpline;
Ceil                    return tCeil;
CenterOfMass            return tCenterOfMass;
Chamfer                 return tChamfer;
Characteristic          return tCharacteristic;
Circle                  return tCircle;
ClassifySurfaces        return tClassifySurfaces;
CodeName                return tCodeName;
Coherence               return tCoherence;
Cohomology              return tCohomology;
Color                   return tColor;
ColorTable              return tColorTable;
Combine                 return tCombine;
Compound                return tCompound;
Cone                    return tCone;
Coordinates             return tCoordinates;
CopyOptions             return tCopyOptions;
Cos                     return tCos;
Cosh                    return tCosh;
Cpu                     return tCpu;
CreateGeometry          return tCreateGeometry;
CreateTopology          return tCreateTopology;
CurrentDir              return tCurrentDirectory;
CurrentDirectory        return tCurrentDirectory;
CurrentFileName         return tCurrentFileName;
Curve                   return tCurve;
Cylinder                return tCylinder;

DefineConstant          return tDefineConstant;
DefineNumber            return tDefineNumber;
DefineString            return tDefineString;
Degenerated             return tDegenerated;
Delete                  return tDelete;
Dilate                  return tDilate;
DimNameSpace            return tDimNameSpace;
DirName                 return tDirName;
Disk                    return tDisk;
Draw                    return tDraw;

Ellipse                 return tEllipse;
Ellipsis                return tEllipse;
Ellipsoid               return tEllipsoid;
Elliptic		return tElliptic;
Else                    return tElse;
ElseIf                  return tElseIf;
EndFor                  return tEndFor;
EndIf                   return tEndIf;
Error                   return tError;
Euclidian               return tEuclidian;
Exists                  return tExists;
Exit                    return tExit;
Exp                     return tExp;
Extrude                 return tExtrude;

Fabs                    return tFabs;
Field                   return tField;
FileExists              return tFileExists;
Fillet                  return tFillet;
Find                    return tFind;
FixRelativePath         return tFixRelativePath;
Floor                   return tFloor;
Fmod                    return tFmod;
For                     return tFor;
Function                return tMacro;

GMSH_MAJOR_VERSION      return tGMSH_MAJOR_VERSION;
GMSH_MINOR_VERSION      return tGMSH_MINOR_VERSION;
GMSH_PATCH_VERSION      return tGMSH_PATCH_VERSION;
GeoEntity               return tGeoEntity;
GetEnv                  return tGetEnv;
GetForced               return tGetForced;
GetForcedStr            return tGetForcedStr;
GetNumber               return tGetNumber;
GetString               return tGetString;
GetStringValue          return tGetStringValue;
GetValue                return tGetValue;
GmshExecutableName      return tGmshExecutableName;

Hide                    return tHide;
Hole                    return tHole;
Homology                return tHomology;
Hypot                   return tHypot;

INTERPOLATION_SCHEME    return tInterpolationScheme;
If                      return tIf;
In                      return tIn;
Intersect               return tIntersect;

Knots			return tNurbsKnots;

Layers                  return tLayers;
Length                  return tLength;
Levelset                return tLevelset;
LinSpace                return tLinSpace;
Line                    return tCurve;
List                    return tList;
ListFromFile            return tListFromFile;
Log                     return tLog;
Log10                   return tLog10;
LogSpace                return tLogSpace;
LowerCase               return tLowerCase;
LowerCaseIn             return tLowerCaseIn;

MPI_Rank                return tMPI_Rank;
MPI_Size                return tMPI_Size;
Macro                   return tMacro;
Mass                    return tMass;
MatrixOfInertia         return tMatrixOfInertia;
Max                     return tMax;
Memory                  return tMemory;
MeshAlgorithm           return tMeshAlgorithm;
MeshSize                return tMeshSize;
MeshSizeFromBoundary    return tMeshSizeFromBoundary;
Min                     return tMin;
Modulo                  return tModulo;

N2S                     return tNameToString;
NameStruct              return tNameStruct;
NameToString            return tNameToString;
NewModel                return tNewModel;
Nurbs			return tNurbs;

OnelabAction            return tOnelabAction;
OnelabRun               return tOnelabRun;
Order			return tNurbsOrder;

Parametric		return tParametric;
Parent                  return tParent;
Periodic                return tPeriodic;
Physical                return tPhysical;
Pi                      return tPi;
Plane                   return tPlane;
Plugin                  return tPlugin;
Point                   return tPoint;
PolarSphere             return tPolarSphere;
Printf                  return tPrintf;

Quadric                 return tQuadric;
Quad[tT]ri[aA]dd[vV]erts        return tQuadTriAddVerts;
Quad[tT]ri[nN]o[nN]ew[vV]erts   return tQuadTriNoNewVerts;

Rand                    return tRand;
Recomb[lL]aterals       return tRecombLaterals;
Recombine               return tRecombine;
Rectangle               return tRectangle;
Recursive               return tRecursive;
RecombineMesh           return tRecombineMesh;
RefineMesh              return tRefineMesh;
RelocateMesh            return tRelocateMesh;
ReorientMesh            return tReorientMesh;
RenumberMeshNodes       return tRenumberMeshNodes;
RenumberMeshElements    return tRenumberMeshElements;
Return                  return tReturn;
ReverseMesh             return tReverseMesh;
Reverse                 return tReverseMesh;
Rotate                  return tRotate;
Round                   return tRound;
Ruled                   return tRuled;

S2N                     return tStringToName;
ScaleLastLayer          return tScaleLast;
SetChanged              return tSetChanged;
SetFactory              return tSetFactory;
SetTag                  return tSetTag;
SetMaxTag               return tSetMaxTag;
SetNumber               return tSetNumber;
SetPartition            return tSetPartition;
SetString               return tSetString;
Sewing                  return tSewing;
ShapeFromFile           return tShapeFromFile;
Show                    return tShow;
Sin                     return tSin;
Sinh                    return tSinh;
Slide                   return tSlide;
Smoother                return tSmoother;
Sphere                  return tSphere;
Spline                  return tSpline;
Split                   return tSplit;
Sprintf                 return tSprintf;
Sqrt                    return tSqrt;
Str                     return tStr;
StrCat                  return tStrCat;
StrChoice               return tStrChoice;
StrCmp                  return tStrCmp;
StrFind                 return tStrFind;
StrLen                  return tStrLen;
StrPrefix               return tStrPrefix;
StrRelative             return tStrRelative;
StrReplace              return tStrReplace;
StrSub                  return tStrSub;
StringToName            return tStringToName;
Struct                  return tDefineStruct;
Surface                 return tSurface;
Symmetry                return tSymmetry;
SyncModel               return tSyncModel;

T2                      return tText2D;
T3                      return tText3D;
TIME                    return tTime;
Tan                     return tTan;
Tanh                    return tTanh;
TestLevel               return tTestLevel;
TextAttributes          return tTextAttributes;
ThickSolid              return tThickSolid;
ThruSections            return tThruSections;
Today                   return tToday;
Torus                   return tTorus;
TotalMemory             return tTotalMemory;
Transf[qQ]uad[tT]ri     return tTransfQuadTri;
Transfinite             return tTransfinite;
Translate               return tTranslate;

UndefineConstant        return tUndefineConstant;
Unique                  return tUnique;
UnsplitWindow           return tUnsplitWindow;
UpperCase               return tUpperCase;
Using                   return tUsing;

Volume                  return tVolume;

Warning                 return tWarning;
Wedge                   return tWedge;
Wire                    return tWire;

{digit}+ |
{digit}+"."{digit}*({exp})? |
{digit}*"."{digit}+({exp})? |
{digit}+{exp}           { gmsh_yylval.d = atof((char *)yytext); return tDOUBLE; }

{string}		{ gmsh_yylval.c = strsave((char*)yytext); return tSTRING; }

.                       return yytext[0];

%%

#undef gmsh_yywrap

int gmsh_yywrap() { return 1; }

void skipcomments(void)
{
  int c;

  while (1) {
    while ((c = yyinput()) != '*') {
      // Test on YY_END_OF_BUFFER_CHAR (0), not on feof(yyin) because whole line
      // in buffer
      if(c == '\0') {
	Msg::Error("End of file in commented region");
        return;
      }
    }
    if((c = yyinput()) == '/')
      return;
    unput(c);
  }
}

void parsestring(char endchar)
{
  int c;
  char tmp[1024];

  // Note that we keep special characters (end-of-line \n, tabs \t, etc.) "as
  // is" in the output string: see yyinput() above
  int i = 0;
  while ((c = yyinput()) != endchar) {
    // Test on YY_END_OF_BUFFER_CHAR (0), not on feof(yyin) because whole line
    // in buffer
    if(c == '\0') {
      Msg::Error("End of file in string");
      break;
    }
    else if(i >= (int)sizeof(tmp) - 1) {
      Msg::Error("String too long");
      break;
    }
    else{
      tmp[i++] = (char)c;
    }
  }
  tmp[i] = '\0';
  gmsh_yylval.c = strsave(tmp);
}

char *strsave(char *ptr)
{
  return((char*)strcpy((char*)malloc(strlen(ptr) + 1), ptr));
}

void skipline()
{
  int c;
  while ((c = yyinput()) != '\n' && c != '\0') {}
  // TODO: would be clever to skip the current buffer because whole line already
  // in it
}

static bool is_alpha(const int c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

void skip(const char *skip, const char *until)
{
  int i, nb_skip = 0;
  int l_skip, l_until, l_max, l;
  char chars[256];
  int c_next, c_next_skip, c_next_until, c_previous = 0;

  l_skip = skip ? strlen(skip) : 0;
  l_until = strlen(until);

  l_max = std::max(l_skip, l_until);
  if(l_max >= (int)sizeof(chars)) {
    Msg::Error("Search pattern too long in skip");
    return;
  }

  while(1) {
    while(1) {
      chars[0] = yyinput();
      // TOFIX: do another test
      if(feof(yyin)) {
	Msg::Error("Unexpected end of file");
	return;
      }
      if(chars[0] == '/') {
        c_next = yyinput();
        if     (c_next ==  '*') skipcomments();
        else if(c_next ==  '/') skipline();
        else unput(c_next);
      }
      if(chars[0] == '"') {
        parsestring('"');
      }
      if(chars[0] == '\'') {
        parsestring('\'');
      }
      if(!c_previous || !is_alpha(c_previous)) {
        if(chars[0] == until[0]) break;
        if(skip && chars[0] == skip[0]) break;
      }
      c_previous = chars[0];
    }

    l = l_max;

    for(i = 1; i < l; i++) {
      chars[i] = yyinput();
      if(feof(yyin)) {
	l = i;
	break;
      }
    }

    c_next = yyinput(); unput(c_next);
    c_next_skip = (l_skip < l) ? chars[l_skip] : c_next;
    c_next_until = (l_until < l) ? chars[l_until] : c_next;

    if(!strncmp(chars, until, l_until) && !is_alpha(c_next_until)) {
      if(!nb_skip) {
	return;
      }
      else{
	nb_skip--;
      }
    }
    else if(skip && !strncmp(chars, skip, l_skip) && !is_alpha(c_next_skip)) {
      nb_skip++;
      // Attention: unput(.) should be applied a number of times equal to
      // l-l_skip (always >0 for skip="For" and until="EndFor", or skip="If" and
      // until="EndIf"); in particular, because "If" is followed by a minimum of
      // 3 chars (e.g., '(1)'), with a total lenght thus exactly equal to the
      // one of "EndIf", one avoid an error when looking then for
      // "EndIf". (Patrick)
    }
    else{
      for(i = 1; i < l - 1; i++) {
	unput(chars[l - i]);
      }
    }

  }
}

void skipTest(const char *skip, const char *until,
              const char *until2, int l_until2_sub, int *type_until2)
{
  int i, nb_skip = 0;
  int l_skip, l_until, l_until2, l_max, l;
  char chars[256];
  int c_next, c_next_skip, c_next_until, c_next_until2, c_previous = 0;
  int flag_EOL_EOF = 0;

  l_skip = skip ? strlen(skip) : 0;
  l_until = strlen(until);
  l_until2 = until2 ? strlen(until2) : 0;

  l_max = std::max(l_skip, l_until);
  l_max = std::max(l_max, l_until2);
  if(l_max >= (int)sizeof(chars)) {
    Msg::Error("Search pattern too long in skipTest");
    return;
  }

  while(1) {
    while(1) {
      chars[0] = yyinput();
      if(feof(yyin)) {
	Msg::Error("Unexpected end of file");
	return;
      }
      if(chars[0] == '/') {
        c_next = yyinput();
        if     (c_next ==  '*') skipcomments();
        else if(c_next ==  '/') skipline();
        else unput(c_next);
      }
      if(!c_previous || !is_alpha(c_previous)) {
        if(chars[0] == until[0]) break;
        if(skip && chars[0] == skip[0]) break;
        if(!nb_skip && until2 && chars[0] == until2[0]) break;
        // Useless to search for until2 if nb_skip!=0
      }
      c_previous = chars[0];
    }

    l = l_max;
    flag_EOL_EOF = 0;

    for(i = 1; i < l; i++) {
      chars[i] = yyinput();
      if(chars[i] == '\n') {
        unput(chars[i]); chars[i] = 0; l = i; flag_EOL_EOF = 1;
        break;
      }
      if(feof(yyin)) {
	l = i; flag_EOL_EOF = 1;
	break;
      }
    }

    if(!flag_EOL_EOF) {
      c_next = yyinput(); unput(c_next);
      c_next_skip = (l_skip < l) ? chars[l_skip] : c_next;
      c_next_until = (l_until < l) ? chars[l_until] : c_next;
      if(!nb_skip)
        c_next_until2 = (l_until2 < l) ? chars[l_until2] : c_next;
    }
    else{
      c_next = 0; c_next_skip = 0; c_next_until = 0; c_next_until2 = 0;
    }

    if(!nb_skip && !strncmp(chars, until2, l_until2) &&
       !is_alpha(c_next_until2)) {
      *type_until2 = 1; // Found word is full until2 (e.g., "ElseIf")
      for(int i = 1; i <= l; i++) { // Only correct if l == l_until2
        unput(chars[l - i]);
      } // New file position points "ElseIf", that will be then analysed by the parser
      return;
    }
    else if(!nb_skip && !strncmp(chars,until2,l_until2_sub) &&
            !is_alpha(chars[l_until2_sub])) {
      *type_until2 = 2; // Found word is subword from until2 (e.g., "Else")
      for(int i = 1; i <= l - l_until2_sub; i++) { // Only correct if l_until2_sub < l
        unput(chars[l - i]);
      }
      return;
    }
    else if(!strncmp(chars, until, l_until) && !is_alpha(c_next_until)) {
      for(int i = 1; i <= l - l_until; i++) {
        unput(chars[l - i]);
      }
      if(!nb_skip) {
	return;
      }
      else{
	nb_skip--;
      }
    }
    else if(skip && !strncmp(chars, skip, l_skip) && !is_alpha(c_next_skip)) {
      nb_skip++;
    }
    else{
      for(i = 1; i < l - 1; i++) {
	unput(chars[l - i]);
      }
    }

  }
}

void gmsh_yyflush() { YY_FLUSH_BUFFER; }
