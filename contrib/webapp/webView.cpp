// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What a web page calls (through ccall) to show Gmsh's scene on its canvas,
// with Emscripten, besides the Gmsh API (api/gmsh.mjs): the scene drawn as a
// window would draw it (see drawContextOffscreen), and the mouse events of
// the page given to the same interaction as the graphical interface's
// (sceneView). Positions are in the CSS pixels of the canvas, from its top
// left corner.

#if defined(__EMSCRIPTEN__)

#include <cmath>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <emscripten.h>
#include "Actions.h"
#include "ScriptStyles.h"
#include "Context.h"
#include "ColorContrast.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "OpenFile.h"
#include "Options.h"
#include "Shortcuts.h"
#include "StringUtils.h"
#include "drawContextOffscreen.h"
#include "sceneView.h"
#include "scriptStringInterface.h"
#include "selectionDriver.h"

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
    // the tool that takes over the clicks, as the buttons of the status bar
    // of the graphical interface, or an operation on selected entities (see
    // gmshWebOperation()); the numbers of Tool in onelab.html
    enum { NoTool, QueryTool, MeasureTool, OperationTool };
    int tool = NoTool;
    webView() : sceneView(nullptr) {}
    bool hostQueryMode() { return tool == QueryTool; }
    bool hostMeasureMode() { return tool == MeasureTool; }
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

  // the operation on selected entities under way, the values of the fields
  // of its form, and how many times operations were carried out (for the
  // page to show what changed)
  selectionDriver *_operation = nullptr;
  std::map<std::string, std::string> _values;
  int _changes = 0;

  void draw()
  {
    _view->drawCurrentOpenglWindow(true);
    _view->end();
  }

  // what the selection of the tool found at a click, for the tool: the
  // selection waits for the next click then (see status_query_cb() and
  // status_measure_cb() in the graphical interface)
  void toolStep()
  {
    std::vector<GVertex *> v;
    std::vector<GEdge *> e;
    std::vector<GFace *> f;
    std::vector<GRegion *> r;
    std::vector<MElement *> el;
    std::vector<SPoint2> p;
    std::vector<PView *> vw;
    char ib = _scene->selectionStep(v, e, f, r, el, p, vw);
    if(!ib) return;
    if(_scene->tool == webView::OperationTool) {
      if(_operation->step(ib, v, e, f, r, el)) _changes++;
      if(_operation->active()) _scene->beginSelection(_operation->type());
      return;
    }
    if(ib == 'l' && _scene->tool == webView::QueryTool)
      _scene->queryClick(v, e, f, r, el, vw);
    else if(ib == 'l' && _scene->tool == webView::MeasureTool)
      _scene->measureClick();
    // the next click, unless the tool was stopped
    if(_scene->tool) _scene->beginSelection(ENT_ALL);
  }
} // namespace

extern "C" {

// draw on the canvas of width x height device pixels, scale being the number
// of them per CSS pixel (the devicePixelRatio of the page)
EMSCRIPTEN_KEEPALIVE int gmshWebDraw(int width, int height, double scale)
{
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
  if(_scene->tool) toolStep();
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
    ctx->t[0] = (ctx->vxmin + x / ctx->viewport[2] * (ctx->vxmax - ctx->vxmin)) / s +
                ctx->t_init[0] / s - start.wnr[0];
    ctx->t[1] = (ctx->vymax - y / ctx->viewport[3] * (ctx->vymax - ctx->vymin)) / s +
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
  if(_scene && _scene->getDrawContext()) _scene->pointerLeft();
}

// what the pointer is over (see General.Tooltips), for the page to show in
// a box hanging from the point xy[2] of the canvas
EMSCRIPTEN_KEEPALIVE const char *gmshWebHoverText(double *xy)
{
  if(!_scene) return "";
  xy[0] = _scene->hoverAnchor()[0];
  xy[1] = _scene->hoverAnchor()[1];
  return _scene->hoverText().c_str();
}

// whether a click would pick something: a cross cursor says so
EMSCRIPTEN_KEEPALIVE int gmshWebCrossCursor()
{
  return (_scene && _scene->cross) ? 1 : 0;
}

// the lasso being drawn (Ctrl+click), as the corner clicked and the pointer
// (CSS pixels) in xy[4]: 0 when there is none
EMSCRIPTEN_KEEPALIVE int gmshWebLasso(double *xy)
{
  return (_scene && _scene->lasso(xy)) ? 1 : 0;
}

// the query or the measurement taking over the clicks, or neither (see
// webView::tool), as the buttons of the status bar of the graphical
// interface: what they left on the picture is taken away
EMSCRIPTEN_KEEPALIVE int gmshWebTool(int tool)
{
  if(!_view || !_view->getDrawContext()) return 0;
  if(!_scene) _scene = new webView();
  _scene->setDrawContext(_view->getDrawContext());
  // the operation under way stops
  delete _operation;
  _operation = nullptr;
  // a query picks mesh elements, as long as it is on
  static int pickElements = 0;
  if(_scene->tool == webView::QueryTool)
    CTX::instance()->pickElements = pickElements;
  _scene->tool = tool;
  GModel::current()->setSelection(0);
  _scene->getDrawContext()->clearMarks();
  _scene->pinTooltip("");
  if(tool == webView::QueryTool) {
    pickElements = CTX::instance()->pickElements;
    CTX::instance()->pickElements = 1;
  }
  if(tool) {
    // a pick needs the mouse selection (the "S" button)
    if(!CTX::instance()->mouseSelection)
      opt_general_mouse_selection(0, GMSH_SET, 1);
    _scene->beginSelection(ENT_ALL);
  }
  else {
    _scene->quitSelection = 1;
    toolStep();
  }
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
  static std::string json;
  json = "";
  if(!gmshWebTool(webView::NoTool) || !name[0]) return json.c_str();
  _values.clear();
  _operation = new selectionDriver(name, [](const std::string &n) {
    auto it = _values.find(n);
    if(it != _values.end()) return it->second;
    for(auto &f : _operation->fields())
      if(f.name == n) return f.value;
    return std::string();
  });
  if(!_operation->active()) {
    delete _operation;
    _operation = nullptr;
    return json.c_str();
  }
  _scene->tool = webView::OperationTool;
  if(!CTX::instance()->mouseSelection)
    opt_general_mouse_selection(0, GMSH_SET, 1);
  _scene->beginSelection(_operation->type());
  json = "[";
  for(auto &f : _operation->fields())
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
  _values[name] = value;
  // (the entities it picks drawn, as the dialog of the graphical interface
  // draws them)
  int mode = selectionDriver::selectionMode(value);
  if(std::string(name) == "Selection mode" && mode != ENT_ALL)
    selectionDriver::show(mode);
  if(_operation && _operation->active())
    _scene->beginSelection(_operation->type());
}

// a key of the operation: 'e' ends the selection, 'u' takes back what was
// picked last, 'q' stops the operation
EMSCRIPTEN_KEEPALIVE void gmshWebOperationKey(int key)
{
  if(!_scene || _scene->tool != webView::OperationTool) return;
  if(key == 'e') _scene->endSelection = 1;
  if(key == 'u') _scene->undoSelection = 1;
  if(key == 'q') _scene->quitSelection = 1;
  toolStep();
}

// the operation, in JSON: {"name" ("" once it is over), "status" (what to
// pick, and the keys), "changes" (the operations carried out so far)}
EMSCRIPTEN_KEEPALIVE const char *gmshWebOperationState()
{
  static std::string json;
  bool on = _operation && _operation->active();
  json = "{\"name\":" + JsonString(on ? _operation->operation() : "") +
         ",\"status\":" + JsonString(on ? _operation->status() : "") +
         ",\"changes\":" + std::to_string(_changes) + "}";
  return json.c_str();
}

// The shapes of the elementary entity dialog of the graphical interface, in
// JSON: [{"name", "fields": [[name, default value], ...]}] (see
// scriptShapes())
EMSCRIPTEN_KEEPALIVE const char *gmshWebShapes()
{
  static std::string json;
  json = "[";
  for(auto &shape : scriptShapes()) {
    json += std::string(json.size() > 1 ? "," : "") +
            "{\"name\":" + JsonString(shape.name) + ",\"fields\":[";
    for(std::size_t i = 0; i < shape.fields.size(); i++)
      json += std::string(i ? "," : "") + "[" +
              JsonString(shape.fields[i].first) + "," +
              JsonString(shape.fields[i].second) + "]";
    json += "]}";
  }
  json += "]";
  return json.c_str();
}

// The action registry (see Actions.h), in JSON: {menu: item}, an item
// {"id", "label", "kind" ("menu", "run", "operation", "shape" or "option"),
// "what", "help", "key", "ask" (the option asked for, or ""), "interface"
// (1 if the page does it), "items"}; the page gives back its id to do it
static std::vector<const actionItem *> _items;

static std::string jsonItem(const actionItem &item)
{
  static const char *kinds[] = {"menu", "run", "operation", "shape", "option"};
  std::string json =
    "{\"id\":" + std::to_string(_items.size()) +
    ",\"label\":" + JsonString(item.label) + ",\"kind\":\"" + kinds[item.kind] +
    "\",\"what\":" + JsonString(item.what) +
    ",\"help\":" + JsonString(item.help) + ",\"key\":" + JsonString(item.key) +
    ",\"ask\":" + JsonString(item.ask.option) +
    ",\"interface\":" + (IsDoneByInterface(item) ? "1" : "0") + ",\"items\":[";
  _items.push_back(&item);
  for(std::size_t i = 0; i < item.items.size(); i++)
    json += std::string(i ? "," : "") + jsonItem(item.items[i]);
  return json + "]}";
}

EMSCRIPTEN_KEEPALIVE const char *gmshWebActions()
{
  static std::string json;
  _items.clear();
  json = "{";
  for(const char *menu : {"Geometry", "Mesh", "Quick access", "View"})
    json += std::string(json.size() > 1 ? "," : "") + JsonString(menu) + ":" +
            jsonItem(GetActionMenu(menu));
  json += "}";
  return json.c_str();
}

static const actionItem *item(int id)
{ return (id >= 0 && id < (int)_items.size()) ? _items[id] : nullptr; }

// What the item of id does, done here (see RunAction()), for the view of
// index view, in the scene: what RunAction() returns
EMSCRIPTEN_KEEPALIVE int gmshWebAction(int id, int view)
{
  if(!item(id)) return 0;
  int ret =
    RunAction(*item(id), view, _view ? _view->getDrawContext() : nullptr);
  if(ret & ActionModelChanged) {
    GModel::current()->setSelection(0);
    SetBoundingBox();
  }
  return ret;
}

// The check mark of the item of id (see GetActionCheck()), -2 if it does not
// apply now (see IsActionAvailable())
EMSCRIPTEN_KEEPALIVE int gmshWebActionCheck(int id)
{
  if(!item(id) || !IsActionAvailable(*item(id))) return -2;
  return GetActionCheck(*item(id));
}

// What the item of id asks for, in JSON: {"min", "max", "step", "value"}
EMSCRIPTEN_KEEPALIVE const char *gmshWebActionAsk(int id)
{
  static std::string json;
  double min = 0., max = 0., step = 0., value = 0.;
  if(item(id)) GetActionAsk(item(id)->ask, min, max, step, value);
  char buf[256];
  snprintf(buf, sizeof(buf),
           "{\"min\":%.16g,\"max\":%.16g,\"step\":%.16g,\"value\":%.16g}", min,
           max, step, value);
  json = buf;
  return json.c_str();
}

// The option asked for by the item of id set (see SetActionOption())
EMSCRIPTEN_KEEPALIVE void gmshWebActionSet(int id, double value)
{
  if(item(id)) SetActionOption(item(id)->ask.option, value);
}

// The style of each character of the text of a file in an editor (see
// GetScriptStyles()), one for each UTF-16 unit of the text as the page has it
EMSCRIPTEN_KEEPALIVE const char *gmshWebScriptStyles(const char *fileName,
                                                     const char *text)
{
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
// new lines; an optional one left empty is left out): returns the number of
// errors, the command being taken back from the script if there are any. A
// model that is not a .geo file is given a .geo file that merges it, as the
// dialog's default answer (the page sets General.NoPopup)
EMSCRIPTEN_KEEPALIVE int gmshWebAddShape(const char *shape, const char *values)
{
  std::vector<std::string> v;
  std::istringstream in(values);
  for(std::string s; std::getline(in, s);) v.push_back(s);
  const std::string f = GModel::current()->getFileName();
  auto fileSize = [&f]() {
    std::ifstream file(f, std::ios::binary | std::ios::ate);
    return file ? (long)file.tellg() : -1L;
  };
  const int errors = Msg::GetErrorCount();
  const long size = fileSize();
  try {
    scriptAddShape(shape, v, f);
  } catch(...) {
    Msg::Error("Could not add the %s", shape);
  }
  // (counted before the script is read again, which resets the count)
  const int added = Msg::GetErrorCount() - errors;
  if(added && f == GModel::current()->getFileName() && fileSize() != size)
    scriptRemoveLastCommand(f);
  GModel::current()->setSelection(0);
  SetBoundingBox();
  return added;
}

// whether the measurement awaits its second point
EMSCRIPTEN_KEEPALIVE int gmshWebMeasuring()
{
  return (_scene && _scene->tool == webView::MeasureTool &&
          _scene->measuring()) ?
           1 :
           0;
}

// What the query and the measurement show over the picture, in JSON, for the
// page to draw where the model is now (CSS pixels from the top left of the
// canvas): {"notes": [{"text", "x", "y"}], "length": {"text", "x", "y"} or
// null, "tint": the colour of their paper}. The paper is the colour of the
// marks (General.Color.Query), lightened over a light picture and darkened
// over a dark one, as in the graphical interface (openglWindow)
EMSCRIPTEN_KEEPALIVE const char *gmshWebNotes()
{
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
  // on the paper of the desktop's notes (see openglWindow::draw())
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
  return followDesktopColorScheme(dark) ? 1 : 0;
}

// the values an option ("Mesh.Algorithm") takes, with their labels, in the
// order to list them, in JSON: [[value, "label"], ...], empty if it takes any
// value (see GetOptionChoices())
EMSCRIPTEN_KEEPALIVE const char *gmshWebOptionChoices(const char *option)
{
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
// name of the Command key, "Cmd+" or "Ctrl+"), "scene" (run by
// gmshWebShortcut())}]
EMSCRIPTEN_KEEPALIVE const char *gmshWebShortcuts(const char *command)
{
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
    bool scene = !strcmp(e.action, "escape") || IsSceneShortcut(e.action);
    if(json.size() > 1) json += ",";
    json += "{\"action\":" + JsonString(e.action) +
            ",\"key\":" + JsonString(key) +
            ",\"mods\":" + std::to_string(e.shortcut.mods) +
            ",\"help\":" + JsonString(e.help) +
            ",\"label\":" + JsonString(e.shortcut.label(command)) +
            ",\"scene\":" + (scene ? "true" : "false") + "}";
  }
  json += "]";
  return json.c_str();
}

// run an action of the shortcuts that changes the scene (see
// RunSceneShortcut()), or Escape, which stops a lasso: returns 2 if the scene
// is to be drawn again, 0 if the action is not one of them
EMSCRIPTEN_KEEPALIVE int gmshWebShortcut(const char *action, int mods)
{
  if(!_view || !_view->getDrawContext()) return 0;
  std::string a(action);
  if(a == "escape") {
    if(!_scene || !_scene->lassoMode) return 0;
    _scene->lassoMode = false;
    return 2;
  }
  return RunSceneShortcut(a, mods, _view->getDrawContext());
}

// the view turned by 90 degrees about the axis out of the screen, clockwise
// or the other way (ccw), as the rotate button of the graphical interface
EMSCRIPTEN_KEEPALIVE int gmshWebRotate(int ccw)
{
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
  if(_view) _view->resetView();
}

} // extern "C"

#endif
