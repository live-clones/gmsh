// $Id: OpenFile.cpp,v 1.84 2005-10-15 19:06:09 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "BDS.h"
#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "PluginManager.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "MinMax.h"
#include "Visibility.h"
#include "ReadImg.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#include "GUI.h"
extern GUI *WID;
void UpdateViewsInGUI();
#endif

extern Mesh *THEM, M;
extern Context_T CTX;

extern  void BDS_To_Mesh(Mesh *m);
extern  void BDS_To_Mesh_2(Mesh *m);

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

void SetBoundingBox(double xmin, double xmax,
		    double ymin, double ymax, 
		    double zmin, double zmax)
{
  double bbox[6] = {xmin, xmax, ymin, ymax, zmin, zmax};
  CalculateMinMax(NULL, bbox);
}

void SetBoundingBox(void)
{
  if(!THEM) 
    return;
  if (THEM->bds)
  {
      double bbox[6] = {THEM->bds->Min[0],THEM->bds->Max[0],THEM->bds->Min[1],
			THEM->bds->Max[1],THEM->bds->Min[2],THEM->bds->Max[2]};
      CalculateMinMax(NULL, bbox);
  }
  else if(Tree_Nbr(THEM->Vertices)) {
    // if we have mesh vertices, use them
    CalculateMinMax(THEM->Vertices, NULL);
  }
  else if(Tree_Nbr(THEM->Points)) { 
    // else, if we have geometry points, use them
    CalculateMinMax(THEM->Points, NULL);
  }
  else if(List_Nbr(CTX.post.list)) {
    // else, if we have views, use the max bb of all the views
    double bbox[6];
    Post_View *v = *(Post_View **)List_Pointer(CTX.post.list, 0);
    for(int i = 0; i < 6; i++) bbox[i] = v->BBox[i];
    for(int i = 1; i < List_Nbr(CTX.post.list); i++){
      v = *(Post_View **)List_Pointer(CTX.post.list, i);
      if(v->BBox[0] < bbox[0]) bbox[0] = v->BBox[0];
      if(v->BBox[1] > bbox[1]) bbox[1] = v->BBox[1];
      if(v->BBox[2] < bbox[2]) bbox[2] = v->BBox[2];
      if(v->BBox[3] > bbox[3]) bbox[3] = v->BBox[3];
      if(v->BBox[4] < bbox[4]) bbox[4] = v->BBox[4];
      if(v->BBox[5] > bbox[5]) bbox[5] = v->BBox[5];
    }
    CalculateMinMax(NULL, bbox);
  }
  else {
    // else, use a default bbox
    CalculateMinMax(NULL, NULL);
  }
}

int ParseFile(char *f, int silent, int close, int warn_if_missing)
{
  char yyname_old[256], tmp[256];
  FILE *yyin_old, *fp;
  int yylineno_old, yyerrorstate_old, numviews_old, status;

  if(!(fp = fopen(f, "r"))){
    if(warn_if_missing)
      Msg(WARNING, "Unable to open file '%s'", f);
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

  if(!silent)
    Msg(INFO, "Parsing file '%s'", yyname);

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
  if(THEM)
    status = THEM->status;
  else
    status = 0;

  if(close)
    fclose(yyin);

  if(!silent){
    Msg(INFO, "Parsed file '%s'", yyname);
    Msg(STATUS2N, "Read '%s'", yyname);
  }

  SetBoundingBox();

  strncpy(yyname, yyname_old, 255);
  yyin = yyin_old;
  yyerrorstate = yyerrorstate_old;
  yylineno = yylineno_old;

  if(List_Nbr(CTX.post.list) != numviews_old){
#if defined(HAVE_FLTK)
    UpdateViewsInGUI();
#endif
  }
  
  GMSH_Solve_Plugin *sp = GMSH_PluginManager::instance()->findSolverPlugin();
  if(sp) {
    sp->readSolverFile(f);
  }

  return status;
}

void ParseString(char *str)
{
  FILE *fp;
  if(!str)
    return;
  if((fp = fopen(CTX.tmp_filename_fullpath, "w"))) {
    fprintf(fp, "%s\n", str);
    fclose(fp);
    ParseFile(CTX.tmp_filename_fullpath, 0, 1);
  }
}

void SetProjectName(char *name)
{
  char base[356], ext[256];
  SplitFileName(name, base, ext);

  strncpy(CTX.filename, name, 255);
  strncpy(CTX.base_filename, base, 255);
  strncpy(THEM->name, CTX.base_filename, 255);

#if defined(HAVE_FLTK)
  if(!CTX.batch)
    WID->set_title(CTX.filename);
#endif
}

int MergeProblem(char *name, int warn_if_missing)
{
  char ext[256], base[256], tmp[256];
  int status;
  FILE *fp;

  if(!(fp = fopen(name, "r"))){
    if(warn_if_missing)
      Msg(WARNING, "Unable to open file '%s'", name);
    return 0;
  }

  SplitFileName(name, base, ext);

#if defined(HAVE_FLTK)
  if(!CTX.batch) {
    if(!strcmp(ext, ".gz")) {
      // the real solution would be to rewrite all our I/O functions in
      // terms of gzFile, but until then, this is better than nothing
      if(fl_choice("File '%s' is in gzip format.\n\nDo you want to uncompress it?", 
		   "Cancel", "Uncompress", NULL, name)){
	fclose(fp);
	sprintf(tmp, "gunzip -c %s > %s", name, base);
	SystemCall(tmp);
	if(!strcmp(CTX.filename, name)) // this is the project file
	  SetProjectName(base);
	return MergeProblem(base);
      }
    }
  }
#endif
  
  if(!strcmp(ext, ".ppm") || !strcmp(ext, ".pnm")) {
    // An image file is used as an input, we transform it onto a post
    // pro file that could be used as a background mesh. We should
    // check the first bytes of the file instead of the extension to
    // determine the file type.
#if defined(HAVE_FLTK)
    read_pnm(name);
    SetBoundingBox();
#endif
    status = 0;
  }
  else if(!strcmp(ext, ".stl")|| !strcmp(ext, ".STL")|| !strcmp(ext, ".mesh")) 
  {
    if (THEM->bds)delete THEM->bds;
    THEM->bds = new BDS_Mesh;
    if(!strcmp(ext, ".mesh"))
      THEM->bds->read_mesh(name);
    else
      THEM->bds->read_stl(name, CTX.mesh.stl_distance_tol);
    THEM->bds->classify(CTX.mesh.dihedral_angle_tol * M_PI / 180);
    BDS_To_Mesh(THEM);
    THEM->bds_mesh = new BDS_Mesh(*THEM->bds);
    BDS_To_Mesh_2(THEM);
    THEM->status = 2;
    SetBoundingBox();
    status = THEM->status;
  }
  else {
    fpos_t position;
    fgetpos(fp, &position);
    fgets(tmp, sizeof(tmp), fp);
    fsetpos(fp, &position);

    if(!strncmp(tmp, "$PTS", 4) || 
       !strncmp(tmp, "$NO", 3) || 
       !strncmp(tmp, "$ELM", 4) ||
       !strncmp(tmp, "$MeshFormat", 4)) {
      if(THEM->status < 0)
	mai3d(THEM, 0);
      Read_Mesh(THEM, fp, name, FORMAT_MSH);
      SetBoundingBox();
      status = THEM->status;
    }
    else if(!strncmp(tmp, "sms", 3)) {
      if(THEM->status < 0)
	mai3d(THEM, 0);
      Read_Mesh(THEM, fp, name, FORMAT_SMS);
      SetBoundingBox();
      status = THEM->status;
    }
    else if(!strncmp(tmp, "$PostFormat", 11) ||
	    !strncmp(tmp, "$View", 5)) {
      ReadView(fp, name);
      SetBoundingBox();
      status = 0;
    }
    else {
      status = ParseFile(name, 0, 1);
    }
  }

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

  InitSymbols();
  Init_Mesh(&M);

  // Initialize pseudo random mesh generator to the same seed
  srand(1);

  SetProjectName(name);

  int status = MergeProblem(name);

  ApplyLcFactor(THEM);

  CTX.threads_lock = 0;

  if(!status)
    mai3d(THEM, 0);

#if defined(HAVE_FLTK)
  if(!CTX.batch)
    WID->reset_visibility();
  ZeroHighlight(&M);
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

void SystemCall(char *command)
{
#if defined(WIN32) && defined(HAVE_FLTK)
  STARTUPINFO suInfo;           // Process startup information
  PROCESS_INFORMATION prInfo;   // Process information
  memset(&suInfo, 0, sizeof(suInfo));
  suInfo.cb = sizeof(suInfo);
  Msg(INFO, "Calling '%s'", command);
  CreateProcess(NULL, command, NULL, NULL, FALSE,
                NORMAL_PRIORITY_CLASS, NULL, NULL, &suInfo, &prInfo);
#else
  if(!system(NULL)) {
    Msg(GERROR, "Could not find /bin/sh: aborting system call");
    return;
  }
  Msg(INFO, "Calling '%s'", command);
  system(command);
#endif
}
