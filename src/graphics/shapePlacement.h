// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SHAPE_PLACEMENT_H
#define SHAPE_PLACEMENT_H

#include <functional>
#include <string>
#include <vector>

class drawContext;
class sceneTool;

// The placing of a shape of the script (see scriptShapes() in
// scriptStringInterface.h), as both graphical interfaces do it. The values of
// its fields are kept as typed (expressions of the .geo language); its
// position, the first three fields, is set by a click: on the model under
// the pointer, else on the work plane, the coordinates typed staying as they
// are (locked); while the pointer moves, a mark shows where a click would put
// it. The scenes draw the work plane's grid, the shape at its position and
// marks that help reading where it is (as the transient geometry of
// drawContext). The interface shows the fields, the locks and the plane, and
// shows them again when the scene changes them (changes()).
class shapePlacement {
public:
  enum Plane { PlaneXY = 0, PlaneYZ, PlaneXZ, PlaneView };

private:
  static shapePlacement *_current;
  int _shape;
  std::vector<std::string> _values;
  bool _locked[3] = {false, false, false};
  Plane _plane = PlaneXY;
  int _changes = 0;
  std::function<void()> _changed;
  // where a click would put the position, if the pointer is over the scene
  bool _hoverOn = false;
  double _hover[3] = {0., 0., 0.};
  // the shape just added is drawn, not its preview, until a field changes
  bool _added = false;
  void _changedByScene();
  void _drawGrid(drawContext *ctx) const;
  void _drawPreview() const;

public:
  // the placement under way, or null
  static shapePlacement *current() { return _current; }
  // place shape (its index in scriptShapes(); not the parameter, 0), the
  // fields starting with the given values; changed() is called when the
  // scene changes the values or the locks (a click, a key), for the interface
  // to show them again
  static void start(int shape, const std::vector<std::string> &values,
                    std::function<void()> changed = nullptr);
  static void stop();
  int shape() const { return _shape; }
  const std::vector<std::string> &values() const { return _values; }
  // a field typed in the interface: a coordinate of the position so typed
  // stays as it is (it is locked)
  void setValue(std::size_t i, const std::string &value);
  bool locked(int i) const { return i >= 0 && i < 3 && _locked[i]; }
  void setLocked(int i, bool on);
  // from a key: the lock of coordinate i toggled, or all but i locked
  void toggleLock(int i, bool allBut);
  Plane plane() const { return _plane; }
  void setPlane(Plane p) { _plane = p; }
  // how many times the scene changed the values or the locks
  int changes() const { return _changes; }
  // the position, if its fields evaluate
  bool position(double xyz[3]) const;
  // the point of the work plane under the point (x, y) of the window of ctx:
  // the plane XY, YZ or XZ through the locked coordinates of the position
  // (else through the origin), or the plane facing the viewer through the
  // center of gravity (also when the line of sight runs along the plane);
  // snapped (Geometry.Snap), and the locked coordinates kept
  void planePoint(drawContext *ctx, double x, double y, double xyz[3]) const;
  // where the pointer is, a point of the model or of the work plane (none:
  // nullptr), and where a click would so put the position (null if nowhere)
  void hover(const double *xyz);
  const double *hovered() const { return _hoverOn ? _hover : nullptr; }
  // the work plane, in words ("the plane z = 0")
  std::string planeName() const;
  // a click there: the position, but its locked coordinates
  void drop(const double xyz[3]);
  // the shape added to the script with the values of its fields: false if it
  // was not
  bool add();
  // what the scenes draw (see drawContext::setDrawGeomTransientFunction())
  static void draw(void *context);
};

// the tool that places the shape (the clicks of a scene: its position; 'e':
// the shape added; Escape: the placement stopped), and what finished() does
// when it ends
sceneTool *newPlacementTool(std::function<void()> finished = nullptr);

#endif
