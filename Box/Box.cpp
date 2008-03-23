// $Id: Box.cpp,v 1.50 2008-03-23 21:42:56 geuzaine Exp $
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

#include "GModel.h"
#include "Gmsh.h"
#include "Message.h"
#include "Generator.h"
#include "Parser.h"
#include "Context.h"
#include "Options.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "CreateFile.h"
#include "ParUtil.h"
#include "Field.h"
#include "BackgroundMesh.h"

Context_T CTX;

// Print some help/info messages

static void Info(int level, char *arg0)
{
  switch (level) {
  case 0:
    if(ParUtil::Instance()->master()) {
      fprintf(stderr, "%s\n", gmsh_progname);
      fprintf(stderr, "%s\n", gmsh_copyright);
      Print_Usage(arg0);
    }
    ParUtil::Instance()->Exit();
  case 1:
    if(ParUtil::Instance()->master())
      fprintf(stderr, "%s\n", Get_GmshVersion());
    ParUtil::Instance()->Exit();
  case 2:
    if(ParUtil::Instance()->master()) {
      fprintf(stderr, "%s%s\n", gmsh_version, Get_GmshVersion());
      fprintf(stderr, "%s\n", gmsh_os);
      fprintf(stderr, "%s\n", gmsh_date);
      fprintf(stderr, "%s\n", gmsh_host);
      fprintf(stderr, "%s\n", gmsh_packager);
      fprintf(stderr, "%s\n", gmsh_url);
      fprintf(stderr, "%s\n", gmsh_email);
    }
    ParUtil::Instance()->Exit();
  default:
    break;
  }
}

// Main routine for the batch (black box) version

int GMSHBOX(int argc, char *argv[])
{
  ParUtil::Instance()->init(argc, argv);

  if(argc < 2) Info(0, argv[0]);

  GmshInitialize(argc, argv);

  new GModel;

  OpenProject(CTX.filename);
  if(gmsh_yyerrorstate)
    ParUtil::Instance()->Abort();
  else {
    for(unsigned int i = 1; i < CTX.files.size(); i++)
      MergeFile(CTX.files[i].c_str());
    if(CTX.bgm_filename) {
      MergeFile(CTX.bgm_filename);
      if(PView::list.size())
        GModel::current()->getFields()->set_background_mesh(PView::list.size() - 1);
      else
        fprintf(stderr, ERROR_STR "Invalid background mesh (no view)\n");
    }
    if(CTX.batch > 0) {
      GModel::current()->mesh(CTX.batch);
      CreateOutputFile(CTX.output_filename, CTX.mesh.format);
    }
    else if(CTX.batch == -1)
      CreateOutputFile(CTX.output_filename, FORMAT_GEO);
    ParUtil::Instance()->Barrier(__LINE__, __FILE__);
    return 1;
  }
  ParUtil::Instance()->Barrier(__LINE__, __FILE__);

  GmshFinalize();
  
  return 1;
}

// General purpose message routine

void Msg(int level, const char *fmt, ...)
{
  va_list args;
  int abort = 0;

  va_start(args, fmt);

  switch (level) {

  case PROGRESS:
  case STATUS1N:
  case STATUS2N:
    break;

  case DIRECT:
    if(CTX.verbosity >= 2 && ParUtil::Instance()->master()) {
      vfprintf(stdout, fmt, args);
      fprintf(stdout, "\n");
    }
    break;

  case FATAL:
  case FATAL3: abort = 1;
  case FATAL1:
  case FATAL2:
    fprintf(stderr, FATAL_STR);
    fprintf(stderr, "[on processor %d] ", ParUtil::Instance()->rank());
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    break;

  case GERROR:
  case GERROR1:
  case GERROR2:
  case GERROR3:
    fprintf(stderr, ERROR_STR);
    fprintf(stderr, "[on processor %d] ", ParUtil::Instance()->rank());
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    break;

  case WARNING:
  case WARNING1:
  case WARNING2:
  case WARNING3:
    if(CTX.verbosity >= 1) {
      fprintf(stderr, WARNING_STR);
      fprintf(stderr, "[on processor %d] ", ParUtil::Instance()->rank());
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;

  case DEBUG:
  case DEBUG1:
  case DEBUG2:
  case DEBUG3:
    if(CTX.verbosity >= 4 && ParUtil::Instance()->master()) {
      fprintf(stderr, DEBUG_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;

  default:
    if(CTX.verbosity >= 2 && ParUtil::Instance()->master()) {
      fprintf(stderr, INFO_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;
  }

  va_end(args);

  if(abort)
    exit(1);
}

// interactive value dialog

double GetValue(const char *text, double defaultval)
{
  if(CTX.nopopup)
    return defaultval;

  printf("%s (default=%.16g): ", text, defaultval);
  char str[256];
  fgets(str, sizeof(str), stdin);
  if(!strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return atof(str);
}

bool GetBinaryAnswer(const char *question, const char *yes, const char *no, 
                     bool defaultval)
{
  if(CTX.nopopup || CTX.batch)
    return defaultval;

  char answ[256];

  while(1){
    printf("%s (%s/%s)",question,yes,no);
    scanf("%s ",answ);
    if (!strcmp(answ,yes))return true;
    if (!strcmp(answ,no))return false;
  }
}

