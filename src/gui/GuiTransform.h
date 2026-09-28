// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_TRANSFORM_H
#define GMSH_GUI_TRANSFORM_H

#include <string>

#include "GuiDialog.h"
#include "GmshDefines.h"

// the mesh extrusion fields are offered only when the action that opened the
// dialog extrudes
class GuiTransform : public GuiTabbed {
public:
  bool extrude = false;
  // what the selection is restricted to: ENT_ALL, ENT_POINT, ENT_CURVE,
  // ENT_SURFACE or ENT_VOLUME
  int selection = ENT_ALL;
  std::string tx = "0", ty = "0", tz = "1"; // translation, extrusion along a line
  std::string ax = "0", ay = "1", az = "0"; // direction of the rotation axis
  std::string px = "0", py = "0", pz = "0", angle = "Pi/4";
  std::string cx = "0", cy = "0", cz = "0", sx = "0.5", sy = "0.5", sz = "0.5";
  std::string sa = "1", sb = "0", sc = "0", sd = "1"; // sa x + sb y + sc z + sd = 0
  bool duplicate = false; // act on a copy instead of on the entities themselves
  bool extrudeMesh = false, recombineMesh = true;
  std::string layers = "5";
  bool recursive = true; // delete the entities on the boundary too
  std::string radius = "0.1"; // fillet
  bool deleteObject = true, deleteTool = true; // boolean operation

  using GuiTabbed::show;
  void show(const std::string &pane, bool extrude);

protected:
  Ui::Form build() override;
};

#endif
