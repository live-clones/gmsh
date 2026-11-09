// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SELECTION_DRIVER_H
#define SELECTION_DRIVER_H

#include <functional>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include "Context.h"
#include "ListUtils.h"

class GEntity;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

// The operations of the Geometry and Mesh modules on entities picked in the
// scene (a curve through points, a surface from its boundary, a translation, a
// boolean, a physical group, a transfinite constraint, the deletion of mesh
// elements, ...), whatever shows the scene. The host begins a selection of
// type() (see sceneView::beginSelection()), shows status(), and gives each
// answer of the selection (sceneView::selectionStep()) to step(), which writes
// the script or changes the mesh once all is picked, then starts again, until
// 'q'. The values an operation needs besides (the translation vector, the name
// of a group, ...) are its fields(), read by name through the function the
// host gives, from its dialog or its form.
//
// An operation is a series of phases, each picking entities of a type: a set
// of them, ended by 'e', or a given number of them one click at a time (the
// points of a line). 'u' takes back the last entity picked, going back to the
// phase before if there is none in this one.
class selectionDriver {
public:
  // the value of a field, "" if it is empty; "1" or "0" for a check box
  typedef std::function<std::string(const std::string &name)> valueFunction;
  struct field {
    // kind: "text", "check", or the choices, separated by '|'
    std::string name, kind, value;
  };

private:
  struct phase {
    // what it picks: ENT_*, or -1 for what the "Selection mode" field says;
    // the dimensions it takes of what is picked (bits)
    int type, dims;
    // what the status names (by default, the entities of its type)
    std::string what;
    // the picks that end it, 0 if 'e' does
    int count;
    // whether 'e' ends it with nothing picked
    bool optional;
    // one entity per click, in the order of the clicks, the same one again
    // if it is clicked again (the points of a spline)
    bool ordered;
  };
  std::string _operation;
  valueFunction _value;
  std::vector<field> _fields;
  std::vector<phase> _phases;
  // the current phase (-1 once the operation is over), what each phase
  // picked (dimension, tag), and what they had picked when the operation was
  // last carried out
  int _phase;
  std::vector<std::vector<std::pair<int, int>>> _picked, _done;
  // the phases pick boundaries (Plane Surface, Surface, Volume): the curves or
  // surfaces of the one being closed; each closed one is a curve or surface
  // loop, picked with dimension -1: the new ones (by tag) are added to the
  // script with the surface or volume, not before (an undo or a quit leaves
  // nothing behind)
  List_T *_loop;
  std::map<int, std::vector<int>> _newLoops;
  // mesh parts are picked (Delete or Reverse mesh ...), drawn again at each
  // step; mesh elements (Delete or Reverse mesh elements), marked with the
  // visibility 2, while the entities and the mesh stay as they were
  bool _meshParts, _pickElements;
  std::vector<MElement *> _elements;
  modelStamps _stamps;
  // the bounding box made again after the operation; the operation stops once
  // it is carried out
  bool _boundingBox, _once;
  // what the operation does with what was picked: false if a value is
  // missing, the selection being kept to try again
  std::function<bool()> _apply;

  // the fields of these names used by the operation
  void _use(const std::vector<std::string> &names);
  void _add(int type, const std::string &what = "", int count = 0,
            bool optional = false, bool ordered = false, int dims = 15);
  std::string _get(const std::string &name) const;
  bool _checked(const std::string &name) const { return _get(name) == "1"; }
  bool _filled(const std::vector<std::string> &names) const;
  std::vector<int> _tags(int phase, int dim = -1) const;
  bool _anyPicked() const;
  void _pick(const std::vector<GEntity *> &entities,
             const std::vector<MElement *> &elements);
  void _unpick(const std::vector<GEntity *> &entities,
               const std::vector<MElement *> &elements);
  void _undo();
  bool _next();
  void _clear();

public:
  // starts the operation (see selectionDriver.cpp for their names)
  selectionDriver(const std::string &operation, valueFunction value);
  ~selectionDriver();
  const std::string &operation() const { return _operation; }
  const std::vector<field> &fields() const { return _fields; }
  // the fields of all the operations
  static const std::vector<field> &allFields();
  // What an operation is, read from its name: on the parts of the mesh
  // ("Delete mesh curves", "Reverse mesh elements": remove is true for a
  // deletion, what is "curves"), on a physical group ("Physical Curve",
  // "Remove Physical Curve": what is "Curve"), a boolean ("BooleanUnion"), or
  // none of these (on the entities of the script, the mesh constraints...)
  enum operationKind { OnScript, OnMeshParts, OnPhysical, OnBoolean };
  struct kind {
    operationKind on;
    bool remove;
    std::string what;
  };
  static kind kindOf(const std::string &operation);
  // the type of the entities a value of the "Selection mode" field picks
  static int selectionMode(const std::string &mode);
  // the entities of the types drawn, to be picked
  static void show(int types);
  // the entities of each dimension: their type (ENT_POINT...), their name
  // ("Point"...) and how a sentence names several ("points"...)
  struct entityKind {
    int type;
    const char *name, *names;
  };
  static const entityKind entityKinds[4];
  bool active() const { return _phase >= 0; }
  // the clicks pick mesh elements (see sceneView::beginSelection())
  bool pickElements() const { return _pickElements; }
  // what to pick now, and the two lines that say so
  int type() const;
  std::string status() const;
  // an answer of the selection ('l', 'r', 'u', 'e' or 'q') and what it
  // picked: true if the operation was carried out (the script or the mesh
  // changed)
  bool step(char ib, const std::vector<GVertex *> &vertices,
            const std::vector<GEdge *> &edges,
            const std::vector<GFace *> &faces,
            const std::vector<GRegion *> &regions,
            const std::vector<MElement *> &elements);
  // what the phases had picked when the operation was last carried out
  const std::vector<std::vector<std::pair<int, int>>> &done() const
  { return _done; }
  // the operation is over: nothing stays picked
  void quit();
};

#endif
