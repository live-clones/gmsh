// $Id: GeoStringInterface.cpp,v 1.24 2008-06-19 15:58:41 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <string.h>
#include <sstream>
#include "Message.h"
#include "Numeric.h"
#include "MallocUtils.h"
#include "Geo.h"
#include "GeoStringInterface.h"
#include "Parser.h"
#include "OpenFile.h"
#include "Context.h"
#include "GModel.h"

extern Context_T CTX;

#define BUFFSIZE 128000

// Some old systems don't have snprintf... Just call sprintf instead.

#if defined(HAVE_NO_SNPRINTF)
int snprintf(char *str, size_t size, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf(str, fmt, args);
  va_end(args);
  return ret;
}
#endif

double evaluate_scalarfunction(const char *var, double val, const char *funct)
{
  FILE *tempf;
  tempf = gmsh_yyin;

  if(!(gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "w"))) {
    Msg::Error("Unable to open temporary file '%s'", CTX.tmp_filename_fullpath);
    return 0.;
  }

  // pose "variable = function" and evaluate function
  fprintf(gmsh_yyin, "%s = %.16g ;\n", var, val);
  fprintf(gmsh_yyin, "ValeurTemporaire__ = %s ;\n", funct);
  fclose(gmsh_yyin);
  gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "r");
  while(!feof(gmsh_yyin)) {
    gmsh_yyparse();
  }
  fclose(gmsh_yyin);
  gmsh_yyin = tempf;

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

void add_infile(const char *text, const char *fich, bool deleted_something)
{
  if(!(gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "w"))) {
    Msg::Error("Unable to open temporary file '%s'", CTX.tmp_filename_fullpath);
    return;
  }

  fprintf(gmsh_yyin, "%s\n", text);
  Msg::StatusBar(2, true, "%s", text);
  fclose(gmsh_yyin);
  gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "r");
  while(!feof(gmsh_yyin)) {
    gmsh_yyparse();
  }
  fclose(gmsh_yyin);

  if(deleted_something){
    // we need to start from scratch since the command just parsed
    // could have deleted some entities
    GModel::current()->destroy();
  }
  GModel::current()->importGEOInternals();
  CTX.mesh.changed = ENT_ALL;

  FILE *file;
  if(!(file = fopen(fich, "a"))) {
    Msg::Error("Unable to open file '%s'", fich);
    return;
  }
  
  if(!CTX.expert_mode) {
    char no_ext[256], ext[256], base[256];
    SplitFileName(fich, no_ext, ext, base);
    if(strlen(ext) && strcmp(ext, ".geo") && strcmp(ext, ".GEO")){
      char question[1024];
      sprintf(question, 
              "A scripting command is going to be appended to a non-`.geo' file.\n\n"
              "Are you sure you want to proceed?\n\n"
              "(You might want to create a new `.geo' file containing the command\n\n"
              "Merge \"%s\";\n\n"
              "and use that file instead. To disable this warning in the future, select\n"
              "`Enable expert mode' in the option dialog.)", fich);
      if(!Msg::GetBinaryAnswer(question, "Proceed", "Cancel", false)){
        fclose(file);
        return;
      }
    }
  }

  fprintf(file, "%s\n", text);
  fclose(file);
}

void coherence(const char *fich)
{
  add_infile("Coherence;", fich, true);
}

void strncat_list(char *text, List_T *list)
{
  char text2[BUFFSIZE];
  for(int i = 0; i < List_Nbr(list); i++){
    int num;
    List_Read(list, i, &num);
    if(!i)
      snprintf(text2, BUFFSIZE, "%d", num);
    else
      snprintf(text2, BUFFSIZE, ",%d", num);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
}

void delet(List_T *list, const char *fich, const char *what)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Delete {\n  %s{", what);
  strncat_list(text, list);
  strncat(text, "};\n}", BUFFSIZE-strlen(text));
  add_infile(text, fich, true);
}

void add_trsfsurf(int N, int *l, const char *fich, const char *dir)
{
  char text[BUFFSIZE], text2[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Transfinite Surface {%d} = {", l[0]);
  for(int i = 1; i < N; i++) {
    if(i == 1)
      snprintf(text2, BUFFSIZE, "%d", l[i]);
    else
      snprintf(text2, BUFFSIZE, ",%d", l[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  if (!strcmp(dir,"Left"))
    snprintf(text2, BUFFSIZE, "};");
  else
    snprintf(text2, BUFFSIZE, "} %s;",dir);

  strncat(text, text2, BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_charlength(List_T *list, const char *fich, const char *lc)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Characteristic Length {");
  strncat_list(text, list);
  strncat(text, "} = ", BUFFSIZE-strlen(text));
  strncat(text, lc, BUFFSIZE-strlen(text));
  strncat(text, ";", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_recosurf(List_T *list, const char *fich)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Recombine Surface {");
  strncat_list(text, list);
  strncat(text, "};", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_trsfline(int N, int *l, const char *fich, const char *type, 
                  const char *typearg, const char *pts)
{
  char text[BUFFSIZE], text2[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Transfinite Line {");
  for(int i = 0; i < N; i++) {
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

void add_param(const char *par, const char *value, const char *fich)
{
  char text[BUFFSIZE];
  snprintf(text, BUFFSIZE, "%s = %s;", par, value);
  add_infile(text, fich);
}

void add_point(const char *fich, const char *x, const char *y, const char *z, 
               const char *lc)
{
  char text[BUFFSIZE];
  int ip = NEWPOINT();
  snprintf(text, BUFFSIZE, "Point(%d) = {%s,%s,%s,%s};", ip, x, y, z, lc);
  add_infile(text, fich);
}

void add_field_option(int field_id, const char *option_name, const char *option_value, const char *fich){
        std::ostringstream sstream;
        sstream<<"Field["<<field_id<<"]."<<std::string(option_name)<<" = "<<std::string(option_value)<<";";
        add_infile(sstream.str().c_str(),fich);
}
void add_field(int field_id, const char *type_name, const char *fich){
        std::ostringstream sstream;
        sstream<<"Field["<<field_id<<"] = "<<std::string(type_name)<<";";
        add_infile(sstream.str().c_str(),fich);
}
void delete_field(int field_id, const char *fich){
        std::ostringstream sstream;
        sstream<<"Delete Field ["<<field_id<<"];";
        add_infile(sstream.str().c_str(),fich);
}
void set_background_field(int field_id,const char *fich){
        std::ostringstream sstream;
        sstream<<"Background Field = "<<field_id<<";";
        add_infile(sstream.str().c_str(),fich);
}

void add_line(int p1, int p2, const char *fich)
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

void add_circ(int p1, int p2, int p3, const char *fich)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Circle(%d) = {%d,%d,%d};", NEWLINE(), p1, p2, p3);
  add_infile(text, fich);
}

void add_ell(int p1, int p2, int p3, int p4, const char *fich)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Ellipse(%d) = {%d,%d,%d,%d};", NEWLINE(), p1, p2,
           p3, p4);
  add_infile(text, fich);
}

void add_spline(int N, int *p, const char *fich)
{
  char text[BUFFSIZE], text2[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Spline(%d) = {", NEWLINE());
  for(int i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_bezier(int N, int *p, const char *fich)
{
  char text[BUFFSIZE], text2[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Bezier(%d) = {", NEWLINE());
  for(int i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_bspline(int N, int *p, const char *fich)
{
  char text[BUFFSIZE], text2[BUFFSIZE];

  snprintf(text, BUFFSIZE, "BSpline(%d) = {", NEWLINE());
  for(int i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_multline(int N, int *p, const char *fich)
{
  char text[BUFFSIZE], text2[BUFFSIZE];
  int iseg;

  List_T *list = List_Create(N, 2, sizeof(int));
  for(int i = 0; i < N; i++)
    List_Add(list, &p[i]);
  if((recognize_seg(MSH_SEGM_LINE, list, &iseg))) {
    List_Delete(list);
    return;
  }
  List_Delete(list);

  snprintf(text, BUFFSIZE, "Line(%d) = {", NEWLINE());
  for(int i = 0; i < N; i++) {
    if(i != N - 1)
      snprintf(text2, BUFFSIZE, "%d,", p[i]);
    else
      snprintf(text2, BUFFSIZE, "%d};", p[i]);
    strncat(text, text2, BUFFSIZE-strlen(text));
  }
  add_infile(text, fich);
}

void add_lineloop(List_T *list, const char *fich, int *numloop)
{
  char text[BUFFSIZE];

  if((recognize_loop(list, numloop)))
    return;

  *numloop = NEWLINELOOP();
  snprintf(text, BUFFSIZE, "Line Loop(%d) = {", *numloop);
  strncat_list(text, list);
  strncat(text, "};", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_surf(List_T *list, const char *fich, int support, int typ)
{
  char text[BUFFSIZE];

  if(typ == 1) {
    snprintf(text, BUFFSIZE, "Ruled Surface(%d) = {", NEWSURFACE());
  }
  else {
    snprintf(text, BUFFSIZE, "Plane Surface(%d) = {", NEWSURFACE());
  }
  strncat_list(text, list);
  strncat(text, "};", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_surfloop(List_T *list, const char *fich, int *numvol)
{
  char text[BUFFSIZE];

  if((recognize_surfloop(list, numvol)))
    return;

  *numvol = NEWSURFACELOOP();
  snprintf(text, BUFFSIZE, "Surface Loop(%d) = {", *numvol);
  strncat_list(text, list);
  strncat(text, "};", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_vol(List_T *list, const char *fich)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Volume(%d) = {", NEWVOLUME());
  strncat_list(text, list);
  strncat(text, "};", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void add_trsfvol(int N, int *l, const char *fich)
{
  char text[BUFFSIZE], text2[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Transfinite Volume{%d} = {", l[0]);
  for(int i = 1; i < N; i++) {
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

int add_physical(List_T *list, const char *fich, int type)
{
  char text[BUFFSIZE];
  int num = NEWPHYSICAL();
  
  switch (type) {
  case ENT_POINT:
    snprintf(text, BUFFSIZE, "Physical Point(%d) = {", num);
    break;
  case ENT_LINE:
    snprintf(text, BUFFSIZE, "Physical Line(%d) = {", num);
    break;
  case ENT_SURFACE:
    snprintf(text, BUFFSIZE, "Physical Surface(%d) = {", num);
    break;
  case ENT_VOLUME:
    snprintf(text, BUFFSIZE, "Physical Volume(%d) = {", num);
    break;
  }

  strncat_list(text, list);
  strncat(text, "};", BUFFSIZE-strlen(text));
  add_infile(text, fich);
  
  return num;
}

void translate(int add, List_T *list, const char *fich, const char *what,
               const char *tx, const char *ty, const char *tz)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE, "Translate {%s,%s,%s} {\n  Duplicata { %s{", tx, ty, tz, what);
  else
    snprintf(text, BUFFSIZE, "Translate {%s,%s,%s} {\n  %s{", tx, ty, tz, what);

  strncat_list(text, list);
  
  if(add)
    strncat(text, "}; }\n}", BUFFSIZE-strlen(text));
  else
    strncat(text, "};\n}", BUFFSIZE-strlen(text));

  add_infile(text, fich);
}

void rotate(int add, List_T *list, const char *fich, const char *what, 
            const char *ax, const char *ay, const char *az,
            const char *px, const char *py, const char *pz, const char *angle)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE, "Rotate {{%s,%s,%s}, {%s,%s,%s}, %s} {\n  Duplicata { %s{",
             ax, ay, az, px, py, pz, angle, what);
  else
    snprintf(text, BUFFSIZE, "Rotate {{%s,%s,%s}, {%s,%s,%s}, %s} {\n  %s{",
             ax, ay, az, px, py, pz, angle, what);

  strncat_list(text, list);

  if(add)
    strncat(text, "}; }\n}", BUFFSIZE-strlen(text));
  else
    strncat(text, "};\n}", BUFFSIZE-strlen(text));

  add_infile(text, fich);
}

void dilate(int add, List_T *list, const char *fich, const char *what,
            const char *dx, const char *dy, const char *dz, const char *df)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE, "Dilate {{%s,%s,%s}, %s} {\n  Duplicata { %s{",
             dx, dy, dz, df, what);
  else
    snprintf(text, BUFFSIZE, "Dilate {{%s,%s,%s}, %s} {\n  %s{",
             dx, dy, dz, df, what);

  strncat_list(text, list);

  if(add)
    strncat(text, "}; }\n}", BUFFSIZE-strlen(text));
  else
    strncat(text, "};\n}", BUFFSIZE-strlen(text));

  add_infile(text, fich);
}

void symmetry(int add, List_T *list, const char *fich, const char *what,
              const char *sa, const char *sb, const char *sc, const char *sd)
{
  char text[BUFFSIZE];

  if(add)
    snprintf(text, BUFFSIZE, "Symmetry {%s,%s,%s,%s} {\n  Duplicata { %s{",
             sa, sb, sc, sd, what);
  else
    snprintf(text, BUFFSIZE, "Symmetry {%s,%s,%s,%s} {\n  %s{",
             sa, sb, sc, sd, what);

  strncat_list(text, list);

  if(add)
    strncat(text, "}; }\n}", BUFFSIZE-strlen(text));
  else
    strncat(text, "};\n}", BUFFSIZE-strlen(text));

  add_infile(text, fich);
}

void extrude(List_T *list, const char *fich, const char *what, 
             const char *tx, const char *ty, const char *tz)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Extrude {%s,%s,%s} {\n  %s{", tx, ty, tz, what);
  strncat_list(text, list);
  strncat(text, "};\n}", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}

void protude(List_T *list, const char *fich, const char *what, 
             const char *ax, const char *ay, const char *az,
             const char *px, const char *py, const char *pz, const char *angle)
{
  char text[BUFFSIZE];

  snprintf(text, BUFFSIZE, "Extrude {{%s,%s,%s}, {%s,%s,%s}, %s} {\n  %s{",
           ax, ay, az, px, py, pz, angle, what);
  strncat_list(text, list);
  strncat(text, "};\n}", BUFFSIZE-strlen(text));
  add_infile(text, fich);
}
