// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
// OK
#elif (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 3)
// OK
#else
#error "Gmsh requires FLTK >= 1.3.3"
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

int GetGmshMajorVersion() { return GMSH_MAJOR_VERSION; }
int GetGmshMinorVersion() { return GMSH_MINOR_VERSION; }
int GetGmshPatchVersion() { return GMSH_PATCH_VERSION; }
const char *GetGmshExtraVersion() { return GMSH_EXTRA_VERSION; }
const char *GetGmshVersion() { return GMSH_VERSION; }
const char *GetGmshBuildDate() { return GMSH_DATE; }
const char *GetGmshBuildHost() { return GMSH_HOST; }
const char *GetGmshPackager() { return GMSH_PACKAGER; }
const char *GetGmshBuildOS() { return GMSH_OS; }
const char *GetGmshShortLicense() { return GMSH_SHORT_LICENSE; }
const char *GetGmshBuildOptions() { return GMSH_CONFIG_OPTIONS; }

std::vector<std::pair<std::string, std::string> > GetUsage()
{
  typedef std::pair<std::string, std::string> mp;
  std::vector<mp> s;
  s.push_back(mp("(Related option names, if any, are given between parentheses)",
                 ""));
  s.push_back(mp("Geometry:", ""));
  s.push_back(mp("-0", "Output model, then exit"));
  s.push_back(mp("-tol value", "Set geometrical tolerance (Geometry.Tolerance)"));
  s.push_back(mp("-match", "Match geometries and meshes"));
  s.push_back(mp("Mesh:", ""));
  s.push_back(mp("-1, -2, -3", "Perform 1D, 2D or 3D mesh generation, then exit"));
  s.push_back(mp("-save", "Save mesh, then exit"));
  s.push_back(mp("-o file", "Specify output file name"));
  s.push_back(mp("-format string", "Select output mesh format: " +
                 GetKnownFileFormats(true) + " (Mesh.Format)"));
  s.push_back(mp("-bin", "Create binary files when possible (Mesh.Binary)"));
  s.push_back(mp("-refine", "Perform uniform mesh refinement, then exit"));
  s.push_back(mp("-barycentric_refine", "Perform barycentric mesh refinement, "
                 "then exit"));
  s.push_back(mp("-reclassify angle", "Reclassify surface mesh, then exit"));
  s.push_back(mp("-reparam angle", "Reparametrize surface mesh, then exit"));
  s.push_back(mp("-part int", "Partition after batch mesh generation "
                 "(Mesh.NbPartitions)"));
  s.push_back(mp("-part_weight [tri,quad,tet,hex,pri,pyr,trih] int",
                 "Weight of a triangle/quad/etc. during partitioning "
                 "(Mesh.Partition[Tri,Quad,...]Weight)"));
  s.push_back(mp("-part_split", "Save mesh partitions in separate files "
                 "(Mesh.PartitionSplitMeshFiles)"));
  s.push_back(mp("-part_[no_]topo", "Create the partition topology "
                 "(Mesh.PartitionCreateTopology)"));
  s.push_back(mp("-part_[no_]ghosts", "Create ghost cells "
                 "(Mesh.PartitionCreateGhostCells)"));
  s.push_back(mp("-part_[no_]physicals", "Create physical groups for partitions "
                 "(Mesh.PartitionCreatePhysicals)"));
  s.push_back(mp("-part_topo_pro", "Save the partition topology .pro file "
                 "(Mesh.PartitionTopologyFile)"));
  s.push_back(mp("-preserve_numbering_msh2", "Preserve element numbering in MSH2 "
                 "format (Mesh.PreserveNumberingMsh2)"));
  s.push_back(mp("-save_all", "Save all elements (Mesh.SaveAll)"));
  s.push_back(mp("-save_parametric", "Save nodes with their parametric "
                 "coordinates (Mesh.SaveParametric)"));
  s.push_back(mp("-save_topology", "Save model topology (Mesh.SaveTopology)"));
  s.push_back(mp("-algo string", "Select mesh algorithm: auto, meshadapt, del2d, "
                 "front2d, delquad, pack, initial2d, del3d, front3d, mmg3d, hxt, "
                 "initial3d (Mesh.Algorithm and Mesh.Algorithm3D)"));
  s.push_back(mp("-smooth int", "Set number of mesh smoothing steps "
                 "(Mesh.Smoothing)"));
  s.push_back(mp("-order int", "Set mesh order (Mesh.ElementOrder)"));
  s.push_back(mp("-optimize[_netgen]", "Optimize quality of tetrahedral elements "
                 "(Mesh.Optimize[Netgen])"));
  s.push_back(mp("-optimize_threshold", "Optimize tetrahedral elements that have a "
                 "quality less than a threshold (Mesh.OptimizeThreshold)"));
  s.push_back(mp("-optimize_ho", "Optimize high order meshes "
                 "(Mesh.HighOrderOptimize)"));
  s.push_back(mp("-ho_[min,max,nlayers]", "High-order optimization parameters "
                 "(Mesh.HighOrderThreshold[Min,Max], Mesh.HighOrderNumLayers)"));
  s.push_back(mp("-clscale value", "Set mesh element size factor "
                 "(Mesh.MeshSizeFactor)"));
  s.push_back(mp("-clmin value", "Set minimum mesh element size "
                 "(Mesh.MeshSizeMin)"));
  s.push_back(mp("-clmax value", "Set maximum mesh element size "
                 "(Mesh.MeshSizeMax)"));
  s.push_back(mp("-clextend value", "Extend mesh element sizes from boundaries "
                 "(Mesh.MeshSizeExtendFromBoundary)"));
  s.push_back(mp("-clcurv value", "Compute mesh element size from curvature, with "
                 "value the target number of elements per 2*pi radians "
                 "(Mesh.MeshSizeFromCurvature)"));
  s.push_back(mp("-aniso_max value", "Set maximum anisotropy for bamg "
                 "(Mesh.AnisoMax)"));
  s.push_back(mp("-smooth_ratio value", "Set smoothing ration between mesh sizes "
                 "at nodes of a same edge for bamg (Mesh.SmoothRatio)"));
  s.push_back(mp("-epslc1d value", "Set accuracy of evaluation of mesh size field "
                 "for 1D mesh (Mesh.LcIntegrationPrecision)"));
  s.push_back(mp("-swapangle value", "Set the threshold angle (in degrees) between "
                 "two adjacent faces below which a swap is allowed "
                 "(Mesh.AllowSwapAngle)"));
  s.push_back(mp("-rand value", "Set random perturbation factor "
                 "(Mesh.RandomFactor)"));
  s.push_back(mp("-bgm file", "Load background mesh from file"));
  s.push_back(mp("-check", "Perform various consistency checks on mesh"));
  s.push_back(mp("-ignore_periocity", "Ignore periodic boundaries "
                 "(Mesh.IgnorePeriodicity)"));
#if defined(HAVE_FLTK)
  s.push_back(mp("Post-processing:", ""));
  s.push_back(mp("-link int", "Select link mode between views "
                 "(PostProcessing.Link)"));
  s.push_back(mp("-combine", "Combine views having identical names into "
                 "multi-time-step views"));
  s.push_back(mp("Solver:", ""));
  s.push_back(mp("-listen string", "Always listen to incoming connection requests "
                 "(Solver.AlwaysListen) on the given socket "
                 "(uses Solver.SocketName if not specified)"));
  s.push_back(mp("-minterpreter string", "Name of Octave interpreter "
                 "(Solver.OctaveInterpreter)"));
  s.push_back(mp("-pyinterpreter string", "Name of Python interpreter "
                 "(Solver.OctaveInterpreter)"));
  s.push_back(mp("-run", "Run ONELAB solver(s)"));
  s.push_back(mp("Display:", ""));
  s.push_back(mp("-n", "Hide all meshes and post-processing views on startup "
                 "(View.Visible, Mesh.[Points,Lines,SurfaceEdges,...])"));
  s.push_back(mp("-nodb", "Disable double buffering (General.DoubleBuffer)"));
  s.push_back(mp("-numsubedges", "Set num of subdivisions for high order element "
                 "display (Mesh.NumSubEdges)"));
  s.push_back(mp("-fontsize int", "Specify the font size for the GUI "
                 "(General.FontSize)"));
  s.push_back(mp("-theme string", "Specify FLTK GUI theme (General.FltkTheme)"));
  s.push_back(mp("-display string", "Specify display (General.Display)"));
  s.push_back(mp("-camera", "Use camera mode view (General.CameraMode)"));
  s.push_back(mp("-stereo", "OpenGL quad-buffered stereo rendering "
                 "(General.Stereo)"));
  s.push_back(mp("-gamepad", "Use gamepad controller if available"));
#endif
  s.push_back(mp("Other:", ""));
  s.push_back(mp("-, -parse_and_exit", "Parse input files, then exit"));
  s.push_back(mp("-new", "Create new model before merge next file"));
  s.push_back(mp("-merge", "Merge next files"));
  s.push_back(mp("-open", "Open next files"));
  s.push_back(mp("-log filename", "Log all messages to filename"));
#if defined(HAVE_FLTK)
  s.push_back(mp("-a, -g, -m, -s, -p", "Start in automatic, geometry, mesh, "
                 "solver or post-processing mode (General.InitialModule)"));
#endif
  s.push_back(mp("-pid", "Print process id on stdout"));
  s.push_back(mp("-watch pattern", "Pattern of files to merge as they become "
                 "available (General.WatchFilePattern)"));
  s.push_back(mp("-bg file", "Load background (image or PDF) file "
                 "(General.BackgroundImageFileName)"));
  s.push_back(mp("-v int", "Set verbosity level (General.Verbosity)"));
  s.push_back(mp("-string \"string\"", "Parse command string at startup"));
  s.push_back(mp("-setnumber name value", "Set constant or option number "
                 "name=value"));
  s.push_back(mp("-setstring name value", "Set constant or option string "
                 "name=value"));
  s.push_back(mp("-nopopup", "Don't popup dialog windows in scripts "
                 "(General.NoPopup)"));
  s.push_back(mp("-noenv", "Don't modify the environment at startup"));
  s.push_back(mp("-nolocale", "Don't modify the locale at startup"));
  s.push_back(mp("-option file", "Parse option file at startup"));
  s.push_back(mp("-convert files", "Convert files into latest binary formats, "
                 "then exit"));
  s.push_back(mp("-nt int", "Set number of threads (General.NumThreads)"));
  s.push_back(mp("-cpu", "Report CPU times for all operations"));
  s.push_back(mp("-version", "Show version number"));
  s.push_back(mp("-info", "Show detailed version information"));
  s.push_back(mp("-help", "Show command line usage"));
  s.push_back(mp("-help_options", "Show all options"));
  return s;
}

std::vector<std::pair<std::string, std::string> >
GetShortcutsUsage(const std::string &ctrl)
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
  s.push_back(mp(cc + "0 or 9", "Reload full project"));
  s.push_back(mp("1 or F1", "Mesh lines"));
  s.push_back(mp("2 or F2", "Mesh surfaces"));
  s.push_back(mp("3 or F3", "Mesh volumes"));
  s.push_back(mp("Escape", "Cancel lasso zoom/selection, toggle mouse "
                 "selection ON/OFF"));
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
  s.push_back(mp("Shift+x", "Move only along x coordinate in geometry "
                 "creation mode"));
  s.push_back(mp("Shift+y", "Move only along y coordinate in geometry "
                 "creation mode"));
  s.push_back(mp("Shift+z", "Move only along z coordinate in geometry "
                 "creation mode"));
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
  s.push_back(mp("Shift+" + cc + "h", "Show current options and workspace "
                 "window"));
  s.push_back(mp("Shift+" + cc + "j", "Save options as default"));
  s.push_back(mp("Shift+" + cc + "m", "Show manipulator window"));
  s.push_back(mp("Shift+" + cc + "n", "Show option window"));
  s.push_back(mp("Shift+" + cc + "o", "Merge file(s)"));
  s.push_back(mp("Shift+" + cc + "r", "Open next-to-last opened file"));
  s.push_back(mp("Shift+" + cc + "u", "Show plugin window"));
  s.push_back(mp("Shift+" + cc + "v", "Show visibility window"));
  s.push_back(mp("Alt+a", "Loop through axes modes"));
  s.push_back(mp("Alt+b", "Hide/show bounding boxes"));
  s.push_back(mp("Alt+c", "Loop through predefined color schemes"));
  s.push_back(mp("Alt+e", "Hide/Show element outlines for visible post-pro "
                 "views"));
  s.push_back(mp("Alt+f", "Change redraw mode (fast/full)"));
  s.push_back(mp("Alt+h", "Hide/show all post-processing views"));
  s.push_back(mp("Alt+i", "Hide/show all post-processing view scales"));
  s.push_back(mp("Alt+l", "Hide/show geometry lines"));
  s.push_back(mp("Alt+m", "Toggle visibility of all mesh entities"));
  s.push_back(mp("Alt+n", "Hide/show all post-processing view annotations"));
  s.push_back(mp("Alt+o", "Change projection mode (orthographic/perspective)"));
  s.push_back(mp("Alt+p", "Hide/show geometry points"));
  s.push_back(mp("Alt+r", "Loop through range modes for visible post-pro "
                 "views"));
  s.push_back(mp("Alt+s", "Hide/show geometry surfaces"));
  s.push_back(mp("Alt+t", "Loop through interval modes for visible post-pro "
                 "views"));
  s.push_back(mp("Alt+v", "Hide/show geometry volumes"));
  s.push_back(mp("Alt+w", "Enable/disable all lighting"));
  s.push_back(mp("Alt+x", "Set X view"));
  s.push_back(mp("Alt+y", "Set Y view"));
  s.push_back(mp("Alt+z", "Set Z view"));
  s.push_back(mp("Alt+1", "Set 1:1 view"));
  s.push_back(mp("Alt+Shift+a", "Hide/show small axes"));
  s.push_back(mp("Alt+Shift+b", "Hide/show mesh volume faces"));
  s.push_back(mp("Alt+Shift+c", "Loop through predefined colormaps"));
  s.push_back(mp("Alt+Shift+d", "Hide/show mesh surface faces"));
  s.push_back(mp("Alt+Shift+l", "Hide/show mesh lines"));
  s.push_back(mp("Alt+Shift+p", "Hide/show mesh nodes"));
  s.push_back(mp("Alt+Shift+s", "Hide/show mesh surface edges"));
  s.push_back(mp("Alt+Shift+t", "Same as Alt+t, but with numeric mode "
                 "included"));
  s.push_back(mp("Alt+Shift+v", "Hide/show mesh volume edges"));
  s.push_back(mp("Alt+Shift+x", "Set -X view"));
  s.push_back(mp("Alt+Shift+y", "Set -Y view"));
  s.push_back(mp("Alt+Shift+z", "Set -Z view"));
  s.push_back(mp("Alt+Shift+1", "Reset bounding box around visible entities"));
  s.push_back(mp("Alt+" + cc + "+1", "Sync scale between viewports"));
  return s;
}

std::vector<std::pair<std::string, std::string> > GetMouseUsage()
{
  typedef std::pair<std::string, std::string> mp;
  std::vector<mp> s;
  s.push_back(mp("Move", "Highlight the entity under the mouse pointer and "
                 "display its properties / Resize a lasso zoom or a lasso "
                 "(un)selection"));
  s.push_back(mp("Left button", "Rotate / Select an entity / Accept a lasso "
                 "zoom or a lasso selection"));
  s.push_back(mp("Ctrl+Left button", "Start a lasso zoom or a lasso "
                 "(un)selection"));
  s.push_back(mp("Middle button", "Zoom / Unselect an entity / Accept a lasso "
                 "zoom or a lasso unselection"));
  s.push_back(mp("Ctrl+Middle button", "Orthogonalize display"));
  s.push_back(mp("Right button", "Pan / Cancel a lasso zoom or a lasso "
                 "(un)selection / Pop-up menu on post-processing view button"));
  s.push_back(mp("Ctrl+Right button", "Reset to default viewpoint"));
  return s;
}

void PrintUsage(const std::string &name)
{
  Msg::Direct("Usage: %s [options] [files]", name.c_str());
  std::vector<std::pair<std::string, std::string> > s = GetUsage();
  for(std::size_t i = 0; i < s.size(); i++) {
    std::string a = s[i].first, b = s[i].second;
    if(b.empty()) { Msg::Direct("%s", a.c_str()); }
    else {
      if(a.size() < 20) a.resize(20, ' ');
      Msg::Direct("  %s %s", a.c_str(), b.c_str());
    }
  }
}

std::vector<std::string> GetBuildInfo()
{
  std::vector<std::string> s;
  s.push_back(std::string("Version       : ") + GMSH_VERSION);
  s.push_back(std::string("License       : ") + GMSH_SHORT_LICENSE);
  s.push_back(std::string("Build OS      : ") + GMSH_OS);
  s.push_back(std::string("Build date    : ") + GMSH_DATE);
  s.push_back(std::string("Build host    : ") + GMSH_HOST);
  s.push_back(std::string("Build options :") + GMSH_CONFIG_OPTIONS);
#if defined(HAVE_FLTK)
  {
    char tmp[256];
    sprintf(tmp, "%d.%d.%d", FL_MAJOR_VERSION, FL_MINOR_VERSION,
            FL_PATCH_VERSION);
    s.push_back(std::string("FLTK version  : ") + tmp);
  }
#endif
#if defined(HAVE_PETSC)
  {
    char tmp[256];
    sprintf(tmp, "%d.%d.%d (%s arithmtic)", PETSC_VERSION_MAJOR,
            PETSC_VERSION_MINOR, PETSC_VERSION_SUBMINOR,
#if defined(PETSC_USE_COMPLEX)
            "complex"
#else
            "real"
#endif
            );
    s.push_back(std::string("PETSc version : ") + tmp);
  }
#endif
#if defined(HAVE_OCC)
  {
    char tmp[256];
    sprintf(tmp, "%d.%d.%d", OCC_VERSION_MAJOR, OCC_VERSION_MINOR,
            OCC_VERSION_MAINTENANCE);
    s.push_back(std::string("OCC version   : ") + tmp);
  }
#endif
#if defined(HAVE_MED)
  {
    char tmp[256];
    sprintf(tmp, "%d.%d.%d", MED_NUM_MAJEUR, MED_NUM_MINEUR, MED_NUM_RELEASE);
    s.push_back(std::string("MED version   : ") + tmp);
  }
#endif
  s.push_back(std::string("Packaged by   : ") + GMSH_PACKAGER);
  s.push_back("Web site      : https://gmsh.info");
  s.push_back("Issue tracker : https://gitlab.onelab.info/gmsh/gmsh/issues");
  return s;
}

void PrintBuildInfo()
{
  std::vector<std::string> s = GetBuildInfo();
  for(std::size_t i = 0; i < s.size(); i++) Msg::Direct("%s", s[i].c_str());
}

void GetOptions(bool readConfigFiles, bool exitOnError)
{
  // print messages on terminal (use special 99 value so that we can detect if
  // it was later set to 1 in the option file)
  int terminal = CTX::instance()->terminal;
  CTX::instance()->terminal = 99;

#if defined(HAVE_PARSER)
  if(readConfigFiles) {
    ParseFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName,
              true);
    ParseFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName,
              true);
  }
#endif

  std::vector<std::string> &argv(Msg::GetCommandLineArgs());

  if(argv.size()) Msg::SetExecutableName(argv[0]);

  // get command line options
  std::size_t i = 1;
  while(i < argv.size()) {
    if(argv[i].size() && argv[i][0] == '-') {
      if(argv[i] == "-" || argv[i] == "-parse_and_exit") {
        CTX::instance()->batch = -99;
        i++;
      }
      else if(argv[i] == "-run") {
        // same as '-', but will run local Gmsh client (if no other clients are
        // requested, e.g. by opening a '.pro' or '.py' file)
        CTX::instance()->batch = -99;
        CTX::instance()->launchSolverAtStartup = -2;
        i++;
      }
      else if(argv[i] == "-onelab") {
        i++;
        if(i + 1 < argv.size() && argv[i + 1].size() && argv[i + 1][0] != '-') {
          Msg::InitializeOnelab(argv[i], argv[i + 1]);
          i += 2;
        }
        else if(i < argv.size()) {
          Msg::InitializeOnelab(argv[i]);
          i += 1;
        }
        else {
          Msg::Error("Missing client name and/or address of ONELAB server");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-socket") {
        i++;
        if(i < argv.size())
          Msg::InitializeOnelab("GmshRemote", argv[i++]);
        else {
          Msg::Error("Missing string");
          if(exitOnError) Msg::Exit(1);
        }
        CTX::instance()->batch = -3;
      }
      else if(argv[i] == "-check") {
        CTX::instance()->batch = -2;
        i++;
      }
      else if(argv[i] == "-0") {
        CTX::instance()->batch = -1;
        i++;
      }
      else if(argv[i] == "-1") {
        CTX::instance()->batch = 1;
        i++;
      }
      else if(argv[i] == "-2") {
        CTX::instance()->batch = 2;
        i++;
      }
      else if(argv[i] == "-3") {
        CTX::instance()->batch = 3;
        i++;
      }
      else if(argv[i] == "-4") {
        CTX::instance()->batch = 4;
        i++;
      }
      else if(argv[i] == "-save") {
        CTX::instance()->batch = 99;
        i++;
      }
      else if(argv[i] == "-cpu") {
        Msg::SetInfoCpu(true);
        Msg::SetInfoMem(true);
        i++;
      }
      else if(argv[i] == "-log") {
        i++;
        if(i < argv.size()) { Msg::SetLogFile(argv[i++]); }
        else {
          Msg::Error("Missing filename");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-refine") {
        CTX::instance()->batch = 5;
        i++;
      }
      else if(argv[i] == "-barycentric_refine") {
        CTX::instance()->batch = 6;
        i++;
      }
      else if(argv[i] == "-reclassify") {
        i++;
        if(i < argv.size()) {
          CTX::instance()->batch = 7;
          CTX::instance()->batchSomeValue = atof(argv[i].c_str());
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-reparam") {
        i++;
        if(i < argv.size()) {
          CTX::instance()->batch = 8;
          CTX::instance()->batchSomeValue = atof(argv[i].c_str());
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-quadlayout") {
        CTX::instance()->batch = 69;
        i++;
      }
      else if(argv[i] == "-part") {
        i++;
        if(i < argv.size()) {
          CTX::instance()->batchAfterMesh = 1;
          opt_mesh_partition_num(0, GMSH_SET, atoi(argv[i++].c_str()));
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-part_weight" || argv[i] == "-partWeight") {
        i++;
        bool check = true;
        opt_mesh_partition_metis_algorithm(0, GMSH_SET,
                                           3); // partGraphKWay w/ weights
        while(check) {
          if(i < argv.size()) {
            if(argv[i] == "tri" || argv[i] == "triangle") {
              i++;
              opt_mesh_partition_tri_weight(0, GMSH_SET, atoi(argv[i].c_str()));
            }
            else if(argv[i] == "quad" || argv[i] == "quadrangle") {
              i++;
              opt_mesh_partition_qua_weight(0, GMSH_SET, atoi(argv[i].c_str()));
            }
            else if(argv[i] == "tet" || argv[i] == "tetrahedron") {
              i++;
              opt_mesh_partition_tet_weight(0, GMSH_SET, atoi(argv[i].c_str()));
            }
            else if(argv[i] == "hex" || argv[i] == "hexahedron") {
              i++;
              opt_mesh_partition_hex_weight(0, GMSH_SET, atoi(argv[i].c_str()));
            }
            else if(argv[i] == "pri" || argv[i] == "prism") {
              i++;
              opt_mesh_partition_pri_weight(0, GMSH_SET, atoi(argv[i].c_str()));
            }
            else if(argv[i] == "pyr" || argv[i] == "pyramid") {
              i++;
              opt_mesh_partition_pyr_weight(0, GMSH_SET, atoi(argv[i].c_str()));
            }
            else if(argv[i] == "trih" || argv[i] == "trihedron") {
              i++;
              opt_mesh_partition_trih_weight(0, GMSH_SET,
                                             atoi(argv[i].c_str()));
            }
            else {
              Msg::Error("Bad argument for 'partWeight' (%s)", argv[i].c_str());
              if(exitOnError) Msg::Exit(1);
            }
            i++;
          }
          else
            check = false;
        }
      }
      else if(argv[i] == "-part_split" || argv[i] == "-part_split_files" ||
              argv[i] == "-oneFilePerPart") {
        opt_mesh_partition_split_mesh_files(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-preserve_numbering_msh2" ||
              argv[i] == "-preserveNumberingMsh2") {
        opt_mesh_preserve_numbering_msh2(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-part_topo_pro" || argv[i] == "-savePartTopology") {
        opt_mesh_partition_save_topology_file(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-part_topo") {
        opt_mesh_partition_create_topology(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-part_no_topo") {
        opt_mesh_partition_create_topology(0, GMSH_SET, 0.);
        i++;
      }
      else if(argv[i] == "-part_physicals") {
        opt_mesh_partition_create_physicals(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-part_no_physicals") {
        opt_mesh_partition_create_physicals(0, GMSH_SET, 0.);
        i++;
      }
      else if(argv[i] == "-part_ghosts") {
        opt_mesh_partition_create_ghost_cells(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-part_no_ghosts") {
        opt_mesh_partition_create_ghost_cells(0, GMSH_SET, 0.);
        i++;
      }
      else if(argv[i] == "-new") {
        CTX::instance()->files.push_back("-new");
        i++;
      }
      else if(argv[i] == "-open") {
        CTX::instance()->files.push_back("-open");
        i++;
      }
      else if(argv[i] == "-merge") {
        CTX::instance()->files.push_back("-merge");
        i++;
      }
      else if(argv[i] == "-pid") {
        fprintf(stdout, "%d\n", GetProcessId());
        fflush(stdout);
        i++;
      }
      else if(argv[i] == "-a") {
        opt_general_initial_context(0, GMSH_SET, 0);
        i++;
      }
      else if(argv[i] == "-g") {
        opt_general_initial_context(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-m") {
        opt_general_initial_context(0, GMSH_SET, 2);
        i++;
      }
      else if(argv[i] == "-s") {
        opt_general_initial_context(0, GMSH_SET, 3);
        i++;
      }
      else if(argv[i] == "-p") {
        opt_general_initial_context(0, GMSH_SET, 4);
        i++;
      }
      else if(argv[i] == "-saveall" || argv[i] == "-save_all") {
        opt_mesh_save_all(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-switch_tags") {
        opt_mesh_switch_elem_tags(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-optimize") {
        Msg::Warning("The '-optimize' option is now obsolete: "
                     "Gmsh optimizes tetrahedral meshes by default");
        Msg::Warning("Use '-optimize_threshold threshold' to "
                     "control which elements are optimized");
        Msg::Warning("Option '-optimize_threshold 0' leads to no optimization");
        opt_mesh_optimize(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-optimize_threshold") {
        i++;
        if(i < argv.size())
          opt_mesh_optimize_threshold(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-optimize_netgen") {
        opt_mesh_optimize_netgen(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-optimize_ho" || argv[i] == "-hoOptimize") {
        i++;
        opt_mesh_ho_optimize(0, GMSH_SET, 2);
      }
      else if(argv[i] == "-ho_min") {
        i++;
        if(i < argv.size())
          opt_mesh_ho_threshold_min(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-debugSurface") {
        i++;
        if(i < argv.size())
          CTX::instance()->debugSurface = atoi(argv[i++].c_str());
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-ho_max") {
        i++;
        if(i < argv.size())
          opt_mesh_ho_threshold_max(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-ho_nlayers") {
        i++;
        if(i < argv.size())
          opt_mesh_ho_nlayers(0, GMSH_SET, atoi(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-nopopup") {
        opt_general_nopopup(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-watch") {
        i++;
        if(i < argv.size()) {
          std::string tmp = argv[i++];
          if(tmp.size() > 2 && tmp[0] == '"' && tmp[tmp.size() - 1] == '"')
            opt_general_watch_file_pattern(0, GMSH_SET,
                                           tmp.substr(1, tmp.size() - 2));
          else
            opt_general_watch_file_pattern(0, GMSH_SET, tmp);
        }
        else {
          Msg::Error("Missing string");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-string") {
        i++;
        if(i < argv.size())
          ParseString(argv[i++]);
        else {
          Msg::Error("Missing string");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-setstring") {
        i++;
        if(i + 1 < argv.size()) {
          std::string n(argv[i]), cat, opt, v = argv[i + 1];
          int index = 0;
          if(SplitOptionName(n, cat, opt, index)) {
            GmshSetStringOption(cat, opt, v, index);
          }
          else {
#if defined(HAVE_PARSER)
            gmsh_yystringsymbols[n] = std::vector<std::string>(1, v);
#endif
            Msg::GetCommandLineStrings()[n] = v;
          }
          i += 2;
        }
        else {
          Msg::Error("Missing name and/or value for string definition");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-setnumber") {
        i++;
        if(i + 1 < argv.size()) {
          std::string n(argv[i]), cat, opt;
          double v = atof(argv[i + 1].c_str());
          int index = 0;
          if(SplitOptionName(n, cat, opt, index)) {
            GmshSetNumberOption(cat, opt, v, index);
          }
          else {
#if defined(HAVE_PARSER)
            gmsh_yysymbols[n].value = std::vector<double>(1, v);
#endif
            Msg::GetCommandLineNumbers()[n] = std::vector<double>(1, v);
          }
          i += 2;
        }
        else {
          Msg::Error("Missing name and/or value for number definition");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-setlist" || argv[i] == "-setlistofnumbers") {
        i++;
        if(i + 1 < argv.size() && argv[i].size() && argv[i][0] != '-') {
          std::string n(argv[i]);
          std::vector<double> v;
          int s = atoi(argv[i + 1].c_str()), j = 0;
          i += 2;
          while(j < s && i < argv.size()) {
            v.push_back(atof(argv[i].c_str()));
            i++;
            j++;
          }
          if(j < s) {
            Msg::Error("Missing values in list (got %d instead of %d)", j, s);
            if(exitOnError) Msg::Exit(1);
          }
#if defined(HAVE_PARSER)
          gmsh_yysymbols[n].value = v;
#endif
          Msg::GetCommandLineNumbers()[n] = v;
        }
        else {
          Msg::Error(
            "Missing name and/or value for definition of list of numbers");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-option") {
        i++;
        if(i < argv.size())
          ParseFile(argv[i++], true);
        else {
          Msg::Error("Missing file name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-o") {
        i++;
        if(i < argv.size())
          CTX::instance()->outputFileName = argv[i++];
        else {
          Msg::Error("Missing file name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-aniso_max" || argv[i] == "-anisoMax") {
        i++;
        if(i < argv.size())
          opt_mesh_aniso_max(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing anisotropy ratio");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-smooth_ratio" || argv[i] == "-smoothRatio") {
        i++;
        if(i < argv.size())
          opt_mesh_smooth_ratio(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing smooth ratio");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-bgm") {
        i++;
        if(i < argv.size())
          CTX::instance()->bgmFileName = argv[i++];
        else {
          Msg::Error("Missing file name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-size_field") {
        i++;
        if(i < argv.size()){
          CTX::instance()->mesh.nLayersPerGap = atoi(argv[i].c_str());
          CTX::instance()->batch = 9;
        }
        else{
          Msg::Error("Missing number of layers per gap");
          if(exitOnError) Msg::Exit(1);
        }
        i++;
        if(i < argv.size()){
          CTX::instance()->mesh.lcFromCurvature = atoi(argv[i].c_str());
          if(CTX::instance()->mesh.lcFromCurvature <= 0.)
            CTX::instance()->mesh.lcFromCurvature = 0;
        }
        else{
          Msg::Error("Missing number of elements density");
          if(exitOnError) Msg::Exit(1);
        }
        i++;
        if(i < argv.size()){
          CTX::instance()->mesh.gradation = atof(argv[i].c_str());
          if(CTX::instance()->mesh.gradation <= 1.){
            CTX::instance()->mesh.gradation = 1.05;
            Msg::Info("Gradation must be > 1 : set to 1.05");
          }
        }
        else{
          Msg::Error("Missing gradation");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-windows") {
        i++;
        if(i < argv.size())
          CTX::instance()->numWindows = atoi(argv[i++].c_str());
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-tiles") {
        i++;
        if(i < argv.size())
          CTX::instance()->numTiles = atoi(argv[i++].c_str());
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-vmsh") {
        i++;
        if(i < argv.size()) {
          opt_mesh_msh_file_version(0, GMSH_SET, atof(argv[i++].c_str()));
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-convert") {
        i++;
        CTX::instance()->batch = 1;
        while(i < argv.size()) {
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
          if(GModel::current()->getMeshStatus() > 0) {
            opt_mesh_msh_file_version(0, GMSH_SET, 4.1);
            opt_mesh_binary(0, GMSH_SET, 1);
            CreateOutputFile(fileName, FORMAT_MSH);
          }
          i++;
        }
        Msg::Exit(0);
      }
      else if(argv[i] == "-tol") {
        i++;
        if(i < argv.size())
          opt_geometry_tolerance(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-match") {
        i++;
        opt_geometry_match_geom_and_mesh(0, GMSH_SET, 1);
      }
      else if(argv[i] == "-scale") {
        i++;
        if(i < argv.size())
          opt_geometry_scaling_factor(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-meshscale") {
        i++;
        if(i < argv.size())
          opt_mesh_scaling_factor(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-rand") {
        i++;
        if(i < argv.size())
          opt_mesh_rand_factor(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-clscale") {
        i++;
        if(i < argv.size()) {
          opt_mesh_lc_factor(0, GMSH_SET, atof(argv[i++].c_str()));
          if(CTX::instance()->mesh.lcFactor <= 0.0) {
            Msg::Error("Mesh element size factor must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-clmin") {
        i++;
        if(i < argv.size())
          opt_mesh_lc_min(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-clmax") {
        i++;
        if(i < argv.size()) {
          opt_mesh_lc_max(0, GMSH_SET, atof(argv[i++].c_str()));
          if(CTX::instance()->mesh.lcMax <= 0.0) {
            Msg::Error("Maximum length size must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-clextend") {
        i++;
        if(i < argv.size())
          opt_mesh_lc_extend_from_boundary(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-ignore_periodicity" ||
              argv[i] == "-ignorePeriodicity") {
        i++;
        opt_mesh_ignore_periodicity(0, GMSH_SET, 1);
      }
      else if(argv[i] == "-edgelmin") {
        i++;
        if(i < argv.size())
          opt_mesh_tolerance_edge_length(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-epslc1d") {
        i++;
        if(i < argv.size()) {
          opt_mesh_lc_integration_precision(0, GMSH_SET,
                                            atof(argv[i++].c_str()));
          if(CTX::instance()->mesh.lcIntegrationPrecision <= 0.0) {
            Msg::Error("Integration accuracy must be > 0");
            if(exitOnError) Msg::Exit(1);
          }
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-swapangle") {
        i++;
        if(i < argv.size())
          opt_mesh_allow_swap_edge_angle(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-clcurv") {
        i++;
        if(i < argv.size()) {
          opt_mesh_lc_from_curvature(0, GMSH_SET, atof(argv[i++].c_str()));
        }
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-clcurviso") {
        opt_mesh_lc_from_curvature_iso(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-smooth") {
        i++;
        if(i < argv.size())
          opt_mesh_nb_smoothing(0, GMSH_SET, atoi(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-order" || argv[i] == "-degree") {
        i++;
        if(i < argv.size())
          opt_mesh_order(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-numsubedges") {
        i++;
        if(i < argv.size())
          opt_mesh_num_sub_edges(0, GMSH_SET, atof(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-statreport") {
        i++;
        CTX::instance()->createAppendMeshStatReport = 1;
        if(i < argv.size())
          CTX::instance()->meshStatReportFileName = argv[i++];
        else {
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-append_statreport") {
        i++;
        CTX::instance()->createAppendMeshStatReport = 2;
        if(i < argv.size())
          CTX::instance()->meshStatReportFileName = argv[i++];
        else {
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-bin") {
        i++;
        opt_mesh_binary(0, GMSH_SET, 1);
      }
      else if(argv[i] == "-save_parametric" || argv[i] == "-parametric") {
        i++;
        opt_mesh_save_parametric(0, GMSH_SET, 1);
      }
      else if(argv[i] == "-save_topology" || argv[i] == "-save_entities") {
        i++;
        opt_mesh_save_topology(0, GMSH_SET, 1);
      }
      else if(argv[i] == "-algo") {
        i++;
        if(i < argv.size()) {
          if(argv[i] == "MeshAdapt" || argv[i] == "meshadapt" ||
             argv[i] == "iso")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_MESHADAPT);
          else if(argv[i] == "auto")
            CTX::instance()->mesh.algo2d = ALGO_2D_AUTO;
          else if(argv[i] == "Delaunay2D" || argv[i] == "del2d" ||
                  argv[i] == "tri")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_DELAUNAY);
          else if(argv[i] == "FrontalDelaunay2D" || argv[i] == "front2d" ||
                  argv[i] == "frontal")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_FRONTAL);
          else if(argv[i] == "bamg")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_BAMG);
          else if(argv[i] == "DelaunayFrontalForQuads" || argv[i] == "delquad")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_FRONTAL_QUAD);
          else if(argv[i] == "PackingOfParallelograms" || argv[i] == "pack")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_PACK_PRLGRMS);
          else if(argv[i] == "initial2d")
            opt_mesh_algo2d(0, GMSH_SET, ALGO_2D_INITIAL_ONLY);
          else if(argv[i] == "del3d" || argv[i] == "gmsh3d")
            opt_mesh_algo3d(0, GMSH_SET, ALGO_3D_DELAUNAY);
          else if(argv[i] == "front3d" || argv[i] == "netgen")
            opt_mesh_algo3d(0, GMSH_SET, ALGO_3D_FRONTAL);
          else if(argv[i] == "mmg3d")
            opt_mesh_algo3d(0, GMSH_SET, ALGO_3D_MMG3D);
          else if(argv[i] == "rtree3d")
            opt_mesh_algo3d(0, GMSH_SET, ALGO_3D_RTREE);
          else if(argv[i] == "hxt")
            opt_mesh_algo3d(0, GMSH_SET, ALGO_3D_HXT);
          else if(argv[i] == "initial3d")
            opt_mesh_algo3d(0, GMSH_SET, ALGO_3D_INITIAL_ONLY);
          else {
            Msg::Error("Unknown mesh algorithm");
            if(exitOnError) Msg::Exit(1);
          }
          i++;
        }
        else {
          Msg::Error("Missing algorithm");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-quad") {
        opt_mesh_recombine_all(0, GMSH_SET, 1);
        opt_mesh_algo_recombine(0, GMSH_SET, 2);
        i++;
      }
      else if(argv[i] == "-format" || argv[i] == "-f") {
        i++;
        if(i < argv.size()) {
          double version = 0.;
          int format =
            GetFileFormatFromExtension(std::string(".") + argv[i], &version);
          if(format < 0) {
            Msg::Error("Unknown mesh format '%s'", argv[i].c_str());
            if(exitOnError) Msg::Exit(1);
          }
          else {
            opt_mesh_file_format(0, GMSH_SET, format);
            if(format == FORMAT_MSH && version > 0.)
              opt_mesh_msh_file_version(0, GMSH_SET, version);
          }
          i++;
        }
        else {
          Msg::Error("Missing format");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-listen") {
        i++;
        opt_solver_listen(0, GMSH_SET, 1);
        if(i < argv.size() && argv[i].size() && argv[i][0] != '-')
          opt_solver_socket_name(0, GMSH_SET, argv[i++]);
      }
      else if(argv[i] == "-minterpreter") {
        i++;
        if(i < argv.size())
          opt_solver_octave_interpreter(0, GMSH_SET, argv[i++]);
        else {
          Msg::Error("Missing interpreter name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-pyinterpreter") {
        i++;
        if(i < argv.size())
          opt_solver_python_interpreter(0, GMSH_SET, argv[i++]);
        else {
          Msg::Error("Missing interpreter name");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-bg") {
        i++;
        if(i < argv.size())
          opt_general_background_image_filename(0, GMSH_SET, argv[i++]);
        else {
          Msg::Error("Missing filename");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-version" || argv[i] == "--version") {
        fprintf(stderr, "%s\n", GMSH_VERSION);
        Msg::Exit(0);
      }
      else if(argv[i] == "-info" || argv[i] == "--info") {
        PrintBuildInfo();
        Msg::Exit(0);
      }
      else if(argv[i] == "-help" || argv[i] == "--help") {
        Msg::Direct(
          "Gmsh, a 3D mesh generator with pre- and post-processing facilities");
        Msg::Direct("Copyright (C) 1997-2021 C. Geuzaine and J.-F. Remacle");
        PrintUsage(argv[0]);
        Msg::Exit(0);
      }
      else if(argv[i] == "-help_options") {
        std::vector<std::string> s;
        PrintOptions(0, GMSH_FULLRC, 0, 1, nullptr, &s);
        for(std::size_t i = 0; i < s.size(); i++)
          Msg::Direct("%s\n", s[i].c_str());
        Msg::Exit(0);
      }
      else if(argv[i] == "-v" || argv[i] == "-verbose") {
        i++;
        if(i < argv.size())
          Msg::SetVerbosity(atoi(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-nt") {
        i++;
        if(i < argv.size())
          opt_general_num_threads(0, GMSH_SET, atoi(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-term") {
        terminal = 1;
        i++;
      }
#if defined(HAVE_FLTK)
      else if(argv[i] == "-dual") {
        opt_mesh_dual(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-voronoi") {
        opt_mesh_voronoi(0, GMSH_SET, 1);
        i++;
      }
      else if(argv[i] == "-noview") {
        opt_view_visible(0, GMSH_SET, 0);
        i++;
      }
      else if(argv[i] == "-nomesh") {
        opt_mesh_nodes(0, GMSH_SET, 0.);
        opt_mesh_lines(0, GMSH_SET, 0.);
        opt_mesh_surface_edges(0, GMSH_SET, 0.);
        opt_mesh_surface_faces(0, GMSH_SET, 0.);
        opt_mesh_volume_edges(0, GMSH_SET, 0.);
        opt_mesh_volume_faces(0, GMSH_SET, 0.);
        i++;
      }
      else if(argv[i] == "-n") {
        opt_view_visible(0, GMSH_SET, 0);
        opt_mesh_nodes(0, GMSH_SET, 0.);
        opt_mesh_lines(0, GMSH_SET, 0.);
        opt_mesh_surface_edges(0, GMSH_SET, 0.);
        opt_mesh_surface_faces(0, GMSH_SET, 0.);
        opt_mesh_volume_edges(0, GMSH_SET, 0.);
        opt_mesh_volume_faces(0, GMSH_SET, 0.);
        i++;
      }
      else if(argv[i] == "-link") {
        i++;
        if(i < argv.size())
          opt_post_link(0, GMSH_SET, atoi(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-smoothview") {
        opt_post_smooth(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-combine") {
        CTX::instance()->post.combineTime = 1;
        i++;
      }
      else if(argv[i] == "-nodb") {
        opt_general_double_buffer(0, GMSH_SET, 0.);
        i++;
      }
      else if(argv[i] == "-camera") {
        opt_general_camera_mode(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-stereo") {
        opt_general_stereo_mode(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-gamepad") {
        opt_general_gamepad(0, GMSH_SET, 1.);
        i++;
      }
      else if(argv[i] == "-fontsize") {
        i++;
        if(i < argv.size())
          opt_general_fontsize(0, GMSH_SET, atoi(argv[i++].c_str()));
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-deltafontsize") {
        i++;
        if(i < argv.size())
          CTX::instance()->deltaFontSize = atoi(argv[i++].c_str());
        else {
          Msg::Error("Missing number");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-theme" || argv[i] == "-scheme") {
        i++;
        if(i < argv.size())
          opt_general_gui_theme(0, GMSH_SET, argv[i++]);
        else {
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
      else if(argv[i] == "-display") {
        i++;
        if(i < argv.size())
          opt_general_display(0, GMSH_SET, argv[i++]);
        else {
          Msg::Error("Missing argument");
          if(exitOnError) Msg::Exit(1);
        }
      }
#endif
#if defined(__APPLE__)
      else if(argv[i] == "-psn") {
        // the Mac Finder launches programs with a special command line argument
        // of the form -psn_XXX: just ignore it silently (and don't exit!)
        i++;
      }
#endif
      else {
        Msg::Error("Unknown option '%s'", argv[i].c_str());
        PrintUsage(argv[0]);
        Msg::Exit(1);
      }
    }
    else {
      CTX::instance()->files.push_back(argv[i++]);
    }
  }

  if(CTX::instance()->files.empty()) {
    std::string base = (getenv("PWD") ? "" : CTX::instance()->homeDir);
    GModel::current()->setFileName(base + CTX::instance()->defaultFileName);
  }
  else
    GModel::current()->setFileName(CTX::instance()->files[0]);

  if(CTX::instance()->terminal == 99) CTX::instance()->terminal = terminal;
}
