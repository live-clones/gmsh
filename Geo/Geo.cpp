// $Id: Geo.cpp,v 1.40 2004-05-18 04:54:50 geuzaine Exp $
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Parser.h"
#include "Context.h"

extern Context_T CTX;

#define BUFFSIZE 128000

// Some old systems don't have snprintf... Just call sprintf instead.

#if defined(HAVE_NO_SNPRINTF)
int snprintf(char *str, size_t size, const char* fmt, ...){
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf(str, fmt, args);
  va_end(args);
  return ret;
}
#endif

double evaluate_scalarfunction(char *var, double val, char *funct)
{
  FILE *tempf;
  tempf = yyin;

  if(!(yyin = fopen(CTX.tmprc_filename, "w"))) {
    Msg(GERROR, "Unable to open temporary file '%s'", CTX.tmprc_filename);
    return 0.;
  }

  // pose "variable = function" and evaluate function
  fprintf(yyin, "%s = %.16g ;\n", var, val);
  fprintf(yyin, "ValeurTemporaire__ = %s ;\n", funct);
  fclose(yyin);
  yyin = fopen(CTX.tmprc_filename, "r");
  while(!feof(yyin)) {
    yyparse();
  }
  fclose(yyin);
  yyin = tempf;

  // retreive value
  Symbol TheSymbol, *TheSymbol_P;
  TheSymbol.Name = (char *)Malloc(100*sizeof(char));
  strcpy(TheSymbol.Name, "ValeurTemporaire__");
  if(!(TheSymbol_P = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
    Free(TheSymbol.Name);
    return 0.0;
  }
  Free(TheSymbol.Name);
  return *(double *)List_Pointer(TheSymbol_P->val, 0);
}

void add_infile(char *text, char *fich)
{
  FILE *file;

  if(!(yyin = fopen(CTX.tmprc_filename, "w"))) {
    Msg(GERROR, "Unable to open temporary file '%s'", CTX.tmprc_filename);
    return;
  }
  if(!(file = fopen(fich, "a"))) {
    Msg(GERROR, "Unable to open file '%s'", fich);
    return;
  }
  fprintf(yyin, "%s\n", text);
  Msg(STATUS1, "%s", text);
  fclose(yyin);
  yyin = fopen(CTX.tmprc_filename, "r");
  while(!feof(yyin)) {
    yyparse();
  }
  fclose(yyin);
  fprintf(file, "%s\n", text);
  fclose(file);
}

void delet(int p1, char *fich, char *what)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Delete {\n  %s{%d};\n}", what, p1);
  add_infile(text, fich);
}

void add_trsfsurf(int N, int *l, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  snprintf(text, BUFFSIZE, "Transfinite Surface {%d} = {", l[0]);
  for(i = 1; i < N; i++) {
    if(i == 1)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  snprintf(text2, BUFFSIZE, "};");
  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_ellipticsurf(int N, int *l, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  snprintf(text, BUFFSIZE, "Elliptic Surface {%d} = {", l[0]);
  for(i = 1; i < N; i++) {
    if(i == 1)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  snprintf(text2, BUFFSIZE, "};");
  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_charlength(int N, int *l, char *fich, char *lc)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  snprintf(text, BUFFSIZE, "Characteristic Length {");
  for(i = 0; i < N; i++) {
    if(i == 0)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  snprintf(text2, BUFFSIZE, "} = %s;", lc);
  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_recosurf(int N, int *l, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  snprintf(text, BUFFSIZE, "Recombine Surface {");
  for(i = 0; i < N; i++) {
    if(i == 0)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  snprintf(text2, BUFFSIZE, "};");
  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}


void add_trsfline(int N, int *l, char *fich, char *type, char *typearg, char *pts)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  snprintf(text, BUFFSIZE, "Transfinite Line {");
  for(i = 0; i < N; i++) {
    if(!i)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  if(strlen(typearg))
    snprintf(text2, BUFFSIZE, "} = %s Using %s %s;", pts, type, typearg);
  else
    snprintf(text2, BUFFSIZE, "} = %s;", pts);
  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}


void add_param(char *par, char *value, char *fich)
{
  char text[BUFFSIZE];
  snprintf(text, BUFFSIZE, "%s = %s;", par, value);
  add_infile(text, fich);
}

void add_point(char *fich, char *x, char *y, char *z, char *lc)
{
  char text[BUFFSIZE];
  int ip = NEWPOINT();
  snprintf(text, BUFFSIZE, "Point(%d) = {%s,%s,%s,%s};", ip, x, y, z, lc);
  add_infile(text, fich);
}

void add_attractor(char *fich, int ip, int typ, char *ax, char *ay, char *ad)
{
  char text[BUFFSIZE];
  if(typ == 0) {
    snprintf(text, BUFFSIZE, "Attractor Point {%d} = {%s,%s,%s} = ;", ip, ax, ay, ad);
  }
  else if(typ == 1) {
    snprintf(text, BUFFSIZE, "Attractor Line {%d} = {%s,%s,%s};", ip, ax, ay, ad);
  }
  else if(typ == 2) {
    snprintf(text, BUFFSIZE, "Attractor Surface {%d} = {%s,%s,%s};", ip, ax, ay, ad);
  }
  add_infile(text, fich);
}


void add_line(int p1, int p2, char *fich)
{
  char text[BUFFSIZE];
  int iseg;
  List_T *list = List_Create(2, 2, sizeof(int));
  List_Add(list, &p1);
  List_Add(list, &p2);
  if((recognize_seg(MSH_SEGM_LINE, list, &iseg))) {
    List_Delete(list);
    return;
  }
  List_Delete(list);

  snprintf(text, BUFFSIZE, "Line(%d) = {%d,%d};", NEWLINE(), p1, p2);
  add_infile(text, fich);
}

void add_circ(int p1, int p2, int p3, char *fich)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Circle(%d) = {%d,%d,%d};", NEWLINE(), p1, p2, p3);
  add_infile(text, fich);
}

void add_ell(int p1, int p2, int p3, int p4, char *fich)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Ellipse(%d) = {%d,%d,%d,%d};", NEWLINE(), p1, p2,
           p3, p4);
  add_infile(text, fich);
}

void add_spline(int N, int *p, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  snprintf(text, BUFFSIZE, "CatmullRom(%d) = {", NEWLINE());
  for(i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_bezier(int N, int *p, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  snprintf(text, BUFFSIZE, "Bezier(%d) = {", NEWLINE());
  for(i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}


void add_bspline(int N, int *p, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  snprintf(text, BUFFSIZE, "BSpline(%d) = {", NEWLINE());
  for(i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_multline(int N, int *p, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  int iseg;
  List_T *list = List_Create(N, 2, sizeof(int));
  for(i = 0; i < N; i++)
    List_Add(list, &p[i]);
  if((recognize_seg(MSH_SEGM_LINE, list, &iseg))) {
    List_Delete(list);
    return;
  }
  List_Delete(list);

  snprintf(text, BUFFSIZE, "Line(%d) = {", NEWLINE());
  for(i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_loop(List_T * list, char *fich, int *numloop)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i, seg;

  if((recognize_loop(list, numloop)))
    return;

  *numloop = NEWLINELOOP();
  snprintf(text, BUFFSIZE, "Line Loop(%d) = {", *numloop);
  for(i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &seg);
    if(i != List_Nbr(list) - 1)
      snprintf(text2, BUFFSIZE, "%d,", seg);
    else
      snprintf(text2, BUFFSIZE, "%d};", seg);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}


void add_surf(List_T * list, char *fich, int support, int typ)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i, seg;

  if(typ == 1) {
    snprintf(text, BUFFSIZE, "Ruled Surface(%d) = {", NEWSURFACE());
  }
  else if(typ == 2) {
    snprintf(text, BUFFSIZE, "Plane Surface(%d) = {", NEWSURFACE());
  }
  else {
    snprintf(text, BUFFSIZE, "Trimmed Surface(%d) = %d {", NEWSURFACE(),
             support);
  }
  for(i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &seg);
    if(i != List_Nbr(list) - 1)
      snprintf(text2, BUFFSIZE, "%d,", seg);
    else
      snprintf(text2, BUFFSIZE, "%d};", seg);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_vol(List_T * list, char *fich, int *numvol)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i, seg;

  if((recognize_surfloop(list, numvol)))
    return;

  *numvol = NEWSURFACELOOP();
  snprintf(text, BUFFSIZE, "Surface Loop(%d) = {", *numvol);
  for(i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &seg);
    if(i != List_Nbr(list) - 1)
      snprintf(text2, BUFFSIZE, "%d,", seg);
    else
      snprintf(text2, BUFFSIZE, "%d};", seg);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_multvol(List_T * list, char *fich)
{
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i, seg;

  snprintf(text, BUFFSIZE, "Volume(%d) = {", NEWVOLUME());
  for(i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &seg);
    if(i != List_Nbr(list) - 1)
      snprintf(text2, BUFFSIZE, "%d,", seg);
    else
      snprintf(text2, BUFFSIZE, "%d};", seg);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_trsfvol(int N, int *l, char *fich, char *vol)
{
  char text[BUFFSIZE], text2[BUFFSIZE];
  int i;

  snprintf(text, BUFFSIZE, "Transfinite Volume{%s} = {", vol);
  for(i = 0; i < N; i++) {
    if(i == 0)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  snprintf(text2, BUFFSIZE, "};");
  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}


void add_physical(List_T * list, char *fich, int type, int *num)
{
  char text[BUFFSIZE], text2[BUFFSIZE];
  int i, elementary_entity;

  *num = NEWPHYSICAL();
  switch (type) {
  case ENT_POINT:
    snprintf(text, BUFFSIZE, "Physical Point(%d) = {", *num);
    break;
  case ENT_LINE:
    snprintf(text, BUFFSIZE, "Physical Line(%d) = {", *num);
    break;
  case ENT_SURFACE:
    snprintf(text, BUFFSIZE, "Physical Surface(%d) = {", *num);
    break;
  case ENT_VOLUME:
    snprintf(text, BUFFSIZE, "Physical Volume(%d) = {", *num);
    break;
  }

  for(i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &elementary_entity);
    if(i != List_Nbr(list) - 1)
      snprintf(text2, BUFFSIZE, "%d,", elementary_entity);
    else
      snprintf(text2, BUFFSIZE, "%d};", elementary_entity);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void translate(int add, int s, char *fich, char *what, char *tx, char *ty, char *tz)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE,
             "Translate {%s,%s,%s} {\n  Duplicata { %s{%d}; }\n}", tx, ty, tz, what, s);
  else
    snprintf(text, BUFFSIZE, "Translate {%s,%s,%s} {\n  %s{%d};\n}", tx, ty, tz, what, s);
  add_infile(text, fich);
}

void rotate(int add, int s, char *fich, char *what, char *ax, char *ay, char *az,
	    char *px, char *py, char *pz, char *angle)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE,
             "Rotate { {%s,%s,%s},{%s,%s,%s},%s } {\n  Duplicata { %s{%d}; }\n}",
             ax, ay, az, px, py, pz, angle, what, s);
  else
    snprintf(text, BUFFSIZE,
             "Rotate { {%s,%s,%s},{%s,%s,%s},%s } {\n  %s{%d};\n}",
             ax, ay, az, px, py, pz, angle, what, s);
  add_infile(text, fich);
}

void dilate(int add, int s, char *fich, char *what, char *dx, char *dy, char *dz, char *df)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE,
             "Dilate { {%s,%s,%s},%s } {\n  Duplicata { %s{%d}; }\n}",
             dx, dy, dz, df, what, s);
  else
    snprintf(text, BUFFSIZE, "Dilate { {%s,%s,%s},%s } {\n  %s{%d};\n}",
             dx, dy, dz, df, what, s);
  add_infile(text, fich);
}

void symmetry(int add, int s, char *fich, char *what, char *sa, char *sb, char *sc, char *sd)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE,
             "Symmetry { %s,%s,%s,%s } {\n  Duplicata { %s{%d}; }\n}",
             sa, sb, sc, sd, what, s);
  else
    snprintf(text, BUFFSIZE, "Symmetry { %s,%s,%s,%s } {\n  %s{%d};\n}",
             sa, sb, sc, sd, what, s);
  add_infile(text, fich);
}

void extrude(int s, char *fich, char *what, char *tx, char *ty, char *tz)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Extrude %s {%d, {%s,%s,%s}};", what, s, tx, ty, tz);
  add_infile(text, fich);
}

void protude(int s, char *fich, char *what, char *ax, char *ay, char *az,
	     char *px, char *py, char *pz, char *angle)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Extrude %s {%d, {%s,%s,%s}, {%s,%s,%s}, %s};",
           what, s, ax, ay, az, px, py, pz, angle);
  add_infile(text, fich);
}
