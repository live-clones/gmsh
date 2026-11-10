// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include "selectionDriver.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "OpenFile.h"
#include "Options.h"
#include "findLinks.h"
#include "scriptStringInterface.h"

const selectionDriver::entityKind selectionDriver::entityKinds[4] = {
  {ENT_POINT, "Point", "points"},
  {ENT_CURVE, "Curve", "curves"},
  {ENT_SURFACE, "Surface", "surfaces"},
  {ENT_VOLUME, "Volume", "volumes"}};

namespace {
  // the dimension of the entities of a type, or -1 for several types
  int dimOf(int type)
  {
    for(int dim = 0; dim < 4; dim++)
      if(selectionDriver::entityKinds[dim].type == type) return dim;
    return -1;
  }

  // the entities of a type, as the status names them
  std::string entityNames(int type)
  {
    int dim = dimOf(type);
    return dim < 0 ? "entities" : selectionDriver::entityKinds[dim].names;
  }

  // the type of the entities named "Point", "Curve", "Surface" or "Volume"
  int typeOf(const std::string &what)
  {
    for(auto &k : selectionDriver::entityKinds)
      if(what == k.name) return k.type;
    return ENT_ALL;
  }

  // the type of the entities named "points", "curves"... (all for
  // "elements")
  int typeOfNames(const std::string &names)
  {
    for(auto &k : selectionDriver::entityKinds)
      if(names == k.names) return k.type;
    return ENT_ALL;
  }

  // the last word of the name of an operation ("define_embed_curve"), and the
  // entity it names, as the .geo language does ("Curve")
  std::string lastWord(const std::string &op)
  {
    return op.substr(op.rfind('_') + 1);
  }
  std::string entityOf(const std::string &op)
  {
    std::string what = lastWord(op);
    if(what.size()) what[0] = toupper(what[0]);
    return what;
  }

  // the commands of the .geo language the operations of these names add
  const std::map<std::string, std::string> geoCommands = {
    {"add_spline", "Spline"},
    {"add_bspline", "BSpline"},
    {"add_bezier", "Bezier"},
    {"add_plane_surface", "Plane Surface"},
    {"add_surface_filling", "Surface"},
    {"boolean_intersection", "BooleanIntersection"},
    {"boolean_union", "BooleanUnion"},
    {"boolean_difference", "BooleanDifference"},
    {"boolean_fragments", "BooleanFragments"}};

  const char *copyField[4] = {"Apply translation on copy",
                              "Apply rotation on copy", "Apply scaling on copy",
                              "Apply symmetry on copy"};

  // the fields of the transformations, as the operations use them
  const std::vector<std::string> translationFields = {
    "Translation X", "Translation Y", "Translation Z"};
  const std::vector<std::string> rotationFields = {"Axis point X",
                                                   "Axis point Y",
                                                   "Axis point Z",
                                                   "Axis direction DX",
                                                   "Axis direction DY",
                                                   "Axis direction DZ",
                                                   "Angle"};
  const std::vector<std::string> scalingFields = {
    "Center X", "Center Y", "Center Z", "Scaling X", "Scaling Y", "Scaling Z"};
  const std::vector<std::string> symmetryFields = {
    "Symmetry plane coefficient A", "Symmetry plane coefficient B",
    "Symmetry plane coefficient C", "Symmetry plane coefficient D"};
} // namespace

void selectionDriver::show(int types)
{
  double (*draw[4])(int, int, double) = {
    opt_geometry_points, opt_geometry_curves, opt_geometry_surfaces,
    opt_geometry_volumes};
  for(int dim = 0; dim < 4; dim++)
    if(types & entityKinds[dim].type) draw[dim](0, GMSH_SET | GMSH_GUI, 1);
}

selectionDriver::kind selectionDriver::kindOf(const std::string &op)
{
  auto starts = [&op](const char *s) {
    return op.compare(0, strlen(s), s) == 0;
  };
  if(starts("mesh_delete_")) return {OnMeshParts, true, lastWord(op)};
  if(starts("mesh_reverse_")) return {OnMeshParts, false, lastWord(op)};
  if(starts("physical_add_")) return {OnPhysical, false, entityOf(op)};
  if(starts("physical_remove_")) return {OnPhysical, true, entityOf(op)};
  if(starts("boolean_")) return {OnBoolean, false, ""};
  return {OnScript, false, ""};
}

int selectionDriver::selectionMode(const std::string &mode)
{
  // "Points"... (see the "Selection mode" field below)
  for(auto &k : entityKinds)
    if(mode == std::string(k.name) + "s") return k.type;
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

void selectionDriver::_use(const std::vector<std::string> &names)
{
  for(const std::string &name : names)
    for(const field &f : allFields())
      if(f.name == name) _fields.push_back(f);
}

// The operations, by name:
// - curves through points: add_line, add_circle_arc, add_ellipse_arc,
//   add_spline, add_bspline, add_bezier;
// - surfaces and volumes from their boundaries: add_plane_surface,
//   add_surface_filling, add_volume;
// - transformations of the entities: translate, rotate, scale, symmetry,
//   extrude_translate, extrude_rotate, extrude_pipe, delete, fillet,
//   split_curve, and boolean_intersection, boolean_union, boolean_difference,
//   boolean_fragments;
// - physical groups: physical_add_point, ..., physical_add_volume, and
//   physical_remove_point, ..., physical_remove_volume;
// - mesh constraints: define_size_at_points, define_recombine,
//   define_transfinite_curve, define_transfinite_surface,
//   define_transfinite_volume, define_embed_point, define_embed_curve,
//   define_embed_surface, define_compound_curve, define_compound_surface;
// - mesh parts: mesh_delete_elements, mesh_delete_curves, ...,
//   mesh_reverse_elements, mesh_reverse_curves, ...
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
  auto translation = [&]() { _use(translationFields); };
  auto rotation = [&]() { _use(rotationFields); };
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

  if(op == "add_line")
    curveFromPoints({"start", "end"});
  else if(op == "add_circle_arc")
    curveFromPoints({"start", "center", "end"});
  else if(op == "add_ellipse_arc")
    curveFromPoints({"start", "center", "major axis", "end"});
  else if(op == "add_spline" || op == "add_bspline" || op == "add_bezier") {
    show(ENT_POINT | ENT_CURVE);
    _add(ENT_POINT, "control points", 0, false, true);
    std::string command = geoCommands.at(op);
    _apply = [this, command, file]() {
      std::vector<int> p = _tags(0);
      if(p.size() >= 2) scriptAddCurve(command, p, file());
      return true;
    };
  }
  else if(op == "add_plane_surface" || op == "add_surface_filling" ||
          op == "add_volume") {
    bool volume = (op == "add_volume");
    int type = volume ? ENT_SURFACE : ENT_CURVE;
    show(type | (volume ? ENT_VOLUME : ENT_SURFACE));
    _loop = List_Create(10, 10, sizeof(int));
    _add(type, volume ? "volume boundary" : "surface boundary", 1);
    _add(type, "hole boundaries", 0, true);
    _apply = [this, volume, op, file]() {
      List_T *loops = List_Create(10, 10, sizeof(int));
      for(int i = 0; i < 2; i++)
        for(int n : _tags(i)) List_Add(loops, &n);
      List_Unique(loops, fcmp_absint);
      // the new loops first
      int dim = volume ? 2 : 1;
      for(int i = 0; i < List_Nbr(loops); i++) {
        int n;
        List_Read(loops, i, &n);
        auto it = _newLoops.find(std::abs(n));
        if(it == _newLoops.end()) continue;
        List_T *l = List_Create(10, 10, sizeof(int));
        for(int c : it->second) List_Add(l, &c);
        scriptAddLoop(dim, l, it->first, file());
        List_Delete(l);
      }
      if(volume)
        scriptAddVolume(loops, file());
      else
        scriptAddSurface(geoCommands.at(op), loops, file());
      List_Delete(loops);
      return true;
    };
  }
  else if(op == "translate") {
    translation();
    _use({copyField[0]});
    transform();
    _apply = [this, file]() {
      if(!_filled(translationFields)) return false;
      scriptTranslate(file(), _picked[0], _get("Translation X"),
                      _get("Translation Y"), _get("Translation Z"),
                      _checked(copyField[0]));
      return true;
    };
  }
  else if(op == "rotate") {
    rotation();
    _use({copyField[1]});
    transform();
    _apply = [this, file]() {
      if(!_filled(rotationFields)) return false;
      scriptRotate(file(), _picked[0], _get("Axis direction DX"),
                   _get("Axis direction DY"), _get("Axis direction DZ"),
                   _get("Axis point X"), _get("Axis point Y"),
                   _get("Axis point Z"), _get("Angle"), _checked(copyField[1]));
      return true;
    };
  }
  else if(op == "scale") {
    _use(scalingFields);
    _use({copyField[2]});
    transform();
    _apply = [this, file]() {
      if(!_filled(scalingFields)) return false;
      scriptDilate(file(), _picked[0], _get("Center X"), _get("Center Y"),
                   _get("Center Z"), _get("Scaling X"), _get("Scaling Y"),
                   _get("Scaling Z"), _checked(copyField[2]));
      return true;
    };
  }
  else if(op == "symmetry") {
    _use(symmetryFields);
    _use({copyField[3]});
    transform();
    _apply = [this, file]() {
      if(!_filled(symmetryFields)) return false;
      scriptMirror(file(), _picked[0], _get(symmetryFields[0]),
                   _get(symmetryFields[1]), _get(symmetryFields[2]),
                   _get(symmetryFields[3]), _checked(copyField[3]));
      return true;
    };
  }
  else if(op == "extrude_translate") {
    translation();
    extrusion();
    transform();
    _apply = [this, file]() {
      if(!_filled(translationFields) ||
         (_checked("Extrude mesh") && !_filled({"Mesh layers"})))
        return false;
      scriptExtrude(file(), _picked[0], _get("Translation X"),
                    _get("Translation Y"), _get("Translation Z"),
                    _checked("Extrude mesh"), _get("Mesh layers"),
                    _checked("Recombine"));
      return true;
    };
  }
  else if(op == "extrude_rotate") {
    rotation();
    extrusion();
    transform();
    _apply = [this, file]() {
      if(!_filled(rotationFields) ||
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
  else if(op == "extrude_pipe") {
    transform();
    _add(ENT_CURVE);
    _apply = [this, file]() {
      scriptAddPipe(file(), _picked[0], _tags(1, 1));
      return true;
    };
  }
  else if(op == "delete") {
    _use({"Recursive"});
    transform();
    _apply = [this, file]() {
      scriptDeleteEntities(file(), _picked[0], _checked("Recursive"));
      return true;
    };
  }
  else if(kindOf(op).on == OnBoolean) {
    _use({"Selection mode", "Delete object", "Delete tool"});
    _add(-1, "object");
    _add(-1, "tool", 0, op == "boolean_fragments");
    _apply = [this, op, file]() {
      scriptBoolean(file(), geoCommands.at(op), _picked[0], _picked[1],
                    _checked("Delete object"),
                    _picked[1].size() ? _checked("Delete tool") : 0);
      return true;
    };
  }
  else if(op == "fillet") {
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
  else if(op == "split_curve") {
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
  else if(kindOf(op).on == OnPhysical) {
    bool remove = kindOf(op).remove;
    std::string what = kindOf(op).what;
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
  else if(op == "define_size_at_points") {
    show(ENT_POINT);
    _use({"Element size"});
    _add(ENT_POINT);
    _apply = [this, file]() {
      if(!_filled({"Element size"})) return false;
      scriptSetMeshSize(file(), _tags(0, 0), _get("Element size"));
      return true;
    };
  }
  else if(op == "define_recombine") {
    show(ENT_SURFACE);
    _add(ENT_SURFACE);
    _apply = [this, file]() {
      scriptRecombineSurface(file(), _tags(0, 2));
      return true;
    };
  }
  else if(op == "define_compound_curve" || op == "define_compound_surface") {
    std::string what = entityOf(op);
    show(typeOf(what));
    _add(typeOf(what));
    _apply = [this, what, file]() {
      scriptSetCompound(file(), what, _tags(0, dimOf(typeOf(what))));
      return true;
    };
  }
  else if(op == "define_transfinite_curve") {
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
  else if(op == "define_transfinite_surface" ||
          op == "define_transfinite_volume") {
    bool surface = (op == "define_transfinite_surface");
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
  else if(op.compare(0, 13, "define_embed_") == 0) {
    std::string what = entityOf(op);
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
  else if(kindOf(op).on == OnMeshParts) {
    bool reverse = !kindOf(op).remove;
    std::string what = kindOf(op).what;
    _meshParts = true;
    _pickElements = (what == "elements");
    _add(typeOfNames(what), what);
    _apply = [this, reverse]() {
      std::set<GEntity *> entities;
      for(auto &p : _picked[0]) {
        GEntity *ge = GModel::current()->getEntityByTag(p.first, p.second);
        if(ge) entities.insert(ge);
      }
      std::set<MElement *> elements;
      for(MElement *e : _elements) {
        if(e->getVisibility() == 2) e->setVisibility(1);
        elements.insert(e);
      }
      modelLock lock;
      if(reverse)
        GModel::current()->reverseElements(entities, elements);
      else
        GModel::current()->removeElements(entities, elements);
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
bool selectionDriver::_filled(const std::vector<std::string> &names) const
{
  for(const std::string &name : names) {
    std::string v = _get(name);
    if(v.find_first_not_of(" \t") == std::string::npos) {
      Msg::Error("Field '%s' is empty", name.c_str());
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
  keys += (keys.empty() ? "" : " or ") + std::string("Escape to abort");
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
      // the loop of the model, or a new one picked before (the same curves
      // or surfaces, as RecognizeLineLoop() compares them), or a new one
      std::vector<int> l, key;
      for(int i = 0; i < List_Nbr(_loop); i++) {
        int c;
        List_Read(_loop, i, &c);
        l.push_back(c);
        key.push_back(std::abs(c));
      }
      std::sort(key.begin(), key.end());
      int after = _newLoops.empty() ? 0 : _newLoops.rbegin()->first + 1;
      if(!scriptFindLoop(dim, _loop, &num, after)) {
        for(auto &n : _newLoops) {
          std::vector<int> k;
          for(int c : n.second) k.push_back(std::abs(c));
          std::sort(k.begin(), k.end());
          if(k == key) num = n.first;
        }
        if(!_newLoops.count(num)) _newLoops[num] = l;
      }
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
  if(p.first < 0) _newLoops.erase(p.second);
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
  // the lock held by another operation (whose events the interface
  // processes): nothing done, the picks stay, to try again
  if(modelBusy()) return false;
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
  _newLoops.clear();
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
  if(_meshParts) CTX::instance()->meshChanged();
}
