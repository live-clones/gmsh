// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdlib>
#include <map>
#include "selectionDriver.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "OpenFile.h"
#include "Options.h"
#include "findLinks.h"
#include "scriptStringInterface.h"

namespace {
  // the entities of a type, as the status names them
  std::string entityNames(int type)
  {
    switch(type) {
    case ENT_POINT: return "points";
    case ENT_CURVE: return "curves";
    case ENT_SURFACE: return "surfaces";
    case ENT_VOLUME: return "volumes";
    default: return "entities";
    }
  }

  // the type of the entities named "Point", "Curve", "Surface" or "Volume"
  int typeOf(const std::string &what)
  {
    if(what == "Point") return ENT_POINT;
    if(what == "Curve") return ENT_CURVE;
    if(what == "Surface") return ENT_SURFACE;
    if(what == "Volume") return ENT_VOLUME;
    return ENT_ALL;
  }

  int dimOf(int type)
  {
    switch(type) {
    case ENT_POINT: return 0;
    case ENT_CURVE: return 1;
    case ENT_SURFACE: return 2;
    case ENT_VOLUME: return 3;
    default: return -1;
    }
  }

  const char *copyField[4] = {"Apply translation on copy",
                              "Apply rotation on copy", "Apply scaling on copy",
                              "Apply symmetry on copy"};
} // namespace

void selectionDriver::show(int types)
{
  if(types & ENT_POINT) opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  if(types & ENT_CURVE) opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  if(types & ENT_SURFACE) opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  if(types & ENT_VOLUME) opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
}

int selectionDriver::selectionMode(const std::string &mode)
{
  if(mode == "Points") return ENT_POINT;
  if(mode == "Curves") return ENT_CURVE;
  if(mode == "Surfaces") return ENT_SURFACE;
  if(mode == "Volumes") return ENT_VOLUME;
  return ENT_ALL;
}

// All the fields of the operations, with their defaults: those of the
// dialogs of the graphical interface, which take them from here
const std::vector<selectionDriver::field> &selectionDriver::allFields()
{
  static const std::vector<field> fields = {
    {"Selection mode", "All entities|Points|Curves|Surfaces|Volumes",
     "All entities"},
    {"Translation X", "text", "0"},
    {"Translation Y", "text", "0"},
    {"Translation Z", "text", "1"},
    {"Axis point X", "text", "0"},
    {"Axis point Y", "text", "0"},
    {"Axis point Z", "text", "0"},
    {"Axis direction DX", "text", "0"},
    {"Axis direction DY", "text", "1"},
    {"Axis direction DZ", "text", "0"},
    {"Angle", "text", "Pi/4"},
    {"Center X", "text", "0"},
    {"Center Y", "text", "0"},
    {"Center Z", "text", "0"},
    {"Scaling X", "text", "0.5"},
    {"Scaling Y", "text", "0.5"},
    {"Scaling Z", "text", "0.5"},
    {"Symmetry plane coefficient A", "text", "1"},
    {"Symmetry plane coefficient B", "text", "0"},
    {"Symmetry plane coefficient C", "text", "0"},
    {"Symmetry plane coefficient D", "text", "1"},
    {"Apply translation on copy", "check", "0"},
    {"Apply rotation on copy", "check", "0"},
    {"Apply scaling on copy", "check", "0"},
    {"Apply symmetry on copy", "check", "0"},
    {"Extrude mesh", "check", "0"},
    {"Mesh layers", "text", "5"},
    {"Recombine", "check", "1"},
    {"Delete object", "check", "1"},
    {"Delete tool", "check", "1"},
    {"Radius", "text", "0.1"},
    {"Recursive", "check", "1"},
    {"Name", "text", ""},
    {"Tag", "text", ""},
    {"Element size", "text", "0.1"},
    {"Number of points", "text", "10"},
    {"Type", "Progression|Bump|Beta|Progression_HWall|Bump_HWall|Beta_HWall",
     "Progression"},
    {"Parameter", "text", "1"},
    {"Arrangement", "Left|Right|Alternated", "Left"}};
  return fields;
}

void selectionDriver::_use(std::initializer_list<std::string> names)
{
  for(const std::string &name : names)
    for(const field &f : allFields())
      if(f.name == name) _fields.push_back(f);
}

// The operations, by name:
// - curves through points: Line, Circle arc, Ellipse arc, Spline, BSpline,
//   Bezier;
// - surfaces and volumes from their boundaries: Plane Surface, Surface,
//   Volume;
// - transformations of the entities: Translate, Rotate, Scale, Symmetry,
//   Extrude translate, Extrude rotate, Pipe, Delete, Fillet, Split curve, and
//   BooleanIntersection, BooleanUnion, BooleanDifference, BooleanFragments;
// - physical groups: Physical Point, ..., Physical Volume, and Remove
//   Physical Point, ..., Remove Physical Volume;
// - mesh constraints: Size at points, Recombine, Transfinite Curve,
//   Transfinite Surface, Transfinite Volume, Embed Point, Embed Curve, Embed
//   Surface, Compound Curve, Compound Surface;
// - mesh parts: Delete mesh elements, Delete mesh curves, ..., Reverse mesh
//   elements, Reverse mesh curves, ...
selectionDriver::selectionDriver(const std::string &operation,
                                 valueFunction value)
  : _operation(operation), _value(value), _phase(0), _loop(nullptr),
    _meshParts(false), _pickElements(false), _boundingBox(false), _once(false)
{
  const std::string &op = operation;
  // the script the operations add to
  auto file = []() { return GModel::current()->getFileName(); };
  // the transformations: the entities picked, of the selection mode
  auto transform = [&]() {
    _use({"Selection mode"});
    _add(-1);
    _boundingBox = true;
  };
  auto translation = [&]() {
    _use({"Translation X", "Translation Y", "Translation Z"});
  };
  auto rotation = [&]() {
    _use({"Axis point X", "Axis point Y", "Axis point Z", "Axis direction DX",
          "Axis direction DY", "Axis direction DZ", "Angle"});
  };
  auto extrusion = [&]() {
    _use({"Extrude mesh", "Mesh layers", "Recombine"});
  };
  // the start, center... points of a curve, then the curve
  auto curveFromPoints = [&](std::initializer_list<const char *> points) {
    show(ENT_POINT | ENT_CURVE);
    for(const char *p : points) _add(ENT_POINT, std::string(p) + " point", 1);
    _apply = [this, file]() {
      std::vector<int> p;
      for(std::size_t i = 0; i < _phases.size(); i++) p.push_back(_tags(i)[0]);
      if(p.size() == 2)
        scriptAddCurve("Line", p, file());
      else if(p.size() == 3)
        scriptAddCircleArc(p[0], p[1], p[2], file());
      else
        scriptAddEllipseArc(p[0], p[1], p[2], p[3], file());
      return true;
    };
  };

  if(op == "Line")
    curveFromPoints({"start", "end"});
  else if(op == "Circle arc")
    curveFromPoints({"start", "center", "end"});
  else if(op == "Ellipse arc")
    curveFromPoints({"start", "center", "major axis", "end"});
  else if(op == "Spline" || op == "BSpline" || op == "Bezier") {
    show(ENT_POINT | ENT_CURVE);
    _add(ENT_POINT, "control points", 0, false, true);
    _apply = [this, op, file]() {
      std::vector<int> p = _tags(0);
      if(p.size() >= 2) scriptAddCurve(op, p, file());
      return true;
    };
  }
  else if(op == "Plane Surface" || op == "Surface" || op == "Volume") {
    int type = (op == "Volume") ? ENT_SURFACE : ENT_CURVE;
    show(type | (op == "Volume" ? ENT_VOLUME : ENT_SURFACE));
    _loop = List_Create(10, 10, sizeof(int));
    _add(type, op == "Volume" ? "volume boundary" : "surface boundary", 1);
    _add(type, "hole boundaries", 0, true);
    _apply = [this, op, file]() {
      List_T *loops = List_Create(10, 10, sizeof(int));
      for(int i = 0; i < 2; i++)
        for(int n : _tags(i)) List_Add(loops, &n);
      List_Unique(loops, fcmp_absint);
      if(op == "Volume")
        scriptAddVolume(loops, file());
      else
        scriptAddSurface(op, loops, file());
      List_Delete(loops);
      return true;
    };
  }
  else if(op == "Translate") {
    translation();
    _use({copyField[0]});
    transform();
    _apply = [this, file]() {
      if(!_filled({"Translation X", "Translation Y", "Translation Z"}))
        return false;
      scriptTranslate(file(), _picked[0], _get("Translation X"),
                      _get("Translation Y"), _get("Translation Z"),
                      _checked(copyField[0]));
      return true;
    };
  }
  else if(op == "Rotate") {
    rotation();
    _use({copyField[1]});
    transform();
    _apply = [this, file]() {
      if(!_filled({"Axis point X", "Axis point Y", "Axis point Z",
                   "Axis direction DX", "Axis direction DY",
                   "Axis direction DZ", "Angle"}))
        return false;
      scriptRotate(file(), _picked[0], _get("Axis direction DX"),
                   _get("Axis direction DY"), _get("Axis direction DZ"),
                   _get("Axis point X"), _get("Axis point Y"),
                   _get("Axis point Z"), _get("Angle"), _checked(copyField[1]));
      return true;
    };
  }
  else if(op == "Scale") {
    _use({"Center X", "Center Y", "Center Z", "Scaling X", "Scaling Y",
          "Scaling Z", copyField[2]});
    transform();
    _apply = [this, file]() {
      if(!_filled({"Center X", "Center Y", "Center Z", "Scaling X", "Scaling Y",
                   "Scaling Z"}))
        return false;
      scriptDilate(file(), _picked[0], _get("Center X"), _get("Center Y"),
                   _get("Center Z"), _get("Scaling X"), _get("Scaling Y"),
                   _get("Scaling Z"), _checked(copyField[2]));
      return true;
    };
  }
  else if(op == "Symmetry") {
    const char *c[4] = {
      "Symmetry plane coefficient A", "Symmetry plane coefficient B",
      "Symmetry plane coefficient C", "Symmetry plane coefficient D"};
    _use({c[0], c[1], c[2], c[3], copyField[3]});
    transform();
    _apply = [this, file, c]() {
      if(!_filled({c[0], c[1], c[2], c[3]})) return false;
      scriptMirror(file(), _picked[0], _get(c[0]), _get(c[1]), _get(c[2]),
                   _get(c[3]), _checked(copyField[3]));
      return true;
    };
  }
  else if(op == "Extrude translate") {
    translation();
    extrusion();
    transform();
    _apply = [this, file]() {
      if(!_filled({"Translation X", "Translation Y", "Translation Z"}) ||
         (_checked("Extrude mesh") && !_filled({"Mesh layers"})))
        return false;
      scriptExtrude(file(), _picked[0], _get("Translation X"),
                    _get("Translation Y"), _get("Translation Z"),
                    _checked("Extrude mesh"), _get("Mesh layers"),
                    _checked("Recombine"));
      return true;
    };
  }
  else if(op == "Extrude rotate") {
    rotation();
    extrusion();
    transform();
    _apply = [this, file]() {
      if(!_filled({"Axis point X", "Axis point Y", "Axis point Z",
                   "Axis direction DX", "Axis direction DY",
                   "Axis direction DZ", "Angle"}) ||
         (_checked("Extrude mesh") && !_filled({"Mesh layers"})))
        return false;
      scriptProtude(file(), _picked[0], _get("Axis direction DX"),
                    _get("Axis direction DY"), _get("Axis direction DZ"),
                    _get("Axis point X"), _get("Axis point Y"),
                    _get("Axis point Z"), _get("Angle"),
                    _checked("Extrude mesh"), _get("Mesh layers"),
                    _checked("Recombine"));
      return true;
    };
  }
  else if(op == "Pipe") {
    transform();
    _add(ENT_CURVE);
    _apply = [this, file]() {
      scriptAddPipe(file(), _picked[0], _tags(1, 1));
      return true;
    };
  }
  else if(op == "Delete") {
    _use({"Recursive"});
    transform();
    _apply = [this, file]() {
      scriptDeleteEntities(file(), _picked[0], _checked("Recursive"));
      return true;
    };
  }
  else if(op.compare(0, 7, "Boolean") == 0) {
    _use({"Selection mode", "Delete object", "Delete tool"});
    _add(-1, "object");
    _add(-1, "tool", 0, op == "BooleanFragments");
    _apply = [this, op, file]() {
      scriptBoolean(file(), op, _picked[0], _picked[1],
                    _checked("Delete object"),
                    _picked[1].size() ? _checked("Delete tool") : 0);
      return true;
    };
  }
  else if(op == "Fillet") {
    show(ENT_VOLUME | ENT_CURVE);
    _use({"Radius"});
    _add(ENT_VOLUME, "volume");
    _add(ENT_CURVE, "curve");
    _apply = [this, file]() {
      if(!_filled({"Radius"})) return false;
      scriptFillet(file(), _tags(0, 3), _tags(1, 1), _get("Radius"));
      return true;
    };
  }
  else if(op == "Split curve") {
    show(ENT_CURVE | ENT_POINT);
    _add(ENT_CURVE, "curve to split", 1);
    _add(ENT_POINT, "break points", 0, true);
    _once = true;
    _apply = [this, file]() {
      List_T *points = List_Create(5, 5, sizeof(int));
      for(int n : _tags(1)) List_Add(points, &n);
      scriptSplitCurve(_tags(0)[0], points, file());
      List_Delete(points);
      return true;
    };
  }
  else if(op.compare(0, 9, "Physical ") == 0 ||
          op.compare(0, 16, "Remove Physical ") == 0) {
    bool remove = (op[0] == 'R');
    std::string what = op.substr(op.rfind(' ') + 1);
    int type = typeOf(what);
    show(type);
    _use({"Name", "Tag"});
    _add(type);
    _apply = [this, remove, what, type, file]() {
      std::string name = _get("Name");
      int tag = atoi(_get("Tag").c_str());
      // a group of this name or tag already there is added to
      std::map<int, std::vector<GEntity *>> groups;
      GModel::current()->getPhysicalGroups(dimOf(type), groups);
      bool append = (tag && groups.count(tag)) ||
                    (name.size() && GModel::current()->getPhysicalNumber(
                                      dimOf(type), name) >= 0);
      scriptAddRemovePhysicalGroup(file(), what, _tags(0, dimOf(type)), name,
                                   tag, append, remove ? "Remove" : "Add");
      return true;
    };
  }
  else if(op == "Size at points") {
    show(ENT_POINT);
    _use({"Element size"});
    _add(ENT_POINT);
    _apply = [this, file]() {
      if(!_filled({"Element size"})) return false;
      scriptSetMeshSize(file(), _tags(0, 0), _get("Element size"));
      return true;
    };
  }
  else if(op == "Recombine") {
    show(ENT_SURFACE);
    _add(ENT_SURFACE);
    _apply = [this, file]() {
      scriptRecombineSurface(file(), _tags(0, 2));
      return true;
    };
  }
  else if(op == "Compound Curve" || op == "Compound Surface") {
    std::string what = op.substr(9);
    show(typeOf(what));
    _add(typeOf(what));
    _apply = [this, what, file]() {
      scriptSetCompound(file(), what, _tags(0, dimOf(typeOf(what))));
      return true;
    };
  }
  else if(op == "Transfinite Curve") {
    show(ENT_POINT | ENT_CURVE);
    _use({"Number of points", "Type", "Parameter"});
    _add(ENT_CURVE);
    _apply = [this, file]() {
      if(!_filled({"Number of points"})) return false;
      std::vector<int> p = _tags(0);
      scriptSetTransfiniteLine(p, file(), _get("Type"), _get("Parameter"),
                               _get("Number of points"));
      return true;
    };
  }
  else if(op == "Transfinite Surface" || op == "Transfinite Volume") {
    bool surface = (op == "Transfinite Surface");
    show(ENT_POINT | (surface ? ENT_SURFACE : ENT_VOLUME));
    if(surface) _use({"Arrangement"});
    _add(surface ? ENT_SURFACE : ENT_VOLUME, surface ? "surface" : "volume", 1);
    _add(ENT_POINT, "(ordered) boundary points", 0, true, true);
    _apply = [this, surface, file]() {
      std::vector<int> p = _tags(0), q = _tags(1);
      p.insert(p.end(), q.begin(), q.end());
      if(surface && (q.empty() || q.size() == 3 || q.size() == 4))
        scriptSetTransfiniteSurface(p, file(), _get("Arrangement"));
      else if(!surface && (q.empty() || q.size() == 6 || q.size() == 8))
        scriptSetTransfiniteVolume(p, file());
      else
        Msg::Error("Wrong number of points for transfinite %s",
                   surface ? "surface" : "volume");
      return true;
    };
  }
  else if(op.compare(0, 6, "Embed ") == 0) {
    std::string what = op.substr(6);
    int type = typeOf(what);
    show(type);
    _add(type);
    // in a surface or a volume
    _add(ENT_ALL, "entity in which to embed the " + entityNames(type), 1, false,
         true, 12);
    _apply = [this, what, file]() {
      std::vector<int> l = _tags(0);
      scriptEmbed(file(), what, l, _picked[1][0].first, _picked[1][0].second);
      return true;
    };
  }
  else if(op.compare(0, 12, "Delete mesh ") == 0 ||
          op.compare(0, 13, "Reverse mesh ") == 0) {
    bool reverse = (op[0] == 'R');
    std::string what = op.substr(op.rfind(' ') + 1);
    _meshParts = true;
    _pickElements = (what == "elements");
    CTX::instance()->pickElements = _pickElements;
    _add(what == "curves"   ? ENT_CURVE :
         what == "surfaces" ? ENT_SURFACE :
         what == "volumes"  ? ENT_VOLUME :
                              ENT_ALL,
         what);
    _apply = [this, reverse]() {
      // the lock held by another operation: the parts stay picked, to try
      // again
      if(modelBusy()) return false;
      for(MElement *e : _elements)
        if(e->getVisibility() == 2) e->setVisibility(0);
      for(auto &p : _picked[0]) {
        GEntity *ge = GModel::current()->getEntityByTag(p.first, p.second);
        if(ge) ge->setVisibility(0);
      }
      modelLock lock;
      if(reverse)
        GModel::current()->reverseInvisibleElements();
      else
        GModel::current()->removeInvisibleElements();
      _elements.clear();
      CTX::instance()->meshChanged();
      return true;
    };
  }
  else {
    Msg::Error("Unknown operation on selected entities: %s", op.c_str());
    _phase = -1;
    return;
  }
  _picked.resize(_phases.size());
}

selectionDriver::~selectionDriver()
{
  quit();
  if(_loop) List_Delete(_loop);
}

void selectionDriver::_add(int type, const std::string &what, int count,
                           bool optional, bool ordered, int dims)
{ _phases.push_back({type, dims, what, count, optional, ordered || count}); }

std::string selectionDriver::_get(const std::string &name) const
{ return _value ? _value(name) : ""; }

// whether the fields are filled in; if not, an error names the first one
// left empty, which would write an invalid command in the script
bool selectionDriver::_filled(std::initializer_list<const char *> names) const
{
  for(const char *name : names) {
    std::string v = _get(name);
    if(v.find_first_not_of(" \t") == std::string::npos) {
      Msg::Error("Field '%s' is empty", name);
      return false;
    }
  }
  return true;
}

// the tags of what a phase picked, of a dimension or all
std::vector<int> selectionDriver::_tags(int phase, int dim) const
{
  std::vector<int> tags;
  for(auto &p : _picked[phase])
    if(dim < 0 || p.first == dim) tags.push_back(p.second);
  return tags;
}

bool selectionDriver::_anyPicked() const
{
  for(auto &p : _picked)
    if(p.size()) return true;
  return (_loop && List_Nbr(_loop)) || _elements.size();
}

int selectionDriver::type() const
{
  if(!active()) return ENT_NONE;
  int type = _phases[_phase].type;
  return type >= 0 ? type : selectionMode(_get("Selection mode"));
}

std::string selectionDriver::status() const
{
  if(!active()) return "";
  const phase &p = _phases[_phase];
  std::string what = p.what.empty() ? entityNames(type()) : p.what;
  if(p.optional && _picked[_phase].empty()) what += " (if none, press 'e')";
  std::string keys = p.count ? "" : "'e' to end selection";
  if(_anyPicked())
    keys +=
      (keys.empty() ? "" : ", ") + std::string("'u' to undo last selection");
  keys += (keys.empty() ? "" : " or ") + std::string("'q' to abort");
  return "Select " + what + "\n[Press " + keys + "]";
}

bool selectionDriver::step(char ib, const std::vector<GVertex *> &vertices,
                           const std::vector<GEdge *> &edges,
                           const std::vector<GFace *> &faces,
                           const std::vector<GRegion *> &regions,
                           const std::vector<MElement *> &elements)
{
  if(!active()) return false;
  // the model or its mesh changed meanwhile: the elements picked may be gone
  // (the entities are kept by their tags)
  if(_stamps.changed()) _elements.clear();
  std::vector<GEntity *> entities(vertices.begin(), vertices.end());
  entities.insert(entities.end(), edges.begin(), edges.end());
  entities.insert(entities.end(), faces.begin(), faces.end());
  entities.insert(entities.end(), regions.begin(), regions.end());
  bool changed = false;
  switch(ib) {
  case 'l': _pick(entities, elements); break;
  case 'r': _unpick(entities, elements); break;
  case 'u': _undo(); break;
  case 'e':
    if(_phases[_phase].count) break; // the phase ends with its picks
    if(_picked[_phase].empty() && _elements.empty() &&
       !_phases[_phase].optional) {
      Msg::Error("No %s selected",
                 (_phases[_phase].what.empty() ? entityNames(type()) :
                                                 _phases[_phase].what)
                   .c_str());
      break;
    }
    changed = _next();
    break;
  case 'q': quit(); return false;
  }
  // a phase of a number of picks is over once they are all there
  if(active() && _phases[_phase].count &&
     (int)_picked[_phase].size() >= _phases[_phase].count)
    changed = _next();
  if(_meshParts) CTX::instance()->meshChanged();
  _stamps.record();
  return changed;
}

void selectionDriver::_pick(const std::vector<GEntity *> &entities,
                            const std::vector<MElement *> &elements)
{
  if(_pickElements) {
    for(MElement *e : elements) {
      if(e->getVisibility() == 2) continue;
      e->setVisibility(2);
      _elements.push_back(e);
    }
    return;
  }
  const phase &p = _phases[_phase];
  for(GEntity *ge : entities) {
    if(!(p.dims & (1 << ge->dim()))) continue;
    if(_loop) {
      // the boundary being closed, completed with what it is linked to: once
      // it is closed, a curve or surface loop
      int dim = ge->dim(), num = ge->tag();
      int closed =
        dim == 1 ? allEdgesLinked(num, _loop) : allFacesLinked(num, _loop);
      for(int i = 0; i < List_Nbr(_loop); i++) {
        List_Read(_loop, i, &num);
        GEntity *e = GModel::current()->getEntityByTag(dim, std::abs(num));
        if(e) e->setSelection(1);
      }
      if(!closed) continue;
      const std::string file = GModel::current()->getFileName();
      if(dim == 1)
        scriptAddCurveLoop(_loop, file, &num);
      else
        scriptAddSurfaceLoop(_loop, file, &num);
      List_Reset(_loop);
      _picked[_phase].push_back(std::make_pair(-1, num));
      continue;
    }
    if(!p.ordered && ge->getSelection() == 1) continue;
    ge->setSelection(1);
    _picked[_phase].push_back(std::make_pair(ge->dim(), ge->tag()));
    if(p.ordered) break;
  }
}

void selectionDriver::_unpick(const std::vector<GEntity *> &entities,
                              const std::vector<MElement *> &elements)
{
  for(MElement *e : elements) {
    auto it = std::find(_elements.begin(), _elements.end(), e);
    if(it == _elements.end()) continue;
    e->setVisibility(1);
    _elements.erase(it);
  }
  auto &picked = _picked[_phase];
  for(GEntity *ge : entities) {
    auto it = std::find(picked.begin(), picked.end(),
                        std::make_pair(ge->dim(), ge->tag()));
    if(it == picked.end()) continue;
    picked.erase(it);
    ge->setSelection(0);
  }
}

void selectionDriver::_undo()
{
  // the last entity of the boundary being closed
  if(_loop && List_Nbr(_loop)) {
    int num;
    List_Read(_loop, List_Nbr(_loop) - 1, &num);
    GEntity *e =
      GModel::current()->getEntityByTag(dimOf(type()), std::abs(num));
    if(e) e->setSelection(0);
    List_Pop(_loop);
    return;
  }
  if(_elements.size()) {
    _elements.back()->setVisibility(1);
    _elements.pop_back();
    return;
  }
  while(_phase > 0 && _picked[_phase].empty()) _phase--;
  if(_picked[_phase].empty()) return;
  std::pair<int, int> p = _picked[_phase].back();
  _picked[_phase].pop_back();
  GEntity *e = (p.first < 0) ?
                 nullptr :
                 GModel::current()->getEntityByTag(p.first, p.second);
  if(e && std::find(_picked[_phase].begin(), _picked[_phase].end(), p) ==
            _picked[_phase].end())
    e->setSelection(0);
}

// the phase is over: the next one, or the operation carried out with all that
// was picked (true), unless a value is missing
bool selectionDriver::_next()
{
  if(_phase + 1 < (int)_phases.size()) {
    _phase++;
    return false;
  }
  if(!_apply()) return false;
  _done = _picked;
  _clear();
  if(_boundingBox) SetBoundingBox();
  if(_once) quit();
  return true;
}

void selectionDriver::_clear()
{
  for(auto &p : _picked) p.clear();
  if(_loop) List_Reset(_loop);
  // (the elements still marked are put back, unless they may be gone)
  if(!_stamps.changed())
    for(MElement *e : _elements)
      if(e->getVisibility() == 2) e->setVisibility(1);
  _elements.clear();
  _phase = 0;
  GModel::current()->setSelection(0);
}

void selectionDriver::quit()
{
  if(!active()) return;
  _clear();
  _phase = -1;
  if(_meshParts) {
    CTX::instance()->pickElements = 0;
    CTX::instance()->meshChanged();
  }
}
