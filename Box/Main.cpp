// $Id: Main.cpp,v 1.29 2003-03-21 00:52:34 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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

#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>

#ifdef __APPLE__
#define   RUSAGE_SELF      0
#define   RUSAGE_CHILDREN -1
#endif

#include "ParUtil.h"
#include "PluginManager.h"
#include "Gmsh.h"
#include "GmshVersion.h"
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "Parser.h"
#include "Context.h"
#include "Options.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "MinMax.h"

char yyname[256];
int yyerrorstate;
Context_T CTX;
Mesh M, *THEM = NULL, *LOCAL = NULL;

// Print some help/info messages

void Info(int level, char *arg0)
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
      fprintf(stderr, "%d.%d.%d\n", GMSH_MAJOR_VERSION, GMSH_MINOR_VERSION,
              GMSH_PATCH_VERSION);
    ParUtil::Instance()->Exit();
  case 2:
    if(ParUtil::Instance()->master()) {
      fprintf(stderr, "%s%d.%d.%d\n", gmsh_version, GMSH_MAJOR_VERSION,
              GMSH_MINOR_VERSION, GMSH_PATCH_VERSION);
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

int main(int argc, char *argv[])
{
  int i, nbf;

  ParUtil::Instance()->init(argc, argv);

  Init_Options(0);

  if(argc < 2)
    Info(0, argv[0]);

  Get_Options(argc, argv, &nbf);

  M.Vertices = NULL;
  M.VertexEdges = NULL;
  M.Simplexes = NULL;
  M.Points = NULL;
  M.Curves = NULL;
  M.SurfaceLoops = NULL;
  M.EdgeLoops = NULL;
  M.Surfaces = NULL;
  M.Volumes = NULL;
  M.PhysicalGroups = NULL;
  M.Metric = NULL;

  signal(SIGINT, Signal);
  signal(SIGSEGV, Signal);
  signal(SIGFPE, Signal);

  if(CTX.default_plugins)
    GMSH_PluginManager::Instance()->RegisterDefaultPlugins();

  check_gsl();

  OpenProblem(CTX.filename);
  if(yyerrorstate)
    ParUtil::Instance()->Abort();
  else {
    for(i = 1; i < nbf; i++)
      MergeProblem(TheFileNameTab[i]);
    if(TheBgmFileName) {
      MergeProblem(TheBgmFileName);
      if(List_Nbr(CTX.post.list))
        BGMWithView((Post_View *)
                    List_Pointer(CTX.post.list, List_Nbr(CTX.post.list) - 1));
      else
        fprintf(stderr, ERROR_STR "Invalid background mesh (no view)\n");
      exit(1);
    }
    if(CTX.batch > 0) {
      mai3d(THEM, CTX.batch);
      Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
    }
    else
      Print_Geo(THEM, CTX.output_filename);
    if(CTX.mesh.histogram)
      Print_Histogram(THEM->Histogram[0]);
    ParUtil::Instance()->Barrier(__LINE__, __FILE__);
    ParUtil::Instance()->Exit();
    return 1;
  }
  ParUtil::Instance()->Barrier(__LINE__, __FILE__);
  ParUtil::Instance()->Exit();
  return 1;
}


// Handle signals. We should not use Msg functions in these...

void Signal(int sig_num)
{
  switch (sig_num) {
  case SIGSEGV:
    Msg(FATAL, "Segmentation violation (invalid memory reference)");
    break;
  case SIGFPE:
    Msg(FATAL, "Floating point exception (division by zero?)");
    break;
  case SIGINT:
    Msg(FATAL, "Interrupt (generated from terminal special char)");
    break;
  default:
    Msg(FATAL, "Unknown signal");
    break;
  }
}

// General purpose message routine

void Msg(int level, char *fmt, ...)
{
  va_list args;
  int abort = 0;

  va_start(args, fmt);

  switch (level) {

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
    fprintf(stderr, "On processor %d : ", ParUtil::Instance()->rank());
    fprintf(stderr, FATAL_STR);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    break;

  case GERROR:
  case GERROR1:
  case GERROR2:
  case GERROR3:
    fprintf(stderr, "On processor %d : ", ParUtil::Instance()->rank());
    fprintf(stderr, ERROR_STR);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    break;

  case WARNING:
  case WARNING1:
  case WARNING2:
  case WARNING3:
    if(CTX.verbosity >= 1) {
      fprintf(stderr, "On processor %d : ", ParUtil::Instance()->rank());
      fprintf(stderr, WARNING_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;

  case DEBUG:
  case DEBUG1:
  case DEBUG2:
  case DEBUG3:
    if(CTX.verbosity >= 3 && ParUtil::Instance()->master()) {
      fprintf(stderr, DEBUG_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;

  default:
    if(CTX.verbosity >= 1 && ParUtil::Instance()->master()) {
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

// CPU time computation

void GetResources(long *s, long *us, long *mem)
{
  static struct rusage r;

  getrusage(RUSAGE_SELF, &r);
  *s = (long)r.ru_utime.tv_sec;
  *us = (long)r.ru_utime.tv_usec;
  *mem = (long)r.ru_maxrss;
}

double Cpu(void)
{
  long s, us, mem;
  GetResources(&s, &us, &mem);
  return (double)s + (double)us / 1.e6;
}
