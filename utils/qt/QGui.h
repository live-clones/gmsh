// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef Q_GUI_H
#define Q_GUI_H

#include <string>
#include <vector>

class GPoint;
class GCurve;
class GSurface;
class GVolume;
class MElement;

class graphicWindow;
class drawContext;

class QGui{
 private:
  static QGui *_instance;
  graphicWindow *_graphicWindow;
 public:
  std::vector<GPoint*> selectedVertices;
  std::vector<GCurve*> selectedEdges;
  std::vector<GSurface*> selectedFaces;
  std::vector<GVolume*> selectedRegions;
  std::vector<MElement*> selectedElements;
 public:
  QGui(int argc, char **argv);
  ~QGui(){}
  // return the single static instance of the GUI
  static QGui *instance(int argc=0, char **argv=0);
  // check if the GUI is available
  static bool available(){ return (_instance != 0); }
  // get draw context
  drawContext *getDrawContext();
};

#endif
