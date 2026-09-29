// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_STATISTICS_H
#define GMSH_GUI_STATISTICS_H

#include <string>
#include <vector>

#include "GuiDialog.h"

// counted when it opens; the quality costs, and waits for Update
class GuiStatistics : public GuiTabbed {
  double s[50];
  // the elements of the adaptive views, as last refined: views, points...
  // trihedra
  double adapted[10];
  double quality[3][101];
  bool qualityDone = false;
  // the averages, minima and maxima of the qualities, and what they were
  // computed for: kept until the mesh changes
  double qualityStats[9];
  std::vector<std::size_t> qualityKey;
  bool visibleOnly = false;
  void compute(bool elementQuality);
  // 0 SICN, 1 Gamma, 2 SIGE, as a curve or on the mesh
  void histogram(int which, bool threeD);

public:
  GuiStatistics();
  void show(const std::string &pane = "");
  void refresh();

protected:
  Ui::Form build() override;
};

#endif
