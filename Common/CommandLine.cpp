// $Id: CommandLine.cpp,v 1.120 2008-02-23 19:49:35 geuzaine Exp $
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
#include "GmshUI.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#include "Message.h"
#include "CommandLine.h"
#include "Numeric.h"
#include "Context.h"
#include "Options.h"
#include "PView.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Parser.h"
#include "GModel.h"
#include "OS.h"

#if !defined(GMSH_EXTRA_VERSION)
#error
#error Common/GmshVersion.h is not up-to-date.
#error Please run 'make tag'.
#error
#endif

extern Context_T CTX;

char gmsh_progname[]  = "Gmsh, a 3D mesh generator with pre- and post-processing facilities" ;
char gmsh_copyright[] = "Copyright (C) 1997-2008 Christophe Geuzaine and Jean-Francois Remacle";
char gmsh_version[]   = "Version        : " ;
char gmsh_license[]   = "License        : " GMSH_SHORT_LICENSE;
char gmsh_gui[]       = "GUI toolkit    : " ;
char gmsh_os[]        = "Build OS       : " GMSH_OS ;
char gmsh_options[]   = "Build options  : " ;
char gmsh_date[]      = "Build date     : " GMSH_DATE ;
char gmsh_host[]      = "Build host     : " GMSH_HOST ;
char gmsh_packager[]  = "Packager       : " GMSH_PACKAGER ;
char gmsh_url[]       = "Web site       : http://www.geuz.org/gmsh/" ;
char gmsh_email[]     = "Mailing list   : gmsh@geuz.org" ;

int Get_GmshMajorVersion(){ return GMSH_MAJOR_VERSION; }
int Get_GmshMinorVersion(){ return GMSH_MINOR_VERSION; }
int Get_GmshPatchVersion(){ return GMSH_PATCH_VERSION; }
const char *Get_GmshExtraVersion(){ return GMSH_EXTRA_VERSION; }
const char *Get_GmshVersion(){ return GMSH_VERSION; }
const char *Get_GmshBuildDate(){ return GMSH_DATE; }
const char *Get_GmshBuildHost(){ return GMSH_HOST; }
const char *Get_GmshPackager(){ return GMSH_PACKAGER; }
const char *Get_GmshBuildOS(){ return GMSH_OS; }
const char *Get_GmshShortLicense(){ return GMSH_SHORT_LICENSE; }

void Print_Usage(const char *name)
{
  // If you make changes in this routine, please also change the
  // texinfo documentation (doc/texinfo/command_line.texi) as well as
  // the man page (doc/gmsh.1)
  Msg(DIRECT, "Usage: %s [options] [files]", name);
  Msg(DIRECT, "Geometry options:");
  Msg(DIRECT, "  -0                    Output unrolled geometry, then exit");
  Msg(DIRECT, "  -tol float            Set geometrical tolerance");
  Msg(DIRECT, "Mesh options:");
  Msg(DIRECT, "  -1, -2, -3            Perform 1D, 2D or 3D mesh generation, then exit");
  Msg(DIRECT, "  -saveall              Save all elements (discard physical group definitions)");
  Msg(DIRECT, "  -o file               Specify mesh output file name");
  Msg(DIRECT, "  -format string        Set output mesh format (msh, msh1, msh2, unv, vrml, stl, mesh,");
  Msg(DIRECT, "                          bdf, p3d, cgns, med)");
  Msg(DIRECT, "  -bin                  Use binary format when available");  
  Msg(DIRECT, "  -algo string          Select mesh algorithm (iso, netgen, tetgen)");
  Msg(DIRECT, "  -smooth int           Set number of mesh smoothing steps");
  Msg(DIRECT, "  -optimize[_netgen]    Optimize quality of tetrahedral elements");
  Msg(DIRECT, "  -order int            Set mesh order (1, ..., 5)");
  Msg(DIRECT, "  -optimize_hom         Optimize higher order meshes (in 2D)");
  Msg(DIRECT, "  -clscale float        Set characteristic length scaling factor");
  Msg(DIRECT, "  -clmin float          Set minimum characteristic length");
  Msg(DIRECT, "  -clmax float          Set maximum characteristic length");
  Msg(DIRECT, "  -clcurv               Compute characteristic lengths from curvatures");
  Msg(DIRECT, "  -epslc1d              Set the accuracy of the evaluation of the LCFIELD for 1D mesh");
  Msg(DIRECT, "  -swapangle            Set the treshold angle (in degree) between two adjacent faces");
  Msg(DIRECT, "                          below which a swap is allowed");
  Msg(DIRECT, "  -rand float           Set random perturbation factor");
  Msg(DIRECT, "  -bgm file             Load background mesh from file");
  Msg(DIRECT, "  -constrain            Constrain background mesh with characteristic lengths");
#if defined(HAVE_FLTK)
  Msg(DIRECT, "Post-processing options:");
  Msg(DIRECT, "  -noview               Hide all views on startup");
  Msg(DIRECT, "  -link int             Select link mode between views (0, 1, 2, 3, 4)");
  Msg(DIRECT, "  -combine              Combine views having identical names into multi-time-step views");
  Msg(DIRECT, "Display options:");    
  Msg(DIRECT, "  -nodb                 Disable double buffering");
  Msg(DIRECT, "  -fontsize int         Specify the font size for the GUI");
  Msg(DIRECT, "  -theme string         Specify FLTK GUI theme");
  Msg(DIRECT, "  -display string       Specify display");
#endif
  Msg(DIRECT, "Other options:");      
  Msg(DIRECT, "  -                     Parse input files, then exit");
#if defined(HAVE_FLTK)
  Msg(DIRECT, "  -a, -g, -m, -s, -p    Start in automatic, geometry, mesh, solver or post-processing mode");
#endif
  Msg(DIRECT, "  -pid                  Print process id on stdout");
  Msg(DIRECT, "  -listen               Always listen to incoming connection requests");
  Msg(DIRECT, "  -v int                Set verbosity level");
  Msg(DIRECT, "  -nopopup              Don't popup dialog windows in scripts");
  Msg(DIRECT, "  -string \"string\"      Parse option string at startup");
  Msg(DIRECT, "  -option file          Parse option file at startup");
  Msg(DIRECT, "  -convert files        Convert files into latest binary formats, then exit");
  Msg(DIRECT, "  -version              Show version number");
  Msg(DIRECT, "  -info                 Show detailed version information");
  Msg(DIRECT, "  -help                 Show this message");
}

char *Get_BuildOptions(void)
{
  static int first=1;
  static char opt[128] = "";
  
  if(first){
#if defined(HAVE_GSL)
    strcat(opt, "GSL ");
#endif
#if defined(HAVE_NETGEN)
    strcat(opt, "NETGEN ");
#endif
#if defined(HAVE_TETGEN)
    strcat(opt, "TETGEN ");
#endif
#if defined(HAVE_LIBJPEG)
    strcat(opt, "JPEG ");
#endif
#if defined(HAVE_LIBPNG)
    strcat(opt, "PNG ");
#endif
#if defined(HAVE_LIBZ)
    strcat(opt, "ZLIB ");
#endif
#if defined(HAVE_MATH_EVAL)
    strcat(opt, "MATHEVAL ");
#endif
#if defined(HAVE_METIS)
    strcat(opt, "METIS ");
#endif
#if defined(HAVE_ANN)
    strcat(opt, "ANN ");
#endif
#if defined(HAVE_CGNS)
    strcat(opt, "CGNS ");
#endif
#if defined(HAVE_OCC)
    strcat(opt, "OCC ");
#endif
#if defined(HAVE_MED)
    strcat(opt, "MED ");
#endif
    first = 0;
  }
  return opt;
}

void Get_Options(int argc, char *argv[])
{
  // Parse session and option files
  ParseFile(CTX.session_filename_fullpath, 1);
  ParseFile(CTX.options_filename_fullpath, 1);

  // Get command line options
  int i = 1;
  while(i < argc) {

    if(argv[i][0] == '-') {

      if(!strcmp(argv[i] + 1, "")) {
        CTX.batch = -2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "0")) {
        CTX.batch = -1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "1")) {
        CTX.batch = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "2")) {
        CTX.batch = 2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "3")) {
        CTX.batch = 3;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "4")) {
        CTX.batch = 4;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "pid")) {
	fprintf(stdout, "%d\n", GetProcessId());
	fflush(stdout);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "a")) {
        CTX.initial_context = 0;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "g")) {
        CTX.initial_context = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "m")) {
        CTX.initial_context = 2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "s")) {
        CTX.initial_context = 3;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "p")) {
        CTX.initial_context = 4;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "saveall")) {
        CTX.mesh.save_all = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "optimize")) {
        CTX.mesh.optimize = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "optimize_netgen")) {
        CTX.mesh.optimize_netgen = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "nopopup")) {
        CTX.nopopup = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "string")) {
        i++;
        if(argv[i] != NULL)
	  ParseString(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing string\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "option")) {
        i++;
        if(argv[i] != NULL)
          ParseFile(argv[i++], 1);
        else {
          fprintf(stderr, ERROR_STR "Missing file name\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "o")) {
        i++;
        if(argv[i] != NULL)
          CTX.output_filename = argv[i++];
        else {
          fprintf(stderr, ERROR_STR "Missing file name\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "bgm")) {
        i++;
        if(argv[i] != NULL)
          CTX.bgm_filename = argv[i++];
        else {
          fprintf(stderr, ERROR_STR "Missing file name\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "constrain")) {
        CTX.mesh.constrained_bgmesh = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "convert")) {
        i++;
        CTX.terminal = 1;
        CTX.batch = 1;
	while(i < argc) {
	  char filename[256];
	  sprintf(filename, "%s_new", argv[i]);
	  unsigned int n = PView::list.size();
          OpenProject(argv[i]);
	  // convert post-processing views to latest binary format
          for(unsigned int j = n; j < PView::list.size(); j++)
	    PView::list[j]->write(filename, 1, (j == n) ? false : true);
	  // convert mesh to latest binary format
	  if(GModel::current()->getMeshStatus() > 0){
	    CTX.mesh.msh_file_version = 2.0;
	    CTX.mesh.msh_binary = 1;
	    CreateOutputFile(filename, FORMAT_MSH);
	  }
	  i++;
        }
        exit(1);
      }
      else if(!strcmp(argv[i] + 1, "tol")) {
        i++;
        if(argv[i] != NULL)
          CTX.geom.tolerance = atof(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "scale")) {
        i++;
        if(argv[i] != NULL)
          CTX.geom.scaling_factor = atof(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "meshscale")) {
        i++;
        if(argv[i] != NULL)
          CTX.mesh.scaling_factor = atof(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "rand")) {
        i++;
        if(argv[i] != NULL)
          CTX.mesh.rand_factor = atof(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "clscale")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_factor = atof(argv[i++]);
          if(CTX.mesh.lc_factor <= 0.0) {
            fprintf(stderr, ERROR_STR
                    "Characteristic length factor must be > 0\n");
            exit(1);
          }
        }
      }
      else if(!strcmp(argv[i] + 1, "clmin")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_min = atof(argv[i++]);
          if(CTX.mesh.lc_min <= 0.0) {
            fprintf(stderr, ERROR_STR
                    "Minimum length size must be > 0\n");
            exit(1);
          }
        }
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "clmax")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_max = atof(argv[i++]);
          if(CTX.mesh.lc_max <= 0.0) {
            fprintf(stderr, ERROR_STR
                    "Maximum length size must be > 0\n");
            exit(1);
          }
        }
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "epslc1d")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_integration_precision = atof(argv[i++]);
          if(CTX.mesh.lc_integration_precision <= 0.0) {
            fprintf(stderr, ERROR_STR 
		    "Integration Accuraci for evaluation of 1D LC FIELD must be > 0\n");
            exit(1);
          }
        }
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "swapangle")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.allow_swap_edge_angle = atof(argv[i++]);
          if(CTX.mesh.allow_swap_edge_angle <= 0.0) {
            fprintf(stderr, ERROR_STR "Treshold angle for edge swap  must be > 0\n");
            exit(1);
          }
        }
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "clcurv")) {
        CTX.mesh.lc_from_curvature = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "smooth")) {
        i++;
        if(argv[i] != NULL)
          CTX.mesh.nb_smoothing = atoi(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "order") || !strcmp(argv[i] + 1, "degree")) {
        i++;
        if(argv[i] != NULL)
          opt_mesh_order(0, GMSH_SET, atof(argv[i++]));
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "c1")) {
        i++;
	opt_mesh_c1(0, GMSH_SET, 1);
      }
      else if(!strcmp(argv[i] + 1, "statreport")) {
        i++;
	CTX.create_append_statreport = 1;
        if(argv[i] != NULL) {
          strcpy(CTX.statreport,argv[i]);
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing argument\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "append_statreport")) {
        i++;
	CTX.create_append_statreport = 2;
        if(argv[i] != NULL) {
          strcpy(CTX.statreport,argv[i]);
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing argument\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "optimize_hom")) {
        i++;
	opt_mesh_smooth_internal_edges(0, GMSH_SET, 1);
      }
      else if(!strcmp(argv[i] + 1, "format") || !strcmp(argv[i] + 1, "f")) {
        i++;
        if(argv[i] != NULL) {
          if(!strcmp(argv[i], "msh1")){
            CTX.mesh.format = FORMAT_MSH;
	    CTX.mesh.msh_file_version = 1.0;
	  }
          else if(!strcmp(argv[i], "msh2")){
            CTX.mesh.format = FORMAT_MSH;
	    CTX.mesh.msh_file_version = 2.0;
	  }
          else if(!strcmp(argv[i], "msh"))
            CTX.mesh.format = FORMAT_MSH;
          else if(!strcmp(argv[i], "unv"))
            CTX.mesh.format = FORMAT_UNV;
          else if(!strcmp(argv[i], "vrml"))
            CTX.mesh.format = FORMAT_VRML;
	  else if(!strcmp(argv[i], "stl"))
            CTX.mesh.format = FORMAT_STL;
          else if(!strcmp(argv[i], "mesh"))
            CTX.mesh.format = FORMAT_MESH;
          else if(!strcmp(argv[i], "bdf"))
            CTX.mesh.format = FORMAT_BDF;
          else if(!strcmp(argv[i], "p3d"))
            CTX.mesh.format = FORMAT_P3D;
          else if(!strcmp(argv[i], "cgns"))
            CTX.mesh.format = FORMAT_CGNS;
          else if(!strcmp(argv[i], "med"))
            CTX.mesh.format = FORMAT_MED;
          else {
            fprintf(stderr, ERROR_STR "Unknown mesh format\n");
            exit(1);
          }
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing format\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "bin")) {
        i++;
	CTX.mesh.stl_binary = CTX.mesh.msh_binary = 1;
      }
      else if(!strcmp(argv[i] + 1, "algo")) {
        i++;
        if(argv[i] != NULL) {
          if(!strncmp(argv[i], "del3d", 5) || !strncmp(argv[i], "tetgen", 6))
            CTX.mesh.algo2d = ALGO_3D_TETGEN_DELAUNAY;
          else if(!strncmp(argv[i], "netgen", 6))
            CTX.mesh.algo3d = ALGO_3D_NETGEN;
          else if(!strncmp(argv[i], "del2d", 5) || !strncmp(argv[i], "tri", 3))
            CTX.mesh.algo2d = ALGO_2D_DELAUNAY;
          else if(!strncmp(argv[i], "bds", 3))
            CTX.mesh.algo2d = ALGO_2D_MESHADAPT;
          else if(!strncmp(argv[i], "del", 3) || !strncmp(argv[i], "iso", 3))
	    CTX.mesh.algo2d = ALGO_2D_MESHADAPT_DELAUNAY;
          else {
            fprintf(stderr, ERROR_STR "Unknown mesh algorithm\n");
            exit(1);
          }
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing algorithm\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "listen")) {
        CTX.solver.listen = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "version") || !strcmp(argv[i] + 1, "-version")) {
        fprintf(stderr, "%s\n", GMSH_VERSION);
        exit(1);
      }
      else if(!strcmp(argv[i] + 1, "info") || !strcmp(argv[i] + 1, "-info")) {
        fprintf(stderr, "%s%s\n", gmsh_version, GMSH_VERSION);
#if defined(HAVE_FLTK)
        fprintf(stderr, "%sFLTK %d.%d.%d\n", gmsh_gui, FL_MAJOR_VERSION,
                FL_MINOR_VERSION, FL_PATCH_VERSION);
#else
        fprintf(stderr, "%snone\n", gmsh_gui);
#endif
        fprintf(stderr, "%s\n", gmsh_license);
        fprintf(stderr, "%s\n", gmsh_os);
        fprintf(stderr, "%s%s\n", gmsh_options, Get_BuildOptions());
        fprintf(stderr, "%s\n", gmsh_date);
        fprintf(stderr, "%s\n", gmsh_host);
        fprintf(stderr, "%s\n", gmsh_packager);
        fprintf(stderr, "%s\n", gmsh_url);
        fprintf(stderr, "%s\n", gmsh_email);
        exit(1);
      }
      else if(!strcmp(argv[i] + 1, "help") || !strcmp(argv[i] + 1, "-help")) {
        fprintf(stderr, "%s\n", gmsh_progname);
        fprintf(stderr, "%s\n", gmsh_copyright);
        CTX.terminal = 1;
        Print_Usage(argv[0]);
        exit(1);
      }
      else if(!strcmp(argv[i] + 1, "v")) {
        i++;
        if(argv[i] != NULL)
          CTX.verbosity = atoi(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
#if defined(HAVE_FLTK)
      else if(!strcmp(argv[i] + 1, "term")) {
        CTX.terminal = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "dual")) {
        CTX.mesh.dual = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "noview")) {
        opt_view_visible(0, GMSH_SET, 0);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "link")) {
        i++;
        if(argv[i] != NULL)
          CTX.post.link = atoi(argv[i++]);
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "smoothview")) {
        CTX.post.smooth = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "combine")) {
        CTX.post.combine_time = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "nodb")) {
        CTX.db = 0;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "fontsize")) {
        i++;
        if(argv[i] != NULL) {
          CTX.fontsize = atoi(argv[i]);
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing number\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "theme") || !strcmp(argv[i] + 1, "scheme")) {
        i++;
        if(argv[i] != NULL) {
          CTX.gui_theme = argv[i];
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing argument\n");
          exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "display")) {
        i++;
        if(argv[i] != NULL) {
          CTX.display = argv[i];
          i++;
        }
        else {
          fprintf(stderr, ERROR_STR "Missing argument\n");
          exit(1);
        }
      }
#endif
#if defined(__APPLE__)
      else if(!strncmp(argv[i] + 1, "psn", 3)) {
        // The Mac Finder launches programs with a special command
        // line argument of the form -psn_XXX: just ignore it silently
        // (and don't exit!)
        i++;
      }
#endif
      else {
        fprintf(stderr, "Unknown option '%s'\n", argv[i]);
        CTX.terminal = 1;
        Print_Usage(argv[0]);
        exit(1);
      }

    }
    else {
      List_Add(CTX.files, &argv[i++]);
    }

  }

  if(!List_Nbr(CTX.files))
    strncpy(CTX.filename, CTX.default_filename_fullpath, 255);
  else
    strncpy(CTX.filename, *(char**)List_Pointer(CTX.files, 0), 255);
}
