// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_CLASSIFY_H
#define GMSH_GUI_CLASSIFY_H

#include <vector>

#include "GuiDialog.h"

class GEdge;
class MElement;
class MVertex;

class GuiClassify : public GuiDialog {
  // sharper first, then those on the boundary
  std::vector<MElement *> elements;
  struct edge {
    MVertex *v1, *v2;
    double angle;
  };
  std::vector<edge> detected, lonely;
  // handed to the classification and disposed of by it
  GEdge *selected = nullptr;
  double angle = 40.;
  bool boundary = false, onlyEdges = false, parametrizable = false;
  int wasSurfaceFaces = 1, wasSurfaceEdges = 1;
  GEdge *curve();
  void updateEdges();
  void selectElements(bool all);
  void deleteEdges();
  void reset();
  void classify();
  void showOnlyEdges();

protected:
  Ui::Form build() override;
  void load() override;
};

#endif
