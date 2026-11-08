// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What a web page calls (through ccall) for the modules of the graphical
// interface's tree, where the Gmsh API has nothing of the kind: the shapes
// added to the model's script, as the dialog of the graphical interface adds
// them (elementaryContextWindow::addShape() in src/fltk/contextWindow.cpp)

#if defined(__EMSCRIPTEN__)

#include <fstream>
#include <sstream>
#include <emscripten.h>
#include "Context.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "OpenFile.h"
#include "scriptStringInterface.h"

namespace {
  long fileSize(const std::string &name)
  {
    std::ifstream in(name, std::ios::binary | std::ios::ate);
    return in ? (long)in.tellg() : -1;
  }
} // namespace

extern "C" {

// Add a shape (Disk, Rectangle, Sphere, Cylinder, Box, Torus, Cone or Wedge)
// to the script of the current model, with its values in the order of the
// dialog's fields (expressions of the .geo language, separated by new lines;
// an empty one is left out): returns the number of errors, the command being
// taken back from the script if there are any. A model that is not a .geo
// file is given a .geo file that merges it, as the dialog's default answer
EMSCRIPTEN_KEEPALIVE int gmshWebAddShape(const char *shape, const char *values)
{
  std::vector<std::string> v;
  std::istringstream in(values);
  for(std::string s; std::getline(in, s);) v.push_back(s);
  v.resize(9);
  const std::string s(shape), f = GModel::current()->getFileName();
  const int errors = Msg::GetErrorCount();
  const long size = fileSize(f);
  // (the questions of the script, answered by default, not on the console,
  // which a browser would ask with a prompt)
  const int noPopup = CTX::instance()->noPopup;
  CTX::instance()->noPopup = 1;
  try {
    if(s == "Disk") scriptAddDisk(f, v[0], v[1], v[2], v[3], v[4]);
    else if(s == "Rectangle")
      scriptAddRectangle(f, v[0], v[1], v[2], v[3], v[4], v[5]);
    else if(s == "Sphere")
      scriptAddSphere(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
    else if(s == "Cylinder")
      scriptAddCylinder(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
    else if(s == "Box") scriptAddBox(f, v[0], v[1], v[2], v[3], v[4], v[5]);
    else if(s == "Torus")
      scriptAddTorus(f, v[0], v[1], v[2], v[3], v[4], v[5]);
    else if(s == "Cone")
      scriptAddCone(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
    else if(s == "Wedge")
      scriptAddWedge(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
    else
      Msg::Error("Unknown shape '%s'", shape);
  } catch(...) {
    Msg::Error("Could not add the %s", shape);
  }
  // (counted before the script is read again, which resets the count)
  const int added = Msg::GetErrorCount() - errors;
  if(added && f == GModel::current()->getFileName() && fileSize(f) != size)
    scriptRemoveLastCommand(f);
  CTX::instance()->noPopup = noPopup;
  GModel::current()->setSelection(0);
  SetBoundingBox();
  return added;
}

} // extern "C"

#endif
