// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the list of entities and their state come from VisibilityList; here, hiding
// by number, by picking, and what each graphic window shows

#include "GmshConfig.h"

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Tree.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "VisibilityList.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "GModel.h"
#include "MElement.h"
#include "MVertex.h"
#include "Options.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

namespace {

  GuiVisibility &_dialog() { return Gui::instance().visibility; }

  // put into the model when one presses Apply
  struct picking {
    std::vector<char> what;
    std::string of; // what the list was of when it was last read
  };

  picking &_picked()
  {
    static picking state;
    return state;
  }

  picking &_pickedTree()
  {
    static picking state;
    return state;
  }

  VisibilityList::VisibilityType _type()
  { return (VisibilityList::VisibilityType)_dialog().type; }

  // an entity, a model, or nothing for a heading
  struct treeNode {
    int depth;
    std::string label;
    GEntity *entity;
    GModel *model;
  };

  std::vector<treeNode> &_tree()
  {
    static std::vector<treeNode> lines;
    return lines;
  }

  // a model of more than ten thousand entities is not put in a tree unless one
  // insists
  bool &_treeWanted()
  {
    static bool wanted = false;
    return wanted;
  }

  int _numEntities()
  {
    int n = 0;
    for(std::size_t i = 0; i < GModel::list.size(); i++)
      n += GModel::list[i]->getNumRegions() + GModel::list[i]->getNumFaces() +
           GModel::list[i]->getNumEdges() + GModel::list[i]->getNumVertices();
    return n;
  }

  void _addLine(int depth, const std::string &label, GEntity *e = nullptr,
                GModel *m = nullptr)
  {
    treeNode line;
    line.depth = depth;
    line.label = label;
    line.entity = e;
    line.model = m;
    _tree().push_back(line);
  }

  std::string _named(GEntity *e)
  {
    const char *const kind[4] = {"Point", "Curve", "Surface", "Volume"};
    std::string out =
      std::string(kind[e->dim()]) + " " + std::to_string(e->tag());
    std::string name = e->model()->getElementaryName(e->dim(), e->tag());
    if(name.size()) out += " - " + name;
    return out;
  }

  void _addVertex(GVertex *v, int depth);
  void _addEdge(GEdge *e, int depth);
  void _addFace(GFace *f, int depth);

  void _addVertex(GVertex *v, int depth) { _addLine(depth, _named(v), v); }

  void _addEdge(GEdge *e, int depth)
  {
    _addLine(depth, _named(e), e);
    if(e->getBeginVertex()) _addVertex(e->getBeginVertex(), depth + 1);
    if(e->getEndVertex()) _addVertex(e->getEndVertex(), depth + 1);
  }

  void _addFace(GFace *f, int depth)
  {
    _addLine(depth, _named(f), f);
    for(auto e : f->edges()) _addEdge(e, depth + 1);
  }

  void _addRegion(GRegion *r, int depth)
  {
    _addLine(depth, _named(r), r);
    for(auto f : r->faces()) _addFace(f, depth + 1);
  }

  void _refreshTree()
  {
    std::size_t was = _tree().size();
    _tree().clear();
    if(!_treeWanted() && _numEntities() > 10000) return;
    for(std::size_t i = 0; i < GModel::list.size(); i++) {
      GModel *m = GModel::list[i];
      std::string label = "Model " + std::to_string(i);
      if(m->getName().size()) label += " - " + m->getName();
      if(m == GModel::current()) label += " (Current Model)";
      _addLine(0, label, nullptr, m);

      _addLine(1, "Elementary entities");
      for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
        _addRegion(*it, 2);
      for(auto it = m->firstFace(); it != m->lastFace(); it++) _addFace(*it, 2);
      for(auto it = m->firstEdge(); it != m->lastEdge(); it++) _addEdge(*it, 2);
      for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
        _addVertex(*it, 2);

      _addLine(1, "Physical groups");
      std::map<int, std::vector<GEntity *>> groups[4];
      m->getPhysicalGroups(groups);
      const char *const kind[4] = {"Physical Point", "Physical Curve",
                                   "Physical Surface", "Physical Volume"};
      for(int dim = 3; dim >= 0; dim--) {
        for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
          if(it->second.empty()) continue;
          std::string name = m->getPhysicalName(dim, it->first);
          std::string label =
            std::string(kind[dim]) + " " + std::to_string(it->first);
          if(name.size()) label += " - " + name;
          _addLine(2, label);
          for(std::size_t j = 0; j < it->second.size(); j++) {
            GEntity *e = it->second[j];
            if(dim == 3)
              _addRegion((GRegion *)e, 3);
            else if(dim == 2)
              _addFace((GFace *)e, 3);
            else if(dim == 1)
              _addEdge((GEdge *)e, 3);
            else
              _addVertex((GVertex *)e, 3);
          }
        }
      }
    }
    // read from the model only when the tree changed, so that a pick survives
    // until applied
    if(_pickedTree().what.size() != _tree().size() || was != _tree().size()) {
      _pickedTree().what.assign(_tree().size(), 0);
      for(std::size_t i = 0; i < _tree().size(); i++) {
        const treeNode &line = _tree()[i];
        if(line.entity)
          _pickedTree().what[i] = line.entity->getVisibility() ? 1 : 0;
        else if(line.model)
          _pickedTree().what[i] = line.model->getVisibility() ? 1 : 0;
      }
    }
  }
  // a line is named by where it sits, "0/1/4": two entities of two models may
  // say the same thing

  std::map<std::string, std::vector<std::string>> &_under()
  {
    static std::map<std::string, std::vector<std::string>> under;
    return under;
  }

  std::map<std::string, int> &_atPath()
  {
    static std::map<std::string, int> at;
    return at;
  }

  void _makePaths()
  {
    _under().clear();
    _atPath().clear();
    std::vector<std::string> stack; // the path of the last line at each depth
    const std::vector<treeNode> &all = _tree();
    for(std::size_t i = 0; i < all.size(); i++) {
      int depth = all[i].depth;
      if((int)stack.size() > depth) stack.resize(depth);
      std::string parent = stack.empty() ? std::string() : stack.back();
      std::string here = parent + "/" + std::to_string(i);
      _under()[parent].push_back(here);
      _atPath()[here] = (int)i;
      stack.push_back(here);
    }
  }

  Ui::Tree _entityTree()
  {
    Ui::Tree t;
    t.children = [](const std::string &parent) {
      _refreshTree();
      _makePaths();
      auto it = _under().find(parent);
      return it == _under().end() ? std::vector<std::string>() : it->second;
    };
    t.node = [](const std::string &path) {
      Ui::Node n;
      auto it = _atPath().find(path);
      if(it == _atPath().end()) return n;
      int i = it->second;
      const std::vector<treeNode> &all = _tree();
      if(i < 0 || i >= (int)all.size()) return n;
      n.path = path;
      n.label = all[i].label;
      if(!all[i].entity && !all[i].model) return n;
      n.picked = [i]() {
        return i < (int)_pickedTree().what.size() && _pickedTree().what[i] != 0;
      };
      n.pick = [i](bool on) {
        const std::vector<treeNode> &all = _tree();
        if(i < 0 || i >= (int)all.size()) return;
        if(i < (int)_pickedTree().what.size())
          _pickedTree().what[i] = on ? 1 : 0;
        for(std::size_t j = i + 1;
            j < all.size() && all[j].depth > all[i].depth; j++)
          if(j < _pickedTree().what.size()) _pickedTree().what[j] = on ? 1 : 0;
      };
      return n;
    };
    t.generation = []() {
      _refreshTree();
      return (unsigned)_tree().size();
    };
    return t;
  }

  void _applyTree()
  {
    const std::vector<treeNode> &all = _tree();
    if(all.empty()) return;
    CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    bool recursive = _dialog().recursive;
    for(std::size_t m = 0; m < GModel::list.size(); m++) {
      std::vector<GEntity *> entities;
      GModel::list[m]->getEntities(entities);
      for(std::size_t i = 0; i < entities.size(); i++)
        entities[i]->setVisibility(0);
    }
    for(std::size_t i = 0; i < all.size() && i < _pickedTree().what.size();
        i++) {
      if(!_pickedTree().what[i]) continue;
      if(all[i].model) all[i].model->setVisibility(1);
      if(!all[i].entity) continue;
      all[i].entity->setVisibility(1, recursive);
      all[i].entity->model()->setVisibility(1);
    }
    drawContext::global()->draw();
  }

  // read from the model only when the list changed, so that a pick survives
  // until applied
  void _refreshList()
  {
    VisibilityList *v = VisibilityList::instance();
    v->update(_type(), _dialog().search);
    std::string of = std::to_string(_dialog().type) + "/" + _dialog().search +
                     "/" + std::to_string(v->getNumEntities()) + "/" +
                     GModel::current()->getName();
    if(_picked().of != of) {
      _picked().of = of;
      _picked().what.assign(v->getNumEntities(), 0);
      for(int i = 0; i < v->getNumEntities(); i++)
        _picked().what[i] = v->getVisibility(i) ? 1 : 0;
    }
    _picked().what.resize(v->getNumEntities(), 0);
  }

  void _applyList()
  {
    VisibilityList *v = VisibilityList::instance();
    if(!v->getNumEntities()) return;
    CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    v->setAllInvisible(_type(), _dialog().allModels);
    for(int i = 0; i < v->getNumEntities() && i < (int)_picked().what.size();
        i++)
      if(_picked().what[i])
        v->setVisibility(i, 1, _dialog().recursive, _dialog().allModels);
    drawContext::global()->draw();
  }

  void _redraw()
  {
    CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    drawContext::global()->draw();
  }

} // namespace

// what = 0 for nodes, 1 for elements, 2 for points, 3 for curves, 4 for
// surfaces, 5 for volumes, and 6 to 9 for the physical groups of each
void visibilityByNumber(int what, const std::string &value, bool show)
{
  bool recursive = _dialog().recursive, allModels = _dialog().allModels;
  char val = show ? 1 : 0;
  bool all = (value == "all" || value == "*" || value.empty());
  int num = all ? -1 : atoi(value.c_str());

  for(std::size_t mod = 0; mod < GModel::list.size(); mod++) {
    GModel *m = GModel::list[mod];
    if(!allModels && m != GModel::current()) continue;
    std::vector<GEntity *> entities;
    m->getEntities(entities);

    switch(what) {
    case 0: // nodes
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
          MVertex *v = entities[i]->mesh_vertices[j];
          if(all || (int)v->getNum() == num) v->setVisibility(val);
        }
      break;
    case 1: // elements
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *e = entities[i]->getMeshElement(j);
          if(all || (int)e->getNum() == num) e->setVisibility(val);
        }
      break;
    case 2:
      for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
        if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
      break;
    case 3:
      for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
        if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
      break;
    case 4:
      for(auto it = m->firstFace(); it != m->lastFace(); it++)
        if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
      break;
    case 5:
      for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
        if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
      break;
    case 6:
      for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
        for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
          if(all || std::abs((*it)->physicals[i]) == num)
            (*it)->setVisibility(val, recursive);
      break;
    case 7:
      for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
        for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
          if(all || std::abs((*it)->physicals[i]) == num)
            (*it)->setVisibility(val, recursive);
      break;
    case 8:
      for(auto it = m->firstFace(); it != m->lastFace(); it++)
        for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
          if(all || std::abs((*it)->physicals[i]) == num)
            (*it)->setVisibility(val, recursive);
      break;
    case 9:
      for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
        for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
          if(all || std::abs((*it)->physicals[i]) == num)
            (*it)->setVisibility(val, recursive);
      break;
    }
  }
  _redraw();
  Gui::instance().visibility.reload();
}

namespace {

  // kept so that hiding can be undone
  void _applyPicked(char mode, bool physical)
  {
    bool recursive = _dialog().recursive, allModels = _dialog().allModels;

    if(mode == 1) { // showing one thing means hiding everything else first
      if(CTX::instance()->pickElements)
        visibilityByNumber(1, "*", false);
      else
        for(int i = 2; i <= 5; i++) visibilityByNumber(i, "*", false);
    }
    if(mode == 2) mode = 1; // undoing a hide is showing again

    if(CTX::instance()->pickElements) {
      const std::vector<MElement *> &elements =
        Gui::instance().selectedElements();
      for(std::size_t i = 0; i < elements.size(); i++)
        elements[i]->setVisibility(mode);
    }
    else {
      const std::vector<GVertex *> &vertices =
        Gui::instance().selectedVertices();
      const std::vector<GEdge *> &edges = Gui::instance().selectedEdges();
      const std::vector<GFace *> &faces = Gui::instance().selectedFaces();
      const std::vector<GRegion *> &regions = Gui::instance().selectedRegions();
      for(std::size_t i = 0; i < vertices.size(); i++) {
        if(!physical)
          vertices[i]->setVisibility(mode, recursive);
        else
          for(std::size_t j = 0; j < vertices[i]->physicals.size(); j++)
            visibilityByNumber(6, std::to_string(vertices[i]->physicals[j]),
                               mode != 0);
      }
      for(std::size_t i = 0; i < edges.size(); i++) {
        if(!physical)
          edges[i]->setVisibility(mode, recursive);
        else
          for(std::size_t j = 0; j < edges[i]->physicals.size(); j++)
            visibilityByNumber(7, std::to_string(edges[i]->physicals[j]),
                               mode != 0);
      }
      for(std::size_t i = 0; i < faces.size(); i++) {
        if(!physical)
          faces[i]->setVisibility(mode, recursive);
        else
          for(std::size_t j = 0; j < faces[i]->physicals.size(); j++)
            visibilityByNumber(8, std::to_string(faces[i]->physicals[j]),
                               mode != 0);
      }
      for(std::size_t i = 0; i < regions.size(); i++) {
        if(!physical)
          regions[i]->setVisibility(mode, recursive);
        else
          for(std::size_t j = 0; j < regions[i]->physicals.size(); j++)
            visibilityByNumber(9, std::to_string(regions[i]->physicals[j]),
                               mode != 0);
      }
    }
    (void)allModels;
    Gui::instance().visibility.reload();
  }

} // namespace

void visibilityInteractive(const std::string &what)
{
  int type;
  char mode; // 0 to hide, 1 to show
  bool physical = (what.find("physical") != std::string::npos);
  bool show = (what.find("to show") != std::string::npos);

  if(what == "show all") {
    for(int i = 1; i <= 5; i++) visibilityByNumber(i, "*", true);
    CTX::instance()->meshChanged();
    drawContext::global()->draw();
    return;
  }
  mode = show ? 1 : 0;
  if(what.find("elements") != std::string::npos) {
    CTX::instance()->pickElements = 1;
    type = ENT_ALL;
  }
  else {
    CTX::instance()->pickElements = 0;
    if(what.find("points") != std::string::npos) {
      type = ENT_POINT;
      opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    }
    else if(what.find("curves") != std::string::npos) {
      type = ENT_CURVE;
      opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
    }
    else if(what.find("surfaces") != std::string::npos) {
      type = ENT_SURFACE;
      if(!show || GModel::current()->getMeshStatus() < 2)
        opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
    }
    else if(what.find("volumes") != std::string::npos) {
      type = ENT_VOLUME;
      if(!show || GModel::current()->getMeshStatus() < 3)
        opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
    }
    else
      return;
  }

  while(1) {
    if(type == ENT_ALL) CTX::instance()->meshChanged();
    drawContext::global()->draw();
    Msg::StatusGl("Select %s\n[Press %s'q' to abort]", what.c_str(),
                  mode ? "" : "'u' to undo or ");
    char ib = Gui::instance().selectEntity(type);
    if(ib == 'l') _applyPicked(mode, physical);
    if(ib == 'u' && !mode) _applyPicked(2, physical);
    if(ib == 'q') break;
  }

  CTX::instance()->meshChanged();
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Msg::StatusGl("");
}

using namespace Ui;
using namespace Declare;

GuiVisibility::GuiVisibility() : type(VisibilityList::ElementaryEntities) {}

Form GuiVisibility::build()
{
  // the buttons in columns of their own, all of one width
  auto byNumber = [this](const std::string &what, int i) {
    return hbox(
      {text("", &number[i])
         .labeled(what, true)
         .tip("Enter " + what + " number, or *")
         .sized(8.),
       button("Show", [this, i]() { visibilityByNumber(i, number[i], true); })
         .sized(7.),
       button("Hide", [this, i]() {
         visibilityByNumber(i, number[i], false);
       }).sized(7.)});
  };
  // what is picked in the view: a column to hide, set in under the headings,
  // one to show, Show all as tall as they are between them; the headings
  // after the first are the hiding column's, the showing one keeps their
  // lines
  std::vector<Item> hiding, showing;
  auto section = [&](const std::string &name,
                     const std::vector<std::string> &picked,
                     const std::string &prefix) {
    if(hiding.size()) {
      hiding.push_back(heading(name));
      showing.push_back(heading(""));
    }
    for(const auto &what : picked) {
      std::string entity = prefix + what;
      hiding.push_back(hbox({gap(), button("Hide " + what, [entity]() {
                                      visibilityInteractive(entity +
                                                            " to hide");
                                    }).sized(10.)}));
      showing.push_back(button("Show " + what, [entity]() {
                          visibilityInteractive(entity + " to show");
                        }).sized(10.));
    }
  };
  section("Mesh", {"elements"}, "");
  section("Elementary entities", {"points", "curves", "surfaces", "volumes"},
          "");
  section("Physical groups", {"points", "curves", "surfaces", "volumes"},
          "physical ");

  // two buttons pick all or the other half; three sort, the other way round
  // when pressed again
  std::vector<Item> head = {
    button("*",
           []() {
             bool none = true;
             for(std::size_t i = 0; i < _picked().what.size(); i++)
               if(_picked().what[i]) none = false;
             for(std::size_t i = 0; i < _picked().what.size(); i++)
               _picked().what[i] = none ? 1 : 0;
           })
      .tip("Select/unselect all")
      .sized(1.25),
    button("-",
           []() {
             for(std::size_t i = 0; i < _picked().what.size(); i++)
               _picked().what[i] = _picked().what[i] ? 0 : 1;
           })
      .tip("Invert selection")
      .sized(1.25)};
  const char *const sorted[3] = {"Type", "Number", "Name"};
  for(int i = 0; i < 3; i++)
    head.push_back(button(sorted[i],
                          [i]() {
                            VisibilityList::instance()->setSortMode(i + 1);
                            _refreshList();
                          })
                     .tip(std::string("Sort by ") + (i == 0 ? "type" :
                                                     i == 1 ? "number" :
                                                              "name"))
                     .sized(i == 2 ? 14. : 7.));
  Item list = vbox(
    {hbox(head, 0.),
     chooseFrom(
       [](std::vector<std::string> &labels, std::vector<int> &values) {
         _refreshList();
         VisibilityList *v = VisibilityList::instance();
         for(int i = 0; i < v->getNumEntities(); i++) {
           labels.push_back(v->getBrowserLine(i));
           values.push_back(i);
         }
       },
       [](int i) {
         return i >= 0 && i < (int)_picked().what.size() &&
                _picked().what[i] != 0;
       },
       [](int i, bool on) {
         if(i >= 0 && i < (int)_picked().what.size())
           _picked().what[i] = on ? 1 : 0;
       },
       true)
       .fills()
       .columns({2.5, 7., 7.}),
     hbox({choice("", &type,
                  {"Models", "Elementary entities", "Physical groups",
                   "Mesh partitions"},
                  {VisibilityList::Models, VisibilityList::ElementaryEntities,
                   VisibilityList::PhysicalEntities,
                   VisibilityList::MeshPartitions})
             .sized(11.)
             .tight(),
           text("", &search).tip("Filter list using regular expression"),
           button("Apply", _applyList).tight()})});

  auto shown = []() { return _treeWanted() || _numEntities() <= 10000; };
  Item treeView =
    vbox({tree(_entityTree()).fills().visibleWhen(shown),
          button("The model contains more than 10 thousand entities, which "
                 "might slow down the tree browser.\n\nCreate tree browser "
                 "anyway?",
                 []() { _treeWanted() = true; })
            .visibleWhen([shown]() { return !shown(); }),
          hbox({gap(), button("Apply", _applyTree)})});

  Item numeric =
    vbox({heading("Mesh"), byNumber("Node", 0), byNumber("Element", 1),
          heading("Elementary entities"), byNumber("Point", 2),
          byNumber("Curve", 3), byNumber("Surface", 4), byNumber("Volume", 5),
          heading("Physical groups"), byNumber("Point", 6),
          byNumber("Curve", 7), byNumber("Surface", 8), byNumber("Volume", 9)});

  Item picked =
    vbox({heading("Mesh"),
          hbox({vbox(hiding),
                button("Show\nall", []() { visibilityInteractive("show all"); })
                  .sized(4.)
                  .tall((int)hiding.size()),
                vbox(showing), gap()})});

  Item windows =
    vbox({chooseFrom(
            [](std::vector<std::string> &labels, std::vector<int> &values) {
              for(std::size_t i = 0; i < GModel::list.size(); i++) {
                labels.push_back("Model " + std::to_string(i) + " - " +
                                 GModel::list[i]->getName());
                values.push_back((int)i);
              }
#if defined(HAVE_POST)
              for(std::size_t i = 0; i < PView::list.size(); i++) {
                labels.push_back("View [" + std::to_string(i) + "] " +
                                 PView::list[i]->getData()->getName());
                values.push_back((int)(GModel::list.size() + i));
              }
#endif
            },
            [](int i) {
              drawContext *ctx = Gui::instance().getCurrentDrawContext();
              if(!ctx) return true;
              if(i < (int)GModel::list.size())
                return ctx->isVisible(GModel::list[i]);
#if defined(HAVE_POST)
              std::size_t v = i - GModel::list.size();
              if(v < PView::list.size()) return ctx->isVisible(PView::list[v]);
#endif
              return true;
            },
            [](int i, bool on) {
              drawContext *ctx = Gui::instance().getCurrentDrawContext();
              if(!ctx) return;
              if(i < (int)GModel::list.size()) {
                if(on)
                  ctx->show(GModel::list[i]);
                else
                  ctx->hide(GModel::list[i]);
              }
#if defined(HAVE_POST)
              else {
                std::size_t v = i - GModel::list.size();
                if(v < PView::list.size()) {
                  if(on)
                    ctx->show(PView::list[v]);
                  else
                    ctx->hide(PView::list[v]);
                }
              }
#endif
              drawContext::global()->draw();
            },
            true)
            .fills(),
          hbox({gap(), button("Reset all", []() {
                  Gui::instance().showAllInEveryWindow();
                  drawContext::global()->draw();
                })})});

  // eighteen lines tall whatever the tab: a list that fills what is left has to
  // be told what that is
  Form f = {
    "visibility", "Visibility",
    vbox({tabs({{"List", list},
                {"Tree", treeView},
                {"Numeric", numeric},
                {"Interactive", picked},
                {"Per window", windows}}),
          hbox({label("Apply"), check("recursively", &recursive),
                check("to all models", &allModels), gap(), button("Save", []() {
                  Msg::StatusBar(true, "Appending visibility info to '%s'...",
                                 GModel::current()->getFileName().c_str());
                  visibility_save(GModel::current()->getFileName());
                  Msg::StatusBar(true, "Done appending visibility info");
                })})})};
  f.leastRows = 15;
  return f;
}
