// $Id: OpenFile.cpp,v 1.42 2003-03-01 22:36:42 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
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
#endif

extern Mesh *THEM, M;
extern Context_T CTX;

int ParseFile(char *f, int silent)
{
  char String[256];
  int status;

  strncpy(yyname, f, 255);
  yyerrorstate = 0;
  yylineno = 1;

  if(!(yyin = fopen(yyname, "r")))
    return 0;

  if(!silent)
    Msg(STATUS2, "Loading '%s'", yyname);

  fpos_t position;
  fgetpos(yyin, &position);
  fgets(String, sizeof(String), yyin);
  fsetpos(yyin, &position);

  if(!strncmp(String, "$PTS", 4) ||
     !strncmp(String, "$NO", 3) || !strncmp(String, "$ELM", 4)) {
    if(THEM->status < 0)
      mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_MSH);
    status = THEM->status;
  }
  else if(!strncmp(String, "sms", 3)) {
    if(THEM->status < 0)
      mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_SMS);
    status = THEM->status;
  }
  else if(!strncmp(String, "$PostFormat", 11) || !strncmp(String, "$View", 5)) {
    ReadView(yyin, yyname);
    status = 0;
  }
  else {
    while(!feof(yyin))
      yyparse();
    if(THEM)
      status = THEM->status;
    else
      status = 0;
  }
  fclose(yyin);

  if(!silent)
    Msg(STATUS2, "Loaded '%s'", yyname);

  return status;
}


void ParseString(char *str)
{
  FILE *f;
  if(!str)
    return;
  if((f = fopen(CTX.tmp_filename, "w"))) {
    fprintf(f, "%s\n", str);
    fclose(f);
    ParseFile(CTX.tmp_filename, 0);
  }
}


int MergeProblem(char *name)
{
  char ext[5];

  if(strlen(name) > 4) {
    strncpy(ext, &name[strlen(name) - 4], 5);
  }
  else {
    strcpy(ext, "");
  }

  // a image file is used as an input, we transform it onto 
  // a post pro file that could be used as a background mesh
  if(!strcmp(ext, ".ppm") || !strcmp(ext, ".pnm")) {
#if defined(HAVE_FLTK)
    read_pnm(name);
#endif
    return 1;
  }
  else {
    return ParseFile(name, 0);
  }
}

void MergeProblemWithBoundingBox(char *name)
{
  int nb = List_Nbr(CTX.post.list);
  int status = MergeProblem(name);
  if(List_Nbr(CTX.post.list) > nb) {
    // if we merged a view, use it
    CalculateMinMax(NULL, ((Post_View *) List_Pointer
                           (CTX.post.list,
                            List_Nbr(CTX.post.list) - 1))->BBox);
  }
  else if(!status) {
    // else, if we did not read a mesh, use the geomnetry
    CalculateMinMax(THEM->Points, NULL);
  }
  else {
    // else, use the mesh
    CalculateMinMax(THEM->Vertices, NULL);
  }
}

void OpenProblem(char *name)
{
  char ext[6];

  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;

  InitSymbols();
  Init_Mesh(&M, 1);

  // Initialize pseudo random mesh generator to the same seed
  srand(1);

  ParseString(TheOptString);

  strncpy(CTX.filename, name, 255);
  strncpy(CTX.base_filename, name, 255);

  if(strlen(name) > 4) {
    strncpy(ext, &name[strlen(name) - 4], 5);
  }
  else {
    strcpy(ext, "");
  }
  if(!strcmp(ext, ".geo") || !strcmp(ext, ".GEO") ||
     !strcmp(ext, ".msh") || !strcmp(ext, ".MSH") ||
     !strcmp(ext, ".stl") || !strcmp(ext, ".STL") ||
     !strcmp(ext, ".sms") || !strcmp(ext, ".SMS") ||
     !strcmp(ext, ".ppm") || !strcmp(ext, ".pnm") ||
     !strcmp(ext, ".pos") || !strcmp(ext, ".POS")) {
    CTX.base_filename[strlen(name) - 4] = '\0';
  }
  else {
    strcat(CTX.filename, ".geo");
  }

  strncpy(THEM->name, CTX.base_filename, 255);

#if defined(HAVE_FLTK)
  if(!CTX.batch)
    WID->set_title(CTX.filename);
#endif

  int status = MergeProblem(CTX.filename);

  ApplyLcFactor(THEM);

  CTX.threads_lock = 0;

  if(!status) {
    mai3d(THEM, 0);
    Maillage_Dimension_0(&M);
  }

#if defined(HAVE_FLTK)
  if(!CTX.batch)
    WID->reset_visibility();
  ZeroHighlight(&M);
#endif

  if(!Tree_Nbr(THEM->Points) && !Tree_Nbr(THEM->Points)
     && List_Nbr(CTX.post.list)) {
    // if there are no points or vertices and there is a view, use it
    CalculateMinMax(NULL, ((Post_View *) List_Pointer
                           (CTX.post.list,
                            List_Nbr(CTX.post.list) - 1))->BBox);
  }
  else if(!status) {
    // else, if we don't have a mesh, use the geometry
    CalculateMinMax(THEM->Points, NULL);
  }
  else {
    // else, suppose we have a mesh (or use a default bbox if empty)
    CalculateMinMax(THEM->Vertices, NULL);
  }

}

// replace "/cygwin/x/" with "x:/"
void decygwin(char *in, char *out)
{
  unsigned int i = 0, j = 0;

  while(i < strlen(in)) {
    if(!strncmp(in + i, "/cygdrive/", 10)) {
      out[j++] = in[i + 10];    // drive letter
      out[j++] = ':';
      out[j++] = '/';
      i += 12;
    }
    else {
      out[j++] = in[i++];
    }
  }
  out[j] = '\0';
}

void SystemCall(char *command)
{
#if defined(WIN32) && defined(HAVE_FLTK)
  STARTUPINFO suInfo;           // Process startup information
  PROCESS_INFORMATION prInfo;   // Process information

  memset(&suInfo, 0, sizeof(suInfo));
  suInfo.cb = sizeof(suInfo);

  char copy[strlen(command) + 1];
  decygwin(command, copy);
  Msg(INFO, "Calling '%s'", copy);
  CreateProcess(NULL, copy, NULL, NULL, FALSE,
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
