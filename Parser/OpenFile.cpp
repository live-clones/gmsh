// $Id: OpenFile.cpp,v 1.29 2002-05-18 07:56:51 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "Parser.h"
#include "OpenFile.h"
#include "GetOptions.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "MinMax.h"
#include "Visibility.h"

#ifndef _BLACKBOX
#include "GmshUI.h"
#include "Draw.h"
#endif

#if _FLTK
#include "GUI.h"
extern GUI *WID;
#endif

extern Mesh      *THEM, M;
extern Context_T  CTX;

int ParseFile(char *f, int silent){
  char String[256];
  int status;

  strncpy(yyname,f,255);
  yyerrorstate=0;
  yylineno=1;

  if(!(yyin = fopen(yyname,"r")))
    return 0;
  
  if(!silent) Msg(STATUS2, "Loading '%s'", yyname); 

  fpos_t position;
  fgetpos(yyin, &position);
  fgets(String, sizeof(String), yyin) ; 
  fsetpos(yyin, &position);

  if(!strncmp(String, "$PTS", 4) || 
     !strncmp(String, "$NO", 3) || 
     !strncmp(String, "$ELM", 4)){
    if(THEM->status < 0) mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_MSH);
    status = THEM->status;
  }
  else if(!strncmp(String, "sms", 3))
  {
    if(THEM->status < 0) mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_SMS);
    status = THEM->status;
  }
  else if(!strncmp(String, "$PostFormat", 11) ||
          !strncmp(String, "$View", 5)){
    Read_View(yyin, yyname);
    status = 0;
  }
  else{
    while(!feof(yyin)) yyparse();
    if(THEM)
      status = THEM->status;
    else
      status = 0;
  }
  fclose(yyin);

  if(!silent) Msg(STATUS2, "Loaded '%s'", yyname); 

  return status;
}


void ParseString(char *str){
  FILE *f;
  if(!str)return;
  if((f = fopen(CTX.tmp_filename,"w"))){
    fprintf(f,"%s\n", str);
    fclose(f);
    ParseFile(CTX.tmp_filename,0);
  }
}

void MergeProblem(char *name){
  ParseFile(name,0);  
}

void OpenProblem(char *name){
  char ext[6];
  int  status;

  if(CTX.threads_lock){
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;

  InitSymbols();
  Init_Mesh(&M, 1);

  // Initialize pseudo random mesh generator to the same seed
  srand(1);

  ParseString(TheOptString);

  strncpy(CTX.filename,name,255);
  strncpy(CTX.base_filename,name,255);

  strcpy(ext,name+(strlen(name)-4));
  if(!strcmp(ext,".geo") || !strcmp(ext,".GEO") ||
     !strcmp(ext,".msh") || !strcmp(ext,".MSH") ||
     !strcmp(ext,".stl") || !strcmp(ext,".STL") ||
     !strcmp(ext,".sms") || !strcmp(ext,".SMS") ||
     !strcmp(ext,".pos") || !strcmp(ext,".POS")){
    CTX.base_filename[strlen(name)-4] = '\0';
  }
  else{
    strcat(CTX.filename,".geo");
  }

  strncpy(THEM->name, CTX.base_filename,255);

#if _FLTK
  if(!CTX.batch) WID->set_title(CTX.filename);
#endif

  int nb = List_Nbr(CTX.post.list);

  status = ParseFile(CTX.filename,0);

  ApplyLcFactor(THEM);

  CTX.threads_lock = 0;

  if(!status){
    mai3d(THEM,0);  
    Maillage_Dimension_0(&M);
  }

#if _FLTK
  if(!CTX.batch) WID->reset_visibility();
#endif

#ifndef _BLACKBOX
  ZeroHighlight(&M); 
#endif
  
  if(List_Nbr(CTX.post.list) > nb)
    CalculateMinMax(NULL, ((Post_View*)List_Pointer
			   (CTX.post.list,List_Nbr(CTX.post.list)-1))->BBox);
  else if(!status) 
    CalculateMinMax(THEM->Points,NULL);
  else
    CalculateMinMax(THEM->Vertices,NULL);

}

