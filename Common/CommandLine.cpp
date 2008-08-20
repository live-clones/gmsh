// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdlib.h>
#include "GmshUI.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#include "Message.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "CreateFile.h"
#include "OS.h"

#if !defined(HAVE_NO_POST)
#include "PView.h"
#endif

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
  Msg::Direct("Usage: %s [options] [files]", name);
  Msg::Direct("Geometry options:");
  Msg::Direct("  -0                    Output unrolled geometry, then exit");
  Msg::Direct("  -tol float            Set geometrical tolerance");
  Msg::Direct("Mesh options:");
  Msg::Direct("  -1, -2, -3            Perform 1D, 2D or 3D mesh generation, then exit");
  Msg::Direct("  -part                 Partition after batch mesh generation");
  Msg::Direct("  -saveall              Save all elements (discard physical group definitions)");
  Msg::Direct("  -o file               Specify mesh output file name");
  Msg::Direct("  -format string        Set output mesh format (msh, msh1, msh2, unv, vrml, stl, mesh,");
  Msg::Direct("                          bdf, p3d, cgns, med)");
  Msg::Direct("  -bin                  Use binary format when available");  
  Msg::Direct("  -algo string          Select mesh algorithm (de, del2d, frontal, iso, netgen, tetgen)");
  Msg::Direct("  -smooth int           Set number of mesh smoothing steps");
  Msg::Direct("  -optimize[_netgen]    Optimize quality of tetrahedral elements");
  Msg::Direct("  -order int            Set mesh order (1, ..., 5)");
  Msg::Direct("  -optimize_hom         Optimize higher order meshes (in 2D)");
  Msg::Direct("  -clscale float        Set characteristic length scaling factor");
  Msg::Direct("  -clmin float          Set minimum characteristic length");
  Msg::Direct("  -clmax float          Set maximum characteristic length");
  Msg::Direct("  -clcurv               Compute characteristic lengths from curvatures");
  Msg::Direct("  -epslc1d              Set the accuracy of the evaluation of the LCFIELD for 1D mesh");
  Msg::Direct("  -swapangle            Set the treshold angle (in degree) between two adjacent faces");
  Msg::Direct("                          below which a swap is allowed");
  Msg::Direct("  -rand float           Set random perturbation factor");
  Msg::Direct("  -bgm file             Load background mesh from file");
#if defined(HAVE_FLTK)
  Msg::Direct("Post-processing options:");
  Msg::Direct("  -noview               Hide all views on startup");
  Msg::Direct("  -link int             Select link mode between views (0, 1, 2, 3, 4)");
  Msg::Direct("  -combine              Combine views having identical names into multi-time-step views");
  Msg::Direct("Display options:");    
  Msg::Direct("  -nodb                 Disable double buffering");
  Msg::Direct("  -fontsize int         Specify the font size for the GUI");
  Msg::Direct("  -theme string         Specify FLTK GUI theme");
  Msg::Direct("  -display string       Specify display");
#endif
  Msg::Direct("Other options:");      
  Msg::Direct("  -                     Parse input files, then exit");
#if defined(HAVE_FLTK)
  Msg::Direct("  -a, -g, -m, -s, -p    Start in automatic, geometry, mesh, solver or post-processing mode");
#endif
  Msg::Direct("  -pid                  Print process id on stdout");
  Msg::Direct("  -listen               Always listen to incoming connection requests");
  Msg::Direct("  -v int                Set verbosity level");
  Msg::Direct("  -nopopup              Don't popup dialog windows in scripts");
  Msg::Direct("  -string \"string\"      Parse option string at startup");
  Msg::Direct("  -option file          Parse option file at startup");
  Msg::Direct("  -convert files        Convert files into latest binary formats, then exit");
  Msg::Direct("  -version              Show version number");
  Msg::Direct("  -info                 Show detailed version information");
  Msg::Direct("  -help                 Show this message");
}

char *Get_BuildOptions(void)
{
  static int first = 1;
  static char opt[256] = "";
  
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
#if defined(HAVE_CHACO)
    strcat(opt, "CHACO ");
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
  // print messages on terminal
  int terminal = CTX.terminal;
  CTX.terminal = 1;

  // Create a dummy model during option processing so we cannot crash
  // the parser, and so we can load files for -convert
  GModel *dummy = new GModel();

#if !defined(HAVE_NO_PARSER)
  // Parse session and option files
  ParseFile(CTX.session_filename_fullpath, 1);
  ParseFile(CTX.options_filename_fullpath, 1);
#endif

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
      else if(!strcmp(argv[i] + 1, "part")) {
        CTX.batchAfterMesh = 1;
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
        else
	  Msg::Fatal("Missing string");
      }
      else if(!strcmp(argv[i] + 1, "option")) {
        i++;
        if(argv[i] != NULL)
          ParseFile(argv[i++], 1);
        else
	  Msg::Fatal("Missing file name");
      }
      else if(!strcmp(argv[i] + 1, "o")) {
        i++;
        if(argv[i] != NULL)
          CTX.output_filename = argv[i++];
        else
	  Msg::Fatal("Missing file name");
      }
      else if(!strcmp(argv[i] + 1, "bgm")) {
        i++;
        if(argv[i] != NULL)
	  CTX.bgm_filename = argv[i++];
	else
	  Msg::Fatal("Missing file name");
      }
      else if(!strcmp(argv[i] + 1, "convert")) {
        i++;
        CTX.batch = 1;
        while(i < argc) {
          char filename[256];
          sprintf(filename, "%s_new", argv[i]);
#if !defined(HAVE_NO_POST)
          unsigned int n = PView::list.size();
#endif
          OpenProject(argv[i]);
#if !defined(HAVE_NO_POST)
          // convert post-processing views to latest binary format
          for(unsigned int j = n; j < PView::list.size(); j++)
            PView::list[j]->write(filename, 1, (j == n) ? false : true);
#endif
          // convert mesh to latest binary format
          if(GModel::current()->getMeshStatus() > 0){
            CTX.mesh.msh_file_version = 2.0;
            CTX.mesh.msh_binary = 1;
            CreateOutputFile(filename, FORMAT_MSH);
          }
          i++;
        }
	Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "tol")) {
        i++;
        if(argv[i] != NULL)
          CTX.geom.tolerance = atof(argv[i++]);
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "scale")) {
        i++;
        if(argv[i] != NULL)
          CTX.geom.scaling_factor = atof(argv[i++]);
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "meshscale")) {
        i++;
        if(argv[i] != NULL)
          CTX.mesh.scaling_factor = atof(argv[i++]);
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "rand")) {
        i++;
        if(argv[i] != NULL)
          CTX.mesh.rand_factor = atof(argv[i++]);
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clscale")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_factor = atof(argv[i++]);
          if(CTX.mesh.lc_factor <= 0.0)
	    Msg::Fatal("Characteristic length factor must be > 0");
        }
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clmin")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_min = atof(argv[i++]);
          if(CTX.mesh.lc_min <= 0.0)
	    Msg::Fatal("Minimum length size must be > 0");
        }
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clmax")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_max = atof(argv[i++]);
          if(CTX.mesh.lc_max <= 0.0)
	    Msg::Fatal("Maximum length size must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "edgelmin")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.tolerance_edge_length = atof(argv[i++]);
          if( CTX.mesh.tolerance_edge_length <= 0.0)
	    Msg::Fatal("Tolerance for model edge length must be > 0 (here %g)", CTX.mesh.tolerance_edge_length);
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "epslc1d")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.lc_integration_precision = atof(argv[i++]);
          if(CTX.mesh.lc_integration_precision <= 0.0)
	    Msg::Fatal("Integration accuracy must be > 0");
        }
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "swapangle")) {
        i++;
        if(argv[i] != NULL) {
          CTX.mesh.allow_swap_edge_angle = atof(argv[i++]);
          if(CTX.mesh.allow_swap_edge_angle <= 0.0)
	    Msg::Fatal("Treshold angle for edge swap must be > 0");
        }
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clcurv")) {
        CTX.mesh.lc_from_curvature = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "smooth")) {
        i++;
        if(argv[i] != NULL)
          CTX.mesh.nb_smoothing = atoi(argv[i++]);
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "order") || !strcmp(argv[i] + 1, "degree")) {
        i++;
        if(argv[i] != NULL)
          opt_mesh_order(0, GMSH_SET, atof(argv[i++]));
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "c1")) {
        i++;
        opt_mesh_c1(0, GMSH_SET, 1);
      }
      else if(!strcmp(argv[i] + 1, "statreport")) {
        i++;
        CTX.create_append_statreport = 1;
        if(argv[i] != NULL)
          strcpy(CTX.statreport, argv[i++]);
        else
	  Msg::Fatal("Missing argument");
      }
      else if(!strcmp(argv[i] + 1, "append_statreport")) {
        i++;
        CTX.create_append_statreport = 2;
        if(argv[i] != NULL)
          strcpy(CTX.statreport, argv[i++]);
        else
	  Msg::Fatal("Missing argument");
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
          else
	    Msg::Fatal("Unknown mesh format");
          i++;
        }
        else
	  Msg::Fatal("Missing format");
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
          else if(!strncmp(argv[i], "frontal", 7))
            CTX.mesh.algo2d = ALGO_2D_FRONTAL;
          else if(!strncmp(argv[i], "del2d", 5) || !strncmp(argv[i], "tri", 3))
            CTX.mesh.algo2d = ALGO_2D_DELAUNAY;
          else if(!strncmp(argv[i], "bds", 3))
            CTX.mesh.algo2d = ALGO_2D_MESHADAPT;
          else if(!strncmp(argv[i], "del", 3) || !strncmp(argv[i], "iso", 3))
            CTX.mesh.algo2d = ALGO_2D_MESHADAPT_DELAUNAY;
          else
	    Msg::Fatal("Unknown mesh algorithm");
          i++;
        }
        else
	  Msg::Fatal("Missing algorithm");
      }
      else if(!strcmp(argv[i] + 1, "listen")) {
        CTX.solver.listen = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "version") || !strcmp(argv[i] + 1, "-version")) {
        fprintf(stderr, "%s\n", GMSH_VERSION);
	Msg::Exit(0);
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
	Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "help") || !strcmp(argv[i] + 1, "-help")) {
        fprintf(stderr, "%s\n", gmsh_progname);
        fprintf(stderr, "%s\n", gmsh_copyright);
        Print_Usage(argv[0]);
	Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "v")) {
        i++;
        if(argv[i] != NULL)
	  Msg::SetVerbosity(atoi(argv[i++]));
        else
	  Msg::Fatal("Missing number");
      }
#if defined(HAVE_FLTK)
      else if(!strcmp(argv[i] + 1, "term")) {
        terminal = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "dual")) {
        CTX.mesh.dual = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "voronoi")) {
        CTX.mesh.voronoi = 1;
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
        else
	  Msg::Fatal("Missing number");
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
        if(argv[i] != NULL)
          CTX.fontsize = atoi(argv[i++]);
        else
	  Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "theme") || !strcmp(argv[i] + 1, "scheme")) {
        i++;
        if(argv[i] != NULL)
          CTX.gui_theme = argv[i++];
        else
	  Msg::Fatal("Missing argument");
      }
      else if(!strcmp(argv[i] + 1, "display")) {
        i++;
        if(argv[i] != NULL)
          CTX.display = argv[i++];
        else
	  Msg::Fatal("Missing argument");
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
	Msg::Error("Unknown option '%s'", argv[i]);
        Print_Usage(argv[0]);
	Msg::Exit(1);
      }

    }
    else {
      CTX.files.push_back(argv[i++]);
    }

  }

  if(CTX.files.empty())
    strncpy(CTX.filename, CTX.default_filename_fullpath, 255);
  else
    strncpy(CTX.filename, CTX.files[0].c_str(), 255);

  delete dummy;

  CTX.terminal = terminal;
}
