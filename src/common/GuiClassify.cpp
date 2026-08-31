// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Reclassifying a triangulation: the counterpart of
// src/fltk/classificationEditor.cpp, described once and built by both
// interfaces. It is what turns a mesh with no geometry under it -- an STL --
// into a model: the edges whose dihedral angle is sharp enough are taken as
// the curves between surfaces, and the surfaces are split along them.
//
// It is not a form one fills: the three steps it is written in are three
// things one does, two of them by picking in the 3D view. That is why the
// panel it describes greys out what does not apply yet, exactly as the window
// it replaces does, and why the work is here rather than in either interface:
// the picking loops go through Gui::selectEntity(), which both of them answer.

#include "GmshConfig.h"

#include <algorithm>
#include <string>
#include <vector>

#include "GuiDialogs.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "MLine.h"
#include "Context.h"
#include "Options.h"
#include "drawContext.h"
#include "discreteEdge.h"

#if defined(HAVE_MESH)
#include "meshGFaceOptimize.h"
#endif

namespace {

  // What the editor has gathered so far. The window this replaces kept it in
  // the editor object, which was also the window; here the two are apart.
  struct classifyState {
    // the elements picked in the view, and what they say the edges are
    std::vector<MElement *> elements;
#if defined(HAVE_MESH)
    std::vector<edge_angle> detected, lonely;
#endif
    // the curve the edges one keeps are gathered in, which is handed to the
    // classification and disposed of by it
    GEdge *selected = nullptr;
    double angle = 40.;
    bool boundary = false;
    bool onlyEdges = false;
    bool parametrizable = false;
    // what the surfaces looked like before "Show only edges" hid them
    int wasSurfaceFaces = 1, wasSurfaceEdges = 1;
  };

  classifyState &_state()
  {
    static classifyState state;
    return state;
  }

  // whether anything has been selected: what one may do next hangs on it, as
  // it does in the window this replaces
  bool _selecting() { return _state().elements.size() > 0; }

  // the curve the picked edges live in, made when it is first wanted
  GEdge *_curve()
  {
    if(!_state().selected) {
      _state().selected = new discreteEdge(
        GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1,
        nullptr, nullptr);
      GModel::current()->add(_state().selected);
    }
    return _state().selected;
  }

  // The edges the threshold angle keeps, drawn as the lines of that curve.
  // Sharper first: the list is sorted, so the first angle under the threshold
  // ends it.
  void _updateEdges()
  {
    GEdge *curve = _state().selected;
    if(!curve) return;
    for(std::size_t i = 0; i < curve->lines.size(); i++) delete curve->lines[i];
    curve->lines.clear();

#if defined(HAVE_MESH)
    double threshold = _state().angle / 180. * M_PI;
    for(std::size_t i = 0; i < _state().detected.size(); i++) {
      edge_angle ea = _state().detected[i];
      if(ea.angle <= threshold) break;
      curve->lines.push_back(new MLine(ea.v1, ea.v2));
    }
    if(_state().boundary) {
      for(std::size_t i = 0; i < _state().lonely.size(); i++) {
        edge_angle ea = _state().lonely[i];
        curve->lines.push_back(new MLine(ea.v1, ea.v2));
      }
    }
    Msg::Info("Edges: %d inside, %d boundary, %d selected",
              (int)_state().detected.size(), (int)_state().lonely.size(),
              (int)curve->lines.size());
#endif

    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
  }

  // Which elements the edges are looked for in: every surface element of the
  // model, or the ones picked in the view. Picking follows the same rules as
  // everywhere else in Gmsh -- left button adds, right button takes back, 'e'
  // ends, 'q' abandons.
  void _selectElements(bool all)
  {
    _curve();

    if(all) {
      for(auto it = GModel::current()->firstFace();
          it != GModel::current()->lastFace(); ++it) {
        _state().elements.insert(_state().elements.end(),
                                 (*it)->triangles.begin(),
                                 (*it)->triangles.end());
        _state().elements.insert(_state().elements.end(),
                                 (*it)->quadrangles.begin(),
                                 (*it)->quadrangles.end());
      }
    }
    else {
      CTX::instance()->pickElements = 1;
      while(1) {
        CTX::instance()->mesh.changed = ENT_ALL;
        drawContext::global()->draw();
        Msg::StatusGl("Select elements\n"
                      "[Press 'e' to end selection or 'q' to abort]");
        char ib = Gui::selectEntity(ENT_ALL);
        if(!Gui::available()) break;
        if(ib == 'l') {
          for(auto *me : Gui::selectedElements()) {
            if(me->getDim() == 2 && me->getVisibility() != 2) {
              me->setVisibility(2);
              _state().elements.push_back(me);
            }
          }
        }
        if(ib == 'r') {
          for(auto *me : Gui::selectedElements()) {
            if(me->getVisibility() == 2) {
              auto it = std::find(_state().elements.begin(),
                                  _state().elements.end(), me);
              if(it != _state().elements.end()) _state().elements.erase(it);
            }
            me->setVisibility(1);
          }
        }
        if(ib == 'e') {
          GModel::current()->setSelection(0);
          break;
        }
        if(ib == 'q') {
          GModel::current()->setSelection(0);
          _state().elements.clear();
          break;
        }
      }
      CTX::instance()->pickElements = 0;
    }

#if defined(HAVE_MESH)
    e2t_cont adj;
    buildEdgeToElements(_state().elements, adj);
    buildListOfEdgeAngle(adj, _state().detected, _state().lonely);
#else
    Msg::Error("Reclassifying surfaces requires the mesh module");
#endif

    _updateEdges();
    Msg::StatusGl("");
  }

  // Take edges out of the selection by picking them in the view: what the
  // threshold keeps is a good guess and no more.
  void _deleteEdges()
  {
    GEdge *curve = _state().selected;
    if(!curve) return;

    CTX::instance()->pickElements = 1;
    std::vector<MLine *> picked;
    while(1) {
      CTX::instance()->mesh.changed = ENT_ALL;
      drawContext::global()->draw();
      Msg::StatusGl("Select elements\n"
                    "[Press 'e' to end selection or 'q' to abort]");
      char ib = Gui::selectEntity(ENT_ALL);
      if(!Gui::available()) break;
      if(ib == 'l') {
        for(auto *me : Gui::selectedElements()) {
          if(me->getType() == TYPE_LIN && me->getVisibility() != 2) {
            me->setVisibility(2);
            picked.push_back((MLine *)me);
          }
        }
      }
      if(ib == 'r') {
        for(auto *me : Gui::selectedElements()) {
          if(me->getVisibility() == 2) {
            auto it = std::find(picked.begin(), picked.end(), me);
            if(it != picked.end()) picked.erase(it);
          }
          me->setVisibility(1);
        }
      }
      if(ib == 'e') {
        GModel::current()->setSelection(0);
        break;
      }
      if(ib == 'q') {
        GModel::current()->setSelection(0);
        picked.clear();
        break;
      }
    }

    std::sort(picked.begin(), picked.end());

    // whatever was picked goes; the rest stays selected
    std::vector<MLine *> keep;
    keep.swap(curve->lines);
    for(std::size_t i = 0; i < keep.size(); i++) {
      if(std::find(picked.begin(), picked.end(), keep[i]) != picked.end())
        delete keep[i];
      else
        curve->lines.push_back(keep[i]);
    }

    CTX::instance()->mesh.changed = ENT_ALL;
    CTX::instance()->pickElements = 0;
    drawContext::global()->draw();
    Msg::StatusGl("");

    // the detection is spent: what is selected now is what one has kept
    _state().elements.clear();
#if defined(HAVE_MESH)
    _state().detected.clear();
#endif
  }

  void _reset()
  {
    GEdge *curve = _state().selected;
    if(!curve) return;
    for(std::size_t i = 0; i < curve->lines.size(); i++) delete curve->lines[i];
    curve->lines.clear();
    curve->deleteVertexArrays();
    _state().elements.clear();
#if defined(HAVE_MESH)
    _state().detected.clear();
#endif
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
  }

  void _classify()
  {
    meshClassifySurfaces(_state().angle, _state().parametrizable,
                         &_state().selected);
    _state().elements.clear();
#if defined(HAVE_MESH)
    _state().detected.clear();
    _state().lonely.clear();
#endif
  }

  // hide everything but the elements one has picked, and put it back
  void _hideUnselected()
  {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
  }

  // Show the edges alone, so that one can see what has been detected. The
  // window this replaces remembers what the surfaces looked like and puts them
  // back.
  void _showOnlyEdges()
  {
    if(_state().onlyEdges) {
      _state().wasSurfaceFaces = (int)opt_mesh_surface_faces(0, GMSH_GET, 0.);
      _state().wasSurfaceEdges = (int)opt_mesh_surface_edges(0, GMSH_GET, 0.);
      opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
      opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, 0.);
      opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, 0.);
    }
    else {
      opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI,
                             _state().wasSurfaceFaces);
      opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI,
                             _state().wasSurfaceEdges);
    }
    drawContext::global()->draw();
  }

} // namespace

namespace Dialog {

  void startClassify()
  {
    // the lines are what one is about to work on: the window this replaces
    // turns them on as it opens
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
    drawContext::global()->draw();
    show(Classify, -1);
  }

  Form classify()
  {
    Form p;
    p.title = "Reclassify 2D";
    // three steps one after another, not three tabs: they are done in order
    p.tabbed = false;

    {
      Pane first;
      first.label = "1. Select mesh elements on which to perform edge detection";
      Ui::Field some = does("Select elements", []() { _selectElements(false); });
      some.packed = true;
      first.fields.push_back(some);
      Ui::Field all = does("All", []() { _selectElements(true); });
      all.packed = true;
      all.sameRow = true;
      first.fields.push_back(all);
      // it is not an option of Gmsh, only a flag of the interface, so the
      // field reaches it through a pair of functions
      Ui::Field hide = check("Hide unselected elements", nullptr);
      hide.readNumber = []() {
        return CTX::instance()->hideUnselected ? 1. : 0.;
      };
      hide.writeNumber = [](double v) {
        CTX::instance()->hideUnselected = (v != 0.) ? 1 : 0;
      };
      hide.packed = true;
      hide.sameRow = true;
      hide.changed = _hideUnselected;
      first.fields.push_back(hide);
      first.separatorAfter = true;
      p.panes.push_back(first);
    }

    {
      Pane second;
      second.label = "2. Fine-tune edge selection";
      Ui::Field threshold = within(number("Threshold angle", &_state().angle),
                               0., 180., 1.);
      threshold.widthEm = 5.;
      threshold.packed = true;
      threshold.enabled = _selecting;
      threshold.changed = _updateEdges;
      second.fields.push_back(threshold);

      Ui::Field only = check("Show only edges", &_state().onlyEdges);
      only.packed = true;
      only.sameRow = true;
      only.changed = _showOnlyEdges;
      second.fields.push_back(only);

      Ui::Field closure = check("Include edges on boundary (closure)",
                            &_state().boundary);
      closure.packed = true;
      closure.enabled = _selecting;
      closure.changed = _updateEdges;
      second.fields.push_back(closure);

      Ui::Field drop = does("Delete edges from selection", _deleteEdges);
      drop.packed = true;
      drop.enabled = _selecting;
      second.fields.push_back(drop);

      Ui::Field again = does("Reset selection", _reset);
      again.packed = true;
      again.sameRow = true;
      again.enabled = _selecting;
      second.fields.push_back(again);

      second.separatorAfter = true;
      p.panes.push_back(second);
    }

    {
      Pane third;
      third.label = "3. Reclassify surfaces using selected edges";
      Ui::Field parametrized = check("Create parametrized discrete model",
                                 &_state().parametrizable);
      parametrized.packed = true;
      parametrized.tooltip =
        "Cut the surfaces further so that each of them can be parametrized, "
        "and build the geometry of the discrete entities";
      third.fields.push_back(parametrized);

      Ui::Field run = does("Reclassify", _classify);
      run.packed = true;
      run.enabled = _selecting;
      third.fields.push_back(run);
      p.panes.push_back(third);
    }

    return p;
  }

} // namespace Dialog
