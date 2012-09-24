// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <string.h>
#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#include "GmshMessage.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "CreateFile.h"
#include "OS.h"

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 1) && (FL_PATCH_VERSION > 6)
// OK
#elif (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
// also OK
#else
#error "Gmsh requires FLTK >= 1.1.7 or FLTK 1.3.x"
#endif
#endif

#if defined(HAVE_POST)
#include "PView.h"
#endif

int GetGmshMajorVersion(){ return GMSH_MAJOR_VERSION; }
int GetGmshMinorVersion(){ return GMSH_MINOR_VERSION; }
int GetGmshPatchVersion(){ return GMSH_PATCH_VERSION; }
const char *GetGmshExtraVersion(){ return GMSH_EXTRA_VERSION; }
const char *GetGmshVersion(){ return GMSH_VERSION; }
const char *GetGmshBuildDate(){ return GMSH_DATE; }
const char *GetGmshBuildHost(){ return GMSH_HOST; }
const char *GetGmshPackager(){ return GMSH_PACKAGER; }
const char *GetGmshBuildOS(){ return GMSH_OS; }
const char *GetGmshShortLicense(){ return GMSH_SHORT_LICENSE; }
const char *GetGmshBuildOptions(){ return GMSH_CONFIG_OPTIONS; }

void PrintUsage(const char *name)
{
  // If you make changes in this routine, please also change the texinfo
  // documentation (doc/texinfo/gmsh.texi) and the man page (doc/gmsh.1)
  Msg::Direct("Usage: %s [options] [files]", name);
  Msg::Direct("Geometry options:");
  Msg::Direct("  -0                    Output unrolled geometry, then exit");
  Msg::Direct("  -tol float            Set geometrical tolerance");
  Msg::Direct("  -match                Match geometries and meshes");
  Msg::Direct("Mesh options:");
  Msg::Direct("  -1, -2, -3            Perform 1D, 2D or 3D mesh generation, then exit");
  Msg::Direct("  -format string        Select output mesh format (auto (default), msh, msh1, msh2,");
  Msg::Direct("                          unv, vrml, ply2, stl, mesh, bdf, cgns, p3d, diff, med, ...)");
  Msg::Direct("  -refine               Perform uniform mesh refinement, then exit");
  Msg::Direct("  -part int             Partition after batch mesh generation");
  Msg::Direct("  -partWeight <tri|quad|tet|prism|hex> int");
  Msg::Direct("                          Weight of a triangle/quad/etc. during partitioning");
  Msg::Direct("  -renumber             Renumber the mesh elements after batch mesh generation");
  Msg::Direct("  -saveall              Save all elements (discard physical group definitions)");
  Msg::Direct("  -o file               Specify output file name");
  Msg::Direct("  -bin                  Use binary format when available");
  Msg::Direct("  -parametric           Save vertices with their parametric coordinates");
  Msg::Direct("  -numsubedges          Set the number of subdivisions when displaying high order elements");
  Msg::Direct("  -algo string          Select mesh algorithm (meshadapt, del2d, front2d, delquad, ");
  Msg::Direct("                          del3d, front3d, mmg3d)");
  Msg::Direct("  -smooth int           Set number of mesh smoothing steps");
  Msg::Direct("  -order int            Set mesh order (1, ..., 5)");
  Msg::Direct("  -hoOptimize           Optimize high order meshes");
  Msg::Direct("  -hoMindisto float     Minimum quality for high-order elements before optimization (0.0->1.0)");
  Msg::Direct("  -hoNLayers int        Number of high order element layers to optimize");
  Msg::Direct("  -hoElasticity float   Poisson ration for the elasticity analogy (-1.0 < nu < 0.5)");
  Msg::Direct("  -optimize[_netgen]    Optimize quality of tetrahedral elements");
  Msg::Direct("  -optimize_lloyd       Optimize 2D meshes using Lloyd algorithm");
  Msg::Direct("  -clscale float        Set global mesh element size scaling factor");
  Msg::Direct("  -clmin float          Set minimum mesh element size");
  Msg::Direct("  -clmax float          Set maximum mesh element size");
  Msg::Direct("  -anisoMax float       Set maximum anisotropy (only used in bamg for now)");
  Msg::Direct("  -smoothRatio float    Set smoothing ration between mesh sizes at nodes of a same edge");
  Msg::Direct("                          (only used in bamg)");
  Msg::Direct("  -clcurv               Automatically compute element sizes from curvatures");
  Msg::Direct("  -epslc1d              Set the accuracy of the evaluation of the LCFIELD for 1D mesh");
  Msg::Direct("  -swapangle            Set the threshold angle (in degree) between two adjacent faces");
  Msg::Direct("                          below which a swap is allowed");
  Msg::Direct("  -rand float           Set random perturbation factor");
  Msg::Direct("  -bgm file             Load background mesh from file");
  Msg::Direct("  -check                Perform various consistency checks on mesh");
  Msg::Direct("  -mpass int            Do several passes on the mesh for complex backround fields");
  Msg::Direct("  -ignorePartBound      Ignore partitions boundaries");
#if defined(HAVE_FLTK)
  Msg::Direct("Post-processing options:");
  Msg::Direct("  -link int             Select link mode between views (0, 1, 2, 3, 4)");
  Msg::Direct("  -combine              Combine views having identical names into multi-time-step views");
  Msg::Direct("Display options:");
  Msg::Direct("  -n                    Hide all meshes and post-processing views on startup");
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
  Msg::Direct("  -watch pattern        Pattern of files to merge as they become available");
  Msg::Direct("  -v int                Set verbosity level");
  Msg::Direct("  -nopopup              Don't popup dialog windows in scripts");
  Msg::Direct("  -string \"string\"      Parse option string at startup");
  Msg::Direct("  -option file          Parse option file at startup");
  Msg::Direct("  -convert files        Convert files into latest binary formats, then exit");
  Msg::Direct("  -version              Show version number");
  Msg::Direct("  -info                 Show detailed version information");
  Msg::Direct("  -help                 Show this message");
}

void GetOptions(int argc, char *argv[])
{
  // print messages on terminal
  int terminal = CTX::instance()->terminal;
  CTX::instance()->terminal = 1;

#if defined(HAVE_PARSER)
  if(argc && argv){
    // parse session and option file (if argc/argv is not provided skip this
    // step: this is usually what is expected when using Gmsh as a library)
    ParseFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName, true);
    ParseFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName, true);
  }
#endif

  // get command line options
  int i = 1;
  while(i < argc) {

    if(argv[i][0] == '-') {

      if(!strcmp(argv[i] + 1, "")) {
        CTX::instance()->batch = -99;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "onelab")) {
        i++;
        if(argv[i] && argv[i + 1] && argv[i + 1][0] != '-'){
          Msg::InitializeOnelab(argv[i], argv[i + 1]);
          i += 2;
        }
        else if(argv[i]){
          Msg::InitializeOnelab(argv[i], "");
          i += 1;
        }
        else
          Msg::Fatal("Missing client name and/or address of OneLab server");
      }
      else if(!strcmp(argv[i] + 1, "socket")) {
        i++;
        if(argv[i])
          Msg::InitializeOnelab("GmshRemote", argv[i++]);
        else
          Msg::Fatal("Missing string");
        CTX::instance()->batch = -3;
      }
      else if(!strcmp(argv[i] + 1, "check")) {
        CTX::instance()->batch = -2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "0")) {
        CTX::instance()->batch = -1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "1")) {
        CTX::instance()->batch = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "2")) {
        CTX::instance()->batch = 2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "3")) {
        CTX::instance()->batch = 3;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "4")) {
        CTX::instance()->batch = 4;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "refine")) {
        CTX::instance()->batch = 5;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "renumber")) {
        CTX::instance()->batchAfterMesh = 1;
        CTX::instance()->partitionOptions.renumber = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part")) {
        i++;
        if(argv[i]){
          CTX::instance()->batchAfterMesh = 1 ;
          opt_mesh_partition_num(0, GMSH_SET, atoi(argv[i++]));
        }
        else
          Msg::Fatal("Missing number");
      }
      else if (!strcmp(argv[i] + 1,"partWeight")) {
        i++;
        bool check = true;
        opt_mesh_partition_partitioner(0, GMSH_SET, 2); // Metis partitioner
        opt_mesh_partition_metis_algorithm(0, GMSH_SET, 3); // partGraphKWay w/ weights
        while (check) {
          if (argv[i]) {
            if (!strcmp(argv[i],"triangle")) {
              i++;
              opt_mesh_partition_tri_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i],"quad")) {
              i++;
              opt_mesh_partition_qua_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i],"tet")) {
              i++;
              opt_mesh_partition_tet_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i],"prism")) {
              i++;
              opt_mesh_partition_pri_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i],"pyramid")) {
              i++;
              opt_mesh_partition_pyr_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i],"hex")) {
              i++;
              opt_mesh_partition_hex_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else check = false;
            i++;
          }
          else check = false;
        }
      }
      else if(!strcmp(argv[i] + 1, "new")) {
        CTX::instance()->files.push_back("-new");
        i++;
      }
      else if(!strcmp(argv[i] + 1, "pid")) {
        fprintf(stdout, "%d\n", GetProcessId());
        fflush(stdout);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "a")) {
        CTX::instance()->initialContext = 0;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "g")) {
        CTX::instance()->initialContext = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "m")) {
        CTX::instance()->initialContext = 2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "s")) {
        CTX::instance()->initialContext = 3;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "p")) {
        CTX::instance()->initialContext = 4;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "saveall")) {
        CTX::instance()->mesh.saveAll = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "switch_tags")) {
        CTX::instance()->mesh.switchElementTags = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "optimize")) {
        CTX::instance()->mesh.optimize = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "bunin")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.bunin = atoi(argv[i++]);
        else
          Msg::Fatal("Missing cavity size in bunin optimization");
      }
      else if(!strcmp(argv[i] + 1, "optimize_netgen")) {
        CTX::instance()->mesh.optimizeNetgen = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "hoOptimize")) {
        i++;
        opt_mesh_smooth_internal_edges(0, GMSH_SET, 1);
      }
      else if(!strcmp(argv[i] + 1, "hoMindisto")) {
        i++;
        if(argv[i])
	  opt_mesh_ho_mindisto(0, GMSH_SET, atof(argv[i++]));
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "hoElasticity")) {
        i++;
        if(argv[i])
	  opt_mesh_ho_poisson(0, GMSH_SET, atof(argv[i++]));
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "hoNlayers")) {
        i++;
        if(argv[i])
	  opt_mesh_ho_nlayers(0, GMSH_SET, atoi(argv[i++]));
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "optimize_lloyd")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.optimizeLloyd = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number of lloyd iterations");
      }
      else if(!strcmp(argv[i] + 1, "nopopup")) {
        CTX::instance()->noPopup = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "watch")) {
        i++;
        if(argv[i]){
          std::string tmp = argv[i++];
          if(tmp.size() > 2 && tmp[0] == '"' && tmp[tmp.size() - 1] == '"')
            CTX::instance()->watchFilePattern = tmp.substr(1, tmp.size() - 2);
          else
            CTX::instance()->watchFilePattern = tmp;
        }
        else
          Msg::Fatal("Missing string");
      }
      else if(!strcmp(argv[i] + 1, "string")) {
        i++;
        if(argv[i])
          ParseString(argv[i++]);
        else
          Msg::Fatal("Missing string");
      }
      else if(!strcmp(argv[i] + 1, "option")) {
        i++;
        if(argv[i])
          ParseFile(argv[i++], true);
        else
          Msg::Fatal("Missing file name");
      }
      else if(!strcmp(argv[i] + 1, "o")) {
        i++;
        if(argv[i])
          CTX::instance()->outputFileName = argv[i++];
        else
          Msg::Fatal("Missing file name");
      }
      else if(!strcmp(argv[i] + 1, "anisoMax")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.anisoMax = atof(argv[i++]);
        else
          Msg::Fatal("Missing anisotropy ratio");
      }
      else if(!strcmp(argv[i] + 1, "smoothRatio")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.smoothRatio = atof(argv[i++]);
        else
          Msg::Fatal("Missing smooth ratio");
      }
      else if(!strcmp(argv[i] + 1, "bgm")) {
        i++;
        if(argv[i])
          CTX::instance()->bgmFileName = argv[i++];
        else
          Msg::Fatal("Missing file name");
      }
      else if(!strcmp(argv[i] + 1, "nw")) {
        i++;
        if(argv[i])
          CTX::instance()->numWindows = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "nt")) {
        i++;
        if(argv[i])
          CTX::instance()->numTiles = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "convert")) {
        i++;
        CTX::instance()->batch = 1;
        while(i < argc) {
          std::string fileName = std::string(argv[i]) + "_new";
#if defined(HAVE_POST)
          unsigned int n = PView::list.size();
#endif
          OpenProject(argv[i]);
#if defined(HAVE_POST)
          // convert post-processing views to latest binary format
          for(unsigned int j = n; j < PView::list.size(); j++)
            PView::list[j]->write(fileName, 1, (j == n) ? false : true);
#endif
          // convert mesh to latest binary format
          if(GModel::current()->getMeshStatus() > 0){
            CTX::instance()->mesh.mshFileVersion = 2.0;
            CTX::instance()->mesh.binary = 1;
            CreateOutputFile(fileName, FORMAT_MSH);
          }
          i++;
        }
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "tol")) {
        i++;
        if(argv[i])
          CTX::instance()->geom.tolerance = atof(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "match")) {
        i++;
        CTX::instance()->geom.matchGeomAndMesh = 1;
      }
      else if(!strcmp(argv[i] + 1, "scale")) {
        i++;
        if(argv[i])
          CTX::instance()->geom.scalingFactor = atof(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "meshscale")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.scalingFactor = atof(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "rand")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.randFactor = atof(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clscale")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcFactor = atof(argv[i++]);
          if(CTX::instance()->mesh.lcFactor <= 0.0)
            Msg::Fatal("Mesh element size factor must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clmin")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcMin = atof(argv[i++]);
          if(CTX::instance()->mesh.lcMin <= 0.0)
            Msg::Fatal("Minimum length size must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clmax")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcMax = atof(argv[i++]);
          if(CTX::instance()->mesh.lcMax <= 0.0)
            Msg::Fatal("Maximum length size must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "mpass")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.multiplePasses = atoi(argv[i++]);
          if(CTX::instance()->mesh.multiplePasses <= 0)
            Msg::Fatal("Number of Mesh Passes must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "ignorePartBound")) {
        i++;
        opt_mesh_ignore_part_bound(0, GMSH_SET, 1);
      }
      else if(!strcmp(argv[i] + 1, "edgelmin")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.toleranceEdgeLength = atof(argv[i++]);
          if(CTX::instance()->mesh.toleranceEdgeLength <= 0.0)
            Msg::Fatal("Tolerance for model edge length must be > 0 (here %g)",
                       CTX::instance()->mesh.toleranceEdgeLength);
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "epslc1d")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcIntegrationPrecision = atof(argv[i++]);
          if(CTX::instance()->mesh.lcIntegrationPrecision <= 0.0)
            Msg::Fatal("Integration accuracy must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "swapangle")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.allowSwapEdgeAngle = atof(argv[i++]);
          if(CTX::instance()->mesh.allowSwapEdgeAngle <= 0.0)
            Msg::Fatal("Threshold angle for edge swap must be > 0");
        }
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "clcurv")) {
        CTX::instance()->mesh.lcFromCurvature = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "clcurviso")) {
        CTX::instance()->mesh.lcFromCurvature = 2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "smooth")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.nbSmoothing = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "order") || !strcmp(argv[i] + 1, "degree")) {
        i++;
        if(argv[i])
          opt_mesh_order(0, GMSH_SET, atof(argv[i++]));
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "numsubedges")) {
        i++;
        if(argv[i])
          opt_mesh_num_sub_edges(0, GMSH_SET, atof(argv[i++]));
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "statreport")) {
        i++;
        CTX::instance()->createAppendMeshStatReport = 1;
        if(argv[i])
          CTX::instance()->meshStatReportFileName = argv[i++];
        else
          Msg::Fatal("Missing argument");
      }
      else if(!strcmp(argv[i] + 1, "append_statreport")) {
        i++;
        CTX::instance()->createAppendMeshStatReport = 2;
        if(argv[i])
          CTX::instance()->meshStatReportFileName = argv[i++];
        else
          Msg::Fatal("Missing argument");
      }
      else if(!strcmp(argv[i] + 1, "bin")) {
        i++;
        CTX::instance()->mesh.binary = 1;
      }
      else if(!strcmp(argv[i] + 1, "parametric")) {
        i++;
        CTX::instance()->mesh.saveParametric = 1;
      }
      else if(!strcmp(argv[i] + 1, "algo")) {
        i++;
        if(argv[i]) {
          if(!strncmp(argv[i], "auto", 4))
            CTX::instance()->mesh.algo2d = ALGO_2D_AUTO;
          else if(!strncmp(argv[i], "meshadapt", 9) || !strncmp(argv[i], "iso", 3))
            CTX::instance()->mesh.algo2d = ALGO_2D_MESHADAPT;
          else if(!strncmp(argv[i], "bds", 3))
            CTX::instance()->mesh.algo2d = ALGO_2D_MESHADAPT_OLD;
          else if(!strncmp(argv[i], "del2d", 5) || !strncmp(argv[i], "tri", 3))
            CTX::instance()->mesh.algo2d = ALGO_2D_DELAUNAY;
          else if(!strncmp(argv[i], "delquad", 5) || !strncmp(argv[i], "tri", 3))
            CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL_QUAD;
          else if(!strncmp(argv[i], "front2d", 7) || !strncmp(argv[i], "frontal", 7))
            CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
          else if(!strncmp(argv[i], "bamg",4))
            CTX::instance()->mesh.algo2d = ALGO_2D_BAMG;
          else if(!strncmp(argv[i], "del3d", 5) || !strncmp(argv[i], "tetgen", 6))
            CTX::instance()->mesh.algo3d = ALGO_3D_DELAUNAY;
          else if(!strncmp(argv[i], "front3d", 7) || !strncmp(argv[i], "netgen", 6))
            CTX::instance()->mesh.algo3d = ALGO_3D_FRONTAL;
          else if(!strncmp(argv[i], "mmg3d", 5))
            CTX::instance()->mesh.algo3d = ALGO_3D_MMG3D;
          else if(!strncmp(argv[i], "delfr3d", 7))
            CTX::instance()->mesh.algo3d = ALGO_3D_FRONTAL_DEL;
          else if(!strncmp(argv[i], "delhex3d", 8))
            CTX::instance()->mesh.algo3d = ALGO_3D_FRONTAL_HEX;
          else if(!strncmp(argv[i], "rtree3d", 9))
            CTX::instance()->mesh.algo3d = ALGO_3D_RTREE;
          else
            Msg::Fatal("Unknown mesh algorithm");
          i++;
        }
        else
          Msg::Fatal("Missing algorithm");
      }
      else if(!strcmp(argv[i] + 1, "format") || !strcmp(argv[i] + 1, "f")) {
        i++;
        if(argv[i]) {
          if(!strcmp(argv[i], "auto")){
            CTX::instance()->mesh.fileFormat = FORMAT_AUTO;
          }
          else if(!strcmp(argv[i], "msh1")){
            CTX::instance()->mesh.fileFormat = FORMAT_MSH;
            CTX::instance()->mesh.mshFileVersion = 1.0;
          }
          else if(!strcmp(argv[i], "msh2")){
            CTX::instance()->mesh.fileFormat = FORMAT_MSH;
            CTX::instance()->mesh.mshFileVersion = 2.0;
          }
          else{
            int format = GetFileFormatFromExtension(std::string(".") + argv[i]);
            if(format < 0){
              Msg::Error("Unknown mesh format `%s', using `msh' instead", argv[i]);
              format = FORMAT_MSH;
            }
            CTX::instance()->mesh.fileFormat = format;
          }
          i++;
        }
        else
          Msg::Fatal("Missing format");
      }
      else if(!strcmp(argv[i] + 1, "listen")) {
        CTX::instance()->solver.listen = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "version") || !strcmp(argv[i] + 1, "-version")) {
        fprintf(stderr, "%s\n", GMSH_VERSION);
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "info") || !strcmp(argv[i] + 1, "-info")) {
        fprintf(stderr, "Version        : %s\n", GMSH_VERSION);
#if defined(HAVE_FLTK)
        fprintf(stderr, "GUI toolkit    : FLTK %d.%d.%d\n", FL_MAJOR_VERSION,
                FL_MINOR_VERSION, FL_PATCH_VERSION);
#else
        fprintf(stderr, "GUI toolkit    : none\n");
#endif
        fprintf(stderr, "License        : %s\n", GMSH_SHORT_LICENSE);
        fprintf(stderr, "Build OS       : %s\n", GMSH_OS);
        fprintf(stderr, "Build options  :%s\n", GMSH_CONFIG_OPTIONS);
        fprintf(stderr, "Build date     : %s\n", GMSH_DATE);
        fprintf(stderr, "Build host     : %s\n", GMSH_HOST);
        fprintf(stderr, "Packager       : %s\n", GMSH_PACKAGER);
        fprintf(stderr, "Web site       : http://www.geuz.org/gmsh/\n");
        fprintf(stderr, "Mailing list   : gmsh@geuz.org\n");
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "help") || !strcmp(argv[i] + 1, "-help")) {
        fprintf(stderr, "Gmsh, a 3D mesh generator with pre- and post-processing facilities\n");
        fprintf(stderr, "Copyright (C) 1997-2012 Christophe Geuzaine and Jean-Francois Remacle\n");
        PrintUsage(argv[0]);
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "v") || !strcmp(argv[i] + 1, "verbose")) {
        i++;
        if(argv[i])
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
        CTX::instance()->mesh.dual = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "voronoi")) {
        CTX::instance()->mesh.voronoi = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "noview")) {
        opt_view_visible(0, GMSH_SET, 0);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "nomesh")) {
        opt_mesh_points(0, GMSH_SET, 0.);
        opt_mesh_lines(0, GMSH_SET, 0.);
        opt_mesh_surfaces_edges(0, GMSH_SET, 0.);
        opt_mesh_surfaces_faces(0, GMSH_SET, 0.);
        opt_mesh_volumes_edges(0, GMSH_SET, 0.);
        opt_mesh_volumes_faces(0, GMSH_SET, 0.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "n")) {
        opt_view_visible(0, GMSH_SET, 0);
        opt_mesh_points(0, GMSH_SET, 0.);
        opt_mesh_lines(0, GMSH_SET, 0.);
        opt_mesh_surfaces_edges(0, GMSH_SET, 0.);
        opt_mesh_surfaces_faces(0, GMSH_SET, 0.);
        opt_mesh_volumes_edges(0, GMSH_SET, 0.);
        opt_mesh_volumes_faces(0, GMSH_SET, 0.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "link")) {
        i++;
        if(argv[i])
          CTX::instance()->post.link = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "smoothview")) {
        CTX::instance()->post.smooth = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "combine")) {
        CTX::instance()->post.combineTime = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "nodb")) {
        CTX::instance()->db = 0;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "fontsize")) {
        i++;
        if(argv[i])
          CTX::instance()->fontSize = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "deltafontsize")) {
        i++;
        if(argv[i])
          CTX::instance()->deltaFontSize = atoi(argv[i++]);
        else
          Msg::Fatal("Missing number");
      }
      else if(!strcmp(argv[i] + 1, "theme") || !strcmp(argv[i] + 1, "scheme")) {
        i++;
        if(argv[i])
          CTX::instance()->guiTheme = argv[i++];
        else
          Msg::Fatal("Missing argument");
      }
      else if(!strcmp(argv[i] + 1, "display")) {
        i++;
        if(argv[i])
          CTX::instance()->display = argv[i++];
        else
          Msg::Fatal("Missing argument");
      }
      else if(!strcmp(argv[i] + 1, "showCompounds")) {
        CTX::instance()->geom.hideCompounds = 0;
        i++;
      }
#endif
#if defined(__APPLE__)
      else if(!strncmp(argv[i] + 1, "psn", 3)) {
        // the Mac Finder launches programs with a special command line argument
        // of the form -psn_XXX: just ignore it silently (and don't exit!)
        i++;
      }
#endif
      else {
        Msg::Error("Unknown option '%s'", argv[i]);
        PrintUsage(argv[0]);
        Msg::Exit(1);
      }

    }
    else {
      CTX::instance()->files.push_back(argv[i++]);
    }

  }

  if(CTX::instance()->files.empty()){
    std::string base = (getenv("PWD") ? "" : CTX::instance()->homeDir);
    GModel::current()->setFileName(base + CTX::instance()->defaultFileName);
  }
  else
    GModel::current()->setFileName(CTX::instance()->files[0]);

  CTX::instance()->terminal = terminal;
}
