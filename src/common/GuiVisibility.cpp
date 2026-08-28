// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What of the model is drawn: the counterpart of src/fltk/visibilityWindow.cpp,
// described once and built by both interfaces. The list of entities and their
// state come from VisibilityList, which was already shared; what is here is the
// rest of what that window did -- hiding by number, hiding by picking, and
// saying which model or view each graphic window shows.

#include "GmshConfig.h"

#include <string>
#include <vector>

#include "GuiDialogs.h"
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

  // What the window is showing and how it applies what one asks of it. The
  // window this replaces kept it in its widgets; here the description owns it,
  // so that both interfaces mean the same thing by "recursively".
  struct visibilityState {
    int type = VisibilityList::ElementaryEntities;
    std::string search;
    bool recursive = true;
    bool allModels = true;
    // what the numeric tab holds, one per line
    std::string number[10] = {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*"};
  };

  visibilityState &_state()
  {
    static visibilityState state;
    return state;
  }

  VisibilityList::VisibilityType _type()
  {
    return (VisibilityList::VisibilityType)_state().type;
  }

  // the list, as it is now: the window asks for it again whenever it draws
  void _refreshList()
  {
    VisibilityList::instance()->update(_type(), _state().search);
  }

  void _redraw()
  {
    CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    drawContext::global()->draw();
  }

} // namespace

// what = 0 for nodes, 1 for elements, 2 for points, 3 for curves, 4 for
// surfaces, 5 for volumes, and 6 to 9 for the physical groups of each
void visibilityByNumber(int what, const std::string &value, bool show)
{
  bool recursive = _state().recursive, allModels = _state().allModels;
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
  Gui::refreshDialog(Dialog::Visibility);
}

namespace {

  // what has just been picked, hidden or shown; kept so that hiding can be
  // undone, as that window lets one do
  void _applyPicked(char mode, bool physical)
  {
    bool recursive = _state().recursive, allModels = _state().allModels;

    if(mode == 1) { // showing one thing means hiding everything else first
      if(CTX::instance()->pickElements)
        visibilityByNumber(1, "*", false);
      else
        for(int i = 2; i <= 5; i++) visibilityByNumber(i, "*", false);
    }
    if(mode == 2) mode = 1; // undoing a hide is showing again

    if(CTX::instance()->pickElements) {
      const std::vector<MElement *> &elements = Gui::selectedElements();
      for(std::size_t i = 0; i < elements.size(); i++)
        elements[i]->setVisibility(mode);
    }
    else {
      const std::vector<GVertex *> &vertices = Gui::selectedVertices();
      const std::vector<GEdge *> &edges = Gui::selectedEdges();
      const std::vector<GFace *> &faces = Gui::selectedFaces();
      const std::vector<GRegion *> &regions = Gui::selectedRegions();
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
    Gui::refreshDialog(Dialog::Visibility);
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
    CTX::instance()->mesh.changed = ENT_ALL;
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
    if(type == ENT_ALL) CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    Msg::StatusGl("Select %s\n[Press %s'q' to abort]", what.c_str(),
                  mode ? "" : "'u' to undo or ");
    char ib = Gui::selectEntity(type);
    if(ib == 'l') _applyPicked(mode, physical);
    // one can only take back a hiding
    if(ib == 'u' && !mode) _applyPicked(2, physical);
    if(ib == 'q') break;
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Msg::StatusGl("");
}

namespace Dialog {

  namespace {

    // one line of the numeric tab: what to hide or show, by number
    void _byNumber(std::vector<Field> &into, const std::string &label, int what)
    {
      Field number = text(label, &_state().number[what],
                          "Enter " + label + " number, or *");
      number.labelBefore = true;
      number.widthEm = 8.;
      into.push_back(number);
      // in a column of its own, so that the buttons of every line stand
      // under one another whatever the line is called
      Field show = does("Show", [what]() {
        visibilityByNumber(what, _state().number[what], true);
      });
      show.sameRow = true;
      into.push_back(show);
      Field hide = does("Hide", [what]() {
        visibilityByNumber(what, _state().number[what], false);
      });
      hide.sameRow = true;
      hide.packed = true;
      into.push_back(hide);
    }

    // one line of the interactive tab: a pair of buttons that pick
    void _byPicking(std::vector<Field> &into, const std::string &what)
    {
      Field hide = does("Hide " + what,
                        [what]() { visibilityInteractive(what + " to hide"); });
      hide.packed = true;
      into.push_back(hide);
      // in a column of its own, so that they stand under one another
      Field show = does("Show " + what,
                        [what]() { visibilityInteractive(what + " to show"); });
      show.sameRow = true;
      into.push_back(show);
    }

  } // namespace

  Panel visibility()
  {
    Panel p;
    p.title = "Visibility";
    p.tabbed = true;
    // The window this replaces is eighteen lines tall whatever tab it is on,
    // of which the row of tabs and the two lines under it take three. A list
    // that fills what is left has to be told what that is.
    p.leastRows = 15;

    // --- the list of what there is, and what of it is drawn
    {
      Pane list;
      list.label = "List";
      // The head of the list: two buttons that pick all of it or the other
      // half of it, and three that sort it -- by type, by number and by name,
      // each the other way round when pressed again.
      Field all = does("*", []() {
        VisibilityList *v = VisibilityList::instance();
        bool none = true;
        for(int i = 0; i < v->getNumEntities(); i++)
          if(v->getVisibility(i)) none = false;
        for(int i = 0; i < v->getNumEntities(); i++)
          v->setVisibility(i, none ? 1 : 0, _state().recursive,
                           _state().allModels);
        _redraw();
      });
      all.tooltip = "Select/unselect all";
      all.widthEm = 1.25;
      all.packed = true;
      list.fields.push_back(all);
      Field invert = does("-", []() {
        VisibilityList *v = VisibilityList::instance();
        for(int i = 0; i < v->getNumEntities(); i++)
          v->setVisibility(i, v->getVisibility(i) ? 0 : 1, _state().recursive,
                           _state().allModels);
        _redraw();
      });
      invert.tooltip = "Invert selection";
      invert.widthEm = 1.25;
      invert.packed = true;
      invert.sameRow = true;
      list.fields.push_back(invert);
      const char *const sorted[3] = {"Type", "Number", "Name"};
      for(int i = 0; i < 3; i++) {
        Field by = does(sorted[i], [i]() {
          VisibilityList::instance()->setSortMode(i + 1);
          _refreshList();
        });
        by.tooltip = std::string("Sort by ") + (i == 0 ? "type" :
                                                i == 1 ? "number" : "name");
        by.widthEm = (i == 2) ? 14. : 7.;
        by.packed = true;
        by.sameRow = true;
        list.fields.push_back(by);
      }
      Field entities = chooseFrom(
        [](std::vector<std::string> &labels, std::vector<int> &values) {
          _refreshList();
          VisibilityList *v = VisibilityList::instance();
          for(int i = 0; i < v->getNumEntities(); i++) {
            labels.push_back(v->getBrowserLine(i));
            values.push_back(i);
          }
        },
        [](int i) {
          VisibilityList *v = VisibilityList::instance();
          return i >= 0 && i < v->getNumEntities() && v->getVisibility(i);
        },
        [](int i, bool on) {
          VisibilityList *v = VisibilityList::instance();
          if(i >= 0 && i < v->getNumEntities())
            v->setVisibility(i, on ? 1 : 0, _state().recursive,
                             _state().allModels);
          _redraw();
        },
        true);
      entities.rows = 0; // as tall as the pane
      // a type, a number and a name, as that window lines them up
      entities.columnsEm = {1.25, 7., 7.};
      list.fields.push_back(entities);

      // what the list is of, what of it is shown, and the button that puts
      // the whole of the selection into the model at once
      Field type =
        choice("", &_state().type,
               {"Models", "Elementary entities", "Physical groups",
                "Mesh partitions"},
               {VisibilityList::Models, VisibilityList::ElementaryEntities,
                VisibilityList::PhysicalEntities,
                VisibilityList::MeshPartitions});
      type.widthEm = 11.;
      type.packed = true;
      list.fields.push_back(type);
      Field search = text("", &_state().search,
                          "Filter list using regular expression");
      search.sameRow = true;
      list.fields.push_back(search);
      Field apply = does("Apply", []() {
        VisibilityList *v = VisibilityList::instance();
        _redraw();
      });
      apply.sameRow = true;
      apply.packed = true;
      list.fields.push_back(apply);
      p.panes.push_back(list);
    }

    // --- by number
    {
      Pane numeric;
      numeric.label = "Numeric";
      numeric.columns = 3;
      numeric.fields.push_back(says([]() { return std::string("Mesh"); }));
      _byNumber(numeric.fields, "Node", 0);
      _byNumber(numeric.fields, "Element", 1);
      numeric.fields.push_back(
        says([]() { return std::string("Elementary entities"); }));
      _byNumber(numeric.fields, "Point", 2);
      _byNumber(numeric.fields, "Curve", 3);
      _byNumber(numeric.fields, "Surface", 4);
      _byNumber(numeric.fields, "Volume", 5);
      numeric.fields.push_back(
        says([]() { return std::string("Physical groups"); }));
      _byNumber(numeric.fields, "Point", 6);
      _byNumber(numeric.fields, "Curve", 7);
      _byNumber(numeric.fields, "Surface", 8);
      _byNumber(numeric.fields, "Volume", 9);
      p.panes.push_back(numeric);
    }

    // --- by picking
    {
      Pane picked;
      picked.label = "Interactive";
      picked.columns = 3;
      picked.fields.push_back(says([]() { return std::string("Mesh"); }));
      _byPicking(picked.fields, "elements");
      picked.fields.push_back(
        says([]() { return std::string("Elementary entities"); }));
      _byPicking(picked.fields, "points");
      _byPicking(picked.fields, "curves");
      _byPicking(picked.fields, "surfaces");
      _byPicking(picked.fields, "volumes");
      picked.fields.push_back(
        says([]() { return std::string("Physical groups"); }));
      _byPicking(picked.fields, "physical points");
      _byPicking(picked.fields, "physical curves");
      _byPicking(picked.fields, "physical surfaces");
      _byPicking(picked.fields, "physical volumes");
      picked.buttonLabel = "Show all";
      picked.button = []() { visibilityInteractive("show all"); };
      p.panes.push_back(picked);
    }

    // --- what each graphic window shows of it
    {
      Pane windows;
      windows.label = "Per window";
      Field which = chooseFrom(
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
          drawContext *ctx = Gui::getCurrentDrawContext();
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
          drawContext *ctx = Gui::getCurrentDrawContext();
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
        true);
      which.rows = 0;
      windows.fields.push_back(which);
      windows.buttonLabel = "Reset all";
      windows.button = []() {
        Gui::showAllInEveryWindow();
        drawContext::global()->draw();
      };
      p.panes.push_back(windows);
    }

    // --- what "apply" means, whichever tab one is on
    p.footer.push_back(tight(says([]() { return std::string("Apply"); })));
    Field recursive = check("recursively", &_state().recursive);
    recursive.sameRow = true;
    recursive.packed = true;
    p.footer.push_back(recursive);
    Field all = check("to all models", &_state().allModels);
    all.sameRow = true;
    all.packed = true;
    p.footer.push_back(all);

    Button save;
    save.label = "Save";
    save.action = []() {
      Msg::StatusBar(true, "Appending visibility info to '%s'...",
                     GModel::current()->getFileName().c_str());
      visibility_save(GModel::current()->getFileName());
      Msg::StatusBar(true, "Done appending visibility info");
    };
    p.buttons.push_back(save);
    p.buttonsInFooter = true;
    return p;
  }

} // namespace Dialog
