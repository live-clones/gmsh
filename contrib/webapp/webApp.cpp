// Gmsh web app - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// What a web page calls (through ccall) besides the Gmsh API (api/gmsh.mjs):
// - the scene on its canvas, drawn as a window would draw it (see
//   drawContextOffscreen), with the mouse events of the page given to the
//   same interaction as the graphical interface's (sceneView; "the graphical
//   interface", here and in the page, is the FLTK graphical user interface
//   of Gmsh, src/fltk); positions are in the CSS pixels of the canvas, from
//   its top left corner;
// - the tools and the operations on the entities picked, the menus (the
//   action registry), the shapes added to the script, the options and the
//   shortcuts of the graphical interface;
// - the ONELAB loop of the graphical interface, in steps, with the solvers run
//   in-process (gmshInProcessClient) in a web worker, and the parameters
//   changed as the graphical interface changes them (they are read through
//   the Gmsh API, gmsh.onelab.get, in JSON). GetDP is one of these solvers
//   when the module is linked with it (HAVE_WEBAPP_GETDP, see build.sh).
// Errors in these entries are reported and return, as in the FLTK
// interface, instead of throwing into the page (Msg::NoThrow).

#if defined(__EMSCRIPTEN__)

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <map>
#include <memory>
#include <sstream>
#include <emscripten.h>
#include "GmshConfig.h"
#include "Actions.h"
#include "IconStrokes.h"
#include "ScriptStyles.h"
#include "Context.h"
#include "ColorContrast.h"
#include "GmshDefines.h"
#include "GmshGlobal.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "OpenFile.h"
#include "OS.h"
#include "PView.h"
#include "PViewData.h"
#include "Options.h"
#include "Shortcuts.h"
#include "StringUtils.h"
#include "drawContextOffscreen.h"
#include "gmshLocalNetworkClient.h"
#include "onelab.h"
#include "onelabUtils.h"
#include "sceneView.h"
#include "scriptStringInterface.h"
#include "selectionDriver.h"
#include "sceneTool.h"
#if defined(HAVE_WEBAPP_GETDP)
#include "getdp.h"
#endif

namespace {
  drawContextOffscreen *_view = nullptr;
  // the canvas as it was last drawn: device pixels, and device pixels per
  // CSS pixel
  int _width = 0, _height = 0;
  double _scale = 1.;

  // the host of the interaction: the canvas of the page, whose events come
  // through gmshWebMouse() and which reads back what it is to show
  class webView : public sceneView {
  public:
    // what the last event asked for
    bool redrawAsked = false, cross = false;
    // a picking pass drew into the canvas: the frame is to be drawn again
    // before the page shows it
    bool picked = false;
    webView() : sceneView(nullptr) {}
    void hostRedraw() { redrawAsked = true; }
    void hostCursor(bool c) { cross = c; }
    bool hostBeginGL()
    {
      if(!_view || !_view->begin(_width, _height, _scale, true)) return false;
      picked = true;
      return true;
    }
    void hostEndGL() { _view->end(); }
    const std::string &hoverText() const { return _hoverText; }
    // where the box hangs (CSS pixels): it moves once the cursor has strayed
    // from it, not at every move (see drawTooltip())
    const double *hoverAnchor() const { return _hoverAnchor; }
    // the lasso rectangle, from the click to the pointer (CSS pixels)
    bool lasso(double xy[4]) const
    {
      if(!lassoMode) return false;
      xy[0] = _click.win[0];
      xy[1] = _click.win[1];
      xy[2] = _curr.win[0];
      xy[3] = _curr.win[1];
      return true;
    }
  };
  webView *_scene = nullptr;

  // the operation on selected entities under way (a tool, see sceneTool),
  // the values of the fields of its form, and how many times operations were
  // carried out (for the page to show what changed)
  operationTool *operation()
  {
    auto *t = dynamic_cast<operationTool *>(sceneTool::current());
    return (t && t->active()) ? t : nullptr;
  }
  std::map<std::string, std::string> _values;
  int _changes = 0;

  void draw()
  {
    _view->drawCurrentOpenglWindow(true);
    _view->end();
  }

  // the items of the action registry given to the page (gmshWebActions()),
  // by id
  std::vector<const actionItem *> _items;

  std::string jsonItem(const actionItem &item)
  {
    static const char *kinds[] = {"menu", "action", "operation", "shape"};
    std::string json = "{\"id\":" + std::to_string(_items.size()) +
                       ",\"label\":" + JsonString(item.label) + ",\"kind\":\"" +
                       kinds[item.kind] +
                       "\",\"name\":" + JsonString(item.name) +
                       ",\"help\":" + JsonString(item.help) +
                       ",\"icon\":" + JsonString(item.icon) +
                       ",\"gmsh\":" + (item.run ? "1" : "0") + ",\"items\":[";
    _items.push_back(&item);
    for(std::size_t i = 0; i < item.items.size(); i++)
      json += std::string(i ? "," : "") + jsonItem(item.items[i]);
    return json + "]}";
  }

  const actionItem *item(int id)
  { return (id >= 0 && id < (int)_items.size()) ? _items[id] : nullptr; }

  // the actions of the page done here, as the buttons of the status bar of
  // the graphical interface do them: the point of view (Shift for the other
  // side, or with "1:1" for the bounding box of what is visible), and the
  // time steps and the views (see gmshWebView())
  typedef std::function<void(unsigned mods, drawContext *ctx)> sceneAction;
  const std::map<std::string, sceneAction> &sceneActions()
  {
    static const std::map<std::string, sceneAction> actions = [] {
      std::map<std::string, sceneAction> m;
      for(const char *a :
          {"view_x", "view_y", "view_z", "view_3d", "view_1_1"}) {
        std::string which = strcmp(a, "view_1_1") ? std::string(a + 5) : "1:1";
        m[a] = [which](unsigned mods, drawContext *ctx) {
          if(which == "1:1" && (mods & ModShift)) SetBoundingBox(true);
          ctx->standardView(which, mods & ModShift);
        };
      }
      m["time_step_prev"] = [](unsigned, drawContext *) {
        PView::animate(true, -CTX::instance()->post.animStep);
      };
      m["time_step_next"] = [](unsigned, drawContext *) {
        PView::animate(true, CTX::instance()->post.animStep);
      };
      m["view_prev"] = [](unsigned, drawContext *) {
        PView::animate(false, -CTX::instance()->post.animStep);
      };
      m["view_next"] = [](unsigned, drawContext *) {
        PView::animate(false, CTX::instance()->post.animStep);
      };
      return m;
    }();
    return actions;
  }

#if defined(HAVE_WEBAPP_GETDP)
  // GetDP is known as soon as the module starts, so that opening a .pro file
  // and running the solver (in the page or with gmsh.onelab.run()) uses it.
  // Its direct solver is UMFPACK (MUMPS needs Fortran), whose default
  // unsymmetric strategy needs ten times the memory of MUMPS on 3D models
  // (28 GB instead of 0.8 for GetDP's tutorial 10): the symmetric strategy
  // with METIS brings it to 2 GB (the options of a model still apply after)
  struct registerGetDP {
    registerGetDP()
    {
      onelabUtils::setInProcessSolver("GetDP", getdp);
      setenv("PETSC_OPTIONS",
             "-mat_umfpack_strategy SYMMETRIC -mat_umfpack_ordering METIS", 0);
    }
  } _registerGetDP;
#endif

  // the client of the solver the last file opened asked for (a .pro file
  // asks for GetDP), as the graphical interface adds it
  void addSolver()
  {
    int num = CTX::instance()->launchSolverAtStartup;
    if(num < 0) return;
    CTX::instance()->launchSolverAtStartup = -1;
    std::string name = opt_solver_name(num, GMSH_GET, "");
    onelabUtils::inProcessSolver solver = onelabUtils::getInProcessSolver(name);
    if(!solver) {
      Msg::Error("Solver '%s' is not available in the web app", name.c_str());
      return;
    }
    onelab::server *s = onelab::server::instance();
    if(s->findClient(name) == s->lastClient()) {
      gmshInProcessClient *c = new gmshInProcessClient(name, solver);
      c->setIndex(num);
    }
  }

  // the loop under way (see onelabUtils::onelabLoop), stepped by the page
  std::unique_ptr<onelabUtils::onelabLoop> _loop;

  // the in-process solvers the loop runs (not the clients a solver adds while
  // it runs)
  std::vector<gmshInProcessClient *> solvers()
  {
    std::vector<gmshInProcessClient *> v;
    if(!_loop) return v;
    for(onelab::client *c : _loop->solvers())
      if(auto *s = dynamic_cast<gmshInProcessClient *>(c)) v.push_back(s);
    return v;
  }

  // in a web worker running a solver: what GetDP asks to show, given to the
  // page (solver.js). GetDP merges such a file in the program, as the files
  // it reads, then asks for a render: the file is then the last one merged,
  // and its views, of no use in the worker, are removed (a solver writing its
  // results at each time step would keep them all, and GetDP would find them
  // as the last views, which a GetDP process of its own never sees).
  // And the database, when GetDP asks for a refresh (Gmsh/Action, e.g. after
  // adding a value to an output drawn on a graph), no more than every quarter
  // of a second, as the graphical interface (gmshLocalNetworkClient)
  class solverMessages : public GmshMessage {
  public:
    void operator()(std::string level, std::string message)
    {
      if(level == "RequestRender") {
        std::size_t first;
        const std::string &file = GmshLastMergedPostProcessingFile(&first);
        if(file.empty()) return;
        EM_ASM(
          {
            if(globalThis.gmshSolverMerge)
              globalThis.gmshSolverMerge(UTF8ToString($0));
          },
          file.c_str());
        while(PView::list.size() > first) delete PView::list.back();
        return;
      }
      static double lastRefresh = 0.;
      double now = TimeOfDay();
      if(now - lastRefresh < 0.25) return;
      std::vector<onelab::string> ps;
      onelab::server::instance()->get(ps, "Gmsh/Action");
      if(ps.empty() || ps[0].getValue() != "refresh") return;
      ps[0].setValue("");
      onelab::server::instance()->set(ps[0]);
      lastRefresh = now;
      EM_ASM({
        if(globalThis.gmshSolverRefresh) globalThis.gmshSolverRefresh();
      });
    }
  };
} // namespace

extern "C" {

// draw on the canvas of width x height device pixels, scale being the number
// of them per CSS pixel (the devicePixelRatio of the page)
EMSCRIPTEN_KEEPALIVE int gmshWebDraw(int width, int height, double scale)
{
  Msg::NoThrow noThrow;
  if(!_view) _view = new drawContextOffscreen();
  if(!_view->begin(width, height, scale, true)) return 0;
  _width = width;
  _height = height;
  _scale = scale;
  draw();
  return 1;
}

// add the next frames of the studio shading (General.Shading) to what the
// last draw showed, for about budget seconds: 1 while there are more to add,
// which the page asks for at its next animation frame
EMSCRIPTEN_KEEPALIVE int gmshWebDrawStudio(int width, int height, double scale,
                                           double budget)
{
  Msg::NoThrow noThrow;
  if(!_view || !_view->begin(width, height, scale, true)) return 0;
  bool more = _view->drawStudioFrames(budget);
  _view->end();
  return more ? 1 : 0;
}

// A mouse event on the canvas: kind as paneInput::Kind (0 move, 1 push, 2
// release, 3 drag, 4 wheel), the pointer at (x, y) in a canvas of w x h CSS
// pixels, the button (0 left, 1 right, 2 middle), the notches the wheel
// turned (positive towards the user) and the modifier keys: ModShift and
// ModAlt (Shortcuts.h), and Control and Meta apart (see modifiers() in
// shortcuts.js). Returns 1 when the picture changed and the page is to draw
// it again.
EMSCRIPTEN_KEEPALIVE int gmshWebMouse(int kind, double x, double y, int w,
                                      int h, int button, double wheel,
                                      int modifiers)
{
  Msg::NoThrow noThrow;
  // nothing to move until the scene has been drawn
  if(!_view || !_view->getDrawContext()) return 0;
  if(!_scene) _scene = new webView();
  // the view may have been made anew (see gmshWebResetView())
  _scene->setDrawContext(_view->getDrawContext());
  _scene->redrawAsked = _scene->picked = false;
  paneInput in;
  in.kind = (paneInput::Kind)kind;
  in.x = x;
  in.y = y;
  in.w = w;
  in.h = h;
  in.button = button;
  in.wheel = wheel;
  const int ModControl = 16, ModMeta = 32;
  in.shift = modifiers & ModShift;
  in.ctrl = modifiers & ModControl;
  in.alt = modifiers & ModAlt;
  in.meta = modifiers & ModMeta;
  _scene->handleMouse(in);
  sceneTool::step();
  // the picking pass left its image on the canvas: put the frame back now,
  // before the page shows it
  if(_scene->picked && _view->begin(_width, _height, _scale, true)) {
    draw();
    return 0;
  }
  return _scene->redrawAsked ? 1 : 0;
}

// A pinch of two fingers on the canvas: kind 0 when the second finger comes
// down, 1 as they move, 2 when one is lifted; (x, y) is the point between
// them (CSS pixels) and d how far apart they are. The model is zoomed as they
// spread or close and moved with the point between them, so that what was
// under the fingers stays under them. Returns 1 when the picture is to be
// drawn again.
EMSCRIPTEN_KEEPALIVE int gmshWebPinch(int kind, double x, double y, double d)
{
  Msg::NoThrow noThrow;
  if(!_view || !_view->getDrawContext()) return 0;
  drawContext *ctx = _view->getDrawContext();
  // where the pinch started, and its last step
  static mousePosition start;
  static double d0 = 0., last[3] = {0., 0., 0.};
  if(kind == 0) {
    start.set(ctx, (int)x, (int)y);
    d0 = d;
    last[0] = x;
    last[1] = y;
    last[2] = d;
    return 0;
  }
  if(kind == 2) {
    CTX::instance()->drawRotationCenter = 0;
    CTX::instance()->mesh.draw = 1;
    CTX::instance()->post.draw = 1;
    return 1;
  }
  if(d0 <= 0. || d <= 0. || last[2] <= 0.) return 0;
  if(CTX::instance()->camera) {
    // as the zoom and the translation of a drag (see sceneView)
    Camera *cam = &ctx->camera;
    double fact = d / last[2];
    double h = ctx->viewport[3];
    double tx = cam->radians * (x - last[0]) * 2. / h;
    double ty = cam->radians * (y - last[1]) * 2. / h;
    cam->zoom(fact);
    cam->update();
    cam->moveRight(tx);
    cam->moveUp(ty);
  }
  else {
    double s = start.s[0] * d / d0;
    ctx->s[0] = ctx->s[1] = ctx->s[2] = s;
    // the point under the fingers where the pinch started (start.wnr) under
    // them now (see mousePosition::set())
    ctx->t[0] =
      (ctx->vxmin + x / ctx->viewport[2] * (ctx->vxmax - ctx->vxmin)) / s +
      ctx->t_init[0] / s - start.wnr[0];
    ctx->t[1] =
      (ctx->vymax - y / ctx->viewport[3] * (ctx->vymax - ctx->vymin)) / s +
      ctx->t_init[1] / s - start.wnr[1];
  }
  if(CTX::instance()->fastRedraw) {
    CTX::instance()->mesh.draw = 0;
    CTX::instance()->post.draw = 0;
  }
  last[0] = x;
  last[1] = y;
  last[2] = d;
  return 1;
}

// the pointer left the canvas
EMSCRIPTEN_KEEPALIVE void gmshWebMouseLeft()
{
  Msg::NoThrow noThrow;
  if(_scene && _scene->getDrawContext()) _scene->pointerLeft();
}

// what the pointer is over (see General.Tooltips), for the page to show in
// a box hanging from the point xy[2] of the canvas
EMSCRIPTEN_KEEPALIVE const char *gmshWebHoverText(double *xy)
{
  Msg::NoThrow noThrow;
  if(!_scene) return "";
  xy[0] = _scene->hoverAnchor()[0];
  xy[1] = _scene->hoverAnchor()[1];
  return _scene->hoverText().c_str();
}

// whether a click would pick something: a cross cursor says so
EMSCRIPTEN_KEEPALIVE int gmshWebCrossCursor()
{
  Msg::NoThrow noThrow;
  return (_scene && _scene->cross) ? 1 : 0;
}

// the lasso being drawn (Ctrl+click), as the corner clicked and the pointer
// (CSS pixels) in xy[4]: 0 when there is none
EMSCRIPTEN_KEEPALIVE int gmshWebLasso(double *xy)
{
  Msg::NoThrow noThrow;
  return (_scene && _scene->lasso(xy)) ? 1 : 0;
}

// the query (1) or the measurement (2) taking over the clicks, or neither
// (0), as the buttons of the status bar of the graphical interface (see
// sceneTool): what they left on the picture is taken away
EMSCRIPTEN_KEEPALIVE int gmshWebTool(int tool)
{
  Msg::NoThrow noThrow;
  if(!_view || !_view->getDrawContext()) return 0;
  if(!_scene) _scene = new webView();
  _scene->setDrawContext(_view->getDrawContext());
  // (the tool under way, an operation say, stops)
  sceneTool::stop();
  if(tool == 1) sceneTool::start(newQueryTool(), _scene);
  if(tool == 2) sceneTool::start(newMeasureTool(), _scene);
  return 1;
}

// Start an operation on selected entities (see selectionDriver), or stop the
// one under way (an empty name): its clicks are those of the canvas, its keys
// those of gmshWebOperationKey(), and the values of its form those of
// gmshWebOperationValue(). Returns its fields, in JSON: [{"name", "kind"
// ("text", "check", or the choices separated by '|'), "value" (by default)}],
// or "" if the operation is unknown
EMSCRIPTEN_KEEPALIVE const char *gmshWebOperation(const char *name)
{
  Msg::NoThrow noThrow;
  static std::string json;
  json = "";
  if(!gmshWebTool(0) || !name[0]) return json.c_str();
  _values.clear();
  auto *t = new operationTool(
    name,
    [](const std::string &n) {
      auto it = _values.find(n);
      if(it != _values.end()) return it->second;
      // the default of the field (of the operation, once it has started)
      operationTool *o = operation();
      for(auto &f : o ? o->driver().fields() : selectionDriver::allFields())
        if(f.name == n) return f.value;
      return std::string();
    },
    [](const selectionDriver &) {
      _changes++;
      return true;
    });
  if(!t->active()) {
    delete t;
    return json.c_str();
  }
  sceneTool::start(t, _scene);
  json = "[";
  for(auto &f : t->driver().fields())
    json += std::string(json.size() > 1 ? "," : "") +
            "{\"name\":" + JsonString(f.name) +
            ",\"kind\":" + JsonString(f.kind) +
            ",\"value\":" + JsonString(f.value) + "}";
  json += "]";
  return json.c_str();
}

// a value of the form of the operation (what it picks may depend on it)
EMSCRIPTEN_KEEPALIVE void gmshWebOperationValue(const char *name,
                                                const char *value)
{
  Msg::NoThrow noThrow;
  _values[name] = value;
  // (the entities it picks drawn, as the dialog of the graphical interface
  // draws them)
  int mode = selectionDriver::selectionMode(value);
  if(std::string(name) == "Selection mode" && mode != ENT_ALL)
    selectionDriver::show(mode);
  if(operation()) sceneTool::restart();
}

// a key of the operation: 'e' ends the selection, 'u' takes back what was
// picked last, 'q' stops the operation
EMSCRIPTEN_KEEPALIVE void gmshWebOperationKey(int key)
{
  Msg::NoThrow noThrow;
  if(!_scene || !operation()) return;
  if(key == 'e') _scene->endSelection = 1;
  if(key == 'u') _scene->undoSelection = 1;
  if(key == 'q') _scene->quitSelection = 1;
  sceneTool::step();
}

// the operation, in JSON: {"name" ("" once it is over), "status" (what to
// pick, and the keys), "changes" (the operations carried out so far)}
EMSCRIPTEN_KEEPALIVE const char *gmshWebOperationState()
{
  Msg::NoThrow noThrow;
  static std::string json;
  operationTool *t = operation();
  json = "{\"name\":" + JsonString(t ? t->name() : "") +
         ",\"status\":" + JsonString(t ? t->status(_scene) : "") +
         ",\"changes\":" + std::to_string(_changes) + "}";
  return json.c_str();
}

// The shapes of the elementary entity dialog of the graphical interface, in
// JSON: [{"name", "label", "fields": [[name, default value], ...]}] (see
// scriptShapes())
EMSCRIPTEN_KEEPALIVE const char *gmshWebShapes()
{
  Msg::NoThrow noThrow;
  static std::string json;
  json = "[";
  for(auto &shape : scriptShapes()) {
    json += std::string(json.size() > 1 ? "," : "") +
            "{\"name\":" + JsonString(shape.name) +
            ",\"label\":" + JsonString(shape.label) + ",\"fields\":[";
    for(std::size_t i = 0; i < shape.fields.size(); i++)
      json += std::string(i ? "," : "") + "[" +
              JsonString(shape.fields[i].first) + "," +
              JsonString(shape.fields[i].second) + "]";
    json += "]}";
  }
  json += "]";
  return json.c_str();
}

// the program written next to the script of the model for an item of the
// registry ("script_edit_py"), or "" (see scriptProgram())
EMSCRIPTEN_KEEPALIVE const char *gmshWebScriptProgram(const char *name)
{
  Msg::NoThrow noThrow;
  static std::string file;
  file = "";
  for(auto &l : scriptLanguages())
    if(std::string(name) == "script_edit_" + l.name)
      file = scriptProgram(GModel::current()->getFileName(), l.name);
  return file.c_str();
}

// The action registry (see Actions.h), in JSON: {menu: item}, the menus and
// the status bar and the actions of the keys in no menu ("Keys"), an item
// {"id", "label", "kind" ("menu", "action", "operation" or "shape"), "name",
// "help", "icon" (the name of its icon, see gmshWebIcon(), or ""), "gmsh" (1
// for an action Gmsh does, done here; the page does the others), "items"}; the
// page gives back its id to do it
EMSCRIPTEN_KEEPALIVE const char *gmshWebActions()
{
  Msg::NoThrow noThrow;
  static std::string json;
  _items.clear();
  json = "{";
  for(const char *menu :
      {"Geometry", "Mesh", "Quick access", "View", "Menu bar", "Status bar",
       "Keys"})
    json += std::string(json.size() > 1 ? "," : "") + JsonString(menu) + ":" +
            jsonItem(GetActionMenu(menu));
  json += "}";
  return json.c_str();
}

// The strokes of the icon of the given name (see IconStrokes.h), the inside of
// an SVG in a 24 by 24 box, or "" (the page colours and sizes them)
EMSCRIPTEN_KEEPALIVE const char *gmshWebIcon(const char *name)
{ return IconStrokes(name); }

// What the item of id does, done here (see RunItem()), for the view of
// index view, in the scene: what RunItem() returns
EMSCRIPTEN_KEEPALIVE int gmshWebAction(int id, int view)
{
  Msg::NoThrow noThrow;
  if(!item(id)) return 0;
  int ret = RunItem(*item(id), view, _view ? _view->getDrawContext() : nullptr);
  if(ret & ActionModelChanged) {
    GModel::current()->setSelection(0);
    SetBoundingBox();
  }
  return ret;
}

// The check mark of the item of id (-1 for none, 0 or 1), -2 if it does not
// apply now
EMSCRIPTEN_KEEPALIVE int gmshWebActionCheck(int id)
{
  Msg::NoThrow noThrow;
  const actionItem *i = item(id);
  if(!i || (i->available && !i->available())) return -2;
  return i->check ? i->check() : -1;
}

// The style of each character of the text of a file in an editor (see
// GetScriptStyles()), one for each UTF-16 unit of the text as the page has it
EMSCRIPTEN_KEEPALIVE const char *gmshWebScriptStyles(const char *fileName,
                                                     const char *text)
{
  Msg::NoThrow noThrow;
  static std::string units;
  std::string bytes = GetScriptStyles(fileName, text);
  units.clear();
  for(std::size_t i = 0; text[i]; i++) {
    unsigned char b = (unsigned char)text[i];
    if((b & 0xC0) == 0x80) continue; // in a character
    units += bytes[i];
    if(b >= 0xF0) units += bytes[i]; // a pair of UTF-16 units
  }
  return units.c_str();
}

// Add a shape (see gmshWebShapes()) to the script of the current model, with
// the values of its fields (expressions of the .geo language, separated by
// new lines; an optional one left empty is left out): returns 1 if it was not
// added (with errors). A model that is not a .geo file is given a .geo file
// that merges it, as the dialog's default answer (the page sets
// General.NoPopup)
EMSCRIPTEN_KEEPALIVE int gmshWebAddShape(const char *shape, const char *values)
{
  Msg::NoThrow noThrow;
  std::vector<std::string> v;
  std::istringstream in(values);
  for(std::string s; std::getline(in, s);) v.push_back(s);
  bool added = scriptAddShape(shape, v, GModel::current()->getFileName());
  GModel::current()->setSelection(0);
  SetBoundingBox();
  return added ? 0 : 1;
}

// what the view of index i holds, over all its steps: 1 if scalars, 2 if
// vectors, 4 if tensors (or-ed), for the page to show the options that apply
EMSCRIPTEN_KEEPALIVE int gmshWebViewContent(int i)
{
  Msg::NoThrow noThrow;
  if(i < 0 || i >= (int)PView::list.size()) return 0;
  PViewData *d = PView::list[i]->getData();
  return (d->getNumScalars() ? 1 : 0) | (d->getNumVectors() ? 2 : 0) |
         (d->getNumTensors() ? 4 : 0);
}

// whether the measurement awaits its second point
EMSCRIPTEN_KEEPALIVE int gmshWebMeasuring()
{
  Msg::NoThrow noThrow;
  bool on = _scene && sceneTool::running("Measure") && _scene->measuring();
  return on ? 1 : 0;
}

// What the query and the measurement show over the picture, in JSON, for the
// page to draw where the model is now (CSS pixels from the top left of the
// canvas): {"notes": [{"text", "x", "y"}], "length": {"text", "x", "y"} or
// null, "tint": the colour of their paper}. The paper is the colour of the
// marks (General.Color.Query), lightened over a light picture and darkened
// over a dark one, as in the graphical interface (openglWindow)
EMSCRIPTEN_KEEPALIVE const char *gmshWebNotes()
{
  Msg::NoThrow noThrow;
  static std::string json;
  json = "{\"notes\":[";
  std::string length = "null";
  if(_scene && _scene->getDrawContext()) {
    drawContext *ctx = _scene->getDrawContext();
    double h = ctx->viewport[3];
    for(std::size_t i = 0; i < _scene->numPinned(); i++) {
      double win[2];
      if(!ctx->world2Window(_scene->pinnedPoint(i), win)) continue;
      if(json.back() == '}') json += ",";
      json += "{\"text\":" + JsonString(_scene->pinnedText(i)) +
              ",\"x\":" + std::to_string(win[0]) +
              ",\"y\":" + std::to_string(h - win[1]) + "}";
    }
    double a[3], b[3], win[2];
    if(ctx->segment(a, b)) {
      double mid[3] = {0.5 * (a[0] + b[0]), 0.5 * (a[1] + b[1]),
                       0.5 * (a[2] + b[2])};
      if(ctx->world2Window(mid, win))
        length = "{\"text\":" + JsonString(measurePoints(a, b)[0]) +
                 ",\"x\":" + std::to_string(win[0]) +
                 ",\"y\":" + std::to_string(h - win[1]) + "}";
    }
  }
  // on the paper of the notes of the FLTK interface (see openglWindow.cpp)
  CTX *c = CTX::instance();
  bool dark;
  unsigned int tint = NotePaperColor(c->color.query, c->color.bg, &dark);
  json += "],\"length\":" + length + ",\"tint\":\"rgb(" +
          std::to_string(c->unpackRed(tint)) + "," +
          std::to_string(c->unpackGreen(tint)) + "," +
          std::to_string(c->unpackBlue(tint)) +
          ")\",\"dark\":" + (dark ? "true" : "false") + "}";
  return json.c_str();
}

// the browser went light (0) or dark (1): the colours follow it when
// General.ColorScheme is 3 (System), as they follow the desktop in the
// graphical interface; returns 1 if the scene is to be drawn again
EMSCRIPTEN_KEEPALIVE int gmshWebColorScheme(int dark)
{
  Msg::NoThrow noThrow;
  return followDesktopColorScheme(dark) ? 1 : 0;
}

// the values an option ("Mesh.Algorithm") takes, with their labels, in the
// order to list them, in JSON: [[value, "label"], ...], empty if it takes any
// value (see GetOptionChoices())
EMSCRIPTEN_KEEPALIVE const char *gmshWebOptionChoices(const char *option)
{
  Msg::NoThrow noThrow;
  static std::string json;
  json = "[";
  for(auto &c : GetOptionChoices(option)) {
    if(json.size() > 1) json += ",";
    char v[32];
    snprintf(v, sizeof(v), "%.16g", c.first);
    json += "[" + std::string(v) + "," + JsonString(c.second) + "]";
  }
  json += "]";
  return json.c_str();
}

// the range of a number option and the step of its fields, in JSON:
// {"min", "max", "step"}, or null if it has none (see GetOptionRange())
EMSCRIPTEN_KEEPALIVE const char *gmshWebOptionRange(const char *option)
{
  Msg::NoThrow noThrow;
  static std::string json;
  const OptionRange *r = GetOptionRange(option);
  if(!r) return "null";
  char buf[128];
  snprintf(buf, sizeof(buf), "{\"min\":%.16g,\"max\":%.16g,\"step\":%.16g}",
           r->min, r->max, r->step);
  json = buf;
  return json.c_str();
}

// the keyboard shortcuts of the graphical interface, in JSON: [{"action",
// "key" (a lower case letter, a digit or a mark, or the name the page gives a
// key: "F1", "Escape", "ArrowLeft", "PageUp"...), "mods" (ModCommand 1,
// ModShift 2, ModAlt 4, AnyModifiers 8), "help", "label" (with command the
// name of the Command key, "Cmd+" or "Ctrl+")}]: a key runs the item of its
// action (see Actions.h)
EMSCRIPTEN_KEEPALIVE const char *gmshWebShortcuts(const char *command)
{
  Msg::NoThrow noThrow;
  static std::string json;
  json = "[";
  for(const ShortcutEntry &e : GetShortcuts()) {
    int k = e.shortcut.key;
    std::string key;
    if(k >= KeyF1 && k < KeyF1 + 12)
      key = "F" + std::to_string(k - KeyF1 + 1);
    else if(k == KeyEscape)
      key = "Escape";
    else if(k == KeyLeft)
      key = "ArrowLeft";
    else if(k == KeyRight)
      key = "ArrowRight";
    else if(k == KeyUp)
      key = "ArrowUp";
    else if(k == KeyDown)
      key = "ArrowDown";
    else if(k == KeyPageUp)
      key = "PageUp";
    else if(k == KeyPageDown)
      key = "PageDown";
    else
      key = std::string(1, (char)k);
    if(json.size() > 1) json += ",";
    json += "{\"action\":" + JsonString(e.action) +
            ",\"key\":" + JsonString(key) +
            ",\"mods\":" + std::to_string(e.shortcut.mods) +
            ",\"help\":" + JsonString(e.help) +
            ",\"label\":" + JsonString(e.shortcut.label(command)) + "}";
  }
  json += "]";
  return json.c_str();
}

// the point of view or the time steps, as the page's actions of these names
// do them (see sceneActions()): 1 when done, for the page to draw again
EMSCRIPTEN_KEEPALIVE int gmshWebView(const char *action, int mods)
{
  Msg::NoThrow noThrow;
  if(!_view || !_view->getDrawContext()) return 0;
  auto it = sceneActions().find(action);
  if(it == sceneActions().end()) return 0;
  it->second(mods, _view->getDrawContext());
  return 1;
}

// the lasso being drawn stopped (Escape): 1 if there was one
EMSCRIPTEN_KEEPALIVE int gmshWebStopLasso()
{
  Msg::NoThrow noThrow;
  if(!_scene || !_scene->lassoMode) return 0;
  _scene->lassoMode = false;
  return 1;
}

// the view turned by 90 degrees about the axis out of the screen, clockwise
// or the other way (ccw), as the rotate button of the graphical interface
EMSCRIPTEN_KEEPALIVE int gmshWebRotate(int ccw)
{
  Msg::NoThrow noThrow;
  if(!_view || !_view->getDrawContext()) return 0;
  drawContext *ctx = _view->getDrawContext();
  double axis[3] = {0., 0., 1.};
  ctx->addQuaternionFromAxisAndAngle(axis, ccw ? 90. : -90.);
  if(CTX::instance()->camera) {
    if(ccw)
      ctx->camera.tiltHeadLeft();
    else
      ctx->camera.tiltHeadRight();
  }
  return 1;
}

// back to the view of the options (General.RotationX, General.ScaleX,
// General.TrackballQuaternion0, ...), as set by the files opened, at the next
// draw
EMSCRIPTEN_KEEPALIVE void gmshWebResetView()
{
  Msg::NoThrow noThrow;
  if(_view) _view->resetView();
}

// the solvers forgotten, as a model starts, or none (Clear in the page): the
// next file opened adds those it asks for (see addSolver())
EMSCRIPTEN_KEEPALIVE void gmshWebOnelabForgetSolvers()
{
  Msg::NoThrow noThrow;
  onelab::server *s = onelab::server::instance();
  std::vector<gmshInProcessClient *> v;
  for(auto it = s->firstClient(); it != s->lastClient(); it++)
    if(auto *c = dynamic_cast<gmshInProcessClient *>(*it)) v.push_back(c);
  // (each unregisters itself)
  for(auto *c : v) delete c;
}

// The ONELAB loop of the graphical interface (onelabRun() in onelabGroup.cpp,
// on onelabUtils::onelabLoop) in steps, for a page that runs the solvers in a
// web worker, as the graphical interface runs them in processes of their own
// (solverClient.mjs and solver.js): the page starts,
// then for each pass runs Gmsh here and the solvers it is given in the worker,
// the database going along, then asks for the next pass. Starting, with
// "check", "compute" or "reset" (whose passes are "check"):
EMSCRIPTEN_KEEPALIVE void gmshWebOnelabStart(const char *what)
{
  Msg::NoThrow noThrow;
  std::string action(what);
  addSolver();
  if(action == "reset") {
    onelabUtils::resetDb(true);
    action = "check";
  }
  _loop.reset(new onelabUtils::onelabLoop(action));
}

// Gmsh's part of a pass ("check" or "compute"), and the solvers to run then,
// in JSON: [{"name":..., "args":[...]}]
EMSCRIPTEN_KEEPALIVE const char *gmshWebOnelabGmsh(const char *what)
{
  Msg::NoThrow noThrow;
  static std::string json;
  json = "[";
  if(!_loop) return "[]";
  _loop->runGmsh();
  for(onelab::client *c : _loop->solvers()) {
    auto *s = dynamic_cast<gmshInProcessClient *>(c);
    if(!s) continue;
    if(json.size() > 1) json += ",";
    json += "{\"name\":" + JsonString(c->getName()) + ",\"args\":[";
    std::vector<std::string> args = s->commandLine();
    for(std::size_t i = 0; i < args.size(); i++)
      json += (i ? "," : "") + JsonString(args[i]);
    json += "]}";
  }
  json += "]";
  return json.c_str();
}

// the end of a pass, once the solvers have run and their database is back:
// returns 1 if there is another pass (a loop over parameters), else the loop
// is finished
EMSCRIPTEN_KEEPALIVE int gmshWebOnelabNext(const char *what)
{
  Msg::NoThrow noThrow;
  if(!_loop) return 0;
  for(onelab::client *c : _loop->solvers()) _loop->solverDone(c);
  if(_loop->nextPass()) return 1;
  _loop->finish();
  _loop.reset();
  return 0;
}

// the whole loop, with the solvers run here (run_models.mjs): returns the
// number of errors
EMSCRIPTEN_KEEPALIVE int gmshWebOnelab(const char *what)
{
  Msg::NoThrow noThrow;
  std::string pass = (std::string(what) == "reset") ? "check" : what;
  gmshWebOnelabStart(what);
  do {
    gmshWebOnelabGmsh(pass.c_str());
    for(auto *c : solvers()) c->run();
  } while(gmshWebOnelabNext(pass.c_str()));
  return Msg::GetErrorCount();
}

// the errors since the start
EMSCRIPTEN_KEEPALIVE int gmshWebErrorCount() { return Msg::GetErrorCount(); }

// In the web worker: run a solver with the arguments of gmshWebOnelabGmsh()
// (separated by new lines), with the database the page sent; the files it
// asks to show go to the page as they are written. Returns the errors
EMSCRIPTEN_KEEPALIVE int gmshWebOnelabSolve(const char *argv)
{
  Msg::NoThrow noThrow;
  std::vector<std::string> args;
  std::string a(argv);
  for(std::size_t start = 0, end; start < a.size(); start = end + 1) {
    end = a.find('\n', start);
    if(end == std::string::npos) end = a.size();
    args.push_back(a.substr(start, end - start));
  }
  if(args.empty()) return 1;
  onelabUtils::inProcessSolver solver =
    onelabUtils::getInProcessSolver(args[0]);
  if(!solver) {
    Msg::Error("Solver '%s' is not available in the web app", args[0].c_str());
    return 1;
  }
  // a solver starts with no views, as in a process of its own
  while(PView::list.size()) delete PView::list.back();
  static solverMessages messages;
  Msg::SetCallback(&messages);
  Msg::ResetErrorCounter();
  int errors = 0;
  try {
    errors = solver(args, onelab::server::instance());
  } catch(...) {
    Msg::Error("'%s' stopped on an error", args[0].c_str());
    errors = 1;
  }
  Msg::SetCallback(nullptr);
  return std::max(errors, Msg::GetErrorCount());
}

// On the page: show a file a solver wrote, as the graphical interface does
// when a solver asks for it (gmshLocalNetworkClient)
EMSCRIPTEN_KEEPALIVE void gmshWebOnelabMerge(const char *name)
{
  Msg::NoThrow noThrow;
  onelabUtils::mergeSolverFile(name);
}

// On the page: the X-Y graphs of the parameters drawn on them (their "Graph"
// attribute), made again from their values, as the graphical interface does
// on a refresh
EMSCRIPTEN_KEEPALIVE void gmshWebOnelabUpdateGraphs()
{
  Msg::NoThrow noThrow;
  onelabUtils::updateGraphs();
}

// change a parameter, given in JSON as gmsh.onelab.get() gives them: returns
// 1 if the model is to be checked, 2 if other parameters were reset, or -1
EMSCRIPTEN_KEEPALIVE int gmshWebOnelabSet(const char *json)
{
  Msg::NoThrow noThrow;
  onelab::number n;
  if(n.fromJSON(json)) return onelabUtils::setParameter(n) & 3;
  onelab::string s;
  if(s.fromJSON(json)) return onelabUtils::setParameter(s) & 3;
  return -1;
}

// extract a zip archive (e.g. a model with its included files) in a directory
EMSCRIPTEN_KEEPALIVE void gmshWebUnzip(const char *fileName, const char *dir)
{
  Msg::NoThrow noThrow;
  UnzipFile(fileName, dir);
}

// the colour of a name as the graphical interface reads it (the "Highlight"
// of a parameter, an X11 name such as LightSteelBlue1), as 0xrrggbb, or -1
EMSCRIPTEN_KEEPALIVE int gmshWebColor(const char *name)
{
  Msg::NoThrow noThrow;
  int r, g, b;
  if(!GetRGBForString(name, r, g, b)) return -1;
  return (r << 16) | (g << 8) | b;
}

// that colour as the graphical interface shows it (see ColorContrast.h), on
// the background bg with the text fg of the page (as 0xrrggbb), in dark mode
// or not: as a text (what = 0), as the background of a field (1) or as the
// text on that field (2)
EMSCRIPTEN_KEEPALIVE int gmshWebReadableColor(int rgb, int bg, int fg, int dark,
                                              int what)
{
  Msg::NoThrow noThrow;
  if(what == 0) return ReadableTextColor(rgb, bg, bg, dark);
  unsigned int fill = ReadableFillColor(rgb, fg, dark);
  return what == 1 ? fill : ContrastingColor(fill);
}

} // extern "C"

#endif
