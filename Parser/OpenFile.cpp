// $Id: OpenFile.cpp,v 1.111 2006-08-15 04:15:19 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#if defined(__CYGWIN__)
#include <sys/cygwin.h>
#endif

#include "Gmsh.h"
#include "gmshModel.h"
#include "Numeric.h"
#include "Context.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Views.h"
#include "Mesh.h"
#include "ReadImg.h"
#include "OS.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#include "GUI.h"
extern GUI *WID;
void UpdateViewsInGUI();
#endif

extern GModel *GMODEL;
extern Context_T CTX;

void FixRelativePath(char *in, char *out){
  if(in[0] == '/' || in[0] == '\\' || (strlen(in)>2 && in[1] == ':')){
    // do nothing: 'in' is an absolute path
    strcpy(out, in);
  }
  else{
    // append 'in' to the path of the parent file
    strcpy(out, yyname);
    int i = strlen(out)-1 ;
    while(i >= 0 && yyname[i] != '/' && yyname[i] != '\\') i-- ;
    out[i+1] = '\0';
    strcat(out, in);
  }
}

void FixWindowsPath(char *in, char *out){
#if defined(__CYGWIN__)
  cygwin_conv_to_win32_path(in, out);
#else
  strcpy(out, in);
#endif
}

void SplitFileName(char *name, char *base, char *ext)
{
  strcpy(base, name);
  strcpy(ext, "");
  for(int i = strlen(name)-1; i >= 0; i--){
    if(name[i] == '.'){
      strcpy(ext, &name[i]);
      base[i] = '\0';
      break;
    }
  }
}

static void FinishUpBoundingBox()
{
  double range[3];

  for(int i = 0; i < 3; i++){
    CTX.cg[i] = 0.5 * (CTX.min[i] + CTX.max[i]);
    range[i] = CTX.max[i] - CTX.min[i];
  }

  if(range[0] == 0. && range[1] == 0. && range[2] == 0.) {
    CTX.min[0] -= 1.; CTX.min[1] -= 1.;
    CTX.max[0] += 1.; CTX.max[1] += 1.;
    CTX.lc = 1.;
  }
  else if(range[0] == 0. && range[1] == 0.) {
    CTX.lc = range[2];
    CTX.min[0] -= CTX.lc; CTX.min[1] -= CTX.lc;
    CTX.max[0] += CTX.lc; CTX.max[1] += CTX.lc;
  }
  else if(range[0] == 0. && range[2] == 0.) {
    CTX.lc = range[1];
    CTX.min[0] -= CTX.lc; CTX.max[0] += CTX.lc;
  }
  else if(range[1] == 0. && range[2] == 0.) {
    CTX.lc = range[0];
    CTX.min[1] -= CTX.lc; CTX.max[1] += CTX.lc;
  }
  else if(range[0] == 0.) {
    CTX.lc = sqrt(DSQR(range[1]) + DSQR(range[2]));
    CTX.min[0] -= CTX.lc; CTX.max[0] += CTX.lc;
  }
  else if(range[1] == 0.) {
    CTX.lc = sqrt(DSQR(range[0]) + DSQR(range[2]));
    CTX.min[1] -= CTX.lc; CTX.max[1] += CTX.lc;
  }
  else if(range[2] == 0.) {
    CTX.lc = sqrt(DSQR(range[0]) + DSQR(range[1]));
  }
  else {
    CTX.lc = sqrt(DSQR(range[0]) + DSQR(range[1]) + DSQR(range[2]));
  }
}

void SetBoundingBox(double xmin, double xmax,
		    double ymin, double ymax, 
		    double zmin, double zmax)
{
  CTX.min[0] = xmin; CTX.max[0] = xmax;
  CTX.min[1] = ymin; CTX.max[1] = ymax;
  CTX.min[2] = zmin; CTX.max[2] = zmax;
  FinishUpBoundingBox();
}

void SetBoundingBox(void)
{
  if(CTX.forced_bbox) return;

  SBoundingBox3d bb;

  bb = GMODEL->bounds();
  
  if(bb.empty() && List_Nbr(CTX.post.list)) {
    for(int i = 0; i < List_Nbr(CTX.post.list); i++){
      Post_View *v = *(Post_View **)List_Pointer(CTX.post.list, i);
      bb += SPoint3(v->BBox[0], v->BBox[2], v->BBox[4]);
      bb += SPoint3(v->BBox[1], v->BBox[3], v->BBox[5]);
    }
  }
  
  if(bb.empty()){
    bb += SPoint3(-1., -1., -1.);
    bb += SPoint3(1., 1., 1.);
  }
  
  CTX.min[0] = bb.min().x(); CTX.max[0] = bb.max().x();
  CTX.min[1] = bb.min().y(); CTX.max[1] = bb.max().y();
  CTX.min[2] = bb.min().z(); CTX.max[2] = bb.max().z();
  FinishUpBoundingBox();
}

int ParseFile(char *f, int close, int warn_if_missing)
{
  char yyname_old[256], tmp[256];
  FILE *yyin_old, *fp;
  int yylineno_old, yyerrorstate_old, numviews_old;

  // add 'b' for pure Windows programs: opening in text mode messes up
  // fsetpos/fgetpos (used e.g. for user-defined functions)
  if(!(fp = fopen(f, "rb"))){
    if(warn_if_missing) Msg(WARNING, "Unable to open file '%s'", f);
    return 0;
  }

  strncpy(yyname_old, yyname, 255);
  yyin_old = yyin;
  yyerrorstate_old = yyerrorstate;
  yylineno_old = yylineno;
  numviews_old = List_Nbr(CTX.post.list);

  strncpy(yyname, f, 255);
  yyin = fp;
  yyerrorstate = 0;
  yylineno = 1;

  fpos_t position;
  fgetpos(yyin, &position);
  fgets(tmp, sizeof(tmp), yyin);
  fsetpos(yyin, &position);

  while(!feof(yyin)){
    yyparse();
    if(yyerrorstate > 20){
      Msg(GERROR, "Too many errors: aborting...");
      force_yyflush();
      break;
    }
  }

  if(close)
    fclose(yyin);

  GMODEL->import();

  strncpy(yyname, yyname_old, 255);
  yyin = yyin_old;
  yyerrorstate = yyerrorstate_old;
  yylineno = yylineno_old;

  if(List_Nbr(CTX.post.list) != numviews_old){
#if defined(HAVE_FLTK)
    UpdateViewsInGUI();
#endif
  }
  
  return 1;
}

void ParseString(char *str)
{
  if(!str) return;
  FILE *fp;
  if((fp = fopen(CTX.tmp_filename_fullpath, "w"))) {
    fprintf(fp, str);
    fprintf(fp, "\n");
    fclose(fp);
    ParseFile(CTX.tmp_filename_fullpath, 1);
  }
}

void SetProjectName(char *name)
{
  char base[356], ext[256];
  SplitFileName(name, base, ext);

  strncpy(CTX.filename, name, 255);
  strncpy(CTX.base_filename, base, 255);

#if defined(HAVE_FLTK)
  if(!CTX.batch) WID->set_title(CTX.filename);
#endif
}

int MergeProblem(char *name, int warn_if_missing)
{
  // added 'b' for pure Windows programs, since some of these files
  // contain binary data
  FILE *fp;
  if(!(fp = fopen(name, "rb"))){
    if(warn_if_missing) Msg(WARNING, "Unable to open file '%s'", name);
    return 0;
  }

  Msg(STATUS2, "Reading '%s'", name);

  char ext[256], base[256];
  SplitFileName(name, base, ext);

#if defined(HAVE_FLTK)
  if(!CTX.batch) {
    if(!strcmp(ext, ".gz")) {
      // the real solution would be to rewrite all our I/O functions in
      // terms of gzFile, but until then, this is better than nothing
      if(fl_choice("File '%s' is in gzip format.\n\nDo you want to uncompress it?", 
		   "Cancel", "Uncompress", NULL, name)){
	fclose(fp);
	char tmp[256];
	sprintf(tmp, "gunzip -c %s > %s", name, base);
	SystemCall(tmp);
	if(!strcmp(CTX.filename, name)) // this is the project file
	  SetProjectName(base);
	return MergeProblem(base);
      }
    }
  }
#endif

  int status = 0;
  if(!strcmp(ext, ".stl") || !strcmp(ext, ".STL")){
    status = GMODEL->readSTL(name, CTX.mesh.stl_distance_tol);
  }
  else if(!strcmp(ext, ".mesh")){
    status = GMODEL->readMESH(name);
  }
#if defined(HAVE_FLTK)
  else if(!strcmp(ext, ".pnm") || !strcmp(ext, ".PNM") ||
	  !strcmp(ext, ".pbm") || !strcmp(ext, ".PBM") ||
	  !strcmp(ext, ".pgm") || !strcmp(ext, ".PGM") ||
	  !strcmp(ext, ".ppm") || !strcmp(ext, ".PPM")) {
    status = read_pnm(name);
  }
  else if(!strcmp(ext, ".bmp") || !strcmp(ext, ".BMP")) {
    status = read_bmp(name);
  }
#if defined(HAVE_LIBJPEG)
  else if(!strcmp(ext, ".jpg") || !strcmp(ext, ".JPG") ||
	  !strcmp(ext, ".jpeg") || !strcmp(ext, ".JPEG")) {
    status = read_jpeg(name);
  }
#endif
#if defined(HAVE_LIBPNG)
  else if(!strcmp(ext, ".png") || !strcmp(ext, ".PNG")) {
    status = read_png(name);
  }
#endif
#endif
  else {
    fpos_t position;
    fgetpos(fp, &position);
    char tmp[256];
    fgets(tmp, sizeof(tmp), fp);
    fsetpos(fp, &position);
    if(!strncmp(tmp, "$PTS", 4) || !strncmp(tmp, "$NO", 3) || 
       !strncmp(tmp, "$PARA", 5) || !strncmp(tmp, "$ELM", 4) ||
       !strncmp(tmp, "$MeshFormat", 11)) {
      status = GMODEL->readMSH(name);
    }
    else if(!strncmp(tmp, "$PostFormat", 11) || !strncmp(tmp, "$View", 5)) {
      status = ReadView(name);
    }
    else {
      status = ParseFile(name, 1);
    }
  }

  SetBoundingBox();
  CTX.mesh.changed = 1;
  Msg(STATUS2, "Read '%s'", name);
  fclose(fp);
  return status;
}

void OpenProblem(char *name)
{
  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;

  // recreate a brand new gmsh model
  if(GMODEL) delete GMODEL;
  GMODEL = new gmshModel;

  Init_Mesh();

  // Initialize pseudo random mesh generator to the same seed
  srand(1);

  SetProjectName(name);
  MergeProblem(name);
  ApplyLcFactor();

  CTX.threads_lock = 0;

#if defined(HAVE_FLTK)
  if(!CTX.batch) WID->reset_visibility();
  ZeroHighlight();
#endif
}

void OpenProblemMacFinder(const char *filename)
{
  static int first = 1;
  if(first){
    // just copy the filename: it will be opened when Gmsh is ready in
    // main() (calling OpenProblem right now would be a bad idea: Gmsh
    // is probably not completely initialized)
    strncpy(CTX.filename, filename, 255);
    first = 0;
  }
  else{
    // should we do MergeProblem instead? not sure what's the most
    // intuitive
    OpenProblem((char*)filename);
#if defined(HAVE_FLTK)
    Draw();
#endif
  }
}

