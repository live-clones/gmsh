// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The ONELAB loop of the FLTK graphical user interface (see onelabCheck() and
// onelabCompute(), on onelabUtils::onelabLoop) on a script: checked, then
// computed, which meshes it; the interface is idle again after each
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "gmsh.h"
#include "FlGui.h"
#include "onelabGroup.h"
#include "GmshMessage.h"

// no display: the test is skipped (ctest reads 77 as skipped)
static bool noDisplay()
{
#if defined(__linux__)
  return !getenv("DISPLAY") && !getenv("WAYLAND_DISPLAY");
#else
  return false;
#endif
}

static int fails = 0;

static void check(bool ok, const std::string &what)
{
  printf("%s %s\n", ok ? "ok  " : "FAIL", what.c_str());
  if(!ok) fails++;
}

static std::size_t nodes()
{
  std::vector<std::size_t> tags;
  std::vector<double> coord, param;
  gmsh::model::mesh::getNodes(tags, coord, param);
  return tags.size();
}

int main(int argc, char **argv)
{
  if(noDisplay()) return 77;
  {
    std::ofstream f("gui_onelab.geo");
    f << "SetFactory(\"OpenCASCADE\");\nBox(1) = {0, 0, 0, 1, 1, 1};\n"
         "MeshSize {:} = 0.3;\n";
  }
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::fltk::initialize();
  gmsh::open("gui_onelab.geo");
  Msg::ResetErrorCounter();
  onelabCheck();
  check(!Msg::GetErrorCount(), "check: no error");
  check(!solverBusy(), "check: idle again");
  onelabCompute();
  check(!Msg::GetErrorCount(), "compute: no error");
  check(nodes() > 0, "compute: the model is meshed");
  check(!solverBusy(), "compute: idle again");
  printf("%d failure(s)\n", fails);
  gmsh::fltk::finalize();
  gmsh::finalize();
  remove("gui_onelab.geo");
  return fails ? 1 : 0;
}
