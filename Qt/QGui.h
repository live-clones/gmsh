// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _Q_GUI_H_
#define _Q_GUI_H_

#include <string>
#include <vector>

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

class graphicWindow;
class drawContext;

class QGui{
 private:
  static QGui *_instance;
  graphicWindow *_graphicWindow;
 public:
  std::vector<GVertex*> selectedVertices;
  std::vector<GEdge*> selectedEdges;
  std::vector<GFace*> selectedFaces;
  std::vector<GRegion*> selectedRegions;
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
