// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_HIGH_ORDER_H
#define GMSH_GUI_HIGH_ORDER_H

#include "GuiDialog.h"

class GuiHighOrder : public GuiDialog {
  int order = 2;
  bool incomplete = false, onlyVisible = true, useCAD = true, showLog = false;
  // 0: optimization, 1: elastic analogy, 2: fast curving, 3: boundary layer
  // curving
  int algorithm = 0;
  double thresholdMin, thresholdMax;
  int numLayers, iterMax, passMax;
  double weight = 1., distanceFactor = 12.;
  // 0 fixed, 1 free
  int boundaryNodes = 1;
  // 0: disjoint strong, 1: adaptive one-by-one, 2: disjoint weak
  int strategy = 0;
  double maxAdaptBlob = 2., adaptBlobDistFact = 2.;
  int adaptBlobLayerFact = 2;
  bool cadAvailable = true;
  bool started = false;
  void generate();
  void regularize();

protected:
  Ui::Form build() override;
  void load() override;
};

#endif
