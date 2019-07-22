// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
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
#include "GmshGlobal.h"
#include "StringUtils.h"

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 3)
// OK
#else
#error "Gmsh requires FLTK >= 1.3"
#endif
#endif

#if defined(HAVE_PETSC)
#include "petsc.h"
#endif

#if defined(HAVE_OCC)
#include "Standard_Version.hxx"
#endif

#if defined(HAVE_MED)
#include <med.h>
#endif

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_PARSER)
#include "Parser.h"
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

std::vector<std::pair<std::string, std::string> > GetUsage()
{
  typedef std::pair<std::string, std::string> mp;
  std::vector<mp> s;
  s.push_back(mp("Geometry options:", ""));
  s.push_back(mp("-0", "Output model, then exit"));
  s.push_back(mp("-tol float", "Set geometrical tolerance"));
  s.push_back(mp("-match", "Match geometries and meshes"));
  s.push_back(mp("Mesh options:", ""));
  s.push_back(mp("-1, -2, -3", "Perform 1D, 2D or 3D mesh generation, then exit"));
  s.push_back(mp("-save", "Save mesh, then exit"));
  s.push_back(mp("-o file", "Specify output file name"));
  s.push_back(mp("-format string", "Select output mesh format (" +
                 GetKnownFileFormats(true) + ")"));
  s.push_back(mp("-bin", "Create binary files when possible"));
  s.push_back(mp("-refine", "Perform uniform mesh refinement, then exit"));
  s.push_back(mp("-barycentric_refine", "Perform barycentric mesh refinement, then exit"));
  s.push_back(mp("-reclassify angle", "Reclassify surface mesh, then exit"));
  s.push_back(mp("-reparam angle", "Reparametrize surface mesh, then exit"));
  s.push_back(mp("-part int", "Partition after batch mesh generation"));
  s.push_back(mp("-part_weight tri|quad|tet|hex|pri|pyr|trih int",
                 "Weight of a triangle/quad/etc. during partitioning"));
  s.push_back(mp("-part_split", "Save mesh partitions in separate files"));
  s.push_back(mp("-part_[no_]topo", "Create the partition topology"));
  s.push_back(mp("-part_[no_]ghosts", "Create ghost cells"));
  s.push_back(mp("-part_[no_]physicals", "Create physical groups for partitions"));
  s.push_back(mp("-part_topo_pro", "Save the partition topology .pro file"));
  s.push_back(mp("-preserve_numbering_msh2", "Preserve element numbering in MSH2 format"));
  s.push_back(mp("-save_all", "Save all elements (discard physical group definitions)"));
  s.push_back(mp("-save_parametric", "Save nodes with their parametric coordinates"));
  s.push_back(mp("-save_topology", "Save model topology"));
  s.push_back(mp("-algo string", "Select mesh algorithm (meshadapt, del2d, front2d, "
                 "delquad, del3d, front3d, mmg3d, pack, hxt)"));
  s.push_back(mp("-smooth int", "Set number of mesh smoothing steps"));
  s.push_back(mp("-order int", "Set mesh order (1, ..., 5)"));
  s.push_back(mp("-optimize[_netgen]", "Optimize quality of tetrahedral elements"));
  s.push_back(mp("-optimize_threshold", "Optimize tetrahedral elements that have a "
                 "quality less than a threshold"));
  s.push_back(mp("-optimize_ho", "Optimize high order meshes"));
  s.push_back(mp("-ho_[min,max,nlayers]", "High-order optimization parameters"));
  s.push_back(mp("-clscale float", "Set global mesh element size scaling factor"));
  s.push_back(mp("-clmin float", "Set minimum mesh element size"));
  s.push_back(mp("-clmax float", "Set maximum mesh element size"));
  s.push_back(mp("-aniso_max float", "Set maximum anisotropy (for bamg)"));
  s.push_back(mp("-smooth_ratio float", "Set smoothing ration between mesh sizes at "
                 "nodes of a same edge (for bamg)"));
  s.push_back(mp("-clcurv", "Automatically compute element sizes from curvatures"));
  s.push_back(mp("-epslc1d", "Set accuracy of evaluation of mesh size field for 1D mesh"));
  s.push_back(mp("-swapangle", "Set the threshold angle (in degree) between two adjacent "
                 "faces below which a swap is allowed"));
  s.push_back(mp("-rand float", "Set random perturbation factor"));
  s.push_back(mp("-bgm file", "Load background mesh from file"));
  s.push_back(mp("-check", "Perform various consistency checks on mesh"));
  s.push_back(mp("-ignore_periocity", "Ignore periodic boundaries"));
#if defined(HAVE_FLTK)
  s.push_back(mp("Post-processing options:", ""));
  s.push_back(mp("-link int", "Select link mode between views (0, 1, 2, 3, 4)"));
  s.push_back(mp("-combine", "Combine views having identical names into multi-time-step "
                 "views"));
  s.push_back(mp("Solver options:", ""));
  s.push_back(mp("-listen", "Always listen to incoming connection requests"));
  s.push_back(mp("-minterpreter string", "Name of Octave interpreter"));
  s.push_back(mp("-pyinterpreter string", "Name of Python interpreter"));
  s.push_back(mp("-run", "Run ONELAB solver(s)"));
  s.push_back(mp("Display options:", ""));
  s.push_back(mp("-n", "Hide all meshes and post-processing views on startup"));
  s.push_back(mp("-nodb", "Disable double buffering"));
  s.push_back(mp("-numsubedges", "Set num of subdivisions for high order element display"));
  s.push_back(mp("-fontsize int", "Specify the font size for the GUI"));
  s.push_back(mp("-theme string", "Specify FLTK GUI theme"));
  s.push_back(mp("-display string", "Specify display"));
  s.push_back(mp("-camera", "Use camera mode view;"));
  s.push_back(mp("-stereo","OpenGL quad-buffered stereo rendering (requires special "
                 "graphics card)"));
  s.push_back(mp("-gamepad", "Use gamepad controller if available"));
#endif
  s.push_back(mp("Other options:", ""));
  s.push_back(mp("-, -parse_and_exit", "Parse input files, then exit"));
  s.push_back(mp("-new", "Create new model before merge next file"));
  s.push_back(mp("-merge", "Merge next files"));
  s.push_back(mp("-open", "Open next files"));
  s.push_back(mp("-log filename", "Log all messages to filename"));
#if defined(HAVE_FLTK)
  s.push_back(mp("-a, -g, -m, -s, -p", "Start in automatic, geometry, mesh, solver or "
                 "post-processing mode"));
#endif
  s.push_back(mp("-pid", "Print process id on stdout"));
  s.push_back(mp("-watch pattern", "Pattern of files to merge as they become available"));
  s.push_back(mp("-bg file", "Load background (image or PDF) file"));
  s.push_back(mp("-v int", "Set verbosity level"));
  s.push_back(mp("-nopopup", "Don't popup dialog windows in scripts"));
  s.push_back(mp("-string \"string\"", "Parse command string at startup"));
  s.push_back(mp("-setnumber name value", "Set constant or option number name=value"));
  s.push_back(mp("-setstring name value", "Set constant or option string name=value"));
  s.push_back(mp("-option file", "Parse option file at startup"));
  s.push_back(mp("-convert files", "Convert files into latest binary formats, then exit"));
  s.push_back(mp("-nt int", "Set number of threads"));
  s.push_back(mp("-cpu", "Report CPU times for all operations"));
  s.push_back(mp("-version", "Show version number"));
  s.push_back(mp("-info", "Show detailed version information"));
  s.push_back(mp("-help", "Show command line usage"));
  s.push_back(mp("-help_options", "Show all options"));
  return s;
}

std::vector<std::pair<std::string, std::string> > GetShortcutsUsage(const std::string &ctrl)
{
  std::string cc = ctrl;
#if defined(__APPLE__)
  if(cc.empty()) cc = "Cmd+";
#else
  if(cc.empty()) cc = "Ctrl+";
#endif
  typedef std::pair<std::string, std::string> mp;
  std::vector<mp> s;
  s.push_back(mp("Left arrow", "Go to previous time step"));
  s.push_back(mp("Right arrow", "Go to next time step"));
  s.push_back(mp("Up arrow", "Make previous view visible"));
  s.push_back(mp("Down arrow", "Make next view visible"));
  s.push_back(mp("0", "Reload geometry"));
  s.push_back(mp(cc + "0", "Reload full project"));
  s.push_back(mp("1 or F1", "Mesh lines"));
  s.push_back(mp("2 or F2", "Mesh surfaces"));
  s.push_back(mp("3 or F3", "Mesh volumes"));
  s.push_back(mp("Escape", "Cancel lasso zoom/selection, toggle mouse selection ON/OFF"));
  s.push_back(mp("e", "End/accept selection in geometry creation mode"));
  s.push_back(mp("g", "Go to geometry module"));
  s.push_back(mp("m", "Go to mesh module"));
  s.push_back(mp("p", "Go to post-processing module"));
  s.push_back(mp("q", "Abort selection in geometry creation mode"));
  s.push_back(mp("s", "Go to solver module"));
  s.push_back(mp("x", "Toogle x coordinate freeze in geometry creation mode"));
  s.push_back(mp("y", "Toogle y coordinate freeze in geometry creation mode"));
  s.push_back(mp("z", "Toogle z coordinate freeze in geometry creation mode"));
  s.push_back(mp("Shift+a", "Bring all windows to front"));
  s.push_back(mp("Shift+g", "Show geometry options"));
  s.push_back(mp("Shift+m", "Show mesh options"));
  s.push_back(mp("Shift+o", "Show general options"));
  s.push_back(mp("Shift+p", "Show post-processing options"));
  s.push_back(mp("Shift+s", "Show solver options"));
  s.push_back(mp("Shift+u", "Show post-processing view plugins"));
  s.push_back(mp("Shift+w", "Show post-processing view options"));
  s.push_back(mp("Shift+x", "Move only along x coordinate in geometry creation mode"));
  s.push_back(mp("Shift+y", "Move only along y coordinate in geometry creation mode"));
  s.push_back(mp("Shift+z", "Move only along z coordinate in geometry creation mode"));
  s.push_back(mp("Shift+Escape", "Enable full mouse selection"));
  s.push_back(mp(cc + "d", "Attach/detach menu"));
  s.push_back(mp(cc + "e", "Export project"));
  s.push_back(mp(cc + "f", "Enter full screen"));
  s.push_back(mp(cc + "i", "Show statistics window"));
  s.push_back(mp(cc + "j", "Save model options"));
  s.push_back(mp(cc + "l", "Show message console"));
#if defined(__APPLE__)
  s.push_back(mp(cc + "m", "Minimize window"));
#endif
  s.push_back(mp(cc + "n", "Create new project file"));
  s.push_back(mp(cc + "o", "Open project file"));
  s.push_back(mp(cc + "q", "Quit"));
  s.push_back(mp(cc + "r", "Rename project file"));
  s.push_back(mp(cc + "s", "Save mesh in default format"));
  s.push_back(mp("Shift+" + cc + "c", "Show clipping plane window"));
  s.push_back(mp("Shift+" + cc + "h", "Show current options and workspace window"));
  s.push_back(mp("Shift+" + cc + "j", "Save options as default"));
  s.push_back(mp("Shift+" + cc + "m", "Show manipulator window"));
  s.push_back(mp("Shift+" + cc + "n", "Show option window"));
  s.push_back(mp("Shift+" + cc + "o", "Merge file(s)"));
  s.push_back(mp("Shift+" + cc + "u", "Show plugin window"));
  s.push_back(mp("Shift+" + cc + "v", "Show visibility window"));
  s.push_back(mp("Alt+a", "Loop through axes modes"));
  s.push_back(mp("Alt+b", "Hide/show bounding boxes"));
  s.push_back(mp("Alt+c", "Loop through predefined color schemes"));
  s.push_back(mp("Alt+e", "Hide/Show element outlines for visible post-pro views"));
  s.push_back(mp("Alt+f", "Change redraw mode (fast/full)"));
  s.push_back(mp("Alt+h", "Hide/show all post-processing views"));
  s.push_back(mp("Alt+i", "Hide/show all post-processing view scales"));
  s.push_back(mp("Alt+l", "Hide/show geometry lines"));
  s.push_back(mp("Alt+m", "Toggle visibility of all mesh entities"));
  s.push_back(mp("Alt+n", "Hide/show all post-processing view annotations"));
  s.push_back(mp("Alt+o", "Change projection mode (orthographic/perspective)"));
  s.push_back(mp("Alt+p", "Hide/show geometry points"));
  s.push_back(mp("Alt+r", "Loop through range modes for visible post-pro views"));
  s.push_back(mp("Alt+s", "Hide/show geometry surfaces"));
  s.push_back(mp("Alt+t", "Loop through interval modes for visible post-pro views"));
  s.push_back(mp("Alt+v", "Hide/show geometry volumes"));
  s.push_back(mp("Alt+w", "Enable/disable all lighting"));
  s.push_back(mp("Alt+x", "Set X view"));
  s.push_back(mp("Alt+y", "Set Y view"));
  s.push_back(mp("Alt+z", "Set Z view"));
  s.push_back(mp("Alt+Shift+a", "Hide/show small axes"));
  s.push_back(mp("Alt+Shift+b", "Hide/show mesh volume faces"));
  s.push_back(mp("Alt+Shift+c", "Loop through predefined colormaps"));
  s.push_back(mp("Alt+Shift+d", "Hide/show mesh surface faces"));
  s.push_back(mp("Alt+Shift+l", "Hide/show mesh lines"));
  s.push_back(mp("Alt+Shift+p", "Hide/show mesh points"));
  s.push_back(mp("Alt+Shift+s", "Hide/show mesh surface edges"));
  s.push_back(mp("Alt+Shift+t", "Same as Alt+t, but with numeric mode included"));
  s.push_back(mp("Alt+Shift+v", "Hide/show mesh volume edges"));
  s.push_back(mp("Alt+Shift+x", "Set -X view"));
  s.push_back(mp("Alt+Shift+y", "Set -Y view"));
  s.push_back(mp("Alt+Shift+z", "Set -Z view"));
  return s;
}

std::vector<std::pair<std::string, std::string> > GetMouseUsage()
{
  typedef std::pair<std::string, std::string> mp;
  std::vector<mp> s;
  s.push_back(mp("Move", "- Highlight the entity under the mouse pointer and "
                 "display its properties"));
  s.push_back(mp("", "- Resize a lasso zoom or a lasso (un)selection"));
  s.push_back(mp("Left button", "- Rotate"));
  s.push_back(mp("", "- Select an entity"));
  s.push_back(mp("", "- Accept a lasso zoom or a lasso selection"));
  s.push_back(mp("Ctrl+Left button", "Start a lasso zoom or a lasso (un)selection"));
  s.push_back(mp("Middle button", "- Zoom"));
  s.push_back(mp("", "- Unselect an entity"));
  s.push_back(mp("", "- Accept a lasso zoom or a lasso unselection"));
  s.push_back(mp("Ctrl+Middle button", "Orthogonalize display"));
  s.push_back(mp("Right button", "- Pan"));
  s.push_back(mp("", "- Cancel a lasso zoom or a lasso (un)selection"));
  s.push_back(mp("", "- Pop-up menu on post-processing view button"));
  s.push_back(mp("Ctrl+Right button", "Reset to default viewpoint"));
  return s;
}

void PrintUsage(const std::string &name)
{
  Msg::Direct("Usage: %s [options] [files]", name.c_str());
  std::vector<std::pair<std::string, std::string> > s = GetUsage();
  for(std::size_t i = 0; i < s.size(); i++){
    std::string a = s[i].first, b = s[i].second;
    if(b.empty()){
      Msg::Direct("%s", a.c_str());
    }
    else{
      if(a.size() < 20) a.resize(20, ' ');
      Msg::Direct("  %s %s", a.c_str(), b.c_str());
    }
  }
}

void PrintInfo()
{
  Msg::Direct("Version       : %s", GMSH_VERSION);
  Msg::Direct("License       : %s", GMSH_SHORT_LICENSE);
  Msg::Direct("Build OS      : %s", GMSH_OS);
  Msg::Direct("Build date    : %s", GMSH_DATE);
  Msg::Direct("Build host    : %s", GMSH_HOST);
  Msg::Direct("Build options :%s", GMSH_CONFIG_OPTIONS);
#if defined(HAVE_FLTK)
  Msg::Direct("FLTK version  : %d.%d.%d", FL_MAJOR_VERSION,
              FL_MINOR_VERSION, FL_PATCH_VERSION);
#endif
#if defined(HAVE_PETSC)
  Msg::Direct("PETSc version : %d.%d.%d (%s arithmtic)", PETSC_VERSION_MAJOR,
              PETSC_VERSION_MINOR, PETSC_VERSION_SUBMINOR,
#if defined(PETSC_USE_COMPLEX)
              "complex"
#else
              "real"
#endif
              );
#endif
#if defined(HAVE_OCC)
  Msg::Direct("OCC version   : %d.%d.%d", OCC_VERSION_MAJOR,
              OCC_VERSION_MINOR, OCC_VERSION_MAINTENANCE);
#endif
#if defined(HAVE_MED)
  Msg::Direct("MED version   : %d.%d.%d", MED_NUM_MAJEUR,
              MED_NUM_MINEUR, MED_NUM_RELEASE);
#endif
  Msg::Direct("Packaged by   : %s", GMSH_PACKAGER);
  Msg::Direct("Web site      : http://gmsh.info");
  Msg::Direct("Issue tracker : https://gitlab.onelab.info/gmsh/gmsh/issues");
}

void GetOptions(int argc, char *argv[], bool readConfigFiles, bool exitOnError)
{
  // print messages on terminal (use special 99 value so that we can detect if
  // it was later set to 1 in the option file)
  int terminal = CTX::instance()->terminal;
  CTX::instance()->terminal = 99;

#if defined(HAVE_PARSER)
  if(readConfigFiles){
    ParseFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName, true);
    ParseFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName, true);
  }
#endif

  if(argc) Msg::SetExecutableName(argv[0]);

  // get command line options
  int i = 1;
  while(i < argc) {

    if(argv[i][0] == '-') {

      if(!strcmp(argv[i] + 1, "") ||
         !strcmp(argv[i] + 1, "parse_and_exit")) {
        CTX::instance()->batch = -99;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "run")) {
        // same as '-', but will run local Gmsh client (if no other clients are
        // requested, e.g. by opening a '.pro' or '.py' file)
        CTX::instance()->batch = -99;
        CTX::instance()->launchSolverAtStartup = -2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "onelab")) {
        i++;
        if(argv[i] && argv[i + 1] && argv[i + 1][0] != '-'){
          Msg::InitializeOnelab(argv[i], argv[i + 1]);
          i += 2;
        }
        else if(argv[i]){
          Msg::InitializeOnelab(argv[i]);
          i += 1;
        }
        else{
          Msg::Error("Missing client name and/or address of ONELAB server");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "socket")) {
        i++;
        if(argv[i])
          Msg::InitializeOnelab("GmshRemote", argv[i++]);
        else{
          Msg::Error("Missing string");
          if(exitOnError) Msg::Exit(1);
        }
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
      else if(!strcmp(argv[i] + 1, "save")) {
        CTX::instance()->batch = 99;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "cpu")) {
        Msg::SetInfoCpu(true);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "log")) {
        i++;
        if(argv[i]){
          Msg::SetLogFile(argv[i++]);
        }
        else{
          Msg::Error("Missing filename");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "refine")) {
        CTX::instance()->batch = 5;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "barycentric_refine")) {
        CTX::instance()->batch = 6;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "reclassify")) {
        i++;
        if(argv[i]){
          CTX::instance()->batch = 7 ;
          CTX::instance()->batchSomeValue = atof(argv[i]);
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "reparam")) {
        i++;
        if(argv[i]){
          CTX::instance()->batch = 8 ;
          CTX::instance()->batchSomeValue = atof(argv[i]);
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "part")) {
        i++;
        if(argv[i]){
          CTX::instance()->batchAfterMesh = 1 ;
          opt_mesh_partition_num(0, GMSH_SET, atoi(argv[i++]));
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "part_weight") ||
              !strcmp(argv[i] + 1, "partWeight")) {
        i++;
        bool check = true;
        opt_mesh_partition_metis_algorithm(0, GMSH_SET, 3); // partGraphKWay w/ weights
        while (check) {
          if (argv[i]) {
            if (!strcmp(argv[i], "tri") || !strcmp(argv[i], "triangle")) {
              i++;
              opt_mesh_partition_tri_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i], "quad") || !strcmp(argv[i], "quadrangle")) {
              i++;
              opt_mesh_partition_qua_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i], "tet") || !strcmp(argv[i], "tetrahedron")) {
              i++;
              opt_mesh_partition_tet_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i], "hex") || !strcmp(argv[i], "hexahedron")) {
              i++;
              opt_mesh_partition_hex_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i], "pri") || !strcmp(argv[i], "prism")) {
              i++;
              opt_mesh_partition_pri_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i], "pyr") || !strcmp(argv[i], "pyramid")) {
              i++;
              opt_mesh_partition_pyr_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else if (!strcmp(argv[i], "trih") || !strcmp(argv[i], "trihedron")) {
              i++;
              opt_mesh_partition_trih_weight(0,GMSH_SET,atoi(argv[i]));
            }
            else {
              Msg::Error("Bad argument for 'partWeight' (%s)", argv[i]);
              if(exitOnError) Msg::Exit(1);
            }
            i++;
          }
          else check = false;
        }
      }
      else if(!strcmp(argv[i] + 1, "part_split") ||
              !strcmp(argv[i] + 1, "part_split_files") ||
              !strcmp(argv[i] + 1, "oneFilePerPart")){
        opt_mesh_partition_split_mesh_files(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "preserveNumberingMsh2")) {
        opt_mesh_preserve_numbering_msh2(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_topo_pro") ||
              !strcmp(argv[i] + 1, "savePartTopology")){
        opt_mesh_partition_save_topology_file(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_topo")){
        opt_mesh_partition_create_topology(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_no_topo")){
        opt_mesh_partition_create_topology(0, GMSH_SET, 0.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_physicals")){
        opt_mesh_partition_create_physicals(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_no_physicals")){
        opt_mesh_partition_create_physicals(0, GMSH_SET, 0.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_ghosts")){
        opt_mesh_partition_create_ghost_cells(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "part_no_ghosts")){
        opt_mesh_partition_create_ghost_cells(0, GMSH_SET, 0.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "new")) {
        CTX::instance()->files.push_back("-new");
        i++;
      }
      else if(!strcmp(argv[i] + 1, "open")) {
        CTX::instance()->files.push_back("-open");
        i++;
      }
      else if(!strcmp(argv[i] + 1, "merge")) {
        CTX::instance()->files.push_back("-merge");
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
      else if(!strcmp(argv[i] + 1, "saveall") ||
              !strcmp(argv[i] + 1, "save_all")) {
        CTX::instance()->mesh.saveAll = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "switch_tags")) {
        CTX::instance()->mesh.switchElementTags = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "optimize")) {
	Msg::Warning("The '-optimize' option is now obsolete: "
                     "Gmsh optimizes tetrahedral meshes by default");
	Msg::Warning("Use '-optimize_threshold threshold' to "
                     "control which elements are optimized");
	Msg::Warning("Option '-optimize_threshold 0' leads to no optimization");
        CTX::instance()->mesh.optimize = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "optimize_threshold")) {
        i++;
        if(argv[i])
          opt_mesh_optimize_threshold(0, GMSH_SET, atof(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "optimize_netgen")) {
        CTX::instance()->mesh.optimizeNetgen = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "optimize_ho") ||
              !strcmp(argv[i] + 1, "hoOptimize")) {
        i++;
        opt_mesh_ho_optimize(0, GMSH_SET, 2);
      }
      else if(!strcmp(argv[i] + 1, "ho_min")) {
        i++;
        if(argv[i])
          opt_mesh_ho_threshold_min(0, GMSH_SET, atof(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "debugSurface")) {
	i++;
        if(argv[i])
          CTX::instance()->debugSurface = atoi(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "ho_max")) {
        i++;
        if(argv[i])
          opt_mesh_ho_threshold_max(0, GMSH_SET, atof(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "ho_nlayers")) {
        i++;
        if(argv[i])
          opt_mesh_ho_nlayers(0, GMSH_SET, atoi(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
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
        else{
          Msg::Error("Missing string");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "string")) {
        i++;
        if(argv[i])
          ParseString(argv[i++]);
        else{
          Msg::Error("Missing string");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "setstring")) {
        i++;
	if (i + 1 < argc && argv[i][0] != '-' && argv[i + 1][0] != '-') {
          std::string n(argv[i]), cat, opt, v = argv[i + 1];
          int index = 0;
          if(SplitOptionName(n, cat, opt, index)){
            GmshSetStringOption(cat, opt, v, index);
          }
          else{
#if defined(HAVE_PARSER)
            gmsh_yystringsymbols[n] = std::vector<std::string>(1, v);
#endif
            Msg::GetCommandLineStrings()[n] = v;
          }
          i += 2;
	}
        else{
          Msg::Error("Missing name and/or value for string definition");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if (!strcmp(argv[i]+1, "setnumber")) {
        i++;
	if (i + 1 < argc && argv[i][0] != '-') {
          std::string n(argv[i]), cat, opt;
          double v = atof(argv[i + 1]);
          int index = 0;
          if(SplitOptionName(n, cat, opt, index)){
            GmshSetNumberOption(cat, opt, v, index);
          }
          else{
#if defined(HAVE_PARSER)
            gmsh_yysymbols[n].value = std::vector<double>(1, v);
#endif
            Msg::GetCommandLineNumbers()[n] = std::vector<double>(1, v);
          }
          i += 2;
	}
        else{
          Msg::Error("Missing name and/or value for number definition");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if (!strcmp(argv[i]+1, "setlist") ||
               !strcmp(argv[i]+1, "setlistofnumbers")) {
        i++;
	if (i + 1 < argc && argv[i][0] != '-') {
          std::string n(argv[i]);
          std::vector<double> v;
          int s = atoi(argv[i + 1]), j = 0;
          i += 2;
          while(j < s && i < argc){
            v.push_back(atof(argv[i]));
            i++; j++;
          }
          if(j < s){
            Msg::Error("Missing values in list (got %d instead of %d)", j, s);
            if(exitOnError) Msg::Exit(1);
          }
#if defined(HAVE_PARSER)
          gmsh_yysymbols[n].value = v;
#endif
          Msg::GetCommandLineNumbers()[n] = v;
	}
        else{
          Msg::Error("Missing name and/or value for definition of list of numbers");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "option")) {
        i++;
        if(argv[i])
          ParseFile(argv[i++], true);
        else{
          Msg::Error("Missing file name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "o")) {
        i++;
        if(argv[i])
          CTX::instance()->outputFileName = argv[i++];
        else{
          Msg::Error("Missing file name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "aniso_max") ||
              !strcmp(argv[i] + 1, "anisoMax")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.anisoMax = atof(argv[i++]);
        else{
          Msg::Error("Missing anisotropy ratio");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "smooth_ratio") ||
              !strcmp(argv[i] + 1, "smoothRatio")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.smoothRatio = atof(argv[i++]);
        else{
          Msg::Error("Missing smooth ratio");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "bgm")) {
        i++;
        if(argv[i])
          CTX::instance()->bgmFileName = argv[i++];
        else{
          Msg::Error("Missing file name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "windows")) {
        i++;
        if(argv[i])
          CTX::instance()->numWindows = atoi(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "tiles")) {
        i++;
        if(argv[i])
          CTX::instance()->numTiles = atoi(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "vmsh")) {
        i++;
        if(argv[i]){
          CTX::instance()->mesh.mshFileVersion = atof(argv[i++]);
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "convert")) {
        i++;
        CTX::instance()->batch = 1;
        while(i < argc) {
          std::string fileName = std::string(argv[i]) + "_new";
#if defined(HAVE_POST)
          std::size_t n = PView::list.size();
#endif
          OpenProject(argv[i]);
#if defined(HAVE_POST)
          // convert post-processing views to latest binary format
          for(std::size_t j = n; j < PView::list.size(); j++)
            PView::list[j]->write(fileName, 1, (j == n) ? false : true);
#endif
          // convert mesh to latest binary format
          if(GModel::current()->getMeshStatus() > 0){
            CTX::instance()->mesh.mshFileVersion = 4.1;
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
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "match")) {
        i++;
        CTX::instance()->geom.matchGeomAndMesh = 1;
      }
      else if(!strcmp(argv[i] + 1, "scale")) {
        i++;
        if(argv[i])
          CTX::instance()->geom.scalingFactor = atof(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "meshscale")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.scalingFactor = atof(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "rand")) {
        i++;
        if(argv[i])
          CTX::instance()->mesh.randFactor = atof(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "clscale")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcFactor = atof(argv[i++]);
          if(CTX::instance()->mesh.lcFactor <= 0.0){
            Msg::Error("Mesh element size factor must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "clmin")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcMin = atof(argv[i++]);
          if(CTX::instance()->mesh.lcMin <= 0.0){
            Msg::Error("Minimum length size must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "clmax")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcMax = atof(argv[i++]);
          if(CTX::instance()->mesh.lcMax <= 0.0){
            Msg::Error("Maximum length size must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "ignore_periodicity") ||
              !strcmp(argv[i] + 1, "ignorePeriodicity")) {
        i++;
        opt_mesh_ignore_periodicity(0, GMSH_SET, 1);
      }
      else if(!strcmp(argv[i] + 1, "edgelmin")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.toleranceEdgeLength = atof(argv[i++]);
          if(CTX::instance()->mesh.toleranceEdgeLength <= 0.0){
            Msg::Error("Tolerance for model curve length must be > 0 (here %g)",
                       CTX::instance()->mesh.toleranceEdgeLength);
            if(exitOnError) Msg::Exit(1);
          }
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "epslc1d")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.lcIntegrationPrecision = atof(argv[i++]);
          if(CTX::instance()->mesh.lcIntegrationPrecision <= 0.0){
            Msg::Error("Integration accuracy must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "swapangle")) {
        i++;
        if(argv[i]) {
          CTX::instance()->mesh.allowSwapEdgeAngle = atof(argv[i++]);
          if(CTX::instance()->mesh.allowSwapEdgeAngle <= 0.0){
            Msg::Error("Threshold angle for edge swap must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
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
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "order") || !strcmp(argv[i] + 1, "degree")) {
        i++;
        if(argv[i])
          opt_mesh_order(0, GMSH_SET, atof(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "numsubedges")) {
        i++;
        if(argv[i])
          opt_mesh_num_sub_edges(0, GMSH_SET, atof(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "statreport")) {
        i++;
        CTX::instance()->createAppendMeshStatReport = 1;
        if(argv[i])
          CTX::instance()->meshStatReportFileName = argv[i++];
        else{
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "append_statreport")) {
        i++;
        CTX::instance()->createAppendMeshStatReport = 2;
        if(argv[i])
          CTX::instance()->meshStatReportFileName = argv[i++];
        else{
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "bin")) {
        i++;
        CTX::instance()->mesh.binary = 1;
      }
      else if(!strcmp(argv[i] + 1, "save_parametric") ||
              !strcmp(argv[i] + 1, "parametric")) {
        i++;
        CTX::instance()->mesh.saveParametric = 1;
      }
      else if(!strcmp(argv[i] + 1, "save_topology") ||
              !strcmp(argv[i] + 1, "save_entities")) {
        i++;
        CTX::instance()->mesh.saveTopology = 1;
      }
      else if(!strcmp(argv[i] + 1, "algo")) {
        i++;
        if(argv[i]) {
          if(!strncmp(argv[i], "auto", 4))
            CTX::instance()->mesh.algo2d = ALGO_2D_AUTO;
          else if(!strncmp(argv[i], "meshadapt", 9) || !strncmp(argv[i], "iso", 3))
            CTX::instance()->mesh.algo2d = ALGO_2D_MESHADAPT;
          else if(!strncmp(argv[i], "del2d", 5) || !strncmp(argv[i], "tri", 3))
            CTX::instance()->mesh.algo2d = ALGO_2D_DELAUNAY;
          else if(!strncmp(argv[i], "delquad", 7))
            CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL_QUAD;
          else if(!strncmp(argv[i], "pack", 4))
            CTX::instance()->mesh.algo2d = ALGO_2D_PACK_PRLGRMS;
          else if(!strncmp(argv[i], "front2d", 7) || !strncmp(argv[i], "frontal", 7))
            CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
          else if(!strncmp(argv[i], "bamg",4))
            CTX::instance()->mesh.algo2d = ALGO_2D_BAMG;
          else if(!strncmp(argv[i], "del3d", 5) || !strncmp(argv[i], "gmsh3d", 6))
            CTX::instance()->mesh.algo3d = ALGO_3D_DELAUNAY;
          else if(!strncmp(argv[i], "hxt", 3) )
            CTX::instance()->mesh.algo3d = ALGO_3D_HXT;
          else if(!strncmp(argv[i], "front3d", 7) || !strncmp(argv[i], "netgen", 6))
            CTX::instance()->mesh.algo3d = ALGO_3D_FRONTAL;
          else if(!strncmp(argv[i], "mmg3d", 5))
            CTX::instance()->mesh.algo3d = ALGO_3D_MMG3D;
          else if(!strncmp(argv[i], "rtree3d", 7))
            CTX::instance()->mesh.algo3d = ALGO_3D_RTREE;
          else{
            Msg::Error("Unknown mesh algorithm");
            if(exitOnError) Msg::Exit(1);
          }
          i++;
        }
        else{
          Msg::Error("Missing algorithm");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "quad")) {
        CTX::instance()->mesh.recombineAll = 1;
        CTX::instance()->mesh.algoRecombine = 2;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "format") || !strcmp(argv[i] + 1, "f")) {
        i++;
        if(argv[i]) {
          double version = 0.;
          int format = GetFileFormatFromExtension
            (std::string(".") + argv[i], &version);
          if(format < 0){
            Msg::Error("Unknown mesh format '%s'", argv[i]);
            if(exitOnError) Msg::Exit(1);
          }
          else{
            CTX::instance()->mesh.fileFormat = format;
            if(format == FORMAT_MSH && version > 0.)
              CTX::instance()->mesh.mshFileVersion = version;
          }
          i++;
        }
        else{
          Msg::Error("Missing format");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "listen")) {
        i++;
        CTX::instance()->solver.listen = 1;
      }
      else if(!strcmp(argv[i] + 1, "minterpreter")) {
        i++;
        if(argv[i])
          CTX::instance()->solver.octaveInterpreter = argv[i++];
        else{
          Msg::Error("Missing interpreter name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "pyinterpreter")) {
        i++;
        if(argv[i])
          CTX::instance()->solver.pythonInterpreter = argv[i++];
        else{
          Msg::Error("Missing interpreter name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "bg")){
        i++;
        if(argv[i])
          CTX::instance()->bgImageFileName = argv[i++];
        else{
          Msg::Error("Missing filename");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "version") || !strcmp(argv[i] + 1, "-version")) {
        fprintf(stderr, "%s\n", GMSH_VERSION);
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "info") || !strcmp(argv[i] + 1, "-info")) {
        PrintInfo();
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "help") || !strcmp(argv[i] + 1, "-help")) {
        Msg::Direct("Gmsh, a 3D mesh generator with pre- and post-processing facilities");
        Msg::Direct("Copyright (C) 1997-2019 C. Geuzaine and J.-F. Remacle");
        PrintUsage(argv[0]);
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "help_options")) {
        std::vector<std::string> s;
        PrintOptions(0, GMSH_FULLRC, 0, 1, 0, &s);
        for(std::size_t i = 0; i < s.size(); i++)
          Msg::Direct("%s\n", s[i].c_str());
        Msg::Exit(0);
      }
      else if(!strcmp(argv[i] + 1, "v") || !strcmp(argv[i] + 1, "verbose")) {
        i++;
        if(argv[i])
          Msg::SetVerbosity(atoi(argv[i++]));
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "nt")) {
        i++;
        if(argv[i]){
          opt_general_num_threads(0, GMSH_SET, atoi(argv[i++]));
	}
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "term")) {
        terminal = 1;
        i++;
      }
#if defined(HAVE_FLTK)
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
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
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
      else if(!strcmp(argv[i] + 1, "camera")) {
        opt_general_camera_mode(0, GMSH_SET, 1.);
	//        CTX::instance()->camera = 1;
        i++;
      }
      else if(!strcmp(argv[i] + 1, "stereo")) {
        opt_general_stereo_mode(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "gamepad")) {
        opt_general_gamepad(0, GMSH_SET, 1.);
        i++;
      }
      else if(!strcmp(argv[i] + 1, "fontsize")) {
        i++;
        if(argv[i])
          CTX::instance()->fontSize = atoi(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "deltafontsize")) {
        i++;
        if(argv[i])
          CTX::instance()->deltaFontSize = atoi(argv[i++]);
        else{
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "theme") || !strcmp(argv[i] + 1, "scheme")) {
        i++;
        if(argv[i])
          CTX::instance()->guiTheme = argv[i++];
        else{
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(!strcmp(argv[i] + 1, "display")) {
        i++;
        if(argv[i])
          CTX::instance()->display = argv[i++];
        else{
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
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

  if(CTX::instance()->terminal == 99)
    CTX::instance()->terminal = terminal;
}
